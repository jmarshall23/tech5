#pragma once

#include "framework/resource.h"
#include "idlib/containers/hashindex.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

// The PDB emitted four explicit specializations without the primary
// template.  This is the common storage contract shared by all of them.
template<typename value_t, typename parent_t, typename handle_t,
    typename type_id_t, int listTag, int hashSize, typename allocator_t,
    typename name_generator_t>
class idAnimHash {
public:
    struct entry_t {
        const value_t* ptr;
        const parent_t* parent;
        idStr name;
        type_id_t typeId;
        handle_t handle;
        idResource::referenceType_t refType;
    };

    idList<entry_t, listTag> list;
    idHashIndex nameHash;
    int markStaticNum;
};
