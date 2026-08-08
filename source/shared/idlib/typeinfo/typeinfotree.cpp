#include "typeinfotree.h"
#include "typeinfofile.h"

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

idTypeInfoTree::idTypeInfoTree() : root(nullptr), nodeBlockAlloc{} {
    nodeBlockAlloc.allowAllocs = true;
}

idTypeInfoTree::idTypeInfoTree(const char* text, const int length)
    : idTypeInfoTree() {
    if (text == nullptr || length <= 0) return;
    idTypeInfoFile file;
    file.settings.resolveEntityPointers = false;
    file.settings.resolveModelPointers = false;
    if (file.ReadMemory(text, length, "", 1)) Parse(file);
}

idTypeInfoTree::~idTypeInfoTree() {
    Clear();
}

void idTypeInfoTree::WriteType_r(idTypeInfoFile& file,
        idTypeInfoNode* node, const bool onlyDiff) const {
    if (node == nullptr || (onlyDiff && !node->diff)) return;
    file.WriteType(node->type.c_str(), node->ops.c_str(), node->name.c_str());
    file.WriteSkipObject(node->skip);
    if (node->children != nullptr) {
        file.WriteOpeningBrace();
        file.WriteComment(node->comment.c_str());
        for (idTypeInfoNode* child = node->children; child != nullptr;
                child = child->next) {
            WriteType_r(file, child, onlyDiff);
        }
        file.WriteClosingBrace();
    } else if (node->value.Length() != 0) {
        file.WriteValueString(node->value);
        file.WriteComment(node->comment.c_str());
    } else {
        file.WriteOpeningBrace();
        file.WriteComment(node->comment.c_str());
        file.WriteClosingBrace();
    }
}

void idTypeInfoTree::Write(idTypeInfoFile& file, const bool onlyDiff) const {
    for (idTypeInfoNode* node = root; node != nullptr; node = node->next) {
        WriteType_r(file, node, onlyDiff);
    }
}

idTypeInfoNode* idTypeInfoTree::ReadType_r(idTypeInfoFile& file,
        idTypeInfoNode* parentNode, const bool overwrite) {
    idTypeInfoNode* first = parentNode == nullptr ? root : parentNode->children;
    idTypeInfoNode* tail = first;
    while (tail != nullptr && tail->next != nullptr) tail = tail->next;

    while (!file.CheckClosingBrace()) {
        idStr type, ops, name;
        int arrayIndex = -1;
        if (!file.CheckArrayElementType(type, ops, name, arrayIndex)) break;
        if (arrayIndex >= 0) {
            char suffix[48];
            std::snprintf(suffix, sizeof(suffix), "[%d]", arrayIndex);
            name.Append(suffix);
        }

        const bool skip = file.CheckSkipObject();
        idStr value, comment;
        const bool hasChildren = file.CheckOpeningBrace();
        if (hasChildren) file.ReadComment(comment);
        else {
            file.ReadValueString(value);
            file.ReadComment(comment);
        }

        idTypeInfoNode* node = nullptr;
        if (overwrite) {
            node = FindAndOverwriteNode(type.c_str(), ops.c_str(),
                name.c_str(), value.c_str(), comment.c_str(), parentNode);
        }
        if (node == nullptr) {
            node = InsertNode(type.c_str(), ops.c_str(), name.c_str(),
                value.c_str(), comment.c_str(), parentNode, tail);
            if (first == nullptr) first = node;
            tail = node;
        }
        if (node == nullptr) break;
        node->skip = skip;
        if (hasChildren) ReadType_r(file, node, overwrite);
    }
    return first;
}

void idTypeInfoTree::Parse(idTypeInfoFile& file) {
    Clear();
    root = ReadType_r(file, nullptr, false);
}

void idTypeInfoTree::ParseOverwrite(idTypeInfoFile& file) {
    root = ReadType_r(file, nullptr, root != nullptr);
    RemoveOutOfBoundsMembers();
}

bool idTypeInfoTree::EqualNoCase(const char* left, const char* right,
        const int prefixLength) {
    const unsigned char* a = reinterpret_cast<const unsigned char*>(
        left == nullptr ? "" : left);
    const unsigned char* b = reinterpret_cast<const unsigned char*>(
        right == nullptr ? "" : right);
    int compared = 0;
    while ((prefixLength < 0 || compared < prefixLength)
            && (*a != 0 || *b != 0)) {
        if (std::tolower(*a) != std::tolower(*b)) return false;
        ++a;
        ++b;
        ++compared;
    }
    return prefixLength >= 0 || *a == *b;
}

idTypeInfoNode* idTypeInfoTree::InsertNode(const char* type, const char* ops,
        const char* name, const char* value, const char* comment,
        idTypeInfoNode* parentNode, idTypeInfoNode* nodeAfter) {
    idTypeInfoNode* const node = new (std::nothrow) idTypeInfoNode;
    if (node == nullptr) return nullptr;
    node->type = type == nullptr ? "" : type;
    node->ops = ops == nullptr ? "" : ops;
    node->name = name == nullptr ? "" : name;
    node->value = value == nullptr ? "" : value;
    node->comment = comment == nullptr ? "" : comment;
    node->next = nullptr;
    node->children = nullptr;
    node->parent = parentNode;
    node->skip = false;
    node->diff = true;
    ++nodeBlockAlloc.total;
    ++nodeBlockAlloc.active;

    idTypeInfoNode** head = parentNode == nullptr ? &root : &parentNode->children;
    if (nodeAfter != nullptr) {
        node->next = nodeAfter->next;
        nodeAfter->next = node;
    } else if (*head == nullptr) {
        *head = node;
    } else {
        idTypeInfoNode* tail = *head;
        while (tail->next != nullptr) tail = tail->next;
        tail->next = node;
    }
    return node;
}

idTypeInfoNode* idTypeInfoTree::SetRoot(const char* type, const char* name,
        const char* value, const char* ops, const char* comment) {
    Clear();
    return InsertNode(type, ops, name, value, comment, nullptr);
}

idTypeInfoNode* idTypeInfoTree::FindAndOverwriteNode(const char* type,
        const char* ops, const char* name, const char* value,
        const char* comment, idTypeInfoNode* parentNode) {
    idTypeInfoNode* node = parentNode == nullptr ? root : parentNode->children;
    while (node != nullptr && std::strcmp(node->name.c_str(), name) != 0) {
        node = node->next;
    }
    if (node == nullptr) return nullptr;
    node->type = type;
    node->ops = ops;
    node->value = value;
    node->comment = comment;
    return node;
}

idTypeInfoPath* idTypeInfoTree::ParsePath(const char* path) {
    if (path == nullptr || *path == '\0') return nullptr;
    idTypeInfoPath* first = nullptr;
    idTypeInfoPath* last = nullptr;
    const char* cursor = path;
    while (*cursor != '\0') {
        const char* begin = cursor;
        int bracketDepth = 0;
        while (*cursor != '\0') {
            if (*cursor == '[') ++bracketDepth;
            if (*cursor == ']') --bracketDepth;
            if (*cursor == '.' && bracketDepth == 0) break;
            ++cursor;
        }
        char segment[256] = {};
        const std::size_t length = static_cast<std::size_t>(cursor - begin);
        if (length == 0 || length >= sizeof(segment)) {
            delete first;
            return nullptr;
        }
        std::memcpy(segment, begin, length);
        idTypeInfoPath* const part = new (std::nothrow) idTypeInfoPath(segment);
        if (part == nullptr) {
            delete first;
            return nullptr;
        }
        if (last == nullptr) first = part;
        else last->next = part;
        last = part;
        if (*cursor == '.') ++cursor;
    }
    return first;
}

idTypeInfoNode* idTypeInfoTree::FindPath(idTypeInfoNode* baseNode,
        const idTypeInfoPath* path) {
    if (baseNode == nullptr || path == nullptr) return nullptr;
    if (std::strcmp(baseNode->name.c_str(), path->name.c_str()) == 0) {
        path = path->next;
        if (path == nullptr) return baseNode;
    }
    idTypeInfoNode* children = baseNode->children;
    while (path != nullptr) {
        while (children != nullptr
                && std::strcmp(children->name.c_str(), path->name.c_str()) != 0) {
            children = children->next;
        }
        if (children == nullptr) return nullptr;
        path = path->next;
        if (path == nullptr) return children;
        children = children->children;
    }
    return nullptr;
}

idTypeInfoNode* idTypeInfoTree::FindPath(idTypeInfoNode* startNode,
        const char* path) const {
    idTypeInfoPath* const parsed = ParsePath(path);
    idTypeInfoNode* const result = FindPath(startNode, parsed);
    delete parsed;
    return result;
}

idTypeInfoNode* idTypeInfoTree::CreatePath(const char* path,
        const idTypeInfoTools*) {
    if (root == nullptr) return nullptr;
    idTypeInfoPath* parsed = ParsePath(path);
    if (parsed == nullptr) return nullptr;
    idTypeInfoPath* part = parsed;
    idTypeInfoNode* current = root;
    if (std::strcmp(current->name.c_str(), part->name.c_str()) == 0) part = part->next;
    while (part != nullptr) {
        idTypeInfoNode* child = current->children;
        while (child != nullptr
                && std::strcmp(child->name.c_str(), part->name.c_str()) != 0) {
            child = child->next;
        }
        if (child == nullptr) {
            child = InsertNode("", "", part->name.c_str(), "", "", current);
            if (child == nullptr) break;
        }
        current = child;
        part = part->next;
    }
    delete parsed;
    return part == nullptr ? current : nullptr;
}

void idTypeInfoTree::FreeTree_r(idTypeInfoNode* node) {
    while (node != nullptr) {
        idTypeInfoNode* const next = node->next;
        FreeTree_r(node->children);
        delete node;
        --nodeBlockAlloc.active;
        node = next;
    }
}

void idTypeInfoTree::Clear() {
    FreeTree_r(root);
    root = nullptr;
    nodeBlockAlloc.total = 0;
    nodeBlockAlloc.active = 0;
}

void idTypeInfoTree::GetPath(const idTypeInfoNode* baseNode,
        const idTypeInfoNode* node, idStr& path) const {
    path.Clear();
    if (baseNode == nullptr || node == nullptr) return;
    const idTypeInfoNode* chain[128] = {};
    int count = 0;
    for (const idTypeInfoNode* current = node;
            current != nullptr && current != baseNode && count < 128;
            current = current->parent) chain[count++] = current;
    for (int index = count - 1; index >= 0; --index) {
        path.Append(chain[index]->name);
        if (index > 0) path.Append('.');
    }
}

idTypeInfoNode* idTypeInfoTree::FindMatchingLeaf(const idTypeInfoTree& tree,
        const idTypeInfoNode* node) {
    if (tree.root == nullptr || node == nullptr) return nullptr;
    const idTypeInfoNode* chain[128] = {};
    int count = 0;
    for (const idTypeInfoNode* current = node; current != nullptr && count < 128;
            current = current->parent) chain[count++] = current;
    idTypeInfoNode* candidate = tree.root;
    if (count == 0 || std::strcmp(candidate->name.c_str(),
            chain[count - 1]->name.c_str()) != 0) return nullptr;
    for (int index = count - 2; index >= 0; --index) {
        candidate = candidate->children;
        while (candidate != nullptr && std::strcmp(candidate->name.c_str(),
                chain[index]->name.c_str()) != 0) candidate = candidate->next;
        if (candidate == nullptr) return nullptr;
    }
    return candidate;
}

void idTypeInfoTree::MarkDifferent(idTypeInfoNode* node) {
    for (; node != nullptr; node = node->parent) node->diff = true;
}

void idTypeInfoTree::Diff_r(const idTypeInfoTree& other, idTypeInfoNode* node) {
    for (idTypeInfoNode* current = node; current != nullptr; current = current->next) {
        current->diff = false;
        if (current->children != nullptr) Diff_r(other, current->children);
        idTypeInfoNode* const match = FindMatchingLeaf(other, current);
        if (match == nullptr || (current->children == nullptr
                && std::strcmp(match->value.c_str(), current->value.c_str()) != 0)) {
            MarkDifferent(current);
        }
    }
}

void idTypeInfoTree::Diff(const idTypeInfoTree& other) {
    Diff_r(other, root);
}

void idTypeInfoTree::ForceRootDifferent(const bool set) {
    if (root != nullptr) root->diff = set;
}

bool idTypeInfoTree::IsSkipped(const char* path) const {
    idTypeInfoNode* const node = FindPath(root, path);
    return node != nullptr && node->skip;
}

bool idTypeInfoTree::GetInt(const char* path, int& result) const {
    result = 0;
    idTypeInfoNode* const node = FindPath(root, path);
    if (node == nullptr) return false;
    result = std::atoi(node->value.c_str());
    return true;
}

bool idTypeInfoTree::GetStr(const char* path, idStr& result) const {
    result.Clear();
    idTypeInfoNode* const node = FindPath(root, path);
    if (node == nullptr) return false;
    result = node->value;
    return true;
}

bool idTypeInfoTree::SetStr(const char* path, const char* newValue) {
    idTypeInfoNode* node = FindPath(root, path);
    if (node == nullptr) node = CreatePath(path);
    if (node == nullptr) return false;
    node->value = newValue == nullptr ? "" : newValue;
    MarkDifferent(node);
    return true;
}

bool idTypeInfoTree::GetBool(const char* path, bool& result) const {
    result = false;
    idTypeInfoNode* const node = FindPath(root, path);
    if (node == nullptr) return false;
    result = EqualNoCase(node->value.c_str(), "true")
        || std::atoi(node->value.c_str()) == 1;
    return true;
}

bool idTypeInfoTree::GetVec3(const char* path, idVec3& result) const {
    result.Zero();
    bool found = false;
    for (int index = 0; index < 3; ++index) {
        char componentPath[1024] = {};
        std::snprintf(componentPath, sizeof(componentPath), "%s.%c", path,
            'x' + index);
        idTypeInfoNode* const node = FindPath(root, componentPath);
        if (node != nullptr && node->value.Length() > 0) {
            result[index] = static_cast<float>(std::atof(node->value.c_str()));
            found = true;
        }
    }
    return found;
}

bool idTypeInfoTree::SetVec3(const char* path, const idVec3& value) {
    bool changed = false;
    for (int index = 0; index < 3; ++index) {
        char componentPath[1024] = {};
        char text[64] = {};
        std::snprintf(componentPath, sizeof(componentPath), "%s.%c", path,
            'x' + index);
        std::snprintf(text, sizeof(text), "%.9g", value[index]);
        changed = SetStr(componentPath, text) || changed;
    }
    return changed;
}

bool idTypeInfoTree::GetMat3(const char* path, idMat3& result) const {
    result = idMat3(1.0f);
    bool found = false;
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            char componentPath[1024] = {};
            std::snprintf(componentPath, sizeof(componentPath),
                "%s.mat.mat[%d].%c", path, row, 'x' + column);
            idTypeInfoNode* const node = FindPath(root, componentPath);
            if (node != nullptr && node->value.Length() > 0) {
                result[row][column] = static_cast<float>(
                    std::atof(node->value.c_str()));
                found = true;
            }
        }
    }
    return found;
}

bool idTypeInfoTree::SetMat3(const char* path, const idMat3& value) {
    bool changed = false;
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            char componentPath[1024] = {};
            char text[64] = {};
            std::snprintf(componentPath, sizeof(componentPath),
                "%s.mat.mat[%d].%c", path, row, 'x' + column);
            std::snprintf(text, sizeof(text), "%.9g", value[row][column]);
            changed = SetStr(componentPath, text) || changed;
        }
    }
    return changed;
}

bool idTypeInfoTree::GetStrType(const char* path, idStr& result) const {
    if (!GetStr(path, result)) return false;
    const char* text = result.c_str();
    const int length = result.Length();
    if (length >= 2 && text[0] == '"' && text[length - 1] == '"') {
        idStr decoded;
        for (int index = 1; index < length - 1; ++index) {
            if (text[index] == '\\' && index + 1 < length - 1) ++index;
            decoded.Append(text[index]);
        }
        result = decoded;
    } else if (std::strcmp(text, "NULL") == 0) {
        result.Clear();
    }
    return true;
}

bool idTypeInfoTree::SetStrType(const char* path, const char* value) {
    if (value == nullptr) return SetStr(path, "NULL");
    idStr quoted("\"");
    for (const char* cursor = value; *cursor != '\0'; ++cursor) {
        if (*cursor == '\\' || *cursor == '"') quoted.Append('\\');
        quoted.Append(*cursor);
    }
    quoted.Append('"');
    return SetStr(path, quoted.c_str());
}

void idTypeInfoTree::GetTypes_r(idTypeInfoNode* node, const char* type,
        const char* ops, idTypeInfoNodeList<idTypeInfoNode*>& nodes) const {
    for (idTypeInfoNode* current = node; current != nullptr; current = current->next) {
        const int prefix = static_cast<int>(std::strlen(type == nullptr ? "" : type));
        if (EqualNoCase(current->type.c_str(), type, prefix)
                && EqualNoCase(current->ops.c_str(), ops)) nodes.Append(current);
        GetTypes_r(current->children, type, ops, nodes);
    }
}

void idTypeInfoTree::GetTypes(const char* type, const char* ops,
        idTypeInfoNodeList<idTypeInfoNode*>& nodes) const {
    GetTypes_r(root, type, ops, nodes);
}

void idTypeInfoTree::RemoveOutOfBoundsMembers_r(idTypeInfoNode* node) {
    for (idTypeInfoNode* current = node; current != nullptr; current = current->next) {
        int count = -1;
        for (idTypeInfoNode* child = current->children; child != nullptr;
                child = child->next) {
            if (std::strcmp(child->name.c_str(), "num") == 0) {
                count = std::atoi(child->value.c_str());
                break;
            }
        }
        if (count >= 0) {
            idTypeInfoNode** link = &current->children;
            while (*link != nullptr) {
                idTypeInfoNode* child = *link;
                int index = -1;
                if (std::strncmp(child->name.c_str(), "item[", 5) == 0) {
                    index = std::atoi(child->name.c_str() + 5);
                }
                if (index >= count) {
                    *link = child->next;
                    child->next = nullptr;
                    FreeTree_r(child);
                } else {
                    link = &child->next;
                }
            }
        }
        RemoveOutOfBoundsMembers_r(current->children);
    }
}

void idTypeInfoTree::RemoveOutOfBoundsMembers() {
    RemoveOutOfBoundsMembers_r(root);
}
