
// ========================================================================
// ?Size@idDeclVoiceOver@@UBAIXZ
// EA  : 0x8262D418
// RVA : 0x0062D418
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

unsigned int __fastcall idDeclVoiceOver::Size(idDeclVoiceOver *this)
{
  int v2; // r31
  unsigned int v3; // r28
  int v4; // r29

  v2 = 0;
  v3 = 4 * (this->tracks.size + 21);
  if ( this->tracks.num > 0 )
  {
    v4 = 0;
    do
    {
      ++v2;
      v3 = idVoiceTrack::Memory(this: this->tracks.list[v4++]) + v3 - 292;
    }
    while ( v2 < this->tracks.num );
  }
  return v3;
}


// ========================================================================
// ?GetMaxLength@idDeclVoiceOver@@QBA?AV?$idTypesafeNumber@HW4millisecondUnique_t@@@@XZ
// EA  : 0x8262D480
// RVA : 0x0062D480
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

idDeclVoiceOver *__fastcall idDeclVoiceOver::GetMaxLength(
        idDeclVoiceOver *this,
        idTypesafeNumber<int,enum millisecondUnique_t> *result)
{
  int value; // r11
  int v3; // r10
  int v4; // r9
  int i; // ctr
  int v6; // r11
  idDeclVoiceOver_vtbl *v7; // r11

  value = result[18].value;
  v3 = 0;
  this->__vftable = nullptr;
  if ( value > 0 )
  {
    v4 = result[17].value;
    for ( i = value; i != 0; --i )
    {
      v6 = *(_DWORD *)(v3 + v4);
      if ( v6 != 0 )
      {
        v7 = *(idDeclVoiceOver_vtbl **)(v6 + 288);
        if ( (int)v7 > (int)this->__vftable )
          this->__vftable = v7;
      }
      v3 += 4;
    }
  }
  return this;
}


// ========================================================================
// ?reloadVoiceOvers_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8262D4D0
// RVA : 0x0062D4D0
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void __fastcall reloadVoiceOvers_f(const idCmdArgs *args)
{
  bool v1; // r31
  int v2; // r31
  int num; // r29
  idResource *v4; // r3

  if ( args->argc <= 1 )
    goto LABEL_6;
  v1 = true;
  if ( args->argc == 2 )
    v1 = idStr::Icmp(s1: args->argv[1], s2: "-force") != 0;
  if ( v1 )
  {
    idLib::Printf(fmt: "USAGE: reloadVoiceOvers [-force]\n");
  }
  else
  {
LABEL_6:
    v2 = 0;
    num = idDeclVoiceOver::resourceList.num;
    ++idResourceList::staleCount;
    if ( idDeclVoiceOver::resourceList.num > 0 )
    {
      do
      {
        v4 = idResourceList::Index(this: &idDeclVoiceOver::resourceList, index: v2);
        v4->ReloadIfStale(this: v4);
        ++v2;
      }
      while ( v2 < num );
    }
  }
}


// ========================================================================
// ??0idDeclVoiceOver@@QAA@XZ
// EA  : 0x8262D860
// RVA : 0x0062D860
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

idDeclVoiceOver *__fastcall idDeclVoiceOver::idDeclVoiceOver(idDeclVoiceOver *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->nextSampleToPlay = -1;
  this->__vftable = (idDeclVoiceOver_vtbl *)&idDeclVoiceOver::`vftable';
  this->tracks.list = nullptr;
  this->tracks.granularity = 0;
  this->tracks.memTag = 65;
  this->tracks.listStatic = 0;
  this->tracks.size = 0;
  this->tracks.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tracks);
  return this;
}


// ========================================================================
// __unwind$220870
// EA  : 0x8262D8DC
// RVA : 0x0062D8DC
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_220870()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idDeclVoiceOver@@UAA@XZ
// EA  : 0x8262D920
// RVA : 0x0062D920
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void __fastcall idDeclVoiceOver::~idDeclVoiceOver(idDeclVoiceOver *this)
{
  idList<idVoiceTrack const *,65> *p_tracks; // r29

  this->__vftable = (idDeclVoiceOver_vtbl *)&idDeclVoiceOver::`vftable';
  p_tracks = &this->tracks;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tracks);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_tracks);
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$220895
// EA  : 0x8262D968
// RVA : 0x0062D968
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_220895()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$220896
// EA  : 0x8262D990
// RVA : 0x0062D990
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_220896()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 68));
}


// ========================================================================
// ?listStaleVoiceTracks_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8262D9C0
// RVA : 0x0062D9C0
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void __fastcall listStaleVoiceTracks_f(const idCmdArgs *args)
{
  int v1; // r24
  int v2; // r27
  int v3; // r26
  int num; // r19
  int v5; // r22
  const char *str; // r4
  const idDecl *v7; // r28
  int resourceListPtr; // r11
  int v9; // r30
  int v10; // r29
  idVoiceTrack *v11; // r31
  BOOL IsCustomized; // r9
  const char *v13; // r5

  common->SetRefreshOnPrint(this: common, a2: true);
  v1 = 0;
  v2 = 0;
  v3 = 0;
  if ( idDeclVoiceOver::resourceList.declSources.num > 0 )
  {
    num = idDeclVoiceOver::resourceList.declSources.num;
    v5 = 0;
    do
    {
      str = idDeclVoiceOver::resourceList.declSources.list[v5]->name.str;
      if ( str != nullptr )
        v7 = idDeclInfo::FindWithInheritance(this: &idDeclVoiceOver::resourceList, name: str, makeDefault: false);
      else
        v7 = nullptr;
      resourceListPtr = (int)v7[1].resourceListPtr;
      v9 = 0;
      v1 += resourceListPtr;
      if ( resourceListPtr > 0 )
      {
        v10 = 0;
        do
        {
          if ( v9 < 0 || v9 >= resourceListPtr )
            v11 = nullptr;
          else
            v11 = *(idVoiceTrack **)((char *)&v7[1].nextOnHashChain->idResource::__vftable + v10);
          if ( idVoiceTrack::IsStale(this: v11) )
          {
            v3 += idVoiceTrack::IsCustomized(this: v11);
            IsCustomized = idVoiceTrack::IsCustomized(this: v11);
            v13 = "^3 - customized";
            if ( !IsCustomized )
              v13 = &byte_8200D768;
            idLib::Printf(fmt: "^7  %s%s\n", v11->name.str, v13);
            ++v2;
          }
          resourceListPtr = (int)v7[1].resourceListPtr;
          ++v9;
          v10 += 4;
        }
        while ( v9 < resourceListPtr );
      }
      --num;
      ++v5;
    }
    while ( num != 0 );
  }
  idLib::Printf(fmt: "%d total referenced voice tracks.\n", v1);
  idLib::Printf(fmt: "%d stale voice tracks found.\n", v2);
  idLib::Printf(fmt: "%d stale voice tracks were customized.\n", v3);
  common->SetRefreshOnPrint(this: common, a2: false);
}


// ========================================================================
// ?listCustomizedVoiceTracks_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8262DC10
// RVA : 0x0062DC10
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void __fastcall listCustomizedVoiceTracks_f(const idCmdArgs *args)
{
  __int64 v1; // r10
  const char **v2; // r8
  int v3; // r7
  int v4; // r6
  signed int v5; // r27
  idStr *list; // r20
  int size; // r18
  int v8; // r17
  idStr *v9; // r23
  int v10; // r19
  signed int v11; // r26
  idStr *v12; // r24
  int v13; // r22
  signed int v14; // r25
  int num; // r25
  const idDecl *v16; // r24
  int resourceListPtr; // r11
  int v18; // r29
  int v19; // r28
  int v20; // r30
  int v21; // r3
  char v22; // r11
  idStr *v23; // r3
  const char **p_data; // r29
  signed int i; // r30
  const char **v26; // r29
  signed int j; // r30
  const char **v28; // r29
  signed int k; // r30
  idStr *v30; // r29
  int m; // r30
  idStr *v32; // r29
  int n; // r30
  idStr *v34; // r29
  int ii; // r30
  idSort_Quick<idStr,idSort_vtr> v36; // [sp+54h] [-12Ch] BYREF
  idSort_Quick<idStr,idSort_vtr> v37; // [sp+58h] [-128h] BYREF
  idSort_Quick<idStr,idSort_vtr> v38; // [sp+5Ch] [-124h] BYREF
  idList<idStr,5> v39; // [sp+60h] [-120h] BYREF
  idList<idStr,5> v40; // [sp+70h] [-110h] BYREF
  idList<idStr,5> v41; // [sp+80h] [-100h] BYREF
  idStr v42; // [sp+90h] [-F0h] BYREF
  idStr v43; // [sp+B0h] [-D0h] BYREF
  idStr v44[5]; // [sp+D0h] [-B0h] BYREF

  common->SetRefreshOnPrint(this: common, a2: true);
  v5 = 0;
  list = nullptr;
  *(_WORD *)&v41.memTag = 1280;
  size = 0;
  memset(&v41, 0, 14);
  v8 = 0;
  v9 = nullptr;
  v10 = 0;
  *(_WORD *)&v40.memTag = 1280;
  v11 = 0;
  memset(&v40, 0, 14);
  v12 = nullptr;
  *(_WORD *)&v39.memTag = 1280;
  v13 = 0;
  v14 = 0;
  memset(&v39, 0, 14);
  if ( idDeclVoiceOver::resourceList.declSources.num > 0 )
  {
    num = idDeclVoiceOver::resourceList.declSources.num;
    while ( 1 )
    {
      LODWORD(v1) = idDeclVoiceOver::resourceList.declSources.list;
      HIDWORD(v1) = (char *)idDeclVoiceOver::resourceList.declSources.list + v11;
      v2 = *(const char ***)((char *)idDeclVoiceOver::resourceList.declSources.list + v11);
      v16 = *v2 != nullptr
          ? idDeclInfo::FindWithInheritance(this: &idDeclVoiceOver::resourceList, name: *v2, makeDefault: false)
          : nullptr;
      resourceListPtr = (int)v16[1].resourceListPtr;
      v18 = 0;
      v8 += resourceListPtr;
      if ( resourceListPtr > 0 )
        break;
LABEL_23:
      --num;
      v11 += 4;
      if ( num == 0 )
      {
        size = v41.size;
        v5 = v41.num;
        list = v41.list;
        v10 = v40.size;
        v11 = v40.num;
        v9 = v40.list;
        v13 = v39.size;
        v14 = v39.num;
        v12 = v39.list;
        goto LABEL_25;
      }
    }
    v19 = 0;
    while ( 1 )
    {
      if ( v18 < 0 || v18 >= resourceListPtr )
        v20 = 0;
      else
        v20 = *(int *)((char *)&v16[1].nextOnHashChain->idResource::__vftable + v19);
      if ( (*(_BYTE *)(v20 + 268) & 4) != 0
        || (v21 = idVoiceEventManager::NumEventType(this: (idVoiceEventManager *)(v20 + 52), type: VOICEEVENT_ANIM),
            v22 = 0,
            v21 > 0) )
      {
        v22 = 1;
      }
      if ( v22 != 0 )
        break;
      if ( **(_BYTE **)(v20 + 208) != 0 )
      {
        idStr::idStr(this: &v43, text: *(const char **)(v20 + 8));
        idList<idStr,5>::Append(this: &v39, obj: &v43);
        v23 = &v43;
        goto _M221720_0;
      }
      if ( idVoiceTrack::IsCustomized(this: (idVoiceTrack *)v20) )
      {
        idStr::idStr(this: v44, text: *(const char **)(v20 + 8));
        idList<idStr,5>::Append(this: &v41, obj: v44);
        v23 = v44;
        goto _M221720_0;
      }
LABEL_22:
      ++v18;
      v19 += 4;
      resourceListPtr = (int)v16[1].resourceListPtr;
      if ( v18 >= resourceListPtr )
        goto LABEL_23;
    }
    idStr::idStr(this: &v42, text: *(const char **)(v20 + 8));
    idList<idStr,5>::Append(this: &v40, obj: &v42);
    v23 = &v42;
_M221720_0:
    idStr::FreeData(this: v23);
    goto LABEL_22;
  }
LABEL_25:
  v38.__vftable = (idSort_Quick<idStr,idSort_vtr>_vtbl *)&idSort_vtr::`vftable';
  if ( list != nullptr )
    idSort_Quick<idStr,idSort_vtr>::Sort(this: &v38, base: list, num: v5, a4: v4, a5: v3, a6: (int)v2, a7: v1);
  v36.__vftable = (idSort_Quick<idStr,idSort_vtr>_vtbl *)&idSort_vtr::`vftable';
  v38.__vftable = (idSort_Quick<idStr,idSort_vtr>_vtbl *)&idSort<idStr>::`vftable';
  if ( v9 != nullptr )
    idSort_Quick<idStr,idSort_vtr>::Sort(this: &v36, base: v9, num: v11, a4: v4, a5: v3, a6: (int)v2, a7: v1);
  v36.__vftable = (idSort_Quick<idStr,idSort_vtr>_vtbl *)&idSort<idStr>::`vftable';
  v37.__vftable = (idSort_Quick<idStr,idSort_vtr>_vtbl *)&idSort_vtr::`vftable';
  if ( v12 != nullptr )
    idSort_Quick<idStr,idSort_vtr>::Sort(this: &v37, base: v12, num: v14, a4: v4, a5: v3, a6: (int)v2, a7: v1);
  v37.__vftable = (idSort_Quick<idStr,idSort_vtr>_vtbl *)&idSort<idStr>::`vftable';
  if ( v5 > 0 )
  {
    p_data = (const char **)&list[-1].data;
    for ( i = v5; i != 0; --i )
    {
      p_data += 8;
      idLib::Printf(fmt: "%s - ^2customized\n", *p_data);
    }
  }
  if ( v11 > 0 )
  {
    v26 = (const char **)&v9[-1].data;
    for ( j = v11; j != 0; --j )
    {
      v26 += 8;
      idLib::Printf(fmt: "%s - ^5edited\n", *v26);
    }
  }
  if ( v14 > 0 )
  {
    v28 = (const char **)&v12[-1].data;
    for ( k = v14; k != 0; --k )
    {
      v28 += 8;
      idLib::Printf(fmt: "%s - ^4hand keyed\n", *v28);
    }
  }
  idLib::Printf(fmt: "^7%d total referenced voice tracks.\n", v8);
  idLib::Printf(fmt: "^3%d customized voice tracks found.\n", v5);
  idLib::Printf(fmt: "^5%d edited voice tracks found.\n", v11);
  idLib::Printf(fmt: "^4%d hand-keyed voice tracks found.\n", v14);
  common->SetRefreshOnPrint(this: common, a2: false);
  if ( (v39.listStatic == 0 || v39.listStatic == 2) && v12 != nullptr )
  {
    if ( v13 > 0 )
    {
      v30 = v12;
      for ( m = v13; m != 0; --m )
        idStr::FreeData(this: v30++);
    }
    idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
  }
  if ( (v40.listStatic == 0 || v40.listStatic == 2) && v9 != nullptr )
  {
    if ( v10 > 0 )
    {
      v32 = v9;
      for ( n = v10; n != 0; --n )
        idStr::FreeData(this: v32++);
    }
    idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
  }
  if ( (v41.listStatic == 0 || v41.listStatic == 2) && list != nullptr )
  {
    if ( size > 0 )
    {
      v34 = list;
      for ( ii = size; ii != 0; --ii )
        idStr::FreeData(this: v34++);
    }
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$221100
// EA  : 0x8262E0AC
// RVA : 0x0062E0AC
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_221100()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 384 + 128));
}


// ========================================================================
// __unwind$221101
// EA  : 0x8262E0D4
// RVA : 0x0062E0D4
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_221101()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 384 + 112));
}


// ========================================================================
// __unwind$221102
// EA  : 0x8262E0FC
// RVA : 0x0062E0FC
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_221102()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$221103
// EA  : 0x8262E124
// RVA : 0x0062E124
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_221103()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 144));
}


// ========================================================================
// __unwind$221104
// EA  : 0x8262E14C
// RVA : 0x0062E14C
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_221104()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 176));
}


// ========================================================================
// __unwind$221105
// EA  : 0x8262E174
// RVA : 0x0062E174
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_221105()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 208));
}


// ========================================================================
// __unwind$221106
// EA  : 0x8262E19C
// RVA : 0x0062E19C
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_221106()
{
  int v0; // r12

  idSort_QuickDefault<idStr>::~idSort_QuickDefault<idStr>(this: (idSort_QuickDefault<idStr> *)(v0 - 384 + 92));
}


// ========================================================================
// __unwind$221107
// EA  : 0x8262E1C4
// RVA : 0x0062E1C4
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_221107()
{
  int v0; // r12

  idSort_QuickDefault<idStr>::~idSort_QuickDefault<idStr>(this: (idSort_QuickDefault<idStr> *)(v0 - 384 + 84));
}


// ========================================================================
// __unwind$221108_0
// EA  : 0x8262E1EC
// RVA : 0x0062E1EC
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_221108_0()
{
  int v0; // r12

  idSort_QuickDefault<idStr>::~idSort_QuickDefault<idStr>(this: (idSort_QuickDefault<idStr> *)(v0 - 384 + 88));
}


// ========================================================================
// ?removeUnreferencedVoiceTracks_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8262E220
// RVA : 0x0062E220
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void __fastcall removeUnreferencedVoiceTracks_f(const idCmdArgs *args)
{
  idStr *list; // r21
  int size; // r20
  int v3; // r27
  int num; // r25
  const char *v5; // r4
  const idDecl *v6; // r28
  int resourceListPtr; // r11
  int v8; // r30
  int v9; // r29
  int v10; // r11
  idFileList *v11; // r25
  int v12; // r23
  int v13; // r24
  int v14; // r26
  int v15; // r30
  const char *data; // r28
  const char **p_data; // r29
  idStr *v18; // r29
  int i; // r30
  idList<idStr,5> v20; // [sp+60h] [-B0h] BYREF
  idStr v21[5]; // [sp+70h] [-A0h] BYREF

  *(_WORD *)&v20.memTag = 1280;
  list = nullptr;
  size = 0;
  v3 = 0;
  memset(&v20, 0, 14);
  common->SetRefreshOnPrint(this: common, a2: true);
  if ( idDeclVoiceOver::resourceList.declSources.num > 0 )
  {
    num = idDeclVoiceOver::resourceList.declSources.num;
    do
    {
      v5 = **(const char ***)((char *)idDeclVoiceOver::resourceList.declSources.list + v3);
      if ( v5 != nullptr )
        v6 = idDeclInfo::FindWithInheritance(this: &idDeclVoiceOver::resourceList, name: v5, makeDefault: false);
      else
        v6 = nullptr;
      v8 = 0;
      resourceListPtr = (int)v6[1].resourceListPtr;
      if ( resourceListPtr > 0 )
      {
        v9 = 0;
        do
        {
          if ( v8 < 0 || v8 >= resourceListPtr )
            v10 = 0;
          else
            v10 = *(int *)((char *)&v6[1].nextOnHashChain->idResource::__vftable + v9);
          idStr::idStr(this: v21, text: *(const char **)(v10 + 8));
          if ( idList<idStr,5>::FindIndex(this: &v20, obj: v21, startIndex: 0) < 0 )
            idList<idStr,5>::Append(this: &v20, obj: v21);
          idStr::FreeData(this: v21);
          ++v8;
          v9 += 4;
          resourceListPtr = (int)v6[1].resourceListPtr;
        }
        while ( v8 < resourceListPtr );
      }
      --num;
      v3 += 4;
    }
    while ( num != 0 );
    v3 = v20.num;
    size = v20.size;
    list = v20.list;
  }
  v11 = fileSystem->ListFilesTree(this: fileSystem, a2: "voicetrack", a3: ".vtr", a4: 0);
  v12 = 0;
  v13 = 0;
  if ( v11->list.num > 0 )
  {
    v14 = 0;
    do
    {
      v15 = 0;
      data = v11->list.list[v14].data;
      if ( v3 <= 0 )
        goto LABEL_25;
      p_data = (const char **)&list->data;
      while ( idStr::Icmp(s1: data, s2: *p_data) != 0 )
      {
        ++v15;
        p_data += 8;
        if ( v15 >= v3 )
          goto LABEL_25;
      }
      if ( v15 >= v3 )
      {
LABEL_25:
        idLib::Printf(fmt: "File '%s' is unreferenced. Deleting...\n", data);
        ++v12;
      }
      ++v13;
      ++v14;
    }
    while ( v13 < v11->list.num );
  }
  idLib::Printf(fmt: "Removed %d unreferenced voice tracks.\n", v12);
  common->SetRefreshOnPrint(this: common, a2: false);
  if ( (v20.listStatic == 0 || v20.listStatic == 2) && list != nullptr )
  {
    if ( size > 0 )
    {
      v18 = list;
      for ( i = size; i != 0; --i )
        idStr::FreeData(this: v18++);
    }
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$221775
// EA  : 0x8262E4B0
// RVA : 0x0062E4B0
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_221775()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$221776
// EA  : 0x8262E4D8
// RVA : 0x0062E4D8
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

void _unwind_221776()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// ?AddTrack@idDeclVoiceOver@@QAA_NPAVidVoiceTrack@@@Z
// EA  : 0x8262E500
// RVA : 0x0062E500
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

int __fastcall idDeclVoiceOver::AddTrack(idDeclVoiceOver *this, idSpawnArea::GeneratedPosition *vtrack)
{
  int v4; // r29
  int v5; // r30
  idList<idSpawnArea::GeneratedPosition *,5> *p_tracks; // r31
  int granularity; // r4
  int size; // r11
  bool v9; // cr58
  signed int v11; // r10
  int v12; // r4
  int v13; // r11
  int num; // r11

  v4 = 0;
  if ( this->tracks.num <= 0 )
  {
LABEL_5:
    p_tracks = (idList<idSpawnArea::GeneratedPosition *,5> *)&this->tracks;
    if ( p_tracks->list != nullptr )
      goto LABEL_9;
    granularity = p_tracks->granularity;
    if ( granularity <= 0 )
      granularity = 1;
    if ( idList<idNavSpline *,5>::Resize(this: p_tracks, newsize: granularity) )
    {
LABEL_9:
      size = p_tracks->size;
      if ( p_tracks->num != size )
        goto LABEL_21;
      if ( forceIdListsToReallocateEveryAppend )
      {
        v9 = !idList<idNavSpline *,5>::Resize(this: p_tracks, newsize: size + 1);
      }
      else
      {
        v11 = p_tracks->granularity;
        if ( p_tracks->granularity != 0 )
        {
          v13 = size + v11;
          __twllei(v11, 0);
          __twlgei(v11 & ~(__ROL4__(v13, 1) - 1), 0xFFFFFFFF);
          v9 = !idList<idNavSpline *,5>::Resize(this: p_tracks, newsize: v13 - v13 % v11);
        }
        else
        {
          v12 = 2 * size;
          if ( 2 * size >= size )
          {
            if ( v12 == 0 )
              v12 = 1;
            v9 = !idList<idNavSpline *,5>::Resize(this: p_tracks, newsize: v12);
          }
          else
          {
            v9 = !idList<idNavSpline *,5>::Resize(this: p_tracks, newsize: 0x7FFFFFFF);
          }
        }
      }
      if ( !v9 )
      {
LABEL_21:
        num = p_tracks->num;
        if ( num < p_tracks->size )
        {
          p_tracks->list[num] = vtrack;
          ++p_tracks->num;
        }
      }
    }
    return 1;
  }
  else
  {
    v5 = 0;
    while ( idStr::Icmp(s1: this->tracks.list[v5]->name.str, s2: (const char *)LODWORD(vtrack->position.z)) != 0 )
    {
      ++v4;
      ++v5;
      if ( v4 >= this->tracks.num )
        goto LABEL_5;
    }
    return 0;
  }
}


// ========================================================================
// `dynamic initializer for 'reloadVoiceOvers_v''
// EA  : 0x833372E0
// RVA : 0x013372E0
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reloadVoiceOvers_v__()
{
  return idCommandLink::idCommandLink(
           this: &reloadVoiceOvers_v,
           cmdName: "reloadVoiceOvers",
           function: reloadVoiceOvers_f,
           description: "reload changed voice overs, add 'force' as a parameter to force regeneration of all voice overs",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'listCustomizedVoiceTracks_v''
// EA  : 0x83337308
// RVA : 0x01337308
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__listCustomizedVoiceTracks_v__()
{
  return idCommandLink::idCommandLink(
           this: &listCustomizedVoiceTracks_v,
           cmdName: "listCustomizedVoiceTracks",
           function: listCustomizedVoiceTracks_f,
           description: "lists referenced voice tracks that have been modified since phoneme to viseme generation.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'listStaleVoiceTracks_v''
// EA  : 0x83337330
// RVA : 0x01337330
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__listStaleVoiceTracks_v__()
{
  return idCommandLink::idCommandLink(
           this: &listStaleVoiceTracks_v,
           cmdName: "listStaleVoiceTracks",
           function: listStaleVoiceTracks_f,
           description: "lists voice tracks that have not been regenerated since their source text or sound shader were changed",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'removeUnreferencedVoiceTracks_v''
// EA  : 0x83337358
// RVA : 0x01337358
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__removeUnreferencedVoiceTracks_v__()
{
  return idCommandLink::idCommandLink(
           this: &removeUnreferencedVoiceTracks_v,
           cmdName: "removeUnreferencedVoiceTracks",
           function: removeUnreferencedVoiceTracks_f,
           description: "Deletes voice tracks (.vtr) files that are not referenced by any voice over decls",
           argCompletion: nullptr);
}

