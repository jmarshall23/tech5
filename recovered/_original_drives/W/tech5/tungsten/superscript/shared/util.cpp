
// ========================================================================
// ?Init@ssUtil@@QAAXXZ
// EA  : 0x82EEBB40
// RVA : 0x00EEBB40
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void __fastcall ssUtil::Init(ssUtil *this)
{
  ssEntity v1; // [sp+50h] [-20h] BYREF
  ssObject<ssWorldUtil> v2; // [sp+58h] [-18h]

  v2.spawnId = ssEntity::ssEntity(this: &v1, name: "world")->spawnId;
  v2.objectId = gameInterface->FindObject(this: gameInterface, a2: v2.spawnId, a3: "ssWorldUtil", a4: true);
  worldUtil = v2;
}


// ========================================================================
// ?CreateNamedThreadOnEntity@ssUtil@@SAXVssString@@@Z
// EA  : 0x82EEBBB0
// RVA : 0x00EEBBB0
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void __fastcall ssUtil::CreateNamedThreadOnEntity(ssString *callFunction)
{
  ssString *v1; // r30
  int v2; // r3
  int v3; // r29
  int spawnId; // r28
  const ssString *v5; // r3
  const ssString *v6; // r3
  ssEntity v7; // [sp+50h] [-70h] BYREF
  ssObject<ssWorldUtil> v8; // [sp+54h] [-6Ch] BYREF
  ssString v9; // [sp+60h] [-60h] BYREF
  ssString v10; // [sp+70h] [-50h] BYREF
  ssString v11[4]; // [sp+80h] [-40h] BYREF

  v1 = callFunction;
  if ( callFunction->len != 0 )
  {
    ssString::Init(this: &v9);
    v2 = ssString::Find(this: v1, a: 46, i: 0);
    v3 = v2;
    if ( v2 >= 0 )
    {
      v5 = ssString::Left(this: &v10, result: v1, num: v2);
      ssEntity::ssEntity(this: &v7, name: v5);
      ssString::Empty(this: &v10);
      if ( (unsigned __int8)ssEntity::IsValid(this: &v7) == 0 )
      {
        ssString::Empty(this: &v9);
LABEL_8:
        callFunction = v1;
        goto _M20401;
      }
      spawnId = v7.spawnId;
      v6 = ssString::Right(this: v11, result: v1, num: v1->len - v3 - 1);
      ssString::operator=(this: &v9, text: v6);
      ssString::Empty(this: v11);
    }
    else
    {
      ssObject<ssWorldUtil>::GetWorld(this: &v8, result: (ssEntity *)&worldUtil);
      spawnId = v8.spawnId;
      ssString::operator=(this: &v9, text: v1);
    }
    gameInterface->CreateNamedThread(this: gameInterface, a2: spawnId, a3: v9.data);
    ssString::Empty(this: &v9);
    goto LABEL_8;
  }
_M20401:
  ssString::Empty(this: callFunction);
}


// ========================================================================
// __unwind$20334
// EA  : 0x82EEBCCC
// RVA : 0x00EEBCCC
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20334()
{
  int v0; // r12

  ssString::~ssString(this: *(ssString **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$20335
// EA  : 0x82EEBCF4
// RVA : 0x00EEBCF4
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20335()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$20336
// EA  : 0x82EEBD1C
// RVA : 0x00EEBD1C
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20336()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$20337
// EA  : 0x82EEBD44
// RVA : 0x00EEBD44
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20337()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 128));
}


// ========================================================================
// ?DefineFlag@ssUtil@@SAXVssEntity@@ABVssString@@@Z
// EA  : 0x82EEBD70
// RVA : 0x00EEBD70
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void __fastcall ssUtil::DefineFlag(ssEntity *ent, const ssString *name)
{
  char v4; // r3
  char v5; // r11
  ssEntity *v6; // r3
  ssEntity v7; // [sp+50h] [-30h] BYREF
  ssObject<util_entityFlag> v8[2]; // [sp+58h] [-28h] BYREF

  if ( ent->spawnId == 0
    || (v4 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v5 = 1,
        v4 == 0) )
  {
    v5 = 0;
  }
  if ( v5 != 0 )
  {
    ssEntity::ssEntity(this: &v7, e: ent);
    ssObject<util_entityFlag>::ssObject<util_entityFlag>(this: v8, e: v6, create: true);
    if ( !ssObject<util_entityFlag>::IsDefined(this: v8, name) )
      ssObject<util_entityFlag>::Define(this: v8, name, animNotify: false, state: false);
  }
}


// ========================================================================
// ?SetWorkingResolution@ssUtil@@QAAXMM@Z
// EA  : 0x82EEBE30
// RVA : 0x00EEBE30
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void __fastcall ssUtil::SetWorkingResolution(ssUtil *this, double screenX, double screenY)
{
  this->fWorkResolutionX = screenX;
  this->fWorkResolutionY = screenY;
}


// ========================================================================
// ?SetFlag@ssUtil@@SAXVssEntity@@ABVssString@@M@Z
// EA  : 0x82EEC050
// RVA : 0x00EEC050
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void __fastcall ssUtil::SetFlag(ssEntity *ent, const ssString *name, double delay)
{
  char v6; // r3
  char v7; // r11
  ssEntity *v8; // r3
  ssEntity *v9; // r29
  const ssString *v10; // r3
  const ssString *v11; // r28
  ssString *v12; // r3
  const ssString *v13; // r3
  const ssString *v14; // r3
  const ssString *v15; // r3
  const ssString *v16; // r3
  ssString *v17; // r3
  ssObjectBase v18[2]; // [sp+50h] [-F0h] BYREF
  ssString v19; // [sp+60h] [-E0h] BYREF
  ssEntity v20; // [sp+70h] [-D0h] BYREF
  cvarInt_ v21; // [sp+80h] [-C0h] BYREF
  ssString v22; // [sp+90h] [-B0h] BYREF
  ssString v23; // [sp+A0h] [-A0h] BYREF
  ssString v24; // [sp+B0h] [-90h] BYREF
  ssString v25; // [sp+C0h] [-80h] BYREF
  ssString v26; // [sp+D0h] [-70h] BYREF
  ssString v27; // [sp+E0h] [-60h] BYREF
  ssString v28; // [sp+F0h] [-50h] BYREF
  ssString v29; // [sp+100h] [-40h] BYREF

  if ( ent->spawnId == 0
    || (v6 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v7 = 1,
        v6 == 0) )
  {
    v7 = 0;
  }
  if ( v7 != 0 )
  {
    ssEntity::ssEntity(this: &v20, e: ent);
    ssObject<util_entityFlag>::ssObject<util_entityFlag>(this: (ssObject<util_entityFlag> *)v18, e: v8, create: false);
    if ( ssObjectBase::IsValid(this: v18) )
    {
      ssObject<util_entityFlag>::Set(this: (ssObject<util_entityFlag> *)v18, name, delay);
    }
    else
    {
      cvarInt_::cvarInt_(this: &v21, name_: "ss_debugPrint", default_: 1);
      if ( gameInterface->GetCVarInteger(this: gameInterface, a2: v21.name, a3: v21.defValue) > 0 )
      {
        v9 = ssEntity::Name(this: (ssEntity *)&v29, result: (ssString *)ent);
        ssString::ssString(this: &v27, i: 540);
        v11 = v10;
        ssString::Init(this: &v19);
        ssString::operator=(this: &v19, text: "ssUtil::SetFlag");
        v12 = operator+(result: &v25, a: "^3", b: &v19);
        v13 = operator+(result: &v23, a: v12, b: "::");
        v14 = operator+(result: &v26, a: v13, b: v11);
        v15 = operator+(result: &v28, a: v14, b: "^0 : ");
        v16 = operator+(result: &v22, a: v15, b: "Could not access the entityFlag object on entity: ");
        v17 = operator+(result: &v24, a: v16, b: (const ssString *)v9);
        gameInterface->Printf(this: gameInterface, a2: "%s\n", v17->data);
        ssString::Empty(this: &v24);
        ssString::Empty(this: &v22);
        ssString::Empty(this: &v28);
        ssString::Empty(this: &v26);
        ssString::Empty(this: &v23);
        ssString::Empty(this: &v25);
        ssString::Empty(this: &v19);
        ssString::Empty(this: &v27);
        ssString::Empty(this: &v29);
      }
    }
  }
}


// ========================================================================
// __unwind$20897
// EA  : 0x82EEC250
// RVA : 0x00EEC250
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20897()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 256));
}


// ========================================================================
// __unwind$20898
// EA  : 0x82EEC278
// RVA : 0x00EEC278
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20898()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 224));
}


// ========================================================================
// __unwind$20899
// EA  : 0x82EEC2A0
// RVA : 0x00EEC2A0
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20899()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$20900
// EA  : 0x82EEC2C8
// RVA : 0x00EEC2C8
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20900()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 192));
}


// ========================================================================
// __unwind$20901
// EA  : 0x82EEC2F0
// RVA : 0x00EEC2F0
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20901()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 160));
}


// ========================================================================
// __unwind$20902
// EA  : 0x82EEC318
// RVA : 0x00EEC318
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20902()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 208));
}


// ========================================================================
// __unwind$20903
// EA  : 0x82EEC340
// RVA : 0x00EEC340
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20903()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 240));
}


// ========================================================================
// __unwind$20904
// EA  : 0x82EEC368
// RVA : 0x00EEC368
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20904()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 144));
}


// ========================================================================
// __unwind$20905
// EA  : 0x82EEC390
// RVA : 0x00EEC390
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_20905()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 176));
}


// ========================================================================
// ?ClearFlag@ssUtil@@SAXVssEntity@@ABVssString@@M@Z
// EA  : 0x82EEC3C0
// RVA : 0x00EEC3C0
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void __fastcall ssUtil::ClearFlag(ssEntity *ent, const ssString *name, double delay)
{
  char v6; // r3
  char v7; // r11
  ssEntity *v8; // r3
  ssEntity *v9; // r29
  const ssString *v10; // r3
  const ssString *v11; // r28
  ssString *v12; // r3
  const ssString *v13; // r3
  const ssString *v14; // r3
  const ssString *v15; // r3
  const ssString *v16; // r3
  ssString *v17; // r3
  ssObjectBase v18[2]; // [sp+50h] [-F0h] BYREF
  ssString v19; // [sp+60h] [-E0h] BYREF
  ssEntity v20; // [sp+70h] [-D0h] BYREF
  cvarInt_ v21; // [sp+80h] [-C0h] BYREF
  ssString v22; // [sp+90h] [-B0h] BYREF
  ssString v23; // [sp+A0h] [-A0h] BYREF
  ssString v24; // [sp+B0h] [-90h] BYREF
  ssString v25; // [sp+C0h] [-80h] BYREF
  ssString v26; // [sp+D0h] [-70h] BYREF
  ssString v27; // [sp+E0h] [-60h] BYREF
  ssString v28; // [sp+F0h] [-50h] BYREF
  ssString v29; // [sp+100h] [-40h] BYREF

  if ( ent->spawnId == 0
    || (v6 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v7 = 1,
        v6 == 0) )
  {
    v7 = 0;
  }
  if ( v7 != 0 )
  {
    ssEntity::ssEntity(this: &v20, e: ent);
    ssObject<util_entityFlag>::ssObject<util_entityFlag>(this: (ssObject<util_entityFlag> *)v18, e: v8, create: false);
    if ( ssObjectBase::IsValid(this: v18) )
    {
      ssObject<util_entityFlag>::Clear(this: (ssObject<util_entityFlag> *)v18, name, delay);
    }
    else
    {
      cvarInt_::cvarInt_(this: &v21, name_: "ss_debugPrint", default_: 1);
      if ( gameInterface->GetCVarInteger(this: gameInterface, a2: v21.name, a3: v21.defValue) > 0 )
      {
        v9 = ssEntity::Name(this: (ssEntity *)&v29, result: (ssString *)ent);
        ssString::ssString(this: &v27, i: 558);
        v11 = v10;
        ssString::Init(this: &v19);
        ssString::operator=(this: &v19, text: "ssUtil::ClearFlag");
        v12 = operator+(result: &v25, a: "^3", b: &v19);
        v13 = operator+(result: &v23, a: v12, b: "::");
        v14 = operator+(result: &v26, a: v13, b: v11);
        v15 = operator+(result: &v28, a: v14, b: "^0 : ");
        v16 = operator+(result: &v22, a: v15, b: "Could not access the entityFlag object on entity: ");
        v17 = operator+(result: &v24, a: v16, b: (const ssString *)v9);
        gameInterface->Printf(this: gameInterface, a2: "%s\n", v17->data);
        ssString::Empty(this: &v24);
        ssString::Empty(this: &v22);
        ssString::Empty(this: &v28);
        ssString::Empty(this: &v26);
        ssString::Empty(this: &v23);
        ssString::Empty(this: &v25);
        ssString::Empty(this: &v19);
        ssString::Empty(this: &v27);
        ssString::Empty(this: &v29);
      }
    }
  }
}


// ========================================================================
// __unwind$21042
// EA  : 0x82EEC5C0
// RVA : 0x00EEC5C0
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_21042()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 256));
}


// ========================================================================
// __unwind$21043
// EA  : 0x82EEC5E8
// RVA : 0x00EEC5E8
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_21043()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 224));
}


// ========================================================================
// __unwind$21044
// EA  : 0x82EEC610
// RVA : 0x00EEC610
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_21044()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$21045
// EA  : 0x82EEC638
// RVA : 0x00EEC638
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_21045()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 192));
}


// ========================================================================
// __unwind$21046
// EA  : 0x82EEC660
// RVA : 0x00EEC660
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_21046()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 160));
}


// ========================================================================
// __unwind$21047
// EA  : 0x82EEC688
// RVA : 0x00EEC688
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_21047()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 208));
}


// ========================================================================
// __unwind$21048
// EA  : 0x82EEC6B0
// RVA : 0x00EEC6B0
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_21048()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 240));
}


// ========================================================================
// __unwind$21049
// EA  : 0x82EEC6D8
// RVA : 0x00EEC6D8
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_21049()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 144));
}


// ========================================================================
// __unwind$21050
// EA  : 0x82EEC700
// RVA : 0x00EEC700
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

void _unwind_21050()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 176));
}


// ========================================================================
// ?IsPlayerLookingAtPoint@ssUtil@@SA_NVssEntity@@VssVector@@_NM02@Z
// EA  : 0x82EEC7D0
// RVA : 0x00EEC7D0
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

int __fastcall ssUtil::IsPlayerLookingAtPoint(
        ssString *player,
        ssVector *point,
        bool testLOS,
        double tolerance,
        ssEntity *skipEnt,
        const ssEntity *ignoreZ,
        char a7)
{
  char v13; // r3
  char v14; // r11
  int result; // r3
  double v16; // fp31
  double v17; // fp12
  double v18; // fp9
  double v19; // fp6
  double v20; // fp30
  long double v21; // fp2
  double v22; // fp28
  double v23; // fp27
  double v24; // fp26
  double y; // fp0
  double z; // fp13
  ssEntity *v27; // r3
  ssEntity v28; // [sp+50h] [-120h] BYREF
  char *v29; // [sp+54h] [-11Ch]
  int v30; // [sp+58h] [-118h]
  ssVector v31; // [sp+60h] [-110h] BYREF
  ssString v32; // [sp+70h] [-100h] BYREF
  ssVector v33; // [sp+80h] [-F0h] BYREF
  ssVector v34; // [sp+90h] [-E0h] BYREF
  ssEntity v35; // [sp+9Ch] [-D4h] BYREF
  ssTrace v36; // [sp+A0h] [-D0h] BYREF

  if ( player->len == 0
    || (v13 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v14 = 1,
        v13 == 0) )
  {
    v14 = 0;
  }
  if ( v14 != 0
    || (ssString::Init(this: &v32),
        ssString::operator=(this: &v32, text: "idPlayer"),
        ssEntity::IsClass(this: (ssEntity *)player, className: &v32)) )
  {
    ssEntity::GetViewPos(this: &v28, result: player);
    ssEntity::GetViewAngles(this: (ssEntity *)&v34, result: player);
    v16 = 0.0;
    if ( a7 != 0 )
    {
      *(float *)&v30 = 0.0;
      point->z = 0.0;
      v34.x = 0.0;
    }
    v17 = (float)(point->y - *(float *)&v29);
    v18 = (float)(point->z - *(float *)&v30);
    v19 = (float)(point->x - *(float *)&v28.spawnId);
    v31.x = 0.0;
    v31.y = 0.0;
    v31.z = 0.0;
    v20 = 1.0;
    *((double *)&v21 + 1) = __fsqrts((float)((float)((float)v19 * (float)v19)
                                           + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))));
    *(double *)&v21 = (float)((float)1.0 / (float)*((double *)&v21 + 1));
    v22 = (float)((float)((float)1.0 / (float)*((double *)&v21 + 1)) * (float)v19);
    v23 = (float)((float)((float)1.0 / (float)*((double *)&v21 + 1)) * (float)v17);
    v24 = (float)((float)v18 * (float)((float)1.0 / (float)*((double *)&v21 + 1)));
    math::AngToVectors(a: &v34, f: &v31, r: nullptr, u: nullptr, a5: v21);
    if ( tolerance < 0.0 || (v16 = tolerance, tolerance <= 1.0) )
      v20 = v16;
    if ( (float)((float)(v31.x * (float)v22) + (float)((float)(v31.z * (float)v24) + (float)(v31.y * (float)v23))) >= (double)(float)-(float)((float)((float)v20 * (float)0.24989998) - (float)0.99989998) )
    {
      if ( !testLOS )
        return 1;
      y = point->y;
      z = point->z;
      if ( (float)((float)((float)(*(float *)&v28.spawnId - point->x) * (float)(*(float *)&v28.spawnId - point->x))
                 + (float)((float)((float)(*(float *)&v30 - point->z) * (float)(*(float *)&v30 - point->z))
                         + (float)((float)(*(float *)&v29 - point->y) * (float)(*(float *)&v29 - point->y)))) < 16777216.0 )
      {
        v33.x = point->x;
        v33.y = y;
        v33.z = z;
        v32.len = v28.spawnId;
        v32.data = v29;
        v32.alloced = v30;
        ssEntity::ssEntity(this: &v35, e: ignoreZ);
        ssTrace::ssTrace(this: &v36, _startPos: (ssVector *)&v32, _endPos: &v33, _contentMask: 1, _ignoreEnt: v27);
        while ( !gameInterface->TracesResolved(this: gameInterface) )
          gameInterface->WaitFrame(this: gameInterface);
        ssTrace::Resolve(this: &v36);
        result = 0;
        if ( v36.hitFraction >= 0.99900001 )
          return 1;
        return result;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?IsPlayerLookingAtEntity@ssUtil@@SA_NVssEntity@@0_NM@Z
// EA  : 0x82EECA88
// RVA : 0x00EECA88
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

int __fastcall ssUtil::IsPlayerLookingAtEntity(ssEntity *player, ssString *ent, bool testLOS, double tolerance)
{
  char v8; // r3
  char v9; // r11
  int JointHandle; // r3
  ssEntity *JointPos; // r3
  double v13; // fp12
  double v14; // fp8
  const ssEntity *v15; // r3
  const ssEntity *v16; // r30
  ssEntity *v17; // r6
  ssString *v18; // r3
  ssEntity v19; // [sp+50h] [-70h] BYREF
  ssEntity v20; // [sp+54h] [-6Ch] BYREF
  ssEntity v21; // [sp+58h] [-68h] BYREF
  float v22; // [sp+5Ch] [-64h]
  int v23; // [sp+60h] [-60h]
  ssString v24; // [sp+70h] [-50h] BYREF
  ssString v25; // [sp+80h] [-40h] BYREF

  if ( player->spawnId == 0
    || (v8 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v9 = 1,
        v8 == 0) )
  {
    v9 = 0;
  }
  if ( v9 == 0 )
  {
    ssString::Init(this: &v24);
    ssString::operator=(this: &v24, text: "idPlayer");
    if ( !ssEntity::IsClass(this: player, className: &v24) )
      return 0;
  }
  ssEntity::GetWorldOrigin(this: &v21, result: ent);
  ssString::Init(this: &v24);
  ssString::operator=(this: &v24, text: "idActor");
  if ( ssEntity::IsClass(this: (ssEntity *)ent, className: &v24) )
  {
    ssString::Init(this: &v25);
    ssString::operator=(this: &v25, text: "head");
    JointHandle = ssEntity::GetJointHandle(this: (ssEntity *)ent, jointname: &v25);
    JointPos = ssEntity::GetJointPos(this: (ssEntity *)&v24, result: ent, jointnum: JointHandle);
    v13 = (float)(*(float *)&JointPos[2].spawnId - *(float *)&v23);
    v14 = (float)(v22 + (float)(*(float *)&JointPos[2].spawnId - *(float *)&v23));
    *(float *)&v21.spawnId = *(float *)&v21.spawnId + (float)(*(float *)&JointPos[2].spawnId - *(float *)&v23);
    v22 = v14;
    *(float *)&v23 = (float)v13 + *(float *)&v23;
  }
  v24.len = v21.spawnId;
  *(float *)&v24.data = v22;
  v24.alloced = v23;
  ssEntity::ssEntity(this: &v19, e: (const ssEntity *)ent);
  v16 = v15;
  ssEntity::ssEntity(this: &v20, e: player);
  return ssUtil::IsPlayerLookingAtPoint(
           player: v18,
           point: (ssVector *)&v24,
           testLOS,
           tolerance,
           skipEnt: v17,
           ignoreZ: v16,
           a7: 0);
}


// ========================================================================
// ?FillListFromTargets@ssUtil@@SAHAAV?$ssList@VssEntity@@@@VssEntity@@@Z
// EA  : 0x82EECC20
// RVA : 0x00EECC20
// PDB : w:\tech5\tungsten\superscript\shared\util.cpp
// ========================================================================

int __fastcall ssUtil::FillListFromTargets(ssList<ssEntity> *dst, ssString *src)
{
  char v4; // r3
  char v5; // r11
  int num; // r27
  int v8; // r30
  double v9; // fp31
  __int64 v10; // r11
  char v11; // r3
  ssEntity v12[2]; // [sp+50h] [-50h] BYREF
  __int64 v13; // [sp+58h] [-48h]

  if ( src->len == 0
    || (v4 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v5 = 1,
        v4 == 0) )
  {
    v5 = 0;
  }
  if ( v5 == 0 )
    return -1;
  num = dst->num;
  v8 = 0;
  v9 = 0.0;
  if ( ssEntity::NumTargets(this: (ssEntity *)src) > 0.0 )
  {
    do
    {
      ssEntity::GetTarget(this: v12, result: src, index: v9);
      if ( v12[0].spawnId == 0
        || (v11 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
            LOBYTE(v10) = 1,
            v11 == 0) )
      {
        LOBYTE(v10) = 0;
      }
      if ( (_BYTE)v10 != 0 )
        ssList<ssEntity>::Insert(this: dst, element: v12, index: dst->num);
      LODWORD(v10) = ++v8;
      v13 = v10;
      v9 = (float)v10;
    }
    while ( v9 < ssEntity::NumTargets(this: (ssEntity *)src) );
  }
  return dst->num - num;
}

