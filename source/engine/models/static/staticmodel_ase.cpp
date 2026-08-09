#include "models/static/staticmodelimport.h"

#include "idlib/filesystem/filesystem.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

std::string Trim(const std::string& input) {
    std::size_t first = 0, last = input.size();
    while (first < last && std::isspace(
        static_cast<unsigned char>(input[first]))) ++first;
    while (last > first && std::isspace(
        static_cast<unsigned char>(input[last - 1]))) --last;
    return input.substr(first, last - first);
}

std::string Quoted(const std::string& line) {
    const std::size_t first = line.find('"');
    const std::size_t last = line.rfind('"');
    return first != std::string::npos && last > first
        ? line.substr(first + 1, last - first - 1) : std::string();
}

int CountChar(const std::string& line, const char value) {
    return static_cast<int>(std::count(line.begin(), line.end(), value));
}

unsigned int ParseSmoothing(const std::string& text) {
    unsigned int mask = 0;
    std::size_t cursor = 0;
    while (cursor < text.size()) {
        while (cursor < text.size() && (text[cursor] == ',' ||
            std::isspace(static_cast<unsigned char>(text[cursor])))) ++cursor;
        if (cursor >= text.size()) break;
        char* end = nullptr;
        const unsigned long group = std::strtoul(text.c_str() + cursor,
            &end, 10);
        if (end == text.c_str() + cursor) break;
        if (group > 0 && group <= 32) mask |= 1u << (group - 1);
        cursor = static_cast<std::size_t>(end - text.c_str());
    }
    return mask;
}

struct ASEFace {
    int position[3]{};
    int texCoord[3]{-1, -1, -1};
    int color[3]{-1, -1, -1};
    int normal[3]{-1, -1, -1};
    int materialId = 0;
    unsigned int smoothing = 0;
};

struct ASEObject {
    std::vector<idVec3> positions;
    std::vector<idVec2> texCoords;
    std::vector<std::uint32_t> colors;
    std::vector<idVec3> normals;
    std::vector<ASEFace> faces;
    int materialRef = 0;
    idMat3 axis = idMat3(1.0f);
    idVec3 origin{0.0f, 0.0f, 0.0f};
};

template<typename Type>
void StoreAt(std::vector<Type>& list, const int index, const Type& value) {
    if (index < 0) return;
    if (index >= static_cast<int>(list.size())) list.resize(index + 1);
    list[index] = value;
}

int FindTokenInt(const std::string& line, const char* token,
        const int fallback = 0) {
    const std::size_t position = line.find(token);
    return position == std::string::npos ? fallback
        : std::atoi(line.c_str() + position + std::strlen(token));
}

void AppendObject(idASEModel& model, const ASEObject& object,
        const std::unordered_map<unsigned int, int>& materialMap) {
    const int positionBase = static_cast<int>(model.positions.size());
    const int texCoordBase = static_cast<int>(model.texCoords.size());
    const int normalBase = static_cast<int>(model.normals.size());
    const int colorBase = static_cast<int>(model.colors.size());
    for (const idVec3& position : object.positions) {
        model.positions.push_back(object.axis[0] * position.x +
            object.axis[1] * position.y + object.axis[2] * position.z +
            object.origin);
    }
    model.texCoords.insert(model.texCoords.end(), object.texCoords.begin(),
        object.texCoords.end());
    model.normals.insert(model.normals.end(), object.normals.begin(),
        object.normals.end());
    model.colors.insert(model.colors.end(), object.colors.begin(),
        object.colors.end());
    for (const ASEFace& face : object.faces) {
        idImportTriangle triangle;
        const unsigned int key = (static_cast<unsigned int>(object.materialRef)
            << 16) | static_cast<unsigned int>(face.materialId & 0xFFFF);
        auto material = materialMap.find(key);
        if (material == materialMap.end())
            material = materialMap.find(static_cast<unsigned int>(
                object.materialRef) << 16);
        triangle.material = material != materialMap.end()
            ? material->second : -1;
        triangle.smoothingGroup = face.smoothing;
        for (int corner = 0; corner < 3; ++corner) {
            triangle.corners[corner].position = positionBase +
                face.position[corner];
            if (face.texCoord[corner] >= 0)
                triangle.corners[corner].texCoord = texCoordBase +
                    face.texCoord[corner];
            if (face.normal[corner] >= 0)
                triangle.corners[corner].normal = normalBase +
                    face.normal[corner];
            if (face.color[corner] >= 0)
                triangle.corners[corner].color = colorBase +
                    face.color[corner];
        }
        model.triangles.push_back(triangle);
    }
}

} // namespace

idASEModel* ASE_Parse(const char* text, bool) {
    if (text == nullptr) return nullptr;
    auto* model = new idASEModel;
    std::unordered_map<unsigned int, int> materialMap;
    std::istringstream stream(text);
    std::string line;
    int currentMaterial = -1, currentSubMaterial = -1;
    int materialDepth = -1, subMaterialDepth = -1;
    int depth = 0;
    bool inObject = false;
    int objectDepth = -1;
    ASEObject object;
    int currentFaceNormal = -1;
    int nextCornerNormal = 0;
    while (std::getline(stream, line)) {
        line = Trim(line);
        const int opens = CountChar(line, '{');
        const int closes = CountChar(line, '}');

        if (line.rfind("*MATERIAL ", 0) == 0 && !inObject) {
            currentMaterial = std::atoi(line.c_str() + 10);
            currentSubMaterial = -1;
            materialDepth = depth + opens;
        } else if (line.rfind("*SUBMATERIAL ", 0) == 0) {
            currentSubMaterial = std::atoi(line.c_str() + 13);
            subMaterialDepth = depth + opens;
        } else if (line.rfind("*MATERIAL_NAME", 0) == 0) {
            idImportMaterial material;
            material.name = Quoted(line);
            const int index = static_cast<int>(model->materials.size());
            model->materials.push_back(material);
            const unsigned int key = (static_cast<unsigned int>(
                (std::max)(0, currentMaterial)) << 16) |
                static_cast<unsigned int>((std::max)(0, currentSubMaterial));
            materialMap[key] = index;
        } else if (line.rfind("*BITMAP", 0) == 0 &&
                !model->materials.empty()) {
            model->materials.back().diffuseMap = Quoted(line);
        } else if (line.rfind("*MATERIAL_TWOSIDED", 0) == 0 &&
                !model->materials.empty()) {
            model->materials.back().twoSided = true;
        }

        if (line.rfind("*GEOMOBJECT", 0) == 0) {
            if (inObject) AppendObject(*model, object, materialMap);
            object = ASEObject{};
            inObject = true;
            objectDepth = depth + opens;
            currentFaceNormal = -1;
        } else if (inObject) {
            if (line.rfind("*MATERIAL_REF", 0) == 0)
                object.materialRef = std::atoi(line.c_str() + 13);
            else if (line.rfind("*TM_ROW0", 0) == 0)
                std::sscanf(line.c_str(), "*TM_ROW0 %f %f %f",
                    &object.axis[0].x, &object.axis[0].y, &object.axis[0].z);
            else if (line.rfind("*TM_ROW1", 0) == 0)
                std::sscanf(line.c_str(), "*TM_ROW1 %f %f %f",
                    &object.axis[1].x, &object.axis[1].y, &object.axis[1].z);
            else if (line.rfind("*TM_ROW2", 0) == 0)
                std::sscanf(line.c_str(), "*TM_ROW2 %f %f %f",
                    &object.axis[2].x, &object.axis[2].y, &object.axis[2].z);
            else if (line.rfind("*TM_ROW3", 0) == 0)
                std::sscanf(line.c_str(), "*TM_ROW3 %f %f %f",
                    &object.origin.x, &object.origin.y, &object.origin.z);
            else if (line.rfind("*MESH_VERTEX ", 0) == 0) {
                int index; idVec3 value;
                if (std::sscanf(line.c_str(), "*MESH_VERTEX %d %f %f %f",
                        &index, &value.x, &value.y, &value.z) == 4)
                    StoreAt(object.positions, index, value);
            } else if (line.rfind("*MESH_TVERT ", 0) == 0) {
                int index; idVec2 value; float ignored;
                if (std::sscanf(line.c_str(), "*MESH_TVERT %d %f %f %f",
                        &index, &value.x, &value.y, &ignored) >= 3) {
                    value.y = 1.0f - value.y;
                    StoreAt(object.texCoords, index, value);
                }
            } else if (line.rfind("*MESH_CVERT ", 0) == 0) {
                int index; float r, g, b;
                if (std::sscanf(line.c_str(), "*MESH_CVERT %d %f %f %f",
                        &index, &r, &g, &b) == 4) {
                    const auto byte = [](float value) {
                        return static_cast<unsigned int>((std::max)(0,
                            (std::min)(255, static_cast<int>(value * 255.0f +
                                0.5f))));
                    };
                    StoreAt(object.colors, index, byte(r) | (byte(g) << 8) |
                        (byte(b) << 16) | 0xFF000000u);
                }
            } else if (line.rfind("*MESH_FACE ", 0) == 0) {
                const int faceIndex = std::atoi(line.c_str() + 11);
                if (faceIndex >= static_cast<int>(object.faces.size()))
                    object.faces.resize(faceIndex + 1);
                ASEFace& face = object.faces[faceIndex];
                face.position[0] = FindTokenInt(line, "A:");
                face.position[1] = FindTokenInt(line, "B:");
                face.position[2] = FindTokenInt(line, "C:");
                face.materialId = FindTokenInt(line, "*MESH_MTLID");
                const std::size_t smoothing = line.find("*MESH_SMOOTHING");
                if (smoothing != std::string::npos) {
                    const std::size_t end = line.find('*', smoothing + 1);
                    face.smoothing = ParseSmoothing(line.substr(
                        smoothing + 15, end == std::string::npos
                            ? std::string::npos : end - smoothing - 15));
                }
            } else if (line.rfind("*MESH_TFACE ", 0) == 0) {
                int face, a, b, c;
                if (std::sscanf(line.c_str(), "*MESH_TFACE %d %d %d %d",
                        &face, &a, &b, &c) == 4) {
                    if (face >= static_cast<int>(object.faces.size()))
                        object.faces.resize(face + 1);
                    object.faces[face].texCoord[0] = a;
                    object.faces[face].texCoord[1] = b;
                    object.faces[face].texCoord[2] = c;
                }
            } else if (line.rfind("*MESH_CFACE ", 0) == 0) {
                int face, a, b, c;
                if (std::sscanf(line.c_str(), "*MESH_CFACE %d %d %d %d",
                        &face, &a, &b, &c) == 4) {
                    if (face >= static_cast<int>(object.faces.size()))
                        object.faces.resize(face + 1);
                    object.faces[face].color[0] = a;
                    object.faces[face].color[1] = b;
                    object.faces[face].color[2] = c;
                }
            } else if (line.rfind("*MESH_FACENORMAL ", 0) == 0) {
                idVec3 normal;
                if (std::sscanf(line.c_str(), "*MESH_FACENORMAL %d %f %f %f",
                        &currentFaceNormal, &normal.x, &normal.y, &normal.z) == 4)
                    nextCornerNormal = 0;
            } else if (line.rfind("*MESH_VERTEXNORMAL ", 0) == 0 &&
                    currentFaceNormal >= 0 &&
                    currentFaceNormal < static_cast<int>(object.faces.size())) {
                int vertex; idVec3 normal;
                if (std::sscanf(line.c_str(), "*MESH_VERTEXNORMAL %d %f %f %f",
                        &vertex, &normal.x, &normal.y, &normal.z) == 4 &&
                    nextCornerNormal < 3) {
                    const int normalIndex = static_cast<int>(
                        object.normals.size());
                    object.normals.push_back(normal);
                    object.faces[currentFaceNormal].normal[nextCornerNormal++] =
                        normalIndex;
                }
            }
        }

        depth += opens - closes;
        if (currentSubMaterial >= 0 && depth < subMaterialDepth)
            currentSubMaterial = -1;
        if (currentMaterial >= 0 && depth < materialDepth) {
            currentMaterial = -1;
            currentSubMaterial = -1;
        }
        if (inObject && depth < objectDepth) {
            AppendObject(*model, object, materialMap);
            object = ASEObject{};
            inObject = false;
        }
    }
    if (inObject) AppendObject(*model, object, materialMap);
    if (model->materials.empty())
        model->materials.push_back({"_default", "", false});
    if (model->triangles.empty()) {
        delete model;
        return nullptr;
    }
    return model;
}

idASEModel* ASE_Load(const char* fileName) {
    if (fileSystem == nullptr || fileName == nullptr) return nullptr;
    void* buffer = nullptr;
    const int length = fileSystem->ReadFile(fileName, &buffer, nullptr);
    if (length < 0 || buffer == nullptr) return nullptr;
    std::string text(static_cast<const char*>(buffer),
        static_cast<std::size_t>(length));
    fileSystem->FreeFile(buffer);
    return ASE_Parse(text.c_str(), false);
}

void ASE_Free(idASEModel* model) { delete model; }

