#include "main.h"

idGameSuperInterface* gameInterface = nullptr;
idSuperScriptLocal superScriptLocal;

// Retail symbol: ?Lock@idSuperScriptLocal@@UAAPAVidGameSuperInterface@@PAV2@@Z
// EA: 0x82EECF38, RVA: 0x00EECF38
idGameSuperInterface* idSuperScriptLocal::Lock(
        idGameSuperInterface* const newInterface) {
    idGameSuperInterface* const previous = gameInterface;
    gameInterface = newInterface;
    return previous;
}

// Retail symbol: ?RegisterCVars@idSuperScriptLocal@@UAAXXZ
// EA: 0x82EECF48, RVA: 0x00EECF48
void idSuperScriptLocal::RegisterCVars() {
    Tungsten_RegisterStaticSuperScriptCVars();
}

// Retail symbol: ?GetSuperScriptAPI@@YAPAVidSuperScript@@H@Z
// EA: 0x82EECF50, RVA: 0x00EECF50
idSuperScript* GetSuperScriptAPI(const int version) {
    return version == 1 ? &superScriptLocal : nullptr;
}
