#include "game/decls/declchapter.h"

#include <array>
#include <cstring>
#include <sstream>

namespace {

class MissingChapterServices final : public idDeclChapterServices {
public:
    const char* GetCurrentMapName() const override { return ""; }
    bool IsLayerActive(const char*) const override { return false; }
    void Warning(const std::string&) override {}
};

MissingChapterServices missingServices;
idDeclChapterServices* chapterServices = &missingServices;

bool HasAllActiveLayers(const idList<idAtomicString, 5>& layers) {
    for (int index = 0; index < layers.Num(); ++index) {
        if (!Tungsten_DeclChapterServices().IsLayerActive(
                layers[index].c_str())) {
            return false;
        }
    }
    return true;
}

template<typename declarationType>
void LoadAllSources(idDeclInfoTemplate<declarationType>& resourceList) {
    for (int index = 0; index < resourceList.declSources.Num(); ++index) {
        const idDeclSource* source = resourceList.declSources[index];
        if (source != nullptr && source->name.c_str() != nullptr) {
            resourceList.FindWithInheritance(source->name.c_str(), false);
        }
    }
}

} // namespace

void Tungsten_SetDeclChapterServices(idDeclChapterServices* services) {
    chapterServices = services != nullptr ? services : &missingServices;
}

idDeclChapterServices& Tungsten_DeclChapterServices() {
    return *chapterServices;
}

idDeclChapter::idDeclChapter()
    : sortId(0)
    , displayName()
    , lockedName()
    , type(CHAPTERTYPE_CAMPAIGN)
    , offset(0.0f, 0.0f)
    , sideMap()
    , variations() {
}

idDeclChapter::~idDeclChapter() = default;

idDeclSecrets::idDeclSecrets()
    : id(-1)
    , map()
    , layers()
    , secrets() {
}

idDeclSecrets::~idDeclSecrets() = default;

// EA 0x82BBCDF8
const idChapterVariation* idDeclChapter::FindVariationById(int id) {
    for (int chapterIndex = 0; chapterIndex < resourceList.num;
            ++chapterIndex) {
        const auto* chapter = static_cast<const idDeclChapter*>(
            resourceList.Index(chapterIndex));
        if (chapter == nullptr) continue;
        for (int variationIndex = 0;
                variationIndex < chapter->variations.Num();
                ++variationIndex) {
            if (chapter->variations[variationIndex].id == id) {
                return &chapter->variations[variationIndex];
            }
        }
    }
    return nullptr;
}

// EA 0x82BBCE98
bool idDeclChapter::FindCurrentEntry(int* chapterIndex,
        int* variationIndex, int* partIndex) {
    if (chapterIndex == nullptr || variationIndex == nullptr
            || partIndex == nullptr) {
        return false;
    }
    const char* currentMap = Tungsten_DeclChapterServices().GetCurrentMapName();
    for (int chapter = 0; chapter < resourceList.num; ++chapter) {
        const auto* declaration = static_cast<const idDeclChapter*>(
            resourceList.Index(chapter));
        if (declaration == nullptr) continue;
        for (int variation = 0;
                variation < declaration->variations.Num(); ++variation) {
            const idChapterVariation& variationData =
                declaration->variations[variation];
            for (int part = 0; part < variationData.parts.Num(); ++part) {
                const idChapterPart& partData = variationData.parts[part];
                if (std::strcmp(partData.mapName.c_str(), currentMap) == 0
                        && HasAllActiveLayers(partData.layers)) {
                    *chapterIndex = chapter;
                    *variationIndex = variation;
                    *partIndex = part;
                    return true;
                }
            }
        }
    }
    return false;
}

// EA 0x82BBD020
const idChapterVariation* idDeclChapter::FindCurrentVariation() {
    int chapter = 0;
    int variation = 0;
    int part = 0;
    if (!FindCurrentEntry(&chapter, &variation, &part)) return nullptr;
    const auto* declaration = static_cast<const idDeclChapter*>(
        resourceList.Index(chapter));
    return declaration != nullptr
        ? &declaration->variations[variation] : nullptr;
}

// EA 0x82BBD090
int idDeclSecrets::FindSecretForEntity(const char* name) {
    if (name == nullptr) return -1;
    idDeclChapterServices& services = Tungsten_DeclChapterServices();
    for (int declarationIndex = 0;
            declarationIndex < resourceList.num; ++declarationIndex) {
        const auto* declaration = static_cast<const idDeclSecrets*>(
            resourceList.Index(declarationIndex));
        if (declaration == nullptr
                || std::strcmp(declaration->map.c_str(),
                    services.GetCurrentMapName()) != 0
                || !HasAllActiveLayers(declaration->layers)) {
            continue;
        }
        for (int secretIndex = 0;
                secretIndex < declaration->secrets.Num(); ++secretIndex) {
            if (std::strcmp(declaration->secrets[secretIndex]
                    .entityName.c_str(), name) == 0) {
                return declaration->secrets[secretIndex].id;
            }
        }
    }
    return -1;
}

// EA 0x82BBD1F8
void idChapterPart::GetLayersParsed(idStr& result) const {
    result.Clear();
    for (int index = 0; index < layers.Num(); ++index) {
        if (index != 0) result.Append(",");
        result.Append(layers[index].c_str());
    }
}

// EA 0x82BBD2F8
void idDeclChapter::LoadAllDecls() {
    std::array<bool, 256> usedIds{};
    LoadAllSources(resourceList);
    for (int chapterIndex = 0; chapterIndex < resourceList.num;
            ++chapterIndex) {
        const auto* chapter = static_cast<const idDeclChapter*>(
            resourceList.Index(chapterIndex));
        if (chapter == nullptr) continue;
        for (int variationIndex = 0;
                variationIndex < chapter->variations.Num();
                ++variationIndex) {
            const int id = chapter->variations[variationIndex].id;
            if (id < 0 || id >= static_cast<int>(usedIds.size())) {
                std::ostringstream warning;
                warning << "Variation " << variationIndex << " in chapter '"
                    << chapter->GetName() << "' has invalid id " << id;
                Tungsten_DeclChapterServices().Warning(warning.str());
            } else if (usedIds[static_cast<std::size_t>(id)]) {
                Tungsten_DeclChapterServices().Warning(
                    "Several variations use the same id number");
            } else {
                usedIds[static_cast<std::size_t>(id)] = true;
            }
        }
    }
}

// EA 0x82BBD418
void idDeclSecretType::LoadAllDecls() {
    LoadAllSources(resourceList);
}

// EA 0x82BBD478
void idDeclSecrets::LoadAllDecls() {
    std::array<bool, 2048> usedIds{};
    LoadAllSources(resourceList);
    for (int declarationIndex = 0;
            declarationIndex < resourceList.num; ++declarationIndex) {
        const auto* declaration = static_cast<const idDeclSecrets*>(
            resourceList.Index(declarationIndex));
        if (declaration == nullptr) continue;
        for (int secretIndex = 0;
                secretIndex < declaration->secrets.Num(); ++secretIndex) {
            const int id = declaration->secrets[secretIndex].id;
            if (id < 0 || id >= static_cast<int>(usedIds.size())) {
                Tungsten_DeclChapterServices().Warning(
                    "Secret declaration has an invalid id");
            } else if (usedIds[static_cast<std::size_t>(id)]) {
                Tungsten_DeclChapterServices().Warning(
                    "Several secrets use the same id number");
            } else {
                usedIds[static_cast<std::size_t>(id)] = true;
            }
        }
    }
}

