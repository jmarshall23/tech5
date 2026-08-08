#pragma once

// The portable permanent-file implementation currently comes from the BFG
// framework baseline. This compatibility include restores the original
// shared/idlib path used by tungsten sources while its wider idTech 5 layout
// is introduced incrementally at the filesystem boundary.
#include "idlib/precompiled.h"

#ifdef nullptr
#undef nullptr
#endif

inline int idFilePermanentSectorSize(const idFile_Permanent&) { return 1; }
