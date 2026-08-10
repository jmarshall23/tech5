#include "models/skeletalanimation/taginfo.h"

#include "idlib/filesystem/file.h"
#include "idlib/lib_print.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "models/skeletalanimation/animation.h"
#include "models/skeletalanimation/declmd6.h"

#include <cstdlib>

namespace {

bool TokenIs(const idToken& token, const char* text) {
    return idStr::Cmp(token.c_str(), text) == 0;
}

const tagData_t& BlankTagData() {
    static const tagData_t blank = {
        idVec3(0.0f, 0.0f, 0.0f),
        idQuat(0.0f, 0.0f, 0.0f, 0.0f),
        idHandle<unsigned short, invalidJointHandle_t, 65535>()
    };
    return blank;
}

} // namespace

bool idTagInfo::Equal(const idTagInfo& other) const {
    return tagData.trans.x == other.tagData.trans.x &&
        tagData.trans.y == other.tagData.trans.y &&
        tagData.trans.z == other.tagData.trans.z &&
        tagData.rot.x == other.tagData.rot.x &&
        tagData.rot.y == other.tagData.rot.y &&
        tagData.rot.z == other.tagData.rot.z &&
        tagData.rot.w == other.tagData.rot.w &&
        tagData.parentJoint == other.tagData.parentJoint;
}

idHandle<unsigned short, invalidJointHandle_t, 65535>
idTagInfo::FindJoint(const char* jointName, const idDeclMD6* declaration) {
    idHandle<unsigned short, invalidJointHandle_t, 65535> handle =
        animation != nullptr && jointName != nullptr
            ? animation->FindJointHandle(jointName)
            : idHandle<unsigned short, invalidJointHandle_t, 65535>();
    if (!handle.IsValid()) {
        idLibPrint::Warning("%s - joint <%s> not found on tag <%s> for <%s>",
            "idTagInfo::FindJoint", jointName != nullptr ? jointName : "",
            tagName.c_str(), declaration != nullptr
                ? declaration->GetName() : "");
    }
    return handle;
}

int idTagInfo::Parse(idParser& parser, const idDeclMD6* declaration) {
    tagData.trans.Set(0.0f, 0.0f, 0.0f);
    tagData.rot = idQuat(0.0f, 0.0f, 0.0f, 0.0f);
    tagData.parentJoint.Invalidate();

    idToken token;
    if (!parser.ExpectTokenType(TT_STRING, 0, token)) return 1;
    tagName.Set(token.c_str());
    if (!parser.ExpectTokenString("{")) return 1;

    int errors = 0;
    while (parser.ReadToken(token)) {
        if (TokenIs(token, "}")) break;
        if (TokenIs(token, "offset") || TokenIs(token, "trans")) {
            if (!parser.Parse1DMatrix(3, &tagData.trans.x)) ++errors;
        } else if (TokenIs(token, "quat") || TokenIs(token, "rot")) {
            if (!parser.Parse1DMatrix(4, &tagData.rot.x)) {
                ++errors;
            } else {
                tagData.rot.Normalize();
            }
        } else if (TokenIs(token, "actor_joint") ||
                TokenIs(token, "parent")) {
            if (!parser.ExpectTokenType(TT_STRING, 0, token)) {
                ++errors;
                continue;
            }
            idStr jointName(token.c_str());
            jointName.MakeNameCanonical();
            tagData.parentJoint = FindJoint(jointName.c_str(), declaration);
            if (!tagData.parentJoint.IsValid()) {
                ++errors;
            }
        } else if (TokenIs(token, "movemode")) {
            if (!parser.ExpectTokenType(TT_STRING, 0, token)) ++errors;
        } else {
            parser.Error("Unknown token '%s' in modeldef '%s'",
                token.c_str(),
                declaration != nullptr ? declaration->GetName() : "");
            ++errors;
        }
    }
    return errors;
}

void idTagInfo::Write(idFile_String& file, const char* indent) const {
    const char* prefix = indent != nullptr ? indent : "";
    file.Printf("%stag \"%s\" {\n", prefix, tagName.c_str());
    file.Printf("%s\ttrans ( %.9g %.9g %.9g )\n", prefix,
        tagData.trans.x, tagData.trans.y, tagData.trans.z);
    file.Printf("%s\trot ( %.9g %.9g %.9g %.9g )\n", prefix,
        tagData.rot.x, tagData.rot.y, tagData.rot.z, tagData.rot.w);
    const char* parentName = animation != nullptr &&
            tagData.parentJoint.IsValid()
        ? animation->GetJointName(tagData.parentJoint) : "";
    file.Printf("%s\tparent \"%s\"\n", prefix,
        parentName != nullptr ? parentName : "");
    file.Printf("%s}\n", prefix);
}

bool idPropInfo::Equal(const idPropInfo& other) const {
    if (idStr::Icmp(propName.c_str(), other.propName.c_str()) != 0 ||
            tags.Num() != other.tags.Num()) return false;
    for (int index = 0; index < tags.Num(); ++index) {
        bool found = false;
        for (int candidate = 0; candidate < other.tags.Num(); ++candidate) {
            if (tags[index].tagName == other.tags[candidate].tagName) {
                found = tags[index].Equal(other.tags[candidate]);
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

int idPropInfo::Parse(idParser& parser, const idDeclMD6* declaration) {
    idToken token;
    if (!parser.ExpectTokenType(TT_STRING, 0, token)) return 1;
    propName = token.c_str();

    if (parser.CheckTokenType(TT_NUMBER, 0, token)) {
        const int count = std::atoi(token.c_str());
        if (count > tags.NumAllocated()) tags.Resize(count);
    }
    if (!parser.ExpectTokenString("{")) return 1;

    int errors = 0;
    while (parser.ReadToken(token)) {
        if (TokenIs(token, "}")) break;
        if (!TokenIs(token, "tag")) {
            parser.Error(
                "Unknown token '%s' while parsing prop info for modeldef '%s'",
                token.c_str(),
                declaration != nullptr ? declaration->GetName() : "");
            ++errors;
            continue;
        }
        idTagInfo* tag = tags.Alloc();
        if (tag == nullptr) {
            ++errors;
            parser.SkipBracedSection(true);
            continue;
        }
        errors += tag->Parse(parser, declaration);
    }
    tags.Resize(tags.Num());
    return errors;
}

void idPropInfo::Write(idFile_String& file, const char* indent,
        const idPropsCollection* otherCollection) const {
    const char* prefix = indent != nullptr ? indent : "";
    file.Printf("%sprop \"%s\" {\n", prefix, propName.c_str());
    idStr tagIndent(prefix);
    tagIndent.Append("\t");
    const idPropInfo* other = otherCollection != nullptr
        ? otherCollection->FindProp(propName.c_str()) : nullptr;
    for (int index = 0; index < tags.Num(); ++index) {
        const idTagInfo& tag = tags[index];
        const idTagInfo* inherited = nullptr;
        if (other != nullptr) {
            for (int otherIndex = 0; otherIndex < other->tags.Num();
                    ++otherIndex) {
                if (other->tags[otherIndex].tagName == tag.tagName) {
                    inherited = &other->tags[otherIndex];
                    break;
                }
            }
        }
        if (inherited == nullptr || !tag.Equal(*inherited))
            tag.Write(file, tagIndent.c_str());
    }
    file.Printf("%s}\n", prefix);
}

int idPropsCollection::Parse(idParser& parser,
        const idDeclMD6* declaration) {
    idToken token;
    if (parser.CheckTokenType(TT_NUMBER, 0, token)) {
        const int count = std::atoi(token.c_str());
        if (count > props.NumAllocated()) props.Resize(count);
    }
    if (!parser.ExpectTokenString("{")) return 1;

    int errors = 0;
    while (parser.ReadToken(token)) {
        if (TokenIs(token, "}")) break;
        if (!TokenIs(token, "prop")) {
            parser.Error(
                "Unknown token '%s' while loading props collection for modeldef '%s'",
                token.c_str(),
                declaration != nullptr ? declaration->GetName() : "");
            ++errors;
            continue;
        }
        idPropInfo* prop = props.Alloc();
        if (prop == nullptr) {
            ++errors;
            parser.SkipBracedSection(true);
            continue;
        }
        errors += prop->Parse(parser, declaration);
    }
    props.Resize(props.Num());
    return errors;
}

void idPropsCollection::DuplicateInherited(
        const idPropsCollection* other) {
    if (other == nullptr) return;
    for (int propIndex = 0; propIndex < other->props.Num(); ++propIndex) {
        const idPropInfo& inherited = other->props[propIndex];
        idPropInfo* local = FindProp(inherited.propName.c_str());
        if (local == nullptr) {
            props.Append(inherited);
            continue;
        }
        for (int tagIndex = 0; tagIndex < inherited.tags.Num(); ++tagIndex) {
            const idTagInfo& tag = inherited.tags[tagIndex];
            bool found = false;
            for (int localTag = 0; localTag < local->tags.Num(); ++localTag) {
                if (local->tags[localTag].tagName == tag.tagName) {
                    found = true;
                    break;
                }
            }
            if (!found) local->tags.Append(tag);
        }
    }
}

void idPropsCollection::Write(idFile_String& file,
        const idDeclMD6* declaration,
        const char* indent) const {
    const idPropsCollection* parentCollection =
        declaration != nullptr && declaration->parentDecl != nullptr
            ? &declaration->parentDecl->props : nullptr;
    Write(file, parentCollection, indent);
}

void idPropsCollection::Write(idFile_String& file,
        const idPropsCollection* otherCollection,
        const char* indent) const {
    const char* prefix = indent != nullptr ? indent : "";
    file.Printf("%sprops {\n", prefix);
    idStr propIndent(prefix);
    propIndent.Append("\t");
    for (int index = 0; index < props.Num(); ++index) {
        const idPropInfo& prop = props[index];
        const idPropInfo* inherited = otherCollection != nullptr
            ? otherCollection->FindProp(prop.propName.c_str()) : nullptr;
        if (inherited == nullptr || !prop.Equal(*inherited))
            prop.Write(file, propIndent.c_str(), otherCollection);
    }
    file.Printf("%s}\n", prefix);
}

idPropInfo* idPropsCollection::FindProp(const char* name) {
    return const_cast<idPropInfo*>(
        static_cast<const idPropsCollection*>(this)->FindProp(name));
}

const idPropInfo* idPropsCollection::FindProp(const char* name) const {
    const int index = FindPropIndex(name);
    return index >= 0 ? &props[index] : nullptr;
}

int idPropsCollection::FindPropIndex(const char* name) const {
    if (name == nullptr) return -1;
    for (int index = 0; index < props.Num(); ++index) {
        if (idStr::Icmp(props[index].propName.c_str(), name) == 0) {
            return index;
        }
    }
    return -1;
}

idTagInfo* idPropsCollection::FindTag(const int propIndex,
    const char* name) {
    return const_cast<idTagInfo*>(
        static_cast<const idPropsCollection*>(this)->FindTag(propIndex,
            name));
}

const idTagInfo* idPropsCollection::FindTag(const int propIndex,
    const char* name) const {
    const int index = FindTagIndex(propIndex, name);
    return index >= 0 ? &props[propIndex].tags[index] : nullptr;
}

int idPropsCollection::FindTagIndex(const int propIndex,
    const char* name) const {
    if (propIndex < 0 || propIndex >= props.Num() || name == nullptr) {
        return -1;
    }
    const idList<idTagInfo, 82>& tags = props[propIndex].tags;
    for (int index = 0; index < tags.Num(); ++index) {
        if (idStr::Icmp(tags[index].tagName.c_str(), name) == 0) {
            return index;
        }
    }
    return -1;
}

const tagData_t& idPropsCollection::GetTag(const char* propName,
    const char* tagName) const {
    const int propIndex = FindPropIndex(propName);
    const idTagInfo* tag = FindTag(propIndex, tagName);
    return tag != nullptr ? tag->tagData : BlankTagData();
}

const tagData_t& idPropsCollection::GetTagByIndices(const int propIndex,
    const int tagIndex) const {
    if (propIndex < 0 || propIndex >= props.Num() || tagIndex < 0
        || tagIndex >= props[propIndex].tags.Num()) {
        return BlankTagData();
    }
    return props[propIndex].tags[tagIndex].tagData;
}

idPropInfo* idPropsCollection::AddProp(const char* name) {
    idPropInfo prop;
    prop.propName = name != nullptr ? name : "";
    if (props.Append(prop) < 0) return nullptr;
    return &props[props.Num() - 1];
}

void idPropsCollection::Free() {
    props.ClearFree();
}
