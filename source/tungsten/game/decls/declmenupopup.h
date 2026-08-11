#pragma once

#include "decls/decltypeinfo.h"
#include "idlib/containers/list.h"
#include "idlib/langdict.h"
#include "idlib/text/str.h"

class idDeclMenuPopup : public idDeclTypeInfo {
public:
    idDeclMenuPopup();
    ~idDeclMenuPopup() override;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    const char* GetScriptName() const;
    static void LoadAllDecls();

    idStr fileName;

    static idDeclInfoTemplate<idDeclMenuPopup> resourceList;
};

class idDeclCredits : public idDeclTypeInfo {
public:
    enum creditEntry_t : int {
        CREDIT_SPACER = -1,
        CREDIT_HEADING = 0,
        CREDIT_SUBHEADING = 1,
        CREDIT_SINGLE = 2,
        CREDIT_DOUBLE = 3,
        CREDIT_IMAGE = 4
    };

    struct creditInfo_t {
        creditEntry_t entryType;
        idStrId localizedStr;
        idStr entry0;
        idStr entry1;

        creditInfo_t()
            : entryType(CREDIT_SPACER)
            , localizedStr()
            , entry0()
            , entry1() {
        }
    };

    idDeclCredits();
    ~idDeclCredits() override;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    creditEntry_t GetCreditType(int index) const;
    idStr GetCreditEntry(int index, int entry) const;

    idList<creditInfo_t, 5> creditList;

    static idDeclInfoTemplate<idDeclCredits> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclMenuPopup) == 96,
    "Recovered menu-popup declaration ABI changed");
static_assert(sizeof(idDeclCredits::creditInfo_t) == 72,
    "Recovered credit-entry ABI changed");
static_assert(sizeof(idDeclCredits) == 80,
    "Recovered credits declaration ABI changed");
#endif
