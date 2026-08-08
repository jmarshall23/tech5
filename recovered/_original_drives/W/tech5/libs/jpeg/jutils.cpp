
// ========================================================================
// ?jdiv_round_up@@YAJJJ@Z
// EA  : 0x83227B70
// RVA : 0x01227B70
// PDB : w:\tech5\libs\jpeg\jutils.cpp
// ========================================================================

int __fastcall jdiv_round_up(int a, int b)
{
  int v2; // r10

  __twllei(b, 0);
  v2 = a + b - 1;
  __twlgei(b & ~(__ROL4__(v2, 1) - 1), 0xFFFFFFFF);
  return v2 / b;
}


// ========================================================================
// ?jround_up@@YAJJJ@Z
// EA  : 0x83227B98
// RVA : 0x01227B98
// PDB : w:\tech5\libs\jpeg\jutils.cpp
// ========================================================================

int __fastcall jround_up(int a, int b)
{
  int v2; // r11

  __twllei(b, 0);
  v2 = a + b - 1;
  __twlgei(b & ~(__ROL4__(v2, 1) - 1), 0xFFFFFFFF);
  return v2 - v2 % b;
}


// ========================================================================
// ?jcopy_sample_rows@@YAXPAPAEH0HHI@Z
// EA  : 0x83227BC8
// RVA : 0x01227BC8
// PDB : w:\tech5\libs\jpeg\jutils.cpp
// ========================================================================

void __fastcall jcopy_sample_rows(
        unsigned __int8 **input_array,
        int source_row,
        unsigned __int8 **output_array,
        int dest_row,
        int num_rows,
        size_t num_cols)
{
  int v7; // r31
  const void **v8; // r30
  void **v9; // r29

  v7 = num_rows;
  if ( num_rows > 0 )
  {
    v8 = (const void **)&input_array[source_row - 1];
    v9 = (void **)&output_array[dest_row - 1];
    do
    {
      memcpy(Dst: *++v9, Src: *++v8, Size: num_cols);
      --v7;
    }
    while ( v7 > 0 );
  }
}


// ========================================================================
// ?jcopy_block_row@@YAXPAY0EA@F0I@Z
// EA  : 0x83227C20
// RVA : 0x01227C20
// PDB : w:\tech5\libs\jpeg\jutils.cpp
// ========================================================================

void __fastcall jcopy_block_row(__int16 (*input_row)[64], __int16 (*output_row)[64], unsigned int num_blocks)
{
  memcpy(Dst: output_row, Src: input_row, Size: num_blocks << 7);
}


// ========================================================================
// ?jzero_far@@YAXPAXI@Z
// EA  : 0x83227C38
// RVA : 0x01227C38
// PDB : w:\tech5\libs\jpeg\jutils.cpp
// ========================================================================

void __fastcall jzero_far(void *target, size_t bytestozero)
{
  memset(Dst: target, Val: 0, Size: bytestozero);
}

