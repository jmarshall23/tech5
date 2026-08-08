
// ========================================================================
// ??0idTest_MetaData_Bounds@@QAA@XZ
// EA  : 0x824E3710
// RVA : 0x004E3710
// PDB : w:\tech5\tungsten\game\entities\testentities.h
// ========================================================================

idTest_MetaData_Bounds *__fastcall idTest_MetaData_Bounds::idTest_MetaData_Bounds(idTest_MetaData_Bounds *this)
{
  idLinkList<idEntity> *v2; // r9
  idSysMutex *p_viewNoteMutex; // r10
  int i; // ctr
  float *p_z; // r10
  idSysMutex *v6; // r11
  int j; // ctr

  idEntity::idEntity(this);
  this->__vftable = (idTest_MetaData_Bounds_vtbl *)&idTest_MetaData_Bounds::`vftable';
  v2 = &this->removeNode + 1;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  for ( i = 6; i != 0; --i )
  {
    ++p_viewNoteMutex;
    v2 = (idLinkList<idEntity> *)((char *)v2 + 4);
    v2->head = (idLinkList<idEntity> *)p_viewNoteMutex->handle;
  }
  p_z = &this->bounds1.b[1].z;
  v6 = &analysisClient.viewNoteMutex;
  for ( j = 6; j != 0; --j )
  {
    ++v6;
    *++p_z = *(float *)&v6->handle;
  }
  return this;
}


// ========================================================================
// ??0idTest_MetaData_MoveableSpheres@@QAA@XZ
// EA  : 0x824FC390
// RVA : 0x004FC390
// PDB : w:\tech5\tungsten\game\entities\testentities.h
// ========================================================================

idTest_MetaData_MoveableSpheres *__fastcall idTest_MetaData_MoveableSpheres::idTest_MetaData_MoveableSpheres(
        idTest_MetaData_MoveableSpheres *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTest_MetaData_MoveableSpheres_vtbl *)&idTest_MetaData_MoveableSpheres::`vftable';
  this->spheres.list = nullptr;
  this->spheres.granularity = 0;
  this->spheres.memTag = 5;
  this->spheres.listStatic = 0;
  this->spheres.size = 0;
  this->spheres.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spheres);
  return this;
}


// ========================================================================
// __unwind$586027
// EA  : 0x824FC404
// RVA : 0x004FC404
// PDB : w:\tech5\tungsten\game\entities\testentities.h
// ========================================================================

void _unwind_586027()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTest_MetaData_String@@QAA@XZ
// EA  : 0x82501338
// RVA : 0x00501338
// PDB : w:\tech5\tungsten\game\entities\testentities.h
// ========================================================================

idTest_MetaData_String *__fastcall idTest_MetaData_String::idTest_MetaData_String(idTest_MetaData_String *this)
{
  idEntity::idEntity(this);
  this->testEnum = VALUE_1;
  this->__vftable = (idTest_MetaData_String_vtbl *)&idTest_MetaData_String::`vftable';
  this->testString.allocedAndFlag = 20;
  this->testString.data = this->testString.baseBuffer;
  this->testString.len = 0;
  this->testString.baseBuffer[0] = 0;
  this->testFloat = 0.0;
  this->testEntityDef = nullptr;
  this->testBool = false;
  return this;
}


// ========================================================================
// ??0idTest_MetaData_Cylinder@@QAA@XZ
// EA  : 0x8251D0A8
// RVA : 0x0051D0A8
// PDB : w:\tech5\tungsten\game\entities\testentities.h
// ========================================================================

idTest_MetaData_Cylinder *__fastcall idTest_MetaData_Cylinder::idTest_MetaData_Cylinder(idTest_MetaData_Cylinder *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTest_MetaData_Cylinder_vtbl *)&idTest_MetaData_Cylinder::`vftable';
  this->radius = 128.0;
  this->top = 96.0;
  this->bottom = 0.0;
  return this;
}


// ========================================================================
// ??0idTest_MetaData_Line@@QAA@XZ
// EA  : 0x8253E6E0
// RVA : 0x0053E6E0
// PDB : w:\tech5\tungsten\game\entities\testentities.h
// ========================================================================

idTest_MetaData_Line *__fastcall idTest_MetaData_Line::idTest_MetaData_Line(idTest_MetaData_Line *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTest_MetaData_Line_vtbl *)&idTest_MetaData_Line::`vftable';
  this->lines.list = nullptr;
  this->lines.granularity = 0;
  this->lines.memTag = 5;
  this->lines.listStatic = 0;
  this->lines.size = 0;
  this->lines.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->lines);
  return this;
}


// ========================================================================
// __unwind$583811
// EA  : 0x8253E754
// RVA : 0x0053E754
// PDB : w:\tech5\tungsten\game\entities\testentities.h
// ========================================================================

void _unwind_583811()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTest_MetaData_Circle@@QAA@XZ
// EA  : 0x82556960
// RVA : 0x00556960
// PDB : w:\tech5\tungsten\game\entities\testentities.h
// ========================================================================

idTest_MetaData_Circle *__fastcall idTest_MetaData_Circle::idTest_MetaData_Circle(idTest_MetaData_Circle *this)
{
  idEntity::idEntity(this);
  this->range = 128.0;
  this->__vftable = (idTest_MetaData_Circle_vtbl *)&idTest_MetaData_Circle::`vftable';
  this->fovYaw.value = 45.0;
  this->foo.skipMe = 0;
  this->foo.bar = 0.0;
  return this;
}


// ========================================================================
// ??0idTest_MetaData_Fov@@QAA@XZ
// EA  : 0x825569C8
// RVA : 0x005569C8
// PDB : w:\tech5\tungsten\game\entities\testentities.h
// ========================================================================

idTest_MetaData_Fov *__fastcall idTest_MetaData_Fov::idTest_MetaData_Fov(idTest_MetaData_Fov *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTest_MetaData_Fov_vtbl *)&idTest_MetaData_Fov::`vftable';
  this->fov.radius = 128.0;
  this->fov.pitchFoV.value = 45.0;
  this->fov.yawFoV.value = 90.0;
  return this;
}

