#include "gamelib/pvs/pvs.h"

#include "idlib/lib_print.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <malloc.h>
#include <string>
#include <vector>

namespace {

int PVSBufferBytes(const int numAreas) {
    return ((numAreas + 31) >> 3) & ~3;
}

std::string ResourcePath(const char* const name) {
    std::string path = name == nullptr ? "" : name;
    const std::string::size_type slash = path.find_last_of("/\\");
    const std::string::size_type dot = path.find_last_of('.');
    if (dot == std::string::npos
            || (slash != std::string::npos && dot < slash)) {
        path += ".pvs";
    } else {
        path.replace(dot, std::string::npos, ".pvs");
    }
    return path;
}

} // namespace

idPVS::idPVS()
    : header{PVS_MAGIC, 0, 0, 0, 0, 0, 0},
      pvsName(),
      dataStart(nullptr),
      planes(nullptr),
      vertices(nullptr),
      nodes(nullptr),
      portals(nullptr),
      areas(nullptr),
      areaOffsets(nullptr),
      areaPVS(nullptr),
      currentPVS{},
      bare(false) {
    for (pvsCurrent_t& current : currentPVS) {
        current.handle.i = -1;
        current.handle.h = 0;
        current.pvs = nullptr;
    }
}

idPVS::~idPVS() {
    Free();
}

void idPVS::DecompressAddPVS(std::uint8_t* const pvs, const int numBytes,
        const std::uint8_t* compressed) {
    if (pvs == nullptr || compressed == nullptr || numBytes <= 0) {
        return;
    }

    const int numBits = numBytes * 8;
    int bit = 0;
    while (bit < numBits) {
        const std::uint8_t code = *compressed++;
        if ((code & 0x80u) != 0) {
            int skip = code & 0x3Fu;
            if ((code & 0x40u) != 0) {
                skip |= static_cast<int>(*compressed++) << 6;
            }
            bit += skip + 1;
            continue;
        }

        for (int literalBit = 0; literalBit < 7 && bit < numBits;
                ++literalBit, ++bit) {
            pvs[bit >> 3] |= static_cast<std::uint8_t>(
                ((code >> literalBit) & 1u) << (bit & 7));
        }
    }
}

int idPVS::GetPVSAreas(const idBounds& bounds, int* const outputAreas,
        const int maxAreas) const {
    if (outputAreas == nullptr || maxAreas <= 0) {
        return 0;
    }
    if (header.numNodes <= 1 || nodes == nullptr || planes == nullptr) {
        outputAreas[0] = 0;
        return 1;
    }

    int count = 0;
    std::vector<int> stack;
    stack.push_back(1);
    while (!stack.empty() && count < maxAreas) {
        const int nodeIndex = stack.back();
        stack.pop_back();
        if (nodeIndex < 0) {
            const int area = -1 - nodeIndex;
            bool duplicate = false;
            for (int index = 0; index < count; ++index) {
                duplicate |= outputAreas[index] == area;
            }
            if (!duplicate && area >= 0) {
                outputAreas[count++] = area;
            }
            continue;
        }
        if (nodeIndex == 0 || nodeIndex >= header.numNodes) {
            continue;
        }

        const pvsNode_t& node = nodes[nodeIndex];
        const int side = bounds.PlaneSide(planes[node.planeNum], 0.1f);
        if (side == 3) {
            stack.push_back(node.children[1]);
            stack.push_back(node.children[0]);
        } else {
            stack.push_back(node.children[side]);
        }
    }
    return count;
}

int idPVS::GetPVSArea(const idVec3& point) const {
    if (header.numNodes <= 1 || nodes == nullptr || planes == nullptr) {
        return 0;
    }

    int nodeIndex = 1;
    while (nodeIndex > 0) {
        if (nodeIndex >= header.numNodes) {
            return 0;
        }
        const pvsNode_t& node = nodes[nodeIndex];
        nodeIndex = node.children[
            planes[node.planeNum].Distance(point) >= 0.0f ? 0 : 1];
    }
    return nodeIndex < 0 ? -1 - nodeIndex : 0;
}

pvsHandle_t idPVS::DecodePVS(const int* const sourceAreas,
        const int numSourceAreas) const {
    if (sourceAreas == nullptr || numSourceAreas <= 0 || areaPVS == nullptr
            || areaOffsets == nullptr) {
        return {-1, 0};
    }

    unsigned int hash = 0;
    for (int index = 0; index < numSourceAreas; ++index) {
        hash ^= static_cast<unsigned int>(sourceAreas[index]);
    }

    int slot = 0;
    while (slot < 8 && currentPVS[slot].handle.i != -1) {
        ++slot;
    }
    if (slot == 8) {
        idLibPrint::Error("idPVS::AllocPVS: no free PVS left");
    }

    currentPVS[slot].handle = {slot, hash};
    const int bytes = PVSBufferBytes(header.numAreas);
    std::memset(currentPVS[slot].pvs, 0, bytes);
    for (int index = 0; index < numSourceAreas; ++index) {
        const int area = sourceAreas[index];
        if (area >= 0 && area < header.numAreas) {
            DecompressAddPVS(currentPVS[slot].pvs, bytes,
                areaPVS + areaOffsets[area]);
        }
    }
    return currentPVS[slot].handle;
}

void idPVS::FreePVS(const pvsHandle_t handle) const {
    if (handle.i >= 0 && handle.i < 8
            && currentPVS[handle.i].handle == handle) {
        currentPVS[handle.i].handle.i = -1;
        return;
    }
    idLibPrint::Error("idPVS::FreePVS: invalid handle");
}

bool idPVS::InPVS(const pvsHandle_t handle, const int* const targetAreas,
        const int numTargetAreas) const {
    if (handle.i < 0 || handle.i >= 8
            || !(currentPVS[handle.i].handle == handle)) {
        idLibPrint::Error("idPVS::InPVS: invalid handle");
    }
    if (targetAreas == nullptr || numTargetAreas <= 0) {
        return false;
    }

    const std::uint8_t* const pvs = currentPVS[handle.i].pvs;
    for (int index = 0; index < numTargetAreas; ++index) {
        const int area = targetAreas[index];
        if (area >= 0 && area < header.numAreas
                && (pvs[area >> 3] & (1u << (area & 7))) != 0) {
            return true;
        }
    }
    return false;
}

unsigned int idPVS::Alloc(const bool bareAllocation) {
    Free();
    bare = bareAllocation;

    const unsigned int coreBytes =
        static_cast<unsigned int>(header.numPlanes * sizeof(idPlane)
        + header.numNodes * sizeof(pvsNode_t)
        + header.numAreas * sizeof(int)
        + header.numPVSBytes);
    const unsigned int detailBytes = bare ? 0u : static_cast<unsigned int>(
        header.numVertices * sizeof(idVec3)
        + header.numPortals * sizeof(pvsPortal_t)
        + header.numAreas * sizeof(pvsArea_t));
    const unsigned int bytes = coreBytes + detailBytes;

    dataStart = static_cast<std::uint8_t*>(
        _aligned_malloc((std::max)(bytes, 1u), 16));
    if (dataStart == nullptr) {
        idLibPrint::Error("idPVS::Alloc: allocation failed");
    }
    std::memset(dataStart, 0, bytes);

    std::uint8_t* cursor = dataStart;
    planes = reinterpret_cast<idPlane*>(cursor);
    cursor += header.numPlanes * sizeof(idPlane);
    nodes = reinterpret_cast<pvsNode_t*>(cursor);
    cursor += header.numNodes * sizeof(pvsNode_t);
    areaOffsets = reinterpret_cast<int*>(cursor);
    cursor += header.numAreas * sizeof(int);
    areaPVS = cursor;
    cursor += header.numPVSBytes;

    if (bare) {
        vertices = nullptr;
        portals = nullptr;
        areas = nullptr;
    } else {
        vertices = reinterpret_cast<idVec3*>(cursor);
        cursor += header.numVertices * sizeof(idVec3);
        portals = reinterpret_cast<pvsPortal_t*>(cursor);
        cursor += header.numPortals * sizeof(pvsPortal_t);
        areas = reinterpret_cast<pvsArea_t*>(cursor);
    }

    const int bufferBytes = PVSBufferBytes(header.numAreas);
    for (pvsCurrent_t& current : currentPVS) {
        current.handle = {-1, 0};
        current.pvs = static_cast<std::uint8_t*>(
            _aligned_malloc((std::max)(bufferBytes, 1), 16));
        if (current.pvs == nullptr) {
            idLibPrint::Error("idPVS::Alloc: handle allocation failed");
        }
        std::memset(current.pvs, 0, bufferBytes);
    }
    return bytes;
}

void idPVS::Free() {
    if (dataStart != nullptr) {
        _aligned_free(dataStart);
        dataStart = nullptr;
    }
    planes = nullptr;
    vertices = nullptr;
    nodes = nullptr;
    portals = nullptr;
    areas = nullptr;
    areaOffsets = nullptr;
    areaPVS = nullptr;
    for (pvsCurrent_t& current : currentPVS) {
        current.handle = {-1, 0};
        if (current.pvs != nullptr) {
            _aligned_free(current.pvs);
            current.pvs = nullptr;
        }
    }
}

void idPVS::Default() {
    Free();
    header = {PVS_MAGIC, 0, 0, 0, 0, 1, 8};
    Alloc(false);
    areas[0] = {0, 0};
    areaOffsets[0] = 0;
    std::memset(areaPVS, 127, 8);
}

void idPVS::LoadResource() {
    Free();
    const std::string path = ResourcePath(pvsName.c_str());
    std::ifstream file(path, std::ios::binary);
    if (!file.read(reinterpret_cast<char*>(&header), sizeof(header))
            || header.magic != PVS_MAGIC) {
        idLibPrint::Warning("failed to open %s", path.c_str());
        Default();
        return;
    }

    const unsigned int bytes = Alloc(bare);
    if (!file.read(reinterpret_cast<char*>(dataStart), bytes)) {
        idLibPrint::Warning("%s is not a PVS file or is truncated",
            path.c_str());
        Default();
    }
}
