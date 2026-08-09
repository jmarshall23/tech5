#pragma once

#include "idlib/containers/hierarchy.h"
#include "idlib/containers/list.h"

class idCmdArgs;
class idClass;

// Local type 13473 is unmapped in the generated header corpus but is the
// metadata record used by every idClass registration function.
class idTypeInfo {
public:
    using createInstance_t = idClass* (*)();
    using spawn_t = void (*)(idClass*);

    idTypeInfo(const char *classname, const char *superclass, int size,
        bool abstract, createInstance_t createInstance, spawn_t spawn);
    ~idTypeInfo();

    void Init();

    const char *classname;
    const char *superclass;
    createInstance_t CreateInstance;
    spawn_t Spawn;
    bool initialized;
    idTypeInfo *super;
    idTypeInfo *next;
    bool isAbstract;
    int size;
    int typeNum;
    int lastChild;
    idHierarchy<idTypeInfo> node;
};

// PDB local type 13472 plus the methods recovered from engine/gamelib/class.cpp.
class idClass {
public:
    virtual idTypeInfo *GetType() = 0;
    virtual ~idClass();

    const char *GetClassname() const;
    bool IsType(const idTypeInfo& superclass) const;
    void CallSpawn();

    static idTypeInfo *GetClass(const char *name);
    static idClass *CreateInstance(const char *name);
    static void Init();
    static void Shutdown();
    static void DisplayInfo_f(const idCmdArgs& args);
    static void ListClasses_f(const idCmdArgs& args);

    static int TypeNumBits() { return typeNumBits; }
    static int NumTypes() { return types.Num(); }
    static const idTypeInfo *TypeForNum(int index) {
        return index >= 0 && index < typenums.Num() ? typenums[index] : nullptr;
    }

    static int memused;
    static int numobjects;

private:
    using spawn_t = idTypeInfo::spawn_t;
    spawn_t CallSpawnFunc(idTypeInfo *type);

    static bool initialized;
    static int typeNumBits;
    static idList<idTypeInfo *, 51> types;
    static idList<idTypeInfo *, 51> typenums;
};

// The generated class.h also carried these Xbox UI local types. Keep their
// recovered layouts valid without coupling GameLib to the Xbox UI runtime.
struct SUB_CLASS_bitfields {
    unsigned int SUB_CLASS_INF : 8;
};

union SUB_CLASS {
    SUB_CLASS_bitfields bitfields;
    SUB_CLASS_bitfields bits;
    unsigned int u32All;
    int i32All;
    float f32All;
};

struct _XUIOBJ;
struct XUIMessage;
struct XUIElementPropDef;
struct XUIObjectMethods {
    long (__fastcall *ObjectProc)(_XUIOBJ *, XUIMessage *, void *);
    long (__fastcall *CreateInstance)(_XUIOBJ *, void **);
    long (__fastcall *DestroyInstance)(void *);
};

struct XUIClass {
    unsigned int cbSize;
    const wchar_t *szClassName;
    const wchar_t *szBaseClassName;
    const wchar_t *szClassDetails;
    XUIObjectMethods Methods;
    const XUIElementPropDef *pPropDefs;
    unsigned int dwPropDefCount;
    int bExtensionClass;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTypeInfo) == 60, "Recovered idTypeInfo ABI changed");
static_assert(sizeof(idClass) == 4, "Recovered idClass ABI changed");
static_assert(sizeof(SUB_CLASS) == 4, "Recovered SUB_CLASS ABI changed");
static_assert(sizeof(XUIObjectMethods) == 12,
    "Recovered XUIObjectMethods ABI changed");
static_assert(sizeof(XUIClass) == 40, "Recovered XUIClass ABI changed");
#endif
