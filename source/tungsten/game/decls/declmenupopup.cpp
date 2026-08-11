#include "game/decls/declmenupopup.h"

idDeclInfoTemplate<idDeclMenuPopup> idDeclMenuPopup::resourceList(
    "menuPopup", "idDeclMenuPopup", "tdef");
idDeclInfoTemplate<idDeclCredits> idDeclCredits::resourceList(
    "credits", "idDeclCredits", "tdef");

// EA 0x82BC8628
idDeclMenuPopup::idDeclMenuPopup()
    : fileName() {
}

// EA 0x82BC86A0
idDeclMenuPopup::~idDeclMenuPopup() = default;

// EA 0x82BC87B0
const char* idDeclMenuPopup::GetScriptName() const {
    // The Xbox routine returned the buffer of a destroyed local idStr. Keep
    // the recovered uppercase behavior while giving the Win32 port a stable
    // result for the caller's immediate script-global registration.
    static idStr scriptName;
    scriptName = GetName();
    scriptName.ToUpper();
    return scriptName.c_str();
}

// EA 0x82BC88A0
void idDeclMenuPopup::LoadAllDecls() {
    for (int sourceIndex = 0;
            sourceIndex < resourceList.declSources.Num(); ++sourceIndex) {
        const idDeclSource* source = resourceList.declSources[sourceIndex];
        if (source != nullptr && source->name.c_str() != nullptr) {
            resourceList.FindWithInheritance(source->name.c_str(), false);
        }
    }
}

// EA 0x82BD5C98
idDeclCredits::idDeclCredits()
    : creditList() {
}

// EA 0x82BD5D48
idDeclCredits::~idDeclCredits() = default;

// EA 0x82BC8780
idDeclCredits::creditEntry_t idDeclCredits::GetCreditType(
        const int index) const {
    if (index >= creditList.Num()) {
        return CREDIT_SPACER;
    }
    return creditList[index].entryType;
}

// EA 0x82BC8800
idStr idDeclCredits::GetCreditEntry(const int index, const int entry) const {
    if (index >= creditList.Num()) {
        return idStr("");
    }

    const creditInfo_t& credit = creditList[index];
    if (credit.localizedStr.IsValid()) {
        return idStr(credit.localizedStr.GetLocalizedString());
    }
    return entry != 0 ? credit.entry1 : credit.entry0;
}
