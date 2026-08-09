#pragma once

#include "idlib/containers/list.h"

#include <cstdint>

class idFile;
class idMD6Anim;
class idMD6Skel;

struct phaseTrackData_t {
    std::uint16_t totalSize;
    std::uint16_t numFrames;
    std::uint16_t ofsPhaseTable;
    std::uint16_t ofsDistanceRemainingTable;
    std::uint8_t pad[8];
};

class idMD6PhaseTrack {
public:
    using GenerateCallback = bool (*)(const idMD6Skel* skel,
        const idMD6Anim* anim, const char* leftAnkleJointName,
        const char* rightAnkleJointName, const char* originJointName,
        bool createDistanceTable, idList<unsigned char, 5>& phaseTable,
        idList<float, 5>& distanceTable);

    idMD6PhaseTrack();
    ~idMD6PhaseTrack();

    idMD6PhaseTrack(const idMD6PhaseTrack&) = delete;
    idMD6PhaseTrack& operator=(const idMD6PhaseTrack&) = delete;

    bool WriteText(const char* fileName, const idMD6Skel* skel,
        const idMD6Anim* anim, const char* leftAnkleJointName,
        const char* rightAnkleJointName, const char* originJointName) const;
    bool GetPhase(int frame, unsigned char& phase) const;
    bool GetDistanceRemaining(int frame, float& distance) const;
    bool IsValid(const idMD6Anim* anim) const;
    bool LoadBinary(idFile* file);
    bool WriteBinary(idFile* file) const;
    bool LoadText(const char* fileName, const idMD6Anim* anim);
    bool Create(const idList<unsigned char, 5>& phaseTable,
        const idList<float, 5>& distanceTable);
    void Free();

    static void SetGenerateCallback(GenerateCallback callback);
    static bool GeneratePhaseTrack(const idMD6Skel* skel,
        const idMD6Anim* anim, const char* leftAnkleJointName,
        const char* rightAnkleJointName, const char* originJointName,
        bool generateDistanceTable);

    phaseTrackData_t* data;

private:
    phaseTrackData_t* CreatePhaseTrackData(const idMD6Skel* skel,
        const idMD6Anim* anim,
        const idList<unsigned char, 5>& phaseTable,
        const idList<float, 5>& distanceTable) const;
    bool CreateForAnim(const idMD6Skel* skel, const idMD6Anim* anim,
        const char* leftAnkleJointName, const char* rightAnkleJointName,
        const char* originJointName, bool createDistanceTable);

    static GenerateCallback generateCallback;
};

static_assert(sizeof(phaseTrackData_t) == 16,
    "Recovered phase-track ABI changed");
