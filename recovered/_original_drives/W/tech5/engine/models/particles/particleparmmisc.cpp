
// ========================================================================
// ?SetCalcTypeFromEditType@idParticleParm@@QAAXW4particleEditCalcType_t@@@Z
// EA  : 0x827ECCC0
// RVA : 0x007ECCC0
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void __fastcall idParticleParm::SetCalcTypeFromEditType(idParticleParm *this, const particleEditCalcType_t editType)
{
  switch ( editType )
  {
    case PARTICLE_EDIT_CALC_NONE:
      this->calcType = PARTICLE_CALC_NONE;
      break;
    case PARTICLE_EDIT_CALC_CONSTANT:
    case PARTICLE_EDIT_CALC_MINMAX:
      this->calcType = PARTICLE_CALC_GENERIC;
      break;
    case PARTICLE_EDIT_CALC_CURVE:
    case PARTICLE_EDIT_CALC_CURVE_SCALE_BIAS:
    case PARTICLE_EDIT_CALC_CURVE_VARIANCE_MOD_CONSTANT:
      this->calcType = PARTICLE_CALC_CURVE_GENERIC;
      break;
    case PARTICLE_EDIT_CALC_CURVE_MOD_CURVE:
      this->calcType = PARTICLE_CALC_CURVE_MOD_CURVE;
      break;
    case PARTICLE_EDIT_CALC_CURVE_ADD_CURVE:
      this->calcType = PARTICLE_CALC_CURVE_ADD_CURVE;
      break;
    case PARTICLE_EDIT_CALC_PARAMETRIC_EVAL:
      this->calcType = PARTICLE_CALC_PARAMETRIC_EVAL;
      break;
    case PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE:
      this->calcType = PARTICLE_CALC_PARAMETRIC_INTEGRATE;
      break;
    case PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE_MINMAX:
      this->calcType = PARTICLE_CALC_PARAMETRIC_INTEGRATE_MINMAX;
      break;
  }
}


// ========================================================================
// ?ParticleCalcNameToType@@YAHABVidStr@@@Z
// EA  : 0x827ECD70
// RVA : 0x007ECD70
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

int __fastcall ParticleCalcNameToType(const idStr *text)
{
  int v2; // r30
  char **p_data; // r31

  v2 = 0;
  p_data = &particleCalcTypeDesc[0].data;
  while ( idStr::Icmp(s1: text->data, s2: *p_data) != 0 )
  {
    p_data += 8;
    ++v2;
    if ( (int)p_data >= (int)&idRenderModelEffects::mappedBufferIndex )
      return -1;
  }
  return v2;
}


// ========================================================================
// ?GetEditCalcType@idParticleParm@@QBA?AW4particleEditCalcType_t@@XZ
// EA  : 0x827ECDD0
// RVA : 0x007ECDD0
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

int __fastcall idParticleParm::GetEditCalcType(idParticleParm *this)
{
  double val0; // fp13
  double val1; // fp11

  val0 = this->val0;
  val1 = this->val1;
  if ( (unsigned int)(this->calcType - 1) > 6 )
    return 0;
  switch ( this->calcType )
  {
    case PARTICLE_CALC_GENERIC:
      if ( val0 == val1 )
        return 1;
      else
        return 2;
    case PARTICLE_CALC_CURVE_MOD_CURVE:
      return 6;
    case PARTICLE_CALC_CURVE_ADD_CURVE:
      return 7;
    case PARTICLE_CALC_PARAMETRIC_EVAL:
      return 8;
    case PARTICLE_CALC_PARAMETRIC_INTEGRATE:
      return 9;
    case PARTICLE_CALC_CURVE_GENERIC:
      if ( this->variance == 0.0 )
      {
        if ( val0 == 1.0 && val1 == 0.0 )
          return 3;
        else
          return 4;
      }
      else
      {
        return 5;
      }
    default:
      return 10;
  }
}


// ========================================================================
// ParseParametric
// EA  : 0x827ECEA0
// RVA : 0x007ECEA0
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void __fastcall ParseParametric(
        idParser *src,
        idParticleParm *parm,
        idList<idDeclTable const *,5> *tableDecls,
        idList<idLookupTable,5> *tables)
{
  double v5; // fp31
  long double v9; // fp2
  double v10; // fp30
  double v11; // fp29
  long double v12; // fp2
  long double v13; // fp2
  idToken v14; // [sp+50h] [-A0h] BYREF

  v5 = 0.0;
  parm->val0 = 0.0;
  v14.floatvalue = -3.4028235e38;
  parm->val1 = 0.0;
  parm->variance = 0.0;
  v14.len = 0;
  parm->tableIdx = -1;
  v14.allocedAndFlag = 20;
  parm->table2Idx = -1;
  v14.data = v14.baseBuffer;
  v14.baseBuffer[0] = 0;
  v14.intvalue = 0;
  memset(&v14.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadToken(this: src, token: &v14) )
  {
    if ( idStr::IsNumeric(s: v14.data) )
    {
      v9 = atof(nptr: v14.data);
      v10 = (float)*(double *)&v9;
      v11 = v10;
      if ( !idParser::HadError(this: src) )
      {
        while ( idParser::ReadToken(this: src, token: &v14) )
        {
          if ( idStr::Icmp(s1: v14.data, s2: "to") != 0 && idStr::Icmp(s1: v14.data, s2: "variance") != 0 )
          {
            idParser::UnreadToken(this: src, token: &v14);
            parm->val0 = v11;
            parm->val1 = v10;
            parm->variance = v5;
            goto LABEL_22;
          }
          if ( idStr::Icmp(s1: v14.data, s2: "to") != 0 )
          {
            if ( idStr::Icmp(s1: v14.data, s2: "variance") != 0 )
            {
              idParser::Error(this: src, str: "unknown token %s\n", v14.data);
            }
            else
            {
              if ( !idParser::ReadToken(this: src, token: &v14) )
              {
                idParser::Error(this: src, str: "Missing 'variance' parameter for parametric parm");
                break;
              }
              v13 = atof(nptr: v14.data);
              v5 = (float)*(double *)&v13;
            }
          }
          else
          {
            if ( !idParser::ReadToken(this: src, token: &v14) )
            {
              idParser::Error(this: src, str: "Missing 'to' parameter for parametric parm");
              break;
            }
            v12 = atof(nptr: v14.data);
            v10 = (float)*(double *)&v12;
          }
          if ( idParser::HadError(this: src) )
          {
            parm->val0 = v11;
            parm->val1 = v10;
            parm->variance = v5;
            goto LABEL_22;
          }
        }
      }
      parm->val0 = v11;
      parm->val1 = v10;
      parm->variance = v5;
    }
    else
    {
      idParser::UnreadToken(this: src, token: &v14);
      ParseParticleParm(src, parm, tableDecls, tables);
    }
  }
  else
  {
    idParser::Error(this: src, str: "not enough parameters");
  }
LABEL_22:
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$220402
// EA  : 0x827ED108
// RVA : 0x007ED108
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_220402()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// WriteParametric
// EA  : 0x827ED130
// RVA : 0x007ED130
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void __fastcall WriteParametric(idFile *f, const idParticleParm *parm, const char *name)
{
  double val0; // fp29
  double v4; // r5
  double v5; // fp31
  double v7; // fp30

  val0 = parm->val0;
  v4 = val0;
  v5 = *(float *)(HIDWORD(v4) + 4);
  v7 = *(float *)(HIDWORD(v4) + 8);
  f->WriteFloatString(this: f, a2: "\"%.3f\" ", LODWORD(val0), val0);
  if ( val0 != v5 )
    f->WriteFloatString(this: f, a2: " to \"%.3f\" ", LODWORD(v5), v5);
  if ( v7 != 0.0 )
    f->WriteFloatString(this: f, a2: " variance \"%.3f\"", LODWORD(v7), v7);
  f->WriteFloatString(this: f, a2: "\n");
}


// ========================================================================
// ?SetParticleParmAsIntegrate@@YAXPAVidParticleParm@@MMM@Z
// EA  : 0x827ED228
// RVA : 0x007ED228
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void __fastcall SetParticleParmAsIntegrate(idParticleParm *parm, double from, double to, double variance)
{
  parm->val0 = from;
  parm->val1 = to;
  parm->variance = variance;
  parm->calcType = PARTICLE_CALC_PARAMETRIC_INTEGRATE;
}


// ========================================================================
// ?SetParticleParmAsEval@@YAXPAVidParticleParm@@MMM@Z
// EA  : 0x827ED240
// RVA : 0x007ED240
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void __fastcall SetParticleParmAsEval(idParticleParm *parm, double from, double to, double variance)
{
  parm->val0 = from;
  parm->val1 = to;
  parm->variance = variance;
  parm->calcType = PARTICLE_CALC_PARAMETRIC_EVAL;
}


// ========================================================================
// ?SetParticleParmAsConstant@@YAXPAVidParticleParm@@MM@Z
// EA  : 0x827ED258
// RVA : 0x007ED258
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void __fastcall SetParticleParmAsConstant(idParticleParm *parm, double constantVal, double variance)
{
  parm->val0 = constantVal;
  parm->val1 = constantVal;
  parm->variance = variance;
  parm->calcType = PARTICLE_CALC_GENERIC;
}


// ========================================================================
// ?SetParticleParmAsMinMax@@YAXPAVidParticleParm@@MM@Z
// EA  : 0x827ED270
// RVA : 0x007ED270
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void __fastcall SetParticleParmAsMinMax(idParticleParm *parm, double min, double max)
{
  parm->val0 = min;
  parm->val1 = max;
  parm->calcType = PARTICLE_CALC_GENERIC;
  parm->variance = 0.0;
}


// ========================================================================
// ?WriteParticleBool@@YA_NPAVidFile@@PBDAB_N2@Z
// EA  : 0x827ED298
// RVA : 0x007ED298
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

int __fastcall WriteParticleBool(idFile *f, const char *name, const bool *value, const bool *defaultValue)
{
  idStr v7[2]; // [sp+50h] [-40h] BYREF

  if ( *(unsigned __int8 *)value == *(unsigned __int8 *)defaultValue )
    return 0;
  idStr::idStr(this: v7, text: name);
  idStr::PadLength(this: v7, newlen: 25);
  f->WriteFloatString(this: f, a2: "\t\t%s\t%i\n", v7[0].data, *(unsigned __int8 *)value);
  idStr::FreeData(this: v7);
  return 1;
}


// ========================================================================
// __unwind$220749_0
// EA  : 0x827ED314
// RVA : 0x007ED314
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_220749_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?WriteParticleVec4@@YA_NPAVidFile@@PBDABVidVec4@@2@Z
// EA  : 0x827ED348
// RVA : 0x007ED348
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

int __fastcall WriteParticleVec4(idFile *f, const char *name, const idVec4 *value, const idVec4 *defaultValue)
{
  char v6; // r11
  idStr v8[2]; // [sp+50h] [-40h] BYREF

  if ( value->x != defaultValue->x
    || value->y != defaultValue->y
    || value->z != defaultValue->z
    || (v6 = 1, value->w != defaultValue->w) )
  {
    v6 = 0;
  }
  if ( v6 != 0 )
    return 0;
  idStr::idStr(this: v8, text: name);
  idStr::PadLength(this: v8, newlen: 25);
  f->WriteFloatString(
    this: f,
    a2: "\t\t%s\t%.3f %.3f %.3f %.3f\n",
    v8[0].data,
    (unsigned int)COERCE_UNSIGNED_INT64(value->x),
    (unsigned int)COERCE_UNSIGNED_INT64(value->y),
    (unsigned int)COERCE_UNSIGNED_INT64(value->z),
    (unsigned int)COERCE_UNSIGNED_INT64(value->w));
  idStr::FreeData(this: v8);
  return 1;
}


// ========================================================================
// __unwind$220815_0
// EA  : 0x827ED434
// RVA : 0x007ED434
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_220815_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?WriteParticleParm@@YAXPAVidFile@@PBDPBVidParticleParm@@2AAV?$idList@PBVidDeclTable@@$04@@ABVidStr@@4@Z
// EA  : 0x827ED468
// RVA : 0x007ED468
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void __fastcall WriteParticleParm(
        idFile *f,
        const char *name,
        idParticleParm *parm,
        const idParticleParm *defaultParm,
        idList<idDeclTable const *,5> *tableDecls,
        const idStr *info,
        const idStr *parentInfo)
{
  char v12; // r11
  int EditCalcType; // r3
  const char *v14; // r5
  double variance; // fp0
  idStr v16[3]; // [sp+60h] [-60h] BYREF

  if ( parm->tableIdx != defaultParm->tableIdx
    || parm->table2Idx != defaultParm->table2Idx
    || parm->val0 != defaultParm->val0
    || parm->val1 != defaultParm->val1
    || parm->variance != defaultParm->variance
    || (v12 = 1, parm->calcType != defaultParm->calcType) )
  {
    v12 = 0;
  }
  if ( v12 == 0 || idStr::Icmp(s1: info->data, s2: parentInfo->data) != 0 )
  {
    idStr::idStr(this: v16, text: name);
    idStr::PadLength(this: v16, newlen: 25);
    f->WriteFloatString(this: f, a2: "\t\t%s\t", v16[0].data);
    if ( info->len != 0 )
      f->WriteFloatString(this: f, a2: "%s ", info->data);
    EditCalcType = idParticleParm::GetEditCalcType(this: parm);
    f->WriteFloatString(this: f, a2: "%s ", particleCalcTypeDesc[EditCalcType].data);
    switch ( idParticleParm::GetEditCalcType(this: parm) )
    {
      case 1:
        f->WriteFloatString(this: f, a2: "\"%.3f\"", (unsigned int)COERCE_UNSIGNED_INT64(parm->val0));
        variance = parm->variance;
        if ( variance != 0.0 )
          f->WriteFloatString(this: f, a2: " \"%.3f\"", LODWORD(variance), variance);
        f->WriteFloatString(this: f, a2: "\n");
        break;
      case 2:
        f->WriteFloatString(
          this: f,
          a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(parm->val0)),
          COERCE_UNSIGNED_INT64(parm->val0),
          COERCE_UNSIGNED_INT64(parm->val1));
        break;
      case 3:
        f->WriteFloatString(this: f, a2: "%s\n", tableDecls->list[parm->tableIdx]->name.str);
        break;
      case 4:
        f->WriteFloatString(
          this: f,
          a2: "%s  \"%.3f\" \"%.3f\"\n",
          tableDecls->list[parm->tableIdx]->name.str,
          (unsigned int)COERCE_UNSIGNED_INT64(parm->val0),
          (unsigned int)COERCE_UNSIGNED_INT64(parm->val1));
        break;
      case 5:
        f->WriteFloatString(
          this: f,
          a2: "%s  \"%.3f\" \"%.3f\"\n",
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(parm->variance)),
          (unsigned int)COERCE_UNSIGNED_INT64(parm->variance),
          (unsigned int)COERCE_UNSIGNED_INT64(parm->val0));
        break;
      case 6:
      case 7:
        f->WriteFloatString(
          this: f,
          a2: "%s  %s\n",
          tableDecls->list[parm->tableIdx]->name.str,
          tableDecls->list[parm->table2Idx]->name.str);
        break;
      case 8:
      case 9:
      case 10:
        WriteParametric(f, parm, name: v14);
        break;
      default:
        break;
    }
    idStr::FreeData(this: v16);
  }
}


// ========================================================================
// __unwind$220854
// EA  : 0x827ED808
// RVA : 0x007ED808
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_220854()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// AddTable
// EA  : 0x827EDA68
// RVA : 0x007EDA68
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

int __fastcall AddTable(const char *tableName, idList<enum encounterGroupRole_t,5> *tableDecls)
{
  const idDeclTable *v3; // r31
  const char *resourceError; // r11
  int num; // r9
  int result; // r3
  int i; // r11
  const idDeclTable *v8; // [sp+50h] [-20h] BYREF

  if ( tableName != nullptr )
    v3 = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                this: &idDeclTable::resourceList,
                                name: tableName,
                                makeDefault: true);
  else
    v3 = nullptr;
  resourceError = v3->resourceError;
  v8 = v3;
  if ( resourceError != nullptr )
    idLib::Warning(fmt: "Table decl error: '%s' - using default.", v3->name.str);
  num = tableDecls->num;
  result = 0;
  if ( num <= 0 )
    return idList<idAnimWebBlendTree *,5>::Append(this: tableDecls, obj: (const encounterGroupRole_t *)&v8);
  for ( i = 0; (const idDeclTable *)tableDecls->list[i] != v3; ++i )
  {
    if ( ++result >= num )
      return idList<idAnimWebBlendTree *,5>::Append(this: tableDecls, obj: (const encounterGroupRole_t *)&v8);
  }
  if ( result < 0 )
    return idList<idAnimWebBlendTree *,5>::Append(this: tableDecls, obj: (const encounterGroupRole_t *)&v8);
  return result;
}


// ========================================================================
// ?ParseParticleParm@@YAXAAVidParser@@PAVidParticleParm@@AAV?$idList@PBVidDeclTable@@$04@@AAV?$idList@VidLookupTable@@$04@@@Z
// EA  : 0x827EDB38
// RVA : 0x007EDB38
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void __fastcall ParseParticleParm(
        idParser *src,
        idParticleParm *parm,
        idList<enum encounterGroupRole_t,5> *tableDecls,
        idList<idLookupTable,5> *tables)
{
  particleEditCalcType_t v4; // r28
  int v9; // r3
  long double v10; // fp2
  long double v11; // fp2
  long double v12; // fp2
  double v13; // fp30
  long double v14; // fp2
  __int16 v15; // r3
  __int16 v16; // r28
  __int16 v17; // r3
  long double v18; // fp2
  double v19; // fp31
  long double v20; // fp2
  long double v21; // fp2
  long double v22; // fp2
  int num; // r30
  int v24; // r29
  idToken v25; // [sp+50h] [-90h] BYREF

  v4 = PARTICLE_EDIT_CALC_NONE;
  v25.len = 0;
  parm->val0 = 0.0;
  v25.floatvalue = -3.4028235e38;
  parm->val1 = 0.0;
  parm->variance = 0.0;
  parm->tableIdx = -1;
  v25.allocedAndFlag = 20;
  parm->table2Idx = -1;
  v25.data = v25.baseBuffer;
  v25.baseBuffer[0] = 0;
  v25.intvalue = 0;
  memset(&v25.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadToken(this: src, token: &v25) )
  {
    v9 = ParticleCalcNameToType(text: &v25);
    if ( v9 >= 0 )
    {
      v4 = v9;
    }
    else if ( idStr::Icmp(s1: v25.data, s2: "constant_use_variance") != 0 )
    {
      idParser::Error(this: src, str: "bad particle parm calculation type: %s\n", v25.data);
    }
    else
    {
      v4 = PARTICLE_EDIT_CALC_CONSTANT;
    }
    idParticleParm::SetCalcTypeFromEditType(this: parm, editType: v4);
    switch ( v4 )
    {
      case PARTICLE_EDIT_CALC_CONSTANT:
        idParser::ReadToken(this: src, token: &v25);
        v10 = atof(nptr: v25.data);
        parm->val0 = *(double *)&v10;
        parm->val1 = *(double *)&v10;
        if ( idParser::ReadTokenOnLine(this: src, token: &v25) != 0 )
        {
          v11 = atof(nptr: v25.data);
          parm->variance = *(double *)&v11;
        }
        goto LABEL_36;
      case PARTICLE_EDIT_CALC_MINMAX:
        if ( !idParser::ReadToken(this: src, token: &v25)
          || (v12 = atof(nptr: v25.data), v13 = (float)*(double *)&v12, !idParser::ReadToken(this: src, token: &v25)) )
        {
          idParser::Error(this: src, str: "particle minmax: not enough parameters");
          break;
        }
        v14 = atof(nptr: v25.data);
        parm->val0 = v13;
        parm->val1 = *(double *)&v14;
        parm->variance = 0.0;
        goto LABEL_36;
      case PARTICLE_EDIT_CALC_CURVE:
        if ( !idParser::ReadToken(this: src, token: &v25) )
        {
          idParser::Error(this: src, str: "particle curve: not enough parameters");
          break;
        }
        v15 = AddTable(tableName: v25.data, tableDecls);
        parm->val1 = 0.0;
        parm->tableIdx = v15;
        parm->val0 = 1.0;
        goto LABEL_36;
      case PARTICLE_EDIT_CALC_CURVE_SCALE_BIAS:
        if ( !idParser::ReadToken(this: src, token: &v25) )
          goto LABEL_24;
        parm->tableIdx = AddTable(tableName: v25.data, tableDecls);
        if ( !idParser::ReadToken(this: src, token: &v25) )
        {
          idParser::Error(this: src, str: "particle curve scale bias: not enough parameters");
          break;
        }
        v18 = atof(nptr: v25.data);
        v19 = (float)*(double *)&v18;
        if ( !idParser::ReadToken(this: src, token: &v25) )
        {
LABEL_24:
          idParser::Error(this: src, str: "particle curve modulate constant: not enough parameters");
          break;
        }
        v20 = atof(nptr: v25.data);
        parm->val0 = v19;
        parm->val1 = *(double *)&v20;
        goto LABEL_36;
      case PARTICLE_EDIT_CALC_CURVE_VARIANCE_MOD_CONSTANT:
        if ( !idParser::ReadToken(this: src, token: &v25)
          || (parm->tableIdx = AddTable(tableName: v25.data, tableDecls), !idParser::ReadToken(this: src, token: &v25))
          || (v21 = atof(nptr: v25.data), parm->variance = *(double *)&v21, !idParser::ReadToken(this: src, token: &v25)) )
        {
          idParser::Error(this: src, str: "particle curve use variance: not enough parameters");
          break;
        }
        v22 = atof(nptr: v25.data);
        parm->val0 = *(double *)&v22;
        goto LABEL_36;
      case PARTICLE_EDIT_CALC_CURVE_MOD_CURVE:
      case PARTICLE_EDIT_CALC_CURVE_ADD_CURVE:
        if ( idParser::ReadToken(this: src, token: &v25)
          && (v16 = AddTable(tableName: v25.data, tableDecls), idParser::ReadToken(this: src, token: &v25)) )
        {
          v17 = AddTable(tableName: v25.data, tableDecls);
          parm->tableIdx = v16;
          parm->table2Idx = v17;
LABEL_36:
          num = tables->num;
          if ( num < tableDecls->num )
          {
            v24 = num;
            do
            {
              idList<idLookupTable,5>::Append(this: tables, obj: *(const idLookupTable **)(tableDecls->list[v24] + 64));
              ++num;
              ++v24;
            }
            while ( num < tableDecls->num );
          }
        }
        else
        {
          idParser::Error(this: src, str: "particle curve modulate/add curve: not enough parameters");
        }
        break;
      case PARTICLE_EDIT_CALC_PARAMETRIC_EVAL:
      case PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE:
      case PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE_MINMAX:
        ParseParametric(src, parm, (idList<idDeclTable const *,5> *)tableDecls, tables);
        goto LABEL_36;
      default:
        idParser::Error(this: src, str: "Particle Cacl Type %d not supported\n", parm->calcType);
        goto LABEL_36;
    }
  }
  else
  {
    idParser::Error(this: src, str: "not enough parameters");
  }
  idStr::FreeData(this: &v25);
}


// ========================================================================
// __unwind$221221
// EA  : 0x827EE00C
// RVA : 0x007EE00C
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_221221()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// `dynamic initializer for 'particleCalcTypeDesc''
// EA  : 0x83342FC8
// RVA : 0x01342FC8
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__particleCalcTypeDesc__()
{
  idStr::idStr(this: (idStr *)particleCalcTypeDesc, text: "none");
  idStr::idStr(this: (idStr *)&particleCalcTypeDesc[1], text: "constant");
  idStr::idStr(this: (idStr *)&particleCalcTypeDesc[2], text: "minmax");
  idStr::idStr(this: (idStr *)&particleCalcTypeDesc[3], text: "curve");
  idStr::idStr(this: (idStr *)&particleCalcTypeDesc[4], text: "curve_scale_bias");
  idStr::idStr(this: (idStr *)&particleCalcTypeDesc[5], text: "curve_use_variance_mod_constant");
  idStr::idStr(this: (idStr *)&particleCalcTypeDesc[6], text: "curve_mod_curve");
  idStr::idStr(this: (idStr *)&particleCalcTypeDesc[7], text: "curve_add_curve");
  idStr::idStr(this: (idStr *)&particleCalcTypeDesc[8], text: "parametricEval");
  idStr::idStr(this: (idStr *)&particleCalcTypeDesc[9], text: "parametricIntegrate");
  idStr::idStr(this: (idStr *)&particleCalcTypeDesc[10], text: "parametricIntegrateMinMax");
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__particleCalcTypeDesc__);
}


// ========================================================================
// __unwind$221576
// EA  : 0x833430BC
// RVA : 0x013430BC
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_221576()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)particleCalcTypeDesc);
}


// ========================================================================
// __unwind$221577
// EA  : 0x833430E4
// RVA : 0x013430E4
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_221577()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&particleCalcTypeDesc[1]);
}


// ========================================================================
// __unwind$221578
// EA  : 0x83343110
// RVA : 0x01343110
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_221578()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&particleCalcTypeDesc[2]);
}


// ========================================================================
// __unwind$221579
// EA  : 0x8334313C
// RVA : 0x0134313C
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_221579()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&particleCalcTypeDesc[3]);
}


// ========================================================================
// __unwind$221580
// EA  : 0x83343168
// RVA : 0x01343168
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_221580()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&particleCalcTypeDesc[4]);
}


// ========================================================================
// __unwind$221581
// EA  : 0x83343194
// RVA : 0x01343194
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_221581()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&particleCalcTypeDesc[5]);
}


// ========================================================================
// __unwind$221582
// EA  : 0x833431C0
// RVA : 0x013431C0
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_221582()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&particleCalcTypeDesc[6]);
}


// ========================================================================
// __unwind$221583
// EA  : 0x833431EC
// RVA : 0x013431EC
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_221583()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&particleCalcTypeDesc[7]);
}


// ========================================================================
// __unwind$221584
// EA  : 0x83343218
// RVA : 0x01343218
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_221584()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&particleCalcTypeDesc[8]);
}


// ========================================================================
// __unwind$221585
// EA  : 0x83343244
// RVA : 0x01343244
// PDB : w:\tech5\engine\models\particles\particleparmmisc.cpp
// ========================================================================

void _unwind_221585()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&particleCalcTypeDesc[9]);
}

