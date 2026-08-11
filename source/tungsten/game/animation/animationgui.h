#pragma once

class idEntity;
class idFont;
class idGUIRect;
class idMD6Anim;
class idMD6Leaf;
class idMD6LeafPlay;
class idMD6Node;
class idRenderModelGui;
class idStr;

using idAnimationGUIFontLoader = const idFont* (*)(const char* name);
using idAnimationGUIAnimInfoProvider = bool (*)(
    const idMD6Anim* animation, int& frameCount, int& frameRate);
using idAnimationGUIDrawTreeCallback = void (*)(
    idStr& indentation, idGUIRect& rectangle, const idMD6Node* node);
using idAnimationGUIDrawDebugCallback = idRenderModelGui* (*)(
    idEntity* entity, const idFont* font, idRenderModelGui* currentModel);

void Tungsten_SetAnimationGUIFontLoader(
    idAnimationGUIFontLoader loader);
void Tungsten_SetAnimationGUIAnimInfoProvider(
    idAnimationGUIAnimInfoProvider provider);
void Tungsten_SetAnimationGUIDrawTreeCallback(
    idAnimationGUIDrawTreeCallback callback);
void Tungsten_SetAnimationGUIDrawDebugCallback(
    idAnimationGUIDrawDebugCallback callback);

float GetAnimTime(const idMD6Leaf* leaf,
    int timeMilliseconds, int ticksPerSecond);

class idAnimationGUI {
public:
    idAnimationGUI();

    idRenderModelGui* DrawDebugGUI(idEntity* entity);

    idRenderModelGui* GetGuiModel() const { return guiModel; }
    const idFont* GetFont() const { return font; }

private:
    void DrawAnimTree_r(idStr& indentation, idGUIRect& rectangle,
        const idMD6Node* treeNode);

    idRenderModelGui* guiModel;
    const idFont* font;
};
