#include "gamelib/animstack/animator_proxy.h"

// These allocator calls are owned by the idAnimStack/md6Allocator recovery.
// Keeping the boundary explicit allows the complete Proxy TU to compile now
// without inventing an allocator layout or a temporary allocation policy.
idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);

idAnimator_Proxy::idAnimator_Proxy()
    : idAnimator_Base()
    , mergeBranch(nullptr) {
}

idAnimator_Proxy::~idAnimator_Proxy() {
    mergeBranch = nullptr;
}

void idAnimator_Proxy::SetTree(idMD6Node* const tree) {
    if (mergeBranch != nullptr) {
        mergeBranch->right = tree;
    }
}

bool idAnimator_Proxy::InternalInit(
    const idAnimatorParms_Base& parameters) {
    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    return true;
}

void idAnimator_Proxy::InternalShutdown(idAnimStack* const stack) {
    if (stack != nullptr && mergeBranch != nullptr) {
        GameLib_FreeMD6Branch(stack, mergeBranch);
        mergeBranch = nullptr;
    }
}

bool idAnimator_Proxy::InternalIsContributing() const {
    return mergeBranch != nullptr && mergeBranch->right != nullptr;
}
