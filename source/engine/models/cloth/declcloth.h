#pragma once

#include "decls/decl.h"
#include "idlib/index.h"
#include "models/cloth/clothsim.h"

#include <cstdint>

class idDeclFX;
class idDeclMD6;
class idMaterial;
enum invalidJointIndex_t : int;

class idDeclCloth : public idDecl {
public:
    class ropeInfo {
    public:
        idList<idVec3, 5> positions;
        idList<idMat3, 5> inverseAxis;
        idList<idIndex<short, invalidJointIndex_t>, 5>
            indexOfJointToAttachTo;
    };

    struct alignas(4) particleInfo_t {
        idVec3 position;
        idIndex<short, invalidJointIndex_t> jointIndex;
        int forwardIndex;
        int rightIndex;
        bool anchored;
    };

    struct springInfo_t {
        std::uint8_t index1;
        std::uint8_t index2;
    };

    using MaterialResolver = const idMaterial* (*)(const char* name,
        bool makeDefault);
    using MD6Resolver = const idDeclMD6* (*)(const char* name,
        bool makeDefault);
    using FXResolver = const idDeclFX* (*)(const char* name,
        bool makeDefault);
    using JointResolver = bool (*)(const idDeclMD6* md6,
        const char* jointName, idIndex<short, invalidJointIndex_t>& index,
        idVec3& position, idMat3& inverseAxis);
    using RopeChainResolver = bool (*)(const idDeclMD6* md6,
        const char* firstJointName, int count, ropeInfo& rope);

    idDeclCloth();
    ~idDeclCloth() override = default;

    idDeclInfo* GetDeclInfo() const override;
    const char* DefaultDefinition() const override;
    void Parse(idParser* parser) override;
    void FreeData() override;

    static void SetMaterialResolver(MaterialResolver resolver);
    static void SetMD6Resolver(MD6Resolver resolver);
    static void SetFXResolver(FXResolver resolver);
    static void SetJointResolver(JointResolver resolver);
    static void SetRopeChainResolver(RopeChainResolver resolver);

    int width;
    int height;
    float vSpacing;
    float hSpacing;
    float gravity;
    float mass;
    float friction;
    float collisionFriction;
    float springLength;
    float springFriction;
    float springMaxLengthMultiplier;
    clothType_t type;
    clothSprings_t springType;
    const idMaterial* material;
    const idDeclMD6* clothMD6;
    const idDeclFX* clothDeclFX;
    bool md6IsBound;
    idList<ropeInfo, 5> ropeData;
    idList<particleInfo_t, 5> particleData;
    idList<springInfo_t, 5> springData;

    static idDeclInfoTemplate<idDeclCloth> resourceList;

private:
    void ResetValues();

    static MaterialResolver materialResolver;
    static MD6Resolver md6Resolver;
    static FXResolver fxResolver;
    static JointResolver jointResolver;
    static RopeChainResolver ropeChainResolver;
};

static_assert(sizeof(idDeclCloth::particleInfo_t) == 28,
    "Recovered cloth particle-info ABI changed");
static_assert(sizeof(idDeclCloth::springInfo_t) == 2,
    "Recovered cloth spring-info ABI changed");
