#pragma once

#include "xmlelement.h"

#include <cstdio>

class idXMLWriter {
public:
    idXMLWriter();
    ~idXMLWriter();

    bool OpenFile(const char* fileName, bool append = false,
        bool writeDeclaration = true);
    bool CloseFile();
    bool OpenElement(const char* name);
    bool OpenElement(const char* name,
        const idRecoveredList<idXMLAttribute>& attributes);
    bool WriteElement(const char* name, const char* value);
    bool WriteElement(const char* name, const char* value,
        const idRecoveredList<idXMLAttribute>& attributes);
    bool CloseElement();
    bool CloseDocument();
    bool WriteDocument(const idXMLElement* root);

private:
    struct stackXMLTag_t {
        idStr tagName;
        stackXMLTag_t* next;
    };

    std::FILE* xmlFile;
    int tabLevel;
    bool hasRoot;
    stackXMLTag_t* firstOpenTag;
    stackXMLTag_t* lastOpenTag;

    bool TestRoot(const char* name);
    bool WriteIndent();
    bool WriteEscaped(const char* text);
    bool WriteAttributes(const idRecoveredList<idXMLAttribute>& attributes);
    bool PushTag(const char* name);
    bool WriteElement_R(const idXMLElement* element);
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idXMLWriter) == 20, "Recovered idXMLWriter ABI changed");
#endif
