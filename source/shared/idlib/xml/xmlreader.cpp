#include "xmlreader.h"

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

idXMLReader::idXMLReader(const char* const fileName)
    : sourceName(fileName), document(nullptr), cursor(nullptr), end(nullptr) {
    FILE* file = nullptr;
    if (fileName == nullptr || fopen_s(&file, fileName, "rb") != 0
        || file == nullptr) {
        return;
    }
    std::fseek(file, 0, SEEK_END);
    const long length = std::ftell(file);
    std::fseek(file, 0, SEEK_SET);
    if (length >= 0) {
        document = static_cast<char*>(std::malloc(static_cast<std::size_t>(length) + 1));
        if (document != nullptr) {
            const std::size_t read = std::fread(document, 1,
                static_cast<std::size_t>(length), file);
            document[read] = '\0';
            cursor = document;
            end = document + read;
        }
    }
    std::fclose(file);
}

idXMLReader::~idXMLReader() {
    std::free(document);
}

void idXMLReader::SkipWhitespace() {
    while (cursor < end
        && std::isspace(static_cast<unsigned char>(*cursor)) != 0) {
        ++cursor;
    }
}

bool idXMLReader::Consume(const char character) {
    if (cursor < end && *cursor == character) {
        ++cursor;
        return true;
    }
    return false;
}

bool idXMLReader::Consume(const char* const text) {
    const std::size_t length = std::strlen(text);
    if (static_cast<std::size_t>(end - cursor) >= length
        && std::memcmp(cursor, text, length) == 0) {
        cursor += length;
        return true;
    }
    return false;
}

bool idXMLReader::SkipMisc() {
    SkipWhitespace();
    if (Consume("<?")) {
        const char* close = std::strstr(cursor, "?>");
        if (close == nullptr || close > end) return false;
        cursor = close + 2;
        return true;
    }
    if (Consume("<!--")) {
        const char* close = std::strstr(cursor, "-->");
        if (close == nullptr || close > end) return false;
        cursor = close + 3;
        return true;
    }
    return false;
}

idStr idXMLReader::ReadName() {
    idStr result;
    while (cursor < end) {
        const unsigned char character = static_cast<unsigned char>(*cursor);
        if (std::isalnum(character) == 0 && character != '_'
            && character != '-' && character != ':' && character != '.'
            && character != '&' && character != ';' && character != '#') {
            break;
        }
        result.Append(*cursor++);
    }
    return result;
}

idStr idXMLReader::ReadQuotedValue() {
    idStr result;
    if (cursor >= end || (*cursor != '"' && *cursor != '\'')) {
        return result;
    }
    const char quote = *cursor++;
    while (cursor < end && *cursor != quote) {
        result.Append(*cursor++);
    }
    Consume(quote);
    return result;
}

idXMLElement* idXMLReader::ReadElement_R() {
    SkipWhitespace();
    while (SkipMisc()) {
        SkipWhitespace();
    }
    if (!Consume('<') || (cursor < end && *cursor == '/')) {
        return nullptr;
    }
    const idStr name = ReadName();
    if (name.Length() == 0) {
        return nullptr;
    }
    idXMLElement* const element = idXMLElement::Create(name.c_str());
    if (element == nullptr) {
        return nullptr;
    }

    for (;;) {
        SkipWhitespace();
        if (Consume("/>")) {
            return element;
        }
        if (Consume('>')) {
            break;
        }
        const idStr attributeName = ReadName();
        SkipWhitespace();
        if (attributeName.Length() == 0 || !Consume('=')) {
            idXMLElement::Destroy(element);
            return nullptr;
        }
        SkipWhitespace();
        const idStr attributeValue = ReadQuotedValue();
        if (element->AddAttribute(attributeName.c_str(), attributeValue.c_str()) == nullptr) {
            idXMLElement::Destroy(element);
            return nullptr;
        }
    }

    for (;;) {
        if (cursor >= end) {
            idXMLElement::Destroy(element);
            return nullptr;
        }
        if (Consume("<!--")) {
            const char* close = std::strstr(cursor, "-->");
            if (close == nullptr || close > end) {
                idXMLElement::Destroy(element);
                return nullptr;
            }
            cursor = close + 3;
            continue;
        }
        if (Consume("<![CDATA[")) {
            const char* close = std::strstr(cursor, "]]>");
            if (close == nullptr || close > end) {
                idXMLElement::Destroy(element);
                return nullptr;
            }
            while (cursor < close) element->AppendValue(*cursor++);
            cursor = close + 3;
            continue;
        }
        if (Consume("</")) {
            const idStr closeName = ReadName();
            SkipWhitespace();
            if (!Consume('>') || std::strcmp(name.c_str(), closeName.c_str()) != 0) {
                idXMLElement::Destroy(element);
                return nullptr;
            }
            return element;
        }
        if (*cursor == '<') {
            idXMLElement* const child = ReadElement_R();
            if (child == nullptr || !element->AdoptChild(child)) {
                idXMLElement::Destroy(child);
                idXMLElement::Destroy(element);
                return nullptr;
            }
        } else {
            element->AppendValue(*cursor++);
        }
    }
}

idXMLElement* idXMLReader::ReadDocument() {
    if (document == nullptr) {
        return nullptr;
    }
    cursor = document;
    while (SkipMisc()) {
    }
    idXMLElement* const root = ReadElement_R();
    if (root != nullptr) {
        root->FormatStrings();
    }
    return root;
}
