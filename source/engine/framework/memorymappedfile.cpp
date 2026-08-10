#include "framework/memorymappedfile.h"
#include "framework/framework_runtime.h"

#include "idlib/csystems/cvarsystem.h"
#include "idlib/filesystem/file.h"
#include "idlib/lib_print.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#include <algorithm>

namespace {
idMemoryMappedFile* currentMemoryMappedFile = nullptr;
idCVar mmf_debug("mmf_debug", "0", CVAR_BOOL,
    "print during memory mapped file operation");

std::int64_t AlignDown(const std::int64_t value, const std::int64_t alignment) {
    return value & ~(alignment - 1);
}

std::int64_t AlignUp(const std::int64_t value, const std::int64_t alignment) {
    return (value + alignment - 1) & ~(alignment - 1);
}
}

idMemoryMappedFile::idMemoryMappedFile(idFile& sourceFile,
        const std::int64_t fileOffset, const std::int64_t length)
    : file(&sourceFile), alignedFileOffset(AlignDown(fileOffset, PAGE_SIZE)),
      alignedLength(AlignUp(fileOffset + length, PAGE_SIZE) - alignedFileOffset),
      virtualBase(static_cast<unsigned char*>(::VirtualAlloc(nullptr,
          static_cast<SIZE_T>(alignedLength), MEM_RESERVE, PAGE_READWRITE))),
      pages(static_cast<unsigned int>(alignedLength / PAGE_SIZE)) {
    for (unsigned int index = 0; index < pages.num; ++index) {
        pages[index] = {nullptr, false, PGST_UNCOMITTED};
    }
    currentMemoryMappedFile = this;
    if (virtualBase == nullptr && alignedLength > 0) {
        idLibPrint::FatalError(
            "idMemoryMappedFile: failed to reserve %lld bytes",
            alignedLength);
    }
}

idMemoryMappedFile::~idMemoryMappedFile() {
    for (unsigned int index = 0; index < pages.num; ++index) {
        if (pages[index].state != PGST_UNCOMITTED) {
            DecommitPage(static_cast<int>(index));
        }
    }
    if (virtualBase != nullptr) {
        ::VirtualFree(virtualBase, 0, MEM_RELEASE);
    }
    if (currentMemoryMappedFile == this) currentMemoryMappedFile = nullptr;
}

void idMemoryMappedFile::CommitPage(const int pageNum) {
    if (virtualBase == nullptr || pageNum < 0
            || pageNum >= static_cast<int>(pages.num)
            || pages[pageNum].state != PGST_UNCOMITTED) {
        return;
    }
    unsigned char* const destination = virtualBase + pageNum * PAGE_SIZE;
    if (::VirtualAlloc(destination, static_cast<SIZE_T>(PAGE_SIZE),
            MEM_COMMIT, PAGE_READWRITE) == nullptr) {
        return;
    }
    mmPage_t& page = pages[pageNum];
    page.dest = destination;
    page.state = PGST_READING;
    const std::int64_t offset = alignedFileOffset + pageNum * PAGE_SIZE;
    const std::int64_t remaining = (std::max<std::int64_t>)(0,
        file->Length() - offset);
    const unsigned int requested = static_cast<unsigned int>(
        (std::min<std::int64_t>)(PAGE_SIZE, remaining));
    const unsigned int read = requested != 0
        ? file->ReadOfs(offset, destination, requested) : 0;
    if (read < PAGE_SIZE) {
        ZeroMemory(destination + read, static_cast<SIZE_T>(PAGE_SIZE - read));
    }
    page.completion = true;
    page.state = PGST_FULL;
    if (mmf_debug.GetBool()) {
        idLibPrint::Printf("idMemoryMappedFile: committed page %d\n",
            pageNum);
    }
}

void idMemoryMappedFile::DecommitPage(const int pageNum) {
    if (virtualBase == nullptr || pageNum < 0
            || pageNum >= static_cast<int>(pages.num)
            || pages[pageNum].state == PGST_UNCOMITTED) {
        return;
    }
    ::VirtualFree(virtualBase + pageNum * PAGE_SIZE,
        static_cast<SIZE_T>(PAGE_SIZE), MEM_DECOMMIT);
    pages[pageNum] = {nullptr, false, PGST_UNCOMITTED};
}

void idMemoryMappedFile::Print() const {
    unsigned int committed = 0;
    for (unsigned int index = 0; index < pages.num; ++index) {
        committed += pages[index].state == PGST_FULL ? 1u : 0u;
    }
    idLibPrint::Printf("memory mapped file %s: %u/%u pages committed\n",
        file != nullptr ? file->GetName() : "<null>", committed, pages.num);
}

bool idMemoryMappedFile::IsBlockFullyCommitted(const std::int64_t fileOffset,
        const std::int64_t length) const {
    if (length <= 0 || fileOffset < alignedFileOffset
            || fileOffset + length > alignedFileOffset + alignedLength) {
        return false;
    }
    const int first = static_cast<int>((fileOffset - alignedFileOffset) / PAGE_SIZE);
    const int last = static_cast<int>((fileOffset + length - 1
        - alignedFileOffset) / PAGE_SIZE);
    for (int page = first; page <= last; ++page) {
        if (pages[page].state == PGST_READING && pages[page].completion) {
            const_cast<mmPage_t&>(pages[page]).state = PGST_FULL;
        }
        if (pages[page].state != PGST_FULL) {
            return false;
        }
    }
    return true;
}

void idMemoryMappedFile::CommitBlock(const std::int64_t fileOffset,
        const std::int64_t length) {
    if (length <= 0) return;
    const int first = static_cast<int>((fileOffset - alignedFileOffset) / PAGE_SIZE);
    const int last = static_cast<int>((fileOffset + length - 1
        - alignedFileOffset) / PAGE_SIZE);
    for (int page = (std::max)(0, first);
            page <= last && page < static_cast<int>(pages.num); ++page) {
        CommitPage(page);
    }
}

void idMemoryMappedFile::DecommitBlock(const std::int64_t fileOffset,
        const std::int64_t length) {
    if (length <= 0) return;
    const int first = static_cast<int>((fileOffset - alignedFileOffset) / PAGE_SIZE);
    const int last = static_cast<int>((fileOffset + length - 1
        - alignedFileOffset) / PAGE_SIZE);
    for (int page = (std::max)(0, first);
            page <= last && page < static_cast<int>(pages.num); ++page) {
        DecommitPage(page);
    }
}

const unsigned char* idMemoryMappedFile::PointerForFileBlock(
        const std::int64_t fileOffset, const std::int64_t length) {
    return IsBlockFullyCommitted(fileOffset, length)
        ? virtualBase + (fileOffset - alignedFileOffset) : nullptr;
}

bool idMemoryMappedFile::SetBatchState(const fileRange_t* const ranges,
        const int numRanges) {
    if (ranges == nullptr || numRanges < 0) {
        return false;
    }
    idTempArray<unsigned char> wanted(pages.num);
    for (int index = 0; index < numRanges; ++index) {
        if (ranges[index].length <= 0) continue;
        const int first = static_cast<int>((ranges[index].fileOffset
            - alignedFileOffset) / PAGE_SIZE);
        const int last = static_cast<int>((ranges[index].fileOffset
            + ranges[index].length - 1 - alignedFileOffset) / PAGE_SIZE);
        for (int page = (std::max)(0, first);
                page <= last && page < static_cast<int>(pages.num); ++page) {
            wanted[static_cast<unsigned int>(page)] = 1;
        }
    }
    for (unsigned int page = 0; page < pages.num; ++page) {
        if (wanted[page] == 0 && pages[page].state != PGST_UNCOMITTED) {
            DecommitPage(static_cast<int>(page));
        }
    }
    for (unsigned int page = 0; page < pages.num; ++page) {
        if (wanted[page] != 0 && pages[page].state == PGST_UNCOMITTED) {
            CommitPage(static_cast<int>(page));
        }
    }
    for (int index = 0; index < numRanges; ++index) {
        if (!IsBlockFullyCommitted(ranges[index].fileOffset,
                ranges[index].length)) return false;
    }
    return true;
}

void RegisterMemoryMappedFileCommands() {
    tech5Framework::RegisterCommand("reportMemoryMappedFile",
        [](const std::vector<idStr>&) {
            if (currentMemoryMappedFile != nullptr) {
                currentMemoryMappedFile->Print();
            } else {
                idLibPrint::Printf("No active memory mapped file\n");
            }
        });
    tech5Framework::RegisterCommand("testMemoryMappedFile",
        [](const std::vector<idStr>&) {
            if (currentMemoryMappedFile == nullptr) {
                idLibPrint::Printf("No active memory mapped file\n");
                return;
            }
            currentMemoryMappedFile->Print();
        });
}
