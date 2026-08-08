
// ========================================================================
// error_exit
// EA  : 0x83213A38
// RVA : 0x01213A38
// PDB : w:\tech5\libs\jpeg\jerror.cpp
// ========================================================================

void __fastcall __noreturn error_exit(jpeg_common_struct *cinfo)
{
  cinfo->err->output_message(a1: cinfo);
  jpeg_destroy(cinfo);
  exit_86(code: 1);
}


// ========================================================================
// output_message
// EA  : 0x83213A70
// RVA : 0x01213A70
// PDB : w:\tech5\libs\jpeg\jerror.cpp
// ========================================================================

void __fastcall output_message(jpeg_common_struct *cinfo)
{
  _iobuf *v1; // r3
  char v2[200]; // [sp+50h] [-D0h] BYREF

  cinfo->err->format_message(a1: cinfo, a2: v2);
  v1 = _iob_func();
  fprintf(str: v1 + 2, format: "%s\n", v2);
}


// ========================================================================
// emit_message
// EA  : 0x83213AB8
// RVA : 0x01213AB8
// PDB : w:\tech5\libs\jpeg\jerror.cpp
// ========================================================================

void __fastcall emit_message(jpeg_common_struct *cinfo, int msg_level)
{
  jpeg_error_mgr *err; // r31

  err = cinfo->err;
  if ( msg_level >= 0 )
  {
    if ( err->trace_level >= msg_level )
      ((void (*)(void))err->output_message)();
  }
  else
  {
    if ( err->num_warnings == 0 || err->trace_level >= 3 )
      ((void (*)(void))err->output_message)();
    ++err->num_warnings;
  }
}


// ========================================================================
// format_message
// EA  : 0x83213B48
// RVA : 0x01213B48
// PDB : w:\tech5\libs\jpeg\jerror.cpp
// ========================================================================

void __fastcall format_message(jpeg_common_struct *cinfo, char *buffer)
{
  jpeg_error_mgr *err; // r11
  int msg_code; // r10
  const char *v5; // r4
  const char *const *addon_message_table; // r8
  int first_addon_message; // r9
  const char **jpeg_message_table; // r9
  char v9; // r8
  const char *v10; // r9
  int v11; // r10

  err = cinfo->err;
  msg_code = cinfo->err->msg_code;
  if ( msg_code > 0 && msg_code <= err->last_jpeg_message )
  {
    v5 = err->jpeg_message_table[msg_code];
    goto LABEL_8;
  }
  addon_message_table = err->addon_message_table;
  if ( addon_message_table != nullptr )
  {
    first_addon_message = err->first_addon_message;
    if ( msg_code >= first_addon_message && msg_code <= err->last_addon_message )
    {
      v5 = addon_message_table[msg_code - first_addon_message];
LABEL_8:
      if ( v5 != nullptr )
        goto LABEL_10;
    }
  }
  jpeg_message_table = (const char **)err->jpeg_message_table;
  err->msg_parm.i[0] = msg_code;
  v5 = *jpeg_message_table;
LABEL_10:
  v9 = 0;
  v10 = v5;
  v11 = *v5;
  if ( *v5 != 0 )
  {
    while ( 1 )
    {
      ++v10;
      if ( v11 == 37 )
        break;
      v11 = *v10;
      if ( *v10 == 0 )
        goto LABEL_16;
    }
    if ( *v10 == 115 )
      v9 = 1;
  }
LABEL_16:
  if ( v9 != 0 )
    sprintf_0(string: buffer, format: v5, &err->msg_parm);
  else
    sprintf_0(
      string: buffer,
      format: v5,
      err->msg_parm.i[0],
      err->msg_parm.i[1],
      err->msg_parm.i[2],
      err->msg_parm.i[3],
      err->msg_parm.i[4],
      err->msg_parm.i[5]);
}


// ========================================================================
// reset_error_mgr
// EA  : 0x83213C78
// RVA : 0x01213C78
// PDB : w:\tech5\libs\jpeg\jerror.cpp
// ========================================================================

void __fastcall reset_error_mgr(jpeg_common_struct *cinfo)
{
  cinfo->err->num_warnings = 0;
  cinfo->err->msg_code = 0;
}


// ========================================================================
// ?jpeg_std_error@@YAPAUjpeg_error_mgr@@PAU1@@Z
// EA  : 0x83213C90
// RVA : 0x01213C90
// PDB : w:\tech5\libs\jpeg\jerror.cpp
// ========================================================================

jpeg_error_mgr *__fastcall jpeg_std_error(jpeg_error_mgr *err)
{
  err->error_exit = (void (__fastcall *)(jpeg_common_struct *))error_exit;
  err->jpeg_message_table = jpeg_std_message_table;
  err->trace_level = 0;
  err->emit_message = emit_message;
  err->output_message = output_message;
  err->format_message = format_message;
  err->reset_error_mgr = reset_error_mgr;
  err->num_warnings = 0;
  err->msg_code = 0;
  err->last_jpeg_message = 123;
  err->addon_message_table = nullptr;
  err->first_addon_message = 0;
  err->last_addon_message = 0;
  return err;
}

