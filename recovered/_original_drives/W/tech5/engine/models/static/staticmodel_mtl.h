
// ========================================================================
// ??0idParsedMtl@@QAA@XZ
// EA  : 0x825F67B0
// RVA : 0x005F67B0
// PDB : w:\tech5\engine\models\static\staticmodel_mtl.h
// ========================================================================

idParsedMtl *__fastcall idParsedMtl::idParsedMtl(idParsedMtl *this)
{
  this->mtlName.len = 0;
  this->mtlName.allocedAndFlag = 20;
  this->mtlName.data = this->mtlName.baseBuffer;
  this->mtlName.baseBuffer[0] = 0;
  this->Ns = 0.0;
  this->Ni = 0.0;
  this->d = 0.0;
  this->Tr = 0.0;
  this->sharpness = 0.0;
  this->Tf.x = 0.0;
  this->Tf.y = 0.0;
  this->Tf.z = 0.0;
  this->illum = 2;
  this->Ka.x = 0.0;
  this->Ka.y = 0.0;
  this->Ka.z = 0.0;
  this->Kd.x = 0.5;
  this->Kd.y = 0.5;
  this->Kd.z = 0.5;
  this->Ks.x = 0.0;
  this->Ks.y = 0.0;
  this->Ks.z = 0.0;
  this->Ke.x = 0.0;
  this->Ke.y = 0.0;
  this->Ke.z = 0.0;
  this->map_Ka.data = this->map_Ka.baseBuffer;
  this->map_Ka.allocedAndFlag = 20;
  this->map_Ka.len = 0;
  this->map_Ka.baseBuffer[0] = 0;
  this->map_Kd.data = this->map_Kd.baseBuffer;
  this->map_Kd.allocedAndFlag = 20;
  this->map_Kd.len = 0;
  this->map_Kd.baseBuffer[0] = 0;
  this->map_Ks.allocedAndFlag = 20;
  this->map_Ks.data = this->map_Ks.baseBuffer;
  this->map_Ks.len = 0;
  this->map_Ks.baseBuffer[0] = 0;
  this->map_Ke.data = this->map_Ke.baseBuffer;
  this->map_Ke.allocedAndFlag = 20;
  this->map_Ke.len = 0;
  this->map_Ke.baseBuffer[0] = 0;
  this->map_bump.data = this->map_bump.baseBuffer;
  this->map_bump.allocedAndFlag = 20;
  this->map_bump.len = 0;
  this->map_bump.baseBuffer[0] = 0;
  this->map_opacity.data = this->map_opacity.baseBuffer;
  this->map_opacity.allocedAndFlag = 20;
  this->map_opacity.len = 0;
  this->map_opacity.baseBuffer[0] = 0;
  this->map_d.data = this->map_d.baseBuffer;
  this->map_d.allocedAndFlag = 20;
  this->map_d.len = 0;
  this->map_d.baseBuffer[0] = 0;
  this->map_Ns.allocedAndFlag = 20;
  this->map_Ns.data = this->map_Ns.baseBuffer;
  this->map_Ns.len = 0;
  this->map_Ns.baseBuffer[0] = 0;
  this->map_refl.data = this->map_refl.baseBuffer;
  this->map_refl.allocedAndFlag = 20;
  this->map_refl.len = 0;
  this->map_refl.baseBuffer[0] = 0;
  this->decal.data = this->decal.baseBuffer;
  this->decal.allocedAndFlag = 20;
  this->decal.len = 0;
  this->decal.baseBuffer[0] = 0;
  this->disp.allocedAndFlag = 20;
  this->disp.data = this->disp.baseBuffer;
  this->disp.len = 0;
  this->disp.baseBuffer[0] = 0;
  this->map_aat = false;
  return this;
}

