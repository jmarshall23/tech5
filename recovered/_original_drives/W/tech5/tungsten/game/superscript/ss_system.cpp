
// ========================================================================
// ?ReturnFloat@idSuperScriptSystem@@QAAXM@Z
// EA  : 0x82EAD6A8
// RVA : 0x00EAD6A8
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::ReturnFloat(idSuperScriptSystem *this, double value)
{
  this->returnFloat = value;
}


// ========================================================================
// ?ReturnInteger@idSuperScriptSystem@@QAAXH@Z
// EA  : 0x82EAD6B0
// RVA : 0x00EAD6B0
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::ReturnInteger(idSuperScriptSystem *this, int value)
{
  this->returnInt = value;
}


// ========================================================================
// ?ReturnString@idSuperScriptSystem@@QAAXPBD@Z
// EA  : 0x82EAD6B8
// RVA : 0x00EAD6B8
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::ReturnString(idSuperScriptSystem *this, const char *string)
{
  idStr::operator=(this: &this->returnString, text: string);
}


// ========================================================================
// ?CreateObject@idSuperScriptSystem@@QAAPAVidSSObject@@PBD@Z
// EA  : 0x82EAD740
// RVA : 0x00EAD740
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

idSSObject *__fastcall idSuperScriptSystem::CreateObject(idSuperScriptSystem *this, const char *name)
{
  const idDecl *v2; // r29
  idSuperScript *superScriptInterface; // r11
  idSuperScript *v7; // r24
  idSSFiber *currentFiber; // r20
  int allocFiberId; // r19
  int v10; // r18
  idSSObject *v11; // r3
  idSSObject *v12; // r28
  int v13; // r3
  int v14; // r25
  int v15; // r26
  const char **v16; // r30
  idDeclInfo *v17; // r3
  const char *v18; // r4
  const idDecl *v19; // r3
  int v20; // r3
  const char *v21; // r17
  const char *v22; // r16
  idTypeInfoTools *v23; // r3
  char *v24; // r9
  int v25; // r3

  superScriptInterface = this->superScriptInterface;
  if ( superScriptInterface == nullptr )
    return nullptr;
  v7 = this->superScriptInterface;
  currentFiber = this->currentFiber;
  allocFiberId = this->allocFiberId;
  this->allocFiberId = -1;
  this->currentFiber = nullptr;
  v10 = (int)superScriptInterface->Lock(this: superScriptInterface, a2: this);
  v11 = this->superScriptInterface->AllocObject(this: this->superScriptInterface, a2: name);
  v12 = v11;
  if ( v11 != nullptr && (v13 = (int)v11->_getDeclPtr(this: v11), v14 = v13, v15 = 0, *(_DWORD *)(v13 + 4) != 0) )
  {
    v16 = (const char **)v13;
    while ( 1 )
    {
      v17 = declManager->GetDeclTypeFromClassname(this: declManager, a2: *v16);
      if ( v17 == nullptr )
        break;
      v18 = v16[2];
      v2 = nullptr;
      if ( v18 != nullptr )
      {
        v19 = idDeclInfo::FindWithInheritance(this: v17, name: v18, makeDefault: false);
        v2 = v19;
        if ( v19 != nullptr )
        {
          v20 = (int)v19->GetDeclInfo(this: v19);
          v21 = *v16;
          v22 = *(const char **)(v20 + 1048);
          v23 = (idTypeInfoTools *)gameLocal->GetTypeInfoTools(this: gameLocal);
          if ( !idTypeInfoTools::IsSubclassOf(this: v23, typeName: v22, superType: v21) )
            goto _LN36_6;
        }
      }
      ++v15;
      v24 = (char *)v12 + (_DWORD)v16[3];
      v16 = (const char **)(16 * v15 + v14);
      *(_DWORD *)v24 = v2;
      if ( v16[1] == nullptr )
        goto LABEL_11;
    }
    idLib::FatalError(fmt: "failed to resolved decl pointer in super Script object %s", name);
_LN36_6:
    v25 = (int)v2->GetDeclInfo(this: v2);
    idLib::FatalError(fmt: "Tried to initialize %s as a %s, found as %s", name, *v16, *(const char **)(v25 + 1048));
    return _LN37_2();
  }
  else
  {
LABEL_11:
    this->allocFiberId = allocFiberId;
    this->currentFiber = currentFiber;
    v7->Lock(this: v7, a2: (idGameSuperInterface *)v10);
    return v12;
  }
}


// ========================================================================
// $LN37_2
// EA  : 0x82EAD928
// RVA : 0x00EAD928
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _LN37_2()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 240 + 88));
}


// ========================================================================
// ?AllocType@idSuperScriptSystem@@QAAPAXPBDH@Z
// EA  : 0x82EAD958
// RVA : 0x00EAD958
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void *__fastcall idSuperScriptSystem::AllocType(idSuperScriptSystem *this, const char *type, int num)
{
  idSuperScript *superScriptInterface; // r29
  idSSFiber *currentFiber; // r25
  int allocFiberId; // r24
  void *v10; // r27
  int v11; // [sp+54h] [-4Ch]

  superScriptInterface = this->superScriptInterface;
  if ( superScriptInterface == nullptr )
    return nullptr;
  currentFiber = this->currentFiber;
  allocFiberId = this->allocFiberId;
  this->currentFiber = nullptr;
  this->allocFiberId = -1;
  v11 = (int)superScriptInterface->Lock(this: superScriptInterface, a2: this);
  v10 = this->superScriptInterface->AllocType(this: this->superScriptInterface, a2: type, a3: num);
  this->allocFiberId = allocFiberId;
  this->currentFiber = currentFiber;
  superScriptInterface->Lock(this: superScriptInterface, a2: (idGameSuperInterface *)v11);
  return v10;
}


// ========================================================================
// __unwind$488241_1
// EA  : 0x82EADA10
// RVA : 0x00EADA10
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_488241_1()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetTypeSize@idSuperScriptSystem@@QAAHPBD@Z
// EA  : 0x82EADA40
// RVA : 0x00EADA40
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::GetTypeSize(idSuperScriptSystem *this, const char *type)
{
  idSuperScript *superScriptInterface; // r29
  idSSFiber *currentFiber; // r26
  int allocFiberId; // r25
  int v8; // r27
  int v9; // [sp+54h] [-4Ch]

  superScriptInterface = this->superScriptInterface;
  if ( superScriptInterface == nullptr )
    return 0;
  currentFiber = this->currentFiber;
  allocFiberId = this->allocFiberId;
  this->currentFiber = nullptr;
  this->allocFiberId = -1;
  v9 = (int)superScriptInterface->Lock(this: superScriptInterface, a2: this);
  v8 = this->superScriptInterface->GetTypeSize(this: this->superScriptInterface, a2: type);
  this->allocFiberId = allocFiberId;
  this->currentFiber = currentFiber;
  superScriptInterface->Lock(this: superScriptInterface, a2: (idGameSuperInterface *)v9);
  return v8;
}


// ========================================================================
// __unwind$488269_0
// EA  : 0x82EADAF0
// RVA : 0x00EADAF0
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_488269_0()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetEnumTypeInfoFor@idSuperScriptSystem@@QAAPAUssEnumTypeInfo_t@@PBD@Z
// EA  : 0x82EADB20
// RVA : 0x00EADB20
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

ssEnumTypeInfo_t *__fastcall idSuperScriptSystem::GetEnumTypeInfoFor(idSuperScriptSystem *this, const char *type)
{
  idSuperScript *superScriptInterface; // r29
  idSSFiber *currentFiber; // r26
  int allocFiberId; // r25
  ssEnumTypeInfo_t *v8; // r27
  int v9; // [sp+54h] [-4Ch]

  superScriptInterface = this->superScriptInterface;
  if ( superScriptInterface == nullptr )
    return nullptr;
  currentFiber = this->currentFiber;
  allocFiberId = this->allocFiberId;
  this->currentFiber = nullptr;
  this->allocFiberId = -1;
  v9 = (int)superScriptInterface->Lock(this: superScriptInterface, a2: this);
  v8 = this->superScriptInterface->GetEnumTypeInfoFor(this: this->superScriptInterface, a2: type);
  this->allocFiberId = allocFiberId;
  this->currentFiber = currentFiber;
  superScriptInterface->Lock(this: superScriptInterface, a2: (idGameSuperInterface *)v9);
  return v8;
}


// ========================================================================
// __unwind$488297_0
// EA  : 0x82EADBD0
// RVA : 0x00EADBD0
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_488297_0()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetVariablesFor@idSuperScriptSystem@@QAAPAUssVarInfo_t@@PBD@Z
// EA  : 0x82EADC00
// RVA : 0x00EADC00
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

ssVarInfo_t *__fastcall idSuperScriptSystem::GetVariablesFor(idSuperScriptSystem *this, const char *type)
{
  idSuperScript *superScriptInterface; // r29
  idSSFiber *currentFiber; // r26
  int allocFiberId; // r25
  ssVarInfo_t *v8; // r27
  int v9; // [sp+54h] [-4Ch]

  superScriptInterface = this->superScriptInterface;
  if ( superScriptInterface == nullptr )
    return nullptr;
  currentFiber = this->currentFiber;
  allocFiberId = this->allocFiberId;
  this->currentFiber = nullptr;
  this->allocFiberId = -1;
  v9 = (int)superScriptInterface->Lock(this: superScriptInterface, a2: this);
  v8 = this->superScriptInterface->GetVariablesFor(this: this->superScriptInterface, a2: type);
  this->allocFiberId = allocFiberId;
  this->currentFiber = currentFiber;
  superScriptInterface->Lock(this: superScriptInterface, a2: (idGameSuperInterface *)v9);
  return v8;
}


// ========================================================================
// __unwind$488323
// EA  : 0x82EADCB0
// RVA : 0x00EADCB0
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_488323()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetCommentTextFor@idSuperScriptSystem@@QAAPBDPBD@Z
// EA  : 0x82EADCE0
// RVA : 0x00EADCE0
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

const char *__fastcall idSuperScriptSystem::GetCommentTextFor(idSuperScriptSystem *this, const char *type)
{
  idSuperScript *superScriptInterface; // r29
  idSSFiber *currentFiber; // r26
  int allocFiberId; // r25
  const char *v8; // r27
  int v9; // [sp+54h] [-4Ch]

  superScriptInterface = this->superScriptInterface;
  if ( superScriptInterface == nullptr )
    return nullptr;
  currentFiber = this->currentFiber;
  allocFiberId = this->allocFiberId;
  this->currentFiber = nullptr;
  this->allocFiberId = -1;
  v9 = (int)superScriptInterface->Lock(this: superScriptInterface, a2: this);
  v8 = this->superScriptInterface->GetCommentTextFor(this: this->superScriptInterface, a2: type);
  this->allocFiberId = allocFiberId;
  this->currentFiber = currentFiber;
  superScriptInterface->Lock(this: superScriptInterface, a2: (idGameSuperInterface *)v9);
  return v8;
}


// ========================================================================
// __unwind$488349_0
// EA  : 0x82EADD90
// RVA : 0x00EADD90
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_488349_0()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetMetaDataFor@idSuperScriptSystem@@QAAPAUssMetaData_t@@PBD@Z
// EA  : 0x82EADDC0
// RVA : 0x00EADDC0
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

ssMetaData_t *__fastcall idSuperScriptSystem::GetMetaDataFor(idSuperScriptSystem *this, const char *type)
{
  idSuperScript *superScriptInterface; // r29
  idSSFiber *currentFiber; // r26
  int allocFiberId; // r25
  ssMetaData_t *v8; // r27
  int v9; // [sp+54h] [-4Ch]

  superScriptInterface = this->superScriptInterface;
  if ( superScriptInterface == nullptr )
    return nullptr;
  currentFiber = this->currentFiber;
  allocFiberId = this->allocFiberId;
  this->currentFiber = nullptr;
  this->allocFiberId = -1;
  v9 = (int)superScriptInterface->Lock(this: superScriptInterface, a2: this);
  v8 = this->superScriptInterface->GetMetaDataFor(this: this->superScriptInterface, a2: type);
  this->allocFiberId = allocFiberId;
  this->currentFiber = currentFiber;
  superScriptInterface->Lock(this: superScriptInterface, a2: (idGameSuperInterface *)v9);
  return v8;
}


// ========================================================================
// __unwind$488375_0
// EA  : 0x82EADE70
// RVA : 0x00EADE70
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_488375_0()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?BindObject@idSuperScriptSystem@@QAAXPAVidSSObject@@PAVidEntity@@@Z
// EA  : 0x82EADEA0
// RVA : 0x00EADEA0
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::BindObject(idSuperScriptSystem *this, idSSObject *object, idEntity *entity)
{
  idSuperScript *superScriptInterface; // r30
  idSuperScript_vtbl *v6; // r11
  int v7; // r28
  int *SpawnId; // r3
  _DWORD v9[16]; // [sp+50h] [-40h] BYREF

  if ( object != nullptr )
  {
    superScriptInterface = this->superScriptInterface;
    v6 = superScriptInterface->__vftable;
    v9[2] = superScriptInterface;
    v7 = (int)v6->Lock(this: superScriptInterface, a2: this);
    v9[3] = v7;
    SpawnId = (int *)idGameLocal::GetSpawnId(this: (idGameLocal *)v9, result: (idSpawnId *)gameLocal, ent: entity);
    object->_setEntity(this: object, a2: *SpawnId);
    superScriptInterface->Lock(this: superScriptInterface, a2: (idGameSuperInterface *)v7);
  }
}


// ========================================================================
// __unwind$488401_1
// EA  : 0x82EADF38
// RVA : 0x00EADF38
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_488401_1()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 144 + 88));
}


// ========================================================================
// ?ReturnVector@idSuperScriptSystem@@QAAXABVidVec3@@@Z
// EA  : 0x82EADF60
// RVA : 0x00EADF60
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::ReturnVector(idSuperScriptSystem *this, const idVec3 *vec)
{
  this->returnVector = *vec;
}


// ========================================================================
// ?DestroyObject@idSuperScriptSystem@@QAAXPAVidSSObject@@@Z
// EA  : 0x82EADF88
// RVA : 0x00EADF88
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::DestroyObject(
        idSuperScriptSystem *this,
        lobbyUser_t *object,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        lobbyUser_t *a14)
{
  int v16; // r27
  int v17; // r29
  idSSFiber **list; // r11
  idSSFiber *v19; // r10
  idSuperScript *superScriptInterface; // r29
  int v21; // [sp+54h] [-3Ch]

  a14 = object;
  if ( object != nullptr && this->superScriptInterface != nullptr && this->currentFiber == nullptr )
  {
    idList<idPresentableAnimatedEntity *,5>::Remove(this: (idList<lobbyUser_t *,5> *)&this->initObjects, obj: &a14);
    this->CreateThread(
      this,
      a2: "Destroy",
      a3: (idSSObject *)object,
      a4: idSuperScriptSystem::FiberEntry_Destroy,
      a5: nullptr);
    v16 = 0;
    if ( this->fibers.num > 0 )
    {
      v17 = 0;
      do
      {
        list = this->fibers.list;
        v19 = list[v17];
        if ( v19 != nullptr && (lobbyUser_t *)v19->object == object )
        {
          ((void (__fastcall *)(idSSFiber *, int))list[v17]->dtr_idSysFiber)(a1: list[v17], a2: 1);
          this->fibers.list[v17] = nullptr;
        }
        ++v16;
        ++v17;
      }
      while ( v16 < this->fibers.num );
    }
    superScriptInterface = this->superScriptInterface;
    v21 = (int)superScriptInterface->Lock(this: superScriptInterface, a2: this);
    (*(void (__fastcall **)(lobbyUser_t *, int))(*(_DWORD *)&object->isBot + 120))(a1: object, a2: 1);
    superScriptInterface->Lock(this: superScriptInterface, a2: (idGameSuperInterface *)v21);
  }
}


// ========================================================================
// __unwind$488798_1
// EA  : 0x82EAE0CC
// RVA : 0x00EAE0CC
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_488798_1()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 144 + 80));
}


// ========================================================================
// ?TracePoints@idSuperScriptSystem@@UAAHABUssVec3_t@@0HH@Z
// EA  : 0x82EAE0F8
// RVA : 0x00EAE0F8
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::TracePoints(
        idSuperScriptSystem *this,
        const ssVec3_t *start,
        const ssVec3_t *end,
        int contentMask,
        int ignoreID)
{
  int v6; // r10
  int v7; // r9
  int v8; // r30
  int *p_ownerThreadId; // r11
  double y; // fp13
  double z; // fp12
  char *v12; // r31
  double v13; // fp10
  double v14; // fp9
  unsigned __int64 v15; // r7
  int v17; // [sp+8h] [-98h]
  bool v18; // [sp+Fh] [-91h]
  const char *v19; // [sp+10h] [-90h]
  int v20; // [sp+14h] [-8Ch]
  int v21; // [sp+18h] [-88h]
  int v22; // [sp+1Ch] [-84h]
  int v23; // [sp+20h] [-80h]
  int v24; // [sp+24h] [-7Ch]
  int v25; // [sp+28h] [-78h]
  int v26; // [sp+2Ch] [-74h]
  int v27; // [sp+30h] [-70h]
  int v28; // [sp+34h] [-6Ch]
  int v29; // [sp+38h] [-68h]
  int v30; // [sp+3Ch] [-64h]
  int v31; // [sp+40h] [-60h]
  int v32; // [sp+44h] [-5Ch]
  int v33; // [sp+48h] [-58h]
  int v34; // [sp+4Ch] [-54h]
  int v35; // [sp+50h] [-50h]
  int v36; // [sp+58h] [-48h]
  int v37; // [sp+60h] [-40h]
  char v38; // [sp+70h] [-30h] BYREF

  v6 = contentMask;
  v7 = ignoreID;
  v8 = 0;
  p_ownerThreadId = &this->clipQueries[0].ownerThreadId;
  while ( *p_ownerThreadId != -1 )
  {
    ++v8;
    p_ownerThreadId += 12;
    if ( v8 >= 32 )
      goto LABEL_6;
  }
  if ( v8 == -1 )
LABEL_6:
    idLib::Error(fmt: "Super Script exceed max traces per frame of %i, use less or request the max be upped", 32);
  y = start->y;
  z = start->z;
  v12 = (char *)this + 48 * v8;
  *((float *)v12 + 16) = start->x;
  *((float *)v12 + 17) = y;
  *((float *)v12 + 18) = z;
  v13 = end->y;
  v14 = end->z;
  *((float *)v12 + 19) = end->x;
  *((float *)v12 + 20) = v13;
  *((float *)v12 + 21) = v14;
  *((_DWORD *)v12 + 22) = v6;
  if ( v7 >> 13 == gameLocal->spawnIds.ptr[v7 & 0x1FFF] )
    *((_DWORD *)v12 + 23) = v7;
  v15 = *(_QWORD *)&idClip::Translation(
                      this: (idClip *)&v38,
                      result: &clientGame->clip,
                      a3: nullptr,
                      start: (const idVec3 *)(v12 + 64),
                      end: (const idVec3 *)(v12 + 76),
                      clipModel: nullptr,
                      startAxis: &mat3_identity,
                      clipMask: v6,
                      passEntityNumber: v17,
                      moveClipModel: v18,
                      userName: v19,
                      a12: v20,
                      a13: v21,
                      a14: v22,
                      a15: v23,
                      a16: v24,
                      a17: v25,
                      a18: v26,
                      a19: v27,
                      a20: v28,
                      a21: v29,
                      a22: v30,
                      a23: v31,
                      a24: v32,
                      a25: v33,
                      a26: v34,
                      a27: v35,
                      a28: *((_DWORD *)v12 + 23) & 0x1FFF,
                      a29: v36,
                      a30: false,
                      a31: v37,
                      a32: (int)"Translation")->world;
  HIDWORD(v15) = 3 * (v8 + 2);
  this->clipQueries[v8].query.index = v15;
  *((_DWORD *)v12 + 26) = this->GetCurrentThreadId(this);
  return v8;
}


// ========================================================================
// ?GetTraceResults@idSuperScriptSystem@@UAAXHAAMAAUssVec3_t@@AAH@Z
// EA  : 0x82EAE248
// RVA : 0x00EAE248
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::GetTraceResults(
        idSuperScriptSystem *this,
        const int clipId,
        float *hitFraction,
        ssVec3_t *hitNormal,
        idGameLocal_vtbl **hitEntId)
{
  idClientGame *v7; // r10
  int v8; // r11
  __int128 v12; // r9
  int entityNum; // r4
  bool v14; // cr56
  double x; // fp13
  double y; // fp12
  double z; // fp11
  const idEntity *v18; // r3
  char v19; // [sp+50h] [-C0h] BYREF
  trace_t v20; // [sp+60h] [-B0h] BYREF

  v7 = clientGame;
  v8 = 48 * (clipId + 2);
  if ( *(unsigned int *)((char *)&this->dll + v8) > LODWORD(clientGame->clip.collisionQueryLastSubmittedIndex) )
    idLib::Error(
      fmt: "Super Script Attempted to get results from a trace still pending, you need to call ResolveTraces() before getting results");
  LODWORD(v12) = 0;
  *(_QWORD *)((char *)&v12 + 4) = *(_QWORD *)((char *)&this->__vftable + v8);
  *(_QWORD *)((char *)&this->__vftable + v8) = v12;
  idCollisionModelManager::GetContentsResult(
    this: collisionModelManager,
    result: &v20,
    query: &v7->clip.collisionQueries[WORD5(v12) & 0xFFF].query,
    peek: false);
  entityNum = v20.c.entityNum;
  v14 = v20.c.entityNum < 0x2000;
  x = v20.c.normal.x;
  y = v20.c.normal.y;
  z = v20.c.normal.z;
  *hitFraction = v20.fraction;
  hitNormal->x = x;
  hitNormal->y = y;
  hitNormal->z = z;
  if ( v14 && entityNum > -1 )
  {
    v18 = (const idEntity *)((int (__fastcall *)(idGameLocal *))gameLocal->GetEntity)(a1: gameLocal);
    *hitEntId = idGameLocal::GetSpawnId(this: (idGameLocal *)&v19, result: (idSpawnId *)gameLocal, ent: v18)->__vftable;
  }
  this->clipQueries[clipId].ownerThreadId = -1;
}


// ========================================================================
// ?TracesResolved@idSuperScriptSystem@@UAA_NXZ
// EA  : 0x82EAE378
// RVA : 0x00EAE378
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::TracesResolved(idSuperScriptSystem *this)
{
  int v2; // r29
  idClipQuery *i; // r30
  idClip *p_clip; // r31
  __int64 v6; // r9
  int v7; // [sp+8h] [-A8h]
  bool v8; // [sp+Fh] [-A1h]
  const char *v9; // [sp+10h] [-A0h]
  int v10; // [sp+14h] [-9Ch]
  int v11; // [sp+18h] [-98h]
  int v12; // [sp+1Ch] [-94h]
  int v13; // [sp+20h] [-90h]
  int v14; // [sp+24h] [-8Ch]
  int v15; // [sp+28h] [-88h]
  int v16; // [sp+2Ch] [-84h]
  int v17; // [sp+30h] [-80h]
  int v18; // [sp+34h] [-7Ch]
  int v19; // [sp+38h] [-78h]
  int v20; // [sp+3Ch] [-74h]
  int v21; // [sp+40h] [-70h]
  int v22; // [sp+44h] [-6Ch]
  int v23; // [sp+48h] [-68h]
  int v24; // [sp+4Ch] [-64h]
  int v25; // [sp+50h] [-60h]
  int v26; // [sp+58h] [-58h]
  int v27; // [sp+60h] [-50h]
  char v28; // [sp+70h] [-40h] BYREF

  v2 = 0;
  for ( i = &this->clipQueries[0].query; ; i += 6 )
  {
    if ( this->GetCurrentThreadId(this) == HIDWORD(i[1].index) )
    {
      if ( LODWORD(i->index) > LODWORD(clientGame->clip.collisionQueryLastSubmittedIndex) )
        return 0;
      p_clip = &clientGame->clip;
      if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: i) == 0 )
        break;
    }
    if ( ++v2 >= 32 )
      return 1;
  }
  v6 = *(_QWORD *)&idClip::Translation(
                     this: (idClip *)&v28,
                     result: p_clip,
                     a3: nullptr,
                     start: &this->clipQueries[v2].start,
                     end: &this->clipQueries[v2].end,
                     clipModel: nullptr,
                     startAxis: &mat3_identity,
                     clipMask: this->clipQueries[v2].contentMask,
                     passEntityNumber: v7,
                     moveClipModel: v8,
                     userName: v9,
                     a12: v10,
                     a13: v11,
                     a14: v12,
                     a15: v13,
                     a16: v14,
                     a17: v15,
                     a18: v16,
                     a19: v17,
                     a20: v18,
                     a21: v19,
                     a22: v20,
                     a23: v21,
                     a24: v22,
                     a25: v23,
                     a26: v24,
                     a27: v25,
                     a28: this->clipQueries[v2].ignoreEntity.spawnId.value & 0x1FFF,
                     a29: v26,
                     a30: false,
                     a31: v27,
                     a32: (int)"Translation")->world;
  HIDWORD(v6) = 3 * (v2 + 2);
  *((_QWORD *)&this->__vftable + 2 * HIDWORD(v6)) = v6;
  return 0;
}


// ========================================================================
// ?CreateNamedThread@idSuperScriptSystem@@UAAHHPBD@Z
// EA  : 0x82EAE4A8
// RVA : 0x00EAE4A8
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::CreateNamedThread(idSuperScriptSystem *this, int entId, const char *name)
{
  int v4; // r3
  int v5; // r11
  int v6; // r29
  int v7; // r30
  int i; // r28
  char v9; // r11
  bool v10; // zf
  idSSObject *v11; // r31
  void (__fastcall *v12)(idSSObject *, void *); // r6

  v4 = ((int (__fastcall *)(idGameLocal *))gameLocal->GetEntityForSpawnId)(a1: gameLocal);
  v5 = *(_DWORD *)(v4 + 736);
  v6 = v4;
  v7 = 0;
  if ( v5 <= 0 )
    return 0;
  for ( i = 0; ; i += 4 )
  {
    if ( v7 < 0 || (v10 = v7 < v5, v9 = 1, !v10) )
      v9 = 0;
    if ( v9 != 0 )
    {
      v11 = *(idSSObject **)(*(_DWORD *)(v6 + 732) + i);
      if ( v11 != nullptr )
      {
        v12 = v11->_getThreadFunction(this: v11, a2: name);
        if ( v12 != nullptr )
          break;
      }
    }
    v5 = *(_DWORD *)(v6 + 736);
    if ( ++v7 >= v5 )
      return 0;
  }
  return gameLocal->superScript.CreateThread(
           this: &gameLocal->superScript,
           a2: &byte_8200D768,
           a3: v11,
           a4: v12,
           a5: nullptr);
}


// ========================================================================
// ?InvokeNamedFunction@idSuperScriptSystem@@QAA_NPBD@Z
// EA  : 0x82EAE5A0
// RVA : 0x00EAE5A0
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

int __fastcall idSuperScriptSystem::InvokeNamedFunction(idSuperScriptSystem *this, const char *callStr)
{
  const char *v3; // r21
  idWorldspawn *world; // r27
  int v5; // r3
  int v6; // r30
  int num; // r11
  int v9; // r24
  int v10; // r28
  int v11; // r25
  char v12; // r11
  bool v13; // zf
  idSSObject *v14; // r30
  void (__fastcall *v15)(idSSObject *, void *); // r6
  idStr v16[4]; // [sp+50h] [-80h] BYREF

  if ( callStr == nullptr || *callStr == 0 )
    return 1;
  v3 = callStr;
  world = gameLocal->world;
  v5 = idStr::Find(str: callStr, c: 46, start: 0, end: -1);
  v6 = v5;
  if ( v5 != -1 )
  {
    v3 = &callStr[v5 + 1];
    idStr::idStr(this: v16, text: callStr);
    if ( v16[0].len > v6 && v6 >= 0 )
    {
      v16[0].data[v6] = 0;
      v16[0].len = v6;
    }
    world = (idWorldspawn *)gameLocal->FindEntity(this: gameLocal, a2: v16[0].data);
    if ( world == nullptr )
    {
      idLib::Warning(fmt: "Entity %s not found while trying to call %s", v16[0].data, callStr);
      idStr::FreeData(this: v16);
      return 0;
    }
    idStr::FreeData(this: v16);
  }
  num = world->superScriptObjects.num;
  v9 = 0;
  v10 = 0;
  if ( num > 0 )
  {
    v11 = 0;
    do
    {
      if ( v10 < 0 || (v13 = v10 < num, v12 = 1, !v13) )
        v12 = 0;
      if ( v12 != 0 )
      {
        v14 = world->superScriptObjects.list[v11];
        if ( v14 != nullptr )
        {
          v15 = v14->_getThreadFunction(this: v14, a2: v3);
          if ( v15 != nullptr )
          {
            gameLocal->superScript.CreateThread(
              this: &gameLocal->superScript,
              a2: &byte_8200D768,
              a3: v14,
              a4: v15,
              a5: nullptr);
            v9 = 1;
          }
        }
      }
      num = world->superScriptObjects.num;
      ++v10;
      ++v11;
    }
    while ( v10 < num );
  }
  if ( (_BYTE)v9 == 0 )
    idLib::Warning(fmt: "Script function not found while trying to call %s", callStr);
  return v9;
}


// ========================================================================
// __unwind$489029_0
// EA  : 0x82EAE774
// RVA : 0x00EAE774
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_489029_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?InitObjectsInInitList@idSuperScriptSystem@@QAAXXZ
// EA  : 0x82EAE7A0
// RVA : 0x00EAE7A0
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::InitObjectsInInitList(idSuperScriptSystem *this)
{
  int v2; // r29
  int v3; // r30
  idSSObject **list; // r11
  idSSObject **v5; // r4

  if ( this->initObjects.num > 0 )
  {
    v2 = 0;
    v3 = 0;
    do
    {
      list = this->initObjects.list;
      if ( list[v3] != nullptr )
        this->CreateThread(this, a2: "Init", a3: list[v3], a4: idSuperScriptSystem::FiberEntry_Init, a5: nullptr);
      ++v2;
      ++v3;
    }
    while ( v2 < this->initObjects.num );
    if ( this->initObjects.listStatic == 0 || this->initObjects.listStatic == 2 )
    {
      v5 = this->initObjects.list;
      if ( v5 != nullptr )
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
      this->initObjects.list = nullptr;
      this->initObjects.size = 0;
    }
    this->initObjects.num = 0;
  }
}


// ========================================================================
// ??0idSuperScriptSystem@@QAA@XZ
// EA  : 0x82EAE870
// RVA : 0x00EAE870
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

idSuperScriptSystem *__fastcall idSuperScriptSystem::idSuperScriptSystem(idSuperScriptSystem *this)
{
  idList<idSSObject *,108> *p_initObjects; // r11
  int i; // ctr
  int v4; // ctr
  int *p_size; // r11

  this->__vftable = (idSuperScriptSystem_vtbl *)&idSuperScriptSystem::`vftable';
  this->objects.list = nullptr;
  this->objects.granularity = 0;
  this->objects.memTag = 108;
  this->objects.listStatic = 0;
  this->objects.size = 0;
  this->objects.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->objects);
  this->fibers.list = nullptr;
  this->fibers.granularity = 0;
  this->fibers.memTag = 108;
  this->fibers.listStatic = 0;
  this->fibers.size = 0;
  this->fibers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->fibers);
  this->initObjects.list = nullptr;
  this->initObjects.granularity = 0;
  this->initObjects.memTag = 108;
  this->initObjects.listStatic = 0;
  this->initObjects.size = 0;
  this->initObjects.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->initObjects);
  p_initObjects = &this->initObjects;
  for ( i = 32; i != 0; --i )
  {
    *(_DWORD *)&p_initObjects[2].granularity = 0x1FFF;
    p_initObjects += 3;
    *(_QWORD *)&p_initObjects->list = 0x6C00000000LL;
  }
  this->returnColor.a = -1.0;
  this->returnColor.b = -1.0;
  this->returnColor.g = -1.0;
  v4 = 32;
  this->returnColor.r = -1.0;
  this->returnString.data = this->returnString.baseBuffer;
  this->returnString.allocedAndFlag = 20;
  p_size = &this->initObjects.size;
  this->returnString.len = 0;
  this->returnString.baseBuffer[0] = 0;
  this->dll = 0;
  this->superScriptInterface = nullptr;
  this->currentFiber = nullptr;
  this->nextFiberId = 1;
  this->allocFiberId = -1;
  do
  {
    p_size += 12;
    *p_size = -1;
    --v4;
  }
  while ( v4 != 0 );
  return this;
}


// ========================================================================
// __unwind$489228
// EA  : 0x82EAE994
// RVA : 0x00EAE994
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_489228()
{
  int v0; // r12

  idGameSuperInterface::~idGameSuperInterface(this: *(idGameSuperInterface **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489229
// EA  : 0x82EAE9BC
// RVA : 0x00EAE9BC
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_489229()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 12));
}


// ========================================================================
// __unwind$489230
// EA  : 0x82EAE9E8
// RVA : 0x00EAE9E8
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_489230()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 28));
}


// ========================================================================
// ??1idSuperScriptSystem@@UAA@XZ
// EA  : 0x82EAEB10
// RVA : 0x00EAEB10
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::~idSuperScriptSystem(idSuperScriptSystem *this)
{
  idList<idSSObject *,108> *p_initObjects; // r11
  __int64 v3; // r29
  int i; // ctr
  idSSObject **list; // r4
  idSSObject **v6; // r4

  this->__vftable = (idSuperScriptSystem_vtbl *)&idSuperScriptSystem::`vftable';
  HIDWORD(v3) = &this->fibers;
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->fibers);
  p_initObjects = &this->initObjects;
  LODWORD(v3) = 0;
  for ( i = 32; i != 0; --i )
  {
    p_initObjects += 3;
    *(_QWORD *)&p_initObjects->list = v3;
  }
  idSuperScriptSystem::UnloadDLL(this);
  idStr::FreeData(this: &this->returnString);
  if ( this->initObjects.listStatic == 0 || this->initObjects.listStatic == 2 )
  {
    list = this->initObjects.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->initObjects.list = nullptr;
    this->initObjects.size = 0;
  }
  this->initObjects.num = 0;
  if ( *(_BYTE *)(HIDWORD(v3) + 15) == 0 || *(_BYTE *)(HIDWORD(v3) + 15) == 2 )
  {
    if ( *(_DWORD *)HIDWORD(v3) != 0 )
      idMem::Free(this: &mem, ptr: *(void **)HIDWORD(v3), align: ALIGN_16);
    *(_DWORD *)HIDWORD(v3) = 0;
    *(_DWORD *)(HIDWORD(v3) + 8) = 0;
  }
  *(_DWORD *)(HIDWORD(v3) + 4) = 0;
  if ( this->objects.listStatic == 0 || this->objects.listStatic == 2 )
  {
    v6 = this->objects.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->objects.list = nullptr;
    this->objects.size = 0;
  }
  this->objects.num = 0;
  this->__vftable = (idSuperScriptSystem_vtbl *)&idGameSuperInterface::`vftable';
}


// ========================================================================
// __unwind$489397_0
// EA  : 0x82EAEC38
// RVA : 0x00EAEC38
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_489397_0()
{
  int v0; // r12

  idGameSuperInterface::~idGameSuperInterface(this: *(idGameSuperInterface **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$489398_1
// EA  : 0x82EAEC60
// RVA : 0x00EAEC60
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_489398_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 12));
}


// ========================================================================
// __unwind$489399_0
// EA  : 0x82EAEC8C
// RVA : 0x00EAEC8C
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_489399_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 28));
}


// ========================================================================
// __unwind$489400_1
// EA  : 0x82EAECB8
// RVA : 0x00EAECB8
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_489400_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 48));
}


// ========================================================================
// __unwind$489401_0
// EA  : 0x82EAECE4
// RVA : 0x00EAECE4
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_489401_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 1636));
}


// ========================================================================
// ?GetScriptObjectNames@idSuperScriptSystem@@QAAXAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82EAED78
// RVA : 0x00EAED78
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::GetScriptObjectNames(idSuperScriptSystem *this, idList<idStr,5> *list)
{
  idSuperScript *superScriptInterface; // r28
  int v5; // r26
  const char **v6; // r3
  const char *v7; // r4
  const char **v8; // r29
  int i; // r30
  idStr v10[3]; // [sp+60h] [-60h] BYREF

  superScriptInterface = this->superScriptInterface;
  if ( superScriptInterface != nullptr )
  {
    v5 = (int)superScriptInterface->Lock(this: this->superScriptInterface, a2: this);
    v6 = this->superScriptInterface->GetObjectList(this: this->superScriptInterface);
    v7 = *v6;
    v8 = v6;
    for ( i = 0; v7 != nullptr; v7 = v8[i] )
    {
      idStr::idStr(this: v10, text: v7);
      idList<idStr,5>::Append(this: list, obj: v10);
      idStr::FreeData(this: v10);
      ++i;
    }
    superScriptInterface->Lock(this: superScriptInterface, a2: (idGameSuperInterface *)v5);
  }
}


// ========================================================================
// __unwind$489601
// EA  : 0x82EAEE38
// RVA : 0x00EAEE38
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_489601()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$489602
// EA  : 0x82EAEE60
// RVA : 0x00EAEE60
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void _unwind_489602()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?AddObjectToInitList@idSuperScriptSystem@@QAAXPAVidSSObject@@@Z
// EA  : 0x82EAEE88
// RVA : 0x00EAEE88
// PDB : w:\tech5\tungsten\game\superscript\ss_system.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::AddObjectToInitList(
        idSuperScriptSystem *this,
        idSSObject *object,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idSSObject *a14)
{
  idList<enum encounterGroupRole_t,5> *p_initObjects; // r3
  int v15; // r10
  int num; // r9
  int v17; // r11

  p_initObjects = (idList<enum encounterGroupRole_t,5> *)&this->initObjects;
  a14 = object;
  v15 = 0;
  num = p_initObjects->num;
  if ( num <= 0 )
    goto LABEL_7;
  v17 = 0;
  while ( (idSSObject *)p_initObjects->list[v17] != object )
  {
    ++v15;
    ++v17;
    if ( v15 >= num )
      goto LABEL_7;
  }
  if ( v15 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(this: p_initObjects, obj: (encounterGroupRole_t *)&a14);
}

