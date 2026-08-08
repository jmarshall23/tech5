#pragma once

#include "xmlattribute.h"

#include <cstdint>
#include <cstdlib>
#include <new>

template<typename type>
class idRecoveredList {
public:
    explicit idRecoveredList(const std::uint8_t tag = 44,
        const std::int16_t initialGranularity = 16)
        : list(nullptr), num(0), size(0), granularity(initialGranularity),
          memTag(tag), listStatic(0) {
    }

    ~idRecoveredList() {
        Clear();
    }

    idRecoveredList(const idRecoveredList&) = delete;
    idRecoveredList& operator=(const idRecoveredList&) = delete;

    int Num() const { return num; }
    type& operator[](const int index) { return list[index]; }
    const type& operator[](const int index) const { return list[index]; }

    type* Append(const type& value) {
        if (num == size && !Grow()) {
            return nullptr;
        }
        list[num] = value;
        return &list[num++];
    }

    void Clear() {
        if (list != nullptr) {
            for (int index = 0; index < size; ++index) {
                list[index].~type();
            }
            std::free(list);
        }
        list = nullptr;
        num = 0;
        size = 0;
    }

private:
    type* list;
    int num;
    int size;
    std::int16_t granularity;
    std::uint8_t memTag;
    std::uint8_t listStatic;

    bool Grow() {
        const int amount = granularity > 0 ? granularity : 16;
        const int newSize = size + amount;
        type* const replacement = static_cast<type*>(
            std::malloc(sizeof(type) * static_cast<std::size_t>(newSize))
        );
        if (replacement == nullptr) {
            return false;
        }
        for (int index = 0; index < newSize; ++index) {
            new (&replacement[index]) type();
        }
        for (int index = 0; index < num; ++index) {
            replacement[index] = list[index];
        }
        if (list != nullptr) {
            for (int index = 0; index < size; ++index) {
                list[index].~type();
            }
            std::free(list);
        }
        list = replacement;
        size = newSize;
        return true;
    }
};

static_assert(sizeof(idRecoveredList<int>) == 16,
    "Recovered idList ABI changed");

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
