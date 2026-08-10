#include "aiblackboard.h"

#include <cstdlib>

void Tungsten_AIBlackboardWarning(const char* message, int maximum);

namespace {

template<typename valueType>
bool CompareValues(
        const valueType left, const valueType right, const aiVarOp_t op) {
    switch (op) {
    case AIVAROP_LESS: return left < right;
    case AIVAROP_LESS_EQUAL: return left <= right;
    case AIVAROP_EQUAL: return left == right;
    case AIVAROP_GREATER_EQUAL: return left >= right;
    case AIVAROP_GREATER: return left > right;
    default: return false;
    }
}

bool CompareStrings(
        const char* const left, const char* const right, const aiVarOp_t op) {
    const int comparison = idStr::Cmp(left, right);
    return CompareValues(comparison, 0, op);
}

} // namespace

// The virtual variable implementations are emitted from aiblackboard.h in the
// retail image. They live here in the reconstruction so the complete source
// behavior has one link owner.
idAIVar::~idAIVar() = default;

void idAIVar::Copy(const idAIVar& other) {
    if (this != &other) {
        name = other.name;
    }
}

idAIVar_String::idAIVar_String() = default;
idAIVar_String::~idAIVar_String() = default;

bool idAIVar_String::Compare(
        const idAIVar& other, const aiVarOp_t op) const {
    idStr value;
    other.GetString(value);
    return Compare(value.c_str(), op);
}

bool idAIVar_String::Compare(
        const char* const value, const aiVarOp_t op) const {
    return CompareStrings(stringVal.c_str(), value, op);
}

bool idAIVar_String::Compare(
        const int value, const aiVarOp_t op) const {
    idStr text;
    text.Format("%d", value);
    return Compare(text.c_str(), op);
}

bool idAIVar_String::Compare(
        const float value, const aiVarOp_t op) const {
    idStr text;
    text.Format("%g", value);
    return Compare(text.c_str(), op);
}

void idAIVar_String::Copy(const idAIVar& other) {
    if (this == &other) {
        return;
    }
    idAIVar::Copy(other);
    other.GetString(stringVal);
}

void idAIVar_String::Set(const char* const value) {
    stringVal = value;
}

void idAIVar_String::Set(const int value) {
    stringVal.Format("%d", value);
}

void idAIVar_String::Set(const float value) {
    stringVal.Format("%g", value);
}

int idAIVar_String::GetInt() const {
    return std::atoi(stringVal.c_str());
}

float idAIVar_String::GetFloat() const {
    return static_cast<float>(std::atof(stringVal.c_str()));
}

void idAIVar_String::GetString(idStr& out) const {
    out = stringVal;
}

idAIVar_Int::idAIVar_Int()
    : intVal(0) {
}

idAIVar_Int::~idAIVar_Int() = default;

bool idAIVar_Int::Compare(
        const idAIVar& other, const aiVarOp_t op) const {
    return Compare(other.GetInt(), op);
}

bool idAIVar_Int::Compare(
        const char* const value, const aiVarOp_t op) const {
    return Compare(value != nullptr ? std::atoi(value) : 0, op);
}

bool idAIVar_Int::Compare(const int value, const aiVarOp_t op) const {
    return CompareValues(intVal, value, op);
}

bool idAIVar_Int::Compare(const float value, const aiVarOp_t op) const {
    return Compare(static_cast<int>(value), op);
}

void idAIVar_Int::Copy(const idAIVar& other) {
    if (this != &other) {
        idAIVar::Copy(other);
        intVal = other.GetInt();
    }
}

void idAIVar_Int::Set(const char* const value) {
    intVal = value != nullptr ? std::atoi(value) : 0;
}

void idAIVar_Int::Set(const int value) {
    intVal = value;
}

void idAIVar_Int::Set(const float value) {
    intVal = static_cast<int>(value);
}

float idAIVar_Int::GetFloat() const {
    return static_cast<float>(intVal);
}

void idAIVar_Int::GetString(idStr& out) const {
    out.Format("%d", intVal);
}

idAIVar_Float::idAIVar_Float()
    : floatVal(0.0f) {
}

idAIVar_Float::~idAIVar_Float() = default;

bool idAIVar_Float::Compare(
        const idAIVar& other, const aiVarOp_t op) const {
    return Compare(other.GetFloat(), op);
}

bool idAIVar_Float::Compare(
        const char* const value, const aiVarOp_t op) const {
    return Compare(value != nullptr
        ? static_cast<float>(std::atof(value)) : 0.0f, op);
}

bool idAIVar_Float::Compare(const int value, const aiVarOp_t op) const {
    return Compare(static_cast<float>(value), op);
}

bool idAIVar_Float::Compare(const float value, const aiVarOp_t op) const {
    return CompareValues(floatVal, value, op);
}

void idAIVar_Float::Copy(const idAIVar& other) {
    if (this != &other) {
        idAIVar::Copy(other);
        floatVal = other.GetFloat();
    }
}

void idAIVar_Float::Set(const char* const value) {
    floatVal = value != nullptr
        ? static_cast<float>(std::atof(value)) : 0.0f;
}

void idAIVar_Float::Set(const int value) {
    floatVal = static_cast<float>(value);
}

void idAIVar_Float::Set(const float value) {
    floatVal = value;
}

int idAIVar_Float::GetInt() const {
    return static_cast<int>(floatVal);
}

float idAIVar_Float::GetFloat() const {
    return floatVal;
}

void idAIVar_Float::GetString(idStr& out) const {
    out.Format("%g", floatVal);
}

// Retail symbol: ?Find@idAIBlackboard@@QBAPAVidAIVar@@PBD@Z
// EA: 0x82A3F988, RVA: 0x00A3F988
idAIVar* idAIBlackboard::Find(const char* const variableName) const {
    for (int variable = 0; variable < vars.Num(); ++variable) {
        const idVarInfo& info = vars[variable];
        idAIVar* result = nullptr;
        switch (info.varArray) {
        case VARRAY_STRING:
            result = const_cast<idAIVar_String*>(&stringVars[info.index]);
            break;
        case VARRAY_INT:
            result = const_cast<idAIVar_Int*>(&intVars[info.index]);
            break;
        case VARRAY_FLOAT:
            result = const_cast<idAIVar_Float*>(&floatVars[info.index]);
            break;
        default:
            break;
        }
        if (result != nullptr
            && idStr::Icmp(variableName, result->GetName()) == 0) {
            return result;
        }
    }
    return nullptr;
}

// Retail symbol: ?Shutdown@idAIBlackboard@@QAAXXZ
// EA: 0x82A3FB30, RVA: 0x00A3FB30
void idAIBlackboard::Shutdown() {
    stringVars.Clear();
    floatVars.Clear();
    intVars.Clear();
    vars.Clear();
}

// Retail symbol: ??1idAIBlackboard@@QAA@XZ
// EA: 0x82A3FE50, RVA: 0x00A3FE50
idAIBlackboard::~idAIBlackboard() = default;

// Retail symbol: ?Init@idAIBlackboard@@QAAXXZ
// EA: 0x82A3FF28, RVA: 0x00A3FF28
void idAIBlackboard::Init() {
    Shutdown();
}

// Retail symbol: ??0idAIBlackboard@@QAA@XZ
// EA: 0x82A40160, RVA: 0x00A40160
idAIBlackboard::idAIBlackboard() = default;

// Retail symbol: ?AllocInt@idAIBlackboard@@QAAPAVidAIVar@@PBDH@Z
// EA: 0x82A40A18, RVA: 0x00A40A18
idAIVar_Int* idAIBlackboard::AllocInt(
        const char* const variableName, const int value) {
    if (intVars.Num() >= MAX_VARS_PER_TYPE) {
        Tungsten_AIBlackboardWarning(
            "Exceeded max number of AI blackboard integer variables",
            MAX_VARS_PER_TYPE);
        return nullptr;
    }
    idAIVar_Int* const result = intVars.Alloc();
    vars.Append({ VARRAY_INT, intVars.Num() - 1 });
    result->Set(value);
    result->SetName(variableName);
    return result;
}

// Retail symbol: ?AllocFloat@idAIBlackboard@@QAAPAVidAIVar@@PBDM@Z
// EA: 0x82A40AB8, RVA: 0x00A40AB8
idAIVar_Float* idAIBlackboard::AllocFloat(
        const char* const variableName, const float value) {
    if (floatVars.Num() >= MAX_VARS_PER_TYPE) {
        Tungsten_AIBlackboardWarning(
            "Exceeded max number of AI blackboard float variables",
            MAX_VARS_PER_TYPE);
        return nullptr;
    }
    idAIVar_Float* const result = floatVars.Alloc();
    vars.Append({ VARRAY_FLOAT, floatVars.Num() - 1 });
    result->Set(value);
    result->SetName(variableName);
    return result;
}

// Retail symbol: ?AllocString@idAIBlackboard@@QAAPAVidAIVar@@PBD0@Z
// EA: 0x82A40B68, RVA: 0x00A40B68
idAIVar_String* idAIBlackboard::AllocString(
        const char* const variableName, const char* const value) {
    if (stringVars.Num() >= MAX_VARS_PER_TYPE) {
        Tungsten_AIBlackboardWarning(
            "Exceeded max number of AI blackboard string variables",
            MAX_VARS_PER_TYPE);
        return nullptr;
    }
    idAIVar_String* const result = stringVars.Alloc();
    vars.Append({ VARRAY_STRING, stringVars.Num() - 1 });
    result->Set(value);
    result->SetName(variableName);
    return result;
}
