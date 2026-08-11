#pragma once

#include "game/entities/animatedentity.h"

class idDeclAnimWeb;
class idDeclRollBones;

class idAnimWebTesting;
class idTestAnimWeb;
class idTestRollBones;

class idAnimatedFaceServices {
public:
    virtual ~idAnimatedFaceServices() = default;
    virtual void AddBlendVariable(
        idAnimWebTesting&, const char*, float&) {}
    virtual bool ReadBlendVariable(
        const char*, float&) { return false; }
    virtual int GetGameMilliseconds() const { return 0; }
    virtual bool InitializeAnimWeb(
        idTestAnimWeb&, const idDeclAnimWeb*) { return false; }
    virtual void ChangeAnimWebState(
        idTestAnimWeb&, const char*) {}
    virtual void SpawnRollBones(idTestRollBones&,
        const idDeclRollBones*, const char*, bool) {}
};

class idAnimWebTesting {
public:
    idAnimWebTesting();
    virtual ~idAnimWebTesting() = default;

    static void SetServices(idAnimatedFaceServices* services);
    static idAnimatedFaceServices& Services();

    virtual void InternalInitWeb();
    virtual void InternalUpdateScalars(int currentTime);

    float blendBack;
    float blendRight;
    float blendAngle;
};

class idTestAnimWeb : public idAnimatedEntity {
public:
    idTestAnimWeb();

    void InitAnimation();
    void Spawn();
    void Think() override;

    const idDeclAnimWeb* animWebDecl;
    idAnimWebTesting animWeb;
    int lastActionTime;
    bool interact;
};

class idTestRollBones : public idAnimatedEntity {
public:
    idTestRollBones();

    void Spawn();
    void Think() override;

    const idDeclRollBones* rollBonesDecl;
    idStr nameBaseTrack;
    bool useDualQuatSkinning;
    idAnimAliasHandle baseTrackAlias;
};
