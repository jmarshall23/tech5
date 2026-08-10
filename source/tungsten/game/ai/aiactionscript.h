#pragma once

#include "idlib/math/vector.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

enum aiActionScriptFlags_t : std::uint32_t {
    ACTIONSCRIPT_ABORT_FOR_COMBAT = 0x1,
    ACTIONSCRIPT_ABORT_FOR_SEARCH = 0x2,
    ACTIONSCRIPT_IGNORE_AI_EVENTS = 0x4,
    ACTIONSCRIPT_NO_COMBAT_CHATTER = 0x8,
    ACTIONSCRIPT_NO_TARGETS = 0x10,
    ACTIONSCRIPT_IGNORE_PLAYER_APPROACH = 0x20,
    ACTIONSCRIPT_NO_DAMAGE = 0x40,
    ACTIONSCRIPT_NO_TWITCH_PAIN = 0x80,
    ACTIONSCRIPT_ENABLE_STAGGER_PAIN = 0x100,
    ACTIONSCRIPT_ENABLE_AUTOFOCUS = 0x200
};

class idAIActionParm {
public:
    enum parm_t : std::uint16_t {
        P_NONE = 0,
        P_DISCRETE = 1,
        P_FLOAT = 2,
        P_STRING = 3,
        P_DECL = 4
    };

    enum subParm_t : std::uint16_t {
        SP_INTEGER = 0,
        SP_BOOL = 1,
        SP_ARRIVALACTION = 2,
        SP_POSTURE = 3,
        SP_COVERACTION = 4,
        SP_EQUIPSLOT = 5,
        SP_ALERTCYCLE = 6,
        SP_FIREMODE = 7,
        SP_AIMPOINT = 8,
        SP_WALKSTATE = 9,
        SP_AIPLAYER = 10,
        SP_OVERRIDEANIM = 11,
        SP_PAIN = 12,
        SP_AIDIRECTION = 13,
        SP_DODGEDIR = 14,
        SP_SUBWEB = 15,
        SP_ACTIONBOOL = 16,
        SP_FLOAT = 17,
        SP_VEC3 = 18,
        SP_ANGLES = 19,
        SP_STRING = 20,
        SP_ANIM_ALIAS = 21,
        SP_ANIM_WEB_NODE = 22,
        SP_ENTITY_NAME = 23,
        SP_DECL_VOICEOVER = 24,
        SP_DECL_SOUND = 25,
        SP_DECL_AMMO = 26,
        SP_DECL_WEAPON = 27,
        SP_AIVAROP = 28,
        SP_AIVARTYPE = 29,
        SP_DECL_INVENTORY = 30,
        SP_AIANIMWEB = 31,
        SP_AIACTIONSCRIPTFLAG = 32,
        SP_AIPERCEPTIONFLAG = 33,
        SP_SITSTATE = 34,
        SP_STANDSTATE = 35,
        SP_IDLESTATE = 36,
        SP_SETMOVEPUSHSTATUS = 37,
        SP_AIMOVEMENTMODE = 38,
        SP_AIANIMWAIT = 39,
        SP_AIIDLETURN = 40,
        SP_ACCURACY = 41,
        SP_AIMOVEREASON = 42,
        SP_MOVE_TO_SCENEPOINT_FLAGS = 43,
        SP_COMMAND_MOVE = 44
    };

    idAIActionParm();
    bool IsEnum() const;
    void Clear();

    parm_t type;
    subParm_t subType;
    int intVal;
    idVec3 floatVal;
    const void* declVal;
    std::string strVal;
};

struct idScriptAction {
    std::string eventName;
    std::vector<idAIActionParm> parms;
};

using aiActionScript_t = std::vector<idScriptAction>;

enum actionScriptFileType_t : int {
    FT_MAP = 0,
    FT_TYPEINFO = 1,
    FT_MAX = 2
};

class idActionScriptConvertor {
public:
    idActionScriptConvertor();

    bool Begin(const char* sourceBuffer, std::size_t length,
        const char* fileName);
    bool BeginFile(const char* fileName);
    void ConvertActionParm(int index, const std::string& argType,
        idAIActionParm& parm);
    bool EndFile(const char* fileName);
    bool ConvertScriptAction(int index, idScriptAction& action);
    bool ConvertActionScript(const std::string& typeName,
        std::size_t sourcePosition);
    void ParseVariableDef_r();
    void ParseEntityClassDef(const std::string& entityClassName);
    void FixEntityDefActionScripts();
    void ParseDeclAIInteraction();
    bool FixTypeInfoActionScripts(const char* fileName);
    bool FixMapFileActionScripts(const char* fileName);

    const std::string& GetOutput() const { return output; }
    int GetNumScripts() const { return numScripts; }
    actionScriptFileType_t GetFileType() const { return fileType; }

private:
    struct token_t {
        std::string text;
        std::size_t begin = 0;
        std::size_t end = 0;
        bool quoted = false;
    };

    bool ReadToken(token_t& token);
    bool PeekToken(token_t& token);
    bool CheckToken(const char* text);
    void ExpectToken(const char* text);
    int ParseInt();
    std::string ReadTypeName();
    void SkipBracedSection(bool openingBraceAlreadyRead);
    void SkipRestOfLine();
    void SkipValue();
    void ParseFailure(const std::string& message) const;
    void ConvertActionParmValue(int index, const std::string& argType,
        const std::string& value, idAIActionParm& parm);

    std::string buffer;
    std::string sourceName;
    std::string output;
    std::size_t cursor;
    std::size_t startPos;
    int numScripts;
    actionScriptFileType_t fileType;
};

struct idCmdArgs {
    std::vector<std::string> argv;
};

void Cmd_FixActionScripts_f(const idCmdArgs& args);

// Runtime-owner seams retained by the recovered offline conversion command.
bool Tungsten_ReadActionScriptFile(const char* fileName,
    std::string& contents);
bool Tungsten_WriteActionScriptFile(const char* fileName,
    const std::string& contents);
bool Tungsten_RenameActionScriptFile(const char* from,
    const char* to);
bool Tungsten_CheckOutActionScriptFile(const char* fileName);
bool Tungsten_HasActionScriptSourceControl();
void Tungsten_SetActionScriptSilentCheckOut(bool silent);
void Tungsten_SetActionScriptRefreshOnPrint(bool refresh);
void Tungsten_ListActionScriptFiles(const char* directory,
    const char* extension, std::vector<std::string>& files);
void Tungsten_ActionScriptPrint(const char* format, ...);
void Tungsten_ActionScriptWarning(const char* format, ...);
bool Tungsten_FindActionScriptEvent(const char* eventName,
    std::vector<std::string>& argumentTypes);
bool Tungsten_FindActionScriptEnumValue(const char* enumType,
    const char* valueName, int& value);
const void* Tungsten_FindActionScriptDecl(const char* declType,
    const char* name, bool makeDefault);
bool Tungsten_WriteActionScriptTypeInfo(const aiActionScript_t& script,
    int indent, std::string& text);
