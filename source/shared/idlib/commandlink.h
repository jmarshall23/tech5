#pragma once

#include "csystems/autocomplete.h"

using commandLinkFunction_t = void (*)(const idCmdArgs& args);
using commandLinkCompletion_t = void (*)(idAutoComplete& completion);

class idCommandLink {
public:
    idCommandLink(const char* commandName, commandLinkFunction_t function,
        const char* description,
        commandLinkCompletion_t argumentCompletion = nullptr);

    idCommandLink* next;
    const char* cmdName_;
    commandLinkFunction_t function_;
    const char* description_;
    commandLinkCompletion_t argCompletion_;
};

idCommandLink* CommandLinks();

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idCommandLink) == 20,
    "Recovered idCommandLink layout changed");
#endif
