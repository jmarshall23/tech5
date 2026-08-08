
// ========================================================================
// ?WriteTGA@idImageData@@QBAXPBD@Z
// EA  : 0x828C5368
// RVA : 0x008C5368
// PDB : w:\tech5\engine\renderer\imagedata.cpp
// ========================================================================

void __fastcall idImageData::WriteTGA(idImageData *this, const char *filename)
{
  R_WriteTGA(
    filename,
    data: this->data,
    width: this->width,
    height: this->height,
    depth: 4,
    flipVertical: false,
    swapRGB: true,
    basePath: FSPATH_BASE);
}

