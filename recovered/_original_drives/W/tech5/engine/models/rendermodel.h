
// ========================================================================
// ?GetOrigin@idRenderModel@@QBAABVidVec3@@XZ
// EA  : 0x826C94E0
// RVA : 0x006C94E0
// PDB : w:\tech5\engine\models\rendermodel.h
// ========================================================================

idRenderModelParms *__fastcall idRenderModel::GetOrigin(idRenderModel *this)
{
  if ( this->useDeferredPosition )
    return (idRenderModelParms *)&this->deferredOrigin;
  else
    return &this->g;
}


// ========================================================================
// ?GetAxis@idRenderModel@@QBAABVidMat3@@XZ
// EA  : 0x826C9500
// RVA : 0x006C9500
// PDB : w:\tech5\engine\models\rendermodel.h
// ========================================================================

const idMat3 *__fastcall idRenderModel::GetAxis(idRenderModel *this)
{
  if ( this->useDeferredPosition )
    return &this->deferredAxis;
  else
    return &this->g.axis;
}


// ========================================================================
// ?SetAxis@idRenderModel@@QAAXABVidMat3@@@Z
// EA  : 0x82702FA8
// RVA : 0x00702FA8
// PDB : w:\tech5\engine\models\rendermodel.h
// ========================================================================

void __fastcall idRenderModel::SetAxis(idRenderModel *this, const idMat3 *a)
{
  if ( !this->deferredPositionInitialized || !this->useDeferredPosition )
    this->g.axis = *a;
  this->deferredAxis = *a;
}


// ========================================================================
// ?SetModelFade@idRenderModel@@QAAXM@Z
// EA  : 0x82703058
// RVA : 0x00703058
// PDB : w:\tech5\engine\models\rendermodel.h
// ========================================================================

void __fastcall idRenderModel::SetModelFade(idRenderModel *this, double v)
{
  idStaticParmBlock<32> *p_gameParmBlock; // r3
  char v4; // r10
  parmValue_t v5; // [sp+50h] [-20h] BYREF

  if ( (*((_BYTE *)&this->g + 116) & 0x20) == 0 )
  {
    this->g.modelFade = v;
    p_gameParmBlock = &this->gameParmBlock;
    if ( v == 1.0 )
    {
      *((_BYTE *)&this->g + 106) &= ~4u;
      idParmBlock::ClearParm(this: p_gameParmBlock, parm: rp->modelFade);
    }
    else
    {
      v4 = *((_BYTE *)&this->g + 106);
      v5.value[3] = v;
      v5.value[2] = v;
      v5.value[1] = v;
      v5.value[0] = v;
      *((_BYTE *)&this->g + 106) = v4 | 4;
      idParmBlock::SetParm(this: p_gameParmBlock, parm: rp->modelFade, parmValue: &v5);
    }
  }
}


// ========================================================================
// ?GetSkins@idRenderModel@@UBAPBVidDeclSkins@@XZ
// EA  : 0x827B08A8
// RVA : 0x007B08A8
// PDB : w:\tech5\engine\models\rendermodel.h
// ========================================================================

const idDeclSkins *__fastcall idRenderModel::GetSkins(idRenderModel *this)
{
  const idDecl *v1; // r30
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: this->name.str);
  idStr::StripFileExtension(this: &v3);
  if ( v3.data != nullptr )
    v1 = idDeclInfo::FindWithInheritance(this: &idDeclSkins::resourceList, name: v3.data, makeDefault: true);
  else
    v1 = nullptr;
  idStr::FreeData(this: &v3);
  return (const idDeclSkins *)v1;
}


// ========================================================================
// __unwind$232548
// EA  : 0x827B0920
// RVA : 0x007B0920
// PDB : w:\tech5\engine\models\rendermodel.h
// ========================================================================

void _unwind_232548()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?GlobalPointToLocal@idRenderModel@@QBAXABVidVec3@@AAV2@@Z
// EA  : 0x8288FE90
// RVA : 0x0088FE90
// PDB : w:\tech5\engine\models\rendermodel.h
// ========================================================================

void __fastcall idRenderModel::GlobalPointToLocal(idRenderModel *this, const idVec3 *in, idVec3 *out)
{
  idRenderModelParms *p_deferredOrigin; // r11
  double v4; // fp0
  double v5; // fp13
  float *p_deferredAxis; // r11
  double v7; // fp12
  double z; // fp10
  double y; // fp8
  double v10; // fp4
  double v11; // fp3

  p_deferredOrigin = (idRenderModelParms *)&this->deferredOrigin;
  if ( !this->useDeferredPosition )
    p_deferredOrigin = &this->g;
  v4 = (float)(in->x - p_deferredOrigin->origin.x);
  v5 = (float)(in->y - p_deferredOrigin->origin.y);
  v7 = (float)(in->z - p_deferredOrigin->origin.z);
  p_deferredAxis = (float *)&this->deferredAxis;
  if ( !this->useDeferredPosition )
    p_deferredAxis = (float *)&this->g.axis;
  z = this->g.scale.z;
  y = this->g.scale.y;
  v10 = (float)((float)(p_deferredAxis[4] * (float)v5)
              + (float)((float)(p_deferredAxis[5] * (float)v7) + (float)(p_deferredAxis[3] * (float)v4)));
  v11 = (float)((float)(p_deferredAxis[7] * (float)v5)
              + (float)((float)(p_deferredAxis[8] * (float)v7) + (float)(p_deferredAxis[6] * (float)v4)));
  out->x = (float)((float)(*p_deferredAxis * (float)v4)
                 + (float)((float)(p_deferredAxis[2] * (float)v7) + (float)(p_deferredAxis[1] * (float)v5)))
         / this->g.scale.x;
  out->y = (float)v10 / (float)y;
  out->z = (float)v11 / (float)z;
}


// ========================================================================
// ?LocalPointToGlobal@idRenderModel@@QBAXABVidVec3@@AAV2@@Z
// EA  : 0x8288FF48
// RVA : 0x0088FF48
// PDB : w:\tech5\engine\models\rendermodel.h
// ========================================================================

void __fastcall idRenderModel::LocalPointToGlobal(idRenderModel *this, const idVec3 *in, idVec3 *out)
{
  idRenderModelParms *p_deferredOrigin; // r10
  float *p_deferredAxis; // r11
  double y; // fp8
  double z; // fp12
  double v7; // fp5
  double v8; // fp4

  p_deferredOrigin = (idRenderModelParms *)&this->deferredOrigin;
  if ( this->useDeferredPosition )
  {
    p_deferredAxis = (float *)&this->deferredAxis;
  }
  else
  {
    p_deferredOrigin = &this->g;
    p_deferredAxis = (float *)&this->g.axis;
  }
  y = p_deferredOrigin->origin.y;
  v7 = (float)((float)(p_deferredAxis[4] * (float)(this->g.scale.y * in->y))
             + (float)((float)(p_deferredAxis[1] * (float)(this->g.scale.x * in->x))
                     + (float)(p_deferredAxis[7] * (float)(this->g.scale.z * in->z))));
  v8 = (float)((float)(p_deferredAxis[5] * (float)(this->g.scale.y * in->y))
             + (float)((float)(p_deferredAxis[2] * (float)(this->g.scale.x * in->x))
                     + (float)(p_deferredAxis[8] * (float)(this->g.scale.z * in->z))));
  z = p_deferredOrigin->origin.z;
  out->x = p_deferredOrigin->origin.x
         + (float)((float)((float)(this->g.scale.x * in->x) * *p_deferredAxis)
                 + (float)((float)(p_deferredAxis[6] * (float)(this->g.scale.z * in->z))
                         + (float)(p_deferredAxis[3] * (float)(this->g.scale.y * in->y))));
  out->y = (float)y + (float)v7;
  out->z = (float)z + (float)v8;
}

