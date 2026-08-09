#pragma once

#include "xmlattribute.h"
#include "../containers/recoveredlist.h"

class idXMLElement {
public:
    explicit idXMLElement(const char* elementName = "");
    idXMLElement(const char* elementName, const char* elementValue);
    ~idXMLElement();

    idXMLElement(const idXMLElement&) = delete;
    idXMLElement& operator=(const idXMLElement&) = delete;

    const char* GetName() const { return name.c_str(); }
    const char* GetValue() const { return value.c_str(); }
    void SetValue(const char* newValue) { value = newValue; }

    idXMLAttribute* AddAttribute(const char* attributeName,
        const char* attributeValue);
    idXMLElement* AddChild(const char* childName, const char* childValue = "");
    bool AdoptChild(idXMLElement* child) { return children.Append(child) != nullptr; }
    void AppendValue(const char* text) { value.Append(text); }
    void AppendValue(char character) { value.Append(character); }
    int NumAttributes() const { return attributes.Num(); }
    int NumChildren() const { return children.Num(); }
    idXMLAttribute& GetAttribute(const int index) { return attributes[index]; }
    const idXMLAttribute& GetAttribute(const int index) const { return attributes[index]; }
    idXMLElement* GetChild(const int index) { return children[index]; }
    const idXMLElement* GetChild(const int index) const { return children[index]; }

    void FormatStrings();

    static idXMLElement* Create(const char* elementName,
        const char* elementValue = "");
    static void Destroy(idXMLElement* element);

private:
    idStr name;
    idStr value;
    idRecoveredList<idXMLAttribute> attributes;
    idRecoveredList<idXMLElement*> children;

    void FormatStrings_R(idXMLElement* element);
};

static_assert(sizeof(idXMLElement) == 96,
    "Recovered idXMLElement ABI changed");
