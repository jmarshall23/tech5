
// ========================================================================
// ??0idSpringEntity@@QAA@XZ
// EA  : 0x82CCAE48
// RVA : 0x00CCAE48
// PDB : w:\tech5\tungsten\game\entities\springentity.cpp
// ========================================================================

idSpringEntity *__fastcall idSpringEntity::idSpringEntity(idSpringEntity *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idSpringEntity_vtbl *)&idSpringEntity::`vftable';
  idPonytail::idPonytail(this: &this->ponytail);
  return this;
}


// ========================================================================
// __unwind$487355
// EA  : 0x82CCAE9C
// RVA : 0x00CCAE9C
// PDB : w:\tech5\tungsten\game\entities\springentity.cpp
// ========================================================================

void _unwind_487355()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idSpringEntity@@UAA@XZ
// EA  : 0x82CCAED0
// RVA : 0x00CCAED0
// PDB : w:\tech5\tungsten\game\entities\springentity.cpp
// ========================================================================

void __fastcall idSpringEntity::~idSpringEntity(idSpringEntity *this)
{
  this->__vftable = (idSpringEntity_vtbl *)&idSpringEntity::`vftable';
  idPonytail::~idPonytail(this: &this->ponytail);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$487375_0
// EA  : 0x82CCAF24
// RVA : 0x00CCAF24
// PDB : w:\tech5\tungsten\game\entities\springentity.cpp
// ========================================================================

void _unwind_487375_0()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?Spawn@idSpringEntity@@QAAXXZ
// EA  : 0x82CCAFB0
// RVA : 0x00CCAFB0
// PDB : w:\tech5\tungsten\game\entities\springentity.cpp
// ========================================================================

void __fastcall idSpringEntity::Spawn(idSpringEntity *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3
  idPhysics *v4; // r3
  float *v5; // r3
  idBounds v6; // [sp+50h] [-30h] BYREF

  idPonytail::Init(this: &this->ponytail, parent_: this);
  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0x200000, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->SetClipMask(this: v3, a2: 0, a3: -1);
  idEntity::BecomeActive(this, flags: 5);
  v4 = idEntity::GetPhysics(this);
  v5 = (float *)v4->GetOrigin(this: v4, a2: 0);
  v6.b[0].x = *v5;
  v6.b[0].y = v5[1];
  v6.b[0].z = v5[2];
  v6.b[1].x = *v5;
  v6.b[1].y = v5[1];
  v6.b[1].z = v5[2];
  idEntity::UpdatePVSAreas(this, bounds: &v6);
}


// ========================================================================
// ?Think@idSpringEntity@@UAAXXZ
// EA  : 0x82CCB090
// RVA : 0x00CCB090
// PDB : w:\tech5\tungsten\game\entities\springentity.cpp
// ========================================================================

void __fastcall idSpringEntity::Think(idSpringEntity *this)
{
  idPhysics *Physics; // r3
  float *v3; // r3
  idBounds v4; // [sp+50h] [-30h] BYREF

  if ( (unsigned __int8)idEntity::UpdateDormant(this) == 0 )
  {
    idAnimatedEntity::Think(this);
    Physics = idEntity::GetPhysics(this);
    v3 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v4.b[0].x = *v3;
    v4.b[0].y = v3[1];
    v4.b[0].z = v3[2];
    v4.b[1].x = *v3;
    v4.b[1].y = v3[1];
    v4.b[1].z = v3[2];
    idEntity::UpdatePVSAreas(this, bounds: &v4);
  }
}

