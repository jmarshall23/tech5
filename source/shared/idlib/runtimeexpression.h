#pragma once

#include "text/str.h"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

template<typename varType, typename varContextType>
class idRuntimeExpression {
public:
    enum { MAX_NODES = 253, INVALID_INDEX = 255 };

    class ExpNode {
    public:
        enum op_t {
            OP_NONE = 0,
            OP_VAL,
            OP_VAR,
            OP_MUL,
            OP_DIV,
            OP_MAX,
            OP_MIN,
            OP_LERP,
            OP_CLAMP,
            OP_SUB,
            OP_ADD
        };

        ExpNode()
            : coef(1.0f), op(OP_NONE), parent(INVALID_INDEX),
              var0(INVALID_INDEX), var1(INVALID_INDEX), var2(INVALID_INDEX),
              varId() {
        }

        float coef;
        op_t op;
        std::uint8_t parent;
        std::uint8_t var0;
        std::uint8_t var1;
        std::uint8_t var2;
        varType varId;
    };

    idRuntimeExpression()
        : root(INVALID_INDEX), nodes(nullptr), numNodes(0), capacity(0),
          granularity(5), memTag(5), listStatic(0) {
    }

    ~idRuntimeExpression() {
        Clear();
    }

    idRuntimeExpression(const idRuntimeExpression&) = delete;
    idRuntimeExpression& operator=(const idRuntimeExpression&) = delete;

    bool Parse(const char* expression, varContextType& context) {
        Clear();
        const char* cursor = expression == nullptr ? "" : expression;
        const int parsedRoot = ParseAddSub(cursor, context);
        SkipWhitespace(cursor);
        if (parsedRoot == INVALID_INDEX || *cursor != '\0') {
            Clear();
            return false;
        }
        root = parsedRoot;
        return true;
    }

    float Eval(varContextType& context) const {
        return root == INVALID_INDEX ? 0.0f : EvalNode(root, context);
    }

    idStr PrintExp() const {
        return root == INVALID_INDEX ? idStr() : PrintNode(root);
    }

    int NumNodes() const { return numNodes; }

    void Clear() {
        if (nodes != nullptr) {
            for (int index = 0; index < capacity; ++index) {
                nodes[index].~ExpNode();
            }
            std::free(nodes);
        }
        root = INVALID_INDEX;
        nodes = nullptr;
        numNodes = 0;
        capacity = 0;
    }

private:
    int root;
    ExpNode* nodes;
    int numNodes;
    int capacity;
    std::int16_t granularity;
    std::uint8_t memTag;
    std::uint8_t listStatic;

    static void SkipWhitespace(const char*& cursor) {
        while (std::isspace(static_cast<unsigned char>(*cursor)) != 0) {
            ++cursor;
        }
    }

    bool Grow() {
        if (capacity >= MAX_NODES) {
            return false;
        }
		const int newCapacity = std::min(static_cast<int>(MAX_NODES),
            capacity + (granularity > 0 ? granularity : 5));
        ExpNode* const replacement = static_cast<ExpNode*>(
            std::malloc(sizeof(ExpNode) * static_cast<std::size_t>(newCapacity))
        );
        if (replacement == nullptr) {
            return false;
        }
        for (int index = 0; index < newCapacity; ++index) {
            new (&replacement[index]) ExpNode();
        }
        for (int index = 0; index < numNodes; ++index) {
            replacement[index] = nodes[index];
        }
        if (nodes != nullptr) {
            for (int index = 0; index < capacity; ++index) {
                nodes[index].~ExpNode();
            }
            std::free(nodes);
        }
        nodes = replacement;
        capacity = newCapacity;
        return true;
    }

    int AddNode(const typename ExpNode::op_t op, const int child0 = INVALID_INDEX,
        const int child1 = INVALID_INDEX, const int child2 = INVALID_INDEX,
        const float coefficient = 1.0f, const varType* variable = nullptr) {
        if (numNodes == capacity && !Grow()) {
            return INVALID_INDEX;
        }
        const int index = numNodes++;
        ExpNode& node = nodes[index];
        node.op = op;
        node.coef = coefficient;
        node.var0 = static_cast<std::uint8_t>(child0);
        node.var1 = static_cast<std::uint8_t>(child1);
        node.var2 = static_cast<std::uint8_t>(child2);
        if (variable != nullptr) {
            node.varId = *variable;
        }
        if (child0 != INVALID_INDEX) nodes[child0].parent = static_cast<std::uint8_t>(index);
        if (child1 != INVALID_INDEX) nodes[child1].parent = static_cast<std::uint8_t>(index);
        if (child2 != INVALID_INDEX) nodes[child2].parent = static_cast<std::uint8_t>(index);
        return index;
    }

    int ParseAddSub(const char*& cursor, varContextType& context) {
        int left = ParseMulDiv(cursor, context);
        while (left != INVALID_INDEX) {
            SkipWhitespace(cursor);
            const char operation = *cursor;
            if (operation != '+' && operation != '-') break;
            ++cursor;
            const int right = ParseMulDiv(cursor, context);
            if (right == INVALID_INDEX) return INVALID_INDEX;
            left = AddNode(operation == '+' ? ExpNode::OP_ADD : ExpNode::OP_SUB,
                left, right);
        }
        return left;
    }

    int ParseMulDiv(const char*& cursor, varContextType& context) {
        int left = ParseUnary(cursor, context);
        while (left != INVALID_INDEX) {
            SkipWhitespace(cursor);
            const char operation = *cursor;
            if (operation != '*' && operation != '/') break;
            ++cursor;
            const int right = ParseUnary(cursor, context);
            if (right == INVALID_INDEX) return INVALID_INDEX;
            left = AddNode(operation == '*' ? ExpNode::OP_MUL : ExpNode::OP_DIV,
                left, right);
        }
        return left;
    }

    int ParseUnary(const char*& cursor, varContextType& context) {
        SkipWhitespace(cursor);
        if (*cursor == '+') {
            ++cursor;
            return ParseUnary(cursor, context);
        }
        if (*cursor == '-') {
            ++cursor;
            const int child = ParseUnary(cursor, context);
            return child == INVALID_INDEX ? INVALID_INDEX
                : AddNode(ExpNode::OP_MUL, child, INVALID_INDEX,
                    INVALID_INDEX, -1.0f);
        }
        return ParsePrimary(cursor, context);
    }

    int ParsePrimary(const char*& cursor, varContextType& context) {
        SkipWhitespace(cursor);
        if (*cursor == '(') {
            ++cursor;
            const int result = ParseAddSub(cursor, context);
            SkipWhitespace(cursor);
            if (*cursor != ')') return INVALID_INDEX;
            ++cursor;
            return result;
        }
        if (std::isdigit(static_cast<unsigned char>(*cursor)) != 0
            || *cursor == '.') {
            char* numberEnd = nullptr;
            const float value = std::strtof(cursor, &numberEnd);
            if (numberEnd == cursor) return INVALID_INDEX;
            cursor = numberEnd;
            return AddNode(ExpNode::OP_VAL, INVALID_INDEX, INVALID_INDEX,
                INVALID_INDEX, value);
        }

        char name[128];
        int nameLength = 0;
        while ((std::isalnum(static_cast<unsigned char>(*cursor)) != 0
            || *cursor == '_' || *cursor == '.') && nameLength < 127) {
            name[nameLength++] = *cursor++;
        }
        name[nameLength] = '\0';
        if (nameLength == 0) return INVALID_INDEX;
        SkipWhitespace(cursor);
        if (*cursor != '(') {
            varType variable;
            if (!context.LookUpVar(name, variable)) return INVALID_INDEX;
            return AddNode(ExpNode::OP_VAR, INVALID_INDEX, INVALID_INDEX,
                INVALID_INDEX, 1.0f, &variable);
        }

        ++cursor;
        const int first = ParseAddSub(cursor, context);
        SkipWhitespace(cursor);
        if (first == INVALID_INDEX || *cursor != ',') return INVALID_INDEX;
        ++cursor;
        const int second = ParseAddSub(cursor, context);
        if (second == INVALID_INDEX) return INVALID_INDEX;
        int third = INVALID_INDEX;
        SkipWhitespace(cursor);
        if (*cursor == ',') {
            ++cursor;
            third = ParseAddSub(cursor, context);
            if (third == INVALID_INDEX) return INVALID_INDEX;
        }
        SkipWhitespace(cursor);
        if (*cursor != ')') return INVALID_INDEX;
        ++cursor;

        typename ExpNode::op_t operation = ExpNode::OP_NONE;
        if (std::strcmp(name, "max") == 0 && third == INVALID_INDEX) operation = ExpNode::OP_MAX;
        else if (std::strcmp(name, "min") == 0 && third == INVALID_INDEX) operation = ExpNode::OP_MIN;
        else if (std::strcmp(name, "lerp") == 0 && third != INVALID_INDEX) operation = ExpNode::OP_LERP;
        else if (std::strcmp(name, "clamp") == 0 && third != INVALID_INDEX) operation = ExpNode::OP_CLAMP;
        if (operation == ExpNode::OP_NONE) return INVALID_INDEX;
        return AddNode(operation, first, second, third);
    }

    float EvalNode(const int index, varContextType& context) const {
        const ExpNode& node = nodes[index];
        const float first = node.var0 == INVALID_INDEX ? 0.0f
            : EvalNode(node.var0, context);
        const float second = node.var1 == INVALID_INDEX ? 0.0f
            : EvalNode(node.var1, context);
        const float third = node.var2 == INVALID_INDEX ? 0.0f
            : EvalNode(node.var2, context);
        float value = 0.0f;
        switch (node.op) {
            case ExpNode::OP_VAL: value = 1.0f; break;
            case ExpNode::OP_VAR: value = context.GetVar(node.varId); break;
            case ExpNode::OP_MUL:
                value = node.var1 == INVALID_INDEX ? first : first * second;
                break;
            case ExpNode::OP_DIV: value = first / second; break;
            case ExpNode::OP_MAX: value = std::max(first, second); break;
            case ExpNode::OP_MIN: value = std::min(first, second); break;
            case ExpNode::OP_LERP: value = first + (second - first) * third; break;
            case ExpNode::OP_CLAMP: value = std::max(first, std::min(second, third)); break;
            case ExpNode::OP_SUB: value = first - second; break;
            case ExpNode::OP_ADD: value = first + second; break;
            default: value = 0.0f; break;
        }
        return node.coef * value;
    }

    idStr PrintNode(const int index) const {
        const ExpNode& node = nodes[index];
        if (node.op == ExpNode::OP_VAL) {
            char number[64];
            std::snprintf(number, sizeof(number), "%g", node.coef);
            return idStr(number);
        }
        if (node.op == ExpNode::OP_VAR) {
            idStr result = node.varId.GetStr();
            if (node.coef != 1.0f) {
                char prefix[64];
                std::snprintf(prefix, sizeof(prefix), "%g*", node.coef);
                idStr scaled(prefix);
                scaled.Append(result);
                return scaled;
            }
            return result;
        }
        const char* opName = nullptr;
        switch (node.op) {
            case ExpNode::OP_MUL: opName = "*"; break;
            case ExpNode::OP_DIV: opName = "/"; break;
            case ExpNode::OP_SUB: opName = "-"; break;
            case ExpNode::OP_ADD: opName = "+"; break;
            case ExpNode::OP_MAX: opName = "max"; break;
            case ExpNode::OP_MIN: opName = "min"; break;
            case ExpNode::OP_LERP: opName = "lerp"; break;
            case ExpNode::OP_CLAMP: opName = "clamp"; break;
            default: return idStr();
        }
        idStr result;
        if (node.op == ExpNode::OP_MAX || node.op == ExpNode::OP_MIN
            || node.op == ExpNode::OP_LERP || node.op == ExpNode::OP_CLAMP) {
            result.Append(opName);
            result.Append('(');
            result.Append(PrintNode(node.var0));
            result.Append(", ");
            result.Append(PrintNode(node.var1));
            if (node.var2 != INVALID_INDEX) {
                result.Append(", ");
                result.Append(PrintNode(node.var2));
            }
            result.Append(')');
        } else if (node.var1 == INVALID_INDEX) {
            char coefficient[64];
            std::snprintf(coefficient, sizeof(coefficient), "%g*", node.coef);
            result.Append(coefficient);
            result.Append(PrintNode(node.var0));
            return result;
        } else {
            result.Append('(');
            result.Append(PrintNode(node.var0));
            result.Append(' ');
            result.Append(opName);
            result.Append(' ');
            result.Append(PrintNode(node.var1));
            result.Append(')');
        }
        if (node.coef != 1.0f) {
            char coefficient[64];
            std::snprintf(coefficient, sizeof(coefficient), "%g*", node.coef);
            idStr scaled(coefficient);
            scaled.Append(result);
            return scaled;
        }
        return result;
    }
};

#if INTPTR_MAX == INT32_MAX
struct idRuntimeExpressionLayoutVar {
    int index;
    idStr GetStr() const { return idStr(); }
};
struct idRuntimeExpressionLayoutContext {
    bool LookUpVar(const char*, idRuntimeExpressionLayoutVar&) { return false; }
    float GetVar(const idRuntimeExpressionLayoutVar&) const { return 0.0f; }
};
static_assert(sizeof(idRuntimeExpression<idRuntimeExpressionLayoutVar,
    idRuntimeExpressionLayoutContext>) == 20,
    "Recovered idRuntimeExpression ABI changed");
#endif
