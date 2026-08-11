#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"

#include <cstdint>

class idDeclParticle;
class idEntity;
class idMaterial;
class idSoundShader;
class idDoor_Laser;

struct idDoorLaserBar {
    int behavior = 0;
    idVec3 startRelativePosition{0.0f, 0.0f, 0.0f};
    idVec3 endRelativePosition{0.0f, 0.0f, 0.0f};
    float openDelay = 0.0f;
    float openSpeed = 0.0f;
    float closeDelay = 0.0f;
    float closeSpeed = 0.0f;
    float recloseDelay = 0.0f;
    float recloseSpeed = 0.0f;
    int numParts = 1;
    idVec3 startPosition{0.0f, 0.0f, 0.0f};
    idVec3 endPosition{0.0f, 0.0f, 0.0f};
    float openPercent[2] = {0.0f, 0.0f};
    std::uint64_t clipQuery[2] = {~0ULL, ~0ULL};
    int startOpenCloseTime = 0;
    int nextSparkTime = 0;
};

class idDoorLaserServices {
public:
    virtual ~idDoorLaserServices() = default;
    virtual int GetGameMilliseconds() const;
    virtual int GetGameMillisecondsPerFrame() const;
    virtual bool UpdateDormant(idDoor_Laser& door);
    virtual float RandomFloat();
    virtual float RandomFloat(float minimum, float maximum);
    virtual int RandomInt(int maximum);
    virtual void GetTransform(const idDoor_Laser& door,
        idVec3& origin, idMat3& axis) const;
    virtual void SetPhysicsAxis(idDoor_Laser& door, const idMat3& axis);
    virtual void BecomeActive(idDoor_Laser& door, int flags);
    virtual void StopWeaponSound(idDoor_Laser& door);
    virtual void PlayWeaponSound(idDoor_Laser& door,
        const idSoundShader* sound);
    virtual bool IsTranslationReady(std::uint64_t query) const;
    virtual float GetTranslationFraction(std::uint64_t query);
    virtual std::uint64_t SubmitTranslation(const idDoor_Laser& door,
        const idVec3& start, const idVec3& end, int clipMask);
    virtual void EmitSpark(idDoor_Laser& door,
        const idDeclParticle* particle, int currentTime,
        int millisecondsPerFrame, float diversity,
        const idVec3& position);
    virtual void UpdateBeam(idDoor_Laser& door,
        const idMaterial* material, float height,
        const idVec3& start, const idVec3& end, float fade);
    virtual void ShowEntity(idDoor_Laser& door);
};

class idDoor_Laser {
public:
    using idDoor_LaserBar = idDoorLaserBar;

    idDoor_Laser();
    virtual ~idDoor_Laser();

    static void SetServices(idDoorLaserServices* services);
    static idDoorLaserServices& Services();

    void Spawn();
    virtual void Think();
    void StartAnimatingIfNecessary();
    void Open();
    void Close();
    void Event_Close(idEntity* user);
    void Event_Disable();
    void Event_Activate(idEntity* activator);
    virtual void OnActivate(idEntity* activator);
    virtual void Hide();
    virtual void Show();

    float doorWidth;
    float doorHeight;
    bool startDoorOpenFlag;
    const idSoundShader* openSound;
    const idSoundShader* closeSound;
    const idSoundShader* passThroughSound;
    const idMaterial* barMaterial;
    float barSize;
    idList<const idDeclParticle*, 5> sparkParticles;
    float sparkDelayMin;
    float sparkDelayMax;
    float barOpenExtraPercent;
    float sparkBackExtraPercent;
    idList<idDoorLaserBar, 5> bars;
    bool shouldBeOpenFlag;
    bool barsAnimatingFlag;
    int touchingCount;
    idVec3 origin;
    idMat3 axis;
    int thinkFlags;
};
