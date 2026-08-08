
// ========================================================================
// rdsys_stack_traceback
// EA  : 0x83233C80
// RVA : 0x01233C80
// PDB : w:\tech5\libs\mgrd\src\rdsys.c
// ========================================================================

unsigned int __fastcall rdsys_stack_traceback(void **buffer, ULONG max)
{
  unsigned int result; // r3
  bool v5; // zf
  void **i; // r11

  v5 = DmCaptureStackBackTrace(FramesToCapture: max, BackTrace: buffer) != 47841280;
  result = 0;
  if ( !v5 )
  {
    if ( max != 0 )
    {
      for ( i = buffer; *i != nullptr; ++i )
      {
        if ( ++result >= max )
          return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}


// ========================================================================
// rdsys_exeimage
// EA  : 0x83233D00
// RVA : 0x01233D00
// PDB : w:\tech5\libs\mgrd\src\rdsys.c
// ========================================================================

char *rdsys_exeimage()
{
  char *result; // r3
  _DM_XBE v1; // [sp+50h] [-130h] BYREF

  result = buffer_0;
  if ( inited_0 == 0 )
  {
    DmGetXbeInfo(szName: buffer_0, a2: &v1);
    strncpy(dest: buffer_0, source: v1.LaunchPath, count: 0x100u);
    inited_0 = 1;
    return buffer_0;
  }
  return result;
}

