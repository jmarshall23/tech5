#pragma once

#include "xmlelement.h"

class idXMLReader {
public:
    explicit idXMLReader(const char* fileName);
    ~idXMLReader();

    idXMLElement* ReadDocument();
    bool IsLoaded() const { return document != nullptr; }

private:
    idStr sourceName;
    char* document;
    const char* cursor;
    const char* end;

    void SkipWhitespace();
    bool SkipMisc();
    bool Consume(char character);
    bool Consume(const char* text);
    idStr ReadName();
    idStr ReadQuotedValue();
    idXMLElement* ReadElement_R();
};
