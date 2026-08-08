
// ========================================================================
// ?_jxr_clear_strip_cur@@YAXPAUjxr_image@@@Z
// EA  : 0x82922520
// RVA : 0x00922520
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\x_strip.cpp
// ========================================================================

void __fastcall _jxr_clear_strip_cur(jxr_image *image)
{
  int v1; // r4
  macroblock_s **p_cur; // r8
  unsigned int v3; // r5
  int v4; // r10
  int v5; // r11
  int i; // ctr

  v1 = 0;
  if ( image->num_channels != 0 )
  {
    p_cur = &image->strip[0].cur;
    do
    {
      v3 = 0;
      if ( (image->extended_width & 0xFFFFFFF0) != 0 )
      {
        v4 = 0;
        do
        {
          v5 = 0;
          for ( i = 64; i != 0; --i )
          {
            (*p_cur)[v4].data[v5] = 0;
            (*p_cur)[v4].data[v5 + 1] = 0;
            (*p_cur)[v4].data[v5 + 2] = 0;
            (*p_cur)[v4].data[v5 + 3] = 0;
            v5 += 4;
          }
          ++v3;
          ++v4;
        }
        while ( v3 < image->extended_width >> 4 );
      }
      ++v1;
      p_cur += 7;
    }
    while ( v1 < image->num_channels );
  }
}

