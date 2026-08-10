#pragma once

#include "autocomplete.h"
#include "../containers/list.h"
#include "../text/strstatic.h"

using cmdFunction_t = void (*)(const idCmdArgs& args);
using argCompletion_t = void (*)(idAutoComplete& completion);

class idCmdSystem {
public:
    virtual ~idCmdSystem();
    virtual void Init() = 0;
    virtual void AddCommand(const char* name, cmdFunction_t function,
        const char* description, argCompletion_t argCompletion = nullptr) = 0;
    virtual const char* GetCommandDescription(const char* name) = 0;
    virtual bool CommandExists(const char* name,
        bool searchForCommandString) = 0;
    virtual void FindCommands(const char* prefix, idList<idStr>& commands) = 0;
    virtual void CommandCompletion(idAutoComplete& completion) = 0;
    virtual void ExecuteCommandText(const char* text) = 0;
    virtual void AppendCommandText(const char* text) = 0;
    virtual void ExecuteCommandBuffer() = 0;
    virtual void ArgCompletion_FolderExtension(idAutoComplete& completion,
        const char* folder, const char* extension, bool stripFolder) = 0;

    static void ArgCompletion_Boolean(idAutoComplete& completion);
    static void ArgCompletion_ConfigName(idAutoComplete& completion);
    static void ArgCompletion_DemoFile(idAutoComplete& completion);
    static void ArgCompletion_EventName(idAutoComplete& completion);
    static void ArgCompletion_FileName(idAutoComplete& completion);
    static void ArgCompletion_ImageName(idAutoComplete& completion);
    static void ArgCompletion_MapName(idAutoComplete& completion);
    static void ArgCompletion_ModelName(idAutoComplete& completion);
    static void ArgCompletion_PlayTestFile(idAutoComplete& completion);
    static void ArgCompletion_RegressionTestName(idAutoComplete& completion);
    static void ArgCompletion_SaveGame(idAutoComplete& completion);
    static void ArgCompletion_TimeTrial(idAutoComplete& completion);

    template<int minimum, int maximum>
    static void ArgCompletion_Integer(idAutoComplete& completion);

    template<const char** strings, int numStrings = -1>
    static void ArgCompletion_String(idAutoComplete& completion);
};

struct commandDef_s {
    commandDef_s* next;
    const char* name;
    cmdFunction_t function;
    argCompletion_t argCompletion;
    const char* description;
};

class idCmdSystemLocal : public idCmdSystem {
public:
    idCmdSystemLocal();
    ~idCmdSystemLocal() override;

    void Init() override;
    void AddCommand(const char* name, cmdFunction_t function,
        const char* description, argCompletion_t argCompletion) override;
    const char* GetCommandDescription(const char* name) override;
    bool CommandExists(const char* name,
        bool searchForCommandString) override;
    void FindCommands(const char* prefix, idList<idStr>& commands) override;
    void CommandCompletion(idAutoComplete& completion) override;
    void ExecuteCommandText(const char* text) override;
    void AppendCommandText(const char* text) override;
    void ExecuteCommandBuffer() override;
    void ArgCompletion_FolderExtension(idAutoComplete& completion,
        const char* folder, const char* extension, bool stripFolder) override;

    void ExecuteTokenizedString(const idCmdArgs& args);
    void InsertCommandText(const char* text);

    commandDef_s* commands;
    int wait;
    idStrStatic<32768> textBuffer;

private:
    static void Echo_f(const idCmdArgs& args);
    static void Exec_f(const idCmdArgs& args);
    static void List_f(const idCmdArgs& args);
    static void Parse_f(const idCmdArgs& args);
    static void Vstr_f(const idCmdArgs& args);
    static void Wait_f(const idCmdArgs& args);
};

extern idCmdSystem* cmdSystem;

template<int minimum, int maximum>
void idCmdSystem::ArgCompletion_Integer(idAutoComplete& completion) {
    for (int value = minimum; value <= maximum; ++value) {
        idStr text;
        text.Format("%d", value);
        completion.Append(text);
    }
}

template<const char** strings, int numStrings>
void idCmdSystem::ArgCompletion_String(idAutoComplete& completion) {
    if (strings == nullptr) return;
    for (int index = 0;
            (numStrings < 0 || index < numStrings)
                && strings[index] != nullptr; ++index)
        completion.Append(idStr(strings[index]));
}

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idCmdSystem) == 4, "Recovered idCmdSystem ABI changed");
static_assert(sizeof(commandDef_s) == 20, "Recovered commandDef_s ABI changed");
static_assert(sizeof(idCmdSystemLocal) == 32812,
    "Recovered idCmdSystemLocal ABI changed");
#endif
