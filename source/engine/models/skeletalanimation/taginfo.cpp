#include "models/skeletalanimation/taginfo.h"

bool idPropInfo::Equal(const idPropInfo& other) const {
    if (idStr::Icmp(propName.c_str(), other.propName.c_str()) != 0
        || tags.Num() != other.tags.Num()) {
        return false;
    }
    for (int index = 0; index < tags.Num(); ++index) {
        if (idStr::Icmp(tags[index].tagName.c_str(),
                other.tags[index].tagName.c_str()) != 0) {
            return false;
        }
    }
    return true;
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

const tagData_t* idPropsCollection::GetTag(const char* propName,
    const char* tagName) const {
    const int propIndex = FindPropIndex(propName);
    const idTagInfo* tag = FindTag(propIndex, tagName);
    return tag != nullptr ? &tag->tagData : nullptr;
}

const tagData_t* idPropsCollection::GetTagByIndices(const int propIndex,
    const int tagIndex) const {
    if (propIndex < 0 || propIndex >= props.Num() || tagIndex < 0
        || tagIndex >= props[propIndex].tags.Num()) {
        return nullptr;
    }
    return &props[propIndex].tags[tagIndex].tagData;
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
