
// ========================================================================
// ??$ArgCompletion_Decl@VidDeclBreakable@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82613A70
// RVA : 0x00613A70
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclBreakable>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclBreakable::resourceList);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclRenderParm@@@@UBAPAVidDeclRenderParm@@XZ
// EA  : 0x82620608
// RVA : 0x00620608
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclRenderParm *__fastcall idDeclInfoTemplate<idDeclRenderParm>::AllocDecl(
        idDeclInfoTemplate<idDeclRenderParm> *this)
{
  idDeclRenderParm *v1; // r3

  v1 = (idDeclRenderParm *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x64u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclRenderParm::idDeclRenderParm(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$221689_0
// EA  : 0x82620670
// RVA : 0x00620670
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221689_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclRenderParm@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x826206A8
// RVA : 0x006206A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclRenderParm *__fastcall idDeclInfoTemplate<idDeclRenderParm>::Alloc(
        idDeclInfoTemplate<idDeclRenderParm> *this,
        const char *name)
{
  idDeclRenderParm *v3; // r3
  idDeclRenderParm *v4; // r30

  v3 = (idDeclRenderParm *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x64u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclRenderParm::idDeclRenderParm(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$221712
// EA  : 0x82620718
// RVA : 0x00620718
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221712()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclMD6@@@@UBAPAVidDeclMD6@@XZ
// EA  : 0x82620750
// RVA : 0x00620750
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclMD6 *__fastcall idDeclInfoTemplate<idDeclMD6>::AllocDecl(idDeclInfoTemplate<idDeclMD6> *this)
{
  idDeclMD6 *v1; // r3

  v1 = (idDeclMD6 *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x2F4u,
                      tag: TAG_DECL,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclMD6::idDeclMD6(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$221743
// EA  : 0x826207B8
// RVA : 0x006207B8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221743()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclMD6@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x826207F0
// RVA : 0x006207F0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclMD6 *__fastcall idDeclInfoTemplate<idDeclMD6>::Alloc(idDeclInfoTemplate<idDeclMD6> *this, const char *name)
{
  idDeclMD6 *v3; // r3
  idDeclMD6 *v4; // r30

  v3 = (idDeclMD6 *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x2F4u,
                      tag: TAG_DECL,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclMD6::idDeclMD6(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$221766_0
// EA  : 0x82620860
// RVA : 0x00620860
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221766_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclMD6@@@@UBAHXZ
// EA  : 0x82620890
// RVA : 0x00620890
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclMD6>::AllocSize(idDeclInfoTemplate<idDeclMD6> *this)
{
  return 756;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclTypeInfo@@@@UBAPAVidDeclTypeInfo@@XZ
// EA  : 0x826208A0
// RVA : 0x006208A0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTypeInfo *__fastcall idDeclInfoTemplate<idDeclTypeInfo>::AllocDecl(idDeclInfoTemplate<idDeclTypeInfo> *this)
{
  idDeclTypeInfo *v1; // r3

  v1 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x40u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclTypeInfo::idDeclTypeInfo(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$221793
// EA  : 0x82620908
// RVA : 0x00620908
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221793()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclTypeInfo@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82620940
// RVA : 0x00620940
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTypeInfo *__fastcall idDeclInfoTemplate<idDeclTypeInfo>::Alloc(
        idDeclInfoTemplate<idDeclTypeInfo> *this,
        const char *name)
{
  idDeclTypeInfo *v3; // r3
  idDeclTypeInfo *v4; // r30

  v3 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x40u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclTypeInfo::idDeclTypeInfo(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$221816
// EA  : 0x826209B0
// RVA : 0x006209B0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221816()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclTable@@@@UBAPAVidDeclTable@@XZ
// EA  : 0x826209E8
// RVA : 0x006209E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTable *__fastcall idDeclInfoTemplate<idDeclTable>::AllocDecl(idDeclInfoTemplate<idDeclTable> *this)
{
  idDeclTable *v1; // r3

  v1 = (idDeclTable *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x44u,
                        tag: TAG_DECL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclTable::idDeclTable(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$221843
// EA  : 0x82620A50
// RVA : 0x00620A50
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221843()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclTable@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82620A88
// RVA : 0x00620A88
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTable *__fastcall idDeclInfoTemplate<idDeclTable>::Alloc(idDeclInfoTemplate<idDeclTable> *this, const char *name)
{
  idDeclTable *v3; // r3
  idDeclTable *v4; // r30

  v3 = (idDeclTable *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x44u,
                        tag: TAG_DECL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclTable::idDeclTable(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$221866
// EA  : 0x82620AF8
// RVA : 0x00620AF8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221866()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclEntityDef@@@@UBAPAVidDeclEntityDef@@XZ
// EA  : 0x82620B30
// RVA : 0x00620B30
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclEntityDef *__fastcall idDeclInfoTemplate<idDeclEntityDef>::AllocDecl(idDeclInfoTemplate<idDeclEntityDef> *this)
{
  idDeclEntityDef *v1; // r3

  v1 = (idDeclEntityDef *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0xC8u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclEntityDef::idDeclEntityDef(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$221893
// EA  : 0x82620B98
// RVA : 0x00620B98
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221893()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclEntityDef@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82620BD0
// RVA : 0x00620BD0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclEntityDef *__fastcall idDeclInfoTemplate<idDeclEntityDef>::Alloc(
        idDeclInfoTemplate<idDeclEntityDef> *this,
        const char *name)
{
  idDeclEntityDef *v3; // r3
  idDeclEntityDef *v4; // r30

  v3 = (idDeclEntityDef *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0xC8u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclEntityDef::idDeclEntityDef(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$221916
// EA  : 0x82620C40
// RVA : 0x00620C40
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221916()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Size@idDeclEntityDef@@UBAIXZ
// EA  : 0x82620C70
// RVA : 0x00620C70
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

unsigned int __fastcall idDeclEntityDef::Size(idDeclEntityDef *this)
{
  return 200;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclFX@@@@UBAPAVidDeclFX@@XZ
// EA  : 0x82620C80
// RVA : 0x00620C80
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclFX *__fastcall idDeclInfoTemplate<idDeclFX>::AllocDecl(idDeclInfoTemplate<idDeclFX> *this)
{
  idDeclFX *v1; // r3

  v1 = (idDeclFX *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                     size: 0x5Cu,
                     tag: TAG_DECL,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclFX::idDeclFX(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$221943
// EA  : 0x82620CE8
// RVA : 0x00620CE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221943()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclFX@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82620D20
// RVA : 0x00620D20
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclFX *__fastcall idDeclInfoTemplate<idDeclFX>::Alloc(idDeclInfoTemplate<idDeclFX> *this, const char *name)
{
  idDeclFX *v3; // r3
  idDeclFX *v4; // r30

  v3 = (idDeclFX *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                     size: 0x5Cu,
                     tag: TAG_DECL,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclFX::idDeclFX(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$221966
// EA  : 0x82620D90
// RVA : 0x00620D90
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221966()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAF@@@@UBAPAVidDeclAF@@XZ
// EA  : 0x82620DC8
// RVA : 0x00620DC8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAF *__fastcall idDeclInfoTemplate<idDeclAF>::AllocDecl(idDeclInfoTemplate<idDeclAF> *this)
{
  idDeclAF *v1; // r3

  v1 = (idDeclAF *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                     size: 0x110u,
                     tag: TAG_DECL,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAF::idDeclAF(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$221993
// EA  : 0x82620E30
// RVA : 0x00620E30
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_221993()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAF@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82620E68
// RVA : 0x00620E68
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAF *__fastcall idDeclInfoTemplate<idDeclAF>::Alloc(idDeclInfoTemplate<idDeclAF> *this, const char *name)
{
  idDeclAF *v3; // r3
  idDeclAF *v4; // r30

  v3 = (idDeclAF *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                     size: 0x110u,
                     tag: TAG_DECL,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAF::idDeclAF(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222016
// EA  : 0x82620ED8
// RVA : 0x00620ED8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222016()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclWalkIK@@@@UBAPAVidDeclWalkIK@@XZ
// EA  : 0x82620F10
// RVA : 0x00620F10
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclWalkIK *__fastcall idDeclInfoTemplate<idDeclWalkIK>::AllocDecl(idDeclInfoTemplate<idDeclWalkIK> *this)
{
  idDeclWalkIK *v1; // r3

  v1 = (idDeclWalkIK *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x9Cu,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclWalkIK::idDeclWalkIK(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222043
// EA  : 0x82620F78
// RVA : 0x00620F78
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222043()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclWalkIK@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82620FB0
// RVA : 0x00620FB0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclWalkIK *__fastcall idDeclInfoTemplate<idDeclWalkIK>::Alloc(
        idDeclInfoTemplate<idDeclWalkIK> *this,
        const char *name)
{
  idDeclWalkIK *v3; // r3
  idDeclWalkIK *v4; // r30

  v3 = (idDeclWalkIK *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x9Cu,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclWalkIK::idDeclWalkIK(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222066
// EA  : 0x82621020
// RVA : 0x00621020
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222066()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclReachIK@@@@UBAPAVidDeclReachIK@@XZ
// EA  : 0x82621058
// RVA : 0x00621058
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclReachIK *__fastcall idDeclInfoTemplate<idDeclReachIK>::AllocDecl(idDeclInfoTemplate<idDeclReachIK> *this)
{
  idDeclReachIK *v1; // r3

  v1 = (idDeclReachIK *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x50u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclReachIK::idDeclReachIK(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222093
// EA  : 0x826210C0
// RVA : 0x006210C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222093()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclReachIK@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x826210F8
// RVA : 0x006210F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclReachIK *__fastcall idDeclInfoTemplate<idDeclReachIK>::Alloc(
        idDeclInfoTemplate<idDeclReachIK> *this,
        const char *name)
{
  idDeclReachIK *v3; // r3
  idDeclReachIK *v4; // r30

  v3 = (idDeclReachIK *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x50u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclReachIK::idDeclReachIK(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222116
// EA  : 0x82621168
// RVA : 0x00621168
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222116()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclBreakable@@@@UBAPAVidDeclBreakable@@XZ
// EA  : 0x826211A0
// RVA : 0x006211A0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclBreakable *__fastcall idDeclInfoTemplate<idDeclBreakable>::AllocDecl(idDeclInfoTemplate<idDeclBreakable> *this)
{
  idDeclBreakable *v1; // r3

  v1 = (idDeclBreakable *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x114u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclBreakable::idDeclBreakable(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222145
// EA  : 0x82621208
// RVA : 0x00621208
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222145()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclBreakable@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82621240
// RVA : 0x00621240
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclBreakable *__fastcall idDeclInfoTemplate<idDeclBreakable>::Alloc(
        idDeclInfoTemplate<idDeclBreakable> *this,
        const char *name)
{
  idDeclBreakable *v3; // r3
  idDeclBreakable *v4; // r30

  v3 = (idDeclBreakable *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x114u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclBreakable::idDeclBreakable(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222168
// EA  : 0x826212B0
// RVA : 0x006212B0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222168()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclRibbon@@@@UBAPAVidDeclRibbon@@XZ
// EA  : 0x826212E8
// RVA : 0x006212E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclRibbon *__fastcall idDeclInfoTemplate<idDeclRibbon>::AllocDecl(idDeclInfoTemplate<idDeclRibbon> *this)
{
  idDeclRibbon *v1; // r3

  v1 = (idDeclRibbon *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD0u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclRibbon::idDeclRibbon(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222195
// EA  : 0x82621350
// RVA : 0x00621350
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222195()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclRibbon@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82621388
// RVA : 0x00621388
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclRibbon *__fastcall idDeclInfoTemplate<idDeclRibbon>::Alloc(
        idDeclInfoTemplate<idDeclRibbon> *this,
        const char *name)
{
  idDeclRibbon *v3; // r3
  idDeclRibbon *v4; // r30

  v3 = (idDeclRibbon *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD0u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclRibbon::idDeclRibbon(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222218
// EA  : 0x826213F8
// RVA : 0x006213F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222218()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclRollBones@@@@UBAPAVidDeclRollBones@@XZ
// EA  : 0x82621430
// RVA : 0x00621430
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclRollBones *__fastcall idDeclInfoTemplate<idDeclRollBones>::AllocDecl(idDeclInfoTemplate<idDeclRollBones> *this)
{
  idDeclRollBones *v1; // r3

  v1 = (idDeclRollBones *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x50u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclRollBones::idDeclRollBones(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222245
// EA  : 0x82621498
// RVA : 0x00621498
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222245()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclRollBones@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x826214D0
// RVA : 0x006214D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclRollBones *__fastcall idDeclInfoTemplate<idDeclRollBones>::Alloc(
        idDeclInfoTemplate<idDeclRollBones> *this,
        const char *name)
{
  idDeclRollBones *v3; // r3
  idDeclRollBones *v4; // r30

  v3 = (idDeclRollBones *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x50u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclRollBones::idDeclRollBones(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222268
// EA  : 0x82621540
// RVA : 0x00621540
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222268()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclDragJoints@@@@UBAPAVidDeclDragJoints@@XZ
// EA  : 0x82621578
// RVA : 0x00621578
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDragJoints *__fastcall idDeclInfoTemplate<idDeclDragJoints>::AllocDecl(
        idDeclInfoTemplate<idDeclDragJoints> *this)
{
  idDeclDragJoints *v1; // r3

  v1 = (idDeclDragJoints *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x84u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclDragJoints::idDeclDragJoints(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222295
// EA  : 0x826215E0
// RVA : 0x006215E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222295()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclDragJoints@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82621618
// RVA : 0x00621618
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDragJoints *__fastcall idDeclInfoTemplate<idDeclDragJoints>::Alloc(
        idDeclInfoTemplate<idDeclDragJoints> *this,
        const char *name)
{
  idDeclDragJoints *v3; // r3
  idDeclDragJoints *v4; // r30

  v3 = (idDeclDragJoints *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x84u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclDragJoints::idDeclDragJoints(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222318
// EA  : 0x82621688
// RVA : 0x00621688
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222318()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclFlare@@@@UBAPAVidDeclFlare@@XZ
// EA  : 0x826216C0
// RVA : 0x006216C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclFlare *__fastcall idDeclInfoTemplate<idDeclFlare>::AllocDecl(idDeclInfoTemplate<idDeclFlare> *this)
{
  idDeclFlare *v1; // r3

  v1 = (idDeclFlare *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x60u,
                        tag: TAG_DECL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclFlare::idDeclFlare(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222345
// EA  : 0x82621728
// RVA : 0x00621728
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222345()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclFlare@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82621760
// RVA : 0x00621760
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclFlare *__fastcall idDeclInfoTemplate<idDeclFlare>::Alloc(idDeclInfoTemplate<idDeclFlare> *this, const char *name)
{
  idDeclFlare *v3; // r3
  idDeclFlare *v4; // r30

  v3 = (idDeclFlare *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x60u,
                        tag: TAG_DECL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclFlare::idDeclFlare(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222368
// EA  : 0x826217D0
// RVA : 0x006217D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222368()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVisemeSet@@@@UBAPAVidDeclVisemeSet@@XZ
// EA  : 0x82621808
// RVA : 0x00621808
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVisemeSet *__fastcall idDeclInfoTemplate<idDeclVisemeSet>::AllocDecl(idDeclInfoTemplate<idDeclVisemeSet> *this)
{
  idDeclVisemeSet *v1; // r3

  v1 = (idDeclVisemeSet *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x80u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVisemeSet::idDeclVisemeSet(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222395
// EA  : 0x82621870
// RVA : 0x00621870
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222395()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVisemeSet@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x826218A8
// RVA : 0x006218A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVisemeSet *__fastcall idDeclInfoTemplate<idDeclVisemeSet>::Alloc(
        idDeclInfoTemplate<idDeclVisemeSet> *this,
        const char *name)
{
  idDeclVisemeSet *v3; // r3
  idDeclVisemeSet *v4; // r30

  v3 = (idDeclVisemeSet *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x80u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVisemeSet::idDeclVisemeSet(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222418
// EA  : 0x82621918
// RVA : 0x00621918
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222418()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclVisemeSet@@@@UBAHXZ
// EA  : 0x82621948
// RVA : 0x00621948
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclVisemeSet>::AllocSize(idDeclInfoTemplate<idDeclVisemeSet> *this)
{
  return 128;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVoiceOver@@@@UBAPAVidDeclVoiceOver@@XZ
// EA  : 0x82621958
// RVA : 0x00621958
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVoiceOver *__fastcall idDeclInfoTemplate<idDeclVoiceOver>::AllocDecl(idDeclInfoTemplate<idDeclVoiceOver> *this)
{
  idDeclVoiceOver *v1; // r3

  v1 = (idDeclVoiceOver *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x54u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVoiceOver::idDeclVoiceOver(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222445
// EA  : 0x826219C0
// RVA : 0x006219C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222445()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVoiceOver@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x826219F8
// RVA : 0x006219F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVoiceOver *__fastcall idDeclInfoTemplate<idDeclVoiceOver>::Alloc(
        idDeclInfoTemplate<idDeclVoiceOver> *this,
        const char *name)
{
  idDeclVoiceOver *v3; // r3
  idDeclVoiceOver *v4; // r30

  v3 = (idDeclVoiceOver *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x54u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVoiceOver::idDeclVoiceOver(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222468
// EA  : 0x82621A68
// RVA : 0x00621A68
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222468()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAnimWeb@@@@UBAPAVidDeclAnimWeb@@XZ
// EA  : 0x82621AA0
// RVA : 0x00621AA0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAnimWeb *__fastcall idDeclInfoTemplate<idDeclAnimWeb>::AllocDecl(idDeclInfoTemplate<idDeclAnimWeb> *this)
{
  idDeclAnimWeb *v1; // r3

  v1 = (idDeclAnimWeb *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x114u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAnimWeb::idDeclAnimWeb(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222495
// EA  : 0x82621B08
// RVA : 0x00621B08
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222495()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAnimWeb@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82621B40
// RVA : 0x00621B40
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAnimWeb *__fastcall idDeclInfoTemplate<idDeclAnimWeb>::Alloc(
        idDeclInfoTemplate<idDeclAnimWeb> *this,
        const char *name)
{
  idDeclAnimWeb *v3; // r3
  idDeclAnimWeb *v4; // r30

  v3 = (idDeclAnimWeb *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x114u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAnimWeb::idDeclAnimWeb(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222518
// EA  : 0x82621BB0
// RVA : 0x00621BB0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222518()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclElectricBolt@@@@UBAPAVidDeclElectricBolt@@XZ
// EA  : 0x82621BE8
// RVA : 0x00621BE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclElectricBolt *__fastcall idDeclInfoTemplate<idDeclElectricBolt>::AllocDecl(
        idDeclInfoTemplate<idDeclElectricBolt> *this)
{
  idDeclElectricBolt *v1; // r3

  v1 = (idDeclElectricBolt *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xC4u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclElectricBolt::idDeclElectricBolt(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222545
// EA  : 0x82621C50
// RVA : 0x00621C50
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222545()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclElectricBolt@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82621C88
// RVA : 0x00621C88
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclElectricBolt *__fastcall idDeclInfoTemplate<idDeclElectricBolt>::Alloc(
        idDeclInfoTemplate<idDeclElectricBolt> *this,
        const char *name)
{
  idDeclElectricBolt *v3; // r3
  idDeclElectricBolt *v4; // r30

  v3 = (idDeclElectricBolt *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xC4u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclElectricBolt::idDeclElectricBolt(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222568
// EA  : 0x82621CF8
// RVA : 0x00621CF8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222568()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclGameTime@@@@UBAPAVidDeclGameTime@@XZ
// EA  : 0x82621D30
// RVA : 0x00621D30
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclGameTime *__fastcall idDeclInfoTemplate<idDeclGameTime>::AllocDecl(idDeclInfoTemplate<idDeclGameTime> *this)
{
  idDeclTypeInfo *v1; // r3
  idDeclTypeInfo *v2; // r30

  v1 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x50u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v2 = v1;
  if ( v1 == nullptr )
    return nullptr;
  idDeclTypeInfo::idDeclTypeInfo(this: v1);
  v2->__vftable = (idDeclTypeInfo_vtbl *)&idDeclGameTime::`vftable';
  *(float *)&v2[1].__vftable = 0.0;
  *(float *)&v2[1].trackedMemory = 0.0;
  *(float *)&v2[1].name.str = 0.0;
  *(float *)&v2[1].nextOnHashChain = 1.0;
  return (idDeclGameTime *)v2;
}


// ========================================================================
// __unwind$222597
// EA  : 0x82621DDC
// RVA : 0x00621DDC
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222597()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclGameTime@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82621E10
// RVA : 0x00621E10
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTypeInfo *__fastcall idDeclInfoTemplate<idDeclGameTime>::Alloc(
        idDeclInfoTemplate<idDeclGameTime> *this,
        const char *name)
{
  idDeclTypeInfo *v3; // r3
  idDeclTypeInfo *v4; // r30

  v3 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x50u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idDeclTypeInfo::idDeclTypeInfo(this: v3);
    v4->__vftable = (idDeclTypeInfo_vtbl *)&idDeclGameTime::`vftable';
    *(float *)&v4[1].__vftable = 0.0;
    *(float *)&v4[1].trackedMemory = 0.0;
    *(float *)&v4[1].name.str = 0.0;
    *(float *)&v4[1].nextOnHashChain = 1.0;
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222630
// EA  : 0x82621EB4
// RVA : 0x00621EB4
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222630()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclProductionFilter@@@@UBAPAVidDeclProductionFilter@@XZ
// EA  : 0x82621EE8
// RVA : 0x00621EE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclProductionFilter *__fastcall idDeclInfoTemplate<idDeclProductionFilter>::AllocDecl(
        idDeclInfoTemplate<idDeclProductionFilter> *this)
{
  idDeclProductionFilter *v1; // r3

  v1 = (idDeclProductionFilter *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x60u,
                                   tag: TAG_DECL,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclProductionFilter::idDeclProductionFilter(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222667
// EA  : 0x82621F50
// RVA : 0x00621F50
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222667()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclProductionFilter@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82621F88
// RVA : 0x00621F88
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclProductionFilter *__fastcall idDeclInfoTemplate<idDeclProductionFilter>::Alloc(
        idDeclInfoTemplate<idDeclProductionFilter> *this,
        const char *name)
{
  idDeclProductionFilter *v3; // r3
  idDeclProductionFilter *v4; // r30

  v3 = (idDeclProductionFilter *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x60u,
                                   tag: TAG_DECL,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclProductionFilter::idDeclProductionFilter(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222690
// EA  : 0x82621FF8
// RVA : 0x00621FF8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222690()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclCloth@@@@UBAPAVidDeclCloth@@XZ
// EA  : 0x82622030
// RVA : 0x00622030
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclCloth *__fastcall idDeclInfoTemplate<idDeclCloth>::AllocDecl(idDeclInfoTemplate<idDeclCloth> *this)
{
  idDeclCloth *v1; // r3

  v1 = (idDeclCloth *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0xACu,
                        tag: TAG_DECL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclCloth::idDeclCloth(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222717
// EA  : 0x82622098
// RVA : 0x00622098
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222717()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclCloth@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x826220D0
// RVA : 0x006220D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclCloth *__fastcall idDeclInfoTemplate<idDeclCloth>::Alloc(idDeclInfoTemplate<idDeclCloth> *this, const char *name)
{
  idDeclCloth *v3; // r3
  idDeclCloth *v4; // r30

  v3 = (idDeclCloth *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0xACu,
                        tag: TAG_DECL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclCloth::idDeclCloth(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222740
// EA  : 0x82622140
// RVA : 0x00622140
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222740()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclParticle@@@@UBAPAVidDeclParticle@@XZ
// EA  : 0x82622178
// RVA : 0x00622178
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclParticle *__fastcall idDeclInfoTemplate<idDeclParticle>::AllocDecl(idDeclInfoTemplate<idDeclParticle> *this)
{
  idDeclParticle *v1; // r3

  v1 = (idDeclParticle *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xA8u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclParticle::idDeclParticle(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222767
// EA  : 0x826221E0
// RVA : 0x006221E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222767()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclParticle@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82622218
// RVA : 0x00622218
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclParticle *__fastcall idDeclInfoTemplate<idDeclParticle>::Alloc(
        idDeclInfoTemplate<idDeclParticle> *this,
        const char *name)
{
  idDeclParticle *v3; // r3
  idDeclParticle *v4; // r30

  v3 = (idDeclParticle *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xA8u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclParticle::idDeclParticle(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222790
// EA  : 0x82622288
// RVA : 0x00622288
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222790()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclDetail@@@@UBAPAVidDeclDetail@@XZ
// EA  : 0x826222C0
// RVA : 0x006222C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDetail *__fastcall idDeclInfoTemplate<idDeclDetail>::AllocDecl(idDeclInfoTemplate<idDeclDetail> *this)
{
  idDeclDetail *v1; // r3

  v1 = (idDeclDetail *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x48u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclDetail::idDeclDetail(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222817
// EA  : 0x82622328
// RVA : 0x00622328
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222817()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclDetail@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82622360
// RVA : 0x00622360
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDetail *__fastcall idDeclInfoTemplate<idDeclDetail>::Alloc(
        idDeclInfoTemplate<idDeclDetail> *this,
        const char *name)
{
  idDeclDetail *v3; // r3
  idDeclDetail *v4; // r30

  v3 = (idDeclDetail *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x48u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclDetail::idDeclDetail(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222840
// EA  : 0x826223D0
// RVA : 0x006223D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222840()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclFoliage@@@@UBAPAVidDeclFoliage@@XZ
// EA  : 0x82622408
// RVA : 0x00622408
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclFoliage *__fastcall idDeclInfoTemplate<idDeclFoliage>::AllocDecl(idDeclInfoTemplate<idDeclFoliage> *this)
{
  idDeclFoliage *v1; // r3

  v1 = (idDeclFoliage *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x9Cu,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclFoliage::idDeclFoliage(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222867
// EA  : 0x82622470
// RVA : 0x00622470
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222867()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclFoliage@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x826224A8
// RVA : 0x006224A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclFoliage *__fastcall idDeclInfoTemplate<idDeclFoliage>::Alloc(
        idDeclInfoTemplate<idDeclFoliage> *this,
        const char *name)
{
  idDeclFoliage *v3; // r3
  idDeclFoliage *v4; // r30

  v3 = (idDeclFoliage *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x9Cu,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclFoliage::idDeclFoliage(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222890
// EA  : 0x82622518
// RVA : 0x00622518
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222890()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclRenderProg@@@@UBAPAVidDeclRenderProg@@XZ
// EA  : 0x82622550
// RVA : 0x00622550
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclRenderProg *__fastcall idDeclInfoTemplate<idDeclRenderProg>::AllocDecl(
        idDeclInfoTemplate<idDeclRenderProg> *this)
{
  idDeclRenderProg *v1; // r3

  v1 = (idDeclRenderProg *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x288u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclRenderProg::idDeclRenderProg(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222917
// EA  : 0x826225B8
// RVA : 0x006225B8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222917()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclRenderProg@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x826225F0
// RVA : 0x006225F0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclRenderProg *__fastcall idDeclInfoTemplate<idDeclRenderProg>::Alloc(
        idDeclInfoTemplate<idDeclRenderProg> *this,
        const char *name)
{
  idDeclRenderProg *v3; // r3
  idDeclRenderProg *v4; // r30

  v3 = (idDeclRenderProg *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x288u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclRenderProg::idDeclRenderProg(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222940
// EA  : 0x82622660
// RVA : 0x00622660
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222940()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclRenderProg@@@@UBAHXZ
// EA  : 0x82622690
// RVA : 0x00622690
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclRenderProg>::AllocSize(idDeclInfoTemplate<idDeclRenderProg> *this)
{
  return 648;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidMaterial@@@@UBAPAVidMaterial@@XZ
// EA  : 0x826226A0
// RVA : 0x006226A0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idMaterial *__fastcall idDeclInfoTemplate<idMaterial>::AllocDecl(idDeclInfoTemplate<idMaterial> *this)
{
  idMaterial *v1; // r3

  v1 = (idMaterial *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x110u,
                       tag: TAG_DECL,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idMaterial::idMaterial(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$222967
// EA  : 0x82622708
// RVA : 0x00622708
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222967()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidMaterial@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82622740
// RVA : 0x00622740
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idMaterial *__fastcall idDeclInfoTemplate<idMaterial>::Alloc(idDeclInfoTemplate<idMaterial> *this, const char *name)
{
  idMaterial *v3; // r3
  idMaterial *v4; // r30

  v3 = (idMaterial *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x110u,
                       tag: TAG_DECL,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idMaterial::idMaterial(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222990
// EA  : 0x826227B0
// RVA : 0x006227B0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_222990()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Size@idDeclAF@@UBAIXZ
// EA  : 0x826227E0
// RVA : 0x006227E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

unsigned int __fastcall idDeclAF::Size(idDeclAF *this)
{
  return 272;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclEnv@@@@UBAPAVidDeclEnv@@XZ
// EA  : 0x826227F0
// RVA : 0x006227F0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclEnv *__fastcall idDeclInfoTemplate<idDeclEnv>::AllocDecl(idDeclInfoTemplate<idDeclEnv> *this)
{
  idDeclEnv *v1; // r3

  v1 = (idDeclEnv *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x68u,
                      tag: TAG_DECL,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclEnv::idDeclEnv(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$223017
// EA  : 0x82622858
// RVA : 0x00622858
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_223017()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclEnv@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82622890
// RVA : 0x00622890
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclEnv *__fastcall idDeclInfoTemplate<idDeclEnv>::Alloc(idDeclInfoTemplate<idDeclEnv> *this, const char *name)
{
  idDeclEnv *v3; // r3
  idDeclEnv *v4; // r30

  v3 = (idDeclEnv *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x68u,
                      tag: TAG_DECL,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclEnv::idDeclEnv(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$223040
// EA  : 0x82622900
// RVA : 0x00622900
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_223040()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclVehicleProps@@@@UBAHXZ
// EA  : 0x82622930
// RVA : 0x00622930
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclVehicleProps>::AllocSize(idDeclInfoTemplate<idDeclVehicleProps> *this)
{
  return 1480;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclDestructiblePieceInfo@@@@UBAPAVidDeclDestructiblePieceInfo@@XZ
// EA  : 0x82622E50
// RVA : 0x00622E50
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDestructiblePieceInfo *__fastcall idDeclInfoTemplate<idDeclDestructiblePieceInfo>::AllocDecl(
        idDeclInfoTemplate<idDeclDestructiblePieceInfo> *this)
{
  idDeclDestructiblePieceInfo *v1; // r3

  v1 = (idDeclDestructiblePieceInfo *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0x50u,
                                        tag: TAG_DECL,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclDestructiblePieceInfo::idDeclDestructiblePieceInfo(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$223907
// EA  : 0x82622EB8
// RVA : 0x00622EB8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_223907()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclDestructiblePieceInfo@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82622EF0
// RVA : 0x00622EF0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDestructiblePieceInfo *__fastcall idDeclInfoTemplate<idDeclDestructiblePieceInfo>::Alloc(
        idDeclInfoTemplate<idDeclDestructiblePieceInfo> *this,
        const char *name)
{
  idDeclDestructiblePieceInfo *v3; // r3
  idDeclDestructiblePieceInfo *v4; // r30

  v3 = (idDeclDestructiblePieceInfo *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0x50u,
                                        tag: TAG_DECL,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclDestructiblePieceInfo::idDeclDestructiblePieceInfo(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$223930
// EA  : 0x82622F60
// RVA : 0x00622F60
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_223930()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclPonytail@@@@UBAPAVidDeclPonytail@@XZ
// EA  : 0x826231D8
// RVA : 0x006231D8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclPonytail *__fastcall idDeclInfoTemplate<idDeclPonytail>::AllocDecl(idDeclInfoTemplate<idDeclPonytail> *this)
{
  idDeclPonytail *v1; // r3

  v1 = (idDeclPonytail *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x68u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclPonytail::idDeclPonytail(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$224186
// EA  : 0x82623240
// RVA : 0x00623240
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_224186()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclPonytail@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82623278
// RVA : 0x00623278
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclPonytail *__fastcall idDeclInfoTemplate<idDeclPonytail>::Alloc(
        idDeclInfoTemplate<idDeclPonytail> *this,
        const char *name)
{
  idDeclPonytail *v3; // r3
  idDeclPonytail *v4; // r30

  v3 = (idDeclPonytail *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x68u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclPonytail::idDeclPonytail(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$224209
// EA  : 0x826232E8
// RVA : 0x006232E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_224209()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleProps@@@@UBAPAVidDeclVehicleProps@@XZ
// EA  : 0x82623A60
// RVA : 0x00623A60
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleProps *__fastcall idDeclInfoTemplate<idDeclVehicleProps>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleProps> *this)
{
  idDeclVehicleProps *v1; // r3

  v1 = (idDeclVehicleProps *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x5C8u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleProps::idDeclVehicleProps(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$224793
// EA  : 0x82623AC8
// RVA : 0x00623AC8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_224793()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleProps@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82623B00
// RVA : 0x00623B00
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleProps *__fastcall idDeclInfoTemplate<idDeclVehicleProps>::Alloc(
        idDeclInfoTemplate<idDeclVehicleProps> *this,
        const char *name)
{
  idDeclVehicleProps *v3; // r3
  idDeclVehicleProps *v4; // r30

  v3 = (idDeclVehicleProps *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x5C8u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleProps::idDeclVehicleProps(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$224816
// EA  : 0x82623B70
// RVA : 0x00623B70
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_224816()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclSkins@@@@UBAPAVidDeclSkins@@XZ
// EA  : 0x82623CE8
// RVA : 0x00623CE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSkins *__fastcall idDeclInfoTemplate<idDeclSkins>::AllocDecl(idDeclInfoTemplate<idDeclSkins> *this)
{
  idDeclSkins *v1; // r3

  v1 = (idDeclSkins *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x48u,
                        tag: TAG_DECL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclSkins::idDeclSkins(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$224929
// EA  : 0x82623D50
// RVA : 0x00623D50
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_224929()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclSkins@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82623D88
// RVA : 0x00623D88
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSkins *__fastcall idDeclInfoTemplate<idDeclSkins>::Alloc(idDeclInfoTemplate<idDeclSkins> *this, const char *name)
{
  idDeclSkins *v3; // r3
  idDeclSkins *v4; // r30

  v3 = (idDeclSkins *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x48u,
                        tag: TAG_DECL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclSkins::idDeclSkins(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDecl, _name: name);
  return v4;
}


// ========================================================================
// __unwind$224952
// EA  : 0x82623DF8
// RVA : 0x00623DF8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_224952()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ??0idDeclSource@@QAA@_N@Z
// EA  : 0x82624638
// RVA : 0x00624638
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSource *__fastcall idDeclSource::idDeclSource(idDeclSource *this, bool _isStatic)
{
  this->name.str = &byte_8200D768;
  idAtomicString::Set(this: &this->name, str_: "emptyDeclSource");
  this->isStatic = _isStatic;
  this->sourceFile = nullptr;
  this->nextInFile = nullptr;
  this->sourceTextOffset = 0;
  this->sourceTextLength = 0;
  this->sourceLine = 0;
  return this;
}


// ========================================================================
// ??1idDeclManager@@UAA@XZ
// EA  : 0x826246A8
// RVA : 0x006246A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::~idDeclManager(idDeclManager *this)
{
  this->__vftable = (idDeclManager_vtbl *)&idDeclManager::`vftable';
}


// ========================================================================
// ?ArgCompletion_DeclTypeAndName@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82624710
// RVA : 0x00624710
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_DeclTypeAndName(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclTypeName(this: declManager, a2: autoComplete);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclGameTime@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82646D48
// RVA : 0x00646D48
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclGameTime>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclGameTime::resourceList);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclMD6@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x8280D1D0
// RVA : 0x0080D1D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclMD6>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclMD6::resourceList);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidMaterial@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x8294B608
// RVA : 0x0094B608
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idMaterial>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idMaterial::resourceList);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclEnv@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x8294B630
// RVA : 0x0094B630
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclEnv>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclEnv::resourceList);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclRenderProg@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x8294B658
// RVA : 0x0094B658
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclRenderProg>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclRenderProg::resourceList);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclRenderParm@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x8294B680
// RVA : 0x0094B680
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclRenderParm>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclRenderParm::resourceList);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidSoundShader@@@@UBAHXZ
// EA  : 0x8298FF58
// RVA : 0x0098FF58
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idSoundShader>::AllocSize(idDeclInfoTemplate<idDeclAnimWeb> *this)
{
  return 276;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclDuck@@@@UBAPAVidDeclDuck@@XZ
// EA  : 0x8298FF68
// RVA : 0x0098FF68
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDuck *__fastcall idDeclInfoTemplate<idDeclDuck>::AllocDecl(idDeclInfoTemplate<idDeclDuck> *this)
{
  idDecl *v1; // r3
  _DWORD *v2; // r30
  _DWORD *v3; // r11
  int i; // ctr

  v1 = (idDecl *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                   size: 0xA0u,
                   tag: TAG_DECL,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v2 = &v1->__vftable;
  if ( v1 == nullptr )
    return nullptr;
  idDecl::idDecl(this: v1);
  *v2 = &idDeclDuck::`vftable';
  v2[14] = 0;
  v3 = v2 + 14;
  for ( i = 25; i != 0; --i )
    *++v3 = 0;
  return (idDeclDuck *)v2;
}


// ========================================================================
// __unwind$224796
// EA  : 0x8299000C
// RVA : 0x0099000C
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_224796()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclDuck@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82990040
// RVA : 0x00990040
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idResource *__fastcall idDeclInfoTemplate<idDeclDuck>::Alloc(idDeclInfoTemplate<idDeclDuck> *this, const char *name)
{
  idDecl *v3; // r3
  idResource *v4; // r30
  const char **p_resourceError; // r11
  int i; // ctr

  v3 = (idDecl *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                   size: 0xA0u,
                   tag: TAG_DECL,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idDecl::idDecl(this: v3);
    v4->__vftable = (idResource_vtbl *)&idDeclDuck::`vftable';
    v4[1].resourceError = nullptr;
    p_resourceError = &v4[1].resourceError;
    for ( i = 25; i != 0; --i )
      *++p_resourceError = nullptr;
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$224831_0
// EA  : 0x829900DC
// RVA : 0x009900DC
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_224831_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidSoundShader@@@@UBAPAVidSoundShader@@XZ
// EA  : 0x82991008
// RVA : 0x00991008
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idSoundShader *__fastcall idDeclInfoTemplate<idSoundShader>::AllocDecl(idDeclInfoTemplate<idSoundShader> *this)
{
  idSoundShader *v1; // r3

  v1 = (idSoundShader *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x114u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idSoundShader::idSoundShader(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$225847
// EA  : 0x82991070
// RVA : 0x00991070
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_225847()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidSoundShader@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x829910A8
// RVA : 0x009910A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idSoundShader *__fastcall idDeclInfoTemplate<idSoundShader>::Alloc(
        idDeclInfoTemplate<idSoundShader> *this,
        const char *name)
{
  idSoundShader *v3; // r3
  idSoundShader *v4; // r30

  v3 = (idSoundShader *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x114u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idSoundShader::idSoundShader(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$225870
// EA  : 0x82991118
// RVA : 0x00991118
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_225870()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidSoundShader@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82991550
// RVA : 0x00991550
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idSoundShader>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idSoundShader::resourceList);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclDuck@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82994000
// RVA : 0x00994000
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclDuck>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclDuck::resourceList);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclMapInfo@@@@UBAPAVidDeclMapInfo@@XZ
// EA  : 0x82BCCAB0
// RVA : 0x00BCCAB0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclMapInfo *__fastcall idDeclInfoTemplate<idDeclMapInfo>::AllocDecl(idDeclInfoTemplate<idDeclMapInfo> *this)
{
  idDeclMapInfo *v1; // r3

  v1 = (idDeclMapInfo *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x5Cu,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclMapInfo::idDeclMapInfo(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$494533
// EA  : 0x82BCCB18
// RVA : 0x00BCCB18
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494533()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclMapInfo@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCCB50
// RVA : 0x00BCCB50
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclMapInfo *__fastcall idDeclInfoTemplate<idDeclMapInfo>::Alloc(
        idDeclInfoTemplate<idDeclMapInfo> *this,
        const char *name)
{
  idDeclMapInfo *v3; // r3
  idDeclMapInfo *v4; // r30

  v3 = (idDeclMapInfo *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x5Cu,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclMapInfo::idDeclMapInfo(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$494556
// EA  : 0x82BCCBC0
// RVA : 0x00BCCBC0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494556()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclFX@@@@UBAHXZ
// EA  : 0x82BCCBF0
// RVA : 0x00BCCBF0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclFX>::AllocSize(idDeclInfoTemplate<idDeclFX> *this)
{
  return 92;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclStaticImage@@@@UBAPAVidDeclStaticImage@@XZ
// EA  : 0x82BCCC00
// RVA : 0x00BCCC00
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclStaticImage *__fastcall idDeclInfoTemplate<idDeclStaticImage>::AllocDecl(
        idDeclInfoTemplate<idDeclStaticImage> *this)
{
  idDeclStaticImage *v1; // r3

  v1 = (idDeclStaticImage *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x44u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclStaticImage::idDeclStaticImage(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$494585
// EA  : 0x82BCCC68
// RVA : 0x00BCCC68
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494585()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclStaticImage@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCCCA0
// RVA : 0x00BCCCA0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclStaticImage *__fastcall idDeclInfoTemplate<idDeclStaticImage>::Alloc(
        idDeclInfoTemplate<idDeclStaticImage> *this,
        const char *name)
{
  idDeclStaticImage *v3; // r3
  idDeclStaticImage *v4; // r30

  v3 = (idDeclStaticImage *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x44u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclStaticImage::idDeclStaticImage(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$494608
// EA  : 0x82BCCD10
// RVA : 0x00BCCD10
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494608()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclTable@@@@UBAHXZ
// EA  : 0x82BCCD40
// RVA : 0x00BCCD40
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclTable>::AllocSize(idDeclInfoTemplate<idDeclTable> *this)
{
  return 68;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclImpactSound@@@@UBAPAVidDeclImpactSound@@XZ
// EA  : 0x82BCCD50
// RVA : 0x00BCCD50
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclImpactSound *__fastcall idDeclInfoTemplate<idDeclImpactSound>::AllocDecl(
        idDeclInfoTemplate<idDeclImpactSound> *this)
{
  idDeclImpactSound *v1; // r3

  v1 = (idDeclImpactSound *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0xC4u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclImpactSound::idDeclImpactSound(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$494635
// EA  : 0x82BCCDB8
// RVA : 0x00BCCDB8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494635()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclImpactSound@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCCDF0
// RVA : 0x00BCCDF0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclImpactSound *__fastcall idDeclInfoTemplate<idDeclImpactSound>::Alloc(
        idDeclInfoTemplate<idDeclImpactSound> *this,
        const char *name)
{
  idDeclImpactSound *v3; // r3
  idDeclImpactSound *v4; // r30

  v3 = (idDeclImpactSound *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0xC4u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclImpactSound::idDeclImpactSound(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$494658
// EA  : 0x82BCCE60
// RVA : 0x00BCCE60
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494658()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclGameMode@@@@UBAHXZ
// EA  : 0x82BCCE90
// RVA : 0x00BCCE90
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclGameMode>::AllocSize(idDeclInfoTemplate<idDeclElectricBolt> *this)
{
  return 196;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclImpactParticle@@@@UBAPAVidDeclImpactParticle@@XZ
// EA  : 0x82BCCEA0
// RVA : 0x00BCCEA0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclImpactParticle *__fastcall idDeclInfoTemplate<idDeclImpactParticle>::AllocDecl(
        idDeclInfoTemplate<idDeclImpactParticle> *this)
{
  idDeclImpactParticle *v1; // r3

  v1 = (idDeclImpactParticle *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xA8u,
                                 tag: TAG_DECL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclImpactParticle::idDeclImpactParticle(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$494685
// EA  : 0x82BCCF08
// RVA : 0x00BCCF08
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494685()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclImpactParticle@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCCF40
// RVA : 0x00BCCF40
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclImpactParticle *__fastcall idDeclInfoTemplate<idDeclImpactParticle>::Alloc(
        idDeclInfoTemplate<idDeclImpactParticle> *this,
        const char *name)
{
  idDeclImpactParticle *v3; // r3
  idDeclImpactParticle *v4; // r30

  v3 = (idDeclImpactParticle *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xA8u,
                                 tag: TAG_DECL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclImpactParticle::idDeclImpactParticle(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$494708
// EA  : 0x82BCCFB0
// RVA : 0x00BCCFB0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494708()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclParticle@@@@UBAHXZ
// EA  : 0x82BCCFE0
// RVA : 0x00BCCFE0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclParticle>::AllocSize(idDeclInfoTemplate<idDeclParticle> *this)
{
  return 168;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclLayer@@@@UBAPAVidDeclLayer@@XZ
// EA  : 0x82BCCFF0
// RVA : 0x00BCCFF0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclLayer *__fastcall idDeclInfoTemplate<idDeclLayer>::AllocDecl(idDeclInfoTemplate<idDeclLayer> *this)
{
  idDeclTypeInfo *v1; // r3
  _DWORD *v2; // r30

  v1 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x40u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v2 = &v1->__vftable;
  if ( v1 == nullptr )
    return nullptr;
  idDeclTypeInfo::idDeclTypeInfo(this: v1);
  *v2 = &idDeclLayer::`vftable';
  return (idDeclLayer *)v2;
}


// ========================================================================
// __unwind$494735
// EA  : 0x82BCD074
// RVA : 0x00BCD074
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494735()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclLayer@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCD0A8
// RVA : 0x00BCD0A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idResource *__fastcall idDeclInfoTemplate<idDeclLayer>::Alloc(idDeclInfoTemplate<idDeclLayer> *this, const char *name)
{
  idDeclTypeInfo *v3; // r3
  idResource *v4; // r30

  v3 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x40u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idDeclTypeInfo::idDeclTypeInfo(this: v3);
    v4->__vftable = (idResource_vtbl *)&idDeclLayer::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$494762
// EA  : 0x82BCD124
// RVA : 0x00BCD124
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494762()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclLayer@@@@UBAHXZ
// EA  : 0x82BCD150
// RVA : 0x00BCD150
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclLayer>::AllocSize(idDeclInfoTemplate<idDeclTypeInfo> *this)
{
  return 64;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclNavigation@@@@UBAPAVidDeclNavigation@@XZ
// EA  : 0x82BCD160
// RVA : 0x00BCD160
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclNavigation *__fastcall idDeclInfoTemplate<idDeclNavigation>::AllocDecl(
        idDeclInfoTemplate<idDeclNavigation> *this)
{
  idDeclNavigation *v1; // r3

  v1 = (idDeclNavigation *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xD0u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclNavigation::idDeclNavigation(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$494793
// EA  : 0x82BCD1C8
// RVA : 0x00BCD1C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494793()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclNavigation@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCD200
// RVA : 0x00BCD200
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclNavigation *__fastcall idDeclInfoTemplate<idDeclNavigation>::Alloc(
        idDeclInfoTemplate<idDeclNavigation> *this,
        const char *name)
{
  idDeclNavigation *v3; // r3
  idDeclNavigation *v4; // r30

  v3 = (idDeclNavigation *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xD0u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclNavigation::idDeclNavigation(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$494816
// EA  : 0x82BCD270
// RVA : 0x00BCD270
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494816()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclNavigation@@@@UBAHXZ
// EA  : 0x82BCD2A0
// RVA : 0x00BCD2A0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclNavigation>::AllocSize(idDeclInfoTemplate<idDeclRibbon> *this)
{
  return 208;
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclAITurnParms@@@@UBAHXZ
// EA  : 0x82BCD2A8
// RVA : 0x00BCD2A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclAITurnParms>::AllocSize(idTypedResourceList<idCollisionModelLocal> *this)
{
  return 116;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclGameStateInt@@@@UBAPAVidDeclGameStateInt@@XZ
// EA  : 0x82BCD2B8
// RVA : 0x00BCD2B8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclGameStateInt *__fastcall idDeclInfoTemplate<idDeclGameStateInt>::AllocDecl(
        idDeclInfoTemplate<idDeclGameStateInt> *this)
{
  idDeclTypeInfo *v1; // r3
  _DWORD *v2; // r30

  v1 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x40u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v2 = &v1->__vftable;
  if ( v1 == nullptr )
    return nullptr;
  idDeclTypeInfo::idDeclTypeInfo(this: v1);
  *v2 = &idDeclGameStateInt::`vftable';
  return (idDeclGameStateInt *)v2;
}


// ========================================================================
// __unwind$494845
// EA  : 0x82BCD33C
// RVA : 0x00BCD33C
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494845()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclGameStateInt@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCD370
// RVA : 0x00BCD370
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idResource *__fastcall idDeclInfoTemplate<idDeclGameStateInt>::Alloc(
        idDeclInfoTemplate<idDeclGameStateInt> *this,
        const char *name)
{
  idDeclTypeInfo *v3; // r3
  idResource *v4; // r30

  v3 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x40u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idDeclTypeInfo::idDeclTypeInfo(this: v3);
    v4->__vftable = (idResource_vtbl *)&idDeclGameStateInt::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$494872
// EA  : 0x82BCD3EC
// RVA : 0x00BCD3EC
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494872()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclEnv@@@@UBAHXZ
// EA  : 0x82BCD418
// RVA : 0x00BCD418
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclEnv>::AllocSize(idDeclInfoTemplate<idDeclEnv> *this)
{
  return 104;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclJobNote@@@@UBAPAVidDeclJobNote@@XZ
// EA  : 0x82BCD428
// RVA : 0x00BCD428
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclJobNote *__fastcall idDeclInfoTemplate<idDeclJobNote>::AllocDecl(idDeclInfoTemplate<idDeclJobNote> *this)
{
  idDeclJobNote *v1; // r3

  v1 = (idDeclJobNote *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x88u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclJobNote::idDeclJobNote(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$494907
// EA  : 0x82BCD490
// RVA : 0x00BCD490
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494907()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclJobNote@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCD4C8
// RVA : 0x00BCD4C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclJobNote *__fastcall idDeclInfoTemplate<idDeclJobNote>::Alloc(
        idDeclInfoTemplate<idDeclJobNote> *this,
        const char *name)
{
  idDeclJobNote *v3; // r3
  idDeclJobNote *v4; // r30

  v3 = (idDeclJobNote *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x88u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclJobNote::idDeclJobNote(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$494930
// EA  : 0x82BCD538
// RVA : 0x00BCD538
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494930()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclJobNote@@@@UBAHXZ
// EA  : 0x82BCD568
// RVA : 0x00BCD568
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclJobNote>::AllocSize(idDeclInfoTemplate<idDeclChapter> *this)
{
  return 136;
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclSpecialEvent@@@@UBAHXZ
// EA  : 0x82BCD570
// RVA : 0x00BCD570
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclSpecialEvent>::AllocSize(idDeclInfoTemplate<idDeclDuck> *this)
{
  return 160;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclJobTimerEvent@@@@UBAPAVidDeclJobTimerEvent@@XZ
// EA  : 0x82BCD580
// RVA : 0x00BCD580
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclJobTimerEvent *__fastcall idDeclInfoTemplate<idDeclJobTimerEvent>::AllocDecl(
        idDeclInfoTemplate<idDeclJobTimerEvent> *this)
{
  idDeclJobTimerEvent *v1; // r3

  v1 = (idDeclJobTimerEvent *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x8Cu,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclJobTimerEvent::idDeclJobTimerEvent(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$494961
// EA  : 0x82BCD5E8
// RVA : 0x00BCD5E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494961()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclJobTimerEvent@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCD620
// RVA : 0x00BCD620
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclJobTimerEvent *__fastcall idDeclInfoTemplate<idDeclJobTimerEvent>::Alloc(
        idDeclInfoTemplate<idDeclJobTimerEvent> *this,
        const char *name)
{
  idDeclJobTimerEvent *v3; // r3
  idDeclJobTimerEvent *v4; // r30

  v3 = (idDeclJobTimerEvent *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x8Cu,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclJobTimerEvent::idDeclJobTimerEvent(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$494984
// EA  : 0x82BCD690
// RVA : 0x00BCD690
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_494984()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclJobTimerEvent@@@@UBAHXZ
// EA  : 0x82BCD6C0
// RVA : 0x00BCD6C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclJobTimerEvent>::AllocSize(
        idTypedResourceList<idDiscreteAnimationModelData> *this)
{
  return 140;
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidSoundSample@@@@UBAHXZ
// EA  : 0x82BCD6C8
// RVA : 0x00BCD6C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idTypedResourceList<idSoundSample>::AllocSize(idTypedResourceList<idSoundSample> *this)
{
  return 152;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclJob@@@@UBAPAVidDeclJob@@XZ
// EA  : 0x82BCD6D8
// RVA : 0x00BCD6D8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclJob *__fastcall idDeclInfoTemplate<idDeclJob>::AllocDecl(idDeclInfoTemplate<idDeclJob> *this)
{
  idDeclJob *v1; // r3

  v1 = (idDeclJob *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x460u,
                      tag: TAG_DECL,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclJob::idDeclJob(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495013_0
// EA  : 0x82BCD740
// RVA : 0x00BCD740
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495013_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclJob@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCD778
// RVA : 0x00BCD778
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclJob *__fastcall idDeclInfoTemplate<idDeclJob>::Alloc(idDeclInfoTemplate<idDeclJob> *this, const char *name)
{
  idDeclJob *v3; // r3
  idDeclJob *v4; // r30

  v3 = (idDeclJob *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x460u,
                      tag: TAG_DECL,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclJob::idDeclJob(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495036
// EA  : 0x82BCD7E8
// RVA : 0x00BCD7E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495036()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclJob@@@@UBAHXZ
// EA  : 0x82BCD818
// RVA : 0x00BCD818
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclJob>::AllocSize(idDeclInfoTemplate<idDeclJob> *this)
{
  return 1120;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclCameraTrigger@@@@UBAPAVidDeclCameraTrigger@@XZ
// EA  : 0x82BCD828
// RVA : 0x00BCD828
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclCameraTrigger *__fastcall idDeclInfoTemplate<idDeclCameraTrigger>::AllocDecl(
        idDeclInfoTemplate<idDeclCameraTrigger> *this)
{
  idDeclCameraTrigger *v1; // r3

  v1 = (idDeclCameraTrigger *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x50u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclCameraTrigger::idDeclCameraTrigger(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495063
// EA  : 0x82BCD890
// RVA : 0x00BCD890
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495063()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclCameraTrigger@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCD8C8
// RVA : 0x00BCD8C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclCameraTrigger *__fastcall idDeclInfoTemplate<idDeclCameraTrigger>::Alloc(
        idDeclInfoTemplate<idDeclCameraTrigger> *this,
        const char *name)
{
  idDeclCameraTrigger *v3; // r3
  idDeclCameraTrigger *v4; // r30

  v3 = (idDeclCameraTrigger *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x50u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclCameraTrigger::idDeclCameraTrigger(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495086
// EA  : 0x82BCD938
// RVA : 0x00BCD938
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495086()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclHandsBobCycle@@@@UBAHXZ
// EA  : 0x82BCD968
// RVA : 0x00BCD968
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclHandsBobCycle>::AllocSize(idDeclInfoTemplate<idDeclHandsBobCycle> *this)
{
  return 696;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAimAssist@@@@UBAPAVidDeclAimAssist@@XZ
// EA  : 0x82BCD978
// RVA : 0x00BCD978
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAimAssist *__fastcall idDeclInfoTemplate<idDeclAimAssist>::AllocDecl(idDeclInfoTemplate<idDeclAimAssist> *this)
{
  idDeclTypeInfo *v1; // r3
  idDeclTypeInfo *v2; // r30

  v1 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xB4u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v2 = v1;
  if ( v1 == nullptr )
    return nullptr;
  idDeclTypeInfo::idDeclTypeInfo(this: v1);
  v2->__vftable = (idDeclTypeInfo_vtbl *)&idDeclAimAssist::`vftable';
  aimAssistData_t::aimAssistData_t(this: (aimAssistData_t *)&v2[1]);
  return (idDeclAimAssist *)v2;
}


// ========================================================================
// __unwind$495115
// EA  : 0x82BCDA04
// RVA : 0x00BCDA04
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495115()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAimAssist@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCDA38
// RVA : 0x00BCDA38
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTypeInfo *__fastcall idDeclInfoTemplate<idDeclAimAssist>::Alloc(
        idDeclInfoTemplate<idDeclAimAssist> *this,
        const char *name)
{
  idDeclTypeInfo *v3; // r3
  idDeclTypeInfo *v4; // r30

  v3 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xB4u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idDeclTypeInfo::idDeclTypeInfo(this: v3);
    v4->__vftable = (idDeclTypeInfo_vtbl *)&idDeclAimAssist::`vftable';
    aimAssistData_t::aimAssistData_t(this: (aimAssistData_t *)&v4[1]);
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495142
// EA  : 0x82BCDABC
// RVA : 0x00BCDABC
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495142()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclAimAssist@@@@UBAHXZ
// EA  : 0x82BCDAE8
// RVA : 0x00BCDAE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclAimAssist>::AllocSize(idDeclInfoTemplate<idDeclAimAssist> *this)
{
  return 180;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclInventory@@@@UBAPAVidDeclInventory@@XZ
// EA  : 0x82BCDAF8
// RVA : 0x00BCDAF8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclInventory *__fastcall idDeclInfoTemplate<idDeclInventory>::AllocDecl(idDeclInfoTemplate<idDeclInventory> *this)
{
  idDeclInventory *v1; // r3

  v1 = (idDeclInventory *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x1F8u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclInventory::idDeclInventory(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495173
// EA  : 0x82BCDB60
// RVA : 0x00BCDB60
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495173()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclInventory@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCDB98
// RVA : 0x00BCDB98
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclInventory *__fastcall idDeclInfoTemplate<idDeclInventory>::Alloc(
        idDeclInfoTemplate<idDeclInventory> *this,
        const char *name)
{
  idDeclInventory *v3; // r3
  idDeclInventory *v4; // r30

  v3 = (idDeclInventory *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x1F8u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclInventory::idDeclInventory(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495196
// EA  : 0x82BCDC08
// RVA : 0x00BCDC08
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495196()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclAuthorityBoostItemUpgrade@@@@UBAHXZ
// EA  : 0x82BCDC38
// RVA : 0x00BCDC38
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclAuthorityBoostItemUpgrade>::AllocSize(
        idDeclInfoTemplate<idDeclAuthorityBoostItemUpgrade> *this)
{
  return 504;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAmmo@@@@UBAPAVidDeclAmmo@@XZ
// EA  : 0x82BCDC48
// RVA : 0x00BCDC48
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAmmo *__fastcall idDeclInfoTemplate<idDeclAmmo>::AllocDecl(idDeclInfoTemplate<idDeclAmmo> *this)
{
  idDeclAmmo *v1; // r3

  v1 = (idDeclAmmo *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x348u,
                       tag: TAG_DECL,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAmmo::idDeclAmmo(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495223
// EA  : 0x82BCDCB0
// RVA : 0x00BCDCB0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495223()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAmmo@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCDCE8
// RVA : 0x00BCDCE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAmmo *__fastcall idDeclInfoTemplate<idDeclAmmo>::Alloc(idDeclInfoTemplate<idDeclAmmo> *this, const char *name)
{
  idDeclAmmo *v3; // r3
  idDeclAmmo *v4; // r30

  v3 = (idDeclAmmo *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x348u,
                       tag: TAG_DECL,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAmmo::idDeclAmmo(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclInventory, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495246
// EA  : 0x82BCDD58
// RVA : 0x00BCDD58
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495246()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclAmmo@@@@UBAHXZ
// EA  : 0x82BCDD88
// RVA : 0x00BCDD88
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclAmmo>::AllocSize(idDeclInfoTemplate<idDeclAmmo> *this)
{
  return 840;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclHealthItem@@@@UBAPAVidDeclHealthItem@@XZ
// EA  : 0x82BCDD98
// RVA : 0x00BCDD98
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclHealthItem *__fastcall idDeclInfoTemplate<idDeclHealthItem>::AllocDecl(
        idDeclInfoTemplate<idDeclHealthItem> *this)
{
  idDeclHealthItem *v1; // r3

  v1 = (idDeclHealthItem *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x200u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclHealthItem::idDeclHealthItem(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495273
// EA  : 0x82BCDE00
// RVA : 0x00BCDE00
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495273()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclHealthItem@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCDE38
// RVA : 0x00BCDE38
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclHealthItem *__fastcall idDeclInfoTemplate<idDeclHealthItem>::Alloc(
        idDeclInfoTemplate<idDeclHealthItem> *this,
        const char *name)
{
  idDeclHealthItem *v3; // r3
  idDeclHealthItem *v4; // r30

  v3 = (idDeclHealthItem *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x200u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclHealthItem::idDeclHealthItem(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495296
// EA  : 0x82BCDEA8
// RVA : 0x00BCDEA8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495296()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclHealthItem@@@@UBAHXZ
// EA  : 0x82BCDED8
// RVA : 0x00BCDED8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclHealthItem>::AllocSize(idDeclInfoTemplate<idDeclVehicleArmor> *this)
{
  return 512;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclSecretItem@@@@UBAPAVidDeclSecretItem@@XZ
// EA  : 0x82BCDEE8
// RVA : 0x00BCDEE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSecretItem *__fastcall idDeclInfoTemplate<idDeclSecretItem>::AllocDecl(
        idDeclInfoTemplate<idDeclSecretItem> *this)
{
  idDeclSecretItem *v1; // r3

  v1 = (idDeclSecretItem *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x1FCu,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclSecretItem::idDeclSecretItem(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495323
// EA  : 0x82BCDF50
// RVA : 0x00BCDF50
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495323()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclSecretItem@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCDF88
// RVA : 0x00BCDF88
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSecretItem *__fastcall idDeclInfoTemplate<idDeclSecretItem>::Alloc(
        idDeclInfoTemplate<idDeclSecretItem> *this,
        const char *name)
{
  idDeclSecretItem *v3; // r3
  idDeclSecretItem *v4; // r30

  v3 = (idDeclSecretItem *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x1FCu,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclSecretItem::idDeclSecretItem(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495346
// EA  : 0x82BCDFF8
// RVA : 0x00BCDFF8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495346()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclSecretItem@@@@UBAHXZ
// EA  : 0x82BCE028
// RVA : 0x00BCE028
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclSecretItem>::AllocSize(idDeclInfoTemplate<idDeclSecretItem> *this)
{
  return 508;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclDamageBoostItem@@@@UBAPAVidDeclDamageBoostItem@@XZ
// EA  : 0x82BCE038
// RVA : 0x00BCE038
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDamageBoostItem *__fastcall idDeclInfoTemplate<idDeclDamageBoostItem>::AllocDecl(
        idDeclInfoTemplate<idDeclDamageBoostItem> *this)
{
  idDeclDamageBoostItem *v1; // r3

  v1 = (idDeclDamageBoostItem *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x200u,
                                  tag: TAG_DECL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclDamageBoostItem::idDeclDamageBoostItem(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495373
// EA  : 0x82BCE0A0
// RVA : 0x00BCE0A0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495373()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclDamageBoostItem@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCE0D8
// RVA : 0x00BCE0D8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDamageBoostItem *__fastcall idDeclInfoTemplate<idDeclDamageBoostItem>::Alloc(
        idDeclInfoTemplate<idDeclDamageBoostItem> *this,
        const char *name)
{
  idDeclDamageBoostItem *v3; // r3
  idDeclDamageBoostItem *v4; // r30

  v3 = (idDeclDamageBoostItem *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x200u,
                                  tag: TAG_DECL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclDamageBoostItem::idDeclDamageBoostItem(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495396
// EA  : 0x82BCE148
// RVA : 0x00BCE148
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495396()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclAuthorityBoostItem@@@@UBAHXZ
// EA  : 0x82BCE178
// RVA : 0x00BCE178
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclAuthorityBoostItem>::AllocSize(
        idDeclInfoTemplate<idDeclAuthorityBoostItem> *this)
{
  return 528;
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclVehicleArmorKit@@@@UBAHXZ
// EA  : 0x82BCE180
// RVA : 0x00BCE180
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclVehicleArmorKit>::AllocSize(idDeclInfoTemplate<idDeclVehicleArmorKit> *this)
{
  return 520;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclWeapon@@@@UBAPAVidDeclWeapon@@XZ
// EA  : 0x82BCE190
// RVA : 0x00BCE190
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclWeapon *__fastcall idDeclInfoTemplate<idDeclWeapon>::AllocDecl(idDeclInfoTemplate<idDeclWeapon> *this)
{
  idDeclWeapon *v1; // r3

  v1 = (idDeclWeapon *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x768u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclWeapon::idDeclWeapon(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495429
// EA  : 0x82BCE1F8
// RVA : 0x00BCE1F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495429()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclWeapon@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCE230
// RVA : 0x00BCE230
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclWeapon *__fastcall idDeclInfoTemplate<idDeclWeapon>::Alloc(
        idDeclInfoTemplate<idDeclWeapon> *this,
        const char *name)
{
  idDeclWeapon *v3; // r3
  idDeclWeapon *v4; // r30

  v3 = (idDeclWeapon *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x768u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclWeapon::idDeclWeapon(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclInventory, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495452
// EA  : 0x82BCE2A0
// RVA : 0x00BCE2A0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495452()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclWeapon@@@@UBAHXZ
// EA  : 0x82BCE2D0
// RVA : 0x00BCE2D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclWeapon>::AllocSize(idDeclInfoTemplate<idDeclWeapon> *this)
{
  return 1896;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclLaserCutter@@@@UBAPAVidDeclLaserCutter@@XZ
// EA  : 0x82BCE2E0
// RVA : 0x00BCE2E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclLaserCutter *__fastcall idDeclInfoTemplate<idDeclLaserCutter>::AllocDecl(
        idDeclInfoTemplate<idDeclLaserCutter> *this)
{
  idDeclLaserCutter *v1; // r3

  v1 = (idDeclLaserCutter *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x878u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclLaserCutter::idDeclLaserCutter(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495479
// EA  : 0x82BCE348
// RVA : 0x00BCE348
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495479()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclLaserCutter@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCE380
// RVA : 0x00BCE380
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclLaserCutter *__fastcall idDeclInfoTemplate<idDeclLaserCutter>::Alloc(
        idDeclInfoTemplate<idDeclLaserCutter> *this,
        const char *name)
{
  idDeclLaserCutter *v3; // r3
  idDeclLaserCutter *v4; // r30

  v3 = (idDeclLaserCutter *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x878u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclLaserCutter::idDeclLaserCutter(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495502
// EA  : 0x82BCE3F0
// RVA : 0x00BCE3F0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495502()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclLaserCutter@@@@UBAHXZ
// EA  : 0x82BCE420
// RVA : 0x00BCE420
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclLaserCutter>::AllocSize(idDeclInfoTemplate<idDeclLaserCutter> *this)
{
  return 2168;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleWeapon@@@@UBAPAVidDeclVehicleWeapon@@XZ
// EA  : 0x82BCE430
// RVA : 0x00BCE430
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleWeapon *__fastcall idDeclInfoTemplate<idDeclVehicleWeapon>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleWeapon> *this)
{
  idDeclVehicleWeapon *v1; // r3

  v1 = (idDeclVehicleWeapon *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xA20u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleWeapon::idDeclVehicleWeapon(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495529
// EA  : 0x82BCE498
// RVA : 0x00BCE498
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495529()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleWeapon@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCE4D0
// RVA : 0x00BCE4D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleWeapon *__fastcall idDeclInfoTemplate<idDeclVehicleWeapon>::Alloc(
        idDeclInfoTemplate<idDeclVehicleWeapon> *this,
        const char *name)
{
  idDeclVehicleWeapon *v3; // r3
  idDeclVehicleWeapon *v4; // r30

  v3 = (idDeclVehicleWeapon *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xA20u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleWeapon::idDeclVehicleWeapon(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495552
// EA  : 0x82BCE540
// RVA : 0x00BCE540
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495552()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclVehicleWeapon@@@@UBAHXZ
// EA  : 0x82BCE570
// RVA : 0x00BCE570
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclVehicleWeapon>::AllocSize(idDeclInfoTemplate<idDeclVehicleWeapon> *this)
{
  return 2592;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclPlayerArmor@@@@UBAPAVidDeclPlayerArmor@@XZ
// EA  : 0x82BCE580
// RVA : 0x00BCE580
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclPlayerArmor *__fastcall idDeclInfoTemplate<idDeclPlayerArmor>::AllocDecl(
        idDeclInfoTemplate<idDeclPlayerArmor> *this)
{
  idDeclPlayerArmor *v1; // r3

  v1 = (idDeclPlayerArmor *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x208u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclPlayerArmor::idDeclPlayerArmor(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495579
// EA  : 0x82BCE5E8
// RVA : 0x00BCE5E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495579()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclPlayerArmor@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCE620
// RVA : 0x00BCE620
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclPlayerArmor *__fastcall idDeclInfoTemplate<idDeclPlayerArmor>::Alloc(
        idDeclInfoTemplate<idDeclPlayerArmor> *this,
        const char *name)
{
  idDeclPlayerArmor *v3; // r3
  idDeclPlayerArmor *v4; // r30

  v3 = (idDeclPlayerArmor *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x208u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclPlayerArmor::idDeclPlayerArmor(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclInventory, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495602
// EA  : 0x82BCE690
// RVA : 0x00BCE690
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495602()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleArmor@@@@UBAPAVidDeclVehicleArmor@@XZ
// EA  : 0x82BCE6C8
// RVA : 0x00BCE6C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleArmor *__fastcall idDeclInfoTemplate<idDeclVehicleArmor>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleArmor> *this)
{
  idDeclVehicleArmor *v1; // r3

  v1 = (idDeclVehicleArmor *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x200u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleArmor::idDeclVehicleArmor(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495629
// EA  : 0x82BCE730
// RVA : 0x00BCE730
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495629()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleArmor@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCE768
// RVA : 0x00BCE768
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleArmor *__fastcall idDeclInfoTemplate<idDeclVehicleArmor>::Alloc(
        idDeclInfoTemplate<idDeclVehicleArmor> *this,
        const char *name)
{
  idDeclVehicleArmor *v3; // r3
  idDeclVehicleArmor *v4; // r30

  v3 = (idDeclVehicleArmor *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x200u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleArmor::idDeclVehicleArmor(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495652
// EA  : 0x82BCE7D8
// RVA : 0x00BCE7D8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495652()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleArmorKit@@@@UBAPAVidDeclVehicleArmorKit@@XZ
// EA  : 0x82BCE810
// RVA : 0x00BCE810
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleArmorKit *__fastcall idDeclInfoTemplate<idDeclVehicleArmorKit>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleArmorKit> *this)
{
  idDeclVehicleArmorKit *v1; // r3

  v1 = (idDeclVehicleArmorKit *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x208u,
                                  tag: TAG_DECL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleArmorKit::idDeclVehicleArmorKit(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495679
// EA  : 0x82BCE878
// RVA : 0x00BCE878
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495679()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleArmorKit@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCE8B0
// RVA : 0x00BCE8B0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleArmorKit *__fastcall idDeclInfoTemplate<idDeclVehicleArmorKit>::Alloc(
        idDeclInfoTemplate<idDeclVehicleArmorKit> *this,
        const char *name)
{
  idDeclVehicleArmorKit *v3; // r3
  idDeclVehicleArmorKit *v4; // r30

  v3 = (idDeclVehicleArmorKit *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x208u,
                                  tag: TAG_DECL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleArmorKit::idDeclVehicleArmorKit(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495702_0
// EA  : 0x82BCE920
// RVA : 0x00BCE920
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495702_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleQuickUseItem@@@@UBAPAVidDeclVehicleQuickUseItem@@XZ
// EA  : 0x82BCE958
// RVA : 0x00BCE958
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleQuickUseItem *__fastcall idDeclInfoTemplate<idDeclVehicleQuickUseItem>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleQuickUseItem> *this)
{
  idDeclVehicleQuickUseItem *v1; // r3

  v1 = (idDeclVehicleQuickUseItem *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x238u,
                                      tag: TAG_DECL,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleQuickUseItem::idDeclVehicleQuickUseItem(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495729
// EA  : 0x82BCE9C0
// RVA : 0x00BCE9C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495729()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleQuickUseItem@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCE9F8
// RVA : 0x00BCE9F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleQuickUseItem *__fastcall idDeclInfoTemplate<idDeclVehicleQuickUseItem>::Alloc(
        idDeclInfoTemplate<idDeclVehicleQuickUseItem> *this,
        const char *name)
{
  idDeclVehicleQuickUseItem *v3; // r3
  idDeclVehicleQuickUseItem *v4; // r30

  v3 = (idDeclVehicleQuickUseItem *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x238u,
                                      tag: TAG_DECL,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleQuickUseItem::idDeclVehicleQuickUseItem(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495752
// EA  : 0x82BCEA68
// RVA : 0x00BCEA68
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495752()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclVehicleQuickUseItem@@@@UBAHXZ
// EA  : 0x82BCEA98
// RVA : 0x00BCEA98
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclVehicleQuickUseItem>::AllocSize(
        idDeclInfoTemplate<idDeclVehicleQuickUseItem> *this)
{
  return 568;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclWeaponUpgrade@@@@UBAPAVidDeclWeaponUpgrade@@XZ
// EA  : 0x82BCEAA8
// RVA : 0x00BCEAA8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclWeaponUpgrade *__fastcall idDeclInfoTemplate<idDeclWeaponUpgrade>::AllocDecl(
        idDeclInfoTemplate<idDeclWeaponUpgrade> *this)
{
  idDeclWeaponUpgrade *v1; // r3

  v1 = (idDeclWeaponUpgrade *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x240u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclWeaponUpgrade::idDeclWeaponUpgrade(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495779
// EA  : 0x82BCEB10
// RVA : 0x00BCEB10
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495779()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclWeaponUpgrade@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCEB48
// RVA : 0x00BCEB48
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclWeaponUpgrade *__fastcall idDeclInfoTemplate<idDeclWeaponUpgrade>::Alloc(
        idDeclInfoTemplate<idDeclWeaponUpgrade> *this,
        const char *name)
{
  idDeclWeaponUpgrade *v3; // r3
  idDeclWeaponUpgrade *v4; // r30

  v3 = (idDeclWeaponUpgrade *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x240u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclWeaponUpgrade::idDeclWeaponUpgrade(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495802
// EA  : 0x82BCEBB8
// RVA : 0x00BCEBB8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495802()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclActorModifier@@@@UBAHXZ
// EA  : 0x82BCEBE8
// RVA : 0x00BCEBE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclActorModifier>::AllocSize(idDeclInfoTemplate<idDeclActorModifier> *this)
{
  return 576;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclLaserCutterUpgrade@@@@UBAPAVidDeclLaserCutterUpgrade@@XZ
// EA  : 0x82BCEBF8
// RVA : 0x00BCEBF8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclLaserCutterUpgrade *__fastcall idDeclInfoTemplate<idDeclLaserCutterUpgrade>::AllocDecl(
        idDeclInfoTemplate<idDeclLaserCutterUpgrade> *this)
{
  idDeclLaserCutterUpgrade *v1; // r3

  v1 = (idDeclLaserCutterUpgrade *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x27Cu,
                                     tag: TAG_DECL,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclLaserCutterUpgrade::idDeclLaserCutterUpgrade(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495829
// EA  : 0x82BCEC60
// RVA : 0x00BCEC60
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495829()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclLaserCutterUpgrade@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCEC98
// RVA : 0x00BCEC98
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclLaserCutterUpgrade *__fastcall idDeclInfoTemplate<idDeclLaserCutterUpgrade>::Alloc(
        idDeclInfoTemplate<idDeclLaserCutterUpgrade> *this,
        const char *name)
{
  idDeclLaserCutterUpgrade *v3; // r3
  idDeclLaserCutterUpgrade *v4; // r30

  v3 = (idDeclLaserCutterUpgrade *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x27Cu,
                                     tag: TAG_DECL,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclLaserCutterUpgrade::idDeclLaserCutterUpgrade(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495852
// EA  : 0x82BCED08
// RVA : 0x00BCED08
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495852()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclLaserCutterUpgrade@@@@UBAHXZ
// EA  : 0x82BCED38
// RVA : 0x00BCED38
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclLaserCutterUpgrade>::AllocSize(
        idDeclInfoTemplate<idDeclLaserCutterUpgrade> *this)
{
  return 636;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleUpgrade@@@@UBAPAVidDeclVehicleUpgrade@@XZ
// EA  : 0x82BCED48
// RVA : 0x00BCED48
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleUpgrade *__fastcall idDeclInfoTemplate<idDeclVehicleUpgrade>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleUpgrade> *this)
{
  idDeclVehicleUpgrade *v1; // r3

  v1 = (idDeclVehicleUpgrade *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x23Cu,
                                 tag: TAG_DECL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleUpgrade::idDeclVehicleUpgrade(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495879
// EA  : 0x82BCEDB0
// RVA : 0x00BCEDB0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495879()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleUpgrade@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCEDE8
// RVA : 0x00BCEDE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleUpgrade *__fastcall idDeclInfoTemplate<idDeclVehicleUpgrade>::Alloc(
        idDeclInfoTemplate<idDeclVehicleUpgrade> *this,
        const char *name)
{
  idDeclVehicleUpgrade *v3; // r3
  idDeclVehicleUpgrade *v4; // r30

  v3 = (idDeclVehicleUpgrade *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x23Cu,
                                 tag: TAG_DECL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleUpgrade::idDeclVehicleUpgrade(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclInventory, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495902
// EA  : 0x82BCEE58
// RVA : 0x00BCEE58
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495902()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclVehicleUpgrade@@@@UBAHXZ
// EA  : 0x82BCEE88
// RVA : 0x00BCEE88
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclVehicleUpgrade>::AllocSize(idDeclInfoTemplate<idDeclVehicleUpgrade> *this)
{
  return 572;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleKey@@@@UBAPAVidDeclVehicleKey@@XZ
// EA  : 0x82BCEE98
// RVA : 0x00BCEE98
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleKey *__fastcall idDeclInfoTemplate<idDeclVehicleKey>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleKey> *this)
{
  idDeclVehicleKey *v1; // r3

  v1 = (idDeclVehicleKey *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x2E8u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleKey::idDeclVehicleKey(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495929
// EA  : 0x82BCEF00
// RVA : 0x00BCEF00
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495929()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleKey@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCEF38
// RVA : 0x00BCEF38
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleKey *__fastcall idDeclInfoTemplate<idDeclVehicleKey>::Alloc(
        idDeclInfoTemplate<idDeclVehicleKey> *this,
        const char *name)
{
  idDeclVehicleKey *v3; // r3
  idDeclVehicleKey *v4; // r30

  v3 = (idDeclVehicleKey *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x2E8u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleKey::idDeclVehicleKey(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$495952_0
// EA  : 0x82BCEFA8
// RVA : 0x00BCEFA8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495952_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclVehicleKey@@@@UBAHXZ
// EA  : 0x82BCEFD8
// RVA : 0x00BCEFD8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclVehicleKey>::AllocSize(idDeclInfoTemplate<idDeclVehicleKey> *this)
{
  return 744;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VmgDeclSmartLoot@@@@UBAPAVmgDeclSmartLoot@@XZ
// EA  : 0x82BCEFE8
// RVA : 0x00BCEFE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

mgDeclSmartLoot *__fastcall idDeclInfoTemplate<mgDeclSmartLoot>::AllocDecl(idDeclInfoTemplate<mgDeclSmartLoot> *this)
{
  mgDeclSmartLoot *v1; // r3

  v1 = (mgDeclSmartLoot *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x130u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return mgDeclSmartLoot::mgDeclSmartLoot(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495979
// EA  : 0x82BCF050
// RVA : 0x00BCF050
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_495979()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VmgDeclSmartLoot@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCF088
// RVA : 0x00BCF088
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

mgDeclSmartLoot *__fastcall idDeclInfoTemplate<mgDeclSmartLoot>::Alloc(
        idDeclInfoTemplate<mgDeclSmartLoot> *this,
        const char *name)
{
  mgDeclSmartLoot *v3; // r3
  mgDeclSmartLoot *v4; // r30

  v3 = (mgDeclSmartLoot *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x130u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = mgDeclSmartLoot::mgDeclSmartLoot(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496002
// EA  : 0x82BCF0F8
// RVA : 0x00BCF0F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496002()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VmgDeclSmartLoot@@@@UBAHXZ
// EA  : 0x82BCF128
// RVA : 0x00BCF128
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<mgDeclSmartLoot>::AllocSize(idDeclInfoTemplate<mgDeclSmartLoot> *this)
{
  return 304;
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclProjectileImpactEffect@@@@UBAHXZ
// EA  : 0x82BCF130
// RVA : 0x00BCF130
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclProjectileImpactEffect>::AllocSize(
        idDeclInfoTemplate<idDeclProjectileImpactEffect> *this)
{
  return 1552;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclProjectile@@@@UBAPAVidDeclProjectile@@XZ
// EA  : 0x82BCF140
// RVA : 0x00BCF140
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclProjectile *__fastcall idDeclInfoTemplate<idDeclProjectile>::AllocDecl(
        idDeclInfoTemplate<idDeclProjectile> *this)
{
  idDeclProjectile *v1; // r3

  v1 = (idDeclProjectile *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x2BCu,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclProjectile::idDeclProjectile(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496033
// EA  : 0x82BCF1A8
// RVA : 0x00BCF1A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496033()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclProjectile@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCF1E0
// RVA : 0x00BCF1E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclProjectile *__fastcall idDeclInfoTemplate<idDeclProjectile>::Alloc(
        idDeclInfoTemplate<idDeclProjectile> *this,
        const char *name)
{
  idDeclProjectile *v3; // r3
  idDeclProjectile *v4; // r30

  v3 = (idDeclProjectile *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x2BCu,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclProjectile::idDeclProjectile(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496056
// EA  : 0x82BCF250
// RVA : 0x00BCF250
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496056()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclProjectile@@@@UBAHXZ
// EA  : 0x82BCF280
// RVA : 0x00BCF280
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclProjectile>::AllocSize(idDeclInfoTemplate<idDeclProjectile> *this)
{
  return 700;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclPlayerProps@@@@UBAPAVidDeclPlayerProps@@XZ
// EA  : 0x82BCF290
// RVA : 0x00BCF290
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclPlayerProps *__fastcall idDeclInfoTemplate<idDeclPlayerProps>::AllocDecl(
        idDeclInfoTemplate<idDeclPlayerProps> *this)
{
  idDeclPlayerProps *v1; // r3

  v1 = (idDeclPlayerProps *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x1B4u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclPlayerProps::idDeclPlayerProps(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496083
// EA  : 0x82BCF2F8
// RVA : 0x00BCF2F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496083()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclPlayerProps@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCF330
// RVA : 0x00BCF330
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclPlayerProps *__fastcall idDeclInfoTemplate<idDeclPlayerProps>::Alloc(
        idDeclInfoTemplate<idDeclPlayerProps> *this,
        const char *name)
{
  idDeclPlayerProps *v3; // r3
  idDeclPlayerProps *v4; // r30

  v3 = (idDeclPlayerProps *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x1B4u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclPlayerProps::idDeclPlayerProps(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496106
// EA  : 0x82BCF3A0
// RVA : 0x00BCF3A0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496106()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclPlayerProps@@@@UBAHXZ
// EA  : 0x82BCF3D0
// RVA : 0x00BCF3D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclPlayerProps>::AllocSize(idDeclInfoTemplate<idDeclPlayerProps> *this)
{
  return 436;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAIInteraction@@@@UBAPAVidDeclAIInteraction@@XZ
// EA  : 0x82BCF3E0
// RVA : 0x00BCF3E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIInteraction *__fastcall idDeclInfoTemplate<idDeclAIInteraction>::AllocDecl(
        idDeclInfoTemplate<idDeclAIInteraction> *this)
{
  idDeclAIInteraction *v1; // r3

  v1 = (idDeclAIInteraction *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x50u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAIInteraction::idDeclAIInteraction(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496135
// EA  : 0x82BCF448
// RVA : 0x00BCF448
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496135()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAIInteraction@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCF480
// RVA : 0x00BCF480
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIInteraction *__fastcall idDeclInfoTemplate<idDeclAIInteraction>::Alloc(
        idDeclInfoTemplate<idDeclAIInteraction> *this,
        const char *name)
{
  idDeclAIInteraction *v3; // r3
  idDeclAIInteraction *v4; // r30

  v3 = (idDeclAIInteraction *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x50u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAIInteraction::idDeclAIInteraction(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496158
// EA  : 0x82BCF4F0
// RVA : 0x00BCF4F0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496158()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAIBehavior@@@@UBAPAVidDeclAIBehavior@@XZ
// EA  : 0x82BCF528
// RVA : 0x00BCF528
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIBehavior *__fastcall idDeclInfoTemplate<idDeclAIBehavior>::AllocDecl(
        idDeclInfoTemplate<idDeclAIBehavior> *this)
{
  idDeclAIBehavior *v1; // r3

  v1 = (idDeclAIBehavior *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x634u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAIBehavior::idDeclAIBehavior(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496189
// EA  : 0x82BCF590
// RVA : 0x00BCF590
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496189()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAIBehavior@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCF5C8
// RVA : 0x00BCF5C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIBehavior *__fastcall idDeclInfoTemplate<idDeclAIBehavior>::Alloc(
        idDeclInfoTemplate<idDeclAIBehavior> *this,
        const char *name)
{
  idDeclAIBehavior *v3; // r3
  idDeclAIBehavior *v4; // r30

  v3 = (idDeclAIBehavior *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x634u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAIBehavior::idDeclAIBehavior(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496212
// EA  : 0x82BCF638
// RVA : 0x00BCF638
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496212()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclAIBehavior@@@@UBAHXZ
// EA  : 0x82BCF668
// RVA : 0x00BCF668
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclAIBehavior>::AllocSize(idDeclInfoTemplate<idDeclAIBehavior> *this)
{
  return 1588;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAIBehaviorVO@@@@UBAPAVidDeclAIBehaviorVO@@XZ
// EA  : 0x82BCF678
// RVA : 0x00BCF678
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIBehaviorVO *__fastcall idDeclInfoTemplate<idDeclAIBehaviorVO>::AllocDecl(
        idDeclInfoTemplate<idDeclAIBehaviorVO> *this)
{
  idDeclAIBehaviorVO *v1; // r3

  v1 = (idDeclAIBehaviorVO *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x168u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAIBehaviorVO::idDeclAIBehaviorVO(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496239
// EA  : 0x82BCF6E0
// RVA : 0x00BCF6E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496239()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAIBehaviorVO@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCF718
// RVA : 0x00BCF718
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIBehaviorVO *__fastcall idDeclInfoTemplate<idDeclAIBehaviorVO>::Alloc(
        idDeclInfoTemplate<idDeclAIBehaviorVO> *this,
        const char *name)
{
  idDeclAIBehaviorVO *v3; // r3
  idDeclAIBehaviorVO *v4; // r30

  v3 = (idDeclAIBehaviorVO *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x168u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAIBehaviorVO::idDeclAIBehaviorVO(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496262
// EA  : 0x82BCF788
// RVA : 0x00BCF788
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496262()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclAIBehaviorVO@@@@UBAHXZ
// EA  : 0x82BCF7B8
// RVA : 0x00BCF7B8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclAIBehaviorVO>::AllocSize(idDeclInfoTemplate<idDeclAIBehaviorVO> *this)
{
  return 360;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAIBehaviorVOChains@@@@UBAPAVidDeclAIBehaviorVOChains@@XZ
// EA  : 0x82BCF7C8
// RVA : 0x00BCF7C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIBehaviorVOChains *__fastcall idDeclInfoTemplate<idDeclAIBehaviorVOChains>::AllocDecl(
        idDeclInfoTemplate<idDeclAIBehaviorVOChains> *this)
{
  idDeclAIBehaviorVOChains *v1; // r3

  v1 = (idDeclAIBehaviorVOChains *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x50u,
                                     tag: TAG_DECL,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAIBehaviorVOChains::idDeclAIBehaviorVOChains(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496289
// EA  : 0x82BCF830
// RVA : 0x00BCF830
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496289()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAIBehaviorVOChains@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCF868
// RVA : 0x00BCF868
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIBehaviorVOChains *__fastcall idDeclInfoTemplate<idDeclAIBehaviorVOChains>::Alloc(
        idDeclInfoTemplate<idDeclAIBehaviorVOChains> *this,
        const char *name)
{
  idDeclAIBehaviorVOChains *v3; // r3
  idDeclAIBehaviorVOChains *v4; // r30

  v3 = (idDeclAIBehaviorVOChains *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x50u,
                                     tag: TAG_DECL,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAIBehaviorVOChains::idDeclAIBehaviorVOChains(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496312
// EA  : 0x82BCF8D8
// RVA : 0x00BCF8D8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496312()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAIBehaviorEvents@@@@UBAPAVidDeclAIBehaviorEvents@@XZ
// EA  : 0x82BCF910
// RVA : 0x00BCF910
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIBehaviorEvents *__fastcall idDeclInfoTemplate<idDeclAIBehaviorEvents>::AllocDecl(
        idDeclInfoTemplate<idDeclAIBehaviorEvents> *this)
{
  idDeclAIBehaviorEvents *v1; // r3

  v1 = (idDeclAIBehaviorEvents *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x84u,
                                   tag: TAG_DECL,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAIBehaviorEvents::idDeclAIBehaviorEvents(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496339
// EA  : 0x82BCF978
// RVA : 0x00BCF978
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496339()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAIBehaviorEvents@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCF9B0
// RVA : 0x00BCF9B0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIBehaviorEvents *__fastcall idDeclInfoTemplate<idDeclAIBehaviorEvents>::Alloc(
        idDeclInfoTemplate<idDeclAIBehaviorEvents> *this,
        const char *name)
{
  idDeclAIBehaviorEvents *v3; // r3
  idDeclAIBehaviorEvents *v4; // r30

  v3 = (idDeclAIBehaviorEvents *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x84u,
                                   tag: TAG_DECL,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAIBehaviorEvents::idDeclAIBehaviorEvents(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496362
// EA  : 0x82BCFA20
// RVA : 0x00BCFA20
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496362()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclAIBehaviorEvents@@@@UBAHXZ
// EA  : 0x82BCFA50
// RVA : 0x00BCFA50
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclAIBehaviorEvents>::AllocSize(idDeclInfoTemplate<idDeclDragJoints> *this)
{
  return 132;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleAttack@@@@UBAPAVidDeclVehicleAttack@@XZ
// EA  : 0x82BCFA60
// RVA : 0x00BCFA60
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleAttack *__fastcall idDeclInfoTemplate<idDeclVehicleAttack>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleAttack> *this)
{
  idDeclVehicleAttack *v1; // r3

  v1 = (idDeclVehicleAttack *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x58u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleAttack::idDeclVehicleAttack(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496389
// EA  : 0x82BCFAC8
// RVA : 0x00BCFAC8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496389()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleAttack@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCFB00
// RVA : 0x00BCFB00
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleAttack *__fastcall idDeclInfoTemplate<idDeclVehicleAttack>::Alloc(
        idDeclInfoTemplate<idDeclVehicleAttack> *this,
        const char *name)
{
  idDeclVehicleAttack *v3; // r3
  idDeclVehicleAttack *v4; // r30

  v3 = (idDeclVehicleAttack *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x58u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleAttack::idDeclVehicleAttack(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496412
// EA  : 0x82BCFB70
// RVA : 0x00BCFB70
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496412()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclVehicleAttack@@@@UBAHXZ
// EA  : 0x82BCFBA0
// RVA : 0x00BCFBA0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclVehicleAttack>::AllocSize(idDeclInfoTemplate<idDeclOnlineLevel> *this)
{
  return 88;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAchievement@@@@UBAPAVidDeclAchievement@@XZ
// EA  : 0x82BCFBB0
// RVA : 0x00BCFBB0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAchievement *__fastcall idDeclInfoTemplate<idDeclAchievement>::AllocDecl(
        idDeclInfoTemplate<idDeclAchievement> *this)
{
  idDeclAchievement *v1; // r3

  v1 = (idDeclAchievement *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0xBCu,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAchievement::idDeclAchievement(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496439
// EA  : 0x82BCFC18
// RVA : 0x00BCFC18
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496439()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAchievement@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCFC50
// RVA : 0x00BCFC50
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAchievement *__fastcall idDeclInfoTemplate<idDeclAchievement>::Alloc(
        idDeclInfoTemplate<idDeclAchievement> *this,
        const char *name)
{
  idDeclAchievement *v3; // r3
  idDeclAchievement *v4; // r30

  v3 = (idDeclAchievement *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0xBCu,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAchievement::idDeclAchievement(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496462
// EA  : 0x82BCFCC0
// RVA : 0x00BCFCC0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496462()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclAchievement@@@@UBAHXZ
// EA  : 0x82BCFCF0
// RVA : 0x00BCFCF0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclAchievement>::AllocSize(idDeclInfoTemplate<idDeclAchievement> *this)
{
  return 188;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclGoreBehavior@@@@UBAPAVidDeclGoreBehavior@@XZ
// EA  : 0x82BCFD00
// RVA : 0x00BCFD00
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclGoreBehavior *__fastcall idDeclInfoTemplate<idDeclGoreBehavior>::AllocDecl(
        idDeclInfoTemplate<idDeclGoreBehavior> *this)
{
  idDeclGoreBehavior *v1; // r3

  v1 = (idDeclGoreBehavior *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x5Cu,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclGoreBehavior::idDeclGoreBehavior(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496489
// EA  : 0x82BCFD68
// RVA : 0x00BCFD68
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496489()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclGoreBehavior@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCFDA0
// RVA : 0x00BCFDA0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclGoreBehavior *__fastcall idDeclInfoTemplate<idDeclGoreBehavior>::Alloc(
        idDeclInfoTemplate<idDeclGoreBehavior> *this,
        const char *name)
{
  idDeclGoreBehavior *v3; // r3
  idDeclGoreBehavior *v4; // r30

  v3 = (idDeclGoreBehavior *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x5Cu,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclGoreBehavior::idDeclGoreBehavior(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496512
// EA  : 0x82BCFE10
// RVA : 0x00BCFE10
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496512()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclDamage@@@@UBAPAVidDeclDamage@@XZ
// EA  : 0x82BCFE48
// RVA : 0x00BCFE48
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDamage *__fastcall idDeclInfoTemplate<idDeclDamage>::AllocDecl(idDeclInfoTemplate<idDeclDamage> *this)
{
  idDeclDamage *v1; // r3

  v1 = (idDeclDamage *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x358u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclDamage::idDeclDamage(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496539
// EA  : 0x82BCFEB0
// RVA : 0x00BCFEB0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496539()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclDamage@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BCFEE8
// RVA : 0x00BCFEE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDamage *__fastcall idDeclInfoTemplate<idDeclDamage>::Alloc(
        idDeclInfoTemplate<idDeclDamage> *this,
        const char *name)
{
  idDeclDamage *v3; // r3
  idDeclDamage *v4; // r30

  v3 = (idDeclDamage *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x358u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclDamage::idDeclDamage(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496562
// EA  : 0x82BCFF58
// RVA : 0x00BCFF58
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496562()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclDamage@@@@UBAHXZ
// EA  : 0x82BCFF88
// RVA : 0x00BCFF88
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclDamage>::AllocSize(idDeclInfoTemplate<idDeclDamage> *this)
{
  return 856;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclOnlinePerk@@@@UBAPAVidDeclOnlinePerk@@XZ
// EA  : 0x82BCFF98
// RVA : 0x00BCFF98
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlinePerk *__fastcall idDeclInfoTemplate<idDeclOnlinePerk>::AllocDecl(
        idDeclInfoTemplate<idDeclOnlinePerk> *this)
{
  idDeclOnlinePerk *v1; // r3

  v1 = (idDeclOnlinePerk *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x60u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclOnlinePerk::idDeclOnlinePerk(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496589
// EA  : 0x82BD0000
// RVA : 0x00BD0000
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496589()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclOnlinePerk@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD0038
// RVA : 0x00BD0038
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlinePerk *__fastcall idDeclInfoTemplate<idDeclOnlinePerk>::Alloc(
        idDeclInfoTemplate<idDeclOnlinePerk> *this,
        const char *name)
{
  idDeclOnlinePerk *v3; // r3
  idDeclOnlinePerk *v4; // r30

  v3 = (idDeclOnlinePerk *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x60u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclOnlinePerk::idDeclOnlinePerk(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496612
// EA  : 0x82BD00A8
// RVA : 0x00BD00A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496612()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclFlare@@@@UBAHXZ
// EA  : 0x82BD00D8
// RVA : 0x00BD00D8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclFlare>::AllocSize(idDeclInfoTemplate<idDeclProductionFilter> *this)
{
  return 96;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclOnlineScoringCallout@@@@UBAPAVidDeclOnlineScoringCallout@@XZ
// EA  : 0x82BD00E8
// RVA : 0x00BD00E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlineScoringCallout *__fastcall idDeclInfoTemplate<idDeclOnlineScoringCallout>::AllocDecl(
        idDeclInfoTemplate<idDeclOnlineScoringCallout> *this)
{
  idDeclOnlineScoringCallout *v1; // r3

  v1 = (idDeclOnlineScoringCallout *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x50u,
                                       tag: TAG_DECL,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclOnlineScoringCallout::idDeclOnlineScoringCallout(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496639
// EA  : 0x82BD0150
// RVA : 0x00BD0150
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496639()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclOnlineScoringCallout@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD0188
// RVA : 0x00BD0188
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlineScoringCallout *__fastcall idDeclInfoTemplate<idDeclOnlineScoringCallout>::Alloc(
        idDeclInfoTemplate<idDeclOnlineScoringCallout> *this,
        const char *name)
{
  idDeclOnlineScoringCallout *v3; // r3
  idDeclOnlineScoringCallout *v4; // r30

  v3 = (idDeclOnlineScoringCallout *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x50u,
                                       tag: TAG_DECL,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclOnlineScoringCallout::idDeclOnlineScoringCallout(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496662
// EA  : 0x82BD01F8
// RVA : 0x00BD01F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496662()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclOnlineCoopScoring@@@@UBAPAVidDeclOnlineCoopScoring@@XZ
// EA  : 0x82BD0230
// RVA : 0x00BD0230
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlineCoopScoring *__fastcall idDeclInfoTemplate<idDeclOnlineCoopScoring>::AllocDecl(
        idDeclInfoTemplate<idDeclOnlineCoopScoring> *this)
{
  idDeclOnlineCoopScoring *v1; // r3

  v1 = (idDeclOnlineCoopScoring *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x10Cu,
                                    tag: TAG_DECL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclOnlineCoopScoring::idDeclOnlineCoopScoring(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496689
// EA  : 0x82BD0298
// RVA : 0x00BD0298
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496689()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclOnlineCoopScoring@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD02D0
// RVA : 0x00BD02D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlineCoopScoring *__fastcall idDeclInfoTemplate<idDeclOnlineCoopScoring>::Alloc(
        idDeclInfoTemplate<idDeclOnlineCoopScoring> *this,
        const char *name)
{
  idDeclOnlineCoopScoring *v3; // r3
  idDeclOnlineCoopScoring *v4; // r30

  v3 = (idDeclOnlineCoopScoring *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x10Cu,
                                    tag: TAG_DECL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclOnlineCoopScoring::idDeclOnlineCoopScoring(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496712
// EA  : 0x82BD0340
// RVA : 0x00BD0340
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496712()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclOnlineCoopScoring@@@@UBAHXZ
// EA  : 0x82BD0370
// RVA : 0x00BD0370
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclOnlineCoopScoring>::AllocSize(
        idDeclInfoTemplate<idDeclOnlineCoopScoring> *this)
{
  return 268;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclOnlineFiction@@@@UBAPAVidDeclOnlineFiction@@XZ
// EA  : 0x82BD0380
// RVA : 0x00BD0380
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlineFiction *__fastcall idDeclInfoTemplate<idDeclOnlineFiction>::AllocDecl(
        idDeclInfoTemplate<idDeclOnlineFiction> *this)
{
  idDeclOnlineFiction *v1; // r3

  v1 = (idDeclOnlineFiction *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x50u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclOnlineFiction::idDeclOnlineFiction(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496739
// EA  : 0x82BD03E8
// RVA : 0x00BD03E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496739()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclOnlineFiction@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD0420
// RVA : 0x00BD0420
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlineFiction *__fastcall idDeclInfoTemplate<idDeclOnlineFiction>::Alloc(
        idDeclInfoTemplate<idDeclOnlineFiction> *this,
        const char *name)
{
  idDeclOnlineFiction *v3; // r3
  idDeclOnlineFiction *v4; // r30

  v3 = (idDeclOnlineFiction *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x50u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclOnlineFiction::idDeclOnlineFiction(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496762
// EA  : 0x82BD0490
// RVA : 0x00BD0490
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496762()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclOnlineVOCallout@@@@UBAPAVidDeclOnlineVOCallout@@XZ
// EA  : 0x82BD04C8
// RVA : 0x00BD04C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlineVOCallout *__fastcall idDeclInfoTemplate<idDeclOnlineVOCallout>::AllocDecl(
        idDeclInfoTemplate<idDeclOnlineVOCallout> *this)
{
  idDeclOnlineVOCallout *v1; // r3

  v1 = (idDeclOnlineVOCallout *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x118u,
                                  tag: TAG_DECL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclOnlineVOCallout::idDeclOnlineVOCallout(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496789
// EA  : 0x82BD0530
// RVA : 0x00BD0530
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496789()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclOnlineVOCallout@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD0568
// RVA : 0x00BD0568
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlineVOCallout *__fastcall idDeclInfoTemplate<idDeclOnlineVOCallout>::Alloc(
        idDeclInfoTemplate<idDeclOnlineVOCallout> *this,
        const char *name)
{
  idDeclOnlineVOCallout *v3; // r3
  idDeclOnlineVOCallout *v4; // r30

  v3 = (idDeclOnlineVOCallout *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x118u,
                                  tag: TAG_DECL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclOnlineVOCallout::idDeclOnlineVOCallout(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496812
// EA  : 0x82BD05D8
// RVA : 0x00BD05D8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496812()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclOnlineVOCallout@@@@UBAHXZ
// EA  : 0x82BD0608
// RVA : 0x00BD0608
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclOnlineVOCallout>::AllocSize(idDeclInfoTemplate<idDeclOnlineVOCallout> *this)
{
  return 280;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleUnlock@@@@UBAPAVidDeclVehicleUnlock@@XZ
// EA  : 0x82BD0618
// RVA : 0x00BD0618
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleUnlock *__fastcall idDeclInfoTemplate<idDeclVehicleUnlock>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleUnlock> *this)
{
  idDeclVehicleUnlock *v1; // r3

  v1 = (idDeclVehicleUnlock *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x8Cu,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleUnlock::idDeclVehicleUnlock(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496839
// EA  : 0x82BD0680
// RVA : 0x00BD0680
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496839()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleUnlock@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD06B8
// RVA : 0x00BD06B8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleUnlock *__fastcall idDeclInfoTemplate<idDeclVehicleUnlock>::Alloc(
        idDeclInfoTemplate<idDeclVehicleUnlock> *this,
        const char *name)
{
  idDeclVehicleUnlock *v3; // r3
  idDeclVehicleUnlock *v4; // r30

  v3 = (idDeclVehicleUnlock *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x8Cu,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleUnlock::idDeclVehicleUnlock(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496862
// EA  : 0x82BD0728
// RVA : 0x00BD0728
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496862()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleLoadout@@@@UBAPAVidDeclVehicleLoadout@@XZ
// EA  : 0x82BD0760
// RVA : 0x00BD0760
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleLoadout *__fastcall idDeclInfoTemplate<idDeclVehicleLoadout>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleLoadout> *this)
{
  idDeclVehicleLoadout *v1; // r3

  v1 = (idDeclVehicleLoadout *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x64u,
                                 tag: TAG_DECL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleLoadout::idDeclVehicleLoadout(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496889
// EA  : 0x82BD07C8
// RVA : 0x00BD07C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496889()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleLoadout@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD0800
// RVA : 0x00BD0800
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleLoadout *__fastcall idDeclInfoTemplate<idDeclVehicleLoadout>::Alloc(
        idDeclInfoTemplate<idDeclVehicleLoadout> *this,
        const char *name)
{
  idDeclVehicleLoadout *v3; // r3
  idDeclVehicleLoadout *v4; // r30

  v3 = (idDeclVehicleLoadout *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x64u,
                                 tag: TAG_DECL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleLoadout::idDeclVehicleLoadout(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496912
// EA  : 0x82BD0870
// RVA : 0x00BD0870
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496912()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclMetric@@@@UBAPAVidDeclMetric@@XZ
// EA  : 0x82BD08A8
// RVA : 0x00BD08A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclMetric *__fastcall idDeclInfoTemplate<idDeclMetric>::AllocDecl(idDeclInfoTemplate<idDeclMetric> *this)
{
  idDeclMetric *v1; // r3

  v1 = (idDeclMetric *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x78u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclMetric::idDeclMetric(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496939
// EA  : 0x82BD0910
// RVA : 0x00BD0910
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496939()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclMetric@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD0948
// RVA : 0x00BD0948
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclMetric *__fastcall idDeclInfoTemplate<idDeclMetric>::Alloc(
        idDeclInfoTemplate<idDeclMetric> *this,
        const char *name)
{
  idDeclMetric *v3; // r3
  idDeclMetric *v4; // r30

  v3 = (idDeclMetric *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x78u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclMetric::idDeclMetric(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$496962
// EA  : 0x82BD09B8
// RVA : 0x00BD09B8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496962()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclGore@@@@UBAHXZ
// EA  : 0x82BD09E8
// RVA : 0x00BD09E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclGore>::AllocSize(idDeclInfoTemplate<idDeclGore> *this)
{
  return 120;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclEmblem@@@@UBAPAVidDeclEmblem@@XZ
// EA  : 0x82BD09F8
// RVA : 0x00BD09F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclEmblem *__fastcall idDeclInfoTemplate<idDeclEmblem>::AllocDecl(idDeclInfoTemplate<idDeclEmblem> *this)
{
  idDeclEmblem *v1; // r3

  v1 = (idDeclEmblem *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x68u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclEmblem::idDeclEmblem(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496989
// EA  : 0x82BD0A60
// RVA : 0x00BD0A60
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_496989()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclEmblem@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD0A98
// RVA : 0x00BD0A98
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclEmblem *__fastcall idDeclInfoTemplate<idDeclEmblem>::Alloc(
        idDeclInfoTemplate<idDeclEmblem> *this,
        const char *name)
{
  idDeclEmblem *v3; // r3
  idDeclEmblem *v4; // r30

  v3 = (idDeclEmblem *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x68u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclEmblem::idDeclEmblem(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497012
// EA  : 0x82BD0B08
// RVA : 0x00BD0B08
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497012()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAccolade@@@@UBAPAVidDeclAccolade@@XZ
// EA  : 0x82BD0B40
// RVA : 0x00BD0B40
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAccolade *__fastcall idDeclInfoTemplate<idDeclAccolade>::AllocDecl(idDeclInfoTemplate<idDeclAccolade> *this)
{
  idDeclAccolade *v1; // r3

  v1 = (idDeclAccolade *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x90u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAccolade::idDeclAccolade(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$497039
// EA  : 0x82BD0BA8
// RVA : 0x00BD0BA8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497039()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAccolade@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD0BE0
// RVA : 0x00BD0BE0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAccolade *__fastcall idDeclInfoTemplate<idDeclAccolade>::Alloc(
        idDeclInfoTemplate<idDeclAccolade> *this,
        const char *name)
{
  idDeclAccolade *v3; // r3
  idDeclAccolade *v4; // r30

  v3 = (idDeclAccolade *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x90u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAccolade::idDeclAccolade(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497062
// EA  : 0x82BD0C50
// RVA : 0x00BD0C50
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497062()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclAccolade@@@@UBAHXZ
// EA  : 0x82BD0C80
// RVA : 0x00BD0C80
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclAccolade>::AllocSize(idDeclInfoTemplate<idDeclAccolade> *this)
{
  return 144;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclGameMode@@@@UBAPAVidDeclGameMode@@XZ
// EA  : 0x82BD0C90
// RVA : 0x00BD0C90
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclGameMode *__fastcall idDeclInfoTemplate<idDeclGameMode>::AllocDecl(idDeclInfoTemplate<idDeclGameMode> *this)
{
  idDeclGameMode *v1; // r3

  v1 = (idDeclGameMode *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xC4u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclGameMode::idDeclGameMode(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$497089
// EA  : 0x82BD0CF8
// RVA : 0x00BD0CF8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497089()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclGameMode@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD0D30
// RVA : 0x00BD0D30
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclGameMode *__fastcall idDeclInfoTemplate<idDeclGameMode>::Alloc(
        idDeclInfoTemplate<idDeclGameMode> *this,
        const char *name)
{
  idDeclGameMode *v3; // r3
  idDeclGameMode *v4; // r30

  v3 = (idDeclGameMode *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xC4u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclGameMode::idDeclGameMode(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497112
// EA  : 0x82BD0DA0
// RVA : 0x00BD0DA0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497112()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclPvPMap@@@@UBAPAVidDeclPvPMap@@XZ
// EA  : 0x82BD0DD8
// RVA : 0x00BD0DD8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclPvPMap *__fastcall idDeclInfoTemplate<idDeclPvPMap>::AllocDecl(idDeclInfoTemplate<idDeclPvPMap> *this)
{
  idDeclPvPMap *v1; // r3

  v1 = (idDeclPvPMap *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xA8u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclPvPMap::idDeclPvPMap(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$497139
// EA  : 0x82BD0E40
// RVA : 0x00BD0E40
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497139()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclPvPMap@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD0E78
// RVA : 0x00BD0E78
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclPvPMap *__fastcall idDeclInfoTemplate<idDeclPvPMap>::Alloc(
        idDeclInfoTemplate<idDeclPvPMap> *this,
        const char *name)
{
  idDeclPvPMap *v3; // r3
  idDeclPvPMap *v4; // r30

  v3 = (idDeclPvPMap *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xA8u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclPvPMap::idDeclPvPMap(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497162
// EA  : 0x82BD0EE8
// RVA : 0x00BD0EE8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497162()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclCoopMap@@@@UBAPAVidDeclCoopMap@@XZ
// EA  : 0x82BD0F20
// RVA : 0x00BD0F20
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclCoopMap *__fastcall idDeclInfoTemplate<idDeclCoopMap>::AllocDecl(idDeclInfoTemplate<idDeclCoopMap> *this)
{
  idDeclCoopMap *v1; // r3

  v1 = (idDeclCoopMap *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x94u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclCoopMap::idDeclCoopMap(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$497189
// EA  : 0x82BD0F88
// RVA : 0x00BD0F88
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497189()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclCoopMap@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD0FC0
// RVA : 0x00BD0FC0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclCoopMap *__fastcall idDeclInfoTemplate<idDeclCoopMap>::Alloc(
        idDeclInfoTemplate<idDeclCoopMap> *this,
        const char *name)
{
  idDeclCoopMap *v3; // r3
  idDeclCoopMap *v4; // r30

  v3 = (idDeclCoopMap *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x94u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclCoopMap::idDeclCoopMap(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497212
// EA  : 0x82BD1030
// RVA : 0x00BD1030
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497212()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclCoopMap@@@@UBAHXZ
// EA  : 0x82BD1060
// RVA : 0x00BD1060
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclCoopMap>::AllocSize(idDeclInfoTemplate<idDeclCoopMap> *this)
{
  return 148;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclTypeInfoGraphTest@@@@UBAPAVidDeclTypeInfoGraphTest@@XZ
// EA  : 0x82BD1070
// RVA : 0x00BD1070
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTypeInfoGraphTest *__fastcall idDeclInfoTemplate<idDeclTypeInfoGraphTest>::AllocDecl(
        idDeclInfoTemplate<idDeclTypeInfoGraphTest> *this)
{
  idDeclTypeInfoGraph *v1; // r3
  idDeclTypeInfoGraph *v2; // r30

  v1 = (idDeclTypeInfoGraph *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x78u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v2 = v1;
  if ( v1 == nullptr )
    return nullptr;
  idDeclTypeInfoGraph::idDeclTypeInfoGraph(this: v1);
  HIBYTE(v2[1].__vftable) = 0;
  v2->__vftable = (idDeclTypeInfoGraph_vtbl *)&idDeclTypeInfoGraphTest::`vftable';
  BYTE1(v2[1].__vftable) = 0;
  v2[1].trackedMemory = 0;
  return (idDeclTypeInfoGraphTest *)v2;
}


// ========================================================================
// __unwind$497239
// EA  : 0x82BD1104
// RVA : 0x00BD1104
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497239()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclTypeInfoGraphTest@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD1138
// RVA : 0x00BD1138
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTypeInfoGraph *__fastcall idDeclInfoTemplate<idDeclTypeInfoGraphTest>::Alloc(
        idDeclInfoTemplate<idDeclTypeInfoGraphTest> *this,
        const char *name)
{
  idDeclTypeInfoGraph *v3; // r3
  idDeclTypeInfoGraph *v4; // r30

  v3 = (idDeclTypeInfoGraph *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x78u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idDeclTypeInfoGraph::idDeclTypeInfoGraph(this: v3);
    HIBYTE(v4[1].__vftable) = 0;
    v4->__vftable = (idDeclTypeInfoGraph_vtbl *)&idDeclTypeInfoGraphTest::`vftable';
    BYTE1(v4[1].__vftable) = 0;
    v4[1].trackedMemory = 0;
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497266
// EA  : 0x82BD11C4
// RVA : 0x00BD11C4
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497266()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclTypeInfoGraphSingleTypeTest@@@@UBAHXZ
// EA  : 0x82BD11F0
// RVA : 0x00BD11F0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclTypeInfoGraphSingleTypeTest>::AllocSize(
        idDeclInfoTemplate<idDeclTypeInfoGraphSingleTypeTest> *this)
{
  return 112;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclOnlineLevel@@@@UBAPAVidDeclOnlineLevel@@XZ
// EA  : 0x82BD1200
// RVA : 0x00BD1200
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlineLevel *__fastcall idDeclInfoTemplate<idDeclOnlineLevel>::AllocDecl(
        idDeclInfoTemplate<idDeclOnlineLevel> *this)
{
  idDeclOnlineLevel *v1; // r3

  v1 = (idDeclOnlineLevel *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x58u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclOnlineLevel::idDeclOnlineLevel(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$497299
// EA  : 0x82BD1268
// RVA : 0x00BD1268
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497299()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclOnlineLevel@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD12A0
// RVA : 0x00BD12A0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclOnlineLevel *__fastcall idDeclInfoTemplate<idDeclOnlineLevel>::Alloc(
        idDeclInfoTemplate<idDeclOnlineLevel> *this,
        const char *name)
{
  idDeclOnlineLevel *v3; // r3
  idDeclOnlineLevel *v4; // r30

  v3 = (idDeclOnlineLevel *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x58u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclOnlineLevel::idDeclOnlineLevel(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497322
// EA  : 0x82BD1310
// RVA : 0x00BD1310
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497322()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclMenuPopup@@@@UBAPAVidDeclMenuPopup@@XZ
// EA  : 0x82BD1348
// RVA : 0x00BD1348
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclMenuPopup *__fastcall idDeclInfoTemplate<idDeclMenuPopup>::AllocDecl(idDeclInfoTemplate<idDeclMenuPopup> *this)
{
  idDeclMenuPopup *v1; // r3

  v1 = (idDeclMenuPopup *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x60u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclMenuPopup::idDeclMenuPopup(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$497349
// EA  : 0x82BD13B0
// RVA : 0x00BD13B0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497349()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclMenuPopup@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD13E8
// RVA : 0x00BD13E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclMenuPopup *__fastcall idDeclInfoTemplate<idDeclMenuPopup>::Alloc(
        idDeclInfoTemplate<idDeclMenuPopup> *this,
        const char *name)
{
  idDeclMenuPopup *v3; // r3
  idDeclMenuPopup *v4; // r30

  v3 = (idDeclMenuPopup *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x60u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclMenuPopup::idDeclMenuPopup(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497372
// EA  : 0x82BD1458
// RVA : 0x00BD1458
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497372()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclMenuItem@@@@UBAPAVidDeclMenuItem@@XZ
// EA  : 0x82BD1490
// RVA : 0x00BD1490
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclMenuItem *__fastcall idDeclInfoTemplate<idDeclMenuItem>::AllocDecl(idDeclInfoTemplate<idDeclMenuItem> *this)
{
  idDeclMenuItem *v1; // r3

  v1 = (idDeclMenuItem *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x8Cu,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclMenuItem::idDeclMenuItem(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$497401
// EA  : 0x82BD14F8
// RVA : 0x00BD14F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497401()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclMenuItem@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD1530
// RVA : 0x00BD1530
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclMenuItem *__fastcall idDeclInfoTemplate<idDeclMenuItem>::Alloc(
        idDeclInfoTemplate<idDeclMenuItem> *this,
        const char *name)
{
  idDeclMenuItem *v3; // r3
  idDeclMenuItem *v4; // r30

  v3 = (idDeclMenuItem *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x8Cu,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclMenuItem::idDeclMenuItem(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497424
// EA  : 0x82BD15A0
// RVA : 0x00BD15A0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497424()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclTwitchPain@@@@UBAPAVidDeclTwitchPain@@XZ
// EA  : 0x82BD15D8
// RVA : 0x00BD15D8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTwitchPain *__fastcall idDeclInfoTemplate<idDeclTwitchPain>::AllocDecl(
        idDeclInfoTemplate<idDeclTwitchPain> *this)
{
  idDeclTwitchPain *v1; // r3

  v1 = (idDeclTwitchPain *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x50u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclTwitchPain::idDeclTwitchPain(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$497451
// EA  : 0x82BD1640
// RVA : 0x00BD1640
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497451()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclTwitchPain@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD1678
// RVA : 0x00BD1678
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTwitchPain *__fastcall idDeclInfoTemplate<idDeclTwitchPain>::Alloc(
        idDeclInfoTemplate<idDeclTwitchPain> *this,
        const char *name)
{
  idDeclTwitchPain *v3; // r3
  idDeclTwitchPain *v4; // r30

  v3 = (idDeclTwitchPain *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x50u,
                             tag: TAG_DECL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclTwitchPain::idDeclTwitchPain(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497474
// EA  : 0x82BD16E8
// RVA : 0x00BD16E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497474()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclSecretType@@@@UBAPAVidDeclSecretType@@XZ
// EA  : 0x82BD1720
// RVA : 0x00BD1720
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSecretType *__fastcall idDeclInfoTemplate<idDeclSecretType>::AllocDecl(
        idDeclInfoTemplate<idDeclSecretType> *this)
{
  idDeclTypeInfo *v1; // r3
  _DWORD *v2; // r30

  v1 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x4Cu,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v2 = &v1->__vftable;
  if ( v1 == nullptr )
    return nullptr;
  idDeclTypeInfo::idDeclTypeInfo(this: v1);
  *v2 = &idDeclSecretType::`vftable';
  v2[17] = -1;
  v2[16] = 0;
  v2[18] = 0;
  return (idDeclSecretType *)v2;
}


// ========================================================================
// __unwind$497503
// EA  : 0x82BD17C0
// RVA : 0x00BD17C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497503()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclSecretType@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD17F8
// RVA : 0x00BD17F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTypeInfo *__fastcall idDeclInfoTemplate<idDeclSecretType>::Alloc(
        idDeclInfoTemplate<idDeclSecretType> *this,
        const char *name)
{
  idDeclTypeInfo *v3; // r3
  idDeclTypeInfo *v4; // r30

  v3 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x4Cu,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idDeclTypeInfo::idDeclTypeInfo(this: v3);
    v4->__vftable = (idDeclTypeInfo_vtbl *)&idDeclSecretType::`vftable';
    v4[1].trackedMemory = -1;
    v4[1].__vftable = nullptr;
    v4[1].name.str = nullptr;
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497536
// EA  : 0x82BD1890
// RVA : 0x00BD1890
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497536()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclSecretType@@@@UBAHXZ
// EA  : 0x82BD18C0
// RVA : 0x00BD18C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclSecretType>::AllocSize(
        COMBAT_LeaveZiplineDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 76;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclBot@@@@UBAPAVidDeclBot@@XZ
// EA  : 0x82BD18D0
// RVA : 0x00BD18D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclBot *__fastcall idDeclInfoTemplate<idDeclBot>::AllocDecl(idDeclInfoTemplate<idDeclBot> *this)
{
  idDeclBot *v1; // r3

  v1 = (idDeclBot *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x60u,
                      tag: TAG_DECL,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclBot::idDeclBot(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$497575
// EA  : 0x82BD1938
// RVA : 0x00BD1938
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497575()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclBot@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD1970
// RVA : 0x00BD1970
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclBot *__fastcall idDeclInfoTemplate<idDeclBot>::Alloc(idDeclInfoTemplate<idDeclBot> *this, const char *name)
{
  idDeclBot *v3; // r3
  idDeclBot *v4; // r30

  v3 = (idDeclBot *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x60u,
                      tag: TAG_DECL,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclBot::idDeclBot(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497598
// EA  : 0x82BD19E0
// RVA : 0x00BD19E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497598()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclLaserGate@@@@UBAPAVidDeclLaserGate@@XZ
// EA  : 0x82BD1A18
// RVA : 0x00BD1A18
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclLaserGate *__fastcall idDeclInfoTemplate<idDeclLaserGate>::AllocDecl(idDeclInfoTemplate<idDeclLaserGate> *this)
{
  idDeclLaserGate *v1; // r3

  v1 = (idDeclLaserGate *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x60u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclLaserGate::idDeclLaserGate(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$497627
// EA  : 0x82BD1A80
// RVA : 0x00BD1A80
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497627()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclLaserGate@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD1AB8
// RVA : 0x00BD1AB8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclLaserGate *__fastcall idDeclInfoTemplate<idDeclLaserGate>::Alloc(
        idDeclInfoTemplate<idDeclLaserGate> *this,
        const char *name)
{
  idDeclLaserGate *v3; // r3
  idDeclLaserGate *v4; // r30

  v3 = (idDeclLaserGate *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x60u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclLaserGate::idDeclLaserGate(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497650
// EA  : 0x82BD1B28
// RVA : 0x00BD1B28
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497650()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAiEvent@@@@UBAPAVidDeclAiEvent@@XZ
// EA  : 0x82BD1B60
// RVA : 0x00BD1B60
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAiEvent *__fastcall idDeclInfoTemplate<idDeclAiEvent>::AllocDecl(idDeclInfoTemplate<idDeclAiEvent> *this)
{
  idDeclAiEvent *v1; // r3

  v1 = (idDeclAiEvent *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x9Cu,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAiEvent::idDeclAiEvent(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$497679
// EA  : 0x82BD1BC8
// RVA : 0x00BD1BC8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497679()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAiEvent@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD1C00
// RVA : 0x00BD1C00
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAiEvent *__fastcall idDeclInfoTemplate<idDeclAiEvent>::Alloc(
        idDeclInfoTemplate<idDeclAiEvent> *this,
        const char *name)
{
  idDeclAiEvent *v3; // r3
  idDeclAiEvent *v4; // r30

  v3 = (idDeclAiEvent *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x9Cu,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAiEvent::idDeclAiEvent(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497702
// EA  : 0x82BD1C70
// RVA : 0x00BD1C70
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497702()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclFoliage@@@@UBAHXZ
// EA  : 0x82BD1CA0
// RVA : 0x00BD1CA0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclFoliage>::AllocSize(idDeclInfoTemplate<idDeclFoliage> *this)
{
  return 156;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclFootstepEvents@@@@UBAPAVidDeclFootstepEvents@@XZ
// EA  : 0x82BD1CB0
// RVA : 0x00BD1CB0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclFootstepEvents *__fastcall idDeclInfoTemplate<idDeclFootstepEvents>::AllocDecl(
        idDeclInfoTemplate<idDeclFootstepEvents> *this)
{
  idDeclTypeInfo *v1; // r3
  _DWORD *v2; // r30

  v1 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x54u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v2 = &v1->__vftable;
  if ( v1 == nullptr )
    return nullptr;
  idDeclTypeInfo::idDeclTypeInfo(this: v1);
  v2[16] = 0;
  *v2 = &idDeclFootstepEvents::`vftable';
  v2[17] = 0;
  v2[18] = 0;
  v2[19] = 0;
  v2[20] = 0;
  return (idDeclFootstepEvents *)v2;
}


// ========================================================================
// __unwind$497735
// EA  : 0x82BD1D4C
// RVA : 0x00BD1D4C
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497735()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclFootstepEvents@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD1D80
// RVA : 0x00BD1D80
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTypeInfo *__fastcall idDeclInfoTemplate<idDeclFootstepEvents>::Alloc(
        idDeclInfoTemplate<idDeclFootstepEvents> *this,
        const char *name)
{
  idDeclTypeInfo *v3; // r3
  idDeclTypeInfo *v4; // r30

  v3 = (idDeclTypeInfo *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x54u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idDeclTypeInfo::idDeclTypeInfo(this: v3);
    v4[1].__vftable = nullptr;
    v4->__vftable = (idDeclTypeInfo_vtbl *)&idDeclFootstepEvents::`vftable';
    v4[1].trackedMemory = 0;
    v4[1].name.str = nullptr;
    v4[1].nextOnHashChain = nullptr;
    v4[1].resourceListPtr = nullptr;
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$497762
// EA  : 0x82BD1E14
// RVA : 0x00BD1E14
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_497762()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclFootstepEvents@@@@UBAHXZ
// EA  : 0x82BD1E40
// RVA : 0x00BD1E40
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclFootstepEvents>::AllocSize(idDeclInfoTemplate<idDeclVoiceOver> *this)
{
  return 84;
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclHandsBobCycle@@@@UBAPAVidDeclHandsBobCycle@@XZ
// EA  : 0x82BD2698
// RVA : 0x00BD2698
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclHandsBobCycle *__fastcall idDeclInfoTemplate<idDeclHandsBobCycle>::AllocDecl(
        idDeclInfoTemplate<idDeclHandsBobCycle> *this)
{
  idDeclHandsBobCycle *v1; // r3

  v1 = (idDeclHandsBobCycle *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x2B8u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclHandsBobCycle::idDeclHandsBobCycle(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$499625_0
// EA  : 0x82BD2700
// RVA : 0x00BD2700
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_499625_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclHandsBobCycle@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD2738
// RVA : 0x00BD2738
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclHandsBobCycle *__fastcall idDeclInfoTemplate<idDeclHandsBobCycle>::Alloc(
        idDeclInfoTemplate<idDeclHandsBobCycle> *this,
        const char *name)
{
  idDeclHandsBobCycle *v3; // r3
  idDeclHandsBobCycle *v4; // r30

  v3 = (idDeclHandsBobCycle *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x2B8u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclHandsBobCycle::idDeclHandsBobCycle(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$499648
// EA  : 0x82BD27A8
// RVA : 0x00BD27A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_499648()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAITurnParms@@@@UBAPAVidDeclAITurnParms@@XZ
// EA  : 0x82BD27E0
// RVA : 0x00BD27E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAITurnParms *__fastcall idDeclInfoTemplate<idDeclAITurnParms>::AllocDecl(
        idDeclInfoTemplate<idDeclAITurnParms> *this)
{
  idDeclAITurnParms *v1; // r3

  v1 = (idDeclAITurnParms *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x74u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAITurnParms::idDeclAITurnParms(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$499673
// EA  : 0x82BD2848
// RVA : 0x00BD2848
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_499673()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAITurnParms@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD2880
// RVA : 0x00BD2880
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAITurnParms *__fastcall idDeclInfoTemplate<idDeclAITurnParms>::Alloc(
        idDeclInfoTemplate<idDeclAITurnParms> *this,
        const char *name)
{
  idDeclAITurnParms *v3; // r3
  idDeclAITurnParms *v4; // r30

  v3 = (idDeclAITurnParms *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x74u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAITurnParms::idDeclAITurnParms(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$499696
// EA  : 0x82BD28F0
// RVA : 0x00BD28F0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_499696()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclTypeInfoGraphSingleTypeTest@@@@UBAPAVidDeclTypeInfoGraphSingleTypeTest@@XZ
// EA  : 0x82BD2928
// RVA : 0x00BD2928
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTypeInfoGraphSingleTypeTest *__fastcall idDeclInfoTemplate<idDeclTypeInfoGraphSingleTypeTest>::AllocDecl(
        idDeclInfoTemplate<idDeclTypeInfoGraphSingleTypeTest> *this)
{
  idDeclTypeInfoGraph *v1; // r3
  _DWORD *v2; // r30

  v1 = (idDeclTypeInfoGraph *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x70u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v2 = &v1->__vftable;
  if ( v1 == nullptr )
    return nullptr;
  idDeclTypeInfoGraph::idDeclTypeInfoGraph(this: v1);
  *v2 = &idDeclTypeInfoGraphSingleTypeTest::`vftable';
  return (idDeclTypeInfoGraphSingleTypeTest *)v2;
}


// ========================================================================
// __unwind$499721
// EA  : 0x82BD29AC
// RVA : 0x00BD29AC
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_499721()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclTypeInfoGraphSingleTypeTest@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD29E0
// RVA : 0x00BD29E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idResource *__fastcall idDeclInfoTemplate<idDeclTypeInfoGraphSingleTypeTest>::Alloc(
        idDeclInfoTemplate<idDeclTypeInfoGraphSingleTypeTest> *this,
        const char *name)
{
  idDeclTypeInfoGraph *v3; // r3
  idResource *v4; // r30

  v3 = (idDeclTypeInfoGraph *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x70u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idDeclTypeInfoGraph::idDeclTypeInfoGraph(this: v3);
    v4->__vftable = (idResource_vtbl *)&idDeclTypeInfoGraphSingleTypeTest::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$499754
// EA  : 0x82BD2A5C
// RVA : 0x00BD2A5C
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_499754()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclRecipe@@@@UBAPAVidDeclRecipe@@XZ
// EA  : 0x82BD3320
// RVA : 0x00BD3320
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclRecipe *__fastcall idDeclInfoTemplate<idDeclRecipe>::AllocDecl(idDeclInfoTemplate<idDeclRecipe> *this)
{
  idDeclRecipe *v1; // r3

  v1 = (idDeclRecipe *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x68u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclRecipe::idDeclRecipe(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$501356
// EA  : 0x82BD3388
// RVA : 0x00BD3388
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_501356()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclRecipe@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD33C0
// RVA : 0x00BD33C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclRecipe *__fastcall idDeclInfoTemplate<idDeclRecipe>::Alloc(
        idDeclInfoTemplate<idDeclRecipe> *this,
        const char *name)
{
  idDeclRecipe *v3; // r3
  idDeclRecipe *v4; // r30

  v3 = (idDeclRecipe *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x68u,
                         tag: TAG_DECL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclRecipe::idDeclRecipe(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$501379
// EA  : 0x82BD3430
// RVA : 0x00BD3430
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_501379()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclSpecialEvent@@@@UBAPAVidDeclSpecialEvent@@XZ
// EA  : 0x82BD3468
// RVA : 0x00BD3468
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSpecialEvent *__fastcall idDeclInfoTemplate<idDeclSpecialEvent>::AllocDecl(
        idDeclInfoTemplate<idDeclSpecialEvent> *this)
{
  idDeclSpecialEvent *v1; // r3

  v1 = (idDeclSpecialEvent *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xA0u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclSpecialEvent::idDeclSpecialEvent(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$501404
// EA  : 0x82BD34D0
// RVA : 0x00BD34D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_501404()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclSpecialEvent@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD3508
// RVA : 0x00BD3508
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSpecialEvent *__fastcall idDeclInfoTemplate<idDeclSpecialEvent>::Alloc(
        idDeclInfoTemplate<idDeclSpecialEvent> *this,
        const char *name)
{
  idDeclSpecialEvent *v3; // r3
  idDeclSpecialEvent *v4; // r30

  v3 = (idDeclSpecialEvent *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xA0u,
                               tag: TAG_DECL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclSpecialEvent::idDeclSpecialEvent(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$501427
// EA  : 0x82BD3578
// RVA : 0x00BD3578
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_501427()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclLootPool@@@@UBAPAVidDeclLootPool@@XZ
// EA  : 0x82BD35B0
// RVA : 0x00BD35B0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclLootPool *__fastcall idDeclInfoTemplate<idDeclLootPool>::AllocDecl(idDeclInfoTemplate<idDeclLootPool> *this)
{
  idDeclLootPool *v1; // r3

  v1 = (idDeclLootPool *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x50u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclLootPool::idDeclLootPool(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$501452
// EA  : 0x82BD3618
// RVA : 0x00BD3618
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_501452()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclLootPool@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD3650
// RVA : 0x00BD3650
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclLootPool *__fastcall idDeclInfoTemplate<idDeclLootPool>::Alloc(
        idDeclInfoTemplate<idDeclLootPool> *this,
        const char *name)
{
  idDeclLootPool *v3; // r3
  idDeclLootPool *v4; // r30

  v3 = (idDeclLootPool *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x50u,
                           tag: TAG_DECL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclLootPool::idDeclLootPool(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$501475
// EA  : 0x82BD36C0
// RVA : 0x00BD36C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_501475()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclTrackingParms@@@@UBAPAVidDeclTrackingParms@@XZ
// EA  : 0x82BD36F8
// RVA : 0x00BD36F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTrackingParms *__fastcall idDeclInfoTemplate<idDeclTrackingParms>::AllocDecl(
        idDeclInfoTemplate<idDeclTrackingParms> *this)
{
  idDeclTrackingParms *v1; // r3

  v1 = (idDeclTrackingParms *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x50u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclTrackingParms::idDeclTrackingParms(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$501500_0
// EA  : 0x82BD3760
// RVA : 0x00BD3760
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_501500_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclTrackingParms@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD3798
// RVA : 0x00BD3798
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTrackingParms *__fastcall idDeclInfoTemplate<idDeclTrackingParms>::Alloc(
        idDeclInfoTemplate<idDeclTrackingParms> *this,
        const char *name)
{
  idDeclTrackingParms *v3; // r3
  idDeclTrackingParms *v4; // r30

  v3 = (idDeclTrackingParms *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x50u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclTrackingParms::idDeclTrackingParms(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$501523
// EA  : 0x82BD3808
// RVA : 0x00BD3808
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_501523()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclSecrets@@@@UBAPAVidDeclSecrets@@XZ
// EA  : 0x82BD3840
// RVA : 0x00BD3840
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSecrets *__fastcall idDeclInfoTemplate<idDeclSecrets>::AllocDecl(idDeclInfoTemplate<idDeclSecrets> *this)
{
  idDeclSecrets *v1; // r3

  v1 = (idDeclSecrets *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x68u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclSecrets::idDeclSecrets(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$501548
// EA  : 0x82BD38A8
// RVA : 0x00BD38A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_501548()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclSecrets@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD38E0
// RVA : 0x00BD38E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSecrets *__fastcall idDeclInfoTemplate<idDeclSecrets>::Alloc(
        idDeclInfoTemplate<idDeclSecrets> *this,
        const char *name)
{
  idDeclSecrets *v3; // r3
  idDeclSecrets *v4; // r30

  v3 = (idDeclSecrets *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x68u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclSecrets::idDeclSecrets(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$501571
// EA  : 0x82BD3950
// RVA : 0x00BD3950
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_501571()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclFaction@@@@UBAPAVidDeclFaction@@XZ
// EA  : 0x82BD52C0
// RVA : 0x00BD52C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclFaction *__fastcall idDeclInfoTemplate<idDeclFaction>::AllocDecl(idDeclInfoTemplate<idDeclFaction> *this)
{
  idDeclFaction *v1; // r3

  v1 = (idDeclFaction *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x74u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclFaction::idDeclFaction(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$503143
// EA  : 0x82BD5328
// RVA : 0x00BD5328
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_503143()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclFaction@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD5360
// RVA : 0x00BD5360
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclFaction *__fastcall idDeclInfoTemplate<idDeclFaction>::Alloc(
        idDeclInfoTemplate<idDeclFaction> *this,
        const char *name)
{
  idDeclFaction *v3; // r3
  idDeclFaction *v4; // r30

  v3 = (idDeclFaction *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x74u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclFaction::idDeclFaction(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$503166
// EA  : 0x82BD53D0
// RVA : 0x00BD53D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_503166()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclSpecialEvent_Area@@@@UBAPAVidDeclSpecialEvent_Area@@XZ
// EA  : 0x82BD5408
// RVA : 0x00BD5408
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSpecialEvent_Area *__fastcall idDeclInfoTemplate<idDeclSpecialEvent_Area>::AllocDecl(
        idDeclInfoTemplate<idDeclSpecialEvent_Area> *this)
{
  idDeclSpecialEvent_Area *v1; // r3

  v1 = (idDeclSpecialEvent_Area *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x88u,
                                    tag: TAG_DECL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclSpecialEvent_Area::idDeclSpecialEvent_Area(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$503191
// EA  : 0x82BD5470
// RVA : 0x00BD5470
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_503191()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclSpecialEvent_Area@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD54A8
// RVA : 0x00BD54A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclSpecialEvent_Area *__fastcall idDeclInfoTemplate<idDeclSpecialEvent_Area>::Alloc(
        idDeclInfoTemplate<idDeclSpecialEvent_Area> *this,
        const char *name)
{
  idDeclSpecialEvent_Area *v3; // r3
  idDeclSpecialEvent_Area *v4; // r30

  v3 = (idDeclSpecialEvent_Area *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x88u,
                                    tag: TAG_DECL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclSpecialEvent_Area::idDeclSpecialEvent_Area(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$503214_0
// EA  : 0x82BD5518
// RVA : 0x00BD5518
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_503214_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclTutorialEvent@@@@UBAPAVidDeclTutorialEvent@@XZ
// EA  : 0x82BD5550
// RVA : 0x00BD5550
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTutorialEvent *__fastcall idDeclInfoTemplate<idDeclTutorialEvent>::AllocDecl(
        idDeclInfoTemplate<idDeclTutorialEvent> *this)
{
  idDeclTutorialEvent *v1; // r3

  v1 = (idDeclTutorialEvent *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x98u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclTutorialEvent::idDeclTutorialEvent(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$503239
// EA  : 0x82BD55B8
// RVA : 0x00BD55B8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_503239()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclTutorialEvent@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD55F0
// RVA : 0x00BD55F0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclTutorialEvent *__fastcall idDeclInfoTemplate<idDeclTutorialEvent>::Alloc(
        idDeclInfoTemplate<idDeclTutorialEvent> *this,
        const char *name)
{
  idDeclTutorialEvent *v3; // r3
  idDeclTutorialEvent *v4; // r30

  v3 = (idDeclTutorialEvent *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x98u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclTutorialEvent::idDeclTutorialEvent(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$503262
// EA  : 0x82BD5660
// RVA : 0x00BD5660
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_503262()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclProjectileImpactEffect@@@@UBAPAVidDeclProjectileImpactEffect@@XZ
// EA  : 0x82BD5698
// RVA : 0x00BD5698
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclProjectileImpactEffect *__fastcall idDeclInfoTemplate<idDeclProjectileImpactEffect>::AllocDecl(
        idDeclInfoTemplate<idDeclProjectileImpactEffect> *this)
{
  idDeclProjectileImpactEffect *v1; // r3

  v1 = (idDeclProjectileImpactEffect *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 0x610u,
                                         tag: TAG_DECL,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclProjectileImpactEffect::idDeclProjectileImpactEffect(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$503287
// EA  : 0x82BD5700
// RVA : 0x00BD5700
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_503287()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclProjectileImpactEffect@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD5738
// RVA : 0x00BD5738
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclProjectileImpactEffect *__fastcall idDeclInfoTemplate<idDeclProjectileImpactEffect>::Alloc(
        idDeclInfoTemplate<idDeclProjectileImpactEffect> *this,
        const char *name)
{
  idDeclProjectileImpactEffect *v3; // r3
  idDeclProjectileImpactEffect *v4; // r30

  v3 = (idDeclProjectileImpactEffect *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 0x610u,
                                         tag: TAG_DECL,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclProjectileImpactEffect::idDeclProjectileImpactEffect(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$503310
// EA  : 0x82BD57A8
// RVA : 0x00BD57A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_503310()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclFacialAnimationSet@@@@UBAPAVidDeclFacialAnimationSet@@XZ
// EA  : 0x82BD57E0
// RVA : 0x00BD57E0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclFacialAnimationSet *__fastcall idDeclInfoTemplate<idDeclFacialAnimationSet>::AllocDecl(
        idDeclInfoTemplate<idDeclFacialAnimationSet> *this)
{
  idDeclFacialAnimationSet *v1; // r3

  v1 = (idDeclFacialAnimationSet *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0xA0u,
                                     tag: TAG_DECL,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclFacialAnimationSet::idDeclFacialAnimationSet(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$503335
// EA  : 0x82BD5848
// RVA : 0x00BD5848
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_503335()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclFacialAnimationSet@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD5880
// RVA : 0x00BD5880
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclFacialAnimationSet *__fastcall idDeclInfoTemplate<idDeclFacialAnimationSet>::Alloc(
        idDeclInfoTemplate<idDeclFacialAnimationSet> *this,
        const char *name)
{
  idDeclFacialAnimationSet *v3; // r3
  idDeclFacialAnimationSet *v4; // r30

  v3 = (idDeclFacialAnimationSet *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0xA0u,
                                     tag: TAG_DECL,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclFacialAnimationSet::idDeclFacialAnimationSet(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$503358
// EA  : 0x82BD58F0
// RVA : 0x00BD58F0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_503358()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAuthorityBoostItem@@@@UBAPAVidDeclAuthorityBoostItem@@XZ
// EA  : 0x82BD60C8
// RVA : 0x00BD60C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAuthorityBoostItem *__fastcall idDeclInfoTemplate<idDeclAuthorityBoostItem>::AllocDecl(
        idDeclInfoTemplate<idDeclAuthorityBoostItem> *this)
{
  idDeclAuthorityBoostItem *v1; // r3

  v1 = (idDeclAuthorityBoostItem *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x210u,
                                     tag: TAG_DECL,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAuthorityBoostItem::idDeclAuthorityBoostItem(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$504120
// EA  : 0x82BD6130
// RVA : 0x00BD6130
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504120()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAuthorityBoostItem@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD6168
// RVA : 0x00BD6168
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAuthorityBoostItem *__fastcall idDeclInfoTemplate<idDeclAuthorityBoostItem>::Alloc(
        idDeclInfoTemplate<idDeclAuthorityBoostItem> *this,
        const char *name)
{
  idDeclAuthorityBoostItem *v3; // r3
  idDeclAuthorityBoostItem *v4; // r30

  v3 = (idDeclAuthorityBoostItem *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x210u,
                                     tag: TAG_DECL,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAuthorityBoostItem::idDeclAuthorityBoostItem(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$504143
// EA  : 0x82BD61D8
// RVA : 0x00BD61D8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504143()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclThrowable@@@@UBAPAVidDeclThrowable@@XZ
// EA  : 0x82BD6210
// RVA : 0x00BD6210
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclThrowable *__fastcall idDeclInfoTemplate<idDeclThrowable>::AllocDecl(idDeclInfoTemplate<idDeclThrowable> *this)
{
  idDeclThrowable *v1; // r3

  v1 = (idDeclThrowable *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x208u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclThrowable::idDeclThrowable(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$504168
// EA  : 0x82BD6278
// RVA : 0x00BD6278
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504168()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclThrowable@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD62B0
// RVA : 0x00BD62B0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclThrowable *__fastcall idDeclInfoTemplate<idDeclThrowable>::Alloc(
        idDeclInfoTemplate<idDeclThrowable> *this,
        const char *name)
{
  idDeclThrowable *v3; // r3
  idDeclThrowable *v4; // r30

  v3 = (idDeclThrowable *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x208u,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclThrowable::idDeclThrowable(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclInventory, _name: name);
  return v4;
}


// ========================================================================
// __unwind$504191
// EA  : 0x82BD6320
// RVA : 0x00BD6320
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504191()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclCredits@@@@UBAPAVidDeclCredits@@XZ
// EA  : 0x82BD6358
// RVA : 0x00BD6358
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclCredits *__fastcall idDeclInfoTemplate<idDeclCredits>::AllocDecl(idDeclInfoTemplate<idDeclCredits> *this)
{
  idDeclCredits *v1; // r3

  v1 = (idDeclCredits *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x50u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclCredits::idDeclCredits(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$504216
// EA  : 0x82BD63C0
// RVA : 0x00BD63C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504216()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclCredits@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD63F8
// RVA : 0x00BD63F8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclCredits *__fastcall idDeclInfoTemplate<idDeclCredits>::Alloc(
        idDeclInfoTemplate<idDeclCredits> *this,
        const char *name)
{
  idDeclCredits *v3; // r3
  idDeclCredits *v4; // r30

  v3 = (idDeclCredits *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x50u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclCredits::idDeclCredits(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$504239
// EA  : 0x82BD6468
// RVA : 0x00BD6468
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504239()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclActorModifier@@@@UBAPAVidDeclActorModifier@@XZ
// EA  : 0x82BD64A0
// RVA : 0x00BD64A0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclActorModifier *__fastcall idDeclInfoTemplate<idDeclActorModifier>::AllocDecl(
        idDeclInfoTemplate<idDeclActorModifier> *this)
{
  idDeclActorModifier *v1; // r3

  v1 = (idDeclActorModifier *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x240u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclActorModifier::idDeclActorModifier(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$504264
// EA  : 0x82BD6508
// RVA : 0x00BD6508
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504264()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclActorModifier@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD6540
// RVA : 0x00BD6540
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclActorModifier *__fastcall idDeclInfoTemplate<idDeclActorModifier>::Alloc(
        idDeclInfoTemplate<idDeclActorModifier> *this,
        const char *name)
{
  idDeclActorModifier *v3; // r3
  idDeclActorModifier *v4; // r30

  v3 = (idDeclActorModifier *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x240u,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclActorModifier::idDeclActorModifier(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclInventory, _name: name);
  return v4;
}


// ========================================================================
// __unwind$504287
// EA  : 0x82BD65B0
// RVA : 0x00BD65B0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504287()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAuthorityBoostItemUpgrade@@@@UBAPAVidDeclAuthorityBoostItemUpgrade@@XZ
// EA  : 0x82BD6880
// RVA : 0x00BD6880
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAuthorityBoostItemUpgrade *__fastcall idDeclInfoTemplate<idDeclAuthorityBoostItemUpgrade>::AllocDecl(
        idDeclInfoTemplate<idDeclAuthorityBoostItemUpgrade> *this)
{
  idDeclAuthorityBoostItemUpgrade *v1; // r3

  v1 = (idDeclAuthorityBoostItemUpgrade *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x1F8u,
                                            tag: TAG_DECL,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAuthorityBoostItemUpgrade::idDeclAuthorityBoostItemUpgrade(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$504499
// EA  : 0x82BD68E8
// RVA : 0x00BD68E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504499()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAuthorityBoostItemUpgrade@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD6920
// RVA : 0x00BD6920
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAuthorityBoostItemUpgrade *__fastcall idDeclInfoTemplate<idDeclAuthorityBoostItemUpgrade>::Alloc(
        idDeclInfoTemplate<idDeclAuthorityBoostItemUpgrade> *this,
        const char *name)
{
  idDeclAuthorityBoostItemUpgrade *v3; // r3
  idDeclAuthorityBoostItemUpgrade *v4; // r30

  v3 = (idDeclAuthorityBoostItemUpgrade *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x1F8u,
                                            tag: TAG_DECL,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAuthorityBoostItemUpgrade::idDeclAuthorityBoostItemUpgrade(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$504522
// EA  : 0x82BD6990
// RVA : 0x00BD6990
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504522()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleDecalDamage@@@@UBAPAVidDeclVehicleDecalDamage@@XZ
// EA  : 0x82BD69C8
// RVA : 0x00BD69C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleDecalDamage *__fastcall idDeclInfoTemplate<idDeclVehicleDecalDamage>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleDecalDamage> *this)
{
  idDeclVehicleDecalDamage *v1; // r3

  v1 = (idDeclVehicleDecalDamage *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x50u,
                                     tag: TAG_DECL,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleDecalDamage::idDeclVehicleDecalDamage(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$504547
// EA  : 0x82BD6A30
// RVA : 0x00BD6A30
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504547()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleDecalDamage@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD6A68
// RVA : 0x00BD6A68
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleDecalDamage *__fastcall idDeclInfoTemplate<idDeclVehicleDecalDamage>::Alloc(
        idDeclInfoTemplate<idDeclVehicleDecalDamage> *this,
        const char *name)
{
  idDeclVehicleDecalDamage *v3; // r3
  idDeclVehicleDecalDamage *v4; // r30

  v3 = (idDeclVehicleDecalDamage *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x50u,
                                     tag: TAG_DECL,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleDecalDamage::idDeclVehicleDecalDamage(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$504570
// EA  : 0x82BD6AD8
// RVA : 0x00BD6AD8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504570()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclGore@@@@UBAPAVidDeclGore@@XZ
// EA  : 0x82BD6F68
// RVA : 0x00BD6F68
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclGore *__fastcall idDeclInfoTemplate<idDeclGore>::AllocDecl(idDeclInfoTemplate<idDeclGore> *this)
{
  idDeclGore *v1; // r3

  v1 = (idDeclGore *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x78u,
                       tag: TAG_DECL,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclGore::idDeclGore(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$504955
// EA  : 0x82BD6FD0
// RVA : 0x00BD6FD0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504955()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclGore@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD7008
// RVA : 0x00BD7008
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclGore *__fastcall idDeclInfoTemplate<idDeclGore>::Alloc(idDeclInfoTemplate<idDeclGore> *this, const char *name)
{
  idDeclGore *v3; // r3
  idDeclGore *v4; // r30

  v3 = (idDeclGore *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x78u,
                       tag: TAG_DECL,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclGore::idDeclGore(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$504978
// EA  : 0x82BD7078
// RVA : 0x00BD7078
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_504978()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclVehicleWindowKit@@@@UBAPAVidDeclVehicleWindowKit@@XZ
// EA  : 0x82BD70B0
// RVA : 0x00BD70B0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleWindowKit *__fastcall idDeclInfoTemplate<idDeclVehicleWindowKit>::AllocDecl(
        idDeclInfoTemplate<idDeclVehicleWindowKit> *this)
{
  idDeclVehicleWindowKit *v1; // r3

  v1 = (idDeclVehicleWindowKit *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x50u,
                                   tag: TAG_DECL,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclVehicleWindowKit::idDeclVehicleWindowKit(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$505003
// EA  : 0x82BD7118
// RVA : 0x00BD7118
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_505003()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclVehicleWindowKit@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD7150
// RVA : 0x00BD7150
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclVehicleWindowKit *__fastcall idDeclInfoTemplate<idDeclVehicleWindowKit>::Alloc(
        idDeclInfoTemplate<idDeclVehicleWindowKit> *this,
        const char *name)
{
  idDeclVehicleWindowKit *v3; // r3
  idDeclVehicleWindowKit *v4; // r30

  v3 = (idDeclVehicleWindowKit *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x50u,
                                   tag: TAG_DECL,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclVehicleWindowKit::idDeclVehicleWindowKit(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$505026
// EA  : 0x82BD71C0
// RVA : 0x00BD71C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_505026()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclDevMenuList@@@@UBAPAVidDeclDevMenuList@@XZ
// EA  : 0x82BD7560
// RVA : 0x00BD7560
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDevMenuList *__fastcall idDeclInfoTemplate<idDeclDevMenuList>::AllocDecl(
        idDeclInfoTemplate<idDeclDevMenuList> *this)
{
  idDeclDevMenuList *v1; // r3

  v1 = (idDeclDevMenuList *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x50u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclDevMenuList::idDeclDevMenuList(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$505282
// EA  : 0x82BD75C8
// RVA : 0x00BD75C8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_505282()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclDevMenuList@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD7600
// RVA : 0x00BD7600
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclDevMenuList *__fastcall idDeclInfoTemplate<idDeclDevMenuList>::Alloc(
        idDeclInfoTemplate<idDeclDevMenuList> *this,
        const char *name)
{
  idDeclDevMenuList *v3; // r3
  idDeclDevMenuList *v4; // r30

  v3 = (idDeclDevMenuList *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x50u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclDevMenuList::idDeclDevMenuList(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$505305
// EA  : 0x82BD7670
// RVA : 0x00BD7670
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_505305()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclAIPlayerInteraction@@@@UBAPAVidDeclAIPlayerInteraction@@XZ
// EA  : 0x82BD76A8
// RVA : 0x00BD76A8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIPlayerInteraction *__fastcall idDeclInfoTemplate<idDeclAIPlayerInteraction>::AllocDecl(
        idDeclInfoTemplate<idDeclAIPlayerInteraction> *this)
{
  idDeclAIPlayerInteraction *v1; // r3

  v1 = (idDeclAIPlayerInteraction *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x5Cu,
                                      tag: TAG_DECL,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclAIPlayerInteraction::idDeclAIPlayerInteraction(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$505330
// EA  : 0x82BD7710
// RVA : 0x00BD7710
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_505330()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclAIPlayerInteraction@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD7748
// RVA : 0x00BD7748
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclAIPlayerInteraction *__fastcall idDeclInfoTemplate<idDeclAIPlayerInteraction>::Alloc(
        idDeclInfoTemplate<idDeclAIPlayerInteraction> *this,
        const char *name)
{
  idDeclAIPlayerInteraction *v3; // r3
  idDeclAIPlayerInteraction *v4; // r30

  v3 = (idDeclAIPlayerInteraction *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x5Cu,
                                      tag: TAG_DECL,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclAIPlayerInteraction::idDeclAIPlayerInteraction(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$505353
// EA  : 0x82BD77B8
// RVA : 0x00BD77B8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_505353()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?AllocDecl@?$idDeclInfoTemplate@VidDeclChapter@@@@UBAPAVidDeclChapter@@XZ
// EA  : 0x82BD7B08
// RVA : 0x00BD7B08
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclChapter *__fastcall idDeclInfoTemplate<idDeclChapter>::AllocDecl(idDeclInfoTemplate<idDeclChapter> *this)
{
  idDeclChapter *v1; // r3

  v1 = (idDeclChapter *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x88u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idDeclChapter::idDeclChapter(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$505549
// EA  : 0x82BD7B70
// RVA : 0x00BD7B70
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_505549()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?Alloc@?$idDeclInfoTemplate@VidDeclChapter@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82BD7BA8
// RVA : 0x00BD7BA8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

idDeclChapter *__fastcall idDeclInfoTemplate<idDeclChapter>::Alloc(
        idDeclInfoTemplate<idDeclChapter> *this,
        const char *name)
{
  idDeclChapter *v3; // r3
  idDeclChapter *v4; // r30

  v3 = (idDeclChapter *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x88u,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDeclChapter::idDeclChapter(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idDeclTypeInfo, _name: name);
  return v4;
}


// ========================================================================
// __unwind$505572_0
// EA  : 0x82BD7C18
// RVA : 0x00BD7C18
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void _unwind_505572_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DECL);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclEntityDef@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82BD7CA0
// RVA : 0x00BD7CA0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclEntityDef>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclEntityDef::resourceList);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclOnlineScoringCallout@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82C50730
// RVA : 0x00C50730
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclOnlineScoringCallout>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(
    this: declManager,
    a2: autoComplete,
    a3: &idDeclOnlineScoringCallout::resourceList);
}


// ========================================================================
// ??$IsType@VidDeclVehicleArmorKit@@@idDecl@@QBA_NXZ
// EA  : 0x82D1F168
// RVA : 0x00D1F168
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDecl::IsType<idDeclVehicleArmorKit>(idDecl *this)
{
  idDeclInfoTemplate<idDeclVehicleArmorKit> *parent; // r3

  parent = (idDeclInfoTemplate<idDeclVehicleArmorKit> *)this->GetDeclInfo(this);
  if ( parent == nullptr )
    return 0;
  while ( parent != &idDeclVehicleArmorKit::resourceList )
  {
    parent = (idDeclInfoTemplate<idDeclVehicleArmorKit> *)parent->parent;
    if ( parent == nullptr )
      return 0;
  }
  return 1;
}


// ========================================================================
// ??$IsType@VidDeclWeapon@@@idDecl@@QBA_NXZ
// EA  : 0x82D1F1D0
// RVA : 0x00D1F1D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDecl::IsType<idDeclWeapon>(idDecl *this)
{
  idDeclInfoTemplate<idDeclWeapon> *parent; // r3

  parent = (idDeclInfoTemplate<idDeclWeapon> *)this->GetDeclInfo(this);
  if ( parent == nullptr )
    return 0;
  while ( parent != &idDeclWeapon::resourceList )
  {
    parent = (idDeclInfoTemplate<idDeclWeapon> *)parent->parent;
    if ( parent == nullptr )
      return 0;
  }
  return 1;
}


// ========================================================================
// ??$IsType@VidDeclVehicleQuickUseItem@@@idDecl@@QBA_NXZ
// EA  : 0x82D1F238
// RVA : 0x00D1F238
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDecl::IsType<idDeclVehicleQuickUseItem>(idDecl *this)
{
  idDeclInfoTemplate<idDeclVehicleQuickUseItem> *parent; // r3

  parent = (idDeclInfoTemplate<idDeclVehicleQuickUseItem> *)this->GetDeclInfo(this);
  if ( parent == nullptr )
    return 0;
  while ( parent != &idDeclVehicleQuickUseItem::resourceList )
  {
    parent = (idDeclInfoTemplate<idDeclVehicleQuickUseItem> *)parent->parent;
    if ( parent == nullptr )
      return 0;
  }
  return 1;
}


// ========================================================================
// ??$IsType@VidDeclVehicleArmor@@@idDecl@@QBA_NXZ
// EA  : 0x82D1F2E8
// RVA : 0x00D1F2E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDecl::IsType<idDeclVehicleArmor>(idDecl *this)
{
  idDeclInfoTemplate<idDeclVehicleArmor> *parent; // r3

  parent = (idDeclInfoTemplate<idDeclVehicleArmor> *)this->GetDeclInfo(this);
  if ( parent == nullptr )
    return 0;
  while ( parent != &idDeclVehicleArmor::resourceList )
  {
    parent = (idDeclInfoTemplate<idDeclVehicleArmor> *)parent->parent;
    if ( parent == nullptr )
      return 0;
  }
  return 1;
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclLayer@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82D78CF8
// RVA : 0x00D78CF8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclLayer>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclLayer::resourceList);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclDevMenuList@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82DA1FF0
// RVA : 0x00DA1FF0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclDevMenuList>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclDevMenuList::resourceList);
}


// ========================================================================
// ?CastTo@?$idDeclInfoTemplate@VidDeclWeapon@@@@QBAPBVidDeclWeapon@@PBVidDecl@@@Z
// EA  : 0x82DE3710
// RVA : 0x00DE3710
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

const idDeclAmmo *__fastcall idDeclInfoTemplate<idDeclWeapon>::CastTo(
        idDeclInfoTemplate<idDeclAmmo> *this,
        const idDecl *decl)
{
  return this != decl->GetDeclInfo(this: decl) ? nullptr : (const idDeclAmmo *)decl;
}


// ========================================================================
// ??$IsType@VidDeclVehicleWeapon@@@idDecl@@QBA_NXZ
// EA  : 0x82DE3768
// RVA : 0x00DE3768
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDecl::IsType<idDeclVehicleWeapon>(idDecl *this)
{
  idDeclInfoTemplate<idDeclVehicleWeapon> *parent; // r3

  parent = (idDeclInfoTemplate<idDeclVehicleWeapon> *)this->GetDeclInfo(this);
  if ( parent == nullptr )
    return 0;
  while ( parent != &idDeclVehicleWeapon::resourceList )
  {
    parent = (idDeclInfoTemplate<idDeclVehicleWeapon> *)parent->parent;
    if ( parent == nullptr )
      return 0;
  }
  return 1;
}


// ========================================================================
// ??$IsType@VidDeclProjectile@@@idDecl@@QBA_NXZ
// EA  : 0x82DE37D0
// RVA : 0x00DE37D0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

int __fastcall idDecl::IsType<idDeclProjectile>(idDecl *this)
{
  idDeclInfoTemplate<idDeclProjectile> *parent; // r3

  parent = (idDeclInfoTemplate<idDeclProjectile> *)this->GetDeclInfo(this);
  if ( parent == nullptr )
    return 0;
  while ( parent != &idDeclProjectile::resourceList )
  {
    parent = (idDeclInfoTemplate<idDeclProjectile> *)parent->parent;
    if ( parent == nullptr )
      return 0;
  }
  return 1;
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclParticle@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82E50770
// RVA : 0x00E50770
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclParticle>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclParticle::resourceList);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclFX@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82E50798
// RVA : 0x00E50798
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclFX>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclFX::resourceList);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclJob@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82E507C0
// RVA : 0x00E507C0
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclJob>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclJob::resourceList);
}


// ========================================================================
// ??$ArgCompletion_Decl@VidDeclAchievement@@@idDeclManager@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82E507E8
// RVA : 0x00E507E8
// PDB : w:\tech5\engine\decls\declmanager.h
// ========================================================================

void __fastcall idDeclManager::ArgCompletion_Decl<idDeclAchievement>(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclAchievement::resourceList);
}

