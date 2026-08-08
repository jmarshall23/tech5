
// ========================================================================
// ?Destroy@phook_test1_derrived@@UAAXXZ
// EA  : 0x82EE9618
// RVA : 0x00EE9618
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void __fastcall phook_test1_derrived::Destroy(phook_test1_derrived *this)
{
  ssString v1; // [sp+50h] [-20h] BYREF

  ssString::Init(this: &v1);
  ssString::operator=(this: &v1, text: "I was destroyed !!! :~~~(");
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v1.data);
  ssString::Empty(this: &v1);
}


// ========================================================================
// __unwind$19653
// EA  : 0x82EE9684
// RVA : 0x00EE9684
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_19653()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 112 + 80));
}


// ========================================================================
// ?Init@phook_test1@@UAAXXZ
// EA  : 0x82EE9F28
// RVA : 0x00EE9F28
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void __fastcall __noreturn phook_test1::Init(phook_test1 *this)
{
  int num; // r28
  int v3; // r3
  int *data; // r28
  int v5; // r3
  int v6; // r4
  int v7; // r3
  int v8; // r11
  int *v9; // r10
  int v10; // r27
  int *v11; // r11
  int v12; // r9
  int v13; // r9
  int v14; // r4
  char v15; // r28
  ssString *v16; // r3
  ssString *v17; // r3
  ssString *v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r3
  int v22; // r3
  int v23; // r3
  ssString *v24; // r3
  ssString *v25; // r3
  ssString *v26; // r3
  unsigned int v27; // r3
  long double v28; // fp2
  int v29; // r4
  ssString *v30; // r3
  idGameSuperInterface_vtbl *v31; // r9
  int *v32; // r3
  int HasAccessors; // r3
  int v34; // r3
  ssEntity v35[4]; // [sp+50h] [-2B0h] BYREF
  ssList<int> v36; // [sp+60h] [-2A0h] BYREF
  ssString v37; // [sp+70h] [-290h] BYREF
  ssString v38; // [sp+80h] [-280h] BYREF
  ssString v39; // [sp+90h] [-270h] BYREF
  ssString v40; // [sp+A0h] [-260h] BYREF
  ssList<int> v41; // [sp+B0h] [-250h] BYREF
  ssObject<phook_test1> v42; // [sp+C0h] [-240h] BYREF
  ssString v43; // [sp+D0h] [-230h] BYREF
  ssVector v44; // [sp+E0h] [-220h] BYREF
  ssString v45; // [sp+F0h] [-210h] BYREF
  ssString v46; // [sp+100h] [-200h] BYREF
  ssEntity v47; // [sp+110h] [-1F0h] BYREF
  ssString v48; // [sp+120h] [-1E0h] BYREF
  ssString v49; // [sp+130h] [-1D0h] BYREF
  ssString v50; // [sp+140h] [-1C0h] BYREF
  ssString v51; // [sp+150h] [-1B0h] BYREF
  ssString v52; // [sp+160h] [-1A0h] BYREF
  ssString v53; // [sp+170h] [-190h] BYREF
  ssString v54; // [sp+180h] [-180h] BYREF
  ssString v55; // [sp+190h] [-170h] BYREF
  ssList<int> v56; // [sp+1A0h] [-160h] BYREF
  ssString v57; // [sp+1B0h] [-150h] BYREF
  ssString v58; // [sp+1C0h] [-140h] BYREF
  ssString v59; // [sp+1D0h] [-130h] BYREF
  ssString v60; // [sp+1E0h] [-120h] BYREF
  ssString v61; // [sp+1F0h] [-110h] BYREF
  ssString v62; // [sp+200h] [-100h] BYREF
  ssString v63; // [sp+210h] [-F0h] BYREF
  ssString v64; // [sp+220h] [-E0h] BYREF
  ssString v65; // [sp+230h] [-D0h] BYREF
  ssString v66; // [sp+240h] [-C0h] BYREF
  ssString v67; // [sp+250h] [-B0h] BYREF
  ssString v68; // [sp+260h] [-A0h] BYREF
  ssString v69; // [sp+270h] [-90h] BYREF
  ssString v70; // [sp+280h] [-80h] BYREF
  ssEntity v71; // [sp+290h] [-70h] BYREF
  ssString v72; // [sp+2A0h] [-60h] BYREF
  ssString v73; // [sp+2B0h] [-50h] BYREF

  memset(&v36, 0, 12);
  if ( gameInterface != nullptr )
    v36.threadId = gameInterface->GetAllocThread(this: gameInterface);
  else
    v36.threadId = 0;
  v35[0].spawnId = 0;
  ssList<int>::Insert(this: &v36, element: &v35[0].spawnId, index: 0);
  v35[0].spawnId = 1;
  ssList<int>::Insert(this: &v36, element: &v35[0].spawnId, index: v36.num);
  v35[0].spawnId = 2;
  ssList<int>::Insert(this: &v36, element: &v35[0].spawnId, index: v36.num);
  v35[0].spawnId = 3;
  ssList<int>::Insert(this: &v36, element: &v35[0].spawnId, index: v36.num);
  v35[0].spawnId = 4;
  ssList<int>::Insert(this: &v36, element: &v35[0].spawnId, index: v36.num);
  ssList<int>::ssList<int>(this: &v41, src: &v36);
  num = v36.num;
  ssString::ssString(this: &v64, i: v36.num);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", *(_DWORD *)(v3 + 4));
  ssString::Empty(this: &v64);
  if ( num < 10 )
    ssList<int>::Resize(this: &v36, newSize: 10);
  data = v36.data;
  v36.num = 10;
  v35[0].spawnId = (int)(v36.data + 3);
  ssString::ssString(this: &v54, i: v36.data[3]);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", *(_DWORD *)(v5 + 4));
  ssString::Empty(this: &v54);
  v6 = data[8];
  v35[0].spawnId = (int)(data + 8);
  ssString::ssString(this: &v51, i: v6);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", *(_DWORD *)(v7 + 4));
  ssString::Empty(this: &v51);
  v35[0].spawnId = 32;
  ssList<int>::Insert(this: &v36, element: &v35[0].spawnId, index: 7u);
  v35[0].spawnId = 16;
  ssList<int>::Insert(this: &v36, element: &v35[0].spawnId, index: v36.num);
  v35[0].spawnId = 33;
  ssList<ssEntity>::Clear(this: (ssList<float> *)&v41);
  ssList<int>::Insert(this: &v41, element: &v35[0].spawnId, index: v41.num);
  ssList<int>::ssList<int>(this: &v56, src: &v36);
  ssList<int>::Append(this: &v36, src: &v56);
  ssList<ssEntity>::Clear(this: (ssList<float> *)&v41);
  ssList<int>::Append(this: &v41, src: &v36);
  v8 = 0;
  v35[0].spawnId = 15;
  if ( v36.num <= 0 )
    goto LABEL_12;
  v9 = v36.data;
  while ( *v9 != 15 )
  {
    ++v8;
    ++v9;
    if ( v8 >= v36.num )
      goto LABEL_12;
  }
  if ( v8 == -1 )
LABEL_12:
    ssList<int>::Insert(this: &v36, element: &v35[0].spawnId, index: v36.num);
  ssList<int>::AppendUnique(this: &v36, src: &v41);
  v10 = v36.num;
  if ( v36.num <= 0 )
    AssertionFailed(msg: "Assertion failed: ( a >= 0 ) && ( a < num )");
  if ( v10 <= 2 )
    AssertionFailed(msg: "Assertion failed: ( b >= 0 ) && ( b < num )");
  v11 = v36.data;
  v12 = *v36.data;
  *v36.data = v36.data[2];
  v11[2] = v12;
  ssList<int>::Reverse(this: &v36);
  ssList<int>::Remove(this: &v36, index: 0);
  if ( v36.num > 1 )
  {
    v13 = v36.num - 1;
    if ( v36.num - 1 > 1 )
      v36.data[1] = v36.data[v36.num - 1];
    v36.num = v13;
  }
  else
  {
    AssertionFailed(msg: "Assertion failed: ( index >= 0 ) && ( index < num )");
  }
  v35[0].spawnId = 15;
  ssList<int>::RemoveElement(this: &v36, element: &v35[0].spawnId);
  v35[0].spawnId = 33;
  ssList<int>::RemoveElementFast(this: &v36, element: &v35[0].spawnId);
  ssString::Init(this: &v38);
  ssString::operator=(this: &v38, text: "THIS IS STRING 1");
  ssString::Init(this: &v37);
  ssString::operator=(this: &v37, text: &v38);
  ssString::operator=(this: &v37, text: "this is string 2");
  ssString::Init(this: &v39);
  ssString::operator=(this: &v39, text: "this is string 3");
  v44.x = 1.1109999;
  v44.y = 2.2219999;
  v44.z = 3.3329999;
  ssString::ssString(this: &v46, v: &v44, format: "x y z");
  ssString::ssString(this: &v57, list: &v36, seperator: " ");
  ssString::Init(this: &v50);
  ssString::operator=(this: &v50, c: 67);
  ssString::Init(this: &v66);
  ssString::operator=(this: &v66, text: "false");
  ssString::ssString(this: &v58, i: -42);
  ssString::ssString(this: &v72, i: 400);
  ssString::ssString(this: &v43, f: 3.1415927, precision: v14, a4: 10);
  v15 = *ssString::operator[](this: &v43, index: 5);
  ssString::Init(this: &v45);
  ssString::operator=(this: &v45, c: v15);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v45.data);
  ssString::Empty(this: &v45);
  *ssString::operator[](this: &v58, index: 0) = 43;
  ssString::operator=(this: &v50, c: 65);
  ssString::Init(this: &v49);
  ssString::operator=(this: &v49, text: "this is string 3a");
  ssString::operator=(this: &v39, text: &v49);
  ssString::Empty(this: &v49);
  v16 = operator+(result: &v69, a: &v38, b: &v37);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v16->data);
  ssString::Empty(this: &v69);
  v17 = operator+(result: &v60, a: "static char string", b: &v37);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v17->data);
  ssString::Empty(this: &v60);
  v18 = operator+(result: &v67, a: &v38, b: "static char string");
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v18->data);
  ssString::Empty(this: &v67);
  ssString::Cmp(this: &v38, text: v37.data);
  ssString::Cmp(this: &v37, text: "blah blah");
  ssString::Cmp(this: &v38, text: "mew mew");
  ssString::Cmp(this: &v39, text: v39.data);
  ssString::Cmp(this: &v38, text: v37.data);
  ssString::Cmp(this: &v37, text: "blah blah");
  ssString::Cmp(this: &v38, text: "mew mew");
  ssString::Cmp(this: &v39, text: v39.data);
  ssString::ssString(this: &v62, i: v38.len);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", *(_DWORD *)(v19 + 4));
  ssString::Empty(this: &v62);
  ssString::ssString(this: &v52, i: v37.len);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", *(_DWORD *)(v20 + 4));
  ssString::Empty(this: &v52);
  ssString::ssString(this: &v53, i: v39.len);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", *(_DWORD *)(v21 + 4));
  ssString::Empty(this: &v53);
  ssString::ssString(this: &v55, i: v46.len);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", *(_DWORD *)(v22 + 4));
  ssString::Empty(this: &v55);
  ssString::ssString(this: &v59, i: v57.len);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", *(_DWORD *)(v23 + 4));
  ssString::Empty(this: &v59);
  v24 = ssString::Left(this: &v61, result: &v38, num: 10);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v24->data);
  ssString::Empty(this: &v61);
  v25 = ssString::Right(this: &v63, result: &v37, num: 8);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v25->data);
  ssString::Empty(this: &v63);
  v26 = ssString::Mid(this: &v68, result: &v39, start: 2u, num: 4);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v26->data);
  ssString::Empty(this: &v68);
  ssString::Skip(this: &v73, result: &v46, num: 5);
  v27 = ssString::Find(this: &v43, a: 49, i: 0xFFFFFFFF);
  ssString::Find(this: &v43, a: 49, i: v27);
  ssString::Init(this: &v48);
  ssString::operator=(this: &v48, text: "2.2");
  ssString::Find(this: &v46, a: &v48, i: 0xFFFFFFFF);
  ssString::Empty(this: &v48);
  v28 = atof(nptr: v43.data);
  v30 = ssString::ssString(this: &v70, f: (float)*(double *)&v28, precision: v29, a4: 10);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v30->data);
  ssString::Empty(this: &v70);
  ssString::ToLower(this: &v38);
  ssString::ToUpper(this: &v37);
  ssString::Empty(this: &v39);
  ssString::Reverse(this: &v43);
  ssEntity::ssEntity(this: &v47, name: "player1");
  ssEntity::ssEntity(this: (ssEntity *)&v40, name: "info_null_1");
  ssEntity::GetWorldOrigin(this: &v71, result: &v40);
  ssEntity::ssEntity(this: v35, e: &this->self);
  v31 = gameInterface->__vftable;
  v42.spawnId = *v32;
  v42.__vftable = (ssObject<phook_test1>_vtbl *)&ssObject<phook_test1>::`vftable';
  v42.objectId = v31->FindObject(this: gameInterface, a2: v42.spawnId, a3: "phook_test1", a4: false);
  ssObject<phook_test1>::SetHasAccessors(this: &v42, hasAccessors: 42);
  HasAccessors = ssObject<phook_test1>::GetHasAccessors(this: &v42);
  ssString::ssString(this: &v65, i: HasAccessors);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", *(_DWORD *)(v34 + 4));
  ssString::Empty(this: &v65);
  while ( 1 )
    gameInterface->WaitFrame(this: gameInterface);
}


// ========================================================================
// __unwind$20212
// EA  : 0x82EEA850
// RVA : 0x00EEA850
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20212()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(v0 - 768 + 96));
}


// ========================================================================
// __unwind$20213
// EA  : 0x82EEA878
// RVA : 0x00EEA878
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20213()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(v0 - 768 + 176));
}


// ========================================================================
// __unwind$20214
// EA  : 0x82EEA8A0
// RVA : 0x00EEA8A0
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20214()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 544));
}


// ========================================================================
// __unwind$20215
// EA  : 0x82EEA8C8
// RVA : 0x00EEA8C8
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20215()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 384));
}


// ========================================================================
// __unwind$20216
// EA  : 0x82EEA8F0
// RVA : 0x00EEA8F0
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20216()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 336));
}


// ========================================================================
// __unwind$20217
// EA  : 0x82EEA918
// RVA : 0x00EEA918
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20217()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(v0 - 768 + 416));
}


// ========================================================================
// __unwind$20218
// EA  : 0x82EEA940
// RVA : 0x00EEA940
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20218()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 128));
}


// ========================================================================
// __unwind$20219
// EA  : 0x82EEA968
// RVA : 0x00EEA968
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20219()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 112));
}


// ========================================================================
// __unwind$20220
// EA  : 0x82EEA990
// RVA : 0x00EEA990
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20220()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 144));
}


// ========================================================================
// __unwind$20221
// EA  : 0x82EEA9B8
// RVA : 0x00EEA9B8
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20221()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 256));
}


// ========================================================================
// __unwind$20222
// EA  : 0x82EEA9E0
// RVA : 0x00EEA9E0
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20222()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 432));
}


// ========================================================================
// __unwind$20223
// EA  : 0x82EEAA08
// RVA : 0x00EEAA08
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20223()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 320));
}


// ========================================================================
// __unwind$20224
// EA  : 0x82EEAA30
// RVA : 0x00EEAA30
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20224()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 576));
}


// ========================================================================
// __unwind$20225
// EA  : 0x82EEAA58
// RVA : 0x00EEAA58
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20225()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 448));
}


// ========================================================================
// __unwind$20226
// EA  : 0x82EEAA80
// RVA : 0x00EEAA80
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20226()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 672));
}


// ========================================================================
// __unwind$20227
// EA  : 0x82EEAAA8
// RVA : 0x00EEAAA8
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20227()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 208));
}


// ========================================================================
// __unwind$20228
// EA  : 0x82EEAAD0
// RVA : 0x00EEAAD0
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20228()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 240));
}


// ========================================================================
// __unwind$20229
// EA  : 0x82EEAAF8
// RVA : 0x00EEAAF8
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20229()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 304));
}


// ========================================================================
// __unwind$20230
// EA  : 0x82EEAB20
// RVA : 0x00EEAB20
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20230()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 624));
}


// ========================================================================
// __unwind$20231
// EA  : 0x82EEAB48
// RVA : 0x00EEAB48
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20231()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 480));
}


// ========================================================================
// __unwind$20232
// EA  : 0x82EEAB70
// RVA : 0x00EEAB70
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20232()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 592));
}


// ========================================================================
// __unwind$20233
// EA  : 0x82EEAB98
// RVA : 0x00EEAB98
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20233()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 512));
}


// ========================================================================
// __unwind$20234
// EA  : 0x82EEABC0
// RVA : 0x00EEABC0
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20234()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 352));
}


// ========================================================================
// __unwind$20235
// EA  : 0x82EEABE8
// RVA : 0x00EEABE8
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20235()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 368));
}


// ========================================================================
// __unwind$20236
// EA  : 0x82EEAC10
// RVA : 0x00EEAC10
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20236()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 400));
}


// ========================================================================
// __unwind$20237
// EA  : 0x82EEAC38
// RVA : 0x00EEAC38
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20237()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 464));
}


// ========================================================================
// __unwind$20238
// EA  : 0x82EEAC60
// RVA : 0x00EEAC60
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20238()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 496));
}


// ========================================================================
// __unwind$20239
// EA  : 0x82EEAC88
// RVA : 0x00EEAC88
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20239()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 528));
}


// ========================================================================
// __unwind$20240
// EA  : 0x82EEACB0
// RVA : 0x00EEACB0
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20240()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 608));
}


// ========================================================================
// __unwind$20241
// EA  : 0x82EEACD8
// RVA : 0x00EEACD8
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20241()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 688));
}


// ========================================================================
// __unwind$20242
// EA  : 0x82EEAD00
// RVA : 0x00EEAD00
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20242()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 288));
}


// ========================================================================
// __unwind$20243
// EA  : 0x82EEAD28
// RVA : 0x00EEAD28
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20243()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 640));
}


// ========================================================================
// __unwind$20244
// EA  : 0x82EEAD50
// RVA : 0x00EEAD50
// PDB : w:\tech5\tungsten\superscript\maps\user\phook\phook_test.cpp
// ========================================================================

void _unwind_20244()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 768 + 560));
}

