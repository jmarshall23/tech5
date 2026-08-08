
// ========================================================================
// ?SetDebugText@idAI2@@QAAXPBDW4aiDebugLevel_t@1@@Z
// EA  : 0x82A34948
// RVA : 0x00A34948
// PDB : w:\tech5\tungsten\game\ai\ai2_debug.cpp
// ========================================================================

void __fastcall idAI2::SetDebugText(idAI2 *this, const char *text, idAI2::aiDebugLevel_t debugLevel)
{
  idAI2::aiDebugLevel_t textLevel; // r10

  textLevel = this->aiVolatile.debugging.textLevel;
  if ( textLevel == AIDEBUGLEVEL_NONE || debugLevel <= textLevel )
  {
    this->aiVolatile.debugging.textLevel = debugLevel;
    idStr::operator=(this: &this->aiVolatile.debugging.debugText, text);
  }
}


// ========================================================================
// ?ClearErrorFlags@idAI2@@QAAXH@Z
// EA  : 0x82A34978
// RVA : 0x00A34978
// PDB : w:\tech5\tungsten\game\ai\ai2_debug.cpp
// ========================================================================

void __fastcall idAI2::ClearErrorFlags(idAI2 *this, const int flags)
{
  this->aiVolatile.debugging.errorFlags &= ~flags;
}


// ========================================================================
// ?GetDebugLevel@idAI2@@SAHXZ
// EA  : 0x82A34990
// RVA : 0x00A34990
// PDB : w:\tech5\tungsten\game\ai\ai2_debug.cpp
// ========================================================================

int __fastcall idAI2::GetDebugLevel()
{
  return ai_debugLevel.valueInteger;
}


// ========================================================================
// ?ShowDebugDamageText@idAI2@@ABAXMMMMMMMMMMMPBVidDamageGroup@@ABVidVec3@@@Z
// EA  : 0x82A349A8
// RVA : 0x00A349A8
// PDB : w:\tech5\tungsten\game\ai\ai2_debug.cpp
// ========================================================================

void __fastcall idAI2::ShowDebugDamageText(
        idAI2 *this,
        double baseDamage,
        double difficultyScale,
        double bodyDamage,
        double limbDamage,
        double armorDamage,
        double shieldDamage,
        double armorDamageScale,
        double armoredHealthDamageScale,
        const idDamageGroup *damageGroup,
        __int64 impactPoint,
        __int64 a12,
        int a13,
        int a14,
        const float bleedThroughDamage,
        const float excessDamage,
        const float attitudeDamageScale,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        float a38,
        float a39,
        float a40,
        float a41,
        int a42,
        float a43,
        int a44)
{
  double v44; // fp11
  double v45; // fp10
  double v46; // fp9
  double v56; // fp23
  double v57; // fp21
  double v58; // fp28
  __int64 v59; // r10
  va *v60; // r3
  __int64 v61; // r6
  __int64 v62; // r8
  __int64 v63; // r10
  va *v64; // r3
  __int64 v65; // r6
  __int64 v66; // r8
  __int64 v67; // r10
  va *v68; // r3
  __int64 v69; // r10
  __int64 v70; // r8
  __int64 v71; // r6
  double v72; // fp29
  va *v73; // r3
  __int64 v74; // r6
  va *v75; // r3
  __int64 v76; // r10
  __int64 v77; // r8
  __int64 v78; // r6
  va *v79; // r3
  va *v80; // r3
  va *v81; // r3
  va *v82; // r3
  va *v83; // r3
  idAIHealth_vtbl *v84; // r10
  idColor *v85; // r9
  float r; // r8
  float b; // r6
  float g; // r7
  idStr *v89; // r3
  int v90; // [sp+8h] [-1128h]
  int v91; // [sp+8h] [-1128h]
  int v92; // [sp+8h] [-1128h]
  int v93; // [sp+8h] [-1128h]
  int v94; // [sp+Ch] [-1124h]
  int v95; // [sp+Ch] [-1124h]
  int v96; // [sp+Ch] [-1124h]
  int v97; // [sp+Ch] [-1124h]
  int v98; // [sp+10h] [-1120h]
  int v99; // [sp+10h] [-1120h]
  int v100; // [sp+10h] [-1120h]
  int v101; // [sp+10h] [-1120h]
  int v102; // [sp+14h] [-111Ch]
  int v103; // [sp+14h] [-111Ch]
  int v104; // [sp+14h] [-111Ch]
  int v105; // [sp+14h] [-111Ch]
  int v106; // [sp+18h] [-1118h]
  int v107; // [sp+18h] [-1118h]
  int v108; // [sp+18h] [-1118h]
  int v109; // [sp+18h] [-1118h]
  int v110; // [sp+1Ch] [-1114h]
  int v111; // [sp+1Ch] [-1114h]
  int v112; // [sp+1Ch] [-1114h]
  int v113; // [sp+1Ch] [-1114h]
  idStr v114; // [sp+60h] [-10D0h] BYREF
  float v115[4]; // [sp+80h] [-10B0h] BYREF
  idStr v116; // [sp+90h] [-10A0h] BYREF
  va v117; // [sp+B0h] [-1080h] BYREF

  v56 = v46;
  v57 = v45;
  v58 = v44;
  if ( ai_debugHealth.valueInteger >= 1 && ai_debugLevel.valueInteger != 0 )
  {
    LODWORD(v59) = v114.baseBuffer;
    v114.len = 0;
    v114.allocedAndFlag = 20;
    v114.data = v114.baseBuffer;
    v114.baseBuffer[0] = 0;
    HIDWORD(impactPoint) = LODWORD(bodyDamage);
    HIDWORD(v59) = "ound traces";
    v60 = va::va(
            this: &v117,
            fmt: "net: %.1f",
            a3: impactPoint,
            a4: a12,
            a5: v59,
            a6: v90,
            a7: v94,
            a8: v98,
            a9: v102,
            a10: v106,
            a11: v110,
            bodyDamage);
    idStr::Append(this: &v114, text: v60);
    HIDWORD(v61) = LODWORD(baseDamage);
    LODWORD(v62) = "ound traces";
    v64 = va::va(
            this: &v117,
            fmt: " base: %.1f ",
            a3: v61,
            a4: v62,
            a5: v63,
            a6: v91,
            a7: v95,
            a8: v99,
            a9: v103,
            a10: v107,
            a11: v111,
            baseDamage);
    idStr::Append(this: &v114, text: v64);
    HIDWORD(v65) = LODWORD(limbDamage);
    HIDWORD(v66) = "ound traces";
    v68 = va::va(
            this: &v117,
            fmt: " limb: %.1f ",
            a3: v65,
            a4: v66,
            a5: v67,
            a6: v92,
            a7: v96,
            a8: v100,
            a9: v104,
            a10: v108,
            a11: v112,
            limbDamage);
    idStr::Append(this: &v114, text: v68);
    LODWORD(v71) = 0x82000000;
    v72 = 1.0;
    if ( difficultyScale != 1.0 )
    {
      HIDWORD(v71) = LODWORD(difficultyScale);
      v73 = va::va(
              this: &v117,
              fmt: " x%.2f (difficulty)",
              a3: v71,
              a4: v70,
              a5: v69,
              a6: v93,
              a7: v97,
              a8: v101,
              a9: v105,
              a10: v109,
              a11: v113,
              difficultyScale);
      idStr::Append(this: &v114, text: v73);
    }
    if ( a42 != 0 )
    {
      v72 = *(float *)(a42 + 32);
      LODWORD(v69) = "ound traces";
      LODWORD(v74) = LODWORD(v72);
      HIDWORD(v74) = *(_DWORD *)(a42 + 4);
      v75 = va::va(
              this: &v117,
              fmt: " (%s scale %.1f)",
              a3: v74,
              a4: v70,
              a5: v69,
              a6: v93,
              a7: v97,
              a8: v101,
              a9: v105,
              a10: v109,
              a11: v113,
              v72);
      idStr::Append(this: &v114, text: v75);
    }
    else
    {
      idStr::Append(this: &v114, text: " (no loc)");
    }
    if ( v58 != 1.0 )
    {
      HIDWORD(v78) = LODWORD(v58);
      v79 = va::va(
              this: &v117,
              fmt: (const char *)HIDWORD(v58),
              a3: v78,
              a4: v77,
              a5: v76,
              a6: v93,
              a7: v97,
              a8: v101,
              a9: v105,
              a10: v109,
              a11: v113,
              v58);
      idStr::Append(this: &v114, text: v79);
    }
    if ( shieldDamage > 0.0 )
    {
      HIDWORD(v78) = LODWORD(shieldDamage);
      v80 = va::va(
              this: &v117,
              fmt: (const char *)HIDWORD(shieldDamage),
              a3: v78,
              a4: v77,
              a5: v76,
              a6: v93,
              a7: v97,
              a8: v101,
              a9: v105,
              a10: v109,
              a11: v113,
              shieldDamage);
      idStr::Append(this: &v114, text: v80);
    }
    if ( armorDamage > 0.0 )
    {
      v81 = va::va(
              this: &v117,
              fmt: (const char *)HIDWORD(armorDamage),
              a3: __SPAIR64__(LODWORD(armorDamage), LODWORD(armorDamageScale)),
              a4: v77,
              a5: v76,
              a6: v93,
              a7: v97,
              a8: v101,
              a9: v105,
              a10: v109,
              a11: v113,
              armorDamage,
              armorDamageScale);
      idStr::Append(this: &v114, text: v81);
    }
    if ( v56 > 0.0 )
    {
      v82 = va::va(
              this: &v117,
              fmt: " %.1f (bleedthrough at scale %.2f)",
              a3: *(__int64 *)&armoredHealthDamageScale,
              a4: v77,
              a5: v76,
              a6: v93,
              a7: v97,
              a8: v101,
              a9: v105,
              a10: v109,
              a11: v113,
              v56,
              armoredHealthDamageScale);
      idStr::Append(this: &v114, text: v82);
    }
    if ( v57 > 0.0 )
    {
      v83 = va::va(
              this: &v117,
              fmt: (const char *)HIDWORD(v57),
              a3: __SPAIR64__(LODWORD(v57), LODWORD(v72)),
              a4: v77,
              a5: v76,
              a6: v93,
              a7: v97,
              a8: v101,
              a9: v105,
              a10: v109,
              a11: v113,
              v57,
              v72);
      idStr::Append(this: &v114, text: v83);
    }
    v115[3] = -1.0;
    v115[2] = -1.0;
    v115[1] = -1.0;
    v84 = this->aiHealth.__vftable;
    v115[0] = -1.0;
    if ( bodyDamage <= ((double (__fastcall *)(idAIHealth *))v84->GetCurBaseHealth_Impl)(a1: &this->aiHealth) )
    {
      v85 = &idColor::colorYellow;
      r = idColor::colorYellow.r;
    }
    else
    {
      v85 = &idColor::colorRed;
      r = idColor::colorRed.r;
    }
    b = v85->b;
    g = v85->g;
    v115[3] = v85->a;
    v115[0] = r;
    v115[2] = b;
    v115[1] = g;
    if ( ai_debugHealth.valueInteger >= 2 )
      ((void (__fastcall *)(idRenderWorld *, char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v114.data,
        a3: a44,
        a4: clientGame->renderWorld->DebugText,
        a5: v115,
        a6: 1,
        a7: 5000,
        a8: 0,
        a9: 0.2);
    v89 = operator+(result: &v116, a: &v114, b: "\n");
    idLib::Printf(fmt: v89->data);
    idStr::FreeData(this: &v116);
    idStr::FreeData(this: &v114);
  }
}


// ========================================================================
// __unwind$490182
// EA  : 0x82A34D54
// RVA : 0x00A34D54
// PDB : w:\tech5\tungsten\game\ai\ai2_debug.cpp
// ========================================================================

void _unwind_490182()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 96));
}


// ========================================================================
// __unwind$490183
// EA  : 0x82A34D7C
// RVA : 0x00A34D7C
// PDB : w:\tech5\tungsten\game\ai\ai2_debug.cpp
// ========================================================================

void _unwind_490183()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 144));
}

