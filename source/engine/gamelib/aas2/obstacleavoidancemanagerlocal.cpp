#include "gamelib/aas2/obstacleavoidancemanagerlocal.h"

#include "idlib/lib_print.h"

#include <malloc.h>
#include <new>

namespace {

template<typename type>
type* AllocAligned(const std::size_t size, const std::size_t alignment) {
    return static_cast<type*>(_aligned_malloc(size, alignment));
}

void FreeAligned(void* const memory) {
    _aligned_free(memory);
}

void ResetBuffer(idObstacleBuffers& buffer) {
    buffer.numObstacles = 0;
    buffer.numVertices = 0;
    buffer.numEdges = 0;
    buffer.numCorners = 0;
    buffer.numTraces = 0;
    buffer.frameCount = 2;
}

idObstacleBuffers* AllocBuffer() {
    idObstacleBuffers* const buffer =
        AllocAligned<idObstacleBuffers>(0x44, 16);
    buffer->parms = AllocAligned<obstacleParms_t>(0xA0, 128);
    buffer->route = AllocAligned<obstacleRoute_t>(0x150, 128);
    buffer->obstacles = AllocAligned<obstacleBox_t>(0x2800, 128);
    buffer->vertices = AllocAligned<obstacleVertex_t>(0x2400, 128);
    buffer->edges = AllocAligned<obstacleEdge_t>(0x2000, 128);
    buffer->corners = AllocAligned<obstacleCorner_t>(0x100, 128);
    buffer->traces = AllocAligned<obstacleTrace_t>(0x1000, 128);
    buffer->traceFractions = AllocAligned<float>(0x400, 128);
    void* const pathMemory = _aligned_malloc(0x270, 128);
    buffer->path = new (pathMemory) obstaclePath_t();
    buffer->user = nullptr;
    buffer->job = nullptr;
    ResetBuffer(*buffer);
    buffer->frameCount = 0;
    return buffer;
}

void FreeBuffer(idObstacleBuffers* const buffer) {
    if (buffer == nullptr) {
        return;
    }
    FreeAligned(buffer->parms);
    FreeAligned(buffer->route);
    FreeAligned(buffer->obstacles);
    FreeAligned(buffer->vertices);
    FreeAligned(buffer->edges);
    FreeAligned(buffer->corners);
    FreeAligned(buffer->traces);
    FreeAligned(buffer->traceFractions);
    if (buffer->path != nullptr) {
        buffer->path->~obstaclePath_t();
        FreeAligned(buffer->path);
    }
    FreeAligned(buffer);
}

} // namespace

idObstacleAvoidanceManagerLocal obstacleAvoidanceManagerLocal;

idObstacleAvoidanceManagerLocal::idObstacleAvoidanceManagerLocal()
    : jobList(nullptr)
    , usedBuffers()
    , freeBuffers()
    , toBeFreedBuffers() {
}

idObstacleAvoidanceManagerLocal::~idObstacleAvoidanceManagerLocal() {
    Shutdown();
}

void idObstacleAvoidanceManagerLocal::Init(
    idParallelJobList* const jobList_) {
    if (jobList != nullptr) {
        return;
    }

    jobList = jobList_;
    freeBuffers.SetNum(32);
    for (int index = 0; index < 32; ++index) {
        freeBuffers[index] = AllocBuffer();
    }
}

void idObstacleAvoidanceManagerLocal::Shutdown() {
    FrameFreeObstacleBuffers();
    for (int index = 0; index < freeBuffers.Num(); ++index) {
        FreeBuffer(freeBuffers[index]);
    }
    usedBuffers.ClearFree();
    freeBuffers.ClearFree();
    toBeFreedBuffers.ClearFree();
    jobList = nullptr;
}

void idObstacleAvoidanceManagerLocal::AllocObstacleBuffers(
    idObstacleAvoidance* const avoidance) {
    const int existingIndex = usedBuffers.FindIndex(avoidance->buffers);
    if (existingIndex >= 0) {
        ResetBuffer(*avoidance->buffers);
        return;
    }

    if (freeBuffers.IsEmpty()) {
        idLibPrint::Warning("out of obstacle avoidance buffers");
        return;
    }

    idObstacleBuffers* const buffer = freeBuffers[freeBuffers.Num() - 1];
    freeBuffers.SetNum(freeBuffers.Num() - 1);
    usedBuffers.Append(buffer);
    buffer->user = avoidance;
    buffer->job = nullptr;
    ResetBuffer(*buffer);
    avoidance->buffers = buffer;
}

void idObstacleAvoidanceManagerLocal::FreeObstacleBuffers(
    idObstacleAvoidance* const avoidance) {
    if (avoidance->buffers == nullptr) {
        return;
    }

    const int index = usedBuffers.FindIndex(avoidance->buffers);
    if (index < 0) {
        return;
    }

    idObstacleBuffers* const buffer = usedBuffers[index];
    buffer->user = nullptr;
    buffer->job = nullptr;
    toBeFreedBuffers.Append(buffer);
    usedBuffers.RemoveIndexFast(index);
    avoidance->buffers = nullptr;
}

void idObstacleAvoidanceManagerLocal::FrameFreeObstacleBuffers() {
    for (int index = 0; index < usedBuffers.Num(); ++index) {
        idObstacleBuffers* const buffer = usedBuffers[index];
        if (--buffer->frameCount <= 0) {
            if (buffer->user != nullptr) {
                buffer->user->buffers = nullptr;
            }
            buffer->user = nullptr;
            buffer->job = nullptr;
            toBeFreedBuffers.Append(buffer);
            usedBuffers.RemoveIndexFast(index--);
        }
    }

    for (int index = 0; index < toBeFreedBuffers.Num(); ++index) {
        freeBuffers.Append(toBeFreedBuffers[index]);
    }
    toBeFreedBuffers.Clear();
}
