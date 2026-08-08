#include "xmlelement.h"

idXMLElement::idXMLElement(const char* const elementName)
    : name(elementName), value(), attributes(), children() {
}

idXMLElement::idXMLElement(const char* const elementName,
    const char* const elementValue)
    : name(elementName), value(elementValue), attributes(), children() {
}

idXMLElement::~idXMLElement() {
    for (int index = 0; index < children.Num(); ++index) {
        idXMLElement* const child = children[index];
        if (child != nullptr) {
            child->~idXMLElement();
            std::free(child);
        }
    }
}

idXMLAttribute* idXMLElement::AddAttribute(const char* const attributeName,
    const char* const attributeValue) {
    return attributes.Append(idXMLAttribute(attributeName, attributeValue));
}

idXMLElement* idXMLElement::AddChild(const char* const childName,
    const char* const childValue) {
    idXMLElement* const child = Create(childName, childValue);
    if (child == nullptr) {
        return nullptr;
    }
    if (children.Append(child) == nullptr) {
        Destroy(child);
        return nullptr;
    }
    return child;
}

idXMLElement* idXMLElement::Create(const char* const elementName,
    const char* const elementValue) {
    void* const storage = std::malloc(sizeof(idXMLElement));
    return storage == nullptr ? nullptr
        : new (storage) idXMLElement(elementName, elementValue);
}

void idXMLElement::Destroy(idXMLElement* const element) {
    if (element != nullptr) {
        element->~idXMLElement();
        std::free(element);
    }
}

void idXMLElement::FormatStrings() {
    FormatStrings_R(this);
}

void idXMLElement::FormatStrings_R(idXMLElement* const element) {
    for (int index = 0; index < element->children.Num(); ++index) {
        FormatStrings_R(element->children[index]);
    }
    element->name.ReplaceRecovered("&amp;", "&");
    element->name.ReplaceRecovered("&lt;", "<");
    element->name.ReplaceRecovered("&gt;", ">");
    element->value.ReplaceRecovered("&amp;", "&");
    element->value.ReplaceRecovered("&lt;", "<");
    element->value.ReplaceRecovered("&gt;", ">");
    for (int index = 0; index < element->attributes.Num(); ++index) {
        element->attributes[index].FormatEntities();
    }
}
