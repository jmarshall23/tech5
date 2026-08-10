#include "models/rendermodelgui.h"

#include <algorithm>
#include <cmath>
#include <cstring>

idRenderModelGui::UpdateCallback idRenderModelGui::updateCallback = nullptr;
idRenderModelGui::MaterialSizeCallback idRenderModelGui::materialSizeCallback =
    nullptr;
const idMaterial* idRenderModelGui::whiteMaterial = nullptr;
const idMaterial* idRenderModelGui::fontMaterial = nullptr;
idList<idDrawVert, 5> idRenderModelGui::mappedVertices;
idList<std::uint16_t, 5> idRenderModelGui::mappedIndices;
int idRenderModelGui::frameCount = 0;
float idRenderModelGui::smallCharWidth = 8.0f;
float idRenderModelGui::smallCharHeight = 16.0f;

idRenderModelGui::idRenderModelGui()
    : surf(nullptr), currentVertexColor(0u), numGuiSurfaces(0),
      useVirtualSize(false), frameNum(0), waitForFrame(0) {
    std::memset(&guiSurfaces, 0, sizeof(guiSurfaces));
    std::memset(&triangles, 0, sizeof(triangles));
    SetName("_guiModel");
    g.noInteractions = 1;
    g.noShadow = 1;
    g.mvpIsOrthographic = 1;
    useDeferredPosition = false;
    g.origin.Set(-1.0f, 1.0f, 0.0f);
    deferredOrigin = g.origin;
    SetViewport(0, 0, 1280, 720);
    SetMaxSurfaces(256);
}

void idRenderModelGui::Init() {
    mappedVertices.ClearFree();
    mappedIndices.ClearFree();
    mappedVertices.PreAllocate(25600);
    mappedIndices.PreAllocate(40960);
    frameCount = 0;
}

void idRenderModelGui::Shutdown() {
    mappedVertices.ClearFree();
    mappedIndices.ClearFree();
    frameCount = 0;
}

void idRenderModelGui::StartFrame() {
    mappedVertices.Clear();
    mappedIndices.Clear();
    ++frameCount;
}

void idRenderModelGui::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelGui::SetUtilityCallbacks(
        const idMaterial* whiteMaterialIn,
        const idMaterial* fontMaterialIn,
        MaterialSizeCallback materialSize) {
    whiteMaterial = whiteMaterialIn;
    fontMaterial = fontMaterialIn;
    materialSizeCallback = materialSize;
}

bool idRenderModelGui::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}

void idRenderModelGui::SetVirtualSize(const int width, const int height) {
    if (width <= 0 || height <= 0) return;
    g.scale.Set(2.0f / static_cast<float>(width),
        -2.0f / static_cast<float>(height), 1.0f);
    useVirtualSize = true;
}

void idRenderModelGui::SetViewport(const int x, const int y,
        const int width, const int height) {
    idRenderModel::SetViewport(x, y, width, height);
    if (!useVirtualSize && width > 0 && height > 0)
        g.scale.Set(2.0f / static_cast<float>(width),
            -2.0f / static_cast<float>(height), 1.0f);
}

float idRenderModelGui::GetVirtualWidth() const {
    return useVirtualSize && std::fabs(g.scale.x) > 1.0e-20f
        ? 2.0f / g.scale.x
        : static_cast<float>(g.viewport.x2 - g.viewport.x1 + 1);
}

float idRenderModelGui::GetVirtualHeight() const {
    return useVirtualSize && std::fabs(g.scale.y) > 1.0e-20f
        ? -2.0f / g.scale.y
        : static_cast<float>(g.viewport.y2 - g.viewport.y1 + 1);
}

void idRenderModelGui::AdvanceSurf() {
    if (numGuiSurfaces >= guiSurfaces.Num()) return;
    guiModelSurface_t& next = guiSurfaces[numGuiSurfaces++];
    if (surf != nullptr) {
        next.material = surf->material;
        next.extraGLState = surf->extraGLState;
    } else {
        next.material = nullptr;
        next.extraGLState = 0;
    }
    next.numVerts = 0;
    next.firstIndex = mappedIndices.Num();
    next.numIndexes = 0;
    surf = &next;
    frameNum = frameCount;
}

void idRenderModelGui::SetGLState(const std::uint64_t bits) {
    if (surf == nullptr) AdvanceSurf();
    if (surf == nullptr) return;
    if (surf->extraGLState != bits && surf->numVerts != 0) AdvanceSurf();
    if (surf != nullptr) surf->extraGLState = bits;
}

idDrawVert* idRenderModelGui::AllocTris(const int numVerts,
        const std::uint16_t* indexes, const int numIndexes,
        const idMaterial* material) {
    if (numVerts <= 0 || indexes == nullptr || numIndexes <= 0 ||
        material == nullptr) return nullptr;
    if (surf == nullptr) AdvanceSurf();
    if (surf == nullptr) return nullptr;
    if (surf->material != material) {
        if (surf->numVerts != 0) AdvanceSurf();
        if (surf == nullptr) return nullptr;
        surf->material = material;
    }
    if (mappedVertices.Num() + numVerts > 25600 ||
        mappedIndices.Num() + numIndexes + 3 > 40960) return nullptr;
    const int vertexBase = mappedVertices.Num();
    if (!mappedVertices.SetNum(vertexBase + numVerts)) return nullptr;
    for (int index = 0; index < numIndexes; ++index)
        mappedIndices.Append(static_cast<std::uint16_t>(
            indexes[index] + vertexBase));
    int storedIndexes = numIndexes;
    if ((numIndexes & 1) != 0) {
        const std::uint16_t finalIndex = static_cast<std::uint16_t>(
            indexes[numIndexes - 1] + vertexBase);
        mappedIndices.Append(finalIndex);
        mappedIndices.Append(finalIndex);
        mappedIndices.Append(finalIndex);
        storedIndexes += 3;
    }
    surf->numVerts += numVerts;
    surf->numIndexes += storedIndexes;
    return mappedVertices.Ptr() + vertexBase;
}

void idRenderModelGui::DrawTris(const idDrawVert* vertices,
        const int numVerts, const std::uint16_t* indexes,
        const int numIndexes, const idMaterial* material) {
    idDrawVert* destination = AllocTris(numVerts, indexes, numIndexes,
        material);
    if (destination != nullptr && vertices != nullptr)
        std::memcpy(destination, vertices,
            numVerts * sizeof(idDrawVert));
}

void idRenderModelGui::DrawStretchPic(const idVec4& topLeft,
        const idVec4& topRight, const idVec4& bottomRight,
        const idVec4& bottomLeft, const idMaterial* material) {
    static const std::uint16_t indexes[6] = {0, 1, 2, 0, 2, 3};
    idDrawVert* vertices = AllocTris(4, indexes, 6, material);
    if (vertices == nullptr) return;
    const idVec4 corners[4] = {topLeft, topRight, bottomRight, bottomLeft};
    for (int index = 0; index < 4; ++index) {
        std::memset(&vertices[index], 0, sizeof(idDrawVert));
        vertices[index].xyz.Set(corners[index].x, corners[index].y, 0.0f);
        vertices[index].st.Set(corners[index].z, corners[index].w);
        vertices[index].SetNormal(idVec3(0.0f, 0.0f, 1.0f));
        vertices[index].SetTangent(idVec3(1.0f, 0.0f, 0.0f));
        vertices[index].tangent[3] = 255;
        std::memcpy(vertices[index].color, &currentVertexColor, 4);
    }
}

int idRenderModelGui::GetStringWidth(const char* string,
        const float scale) const {
    if (string == nullptr) return 0;
    int visible = 0;
    for (const char* cursor = string; *cursor != '\0';) {
        if (*cursor == '^' && cursor[1] != '\0' && cursor[1] != ' ') {
            cursor += 2;
            continue;
        }
        ++visible;
        ++cursor;
    }
    return static_cast<int>(visible * smallCharWidth * scale);
}

int idRenderModelGui::GetStringHeight(const float scale) const {
    return static_cast<int>(smallCharHeight * scale);
}

void idRenderModelGui::SetupMonospaceFont(const float drawWidth) {
    if (drawWidth <= 0.0f) return;
    smallCharWidth = drawWidth;
    smallCharHeight = drawWidth * 2.0f;
}

void idRenderModelGui::Clear(const std::uint64_t glState) {
    numGuiSurfaces = 0;
    surf = nullptr;
    AdvanceSurf();
    SetGLState(glState);
}

void idRenderModelGui::DrawFilled(const idVec4& color, const float x,
        const float y, const float width, const float height) {
    if (whiteMaterial == nullptr) return;
    const unsigned int previous = currentVertexColor;
    currentVertexColor = idColor::PackColor(color);
    DrawStretchPic(idVec4(x, y, 0.0f, 0.0f),
        idVec4(x + width, y, 1.0f, 0.0f),
        idVec4(x + width, y + height, 1.0f, 1.0f),
        idVec4(x, y + height, 0.0f, 1.0f), whiteMaterial);
    currentVertexColor = previous;
}

void idRenderModelGui::DrawPic(const float x, const float y,
        const idMaterial* material) {
    if (material == nullptr) return;
    int width = 1, height = 1;
    if (materialSizeCallback != nullptr)
        materialSizeCallback(material, width, height);
    DrawStretchPic(idVec4(x, y, 0.0f, 0.0f),
        idVec4(x + width, y, 1.0f, 0.0f),
        idVec4(x + width, y + height, 1.0f, 1.0f),
        idVec4(x, y + height, 0.0f, 1.0f), material);
}

void idRenderModelGui::DrawChar(const float x, const float y,
        const int character, const float scale) {
    if (fontMaterial == nullptr || character == ' ') return;
    const int glyph = character & 255;
    const float s0 = static_cast<float>(glyph & 15) / 16.0f;
    const float t0 = static_cast<float>((glyph >> 4) & 15) / 16.0f;
    const float s1 = s0 + 1.0f / 16.0f;
    const float t1 = t0 + 1.0f / 16.0f;
    const float width = smallCharWidth * scale;
    const float height = smallCharHeight * scale;
    DrawStretchPic(idVec4(x, y, s0, t0),
        idVec4(x + width, y, s1, t0),
        idVec4(x + width, y + height, s1, t1),
        idVec4(x, y + height, s0, t1), fontMaterial);
}

void idRenderModelGui::DrawString(float x, float y, const char* string,
        const idVec4& color, const bool forceColor, const float scale) {
    if (string == nullptr) return;
    const unsigned int previous = currentVertexColor;
    currentVertexColor = idColor::PackColor(color);
    const float startX = x;
    static const idVec4 colorTable[8] = {
        idVec4(0,0,0,1), idVec4(1,0,0,1), idVec4(0,1,0,1),
        idVec4(1,1,0,1), idVec4(0,0,1,1), idVec4(0,1,1,1),
        idVec4(1,0,1,1), idVec4(1,1,1,1)
    };
    for (const char* cursor = string; *cursor != '\0'; ++cursor) {
        if (*cursor == '\n') {
            x = startX;
            y += smallCharHeight * scale;
            continue;
        }
        if (*cursor == '^' && cursor[1] != '\0' && cursor[1] != ' ') {
            if (!forceColor && cursor[1] >= '0' && cursor[1] <= '7')
                currentVertexColor = idColor::PackColor(
                    colorTable[cursor[1] - '0']);
            ++cursor;
            continue;
        }
        DrawChar(x, y, static_cast<unsigned char>(*cursor), scale);
        x += smallCharWidth * scale;
    }
    currentVertexColor = previous;
}

bool idRenderModelGui::CommitSubclass() {
    surfaces.Clear();
    waitForFrame = frameNum + 1;
    for (int index = 0; index < numGuiSurfaces; ++index) {
        const guiModelSurface_t& guiSurface = guiSurfaces[index];
        if (guiSurface.material == nullptr || guiSurface.numVerts == 0 ||
            guiSurface.numIndexes == 0) continue;
        idTriangles& geometry = triangles[index];
        geometry.numVerts = mappedVertices.Num();
        geometry.numIndexes = guiSurface.numIndexes;
        geometry.verts = mappedVertices.Ptr();
        geometry.indexes = mappedIndices.Ptr() + guiSurface.firstIndex;
        geometry.vertexMask = geometry.cpuVertexMask = 0x1Fu;
        geometry.bounds[0].Set(-99999.0f, -99999.0f, -99999.0f);
        geometry.bounds[1].Set(99999.0f, 99999.0f, 99999.0f);
        idRenderModelSurface surface{};
        surface.material = guiSurface.material;
        surface.extraGLState = guiSurface.extraGLState;
        surface.geometry = &geometry;
        surface.geometryIsReference = true;
        surfaces.Append(surface);
    }
    numGuiSurfaces = 0;
    surf = nullptr;
    return surfaces.Num() != 0;
}
