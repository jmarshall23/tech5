
// ========================================================================
// ??0idImageOpts@@QAA@XZ
// EA  : 0x82771D60
// RVA : 0x00771D60
// PDB : w:\tech5\engine\renderer\image.h
// ========================================================================

idImageOpts *__fastcall idImageOpts::idImageOpts(idImageOpts *this)
{
  this->format = FMT_NONE;
  this->colorFormat = CFM_DEFAULT;
  this->filter = TF_DEFAULT;
  this->repeat = TR_REPEAT;
  this->cubeFilter = false;
  this->width = 0;
  this->height = 0;
  this->depth = 0;
  this->numLevels = 0;
  this->textureType = TT_2D;
  this->border.x = 0.0;
  this->border.y = 0.0;
  this->border.z = 0.0;
  this->border.w = 0.0;
  this->packedTail = true;
  this->lodBias = 0.0;
  this->readback = false;
  this->lodMinClamp = 0.0;
  this->linear = false;
  this->lodMaxClamp = 13.0;
  this->forceBias = false;
  this->aniso = 0.0;
  this->depthCompareMode = false;
  this->overlayMemory = false;
  this->startPurged = false;
  return this;
}


// ========================================================================
// ?GetResourceList@idImage@@UBAPAVidResourceList@@XZ
// EA  : 0x828C2E68
// RVA : 0x008C2E68
// PDB : w:\tech5\engine\renderer\image.h
// ========================================================================

idTypedResourceList<idImage> *__fastcall idImage::GetResourceList(idImage *this)
{
  return &idImage::resourceList;
}


// ========================================================================
// ?EnableDepthCompareMode@idImage@@QAA_N_N@Z
// EA  : 0x82967D18
// RVA : 0x00967D18
// PDB : w:\tech5\engine\renderer\image.h
// ========================================================================

BOOL __fastcall idImage::EnableDepthCompareMode(idImage *this, bool enable)
{
  BOOL depthCompareMode; // r30
  int v4; // r10
  int v5; // r9
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r5
  int v10; // r4
  int v12; // [sp+8h] [-68h]

  depthCompareMode = this->opts.depthCompareMode;
  if ( enable != depthCompareMode )
  {
    this->opts.depthCompareMode = enable;
    idImageOpts::operator=(this: &this->opts, __that: &this->opts);
    idImage::DetermineSamplerStateFromOpts(this, a2: v10, a3: v9, a4: v8, a5: v7, a6: v6, a7: v5, a8: v4, a9: v12);
    GL_ResetTextureState();
  }
  return depthCompareMode;
}

