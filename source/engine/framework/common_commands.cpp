#include "framework/framework_runtime_internal.h"

#include "framework/common_local.h"
#include "framework/framework_hooks.h"
#include "framework/keyinput.h"
#include "framework/consolehistory.h"
#include "framework/memorymappedfile.h"
#include "framework/playerprofile.h"
#include "framework/rendermanager.h"
#include "framework/resourcelist.h"
#include "framework/streamfilelog.h"
#include "framework/regression.h"
#include "framework/streamfilecache.h"
#include "framework/timemanager.h"
#include "framework/usercmdgen.h"
#include "idlib/lib_print.h"
#include "idlib/text/cmdargs.h"
#include "idlib/text/lexer.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>

namespace tech5Framework {

bool RegisterCommand(const char* const name, commandFunction_t function) {
    if (name == nullptr || *name == '\0' || !function) return false;
    std::string canonical(name);
    for (char& c : canonical) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    return state.commands.emplace(canonical, std::move(function)).second;
}

bool ExecuteCommand(const char* const commandLine) {
    if (commandLine == nullptr) return false;
    std::vector<idStr> args;
    std::string token;
    bool quoted = false;
    for (const char* p = commandLine; ; ++p) {
        const char c = *p;
        if (c == '"') quoted = !quoted;
        else if (c == '\0' || (!quoted && std::isspace(static_cast<unsigned char>(c)))) {
            if (!token.empty()) { args.emplace_back(token.c_str()); token.clear(); }
            if (c == '\0') break;
        } else token.push_back(c);
    }
    if (args.empty()) return false;
    std::string name(args[0].c_str());
    for (char& c : name) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    runtimeState_t& state = State();
    commandFunction_t function;
    {
        std::lock_guard<std::recursive_mutex> lock(state.mutex);
        const auto found = state.commands.find(name);
        if (found == state.commands.end()) return false;
        function = found->second;
    }
    function(args);
    return true;
}

void ClearCommands() {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.commands.clear();
}

} // namespace tech5Framework

namespace {

idCmdArgs MakeCommandArgs(const std::vector<idStr>& values) {
    idCmdArgs result;
    for (const idStr& value : values) result.AppendArg(value.c_str());
    return result;
}

bool DelegateCommand(const char* const name, const idCmdArgs& args) {
    if (frameworkHooks.ownerCommand != nullptr
        && frameworkHooks.ownerCommand(name, args)) {
        return true;
    }
    tech5Framework::Print(0xFFFFFF00u,
        "%s requires its owning engine subsystem\n", name);
    return false;
}

using commandHandler_t = void (*)(const idCmdArgs&);

void RegisterRecoveredCommand(const char* const name,
        commandHandler_t handler) {
    tech5Framework::RegisterCommand(name,
        [handler](const std::vector<idStr>& values) {
            const idCmdArgs args = MakeCommandArgs(values);
            handler(args);
        });
}

} // namespace

void StopTest_f(const idCmdArgs&) {
    if (commonLocal.GetRegression() != nullptr) {
        commonLocal.GetRegression()->StopTest();
    }
}

void configVersion_f(const idCmdArgs& args) {
    if (args.Argc() == 1) {
        idLibPrint::Printf("Current config version is %d.\n", 1);
    } else if (std::atoi(args.Argv(1)) < 1) {
        idLibPrint::Warning("Unsupported config version. Execution may "
            "create invalid or strange controller bindings.");
    }
}

void GatherMapStats_f(const idCmdArgs& args) {
    DelegateCommand("gatherMapStats", args);
}

void nextRegressionTest_f(const idCmdArgs&) {
    if (commonLocal.GetRegression() != nullptr) {
        commonLocal.GetRegression()->NextTest();
    }
}

void Com_TestStatsBegin_f(const idCmdArgs&) {
    if (commonLocal.GetRegression() != nullptr) {
        commonLocal.GetRegression()->SetTestInProgress(true);
    }
}

void Com_TestStatsEnd_f(const idCmdArgs&) {
    if (commonLocal.GetRegression() != nullptr) {
        commonLocal.GetRegression()->SetTestInProgress(false);
    }
}

void R_VidRestart_f(const idCmdArgs& args) {
    DelegateCommand("vid_restart", args);
}

void SetGameHz_f(const idCmdArgs& args) {
    if (args.Argc() != 2) {
        tech5Framework::Print(0xFFFFFFFFu,
            "usage: setGameHz <positive hertz>\n");
        return;
    }
    const int hz = std::atoi(args.Argv(1));
    if (hz <= 0) {
        tech5Framework::Print(0xFFFFFF00u, "setGameHz: invalid rate\n");
        return;
    }
    timeManager.SetGameHz(hz);
}

void StopSlowMotion_f(const idCmdArgs& args) {
    DelegateCommand("stopSlowMotion", args);
}
void StartSlowMotion2_f(const idCmdArgs& args) {
    DelegateCommand("startSlowMotion2", args);
}
void StopSlowMotion2_f(const idCmdArgs& args) {
    DelegateCommand("stopSlowMotion2", args);
}
void StartSlowMotion_f(const idCmdArgs& args) {
    DelegateCommand("startSlowMotion", args);
}

void Com_WriteConfig_f(const idCmdArgs& args) {
    const char* const filename = args.Argc() > 1
        ? args.Argv(1) : "config.cfg";
    commonLocal.WriteConfigToFile(filename);
}

void idCommonLocal::InitLanguageDict() {
    idCmdArgs args;
    args.AppendArg("reloadLanguage");
    DelegateCommand("reloadLanguage", args);
}

void Com_ReloadLanguage_f(const idCmdArgs&) {
    commonLocal.InitLanguageDict();
}

void Com_RecordEvents_f(const idCmdArgs& args) {
    commonLocal.RecordPlayback(true,
        args.Argc() > 1 ? args.Argv(1) : nullptr);
}

void Com_PlayEvents_f(const idCmdArgs& args) {
    commonLocal.RecordPlayback(false,
        args.Argc() > 1 ? args.Argv(1) : nullptr);
}

void MakeTest_f(const idCmdArgs& args) {
    if (commonLocal.GetRegression() != nullptr) {
        commonLocal.GetRegression()->MakeTest(&args);
    }
}
void MakeTestLoadGame_f(const idCmdArgs& args) {
    if (commonLocal.GetRegression() != nullptr) {
        commonLocal.GetRegression()->MakeTestLoadGame(&args);
    }
}
void PlayTest_f(const idCmdArgs& args) {
    if (commonLocal.GetRegression() != nullptr && args.Argc() > 1) {
        commonLocal.GetRegression()->PlayTest(args.Argv(1), false);
    }
}
void PlayTestAndExit_f(const idCmdArgs& args) {
    if (commonLocal.GetRegression() != nullptr && args.Argc() > 1) {
        commonLocal.GetRegression()->PlayTest(args.Argv(1), true);
    }
}

void DelayedScreenshot_f(const idCmdArgs& args) {
    DelegateCommand("delayedScreenshot", args);
}

void DumpWarnings_f(const idCmdArgs& args) {
    if (args.Argc() == 2) {
        commonLocal.DumpWarnings(args.Argv(1));
    } else {
        idLibPrint::Printf("USAGE: com_dumpWarnings <file name>\n");
    }
}

void sys_writeMemoryReport_f(const idCmdArgs& args) {
    if (streamFileCache != nullptr) streamFileCache->Stats();
    DelegateCommand("writeMemoryReport", args);
}

void reportNumRenderModels_f(const idCmdArgs& args) {
    DelegateCommand("reportNumRenderModels", args);
}

void Com_StripStrings_f(const idCmdArgs& args) {
    DelegateCommand("stripStrings", args);
}

void writeEntitiesFile_f(const idCmdArgs& args) {
    DelegateCommand("writeEntitiesFile", args);
}

void Com_Find_f(const idCmdArgs& args) {
    if (args.Argc() < 2) {
        tech5Framework::Print(0xFFFFFFFFu, "usage: find <text>\n");
        return;
    }
    std::string needle(args.Argv(1));
    for (char& character : needle) {
        character = static_cast<char>(std::tolower(
            static_cast<unsigned char>(character)));
    }
    tech5Framework::runtimeState_t& state = tech5Framework::State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    for (const auto& command : state.commands) {
        if (command.first.find(needle) != std::string::npos) {
            idLibPrint::Printf("%s\n", command.first.c_str());
        }
    }
}

void FindUnlocalizedStrings_f(const idCmdArgs& args) {
    DelegateCommand("findUnlocalizedStrings", args);
}
void FindUnreferencedStrings_f(const idCmdArgs& args) {
    DelegateCommand("findUnreferencedStrings", args);
}
void cleanMapFolders_f(const idCmdArgs& args) {
    DelegateCommand("cleanMapFolders", args);
}

void testXML_f(const idCmdArgs& args) {
    if (args.Argc() != 2) {
        tech5Framework::Print(0xFFFFFFFFu, "usage: testXML <filename>\n");
        return;
    }
    idLexer lexer(LEXFL_NOSTRINGCONCAT | LEXFL_NOFATALERRORS);
    if (!lexer.LoadFile(args.Argv(1))) {
        tech5Framework::Print(0xFFFF8080u, "testXML: could not load %s\n",
            args.Argv(1));
        return;
    }
    int tokens = 0;
    int depth = 0;
    idToken token;
    while (lexer.ReadToken(token)) {
        ++tokens;
        if (idStr::Cmp(token.c_str(), "<") == 0) ++depth;
        else if (idStr::Cmp(token.c_str(), ">") == 0 && depth > 0) --depth;
    }
    tech5Framework::Print(lexer.HadError() ? 0xFFFF8080u : 0xFFFFFFFFu,
        "testXML: %d tokens, parser errors=%d\n", tokens,
        lexer.HadError() ? 1 : 0);
}

void idCommonLocal::InitCommands() {
    struct commandDef_t { const char* name; commandHandler_t function; };
    static const commandDef_t commands[] = {
        {"configVersion", configVersion_f},
        {"stopTest", StopTest_f}, {"gatherMapStats", GatherMapStats_f},
        {"nextRegressionTest", nextRegressionTest_f},
        {"testStatsBegin", Com_TestStatsBegin_f},
        {"testStatsEnd", Com_TestStatsEnd_f},
        {"vid_restart", R_VidRestart_f}, {"setGameHz", SetGameHz_f},
        {"stopSlowMotion", StopSlowMotion_f},
        {"startSlowMotion2", StartSlowMotion2_f},
        {"stopSlowMotion2", StopSlowMotion2_f},
        {"startSlowMotion", StartSlowMotion_f},
        {"writeConfig", Com_WriteConfig_f},
        {"reloadLanguage", Com_ReloadLanguage_f},
        {"recordEvents", Com_RecordEvents_f},
        {"playEvents", Com_PlayEvents_f}, {"makeTest", MakeTest_f},
        {"makeTestLoadGame", MakeTestLoadGame_f},
        {"playTest", PlayTest_f}, {"playTestAndExit", PlayTestAndExit_f},
        {"delayedScreenshot", DelayedScreenshot_f},
        {"com_dumpWarnings", DumpWarnings_f},
        {"writeMemoryReport", sys_writeMemoryReport_f},
        {"reportNumRenderModels", reportNumRenderModels_f},
        {"stripStrings", Com_StripStrings_f},
        {"writeEntitiesFile", writeEntitiesFile_f}, {"find", Com_Find_f},
        {"findUnlocalizedStrings", FindUnlocalizedStrings_f},
        {"findUnreferencedStrings", FindUnreferencedStrings_f},
        {"cleanMapFolders", cleanMapFolders_f}, {"testXML", testXML_f}
    };
    for (const commandDef_t& command : commands) {
        RegisterRecoveredCommand(command.name, command.function);
    }
    RegisterKeyInputCommands();
    RegisterConsoleHistoryCommands();
    RegisterDialogCommands();
    RegisterMemoryMappedFileCommands();
    RegisterPlayerProfileCommands();
    RegisterRenderManagerCommands();
    RegisterResourceListCommands();
    RegisterStreamFileCacheCommands();
    RegisterStreamFileLogCommands();
    RegisterUsercmdCommands();
}
