
// ========================================================================
// ?CreateNewStage@idDeclParticle@@QAAPAVidParticleStage@@XZ
// EA  : 0x827DDEF8
// RVA : 0x007DDEF8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

idParticleStage *__fastcall idDeclParticle::CreateNewStage(idDeclParticle *this)
{
  idParticleStage *v1; // r3

  v1 = (idParticleStage *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\models\\particles\\DeclParticle.cpp(1186) : TAG_PARTICLE",
                            size: 0x4ECu,
                            tag: TAG_PARTICLE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idParticleStage::idParticleStage(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$221784
// EA  : 0x827DDF64
// RVA : 0x007DDF64
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_221784()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 112 + 84));
}


// ========================================================================
// ?DefaultDefinition@idDeclParticle@@UBAPBDXZ
// EA  : 0x827DDF90
// RVA : 0x007DDF90
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

const char *__fastcall idDeclParticle::DefaultDefinition(idDeclParticle *this)
{
  return "{\n"
         "\t{\n"
         "\t\tmaterial\ttextures/particles/default\n"
         "\t\tcount\t\t5\n"
         "\t\ttime\t\tconstant 1.0\n"
         "\t\tspeedZ\t\tparametricIntegrate \"150.000\"\n"
         "\t}\n"
         "}\n";
}


// ========================================================================
// ?ParticleDistributionNameToType@@YAHABVidStr@@@Z
// EA  : 0x827DE2D8
// RVA : 0x007DE2D8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall ParticleDistributionNameToType(const idStr *text)
{
  int v2; // r30
  const particleParmDesc_t *v3; // r31

  v2 = 0;
  v3 = particleDistributionDesc;
  while ( idStr::Icmp(s1: text->data, s2: v3->name) != 0 )
  {
    ++v3;
    ++v2;
    if ( (int)v3 >= (int)particleDirectionDesc )
      return -1;
  }
  return v2;
}


// ========================================================================
// ?ParticleDirectionNameToType@@YAHABVidStr@@@Z
// EA  : 0x827DE338
// RVA : 0x007DE338
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall ParticleDirectionNameToType(const idStr *text)
{
  int v2; // r30
  const particleParmDesc_t *v3; // r31

  v2 = 0;
  v3 = particleDirectionDesc;
  while ( idStr::Icmp(s1: text->data, s2: v3->name) != 0 )
  {
    ++v3;
    ++v2;
    if ( (int)v3 >= (int)particleCustomDesc )
      return -1;
  }
  return v2;
}


// ========================================================================
// ?ParticleOrientationNameToType@@YAHABVidStr@@@Z
// EA  : 0x827DE398
// RVA : 0x007DE398
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall ParticleOrientationNameToType(const idStr *text)
{
  int v2; // r30
  const particleParmDesc_t *v3; // r31

  v2 = 0;
  v3 = particleOrientationDesc;
  while ( idStr::Icmp(s1: text->data, s2: v3->name) != 0 )
  {
    ++v3;
    ++v2;
    if ( (int)v3 >= (int)particleTexFlipTypeDesc )
      return -1;
  }
  return v2;
}


// ========================================================================
// ?ParticleCustomNameToType@@YAHABVidStr@@@Z
// EA  : 0x827DE3F8
// RVA : 0x007DE3F8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall ParticleCustomNameToType(const idStr *text)
{
  int v2; // r30
  const particleParmDesc_t *v3; // r31

  v2 = 0;
  v3 = particleCustomDesc;
  while ( idStr::Icmp(s1: text->data, s2: v3->name) != 0 )
  {
    ++v3;
    ++v2;
    if ( (int)v3 >= (int)particleOrientationDesc )
      return -1;
  }
  return v2;
}


// ========================================================================
// ?ParticleTextureFlipNameToType@@YAHABVidStr@@@Z
// EA  : 0x827DE458
// RVA : 0x007DE458
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall ParticleTextureFlipNameToType(const idStr *text)
{
  int v2; // r30
  const particleParmDesc_t *v3; // r31

  v2 = 0;
  v3 = particleTexFlipTypeDesc;
  while ( idStr::Icmp(s1: text->data, s2: v3->name) != 0 )
  {
    ++v3;
    ++v2;
    if ( (int)v3 >= (int)particleAnimationTypeDesc )
      return -1;
  }
  return v2;
}


// ========================================================================
// ?ParticleAnimationNameToType@@YAHABVidStr@@@Z
// EA  : 0x827DE4B8
// RVA : 0x007DE4B8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall ParticleAnimationNameToType(const idStr *text)
{
  int v2; // r30
  const particleParmDesc_t *v3; // r31

  v2 = 0;
  v3 = particleAnimationTypeDesc;
  while ( idStr::Icmp(s1: text->data, s2: v3->name) != 0 )
  {
    ++v3;
    ++v2;
    if ( (int)v3 >= (int)particleSortTypeDesc )
      return -1;
  }
  return v2;
}


// ========================================================================
// ?ParticleSortNameToType@@YAHABVidStr@@@Z
// EA  : 0x827DE518
// RVA : 0x007DE518
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall ParticleSortNameToType(const idStr *text)
{
  int v2; // r30
  const particleParmDesc_t *v3; // r31

  v2 = 0;
  v3 = particleSortTypeDesc;
  while ( idStr::Icmp(s1: text->data, s2: v3->name) != 0 )
  {
    ++v3;
    ++v2;
    if ( (int)v3 >= (int)"w:\\tech5\\engine\\models\\particles\\DeclParticle.cpp(1186) : TAG_PARTICLE" )
      return -1;
  }
  return v2;
}


// ========================================================================
// ?ParseParms@idDeclParticle@@AAAXAAVidParser@@PAMH@Z
// EA  : 0x827DE580
// RVA : 0x007DE580
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void __fastcall idDeclParticle::ParseParms(idDeclParticle *this, idParser *src, float *parms, int maxParms)
{
  int v4; // r30
  float *v6; // r29
  long double v8; // fp2
  long double v9; // fp2
  idToken v10; // [sp+50h] [-80h] BYREF

  v4 = 0;
  v10.len = 0;
  v10.baseBuffer[0] = 0;
  v6 = parms;
  v10.floatvalue = -3.4028235e38;
  v10.intvalue = 0;
  memset(&v10.whiteSpaceStart_p, 0, 12);
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  memset(Dst: parms, Val: 0, Size: 4 * maxParms);
  if ( idParser::ReadTokenOnLine(this: src, token: &v10) != 0 )
  {
    while ( v4 != maxParms )
    {
      if ( v10.type != 5 || idStr::Cmp(s1: v10.data, s2: "-") != 0 )
      {
        idStr::StripQuotes(this: &v10);
        v9 = atof(nptr: v10.data);
        *v6 = *(double *)&v9;
      }
      else
      {
        idParser::ExpectTokenType(this: src, type: 3, subtype: 0, token: &v10);
        v8 = atof(nptr: v10.data);
        *v6 = -*(double *)&v8;
      }
      ++v4;
      ++v6;
      if ( idParser::ReadTokenOnLine(this: src, token: &v10) == 0 )
        goto LABEL_10;
    }
    idParser::Error(this: src, str: "too many parms on line");
  }
LABEL_10:
  idStr::FreeData(this: &v10);
}


// ========================================================================
// __unwind$223010
// EA  : 0x827DE6AC
// RVA : 0x007DE6AC
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_223010()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ParseBounds@@YAXAAVidParser@@AAVidBounds@@@Z
// EA  : 0x827DE6E0
// RVA : 0x007DE6E0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void __fastcall ParseBounds(idParser *src, idBounds *bounds)
{
  int v4; // r29
  float *v5; // r28
  long double v6; // fp2
  double v13; // fp11
  double v14; // fp10
  double v15; // fp9
  float v34[9]; // [sp+4Ch] [-C4h] BYREF
  idToken v35; // [sp+70h] [-A0h] BYREF

  v35.len = 0;
  bounds->b[0].x = 0.0;
  v35.baseBuffer[0] = 0;
  v35.floatvalue = -3.4028235e38;
  v35.intvalue = 0;
  bounds->b[1].z = 0.0;
  v35.whiteSpaceStart_p = nullptr;
  bounds->b[1].y = 0.0;
  v35.whiteSpaceEnd_p = nullptr;
  bounds->b[1].x = 0.0;
  v35.next = nullptr;
  bounds->b[0].z = 0.0;
  v35.allocedAndFlag = 20;
  bounds->b[0].y = 0.0;
  v35.data = v35.baseBuffer;
  v4 = 0;
  if ( idParser::ReadTokenOnLine(this: src, token: &v35) != 0 )
  {
    v5 = v34;
    while ( v4 != 6 )
    {
      idStr::StripQuotes(this: &v35);
      v6 = atof(nptr: v35.data);
      *++v5 = *(double *)&v6;
      ++v4;
      if ( idParser::ReadTokenOnLine(this: src, token: &v35) == 0 )
        goto LABEL_5;
    }
    idParser::Error(this: src, str: "ParseBounds: too many parms on line");
  }
  else
  {
LABEL_5:
    _FP7 = (float)(bounds->b[0].y - v34[2]);
    _FP4 = (float)(bounds->b[0].z - v34[3]);
    _FP2 = (float)(v34[1] - bounds->b[1].x);
    _FP31 = (float)(v34[2] - bounds->b[1].y);
    _FP29 = (float)(v34[3] - bounds->b[1].z);
    _FP28 = (float)(bounds->b[0].x - v34[1]);
    v13 = v34[5];
    v14 = v34[6];
    v15 = v34[4];
    __asm { fsel      f8, f7, f0, f8 }
    bounds->b[0].y = _FP8;
    __asm { fsel      f7, f4, f13, f6 }
    bounds->b[0].z = _FP7;
    __asm { fsel      f6, f2, f12, f5 }
    bounds->b[1].x = _FP6;
    __asm { fsel      f5, f31, f0, f3 }
    bounds->b[1].y = _FP5;
    __asm { fsel      f4, f29, f13, f1 }
    bounds->b[1].z = _FP4;
    __asm { fsel      f3, f28, f12, f30 }
    _FP2 = (float)((float)_FP8 - (float)v13);
    _FP1 = (float)((float)_FP7 - (float)v14);
    _FP0 = (float)((float)v15 - (float)_FP6);
    _FP13 = (float)((float)v13 - (float)_FP5);
    _FP12 = (float)((float)v14 - (float)_FP4);
    _FP31 = (float)((float)_FP3 - (float)v15);
    __asm { fsel      f8, f2, f11, f8 }
    bounds->b[0].y = _FP8;
    __asm { fsel      f7, f1, f10, f7 }
    bounds->b[0].z = _FP7;
    __asm { fsel      f6, f0, f9, f6 }
    bounds->b[1].x = _FP6;
    __asm { fsel      f5, f13, f11, f5 }
    bounds->b[1].y = _FP5;
    __asm { fsel      f4, f12, f10, f4 }
    bounds->b[1].z = _FP4;
    __asm { fsel      f3, f31, f9, f3 }
    bounds->b[0].x = _FP3;
  }
  idStr::FreeData(this: &v35);
}


// ========================================================================
// __unwind$223120
// EA  : 0x827DE894
// RVA : 0x007DE894
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_223120()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// ?WriteBounds@@YAXPAVidFile@@ABVidStr@@ABVidBounds@@@Z
// EA  : 0x827DE8C0
// RVA : 0x007DE8C0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void __fastcall WriteBounds(idFile *f, const idStr *varName, const idBounds *bounds)
{
  float x; // [sp+50h] [-40h]
  float y; // [sp+54h] [-3Ch]
  float z; // [sp+58h] [-38h]
  idVec3 v7; // 0:^60.12

  x = bounds->b[0].x;
  y = bounds->b[0].y;
  z = bounds->b[0].z;
  v7 = bounds->b[1];
  f->WriteFloatString(this: f, a2: "\t\t%s\t ", varName->data);
  f->WriteFloatString(
    this: f,
    a2: "\"%.3f\" \"%.3f\" \"%.3f\" ",
    (unsigned int)COERCE_UNSIGNED_INT64(x),
    (unsigned int)COERCE_UNSIGNED_INT64(y),
    (unsigned int)COERCE_UNSIGNED_INT64(z));
  f->WriteFloatString(
    this: f,
    a2: "\"%.3f\" \"%.3f\" \"%.3f\" ",
    (unsigned int)COERCE_UNSIGNED_INT64(v7.x),
    (unsigned int)COERCE_UNSIGNED_INT64(v7.y),
    (unsigned int)COERCE_UNSIGNED_INT64(v7.z));
  f->WriteFloatString(this: f, a2: "\n");
}


// ========================================================================
// ?FindStageByName@idDeclParticle@@QAAPAVidParticleStage@@PBD@Z
// EA  : 0x827DE9C8
// RVA : 0x007DE9C8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

idParticleStage *__fastcall idDeclParticle::FindStageByName(idDeclParticle *this, const char *name)
{
  int v4; // r29
  int i; // r31

  if ( name == nullptr )
    return nullptr;
  if ( *name == 0 )
    return nullptr;
  v4 = 0;
  if ( this->stageNames.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: this->stageNames.list[i].str, s2: name) != 0; ++i )
  {
    if ( ++v4 >= this->stageNames.num )
      return nullptr;
  }
  return this->stages.list[v4];
}


// ========================================================================
// ?CalcLodForDistance@idDeclParticle@@QBAHM@Z
// EA  : 0x827DEA50
// RVA : 0x007DEA50
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall idDeclParticle::CalcLodForDistance(
        idDeclParticle *this,
        double distSqr,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  int lodRadius; // r11
  int v9; // r11

  lodRadius = this->lodRadius;
  if ( lodRadius <= 0 )
    return 0;
  LODWORD(a8) = lodRadius * lodRadius;
  v9 = (int)(float)((float)distSqr / (float)a8);
  if ( v9 < 0 )
    return 3;
  if ( v9 > 3 )
    v9 = 3;
  return 3 - v9;
}


// ========================================================================
// ?GetTables@idDeclParticle@@QBAPBVidLookupTable@@XZ
// EA  : 0x827DEAB8
// RVA : 0x007DEAB8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

const idLookupTable *__fastcall idDeclParticle::GetTables(idDeclParticle *this)
{
  int v2; // r28
  int v3; // r30
  int v4; // r29

  v2 = 0;
  if ( this->tableDecls.num > 0 )
  {
    v3 = 0;
    v4 = 0;
    do
    {
      if ( (unsigned __int8)idDecl::SourceFileExists(this: &this->tableDecls.list[v3]->idDecl) != 0
        && idDecl::EverReloaded(this: &this->tableDecls.list[v3]->idDecl) )
      {
        memcpy(Dst: &this->tables.list[v4], Src: this->tableDecls.list[v3]->table, Size: sizeof(this->tables.list[v4]));
      }
      ++v2;
      ++v4;
      ++v3;
    }
    while ( v2 < this->tableDecls.num );
  }
  return this->tables.list;
}


// ========================================================================
// ?ParseParticleStage@idDeclParticle@@AAAPAVidParticleStage@@AAVidParser@@ABVidStr@@AAV4@@Z
// EA  : 0x827DEB58
// RVA : 0x007DEB58
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

idParticleStage *__fastcall idDeclParticle::ParseParticleStage(
        idDeclParticle *this,
        idParser *src,
        const idStr *stageName,
        idStr *inheritFrom,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10)
{
  idDeclParticle *v10; // r26
  idParticleStage *NewStage; // r30
  const idLookupTable *Tables; // r3
  __int128 v15; // r23
  const idStr *v16; // r28
  const idParticleStage *StageByName; // r3
  int len; // r28
  int v19; // r4
  unsigned int allocedAndFlag; // r11
  int v21; // r11
  bool v22; // zf
  const idMaterial *v23; // r3
  const idStaticParticleModelData *v24; // r3
  int v25; // r3
  int v26; // r3
  double v27; // fp0
  double v28; // fp13
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r6
  va *v32; // r3
  int v33; // r3
  double v34; // fp0
  double v35; // fp13
  int v36; // r3
  __int64 v37; // r10
  __int64 v38; // r8
  __int64 v39; // r6
  va *v40; // r3
  int v41; // r3
  prtOrientationType_t type; // r11
  long double v43; // fp2
  int v44; // r3
  unsigned __int16 v47; // r3
  unsigned __int16 v48; // r3
  int v49; // r3
  int v50; // r3
  int v51; // r3
  int v52; // r3
  int v53; // r3
  __int16 v54; // r11
  const idLookupTable *v55; // r3
  const idLookupTable *v56; // r3
  double MaxParmVal; // fp1
  double emissionTime; // fp13
  double maxParticleLife; // fp0
  const idStaticParticleModelData *staticData; // r10
  int numStaticVerts; // r11
  int v62; // r11
  int totalParticles; // r5
  int v64; // r11
  int v65; // r11
  signed int v66; // r11
  const char *str; // r4
  int v68; // r28
  int v69; // r11
  int v70; // r11
  int v71; // r5
  int v72; // r11
  int v73; // r11
  signed int v74; // r11
  const char *v75; // r4
  int v76; // r29
  int v78; // r10
  int v79; // r9
  int v80; // r8
  int v81; // r7
  int v82; // r6
  int v83; // r5
  int v84; // r4
  int v85; // r3
  int v86; // [sp+8h] [-1388h]
  int v87; // [sp+Ch] [-1384h]
  int v88; // [sp+10h] [-1380h]
  int v89; // [sp+14h] [-137Ch]
  int v90; // [sp+18h] [-1378h]
  int v91; // [sp+1Ch] [-1374h]
  idToken v92; // [sp+60h] [-1330h] BYREF
  const char *v93; // [sp+A8h] [-12E8h]
  const char *v94; // [sp+ACh] [-12E4h]
  const char *v95; // [sp+B0h] [-12E0h]
  const char *v96; // [sp+B4h] [-12DCh]
  const char *v97; // [sp+B8h] [-12D8h]
  const char *v98; // [sp+BCh] [-12D4h]
  const char *v99; // [sp+C0h] [-12D0h]
  const char *v100; // [sp+C4h] [-12CCh]
  const char *v101; // [sp+C8h] [-12C8h]
  const char *v102; // [sp+CCh] [-12C4h]
  const char *v103; // [sp+D0h] [-12C0h]
  int v104; // [sp+D4h] [-12BCh]
  const char *v105; // [sp+D8h] [-12B8h]
  int v106; // [sp+DCh] [-12B4h]
  const char *v107; // [sp+E0h] [-12B0h]
  int v108; // [sp+E4h] [-12ACh]
  const char *v109; // [sp+E8h] [-12A8h]
  const char *v110; // [sp+F0h] [-12A0h]
  int v111; // [sp+F4h] [-129Ch]
  int v112; // [sp+F8h] [-1298h]
  idParticleStage *v113; // [sp+FCh] [-1294h]
  const char *v114; // [sp+100h] [-1290h]
  const char *v115; // [sp+104h] [-128Ch]
  const char *v116; // [sp+108h] [-1288h]
  const char *v117; // [sp+10Ch] [-1284h]
  const char *v118; // [sp+110h] [-1280h]
  const char *v119; // [sp+114h] [-127Ch]
  const char *v120; // [sp+118h] [-1278h]
  const char *v121; // [sp+11Ch] [-1274h]
  const char *v122; // [sp+120h] [-1270h]
  const char *v123; // [sp+124h] [-126Ch]
  const char *v124; // [sp+128h] [-1268h]
  const char *v125; // [sp+12Ch] [-1264h]
  const char *v126; // [sp+130h] [-1260h]
  const char *v127; // [sp+134h] [-125Ch]
  const char *v128; // [sp+138h] [-1258h]
  const char *v129; // [sp+13Ch] [-1254h]
  const char *v130; // [sp+140h] [-1250h]
  const char *v131; // [sp+144h] [-124Ch]
  const char *v132; // [sp+148h] [-1248h]
  const char *v133; // [sp+14Ch] [-1244h]
  const char *v134; // [sp+150h] [-1240h]
  const char *v135; // [sp+154h] [-123Ch]
  const char *v136; // [sp+158h] [-1238h]
  const char *v137; // [sp+15Ch] [-1234h]
  const char *v138; // [sp+160h] [-1230h]
  const char *v139; // [sp+164h] [-122Ch]
  const char *v140; // [sp+168h] [-1228h]
  const char *v141; // [sp+16Ch] [-1224h]
  const char *v142; // [sp+170h] [-1220h]
  const char *v143; // [sp+174h] [-121Ch]
  const char *v144; // [sp+178h] [-1218h]
  const char *v145; // [sp+17Ch] [-1214h]
  const char *v146; // [sp+180h] [-1210h]
  const char *v147; // [sp+184h] [-120Ch]
  const char *v148; // [sp+188h] [-1208h]
  const char *v149; // [sp+18Ch] [-1204h]
  const char *v150; // [sp+190h] [-1200h]
  const char *v151; // [sp+194h] [-11FCh]
  const char *v152; // [sp+198h] [-11F8h]
  const char *v153; // [sp+19Ch] [-11F4h]
  const char *v154; // [sp+1A0h] [-11F0h]
  const char *v155; // [sp+1A4h] [-11ECh]
  const char *v156; // [sp+1A8h] [-11E8h]
  const char *v157; // [sp+1ACh] [-11E4h]
  const char *v158; // [sp+1B0h] [-11E0h]
  const char *v159; // [sp+1B4h] [-11DCh]
  const char *v160; // [sp+1B8h] [-11D8h]
  const char *v161; // [sp+1BCh] [-11D4h]
  const char *v162; // [sp+1C0h] [-11D0h]
  const char *v163; // [sp+1C4h] [-11CCh]
  const char *v164; // [sp+1C8h] [-11C8h]
  const char *v165; // [sp+1CCh] [-11C4h]
  const char *v166; // [sp+1D0h] [-11C0h]
  const char *v167; // [sp+1D4h] [-11BCh]
  const char *v168; // [sp+1D8h] [-11B8h]
  const char *v169; // [sp+1DCh] [-11B4h]
  const char *v170; // [sp+1E0h] [-11B0h]
  const char *v171; // [sp+1E4h] [-11ACh]
  const char *v172; // [sp+1E8h] [-11A8h]
  const char *v173; // [sp+1ECh] [-11A4h]
  const char *v174; // [sp+1F0h] [-11A0h]
  const char *v175; // [sp+1F4h] [-119Ch]
  const char *v176; // [sp+1F8h] [-1198h]
  const char *v177; // [sp+1FCh] [-1194h]
  const char *v178; // [sp+200h] [-1190h]
  int v179; // [sp+204h] [-118Ch]
  const char *v180; // [sp+208h] [-1188h]
  const char *v181; // [sp+20Ch] [-1184h]
  const char *v182; // [sp+210h] [-1180h]
  const char *v183; // [sp+214h] [-117Ch]
  const char *v184; // [sp+218h] [-1178h]
  const char *v185; // [sp+21Ch] [-1174h]
  const char *v186; // [sp+220h] [-1170h]
  const char *v187; // [sp+224h] [-116Ch]
  const char *v188; // [sp+228h] [-1168h]
  const char *v189; // [sp+22Ch] [-1164h]
  const char *v190; // [sp+230h] [-1160h]
  const char *v191; // [sp+234h] [-115Ch]
  const char *v192; // [sp+238h] [-1158h]
  const char *v193; // [sp+23Ch] [-1154h]
  const char *v194; // [sp+240h] [-1150h]
  const char *v195; // [sp+244h] [-114Ch]
  const char *v196; // [sp+248h] [-1148h]
  const char *v197; // [sp+24Ch] [-1144h]
  const char *v198; // [sp+250h] [-1140h]
  const char *v199; // [sp+254h] [-113Ch]
  const char *v200; // [sp+258h] [-1138h]
  const char *v201; // [sp+25Ch] [-1134h]
  const char *v202; // [sp+260h] [-1130h]
  const char *v203; // [sp+264h] [-112Ch]
  const char *v204; // [sp+268h] [-1128h]
  const char *v205; // [sp+26Ch] [-1124h]
  float v206[4]; // [sp+270h] [-1120h] BYREF
  _QWORD v207[4]; // [sp+280h] [-1110h] BYREF
  unsigned __int64 v208; // [sp+2A0h] [-10F0h]
  unsigned __int64 v209; // [sp+2A8h] [-10E8h]
  unsigned __int64 v210; // [sp+2B0h] [-10E0h]
  idAngles v211[4]; // [sp+2C0h] [-10D0h] BYREF
  va v212; // [sp+2F0h] [-10A0h] BYREF

  v10 = this;
  NewStage = idDeclParticle::CreateNewStage(this);
  v113 = NewStage;
  idStr::EnsureAlloced(this: inheritFrom, amount: 1, keepold: true, geometricGrowth: false);
  *inheritFrom->data = 0;
  inheritFrom->len = 0;
  Tables = idDeclParticle::GetTables(this: v10);
  idParticleStage::Default(this: NewStage, tables: Tables);
  v92.len = 0;
  v92.baseBuffer[0] = 0;
  v92.allocedAndFlag = 20;
  v92.data = v92.baseBuffer;
  v112 = 0;
  v92.floatvalue = -3.4028235e38;
  v92.intvalue = 0;
  memset(&v92.whiteSpaceStart_p, 0, 12);
  if ( !idParser::HadError(this: src) )
  {
    v202 = "w:\\tech5\\shared\\idlib\\text/Str.h";
    v157 = "animationStartFrame";
    v155 = "useRndStartFrame";
    v153 = "animationRate";
    v188 = "lodScale";
    v154 = "amount <= GetAlloced()";
    v194 = "unknown token %s\n";
    v192 = "lodRadius";
    v190 = "lodLerpAmount";
    v186 = "lodCount";
    v184 = "bad sort type: %s\n";
    v182 = "sortType";
    v171 = "allowRotDirOverride";
    v180 = "windBias";
    v177 = "gravity";
    v175 = "randomOnCycle";
    v173 = "boundsExpansion";
    v151 = "%s: particle filmstrip has exceeded max row frames %d with %d frames, capping frames\n";
    v169 = "rndFlipTexT";
    v114 = "bad texture flip mode type: %s\n";
    v167 = "rndFlipTexS";
    v165 = "skipAnimCrossFade";
    v163 = "bad animation type: %s\n";
    v161 = "animationType";
    v159 = "useRndAnimRow";
    v125 = "genericParmA";
    v149 = "animationRows";
    v129 = "colorR";
    v147 = "%s: particle filmstrip has exceeded max column frames %d with %d frames, capping frames\n";
    v127 = "useGlobalShadows";
    v145 = "animationFrames";
    v123 = "genericParmB";
    v143 = "offsetZ";
    v141 = "offsetY";
    v139 = "offsetX";
    v137 = "fadeColor";
    v135 = "colorA";
    v133 = "colorB";
    v131 = "colorG";
    v179 = -2111832064;
    v164 = (const char *)-2113383528;
    v162 = (const char *)-2111824756;
    v121 = "genericParmG";
    v116 = (const char *)-2113383584;
    v119 = (const char *)-2111824712;
    v117 = (const char *)-2113334572;
    v204 = (const char *)-2113844384;
    v160 = (const char *)-2113605664;
    v187 = (const char *)-2111824764;
    v158 = (const char *)-2111824772;
    v115 = (const char *)-2111824804;
    v205 = (const char *)-2111824816;
    v152 = (const char *)-2111824828;
    v183 = "spawnLocX";
    v148 = "angleX";
    v189 = (const char *)-2113383336;
    v200 = (const char *)-2111824780;
    v156 = (const char *)-2111824788;
    v185 = (const char *)-2111824796;
    v150 = "angleZ";
    v198 = "angleY";
    v181 = "rotationSpeedZ";
    v146 = "rotationSpeedY";
    v136 = "speedY";
    v174 = "speedX";
    v199 = "customPathParm3";
    v134 = "customPathParm4";
    v172 = "customPathParm1";
    v132 = "customPathParm2";
    v203 = "rotationSpeedX";
    v130 = "customPathParm0";
    v193 = "bad custom path type: %s\n";
    v128 = "customPathType";
    v144 = "frictionZ";
    v178 = "frictionY";
    v142 = (const char *)-2111824948;
    v201 = "accelerationZ";
    v140 = "accelerationY";
    v176 = "accelerationX";
    v138 = "worldAcceleration";
    v195 = "speedZ";
    HIDWORD(v15) = -2111832064;
    *(_QWORD *)((char *)&v15 + 4) = 0x8220000082200000uLL;
    LODWORD(v15) = -2111832064;
    v104 = -2113601536;
    v208 = 0x8206000083720000uLL;
    v209 = 0x8220000082200000uLL;
    *(_OWORD *)&v207[2] = v15;
    v210 = 0x8220000082200000uLL;
    v106 = -2111832064;
    v108 = -2111832064;
    v111 = -2113601536;
    v168 = (const char *)-2113381908;
    v170 = "bad orientation type: %s\n";
    v126 = (const char *)-2111825240;
    v197 = (const char *)-2113382364;
    v124 = (const char *)-2113382072;
    v122 = (const char *)-2113382288;
    v191 = (const char *)-2113382196;
    v120 = (const char *)-2113381956;
    v166 = (const char *)-2113382004;
    v101 = (const char *)-2113321952;
    v118 = (const char *)-2111825272;
    v196 = (const char *)-2113375584;
    v100 = (const char *)-2111825344;
    v95 = (const char *)-2113382592;
    v99 = (const char *)-2113382536;
    v98 = "randomDistribution";
    v102 = "deadTime";
    v110 = "count";
    v105 = "cycles";
    v107 = "time";
    v94 = "timeOffset";
    v10 = this;
    NewStage = v113;
    v96 = "emissionTime";
    v93 = "useSysTime";
    v97 = "diversity";
    v16 = stageName;
    v103 = (const char *)-2113536000;
    v109 = "inherit";
    v113 = (idParticleStage *)"}";
    do
    {
      if ( !idParser::ReadToken(this: src, token: &v92) || idStr::Icmp(s1: v92.data, s2: (const char *)v113) == 0 )
        break;
      if ( idStr::Icmp(s1: v92.data, s2: v109) != 0 )
      {
        ++v112;
        if ( idStr::Icmp(s1: v92.data, s2: "material") == 0 )
        {
          idParser::ReadToken(this: src, token: &v92);
          if ( v92.data != nullptr )
          {
            v23 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                        this: &idMaterial::resourceList,
                                        name: v92.data,
                                        makeDefault: true);
            idParticleStage::SetMaterial(this: NewStage, mtr: v23);
          }
          else
          {
            idParticleStage::SetMaterial(this: NewStage, mtr: nullptr);
          }
          continue;
        }
        if ( idStr::Icmp(s1: v92.data, s2: "staticMesh") != 0 )
        {
          if ( idStr::Icmp(s1: v92.data, s2: v103) != 0 )
          {
            if ( idStr::Icmp(s1: v92.data, s2: v110) != 0 )
            {
              if ( idStr::Icmp(s1: v92.data, s2: v107) != 0 )
              {
                if ( idStr::Icmp(s1: v92.data, s2: v105) != 0 )
                {
                  if ( idStr::Icmp(s1: v92.data, s2: v94) != 0 )
                  {
                    if ( idStr::Icmp(s1: v92.data, s2: v97) != 0 )
                    {
                      if ( idStr::Icmp(s1: v92.data, s2: v93) != 0 )
                      {
                        if ( idStr::Icmp(s1: v92.data, s2: v96) != 0 )
                        {
                          if ( idStr::Icmp(s1: v92.data, s2: v102) != 0 )
                          {
                            if ( idStr::Icmp(s1: v92.data, s2: v98) != 0 )
                            {
                              if ( idStr::Icmp(s1: v92.data, s2: "bunching") != 0 )
                              {
                                if ( idStr::Icmp(s1: v92.data, s2: "distributionType") == 0 )
                                {
                                  idParser::ReadToken(this: src, token: &v92);
                                  v25 = ParticleDistributionNameToType(text: &v92);
                                  if ( v25 >= 0 )
                                    NewStage->distribution.type = v25;
                                  else
                                    idParser::Error(this: src, str: "bad distribution type: %s\n", v92.data);
                                  continue;
                                }
                                if ( idStr::Icmp(s1: v92.data, s2: "distribSizeX") != 0 )
                                {
                                  if ( idStr::Icmp(s1: v92.data, s2: "distribSizeY") != 0 )
                                  {
                                    if ( idStr::Icmp(s1: v92.data, s2: "distribSizeZ") != 0 )
                                    {
                                      if ( idStr::Icmp(s1: v92.data, s2: "frictionTime") == 0 )
                                      {
                                        if ( idParser::PeekTokenType(this: src, type: 5, subtype: 46, token: &v92) != 0 )
                                        {
                                          idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v92);
                                          while ( idParser::ReadToken(this: src, token: &v92) )
                                          {
                                            if ( v92.type == 5 && v92.subtype == 47 )
                                              break;
                                            if ( idStr::Icmp(s1: v92.data, s2: "type") != 0 )
                                            {
                                              if ( idStr::Icmp(s1: v92.data, s2: "parms") != 0 )
                                              {
                                                if ( idStr::Icmp(s1: v92.data, s2: v99) != 0 )
                                                {
                                                  if ( idStr::Icmp(s1: v92.data, s2: v95) != 0 )
                                                  {
                                                    HIDWORD(v30) = this->name.str;
                                                    LODWORD(v31) = v16->data;
                                                    HIDWORD(v31) = v92.data;
                                                    v32 = va::va(
                                                            this: &v212,
                                                            fmt: v100,
                                                            a3: v31,
                                                            a4: v30,
                                                            a5: v29,
                                                            a6: v86,
                                                            a7: v87,
                                                            a8: v88,
                                                            a9: v89,
                                                            a10: v90,
                                                            a11: v91);
                                                    idParser::Error(this: src, str: v32->buffer);
                                                  }
                                                  else
                                                  {
                                                    idDeclParticle::ParseParms(
                                                      this,
                                                      src,
                                                      parms: NewStage->direction.angleOffsetRange,
                                                      maxParms: 2);
                                                  }
                                                }
                                                else
                                                {
                                                  idDeclParticle::ParseParms(
                                                    this,
                                                    src,
                                                    parms: NewStage->direction.angleOffsetStart,
                                                    maxParms: 2);
                                                }
                                              }
                                              else
                                              {
                                                idDeclParticle::ParseParms(
                                                  this,
                                                  src,
                                                  parms: NewStage->direction.parms,
                                                  maxParms: 4);
                                                v27 = NewStage->direction.parms[3];
                                                v28 = NewStage->direction.parms[2];
                                                v206[0] = NewStage->direction.parms[1];
                                                v206[1] = v28;
                                                v206[2] = v27;
                                                NewStage->direction.coneAxis = *idAngles::ToMat3(
                                                                                  this: v211,
                                                                                  result: (idMat3 *)v206);
                                              }
                                            }
                                            else
                                            {
                                              idParser::ReadToken(this: src, token: &v92);
                                              v26 = ParticleDirectionNameToType(text: &v92);
                                              if ( v26 >= 0 )
                                                NewStage->direction.type = v26;
                                              else
                                                idParser::Error(this: src, str: "bad direction type: %s\n", v92.data);
                                            }
                                          }
                                        }
                                        else
                                        {
                                          idParser::ReadToken(this: src, token: &v92);
                                          v33 = ParticleDirectionNameToType(text: &v92);
                                          if ( v33 >= 0 )
                                            NewStage->direction.type = v33;
                                          else
                                            idParser::Error(this: src, str: "bad direction type: %s\n", v92.data);
                                          idDeclParticle::ParseParms(
                                            this,
                                            src,
                                            parms: NewStage->direction.parms,
                                            maxParms: 4);
                                          v34 = NewStage->direction.parms[3];
                                          v35 = NewStage->direction.parms[2];
                                          *(float *)v207 = NewStage->direction.parms[1];
                                          *((float *)v207 + 1) = v35;
                                          *(float *)&v207[1] = v34;
                                          NewStage->direction.coneAxis = *idAngles::ToMat3(
                                                                            this: v211,
                                                                            result: (idMat3 *)v207);
                                        }
                                        continue;
                                      }
                                      if ( idStr::Icmp(s1: v92.data, s2: v196) == 0 )
                                      {
                                        if ( idParser::PeekTokenType(this: src, type: 5, subtype: 46, token: &v92) != 0 )
                                        {
                                          idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v92);
                                          while ( idParser::ReadToken(this: src, token: &v92) )
                                          {
                                            if ( v92.type == 5 && v92.subtype == 47 )
                                              break;
                                            if ( idStr::Icmp(s1: v92.data, s2: "type") != 0 )
                                            {
                                              if ( idStr::Icmp(s1: v92.data, s2: v101) != 0 )
                                              {
                                                if ( idStr::Icmp(s1: v92.data, s2: v166) != 0 )
                                                {
                                                  if ( idStr::Icmp(s1: v92.data, s2: v120) != 0 )
                                                  {
                                                    if ( idStr::Icmp(s1: v92.data, s2: v191) != 0 )
                                                    {
                                                      if ( idStr::Icmp(s1: v92.data, s2: v122) != 0 )
                                                      {
                                                        if ( idStr::Icmp(s1: v92.data, s2: v168) != 0 )
                                                        {
                                                          if ( idStr::Icmp(s1: v92.data, s2: v124) != 0 )
                                                          {
                                                            if ( idStr::Icmp(s1: v92.data, s2: v197) != 0 )
                                                            {
                                                              HIDWORD(v38) = this->name.str;
                                                              LODWORD(v39) = v16->data;
                                                              HIDWORD(v39) = v92.data;
                                                              v40 = va::va(
                                                                      this: &v212,
                                                                      fmt: v126,
                                                                      a3: v39,
                                                                      a4: v38,
                                                                      a5: v37,
                                                                      a6: v86,
                                                                      a7: v87,
                                                                      a8: v88,
                                                                      a9: v89,
                                                                      a10: v90,
                                                                      a11: v91);
                                                              idParser::Error(this: src, str: v40->buffer);
                                                            }
                                                            else
                                                            {
                                                              NewStage->orientation.depthOffset = idParser::ParseFloat(
                                                                                                    this: src,
                                                                                                    errorFlag: nullptr);
                                                            }
                                                          }
                                                          else
                                                          {
                                                            NewStage->orientation.orientToVelOnly = idParser::ParseBool(this: src);
                                                          }
                                                        }
                                                        else
                                                        {
                                                          NewStage->orientation.numTrails = idParser::ParseInt(this: src);
                                                        }
                                                      }
                                                      else
                                                      {
                                                        NewStage->orientation.aimedSafeQuadAlign = idParser::ParseFloat(
                                                                                                     this: src,
                                                                                                     errorFlag: nullptr);
                                                      }
                                                    }
                                                    else
                                                    {
                                                      NewStage->orientation.aimedSafeQuad = idParser::ParseBool(this: src);
                                                    }
                                                  }
                                                  else
                                                  {
                                                    NewStage->orientation.segmentLength = idParser::ParseFloat(
                                                                                            this: src,
                                                                                            errorFlag: nullptr);
                                                  }
                                                }
                                                else
                                                {
                                                  NewStage->orientation.viewFade = idParser::ParseFloat(
                                                                                     this: src,
                                                                                     errorFlag: nullptr);
                                                }
                                              }
                                              else
                                              {
                                                NewStage->orientation.world = idParser::ParseBool(this: src);
                                              }
                                            }
                                            else
                                            {
                                              idParser::ReadToken(this: src, token: &v92);
                                              v36 = ParticleOrientationNameToType(text: &v92);
                                              if ( v36 >= 0 )
                                                NewStage->orientation.type = v36;
                                              else
                                                idParser::Error(this: src, str: v118, v92.data);
                                            }
                                          }
                                        }
                                        else
                                        {
                                          idParser::ReadToken(this: src, token: &v92);
                                          if ( idStr::Icmp(s1: v92.data, s2: v101) == 0 )
                                          {
                                            NewStage->orientation.world = true;
                                            idParser::ReadToken(this: src, token: &v92);
                                          }
                                          v41 = ParticleOrientationNameToType(text: &v92);
                                          if ( v41 >= 0 )
                                            NewStage->orientation.type = v41;
                                          else
                                            idParser::Error(this: src, str: v170, v92.data);
                                          type = NewStage->orientation.type;
                                          if ( type == POR_TRAIL )
                                          {
                                            NewStage->orientation.numTrails = idParser::ParseInt(this: src);
                                            NewStage->orientation.segmentLength = idParser::ParseFloat(
                                                                                    this: src,
                                                                                    errorFlag: nullptr);
                                          }
                                          else if ( type == POR_AIMED )
                                          {
                                            NewStage->orientation.segmentLength = idParser::ParseFloat(
                                                                                    this: src,
                                                                                    errorFlag: nullptr);
                                            if ( idParser::ReadTokenOnLine(this: src, token: &v92) != 0
                                              && atol(nptr: v92.data) == 1 )
                                            {
                                              NewStage->orientation.orientToVelOnly = true;
                                            }
                                            if ( idParser::ReadTokenOnLine(this: src, token: &v92) != 0 )
                                            {
                                              v43 = atof(nptr: v92.data);
                                              NewStage->orientation.viewFade = *(double *)&v43;
                                            }
                                          }
                                        }
                                        continue;
                                      }
                                      if ( idStr::Icmp(s1: v92.data, s2: v128) == 0 )
                                      {
                                        idParser::ReadToken(this: src, token: &v92);
                                        v44 = ParticleCustomNameToType(text: &v92);
                                        if ( v44 >= 0 )
                                          NewStage->customPath.type = v44;
                                        else
                                          idParser::Error(this: src, str: v193, v92.data);
                                        continue;
                                      }
                                      if ( idStr::Icmp(s1: v92.data, s2: v130) != 0 )
                                      {
                                        if ( idStr::Icmp(s1: v92.data, s2: v172) != 0 )
                                        {
                                          if ( idStr::Icmp(s1: v92.data, s2: v132) != 0 )
                                          {
                                            if ( idStr::Icmp(s1: v92.data, s2: v199) != 0 )
                                            {
                                              if ( idStr::Icmp(s1: v92.data, s2: v134) != 0 )
                                              {
                                                if ( idStr::Icmp(s1: v92.data, s2: v174) != 0 )
                                                {
                                                  if ( idStr::Icmp(s1: v92.data, s2: v136) != 0 )
                                                  {
                                                    if ( idStr::Icmp(s1: v92.data, s2: v195) != 0 )
                                                    {
                                                      if ( idStr::Icmp(s1: v92.data, s2: v138) != 0 )
                                                      {
                                                        if ( idStr::Icmp(s1: v92.data, s2: v176) != 0 )
                                                        {
                                                          if ( idStr::Icmp(s1: v92.data, s2: v140) != 0 )
                                                          {
                                                            if ( idStr::Icmp(s1: v92.data, s2: v201) != 0 )
                                                            {
                                                              if ( idStr::Icmp(s1: v92.data, s2: v142) != 0 )
                                                              {
                                                                if ( idStr::Icmp(s1: v92.data, s2: v178) != 0 )
                                                                {
                                                                  if ( idStr::Icmp(s1: v92.data, s2: v144) != 0 )
                                                                  {
                                                                    if ( idStr::Icmp(s1: v92.data, s2: v203) != 0 )
                                                                    {
                                                                      if ( idStr::Icmp(s1: v92.data, s2: v146) != 0 )
                                                                      {
                                                                        if ( idStr::Icmp(s1: v92.data, s2: v181) != 0 )
                                                                        {
                                                                          if ( idStr::Icmp(s1: v92.data, s2: v148) != 0 )
                                                                          {
                                                                            if ( idStr::Icmp(s1: v92.data, s2: v198) != 0 )
                                                                            {
                                                                              if ( idStr::Icmp(s1: v92.data, s2: v150) != 0 )
                                                                              {
                                                                                if ( idStr::Icmp(s1: v92.data, s2: v183) != 0 )
                                                                                {
                                                                                  if ( idStr::Icmp(
                                                                                         s1: v92.data,
                                                                                         s2: v152) != 0 )
                                                                                  {
                                                                                    if ( idStr::Icmp(
                                                                                           s1: v92.data,
                                                                                           s2: v205) != 0 )
                                                                                    {
                                                                                      if ( idStr::Icmp(
                                                                                             s1: v92.data,
                                                                                             s2: v115) != 0 )
                                                                                      {
                                                                                        if ( idStr::Icmp(
                                                                                               s1: v92.data,
                                                                                               s2: v185) != 0 )
                                                                                        {
                                                                                          if ( idStr::Icmp(
                                                                                                 s1: v92.data,
                                                                                                 s2: v156) != 0 )
                                                                                          {
                                                                                            if ( idStr::Icmp(
                                                                                                   s1: v92.data,
                                                                                                   s2: v200) != 0 )
                                                                                            {
                                                                                              if ( idStr::Icmp(
                                                                                                     s1: v92.data,
                                                                                                     s2: v158) != 0 )
                                                                                              {
                                                                                                if ( idStr::Icmp(s1: v92.data, s2: v187) != 0 )
                                                                                                {
                                                                                                  if ( idStr::Icmp(s1: v92.data, s2: v160) != 0 )
                                                                                                  {
                                                                                                    if ( idStr::Icmp(s1: v92.data, s2: v204) != 0 )
                                                                                                    {
                                                                                                      if ( idStr::Icmp(s1: v92.data, s2: v162) != 0 )
                                                                                                      {
                                                                                                        if ( idStr::Icmp(s1: v92.data, s2: v189) != 0 )
                                                                                                        {
                                                                                                          if ( idStr::Icmp(s1: v92.data, s2: v164) != 0 )
                                                                                                          {
                                                                                                            if ( idStr::Icmp(s1: v92.data, s2: v116) != 0 )
                                                                                                            {
                                                                                                              if ( idStr::Icmp(s1: v92.data, s2: v117) != 0 )
                                                                                                              {
                                                                                                                if ( idStr::Icmp(s1: v92.data, s2: v119) != 0 )
                                                                                                                {
                                                                                                                  if ( idStr::Icmp(s1: v92.data, s2: v121) != 0 )
                                                                                                                  {
                                                                                                                    if ( idStr::Icmp(s1: v92.data, s2: v123) != 0 )
                                                                                                                    {
                                                                                                                      if ( idStr::Icmp(s1: v92.data, s2: v125) != 0 )
                                                                                                                      {
                                                                                                                        if ( idStr::Icmp(s1: v92.data, s2: v127) != 0 )
                                                                                                                        {
                                                                                                                          if ( idStr::Icmp(s1: v92.data, s2: v129) != 0 )
                                                                                                                          {
                                                                                                                            if ( idStr::Icmp(s1: v92.data, s2: v131) != 0 )
                                                                                                                            {
                                                                                                                              if ( idStr::Icmp(s1: v92.data, s2: v133) != 0 )
                                                                                                                              {
                                                                                                                                if ( idStr::Icmp(s1: v92.data, s2: v135) != 0 )
                                                                                                                                {
                                                                                                                                  if ( idStr::Icmp(s1: v92.data, s2: v137) != 0 )
                                                                                                                                  {
                                                                                                                                    if ( idStr::Icmp(s1: v92.data, s2: v139) != 0 )
                                                                                                                                    {
                                                                                                                                      if ( idStr::Icmp(s1: v92.data, s2: v141) != 0 )
                                                                                                                                      {
                                                                                                                                        if ( idStr::Icmp(s1: v92.data, s2: v143) != 0 )
                                                                                                                                        {
                                                                                                                                          if ( idStr::Icmp(s1: v92.data, s2: v145) == 0 )
                                                                                                                                          {
                                                                                                                                            v47 = idParser::ParseInt(this: src);
                                                                                                                                            NewStage->texAnimation.numColumns = v47;
                                                                                                                                            if ( v47 > 0x40u )
                                                                                                                                            {
                                                                                                                                              idLib::Printf(fmt: v147, this->name.str, v47, 64);
                                                                                                                                              NewStage->texAnimation.numColumns = 64;
                                                                                                                                            }
                                                                                                                                            continue;
                                                                                                                                          }
                                                                                                                                          if ( idStr::Icmp(s1: v92.data, s2: v149) == 0 )
                                                                                                                                          {
                                                                                                                                            v48 = idParser::ParseInt(this: src);
                                                                                                                                            NewStage->texAnimation.numRows = v48;
                                                                                                                                            if ( v48 > 4u )
                                                                                                                                            {
                                                                                                                                              idLib::Printf(fmt: v151, this->name.str, v48, 4);
                                                                                                                                              NewStage->texAnimation.numRows = 4;
                                                                                                                                            }
                                                                                                                                            continue;
                                                                                                                                          }
                                                                                                                                          if ( idStr::Icmp(s1: v92.data, s2: v153) != 0 )
                                                                                                                                          {
                                                                                                                                            if ( idStr::Icmp(s1: v92.data, s2: v155) == 0 )
                                                                                                                                            {
                                                                                                                                              if ( idParser::ParseBool(this: src) )
                                                                                                                                                NewStage->texAnimation.startFrame = -1;
                                                                                                                                              continue;
                                                                                                                                            }
                                                                                                                                            if ( idStr::Icmp(s1: v92.data, s2: v157) != 0 )
                                                                                                                                            {
                                                                                                                                              if ( idStr::Icmp(s1: v92.data, s2: v159) != 0 )
                                                                                                                                              {
                                                                                                                                                if ( idStr::Icmp(s1: v92.data, s2: v161) == 0 )
                                                                                                                                                {
                                                                                                                                                  idParser::ReadToken(this: src, token: &v92);
                                                                                                                                                  v49 = ParticleAnimationNameToType(text: &v92);
                                                                                                                                                  if ( v49 >= 0 )
                                                                                                                                                    NewStage->texAnimation.type = v49;
                                                                                                                                                  else
                                                                                                                                                    idParser::Error(this: src, str: v163, v92.data);
                                                                                                                                                  continue;
                                                                                                                                                }
                                                                                                                                                if ( idStr::Icmp(s1: v92.data, s2: v165) != 0 )
                                                                                                                                                {
                                                                                                                                                  if ( idStr::Icmp(s1: v92.data, s2: v167) != 0 )
                                                                                                                                                  {
                                                                                                                                                    if ( idStr::Icmp(s1: v92.data, s2: v169) != 0 )
                                                                                                                                                    {
                                                                                                                                                      if ( idStr::Icmp(s1: v92.data, s2: v171) != 0 )
                                                                                                                                                      {
                                                                                                                                                        if ( idStr::Icmp(s1: v92.data, s2: v173) != 0 )
                                                                                                                                                        {
                                                                                                                                                          if ( idStr::Icmp(s1: v92.data, s2: v175) != 0 )
                                                                                                                                                          {
                                                                                                                                                            if ( idStr::Icmp(s1: v92.data, s2: v177) != 0 )
                                                                                                                                                            {
                                                                                                                                                              if ( idStr::Icmp(s1: v92.data, s2: v180) != 0 )
                                                                                                                                                              {
                                                                                                                                                                if ( idStr::Icmp(s1: v92.data, s2: v182) != 0 )
                                                                                                                                                                {
                                                                                                                                                                  if ( idStr::Icmp(s1: v92.data, s2: v186) != 0 )
                                                                                                                                                                  {
                                                                                                                                                                    if ( idStr::Icmp(s1: v92.data, s2: v188) != 0 )
                                                                                                                                                                    {
                                                                                                                                                                      if ( idStr::Icmp(s1: v92.data, s2: v190) != 0 )
                                                                                                                                                                      {
                                                                                                                                                                        if ( idStr::Icmp(s1: v92.data, s2: v192) != 0 )
                                                                                                                                                                          idParser::Warning(this: src, str: v194, v92.data);
                                                                                                                                                                        else
                                                                                                                                                                          NewStage->lodParms.radius = idParser::ParseInt(this: src);
                                                                                                                                                                      }
                                                                                                                                                                      else
                                                                                                                                                                      {
                                                                                                                                                                        NewStage->lodParms.lerpAmount = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                                                                                      }
                                                                                                                                                                    }
                                                                                                                                                                    else
                                                                                                                                                                    {
                                                                                                                                                                      NewStage->lodParms.sizeScale = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                                                                                    }
                                                                                                                                                                  }
                                                                                                                                                                  else
                                                                                                                                                                  {
                                                                                                                                                                    v53 = idParser::ParseInt(this: src);
                                                                                                                                                                    v54 = v53;
                                                                                                                                                                    if ( v53 <= 1 )
                                                                                                                                                                      v54 = 1;
                                                                                                                                                                    NewStage->lodParms.totalParticles = v54;
                                                                                                                                                                  }
                                                                                                                                                                }
                                                                                                                                                                else
                                                                                                                                                                {
                                                                                                                                                                  idParser::ReadToken(this: src, token: &v92);
                                                                                                                                                                  v52 = ParticleSortNameToType(text: &v92);
                                                                                                                                                                  if ( v52 >= 0 )
                                                                                                                                                                    NewStage->systemProperties.sortType = v52;
                                                                                                                                                                  else
                                                                                                                                                                    idParser::Error(this: src, str: v184, v92.data);
                                                                                                                                                                }
                                                                                                                                                              }
                                                                                                                                                              else
                                                                                                                                                              {
                                                                                                                                                                ParseParticleParm(src, parm: &NewStage->systemProperties.windBias, tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                                                              }
                                                                                                                                                            }
                                                                                                                                                            else
                                                                                                                                                            {
                                                                                                                                                              idParser::ReadToken(this: src, token: &v92);
                                                                                                                                                              if ( idStr::Icmp(s1: v92.data, s2: v101) != 0 )
                                                                                                                                                                idParser::UnreadToken(this: src, token: &v92);
                                                                                                                                                              else
                                                                                                                                                                NewStage->gravity.world = true;
                                                                                                                                                              ParseParticleParm(src, parm: &NewStage->gravity.gravity, tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                                                            }
                                                                                                                                                          }
                                                                                                                                                          else
                                                                                                                                                          {
                                                                                                                                                            NewStage->systemProperties.randomOnCycle = idParser::ParseBool(this: src);
                                                                                                                                                          }
                                                                                                                                                        }
                                                                                                                                                        else
                                                                                                                                                        {
                                                                                                                                                          NewStage->systemProperties.boundsExpansion = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                                                                        }
                                                                                                                                                      }
                                                                                                                                                      else
                                                                                                                                                      {
                                                                                                                                                        NewStage->rotation.allowRotDirOverride = idParser::ParseBool(this: src);
                                                                                                                                                      }
                                                                                                                                                      continue;
                                                                                                                                                    }
                                                                                                                                                    idParser::ReadToken(this: src, token: &v92);
                                                                                                                                                    v51 = ParticleTextureFlipNameToType(text: &v92);
                                                                                                                                                    if ( v51 >= 0 )
                                                                                                                                                    {
                                                                                                                                                      NewStage->systemProperties.textureFlipT = v51;
                                                                                                                                                      continue;
                                                                                                                                                    }
                                                                                                                                                  }
                                                                                                                                                  else
                                                                                                                                                  {
                                                                                                                                                    idParser::ReadToken(this: src, token: &v92);
                                                                                                                                                    v50 = ParticleTextureFlipNameToType(text: &v92);
                                                                                                                                                    if ( v50 >= 0 )
                                                                                                                                                    {
                                                                                                                                                      NewStage->systemProperties.textureFlipS = v50;
                                                                                                                                                      continue;
                                                                                                                                                    }
                                                                                                                                                  }
                                                                                                                                                  idParser::Error(this: src, str: v114, v92.data);
                                                                                                                                                }
                                                                                                                                                else
                                                                                                                                                {
                                                                                                                                                  NewStage->texAnimation.useFrameBlending = (_cntlzw(idParser::ParseBool(this: src)) & 0x20) != 0;
                                                                                                                                                }
                                                                                                                                              }
                                                                                                                                              else
                                                                                                                                              {
                                                                                                                                                NewStage->texAnimation.useRandomRow = idParser::ParseBool(this: src);
                                                                                                                                              }
                                                                                                                                            }
                                                                                                                                            else
                                                                                                                                            {
                                                                                                                                              NewStage->texAnimation.startFrame = idParser::ParseInt(this: src);
                                                                                                                                            }
                                                                                                                                          }
                                                                                                                                          else
                                                                                                                                          {
                                                                                                                                            ParseParticleParm(src, parm: &NewStage->texAnimation.rate, tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                                          }
                                                                                                                                        }
                                                                                                                                        else
                                                                                                                                        {
                                                                                                                                          ParseParticleParm(src, parm: &NewStage->offset.offset[2], tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                                        }
                                                                                                                                      }
                                                                                                                                      else
                                                                                                                                      {
                                                                                                                                        ParseParticleParm(src, parm: &NewStage->offset.offset[1], tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                                      }
                                                                                                                                    }
                                                                                                                                    else
                                                                                                                                    {
                                                                                                                                      ParseParticleParm(src, parm: NewStage->offset.offset, tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                                    }
                                                                                                                                  }
                                                                                                                                  else
                                                                                                                                  {
                                                                                                                                    NewStage->colorAttributes.fadeColor.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                                                    NewStage->colorAttributes.fadeColor.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                                                    NewStage->colorAttributes.fadeColor.z = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                                                    NewStage->colorAttributes.fadeColor.w = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                                                  }
                                                                                                                                }
                                                                                                                                else
                                                                                                                                {
                                                                                                                                  ParseParticleParm(src, parm: &NewStage->colorAttributes.baseColor[3], tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                                }
                                                                                                                              }
                                                                                                                              else
                                                                                                                              {
                                                                                                                                ParseParticleParm(src, parm: &NewStage->colorAttributes.baseColor[2], tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                              }
                                                                                                                            }
                                                                                                                            else
                                                                                                                            {
                                                                                                                              ParseParticleParm(src, parm: &NewStage->colorAttributes.baseColor[1], tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                            }
                                                                                                                          }
                                                                                                                          else
                                                                                                                          {
                                                                                                                            ParseParticleParm(src, parm: NewStage->colorAttributes.baseColor, tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                          }
                                                                                                                        }
                                                                                                                        else
                                                                                                                        {
                                                                                                                          NewStage->colorAttributes.useGlobalShadows = idParser::ParseBool(this: src);
                                                                                                                        }
                                                                                                                      }
                                                                                                                      else
                                                                                                                      {
                                                                                                                        ParseParticleParm(src, parm: &NewStage->genericParm.genericParm[3], tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                      }
                                                                                                                    }
                                                                                                                    else
                                                                                                                    {
                                                                                                                      ParseParticleParm(src, parm: &NewStage->genericParm.genericParm[2], tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                    }
                                                                                                                  }
                                                                                                                  else
                                                                                                                  {
                                                                                                                    ParseParticleParm(src, parm: &NewStage->genericParm.genericParm[1], tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                  }
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                  ParseParticleParm(src, parm: NewStage->genericParm.genericParm, tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                                }
                                                                                                              }
                                                                                                              else
                                                                                                              {
                                                                                                                ParseParticleParm(src, parm: &NewStage->colorAttributes.brightness, tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls, tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                              }
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                              NewStage->colorAttributes.entityColorBlendVal = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                            }
                                                                                                          }
                                                                                                          else
                                                                                                          {
                                                                                                            NewStage->colorAttributes.minShadowVal = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                          }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                          _FP0 = (float)(idParser::ParseFloat(this: src, errorFlag: nullptr) - (float)1.0);
                                                                                                          __asm { fsel      f13, f0, f1, f31 }
                                                                                                          NewStage->colorAttributes.softParticleAlphaScale = (float)1.0 / (float)_FP13;
                                                                                                        }
                                                                                                      }
                                                                                                      else
                                                                                                      {
                                                                                                        NewStage->colorAttributes.fadeIndexFraction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                      }
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                      NewStage->colorAttributes.fadeOutFraction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                    }
                                                                                                  }
                                                                                                  else
                                                                                                  {
                                                                                                    NewStage->colorAttributes.fadeInFraction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                                  }
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                  ParseParticleParm(
                                                                                                    src,
                                                                                                    parm: &NewStage->size.aspectRatio,
                                                                                                    tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                                                    tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                                }
                                                                                              }
                                                                                              else
                                                                                              {
                                                                                                ParseParticleParm(
                                                                                                  src,
                                                                                                  parm: &NewStage->size.size[2],
                                                                                                  tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                                                  tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                              }
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                              ParseParticleParm(
                                                                                                src,
                                                                                                parm: &NewStage->size.size[1],
                                                                                                tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                                                tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                            }
                                                                                          }
                                                                                          else
                                                                                          {
                                                                                            ParseParticleParm(
                                                                                              src,
                                                                                              parm: NewStage->size.size,
                                                                                              tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                                              tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                          }
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                          NewStage->pivot.pivotOffset.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                        }
                                                                                      }
                                                                                      else
                                                                                      {
                                                                                        NewStage->pivot.pivotOffset.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                                                                      }
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                      ParseParticleParm(
                                                                                        src,
                                                                                        parm: &NewStage->spawnLocation.spawnLocation[2],
                                                                                        tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                                        tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                    }
                                                                                  }
                                                                                  else
                                                                                  {
                                                                                    ParseParticleParm(
                                                                                      src,
                                                                                      parm: &NewStage->spawnLocation.spawnLocation[1],
                                                                                      tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                                      tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                  }
                                                                                }
                                                                                else
                                                                                {
                                                                                  ParseParticleParm(
                                                                                    src,
                                                                                    parm: NewStage->spawnLocation.spawnLocation,
                                                                                    tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                                    tables: (idList<idLookupTable,5> *)&this->tables);
                                                                                }
                                                                              }
                                                                              else
                                                                              {
                                                                                ParseParticleParm(
                                                                                  src,
                                                                                  parm: &NewStage->initialRotation.initialAngle[2],
                                                                                  tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                                  tables: (idList<idLookupTable,5> *)&this->tables);
                                                                              }
                                                                            }
                                                                            else
                                                                            {
                                                                              ParseParticleParm(
                                                                                src,
                                                                                parm: &NewStage->initialRotation.initialAngle[1],
                                                                                tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                                tables: (idList<idLookupTable,5> *)&this->tables);
                                                                            }
                                                                          }
                                                                          else
                                                                          {
                                                                            ParseParticleParm(
                                                                              src,
                                                                              parm: NewStage->initialRotation.initialAngle,
                                                                              tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                              tables: (idList<idLookupTable,5> *)&this->tables);
                                                                          }
                                                                        }
                                                                        else
                                                                        {
                                                                          ParseParticleParm(
                                                                            src,
                                                                            parm: &NewStage->rotation.rotation[2],
                                                                            tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                            tables: (idList<idLookupTable,5> *)&this->tables);
                                                                        }
                                                                      }
                                                                      else
                                                                      {
                                                                        ParseParticleParm(
                                                                          src,
                                                                          parm: &NewStage->rotation.rotation[1],
                                                                          tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                          tables: (idList<idLookupTable,5> *)&this->tables);
                                                                      }
                                                                    }
                                                                    else
                                                                    {
                                                                      ParseParticleParm(
                                                                        src,
                                                                        parm: NewStage->rotation.rotation,
                                                                        tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                        tables: (idList<idLookupTable,5> *)&this->tables);
                                                                    }
                                                                  }
                                                                  else
                                                                  {
                                                                    ParseParticleParm(
                                                                      src,
                                                                      parm: &NewStage->friction.friction[2],
                                                                      tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                      tables: (idList<idLookupTable,5> *)&this->tables);
                                                                  }
                                                                }
                                                                else
                                                                {
                                                                  ParseParticleParm(
                                                                    src,
                                                                    parm: &NewStage->friction.friction[1],
                                                                    tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                    tables: (idList<idLookupTable,5> *)&this->tables);
                                                                }
                                                              }
                                                              else
                                                              {
                                                                ParseParticleParm(
                                                                  src,
                                                                  parm: NewStage->friction.friction,
                                                                  tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                  tables: (idList<idLookupTable,5> *)&this->tables);
                                                              }
                                                            }
                                                            else
                                                            {
                                                              ParseParticleParm(
                                                                src,
                                                                parm: &NewStage->acceleration.acceleration[2],
                                                                tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                                tables: (idList<idLookupTable,5> *)&this->tables);
                                                            }
                                                          }
                                                          else
                                                          {
                                                            ParseParticleParm(
                                                              src,
                                                              parm: &NewStage->acceleration.acceleration[1],
                                                              tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                              tables: (idList<idLookupTable,5> *)&this->tables);
                                                          }
                                                        }
                                                        else
                                                        {
                                                          ParseParticleParm(
                                                            src,
                                                            parm: NewStage->acceleration.acceleration,
                                                            tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                            tables: (idList<idLookupTable,5> *)&this->tables);
                                                        }
                                                      }
                                                      else
                                                      {
                                                        NewStage->acceleration.world = idParser::ParseBool(this: src);
                                                      }
                                                    }
                                                    else
                                                    {
                                                      ParseParticleParm(
                                                        src,
                                                        parm: &NewStage->speed.speed[2],
                                                        tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                        tables: (idList<idLookupTable,5> *)&this->tables);
                                                    }
                                                  }
                                                  else
                                                  {
                                                    ParseParticleParm(
                                                      src,
                                                      parm: &NewStage->speed.speed[1],
                                                      tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                      tables: (idList<idLookupTable,5> *)&this->tables);
                                                  }
                                                }
                                                else
                                                {
                                                  ParseParticleParm(
                                                    src,
                                                    parm: NewStage->speed.speed,
                                                    tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                    tables: (idList<idLookupTable,5> *)&this->tables);
                                                }
                                              }
                                              else
                                              {
                                                ParseParticleParm(
                                                  src,
                                                  parm: &NewStage->customPath.parms[4],
                                                  tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                  tables: (idList<idLookupTable,5> *)&this->tables);
                                              }
                                            }
                                            else
                                            {
                                              ParseParticleParm(
                                                src,
                                                parm: &NewStage->customPath.parms[3],
                                                tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                                tables: (idList<idLookupTable,5> *)&this->tables);
                                            }
                                          }
                                          else
                                          {
                                            ParseParticleParm(
                                              src,
                                              parm: &NewStage->customPath.parms[2],
                                              tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                              tables: (idList<idLookupTable,5> *)&this->tables);
                                          }
                                        }
                                        else
                                        {
                                          ParseParticleParm(
                                            src,
                                            parm: &NewStage->customPath.parms[1],
                                            tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                            tables: (idList<idLookupTable,5> *)&this->tables);
                                        }
                                      }
                                      else
                                      {
                                        ParseParticleParm(
                                          src,
                                          parm: NewStage->customPath.parms,
                                          tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                          tables: (idList<idLookupTable,5> *)&this->tables);
                                      }
                                    }
                                    else
                                    {
                                      ParseParticleParm(
                                        src,
                                        parm: &NewStage->distribution.size[2],
                                        tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                        tables: (idList<idLookupTable,5> *)&this->tables);
                                    }
                                  }
                                  else
                                  {
                                    ParseParticleParm(
                                      src,
                                      parm: &NewStage->distribution.size[1],
                                      tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                      tables: (idList<idLookupTable,5> *)&this->tables);
                                  }
                                }
                                else
                                {
                                  ParseParticleParm(
                                    src,
                                    parm: NewStage->distribution.size,
                                    tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                                    tables: (idList<idLookupTable,5> *)&this->tables);
                                }
                              }
                              else
                              {
                                NewStage->systemProperties.spawnBunching = idParser::ParseFloat(
                                                                             this: src,
                                                                             errorFlag: nullptr);
                              }
                            }
                            else
                            {
                              NewStage->distribution.random = idParser::ParseBool(this: src);
                            }
                          }
                          else
                          {
                            ParseParticleParm(
                              src,
                              parm: &NewStage->systemProperties.deadTime,
                              tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                              tables: (idList<idLookupTable,5> *)&this->tables);
                          }
                        }
                        else
                        {
                          NewStage->systemProperties.emissionTime = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        }
                      }
                      else
                      {
                        NewStage->systemProperties.useSysTime = idParser::ParseFloat(this: src, errorFlag: nullptr);
                      }
                    }
                    else
                    {
                      NewStage->systemProperties.diversity = idParser::ParseInt(this: src) & 0x7FFF;
                    }
                  }
                  else
                  {
                    NewStage->systemProperties.timeOffset = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  NewStage->systemProperties.cycles = idParser::ParseInt(this: src);
                }
              }
              else
              {
                ParseParticleParm(
                  src,
                  parm: &NewStage->systemProperties.particleLife,
                  tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
                  tables: (idList<idLookupTable,5> *)&this->tables);
              }
            }
            else
            {
              NewStage->systemProperties.totalParticles = idParser::ParseInt(this: src);
            }
          }
          else
          {
            ParseBounds(src, bounds: &NewStage->bounds);
          }
        }
        else
        {
          idParser::ReadToken(this: src, token: &v92);
          v24 = (const idStaticParticleModelData *)idResourceList::Load(
                                                     this: &idStaticParticleModelData::resourceList,
                                                     name: v92.data,
                                                     makeDefault: true,
                                                     skipStaleCheck: false);
          idParticleStage::SetStaticMesh(this: NewStage, _staticData: v24);
        }
      }
      else
      {
        if ( v112 > 0 )
        {
          idLib::Error(
            fmt: "Particle: %s: Stage inherited after other parms were parsed!. 'inherit' must come first.",
            this->name.str);
          goto _LN919;
        }
        if ( !idParser::ReadToken(this: src, token: &v92) )
          break;
        StageByName = idDeclParticle::FindStageByName(this, name: v92.data);
        if ( StageByName == nullptr )
        {
          idLib::Error(fmt: "Particle: %s: Stage inherited from invalid stage '%s'.", this->name.str, v92.data);
          return _LN920(a1: v85, a2: v84, a3: v83, a4: v82, a5: v81, a6: v80, a7: v79, a8: v78, a9, a10);
        }
        idParticleStage::operator=(this: NewStage, src: StageByName);
        len = v92.len;
        v19 = v92.len + 1;
        allocedAndFlag = inheritFrom->allocedAndFlag;
        v22 = allocedAndFlag >> 31 == 0;
        v21 = allocedAndFlag & 0x7FFFFFFF;
        if ( v22 )
        {
          if ( v19 > v21 )
            idStr::ReAllocate(this: inheritFrom, amount: v19, keepold: false);
        }
        else if ( v19 > v21 && AssertFailed(file: v202, line: 463, expression: v154, inlineBreak: true) )
        {
          __trap();
        }
        memcpy(Dst: inheritFrom->data, Src: v92.data, Size: len);
        inheritFrom->data[len] = 0;
        inheritFrom->len = len;
        v16 = stageName;
      }
    }
    while ( !idParser::HadError(this: src) );
  }
  v55 = idDeclParticle::GetTables(this: v10);
  NewStage->maxParticleLife = idParticleParm::GetMaxParmVal(this: &NewStage->systemProperties.particleLife, tables: v55);
  v56 = idDeclParticle::GetTables(this: v10);
  MaxParmVal = idParticleParm::GetMaxParmVal(this: &NewStage->systemProperties.deadTime, tables: v56);
  emissionTime = NewStage->systemProperties.emissionTime;
  maxParticleLife = NewStage->maxParticleLife;
  NewStage->maxDeadTime = MaxParmVal;
  NewStage->cycleMsec = (int)(float)((float)((float)maxParticleLife + (float)MaxParmVal) * (float)1000.0);
  if ( emissionTime > 0.0 )
    maxParticleLife = emissionTime;
  staticData = NewStage->staticData;
  NewStage->bunchTime = maxParticleLife;
  if ( staticData != nullptr )
  {
    numStaticVerts = NewStage->numStaticVerts;
  }
  else
  {
_LN919:
    if ( NewStage->orientation.type == POR_TRAIL )
      v62 = NewStage->orientation.numTrails + 1;
    else
      v62 = 1;
    numStaticVerts = 4 * v62;
  }
  totalParticles = NewStage->systemProperties.totalParticles;
  if ( totalParticles * numStaticVerts > 512 )
  {
    if ( staticData != nullptr )
    {
      v64 = NewStage->numStaticVerts;
    }
    else
    {
      if ( NewStage->orientation.type == POR_TRAIL )
        v65 = NewStage->orientation.numTrails + 1;
      else
        v65 = 1;
      v64 = 4 * v65;
    }
    v66 = 32 * v64;
    str = v10->name.str;
    v68 = 0x4000 / v66;
    __twllei(v66, 0);
    idLib::Warning(
      fmt: "Particle %s exceeds max vert count, reducing number of particles from %d to %d!!",
      str,
      totalParticles,
      0x4000 / v66);
    NewStage->systemProperties.totalParticles = v68;
  }
  if ( NewStage->staticData != nullptr )
  {
    v69 = NewStage->numStaticVerts;
  }
  else
  {
    if ( NewStage->orientation.type == POR_TRAIL )
      v70 = NewStage->orientation.numTrails + 1;
    else
      v70 = 1;
    v69 = 4 * v70;
  }
  v71 = NewStage->lodParms.totalParticles;
  if ( v71 * v69 > 512 )
  {
    if ( NewStage->staticData != nullptr )
    {
      v72 = NewStage->numStaticVerts;
    }
    else
    {
      if ( NewStage->orientation.type == POR_TRAIL )
        v73 = NewStage->orientation.numTrails + 1;
      else
        v73 = 1;
      v72 = 4 * v73;
    }
    v74 = 32 * v72;
    v75 = v10->name.str;
    v76 = 0x4000 / v74;
    __twllei(v74, 0);
    idLib::Warning(
      fmt: "Particle %s exceeds max vert count, reducing number of LOD particles from %d to %d!!",
      v75,
      v71,
      0x4000 / v74);
    NewStage->lodParms.totalParticles = v76;
  }
  if ( NewStage->orientation.numTrails > 6 )
    NewStage->orientation.numTrails = 6;
  idStr::FreeData(this: &v92);
  return NewStage;
}


// ========================================================================
// $LN920
// EA  : 0x827E0CC4
// RVA : 0x007E0CC4
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _LN920()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5008 + 96));
}


// ========================================================================
// ?UpdateBounds@idDeclParticle@@AAAXXZ
// EA  : 0x827E0CF0
// RVA : 0x007E0CF0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void __fastcall idDeclParticle::UpdateBounds(idDeclParticle *this)
{
  float *p_bounds; // r31
  idVec3 *v3; // r28
  int num; // r11
  int v5; // r27
  int v6; // r29
  idParticleStage **list; // r26
  const idLookupTable *Tables; // r3
  double v9; // fp13
  double v10; // fp12
  double v11; // fp11
  double v12; // fp10
  double v13; // fp9
  float *v14; // r11
  int v27; // r9
  int v28; // r10
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v32; // fp10
  float *v33; // r11
  double v34; // fp9
  double v47; // fp12
  double v48; // fp11
  double v49; // fp9

  p_bounds = (float *)&this->bounds;
  v3 = &this->bounds.b[1];
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  num = this->stages.num;
  if ( idLib::production >= PROD_PRODUCTION )
  {
    v27 = 0;
    if ( num > 0 )
    {
      v28 = 0;
      do
      {
        y = this->bounds.b[0].y;
        ++v27;
        z = this->bounds.b[0].z;
        x = v3->x;
        v32 = this->bounds.b[1].y;
        v33 = (float *)this->stages.list[v28];
        v34 = this->bounds.b[1].z;
        ++v28;
        _FP7 = (float)(*p_bounds - v33[7]);
        __asm { fsel      f6, f7, f8, f0 }
        *p_bounds = _FP6;
        _FP4 = (float)((float)y - v33[8]);
        __asm { fsel      f3, f4, f5, f13 }
        this->bounds.b[0].y = _FP3;
        _FP1 = (float)((float)z - v33[9]);
        __asm { fsel      f0, f1, f2, f12 }
        this->bounds.b[0].z = _FP0;
        _FP12 = (float)(v33[10] - (float)x);
        __asm { fsel      f11, f12, f13, f11 }
        v3->x = _FP11;
        _FP7 = (float)(v33[11] - (float)v32);
        __asm { fsel      f6, f7, f8, f10 }
        this->bounds.b[1].y = _FP6;
        _FP4 = (float)(v33[12] - (float)v34);
        __asm { fsel      f3, f4, f5, f9 }
        this->bounds.b[1].z = _FP3;
      }
      while ( v27 < this->stages.num );
    }
  }
  else
  {
    v5 = 0;
    if ( num > 0 )
    {
      v6 = 0;
      do
      {
        list = this->stages.list;
        Tables = idDeclParticle::GetTables(this);
        idParticleStage::CalculateBounds(this: list[v6], tables: Tables);
        ++v5;
        v9 = p_bounds[1];
        v10 = p_bounds[2];
        v11 = v3->x;
        v12 = p_bounds[4];
        v13 = p_bounds[5];
        v14 = (float *)this->stages.list[v6++];
        _FP7 = (float)(*p_bounds - v14[7]);
        __asm { fsel      f6, f7, f8, f0 }
        *p_bounds = _FP6;
        _FP4 = (float)((float)v9 - v14[8]);
        __asm { fsel      f3, f4, f5, f13 }
        p_bounds[1] = _FP3;
        _FP1 = (float)((float)v10 - v14[9]);
        __asm { fsel      f0, f1, f2, f12 }
        p_bounds[2] = _FP0;
        _FP12 = (float)(v14[10] - (float)v11);
        __asm { fsel      f11, f12, f13, f11 }
        v3->x = _FP11;
        _FP7 = (float)(v14[11] - (float)v12);
        __asm { fsel      f6, f7, f8, f10 }
        p_bounds[4] = _FP6;
        _FP4 = (float)(v14[12] - (float)v13);
        __asm { fsel      f3, f4, f5, f9 }
        p_bounds[5] = _FP3;
      }
      while ( v5 < this->stages.num );
    }
  }
  if ( *p_bounds >= (double)v3->x
    || p_bounds[1] >= (double)p_bounds[4]
    || p_bounds[2] >= (double)p_bounds[5]
    || (float)((float)((float)(p_bounds[5] - p_bounds[2]) * (float)(p_bounds[4] - p_bounds[1]))
             * (float)(v3->x - *p_bounds)) <= 0.1 )
  {
    v47 = vec3_origin.y;
    v48 = vec3_origin.z;
    v49 = (float)(vec3_origin.x + (float)8.0);
    *p_bounds = vec3_origin.x - (float)8.0;
    v3->x = v49;
    p_bounds[1] = (float)v47 - (float)8.0;
    p_bounds[2] = (float)v48 - (float)8.0;
    v3->y = (float)v47 + (float)8.0;
    v3->z = (float)v48 + (float)8.0;
  }
}


// ========================================================================
// ?UpdateMaxSystemDuration@idDeclParticle@@AAAXXZ
// EA  : 0x827E0F58
// RVA : 0x007E0F58
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void __fastcall idDeclParticle::UpdateMaxSystemDuration(idDeclParticle *this)
{
  int num; // r11
  int v2; // r9
  int v3; // r6
  idParticleStage **list; // r8
  int v5; // r11

  num = this->stages.num;
  v2 = 0;
  v3 = 0;
  this->maxSystemDuration = 0;
  if ( num > 0 )
  {
    list = this->stages.list;
    do
    {
      v5 = (int)(float)(list[v2]->systemProperties.timeOffset * 1000.0) + list[v2]->cycleMsec;
      if ( v5 > this->maxSystemDuration )
        this->maxSystemDuration = v5;
      ++v3;
      ++v2;
    }
    while ( v3 < this->stages.num );
  }
}


// ========================================================================
// ?FreeData@idDeclParticle@@UAAXXZ
// EA  : 0x827E0FC8
// RVA : 0x007E0FC8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void __fastcall idDeclParticle::FreeData(idDeclParticle *this)
{
  int v2; // r30
  int v3; // r29
  idParticleStage **list; // r4
  idAtomicString *v5; // r4
  idAtomicString *v6; // r4
  const idDeclTable **v7; // r4
  idLookupTable *v8; // r4

  v2 = 0;
  if ( this->stages.num > 0 )
  {
    v3 = 0;
    do
    {
      idMem::Free(this: &mem, ptr: this->stages.list[v3], align: ALIGN_16);
      ++v2;
      ++v3;
    }
    while ( v2 < this->stages.num );
  }
  if ( this->stages.listStatic == 0 || this->stages.listStatic == 2 )
  {
    list = this->stages.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->stages.list = nullptr;
    this->stages.size = 0;
  }
  this->stages.num = 0;
  if ( this->stageNames.listStatic == 0 || this->stageNames.listStatic == 2 )
  {
    v5 = this->stageNames.list;
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    this->stageNames.list = nullptr;
    this->stageNames.size = 0;
  }
  this->stageNames.num = 0;
  if ( this->stageInheritNames.listStatic == 0 || this->stageInheritNames.listStatic == 2 )
  {
    v6 = this->stageInheritNames.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->stageInheritNames.list = nullptr;
    this->stageInheritNames.size = 0;
  }
  this->stageInheritNames.num = 0;
  if ( this->tableDecls.listStatic == 0 || this->tableDecls.listStatic == 2 )
  {
    v7 = this->tableDecls.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->tableDecls.list = nullptr;
    this->tableDecls.size = 0;
  }
  this->tableDecls.num = 0;
  if ( this->tables.listStatic == 0 || this->tables.listStatic == 2 )
  {
    v8 = this->tables.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->tables.list = nullptr;
    this->tables.size = 0;
  }
  this->tables.num = 0;
}


// ========================================================================
// ??$WriteParticleString@F@@YA_NPAVidFile@@PBD1ABF2@Z
// EA  : 0x827E1148
// RVA : 0x007E1148
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall WriteParticleString<short>(
        idFile *f,
        const char *name,
        const char *specifier,
        const __int16 *value,
        const __int16 *defaultValue)
{
  __int64 v8; // r10
  __int64 v9; // r8
  va *v10; // r3
  int v12; // [sp+8h] [-10B8h]
  int v13; // [sp+Ch] [-10B4h]
  int v14; // [sp+10h] [-10B0h]
  int v15; // [sp+14h] [-10ACh]
  int v16; // [sp+18h] [-10A8h]
  int v17; // [sp+1Ch] [-10A4h]
  idStr v18; // [sp+50h] [-1070h] BYREF
  idStr v19; // [sp+70h] [-1050h] BYREF
  va v20; // [sp+90h] [-1030h] BYREF

  if ( *(unsigned __int16 *)value == *(unsigned __int16 *)defaultValue )
    return 0;
  idStr::idStr(this: &v18, text: name);
  idStr::PadLength(this: &v18, newlen: 25);
  v10 = va::va(
          this: &v20,
          fmt: "\t\t%s\t%s\n",
          a3: __SPAIR64__((unsigned int)v18.data, (unsigned int)specifier),
          a4: v9,
          a5: v8,
          a6: v12,
          a7: v13,
          a8: v14,
          a9: v15,
          a10: v16,
          a11: v17);
  idStr::idStr(this: &v19, text: v10);
  f->WriteFloatString(this: f, a2: v19.data, *value);
  idStr::FreeData(this: &v19);
  idStr::FreeData(this: &v18);
  return 1;
}


// ========================================================================
// __unwind$226202_0
// EA  : 0x827E11F4
// RVA : 0x007E11F4
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226202_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// __unwind$226203_0
// EA  : 0x827E121C
// RVA : 0x007E121C
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226203_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 112));
}


// ========================================================================
// ??$WriteParticleString@PBD@@YA_NPAVidFile@@PBD1ABQBD2@Z
// EA  : 0x827E1250
// RVA : 0x007E1250
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall WriteParticleString<char const *>(
        idFile *f,
        const char *name,
        const char *specifier,
        const char *const *value,
        const char *const *defaultValue)
{
  __int64 v8; // r10
  __int64 v9; // r8
  va *v10; // r3
  int v12; // [sp+8h] [-10B8h]
  int v13; // [sp+Ch] [-10B4h]
  int v14; // [sp+10h] [-10B0h]
  int v15; // [sp+14h] [-10ACh]
  int v16; // [sp+18h] [-10A8h]
  int v17; // [sp+1Ch] [-10A4h]
  idStr v18; // [sp+50h] [-1070h] BYREF
  idStr v19; // [sp+70h] [-1050h] BYREF
  va v20; // [sp+90h] [-1030h] BYREF

  if ( *value == *defaultValue )
    return 0;
  idStr::idStr(this: &v18, text: name);
  idStr::PadLength(this: &v18, newlen: 25);
  v10 = va::va(
          this: &v20,
          fmt: "\t\t%s\t%s\n",
          a3: __SPAIR64__((unsigned int)v18.data, (unsigned int)specifier),
          a4: v9,
          a5: v8,
          a6: v12,
          a7: v13,
          a8: v14,
          a9: v15,
          a10: v16,
          a11: v17);
  idStr::idStr(this: &v19, text: v10);
  f->WriteFloatString(this: f, a2: v19.data, *value);
  idStr::FreeData(this: &v19);
  idStr::FreeData(this: &v18);
  return 1;
}


// ========================================================================
// __unwind$226248
// EA  : 0x827E12F8
// RVA : 0x007E12F8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226248()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// __unwind$226249
// EA  : 0x827E1320
// RVA : 0x007E1320
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226249()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 112));
}


// ========================================================================
// ??$WriteParticleString@M@@YA_NPAVidFile@@PBD1ABM2@Z
// EA  : 0x827E1350
// RVA : 0x007E1350
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall WriteParticleString<float>(
        idFile *f,
        const char *name,
        const char *specifier,
        const float *value,
        const float *defaultValue)
{
  __int64 v8; // r10
  __int64 v9; // r8
  va *v10; // r3
  int v12; // [sp+8h] [-10B8h]
  int v13; // [sp+Ch] [-10B4h]
  int v14; // [sp+10h] [-10B0h]
  int v15; // [sp+14h] [-10ACh]
  int v16; // [sp+18h] [-10A8h]
  int v17; // [sp+1Ch] [-10A4h]
  idStr v18; // [sp+50h] [-1070h] BYREF
  idStr v19; // [sp+70h] [-1050h] BYREF
  va v20; // [sp+90h] [-1030h] BYREF

  if ( *value == *defaultValue )
    return 0;
  idStr::idStr(this: &v18, text: name);
  idStr::PadLength(this: &v18, newlen: 25);
  v10 = va::va(
          this: &v20,
          fmt: "\t\t%s\t%s\n",
          a3: __SPAIR64__((unsigned int)v18.data, (unsigned int)specifier),
          a4: v9,
          a5: v8,
          a6: v12,
          a7: v13,
          a8: v14,
          a9: v15,
          a10: v16,
          a11: v17);
  idStr::idStr(this: &v19, text: v10);
  f->WriteFloatString(this: f, a2: v19.data, COERCE_UNSIGNED_INT64(*value));
  idStr::FreeData(this: &v19);
  idStr::FreeData(this: &v18);
  return 1;
}


// ========================================================================
// __unwind$226294_0
// EA  : 0x827E1400
// RVA : 0x007E1400
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226294_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// __unwind$226295
// EA  : 0x827E1428
// RVA : 0x007E1428
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226295()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 112));
}


// ========================================================================
// ??$WriteParticleString@H@@YA_NPAVidFile@@PBD1ABH2@Z
// EA  : 0x827E1458
// RVA : 0x007E1458
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall WriteParticleString<int>(
        idFile *f,
        const char *name,
        const char *specifier,
        const int *value,
        const int *defaultValue)
{
  __int64 v8; // r10
  __int64 v9; // r8
  va *v10; // r3
  int v12; // [sp+8h] [-10B8h]
  int v13; // [sp+Ch] [-10B4h]
  int v14; // [sp+10h] [-10B0h]
  int v15; // [sp+14h] [-10ACh]
  int v16; // [sp+18h] [-10A8h]
  int v17; // [sp+1Ch] [-10A4h]
  idStr v18; // [sp+50h] [-1070h] BYREF
  idStr v19; // [sp+70h] [-1050h] BYREF
  va v20; // [sp+90h] [-1030h] BYREF

  if ( *value == *defaultValue )
    return 0;
  idStr::idStr(this: &v18, text: name);
  idStr::PadLength(this: &v18, newlen: 25);
  v10 = va::va(
          this: &v20,
          fmt: "\t\t%s\t%s\n",
          a3: __SPAIR64__((unsigned int)v18.data, (unsigned int)specifier),
          a4: v9,
          a5: v8,
          a6: v12,
          a7: v13,
          a8: v14,
          a9: v15,
          a10: v16,
          a11: v17);
  idStr::idStr(this: &v19, text: v10);
  f->WriteFloatString(this: f, a2: v19.data, *value);
  idStr::FreeData(this: &v19);
  idStr::FreeData(this: &v18);
  return 1;
}


// ========================================================================
// __unwind$226340
// EA  : 0x827E1500
// RVA : 0x007E1500
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226340()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// __unwind$226341
// EA  : 0x827E1528
// RVA : 0x007E1528
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226341()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 112));
}


// ========================================================================
// ??$WriteParticleString@G@@YA_NPAVidFile@@PBD1ABG2@Z
// EA  : 0x827E1558
// RVA : 0x007E1558
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall WriteParticleString<unsigned short>(
        idFile *f,
        const char *name,
        const char *specifier,
        const unsigned __int16 *value,
        const unsigned __int16 *defaultValue)
{
  __int64 v8; // r10
  __int64 v9; // r8
  va *v10; // r3
  int v12; // [sp+8h] [-10B8h]
  int v13; // [sp+Ch] [-10B4h]
  int v14; // [sp+10h] [-10B0h]
  int v15; // [sp+14h] [-10ACh]
  int v16; // [sp+18h] [-10A8h]
  int v17; // [sp+1Ch] [-10A4h]
  idStr v18; // [sp+50h] [-1070h] BYREF
  idStr v19; // [sp+70h] [-1050h] BYREF
  va v20; // [sp+90h] [-1030h] BYREF

  if ( *value == *defaultValue )
    return 0;
  idStr::idStr(this: &v18, text: name);
  idStr::PadLength(this: &v18, newlen: 25);
  v10 = va::va(
          this: &v20,
          fmt: "\t\t%s\t%s\n",
          a3: __SPAIR64__((unsigned int)v18.data, (unsigned int)specifier),
          a4: v9,
          a5: v8,
          a6: v12,
          a7: v13,
          a8: v14,
          a9: v15,
          a10: v16,
          a11: v17);
  idStr::idStr(this: &v19, text: v10);
  f->WriteFloatString(this: f, a2: v19.data, *value);
  idStr::FreeData(this: &v19);
  idStr::FreeData(this: &v18);
  return 1;
}


// ========================================================================
// __unwind$226386
// EA  : 0x827E1600
// RVA : 0x007E1600
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226386()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// __unwind$226387
// EA  : 0x827E1628
// RVA : 0x007E1628
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226387()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 112));
}


// ========================================================================
// ??0idDeclParticle@@QAA@XZ
// EA  : 0x827E1658
// RVA : 0x007E1658
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

idDeclParticle *__fastcall idDeclParticle::idDeclParticle(idDeclParticle *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idDeclParticle_vtbl *)&idDeclParticle::`vftable';
  this->stages.list = nullptr;
  this->stages.granularity = 0;
  this->stages.memTag = 79;
  this->stages.listStatic = 0;
  this->stages.size = 0;
  this->stages.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stages);
  this->stageNames.list = nullptr;
  this->stageNames.granularity = 0;
  this->stageNames.memTag = 79;
  this->stageNames.listStatic = 0;
  this->stageNames.size = 0;
  this->stageNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stageNames);
  this->stageInheritNames.list = nullptr;
  this->stageInheritNames.granularity = 0;
  this->stageInheritNames.memTag = 79;
  this->stageInheritNames.listStatic = 0;
  this->stageInheritNames.size = 0;
  this->stageInheritNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stageInheritNames);
  this->tableDecls.list = nullptr;
  this->tableDecls.granularity = 0;
  this->tableDecls.memTag = 79;
  this->tableDecls.listStatic = 0;
  this->tableDecls.size = 0;
  this->tableDecls.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tableDecls);
  this->tables.list = nullptr;
  this->tables.granularity = 0;
  this->tables.memTag = 79;
  this->tables.listStatic = 0;
  this->tables.size = 0;
  this->tables.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tables);
  this->bounds.b[1].z = 0.0;
  this->bounds.b[1].y = 0.0;
  this->bounds.b[1].x = 0.0;
  this->bounds.b[0].z = 0.0;
  this->bounds.b[0].y = 0.0;
  this->bounds.b[0].x = 0.0;
  this->maxSystemDuration = 0;
  this->lodRadius = 0;
  return this;
}


// ========================================================================
// __unwind$226514
// EA  : 0x827E1764
// RVA : 0x007E1764
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226514()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$226515
// EA  : 0x827E178C
// RVA : 0x007E178C
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226515()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 56));
}


// ========================================================================
// __unwind$226516
// EA  : 0x827E17B8
// RVA : 0x007E17B8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226516()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 72));
}


// ========================================================================
// __unwind$226517
// EA  : 0x827E17E4
// RVA : 0x007E17E4
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226517()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 88));
}


// ========================================================================
// __unwind$226518
// EA  : 0x827E1810
// RVA : 0x007E1810
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226518()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 104));
}


// ========================================================================
// ?WriteStage@idDeclParticle@@AAAXPAVidFile@@PBVidParticleStage@@PBD12@Z
// EA  : 0x827E1858
// RVA : 0x007E1858
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void __fastcall idDeclParticle::WriteStage(
        idDeclParticle *this,
        idFile *f,
        __int64 stageName,
        __int64 parentName,
        __int64 a5)
{
  int *v7; // r29
  int v8; // r28
  const char *v9; // r26
  va *v10; // r3
  const char *v11; // r19
  int v12; // r8
  int v13; // r11
  idList<idDeclTable const *,79> *p_tableDecls; // r26
  int v15; // r10
  int v16; // r25
  const idParticleParm *v17; // r24
  __int64 v18; // r6
  __int64 v19; // r10
  __int64 v20; // r8
  va *v21; // r3
  const char *v22; // r9
  int v23; // r7
  int v24; // r11
  char v25; // r8
  int count; // r25
  float *v27; // r10
  float *v28; // r11
  char v29; // r8
  bool v30; // r9
  float *v31; // r11
  int v32; // ctr
  bool v33; // r10
  int v34; // r11
  int v35; // r10
  float *v36; // r11
  float *v37; // r24
  float *v38; // r11
  int v39; // r10
  int v40; // r23
  float *v41; // r24
  int i; // r25
  int v43; // r10
  float *v44; // r11
  float *v45; // r24
  int j; // r25
  int v47; // r25
  double v48; // fp1
  const char *v49; // r5
  double v50; // fp1
  double v51; // fp1
  const char *v52; // r5
  double v53; // fp1
  const char *v54; // r4
  double v55; // fp13
  double v56; // fp11
  const char *v57; // r4
  const char *v58; // r4
  const char *v59; // r25
  const char *v60; // r5
  const char *v61; // r9
  const char *v62; // r8
  const char *v63; // r9
  char v64; // r7
  const char *v65; // r11
  int v66; // [sp+8h] [-1C08h]
  int v67; // [sp+8h] [-1C08h]
  int v68; // [sp+Ch] [-1C04h]
  int v69; // [sp+Ch] [-1C04h]
  int v70; // [sp+10h] [-1C00h]
  int v71; // [sp+10h] [-1C00h]
  int v72; // [sp+14h] [-1BFCh]
  int v73; // [sp+14h] [-1BFCh]
  int v74; // [sp+18h] [-1BF8h]
  int v75; // [sp+18h] [-1BF8h]
  int v76; // [sp+1Ch] [-1BF4h]
  int v77; // [sp+1Ch] [-1BF4h]
  float v78; // [sp+50h] [-1BC0h] BYREF
  float v79; // [sp+54h] [-1BBCh] BYREF
  float v80; // [sp+58h] [-1BB8h] BYREF
  const char *name; // [sp+5Ch] [-1BB4h] BYREF
  bool v82; // [sp+60h] [-1BB0h] BYREF
  bool v83; // [sp+61h] [-1BAFh] BYREF
  idStr v84; // [sp+70h] [-1BA0h] BYREF
  idStr v85; // [sp+90h] [-1B80h] BYREF
  idStr v86; // [sp+B0h] [-1B60h] BYREF
  idStr v87; // [sp+D0h] [-1B40h] BYREF
  idStr v88; // [sp+F0h] [-1B20h] BYREF
  idStr v89; // [sp+110h] [-1B00h] BYREF
  idStr v90; // [sp+130h] [-1AE0h] BYREF
  idStr v91; // [sp+150h] [-1AC0h] BYREF
  idStr v92; // [sp+170h] [-1AA0h] BYREF
  idStr v93; // [sp+190h] [-1A80h] BYREF
  idStr v94; // [sp+1B0h] [-1A60h] BYREF
  idStr v95; // [sp+1D0h] [-1A40h] BYREF
  idStr v96; // [sp+1F0h] [-1A20h] BYREF
  idStr v97; // [sp+210h] [-1A00h] BYREF
  idStr v98; // [sp+230h] [-19E0h] BYREF
  idStr v99; // [sp+250h] [-19C0h] BYREF
  idStr v100; // [sp+270h] [-19A0h] BYREF
  idStr v101; // [sp+290h] [-1980h] BYREF
  idStr v102; // [sp+2B0h] [-1960h] BYREF
  idStr v103; // [sp+2D0h] [-1940h] BYREF
  idStr v104; // [sp+2F0h] [-1920h] BYREF
  idStr v105; // [sp+310h] [-1900h] BYREF
  idStr v106; // [sp+330h] [-18E0h] BYREF
  idStr v107; // [sp+350h] [-18C0h] BYREF
  idStr v108; // [sp+370h] [-18A0h] BYREF
  idStr v109; // [sp+390h] [-1880h] BYREF
  idStr v110; // [sp+3B0h] [-1860h] BYREF
  idStr v111; // [sp+3D0h] [-1840h] BYREF
  idStr v112; // [sp+3F0h] [-1820h] BYREF
  idStr v113; // [sp+410h] [-1800h] BYREF
  idStr v114; // [sp+430h] [-17E0h] BYREF
  idStr v115; // [sp+450h] [-17C0h] BYREF
  idStr v116; // [sp+470h] [-17A0h] BYREF
  idStr v117; // [sp+490h] [-1780h] BYREF
  idStr v118; // [sp+4B0h] [-1760h] BYREF
  idStr v119; // [sp+4D0h] [-1740h] BYREF
  idStr v120; // [sp+4F0h] [-1720h] BYREF
  idStr v121; // [sp+510h] [-1700h] BYREF
  idStr v122; // [sp+530h] [-16E0h] BYREF
  idStr v123; // [sp+550h] [-16C0h] BYREF
  idStr v124; // [sp+570h] [-16A0h] BYREF
  idStr v125; // [sp+590h] [-1680h] BYREF
  idStr v126; // [sp+5B0h] [-1660h] BYREF
  idStr v127; // [sp+5D0h] [-1640h] BYREF
  idStr v128; // [sp+5F0h] [-1620h] BYREF
  idStr v129; // [sp+610h] [-1600h] BYREF
  idStr v130; // [sp+630h] [-15E0h] BYREF
  idStr v131; // [sp+650h] [-15C0h] BYREF
  idStr v132; // [sp+670h] [-15A0h] BYREF
  idStr v133; // [sp+690h] [-1580h] BYREF
  idStr v134; // [sp+6B0h] [-1560h] BYREF
  idStr v135; // [sp+6D0h] [-1540h] BYREF
  idStr v136; // [sp+6F0h] [-1520h] BYREF
  idStr v137; // [sp+710h] [-1500h] BYREF
  idStr v138; // [sp+730h] [-14E0h] BYREF
  idStr v139; // [sp+750h] [-14C0h] BYREF
  idStr v140; // [sp+770h] [-14A0h] BYREF
  idStr v141; // [sp+790h] [-1480h] BYREF
  idStr v142; // [sp+7B0h] [-1460h] BYREF
  idStr v143; // [sp+7D0h] [-1440h] BYREF
  idStr v144; // [sp+7F0h] [-1420h] BYREF
  idStr v145; // [sp+810h] [-1400h] BYREF
  idStr v146; // [sp+830h] [-13E0h] BYREF
  idStr v147; // [sp+850h] [-13C0h] BYREF
  idStr v148; // [sp+870h] [-13A0h] BYREF
  idStr v149; // [sp+890h] [-1380h] BYREF
  idStr v150; // [sp+8B0h] [-1360h] BYREF
  idStr v151; // [sp+8D0h] [-1340h] BYREF
  idStr v152; // [sp+8F0h] [-1320h] BYREF
  idStr v153; // [sp+910h] [-1300h] BYREF
  idStr v154; // [sp+930h] [-12E0h] BYREF
  idStr v155; // [sp+950h] [-12C0h] BYREF
  idStr v156; // [sp+970h] [-12A0h] BYREF
  idStr v157; // [sp+990h] [-1280h] BYREF
  idStr v158; // [sp+9B0h] [-1260h] BYREF
  idStr v159; // [sp+9D0h] [-1240h] BYREF
  idStr v160; // [sp+9F0h] [-1220h] BYREF
  idStr v161; // [sp+A10h] [-1200h] BYREF
  idStr v162; // [sp+A30h] [-11E0h] BYREF
  idStr v163; // [sp+A50h] [-11C0h] BYREF
  idStr v164; // [sp+A70h] [-11A0h] BYREF
  idStr v165; // [sp+A90h] [-1180h] BYREF
  idStr v166; // [sp+AB0h] [-1160h] BYREF
  idStr v167; // [sp+AD0h] [-1140h] BYREF
  idStr v168; // [sp+AF0h] [-1120h] BYREF
  idStr v169; // [sp+B10h] [-1100h] BYREF
  idStr v170; // [sp+B30h] [-10E0h] BYREF
  idStr v171; // [sp+B50h] [-10C0h] BYREF
  va v172; // [sp+B70h] [-10A0h] BYREF

  v7 = (int *)HIDWORD(stageName);
  HIDWORD(stageName) = stageName;
  v8 = HIDWORD(parentName);
  v9 = (const char *)parentName;
  v10 = va::va(
          this: &v172,
          fmt: "\t\"%s\" {\n\n",
          a3: stageName,
          a4: parentName,
          a5,
          a6: v66,
          a7: v68,
          a8: v70,
          a9: v72,
          a10: v74,
          a11: v76);
  f->WriteFloatString(this: f, a2: (const char *)v10);
  if ( idStr::Cmp(s1: v9, s2: &byte_8200D768) != 0 )
  {
    idStr::idStr(this: &v84, text: "inherit");
    idStr::PadLength(this: &v84, newlen: 25);
    f->WriteFloatString(this: f, a2: "\t\t%s\t\"%s\"\n", v84.data, v9);
    idStr::FreeData(this: &v84);
  }
  idStr::idStr(this: &v149, text: "bounds");
  WriteBounds(f, varName: &v149, bounds: (const idBounds *)(v7 + 7));
  idStr::FreeData(this: &v149);
  v11 = "%i";
  v78 = COERCE_FLOAT("%i");
  WriteParticleString<short>(
    f,
    name: "count",
    specifier: "%i",
    value: (const __int16 *)v7 + 38,
    defaultValue: (const __int16 *)(v8 + 76));
  v12 = *(_DWORD *)(v8 + 72);
  v80 = COERCE_FLOAT("%s");
  name = *(const char **)(v12 + 8);
  v79 = *(float *)(v7[18] + 8);
  WriteParticleString<char const *>(
    f,
    name: "material",
    specifier: "%s",
    value: (const char *const *)&v79,
    defaultValue: &name);
  v13 = *v7;
  if ( *v7 != 0 )
  {
    if ( *(_DWORD *)v8 != 0 )
      name = *(const char **)(*(_DWORD *)v8 + 8);
    else
      name = &byte_8200D768;
    v79 = *(float *)(v13 + 8);
    WriteParticleString<char const *>(
      f,
      name: "staticMesh",
      specifier: "%s",
      value: (const char *const *)&v79,
      defaultValue: &name);
  }
  WriteParticleString<short>(
    f,
    name: "cycles",
    specifier: "%i",
    value: (const __int16 *)v7 + 39,
    defaultValue: (const __int16 *)(v8 + 78));
  WriteParticleString<float>(
    f,
    name: "bunching",
    specifier: "%.3f",
    value: (const float *)v7 + 33,
    defaultValue: (const float *)(v8 + 132));
  idStr::idStr(this: &v151, text: &byte_8200D768);
  idStr::idStr(this: &v87, text: &byte_8200D768);
  p_tableDecls = &this->tableDecls;
  WriteParticleParm(
    f,
    name: "offsetX",
    parm: (const idParticleParm *)(v7 + 139),
    defaultParm: (const idParticleParm *)(v8 + 556),
    tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
    info: &v87,
    parentInfo: &v151);
  idStr::FreeData(this: &v87);
  idStr::FreeData(this: &v151);
  idStr::idStr(this: &v131, text: &byte_8200D768);
  idStr::idStr(this: &v89, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "offsetY",
    parm: (const idParticleParm *)(v7 + 144),
    defaultParm: (const idParticleParm *)(v8 + 576),
    tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
    info: &v89,
    parentInfo: &v131);
  idStr::FreeData(this: &v89);
  idStr::FreeData(this: &v131);
  idStr::idStr(this: &v167, text: &byte_8200D768);
  idStr::idStr(this: &v91, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "offsetZ",
    parm: (const idParticleParm *)(v7 + 149),
    defaultParm: (const idParticleParm *)(v8 + 596),
    tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
    info: &v91,
    parentInfo: &v167);
  idStr::FreeData(this: &v91);
  idStr::FreeData(this: &v167);
  WriteParticleString<float>(
    f,
    name: "boundsExpansion",
    specifier: "%.3f",
    value: (const float *)v7 + 43,
    defaultValue: (const float *)(v8 + 172));
  WriteParticleBool(f, name: "randomOnCycle", value: (const bool *)v7 + 176, defaultValue: (const bool *)(v8 + 176));
  idStr::idStr(this: &v133, text: &byte_8200D768);
  idStr::idStr(this: &v93, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "time",
    parm: (const idParticleParm *)(v7 + 21),
    defaultParm: (const idParticleParm *)(v8 + 84),
    tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
    info: &v93,
    parentInfo: &v133);
  idStr::FreeData(this: &v93);
  idStr::FreeData(this: &v133);
  WriteParticleString<float>(
    f,
    name: "timeOffset",
    specifier: "%.3f",
    value: (const float *)v7 + 26,
    defaultValue: (const float *)(v8 + 104));
  WriteParticleString<int>(f, name: "diversity", specifier: "%i", value: v7 + 20, defaultValue: (const int *)(v8 + 80));
  WriteParticleString<float>(
    f,
    name: "useSysTime",
    specifier: "%.3f",
    value: (const float *)v7 + 32,
    defaultValue: (const float *)(v8 + 128));
  WriteParticleString<float>(
    f,
    name: "emissionTime",
    specifier: "%.3f",
    value: (const float *)v7 + 34,
    defaultValue: (const float *)(v8 + 136));
  idStr::idStr(this: &v153, text: &byte_8200D768);
  idStr::idStr(this: &v95, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "deadTime",
    parm: (const idParticleParm *)(v7 + 27),
    defaultParm: (const idParticleParm *)(v8 + 108),
    tableDecls: (idList<idDeclTable const *,5> *)&this->tableDecls,
    info: &v95,
    parentInfo: &v153);
  idStr::FreeData(this: &v95);
  idStr::FreeData(this: &v153);
  v15 = *(_DWORD *)(v8 + 1064);
  v79 = *(float *)&particleCustomDesc[v7[266]].name;
  name = particleCustomDesc[v15].name;
  WriteParticleString<char const *>(
    f,
    name: "customPathType",
    specifier: "%s",
    value: (const char *const *)&v79,
    defaultValue: &name);
  v16 = 0;
  if ( particleCustomDesc[v7[266]].count > 0 )
  {
    v17 = (const idParticleParm *)(v7 + 267);
    do
    {
      idStr::idStr(this: &v135, text: &byte_8200D768);
      idStr::idStr(this: &v97, text: &byte_8200D768);
      HIDWORD(v18) = v16;
      v21 = va::va(
              this: &v172,
              fmt: "customPathParm%d",
              a3: v18,
              a4: v20,
              a5: v19,
              a6: v67,
              a7: v69,
              a8: v71,
              a9: v73,
              a10: v75,
              a11: v77);
      WriteParticleParm(
        f,
        name: v21->buffer,
        parm: v17,
        defaultParm: (const idParticleParm *)((char *)v17 + v8 - (_DWORD)v7),
        tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
        info: &v97,
        parentInfo: &v135);
      idStr::FreeData(this: &v97);
      idStr::FreeData(this: &v135);
      ++v16;
      ++v17;
    }
    while ( v16 < particleCustomDesc[v7[266]].count );
  }
  v22 = particleDistributionDesc[v7[45]].name;
  v79 = *(float *)&particleDistributionDesc[*(_DWORD *)(v8 + 180)].name;
  name = v22;
  WriteParticleString<char const *>(
    f,
    name: "distributionType",
    specifier: "%s",
    value: &name,
    defaultValue: (const char *const *)&v79);
  WriteParticleBool(
    f,
    name: "randomDistribution",
    value: (const bool *)v7 + 244,
    defaultValue: (const bool *)(v8 + 244));
  idStr::idStr(this: &v163, text: &byte_8200D768);
  idStr::idStr(this: &v99, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "distribSizeX",
    parm: (const idParticleParm *)(v7 + 46),
    defaultParm: (const idParticleParm *)(v8 + 184),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v99,
    parentInfo: &v163);
  idStr::FreeData(this: &v99);
  idStr::FreeData(this: &v163);
  idStr::idStr(this: &v137, text: &byte_8200D768);
  idStr::idStr(this: &v101, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "distribSizeY",
    parm: (const idParticleParm *)(v7 + 51),
    defaultParm: (const idParticleParm *)(v8 + 204),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v101,
    parentInfo: &v137);
  idStr::FreeData(this: &v101);
  idStr::FreeData(this: &v137);
  idStr::idStr(this: &v155, text: &byte_8200D768);
  idStr::idStr(this: &v103, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "distribSizeZ",
    parm: (const idParticleParm *)(v7 + 56),
    defaultParm: (const idParticleParm *)(v8 + 224),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v103,
    parentInfo: &v155);
  idStr::FreeData(this: &v103);
  idStr::FreeData(this: &v155);
  idStr::idStr(this: &v139, text: &byte_8200D768);
  idStr::idStr(this: &v105, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "spawnLocX",
    parm: (const idParticleParm *)(v7 + 154),
    defaultParm: (const idParticleParm *)(v8 + 616),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v105,
    parentInfo: &v139);
  idStr::FreeData(this: &v105);
  idStr::FreeData(this: &v139);
  idStr::idStr(this: &v171, text: &byte_8200D768);
  idStr::idStr(this: &v107, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "spawnLocY",
    parm: (const idParticleParm *)(v7 + 159),
    defaultParm: (const idParticleParm *)(v8 + 636),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v107,
    parentInfo: &v171);
  idStr::FreeData(this: &v107);
  idStr::FreeData(this: &v171);
  idStr::idStr(this: &v141, text: &byte_8200D768);
  idStr::idStr(this: &v109, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "spawnLocZ",
    parm: (const idParticleParm *)(v7 + 164),
    defaultParm: (const idParticleParm *)(v8 + 656),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v109,
    parentInfo: &v141);
  idStr::FreeData(this: &v109);
  idStr::FreeData(this: &v141);
  v23 = 0;
  v24 = v7[69];
  v25 = *(_DWORD *)(v8 + 276) != v24;
  count = particleDirectionDesc[v24].count;
  if ( count >= 4 )
  {
    v27 = (float *)(v7 + 72);
    v28 = (float *)(v8 + 280);
    do
    {
      v29 = v25 | (*(float *)((char *)v28 + (_DWORD)v7 - v8) != *v28) | (*(v27 - 1) != v28[1]) | (*v27 != v28[2]);
      v30 = v27[1] != v28[3];
      v23 += 4;
      v28 += 4;
      v25 = v29 | v30;
      v27 += 4;
    }
    while ( v23 < count - 3 );
  }
  if ( v23 < count )
  {
    v31 = (float *)(4 * (v23 + 70) + v8);
    v32 = count - v23;
    do
    {
      v33 = *(float *)((char *)v7 + (_DWORD)v31 - v8) != *v31;
      ++v31;
      v25 |= v33;
      --v32;
    }
    while ( v32 != 0 );
  }
  if ( ((unsigned __int8)(v25
                        | (*((float *)v7 + 74) != *(float *)(v8 + 296))
                        | (*((float *)v7 + 76) != *(float *)(v8 + 304))
                        | (*((float *)v7 + 75) != *(float *)(v8 + 300)))
      | (*((float *)v7 + 77) != *(float *)(v8 + 308))) != 0 )
  {
    f->WriteFloatString(this: f, a2: "\t\tdirection {\n");
    v34 = v7[69];
    if ( v34 != *(_DWORD *)(v8 + 276) )
      f->WriteFloatString(this: f, a2: "\t\t\ttype %s\n", particleDirectionDesc[v34].name);
    v35 = 0;
    if ( count > 0 )
    {
      v36 = (float *)(v8 + 280);
      while ( *(float *)((char *)v7 + (_DWORD)v36 - v8) == *v36 )
      {
        ++v35;
        ++v36;
        if ( v35 >= count )
          goto LABEL_28;
      }
      f->WriteFloatString(this: f, a2: "\t\t\tparms");
      v37 = (float *)(v7 + 69);
      do
      {
        f->WriteFloatString(this: f, a2: " %.3f", (unsigned int)COERCE_UNSIGNED_INT64(*++v37));
        --count;
      }
      while ( count != 0 );
      f->WriteFloatString(this: f, a2: "\n");
    }
LABEL_28:
    v38 = (float *)(v8 + 296);
    v39 = 0;
    v40 = (int)v7 - v8;
    while ( *(float *)((char *)v38 + v40) == *v38 )
    {
      ++v39;
      ++v38;
      if ( v39 >= 2 )
        goto LABEL_35;
    }
    f->WriteFloatString(this: f, a2: "\t\t\tangleOffsetStart");
    v41 = (float *)(v7 + 73);
    for ( i = 2; i != 0; --i )
    {
      ++v41;
      f->WriteFloatString(
        this: f,
        a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(*v41)),
        COERCE_UNSIGNED_INT64(*v41));
    }
    f->WriteFloatString(this: f, a2: "\n");
LABEL_35:
    v43 = 0;
    v44 = (float *)(v8 + 304);
    while ( *(float *)((char *)v44 + v40) == *v44 )
    {
      ++v43;
      ++v44;
      if ( v43 >= 2 )
        goto LABEL_42;
    }
    f->WriteFloatString(this: f, a2: "\t\t\tangleOffsetRange");
    v45 = (float *)(v7 + 75);
    for ( j = 2; j != 0; --j )
      f->WriteFloatString(this: f, a2: " %.3f", (unsigned int)COERCE_UNSIGNED_INT64(*++v45));
    f->WriteFloatString(this: f, a2: "\n");
LABEL_42:
    f->WriteFloatString(this: f, a2: "\t\t}\n");
    v11 = (const char *)LODWORD(v78);
  }
  if ( *((unsigned __int8 *)v7 + 265) != *(unsigned __int8 *)(v8 + 265)
    || v7[62] != *(_DWORD *)(v8 + 248)
    || *((unsigned __int16 *)v7 + 126) != *(unsigned __int16 *)(v8 + 252)
    || *((float *)v7 + 64) != *(float *)(v8 + 256)
    || *((unsigned __int8 *)v7 + 264) != *(unsigned __int8 *)(v8 + 264)
    || *((float *)v7 + 65) != *(float *)(v8 + 260)
    || *((unsigned __int8 *)v7 + 266) != *(unsigned __int8 *)(v8 + 266)
    || *((float *)v7 + 67) != *(float *)(v8 + 268)
    || *((float *)v7 + 68) != *(float *)(v8 + 272) )
  {
    f->WriteFloatString(this: f, a2: "\t\torientation {\n");
    v47 = v7[62];
    if ( v47 != *(_DWORD *)(v8 + 248) )
      f->WriteFloatString(this: f, a2: "\t\t\ttype %s\n", particleOrientationDesc[v47].name);
    v48 = *((float *)v7 + 68);
    if ( v48 != *(float *)(v8 + 272) )
      f->WriteFloatString(this: f, a2: "\t\t\tdepthOffset %.3f\n", LODWORD(v48));
    if ( v47 != 1 && *((unsigned __int8 *)v7 + 265) != *(unsigned __int8 *)(v8 + 265) )
    {
      v49 = "true";
      if ( *((_BYTE *)v7 + 265) == 0 )
        v49 = "false";
      f->WriteFloatString(this: f, a2: "\t\t\tworld %s\n", v49);
    }
    if ( v47 != 0 )
    {
      v50 = *((float *)v7 + 65);
      if ( v50 != *(float *)(v8 + 260) )
        f->WriteFloatString(this: f, a2: (const char *)HIDWORD(v50), LODWORD(v50));
    }
    if ( v47 != 2 && v47 != 1 )
      goto LABEL_79;
    v51 = *((float *)v7 + 64);
    if ( v51 != *(float *)(v8 + 256) )
      f->WriteFloatString(this: f, a2: "\t\t\tsegmentLength %.3f\n", LODWORD(v51));
    if ( *((unsigned __int8 *)v7 + 266) != *(unsigned __int8 *)(v8 + 266) )
    {
      v52 = "true";
      if ( *((_BYTE *)v7 + 266) == 0 )
        v52 = "false";
      f->WriteFloatString(this: f, a2: "\t\t\taimedSafeQuad %s\n", v52);
    }
    if ( *((_BYTE *)v7 + 266) != 0 )
    {
      v53 = *((float *)v7 + 67);
      if ( v53 != *(float *)(v8 + 268) )
        f->WriteFloatString(this: f, a2: "\t\t\taimedSafeQuadAlign %.3f\n", LODWORD(v53));
    }
    if ( v47 == 1 )
    {
      if ( *((__int16 *)v7 + 126) == *(__int16 *)(v8 + 252) )
      {
LABEL_82:
        f->WriteFloatString(this: f, a2: "\t\t}\n");
        goto LABEL_83;
      }
      v54 = "\t\t\tnumTrails %d\n";
    }
    else
    {
LABEL_79:
      if ( v47 != 2 || *((unsigned __int8 *)v7 + 264) == *(unsigned __int8 *)(v8 + 264) )
        goto LABEL_82;
      v54 = "\t\t\torientToVelOnly %s\n";
    }
    f->WriteFloatString(this: f, a2: v54);
    goto LABEL_82;
  }
LABEL_83:
  WriteParticleBool(
    f,
    name: "allowRotDirOverride",
    value: (const bool *)v7 + 880,
    defaultValue: (const bool *)(v8 + 880));
  idStr::idStr(this: &v157, text: &byte_8200D768);
  idStr::idStr(this: &v111, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "angleX",
    parm: (const idParticleParm *)(v7 + 221),
    defaultParm: (const idParticleParm *)(v8 + 884),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v111,
    parentInfo: &v157);
  idStr::FreeData(this: &v111);
  idStr::FreeData(this: &v157);
  idStr::idStr(this: &v143, text: &byte_8200D768);
  idStr::idStr(this: &v113, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "angleY",
    parm: (const idParticleParm *)(v7 + 226),
    defaultParm: (const idParticleParm *)(v8 + 904),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v113,
    parentInfo: &v143);
  idStr::FreeData(this: &v113);
  idStr::FreeData(this: &v143);
  idStr::idStr(this: &v165, text: &byte_8200D768);
  idStr::idStr(this: &v115, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "angleZ",
    parm: (const idParticleParm *)(v7 + 231),
    defaultParm: (const idParticleParm *)(v8 + 924),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v115,
    parentInfo: &v165);
  idStr::FreeData(this: &v115);
  idStr::FreeData(this: &v165);
  v55 = *((float *)v7 + 236);
  v78 = *(float *)(v8 + 944);
  v79 = v55;
  WriteParticleString<float>(f, name: "pivotX", specifier: "%.3f", value: &v79, defaultValue: &v78);
  v56 = *((float *)v7 + 237);
  v78 = *(float *)(v8 + 948);
  v79 = v56;
  WriteParticleString<float>(f, name: "pivotY", specifier: "%.3f", value: &v79, defaultValue: &v78);
  idStr::idStr(this: &v145, text: &byte_8200D768);
  idStr::idStr(this: &v117, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "speedX",
    parm: (const idParticleParm *)(v7 + 87),
    defaultParm: (const idParticleParm *)(v8 + 348),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v117,
    parentInfo: &v145);
  idStr::FreeData(this: &v117);
  idStr::FreeData(this: &v145);
  idStr::idStr(this: &v159, text: &byte_8200D768);
  idStr::idStr(this: &v119, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "speedY",
    parm: (const idParticleParm *)(v7 + 92),
    defaultParm: (const idParticleParm *)(v8 + 368),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v119,
    parentInfo: &v159);
  idStr::FreeData(this: &v119);
  idStr::FreeData(this: &v159);
  idStr::idStr(this: &v147, text: &byte_8200D768);
  idStr::idStr(this: &v121, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "speedZ",
    parm: (const idParticleParm *)(v7 + 97),
    defaultParm: (const idParticleParm *)(v8 + 388),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v121,
    parentInfo: &v147);
  idStr::FreeData(this: &v121);
  idStr::FreeData(this: &v147);
  idStr::idStr(this: &v169, text: &byte_8200D768);
  idStr::idStr(this: &v123, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "rotationSpeedX",
    parm: (const idParticleParm *)v7 + 41,
    defaultParm: (const idParticleParm *)(v8 + 820),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v123,
    parentInfo: &v169);
  idStr::FreeData(this: &v123);
  idStr::FreeData(this: &v169);
  idStr::idStr(this: &v85, text: &byte_8200D768);
  idStr::idStr(this: &v125, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "rotationSpeedY",
    parm: (const idParticleParm *)v7 + 42,
    defaultParm: (const idParticleParm *)(v8 + 840),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v125,
    parentInfo: &v85);
  idStr::FreeData(this: &v125);
  idStr::FreeData(this: &v85);
  idStr::idStr(this: &v161, text: &byte_8200D768);
  idStr::idStr(this: &v127, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "rotationSpeedZ",
    parm: (const idParticleParm *)v7 + 43,
    defaultParm: (const idParticleParm *)(v8 + 860),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v127,
    parentInfo: &v161);
  idStr::FreeData(this: &v127);
  idStr::FreeData(this: &v161);
  WriteParticleBool(f, name: "worldAcceleration", value: (const bool *)v7 + 468, defaultValue: (const bool *)(v8 + 468));
  idStr::idStr(this: &v86, text: &byte_8200D768);
  idStr::idStr(this: &v129, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "accelerationX",
    parm: (const idParticleParm *)(v7 + 102),
    defaultParm: (const idParticleParm *)(v8 + 408),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v129,
    parentInfo: &v86);
  idStr::FreeData(this: &v129);
  idStr::FreeData(this: &v86);
  idStr::idStr(this: &v90, text: &byte_8200D768);
  idStr::idStr(this: &v88, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "accelerationY",
    parm: (const idParticleParm *)(v7 + 107),
    defaultParm: (const idParticleParm *)(v8 + 428),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v88,
    parentInfo: &v90);
  idStr::FreeData(this: &v88);
  idStr::FreeData(this: &v90);
  idStr::idStr(this: &v94, text: &byte_8200D768);
  idStr::idStr(this: &v92, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "accelerationZ",
    parm: (const idParticleParm *)(v7 + 112),
    defaultParm: (const idParticleParm *)(v8 + 448),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v92,
    parentInfo: &v94);
  idStr::FreeData(this: &v92);
  idStr::FreeData(this: &v94);
  v57 = "world";
  if ( *(_BYTE *)(v8 + 492) == 0 )
    v57 = &byte_8200D768;
  idStr::idStr(this: &v98, text: v57);
  v58 = "world";
  if ( *((_BYTE *)v7 + 492) == 0 )
    v58 = &byte_8200D768;
  idStr::idStr(this: &v96, text: v58);
  WriteParticleParm(
    f,
    name: "gravity",
    parm: (const idParticleParm *)(v7 + 118),
    defaultParm: (const idParticleParm *)(v8 + 472),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v96,
    parentInfo: &v98);
  idStr::FreeData(this: &v96);
  idStr::FreeData(this: &v98);
  idStr::idStr(this: &v102, text: &byte_8200D768);
  idStr::idStr(this: &v100, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "windBias",
    parm: (const idParticleParm *)(v7 + 37),
    defaultParm: (const idParticleParm *)(v8 + 148),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v100,
    parentInfo: &v102);
  idStr::FreeData(this: &v100);
  idStr::FreeData(this: &v102);
  idStr::idStr(this: &v106, text: &byte_8200D768);
  idStr::idStr(this: &v104, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "frictionX",
    parm: (const idParticleParm *)(v7 + 124),
    defaultParm: (const idParticleParm *)(v8 + 496),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v104,
    parentInfo: &v106);
  idStr::FreeData(this: &v104);
  idStr::FreeData(this: &v106);
  idStr::idStr(this: &v110, text: &byte_8200D768);
  idStr::idStr(this: &v108, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "frictionY",
    parm: (const idParticleParm *)(v7 + 129),
    defaultParm: (const idParticleParm *)(v8 + 516),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v108,
    parentInfo: &v110);
  idStr::FreeData(this: &v108);
  idStr::FreeData(this: &v110);
  idStr::idStr(this: &v114, text: &byte_8200D768);
  idStr::idStr(this: &v112, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "frictionZ",
    parm: (const idParticleParm *)(v7 + 134),
    defaultParm: (const idParticleParm *)(v8 + 536),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v112,
    parentInfo: &v114);
  idStr::FreeData(this: &v112);
  idStr::FreeData(this: &v114);
  idStr::idStr(this: &v118, text: &byte_8200D768);
  idStr::idStr(this: &v116, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "sizeX",
    parm: (const idParticleParm *)(v7 + 238),
    defaultParm: (const idParticleParm *)(v8 + 952),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v116,
    parentInfo: &v118);
  idStr::FreeData(this: &v116);
  idStr::FreeData(this: &v118);
  idStr::idStr(this: &v122, text: &byte_8200D768);
  idStr::idStr(this: &v120, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "sizeY",
    parm: (const idParticleParm *)(v7 + 243),
    defaultParm: (const idParticleParm *)(v8 + 972),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v120,
    parentInfo: &v122);
  idStr::FreeData(this: &v120);
  idStr::FreeData(this: &v122);
  idStr::idStr(this: &v126, text: &byte_8200D768);
  idStr::idStr(this: &v124, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "sizeZ",
    parm: (const idParticleParm *)(v7 + 248),
    defaultParm: (const idParticleParm *)(v8 + 992),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v124,
    parentInfo: &v126);
  idStr::FreeData(this: &v124);
  idStr::FreeData(this: &v126);
  idStr::idStr(this: &v130, text: &byte_8200D768);
  idStr::idStr(this: &v128, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "aspect",
    parm: (const idParticleParm *)(v7 + 253),
    defaultParm: (const idParticleParm *)(v8 + 1012),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v128,
    parentInfo: &v130);
  idStr::FreeData(this: &v128);
  idStr::FreeData(this: &v130);
  v59 = (const char *)LODWORD(v80);
  v60 = (const char *)LODWORD(v80);
  v61 = particleTexFlipTypeDesc[v7[35]].name;
  v80 = *(float *)&particleTexFlipTypeDesc[*(_DWORD *)(v8 + 140)].name;
  v78 = *(float *)&v61;
  WriteParticleString<char const *>(
    f,
    name: "rndFlipTexS",
    specifier: v60,
    value: (const char *const *)&v78,
    defaultValue: (const char *const *)&v80);
  v62 = particleTexFlipTypeDesc[v7[36]].name;
  v80 = *(float *)&particleTexFlipTypeDesc[*(_DWORD *)(v8 + 144)].name;
  v78 = *(float *)&v62;
  WriteParticleString<char const *>(
    f,
    name: "rndFlipTexT",
    specifier: v59,
    value: (const char *const *)&v78,
    defaultValue: (const char *const *)&v80);
  v63 = particleAnimationTypeDesc[v7[258]].name;
  v80 = *(float *)&particleAnimationTypeDesc[*(_DWORD *)(v8 + 1032)].name;
  v78 = *(float *)&v63;
  WriteParticleString<char const *>(
    f,
    name: "animationType",
    specifier: v59,
    value: (const char *const *)&v78,
    defaultValue: (const char *const *)&v80);
  WriteParticleString<unsigned short>(
    f,
    name: "animationFrames",
    specifier: v11,
    value: (const unsigned __int16 *)v7 + 518,
    defaultValue: (const unsigned __int16 *)(v8 + 1036));
  WriteParticleString<unsigned short>(
    f,
    name: "animationRows",
    specifier: v11,
    value: (const unsigned __int16 *)v7 + 519,
    defaultValue: (const unsigned __int16 *)(v8 + 1038));
  idStr::idStr(this: &v134, text: &byte_8200D768);
  idStr::idStr(this: &v132, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "animationRate",
    parm: (const idParticleParm *)v7 + 52,
    defaultParm: (const idParticleParm *)(v8 + 1040),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v132,
    parentInfo: &v134);
  idStr::FreeData(this: &v132);
  idStr::FreeData(this: &v134);
  WriteParticleString<short>(
    f,
    name: "animationStartFrame",
    specifier: v11,
    value: (const __int16 *)v7 + 530,
    defaultValue: (const __int16 *)(v8 + 1060));
  WriteParticleBool(f, name: "useRndAnimRow", value: (const bool *)v7 + 1062, defaultValue: (const bool *)(v8 + 1062));
  v64 = _cntlzw(*((unsigned __int8 *)v7 + 1063));
  v83 = (_cntlzw(*(unsigned __int8 *)(v8 + 1063)) & 0x20) != 0;
  v82 = (v64 & 0x20) != 0;
  WriteParticleBool(f, name: "skipAnimCrossFade", value: &v82, defaultValue: &v83);
  WriteParticleString<float>(
    f,
    name: "fadeIn",
    specifier: "%.3f",
    value: (const float *)v7 + 193,
    defaultValue: (const float *)(v8 + 772));
  WriteParticleString<float>(
    f,
    name: "fadeOut",
    specifier: "%.3f",
    value: (const float *)v7 + 194,
    defaultValue: (const float *)(v8 + 776));
  WriteParticleString<float>(
    f,
    name: "fadeIndex",
    specifier: "%.3f",
    value: (const float *)v7 + 195,
    defaultValue: (const float *)(v8 + 780));
  WriteParticleVec4(f, name: "fadeColor", value: (const idVec4 *)(v7 + 189), defaultValue: (const idVec4 *)(v8 + 756));
  idStr::idStr(this: &v138, text: &byte_8200D768);
  idStr::idStr(this: &v136, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "colorR",
    parm: (const idParticleParm *)(v7 + 169),
    defaultParm: (const idParticleParm *)(v8 + 676),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v136,
    parentInfo: &v138);
  idStr::FreeData(this: &v136);
  idStr::FreeData(this: &v138);
  idStr::idStr(this: &v142, text: &byte_8200D768);
  idStr::idStr(this: &v140, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "colorG",
    parm: (const idParticleParm *)(v7 + 174),
    defaultParm: (const idParticleParm *)(v8 + 696),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v140,
    parentInfo: &v142);
  idStr::FreeData(this: &v140);
  idStr::FreeData(this: &v142);
  idStr::idStr(this: &v146, text: &byte_8200D768);
  idStr::idStr(this: &v144, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "colorB",
    parm: (const idParticleParm *)(v7 + 179),
    defaultParm: (const idParticleParm *)(v8 + 716),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v144,
    parentInfo: &v146);
  idStr::FreeData(this: &v144);
  idStr::FreeData(this: &v146);
  idStr::idStr(this: &v150, text: &byte_8200D768);
  idStr::idStr(this: &v148, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "colorA",
    parm: (const idParticleParm *)(v7 + 184),
    defaultParm: (const idParticleParm *)(v8 + 736),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v148,
    parentInfo: &v150);
  idStr::FreeData(this: &v148);
  idStr::FreeData(this: &v150);
  idStr::idStr(this: &v154, text: &byte_8200D768);
  idStr::idStr(this: &v152, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "brightness",
    parm: (const idParticleParm *)(v7 + 197),
    defaultParm: (const idParticleParm *)(v8 + 788),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v152,
    parentInfo: &v154);
  idStr::FreeData(this: &v152);
  idStr::FreeData(this: &v154);
  idStr::idStr(this: &v158, text: &byte_8200D768);
  idStr::idStr(this: &v156, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "genericParmR",
    parm: (const idParticleParm *)(v7 + 292),
    defaultParm: (const idParticleParm *)(v8 + 1168),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v156,
    parentInfo: &v158);
  idStr::FreeData(this: &v156);
  idStr::FreeData(this: &v158);
  idStr::idStr(this: &v162, text: &byte_8200D768);
  idStr::idStr(this: &v160, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "genericParmG",
    parm: (const idParticleParm *)(v7 + 297),
    defaultParm: (const idParticleParm *)(v8 + 1188),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v160,
    parentInfo: &v162);
  idStr::FreeData(this: &v160);
  idStr::FreeData(this: &v162);
  idStr::idStr(this: &v166, text: &byte_8200D768);
  idStr::idStr(this: &v164, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "genericParmB",
    parm: (const idParticleParm *)(v7 + 302),
    defaultParm: (const idParticleParm *)(v8 + 1208),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v164,
    parentInfo: &v166);
  idStr::FreeData(this: &v164);
  idStr::FreeData(this: &v166);
  idStr::idStr(this: &v170, text: &byte_8200D768);
  idStr::idStr(this: &v168, text: &byte_8200D768);
  WriteParticleParm(
    f,
    name: "genericParmA",
    parm: (const idParticleParm *)(v7 + 307),
    defaultParm: (const idParticleParm *)(v8 + 1228),
    tableDecls: (idList<idDeclTable const *,5> *)p_tableDecls,
    info: &v168,
    parentInfo: &v170);
  idStr::FreeData(this: &v168);
  idStr::FreeData(this: &v170);
  v80 = (float)1.0 / *((float *)v7 + 196);
  WriteParticleString<float>(
    f,
    name: "softParticleAlphaScale",
    specifier: "%.3f",
    value: &v80,
    defaultValue: (const float *)(v8 + 784));
  WriteParticleBool(f, name: "useGlobalShadows", value: (const bool *)v7 + 808, defaultValue: (const bool *)(v8 + 808));
  WriteParticleString<float>(
    f,
    name: "minShadowVal",
    specifier: "%.3f",
    value: (const float *)v7 + 203,
    defaultValue: (const float *)(v8 + 812));
  WriteParticleString<float>(
    f,
    name: "entityColorBlendVal",
    specifier: "%.3f",
    value: (const float *)v7 + 204,
    defaultValue: (const float *)(v8 + 816));
  WriteParticleString<short>(
    f,
    name: "lodCount",
    specifier: v11,
    value: (const __int16 *)v7 + 629,
    defaultValue: (const __int16 *)(v8 + 1258));
  WriteParticleString<float>(
    f,
    name: "lodScale",
    specifier: "%.3f",
    value: (const float *)v7 + 312,
    defaultValue: (const float *)(v8 + 1248));
  WriteParticleString<float>(
    f,
    name: "lodLerpAmount",
    specifier: "%.3f",
    value: (const float *)v7 + 313,
    defaultValue: (const float *)(v8 + 1252));
  WriteParticleString<short>(
    f,
    name: "lodRadius",
    specifier: v11,
    value: (const __int16 *)v7 + 628,
    defaultValue: (const __int16 *)(v8 + 1256));
  v65 = particleSortTypeDesc[v7[42]].name;
  v80 = *(float *)&particleSortTypeDesc[*(_DWORD *)(v8 + 168)].name;
  v78 = *(float *)&v65;
  WriteParticleString<char const *>(
    f,
    name: "sortType",
    specifier: v59,
    value: (const char *const *)&v78,
    defaultValue: (const char *const *)&v80);
  f->WriteFloatString(this: f, a2: "\n\t}\n");
}


// ========================================================================
// __unwind$226792
// EA  : 0x827E3420
// RVA : 0x007E3420
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226792()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 112));
}


// ========================================================================
// __unwind$226793
// EA  : 0x827E3448
// RVA : 0x007E3448
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226793()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2192));
}


// ========================================================================
// __unwind$226794
// EA  : 0x827E3470
// RVA : 0x007E3470
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226794()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2256));
}


// ========================================================================
// __unwind$226795
// EA  : 0x827E3498
// RVA : 0x007E3498
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226795()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 208));
}


// ========================================================================
// __unwind$226796
// EA  : 0x827E34C0
// RVA : 0x007E34C0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226796()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1616));
}


// ========================================================================
// __unwind$226797
// EA  : 0x827E34E8
// RVA : 0x007E34E8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226797()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 272));
}


// ========================================================================
// __unwind$226798
// EA  : 0x827E3510
// RVA : 0x007E3510
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226798()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2768));
}


// ========================================================================
// __unwind$226799
// EA  : 0x827E3538
// RVA : 0x007E3538
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226799()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 336));
}


// ========================================================================
// __unwind$226800
// EA  : 0x827E3560
// RVA : 0x007E3560
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226800()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1680));
}


// ========================================================================
// __unwind$226801
// EA  : 0x827E3588
// RVA : 0x007E3588
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226801()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 400));
}


// ========================================================================
// __unwind$226802
// EA  : 0x827E35B0
// RVA : 0x007E35B0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226802()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2320));
}


// ========================================================================
// __unwind$226803
// EA  : 0x827E35D8
// RVA : 0x007E35D8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226803()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 464));
}


// ========================================================================
// __unwind$226804
// EA  : 0x827E3600
// RVA : 0x007E3600
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226804()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1744));
}


// ========================================================================
// __unwind$226805
// EA  : 0x827E3628
// RVA : 0x007E3628
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226805()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 528));
}


// ========================================================================
// __unwind$226806
// EA  : 0x827E3650
// RVA : 0x007E3650
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226806()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2640));
}


// ========================================================================
// __unwind$226807
// EA  : 0x827E3678
// RVA : 0x007E3678
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226807()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 592));
}


// ========================================================================
// __unwind$226808
// EA  : 0x827E36A0
// RVA : 0x007E36A0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226808()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1808));
}


// ========================================================================
// __unwind$226809
// EA  : 0x827E36C8
// RVA : 0x007E36C8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226809()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 656));
}


// ========================================================================
// __unwind$226810
// EA  : 0x827E36F0
// RVA : 0x007E36F0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226810()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2384));
}


// ========================================================================
// __unwind$226811
// EA  : 0x827E3718
// RVA : 0x007E3718
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226811()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 720));
}


// ========================================================================
// __unwind$226812
// EA  : 0x827E3740
// RVA : 0x007E3740
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226812()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1872));
}


// ========================================================================
// __unwind$226813
// EA  : 0x827E3768
// RVA : 0x007E3768
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226813()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 784));
}


// ========================================================================
// __unwind$226814
// EA  : 0x827E3790
// RVA : 0x007E3790
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226814()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2896));
}


// ========================================================================
// __unwind$226815
// EA  : 0x827E37B8
// RVA : 0x007E37B8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226815()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 848));
}


// ========================================================================
// __unwind$226816
// EA  : 0x827E37E0
// RVA : 0x007E37E0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226816()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1936));
}


// ========================================================================
// __unwind$226817
// EA  : 0x827E3808
// RVA : 0x007E3808
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226817()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 912));
}


// ========================================================================
// __unwind$226818
// EA  : 0x827E3830
// RVA : 0x007E3830
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226818()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2448));
}


// ========================================================================
// __unwind$226819
// EA  : 0x827E3858
// RVA : 0x007E3858
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226819()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 976));
}


// ========================================================================
// __unwind$226820
// EA  : 0x827E3880
// RVA : 0x007E3880
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226820()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2000));
}


// ========================================================================
// __unwind$226821
// EA  : 0x827E38A8
// RVA : 0x007E38A8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226821()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1040));
}


// ========================================================================
// __unwind$226822
// EA  : 0x827E38D0
// RVA : 0x007E38D0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226822()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2704));
}


// ========================================================================
// __unwind$226823
// EA  : 0x827E38F8
// RVA : 0x007E38F8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226823()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1104));
}


// ========================================================================
// __unwind$226824
// EA  : 0x827E3920
// RVA : 0x007E3920
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226824()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2064));
}


// ========================================================================
// __unwind$226825
// EA  : 0x827E3948
// RVA : 0x007E3948
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226825()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1168));
}


// ========================================================================
// __unwind$226826
// EA  : 0x827E3970
// RVA : 0x007E3970
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226826()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2512));
}


// ========================================================================
// __unwind$226827
// EA  : 0x827E3998
// RVA : 0x007E3998
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226827()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1232));
}


// ========================================================================
// __unwind$226828
// EA  : 0x827E39C0
// RVA : 0x007E39C0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226828()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2128));
}


// ========================================================================
// __unwind$226829
// EA  : 0x827E39E8
// RVA : 0x007E39E8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226829()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1296));
}


// ========================================================================
// __unwind$226830
// EA  : 0x827E3A10
// RVA : 0x007E3A10
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226830()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2832));
}


// ========================================================================
// __unwind$226831
// EA  : 0x827E3A38
// RVA : 0x007E3A38
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226831()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1360));
}


// ========================================================================
// __unwind$226832
// EA  : 0x827E3A60
// RVA : 0x007E3A60
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226832()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 144));
}


// ========================================================================
// __unwind$226833
// EA  : 0x827E3A88
// RVA : 0x007E3A88
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226833()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1424));
}


// ========================================================================
// __unwind$226834
// EA  : 0x827E3AB0
// RVA : 0x007E3AB0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226834()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2576));
}


// ========================================================================
// __unwind$226835
// EA  : 0x827E3AD8
// RVA : 0x007E3AD8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226835()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1488));
}


// ========================================================================
// __unwind$226836
// EA  : 0x827E3B00
// RVA : 0x007E3B00
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226836()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 176));
}


// ========================================================================
// __unwind$226837
// EA  : 0x827E3B28
// RVA : 0x007E3B28
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226837()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1552));
}


// ========================================================================
// __unwind$226838
// EA  : 0x827E3B50
// RVA : 0x007E3B50
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226838()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 304));
}


// ========================================================================
// __unwind$226839
// EA  : 0x827E3B78
// RVA : 0x007E3B78
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226839()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 240));
}


// ========================================================================
// __unwind$226840
// EA  : 0x827E3BA0
// RVA : 0x007E3BA0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226840()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 432));
}


// ========================================================================
// __unwind$226841_0
// EA  : 0x827E3BC8
// RVA : 0x007E3BC8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226841_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 368));
}


// ========================================================================
// __unwind$226842_0
// EA  : 0x827E3BF0
// RVA : 0x007E3BF0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226842_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 560));
}


// ========================================================================
// __unwind$226843_0
// EA  : 0x827E3C18
// RVA : 0x007E3C18
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226843_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 496));
}


// ========================================================================
// __unwind$226844_0
// EA  : 0x827E3C40
// RVA : 0x007E3C40
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226844_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 688));
}


// ========================================================================
// __unwind$226845
// EA  : 0x827E3C68
// RVA : 0x007E3C68
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226845()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 624));
}


// ========================================================================
// __unwind$226846
// EA  : 0x827E3C90
// RVA : 0x007E3C90
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226846()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 816));
}


// ========================================================================
// __unwind$226847_0
// EA  : 0x827E3CB8
// RVA : 0x007E3CB8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226847_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 752));
}


// ========================================================================
// __unwind$226848_1
// EA  : 0x827E3CE0
// RVA : 0x007E3CE0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226848_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 944));
}


// ========================================================================
// __unwind$226849
// EA  : 0x827E3D08
// RVA : 0x007E3D08
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226849()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 880));
}


// ========================================================================
// __unwind$226850
// EA  : 0x827E3D30
// RVA : 0x007E3D30
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226850()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1072));
}


// ========================================================================
// __unwind$226851
// EA  : 0x827E3D58
// RVA : 0x007E3D58
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226851()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1008));
}


// ========================================================================
// __unwind$226852
// EA  : 0x827E3D80
// RVA : 0x007E3D80
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226852()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1200));
}


// ========================================================================
// __unwind$226853
// EA  : 0x827E3DA8
// RVA : 0x007E3DA8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226853()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1136));
}


// ========================================================================
// __unwind$226854
// EA  : 0x827E3DD0
// RVA : 0x007E3DD0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226854()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1328));
}


// ========================================================================
// __unwind$226855
// EA  : 0x827E3DF8
// RVA : 0x007E3DF8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226855()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1264));
}


// ========================================================================
// __unwind$226856
// EA  : 0x827E3E20
// RVA : 0x007E3E20
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226856()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1456));
}


// ========================================================================
// __unwind$226857
// EA  : 0x827E3E48
// RVA : 0x007E3E48
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226857()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1392));
}


// ========================================================================
// __unwind$226858
// EA  : 0x827E3E70
// RVA : 0x007E3E70
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226858()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1584));
}


// ========================================================================
// __unwind$226859
// EA  : 0x827E3E98
// RVA : 0x007E3E98
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226859()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1520));
}


// ========================================================================
// __unwind$226860
// EA  : 0x827E3EC0
// RVA : 0x007E3EC0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226860()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1712));
}


// ========================================================================
// __unwind$226861
// EA  : 0x827E3EE8
// RVA : 0x007E3EE8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226861()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1648));
}


// ========================================================================
// __unwind$226862
// EA  : 0x827E3F10
// RVA : 0x007E3F10
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226862()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1840));
}


// ========================================================================
// __unwind$226863
// EA  : 0x827E3F38
// RVA : 0x007E3F38
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226863()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1776));
}


// ========================================================================
// __unwind$226864
// EA  : 0x827E3F60
// RVA : 0x007E3F60
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226864()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1968));
}


// ========================================================================
// __unwind$226865
// EA  : 0x827E3F88
// RVA : 0x007E3F88
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226865()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 1904));
}


// ========================================================================
// __unwind$226866
// EA  : 0x827E3FB0
// RVA : 0x007E3FB0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226866()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2096));
}


// ========================================================================
// __unwind$226867
// EA  : 0x827E3FD8
// RVA : 0x007E3FD8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226867()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2032));
}


// ========================================================================
// __unwind$226868
// EA  : 0x827E4000
// RVA : 0x007E4000
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226868()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2224));
}


// ========================================================================
// __unwind$226869
// EA  : 0x827E4028
// RVA : 0x007E4028
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226869()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2160));
}


// ========================================================================
// __unwind$226870
// EA  : 0x827E4050
// RVA : 0x007E4050
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226870()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2352));
}


// ========================================================================
// __unwind$226871
// EA  : 0x827E4078
// RVA : 0x007E4078
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226871()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2288));
}


// ========================================================================
// __unwind$226872
// EA  : 0x827E40A0
// RVA : 0x007E40A0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226872()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2480));
}


// ========================================================================
// __unwind$226873
// EA  : 0x827E40C8
// RVA : 0x007E40C8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226873()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2416));
}


// ========================================================================
// __unwind$226874
// EA  : 0x827E40F0
// RVA : 0x007E40F0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226874()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2608));
}


// ========================================================================
// __unwind$226875
// EA  : 0x827E4118
// RVA : 0x007E4118
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226875()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2544));
}


// ========================================================================
// __unwind$226876
// EA  : 0x827E4140
// RVA : 0x007E4140
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226876()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2736));
}


// ========================================================================
// __unwind$226877
// EA  : 0x827E4168
// RVA : 0x007E4168
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226877()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2672));
}


// ========================================================================
// __unwind$226878_0
// EA  : 0x827E4190
// RVA : 0x007E4190
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226878_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2864));
}


// ========================================================================
// __unwind$226879
// EA  : 0x827E41B8
// RVA : 0x007E41B8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_226879()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7184 + 2800));
}


// ========================================================================
// ?RebuildTextSource@idDeclParticle@@UAA_NXZ
// EA  : 0x827E41E8
// RVA : 0x007E41E8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

int __fastcall idDeclParticle::RebuildTextSource(idDeclParticle *this)
{
  const idLookupTable *Tables; // r3
  char v3; // r11
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  int v7; // r28
  int v8; // r29
  char *str; // r11
  char v10; // r11
  bool v11; // zf
  va *v12; // r3
  __int64 v13; // r8
  __int64 v14; // r10
  __int64 v15; // r6
  int v17; // [sp+8h] [-16E8h]
  int v18; // [sp+Ch] [-16E4h]
  int v19; // [sp+10h] [-16E0h]
  int v20; // [sp+14h] [-16DCh]
  int v21; // [sp+18h] [-16D8h]
  int v22; // [sp+1Ch] [-16D4h]
  idStr v23; // [sp+50h] [-16A0h] BYREF
  idFile_Memory v24; // [sp+70h] [-1680h] BYREF
  idParticleStage v25; // [sp+1C0h] [-1530h] BYREF
  va v26; // [sp+6B0h] [-1040h] BYREF

  idFile_Memory::idFile_Memory(this: &v24);
  idFile::WriteFloatString(this: &v24, fmt: "{\n");
  idParticleStage::idParticleStage(this: &v25);
  Tables = idDeclParticle::GetTables(this);
  idParticleStage::Default(this: &v25, tables: Tables);
  if ( this->bounds.b[0].x != 0.0
    || this->bounds.b[1].x != 0.0
    || this->bounds.b[0].y != 0.0
    || this->bounds.b[1].y != 0.0
    || this->bounds.b[0].z != 0.0
    || (v3 = 1, this->bounds.b[1].z != 0.0) )
  {
    v3 = 0;
  }
  if ( v3 != 0 )
  {
    idLib::Warning(fmt: "Invalid bounds for %s!", this->name.str);
  }
  else
  {
    idStr::idStr(this: &v23, text: "bounds");
    WriteBounds(f: &v24, varName: &v23, bounds: &this->bounds);
    idStr::FreeData(this: &v23);
  }
  v7 = 0;
  if ( this->stages.num > 0 )
  {
    v8 = 0;
    do
    {
      LODWORD(v4) = &byte_8200D768;
      str = (char *)this->stageNames.list[v8].str;
      if ( str == &byte_8200D768 || (v11 = *str != 0, v10 = 0, !v11) )
        v10 = 1;
      if ( v10 != 0 )
      {
        HIDWORD(v6) = v7;
        v12 = va::va(
                this: &v26,
                fmt: "stage%d",
                a3: v6,
                a4: v5,
                a5: v4,
                a6: v17,
                a7: v18,
                a8: v19,
                a9: v20,
                a10: v21,
                a11: v22);
        idAtomicString::Set(this: &this->stageNames.list[v8], str_: v12->buffer);
      }
      HIDWORD(v13) = idDeclParticle::FindStageByName(this, name: this->stageInheritNames.list[v8].str);
      if ( HIDWORD(v13) == 0 )
        HIDWORD(v13) = &v25;
      LODWORD(v14) = this->stageNames.list;
      HIDWORD(v14) = this->stages.list;
      LODWORD(v13) = this->stageInheritNames.list[v8].str;
      LODWORD(v15) = *(_DWORD *)(v14 + v8 * 4);
      HIDWORD(v15) = *(_DWORD *)(v8 * 4 + HIDWORD(v14));
      idDeclParticle::WriteStage(this, f: &v24, stageName: v15, parentName: v13, a5: v14);
      LODWORD(v5) = this->stages.num;
      ++v7;
      ++v8;
    }
    while ( v7 < (int)v5 );
  }
  idFile::WriteFloatString(this: &v24, fmt: "}");
  idDecl::SetText(this: &this->idDecl, text: v24.filePtr, length: 0);
  idFile_Memory::~idFile_Memory(this: &v24);
  return 1;
}


// ========================================================================
// __unwind$227998
// EA  : 0x827E43D8
// RVA : 0x007E43D8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_227998()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 5872 + 112));
}


// ========================================================================
// __unwind$227999
// EA  : 0x827E4400
// RVA : 0x007E4400
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_227999()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5872 + 80));
}


// ========================================================================
// ?Parse@idDeclParticle@@UAAXAAVidParser@@@Z
// EA  : 0x827E46D8
// RVA : 0x007E46D8
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void __fastcall idDeclParticle::Parse(idDeclParticle *this, idParser *src)
{
  int v2; // r30
  int len; // r23
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  int num; // r11
  int v11; // r10
  idParticleStage **list; // r9
  __int16 radius; // r7
  int v14; // [sp+8h] [-138h]
  int v15; // [sp+Ch] [-134h]
  idAtomicString v16; // [sp+50h] [-F0h] BYREF
  idAtomicString v17; // [sp+54h] [-ECh] BYREF
  idParticleStage *v18; // [sp+58h] [-E8h] BYREF
  idStr v19; // [sp+60h] [-E0h] BYREF
  idToken v20; // [sp+80h] [-C0h] BYREF
  idStr v21[3]; // [sp+D0h] [-70h] BYREF

  v2 = 0;
  v20.len = 0;
  v20.allocedAndFlag = 20;
  v20.floatvalue = -3.4028235e38;
  v20.data = v20.baseBuffer;
  v20.baseBuffer[0] = 0;
  v20.intvalue = 0;
  memset(&v20.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadToken(this: src, token: &v20) )
  {
    while ( idStr::Icmp(s1: v20.data, s2: "}") != 0 )
    {
      if ( idStr::Icmp(s1: v20.data, s2: "bounds") != 0 )
      {
        v19.allocedAndFlag = 20;
        v19.len = 0;
        v19.data = v19.baseBuffer;
        v19.baseBuffer[0] = 0;
        if ( v20.type == 1 )
        {
          len = v20.len;
          idStr::EnsureAlloced(this: &v19, amount: v20.len + 1, keepold: false, geometricGrowth: false);
          memcpy(Dst: v19.data, Src: v20.data, Size: len);
          v19.data[len] = 0;
          v19.len = len;
          idParser::ReadToken(this: src, token: &v20);
        }
        if ( idStr::Icmp(s1: v20.data, s2: "{") != 0 )
        {
          idParser::Warning(this: src, str: "bad token %s", v20.data);
          idStr::FreeData(this: &v19);
          goto LABEL_19;
        }
        v21[0].allocedAndFlag = 20;
        v21[0].len = 0;
        v21[0].data = v21[0].baseBuffer;
        v21[0].baseBuffer[0] = 0;
        v18 = idDeclParticle::ParseParticleStage(
                this,
                src,
                stageName: &v19,
                inheritFrom: v21,
                a5: v9,
                a6: v8,
                a7: v7,
                a8: v6,
                a9: v14,
                a10: v15);
        if ( v18 == nullptr )
        {
          idParser::Warning(this: src, str: "Particle stage parse failed");
          idStr::FreeData(this: v21);
          idStr::FreeData(this: &v19);
          goto LABEL_19;
        }
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->stages,
          obj: (const encounterGroupRole_t *)&v18);
        idAtomicString::Set(this: &v17, str_: v19.data);
        idList<idAtomicString,109>::Append(this: (idList<idAtomicString,5> *)&this->stageNames, obj: &v17);
        idAtomicString::Set(this: &v16, str_: v21[0].data);
        idList<idAtomicString,109>::Append(this: (idList<idAtomicString,5> *)&this->stageInheritNames, obj: &v16);
        idStr::FreeData(this: v21);
        idStr::FreeData(this: &v19);
      }
      else
      {
        ParseBounds(src, bounds: &this->bounds);
      }
      if ( !idParser::ReadToken(this: src, token: &v20) )
        break;
    }
  }
  idDeclParticle::UpdateBounds(this);
  idDeclParticle::UpdateMaxSystemDuration(this);
  num = this->stages.num;
  v11 = 0;
  this->lodRadius = 0;
  if ( num > 0 )
  {
    list = this->stages.list;
    do
    {
      radius = list[v2]->lodParms.radius;
      if ( radius > this->lodRadius )
        this->lodRadius = radius;
      ++v11;
      ++v2;
    }
    while ( v11 < this->stages.num );
  }
LABEL_19:
  idStr::FreeData(this: &v20);
}


// ========================================================================
// __unwind$228417
// EA  : 0x827E494C
// RVA : 0x007E494C
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_228417()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$228418
// EA  : 0x827E4974
// RVA : 0x007E4974
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_228418()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$228419
// EA  : 0x827E499C
// RVA : 0x007E499C
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_228419()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 208));
}


// ========================================================================
// ?LogMissingDecl@idDeclParticle@@UBAXXZ
// EA  : 0x827E49D0
// RVA : 0x007E49D0
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void __fastcall idDeclParticle::LogMissingDecl(idDeclParticle *this)
{
  BOOL v2; // r30
  idFile *v3; // r30
  idDeclParticle *v4; // r3
  idFile_vtbl *v5; // r29
  const char *str; // r28
  const char *(__fastcall *DefaultDefinition)(struct idDeclParticle *); // ctr
  int v8; // r3
  idStr v9; // [sp+50h] [-170h] BYREF
  idStr v10; // [sp+70h] [-150h] BYREF
  char v11[304]; // [sp+90h] [-130h] BYREF

  idStr::idStr(this: &v9, text: "decls/particles/missing_decls.prt");
  fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v9.data, a3: v11, a4: 256, a5: FSPATH_BASE);
  if ( idLib::sourceControl != nullptr )
  {
    idStr::idStr(this: &v10, text: v11);
    v2 = (_cntlzw(idSourceControl::CheckOut(this: idLib::sourceControl, file: &v10)) & 0x20) != 0;
    idStr::FreeData(this: &v10);
    if ( v2 )
      idLib::Error(fmt: "Failed to check out %s\n", v11);
    v3 = fileSystem->OpenFileAppend(this: fileSystem, a2: v9.data, a3: 0);
    if ( v3 == nullptr )
      idLib::Error(fmt: "Failed to open %s\n", v9.data);
    v4 = this;
    v5 = v3->__vftable;
    DefaultDefinition = this->DefaultDefinition;
    str = this->name.str;
    v8 = (int)DefaultDefinition(this: v4);
    v5->Printf(this: v3, a2: "particle %s\n%s", str, v8);
    ((void (__fastcall *)(idFile *, int))v3->dtr_idFile)(a1: v3, a2: 1);
    idStr::FreeData(this: &v9);
  }
  else
  {
    idLib::Error(fmt: "Source control not active when attempting to check out %s\n", v9.data);
    _LN50_2();
  }
}


// ========================================================================
// $LN50_2
// EA  : 0x827E4B18
// RVA : 0x007E4B18
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _LN50_2()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 80));
}


// ========================================================================
// __unwind$228720
// EA  : 0x827E4B40
// RVA : 0x007E4B40
// PDB : w:\tech5\engine\models\particles\declparticle.cpp
// ========================================================================

void _unwind_228720()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 112));
}

