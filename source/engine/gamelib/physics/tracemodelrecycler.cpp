#include "gamelib/physics/tracemodelrecycler.h"

idTraceModelRecycler::~idTraceModelRecycler() {
    Shutdown();
}

void idTraceModelRecycler::Shutdown() {
    for (int index = 0; index < allocated.Num(); ++index) {
        idRecycledTraceModel* const recycled = allocated[index];
        delete recycled->trm;
        recycled->trm = nullptr;
    }

    allocated.ClearFree();
    for (int stage = 0; stage < 3; ++stage) {
        free[stage].ClearFree();
    }
    allocator.Shutdown();
}

idRecycledTraceModel* idTraceModelRecycler::GetTraceModel() {
    if (free[0].Num() != 0) {
        idRecycledTraceModel* const result = free[0][free[0].Num() - 1];
        free[0].RemoveIndexFast(free[0].Num() - 1);
        return result;
    }

    idRecycledTraceModel* const result = allocator.Alloc();
    if (result == nullptr) {
        return nullptr;
    }

    result->trm = new idTraceModel();
    result->index = allocated.Append(result);
    if (result->index < 0) {
        delete result->trm;
        result->trm = nullptr;
        allocator.Free(result);
        return nullptr;
    }
    return result;
}

void idTraceModelRecycler::RecycleTraceModel(
        idRecycledTraceModel* const recycledTrm, const bool defer) {
    if (recycledTrm == nullptr) {
        return;
    }
    free[defer ? 2 : 0].Append(recycledTrm);
}

void idTraceModelRecycler::UpdateDeferredFreed() {
    for (int stage = 1; stage < 3; ++stage) {
        for (int index = 0; index < free[stage].Num(); ++index) {
            free[stage - 1].Append(free[stage][index]);
        }
        free[stage].ClearFree();
    }
}
