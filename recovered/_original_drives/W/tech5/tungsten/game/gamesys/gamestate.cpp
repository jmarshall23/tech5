
// ========================================================================
// ?Shutdown@idGameState@@SAXXZ
// EA  : 0x82D62850
// RVA : 0x00D62850
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

static void __fastcall idGameState::Shutdown()
{
  idTypeInfoTools::Shutdown(this: typeInfoTools);
  idTypeInfoStrings::Shutdown(this: &ptrNames);
}


// ========================================================================
// ?GetTypeInfoTools@idGameState@@SAPBVidTypeInfoTools@@XZ
// EA  : 0x82D62888
// RVA : 0x00D62888
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

const idTypeInfoTools *__fastcall idGameState::GetTypeInfoTools()
{
  return typeInfoTools;
}


// ========================================================================
// ?FindUninitializedMemory_f@idGameState@@SAXABVidCmdArgs@@@Z
// EA  : 0x82D62898
// RVA : 0x00D62898
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall idGameState::FindUninitializedMemory_f(const idCmdArgs *args)
{
  idFile *v1; // r22
  int v2; // r17
  classTypeInfo_t *classes; // r11
  int v4; // r10
  const char *name; // r30
  idTypeInfo *Class; // r3
  idTypeInfo *v7; // r31
  idClass *Instance; // r21
  unsigned int v9; // r11
  int v10; // r31
  unsigned int i; // r23
  const char *VariableNameFromOffset; // r29
  const char *VariableTypeFromOffset; // r28
  const char *VariableOpsFromOffset; // r27

  v1 = fileSystem->OpenFileWrite(this: fileSystem, a2: "uninitialized.txt", a3: 0);
  if ( v1 != nullptr )
  {
    v2 = 0;
    classes = typeInfo.classes;
    if ( typeInfo.classes->name != nullptr )
    {
      v4 = 0;
      do
      {
        name = classes[v4].name;
        if ( idTypeInfoTools::IsSubclassOf(this: typeInfoTools, typeName: name, superType: "idClass") )
        {
          Class = idClass::GetClass(name);
          v7 = Class;
          if ( Class != nullptr && !Class->isAbstract )
          {
            Instance = idClass::CreateInstance(name);
            v9 = (unsigned int)v7->size >> 2;
            if ( v9 != 0 )
            {
              v10 = 0;
              for ( i = v9; i != 0; --i )
              {
                if ( Instance[v10 / 4u].__vftable == (idClass_vtbl *)-842150451 )
                {
                  VariableNameFromOffset = idTypeInfoTools::GetVariableNameFromOffset(
                                             this: typeInfoTools,
                                             typeName: name,
                                             offset: v10);
                  VariableTypeFromOffset = idTypeInfoTools::GetVariableTypeFromOffset(
                                             this: typeInfoTools,
                                             typeName: name,
                                             offset: v10);
                  VariableOpsFromOffset = idTypeInfoTools::GetVariableOpsFromOffset(
                                            this: typeInfoTools,
                                            typeName: name,
                                            offset: v10);
                  if ( idStr::Find(
                         searchIn: VariableNameFromOffset,
                         searchFor: "baseBuffer",
                         casesensitive: true,
                         start: 0,
                         end: -1) == -1
                    && idStr::Cmpn(s1: VariableTypeFromOffset, s2: "<unknown", n: 8) != 0 )
                  {
                    idLib::Printf(
                      fmt: "type '%s' has uninitialized variable: %s %s %s (offset %d)\n",
                      name,
                      VariableTypeFromOffset,
                      VariableOpsFromOffset,
                      VariableNameFromOffset,
                      v10);
                    v1->WriteFloatString(
                      this: v1,
                      a2: "type '%s' has uninitialized variable: %s %s %s (offset %d)\n",
                      name,
                      VariableTypeFromOffset,
                      VariableOpsFromOffset,
                      VariableNameFromOffset,
                      v10);
                  }
                }
                v10 += 4;
              }
            }
            if ( Instance != nullptr )
              ((void (__fastcall *)(idClass *, int))Instance->dtr_idClass)(a1: Instance, a2: 1);
          }
        }
        ++v2;
        classes = typeInfo.classes;
        v4 = v2;
      }
      while ( typeInfo.classes[v2].name != nullptr );
    }
    ((void (__fastcall *)(idFile *, int))v1->dtr_idFile)(a1: v1, a2: 1);
    idLib::Printf(fmt: "'%s' written\n", "uninitialized.txt");
  }
}


// ========================================================================
// ?WriteAliasRef_t@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D62AD0
// RVA : 0x00D62AD0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteAliasRef_t(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const char **a28)
{
  idTypeInfoFile::WriteStr(this: file, s: *a28);
}


// ========================================================================
// ?ReadAliasRef_t@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D62AE8
// RVA : 0x00D62AE8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadAliasRef_t(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idAtomicString *a28)
{
  int v28; // [sp+50h] [-40h] BYREF
  idStr v29; // [sp+60h] [-30h] BYREF

  v29.len = 0;
  v29.allocedAndFlag = 20;
  v29.data = v29.baseBuffer;
  v29.baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: &v29);
  idAtomicString::Set(this: a28, str_: v29.data);
  ((void (__fastcall *)(int *))animation->AddStrongAliasRef)(a1: &v28);
  idStr::FreeData(this: &v29);
}


// ========================================================================
// __unwind$507343
// EA  : 0x82D62B6C
// RVA : 0x00D62B6C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_507343()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 96));
}


// ========================================================================
// ?ListTypeInfo_f@idGameState@@SAXABVidCmdArgs@@@Z
// EA  : 0x82D639B8
// RVA : 0x00D639B8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall idGameState::ListTypeInfo_f(const idCmdArgs *args)
{
  __int64 v2; // r10
  int v3; // r8
  int v4; // r6
  int v5; // r29
  const char *name; // r7
  bool v7; // cr57
  encounterGroupRole_t *list; // r26
  classTypeInfo_t *v9; // r28
  encounterGroupRole_t *v10; // r29
  int argc; // [sp+50h] [-60h] BYREF
  idSort_Quick<int,idSort_ClassTypeInfoBySize> v12; // [sp+54h] [-5Ch] BYREF
  idSort_Quick<int,idSort_ClassTypeInfoByName> v13; // [sp+58h] [-58h] BYREF
  idList<enum encounterGroupRole_t,5> v14[5]; // [sp+60h] [-50h] BYREF

  memset(v14, 0, 14);
  v14[0].listStatic = 0;
  v14[0].memTag = 5;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v14);
  idLib::Printf(fmt: "%-48s : %-48s : size (B)\n", "type name", "super type name");
  v5 = 0;
  argc = 0;
  name = classTypeInfo[0].name;
  if ( classTypeInfo[0].name != nullptr )
  {
    do
    {
      idList<idAnimWebBlendTree *,5>::Append(this: v14, obj: (encounterGroupRole_t *)&argc);
      argc = ++v5;
      LODWORD(v2) = classTypeInfo[v5].name;
    }
    while ( (_DWORD)v2 != 0 );
  }
  v7 = args->argc > 1;
  argc = args->argc;
  if ( !v7 || idStr::Icmp(s1: args->argv[1], s2: "size") != 0 )
  {
    v13.__vftable = (idSort_Quick<int,idSort_ClassTypeInfoByName>_vtbl *)&idSort_ClassTypeInfoByName::`vftable';
    list = v14[0].list;
    if ( v14[0].list != nullptr )
      idSort_Quick<int,idSort_ClassTypeInfoByName>::Sort(
        this: &v13,
        base: (int *)v14[0].list,
        num: v14[0].num,
        a4: v4,
        a5: (int)name,
        a6: v3,
        a7: v2);
    v13.__vftable = (idSort_Quick<int,idSort_ClassTypeInfoByName>_vtbl *)&idSort<int>::`vftable';
  }
  else
  {
    v12.__vftable = (idSort_Quick<int,idSort_ClassTypeInfoBySize>_vtbl *)&idSort_ClassTypeInfoBySize::`vftable';
    list = v14[0].list;
    if ( v14[0].list != nullptr )
      idSort_Quick<int,idSort_ClassTypeInfoBySize>::Sort(
        this: &v12,
        base: (int *)v14[0].list,
        num: v14[0].num,
        a4: v4,
        a5: (int)name,
        a6: v3,
        a7: v2);
    v12.__vftable = (idSort_Quick<int,idSort_ClassTypeInfoBySize>_vtbl *)&idSort<int>::`vftable';
  }
  if ( classTypeInfo[0].name != nullptr )
  {
    v9 = classTypeInfo;
    v10 = list - 1;
    do
    {
      ++v10;
      idLib::Printf(
        fmt: "%-48s : %-48s : %d\n",
        classTypeInfo[*v10].name,
        classTypeInfo[*v10].superType,
        classTypeInfo[*v10].size);
      ++v9;
    }
    while ( v9->name != nullptr );
  }
  if ( (v14[0].listStatic == 0 || v14[0].listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// __unwind$508681
// EA  : 0x82D63B78
// RVA : 0x00D63B78
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_508681()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$508682
// EA  : 0x82D63BA0
// RVA : 0x00D63BA0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_508682()
{
  int v0; // r12

  idSort_EntryDepthAndTicks::~idSort_EntryDepthAndTicks(this: (idSort_AnimEventSort *)(v0 - 176 + 84));
}


// ========================================================================
// __unwind$508683
// EA  : 0x82D63BC8
// RVA : 0x00D63BC8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_508683()
{
  int v0; // r12

  idSort_EntryDepthAndTicks::~idSort_EntryDepthAndTicks(this: (idSort_AnimEventSort *)(v0 - 176 + 88));
}


// ========================================================================
// ?ListGameTypeInfo_f@idGameState@@SAXABVidCmdArgs@@@Z
// EA  : 0x82D63BF8
// RVA : 0x00D63BF8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall idGameState::ListGameTypeInfo_f(const idCmdArgs *args)
{
  int v1; // r30
  __int64 v3; // r10
  int v4; // r8
  int v5; // r7
  int v6; // r6
  classTypeInfo_t *v7; // r29
  bool v8; // cr57
  encounterGroupRole_t *list; // r27
  int num; // r30
  encounterGroupRole_t *v11; // r29
  int argc; // [sp+50h] [-70h] BYREF
  idSort_Quick<int,idSort_ClassTypeInfoBySize> v13; // [sp+54h] [-6Ch] BYREF
  idSort_Quick<int,idSort_ClassTypeInfoByName> v14; // [sp+58h] [-68h] BYREF
  idList<enum encounterGroupRole_t,5> v15[6]; // [sp+60h] [-60h] BYREF

  v1 = 0;
  memset(v15, 0, 14);
  v15[0].listStatic = 0;
  v15[0].memTag = 5;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v15);
  idLib::Printf(fmt: "%-48s : %-48s : size (B)\n", "type name", "super type name");
  argc = 0;
  if ( classTypeInfo[0].name != nullptr )
  {
    v7 = classTypeInfo;
    do
    {
      if ( idTypeInfoTools::IsSubclassOf(this: typeInfoTools, typeName: v7->name, superType: "idClass")
        || idTypeInfoTools::IsSubclassOf(this: typeInfoTools, typeName: v7->name, superType: "idGameLocal") )
      {
        idList<idAnimWebBlendTree *,5>::Append(this: v15, obj: (encounterGroupRole_t *)&argc);
      }
      argc = ++v1;
      LODWORD(v3) = classTypeInfo[v1].name;
      v7 = &classTypeInfo[v1];
    }
    while ( (_DWORD)v3 != 0 );
  }
  v8 = args->argc > 1;
  argc = args->argc;
  if ( !v8 || idStr::Icmp(s1: args->argv[1], s2: "size") != 0 )
  {
    v14.__vftable = (idSort_Quick<int,idSort_ClassTypeInfoByName>_vtbl *)&idSort_ClassTypeInfoByName::`vftable';
    list = v15[0].list;
    num = v15[0].num;
    if ( v15[0].list != nullptr )
      idSort_Quick<int,idSort_ClassTypeInfoByName>::Sort(
        this: &v14,
        base: (int *)v15[0].list,
        num: v15[0].num,
        a4: v6,
        a5: v5,
        a6: v4,
        a7: v3);
    v14.__vftable = (idSort_Quick<int,idSort_ClassTypeInfoByName>_vtbl *)&idSort<int>::`vftable';
  }
  else
  {
    v13.__vftable = (idSort_Quick<int,idSort_ClassTypeInfoBySize>_vtbl *)&idSort_ClassTypeInfoBySize::`vftable';
    list = v15[0].list;
    num = v15[0].num;
    if ( v15[0].list != nullptr )
      idSort_Quick<int,idSort_ClassTypeInfoBySize>::Sort(
        this: &v13,
        base: (int *)v15[0].list,
        num: v15[0].num,
        a4: v6,
        a5: v5,
        a6: v4,
        a7: v3);
    v13.__vftable = (idSort_Quick<int,idSort_ClassTypeInfoBySize>_vtbl *)&idSort<int>::`vftable';
  }
  if ( num > 0 )
  {
    v11 = list - 1;
    do
    {
      ++v11;
      idLib::Printf(
        fmt: "%-48s : %-48s : %d\n",
        classTypeInfo[*v11].name,
        classTypeInfo[*v11].superType,
        classTypeInfo[*v11].size);
      --num;
    }
    while ( num != 0 );
  }
  if ( (v15[0].listStatic == 0 || v15[0].listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// __unwind$508865
// EA  : 0x82D63E04
// RVA : 0x00D63E04
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_508865()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$508866
// EA  : 0x82D63E2C
// RVA : 0x00D63E2C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_508866()
{
  int v0; // r12

  idSort_EntryDepthAndTicks::~idSort_EntryDepthAndTicks(this: (idSort_AnimEventSort *)(v0 - 192 + 84));
}


// ========================================================================
// __unwind$508867
// EA  : 0x82D63E54
// RVA : 0x00D63E54
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_508867()
{
  int v0; // r12

  idSort_EntryDepthAndTicks::~idSort_EntryDepthAndTicks(this: (idSort_AnimEventSort *)(v0 - 192 + 88));
}


// ========================================================================
// ?ListClassTypeInfo_f@idGameState@@SAXABVidCmdArgs@@@Z
// EA  : 0x82D63E88
// RVA : 0x00D63E88
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall idGameState::ListClassTypeInfo_f(const idCmdArgs *args)
{
  int v1; // r30
  int v3; // r27
  int v4; // r11
  classTypeInfo_t *v5; // r28
  char *v6; // r3
  const char *v7; // r4
  const classVariableInfo_t *variables; // r11
  const classVariableInfo_t *v9; // r10
  int argc; // r11
  signed int num; // r30
  int *list; // r25
  bool v13; // cr57
  const char *v14; // r3
  encounterGroupRole_t *v15; // r4
  __int64 v16; // r10
  int v17; // r8
  int v18; // r7
  int v19; // r6
  const char *v20; // r3
  __int64 v21; // r10
  int v22; // r8
  int v23; // r7
  int v24; // r6
  int *v25; // r29
  int v26; // r11
  int v27; // [sp+50h] [-80h] BYREF
  idSort_Quick<int,idSort_ClassVariableInfoBySize> v28[2]; // [sp+58h] [-78h] BYREF
  idSort_Quick<int,idSort_ClassVariableInfoByName> v29[4]; // [sp+60h] [-70h] BYREF
  idList<enum encounterGroupRole_t,5> v30[6]; // [sp+70h] [-60h] BYREF

  v1 = 0;
  memset(v30, 0, 14);
  v30[0].listStatic = 0;
  v30[0].memTag = 5;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v30);
  idLib::Printf(fmt: "%-48s : %-48s : size (B)\n", "type", "name");
  v3 = 0;
  if ( classTypeInfo[0].name != nullptr )
  {
    v4 = 0;
    while ( 1 )
    {
      if ( classTypeInfo[v4].variables != nullptr )
      {
        v5 = &classTypeInfo[v4];
        v6 = idCmdArgs::Argv(this: args, arg: 1);
        if ( idStr::Icmp(s1: v5->name, s2: v6) == 0 )
          break;
      }
      v4 = ++v3;
      if ( classTypeInfo[v3].name == nullptr )
        goto LABEL_6;
    }
    variables = v5->variables;
    v27 = 0;
    if ( variables->name != nullptr )
    {
      do
      {
        idList<idAnimWebBlendTree *,5>::Append(this: v30, obj: (encounterGroupRole_t *)&v27);
        ++v1;
        v9 = v5->variables;
        v27 = v1;
      }
      while ( v9[v1].name != nullptr );
    }
    argc = args->argc;
    num = v30[0].num;
    list = (int *)v30[0].list;
    v13 = args->argc > 2;
    v27 = args->argc;
    if ( v13 )
    {
      if ( argc <= 2 )
        v14 = &byte_8200D768;
      else
        v14 = args->argv[2];
      if ( idStr::Icmp(s1: v14, s2: "size") != 0 )
      {
        if ( args->argc <= 2 )
          v20 = &byte_8200D768;
        else
          v20 = args->argv[2];
        if ( idStr::Icmp(s1: v20, s2: "name") == 0 )
        {
          v29[1].__vftable = (idSort_Quick<int,idSort_ClassVariableInfoByName>_vtbl *)v5;
          v29[0].__vftable = (idSort_Quick<int,idSort_ClassVariableInfoByName>_vtbl *)&idSort_ClassVariableInfoByName::`vftable';
          if ( list != nullptr )
            idSort_Quick<int,idSort_ClassVariableInfoByName>::Sort(
              this: v29,
              base: list,
              num,
              a4: v24,
              a5: v23,
              a6: v22,
              a7: v21);
          v29[0].__vftable = (idSort_Quick<int,idSort_ClassVariableInfoByName>_vtbl *)&idSort<int>::`vftable';
        }
      }
      else
      {
        v28[1].__vftable = (idSort_Quick<int,idSort_ClassVariableInfoBySize>_vtbl *)v5;
        v28[0].__vftable = (idSort_Quick<int,idSort_ClassVariableInfoBySize>_vtbl *)&idSort_ClassVariableInfoBySize::`vftable';
        if ( list != nullptr )
          idSort_Quick<int,idSort_ClassVariableInfoBySize>::Sort(
            this: v28,
            base: list,
            num,
            a4: v19,
            a5: v18,
            a6: v17,
            a7: v16);
        v28[0].__vftable = (idSort_Quick<int,idSort_ClassVariableInfoBySize>_vtbl *)&idSort<int>::`vftable';
      }
    }
    if ( num > 0 )
    {
      v25 = list - 1;
      do
      {
        v26 = (int)&v5->variables[*++v25];
        idLib::Printf(
          fmt: "%-48s : %-48s : %d\n",
          *(const char **)v26,
          *(const char **)(v26 + 8),
          *(_DWORD *)(v26 + 16));
        --num;
      }
      while ( num != 0 );
    }
    idLib::Printf(fmt: "-------------------------\n");
    idLib::Printf(fmt: "total size = %5d bytes\n", v5->size);
    if ( (v30[0].listStatic == 0 || v30[0].listStatic == 2) && list != nullptr )
    {
      v15 = (encounterGroupRole_t *)list;
LABEL_37:
      idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
    }
  }
  else
  {
LABEL_6:
    if ( args->argc <= 1 )
      v7 = &byte_8200D768;
    else
      v7 = args->argv[1];
    idLib::Printf(fmt: "class %s not found\n", v7);
    if ( v30[0].listStatic == 0 || v30[0].listStatic == 2 )
    {
      v15 = v30[0].list;
      if ( v30[0].list != nullptr )
        goto LABEL_37;
    }
  }
}


// ========================================================================
// __unwind$509050
// EA  : 0x82D64164
// RVA : 0x00D64164
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509050()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$509051
// EA  : 0x82D6418C
// RVA : 0x00D6418C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509051()
{
  int v0; // r12

  idSort_EntryDepthAndTicks::~idSort_EntryDepthAndTicks(this: (idSort_AnimEventSort *)(v0 - 208 + 88));
}


// ========================================================================
// __unwind$509052
// EA  : 0x82D641B4
// RVA : 0x00D641B4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509052()
{
  int v0; // r12

  idSort_EntryDepthAndTicks::~idSort_EntryDepthAndTicks(this: (idSort_AnimEventSort *)(v0 - 208 + 96));
}


// ========================================================================
// ?AddRenderModelReference@idGameState@@SAXPBVidRenderModel@@@Z
// EA  : 0x82D64290
// RVA : 0x00D64290
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall idGameState::AddRenderModelReference(
        const idRenderModel *rm,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        const idRenderModel *a12)
{
  int v12; // r11
  const idRenderModel **list; // r10

  a12 = rm;
  v12 = 0;
  if ( idGameState::referencedModels.num <= 0 )
    goto LABEL_7;
  list = idGameState::referencedModels.list;
  while ( *list != rm )
  {
    ++v12;
    ++list;
    if ( v12 >= idGameState::referencedModels.num )
      goto LABEL_7;
  }
  if ( v12 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&idGameState::referencedModels,
      obj: (encounterGroupRole_t *)&a12);
}


// ========================================================================
// ?WriteList@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D64308
// RVA : 0x00D64308
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteList(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v33; // r6
  const char *v34; // r7
  const classVariableInfo_t *templateParms; // r25
  void *v36; // [sp+8h] [-A8h]
  int v37; // [sp+Ch] [-A4h]
  idPLogScope v38[10]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "WriteList");
  LODWORD(v33) = "WriteList";
  HIDWORD(v33) = 2;
  idPLogScope::idPLogScope(this: v38, pl: &pLog, gMask: v33, label: v34);
  templateParms = idTypeInfoTools::FindClassInfo(this: ti, typeName: varType)->templateParms;
  idTypeInfoFile::WriteOpeningBrace(this: file);
  idTypeInfoFile::WriteComment(this: file, comment);
  idTypeInfoFile::WriteType(this: file, type: "int", ops: &byte_8200D768, name: "num");
  idTypeInfoFile::WriteInt(this: file, l: *(_DWORD *)(a28 + 4));
  idTypeInfoTools::WriteArray(
    this: ti,
    file,
    scope,
    varType: templateParms->type,
    varOps: templateParms->ops,
    varName: "item",
    varFlags: templateParms->flags,
    comment: &byte_8200D768,
    varPtr: v36,
    num: v37);
  idTypeInfoFile::WriteClosingBrace(this: file);
  idPLogScope::~idPLogScope(this: v38);
  RD_EventEnd();
}


// ========================================================================
// __unwind$509559
// EA  : 0x82D64404
// RVA : 0x00D64404
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509559()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 104));
}


// ========================================================================
// __unwind$509560
// EA  : 0x82D6442C
// RVA : 0x00D6442C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509560()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 96));
}


// ========================================================================
// ?ReadList@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D64460
// RVA : 0x00D64460
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadList(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v32; // r6
  const char *v33; // r7
  const classVariableInfo_t *templateParms; // r29
  const char *ops; // r4
  const char *type; // r3
  BOOL IsUninitializedType; // r3
  int v38; // r3
  unsigned int v39; // r11
  void *v40; // [sp+8h] [-B8h]
  int v41; // [sp+Ch] [-B4h]
  unsigned int v42; // [sp+60h] [-60h] BYREF
  idPLogScope v43[11]; // [sp+68h] [-58h] BYREF

  RD_EventBegin(name: "ReadList");
  LODWORD(v32) = "ReadList";
  HIDWORD(v32) = 2;
  idPLogScope::idPLogScope(this: v43, pl: &pLog, gMask: v32, label: v33);
  templateParms = idTypeInfoTools::FindClassInfo(this: ti, typeName: varType)->templateParms;
  idTypeInfoFile::ReadOpeningBrace(this: file);
  if ( idTypeInfoFile::CheckType(this: file, type: "int", ops: &byte_8200D768, name: "num") )
  {
    idTypeInfoFile::ReadUnsignedLong(this: file, l: &v42);
    ops = templateParms->ops;
    type = templateParms->type;
    v42 &= (v42 == 0) + (v42 >> 31) - 1;
    IsUninitializedType = idTypeInfoTools::IsUninitializedType(type, ops);
    v38 = (int)templateParms->reallocate(
                 a1: *(void **)a28,
                 a2: *(_DWORD *)(a28 + 4),
                 a3: v42,
                 a4: (memTag_t)*(unsigned __int8 *)(a28 + 14),
                 a5: IsUninitializedType);
    v39 = v42;
    *(_DWORD *)a28 = v38;
    *(_DWORD *)(a28 + 8) = v39;
    *(_DWORD *)(a28 + 4) = v39;
  }
  idTypeInfoTools::ReadArray(
    this: ti,
    file,
    scope,
    varType: templateParms->type,
    varOps: templateParms->ops,
    varName: "item",
    varFlags: templateParms->flags,
    comment: &byte_8200D768,
    varPtr: v40,
    num: v41);
  idTypeInfoFile::ReadClosingBrace(this: file);
  idPLogScope::~idPLogScope(this: v43);
  RD_EventEnd();
}


// ========================================================================
// __unwind$509598
// EA  : 0x82D645AC
// RVA : 0x00D645AC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509598()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$509599
// EA  : 0x82D645D4
// RVA : 0x00D645D4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509599()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 104));
}


// ========================================================================
// ?WriteStaticList@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D64608
// RVA : 0x00D64608
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteStaticList(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v33; // r6
  const char *v34; // r7
  const classVariableInfo_t *templateParms; // r25
  void *v36; // [sp+8h] [-A8h]
  int v37; // [sp+Ch] [-A4h]
  idPLogScope v38[10]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "WriteStaticList");
  LODWORD(v33) = "WriteStaticList";
  HIDWORD(v33) = 2;
  idPLogScope::idPLogScope(this: v38, pl: &pLog, gMask: v33, label: v34);
  templateParms = idTypeInfoTools::FindClassInfo(this: ti, typeName: varType)->templateParms;
  idTypeInfoFile::WriteOpeningBrace(this: file);
  idTypeInfoFile::WriteComment(this: file, comment);
  idTypeInfoFile::WriteType(this: file, type: "int", ops: &byte_8200D768, name: "num");
  idTypeInfoFile::WriteInt(this: file, l: *(_DWORD *)(a28 + 4));
  idTypeInfoTools::WriteArray(
    this: ti,
    file,
    scope,
    varType: templateParms->type,
    varOps: templateParms->ops,
    varName: "item",
    varFlags: templateParms->flags,
    comment: &byte_8200D768,
    varPtr: v36,
    num: v37);
  idTypeInfoFile::WriteClosingBrace(this: file);
  idPLogScope::~idPLogScope(this: v38);
  RD_EventEnd();
}


// ========================================================================
// __unwind$509644
// EA  : 0x82D64704
// RVA : 0x00D64704
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509644()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 104));
}


// ========================================================================
// __unwind$509645
// EA  : 0x82D6472C
// RVA : 0x00D6472C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509645()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 96));
}


// ========================================================================
// ?ReadStaticList@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D64760
// RVA : 0x00D64760
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadStaticList(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v32; // r6
  const char *v33; // r7
  const classVariableInfo_t *templateParms; // r29
  void *v35; // [sp+8h] [-A8h]
  int v36; // [sp+Ch] [-A4h]
  idPLogScope v37[10]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "ReadStaticList");
  LODWORD(v32) = "ReadStaticList";
  HIDWORD(v32) = 2;
  idPLogScope::idPLogScope(this: v37, pl: &pLog, gMask: v32, label: v33);
  templateParms = idTypeInfoTools::FindClassInfo(this: ti, typeName: varType)->templateParms;
  idTypeInfoFile::ReadOpeningBrace(this: file);
  if ( idTypeInfoFile::CheckType(this: file, type: "int", ops: &byte_8200D768, name: "num") )
    idTypeInfoFile::ReadUnsignedLong(this: file, l: (unsigned int *)(a28 + 4));
  idTypeInfoTools::ReadArray(
    this: ti,
    file,
    scope,
    varType: templateParms->type,
    varOps: templateParms->ops,
    varName: "item",
    varFlags: templateParms->flags,
    comment: &byte_8200D768,
    varPtr: v35,
    num: v36);
  idTypeInfoFile::ReadClosingBrace(this: file);
  idPLogScope::~idPLogScope(this: v37);
  RD_EventEnd();
}


// ========================================================================
// __unwind$509683
// EA  : 0x82D64858
// RVA : 0x00D64858
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509683()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 104));
}


// ========================================================================
// __unwind$509684
// EA  : 0x82D64880
// RVA : 0x00D64880
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509684()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 96));
}


// ========================================================================
// ?WriteScriptObject@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D648B0
// RVA : 0x00D648B0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteScriptObject(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idScriptObject *a28)
{
  unsigned __int64 v30; // r6
  const char *v31; // r7
  idPLogScope v32[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "WriteScriptObject");
  LODWORD(v30) = "WriteScriptObject";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: v32, pl: &pLog, gMask: v30, label: v31);
  idTypeInfoFile::WriteOpeningBrace(this: file);
  idTypeInfoFile::WriteComment(this: file, comment);
  idScriptObject::Write(this: a28, file, writeEditables: false);
  idTypeInfoFile::WriteClosingBrace(this: file);
  idPLogScope::~idPLogScope(this: v32);
  RD_EventEnd();
}


// ========================================================================
// __unwind$509722
// EA  : 0x82D64930
// RVA : 0x00D64930
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509722()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$509723
// EA  : 0x82D64958
// RVA : 0x00D64958
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509723()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?ReadScriptObject@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D64988
// RVA : 0x00D64988
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadScriptObject(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idScriptObject *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idPLogScope v31[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "ReadScriptObject");
  LODWORD(v29) = "ReadScriptObject";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v31, pl: &pLog, gMask: v29, label: v30);
  if ( file->settings.skipScriptObjects )
  {
    idTypeInfoFile::ReadUnknown(this: file);
  }
  else
  {
    idTypeInfoFile::ReadOpeningBrace(this: file);
    idScriptObject::Read(this: a28, file);
    idTypeInfoFile::ReadClosingBrace(this: file);
  }
  idPLogScope::~idPLogScope(this: v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$509753
// EA  : 0x82D64A14
// RVA : 0x00D64A14
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509753()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$509754
// EA  : 0x82D64A3C
// RVA : 0x00D64A3C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509754()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?WriteDecl@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D64A70
// RVA : 0x00D64A70
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteDecl(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v30; // r6
  const char *v31; // r7
  idPLogScope v32[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "WriteDecl");
  LODWORD(v30) = "WriteDecl";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: v32, pl: &pLog, gMask: v30, label: v31);
  idTypeInfoFile::WriteStr(this: file, s: *(const char **)(*(_DWORD *)a28 + 8));
  idTypeInfoFile::WriteComment(this: file, comment);
  idPLogScope::~idPLogScope(this: v32);
  RD_EventEnd();
}


// ========================================================================
// __unwind$509791
// EA  : 0x82D64AE4
// RVA : 0x00D64AE4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509791()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$509792
// EA  : 0x82D64B0C
// RVA : 0x00D64B0C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509792()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?ReadDecl@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D64B40
// RVA : 0x00D64B40
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadDecl(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idDecl **a28)
{
  unsigned __int64 v30; // r6
  const char *v31; // r7
  idDeclInfo *v32; // r3
  idDeclInfoTemplate<idDeclEntityDef> *v33; // r27
  const idDecl *v34; // r28
  int i; // r30
  idDeclInfo *v36; // r3
  idGameLocal_vtbl *v37; // r29
  idTypeInfoSettings *v38; // r3
  idEntity *v39; // r3
  idEntity *v40; // r29
  idPLog *pLog; // r29
  idPLog::logEntry_t *v42; // r30
  int v43; // r3
  __int64 totalTicks; // r11
  __int64 v45; // r9
  idPLogScope v46; // [sp+50h] [-80h] BYREF
  idTypeInfoSettings v47[2]; // [sp+58h] [-78h] BYREF
  idStr v48[3]; // [sp+70h] [-60h] BYREF

  RD_EventBegin(name: "ReadDecl");
  LODWORD(v30) = "ReadDecl";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: &v46, pl: &::pLog, gMask: v30, label: v31);
  v32 = declManager->GetDeclTypeFromClassname(this: declManager, a2: varType);
  v48[0].len = 0;
  v48[0].baseBuffer[0] = 0;
  v33 = (idDeclInfoTemplate<idDeclEntityDef> *)v32;
  v48[0].allocedAndFlag = 20;
  v48[0].data = v48[0].baseBuffer;
  idTypeInfoFile::ReadStr(this: file, s: v48);
  v34 = nullptr;
  if ( v33 != nullptr )
  {
    if ( v48[0].data != nullptr )
      v34 = idDeclInfo::FindWithInheritance(this: v33, name: v48[0].data, makeDefault: true);
    else
      v34 = nullptr;
  }
  else
  {
    for ( i = 0; i < declManager->GetNumDeclTypes(this: declManager); ++i )
    {
      v36 = declManager->GetDeclType_2(this: declManager, a2: i);
      v33 = (idDeclInfoTemplate<idDeclEntityDef> *)v36;
      if ( v48[0].data != nullptr )
      {
        v34 = idDeclInfo::FindWithInheritance(this: v36, name: v48[0].data, makeDefault: false);
        if ( v34 != nullptr )
          break;
      }
      else
      {
        v34 = nullptr;
      }
    }
  }
  *a28 = v34;
  if ( idLib::AvoidLinkErrorGetProduction() == PROD_DEVELOPMENT
    && gameLocal != nullptr
    && idGameLocal::GameState(this: gameLocal) != GAMESTATE_ACTIVE
    && v33 == &idDeclEntityDef::resourceList
    && (gameLocal->GetGameFlags(this: gameLocal) & 2) == 0 )
  {
    v37 = gameLocal->__vftable;
    v38 = idTypeInfoSettings::idTypeInfoSettings(this: v47);
    v39 = v37->CreateEntityFromDef(this: gameLocal, a2: v34, a3: v38);
    v40 = v39;
    if ( v39 != nullptr )
    {
      idEntity::ReferenceDefaultPhysics(this: v39);
      gameLocal->DeleteEntity(this: gameLocal, a2: v40);
    }
  }
  idStr::FreeData(this: v48);
  if ( v46.logIndex >= 0 )
  {
    pLog = v46.pLog;
    v42 = &v46.pLog->logEntries.list[v46.logIndex];
    v43 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v42->totalTicks;
    HIDWORD(totalTicks) = v42->parent;
    LODWORD(v45) = v43 - totalTicks;
    v42->totalTicks = v45;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$509832
// EA  : 0x82D64D7C
// RVA : 0x00D64D7C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509832()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 144));
}


// ========================================================================
// __unwind$509833
// EA  : 0x82D64DA4
// RVA : 0x00D64DA4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509833()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$509834
// EA  : 0x82D64DCC
// RVA : 0x00D64DCC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509834()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?WriteCollisionModel@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D64E00
// RVA : 0x00D64E00
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteCollisionModel(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v30; // r6
  const char *v31; // r7
  idPLogScope v32[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "WriteCollisionModel");
  LODWORD(v30) = "WriteCollisionModel";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: v32, pl: &pLog, gMask: v30, label: v31);
  idTypeInfoFile::WriteStr(this: file, s: *(const char **)(*(_DWORD *)a28 + 8));
  idTypeInfoFile::WriteComment(this: file, comment);
  idPLogScope::~idPLogScope(this: v32);
  RD_EventEnd();
}


// ========================================================================
// __unwind$509935
// EA  : 0x82D64E74
// RVA : 0x00D64E74
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509935()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$509936
// EA  : 0x82D64E9C
// RVA : 0x00D64E9C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509936()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?ReadCollisionModel@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D64ED0
// RVA : 0x00D64ED0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadCollisionModel(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        _DWORD *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idPLogScope v31[2]; // [sp+50h] [-60h] BYREF
  idStr v32[2]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "ReadCollisionModel");
  LODWORD(v29) = "ReadCollisionModel";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v31, pl: &pLog, gMask: v29, label: v30);
  v32[0].len = 0;
  v32[0].allocedAndFlag = 20;
  v32[0].data = v32[0].baseBuffer;
  v32[0].baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: v32);
  *a28 = idCollisionModelManager::LoadModel(this: collisionModelManager, modelName: v32[0].data);
  idStr::FreeData(this: v32);
  idPLogScope::~idPLogScope(this: v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$509975
// EA  : 0x82D64F68
// RVA : 0x00D64F68
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509975()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 128));
}


// ========================================================================
// __unwind$509976
// EA  : 0x82D64F90
// RVA : 0x00D64F90
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509976()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$509977
// EA  : 0x82D64FB8
// RVA : 0x00D64FB8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_509977()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?WriteStaticModel@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D64FE8
// RVA : 0x00D64FE8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteStaticModel(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v30; // r6
  const char *v31; // r7
  const char *v32; // r4
  idTypeInfoFile *v33; // r3
  idPLogScope v34[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "WriteStaticModel");
  LODWORD(v30) = "WriteStaticModel";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: v34, pl: &pLog, gMask: v30, label: v31);
  if ( *(_DWORD *)a28 != 0 )
  {
    v32 = *(const char **)(*(_DWORD *)a28 + 8);
    v33 = file;
  }
  else
  {
    v33 = file;
    v32 = &byte_8200D768;
  }
  idTypeInfoFile::WriteStr(this: v33, s: v32);
  idTypeInfoFile::WriteComment(this: file, comment);
  idPLogScope::~idPLogScope(this: v34);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510046
// EA  : 0x82D65074
// RVA : 0x00D65074
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510046()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$510047
// EA  : 0x82D6509C
// RVA : 0x00D6509C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510047()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?ReadStaticModel@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D650D0
// RVA : 0x00D650D0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadStaticModel(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        _DWORD *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idPLogScope v31[2]; // [sp+50h] [-60h] BYREF
  idStr v32[2]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "ReadStaticModel");
  LODWORD(v29) = "ReadStaticModel";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v31, pl: &pLog, gMask: v29, label: v30);
  v32[0].len = 0;
  v32[0].allocedAndFlag = 20;
  v32[0].data = v32[0].baseBuffer;
  v32[0].baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: v32);
  if ( v32[0].len != 0 )
    *a28 = staticModelManager->FindStaticModel(this: staticModelManager, a2: v32[0].data, a3: false);
  else
    *a28 = 0;
  idStr::FreeData(this: v32);
  idPLogScope::~idPLogScope(this: v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510087
// EA  : 0x82D65190
// RVA : 0x00D65190
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510087()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 128));
}


// ========================================================================
// __unwind$510088
// EA  : 0x82D651B8
// RVA : 0x00D651B8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510088()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$510089
// EA  : 0x82D651E0
// RVA : 0x00D651E0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510089()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?WriteSWF@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D65210
// RVA : 0x00D65210
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteSWF(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const char ***a28)
{
  unsigned __int64 v30; // r6
  const char *v31; // r7
  const char *v32; // r4
  idTypeInfoFile *v33; // r3
  idPLogScope v34[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "WriteSWF");
  LODWORD(v30) = "WriteSWF";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: v34, pl: &pLog, gMask: v30, label: v31);
  if ( *a28 != nullptr )
  {
    v32 = **a28;
    v33 = file;
  }
  else
  {
    v33 = file;
    v32 = &byte_8200D768;
  }
  idTypeInfoFile::WriteStr(this: v33, s: v32);
  idTypeInfoFile::WriteComment(this: file, comment);
  idPLogScope::~idPLogScope(this: v34);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510161_0
// EA  : 0x82D6529C
// RVA : 0x00D6529C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510161_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$510162_0
// EA  : 0x82D652C4
// RVA : 0x00D652C4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510162_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?ReadSWF@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D652F8
// RVA : 0x00D652F8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadSWF(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idSWF **a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idSWF *v31; // r3
  idSWF *v32; // r3
  idPLogScope v33; // [sp+58h] [-58h] BYREF
  idStr v34[2]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "ReadSWF");
  LODWORD(v29) = "ReadSWF";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: &v33, pl: &pLog, gMask: v29, label: v30);
  v34[0].len = 0;
  v34[0].allocedAndFlag = 20;
  v34[0].data = v34[0].baseBuffer;
  v34[0].baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: v34);
  if ( v34[0].len != 0 )
  {
    v31 = (idSWF *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                     size: 0x27Cu,
                     tag: TAG_NEW,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
    if ( v31 != nullptr )
    {
      if ( clientGame != nullptr )
        v32 = idSWF::idSWF(this: v31, filename_: v34[0].data, soundWorld: clientGame->soundWorld, atlasPurgable_: true);
      else
        v32 = idSWF::idSWF(this: v31, filename_: v34[0].data, soundWorld: nullptr, atlasPurgable_: true);
    }
    else
    {
      v32 = nullptr;
    }
    *a28 = v32;
  }
  else
  {
    *a28 = nullptr;
  }
  idStr::FreeData(this: v34);
  idPLogScope::~idPLogScope(this: &v33);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510203
// EA  : 0x82D65408
// RVA : 0x00D65408
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510203()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 128));
}


// ========================================================================
// __unwind$510204
// EA  : 0x82D65430
// RVA : 0x00D65430
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510204()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$510205
// EA  : 0x82D65458
// RVA : 0x00D65458
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510205()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$510206
// EA  : 0x82D65480
// RVA : 0x00D65480
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall _unwind_510206(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 80), tag: a2);
}


// ========================================================================
// ?WriteSWFFile@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D654B0
// RVA : 0x00D654B0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteSWFFile(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        char **a28)
{
  unsigned __int64 v30; // r6
  const char *v31; // r7
  char *v32; // r4
  char v33; // r11
  idPLogScope v34[7]; // [sp+58h] [-38h] BYREF

  RD_EventBegin(name: "WriteSWFFile");
  LODWORD(v30) = "WriteSWFFile";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: v34, pl: &pLog, gMask: v30, label: v31);
  v32 = *a28;
  if ( *a28 == &byte_8200D768 || (v33 = 0, *v32 == 0) )
    v33 = 1;
  if ( v33 != 0 )
    v32 = &byte_8200D768;
  idTypeInfoFile::WriteStr(this: file, s: v32);
  idTypeInfoFile::WriteComment(this: file, comment);
  idPLogScope::~idPLogScope(this: v34);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510288
// EA  : 0x82D65564
// RVA : 0x00D65564
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510288()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$510289
// EA  : 0x82D6558C
// RVA : 0x00D6558C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510289()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 88));
}


// ========================================================================
// ?ReadSWFFile@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D655C0
// RVA : 0x00D655C0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadSWFFile(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idAtomicString *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idSWF *v31; // r30
  idSWF *v32; // r3
  idSoundWorld *soundWorld; // r5
  idPLogScope v34; // [sp+58h] [-58h] BYREF
  idStr v35[2]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "ReadSWFFile");
  LODWORD(v29) = "ReadSWFFile";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: &v34, pl: &pLog, gMask: v29, label: v30);
  v31 = nullptr;
  v35[0].len = 0;
  v35[0].allocedAndFlag = 20;
  v35[0].data = v35[0].baseBuffer;
  v35[0].baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: v35);
  idAtomicString::Set(this: a28, str_: v35[0].data);
  if ( v35[0].len != 0 && idLib::AvoidLinkErrorGetProduction() == PROD_DEVELOPMENT )
  {
    v32 = (idSWF *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                     size: 0x27Cu,
                     tag: TAG_NEW,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
    if ( v32 != nullptr )
    {
      if ( clientGame != nullptr )
        soundWorld = clientGame->soundWorld;
      else
        soundWorld = nullptr;
      v31 = idSWF::idSWF(this: v32, filename_: v35[0].data, soundWorld, atlasPurgable_: true);
    }
    if ( v31 != nullptr )
    {
      idSWF::~idSWF(this: v31);
      idMem::Free(this: &mem, ptr: v31, align: ALIGN_16);
    }
  }
  idStr::FreeData(this: v35);
  idPLogScope::~idPLogScope(this: &v34);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510341
// EA  : 0x82D656E8
// RVA : 0x00D656E8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510341()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 128));
}


// ========================================================================
// __unwind$510342
// EA  : 0x82D65710
// RVA : 0x00D65710
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510342()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$510343
// EA  : 0x82D65738
// RVA : 0x00D65738
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510343()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$510344
// EA  : 0x82D65760
// RVA : 0x00D65760
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall _unwind_510344(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 80), tag: a2);
}


// ========================================================================
// ?WriteInGameVideoFile@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D65790
// RVA : 0x00D65790
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteInGameVideoFile(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idTypeInfoFile *v31; // r3
  const char *v32; // r4
  idPLogScope v33[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "WriteInGameVideoFile");
  LODWORD(v29) = "WriteInGameVideoFile";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v33, pl: &pLog, gMask: v29, label: v30);
  if ( *(_DWORD *)a28 != 0 )
  {
    v32 = *(const char **)(*(_DWORD *)a28 + 8);
    v31 = file;
  }
  else
  {
    v31 = file;
    v32 = &byte_8200D768;
  }
  idTypeInfoFile::WriteStr(this: v31, s: v32);
  idPLogScope::~idPLogScope(this: v33);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510443
// EA  : 0x82D6580C
// RVA : 0x00D6580C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510443()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$510444
// EA  : 0x82D65834
// RVA : 0x00D65834
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510444()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?ReadInGameVideoFile@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D65868
// RVA : 0x00D65868
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadInGameVideoFile(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idResource **a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idPLogScope v31[2]; // [sp+50h] [-60h] BYREF
  idStr v32[2]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "ReadInGameVideoFile");
  LODWORD(v29) = "ReadInGameVideoFile";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v31, pl: &pLog, gMask: v29, label: v30);
  v32[0].len = 0;
  v32[0].allocedAndFlag = 20;
  v32[0].data = v32[0].baseBuffer;
  v32[0].baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: v32);
  *a28 = idResourceList::Load(
           this: &idInGameVideoFile::resourceList,
           name: v32[0].data,
           makeDefault: true,
           skipStaleCheck: false);
  idStr::FreeData(this: v32);
  idPLogScope::~idPLogScope(this: v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510484
// EA  : 0x82D65908
// RVA : 0x00D65908
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510484()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 128));
}


// ========================================================================
// __unwind$510485
// EA  : 0x82D65930
// RVA : 0x00D65930
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510485()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$510486
// EA  : 0x82D65958
// RVA : 0x00D65958
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510486()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?WriteRandomValue@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D65988
// RVA : 0x00D65988
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteRandomValue(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        float *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  long double v31; // fp2
  long double v32; // fp2
  long double v33; // fp2
  long double v34; // fp2
  idPLogScope v35[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "WriteRandomValue");
  LODWORD(v29) = "WriteRandomValue";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v35, pl: &pLog, gMask: v29, label: v30);
  if ( !file->settings.writeType && (*(double *)&v31 = *a28, *(double *)&v31 == a28[1]) && a28[2] == 0.0 )
  {
    idTypeInfoFile::WriteFloat(this: file, d: v31);
  }
  else
  {
    idTypeInfoFile::WriteOpeningBrace(this: file);
    idTypeInfoFile::WriteType(this: file, type: "float", ops: &byte_8200D768, name: "min");
    *(double *)&v32 = *a28;
    idTypeInfoFile::WriteFloat(this: file, d: v32);
    idTypeInfoFile::WriteType(this: file, type: "float", ops: &byte_8200D768, name: "max");
    *(double *)&v33 = a28[1];
    idTypeInfoFile::WriteFloat(this: file, d: v33);
    idTypeInfoFile::WriteType(this: file, type: "float", ops: &byte_8200D768, name: "granularity");
    *(double *)&v34 = a28[2];
    idTypeInfoFile::WriteFloat(this: file, d: v34);
    idTypeInfoFile::WriteClosingBrace(this: file);
  }
  idPLogScope::~idPLogScope(this: v35);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510558
// EA  : 0x82D65AA4
// RVA : 0x00D65AA4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510558()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$510559
// EA  : 0x82D65ACC
// RVA : 0x00D65ACC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510559()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?ReadRandomValue@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D65B00
// RVA : 0x00D65B00
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadRandomValue(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        float *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idPLogScope v31[2]; // [sp+50h] [-C0h] BYREF
  idStr v32; // [sp+60h] [-B0h] BYREF
  idStr v33; // [sp+80h] [-90h] BYREF
  idStr v34[3]; // [sp+A0h] [-70h] BYREF

  RD_EventBegin(name: "ReadRandomValue");
  LODWORD(v29) = "ReadRandomValue";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v31, pl: &pLog, gMask: v29, label: v30);
  if ( idTypeInfoFile::CheckOpeningBrace(this: file) )
  {
    while ( !idTypeInfoFile::CheckClosingBrace(this: file) )
    {
      v34[0].allocedAndFlag = 20;
      v34[0].len = 0;
      v34[0].data = v34[0].baseBuffer;
      v34[0].baseBuffer[0] = 0;
      v33.allocedAndFlag = 20;
      v33.data = v33.baseBuffer;
      v33.len = 0;
      v33.baseBuffer[0] = 0;
      v32.allocedAndFlag = 20;
      v32.data = v32.baseBuffer;
      v32.len = 0;
      v32.baseBuffer[0] = 0;
      idTypeInfoFile::ReadType(this: file, type: v34, ops: &v33, name: &v32);
      if ( idStr::Cmp(s1: v32.data, s2: "min") != 0 )
      {
        if ( idStr::Cmp(s1: v32.data, s2: "max") != 0 )
        {
          if ( idStr::Cmp(s1: v32.data, s2: "granularity") != 0 )
            idTypeInfoFile::ReadUnknown(this: file);
          else
            idTypeInfoFile::ReadFloat(this: file, f: a28 + 2);
        }
        else
        {
          idTypeInfoFile::ReadFloat(this: file, f: a28 + 1);
        }
      }
      else
      {
        idTypeInfoFile::ReadFloat(this: file, f: a28);
      }
      idStr::FreeData(this: &v32);
      idStr::FreeData(this: &v33);
      idStr::FreeData(this: v34);
    }
  }
  else
  {
    idTypeInfoFile::ReadFloat(this: file, f: a28);
    a28[2] = 0.0;
    a28[1] = *a28;
  }
  idPLogScope::~idPLogScope(this: v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510591
// EA  : 0x82D65CAC
// RVA : 0x00D65CAC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510591()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 192));
}


// ========================================================================
// __unwind$510592
// EA  : 0x82D65CD4
// RVA : 0x00D65CD4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510592()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$510593
// EA  : 0x82D65CFC
// RVA : 0x00D65CFC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510593()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 160));
}


// ========================================================================
// __unwind$510594
// EA  : 0x82D65D24
// RVA : 0x00D65D24
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510594()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$510595
// EA  : 0x82D65D4C
// RVA : 0x00D65D4C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510595()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// ?WriteTypesafeFloat@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D65D80
// RVA : 0x00D65D80
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteTypesafeFloat(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        float *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  long double v31; // fp2
  idPLogScope v32[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "WriteTypesafeFloat");
  LODWORD(v29) = "WriteTypesafeFloat";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v32, pl: &pLog, gMask: v29, label: v30);
  idTypeInfoFile::WriteOpeningBrace(this: file);
  idTypeInfoFile::WriteType(this: file, type: "float", ops: &byte_8200D768, name: "value");
  *(double *)&v31 = *a28;
  idTypeInfoFile::WriteFloat(this: file, d: v31);
  idTypeInfoFile::WriteClosingBrace(this: file);
  idPLogScope::~idPLogScope(this: v32);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510727
// EA  : 0x82D65E10
// RVA : 0x00D65E10
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510727()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$510728
// EA  : 0x82D65E38
// RVA : 0x00D65E38
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510728()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?ReadTypesafeFloat@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D65E68
// RVA : 0x00D65E68
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadTypesafeFloat(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        float *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idPLogScope v31[2]; // [sp+50h] [-A0h] BYREF
  idStr v32; // [sp+60h] [-90h] BYREF
  idStr v33; // [sp+80h] [-70h] BYREF
  idStr v34[2]; // [sp+A0h] [-50h] BYREF

  RD_EventBegin(name: "ReadTypesafeFloat");
  LODWORD(v29) = "ReadTypesafeFloat";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v31, pl: &pLog, gMask: v29, label: v30);
  if ( idTypeInfoFile::CheckOpeningBrace(this: file) )
  {
    v34[0].len = 0;
    v34[0].allocedAndFlag = 20;
    v34[0].data = v34[0].baseBuffer;
    v34[0].baseBuffer[0] = 0;
    v33.allocedAndFlag = 20;
    v33.data = v33.baseBuffer;
    v33.len = 0;
    v33.baseBuffer[0] = 0;
    v32.allocedAndFlag = 20;
    v32.data = v32.baseBuffer;
    v32.len = 0;
    v32.baseBuffer[0] = 0;
    idTypeInfoFile::ReadType(this: file, type: v34, ops: &v33, name: &v32);
    if ( idStr::Cmp(s1: v32.data, s2: "value") != 0 )
      idTypeInfoFile::ReadUnknown(this: file);
    else
      idTypeInfoFile::ReadFloat(this: file, f: a28);
    idTypeInfoFile::ReadClosingBrace(this: file);
    idStr::FreeData(this: &v32);
    idStr::FreeData(this: &v33);
    idStr::FreeData(this: v34);
  }
  else
  {
    idTypeInfoFile::ReadFloat(this: file, f: a28);
  }
  idPLogScope::~idPLogScope(this: v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510762
// EA  : 0x82D65F80
// RVA : 0x00D65F80
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510762()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 192));
}


// ========================================================================
// __unwind$510763
// EA  : 0x82D65FA8
// RVA : 0x00D65FA8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510763()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$510764
// EA  : 0x82D65FD0
// RVA : 0x00D65FD0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510764()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 160));
}


// ========================================================================
// __unwind$510765
// EA  : 0x82D65FF8
// RVA : 0x00D65FF8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510765()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$510766
// EA  : 0x82D66020
// RVA : 0x00D66020
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510766()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// ?WriteBoundedIntBase@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D66050
// RVA : 0x00D66050
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteBoundedIntBase(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  int v31; // r3
  idPLogScope v32[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "WriteBoundedIntBase");
  LODWORD(v29) = "WriteBoundedIntBase";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v32, pl: &pLog, gMask: v29, label: v30);
  v31 = (*(int (__fastcall **)(int))(*(_DWORD *)a28 + 4))(a1: a28);
  idTypeInfoFile::WriteInt(this: file, l: v31);
  idPLogScope::~idPLogScope(this: v32);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510896
// EA  : 0x82D660C0
// RVA : 0x00D660C0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510896()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$510897
// EA  : 0x82D660E8
// RVA : 0x00D660E8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510897()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?ReadBoundedIntBase@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D66118
// RVA : 0x00D66118
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadBoundedIntBase(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        void (__fastcall ***a28)(_DWORD, unsigned int))
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  unsigned int v31; // [sp+50h] [-40h] BYREF
  idPLogScope v32[7]; // [sp+58h] [-38h] BYREF

  RD_EventBegin(name: "ReadBoundedIntBase");
  LODWORD(v29) = "ReadBoundedIntBase";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v32, pl: &pLog, gMask: v29, label: v30);
  v31 = 0;
  idTypeInfoFile::ReadUnsignedLong(this: file, l: &v31);
  (**a28)(a1: a28, a2: v31);
  idPLogScope::~idPLogScope(this: v32);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510927_0
// EA  : 0x82D66194
// RVA : 0x00D66194
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510927_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$510928_0
// EA  : 0x82D661BC
// RVA : 0x00D661BC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510928_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 88));
}


// ========================================================================
// ?WriteBoundedFloatBase@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D661F0
// RVA : 0x00D661F0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteBoundedFloatBase(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  long double v31; // fp2
  idPLogScope v32[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "WriteBoundedFloatBase");
  LODWORD(v29) = "WriteBoundedFloatBase";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v32, pl: &pLog, gMask: v29, label: v30);
  v31 = ((long double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)a28 + 4))(a1: a28);
  idTypeInfoFile::WriteFloat(this: file, d: v31);
  idPLogScope::~idPLogScope(this: v32);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510958
// EA  : 0x82D6625C
// RVA : 0x00D6625C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510958()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$510959
// EA  : 0x82D66284
// RVA : 0x00D66284
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510959()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?ReadBoundedFloatBase@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D662B8
// RVA : 0x00D662B8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadBoundedFloatBase(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        void (__fastcall ***a28)(_DWORD, double))
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  float v31; // [sp+50h] [-40h] BYREF
  idPLogScope v32[7]; // [sp+58h] [-38h] BYREF

  RD_EventBegin(name: "ReadBoundedFloatBase");
  LODWORD(v29) = "ReadBoundedFloatBase";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v32, pl: &pLog, gMask: v29, label: v30);
  v31 = 0.0;
  idTypeInfoFile::ReadFloat(this: file, f: &v31);
  (**a28)(a1: a28, a2: v31);
  idPLogScope::~idPLogScope(this: v32);
  RD_EventEnd();
}


// ========================================================================
// __unwind$510989
// EA  : 0x82D66338
// RVA : 0x00D66338
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510989()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$510990
// EA  : 0x82D66360
// RVA : 0x00D66360
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_510990()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 88));
}


// ========================================================================
// ?WriteNothing@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D66390
// RVA : 0x00D66390
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteNothing(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  idPLogScope v12[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "WriteNothing");
  LODWORD(v10) = "WriteNothing";
  HIDWORD(v10) = 2;
  idPLogScope::idPLogScope(this: v12, pl: &pLog, gMask: v10, label: v11);
  idTypeInfoFile::WriteOpeningBrace(this: file);
  idTypeInfoFile::WriteClosingBrace(this: file);
  idPLogScope::~idPLogScope(this: v12);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511020
// EA  : 0x82D663F0
// RVA : 0x00D663F0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511020()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$511021
// EA  : 0x82D66418
// RVA : 0x00D66418
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511021()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?WriteAnimWebPath@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D66448
// RVA : 0x00D66448
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteAnimWebPath(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idStr *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idPLogScope v31[2]; // [sp+50h] [-60h] BYREF
  idStr v32[2]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "WriteAnimWebPath");
  LODWORD(v29) = "WriteAnimWebPath";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v31, pl: &pLog, gMask: v29, label: v30);
  idStr::idStr(this: v32, text: a28);
  idStr::ReplaceChar(this: v32, oldChar: 46, newChar: 47);
  idStr::ReplaceChar(this: v32, oldChar: 58, newChar: 47);
  idTypeInfoFile::WriteStr(this: file, s: v32[0].data);
  idStr::FreeData(this: v32);
  idPLogScope::~idPLogScope(this: v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511082
// EA  : 0x82D664D8
// RVA : 0x00D664D8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511082()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 128));
}


// ========================================================================
// __unwind$511083
// EA  : 0x82D66500
// RVA : 0x00D66500
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511083()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$511084
// EA  : 0x82D66528
// RVA : 0x00D66528
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511084()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?ReadAnimWebPath@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D66558
// RVA : 0x00D66558
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadAnimWebPath(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idStr *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idPLogScope v31[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "ReadAnimWebPath");
  LODWORD(v29) = "ReadAnimWebPath";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v31, pl: &pLog, gMask: v29, label: v30);
  idTypeInfoFile::ReadStr(this: file, s: a28);
  idStr::ReplaceChar(this: a28, oldChar: 46, newChar: 47);
  idStr::ReplaceChar(this: a28, oldChar: 58, newChar: 47);
  idPLogScope::~idPLogScope(this: v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511132
// EA  : 0x82D665D8
// RVA : 0x00D665D8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511132()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$511133
// EA  : 0x82D66600
// RVA : 0x00D66600
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511133()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?WriteGraphDeclItemPointer@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D66630
// RVA : 0x00D66630
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteGraphDeclItemPointer(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const char ***a28)
{
  unsigned __int64 v36; // r6
  const char *v37; // r7
  const char **v38; // r29
  void *v39; // [sp+8h] [-C8h]
  idPLogScope v40[14]; // [sp+60h] [-70h] BYREF

  RD_EventBegin(name: "WriteGraphDeclItemPointer");
  LODWORD(v36) = "WriteGraphDeclItemPointer";
  HIDWORD(v36) = 2;
  idPLogScope::idPLogScope(this: v40, pl: &pLog, gMask: v36, label: v37);
  idTypeInfoFile::WriteOpeningBrace(this: file);
  v38 = *a28;
  if ( *a28 != nullptr )
  {
    idTypeInfoFile::WriteType(
      this: file,
      type: "idStr",
      ops: &byte_8200D768,
      name: idDeclTypeInfoGraph::classNameIdentifier);
    idTypeInfoFile::WriteStr(this: file, s: v38[2]);
    idTypeInfoFile::WriteType(
      this: file,
      type: v38[2],
      ops: &byte_8200D768,
      name: idDeclTypeInfoGraph::objectIdentifier);
    idTypeInfoTools::WriteObject(
      this: ti,
      file,
      objectType: v38[2],
      objectOps: &byte_8200D768,
      objectName: idDeclTypeInfoGraph::objectIdentifier,
      objectPtr: v38);
  }
  else
  {
    idTypeInfoFile::WriteType(
      this: file,
      type: "idStr",
      ops: &byte_8200D768,
      name: idDeclTypeInfoGraph::classNameIdentifier);
    idTypeInfoFile::WriteStr(this: file, s: &byte_8200D768);
    idTypeInfoFile::WriteType(
      this: file,
      type: &byte_8200D768,
      ops: &byte_8200D768,
      name: idDeclTypeInfoGraph::objectIdentifier);
    WriteNothing(ti, file, scope, varType, varOps, varName, varFlags, comment, varPtr: v39);
  }
  idTypeInfoFile::WriteClosingBrace(this: file);
  idPLogScope::~idPLogScope(this: v40);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511163
// EA  : 0x82D6677C
// RVA : 0x00D6677C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511163()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 104));
}


// ========================================================================
// __unwind$511164
// EA  : 0x82D667A4
// RVA : 0x00D667A4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511164()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 96));
}


// ========================================================================
// ?ReadGraphDeclItemPointer@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D667D8
// RVA : 0x00D667D8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadGraphDeclItemPointer(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idTypeInfoGraphLink **a28)
{
  unsigned __int64 v30; // r6
  const char *v31; // r7
  char *v32; // r30
  idGraphItemFactory<idTypeInfoGraphLink> *SubGraphFactory; // r3
  idTypeInfoGraphLink **v34; // r28
  idTypeInfoGraphLink *v35; // r30
  idTypeInfoGraphLink *v36; // r11
  char *data; // r30
  idGraphItemFactory<idTypeInfoGraphLink> *GraphNodeFactory; // r3
  char *v39; // r30
  idGraphItemFactory<idTypeInfoGraphLink> *GraphLinkFactory; // r3
  idStr v41; // [sp+50h] [-E0h] BYREF
  idStr v42; // [sp+70h] [-C0h] BYREF
  idPLogScope v43[2]; // [sp+90h] [-A0h] BYREF
  idStr v44; // [sp+A0h] [-90h] BYREF
  idStr v45[3]; // [sp+C0h] [-70h] BYREF

  RD_EventBegin(name: "ReadGraphDeclItemPointer");
  LODWORD(v30) = "ReadGraphDeclItemPointer";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: v43, pl: &pLog, gMask: v30, label: v31);
  idTypeInfoFile::ReadOpeningBrace(this: file);
  if ( !idTypeInfoFile::CheckType(
          this: file,
          type: "idStr",
          ops: &byte_8200D768,
          name: idDeclTypeInfoGraph::classNameIdentifier) )
  {
    idLib::Error(fmt: "Malformed typeinfo for an '%s' object\n", "idDeclTypeInfoGraph");
    _LN125_0();
    return;
  }
  v41.len = 0;
  v41.allocedAndFlag = 20;
  v41.data = v41.baseBuffer;
  v41.baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: &v41);
  if ( !idTypeInfoTools::IsSubclassOf(this: ti, typeName: v41.data, superType: "idTypeInfoSubGraph") )
  {
    if ( idTypeInfoTools::IsSubclassOf(this: ti, typeName: v41.data, superType: "idTypeInfoGraphNode") )
    {
      data = v41.data;
      GraphNodeFactory = (idGraphItemFactory<idTypeInfoGraphLink> *)idDeclTypeInfoGraph::GetGraphNodeFactory();
      v34 = a28;
      v35 = idGraphItemFactory<idTypeInfoSubGraph>::Create(this: GraphNodeFactory, itemClassName: data);
      v36 = *a28;
      if ( *a28 != nullptr )
        goto LABEL_4;
    }
    else
    {
      if ( !idTypeInfoTools::IsSubclassOf(this: ti, typeName: v41.data, superType: "idTypeInfoGraphLink") )
      {
        v35 = nullptr;
        goto LABEL_13;
      }
      v39 = v41.data;
      GraphLinkFactory = idDeclTypeInfoGraph::GetGraphLinkFactory();
      v34 = a28;
      v35 = idGraphItemFactory<idTypeInfoSubGraph>::Create(this: GraphLinkFactory, itemClassName: v39);
      if ( *a28 != nullptr )
        ((void (__fastcall *)(idTypeInfoGraphLink *, int))(*a28)->dtr_idTypeInfoGraphItem)(a1: *a28, a2: 1);
    }
LABEL_11:
    *v34 = v35;
    goto LABEL_13;
  }
  v32 = v41.data;
  SubGraphFactory = (idGraphItemFactory<idTypeInfoGraphLink> *)idDeclTypeInfoGraph::GetSubGraphFactory();
  v34 = a28;
  v35 = idGraphItemFactory<idTypeInfoSubGraph>::Create(this: SubGraphFactory, itemClassName: v32);
  v36 = *a28;
  if ( *a28 == nullptr )
    goto LABEL_11;
LABEL_4:
  ((void (__fastcall *)(idTypeInfoGraphLink *, int))v36->dtr_idTypeInfoGraphItem)(a1: *v34, a2: 1);
  *v34 = v35;
LABEL_13:
  v45[0].allocedAndFlag = 20;
  v45[0].len = 0;
  v45[0].data = v45[0].baseBuffer;
  v45[0].baseBuffer[0] = 0;
  v42.allocedAndFlag = 20;
  v42.data = v42.baseBuffer;
  v42.len = 0;
  v42.baseBuffer[0] = 0;
  v44.allocedAndFlag = 20;
  v44.data = v44.baseBuffer;
  v44.len = 0;
  v44.baseBuffer[0] = 0;
  idTypeInfoFile::ReadType(this: file, type: v45, ops: &v44, name: &v42);
  if ( v35 != nullptr )
    idTypeInfoTools::ReadObject(
      this: ti,
      file,
      objectType: v41.data,
      objectOps: &byte_8200D768,
      objectName: v42.data,
      objectPtr: v35);
  else
    idLexer::SkipBracedSection(this: &file->src, parseFirstBrace: true);
  idTypeInfoFile::ReadClosingBrace(this: file);
  idStr::FreeData(this: &v44);
  idStr::FreeData(this: &v42);
  idStr::FreeData(this: v45);
  idStr::FreeData(this: &v41);
  idPLogScope::~idPLogScope(this: v43);
  RD_EventEnd();
}


// ========================================================================
// $LN125_0
// EA  : 0x82D66A7C
// RVA : 0x00D66A7C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _LN125_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 304 + 224));
}


// ========================================================================
// __unwind$511234
// EA  : 0x82D66AA4
// RVA : 0x00D66AA4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511234()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 304 + 144));
}


// ========================================================================
// __unwind$511235
// EA  : 0x82D66ACC
// RVA : 0x00D66ACC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511235()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 80));
}


// ========================================================================
// __unwind$511236
// EA  : 0x82D66AF4
// RVA : 0x00D66AF4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511236()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 192));
}


// ========================================================================
// __unwind$511237
// EA  : 0x82D66B1C
// RVA : 0x00D66B1C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511237()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$511238
// EA  : 0x82D66B44
// RVA : 0x00D66B44
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511238()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 160));
}


// ========================================================================
// ?ReadAIActionParm@idAIActionParm@@SAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D66B78
// RVA : 0x00D66B78
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall idAIActionParm::ReadAIActionParm(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  char *data; // r4
  idDeclInfoTemplate<idDeclInventory> *v32; // r3
  const idDecl *v33; // r3
  idStr v34; // [sp+50h] [-100h] BYREF
  idStr v35; // [sp+70h] [-E0h] BYREF
  idPLogScope v36[2]; // [sp+90h] [-C0h] BYREF
  idStr v37; // [sp+A0h] [-B0h] BYREF
  idStr v38[4]; // [sp+C0h] [-90h] BYREF

  RD_EventBegin(name: "idAIActionParm::ReadAIActionParm");
  LODWORD(v29) = "idAIActionParm::ReadAIActionParm";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v36, pl: &pLog, gMask: v29, label: v30);
  v35.len = 0;
  v35.allocedAndFlag = 20;
  v35.data = v35.baseBuffer;
  v35.baseBuffer[0] = 0;
  idTypeInfoFile::ReadOpeningBrace(this: file);
  while ( !idTypeInfoFile::CheckClosingBrace(this: file) )
  {
    v38[0].allocedAndFlag = 20;
    v38[0].len = 0;
    v38[0].data = v38[0].baseBuffer;
    v38[0].baseBuffer[0] = 0;
    v37.allocedAndFlag = 20;
    v37.data = v37.baseBuffer;
    v37.len = 0;
    v37.baseBuffer[0] = 0;
    v34.allocedAndFlag = 20;
    v34.data = v34.baseBuffer;
    v34.len = 0;
    v34.baseBuffer[0] = 0;
    idTypeInfoFile::ReadType(this: file, type: v38, ops: &v37, name: &v34);
    if ( idStr::Cmp(s1: v34.data, s2: "type") != 0 )
    {
      if ( idStr::Cmp(s1: v34.data, s2: "subType") != 0 )
      {
        if ( idStr::Cmp(s1: v34.data, s2: "intVal") != 0 )
        {
          if ( idStr::Cmp(s1: v34.data, s2: "floatVal") != 0 )
          {
            if ( idStr::Cmp(s1: v34.data, s2: "declVal") != 0 )
            {
              if ( idStr::Cmp(s1: v34.data, s2: "strVal") != 0 )
                idTypeInfoFile::ReadUnknown(this: file);
              else
                idTypeInfoFile::ReadStr(this: file, s: (idStr *)(a28 + 24));
            }
            else
            {
              idTypeInfoFile::ReadStr(this: file, s: &v35);
            }
          }
          else
          {
            idTypeInfoFile::ReadVec3(this: file, v: (idVec3 *)(a28 + 8));
          }
        }
        else
        {
          idTypeInfoFile::ReadUnsignedLong(this: file, l: (unsigned int *)(a28 + 4));
        }
      }
      else
      {
        idTypeInfoFile::ReadWChar(this: file, s: (unsigned __int16 *)(a28 + 2));
      }
    }
    else
    {
      idTypeInfoFile::ReadWChar(this: file, s: (unsigned __int16 *)a28);
    }
    idStr::FreeData(this: &v34);
    idStr::FreeData(this: &v37);
    idStr::FreeData(this: v38);
  }
  if ( *(_WORD *)a28 == 4 && (unsigned int)*(unsigned __int16 *)(a28 + 2) - 24 <= 6 )
  {
    switch ( *(_WORD *)(a28 + 2) )
    {
      case 0x19:
        data = v35.data;
        if ( v35.data != nullptr )
        {
          v32 = (idDeclInfoTemplate<idDeclInventory> *)&idSoundShader::resourceList;
          goto LABEL_35;
        }
LABEL_33:
        v33 = nullptr;
LABEL_36:
        *(_DWORD *)(a28 + 20) = v33;
        goto LABEL_37;
      case 0x1A:
        data = v35.data;
        if ( v35.data != nullptr )
        {
          v32 = (idDeclInfoTemplate<idDeclInventory> *)&idDeclAmmo::resourceList;
          goto LABEL_35;
        }
        goto LABEL_33;
      case 0x1B:
        data = v35.data;
        if ( v35.data != nullptr )
        {
          v32 = (idDeclInfoTemplate<idDeclInventory> *)&idDeclWeapon::resourceList;
          goto LABEL_35;
        }
        goto LABEL_33;
      default:
        break;
    }
    if ( *(_WORD *)(a28 + 2) != 28 && *(_WORD *)(a28 + 2) != 29 )
    {
      if ( *(_WORD *)(a28 + 2) == 24 )
      {
        data = v35.data;
        if ( v35.data != nullptr )
        {
          v32 = (idDeclInfoTemplate<idDeclInventory> *)&idDeclVoiceOver::resourceList;
LABEL_35:
          v33 = idDeclInfo::FindWithInheritance(this: v32, name: data, makeDefault: true);
          goto LABEL_36;
        }
      }
      else
      {
        data = v35.data;
        if ( v35.data != nullptr )
        {
          v32 = &idDeclInventory::resourceList;
          goto LABEL_35;
        }
      }
      goto LABEL_33;
    }
  }
LABEL_37:
  idStr::FreeData(this: &v35);
  idPLogScope::~idPLogScope(this: v36);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511442
// EA  : 0x82D66E58
// RVA : 0x00D66E58
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511442()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 224));
}


// ========================================================================
// __unwind$511443
// EA  : 0x82D66E80
// RVA : 0x00D66E80
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511443()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 144));
}


// ========================================================================
// __unwind$511444
// EA  : 0x82D66EA8
// RVA : 0x00D66EA8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511444()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 112));
}


// ========================================================================
// __unwind$511445
// EA  : 0x82D66ED0
// RVA : 0x00D66ED0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511445()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 192));
}


// ========================================================================
// __unwind$511446
// EA  : 0x82D66EF8
// RVA : 0x00D66EF8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511446()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$511447
// EA  : 0x82D66F20
// RVA : 0x00D66F20
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511447()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 80));
}


// ========================================================================
// ?WriteAliasHandle@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D66F50
// RVA : 0x00D66F50
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteAliasHandle(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned __int16 *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  const char *v31; // r3
  idPLogScope v32[2]; // [sp+50h] [-60h] BYREF
  idStr v33[2]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "WriteAliasHandle");
  LODWORD(v29) = "WriteAliasHandle";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v32, pl: &pLog, gMask: v29, label: v30);
  if ( *a28 == 0xFFFF )
  {
    idTypeInfoFile::WriteStr(this: file, s: &byte_8200D768);
  }
  else
  {
    v31 = (const char *)((int (__fastcall *)(idAnimation *))animation->FindAliasName)(a1: animation);
    idStr::idStr(this: v33, text: v31);
    idTypeInfoFile::WriteStr(this: file, s: v33[0].data);
    idStr::FreeData(this: v33);
  }
  idPLogScope::~idPLogScope(this: v32);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511722
// EA  : 0x82D66FFC
// RVA : 0x00D66FFC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511722()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 128));
}


// ========================================================================
// __unwind$511723
// EA  : 0x82D67024
// RVA : 0x00D67024
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511723()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$511724
// EA  : 0x82D6704C
// RVA : 0x00D6704C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511724()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?ReadIESFile@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D67080
// RVA : 0x00D67080
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadIESFile(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idResource **a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idPLogScope v31[2]; // [sp+50h] [-60h] BYREF
  idStr v32[2]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "ReadIESFile");
  LODWORD(v29) = "ReadIESFile";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v31, pl: &pLog, gMask: v29, label: v30);
  v32[0].len = 0;
  v32[0].allocedAndFlag = 20;
  v32[0].data = v32[0].baseBuffer;
  v32[0].baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: v32);
  if ( v32[0].len != 0 )
    *a28 = idResourceList::Load(
             this: &idIESfile::resourceList,
             name: v32[0].data,
             makeDefault: false,
             skipStaleCheck: false);
  else
    *a28 = nullptr;
  idStr::FreeData(this: v32);
  idPLogScope::~idPLogScope(this: v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511770
// EA  : 0x82D67138
// RVA : 0x00D67138
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511770()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 128));
}


// ========================================================================
// __unwind$511771
// EA  : 0x82D67160
// RVA : 0x00D67160
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511771()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$511772
// EA  : 0x82D67188
// RVA : 0x00D67188
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511772()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?WriteIESFile@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D671B8
// RVA : 0x00D671B8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteIESFile(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v30; // r6
  const char *v31; // r7
  const char *v32; // r4
  idTypeInfoFile *v33; // r3
  idPLogScope v34[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "WriteIESFile");
  LODWORD(v30) = "WriteIESFile";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: v34, pl: &pLog, gMask: v30, label: v31);
  if ( *(_DWORD *)a28 != 0 )
  {
    v32 = *(const char **)(*(_DWORD *)a28 + 8);
    v33 = file;
  }
  else
  {
    v33 = file;
    v32 = &byte_8200D768;
  }
  idTypeInfoFile::WriteStr(this: v33, s: v32);
  idTypeInfoFile::WriteComment(this: file, comment);
  idPLogScope::~idPLogScope(this: v34);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511847
// EA  : 0x82D67244
// RVA : 0x00D67244
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511847()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$511848
// EA  : 0x82D6726C
// RVA : 0x00D6726C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511848()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?ReadVoiceTrack@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D672A0
// RVA : 0x00D672A0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadVoiceTrack(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idResource **a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  idPLogScope v31[2]; // [sp+50h] [-60h] BYREF
  idStr v32[2]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "ReadVoiceTrack");
  LODWORD(v29) = "ReadVoiceTrack";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: v31, pl: &pLog, gMask: v29, label: v30);
  v32[0].len = 0;
  v32[0].allocedAndFlag = 20;
  v32[0].data = v32[0].baseBuffer;
  v32[0].baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: v32);
  if ( v32[0].len != 0 )
    *a28 = idResourceList::Load(
             this: &idVoiceTrack::resourceList,
             name: v32[0].data,
             makeDefault: true,
             skipStaleCheck: false);
  else
    *a28 = nullptr;
  idStr::FreeData(this: v32);
  idPLogScope::~idPLogScope(this: v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511888
// EA  : 0x82D67358
// RVA : 0x00D67358
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511888()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 128));
}


// ========================================================================
// __unwind$511889
// EA  : 0x82D67380
// RVA : 0x00D67380
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511889()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$511890
// EA  : 0x82D673A8
// RVA : 0x00D673A8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511890()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?WriteVoiceTrack@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D673D8
// RVA : 0x00D673D8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteVoiceTrack(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  unsigned __int64 v30; // r6
  const char *v31; // r7
  const char *v32; // r4
  idTypeInfoFile *v33; // r3
  idPLogScope v34[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "WriteVoiceTrack");
  LODWORD(v30) = "WriteVoiceTrack";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: v34, pl: &pLog, gMask: v30, label: v31);
  if ( *(_DWORD *)a28 != 0 )
  {
    v32 = *(const char **)(*(_DWORD *)a28 + 8);
    v33 = file;
  }
  else
  {
    v33 = file;
    v32 = &byte_8200D768;
  }
  idTypeInfoFile::WriteStr(this: v33, s: v32);
  idTypeInfoFile::WriteComment(this: file, comment);
  idPLogScope::~idPLogScope(this: v34);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511965
// EA  : 0x82D67464
// RVA : 0x00D67464
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511965()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$511966
// EA  : 0x82D6748C
// RVA : 0x00D6748C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_511966()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetUnresolvedEntityName@idGameState@@SAPBDABV?$idEntityPtr@VidEntity@@@@@Z
// EA  : 0x82D674C0
// RVA : 0x00D674C0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

char *__fastcall idGameState::GetUnresolvedEntityName(const idEntityPtr<idEntity> *ptr)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int value; // r11
  int v5; // r30
  const char *StringForIndex; // r30
  idPLogScope v8[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idGameState::GetUnresolvedEntityName");
  LODWORD(v2) = "idGameState::GetUnresolvedEntityName";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v8, pl: &pLog, gMask: v2, label: v3);
  value = ptr->spawnId.value;
  if ( ptr->spawnId.value != 0 && value != 0x1FFF )
  {
    v5 = value - 1;
    if ( value - 1 >= 0 && v5 < (int)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)&ptrNames) )
    {
      StringForIndex = idTypeInfoStrings::GetStringForIndex(this: &ptrNames, index: v5);
      idPLogScope::~idPLogScope(this: v8);
      RD_EventEnd();
      return (char *)StringForIndex;
    }
    idLib::Error(
      fmt: "idGameState::GetUnresolvedEntityName: bad idEntityPtr pointer, make sure the pointer was initialized without resolving pointers");
  }
  idPLogScope::~idPLogScope(this: v8);
  RD_EventEnd();
  return &byte_8200D768;
}


// ========================================================================
// $LN19_4
// EA  : 0x82D6757C
// RVA : 0x00D6757C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _LN19_4()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$512010
// EA  : 0x82D675A4
// RVA : 0x00D675A4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512010()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetUnresolvedEntityName@idGameState@@SAXAAV?$idEntityPtr@VidEntity@@@@PBD@Z
// EA  : 0x82D675D8
// RVA : 0x00D675D8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall idGameState::SetUnresolvedEntityName(idEntityPtr<idEntity> *ptr, const char *name)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idPLogScope v6[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idGameState::SetUnresolvedEntityName");
  LODWORD(v4) = "idGameState::SetUnresolvedEntityName";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: v6, pl: &pLog, gMask: v4, label: v5);
  ptr->spawnId.value = idTypeInfoStrings::FindString(this: &ptrNames, s: name) + 1;
  idPLogScope::~idPLogScope(this: v6);
  RD_EventEnd();
}


// ========================================================================
// __unwind$512055
// EA  : 0x82D67644
// RVA : 0x00D67644
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512055()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$512056
// EA  : 0x82D6766C
// RVA : 0x00D6766C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512056()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetUnresolvedModelName@idGameState@@SAPBDPAPBVidRenderModel@@@Z
// EA  : 0x82D676A0
// RVA : 0x00D676A0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

char *__fastcall idGameState::GetUnresolvedModelName(const idRenderModel **ptr)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  char *v4; // r30
  const char *StringForIndex; // r30
  idPLogScope v7[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idGameState::GetUnresolvedModelName");
  LODWORD(v2) = "idGameState::GetUnresolvedModelName";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v7, pl: &pLog, gMask: v2, label: v3);
  v4 = (char *)&(*ptr)[-1].decalData.staticList[15].jointId + 3;
  if ( v4 == (char *)-1 )
  {
    idPLogScope::~idPLogScope(this: v7);
    RD_EventEnd();
    return &byte_8200D768;
  }
  else if ( (int)v4 < 0 || (int)v4 >= (int)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)&ptrNames) )
  {
    idLib::Error(
      fmt: "idGameState::GetUnresolvedModelName: bad idRenderModel pointer, make sure the pointer was initialized without resolving pointers");
    return (char *)_LN30_3();
  }
  else
  {
    StringForIndex = idTypeInfoStrings::GetStringForIndex(this: &ptrNames, index: (int)v4);
    idPLogScope::~idPLogScope(this: v7);
    RD_EventEnd();
    return (char *)StringForIndex;
  }
}


// ========================================================================
// $LN30_3
// EA  : 0x82D67758
// RVA : 0x00D67758
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _LN30_3()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$512101
// EA  : 0x82D67780
// RVA : 0x00D67780
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512101()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetUnresolvedModelName@idGameState@@SAXPAPAVidRenderModel@@PBD@Z
// EA  : 0x82D677B0
// RVA : 0x00D677B0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall idGameState::SetUnresolvedModelName(idRenderModel **ptr, const char *name)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idPLogScope v6[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idGameState::SetUnresolvedModelName");
  LODWORD(v4) = "idGameState::SetUnresolvedModelName";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: v6, pl: &pLog, gMask: v4, label: v5);
  *ptr = (idRenderModel *)(idTypeInfoStrings::FindString(this: &ptrNames, s: name) + 1);
  idPLogScope::~idPLogScope(this: v6);
  RD_EventEnd();
}


// ========================================================================
// __unwind$512140
// EA  : 0x82D6781C
// RVA : 0x00D6781C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512140()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$512141
// EA  : 0x82D67844
// RVA : 0x00D67844
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512141()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetEntityEditState@idGameState@@SAXPBVidEntity@@AAVidTypeInfoFile@@_N@Z
// EA  : 0x82D67878
// RVA : 0x00D67878
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall idGameState::GetEntityEditState(idEntity *entity, idTypeInfoFile *file, bool includeDefVars)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  const char **v8; // r3
  const char **v9; // r3
  idPLogScope v10[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idGameState::GetEntityEditState");
  LODWORD(v6) = "idGameState::GetEntityEditState";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v10, pl: &pLog, gMask: v6, label: v7);
  file->settings.writeModifier = ((_cntlzw(includeDefVars) & 0x20) != 0) + 1;
  v8 = (const char **)entity->GetType(this: entity);
  idTypeInfoFile::WriteType(this: file, type: *v8, ops: &byte_8200D768, name: "edit");
  v9 = (const char **)entity->GetType(this: entity);
  idTypeInfoTools::WriteObject(
    this: typeInfoTools,
    file,
    objectType: *v9,
    objectOps: &byte_8200D768,
    objectName: "edit",
    objectPtr: entity);
  idPLogScope::~idPLogScope(this: v10);
  RD_EventEnd();
}


// ========================================================================
// __unwind$512171
// EA  : 0x82D67954
// RVA : 0x00D67954
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512171()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$512172
// EA  : 0x82D6797C
// RVA : 0x00D6797C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512172()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?SetEntityEditState@idGameState@@SAXPAVidEntity@@AAVidTypeInfoFile@@_N@Z
// EA  : 0x82D679B0
// RVA : 0x00D679B0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall idGameState::SetEntityEditState(idEntity *entity, idTypeInfoFile *file, bool includeDefVars)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  bool v8; // r18
  int num; // r24
  int v10; // r19
  unsigned __int64 v11; // r6
  const char *v12; // r7
  const char **v13; // r3
  unsigned __int64 v14; // r6
  const char *v15; // r7
  int v16; // r29
  int v17; // r30
  int v18; // r25
  int v19; // r21
  const idDeclMD6 **v20; // r27
  int v21; // r29
  int v22; // r30
  int size; // r11
  bool v24; // cr56
  int v25; // r11
  bool v26; // cr56
  idPLog *pLog; // r29
  idPLog::logEntry_t *v28; // r30
  int v29; // r3
  __int64 totalTicks; // r11
  __int64 v31; // r9
  idPLog *v32; // r29
  idPLog::logEntry_t *v33; // r30
  int v34; // r3
  __int64 v35; // r11
  __int64 v36; // r9
  const idRenderModel **v37; // [sp+54h] [-FCh] BYREF
  idPLogScope v38; // [sp+58h] [-F8h] BYREF
  idPLogScope v39; // [sp+60h] [-F0h] BYREF
  idStr v40; // [sp+70h] [-E0h] BYREF
  idStr v41; // [sp+90h] [-C0h] BYREF
  idStr v42[5]; // [sp+B0h] [-A0h] BYREF

  RD_EventBegin(name: "idGameState::SetEntityEditState");
  LODWORD(v6) = "idGameState::SetEntityEditState";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v39, pl: &::pLog, gMask: v6, label: v7);
  v8 = idLib::PushWarningInfo(type: "entity", name: entity->name.data);
  num = idGameState::referencedAliases.num;
  v10 = idGameState::referencedModels.num;
  file->settings.writeModifier = ((_cntlzw(includeDefVars) & 0x20) != 0) + 1;
  v42[0].allocedAndFlag = 20;
  v42[0].data = v42[0].baseBuffer;
  v42[0].len = 0;
  v42[0].baseBuffer[0] = 0;
  v41.allocedAndFlag = 20;
  v41.data = v41.baseBuffer;
  v41.len = 0;
  v41.baseBuffer[0] = 0;
  v40.allocedAndFlag = 20;
  v40.data = v40.baseBuffer;
  v40.len = 0;
  v40.baseBuffer[0] = 0;
  RD_EventBegin(name: "idGameState::SetEntityEditState - Read object");
  LODWORD(v11) = "idGameState::SetEntityEditState - Read object";
  HIDWORD(v11) = 2;
  idPLogScope::idPLogScope(this: &v38, pl: &::pLog, gMask: v11, label: v12);
  idTypeInfoFile::ReadType(this: file, type: v42, ops: &v41, name: &v40);
  v13 = (const char **)entity->GetType(this: entity);
  idTypeInfoTools::ReadObject(
    this: typeInfoTools,
    file,
    objectType: *v13,
    objectOps: &byte_8200D768,
    objectName: v40.data,
    objectPtr: entity);
  if ( idTypeInfoFile::HadError(this: file) )
    idLib::Error(fmt: "SetEntityEditState: failed to parse typeinfo state, see console for previous error.");
  idPLogScope::~idPLogScope(this: &v38);
  RD_EventEnd();
  RD_EventBegin(name: "idGameState::SetEntityEditState - strong load aliases");
  LODWORD(v14) = "idGameState::SetEntityEditState - strong load aliases";
  HIDWORD(v14) = 2;
  idPLogScope::idPLogScope(this: &v38, pl: &::pLog, gMask: v14, label: v15);
  if ( idGameState::referencedAliases.num - num > 0 )
  {
    if ( idGameState::referencedModels.num - v10 > 0 )
    {
      if ( idGameState::referencedModels.num - 1 >= v10 )
      {
        v18 = idGameState::referencedModels.num - 1;
        v19 = idGameState::referencedModels.num - v10;
        do
        {
          v37 = &idGameState::referencedModels.list[v18];
          v20 = (const idDeclMD6 **)_RTDynamicCast(
                                      inptr: (void *)idGameState::referencedModels.list[v18],
                                      VfDelta: 0,
                                      SrcType: &idRenderModel `RTTI Type Descriptor',
                                      TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                      isReference: 0);
          if ( v20 != nullptr && idGameState::referencedAliases.num - 1 >= num )
          {
            v21 = idGameState::referencedAliases.num - 1;
            v22 = idGameState::referencedAliases.num - num;
            do
            {
              animation->StrongLoadAlias_2(this: animation, a2: v20[508], a3: &idGameState::referencedAliases.list[v21]);
              --v22;
              --v21;
            }
            while ( v22 != 0 );
          }
          --v19;
          --v18;
        }
        while ( v19 != 0 );
      }
    }
    else if ( idGameState::referencedAliases.num - 1 >= num )
    {
      v16 = idGameState::referencedAliases.num - 1;
      v17 = idGameState::referencedAliases.num - num;
      do
      {
        animation->FindAliasName(this: animation, a2: &idGameState::referencedAliases.list[v16]);
        ((void (__fastcall *)(const idRenderModel ***))animation->AddStrongAliasRef)(a1: &v37);
        --v17;
        --v16;
      }
      while ( v17 != 0 );
    }
  }
  size = idGameState::referencedAliases.size;
  v24 = num < idGameState::referencedAliases.size;
  if ( num > idGameState::referencedAliases.size )
  {
    if ( (unsigned __int8)idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Resize(
                            this: &idGameState::referencedAliases,
                            newsize: num) == 0 )
      goto LABEL_22;
    size = idGameState::referencedAliases.size;
    v24 = num < idGameState::referencedAliases.size;
  }
  if ( v24 )
    idGameState::referencedAliases.num = num;
  else
    idGameState::referencedAliases.num = size;
LABEL_22:
  v25 = idGameState::referencedModels.size;
  v26 = v10 < idGameState::referencedModels.size;
  if ( v10 > idGameState::referencedModels.size )
  {
    if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(
                            this: (idList<idSpawnArea::GeneratedPosition *,5> *)&idGameState::referencedModels,
                            newsize: v10) == 0 )
      goto LABEL_28;
    v25 = idGameState::referencedModels.size;
    v26 = v10 < idGameState::referencedModels.size;
  }
  if ( v26 )
    idGameState::referencedModels.num = v10;
  else
    idGameState::referencedModels.num = v25;
LABEL_28:
  if ( v38.logIndex >= 0 )
  {
    pLog = v38.pLog;
    v28 = &v38.pLog->logEntries.list[v38.logIndex];
    v29 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v28->totalTicks;
    HIDWORD(totalTicks) = v28->parent;
    LODWORD(v31) = v29 - totalTicks;
    v28->totalTicks = v31;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  idStr::FreeData(this: &v40);
  idStr::FreeData(this: &v41);
  idStr::FreeData(this: v42);
  if ( v8 )
    idLib::PopWarningInfo();
  if ( v39.logIndex >= 0 )
  {
    v32 = v39.pLog;
    v33 = &v39.pLog->logEntries.list[v39.logIndex];
    v34 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v35 = v33->totalTicks;
    HIDWORD(v35) = v33->parent;
    LODWORD(v36) = v34 - v35;
    v33->totalTicks = v36;
    v32->lastEntry = HIDWORD(v35);
  }
  RD_EventEnd();
}


// ========================================================================
// $LN136_0
// EA  : 0x82D67D84
// RVA : 0x00D67D84
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _LN136_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 208));
}


// ========================================================================
// __unwind$512205
// EA  : 0x82D67DAC
// RVA : 0x00D67DAC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512205()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 96));
}


// ========================================================================
// __unwind$512206
// EA  : 0x82D67DD4
// RVA : 0x00D67DD4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512206()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 336 + 80));
}


// ========================================================================
// __unwind$512207
// EA  : 0x82D67DFC
// RVA : 0x00D67DFC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512207()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 176));
}


// ========================================================================
// __unwind$512208
// EA  : 0x82D67E24
// RVA : 0x00D67E24
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512208()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 144));
}


// ========================================================================
// __unwind$512209
// EA  : 0x82D67E4C
// RVA : 0x00D67E4C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512209()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 112));
}


// ========================================================================
// __unwind$512210
// EA  : 0x82D67E74
// RVA : 0x00D67E74
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512210()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 209));
}


// ========================================================================
// __unwind$512211
// EA  : 0x82D67E9C
// RVA : 0x00D67E9C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512211()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 88));
}


// ========================================================================
// __unwind$512212
// EA  : 0x82D67EC4
// RVA : 0x00D67EC4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512212()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 210));
}


// ========================================================================
// __unwind$512213
// EA  : 0x82D67EEC
// RVA : 0x00D67EEC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512213()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 88));
}


// ========================================================================
// ?AddAnimAliasReference@idGameState@@SAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x82D67F18
// RVA : 0x00D67F18
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall idGameState::AddAnimAliasReference(
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *alias,
        const char *name)
{
  int v2; // r10
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *list; // r11

  v2 = 0;
  if ( idGameState::referencedAliases.num <= 0 )
    goto LABEL_7;
  list = idGameState::referencedAliases.list;
  while ( list->value != alias->value )
  {
    ++v2;
    ++list;
    if ( v2 >= idGameState::referencedAliases.num )
      goto LABEL_7;
  }
  if ( v2 < 0 )
LABEL_7:
    idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Append(
      this: (idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,30> *)&idGameState::referencedAliases,
      obj: alias);
}


// ========================================================================
// ?WriteRenderModel@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D67F78
// RVA : 0x00D67F78
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteRenderModel(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idRenderModel **a28)
{
  unsigned __int64 v30; // r6
  const char *v31; // r7
  char *UnresolvedModelName; // r4
  idTypeInfoFile *v33; // r3
  int Index; // r3
  idPLogScope v35[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "WriteRenderModel");
  LODWORD(v30) = "WriteRenderModel";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: v35, pl: &pLog, gMask: v30, label: v31);
  if ( !file->settings.resolveModelPointers )
  {
    UnresolvedModelName = idGameState::GetUnresolvedModelName(ptr: a28);
    v33 = file;
    goto LABEL_6;
  }
  if ( file->settings.writeModifier != WRITE_ALL_PROPERTIES )
  {
    UnresolvedModelName = (char *)(*a28)->name.str;
    v33 = file;
LABEL_6:
    idTypeInfoFile::WriteStr(this: v33, s: UnresolvedModelName);
    goto LABEL_7;
  }
  Index = idRenderModel::GetIndex(this: (idRenderModel *)*a28);
  idTypeInfoFile::WriteInt(this: file, l: Index);
LABEL_7:
  idTypeInfoFile::WriteComment(this: file, comment);
  idPLogScope::~idPLogScope(this: v35);
  RD_EventEnd();
}


// ========================================================================
// __unwind$512540
// EA  : 0x82D68030
// RVA : 0x00D68030
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512540()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$512541
// EA  : 0x82D68058
// RVA : 0x00D68058
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512541()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?ReadRenderModel@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D68088
// RVA : 0x00D68088
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadRenderModel(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idRenderModel **a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  int v31; // r10
  int v32; // r9
  int v33; // r8
  int v34; // r7
  int v35; // r6
  int v36; // r5
  int v37; // r4
  __int64 v38; // r4
  int v39; // r10
  int v40; // r9
  int v41; // r8
  int v42; // r7
  int v43; // r6
  int v44; // r5
  int v45; // [sp+8h] [-C8h]
  int v46; // [sp+Ch] [-C4h]
  int v47; // [sp+10h] [-C0h]
  const idRenderModel *v48; // [sp+14h] [-BCh]
  unsigned int v49; // [sp+50h] [-80h] BYREF
  idPLogScope v50; // [sp+58h] [-78h] BYREF
  idStr v51; // [sp+60h] [-70h] BYREF
  idStr v52[2]; // [sp+80h] [-50h] BYREF

  RD_EventBegin(name: "ReadRenderModel");
  LODWORD(v29) = "ReadRenderModel";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: &v50, pl: &pLog, gMask: v29, label: v30);
  if ( file->settings.resolveModelPointers )
  {
    if ( file->settings.writeModifier != WRITE_ALL_PROPERTIES )
    {
      v51.len = 0;
      v51.allocedAndFlag = 20;
      v51.data = v51.baseBuffer;
      v51.baseBuffer[0] = 0;
      idTypeInfoFile::ReadStr(this: file, s: &v51);
      *a28 = gameLocal->clientGame.renderWorld->AllocRenderModel(
               this: gameLocal->clientGame.renderWorld,
               a2: v51.data,
               a3: 0,
               a4: -1);
      idStr::FreeData(this: &v51);
      idGameState::AddRenderModelReference(
        rm: *a28,
        a2: v37,
        a3: v36,
        a4: v35,
        a5: v34,
        a6: v33,
        a7: v32,
        a8: v31,
        a9: v45,
        a10: v46,
        a11: v47,
        a12: v48);
    }
    else
    {
      idTypeInfoFile::ReadUnsignedLong(this: file, l: &v49);
      v38 = ((__int64 (__fastcall *)(idRenderWorld *, unsigned int))gameLocal->clientGame.renderWorld->RenderModelForIndex)(
              a1: gameLocal->clientGame.renderWorld,
              a2: v49);
      *a28 = (const idRenderModel *)HIDWORD(v38);
      idGameState::AddRenderModelReference(
        rm: (const idRenderModel *)HIDWORD(v38),
        a2: v38,
        a3: v44,
        a4: v43,
        a5: v42,
        a6: v41,
        a7: v40,
        a8: v39,
        a9: v45,
        a10: v46,
        a11: v47,
        a12: v48);
    }
  }
  else
  {
    v52[0].len = 0;
    v52[0].allocedAndFlag = 20;
    v52[0].data = v52[0].baseBuffer;
    v52[0].baseBuffer[0] = 0;
    idTypeInfoFile::ReadStr(this: file, s: v52);
    idGameState::SetUnresolvedModelName(ptr: (idRenderModel **)a28, name: v52[0].data);
    idStr::FreeData(this: v52);
  }
  idPLogScope::~idPLogScope(this: &v50);
  RD_EventEnd();
}


// ========================================================================
// __unwind$512581
// EA  : 0x82D681E8
// RVA : 0x00D681E8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512581()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 160));
}


// ========================================================================
// __unwind$512582
// EA  : 0x82D68210
// RVA : 0x00D68210
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512582()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 88));
}


// ========================================================================
// __unwind$512583
// EA  : 0x82D68238
// RVA : 0x00D68238
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512583()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$512584
// EA  : 0x82D68260
// RVA : 0x00D68260
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512584()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// ?WriteEntityPtr@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D68290
// RVA : 0x00D68290
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteEntityPtr(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idEntityPtr<idEntity> *a28)
{
  unsigned __int64 v36; // r6
  const char *v37; // r7
  idEntity *v38; // r3
  idEntity *v39; // r3
  char *data; // r4
  void *v41; // [sp+8h] [-C8h]
  bool v42; // [sp+Fh] [-C1h]
  idPLogScope v43[14]; // [sp+60h] [-70h] BYREF

  RD_EventBegin(name: "WriteEntityPtr");
  LODWORD(v36) = "WriteEntityPtr";
  HIDWORD(v36) = 2;
  idPLogScope::idPLogScope(this: v43, pl: &pLog, gMask: v36, label: v37);
  if ( file->settings.writeModifier != WRITE_ALL_PROPERTIES )
  {
    if ( file->settings.resolveEntityPointers )
    {
      if ( gameLocal->spawnIds.ptr[a28->spawnId.value & 0x1FFF] == a28->spawnId.value >> 13
        && (v38 = gameLocal->entities.ptr[a28->spawnId.value & 0x1FFF]) != nullptr
        && (v39 = idEntity::CastTo(c: v38)) != nullptr )
      {
        data = v39->name.data;
      }
      else
      {
        data = &byte_8200D768;
      }
    }
    else
    {
      data = idGameState::GetUnresolvedEntityName(ptr: a28);
    }
    idTypeInfoFile::WriteStr(this: file, s: data);
    idTypeInfoFile::WriteComment(this: file, comment);
  }
  else
  {
    idTypeInfoTools::WriteType_r(
      this: ti,
      file,
      scope,
      varType,
      varOps,
      varName,
      varFlags,
      comment,
      varPtr: v41,
      allowSpecialCase: v42);
  }
  idPLogScope::~idPLogScope(this: v43);
  RD_EventEnd();
}


// ========================================================================
// __unwind$512693
// EA  : 0x82D683CC
// RVA : 0x00D683CC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512693()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 104));
}


// ========================================================================
// __unwind$512694
// EA  : 0x82D683F4
// RVA : 0x00D683F4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512694()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 96));
}


// ========================================================================
// ?ReadEntityPtr@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D68428
// RVA : 0x00D68428
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadEntityPtr(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idEntityPtr<idEntity> *a28)
{
  unsigned __int64 v36; // r6
  const char *v37; // r7
  idEntity *v38; // r3
  void *v39; // [sp+8h] [-E8h]
  bool v40; // [sp+Fh] [-E1h]
  idPLogScope v41; // [sp+68h] [-88h] BYREF
  idStr v42[4]; // [sp+70h] [-80h] BYREF

  RD_EventBegin(name: "ReadEntityPtr");
  LODWORD(v36) = "ReadEntityPtr";
  HIDWORD(v36) = 2;
  idPLogScope::idPLogScope(this: &v41, pl: &pLog, gMask: v36, label: v37);
  if ( file->settings.writeModifier != WRITE_ALL_PROPERTIES )
  {
    v42[0].len = 0;
    v42[0].allocedAndFlag = 20;
    v42[0].data = v42[0].baseBuffer;
    v42[0].baseBuffer[0] = 0;
    idTypeInfoFile::ReadStr(this: file, s: v42);
    if ( file->settings.resolveEntityPointers )
    {
      if ( v42[0].len != 0 )
      {
        v38 = gameLocal->FindEntity(this: gameLocal, a2: v42[0].data);
        if ( v38 != nullptr )
          a28->spawnId.value = (gameLocal->spawnIds.ptr[v38->entityNumber] << 13) | v38->entityNumber;
      }
      else
      {
        a28->spawnId.value = 0x1FFF;
      }
    }
    else
    {
      idGameState::SetUnresolvedEntityName(ptr: a28, name: v42[0].data);
    }
    idStr::FreeData(this: v42);
  }
  else
  {
    idTypeInfoTools::ReadType_r(
      this: ti,
      file,
      scope,
      varType,
      varOps,
      varName,
      varFlags,
      comment,
      varPtr: v39,
      allowSpecialCase: v40);
  }
  idPLogScope::~idPLogScope(this: &v41);
  RD_EventEnd();
}


// ========================================================================
// __unwind$512763
// EA  : 0x82D68590
// RVA : 0x00D68590
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512763()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$512764
// EA  : 0x82D685B8
// RVA : 0x00D685B8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512764()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 104));
}


// ========================================================================
// __unwind$512765
// EA  : 0x82D685E0
// RVA : 0x00D685E0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512765()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ?WriteSSObjectType@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD22PAX2@Z
// EA  : 0x82D68610
// RVA : 0x00D68610
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteSSObjectType(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *varType,
        const char *varOps,
        const char *varName,
        const bool *varPtr,
        const char *comment)
{
  ssVarInfo_t *VariablesFor; // r30
  const enumTypeInfo_t *v15; // r3
  const enumTypeInfo_t *v16; // r27
  const char **v17; // r11
  float v18; // r25
  __int64 v19; // r6
  int v20; // r10
  const enumValueInfo_t *values; // r9
  const enumValueInfo_t *v22; // r11
  __int64 v23; // r10
  int v24; // r28
  __int64 v25; // r8
  int v26; // r30
  int v27; // r10
  int value; // r11
  va *data; // r4
  const enumTypeInfo_t *EnumInfo; // r3
  const enumValueInfo_t *v31; // r11
  int v32; // r4
  const char *name; // r10
  int v34; // r5
  const char *v35; // r11
  const char *v36; // r10
  int v37; // r11
  char *v38; // r28
  int v39; // r25
  int TypeSize; // r24
  int i; // r30
  int v42; // r5
  const char *v43; // r11
  const char *v44; // r10
  int v45; // r11
  int v46; // r27
  idEntity *v47; // r3
  char v48; // r11
  idSSObject *v49; // r3
  const char *v50; // r3
  const char *v51; // r4
  long double v52; // fp2
  long double v53; // fp2
  const char *type; // r4
  const char **p_name; // r30
  void *v56; // [sp+8h] [-1178h]
  int v57; // [sp+Ch] [-1174h]
  int v58; // [sp+10h] [-1170h]
  int v59; // [sp+14h] [-116Ch]
  int v60; // [sp+18h] [-1168h]
  int v61; // [sp+1Ch] [-1164h]
  int v62; // [sp+20h] [-1160h]
  int v63; // [sp+24h] [-115Ch]
  int v64; // [sp+28h] [-1158h]
  int v65; // [sp+2Ch] [-1154h]
  int v66; // [sp+30h] [-1150h]
  int v67; // [sp+34h] [-114Ch]
  int v68; // [sp+38h] [-1148h]
  int v69; // [sp+3Ch] [-1144h]
  int v70; // [sp+40h] [-1140h]
  int v71; // [sp+44h] [-113Ch]
  int v72; // [sp+48h] [-1138h]
  int v73; // [sp+4Ch] [-1134h]
  int v74; // [sp+50h] [-1130h]
  idEntityPtr<idEntity> v75; // [sp+60h] [-1120h] BYREF
  idStr v76; // [sp+70h] [-1110h] BYREF
  idStr v77; // [sp+90h] [-10F0h] BYREF
  idStr v78; // [sp+B0h] [-10D0h] BYREF
  idStr v79; // [sp+D0h] [-10B0h] BYREF
  idStr v80; // [sp+F0h] [-1090h] BYREF
  va v81; // [sp+110h] [-1070h] BYREF

  VariablesFor = idSuperScriptSystem::GetVariablesFor(this: &gameLocal->superScript, type: varType);
  if ( VariablesFor != nullptr )
  {
    idTypeInfoFile::WriteOpeningBrace(this: file);
    idTypeInfoFile::WriteComment(this: file, comment);
    type = VariablesFor->type;
    if ( VariablesFor->type != nullptr )
    {
      p_name = &VariablesFor->name;
      do
      {
        idTypeInfoFile::WriteType(this: file, type, ops: *(p_name - 1), name: *p_name);
        WriteSSObjectType(
          ti,
          file,
          varType: *(p_name - 2),
          varOps: *(p_name - 1),
          varName: *p_name,
          varPtr: (void *)&varPtr[(_DWORD)p_name[2]],
          comment: p_name[1]);
        p_name += 6;
        type = *(p_name - 2);
      }
      while ( type != nullptr );
    }
    idTypeInfoFile::WriteClosingBrace(this: file);
    return;
  }
  v15 = gameLocal->SS_FindEnumTypeInfo(this: gameLocal, a2: varType);
  v16 = v15;
  if ( v15 != nullptr )
  {
    v17 = &v15->values->name;
    if ( v17 != nullptr )
    {
      v18 = *(float *)varPtr;
      idStr::idStr(this: &v80, text: *v17);
      v20 = v16->flags & 0x400000;
      if ( v20 != 0 )
      {
        LODWORD(v23) = v77.baseBuffer;
        HIDWORD(v23) = 0;
        v77.allocedAndFlag = 20;
        LODWORD(v25) = 0;
        v77.data = v77.baseBuffer;
        v77.len = 0;
        v77.baseBuffer[0] = 0;
        v24 = 0;
        HIDWORD(v25) = v16->values->name;
        if ( HIDWORD(v25) == 0 )
          goto LABEL_22;
        v26 = 0;
        LODWORD(v23) = v16->values;
        do
        {
          v27 = *(_DWORD *)(v23 + 4);
          if ( v27 != 0 )
          {
            value = v16->values[v26].value;
            LODWORD(v25) = value - 1;
            HIDWORD(v25) = (value - 1) & value;
            if ( HIDWORD(v25) == 0 && (v27 & LODWORD(v18)) != 0 )
            {
              if ( HIDWORD(v23) != 0 )
                idStr::operator+=(this: &v77, a: 32);
              idStr::Append(this: &v77, text: (char *)v16->values[v26].name);
              HIDWORD(v23) = v77.len;
            }
          }
          v26 = ++v24;
          LODWORD(v23) = &v16->values[v24];
        }
        while ( *(_DWORD *)v23 != 0 );
        if ( HIDWORD(v23) != 0 )
        {
          data = (va *)v77.data;
        }
        else
        {
LABEL_22:
          HIDWORD(v19) = *(_DWORD *)varPtr;
          data = va::va(
                   this: &v81,
                   fmt: "%d",
                   a3: v19,
                   a4: v25,
                   a5: v23,
                   a6: (int)v56,
                   a7: v57,
                   a8: v58,
                   a9: v59,
                   a10: v60,
                   a11: v61);
        }
        idTypeInfoFile::WriteStr(this: file, s: data->buffer);
        idStr::FreeData(this: &v77);
      }
      else
      {
        values = v16->values;
        if ( values->name != nullptr )
        {
          v22 = v16->values;
          while ( v22->value != LODWORD(v18) )
          {
            v22 = &values[++v20];
            if ( v22->name == nullptr )
              goto LABEL_9;
          }
          idTypeInfoFile::WriteStr(this: file, s: v22->name);
          idTypeInfoFile::WriteComment(this: file, comment);
          idStr::FreeData(this: &v80);
          return;
        }
LABEL_9:
        idTypeInfoFile::WriteStr(this: file, s: v80.data);
      }
      idTypeInfoFile::WriteComment(this: file, comment);
      idStr::FreeData(this: &v80);
      return;
    }
  }
  EnumInfo = idTypeInfoTools::FindEnumInfo(this: ti, typeName: varType);
  if ( EnumInfo != nullptr )
  {
    v31 = EnumInfo->values;
    v32 = *(_DWORD *)varPtr;
    name = v31->name;
    if ( v31->name != nullptr )
    {
      while ( v31->value != v32 )
      {
        ++v31;
        name = v31->name;
        if ( v31->name == nullptr )
          goto LABEL_29;
      }
      idTypeInfoFile::WriteStr(this: file, s: name);
      idTypeInfoFile::WriteComment(this: file, comment);
    }
    else
    {
LABEL_29:
      idTypeInfoFile::WriteInt(this: file, l: v32);
      idTypeInfoFile::WriteComment(this: file, comment);
    }
  }
  else
  {
    v34 = 0;
    v35 = "ssList<";
    do
    {
      ++v35;
      ++v34;
    }
    while ( *v35 != 0 );
    if ( idStr::Cmpn(s1: varType, s2: "ssList<", n: v34) != 0 )
    {
      v42 = 0;
      v43 = "ssObject<";
      do
      {
        ++v43;
        ++v42;
      }
      while ( *v43 != 0 );
      if ( idStr::Cmpn(s1: varType, s2: "ssObject<", n: v42) != 0 )
      {
        if ( idStr::Cmp(s1: varType, s2: "ssEntity") != 0 )
        {
          if ( idStr::Cmp(s1: varType, s2: "ssVector") != 0 )
          {
            if ( idStr::Cmp(s1: varType, s2: "ssColor") != 0 )
            {
              if ( idStr::Cmp(s1: varType, s2: "ssString") != 0 )
              {
                idStr::idStr(this: &v76, text: varType);
                idStr::Replace(this: &v76, old: "signed", nw: &byte_8200D768);
                idStr::Replace(this: &v76, old: "const", nw: &byte_8200D768);
                if ( idStr::Cmp(s1: v76.data, s2: "unsigned int") != 0
                  && idStr::Cmp(s1: v76.data, s2: "unsigned long") != 0 )
                {
                  if ( idStr::Cmp(s1: v76.data, s2: "int") != 0 && idStr::Cmp(s1: v76.data, s2: "long") != 0 )
                  {
                    if ( idStr::Cmp(s1: v76.data, s2: "unsigned short") != 0 )
                    {
                      if ( idStr::Cmp(s1: v76.data, s2: "short") != 0 )
                      {
                        if ( idStr::Cmp(s1: v76.data, s2: "unsigned char") != 0 )
                        {
                          if ( idStr::Cmp(s1: v76.data, s2: "char") != 0 )
                          {
                            if ( idStr::Cmp(s1: v76.data, s2: "bool") != 0 )
                            {
                              if ( idStr::Cmp(s1: v76.data, s2: "float") != 0 )
                              {
                                if ( idStr::Cmp(s1: v76.data, s2: "double") != 0 )
                                {
                                  if ( idTypeInfoTools::IsSubclassOf(this: ti, typeName: v76.data, superType: "idDecl") )
                                  {
                                    if ( *(_DWORD *)varPtr != 0 )
                                      WriteDecl(
                                        ti,
                                        file,
                                        scope: nullptr,
                                        varType,
                                        varOps,
                                        varName,
                                        varFlags: 0,
                                        comment,
                                        varPtr: v56,
                                        a10: v57,
                                        a11: v58,
                                        a12: v59,
                                        a13: v60,
                                        a14: v61,
                                        a15: v62,
                                        a16: v63,
                                        a17: v64,
                                        a18: v65,
                                        a19: v66,
                                        a20: v67,
                                        a21: v68,
                                        a22: v69,
                                        a23: v70,
                                        a24: v71,
                                        a25: v72,
                                        a26: v73,
                                        a27: v74,
                                        a28: (int)varPtr);
                                    else
                                      idTypeInfoFile::WriteNullPointer(this: file);
                                  }
                                  else
                                  {
                                    idTypeInfoFile::WriteUnknown(this: file);
                                  }
                                }
                                else
                                {
                                  *(_QWORD *)&v53 = *(_QWORD *)varPtr;
                                  idTypeInfoFile::WriteFloat(this: file, d: v53);
                                }
                              }
                              else
                              {
                                *(double *)&v52 = *(float *)varPtr;
                                idTypeInfoFile::WriteFloat(this: file, d: v52);
                              }
                            }
                            else
                            {
                              idTypeInfoFile::WriteBool(this: file, b: *varPtr);
                            }
                          }
                          else
                          {
                            idTypeInfoFile::WriteChar(this: file, c: *varPtr);
                          }
                        }
                        else
                        {
                          idTypeInfoFile::WriteUnsignedChar(this: file, c: *varPtr);
                        }
                      }
                      else
                      {
                        idTypeInfoFile::WriteShort(this: file, s: *(_WORD *)varPtr);
                      }
                    }
                    else
                    {
                      idTypeInfoFile::WriteUnsignedShort(this: file, s: *(_WORD *)varPtr);
                    }
                  }
                  else
                  {
                    idTypeInfoFile::WriteInt(this: file, l: *(_DWORD *)varPtr);
                  }
                }
                else
                {
                  idTypeInfoFile::WriteUnsignedLong(this: file, l: *(_DWORD *)varPtr);
                }
                if ( comment != nullptr )
                  idTypeInfoFile::WriteComment(this: file, comment);
                idStr::FreeData(this: &v76);
              }
              else
              {
                v51 = *((const char **)varPtr + 1);
                if ( v51 == nullptr )
                  v51 = &byte_8200D768;
                idTypeInfoFile::WriteStr(this: file, s: v51);
              }
            }
            else
            {
              idTypeInfoFile::WriteColor(this: file, c: (const idColor *)varPtr);
            }
          }
          else
          {
            idTypeInfoFile::WriteVec3(this: file, v: (const idVec3 *)varPtr);
          }
        }
        else
        {
          WriteEntityPtr(
            ti,
            file,
            scope: &byte_8200D768,
            varType,
            varOps,
            varName,
            varFlags: 0,
            comment,
            varPtr: v56,
            a10: v57,
            a11: v58,
            a12: v59,
            a13: v60,
            a14: v61,
            a15: v62,
            a16: v63,
            a17: v64,
            a18: v65,
            a19: v66,
            a20: v67,
            a21: v68,
            a22: v69,
            a23: v70,
            a24: v71,
            a25: v72,
            a26: v73,
            a27: v74,
            a28: (const idEntityPtr<idEntity> *)varPtr);
        }
      }
      else
      {
        v44 = "ssObject<";
        v45 = 0;
        do
        {
          ++v44;
          ++v45;
        }
        while ( *v44 != 0 );
        idStr::idStr(this: &v79, text: &varType[v45]);
        idStr::StripTrailingOnce(this: &v79, string: ">");
        idStr::StripLeadingWhiteSpace(this: &v79);
        idStr::StripTrailingWhitespace(this: &v79);
        if ( v79.len != 0 )
        {
          WriteEntityPtr(
            ti,
            file,
            scope: &byte_8200D768,
            varType,
            varOps,
            varName,
            varFlags: 0,
            comment,
            varPtr: v56,
            a10: v57,
            a11: v58,
            a12: v59,
            a13: v60,
            a14: v61,
            a15: v62,
            a16: v63,
            a17: v64,
            a18: v65,
            a19: v66,
            a20: v67,
            a21: v68,
            a22: v69,
            a23: v70,
            a24: v71,
            a25: v72,
            a26: v73,
            a27: v74,
            a28: (const idEntityPtr<idEntity> *)varPtr);
        }
        else
        {
          v46 = *((_DWORD *)varPtr + 1);
          v75.spawnId.value = *(_DWORD *)varPtr;
          idTypeInfoFile::WriteOpeningBrace(this: file);
          idTypeInfoFile::WriteType(this: file, type: "ssEntity", ops: &byte_8200D768, name: "self");
          WriteEntityPtr(
            ti,
            file,
            scope: &byte_8200D768,
            varType,
            varOps,
            varName,
            varFlags: 0,
            comment,
            varPtr: v56,
            a10: v57,
            a11: v58,
            a12: v59,
            a13: v60,
            a14: v61,
            a15: v62,
            a16: v63,
            a17: v64,
            a18: v65,
            a19: v66,
            a20: v67,
            a21: v68,
            a22: v69,
            a23: v70,
            a24: v71,
            a25: v72,
            a26: v73,
            a27: v74,
            a28: &v75);
          idTypeInfoFile::WriteType(this: file, type: "ssString", ops: &byte_8200D768, name: "type");
          v47 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: v75.spawnId.value);
          if ( v47 == nullptr )
            goto LABEL_54;
          if ( v46 < 0 || (v48 = 1, v46 >= v47->superScriptObjects.num) )
            v48 = 0;
          if ( v48 != 0 && (v49 = v47->superScriptObjects.list[v46]) != nullptr )
          {
            v50 = v49->_name(this: v49);
            idTypeInfoFile::WriteStr(this: file, s: v50);
            idTypeInfoFile::WriteClosingBrace(this: file);
          }
          else
          {
LABEL_54:
            idTypeInfoFile::WriteStr(this: file, s: &byte_8200D768);
            idTypeInfoFile::WriteClosingBrace(this: file);
          }
        }
        idStr::FreeData(this: &v79);
      }
    }
    else
    {
      v36 = "ssList<";
      v37 = 0;
      do
      {
        ++v36;
        ++v37;
      }
      while ( *v36 != 0 );
      idStr::idStr(this: &v78, text: &varType[v37]);
      idStr::StripTrailingOnce(this: &v78, string: ">");
      idStr::StripLeadingWhiteSpace(this: &v78);
      idStr::StripTrailingWhitespace(this: &v78);
      v38 = *(char **)varPtr;
      v39 = *((_DWORD *)varPtr + 1);
      TypeSize = idSuperScriptSystem::GetTypeSize(this: &gameLocal->superScript, type: v78.data);
      idTypeInfoFile::WriteOpeningBrace(this: file);
      if ( comment != nullptr )
        idTypeInfoFile::WriteComment(this: file, comment);
      idTypeInfoFile::WriteType(this: file, type: "int", ops: &byte_8200D768, name: "num");
      idTypeInfoFile::WriteInt(this: file, l: v39);
      for ( i = 0; i < v39; v38 += TypeSize )
      {
        idTypeInfoFile::WriteArrayElementType(this: file, type: v78.data, ops: &byte_8200D768, name: "item", i);
        WriteSSObjectType(
          ti,
          file,
          varType: v78.data,
          varOps: &byte_8200D768,
          varName: "item",
          varPtr: v38,
          comment: nullptr);
        ++i;
      }
      idTypeInfoFile::WriteClosingBrace(this: file);
      idStr::FreeData(this: &v78);
    }
  }
}


// ========================================================================
// __unwind$512953
// EA  : 0x82D68F6C
// RVA : 0x00D68F6C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512953()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 240));
}


// ========================================================================
// __unwind$512954
// EA  : 0x82D68F94
// RVA : 0x00D68F94
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512954()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 144));
}


// ========================================================================
// __unwind$512955
// EA  : 0x82D68FBC
// RVA : 0x00D68FBC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512955()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 176));
}


// ========================================================================
// __unwind$512956
// EA  : 0x82D68FE4
// RVA : 0x00D68FE4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512956()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 208));
}


// ========================================================================
// __unwind$512957
// EA  : 0x82D6900C
// RVA : 0x00D6900C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_512957()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 112));
}


// ========================================================================
// ?ReadSSObjectType@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD22PAX@Z
// EA  : 0x82D69040
// RVA : 0x00D69040
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadSSObjectType(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *varType,
        const char *varOps,
        const char *varName,
        char *varPtr)
{
  ssVarInfo_t *VariablesFor; // r28
  const enumTypeInfo_t *v13; // r3
  const enumTypeInfo_t *v14; // r22
  char *data; // r3
  int v16; // r11
  const enumValueInfo_t *values; // r9
  int v18; // r30
  int v19; // r11
  const enumValueInfo_t *v20; // r10
  int v21; // r3
  int v22; // r3
  const enumValueInfo_t *EnumValueInfo; // r3
  char *v24; // r29
  int allocedAndFlag; // r10
  char v26; // r30
  int i; // r11
  int v28; // r11
  const enumValueInfo_t *v29; // r3
  const enumTypeInfo_t *EnumInfo; // r3
  const enumValueInfo_t *v31; // r30
  const char *name; // r3
  int v33; // r5
  const char *v34; // r11
  const char *v35; // r10
  int v36; // r11
  int *v37; // r25
  int TypeSize; // r28
  int v39; // r5
  const char *v40; // r11
  const char *v41; // r10
  int v42; // r11
  int len; // r11
  int v44; // r9
  int v45; // r4
  int v46; // r3
  char v47; // r29
  ssVarInfo_t *v48; // r30
  void *v49; // [sp+8h] [-278h]
  int v50; // [sp+Ch] [-274h]
  int v51; // [sp+10h] [-270h]
  int v52; // [sp+14h] [-26Ch]
  int v53; // [sp+18h] [-268h]
  int v54; // [sp+1Ch] [-264h]
  int v55; // [sp+20h] [-260h]
  int v56; // [sp+24h] [-25Ch]
  int v57; // [sp+28h] [-258h]
  int v58; // [sp+2Ch] [-254h]
  int v59; // [sp+30h] [-250h]
  int v60; // [sp+34h] [-24Ch]
  int v61; // [sp+38h] [-248h]
  int v62; // [sp+3Ch] [-244h]
  int v63; // [sp+40h] [-240h]
  int v64; // [sp+44h] [-23Ch]
  int v65; // [sp+48h] [-238h]
  int v66; // [sp+4Ch] [-234h]
  int v67; // [sp+50h] [-230h]
  int v68[4]; // [sp+60h] [-220h] BYREF
  idStr v69; // [sp+70h] [-210h] BYREF
  idStr v70; // [sp+90h] [-1F0h] BYREF
  idStr v71; // [sp+B0h] [-1D0h] BYREF
  idStr v72; // [sp+D0h] [-1B0h] BYREF
  idStr v73; // [sp+F0h] [-190h] BYREF
  idStr v74; // [sp+110h] [-170h] BYREF
  idStr v75; // [sp+130h] [-150h] BYREF
  idStr v76; // [sp+150h] [-130h] BYREF
  idStr v77; // [sp+170h] [-110h] BYREF
  idStr v78; // [sp+190h] [-F0h] BYREF
  idStr v79; // [sp+1B0h] [-D0h] BYREF
  idStr v80; // [sp+1D0h] [-B0h] BYREF
  idStr v81[4]; // [sp+1F0h] [-90h] BYREF

  VariablesFor = idSuperScriptSystem::GetVariablesFor(this: &gameLocal->superScript, type: varType);
  if ( VariablesFor != nullptr )
  {
    if ( idTypeInfoFile::CheckOpeningBrace(this: file) && !idTypeInfoFile::CheckClosingBrace(this: file) )
    {
      do
      {
        if ( idTypeInfoFile::HadError(this: file) )
          break;
        v81[0].allocedAndFlag = 20;
        v81[0].len = 0;
        v81[0].data = v81[0].baseBuffer;
        v81[0].baseBuffer[0] = 0;
        v79.allocedAndFlag = 20;
        v79.data = v79.baseBuffer;
        v79.len = 0;
        v79.baseBuffer[0] = 0;
        v76.allocedAndFlag = 20;
        v76.data = v76.baseBuffer;
        v76.len = 0;
        v76.baseBuffer[0] = 0;
        idTypeInfoFile::ReadType(this: file, type: v81, ops: &v79, name: &v76);
        v47 = 0;
        v48 = VariablesFor;
        if ( VariablesFor->type != nullptr )
        {
          while ( idStr::Cmp(s1: v48->name, s2: v76.data) != 0 )
          {
            ++v48;
            if ( v48->type == nullptr )
              goto LABEL_114;
          }
          ReadSSObjectType(
            ti,
            file,
            varType: v48->type,
            varOps: v48->ops,
            varName: v48->name,
            varPtr: &varPtr[v48->offset]);
          v47 = 1;
        }
LABEL_114:
        if ( v47 == 0 )
          idTypeInfoFile::ReadUnknown(this: file);
        idStr::FreeData(this: &v76);
        idStr::FreeData(this: &v79);
        idStr::FreeData(this: v81);
      }
      while ( !idTypeInfoFile::CheckClosingBrace(this: file) );
    }
  }
  else
  {
    v13 = gameLocal->SS_FindEnumTypeInfo(this: gameLocal, a2: varType);
    v14 = v13;
    if ( v13 != nullptr && v13->values != nullptr )
    {
      v71.len = 0;
      v71.allocedAndFlag = 20;
      v71.data = v71.baseBuffer;
      v71.baseBuffer[0] = 0;
      idTypeInfoFile::ReadStr(this: file, s: &v71);
      data = v71.data;
      if ( v71.len != 0 && ((v16 = *v71.data) == 45 || v16 >= 48 && v16 <= 57) )
      {
        if ( (v14->flags & 0x400000) != 0 )
        {
          values = v14->values;
          v18 = 0;
          v19 = 0;
          if ( values->name != nullptr )
          {
            v20 = v14->values;
            do
            {
              ++v19;
              v18 |= v20->value;
              v20 = &values[v19];
            }
            while ( v20->name != nullptr );
          }
          v21 = atol(nptr: v71.data);
          if ( (v21 & ~v18) == 0 )
          {
            *(_DWORD *)varPtr = v21;
            goto LABEL_39;
          }
LABEL_13:
          idTypeInfoFile::Warning(this: file, str: "reading unknown value %s for enum %s", v71.data, varType);
LABEL_39:
          idStr::FreeData(this: &v71);
          return;
        }
        v22 = atol(nptr: v71.data);
        EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(this: ti, enumInfo: v14, value: v22);
      }
      else
      {
        if ( (v14->flags & 0x400000) != 0 )
        {
          *(_DWORD *)varPtr = 0;
          v24 = data;
          while ( *v24 != 0 )
          {
            v70.baseBuffer[0] = 0;
            allocedAndFlag = 20;
            v70.len = 0;
            v70.allocedAndFlag = 20;
            v70.data = v70.baseBuffer;
            v26 = *v24;
            for ( i = *v24; i == 32; i = *v24 )
              v26 = *++v24;
            if ( i != 0 )
            {
              while ( i != 32 )
              {
                v28 = v70.len + 2;
                if ( allocedAndFlag >= 0 )
                {
                  if ( v28 > (allocedAndFlag & 0x7FFFFFFF) )
                    idStr::ReAllocate(this: &v70, amount: (v28 >> 1) + v28, keepold: true);
                }
                else if ( v28 > (allocedAndFlag & 0x7FFFFFFF)
                       && AssertFailed(
                            file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                            line: 463,
                            expression: "amount <= GetAlloced()",
                            inlineBreak: true) )
                {
                  __trap();
                }
                v70.data[v70.len++] = v26;
                v70.data[v70.len] = 0;
                v26 = *++v24;
                i = *v24;
                if ( *v24 == 0 )
                  break;
                allocedAndFlag = v70.allocedAndFlag;
              }
            }
            v29 = idTypeInfoTools::FindEnumValueInfo(this: ti, enumInfo: v14, name: v70.data, defaultIfNotFound: false);
            if ( v29 != nullptr )
              *(_DWORD *)varPtr |= v29->value;
            else
              idTypeInfoFile::Warning(this: file, str: "reading unknown value %s for enum %s", v70.data, varType);
            idStr::FreeData(this: &v70);
          }
          goto LABEL_39;
        }
        EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                          this: ti,
                          enumInfo: v14,
                          name: v71.data,
                          defaultIfNotFound: false);
      }
      if ( EnumValueInfo != nullptr )
      {
        *(_DWORD *)varPtr = EnumValueInfo->value;
        goto LABEL_39;
      }
      goto LABEL_13;
    }
    EnumInfo = idTypeInfoTools::FindEnumInfo(this: ti, typeName: varType);
    if ( EnumInfo != nullptr )
    {
      v31 = EnumInfo->values;
      v72.len = 0;
      v72.allocedAndFlag = 20;
      v72.data = v72.baseBuffer;
      v72.baseBuffer[0] = 0;
      idTypeInfoFile::ReadStr(this: file, s: &v72);
      name = v31->name;
      if ( v31->name != nullptr )
      {
        while ( 1 )
        {
          v68[0] = (int)name;
          if ( idStr::Cmp(s1: name, s2: v72.data) == 0 )
            break;
          ++v31;
          name = v31->name;
          if ( v31->name == nullptr )
            goto LABEL_44;
        }
        *(_DWORD *)varPtr = v31->value;
        idStr::FreeData(this: &v72);
      }
      else
      {
LABEL_44:
        *(_DWORD *)varPtr = atol(nptr: v72.data);
        idStr::FreeData(this: &v72);
      }
    }
    else
    {
      v33 = 0;
      v34 = "ssList<";
      do
      {
        ++v34;
        ++v33;
      }
      while ( *v34 != 0 );
      if ( idStr::Cmpn(s1: varType, s2: "ssList<", n: v33) != 0 )
      {
        v39 = 0;
        v40 = "ssObject<";
        do
        {
          ++v40;
          ++v39;
        }
        while ( *v40 != 0 );
        if ( idStr::Cmpn(s1: varType, s2: "ssObject<", n: v39) != 0 )
        {
          if ( idStr::Cmp(s1: varType, s2: "ssEntity") != 0 )
          {
            if ( idStr::Cmp(s1: varType, s2: "ssVector") != 0 )
            {
              if ( idStr::Cmp(s1: varType, s2: "ssColor") != 0 )
              {
                if ( idStr::Cmp(s1: varType, s2: "ssString") != 0 )
                {
                  idStr::idStr(this: &v69, text: varType);
                  idStr::Replace(this: &v69, old: "signed", nw: &byte_8200D768);
                  idStr::Replace(this: &v69, old: "const", nw: &byte_8200D768);
                  if ( idStr::Cmp(s1: v69.data, s2: "unsigned int") != 0
                    && idStr::Cmp(s1: v69.data, s2: "unsigned long") != 0
                    && idStr::Cmp(s1: v69.data, s2: "int") != 0
                    && idStr::Cmp(s1: v69.data, s2: "long") != 0 )
                  {
                    if ( idStr::Cmp(s1: v69.data, s2: "unsigned short") != 0
                      && idStr::Cmp(s1: v69.data, s2: "short") != 0 )
                    {
                      if ( idStr::Cmp(s1: v69.data, s2: "unsigned char") != 0
                        && idStr::Cmp(s1: v69.data, s2: "char") != 0 )
                      {
                        if ( idStr::Cmp(s1: v69.data, s2: "bool") != 0 )
                        {
                          if ( idStr::Cmp(s1: v69.data, s2: "float") != 0 )
                          {
                            if ( idStr::Cmp(s1: v69.data, s2: "double") != 0 )
                            {
                              if ( idTypeInfoTools::IsSubclassOf(this: ti, typeName: v69.data, superType: "idDecl") )
                              {
                                if ( idTypeInfoFile::CheckNullPointer(this: file) )
                                  *(_DWORD *)varPtr = 0;
                                else
                                  ReadDecl(
                                    ti,
                                    file,
                                    scope: nullptr,
                                    varType,
                                    varOps,
                                    varName,
                                    varFlags: 0,
                                    comment: nullptr,
                                    varPtr: v49,
                                    a10: v50,
                                    a11: v51,
                                    a12: v52,
                                    a13: v53,
                                    a14: v54,
                                    a15: v55,
                                    a16: v56,
                                    a17: v57,
                                    a18: v58,
                                    a19: v59,
                                    a20: v60,
                                    a21: v61,
                                    a22: v62,
                                    a23: v63,
                                    a24: v64,
                                    a25: v65,
                                    a26: v66,
                                    a27: v67,
                                    a28: (const idDecl **)varPtr);
                              }
                              else
                              {
                                idTypeInfoFile::ReadUnknown(this: file);
                              }
                            }
                            else
                            {
                              idTypeInfoFile::ReadDouble(this: file, d: (long double *)varPtr);
                            }
                          }
                          else
                          {
                            idTypeInfoFile::ReadFloat(this: file, f: (float *)varPtr);
                          }
                        }
                        else
                        {
                          idTypeInfoFile::ReadBool(this: file, b: (bool *)varPtr);
                        }
                      }
                      else
                      {
                        idTypeInfoFile::ReadUnsignedChar(this: file, c: (unsigned __int8 *)varPtr);
                      }
                    }
                    else
                    {
                      idTypeInfoFile::ReadWChar(this: file, s: (unsigned __int16 *)varPtr);
                    }
                  }
                  else
                  {
                    idTypeInfoFile::ReadUnsignedLong(this: file, l: (unsigned int *)varPtr);
                  }
                  idStr::FreeData(this: &v69);
                }
                else
                {
                  v73.len = 0;
                  v73.baseBuffer[0] = 0;
                  v73.allocedAndFlag = 20;
                  v73.data = v73.baseBuffer;
                  idTypeInfoFile::ReadStr(this: file, s: &v73);
                  len = v73.len;
                  v44 = *((_DWORD *)varPtr + 2);
                  v45 = v73.len + 1;
                  *(_DWORD *)varPtr = v73.len;
                  if ( len + 1 > v44 )
                  {
                    *((_DWORD *)varPtr + 2) = v45;
                    v46 = ((int (__fastcall *)(idSuperScriptSystem *))gameLocal->superScript.Allocate)(a1: &gameLocal->superScript);
                    len = v73.len;
                    *((_DWORD *)varPtr + 1) = v46;
                  }
                  memcpy(Dst: *((void **)varPtr + 1), Src: v73.data, Size: len + 1);
                  idStr::FreeData(this: &v73);
                }
              }
              else
              {
                idTypeInfoFile::ReadColor(this: file, c: (idColor *)varPtr);
              }
            }
            else
            {
              idTypeInfoFile::ReadVec3(this: file, v: (idVec3 *)varPtr);
            }
          }
          else
          {
            ReadEntityPtr(
              ti,
              file,
              scope: &byte_8200D768,
              varType,
              varOps,
              varName,
              varFlags: 0,
              comment: &byte_8200D768,
              varPtr: v49,
              a10: v50,
              a11: v51,
              a12: v52,
              a13: v53,
              a14: v54,
              a15: v55,
              a16: v56,
              a17: v57,
              a18: v58,
              a19: v59,
              a20: v60,
              a21: v61,
              a22: v62,
              a23: v63,
              a24: v64,
              a25: v65,
              a26: v66,
              a27: v67,
              a28: (idEntityPtr<idEntity> *)varPtr);
          }
        }
        else
        {
          v41 = "ssObject<";
          v42 = 0;
          do
          {
            ++v41;
            ++v42;
          }
          while ( *v41 != 0 );
          idStr::idStr(this: &v75, text: &varType[v42]);
          idStr::StripTrailingOnce(this: &v75, string: ">");
          idStr::StripLeadingWhiteSpace(this: &v75);
          idStr::StripTrailingWhitespace(this: &v75);
          if ( v75.len != 0 )
          {
            ReadEntityPtr(
              ti,
              file,
              scope: &byte_8200D768,
              varType,
              varOps,
              varName,
              varFlags: 0,
              comment: &byte_8200D768,
              varPtr: v49,
              a10: v50,
              a11: v51,
              a12: v52,
              a13: v53,
              a14: v54,
              a15: v55,
              a16: v56,
              a17: v57,
              a18: v58,
              a19: v59,
              a20: v60,
              a21: v61,
              a22: v62,
              a23: v63,
              a24: v64,
              a25: v65,
              a26: v66,
              a27: v67,
              a28: (idEntityPtr<idEntity> *)varPtr);
          }
          else
          {
            idTypeInfoFile::ReadOpeningBrace(this: file);
            idTypeInfoFile::ExpectType(this: file, type: "ssEntity", ops: &byte_8200D768, name: "self");
            ReadEntityPtr(
              ti,
              file,
              scope: &byte_8200D768,
              varType,
              varOps,
              varName,
              varFlags: 0,
              comment: &byte_8200D768,
              varPtr: v49,
              a10: v50,
              a11: v51,
              a12: v52,
              a13: v53,
              a14: v54,
              a15: v55,
              a16: v56,
              a17: v57,
              a18: v58,
              a19: v59,
              a20: v60,
              a21: v61,
              a22: v62,
              a23: v63,
              a24: v64,
              a25: v65,
              a26: v66,
              a27: v67,
              a28: (idEntityPtr<idEntity> *)varPtr);
            idTypeInfoFile::ExpectType(this: file, type: "ssString", ops: &byte_8200D768, name: "type");
            idTypeInfoFile::ReadStr(this: file, s: &v75);
            *((_DWORD *)varPtr + 1) = gameLocal->superScript.FindObject(
                                        this: &gameLocal->superScript,
                                        a2: *(_DWORD *)varPtr,
                                        a3: v75.data,
                                        a4: true);
            idTypeInfoFile::ReadClosingBrace(this: file);
          }
          idStr::FreeData(this: &v75);
        }
      }
      else
      {
        v35 = "ssList<";
        v36 = 0;
        do
        {
          ++v35;
          ++v36;
        }
        while ( *v35 != 0 );
        idStr::idStr(this: &v74, text: &varType[v36]);
        idStr::StripTrailingOnce(this: &v74, string: ">");
        idStr::StripLeadingWhiteSpace(this: &v74);
        idStr::StripTrailingWhitespace(this: &v74);
        v37 = (int *)(varPtr + 4);
        TypeSize = idSuperScriptSystem::GetTypeSize(this: &gameLocal->superScript, type: v74.data);
        idTypeInfoFile::ReadOpeningBrace(this: file);
        if ( idTypeInfoFile::ExpectType(this: file, type: "int", ops: &byte_8200D768, name: "num") )
        {
          idTypeInfoFile::ReadUnsignedLong(this: file, l: (unsigned int *)varPtr + 1);
          if ( *v37 <= 0 )
          {
            while ( !idTypeInfoFile::CheckClosingBrace(this: file) )
              idTypeInfoFile::ReadUnknown(this: file);
          }
          else
          {
            *(_DWORD *)varPtr = idSuperScriptSystem::AllocType(this: &gameLocal->superScript, type: v74.data, num: *v37);
            v68[0] = 0;
            v78.allocedAndFlag = 20;
            v78.data = v78.baseBuffer;
            v78.len = 0;
            v78.baseBuffer[0] = 0;
            v77.allocedAndFlag = 20;
            v77.data = v77.baseBuffer;
            v77.len = 0;
            v77.baseBuffer[0] = 0;
            v80.allocedAndFlag = 20;
            v80.data = v80.baseBuffer;
            v80.len = 0;
            v80.baseBuffer[0] = 0;
            while ( !idTypeInfoFile::CheckClosingBrace(this: file) )
            {
              if ( idTypeInfoFile::HadError(this: file)
                || !idTypeInfoFile::CheckArrayElementType(this: file, type: &v78, ops: &v77, name: &v80, index: v68) )
              {
                break;
              }
              if ( v68[0] >= *v37 )
                idTypeInfoFile::ReadUnknown(this: file);
              else
                ReadSSObjectType(
                  ti,
                  file,
                  varType: v74.data,
                  varOps: &byte_8200D768,
                  varName: "item",
                  varPtr: (void *)(v68[0] * TypeSize + *(_DWORD *)varPtr));
            }
            idStr::FreeData(this: &v80);
            idStr::FreeData(this: &v77);
            idStr::FreeData(this: &v78);
          }
        }
        idStr::FreeData(this: &v74);
      }
    }
  }
}


// ========================================================================
// __unwind$513212
// EA  : 0x82D69C70
// RVA : 0x00D69C70
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513212()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 176));
}


// ========================================================================
// __unwind$513213
// EA  : 0x82D69C98
// RVA : 0x00D69C98
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513213()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 144));
}


// ========================================================================
// __unwind$513214
// EA  : 0x82D69CC0
// RVA : 0x00D69CC0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513214()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 208));
}


// ========================================================================
// __unwind$513215
// EA  : 0x82D69CE8
// RVA : 0x00D69CE8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513215()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 272));
}


// ========================================================================
// __unwind$513216
// EA  : 0x82D69D10
// RVA : 0x00D69D10
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513216()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 400));
}


// ========================================================================
// __unwind$513217
// EA  : 0x82D69D38
// RVA : 0x00D69D38
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513217()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 368));
}


// ========================================================================
// __unwind$513218
// EA  : 0x82D69D60
// RVA : 0x00D69D60
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513218()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 464));
}


// ========================================================================
// __unwind$513219
// EA  : 0x82D69D88
// RVA : 0x00D69D88
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513219()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 304));
}


// ========================================================================
// __unwind$513220
// EA  : 0x82D69DB0
// RVA : 0x00D69DB0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513220()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 240));
}


// ========================================================================
// __unwind$513221
// EA  : 0x82D69DD8
// RVA : 0x00D69DD8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513221()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 112));
}


// ========================================================================
// __unwind$513222
// EA  : 0x82D69E00
// RVA : 0x00D69E00
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513222()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 496));
}


// ========================================================================
// __unwind$513223
// EA  : 0x82D69E28
// RVA : 0x00D69E28
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513223()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 432));
}


// ========================================================================
// __unwind$513224
// EA  : 0x82D69E50
// RVA : 0x00D69E50
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513224()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 336));
}


// ========================================================================
// ?WriteSSObject@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D69E78
// RVA : 0x00D69E78
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteSSObject(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int *a28)
{
  int v31; // r30
  const char *v32; // r3
  const char *v33; // r3
  const char *v34; // r3
  const char *CommentTextFor; // r3
  const char *v36; // r3
  ssVarInfo_t *VariablesFor; // r3
  const char *type; // r4
  const char **p_name; // r31

  v31 = *a28;
  if ( *a28 != 0 )
  {
    idTypeInfoFile::WriteOpeningBrace(this: file);
    idTypeInfoFile::WriteComment(this: file, comment);
    idTypeInfoFile::WriteType(this: file, type: "idSSObjectName", ops: &byte_8200D768, name: "object");
    v32 = (const char *)(*(int (__fastcall **)(int))(*(_DWORD *)v31 + 92))(a1: v31);
    idTypeInfoFile::WriteStr(this: file, s: v32);
    v33 = (const char *)(*(int (__fastcall **)(int))(*(_DWORD *)v31 + 92))(a1: v31);
    if ( idSuperScriptSystem::GetCommentTextFor(this: &gameLocal->superScript, type: v33) != nullptr )
    {
      v34 = (const char *)(*(int (__fastcall **)(int))(*(_DWORD *)v31 + 92))(a1: v31);
      CommentTextFor = idSuperScriptSystem::GetCommentTextFor(this: &gameLocal->superScript, type: v34);
      idTypeInfoFile::WriteComment(this: file, comment: CommentTextFor);
    }
    v36 = (const char *)(*(int (__fastcall **)(int))(*(_DWORD *)v31 + 92))(a1: v31);
    VariablesFor = idSuperScriptSystem::GetVariablesFor(this: &gameLocal->superScript, type: v36);
    if ( VariablesFor != nullptr )
    {
      type = VariablesFor->type;
      if ( VariablesFor->type != nullptr )
      {
        p_name = &VariablesFor->name;
        do
        {
          idTypeInfoFile::WriteType(this: file, type, ops: *(p_name - 1), name: *p_name);
          WriteSSObjectType(
            ti,
            file,
            varType: *(p_name - 2),
            varOps: *(p_name - 1),
            varName: *p_name,
            varPtr: (const bool *)&p_name[2][v31],
            comment: p_name[1]);
          p_name += 6;
          type = *(p_name - 2);
        }
        while ( type != nullptr );
      }
    }
    idTypeInfoFile::WriteClosingBrace(this: file);
  }
  else
  {
    idTypeInfoFile::WriteNullPointer(this: file);
  }
}


// ========================================================================
// ?ReadSSObject@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D6A000
// RVA : 0x00D6A000
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadSSObject(
        idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idSSObject **a28)
{
  idSSObject *Object; // r24
  idStr *v31; // r3
  ssVarInfo_t *VariablesFor; // r26
  char v33; // r27
  ssVarInfo_t *v34; // r30
  idStr v35; // [sp+50h] [-100h] BYREF
  idStr v36; // [sp+70h] [-E0h] BYREF
  idStr v37; // [sp+90h] [-C0h] BYREF
  idStr v38; // [sp+B0h] [-A0h] BYREF
  idStr v39[4]; // [sp+D0h] [-80h] BYREF

  Object = nullptr;
  if ( !idTypeInfoFile::CheckNullPointer(this: file) )
  {
    if ( !idTypeInfoFile::CheckOpeningBrace(this: file) )
    {
      v36.len = 0;
      v36.baseBuffer[0] = 0;
      v36.allocedAndFlag = 20;
      v36.data = v36.baseBuffer;
      idTypeInfoFile::ReadStr(this: file, s: &v36);
      Object = idSuperScriptSystem::CreateObject(this: &gameLocal->superScript, name: v36.data);
      if ( Object == nullptr && (gameLocal->GetGameFlags(this: gameLocal) & 8) != 0 )
        idLib::Error(fmt: "Could not create Super Script object %s", v36.data);
      v31 = &v36;
      goto LABEL_17;
    }
    if ( idTypeInfoFile::CheckClosingBrace(this: file) )
      goto LABEL_18;
    if ( !idTypeInfoFile::ExpectType(this: file, type: "idSSObjectName", ops: &byte_8200D768, name: "object") )
    {
      idLexer::SkipBracedSection(this: &file->src, parseFirstBrace: false);
      *a28 = nullptr;
      return;
    }
    if ( idTypeInfoFile::CheckNullPointer(this: file) )
    {
      idLib::Warning(fmt: "NULL entry in superscript list");
      idLexer::SkipBracedSection(this: &file->src, parseFirstBrace: false);
      goto LABEL_18;
    }
    v35.len = 0;
    v35.baseBuffer[0] = 0;
    v35.allocedAndFlag = 20;
    v35.data = v35.baseBuffer;
    idTypeInfoFile::ReadStr(this: file, s: &v35);
    if ( idStr::Cmp(s1: v35.data, s2: "NULL") != 0 )
    {
      Object = idSuperScriptSystem::CreateObject(this: &gameLocal->superScript, name: v35.data);
      if ( Object == nullptr )
      {
        if ( (gameLocal->GetGameFlags(this: gameLocal) & 8) == 0 )
          goto LABEL_15;
        idLib::Error(fmt: "Could not create Super Script object %s", v35.data);
      }
      VariablesFor = idSuperScriptSystem::GetVariablesFor(this: &gameLocal->superScript, type: v35.data);
      if ( VariablesFor != nullptr )
      {
        while ( !idTypeInfoFile::CheckClosingBrace(this: file) )
        {
          if ( idTypeInfoFile::HadError(this: file) )
            break;
          v39[0].allocedAndFlag = 20;
          v39[0].len = 0;
          v39[0].data = v39[0].baseBuffer;
          v39[0].baseBuffer[0] = 0;
          v38.allocedAndFlag = 20;
          v38.data = v38.baseBuffer;
          v38.len = 0;
          v38.baseBuffer[0] = 0;
          v37.allocedAndFlag = 20;
          v37.data = v37.baseBuffer;
          v37.len = 0;
          v37.baseBuffer[0] = 0;
          idTypeInfoFile::ReadType(this: file, type: v39, ops: &v38, name: &v37);
          v33 = 0;
          v34 = VariablesFor;
          if ( VariablesFor->type != nullptr )
          {
            while ( idStr::Cmp(s1: v34->name, s2: v37.data) != 0 )
            {
              ++v34;
              if ( v34->type == nullptr )
                goto LABEL_32;
            }
            ReadSSObjectType(
              ti,
              file,
              varType: v34->type,
              varOps: v34->ops,
              varName: v34->name,
              varPtr: (char *)Object + v34->offset);
            v33 = 1;
          }
LABEL_32:
          if ( v33 == 0 )
            idTypeInfoFile::ReadUnknown(this: file);
          idStr::FreeData(this: &v37);
          idStr::FreeData(this: &v38);
          idStr::FreeData(this: v39);
        }
        goto LABEL_16;
      }
    }
    else
    {
      idLib::Warning(fmt: "NULL entry in superscript list");
    }
LABEL_15:
    idLexer::SkipBracedSection(this: &file->src, parseFirstBrace: false);
LABEL_16:
    v31 = &v35;
LABEL_17:
    idStr::FreeData(this: v31);
    goto LABEL_18;
  }
  idLib::Warning(fmt: "NULL entry in superscript list");
LABEL_18:
  if ( *a28 != nullptr )
    idSuperScriptSystem::DestroyObject(this: &gameLocal->superScript, object: *a28);
  *a28 = Object;
}


// ========================================================================
// $LN118_1
// EA  : 0x82D6A368
// RVA : 0x00D6A368
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _LN118_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 112));
}


// ========================================================================
// __unwind$513871
// EA  : 0x82D6A390
// RVA : 0x00D6A390
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513871()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 80));
}


// ========================================================================
// __unwind$513872
// EA  : 0x82D6A3B8
// RVA : 0x00D6A3B8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513872()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 208));
}


// ========================================================================
// __unwind$513873
// EA  : 0x82D6A3E0
// RVA : 0x00D6A3E0
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513873()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 176));
}


// ========================================================================
// __unwind$513874
// EA  : 0x82D6A408
// RVA : 0x00D6A408
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_513874()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 144));
}


// ========================================================================
// ?ReadAliasHandle@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D6A438
// RVA : 0x00D6A438
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadAliasHandle(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> *a28)
{
  unsigned __int64 v29; // r6
  const char *v30; // r7
  int value; // r9
  int v32; // [sp+50h] [-60h] BYREF
  idPLogScope v33; // [sp+58h] [-58h] BYREF
  idStr v34[2]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "ReadAliasHandle");
  LODWORD(v29) = "ReadAliasHandle";
  HIDWORD(v29) = 2;
  idPLogScope::idPLogScope(this: &v33, pl: &pLog, gMask: v29, label: v30);
  v34[0].len = 0;
  v34[0].allocedAndFlag = 20;
  v34[0].data = v34[0].baseBuffer;
  v34[0].baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: v34);
  value = animation->RegisterAlias(this: &v32, result: animation, a3: 0, a4: v34[0].data)->value;
  a28->value = value;
  if ( value != 0xFFFF )
    idGameState::AddAnimAliasReference(alias: a28, name: v34[0].data);
  idStr::FreeData(this: v34);
  idPLogScope::~idPLogScope(this: &v33);
  RD_EventEnd();
}


// ========================================================================
// __unwind$514107
// EA  : 0x82D6A4FC
// RVA : 0x00D6A4FC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514107()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 128));
}


// ========================================================================
// __unwind$514108
// EA  : 0x82D6A524
// RVA : 0x00D6A524
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514108()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$514109
// EA  : 0x82D6A54C
// RVA : 0x00D6A54C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514109()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?WriteEventArg@@YAXPAVidTypeInfoFile@@PBVidEventDef@@HABVidEventArg@@@Z
// EA  : 0x82D6A580
// RVA : 0x00D6A580
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteEventArg(idTypeInfoFile *file, const idEventDef *eventDef, int argNum, idAICover *arg)
{
  const char *v8; // r11
  idTypeInfoFile *v9; // r3
  const char *v10; // r3
  double v11; // fp13
  double v12; // fp12
  int value; // r11
  const char *EnumValueName; // r4
  long double v15; // fp2
  double v16; // fp13
  double v17; // fp12
  char *data; // r28
  int v19; // r3
  const char *EnumName; // r3
  char aas_high; // [sp+50h] [-90h]
  __int16 v22; // [sp+52h] [-8Eh] BYREF
  idEntityPtr<idEntity> v23; // [sp+54h] [-8Ch] BYREF
  idEventArg v24; // [sp+58h] [-88h] BYREF
  idVec3 v25; // [sp+70h] [-70h] BYREF
  idStr v26[3]; // [sp+80h] [-60h] BYREF

  idTypeInfoFile::WriteOpeningBrace(this: file);
  aas_high = HIBYTE(arg->aas);
  if ( SHIBYTE(arg->aas) > 98 )
  {
    switch ( aas_high )
    {
      case 'd':
        idTypeInfoFile::WriteType(this: file, type: "idDecl", ops: "*", name: "decl");
        v9 = file;
        if ( arg->spawnId.value == 0 )
          goto LABEL_15;
        idTypeInfoFile::WriteOpeningBrace(this: file);
        v19 = (*(int (__fastcall **)(int))(*(_DWORD *)arg->spawnId.value + 32))(a1: arg->spawnId.value);
        idTypeInfoFile::WriteType(this: file, type: "idStr", ops: &byte_8200D768, name: *(const char **)(v19 + 1044));
        idTypeInfoFile::WriteStr(this: file, s: *(const char **)(arg->spawnId.value + 8));
        idTypeInfoFile::WriteClosingBrace(this: file);
        break;
      case 'e':
        data = &byte_8200D768;
        if ( file->settings.writeModifier != WRITE_ALL_PROPERTIES )
        {
          if ( file->settings.resolveEntityPointers )
          {
            if ( idEventArg::GetEntity(this: arg) != nullptr )
              data = idEventArg::GetEntity(this: arg)->name.data;
          }
          else
          {
            v23.spawnId.value = *(_DWORD *)&idEventArg::GetEntitySpawnId(this: &v24, result: (idSpawnId *)arg)->type;
            data = idGameState::GetUnresolvedEntityName(ptr: &v23);
          }
        }
        idTypeInfoFile::WriteType(this: file, type: "idEntityPtr< idEntity >", ops: "*", name: "entity");
        idTypeInfoFile::WriteStr(this: file, s: data);
        break;
      case 'f':
        idTypeInfoFile::WriteType(this: file, type: "float", ops: &byte_8200D768, name: "float");
        *(double *)&v15 = *(float *)&arg->spawnId.value;
        idTypeInfoFile::WriteFloat(this: file, d: v15);
        break;
      case 'i':
        idTypeInfoFile::WriteType(this: file, type: "int", ops: &byte_8200D768, name: "int");
        v26[0].len = 0;
        v26[0].allocedAndFlag = 20;
        v26[0].data = v26[0].baseBuffer;
        v26[0].baseBuffer[0] = 0;
        if ( (unsigned __int8)idEventDef::GetArgTypeName(this: eventDef, arg: argNum, typeName: v26) == 0
          || idStr::Cmp(s1: v26[0].data, s2: "int") == 0 )
        {
          goto LABEL_33;
        }
        EnumValueName = idTypeInfoTools::FindEnumValueName(
                          this: typeInfoTools,
                          enumTypeName: v26[0].data,
                          value: arg->spawnId.value);
        if ( EnumValueName != nullptr )
        {
          idTypeInfoFile::WriteStr(this: file, s: EnumValueName);
        }
        else
        {
          idLib::Warning(fmt: "Enumeration value not found for type '%s', value '%d'", v26[0].data, arg->spawnId.value);
LABEL_33:
          idTypeInfoFile::WriteInt(this: file, l: arg->spawnId.value);
        }
        idStr::FreeData(this: v26);
        break;
      case 's':
        idTypeInfoFile::WriteType(this: file, type: "idStr", ops: &byte_8200D768, name: "string");
        idTypeInfoFile::WriteStr(this: file, s: (const char *)arg->spawnId.value);
        break;
      case 'v':
        idTypeInfoFile::WriteType(this: file, type: "idVec3", ops: &byte_8200D768, name: "vec3");
        v16 = *(float *)&arg->coverIndex;
        v17 = *(float *)&arg[1].aas;
        v25.x = *(float *)&arg->spawnId.value;
        v25.y = v16;
        v25.z = v17;
        idTypeInfoFile::WriteVec3(this: file, v: &v25);
        break;
      default:
        goto LABEL_47;
    }
  }
  else
  {
    if ( aas_high == 98 )
    {
      idTypeInfoFile::WriteType(this: file, type: "bool", ops: &byte_8200D768, name: "bool");
      idTypeInfoFile::WriteBool(this: file, b: arg->spawnId.value != 0);
      goto LABEL_48;
    }
    if ( aas_high > 51 )
    {
      switch ( aas_high )
      {
        case '4':
          idTypeInfoFile::WriteType(this: file, type: "idDeclMD6 ", ops: "*", name: "md6Anim");
          value = arg->spawnId.value;
          if ( value != 0 )
            idTypeInfoFile::WriteStr(this: file, s: *(const char **)(value + 8));
          else
            idTypeInfoFile::WriteStr(this: file, s: &byte_8200D768);
          break;
        case '5':
          idTypeInfoFile::WriteType(this: file, type: "idJointTag ", ops: &byte_8200D768, name: "jointTag");
          v8 = (const char *)arg->spawnId.value;
          if ( v8 == nullptr )
            v8 = &byte_8200D768;
          goto LABEL_23;
        case 'a':
          idTypeInfoFile::WriteType(this: file, type: "idAngles", ops: &byte_8200D768, name: "angles");
          v11 = *(float *)&arg->coverIndex;
          v12 = *(float *)&arg[1].aas;
          v24.value.v[1] = *(float *)&arg->spawnId.value;
          v24.value.v[2] = v11;
          v24.value.q[3] = v12;
          idTypeInfoFile::WriteAngles(this: file, a: (const idAngles *)&v24.value.q[1]);
          break;
        default:
          goto LABEL_47;
      }
    }
    else
    {
      switch ( aas_high )
      {
        case 51:
          idTypeInfoFile::WriteType(this: file, type: "aliasHandle_t ", ops: &byte_8200D768, name: "animAlias");
          v22 = arg->spawnId.value;
          v10 = animation->FindAliasName(this: animation, a2: &v22);
          idTypeInfoFile::WriteStr(this: file, s: v10);
          break;
        case 0:
          idTypeInfoFile::WriteType(this: file, type: "void", ops: &byte_8200D768, name: "void");
          v9 = file;
LABEL_15:
          idTypeInfoFile::WriteNullPointer(this: v9);
          break;
        case 49:
          idTypeInfoFile::WriteType(this: file, type: "idAnimWebPath", ops: &byte_8200D768, name: "animWebPath");
          v8 = (const char *)arg->spawnId.value;
          if ( v8 == nullptr )
            v8 = &byte_8200D768;
          goto LABEL_23;
        case 50:
          idTypeInfoFile::WriteType(this: file, type: "idJointName", ops: &byte_8200D768, name: "jointName");
          v8 = (const char *)arg->spawnId.value;
          if ( v8 == nullptr )
            v8 = &byte_8200D768;
LABEL_23:
          idTypeInfoFile::WriteStr(this: file, s: v8);
          break;
        default:
LABEL_47:
          EnumName = idTypeInfoTools::GetEnumName(
                       this: typeInfoTools,
                       enumTypeName: "eventArgType_t",
                       enumValue: aas_high,
                       defaultValue: "<unknown>");
          idLib::Warning(fmt: "WriteEventCallInfo: Unhandled arg type '%s'", EnumName);
          break;
      }
    }
  }
LABEL_48:
  idTypeInfoFile::WriteClosingBrace(this: file);
}


// ========================================================================
// __unwind$514206
// EA  : 0x82D6AB40
// RVA : 0x00D6AB40
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514206()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?WriteEventCallInfo@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D6AB70
// RVA : 0x00D6AB70
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall WriteEventCallInfo(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        __int16 *a28)
{
  bool v29; // r23
  unsigned int v30; // r3
  const idEventDef *EventCommand; // r3
  const idEventDef *v32; // r27
  const char *name; // r4
  int numargs; // r4
  int v35; // r30
  idAICover *v36; // r28

  v29 = idLib::PushWarningInfo(type: varName, name: "WriteEventCallInfo");
  idTypeInfoFile::WriteOpeningBrace(this: file);
  idTypeInfoFile::WriteType(this: file, type: "eventHandle_t", ops: &byte_8200D768, name: "eventDef");
  v30 = *a28;
  if ( v30 == -1 )
  {
    v32 = nullptr;
  }
  else
  {
    EventCommand = idEventDef::GetEventCommand(eventnum: v30);
    v32 = EventCommand;
    if ( EventCommand != nullptr )
    {
      name = EventCommand->name;
      goto LABEL_6;
    }
  }
  name = &byte_8200D768;
LABEL_6:
  idTypeInfoFile::WriteStr(this: file, s: name);
  idTypeInfoFile::WriteType(this: file, type: "eventArgs_t", ops: &byte_8200D768, name: "args");
  idTypeInfoFile::WriteOpeningBrace(this: file);
  idTypeInfoFile::WriteType(this: file, type: "int", ops: &byte_8200D768, name: "numArgs");
  if ( v32 != nullptr )
    numargs = v32->numargs;
  else
    numargs = 0;
  idTypeInfoFile::WriteInt(this: file, l: numargs);
  if ( v32 != nullptr )
  {
    v35 = 0;
    if ( v32->numargs > 0 )
    {
      v36 = (idAICover *)(a28 + 2);
      do
      {
        idTypeInfoFile::WriteArrayElementType(this: file, type: "idEventArg", ops: &byte_8200D768, name: "arg", i: v35);
        WriteEventArg(file, eventDef: v32, argNum: v35++, arg: v36);
        v36 = (idAICover *)((char *)v36 + 20);
      }
      while ( v35 < v32->numargs );
    }
  }
  idTypeInfoFile::WriteClosingBrace(this: file);
  idTypeInfoFile::WriteClosingBrace(this: file);
  if ( v29 )
    idLib::PopWarningInfo();
}


// ========================================================================
// __unwind$514442
// EA  : 0x82D6AD08
// RVA : 0x00D6AD08
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514442()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 176 + 80));
}


// ========================================================================
// ?ReadEventArg@@YAXPAVidTypeInfoFile@@PBVidEventDef@@HAAVidEventArg@@@Z
// EA  : 0x82D6AD38
// RVA : 0x00D6AD38
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadEventArg(idTypeInfoFile *file, const idEventDef *eventDef, int argNum, idEventArg *arg)
{
  const idDecl *value; // r30
  int *v9; // r11
  _DWORD *v10; // r10
  int i; // ctr
  const enumTypeInfo_t *EnumInfo; // r29
  int *v13; // r11
  _DWORD *v14; // r10
  int j; // ctr
  idStr *v16; // r3
  int *v17; // r11
  _DWORD *v18; // r10
  int k; // ctr
  int *v20; // r11
  _DWORD *v21; // r10
  int m; // ctr
  int *v23; // r11
  _DWORD *v24; // r10
  int n; // ctr
  int *v26; // r11
  _DWORD *v27; // r10
  int ii; // ctr
  int *v29; // r11
  _DWORD *v30; // r10
  int v31; // ctr
  bool v32; // cr58
  const idEntity *v33; // r3
  idEventArg *v34; // r3
  _DWORD *v35; // r10
  _DWORD *v36; // r11
  int jj; // ctr
  idDeclInfo *v38; // r3
  int *v39; // r11
  _DWORD *v40; // r10
  int kk; // ctr
  int *v42; // r11
  _DWORD *v43; // r10
  int v44; // ctr
  int *v45; // r11
  _DWORD *v46; // r10
  int v47; // ctr
  int v48; // r7
  int *v49; // r10
  _DWORD *v50; // r9
  int mm; // ctr
  idResource *Existing; // r3
  int *v53; // r11
  _DWORD *v54; // r10
  int nn; // ctr
  idSpawnId v56[3]; // [sp+50h] [-220h] BYREF
  int v57; // [sp+5Ch] [-214h] BYREF
  idEventArg v58; // [sp+60h] [-210h] BYREF
  idSpawnId v59; // [sp+74h] [-1FCh] BYREF
  idStr v60; // [sp+80h] [-1F0h] BYREF
  idStr v61; // [sp+A0h] [-1D0h] BYREF
  idAtomicString v62; // [sp+C0h] [-1B0h] BYREF
  idAtomicString v63; // [sp+C4h] [-1ACh] BYREF
  idAtomicString v64; // [sp+C8h] [-1A8h] BYREF
  idStr v65; // [sp+D0h] [-1A0h] BYREF
  idVec3 v66; // [sp+F0h] [-180h] BYREF
  idAngles v67; // [sp+100h] [-170h] BYREF
  idStr v68; // [sp+110h] [-160h] BYREF
  idStr v69; // [sp+130h] [-140h] BYREF
  idStr v70; // [sp+150h] [-120h] BYREF
  idStr v71; // [sp+170h] [-100h] BYREF
  idStr v72; // [sp+190h] [-E0h] BYREF
  idStr v73; // [sp+1B0h] [-C0h] BYREF
  idStr v74; // [sp+1D0h] [-A0h] BYREF
  idStr v75; // [sp+1F0h] [-80h] BYREF
  idStr v76[3]; // [sp+210h] [-60h] BYREF

  value = nullptr;
  v61.len = 0;
  v61.allocedAndFlag = 20;
  v61.data = v61.baseBuffer;
  v61.baseBuffer[0] = 0;
  idEventDef::GetArgTypeName(this: eventDef, arg: argNum, typeName: &v61);
  idTypeInfoFile::ReadOpeningBrace(this: file);
  v76[0].allocedAndFlag = 20;
  v76[0].data = v76[0].baseBuffer;
  v76[0].len = 0;
  v76[0].baseBuffer[0] = 0;
  v74.allocedAndFlag = 20;
  v74.data = v74.baseBuffer;
  v74.len = 0;
  v74.baseBuffer[0] = 0;
  v60.allocedAndFlag = 20;
  v60.data = v60.baseBuffer;
  v60.len = 0;
  v60.baseBuffer[0] = 0;
  idTypeInfoFile::ReadType(this: file, type: v76, ops: &v74, name: &v60);
  if ( idStr::Cmp(s1: v60.data, s2: "void") == 0 )
  {
    idTypeInfoFile::ReadNullPointer(this: file);
    v9 = &v57;
    v58.type = 0;
    v58.value.i = 0;
    v10 = (_DWORD *)&arg[-1].value.q[3];
    for ( i = 5; i != 0; --i )
      *++v10 = *++v9;
    goto LABEL_101;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "int") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 105 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found int, expected %s.",
        argNum,
        v61.data);
    v65.allocedAndFlag = 20;
    v65.len = 0;
    v65.data = v65.baseBuffer;
    v65.baseBuffer[0] = 0;
    idTypeInfoFile::ReadStr(this: file, s: &v65);
    if ( idStr::IsNumeric(s: v65.data) )
    {
      value = (const idDecl *)atol(nptr: v65.data);
    }
    else
    {
      EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: v61.data);
      if ( EnumInfo != nullptr )
      {
        if ( idTypeInfoTools::FindEnumValueInfo(
               this: typeInfoTools,
               enumInfo: EnumInfo,
               name: v65.data,
               defaultIfNotFound: false) == nullptr )
          idLib::Warning(fmt: "Unknown enumeration value('%s')", v65.data);
        value = (const idDecl *)idTypeInfoTools::FindEnumValueInfo(
                                  this: typeInfoTools,
                                  enumInfo: EnumInfo,
                                  name: v65.data,
                                  defaultIfNotFound: true)->value;
      }
      else
      {
        idLib::Warning(fmt: "Unknown enumeration('%s')", v61.data);
      }
    }
    v58.value.i = (int)value;
    v13 = &v57;
    v58.type = 105;
    v14 = (_DWORD *)&arg[-1].value.q[3];
    for ( j = 5; j != 0; --j )
      *++v14 = *++v13;
    v16 = &v65;
LABEL_100:
    idStr::FreeData(this: v16);
LABEL_101:
    idTypeInfoFile::ReadClosingBrace(this: file);
    idStr::FreeData(this: &v60);
    idStr::FreeData(this: &v74);
    idStr::FreeData(this: v76);
    idStr::FreeData(this: &v61);
    return;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "float") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 102 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found float, expected %s.",
        argNum,
        v61.data);
    idTypeInfoFile::ReadFloat(this: file, f: (float *)&v56[0].value);
    v17 = &v57;
    v58.value.f = *(float *)&v56[0].value;
    v58.type = 102;
    v18 = (_DWORD *)&arg[-1].value.q[3];
    for ( k = 5; k != 0; --k )
      *++v18 = *++v17;
    goto LABEL_101;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "bool") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 98 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found bool, expected %s.",
        argNum,
        v61.data);
    idTypeInfoFile::ReadBool(this: file, b: (bool *)v56);
    v20 = &v57;
    v58.type = 105;
    v21 = (_DWORD *)&arg[-1].value.q[3];
    v58.value.i = HIBYTE(v56[0].value);
    for ( m = 5; m != 0; --m )
      *++v21 = *++v20;
    goto LABEL_101;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "vec3") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 118 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found vec3, expected %s.",
        argNum,
        v61.data);
    idTypeInfoFile::ReadVec3(this: file, v: &v66);
    v23 = &v57;
    v58.type = 118;
    v58.value.f = v66.x;
    v58.value.v[1] = v66.y;
    v24 = (_DWORD *)&arg[-1].value.q[3];
    v58.value.v[2] = v66.z;
    for ( n = 5; n != 0; --n )
      *++v24 = *++v23;
    goto LABEL_101;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "angles") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 97 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found angles, expected %s.",
        argNum,
        v61.data);
    idTypeInfoFile::ReadAngles(this: file, a: &v67);
    v26 = &v57;
    v58.type = 97;
    v58.value.f = v67.pitch;
    v58.value.v[1] = v67.yaw;
    v27 = (_DWORD *)&arg[-1].value.q[3];
    v58.value.v[2] = v67.roll;
    for ( ii = 5; ii != 0; --ii )
      *++v27 = *++v26;
    goto LABEL_101;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "string") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 115 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found string, expected %s.",
        argNum,
        v61.data);
    v75.allocedAndFlag = 20;
    v75.len = 0;
    v75.data = v75.baseBuffer;
    v75.baseBuffer[0] = 0;
    idTypeInfoFile::ReadStr(this: file, s: &v75);
    idAtomicString::Set(this: &v63, str_: v75.data);
    v29 = &v57;
    v58.type = 115;
    v30 = (_DWORD *)&arg[-1].value.q[3];
    v31 = 5;
    v58.value.i = (int)v63.str;
    do
    {
      *++v30 = *++v29;
      --v31;
    }
    while ( v31 != 0 );
    v16 = &v75;
    goto LABEL_100;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "entity") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 101 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found entity, expected %s.",
        argNum,
        v61.data);
    v69.allocedAndFlag = 20;
    v69.len = 0;
    v69.data = v69.baseBuffer;
    v69.baseBuffer[0] = 0;
    idTypeInfoFile::ReadStr(this: file, s: &v69);
    v32 = file->settings.writeModifier == WRITE_ALL_PROPERTIES;
    v59.value = 0x1FFF;
    if ( !v32 )
    {
      if ( file->settings.resolveEntityPointers )
      {
        v33 = gameLocal->FindEntity(this: gameLocal, a2: v69.data);
        v59.value = idSpawnId::idSpawnId(this: v56, ent: v33)->value;
      }
      else
      {
        v56[0].value = 0x1FFF;
        idGameState::SetUnresolvedEntityName(ptr: (idEntityPtr<idEntity> *)v56, name: v69.data);
        v59.value = v56[0].value;
      }
    }
    v34 = idEventArg::idEventArg(this: &v58, data: &v59);
    v35 = (_DWORD *)&arg[-1].value.q[3];
    v36 = (_DWORD *)&v34[-1].value.q[3];
    for ( jj = 5; jj != 0; --jj )
      *++v35 = *++v36;
    v16 = &v69;
    goto LABEL_100;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "decl") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 100 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found decl, expected %s.",
        argNum,
        v61.data);
    if ( !idTypeInfoFile::CheckNullPointer(this: file) )
    {
      idTypeInfoFile::ReadOpeningBrace(this: file);
      idTypeInfoFile::ReadType(this: file, type: v76, ops: &v74, name: &v60);
      v68.allocedAndFlag = 20;
      v68.data = v68.baseBuffer;
      v68.len = 0;
      v68.baseBuffer[0] = 0;
      idTypeInfoFile::ReadStr(this: file, s: &v68);
      idTypeInfoFile::ReadClosingBrace(this: file);
      v38 = declManager->GetDeclType(this: declManager, a2: v60.data);
      if ( v38 != nullptr )
      {
        if ( (v68.data == nullptr
           || (value = idDeclInfo::FindWithInheritance(this: v38, name: v68.data, makeDefault: true)) == nullptr)
          && v68.len != 0 )
        {
          idLib::Warning(fmt: "Unknown Decl %s");
        }
      }
      else
      {
        idLib::Warning(fmt: "Unknown Decl Type %s");
      }
      idStr::FreeData(this: &v68);
    }
    v58.value.i = (int)value;
    v39 = &v57;
    v58.type = 100;
    v40 = (_DWORD *)&arg[-1].value.q[3];
    for ( kk = 5; kk != 0; --kk )
      *++v40 = *++v39;
    goto LABEL_101;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "animWebPath") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 49 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found animWebPath, expected %s.",
        argNum,
        v61.data);
    v72.allocedAndFlag = 20;
    v72.len = 0;
    v72.data = v72.baseBuffer;
    v72.baseBuffer[0] = 0;
    idTypeInfoFile::ReadStr(this: file, s: &v72);
    idAtomicString::Set(this: &v62, str_: v72.data);
    v42 = &v57;
    v58.type = 115;
    v43 = (_DWORD *)&arg[-1].value.q[3];
    v44 = 5;
    v58.value.i = (int)v62.str;
    do
    {
      *++v43 = *++v42;
      --v44;
    }
    while ( v44 != 0 );
    v16 = &v72;
    goto LABEL_100;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "jointName") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 50 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found jointName, expected %s.",
        argNum,
        v61.data);
    v73.allocedAndFlag = 20;
    v73.len = 0;
    v73.data = v73.baseBuffer;
    v73.baseBuffer[0] = 0;
    idTypeInfoFile::ReadStr(this: file, s: &v73);
    idAtomicString::Set(this: &v64, str_: v73.data);
    v45 = &v57;
    v58.type = 115;
    v46 = (_DWORD *)&arg[-1].value.q[3];
    v47 = 5;
    v58.value.i = (int)v64.str;
    do
    {
      *++v46 = *++v45;
      --v47;
    }
    while ( v47 != 0 );
    v16 = &v73;
    goto LABEL_100;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "animAlias") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 51 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found animAlias, expected %s.",
        argNum,
        v61.data);
    v70.allocedAndFlag = 20;
    v70.len = 0;
    v70.data = v70.baseBuffer;
    v70.baseBuffer[0] = 0;
    idTypeInfoFile::ReadStr(this: file, s: &v70);
    v48 = *(unsigned __int16 *)((int (__fastcall *)(idSpawnId *))animation->FindAliasHandle_2)(a1: v56);
    v49 = &v57;
    v50 = (_DWORD *)&arg[-1].value.q[3];
    v58.value.i = v48;
    v58.type = 51;
    for ( mm = 5; mm != 0; --mm )
      *++v50 = *++v49;
    if ( (unsigned __int16)arg->value.i == 0xFFFF )
      idLib::Warning(fmt: "ReadEventCallInfo: animAlias '%s' not found", v70.data);
    v16 = &v70;
    goto LABEL_100;
  }
  if ( idStr::Cmp(s1: v60.data, s2: "md6Anim") == 0 )
  {
    if ( eventDef->formatspec[argNum] != 52 )
      idTypeInfoFile::Error(
        this: file,
        str: "Invalid argument for event arg %d: found md6Anim, expected %s.",
        argNum,
        v61.data);
    v71.allocedAndFlag = 20;
    v71.len = 0;
    v71.data = v71.baseBuffer;
    v71.baseBuffer[0] = 0;
    idTypeInfoFile::ReadStr(this: file, s: &v71);
    Existing = idResourceList::FindExisting(this: &idMD6Anim::resourceList, name: v71.data, skipStaleCheck: false);
    v53 = &v57;
    v58.value.i = (int)Existing;
    v58.type = 52;
    v54 = (_DWORD *)&arg[-1].value.q[3];
    for ( nn = 5; nn != 0; --nn )
      *++v54 = *++v53;
    if ( arg->value.i == 0 )
      idLib::Warning(fmt: "ReadEventCallInfo: md6Anim '%s' not found", v71.data);
    v16 = &v71;
    goto LABEL_100;
  }
  idLib::Error(fmt: "ReadEventCallInfo: unhandled arg type '%s'", v60.data);
  _LN455();
}


// ========================================================================
// $LN455
// EA  : 0x82D6B744
// RVA : 0x00D6B744
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _LN455()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 160));
}


// ========================================================================
// __unwind$514518
// EA  : 0x82D6B76C
// RVA : 0x00D6B76C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514518()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 528));
}


// ========================================================================
// __unwind$514519
// EA  : 0x82D6B794
// RVA : 0x00D6B794
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514519()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 464));
}


// ========================================================================
// __unwind$514520
// EA  : 0x82D6B7BC
// RVA : 0x00D6B7BC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514520()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 128));
}


// ========================================================================
// __unwind$514521
// EA  : 0x82D6B7E4
// RVA : 0x00D6B7E4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514521()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 208));
}


// ========================================================================
// __unwind$514522
// EA  : 0x82D6B80C
// RVA : 0x00D6B80C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514522()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 496));
}


// ========================================================================
// __unwind$514523
// EA  : 0x82D6B834
// RVA : 0x00D6B834
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514523()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 304));
}


// ========================================================================
// __unwind$514524
// EA  : 0x82D6B85C
// RVA : 0x00D6B85C
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514524()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 272));
}


// ========================================================================
// __unwind$514525
// EA  : 0x82D6B884
// RVA : 0x00D6B884
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514525()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 400));
}


// ========================================================================
// __unwind$514526
// EA  : 0x82D6B8AC
// RVA : 0x00D6B8AC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514526()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 432));
}


// ========================================================================
// __unwind$514527
// EA  : 0x82D6B8D4
// RVA : 0x00D6B8D4
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514527()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 336));
}


// ========================================================================
// __unwind$514528
// EA  : 0x82D6B8FC
// RVA : 0x00D6B8FC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_514528()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 368));
}


// ========================================================================
// ?ReadEventCallInfo@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82D6B930
// RVA : 0x00D6B930
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __fastcall ReadEventCallInfo(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        _WORD *a28)
{
  bool v29; // r22
  const idEventDef *Event; // r3
  const idEventDef *v31; // r28
  int eventnum; // r11
  int v33; // r29
  int v34; // [sp+54h] [-8Ch] BYREF
  int v35; // [sp+58h] [-88h] BYREF
  idStr v36[4]; // [sp+60h] [-80h] BYREF

  v29 = idLib::PushWarningInfo(type: varName, name: "ReadEventCallInfo");
  idTypeInfoFile::ReadOpeningBrace(this: file);
  idTypeInfoFile::ExpectType(this: file, type: "eventHandle_t", ops: &byte_8200D768, name: "eventDef");
  v36[0].len = 0;
  v36[0].allocedAndFlag = 20;
  v36[0].data = v36[0].baseBuffer;
  v36[0].baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: v36);
  Event = idEventDef::FindEvent(name: v36[0].data);
  v31 = Event;
  if ( Event != nullptr )
    eventnum = Event->eventnum;
  else
    LOWORD(eventnum) = -1;
  *a28 = eventnum;
  idTypeInfoFile::ExpectType(this: file, type: "eventArgs_t", ops: &byte_8200D768, name: "args");
  if ( v31 != nullptr )
  {
    idTypeInfoFile::ReadOpeningBrace(this: file);
    v34 = 0;
    idTypeInfoFile::ExpectType(this: file, type: "int", ops: &byte_8200D768, name: "numArgs");
    idTypeInfoFile::ReadUnsignedLong(this: file, l: (unsigned int *)&v34);
    v33 = 0;
    if ( v34 > 0 )
    {
      while ( 1 )
      {
        v35 = 0;
        if ( !idTypeInfoFile::ExpectArrayElementType(
                this: file,
                type: "idEventArg",
                ops: &byte_8200D768,
                name: "arg",
                index: &v35) )
          break;
        ReadEventArg(file, eventDef: v31, argNum: v35, arg: (idEventArg *)&a28[10 * v35 + 2]);
        if ( ++v33 >= v34 )
          goto LABEL_11;
      }
      idTypeInfoFile::ReadClosingBrace(this: file);
    }
LABEL_11:
    idTypeInfoFile::ReadClosingBrace(this: file);
    idTypeInfoFile::ReadClosingBrace(this: file);
    idStr::FreeData(this: v36);
  }
  else
  {
    idLexer::SkipBracedSection(this: &file->src, parseFirstBrace: true);
    idStr::FreeData(this: v36);
  }
  if ( v29 )
    idLib::PopWarningInfo();
}


// ========================================================================
// __unwind$515323
// EA  : 0x82D6BAFC
// RVA : 0x00D6BAFC
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_515323()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$515324
// EA  : 0x82D6BB24
// RVA : 0x00D6BB24
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_515324()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// ?Init@idGameState@@SAXXZ
// EA  : 0x82D6BB50
// RVA : 0x00D6BB50
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

static void __fastcall idGameState::Init()
{
  idTypeInfoTools::Init(this: typeInfoTools, typeInfo_: &typeInfo);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idList <",
    isPointer: false,
    matchPrefix: true,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteList,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadList);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idStaticList <",
    isPointer: false,
    matchPrefix: true,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteStaticList,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadStaticList);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idScriptObject",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteScriptObject,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadScriptObject);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idEntityPtr <",
    isPointer: false,
    matchPrefix: true,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteEntityPtr,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadEntityPtr);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "randomValue_t",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteRandomValue,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadRandomValue);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idTypesafeNumber < float",
    isPointer: false,
    matchPrefix: true,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteTypesafeFloat,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadTypesafeFloat);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idBoundedIntBase",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: true,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteBoundedIntBase,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadBoundedIntBase);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idBoundedFloatBase",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: true,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteBoundedFloatBase,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadBoundedFloatBase);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idAnimWebPath",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteAnimWebPath,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadAnimWebPath);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idAnimWebPath_Preview",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteAnimWebPath,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadAnimWebPath);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idDecl",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: true,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteDecl,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadDecl);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idCollisionModel",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteCollisionModel,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadCollisionModel);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idRenderModel",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: true,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteRenderModel,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadRenderModel);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idStaticModel",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteStaticModel,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadStaticModel);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idSWF",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteSWF,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadSWF);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idSWFFile",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteSWFFile,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadSWFFile);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idInGameVideoFile",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteInGameVideoFile,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadInGameVideoFile);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idTypeInfoSubGraph",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteGraphDeclItemPointer,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadGraphDeclItemPointer);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idTypeInfoGraphNode",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteGraphDeclItemPointer,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadGraphDeclItemPointer);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idTypeInfoGraphLink",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteGraphDeclItemPointer,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadGraphDeclItemPointer);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idIESfile",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteIESFile,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadIESFile);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idVoiceTrack",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteVoiceTrack,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadVoiceTrack);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idSSObject",
    isPointer: true,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteSSObject,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadSSObject);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idAIActionParm",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: nullptr,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))idAIActionParm::ReadAIActionParm);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idHandle < unsigned short , invalidAliasHandle_t , INVALID_ALIAS_HANDLE >",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteAliasHandle,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadAliasHandle);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idAtomicHandleT < aliasRefType_t >",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteAliasRef_t,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadAliasRef_t);
  idTypeInfoTools::AddClass(
    this: typeInfoTools,
    typeName: "idEventCallInfo",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteEventCallInfo,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadEventCallInfo);
}


// ========================================================================
// `dynamic initializer for 'typeInfoToolsLocal''
// EA  : 0x833807B8
// RVA : 0x013807B8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__typeInfoToolsLocal__()
{
  idTypeInfoTools::idTypeInfoTools(this: &typeInfoToolsLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__typeInfoToolsLocal__);
}


// ========================================================================
// `dynamic initializer for 'ptrNames''
// EA  : 0x833807F8
// RVA : 0x013807F8
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ptrNames__()
{
  idHashIndex::InternalInit(this: &ptrNames.stringHash, initialHashSize: 1024, initialIndexSize: 1024);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ptrNames__);
}


// ========================================================================
// __unwind$515425
// EA  : 0x83380844
// RVA : 0x01380844
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void _unwind_515425()
{
  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)&ptrNames);
}


// ========================================================================
// `dynamic initializer for 'idGameState::referencedModels''
// EA  : 0x83380870
// RVA : 0x01380870
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idGameState::referencedModels__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idGameState::referencedModels__);
}


// ========================================================================
// `dynamic initializer for 'idGameState::referencedAliases''
// EA  : 0x83380880
// RVA : 0x01380880
// PDB : w:\tech5\tungsten\game\gamesys\gamestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idGameState::referencedAliases__()
{
  unsigned __int8 *p_memTag; // r11
  int i; // ctr

  p_memTag = &idGameState::referencedAliases.memTag;
  for ( i = 100; i != 0; --i )
  {
    p_memTag += 2;
    *(_WORD *)p_memTag = -1;
  }
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idGameState::referencedAliases__);
}

