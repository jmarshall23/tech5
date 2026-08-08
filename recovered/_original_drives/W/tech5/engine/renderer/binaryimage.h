
// ========================================================================
// ?Set@idBinaryImageData@idBinaryImage@@QAAXHHHHH@Z
// EA  : 0x828A5420
// RVA : 0x008A5420
// PDB : w:\tech5\engine\renderer\binaryimage.h
// ========================================================================

void __fastcall idBinaryImage::idBinaryImageData::Set(
        idBinaryImage::idBinaryImageData *this,
        int l,
        int z,
        int w,
        int h,
        int sz)
{
  idList<unsigned char,34> *p_data; // r30
  int size; // r11

  this->level = l;
  this->destZ = z;
  p_data = &this->data;
  this->width = w;
  this->height = h;
  this->dataSize = sz;
  if ( sz <= this->data.size
    || (unsigned __int8)idList<unsigned char,25>::Resize(this: (idList<unsigned char,37> *)&this->data, newsize: sz) != 0 )
  {
    size = p_data->size;
    if ( sz < size )
      size = sz;
    p_data->num = size;
  }
}


// ========================================================================
// ??0idBinaryImage@@QAA@PBD@Z
// EA  : 0x828A5B48
// RVA : 0x008A5B48
// PDB : w:\tech5\engine\renderer\binaryimage.h
// ========================================================================

idBinaryImage *__fastcall idBinaryImage::idBinaryImage(idBinaryImage *this, const char *name)
{
  idStr::idStr(this: &this->imgName, text: name);
  this->sourceFileTime = -1;
  this->binaryFileTime = -1;
  this->opts.format = FMT_NONE;
  this->opts.colorFormat = CFM_DEFAULT;
  this->opts.filter = TF_DEFAULT;
  this->opts.repeat = TR_REPEAT;
  this->opts.cubeFilter = false;
  this->opts.width = 0;
  this->opts.height = 0;
  this->opts.depth = 0;
  this->opts.numLevels = 0;
  this->opts.textureType = TT_2D;
  this->opts.border.x = 0.0;
  this->opts.border.y = 0.0;
  this->opts.border.z = 0.0;
  this->opts.border.w = 0.0;
  this->opts.packedTail = true;
  this->opts.lodBias = 0.0;
  this->opts.readback = false;
  this->opts.lodMinClamp = 0.0;
  this->opts.linear = false;
  this->opts.lodMaxClamp = 13.0;
  this->opts.forceBias = false;
  this->opts.aniso = 0.0;
  this->opts.depthCompareMode = false;
  this->opts.overlayMemory = false;
  this->opts.startPurged = false;
  this->images.granularity = 0;
  this->images.memTag = 34;
  this->images.listStatic = 0;
  this->images.list = nullptr;
  this->images.size = 0;
  this->images.num = 0;
  return this;
}


// ========================================================================
// __unwind$232361_0
// EA  : 0x828A5C3C
// RVA : 0x008A5C3C
// PDB : w:\tech5\engine\renderer\binaryimage.h
// ========================================================================

void _unwind_232361_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}

