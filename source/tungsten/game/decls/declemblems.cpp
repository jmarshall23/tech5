#include "game/decls/declemblems.h"

idList<const idDeclEmblem*, 5> idDeclEmblem::orderedList;

// EA 0x82BBDBA0
idDeclEmblem::idDeclEmblem()
    : ordinal(0)
    , icon(nullptr)
    , requirements()
    , allEventsRequired(true)
    , category(EMBLEM_COOP)
    , unlockDescription()
    , index(-1) {
}

// EA 0x82BBDC60
idDeclEmblem::~idDeclEmblem() = default;

