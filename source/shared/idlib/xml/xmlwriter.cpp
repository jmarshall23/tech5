#include "xmlwriter.h"

#include <cstdlib>
#include <cstring>
#include <new>

idXMLWriter::idXMLWriter()
    : xmlFile(nullptr), tabLevel(0), hasRoot(false),
      firstOpenTag(nullptr), lastOpenTag(nullptr) {
}

idXMLWriter::~idXMLWriter() {
    CloseFile();
}

bool idXMLWriter::OpenFile(const char* const fileName, const bool append,
    const bool writeDeclaration) {
    if (xmlFile != nullptr || fileName == nullptr) {
        return false;
    }
    if (fopen_s(&xmlFile, fileName, append ? "ab" : "wb") != 0
        || xmlFile == nullptr) {
        xmlFile = nullptr;
        return false;
    }
    tabLevel = 0;
    hasRoot = append;
    if (!append && writeDeclaration) {
        std::fputs("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n", xmlFile);
    }
    return true;
}

bool idXMLWriter::CloseFile() {
    if (xmlFile == nullptr) {
        return true;
    }
    while (firstOpenTag != nullptr) {
        CloseElement();
    }
    const bool success = std::fclose(xmlFile) == 0;
    xmlFile = nullptr;
    tabLevel = 0;
    hasRoot = false;
    return success;
}

bool idXMLWriter::TestRoot(const char*) {
    if (xmlFile == nullptr) {
        return false;
    }
    if (tabLevel == 0 && hasRoot) {
        return false;
    }
    if (tabLevel == 0) {
        hasRoot = true;
    }
    return true;
}

bool idXMLWriter::WriteIndent() {
    if (xmlFile == nullptr) {
        return false;
    }
    for (int index = 0; index < tabLevel; ++index) {
        if (std::fputs("  ", xmlFile) < 0) {
            return false;
        }
    }
    return true;
}

bool idXMLWriter::WriteEscaped(const char* text) {
    if (xmlFile == nullptr) {
        return false;
    }
    const char* cursor = text == nullptr ? "" : text;
    while (*cursor != '\0') {
        const char* escaped = nullptr;
        switch (*cursor) {
            case '&': escaped = "&amp;"; break;
            case '<': escaped = "&lt;"; break;
            case '>': escaped = "&gt;"; break;
            case '"': escaped = "&quot;"; break;
            case '\'': escaped = "&apos;"; break;
            default: break;
        }
        if (escaped != nullptr) {
            if (std::fputs(escaped, xmlFile) < 0) return false;
        } else if (std::fputc(*cursor, xmlFile) == EOF) {
            return false;
        }
        ++cursor;
    }
    return true;
}

bool idXMLWriter::WriteAttributes(
    const idRecoveredList<idXMLAttribute>& attributes) {
    for (int index = 0; index < attributes.Num(); ++index) {
        if (std::fputc(' ', xmlFile) == EOF
            || !WriteEscaped(attributes[index].GetName())
            || std::fputs("=\"", xmlFile) < 0
            || !WriteEscaped(attributes[index].GetValue())
            || std::fputc('"', xmlFile) == EOF) {
            return false;
        }
    }
    return true;
}

bool idXMLWriter::PushTag(const char* const name) {
    void* const storage = std::malloc(sizeof(stackXMLTag_t));
    if (storage == nullptr) {
        return false;
    }
    stackXMLTag_t* const tag = new (storage) stackXMLTag_t;
    tag->tagName = name;
    tag->next = firstOpenTag;
    firstOpenTag = tag;
    if (lastOpenTag == nullptr) {
        lastOpenTag = tag;
    }
    return true;
}

bool idXMLWriter::OpenElement(const char* const name) {
    idRecoveredList<idXMLAttribute> noAttributes;
    return OpenElement(name, noAttributes);
}

bool idXMLWriter::OpenElement(const char* const name,
    const idRecoveredList<idXMLAttribute>& attributes) {
    if (!TestRoot(name) || !WriteIndent() || std::fputc('<', xmlFile) == EOF
        || !WriteEscaped(name) || !WriteAttributes(attributes)
        || std::fputs(">\n", xmlFile) < 0 || !PushTag(name)) {
        return false;
    }
    ++tabLevel;
    return true;
}

bool idXMLWriter::WriteElement(const char* const name, const char* const value) {
    idRecoveredList<idXMLAttribute> noAttributes;
    return WriteElement(name, value, noAttributes);
}

bool idXMLWriter::WriteElement(const char* const name, const char* const value,
    const idRecoveredList<idXMLAttribute>& attributes) {
    if (!TestRoot(name) || !WriteIndent() || std::fputc('<', xmlFile) == EOF
        || !WriteEscaped(name) || !WriteAttributes(attributes)) {
        return false;
    }
    if (value == nullptr || value[0] == '\0') {
        return std::fputs("/>\n", xmlFile) >= 0;
    }
    return std::fputc('>', xmlFile) != EOF && WriteEscaped(value)
        && std::fputs("</", xmlFile) >= 0 && WriteEscaped(name)
        && std::fputs(">\n", xmlFile) >= 0;
}

bool idXMLWriter::CloseElement() {
    if (xmlFile == nullptr || firstOpenTag == nullptr) {
        return false;
    }
    stackXMLTag_t* const tag = firstOpenTag;
    firstOpenTag = tag->next;
    if (firstOpenTag == nullptr) {
        lastOpenTag = nullptr;
    }
    --tabLevel;
    const bool success = WriteIndent() && std::fputs("</", xmlFile) >= 0
        && WriteEscaped(tag->tagName.c_str()) && std::fputs(">\n", xmlFile) >= 0;
    tag->~stackXMLTag_t();
    std::free(tag);
    return success;
}

bool idXMLWriter::CloseDocument() {
    while (firstOpenTag != nullptr) {
        if (!CloseElement()) {
            return false;
        }
    }
    return CloseFile();
}

bool idXMLWriter::WriteElement_R(const idXMLElement* const element) {
    if (element == nullptr) {
        return false;
    }
    if (element->NumChildren() == 0) {
        idRecoveredList<idXMLAttribute> attributes;
        for (int index = 0; index < element->NumAttributes(); ++index) {
            attributes.Append(element->GetAttribute(index));
        }
        return WriteElement(element->GetName(), element->GetValue(), attributes);
    }
    idRecoveredList<idXMLAttribute> attributes;
    for (int index = 0; index < element->NumAttributes(); ++index) {
        attributes.Append(element->GetAttribute(index));
    }
    if (!OpenElement(element->GetName(), attributes)) {
        return false;
    }
    if (element->GetValue()[0] != '\0') {
        if (!WriteIndent() || !WriteEscaped(element->GetValue())
            || std::fputc('\n', xmlFile) == EOF) return false;
    }
    for (int index = 0; index < element->NumChildren(); ++index) {
        if (!WriteElement_R(element->GetChild(index))) return false;
    }
    return CloseElement();
}

bool idXMLWriter::WriteDocument(const idXMLElement* const root) {
    return xmlFile != nullptr && !hasRoot && WriteElement_R(root);
}
