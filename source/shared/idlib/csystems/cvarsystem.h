#pragma once

#include "autocomplete.h"
#include "../callback.h"
#include "../containers/hashindex.h"
#include "../containers/list.h"
#include "../filesystem/file.h"
#include "../text/str.h"

enum cvarFlags_t : int {
    CVAR_BOOL = 0x00000001,
    CVAR_INTEGER = 0x00000002,
    CVAR_FLOAT = 0x00000004,
    CVAR_CHEAT = 0x00000008,
    CVAR_NOCHEAT = 0x00000010,
    CVAR_INIT = 0x00004000,
    CVAR_ROM = 0x00008000,
    CVAR_ARCHIVE = 0x00010000,
    CVAR_MODIFIED = 0x00020000,
    CVAR_MODIFIED2 = 0x00040000
};

class idCVar {
public:
    using valueCompletion_t = void (*)(idAutoComplete& completion);

    struct cvarCallback_t {
        idCallback* callback;
        cvarCallback_t* next;
    };

    idCVar(const char* name, const char* value, int flags,
        const char* description, valueCompletion_t completion = nullptr);
    idCVar(const char* name, const char* value, int flags,
        const char* description, float valueMin, float valueMax,
        valueCompletion_t completion = nullptr);
    idCVar(const char* name, const char* value, int flags,
        const char* description, const char** valueStrings,
        valueCompletion_t completion = nullptr);

    const char* GetName() const { return name; }
    const char* GetString() const { return valueString.c_str(); }
    bool GetBool() const { return valueInteger != 0; }
    int GetInteger() const { return valueInteger; }
    float GetFloat() const { return valueFloat; }
    const char* GetDescription() const { return description; }
    int GetFlags() const { return flags; }
    float GetMinValue() const { return valueMin; }
    float GetMaxValue() const { return valueMax; }
    const char** GetValueStrings() const { return valueStrings; }
    valueCompletion_t GetValueCompletion() const { return valueCompletion; }

    void Reset();
    bool Set(const char* newValue, bool force = false);
    void SetString(const char* newValue, bool force = false);
    void SetBool(bool newValue, bool force = false);
    void SetInteger(int newValue, bool force = false);
    void SetFloat(float newValue, bool force = false);
    static void RegisterStaticVars();

    idStr valueString;
    int valueInteger;
    float valueFloat;
    const char* name;
    const char* resetString;
    const char* description;
    int flags;
    float valueMin;
    float valueMax;
    const char** valueStrings;
    valueCompletion_t valueCompletion;
    cvarCallback_t* onChange;
    idCVar* next;

protected:
    void Init(const char* name, const char* value, int flags,
        const char* description, float valueMin, float valueMax,
        const char** valueStrings, valueCompletion_t completion);
    void UpdateValue();
};

class idCVarSystem {
public:
    virtual ~idCVarSystem();
    virtual int NumCVars() const = 0;
    virtual const idCVar* FindByIndex(int index) const = 0;
    virtual idCVar* Find(const char* name) const = 0;
    virtual bool CvarExists(const char* name,
        bool searchForCvarString) const = 0;
    virtual void FindCvarsByPrefix(const char* prefix,
        idList<idCVar*>& cvars) const = 0;
    virtual void SetCVarString(const char* name, const char* value,
        int flags = 0) = 0;
    virtual void SetCVarBool(const char* name, bool value, int flags = 0) = 0;
    virtual void SetCVarInteger(const char* name, int value,
        int flags = 0) = 0;
    virtual void SetCVarFloat(const char* name, float value,
        int flags = 0) = 0;
    virtual const char* GetCVarString(const char* name,
        const char* defaultValue = "") const = 0;
    virtual bool GetCVarBool(const char* name, bool defaultValue = false) const = 0;
    virtual int GetCVarInteger(const char* name, int defaultValue = 0) const = 0;
    virtual float GetCVarFloat(const char* name,
        float defaultValue = 0.0f) const = 0;
    virtual bool Command(const idCmdArgs& args) = 0;
    virtual void CommandCompletion(idAutoComplete& completion) = 0;
    virtual void SetModifiedFlags(int flags) = 0;
    virtual int GetModifiedFlags() const = 0;
    virtual void ClearModifiedFlags(int flags) = 0;
    virtual void ResetFlaggedVariables(int flags) = 0;
    virtual void WriteFlaggedVariables(int flags, idFile* file) const = 0;
    virtual void ReportModifiedCVars() = 0;
    virtual void ClearModifiedCVars() = 0;
};

class idCVarSystemLocal : public idCVarSystem {
public:
    idCVarSystemLocal();
    ~idCVarSystemLocal() override;

    int NumCVars() const override { return cvars.Num(); }
    const idCVar* FindByIndex(int index) const override { return cvars[index]; }
    idCVar* Find(const char* name) const override;
    bool CvarExists(const char* name,
        bool searchForCvarString) const override;
    void FindCvarsByPrefix(const char* prefix,
        idList<idCVar*>& found) const override;
    void SetCVarString(const char* name, const char* value,
        int flags) override;
    void SetCVarBool(const char* name, bool value, int flags) override;
    void SetCVarInteger(const char* name, int value, int flags) override;
    void SetCVarFloat(const char* name, float value, int flags) override;
    const char* GetCVarString(const char* name,
        const char* defaultValue) const override;
    bool GetCVarBool(const char* name, bool defaultValue) const override;
    int GetCVarInteger(const char* name, int defaultValue) const override;
    float GetCVarFloat(const char* name, float defaultValue) const override;
    bool Command(const idCmdArgs& args) override;
    void CommandCompletion(idAutoComplete& completion) override;
    void SetModifiedFlags(int flags) override;
    int GetModifiedFlags() const override { return modifiedFlags; }
    void ClearModifiedFlags(int flags) override;
    void ResetFlaggedVariables(int flags) override;
    void WriteFlaggedVariables(int flags, idFile* file) const override;
    void ReportModifiedCVars() override;
    void ClearModifiedCVars() override;

    static void ListCvars(const idCmdArgs& args);

    idList<idCVar*, TAG_CVAR> cvars;
    idHashIndex cvarHash;
    int modifiedFlags;
};

extern idCVarSystem* cvarSystem;

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idCVar::cvarCallback_t) == 8,
    "Recovered idCVar callback ABI changed");
static_assert(sizeof(idCVar) == 80, "Recovered idCVar ABI changed");
static_assert(sizeof(idCVarSystem) == 4,
    "Recovered idCVarSystem ABI changed");
static_assert(sizeof(idCVarSystemLocal) == 56,
    "Recovered idCVarSystemLocal ABI changed");
#endif
