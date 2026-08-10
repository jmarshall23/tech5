#pragma once

#include "decls/declaccolades.h"

class idLocalUser;

class idAccolade {
public:
    idAccolade(const idDeclAccolade& declaration, int count);

    const char* Icon() const;
    const char* Name() const;
    const char* Description() const;

    int count;
    const idDeclAccolade* decl;
};

class idAccolades {
public:
    static int Num();
    static idAccolade GetLifetime(idLocalUser& user, int index);
    static idAccolade GetSession(int playerId, int index);
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAccolade) == 8,
    "Recovered accolade result ABI changed");
#endif
