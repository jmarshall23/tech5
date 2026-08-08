
// ========================================================================
// ?InitPhysics@idPhysics@@QAAXPAVidClip@@PAVidPhysicsCallbacks@@H@Z
// EA  : 0x8273A158
// RVA : 0x0073A158
// PDB : w:\tech5\engine\gamelib\physics\physics.cpp
// ========================================================================

void __fastcall idPhysics::InitPhysics(
        idPhysics *this,
        idClip *clip_,
        idPhysicsCallbacks *callbacks_,
        int entityNumber_)
{
  this->clip = clip_;
  this->callbacks = callbacks_;
  this->entityNumber = entityNumber_;
}


// ========================================================================
// ?ClearHash@idPhysics@@SAXXZ
// EA  : 0x8273A168
// RVA : 0x0073A168
// PDB : w:\tech5\engine\gamelib\physics\physics.cpp
// ========================================================================

static void __fastcall idPhysics::ClearHash()
{
  memset(Dst: idPhysics::hash, Val: 0, Size: sizeof(idPhysics::hash));
  idPhysics::currentPhysicsId = 0;
}


// ========================================================================
// ?GetPhysicsForId@idPhysics@@SAPAV1@H@Z
// EA  : 0x8273A1A8
// RVA : 0x0073A1A8
// PDB : w:\tech5\engine\gamelib\physics\physics.cpp
// ========================================================================

idPhysics *__fastcall idPhysics::GetPhysicsForId(const int physicsId_)
{
  int v1; // r11

  if ( physicsId_ == -1 )
    return nullptr;
  v1 = *(int *)((char *)idPhysics::hash + ((4 * physicsId_) & 0xFFC));
  if ( v1 == 0 )
    return nullptr;
  while ( *(_DWORD *)(v1 + 12) != physicsId_ )
  {
    v1 = *(_DWORD *)(v1 + 20);
    if ( v1 == 0 )
      return nullptr;
  }
  return (idPhysics *)v1;
}


// ========================================================================
// ?UpdateCollisionResidency@idPhysics@@IAAXABUcontactInfo_t@@@Z
// EA  : 0x8273A1F0
// RVA : 0x0073A1F0
// PDB : w:\tech5\engine\gamelib\physics\physics.cpp
// ========================================================================

void __fastcall idPhysics::UpdateCollisionResidency(idPhysics *this, const contactInfo_t *contact)
{
  if ( (contact->flags & 1) != 0 )
    this->collisionResidency = RESIDENCY_NO;
}


// ========================================================================
// ?Unlink@idPhysics@@AAAXXZ
// EA  : 0x8273A210
// RVA : 0x0073A210
// PDB : w:\tech5\engine\gamelib\physics\physics.cpp
// ========================================================================

void __fastcall idPhysics::Unlink(idPhysics *this)
{
  int physicsId; // r9
  idPhysics **p_nextInHash; // r11
  idPhysics *v3; // r10

  physicsId = this->physicsId;
  p_nextInHash = (idPhysics **)((char *)idPhysics::hash + ((4 * physicsId) & 0xFFC));
  if ( *p_nextInHash != nullptr )
  {
    while ( 1 )
    {
      v3 = *p_nextInHash;
      if ( (*p_nextInHash)->physicsId == physicsId && v3 == this )
        break;
      p_nextInHash = &v3->nextInHash;
      if ( v3->nextInHash == nullptr )
        return;
    }
    *p_nextInHash = v3->nextInHash;
  }
}


// ========================================================================
// ?Link@idPhysics@@AAAXXZ
// EA  : 0x8273A268
// RVA : 0x0073A268
// PDB : w:\tech5\engine\gamelib\physics\physics.cpp
// ========================================================================

void __fastcall idPhysics::Link(idPhysics *this)
{
  int physicsId; // r4
  int v3; // r11
  int v4; // r10
  int v5; // r11
  int v6; // r11

  physicsId = this->physicsId;
  if ( physicsId != -1 )
  {
    v3 = *(int *)((char *)idPhysics::hash + ((4 * physicsId) & 0xFFC));
    if ( v3 != 0 )
    {
      while ( *(_DWORD *)(v3 + 12) != physicsId )
      {
        v3 = *(_DWORD *)(v3 + 20);
        if ( v3 == 0 )
          goto LABEL_11;
      }
      idLib::Printf(fmt: " duplicate physicsId = %d\n", physicsId);
      v4 = idPhysics::currentPhysicsId;
      while ( 1 )
      {
        this->physicsId = v4;
        v4 = ++idPhysics::currentPhysicsId;
        physicsId = this->physicsId;
        if ( physicsId == -1 )
          break;
        v5 = *(int *)((char *)idPhysics::hash + ((4 * physicsId) & 0xFFC));
        if ( v5 == 0 )
          break;
        while ( *(_DWORD *)(v5 + 12) != physicsId )
        {
          v5 = *(_DWORD *)(v5 + 20);
          if ( v5 == 0 )
            goto LABEL_11;
        }
      }
    }
  }
LABEL_11:
  v6 = (4 * physicsId) & 0xFFC;
  this->nextInHash = *(idPhysics **)((char *)idPhysics::hash + v6);
  *(idPhysics **)((char *)idPhysics::hash + v6) = this;
}


// ========================================================================
// ?OutputPhysicsHash_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8273A340
// RVA : 0x0073A340
// PDB : w:\tech5\engine\gamelib\physics\physics.cpp
// ========================================================================

void __fastcall OutputPhysicsHash_f(const idCmdArgs *args)
{
  int v1; // r29
  idPhysics **v2; // r30
  idPhysics *i; // r31

  v1 = 0;
  v2 = idPhysics::hash;
  do
  {
    if ( *v2 != nullptr )
    {
      idLib::Printf(fmt: "%d:", v1);
      for ( i = *v2; i != nullptr; i = i->nextInHash )
        idLib::Printf(fmt: " (%d) 0x%p", i->physicsId, i);
      idLib::Printf(fmt: "\n");
    }
    ++v2;
    ++v1;
  }
  while ( (int)v2 < (int)&OutputPhysicsHash_v );
}


// ========================================================================
// ??0idPhysics@@QAA@XZ
// EA  : 0x8273A3D8
// RVA : 0x0073A3D8
// PDB : w:\tech5\engine\gamelib\physics\physics.cpp
// ========================================================================

idPhysics *__fastcall idPhysics::idPhysics(idPhysics *this)
{
  unsigned __int64 v1; // r11

  LODWORD(v1) = 0;
  this->__vftable = (idPhysics_vtbl *)&idPhysics::`vftable';
  this->residencyQuery.index = v1;
  this->type = PHYSICS_INVALID;
  this->physicsId = ++idPhysics::currentPhysicsId;
  this->entityNumber = 0x1FFF;
  this->nextInHash = nullptr;
  this->clip = nullptr;
  this->callbacks = nullptr;
  this->collisionResidency = RESIDENCY_NOT_TESTED;
  idPhysics::Link(this);
  return this;
}


// ========================================================================
// ??1idPhysics@@UAA@XZ
// EA  : 0x8273A450
// RVA : 0x0073A450
// PDB : w:\tech5\engine\gamelib\physics\physics.cpp
// ========================================================================

void __fastcall idPhysics::~idPhysics(idPhysics *this)
{
  _DWORD *v1; // r3

  this->__vftable = (idPhysics_vtbl *)&idPhysics::`vftable';
  idPhysics::Unlink(this);
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
}


// ========================================================================
// ?IsInNonResidentCollisionArea@idPhysics@@UAA_N_N@Z
// EA  : 0x8273A490
// RVA : 0x0073A490
// PDB : w:\tech5\engine\gamelib\physics\physics.cpp
// ========================================================================

BOOL __fastcall idPhysics::IsInNonResidentCollisionArea(idPhysics *this, bool assumeNonResident)
{
  idResidencyQuery *clip; // r31
  unsigned __int64 index; // r11
  unsigned __int64 v6; // r9
  bool v7; // zf
  char v8; // r11
  idPhysics::residency_t v9; // r11
  const idBounds *v10; // r3
  idPhysics::residency_t collisionResidency; // r11
  char v13; // [sp+50h] [-30h] BYREF

  clip = (idResidencyQuery *)this->clip;
  index = this->residencyQuery.index;
  HIDWORD(index) |= 0x5E0u;
  HIDWORD(v6) = 460264;
  if ( (unsigned int)index < *(_DWORD *)((char *)&clip->index + HIDWORD(index) + 4)
    || (v6 = clip[57533].index, v7 = (unsigned int)index <= (unsigned int)v6, LOBYTE(v6) = 1, !v7) )
  {
    LOBYTE(v6) = 0;
  }
  if ( (_BYTE)v6 != 0 )
  {
    if ( (unsigned int)index < *(_DWORD *)((char *)&clip->index + HIDWORD(index) + 4)
      || (unsigned int)index > *(_DWORD *)((char *)&clip->index + HIDWORD(v6) + 4) )
    {
      v8 = 1;
    }
    else
    {
      v8 = *((_BYTE *)&clip[53439].index + ((32 * index) & 0x7FE0));
    }
    v7 = v8 != 0;
    v9 = RESIDENCY_YES;
    if ( !v7 )
      v9 = RESIDENCY_NO;
    this->collisionResidency = v9;
  }
  if ( LODWORD(this->residencyQuery.index) <= *(_DWORD *)((char *)&clip->index + HIDWORD(v6) + 4) )
  {
    v10 = this->GetAbsBounds(this, a2: -1);
    this->residencyQuery.index = *(_QWORD *)&idClip::TestResidency(this: (idClip *)&v13, result: clip, absBounds: v10)->world;
  }
  collisionResidency = this->collisionResidency;
  return collisionResidency == RESIDENCY_NO || collisionResidency == RESIDENCY_NOT_TESTED && assumeNonResident;
}


// ========================================================================
// `dynamic initializer for 'OutputPhysicsHash_v''
// EA  : 0x833402F0
// RVA : 0x013402F0
// PDB : w:\tech5\engine\gamelib\physics\physics.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__OutputPhysicsHash_v__()
{
  return idCommandLink::idCommandLink(
           this: &OutputPhysicsHash_v,
           cmdName: "OutputPhysicsHash",
           function: OutputPhysicsHash_f,
           description: "prints the physics hash table",
           argCompletion: nullptr);
}

