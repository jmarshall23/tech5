#include "models/skeletalanimation/declmd6.h"
#include "models/skeletalanimation/md6anim.h"

#include <algorithm>

idDeclInfoTemplate<idDeclMD6> idDeclMD6::resourceList(
    "md6Def", "idDeclMD6", "md6def");

idDeclMD6::idDeclMD6()
    : config(new idMD6Blend::configInfo_t{}), model(nullptr),
      parentDecl(nullptr), numLoadErrors(0), curAliasHandle(0),
      morphVertices(nullptr), calcRefBoundsFromJoints(false),
      attachmentOverrideScale(-1.0f), modelCaps(0),
      userChannelWeightGroupOverride(0) {
    referenceBounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    referenceBounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    for (idStr& meshKit : meshKitDefault) meshKit = "";
    idEyeInfo defaultEye;
    defaultEye.name = "default";
    eyeInfoCollection.AddEyeInfo(defaultEye);
}

idDeclMD6::~idDeclMD6() {
    FreeData();
    delete config;
    config = nullptr;
}

unsigned int idDeclMD6::GetDeclTimestamp() const {
    return 0;
}

idDeclInfo* idDeclMD6::GetDeclInfo() const {
    return &resourceList;
}

bool idDeclMD6::RebuildTextSource() {
    return false;
}

const char* idDeclMD6::DefaultDefinition() const {
    return "{\n"
        "\tinit {\n"
        "\tmesh \"md6/default.md6mesh\"\n"
        "\t}\n"
        "\tuserProps {\n\t}\n"
        "\tjointGroups {\n\t}\n"
        "\tevents {\n\t}\n"
        "\taliases {\n\t}\n"
        "\tprops {\n\tprop \"_info\" {\n\t\t}\n\t}\n"
        "\teyeInfoCollection 0 {\n\t}\n"
        "}\n";
}

void idDeclMD6::LogMissingDecl() const {
}

void idDeclMD6::Parse(idParser*) {
    // Text parsing depends on the declaration registry and animation manager;
    // their adapters are recovered outside the models module.
}

void idDeclMD6::FreeData() {
    model = nullptr;
    parent = "";
    parentDecl = nullptr;
    declsToIncludeAnimDataFrom.ClearFree();
    numLoadErrors = 0;
    jointGroupCollection.Free();
    props.Free();
    animEvents.Free();
    eyeInfoCollection.Free();
    userProps.ClearFree();
    aliases.ClearFree();
    aliasHash.Clear();
    curAliasHandle = 0;
    headTrackGroups.ClearFree();
    for (int index = 0; index < 3; ++index) {
        meshKitGroups[index].ClearFree();
        meshKitDefault[index] = "";
    }
    morphVertices = nullptr;
    morphDefList.ClearFree();
    calcRefBoundsFromJoints = false;
    wrinkleMapRegionExpressions.ClearFree();
    attachmentOverrideScale = -1.0f;
    modelCaps = 0;
    userChannelWeightGroupOverride = 0;
    baseUserChannelAlias.Invalidate();
    userChannelToAnimationAliasMap.ClearFree();
    userChannelToAnimationAliasOverrides.ClearFree();
}

unsigned int idDeclMD6::Size() const {
    unsigned int total = sizeof(*this);
    total += declsToIncludeAnimDataFrom.MemoryUsed();
    total += jointGroupCollection.jointGroups.MemoryUsed();
    total += props.props.MemoryUsed();
    total += animEvents.list.MemoryUsed();
    total += eyeInfoCollection.eyeInfos.MemoryUsed();
    total += userProps.MemoryUsed() + aliases.MemoryUsed();
    total += headTrackGroups.MemoryUsed();
    total += morphDefList.MemoryUsed();
    total += wrinkleMapRegionExpressions.MemoryUsed();
    total += userChannelToAnimationAliasMap.MemoryUsed();
    total += userChannelToAnimationAliasOverrides.MemoryUsed();
    for (const auto& groups : meshKitGroups) total += groups.MemoryUsed();
    return total;
}

void idDeclMD6::Write(idFile_String*, const char*) const {
}

namespace {

void MergeAnimEvents(
        const idStaticList<const idMD6AnimEvent*, 16>& incoming,
        idStaticList<const idMD6AnimEvent*, 16>& result) {
    for (int sourceIndex = 0; sourceIndex < incoming.Num(); ++sourceIndex) {
        const idMD6AnimEvent* event = incoming[sourceIndex];
        int destination = 0;
        while (destination < result.Num()) {
            const idMD6AnimEvent* current = result[destination];
            if (event->frameNum == current->frameNum &&
                event->row == current->row) {
                event = nullptr; // The nearer declaration overrides this row.
                break;
            }
            if (event->frameNum < current->frameNum ||
                (event->frameNum == current->frameNum &&
                 event->row < current->row)) {
                break;
            }
            ++destination;
        }
        if (event != nullptr && result.Num() < result.Max())
            result.Insert(event, destination);
    }
}

template<typename Finder>
bool FindInheritedAnimEvents(const idDeclMD6& declaration,
        Finder&& finder,
        idStaticList<const idMD6AnimEvent*, 16>& events) {
    events.Clear();
    finder(declaration.animEvents, events);

    idStaticList<const idMD6AnimEvent*, 16> inherited;
    for (const idDeclMD6* current = declaration.parentDecl;
         current != nullptr; current = current->parentDecl) {
        inherited.Clear();
        finder(current->animEvents, inherited);
        MergeAnimEvents(inherited, events);
    }
    for (int includeIndex = 0;
         includeIndex < declaration.declsToIncludeAnimDataFrom.Num();
         ++includeIndex) {
        for (const idDeclMD6* current = declaration
                 .declsToIncludeAnimDataFrom[includeIndex].includeDecl;
             current != nullptr; current = current->parentDecl) {
            inherited.Clear();
            finder(current->animEvents, inherited);
            MergeAnimEvents(inherited, events);
        }
    }
    return events.Num() != 0;
}

} // namespace

bool idDeclMD6::FindAnimEvents(const idMD6Anim* animation,
        const int startFrame, const int endFrame,
        idStaticList<const idMD6AnimEvent*, 16>& events) const {
    if (animation == nullptr) {
        events.Clear();
        return false;
    }
    const idAtomicStringT<md6AnimAtomicString_t> reference(
        animation->GetName());
    return FindInheritedAnimEvents(*this,
        [&](const idAnimEvents& source,
            idStaticList<const idMD6AnimEvent*, 16>& destination) {
            source.FindAnimEvents(reference, startFrame, endFrame,
                destination);
        }, events);
}

bool idDeclMD6::FindAnimEvents(const idMD6Anim* animation,
        const int startFrame, const int endFrame, const int eventNum,
        idStaticList<const idMD6AnimEvent*, 16>& events) const {
    if (animation == nullptr) {
        events.Clear();
        return false;
    }
    const idAtomicStringT<md6AnimAtomicString_t> reference(
        animation->GetName());
    return FindInheritedAnimEvents(*this,
        [&](const idAnimEvents& source,
            idStaticList<const idMD6AnimEvent*, 16>& destination) {
            source.FindAnimEvents(reference, startFrame, endFrame,
                eventNum, destination);
        }, events);
}
