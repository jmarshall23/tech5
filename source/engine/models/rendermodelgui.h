#pragma once

#include "idlib/containers/array.h"
#include "models/rendermodel.h"

struct guiModelSurface_t {
    std::uint64_t extraGLState;
    const idMaterial* material;
    int numVerts;
    int firstIndex;
    int numIndexes;
};

class alignas(16) idRenderModelGui : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelGui* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    using MaterialSizeCallback = void (*)(const idMaterial* material,
        int& width, int& height);

    idRenderModelGui();
    ~idRenderModelGui() override = default;
    static void Init();
    static void Shutdown();
    static void StartFrame();
    static void SetUpdateCallback(UpdateCallback callback);
    static void SetUtilityCallbacks(const idMaterial* whiteMaterial,
        const idMaterial* fontMaterial, MaterialSizeCallback materialSize);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    bool CommitSubclass() override;
    void SetVirtualSize(int width, int height);
    void SetViewport(int x, int y, int width, int height);
    float GetVirtualWidth() const;
    float GetVirtualHeight() const;
    void SetGLState(std::uint64_t bits);
    idDrawVert* AllocTris(int numVerts, const std::uint16_t* indexes,
        int numIndexes, const idMaterial* material);
    void DrawTris(const idDrawVert* vertices, int numVerts,
        const std::uint16_t* indexes, int numIndexes,
        const idMaterial* material);
    void DrawStretchPic(const idVec4& topLeft, const idVec4& topRight,
        const idVec4& bottomRight, const idVec4& bottomLeft,
        const idMaterial* material);
    int GetStringWidth(const char* string, float scale) const;
    int GetStringHeight(float scale) const;
    void SetupMonospaceFont(float drawWidth);
    void Clear(std::uint64_t glState = 0);
    void DrawFilled(const idVec4& color, float x, float y, float width,
        float height);
    void DrawPic(float x, float y, const idMaterial* material);
    void DrawChar(float x, float y, int character, float scale);
    void DrawString(float x, float y, const char* string,
        const idVec4& color, bool forceColor, float scale);

    guiModelSurface_t* surf;
    unsigned int currentVertexColor;
    int numGuiSurfaces;
    idArray<guiModelSurface_t, 256> guiSurfaces;
    idArray<idTriangles, 256> triangles;
    bool useVirtualSize;
    int frameNum;
    int waitForFrame;

private:
    void AdvanceSurf();
    static UpdateCallback updateCallback;
    static MaterialSizeCallback materialSizeCallback;
    static const idMaterial* whiteMaterial;
    static const idMaterial* fontMaterial;
    static idList<idDrawVert, 5> mappedVertices;
    static idList<std::uint16_t, 5> mappedIndices;
    static int frameCount;
    static float smallCharWidth;
    static float smallCharHeight;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(guiModelSurface_t) == 24,
    "Recovered GUI model-surface ABI changed");
#endif
