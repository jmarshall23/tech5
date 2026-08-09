#include "models/skeletalanimation/md6model.h"

#include <cstdio>

namespace {

void PrintDrawVertex(const int index, const idDrawVert& vertex) {
    std::printf("%5d: XYZ:(%f %f %f) ST:(%f %f) "
        "color:(%u %u %u %u) normal:(%u %u %u %u) "
        "tangent:(%u %u %u %u)\n", index,
        vertex.xyz.x, vertex.xyz.y, vertex.xyz.z,
        vertex.st.x, vertex.st.y,
        vertex.color[0], vertex.color[1], vertex.color[2], vertex.color[3],
        vertex.normal[0], vertex.normal[1], vertex.normal[2], vertex.normal[3],
        vertex.tangent[0], vertex.tangent[1], vertex.tangent[2],
        vertex.tangent[3]);
}

void PrintTriangles(const idTriangles* triangles) {
    if (triangles == nullptr) {
        std::printf("<NULL>\n");
        return;
    }
    if (triangles->verts != nullptr) {
        for (int vertex = 0; vertex < triangles->numVerts; ++vertex)
            PrintDrawVertex(vertex, triangles->verts[vertex]);
    }
    if (triangles->indexes != nullptr) {
        for (int index = 0; index + 2 < triangles->numIndexes; index += 3) {
            std::printf("%5d: (%u %u %u)\n", index / 3,
                triangles->indexes[index], triangles->indexes[index + 1],
                triangles->indexes[index + 2]);
        }
    }
}

} // namespace

void idMD6Model::PrintDetailed() const {
    std::printf("----------------------------- %s "
        "----------------------------\n", GetName());
    std::printf("    verts tris  material\n");
    for (int index = 0; index < meshes.Num(); ++index) {
        const idMD6Mesh* mesh = meshes[index];
        std::printf("----- mesh %d : %s -----\n", index,
            mesh != nullptr ? mesh->name.c_str() : "<NULL>");
        PrintTriangles(mesh != nullptr ? mesh->tris : nullptr);
    }
}

