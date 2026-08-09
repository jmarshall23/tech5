#pragma once

#include "lexer.h"
#include "../containers/list.h"

class idParser {
public:
    struct define_t {
        idStr name;
        int scope;
        int builtin;
        int numparms;
        idToken* parms;
        idToken* tokens;
        define_t* next;
        define_t* hashnext;
    };

    struct indent_t {
        int type;
        int skip;
        int skipElse;
        idLexer* script;
    };

    class idDependency {
    public:
        int includeLevel;
        idStr fileName;
    };

    using pragmaCallback_t = void (*)(void* data, const char* text);

    explicit idParser(int flags = 0);
    ~idParser();

    bool LoadFile(const char* fileName, bool OSPath = false);
    bool LoadMemory(const char* pointer, int length, const char* name);
    void FreeSource();
    void AddInclude(const char* fileName);
    int AddDefine(const char* defineString);
    void PushDefineScope();
    void PopDefineScope();
    void SetFlags(int parserFlags);
    int GetFlags() const { return flags; }
    void SetIncludePath(const char* path) { includepath = path; }
    void SetPragmaCallback(pragmaCallback_t callback, void* data) {
        pragmaCallback = callback;
        pragmaData = data;
    }

    bool ReadToken(idToken& token);
    int ReadTokenOnLine(idToken& token);
    void UnreadToken(const idToken& token);
    bool ExpectTokenString(const char* string);
    int ExpectTokenType(int type, int subtype, idToken& token);
    int ExpectAnyToken(idToken& token);
    int CheckTokenString(const char* string);
    int CheckTokenType(int type, int subtype, idToken& token);
    int PeekTokenString(const char* string);
    int PeekTokenType(int type, int subtype, idToken& token);
    bool SkipUntilString(const char* string);
    int SkipRestOfLine();
    int SkipBracedSection(bool parseFirstBrace = true);
    bool ParseBracedSectionExact(idStr& out, bool parseFirstBrace = true);
    const char* ParseRestOfLine(idStr& out);
    int ParseInt();
    bool ParseBool();
    float ParseFloat(bool* errorFlag = nullptr);
    bool Parse1DMatrix(int x, float* matrix);
    int GetLastWhiteSpace(idStr& whiteSpace) const;
    int GetNextWhiteSpace(idStr& whiteSpace, bool currentLine);
    int GetPunctuationId(const char* punctuation);
    bool HadError() const;
    bool HadWarning() const;
    const idList<idDependency, TAG_LEXER>& GetDependencies() const {
        return dependencies;
    }
    void Error(const char* format, ...) const;
    void Warning(const char* format, ...) const;

    static void SetupGlobalDefines();

    bool loaded;
    idStr filename;
    idStr includepath;
    bool OSPath;
    const punctuation_t* punctuations;
    int flags;
    idLexer* scriptstack;
    idToken* tokens;
    int defineScope;
    define_t* definehash[128];
    idList<indent_t, TAG_LEXER> indentstack;
    int skip;
    pragmaCallback_t pragmaCallback;
    void* pragmaData;
    bool hadError;
    bool hadWarning;
    int includeLevel;
    idList<idDependency, TAG_LEXER> dependencies;

private:
    void AddDependency(int level, const char* fileName);
    void AddGlobalDefinesToSource();
    define_t* CopyDefine(define_t* define);
    static define_t* DefineFromString(const char* string);
    static void FreeDefine(define_t* define);
    define_t* FindHashedDefine(const char* name);
    int FindDefineParm(define_t* define, const char* name);
    bool PushScript(idLexer* script);
    bool UnreadSourceToken(const idToken& token);
    int ReadSourceToken(idToken& token);
    int ReadDefineParms(define_t* define, idToken** parms, int maxParms);
    int ReadDirective();
    int ReadDollarDirective();
    int ReadLine(idToken& token, bool multiline);
    void PushIndent(int type, int skip, int skipElse);
    void UnreadSignToken();
    int StringizeTokens(idToken* tokens, idToken* token);
    int MergeTokens(idToken* first, idToken* second);
    int ExpandBuiltinDefine(idToken* token, define_t* define,
        idToken** firstToken, idToken** lastToken);
    int ExpandDefine(idToken* token, define_t* define,
        idToken** firstToken, idToken** lastToken);
    int ExpandDefineIntoSource(idToken* token, define_t* define);
    int EvaluateTokens(idToken* tokens, int* intValue, double* floatValue,
        int integer);
    int Evaluate(int* intValue, double* floatValue, int integer);
    int EvaluateFunction(int* intValue, double* floatValue, int integer);
    define_t* Directive_define(bool builtin);
    int Directive_elif();
    int Directive_else();
    int Directive_endif();
    int Directive_error();
    int Directive_evalfloat();
    int Directive_evalint();
    int Directive_if();
    int Directive_if_def(int type);
    int Directive_include();
    int Directive_line();
    int Directive_pragma();
    int Directive_undef();
    int Directive_warning();
    int DollarDirective_elif();
    int DollarDirective_else();
    int DollarDirective_endif();
    int DollarDirective_if_def(int type);
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idParser::define_t) == 60,
    "Recovered idParser::define_t ABI changed");
static_assert(sizeof(idParser::indent_t) == 16,
    "Recovered idParser::indent_t ABI changed");
static_assert(sizeof(idParser::idDependency) == 36,
    "Recovered idParser::idDependency ABI changed");
static_assert(sizeof(idParser) == 656, "Recovered idParser ABI changed");
#endif
