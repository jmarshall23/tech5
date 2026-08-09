#pragma once

#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/text/atomicstring.h"

#include <cstdint>

enum invalidAliasHandle_t : int;
enum md6AnimAtomicString_t : int;
class idDecl;
class idDeclMD6;
class idFile_String;
class idParser;

// The tag is compile-time type separation; storage is the same single atomic
// string pointer recovered for idAtomicString.
template<class tag_t>
class idAtomicStringT : public idAtomicString {
public:
    using idAtomicString::idAtomicString;
};

class idMD6Alias {
public:
    using AnimLoadCallback = bool (*)(const char* animationName);
    enum flags_t : std::uint16_t {
        ALIASFLAG_FORCE_LOAD = 0x1,
        ALIASFLAG_IS_LOADED = 0x2,
        ALIASFLAG_WRITABLE_FLAGS = ALIASFLAG_FORCE_LOAD
    };

    idMD6Alias();

    void Write(const idDecl* decl, idFile_String& file,
        const char* indent) const;
    bool IsInherited(const idMD6Alias& other) const;
    void LoadAnims(const idDeclMD6* decl) const;
    void Parse(const idDecl* decl, idParser& parser, int& loadErrors);
    static void SetAnimLoadCallback(AnimLoadCallback callback);

    idAtomicString name;
    idHandle<unsigned short, invalidAliasHandle_t, 65535> aliasHandle;
    std::uint16_t flags;
    idList<idAtomicStringT<md6AnimAtomicString_t>, 19> animRefs;

private:
    static AnimLoadCallback animLoadCallback;
};
