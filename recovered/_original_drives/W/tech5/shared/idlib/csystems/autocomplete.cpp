
// ========================================================================
// ?Append@idAutoComplete@@QAAXABVidStr@@H@Z
// EA  : 0x82EFBD60
// RVA : 0x00EFBD60
// PDB : w:\tech5\shared\idlib\csystems\autocomplete.cpp
// ========================================================================

void __fastcall idAutoComplete::Append(idAutoComplete *this, const idStr *suggestion, int completingArg)
{
  int v5; // r28
  idCmdArgs *p_args; // r23
  char *v7; // r4
  int v8; // r5
  int v9; // r30
  int v10; // r29
  char *v11; // r4
  int v12; // r10
  int v13; // r11
  int argc; // [sp+50h] [-A0h]
  idStr v15[4]; // [sp+60h] [-90h] BYREF

  v5 = completingArg;
  if ( completingArg < 0 )
    v5 = this->args.argc - 1;
  p_args = &this->args;
  argc = this->args.argc;
  if ( v5 >= argc )
    goto LABEL_13;
  v7 = v5 < 0 || v5 >= argc ? &byte_8200D768 : p_args->argv[v5];
  if ( *v7 == 0 )
    goto LABEL_13;
  v8 = 0;
  do
    ++v8;
  while ( v7[v8] != 0 );
  if ( idStr::Icmpn(s1: suggestion->data, s2: v7, n: v8) == 0 )
  {
LABEL_13:
    if ( p_args->argc != 1 || v5 != 0 )
    {
      v15[0].len = 0;
      v15[0].baseBuffer[0] = 0;
      v15[0].allocedAndFlag = 20;
      v15[0].data = v15[0].baseBuffer;
      v9 = 0;
      if ( v5 > 0 )
      {
        v10 = 0;
        do
        {
          if ( v9 < 0 || v9 >= p_args->argc )
            v11 = &byte_8200D768;
          else
            v11 = p_args->argv[v10];
          idStr::Append(this: v15, text: v11);
          v13 = v15[0].len + 2;
          v12 = v15[0].allocedAndFlag & 0x7FFFFFFF;
          if ( v15[0].allocedAndFlag >= 0 )
          {
            if ( v13 > v12 )
              idStr::ReAllocate(this: v15, amount: (v13 >> 1) + v13, keepold: true);
          }
          else if ( v13 > v12
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          ++v9;
          ++v10;
          v15[0].data[v15[0].len] = 32;
          v15[0].data[++v15[0].len] = 0;
        }
        while ( v9 < v5 );
      }
      idStr::Append(this: v15, text: suggestion);
      idList<idStr,5>::Append(this: &this->suggestions, obj: v15);
      idStr::FreeData(this: v15);
    }
    else
    {
      idList<idStr,5>::Append(this: &this->suggestions, obj: suggestion);
    }
  }
}


// ========================================================================
// __unwind$111306
// EA  : 0x82EFBF4C
// RVA : 0x00EFBF4C
// PDB : w:\tech5\shared\idlib\csystems\autocomplete.cpp
// ========================================================================

void _unwind_111306()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}

