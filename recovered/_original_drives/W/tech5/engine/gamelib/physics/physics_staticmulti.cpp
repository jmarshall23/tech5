
// ========================================================================
// ?GetPushedLinearVelocity@idPhysics_Robot@@UBA?AVidVec3@@H@Z
// EA  : 0x82763340
// RVA : 0x00763340
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

idAnimBaseFSM *__fastcall idPhysics_Robot::GetPushedLinearVelocity(idAnimBaseFSM *this, idVec3 *result)
{
  float y; // r8
  float z; // r7

  y = vec3_origin.y;
  z = vec3_origin.z;
  this->idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimBaseFSM_vtbl *)LODWORD(vec3_origin.x);
  *(float *)&this->listenerList = y;
  *(float *)&this->listeningToList = z;
  return this;
}


// ========================================================================
// ?ClipTranslation@idPhysics_StaticMulti@@UBAXAAUtrace_t@@ABVidVec3@@PBVidClipModel@@@Z
// EA  : 0x82763368
// RVA : 0x00763368
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::ClipTranslation(
        idPhysics_StaticMulti *this,
        trace_t *results,
        const idVec3 *translation,
        const idClipModel *model)
{
  memset(Dst: results, Val: 0, Size: sizeof(trace_t));
  idLib::Warning(fmt: "idPhysics_StaticMulti::ClipTranslation called");
}


// ========================================================================
// ?ClipRotation@idPhysics_StaticMulti@@UBAXAAUtrace_t@@ABVidRotation@@PBVidClipModel@@@Z
// EA  : 0x827633A0
// RVA : 0x007633A0
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::ClipRotation(
        idPhysics_StaticMulti *this,
        trace_t *results,
        const idRotation *rotation,
        const idClipModel *model)
{
  memset(Dst: results, Val: 0, Size: sizeof(trace_t));
  idLib::Warning(fmt: "idPhysics_StaticMulti::ClipRotation called");
}


// ========================================================================
// ?GetBlockingEntityNum@idPhysics_Static@@UBAHXZ
// EA  : 0x827633D8
// RVA : 0x007633D8
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

int __fastcall idPhysics_Static::GetBlockingEntityNum(idPhysics_DynamicBase *this)
{
  return 0x1FFF;
}


// ========================================================================
// ?GetClipModel@idPhysics_StaticMulti@@UBAPAVidClipModel@@H@Z
// EA  : 0x827633E0
// RVA : 0x007633E0
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

idClipModel *__fastcall idPhysics_StaticMulti::GetClipModel(idPhysics_StaticMulti *this, int id)
{
  idClipModel **list; // r11

  if ( id >= 0 && id < this->clipModels.num && (list = this->clipModels.list)[id] != nullptr )
    return list[id];
  else
    return this->clip->defaultClipModel;
}


// ========================================================================
// ?Name@function_t@@QBAPBDXZ
// EA  : 0x82763420
// RVA : 0x00763420
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

idDeclSource *__fastcall function_t::Name(idDecl *this)
{
  return this->declSource;
}


// ========================================================================
// ?GetMass@idPhysics_StaticMulti@@UBAMH@Z
// EA  : 0x82763428
// RVA : 0x00763428
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

float __fastcall idPhysics_StaticMulti::GetMass(idPhysics_StaticMulti *this, int id)
{
  double v2; // fp1
  int num; // r6
  int v4; // r10
  double v5; // fp0
  double v6; // fp13
  double v7; // fp12
  float *list; // r9
  int v9; // r11

  if ( id <= -1 )
  {
    num = this->clipModels.num;
    v4 = 0;
    v5 = 0.0;
    v6 = 0.0;
    v7 = 0.0;
    if ( num >= 2 )
    {
      list = this->mass.list;
      v9 = 0;
      do
      {
        v4 += 2;
        v5 = (float)(list[v9] + (float)v5);
        v6 = (float)(list[v9 + 1] + (float)v6);
        v9 += 2;
      }
      while ( v4 < num - 1 );
    }
    if ( v4 < num )
      v7 = this->mass.list[v4];
    v2 = (float)((float)((float)v6 + (float)v5) + (float)v7);
  }
  else
  {
    v2 = this->mass.list[id];
  }
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?SetContents@idPhysics_StaticMulti@@UAAXHH@Z
// EA  : 0x827634B0
// RVA : 0x007634B0
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::SetContents(idPhysics_StaticMulti *this, int contents, int id)
{
  idClipModel **v5; // r11
  int v6; // r29
  int v7; // r31
  idClipModel **list; // r11

  if ( id < 0 || id >= this->clipModels.num )
  {
    if ( id == -1 )
    {
      v6 = 0;
      if ( this->clipModels.num > 0 )
      {
        v7 = 0;
        do
        {
          list = this->clipModels.list;
          if ( list[v7] != nullptr )
            idClipModel::SetContents(this: list[v7], newContents: contents);
          ++v6;
          ++v7;
        }
        while ( v6 < this->clipModels.num );
      }
    }
  }
  else
  {
    v5 = this->clipModels.list;
    if ( v5[id] != nullptr )
      idClipModel::SetContents(this: v5[id], newContents: contents);
  }
}


// ========================================================================
// ?GetContents@idPhysics_StaticMulti@@UBAHH@Z
// EA  : 0x82763550
// RVA : 0x00763550
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

int __fastcall idPhysics_StaticMulti::GetContents(idPhysics_StaticMulti *this, int id)
{
  int result; // r3
  idClipModel *v4; // r9
  int num; // r9
  idClipModel **list; // r10
  int v7; // r11
  int i; // ctr
  idClipModel *v9; // r9

  result = 0;
  if ( id < 0 || id >= this->clipModels.num )
  {
    if ( id == -1 )
    {
      num = this->clipModels.num;
      if ( num > 0 )
      {
        list = this->clipModels.list;
        v7 = 0;
        for ( i = num; i != 0; --i )
        {
          v9 = list[v7];
          if ( v9 != nullptr )
            result |= v9->contents;
          ++v7;
        }
      }
    }
  }
  else
  {
    v4 = this->clipModels.list[id];
    if ( v4 != nullptr )
      return v4->contents;
  }
  return result;
}


// ========================================================================
// ?GetBounds@idPhysics_StaticMulti@@UBAABVidBounds@@H@Z
// EA  : 0x827635D0
// RVA : 0x007635D0
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_StaticMulti::GetBounds(
        idPhysics_StaticMulti *this,
        int id,
        int a3,
        int a4,
        int a5)
{
  idClipModel *v5; // r9
  int v7; // r9
  int v14; // r10
  float *v15; // r8
  float *v22; // r3
  float v23; // r8
  float v24; // [sp+50h] [-20h]
  float v25; // [sp+58h] [-18h]

  if ( (_S13_15 & 1) == 0 )
    _S13_15 |= 1u;
  if ( id >= 0 && id < this->clipModels.num )
  {
    v5 = this->clipModels.list[id];
    if ( v5 != nullptr )
      return &v5->bounds;
  }
  if ( id != -1 )
    return &bounds_zero;
  v7 = 0;
  _FP0 = 1.0e30;
  _FP11 = -1.0e30;
  bounds.b[0].x = 1.0e30;
  _FP12 = 1.0e30;
  bounds.b[0].z = 1.0e30;
  _FP13 = 1.0e30;
  bounds.b[0].y = 1.0e30;
  bounds.b[1].z = -1.0e30;
  bounds.b[1].y = -1.0e30;
  bounds.b[1].x = -1.0e30;
  _FP9 = -1.0e30;
  _FP10 = -1.0e30;
  if ( this->clipModels.num > 0 )
  {
    v14 = 0;
    do
    {
      v15 = (float *)this->clipModels.list[v14];
      if ( v15 != nullptr )
      {
        _FP7 = (float)((float)_FP0 - v15[26]);
        __asm { fsel      f0, f7, f8, f0 }
        bounds.b[0].x = _FP0;
        _FP5 = (float)((float)_FP13 - v15[27]);
        __asm { fsel      f13, f5, f6, f13 }
        bounds.b[0].y = _FP13;
        _FP3 = (float)((float)_FP12 - v15[28]);
        __asm { fsel      f12, f3, f4, f12 }
        bounds.b[0].z = _FP12;
        _FP1 = (float)(v15[29] - (float)_FP11);
        __asm { fsel      f11, f1, f2, f11 }
        bounds.b[1].x = _FP11;
        _FP7 = (float)(v15[30] - (float)_FP10);
        __asm { fsel      f10, f7, f8, f10 }
        bounds.b[1].y = _FP10;
        _FP5 = (float)(v15[31] - (float)_FP9);
        __asm { fsel      f9, f5, f6, f9 }
        bounds.b[1].z = _FP9;
      }
      ++v7;
      ++v14;
    }
    while ( v7 < this->clipModels.num );
  }
  v22 = (float *)((int (__fastcall *)(idPhysics_StaticMulti *, _DWORD, int, int, int))this->GetOrigin)(
                   a1: this,
                   a2: 0,
                   a3,
                   a4,
                   a5);
  v23 = v22[1];
  v25 = v22[2];
  v24 = *v22;
  bounds.b[0].x = bounds.b[0].x - *v22;
  bounds.b[0].y = bounds.b[0].y - v23;
  bounds.b[0].z = bounds.b[0].z - v25;
  bounds.b[1].x = bounds.b[1].x - v24;
  bounds.b[1].y = bounds.b[1].y - v23;
  bounds.b[1].z = bounds.b[1].z - v25;
  return &bounds;
}


// ========================================================================
// ?GetAbsBounds@idPhysics_StaticMulti@@UBAABVidBounds@@H@Z
// EA  : 0x827637D8
// RVA : 0x007637D8
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_StaticMulti::GetAbsBounds(idPhysics_StaticMulti *this, int id)
{
  idClipModel *v2; // r9
  idBounds *p_absBounds; // r11
  int v5; // r8
  int v6; // r9
  float *v7; // r7
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v11; // fp10
  double v13; // fp7

  if ( id >= 0 && id < this->clipModels.num )
  {
    v2 = this->clipModels.list[id];
    if ( v2 != nullptr )
      return &v2->absBounds;
  }
  if ( id != -1 )
    return &bounds_zero;
  p_absBounds = &this->absBounds;
  v5 = 0;
  this->absBounds.b[0].z = 1.0e30;
  this->absBounds.b[0].y = 1.0e30;
  this->absBounds.b[0].x = 1.0e30;
  this->absBounds.b[1].z = -1.0e30;
  this->absBounds.b[1].y = -1.0e30;
  this->absBounds.b[1].x = -1.0e30;
  if ( this->clipModels.num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = (float *)this->clipModels.list[v6];
      if ( v7 != nullptr )
      {
        y = this->absBounds.b[0].y;
        z = this->absBounds.b[0].z;
        x = this->absBounds.b[1].x;
        v11 = this->absBounds.b[1].y;
        _FP8 = (float)(p_absBounds->b[0].x - v7[26]);
        v13 = this->absBounds.b[1].z;
        __asm { fsel      f6, f8, f9, f0 }
        p_absBounds->b[0].x = _FP6;
        _FP4 = (float)((float)y - v7[27]);
        __asm { fsel      f3, f4, f5, f13 }
        this->absBounds.b[0].y = _FP3;
        _FP1 = (float)((float)z - v7[28]);
        __asm { fsel      f0, f1, f2, f12 }
        this->absBounds.b[0].z = _FP0;
        _FP12 = (float)(v7[29] - (float)x);
        __asm { fsel      f11, f12, f13, f11 }
        this->absBounds.b[1].x = _FP11;
        _FP8 = (float)(v7[30] - (float)v11);
        __asm { fsel      f6, f8, f9, f10 }
        this->absBounds.b[1].y = _FP6;
        _FP4 = (float)(v7[31] - (float)v13);
        __asm { fsel      f3, f4, f5, f7 }
        this->absBounds.b[1].z = _FP3;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->clipModels.num );
  }
  return &this->absBounds;
}


// ========================================================================
// ?Evaluate@idPhysics_StaticMulti@@UAA_NHH@Z
// EA  : 0x82763910
// RVA : 0x00763910
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

int __fastcall idPhysics_StaticMulti::Evaluate(idPhysics_StaticMulti *this, int timeStepMSec, int endTimeMSec)
{
  int v4; // r27
  int v5; // r28
  int v6; // r29
  staticPState_t *v7; // r11
  double v8; // fp13
  double v9; // fp31
  double v10; // fp5
  double v11; // fp8
  staticPState_t *list; // r11
  float *p_x; // r11
  idClipModel **v14; // r10
  float v16[4]; // [sp+50h] [-A0h] BYREF
  idMat3 v17; // [sp+60h] [-90h] BYREF
  idMat3 v18; // [sp+90h] [-60h] BYREF

  if ( !this->hasMaster )
    return 0;
  this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v16, a3: &v17);
  v4 = 0;
  if ( this->clipModels.num > 0 )
  {
    v5 = 0;
    v6 = 0;
    do
    {
      v7 = &this->current.list[v6];
      v8 = v16[0];
      v9 = v16[2];
      v10 = (float)((float)(v7->localOrigin.y * v17.mat[1].z)
                  + (float)((float)(v7->localOrigin.x * v17.mat[0].z) + (float)(v7->localOrigin.z * v17.mat[2].z)));
      v11 = (float)((float)(v7->localOrigin.x * v17.mat[0].x)
                  + (float)((float)(v7->localOrigin.z * v17.mat[2].x) + (float)(v7->localOrigin.y * v17.mat[1].x)));
      v7->worldOrigin.y = v16[1]
                        + (float)((float)(v7->localOrigin.y * v17.mat[1].y)
                                + (float)((float)(v7->localOrigin.x * v17.mat[0].y)
                                        + (float)(v7->localOrigin.z * v17.mat[2].y)));
      v7->worldOrigin.z = (float)v9 + (float)v10;
      v7->worldOrigin.x = (float)v11 + (float)v8;
      list = this->current.list;
      if ( this->isOrientated )
      {
        list[v6].worldAxis = *idMat3::operator*(this: &v18, result: &list[v6].localAxis, a: &v17);
      }
      else
      {
        p_x = &list[v6].worldOrigin.x;
        p_x[3] = p_x[15];
        p_x[4] = p_x[16];
        p_x[5] = p_x[17];
        p_x[6] = p_x[18];
        p_x[7] = p_x[19];
        p_x[8] = p_x[20];
        p_x[9] = p_x[21];
        p_x[10] = p_x[22];
        p_x[11] = p_x[23];
      }
      v14 = this->clipModels.list;
      if ( v14[v5] != nullptr )
        idClipModel::Link(
          this: v14[v5],
          newEntityNumber: this->entityNumber,
          newPhysicsId: this->physicsId,
          newBodyId: v4,
          newOrigin: &this->current.list[v6].worldOrigin,
          newAxis: &this->current.list[v6].worldAxis);
      ++v4;
      ++v6;
      ++v5;
    }
    while ( v4 < this->clipModels.num );
  }
  return 1;
}


// ========================================================================
// ?SetOrigin@idPhysics_StaticMulti@@UAAXABVidVec3@@H@Z
// EA  : 0x82763B18
// RVA : 0x00763B18
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::SetOrigin(idPhysics_StaticMulti *this, const idVec3 *newOrigin, int id)
{
  int v6; // r29
  staticPState_t *v7; // r11
  double v8; // fp2
  double v9; // fp9
  double v10; // fp6
  double v11; // fp4
  double v12; // fp3
  idClipModel **v13; // r10
  staticPState_t *list; // r11
  idPhysics_StaticMulti_vtbl *v15; // r10
  double v16; // fp9
  double v17; // fp7
  void (__fastcall *Translate)(struct idPhysics_StaticMulti *, const idVec3 *, int); // ctr
  float v19; // [sp+50h] [-70h] BYREF
  float v20; // [sp+54h] [-6Ch]
  float v21; // [sp+58h] [-68h]
  float v22[4]; // [sp+60h] [-60h] BYREF
  float v23[20]; // [sp+70h] [-50h] BYREF

  if ( id < 0 || id >= this->clipModels.num )
  {
    if ( id == -1 )
    {
      list = this->current.list;
      v15 = this->__vftable;
      v16 = (float)(newOrigin->z - list->worldOrigin.z);
      v17 = (float)(newOrigin->y - list->worldOrigin.y);
      v22[0] = newOrigin->x - list->worldOrigin.x;
      v22[2] = v16;
      Translate = v15->Translate;
      v22[1] = v17;
      Translate(this, a2: (const idVec3 *)v22, a3: -1);
    }
  }
  else
  {
    v6 = id;
    this->current.list[id].worldOrigin = *newOrigin;
    if ( this->hasMaster )
    {
      this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v19, a3: (idMat3 *)v23);
      v7 = &this->current.list[v6];
      v8 = (float)(newOrigin->x - v19);
      v9 = v23[3];
      v10 = v23[6];
      v11 = (float)((float)(v23[4] * (float)(newOrigin->y - v20)) + (float)(v23[5] * (float)(newOrigin->z - v21)));
      v12 = (float)((float)(v23[7] * (float)(newOrigin->y - v20)) + (float)(v23[8] * (float)(newOrigin->z - v21)));
      v7->localOrigin.x = (float)(v23[0] * (float)(newOrigin->x - v19))
                        + (float)((float)(v23[1] * (float)(newOrigin->y - v20))
                                + (float)(v23[2] * (float)(newOrigin->z - v21)));
      v7->localOrigin.y = (float)((float)v9 * (float)v8) + (float)v11;
      v7->localOrigin.z = (float)((float)v10 * (float)v8) + (float)v12;
    }
    else
    {
      this->current.list[v6].localOrigin = *newOrigin;
    }
    v13 = this->clipModels.list;
    if ( v13[id] != nullptr )
      idClipModel::Link(
        this: v13[id],
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: id,
        newOrigin: &this->current.list[v6].worldOrigin,
        newAxis: &this->current.list[v6].worldAxis);
  }
}


// ========================================================================
// ?SetAxis@idPhysics_StaticMulti@@UAAXABVidMat3@@H@Z
// EA  : 0x82763CE0
// RVA : 0x00763CE0
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::SetAxis(idPhysics_StaticMulti *this, idMat3 *newAxis, int id)
{
  int v6; // r29
  idMat3 *v7; // r4
  staticPState_t *v8; // r30
  idClipModel **v9; // r10
  float *p_x; // r11
  double v11; // fp13
  double v12; // fp12
  double v13; // fp11
  double v14; // fp10
  double v15; // fp9
  double v16; // fp8
  double v17; // fp7
  double v18; // fp6
  idRotation *v19; // r3
  staticPState_t *list; // r11
  idPhysics_StaticMulti_vtbl *v21; // r10
  void (__fastcall *Rotate)(struct idPhysics_StaticMulti *, const idRotation *, int); // r9
  idMat3 v23; // [sp+50h] [-110h] BYREF
  float v24[10]; // [sp+80h] [-E0h] BYREF
  _BYTE v25[24]; // [sp+A8h] [-B8h] BYREF
  idMat3 v26[2]; // [sp+C0h] [-A0h] BYREF
  idMat3 v27[2]; // [sp+110h] [-50h] BYREF

  if ( id < 0 || id >= this->clipModels.num )
  {
    if ( id == -1 )
    {
      p_x = &this->current.list->worldOrigin.x;
      v11 = p_x[8];
      v12 = p_x[5];
      v13 = p_x[10];
      v14 = p_x[7];
      v15 = p_x[4];
      v16 = p_x[9];
      v17 = p_x[6];
      v18 = p_x[3];
      v23.mat[2].z = p_x[11];
      v23.mat[2].y = v11;
      v23.mat[2].x = v12;
      v23.mat[1].z = v13;
      v23.mat[1].y = v14;
      v23.mat[1].x = v15;
      v23.mat[0].z = v16;
      v23.mat[0].y = v17;
      v23.mat[0].x = v18;
      v19 = (idRotation *)idMat3::operator*(this: v27, result: &v23, a: newAxis);
      idMat3::ToRotation(this: v26, result: v19);
      list = this->current.list;
      v21 = this->__vftable;
      v26[0].mat[0].x = list->worldOrigin.x;
      Rotate = v21->Rotate;
      v26[0].mat[0].y = list->worldOrigin.y;
      v26[0].mat[0].z = list->worldOrigin.z;
      Rotate(this, a2: (const idRotation *)v26, a3: -1);
    }
  }
  else
  {
    v6 = id;
    this->current.list[id].worldAxis = *newAxis;
    if ( this->hasMaster && this->isOrientated )
    {
      this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v25, a3: (idMat3 *)v24);
      v7 = newAxis;
      v8 = &this->current.list[v6];
      v23.mat[0].x = v24[0];
      v23.mat[0].y = v24[3];
      v23.mat[0].z = v24[6];
      v23.mat[1].x = v24[1];
      v23.mat[1].y = v24[4];
      v23.mat[1].z = v24[7];
      v23.mat[2].x = v24[2];
      v23.mat[2].y = v24[5];
      v23.mat[2].z = v24[8];
      v8->localAxis = *idMat3::operator*(this: v27, result: v7, a: &v23);
    }
    else
    {
      this->current.list[v6].localAxis = *newAxis;
    }
    v9 = this->clipModels.list;
    if ( v9[id] != nullptr )
      idClipModel::Link(
        this: v9[id],
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: id,
        newOrigin: &this->current.list[v6].worldOrigin,
        newAxis: &this->current.list[v6].worldAxis);
  }
}


// ========================================================================
// ?Translate@idPhysics_StaticMulti@@UAAXABVidVec3@@H@Z
// EA  : 0x82763F98
// RVA : 0x00763F98
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::Translate(idPhysics_StaticMulti *this, const idVec3 *translation, int id)
{
  staticPState_t *v5; // r11
  staticPState_t *v6; // r11
  double v7; // fp4
  double v8; // fp3
  idClipModel **v9; // r11
  int v10; // r27
  int v11; // r28
  int v12; // r29
  staticPState_t *v13; // r11
  staticPState_t *v14; // r11
  double y; // fp1
  double z; // fp4
  idClipModel **list; // r11

  if ( id < 0 || id >= this->clipModels.num )
  {
    if ( id == -1 )
    {
      v10 = 0;
      if ( this->clipModels.num > 0 )
      {
        v11 = 0;
        v12 = 0;
        do
        {
          v13 = &this->current.list[v12];
          v13->localOrigin.x = v13->localOrigin.x + translation->x;
          v13->localOrigin.y = v13->localOrigin.y + translation->y;
          v13->localOrigin.z = v13->localOrigin.z + translation->z;
          v14 = &this->current.list[v12];
          y = v14->worldOrigin.y;
          z = v14->worldOrigin.z;
          v14->worldOrigin.x = v14->worldOrigin.x + translation->x;
          v14->worldOrigin.y = (float)y + translation->y;
          v14->worldOrigin.z = (float)z + translation->z;
          list = this->clipModels.list;
          if ( list[v11] != nullptr )
            idClipModel::Link(
              this: list[v11],
              newEntityNumber: this->entityNumber,
              newPhysicsId: this->physicsId,
              newBodyId: v10,
              newOrigin: &this->current.list[v12].worldOrigin,
              newAxis: &this->current.list[v12].worldAxis);
          ++v10;
          ++v12;
          ++v11;
        }
        while ( v10 < this->clipModels.num );
      }
    }
  }
  else
  {
    v5 = &this->current.list[id];
    v5->localOrigin.x = v5->localOrigin.x + translation->x;
    v5->localOrigin.y = translation->y + v5->localOrigin.y;
    v5->localOrigin.z = v5->localOrigin.z + translation->z;
    v6 = &this->current.list[id];
    v7 = v6->worldOrigin.y;
    v8 = v6->worldOrigin.z;
    v6->worldOrigin.x = translation->x + v6->worldOrigin.x;
    v6->worldOrigin.y = (float)v7 + translation->y;
    v6->worldOrigin.z = (float)v8 + translation->z;
    v9 = this->clipModels.list;
    if ( v9[id] != nullptr )
      idClipModel::Link(
        this: v9[id],
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: id,
        newOrigin: &this->current.list[id].worldOrigin,
        newAxis: &this->current.list[id].worldAxis);
  }
}


// ========================================================================
// ?Rotate@idPhysics_StaticMulti@@UAAXABVidRotation@@H@Z
// EA  : 0x82764160
// RVA : 0x00764160
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::Rotate(idPhysics_StaticMulti *this, idRotation *rotation, int id)
{
  int v6; // r30
  staticPState_t *v7; // r29
  staticPState_t *v8; // r29
  const idMat3 *v9; // r3
  staticPState_t *v10; // r29
  const idMat3 *v11; // r3
  staticPState_t *v12; // r11
  double v13; // fp1
  double v14; // fp9
  double v15; // fp7
  double v16; // fp4
  double v17; // fp3
  float *v18; // r11
  staticPState_t *v19; // r11
  idClipModel **v20; // r10
  int v21; // r26
  int v22; // r28
  int v23; // r30
  staticPState_t *v24; // r29
  staticPState_t *v25; // r29
  const idMat3 *v26; // r3
  staticPState_t *v27; // r29
  const idMat3 *v28; // r3
  staticPState_t *v29; // r11
  double v30; // fp1
  double z; // fp9
  double v32; // fp7
  double v33; // fp4
  double v34; // fp3
  float *p_x; // r11
  staticPState_t *v36; // r11
  idClipModel **list; // r10
  float v38; // [sp+50h] [-80h] BYREF
  float v39; // [sp+54h] [-7Ch]
  float v40; // [sp+58h] [-78h]
  idRotation v41; // [sp+60h] [-70h] BYREF

  if ( id < 0 || id >= this->clipModels.num )
  {
    if ( id == -1 )
    {
      v21 = 0;
      if ( this->clipModels.num > 0 )
      {
        v22 = 0;
        v23 = 0;
        do
        {
          v24 = &this->current.list[v23];
          v24->worldOrigin = idRotation::operator*(this: &v41, result: rotation, v: &v24->worldOrigin)->origin;
          v25 = &this->current.list[v23];
          v26 = idRotation::ToMat3(this: rotation);
          idMat3::operator*=(this: &v25->worldAxis, a: v26);
          if ( this->hasMaster )
          {
            this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v38, a3: (idMat3 *)&v41.vec.y);
            v27 = &this->current.list[v23];
            v28 = idRotation::ToMat3(this: rotation);
            idMat3::operator*=(this: &v27->localAxis, a: v28);
            v29 = &this->current.list[v23];
            v30 = (float)(v29->worldOrigin.z - v40);
            z = v41.axis.mat[0].z;
            v32 = v41.axis.mat[1].z;
            v33 = (float)((float)(v41.axis.mat[0].x * (float)(v29->worldOrigin.x - v38))
                        + (float)(v41.axis.mat[0].y * (float)(v29->worldOrigin.y - v39)));
            v34 = (float)((float)(v41.axis.mat[1].x * (float)(v29->worldOrigin.x - v38))
                        + (float)(v41.axis.mat[1].y * (float)(v29->worldOrigin.y - v39)));
            v29->localOrigin.x = (float)(v41.angle * (float)(v29->worldOrigin.z - v40))
                               + (float)((float)(v41.vec.y * (float)(v29->worldOrigin.x - v38))
                                       + (float)(v41.vec.z * (float)(v29->worldOrigin.y - v39)));
            v29->localOrigin.y = (float)((float)z * (float)v30) + (float)v33;
            v29->localOrigin.z = (float)((float)v32 * (float)v30) + (float)v34;
          }
          else
          {
            p_x = &this->current.list[v23].worldOrigin.x;
            p_x[15] = p_x[3];
            p_x[16] = p_x[4];
            p_x[17] = p_x[5];
            p_x[18] = p_x[6];
            p_x[19] = p_x[7];
            p_x[20] = p_x[8];
            p_x[21] = p_x[9];
            p_x[22] = p_x[10];
            p_x[23] = p_x[11];
            v36 = &this->current.list[v23];
            v36->localOrigin.x = v36->worldOrigin.x;
            v36->localOrigin.y = v36->worldOrigin.y;
            v36->localOrigin.z = v36->worldOrigin.z;
          }
          list = this->clipModels.list;
          if ( list[v22] != nullptr )
            idClipModel::Link(
              this: list[v22],
              newEntityNumber: this->entityNumber,
              newPhysicsId: this->physicsId,
              newBodyId: v21,
              newOrigin: &this->current.list[v23].worldOrigin,
              newAxis: &this->current.list[v23].worldAxis);
          ++v21;
          ++v23;
          ++v22;
        }
        while ( v21 < this->clipModels.num );
      }
    }
  }
  else
  {
    v6 = id;
    v7 = &this->current.list[id];
    v7->worldOrigin = idRotation::operator*(this: &v41, result: rotation, v: &v7->worldOrigin)->origin;
    v8 = &this->current.list[v6];
    v9 = idRotation::ToMat3(this: rotation);
    idMat3::operator*=(this: &v8->worldAxis, a: v9);
    if ( this->hasMaster )
    {
      this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v38, a3: (idMat3 *)&v41.vec.y);
      v10 = &this->current.list[v6];
      v11 = idRotation::ToMat3(this: rotation);
      idMat3::operator*=(this: &v10->localAxis, a: v11);
      v12 = &this->current.list[v6];
      v13 = (float)(v12->worldOrigin.z - v40);
      v14 = v41.axis.mat[0].z;
      v15 = v41.axis.mat[1].z;
      v16 = (float)((float)(v41.axis.mat[0].x * (float)(v12->worldOrigin.x - v38))
                  + (float)(v41.axis.mat[0].y * (float)(v12->worldOrigin.y - v39)));
      v17 = (float)((float)(v41.axis.mat[1].x * (float)(v12->worldOrigin.x - v38))
                  + (float)(v41.axis.mat[1].y * (float)(v12->worldOrigin.y - v39)));
      v12->localOrigin.x = (float)(v41.angle * (float)(v12->worldOrigin.z - v40))
                         + (float)((float)(v41.vec.y * (float)(v12->worldOrigin.x - v38))
                                 + (float)(v41.vec.z * (float)(v12->worldOrigin.y - v39)));
      v12->localOrigin.y = (float)((float)v14 * (float)v13) + (float)v16;
      v12->localOrigin.z = (float)((float)v15 * (float)v13) + (float)v17;
    }
    else
    {
      v18 = &this->current.list[v6].worldOrigin.x;
      v18[15] = v18[3];
      v18[16] = v18[4];
      v18[17] = v18[5];
      v18[18] = v18[6];
      v18[19] = v18[7];
      v18[20] = v18[8];
      v18[21] = v18[9];
      v18[22] = v18[10];
      v18[23] = v18[11];
      v19 = &this->current.list[v6];
      v19->localOrigin.x = v19->worldOrigin.x;
      v19->localOrigin.y = v19->worldOrigin.y;
      v19->localOrigin.z = v19->worldOrigin.z;
    }
    v20 = this->clipModels.list;
    if ( v20[id] != nullptr )
      idClipModel::Link(
        this: v20[id],
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: id,
        newOrigin: &this->current.list[v6].worldOrigin,
        newAxis: &this->current.list[v6].worldAxis);
  }
}


// ========================================================================
// ?GetOrigin@idPhysics_StaticMulti@@UBAABVidVec3@@H@Z
// EA  : 0x82764560
// RVA : 0x00764560
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

staticPState_t *__fastcall idPhysics_StaticMulti::GetOrigin(idPhysics_StaticMulti *this, int id)
{
  if ( id >= 0 && id < this->clipModels.num )
    return &this->current.list[id];
  if ( this->clipModels.num != 0 )
    return this->current.list;
  return (staticPState_t *)&vec3_origin;
}


// ========================================================================
// ?GetAxis@idPhysics_StaticMulti@@UBAABVidMat3@@H@Z
// EA  : 0x827645B0
// RVA : 0x007645B0
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

const idMat3 *__fastcall idPhysics_StaticMulti::GetAxis(idPhysics_StaticMulti *this, int id)
{
  if ( id >= 0 && id < this->clipModels.num )
    return &this->current.list[id].worldAxis;
  if ( this->clipModels.num != 0 )
    return &this->current.list->worldAxis;
  return &mat3_identity;
}


// ========================================================================
// ?GetLocalOrigin@idPhysics_StaticMulti@@UBAABVidVec3@@H@Z
// EA  : 0x82764608
// RVA : 0x00764608
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

const idVec3 *__fastcall idPhysics_StaticMulti::GetLocalOrigin(idPhysics_StaticMulti *this, int id)
{
  if ( id >= 0 && id < this->clipModels.num )
    return &this->current.list[id].localOrigin;
  if ( this->clipModels.num != 0 )
    return &this->current.list->localOrigin;
  return &vec3_origin;
}


// ========================================================================
// ?GetLocalAxis@idPhysics_StaticMulti@@UBAABVidMat3@@H@Z
// EA  : 0x82764660
// RVA : 0x00764660
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

const idMat3 *__fastcall idPhysics_StaticMulti::GetLocalAxis(idPhysics_StaticMulti *this, int id)
{
  if ( id >= 0 && id < this->clipModels.num )
    return &this->current.list[id].localAxis;
  if ( this->clipModels.num != 0 )
    return &this->current.list->localAxis;
  return &mat3_identity;
}


// ========================================================================
// ?DisableClip@idPhysics_StaticMulti@@UAAXXZ
// EA  : 0x827646B8
// RVA : 0x007646B8
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::DisableClip(idPhysics_StaticMulti *this)
{
  int v1; // r9
  int v2; // r11
  idClipModel *v3; // r7

  v1 = 0;
  if ( this->clipModels.num > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this->clipModels.list[v2];
      if ( v3 != nullptr )
        v3->enabled = false;
      ++v1;
      ++v2;
    }
    while ( v1 < this->clipModels.num );
  }
}


// ========================================================================
// ?EnableClip@idPhysics_StaticMulti@@UAAXXZ
// EA  : 0x82764700
// RVA : 0x00764700
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::EnableClip(idPhysics_StaticMulti *this)
{
  int v1; // r9
  int v2; // r11
  idClipModel *v3; // r7

  v1 = 0;
  if ( this->clipModels.num > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this->clipModels.list[v2];
      if ( v3 != nullptr )
        v3->enabled = true;
      ++v1;
      ++v2;
    }
    while ( v1 < this->clipModels.num );
  }
}


// ========================================================================
// ?UnlinkClip@idPhysics_StaticMulti@@UAAXXZ
// EA  : 0x82764748
// RVA : 0x00764748
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::UnlinkClip(idPhysics_StaticMulti *this)
{
  int v2; // r29
  int v3; // r31
  idClipModel **list; // r11

  v2 = 0;
  if ( this->clipModels.num > 0 )
  {
    v3 = 0;
    do
    {
      list = this->clipModels.list;
      if ( list[v3] != nullptr )
        idClipModel::Unlink(this: list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->clipModels.num );
  }
}


// ========================================================================
// ?LinkClip@idPhysics_StaticMulti@@UAAXXZ
// EA  : 0x827647A0
// RVA : 0x007647A0
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::LinkClip(idPhysics_StaticMulti *this)
{
  int v2; // r29
  int v3; // r30
  int v4; // r28
  idClipModel **list; // r10

  v2 = 0;
  if ( this->clipModels.num > 0 )
  {
    v3 = 0;
    v4 = 0;
    do
    {
      list = this->clipModels.list;
      if ( list[v3] != nullptr )
        idClipModel::Link(
          this: list[v3],
          newEntityNumber: this->entityNumber,
          newPhysicsId: this->physicsId,
          newBodyId: v2,
          newOrigin: &this->current.list[v4].worldOrigin,
          newAxis: &this->current.list[v4].worldAxis);
      ++v2;
      ++v4;
      ++v3;
    }
    while ( v2 < this->clipModels.num );
  }
}


// ========================================================================
// ?GetContact@idPhysics_StaticMulti@@UBAABUcontactInfo_t@@H@Z
// EA  : 0x82764818
// RVA : 0x00764818
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

const contactInfo_t *__fastcall idPhysics_StaticMulti::GetContact(idPhysics_StaticMulti *this, int num)
{
  if ( (_S14_3 & 1) == 0 )
    _S14_3 |= 1u;
  memset(Dst: &info_0, Val: 0, Size: sizeof(info_0));
  return &info_0;
}


// ========================================================================
// ?SetMaster@idPhysics_StaticMulti@@UAAX_NABVidVec3@@ABVidMat3@@W4bindFlags_t@@@Z
// EA  : 0x82764878
// RVA : 0x00764878
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::SetMaster(
        idPhysics_StaticMulti *this,
        bool enable,
        const idVec3 *masterOrigin,
        const idMat3 *masterAxis,
        const bindFlags_t bflags)
{
  char v8; // r24
  int v9; // r25
  __int32 v10; // r26
  int v11; // r29
  staticPState_t *v12; // r11
  double v13; // fp1
  double x; // fp13
  double v15; // fp9
  double v16; // fp10
  double v17; // fp8
  staticPState_t *list; // r11
  double z; // fp0
  double v20; // fp12
  double y; // fp11
  double v22; // fp10
  double v23; // fp9
  double v24; // fp8
  double v25; // fp7
  double v26; // fp6
  float *p_x; // r11
  idMat3 v28; // [sp+50h] [-A0h] BYREF
  idMat3 v29[3]; // [sp+80h] [-70h] BYREF

  v8 = bflags;
  if ( enable )
  {
    if ( !this->hasMaster )
    {
      v9 = 0;
      if ( this->clipModels.num > 0 )
      {
        v10 = bflags & 1;
        v11 = 0;
        do
        {
          v12 = &this->current.list[v11];
          v13 = (float)(v12->worldOrigin.x - masterOrigin->x);
          x = masterAxis->mat[2].x;
          v15 = masterAxis->mat[1].x;
          v16 = (float)((float)((float)(v12->worldOrigin.y - masterOrigin->y) * masterAxis->mat[1].y)
                      + (float)((float)(v12->worldOrigin.z - masterOrigin->z) * masterAxis->mat[1].z));
          v17 = (float)((float)((float)(v12->worldOrigin.y - masterOrigin->y) * masterAxis->mat[2].y)
                      + (float)((float)(v12->worldOrigin.z - masterOrigin->z) * masterAxis->mat[2].z));
          v12->localOrigin.x = (float)((float)(v12->worldOrigin.x - masterOrigin->x) * masterAxis->mat[0].x)
                             + (float)((float)((float)(v12->worldOrigin.y - masterOrigin->y) * masterAxis->mat[0].y)
                                     + (float)((float)(v12->worldOrigin.z - masterOrigin->z) * masterAxis->mat[0].z));
          v12->localOrigin.y = (float)((float)v13 * (float)v15) + (float)v16;
          v12->localOrigin.z = (float)((float)v13 * (float)x) + (float)v17;
          list = this->current.list;
          if ( v10 != 0 )
          {
            z = masterAxis->mat[2].z;
            v20 = masterAxis->mat[0].z;
            y = masterAxis->mat[2].y;
            v22 = masterAxis->mat[1].y;
            v23 = masterAxis->mat[0].y;
            v24 = masterAxis->mat[2].x;
            v25 = masterAxis->mat[1].x;
            v26 = masterAxis->mat[0].x;
            v28.mat[2].y = masterAxis->mat[1].z;
            v28.mat[2].x = v20;
            v28.mat[1].z = y;
            v28.mat[1].y = v22;
            v28.mat[1].x = v23;
            v28.mat[0].z = v24;
            v28.mat[0].x = v26;
            v28.mat[0].y = v25;
            v28.mat[2].z = z;
            list[v11].localAxis = *idMat3::operator*(this: v29, result: &list[v11].worldAxis, a: &v28);
          }
          else
          {
            p_x = &list[v11].worldOrigin.x;
            p_x[15] = p_x[3];
            p_x[16] = p_x[4];
            p_x[17] = p_x[5];
            p_x[18] = p_x[6];
            p_x[19] = p_x[7];
            p_x[20] = p_x[8];
            p_x[21] = p_x[9];
            p_x[22] = p_x[10];
            p_x[23] = p_x[11];
          }
          ++v9;
          ++v11;
        }
        while ( v9 < this->clipModels.num );
      }
      this->hasMaster = true;
      this->isOrientated = v8 & 1;
    }
  }
  else if ( this->hasMaster )
  {
    this->hasMaster = false;
  }
}


// ========================================================================
// ?SetLocalOrigin@idPhysics_StaticMulti@@UAAXABVidVec3@@H@Z
// EA  : 0x82764A98
// RVA : 0x00764A98
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::SetLocalOrigin(idPhysics_StaticMulti *this, const idVec3 *newOrigin, int id)
{
  int v6; // r29
  staticPState_t *v7; // r11
  double v8; // fp9
  double v9; // fp6
  double v10; // fp2
  double v11; // fp1
  double z; // fp12
  idClipModel **v13; // r10
  staticPState_t *list; // r9
  void (__fastcall *Translate)(struct idPhysics_StaticMulti *, const idVec3 *, int); // ctr
  double x; // fp5
  double v17; // fp12
  double v18; // fp10
  staticPState_t *v19; // r11
  idPhysics_StaticMulti_vtbl *v20; // r10
  double v21; // fp9
  double v22; // fp7
  void (__fastcall *v23)(struct idPhysics_StaticMulti *, const idVec3 *, int); // ctr
  float v24[4]; // [sp+50h] [-C0h] BYREF
  float v25[4]; // [sp+60h] [-B0h] BYREF
  float v26[4]; // [sp+70h] [-A0h] BYREF
  float v27[4]; // [sp+80h] [-90h] BYREF
  float v28[12]; // [sp+90h] [-80h] BYREF
  float v29[20]; // [sp+C0h] [-50h] BYREF

  if ( id < 0 || id >= this->clipModels.num )
  {
    if ( id == -1 )
    {
      if ( this->hasMaster )
      {
        this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v25, a3: (idMat3 *)v29);
        list = this->current.list;
        Translate = this->Translate;
        x = list->worldOrigin.x;
        v17 = (float)((float)((float)(newOrigin->x * v29[0])
                            + (float)((float)(newOrigin->z * v29[6]) + (float)(newOrigin->y * v29[3])))
                    + v25[0]);
        v18 = (float)((float)(v25[2]
                            + (float)((float)(newOrigin->x * v29[2])
                                    + (float)((float)(newOrigin->z * v29[8]) + (float)(newOrigin->y * v29[5]))))
                    - list->worldOrigin.z);
        v26[1] = (float)(v25[1]
                       + (float)((float)(newOrigin->x * v29[1])
                               + (float)((float)(newOrigin->z * v29[7]) + (float)(newOrigin->y * v29[4]))))
               - list->worldOrigin.y;
        v26[2] = v18;
        v26[0] = (float)v17 - (float)x;
        Translate(this, a2: (const idVec3 *)v26, a3: -1);
      }
      else
      {
        v19 = this->current.list;
        v20 = this->__vftable;
        v21 = (float)(newOrigin->z - v19->worldOrigin.z);
        v22 = (float)(newOrigin->y - v19->worldOrigin.y);
        v27[0] = newOrigin->x - v19->worldOrigin.x;
        v27[2] = v21;
        v23 = v20->Translate;
        v27[1] = v22;
        v23(this, a2: (const idVec3 *)v27, a3: -1);
      }
    }
  }
  else
  {
    v6 = id;
    this->current.list[id].localOrigin = *newOrigin;
    if ( this->hasMaster )
    {
      this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v24, a3: (idMat3 *)v28);
      v7 = &this->current.list[v6];
      v8 = v24[1];
      v9 = v24[2];
      v10 = (float)((float)(newOrigin->x * v28[1])
                  + (float)((float)(newOrigin->y * v28[4]) + (float)(newOrigin->z * v28[7])));
      v11 = (float)((float)(newOrigin->x * v28[2])
                  + (float)((float)(newOrigin->z * v28[8]) + (float)(newOrigin->y * v28[5])));
      v7->worldOrigin.x = (float)((float)(newOrigin->x * v28[0])
                                + (float)((float)(newOrigin->z * v28[6]) + (float)(newOrigin->y * v28[3])))
                        + v24[0];
      v7->worldOrigin.y = (float)v8 + (float)v10;
      z = (float)((float)v9 + (float)v11);
    }
    else
    {
      v7 = &this->current.list[v6];
      v7->worldOrigin.x = newOrigin->x;
      v7->worldOrigin.y = newOrigin->y;
      z = newOrigin->z;
    }
    v7->worldOrigin.z = z;
    v13 = this->clipModels.list;
    if ( v13[id] != nullptr )
      idClipModel::Link(
        this: v13[id],
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: id,
        newOrigin: &this->current.list[v6].worldOrigin,
        newAxis: &this->current.list[v6].worldAxis);
  }
}


// ========================================================================
// ?SetLocalAxis@idPhysics_StaticMulti@@UAAXABVidMat3@@H@Z
// EA  : 0x82764D38
// RVA : 0x00764D38
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::SetLocalAxis(idPhysics_StaticMulti *this, idMat3 *newAxis, int id)
{
  int v6; // r29
  idMat3 *v7; // r4
  staticPState_t *v8; // r31
  idClipModel **v9; // r10
  float *p_x; // r11
  double v11; // fp13
  double v12; // fp12
  double v13; // fp11
  double v14; // fp10
  double v15; // fp9
  double v16; // fp8
  double v17; // fp7
  double v18; // fp6
  const idMat3 *v19; // r5
  float *v20; // r11
  double v21; // fp13
  double v22; // fp12
  double v23; // fp11
  double v24; // fp10
  double v25; // fp9
  double v26; // fp8
  double v27; // fp7
  double v28; // fp6
  float *v29; // r3
  const idRotation *v30; // r3
  staticPState_t *list; // r11
  idPhysics_StaticMulti_vtbl *v32; // r10
  void (__fastcall *Rotate)(struct idPhysics_StaticMulti *, const idRotation *, int); // r9
  idMat3 v34; // [sp+50h] [-1A0h] BYREF
  idRotation v35; // [sp+80h] [-170h] BYREF
  _BYTE v36[16]; // [sp+D8h] [-118h] BYREF
  _BYTE v37[24]; // [sp+E8h] [-108h] BYREF
  idRotation v38; // [sp+100h] [-F0h] BYREF
  idMat3 v39[2]; // [sp+150h] [-A0h] BYREF
  idMat3 v40[2]; // [sp+1A0h] [-50h] BYREF

  if ( id < 0 || id >= this->clipModels.num )
  {
    if ( id == -1 )
    {
      if ( this->hasMaster )
      {
        this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v36, a3: (idMat3 *)&v35.axis.mat[1].z);
        p_x = &this->current.list->worldOrigin.x;
        v11 = p_x[8];
        v12 = p_x[5];
        v13 = p_x[10];
        v14 = p_x[7];
        v15 = p_x[4];
        v16 = p_x[9];
        v17 = p_x[6];
        v18 = p_x[3];
        v34.mat[2].z = p_x[11];
        v34.mat[2].y = v11;
        v34.mat[2].x = v12;
        v34.mat[1].z = v13;
        v34.mat[1].y = v14;
        v34.mat[1].x = v15;
        v34.mat[0].z = v16;
        v34.mat[0].y = v17;
        v34.mat[0].x = v18;
        v19 = idMat3::operator*(this: v40, result: newAxis, a: (const idMat3 *)&v35.axis.mat[1].z);
      }
      else
      {
        v20 = &this->current.list->worldOrigin.x;
        v19 = newAxis;
        v21 = v20[8];
        v22 = v20[5];
        v23 = v20[10];
        v24 = v20[7];
        v25 = v20[4];
        v26 = v20[9];
        v27 = v20[6];
        v28 = v20[3];
        v34.mat[2].z = v20[11];
        v34.mat[2].y = v21;
        v34.mat[2].x = v22;
        v34.mat[1].z = v23;
        v34.mat[1].y = v24;
        v34.mat[1].x = v25;
        v34.mat[0].z = v26;
        v34.mat[0].y = v27;
        v34.mat[0].x = v28;
      }
      v29 = (float *)idMat3::operator*(this: v39, result: &v34, a: v19);
      v35.origin.x = *v29;
      v35.origin.y = v29[1];
      v35.origin.z = v29[2];
      v35.vec.x = v29[3];
      v35.vec.y = v29[4];
      v35.vec.z = v29[5];
      v35.angle = v29[6];
      v35.axis.mat[0].x = v29[7];
      v35.axis.mat[0].y = v29[8];
      v30 = idMat3::ToRotation(this: v39, result: &v35);
      idRotation::operator=(this: &v38, __that: v30);
      list = this->current.list;
      v32 = this->__vftable;
      v38.origin.x = list->worldOrigin.x;
      Rotate = v32->Rotate;
      v38.origin.y = list->worldOrigin.y;
      v38.origin.z = list->worldOrigin.z;
      Rotate(this, a2: &v38, a3: -1);
    }
  }
  else
  {
    v6 = id;
    this->current.list[id].localAxis = *newAxis;
    if ( this->hasMaster && this->isOrientated )
    {
      this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v37, a3: &v34);
      v7 = newAxis;
      v8 = &this->current.list[v6];
      v8->worldAxis = *idMat3::operator*(this: (idMat3 *)&v35.axis.mat[1].z, result: v7, a: &v34);
    }
    else
    {
      this->current.list[v6].worldAxis = *newAxis;
    }
    v9 = this->clipModels.list;
    if ( v9[id] != nullptr )
      idClipModel::Link(
        this: v9[id],
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: id,
        newOrigin: &this->current.list[v6].worldOrigin,
        newAxis: &this->current.list[v6].worldAxis);
  }
}


// ========================================================================
// ??1idPhysics_StaticMulti@@UAA@XZ
// EA  : 0x82765090
// RVA : 0x00765090
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::~idPhysics_StaticMulti(idPhysics_StaticMulti *this)
{
  int v2; // r28
  int v3; // r29
  idClipModel **list; // r11
  staticPState_t *v5; // r4
  float *v6; // r4
  idClipModel **v7; // r4

  this->__vftable = (idPhysics_StaticMulti_vtbl *)&idPhysics_StaticMulti::`vftable';
  v2 = 0;
  if ( this->clipModels.num > 0 )
  {
    v3 = 0;
    do
    {
      list = this->clipModels.list;
      if ( list[v3] != nullptr )
        idClipModel::Delete(this: list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->clipModels.num );
  }
  if ( this->current.listStatic == 0 || this->current.listStatic == 2 )
  {
    v5 = this->current.list;
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    this->current.list = nullptr;
    this->current.size = 0;
  }
  this->current.num = 0;
  if ( this->mass.listStatic == 0 || this->mass.listStatic == 2 )
  {
    v6 = this->mass.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->mass.list = nullptr;
    this->mass.size = 0;
  }
  this->mass.num = 0;
  if ( this->clipModels.listStatic == 0 || this->clipModels.listStatic == 2 )
  {
    v7 = this->clipModels.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->clipModels.list = nullptr;
    this->clipModels.size = 0;
  }
  this->clipModels.num = 0;
  idPhysics::~idPhysics(this);
}


// ========================================================================
// __unwind$251395
// EA  : 0x827651C4
// RVA : 0x007651C4
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void _unwind_251395()
{
  int v0; // r12

  idPhysics::~idPhysics(this: *(idPhysics **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$251396
// EA  : 0x827651EC
// RVA : 0x007651EC
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void _unwind_251396()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 48));
}


// ========================================================================
// __unwind$251397
// EA  : 0x82765218
// RVA : 0x00765218
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void _unwind_251397()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 64));
}


// ========================================================================
// __unwind$251398
// EA  : 0x82765244
// RVA : 0x00765244
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void _unwind_251398()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 132));
}


// ========================================================================
// ?ClipContents@idPhysics_StaticMulti@@UBAHPBVidClipModel@@H@Z
// EA  : 0x82765270
// RVA : 0x00765270
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

int __fastcall idPhysics_StaticMulti::ClipContents(idPhysics_StaticMulti *this, idClipModel *model, int clipMask)
{
  int v6; // r25
  int v7; // r28
  int v8; // r30
  int v9; // r8
  int v10; // r9
  const idMat3 *v12; // [sp+8h] [-128h]
  int v13; // [sp+Ch] [-124h]
  int v14; // [sp+10h] [-120h]
  int v15; // [sp+14h] [-11Ch]
  int v16; // [sp+18h] [-118h]
  int v17; // [sp+1Ch] [-114h]
  int v18; // [sp+20h] [-110h]
  int v19; // [sp+24h] [-10Ch]
  int v20; // [sp+28h] [-108h]
  int v21; // [sp+2Ch] [-104h]
  int v22; // [sp+30h] [-100h]
  int v23; // [sp+34h] [-FCh]
  int v24; // [sp+38h] [-F8h]
  int v25; // [sp+3Ch] [-F4h]
  int v26; // [sp+40h] [-F0h]
  int v27; // [sp+44h] [-ECh]
  int v28; // [sp+48h] [-E8h]
  int v29; // [sp+4Ch] [-E4h]
  int v30; // [sp+50h] [-E0h]
  char v31; // [sp+60h] [-D0h] BYREF
  trace_t v32; // [sp+70h] [-C0h] BYREF

  v6 = 0;
  v7 = 0;
  if ( this->clipModels.num > 0 )
  {
    v8 = 0;
    do
    {
      if ( this->clipModels.list[v8] != nullptr )
      {
        if ( model != nullptr )
        {
          v9 = clipMask;
          if ( clipMask == 0 )
            v9 = -1;
          idClip::ContentsModel(
            this: this->clip,
            result: &v32,
            start: &this->clipModels.list[v8]->origin,
            trm: this->clipModels.list[v8],
            trmAxis: &this->clipModels.list[v8]->axis,
            clipMask: v9,
            model,
            modelOrigin: &model->origin,
            modelAxis: v12,
            a10: v13,
            a11: v14,
            a12: v15,
            a13: v16,
            a14: v17,
            a15: v18,
            a16: v19,
            a17: v20,
            a18: v21,
            a19: v22,
            a20: v23,
            a21: v24,
            a22: v25,
            a23: v26,
            a24: v27,
            a25: v28,
            a26: v29,
            a27: v30,
            a28: (float *)&model->axis);
        }
        else
        {
          v10 = clipMask;
          if ( clipMask == 0 )
            v10 = -1;
          idClip::Contents(
            this: (idClip *)&v31,
            result: this->clip,
            a3: &v32,
            start: &this->clipModels.list[v8]->origin,
            clipModel: this->clipModels.list[v8],
            startAxis: &this->clipModels.list[v8]->axis,
            clipMask: v10,
            passEntityNumber: 0x1FFF,
            userName: (const char *)v12,
            a10: v13,
            a11: v14,
            a12: v15,
            a13: v16,
            a14: v17,
            a15: v18,
            a16: v19,
            a17: v20,
            a18: v21,
            a19: v22,
            a20: v23,
            a21: v24,
            a22: v25,
            a23: v26,
            a24: v27,
            a25: v28,
            a26: v29,
            a27: v30,
            a28: 0);
        }
        v6 |= v32.c.contentFlags;
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->clipModels.num );
  }
  return v6;
}


// ========================================================================
// ??0idPhysics_StaticMulti@@QAA@XZ
// EA  : 0x82765520
// RVA : 0x00765520
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

idPhysics_StaticMulti *__fastcall idPhysics_StaticMulti::idPhysics_StaticMulti(idPhysics_StaticMulti *this)
{
  int size; // r11
  int v3; // r11
  int v4; // r11

  idPhysics::idPhysics(this);
  this->__vftable = (idPhysics_StaticMulti_vtbl *)&idPhysics_StaticMulti::`vftable';
  this->clipModels.list = nullptr;
  this->clipModels.granularity = 0;
  this->clipModels.memTag = 77;
  this->clipModels.listStatic = 0;
  this->clipModels.size = 0;
  this->clipModels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->clipModels);
  this->mass.list = nullptr;
  this->mass.granularity = 0;
  this->mass.memTag = 77;
  this->mass.listStatic = 0;
  this->mass.size = 0;
  this->mass.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->mass);
  this->current.list = nullptr;
  this->current.granularity = 0;
  this->current.memTag = 77;
  this->current.listStatic = 0;
  this->current.size = 0;
  this->current.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->current);
  this->hasMaster = false;
  this->isOrientated = false;
  this->type = PHYSICS_STATICMULTI;
  defaultState.worldOrigin.z = 0.0;
  defaultState.worldOrigin.y = 0.0;
  defaultState.worldOrigin.x = 0.0;
  defaultState.worldAxis.mat[2].z = 1.0;
  defaultState.worldAxis.mat[1].y = 1.0;
  defaultState.worldAxis.mat[0].x = 1.0;
  defaultState.worldAxis.mat[1].z = 0.0;
  defaultState.worldAxis.mat[0].z = 0.0;
  defaultState.worldAxis.mat[0].y = 0.0;
  defaultState.worldAxis.mat[2].y = 0.0;
  defaultState.worldAxis.mat[2].x = 0.0;
  defaultState.worldAxis.mat[1].x = 0.0;
  defaultState.localOrigin.z = 0.0;
  defaultState.localOrigin.y = 0.0;
  defaultState.localOrigin.x = 0.0;
  defaultState.localAxis.mat[2].z = 1.0;
  defaultState.localAxis.mat[1].y = 1.0;
  defaultState.localAxis.mat[0].x = 1.0;
  defaultState.localAxis.mat[1].z = 0.0;
  defaultState.localAxis.mat[0].z = 0.0;
  defaultState.localAxis.mat[0].y = 0.0;
  defaultState.localAxis.mat[2].y = 0.0;
  defaultState.localAxis.mat[2].x = 0.0;
  defaultState.localAxis.mat[1].x = 0.0;
  if ( this->current.size >= 1
    || (unsigned __int8)idList<staticPState_t,77>::Resize(this: &this->current, newsize: 1) != 0 )
  {
    size = this->current.size;
    if ( size > 1 )
      size = 1;
    this->current.num = size;
  }
  staticPState_t::operator=(this: this->current.list, __that: &defaultState);
  if ( this->clipModels.size >= 1
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->clipModels,
         newsize: 1) )
  {
    v3 = this->clipModels.size;
    if ( v3 > 1 )
      v3 = 1;
    this->clipModels.num = v3;
  }
  *this->clipModels.list = nullptr;
  if ( this->mass.size >= 1
    || (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&this->mass, newsize: 1) != 0 )
  {
    v4 = this->mass.size;
    if ( v4 > 1 )
      v4 = 1;
    this->mass.num = v4;
  }
  *this->mass.list = 1.0;
  return this;
}


// ========================================================================
// __unwind$251717
// EA  : 0x82765728
// RVA : 0x00765728
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void _unwind_251717()
{
  int v0; // r12

  idPhysics::~idPhysics(this: *(idPhysics **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$251718
// EA  : 0x82765750
// RVA : 0x00765750
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void _unwind_251718()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 48));
}


// ========================================================================
// __unwind$251719
// EA  : 0x8276577C
// RVA : 0x0076577C
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void _unwind_251719()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 64));
}


// ========================================================================
// __unwind$251720_0
// EA  : 0x827657A8
// RVA : 0x007657A8
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void _unwind_251720_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 132));
}


// ========================================================================
// ?SetClipModel@idPhysics_StaticMulti@@UAAXPAVidClipModel@@MH_N@Z
// EA  : 0x827657D8
// RVA : 0x007657D8
// PDB : w:\tech5\engine\gamelib\physics\physics_staticmulti.cpp
// ========================================================================

void __fastcall idPhysics_StaticMulti::SetClipModel(
        idPhysics_StaticMulti *this,
        idClipModel *model,
        double density,
        int id,
        int freeOld,
        char a6)
{
  int num; // r11
  int v12; // r31
  int v13; // r11
  int v14; // r11
  idClipModel **list; // r10
  idList<idClipModel *,77> *p_clipModels; // r28
  idClipModel *v17; // r11
  float *v18; // r11
  int v19; // r11
  int v20; // r10
  int v21; // r31
  int size; // r11
  int v23; // r11
  idList<float,13> *p_mass; // r30
  int v25; // r11
  int v26[2]; // [sp+50h] [-90h] BYREF
  idMat3 v27; // [sp+58h] [-88h] BYREF

  if ( freeOld >= this->clipModels.num )
  {
    num = this->current.num;
    v12 = freeOld + 1;
    if ( freeOld + 1 > num )
      num = freeOld + 1;
    idList<staticPState_t,77>::SetNum(this: &this->current, newNum: num, initValue: &defaultState);
    v13 = this->clipModels.num;
    v26[0] = 0;
    if ( v12 > v13 )
      v13 = v12;
    idList<idRenderModelCommitted *,5>::SetNum(this: (idList<int,5> *)&this->clipModels, newNum: v13, initValue: v26);
    v14 = this->clipModels.num;
    *(float *)v26 = 1.0;
    if ( v12 > v14 )
      v14 = v12;
    idList<float,17>::SetNum(this: (idList<float,32> *)&this->mass, newNum: v14, initValue: (float *)v26);
  }
  list = this->clipModels.list;
  p_clipModels = &this->clipModels;
  v17 = list[freeOld];
  if ( v17 != nullptr && v17 != model && a6 != 0 )
    idClipModel::Delete(this: list[freeOld]);
  p_clipModels->list[freeOld] = model;
  if ( p_clipModels->list[freeOld] != nullptr )
  {
    v18 = this->mass.list;
    if ( model->traceModels.num != 0 )
      idClipModel::GetMassProperties(
        this: p_clipModels->list[freeOld],
        density,
        mass: (float *)model,
        centerOfMass: (idVec3 *)&v18[freeOld],
        inertiaTensor: &v27,
        a6: &v27.mat[2].x);
    else
      v18[freeOld] = 1.0;
    idClipModel::Link(
      this: p_clipModels->list[freeOld],
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: freeOld,
      newOrigin: &this->current.list[freeOld].worldOrigin,
      newAxis: &this->current.list[freeOld].worldAxis);
  }
  v19 = this->clipModels.num - 1;
  if ( v19 >= 1 )
  {
    v20 = v19;
    do
    {
      if ( p_clipModels->list[v20] != nullptr )
        break;
      --v19;
      --v20;
    }
    while ( v19 >= 1 );
  }
  v21 = v19 + 1;
  if ( v19 + 1 <= this->current.size
    || (unsigned __int8)idList<staticPState_t,77>::Resize(this: &this->current, newsize: v19 + 1) != 0 )
  {
    size = this->current.size;
    if ( v21 < size )
      size = v21;
    this->current.num = size;
  }
  if ( v21 <= this->clipModels.size
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->clipModels,
         newsize: v21) )
  {
    v23 = this->clipModels.size;
    if ( v21 < v23 )
      v23 = v21;
    this->clipModels.num = v23;
  }
  p_mass = (idList<float,13> *)&this->mass;
  if ( v21 <= p_mass->size || (unsigned __int8)idList<float,116>::Resize(this: p_mass, newsize: v21) != 0 )
  {
    v25 = p_mass->size;
    if ( v21 < v25 )
      v25 = v21;
    p_mass->num = v25;
  }
}

