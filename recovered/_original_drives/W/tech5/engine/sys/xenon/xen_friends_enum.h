
// ========================================================================
// ??1idFriendsEnum@@UAA@XZ
// EA  : 0x829DE740
// RVA : 0x009DE740
// PDB : w:\tech5\engine\sys\xenon\xen_friends_enum.h
// ========================================================================

void __fastcall idFriendsEnum::~idFriendsEnum(idFriendsEnum *this)
{
  void *resultsEnum; // r3
  unsigned __int8 *resultsBuffer; // r4

  resultsEnum = this->resultsEnum;
  this->__vftable = (idFriendsEnum_vtbl *)&idFriendsEnum::`vftable';
  if ( resultsEnum != nullptr )
  {
    CloseHandle(hObject: resultsEnum);
    this->resultsEnum = nullptr;
  }
  resultsBuffer = this->resultsBuffer;
  if ( resultsBuffer != nullptr )
  {
    idMem::Free(this: &mem, ptr: resultsBuffer, align: ALIGN_16);
    this->resultsBuffer = nullptr;
  }
  this->__vftable = (idFriendsEnum_vtbl *)&OverlappedOperation::`vftable';
}


// ========================================================================
// ?Start@idFriendsEnum@@QAA_NH@Z
// EA  : 0x829DE7C0
// RVA : 0x009DE7C0
// PDB : w:\tech5\engine\sys\xenon\xen_friends_enum.h
// ========================================================================

int __fastcall idFriendsEnum::Start(idFriendsEnum *this, unsigned int user)
{
  void **p_resultsEnum; // r31
  unsigned __int8 *v5; // r9
  void *v6; // r3
  unsigned int v7; // [sp+50h] [-30h] BYREF

  v7 = 0;
  p_resultsEnum = &this->resultsEnum;
  if ( XFriendsCreateEnumerator(
         dwUserIndex: user,
         dwStartingIndex: 0,
         dwFriendsToReturn: 0x64u,
         pcbBuffer: &v7,
         ph: &this->resultsEnum) != 0 )
    return 0;
  v5 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                            size: v7,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v6 = *p_resultsEnum;
  this->resultsBuffer = v5;
  if ( XEnumerate(hEnum: v6, pvBuffer: v5, cbBuffer: v7, pcItemsReturned: nullptr, pOverlapped: &this->overlapped) != 997 )
  {
    CloseHandle(hObject: *p_resultsEnum);
    *p_resultsEnum = nullptr;
  }
  return 1;
}

