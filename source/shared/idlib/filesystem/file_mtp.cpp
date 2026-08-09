#include "file_mtp.h"

#include "idlib/sys/sys_networking.h"

#include <algorithm>
#include <cstring>
#include <mutex>
#include <vector>

namespace {

idTCP mtpTCP;
char mtpServer[256] = "10.4.20.180";
unsigned short mtpPort = 2769;
int mtpWriteSize = 1400;
int mtpTimeout = 1000;
std::mutex mtpMutex;

void PutUInt16BE(unsigned char* output, const unsigned int value) {
    output[0] = static_cast<unsigned char>(value >> 8);
    output[1] = static_cast<unsigned char>(value);
}

void PutUInt32BE(unsigned char* output, const unsigned int value) {
    output[0] = static_cast<unsigned char>(value >> 24);
    output[1] = static_cast<unsigned char>(value >> 16);
    output[2] = static_cast<unsigned char>(value >> 8);
    output[3] = static_cast<unsigned char>(value);
}

void PutUInt64BE(unsigned char* output, const std::uint64_t value) {
    PutUInt32BE(output, static_cast<unsigned int>(value >> 32));
    PutUInt32BE(output + 4, static_cast<unsigned int>(value));
}

unsigned int GetUInt32BE(const unsigned char* input) {
    return (static_cast<unsigned int>(input[0]) << 24)
        | (static_cast<unsigned int>(input[1]) << 16)
        | (static_cast<unsigned int>(input[2]) << 8)
        | static_cast<unsigned int>(input[3]);
}

std::uint64_t GetUInt64BE(const unsigned char* input) {
    return (static_cast<std::uint64_t>(GetUInt32BE(input)) << 32)
        | GetUInt32BE(input + 4);
}

} // namespace

idFile_MTP::idFile_MTP()
    : position(0), mode(FS_READ), length(0),
      timestamp(static_cast<unsigned int>(-1)) {
}

idFile_MTP::~idFile_MTP() = default;

void idFile_MTP::ConfigureServer(const char* host, const unsigned short port,
        const int writeSize, const int timeoutMilliseconds) {
    std::lock_guard<std::mutex> lock(mtpMutex);
    mtpTCP.Close();
    const char* const safeHost = host == nullptr || *host == '\0'
        ? "127.0.0.1" : host;
    std::strncpy(mtpServer, safeHost, sizeof(mtpServer) - 1);
    mtpServer[sizeof(mtpServer) - 1] = '\0';
    mtpPort = port;
    mtpWriteSize = (std::max)(1, writeSize);
    mtpTimeout = (std::max)(1, timeoutMilliseconds);
}

void idFile_MTP::ShutdownTransport() {
    std::lock_guard<std::mutex> lock(mtpMutex);
    mtpTCP.Close();
}

bool idFile_MTP::EnsureConnection() {
    return mtpTCP.IsOpen()
        || mtpTCP.Connect(mtpServer, mtpPort, false, true, false);
}

bool idFile_MTP::SendRequest(const std::uint64_t offset,
        const unsigned int requestLength, const operation_t operation,
        const char* filename) {
    if (!EnsureConnection()) return false;
    const char* const safeName = filename == nullptr ? "" : filename;
    const std::size_t filenameLength = (std::min<std::size_t>)(
        std::strlen(safeName), 0xFFFFu);
    unsigned char request[16] = {};
    PutUInt64BE(request, offset);
    PutUInt32BE(request + 8, requestLength);
    PutUInt16BE(request + 12, static_cast<unsigned int>(filenameLength));
    PutUInt16BE(request + 14, operation);
    if (mtpTCP.WriteBlocking(request, sizeof(request), mtpTimeout)
            != sizeof(request)) {
        mtpTCP.Close();
        return false;
    }
    if (filenameLength > 0 && mtpTCP.WriteBlocking(safeName,
            static_cast<int>(filenameLength), mtpTimeout)
            != static_cast<int>(filenameLength)) {
        mtpTCP.Close();
        return false;
    }
    return true;
}

bool idFile_MTP::Open(const char* filename, const fsMode_t openMode) {
    const char* const safeName = filename == nullptr ? "" : filename;
    name = safeName;
    fullPath.Format("MTP:%s", safeName);
    mode = openMode;
    position = 0;

    unsigned int access = 1;
    if (mode == FS_READ || mode == FS_READ_NO_BUFFERING) {
        access = 0;
    } else if (mode == FS_APPEND) {
        access = 2;
    }

    std::lock_guard<std::mutex> lock(mtpMutex);
    if (!SendRequest(0, access, OP_OPEN,
            name.c_str())) return false;
    unsigned char stats[16] = {};
    if (mtpTCP.ReadBlocking(stats, sizeof(stats), mtpTimeout)
            != sizeof(stats)) {
        mtpTCP.Close();
        return false;
    }
    length = GetUInt64BE(stats);
    timestamp = GetUInt32BE(stats + 8);
    if (timestamp == static_cast<unsigned int>(-1)) return false;
    if (mode == FS_APPEND) position = length;
    return true;
}

unsigned int idFile_MTP::Read(void* buffer, const unsigned int len) {
    return ReadOfs(static_cast<std::int64_t>(position), buffer, len);
}

unsigned int idFile_MTP::ReadOfs(const std::int64_t offset, void* buffer,
        const unsigned int len) {
    if (buffer == nullptr || len <= 0 || offset < 0
            || (mode != FS_READ && mode != FS_READ_WRITE
                && mode != FS_READ_NO_BUFFERING)) return 0;
    std::lock_guard<std::mutex> lock(mtpMutex);

    for (int attempt = 0; attempt < 5; ++attempt) {
        if (!SendRequest(static_cast<std::uint64_t>(offset),
                static_cast<unsigned int>(len), OP_READ, name.c_str())) {
            mtpTCP.Close();
            continue;
        }
        unsigned int total = 0;
        bool failed = false;
        while (total < len) {
            unsigned char sizeBytes[4] = {};
            if (mtpTCP.ReadBlocking(sizeBytes, sizeof(sizeBytes), mtpTimeout)
                    != sizeof(sizeBytes)) {
                failed = true;
                break;
            }
            const unsigned int chunk = GetUInt32BE(sizeBytes);
            if (chunk == 0) break;
            if (chunk > len - total
                    || mtpTCP.ReadBlocking(static_cast<unsigned char*>(buffer)
                        + total, static_cast<int>(chunk), mtpTimeout)
                        != static_cast<int>(chunk)) {
                failed = true;
                break;
            }
            total += chunk;
        }
        if (!failed) {
            position = static_cast<std::uint64_t>(offset) + total;
            return total;
        }
        mtpTCP.Close();
    }
    return 0;
}

unsigned int idFile_MTP::Write(const void* buffer, const unsigned int len) {
    return WriteOfs(static_cast<std::int64_t>(position), buffer, len);
}

unsigned int idFile_MTP::WriteOfs(const std::int64_t offset,
        const void* buffer, const unsigned int len) {
    if (buffer == nullptr || len <= 0 || offset < 0
            || (mode != FS_WRITE && mode != FS_READ_WRITE
                && mode != FS_APPEND)) return 0;
    std::lock_guard<std::mutex> lock(mtpMutex);
    unsigned int total = 0;
    while (total < len) {
        const unsigned int chunk = (std::min)(
            static_cast<unsigned int>(mtpWriteSize), len - total);
        if (!SendRequest(static_cast<std::uint64_t>(offset) + total,
                chunk, OP_WRITE, name.c_str())
                || mtpTCP.WriteBlocking(static_cast<const unsigned char*>(buffer)
                    + total, static_cast<int>(chunk), mtpTimeout)
                    != static_cast<int>(chunk)) {
            mtpTCP.Close();
            break;
        }
        unsigned char countBytes[4] = {};
        if (mtpTCP.ReadBlocking(countBytes, sizeof(countBytes), mtpTimeout)
                != sizeof(countBytes)) {
            mtpTCP.Close();
            break;
        }
        const unsigned int accepted = GetUInt32BE(countBytes);
        if (accepted == 0 || accepted > chunk) {
            mtpTCP.Close();
            break;
        }
        total += accepted;
        if (accepted != chunk) break;
    }
    position = static_cast<std::uint64_t>(offset) + total;
    length = (std::max)(length, position);
    return total;
}

void idFile_MTP::SetLength(const unsigned int len) {
    std::lock_guard<std::mutex> lock(mtpMutex);
    if (SendRequest(0, len, OP_SET_LENGTH, name.c_str())) {
        length = len;
        if (position > length) position = length;
    }
}

std::int64_t idFile_MTP::Length() const {
    return static_cast<std::int64_t>(length);
}

std::int64_t idFile_MTP::Tell() const {
    return static_cast<std::int64_t>(position);
}

int idFile_MTP::Seek(const std::int64_t offset, const fsOrigin_t origin) {
    std::int64_t target = 0;
    if (origin == FS_SEEK_CUR) {
        target = static_cast<std::int64_t>(position) + offset;
    } else if (origin == FS_SEEK_END) {
        target = static_cast<std::int64_t>(length) + offset;
    } else if (origin == FS_SEEK_SET) {
        target = offset;
    } else {
        return -1;
    }
    if (target < 0) return -1;
    position = static_cast<std::uint64_t>(target);
    return 0;
}

bool idFile_MTP::List(const char* directory, const char* extension,
        idList<idStr>& list) {
    const char* const safeDirectory = directory == nullptr ? "" : directory;
    const char* const safeExtension = extension == nullptr ? "" : extension;
    fullPath.Format("%s\\*%s", safeDirectory, safeExtension);
    name = fullPath;

    std::lock_guard<std::mutex> lock(mtpMutex);
    if (!SendRequest(0, 0, OP_LIST, name.c_str())) return false;
    unsigned char lengthBytes[4] = {};
    if (mtpTCP.ReadBlocking(lengthBytes, sizeof(lengthBytes), mtpTimeout)
            != sizeof(lengthBytes)) {
        mtpTCP.Close();
        return false;
    }
    const unsigned int byteCount = GetUInt32BE(lengthBytes);
    if (byteCount > 16u * 1024u * 1024u) return false;
    std::vector<char> entries(byteCount);
    if (byteCount > 0 && mtpTCP.ReadBlocking(entries.data(),
            static_cast<int>(byteCount), mtpTimeout)
            != static_cast<int>(byteCount)) {
        mtpTCP.Close();
        return false;
    }
    unsigned int cursor = 0;
    while (cursor < byteCount) {
        const char* const entry = entries.data() + cursor;
        const std::size_t remaining = byteCount - cursor;
        const std::size_t entryLength = strnlen(entry, remaining);
        if (entryLength == remaining) return false;
        list.Append(idStr(entry));
        cursor += static_cast<unsigned int>(entryLength + 1);
    }
    return true;
}
