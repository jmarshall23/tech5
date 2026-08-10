#include "framework/buildversion.h"

#include <cstdio>

namespace {
constexpr int BUILD_MAJOR = 1683;
constexpr int BUILD_CHANGELIST = 2952;
}

idVersionInfo::idVersionInfo() : fullVersion{}, netVersion{} {
    // Xbox-specific compiler/date fragments in the dump were unresolved PDB
    // temporaries.  The stable product and network portions are authoritative.
    std::snprintf(fullVersion, sizeof(fullVersion),
        "Tungsten.%d.%d pc", BUILD_MAJOR, BUILD_CHANGELIST);
    std::snprintf(netVersion, sizeof(netVersion),
        "Tungsten.%d.%d", BUILD_MAJOR, BUILD_CHANGELIST);
}

idVersionInfo versionInfo;
