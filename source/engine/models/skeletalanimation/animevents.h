#pragma once

#include "idlib/containers/hashindex.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "models/skeletalanimation/md6alias.h"
#include "models/skeletalanimation/md6animevent.h"

class idAnimEvents {
public:
    using CacheTransformsCallback = bool (*)(idAnimEvents& events,
        idDeclMD6& declaration);
    struct animEventInfo_t {
        bool operator==(const animEventInfo_t& other) const;
        bool GetCachedJoints(int eventNum,
            idStaticList<const idCachedJoint*, 8>& joints) const;

        idAtomicStringT<md6AnimAtomicString_t> animRef;
        idList<idMD6AnimEvent, 28> events;
    };

    idAnimEvents();
    virtual ~idAnimEvents();

    static idHandle<unsigned int, invalidAnimEventId_t, 0> GetNextEventId();

    void Parse(const idDeclMD6* declaration, idParser& parser,
        int& loadErrors);
    void Write(idFile_String& file, const char* indent) const;
    bool CacheTransforms(idDeclMD6* declaration);
    static void SetCacheTransformsCallback(CacheTransformsCallback callback);

    int FindAnimEventInfoIndex(
        const idAtomicStringT<md6AnimAtomicString_t>& animation) const;
    animEventInfo_t* FindAnimEventInfo(
        const idAtomicStringT<md6AnimAtomicString_t>& animation);
    const animEventInfo_t* FindAnimEventInfo(
        const idAtomicStringT<md6AnimAtomicString_t>& animation) const;
    bool FindAnimEvents(
        const idAtomicStringT<md6AnimAtomicString_t>& animation,
        int startFrame, int endFrame,
        idStaticList<const idMD6AnimEvent*, 16>& events) const;
    bool FindAnimEvents(
        const idAtomicStringT<md6AnimAtomicString_t>& animation,
        int startFrame, int endFrame, int eventNum,
        idStaticList<const idMD6AnimEvent*, 16>& events) const;
    void Free();

    idList<animEventInfo_t, 28> list;
    idHashIndex hashIndex;

private:
    static idHandle<unsigned int, invalidAnimEventId_t, 0> curEventId;
    static CacheTransformsCallback cacheTransformsCallback;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idAnimEvents::animEventInfo_t) == 20,
    "Recovered animation-event info ABI changed");
static_assert(sizeof(idAnimEvents) == 52,
    "Recovered animation-event collection ABI changed");
#endif
