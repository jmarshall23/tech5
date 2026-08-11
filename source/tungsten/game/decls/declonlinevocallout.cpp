#include "game/decls/declonlinevocallout.h"

idDeclInfoTemplate<idDeclOnlineVOCallout>
    idDeclOnlineVOCallout::resourceList(
        "onlineVOCallout", "idDeclOnlineVOCallout", "tdef");

// EA 0x82BCA870
idDeclOnlineVOCallout::idDeclOnlineVOCallout()
    : parms()
    , takenLead(nullptr)
    , tiedLead(nullptr)
    , lostLead(nullptr)
    , impressive(nullptr)
    , doubleKill(nullptr)
    , tripleKill(nullptr)
    , quadKill(nullptr)
    , slaughter(nullptr)
    , revenge(nullptr)
    , airMail(nullptr)
    , pull(nullptr)
    , afterLife(nullptr)
    , maxChain(nullptr)
    , chainBreaker(nullptr)
    , denial(nullptr)
    , closeCall(nullptr)
    , airRally(nullptr) {
    parms.Clear();
}
