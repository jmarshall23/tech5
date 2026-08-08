
// ========================================================================
// ?AssertFailed@@YA_NPBDH0_N@Z
// EA  : 0x82F816A0
// RVA : 0x00F816A0
// PDB : w:\tech5\shared\idlib\sys\sys_assert.cpp
// ========================================================================

int __fastcall AssertFailed(const char *file, __int64 expression, bool inlineBreak, __int64 a4)
{
  int v5; // r27
  __int64 v7; // r10
  int v8; // r11
  int v9; // r29
  bool v10; // zf
  int num; // r11
  skippedAssertion_t *v12; // r11
  skippedAssertion_t *v14; // r11
  int v15; // [sp+8h] [-78h]
  int v16; // [sp+Ch] [-74h]
  int v17; // [sp+10h] [-70h]
  int v18; // [sp+14h] [-6Ch]

  v5 = HIDWORD(expression);
  LODWORD(v7) = skipAllAssertions;
  if ( skipAllAssertions )
    return 0;
  v8 = 0;
  skipThisAssertion = skipAllAssertions;
  HIDWORD(v7) = skippedAssertions.num;
  if ( skippedAssertions.num > 0 )
  {
    LODWORD(a4) = skippedAssertions.list;
    LODWORD(v7) = skippedAssertions.list;
    while ( 1 )
    {
      HIDWORD(a4) = *(_DWORD *)v7;
      if ( *(const char **)v7 == file )
      {
        HIDWORD(a4) = *(_DWORD *)(v7 + 4);
        if ( HIDWORD(a4) == HIDWORD(expression) )
          break;
      }
      ++v8;
      LODWORD(v7) = v7 + 8;
      if ( v8 >= skippedAssertions.num )
        goto LABEL_7;
    }
    skipThisAssertion = true;
    return 0;
  }
LABEL_7:
  idLib::Warning(
    fmt: __SPAIR64__("ASSERTION FAILED! %s(%d): '%s'", (unsigned int)file),
    a2: expression,
    a3: a4,
    a4: v7,
    a5: v15,
    a6: v16,
    a7: v17,
    a8: v18);
  v10 = inlineBreak;
  v9 = 1;
  if ( !v10 )
  {
    __trap();
    v9 = 0;
  }
  if ( skipThisAssertion || com_assertOnce.valueInteger != 0 )
  {
    idList<skippedAssertion_t,5>::PreAllocateWithGranularity(
      this: &skippedAssertions,
      newSize: skippedAssertions.num + 1);
    num = skippedAssertions.num;
    if ( skippedAssertions.num < skippedAssertions.size )
    {
      ++skippedAssertions.num;
      v12 = &skippedAssertions.list[num];
      v12->file = file;
      v12->line = v5;
      return v9;
    }
    v14 = &skippedAssertions.list[skippedAssertions.size - 1];
    v14->file = file;
    v14->line = v5;
  }
  return v9;
}


// ========================================================================
// `dynamic initializer for 'com_assertOnce''
// EA  : 0x83396B68
// RVA : 0x01396B68
// PDB : w:\tech5\shared\idlib\sys\sys_assert.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_assertOnce__()
{
  idCVar::idCVar(
    this: &com_assertOnce,
    name: "com_assertOnce",
    value: "0",
    flags: 1,
    description: "Only assert once per assert instance (file/line combination)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_assertOnce__);
}


// ========================================================================
// `dynamic initializer for 'skippedAssertions''
// EA  : 0x83396BC0
// RVA : 0x01396BC0
// PDB : w:\tech5\shared\idlib\sys\sys_assert.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__skippedAssertions__()
{
  int v0; // ctr
  __int16 *p_granularity; // r11

  v0 = 20;
  p_granularity = &skippedAssertions.granularity;
  do
  {
    *((_DWORD *)p_granularity + 1) = 0;
    p_granularity += 4;
    *(_DWORD *)p_granularity = -1;
    --v0;
  }
  while ( v0 != 0 );
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__skippedAssertions__);
}

