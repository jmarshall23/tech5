#pragma once

// PDB ordinal 17688 and buildversion.cpp constructor surface.
struct idVersionInfo {
    idVersionInfo();

    char fullVersion[128];
    char netVersion[128];
};

extern idVersionInfo versionInfo;

static_assert(sizeof(idVersionInfo) == 256,
    "Recovered idVersionInfo ABI changed");
