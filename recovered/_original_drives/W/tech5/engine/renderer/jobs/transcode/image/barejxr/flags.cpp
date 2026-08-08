
// ========================================================================
// ?jxr_get_TILING_FLAG@@YAHPAUjxr_image@@@Z
// EA  : 0x82903C78
// RVA : 0x00903C78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\flags.cpp
// ========================================================================

int __fastcall jxr_get_TILING_FLAG(jxr_image *image)
{
  return image->header_flags1 >> 7;
}


// ========================================================================
// ?jxr_get_TILE_WIDTH@@YAHPAUjxr_image@@I@Z
// EA  : 0x82903C88
// RVA : 0x00903C88
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\flags.cpp
// ========================================================================

unsigned int __fastcall jxr_get_TILE_WIDTH(jxr_image *image, unsigned int column)
{
  unsigned int tile_columns; // r11

  tile_columns = image->tile_columns;
  if ( column > tile_columns )
    return 0;
  if ( column != tile_columns )
    return image->tile_column_width[column];
  if ( column != 0 )
    return (image->extended_width >> 4) - image->tile_column_position[column - 1];
  return image->extended_width >> 4;
}


// ========================================================================
// ?jxr_get_TILE_HEIGHT@@YAHPAUjxr_image@@I@Z
// EA  : 0x82903CE8
// RVA : 0x00903CE8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\flags.cpp
// ========================================================================

unsigned int __fastcall jxr_get_TILE_HEIGHT(jxr_image *image, unsigned int row)
{
  unsigned int tile_rows; // r11

  tile_rows = image->tile_rows;
  if ( row > tile_rows )
    return 0;
  if ( row != tile_rows )
    return image->tile_row_height[row];
  if ( row != 0 )
    return (image->extended_height >> 4) - image->tile_row_position[row - 1];
  return image->extended_height >> 4;
}

