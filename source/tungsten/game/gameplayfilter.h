#pragma once

#include "../../shared/idlib/containers/list.h"

#include <cstdint>

// Reconstructed from the retail PDB types associated with
// w:\tech5\tungsten\game\gameplayfilter.h.  The original generated header
// placed the nested types before their owner, which was useful as type
// evidence but was not valid C++.

class idGameplayFilterTarget {
public:
    void SetFlag(int index, bool flagValue);

    std::uint32_t bits;
};

class idGameplayFilter {
public:
    class Element {
    public:
        enum flagState_t : std::int32_t {
            FS_FALSE = 0,
            FS_TRUE = 1,
            FS_IGNORE = 2
        };

        enum elementType_t : std::int32_t {
            ET_AND = 0,
            ET_OR = 1
        };

        std::uint32_t desiredBits;
        std::uint32_t activeBits;
        elementType_t elementType;
    };

    idList<Element, 5> elements;
};

static_assert(sizeof(idGameplayFilterTarget) == 4,
    "Recovered idGameplayFilterTarget layout changed");
static_assert(sizeof(idGameplayFilter::Element) == 12,
    "Recovered idGameplayFilter::Element layout changed");

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idGameplayFilter) == 16,
    "Recovered idGameplayFilter Xbox 360 layout changed");
#endif
