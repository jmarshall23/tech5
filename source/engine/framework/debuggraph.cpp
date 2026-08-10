#include "framework/debuggraph.h"

#include "framework/framework_hooks.h"

#include <algorithm>
#include <cmath>

namespace {
unsigned int Pack(const idColor& color) {
    const auto channel = [](const float value) {
        return static_cast<unsigned int>(std::max(0.0f,
            std::min(255.0f, value * 255.0f)));
    };
    return channel(color.r) | channel(color.g) << 8 | channel(color.b) << 16
        | channel(color.a) << 24;
}
}

idDebugGraph::idDebugGraph(const int numBars)
    : white(nullptr), bgColor(0.0f, 0.0f, 0.0f, 0.65f),
      fontColor(1.0f, 1.0f, 1.0f, 1.0f), mode(GRAPH_LINE), sideways(false),
      border(1.0f), position(0.0f, 0.0f, 256.0f, 128.0f), enable(true),
      clamp(true), capPos(CAP_TOP) {
    Init(numBars);
}

void idDebugGraph::Init(const int numBars) {
    bars.SetNum(std::max(0, numBars));
    labels.SetNum(std::max(0, numBars));
    for (int index = 0; index < bars.Num(); ++index) {
        bars[index].value = 0.0f;
        bars[index].color = idColor(0.2f, 0.8f, 0.2f, 1.0f);
    }
}

void idDebugGraph::SetLabel(const int index, const char* const text) {
    if (index >= 0 && index < labels.Num()) {
        labels[index] = text != nullptr ? text : "";
    }
}

void idDebugGraph::AddGridLine(const float value, const idColor& color) {
    graphPlot_t plot = {value, color};
    grid.Append(plot);
}

void idDebugGraph::SetValue(const int index, const float value,
        const idColor& color) {
    if (index < 0) {
        return;
    }
    if (index >= bars.Num()) {
        bars.SetNum(index + 1);
        labels.SetNum(index + 1);
    }
    bars[index].value = clamp ? std::max(0.0f, std::min(1.0f, value)) : value;
    bars[index].color = color;
}

void idDebugGraph::Render(idRenderModelGui* const gui) {
    if (!enable || gui == nullptr || frameworkHooks.drawRect == nullptr) {
        return;
    }
    frameworkHooks.drawRect(gui, position.x, position.y, position.z,
        position.w, Pack(bgColor));
    for (int index = 0; index < grid.Num(); ++index) {
        const float y = position.y + position.w * (1.0f - grid[index].value);
        frameworkHooks.drawRect(gui, position.x, y, position.z, 1.0f,
            Pack(grid[index].color));
    }
    if (bars.Num() == 0) {
        return;
    }
    const float cell = position.z / static_cast<float>(bars.Num());
    for (int index = 0; index < bars.Num(); ++index) {
        const float height = position.w * bars[index].value;
        const float x = position.x + cell * index;
        const float y = mode == GRAPH_FILL_REVERSE ? position.y
            : position.y + position.w - height;
        frameworkHooks.drawRect(gui, x, y, std::max(1.0f, cell - border),
            mode == GRAPH_LINE ? 1.0f : height, Pack(bars[index].color));
        if (frameworkHooks.drawString != nullptr && index < labels.Num()
                && labels[index].Length() != 0) {
            frameworkHooks.drawString(gui, x, position.y + position.w + 2.0f,
                labels[index].c_str(), Pack(fontColor), 0.75f);
        }
    }
}
