
// ========================================================================
// ??0swfGradient_t@@QAA@XZ
// EA  : 0x82561348
// RVA : 0x00561348
// PDB : w:\tech5\engine\guis\swf\swf_types.h
// ========================================================================

swfGradient_t *__fastcall swfGradient_t::swfGradient_t(swfGradient_t *this)
{
  swfGradient_t *v1; // r11
  _BYTE *v2; // r9
  int i; // ctr

  v1 = this;
  v2 = (char *)this - 9;
  this->numGradients = 0;
  for ( i = 16; i != 0; --i )
  {
    v2 += 10;
    *v2 = 0;
    *(_WORD *)&v1->gradientRecords[0].endRatio = 255;
    v1->gradientRecords[0].startColor.g = -1;
    v1->gradientRecords[0].startColor.b = -1;
    v1->gradientRecords[0].startColor.a = -1;
    v1->gradientRecords[0].endColor.r = -1;
    v1->gradientRecords[0].endColor.g = -1;
    v1->gradientRecords[0].endColor.b = -1;
    v1 = (swfGradient_t *)((char *)v1 + 10);
    v1->numGradients = -1;
  }
  return this;
}


// ========================================================================
// ??0swfFillStyle_t@@QAA@XZ
// EA  : 0x82561398
// RVA : 0x00561398
// PDB : w:\tech5\engine\guis\swf\swf_types.h
// ========================================================================

swfFillStyle_t *__fastcall swfFillStyle_t::swfFillStyle_t(swfFillStyle_t *this)
{
  this->type = 0;
  this->subType = 0;
  this->startColor.r = -1;
  this->startColor.g = -1;
  this->startColor.b = -1;
  this->startColor.a = -1;
  this->endColor.r = -1;
  this->endColor.g = -1;
  this->endColor.b = -1;
  this->endColor.a = -1;
  this->startMatrix.xx = 1.0;
  this->startMatrix.yy = 1.0;
  this->startMatrix.xy = 0.0;
  this->startMatrix.yx = 0.0;
  this->startMatrix.tx = 0.0;
  this->startMatrix.ty = 0.0;
  this->endMatrix.xx = 1.0;
  this->endMatrix.yy = 1.0;
  this->endMatrix.xy = 0.0;
  this->endMatrix.yx = 0.0;
  this->endMatrix.tx = 0.0;
  this->endMatrix.ty = 0.0;
  swfGradient_t::swfGradient_t(this: &this->gradient);
  this->focalPoint = 0.0;
  this->bitmapID = 0;
  return this;
}


// ========================================================================
// ?Inverse@swfMatrix_t@@QBA?AU1@XZ
// EA  : 0x8277E668
// RVA : 0x0077E668
// PDB : w:\tech5\engine\guis\swf\swf_types.h
// ========================================================================

swfMatrix_t *__fastcall swfMatrix_t::Inverse(swfMatrix_t *this, swfMatrix_t *result)
{
  double yx; // fp12
  double xy; // fp11
  double v4; // fp8
  double yy; // fp10
  double xx; // fp9
  _DWORD *v7; // r10
  int v8; // ctr
  double v9; // fp8
  _DWORD *p_ty; // r11
  char *v11; // r11
  char v12; // [sp+0h] [-24h] BYREF
  float v13; // [sp+4h] [-20h]
  float v14; // [sp+8h] [-1Ch]
  float back_chain; // [sp+Ch] [-18h]
  float v16; // [sp+10h] [-14h]
  float v17; // [sp+14h] [-10h]
  float v18; // [sp+18h] [-Ch]

  yx = result->yx;
  xy = result->xy;
  v4 = (float)(result->xy * result->yx);
  yy = result->yy;
  xx = result->xx;
  back_chain = 0.0;
  v7 = (_DWORD *)((char *)this - 4);
  v13 = 1.0;
  v14 = 1.0;
  v8 = 6;
  v16 = 0.0;
  v9 = (float)((float)((float)xx * (float)yy) - (float)v4);
  v17 = 0.0;
  v18 = 0.0;
  if ( __fabs(v9) >= idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    v11 = &v12;
    v13 = (float)yy * (float)((float)1.0 / (float)v9);
    v14 = (float)xx * (float)((float)1.0 / (float)v9);
    v16 = -(float)((float)yx * (float)((float)1.0 / (float)v9));
    back_chain = -(float)((float)xy * (float)((float)1.0 / (float)v9));
    do
    {
      v11 += 4;
      *++v7 = *(_DWORD *)v11;
      --v8;
    }
    while ( v8 != 0 );
  }
  else
  {
    p_ty = (_DWORD *)&result[-1].ty;
    do
    {
      *++v7 = *++p_ty;
      --v8;
    }
    while ( v8 != 0 );
  }
  return this;
}


// ========================================================================
// ?ToVec4@swfColorRGBA_t@@QBA?AVidVec4@@XZ
// EA  : 0x8277E720
// RVA : 0x0077E720
// PDB : w:\tech5\engine\guis\swf\swf_types.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
swfColorRGBA_t *__fastcall swfColorRGBA_t::ToVec4(swfColorRGBA_t *this, idVec4 *result, __int64 a3)
{
  __int64 v3; // r8
  __int64 v4; // r11

  HIDWORD(v3) = LOBYTE(result->x);
  HIDWORD(v4) = byte_821B0000;
  LODWORD(a3) = HIBYTE(result->x);
  LODWORD(v3) = BYTE1(result->x);
  LODWORD(v4) = BYTE2(result->x);
  *((float *)this + 2) = (float)v4 * (float)0.0039215689;
  *((float *)this + 1) = (float)v3 * (float)0.0039215689;
  *(float *)this = (float)a3 * (float)0.0039215689;
  *((float *)this + 3) = (float)*(__int64 *)((char *)&a3 - 4) * (float)0.0039215689;
  return this;
}


// ========================================================================
// ?Multiply@swfColorXform_t@@QBA?AU1@ABU1@@Z
// EA  : 0x8277E7A0
// RVA : 0x0077E7A0
// PDB : w:\tech5\engine\guis\swf\swf_types.h
// ========================================================================

swfColorXform_t *__fastcall swfColorXform_t::Multiply(
        swfColorXform_t *this,
        swfColorXform_t *result,
        const swfColorXform_t *a)
{
  double x; // fp12
  double v4; // fp11
  double z; // fp8
  double v6; // fp7
  double v7; // fp5
  double v8; // fp10
  double v9; // fp8
  double w; // fp7
  double v11; // fp0
  double v12; // fp4
  double v13; // fp13

  this->mul.x = 1.0;
  this->mul.y = 1.0;
  this->mul.z = 1.0;
  this->mul.w = 1.0;
  this->add.x = 0.0;
  this->add.y = 0.0;
  this->add.z = 0.0;
  this->add.w = 0.0;
  x = a->mul.x;
  v4 = result->mul.x;
  z = result->mul.z;
  v6 = a->mul.z;
  v7 = (float)(result->mul.y * a->mul.y);
  this->mul.w = result->mul.w * a->mul.w;
  this->mul.x = (float)x * (float)v4;
  this->mul.y = v7;
  this->mul.z = (float)z * (float)v6;
  v8 = a->add.x;
  v9 = a->add.z;
  w = a->add.w;
  v11 = (float)(a->mul.x * result->add.x);
  v12 = (float)(result->add.z * a->mul.z);
  v13 = (float)(result->add.w * a->mul.w);
  this->add.y = a->add.y + (float)(result->add.y * a->mul.y);
  this->add.x = (float)v8 + (float)v11;
  this->add.z = (float)v9 + (float)v12;
  this->add.w = (float)w + (float)v13;
  return this;
}

