
// ========================================================================
// ??0idTest_RandomAimPoint@@QAA@XZ
// EA  : 0x82CE1048
// RVA : 0x00CE1048
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

idTest_RandomAimPoint *__fastcall idTest_RandomAimPoint::idTest_RandomAimPoint(idTest_RandomAimPoint *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTest_RandomAimPoint_vtbl *)&idTest_RandomAimPoint::`vftable';
  this->interval = 5.0;
  this->nextChangeTime = -1;
  this->distance = 128.0;
  this->point = vec3_origin;
  return this;
}


// ========================================================================
// ??0idTest_ConeConstraint@@QAA@XZ
// EA  : 0x82CE10D0
// RVA : 0x00CE10D0
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

idTest_ConeConstraint *__fastcall idTest_ConeConstraint::idTest_ConeConstraint(idTest_ConeConstraint *this)
{
  idSegment **v2; // r3
  int numSegments; // r6

  idEntity::idEntity(this);
  this->numSegments = 10;
  this->__vftable = (idTest_ConeConstraint_vtbl *)&idTest_ConeConstraint::`vftable';
  v2 = (idSegment **)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\tungsten\\game\\entities\\TestEntities.cpp(317) : TAG_TEMP",
                       size: 0x28u,
                       tag: TAG_TEMP,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  numSegments = this->numSegments;
  this->segments = v2;
  memset(Dst: v2, Val: 0, Size: 4 * numSegments);
  return this;
}


// ========================================================================
// __unwind$487768_0
// EA  : 0x82CE1160
// RVA : 0x00CE1160
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void _unwind_487768_0()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTest_AimPoint@@QAA@XZ
// EA  : 0x82CE1188
// RVA : 0x00CE1188
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

idTest_AimPoint *__fastcall idTest_AimPoint::idTest_AimPoint(idTest_AimPoint *this)
{
  idLinkList<idEntity> *v2; // r10
  float *p_y; // r11
  int i; // ctr

  idEntity::idEntity(this);
  this->__vftable = (idTest_AimPoint_vtbl *)&idTest_AimPoint::`vftable';
  v2 = &this->removeNode + 1;
  p_y = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
  {
    ++p_y;
    v2 = (idLinkList<idEntity> *)((char *)v2 + 4);
    v2->head = *(idLinkList<idEntity> **)p_y;
  }
  this->offset.x = 0.0;
  this->offset.y = 0.0;
  this->offset.z = 0.0;
  this->startActive = true;
  this->visible = true;
  this->degreesPerSec = 90.0;
  this->startTime = 0;
  this->stopTime = -1;
  return this;
}


// ========================================================================
// ?Think@idTest_AimPoint@@UAAXXZ
// EA  : 0x82CE1290
// RVA : 0x00CE1290
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_AimPoint::Think(idTest_AimPoint *this)
{
  idRenderWorld *v1; // r3
  _BYTE v2[24]; // [sp+50h] [-20h] BYREF

  if ( this->visible )
  {
    this->GetAimPoint(this, a2: AIMPOINT_ORIGIN, a3: (idVec3 *)v2);
    v1 = gameLocal->GetRenderWorld(this: gameLocal);
    v1->DebugPoint(this: v1, a2: (const idVec4 *)&idColor::colorCyan, a3: (const idVec3 *)v2, a4: 1, a5: true);
  }
  else
  {
    idEntity::BecomeInactive(this, flags: 1);
  }
}


// ========================================================================
// ?Start@idTest_AimPoint@@AAAXXZ
// EA  : 0x82CE1328
// RVA : 0x00CE1328
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_AimPoint::Start(idTest_AimPoint *this)
{
  int GameMs; // r3
  BOOL visible; // r9

  this->stopTime = -1;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  visible = this->visible;
  this->startTime = GameMs;
  if ( visible )
    idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?Spawn@idTest_RandomAimPoint@@QAAXXZ
// EA  : 0x82CE13F8
// RVA : 0x00CE13F8
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_RandomAimPoint::Spawn(idTest_RandomAimPoint *this)
{
  double distance; // fp0
  double y; // fp12
  double z; // fp10

  distance = this->distance;
  y = this->spawnPosition.y;
  z = this->spawnPosition.z;
  this->point.x = this->spawnPosition.x + this->distance;
  this->point.y = (float)y + (float)((float)distance * (float)0.0);
  this->point.z = (float)z + (float)((float)distance * (float)0.0);
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?Think@idTest_RandomAimPoint@@UAAXXZ
// EA  : 0x82CE1438
// RVA : 0x00CE1438
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_RandomAimPoint::Think(idTest_RandomAimPoint *this)
{
  idClientGame *v2; // r3
  idClientGame *v3; // r9
  __int64 v4; // r6
  __int64 v5; // r3
  __int64 v6; // r10
  unsigned int v7; // r4
  double distance; // fp1
  double v9; // fp2
  double v10; // fp9
  double v11; // fp6
  double v14; // fp11
  double y; // fp4
  double z; // fp3
  double v17; // fp8
  idRenderWorld *v18; // r3

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->nextChangeTime )
  {
    this->nextChangeTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                         - (int)(float)(this->interval * (float)-1000.0);
    v2 = clientGame;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    v3 = clientGame;
    HIDWORD(v4) = 1664525 * clientGame->random.seed + 1013904223;
    LODWORD(v4) = (v2->random.seed >> 10) & 0x7FFF;
    clientGame->random.seed = HIDWORD(v4);
    LODWORD(v5) = (v3->random.seed >> 10) & 0x7FFF;
    HIDWORD(v6) = clientGame->random.seed;
    v7 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v7;
    LODWORD(v6) = (v7 >> 10) & 0x7FFF;
    distance = this->distance;
    v9 = (float)((float)((float)v5 * (float)0.000030518509) - (float)0.5);
    v10 = (float)((float)((float)v4 * (float)0.000030518509) - (float)0.5);
    v11 = (float)((float)((float)v6 * (float)0.000030518509) - (float)0.5);
    _FP3 = (float)((float)((float)((float)v11 * (float)v11)
                         + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f12, f3, f4, f12 }
    v14 = __frsqrte(_FP12);
    y = this->spawnPosition.y;
    z = this->spawnPosition.z;
    v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                        * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                                * (float)0.5))
                                                                                * (float)v14)
                                                                        - (float)1.5)
                                                        * (float)v14)
                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                + (float)((float)((float)v10 * (float)v10)
                                                                        + (float)((float)v9 * (float)v9)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v14
                                                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                                                + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                        * (float)0.5))
                                                                        * (float)v14)
                                                                - (float)1.5)
                                                * (float)v14))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v14
                                                        * (float)((float)((float)((float)v11 * (float)v11)
                                                                        + (float)((float)((float)v10 * (float)v10)
                                                                                + (float)((float)v9 * (float)v9)))
                                                                * (float)0.5))
                                                * (float)v14)
                                        - (float)1.5)
                        * (float)v14));
    this->point.x = this->spawnPosition.x
                  + (float)(this->distance
                          * (float)((float)v11
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14) * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14))
                                                                                                  - (float)1.5)
                                                                                  * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                          * (float)v14))
                                                                          * (float)((float)((float)((float)v11
                                                                                                  * (float)v11)
                                                                                          + (float)((float)((float)v10 * (float)v10)
                                                                                                  + (float)((float)v9 * (float)v9)))
                                                                                  * (float)0.5))
                                                                  * (float)v17)
                                                          - (float)1.5)
                                          * (float)v17)));
    this->point.y = (float)y
                  + (float)((float)((float)v9
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14) * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14))
                                                                                                  - (float)1.5)
                                                                                  * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                          * (float)v14))
                                                                          * (float)((float)((float)((float)v11
                                                                                                  * (float)v11)
                                                                                          + (float)((float)((float)v10 * (float)v10)
                                                                                                  + (float)((float)v9 * (float)v9)))
                                                                                  * (float)0.5))
                                                                  * (float)v17)
                                                          - (float)1.5)
                                          * (float)v17))
                          * (float)distance);
    this->point.z = (float)z
                  + (float)((float)((float)v10
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14) * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14))
                                                                                                  - (float)1.5)
                                                                                  * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                          * (float)v14))
                                                                          * (float)((float)((float)((float)v11
                                                                                                  * (float)v11)
                                                                                          + (float)((float)((float)v10 * (float)v10)
                                                                                                  + (float)((float)v9 * (float)v9)))
                                                                                  * (float)0.5))
                                                                  * (float)v17)
                                                          - (float)1.5)
                                          * (float)v17))
                          * (float)distance);
  }
  v18 = gameLocal->GetRenderWorld(this: gameLocal);
  v18->DebugPoint(this: v18, a2: (const idVec4 *)&idColor::colorCyan, a3: &this->point, a4: 1, a5: true);
}


// ========================================================================
// ?GetAimPoint@idTest_RandomAimPoint@@UBAXW4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82CE1650
// RVA : 0x00CE1650
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_RandomAimPoint::GetAimPoint(idTest_RandomAimPoint *this, const aimPoint_t type, idVec3 *pos)
{
  *pos = this->point;
}


// ========================================================================
// ??1idTest_ConeConstraint@@UAA@XZ
// EA  : 0x82CE1678
// RVA : 0x00CE1678
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_ConeConstraint::~idTest_ConeConstraint(idTest_ConeConstraint *this)
{
  int v2; // r28
  int v3; // r30
  idSegment **segments; // r11

  this->__vftable = (idTest_ConeConstraint_vtbl *)&idTest_ConeConstraint::`vftable';
  if ( this->segments != nullptr )
  {
    v2 = 0;
    if ( this->numSegments > 0 )
    {
      v3 = 0;
      do
      {
        segments = this->segments;
        if ( segments[v3] != nullptr )
        {
          idMem::Free(this: &mem, ptr: segments[v3], align: ALIGN_16);
          this->segments[v3] = nullptr;
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->numSegments );
    }
    idMem::Free(this: &mem, ptr: this->segments, align: ALIGN_16);
    this->segments = nullptr;
  }
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$488390
// EA  : 0x82CE1728
// RVA : 0x00CE1728
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void _unwind_488390()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 144 + 164));
}


// ========================================================================
// ?Spawn@idTest_ConeConstraint@@QAAXXZ
// EA  : 0x82CE1758
// RVA : 0x00CE1758
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_ConeConstraint::Spawn(idTest_ConeConstraint *this, long double a2)
{
  float y; // r6
  int v4; // r28
  float z; // r5
  int numSegments; // r4
  double v7; // fp30
  double v8; // fp31
  double v9; // fp29
  int v10; // r27
  float v11; // r3
  idSegment *v12; // r30
  float v13; // r10
  float v14; // r9
  idSegment **segments; // r11
  int v16; // r10
  idTypesafeNumber<float,enum RadiansUnique_t> v17; // [sp+50h] [-C0h] BYREF
  float x; // [sp+58h] [-B8h]
  float v19; // [sp+5Ch] [-B4h]
  float v20; // [sp+60h] [-B0h]
  idVec3 v21; // [sp+68h] [-A8h] BYREF
  idConeConstraint_Vec3 v22; // [sp+80h] [-90h] BYREF

  v17.value = cone_limit.valueFloat;
  v21.x = 1.0;
  v21.y = 0.0;
  v21.z = 0.0;
  idConeConstraint_Vec3::idConeConstraint_Vec3(this: &v22, center_: &v21, maxAngle_: &v17, a4: a2);
  y = this->spawnPosition.y;
  v4 = 0;
  z = this->spawnPosition.z;
  numSegments = this->numSegments;
  x = this->spawnPosition.x;
  v19 = y;
  v20 = z;
  if ( numSegments > 0 )
  {
    v7 = v20;
    v8 = v19;
    v9 = x;
    v10 = 0;
    do
    {
      v11 = COERCE_FLOAT(
              idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                size: 0x30u,
                tag: TAG_NEW,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP));
      v12 = (idSegment *)LODWORD(v11);
      v17.value = v11;
      if ( v11 == 0.0 )
      {
        v12 = nullptr;
      }
      else
      {
        v13 = v19;
        v14 = v20;
        *(float *)LODWORD(v11) = x;
        *(float *)(LODWORD(v11) + 4) = v13;
        *(float *)(LODWORD(v11) + 8) = v14;
        idConeConstraint_Vec3::idConeConstraint_Vec3(this: (idConeConstraint_Vec3 *)(LODWORD(v11) + 12), other: &v22);
      }
      segments = this->segments;
      ++v4;
      v19 = v8;
      v20 = v7;
      segments[v10] = v12;
      v16 = this->numSegments;
      v9 = (float)(cone_segmentLen.valueFloat + (float)v9);
      x = v9;
      ++v10;
    }
    while ( v4 < v16 );
  }
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// __unwind$488423
// EA  : 0x82CE18B0
// RVA : 0x00CE18B0
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall _unwind_488423(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 272 + 80), tag: a2);
}


// ========================================================================
// ?OnActivate@idTest_AimPoint@@UAAXPAVidEntity@@@Z
// EA  : 0x82CE18D8
// RVA : 0x00CE18D8
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_AimPoint::OnActivate(idTest_AimPoint *this, idEntity *activator)
{
  if ( (this->thinkFlags & 1) != 0 )
  {
    this->stopTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idEntity::BecomeInactive(this, flags: 1);
  }
  else
  {
    idTest_AimPoint::Start(this);
  }
}


// ========================================================================
// ?Spawn@idTest_AimPoint@@QAAXXZ
// EA  : 0x82CE19B8
// RVA : 0x00CE19B8
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_AimPoint::Spawn(idTest_AimPoint *this)
{
  int value; // r9
  idEntity *v3; // r3
  idEntity *v4; // r30
  idPhysics *Physics; // r3
  float *v6; // r3
  double v7; // fp7
  double v8; // fp6
  float x; // r7
  float y; // r6
  idMat3 v11; // [sp+50h] [-50h] BYREF

  if ( this->targets.num > 0 )
  {
    value = this->targets.list->spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v4 = idEntity::CastTo(c: v3);
    }
    else
    {
      v4 = nullptr;
    }
    if ( v4 == nullptr )
      idLib::Error(fmt: "idTest_AimPoint '%s' has no target.", this->name.data);
    Physics = idEntity::GetPhysics(this);
    v6 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v7 = (float)(v6[1] - v4->spawnPosition.y);
    v8 = (float)(v6[2] - v4->spawnPosition.z);
    this->offset.x = *v6 - v4->spawnPosition.x;
    this->offset.y = v7;
    this->offset.z = v8;
    x = this->offset.x;
    y = this->offset.y;
    v11.mat[0].z = this->offset.z;
    v11.mat[0].y = y;
    v11.mat[0].x = x;
    idVec3::NormalizeFast(this: v11.mat);
    this->axis = *idVec3::ToMat3(this: (idVec3 *)&v11.mat[1].y, result: &v11);
    if ( this->startActive )
      idTest_AimPoint::Start(this);
  }
  else
  {
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
  }
}


// ========================================================================
// ?GetAimPoint@idTest_AimPoint@@UBAXW4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82CE1B50
// RVA : 0x00CE1B50
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_AimPoint::GetAimPoint(idTest_AimPoint *this, const aimPoint_t type, idVec3 *pos)
{
  int stopTime; // r11
  int v6; // r8
  char *v7; // r10
  idLinkList<idEntity> *v8; // r11
  int i; // ctr
  int value; // r9
  idEntity *v11; // r3
  idEntity *v12; // r3
  idPhysics *Physics; // r3
  double v14; // fp5
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  float *v18; // r3
  double v19; // fp0
  double v20; // fp13
  char v21; // [sp+5Ch] [-64h] BYREF
  idMat3 v22; // [sp+60h] [-60h] BYREF

  stopTime = this->stopTime;
  if ( stopTime >= 0 )
    v6 = stopTime - this->startTime;
  else
    v6 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->startTime;
  v7 = &v21;
  v8 = &this->removeNode + 1;
  for ( i = 9; i != 0; --i )
  {
    v8 = (idLinkList<idEntity> *)((char *)v8 + 4);
    v7 += 4;
    *(_DWORD *)v7 = v8->head;
  }
  idMat3::RotateSelf(
    this: &v22,
    axis: &this->axis.mat[2],
    angle: (float)((float)((float)((float)__SPAIR64__(&off_82040000, v6) * (float)0.001) * this->degreesPerSec)
          * idMath::M_DEG2RAD));
  if ( this->targets.num > 0
    && (value = this->targets.list->spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v11 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v12 = idEntity::CastTo(c: v11);
  }
  else
  {
    v12 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v12);
  v14 = __fsqrts((float)((float)(this->offset.z * this->offset.z)
                       + (float)((float)(this->offset.x * this->offset.x) + (float)(this->offset.y * this->offset.y))));
  v15 = (float)(v22.mat[0].x * (float)v14);
  v16 = (float)(v22.mat[0].y * (float)v14);
  v17 = (float)(v22.mat[0].z * (float)v14);
  v18 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v19 = (float)(v18[1] + (float)v16);
  v20 = (float)(v18[2] + (float)v17);
  pos->x = *v18 + (float)v15;
  pos->y = v19;
  pos->z = v20;
}


// ========================================================================
// ?Think@idTest_RotationTracker@@UAAXXZ
// EA  : 0x82CE1CF8
// RVA : 0x00CE1CF8
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_RotationTracker::Think(idTest_RotationTracker *this)
{
  int value; // r9
  idEntity *v3; // r3
  idEntity *v4; // r3
  idPlayer *DebugPlayer; // r3
  idPhysics *Physics; // r3
  float *v7; // r29
  idPhysics *v8; // r3
  int v9; // r3
  double v10; // fp5
  const idMat3 *v11; // r28
  double v14; // fp9
  double v15; // fp13
  double v16; // fp9
  double v17; // fp7
  __int64 v18; // r9
  idRotationTracker *p_tracker; // r30
  idRenderWorld *v20; // r3
  idRenderWorld *v21; // r3
  double v22; // fp10
  double v23; // fp6
  idRenderWorld *v24; // r3
  double v25; // fp10
  double v26; // fp8
  idRenderWorld *v27; // r3
  double v28; // fp13
  double v29; // fp10
  float v30; // [sp+58h] [-B8h] BYREF
  float v31; // [sp+5Ch] [-B4h]
  float v32; // [sp+60h] [-B0h]
  float v33[4]; // [sp+68h] [-A8h] BYREF
  float v34[4]; // [sp+78h] [-98h] BYREF
  float v35[4]; // [sp+88h] [-88h] BYREF
  float v36[6]; // [sp+98h] [-78h] BYREF
  idMat3 v37; // [sp+B0h] [-60h] BYREF

  if ( this->targets.num > 0
    && ((value = this->targets.list->spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13)
     || (v3 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
      ? (v4 = nullptr)
      : (v4 = idEntity::CastTo(c: v3)),
        v4 != nullptr) )
  {
    v4->GetAimPoint(this: v4, a2: AIMPOINT_BEST, a3: (idVec3 *)&v30);
  }
  else
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    if ( DebugPlayer == nullptr )
      return;
    DebugPlayer->GetEyePos(this: DebugPlayer, a2: (idVec3 *)&v30);
  }
  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = idEntity::GetPhysics(this);
  v9 = (int)v8->GetAxis(this: v8, a2: 0);
  v10 = (float)(v32 - v7[2]);
  v11 = (const idMat3 *)v9;
  _FP1 = (float)((float)((float)((float)(v32 - v7[2]) * (float)(v32 - v7[2]))
                       + (float)((float)((float)(v30 - *v7) * (float)(v30 - *v7))
                               + (float)((float)(v31 - v7[1]) * (float)(v31 - v7[1]))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f10, f1, f2, f13 }
  v14 = __frsqrte(_FP10);
  v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)((float)((float)(v32 - v7[2]) * (float)(v32 - v7[2])) + (float)((float)((float)(v30 - *v7) * (float)(v30 - *v7)) + (float)((float)(v31 - v7[1]) * (float)(v31 - v7[1]))))
                                                                                              * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14)
                                              * (float)((float)((float)((float)(v32 - v7[2]) * (float)(v32 - v7[2]))
                                                              + (float)((float)((float)(v30 - *v7) * (float)(v30 - *v7))
                                                                      + (float)((float)(v31 - v7[1])
                                                                              * (float)(v31 - v7[1]))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                              * (float)((float)((float)((float)(v32 - v7[2]) * (float)(v32 - v7[2]))
                                                                                              + (float)((float)((float)(v30 - *v7) * (float)(v30 - *v7)) + (float)((float)(v31 - v7[1]) * (float)(v31 - v7[1]))))
                                                                                      * (float)0.5))
                                                                      * (float)v14)
                                                              - (float)1.5)
                                              * (float)v14))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v14
                                                      * (float)((float)((float)((float)(v32 - v7[2])
                                                                              * (float)(v32 - v7[2]))
                                                                      + (float)((float)((float)(v30 - *v7)
                                                                                      * (float)(v30 - *v7))
                                                                              + (float)((float)(v31 - v7[1])
                                                                                      * (float)(v31 - v7[1]))))
                                                              * (float)0.5))
                                              * (float)v14)
                                      - (float)1.5)
                      * (float)v14));
  v16 = (float)((float)-(float)((float)((float)((float)v15
                                              * (float)((float)((float)((float)(v32 - v7[2]) * (float)(v32 - v7[2]))
                                                              + (float)((float)((float)(v30 - *v7) * (float)(v30 - *v7))
                                                                      + (float)((float)(v31 - v7[1])
                                                                              * (float)(v31 - v7[1]))))
                                                      * (float)0.5))
                                      * (float)v15)
                              - (float)1.5)
              * (float)v15);
  v17 = (float)((float)(v31 - v7[1])
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)(v32 - v7[2])
                                                                              * (float)(v32 - v7[2]))
                                                                      + (float)((float)((float)(v30 - *v7)
                                                                                      * (float)(v30 - *v7))
                                                                              + (float)((float)(v31 - v7[1])
                                                                                      * (float)(v31 - v7[1]))))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v33[0] = (float)(v30 - *v7)
         * (float)((float)-(float)((float)((float)((float)v15
                                                 * (float)((float)((float)((float)(v32 - v7[2]) * (float)(v32 - v7[2]))
                                                                 + (float)((float)((float)(v30 - *v7)
                                                                                 * (float)(v30 - *v7))
                                                                         + (float)((float)(v31 - v7[1])
                                                                                 * (float)(v31 - v7[1]))))
                                                         * (float)0.5))
                                         * (float)v15)
                                 - (float)1.5)
                 * (float)v15);
  v33[1] = v17;
  v33[2] = (float)v10 * (float)v16;
  LODWORD(v18) = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
  HIDWORD(v18) = this->tracker.__vftable;
  p_tracker = &this->tracker;
  (*(void (__fastcall **)(idRotationTracker *, float *, const idMat3 *, float *, double))(HIDWORD(v18) + 4))(
    a1: p_tracker,
    a2: v7,
    a3: v11,
    a4: v33,
    a5: (float)((float)v18 * (float)0.001));
  idRotationTracker::GetWorldSpaceAxis(this: p_tracker, refAxis: v11, wsAxis: &v37);
  v20 = gameLocal->GetRenderWorld(this: gameLocal);
  v20->DebugLine(
    this: v20,
    a2: (const idVec4 *)&idColor::colorLtGrey,
    a3: (const idVec3 *)v7,
    a4: (const idVec3 *)&v30,
    a5: 0,
    a6: true);
  v21 = gameLocal->GetRenderWorld(this: gameLocal);
  v22 = *v7;
  v23 = (float)(v7[2] + (float)(v37.mat[0].z * (float)64.0));
  v34[1] = v7[1] + (float)(v37.mat[0].y * (float)64.0);
  v34[2] = v23;
  v34[0] = (float)v22 + (float)(v37.mat[0].x * (float)64.0);
  v21->DebugLine(
    this: v21,
    a2: (const idVec4 *)&idColor::colorGreen,
    a3: (const idVec3 *)v7,
    a4: (const idVec3 *)v34,
    a5: 0,
    a6: true);
  v24 = gameLocal->GetRenderWorld(this: gameLocal);
  v25 = *v7;
  v26 = (float)(v7[2] + (float)(v37.mat[1].z * (float)64.0));
  v35[1] = v7[1] + (float)(v37.mat[1].y * (float)64.0);
  v35[2] = v26;
  v35[0] = (float)v25 + (float)(v37.mat[1].x * (float)64.0);
  v24->DebugLine(
    this: v24,
    a2: (const idVec4 *)&idColor::colorRed,
    a3: (const idVec3 *)v7,
    a4: (const idVec3 *)v35,
    a5: 0,
    a6: true);
  v27 = gameLocal->GetRenderWorld(this: gameLocal);
  v28 = v7[1];
  v29 = (float)(*v7 + (float)(v37.mat[2].x * (float)64.0));
  v36[2] = v7[2] + (float)(v37.mat[2].z * (float)64.0);
  v36[0] = v29;
  v36[1] = (float)v28 + (float)(v37.mat[2].y * (float)64.0);
  v27->DebugLine(
    this: v27,
    a2: (const idVec4 *)&idColor::colorBlue,
    a3: (const idVec3 *)v7,
    a4: (const idVec3 *)v36,
    a5: 0,
    a6: true);
}


// ========================================================================
// ?Think@idTest_ConeConstraint@@UAAXXZ
// EA  : 0x82CE20B8
// RVA : 0x00CE20B8
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __fastcall idTest_ConeConstraint::Think(idTest_ConeConstraint *this)
{
  int value; // r9
  idEntity *v3; // r3
  idPlayer *Player; // r3
  int v5; // r30
  int v6; // r29
  idSegment **v7; // r11
  idSegment *v8; // r31
  float *v9; // r11
  double v10; // fp9
  double v11; // fp8
  double v12; // fp6
  double v13; // fp5
  double v14; // fp6
  double v17; // fp10
  double v18; // fp0
  double v19; // fp10
  double v20; // fp8
  idRenderWorld *v21; // r3
  double v22; // fp11
  double x; // fp10
  double v24; // fp8
  float v25; // [sp+50h] [-A0h] BYREF
  float v26; // [sp+54h] [-9Ch]
  float v27; // [sp+58h] [-98h]
  idVec3 v28; // [sp+60h] [-90h] BYREF
  float v29[6]; // [sp+70h] [-80h] BYREF

  if ( this->targets.num <= 0 )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  }
  else
  {
    value = this->targets.list->spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      Player = (idPlayer *)idEntity::CastTo(c: v3);
    }
    else
    {
      Player = nullptr;
    }
  }
  if ( Player != nullptr )
  {
    Player->GetAimPoint(this: Player, a2: AIMPOINT_CENTER, a3: (idVec3 *)&v25);
    v5 = 0;
    if ( this->numSegments > 0 )
    {
      v6 = 0;
      do
      {
        v7 = &this->segments[v6];
        v8 = *v7;
        if ( v5 > 0 )
        {
          v9 = (float *)*(v7 - 1);
          v10 = (float)(cone_segmentLen.valueFloat * v9[4]);
          v11 = (float)(cone_segmentLen.valueFloat * v9[5]);
          v12 = v9[1];
          v13 = v9[2];
          v8->origin.x = *v9 + (float)(v9[3] * cone_segmentLen.valueFloat);
          v8->origin.y = (float)v12 + (float)v10;
          v8->origin.z = (float)v13 + (float)v11;
          v8->coneConstraint.center.x = v9[3];
          v8->coneConstraint.center.y = v9[4];
          v8->coneConstraint.center.z = v9[5];
        }
        v14 = (float)(v27 - v8->origin.z);
        _FP2 = (float)((float)((float)((float)(v27 - v8->origin.z) * (float)(v27 - v8->origin.z))
                             + (float)((float)((float)(v25 - v8->origin.x) * (float)(v25 - v8->origin.x))
                                     + (float)((float)(v26 - v8->origin.y) * (float)(v26 - v8->origin.y))))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f11, f2, f3, f0 }
        v17 = __frsqrte(_FP11);
        v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                            * (float)((float)((float)((float)(v27 - v8->origin.z) * (float)(v27 - v8->origin.z)) + (float)((float)((float)(v25 - v8->origin.x) * (float)(v25 - v8->origin.x)) + (float)((float)(v26 - v8->origin.y) * (float)(v26 - v8->origin.y)))) * (float)0.5))
                                                                                    * (float)v17)
                                                                            - (float)1.5)
                                                            * (float)v17)
                                                    * (float)((float)((float)((float)(v27 - v8->origin.z)
                                                                            * (float)(v27 - v8->origin.z))
                                                                    + (float)((float)((float)(v25 - v8->origin.x)
                                                                                    * (float)(v25 - v8->origin.x))
                                                                            + (float)((float)(v26 - v8->origin.y)
                                                                                    * (float)(v26 - v8->origin.y))))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v17
                                                                                    * (float)((float)((float)((float)(v27 - v8->origin.z) * (float)(v27 - v8->origin.z)) + (float)((float)((float)(v25 - v8->origin.x) * (float)(v25 - v8->origin.x)) + (float)((float)(v26 - v8->origin.y) * (float)(v26 - v8->origin.y))))
                                                                                            * (float)0.5))
                                                                            * (float)v17)
                                                                    - (float)1.5)
                                                    * (float)v17))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v17
                                                            * (float)((float)((float)((float)(v27 - v8->origin.z)
                                                                                    * (float)(v27 - v8->origin.z))
                                                                            + (float)((float)((float)(v25 - v8->origin.x)
                                                                                            * (float)(v25 - v8->origin.x))
                                                                                    + (float)((float)(v26 - v8->origin.y)
                                                                                            * (float)(v26 - v8->origin.y))))
                                                                    * (float)0.5))
                                                    * (float)v17)
                                            - (float)1.5)
                            * (float)v17));
        v19 = (float)((float)-(float)((float)((float)((float)v18
                                                    * (float)((float)((float)((float)(v27 - v8->origin.z)
                                                                            * (float)(v27 - v8->origin.z))
                                                                    + (float)((float)((float)(v25 - v8->origin.x)
                                                                                    * (float)(v25 - v8->origin.x))
                                                                            + (float)((float)(v26 - v8->origin.y)
                                                                                    * (float)(v26 - v8->origin.y))))
                                                            * (float)0.5))
                                            * (float)v18)
                                    - (float)1.5)
                    * (float)v18);
        v20 = (float)((float)(v26 - v8->origin.y)
                    * (float)((float)-(float)((float)((float)((float)v18
                                                            * (float)((float)((float)((float)(v27 - v8->origin.z)
                                                                                    * (float)(v27 - v8->origin.z))
                                                                            + (float)((float)((float)(v25 - v8->origin.x)
                                                                                            * (float)(v25 - v8->origin.x))
                                                                                    + (float)((float)(v26 - v8->origin.y)
                                                                                            * (float)(v26 - v8->origin.y))))
                                                                    * (float)0.5))
                                                    * (float)v18)
                                            - (float)1.5)
                            * (float)v18));
        v28.x = (float)(v25 - v8->origin.x)
              * (float)((float)-(float)((float)((float)((float)v18
                                                      * (float)((float)((float)((float)(v27 - v8->origin.z)
                                                                              * (float)(v27 - v8->origin.z))
                                                                      + (float)((float)((float)(v25 - v8->origin.x)
                                                                                      * (float)(v25 - v8->origin.x))
                                                                              + (float)((float)(v26 - v8->origin.y)
                                                                                      * (float)(v26 - v8->origin.y))))
                                                              * (float)0.5))
                                              * (float)v18)
                                      - (float)1.5)
                      * (float)v18);
        v28.y = v20;
        v28.z = (float)v14 * (float)v19;
        idConeConstraint_Vec3::RotateTo(this: &v8->coneConstraint, dir: &v28, lerpRate: cone_lerpRate.valueFloat);
        v21 = common->RW(this: common);
        v22 = (float)(v8->coneConstraint.current.x * cone_segmentLen.valueFloat);
        x = v8->origin.x;
        v24 = (float)(v8->origin.z + (float)(v8->coneConstraint.current.z * cone_segmentLen.valueFloat));
        v29[1] = v8->origin.y + (float)(v8->coneConstraint.current.y * cone_segmentLen.valueFloat);
        v29[2] = v24;
        v29[0] = (float)x + (float)v22;
        ((void (__fastcall *)(idRenderWorld *, idColor *, idSegment *, float *, double))v21->DebugArrow)(
          a1: v21,
          a2: &idColor::colorRed,
          a3: v8,
          a4: v29,
          a5: 2.0);
        ++v5;
        ++v6;
      }
      while ( v5 < this->numSegments );
    }
  }
}


// ========================================================================
// `dynamic initializer for 'cone_segmentLen''
// EA  : 0x833795A8
// RVA : 0x013795A8
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cone_segmentLen__()
{
  idCVar::idCVar(
    this: &cone_segmentLen,
    name: "cone_segmentLen",
    value: "6.4",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cone_segmentLen__);
}


// ========================================================================
// `dynamic initializer for 'cone_limit''
// EA  : 0x83379600
// RVA : 0x01379600
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cone_limit__()
{
  idCVar::idCVar(
    this: &cone_limit,
    name: "cone_limit",
    value: "0.785398163397",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cone_limit__);
}


// ========================================================================
// `dynamic initializer for 'cone_lerpRate''
// EA  : 0x83379658
// RVA : 0x01379658
// PDB : w:\tech5\tungsten\game\entities\testentities.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cone_lerpRate__()
{
  idCVar::idCVar(
    this: &cone_lerpRate,
    name: "cone_lerpRate",
    value: "0.1",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cone_lerpRate__);
}

