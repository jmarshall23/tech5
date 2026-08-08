
// ========================================================================
// ?GetItemUnlock@idMatchResults@@QBAABVidDeclVehicleUnlock@@H@Z
// EA  : 0x82DD51A8
// RVA : 0x00DD51A8
// PDB : w:\tech5\tungsten\game\matchresults.cpp
// ========================================================================

const idDeclVehicleUnlock *__fastcall idMatchResults::GetItemUnlock(
        idMatchResults *this,
        int i,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12)
{
  return idDeclVehicleUnlock::GetUnlockByOrdinal(
           ordinal: this->itemsUnlocked.list[i],
           a2: i,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8: (int)this->itemsUnlocked.list,
           a9,
           a10,
           a11,
           a12);
}


// ========================================================================
// FormatTime
// EA  : 0x82DD51B8
// RVA : 0x00DD51B8
// PDB : w:\tech5\tungsten\game\matchresults.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idStr *__fastcall FormatTime(__int64 result, __int64 time)
{
  idStr *v2; // r31
  __int64 v3; // r11 OVERLAPPED
  __int64 v4; // r8 OVERLAPPED
  __int64 v5; // r6
  int v6; // r9
  va *v7; // r3
  int v9; // [sp+8h] [-1058h]
  int v10; // [sp+Ch] [-1054h]
  int v11; // [sp+10h] [-1050h]
  int v12; // [sp+14h] [-104Ch]
  int v13; // [sp+18h] [-1048h]
  int v14; // [sp+1Ch] [-1044h]
  va v15; // [sp+50h] [-1010h] BYREF

  v2 = (idStr *)HIDWORD(result);
  LODWORD(v3) = 60000;
  HIDWORD(v3) = result;
  LODWORD(v4) = 1000;
  HIDWORD(result) = result / v3;
  HIDWORD(v5) = &unk_82340000;
  LODWORD(v5) = result - 60000 * HIDWORD(result);
  HIDWORD(v4) = result;
  *(__int64 *)((char *)&v3 + 4) = v5 / v4;
  LODWORD(v5) = v5 / v4;
  HIDWORD(v5) = HIDWORD(result);
  v6 = 60 * HIDWORD(result) + v5;
  LODWORD(v4) = 1000 * v6;
  HIDWORD(v4) = result - 1000 * v6;
  v7 = va::va(
         this: &v15,
         fmt: "%02d:%02d.%03d",
         a3: v5,
         a4: v4,
         a5: *(__int64 *)((char *)&v3 + 4),
         a6: v9,
         a7: v10,
         a8: v11,
         a9: v12,
         a10: v13,
         a11: v14);
  idStr::idStr(this: v2, text: v7);
  return v2;
}


// ========================================================================
// ?GetAccolade@idMatchResults@@QBA?AVidAccolade@@H@Z
// EA  : 0x82DD5248
// RVA : 0x00DD5248
// PDB : w:\tech5\tungsten\game\matchresults.cpp
// ========================================================================

idMatchResults *__fastcall idMatchResults::GetAccolade(idMatchResults *this, idAccolade *result, int i)
{
  idAccolade::idAccolade(
    (idAccolade *)this,
    decl_: idDeclAccolade::orderedList.list[*(_DWORD *)(result[5].count + 8 * i)],
    count_: *(_DWORD *)(result[5].count + 8 * i + 4));
  return this;
}


// ========================================================================
// ?ClearItemsUnlocked@idMatchResults@@QAAXXZ
// EA  : 0x82DD52A8
// RVA : 0x00DD52A8
// PDB : w:\tech5\tungsten\game\matchresults.cpp
// ========================================================================

void __fastcall idMatchResults::ClearItemsUnlocked(idMatchResults *this)
{
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->itemsUnlocked);
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$487839
// EA  : 0x82DD52E8
// RVA : 0x00DD52E8
// PDB : w:\tech5\tungsten\game\matchresults.cpp
// ========================================================================

void _unwind_487839()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetCashGainStr@idMatchResults@@QBA?AVidStr@@XZ
// EA  : 0x82DD5310
// RVA : 0x00DD5310
// PDB : w:\tech5\tungsten\game\matchresults.cpp
// ========================================================================

idMatchResults *__fastcall idMatchResults::GetCashGainStr(idMatchResults *this, idStr *result, __int64 a3)
{
  FormatCash(result: (idStr *)this, a2: *(_DWORD *)&result->baseBuffer[16], cash: a3);
  return this;
}


// ========================================================================
// ?GetMatchTimeStr@idMatchResults@@QBA?AVidStr@@XZ
// EA  : 0x82DD5350
// RVA : 0x00DD5350
// PDB : w:\tech5\tungsten\game\matchresults.cpp
// ========================================================================

idMatchResults *__fastcall idMatchResults::GetMatchTimeStr(idMatchResults *this, idStr *result, __int64 a3)
{
  idStr *v4; // r3
  char v5; // r30
  __int64 v6; // r4
  char v7; // r30
  idStr v9; // [sp+60h] [-60h] BYREF
  idStr v10[2]; // [sp+80h] [-40h] BYREF

  if ( result[1].data == (char *)0x7FFFFFFF )
  {
    v4 = idStr::idStr(this: v10, text: "-");
    v5 = 1;
  }
  else
  {
    LODWORD(v6) = result[1].data;
    HIDWORD(v6) = &v9;
    v4 = FormatTime(result: v6, time: a3);
    v5 = 2;
  }
  idStr::idStr((idStr *)this, text: v4);
  v7 = v5 | 4;
  if ( (v7 & 2) != 0 )
  {
    v7 &= ~2u;
    idStr::FreeData(this: &v9);
  }
  if ( (v7 & 1) != 0 )
    idStr::FreeData(this: v10);
  return this;
}


// ========================================================================
// __unwind$487879
// EA  : 0x82DD5404
// RVA : 0x00DD5404
// PDB : w:\tech5\tungsten\game\matchresults.cpp
// ========================================================================

void _unwind_487879()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 128));
  }
}


// ========================================================================
// __unwind$487881
// EA  : 0x82DD5448
// RVA : 0x00DD5448
// PDB : w:\tech5\tungsten\game\matchresults.cpp
// ========================================================================

void _unwind_487881()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 80) & 2) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~2u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 96));
  }
}


// ========================================================================
// __unwind$487883
// EA  : 0x82DD548C
// RVA : 0x00DD548C
// PDB : w:\tech5\tungsten\game\matchresults.cpp
// ========================================================================

void _unwind_487883()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 80) & 4) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~4u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 212));
  }
}


// ========================================================================
// `dynamic initializer for 'playerMatchResults''
// EA  : 0x83385810
// RVA : 0x01385810
// PDB : w:\tech5\tungsten\game\matchresults.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__playerMatchResults__()
{
  `eh vector constructor iterator'(
    ptr: (char *)playerMatchResults,
    size: 0x7Cu,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idMatchResults::idMatchResults,
    pDtor: (void (__fastcall *)(void *))idSWFText::~idSWFText);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__playerMatchResults__);
}

