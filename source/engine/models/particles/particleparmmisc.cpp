#include "models/particles/jobs/particleparm.h"

#include "decls/decltable.h"
#include "idlib/filesystem/file.h"
#include "idlib/lookuptable.h"
#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"

#include <cerrno>
#include <cmath>
#include <cstdlib>

namespace {

const char* const particleCalcTypeNames[] = {
    "none",
    "constant",
    "minmax",
    "curve",
    "curve_scale_bias",
    "curve_use_variance_mod_constant",
    "curve_mod_curve",
    "curve_add_curve",
    "parametricEval",
    "parametricIntegrate",
    "parametricIntegrateMinMax"
};

bool ParseNumber(const char* text, float& value) {
    if (text == nullptr || *text == '\0') return false;
    char* end = nullptr;
    errno = 0;
    const float parsed = std::strtof(text, &end);
    if (end == text || *end != '\0' || errno == ERANGE
            || !std::isfinite(parsed)) {
        return false;
    }
    value = parsed;
    return true;
}

bool ReadNumber(idParser* parser, float& value) {
    idTokenStatic<256> token;
    if (parser == nullptr || !parser->ReadToken(token)) return false;
    if (idStr::Cmp(token.c_str(), "-") == 0) {
        if (!parser->ReadToken(token) || !ParseNumber(token.c_str(), value)) {
            return false;
        }
        value = -value;
        return true;
    }
    return ParseNumber(token.c_str(), value);
}

int AddTable(const char* tableName,
    idList<const idDeclTable*, 79>& tableDecls,
    idList<idLookupTable, 79>& tables) {
    const idDeclTable* declaration = static_cast<const idDeclTable*>(
        idDeclTable::resourceList.FindWithInheritance(tableName, true));
    if (declaration == nullptr || declaration->table == nullptr) return -1;

    for (int index = 0; index < tableDecls.Num(); ++index) {
        if (tableDecls[index] == declaration) return index;
    }

    const int index = tableDecls.Append(declaration);
    if (index >= 0) tables.Append(*declaration->table);
    return index;
}

void ParseParametric(idParser* parser, idParticleParm* parm,
    idList<const idDeclTable*, 79>& tableDecls,
    idList<idLookupTable, 79>& tables) {
    idTokenStatic<256> token;
    if (!parser->ReadToken(token)) {
        parser->Error("not enough parameters");
        return;
    }

    float first = 0.0f;
    if (!ParseNumber(token.c_str(), first)) {
        parser->UnreadToken(token);
        ParseParticleParm(parser, parm, tableDecls, tables);
        return;
    }

    float last = first;
    float variance = 0.0f;
    while (parser->ReadToken(token) != 0) {
        if (idStr::Icmp(token.c_str(), "to") == 0) {
            if (!ReadNumber(parser, last)) {
                parser->Error("Missing 'to' parameter for parametric parm");
                return;
            }
        } else if (idStr::Icmp(token.c_str(), "variance") == 0) {
            if (!ReadNumber(parser, variance)) {
                parser->Error(
                    "Missing 'variance' parameter for parametric parm");
                return;
            }
        } else {
            parser->UnreadToken(token);
            break;
        }
    }
    parm->val0 = first;
    parm->val1 = last;
    parm->variance = variance;
}

const char* TableName(const idList<const idDeclTable*, 79>& tableDecls,
    const int index) {
    return index >= 0 && index < tableDecls.Num()
        && tableDecls[index] != nullptr
        ? tableDecls[index]->GetName() : "";
}

} // namespace

int ParticleCalcNameToType(const char* name) {
    if (name == nullptr) return -1;
    for (int index = 0; index < NUM_PARTICLE_EDIT_CALC_TYPES; ++index) {
        if (idStr::Icmp(name, particleCalcTypeNames[index]) == 0) {
            return index;
        }
    }
    return idStr::Icmp(name, "constant_use_variance") == 0
        ? PARTICLE_EDIT_CALC_CONSTANT : -1;
}

void ParseParticleParm(idParser* parser, idParticleParm* parm,
    idList<const idDeclTable*, 79>& tableDecls,
    idList<idLookupTable, 79>& tables) {
    if (parser == nullptr || parm == nullptr) return;
    parm->Clear();

    idTokenStatic<256> token;
    if (!parser->ReadToken(token)) {
        parser->Error("not enough parameters");
        return;
    }

    const int editTypeValue = ParticleCalcNameToType(token.c_str());
    if (editTypeValue < 0) {
        parser->Error("bad particle parm calculation type: %s",
            token.c_str());
        return;
    }
    const particleEditCalcType_t editType =
        static_cast<particleEditCalcType_t>(editTypeValue);
    parm->SetCalcTypeFromEditType(editType);

    float first = 0.0f;
    float second = 0.0f;
    switch (editType) {
    case PARTICLE_EDIT_CALC_CONSTANT:
        if (!ReadNumber(parser, first)) {
            parser->Error("particle constant: not enough parameters");
            return;
        }
        parm->val0 = first;
        parm->val1 = first;
        if (parser->ReadTokenOnLine(token) != 0) {
            if (ParseNumber(token.c_str(), second)) parm->variance = second;
            else parser->UnreadToken(token);
        }
        break;

    case PARTICLE_EDIT_CALC_MINMAX:
        if (!ReadNumber(parser, first) || !ReadNumber(parser, second)) {
            parser->Error("particle minmax: not enough parameters");
            return;
        }
        parm->val0 = first;
        parm->val1 = second;
        break;

    case PARTICLE_EDIT_CALC_CURVE:
        if (!parser->ReadToken(token)) {
            parser->Error("particle curve: not enough parameters");
            return;
        }
        parm->tableIdx = static_cast<std::int16_t>(
            AddTable(token.c_str(), tableDecls, tables));
        parm->val0 = 1.0f;
        break;

    case PARTICLE_EDIT_CALC_CURVE_SCALE_BIAS:
        if (!parser->ReadToken(token)) {
            parser->Error("particle curve scale bias: not enough parameters");
            return;
        }
        parm->tableIdx = static_cast<std::int16_t>(
            AddTable(token.c_str(), tableDecls, tables));
        if (!ReadNumber(parser, parm->val0)
                || !ReadNumber(parser, parm->val1)) {
            parser->Error("particle curve scale bias: not enough parameters");
            return;
        }
        break;

    case PARTICLE_EDIT_CALC_CURVE_VARIANCE_MOD_CONSTANT:
        if (!parser->ReadToken(token)) {
            parser->Error("particle curve use variance: not enough parameters");
            return;
        }
        parm->tableIdx = static_cast<std::int16_t>(
            AddTable(token.c_str(), tableDecls, tables));
        if (!ReadNumber(parser, parm->variance)
                || !ReadNumber(parser, parm->val0)) {
            parser->Error("particle curve use variance: not enough parameters");
            return;
        }
        break;

    case PARTICLE_EDIT_CALC_CURVE_MOD_CURVE:
    case PARTICLE_EDIT_CALC_CURVE_ADD_CURVE: {
        if (!parser->ReadToken(token)) {
            parser->Error("particle curve operation: not enough parameters");
            return;
        }
        parm->tableIdx = static_cast<std::int16_t>(
            AddTable(token.c_str(), tableDecls, tables));
        if (!parser->ReadToken(token)) {
            parser->Error("particle curve operation: not enough parameters");
            return;
        }
        parm->table2Idx = static_cast<std::int16_t>(
            AddTable(token.c_str(), tableDecls, tables));
        break;
    }

    case PARTICLE_EDIT_CALC_PARAMETRIC_EVAL:
    case PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE:
    case PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE_MINMAX:
        ParseParametric(parser, parm, tableDecls, tables);
        break;

    default:
        parser->Error("Particle Calc Type %d not supported", editTypeValue);
        break;
    }
}

bool WriteParticleBool(idFile* file, const char* name, const bool value,
    const bool defaultValue) {
    if (file == nullptr || value == defaultValue) return false;
    file->WriteFloatString("\t\t%-25s\t%i\n", name, value ? 1 : 0);
    return true;
}

bool WriteParticleVec4(idFile* file, const char* name, const idVec4& value,
    const idVec4& defaultValue) {
    if (file == nullptr || (value.x == defaultValue.x
            && value.y == defaultValue.y && value.z == defaultValue.z
            && value.w == defaultValue.w)) {
        return false;
    }
    file->WriteFloatString("\t\t%-25s\t%.3f %.3f %.3f %.3f\n", name,
        value.x, value.y, value.z, value.w);
    return true;
}

void WriteParticleParm(idFile* file, const char* name,
    const idParticleParm& parm, const idParticleParm& defaultParm,
    const idList<const idDeclTable*, 79>& tableDecls,
    const idStr& info, const idStr& parentInfo) {
    if (file == nullptr) return;
    const bool same = parm.tableIdx == defaultParm.tableIdx
        && parm.table2Idx == defaultParm.table2Idx
        && parm.val0 == defaultParm.val0 && parm.val1 == defaultParm.val1
        && parm.variance == defaultParm.variance
        && parm.calcType == defaultParm.calcType;
    if (same && idStr::Icmp(info.c_str(), parentInfo.c_str()) == 0) return;

    file->WriteFloatString("\t\t%-25s\t", name);
    if (info.Length() != 0) file->WriteFloatString("%s ", info.c_str());
    const particleEditCalcType_t type = parm.GetEditCalcType();
    file->WriteFloatString("%s ", particleCalcTypeNames[type]);
    switch (type) {
    case PARTICLE_EDIT_CALC_CONSTANT:
        file->WriteFloatString("\"%.3f\"", parm.val0);
        if (parm.variance != 0.0f) {
            file->WriteFloatString(" \"%.3f\"", parm.variance);
        }
        break;
    case PARTICLE_EDIT_CALC_MINMAX:
        file->WriteFloatString("\"%.3f\" \"%.3f\"", parm.val0,
            parm.val1);
        break;
    case PARTICLE_EDIT_CALC_CURVE:
        file->WriteFloatString("%s", TableName(tableDecls, parm.tableIdx));
        break;
    case PARTICLE_EDIT_CALC_CURVE_SCALE_BIAS:
        file->WriteFloatString("%s \"%.3f\" \"%.3f\"",
            TableName(tableDecls, parm.tableIdx), parm.val0, parm.val1);
        break;
    case PARTICLE_EDIT_CALC_CURVE_VARIANCE_MOD_CONSTANT:
        file->WriteFloatString("%s \"%.3f\" \"%.3f\"",
            TableName(tableDecls, parm.tableIdx), parm.variance, parm.val0);
        break;
    case PARTICLE_EDIT_CALC_CURVE_MOD_CURVE:
    case PARTICLE_EDIT_CALC_CURVE_ADD_CURVE:
        file->WriteFloatString("%s %s", TableName(tableDecls, parm.tableIdx),
            TableName(tableDecls, parm.table2Idx));
        break;
    case PARTICLE_EDIT_CALC_PARAMETRIC_EVAL:
    case PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE:
    case PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE_MINMAX:
        file->WriteFloatString("\"%.3f\"", parm.val0);
        if (parm.val0 != parm.val1) {
            file->WriteFloatString(" to \"%.3f\"", parm.val1);
        }
        if (parm.variance != 0.0f) {
            file->WriteFloatString(" variance \"%.3f\"", parm.variance);
        }
        break;
    default:
        break;
    }
    file->WriteFloatString("\n");
}
