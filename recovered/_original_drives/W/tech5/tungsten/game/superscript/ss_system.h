
// ========================================================================
// ??$CreateThreadDelayed1@H@idSuperScriptSystem@@AAAHPBDPAVidSSObject@@P6AX1H@ZH@Z
// EA  : 0x82C42C50
// RVA : 0x00C42C50
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

int __fastcall idSuperScriptSystem::CreateThreadDelayed1<int>(
        idSuperScriptSystem *this,
        const char *name,
        idSSObject *sso,
        idSSFiber_vtbl *entryPoint,
        char *p1)
{
  int nextFiberId; // r29
  idSSFiber *v12; // r3
  idSSFiber *v13; // r30
  idSSFiber *v14; // r11
  idSSFiber *v15; // [sp+50h] [-50h] BYREF

  if ( sso == nullptr )
    return 0;
  nextFiberId = this->nextFiberId;
  this->nextFiberId = nextFiberId + 1;
  v12 = (idSSFiber *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                       size: 0x38u,
                       tag: TAG_NEW,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v13 = v12;
  v15 = v12;
  if ( v12 != nullptr )
  {
    idSSFiber::idSSFiber(this: v12, name, fiberId: nextFiberId, sso);
    v13[1].__vftable = entryPoint;
    v14 = v13;
    v13[1].name = p1;
    v13->__vftable = (idSSFiber_vtbl *)&idSSFiber1<int>::`vftable';
  }
  else
  {
    v14 = nullptr;
  }
  v15 = v14;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fibers,
    obj: (encounterGroupRole_t *)&v15);
  return nextFiberId;
}


// ========================================================================
// __unwind$507043
// EA  : 0x82C42D14
// RVA : 0x00C42D14
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

void __fastcall _unwind_507043(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ??$CreateThreadDelayed2@HM@idSuperScriptSystem@@AAAHPBDPAVidSSObject@@P6AX1HM@ZHM@Z
// EA  : 0x82C42D48
// RVA : 0x00C42D48
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

int __fastcall idSuperScriptSystem::CreateThreadDelayed2<int,float>(
        idSuperScriptSystem *this,
        const char *name,
        idSSObject *sso,
        idSSFiber_vtbl *entryPoint,
        char *p1,
        double p2)
{
  int nextFiberId; // r29
  idSSFiber *v14; // r3
  idSSFiber *v15; // r30
  idSSFiber *v16; // r11
  idSSFiber *v17; // [sp+50h] [-60h] BYREF

  if ( sso == nullptr )
    return 0;
  nextFiberId = this->nextFiberId;
  this->nextFiberId = nextFiberId + 1;
  v14 = (idSSFiber *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                       size: 0x3Cu,
                       tag: TAG_NEW,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v15 = v14;
  v17 = v14;
  if ( v14 != nullptr )
  {
    idSSFiber::idSSFiber(this: v14, name, fiberId: nextFiberId, sso);
    *(float *)&v15[1].alive = p2;
    v15[1].__vftable = entryPoint;
    v15[1].name = p1;
    v16 = v15;
    v15->__vftable = (idSSFiber_vtbl *)&idSSFiber2<int,float>::`vftable';
  }
  else
  {
    v16 = nullptr;
  }
  v17 = v16;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fibers,
    obj: (encounterGroupRole_t *)&v17);
  return nextFiberId;
}


// ========================================================================
// __unwind$507101
// EA  : 0x82C42E1C
// RVA : 0x00C42E1C
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

void __fastcall _unwind_507101(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 80), tag: a2);
}


// ========================================================================
// ??$CreateThreadDelayed1@PBD@idSuperScriptSystem@@AAAHPBDPAVidSSObject@@P6AX10@Z0@Z
// EA  : 0x82C42E50
// RVA : 0x00C42E50
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

int __fastcall idSuperScriptSystem::CreateThreadDelayed1<char const *>(
        idSuperScriptSystem *this,
        const char *name,
        idSSObject *sso,
        idSSFiber_vtbl *entryPoint,
        char *p1)
{
  int nextFiberId; // r29
  idSSFiber *v12; // r3
  idSSFiber *v13; // r30
  idSSFiber *v14; // r11
  idSSFiber *v15; // [sp+50h] [-50h] BYREF

  if ( sso == nullptr )
    return 0;
  nextFiberId = this->nextFiberId;
  this->nextFiberId = nextFiberId + 1;
  v12 = (idSSFiber *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                       size: 0x38u,
                       tag: TAG_NEW,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v13 = v12;
  v15 = v12;
  if ( v12 != nullptr )
  {
    idSSFiber::idSSFiber(this: v12, name, fiberId: nextFiberId, sso);
    v13[1].__vftable = entryPoint;
    v14 = v13;
    v13[1].name = p1;
    v13->__vftable = (idSSFiber_vtbl *)&idSSFiber1<char const *>::`vftable';
  }
  else
  {
    v14 = nullptr;
  }
  v15 = v14;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fibers,
    obj: (encounterGroupRole_t *)&v15);
  return nextFiberId;
}


// ========================================================================
// __unwind$507130
// EA  : 0x82C42F14
// RVA : 0x00C42F14
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

void __fastcall _unwind_507130(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ??1idSSLock@@QAA@XZ
// EA  : 0x82EAB050
// RVA : 0x00EAB050
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

void __fastcall idSSLock::~idSSLock(idSSLock *this)
{
  this->superScript->Lock(this: this->superScript, a2: this->prev);
}


// ========================================================================
// ?FiberEntry_Init@idSuperScriptSystem@@CAXPAVidSSObject@@PAX@Z
// EA  : 0x82EAB7F8
// RVA : 0x00EAB7F8
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_Init(idSSObject *object, void *__formal)
{
  ((void (__fastcall *)(idSSObject *, void *))object->Init)(a1: object, a2: __formal);
}


// ========================================================================
// ?FiberEntry_Destroy@idSuperScriptSystem@@CAXPAVidSSObject@@PAX@Z
// EA  : 0x82EAD728
// RVA : 0x00EAD728
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_Destroy(idSSObject *object, void *__formal)
{
  ((void (__fastcall *)(idSSObject *, void *))object->Destroy)(a1: object, a2: __formal);
}


// ========================================================================
// ?SetCVarString@idSuperScriptSystem@@UAAXPBD0@Z
// EA  : 0x82EAEA18
// RVA : 0x00EAEA18
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

void __fastcall idSuperScriptSystem::SetCVarString(idSuperScriptSystem *this, const char *name, const char *value)
{
  cvarSystem->SetCVarString(this: cvarSystem, a2: name, a3: value, a4: 0);
}


// ========================================================================
// ?SetCVarBool@idSuperScriptSystem@@UAAXPBD_N@Z
// EA  : 0x82EAEA38
// RVA : 0x00EAEA38
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

void __fastcall idSuperScriptSystem::SetCVarBool(idSuperScriptSystem *this, const char *name, bool value)
{
  cvarSystem->SetCVarBool(this: cvarSystem, a2: name, a3: value, a4: 0);
}


// ========================================================================
// ?SetCVarInteger@idSuperScriptSystem@@UAAXPBDH@Z
// EA  : 0x82EAEA58
// RVA : 0x00EAEA58
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

void __fastcall idSuperScriptSystem::SetCVarInteger(idSuperScriptSystem *this, const char *name, int value)
{
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: name, a3: value, a4: 0);
}


// ========================================================================
// ?SetCVarFloat@idSuperScriptSystem@@UAAXPBDM@Z
// EA  : 0x82EAEA78
// RVA : 0x00EAEA78
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

void __fastcall idSuperScriptSystem::SetCVarFloat(idSuperScriptSystem *this, const char *name, double value, int a4)
{
  ((void (__fastcall *)(idCVarSystem *, const char *, int, _DWORD, double))cvarSystem->SetCVarFloat)(
    a1: cvarSystem,
    a2: name,
    a3: a4,
    a4: 0,
    a5: value);
}


// ========================================================================
// ?GetCVarString@idSuperScriptSystem@@UBAPBDPBD0@Z
// EA  : 0x82EAEA98
// RVA : 0x00EAEA98
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

const char *__fastcall idSuperScriptSystem::GetCVarString(
        idSuperScriptSystem *this,
        const char *name,
        const char *defValue)
{
  return cvarSystem->GetCVarString(this: cvarSystem, a2: name, a3: defValue);
}


// ========================================================================
// ?GetCVarBool@idSuperScriptSystem@@UBA_NPBD_N@Z
// EA  : 0x82EAEAB0
// RVA : 0x00EAEAB0
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

BOOL __fastcall idSuperScriptSystem::GetCVarBool(idSuperScriptSystem *this, const char *name, bool defValue)
{
  return cvarSystem->GetCVarBool(this: cvarSystem, a2: name, a3: defValue);
}


// ========================================================================
// ?GetCVarInteger@idSuperScriptSystem@@UBAHPBDH@Z
// EA  : 0x82EAEAC8
// RVA : 0x00EAEAC8
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

int __fastcall idSuperScriptSystem::GetCVarInteger(idSuperScriptSystem *this, const char *name, int defValue)
{
  return cvarSystem->GetCVarInteger(this: cvarSystem, a2: name, a3: defValue);
}


// ========================================================================
// ?GetCVarFloat@idSuperScriptSystem@@UBAMPBDM@Z
// EA  : 0x82EAEAE0
// RVA : 0x00EAEAE0
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

float __fastcall idSuperScriptSystem::GetCVarFloat(idSuperScriptSystem *this, const char *name, double defValue)
{
  double v3; // fp1

  v3 = cvarSystem->GetCVarFloat(this: cvarSystem, a2: name, a3: defValue);
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?IsDeclValid@idSuperScriptSystem@@UAA_NPBX@Z
// EA  : 0x82EAEAF8
// RVA : 0x00EAEAF8
// PDB : w:\tech5\tungsten\game\superscript\ss_system.h
// ========================================================================

BOOL __fastcall idSuperScriptSystem::IsDeclValid(idSuperScriptSystem *this, const void *decl)
{
  return decl != nullptr;
}

