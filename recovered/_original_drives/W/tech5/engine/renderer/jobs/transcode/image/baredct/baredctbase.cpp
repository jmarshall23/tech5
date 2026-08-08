
// ========================================================================
// ??0idBareDctBase@@QAA@XZ
// EA  : 0x828E4CE8
// RVA : 0x008E4CE8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctbase.cpp
// ========================================================================

idBareDctBase *__fastcall idBareDctBase::idBareDctBase(idBareDctBase *this)
{
  this->luminanceQuality = 75;
  this->chrominanceQuality = 75;
  this->alphaQuality = 75;
  this->sampleMode = SAMPLE_420;
  return this;
}


// ========================================================================
// ?InitQuantTable@idBareDctBase@@IAAXXZ
// EA  : 0x828E4D08
// RVA : 0x008E4D08
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctbase.cpp
// ========================================================================

void __fastcall idBareDctBase::InitQuantTable(idBareDctBase *this)
{
  idBareDctBase::SetQuality_Xenon(
    this,
    luminanceQuality: this->luminanceQuality,
    chrominanceQuality: this->chrominanceQuality,
    alphaQuality: this->alphaQuality);
}


// ========================================================================
// ?QuantizationScaleFromQuality@idBareDctBase@@KAHH@Z
// EA  : 0x828E4D18
// RVA : 0x008E4D18
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctbase.cpp
// ========================================================================

int __fastcall idBareDctBase::QuantizationScaleFromQuality(int quality)
{
  if ( quality <= 0 )
  {
    __twllei(1u, 0);
    return 5000;
  }
  if ( quality > 100 )
  {
    quality = 100;
    return 2 * (100 - quality);
  }
  if ( quality >= 50 )
    return 2 * (100 - quality);
  __twllei(quality, 0);
  return 5000 / quality;
}


// ========================================================================
// ?ScaleQuantTable@idBareDctBase@@KAXPAGPBGH@Z
// EA  : 0x828E4D68
// RVA : 0x008E4D68
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctbase.cpp
// ========================================================================

void __fastcall idBareDctBase::ScaleQuantTable(char *result, char *standard, const int scale)
{
  char *v3; // r10
  int i; // ctr
  int v5; // r11

  v3 = result;
  for ( i = 64; i != 0; --i )
  {
    v5 = (*(unsigned __int16 *)&v3[standard - result] * (((36701 * scale) >> 16) + 2 * scale)) >> 16;
    if ( v5 >= 1 )
    {
      if ( v5 > 255 )
        LOWORD(v5) = 255;
    }
    else
    {
      LOWORD(v5) = 1;
    }
    *(_WORD *)v3 = v5;
    v3 += 2;
  }
}


// ========================================================================
// ?SetQuality_Generic@idBareDctBase@@QAAXHHH@Z
// EA  : 0x828E4DD0
// RVA : 0x008E4DD0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctbase.cpp
// ========================================================================

void __fastcall idBareDctBase::SetQuality_Generic(
        idBareDctBase *this,
        int luminanceQuality,
        int chrominanceQuality,
        int alphaQuality)
{
  int v6; // r11
  int v7; // r5
  int v8; // r11
  int v9; // r30
  int v10; // r11
  int v11; // r31
  int v12; // r6
  int v13; // r6

  v6 = luminanceQuality;
  if ( luminanceQuality <= 0 )
  {
    v7 = 5000;
    __twllei(1u, 0);
    goto LABEL_6;
  }
  if ( luminanceQuality > 100 )
  {
    v6 = 100;
LABEL_5:
    v7 = 2 * (100 - v6);
    goto LABEL_6;
  }
  if ( luminanceQuality >= 50 )
    goto LABEL_5;
  v7 = 5000 / luminanceQuality;
  __twllei(luminanceQuality, 0);
LABEL_6:
  v8 = chrominanceQuality;
  if ( chrominanceQuality <= 0 )
  {
    v9 = 5000;
    __twllei(1u, 0);
    goto LABEL_13;
  }
  if ( chrominanceQuality > 100 )
  {
    v8 = 100;
LABEL_12:
    v9 = 2 * (100 - v8);
    goto LABEL_13;
  }
  if ( chrominanceQuality >= 50 )
    goto LABEL_12;
  v9 = 5000 / chrominanceQuality;
  __twllei(chrominanceQuality, 0);
LABEL_13:
  v10 = alphaQuality;
  if ( alphaQuality > 0 )
  {
    if ( alphaQuality <= 100 )
    {
      if ( alphaQuality < 50 )
      {
        v11 = 5000 / alphaQuality;
        __twllei(alphaQuality, 0);
        goto LABEL_20;
      }
    }
    else
    {
      v10 = 100;
    }
    v11 = 2 * (100 - v10);
  }
  else
  {
    v11 = 5000;
    __twllei(1u, 0);
  }
LABEL_20:
  idBareDctBase::ScaleQuantTable(
    result: (char *)this->quantTableY,
    standard: (char *)std_luminance_quant_tbl,
    scale: v7);
  idBareDctBase::ScaleQuantTable(result: (char *)this->quantTableCoCg, standard: (char *)(v12 + 128), scale: v9);
  idBareDctBase::ScaleQuantTable(result: (char *)this->quantTableA, standard: (char *)(v13 + 256), scale: v11);
}

