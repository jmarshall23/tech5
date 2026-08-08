#pragma once

#include "../text/str.h"

class idXMLAttribute {
public:
    idXMLAttribute(const char* attributeName = "", const char* attributeValue = "")
        : name(attributeName), value(attributeValue) {
        name.TrimWhitespaceRecovered();
    }

    const char* GetName() const { return name.c_str(); }
    const char* GetValue() const { return value.c_str(); }
    void SetValue(const char* newValue) { value = newValue; }
    void FormatEntities() {
        name.ReplaceRecovered("&amp;", "&");
        name.ReplaceRecovered("&lt;", "<");
        name.ReplaceRecovered("&gt;", ">");
        value.ReplaceRecovered("&amp;", "&");
        value.ReplaceRecovered("&lt;", "<");
        value.ReplaceRecovered("&gt;", ">");
    }

private:
    idStr name;
    idStr value;
};

static_assert(sizeof(idXMLAttribute) == 64,
    "Recovered idXMLAttribute ABI changed");
