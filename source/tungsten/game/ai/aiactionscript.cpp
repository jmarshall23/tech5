#include "aiactionscript.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stdexcept>

namespace {

bool IsPunctuation(const char value) {
    switch (value) {
        case '{': case '}': case '[': case ']': case '=': case ';':
        case '<': case '>': case ',': case '(': case ')':
        case '&': case '*':
            return true;
        default:
            return false;
    }
}

std::string Lower(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(),
        [](const unsigned char character) {
            return static_cast<char>(std::tolower(character));
        });
    return value;
}

std::string ReplaceExtension(const std::string& path,
        const char* const extension) {
    const std::size_t slash = path.find_last_of("/\\");
    const std::size_t dot = path.find_last_of('.');
    if (dot == std::string::npos
        || (slash != std::string::npos && dot < slash)) {
        return path + extension;
    }
    return path.substr(0, dot) + extension;
}

std::string ExtractExtension(const std::string& path) {
    const std::size_t slash = path.find_last_of("/\\");
    const std::size_t dot = path.find_last_of('.');
    if (dot == std::string::npos
        || (slash != std::string::npos && dot < slash)) {
        return std::string();
    }
    return Lower(path.substr(dot + 1));
}

bool ParseTriple(const std::string& text, idVec3& value) {
    std::string normalized = text;
    for (char& character : normalized) {
        if (character == '(' || character == ')' || character == ',') {
            character = ' ';
        }
    }
    std::istringstream stream(normalized);
    return static_cast<bool>(stream >> value.x >> value.y >> value.z);
}

idAIActionParm::subParm_t EnumSubType(const std::string& typeName) {
    struct mapping_t {
        const char* name;
        idAIActionParm::subParm_t type;
    };
    static const mapping_t mappings[] = {
        { "aiArrivalAction_t", idAIActionParm::SP_ARRIVALACTION },
        { "posture_t", idAIActionParm::SP_POSTURE },
        { "coverAction_t", idAIActionParm::SP_COVERACTION },
        { "equipSlot_t", idAIActionParm::SP_EQUIPSLOT },
        { "alertCycle_t", idAIActionParm::SP_ALERTCYCLE },
        { "aiFireMode_t", idAIActionParm::SP_FIREMODE },
        { "aimPoint_t", idAIActionParm::SP_AIMPOINT },
        { "walkState_t", idAIActionParm::SP_WALKSTATE },
        { "aiPlayer_t", idAIActionParm::SP_AIPLAYER },
        { "overrideAnim_t", idAIActionParm::SP_OVERRIDEANIM },
        { "painType_t", idAIActionParm::SP_PAIN },
        { "aiDirection_t", idAIActionParm::SP_AIDIRECTION },
        { "aiDodgeDir_t", idAIActionParm::SP_DODGEDIR },
        { "aiSubWeb_t", idAIActionParm::SP_SUBWEB },
        { "aiActionBool_t", idAIActionParm::SP_ACTIONBOOL }
    };
    for (const mapping_t& mapping : mappings) {
        if (typeName == mapping.name) {
            return mapping.type;
        }
    }
    return idAIActionParm::SP_INTEGER;
}

bool IsSupportedLegacyEnum(const std::string& typeName) {
    return EnumSubType(typeName) != idAIActionParm::SP_INTEGER;
}

// Retail catch helper: $M492308
// EA: 0x82A3E7F8, RVA: 0x00A3E7F8
bool HandleTypeInfoParseFailure(const char* const fileName,
        const char* const message) {
    Tungsten_ActionScriptWarning("Failed to parse map file '%s' - %s",
        fileName, message);
    return false;
}

// Retail catch helper: $M492504
// EA: 0x82A3EC34, RVA: 0x00A3EC34
bool HandleMapParseFailure(const char* const fileName,
        const char* const message) {
    Tungsten_ActionScriptWarning("Failed to parse map file '%s' - %s",
        fileName, message);
    return false;
}

} // namespace

idAIActionParm::idAIActionParm()
    : type(P_NONE)
    , subType(SP_INTEGER)
    , intVal(0)
    , floatVal(0.0f, 0.0f, 0.0f)
    , declVal(nullptr)
    , strVal() {
}

// Retail symbol: ?IsEnum@idAIActionParm@@QBA_NXZ
// EA: 0x82A3B9A8, RVA: 0x00A3B9A8
bool idAIActionParm::IsEnum() const {
    if (subType >= SP_ARRIVALACTION && subType <= SP_ACTIONBOOL) {
        return true;
    }
    switch (subType) {
        case SP_AIVAROP:
        case SP_AIVARTYPE:
        case SP_AIANIMWEB:
        case SP_AIACTIONSCRIPTFLAG:
        case SP_AIPERCEPTIONFLAG:
        case SP_SITSTATE:
        case SP_STANDSTATE:
        case SP_IDLESTATE:
        case SP_SETMOVEPUSHSTATUS:
        case SP_AIMOVEMENTMODE:
        case SP_AIANIMWAIT:
        case SP_AIIDLETURN:
        case SP_ACCURACY:
        case SP_AIMOVEREASON:
        case SP_MOVE_TO_SCENEPOINT_FLAGS:
        case SP_COMMAND_MOVE:
            return true;
        default:
            return false;
    }
}

void idAIActionParm::Clear() {
    type = P_NONE;
    subType = SP_INTEGER;
    intVal = 0;
    floatVal.Zero();
    declVal = nullptr;
    strVal.clear();
}

// Retail symbol: ??0idActionScriptConvertor@@QAA@XZ
// EA: 0x82A3C1B8, RVA: 0x00A3C1B8
idActionScriptConvertor::idActionScriptConvertor()
    : buffer()
    , sourceName("*unknown*")
    , output()
    , cursor(0)
    , startPos(0)
    , numScripts(0)
    , fileType(FT_MAX) {
}

// Retail symbol: ?Begin@idActionScriptConvertor@@AAA_NPBDI0@Z
// EA: 0x82A3C250, RVA: 0x00A3C250
bool idActionScriptConvertor::Begin(const char* const sourceBuffer,
        const std::size_t length, const char* const fileName) {
    if (sourceBuffer == nullptr && length != 0) {
        return false;
    }
    buffer.assign(sourceBuffer != nullptr ? sourceBuffer : "", length);
    sourceName = fileName != nullptr ? fileName : "*memory*";
    output.clear();
    cursor = 0;
    startPos = 0;
    numScripts = 0;
    fileType = FT_MAX;
    return true;
}

// Retail symbol: ?BeginFile@idActionScriptConvertor@@AAA_NPBD@Z
// EA: 0x82A3C2E0, RVA: 0x00A3C2E0
bool idActionScriptConvertor::BeginFile(const char* const fileName) {
    std::string contents;
    if (fileName == nullptr
        || !Tungsten_ReadActionScriptFile(fileName, contents)
        || contents.empty()) {
        Tungsten_ActionScriptWarning("Error reading file.");
        return false;
    }
    if (!Begin(contents.data(), contents.size(), fileName)) {
        Tungsten_ActionScriptWarning("Error lexing file.");
        return false;
    }
    Tungsten_ActionScriptPrint("Parsing '%s'...", fileName);
    return true;
}

bool idActionScriptConvertor::ReadToken(token_t& token) {
    while (cursor < buffer.size()) {
        if (std::isspace(static_cast<unsigned char>(buffer[cursor]))) {
            ++cursor;
            continue;
        }
        if (buffer[cursor] == '/' && cursor + 1 < buffer.size()) {
            if (buffer[cursor + 1] == '/') {
                cursor += 2;
                while (cursor < buffer.size() && buffer[cursor] != '\n') {
                    ++cursor;
                }
                continue;
            }
            if (buffer[cursor + 1] == '*') {
                cursor += 2;
                while (cursor + 1 < buffer.size()
                    && !(buffer[cursor] == '*'
                        && buffer[cursor + 1] == '/')) {
                    ++cursor;
                }
                cursor = (std::min)(buffer.size(), cursor + 2);
                continue;
            }
        }
        break;
    }
    if (cursor >= buffer.size()) {
        return false;
    }

    token = token_t();
    token.begin = cursor;
    const char first = buffer[cursor];
    if (first == '"') {
        token.quoted = true;
        ++cursor;
        while (cursor < buffer.size()) {
            const char character = buffer[cursor++];
            if (character == '"') {
                token.end = cursor;
                return true;
            }
            if (character == '\\' && cursor < buffer.size()) {
                const char escaped = buffer[cursor++];
                switch (escaped) {
                    case 'n': token.text.push_back('\n'); break;
                    case 'r': token.text.push_back('\r'); break;
                    case 't': token.text.push_back('\t'); break;
                    default: token.text.push_back(escaped); break;
                }
            } else {
                token.text.push_back(character);
            }
        }
        ParseFailure("unterminated quoted string");
    }
    if (IsPunctuation(first)) {
        token.text.assign(1, first);
        token.end = ++cursor;
        return true;
    }
    while (cursor < buffer.size()
        && !std::isspace(static_cast<unsigned char>(buffer[cursor]))
        && !IsPunctuation(buffer[cursor])) {
        if (buffer[cursor] == '/' && cursor + 1 < buffer.size()
            && (buffer[cursor + 1] == '/'
                || buffer[cursor + 1] == '*')) {
            break;
        }
        token.text.push_back(buffer[cursor++]);
    }
    token.end = cursor;
    return !token.text.empty();
}

bool idActionScriptConvertor::PeekToken(token_t& token) {
    const std::size_t saved = cursor;
    const bool result = ReadToken(token);
    cursor = saved;
    return result;
}

bool idActionScriptConvertor::CheckToken(const char* const text) {
    token_t token;
    const std::size_t saved = cursor;
    if (ReadToken(token) && token.text == text) {
        return true;
    }
    cursor = saved;
    return false;
}

void idActionScriptConvertor::ExpectToken(const char* const text) {
    token_t token;
    if (!ReadToken(token) || token.text != text) {
        ParseFailure(std::string("expected '") + text + "'");
    }
}

int idActionScriptConvertor::ParseInt() {
    token_t token;
    if (!ReadToken(token)) {
        ParseFailure("expected integer");
    }
    char* end = nullptr;
    const long value = std::strtol(token.text.c_str(), &end, 0);
    if (end == token.text.c_str() || *end != '\0') {
        ParseFailure(std::string("expected integer, found '")
            + token.text + "'");
    }
    return static_cast<int>(value);
}

std::string idActionScriptConvertor::ReadTypeName() {
    token_t token;
    if (!ReadToken(token)) {
        ParseFailure("expected type name");
    }
    std::string result = token.text;
    if (CheckToken("<")) {
        result += '<';
        int depth = 1;
        while (depth > 0) {
            if (!ReadToken(token)) {
                ParseFailure("unterminated template type");
            }
            if (token.text == "<") {
                ++depth;
            } else if (token.text == ">") {
                --depth;
            }
            result += token.text;
        }
    }
    while (true) {
        if (CheckToken("&")) {
            result += '&';
        } else if (CheckToken("*")) {
            result += '*';
        } else {
            break;
        }
    }
    return result;
}

void idActionScriptConvertor::SkipBracedSection(
        const bool openingBraceAlreadyRead) {
    if (!openingBraceAlreadyRead) {
        ExpectToken("{");
    }
    int depth = 1;
    token_t token;
    while (depth > 0 && ReadToken(token)) {
        if (token.text == "{") {
            ++depth;
        } else if (token.text == "}") {
            --depth;
        }
    }
    if (depth != 0) {
        ParseFailure("unterminated braced section");
    }
}

void idActionScriptConvertor::SkipRestOfLine() {
    while (cursor < buffer.size() && buffer[cursor] != '\n') {
        ++cursor;
    }
}

void idActionScriptConvertor::SkipValue() {
    token_t token;
    int depth = 0;
    while (ReadToken(token)) {
        if (token.text == "{") {
            ++depth;
        } else if (token.text == "}") {
            if (depth == 0) {
                ParseFailure("unexpected end of block while skipping value");
            }
            --depth;
        } else if (token.text == ";" && depth == 0) {
            return;
        }
    }
    ParseFailure("unterminated value");
}

void idActionScriptConvertor::ParseFailure(
        const std::string& message) const {
    std::ostringstream text;
    text << sourceName << ':' << cursor << ": " << message;
    throw std::runtime_error(text.str());
}

// Retail symbol: ?ConvertActionParm@idActionScriptConvertor@@AAAXHABVidStr@@AAVidAIActionParm@@@Z
// EA: 0x82A3C428, RVA: 0x00A3C428
void idActionScriptConvertor::ConvertActionParm(const int index,
        const std::string& argType, idAIActionParm& parm) {
    const std::string fieldType = ReadTypeName();
    if (fieldType != "idStr") {
        ParseFailure("expected idStr action parameter");
    }
    token_t token;
    bool foundAssignment = false;
    while (ReadToken(token)) {
        if (token.text == "=") {
            foundAssignment = true;
            break;
        }
        if (token.text == ";" || token.text == "}") {
            ParseFailure("action parameter has no assignment");
        }
    }
    if (!foundAssignment || !ReadToken(token)) {
        ParseFailure("action parameter has no value");
    }
    const std::string value = token.text;
    while (token.text != ";") {
        if (!ReadToken(token)) {
            ParseFailure("unterminated action parameter");
        }
    }
    ConvertActionParmValue(index, argType, value, parm);
}

void idActionScriptConvertor::ConvertActionParmValue(const int,
        const std::string& argType, const std::string& value,
        idAIActionParm& parm) {
    parm.Clear();
    if (argType == "bool") {
        parm.type = idAIActionParm::P_DISCRETE;
        parm.subType = idAIActionParm::SP_BOOL;
        parm.intVal = value == "true" ? 1 : 0;
        return;
    }
    if (argType == "int") {
        parm.type = idAIActionParm::P_DISCRETE;
        parm.subType = idAIActionParm::SP_INTEGER;
        parm.intVal = static_cast<int>(std::strtol(value.c_str(), nullptr, 0));
        return;
    }
    if (argType == "float") {
        parm.type = idAIActionParm::P_FLOAT;
        parm.subType = idAIActionParm::SP_FLOAT;
        parm.floatVal.x = std::strtof(value.c_str(), nullptr);
        return;
    }
    if (argType == "idVec3&" || argType == "idAngles&") {
        if (!ParseTriple(value, parm.floatVal)) {
            ParseFailure(std::string("invalid ") + argType
                + " action parameter");
        }
        parm.type = idAIActionParm::P_FLOAT;
        parm.subType = argType == "idVec3&"
            ? idAIActionParm::SP_VEC3 : idAIActionParm::SP_ANGLES;
        return;
    }
    if (argType == "char*" || argType == "idAnimWebPath&"
        || argType == "aliasHandle_t" || argType == "idEntity*") {
        parm.type = idAIActionParm::P_STRING;
        parm.subType = argType == "char*" ? idAIActionParm::SP_STRING
            : argType == "idAnimWebPath&" ? idAIActionParm::SP_ANIM_WEB_NODE
            : argType == "aliasHandle_t" ? idAIActionParm::SP_ANIM_ALIAS
            : idAIActionParm::SP_ENTITY_NAME;
        parm.strVal = value;
        return;
    }
    const char* declType = nullptr;
    idAIActionParm::subParm_t declSubType = idAIActionParm::SP_INTEGER;
    if (argType == "idDeclVoiceOver*") {
        declType = "idDeclVoiceOver";
        declSubType = idAIActionParm::SP_DECL_VOICEOVER;
    } else if (argType == "idSoundShader*") {
        declType = "idSoundShader";
        declSubType = idAIActionParm::SP_DECL_SOUND;
    } else if (argType == "idDeclAmmo*") {
        declType = "idDeclAmmo";
        declSubType = idAIActionParm::SP_DECL_AMMO;
    } else if (argType == "idDeclWeapon*") {
        declType = "idDeclWeapon";
        declSubType = idAIActionParm::SP_DECL_WEAPON;
    }
    if (declType != nullptr) {
        parm.type = idAIActionParm::P_DECL;
        parm.subType = declSubType;
        parm.declVal = Tungsten_FindActionScriptDecl(
            declType, value.c_str(), true);
        return;
    }

    int enumValue = 0;
    if (!Tungsten_FindActionScriptEnumValue(
            argType.c_str(), value.c_str(), enumValue)) {
        if (value == "AIPLAYER_1") {
            enumValue = 0;
        } else {
            ParseFailure(std::string("unknown enum value '")
                + value + "' for '" + argType + "'");
        }
    }
    if (!IsSupportedLegacyEnum(argType)) {
        ParseFailure(std::string("unsupported enum type '")
            + argType + "'");
    }
    parm.type = idAIActionParm::P_DISCRETE;
    parm.subType = EnumSubType(argType);
    parm.intVal = argType == "aiActionBool_t"
        ? (enumValue != 0 ? 1 : 0) : enumValue;
}

// Retail symbol: ?EndFile@idActionScriptConvertor@@AAA_NPBD@Z
// EA: 0x82A3CE88, RVA: 0x00A3CE88
bool idActionScriptConvertor::EndFile(const char* const fileName) {
    if (output.empty()) {
        Tungsten_ActionScriptPrint("no scripts found.\n");
        buffer.clear();
        return true;
    }
    output.append(buffer, startPos, cursor - startPos);
    Tungsten_ActionScriptPrint(
        "found %d action scripts. Writing '%s'...\n",
        numScripts, fileName);
    if (Tungsten_HasActionScriptSourceControl()
        && !Tungsten_CheckOutActionScriptFile(fileName)) {
        Tungsten_ActionScriptWarning(
            "Failed to check out file '%s'", fileName);
        buffer.clear();
        return false;
    }
    const std::string backup = ReplaceExtension(
        fileName, ".map.actionscript.bak");
    Tungsten_RenameActionScriptFile(fileName, backup.c_str());
    const bool result = Tungsten_WriteActionScriptFile(fileName, output);
    buffer.clear();
    return result;
}

// Retail symbol: ?ConvertScriptAction@idActionScriptConvertor@@AAA_NHAAVidScriptAction@@@Z
// EA: 0x82A3D118, RVA: 0x00A3D118
bool idActionScriptConvertor::ConvertScriptAction(const int,
        idScriptAction& action) {
    token_t token;
    const std::string eventFieldType = ReadTypeName();
    if (eventFieldType != "idStr") {
        ParseFailure("expected idStr eventName field");
    }
    do {
        if (!ReadToken(token)) {
            ParseFailure("missing eventName field");
        }
    } while (token.text != "eventName");
    ExpectToken("=");
    if (!ReadToken(token)) {
        ParseFailure("missing event name");
    }
    action.eventName = token.text;
    ExpectToken(";");

    std::vector<std::string> argumentTypes;
    if (!Tungsten_FindActionScriptEvent(
            action.eventName.c_str(), argumentTypes)) {
        const std::string decorated = '<' + action.eventName + '>';
        if (Tungsten_FindActionScriptEvent(
                decorated.c_str(), argumentTypes)) {
            action.eventName = decorated;
        } else {
            Tungsten_ActionScriptWarning(
                "Error: event '%s' was not found.",
                action.eventName.c_str());
            SkipBracedSection(true);
            return true;
        }
    }

    const std::string parameterType = ReadTypeName();
    do {
        if (!ReadToken(token)) {
            ParseFailure("missing params field");
        }
    } while (token.text != "params");
    ExpectToken("=");
    ExpectToken("{");
    if (parameterType.find("idAIActionParm") != std::string::npos) {
        SkipBracedSection(true);
        ExpectToken(";");
        ExpectToken("}");
        return false;
    }
    if (parameterType.find("idStr") == std::string::npos) {
        ParseFailure("expected idList of idStr action parameters");
    }

    ExpectToken("int");
    ExpectToken("num");
    ExpectToken("=");
    ParseInt();
    ExpectToken(";");
    while (PeekToken(token) && token.text != "}") {
        const std::size_t parameterStart = cursor;
        const std::string itemType = ReadTypeName();
        if (itemType != "idStr") {
            ParseFailure("expected idStr action parameter item");
        }
        cursor = parameterStart;
        const std::size_t index = action.parms.size();
        if (index >= argumentTypes.size()) {
            ParseFailure("action has more parameters than its event");
        }
        action.parms.emplace_back();
        ConvertActionParm(static_cast<int>(index),
            argumentTypes[index], action.parms.back());
    }
    ExpectToken("}");
    CheckToken(";");
    ExpectToken("}");
    return true;
}

// Retail symbol: ?ConvertActionScript@idActionScriptConvertor@@AAA_NABVidToken@@PBD@Z
// EA: 0x82A3D8A8, RVA: 0x00A3D8A8
bool idActionScriptConvertor::ConvertActionScript(
        const std::string&, const std::size_t sourcePosition) {
    token_t token;
    ExpectToken("int");
    ExpectToken("num");
    ExpectToken("=");
    ParseInt();
    ExpectToken(";");

    aiActionScript_t actions;
    while (PeekToken(token) && token.text != "}") {
        const std::string actionType = ReadTypeName();
        if (actionType != "idScriptAction") {
            ParseFailure("expected idScriptAction item");
        }
        bool foundAssignment = false;
        while (ReadToken(token)) {
            if (token.text == "=") {
                foundAssignment = true;
                break;
            }
            if (token.text == "{") {
                ParseFailure("action item has no assignment");
            }
        }
        if (!foundAssignment) {
            ParseFailure("unterminated action item");
        }
        ExpectToken("{");
        actions.emplace_back();
        if (!ConvertScriptAction(
                static_cast<int>(actions.size() - 1), actions.back())) {
            actions.pop_back();
            SkipBracedSection(true);
            return false;
        }
        CheckToken(";");
    }
    ExpectToken("}");
    CheckToken(";");

    if (sourcePosition < startPos || sourcePosition > buffer.size()) {
        ParseFailure("invalid rewrite source position");
    }
    output.append(buffer, startPos, sourcePosition - startPos);
    output += "\n\\ BEGIN REWRITE\n";
    std::string typeInfo;
    const int indent = fileType == FT_TYPEINFO ? 4 : 2;
    if (!Tungsten_WriteActionScriptTypeInfo(actions, indent, typeInfo)) {
        ParseFailure("failed to serialize converted action script");
    }
    output += typeInfo;
    output += "\n\\ END REWRITE\n";
    startPos = cursor;
    return true;
}

// Retail symbol: ?ParseVariableDef_r@idActionScriptConvertor@@AAAXXZ
// EA: 0x82A3DD80, RVA: 0x00A3DD80
void idActionScriptConvertor::ParseVariableDef_r() {
    token_t token;
    while (PeekToken(token)) {
        if (token.text == "}") {
            ReadToken(token);
            return;
        }
        const std::size_t fieldPosition = token.begin;
        const std::string typeName = ReadTypeName();
        if (!ReadToken(token)) {
            ParseFailure("expected variable name");
        }
        if (CheckToken("[")) {
            ParseInt();
            ExpectToken("]");
        }
        ExpectToken("=");
        if (CheckToken("{")) {
            if (typeName.find("idList") != std::string::npos
                && typeName.find("idScriptAction") != std::string::npos) {
                if (ConvertActionScript(typeName, fieldPosition)) {
                    ++numScripts;
                }
            } else {
                ParseVariableDef_r();
                CheckToken(";");
            }
        } else {
            SkipValue();
        }
    }
}

// Retail symbol: ?ParseEntityClassDef@idActionScriptConvertor@@AAAXAAVidToken@@@Z
// EA: 0x82A3E188, RVA: 0x00A3E188
void idActionScriptConvertor::ParseEntityClassDef(
        const std::string&) {
    token_t token;
    if (!ReadToken(token)) {
        ParseFailure("expected entity class field name");
    }
    ExpectToken("=");
    ExpectToken("{");
    ParseVariableDef_r();
    CheckToken(";");
}

// Retail symbol: ?FixEntityDefActionScripts@idActionScriptConvertor@@QAAXXZ
// EA: 0x82A3E2A8, RVA: 0x00A3E2A8
void idActionScriptConvertor::FixEntityDefActionScripts() {
    token_t token;
    if (!ReadToken(token) || token.text == "{") {
        ParseFailure("expected entity name");
    }
    ExpectToken("{");
    while (ReadToken(token)) {
        if (token.text == "}") {
            return;
        }
        if (token.text == "inherit" || token.text == "class") {
            SkipRestOfLine();
        } else {
            ParseEntityClassDef(token.text);
        }
    }
    ParseFailure("unterminated entityDef");
}

// Retail symbol: ?ParseDeclAIInteraction@idActionScriptConvertor@@AAAXXZ
// EA: 0x82A3E4A0, RVA: 0x00A3E4A0
void idActionScriptConvertor::ParseDeclAIInteraction() {
    token_t token;
    while (ReadToken(token)) {
        if (token.text == "}") {
            return;
        }
        if (token.text == "inherit" || token.text == "class") {
            SkipRestOfLine();
        } else {
            ParseEntityClassDef(token.text);
        }
    }
    ParseFailure("unterminated aiInteraction declaration");
}

// Retail symbol: ?FixTypeInfoActionScripts@idActionScriptConvertor@@QAA_NPBD@Z
// EA: 0x82A3E610, RVA: 0x00A3E610
bool idActionScriptConvertor::FixTypeInfoActionScripts(
        const char* const fileName) {
    if (!BeginFile(fileName)) {
        return false;
    }
    fileType = FT_TYPEINFO;
    try {
        token_t declarationType;
        token_t declarationName;
        while (ReadToken(declarationType)) {
            if (!ReadToken(declarationName)) {
                ParseFailure("expected declaration name");
            }
            ExpectToken("{");
            if (declarationType.text == "aiInteraction") {
                ParseDeclAIInteraction();
            } else {
                SkipBracedSection(true);
            }
        }
        return EndFile(fileName);
    } catch (const std::exception& exception) {
        buffer.clear();
        return HandleTypeInfoParseFailure(fileName, exception.what());
    }
}

// Retail symbol: ?FixMapFileActionScripts@idActionScriptConvertor@@QAA_NPBD@Z
// EA: 0x82A3E8D8, RVA: 0x00A3E8D8
bool idActionScriptConvertor::FixMapFileActionScripts(
        const char* const fileName) {
    if (!BeginFile(fileName)) {
        return false;
    }
    fileType = FT_MAP;
    try {
        ExpectToken("Version");
        if (ParseInt() != 3) {
            ParseFailure("map version must be 3 in order to convert");
        }
        token_t token;
        while (ReadToken(token)) {
            if (token.text == "entity") {
                ParseInt();
                ExpectToken("{");
                while (ReadToken(token)) {
                    if (token.text == "}") {
                        break;
                    }
                    if (token.text == "groups"
                        || token.text == "layers") {
                        SkipBracedSection(false);
                    } else if (token.text == "entityDef") {
                        FixEntityDefActionScripts();
                    } else if (token.text == "{") {
                        SkipBracedSection(true);
                    } else {
                        ParseFailure(std::string("unknown entity token '")
                            + token.text + "'");
                    }
                }
            } else if (token.text == "groupstates"
                || token.text == "includes") {
                SkipBracedSection(false);
            } else if (token.text == "compound") {
                ParseInt();
                SkipBracedSection(false);
            } else {
                ParseFailure(std::string("unknown map token '")
                    + token.text + "'");
            }
        }
        return EndFile(fileName);
    } catch (const std::exception& exception) {
        buffer.clear();
        return HandleMapParseFailure(fileName, exception.what());
    }
}

// Retail symbol: ?Cmd_FixActionScripts_f@@YAXABVidCmdArgs@@@Z
// EA: 0x82A3ECC8, RVA: 0x00A3ECC8
void Cmd_FixActionScripts_f(const idCmdArgs& args) {
    idActionScriptConvertor convertor;
    if (args.argv.size() > 1) {
        const std::string extension = ExtractExtension(args.argv[1]);
        if (extension == "tdef") {
            convertor.FixTypeInfoActionScripts(args.argv[1].c_str());
        } else if (extension == "map") {
            convertor.FixMapFileActionScripts(args.argv[1].c_str());
        } else {
            Tungsten_ActionScriptWarning(
                "Unknown extension type '%s'", extension.c_str());
        }
        return;
    }

    if (Tungsten_HasActionScriptSourceControl()) {
        Tungsten_SetActionScriptSilentCheckOut(true);
    }
    Tungsten_SetActionScriptRefreshOnPrint(true);
    std::vector<std::string> files;
    Tungsten_ListActionScriptFiles("typeinfo", ".tdef", files);
    for (const std::string& file : files) {
        convertor.FixTypeInfoActionScripts(file.c_str());
    }
    files.clear();
    Tungsten_ListActionScriptFiles("maps", ".map", files);
    for (const std::string& file : files) {
        convertor.FixMapFileActionScripts(file.c_str());
    }
    Tungsten_SetActionScriptRefreshOnPrint(false);
    if (Tungsten_HasActionScriptSourceControl()) {
        Tungsten_SetActionScriptSilentCheckOut(false);
    }
}
