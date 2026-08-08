
// ========================================================================
// ?idStrListCombineString@@YA?AVidStr@@ABV?$idList@VidStr@@$04@@PBD@Z
// EA  : 0x824E0540
// RVA : 0x004E0540
// PDB : w:\tech5\shared\idlib\containers\strlist.h
// ========================================================================

idStr *__fastcall idStrListCombineString(idStr *result, const idList<idStr,5> *list, char *separator)
{
  int v6; // r29
  int num; // r11
  int v8; // r27
  idStr *v9; // r3

  v6 = 0;
  result->len = 0;
  result->allocedAndFlag = 20;
  result->data = result->baseBuffer;
  result->baseBuffer[0] = 0;
  num = list->num;
  if ( num - 1 > 0 )
  {
    v8 = 0;
    do
    {
      idStr::Append(this: result, text: &list->list[v8]);
      idStr::Append(this: result, text: separator);
      ++v6;
      ++v8;
      num = list->num;
    }
    while ( v6 < num - 1 );
  }
  v9 = result;
  if ( num > 0 )
  {
    idStr::Append(this: result, text: &list->list[num - 1]);
    return result;
  }
  return v9;
}


// ========================================================================
// __unwind$520321
// EA  : 0x824E0608
// RVA : 0x004E0608
// PDB : w:\tech5\shared\idlib\containers\strlist.h
// ========================================================================

void _unwind_520321()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 144;
  if ( (*(_DWORD *)(v0 - 144 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 164));
  }
}


// ========================================================================
// ?idStrListBreakupString@@YAXAAV?$idList@VidStr@@$04@@PBDD@Z
// EA  : 0x824E0808
// RVA : 0x004E0808
// PDB : w:\tech5\shared\idlib\containers\strlist.h
// ========================================================================

void __fastcall idStrListBreakupString(idList<idStr,5> *list, const char *string, char separator)
{
  idStr *v6; // r3
  int v7; // r27
  int v8; // r29
  int v9; // r28
  idStr *v10; // r11
  idStr v11; // [sp+50h] [-80h] BYREF
  idStr v12[3]; // [sp+70h] [-60h] BYREF

  if ( list->listStatic == 0 || list->listStatic == 2 )
  {
    v6 = list->list;
    if ( list->list != nullptr )
      idListArrayDelete<idStr>(ptr: v6, num: list->size);
    list->list = nullptr;
    list->size = 0;
  }
  list->num = 0;
  idStr::idStr(this: &v11, text: string);
  idList<idStr,5>::Append(this: list, obj: &v11);
  idStr::FreeData(this: &v11);
  v7 = 0;
  v8 = idStr::Find(str: list->list->data, c: separator, start: 0, end: list->list->len);
  if ( v8 != -1 )
  {
    v9 = 0;
    do
    {
      idStr::idStr(this: v12, text: &list->list[v9].data[v8 + 1]);
      idList<idStr,5>::Append(this: list, obj: v12);
      idStr::FreeData(this: v12);
      v10 = &list->list[v9];
      if ( v10->len > v8 && v8 >= 0 )
      {
        v10->data[v8] = 0;
        v10->len = v8;
      }
      v9 = ++v7;
      v8 = idStr::Find(str: list->list[v7].data, c: separator, start: 0, end: list->list[v7].len);
    }
    while ( v8 != -1 );
  }
}


// ========================================================================
// __unwind$520595
// EA  : 0x824E0938
// RVA : 0x004E0938
// PDB : w:\tech5\shared\idlib\containers\strlist.h
// ========================================================================

void _unwind_520595()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$520596
// EA  : 0x824E0960
// RVA : 0x004E0960
// PDB : w:\tech5\shared\idlib\containers\strlist.h
// ========================================================================

void _unwind_520596()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?idStrListBreakupString@@YAXAAV?$idList@VidStr@@$04@@PBD1@Z
// EA  : 0x824E0990
// RVA : 0x004E0990
// PDB : w:\tech5\shared\idlib\containers\strlist.h
// ========================================================================

void __fastcall idStrListBreakupString(idList<idStr,5> *list, const char *string, const char *separator)
{
  int v6; // r26
  idStr *v7; // r3
  int v8; // r27
  int v9; // r30
  int v10; // r28
  idStr *v11; // r11
  idStr v12; // [sp+50h] [-90h] BYREF
  idStr v13[3]; // [sp+70h] [-70h] BYREF

  v6 = 0;
  if ( *separator != 0 )
  {
    do
      ++v6;
    while ( separator[v6] != 0 );
  }
  if ( list->listStatic == 0 || list->listStatic == 2 )
  {
    v7 = list->list;
    if ( list->list != nullptr )
      idListArrayDelete<idStr>(ptr: v7, num: list->size);
    list->list = nullptr;
    list->size = 0;
  }
  list->num = 0;
  idStr::idStr(this: &v12, text: string);
  idList<idStr,5>::Append(this: list, obj: &v12);
  idStr::FreeData(this: &v12);
  v8 = 0;
  v9 = idStr::Find(
         searchIn: list->list->data,
         searchFor: separator,
         casesensitive: true,
         start: 0,
         end: list->list->len);
  if ( v9 != -1 )
  {
    v10 = 0;
    do
    {
      idStr::idStr(this: v13, text: &list->list[v10].data[v6 + v9]);
      idList<idStr,5>::Append(this: list, obj: v13);
      idStr::FreeData(this: v13);
      v11 = &list->list[v10];
      if ( v11->len > v9 && v9 >= 0 )
      {
        v11->data[v9] = 0;
        v11->len = v9;
      }
      v10 = ++v8;
      v9 = idStr::Find(
             searchIn: list->list[v8].data,
             searchFor: separator,
             casesensitive: true,
             start: 0,
             end: list->list[v8].len);
    }
    while ( v9 != -1 );
  }
}


// ========================================================================
// __unwind$520673
// EA  : 0x824E0AE8
// RVA : 0x004E0AE8
// PDB : w:\tech5\shared\idlib\containers\strlist.h
// ========================================================================

void _unwind_520673()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$520674
// EA  : 0x824E0B10
// RVA : 0x004E0B10
// PDB : w:\tech5\shared\idlib\containers\strlist.h
// ========================================================================

void _unwind_520674()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}

