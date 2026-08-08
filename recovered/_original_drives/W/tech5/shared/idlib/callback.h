
// ========================================================================
// ??1?$idCallbackBindMem@VidMainMenu@@@@UAA@XZ
// EA  : 0x824E0270
// RVA : 0x004E0270
// PDB : w:\tech5\shared\idlib\callback.h
// ========================================================================

void __fastcall idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(idCallback *this)
{
  this->__vftable = (idCallback_vtbl *)&idCallback::`vftable';
}


// ========================================================================
// ?Call@?$idCallbackBindMemArg1@VidProfileMgr@@PAVidSaveLoadParms@@@@UAAXXZ
// EA  : 0x829BB148
// RVA : 0x009BB148
// PDB : w:\tech5\shared\idlib\callback.h
// ========================================================================

void __fastcall idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *>::Call(
        idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *> *this)
{
  this->f(this: this->t, a2: this->a1);
}


// ========================================================================
// ??$MakeCallback@VidProfileMgr@@PAVidSaveLoadParms@@@@YA?AV?$idCallbackBindMemArg1@VidProfileMgr@@PAVidSaveLoadParms@@@@PAVidProfileMgr@@P81@AAXPAVidSaveLoadParms@@@Z1@Z
// EA  : 0x829BB160
// RVA : 0x009BB160
// PDB : w:\tech5\shared\idlib\callback.h
// ========================================================================

idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *> *__fastcall MakeCallback<idProfileMgr,idSaveLoadParms *>(
        idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *> *result,
        idProfileMgr *t,
        void (__fastcall *f)(idProfileMgr *this, idSaveLoadParms *),
        idSaveLoadParms *a1)
{
  result->t = t;
  result->f = f;
  result->a1 = a1;
  result->__vftable = (idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *>_vtbl *)&idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *>::`vftable';
  return result;
}


// ========================================================================
// ?Clone@?$idCallbackBindMemArg1@VidProfileMgr@@PAVidSaveLoadParms@@@@UBAPAVidCallback@@XZ
// EA  : 0x829BB6B0
// RVA : 0x009BB6B0
// PDB : w:\tech5\shared\idlib\callback.h
// ========================================================================

idCallback *__fastcall idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *>::Clone(
        idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *> *this)
{
  idCallback *result; // r3
  idCallback_vtbl *a1; // r11
  void (__fastcall *f)(idProfileMgr *, idSaveLoadParms *); // r10
  idCallback_vtbl *t; // r8

  result = (idCallback *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x10u,
                           tag: TAG_FUNC_CALLBACK,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( result == nullptr )
    return nullptr;
  a1 = (idCallback_vtbl *)this->a1;
  f = this->f;
  t = (idCallback_vtbl *)this->t;
  result->__vftable = (idCallback_vtbl *)&idCallbackBindMemArg1<idProfileMgr,idSaveLoadParms *>::`vftable';
  result[3].__vftable = a1;
  result[2].__vftable = (idCallback_vtbl *)f;
  result[1].__vftable = t;
  return result;
}


// ========================================================================
// ??$MakeCallback@VidSessionLocal@@PAVidSaveLoadParms@@@@YA?AV?$idCallbackBindMemArg1@VidSessionLocal@@PAVidSaveLoadParms@@@@PAVidSessionLocal@@P81@AAXPAVidSaveLoadParms@@@Z1@Z
// EA  : 0x829CC038
// RVA : 0x009CC038
// PDB : w:\tech5\shared\idlib\callback.h
// ========================================================================

idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> *__fastcall MakeCallback<idSessionLocal,idSaveLoadParms *>(
        idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> *result,
        idSessionLocal *t,
        void (__fastcall *f)(idSessionLocal *this, idSaveLoadParms *),
        idSaveLoadParms *a1)
{
  result->t = t;
  result->f = f;
  result->a1 = a1;
  result->__vftable = (idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *>_vtbl *)&idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *>::`vftable';
  return result;
}


// ========================================================================
// ?Clone@?$idCallbackBindMemArg1@VidSessionLocal@@PAVidSaveLoadParms@@@@UBAPAVidCallback@@XZ
// EA  : 0x829CC6A0
// RVA : 0x009CC6A0
// PDB : w:\tech5\shared\idlib\callback.h
// ========================================================================

idCallback *__fastcall idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *>::Clone(
        idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *> *this)
{
  idCallback *result; // r3
  idCallback_vtbl *a1; // r11
  void (__fastcall *f)(idSessionLocal *, idSaveLoadParms *); // r10
  idCallback_vtbl *t; // r8

  result = (idCallback *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x10u,
                           tag: TAG_FUNC_CALLBACK,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( result == nullptr )
    return nullptr;
  a1 = (idCallback_vtbl *)this->a1;
  f = this->f;
  t = (idCallback_vtbl *)this->t;
  result->__vftable = (idCallback_vtbl *)&idCallbackBindMemArg1<idSessionLocal,idSaveLoadParms *>::`vftable';
  result[3].__vftable = a1;
  result[2].__vftable = (idCallback_vtbl *)f;
  result[1].__vftable = t;
  return result;
}


// ========================================================================
// ?Call@?$idCallbackBindMem@VidMainMenu@@@@UAAXXZ
// EA  : 0x82DBEF00
// RVA : 0x00DBEF00
// PDB : w:\tech5\shared\idlib\callback.h
// ========================================================================

void __fastcall idCallbackBindMem<idMainMenu>::Call(idCallbackBindMem<idMainMenu> *this)
{
  this->f(this: this->t);
}


// ========================================================================
// ??$MakeCallback@VidMainMenu@@@@YA?AV?$idCallbackBindMem@VidMainMenu@@@@PAVidMainMenu@@P81@AAXXZ@Z
// EA  : 0x82DBEF10
// RVA : 0x00DBEF10
// PDB : w:\tech5\shared\idlib\callback.h
// ========================================================================

idCallbackBindMem<idMainMenu> *__fastcall MakeCallback<idMainMenu>(
        idCallbackBindMem<idMainMenu> *result,
        idMainMenu *t,
        void (__fastcall *f)(idMainMenu *this))
{
  result->t = t;
  result->f = f;
  result->__vftable = (idCallbackBindMem<idMainMenu>_vtbl *)&idCallbackBindMem<idMainMenu>::`vftable';
  return result;
}


// ========================================================================
// ?Clone@?$idCallbackBindMem@VidMainMenu@@@@UBAPAVidCallback@@XZ
// EA  : 0x82DBFAB8
// RVA : 0x00DBFAB8
// PDB : w:\tech5\shared\idlib\callback.h
// ========================================================================

idCallback *__fastcall idCallbackBindMem<idMainMenu>::Clone(idCallbackBindMem<idMainMenu> *this)
{
  idCallback *result; // r3
  void (__fastcall *f)(idMainMenu *); // r11
  idCallback_vtbl *t; // r10

  result = (idCallback *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xCu,
                           tag: TAG_FUNC_CALLBACK,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( result == nullptr )
    return nullptr;
  f = this->f;
  t = (idCallback_vtbl *)this->t;
  result->__vftable = (idCallback_vtbl *)&idCallbackBindMem<idMainMenu>::`vftable';
  result[2].__vftable = (idCallback_vtbl *)f;
  result[1].__vftable = t;
  return result;
}

