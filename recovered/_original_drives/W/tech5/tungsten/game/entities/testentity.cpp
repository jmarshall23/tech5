
// ========================================================================
// ??0idTestEntity@@QAA@XZ
// EA  : 0x82CE2480
// RVA : 0x00CE2480
// PDB : w:\tech5\tungsten\game\entities\testentity.cpp
// ========================================================================

idTestEntity *__fastcall idTestEntity::idTestEntity(idTestEntity *this)
{
  char *v2; // r28
  int v3; // ctr
  const idDeclWeapon **p_weaponDef; // r11
  int list; // r11
  int v6; // r11
  int v7; // r9
  int v8; // r10
  float *v9; // r11
  float *v10; // r11

  idEntity::idEntity(this);
  this->__vftable = (idTestEntity_vtbl *)&idTestEntity::`vftable';
  DWORD2(this->double_) = &idBoundedInt<0,4>::`vftable';
  this->boundedInt.__vftable = (idBoundedInt<0,4>_vtbl *)&idBoundedFloat<0,0,1,0>::`vftable';
  this->enum_ = TESTME_FLAG1;
  this->string.len = 20;
  *(_DWORD *)&this->testFlags = &this->string.data;
  HIBYTE(this->string.data) = 0;
  this->color.g = -1.0;
  this->color.r = -1.0;
  *(float *)&this->string.baseBuffer[16] = -1.0;
  *(float *)&this->string.baseBuffer[12] = -1.0;
  this->weaponDef = (const idDeclWeapon *)0x1FFF;
  this->intArray[8] = 0;
  HIWORD(this->intList.num) = 0;
  BYTE2(this->intList.num) = 5;
  LOBYTE(this->intList.num) = 0;
  this->intList.list = nullptr;
  this->intArray[9] = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->intArray[8]);
  HIWORD(this->strList.num) = 0;
  BYTE2(this->strList.num) = 5;
  LOBYTE(this->strList.num) = 0;
  this->intList.size = 0;
  this->strList.list = nullptr;
  *(_DWORD *)&this->intList.granularity = 0;
  this->strList.size = 0;
  HIWORD(this->soundList.num) = 0;
  BYTE2(this->soundList.num) = 5;
  LOBYTE(this->soundList.num) = 0;
  this->soundList.list = nullptr;
  *(_DWORD *)&this->strList.granularity = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->strList.size);
  HIWORD(this->spawnRenderParmBlock.num) = 0;
  BYTE2(this->spawnRenderParmBlock.num) = 5;
  LOBYTE(this->spawnRenderParmBlock.num) = 0;
  this->soundList.size = 0;
  this->spawnRenderParmBlock.list = nullptr;
  *(_DWORD *)&this->soundList.granularity = 0;
  `eh vector constructor iterator'(
    ptr: &this->spawnRenderParmBlock.size,
    size: 0x24u,
    count: 10,
    pCtor: (void (__fastcall *)(void *))idSpawnRenderParm::idSpawnRenderParm,
    pDtor: (void (__fastcall *)(void *))idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels);
  *(_DWORD *)&this->spawnRenderParmArray[9].value.baseBuffer[12] = 0;
  HIWORD(this->structList.num) = 0;
  v2 = &this->spawnRenderParmArray[9].value.baseBuffer[12];
  BYTE2(this->structList.num) = 5;
  LOBYTE(this->structList.num) = 0;
  this->structList.list = nullptr;
  *(_DWORD *)&this->spawnRenderParmArray[9].value.baseBuffer[16] = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnRenderParmArray[9].value.baseBuffer[12]);
  this->int_ = 5;
  this->bool_ = false;
  this->char_ = 1;
  this->unsignedchar = 2;
  this->short_ = 3;
  this->unsignedshort = 4;
  this->float_ = 9.5;
  this->unsignedint = 6;
  *(_QWORD *)&this->double_ = 0x4025000000000000LL;
  LODWORD(this->double_) = 2;
  *(float *)&this->boundedInt.value = 1.0;
  this->long_ = 7;
  this->unsignedlong = 8;
  this->boundedFloat = (idBoundedFloat<0,0,1,0>)vec2_origin;
  this->vec2.x = vec3_origin.x;
  this->vec2.y = vec3_origin.y;
  this->vec3.x = vec3_origin.z;
  *(idVec4 *)&this->vec3.y = vec4_origin;
  *(idMat3 *)&this->vec4.z = mat3_identity;
  *(idAngles *)&this->mat3.mat[2].y = ang_zero;
  this->angles.yaw = 0.0;
  HIBYTE(this->angles.roll) &= 3u;
  idStr::operator=(this: (idStr *)&this->enum_, text: "test string with \"double\" quotes");
  v3 = 10;
  p_weaponDef = &this->weaponDef;
  *(idColor *)&this->string.baseBuffer[12] = idColor::colorWhite;
  this->color.b = 0.0;
  this->color.a = 0.0;
  this->collisionModel = nullptr;
  this->renderModel = nullptr;
  this->table = nullptr;
  this->material = nullptr;
  this->soundShader = nullptr;
  this->testEntityDef = nullptr;
  this->fx = nullptr;
  this->particle = nullptr;
  this->af = nullptr;
  this->renderParm = nullptr;
  this->renderProg = nullptr;
  this->damageDef = nullptr;
  this->inventoryDef = nullptr;
  this->weaponDef = (const idDeclWeapon *)0x1FFF;
  do
  {
    *++p_weaponDef = nullptr;
    --v3;
  }
  while ( v3 != 0 );
  if ( (int)this->spawnRenderParmBlock.list >= 10
    || (unsigned __int8)idList<idSpawnRenderParm,5>::Resize(
                          this: (idList<idSpawnRenderParm,5> *)&this->soundList.size,
                          newsize: 10) != 0 )
  {
    list = (int)this->spawnRenderParmBlock.list;
    if ( list > 10 )
      list = 10;
    *(_DWORD *)&this->soundList.granularity = list;
  }
  if ( (int)this->structList.list >= 10
    || (unsigned __int8)idList<idTestEntity::test_t,5>::Resize(
                          this: (idList<eboltControlNode_t,5> *)&this->spawnRenderParmArray[9].value.baseBuffer[12],
                          newsize: 10) != 0 )
  {
    v6 = (int)this->structList.list;
    if ( v6 > 10 )
      v6 = 10;
    *(_DWORD *)&this->spawnRenderParmArray[9].value.baseBuffer[16] = v6;
  }
  v7 = 0;
  if ( *(int *)&this->spawnRenderParmArray[9].value.baseBuffer[16] > 0 )
  {
    v8 = 0;
    do
    {
      ++v7;
      v9 = (float *)(*(_DWORD *)v2 + v8);
      *v9 = 1.0;
      v9[1] = 2.0;
      v9[2] = 3.0;
      v10 = (float *)(*(_DWORD *)v2 + v8);
      v10[5] = 6.0;
      v10[3] = 4.0;
      v8 += 24;
      v10[4] = 5.0;
    }
    while ( v7 < *(_DWORD *)&this->spawnRenderParmArray[9].value.baseBuffer[16] );
  }
  this->structList.size = 0;
  *(float *)&this->structList.granularity = 0.0;
  *(idVec3 *)&this->test1 = vec3_origin;
  return this;
}


// ========================================================================
// __unwind$488779
// EA  : 0x82CE2930
// RVA : 0x00CE2930
// PDB : w:\tech5\tungsten\game\entities\testentity.cpp
// ========================================================================

void _unwind_488779()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 224 + 244));
}


// ========================================================================
// __unwind$488780
// EA  : 0x82CE2958
// RVA : 0x00CE2958
// PDB : w:\tech5\tungsten\game\entities\testentity.cpp
// ========================================================================

void _unwind_488780()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 224 + 244) + 948));
}


// ========================================================================
// __unwind$488781_1
// EA  : 0x82CE2984
// RVA : 0x00CE2984
// PDB : w:\tech5\tungsten\game\entities\testentity.cpp
// ========================================================================

void _unwind_488781_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 224 + 244) + 1100));
}


// ========================================================================
// __unwind$488782
// EA  : 0x82CE29B0
// RVA : 0x00CE29B0
// PDB : w:\tech5\tungsten\game\entities\testentity.cpp
// ========================================================================

void _unwind_488782()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 224 + 244) + 1116));
}


// ========================================================================
// __unwind$488783
// EA  : 0x82CE29DC
// RVA : 0x00CE29DC
// PDB : w:\tech5\tungsten\game\entities\testentity.cpp
// ========================================================================

void _unwind_488783()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 224 + 244) + 1132));
}


// ========================================================================
// __unwind$488784
// EA  : 0x82CE2A08
// RVA : 0x00CE2A08
// PDB : w:\tech5\tungsten\game\entities\testentity.cpp
// ========================================================================

void _unwind_488784()
{
  int v0; // r12

  idList<idSpawnRenderParm,5>::Clear(this: (idList<idRenderParm,5> *)(*(_DWORD *)(v0 - 224 + 244) + 1148));
}


// ========================================================================
// __unwind$488785_0
// EA  : 0x82CE2A34
// RVA : 0x00CE2A34
// PDB : w:\tech5\tungsten\game\entities\testentity.cpp
// ========================================================================

void _unwind_488785_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 224 + 244) + 1164),
    size: 0x24u,
    count: 10,
    pDtor: (void (__fastcall *)(void *))idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels);
}


// ========================================================================
// __unwind$488786
// EA  : 0x82CE2A70
// RVA : 0x00CE2A70
// PDB : w:\tech5\tungsten\game\entities\testentity.cpp
// ========================================================================

void _unwind_488786()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 224 + 244) + 1524));
}

