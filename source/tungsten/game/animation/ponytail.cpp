#include "ponytail.h"

// Retail symbol: ??1idPonytail@@QAA@XZ
// EA: 0x82B35E08, RVA: 0x00B35E08
idPonytail::~idPonytail() = default;

// Retail symbol: ??0idPonytail@@QAA@XZ
// EA: 0x82B35EF8, RVA: 0x00B35EF8
idPonytail::idPonytail()
    : declPonytail(nullptr), parent(nullptr), attachmentHandle(-1),
      usingParentAnimStack(false), initialized(false), services(nullptr) {
}

// Retail symbol: ?Update@idPonytail@@QAAXXZ
// EA: 0x82B35F88, RVA: 0x00B35F88
void idPonytail::Update() {
    if (initialized && !usingParentAnimStack && services != nullptr) {
        services->UpdatePonytail(*this);
    }
}

// Retail symbol: ?Shutdown@idPonytail@@QAAXXZ
// EA: 0x82B36058, RVA: 0x00B36058
void idPonytail::Shutdown() {
    if (parent != nullptr && attachmentHandle != -1
            && services != nullptr) {
        services->RemoveAttachment(parent, attachmentHandle);
        attachmentHandle = -1;
    }
    initialized = false;
}

// Retail symbol: ?Init@idPonytail@@QAA_NPAVidEntity@@@Z
// EA: 0x82B36148, RVA: 0x00B36148
bool idPonytail::Init(idEntity* const parentEntity) {
    parent = parentEntity;
    usingParentAnimStack = false;
    attachmentHandle = -1;
    initialized = false;
    if (parent == nullptr || declPonytail == nullptr || services == nullptr) {
        return false;
    }
    idPonytailInitResult result;
    if (!services->InitializePonytail(
            *this, parent, declPonytail, result)) {
        Shutdown();
        return false;
    }
    usingParentAnimStack = result.usingParentAnimStack;
    attachmentHandle = result.attachmentHandle;
    initialized = true;
    return true;
}
