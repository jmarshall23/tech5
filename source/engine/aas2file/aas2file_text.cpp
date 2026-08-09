#include "aas2file/aas2file.h"

#include "idlib/text/lexer.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

namespace {

bool BeginArray(idLexer& source, int& count) {
    count = source.ParseInt();
    return count >= 0 && source.ExpectTokenString("{");
}

bool BeginRecord(idLexer& source) {
    source.ParseInt(); // the serialized record index is informational
    return source.ExpectTokenString("(");
}

std::int16_t ClampShort(const float value) {
    const int integer = static_cast<int>(value);
    return static_cast<std::int16_t>((std::max)(-32768,
        (std::min)(32767, integer)));
}

} // namespace

bool idAAS2File::ParseIndex(idLexer& source, idList<int, 37>& indexes) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    indexes.Clear();
    if (!indexes.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        source.ParseInt();
        if (!source.ExpectTokenString("(")) return false;
        const int value = source.ParseInt();
        if (!source.ExpectTokenString(")")) return false;
        indexes.Append(value);
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseNames(idLexer& source,
        idList<aas2Name_t, 37>& names) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    names.Clear();
    if (!names.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        idToken token;
        aas2Name_t entry{};
        if (!source.ReadToken(token)) return false;
        strncpy_s(entry.name, token.c_str(), _TRUNCATE);
        entry.index = source.ParseInt();
        names.Append(entry);
    }
    return source.ExpectTokenString("}");
}

template<typename nameType>
bool idAAS2File::ParseInteractionEntityNames(idLexer& source,
        idList<nameType, 37>& names) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    names.Clear();
    if (!names.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        idToken token;
        nameType entry{};
        if (!source.ReadToken(token)) return false;
        strncpy_s(entry.name, token.c_str(), _TRUNCATE);
        names.Append(entry);
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseVertices(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    vertices.Clear();
    if (!vertices.PreAllocate(count + 1)) return false;
    for (int index = 0; index < count; ++index) {
        source.ParseInt();
        idVec3 vertex;
        if (!source.Parse1DMatrix(3, &vertex.x, false)) return false;
        vertices.Append(vertex);
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseEdges(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    edges.Clear();
    if (!edges.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        aas2Edge_t edge{};
        if (!BeginRecord(source)) return false;
        edge.vertexNum[0] = source.ParseInt();
        edge.vertexNum[1] = source.ParseInt();
        edge.flags = source.ParseInt();
        if (!source.ExpectTokenString(")")) return false;
        edges.Append(edge);
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseNodes(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    nodes.Clear();
    if (!nodes.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        aas2Node_t node{};
        if (!BeginRecord(source)) return false;
        node.planeNum = source.ParseUnsignedInt();
        node.flags = source.ParseUnsignedInt();
        node.children[0] = source.ParseInt();
        node.children[1] = source.ParseInt();
        if (!source.ExpectTokenString(")")) return false;
        nodes.Append(node);
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParsePortals(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    portals.Clear();
    if (!portals.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        aas2Portal_t portal{};
        if (!BeginRecord(source)) return false;
        portal.areaNum = static_cast<std::uint16_t>(source.ParseInt());
        portal.clusters[0] = static_cast<std::int16_t>(source.ParseInt());
        portal.clusters[1] = static_cast<std::int16_t>(source.ParseInt());
        portal.clusterAreaNum[0] = static_cast<std::uint16_t>(source.ParseInt());
        portal.clusterAreaNum[1] = static_cast<std::uint16_t>(source.ParseInt());
        portal.maxAreaTravelTime = 0;
        if (!source.ExpectTokenString(")")) return false;
        portals.Append(portal);
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseClusters(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    clusters.Clear();
    if (!clusters.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        aas2Cluster_t cluster{};
        if (!BeginRecord(source)) return false;
        cluster.numAreas = source.ParseInt();
        cluster.numReachableAreas = source.ParseInt();
        cluster.firstPortal = source.ParseInt();
        cluster.numPortals = source.ParseInt();
        if (!source.ExpectTokenString(")")) return false;
        clusters.Append(cluster);
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseObstaclePVS(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    obstaclePVS.Clear();
    if (!obstaclePVS.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        if (!BeginRecord(source)) return false;
        const auto value = static_cast<std::uint8_t>(source.ParseInt());
        if (!source.ExpectTokenString(")")) return false;
        obstaclePVS.Append(value);
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParsePlanes(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    planes.Clear();
    if (!planes.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        source.ParseInt();
        float values[4] = {};
        if (!source.Parse1DMatrix(4, values, false)) return false;
        planes.Append(idPlane(values[0], values[1], values[2], -values[3]));
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseReachabilities(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    reachabilities.Clear();
    if (!reachabilities.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        aas2Reachability_t reachability{};
        reachability.next.Invalidate();
        reachability.rev_next.Invalidate();
        if (!BeginRecord(source)) return false;
        reachability.travelFlags = source.ParseUnsignedInt();
        reachability.travelTime = static_cast<std::uint16_t>(source.ParseInt());
        reachability.fromAreaNum = static_cast<std::uint16_t>(source.ParseInt());
        reachability.toAreaNum = static_cast<std::uint16_t>(source.ParseInt());
        if (!source.ExpectTokenString("(")) return false;
        for (int axis = 0; axis < 3; ++axis) {
            reachability.start[axis] = static_cast<std::int16_t>(source.ParseInt());
        }
        if (!source.ExpectTokenString(")")
            || !source.ExpectTokenString("(")) return false;
        for (int axis = 0; axis < 3; ++axis) {
            reachability.end[axis] = static_cast<std::int16_t>(source.ParseInt());
        }
        if (!source.ExpectTokenString(")")
            || !source.ExpectTokenString(")")) return false;
        reachabilities.Append(reachability);
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseAreas(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    areas.Clear();
    if (!areas.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        aas2Area_t area;
        area.reach.Invalidate();
        area.rev_reach.Invalidate();
        area.firstChokePoint = 0;
        area.numChokePoints = 0;
        if (!BeginRecord(source)) return false;
        area.flags = static_cast<std::uint16_t>(source.ParseInt());
        area.travelFlags = source.ParseUnsignedInt();
        area.numEdges = static_cast<std::int16_t>(source.ParseInt());
        area.firstEdge = source.ParseInt();
        area.cluster = static_cast<std::int16_t>(source.ParseInt());
        area.clusterAreaNum = static_cast<std::uint16_t>(source.ParseInt());
        area.obstaclePVSOffset = source.ParseUnsignedInt();
        area.firstCover = static_cast<std::uint16_t>(source.ParseInt());
        area.numCover = static_cast<std::uint16_t>(source.ParseInt());
        area.firstTraversal = static_cast<std::uint16_t>(source.ParseInt());
        area.numTraversals = static_cast<std::uint16_t>(source.ParseInt());
        area.firstHintNode = static_cast<std::uint16_t>(source.ParseInt());
        area.numHintNodes = static_cast<std::uint16_t>(source.ParseInt());
        if (!source.ExpectTokenString(")")) return false;
        areas.Append(area);
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseCover(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    cover.Clear();
    if (!cover.SetNum(count)) return false;
    for (int index = 0; index < count; ++index) {
        if (!BeginRecord(source)) return false;
        aas2Cover_t& entry = cover[index];
        const float originX = source.ParseFloat();
        const float originY = source.ParseFloat();
        const float originZ = source.ParseFloat();
        entry.origin.Set(originX, originY, originZ);
        const float dirX = source.ParseFloat();
        const float dirY = source.ParseFloat();
        const float dirZ = source.ParseFloat();
        entry.dir.Set(dirX, dirY, dirZ);
        entry.areaNum = static_cast<std::int16_t>(source.ParseInt());
        entry.flags = static_cast<std::int16_t>(source.ParseInt());
        entry.firstTouching = source.ParseInt();
        entry.numTouching = source.ParseInt();
        if (source.CheckTokenString(")")) continue;
        entry.durationSec = source.ParseFloat();
        entry.minRange = source.ParseFloat();
        entry.maxRange = source.ParseFloat();
        if (!source.ExpectTokenString(")")) return false;
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseTraversalPoints(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    traversalPoints.Clear();
    if (!traversalPoints.SetNum(count)) return false;
    for (int index = 0; index < count; ++index) {
        if (!BeginRecord(source)) return false;
        aas2Traversal_t& traversal = traversalPoints[index];
        traversal.Clear();
        const float startX = source.ParseFloat();
        const float startY = source.ParseFloat();
        const float startZ = source.ParseFloat();
        traversal.startPoint.Set(startX, startY, startZ);
        const float endX = source.ParseFloat();
        const float endY = source.ParseFloat();
        const float endZ = source.ParseFloat();
        traversal.endPoint.Set(endX, endY, endZ);
        traversal.orientationFwd.x = static_cast<std::int16_t>(source.ParseInt());
        traversal.orientationFwd.y = static_cast<std::int16_t>(source.ParseInt());
        traversal.orientationFwd.z = static_cast<std::int16_t>(source.ParseInt());
        traversal.extrusionFwd.x = static_cast<std::int16_t>(source.ParseInt());
        traversal.extrusionFwd.y = static_cast<std::int16_t>(source.ParseInt());
        traversal.extrusionFwd.z = static_cast<std::int16_t>(source.ParseInt());
        traversal.extrusionDistance = static_cast<std::int16_t>(source.ParseInt());
        traversal.startAreaNum = static_cast<std::int16_t>(source.ParseInt());
        traversal.endAreaNum = static_cast<std::int16_t>(source.ParseInt());
        traversal.animIndex = idIndex<short, invalidAASAnimIndex_t>(
            static_cast<short>(source.ParseInt()));
        traversal.reachabilityIndex = idIndex<short, invalidReachability_t>(
            static_cast<short>(source.ParseInt()));
        traversal.flags = source.ParseUnsignedInt();
        traversal.dependencyIndex = idIndex<short, invalidAASDependencyIndex_t>(
            static_cast<short>(source.ParseInt()));
        traversal.interactionEntIndex = idIndex<short, invalidAASInteractionEntIndex_t>(
            static_cast<short>(source.ParseInt()));
        traversal.traversalNameIndex = idIndex<short, invalidAASTraversalNameIndex_t>(
            static_cast<short>(source.ParseInt()));
        if (!source.ExpectTokenString(")")) return false;
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseHintNodes(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    hintNodes.Clear();
    if (!hintNodes.SetNum(count)) return false;
    for (int index = 0; index < count; ++index) {
        if (!BeginRecord(source)) return false;
        aas2HintNode_t& hint = hintNodes[index];
        const float originX = source.ParseFloat();
        const float originY = source.ParseFloat();
        const float originZ = source.ParseFloat();
        hint.origin.Set(originX, originY, originZ);
        hint.areaNum = static_cast<std::int16_t>(source.ParseInt());
        hint.radius = static_cast<std::int16_t>(source.ParseInt());
        hint.hintType = static_cast<std::uint8_t>(source.ParseInt());
        hint.orientation = static_cast<std::uint8_t>(source.ParseInt());
        hint.dirFlags = static_cast<std::uint8_t>(source.ParseInt());
        hint.grouping = static_cast<std::uint8_t>(source.ParseInt());
        hint.hintData = source.ParseInt();
        if (!source.ExpectTokenString(")")) return false;
    }
    return source.ExpectTokenString("}");
}

bool idAAS2File::ParseTrees(idLexer& source) {
    int count = 0;
    if (!BeginArray(source, count)) return false;
    trees.Clear();
    if (!trees.PreAllocate(count)) return false;
    for (int index = 0; index < count; ++index) {
        bspTree_t tree{};
        source.ParseInt();
        if (!source.ExpectTokenString("(")) return false;
        const float normalX = source.ParseFloat();
        const float normalY = source.ParseFloat();
        const float normalZ = source.ParseFloat();
        tree.floorNormal.Set(normalX, normalY, normalZ);
        if (!source.ExpectTokenString(")")) return false;
        tree.headNode = source.ParseInt();
        tree.firstArea = source.ParseInt();
        tree.lastArea = source.ParseInt();
        trees.Append(tree);
    }
    return source.ExpectTokenString("}");
}

void idAAS2File::BuildReachabilityChains() {
    for (int areaNum = 0; areaNum < areas.Num(); ++areaNum) {
        areas[areaNum].reach.Invalidate();
        areas[areaNum].rev_reach.Invalidate();
    }
    for (int index = 0; index < reachabilities.Num(); ++index) {
        aas2Reachability_t& reachability = reachabilities[index];
        if (reachability.fromAreaNum < areas.Num()) {
            reachability.next = areas[reachability.fromAreaNum].reach;
            areas[reachability.fromAreaNum].reach =
                idIndex<short, invalidReachability_t>(static_cast<short>(index));
        }
        if (reachability.toAreaNum < areas.Num()) {
            reachability.rev_next = areas[reachability.toAreaNum].rev_reach;
            areas[reachability.toAreaNum].rev_reach =
                idIndex<short, invalidReachability_t>(static_cast<short>(index));
        }
    }
}

void idAAS2File::CalculateAreaBounds() {
    areaBounds.SetNum(areas.Num());
    for (int areaNum = 0; areaNum < areas.Num(); ++areaNum) {
        const idBounds bounds = AreaBounds(areaNum);
        for (int axis = 0; axis < 3; ++axis) {
            areaBounds[areaNum].min[axis] = ClampShort(std::floor(bounds[0][axis]));
            areaBounds[areaNum].max[axis] = ClampShort(std::ceil(bounds[1][axis]));
        }
    }
}

bool idAAS2File::LoadText(const char* const fileName,
        const std::uint32_t sourceTimestamp) {
    idLexer source(564);
    if (!source.LoadFile(fileName, false)) return false;

    idToken identifier;
    idToken version;
    if (!source.ReadToken(identifier) || !source.ReadToken(version)) return false;
    if (std::strcmp(identifier.c_str(), "DewmAAS") != 0
        && std::strcmp(identifier.c_str(), "DewmAAS2") != 0
        && std::strcmp(identifier.c_str(), "AAS2") != 0) {
        return false;
    }
    int parsedMajor = 0;
    int parsedMinor = 0;
    if (std::sscanf(version.c_str(), "%d.%d", &parsedMajor, &parsedMinor) != 2
        || parsedMajor != 3 || parsedMinor != 13) {
        return false;
    }
    const std::uint32_t parsedCRC = source.ParseUnsignedInt();
    if (!source.ExpectTokenString("firstFakeVertex")) return false;
    const int parsedFirstFakeVertex = source.ParseInt();
    if (!source.ExpectTokenString("firstFakeEdge")) return false;
    const int parsedFirstFakeEdge = source.ParseInt();
    if (!source.ExpectTokenString("firstFakeEdgeIndex")) return false;
    const int parsedFirstFakeEdgeIndex = source.ParseInt();
    if (!source.ExpectTokenString("firstFakeArea")) return false;
    const int parsedFirstFakeArea = source.ParseInt();

    Clear();
    major = parsedMajor;
    minor = parsedMinor;
    crc = parsedCRC;
    timestamp = sourceTimestamp;
    firstFakeVertex = parsedFirstFakeVertex;
    firstFakeEdge = parsedFirstFakeEdge;
    firstFakeEdgeIndex = parsedFirstFakeEdgeIndex;
    firstFakeArea = parsedFirstFakeArea;

    idToken section;
    while (source.ReadToken(section)) {
        const char* const name = section.c_str();
        bool ok = false;
        if (std::strcmp(name, "settings") == 0) ok = settings.ReadFromFile(source);
        else if (std::strcmp(name, "planes") == 0) ok = ParsePlanes(source);
        else if (std::strcmp(name, "vertices") == 0) ok = ParseVertices(source);
        else if (std::strcmp(name, "edges") == 0) ok = ParseEdges(source);
        else if (std::strcmp(name, "edgeIndex") == 0) ok = ParseIndex(source, edgeIndex);
        else if (std::strcmp(name, "reachabilities") == 0) ok = ParseReachabilities(source);
        else if (std::strcmp(name, "areas") == 0) ok = ParseAreas(source);
        else if (std::strcmp(name, "nodes") == 0) ok = ParseNodes(source);
        else if (std::strcmp(name, "portals") == 0) ok = ParsePortals(source);
        else if (std::strcmp(name, "portalIndex") == 0) ok = ParseIndex(source, portalIndex);
        else if (std::strcmp(name, "clusters") == 0) ok = ParseClusters(source);
        else if (std::strcmp(name, "obstaclePVS") == 0) ok = ParseObstaclePVS(source);
        else if (std::strcmp(name, "reachNames") == 0) ok = ParseNames(source, reachabilityNames);
        else if (std::strcmp(name, "traversalAnimNames") == 0
            || std::strcmp(name, "animNames") == 0) ok = ParseInteractionEntityNames(source, animNames);
        else if (std::strcmp(name, "dependencyNames") == 0) ok = ParseInteractionEntityNames(source, dependencyNames);
        else if (std::strcmp(name, "interactionEntityNames") == 0) ok = ParseInteractionEntityNames(source, interactionEntityNames);
        else if (std::strcmp(name, "traversalEntityNames") == 0) ok = ParseInteractionEntityNames(source, traversalEntityNames);
        else if (std::strcmp(name, "cover") == 0) ok = ParseCover(source);
        else if (std::strcmp(name, "areaCoverIndex") == 0) ok = ParseIndex(source, areaCoverIndex);
        else if (std::strcmp(name, "touchingCoverIndex") == 0) ok = ParseIndex(source, touchingCoverIndex);
        else if (std::strcmp(name, "traversalPoints") == 0) ok = ParseTraversalPoints(source);
        else if (std::strcmp(name, "hintNodes") == 0) ok = ParseHintNodes(source);
        else if (std::strcmp(name, "trees") == 0) ok = ParseTrees(source);
        else return false;
        if (!ok) return false;
    }

    if (trees.Num() == 0) {
        bspTree_t tree{};
        tree.floorNormal = -settings.gravityDir;
        tree.headNode = 1;
        tree.firstArea = 1;
        tree.lastArea = areas.Num();
        trees.Append(tree);
    }
    BuildReachabilityChains();
    CalculateAreaBounds();
    return true;
}
