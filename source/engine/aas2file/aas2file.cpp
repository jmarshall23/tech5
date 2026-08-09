#include "aas2file/aas2file.h"

#include "framework/resourcelist.h"
#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/hashing/crc32.h"
#include "idlib/lib_print.h"
#include "idlib/text/lexer.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <vector>

namespace {

constexpr std::uint32_t AAS2_FILE_ID_BINARY = 0x32534141u; // "AAS2"
constexpr std::uint8_t AAS2_BINARY_MAJOR = 3;
constexpr std::uint8_t AAS2_BINARY_MINOR = 18;
constexpr std::uint8_t AAS2_BINARY_REVISION = 97;

bool ReadExact(idFile& file, void* data, const unsigned int bytes) {
    return bytes == 0 || file.Read(data, bytes) == bytes;
}

bool WriteExact(idFile& file, const void* data, const unsigned int bytes) {
    return bytes == 0 || file.Write(data, bytes) == bytes;
}

std::uint16_t ByteSwap16(const std::uint16_t value) {
    return static_cast<std::uint16_t>((value << 8) | (value >> 8));
}

std::uint32_t ByteSwap32(const std::uint32_t value) {
    return (value << 24) | ((value << 8) & 0x00FF0000u)
        | ((value >> 8) & 0x0000FF00u) | (value >> 24);
}

void Swap(std::uint16_t& value) { value = ByteSwap16(value); }
void Swap(std::int16_t& value) {
    value = static_cast<std::int16_t>(
        ByteSwap16(static_cast<std::uint16_t>(value)));
}
void Swap(std::uint32_t& value) { value = ByteSwap32(value); }
void Swap(int& value) {
    value = static_cast<int>(ByteSwap32(static_cast<std::uint32_t>(value)));
}
void Swap(float& value) {
    std::uint32_t bits = 0;
    std::memcpy(&bits, &value, sizeof(bits));
    bits = ByteSwap32(bits);
    std::memcpy(&value, &bits, sizeof(value));
}
void Swap(std::uint8_t&) {}

template<typename valueType, typename invalidType>
void Swap(idIndex<valueType, invalidType>& index) {
    valueType value = index.Get();
    Swap(value);
    index = idIndex<valueType, invalidType>(value);
}

void Swap(idVec3& value) {
    Swap(value.x); Swap(value.y); Swap(value.z);
}

void Swap(idBounds& value) { Swap(value[0]); Swap(value[1]); }

void Swap(idPlane& value) {
    Swap(value.a); Swap(value.b); Swap(value.c); Swap(value.d);
}

void Swap(idQuantizedVec3& value) {
    Swap(value.x); Swap(value.y); Swap(value.z);
}

void Swap(aas2Edge_t& value) {
    Swap(value.vertexNum[0]); Swap(value.vertexNum[1]); Swap(value.flags);
}

void Swap(aas2Reachability_t& value) {
    Swap(value.travelFlags); Swap(value.travelTime);
    Swap(value.fromAreaNum); Swap(value.toAreaNum); Swap(value.padding);
    for (int axis = 0; axis < 3; ++axis) Swap(value.start[axis]);
    for (int axis = 0; axis < 3; ++axis) Swap(value.end[axis]);
    Swap(value.areaTTOfsAndNumber); Swap(value.next); Swap(value.rev_next);
}

void Swap(aas2Area_t& value) {
    Swap(value.travelFlags); Swap(value.flags); Swap(value.numEdges);
    Swap(value.firstEdge); Swap(value.cluster); Swap(value.clusterAreaNum);
    Swap(value.obstaclePVSOffset); Swap(value.reach); Swap(value.rev_reach);
    Swap(value.firstChokePoint); Swap(value.numChokePoints);
    Swap(value.firstCover); Swap(value.numCover); Swap(value.firstTraversal);
    Swap(value.numTraversals); Swap(value.firstHintNode);
    Swap(value.numHintNodes);
}

void Swap(aas2Node_t& value) {
    Swap(value.planeNum); Swap(value.flags);
    Swap(value.children[0]); Swap(value.children[1]);
}

void Swap(aas2Portal_t& value) {
    Swap(value.areaNum); Swap(value.clusters[0]); Swap(value.clusters[1]);
    Swap(value.clusterAreaNum[0]); Swap(value.clusterAreaNum[1]);
    Swap(value.maxAreaTravelTime);
}

void Swap(aas2Cluster_t& value) {
    Swap(value.numAreas); Swap(value.numReachableAreas);
    Swap(value.numPortals); Swap(value.firstPortal);
}

void Swap(aas2Name_t& value) { Swap(value.index); }
void Swap(aas2AnimName_t&) {}
void Swap(aas2DependencyName_t&) {}
void Swap(aas2InteractionEntityName_t&) {}
void Swap(aas2TraversalEntityName_t&) {}

void Swap(aas2Cover_t& value) {
    Swap(value.origin); Swap(value.dir); Swap(value.areaNum);
    Swap(value.flags); Swap(value.numTouching); Swap(value.firstTouching);
    Swap(value.durationSec); Swap(value.minRange); Swap(value.maxRange);
    Swap(value.reservedBy); Swap(value.usableTime);
}

void Swap(aas2Traversal_t& value) {
    Swap(value.startPoint); Swap(value.endPoint); Swap(value.orientationFwd);
    Swap(value.extrusionFwd); Swap(value.animIndex);
    Swap(value.reachabilityIndex); Swap(value.dependencyIndex);
    Swap(value.interactionEntIndex); Swap(value.extrusionDistance);
    Swap(value.startAreaNum); Swap(value.endAreaNum);
    Swap(value.traversalNameIndex); Swap(value.flags);
}

void Swap(aas2HintNode_t& value) {
    Swap(value.origin); Swap(value.areaNum); Swap(value.radius);
    Swap(value.hintData);
}

void Swap(idAAS2File::bspTree_t& value) {
    Swap(value.floorNormal); Swap(value.headNode);
    Swap(value.firstArea); Swap(value.lastArea);
}

void Swap(aas2AreaBounds_t& value) {
    for (int axis = 0; axis < 3; ++axis) Swap(value.min[axis]);
    for (int axis = 0; axis < 3; ++axis) Swap(value.max[axis]);
}

bool ReadEndianString(idFile& file, idStr& string,
        const bool byteSwap) {
    std::uint32_t count = 0;
    if (!ReadExact(file, &count, sizeof(count))) return false;
    if (byteSwap) Swap(count);
    if (count > 16u * 1024u * 1024u) return false;
    if (count == 0) {
        string.Clear();
        return true;
    }
    char* text = static_cast<char*>(std::malloc(count + 1u));
    if (text == nullptr) return false;
    const bool result = ReadExact(file, text, count);
    if (result) {
        text[count] = '\0';
        string = text;
    }
    std::free(text);
    return result;
}

bool ReadBinarySettings(idFile& file, idAAS2Settings& settings,
        const bool byteSwap) {
    int storedType = 0;
    if (!ReadExact(file, &storedType, 4)) return false;
    if (byteSwap) Swap(storedType);
    if (!ReadEndianString(file, settings.fileExtensionAAS, byteSwap)
        || !ReadEndianString(file, settings.groupName, byteSwap)
        || !ReadEndianString(file, settings.explicitGroupName, byteSwap)) {
        return false;
    }
    settings.type = static_cast<idAAS2Settings::type_t>(storedType);
    void* blocks[] = {
        &settings.boundingBox, &settings.primitiveModeBrush,
        &settings.primitiveModePatch, &settings.primitiveModeModel,
        &settings.gravityDir, &settings.gravityValue,
        &settings.maxStepHeight, &settings.maxBarrierHeight,
        &settings.maxWaterJumpHeight, &settings.maxFallHeight,
        &settings.minFloorCos, &settings.minHighCeiling,
        &settings.groundSpeed, &settings.waterSpeed, &settings.ladderSpeed,
        &settings.wallCornerEdgeRadius, &settings.ledgeCornerEdgeRadius,
        &settings.obstaclePVSRadius, &settings.minCrouchingCoverHeight,
        &settings.minStandingCoverHeight, &settings.obstaclePVSRadius,
        &settings.standingFireHeight, &settings.minWallWidth,
        &settings.maxWallWidth, &settings.minDoorWidth,
        &settings.maxDoorWidth, &settings.coverCornerDistance,
        &settings.coverWallDistance, &settings.chokePointWidth,
        &settings.tt_barrierJump, &settings.tt_waterJump,
        &settings.tt_startWalkOffLedge, &settings.tt_startLadderClimb
    };
    const unsigned int sizes[] = {
        24, 4, 4, 4, 12, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    };
    for (unsigned int index = 0;
            index < sizeof(sizes) / sizeof(sizes[0]); ++index) {
        if (!ReadExact(file, blocks[index], sizes[index])) return false;
        if (byteSwap) {
            std::uint32_t* words = static_cast<std::uint32_t*>(blocks[index]);
            for (unsigned int word = 0; word < sizes[index] / 4; ++word) {
                words[word] = ByteSwap32(words[word]);
            }
        }
    }
    return true;
}

template<typename type, int tag>
bool ReadList(idFile& file, idList<type, tag>& list,
        const bool byteSwap = false) {
    int count = 0;
    if (!ReadExact(file, &count, sizeof(count))) return false;
    if (byteSwap) Swap(count);
    if (count < 0
        || count > 0x10000000 / (std::max)(1, int(sizeof(type)))) {
        return false;
    }
    if (!list.SetNum(count)) {
        return false;
    }
    if (!ReadExact(file, list.Ptr(),
            static_cast<unsigned int>(count * sizeof(type)))) return false;
    if (byteSwap) {
        for (int index = 0; index < count; ++index) Swap(list[index]);
    }
    return true;
}

template<typename type, int tag>
bool WriteList(idFile& file, const idList<type, tag>& list) {
    const int count = list.Num();
    return WriteExact(file, &count, sizeof(count))
        && WriteExact(file, list.Ptr(),
            static_cast<unsigned int>(count * sizeof(type)));
}

template<typename indexType, typename nameType, int tag>
indexType FindNameIndex(const idList<nameType, tag>& names,
        const char* name) {
    if (name == nullptr) {
        return indexType();
    }
    for (int index = 0; index < names.Num(); ++index) {
        if (_stricmp(name, names[index].name) == 0) {
            return indexType(static_cast<short>(index));
        }
    }
    return indexType();
}

bool IsValidArea(const idList<aas2Area_t, 37>& areas, const int areaNum) {
    return areaNum > 0 && areaNum < areas.Num();
}

idBounds ClearedBounds() {
    idBounds result;
    const float maximum = (std::numeric_limits<float>::max)();
    result[0].Set(maximum, maximum, maximum);
    result[1].Set(-maximum, -maximum, -maximum);
    return result;
}

void AddPoint(idBounds& bounds, const idVec3& point) {
    for (int axis = 0; axis < 3; ++axis) {
        bounds[0][axis] = (std::min)(bounds[0][axis], point[axis]);
        bounds[1][axis] = (std::max)(bounds[1][axis], point[axis]);
    }
}

bool Intersects(const idBounds& left, const idBounds& right) {
    for (int axis = 0; axis < 3; ++axis) {
        if (left[1][axis] < right[0][axis]
            || left[0][axis] > right[1][axis]) {
            return false;
        }
    }
    return true;
}

bool Contains(const idBounds& bounds, const idVec3& point) {
    for (int axis = 0; axis < 3; ++axis) {
        if (point[axis] < bounds[0][axis] || point[axis] > bounds[1][axis]) {
            return false;
        }
    }
    return true;
}

std::uint32_t CanonicalXboxAreaChecksum(
        const idList<aas2Area_t, 37>& areas) {
    if (areas.Num() == 0) return CRC32_BlockChecksum(nullptr, 0);
    std::vector<aas2Area_t> bigEndianAreas(areas.Ptr(),
        areas.Ptr() + areas.Num());
    for (aas2Area_t& area : bigEndianAreas) Swap(area);
    return CRC32_BlockChecksum(bigEndianAreas.data(),
        static_cast<int>(bigEndianAreas.size() * sizeof(aas2Area_t)));
}

} // namespace

idTypedResourceList<idAAS2File> idAAS2File::resourceList("aas");

aas2Cover_t::aas2Cover_t()
    : origin(), dir(), areaNum(0), flags(0), numTouching(0),
      firstTouching(0), durationSec(-1.0f), minRange(0.0f), maxRange(0.0f),
      reservedBy(0x1FFF), usableTime(0) {
    origin.Zero();
    dir.Zero();
}

aas2Traversal_t::aas2Traversal_t()
    : startPoint(), endPoint(), orientationFwd(), extrusionFwd(),
      animIndex(), reachabilityIndex(), dependencyIndex(),
      interactionEntIndex(), extrusionDistance(0), startAreaNum(0),
      endAreaNum(-1), traversalNameIndex(0), flags(0) {
    startPoint.Zero();
    endPoint.Zero();
    const idVec3 zero(0.0f, 0.0f, 0.0f);
    orientationFwd.Set(zero);
    extrusionFwd.Set(zero);
    animIndex.Invalidate();
    reachabilityIndex.Invalidate();
    dependencyIndex = idIndex<short, invalidAASDependencyIndex_t>(0);
    interactionEntIndex.Invalidate();
}

void aas2Traversal_t::Clear() {
    startPoint.Zero();
    endPoint.Zero();
    const idVec3 zero(0.0f, 0.0f, 0.0f);
    orientationFwd.Set(zero);
    extrusionFwd.Set(zero);
    animIndex.Invalidate();
    reachabilityIndex.Invalidate();
    dependencyIndex.Invalidate();
    interactionEntIndex.Invalidate();
    extrusionDistance = 0;
    startAreaNum = 0;
    endAreaNum = 0;
    traversalNameIndex.Invalidate();
    flags = 0;
}

void aas2Traversal_t::CalcExtrusionPoint(idVec3& extrusionPoint,
        const idVec3&) const {
    extrusionPoint = startPoint;
    if (extrusionDistance > 0) {
        extrusionPoint = extrusionPoint
            + extrusionFwd.ToVec3() * static_cast<float>(extrusionDistance);
    }
}

aas2HintNode_t::aas2HintNode_t()
    : origin(), areaNum(0), radius(128), hintType(HINT_NODE_TYPE_SEARCH_AUTO),
      orientation(0), dirFlags(0), grouping(0), hintData(0) {
    origin.Zero();
}

void aas2HintNode_t::GetOrientationVector(idVec3& direction) const {
    const float yaw = static_cast<float>(orientation) * 1.4117647f;
    const float radians = yaw * 0.01745329251994329577f;
    direction.Set(std::cos(radians), std::sin(radians), 0.0f);
}

aas2Area_t::aas2Area_t()
    : travelFlags(0), flags(0), numEdges(0), firstEdge(0), cluster(0),
      clusterAreaNum(0), obstaclePVSOffset(0), reach(), rev_reach(),
      firstChokePoint(0), numChokePoints(0), firstCover(0), numCover(0),
      firstTraversal(0), numTraversals(0), firstHintNode(0), numHintNodes(0) {
    // The textual loader builds these chains explicitly; zero is the exact
    // value materialized by the recovered constructor.
    reach = idIndex<short, invalidReachability_t>(0);
    rev_reach = idIndex<short, invalidReachability_t>(0);
}

idAAS2Settings::idAAS2Settings()
    : type(AAS_MAX), fileExtensionAAS("defaulted"), groupName("aas"),
      explicitGroupName("defaulted"), boundingBox(),
      primitiveModeBrush(AAS_PRIMITIVE_MODE_DEFAULT),
      primitiveModePatch(AAS_PRIMITIVE_MODE_NEVER),
      primitiveModeModel(AAS_PRIMITIVE_MODE_NEVER),
      gravityDir(0.0f, 0.0f, -1.0f), gravityValue(1066.0f),
      maxStepHeight(14.0f), maxBarrierHeight(32.0f),
      maxWaterJumpHeight(20.0f), maxFallHeight(64.0f), minFloorCos(0.7f),
      minHighCeiling(80.0f), groundSpeed(250.0f), waterSpeed(150.0f),
      ladderSpeed(50.0f), wallCornerEdgeRadius(16.0f),
      ledgeCornerEdgeRadius(16.0f), obstaclePVSRadius(1024.0f),
      wallCornerReachabilityBackoff(0.0f),
      highQualityReachabilityBackoff(0.0f),
      minCrouchingCoverHeight(32.0f), minStandingCoverHeight(64.0f),
      crouchingFireHeight(48.0f), standingFireHeight(72.0f),
      minWallWidth(8.0f), maxWallWidth(32.0f), minDoorWidth(32.0f),
      maxDoorWidth(80.0f), coverCornerDistance(8.0f),
      coverWallDistance(8.0f), chokePointWidth(96.0f),
      tt_barrierJump(100), tt_waterJump(100),
      tt_startWalkOffLedge(100), tt_startLadderClimb(100) {
    boundingBox[0].Set(-16.0f, -16.0f, 0.0f);
    boundingBox[1].Set(16.0f, 16.0f, 96.0f);
}

bool idAAS2Settings::ParseInt(idLexer& source, int& value) {
    if (!source.ExpectTokenString("=")) return false;
    value = source.ParseInt();
    return !source.HadError();
}

bool idAAS2Settings::ParseFloat(idLexer& source, float& value) {
    if (!source.ExpectTokenString("=")) return false;
    value = source.ParseFloat();
    return !source.HadError();
}

bool idAAS2Settings::ParseVector(idLexer& source, idVec3& vector) {
    return source.ExpectTokenString("=")
        && source.Parse1DMatrix(3, &vector.x, false);
}

bool idAAS2Settings::ParseBounds(idLexer& source, idBounds& bounds) {
    return source.ExpectTokenString("=")
        && source.Parse1DMatrix(3, &bounds[0].x, false)
        && source.ExpectTokenString("-")
        && source.Parse1DMatrix(3, &bounds[1].x, false);
}

bool idAAS2Settings::ValidForBounds(const idBounds& bounds) const {
    for (int axis = 0; axis < 3; ++axis) {
        if (bounds[0][axis] < boundingBox[0][axis]
            || bounds[1][axis] > boundingBox[1][axis]) {
            return false;
        }
    }
    return true;
}

bool idAAS2Settings::ReadFromFile(idLexer& source) {
    if (!source.ExpectTokenString("{")) return false;
    idToken token;
    while (source.ReadToken(token)) {
        const char* const key = token.c_str();
        if (std::strcmp(key, "}") == 0) return true;

        if (std::strcmp(key, "type") == 0) {
            int parsed = static_cast<int>(type);
            if (!ParseInt(source, parsed)) return false;
            type = static_cast<type_t>(parsed);
        } else if (std::strcmp(key, "mMaterial") == 0) {
            idToken ignored;
            if (!source.ExpectTokenString("=") || !source.ReadToken(ignored)) return false;
        } else if (std::strcmp(key, "groupName") == 0
            || std::strcmp(key, "explicitGroupName") == 0) {
            idToken text;
            if (!source.ExpectTokenString("=") || !source.ReadToken(text)) return false;
            (key[0] == 'g' ? groupName : explicitGroupName) = text.c_str();
        } else if (std::strcmp(key, "bbox") == 0) {
            if (!ParseBounds(source, boundingBox)) return false;
        } else if (std::strcmp(key, "primitiveModeBrush") == 0) {
            if (!ParseInt(source, primitiveModeBrush)) return false;
        } else if (std::strcmp(key, "primitiveModePatch") == 0) {
            if (!ParseInt(source, primitiveModePatch)) return false;
        } else if (std::strcmp(key, "primitiveModeModel") == 0) {
            if (!ParseInt(source, primitiveModeModel)) return false;
        } else if (std::strcmp(key, "gravity") == 0) {
            if (!ParseVector(source, gravityDir)) return false;
        } else if (std::strcmp(key, "gravityValue") == 0) {
            if (!ParseFloat(source, gravityValue)) return false;
        } else if (std::strcmp(key, "maxStepHeight") == 0) {
            if (!ParseFloat(source, maxStepHeight)) return false;
        } else if (std::strcmp(key, "maxBarrierHeight") == 0) {
            if (!ParseFloat(source, maxBarrierHeight)) return false;
        } else if (std::strcmp(key, "maxWaterJumpHeight") == 0) {
            if (!ParseFloat(source, maxWaterJumpHeight)) return false;
        } else if (std::strcmp(key, "maxFallHeight") == 0) {
            if (!ParseFloat(source, maxFallHeight)) return false;
        } else if (std::strcmp(key, "minFloorCos") == 0) {
            if (!ParseFloat(source, minFloorCos)) return false;
        } else if (std::strcmp(key, "minHighCeiling") == 0) {
            if (!ParseFloat(source, minHighCeiling)) return false;
        } else if (std::strcmp(key, "groundSpeed") == 0) {
            if (!ParseFloat(source, groundSpeed)) return false;
        } else if (std::strcmp(key, "waterSpeed") == 0) {
            if (!ParseFloat(source, waterSpeed)) return false;
        } else if (std::strcmp(key, "ladderSpeed") == 0) {
            if (!ParseFloat(source, ladderSpeed)) return false;
        } else if (std::strcmp(key, "wallCornerEdgeRadius") == 0) {
            if (!ParseFloat(source, wallCornerEdgeRadius)) return false;
        } else if (std::strcmp(key, "ledgeCornerEdgeRadius") == 0) {
            if (!ParseFloat(source, ledgeCornerEdgeRadius)) return false;
        } else if (std::strcmp(key, "obstaclePVSRadius") == 0) {
            if (!ParseFloat(source, obstaclePVSRadius)) return false;
        } else if (std::strcmp(key, "wallCornerReachabilityBackoff") == 0) {
            if (!ParseFloat(source, wallCornerReachabilityBackoff)) return false;
        } else if (std::strcmp(key, "highQualityReachabilityBackoff") == 0) {
            if (!ParseFloat(source, highQualityReachabilityBackoff)) return false;
        } else if (std::strcmp(key, "minCrouchingCoverHeight") == 0) {
            if (!ParseFloat(source, minCrouchingCoverHeight)) return false;
        } else if (std::strcmp(key, "minStandingCoverHeight") == 0) {
            if (!ParseFloat(source, minStandingCoverHeight)) return false;
        } else if (std::strcmp(key, "crouchingFireHeight") == 0) {
            if (!ParseFloat(source, crouchingFireHeight)) return false;
        } else if (std::strcmp(key, "standingFireHeight") == 0) {
            if (!ParseFloat(source, standingFireHeight)) return false;
        } else if (std::strcmp(key, "minWallWidth") == 0) {
            if (!ParseFloat(source, minWallWidth)) return false;
        } else if (std::strcmp(key, "maxWallWidth") == 0) {
            if (!ParseFloat(source, maxWallWidth)) return false;
        } else if (std::strcmp(key, "minDoorWidth") == 0) {
            if (!ParseFloat(source, minDoorWidth)) return false;
        } else if (std::strcmp(key, "maxDoorWidth") == 0) {
            if (!ParseFloat(source, maxDoorWidth)) return false;
        } else if (std::strcmp(key, "coverCornerDistance") == 0) {
            if (!ParseFloat(source, coverCornerDistance)) return false;
        } else if (std::strcmp(key, "coverWallDistance") == 0) {
            if (!ParseFloat(source, coverWallDistance)) return false;
        } else if (std::strcmp(key, "chokePointWidth") == 0) {
            if (!ParseFloat(source, chokePointWidth)) return false;
        } else if (std::strcmp(key, "tt_barrierJump") == 0) {
            if (!ParseInt(source, tt_barrierJump)) return false;
        } else if (std::strcmp(key, "tt_waterJump") == 0) {
            if (!ParseInt(source, tt_waterJump)) return false;
        } else if (std::strcmp(key, "tt_startWalkOffLedge") == 0) {
            if (!ParseInt(source, tt_startWalkOffLedge)) return false;
        } else if (std::strcmp(key, "tt_startLadderClimb") == 0) {
            if (!ParseInt(source, tt_startLadderClimb)) return false;
        } else {
            source.Error("invalid token '%s'", key);
            return false;
        }
    }
    return false;
}

bool idAAS2Settings::WriteToFileBinary(idFile& file) const {
    const int storedType = static_cast<int>(type);
    if (!WriteExact(file, &storedType, 4)
        || file.WriteString(fileExtensionAAS) == 0
        || file.WriteString(groupName) == 0
        || file.WriteString(explicitGroupName) == 0) {
        return false;
    }
    const void* blocks[] = {
        &boundingBox, &primitiveModeBrush, &primitiveModePatch,
        &primitiveModeModel, &gravityDir, &gravityValue, &maxStepHeight,
        &maxBarrierHeight, &maxWaterJumpHeight, &maxFallHeight, &minFloorCos,
        &minHighCeiling, &groundSpeed, &waterSpeed, &ladderSpeed,
        &wallCornerEdgeRadius, &ledgeCornerEdgeRadius, &obstaclePVSRadius,
        &minCrouchingCoverHeight, &minStandingCoverHeight,
        &obstaclePVSRadius, &standingFireHeight, &minWallWidth, &maxWallWidth,
        &minDoorWidth, &maxDoorWidth, &coverCornerDistance,
        &coverWallDistance, &chokePointWidth, &tt_barrierJump, &tt_waterJump,
        &tt_startWalkOffLedge, &tt_startLadderClimb
    };
    const unsigned int sizes[] = {
        24, 4, 4, 4, 12, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    };
    for (unsigned int index = 0; index < sizeof(sizes) / sizeof(sizes[0]); ++index) {
        if (!WriteExact(file, blocks[index], sizes[index])) return false;
    }
    return true;
}

bool idAAS2Settings::ReadFromFileBinary(idFile& file) {
    return ReadBinarySettings(file, *this, false);
}

idAAS2File::idAAS2File()
    : crc(0), timestamp(0), visitedAreas(0), settings(), major(0), minor(0),
      firstFakeVertex(0), firstFakeEdge(0), firstFakeEdgeIndex(0),
      firstFakeArea(0), trees(0), planes(0), vertices(0), edges(0),
      edgeIndex(0), reachabilities(0), areas(0), nodes(0), portals(0),
      portalIndex(0), clusters(0), obstaclePVS(0), reachabilityNames(0),
      animNames(0), dependencyNames(0), interactionEntityNames(0),
      traversalEntityNames(0), cover(0), areaCoverIndex(0),
      touchingCoverIndex(0), chokePoints(0), traversalPoints(0),
      hintNodes(0), areaBounds(0) {
}

idAAS2File::~idAAS2File() = default;

idResourceList* idAAS2File::GetResourceList() { return &resourceList; }

void idAAS2File::Clear() {
    crc = timestamp = 0;
    firstFakeVertex = firstFakeEdge = firstFakeEdgeIndex = firstFakeArea = 0;
    visitedAreas.Clear();
    trees.Clear(); planes.Clear(); vertices.Clear(); edges.Clear();
    edgeIndex.Clear(); reachabilities.Clear(); areas.Clear(); nodes.Clear();
    portals.Clear(); portalIndex.Clear(); clusters.Clear(); obstaclePVS.Clear();
    reachabilityNames.Clear(); animNames.Clear(); dependencyNames.Clear();
    interactionEntityNames.Clear(); cover.Clear();
    areaCoverIndex.Clear(); touchingCoverIndex.Clear(); chokePoints.Clear();
    traversalPoints.Clear(); hintNodes.Clear();
}

void idAAS2File::MakeDefault() {
    Clear();

    // This is the exact five-plane, one-area fallback BSP materialized by
    // the recovered executable.  Index zero is deliberately reserved in
    // the edge, area, node, portal, cluster, cover, and traversal tables.
    planes.Append(idPlane(0.0f, -1.0f, 0.0f, 32768.0f));
    planes.Append(idPlane(1.0f, 0.0f, 0.0f, 32768.0f));
    planes.Append(idPlane(1.0f, 0.0f, 0.0f, -32768.0f));
    planes.Append(idPlane(0.0f, -1.0f, 0.0f, -32768.0f));
    planes.Append(idPlane(0.0f, 0.0f, 1.0f, 32768.0f));

    vertices.Append(idVec3(-32768.0f, -32768.0f, -32768.0f));
    vertices.Append(idVec3(-32768.0f, 32768.0f, -32768.0f));
    vertices.Append(idVec3(32768.0f, 32768.0f, -32768.0f));
    vertices.Append(idVec3(32768.0f, -32768.0f, -32768.0f));

    edges.Append(aas2Edge_t{ { 0, 0 }, 0 });
    edges.Append(aas2Edge_t{ { 0, 1 }, AAS_EDGE_WALL });
    edges.Append(aas2Edge_t{ { 1, 2 }, AAS_EDGE_WALL });
    edges.Append(aas2Edge_t{ { 2, 3 }, AAS_EDGE_WALL });
    edges.Append(aas2Edge_t{ { 3, 0 }, AAS_EDGE_WALL });
    edgeIndex.Append(1);
    edgeIndex.Append(2);
    edgeIndex.Append(3);
    edgeIndex.Append(4);

    areas.SetNum(2);
    areas[0] = aas2Area_t();
    areas[1].numEdges = 4;
    areas[1].firstEdge = 0;
    areas[1].travelFlags = AAS_TFL_AIR;
    areas[1].flags = AAS_AREA_REACHABLE_WALK | AAS_AREA_OUTSIDE
        | AAS_AREA_HIGH_CEILING;
    areas[1].cluster = 1;
    areas[1].clusterAreaNum = 0;
    areas[1].obstaclePVSOffset = 1;
    areas[1].reach.Invalidate();
    areas[1].rev_reach.Invalidate();

    nodes.Append(aas2Node_t{ 0, 0, { 0, 0 } });
    nodes.Append(aas2Node_t{ 0, 0, { 2, 0 } });
    nodes.Append(aas2Node_t{ 1, 0, { 3, 0 } });
    nodes.Append(aas2Node_t{ 2, 0, { 0, 4 } });
    nodes.Append(aas2Node_t{ 3, 0, { 0, 5 } });
    nodes.Append(aas2Node_t{ 4, 0xFFFFFFFFu, { -1, 0 } });

    portals.Append(aas2Portal_t{});
    clusters.Append(aas2Cluster_t{ 0, 0, 0, 0 });
    clusters.Append(aas2Cluster_t{ 1, 1, 0, 0 });
    obstaclePVS.Append(1);
    obstaclePVS.Append(2);

    trees.SetNum(1);
    trees[0].floorNormal.Set(0.0f, 0.0f, 1.0f);
    trees[0].headNode = 1;
    trees[0].firstArea = 1;
    trees[0].lastArea = 2;

    cover.Alloc();
    traversalPoints.Alloc();
}

unsigned int idAAS2File::MemorySize() const {
    return 4u * (4u * (2u * reachabilities.NumAllocated()
            + clusters.NumAllocated() + nodes.NumAllocated()
            + planes.NumAllocated())
        + 3u * (portals.NumAllocated() + edges.NumAllocated()
            + vertices.NumAllocated())
        + 14u * cover.NumAllocated() + 10u * areas.NumAllocated()
        + touchingCoverIndex.NumAllocated() + areaCoverIndex.NumAllocated()
        + portalIndex.NumAllocated() + edgeIndex.NumAllocated() + 67u)
        + obstaclePVS.NumAllocated();
}

bool idAAS2File::LoadBinary(const char* const fileName,
        const char* const binaryFileName,
        const std::uint32_t mapFileCRC,
        const std::uint32_t sourceTimestamp) {
    idFileLocal file(fileSystem->OpenFileRead(binaryFileName, true, false));
    if (file.file == nullptr) return false;

    std::uint32_t magic = 0;
    std::uint8_t version[3] = {};
    std::uint32_t storedTimestamp = 0;
    std::uint32_t storedCRC = 0;
    if (!ReadExact(*file.file, &magic, 4)) return false;
    const bool byteSwap = magic != AAS2_FILE_ID_BINARY
        && ByteSwap32(magic) == AAS2_FILE_ID_BINARY;
    if ((!byteSwap && magic != AAS2_FILE_ID_BINARY)
        || !ReadExact(*file.file, version, 3)
        || version[0] != AAS2_BINARY_MAJOR
        || version[1] != AAS2_BINARY_MINOR
        || version[2] != AAS2_BINARY_REVISION
        || !ReadExact(*file.file, &storedTimestamp, 4)) {
        return false;
    }
    if (byteSwap) Swap(storedTimestamp);
    if ((sourceTimestamp != 0 && sourceTimestamp != std::uint32_t(-1)
            && sourceTimestamp != storedTimestamp)
        || !ReadExact(*file.file, &storedCRC, 4)) return false;
    if (byteSwap) Swap(storedCRC);
    if (storedCRC != mapFileCRC) return false;

    Clear();
    major = AAS2_BINARY_MAJOR;
    minor = AAS2_BINARY_MINOR;
    timestamp = sourceTimestamp;
    crc = mapFileCRC;
    if (!ReadExact(*file.file, &firstFakeVertex, 4)
        || !ReadExact(*file.file, &firstFakeEdge, 4)
        || !ReadExact(*file.file, &firstFakeEdgeIndex, 4)
        || !ReadExact(*file.file, &firstFakeArea, 4)) {
        return false;
    }
    if (byteSwap) {
        Swap(firstFakeVertex); Swap(firstFakeEdge);
        Swap(firstFakeEdgeIndex); Swap(firstFakeArea);
    }
    if (!ReadBinarySettings(*file.file, settings, byteSwap)
        || !ReadList(*file.file, planes, byteSwap)
        || !ReadList(*file.file, vertices, byteSwap)
        || !ReadList(*file.file, edges, byteSwap)
        || !ReadList(*file.file, edgeIndex, byteSwap)
        || !ReadList(*file.file, reachabilities, byteSwap)
        || !ReadList(*file.file, areas, byteSwap)
        || !ReadList(*file.file, nodes, byteSwap)
        || !ReadList(*file.file, portals, byteSwap)
        || !ReadList(*file.file, portalIndex, byteSwap)
        || !ReadList(*file.file, clusters, byteSwap)
        || !ReadList(*file.file, obstaclePVS, byteSwap)
        || !ReadList(*file.file, reachabilityNames, byteSwap)
        || !ReadList(*file.file, animNames, byteSwap)
        || !ReadList(*file.file, dependencyNames, byteSwap)
        || !ReadList(*file.file, interactionEntityNames, byteSwap)
        || !ReadList(*file.file, traversalEntityNames, byteSwap)
        || !ReadList(*file.file, cover, byteSwap)
        || !ReadList(*file.file, areaCoverIndex, byteSwap)
        || !ReadList(*file.file, touchingCoverIndex, byteSwap)
        || !ReadList(*file.file, traversalPoints, byteSwap)
        || !ReadList(*file.file, hintNodes, byteSwap)
        || !ReadList(*file.file, trees, byteSwap)
        || !ReadList(*file.file, areaBounds, byteSwap)) {
        Clear();
        return false;
    }
    FlagNoPushAreas();
    for (int tree = 0; tree < trees.Num(); ++tree) {
        if (MaxTreeDepth(tree) > 128) {
            MakeDefault();
            return false;
        }
    }

    // Shipping-data corrections present verbatim in the recovered loader.
    // They are keyed by both map name and the complete area-table checksum,
    // so unrelated or regenerated AAS data cannot accidentally receive them.
    const std::uint32_t areaChecksum = CanonicalXboxAreaChecksum(areas);
    if (fileName != nullptr && std::strstr(fileName, "ghost_hideout") != nullptr
        && areaChecksum == 0xF7C91972u && areas.Num() > 1271) {
        areas[1271].travelFlags |= AAS_TFL_INVALID;
    } else if (fileName != nullptr
        && std::strstr(fileName, "wellspring_coop") != nullptr
        && areaChecksum == 0x2A1D82D3u && areas.Num() > 79) {
        areas[79].flags |= AAS_AREA_NOPUSH;
    }
    return true;
}

bool idAAS2File::WriteBinary(const char*, const char* const binaryFileName,
        const std::uint32_t mapFileCRC,
        const std::uint32_t sourceTimestamp) {
    ResetCover();
    idFileLocal file(fileSystem->OpenFileWrite(binaryFileName, FSPATH_BASE));
    if (file.file == nullptr) return false;
    const std::uint8_t version[] = {
        AAS2_BINARY_MAJOR, AAS2_BINARY_MINOR, AAS2_BINARY_REVISION
    };
    return WriteExact(*file.file, &AAS2_FILE_ID_BINARY, 4)
        && WriteExact(*file.file, version, 3)
        && WriteExact(*file.file, &sourceTimestamp, 4)
        && WriteExact(*file.file, &mapFileCRC, 4)
        && WriteExact(*file.file, &firstFakeVertex, 4)
        && WriteExact(*file.file, &firstFakeEdge, 4)
        && WriteExact(*file.file, &firstFakeEdgeIndex, 4)
        && WriteExact(*file.file, &firstFakeArea, 4)
        && settings.WriteToFileBinary(*file.file)
        && WriteList(*file.file, planes)
        && WriteList(*file.file, vertices)
        && WriteList(*file.file, edges)
        && WriteList(*file.file, edgeIndex)
        && WriteList(*file.file, reachabilities)
        && WriteList(*file.file, areas)
        && WriteList(*file.file, nodes)
        && WriteList(*file.file, portals)
        && WriteList(*file.file, portalIndex)
        && WriteList(*file.file, clusters)
        && WriteList(*file.file, obstaclePVS)
        && WriteList(*file.file, reachabilityNames)
        && WriteList(*file.file, animNames)
        && WriteList(*file.file, dependencyNames)
        && WriteList(*file.file, interactionEntityNames)
        && WriteList(*file.file, traversalEntityNames)
        && WriteList(*file.file, cover)
        && WriteList(*file.file, areaCoverIndex)
        && WriteList(*file.file, touchingCoverIndex)
        && WriteList(*file.file, traversalPoints)
        && WriteList(*file.file, hintNodes)
        && WriteList(*file.file, trees)
        && WriteList(*file.file, areaBounds);
}

void idAAS2File::LoadResource() {
    idStr binaryName(GetName());
    const char* dot = std::strrchr(GetName(), '.');
    const char* extension = dot != nullptr ? dot + 1 : "aas";
    char binaryPath[256] = {};
    idStr binaryExtension("b");
    binaryExtension.Append(extension);
    fileSystem->FixLongFilename("generated", binaryExtension.c_str(),
        GetName(), binaryPath, sizeof(binaryPath));
    const std::uint32_t sourceTime = fileSystem->GetTimestamp(GetName(), false);
    if (LoadBinary(GetName(), binaryPath, 0, sourceTime)) {
        resourceError = nullptr;
        return;
    }
    if (!LoadText(GetName(), sourceTime)) {
        resourceError = "AAS source and generated binary unavailable";
        MakeDefault();
        return;
    }
    WriteBinary(GetName(), binaryPath, 0, sourceTime);
    FlagNoPushAreas();
    for (int tree = 0; tree < trees.Num(); ++tree) {
        if (MaxTreeDepth(tree) > 128) {
            resourceError = "AAS BSP exceeds recovered maximum depth";
            MakeDefault();
            return;
        }
    }
    resourceError = nullptr;
}

bool idAAS2File::ReloadIfStale() {
    const std::uint32_t current = fileSystem->GetTimestamp(GetName(), false);
    if (current == timestamp) return false;
    const char* dot = std::strrchr(GetName(), '.');
    const char* extension = dot != nullptr ? dot + 1 : "aas";
    idStr binaryExtension("b");
    binaryExtension.Append(extension);
    char binaryPath[256] = {};
    fileSystem->FixLongFilename("generated", binaryExtension.c_str(),
        GetName(), binaryPath, sizeof(binaryPath));
    fileSystem->RemoveFile(binaryPath, FSPATH_BASE);
    LoadResource();
    return true;
}

bool idAAS2File::GetAASAnim(
        const idIndex<short, invalidAASAnimIndex_t> index,
        const aas2AnimName_t** const value) const {
    const int number = index.Get();
    if (number < 0 || number >= animNames.Num()) {
        *value = nullptr;
        return false;
    }
    *value = &animNames[number];
    return true;
}

idIndex<short, invalidAASAnimIndex_t>
idAAS2File::GetAASAnimIndexByName(const char* const name) const {
    return FindNameIndex<idIndex<short, invalidAASAnimIndex_t>>(animNames, name);
}

bool idAAS2File::GetAASDependency(
        const idIndex<short, invalidAASDependencyIndex_t> index,
        const aas2DependencyName_t** const value) const {
    const int number = index.Get();
    if (number < 0 || number >= dependencyNames.Num()) {
        *value = nullptr;
        return false;
    }
    *value = &dependencyNames[number];
    return true;
}

idIndex<short, invalidAASDependencyIndex_t>
idAAS2File::GetAASDependencyIndexByName(const char* const name) const {
    return FindNameIndex<idIndex<short, invalidAASDependencyIndex_t>>(
        dependencyNames, name);
}

bool idAAS2File::GetAASInteractionEntity(
        const idIndex<short, invalidAASInteractionEntIndex_t> index,
        const aas2InteractionEntityName_t** const value) const {
    const int number = index.Get();
    if (number < 0 || number >= interactionEntityNames.Num()) {
        *value = nullptr;
        return false;
    }
    *value = &interactionEntityNames[number];
    return true;
}

idIndex<short, invalidAASInteractionEntIndex_t>
idAAS2File::GetAASInteractionEntityIndexByName(const char* const name) const {
    return FindNameIndex<idIndex<short, invalidAASInteractionEntIndex_t>>(
        interactionEntityNames, name);
}

bool idAAS2File::GetAASTraversalNameIndex(
        const idIndex<short, invalidAASTraversalNameIndex_t> index,
        const aas2TraversalEntityName_t** const value) const {
    const int number = index.Get();
    if (number < 0 || number >= traversalEntityNames.Num()) {
        *value = nullptr;
        return false;
    }
    *value = &traversalEntityNames[number];
    return true;
}

idIndex<short, invalidAASTraversalNameIndex_t>
idAAS2File::GetAASTraversalNameIndexByName(const char* const name) const {
    return FindNameIndex<idIndex<short, invalidAASTraversalNameIndex_t>>(
        traversalEntityNames, name);
}

int idAAS2File::GetAASTraversalIndexByNameIndex(
        const idIndex<short, invalidAASTraversalNameIndex_t> index) const {
    if (index.Get() < 0) return 0;
    for (int traversal = 1; traversal < traversalPoints.Num(); ++traversal) {
        if (traversalPoints[traversal].traversalNameIndex == index) {
            return traversal;
        }
    }
    return 0;
}

bool idAAS2File::SetTraversalFlag(const int index, const int flags) {
    if (index <= 0 || index >= traversalPoints.Num()) return false;
    aas2Traversal_t& traversal = traversalPoints[index];
    const std::uint32_t changed = traversal.flags
        | static_cast<std::uint32_t>(flags);
    if (changed == traversal.flags) return false;
    traversal.flags = changed;
    const int reachability = traversal.reachabilityIndex.Get();
    if ((changed & 1u) == 0 && reachability >= 0
        && reachability < reachabilities.Num()) {
        reachabilities[reachability].travelFlags &= ~std::uint32_t(AAS_TFL_INVALID);
    }
    return true;
}

bool idAAS2File::ClearTraversalFlag(const int index, const int flags) {
    if (index <= 0 || index >= traversalPoints.Num()) return false;
    aas2Traversal_t& traversal = traversalPoints[index];
    const std::uint32_t changed = traversal.flags
        & ~static_cast<std::uint32_t>(flags);
    if (changed == traversal.flags) return false;
    traversal.flags = changed;
    const int reachability = traversal.reachabilityIndex.Get();
    if ((changed & 1u) == 0 && reachability >= 0
        && reachability < reachabilities.Num()) {
        reachabilities[reachability].travelFlags |= AAS_TFL_INVALID;
    }
    return true;
}

bool idAAS2File::GetAASTraversalAreas(const int index, int& startArea,
        int& goalArea) const {
    if (index <= 0 || index >= traversalPoints.Num()) return false;
    startArea = traversalPoints[index].startAreaNum;
    goalArea = traversalPoints[index].endAreaNum;
    return true;
}

idIndex<short, invalidReachability_t>
idAAS2File::FindReachabilityByName(const char* const name) const {
    for (int index = 0; index < reachabilityNames.Num(); ++index) {
        if (_stricmp(name != nullptr ? name : "", reachabilityNames[index].name) == 0) {
            return idIndex<short, invalidReachability_t>(
                static_cast<short>(reachabilityNames[index].index));
        }
    }
    return idIndex<short, invalidReachability_t>();
}

int idAAS2File::GetTraversalsForReachability(
        const idIndex<short, invalidReachability_t> reachIndex,
        idList<int, 5>& traversals) const {
    traversals.Clear();
    const int number = reachIndex.Get();
    if (number < 0 || number >= reachabilities.Num()) return 0;
    const aas2Reachability_t& reachability = reachabilities[number];
    if (!IsValidArea(areas, reachability.fromAreaNum)) return 0;
    const aas2Area_t& area = areas[reachability.fromAreaNum];
    for (int index = area.firstTraversal;
         index < area.firstTraversal + area.numTraversals
             && index < traversalPoints.Num(); ++index) {
        const aas2Traversal_t& traversal = traversalPoints[index];
        if (traversal.startAreaNum == reachability.fromAreaNum
            && traversal.endAreaNum == reachability.toAreaNum) {
            traversals.Append(index);
        }
    }
    return traversals.Num();
}

int idAAS2File::GetTraversalsForInteractableEntity(
        const idIndex<short, invalidAASInteractionEntIndex_t> entityIndex,
        idList<int, 5>& traversals) const {
    traversals.Clear();
    for (int index = 0; index < traversalPoints.Num(); ++index) {
        if (traversalPoints[index].interactionEntIndex == entityIndex) {
            traversals.Append(index);
        }
    }
    return traversals.Num();
}

void idAAS2File::ResetCover() {
    for (int index = 0; index < cover.Num(); ++index) {
        cover[index].usableTime = 0;
        cover[index].reservedBy = 0x1FFF;
    }
}

idIndex<int, invalidAASTree_t> idAAS2File::GetTreeForFloorNormal(
        const idVec3& normal) const {
    float bestDot = -2.0f;
    int bestTree = -1;
    for (int tree = 0; tree < trees.Num(); ++tree) {
        const float dot = trees[tree].floorNormal.Dot(normal);
        if (dot > 0.70710677f && dot > bestDot) {
            bestDot = dot;
            bestTree = tree;
        }
    }
    return idIndex<int, invalidAASTree_t>(bestTree);
}

idIndex<int, invalidAASTree_t> idAAS2File::GetTreeForArea(
        const int areaNum) const {
    for (int tree = 0; tree < trees.Num(); ++tree) {
        if (areaNum >= trees[tree].firstArea && areaNum < trees[tree].lastArea) {
            return idIndex<int, invalidAASTree_t>(tree);
        }
    }
    return idIndex<int, invalidAASTree_t>(0);
}

int idAAS2File::GetNumAreasInTree(
        const idIndex<int, invalidAASTree_t> treeNum) const {
    const int index = treeNum.Get();
    return index >= 0 && index < trees.Num()
        ? trees[index].lastArea - trees[index].firstArea : 0;
}

const idVec3* idAAS2File::GetFloorNormalForTree(
        const idIndex<int, invalidAASTree_t> treeNum) const {
    const int index = treeNum.Get();
    return index >= 0 && index < trees.Num() ? &trees[index].floorNormal : nullptr;
}

const idVec3* idAAS2File::GetFloorNormalForArea(const int areaNum) const {
    return GetFloorNormalForTree(GetTreeForArea(areaNum));
}

void idAAS2File::FloodAddVisitedArea(const int areaNum) {
    if (areaNum < 0 || areaNum >= areas.Num()) return;
    visitedAreas.Append(areaNum);
    areas[areaNum].flags |= AAS_AREA_FLOOD_VISITED;
}

void idAAS2File::FloodClearVisitedAreas(const int offset) {
    const int first = (std::max)(0, offset);
    for (int index = first; index < visitedAreas.Num(); ++index) {
        const int areaNum = visitedAreas[index];
        if (areaNum >= 0 && areaNum < areas.Num()) {
            areas[areaNum].flags &= ~AAS_AREA_FLOOD_VISITED;
        }
    }
    visitedAreas.SetNum((std::min)(first, visitedAreas.Num()));
}

void idAAS2File::FlagNoPushAreas() {
    for (int areaNum = 1; areaNum < areas.Num(); ++areaNum) {
        if (areas[areaNum].numEdges <= 0) continue;
        idVec3 center = AreaCenter(areaNum);
        if (PushPointIntoAreaNum(areaNum, center)) {
            areas[areaNum].flags |= AAS_AREA_NOPUSH;
        }
    }
}

void idAAS2File::MaxTreeDepth_r(const int nodeNum, const int depth,
        int& maximumDepth) const {
    maximumDepth = (std::max)(maximumDepth, depth);
    if (nodeNum <= 0 || nodeNum >= nodes.Num() || depth > 256) return;
    MaxTreeDepth_r(nodes[nodeNum].children[0], depth + 1, maximumDepth);
    MaxTreeDepth_r(nodes[nodeNum].children[1], depth + 1, maximumDepth);
}

int idAAS2File::MaxTreeDepth(const int tree) const {
    if (tree < 0 || tree >= trees.Num()) return 0;
    int maximumDepth = 0;
    MaxTreeDepth_r(trees[tree].headNode, 0, maximumDepth);
    return maximumDepth;
}
