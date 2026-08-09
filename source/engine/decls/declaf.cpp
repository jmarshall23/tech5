#include "decls/declaf.h"

#include "idlib/filesystem/file.h"
#include "idlib/text/lexer.h"
#include "idlib/text/parser.h"
#include "idlib/text/str.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>

const idDeclMD6* Decls_FindMD6Declaration(const char* name);
const char* Decls_MD6DeclarationName(const idDeclMD6* declaration);
const idMaterial* Decls_FindMaterial(const char* name);
const char* Decls_AFMaterialName(const idMaterial* material);
void Decls_AFGetJointList(const idDeclMD6* model, const char* expression,
    idList<idIndex<short, invalidJointIndex_t>, 71>& joints);

namespace {

const char* const defaultAFDefinition =
    "{\n"
    "\tsettings {\n"
    "\t\tmodel \"\"\n"
    "\t\tskin \"\"\n"
    "\t\tdefaultBouncyness 0.3\n"
    "\t\tdefaultLinearFriction 0.01\n"
    "\t\tdefaultAngularFriction 0.01\n"
    "\t\tdefaultContactFriction 0.8\n"
    "\t\tdefaultConstraintFriction 0.5\n"
    "\t\tsuspendSpeed 20, 30, 40, 60\n"
    "\t\tnoMoveTime 1\n"
    "\t\tnoMoveTranslation 10\n"
    "\t\tnoMoveRotation 10\n"
    "\t\tminMoveTime -1\n"
    "\t\tmaxMoveTime -1\n"
    "\t\tcontents corpse\n"
    "\t\tclipMask solid, corpse\n"
    "\t\tselfCollision 1\n"
    "\t\tbase \"origin\"\n"
    "\t}\n"
    "\tbody \"body\" {\n"
    "\t\tjoint \"origin\"\n"
    "\t\tmod orientation\n"
    "\t\tmodel box( ( -10, -10, -10 ), ( 10, 10, 10 ) )\n"
    "\t\torigin ( 0, 0, 0 )\n"
    "\t\tdensity 0.2\n"
    "\t\tcontents corpse\n"
    "\t\tclipMask solid, corpse\n"
    "\t\tselfCollision 1\n"
    "\t\tcontainedJoints \"*origin\"\n"
    "\t\tnoSyncCollide 0\n"
    "\t\tclearClipMaskInSolid 0\n"
    "\t}\n"
    "}\n";

const char* JointModName(const declAFJointMod_t value) {
    switch (value) {
    case DECLAF_JOINTMOD_ORIGIN: return "position";
    case DECLAF_JOINTMOD_BOTH: return "both";
    default: return "orientation";
    }
}

std::string Lowercase(const char* const source) {
    std::string result(source != nullptr ? source : "");
    for (char& character : result)
        character = static_cast<char>(std::tolower(
            static_cast<unsigned char>(character)));
    return result;
}

bool ReadAtomic(idParser& parser, idAtomicString& output,
        const bool lower = false) {
    idToken token;
    if (parser.ReadToken(token) == 0) return false;
    if (lower) {
        const std::string text = Lowercase(token.c_str());
        output.Set(text.c_str());
    } else output.Set(token.c_str());
    return true;
}

bool IsClosingBrace(const idToken& token) {
    return idStr::Cmp(token.c_str(), "}") == 0;
}

void WriteVectorLine(idFile& file, const char* const label,
        const idAFVector& vector) {
    file.WriteFloatString("\t%s ", label);
    vector.Write(file);
    file.WriteFloatString("\n");
}

} // namespace

idDeclInfoTemplate<idDeclAF> idDeclAF::resourceList(
    "articulatedFigure", "idDeclAF", "af");

idAFVector::idAFVector()
    : type(VEC_COORDS), joint1(""), joint2(""),
      vec(0.0f, 0.0f, 0.0f), negate(false) {
}

bool idAFVector::Parse(idParser& parser) {
    idToken token;
    if (parser.ReadToken(token) == 0) return false;
    if (idStr::Cmp(token.c_str(), "-") == 0) {
        negate = true;
        if (parser.ReadToken(token) == 0) return false;
    } else negate = false;

    if (idStr::Cmp(token.c_str(), "(") == 0) {
        type = VEC_COORDS;
        vec.x = parser.ParseFloat();
        if (!parser.ExpectTokenString(",")) return false;
        vec.y = parser.ParseFloat();
        if (!parser.ExpectTokenString(",")) return false;
        vec.z = parser.ParseFloat();
        return parser.ExpectTokenString(")") != 0;
    }

    if (idStr::Icmp(token.c_str(), "joint") == 0) {
        type = VEC_JOINT;
        if (!parser.ExpectTokenString("(") || !ReadAtomic(parser, joint1, true))
            return false;
        return parser.ExpectTokenString(")") != 0;
    }

    if (idStr::Icmp(token.c_str(), "bonecenter") == 0
        || idStr::Icmp(token.c_str(), "bonedir") == 0) {
        type = idStr::Icmp(token.c_str(), "bonecenter") == 0
            ? VEC_BONECENTER : VEC_BONEDIR;
        if (!parser.ExpectTokenString("(") || !ReadAtomic(parser, joint1, true)
            || !parser.ExpectTokenString(",")
            || !ReadAtomic(parser, joint2, true)) return false;
        return parser.ExpectTokenString(")") != 0;
    }

    parser.Error("unknown token %s in vector", token.c_str());
    return false;
}

bool idAFVector::Write(idFile& file) const {
    if (negate) file.WriteFloatString("-");
    switch (type) {
    case VEC_COORDS:
        file.WriteFloatString("( %f, %f, %f )", vec.x, vec.y, vec.z);
        break;
    case VEC_JOINT:
        file.WriteFloatString("joint( \"%s\" )", joint1.c_str());
        break;
    case VEC_BONECENTER:
        file.WriteFloatString("bonecenter( \"%s\", \"%s\" )",
            joint1.c_str(), joint2.c_str());
        break;
    case VEC_BONEDIR:
        file.WriteFloatString("bonedir( \"%s\", \"%s\" )",
            joint1.c_str(), joint2.c_str());
        break;
    }
    return true;
}

bool idAFVector::Finish(const char*, const getJointTransform_t transform,
        const idJointMat* const frame, void* const model) {
    idVec3 first(0.0f, 0.0f, 0.0f);
    idVec3 second(0.0f, 0.0f, 0.0f);
    idMat3 axis(1.0f);
    if (type == VEC_JOINT) {
        if (transform == nullptr
            || !transform(model, frame, joint1.c_str(), &vec, &axis))
            vec = idVec3(0.0f, 0.0f, 0.0f);
    } else if (type == VEC_BONECENTER || type == VEC_BONEDIR) {
        if (transform != nullptr) {
            transform(model, frame, joint1.c_str(), &first, &axis);
            transform(model, frame, joint2.c_str(), &second, &axis);
        }
        vec = type == VEC_BONECENTER
            ? (first + second) * 0.5f : second - first;
    }
    if (negate) vec = vec * -1.0f;
    return true;
}

idDeclAF_Body::idDeclAF_Body() : containedJointIndices(16) {
}

void idDeclAF_Body::SetDefault(const idDeclAF* const declaration) {
    name.Set("noname");
    jointName.Set(declaration != nullptr ? declaration->base.c_str() : "origin");
    jointMod = DECLAF_JOINTMOD_AXIS;
    modelType = 1;
    modelName.Set("");
    v1 = idAFVector(); v1.vec = idVec3(-10.0f, -10.0f, -10.0f);
    v2 = idAFVector(); v2.vec = idVec3(10.0f, 10.0f, 10.0f);
    numSides = 3;
    width = 0.0f;
    density = 0.002f;
    origin = idAFVector();
    angles = idAngles(0.0f, 0.0f, 0.0f);
    contents = declaration != nullptr ? declaration->contents : 0x1000;
    clipMask = declaration != nullptr ? declaration->clipMask : 0x1001;
    selfCollision = declaration == nullptr || declaration->selfCollision;
    noSyncCollide = false;
    clearClipMaskInSolid = false;
    bouncyness = declaration != nullptr ? declaration->defaultBouncyness : 0.3f;
    inertiaScale = idMat3(1.0f);
    linearFriction = declaration != nullptr ? declaration->defaultLinearFriction : 0.01f;
    angularFriction = declaration != nullptr ? declaration->defaultAngularFriction : 0.01f;
    contactFriction = declaration != nullptr ? declaration->defaultContactFriction : 0.8f;
    containedJoints.Set("*origin");
    frictionDirection = idAFVector();
    contactMotorDirection = idAFVector();
    containedJointIndices.Clear();
}

idDeclAF_Constraint::idDeclAF_Constraint() = default;

void idDeclAF_Constraint::SetDefault(const idDeclAF* const declaration) {
    name.Set("noname");
    type = DECLAF_CONSTRAINT_UNIVERSALJOINT;
    body1.Set(declaration != nullptr && declaration->bodies.Num() > 0
        ? declaration->bodies[0]->name.c_str() : "world");
    body2.Set("world");
    friction = declaration != nullptr ? declaration->defaultConstraintFriction : 0.5f;
    stretch = 0.0f; compress = 0.0f; damping = 0.0f;
    restLength = 0.0f; minLength = 0.0f; maxLength = 0.0f;
    anchor = idAFVector();
    anchor2 = idAFVector();
    shaft[0] = idAFVector(); shaft[0].vec = idVec3(0.0f, 0.0f, -1.0f);
    shaft[1] = idAFVector(); shaft[1].vec = idVec3(0.0f, 0.0f, 1.0f);
    axis = idAFVector(); axis.vec = idVec3(1.0f, 0.0f, 0.0f);
    limit = LIMIT_NONE;
    limitAxis = idAFVector(); limitAxis.vec = idVec3(0.0f, 0.0f, -1.0f);
    limitAngles[0] = limitAngles[1] = limitAngles[2] = 0.0f;
    syncConstraint = false;
}

idDeclAF::idDeclAF()
    : modified(false), modelDef(nullptr), skin(""), base("origin"),
      clipMaterial(nullptr), bodies(16), constraints(16) {
    solverConstants = { 0.5f, 256.0f, 0.00001f, 0.3f, 256.0f,
        0.0001f, 0.2f, 256.0f, 0.000001f, 0.5f, 256.0f, 0.1f };
    syncSolverConstants = { 0.5f, 512.0f, 0.001f, 0.1f, 128.0f,
        0.000001f, 0.2f, 256.0f, 0.000001f, 0.5f, 512.0f, 0.1f };
    FreeData();
}

idDeclAF::~idDeclAF() { FreeData(); }

idDeclInfo* idDeclAF::GetDeclInfo() const { return &resourceList; }

const char* idDeclAF::DefaultDefinition() const { return defaultAFDefinition; }

void idDeclAF::FreeData() {
    modified = false;
    defaultBouncyness = 0.3f;
    defaultLinearFriction = 0.01f;
    defaultAngularFriction = 0.01f;
    defaultContactFriction = 0.8f;
    defaultConstraintFriction = 0.5f;
    suspendVelocity = idVec2(20.0f, 30.0f);
    suspendAcceleration = idVec2(40.0f, 60.0f);
    noMoveTime = 1.0f;
    noMoveTranslation = 10.0f;
    noMoveRotation = 10.0f;
    minMoveTime = -1.0f;
    maxMoveTime = -1.0f;
    contents = 0x1000;
    clipMask = 0x1001;
    selfCollision = true;
    for (int index = 0; index < bodies.Num(); ++index) delete bodies[index];
    for (int index = 0; index < constraints.Num(); ++index) delete constraints[index];
    bodies.ClearFree();
    constraints.ClearFree();
    base.Set("origin");
    clipMaterial = nullptr;
}

unsigned int idDeclAF::Size() const {
    unsigned int bytes = static_cast<unsigned int>(sizeof(*this)
        + bodies.MemoryUsed() + constraints.MemoryUsed());
    for (int index = 0; index < bodies.Num(); ++index) {
        bytes += sizeof(idDeclAF_Body);
        bytes += bodies[index]->containedJointIndices.MemoryUsed();
    }
    bytes += static_cast<unsigned int>(constraints.Num()
        * sizeof(idDeclAF_Constraint));
    return bytes;
}

declAFJointMod_t idDeclAF::JointModFromString(const char* const text) {
    if (idStr::Icmp(text, "position") == 0) return DECLAF_JOINTMOD_ORIGIN;
    if (idStr::Icmp(text, "both") == 0) return DECLAF_JOINTMOD_BOTH;
    return DECLAF_JOINTMOD_AXIS;
}

int idDeclAF::ContentsFromString(const char* const text) {
    if (text == nullptr) return 0;
    idLexer lexer;
    lexer.LoadMemory(text, static_cast<unsigned int>(std::strlen(text)),
        "idDeclAF::ContentsFromString");
    idToken token;
    int result = 0;
    while (lexer.ReadToken(token)) {
        const char* const value = token.c_str();
        if (idStr::Icmp(value, "none") == 0 || idStr::Cmp(value, ",") == 0)
            continue;
        if (idStr::Icmp(value, "solid") == 0) result |= 0x0001;
        else if (idStr::Icmp(value, "ikclip") == 0) result |= 0x0100;
        else if (idStr::Icmp(value, "ai") == 0) result |= 0x0400;
        else if (idStr::Icmp(value, "corpse") == 0) result |= 0x1000;
        else if (idStr::Icmp(value, "player") == 0) result |= 0x8000;
        else if (idStr::Icmp(value, "playerclip") == 0) result |= 0x0008;
        else if (idStr::Icmp(value, "monsterclip") == 0) result |= 0x0010;
        else break;
    }
    return result;
}

const char* idDeclAF::ContentsToString(const int contentsValue, idStr& text) {
    text.Clear();
    struct Entry { int flag; const char* name; };
    static const Entry entries[] = {
        { 0x0001, "solid" }, { 0x0100, "ikclip" }, { 0x0400, "ai" },
        { 0x1000, "corpse" }, { 0x8000, "player" },
        { 0x0008, "playerclip" }, { 0x0010, "monsterclip" }
    };
    for (const Entry& entry : entries) {
        if ((contentsValue & entry.flag) == 0) continue;
        if (text.Length() != 0) text.Append(", ");
        text.Append(entry.name);
    }
    if (text.Length() == 0) text = "none";
    return text.c_str();
}

bool idDeclAF::ParseContents(idParser& parser, int& result) const {
    idStr expression;
    idToken token;
    while (parser.ReadToken(token) != 0) {
        expression.Append(token.c_str());
        if (parser.CheckTokenString(",") == 0) break;
        expression.Append(",");
    }
    result = ContentsFromString(expression.c_str());
    return true;
}

bool idDeclAF::ParseSolverConstants(idParser& parser,
        solverConstants_t& constants) {
    if (!parser.ExpectTokenString("{")) return false;
    idToken token;
    while (parser.ReadToken(token) != 0 && !IsClosingBrace(token)) {
        const char* const key = token.c_str();
        float* destination = nullptr;
        if (idStr::Icmp(key, "errorReduction") == 0) destination = &constants.errorReduction;
        else if (idStr::Icmp(key, "errorReductionMax") == 0) destination = &constants.errorReductionMax;
        else if (idStr::Icmp(key, "lcpEpsilon") == 0) destination = &constants.lcpEpsilon;
        else if (idStr::Icmp(key, "limitErrorReduction") == 0) destination = &constants.limitErrorReduction;
        else if (idStr::Icmp(key, "limitErrorReductionMax") == 0) destination = &constants.limitErrorReductionMax;
        else if (idStr::Icmp(key, "limitLcpEpsilon") == 0) destination = &constants.limitLcpEpsilon;
        else if (idStr::Icmp(key, "contactErrorReduction") == 0) destination = &constants.contactErrorReduction;
        else if (idStr::Icmp(key, "contactErrorReductionMax") == 0) destination = &constants.contactErrorReductionMax;
        else if (idStr::Icmp(key, "contactLcpEpsilon") == 0) destination = &constants.contactLcpEpsilon;
        else if (idStr::Icmp(key, "universalErrorReduction") == 0) destination = &constants.universalErrorReduction;
        else if (idStr::Icmp(key, "universalErrorReductionMax") == 0) destination = &constants.universalErrorReductionMax;
        else if (idStr::Icmp(key, "universalTorsionLcpEpsilon") == 0) destination = &constants.universalTorsionLcpEpsilon;
        else { parser.Error("unknown token in solver constants: %s", key); return false; }
        *destination = parser.ParseFloat();
    }
    return true;
}

bool idDeclAF::ParseSettings(idParser& parser) {
    if (!parser.ExpectTokenString("{")) return false;
    idToken token;
    while (parser.ReadToken(token) != 0 && !IsClosingBrace(token)) {
        const char* const key = token.c_str();
        if (idStr::Icmp(key, "mesh") == 0 || idStr::Icmp(key, "anim") == 0) {
            parser.ReadToken(token);
        } else if (idStr::Icmp(key, "model") == 0) {
            if (parser.ReadToken(token) == 0) return false;
            modelDef = Decls_FindMD6Declaration(token.c_str());
        } else if (idStr::Icmp(key, "clipMaterial") == 0) {
            if (parser.ReadToken(token) == 0) return false;
            clipMaterial = Decls_FindMaterial(token.c_str());
        } else if (idStr::Icmp(key, "skin") == 0) {
            if (!ReadAtomic(parser, skin)) return false;
        } else if (idStr::Icmp(key, "defaultBouncyness") == 0) defaultBouncyness = parser.ParseFloat();
        else if (idStr::Icmp(key, "defaultLinearFriction") == 0) defaultLinearFriction = parser.ParseFloat();
        else if (idStr::Icmp(key, "defaultAngularFriction") == 0) defaultAngularFriction = parser.ParseFloat();
        else if (idStr::Icmp(key, "defaultContactFriction") == 0) defaultContactFriction = parser.ParseFloat();
        else if (idStr::Icmp(key, "defaultConstraintFriction") == 0) defaultConstraintFriction = parser.ParseFloat();
        else if (idStr::Icmp(key, "suspendSpeed") == 0) {
            suspendVelocity.x = parser.ParseFloat(); parser.ExpectTokenString(",");
            suspendVelocity.y = parser.ParseFloat(); parser.ExpectTokenString(",");
            suspendAcceleration.x = parser.ParseFloat(); parser.ExpectTokenString(",");
            suspendAcceleration.y = parser.ParseFloat();
        } else if (idStr::Icmp(key, "noMoveTime") == 0) noMoveTime = parser.ParseFloat();
        else if (idStr::Icmp(key, "noMoveTranslation") == 0) noMoveTranslation = parser.ParseFloat();
        else if (idStr::Icmp(key, "noMoveRotation") == 0) noMoveRotation = parser.ParseFloat();
        else if (idStr::Icmp(key, "minMoveTime") == 0) minMoveTime = parser.ParseFloat();
        else if (idStr::Icmp(key, "maxMoveTime") == 0) maxMoveTime = parser.ParseFloat();
        else if (idStr::Icmp(key, "contents") == 0) ParseContents(parser, contents);
        else if (idStr::Icmp(key, "clipMask") == 0) ParseContents(parser, clipMask);
        else if (idStr::Icmp(key, "selfCollision") == 0) selfCollision = parser.ParseBool();
        else if (idStr::Icmp(key, "base") == 0) {
            if (!ReadAtomic(parser, base, true)) return false;
        } else if (idStr::Cmp(key, "solverConstants") == 0) {
            if (!ParseSolverConstants(parser, solverConstants)) return false;
        } else if (idStr::Cmp(key, "syncSolverConstants") == 0) {
            if (!ParseSolverConstants(parser, syncSolverConstants)) return false;
        } else { parser.Error("unknown token %s in settings", key); return false; }
    }
    return true;
}

bool idDeclAF::ParseBody(idParser& parser) {
    idToken token;
    if (parser.ReadToken(token) == 0) return false;
    idDeclAF_Body* const body = new idDeclAF_Body();
    body->SetDefault(this);
    body->name.Set(token.c_str());
    bodies.Append(body);
    if (idStr::Icmp(body->name.c_str(), "origin") == 0
        || idStr::Icmp(body->name.c_str(), "world") == 0) {
        parser.Error("a body may not be named \"origin\" or \"world\"");
        return false;
    }
    if (!parser.ExpectTokenString("{")) return false;
    bool jointSet = false;
    while (parser.ReadToken(token) != 0 && !IsClosingBrace(token)) {
        const char* const key = token.c_str();
        if (idStr::Icmp(key, "model") == 0) {
            if (parser.ReadToken(token) == 0) return false;
            const char* const modelType = token.c_str();
            if (idStr::Icmp(modelType, "box") == 0) body->modelType = 1;
            else if (idStr::Icmp(modelType, "octahedron") == 0) body->modelType = 2;
            else if (idStr::Icmp(modelType, "dodecahedron") == 0) body->modelType = 3;
            else if (idStr::Icmp(modelType, "cylinder") == 0) body->modelType = 4;
            else if (idStr::Icmp(modelType, "cone") == 0) body->modelType = 5;
            else if (idStr::Icmp(modelType, "bone") == 0) body->modelType = 6;
            else if (idStr::Icmp(modelType, "custom") == 0) body->modelType = 9;
            else { parser.Error("unknown model type %s", modelType); return false; }
            if (!parser.ExpectTokenString("(")) return false;
            if (body->modelType == 9) {
                if (!ReadAtomic(parser, body->modelName)
                    || !parser.ExpectTokenString(",")) return false;
            }
            if (!body->v1.Parse(parser) || !parser.ExpectTokenString(",")
                || !body->v2.Parse(parser)) return false;
            if (body->modelType == 4 || body->modelType == 5) {
                if (!parser.ExpectTokenString(",")) return false;
                body->numSides = parser.ParseInt();
            } else if (body->modelType == 6) {
                if (!parser.ExpectTokenString(",")) return false;
                body->width = parser.ParseFloat();
            }
            if (!parser.ExpectTokenString(")")) return false;
        } else if (idStr::Icmp(key, "origin") == 0) {
            if (!body->origin.Parse(parser)) return false;
        } else if (idStr::Icmp(key, "angles") == 0) {
            idAFVector value;
            if (!value.Parse(parser)) return false;
            body->angles = idAngles(value.vec.x, value.vec.y, value.vec.z);
        } else if (idStr::Icmp(key, "joint") == 0) {
            if (!ReadAtomic(parser, body->jointName, true)) return false;
            jointSet = true;
        } else if (idStr::Icmp(key, "mod") == 0) {
            if (parser.ReadToken(token) == 0) return false;
            body->jointMod = JointModFromString(token.c_str());
        } else if (idStr::Icmp(key, "density") == 0) body->density = parser.ParseFloat();
        else if (idStr::Icmp(key, "inertiaScale") == 0) parser.Parse1DMatrix(9, &body->inertiaScale[0].x);
        else if (idStr::Icmp(key, "linearFriction") == 0) body->linearFriction = parser.ParseFloat();
        else if (idStr::Icmp(key, "angularFriction") == 0) body->angularFriction = parser.ParseFloat();
        else if (idStr::Icmp(key, "contactFriction") == 0) body->contactFriction = parser.ParseFloat();
        else if (idStr::Icmp(key, "contents") == 0) ParseContents(parser, body->contents);
        else if (idStr::Icmp(key, "clipMask") == 0) ParseContents(parser, body->clipMask);
        else if (idStr::Icmp(key, "selfCollision") == 0) body->selfCollision = parser.ParseBool();
        else if (idStr::Icmp(key, "bouncyness") == 0) body->bouncyness = parser.ParseFloat();
        else if (idStr::Icmp(key, "noSyncCollide") == 0) body->noSyncCollide = parser.ParseBool();
        else if (idStr::Icmp(key, "clearClipMaskInSolid") == 0) body->clearClipMaskInSolid = parser.ParseBool();
        else if (idStr::Icmp(key, "containedjoints") == 0) {
            if (!ReadAtomic(parser, body->containedJoints)) return false;
            if (modelDef != nullptr) Decls_AFGetJointList(modelDef,
                body->containedJoints.c_str(), body->containedJointIndices);
        } else if (idStr::Icmp(key, "frictionDirection") == 0) {
            if (!body->frictionDirection.Parse(parser)) return false;
        } else if (idStr::Icmp(key, "contactMotorDirection") == 0) {
            if (!body->contactMotorDirection.Parse(parser)) return false;
        } else { parser.Error("unknown token %s in body", key); return false; }
    }
    if (!jointSet) { parser.Error("no joint set for body"); return false; }
    body->clipMask |= 0x40;
    return true;
}

bool idDeclAF::ParseConstraint(idParser& parser,
        const declAFConstraintType_t constraintType) {
    idToken token;
    if (parser.ReadToken(token) == 0) return false;
    idDeclAF_Constraint* const constraint = new idDeclAF_Constraint();
    constraint->SetDefault(this);
    constraint->type = constraintType;
    constraint->name.Set(token.c_str());
    constraints.Append(constraint);
    if (!parser.ExpectTokenString("{")) return false;
    while (parser.ReadToken(token) != 0 && !IsClosingBrace(token)) {
        const char* const key = token.c_str();
        if (idStr::Icmp(key, "body1") == 0) {
            if (!ReadAtomic(parser, constraint->body1)) return false;
        } else if (idStr::Icmp(key, "body2") == 0) {
            if (!ReadAtomic(parser, constraint->body2)) return false;
        } else if (idStr::Icmp(key, "anchor") == 0
            || idStr::Icmp(key, "anchor1") == 0) {
            if (!constraint->anchor.Parse(parser)) return false;
        } else if (idStr::Icmp(key, "anchor2") == 0) {
            if (!constraint->anchor2.Parse(parser)) return false;
        } else if (idStr::Icmp(key, "axis") == 0) {
            if (!constraint->axis.Parse(parser)) return false;
        } else if (idStr::Icmp(key, "shafts") == 0) {
            if (!constraint->shaft[0].Parse(parser)
                || !parser.ExpectTokenString(",")
                || !constraint->shaft[1].Parse(parser)) return false;
        } else if (idStr::Icmp(key, "conelimit") == 0) {
            if (!constraint->limitAxis.Parse(parser)
                || !parser.ExpectTokenString(",")) return false;
            constraint->limitAngles[0] = parser.ParseFloat();
            if (constraintType == DECLAF_CONSTRAINT_BALLANDSOCKETJOINT) {
                if (!parser.ExpectTokenString(",")
                    || !constraint->shaft[0].Parse(parser)) return false;
            }
            constraint->limit = idDeclAF_Constraint::LIMIT_CONE;
        } else if (idStr::Icmp(key, "pyramidlimit") == 0) {
            if (!constraint->limitAxis.Parse(parser)
                || !parser.ExpectTokenString(",")) return false;
            constraint->limitAngles[0] = parser.ParseFloat(); parser.ExpectTokenString(",");
            constraint->limitAngles[1] = parser.ParseFloat(); parser.ExpectTokenString(",");
            constraint->limitAngles[2] = parser.ParseFloat();
            if (constraintType == DECLAF_CONSTRAINT_BALLANDSOCKETJOINT) {
                if (!parser.ExpectTokenString(",")
                    || !constraint->shaft[0].Parse(parser)) return false;
            }
            constraint->limit = idDeclAF_Constraint::LIMIT_PYRAMID;
        } else if (idStr::Icmp(key, "limit") == 0) {
            constraint->limitAngles[0] = parser.ParseFloat(); parser.ExpectTokenString(",");
            constraint->limitAngles[1] = parser.ParseFloat(); parser.ExpectTokenString(",");
            constraint->limitAngles[2] = parser.ParseFloat();
            constraint->limit = idDeclAF_Constraint::LIMIT_CONE;
        } else if (idStr::Icmp(key, "friction") == 0) constraint->friction = parser.ParseFloat();
        else if (idStr::Icmp(key, "stretch") == 0) constraint->stretch = parser.ParseFloat();
        else if (idStr::Icmp(key, "compress") == 0) constraint->compress = parser.ParseFloat();
        else if (idStr::Icmp(key, "damping") == 0) constraint->damping = parser.ParseFloat();
        else if (idStr::Icmp(key, "restLength") == 0) constraint->restLength = parser.ParseFloat();
        else if (idStr::Icmp(key, "minLength") == 0) constraint->minLength = parser.ParseFloat();
        else if (idStr::Icmp(key, "maxLength") == 0) constraint->maxLength = parser.ParseFloat();
        else if (idStr::Icmp(key, "syncConstraint") == 0) constraint->syncConstraint = parser.ParseBool();
        else { parser.Error("unknown token %s in constraint", key); return false; }
    }
    return true;
}

void idDeclAF::Parse(idParser* const parser) {
    if (parser == nullptr) return;
    idToken token;
    while (parser->ReadToken(token) != 0) {
        const char* const key = token.c_str();
        if (idStr::Cmp(key, "}") == 0) break;
        bool parsed = false;
        if (idStr::Icmp(key, "settings") == 0) parsed = ParseSettings(*parser);
        else if (idStr::Icmp(key, "body") == 0) parsed = ParseBody(*parser);
        else if (idStr::Icmp(key, "fixed") == 0) parsed = ParseConstraint(*parser, DECLAF_CONSTRAINT_FIXED);
        else if (idStr::Icmp(key, "ballAndSocketJoint") == 0) parsed = ParseConstraint(*parser, DECLAF_CONSTRAINT_BALLANDSOCKETJOINT);
        else if (idStr::Icmp(key, "universalJoint") == 0) parsed = ParseConstraint(*parser, DECLAF_CONSTRAINT_UNIVERSALJOINT);
        else if (idStr::Icmp(key, "hinge") == 0) parsed = ParseConstraint(*parser, DECLAF_CONSTRAINT_HINGE);
        else if (idStr::Icmp(key, "slider") == 0) parsed = ParseConstraint(*parser, DECLAF_CONSTRAINT_SLIDER);
        else if (idStr::Icmp(key, "spring") == 0) parsed = ParseConstraint(*parser, DECLAF_CONSTRAINT_SPRING);
        else { parser->Error("unknown keyword %s", key); return; }
        if (!parsed) return;
    }

    for (int first = 0; first < bodies.Num(); ++first)
        for (int second = first + 1; second < bodies.Num(); ++second)
            if (bodies[first]->name == bodies[second]->name)
                parser->Error("two bodies with the same name \"%s\"",
                    bodies[first]->name.c_str());
    for (int first = 0; first < constraints.Num(); ++first) {
        for (int second = first + 1; second < constraints.Num(); ++second)
            if (constraints[first]->name == constraints[second]->name)
                parser->Error("two constraints with the same name \"%s\"",
                    constraints[first]->name.c_str());
        if (constraints[first]->body1.IsEmpty())
            parser->Error("no valid body1 specified for constraint '%s'",
                constraints[first]->name.c_str());
        if (constraints[first]->body2.IsEmpty())
            parser->Error("no valid body2 specified for constraint '%s'",
                constraints[first]->name.c_str());
    }
    for (int index = 0; index < bodies.Num(); ++index) {
        if (bodies[index]->jointName == base) {
            if (index != 0) std::swap(bodies[0], bodies[index]);
            break;
        }
    }
}

void idDeclAF::Finish(const getJointTransform_t transform,
        const idJointMat* const frame, void* const model) {
    for (int index = 0; index < bodies.Num(); ++index) {
        idDeclAF_Body& body = *bodies[index];
        body.v1.Finish(GetName(), transform, frame, model);
        body.v2.Finish(GetName(), transform, frame, model);
        body.origin.Finish(GetName(), transform, frame, model);
        body.frictionDirection.Finish(GetName(), transform, frame, model);
        body.contactMotorDirection.Finish(GetName(), transform, frame, model);
    }
    for (int index = 0; index < constraints.Num(); ++index) {
        idDeclAF_Constraint& constraint = *constraints[index];
        constraint.anchor.Finish(GetName(), transform, frame, model);
        constraint.anchor2.Finish(GetName(), transform, frame, model);
        constraint.shaft[0].Finish(GetName(), transform, frame, model);
        constraint.shaft[1].Finish(GetName(), transform, frame, model);
        constraint.axis.Finish(GetName(), transform, frame, model);
        constraint.limitAxis.Finish(GetName(), transform, frame, model);
    }
}

void idDeclAF::WriteSolverConstants(idFile& file,
        const solverConstants_t& constants, const char* const name,
        const char* const indent) const {
    file.WriteFloatString("%s%s {\n", indent, name);
#define WRITE_AF_CONSTANT(field) \
    file.WriteFloatString("\t%s" #field " %f\n", indent, constants.field)
    WRITE_AF_CONSTANT(errorReduction);
    WRITE_AF_CONSTANT(errorReductionMax);
    WRITE_AF_CONSTANT(lcpEpsilon);
    WRITE_AF_CONSTANT(limitErrorReduction);
    WRITE_AF_CONSTANT(limitErrorReductionMax);
    WRITE_AF_CONSTANT(limitLcpEpsilon);
    WRITE_AF_CONSTANT(contactErrorReduction);
    WRITE_AF_CONSTANT(contactErrorReductionMax);
    WRITE_AF_CONSTANT(contactLcpEpsilon);
    WRITE_AF_CONSTANT(universalErrorReduction);
    WRITE_AF_CONSTANT(universalErrorReductionMax);
    WRITE_AF_CONSTANT(universalTorsionLcpEpsilon);
#undef WRITE_AF_CONSTANT
    file.WriteFloatString("%s}\n", indent);
}

bool idDeclAF::WriteSettings(idFile& file) const {
    idStr contentText;
    file.WriteFloatString("\nsettings {\n");
    file.WriteFloatString("\tmodel \"%s\"\n",
        modelDef != nullptr ? Decls_MD6DeclarationName(modelDef) : "");
    file.WriteFloatString("\tskin \"%s\"\n", skin.c_str());
    if (clipMaterial != nullptr)
        file.WriteFloatString("\tclipMaterial \"%s\"\n",
            Decls_AFMaterialName(clipMaterial));
    file.WriteFloatString("\tdefaultBouncyness %f\n", defaultBouncyness);
    file.WriteFloatString("\tdefaultLinearFriction %f\n", defaultLinearFriction);
    file.WriteFloatString("\tdefaultAngularFriction %f\n", defaultAngularFriction);
    file.WriteFloatString("\tdefaultContactFriction %f\n", defaultContactFriction);
    file.WriteFloatString("\tdefaultConstraintFriction %f\n", defaultConstraintFriction);
    file.WriteFloatString("\tsuspendSpeed %f, %f, %f, %f\n",
        suspendVelocity.x, suspendVelocity.y, suspendAcceleration.x,
        suspendAcceleration.y);
    file.WriteFloatString("\tnoMoveTime %f\n", noMoveTime);
    file.WriteFloatString("\tnoMoveTranslation %f\n", noMoveTranslation);
    file.WriteFloatString("\tnoMoveRotation %f\n", noMoveRotation);
    file.WriteFloatString("\tminMoveTime %f\n", minMoveTime);
    file.WriteFloatString("\tmaxMoveTime %f\n", maxMoveTime);
    file.WriteFloatString("\tcontents %s\n", ContentsToString(contents, contentText));
    file.WriteFloatString("\tclipMask %s\n", ContentsToString(clipMask, contentText));
    file.WriteFloatString("\tselfCollision %d\n", selfCollision ? 1 : 0);
    file.WriteFloatString("\tbase \"%s\"\n", base.c_str());
    WriteSolverConstants(file, solverConstants, "solverConstants", "\t");
    WriteSolverConstants(file, syncSolverConstants, "syncSolverConstants", "\t");
    file.WriteFloatString("}\n");
    return true;
}

bool idDeclAF::WriteBody(idFile& file, const idDeclAF_Body& body) const {
    idStr text;
    static const char* const modelNames[] = {
        "", "box", "octahedron", "dodecahedron", "cylinder", "cone",
        "bone", "", "", "custom"
    };
    file.WriteFloatString("\nbody \"%s\" {\n", body.name.c_str());
    file.WriteFloatString("\tjoint \"%s\"\n", body.jointName.c_str());
    file.WriteFloatString("\tmod %s\n", JointModName(body.jointMod));
    file.WriteFloatString("\tmodel %s( ",
        body.modelType >= 0 && body.modelType < 10 ? modelNames[body.modelType] : "box");
    if (body.modelType == 9)
        file.WriteFloatString("\"%s\", ", body.modelName.c_str());
    body.v1.Write(file); file.WriteFloatString(", "); body.v2.Write(file);
    if (body.modelType == 4 || body.modelType == 5)
        file.WriteFloatString(", %d", body.numSides);
    else if (body.modelType == 6) file.WriteFloatString(", %f", body.width);
    file.WriteFloatString(" )\n");
    WriteVectorLine(file, "origin", body.origin);
    file.WriteFloatString("\tangles ( %f, %f, %f )\n",
        body.angles.pitch, body.angles.yaw, body.angles.roll);
    file.WriteFloatString("\tdensity %f\n", body.density);
    file.WriteFloatString("\tinertiaScale ( %f, %f, %f, %f, %f, %f, %f, %f, %f )\n",
        body.inertiaScale[0].x, body.inertiaScale[0].y, body.inertiaScale[0].z,
        body.inertiaScale[1].x, body.inertiaScale[1].y, body.inertiaScale[1].z,
        body.inertiaScale[2].x, body.inertiaScale[2].y, body.inertiaScale[2].z);
    file.WriteFloatString("\tlinearFriction %f\n", body.linearFriction);
    file.WriteFloatString("\tangularFriction %f\n", body.angularFriction);
    file.WriteFloatString("\tcontactFriction %f\n", body.contactFriction);
    file.WriteFloatString("\tbouncyness %f\n", body.bouncyness);
    file.WriteFloatString("\tcontents %s\n", ContentsToString(body.contents, text));
    file.WriteFloatString("\tclipMask %s\n", ContentsToString(body.clipMask, text));
    file.WriteFloatString("\tselfCollision %d\n", body.selfCollision ? 1 : 0);
    file.WriteFloatString("\tcontainedJoints \"%s\"\n", body.containedJoints.c_str());
    file.WriteFloatString("\tnoSyncCollide %d\n", body.noSyncCollide ? 1 : 0);
    file.WriteFloatString("\tclearClipMaskInSolid %d\n",
        body.clearClipMaskInSolid ? 1 : 0);
    if (body.frictionDirection.vec.LengthSqr() != 0.0f)
        WriteVectorLine(file, "frictionDirection", body.frictionDirection);
    if (body.contactMotorDirection.vec.LengthSqr() != 0.0f)
        WriteVectorLine(file, "contactMotorDirection", body.contactMotorDirection);
    file.WriteFloatString("}\n");
    return true;
}

bool idDeclAF::WriteConstraint(idFile& file,
        const idDeclAF_Constraint& constraint) const {
    static const char* const names[] = {
        "", "fixed", "ballAndSocketJoint", "universalJoint", "hinge",
        "slider", "spring"
    };
    file.WriteFloatString("\n%s \"%s\" {\n", names[constraint.type],
        constraint.name.c_str());
    file.WriteFloatString("\tbody1 \"%s\"\n", constraint.body1.c_str());
    file.WriteFloatString("\tbody2 \"%s\"\n", constraint.body2.c_str());
    if (constraint.type == DECLAF_CONSTRAINT_BALLANDSOCKETJOINT
        || constraint.type == DECLAF_CONSTRAINT_UNIVERSALJOINT
        || constraint.type == DECLAF_CONSTRAINT_HINGE)
        WriteVectorLine(file, "anchor", constraint.anchor);
    if (constraint.type == DECLAF_CONSTRAINT_SPRING) {
        WriteVectorLine(file, "anchor1", constraint.anchor);
        WriteVectorLine(file, "anchor2", constraint.anchor2);
    }
    if (constraint.type == DECLAF_CONSTRAINT_UNIVERSALJOINT) {
        file.WriteFloatString("\tshafts "); constraint.shaft[0].Write(file);
        file.WriteFloatString(", "); constraint.shaft[1].Write(file);
        file.WriteFloatString("\n");
    } else if (constraint.type == DECLAF_CONSTRAINT_HINGE
        && constraint.shaft[0].type == idAFVector::VEC_BONEDIR
        && constraint.shaft[1].type == idAFVector::VEC_BONEDIR) {
        file.WriteFloatString("\tshafts "); constraint.shaft[0].Write(file);
        file.WriteFloatString(", "); constraint.shaft[1].Write(file);
        file.WriteFloatString("\n");
    } else if (constraint.type == DECLAF_CONSTRAINT_HINGE
        || constraint.type == DECLAF_CONSTRAINT_SLIDER)
        WriteVectorLine(file, "axis", constraint.axis);
    if (constraint.type != DECLAF_CONSTRAINT_FIXED)
        file.WriteFloatString("\tfriction %f\n", constraint.friction);
    if (constraint.limit == idDeclAF_Constraint::LIMIT_CONE
        && (constraint.type == DECLAF_CONSTRAINT_BALLANDSOCKETJOINT
            || constraint.type == DECLAF_CONSTRAINT_UNIVERSALJOINT)) {
        file.WriteFloatString("\tconeLimit "); constraint.limitAxis.Write(file);
        file.WriteFloatString(", %f", constraint.limitAngles[0]);
        if (constraint.type == DECLAF_CONSTRAINT_BALLANDSOCKETJOINT) {
            file.WriteFloatString(", "); constraint.shaft[0].Write(file);
        }
        file.WriteFloatString("\n");
    } else if (constraint.limit == idDeclAF_Constraint::LIMIT_PYRAMID) {
        file.WriteFloatString("\tpyramidLimit "); constraint.limitAxis.Write(file);
        file.WriteFloatString(", %f, %f, %f", constraint.limitAngles[0],
            constraint.limitAngles[1], constraint.limitAngles[2]);
        if (constraint.type == DECLAF_CONSTRAINT_BALLANDSOCKETJOINT) {
            file.WriteFloatString(", "); constraint.shaft[0].Write(file);
        }
        file.WriteFloatString("\n");
    } else if (constraint.type == DECLAF_CONSTRAINT_HINGE
        && constraint.limit == idDeclAF_Constraint::LIMIT_CONE)
        file.WriteFloatString("\tlimit %f, %f, %f\n",
            constraint.limitAngles[0], constraint.limitAngles[1],
            constraint.limitAngles[2]);
    if (constraint.type == DECLAF_CONSTRAINT_SPRING) {
        file.WriteFloatString("\tstretch %f\n", constraint.stretch);
        file.WriteFloatString("\tcompress %f\n", constraint.compress);
        file.WriteFloatString("\tdamping %f\n", constraint.damping);
        file.WriteFloatString("\trestLength %f\n", constraint.restLength);
        file.WriteFloatString("\tminLength %f\n", constraint.minLength);
        file.WriteFloatString("\tmaxLength %f\n", constraint.maxLength);
    }
    file.WriteFloatString("\tsyncConstraint %d\n",
        constraint.syncConstraint ? 1 : 0);
    file.WriteFloatString("}\n");
    return true;
}

bool idDeclAF::RebuildTextSource() {
    idFile_Memory file;
    file.WriteFloatString("{\n");
    WriteSettings(file);
    for (int index = 0; index < bodies.Num(); ++index)
        WriteBody(file, *bodies[index]);
    for (int index = 0; index < constraints.Num(); ++index)
        WriteConstraint(file, *constraints[index]);
    file.WriteFloatString("\n}");
    SetText(file.GetDataPtr(), static_cast<int>(file.Length()));
    modified = false;
    return true;
}
