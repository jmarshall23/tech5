#include "models/static/staticmodelimport.h"
#include "models/static/staticmodel.h"

#include "idlib/filesystem/filesystem.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
#include <unordered_map>

namespace {

std::string Trim(const std::string& input) {
    std::size_t first = 0, last = input.size();
    while (first < last && std::isspace(
        static_cast<unsigned char>(input[first]))) ++first;
    while (last > first && std::isspace(
        static_cast<unsigned char>(input[last - 1]))) --last;
    return input.substr(first, last - first);
}

int ResolveIndex(const int parsed, const int count) {
    if (parsed > 0) return parsed - 1;
    if (parsed < 0) return count + parsed;
    return -1;
}

idImportCorner ParseCorner(const std::string& token,
        const idOBJModel& model) {
    idImportCorner corner;
    int values[3] = {0, 0, 0};
    int field = 0;
    std::size_t start = 0;
    while (field < 3 && start <= token.size()) {
        const std::size_t slash = token.find('/', start);
        const std::string component = token.substr(start,
            slash == std::string::npos ? std::string::npos : slash - start);
        if (!component.empty()) values[field] = std::atoi(component.c_str());
        ++field;
        if (slash == std::string::npos) break;
        start = slash + 1;
    }
    corner.position = ResolveIndex(values[0],
        static_cast<int>(model.positions.size()));
    corner.texCoord = ResolveIndex(values[1],
        static_cast<int>(model.texCoords.size()));
    corner.normal = ResolveIndex(values[2],
        static_cast<int>(model.normals.size()));
    return corner;
}

int MaterialIndex(idOBJModel& model,
        std::unordered_map<std::string, int>& lookup,
        const std::string& name) {
    const auto found = lookup.find(name);
    if (found != lookup.end()) return found->second;
    const int index = static_cast<int>(model.materials.size());
    model.materials.push_back({name, "", false});
    lookup.emplace(name, index);
    return index;
}

bool ReadTextFile(const char* fileName, std::string& text,
        unsigned int* timestamp = nullptr) {
    if (fileSystem == nullptr || fileName == nullptr) return false;
    void* buffer = nullptr;
    const int length = fileSystem->ReadFile(fileName, &buffer, timestamp);
    if (length < 0 || buffer == nullptr) return false;
    text.assign(static_cast<const char*>(buffer),
        static_cast<std::size_t>(length));
    fileSystem->FreeFile(buffer);
    return true;
}

const char* MaterialName(const idMaterial* material) {
    return idStaticModel::MaterialName(material);
}

} // namespace

bool idOBJModel::Load(const char* fileName) {
    std::string text;
    if (!ReadTextFile(fileName, text)) return false;
    positions.clear();
    texCoords.clear();
    normals.clear();
    colors.clear();
    materials.clear();
    triangles.clear();

    std::unordered_map<std::string, int> materialLookup;
    int currentMaterial = MaterialIndex(*this, materialLookup, "_default");
    unsigned int smoothing = 0;
    std::istringstream stream(text);
    std::string line;
    while (std::getline(stream, line)) {
        const std::size_t comment = line.find('#');
        if (comment != std::string::npos) line.erase(comment);
        line = Trim(line);
        if (line.empty()) continue;
        std::istringstream fields(line);
        std::string command;
        fields >> command;
        if (command == "v") {
            idVec3 position;
            fields >> position.x >> position.y >> position.z;
            positions.push_back(position);
            float r, g, b, a = 1.0f;
            if (fields >> r >> g >> b) {
                fields >> a;
                const auto byte = [](float value) {
                    return static_cast<std::uint32_t>((std::max)(0,
                        (std::min)(255, static_cast<int>(value * 255.0f +
                            0.5f))));
                };
                colors.push_back(byte(r) | (byte(g) << 8) |
                    (byte(b) << 16) | (byte(a) << 24));
            }
        } else if (command == "vt") {
            idVec2 texCoord;
            fields >> texCoord.x >> texCoord.y;
            texCoords.push_back(texCoord);
        } else if (command == "vn") {
            idVec3 normal;
            fields >> normal.x >> normal.y >> normal.z;
            normals.push_back(normal);
        } else if (command == "usemtl") {
            std::string name;
            std::getline(fields, name);
            currentMaterial = MaterialIndex(*this, materialLookup,
                Trim(name));
        } else if (command == "s") {
            std::string value;
            fields >> value;
            smoothing = value == "off" || value == "0" ? 0u
                : static_cast<unsigned int>(std::strtoul(value.c_str(),
                    nullptr, 10));
        } else if (command == "f") {
            std::vector<idImportCorner> polygon;
            std::string cornerToken;
            while (fields >> cornerToken) {
                idImportCorner corner = ParseCorner(cornerToken, *this);
                if (corner.position >= 0 &&
                    corner.position < static_cast<int>(positions.size())) {
                    if (corner.position < static_cast<int>(colors.size()))
                        corner.color = corner.position;
                    polygon.push_back(corner);
                }
            }
            for (std::size_t corner = 1; corner + 1 < polygon.size();
                 ++corner) {
                idImportTriangle triangle;
                triangle.corners[0] = polygon[0];
                triangle.corners[1] = polygon[corner];
                triangle.corners[2] = polygon[corner + 1];
                triangle.material = currentMaterial;
                triangle.smoothingGroup = smoothing;
                triangles.push_back(triangle);
            }
        }
    }
    return !triangles.empty();
}

bool idOBJModel::Save(const char* fileName) const {
    if (fileSystem == nullptr || fileName == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileWrite(fileName, FSPATH_BASE));
    if (file.file == nullptr) return false;
    for (const idVec3& position : positions)
        file->Printf("v %.9g %.9g %.9g\n", position.x, position.y,
            position.z);
    for (const idVec2& texCoord : texCoords)
        file->Printf("vt %.9g %.9g\n", texCoord.x, texCoord.y);
    for (const idVec3& normal : normals)
        file->Printf("vn %.9g %.9g %.9g\n", normal.x, normal.y, normal.z);
    int lastMaterial = -2;
    for (const idImportTriangle& triangle : triangles) {
        if (triangle.material != lastMaterial) {
            const char* name = triangle.material >= 0 &&
                    triangle.material < static_cast<int>(materials.size())
                ? materials[triangle.material].name.c_str() : "_default";
            file->Printf("usemtl %s\n", name);
            lastMaterial = triangle.material;
        }
        file->Printf("f");
        for (const idImportCorner& corner : triangle.corners) {
            file->Printf(" %d", corner.position + 1);
            if (corner.texCoord >= 0 || corner.normal >= 0) {
                file->Printf("/%s", corner.texCoord >= 0
                    ? std::to_string(corner.texCoord + 1).c_str() : "");
                if (corner.normal >= 0)
                    file->Printf("/%d", corner.normal + 1);
            }
        }
        file->Printf("\n");
    }
    return true;
}

bool idOBJModel::AddGroupGeometry(const char* groupName,
        const idList<idTriangles*, 5>& geometry,
        const idList<const idMaterial*, 5>& groupMaterials) {
    if (geometry.Num() != groupMaterials.Num()) return false;
    for (int surface = 0; surface < geometry.Num(); ++surface) {
        const idTriangles* trianglesIn = geometry[surface];
        if (trianglesIn == nullptr || trianglesIn->verts == nullptr ||
            trianglesIn->indexes == nullptr) continue;
        idImportMaterial material;
        material.name = MaterialName(groupMaterials[surface]);
        if (material.name.empty()) material.name = groupName != nullptr
            ? groupName : "_default";
        const int materialIndex = static_cast<int>(materials.size());
        materials.push_back(material);
        const int positionBase = static_cast<int>(positions.size());
        const int texCoordBase = static_cast<int>(texCoords.size());
        const int normalBase = static_cast<int>(normals.size());
        for (int vertex = 0; vertex < trianglesIn->numVerts; ++vertex) {
            positions.push_back(trianglesIn->verts[vertex].xyz);
            texCoords.push_back(trianglesIn->verts[vertex].st);
            normals.push_back(trianglesIn->verts[vertex].GetNormal());
        }
        for (int index = 0; index + 2 < trianglesIn->numIndexes; index += 3) {
            idImportTriangle triangle;
            triangle.material = materialIndex;
            for (int corner = 0; corner < 3; ++corner) {
                const int vertex = trianglesIn->indexes[index + corner];
                triangle.corners[corner].position = positionBase + vertex;
                triangle.corners[corner].texCoord = texCoordBase + vertex;
                triangle.corners[corner].normal = normalBase + vertex;
            }
            triangles.push_back(triangle);
        }
    }
    return true;
}

idOBJModel* OBJ_Load(const char* fileName) {
    idOBJModel* model = new idOBJModel;
    if (!model->Load(fileName)) {
        delete model;
        return nullptr;
    }
    return model;
}
