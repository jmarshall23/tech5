#include "ai2_debug.h"

#include "idlib/text/str.h"

namespace {

void AppendFloat(idStr& destination, const char* format,
        const float first) {
    idStr text;
    text.Format(format, first);
    destination.Append(text);
}

void AppendFloats(idStr& destination, const char* format,
        const float first, const float second) {
    idStr text;
    text.Format(format, first, second);
    destination.Append(text);
}

} // namespace

// Retail symbol: ?SetDebugText@idAI2@@QAAXPBDW4aiDebugLevel_t@1@@Z
// EA: 0x82A34948, RVA: 0x00A34948
void idAI2::SetDebugText(const char* const text,
        const aiDebugLevel_t debugLevel) {
    idAI2DebugRuntime runtime{};
    if (!Tungsten_GetAI2DebugRuntime(*this, runtime)) {
        return;
    }
    if (runtime.textLevel == AIDEBUGLEVEL_NONE
            || debugLevel <= runtime.textLevel) {
        Tungsten_SetAI2DebugText(*this, debugLevel, text);
    }
}

// Retail symbol: ?ClearErrorFlags@idAI2@@QAAXH@Z
// EA: 0x82A34978, RVA: 0x00A34978
void idAI2::ClearErrorFlags(const int flags) {
    idAI2DebugRuntime runtime{};
    if (Tungsten_GetAI2DebugRuntime(*this, runtime)) {
        Tungsten_SetAI2ErrorFlags(*this, runtime.errorFlags & ~flags);
    }
}

// Retail symbol: ?GetDebugLevel@idAI2@@SAHXZ
// EA: 0x82A34990, RVA: 0x00A34990
int idAI2::GetDebugLevel() {
    return Tungsten_GetAI2DebugLevelValue();
}

// Retail symbol:
// ?ShowDebugDamageText@idAI2@@ABAXMMMMMMMMMMMPBVidDamageGroup@@ABVidVec3@@@Z
// EA: 0x82A349A8, RVA: 0x00A349A8
void idAI2::ShowDebugDamageText(const float baseDamage,
        const float difficultyScale, const float bodyDamage,
        const float limbDamage, const float armorDamage,
        const float shieldDamage, const float armorDamageScale,
        const float armoredHealthDamageScale,
        const float bleedThroughDamage, const float excessDamage,
        const float attitudeDamageScale,
        const idDamageGroup* const damageGroup,
        const idVec3& impactPoint) const {
    const int debugHealth = Tungsten_GetAI2DebugHealthValue();
    if (debugHealth < 1 || Tungsten_GetAI2DebugLevelValue() == 0) {
        return;
    }

    idStr output;
    AppendFloat(output, "net: %.1f", bodyDamage);
    AppendFloat(output, " base: %.1f ", baseDamage);
    AppendFloat(output, " limb: %.1f ", limbDamage);
    if (difficultyScale != 1.0f) {
        AppendFloat(output, " x%.2f (difficulty)", difficultyScale);
    }

    float damageGroupScale = 1.0f;
    if (damageGroup != nullptr) {
        const char* damageGroupName = "";
        Tungsten_GetAI2DamageGroupDebugInfo(
            *damageGroup, damageGroupName, damageGroupScale);
        idStr groupText;
        groupText.Format(" (%s scale %.1f)",
            damageGroupName != nullptr ? damageGroupName : "",
            damageGroupScale);
        output.Append(groupText);
    } else {
        output.Append(" (no loc)");
    }
    if (attitudeDamageScale != 1.0f) {
        AppendFloat(output, " x%.1f (friendly)", attitudeDamageScale);
    }
    if (shieldDamage > 0.0f) {
        AppendFloat(output, " -%.0f (to shield)", shieldDamage);
    }
    if (armorDamage > 0.0f) {
        AppendFloats(output, " %.1f (to armor at scale %.1f)",
            armorDamage, armorDamageScale);
    }
    if (bleedThroughDamage > 0.0f) {
        AppendFloats(output,
            " %.1f (bleedthrough at scale %.2f)",
            bleedThroughDamage, armoredHealthDamageScale);
    }
    if (excessDamage > 0.0f) {
        AppendFloats(output,
            " %.1f (after armor gone at scale %.1f)",
            excessDamage, damageGroupScale);
    }

    const idVec4 color = bodyDamage
            <= Tungsten_GetAI2CurrentBaseHealth(*this)
        ? idVec4(1.0f, 1.0f, 0.0f, 1.0f)
        : idVec4(1.0f, 0.0f, 0.0f, 1.0f);
    if (debugHealth >= 2) {
        Tungsten_DrawAI2DamageDebugText(
            output.c_str(), impactPoint, color, 5000, 0.2f);
    }
    output.Append('\n');
    Tungsten_PrintAI2DebugText(output.c_str());
}
