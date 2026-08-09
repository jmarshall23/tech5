#include "commandlink.h"

namespace {
idCommandLink* commandLinks = nullptr;
}

idCommandLink* CommandLinks() {
    return commandLinks;
}

idCommandLink::idCommandLink(const char* commandName,
        commandLinkFunction_t function, const char* description,
        commandLinkCompletion_t argumentCompletion)
    : next(commandLinks), cmdName_(commandName), function_(function),
      description_(description), argCompletion_(argumentCompletion) {
    commandLinks = this;
}
