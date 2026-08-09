#pragma once

#include "decls/decltypeinfo.h"
#include "idlib/geometry/jointtransform.h"
#include "idlib/index.h"
#include "idlib/math/vector.h"

class idDeclAF;
class idDeclMD6;
class idFile;
class idMaterial;
class idParser;
enum invalidJointIndex_t : int;

enum declAFConstraintType_t : int {
    DECLAF_CONSTRAINT_INVALID = 0,
    DECLAF_CONSTRAINT_FIXED = 1,
    DECLAF_CONSTRAINT_BALLANDSOCKETJOINT = 2,
    DECLAF_CONSTRAINT_UNIVERSALJOINT = 3,
    DECLAF_CONSTRAINT_HINGE = 4,
    DECLAF_CONSTRAINT_SLIDER = 5,
    DECLAF_CONSTRAINT_SPRING = 6
};

enum declAFJointMod_t : int {
    DECLAF_JOINTMOD_AXIS = 0,
    DECLAF_JOINTMOD_ORIGIN = 1,
    DECLAF_JOINTMOD_BOTH = 2
};

class alignas(4) idAFVector {
public:
    enum afVectorType_t : int {
        VEC_COORDS = 0,
        VEC_JOINT = 1,
        VEC_BONECENTER = 2,
        VEC_BONEDIR = 3
    };

    idAFVector();
    bool Parse(idParser& parser);
    bool Write(idFile& file) const;
    bool Finish(const char* fileName, getJointTransform_t getJointTransform,
        const idJointMat* frame, void* model);

    afVectorType_t type;
    idAtomicString joint1;
    idAtomicString joint2;
    idVec3 vec;
    bool negate;
};

class alignas(4) idDeclAF_Body {
public:
    idDeclAF_Body();
    void SetDefault(const idDeclAF* declaration);

    idAtomicString name;
    idAtomicString jointName;
    declAFJointMod_t jointMod;
    int modelType;
    idAtomicString modelName;
    idAFVector v1;
    idAFVector v2;
    int numSides;
    float width;
    float density;
    idAFVector origin;
    idAngles angles;
    int contents;
    int clipMask;
    bool selfCollision;
    bool noSyncCollide;
    bool clearClipMaskInSolid;
    float bouncyness;
    idMat3 inertiaScale;
    float linearFriction;
    float angularFriction;
    float contactFriction;
    idAtomicString containedJoints;
    idAFVector frictionDirection;
    idAFVector contactMotorDirection;
    idList<idIndex<short, invalidJointIndex_t>, 71> containedJointIndices;
};

class alignas(4) idDeclAF_Constraint {
public:
    enum afConstraintLimit_t : int {
        LIMIT_NONE = -1,
        LIMIT_CONE = 0,
        LIMIT_PYRAMID = 1
    };

    idDeclAF_Constraint();
    void SetDefault(const idDeclAF* declaration);

    idAtomicString name;
    idAtomicString body1;
    idAtomicString body2;
    declAFConstraintType_t type;
    float friction;
    float stretch;
    float compress;
    float damping;
    float restLength;
    float minLength;
    float maxLength;
    idAFVector anchor;
    idAFVector anchor2;
    idAFVector shaft[2];
    idAFVector axis;
    afConstraintLimit_t limit;
    idAFVector limitAxis;
    float limitAngles[3];
    bool syncConstraint;
};

class alignas(4) idDeclAF : public idDecl {
public:
    struct solverConstants_t {
        float errorReduction;
        float errorReductionMax;
        float lcpEpsilon;
        float limitErrorReduction;
        float limitErrorReductionMax;
        float limitLcpEpsilon;
        float contactErrorReduction;
        float contactErrorReductionMax;
        float contactLcpEpsilon;
        float universalErrorReduction;
        float universalErrorReductionMax;
        float universalTorsionLcpEpsilon;
    };

    idDeclAF();
    ~idDeclAF() override;

    idDeclInfo* GetDeclInfo() const override;
    bool RebuildTextSource() override;
    const char* DefaultDefinition() const override;
    void Parse(idParser* parser) override;
    void FreeData() override;
    unsigned int Size() const override;

    virtual void Finish(getJointTransform_t getJointTransform,
        const idJointMat* frame, void* model);

    static declAFJointMod_t JointModFromString(const char* text);
    static int ContentsFromString(const char* text);
    static const char* ContentsToString(int contents, idStr& text);

    bool modified;
    const idDeclMD6* modelDef;
    idAtomicString skin;
    float defaultBouncyness;
    float defaultLinearFriction;
    float defaultAngularFriction;
    float defaultContactFriction;
    float defaultConstraintFriction;
    idVec2 suspendVelocity;
    idVec2 suspendAcceleration;
    float noMoveTime;
    float noMoveTranslation;
    float noMoveRotation;
    float minMoveTime;
    float maxMoveTime;
    int contents;
    int clipMask;
    solverConstants_t solverConstants;
    solverConstants_t syncSolverConstants;
    bool selfCollision;
    idAtomicString base;
    const idMaterial* clipMaterial;
    idList<idDeclAF_Body*, 71> bodies;
    idList<idDeclAF_Constraint*, 71> constraints;

    static idDeclInfoTemplate<idDeclAF> resourceList;

private:
    bool ParseSolverConstants(idParser& parser, solverConstants_t& constants);
    bool ParseContents(idParser& parser, int& result) const;
    bool ParseSettings(idParser& parser);
    bool ParseBody(idParser& parser);
    bool ParseConstraint(idParser& parser, declAFConstraintType_t type);
    void WriteSolverConstants(idFile& file, const solverConstants_t& constants,
        const char* name, const char* indent) const;
    bool WriteSettings(idFile& file) const;
    bool WriteBody(idFile& file, const idDeclAF_Body& body) const;
    bool WriteConstraint(idFile& file,
        const idDeclAF_Constraint& constraint) const;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAFVector) == 28,
    "Recovered AF vector ABI changed");
static_assert(sizeof(idDeclAF_Body) == 268,
    "Recovered AF body ABI changed");
static_assert(sizeof(idDeclAF_Constraint) == 232,
    "Recovered AF constraint ABI changed");
static_assert(sizeof(idDeclAF::solverConstants_t) == 48,
    "Recovered AF solver constants ABI changed");
static_assert(sizeof(idDeclAF) == 272,
    "Recovered articulated-figure declaration ABI changed");
#endif
