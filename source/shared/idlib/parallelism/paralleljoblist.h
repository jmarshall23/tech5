#pragma once

class idParallelJobList_Threads;
class idColor;

class idParallelJobList {
public:
    struct idParallelJobList_SPURS;

    idParallelJobList_SPURS* jobListSPURS;
    idParallelJobList_Threads* jobListThreads;
    const idColor* color;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idParallelJobList) == 12,
    "Recovered idParallelJobList ABI changed");
#endif

