#include "models/skeletalanimation/md6phasetrack.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "models/skeletalanimation/md6anim.h"
#include "models/skeletalanimation/md6skel.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <malloc.h>
#include <new>
#include <string>
#include <vector>

namespace {

constexpr unsigned int PHASE_TRACK_ALIGNMENT = 16;
constexpr unsigned int MAX_PHASE_TRACK_SIZE = 0xFFFFu;

unsigned int Align16(const unsigned int value) {
    return (value + 15u) & ~15u;
}

bool ReadExact(idFile* file, void* data, const unsigned int length) {
    return length == 0 || (file != nullptr && file->Read(data, length) == length);
}

bool WriteExact(idFile* file, const void* data, const unsigned int length) {
    return length == 0 || (file != nullptr && file->Write(data, length) == length);
}

std::vector<std::string> Tokenize(const char* text, const std::size_t length) {
    std::vector<std::string> tokens;
    std::size_t index = 0;
    while (index < length) {
        while (index < length && std::isspace(
                static_cast<unsigned char>(text[index]))) ++index;
        if (index >= length) break;
        if (text[index] == '/' && index + 1 < length && text[index + 1] == '/') {
            while (index < length && text[index] != '\n') ++index;
            continue;
        }
        if (text[index] == '{' || text[index] == '}') {
            tokens.emplace_back(1, text[index++]);
            continue;
        }
        if (text[index] == '"') {
            const std::size_t begin = ++index;
            while (index < length && text[index] != '"') ++index;
            tokens.emplace_back(text + begin, index - begin);
            if (index < length) ++index;
            continue;
        }
        const std::size_t begin = index;
        while (index < length && !std::isspace(
                static_cast<unsigned char>(text[index])) &&
                text[index] != '{' && text[index] != '}') ++index;
        tokens.emplace_back(text + begin, index - begin);
    }
    return tokens;
}

int FindToken(const std::vector<std::string>& tokens, const char* value,
        const int first = 0) {
    for (int index = (std::max)(0, first);
            index < static_cast<int>(tokens.size()); ++index) {
        if (tokens[index] == value) return index;
    }
    return -1;
}

bool ParseInt(const std::string& token, int& value) {
    char* end = nullptr;
    const long parsed = std::strtol(token.c_str(), &end, 10);
    if (end == token.c_str() || *end != '\0') return false;
    value = static_cast<int>(parsed);
    return true;
}

bool ParseFloat(const std::string& token, float& value) {
    char* end = nullptr;
    value = std::strtof(token.c_str(), &end);
    return end != token.c_str() && *end == '\0';
}

} // namespace

idMD6PhaseTrack::GenerateCallback idMD6PhaseTrack::generateCallback = nullptr;

idMD6PhaseTrack::idMD6PhaseTrack() : data(nullptr) {}

idMD6PhaseTrack::~idMD6PhaseTrack() { Free(); }

void idMD6PhaseTrack::Free() {
    if (data != nullptr) _aligned_free(data);
    data = nullptr;
}

phaseTrackData_t* idMD6PhaseTrack::CreatePhaseTrackData(
        const idMD6Skel*, const idMD6Anim*,
        const idList<unsigned char, 5>& phaseTable,
        const idList<float, 5>& distanceTable) const {
    if (phaseTable.Num() < 0 || phaseTable.Num() > 0xFFFF ||
            (distanceTable.Num() != 0 &&
             distanceTable.Num() != phaseTable.Num())) return nullptr;

    const unsigned int phaseOffset = sizeof(phaseTrackData_t);
    const unsigned int distanceOffset = distanceTable.Num() == 0 ? 0u
        : Align16(phaseOffset + phaseTable.Num());
    const unsigned int totalSize = distanceOffset == 0
        ? Align16(phaseOffset + phaseTable.Num())
        : Align16(distanceOffset + distanceTable.Num() * sizeof(float));
    if (totalSize > MAX_PHASE_TRACK_SIZE) return nullptr;

    phaseTrackData_t* result = static_cast<phaseTrackData_t*>(
        _aligned_malloc((std::max)(totalSize, PHASE_TRACK_ALIGNMENT),
            PHASE_TRACK_ALIGNMENT));
    if (result == nullptr) return nullptr;
    std::memset(result, 0, totalSize);
    result->totalSize = static_cast<std::uint16_t>(totalSize);
    result->numFrames = static_cast<std::uint16_t>(phaseTable.Num());
    result->ofsPhaseTable = static_cast<std::uint16_t>(phaseOffset);
    result->ofsDistanceRemainingTable =
        static_cast<std::uint16_t>(distanceOffset);
    if (phaseTable.Num() > 0) {
        std::memcpy(reinterpret_cast<unsigned char*>(result) + phaseOffset,
            phaseTable.Ptr(), phaseTable.Num());
    }
    if (distanceTable.Num() > 0) {
        std::memcpy(reinterpret_cast<unsigned char*>(result) + distanceOffset,
            distanceTable.Ptr(), distanceTable.Num() * sizeof(float));
    }
    return result;
}

bool idMD6PhaseTrack::Create(
        const idList<unsigned char, 5>& phaseTable,
        const idList<float, 5>& distanceTable) {
    phaseTrackData_t* replacement = CreatePhaseTrackData(
        nullptr, nullptr, phaseTable, distanceTable);
    if (replacement == nullptr) return false;
    Free();
    data = replacement;
    return true;
}

bool idMD6PhaseTrack::GetPhase(const int frame, unsigned char& phase) const {
    if (data == nullptr || data->ofsPhaseTable < sizeof(*data) || frame < 0 ||
            frame >= data->numFrames ||
            static_cast<unsigned int>(data->ofsPhaseTable + frame) >=
                data->totalSize) {
        phase = 0;
        return false;
    }
    phase = *(reinterpret_cast<const unsigned char*>(data) +
        data->ofsPhaseTable + frame);
    return true;
}

bool idMD6PhaseTrack::GetDistanceRemaining(const int frame,
        float& distance) const {
    distance = 0.0f;
    if (data == nullptr || data->ofsDistanceRemainingTable == 0 || frame < 0 ||
            frame >= data->numFrames) return false;
    const unsigned int offset = data->ofsDistanceRemainingTable +
        frame * sizeof(float);
    if (offset + sizeof(float) > data->totalSize) return false;
    std::memcpy(&distance,
        reinterpret_cast<const unsigned char*>(data) + offset,
        sizeof(distance));
    return true;
}

bool idMD6PhaseTrack::IsValid(const idMD6Anim* anim) const {
    return data != nullptr && data->ofsPhaseTable >= sizeof(*data) &&
        data->ofsPhaseTable < data->totalSize && anim != nullptr &&
        anim->animData != nullptr &&
        data->numFrames == anim->animData->numFrames;
}

bool idMD6PhaseTrack::LoadBinary(idFile* file) {
    std::uint16_t size = 0;
    if (!ReadExact(file, &size, sizeof(size))) return false;
    if (size == 0) {
        Free();
        return true;
    }
    if (size < sizeof(phaseTrackData_t)) return false;
    phaseTrackData_t* replacement = static_cast<phaseTrackData_t*>(
        _aligned_malloc(size, PHASE_TRACK_ALIGNMENT));
    if (replacement == nullptr) return false;
    std::memset(replacement, 0, size);
    replacement->totalSize = size;
    if (!ReadExact(file, &replacement->numFrames, size - sizeof(size))) {
        _aligned_free(replacement);
        return false;
    }
    const unsigned int phaseEnd = replacement->ofsPhaseTable +
        replacement->numFrames;
    const unsigned int distanceEnd = replacement->ofsDistanceRemainingTable == 0
        ? 0u : replacement->ofsDistanceRemainingTable +
            replacement->numFrames * sizeof(float);
    if (replacement->ofsPhaseTable < sizeof(*replacement) ||
            phaseEnd > size || distanceEnd > size) {
        _aligned_free(replacement);
        return false;
    }
    Free();
    data = replacement;
    return true;
}

bool idMD6PhaseTrack::WriteBinary(idFile* file) const {
    const std::uint16_t zero = 0;
    return data != nullptr
        ? WriteExact(file, data, data->totalSize)
        : WriteExact(file, &zero, sizeof(zero));
}

bool idMD6PhaseTrack::WriteText(const char* fileName, const idMD6Skel* skel,
        const idMD6Anim* anim, const char* leftAnkleJointName,
        const char* rightAnkleJointName, const char* originJointName) const {
    if (fileName == nullptr || data == nullptr || fileSystem == nullptr)
        return false;
    idFile_Memory text(fileName);
    text.Printf("MD6PHASETRACK version 1\ninit {\n");
    text.Printf("\tdependentAnimName \"%s\"\n",
        anim != nullptr ? anim->GetName() : "");
    text.Printf("\tdependentAnimTimestamp %u\n",
        anim != nullptr ? anim->timestamp : 0u);
    text.Printf("\tdependentSkelName \"%s\"\n",
        skel != nullptr ? skel->GetName() : "");
    text.Printf("\tleftAnkleJoint \"%s\"\n",
        leftAnkleJointName != nullptr ? leftAnkleJointName : "");
    text.Printf("\trightAnkleJoint \"%s\"\n",
        rightAnkleJointName != nullptr ? rightAnkleJointName : "");
    text.Printf("\toriginJoint \"%s\"\n",
        originJointName != nullptr ? originJointName : "");
    text.Printf("\tnumFrames %u\n}\nphase {\n\t", data->numFrames);
    for (int frame = 0; frame < data->numFrames; ++frame) {
        if (frame != 0 && frame % 21 == 0) text.Printf("\n\t");
        unsigned char phase = 0;
        GetPhase(frame, phase);
        text.Printf("%u ", static_cast<unsigned int>(phase));
    }
    text.Printf("\n}\n");
    if (data->ofsDistanceRemainingTable != 0) {
        text.Printf("distanceRemaining {\n\t");
        for (int frame = 0; frame < data->numFrames; ++frame) {
            if (frame != 0 && frame % 10 == 0) text.Printf("\n\t");
            float distance = 0.0f;
            GetDistanceRemaining(frame, distance);
            text.Printf("%.9g ", distance);
        }
        text.Printf("\n}\n");
    }
    idFileLocal output(fileSystem->OpenFileWrite(fileName, FSPATH_BASE));
    return output.file != nullptr && WriteExact(output.file, text.GetDataPtr(),
        static_cast<unsigned int>(text.Length()));
}

bool idMD6PhaseTrack::LoadText(const char* fileName,
        const idMD6Anim* anim) {
    if (fileName == nullptr || fileSystem == nullptr) return false;
    idFileLocal input(fileSystem->OpenFileRead(fileName, true, false));
    if (input.file == nullptr || input->Length() <= 0 ||
            input->Length() > 16 * 1024 * 1024) return false;
    std::vector<char> buffer(static_cast<std::size_t>(input->Length()) + 1, 0);
    if (!ReadExact(input.file, buffer.data(),
            static_cast<unsigned int>(input->Length()))) return false;
    const std::vector<std::string> tokens = Tokenize(
        buffer.data(), static_cast<std::size_t>(input->Length()));
    if (tokens.size() < 4 || tokens[0] != "MD6PHASETRACK" ||
            tokens[1] != "version" || tokens[2] != "1") return false;
    const int frameToken = FindToken(tokens, "numFrames");
    int numFrames = 0;
    if (frameToken < 0 || frameToken + 1 >= static_cast<int>(tokens.size()) ||
            !ParseInt(tokens[frameToken + 1], numFrames) || numFrames < 0 ||
            numFrames > 0xFFFF || (anim != nullptr && anim->animData != nullptr &&
             numFrames != anim->animData->numFrames)) return false;

    const int phaseBlock = FindToken(tokens, "phase", frameToken + 1);
    if (phaseBlock < 0 || phaseBlock + 1 >= static_cast<int>(tokens.size()) ||
            tokens[phaseBlock + 1] != "{") return false;
    idList<unsigned char, 5> phases;
    phases.SetNum(numFrames);
    int cursor = phaseBlock + 2;
    for (int frame = 0; frame < numFrames; ++frame, ++cursor) {
        int phase = 0;
        if (cursor >= static_cast<int>(tokens.size()) ||
                !ParseInt(tokens[cursor], phase) || phase < 0 || phase > 255)
            return false;
        phases[frame] = static_cast<unsigned char>(phase);
    }
    if (cursor >= static_cast<int>(tokens.size()) || tokens[cursor] != "}")
        return false;

    idList<float, 5> distances;
    const int distanceBlock = FindToken(tokens, "distanceRemaining", cursor + 1);
    if (distanceBlock >= 0) {
        if (distanceBlock + 1 >= static_cast<int>(tokens.size()) ||
                tokens[distanceBlock + 1] != "{") return false;
        distances.SetNum(numFrames);
        cursor = distanceBlock + 2;
        for (int frame = 0; frame < numFrames; ++frame, ++cursor) {
            if (cursor >= static_cast<int>(tokens.size()) ||
                    !ParseFloat(tokens[cursor], distances[frame])) return false;
        }
        if (cursor >= static_cast<int>(tokens.size()) || tokens[cursor] != "}")
            return false;
    }
    return Create(phases, distances);
}

void idMD6PhaseTrack::SetGenerateCallback(GenerateCallback callback) {
    generateCallback = callback;
}

bool idMD6PhaseTrack::CreateForAnim(const idMD6Skel* skel,
        const idMD6Anim* anim, const char* leftAnkleJointName,
        const char* rightAnkleJointName, const char* originJointName,
        const bool createDistanceTable) {
    if (skel == nullptr || anim == nullptr || anim->animData == nullptr ||
            generateCallback == nullptr) return false;
    idList<unsigned char, 5> phases;
    idList<float, 5> distances;
    if (!generateCallback(skel, anim, leftAnkleJointName,
            rightAnkleJointName, originJointName, createDistanceTable,
            phases, distances) || phases.Num() != anim->animData->numFrames ||
            (createDistanceTable && distances.Num() != phases.Num())) return false;
    return Create(phases, distances);
}

bool idMD6PhaseTrack::GeneratePhaseTrack(const idMD6Skel* skel,
        const idMD6Anim* anim, const char* leftAnkleJointName,
        const char* rightAnkleJointName, const char* originJointName,
        const bool generateDistanceTable) {
    if (skel == nullptr || anim == nullptr) return false;
    idMD6PhaseTrack track;
    if (!track.CreateForAnim(skel, anim, leftAnkleJointName,
            rightAnkleJointName, originJointName, generateDistanceTable))
        return false;
    idStr fileName(anim->GetName());
    fileName.SetFileExtension("ptrack");
    return track.WriteText(fileName.c_str(), skel, anim,
        leftAnkleJointName, rightAnkleJointName, originJointName);
}
