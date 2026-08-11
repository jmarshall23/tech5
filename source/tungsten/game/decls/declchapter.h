#pragma once

#include "decls/decltypeinfo.h"
#include "idlib/langdict.h"
#include "idlib/math/vector.h"

#include <string>

struct idChapterPart {
    void GetLayersParsed(idStr& result) const;

    idList<idAtomicString, 5> layers;
    idAtomicString mapName;
};

struct idChapterVariation {
    int id{0};
    int reserved{0};
    idList<idChapterPart, 5> parts;
};

class idDeclChapterServices {
public:
    virtual ~idDeclChapterServices() = default;
    virtual const char* GetCurrentMapName() const = 0;
    virtual bool IsLayerActive(const char* layerName) const = 0;
    virtual void Warning(const std::string& message) = 0;
};

void Tungsten_SetDeclChapterServices(idDeclChapterServices* services);
idDeclChapterServices& Tungsten_DeclChapterServices();

class idDeclChapter : public idDeclTypeInfo {
public:
    enum chapterType_t : int {
        CHAPTERTYPE_CAMPAIGN = 0,
        CHAPTERTYPE_SIDEMISSION = 1,
        MAX_TYPES = 2
    };

    idDeclChapter();
    ~idDeclChapter() override;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    static const idChapterVariation* FindVariationById(int id);
    static bool FindCurrentEntry(int* chapterIndex, int* variationIndex,
        int* partIndex);
    static const idChapterVariation* FindCurrentVariation();
    static void LoadAllDecls();

    int sortId;
    idStrId displayName;
    idStrId lockedName;
    chapterType_t type;
    idVec2 offset;
    idStr sideMap;
    idList<idChapterVariation, 5> variations;

    static idDeclInfoTemplate<idDeclChapter> resourceList;
};

class idDeclSecretType : public idDeclTypeInfo {
public:
    enum bonus_t : int {
        BONUS_NONE = 0,
        BONUS_MAX
    };

    idDeclSecretType() : sortId(0), bonus(BONUS_NONE) {}
    ~idDeclSecretType() override = default;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    static void LoadAllDecls();

    int sortId;
    bonus_t bonus;
    static idDeclInfoTemplate<idDeclSecretType> resourceList;
};

struct idSecretEntry {
    int id{0};
    const idDeclSecretType* type{nullptr};
    idAtomicString entityName;
};

class idDeclSecrets : public idDeclTypeInfo {
public:
    idDeclSecrets();
    ~idDeclSecrets() override;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    static int FindSecretForEntity(const char* name);
    static void LoadAllDecls();

    int id;
    idAtomicString map;
    idList<idAtomicString, 5> layers;
    idList<idSecretEntry, 5> secrets;
    static idDeclInfoTemplate<idDeclSecrets> resourceList;
};

