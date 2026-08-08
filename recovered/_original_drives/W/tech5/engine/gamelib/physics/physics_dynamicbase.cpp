
// ========================================================================
// ?SetClipMask@idPhysics_DynamicBase@@UAAXHH@Z
// EA  : 0x82747640
// RVA : 0x00747640
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::SetClipMask(idPhysics_DynamicBase *this, int mask, int id)
{
  this->clipMask = mask;
}


// ========================================================================
// ?GetAbsBounds@idPhysics_DynamicBase@@UBAABVidBounds@@H@Z
// EA  : 0x82747648
// RVA : 0x00747648
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_DynamicBase::GetAbsBounds(idPhysics_DynamicBase *this, int id)
{
  return &bounds_zero;
}


// ========================================================================
// ?GetGravity@idPhysics_DynamicBase@@UBAABVidVec3@@XZ
// EA  : 0x82747658
// RVA : 0x00747658
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

const idVec3 *__fastcall idPhysics_DynamicBase::GetGravity(idPhysics_DynamicBase *this)
{
  return &this->gravityVector;
}


// ========================================================================
// ?GetGravityNormal@idPhysics_DynamicBase@@UBAABVidVec3@@XZ
// EA  : 0x82747660
// RVA : 0x00747660
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

const idVec3 *__fastcall idPhysics_DynamicBase::GetGravityNormal(idPhysics_DynamicBase *this)
{
  return &this->gravityNormal;
}


// ========================================================================
// ?ClipTranslation@idPhysics_DynamicBase@@UBAXAAUtrace_t@@ABVidVec3@@PBVidClipModel@@@Z
// EA  : 0x82747668
// RVA : 0x00747668
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::ClipTranslation(
        idPhysics_DynamicBase *this,
        trace_t *results,
        const idRotation *rotation,
        const idClipModel *model)
{
  memset(Dst: results, Val: 0, Size: sizeof(trace_t));
}


// ========================================================================
// ?SetWaterLevel@idPhysics_DynamicBase@@UAAXMH@Z
// EA  : 0x82747678
// RVA : 0x00747678
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::SetWaterLevel(idPhysics_DynamicBase *this, double level, int id)
{
  this->waterLevel = level;
}


// ========================================================================
// ?GetWaterLevel@idPhysics_DynamicBase@@UBAMH@Z
// EA  : 0x82747680
// RVA : 0x00747680
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

float __fastcall idPhysics_DynamicBase::GetWaterLevel(idPhysics_DynamicBase *this, int id)
{
  double waterLevel; // fp1

  waterLevel = this->waterLevel;
  return *((float *)&waterLevel + 1);
}


// ========================================================================
// ?SetWaterViscosity@idPhysics_DynamicBase@@UAAXMH@Z
// EA  : 0x82747688
// RVA : 0x00747688
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::SetWaterViscosity(idPhysics_DynamicBase *this, double viscosity, int id)
{
  this->waterViscosity = viscosity;
}


// ========================================================================
// ?GetWaterViscosity@idPhysics_DynamicBase@@UBAMH@Z
// EA  : 0x82747690
// RVA : 0x00747690
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

float __fastcall idPhysics_DynamicBase::GetWaterViscosity(idPhysics_DynamicBase *this, int id)
{
  double waterViscosity; // fp1

  waterViscosity = this->waterViscosity;
  return *((float *)&waterViscosity + 1);
}


// ========================================================================
// ?SetGravity@idPhysics_DynamicBase@@UAAXABVidVec3@@@Z
// EA  : 0x82747750
// RVA : 0x00747750
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::SetGravity(idPhysics_DynamicBase *this, const idVec3 *newGravity)
{
  double x; // fp8
  double y; // fp10
  double v4; // fp4
  double z; // fp9
  double v6; // fp7
  double v9; // fp1
  double v10; // fp12
  double v11; // fp9
  double v12; // fp2
  double v13; // fp1

  this->gravityVector = *newGravity;
  x = newGravity->x;
  this->gravityNormal.x = newGravity->x;
  y = newGravity->y;
  v4 = (float)((float)((float)x * (float)x) + (float)(newGravity->y * newGravity->y));
  this->gravityNormal.y = newGravity->y;
  z = newGravity->z;
  this->gravityNormal.z = newGravity->z;
  v6 = z;
  _FP2 = (float)((float)((float)((float)z * (float)z) + (float)v4) - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f13 }
  v9 = (float)((float)((float)((float)z * (float)z) + (float)v4) * (float)0.5);
  v10 = __frsqrte(_FP13);
  v11 = (float)-(float)((float)((float)((float)v10
                                      * (float)((float)((float)((float)z * (float)z) + (float)v4) * (float)0.5))
                              * (float)v10)
                      - (float)1.5);
  v12 = (float)((float)-(float)((float)((float)((float)((float)v11 * (float)v10) * (float)v9)
                                      * (float)((float)v11 * (float)v10))
                              - (float)1.5)
              * (float)((float)v11 * (float)v10));
  v13 = (float)((float)((float)-(float)((float)((float)((float)((float)v11 * (float)v10) * (float)v9)
                                              * (float)((float)v11 * (float)v10))
                                      - (float)1.5)
                      * (float)((float)v11 * (float)v10))
              * (float)v9);
  this->gravityNormal.x = (float)x
                        * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12);
  this->gravityNormal.y = (float)y
                        * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12);
  this->gravityNormal.z = (float)v6
                        * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12);
}


// ========================================================================
// ?GetContact@idPhysics_DynamicBase@@UBAABUcontactInfo_t@@H@Z
// EA  : 0x82747808
// RVA : 0x00747808
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

const contactInfo_t *__fastcall idPhysics_DynamicBase::GetContact(idPhysics_DynamicBase *this, int index)
{
  return &this->contacts.list[index];
}


// ========================================================================
// ?RemoveContactPhysics@idPhysics_DynamicBase@@UAAXPAVidPhysics@@@Z
// EA  : 0x82747818
// RVA : 0x00747818
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::RemoveContactPhysics(idPhysics_DynamicBase *this, idPhysics *phys)
{
  int v4; // r31
  idList<int,77> *p_contactPhysicsIds; // r30
  int v6; // r29
  idPhysics *PhysicsForId; // r3
  int num; // r11
  int v9; // r11

  v4 = 0;
  if ( this->contactPhysicsIds.num > 0 )
  {
    p_contactPhysicsIds = &this->contactPhysicsIds;
    v6 = 0;
    do
    {
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: p_contactPhysicsIds->list[v6]);
      if ( PhysicsForId == nullptr || PhysicsForId == phys )
      {
        if ( v4 >= 0 )
        {
          num = p_contactPhysicsIds->num;
          if ( v4 < num )
          {
            v9 = num - 1;
            p_contactPhysicsIds->num = v9;
            if ( v4 != v9 )
              p_contactPhysicsIds->list[v6] = p_contactPhysicsIds->list[v9];
          }
        }
        --v6;
        --v4;
      }
      ++v4;
      ++v6;
    }
    while ( v4 < this->contactPhysicsIds.num );
  }
}


// ========================================================================
// ?GetContactPhysics@idPhysics_DynamicBase@@UBAPAVidPhysics@@H@Z
// EA  : 0x827478B8
// RVA : 0x007478B8
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

idPhysics *__fastcall idPhysics_DynamicBase::GetContactPhysics(idPhysics_DynamicBase *this, int index)
{
  return idPhysics::GetPhysicsForId(physicsId_: this->contactPhysicsIds.list[index]);
}


// ========================================================================
// ?ActivateContactPhysics@idPhysics_DynamicBase@@UAAXXZ
// EA  : 0x827478C8
// RVA : 0x007478C8
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::ActivateContactPhysics(idPhysics_DynamicBase *this)
{
  int v2; // r31
  idList<int,77> *p_contactPhysicsIds; // r29
  int v4; // r30
  idPhysics *PhysicsForId; // r3
  int num; // r11
  int v7; // r11

  v2 = 0;
  if ( this->contactPhysicsIds.num > 0 )
  {
    p_contactPhysicsIds = &this->contactPhysicsIds;
    v4 = 0;
    do
    {
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: p_contactPhysicsIds->list[v4]);
      if ( PhysicsForId != nullptr )
      {
        PhysicsForId->callbacks->ActivatePhysics(this: PhysicsForId->callbacks, a2: this->physicsId);
      }
      else
      {
        if ( v2 >= 0 )
        {
          num = p_contactPhysicsIds->num;
          if ( v2 < num )
          {
            v7 = num - 1;
            p_contactPhysicsIds->num = v7;
            if ( v2 != v7 )
              p_contactPhysicsIds->list[v4] = p_contactPhysicsIds->list[v7];
          }
        }
        --v2;
        --v4;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < this->contactPhysicsIds.num );
  }
}


// ========================================================================
// ?HasGroundContacts@idPhysics_DynamicBase@@UBA_NXZ
// EA  : 0x82747978
// RVA : 0x00747978
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

int __fastcall idPhysics_DynamicBase::HasGroundContacts(idPhysics_DynamicBase *this)
{
  int num; // r6
  int v2; // r8
  int i; // r10

  num = this->contacts.num;
  v2 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = 0;
        (float)((float)(this->contacts.list[i].normal.x * (float)-this->gravityNormal.x)
              + (float)((float)(this->contacts.list[i].normal.z * (float)-this->gravityNormal.z)
                      + (float)(this->contacts.list[i].normal.y * (float)-this->gravityNormal.y))) <= 0.0;
        ++i )
  {
    if ( ++v2 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?IsGroundEntity@idPhysics_DynamicBase@@UBA_NH@Z
// EA  : 0x827479F8
// RVA : 0x007479F8
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

int __fastcall idPhysics_DynamicBase::IsGroundEntity(idPhysics_DynamicBase *this, int entityNum)
{
  int num; // r7
  int v3; // r9
  contactInfo_t *list; // r8
  int i; // r10

  num = this->contacts.num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  list = this->contacts.list;
  for ( i = 0;
        list[i].entityNum != entityNum
     || (float)((float)(list[i].normal.x * this->gravityNormal.x)
              + (float)((float)(this->gravityNormal.z * list[i].normal.z)
                      + (float)(this->gravityNormal.y * list[i].normal.y))) >= -0.1;
        ++i )
  {
    if ( ++v3 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?IsGroundClipModel@idPhysics_DynamicBase@@UBA_NHH@Z
// EA  : 0x82747A88
// RVA : 0x00747A88
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

int __fastcall idPhysics_DynamicBase::IsGroundClipModel(idPhysics_AF *this, int entityNum, int id)
{
  int num; // r7
  int v4; // r9
  contactInfo_t *list; // r8
  int i; // r10
  contactInfo_t *v7; // r11

  num = this->contacts.num;
  v4 = 0;
  if ( num <= 0 )
    return 0;
  list = this->contacts.list;
  for ( i = 0; ; ++i )
  {
    v7 = &list[i];
    if ( list[i].entityNum == entityNum
      && v7->bodyId == id
      && (float)((float)(v7->normal.x * this->gravityNormal.x)
               + (float)((float)(v7->normal.z * this->gravityNormal.z) + (float)(v7->normal.y * this->gravityNormal.y))) < -0.98480773 )
    {
      break;
    }
    if ( ++v4 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?AddContactPhysicsForContacts@idPhysics_DynamicBase@@IAAXXZ
// EA  : 0x82747B10
// RVA : 0x00747B10
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::AddContactPhysicsForContacts(idPhysics_DynamicBase *this)
{
  int v2; // r29
  int v3; // r30
  idPhysics_DynamicBase *PhysicsForId; // r3

  v2 = 0;
  if ( this->contacts.num > 0 )
  {
    v3 = 0;
    do
    {
      PhysicsForId = (idPhysics_DynamicBase *)idPhysics::GetPhysicsForId(physicsId_: this->contacts.list[v3].physicsId);
      if ( PhysicsForId != nullptr && PhysicsForId != this )
        PhysicsForId->AddContactPhysics(this: PhysicsForId, a2: this);
      ++v2;
      ++v3;
    }
    while ( v2 < this->contacts.num );
  }
}


// ========================================================================
// ?IsOutsideWorld@idPhysics_DynamicBase@@UBA_NXZ
// EA  : 0x82747B88
// RVA : 0x00747B88
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

BOOL __fastcall idPhysics_DynamicBase::IsOutsideWorld(idPhysics_DynamicBase *this)
{
  float *WorldBounds; // r3
  double v3; // fp29
  double v4; // fp28
  double v5; // fp27
  double v6; // fp26
  double v7; // fp31
  double v8; // fp30
  float *v9; // r3
  unsigned __int8 v10; // r11

  WorldBounds = (float *)idClip::GetWorldBounds(this: this->clip);
  v3 = (float)(WorldBounds[3] + (float)1024.0);
  v4 = (float)(WorldBounds[4] + (float)1024.0);
  v5 = (float)(WorldBounds[5] + (float)1024.0);
  v6 = (float)(*WorldBounds - (float)1024.0);
  v7 = (float)(WorldBounds[1] - (float)1024.0);
  v8 = (float)(WorldBounds[2] - (float)1024.0);
  v9 = (float *)this->GetAbsBounds(this, a2: -1);
  if ( v9[3] < v6 || v9[4] < v7 || v9[5] < v8 || *v9 > v3 || v9[1] > v4 || (v10 = 1, v9[2] > v5) )
    v10 = 0;
  return (_cntlzw(v10) & 0x20) != 0;
}


// ========================================================================
// ?DrawVelocity@idPhysics_DynamicBase@@IBAXHMM@Z
// EA  : 0x82747C78
// RVA : 0x00747C78
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::DrawVelocity(
        idPhysics_DynamicBase *this,
        int id,
        double linearScale,
        double angularScale)
{
  idVec3 *v8; // r3
  double v9; // fp0
  double v10; // fp13
  double v11; // fp12
  const idVec3 *v12; // r3
  idRenderWorld *v13; // r3
  idVec3 *v14; // r3
  double v17; // fp3
  double v18; // fp4
  double v19; // fp3
  double v20; // fp26
  double v21; // fp25
  double v22; // fp24
  double v23; // fp23
  double v24; // fp0
  float *v25; // r3
  double v26; // fp12
  double v27; // fp0
  double v28; // fp13
  double v29; // fp28
  double v30; // fp2
  double v31; // fp1
  double v32; // fp13
  double v33; // fp12
  double v34; // fp9
  double v36; // fp1
  double v38; // fp10
  double v39; // fp0
  double v40; // fp1
  double v41; // fp30
  double v42; // fp29
  double v43; // fp31
  float *v44; // r3
  double v45; // fp7
  double v46; // fp6
  idRenderWorld *v47; // r3
  float *v48; // r3
  double v49; // fp7
  double v50; // fp6
  idRenderWorld *v51; // r3
  float x; // [sp+50h] [-170h] BYREF
  float y; // [sp+54h] [-16Ch]
  float z; // [sp+58h] [-168h]
  float v55; // [sp+60h] [-160h] BYREF
  float v56; // [sp+64h] [-15Ch]
  float v57; // [sp+68h] [-158h]
  idVec3 v58; // [sp+70h] [-150h] BYREF
  float v59; // [sp+80h] [-140h] BYREF
  float v60; // [sp+84h] [-13Ch]
  float v61; // [sp+88h] [-138h]
  float v62[4]; // [sp+90h] [-130h] BYREF
  idRotation v63; // [sp+A0h] [-120h] BYREF
  idRotation v64; // [sp+F0h] [-D0h] BYREF

  v8 = this->GetLinearVelocity(this: &v58, result: this, a3: id);
  v9 = (float)(v8->y * (float)linearScale);
  v10 = (float)(v8->z * (float)linearScale);
  v11 = (float)(v8->x * (float)linearScale);
  v58.z = v8->z * (float)linearScale;
  v58.y = v9;
  v58.x = v11;
  if ( (float)((float)((float)v11 * (float)v11)
             + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) > 0.010000001 )
  {
    idVec3::Truncate(this: &v58, length: 10.0);
    v12 = this->GetOrigin(this, a2: id);
    x = v12->x;
    y = v12->y;
    z = v12->z;
    v13 = common->RW(this: common);
    v62[0] = x + v58.x;
    v62[1] = v58.y + y;
    v62[2] = z + v58.z;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v13->DebugArrow)(
      a1: v13,
      a2: &idColor::colorRed,
      a3: &x,
      a4: v62,
      a5: 1.0);
  }
  v14 = this->GetAngularVelocity(this: &v58, result: this, a3: id);
  _FP6 = (float)((float)((float)(v14->x * v14->x) + (float)((float)(v14->z * v14->z) + (float)(v14->y * v14->y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f0 }
  v17 = __frsqrte(_FP4);
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)(v14->x * v14->x) + (float)((float)(v14->z * v14->z) + (float)(v14->y * v14->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17)
                                              * (float)((float)((float)(v14->x * v14->x)
                                                              + (float)((float)(v14->z * v14->z)
                                                                      + (float)(v14->y * v14->y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                              * (float)((float)((float)(v14->x * v14->x)
                                                                                              + (float)((float)(v14->z * v14->z) + (float)(v14->y * v14->y)))
                                                                                      * (float)0.5))
                                                                      * (float)v17)
                                                              - (float)1.5)
                                              * (float)v17))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v17
                                                      * (float)((float)((float)(v14->x * v14->x)
                                                                      + (float)((float)(v14->z * v14->z)
                                                                              + (float)(v14->y * v14->y)))
                                                              * (float)0.5))
                                              * (float)v17)
                                      - (float)1.5)
                      * (float)v17));
  v19 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                              * (float)((float)((float)(v14->x * v14->x) + (float)((float)(v14->z * v14->z) + (float)(v14->y * v14->y))) * (float)0.5))
                                                                                      * (float)v17)
                                                                              - (float)1.5)
                                                              * (float)v17)
                                                      * (float)((float)((float)(v14->x * v14->x)
                                                                      + (float)((float)(v14->z * v14->z)
                                                                              + (float)(v14->y * v14->y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)(v14->x * v14->x) + (float)((float)(v14->z * v14->z) + (float)(v14->y * v14->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v17
                                                              * (float)((float)((float)(v14->x * v14->x)
                                                                              + (float)((float)(v14->z * v14->z)
                                                                                      + (float)(v14->y * v14->y)))
                                                                      * (float)0.5))
                                                      * (float)v17)
                                              - (float)1.5)
                              * (float)v17))
              * (float)((float)((float)(v14->x * v14->x) + (float)((float)(v14->z * v14->z) + (float)(v14->y * v14->y)))
                      * (float)0.5));
  v20 = (float)((float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18) * v14->x);
  v21 = (float)(v14->y * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18));
  v22 = (float)(v14->z * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18));
  v23 = (float)((float)((float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18)
                      * (float)((float)(v14->x * v14->x) + (float)((float)(v14->z * v14->z) + (float)(v14->y * v14->y))))
              * (float)angularScale);
  if ( v23 > 0.1 )
  {
    v24 = 60.0;
    if ( v23 < 60.0 || (v24 = 360.0, v23 > 360.0) )
      v23 = v24;
    v25 = (float *)this->GetAxis(this, a2: id);
    v26 = v25[8];
    v27 = v25[6];
    v28 = v25[7];
    if ( __fabs((float)((float)(v25[7] * (float)v21)
                      + (float)((float)(v25[6] * (float)v20) + (float)(v25[8] * (float)v22)))) > 0.99000001 )
    {
      v27 = *v25;
      v28 = v25[1];
      v26 = v25[2];
    }
    v29 = 20.0;
    v30 = (float)((float)v26
                * (float)((float)((float)v27 * (float)v20)
                        + (float)((float)((float)v26 * (float)v22) + (float)((float)v28 * (float)v21))));
    v31 = (float)((float)((float)((float)v27 * (float)v20)
                        + (float)((float)((float)v26 * (float)v22) + (float)((float)v28 * (float)v21)))
                * (float)v27);
    v32 = (float)((float)v28
                - (float)((float)v28
                        * (float)((float)((float)v27 * (float)v20)
                                + (float)((float)((float)v26 * (float)v22) + (float)((float)v28 * (float)v21)))));
    v33 = (float)((float)v26 - (float)v30);
    v34 = (float)((float)v27 - (float)v31);
    _FP2 = (float)((float)((float)((float)((float)v27 - (float)v31) * (float)((float)v27 - (float)v31))
                         + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v36 = (float)((float)((float)((float)((float)v27 - (float)v31) * (float)((float)v27 - (float)v31))
                        + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                * (float)0.5);
    __asm { fsel      f0, f2, f3, f10 }
    v38 = __frsqrte(_FP0);
    v39 = (float)((float)v32
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5) * (float)v38)
                                                                                                * (float)v36)
                                                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                                                                                * (float)v38))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                                * (float)v38)
                                                                                        - (float)1.5)
                                                                        * (float)v38))
                                                        * (float)v36)
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                                                                                * (float)v38)
                                                                                        * (float)v36)
                                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                                                                        * (float)v38))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                        * (float)v38)
                                                                                - (float)1.5)
                                                                * (float)v38)))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                                * (float)v38)
                                                                                        - (float)1.5)
                                                                        * (float)v38)
                                                                * (float)v36)
                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                        * (float)v38)
                                                                                - (float)1.5)
                                                                * (float)v38))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38)
                                                        - (float)1.5)
                                        * (float)v38))));
    v41 = (float)((float)((float)v32
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5) * (float)v38) * (float)v36)
                                                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5) * (float)v38))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38)
                                                                                                - (float)1.5)
                                                                                * (float)v38))
                                                                * (float)v36)
                                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5) * (float)v38)
                                                                                                * (float)v36)
                                                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                                                                                * (float)v38))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                                * (float)v38)
                                                                                        - (float)1.5)
                                                                        * (float)v38)))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38)
                                                                                                - (float)1.5)
                                                                                * (float)v38)
                                                                        * (float)v36)
                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                                * (float)v38)
                                                                                        - (float)1.5)
                                                                        * (float)v38))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38)
                                                                - (float)1.5)
                                                * (float)v38))))
                * (float)4.0);
    v42 = (float)((float)((float)v33
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5) * (float)v38) * (float)v36)
                                                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5) * (float)v38))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38)
                                                                                                - (float)1.5)
                                                                                * (float)v38))
                                                                * (float)v36)
                                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5) * (float)v38)
                                                                                                * (float)v36)
                                                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                                                                                * (float)v38))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                                * (float)v38)
                                                                                        - (float)1.5)
                                                                        * (float)v38)))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38)
                                                                                                - (float)1.5)
                                                                                * (float)v38)
                                                                        * (float)v36)
                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                                * (float)v38)
                                                                                        - (float)1.5)
                                                                        * (float)v38))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38)
                                                                - (float)1.5)
                                                * (float)v38))))
                * (float)4.0);
    v40 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5) * (float)v38)
                                                                                                * (float)v36)
                                                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                                                                                * (float)v38))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                                * (float)v38)
                                                                                        - (float)1.5)
                                                                        * (float)v38))
                                                        * (float)v36)
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                                                                                * (float)v38)
                                                                                        * (float)v36)
                                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                                                                        * (float)v38))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                        * (float)v38)
                                                                                - (float)1.5)
                                                                * (float)v38)))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                                * (float)v38)
                                                                                        - (float)1.5)
                                                                        * (float)v38)
                                                                * (float)v36)
                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                        * (float)v38)
                                                                                - (float)1.5)
                                                                * (float)v38))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38)
                                                        - (float)1.5)
                                        * (float)v38)))
                * (float)v34);
    v43 = (float)((float)v40 * (float)4.0);
    v60 = (float)((float)v39 * (float)4.0) + y;
    v61 = (float)v42 + z;
    v59 = (float)((float)v40 * (float)4.0) + x;
    if ( v23 > 20.0 )
    {
      do
      {
        v63.axisValid = false;
        v63.origin.x = vec3_origin.x;
        v63.origin.y = vec3_origin.y;
        v63.origin.z = vec3_origin.z;
        v63.vec.x = v20;
        v63.vec.y = v21;
        v63.vec.z = v22;
        v63.angle = -v29;
        v63.axis.mat[0].x = mat3_identity.mat[0].x;
        v63.axis.mat[0].y = mat3_identity.mat[0].y;
        v63.axis.mat[0].z = mat3_identity.mat[0].z;
        v63.axis.mat[1].x = mat3_identity.mat[1].x;
        v63.axis.mat[1].y = mat3_identity.mat[1].y;
        v63.axis.mat[1].z = mat3_identity.mat[1].z;
        v63.axis.mat[2].x = mat3_identity.mat[2].x;
        v63.axis.mat[2].y = mat3_identity.mat[2].y;
        v63.axis.mat[2].z = mat3_identity.mat[2].z;
        v44 = (float *)idRotation::ToMat3(this: &v63);
        v45 = (float)((float)(v44[1] * (float)v43) + (float)((float)(v44[7] * (float)v42) + (float)(v44[4] * (float)v41)));
        v46 = (float)((float)(v44[2] * (float)v43) + (float)((float)(v44[8] * (float)v42) + (float)(v44[5] * (float)v41)));
        v55 = (float)((float)(*v44 * (float)v43) + (float)((float)(v44[6] * (float)v42) + (float)(v44[3] * (float)v41)))
            + x;
        v56 = (float)v45 + y;
        v57 = (float)v46 + z;
        v47 = common->RW(this: common);
        v47->DebugLine(
          this: v47,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: (const idVec3 *)&v59,
          a4: (const idVec3 *)&v55,
          a5: 1,
          a6: false);
        v29 = (float)((float)v29 + (float)20.0);
        v59 = v55;
        v60 = v56;
        v61 = v57;
      }
      while ( v29 < v23 );
    }
    v64.axisValid = false;
    v64.origin.x = vec3_origin.x;
    v64.origin.y = vec3_origin.y;
    v64.origin.z = vec3_origin.z;
    v64.vec.x = v20;
    v64.vec.y = v21;
    v64.vec.z = v22;
    v64.angle = -v23;
    v64.axis.mat[0].x = mat3_identity.mat[0].x;
    v64.axis.mat[0].y = mat3_identity.mat[0].y;
    v64.axis.mat[0].z = mat3_identity.mat[0].z;
    v64.axis.mat[1].x = mat3_identity.mat[1].x;
    v64.axis.mat[1].y = mat3_identity.mat[1].y;
    v64.axis.mat[1].z = mat3_identity.mat[1].z;
    v64.axis.mat[2].x = mat3_identity.mat[2].x;
    v64.axis.mat[2].y = mat3_identity.mat[2].y;
    v64.axis.mat[2].z = mat3_identity.mat[2].z;
    v48 = (float *)idRotation::ToMat3(this: &v64);
    v49 = (float)((float)(v48[1] * (float)v43) + (float)((float)(v48[7] * (float)v42) + (float)(v48[4] * (float)v41)));
    v50 = (float)((float)(v48[2] * (float)v43) + (float)((float)(v48[8] * (float)v42) + (float)(v48[5] * (float)v41)));
    v55 = (float)((float)((float)v43 * *v48) + (float)((float)(v48[6] * (float)v42) + (float)(v48[3] * (float)v41))) + x;
    v56 = (float)v49 + y;
    v57 = (float)v50 + z;
    v51 = common->RW(this: common);
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v51->DebugArrow)(
      a1: v51,
      a2: &idColor::colorBlue,
      a3: &v59,
      a4: &v55,
      a5: 1.0);
  }
}


// ========================================================================
// ?AddContactPhysics@idPhysics_DynamicBase@@UAAXPAVidPhysics@@@Z
// EA  : 0x82748248
// RVA : 0x00748248
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::AddContactPhysics(idPhysics_DynamicBase *this, idPhysics *phys)
{
  char v4; // r26
  int v5; // r31
  idList<int,77> *p_contactPhysicsIds; // r29
  int v7; // r30
  idPhysics *PhysicsForId; // r3
  int num; // r11
  int v10; // r11
  int physicsId; // r30
  int v12; // r11
  int size; // r10
  int *list; // r9

  v4 = 0;
  v5 = 0;
  if ( this->contactPhysicsIds.num > 0 )
  {
    p_contactPhysicsIds = &this->contactPhysicsIds;
    v7 = 0;
    do
    {
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: p_contactPhysicsIds->list[v7]);
      if ( PhysicsForId != nullptr )
      {
        if ( PhysicsForId == phys )
          v4 = 1;
      }
      else
      {
        if ( v5 >= 0 )
        {
          num = p_contactPhysicsIds->num;
          if ( v5 < num )
          {
            v10 = num - 1;
            p_contactPhysicsIds->num = v10;
            if ( v5 != v10 )
              p_contactPhysicsIds->list[v7] = p_contactPhysicsIds->list[v10];
          }
        }
        --v5;
        --v7;
      }
      ++v5;
      ++v7;
    }
    while ( v5 < this->contactPhysicsIds.num );
  }
  if ( v4 == 0 )
  {
    physicsId = phys->physicsId;
    idList<idMD6Node *,5>::PreAllocateWithGranularity(
      this: (idList<idMD6Filter *,5> *)&this->contactPhysicsIds,
      newSize: this->contactPhysicsIds.num + 1);
    v12 = this->contactPhysicsIds.num;
    size = this->contactPhysicsIds.size;
    list = this->contactPhysicsIds.list;
    if ( v12 >= size )
    {
      list[size - 1] = physicsId;
    }
    else
    {
      this->contactPhysicsIds.num = v12 + 1;
      list[v12] = physicsId;
    }
  }
}


// ========================================================================
// ?ClearContacts@idPhysics_DynamicBase@@UAAXXZ
// EA  : 0x82748358
// RVA : 0x00748358
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::ClearContacts(idPhysics_DynamicBase *this)
{
  int v2; // r29
  int v3; // r30
  idPhysics *PhysicsForId; // r3
  idList<contactInfo_t,77> *p_contacts; // r31

  v2 = 0;
  if ( this->contacts.num > 0 )
  {
    v3 = 0;
    do
    {
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: this->contacts.list[v3].physicsId);
      if ( PhysicsForId != nullptr )
        PhysicsForId->RemoveContactPhysics(this: PhysicsForId, a2: this);
      ++v2;
      ++v3;
    }
    while ( v2 < this->contacts.num );
  }
  p_contacts = &this->contacts;
  if ( p_contacts->size < 0 )
  {
    if ( p_contacts->listStatic == 0 || p_contacts->listStatic == 2 )
    {
      if ( p_contacts->list != nullptr )
        idMem::Free(this: &mem, ptr: p_contacts->list, align: ALIGN_16);
      p_contacts->list = nullptr;
      p_contacts->size = 0;
    }
    p_contacts->num = 0;
  }
  p_contacts->num = __CFADD__(-p_contacts->size, p_contacts->size ^ 0x80000000) ? 0 : p_contacts->size;
}


// ========================================================================
// ?AddGroundContacts@idPhysics_DynamicBase@@IAAXPBVidClipModel@@H@Z
// EA  : 0x82748430
// RVA : 0x00748430
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::AddGroundContacts(
        idPhysics_DynamicBase *this,
        const idMat3 *clipModel,
        const idBounds *clipMask)
{
  int v4; // r29
  idList<contactInfo_t,77> *p_contacts; // r31
  contactInfo_t *contacts; // r30
  int granularity; // r4
  int size; // r11
  bool v9; // cr58
  signed int v10; // r10
  int v11; // r4
  int v12; // r11
  int num; // r11
  int v14; // [sp+8h] [-448h]
  const char *v15; // [sp+Ch] [-444h]
  int v16; // [sp+10h] [-440h]
  int v17; // [sp+14h] [-43Ch]
  int v18; // [sp+18h] [-438h]
  int v19; // [sp+1Ch] [-434h]
  int v20; // [sp+20h] [-430h]
  int v21; // [sp+24h] [-42Ch]
  int v22; // [sp+28h] [-428h]
  int v23; // [sp+2Ch] [-424h]
  int v24; // [sp+30h] [-420h]
  int v25; // [sp+34h] [-41Ch]
  int v26; // [sp+38h] [-418h]
  int v27; // [sp+3Ch] [-414h]
  int v28; // [sp+40h] [-410h]
  int v29; // [sp+44h] [-40Ch]
  int v30; // [sp+48h] [-408h]
  int v31; // [sp+4Ch] [-404h]
  int v32; // [sp+50h] [-400h]
  int v33; // [sp+58h] [-3F8h]
  int v34; // [sp+60h] [-3F0h]
  char v35; // [sp+70h] [-3E0h] BYREF
  contactsResult_t v36; // [sp+80h] [-3D0h] BYREF

  v4 = 0;
  idClip::Contacts(
    this: (idClip *)&v35,
    result: this->clip,
    a3: &v36,
    start: (const idVec3 *)&clipModel->mat[2].z,
    dir: &this->gravityNormal,
    depth: 0.5,
    clipModel: (const idClipModel *)this->entityNumber,
    startAxis: clipModel,
    clipMask: (int)&clipModel[1].mat[0].z,
    passEntityNumber: v14,
    userName: v15,
    a12: v16,
    a13: v17,
    a14: v18,
    a15: v19,
    a16: v20,
    a17: v21,
    a18: v22,
    a19: v23,
    a20: v24,
    a21: v25,
    a22: v26,
    a23: v27,
    a24: v28,
    a25: v29,
    a26: v30,
    a27: v31,
    a28: v32,
    a29: clipMask,
    a30: v33,
    a31: (const idClipModel *)this->entityNumber,
    a32: v34,
    a33: 0);
  if ( v36.numContacts > 0 )
  {
    p_contacts = &this->contacts;
    contacts = v36.contacts;
    do
    {
      if ( p_contacts->list != nullptr )
        goto LABEL_7;
      granularity = p_contacts->granularity;
      if ( granularity <= 0 )
        granularity = 1;
      if ( (unsigned __int8)idList<contactInfo_t,77>::Resize(this: p_contacts, newsize: granularity) != 0 )
      {
LABEL_7:
        size = p_contacts->size;
        if ( p_contacts->num != size )
          goto LABEL_18;
        if ( forceIdListsToReallocateEveryAppend )
        {
          v9 = (unsigned __int8)idList<contactInfo_t,77>::Resize(this: p_contacts, newsize: size + 1) == 0;
        }
        else
        {
          v10 = p_contacts->granularity;
          if ( p_contacts->granularity != 0 )
          {
            v12 = size + v10;
            __twllei(v10, 0);
            __twlgei(v10 & ~(__ROL4__(v12, 1) - 1), 0xFFFFFFFF);
            v9 = (unsigned __int8)idList<contactInfo_t,77>::Resize(this: p_contacts, newsize: v12 - v12 % v10) == 0;
          }
          else
          {
            v11 = 2 * size;
            if ( 2 * size >= size )
            {
              if ( v11 == 0 )
                v11 = 1;
              v9 = (unsigned __int8)idList<contactInfo_t,77>::Resize(this: p_contacts, newsize: v11) == 0;
            }
            else
            {
              v9 = (unsigned __int8)idList<contactInfo_t,77>::Resize(this: p_contacts, newsize: 0x7FFFFFFF) == 0;
            }
          }
        }
        if ( !v9 )
        {
LABEL_18:
          num = p_contacts->num;
          if ( num < p_contacts->size )
          {
            contactInfo_t::operator=(this: &p_contacts->list[num], __that: contacts);
            ++p_contacts->num;
          }
        }
      }
      ++v4;
      ++contacts;
    }
    while ( v4 < v36.numContacts );
  }
}


// ========================================================================
// ??0idPhysics_DynamicBase@@QAA@XZ
// EA  : 0x827485E8
// RVA : 0x007485E8
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

idPhysics_DynamicBase *__fastcall idPhysics_DynamicBase::idPhysics_DynamicBase(idPhysics_DynamicBase *this)
{
  idPhysics_DynamicBase *v2; // r3
  idVec3 v4; // [sp+50h] [-40h] BYREF

  idPhysics::idPhysics(this);
  this->__vftable = (idPhysics_DynamicBase_vtbl *)&idPhysics_DynamicBase::`vftable';
  this->contacts.list = nullptr;
  this->contacts.granularity = 0;
  this->contacts.memTag = 77;
  this->contacts.listStatic = 0;
  this->contacts.size = 0;
  this->contacts.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contacts);
  this->contactPhysicsIds.list = nullptr;
  this->contactPhysicsIds.granularity = 0;
  this->contactPhysicsIds.memTag = 77;
  this->contactPhysicsIds.listStatic = 0;
  this->contactPhysicsIds.size = 0;
  this->contactPhysicsIds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactPhysicsIds);
  this->type = PHYSICS_INVALID;
  this->clipMask = 0;
  v4.x = 0.0;
  v4.y = 0.0;
  v4.z = -800.0;
  idPhysics_DynamicBase::SetGravity(this, newGravity: &v4);
  idPhysics_DynamicBase::ClearContacts(this: v2);
  this->waterLevel = 0;
  this->waterViscosity = 0.0;
  return this;
}


// ========================================================================
// __unwind$248654
// EA  : 0x827486A4
// RVA : 0x007486A4
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void _unwind_248654()
{
  int v0; // r12

  idPhysics::~idPhysics(this: *(idPhysics **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$248655
// EA  : 0x827486CC
// RVA : 0x007486CC
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void _unwind_248655()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 76));
}


// ========================================================================
// __unwind$248656
// EA  : 0x827486F8
// RVA : 0x007486F8
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void _unwind_248656()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 92));
}


// ========================================================================
// ??1idPhysics_DynamicBase@@UAA@XZ
// EA  : 0x82748730
// RVA : 0x00748730
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void __fastcall idPhysics_DynamicBase::~idPhysics_DynamicBase(idPhysics_DynamicBase *this)
{
  this->__vftable = (idPhysics_DynamicBase_vtbl *)&idPhysics_DynamicBase::`vftable';
  idPhysics_DynamicBase::ClearContacts(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactPhysicsIds);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contacts);
  idPhysics::~idPhysics(this);
}


// ========================================================================
// __unwind$248718
// EA  : 0x82748790
// RVA : 0x00748790
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void _unwind_248718()
{
  int v0; // r12

  idPhysics::~idPhysics(this: *(idPhysics **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$248719
// EA  : 0x827487B8
// RVA : 0x007487B8
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void _unwind_248719()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 76));
}


// ========================================================================
// __unwind$248720
// EA  : 0x827487E4
// RVA : 0x007487E4
// PDB : w:\tech5\engine\gamelib\physics\physics_dynamicbase.cpp
// ========================================================================

void _unwind_248720()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 92));
}

