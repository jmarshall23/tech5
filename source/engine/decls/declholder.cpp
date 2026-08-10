#include "decls/declholder.h"

#include "decls/declelectricbolt.h"
#include "decls/animwebs/declanimweb.h"
#include "decls/declaf.h"
#include "decls/declbreakable.h"
#include "decls/declentitydef.h"
#include "decls/declenv.h"
#include "decls/declflare.h"
#include "decls/declfx.h"
#include "decls/declimpactparticle.h"
#include "decls/declimpactsound.h"
#include "decls/decldragjoints.h"
#include "decls/declmanagerlocal.h"
#include "decls/declmapinfo.h"
#include "decls/declproductionfilter.h"
#include "decls/declreachik.h"
#include "decls/declribbon.h"
#include "decls/declrollbones.h"
#include "decls/declskins.h"
#include "decls/declstaticimage.h"
#include "decls/decltable.h"
#include "decls/decltypeinfo.h"
#include "decls/declwalkik.h"
#include "decls/voiceovers/declvoiceover.h"
#include "decls/voiceovers/declvisemeset.h"
#include "models/particles/declparticle.h"

namespace {

void AddType(idDeclManagerLocal& manager, idDeclInfo* const type) {
    if (type != nullptr && manager.declTypes.FindIndex(type) < 0)
        manager.declTypes.Append(type);
}

} // namespace

// The 360 translation unit materialized these idDeclInfoTemplate records with
// dynamic initializers.  Their C++ static definitions live beside each class
// on PC; this function recreates the manager's discovery of those records.
void Decls_RegisterBuiltinDeclTypes(idDeclManagerLocal& manager) {
    AddType(manager, &idDeclTypeInfo::resourceList);
    AddType(manager, &idDeclAF::resourceList);
    AddType(manager, &idDeclAnimWeb::resourceList);
    AddType(manager, &idDeclBreakable::resourceList);
    AddType(manager, &idDeclFX::resourceList);
    AddType(manager, &idDeclEntityDef::resourceList);
    AddType(manager, &idDeclTable::resourceList);
    AddType(manager, &idDeclRibbon::resourceList);
    AddType(manager, &idDeclFlare::resourceList);
    AddType(manager, &idDeclElectricBolt::resourceList);
    AddType(manager, &idDeclEnv::resourceList);
    AddType(manager, &idDeclProductionFilter::resourceList);
    AddType(manager, &idDeclWalkIK::resourceList);
    AddType(manager, &idDeclReachIK::resourceList);
    AddType(manager, &idDeclRollBones::resourceList);
    AddType(manager, &idDeclDragJoints::resourceList);
    AddType(manager, &idDeclSkins::resourceList);
    AddType(manager, &idDeclVisemeSet::resourceList);
    AddType(manager, &idDeclVoiceOver::resourceList);
    AddType(manager, &idDeclParticle::resourceList);

    // These four classes are implemented in engine/decls, while the original
    // tungsten game registry supplied their tdef type records.
    AddType(manager, &idDeclImpactParticle::resourceList);
    AddType(manager, &idDeclImpactSound::resourceList);
    AddType(manager, &idDeclMapInfo::resourceList);
    AddType(manager, &idDeclStaticImage::resourceList);

    manager.RegisterDeclFolder("decls/ribbons", ".ribbon",
        &idDeclRibbon::resourceList);
    manager.RegisterDeclFolder("decls/af", ".af",
        &idDeclAF::resourceList);
    manager.RegisterDeclFolder("decls/animwebs", ".aweb",
        &idDeclAnimWeb::resourceList);
    manager.RegisterDeclFolder("decls/effects", ".break",
        &idDeclBreakable::resourceList);
    manager.RegisterDeclFolder("decls/flares", ".flare",
        &idDeclFlare::resourceList);
    manager.RegisterDeclFolder("decls/ebolts", ".ebolt",
        &idDeclElectricBolt::resourceList);
    manager.RegisterDeclFolder("decls/env", ".env",
        &idDeclEnv::resourceList);
    manager.RegisterDeclFolder("decls/ik", ".walkik",
        &idDeclWalkIK::resourceList);
    manager.RegisterDeclFolder("decls/reachik", ".reachik",
        &idDeclReachIK::resourceList);
    manager.RegisterDeclFolder("decls/rollbones", ".rollbones",
        &idDeclRollBones::resourceList);
    manager.RegisterDeclFolder("decls/visemes", ".vset",
        &idDeclVisemeSet::resourceList);
    manager.RegisterDeclFolder("decls/voiceovers", ".vo",
        &idDeclVoiceOver::resourceList);
    manager.RegisterDeclFolder("particles", ".prt",
        &idDeclParticle::resourceList);
}

void Decls_InitializeDeclHolders() {
    if (declManager != nullptr) declManager->Init();
}

void Decls_ShutdownDeclHolders() {
    if (declManager != nullptr) declManager->Shutdown();
}
