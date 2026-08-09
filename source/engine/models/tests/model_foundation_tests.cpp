#include "models/cuttable/contourinfo.h"
#include "models/cuttable/cuttercontour.h"
#include "models/cuttable/cutterclip.h"
#include "models/cuttable/cuttergraph.h"
#include "models/cuttable/convexhull.h"
#include "models/cuttable/earcliptriangulate.h"
#include "models/cuttable/triangleinterpolator.h"
#include "models/cloth/jobs/clothgen.h"
#include "models/detail/jobs/detailgen.h"
#include "models/foliage/jobs/foliagegen.h"
#include "models/particles/jobs/particlestage.h"
#include "models/particles/jobs/particlegen.h"
#include "models/skeletalanimation/md6allocator.h"
#include "models/skeletalanimation/md6blockalloc.h"
#include "models/skeletalanimation/eyeinfocollection.h"
#include "models/skeletalanimation/userchannelexpression.h"
#include "models/static/jobs/statictransparencygen.h"
#include "models/transparency/jobs/influencespherecull.h"
#include "models/transparency/jobs/transparencybin.h"
#include "models/transparency/jobs/transparencysort.h"
#include "models/water/jobs/watergen.h"
#include "models/water/watersurfacesim.h"
#include "models/zipline/jobs/nonuniformbspline.h"
#include "models/zipline/jobs/ziplinegen.h"

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <vector>

namespace {

bool Near(float a, float b, float epsilon = 1.0e-4f) {
    return std::fabs(a - b) <= epsilon;
}

bool LookUpTestChannel(const idDeclMD6*, const char* name, int& index) {
    if (std::strcmp(name, "speed") != 0) {
        return false;
    }
    index = 1;
    return true;
}

void TestContour() {
    ContourNode_t nodes[5] = {};
    nodes[0].pos.Set(0, 0);
    nodes[1].pos.Set(10, 0);
    nodes[2].pos.Set(10, 10);
    nodes[3].pos.Set(0, 10);
    nodes[4].pos.Set(0, 0);
    for (int index = 0; index < 4; ++index) {
        nodes[index].next = &nodes[index + 1];
    }

    ContourEdge_t edge = {};
    edge.node = nodes;
    Contour contour = {};
    contour.edges = &edge;
    contour.numEdges = 4;

    assert(contour.ContainsPoint(idVec2i(5, 5)));
    assert(contour.ContainsPoint(idVec2i(0, 5)));
    assert(!contour.ContainsPoint(idVec2i(12, 5)));
    assert(Contour::SlopesEqual(idVec2i(0, 0), idVec2i(2, 2),
        idVec2i(4, 4)));
}

void TestContourManager() {
    ContourManager manager;
    idList<idVec2i, 5> firstPoints;
    firstPoints.Append(idVec2i(0, 0));
    firstPoints.Append(idVec2i(5, 0));
    firstPoints.Append(idVec2i(10, 0));
    firstPoints.Append(idVec2i(10, 10));
    firstPoints.Append(idVec2i(0, 10));
    firstPoints.Append(idVec2i(0, 0));
    Contour* first = manager.Create(firstPoints);
    assert(first != nullptr && first->numEdges == 4);
    assert(first->ContainsPoint(idVec2i(5, 5)));
    assert(Near(first->bound[0].x, -1.0f));
    assert(Near(first->bound[1].x, 11.0f));

    idList<idVec2i, 5> secondPoints;
    secondPoints.Append(idVec2i(10, 3));
    secondPoints.Append(idVec2i(20, 3));
    secondPoints.Append(idVec2i(20, 7));
    secondPoints.Append(idVec2i(10, 7));
    Contour* second = manager.Create(secondPoints);
    assert(second != nullptr);
    first->next = second;
    manager.Merge(first);
    ContourEdge_t* shared = first->FindEdge(idVec2i(10, 0),
        idVec2i(10, 10));
    assert(shared != nullptr);
    assert(Contour::FindNode(shared, idVec2i(10, 3),
        idVec2i(10, 7)) != nullptr);

    manager.Free(first);
    Contour* reused = manager.Create(firstPoints);
    assert(reused == second);
    manager.Free(reused);
}

void TestCutterGraph() {
    idCutterGraphManager manager;
    idList<idVec3, 5> boundary;
    boundary.Append(idVec3(0.0f, 0.0f, 0.0f));
    boundary.Append(idVec3(10.0f, 0.0f, 0.0f));
    boundary.Append(idVec3(10.0f, 10.0f, 0.0f));
    boundary.Append(idVec3(0.0f, 10.0f, 0.0f));
    const int handle = manager.AllocateGraph(idStr("graph"),
        idVec3(0.0f, 0.0f, 0.0f), idMat3(1.0f),
        idVec3(0.0f, 0.0f, 1.0f), boundary);
    assert(handle >= 0 && manager.IsGraphValid(handle));
    manager.Acquire(handle);
    const idVec2i start = manager.GetLocal2D(idVec3(1.0f, 5.0f, 0.0f));
    const idVec2i end = manager.GetLocal2D(idVec3(9.0f, 5.0f, 0.0f));
    manager.PreAcquire();
    assert(manager.BuildEdge(start));
    assert(manager.BuildEdge(end));

    idList<idVec2i, 5> path;
    assert(manager.PathFind(path));
    assert(path.Num() == 2 && path[0] == start && path[1] == end);
    graphTree_t tree;
    manager.BuildGraphTree(handle, tree);
    assert(tree.branches.Num() == 1);
    assert(tree.positions.Num() == 2);
    assert(tree.endpoints.Num() == 2);
    manager.ReleaseGraph();
    manager.FreeGraph(handle);
    assert(!manager.IsGraphValid(handle));
}

float PolygonArea(const idList<idVec2i, 5>& points) {
    float area = 0.0f;
    for (int index = 0; index < points.Num(); ++index) {
        const idVec2i& a = points[index];
        const idVec2i& b = points[(index + 1) % points.Num()];
        area += static_cast<float>(a.x * b.y - b.x * a.y);
    }
    return std::fabs(area) * 0.5f;
}

void TestCutterClip() {
    ContourManager manager;
    idList<idVec2i, 5> subjectPoints;
    subjectPoints.Append(idVec2i(0, 0));
    subjectPoints.Append(idVec2i(10, 0));
    subjectPoints.Append(idVec2i(10, 10));
    subjectPoints.Append(idVec2i(0, 10));
    idList<idVec2i, 5> clipPoints;
    clipPoints.Append(idVec2i(5, 0));
    clipPoints.Append(idVec2i(15, 0));
    clipPoints.Append(idVec2i(15, 10));
    clipPoints.Append(idVec2i(5, 10));
    Contour* subject = manager.Create(subjectPoints);
    Contour* clipping = manager.Create(clipPoints);

    idCutterClip clipper;
    clipper.AddContour(subject, POLYTYPE_SUBJECT);
    clipper.AddContour(clipping, POLYTYPE_CLIP);
    idList<idVec2i, 5> result;
    assert(clipper.Clip(CLIPMODE_INTERSECT, FILLTYPE_EVEN_ODD));
    assert(clipper.GetNumPolygons() == 1);
    clipper.GetPolygon(0, result);
    assert(Near(PolygonArea(result), 50.0f));

    assert(clipper.Clip(CLIPMODE_UNION, FILLTYPE_EVEN_ODD));
    assert(clipper.GetNumPolygons() == 1);
    clipper.GetPolygon(0, result);
    assert(Near(PolygonArea(result), 150.0f));

    assert(clipper.Clip(CLIPMODE_DIFFERENCE, FILLTYPE_NON_ZERO));
    assert(clipper.GetNumPolygons() == 1);
    clipper.GetPolygon(0, result);
    assert(Near(PolygonArea(result), 50.0f));

    assert(clipper.Clip(CLIPMODE_XOR, FILLTYPE_EVEN_ODD));
    assert(clipper.GetNumPolygons() == 2);
    manager.Free(subject);
    manager.Free(clipping);
}

void TestConvexHull() {
    idList<idVec2i, 5> points;
    points.Append(idVec2i(0, 0));
    points.Append(idVec2i(10, 0));
    points.Append(idVec2i(10, 10));
    points.Append(idVec2i(0, 10));
    points.Append(idVec2i(5, 5));
    points.Append(idVec2i(0, 0));

    idConvexHull hull;
    hull.Create(points);
    assert(hull.vertices.Num() == 4);
}

void TestEarClipTriangulation() {
    idList<idVec2, 5> outer;
    outer.Append(idVec2(0.0f, 0.0f));
    outer.Append(idVec2(10.0f, 0.0f));
    outer.Append(idVec2(10.0f, 10.0f));
    outer.Append(idVec2(0.0f, 10.0f));
    idList<idVec2, 5> hole;
    hole.Append(idVec2(3.0f, 3.0f));
    hole.Append(idVec2(3.0f, 7.0f));
    hole.Append(idVec2(7.0f, 7.0f));
    hole.Append(idVec2(7.0f, 3.0f));

    idEarClipTriangulate triangulator;
    triangulator.SetOuterFromPoints(outer);
    triangulator.AddInnerFromPoints(hole);
    triangulator.Triangulate();
    assert(triangulator.triangles.Num() % 3 == 0);

    float area = 0.0f;
    for (int index = 0; index < triangulator.triangles.Num(); index += 3) {
        const idVec2& a = triangulator.positions[triangulator.triangles[index]];
        const idVec2& b = triangulator.positions[triangulator.triangles[index + 1]];
        const idVec2& c = triangulator.positions[triangulator.triangles[index + 2]];
        area += std::fabs((b.x - a.x) * (c.y - a.y) -
            (b.y - a.y) * (c.x - a.x)) * 0.5f;
    }
    assert(Near(area, 84.0f));
}

void TestTriangleInterpolator() {
    idDrawVert vertices[3] = {};
    vertices[0].xyz.Set(0.0f, 0.0f, 0.0f);
    vertices[1].xyz.Set(1.0f, 0.0f, 0.0f);
    vertices[2].xyz.Set(0.0f, 1.0f, 0.0f);
    vertices[0].st.Set(0.0f, 0.0f);
    vertices[1].st.Set(1.0f, 0.0f);
    vertices[2].st.Set(0.0f, 1.0f);
    vertices[0].color[0] = 255;
    vertices[1].color[1] = 255;
    vertices[2].color[2] = 255;
    for (idDrawVert& vertex : vertices) {
        vertex.color[3] = 255;
    }

    const idVec2 originalST[3] = {
        idVec2(0.0f, 0.0f), idVec2(2.0f, 0.0f), idVec2(0.0f, 2.0f)
    };
    const std::uint16_t indices[3] = { 0, 1, 2 };
    idTriangleInterpolator interpolator;
    interpolator.AddTriangles(vertices, originalST, indices, 3);

    idDrawVert output = {};
    idVec2 outputST;
    assert(interpolator.Interpolate(idVec2(0.25f, 0.25f), output,
        outputST));
    assert(Near(output.st.x, 0.25f));
    assert(Near(output.st.y, 0.25f));
    assert(Near(outputST.x, 0.5f));
    assert(Near(outputST.y, 0.5f));
    assert(!interpolator.Interpolate(idVec2(2.0f, 2.0f), output,
        outputST));
}

void TestSpline() {
    idNonUniformBSpline<idVec3> spline;
    spline.SetOrder(2);
    assert(spline.AddValue(0.0f, idVec3(0.0f, 0.0f, 0.0f)) == 0);
    assert(spline.AddValue(1.0f, idVec3(10.0f, 20.0f, 30.0f)) == 1);
    const idVec3 middle = spline.GetCurrentValue(0.5f);
    assert(Near(middle.x, 5.0f));
    assert(Near(middle.y, 10.0f));
    assert(Near(middle.z, 15.0f));
    assert(Near(spline.GetCurrentValue(-1.0f).x, 0.0f));
    assert(Near(spline.GetCurrentValue(2.0f).x, 10.0f));
}

void TestZiplineGeneration() {
    idNonUniformBSpline<idVec3> spline;
    spline.SetOrder(2);
    spline.AddValue(0.0f, idVec3(0.0f, 0.0f, 0.0f));
    spline.AddValue(1.0f, idVec3(0.0f, 0.0f, 10.0f));

    idDrawVert vertices[32] = {};
    std::uint16_t indices[128] = {};
    int numVertices = 0;
    int numIndices = 0;
    zipLineGenParms_t parms = {};
    parms.controlSpline = &spline;
    parms.splineTessellationDistance = 5;
    parms.splineMaxSubdivisions = 8;
    parms.cableSubdivisions = 4;
    parms.cableDiameter = 2.0f;
    parms.maxVertices = 32;
    parms.maxIndices = 128;
    parms.vertices = vertices;
    parms.indices = indices;
    parms.numVertices = &numVertices;
    parms.numIndices = &numIndices;
    GenZipline(&parms);

    assert(numVertices == 12);
    assert(numIndices == 48);
    assert(Near(vertices[0].xyz.z, 0.0f));
    assert(Near(vertices[8].xyz.z, 10.0f));
}

void TestParticleStage() {
    idParticleStage stage;
    assert(stage.systemProperties.totalParticles == 20);
    assert(Near(stage.maxParticleLife, 1.5f));
    assert(stage.cycleMsec == 1500);
    assert(stage.NumVertsPerParticle() == 4);
    stage.orientation.type = POR_TRAIL;
    stage.orientation.numTrails = 2;
    assert(stage.NumVertsPerParticle() == 12);
    idDrawVert staticVertices[24] = {};
    stage.SetStaticMesh(reinterpret_cast<const idStaticParticleModelData*>(1),
        staticVertices, 24);
    assert(stage.NumVertsPerParticle() == 24);
}

void TestParticleGeneration() {
    idParticleParm parameter = {};
    idRandom2 random(17);
    SetParticleParmAsEval(&parameter, 0.0f, 10.0f, 0.0f);
    assert(Near(parameter.Compute(nullptr, 0.25f, random), 2.5f));
    SetParticleParmAsIntegrate(&parameter, 0.0f, 10.0f, 0.0f);
    assert(Near(parameter.Compute(nullptr, 0.5f, random), 1.25f));

    idParticleStage stage;
    stage.systemProperties.totalParticles = 1;
    SetParticleParmAsConstant(&stage.systemProperties.particleLife, 1.0f);
    stage.CalculateBounds(nullptr);

    particleRenderView_t view = {};
    view.viewOrg.Set(0.0f, 0.0f, -10.0f);
    view.viewFwd.Set(0.0f, 0.0f, 1.0f);
    view.viewLeft.Set(1.0f, 0.0f, 0.0f);
    view.viewUp.Set(0.0f, 1.0f, 0.0f);
    view.renderTime = 500;
    view.atlasWidth = 1;
    view.atlasHeight = 1;

    effectParticleParms_t effect = {};
    effect.startTime = 0;
    effect.duration = 1000;
    effect.stage = &stage;
    effect.diversity = 11;
    effect.axis = idMat3(1.0f);
    effect.currTime = 500;
    effect.color = 0xFFFFFFFFu;

    idTransparencyVert vertices[4] = {};
    float depth = 0.0f;
    int quadsUsed = 0;
    deferredParticleGenParms_t parms = {};
    parms.renderView = &view;
    parms.effectParticleParms = &effect;
    parms.numEffectParticleParms = 1;
    parms.maxVertsToGen = 4;
    parms.verts = vertices;
    parms.quadDepth = &depth;
    parms.quadsUsed = &quadsUsed;
    ParticleGenJob(&parms);

    assert(quadsUsed == 1);
    assert(Near(depth, 10.0f));
    assert(vertices[0].color[0] == 255);
    assert(vertices[0].color[3] > 0);
    assert((vertices[1].xyz - vertices[0].xyz).LengthSqr() > 1.0f);
    assert(vertices[0].st[0] < 0 && vertices[2].st[0] > 0);

    stage.orientation.type = POR_TRAIL;
    stage.orientation.numTrails = 2;
    stage.orientation.segmentLength = 0.1f;
    stage.CalculateBounds(nullptr);
    idTransparencyVert trailVertices[12] = {};
    float trailDepth[3] = {};
    quadsUsed = 0;
    parms.verts = trailVertices;
    parms.quadDepth = trailDepth;
    parms.maxVertsToGen = 12;
    ParticleGenJob(&parms);
    assert(quadsUsed == 3);
    assert(trailVertices[0].color[3] > 0);

    idDrawVert staticVertices[4] = {};
    staticVertices[0].xyz.Set(-1.0f, -1.0f, 0.0f);
    staticVertices[1].xyz.Set(1.0f, -1.0f, 0.0f);
    staticVertices[2].xyz.Set(1.0f, 1.0f, 0.0f);
    staticVertices[3].xyz.Set(-1.0f, 1.0f, 0.0f);
    staticVertices[0].st.Set(0.0f, 0.0f);
    staticVertices[1].st.Set(1.0f, 0.0f);
    staticVertices[2].st.Set(1.0f, 1.0f);
    staticVertices[3].st.Set(0.0f, 1.0f);
    for (idDrawVert& vertex : staticVertices) {
        for (int component = 0; component < 4; ++component) {
            vertex.color[component] = 255;
        }
    }
    stage.orientation.type = POR_VIEW;
    stage.orientation.numTrails = 0;
    stage.SetStaticMesh(reinterpret_cast<const idStaticParticleModelData*>(1),
        staticVertices, 4);
    idTransparencyVert generatedStatic[4] = {};
    quadsUsed = 0;
    parms.verts = generatedStatic;
    parms.quadDepth = &depth;
    parms.maxVertsToGen = 4;
    ParticleGenJob(&parms);
    assert(quadsUsed == 1);
    assert((generatedStatic[2].xyz - generatedStatic[0].xyz).LengthSqr()
        > 1.0f);
    assert(generatedStatic[0].color[3] > 0);
}

void TestSkeletalUtilities() {
    idUserChannelExpression::SetLookupCallback(&LookUpTestChannel);
    idUserChannelExpression expression;
    assert(expression.Parse("speed * 2 + 1", nullptr));
    const float channels[2] = { 0.0f, 3.0f };
    assert(Near(expression.Eval(channels, 2), 7.0f));

    idEyeInfo info;
    info.name = "primary";
    idEyeInfoCollection collection;
    const eyeInfoHandle_t handle = collection.AddEyeInfo(info);
    assert(handle.IsValid());
    assert(collection.GetEyeInfo(handle) != nullptr);
    assert(collection.FindEyeInfoHandle("primary") == handle);
    collection.Free();
}

void TestAllocators() {
    idMD6Allocator_New heapAllocator;
    idMD6Node* branch = heapAllocator.Alloc(idMD6Node::NODE_BRANCH);
    idMD6Node* play = heapAllocator.Alloc(idMD6Node::NODE_LEAF_PLAY);
    assert(branch != nullptr && play != nullptr);
    assert(heapAllocator.NumNodes() == 2);
    assert(heapAllocator.Size() == 64);
    assert(static_cast<idMD6Branch*>(branch)->leftTimeOverride == -1);
    heapAllocator.Free(branch);
    assert(heapAllocator.NumNodes() == 1);
    assert(heapAllocator.NodeForIndex(-1) == nullptr);

    idMD6BlockAlloc blockAllocator;
    idMD6Node* pooledBranch = blockAllocator.Alloc(idMD6Node::NODE_BRANCH);
    idMD6Node* pause = blockAllocator.Alloc(idMD6Node::NODE_LEAF_PAUSE);
    assert(pooledBranch != nullptr && pause != nullptr);
    assert(blockAllocator.NumNodes() == 2);
    assert(blockAllocator.Size() == 556);
    blockAllocator.Free(pooledBranch);
    blockAllocator.DeferredFree();
    assert(blockAllocator.NumNodes() == 1);
    const unsigned int pooledSize = blockAllocator.Size();
    assert(blockAllocator.Alloc(idMD6Node::NODE_BRANCH) == pooledBranch);
    assert(blockAllocator.Size() == pooledSize);
}

void TestInfluenceSphereCull() {
    influenceSphere_t spheres[3] = {};
    spheres[0].center.Set(0.0f, 0.0f, 10.0f);
    spheres[0].innerRadius = 0.5f;
    spheres[0].outerRadius = 1.0f;
    spheres[0].angle = 0.75f;
    spheres[1].center.Set(0.0f, 0.0f, -10.0f);
    spheres[1].outerRadius = 1.0f;
    spheres[2].center.Set(20.0f, 0.0f, 10.0f);
    spheres[2].outerRadius = 1.0f;

    visibleInfluenceSpheres_t visible = {};
    influenceSphereCullParms_t parms = {};
    parms.nearDist = 0.1f;
    parms.farDist = 100.0f;
    parms.fov.Set(1.0f, 1.0f);
    parms.viewOrg.Set(0.0f, 0.0f, 0.0f);
    parms.viewFwd.Set(0.0f, 0.0f, 1.0f);
    parms.viewLeft.Set(1.0f, 0.0f, 0.0f);
    parms.viewUp.Set(0.0f, 1.0f, 0.0f);
    parms.influenceSpheres = spheres;
    parms.numInfluenceSpheres = 3;
    parms.visibleInfluenceSpheres = &visible;
    CullInfluenceSpheresForView(&parms);

    assert(visible.numSpheres == 1);
    assert(Near(visible.spheres[0].center.z, 10.0f));
    assert(Near(visible.spheres[0].angle, 0.75f));
}

void TestWaterSurfaceSim() {
    idBounds bounds;
    bounds[0].Set(0.0f, 0.0f, 0.0f);
    bounds[1].Set(32.0f, 32.0f, 1.0f);
    idWaterSurfaceSim simulation(bounds, 1.0f, 0.98f, 1.0f, 0.016f);
    assert(simulation.width == 32 && simulation.height == 32);
    assert(simulation.GridIndex(0, 0) == 0);
    assert(simulation.GridIndex(16, 0) == 256);
    assert(simulation.GridIndex(0, 16) == 512);

    simulation.visible = true;
    simulation.AddWave(idVec2(1.0f, 0.0f), 2.0f, 0.25f, 0.5f, 1.0f);
    simulation.AddDrop(4, 5, 2.0f, 0.75f);
    assert(simulation.numDisturbances == 2);
    assert(simulation.waterDisturbances[0][0].type ==
        WATER_DISTURBANCE_TYPE_WAVE);
    assert(simulation.waterDisturbances[0][1].type ==
        WATER_DISTURBANCE_TYPE_DROPLET);

    simulation.SetSimulationParms(1, 1,
        idVec4(1.0f, 0.5f, 0.25f, 0.0f));
    assert(simulation.simulateParms[simulation.GridIndex(1, 1)] ==
        0x007FFF3Fu);
    simulation.ApplyRadiusEffect(idVec3(4.0f, 4.0f, 1.0f), nullptr,
        3.0f, 1.0f);
    assert(simulation.vertGradient[simulation.GridIndex(4, 4)] < 255);
    simulation.ClearRadiusEffects();
    assert(simulation.vertGradient[simulation.GridIndex(4, 4)] == 255);

    simulation.Swap();
    assert(simulation.numDisturbances == 0);
    simulation.waveHeight[0][simulation.GridIndex(1, 1)] = 1.0f;
    simulation.waveHeight[0][simulation.GridIndex(2, 1)] = 1.0f;
    simulation.waveHeight[0][simulation.GridIndex(1, 2)] = 1.0f;
    simulation.waveHeight[0][simulation.GridIndex(2, 2)] = 1.0f;
    idVec3 point(1.5f, 1.5f, 1.0f);
    idVec3 normal;
    float height = 0.0f;
    assert(simulation.GetSurfacePositionAtPoint(point, nullptr, height,
        normal));
    assert(Near(height, 1.0f));
    assert(Near(point.z, 2.0f));
    assert(Near(normal.z, 1.0f));
}

void TestWaterBlockGeneration() {
    int gridX = -1;
    int gridY = -1;
    BlockToGridPos(1, 2, 3, 4, gridX, gridY);
    assert(gridX == 19 && gridY == 36);
    assert(GridPosToBlockLoc(17, 2, 2, 2) == 289);
    assert(BlockPosToBlockLoc(1, 1, 2) == 768);

    float current[256] = {};
    float previous[256] = {};
    float outputHeights[256] = {};
    float neighbors[256] = {};
    unsigned int simulationParms[256];
    unsigned char gradients[256];
    idDrawVert vertices[256] = {};
    for (int index = 0; index < 256; ++index) {
        simulationParms[index] = 0x000000FFu;
        gradients[index] = 123;
    }

    waterDisturbanceParms_t drop = {};
    drop.type = WATER_DISTURBANCE_TYPE_DROPLET;
    drop.gridX = 8;
    drop.gridY = 8;
    drop.parms.x = 1.0f;
    drop.radius = 2.0f;

    deferredWaterBlockGenParms_t parms = {};
    parms.currBlock = current;
    parms.currBlockL = neighbors;
    parms.currBlockR = neighbors;
    parms.currBlockU = neighbors;
    parms.currBlockD = neighbors;
    parms.simulationParms = simulationParms;
    parms.vertGradient = gradients;
    parms.disturbances = &drop;
    parms.numDisturbances = 1;
    parms.spacing = 1.0f;
    parms.speed = 0.0f;
    parms.damping = 0.0f;
    parms.timeDelta = 1.0f;
    parms.gridWidth = 16;
    parms.gridHeight = 16;
    parms.verts = vertices;
    parms.prevBlock = outputHeights;

    ApplyDisturbances(&parms);
    assert(Near(current[8 * 16 + 8], 1.0f));
    assert(Near(current[0], 0.0f));

    GenWaterSurface(&parms, previous);
    assert(Near(outputHeights[8 * 16 + 8], 1.99f));
    assert(Near(vertices[8 * 16 + 8].xyz.x, 8.0f));
    assert(Near(vertices[8 * 16 + 8].xyz.y, 8.0f));
    assert(Near(vertices[8 * 16 + 8].xyz.z, 1.99f));
    assert(vertices[8 * 16 + 8].color[0] == 123);
}

void TestStaticTransparencyGen() {
    idDrawVert input[4] = {};
    input[0].xyz.Set(0.0f, 0.0f, 2.0f);
    input[1].xyz.Set(1.0f, 0.0f, 2.0f);
    input[2].xyz.Set(1.0f, 1.0f, 2.0f);
    input[3].xyz.Set(0.0f, 1.0f, 2.0f);
    for (int index = 0; index < 4; ++index) {
        input[index].SetNormal(idVec3(0.0f, 0.0f, 1.0f));
    }
    input[0].st.Set(0.0f, 0.0f);
    input[1].st.Set(1.0f, 0.0f);
    input[2].st.Set(1.0f, 1.0f);
    input[3].st.Set(0.0f, 1.0f);

    idTransparencyVert output[4] = {};
    float depth = 0.0f;
    int quadsUsed = 0;
    staticTransparencyGenParms_t parms = {};
    parms.inputVerts = input;
    parms.numInputVerts = 4;
    parms.fadeStartDist = 0.0f;
    parms.fadeMaxDist = 10.0f;
    parms.axis = idMat3(1.0f);
    parms.viewDir.Set(0.0f, 0.0f, 1.0f);
    parms.transSortScaleBias.Set(1.0f, 1.0f, 0.0f, 0.0f);
    for (idVec4& channel : parms.lighting.channelLighting) {
        channel.Set(0.0f, 0.0f, 0.0f, 0.0f);
    }
    parms.lighting.channelLighting[4].Set(1.0f, 1.0f, 1.0f, 0.0f);
    parms.verts = output;
    parms.quadDepth = &depth;
    parms.quadsUsed = &quadsUsed;
    StaticTransparencyGenJob(&parms);

    assert(quadsUsed == 1);
    assert(Near(depth, 2.0f));
    assert(output[0].color[0] >= 254);
    assert(output[0].color[1] >= 254);
    assert(output[0].color[2] >= 254);
    assert(output[0].color[3] == 204);
}

void TestTransparencySort() {
    idTransparencyVert vertices[12] = {};
    float depths[3] = { 2.0f, 5.0f, -1.0f };
    std::uint8_t emissive[3] = {};
    std::uint16_t indices[18] = {};
    std::uint16_t emissiveIndices[18] = {};
    transSortSegmentInfo_t segment = {};
    segment.segmentOffset = 0;
    segment.quadsAllocated = 3;
    segment.quadsUsed = 3;
    segment.emissivePass = true;
    transSortResult_t result = {};
    transSortParms_t parms = {};
    parms.verts = vertices;
    parms.quadDepths = depths;
    parms.emissiveQuads = emissive;
    parms.segmentInfo = &segment;
    parms.numSegmentAllocations = 1;
    parms.sort = true;
    parms.indices = indices;
    parms.maxIndices = 18;
    parms.indices2 = emissiveIndices;
    parms.maxIndices2 = 18;
    parms.sortResult = &result;

    assert(TransparencySortQuads(&parms) == 2);
    assert(TransparencyTriIndGen(&parms, 0) == 2);
    assert(indices[0] == 4 && indices[1] == 6 && indices[2] == 7);
    assert(TransparencyEmissiveTriIndGen(&parms, 0) == 2);
    assert(emissiveIndices[0] == 4);
}

void TestTransparencyBin() {
    idTransparencyVert vertices[4] = {};
    vertices[2].xyz.Set(128.0f, 2.0f, 2.0f);
    vertices[3].xyz.Set(128.0f, 4.0f, 2.0f);
    vertices[1].xyz.Set(128.0f, 4.0f, 4.0f);
    vertices[0].xyz.Set(128.0f, 2.0f, 4.0f);
    const std::uint16_t inputIndices[6] = {0, 1, 2, 0, 2, 3};

    std::vector<bin_t> bins(TRANSPARENCY_BIN_COUNT);
    std::vector<node_t> nodes(TRANSPARENCY_BIN_NODE_COUNT);
    std::vector<idTransparencyVert> temporaryVertices(4096);
    std::vector<int> vertexRemap(4096);
    std::vector<idTransparencyVert> outputVertices(4096);
    std::vector<std::uint16_t> outputIndices(4096);

    deferredTransparencyBinParms_t parms = {};
    parms.verts = vertices;
    parms.numVerts = 4;
    parms.indices = inputIndices;
    parms.numIndices = 6;
    parms.viewOrigin.Set(0.0f, 0.0f, 0.0f);
    parms.viewAxis = idMat3(1.0f);
    parms.fovX = 1.0f;
    parms.fovY = 1.0f;
    parms.bins = bins.data();
    parms.nodes = nodes.data();
    parms.tempBinVerts = temporaryVertices.data();
    parms.maxBinVerts = static_cast<int>(temporaryVertices.size());
    parms.vertexRemap = vertexRemap.data();
    parms.binVerts = outputVertices.data();
    parms.binIndices = outputIndices.data();
    parms.maxBinIndices = static_cast<int>(outputIndices.size());

    BinQuads(&parms);
    assert(parms.numBins == TRANSPARENCY_BIN_COUNT);
    assert(parms.numNodes == TRANSPARENCY_BIN_NODE_COUNT - 1);
    assert(parms.numBinVerts >= 4);
    assert(parms.numBinIndices >= 6 && parms.numBinIndices % 3 == 0);
    for (int index = 0; index < parms.numBinIndices; ++index) {
        assert(outputIndices[index] < parms.numBinVerts);
    }
}

void TestClothGeneration() {
    idClothParticle particles[4] = {};
    for (idClothParticle& particle : particles) {
        particle.Reset();
        particle.mass = 1.0f;
    }
    particles[0].origin.Set(0.0f, 0.0f, 0.0f);
    particles[1].origin.Set(1.0f, 0.0f, 0.0f);
    particles[2].origin.Set(0.0f, 1.0f, 0.0f);
    particles[3].origin.Set(1.0f, 1.0f, 0.0f);
    for (idClothParticle& particle : particles) {
        particle.lastOrigin = particle.origin;
    }
    particles[0].anchored = 1;
    particles[1].anchored = 1;

    idClothSpring springs[4];
    springs[0].Init(0.0f, particles, 0, 2, false, false);
    springs[1].Init(0.0f, particles, 1, 3, false, false);
    springs[2].Init(0.0f, particles, 2, 3, false, false);
    springs[3].Init(0.0f, particles, 0, 1, false, false);
    idDrawVert vertices[4] = {};
    idBounds bounds = {};
    clothParms_t parms = {};
    parms.type = CLOTH_SQUARE;
    parms.cloth = particles;
    parms.numClothParticles = 4;
    parms.springs = springs;
    parms.numSprings = 4;
    parms.vertices = vertices;
    parms.bounds = &bounds;
    parms.axis = idMat3(1.0f);
    parms.gravity.Set(0.0f, 0.0f, -10.0f);
    parms.width = 2;
    parms.height = 2;
    parms.timeDelta = 0.1f;
    parms.numIterations = 4;
    parms.rect = true;
    ClothGenJob(parms);

    assert(Near(particles[0].origin.z, 0.0f));
    assert(particles[2].origin.z < 0.0f);
    assert(bounds[0].z < 0.0f && Near(bounds[1].z, 0.0f));
    assert(vertices[2].normal[3] == 0);

    idSphere collision(idVec3(0.0f, 0.0f, 0.0f), 1.0f);
    idClothParticle colliding = {};
    colliding.Reset();
    colliding.origin.Set(0.0f, 0.0f, 0.25f);
    colliding.Collide(&collision, 1.0f);
    assert(Near(colliding.origin.Length(), 1.0f));
    assert(SphereLineIntersection(idVec3(0.0f, 0.0f, 0.0f),
        1.0f, idVec3(-2.0f, 0.0f, 0.0f),
        idVec3(2.0f, 0.0f, 0.0f)));
}

void TestDetailGatherAndGeneration() {
    alignas(16) std::uint8_t treeBuffer[
        sizeof(dm_subTreeTreeNodes_t) + sizeof(dm_treeNode_t)] = {};
    dm_subTreeTreeNodes_t* treeHeader =
        reinterpret_cast<dm_subTreeTreeNodes_t*>(treeBuffer);
    treeHeader->numTreeNodes = 1;
    treeHeader->treeNodeOffset = sizeof(dm_subTreeTreeNodes_t);
    dm_treeNode_t* tree = reinterpret_cast<dm_treeNode_t*>(
        treeBuffer + treeHeader->treeNodeOffset);
    tree->planeType = static_cast<std::uint16_t>((1 << 2) | (1 << 9));
    tree->planeDist = 0;
    tree->children[0] = 0x8000;
    tree->children[1] = 0x8001;
    tree->counts[0] = (3u << 16) | 3u;
    tree->counts[1] = (3u << 16) | 3u;

    dm_subTreeBounds_t treeBounds = {};
    treeBounds.b[0][0] = treeBounds.b[0][1] =
        treeBounds.b[0][2] = -1;
    treeBounds.b[1][0] = treeBounds.b[1][1] =
        treeBounds.b[1][2] = 1;
    detailRenderView_t view = {};
    view.nearDist = 0.1f;
    view.farDist = 1.0f;
    view.fov[0] = view.fov[1] = 1.0f;
    view.viewFwd.Set(0.0f, 0.0f, 1.0f);
    view.viewLeft.Set(1.0f, 0.0f, 0.0f);
    view.viewUp.Set(0.0f, 1.0f, 0.0f);
    view.mvpMatrix.Identity();
    std::uint16_t gathered[4] = {};
    detailSubTreeStats_t gatherStats = {};
    deferredDetailGatherParms_t gatherParms = {};
    gatherParms.viewData = &view;
    gatherParms.subTreeBounds = &treeBounds;
    gatherParms.subTreeTreeNodes = treeHeader;
    gatherParms.subTreeTreeNodesSize = sizeof(treeBuffer);
    gatherParms.detailCount = &gatherStats;
    gatherParms.detailIndices = gathered;
    gatherParms.maxDetailIndices = 4;
    int gatheredCount = 0;
    GatherDetailIndicesForSubTree(&gatherParms, gatheredCount);
    assert(gatheredCount == 2);
    assert(gathered[0] == 0 && gathered[1] == 1);
    assert(gatherStats.vertCount == 6 && gatherStats.indexCount == 6);

    detailPaletteEntry_t entry = {0, 0, 3, 3};
    detailPaletteVert_t packedVertices[3] = {};
    packedVertices[0].xyz[0] = 0;
    packedVertices[1].xyz[0] = 10;
    packedVertices[2].xyz[1] = 10;
    const std::uint16_t packedIndices[3] = {0, 1, 2};
    dm_detail_t placement = {};
    placement.xyz[0] = 5;
    placement.xyz[1] = 6;
    placement.xyz[2] = 7;
    placement.uniformSizeScale = 100;
    placement.color[0] = 10;
    placement.color[1] = 20;
    placement.color[2] = 30;
    idDrawVert generated[3] = {};
    std::uint16_t generatedIndices[3] = {};
    detailGenTotals_t totals = {};
    const detailPalette_t palette = {
        &entry, packedVertices, packedIndices
    };
    BuildDetailModel(palette, generated, generatedIndices, 0,
        &placement, nullptr, totals);
    assert(totals.totalVerts == 3 && totals.totalIndices == 3);
    assert(Near(generated[0].xyz.x, 5.0f));
    assert(Near(generated[1].xyz.x, 15.0f));
    assert(Near(generated[2].xyz.y, 16.0f));
    assert(generated[0].color[0] == 10
        && generated[0].color[3] == 255);
    assert(generatedIndices[0] == 0 && generatedIndices[2] == 2);
}

void TestFoliageGeneration() {
    fm_foliage_t foliage = {};
    foliage.xyz[0] = 2;
    foliage.xyz[1] = 3;
    foliage.xyz[2] = 4;
    foliage.uniformSizeScale = 100;
    foliage.color[0] = 50;
    foliage.color[1] = 100;
    foliage.color[2] = 150;
    foliage.upVec[0] = 128;
    foliage.upVec[1] = 128;
    foliage.upVec[2] = 255;
    fm_attribute_t attribute = {};
    attribute.quadWidth = 4;
    attribute.quadHeight = 10;
    attribute.sortScaleBias[0] = 1.0f;
    attribute.sortScaleBias[1] = 1.0f;
    foliageRenderView_t view = {};
    view.viewOrg.Set(2.0f, -10.0f, 4.0f);
    view.viewFwd.Set(0.0f, 1.0f, 0.0f);
    view.viewLeft.Set(1.0f, 0.0f, 0.0f);
    view.viewUp.Set(0.0f, 0.0f, 1.0f);
    view.atlasWidth = view.atlasHeight = 256;
    idTransparencyVert vertices[4] = {};
    float depth = 0.0f;
    const std::int16_t noSpheres[1] = {-1};
    assert(BuildFoliageQuad(vertices, &depth, 0, &foliage,
        &attribute, &view, nullptr, noSpheres, 100.0f, 200.0f,
        300.0f) == 4);
    assert((vertices[1].xyz - vertices[0].xyz).LengthSqr() > 15.0f);
    assert(vertices[2].xyz.z > 13.0f);
    assert(vertices[0].color[0] == 50 && vertices[0].color[3] == 255);
    assert(depth > 10.0f);

    idBounds bounds;
    CalculateFoliageBounds(&foliage, &attribute, bounds);
    assert(bounds[0].x < 2.0f && bounds[1].x > 2.0f);
    assert(bounds[1].z > 13.0f);
}

} // namespace

int main() {
    TestContour();
    TestContourManager();
    TestCutterGraph();
    TestCutterClip();
    TestConvexHull();
    TestEarClipTriangulation();
    TestTriangleInterpolator();
    TestSpline();
    TestZiplineGeneration();
    TestParticleStage();
    TestParticleGeneration();
    TestSkeletalUtilities();
    TestAllocators();
    TestInfluenceSphereCull();
    TestWaterSurfaceSim();
    TestWaterBlockGeneration();
    TestStaticTransparencyGen();
    TestTransparencySort();
    TestTransparencyBin();
    TestClothGeneration();
    TestDetailGatherAndGeneration();
    TestFoliageGeneration();
    return 0;
}
