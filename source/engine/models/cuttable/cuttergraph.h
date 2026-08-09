#pragma once

#include "idlib/color.h"
#include "idlib/containers/list.h"
#include "idlib/math/matrix.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"
#include "models/cuttable/contourinfo.h"

#include <cstdint>

class ContourManager;
class idFile;
class idRenderWorld;

struct graphBranch_t {
    int index;
    int num;
};

struct graphTree_t {
    idList<idVec3, 5> positions;
    idList<graphBranch_t, 5> branches;
    idList<idVec3, 5> endpoints;
    idList<idVec3, 5> intersections;
};

class idCutterGraphManager {
public:
    enum { NUM_POOLNODES = 0x400, NUM_POOLLINKS = 0x400 };

    struct Link_t;
    struct Edge_t;

    struct Node_t {
        Node_t* next;
        Link_t* link;
        idVec2i pos;
        std::uint32_t allocated : 1;
        std::uint32_t id : 31;
    };

    struct Link_t {
        Link_t* next;
        Edge_t* edge;
        Node_t* node;
        std::uint32_t reserved : 31;
        std::uint32_t allocated : 1;
        int invalid;
    };

    struct Edge_t {
        Edge_t* next;
        Node_t* node1;
        Node_t* node2;
        Contour* contour;
        ContourEdge_t* contourEdge;
        std::uint32_t reserved : 30;
        std::uint32_t allocated : 1;
        std::uint32_t visited : 1;
    };

    struct nodeHandle_t { Node_t* data; };
    struct edgeHandle_t { Edge_t* data; };
    struct linkHandle_t { Link_t* data; };

    class IDHeap {
    public:
        IDHeap();
        int Alloc();
        void Free(int id);
        void Create(int numBits_);
        void Read(idFile* file);
        void Write(idFile* file) const;

        idList<unsigned char, 5> buffer;
        std::uint32_t isStatic : 1;
        std::uint32_t index : 31;
        int numBits;
    };

    class Graph {
    public:
        Graph();

        void Acquire();
        void AddNode(Node_t* node);
        void RemoveEdge(Edge_t* edge);
        void RemoveLink(Link_t* link);
        int FindNodeIndex(const idVec2i& pos, int threshold) const;
        int FindClosestNode(Edge_t* edge, const idVec2i& pos,
            int threshold) const;
        Edge_t* FindSplitEdge(const Node_t* source, const idVec2i& pos,
            idVec2i& intersection) const;
        idVec2i Local3DToLocal2D(const idVec3& localPoint) const;
        idVec2i GetLocal2D(const idVec3& point) const;
        idVec3 GetPosition3D(const idVec2i& point2d) const;
        void SetPosition(const idVec3& position_,
            const idMat3& orientation_);
        void BuildGraphTree(graphTree_t& graphTree) const;
        bool PathFind(idList<idVec2i, 5>& points) const;
        void DebugDraw(idRenderWorld* renderWorld, int lifeTime) const;

        Node_t* lastNode;
        Node_t* prevNode;
        idList<nodeHandle_t, 5> nodes;
        idList<edgeHandle_t, 5> edges;
        idList<linkHandle_t, 5> links;
        Contour* contoursOuter;
        Contour* contoursInner;
        IDHeap idheap;
        idStr name;
        idMat3 inverse;
        idMat3 orientation;
        idVec3 position;
        idVec3 normal;
        idVec3 left;
        idVec3 down;
    };

    struct savedContour_t {
        idList<idVec3, 5> contourPoints;
        idColor color;
        idStr text;
    };

    struct savedPathPos_t {
        idVec3 pos;
        idVec2 localPos;
        idColor color;
    };

    struct graph_t { Graph* graph; };

    idCutterGraphManager();
    virtual ~idCutterGraphManager();

    Contour* CreateContour(const idList<idVec2i, 5>& points);
    void MergeContours(Contour* contour);
    void FreeContour(Contour* contour);
    void PreAcquire();
    int AllocateGraph(const idStr& name, const idVec3& position,
        const idMat3& orientation, const idVec3& normal,
        const idList<idVec3, 5>& points);
    void FreeGraph(int id);
    void Acquire(int id);
    void ReleaseGraph(int id = -1);
    bool IsGraphValid(int id) const;
    void SetPosition(int id, const idVec3& position,
        const idMat3& orientation);
    idVec2i GetLocal2D(const idVec3& point) const;
    idVec3 GetLocal3D(const idVec2& point2d) const;
    void GetNormalVectors(int id, idVec3& normal_, idVec3& left_,
        idVec3& up_) const;
    Contour* GetOuterContour(int id) const;
    Contour* GetInnerContour(int id) const;
    void DebugDraw(int id, idRenderWorld* renderWorld, int lifeTime) const;
    bool BuildEdge(const idVec2i& dst);
    bool PathFind(idList<idVec2i, 5>& points) const;
    void BuildGraphTree(int id, graphTree_t& graphTree) const;
    Contour* IntersectContours(Contour* contour);
    bool AddContour(Contour* contours, Contour* mergedContours);

    static void Write(idCutterGraphManager* manager, idFile* file,
        int graphHandle);
    static void Read(idCutterGraphManager* manager, idFile* file);

    idList<savedContour_t, 5> savedContours;
    idList<savedPathPos_t, 5> savedNodes;
    idList<Node_t*, 5> invalidNodes;
    idList<graph_t, 5> graphs;
    idList<Link_t*, 5> linksPoolBlock;
    idList<Node_t*, 5> nodesPoolBlock;
    idList<Edge_t*, 5> edgesPoolBlock;
    idList<Link_t*, 5> linksPool;
    idList<Node_t*, 5> nodesPool;
    idList<Edge_t*, 5> edgesPool;
    ContourManager* contourManager;
    Graph* graph;

private:
    void PreAllocatePools();
    Link_t* AllocateLink();
    Node_t* AllocateNode();
    Edge_t* AllocateEdge();
    void FreeLink(Link_t* link);
    void FreeNode(Node_t* node);
    void FreeEdge(Edge_t* edge);
    Node_t* GenerateNode(const idVec3& pos3d, const idVec2i& pos,
        int threshold);
    void AddLink(Node_t* srcNode, Node_t* dstNode, Edge_t* edge);
    void RemoveLink(Node_t* srcNode, Node_t* dstNode);
    Edge_t* Connect(Node_t* srcNode, Node_t* dstNode, Contour* contour,
        ContourEdge_t* contourEdge = nullptr);
    void Disconnect(Edge_t* edge);
    void ApplyGraph(Graph* newGraph);
    bool PointInPolygon(const idVec2i& pos,
        const ContourEdge_t* edge) const;
};

class idCutterGraphState {
public:
    idCutterGraphManager* manager;
    idList<int, 5> graphHandles;
};
