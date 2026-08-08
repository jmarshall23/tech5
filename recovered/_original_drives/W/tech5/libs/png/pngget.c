
// ========================================================================
// png_get_IHDR
// EA  : 0x8321B6E8
// RVA : 0x0121B6E8
// PDB : w:\tech5\libs\png\pngget.c
// ========================================================================

unsigned int __fastcall png_get_IHDR(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        unsigned int *width,
        unsigned int *height,
        int *bit_depth,
        int *color_type,
        int *interlace_type,
        int *compression_type,
        int *filter_type,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        _DWORD *a28)
{
  if ( png_ptr == nullptr
    || info_ptr == nullptr
    || width == nullptr
    || height == nullptr
    || bit_depth == nullptr
    || color_type == nullptr )
  {
    return 0;
  }
  *width = info_ptr->width;
  *height = info_ptr->height;
  *bit_depth = info_ptr->bit_depth;
  if ( info_ptr->bit_depth == 0 || info_ptr->bit_depth > 0x10u )
    png_error(png_ptr, error_message: "Invalid bit depth");
  *color_type = info_ptr->color_type;
  if ( info_ptr->color_type > 6u )
    png_error(png_ptr, error_message: "Invalid color type");
  if ( compression_type != nullptr )
    *compression_type = info_ptr->compression_type;
  if ( a28 != nullptr )
    *a28 = info_ptr->filter_type;
  if ( interlace_type != nullptr )
    *interlace_type = info_ptr->interlace_type;
  if ( (int)*width <= 0 )
    png_error(png_ptr, error_message: "Invalid image width");
  if ( (int)*height <= 0 )
    png_error(png_ptr, error_message: "Invalid image height");
  if ( info_ptr->width > 0x1FFFFF7E )
    png_warning(png_ptr, warning_message: "Width too large for libpng to process image data.");
  return 1;
}

