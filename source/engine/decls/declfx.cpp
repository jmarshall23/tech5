#include "decls/declfx.h"

#include "gamelib/effects/fxmanager.h"
#include "idlib/filesystem/file.h"
#include "idlib/text/parser.h"
#include "idlib/text/str.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>
#include <cmath>
#include <cstring>

const idDeclTable* Decls_FindTable(const char* name);
const idMaterial* Decls_FindMaterial(const char* name);
const idDeclParticle* Decls_FindParticle(const char* name);
const idSoundShader* Decls_FindSoundShader(const char* name);
const idDeclRenderParm* Decls_FindRenderParm(const char* name);
const idDeclEnv* Decls_FindEnv(const char* name);
const idDeclFlare* Decls_FindFlare(const char* name);
const idDeclRibbon* Decls_FindRibbon(const char* name);
const char* Decls_FXResourceName(const void* resource);
fxCondition_t Decls_FXConditionForName(const char* name);
fxExtraCondition_t Decls_FXExtraConditionForName(const char* name);
const char* Decls_FXConditionName(fxCondition_t condition);
const char* Decls_FXExtraConditionName(fxExtraCondition_t condition);
int Decls_FXParticleDuration(const idDeclParticle* particle);
void Decls_FXSoundProperties(const idSoundShader* sound, bool& looping,
    int& durationMilliseconds, soundChannel_t& channel);

namespace {

constexpr const char* FX_TEXT_VERSION_STRING = "fxVersion";
constexpr int FX_TEXT_VERSION = 1;

const char* const actionTypeNames[FX_MAX] = {
    "light", "particle", "decal", "decal2", "model", "sound",
    "shake", "controllershake", "wind", "renderParm", "environment",
    "environment", "flare", "radialBlur", "ribbon", "fadeparent"
};

const char* OriginName(const fxOriginType_t value) {
    static const char* const names[] = {
        "FX_ORG_START_POS", "FX_ORG_TRACK_POS", "FX_ORG_TRACK_LOCAL_POS",
        "FX_ORG_EXTERNALPOS"
    };
    return value >= FX_ORG_START_POS && value <= FX_ORG_EXTERNALPOS
        ? names[value] : names[0];
}

fxOriginType_t OriginForName(const char* const name) {
    if (idStr::Icmp(name, "FX_ORG_TRACK_POS") == 0
        || idStr::Icmp(name, "track") == 0) return FX_ORG_TRACK_POS;
    if (idStr::Icmp(name, "FX_ORG_TRACK_LOCAL_POS") == 0
        || idStr::Icmp(name, "trackLocal") == 0) return FX_ORG_TRACK_LOCAL_POS;
    if (idStr::Icmp(name, "FX_ORG_EXTERNALPOS") == 0
        || idStr::Icmp(name, "external") == 0) return FX_ORG_EXTERNALPOS;
    return FX_ORG_START_POS;
}

const char* RotationName(const fxRotationType_t value) {
    static const char* const names[] = {
        "FX_ROT_START_AXIS", "FX_ROT_START_AXIS_PARENT", "FX_ROT_TRACK_AXIS",
        "FX_ROT_TRACK_AXIS_PARENT", "FX_ROT_TRACK_LOCAL_AXIS",
        "FX_ROT_EXPLICIT_ANGLES", "FX_ROT_EXPLICIT_TABLES",
        "FX_ROT_EXPLICIT_TABLES_LOCAL", "FX_ROT_EXTERNALROT"
    };
    return value >= FX_ROT_START_AXIS && value <= FX_ROT_EXTERNALROT
        ? names[value] : names[0];
}

fxRotationType_t RotationForName(const char* const name) {
    static const fxRotationType_t values[] = {
        FX_ROT_START_AXIS, FX_ROT_START_AXIS_PARENT, FX_ROT_TRACK_AXIS,
        FX_ROT_TRACK_AXIS_PARENT, FX_ROT_TRACK_LOCAL_AXIS,
        FX_ROT_EXPLICIT_ANGLES, FX_ROT_EXPLICIT_TABLES,
        FX_ROT_EXPLICIT_TABLES_LOCAL, FX_ROT_EXTERNALROT
    };
    for (int index = 0; index < 9; ++index)
        if (idStr::Icmp(name, RotationName(values[index])) == 0)
            return values[index];
    return FX_ROT_START_AXIS;
}

const char* MultiTagName(const fxMultiTagUseType_t value) {
    static const char* const names[] = {
        "FX_MULTI_TAG_USE_RND", "FX_MULTI_TAG_USE_EXPLICIT",
        "FX_MULTI_TAG_USE_ALL"
    };
    return value >= FX_MULTI_TAG_USE_RND && value <= FX_MULTI_TAG_USE_ALL
        ? names[value] : names[0];
}

fxMultiTagUseType_t MultiTagForName(const char* const name) {
    if (idStr::Icmp(name, "FX_MULTI_TAG_USE_EXPLICIT") == 0
        || idStr::Icmp(name, "explicit") == 0)
        return FX_MULTI_TAG_USE_EXPLICIT;
    if (idStr::Icmp(name, "FX_MULTI_TAG_USE_ALL") == 0
        || idStr::Icmp(name, "all") == 0) return FX_MULTI_TAG_USE_ALL;
    return FX_MULTI_TAG_USE_RND;
}

void ReadVec2(idParser& parser, idVec2& value) {
    value.x = parser.ParseFloat();
    parser.CheckTokenString(",");
    value.y = parser.ParseFloat();
}

void ReadVec3(idParser& parser, idVec3& value) {
    value.x = parser.ParseFloat(); parser.CheckTokenString(",");
    value.y = parser.ParseFloat(); parser.CheckTokenString(",");
    value.z = parser.ParseFloat();
}

void ReadAngles(idParser& parser, idAngles& value) {
    value.pitch = parser.ParseFloat(); parser.CheckTokenString(",");
    value.yaw = parser.ParseFloat(); parser.CheckTokenString(",");
    value.roll = parser.ParseFloat();
}

void ReadColor(idParser& parser, idVec4& value) {
    value.x = parser.ParseFloat(); parser.CheckTokenString(",");
    value.y = parser.ParseFloat(); parser.CheckTokenString(",");
    value.z = parser.ParseFloat(); parser.CheckTokenString(",");
    value.w = parser.ParseFloat();
}

template<class valueType, int tag>
void ReadEnumLine(idParser& parser, idList<valueType, tag>& output,
        valueType (*resolver)(const char*)) {
    idToken token;
    while (parser.ReadTokenOnLine(token) != 0) {
        if (idStr::Cmp(token.c_str(), ",") != 0)
            output.Append(resolver(token.c_str()));
    }
}

void ReadTagLine(idParser& parser, idList<idAtomicString, 109>& output) {
    idToken token;
    while (parser.ReadTokenOnLine(token) != 0)
        if (idStr::Cmp(token.c_str(), ",") != 0)
            output.Append(idAtomicString(token.c_str()));
}

const char* ResourceName(const void* const resource) {
    return resource != nullptr ? Decls_FXResourceName(resource) : "";
}

} // namespace

idDeclInfoTemplate<idDeclFX> idDeclFX::resourceList(
    "fx", "idDeclFX", "fx");

idFXSingleAction::idFXSingleAction()
    : tagNames(16), startCondition(16), stopCondition(16), extraCondition(16) {
    Default();
}

void idFXSingleAction::Default() {
    name.Set("<none>");
    group.Set("");
    type = FX_MAX;
    duration = 2.0f;
    delay = idVec2(0.0f, 0.0f);
    restart = false;
    looping = false;
    fadeInTime = 0.0f;
    fadeOutTime = 0.0f;
    fadeStartDistance = 0.0f;
    distance = -1.0f;
    size = 1.0f;
    color = idVec4(1.0f, 1.0f, 1.0f, 1.0f);
    noshadows = true;
    fire.Set("");
    multiTagUseType = FX_MULTI_TAG_USE_RND;
    tagNames.Clear();
    startCondition.Clear();
    stopCondition.Clear();
    extraCondition.Clear();
    originType = FX_ORG_START_POS;
    offset = idVec3(0.0f, 0.0f, 0.0f);
    rotationType = FX_ROT_START_AXIS;
    rotOffsetAngles = idAngles(0.0f, 0.0f, 0.0f);
    rndRotX = idVec2(0.0f, 0.0f);
    rndRotY = idVec2(0.0f, 0.0f);
    rndRotZ = idVec2(0.0f, 0.0f);
    explicitAngles = idAngles(0.0f, 0.0f, 0.0f);
    rotateTablePitch = nullptr;
    rotateTableYaw = nullptr;
    rotateTableRoll = nullptr;
    colorTableRGB = nullptr;
    colorTableA = nullptr;
    customTable1 = nullptr;
    customTable2 = nullptr;
    customRenderParm = nullptr;
    lightParms.radius = idVec3(0.0f, 0.0f, 0.0f);
    lightParms.intensity = 1.0f;
    lightParms.lightMtr = nullptr;
    particleParms.trackVelocity = false;
    particleParms.velocityScale = 1.0f;
    particleParms.minVelocity = 0.0f;
    particleParms.useSmokeSystem = false;
    particleParms.smokeSystemRate = 1;
    particleParms.trailSpacing = 0.0f;
    particleParms.isScreenPrt = false;
    particleParms.screenPrtExcludeAngle = -1.0f;
    particleParms.declPrt = nullptr;
    decalParms.angle = 0.0f;
    decalParms.depth = 8.0f;
    decalParms.decalMtr = nullptr;
    modelParms.modelName.Set("");
    modelParms.customMaterial = nullptr;
    soundParms.channel = SND_CHANNEL_ANY;
    soundParms.sound = nullptr;
    screenShakeParms.magnitude = 0.0f;
    screenShakeParms.maxAngles = idAngles(0.2f, 0.2f, 0.2f);
    screenShakeParms.maxOffset = idVec3(0.2f, 0.2f, 0.2f);
    controllerShakeParms.highMag = 0.5f;
    controllerShakeParms.lowMag = 1.0f;
    controllerShakeParms.highDuration = 200.0f;
    controllerShakeParms.lowDuration = 100.0f;
    windParms.angle = 0.0f;
    windParms.multiplier = 0.1f;
    windParms.strength = idVec2(10.0f, 30.0f);
    renderParmParms.declRenderParm = nullptr;
    envParms.declEnv = nullptr;
    envParms.envRenderParm.Clear();
    radialBlurParms.maxScale = 0.3f;
    flareParms.position = idVec3(0.0f, 0.0f, 0.0f);
    flareParms.isAutosprited = false;
    flareParms.declFlare = nullptr;
    ribbonParms.declRibbon = nullptr;
    axis = idMat3(1.0f);
    rotOffset = idMat3(1.0f);
    implicit = false;
    triggered = false;
}

idDeclFX::idDeclFX() : editEvents(16), events(16), changeId(-1) {
    FreeData();
}

idDeclFX::~idDeclFX() { FreeData(); }

idDeclInfo* idDeclFX::GetDeclInfo() const { return &resourceList; }

const char* idDeclFX::DefaultDefinition() const {
    return "{\n\t{\n\t\tduration\t2\n\t}\n}\n";
}

void idDeclFX::FreeData() {
    editEvents.ClearFree();
    events.ClearFree();
}

unsigned int idDeclFX::Size() const {
    return static_cast<unsigned int>(sizeof(*this)
        + editEvents.MemoryUsed() + events.MemoryUsed());
}

const char* idDeclFX::FXActionTypeToName(const fxActionType_t type) {
    return type >= FX_LIGHT && type < FX_MAX
        ? actionTypeNames[type] : "FX_MAX (invalid?)";
}

const char* idDeclFX::FXConditionToName(const fxCondition_t condition) {
    return Decls_FXConditionName(condition);
}

int idDeclFX::GetMaxDuration(const fxCondition_t condition) const {
    int maximum = 0;
    for (int index = 0; index < events.Num(); ++index) {
        const idFXSingleAction& action = events[index];
        if (action.startCondition.FindIndex(condition) < 0
            && action.startCondition.FindIndex(FX_NONE) < 0) continue;
        int duration = static_cast<int>(action.duration * 1000.0f);
        if (duration <= 0 && action.type == FX_PARTICLE)
            duration = Decls_FXParticleDuration(action.particleParms.declPrt);
        duration += static_cast<int>(action.delay.y * 1000.0f);
        maximum = (std::max)(maximum, duration);
    }
    return maximum;
}

int idDeclFX::GetMaxFadeOutTime(const fxCondition_t condition) const {
    int maximum = 0;
    for (int index = 0; index < events.Num(); ++index) {
        const idFXSingleAction& action = events[index];
        if (action.startCondition.FindIndex(condition) < 0
            && action.startCondition.FindIndex(FX_NONE) < 0) continue;
        maximum = (std::max)(maximum,
            static_cast<int>(action.fadeOutTime * 1000.0f));
    }
    return maximum;
}

void idDeclFX::WriteSingleFXAction(idFile& file,
        const idFXSingleAction& action) const {
    if (action.implicit) return;
    file.WriteFloatString("\t{\n");
    if (!action.name.IsEmpty() && idStr::Cmp(action.name.c_str(), "<none>") != 0)
        file.WriteFloatString("\t\tname\t\t\t\"%s\"\n", action.name.c_str());
    if (!action.group.IsEmpty())
        file.WriteFloatString("\t\tgroup\t\t\t\"%s\"\n", action.group.c_str());
    if (action.delay.x != 0.0f || action.delay.y != 0.0f)
        file.WriteFloatString("\t\tdelay\t\t\t%.3f, %.3f\n", action.delay.x, action.delay.y);
    if (action.type != FX_SOUND)
        file.WriteFloatString("\t\tduration\t\t\t%.3f\n", action.duration);
    if (action.fadeInTime != 0.0f)
        file.WriteFloatString("\t\tfadeIn\t\t\t%.3f\n", action.fadeInTime);
    if (action.fadeOutTime != 0.0f)
        file.WriteFloatString("\t\tfadeOut\t\t\t%.3f\n", action.fadeOutTime);
    if (action.restart) file.WriteFloatString("\t\trestart\t\t\t1\n");
    if (action.looping && action.type != FX_SOUND)
        file.WriteFloatString("\t\tlooping\t\t\t1\n");
    if (!action.noshadows) file.WriteFloatString("\t\tnoshadows\t\t\t0\n");
    if (action.offset.x != 0.0f || action.offset.y != 0.0f || action.offset.z != 0.0f)
        file.WriteFloatString("\t\toffset\t\t\t%.3f, %.3f, %.3f\n",
            action.offset.x, action.offset.y, action.offset.z);
    if (action.rotOffsetAngles.pitch != 0.0f || action.rotOffsetAngles.yaw != 0.0f
        || action.rotOffsetAngles.roll != 0.0f)
        file.WriteFloatString("\t\trotOffset\t\t\t%.3f, %.3f, %.3f\n",
            action.rotOffsetAngles.pitch, action.rotOffsetAngles.yaw,
            action.rotOffsetAngles.roll);
    if (action.size != 1.0f)
        file.WriteFloatString("\t\tsize\t\t\t%.3f\n", action.size);
    if (action.rotationType == FX_ROT_EXPLICIT_ANGLES)
        file.WriteFloatString("\t\texplicitAngles\t\t\t%.3f, %.3f, %.3f\n",
            action.explicitAngles.pitch, action.explicitAngles.yaw,
            action.explicitAngles.roll);
    if (action.rotateTablePitch != nullptr)
        file.WriteFloatString("\t\trotateTablePitch\t\t\t\t\"%s\"\n",
            ResourceName(action.rotateTablePitch));
    if (action.rotateTableYaw != nullptr)
        file.WriteFloatString("\t\trotateTableYaw\t\t\t\t\"%s\"\n",
            ResourceName(action.rotateTableYaw));
    if (action.rotateTableRoll != nullptr)
        file.WriteFloatString("\t\trotateTableRoll\t\t\t\t\"%s\"\n",
            ResourceName(action.rotateTableRoll));
    if (action.rndRotX.x != 0.0f || action.rndRotX.y != 0.0f)
        file.WriteFloatString("\t\trandomRotationX\t\t\t%.3f, %.3f\n",
            action.rndRotX.x, action.rndRotX.y);
    if (action.rndRotY.x != 0.0f || action.rndRotY.y != 0.0f)
        file.WriteFloatString("\t\trandomRotationY\t\t\t%.3f, %.3f\n",
            action.rndRotY.x, action.rndRotY.y);
    if (action.rndRotZ.x != 0.0f || action.rndRotZ.y != 0.0f)
        file.WriteFloatString("\t\trandomRotationZ\t\t\t%.3f, %.3f\n",
            action.rndRotZ.x, action.rndRotZ.y);
    if (!action.fire.IsEmpty())
        file.WriteFloatString("\t\tfire\t\t\t\"%s\"\n", action.fire.c_str());
    if (action.tagNames.Num() > 0)
        file.WriteFloatString("\t\tmultiTagUseType\t\t\t%s\n",
            MultiTagName(action.multiTagUseType));
    if (action.originType != FX_ORG_START_POS)
        file.WriteFloatString("\t\toriginType\t\t\t%s\n", OriginName(action.originType));
    if (action.rotationType != FX_ROT_START_AXIS)
        file.WriteFloatString("\t\trotationType\t\t\t%s\n",
            RotationName(action.rotationType));

    if (action.tagNames.Num() > 0) {
        file.WriteFloatString("\t\ttagName\t\t\t");
        for (int index = 0; index < action.tagNames.Num(); ++index)
            file.WriteFloatString("\"%s\" ", action.tagNames[index].c_str());
        file.WriteFloatString("\n");
    }
    if (action.startCondition.Num() > 0) {
        file.WriteFloatString("\t\tstartCondition\t\t\t");
        for (int index = 0; index < action.startCondition.Num(); ++index)
            file.WriteFloatString("%s ", Decls_FXConditionName(action.startCondition[index]));
        file.WriteFloatString("\n");
    }
    if (action.stopCondition.Num() > 0) {
        file.WriteFloatString("\t\tstopCondition\t\t\t");
        for (int index = 0; index < action.stopCondition.Num(); ++index)
            file.WriteFloatString("%s ", Decls_FXConditionName(action.stopCondition[index]));
        file.WriteFloatString("\n");
    }
    if (action.extraCondition.Num() > 0) {
        file.WriteFloatString("\t\textraCondition\t\t\t");
        for (int index = 0; index < action.extraCondition.Num(); ++index)
            file.WriteFloatString("%s ", Decls_FXExtraConditionName(action.extraCondition[index]));
        file.WriteFloatString("\n");
    }
    if (action.colorTableRGB != nullptr)
        file.WriteFloatString("\t\tcolorTableRGB\t\t\t\t\"%s\"\n",
            ResourceName(action.colorTableRGB));
    if (action.colorTableA != nullptr)
        file.WriteFloatString("\t\tcolorTableAlpha\t\t\t\t\"%s\"\n",
            ResourceName(action.colorTableA));
    if (action.customRenderParm != nullptr)
        file.WriteFloatString("\t\tcustomRenderParm\t\t\t\t\"%s\"\n",
            ResourceName(action.customRenderParm));
    if (action.customTable1 != nullptr)
        file.WriteFloatString("\t\tcustomTable1\t\t\t\t\"%s\"\n",
            ResourceName(action.customTable1));
    if (action.customTable2 != nullptr)
        file.WriteFloatString("\t\tcustomTable2\t\t\t\t\"%s\"\n",
            ResourceName(action.customTable2));

    switch (action.type) {
    case FX_LIGHT:
        file.WriteFloatString("\t\tlight\t\t\t\"%s\", %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f\n",
            ResourceName(action.lightParms.lightMtr), action.color.x, action.color.y,
            action.color.z, action.lightParms.radius.x, action.lightParms.radius.y,
            action.lightParms.radius.z, action.lightParms.intensity);
        break;
    case FX_PARTICLE:
        file.WriteFloatString("\t\tparticle\t\t\t\t\"%s\"\n",
            ResourceName(action.particleParms.declPrt));
        if (action.particleParms.useSmokeSystem) {
            file.WriteFloatString("\t\tuseSmokeSystem\t\t\t\t1\n");
            file.WriteFloatString("\t\tsmokeSystemRate\t\t\t\t%d\n",
                action.particleParms.smokeSystemRate);
            file.WriteFloatString("\t\ttrailSpacing\t\t\t\t%.3f\n",
                action.particleParms.trailSpacing);
        }
        if (action.particleParms.trackVelocity) {
            file.WriteFloatString("\t\tparticleTrackVelocity\n");
            file.WriteFloatString("\t\tvelocityScale\t\t\t\t%.3f\n",
                action.particleParms.velocityScale);
            file.WriteFloatString("\t\tminVelocity\t\t\t\t%.3f\n",
                action.particleParms.minVelocity);
        }
        if (action.particleParms.isScreenPrt) {
            file.WriteFloatString("\t\tisScreenPrt\t\t\t\t1\n");
            file.WriteFloatString("\t\tscreenPrtExcludeAngle\t\t\t\t%.3f\n",
                action.particleParms.screenPrtExcludeAngle);
        }
        file.WriteFloatString("\t\tcolor\t\t\t%.3f, %.3f, %.3f, %.3f\n",
            action.color.x, action.color.y, action.color.z, action.color.w);
        break;
    case FX_DECAL:
        file.WriteFloatString("\t\tdecal\t\t\t\t\"%s\", %.3f, %.3f\n",
            ResourceName(action.decalParms.decalMtr), action.decalParms.angle,
            action.decalParms.depth);
        break;
    case FX_DECAL2:
        file.WriteFloatString("\t\tdecal2\t\t\t\t\"%s\", %.3f\n",
            ResourceName(action.decalParms.decalMtr), action.decalParms.depth);
        break;
    case FX_MODEL:
        file.WriteFloatString("\t\tmodel\t\t\t\t\"%s\"\n",
            action.modelParms.modelName.c_str());
        if (action.modelParms.customMaterial != nullptr)
            file.WriteFloatString("\t\tcustomMaterial\t\t\t\t\"%s\"\n",
                ResourceName(action.modelParms.customMaterial));
        file.WriteFloatString("\t\tcolor\t\t\t%.3f, %.3f, %.3f, %.3f\n",
            action.color.x, action.color.y, action.color.z, action.color.w);
        break;
    case FX_SOUND:
        file.WriteFloatString("\t\tsound\t\t\t\t\"%s\"\n",
            ResourceName(action.soundParms.sound));
        break;
    case FX_SCREEN_SHAKE:
        file.WriteFloatString("\t\tshake\t\t\t%.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f\n",
            action.screenShakeParms.magnitude, action.distance,
            action.screenShakeParms.maxAngles.pitch,
            action.screenShakeParms.maxAngles.yaw,
            action.screenShakeParms.maxAngles.roll,
            action.screenShakeParms.maxOffset.x,
            action.screenShakeParms.maxOffset.y,
            action.screenShakeParms.maxOffset.z);
        break;
    case FX_CONTROLLER_SHAKE:
        file.WriteFloatString("\t\tcontrollershake\t\t\t%.3f, %.3f, %.3f, %.3f\n",
            action.controllerShakeParms.highMag,
            action.controllerShakeParms.lowMag,
            action.controllerShakeParms.highDuration,
            action.controllerShakeParms.lowDuration);
        break;
    case FX_WIND:
        file.WriteFloatString("\t\twind\t\t\t%.3f, %.3f, %.3f, %.3f\n",
            action.windParms.angle, action.windParms.multiplier,
            action.windParms.strength.x, action.windParms.strength.y);
        break;
    case FX_RENDERPARM:
        file.WriteFloatString("\t\trenderParm\t\t\t\t\"%s\"\n",
            ResourceName(action.renderParmParms.declRenderParm));
        break;
    case FX_ENV_OVERRIDE:
    case FX_ENV_CHANGE:
        file.WriteFloatString("\t\tenvironment\t\t\t\t\"%s\", %.3f\n",
            ResourceName(action.envParms.declEnv), action.duration);
        break;
    case FX_FLARE:
        file.WriteFloatString("\t\tflare\t\t\t\t\"%s\", %.3f, %.3f, %.3f, %d, %.3f, %.3f\n",
            ResourceName(action.flareParms.declFlare), action.flareParms.position.x,
            action.flareParms.position.y, action.flareParms.position.z,
            action.flareParms.isAutosprited ? 1 : 0, action.size, action.distance);
        break;
    case FX_RADIAL_BLUR:
        file.WriteFloatString("\t\tradialBlur\t\t\t%.3f\n",
            action.radialBlurParms.maxScale);
        break;
    case FX_RIBBON:
        file.WriteFloatString("\t\tribbon\t\t\t\t\"%s\"\n",
            ResourceName(action.ribbonParms.declRibbon));
        break;
    case FX_FADE_PARENT:
        file.WriteFloatString("\t\tfadeParent\n");
        break;
    default:
        break;
    }
    file.WriteFloatString("\t}\n");
}

bool idDeclFX::RebuildTextSource() {
    idFile_Memory file;
    file.WriteFloatString("{\n\t%s %d\n\n", FX_TEXT_VERSION_STRING,
        FX_TEXT_VERSION);
    for (int index = 0; index < editEvents.Num(); ++index)
        WriteSingleFXAction(file, editEvents[index]);
    file.WriteFloatString("}");
    SetText(file.GetDataPtr(), static_cast<int>(file.Length()));
    return true;
}

void idDeclFX::ParseSingleFXAction(idParser& parser,
        idFXSingleAction& action) {
    idToken token;
    while (parser.ReadToken(token) != 0) {
        const char* const key = token.c_str();
        if (idStr::Cmp(key, "}") == 0) return;
        if (idStr::Icmp(key, "name") == 0) {
            parser.ReadToken(token); action.name.Set(token.c_str());
        } else if (idStr::Icmp(key, "group") == 0) {
            parser.ReadToken(token); action.group.Set(token.c_str());
        } else if (idStr::Icmp(key, "fire") == 0) {
            parser.ReadToken(token); action.fire.Set(token.c_str());
        } else if (idStr::Icmp(key, "multiTagUseType") == 0) {
            parser.ReadToken(token); action.multiTagUseType = MultiTagForName(token.c_str());
        } else if (idStr::Icmp(key, "tagName") == 0) {
            ReadTagLine(parser, action.tagNames);
        } else if (idStr::Icmp(key, "startCondition") == 0) {
            ReadEnumLine(parser, action.startCondition, Decls_FXConditionForName);
        } else if (idStr::Icmp(key, "stopCondition") == 0) {
            ReadEnumLine(parser, action.stopCondition, Decls_FXConditionForName);
        } else if (idStr::Icmp(key, "extraCondition") == 0) {
            ReadEnumLine(parser, action.extraCondition, Decls_FXExtraConditionForName);
        } else if (idStr::Icmp(key, "delay") == 0) ReadVec2(parser, action.delay);
        else if (idStr::Icmp(key, "duration") == 0) action.duration = parser.ParseFloat();
        else if (idStr::Icmp(key, "fadeIn") == 0) action.fadeInTime = parser.ParseFloat();
        else if (idStr::Icmp(key, "fadeOut") == 0) action.fadeOutTime = parser.ParseFloat();
        else if (idStr::Icmp(key, "fadeStartDistance") == 0) action.fadeStartDistance = parser.ParseFloat();
        else if (idStr::Icmp(key, "distance") == 0) action.distance = parser.ParseFloat();
        else if (idStr::Icmp(key, "size") == 0) action.size = parser.ParseFloat();
        else if (idStr::Icmp(key, "restart") == 0) action.restart = parser.ParseBool();
        else if (idStr::Icmp(key, "looping") == 0) action.looping = parser.ParseBool();
        else if (idStr::Icmp(key, "noshadows") == 0) action.noshadows = parser.ParseBool();
        else if (idStr::Icmp(key, "originType") == 0) {
            parser.ReadToken(token); action.originType = OriginForName(token.c_str());
        } else if (idStr::Icmp(key, "rotationType") == 0) {
            parser.ReadToken(token); action.rotationType = RotationForName(token.c_str());
        } else if (idStr::Icmp(key, "offset") == 0) ReadVec3(parser, action.offset);
        else if (idStr::Icmp(key, "rotOffset") == 0) ReadAngles(parser, action.rotOffsetAngles);
        else if (idStr::Icmp(key, "explicitAngles") == 0) {
            ReadAngles(parser, action.explicitAngles);
            action.rotationType = FX_ROT_EXPLICIT_ANGLES;
        } else if (idStr::Icmp(key, "randomRotationX") == 0
            || idStr::Icmp(key, "rndRotX") == 0) ReadVec2(parser, action.rndRotX);
        else if (idStr::Icmp(key, "randomRotationY") == 0
            || idStr::Icmp(key, "rndRotY") == 0) ReadVec2(parser, action.rndRotY);
        else if (idStr::Icmp(key, "randomRotationZ") == 0
            || idStr::Icmp(key, "rndRotZ") == 0) ReadVec2(parser, action.rndRotZ);
        else if (idStr::Icmp(key, "rotateTablePitch") == 0) {
            parser.ReadToken(token); action.rotateTablePitch = Decls_FindTable(token.c_str());
        } else if (idStr::Icmp(key, "rotateTableYaw") == 0) {
            parser.ReadToken(token); action.rotateTableYaw = Decls_FindTable(token.c_str());
        } else if (idStr::Icmp(key, "rotateTableRoll") == 0) {
            parser.ReadToken(token); action.rotateTableRoll = Decls_FindTable(token.c_str());
        } else if (idStr::Icmp(key, "colorTableRGB") == 0) {
            parser.ReadToken(token); action.colorTableRGB = Decls_FindTable(token.c_str());
        } else if (idStr::Icmp(key, "colorTableAlpha") == 0) {
            parser.ReadToken(token); action.colorTableA = Decls_FindTable(token.c_str());
        } else if (idStr::Icmp(key, "customTable1") == 0) {
            parser.ReadToken(token); action.customTable1 = Decls_FindTable(token.c_str());
        } else if (idStr::Icmp(key, "customTable2") == 0) {
            parser.ReadToken(token); action.customTable2 = Decls_FindTable(token.c_str());
        } else if (idStr::Icmp(key, "customRenderParm") == 0) {
            parser.ReadToken(token); action.customRenderParm = Decls_FindRenderParm(token.c_str());
        } else if (idStr::Icmp(key, "color") == 0) ReadColor(parser, action.color);
        else if (idStr::Icmp(key, "light") == 0) {
            action.type = FX_LIGHT;
            parser.ReadToken(token); action.lightParms.lightMtr = Decls_FindMaterial(token.c_str());
            parser.CheckTokenString(",");
            action.color.x = parser.ParseFloat(); parser.CheckTokenString(",");
            action.color.y = parser.ParseFloat(); parser.CheckTokenString(",");
            action.color.z = parser.ParseFloat(); parser.CheckTokenString(",");
            ReadVec3(parser, action.lightParms.radius); parser.CheckTokenString(",");
            action.lightParms.intensity = parser.ParseFloat();
        } else if (idStr::Icmp(key, "particle") == 0) {
            action.type = FX_PARTICLE; parser.ReadToken(token);
            action.particleParms.declPrt = Decls_FindParticle(token.c_str());
        } else if (idStr::Icmp(key, "particleTrackVelocity") == 0)
            action.particleParms.trackVelocity = true;
        else if (idStr::Icmp(key, "velocityScale") == 0)
            action.particleParms.velocityScale = parser.ParseFloat();
        else if (idStr::Icmp(key, "minVelocity") == 0)
            action.particleParms.minVelocity = parser.ParseFloat();
        else if (idStr::Icmp(key, "useSmokeSystem") == 0)
            action.particleParms.useSmokeSystem = parser.ParseBool();
        else if (idStr::Icmp(key, "smokeSystemRate") == 0)
            action.particleParms.smokeSystemRate = parser.ParseInt();
        else if (idStr::Icmp(key, "trailSpacing") == 0)
            action.particleParms.trailSpacing = parser.ParseFloat();
        else if (idStr::Icmp(key, "isScreenPrt") == 0)
            action.particleParms.isScreenPrt = parser.ParseBool();
        else if (idStr::Icmp(key, "screenPrtExcludeAngle") == 0)
            action.particleParms.screenPrtExcludeAngle = parser.ParseFloat();
        else if (idStr::Icmp(key, "decal") == 0 || idStr::Icmp(key, "decal2") == 0) {
            action.type = idStr::Icmp(key, "decal") == 0 ? FX_DECAL : FX_DECAL2;
            parser.ReadToken(token); action.decalParms.decalMtr = Decls_FindMaterial(token.c_str());
            parser.CheckTokenString(",");
            if (action.type == FX_DECAL) {
                action.decalParms.angle = parser.ParseFloat(); parser.CheckTokenString(",");
            }
            action.decalParms.depth = parser.ParseFloat();
        } else if (idStr::Icmp(key, "model") == 0) {
            action.type = FX_MODEL; parser.ReadToken(token);
            action.modelParms.modelName.Set(token.c_str());
        } else if (idStr::Icmp(key, "customMaterial") == 0) {
            parser.ReadToken(token); action.modelParms.customMaterial = Decls_FindMaterial(token.c_str());
        } else if (idStr::Icmp(key, "sound") == 0) {
            action.type = FX_SOUND; parser.ReadToken(token);
            action.soundParms.sound = Decls_FindSoundShader(token.c_str());
        } else if (idStr::Icmp(key, "shake") == 0) {
            action.type = FX_SCREEN_SHAKE;
            action.screenShakeParms.magnitude = parser.ParseFloat(); parser.CheckTokenString(",");
            action.distance = parser.ParseFloat(); parser.CheckTokenString(",");
            ReadAngles(parser, action.screenShakeParms.maxAngles); parser.CheckTokenString(",");
            ReadVec3(parser, action.screenShakeParms.maxOffset);
        } else if (idStr::Icmp(key, "controllershake") == 0) {
            action.type = FX_CONTROLLER_SHAKE;
            action.controllerShakeParms.highMag = parser.ParseFloat(); parser.CheckTokenString(",");
            action.controllerShakeParms.lowMag = parser.ParseFloat(); parser.CheckTokenString(",");
            action.controllerShakeParms.highDuration = parser.ParseFloat(); parser.CheckTokenString(",");
            action.controllerShakeParms.lowDuration = parser.ParseFloat();
        } else if (idStr::Icmp(key, "wind") == 0) {
            action.type = FX_WIND;
            action.windParms.angle = parser.ParseFloat(); parser.CheckTokenString(",");
            action.windParms.multiplier = parser.ParseFloat(); parser.CheckTokenString(",");
            ReadVec2(parser, action.windParms.strength);
        } else if (idStr::Icmp(key, "renderParm") == 0) {
            action.type = FX_RENDERPARM; parser.ReadToken(token);
            action.renderParmParms.declRenderParm = Decls_FindRenderParm(token.c_str());
        } else if (idStr::Icmp(key, "environment") == 0
            || idStr::Icmp(key, "environmentOverride") == 0) {
            action.type = idStr::Icmp(key, "environmentOverride") == 0
                ? FX_ENV_OVERRIDE : FX_ENV_CHANGE;
            parser.ReadToken(token); action.envParms.declEnv = Decls_FindEnv(token.c_str());
            if (parser.CheckTokenString(",") != 0) action.duration = parser.ParseFloat();
        } else if (idStr::Icmp(key, "flare") == 0) {
            action.type = FX_FLARE; parser.ReadToken(token);
            action.flareParms.declFlare = Decls_FindFlare(token.c_str());
            parser.CheckTokenString(","); ReadVec3(parser, action.flareParms.position);
            if (parser.CheckTokenString(",") != 0)
                action.flareParms.isAutosprited = parser.ParseBool();
            if (parser.CheckTokenString(",") != 0) action.size = parser.ParseFloat();
            if (parser.CheckTokenString(",") != 0) action.distance = parser.ParseFloat();
        } else if (idStr::Icmp(key, "radialBlur") == 0) {
            action.type = FX_RADIAL_BLUR;
            action.radialBlurParms.maxScale = parser.ParseFloat();
        } else if (idStr::Icmp(key, "ribbon") == 0) {
            action.type = FX_RIBBON; parser.ReadToken(token);
            action.ribbonParms.declRibbon = Decls_FindRibbon(token.c_str());
        } else if (idStr::Icmp(key, "fadeparent") == 0) {
            action.type = FX_FADE_PARENT;
        } else {
            parser.Warning("FX File: bad token '%s'", key);
        }
    }
}

void idDeclFX::Parse(idParser* const parser) {
    FreeData();
    ++changeId;
    if (parser == nullptr) return;

    idToken token;
    if (parser->ReadToken(token) == 0) return;
    if (idStr::Cmp(token.c_str(), FX_TEXT_VERSION_STRING) == 0)
        parser->ParseInt();
    else parser->UnreadToken(token);

    while (parser->ReadToken(token) != 0) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        if (token.type == 1) {
            idToken brace;
            if (parser->ReadToken(brace) == 0) break;
            token = brace;
        }
        if (idStr::Cmp(token.c_str(), "{") != 0) {
            parser->Warning("FX File: expected action block, found '%s'", token.c_str());
            continue;
        }
        idFXSingleAction action;
        ParseSingleFXAction(*parser, action);
        editEvents.Append(action);
    }

    for (int index = 0; index < editEvents.Num(); ++index) {
        idFXSingleAction& action = editEvents[index];
        if (action.startCondition.Num() == 0) action.startCondition.Append(FX_NONE);
        if (action.stopCondition.Num() == 0) action.stopCondition.Append(FX_NONE);
        if (action.type == FX_SOUND && action.soundParms.sound != nullptr) {
            int durationMilliseconds = 0;
            Decls_FXSoundProperties(action.soundParms.sound, action.looping,
                durationMilliseconds, action.soundParms.channel);
            if (!action.looping) action.duration = durationMilliseconds * 0.001f;
        }
        events.Append(action);
        if (action.multiTagUseType == FX_MULTI_TAG_USE_ALL
            && action.tagNames.Num() > 1) {
            for (int tag = 1; tag < action.tagNames.Num(); ++tag) {
                idFXSingleAction clone(action);
                clone.tagNames.Clear();
                clone.tagNames.Append(action.tagNames[tag]);
                clone.implicit = true;
                events.Append(clone);
            }
        }
    }

    for (int fired = 0; fired < events.Num(); ++fired) {
        if (events[fired].fire.IsEmpty()) continue;
        for (int candidate = 0; candidate < events.Num(); ++candidate) {
            if (idStr::Icmp(events[candidate].name.c_str(),
                    events[fired].fire.c_str()) == 0)
                events[candidate].triggered = true;
        }
    }
}

int GameLib_GetFXDeclActionCount(const idDeclFX* declaration) {
    return declaration != nullptr ? declaration->events.Num() : 0;
}

int GameLib_GetFXDeclChangeId(const idDeclFX* declaration) {
    return declaration != nullptr ? declaration->changeId : -1;
}

const char* GameLib_GetFXDeclName(const idDeclFX* declaration) {
    return declaration != nullptr ? declaration->GetName() : "";
}

bool GameLib_GetFXActionParameters(const idDeclFX* declaration,
        int actionIndex, idFXActionParameters& parameters) {
    if (declaration == nullptr || actionIndex < 0
        || actionIndex >= declaration->events.Num()) return false;
    const idFXSingleAction& action = declaration->events[actionIndex];
    parameters.type = action.type;
    parameters.startCondition = action.startCondition.Num() > 0
        ? action.startCondition[0] : FX_NONE;
    parameters.stopCondition = action.stopCondition.Num() > 0
        ? action.stopCondition[0] : FX_NONE;
    parameters.extraCondition = action.extraCondition.Num() > 0
        ? action.extraCondition[0] : FX_EXTRA_COND_NONE;
    parameters.delay = action.delay;
    parameters.duration = action.duration;
    parameters.fadeInTime = action.fadeInTime;
    parameters.fadeOutTime = action.fadeOutTime;
    parameters.restart = action.restart ? 1.0f : 0.0f;
    parameters.looping = action.looping;
    parameters.triggered = action.triggered;
    parameters.trackOrigin = action.originType == FX_ORG_TRACK_POS
        || action.originType == FX_ORG_TRACK_LOCAL_POS;
    parameters.bindOrigin = action.originType == FX_ORG_TRACK_LOCAL_POS;
    parameters.bindAxis = action.rotationType == FX_ROT_TRACK_LOCAL_AXIS;
    parameters.randomRotationX = action.rndRotX;
    parameters.randomRotationY = action.rndRotY;
    parameters.randomRotationZ = action.rndRotZ;
    parameters.particleDecl = action.particleParms.declPrt;
    parameters.modelName = action.modelParms.modelName;
    parameters.sound = action.soundParms.sound;
    parameters.soundChannel = action.soundParms.channel;
    return true;
}
