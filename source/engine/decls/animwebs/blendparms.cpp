#include "decls/animwebs/blendparms.h"

#include "idlib/filesystem/file.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>
#include <cmath>
#include <cstring>

const idMD6Anim* AnimWeb_LoadAnim(const char* name, bool makeDefault);
const char* AnimWeb_GetAnimName(const idMD6Anim* animation);
int AnimWeb_GetAnimNumFrames(const idMD6Anim* animation);
bool AnimWeb_ParseOriginBlend(const char* name, char& value);
bool AnimWeb_ParseBlendType(const char* name, char& value);
const char* AnimWeb_GetOriginBlendName(char value);
const char* AnimWeb_GetBlendTypeName(char value);

namespace {

std::int16_t ClampFrame(const int value) {
    return static_cast<std::int16_t>((std::max)(-32767,
        (std::min)(32767, value)));
}

bool TokenIs(const idToken& token, const char* const text) {
    return _stricmp(token.c_str(), text) == 0;
}

} // namespace

blendParms_t::blendParms_t() : parms{} {
    parms.sourceStartFrame = 32767;
}

int blendParms_t::GetDuration() const {
    return static_cast<unsigned short>(parms.destDuration);
}

int blendParms_t::GetDurationMS() const {
    return static_cast<unsigned short>(static_cast<int>(
        static_cast<float>(parms.destDuration) * (1000.0f / 30.0f)));
}

void blendParms_t::Write(idFile_String& file, const char* const indent) const {
    const char* const prefix = indent != nullptr ? indent : "";
    file.Printf("%sblendParms {\n", prefix);
    file.Printf("%s\tsrcAnim \"%s\"\n", prefix,
        parms.srcAnim != nullptr ? AnimWeb_GetAnimName(parms.srcAnim) : "");
    file.Printf("%s\tdestAnim \"%s\"\n", prefix,
        parms.destAnim != nullptr ? AnimWeb_GetAnimName(parms.destAnim) : "");
    file.Printf("%s\tsourceStartFrame %d\n", prefix,
        static_cast<int>(parms.sourceStartFrame));
    file.Printf("%s\tsourceDuration %d\n", prefix,
        static_cast<int>(parms.sourceDuration));
    file.Printf("%s\tdestStartFrame %d\n", prefix,
        static_cast<int>(parms.destStartFrame));
    file.Printf("%s\tdestDuration %d\n", prefix,
        static_cast<int>(parms.destDuration));
    if (parms.originBlend != 0)
        file.Printf("%s\toriginBlend \"%s\"\n", prefix,
            AnimWeb_GetOriginBlendName(parms.originBlend));
    if (parms.blendType != 0)
        file.Printf("%s\tblendType \"%s\"\n", prefix,
            AnimWeb_GetBlendTypeName(parms.blendType));
    if ((parms.flags & BLENDFLAG_SOURCE_END_RELATIVE) != 0)
        file.Printf("%s\tsourceEndRelative\n", prefix);
    if ((parms.flags & BLENDFLAG_DEST_END_RELATIVE) != 0)
        file.Printf("%s\tdestEndRelative\n", prefix);
    file.Printf("%s}\n", prefix);
}

bool blendParms_t::GetRelativeFrames(const idMD6Anim* const anim,
        const bool endRelative, const std::int16_t& inFirstFrame,
        const std::int16_t& inDuration,
        std::int16_t& outFirstRelativeFrame,
        std::int16_t& outLastRelativeFrame) const {
    if (endRelative) {
        if (anim == nullptr) return false;
        outFirstRelativeFrame = static_cast<std::int16_t>(
            AnimWeb_GetAnimNumFrames(anim) - inFirstFrame - 1);
    } else {
        outFirstRelativeFrame = inFirstFrame;
    }
    outLastRelativeFrame = static_cast<std::int16_t>((std::max)(0,
        (std::min)(32767,
            static_cast<int>(outFirstRelativeFrame) + inDuration)));
    return true;
}

bool blendParms_t::GetSourceFrames(const idMD6Anim* const anim,
        std::int16_t& firstFrame, std::int16_t& lastFrame) const {
    return GetRelativeFrames(anim,
        (parms.flags & BLENDFLAG_SOURCE_END_RELATIVE) != 0,
        parms.sourceStartFrame, parms.sourceDuration, firstFrame, lastFrame);
}

bool blendParms_t::GetDestFrames(const idMD6Anim* const anim,
        std::int16_t& firstFrame, std::int16_t& duration) const {
    duration = parms.destDuration;
    std::int16_t lastFrame = 0;
    return GetRelativeFrames(anim,
        (parms.flags & BLENDFLAG_DEST_END_RELATIVE) != 0,
        parms.destStartFrame, parms.destDuration, firstFrame, lastFrame);
}

void blendParms_t::SetDestStartFrame(const int frame) {
    parms.destStartFrame = ClampFrame(frame);
}

void blendParms_t::SetDuration(const int frames) {
    parms.destDuration = ClampFrame(frames);
}

void blendParms_t::SetDurationMS(const int milliseconds) {
    SetDuration(static_cast<int>(static_cast<float>(milliseconds)
        * 30.0f * 0.001f));
}

void blendParms_t::Parse(idDeclAnimWeb*, idDeclAnimWebNode*, const char*,
        const char*, idParser& parser) {
    idToken token;
    if (!parser.ExpectTokenString("{")) return;
    bool sourceLastFrameWasAuthored = false;
    while (parser.ReadToken(token)) {
        if (TokenIs(token, "}")) break;
        if (TokenIs(token, "srcAnim") || TokenIs(token, "destAnim")) {
            const bool source = TokenIs(token, "srcAnim");
            if (parser.ExpectAnyToken(token) == 0) return;
            const idMD6Anim* const anim = token.Length() != 0
                ? AnimWeb_LoadAnim(token.c_str(), true) : nullptr;
            if (source) parms.srcAnim = anim; else parms.destAnim = anim;
        } else if (TokenIs(token, "sourceStartFrame")) {
            parms.sourceStartFrame = ClampFrame(parser.ParseInt());
        } else if (TokenIs(token, "sourceDuration")) {
            parms.sourceDuration = ClampFrame(parser.ParseInt());
        } else if (TokenIs(token, "destStartFrame")) {
            SetDestStartFrame(parser.ParseInt());
        } else if (TokenIs(token, "destDuration")) {
            SetDuration(parser.ParseInt());
        } else if (TokenIs(token, "duration")) {
            SetDuration(static_cast<int>(std::ceil(
                static_cast<float>(parser.ParseInt()) * 0.001f * 30.0f)));
            parms.flags |= BLENDFLAG_CONVERT_DEST_TO_RELATIVE;
        } else if (TokenIs(token, "durationf")) {
            SetDuration(parser.ParseInt());
            parms.flags |= BLENDFLAG_CONVERT_DEST_TO_RELATIVE;
        } else if (TokenIs(token, "srcFirstFrame")) {
            parms.sourceStartFrame = ClampFrame(parser.ParseInt());
            parms.flags |= BLENDFLAG_CONVERT_SOURCE_TO_RELATIVE;
        } else if (TokenIs(token, "srcLastFrame")) {
            parms.sourceDuration = ClampFrame(parser.ParseInt());
            sourceLastFrameWasAuthored = true;
            parms.flags |= BLENDFLAG_CONVERT_DEST_TO_RELATIVE;
        } else if (TokenIs(token, "destFrame")) {
            parms.destStartFrame = ClampFrame(parser.ParseInt());
            parms.flags |= BLENDFLAG_CONVERT_DEST_TO_RELATIVE;
        } else if (TokenIs(token, "originBlend")) {
            if (parser.ExpectAnyToken(token) == 0
                || !AnimWeb_ParseOriginBlend(token.c_str(), parms.originBlend))
                parser.Error("Unknown origin blend type '%s'", token.c_str());
        } else if (TokenIs(token, "blendType")) {
            if (parser.ExpectAnyToken(token) == 0
                || !AnimWeb_ParseBlendType(token.c_str(), parms.blendType))
                parser.Error("Unknown blend type '%s'", token.c_str());
        } else if (TokenIs(token, "sourceEndRelative")) {
            parms.flags |= BLENDFLAG_SOURCE_END_RELATIVE;
        } else if (TokenIs(token, "destEndRelative")) {
            parms.flags |= BLENDFLAG_DEST_END_RELATIVE;
        } else {
            parser.Error("Unknown blendParms parameter '%s'", token.c_str());
        }
    }
    if (sourceLastFrameWasAuthored)
        parms.sourceDuration = static_cast<std::int16_t>(
            parms.sourceDuration - parms.sourceStartFrame);
}
