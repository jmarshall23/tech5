
// ========================================================================
// ?Tell@idFile_MTP@@UBA_JXZ
// EA  : 0x82F11538
// RVA : 0x00F11538
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idFile_MTP::Tell(idFile_MTP *this)
{
  __int64 result; // r4 OVERLAPPED

  *(__int64 *)((char *)&result + 4) = this->position;
  return result;
}

