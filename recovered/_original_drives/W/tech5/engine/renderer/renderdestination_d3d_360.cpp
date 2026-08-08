
// ========================================================================
// ??0idRenderDestination@@QAA@XZ
// EA  : 0x82942320
// RVA : 0x00942320
// PDB : w:\tech5\engine\renderer\renderdestination_d3d_360.cpp
// ========================================================================

idRenderDestination *__fastcall idRenderDestination::idRenderDestination(idRenderDestination *this)
{
  this->isDefault = false;
  this->targetWidth = -1;
  this->targetHeight = -1;
  this->targetImage[0] = nullptr;
  this->targetImage[1] = nullptr;
  this->targetImage[2] = nullptr;
  this->targetImage[3] = nullptr;
  this->depthImage = nullptr;
  this->stencilImage = nullptr;
  this->targetSurface[0] = nullptr;
  this->targetSurface[1] = nullptr;
  this->targetSurface[2] = nullptr;
  this->targetSurface[3] = nullptr;
  this->depthSurface = nullptr;
  return this;
}


// ========================================================================
// ?AddTarget@idRenderDestination@@QAAXPAVidImage@@PAUD3DSurface@@@Z
// EA  : 0x82942370
// RVA : 0x00942370
// PDB : w:\tech5\engine\renderer\renderdestination_d3d_360.cpp
// ========================================================================

void __fastcall idRenderDestination::AddTarget(idRenderDestination *this, idImage *target, D3DSurface *surf)
{
  int v3; // r11
  D3DSurface **i; // r10

  v3 = 0;
  for ( i = this->targetSurface; *i != nullptr; ++i )
  {
    if ( ++v3 >= 4 )
      return;
  }
  this->targetImage[v3] = target;
  this->targetSurface[v3] = surf;
}


// ========================================================================
// ?Resize@idRenderDestination@@QAAXHH@Z
// EA  : 0x829423B8
// RVA : 0x009423B8
// PDB : w:\tech5\engine\renderer\renderdestination_d3d_360.cpp
// ========================================================================

void __fastcall idRenderDestination::Resize(idRenderDestination *this, unsigned int width, unsigned int height)
{
  idImage **targetImage; // r31
  int i; // r27
  idImage *depthImage; // r3

  this->targetWidth = width;
  this->targetHeight = height;
  targetImage = this->targetImage;
  for ( i = 4; i != 0; --i )
  {
    if ( *targetImage != nullptr )
      idImage::Resize(this: *targetImage, width, height, depth: 0);
    ++targetImage;
  }
  depthImage = this->depthImage;
  if ( depthImage != nullptr )
    idImage::Resize(this: depthImage, width, height, depth: 0);
}


// ========================================================================
// ?CreateFromImages@idRenderDestination@@QAAXPAVidImage@@00PAUD3DSurface@@1@Z
// EA  : 0x82942430
// RVA : 0x00942430
// PDB : w:\tech5\engine\renderer\renderdestination_d3d_360.cpp
// ========================================================================

void __fastcall idRenderDestination::CreateFromImages(
        idRenderDestination *this,
        idImage *color,
        idImage *depth,
        idImage *stencil,
        D3DSurface *colorSurf,
        D3DSurface *depthSurf)
{
  int height; // r10
  D3DSurface *v12; // r3
  _D3DSURFACE_DESC v13; // [sp+50h] [-50h] BYREF

  if ( color != nullptr )
  {
    this->targetWidth = color->opts.width;
    height = color->opts.height;
  }
  else if ( depth != nullptr )
  {
    this->targetWidth = depth->opts.width;
    height = depth->opts.height;
  }
  else
  {
    v12 = colorSurf;
    if ( colorSurf == nullptr )
      v12 = depthSurf;
    D3DSurface_GetDesc(pSurface: v12, pDesc: &v13);
    height = v13.Height;
    this->targetWidth = v13.Width;
  }
  this->targetHeight = height;
  this->targetImage[0] = color;
  this->targetImage[1] = nullptr;
  this->targetImage[2] = nullptr;
  this->targetImage[3] = nullptr;
  this->depthImage = depth;
  this->targetSurface[0] = colorSurf;
  this->targetSurface[1] = nullptr;
  this->targetSurface[2] = nullptr;
  this->targetSurface[3] = nullptr;
  this->depthSurface = depthSurf;
}

