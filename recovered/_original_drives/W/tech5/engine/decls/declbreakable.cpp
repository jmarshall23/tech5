
// ========================================================================
// ?DefaultDefinition@idDeclBreakable@@UBAPBDXZ
// EA  : 0x82613A60
// RVA : 0x00613A60
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

const char *__fastcall idDeclBreakable::DefaultDefinition(idDeclBreakable *this)
{
  return "{}\n";
}


// ========================================================================
// ?ContentsFromString@idDeclBreakable@@CAHPBD@Z
// EA  : 0x82613B70
// RVA : 0x00613B70
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

int __fastcall idDeclBreakable::ContentsFromString(const char *str)
{
  unsigned int v2; // r5
  int v3; // r29
  idToken v5; // [sp+50h] [-150h] BYREF
  idLexer v6; // [sp+A0h] [-100h] BYREF

  v5.len = 0;
  v5.baseBuffer[0] = 0;
  v5.intvalue = 0;
  v5.floatvalue = -3.4028235e38;
  memset(&v5.whiteSpaceStart_p, 0, 12);
  v5.allocedAndFlag = 20;
  v5.data = v5.baseBuffer;
  idLexer::idLexer(this: &v6, flags_: 0);
  v2 = 0;
  if ( *str != 0 )
  {
    do
      ++v2;
    while ( str[v2] != 0 );
  }
  idLexer::LoadMemory(this: &v6, ptr: str, length_: v2, name: "idDeclBreakable::ContentsFromString");
LABEL_4:
  v3 = 0;
  while ( idLexer::ReadToken(this: &v6, token: &v5) )
  {
    if ( idStr::Icmp(s1: v5.data, s2: "none") == 0 )
      goto LABEL_4;
    if ( idStr::Icmp(s1: v5.data, s2: "solid") != 0 )
    {
      if ( idStr::Icmp(s1: v5.data, s2: "ikclip") != 0 )
      {
        if ( idStr::Icmp(s1: v5.data, s2: "ai") != 0 )
        {
          if ( idStr::Icmp(s1: v5.data, s2: "corpse") != 0 )
          {
            if ( idStr::Icmp(s1: v5.data, s2: "playerclip") != 0 )
            {
              if ( idStr::Icmp(s1: v5.data, s2: "monsterclip") != 0 )
              {
                if ( idStr::Icmp(s1: v5.data, s2: "vehicleclip") != 0 )
                {
                  if ( idStr::Icmp(s1: v5.data, s2: "vehicle") != 0 )
                  {
                    if ( idStr::Cmp(s1: v5.data, s2: ",") != 0 )
                      break;
                  }
                  else
                  {
                    v3 |= 0x10000u;
                  }
                }
                else
                {
                  v3 |= 0x20u;
                }
              }
              else
              {
                v3 |= 0x10u;
              }
            }
            else
            {
              v3 |= 8u;
            }
          }
          else
          {
            v3 |= 0x1000u;
          }
        }
        else
        {
          v3 |= 0x400u;
        }
      }
      else
      {
        v3 |= 0x100u;
      }
    }
    else
    {
      v3 |= 1u;
    }
  }
  idLexer::~idLexer(this: &v6);
  idStr::FreeData(this: &v5);
  return v3;
}


// ========================================================================
// __unwind$221933
// EA  : 0x82613D98
// RVA : 0x00613D98
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_221933()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 80));
}


// ========================================================================
// __unwind$221934
// EA  : 0x82613DC0
// RVA : 0x00613DC0
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_221934()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 416 + 160));
}


// ========================================================================
// ??0idBreakableSettings@@QAA@XZ
// EA  : 0x82613DE8
// RVA : 0x00613DE8
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

idBreakableSettings *__fastcall idBreakableSettings::idBreakableSettings(idBreakableSettings *this)
{
  this->bouncyness = 1.0;
  this->linearFriction = 0.0;
  this->angularFriction = 0.0;
  this->contactFriction = 0.0;
  this->linearFrictionWater = 0.0;
  this->angularFrictionWater = 0.0;
  this->gravityVector.z = -250.0;
  this->gravityVector.x = 0.0;
  this->gravityVector.y = 0.0;
  this->worldCollisionOnly = false;
  this->simplePointCollision = false;
  this->impactParticle = nullptr;
  this->deathParticle = nullptr;
  this->stopSpeed = 10.0;
  this->harmlessParticle = nullptr;
  this->maxSimulationTime = 5.0;
  this->crazyBounceChance = 0.0;
  this->maxLinearVelocity = 5000.0;
  this->maxAngularVelocity = (float)3.1415927 * (float)4.0;
  this->noShadows = false;
  this->dampeningDecay = 0.0;
  this->clipMask = 1;
  return this;
}


// ========================================================================
// ?ParseArmoredPieces@idDeclBreakable@@AAAXAAVidParser@@@Z
// EA  : 0x82613F08
// RVA : 0x00613F08
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall idDeclBreakable::ParseArmoredPieces(idDeclBreakable *this, idParser *src)
{
  idList<int,59> *p_armoredPieces; // r27
  unsigned int intvalue; // r30
  int v6; // [sp+50h] [-A0h] BYREF
  idToken v7[2]; // [sp+60h] [-90h] BYREF

  v7[0].len = 0;
  v7[0].allocedAndFlag = 20;
  v7[0].floatvalue = -3.4028235e38;
  v7[0].data = v7[0].baseBuffer;
  v7[0].baseBuffer[0] = 0;
  v7[0].intvalue = 0;
  v7[0].whiteSpaceStart_p = nullptr;
  v7[0].whiteSpaceEnd_p = nullptr;
  v7[0].next = nullptr;
  v6 = 0;
  p_armoredPieces = &this->armoredPieces;
  idList<idRenderModelCommitted *,5>::SetNum(
    this: (idList<int,5> *)&this->armoredPieces,
    newNum: this->numPieces,
    initValue: &v6);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: v7);
  while ( idParser::ReadToken(this: src, token: v7) )
  {
    if ( v7[0].type == 5 )
    {
      if ( v7[0].subtype == 47 )
        break;
      if ( v7[0].subtype == 40 )
        continue;
    }
    if ( !idStr::IsNumeric(s: v7[0].data) )
      goto LABEL_17;
    if ( v7[0].type == 3 )
    {
      if ( (v7[0].subtype & 0x10000) == 0 )
        idToken::NumberValue(this: v7);
      intvalue = v7[0].intvalue;
    }
    else
    {
      intvalue = 0;
    }
    idParser::ReadToken(this: src, token: v7);
    if ( idStr::IsNumeric(s: v7[0].data) )
    {
      if ( v7[0].type == 3 )
      {
        if ( (v7[0].subtype & 0x10000) == 0 )
          idToken::NumberValue(this: v7);
        p_armoredPieces->list[intvalue - 1] = v7[0].intvalue;
      }
      else
      {
        p_armoredPieces->list[intvalue - 1] = 0;
      }
    }
    else
    {
LABEL_17:
      idParser::Error(
        this: src,
        str: "Unknown token '%s' in breakable '%s' in armored piece structure.",
        v7[0].data,
        this->name.str);
    }
  }
  idStr::FreeData(this: &v7[0]);
}


// ========================================================================
// __unwind$222816
// EA  : 0x826140B8
// RVA : 0x006140B8
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_222816()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// ?ParseHealthPieces@idDeclBreakable@@AAAXAAVidParser@@@Z
// EA  : 0x826140E8
// RVA : 0x006140E8
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall idDeclBreakable::ParseHealthPieces(idDeclBreakable *this, idParser *src)
{
  idList<int,59> *p_healthPieces; // r26
  int v5; // r30
  int v6; // r27
  int v7; // [sp+50h] [-A0h] BYREF
  idToken v8[2]; // [sp+60h] [-90h] BYREF

  v8[0].len = 0;
  v8[0].allocedAndFlag = 20;
  v8[0].floatvalue = -3.4028235e38;
  v8[0].data = v8[0].baseBuffer;
  v8[0].baseBuffer[0] = 0;
  v8[0].intvalue = 0;
  v8[0].whiteSpaceStart_p = nullptr;
  v8[0].whiteSpaceEnd_p = nullptr;
  v8[0].next = nullptr;
  v7 = 0;
  p_healthPieces = &this->healthPieces;
  idList<idRenderModelCommitted *,5>::SetNum(
    this: (idList<int,5> *)&this->healthPieces,
    newNum: this->numPieces,
    initValue: &v7);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: v8);
  while ( idParser::ReadToken(this: src, token: v8) )
  {
    if ( v8[0].type == 5 )
    {
      if ( v8[0].subtype == 47 )
        break;
      if ( v8[0].subtype == 40 )
        continue;
    }
    else
    {
      idParser::UnreadToken(this: src, token: v8);
    }
    v5 = idParser::ParseInt(this: src);
    v6 = idParser::ParseInt(this: src);
    if ( v5 < 1 || v5 > this->healthPieces.num )
      idParser::Error(
        this: src,
        str: "Health piece index %d/%d is out of range in breakable '%s'",
        v5 - 1,
        this->healthPieces.num,
        this->name.str);
    p_healthPieces->list[v5 - 1] = v6;
  }
  idStr::FreeData(this: &v8[0]);
}


// ========================================================================
// __unwind$222932
// EA  : 0x82614230
// RVA : 0x00614230
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_222932()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// ?ParseContents@idDeclBreakable@@ABAXAAVidParser@@AAH@Z
// EA  : 0x82614260
// RVA : 0x00614260
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall idDeclBreakable::ParseContents(idDeclBreakable *this, idParser *src, int *c)
{
  idStr v5; // [sp+50h] [-90h] BYREF
  idToken v6; // [sp+70h] [-70h] BYREF

  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.floatvalue = -3.4028235e38;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  v6.intvalue = 0;
  memset(&v6.whiteSpaceStart_p, 0, 12);
  v5.allocedAndFlag = 20;
  v5.data = v5.baseBuffer;
  v5.len = 0;
  v5.baseBuffer[0] = 0;
  while ( idParser::ReadToken(this: src, token: &v6) )
  {
    idStr::Append(this: &v5, text: &v6);
    if ( idParser::CheckTokenString(this: src, string: ",") == 0 )
      break;
    idStr::Append(this: &v5, text: ",");
  }
  *c = idDeclBreakable::ContentsFromString(str: v5.data);
  idStr::FreeData(this: &v5);
  idStr::FreeData(this: &v6);
}


// ========================================================================
// __unwind$223072
// EA  : 0x8261434C
// RVA : 0x0061434C
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_223072()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$223073
// EA  : 0x82614374
// RVA : 0x00614374
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_223073()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ?ParseSpark@idDeclBreakable@@AAAXAAVidParser@@@Z
// EA  : 0x826143A8
// RVA : 0x006143A8
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall idDeclBreakable::ParseSpark(idDeclBreakable *this, idParser *src)
{
  char *data; // r11
  const idDecl *v5; // r3
  const idDecl *v6; // [sp+50h] [-D0h] BYREF
  idToken v7[2]; // [sp+60h] [-C0h] BYREF

  this->sparks.sizeMin = 1.0;
  this->sparks.sizeMax = 1.0;
  this->sparks.velocityScaleMin = 1.0;
  this->sparks.velocityScaleMax = 1.0;
  if ( idParser::ExpectTokenString(this: src, string: "{") )
  {
    v7[0].len = 0;
    v7[0].allocedAndFlag = 20;
    v7[0].data = v7[0].baseBuffer;
    v7[0].floatvalue = -3.4028235e38;
    v7[0].baseBuffer[0] = 0;
    v7[0].intvalue = 0;
    v7[0].whiteSpaceStart_p = nullptr;
    v7[0].whiteSpaceEnd_p = nullptr;
    v7[0].next = nullptr;
    if ( idParser::ExpectAnyToken(this: src, token: v7) != 0 )
    {
      while ( idStr::Cmp(s1: v7[0].data, s2: "}") != 0 )
      {
        if ( idStr::Icmp(s1: v7[0].data, s2: "sizeMin") != 0 )
        {
          if ( idStr::Icmp(s1: v7[0].data, s2: "sizeMax") != 0 )
          {
            if ( idStr::Icmp(s1: v7[0].data, s2: "velocityScaleMin") != 0 )
            {
              if ( idStr::Icmp(s1: v7[0].data, s2: "velocityScaleMax") != 0 )
              {
                if ( idStr::Icmp(s1: v7[0].data, s2: "material") != 0 )
                {
                  idParser::Warning(this: src, str: "Bad token '%s'\n", v7[0].data);
                  break;
                }
                idParser::ExpectTokenString(this: src, string: "{");
                while ( idParser::ReadToken(this: src, token: v7) )
                {
                  if ( idStr::Cmp(s1: v7[0].data, s2: "}") == 0 )
                    break;
                  data = v7[0].data;
                  if ( v7[0].data != nullptr )
                  {
                    v5 = idDeclInfo::FindWithInheritance(
                           this: &idMaterial::resourceList,
                           name: v7[0].data,
                           makeDefault: false);
                    data = v7[0].data;
                  }
                  else
                  {
                    v5 = nullptr;
                  }
                  v6 = v5;
                  if ( v5 == nullptr )
                    idParser::Error(
                      this: src,
                      str: "Could not find material '%s' for breakable '%s'.",
                      data,
                      this->name.str);
                  idList<idAnimWebBlendTree *,5>::Append(
                    this: (idList<enum encounterGroupRole_t,5> *)&this->sparks,
                    obj: (const encounterGroupRole_t *)&v6);
                }
              }
              else
              {
                this->sparks.velocityScaleMax = idParser::ParseFloat(this: src, errorFlag: nullptr);
              }
            }
            else
            {
              this->sparks.velocityScaleMin = idParser::ParseFloat(this: src, errorFlag: nullptr);
            }
          }
          else
          {
            this->sparks.sizeMax = idParser::ParseFloat(this: src, errorFlag: nullptr);
          }
        }
        else
        {
          this->sparks.sizeMin = idParser::ParseFloat(this: src, errorFlag: nullptr);
        }
        if ( idParser::ExpectAnyToken(this: src, token: v7) == 0 )
          break;
      }
    }
    idStr::FreeData(this: &v7[0]);
  }
}


// ========================================================================
// __unwind$223818
// EA  : 0x82614634
// RVA : 0x00614634
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_223818()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// ?GenerateDecalInfoFromModel@idDeclBreakable@@SAXPBV1@PBD@Z
// EA  : 0x82614668
// RVA : 0x00614668
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall idDeclBreakable::GenerateDecalInfoFromModel(
        const idDeclBreakable *breakableDecl,
        const char *decalModelName)
{
  const idDeclBreakable *v2; // r29
  const char *v3; // r28
  int v4; // r30
  double v5; // fp31
  int v6; // r10
  idStaticModelSurface *v7; // r30
  idTriangles *geometry; // r8
  int materialNum; // r11
  float *p_x; // r26
  unsigned __int16 *indexes; // r24
  int numVerts; // r27
  int numIndexes; // r25
  __int64 v14; // r10
  __int64 v15; // r8
  int v16; // r5
  bool *list; // r19
  bool *v18; // r6
  int v19; // r10
  float *v20; // r11
  int v21; // ctr
  double v22; // fp12
  double v23; // fp9
  double v24; // fp6
  const idMaterial *material; // r21
  double v26; // fp27
  double v27; // fp26
  int v28; // r28
  double v29; // fp25
  int v30; // r29
  double v31; // fp31
  double v32; // fp30
  double v33; // fp29
  const idVec3 *v34; // r30
  const idVec3 *Normal; // r3
  double v36; // fp11
  double v37; // fp12
  double v39; // fp22
  double v40; // fp21
  double v41; // fp20
  double v43; // fp2
  double v44; // fp6
  double v45; // fp3
  double v46; // fp31
  double v47; // fp30
  double v48; // fp29
  double v49; // fp13
  double v52; // fp9
  double v53; // fp2
  double v54; // fp13
  double v55; // fp10
  double v56; // fp6
  idVec3 *v57; // r29
  double v58; // fp4
  double v59; // fp18
  double v60; // fp17
  double v61; // fp16
  unsigned __int16 *v62; // r30
  unsigned int v63; // r29
  int v64; // r30
  float z; // r7
  float v66; // r8
  float y; // r5
  float v68; // r9
  double v69; // fp11
  float v70; // r7
  double v71; // fp12
  float x; // r8
  encounterGroupRole_t *v73; // r23
  int v74; // r27
  idVec3 *v75; // r22
  int v76; // r24
  int num; // r26
  int v78; // r25
  idStaticModelSurface *v79; // r28
  bool v80; // r7
  int v81; // r29
  const idVec3 *v82; // r30
  double v83; // fp13
  double v84; // fp10
  int v85; // r11
  int v86; // r9
  encounterGroupRole_t *v87; // r10
  encounterGroupRole_t *v88; // r29
  int i; // r30
  int v90; // r8
  int v91; // r7
  int v92; // r6
  int v93; // r5
  int v94; // r4
  int v95; // r3
  bool v96; // [sp+50h] [-590h] BYREF
  idList<idVec3,5> v97; // [sp+60h] [-580h] BYREF
  float v98; // [sp+70h] [-570h] BYREF
  unsigned int v99; // [sp+74h] [-56Ch]
  idList<enum encounterGroupRole_t,5> v100; // [sp+80h] [-560h] BYREF
  idList<bool,5> v101; // [sp+90h] [-550h] BYREF
  int v102; // [sp+A0h] [-540h]
  idVec3 v103; // [sp+A8h] [-538h] BYREF
  idVec3 v104; // [sp+B8h] [-528h] BYREF
  idVec3 v105[2]; // [sp+C8h] [-518h] BYREF
  idList<idVec3,5> v106; // [sp+E0h] [-500h] BYREF
  idVec3 v107; // [sp+F0h] [-4F0h] BYREF
  const char *v108; // [sp+FCh] [-4E4h]
  const char *v109; // [sp+100h] [-4E0h]
  const char *v110; // [sp+104h] [-4DCh]
  float v111; // [sp+108h] [-4D8h]
  const char *v112; // [sp+10Ch] [-4D4h]
  int v113; // [sp+110h] [-4D0h]
  float v114; // [sp+114h] [-4CCh]
  const char *v115; // [sp+118h] [-4C8h]
  int v116; // [sp+11Ch] [-4C4h]
  const char *v117; // [sp+120h] [-4C0h]
  idVec3 v118; // [sp+128h] [-4B8h] BYREF
  __int64 v119; // [sp+138h] [-4A8h]
  idDrawVert v120[2]; // [sp+140h] [-4A0h] BYREF
  idStaticModel v121; // [sp+180h] [-460h] BYREF
  idStaticModel v122; // [sp+320h] [-2C0h] BYREF

  v2 = breakableDecl;
  v3 = decalModelName;
  if ( breakableDecl != nullptr && decalModelName != nullptr )
  {
    idStaticModel::idStaticModel(this: &v122);
    idResource::SetName(this: &v122, _name: v3);
    idStaticModel::PristineLoadResource(this: &v122);
    idStaticModel::idStaticModel(this: &v121);
    idResource::SetName(this: &v121, _name: v2->modelName.str);
    idStaticModel::PristineLoadResource(this: &v121);
    v4 = 0;
    v102 = 0;
    if ( v122.surfaces.num <= 0 )
    {
LABEL_73:
      idStaticModel::~idStaticModel(this: &v121);
    }
    else
    {
      v99 = 0;
      v5 = 0.0000099999997;
      v111 = 0.33333334;
      v114 = 0.0000099999997;
      v116 = -2089680896;
      v108 = "} }\n";
      v110 = "( %.2f %.2f %.2f ) { ";
      v112 = "( %.2f %.2f %.2f ) ";
      v117 = "( %.2f %.2f ) ";
      v115 = "%s ";
      v109 = "pieceDecal {  ";
      while ( 1 )
      {
        v6 = v4 + 1;
        geometry = v122.surfaces.list[v99 / 0x48].geometry;
        materialNum = v122.surfaces.list[v99 / 0x48].materialNum;
        p_x = &geometry->verts->xyz.x;
        indexes = geometry->indexes;
        numVerts = geometry->numVerts;
        numIndexes = geometry->numIndexes;
        v7 = &v122.surfaces.list[v99 / 0x48];
        if ( materialNum != v6 )
          break;
        memset(&v101, 0, 14);
        *(_WORD *)&v101.memTag = 1280;
        v113 = materialNum;
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v101);
        v96 = false;
        idList<bool,5>::SetNum(this: &v101, newNum: numVerts, initValue: &v96);
        list = v101.list;
        if ( numVerts - 1 > 0 )
        {
          LODWORD(v15) = 1;
          HIDWORD(v14) = p_x + 2;
          v18 = v101.list - 1;
          HIDWORD(v15) = numVerts - 1;
          do
          {
            if ( !v18[v15] )
            {
              v19 = v15;
              if ( (int)v15 < numVerts )
              {
                v20 = (float *)(HIDWORD(v14) + 28);
                v21 = numVerts - v15;
                do
                {
                  v16 = list[v19];
                  if ( v16 != 1 )
                  {
                    v22 = (float)(*(float *)(HIDWORD(v14) - 4) - *v20);
                    v23 = (float)(*(float *)(HIDWORD(v14) - 8) - *(v20 - 1));
                    v24 = (float)(*(float *)HIDWORD(v14) - v20[1]);
                    if ( (float)((float)((float)v24 * (float)v24)
                               + (float)((float)((float)v23 * (float)v23) + (float)((float)v22 * (float)v22))) < v5 )
                      list[v19] = true;
                  }
                  ++v19;
                  v20 += 8;
                  --v21;
                }
                while ( v21 != 0 );
              }
            }
            --HIDWORD(v15);
            LODWORD(v15) = v15 + 1;
            HIDWORD(v14) += 32;
          }
          while ( HIDWORD(v15) != 0 );
        }
        material = v7->material;
        v26 = 0.0;
        v27 = 0.0;
        v28 = 0;
        v29 = 0.0;
        v30 = 0;
        v31 = 0.0;
        v32 = 0.0;
        v33 = 0.0;
        if ( numVerts > 0 )
        {
          v34 = (const idVec3 *)p_x;
          do
          {
            if ( !list[v30] )
            {
              v26 = (float)((float)v26 + v34->x);
              v27 = (float)(v34->y + (float)v27);
              v29 = (float)((float)v29 + v34->z);
              Normal = idDrawVert::GetNormal(this: v120, result: v34, a3: v16, a4: v15);
              ++v28;
              v31 = (float)(Normal->x + (float)v31);
              v32 = (float)(Normal->y + (float)v32);
              v33 = (float)(Normal->z + (float)v33);
            }
            ++v30;
            v34 = (const idVec3 *)((char *)v34 + 32);
          }
          while ( v30 < numVerts );
        }
        LODWORD(v14) = v28;
        v36 = 1.0;
        v37 = 0.0;
        v119 = v14;
        _FP5 = (float)((float)((float)((float)v31 * (float)v31)
                             + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v39 = (float)((float)((float)1.0 / (float)v14) * (float)v26);
        v40 = (float)((float)((float)1.0 / (float)v14) * (float)v27);
        v41 = (float)((float)((float)1.0 / (float)v14) * (float)v29);
        __asm { fsel      f3, f5, f7, f0 }
        v43 = __frsqrte(_FP3);
        v44 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v43
                                                                                            * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5))
                                                                                    * (float)v43)
                                                                            - (float)1.5)
                                                            * (float)v43)
                                                    * (float)((float)((float)((float)v31 * (float)v31)
                                                                    + (float)((float)((float)v33 * (float)v33)
                                                                            + (float)((float)v32 * (float)v32)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v43
                                                                                    * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                                                                                            * (float)0.5))
                                                                            * (float)v43)
                                                                    - (float)1.5)
                                                    * (float)v43))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v43
                                                            * (float)((float)((float)((float)v31 * (float)v31)
                                                                            + (float)((float)((float)v33 * (float)v33)
                                                                                    + (float)((float)v32 * (float)v32)))
                                                                    * (float)0.5))
                                                    * (float)v43)
                                            - (float)1.5)
                            * (float)v43));
        v45 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v43 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5)) * (float)v43) - (float)1.5) * (float)v43)
                                                                                            * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v43 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5)) * (float)v43) - (float)1.5)
                                                                                            * (float)v43))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v43 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5))
                                                                                            * (float)v43)
                                                                                    - (float)1.5)
                                                                    * (float)v43))
                                                    * (float)((float)((float)((float)v31 * (float)v31)
                                                                    + (float)((float)((float)v33 * (float)v33)
                                                                            + (float)((float)v32 * (float)v32)))
                                                            * (float)0.5))
                                            * (float)v44)
                                    - (float)1.5)
                    * (float)v44);
        v46 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v43 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5)) * (float)v43) - (float)1.5) * (float)v43) * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v43 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5)) * (float)v43) - (float)1.5) * (float)v43))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v43 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5)) * (float)v43)
                                                                                            - (float)1.5)
                                                                            * (float)v43))
                                                            * (float)((float)((float)((float)v31 * (float)v31)
                                                                            + (float)((float)((float)v33 * (float)v33)
                                                                                    + (float)((float)v32 * (float)v32)))
                                                                    * (float)0.5))
                                                    * (float)v44)
                                            - (float)1.5)
                            * (float)v44)
                    * (float)v31);
        v47 = (float)((float)v45 * (float)v32);
        v48 = (float)((float)v45 * (float)v33);
        v49 = (float)((float)((float)v47 * (float)v47) + (float)((float)v46 * (float)v46));
        if ( v49 != 0.0 )
        {
          _FP12 = (float)((float)((float)((float)v47 * (float)v47) + (float)((float)v46 * (float)v46))
                        - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f10, f12, f13, f0 }
          v52 = __frsqrte(_FP10);
          v53 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v52
                                                                                              * (float)((float)v49 * (float)0.5))
                                                                                      * (float)v52)
                                                                              - (float)1.5)
                                                              * (float)v52)
                                                      * (float)((float)v49 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v52
                                                                                      * (float)((float)v49 * (float)0.5))
                                                                              * (float)v52)
                                                                      - (float)1.5)
                                                      * (float)v52))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v52 * (float)((float)v49 * (float)0.5))
                                                      * (float)v52)
                                              - (float)1.5)
                              * (float)v52));
          v54 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v52 * (float)((float)v49 * (float)0.5)) * (float)v52) - (float)1.5) * (float)v52)
                                                                                              * (float)((float)v49 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v52 * (float)((float)v49 * (float)0.5)) * (float)v52) - (float)1.5)
                                                                                              * (float)v52))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v52 * (float)((float)v49 * (float)0.5))
                                                                                              * (float)v52)
                                                                                      - (float)1.5)
                                                                      * (float)v52))
                                                      * (float)((float)v49 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v52 * (float)((float)v49 * (float)0.5)) * (float)v52) - (float)1.5)
                                                                                              * (float)v52)
                                                                                      * (float)((float)v49 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v52 * (float)((float)v49 * (float)0.5)) * (float)v52) - (float)1.5)
                                                                                      * (float)v52))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v52
                                                                                              * (float)((float)v49 * (float)0.5))
                                                                                      * (float)v52)
                                                                              - (float)1.5)
                                                              * (float)v52)))
                                      - (float)1.5)
                      * (float)v53);
          v37 = (float)((float)v46 * (float)v54);
          v36 = -(float)((float)v47 * (float)v54);
        }
        v55 = (float)(p_x[1] - (float)((float)((float)1.0 / (float)v119) * (float)v27));
        v56 = (float)(*p_x - (float)((float)((float)1.0 / (float)v119) * (float)v26));
        v57 = nullptr;
        v58 = (float)(p_x[2] - (float)((float)((float)1.0 / (float)v119) * (float)v29));
        v98 = p_x[1] - (float)((float)((float)1.0 / (float)v119) * (float)v27);
        memset(&v97, 0, 14);
        v59 = idMath::TWO_PI;
        *(_WORD *)&v97.memTag = 1280;
        v60 = __fabs((float)((float)((float)v58 * (float)0.0)
                           + (float)((float)((float)v56 * (float)v36) + (float)((float)v37 * (float)v55))));
        v61 = __fabs((float)((float)((float)v58
                                   * (float)((float)((float)v37 * (float)v46) - (float)((float)v36 * (float)v47)))
                           + (float)((float)((float)v56
                                           * (float)((float)((float)v47 * (float)0.0) - (float)((float)v37 * (float)v48)))
                                   + (float)((float)v55
                                           * (float)((float)((float)v36 * (float)v48) - (float)((float)v46 * (float)0.0))))));
        if ( numIndexes > 0 )
        {
          v62 = indexes - 1;
          v63 = (numIndexes - 1) / 3u + 1;
          do
          {
            idList<idAngles,5>::Append(this: &v97, obj: (const idVec3 *)((char *)p_x + __ROL4__(v62[1], 5)));
            idList<idAngles,5>::Append(this: &v97, obj: (const idVec3 *)((char *)p_x + __ROL4__(v62[2], 5)));
            v62 += 3;
            idList<idAngles,5>::Append(this: &v97, obj: (const idVec3 *)((char *)p_x + __ROL4__(*v62, 5)));
            --v63;
          }
          while ( v63 != 0 );
          v57 = v97.list;
        }
        v106.list = nullptr;
        v106.listStatic = 0;
        idList<idVec3,30>::operator=(this: (idList<idVec3,59> *)&v106, other: (const idList<idVec3,59> *)&v97);
        v64 = 0;
        while ( 1 )
        {
          z = v57[v64 + 1].z;
          v66 = v57[v64].z;
          v105[0].x = v57[v64].x;
          y = v57[v64 + 2].y;
          v68 = v57[v64 + 2].z;
          v104.z = z;
          v69 = z;
          v70 = v57[v64].y;
          v105[0].z = v66;
          v71 = v66;
          x = v57[v64 + 2].x;
          v103.y = y;
          v103.z = v68;
          v105[0].y = v70;
          v104.x = v57[v64 + 1].x;
          v103.x = x;
          v104.y = v57[v64 + 1].y;
          v107.y = (float)(y + (float)(v70 + v104.y)) * v111;
          v107.x = (float)((float)(v104.x + v105[0].x) + x) * v111;
          v107.z = (float)(v68 + (float)((float)v71 + (float)v69)) * v111;
          idList<idAngles,5>::Append(this: &v97, obj: &v107);
          idList<idAngles,5>::Append(this: &v97, obj: &v104);
          idList<idAngles,5>::Append(this: &v97, obj: &v103);
          idList<idAngles,5>::Append(this: &v97, obj: v105);
          idList<idAngles,5>::Append(this: &v97, obj: &v107);
          idList<idAngles,5>::Append(this: &v97, obj: &v103);
          idList<idAngles,5>::Append(this: &v97, obj: v105);
          idList<idAngles,5>::Append(this: &v97, obj: &v104);
          idList<idAngles,5>::Append(this: &v97, obj: &v107);
          idList<idAngles,5>::Append(this: &v106, obj: &v107);
          v64 += 3;
          if ( v64 >= 45 )
            break;
          v57 = v97.list;
        }
        v73 = nullptr;
        v74 = 0;
        *(_WORD *)&v100.memTag = 1280;
        memset(&v100, 0, 14);
        v75 = v106.list;
        v76 = 0;
        if ( v121.surfaces.num > 0 )
        {
          num = v106.num;
          v78 = 0;
          do
          {
            v79 = &v121.surfaces.list[v78];
            if ( &v121.surfaces.list[v78] != nullptr
              && (idParmBlock::GetInteger(
                    this: &v79->material->parmBlock,
                    parm: *(const idDeclRenderParm **)(*(_DWORD *)(v116 + 28248) + 160))
                & 0x40) != 0 )
            {
              v81 = 0;
              if ( num > 0 )
              {
                v82 = v75;
                while ( 1 )
                {
                  v83 = v82->y;
                  v84 = (float)(v82->x - (float)((float)((float)v46 * (float)32.0) * (float)0.5));
                  v118.z = v82->z - (float)((float)((float)v48 * (float)32.0) * (float)0.5);
                  v118.x = v84;
                  v118.y = (float)v83 - (float)((float)((float)v47 * (float)32.0) * (float)0.5);
                  idTriangles::TriangleTrace(
                    this: (idTriangles *)&v120[0].st.y,
                    result: (localTrace_t *)v79->geometry,
                    start: v82,
                    end: &v118,
                    radius: 0.0,
                    twoSided: v80);
                  if ( v120[0].st.y < 1.0 )
                    break;
                  ++v81;
                  ++v82;
                  if ( v81 >= num )
                    goto LABEL_47;
                }
                v85 = 0;
                v86 = v79->materialNum - 1;
                v98 = *(float *)&v86;
                if ( v74 <= 0 )
                  goto LABEL_46;
                v87 = v73;
                while ( *v87 != v86 )
                {
                  ++v85;
                  ++v87;
                  if ( v85 >= v74 )
                    goto LABEL_46;
                }
                if ( v85 < 0 )
                {
LABEL_46:
                  idList<idAnimWebBlendTree *,5>::Append(this: &v100, obj: (const encounterGroupRole_t *)&v98);
                  v74 = v100.num;
                  v73 = v100.list;
                }
              }
            }
LABEL_47:
            ++v76;
            ++v78;
          }
          while ( v76 < v121.surfaces.num );
          if ( v74 > 0 )
          {
            idLib::Printf(fmt: v109);
            idLib::Printf(fmt: v115, material->name.str);
            idLib::Printf(fmt: v117, LODWORD(v60), LODWORD(v61), v60, v61);
            idLib::Printf(fmt: "%.2f ", 32.0);
            idLib::Printf(fmt: "%.2f ", v59);
            idLib::Printf(fmt: v112, LODWORD(v39), LODWORD(v40), LODWORD(v41), v39, v40, v41);
            idLib::Printf(fmt: v110, LODWORD(v46), LODWORD(v47), LODWORD(v48), v46, v47, v48);
            v88 = v73 - 1;
            for ( i = v74; i != 0; --i )
              idLib::Printf(fmt: "%d ", *++v88);
            idLib::Printf(fmt: v108);
          }
        }
        if ( v100.listStatic == 0 || v100.listStatic == 2 )
        {
          if ( v73 != nullptr )
            idMem::Free(this: &mem, ptr: v73, align: ALIGN_16);
          v100.list = nullptr;
          v100.size = 0;
        }
        v100.num = 0;
        if ( v106.listStatic == 0 || v106.listStatic == 2 )
        {
          if ( v75 != nullptr )
            idMem::Free(this: &mem, ptr: v75, align: ALIGN_16);
          v106.list = nullptr;
          v106.size = 0;
        }
        v106.num = 0;
        if ( v97.listStatic == 0 || v97.listStatic == 2 )
        {
          if ( v97.list != nullptr )
            idMem::Free(this: &mem, ptr: v97.list, align: ALIGN_16);
          v97.list = nullptr;
          v97.size = 0;
        }
        v97.num = 0;
        if ( v101.listStatic == 0 || v101.listStatic == 2 )
        {
          if ( list != nullptr )
            idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
          v101.list = nullptr;
          v101.size = 0;
        }
        v101.num = 0;
        ++v102;
        v99 += 72;
        if ( v102 >= v122.surfaces.num )
          goto LABEL_73;
        v5 = v114;
        v4 = v113;
        v2 = breakableDecl;
        v3 = decalModelName;
      }
      idLib::Warning(
        fmt: "idDeclBreakable::GenerateDecalInfoFromModel() - %s loaded in decal model %s with incorrect surface num info",
        v2->name.str,
        v3);
      idStaticModel::~idStaticModel(this: &v121);
    }
    idStaticModel::~idStaticModel(this: &v122);
  }
  else
  {
    idLib::Error(fmt: "idDeclBreakable::GenerateDecalInfoFromModel() - passed a NULL argument");
    _LN336(a1: v95, a2: v94, a3: v93, a4: v92, a5: v91, a6: v90);
  }
}


// ========================================================================
// $LN336
// EA  : 0x82614FFC
// RVA : 0x00614FFC
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _LN336()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 1504 + 800));
}


// ========================================================================
// __unwind$223979
// EA  : 0x82615024
// RVA : 0x00615024
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_223979()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 1504 + 384));
}


// ========================================================================
// __unwind$223980
// EA  : 0x8261504C
// RVA : 0x0061504C
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_223980()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1504 + 144));
}


// ========================================================================
// __unwind$223981
// EA  : 0x82615074
// RVA : 0x00615074
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_223981()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1504 + 96));
}


// ========================================================================
// __unwind$223982
// EA  : 0x8261509C
// RVA : 0x0061509C
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_223982()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1504 + 224));
}


// ========================================================================
// __unwind$223983_0
// EA  : 0x826150C4
// RVA : 0x006150C4
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_223983_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1504 + 128));
}


// ========================================================================
// ?GenerateBreakableDecalInfo_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826150F0
// RVA : 0x006150F0
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall GenerateBreakableDecalInfo_f(const idCmdArgs *args)
{
  const char *v2; // r4
  const idDeclBreakable *v3; // r3
  const char *v4; // r4

  if ( args->argc == 3 )
  {
    v2 = args->argv[1];
    if ( v2 != nullptr )
      v3 = (const idDeclBreakable *)idDeclInfo::FindWithInheritance(
                                      this: &idDeclBreakable::resourceList,
                                      name: v2,
                                      makeDefault: false);
    else
      v3 = nullptr;
    if ( args->argc <= 2 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[2];
    if ( v3 != nullptr )
      idDeclBreakable::GenerateDecalInfoFromModel(breakableDecl: v3, decalModelName: v4);
  }
}


// ========================================================================
// ?Clear@idDeclBreakable@@AAAXXZ
// EA  : 0x82615540
// RVA : 0x00615540
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall idDeclBreakable::Clear(idDeclBreakable *this)
{
  char *list; // r3
  char *v3; // r3
  char *v4; // r3
  char *v5; // r3

  this->numPieces = 0;
  this->settings.linearFriction = 0.60000002;
  this->settings.angularFriction = 0.60000002;
  this->settings.bouncyness = 0.60000002;
  this->settings.contactFriction = 0.5;
  this->settings.linearFrictionWater = 1.0;
  this->settings.angularFrictionWater = 1.0;
  this->settings.gravityVector.x = 0.0;
  this->settings.gravityVector.y = 0.0;
  this->settings.gravityVector.z = -250.0;
  this->settings.worldCollisionOnly = false;
  this->settings.simplePointCollision = false;
  this->settings.crazyBounceChance = 0.0;
  this->settings.noShadows = false;
  this->settings.maxSimulationTime = 10.0;
  this->settings.dampeningDecay = 0.0;
  if ( this->explosions.listStatic == 0 || this->explosions.listStatic == 2 )
  {
    list = (char *)this->explosions.list;
    if ( list != nullptr )
      idListArrayDelete<idBreakableExplosion>(ptr: list, num: this->explosions.size);
    this->explosions.list = nullptr;
    this->explosions.size = 0;
  }
  this->explosions.num = 0;
  if ( this->trails.listStatic == 0 || this->trails.listStatic == 2 )
  {
    v3 = (char *)this->trails.list;
    if ( v3 != nullptr )
      idListArrayDelete<idBreakableTrail>(ptr: v3, num: this->trails.size);
    this->trails.list = nullptr;
    this->trails.size = 0;
  }
  this->trails.num = 0;
  if ( this->decals.listStatic == 0 || this->decals.listStatic == 2 )
  {
    v4 = (char *)this->decals.list;
    if ( v4 != nullptr )
      idListArrayDelete<idBreakableDecal>(ptr: v4, num: this->decals.size);
    this->decals.list = nullptr;
    this->decals.size = 0;
  }
  this->decals.num = 0;
  if ( this->pieceDecals.listStatic == 0 || this->pieceDecals.listStatic == 2 )
  {
    v5 = (char *)this->pieceDecals.list;
    if ( v5 != nullptr )
      idListArrayDelete<idBreakablePieceDecal>(ptr: v5, num: this->pieceDecals.size);
    this->pieceDecals.list = nullptr;
    this->pieceDecals.size = 0;
  }
  this->pieceDecals.num = 0;
}


// ========================================================================
// ??0idDeclBreakable@@QAA@XZ
// EA  : 0x82615D70
// RVA : 0x00615D70
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

idDeclBreakable *__fastcall idDeclBreakable::idDeclBreakable(idDeclBreakable *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idDeclBreakable_vtbl *)&idDeclBreakable::`vftable';
  this->modelName.str = &byte_8200D768;
  idBreakableSettings::idBreakableSettings(this: &this->settings);
  this->explosions.granularity = 0;
  this->explosions.memTag = 59;
  this->explosions.listStatic = 0;
  this->explosions.list = nullptr;
  this->explosions.size = 0;
  this->explosions.num = 0;
  this->trails.granularity = 0;
  this->trails.memTag = 59;
  this->trails.listStatic = 0;
  this->trails.list = nullptr;
  this->trails.size = 0;
  this->trails.num = 0;
  this->armoredPieces.list = nullptr;
  this->armoredPieces.granularity = 0;
  this->armoredPieces.memTag = 59;
  this->armoredPieces.listStatic = 0;
  this->armoredPieces.size = 0;
  this->armoredPieces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->armoredPieces);
  this->healthPieces.list = nullptr;
  this->healthPieces.granularity = 0;
  this->healthPieces.memTag = 59;
  this->healthPieces.listStatic = 0;
  this->healthPieces.size = 0;
  this->healthPieces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->healthPieces);
  this->decals.granularity = 0;
  this->decals.memTag = 59;
  this->decals.listStatic = 0;
  this->decals.list = nullptr;
  this->decals.size = 0;
  this->decals.num = 0;
  this->pieceDecals.granularity = 0;
  this->pieceDecals.memTag = 5;
  this->pieceDecals.listStatic = 0;
  this->pieceDecals.list = nullptr;
  this->pieceDecals.size = 0;
  this->pieceDecals.num = 0;
  this->sparks.materials.list = nullptr;
  this->sparks.materials.granularity = 0;
  this->sparks.materials.memTag = 59;
  this->sparks.materials.listStatic = 0;
  this->sparks.materials.size = 0;
  this->sparks.materials.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sparks);
  idDeclBreakable::Clear(this);
  return this;
}


// ========================================================================
// __unwind$225374
// EA  : 0x82615EB4
// RVA : 0x00615EB4
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225374()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$225375
// EA  : 0x82615EDC
// RVA : 0x00615EDC
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225375()
{
  int v0; // r12

  idList<idBreakableExplosion,59>::~idList<idBreakableExplosion,59>(this: (idList<idBreakableExplosion,59> *)(*(_DWORD *)(v0 - 128 + 148) + 148));
}


// ========================================================================
// __unwind$225376
// EA  : 0x82615F08
// RVA : 0x00615F08
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225376()
{
  int v0; // r12

  idList<idBreakableTrail,59>::~idList<idBreakableTrail,59>(this: (idList<idBreakableTrail,59> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                                + 164));
}


// ========================================================================
// __unwind$225377
// EA  : 0x82615F34
// RVA : 0x00615F34
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225377()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 180));
}


// ========================================================================
// __unwind$225378_0
// EA  : 0x82615F60
// RVA : 0x00615F60
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225378_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 196));
}


// ========================================================================
// __unwind$225379_0
// EA  : 0x82615F8C
// RVA : 0x00615F8C
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225379_0()
{
  int v0; // r12

  idList<idBreakableDecal,59>::~idList<idBreakableDecal,59>(this: (idList<idBreakableDecal,59> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                                + 212));
}


// ========================================================================
// __unwind$225380
// EA  : 0x82615FB8
// RVA : 0x00615FB8
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225380()
{
  int v0; // r12

  idList<idBreakablePieceDecal,5>::Clear(this: (idList<idBreakablePieceDecal,5> *)(*(_DWORD *)(v0 - 128 + 148) + 228));
}


// ========================================================================
// __unwind$225381
// EA  : 0x82615FE4
// RVA : 0x00615FE4
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225381()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 244));
}


// ========================================================================
// ?ParseExplosion@idDeclBreakable@@AAAXAAVidParser@@@Z
// EA  : 0x82616278
// RVA : 0x00616278
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall idDeclBreakable::ParseExplosion(idDeclBreakable *this, idParser *src)
{
  int UnsignedIntValue; // r3
  int v5; // r29
  int num; // r30
  encounterGroupRole_t *list; // r28
  int v8; // r10
  encounterGroupRole_t *v9; // r11
  int numPieces; // r11
  const char *v11; // [sp+50h] [-160h] BYREF
  int v12; // [sp+58h] [-158h] BYREF
  int v13; // [sp+5Ch] [-154h]
  idList<enum encounterGroupRole_t,5> v14; // [sp+60h] [-150h] BYREF
  idToken v15; // [sp+70h] [-140h] BYREF
  idBreakableExplosion v16[2]; // [sp+C0h] [-F0h] BYREF

  v16[0].pieces.list = nullptr;
  v16[0].pieces.granularity = 0;
  v16[0].pieces.memTag = 59;
  v16[0].pieces.listStatic = 0;
  v16[0].pieces.size = 0;
  v16[0].pieces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v16[0].pieces);
  v16[0].fx = nullptr;
  v16[0].particle = nullptr;
  v16[0].delay = 0;
  v16[0].useLinear = false;
  v16[0].activateAllDelay = -1;
  v16[0].duration = 200;
  memset(&v14, 0, 14);
  v16[0].position.z = 0.0;
  v16[0].position.y = 0.0;
  v16[0].position.x = 0.0;
  *(_WORD *)&v14.memTag = 15104;
  v16[0].radius = 0.0;
  v16[0].impulse = 3000.0;
  v16[0].falloff = 0.2;
  v16[0].angular = 0.0;
  v16[0].distTimeScaleDelay = 0.0;
  v16[0].endLinear.z = 0.0;
  v16[0].endLinear.y = 0.0;
  v16[0].endLinear.x = 0.0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14);
  if ( this->numPieces == 0 )
    idParser::Warning(this: src, str: "no model specified\n");
  v11 = "{";
  if ( idParser::ExpectTokenString(this: src, string: "{") )
  {
    v15.len = 0;
    v15.baseBuffer[0] = 0;
    v15.intvalue = 0;
    v15.allocedAndFlag = 20;
    v15.data = v15.baseBuffer;
    memset(&v15.whiteSpaceStart_p, 0, 12);
    v15.floatvalue = -3.4028235e38;
    if ( idParser::ExpectAnyToken(this: src, token: &v15) != 0 )
    {
      while ( idStr::Cmp(s1: v15.data, s2: "}") != 0 )
      {
        if ( idStr::Icmp(s1: v15.data, s2: "particle") != 0 )
        {
          if ( idStr::Icmp(s1: v15.data, s2: "fx") != 0 )
          {
            if ( idStr::Icmp(s1: v15.data, s2: "position") != 0 )
            {
              if ( idStr::Icmp(s1: v15.data, s2: "radius") != 0 )
              {
                if ( idStr::Icmp(s1: v15.data, s2: "impulse") != 0 )
                {
                  if ( idStr::Icmp(s1: v15.data, s2: "falloff") != 0 )
                  {
                    if ( idStr::Icmp(s1: v15.data, s2: "angular") != 0 )
                    {
                      if ( idStr::Icmp(s1: v15.data, s2: "delay") != 0 )
                      {
                        if ( idStr::Icmp(s1: v15.data, s2: "activateAllDelay") != 0 )
                        {
                          if ( idStr::Icmp(s1: v15.data, s2: "duration") != 0 )
                          {
                            if ( idStr::Icmp(s1: v15.data, s2: "excludePieces") != 0 )
                            {
                              idParser::Warning(this: src, str: "Bad token '%s'\n", v15.data);
                              idStr::FreeData(this: &v15);
                              idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14);
                              goto LABEL_53;
                            }
                            idParser::ExpectTokenString(this: src, string: v11);
                            while ( idParser::ReadToken(this: src, token: &v15) )
                            {
                              if ( idStr::Cmp(s1: v15.data, s2: "}") == 0 )
                                break;
                              UnsignedIntValue = idToken::GetUnsignedIntValue(this: &v15);
                              if ( UnsignedIntValue < 1 || UnsignedIntValue > this->numPieces )
                              {
                                idParser::Warning(
                                  this: src,
                                  str: "excludePieces { } number %d out of range\n",
                                  UnsignedIntValue);
                              }
                              else
                              {
                                v12 = UnsignedIntValue - 1;
                                idList<idAnimWebBlendTree *,5>::Append(
                                  this: &v14,
                                  obj: (const encounterGroupRole_t *)&v12);
                              }
                            }
                          }
                          else
                          {
                            v13 = (int)(float)(idParser::ParseFloat(this: src, errorFlag: nullptr) * 1000.0);
                            v16[0].duration = v13;
                          }
                        }
                        else
                        {
                          v13 = (int)(float)(idParser::ParseFloat(this: src, errorFlag: nullptr) * 1000.0);
                          v16[0].activateAllDelay = v13;
                        }
                      }
                      else
                      {
                        v13 = (int)(float)(idParser::ParseFloat(this: src, errorFlag: nullptr) * 1000.0);
                        v16[0].delay = v13;
                      }
                    }
                    else
                    {
                      v16[0].angular = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    }
                  }
                  else
                  {
                    v16[0].falloff = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  v16[0].impulse = idParser::ParseFloat(this: src, errorFlag: nullptr);
                }
              }
              else
              {
                v16[0].radius = idParser::ParseFloat(this: src, errorFlag: nullptr);
              }
            }
            else
            {
              v16[0].position.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
              v16[0].position.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
              v16[0].position.z = idParser::ParseFloat(this: src, errorFlag: nullptr);
            }
          }
          else
          {
            idParser::ReadToken(this: src, token: &v15);
            if ( v15.data != nullptr )
              v16[0].fx = (const idDeclFX *)idDeclInfo::FindWithInheritance(
                                              this: &idDeclFX::resourceList,
                                              name: v15.data,
                                              makeDefault: false);
            else
              v16[0].fx = nullptr;
          }
        }
        else
        {
          idParser::ReadToken(this: src, token: &v15);
          if ( v15.data != nullptr )
            v16[0].particle = (const idDeclParticle *)idDeclInfo::FindWithInheritance(
                                                        this: &idDeclParticle::resourceList,
                                                        name: v15.data,
                                                        makeDefault: false);
          else
            v16[0].particle = nullptr;
        }
        if ( idParser::ExpectAnyToken(this: src, token: &v15) == 0 )
          goto LABEL_40;
      }
      v5 = 0;
      v11 = nullptr;
      if ( this->numPieces > 0 )
      {
        num = v14.num;
        list = v14.list;
        do
        {
          v8 = 0;
          if ( num <= 0 )
            goto LABEL_49;
          v9 = list;
          while ( *v9 != v5 )
          {
            ++v8;
            ++v9;
            if ( v8 >= num )
              goto LABEL_49;
          }
          if ( v8 >= num )
LABEL_49:
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&v16[0].pieces,
              obj: (const encounterGroupRole_t *)&v11);
          numPieces = this->numPieces;
          v11 = (const char *)++v5;
        }
        while ( v5 < numPieces );
      }
      idList<idBreakableExplosion,59>::Append(this: &this->explosions, obj: v16);
      idStr::FreeData(this: &v15);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14);
    }
    else
    {
LABEL_40:
      idStr::FreeData(this: &v15);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14);
    }
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14);
  }
LABEL_53:
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v16[0].pieces);
}


// ========================================================================
// __unwind$225647
// EA  : 0x82616834
// RVA : 0x00616834
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225647()
{
  int v0; // r12

  idBreakableExplosion::~idBreakableExplosion(this: (idBreakableExplosion *)(v0 - 432 + 192));
}


// ========================================================================
// __unwind$225648
// EA  : 0x8261685C
// RVA : 0x0061685C
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225648()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 96));
}


// ========================================================================
// __unwind$225649
// EA  : 0x82616884
// RVA : 0x00616884
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225649()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 112));
}


// ========================================================================
// ?ParseTrail@idDeclBreakable@@AAAXAAVidParser@@@Z
// EA  : 0x826168B8
// RVA : 0x006168B8
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall idDeclBreakable::ParseTrail(idDeclBreakable *this, idParser *src)
{
  int numPieces; // r8
  double v5; // fp1
  int UnsignedIntValue; // r3
  idDeclBreakable *v7; // r29
  int size; // r11
  int v9; // r30
  int v10; // r11
  int *v11; // r10
  int v12; // [sp+50h] [-160h] BYREF
  int v13; // [sp+54h] [-15Ch]
  idBreakableTrail v14; // [sp+60h] [-150h] BYREF
  idToken v15; // [sp+B0h] [-100h] BYREF
  int v16; // [sp+F8h] [-B8h]
  const char *v17; // [sp+FCh] [-B4h]
  const char *v18; // [sp+100h] [-B0h]
  const char *v19; // [sp+104h] [-ACh]
  const char *v20; // [sp+108h] [-A8h]
  const char *v21; // [sp+10Ch] [-A4h]

  memset(&v14.pieces, 0, 14);
  v14.pieces.memTag = 59;
  v14.pieces.listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14.pieces);
  numPieces = this->numPieces;
  memset(&v14, 0, 16);
  v14.glowQuadSize = 20.0;
  memset(&v14.delay, 0, 16);
  v14.minTrailVelocity = 10.0;
  v14.minBounceVelocity = 10.0;
  v14.trailSpacing = 20.0;
  v14.trailVelocityScale = 0.0;
  if ( numPieces == 0 )
    idParser::Warning(this: src, str: "no model specified\n");
  v20 = "{";
  if ( idParser::ExpectTokenString(this: src, string: "{") )
  {
    v15.len = 0;
    v15.baseBuffer[0] = 0;
    v15.intvalue = 0;
    v15.allocedAndFlag = 20;
    v15.data = v15.baseBuffer;
    memset(&v15.whiteSpaceStart_p, 0, 12);
    v15.floatvalue = -3.4028235e38;
    if ( idParser::ExpectAnyToken(this: src, token: &v15) != 0 )
    {
      v16 = -2110193664;
      v21 = "glowQuadMaterial";
      v19 = "particleDie";
      v17 = "particleBounce";
      v18 = "particleTrail";
      while ( idStr::Cmp(s1: v15.data, s2: "}") != 0 )
      {
        if ( idStr::Icmp(s1: v15.data, s2: v18) != 0 )
        {
          if ( idStr::Icmp(s1: v15.data, s2: v17) != 0 )
          {
            if ( idStr::Icmp(s1: v15.data, s2: v19) != 0 )
            {
              if ( idStr::Icmp(s1: v15.data, s2: v21) != 0 )
              {
                if ( idStr::Icmp(s1: v15.data, s2: "glowQuadSize") != 0 )
                {
                  if ( idStr::Icmp(s1: v15.data, s2: "fadeInDuration") != 0 )
                  {
                    if ( idStr::Icmp(s1: v15.data, s2: "fadeOutDuration") != 0 )
                    {
                      if ( idStr::Icmp(s1: v15.data, s2: "minTrailVelocity") != 0 )
                      {
                        if ( idStr::Icmp(s1: v15.data, s2: "minBounceVelocity") != 0 )
                        {
                          if ( idStr::Icmp(s1: v15.data, s2: "trailSpacing") != 0 )
                          {
                            if ( idStr::Icmp(s1: v15.data, s2: "trailVelocityScale") != 0 )
                            {
                              if ( idStr::Icmp(s1: v15.data, s2: "delay") != 0 )
                              {
                                if ( idStr::Icmp(s1: v15.data, s2: "duration") != 0 )
                                {
                                  if ( idStr::Icmp(s1: v15.data, s2: "pieces") != 0 )
                                  {
                                    idParser::Warning(this: src, str: "Bad token '%s'\n", v15.data);
                                    idStr::FreeData(this: &v15);
                                    goto LABEL_70;
                                  }
                                  idParser::ExpectTokenString(this: src, string: v20);
                                  while ( idParser::ReadToken(this: src, token: &v15) )
                                  {
                                    if ( idStr::Cmp(s1: v15.data, s2: "}") == 0 )
                                      break;
                                    if ( idStr::Cmp(s1: v15.data, s2: "all") != 0 )
                                    {
                                      UnsignedIntValue = idToken::GetUnsignedIntValue(this: &v15);
                                      if ( UnsignedIntValue < 1 || UnsignedIntValue > this->numPieces )
                                      {
                                        idParser::Warning(
                                          this: src,
                                          str: "pieces { } number %d out of range\n",
                                          UnsignedIntValue);
                                      }
                                      else
                                      {
                                        v12 = UnsignedIntValue - 1;
                                        idList<idAnimWebBlendTree *,5>::Append(
                                          this: (idList<enum encounterGroupRole_t,5> *)&v14.pieces,
                                          obj: (const encounterGroupRole_t *)&v12);
                                      }
                                    }
                                    else
                                    {
                                      idList<idObstacleBuffers *,5>::SetNum(
                                        this: (idList<int,37> *)&v14.pieces,
                                        newNum: 0);
                                    }
                                  }
                                }
                                else
                                {
                                  v13 = (int)(float)(idParser::ParseFloat(this: src, errorFlag: nullptr) * 1000.0);
                                  v14.duration = v13;
                                }
                              }
                              else
                              {
                                v13 = (int)(float)(idParser::ParseFloat(this: src, errorFlag: nullptr) * 1000.0);
                                v14.delay = v13;
                              }
                            }
                            else
                            {
                              v14.trailVelocityScale = idParser::ParseFloat(this: src, errorFlag: nullptr);
                            }
                          }
                          else
                          {
                            v5 = idParser::ParseFloat(this: src, errorFlag: nullptr);
                            if ( v5 >= 1.0 )
                            {
                              if ( v5 <= *(float *)(v16 - 31152) )
                                v14.trailSpacing = v5;
                              else
                                v14.trailSpacing = *(float *)(v16 - 31152);
                            }
                            else
                            {
                              v14.trailSpacing = 1.0;
                            }
                          }
                        }
                        else
                        {
                          v14.minBounceVelocity = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        }
                      }
                      else
                      {
                        v14.minTrailVelocity = idParser::ParseFloat(this: src, errorFlag: nullptr);
                      }
                    }
                    else
                    {
                      v13 = (int)(float)(idParser::ParseFloat(this: src, errorFlag: nullptr) * 1000.0);
                      v14.fadeOutDuration = v13;
                    }
                  }
                  else
                  {
                    v13 = (int)(float)(idParser::ParseFloat(this: src, errorFlag: nullptr) * 1000.0);
                    v14.fadeInDuration = v13;
                  }
                }
                else
                {
                  v14.glowQuadSize = idParser::ParseFloat(this: src, errorFlag: nullptr);
                }
              }
              else
              {
                idParser::ReadToken(this: src, token: &v15);
                if ( v15.data != nullptr )
                  v14.glowQuadMaterial = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                               this: &idMaterial::resourceList,
                                                               name: v15.data,
                                                               makeDefault: false);
                else
                  v14.glowQuadMaterial = nullptr;
              }
            }
            else
            {
              idParser::ReadToken(this: src, token: &v15);
              if ( v15.data != nullptr )
                v14.particleDie = (const idDeclParticle *)idDeclInfo::FindWithInheritance(
                                                            this: &idDeclParticle::resourceList,
                                                            name: v15.data,
                                                            makeDefault: false);
              else
                v14.particleDie = nullptr;
            }
          }
          else
          {
            idParser::ReadToken(this: src, token: &v15);
            if ( v15.data != nullptr )
              v14.particleBounce = (const idDeclParticle *)idDeclInfo::FindWithInheritance(
                                                             this: &idDeclParticle::resourceList,
                                                             name: v15.data,
                                                             makeDefault: false);
            else
              v14.particleBounce = nullptr;
          }
        }
        else
        {
          idParser::ReadToken(this: src, token: &v15);
          if ( v15.data != nullptr )
            v14.particleTrail = (const idDeclParticle *)idDeclInfo::FindWithInheritance(
                                                          this: &idDeclParticle::resourceList,
                                                          name: v15.data,
                                                          makeDefault: false);
          else
            v14.particleTrail = nullptr;
        }
        if ( idParser::ExpectAnyToken(this: src, token: &v15) == 0 )
          goto LABEL_56;
      }
      if ( v14.pieces.num != 0 )
      {
        v7 = this;
LABEL_68:
        idList<idBreakableTrail,59>::Append(this: &v7->trails, obj: &v14);
        idStr::FreeData(this: &v15);
        goto LABEL_70;
      }
      v7 = this;
      size = v14.pieces.size;
      v9 = this->numPieces;
      if ( v9 > v14.pieces.size )
      {
        if ( !idList<idNavSpline *,5>::Resize(
                this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v14.pieces,
                newsize: this->numPieces) )
        {
LABEL_63:
          v10 = 0;
          if ( this->numPieces > 0 )
          {
            v11 = v14.pieces.list - 1;
            do
              *++v11 = v10++;
            while ( v10 < this->numPieces );
          }
          goto LABEL_68;
        }
        size = v14.pieces.size;
      }
      v14.pieces.num = v9;
      if ( v9 >= size )
        v14.pieces.num = size;
      goto LABEL_63;
    }
LABEL_56:
    idStr::FreeData(this: &v15);
  }
LABEL_70:
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14.pieces);
}


// ========================================================================
// __unwind$225998
// EA  : 0x82616F6C
// RVA : 0x00616F6C
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225998()
{
  int v0; // r12

  idInfluenceTrail::~idInfluenceTrail(this: (idInfluenceTrail *)(v0 - 432 + 96));
}


// ========================================================================
// __unwind$225999
// EA  : 0x82616F94
// RVA : 0x00616F94
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_225999()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 176));
}


// ========================================================================
// ?ParseDecals@idDeclBreakable@@AAAXAAVidParser@@@Z
// EA  : 0x82616FC8
// RVA : 0x00616FC8
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall idDeclBreakable::ParseDecals(idDeclBreakable *this, idParser *src)
{
  int numPieces; // r9
  double v5; // fp1
  const idDecl *v6; // r3
  int UnsignedIntValue; // r3
  double x; // fp12
  double y; // fp13
  idDeclBreakable *v10; // r29
  int size; // r11
  int v12; // r30
  int v13; // r11
  int v14; // r10
  const idDecl *v15; // [sp+50h] [-160h] BYREF
  int v16; // [sp+54h] [-15Ch]
  const char *v17; // [sp+58h] [-158h]
  idBreakableDecal v18; // [sp+60h] [-150h] BYREF
  idToken v19; // [sp+B0h] [-100h] BYREF
  const char *v20; // [sp+F8h] [-B8h]
  const char *v21; // [sp+FCh] [-B4h]
  const char *v22; // [sp+100h] [-B0h]

  idBreakableDecal::idBreakableDecal(this: &v18);
  numPieces = this->numPieces;
  v18.lifetime = 10000;
  v18.fadeOutStartTime = 2000;
  v18.minSize.x = 32.0;
  v18.fadeInEndTime = 0;
  v18.minSize.y = 32.0;
  v18.splatterOnBounce = false;
  v18.maxSize.x = 32.0;
  v18.splatterOnRest = false;
  v18.maxSize.y = 32.0;
  v18.minBounceVelocity = 10.0;
  v18.decalSpacing = 3000.0;
  v18.depth = 8.0;
  if ( numPieces == 0 )
    idParser::Warning(this: src, str: "no model specified\n");
  v17 = "{";
  if ( idParser::ExpectTokenString(this: src, string: "{") )
  {
    v19.len = 0;
    v19.baseBuffer[0] = 0;
    v19.intvalue = 0;
    v19.allocedAndFlag = 20;
    v19.data = v19.baseBuffer;
    memset(&v19.whiteSpaceStart_p, 0, 12);
    v19.floatvalue = -3.4028235e38;
    if ( idParser::ExpectAnyToken(this: src, token: &v19) == 0 )
    {
LABEL_52:
      idStr::FreeData(this: &v19);
      goto LABEL_84;
    }
    v20 = "minSizeX";
    v22 = "maxSizeY";
    v21 = "maxSizeX";
    while ( idStr::Cmp(s1: v19.data, s2: "}") != 0 )
    {
      if ( idStr::Icmp(s1: v19.data, s2: v21) != 0 )
      {
        if ( idStr::Icmp(s1: v19.data, s2: v22) != 0 )
        {
          if ( idStr::Icmp(s1: v19.data, s2: v20) != 0 )
          {
            if ( idStr::Icmp(s1: v19.data, s2: "minSizeY") != 0 )
            {
              if ( idStr::Icmp(s1: v19.data, s2: "lifetime") != 0 )
              {
                if ( idStr::Icmp(s1: v19.data, s2: "fadetime") != 0 )
                {
                  if ( idStr::Icmp(s1: v19.data, s2: "fadeInEndTime") != 0 )
                  {
                    if ( idStr::Icmp(s1: v19.data, s2: "decalSpacing") != 0 )
                    {
                      if ( idStr::Icmp(s1: v19.data, s2: "minBounceVelocity") != 0 )
                      {
                        if ( idStr::Icmp(s1: v19.data, s2: "splatterOnBounce") != 0 )
                        {
                          if ( idStr::Icmp(s1: v19.data, s2: "splatterOnRest") != 0 )
                          {
                            if ( idStr::Icmp(s1: v19.data, s2: "depth") != 0 )
                            {
                              if ( idStr::Icmp(s1: v19.data, s2: "materials") != 0 )
                              {
                                if ( idStr::Icmp(s1: v19.data, s2: "pieces") != 0 )
                                {
                                  idParser::Warning(this: src, str: "Bad token '%s'\n", v19.data);
                                  idStr::FreeData(this: &v19);
                                  goto LABEL_84;
                                }
                                idParser::ExpectTokenString(this: src, string: v17);
                                while ( idParser::ReadToken(this: src, token: &v19) )
                                {
                                  if ( idStr::Cmp(s1: v19.data, s2: "}") == 0 )
                                    break;
                                  if ( idStr::Cmp(s1: v19.data, s2: "all") != 0 )
                                  {
                                    UnsignedIntValue = idToken::GetUnsignedIntValue(this: &v19);
                                    if ( UnsignedIntValue < 1 || UnsignedIntValue > this->numPieces )
                                    {
                                      idParser::Warning(
                                        this: src,
                                        str: "pieces { } number %d out of range\n",
                                        UnsignedIntValue);
                                    }
                                    else
                                    {
                                      v15 = (const idDecl *)(UnsignedIntValue - 1);
                                      idList<idAnimWebBlendTree *,5>::Append(
                                        this: (idList<enum encounterGroupRole_t,5> *)&v18.pieces,
                                        obj: (const encounterGroupRole_t *)&v15);
                                    }
                                  }
                                  else
                                  {
                                    idList<idObstacleBuffers *,5>::SetNum(
                                      this: (idList<int,37> *)&v18.pieces,
                                      newNum: 0);
                                  }
                                }
                              }
                              else
                              {
                                idParser::ExpectTokenString(this: src, string: v17);
                                if ( idParser::ReadToken(this: src, token: &v19) )
                                {
                                  while ( idStr::Cmp(s1: v19.data, s2: "}") != 0 )
                                  {
                                    if ( v19.data != nullptr )
                                      v6 = idDeclInfo::FindWithInheritance(
                                             this: &idMaterial::resourceList,
                                             name: v19.data,
                                             makeDefault: false);
                                    else
                                      v6 = nullptr;
                                    v15 = v6;
                                    if ( v6 == nullptr )
                                    {
                                      idParser::Warning(this: src, str: "Problem finding all the decals.");
                                      idStr::FreeData(this: &v19);
                                      goto LABEL_84;
                                    }
                                    idList<idAnimWebBlendTree *,5>::Append(
                                      this: (idList<enum encounterGroupRole_t,5> *)&v18,
                                      obj: (const encounterGroupRole_t *)&v15);
                                    if ( !idParser::ReadToken(this: src, token: &v19) )
                                      break;
                                  }
                                }
                              }
                            }
                            else
                            {
                              v5 = idParser::ParseFloat(this: src, errorFlag: nullptr);
                              v18.depth = v5;
                              if ( v5 <= 0.1 )
                              {
                                idParser::Warning(this: src, str: "Decal depth is too small");
                                idStr::FreeData(this: &v19);
                                goto LABEL_84;
                              }
                            }
                          }
                          else
                          {
                            v18.splatterOnRest = idParser::ParseBool(this: src);
                          }
                        }
                        else
                        {
                          v18.splatterOnBounce = idParser::ParseBool(this: src);
                        }
                      }
                      else
                      {
                        v18.minBounceVelocity = idParser::ParseFloat(this: src, errorFlag: nullptr);
                      }
                    }
                    else
                    {
                      v18.decalSpacing = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    }
                  }
                  else
                  {
                    v16 = (int)(float)(idParser::ParseFloat(this: src, errorFlag: nullptr) * 1000.0);
                    v18.fadeInEndTime = v16;
                  }
                }
                else
                {
                  v16 = (int)(float)(idParser::ParseFloat(this: src, errorFlag: nullptr) * 1000.0);
                  v18.fadeOutStartTime = v16;
                }
              }
              else
              {
                v16 = (int)(float)(idParser::ParseFloat(this: src, errorFlag: nullptr) * 1000.0);
                v18.lifetime = v16;
              }
            }
            else
            {
              v18.minSize.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
            }
          }
          else
          {
            v18.minSize.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
          }
        }
        else
        {
          v18.maxSize.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
        }
      }
      else
      {
        v18.maxSize.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
      }
      if ( idParser::ExpectAnyToken(this: src, token: &v19) == 0 )
        goto LABEL_52;
    }
    x = v18.maxSize.x;
    if ( v18.maxSize.x < (double)v18.minSize.x )
    {
      v18.maxSize.x = v18.minSize.x;
      x = v18.minSize.x;
    }
    y = v18.maxSize.y;
    if ( v18.maxSize.y < (double)v18.minSize.y )
    {
      v18.maxSize.y = v18.minSize.y;
      y = v18.minSize.y;
    }
    if ( x > 4.0 && y > 4.0 )
    {
      if ( v18.materials.num == 0 )
      {
        idParser::Warning(this: src, str: "No valid materials found");
        idStr::FreeData(this: &v19);
        goto LABEL_84;
      }
      if ( v18.pieces.num != 0 )
      {
        v10 = this;
LABEL_72:
        idList<idBreakableDecal,59>::Append(this: &v10->decals, obj: (const idList<idMD6Node *,5> *)&v18);
        idStr::FreeData(this: &v19);
        goto LABEL_84;
      }
      v10 = this;
      size = v18.pieces.size;
      v12 = this->numPieces;
      if ( v12 > v18.pieces.size )
      {
        if ( !idList<idNavSpline *,5>::Resize(
                this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v18.pieces,
                newsize: this->numPieces) )
        {
LABEL_67:
          v13 = 0;
          if ( this->numPieces > 0 )
          {
            v14 = 0;
            do
              v18.pieces.list[v14++] = v13++;
            while ( v13 < this->numPieces );
          }
          goto LABEL_72;
        }
        size = v18.pieces.size;
      }
      v18.pieces.num = v12;
      if ( v12 >= size )
        v18.pieces.num = size;
      goto LABEL_67;
    }
    idParser::Warning(this: src, str: "Decals have bad sizes");
    idStr::FreeData(this: &v19);
    if ( v18.pieces.listStatic == 0 || v18.pieces.listStatic == 2 )
    {
      if ( v18.pieces.list != nullptr )
        idMem::Free(this: &mem, ptr: v18.pieces.list, align: ALIGN_16);
      v18.pieces.list = nullptr;
      v18.pieces.size = 0;
    }
    v18.pieces.num = 0;
    if ( (v18.materials.listStatic == 0 || v18.materials.listStatic == 2) && v18.materials.list != nullptr )
      idMem::Free(this: &mem, ptr: v18.materials.list, align: ALIGN_16);
  }
  else
  {
LABEL_84:
    idBreakableDecal::~idBreakableDecal(this: &v18);
  }
}


// ========================================================================
// __unwind$226363
// EA  : 0x82617740
// RVA : 0x00617740
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_226363()
{
  int v0; // r12

  idBreakableDecal::~idBreakableDecal(this: (idBreakableDecal *)(v0 - 432 + 96));
}


// ========================================================================
// __unwind$226364
// EA  : 0x82617768
// RVA : 0x00617768
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_226364()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 176));
}


// ========================================================================
// __unwind$226555
// EA  : 0x82617790
// RVA : 0x00617790
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_226555()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 96));
}


// ========================================================================
// ?ParsePieceDecal@idDeclBreakable@@AAAXAAVidParser@@@Z
// EA  : 0x826177C0
// RVA : 0x006177C0
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall idDeclBreakable::ParsePieceDecal(idDeclBreakable *this, idParser *src)
{
  char *data; // r4
  const idMaterial *v5; // r3
  unsigned int intvalue; // r11
  unsigned int v7; // [sp+50h] [-D0h] BYREF
  idToken v8; // [sp+60h] [-C0h] BYREF
  idBreakablePieceDecal v9; // [sp+B0h] [-70h] BYREF

  if ( idParser::ExpectTokenString(this: src, string: "{") )
  {
    memset(&v9.affectedPieces, 0, 14);
    v9.affectedPieces.memTag = 5;
    v9.affectedPieces.listStatic = 0;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v9.affectedPieces);
    v8.len = 0;
    v8.baseBuffer[0] = 0;
    v8.allocedAndFlag = 20;
    v8.data = v8.baseBuffer;
    v8.intvalue = 0;
    v8.floatvalue = -3.4028235e38;
    memset(&v8.whiteSpaceStart_p, 0, 12);
    idParser::ReadToken(this: src, token: &v8);
    data = v8.data;
    if ( v8.data != nullptr )
    {
      v5 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                 this: &idMaterial::resourceList,
                                 name: v8.data,
                                 makeDefault: false);
      data = v8.data;
    }
    else
    {
      v5 = nullptr;
    }
    v9.material = v5;
    if ( v5 == nullptr )
      idParser::Error(this: src, str: "Could not find material '%s' for breakable '%s'.", data, this->name.str);
    idParser::Parse1DMatrix(this: src, x: 2, m: &v9.size.x);
    v9.depth = idParser::ParseFloat(this: src, errorFlag: nullptr);
    v9.angle = idParser::ParseFloat(this: src, errorFlag: nullptr);
    idParser::Parse1DMatrix(this: src, x: 3, m: &v9.position.x);
    idParser::Parse1DMatrix(this: src, x: 3, m: &v9.direction.x);
    if ( !idParser::ExpectTokenString(this: src, string: "{") )
      idParser::Error(this: src, str: "Bad Parsing");
    if ( idParser::ExpectAnyToken(this: src, token: &v8) != 0 )
    {
      while ( idStr::Cmp(s1: v8.data, s2: "}") != 0 )
      {
        if ( v8.type == 3 )
        {
          if ( (v8.subtype & 0x10000) == 0 )
            idToken::NumberValue(this: &v8);
          intvalue = v8.intvalue;
        }
        else
        {
          intvalue = 0;
        }
        v7 = intvalue;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&v9.affectedPieces,
          obj: (const encounterGroupRole_t *)&v7);
        if ( idParser::ExpectAnyToken(this: src, token: &v8) == 0 )
          goto LABEL_17;
      }
      idParser::ExpectTokenString(this: src, string: "}");
      idList<idBreakablePieceDecal,5>::Append(this: &this->pieceDecals, obj: &v9);
      idStr::FreeData(this: &v8);
    }
    else
    {
LABEL_17:
      idStr::FreeData(this: &v8);
    }
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v9.affectedPieces);
  }
}


// ========================================================================
// __unwind$226788
// EA  : 0x826179E4
// RVA : 0x006179E4
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_226788()
{
  int v0; // r12

  idBreakablePieceDecal::~idBreakablePieceDecal(this: (idBreakablePieceDecal *)(v0 - 288 + 176));
}


// ========================================================================
// __unwind$226789
// EA  : 0x82617A0C
// RVA : 0x00617A0C
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_226789()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// ?Parse@idDeclBreakable@@UAAXAAVidParser@@@Z
// EA  : 0x82617A40
// RVA : 0x00617A40
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void __fastcall idDeclBreakable::Parse(idDeclBreakable *this, idParser *src)
{
  idResource *v3; // r3
  char *str; // r11
  char v5; // r11
  bool v6; // zf
  idToken v7; // [sp+70h] [-120h] BYREF
  const char *v8; // [sp+B8h] [-D8h]
  const char *v9; // [sp+BCh] [-D4h]
  const char *v10; // [sp+C0h] [-D0h]
  const char *v11; // [sp+C4h] [-CCh]
  const char *v12; // [sp+C8h] [-C8h]
  const char *v13; // [sp+CCh] [-C4h]
  const char *v14; // [sp+D0h] [-C0h]
  const char *v15; // [sp+D4h] [-BCh]
  const char *v16; // [sp+D8h] [-B8h]
  const char *v17; // [sp+DCh] [-B4h]
  const char *v18; // [sp+E0h] [-B0h]
  const char *v19; // [sp+E4h] [-ACh]
  const char *v20; // [sp+E8h] [-A8h]
  const char *v21; // [sp+ECh] [-A4h]

  v7.len = 0;
  v7.allocedAndFlag = 20;
  v7.data = v7.baseBuffer;
  v7.floatvalue = -3.4028235e38;
  v7.baseBuffer[0] = 0;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  idDeclBreakable::Clear(this);
  if ( idParser::ExpectAnyToken(this: src, token: &v7) != 0 )
  {
    v19 = "pieceDecal";
    v15 = (const char *)-2113343024;
    v17 = (const char *)-2112123584;
    v13 = (const char *)-2112148604;
    v11 = (const char *)-2113349912;
    v9 = (const char *)-2113349896;
    v18 = (const char *)-2112850488;
    v14 = "bouncyness";
    v20 = "angularFrictionWater";
    v8 = "linearFrictionWater";
    v16 = "contactFriction";
    v10 = "angularFriction";
    v21 = "impactSoundTable";
    v12 = "harmlessParticle";
    while ( idStr::Cmp(s1: v7.data, s2: "}") != 0 )
    {
      if ( idStr::Icmp(s1: v7.data, s2: "model") != 0 )
      {
        if ( idStr::Icmp(s1: v7.data, s2: "linearFriction") != 0 )
        {
          if ( idStr::Icmp(s1: v7.data, s2: "impactParticle") != 0 )
          {
            if ( idStr::Icmp(s1: v7.data, s2: "deathParticle") != 0 )
            {
              if ( idStr::Icmp(s1: v7.data, s2: v12) != 0 )
              {
                if ( idStr::Icmp(s1: v7.data, s2: v21) != 0 )
                {
                  if ( idStr::Icmp(s1: v7.data, s2: v10) != 0 )
                  {
                    if ( idStr::Icmp(s1: v7.data, s2: v16) != 0 )
                    {
                      if ( idStr::Icmp(s1: v7.data, s2: v8) != 0 )
                      {
                        if ( idStr::Icmp(s1: v7.data, s2: v20) != 0 )
                        {
                          if ( idStr::Icmp(s1: v7.data, s2: v14) != 0 )
                          {
                            if ( idStr::Icmp(s1: v7.data, s2: "dampeningDecay") != 0 )
                            {
                              if ( idStr::Icmp(s1: v7.data, s2: "gravity") != 0 )
                              {
                                if ( idStr::Icmp(s1: v7.data, s2: "worldCollisionOnly") != 0 )
                                {
                                  if ( idStr::Icmp(s1: v7.data, s2: "simplePointCollision") != 0 )
                                  {
                                    if ( idStr::Icmp(s1: v7.data, s2: "crazyBounceChance") != 0 )
                                    {
                                      if ( idStr::Icmp(s1: v7.data, s2: "maxSimulationTime") != 0 )
                                      {
                                        if ( idStr::Icmp(s1: v7.data, s2: "stopSpeed") != 0 )
                                        {
                                          if ( idStr::Icmp(s1: v7.data, s2: "maxLinearVelocity") != 0 )
                                          {
                                            if ( idStr::Icmp(s1: v7.data, s2: "maxAngularVelocity") != 0 )
                                            {
                                              if ( idStr::Icmp(s1: v7.data, s2: "noShadows") != 0 )
                                              {
                                                if ( idStr::Icmp(s1: v7.data, s2: "explosion") != 0 )
                                                {
                                                  if ( idStr::Icmp(s1: v7.data, s2: v18) != 0 )
                                                  {
                                                    if ( idStr::Icmp(s1: v7.data, s2: v9) != 0 )
                                                    {
                                                      if ( idStr::Icmp(s1: v7.data, s2: v11) != 0 )
                                                      {
                                                        if ( idStr::Icmp(s1: v7.data, s2: v13) != 0 )
                                                        {
                                                          if ( idStr::Icmp(s1: v7.data, s2: v15) != 0 )
                                                          {
                                                            if ( idStr::Icmp(s1: v7.data, s2: v17) != 0 )
                                                            {
                                                              if ( idStr::Icmp(s1: v7.data, s2: v19) != 0 )
                                                              {
                                                                idParser::Warning(
                                                                  this: src,
                                                                  str: "Bad token '%s'\n",
                                                                  v7.data);
                                                                goto _M227299;
                                                              }
                                                              idDeclBreakable::ParsePieceDecal(this, src);
                                                            }
                                                            else
                                                            {
                                                              idDeclBreakable::ParseSpark(this, src);
                                                            }
                                                          }
                                                          else
                                                          {
                                                            idDeclBreakable::ParseContents(
                                                              this,
                                                              src,
                                                              c: &this->settings.clipMask);
                                                          }
                                                        }
                                                        else
                                                        {
                                                          idDeclBreakable::ParseDecals(this, src);
                                                        }
                                                      }
                                                      else
                                                      {
                                                        idDeclBreakable::ParseHealthPieces(this, src);
                                                      }
                                                    }
                                                    else
                                                    {
                                                      idDeclBreakable::ParseArmoredPieces(this, src);
                                                    }
                                                  }
                                                  else
                                                  {
                                                    idDeclBreakable::ParseTrail(this, src);
                                                  }
                                                }
                                                else
                                                {
                                                  idDeclBreakable::ParseExplosion(this, src);
                                                }
                                              }
                                              else
                                              {
                                                this->settings.noShadows = idParser::ParseBool(this: src);
                                              }
                                            }
                                            else
                                            {
                                              this->settings.maxAngularVelocity = idParser::ParseFloat(
                                                                                    this: src,
                                                                                    errorFlag: nullptr);
                                            }
                                          }
                                          else
                                          {
                                            this->settings.maxLinearVelocity = idParser::ParseFloat(
                                                                                 this: src,
                                                                                 errorFlag: nullptr);
                                          }
                                        }
                                        else
                                        {
                                          this->settings.stopSpeed = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                        }
                                      }
                                      else
                                      {
                                        this->settings.maxSimulationTime = idParser::ParseFloat(
                                                                             this: src,
                                                                             errorFlag: nullptr);
                                      }
                                    }
                                    else
                                    {
                                      this->settings.crazyBounceChance = idParser::ParseFloat(
                                                                           this: src,
                                                                           errorFlag: nullptr);
                                    }
                                  }
                                  else
                                  {
                                    this->settings.simplePointCollision = idParser::ParseBool(this: src);
                                  }
                                }
                                else
                                {
                                  this->settings.worldCollisionOnly = idParser::ParseBool(this: src);
                                }
                              }
                              else
                              {
                                this->settings.gravityVector.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                this->settings.gravityVector.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                this->settings.gravityVector.z = idParser::ParseFloat(this: src, errorFlag: nullptr);
                              }
                            }
                            else
                            {
                              this->settings.dampeningDecay = idParser::ParseFloat(this: src, errorFlag: nullptr);
                            }
                          }
                          else
                          {
                            this->settings.bouncyness = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          }
                        }
                        else
                        {
                          this->settings.angularFrictionWater = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        }
                      }
                      else
                      {
                        this->settings.linearFrictionWater = idParser::ParseFloat(this: src, errorFlag: nullptr);
                      }
                    }
                    else
                    {
                      this->settings.contactFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    }
                  }
                  else
                  {
                    this->settings.angularFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  idParser::ReadToken(this: src, token: &v7);
                  if ( v7.data != nullptr )
                    idDeclInfo::FindWithInheritance(
                      this: &idDeclImpactSound::resourceList,
                      name: v7.data,
                      makeDefault: false);
                }
              }
              else
              {
                idParser::ReadToken(this: src, token: &v7);
                if ( v7.data != nullptr )
                  this->settings.harmlessParticle = (const idDeclParticle *)idDeclInfo::FindWithInheritance(
                                                                              this: &idDeclParticle::resourceList,
                                                                              name: v7.data,
                                                                              makeDefault: false);
                else
                  this->settings.harmlessParticle = nullptr;
              }
            }
            else
            {
              idParser::ReadToken(this: src, token: &v7);
              if ( v7.data != nullptr )
                this->settings.deathParticle = (const idDeclParticle *)idDeclInfo::FindWithInheritance(
                                                                         this: &idDeclParticle::resourceList,
                                                                         name: v7.data,
                                                                         makeDefault: false);
              else
                this->settings.deathParticle = nullptr;
            }
          }
          else
          {
            idParser::ReadToken(this: src, token: &v7);
            if ( v7.data != nullptr )
              this->settings.impactParticle = (const idDeclParticle *)idDeclInfo::FindWithInheritance(
                                                                        this: &idDeclParticle::resourceList,
                                                                        name: v7.data,
                                                                        makeDefault: false);
            else
              this->settings.impactParticle = nullptr;
          }
        }
        else
        {
          this->settings.linearFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
        }
      }
      else
      {
        idParser::ExpectAnyToken(this: src, token: &v7);
        idAtomicString::Set(this: &this->modelName, str_: v7.data);
        v3 = idResourceList::Load(
               this: &idDiscreteAnimationModelData::resourceList,
               name: this->modelName.str,
               makeDefault: true,
               skipStaleCheck: false);
        if ( v3->resourceError != nullptr )
        {
          ((void (__fastcall *)(idResource *, int))v3->dtr_idResource)(a1: v3, a2: 1);
          this->numPieces = 0;
        }
        else
        {
          this->numPieces = (int)v3[2].resourceError;
        }
        declManager->AddDependency(this: declManager, a2: (idDecl *)this, a3: this->modelName.str);
      }
      if ( idParser::ExpectAnyToken(this: src, token: &v7) == 0 )
        goto _M227299;
    }
    str = (char *)this->modelName.str;
    if ( str == &byte_8200D768 || (v6 = *str != 0, v5 = 0, !v6) )
      v5 = 1;
    if ( v5 != 0 )
      idParser::Warning(this: src, str: "No model specified for breakable\n");
  }
_M227299:
  idStr::FreeData(this: &v7);
}


// ========================================================================
// __unwind$226972
// EA  : 0x82618250
// RVA : 0x00618250
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

void _unwind_226972()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 112));
}


// ========================================================================
// `dynamic initializer for 'GenerateBreakableDecalInfo_v''
// EA  : 0x833365B8
// RVA : 0x013365B8
// PDB : w:\tech5\engine\decls\declbreakable.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__GenerateBreakableDecalInfo_v__()
{
  return idCommandLink::idCommandLink(
           this: &GenerateBreakableDecalInfo_v,
           cmdName: "GenerateBreakableDecalInfo",
           function: GenerateBreakableDecalInfo_f,
           description: "Generates decal data for a breakable",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclBreakable>);
}

