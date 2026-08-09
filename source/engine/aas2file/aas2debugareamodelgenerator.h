#pragma once

#include <cstdint>

class idAAS2DebugAreaModelData;

class idAAS2DebugAreaModelGenerator {
public:
    static bool WriteToBinary(const char* uniqueIdName, const char* fileName,
        std::uint32_t sourceTimestamp,
        const idAAS2DebugAreaModelData& data);
};

static_assert(sizeof(idAAS2DebugAreaModelGenerator) == 1,
    "Recovered stateless AAS2 debug generator ABI changed");
