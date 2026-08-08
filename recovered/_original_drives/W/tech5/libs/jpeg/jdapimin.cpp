
// ========================================================================
// ?jpeg_CreateDecompress@@YAXPAUjpeg_decompress_struct@@HI@Z
// EA  : 0x83210E30
// RVA : 0x01210E30
// PDB : w:\tech5\libs\jpeg\jdapimin.cpp
// ========================================================================

void __fastcall jpeg_CreateDecompress(jpeg_common_struct *cinfo, int version, int structsize)
{
  jpeg_error_mgr *err; // r29
  void *client_data; // r28
  JQUANT_TBL **p_mem; // r11
  int v8; // ctr

  cinfo->mem = nullptr;
  if ( version != 62 )
  {
    cinfo->err->msg_code = 12;
    cinfo->err->msg_parm.i[0] = 62;
    cinfo->err->msg_parm.i[1] = version;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( structsize != 432 )
  {
    cinfo->err->msg_code = 21;
    cinfo->err->msg_parm.i[0] = 432;
    cinfo->err->msg_parm.i[1] = structsize;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = cinfo->err;
  client_data = cinfo->client_data;
  memset(Dst: cinfo, Val: 0, Size: 0x1B0u);
  cinfo->err = err;
  cinfo->client_data = client_data;
  cinfo->is_decompressor = 1;
  jinit_memory_mgr(cinfo);
  cinfo->progress = nullptr;
  cinfo[1].err = nullptr;
  p_mem = (JQUANT_TBL **)&cinfo[7].mem;
  cinfo[6].err = nullptr;
  cinfo[6].mem = nullptr;
  cinfo[6].progress = nullptr;
  v8 = 4;
  cinfo[6].client_data = nullptr;
  do
  {
    *(p_mem - 3) = nullptr;
    *++p_mem = nullptr;
    --v8;
  }
  while ( v8 != 0 );
  cinfo[11].mem = nullptr;
  jinit_marker_reader((jpeg_decompress_struct *)cinfo);
  jinit_input_controller((jpeg_decompress_struct *)cinfo);
  cinfo->global_state = 200;
}


// ========================================================================
// ?jpeg_destroy_decompress@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x83210F48
// RVA : 0x01210F48
// PDB : w:\tech5\libs\jpeg\jdapimin.cpp
// ========================================================================

// attributes: thunk
void __fastcall jpeg_destroy_decompress(jpeg_common_struct *cinfo)
{
  jpeg_destroy(cinfo);
}


// ========================================================================
// ?jpeg_abort_decompress@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x83210F50
// RVA : 0x01210F50
// PDB : w:\tech5\libs\jpeg\jdapimin.cpp
// ========================================================================

// attributes: thunk
void __fastcall jpeg_abort_decompress(jpeg_common_struct *cinfo)
{
  jpeg_abort(cinfo);
}


// ========================================================================
// default_decompress_parms
// EA  : 0x83210F58
// RVA : 0x01210F58
// PDB : w:\tech5\libs\jpeg\jdapimin.cpp
// ========================================================================

void __fastcall default_decompress_parms(jpeg_common_struct *cinfo)
{
  int client_data; // r11
  JHUFF_TBL *mem; // r11
  int v4; // r10
  int v5; // r9
  int v6; // r8
  jpeg_error_mgr *err; // r11

  client_data = (int)cinfo[1].client_data;
  switch ( client_data )
  {
    case 1:
      *(_DWORD *)&cinfo[1].is_decompressor = 1;
      cinfo[1].global_state = 1;
      break;
    case 3:
      if ( cinfo[10].is_decompressor != 0 )
        goto LABEL_19;
      if ( HIBYTE(cinfo[11].err) != 0 )
      {
        if ( BYTE1(cinfo[11].err) != 0 )
        {
          if ( BYTE1(cinfo[11].err) != 1 )
          {
            cinfo->err->msg_code = 114;
            cinfo->err->msg_parm.i[0] = BYTE1(cinfo[11].err);
            cinfo->err->emit_message(a1: cinfo, a2: -1);
            cinfo[1].global_state = 2;
            *(_DWORD *)&cinfo[1].is_decompressor = 3;
            break;
          }
LABEL_19:
          cinfo[1].global_state = 2;
          *(_DWORD *)&cinfo[1].is_decompressor = 3;
          break;
        }
LABEL_23:
        *(_DWORD *)&cinfo[1].is_decompressor = 2;
        cinfo[1].global_state = 2;
        break;
      }
      mem = (JHUFF_TBL *)cinfo[8].mem;
      v4 = *(_DWORD *)mem->bits;
      v5 = *(_DWORD *)&mem->huffval[67];
      v6 = *(_DWORD *)&mem->huffval[151];
      if ( *(_DWORD *)mem->bits == 1 )
      {
        if ( v5 == 2 && v6 == 3 )
          goto LABEL_19;
      }
      else if ( v4 == 82 && v5 == 71 && v6 == 66 )
      {
        goto LABEL_23;
      }
      err = cinfo->err;
      err->msg_parm.i[1] = v5;
      err->msg_parm.i[0] = v4;
      err->msg_parm.i[2] = v6;
      cinfo->err->msg_code = 111;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      cinfo[1].global_state = 2;
      *(_DWORD *)&cinfo[1].is_decompressor = 3;
      break;
    case 4:
      if ( HIBYTE(cinfo[11].err) != 0 && BYTE1(cinfo[11].err) != 0 )
      {
        if ( BYTE1(cinfo[11].err) == 2 )
        {
          cinfo[1].global_state = 4;
          *(_DWORD *)&cinfo[1].is_decompressor = 5;
        }
        else
        {
          cinfo->err->msg_code = 114;
          cinfo->err->msg_parm.i[0] = BYTE1(cinfo[11].err);
          cinfo->err->emit_message(a1: cinfo, a2: -1);
          cinfo[1].global_state = 4;
          *(_DWORD *)&cinfo[1].is_decompressor = 5;
        }
      }
      else
      {
        *(_DWORD *)&cinfo[1].is_decompressor = 4;
        cinfo[1].global_state = 4;
      }
      break;
    default:
      *(_DWORD *)&cinfo[1].is_decompressor = 0;
      cinfo[1].global_state = 0;
      break;
  }
  cinfo[2].err = (jpeg_error_mgr *)1;
  cinfo[2].mem = (jpeg_memory_mgr *)1;
  cinfo[2].is_decompressor = 0;
  *(&cinfo[2].is_decompressor + 1) = 0;
  cinfo[2].global_state = 0;
  HIBYTE(cinfo[3].err) = 1;
  *(_QWORD *)&cinfo[2].progress = 0x3FF0000000000000LL;
  BYTE1(cinfo[3].err) = 1;
  BYTE2(cinfo[3].err) = 0;
  cinfo[3].mem = (jpeg_memory_mgr *)2;
  HIBYTE(cinfo[3].progress) = 1;
  cinfo[3].client_data = (void *)256;
  cinfo[4].global_state = 0;
  cinfo[3].is_decompressor = 0;
  *(&cinfo[3].is_decompressor + 1) = 0;
  *(&cinfo[3].is_decompressor + 2) = 0;
}


// ========================================================================
// ?jpeg_consume_input@@YAHPAUjpeg_decompress_struct@@@Z
// EA  : 0x83211180
// RVA : 0x01211180
// PDB : w:\tech5\libs\jpeg\jdapimin.cpp
// ========================================================================

int __fastcall jpeg_consume_input(jpeg_decompress_struct *cinfo)
{
  int v2; // r30

  v2 = 0;
  switch ( cinfo->global_state )
  {
    case 0xC8:
      cinfo->master->finish_output_pass(a1: cinfo);
      cinfo->src->init_source(a1: cinfo);
      cinfo->global_state = 201;
      goto LABEL_3;
    case 0xC9:
LABEL_3:
      v2 = ((int (__fastcall *)(jpeg_decompress_struct *))cinfo->master->prepare_for_output_pass)(a1: cinfo);
      if ( v2 == 1 )
      {
        default_decompress_parms((jpeg_common_struct *)cinfo);
        cinfo->global_state = 202;
      }
      return v2;
    case 0xCA:
      return 1;
    case 0xCB:
    case 0xCC:
    case 0xCD:
    case 0xCE:
    case 0xCF:
    case 0xD0:
    case 0xD2:
      return ((int (__fastcall *)(jpeg_decompress_struct *))cinfo->master->prepare_for_output_pass)(a1: cinfo);
    default:
      cinfo->err->msg_code = 20;
      cinfo->err->msg_parm.i[0] = cinfo->global_state;
      cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
      return v2;
  }
}


// ========================================================================
// ?jpeg_finish_decompress@@YAEPAUjpeg_decompress_struct@@@Z
// EA  : 0x832112C0
// RVA : 0x012112C0
// PDB : w:\tech5\libs\jpeg\jdapimin.cpp
// ========================================================================

int __fastcall jpeg_finish_decompress(jpeg_common_struct *cinfo)
{
  int global_state; // r11

  global_state = cinfo->global_state;
  if ( (global_state == 205 || global_state == 206) && cinfo[2].is_decompressor == 0 )
  {
    if ( cinfo[5].err < cinfo[4].err )
    {
      cinfo->err->msg_code = 67;
      cinfo->err->error_exit(a1: cinfo);
    }
    ((void (__fastcall *)(jpeg_common_struct *))cinfo[16].err->emit_message)(a1: cinfo);
    cinfo->global_state = 210;
  }
  else if ( global_state == 207 )
  {
    cinfo->global_state = 210;
  }
  else if ( global_state != 210 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 17) != 0 )
  {
LABEL_14:
    ((void (__fastcall *)(jpeg_common_struct *))cinfo[1].err->msg_parm.i[0])(a1: cinfo);
    jpeg_abort(cinfo);
    return 1;
  }
  else
  {
    while ( (**(int (__fastcall ***)(jpeg_common_struct *))&cinfo[16].is_decompressor)(a1: cinfo) != 0 )
    {
      if ( *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 17) != 0 )
        goto LABEL_14;
    }
    return 0;
  }
}


// ========================================================================
// ?jpeg_read_header@@YAHPAUjpeg_decompress_struct@@E@Z
// EA  : 0x83211418
// RVA : 0x01211418
// PDB : w:\tech5\libs\jpeg\jdapimin.cpp
// ========================================================================

int __fastcall jpeg_read_header(jpeg_common_struct *cinfo, unsigned __int8 require_image)
{
  int global_state; // r11
  int result; // r3

  global_state = cinfo->global_state;
  if ( global_state != 200 && global_state != 201 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = jpeg_consume_input((jpeg_decompress_struct *)cinfo);
  if ( result == 1 )
    return 1;
  if ( result == 2 )
  {
    if ( require_image != 0 )
    {
      cinfo->err->msg_code = 51;
      cinfo->err->error_exit(a1: cinfo);
    }
    jpeg_abort(cinfo);
    return 2;
  }
  return result;
}

