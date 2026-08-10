#pragma once

#include "idlib/handle.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/atomicstring.h"
#include "idlib/text/str.h"

class idDeclMD6;
class idFile_String;
class idParser;
class idPropsCollection;

enum invalidJointHandle_t : int;

struct alignas(4) tagData_t {
    idVec3 trans;
    idQuat rot;
    idHandle<unsigned short, invalidJointHandle_t, 65535> parentJoint;
};

class idTagInfo {
public:
    bool Equal(const idTagInfo& other) const;
    idHandle<unsigned short, invalidJointHandle_t, 65535> FindJoint(
        const char* jointName, const idDeclMD6* declaration);
    int Parse(idParser& parser, const idDeclMD6* declaration);
    void Write(idFile_String& file, const char* indent) const;

    idAtomicString tagName;
    tagData_t tagData;
};

class idPropInfo {
public:
    bool Equal(const idPropInfo& other) const;
    int Parse(idParser& parser, const idDeclMD6* declaration);
    void Write(idFile_String& file, const char* indent,
        const idPropsCollection* otherCollection = nullptr) const;

    idStr propName;
    idList<idTagInfo, 82> tags;
};

class idPropsCollection {
public:
    int Parse(idParser& parser, const idDeclMD6* declaration);
    void DuplicateInherited(const idPropsCollection* other);
    void Write(idFile_String& file, const idDeclMD6* declaration,
        const char* indent) const;

    idPropInfo* FindProp(const char* propName);
    const idPropInfo* FindProp(const char* propName) const;
    int FindPropIndex(const char* propName) const;
    idTagInfo* FindTag(int propIndex, const char* tagName);
    const idTagInfo* FindTag(int propIndex, const char* tagName) const;
    int FindTagIndex(int propIndex, const char* tagName) const;
    const tagData_t& GetTag(const char* propName,
        const char* tagName) const;
    const tagData_t& GetTagByIndices(int propIndex, int tagIndex) const;
    idPropInfo* AddProp(const char* propName);
    void Free();

    idList<idPropInfo, 82> props;

private:
    void Write(idFile_String& file,
        const idPropsCollection* otherCollection,
        const char* indent) const;
};

static_assert(sizeof(tagData_t) == 32,
    "Recovered tag-data ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idTagInfo) == 36,
    "Recovered tag-information ABI changed");
static_assert(sizeof(idPropInfo) == 48,
    "Recovered prop-information ABI changed");
static_assert(sizeof(idPropsCollection) == 16,
    "Recovered props-collection ABI changed");
#endif
