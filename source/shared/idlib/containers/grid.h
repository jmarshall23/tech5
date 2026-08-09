#pragma once

// Recovered Windows/Xbox large-grid region identifier.  The Windows SDK
// already owns the public LGRPID spelling on PC; its unsigned-long storage is
// the same four-byte ABI as Tungsten's recovered unsigned-int typedef.
#if defined(_WIN32)
#include <Windows.h>
#else
typedef unsigned int LGRPID;
#endif

static_assert(sizeof(LGRPID) == 4, "Recovered LGRPID ABI changed");
