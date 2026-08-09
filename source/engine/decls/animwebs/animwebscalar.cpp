#include "decls/animwebs/animwebscalar.h"

#include "idlib/containers/list.h"
#include "idlib/lib_print.h"
#include "idlib/sys/sys_alloc.h"

idScalarMemBlock::~idScalarMemBlock() {
    Free();
}

void idScalarMemBlock::Free() {
    num = 0;
    if (floats != nullptr) {
        mem.Free(floats, ALIGN_16);
        floats = nullptr;
    }
}

void idScalarMemBlock::Alloc(const int count) {
    Free();
    num = count;
    if (count > 0) {
        floats = static_cast<float*>(mem.AllocWithLocation(
            "engine/decls/animwebs/animwebscalar.cpp: TAG_ANIMWEB",
            static_cast<unsigned int>(sizeof(float) * count), TAG_ANIMWEB,
            false, ALIGN_16, HEAP_DEFAULTHEAP));
    }
}

void idScalarMemBlock::Free(idList<idAnimWebScalar, 5>& scalars) {
    for (int index = 0; index < scalars.Num(); ++index)
        scalars[index].scalarIndex = -1;
    Free();
}

void idScalarMemBlock::Free(idList<idAnimWebScalar, 33>& scalars) {
    for (int index = 0; index < scalars.Num(); ++index)
        scalars[index].scalarIndex = -1;
    Free();
}

void idAnimWebScalar::SetScalarPtr(float* const scalar) {
    if (scalar != nullptr) {
        scalarPtr = scalar;
        scalarIndex = -1;
    }
}

void idAnimWebScalar::SetIndex(const idScalarMemBlock&, const int index) {
    scalarIndex = static_cast<short>(index);
    scalarPtr = nullptr;
}

void idAnimWebScalar::SetName(const char* const scalarName) {
    name.Set(scalarName);
}

float idAnimWebScalar::GetScalar(const idScalarMemBlock& memBlock) const {
    if (scalarIndex >= 0) return memBlock.floats[scalarIndex];
    if (scalarPtr != nullptr) return *scalarPtr;
    idLibPrint::Warning(
        "idAnimWebScalar::GetScalar - Trying to access uninitialized blend variable \"%s\"",
        name.c_str());
    return 0.0f;
}

void idAnimWebScalar::SetScalar(idScalarMemBlock& memBlock,
        const float value) {
    if (scalarIndex >= 0) memBlock.floats[scalarIndex] = value;
    else *scalarPtr = value;
}

void idAnimWebScalar::Init(const char* const scalarName,
        const unsigned char scalarFlags, float* const scalar) {
    name.Set(scalarName);
    flags = scalarFlags;
    if (scalar != nullptr) {
        scalarPtr = scalar;
        scalarIndex = -1;
    }
}
