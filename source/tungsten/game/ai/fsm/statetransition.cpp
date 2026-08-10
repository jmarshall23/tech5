#include "statetransition.h"

#include <string>

// Retail symbol: ??0idStateTransition@@QAA@H@Z
// EA: 0x82AF80C8, RVA: 0x00AF80C8
idStateTransition::idStateTransition(const int transitionFlags)
    : flags(transitionFlags) {
}

// Retail symbol:
// ?Save@idStateTransition@@UBAXAAVidFile_String@@PBDABV?$idList@UtransDest_t@idStateTransition@@$04@@@Z
// EA: 0x82AF80E0, RVA: 0x00AF80E0
void idStateTransition::Save(
        idFile_String& file,
        const char* const indent,
        const idList<transDest_t, 5>& destinations) {
    const char* const safeIndent = indent != nullptr ? indent : "";
    const char* const className = Tungsten_GetStateTransitionClassname(this);
    const std::string opening = std::string(safeIndent) + "transition \""
        + (className != nullptr ? className : "") + "\" {\n";
    Tungsten_AppendStateTransitionText(file, opening.c_str());
    InternalSave(file, safeIndent, destinations);
    const std::string closing = std::string(safeIndent) + "}\n";
    Tungsten_AppendStateTransitionText(file, closing.c_str());
}
