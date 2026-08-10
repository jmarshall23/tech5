#include "models/skeletalanimation/eyeinfocollection.h"

#include "idlib/filesystem/file.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "models/skeletalanimation/declmd6.h"
#include "models/skeletalanimation/md6model.h"
#include "models/skeletalanimation/md6skel.h"

#include <cstdlib>

namespace {

bool EyeTokenIs(const idToken& token, const char* text) {
    return idStr::Cmp(token.c_str(), text) == 0;
}

} // namespace

idEyeInfo::idEyeInfo()
    : basisJointIndex(static_cast<short>(-1)),
      minEyePitch(-16.0f), maxEyePitch(16.0f),
      minEyeYaw(-23.0f), maxEyeYaw(23.0f),
      lidMinPitch(-15.0f), lidMaxPitch(15.0f),
      lidMinYaw(-21.0f), lidMaxYaw(21.0f) {
    for (perEyeInfo_t& eye : perEyeInfo) {
        eye.focusScale = 0.25f;
        eye.wanderRate = 0.0f;
        eye.maxWanderPitch = 15.0f;
        eye.maxWanderYaw = 15.0f;
        eye.jitterScale = 1.0f;
        eye.slerpScale = 0.5f;
        eye.angleOffset = idAngles();
    }
}

void idEyeInfo::Parse(const idDeclMD6* declaration, idParser& parser,
        int& loadErrors) {
    idToken token;
    if (!parser.ExpectTokenType(TT_STRING, 0, token)) {
        ++loadErrors;
        return;
    }
    name = token.c_str();
    if (!parser.ExpectTokenString("{")) {
        ++loadErrors;
        return;
    }

    while (parser.ReadToken(token)) {
        if (EyeTokenIs(token, "}")) break;
        if (EyeTokenIs(token, "basisJoint")) {
            if (!parser.ExpectTokenType(TT_STRING, 0, token)) {
                ++loadErrors;
                continue;
            }
            basisJointIndex = declaration != nullptr
                    ? declaration->GetJointIndex(token.c_str())
                    : idIndex<short, invalidJointIndex_t>();
        } else if (EyeTokenIs(token, "minPitch")) {
            minEyePitch = parser.ParseFloat();
        } else if (EyeTokenIs(token, "maxPitch")) {
            maxEyePitch = parser.ParseFloat();
        } else if (EyeTokenIs(token, "minYaw")) {
            minEyeYaw = parser.ParseFloat();
        } else if (EyeTokenIs(token, "maxYaw")) {
            maxEyeYaw = parser.ParseFloat();
        } else if (EyeTokenIs(token, "lidMinPitch")) {
            lidMinPitch = parser.ParseFloat();
        } else if (EyeTokenIs(token, "lidMaxPitch")) {
            lidMaxPitch = parser.ParseFloat();
        } else if (EyeTokenIs(token, "lidMinYaw")) {
            lidMinYaw = parser.ParseFloat();
        } else if (EyeTokenIs(token, "lidMaxYaw")) {
            lidMaxYaw = parser.ParseFloat();
        } else {
            int eyeIndex = -1;
            if (idStr::Icmp(token.c_str(), "left") == 0) eyeIndex = 0;
            if (idStr::Icmp(token.c_str(), "right") == 0) eyeIndex = 1;
            if (eyeIndex < 0 || !parser.ExpectTokenString("{")) {
                parser.Error("Unknown token '%s' in modeldef '%s' eyeInfo '%s'",
                    token.c_str(),
                    declaration != nullptr ? declaration->GetName() : "",
                    name.c_str());
                ++loadErrors;
                continue;
            }

            while (parser.ReadToken(token)) {
                if (EyeTokenIs(token, "}")) break;
                perEyeInfo_t& eye = perEyeInfo[eyeIndex];
                if (EyeTokenIs(token, "focusScale")) {
                    eye.focusScale = parser.ParseFloat();
                } else if (EyeTokenIs(token, "wanderRate")) {
                    eye.wanderRate = parser.ParseFloat();
                } else if (EyeTokenIs(token, "maxWanderPitch")) {
                    eye.maxWanderPitch = parser.ParseFloat();
                } else if (EyeTokenIs(token, "maxWanderYaw")) {
                    eye.maxWanderYaw = parser.ParseFloat();
                } else if (EyeTokenIs(token, "jitterScale")) {
                    eye.jitterScale = parser.ParseFloat();
                } else if (EyeTokenIs(token, "slerpScale")) {
                    eye.slerpScale = parser.ParseFloat();
                } else if (EyeTokenIs(token, "angleOffset")) {
                    if (!parser.Parse1DMatrix(3, &eye.angleOffset.pitch))
                        ++loadErrors;
                } else {
                    parser.Error(
                        "Unknown token '%s' in modeldef '%s' eyeInfo '%s'",
                        token.c_str(),
                        declaration != nullptr ? declaration->GetName() : "",
                        name.c_str());
                    ++loadErrors;
                }
            }
        }
    }
}

void idEyeInfo::Write(const idDeclMD6* declaration, idFile_String& file,
        const char* indent) const {
    const char* prefix = indent != nullptr ? indent : "";
    file.Printf("%seyeInfo \"%s\" {\n", prefix, name.c_str());
    const char* basisName = declaration != nullptr
        ? declaration->GetJointName(basisJointIndex) : nullptr;
    file.Printf("%s\tbasisJoint \"%s\"\n", prefix,
        basisName != nullptr ? basisName : "");
    file.Printf("%s\tminPitch %.9g\n", prefix, minEyePitch);
    file.Printf("%s\tmaxPitch %.9g\n", prefix, maxEyePitch);
    file.Printf("%s\tminYaw %.9g\n", prefix, minEyeYaw);
    file.Printf("%s\tmaxYaw %.9g\n", prefix, maxEyeYaw);
    file.Printf("%s\tlidMinPitch %.9g\n", prefix, lidMinPitch);
    file.Printf("%s\tlidMaxPitch %.9g\n", prefix, lidMaxPitch);
    file.Printf("%s\tlidMinYaw %.9g\n", prefix, lidMinYaw);
    file.Printf("%s\tlidMaxYaw %.9g\n", prefix, lidMaxYaw);
    static const char* const eyeNames[2] = {"left", "right"};
    for (int eyeIndex = 0; eyeIndex < 2; ++eyeIndex) {
        const perEyeInfo_t& eye = perEyeInfo[eyeIndex];
        file.Printf("%s\t%s {\n", prefix, eyeNames[eyeIndex]);
        file.Printf("%s\t\tfocusScale %.9g\n", prefix, eye.focusScale);
        file.Printf("%s\t\twanderRate %.9g\n", prefix, eye.wanderRate);
        file.Printf("%s\t\tmaxWanderPitch %.9g\n", prefix,
            eye.maxWanderPitch);
        file.Printf("%s\t\tmaxWanderYaw %.9g\n", prefix,
            eye.maxWanderYaw);
        file.Printf("%s\t\tjitterScale %.9g\n", prefix, eye.jitterScale);
        file.Printf("%s\t\tslerpScale %.9g\n", prefix, eye.slerpScale);
        file.Printf("%s\t\tangleOffset ( %.9g %.9g %.9g )\n", prefix,
            eye.angleOffset.pitch, eye.angleOffset.yaw,
            eye.angleOffset.roll);
        file.Printf("%s\t}\n", prefix);
    }
    file.Printf("%s}\n", prefix);
}

idEyeInfoCollection::idEyeInfoCollection()
    : curHandle(0), eyeInfos(16) {
}

void idEyeInfoCollection::Free() {
    eyeInfos.ClearFree();
    curHandle = 0;
}

void idEyeInfoCollection::Parse(const idDeclMD6* declaration,
        idParser& parser, int& loadErrors) {
    const int count = parser.ParseInt();
    if (count > eyeInfos.NumAllocated()) eyeInfos.Resize(count);

    idToken token;
    if (!parser.ExpectTokenString("{")) {
        ++loadErrors;
        return;
    }
    while (parser.ReadToken(token)) {
        if (EyeTokenIs(token, "}")) break;
        if (!EyeTokenIs(token, "eyeInfo")) {
            parser.Error(
                "Unknown token '%s' in model def '%s' in eye info collection.",
                token.c_str(),
                declaration != nullptr ? declaration->GetName() : "");
            ++loadErrors;
            continue;
        }
        idEyeInfo info;
        info.Parse(declaration, parser, loadErrors);
        AddEyeInfo(info);
    }
    eyeInfos.Resize(eyeInfos.Num());
}

void idEyeInfoCollection::DuplicateInherited(const idDeclMD6*,
        const idEyeInfoCollection* parentCollection) {
    if (parentCollection == nullptr) return;
    for (int inheritedIndex = 0;
            inheritedIndex < parentCollection->eyeInfos.Num();
            ++inheritedIndex) {
        const idEyeInfo& inherited =
            parentCollection->eyeInfos[inheritedIndex];
        if (!FindEyeInfoHandle(inherited.name.c_str()).IsValid())
            AddEyeInfo(inherited);
    }
}

void idEyeInfoCollection::Write(const idDeclMD6* declaration,
        idFile_String& file, const char* indent) const {
    const char* prefix = indent != nullptr ? indent : "";
    file.Printf("%seyeInfoCollection %d {\n", prefix, eyeInfos.Num());
    idStr eyeIndent(prefix);
    eyeIndent.Append("\t");
    const idEyeInfoCollection* parentCollection =
        declaration != nullptr && declaration->parentDecl != nullptr
            ? &declaration->parentDecl->eyeInfoCollection : nullptr;
    for (int index = 0; index < eyeInfos.Num(); ++index) {
        if (!IsInherited(eyeInfos[index], parentCollection))
            eyeInfos[index].Write(declaration, file, eyeIndent.c_str());
    }
    file.Printf("%s}\n", prefix);
}

eyeInfoHandle_t idEyeInfoCollection::AddEyeInfo(const idEyeInfo& info) {
    eyeInfoHandle_t result(curHandle++);
    const int index = eyeInfos.Append(info);
    if (index < 0) {
        result.Invalidate();
        return result;
    }
    eyeInfos[index].handle = result.Get();
    return result;
}

const idEyeInfo* idEyeInfoCollection::GetEyeInfo(
    eyeInfoHandle_t handle) const {
    const int index = FindEyeInfoIndex(handle);
    return index >= 0 ? &eyeInfos[index] : nullptr;
}

eyeInfoHandle_t idEyeInfoCollection::FindEyeInfoHandle(
    const char* searchName) const {
    const int index = FindEyeInfoIndex(searchName);
    return index >= 0 ? eyeInfos[index].handle : eyeInfoHandle_t();
}

int idEyeInfoCollection::FindEyeInfoIndex(
        const eyeInfoHandle_t& handle) const {
    for (int index = 0; index < eyeInfos.Num(); ++index) {
        if (eyeInfos[index].handle == handle) return index;
    }
    return -1;
}

int idEyeInfoCollection::FindEyeInfoIndex(const char* searchName) const {
    if (searchName == nullptr) return -1;
    for (int index = 0; index < eyeInfos.Num(); ++index) {
        if (idStr::Icmp(eyeInfos[index].name.c_str(), searchName) == 0)
            return index;
    }
    return -1;
}

bool idEyeInfoCollection::IsInherited(const idEyeInfo& info,
        const idEyeInfoCollection* parentCollection) const {
    if (parentCollection == nullptr) return false;
    for (int index = 0; index < parentCollection->eyeInfos.Num(); ++index) {
        const idEyeInfo& inherited = parentCollection->eyeInfos[index];
        if (idStr::Cmp(info.name.c_str(), inherited.name.c_str()) == 0 &&
                info.basisJointIndex == inherited.basisJointIndex &&
                info.minEyePitch == inherited.minEyePitch &&
                info.maxEyePitch == inherited.maxEyePitch &&
                info.minEyeYaw == inherited.minEyeYaw &&
                info.maxEyeYaw == inherited.maxEyeYaw &&
                info.lidMinPitch == inherited.lidMinPitch &&
                info.lidMaxPitch == inherited.lidMaxPitch &&
                info.lidMinYaw == inherited.lidMinYaw &&
                info.lidMaxYaw == inherited.lidMaxYaw) {
            return true;
        }
    }
    return false;
}
