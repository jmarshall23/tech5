#include "gamelib/class.h"

#include "idlib/lib_print.h"
#include "idlib/text/str.h"

namespace {

idTypeInfo *typeList = nullptr;
idHierarchy<idTypeInfo> classHierarchy;

int NumberTypeHierarchy(idHierarchy<idTypeInfo> *node, int nextType) {
    for (idHierarchy<idTypeInfo> *current = node; current != nullptr;
            current = current->sibling) {
        idTypeInfo *type = current->owner;
        if (type == nullptr) {
            continue;
        }
        type->typeNum = nextType++;
        nextType = NumberTypeHierarchy(current->child, nextType);
        type->lastChild = nextType - 1;
    }
    return nextType;
}

} // namespace

bool idClass::initialized = false;
int idClass::typeNumBits = 0;
int idClass::memused = 0;
int idClass::numobjects = 0;
idList<idTypeInfo *, 51> idClass::types(16);
idList<idTypeInfo *, 51> idClass::typenums(16);

idClass::~idClass() = default;

idTypeInfo::idTypeInfo(const char *classname_, const char *superclass_,
        const int size_, const bool abstract_,
        const createInstance_t createInstance_, const spawn_t spawn_)
    : classname(classname_)
    , superclass(superclass_)
    , CreateInstance(createInstance_)
    , Spawn(spawn_)
    , initialized(false)
    , super(idClass::GetClass(superclass_))
    , next(nullptr)
    , isAbstract(abstract_)
    , size(size_)
    , typeNum(0)
    , lastChild(0)
    , node(nullptr) {
    for (idTypeInfo *type = typeList; type != nullptr; type = type->next) {
        if (type->super == nullptr && type->superclass != nullptr
                && idStr::Cmp(type->superclass, classname) == 0
                && idStr::Cmp(type->classname, "idClass") != 0) {
            type->super = this;
        }
    }

    idTypeInfo **link = &typeList;
    while (*link != nullptr && idStr::Cmp(classname, (*link)->classname) >= 0) {
        link = &(*link)->next;
    }
    next = *link;
    *link = this;
}

idTypeInfo::~idTypeInfo() {
    node.RemoveFromHierarchy();
}

void idTypeInfo::Init() {
    if (initialized) {
        return;
    }
    if (super != nullptr && !super->initialized) {
        super->Init();
    }
    node.ParentTo(super != nullptr ? super->node : classHierarchy);
    node.SetOwner(this);
    for (idTypeInfo *ancestor = super; ancestor != nullptr;
            ancestor = ancestor->super) {
        ++ancestor->lastChild;
    }
    initialized = true;
}

idClass::spawn_t idClass::CallSpawnFunc(idTypeInfo *type) {
    if (type == nullptr) {
        return nullptr;
    }
    const spawn_t inherited = type->super != nullptr
        ? CallSpawnFunc(type->super)
        : nullptr;
    if (type->Spawn != nullptr && inherited != type->Spawn) {
        type->Spawn(this);
        return type->Spawn;
    }
    return inherited;
}

void idClass::CallSpawn() {
    idTypeInfo *type = GetType();
    if (type == nullptr) {
        return;
    }
    const spawn_t inherited = type->super != nullptr
        ? CallSpawnFunc(type->super)
        : nullptr;
    if (type->Spawn != nullptr && inherited != type->Spawn) {
        type->Spawn(this);
    }
}

const char *idClass::GetClassname() const {
    idTypeInfo *type = const_cast<idClass*>(this)->GetType();
    return type != nullptr ? type->classname : nullptr;
}

bool idClass::IsType(const idTypeInfo& superclass) const {
    idTypeInfo *type = const_cast<idClass*>(this)->GetType();
    return type != nullptr && type->typeNum >= superclass.typeNum
        && type->typeNum <= superclass.lastChild;
}

idTypeInfo *idClass::GetClass(const char *name) {
    if (name == nullptr) {
        return nullptr;
    }
    if (!initialized) {
        for (idTypeInfo *type = typeList; type != nullptr; type = type->next) {
            if (idStr::Cmp(type->classname, name) == 0) {
                return type;
            }
        }
        return nullptr;
    }

    int lower = 0;
    int upper = types.Num() - 1;
    while (lower <= upper) {
        const int middle = (lower + upper) / 2;
        idTypeInfo *type = types[middle];
        const int comparison = idStr::Cmp(type->classname, name);
        if (comparison == 0) {
            return type;
        }
        if (comparison < 0) {
            lower = middle + 1;
        } else {
            upper = middle - 1;
        }
    }
    return nullptr;
}

idClass *idClass::CreateInstance(const char *name) {
    idTypeInfo *type = GetClass(name);
    return type != nullptr && type->CreateInstance != nullptr
        ? type->CreateInstance()
        : nullptr;
}

void idClass::DisplayInfo_f(const idCmdArgs&) {
    idLibPrint::Printf("Class memory status: %i bytes allocated in %i objects\n",
        memused, numobjects);
}

void idClass::ListClasses_f(const idCmdArgs&) {
    idLibPrint::Printf("%-24s %-24s %-6s %-6s\n",
        "Classname", "Superclass", "Type", "Subclasses");
    idLibPrint::Printf(
        "----------------------------------------------------------------------\n");
    for (int index = 0; index < types.Num(); ++index) {
        const idTypeInfo *type = types[index];
        idLibPrint::Printf("%-24s %-24s %6d %6d\n", type->classname,
            type->superclass, type->typeNum, type->lastChild - type->typeNum);
    }
    idLibPrint::Printf("...%d classes", types.Num());
}

void idClass::Init() {
    idLibPrint::Printf("Initializing class hierarchy\n");
    if (initialized) {
        idLibPrint::Printf("...already initialized\n");
        return;
    }

    for (idTypeInfo *type = typeList; type != nullptr; type = type->next) {
        type->Init();
    }
    const int count = NumberTypeHierarchy(classHierarchy.child, 0);
    typeNumBits = 0;
    while ((1u << typeNumBits) < static_cast<unsigned int>(count)
            && typeNumBits < 31) {
        ++typeNumBits;
    }

    types.SetNum(count);
    typenums.SetNum(count);
    int sortedIndex = 0;
    for (idTypeInfo *type = typeList; type != nullptr; type = type->next) {
        if (sortedIndex < count) {
            types[sortedIndex++] = type;
        }
        if (type->typeNum >= 0 && type->typeNum < count) {
            typenums[type->typeNum] = type;
        }
    }
    initialized = true;
}

void idClass::Shutdown() {
    types.ClearFree();
    typenums.ClearFree();
    initialized = false;
}
