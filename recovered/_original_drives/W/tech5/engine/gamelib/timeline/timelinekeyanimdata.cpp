
// ========================================================================
// ?PostLoadInit@mgTimelineKeyAnimData@@QAAXXZ
// EA  : 0x8276ADE8
// RVA : 0x0076ADE8
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

void __fastcall mgTimelineKeyAnimData::PostLoadInit(mgTimelineKeyAnimData *this)
{
  this->keySize = mgTimelineKeyUtil::KeySize(type: this->type);
}


// ========================================================================
// ??0mgTimelineKeyAnimData@@QAA@XZ
// EA  : 0x8276AEE0
// RVA : 0x0076AEE0
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

mgTimelineKeyAnimData *__fastcall mgTimelineKeyAnimData::mgTimelineKeyAnimData(mgTimelineKeyAnimData *this)
{
  this->times.list = nullptr;
  this->times.granularity = 0;
  this->times.memTag = 5;
  this->times.listStatic = 0;
  this->times.size = 0;
  this->times.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->times);
  this->data.list = nullptr;
  this->data.granularity = 0;
  this->data.memTag = 5;
  this->data.listStatic = 0;
  this->data.size = 0;
  this->data.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->data);
  this->keySize = 0;
  this->type = TL_KEYTYPE_MAX;
  return this;
}


// ========================================================================
// __unwind$247917
// EA  : 0x8276AF58
// RVA : 0x0076AF58
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

void _unwind_247917()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// ?FindLerpKeys@mgTimelineKeyAnimData@@QBA_NMPAH0PAM@Z
// EA  : 0x8276B280
// RVA : 0x0076B280
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

int __fastcall mgTimelineKeyAnimData::FindLerpKeys(
        mgTimelineKeyAnimData *this,
        double time,
        int *k0,
        int *k1,
        float *t,
        float *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18,
        float a19)
{
  int num; // r31
  float *list; // r30
  int v26; // r3
  float *v27; // r11
  double v28; // fp0
  double v29; // fp11

  num = this->times.num;
  a19 = time;
  list = this->times.list;
  if ( num == 0 )
    return 0;
  v26 = idSearch_Binary<float,idSearch_BinaryDefault<float>>::Search_LastLessEqual(
          this: &search,
          base: list,
          num,
          value: &a19);
  v27 = &list[v26];
  v28 = *v27;
  if ( v28 > time )
    return 0;
  if ( v26 < num - 1 )
  {
    v29 = (float)(v27[1] - *v27);
    *k1 = v26;
    *(_DWORD *)t = v26 + 1;
    *a6 = (float)((float)time - (float)v28) / (float)v29;
    return 1;
  }
  else
  {
    *k1 = v26;
    *(_DWORD *)t = v26;
    *a6 = 0.0;
    return 1;
  }
}


// ========================================================================
// ??$GetLerped@H@mgTimelineKeyAnimData@@ABA_NMPAH@Z
// EA  : 0x8276B350
// RVA : 0x0076B350
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

int __fastcall mgTimelineKeyAnimData::GetLerped<int>(
        mgTimelineKeyAnimData *this,
        double time,
        int *val,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // r11
  __int64 v15; // r5
  float v16; // [sp+8h] [-78h]
  float v17; // [sp+Ch] [-74h]
  float v18; // [sp+10h] [-70h]
  float v19; // [sp+14h] [-6Ch]
  float v20; // [sp+18h] [-68h]
  float v21; // [sp+1Ch] [-64h]
  int v22; // [sp+50h] [-30h] BYREF
  float v23; // [sp+54h] [-2Ch] BYREF
  __int64 v24; // [sp+58h] [-28h] BYREF

  if ( (unsigned __int8)mgTimelineKeyAnimData::FindLerpKeys(
                          this,
                          time,
                          k0: val,
                          k1: (int *)&v24,
                          t: (float *)&v22,
                          a6: &v23,
                          a7: a5,
                          a8: a6,
                          a9: a7,
                          a10: a8,
                          a11: a9,
                          a12: a10,
                          a13: a11,
                          a14: v16,
                          a15: v17,
                          a16: v18,
                          a17: v19,
                          a18: v20,
                          a19: v21) == 0 )
    return 0;
  HIDWORD(v14) = this->data.list;
  HIDWORD(v15) = *(_DWORD *)(4 * HIDWORD(v24) + HIDWORD(v14));
  LODWORD(v15) = *(_DWORD *)(4 * v22 + HIDWORD(v14));
  LODWORD(v14) = HIDWORD(v15);
  v24 = v14;
  *a4 = (int)(float)((float)((float)((float)v15 - (float)v14) * v23) + (float)v14);
  return 1;
}


// ========================================================================
// ??$GetLerped@M@mgTimelineKeyAnimData@@ABA_NMPAM@Z
// EA  : 0x8276B408
// RVA : 0x0076B408
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

int __fastcall mgTimelineKeyAnimData::GetLerped<float>(
        mgTimelineKeyAnimData *this,
        double time,
        float *val,
        float *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  float v14; // [sp+8h] [-78h]
  float v15; // [sp+Ch] [-74h]
  float v16; // [sp+10h] [-70h]
  float v17; // [sp+14h] [-6Ch]
  float v18; // [sp+18h] [-68h]
  float v19; // [sp+1Ch] [-64h]
  int v20; // [sp+50h] [-30h] BYREF
  float v21; // [sp+54h] [-2Ch] BYREF
  float v22[4]; // [sp+58h] [-28h] BYREF

  if ( (unsigned __int8)mgTimelineKeyAnimData::FindLerpKeys(
                          this,
                          time,
                          k0: (int *)val,
                          k1: &v20,
                          t: v22,
                          a6: &v21,
                          a7: a5,
                          a8: a6,
                          a9: a7,
                          a10: a8,
                          a11: a9,
                          a12: a10,
                          a13: a11,
                          a14: v14,
                          a15: v15,
                          a16: v16,
                          a17: v17,
                          a18: v18,
                          a19: v19) == 0 )
    return 0;
  *a4 = (float)((float)(*(float *)&this->data.list[4 * LODWORD(v22[0])] - *(float *)&this->data.list[4 * v20]) * v21)
      + *(float *)&this->data.list[4 * v20];
  return 1;
}


// ========================================================================
// ??$GetLerped@VidVec3@@@mgTimelineKeyAnimData@@ABA_NMPAVidVec3@@@Z
// EA  : 0x8276B490
// RVA : 0x0076B490
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

int __fastcall mgTimelineKeyAnimData::GetLerped<idVec3>(
        mgTimelineKeyAnimData *this,
        double time,
        idVec3 *val,
        float *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char *list; // r11
  float *v15; // r10
  float *v16; // r11
  float v17; // r7
  float v18; // r4
  float v19; // r5
  float v20; // r10
  float v21; // r9
  float v22; // r6
  double v23; // fp4
  double v24; // fp2
  float v25; // [sp+8h] [-98h]
  float v26; // [sp+Ch] [-94h]
  float v27; // [sp+10h] [-90h]
  float v28; // [sp+14h] [-8Ch]
  float v29; // [sp+18h] [-88h]
  float v30; // [sp+1Ch] [-84h]
  int v31; // [sp+50h] [-50h] BYREF
  float v32; // [sp+54h] [-4Ch] BYREF
  int v33[12]; // [sp+58h] [-48h] BYREF

  if ( (unsigned __int8)mgTimelineKeyAnimData::FindLerpKeys(
                          this,
                          time,
                          k0: (int *)val,
                          k1: v33,
                          t: (float *)&v31,
                          a6: &v32,
                          a7: a5,
                          a8: a6,
                          a9: a7,
                          a10: a8,
                          a11: a9,
                          a12: a10,
                          a13: a11,
                          a14: v25,
                          a15: v26,
                          a16: v27,
                          a17: v28,
                          a18: v29,
                          a19: v30) == 0 )
    return 0;
  list = this->data.list;
  v15 = (float *)&list[12 * v31];
  v16 = (float *)&list[12 * v33[0]];
  v17 = v15[2];
  v18 = *v15;
  v19 = v16[2];
  v20 = v15[1];
  v21 = v16[1];
  *(float *)&v33[4] = v17;
  v22 = *v16;
  *(float *)&v33[8] = v19;
  *(float *)&v33[3] = v20;
  *(float *)&v33[7] = v21;
  *(float *)&v33[2] = v18;
  *(float *)&v33[6] = v22;
  v23 = (float)((float)(v20 - v21) * v32);
  v24 = (float)((float)(v17 - v19) * v32);
  *a4 = (float)((float)(v18 - v22) * v32) + v22;
  a4[1] = (float)v23 + v21;
  a4[2] = (float)v24 + v19;
  return 1;
}


// ========================================================================
// ??$GetLerped@VidVec4@@@mgTimelineKeyAnimData@@ABA_NMPAVidVec4@@@Z
// EA  : 0x8276B598
// RVA : 0x0076B598
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

int __fastcall mgTimelineKeyAnimData::GetLerped<idVec4>(
        mgTimelineKeyAnimData *this,
        double time,
        idVec4 *val,
        float *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char *list; // r10
  float *v14; // r11
  float *v15; // r10
  float v17; // r5
  float v18; // r4
  float v19; // r9
  float v20; // r7
  float v21; // r11
  float v22; // r30
  float v23; // r29
  float v24; // r10
  double v25; // fp1
  double v26; // fp8
  double v27; // fp7
  float v28; // [sp+8h] [-98h]
  float v29; // [sp+Ch] [-94h]
  float v30; // [sp+10h] [-90h]
  float v31; // [sp+14h] [-8Ch]
  float v32; // [sp+18h] [-88h]
  float v33; // [sp+1Ch] [-84h]
  int v34; // [sp+50h] [-50h] BYREF
  int v35; // [sp+54h] [-4Ch] BYREF
  float v36[18]; // [sp+58h] [-48h] BYREF

  if ( (unsigned __int8)mgTimelineKeyAnimData::FindLerpKeys(
                          this,
                          time,
                          k0: (int *)val,
                          k1: &v35,
                          t: (float *)&v34,
                          a6: v36,
                          a7: a5,
                          a8: a6,
                          a9: a7,
                          a10: a8,
                          a11: a9,
                          a12: a10,
                          a13: a11,
                          a14: v28,
                          a15: v29,
                          a16: v30,
                          a17: v31,
                          a18: v32,
                          a19: v33) == 0 )
    return 0;
  list = this->data.list;
  v14 = (float *)&list[16 * v34];
  v15 = (float *)&list[16 * v35];
  v17 = *v14;
  v18 = v14[1];
  v19 = v14[2];
  v20 = v14[3];
  v21 = *v15;
  v22 = v15[1];
  v23 = v15[2];
  v24 = v15[3];
  v36[2] = v17;
  v36[3] = v18;
  v36[4] = v19;
  v36[5] = v20;
  v36[6] = v21;
  v36[7] = v22;
  v36[8] = v23;
  v36[9] = v24;
  v25 = (float)((float)(v17 - v21) * v36[0]);
  v26 = (float)((float)(v19 - v23) * v36[0]);
  v27 = (float)((float)(v20 - v24) * v36[0]);
  a4[1] = (float)((float)(v18 - v22) * v36[0]) + v22;
  *a4 = (float)v25 + v21;
  a4[2] = (float)v26 + v23;
  a4[3] = (float)v27 + v24;
  return 1;
}


// ========================================================================
// ?GetData@mgTimelineKeyAnimData@@QBA_NMPA_N@Z
// EA  : 0x8276B6A8
// RVA : 0x0076B6A8
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

int __fastcall mgTimelineKeyAnimData::GetData(
        mgTimelineKeyAnimData *this,
        double time,
        bool *val,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  float v14; // [sp+8h] [-78h]
  float v15; // [sp+Ch] [-74h]
  float v16; // [sp+10h] [-70h]
  float v17; // [sp+14h] [-6Ch]
  float v18; // [sp+18h] [-68h]
  float v19; // [sp+1Ch] [-64h]
  int v20; // [sp+50h] [-30h] BYREF
  float v21; // [sp+54h] [-2Ch] BYREF
  float v22[4]; // [sp+58h] [-28h] BYREF

  if ( (unsigned __int8)mgTimelineKeyAnimData::FindLerpKeys(
                          this,
                          time,
                          k0: (int *)val,
                          k1: &v20,
                          t: v22,
                          a6: &v21,
                          a7: a5,
                          a8: a6,
                          a9: a7,
                          a10: a8,
                          a11: a9,
                          a12: a10,
                          a13: a11,
                          a14: v14,
                          a15: v15,
                          a16: v16,
                          a17: v17,
                          a18: v18,
                          a19: v19) == 0 )
    return 0;
  *a4 = this->data.list[v20];
  return 1;
}


// ========================================================================
// ?GetData@mgTimelineKeyAnimData@@QBA_NMPAH@Z
// EA  : 0x8276B718
// RVA : 0x0076B718
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

// attributes: thunk
int __fastcall mgTimelineKeyAnimData::GetData(
        mgTimelineKeyAnimData *this,
        double time,
        int *val,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  return mgTimelineKeyAnimData::GetLerped<int>(this, time, val, a4, a5, a6, a7, a8, a9, a10, a11);
}


// ========================================================================
// ?GetData@mgTimelineKeyAnimData@@QBA_NMPAM@Z
// EA  : 0x8276B720
// RVA : 0x0076B720
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

// attributes: thunk
int __fastcall mgTimelineKeyAnimData::GetData(
        mgTimelineKeyAnimData *this,
        double time,
        float *val,
        float *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  return mgTimelineKeyAnimData::GetLerped<float>(this, time, val, a4, a5, a6, a7, a8, a9, a10, a11);
}


// ========================================================================
// ?GetData@mgTimelineKeyAnimData@@QBA_NMPAVidVec3@@@Z
// EA  : 0x8276B728
// RVA : 0x0076B728
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

// attributes: thunk
int __fastcall mgTimelineKeyAnimData::GetData(
        mgTimelineKeyAnimData *this,
        double time,
        idVec3 *val,
        float *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  return mgTimelineKeyAnimData::GetLerped<idVec3>(this, time, val, a4, a5, a6, a7, a8, a9, a10, a11);
}


// ========================================================================
// ?GetData@mgTimelineKeyAnimData@@QBA_NMPAVidVec4@@@Z
// EA  : 0x8276B730
// RVA : 0x0076B730
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

// attributes: thunk
int __fastcall mgTimelineKeyAnimData::GetData(
        mgTimelineKeyAnimData *this,
        double time,
        idVec4 *val,
        float *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  return mgTimelineKeyAnimData::GetLerped<idVec4>(this, time, val, a4, a5, a6, a7, a8, a9, a10, a11);
}


// ========================================================================
// `dynamic initializer for 'search''
// EA  : 0x83341720
// RVA : 0x01341720
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__search__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__search__);
}

