
// ========================================================================
// ?ParseCoverParms@idCoverPoints@@IAA_NAAVidLexer@@@Z
// EA  : 0x82DE6548
// RVA : 0x00DE6548
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

int __fastcall idCoverPoints::ParseCoverParms(idCoverPoints *this, idLexer *src)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  navLayer_t EnumValue; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  unsigned int v11; // r3
  float *v12; // r29
  int v14; // [sp+8h] [-108h]
  int v15; // [sp+Ch] [-104h]
  int v16; // [sp+10h] [-100h]
  int v17; // [sp+14h] [-FCh]
  int v18; // [sp+18h] [-F8h]
  int v19; // [sp+1Ch] [-F4h]
  idToken v20[2]; // [sp+50h] [-C0h] BYREF

  v20[0].len = 0;
  v20[0].allocedAndFlag = 20;
  v20[0].floatvalue = -3.4028235e38;
  v20[0].data = v20[0].baseBuffer;
  v20[0].baseBuffer[0] = 0;
  v20[0].intvalue = 0;
  v20[0].whiteSpaceStart_p = nullptr;
  v20[0].whiteSpaceEnd_p = nullptr;
  v20[0].next = nullptr;
  if ( idLexer::ExpectTokenString(this: src, string: "{") )
  {
    idLexer::ReadToken(this: src, token: v20);
    EnumValue = idTypeInfoTools::FindEnumValue(
                  this: typeInfoTools,
                  enumTypeName: "navLayer_t",
                  name: v20[0].data,
                  defaultValue: 7);
    this->navLayer = EnumValue;
    if ( EnumValue == NAVLAYER_NONE )
    {
      HIDWORD(v6) = v20[0].data;
      idResource::SetResourceError(
        this,
        fmt: "Invalid Nav Layer %s",
        a3: v6,
        a4: v5,
        a5: v4,
        a6: v14,
        a7: v15,
        a8: v16,
        a9: v17,
        a10: v18,
        a11: v19);
    }
    else
    {
      idLexer::ReadToken(this: src, token: v20);
      if ( idStr::Cmp(s1: v20[0].data, s2: "}") == 0 )
      {
LABEL_22:
        idStr::FreeData(this: &v20[0]);
        return 1;
      }
      while ( 1 )
      {
        v11 = idTypeInfoTools::FindEnumValue(
                this: typeInfoTools,
                enumTypeName: "idCoverPoints::coverLevel_t",
                name: v20[0].data,
                defaultValue: 3);
        if ( v11 >= 3 )
          break;
        v12 = (float *)((char *)this + 16 * v11);
        if ( !idLexer::ExpectTokenString(this: src, string: "{") )
          goto LABEL_24;
        while ( idLexer::CheckTokenType(this: src, type: 4, subtype: 0, token: v20) )
        {
          if ( idStr::Cmp(s1: v20[0].data, s2: "coverHeight") != 0 )
          {
            if ( idStr::Cmp(s1: v20[0].data, s2: "coverMinLength") != 0 )
            {
              if ( idStr::Cmp(s1: v20[0].data, s2: "coverFireOverHeight") != 0 )
              {
                if ( idStr::Cmp(s1: v20[0].data, s2: "coverStepOutDist") != 0 )
                {
                  if ( idStr::Cmp(s1: v20[0].data, s2: "coverStepOutHeight") != 0 )
                  {
                    if ( idStr::Cmp(s1: v20[0].data, s2: "}") == 0 )
                      break;
                  }
                  else
                  {
                    v12[14] = idLexer::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  v12[13] = idLexer::ParseFloat(this: src, errorFlag: nullptr);
                }
              }
              else
              {
                v12[12] = idLexer::ParseFloat(this: src, errorFlag: nullptr);
              }
            }
            else
            {
              idLexer::ParseFloat(this: src, errorFlag: nullptr);
            }
          }
          else
          {
            v12[11] = idLexer::ParseFloat(this: src, errorFlag: nullptr);
          }
        }
        if ( !idLexer::ExpectTokenString(this: src, string: "}") )
          goto LABEL_24;
        idLexer::ReadToken(this: src, token: v20);
        if ( idStr::Cmp(s1: v20[0].data, s2: "}") == 0 )
          goto LABEL_22;
      }
      HIDWORD(v10) = v20[0].data;
      idResource::SetResourceError(
        this,
        fmt: "Invalid Cover Level %s",
        a3: v10,
        a4: v9,
        a5: v8,
        a6: v14,
        a7: v15,
        a8: v16,
        a9: v17,
        a10: v18,
        a11: v19);
    }
  }
LABEL_24:
  idStr::FreeData(this: &v20[0]);
  return 0;
}


// ========================================================================
// __unwind$488349
// EA  : 0x82DE6838
// RVA : 0x00DE6838
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

void _unwind_488349()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 80));
}


// ========================================================================
// ?ReloadIfStale@idCoverPoints@@UAA_NXZ
// EA  : 0x82DE6870
// RVA : 0x00DE6870
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

int __fastcall idCoverPoints::ReloadIfStale(idCoverPoints *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  va *v6; // r3
  int v8; // [sp+8h] [-1088h]
  int v9; // [sp+Ch] [-1084h]
  int v10; // [sp+10h] [-1080h]
  int v11; // [sp+14h] [-107Ch]
  int v12; // [sp+18h] [-1078h]
  int v13; // [sp+1Ch] [-1074h]
  idStr v14; // [sp+50h] [-1040h] BYREF
  va v15; // [sp+70h] [-1020h] BYREF

  HIDWORD(a3) = this->name.str;
  v6 = va::va(this: &v15, fmt: "%s.cover", a3, a4, a5, a6: v8, a7: v9, a8: v10, a9: v11, a10: v12, a11: v13);
  idStr::idStr(this: &v14, text: v6);
  if ( this->timestamp == fileSystem->GetTimestamp(this: fileSystem, a2: v14.data, a3: false) )
  {
    idStr::FreeData(this: &v14);
    return 0;
  }
  else
  {
    this->LoadResource(this);
    idStr::FreeData(this: &v14);
    return 1;
  }
}


// ========================================================================
// __unwind$488744_0
// EA  : 0x82DE6924
// RVA : 0x00DE6924
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

void _unwind_488744_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4240 + 80));
}


// ========================================================================
// ??0idCoverPoints@@QAA@XZ
// EA  : 0x82DE6958
// RVA : 0x00DE6958
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

idCoverPoints *__fastcall idCoverPoints::idCoverPoints(idCoverPoints *this)
{
  idResource::idResource(this);
  this->timestamp = 0;
  this->__vftable = (idCoverPoints_vtbl *)&idCoverPoints::`vftable';
  this->navLayer = NAVLAYER_NONE;
  this->coverThresholds[0].coverHeight = 0.0;
  this->coverThresholds[0].coverFireOverHeight = 0.0;
  this->coverThresholds[0].coverStepOutDist = 0.0;
  this->coverThresholds[0].coverStepOutHeight = 0.0;
  this->coverThresholds[1].coverHeight = 0.0;
  this->coverThresholds[1].coverFireOverHeight = 0.0;
  this->coverThresholds[1].coverStepOutDist = 0.0;
  this->coverThresholds[1].coverStepOutHeight = 0.0;
  this->coverThresholds[2].coverHeight = 0.0;
  this->coverThresholds[2].coverFireOverHeight = 0.0;
  this->coverThresholds[2].coverStepOutDist = 0.0;
  this->coverThresholds[2].coverStepOutHeight = 0.0;
  this->coverSegments.list = nullptr;
  this->coverSegments.granularity = 0;
  this->coverSegments.memTag = 5;
  this->coverSegments.listStatic = 0;
  this->coverSegments.size = 0;
  this->coverSegments.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->coverSegments);
  return this;
}


// ========================================================================
// __unwind$489045
// EA  : 0x82DE6A18
// RVA : 0x00DE6A18
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

void _unwind_489045()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idCoverPoints@@UAA@XZ
// EA  : 0x82DE6A58
// RVA : 0x00DE6A58
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

void __fastcall idCoverPoints::~idCoverPoints(idCoverPoints *this)
{
  this->__vftable = (idCoverPoints_vtbl *)&idCoverPoints::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->coverSegments);
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$489086_0
// EA  : 0x82DE6AAC
// RVA : 0x00DE6AAC
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

void _unwind_489086_0()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?ParseCoverSegments@idCoverPoints@@IAA_NAAVidLexer@@@Z
// EA  : 0x82DE6E80
// RVA : 0x00DE6E80
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

int __fastcall idCoverPoints::ParseCoverSegments(idCoverPoints *this, idLexer *src)
{
  int v4; // r3
  idList<idCoverPoints::coverSegment_t,5> *p_coverSegments; // r20
  int v6; // r29
  int size; // r11
  int v8; // r11
  int i; // r19
  double v11; // fp1
  double v12; // fp31
  double v13; // fp1
  double v14; // fp30
  double v15; // fp1
  double v16; // fp29
  idCoverPoints::coverHeights_t v17; // r25
  const enumTypeInfo_t *EnumInfo; // r27
  const enumValueInfo_t *EnumValueInfo; // r3
  float v20; // [sp+50h] [-120h]
  float v21; // [sp+54h] [-11Ch]
  idCoverPoints::coverSegment_t v22; // [sp+60h] [-110h] BYREF
  idToken v23; // [sp+90h] [-E0h] BYREF

  p_coverSegments = &this->coverSegments;
  v4 = idLexer::ParseInt(this: src);
  size = this->coverSegments.size;
  v6 = v4;
  if ( v4 > size )
    idList<idCoverPoints::coverSegment_t,5>::Resize(this: p_coverSegments, newsize: v4);
  if ( p_coverSegments->size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_coverSegments);
  v8 = p_coverSegments->size;
  v23.len = 0;
  v23.baseBuffer[0] = 0;
  v23.intvalue = 0;
  v23.whiteSpaceStart_p = nullptr;
  v23.floatvalue = -3.4028235e38;
  v23.allocedAndFlag = 20;
  v23.data = v23.baseBuffer;
  v23.whiteSpaceEnd_p = nullptr;
  p_coverSegments->num = __CFADD__(-v8, v8 ^ 0x80000000) ? 0 : v8;
  v23.next = nullptr;
  if ( !idLexer::ExpectTokenString(this: src, string: "{") )
    goto LABEL_6;
  if ( v6 > 0 )
  {
    for ( i = v6; i != 0; --i )
    {
      idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: "(");
      v11 = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v22.s0.x = v11;
      v12 = v11;
      v13 = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v22.s0.y = v13;
      v14 = v13;
      v15 = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v22.s0.z = v15;
      v16 = v15;
      idLexer::ExpectTokenString(this: src, string: ")");
      idLexer::ExpectTokenString(this: src, string: "(");
      v22.s1.x = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v22.s1.y = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v22.s1.z = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      idLexer::ExpectTokenString(this: src, string: ")");
      idLexer::ExpectTokenString(this: src, string: "(");
      v20 = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v21 = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v22.coverPlane.c = idLexer::ParseFloat(this: src, errorFlag: nullptr);
      v22.coverPlane.b = v21;
      v22.coverPlane.a = v20;
      v22.coverPlane.d = -(float)((float)(v20 * (float)v12)
                                + (float)((float)(v22.coverPlane.c * (float)v16) + (float)(v21 * (float)v14)));
      idLexer::ExpectTokenString(this: src, string: ")");
      idLexer::ExpectTokenString(this: src, string: "(");
      v22.groupNum = idLexer::ParseInt(this: src);
      idLexer::ExpectTokenString(this: src, string: ")");
      idLexer::ExpectTokenString(this: src, string: "coverHeights");
      idLexer::ExpectTokenString(this: src, string: "(");
      v17 = COV_NONE;
      v22.heights = COV_NONE;
      EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "idCoverPoints::coverHeights_t");
      if ( idLexer::ReadTokenOnLine(this: src, token: &v23) )
      {
        do
        {
          if ( idStr::Cmp(s1: v23.data, s2: ")") == 0 )
            break;
          if ( EnumInfo != nullptr )
          {
            EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                              this: typeInfoTools,
                              enumInfo: EnumInfo,
                              name: v23.data,
                              defaultIfNotFound: false);
            if ( EnumValueInfo != nullptr )
              v17 |= EnumValueInfo->value;
            else
              idLib::Warning(fmt: "unrecognized coverHeights_t '%s'", v23.data);
          }
        }
        while ( idLexer::ReadTokenOnLine(this: src, token: &v23) );
        v22.heights = v17;
      }
      idList<idCoverPoints::coverSegment_t,5>::Append(this: p_coverSegments, obj: &v22);
    }
  }
  if ( idLexer::ExpectTokenString(this: src, string: "}") )
  {
    idStr::FreeData(this: &v23);
    return 1;
  }
  else
  {
LABEL_6:
    idStr::FreeData(this: &v23);
    return 0;
  }
}


// ========================================================================
// __unwind$489214
// EA  : 0x82DE71F4
// RVA : 0x00DE71F4
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

void _unwind_489214()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 144));
}


// ========================================================================
// ?LoadResource@idCoverPoints@@UAAXXZ
// EA  : 0x82DE7228
// RVA : 0x00DE7228
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

void __fastcall idCoverPoints::LoadResource(idCoverPoints *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  va *v6; // r3
  unsigned int v7; // r27
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  int v17; // [sp+8h] [-1178h]
  int v18; // [sp+8h] [-1178h]
  int v19; // [sp+Ch] [-1174h]
  int v20; // [sp+Ch] [-1174h]
  int v21; // [sp+10h] [-1170h]
  int v22; // [sp+10h] [-1170h]
  int v23; // [sp+14h] [-116Ch]
  int v24; // [sp+14h] [-116Ch]
  int v25; // [sp+18h] [-1168h]
  int v26; // [sp+18h] [-1168h]
  int v27; // [sp+1Ch] [-1164h]
  int v28; // [sp+1Ch] [-1164h]
  idStr v29; // [sp+50h] [-1130h] BYREF
  idToken v30; // [sp+70h] [-1110h] BYREF
  idLexer v31; // [sp+C0h] [-10C0h] BYREF
  va v32; // [sp+150h] [-1030h] BYREF

  HIDWORD(a3) = this->name.str;
  v6 = va::va(this: &v32, fmt: "%s.cover", a3, a4, a5, a6: v17, a7: v19, a8: v21, a9: v23, a10: v25, a11: v27);
  idStr::idStr(this: &v29, text: v6);
  v7 = 0;
  if ( idLib::production == PROD_DEVELOPMENT )
    v7 = fileSystem->GetTimestamp(this: fileSystem, a2: v29.data, a3: false);
  idLexer::idLexer(this: &v31, flags_: 564);
  if ( idLexer::LoadFile(this: &v31, filename_: v29.data, OSPath: false) )
  {
    if ( idLexer::ExpectTokenString(this: &v31, string: "DOOMCOVER") )
    {
      v30.len = 0;
      v30.baseBuffer[0] = 0;
      v30.intvalue = 0;
      v30.allocedAndFlag = 20;
      v30.data = v30.baseBuffer;
      memset(&v30.whiteSpaceStart_p, 0, 12);
      v30.floatvalue = -3.4028235e38;
      if ( idLexer::ExpectTokenType(this: &v31, type: 3, subtype: 0, token: &v30) )
      {
        while ( idLexer::ReadToken(this: &v31, token: &v30) )
        {
          if ( idStr::Cmp(s1: v30.data, s2: "coverParms") != 0 )
          {
            if ( idStr::Cmp(s1: v30.data, s2: "coverSegments") != 0 )
            {
              idLexer::Error(this: &v31, str: "idCoverPoints::Load: bad token \"%s\"", v30.data);
              idStr::FreeData(this: &v30);
              idLexer::~idLexer(this: &v31);
              goto LABEL_19;
            }
            if ( (unsigned __int8)idCoverPoints::ParseCoverSegments(this, src: &v31) == 0 )
            {
LABEL_12:
              idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->coverSegments);
              idStr::FreeData(this: &v30);
              idLexer::~idLexer(this: &v31);
              goto LABEL_19;
            }
          }
          else if ( (unsigned __int8)idCoverPoints::ParseCoverParms(this, src: &v31) == 0 )
          {
            goto LABEL_12;
          }
        }
        this->timestamp = v7;
        idStr::FreeData(this: &v30);
        idLexer::~idLexer(this: &v31);
      }
      else
      {
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->coverSegments);
        HIDWORD(v14) = v30.data;
        idResource::SetResourceError(
          this,
          fmt: "CoverPoints file has malformed version number '%s'.",
          a3: v14,
          a4: v16,
          a5: v15,
          a6: v18,
          a7: v20,
          a8: v22,
          a9: v24,
          a10: v26,
          a11: v28);
        idStr::FreeData(this: &v30);
        idLexer::~idLexer(this: &v31);
      }
    }
    else
    {
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->coverSegments);
      idResource::SetResourceError(
        this,
        fmt: "Not a cover points file",
        a3: v13,
        a4: v12,
        a5: v11,
        a6: v18,
        a7: v20,
        a8: v22,
        a9: v24,
        a10: v26,
        a11: v28);
      idLexer::~idLexer(this: &v31);
    }
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->coverSegments);
    idResource::SetResourceError(
      this,
      fmt: "file not found",
      a3: v10,
      a4: v9,
      a5: v8,
      a6: v18,
      a7: v20,
      a8: v22,
      a9: v24,
      a10: v26,
      a11: v28);
    idLexer::~idLexer(this: &v31);
  }
LABEL_19:
  idStr::FreeData(this: &v29);
}


// ========================================================================
// __unwind$489723_0
// EA  : 0x82DE74C8
// RVA : 0x00DE74C8
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

void _unwind_489723_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 80));
}


// ========================================================================
// __unwind$489724_0
// EA  : 0x82DE74F0
// RVA : 0x00DE74F0
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

void _unwind_489724_0()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 4480 + 192));
}


// ========================================================================
// __unwind$489725
// EA  : 0x82DE7518
// RVA : 0x00DE7518
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

void _unwind_489725()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 112));
}


// ========================================================================
// `dynamic initializer for 'idCoverPoints::resourceList''
// EA  : 0x83385A70
// RVA : 0x01385A70
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idCoverPoints::resourceList__()
{
  idResourceList::idResourceList(this: &idCoverPoints::resourceList, typeName: "cover");
  idCoverPoints::resourceList.__vftable = (idTypedResourceList<idCoverPoints>_vtbl *)&idTypedResourceList<idCoverPoints>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idCoverPoints::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'colorLevel''
// EA  : 0x83385AC0
// RVA : 0x01385AC0
// PDB : w:\tech5\tungsten\game\navpower\cover_compiler.cpp
// ========================================================================

int _dynamic_initializer_for__colorLevel__()
{
  colorLevel[0] = idColor::colorYellow;
  colorLevel[1] = idColor::colorOrange;
  colorLevel[2] = idColor::colorMagenta;
  return LODWORD(idColor::colorOrange.r);
}

