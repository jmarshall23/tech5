
// ========================================================================
// start_pass
// EA  : 0x832374F8
// RVA : 0x012374F8
// PDB : w:\tech5\libs\jpeg\jddctmgr.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall start_pass(jpeg_common_struct *cinfo, __int64 a2, __int64 a3)
{
  int v3; // r2 OVERLAPPED
  int v5; // r29
  void (__fastcall *v6)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // r27
  int v7; // r24
  unsigned __int8 *p_free_pool; // r30
  int *p_max_memory_to_use; // r25
  unsigned int global_state; // r11
  int v11; // r11
  double *v12; // r10
  float *v13; // r9
  unsigned __int16 *v14; // r11
  int i; // ctr
  int v16; // r3
  int v17; // r8
  __int16 *v18; // r9
  int *v19; // r10
  int v20; // ctr
  unsigned __int16 *v21; // r11
  int v22; // r3
  unsigned __int16 *v23; // r11
  _DWORD *v24; // r10
  int j; // ctr

  v5 = 0;
  v6 = nullptr;
  v7 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_free_pool = (unsigned __int8 *)&cinfo[8].mem->free_pool;
    p_max_memory_to_use = &cinfo[17].mem->max_memory_to_use;
    do
    {
      if ( (unsigned int)(*(_DWORD *)p_free_pool - 1) <= 7 )
      {
        if ( *(_DWORD *)p_free_pool == 2 )
        {
          v5 = 0;
          v6 = jpeg_idct_2x2;
          goto LABEL_22;
        }
        if ( *(_DWORD *)p_free_pool != 3 )
        {
          if ( *(_DWORD *)p_free_pool == 4 )
          {
            v5 = 0;
            v6 = jpeg_idct_4x4;
            goto LABEL_22;
          }
          if ( *(_DWORD *)p_free_pool != 5 && *(_DWORD *)p_free_pool != 6 && *(_DWORD *)p_free_pool != 7 )
          {
            if ( *(_DWORD *)p_free_pool == 1 )
            {
              v5 = 0;
              v6 = jpeg_idct_1x1;
            }
            else
            {
              global_state = cinfo[2].global_state;
              if ( global_state != 0 )
              {
                if ( global_state == 1 )
                {
                  v5 = 1;
                  v6 = jpeg_idct_ifast;
                }
                else if ( global_state < 3 )
                {
                  v5 = 2;
                  v6 = jpeg_idct_float;
                }
                else
                {
                  cinfo->err->msg_code = 48;
                  cinfo->err->error_exit(a1: cinfo);
                }
              }
              else
              {
                v5 = 0;
                v6 = jpeg_idct_islow;
              }
            }
            goto LABEL_22;
          }
        }
      }
      cinfo->err->msg_code = 7;
      cinfo->err->msg_parm.i[0] = *(_DWORD *)p_free_pool;
      cinfo->err->error_exit(a1: cinfo);
LABEL_22:
      *(p_max_memory_to_use - 10) = (int)v6;
      if ( p_free_pool[12] != 0 && *p_max_memory_to_use != v5 )
      {
        v11 = *((_DWORD *)p_free_pool + 10);
        if ( v11 != 0 )
        {
          *p_max_memory_to_use = v5;
          if ( v5 != 0 )
          {
            if ( v5 == 1 )
            {
              v18 = (__int16 *)&aanscalefactor[3] + 5;
              v19 = (int *)(*((_DWORD *)p_free_pool + 11) - 4);
              v20 = 16;
              LODWORD(a3) = (char *)aanscales - v11;
              HIDWORD(a3) = (char *)&aanscales[1] - v11;
              v21 = (unsigned __int16 *)(v11 + 4);
              do
              {
                v19[1] = (*(v21 - 2) * v18[3] + 2048) >> 12;
                v18 += 4;
                v19[2] = (*(v21 - 1) * *v18 + 2048) >> 12;
                v19[3] = (*(__int16 *)((char *)v21 + a3) * *v21 + 2048) >> 12;
                HIDWORD(a2) = *(__int16 *)((char *)v21 + HIDWORD(a3));
                v22 = HIDWORD(a2) * v21[1] + 2048;
                v21 += 4;
                v19 += 4;
                *v19 = v22 >> 12;
                --v20;
              }
              while ( v20 != 0 );
            }
            else
            {
              v12 = (double *)&extend_offset_0[14];
              v13 = (float *)(*((_DWORD *)p_free_pool + 11) - 4);
              v14 = (unsigned __int16 *)(v11 - 2);
              for ( i = 8; i != 0; --i )
              {
                LODWORD(a3) = v14[1];
                v13[1] = (double)a3 * v12[1];
                LODWORD(a2) = v14[2];
                v13[2] = (double)a2 * v12[1] * 1.387039845;
                v16 = v14[3];
                v13[3] = (double)*(__int64 *)(&v3 - 1) * v12[1] * 1.306562965;
                LODWORD(a3) = v14[4];
                v13[4] = (double)a3 * v12[1] * 1.175875602;
                LODWORD(a2) = v14[5];
                v13[5] = (double)a2 * v12[1] * 1.0;
                HIDWORD(a2) = v14[6];
                v13[6] = (double)*(__int64 *)((char *)&a2 + 4) * v12[1] * 0.785694958;
                LODWORD(a3) = v14[7];
                v13[7] = (double)a3 * v12[1] * 0.5411961;
                ++v12;
                v14 += 8;
                v17 = *v14;
                HIDWORD(a3) = v17;
                v13 += 8;
                *v13 = (double)*(__int64 *)((char *)&a3 - 4) * *v12 * 0.275899379;
              }
            }
          }
          else
          {
            v23 = (unsigned __int16 *)(v11 - 2);
            v24 = (_DWORD *)(*((_DWORD *)p_free_pool + 11) - 4);
            for ( j = 64; j != 0; --j )
              *++v24 = *++v23;
          }
        }
      }
      ++v7;
      ++p_max_memory_to_use;
      p_free_pool += 84;
    }
    while ( v7 < (int)cinfo[1].client_data );
  }
}


// ========================================================================
// ?jinit_inverse_dct@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x832378D8
// RVA : 0x012378D8
// PDB : w:\tech5\libs\jpeg\jddctmgr.cpp
// ========================================================================

void __fastcall jinit_inverse_dct(jpeg_common_struct *cinfo)
{
  jpeg_d_post_controller *v2; // r3
  int v3; // r30
  int *p_max_alloc_chunk; // r29
  jpeg_d_post_controller *v5; // r28
  void *v6; // r3

  v2 = (jpeg_d_post_controller *)((int (*)(void))cinfo->mem->alloc_small)();
  cinfo[17].mem = (jpeg_memory_mgr *)v2;
  v3 = 0;
  v2->start_pass = (void (__fastcall *)(jpeg_decompress_struct *, J_BUF_MODE))start_pass;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_max_alloc_chunk = &cinfo[8].mem[-1].max_alloc_chunk;
    v5 = v2 + 5;
    do
    {
      v6 = (void *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 256);
      p_max_alloc_chunk += 21;
      *p_max_alloc_chunk = (int)v6;
      memset(Dst: v6, Val: 0, Size: 0x100u);
      v5 = (jpeg_d_post_controller *)((char *)v5 + 4);
      v5->start_pass = (void (__fastcall *)(jpeg_decompress_struct *, J_BUF_MODE))-1;
      ++v3;
    }
    while ( v3 < (int)cinfo[1].client_data );
  }
}

