#pragma once

#include "../../../shared/idlib/containers/staticlist.h"
#include "../../../shared/idlib/text/str.h"

enum aiVarOp_t : int {
    AIVAROP_LESS = 0,
    AIVAROP_LESS_EQUAL = 1,
    AIVAROP_EQUAL = 2,
    AIVAROP_GREATER_EQUAL = 3,
    AIVAROP_GREATER = 4
};

class idAIVar {
public:
    idAIVar() = default;
    virtual ~idAIVar();

    virtual bool Compare(const idAIVar& other, aiVarOp_t op) const = 0;
    virtual bool Compare(const char* value, aiVarOp_t op) const = 0;
    virtual bool Compare(int value, aiVarOp_t op) const = 0;
    virtual bool Compare(float value, aiVarOp_t op) const = 0;
    virtual void Copy(const idAIVar& other);
    virtual void Set(const char* value) = 0;
    virtual void Set(int value) = 0;
    virtual void Set(float value) = 0;
    virtual int GetInt() const = 0;
    virtual float GetFloat() const = 0;
    virtual void GetString(idStr& out) const = 0;

    const char* GetName() const { return name.c_str(); }
    void SetName(const char* value) { name = value; }

protected:
    idStr name;
};

class idAIVar_String final : public idAIVar {
public:
    idAIVar_String();
    ~idAIVar_String() override;

    bool Compare(const idAIVar& other, aiVarOp_t op) const override;
    bool Compare(const char* value, aiVarOp_t op) const override;
    bool Compare(int value, aiVarOp_t op) const override;
    bool Compare(float value, aiVarOp_t op) const override;
    void Copy(const idAIVar& other) override;
    void Set(const char* value) override;
    void Set(int value) override;
    void Set(float value) override;
    int GetInt() const override;
    float GetFloat() const override;
    void GetString(idStr& out) const override;

private:
    idStr stringVal;
};

class idAIVar_Int final : public idAIVar {
public:
    idAIVar_Int();
    ~idAIVar_Int() override;

    bool Compare(const idAIVar& other, aiVarOp_t op) const override;
    bool Compare(const char* value, aiVarOp_t op) const override;
    bool Compare(int value, aiVarOp_t op) const override;
    bool Compare(float value, aiVarOp_t op) const override;
    void Copy(const idAIVar& other) override;
    void Set(const char* value) override;
    void Set(int value) override;
    void Set(float value) override;
    int GetInt() const override { return intVal; }
    float GetFloat() const override;
    void GetString(idStr& out) const override;

private:
    int intVal;
};

class idAIVar_Float final : public idAIVar {
public:
    idAIVar_Float();
    ~idAIVar_Float() override;

    bool Compare(const idAIVar& other, aiVarOp_t op) const override;
    bool Compare(const char* value, aiVarOp_t op) const override;
    bool Compare(int value, aiVarOp_t op) const override;
    bool Compare(float value, aiVarOp_t op) const override;
    void Copy(const idAIVar& other) override;
    void Set(const char* value) override;
    void Set(int value) override;
    void Set(float value) override;
    int GetInt() const override;
    float GetFloat() const override;
    void GetString(idStr& out) const override;

private:
    float floatVal;
};

class idAIBlackboard {
public:
    static constexpr int MAX_VARS_PER_TYPE = 8;

    enum varArray_t : int {
        VARRAY_NONE = 0,
        VARRAY_STRING = 1,
        VARRAY_INT = 2,
        VARRAY_FLOAT = 3
    };

    struct idVarInfo {
        varArray_t varArray;
        int index;
    };

    idAIBlackboard();
    ~idAIBlackboard();

    idAIVar* Find(const char* name) const;
    void Init();
    void Shutdown();
    idAIVar_Int* AllocInt(const char* name, int value);
    idAIVar_Float* AllocFloat(const char* name, float value);
    idAIVar_String* AllocString(const char* name, const char* value);

    int Num() const { return vars.Num(); }

private:
    idStaticList<idAIVar_String, MAX_VARS_PER_TYPE> stringVars;
    idStaticList<idAIVar_Float, MAX_VARS_PER_TYPE> floatVars;
    idStaticList<idAIVar_Int, MAX_VARS_PER_TYPE> intVars;
    idStaticList<idVarInfo, MAX_VARS_PER_TYPE * 3> vars;
};
