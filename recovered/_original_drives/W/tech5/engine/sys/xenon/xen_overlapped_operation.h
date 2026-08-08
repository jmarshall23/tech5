
// ========================================================================
// ??1OverlappedOperation@@UAA@XZ
// EA  : 0x829DE4D0
// RVA : 0x009DE4D0
// PDB : w:\tech5\engine\sys\xenon\xen_overlapped_operation.h
// ========================================================================

void __fastcall OverlappedOperation::~OverlappedOperation(OverlappedOperation *this)
{
  this->__vftable = (OverlappedOperation_vtbl *)&OverlappedOperation::`vftable';
}


// ========================================================================
// ?Cancel@OverlappedOperation@@QAAXXZ
// EA  : 0x829DE4E0
// RVA : 0x009DE4E0
// PDB : w:\tech5\engine\sys\xenon\xen_overlapped_operation.h
// ========================================================================

void __fastcall OverlappedOperation::Cancel(OverlappedOperation *this)
{
  _XOVERLAPPED *p_overlapped; // r31
  unsigned int *p_dwExtendedError; // r11
  int i; // ctr

  if ( !OverlappedOperation::HasCompleted(this) )
  {
    p_overlapped = &this->overlapped;
    if ( XCancelOverlapped(lpXOverlapped: p_overlapped) != 0 )
      idLib::Printf(fmt: "OverlappedOperation::XCancelOverlapped FAILED.\n");
    p_dwExtendedError = &p_overlapped[-1].dwExtendedError;
    for ( i = 7; i != 0; --i )
      *++p_dwExtendedError = 0;
  }
}

