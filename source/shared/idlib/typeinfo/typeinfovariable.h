#pragma once

#include <cstdint>

class idTypeInfoVariable {
public:
    idTypeInfoVariable(const char* typeName = "", const char* typeOps = "",
            const char* variablePath = "")
        : type(typeName), ops(typeOps), path(variablePath) {}

    const char* type;
    const char* ops;
    const char* path;
};

class idTypeInfoVariableTemplate : public idTypeInfoVariable {
public:
    idTypeInfoVariableTemplate(const char* typeName = "",
            const char* typeOps = "", const char* variablePath = "",
            const char* argumentType = "", const char* argumentOps = "")
        : idTypeInfoVariable(typeName, typeOps, variablePath),
          argType(argumentType), argOps(argumentOps) {}

    const char* argType;
    const char* argOps;
};

#define IDTECH5_TYPEINFO_VARIABLE(name) \
    class idTypeInfoVariable_##name : public idTypeInfoVariable { \
    public: \
        using idTypeInfoVariable::idTypeInfoVariable; \
    }

IDTECH5_TYPEINFO_VARIABLE(bool);
IDTECH5_TYPEINFO_VARIABLE(int);
IDTECH5_TYPEINFO_VARIABLE(float);
IDTECH5_TYPEINFO_VARIABLE(StrPtr);
IDTECH5_TYPEINFO_VARIABLE(enum);
IDTECH5_TYPEINFO_VARIABLE(idStr);
IDTECH5_TYPEINFO_VARIABLE(idMat2);
IDTECH5_TYPEINFO_VARIABLE(idMat3);
IDTECH5_TYPEINFO_VARIABLE(idAngles);
IDTECH5_TYPEINFO_VARIABLE(idVec4);
IDTECH5_TYPEINFO_VARIABLE(unsigned_char);
IDTECH5_TYPEINFO_VARIABLE(wchar_t);
IDTECH5_TYPEINFO_VARIABLE(idBounds);
IDTECH5_TYPEINFO_VARIABLE(short);
IDTECH5_TYPEINFO_VARIABLE(idVec3);
IDTECH5_TYPEINFO_VARIABLE(char);
IDTECH5_TYPEINFO_VARIABLE(idVecX);
IDTECH5_TYPEINFO_VARIABLE(idMat4);
IDTECH5_TYPEINFO_VARIABLE(idEntityPtr);
IDTECH5_TYPEINFO_VARIABLE(unsigned_int);
IDTECH5_TYPEINFO_VARIABLE(idColor);
IDTECH5_TYPEINFO_VARIABLE(double);
IDTECH5_TYPEINFO_VARIABLE(long);
IDTECH5_TYPEINFO_VARIABLE(unsigned_long);
IDTECH5_TYPEINFO_VARIABLE(idVec2);
IDTECH5_TYPEINFO_VARIABLE(idMatX);

#undef IDTECH5_TYPEINFO_VARIABLE

class idTypeInfoVariable_idList : public idTypeInfoVariableTemplate {
public:
    using idTypeInfoVariableTemplate::idTypeInfoVariableTemplate;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idTypeInfoVariable) == 12,
    "Recovered idTypeInfoVariable ABI changed");
static_assert(sizeof(idTypeInfoVariableTemplate) == 20,
    "Recovered template variable ABI changed");
#endif
