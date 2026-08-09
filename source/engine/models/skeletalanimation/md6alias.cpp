#include "models/skeletalanimation/md6alias.h"

#include "decls/decl.h"
#include "idlib/filesystem/file.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "idlib/text/str.h"
#include "models/skeletalanimation/declmd6.h"

#include <cstring>

idMD6Alias::AnimLoadCallback idMD6Alias::animLoadCallback = nullptr;

idMD6Alias::idMD6Alias() : name(""), aliasHandle(), flags(0), animRefs() {}

void idMD6Alias::SetAnimLoadCallback(AnimLoadCallback callback) {
    animLoadCallback = callback;
}

void idMD6Alias::Write(const idDecl*, idFile_String& file,
        const char* indent) const {
    const char* prefix = indent != nullptr ? indent : "";
    file.Printf("%salias {\n", prefix);
    file.Printf("%s\tname \"%s\"\n", prefix, name.c_str());
    if ((flags & ALIASFLAG_WRITABLE_FLAGS) != 0) {
        file.Printf("%s\tflags {\n", prefix);
        if ((flags & ALIASFLAG_FORCE_LOAD) != 0)
            file.Printf("%s\t\tforceLoad\n", prefix);
        file.Printf("%s\t}\n", prefix);
    }
    for (int index = 0; index < animRefs.Num(); ++index)
        file.Printf("%s\tanim \"%s\"\n", prefix, animRefs[index].c_str());
    file.Printf("%s}\n", prefix);
}

bool idMD6Alias::IsInherited(const idMD6Alias& other) const {
    if (idStr::Icmp(name.c_str(), other.name.c_str()) != 0 ||
            animRefs.Num() != other.animRefs.Num()) return false;
    for (int index = 0; index < animRefs.Num(); ++index) {
        if (idStr::Icmp(animRefs[index].c_str(),
                other.animRefs[index].c_str()) != 0) return false;
    }
    return true;
}

void idMD6Alias::LoadAnims(const idDeclMD6* decl) const {
    if (decl == nullptr || decl->model == nullptr) return;
    const_cast<idMD6Alias*>(this)->flags |= ALIASFLAG_IS_LOADED;
    if (animLoadCallback == nullptr) return;
    for (int index = 0; index < animRefs.Num(); ++index)
        animLoadCallback(animRefs[index].c_str());
}

void idMD6Alias::Parse(const idDecl*, idParser& parser, int& loadErrors) {
    idToken token;
    if (!parser.ExpectTokenString("{") ||
            !parser.ExpectTokenString("name") || !parser.ReadToken(token)) {
        ++loadErrors;
        return;
    }
    name.Set(token.c_str());
    flags = 0;
    animRefs.Clear();

    while (parser.ReadToken(token)) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        if (idStr::Cmp(token.c_str(), "anim") == 0) {
            if (!parser.ReadToken(token)) {
                ++loadErrors;
                return;
            }
            animRefs.Append(idAtomicStringT<md6AnimAtomicString_t>(
                token.c_str()));
        } else if (idStr::Cmp(token.c_str(), "flags") == 0) {
            if (!parser.ExpectTokenString("{")) {
                ++loadErrors;
                return;
            }
            while (parser.ReadToken(token) &&
                    idStr::Cmp(token.c_str(), "}") != 0) {
                if (idStr::Icmp(token.c_str(), "forceLoad") == 0)
                    flags |= ALIASFLAG_FORCE_LOAD;
                else
                    parser.Warning("Unknown MD6 alias flag '%s'", token.c_str());
            }
        } else {
            parser.Error("Unknown token '%s' in MD6 alias", token.c_str());
            ++loadErrors;
            return;
        }
    }

    if ((flags & ALIASFLAG_FORCE_LOAD) != 0 && animLoadCallback != nullptr) {
        for (int index = 0; index < animRefs.Num(); ++index) {
            if (!animLoadCallback(animRefs[index].c_str())) ++loadErrors;
        }
    }
}
