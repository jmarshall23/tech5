#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/math/vectori.h"

#include <cstdint>

class Contour;

enum polygonType_t : int {
    POLYTYPE_CLIP = 0,
    POLYTYPE_SUBJECT = 1
};

enum clipMode_t : int {
    CLIPMODE_INTERSECT = 0,
    CLIPMODE_UNION,
    CLIPMODE_DIFFERENCE,
    CLIPMODE_XOR
};

enum fillType_t : int {
    FILLTYPE_EVEN_ODD = 0,
    FILLTYPE_NON_ZERO
};

class alignas(4) idCutterClip {
public:
    enum edgeSide_t { EDGESIDE_LEFT = 0, EDGESIDE_RIGHT = 1 };
    enum horizontalDirection_t {
        HORIZONTALDIRECTION_NONE = 0,
        HORIZONTALDIRECTION_LEFTTORIGHT,
        HORIZONTALDIRECTION_RIGHTTOLEFT
    };
    enum intersectProtects_t {
        INTERSECTPROTECTS_NONE = 0,
        INTERSECTPROTECTS_LEFT,
        INTERSECTPROTECTS_RIGHT,
        INTERSECTPROTECTS_BOTH
    };
    enum addEdge_t {
        ADDEDGE_NONE = 0,
        ADDEDGE_LEFT,
        ADDEDGE_RIGHT,
        ADDEDGE_BOTH
    };
    enum memPool_t {
        NUM_POOLSCANBEAMS = 0x100,
        NUM_POOLLOCALMINIMAS = 0x100,
        NUM_POOLEDGES = 0x400,
        NUM_POOLPOLYGONS = 0x20,
        NUM_POOLPOLYGONPOINTS = 0x400,
        NUM_POOLINTERSECTPOINTS = 0x80,
        NUM_POOLJOINRECORDS = 0x80,
        NUM_POOLHORIZONTALJOINRECORDS = 0x80,
        NUM_POOLNESTEDPOLYGONS = 0x20,
        NUM_POOLCONTOURS = 0x20,
        NUM_POOLCONTOUREDGES = 0x400,
        NUM_POOLCONTOURNODES = 0x400
    };

    struct Edge_t;
    struct PolygonPoint_t;
    struct Polygon_t;

    struct Edge_t {
        Edge_t* prev;
        Edge_t* next;
        Edge_t* prevLML;
        Edge_t* nextLML;
        Edge_t* prevAEL;
        Edge_t* nextAEL;
        Edge_t* prevSEL;
        Edge_t* nextSEL;
        idVec2i top;
        idVec2i bottom;
        idVec2i current;
        float deltaX;
        int tmpX;
        std::int16_t windingCount;
        std::int16_t windingCount2;
        std::int16_t outIndex;
        std::int16_t windingDelta;
        std::uint16_t reserved0 : 1;
        std::uint16_t freeBits : 12;
        std::uint16_t horizontal : 1;
        std::uint16_t polyType : 1;
        std::uint16_t side : 1;
        int ID;
    };

    struct Scanbeam_t {
        Scanbeam_t* next;
        int y;
    };

    struct alignas(4) Polygon_t {
        Polygon_t* next;
        Polygon_t* firstLeft;
        Polygon_t* appendLink;
        PolygonPoint_t* points;
        PolygonPoint_t* bottomPoint;
        Edge_t* bottomEdge1;
        Edge_t* bottomEdge2;
        int index;
        bool connected;
        bool hole;
    };

    struct PolygonPoint_t {
        PolygonPoint_t* next;
        PolygonPoint_t* prev;
        idVec2i pos;
        int index;
    };

    struct NestedPolygon_t {
        NestedPolygon_t* next;
        Polygon_t* outer;
        Polygon_t* inner;
    };

    struct LocalMinima_t {
        LocalMinima_t* next;
        Edge_t* leftBound;
        Edge_t* rightBound;
        int y;
    };

    struct IntersectNode_t {
        IntersectNode_t* next;
        Edge_t* edge1;
        Edge_t* edge2;
        idVec2i pos;
    };

    struct JoinRecord_t {
        JoinRecord_t* next;
        idVec2i point1a;
        idVec2i point1b;
        idVec2i point2a;
        idVec2i point2b;
        std::int16_t polyIndex1;
        std::int16_t polyIndex2;
    };

    struct alignas(4) HorizontalJoinRecord_t {
        HorizontalJoinRecord_t* next;
        Edge_t* edge;
        std::int16_t savedIndex;
    };

    class idSort_Polygons {
    public:
        int Compare(const Polygon_t* a, const Polygon_t* b) const;
    };

    idCutterClip();
    ~idCutterClip();

    void Prepare();
    void PreAllocate();
    void AddContour(const Contour* contours, polygonType_t polyType);
    bool Clip(clipMode_t clipMode_, fillType_t fillType);
    int GetNumPolygons() const;
    int GetConnectedPolygons() const;
    void GetPolygon(int id, idList<idVec2i, 5>& list);
    void GetInnerPolygon(idList<idVec2i, 5>& list);
    void GetConnectedPolygon(int index,
        idList<idVec2i, 5>& list) const;

    int memoryPeek;
    int memoryCurrent;
    int numEdges;
    int maxEdges;
    int numLocalMinima;
    int maxLocalMinima;
    int numScanbeams;
    int maxScanbeams;
    int numPolygons;
    int maxPolygons;
    int numPolygonPoints;
    int maxPolygonPoints;
    int numNestedPolygons;
    int maxNestedPolygons;
    int numJoinRecords;
    int maxJoinRecords;
    int numHorizontalJoinRecords;
    int maxHorizontalJoinRecords;
    int numIntersectNode;
    int maxIntersectNode;
    Edge_t* edgesPool;
    Scanbeam_t* scanbeamsPool;
    Polygon_t* polygonsPool;
    PolygonPoint_t* polygonPointsPool;
    NestedPolygon_t* nestedPolygonsPool;
    LocalMinima_t* localMinimasPool;
    IntersectNode_t* intersectNodesPool;
    JoinRecord_t* joinRecordsPool;
    HorizontalJoinRecord_t* horizontalJoinRecordsPool;
    LocalMinima_t* currentLocalMinima;
    LocalMinima_t* localMinimaList;
    Scanbeam_t* scanbeams;
    Edge_t* activeEdges;
    Edge_t* sortedEdges;
    IntersectNode_t* intersectNodes;
    NestedPolygon_t* currentNestedPolygon;
    Polygon_t* currentInnerPolygon;
    idList<Edge_t*, 5> edges;
    idList<PolygonPoint_t*, 5> polygonPoints;
    idList<Polygon_t*, 5> polygons;
    idList<NestedPolygon_t*, 5> nestedPolygons;
    idList<JoinRecord_t*, 5> joins;
    idList<HorizontalJoinRecord_t*, 5> horizontalJoins;
    idList<void*, 5> poolAllocations;
    fillType_t fillTypeSubject;
    fillType_t fillTypeClip;
    clipMode_t clipMode;
    std::uint8_t reserved : 7;
    std::uint8_t running : 1;

private:
    void SwapEdgeInAEL(Edge_t* edge1, Edge_t* edge2);
    void SwapEdgeInSEL(Edge_t* edge1, Edge_t* edge2);
    void AddEdgeToAEL(Edge_t* edge);
    void RemoveEdgeFromAEL(Edge_t* edge);
    static PolygonPoint_t* FindBottom(PolygonPoint_t* point);
    static bool IsClockwise(const PolygonPoint_t* points);
    bool IsTopHorizontal(int x) const;
    bool FixupIntersections();
    static bool PointInPolygon(const idVec2i& pos,
        const PolygonPoint_t* point);
    static int CalculateTopX(const Edge_t* edge, int y);
    void FixHoleLinkage_r(Polygon_t* polygon);
    static bool IsPolygonPoint(const idVec2i& pos,
        const PolygonPoint_t* point);
    static bool IsContributing(clipMode_t mode, Edge_t* edge);
    static bool SlopesEqual(Edge_t* edge1, Edge_t* edge2);
    static bool IsSegmentOverlapping(const idVec2i& p1a,
        const idVec2i& p1b, const idVec2i& p2a, const idVec2i& p2b,
        idVec2i& overlap1, idVec2i& overlap2);
    void SetHoleState(const Edge_t* edge, Polygon_t* polygon);
    static const Polygon_t* FindBottomPolygon(const Polygon_t* polygon1,
        const Polygon_t* polygon2);
    void AppendPolygon(Edge_t* edge1, Edge_t* edge2);
    void SetWindingCount(Edge_t* edge);
    void ClearHorizontalJoinRecords();
    void ClearJoinRecords();
    void ClearNestedPolygons();
    void ClearPolygons();
    void ClearPolygonPoints();
    static bool EdgeEdgeIntersection(Edge_t* edge1, Edge_t* edge2,
        idVec2i& pos);
    void FixupPolygon(Polygon_t* polygon);
    static bool FindSegment(PolygonPoint_t*& point, idVec2i& p1,
        idVec2i& p2);
    Edge_t* AllocEdge();
    LocalMinima_t* AllocLocalMinima();
    Scanbeam_t* AllocScanbeam();
    Polygon_t* AllocPolygon();
    PolygonPoint_t* AllocPolygonPoint();
    NestedPolygon_t* AllocNestedPolygon();
    JoinRecord_t* AllocJoinRecord();
    HorizontalJoinRecord_t* AllocHorizontalJoinRecord();
    IntersectNode_t* AllocIntersectNode();
    void BuildResult();
    Edge_t* AddBoundToLML(Edge_t* edge);
    void AddScanbeam(int y);
    void AddJoinRecord(Edge_t* edge1, Edge_t* edge2,
        std::int16_t outIndexEdge1, std::int16_t outIndexEdge2);
    void AddIntersectNode(Edge_t* edge1, Edge_t* edge2,
        const idVec2i& pos);
    PolygonPoint_t* AddPolygonPoint(Edge_t* edge1, Edge_t* edge2,
        const idVec2i& pos);
    PolygonPoint_t* AddPolygonPoint(Polygon_t* polygon,
        PolygonPoint_t* before, PolygonPoint_t* after,
        const idVec2i& pos);
    void AddLocalMinPolygon(Edge_t* edge1, Edge_t* edge2,
        const idVec2i& pos);
    void AddLocalMaxPolygon(Edge_t* edge1, Edge_t* edge2,
        const idVec2i& pos);
    void IntersectEdges(Edge_t* edge1, Edge_t* edge2,
        const idVec2i& pos, intersectProtects_t protects);
    void Reset();
    Edge_t* UpdateEdgeInAEL(Edge_t* edge);
    void ProcessIntersectList();
    void BuildIntersectList(int yBottom, int yTop);
    static void GetPolygon(const Polygon_t* polygon,
        idList<idVec2i, 5>& list);
    void DoMaxima(Edge_t* edge, Edge_t* maximaPair, int y);
    void AddLocalMinimaToAEL(int yBottom);
    void ProcessHorizontal(Edge_t* edge);
    void JoinEdges();
    void ProcessHorizontals();
    void ProcessEdgesAtTopOfScanbeam(int y);
};
