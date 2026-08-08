
// ========================================================================
// ?Sys_CurrentSystemTime@@YA_KXZ
// EA  : 0x82F81C80
// RVA : 0x00F81C80
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

unsigned int __fastcall Sys_CurrentSystemTime()
{
  _FILETIME v1; // [sp+50h] [-10h] BYREF

  GetSystemTimeAsFileTime(CurrentTime: &v1);
  return v1.dwLowDateTime;
}


// ========================================================================
// ?Sys_TimeStampToLogFormat@@YAPBDH@Z
// EA  : 0x82F81CC0
// RVA : 0x00F81CC0
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

char *__fastcall Sys_TimeStampToLogFormat(int timeStamp)
{
  __int64 v1; // r11
  tm *v2; // r3
  __int64 v3; // r6
  __int64 v4; // r10
  __int64 v5; // r8
  va *v6; // r3
  int v8; // [sp+8h] [-1098h]
  int v9; // [sp+Ch] [-1094h]
  int v10; // [sp+10h] [-1090h]
  int v11; // [sp+14h] [-108Ch]
  int v12; // [sp+18h] [-1088h]
  int v13; // [sp+1Ch] [-1084h]
  idStr v14; // [sp+50h] [-1050h] BYREF
  __int64 v15; // [sp+70h] [-1030h] BYREF
  va v16; // [sp+80h] [-1020h] BYREF

  HIDWORD(v1) = allocationCurrent[242];
  timeString[0] = 0;
  if ( timeStamp != -1 )
  {
    LODWORD(v1) = timeStamp;
    v15 = v1;
    v2 = localtime64(ptime: &v15);
    v14.len = 0;
    v14.allocedAndFlag = 20;
    v14.data = v14.baseBuffer;
    v14.baseBuffer[0] = 0;
    LODWORD(v3) = v2->tm_mon + 1;
    LODWORD(v4) = v2->tm_sec;
    HIDWORD(v3) = v2->tm_year + 1900;
    HIDWORD(v4) = v2->tm_min;
    LODWORD(v5) = v2->tm_hour;
    HIDWORD(v5) = v2->tm_mday;
    v6 = va::va(
           this: &v16,
           fmt: "%d-%02d-%02dT%02d:%02d:%02dZ",
           a3: v3,
           a4: v5,
           a5: v4,
           a6: v8,
           a7: v9,
           a8: v10,
           a9: v11,
           a10: v12,
           a11: v13);
    idStr::operator=(this: &v14, text: v6);
    idStr::Copynz(dest: timeString, src: v14.data, destsize: 128);
    idStr::FreeData(this: &v14);
  }
  return timeString;
}


// ========================================================================
// __unwind$114256
// EA  : 0x82F81D7C
// RVA : 0x00F81D7C
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

void _unwind_114256()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4256 + 80));
}


// ========================================================================
// ?Sys_TimeStampToStr@@YAPBDH_N@Z
// EA  : 0x82F81EC8
// RVA : 0x00F81EC8
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

char *__fastcall Sys_TimeStampToStr(int timeStamp, bool padded)
{
  __int64 v2; // r11
  tm *v4; // r30
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  const char *v8; // r4
  va *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  const char *v13; // r4
  va *v14; // r3
  __int64 v15; // r6
  __int64 v16; // r10
  __int64 v17; // r8
  va *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  const char *v22; // r4
  __int64 v23; // r10
  __int64 v24; // r8
  va *v25; // r3
  __int64 v26; // r6
  va *v27; // r3
  va *v28; // r3
  __int64 v29; // r6
  __int64 v30; // r10
  __int64 v31; // r8
  va *v32; // r3
  __int64 v33; // r10
  __int64 v34; // r6
  __int64 v35; // r8
  va *v36; // r3
  __int64 v37; // r6
  __int64 v38; // r10
  __int64 v39; // r8
  va *v40; // r3
  __int64 v41; // r10
  __int64 v42; // r8
  __int64 v43; // r6
  va *v44; // r3
  __int64 v45; // r6
  __int64 v46; // r10
  __int64 v47; // r8
  va *v48; // r3
  __int64 v49; // r6
  __int64 v50; // r10
  __int64 v51; // r8
  va *v52; // r3
  __int64 v53; // r6
  __int64 v54; // r10
  __int64 v55; // r8
  va *v56; // r3
  va *v57; // r3
  int v59; // [sp+8h] [-10D8h]
  int v60; // [sp+8h] [-10D8h]
  int v61; // [sp+8h] [-10D8h]
  int v62; // [sp+8h] [-10D8h]
  int v63; // [sp+8h] [-10D8h]
  int v64; // [sp+8h] [-10D8h]
  int v65; // [sp+8h] [-10D8h]
  int v66; // [sp+8h] [-10D8h]
  int v67; // [sp+8h] [-10D8h]
  int v68; // [sp+8h] [-10D8h]
  int v69; // [sp+8h] [-10D8h]
  int v70; // [sp+Ch] [-10D4h]
  int v71; // [sp+Ch] [-10D4h]
  int v72; // [sp+Ch] [-10D4h]
  int v73; // [sp+Ch] [-10D4h]
  int v74; // [sp+Ch] [-10D4h]
  int v75; // [sp+Ch] [-10D4h]
  int v76; // [sp+Ch] [-10D4h]
  int v77; // [sp+Ch] [-10D4h]
  int v78; // [sp+Ch] [-10D4h]
  int v79; // [sp+Ch] [-10D4h]
  int v80; // [sp+Ch] [-10D4h]
  int v81; // [sp+10h] [-10D0h]
  int v82; // [sp+10h] [-10D0h]
  int v83; // [sp+10h] [-10D0h]
  int v84; // [sp+10h] [-10D0h]
  int v85; // [sp+10h] [-10D0h]
  int v86; // [sp+10h] [-10D0h]
  int v87; // [sp+10h] [-10D0h]
  int v88; // [sp+10h] [-10D0h]
  int v89; // [sp+10h] [-10D0h]
  int v90; // [sp+10h] [-10D0h]
  int v91; // [sp+10h] [-10D0h]
  int v92; // [sp+14h] [-10CCh]
  int v93; // [sp+14h] [-10CCh]
  int v94; // [sp+14h] [-10CCh]
  int v95; // [sp+14h] [-10CCh]
  int v96; // [sp+14h] [-10CCh]
  int v97; // [sp+14h] [-10CCh]
  int v98; // [sp+14h] [-10CCh]
  int v99; // [sp+14h] [-10CCh]
  int v100; // [sp+14h] [-10CCh]
  int v101; // [sp+14h] [-10CCh]
  int v102; // [sp+14h] [-10CCh]
  int v103; // [sp+18h] [-10C8h]
  int v104; // [sp+18h] [-10C8h]
  int v105; // [sp+18h] [-10C8h]
  int v106; // [sp+18h] [-10C8h]
  int v107; // [sp+18h] [-10C8h]
  int v108; // [sp+18h] [-10C8h]
  int v109; // [sp+18h] [-10C8h]
  int v110; // [sp+18h] [-10C8h]
  int v111; // [sp+18h] [-10C8h]
  int v112; // [sp+18h] [-10C8h]
  int v113; // [sp+18h] [-10C8h]
  int v114; // [sp+1Ch] [-10C4h]
  int v115; // [sp+1Ch] [-10C4h]
  int v116; // [sp+1Ch] [-10C4h]
  int v117; // [sp+1Ch] [-10C4h]
  int v118; // [sp+1Ch] [-10C4h]
  int v119; // [sp+1Ch] [-10C4h]
  int v120; // [sp+1Ch] [-10C4h]
  int v121; // [sp+1Ch] [-10C4h]
  int v122; // [sp+1Ch] [-10C4h]
  int v123; // [sp+1Ch] [-10C4h]
  int v124; // [sp+1Ch] [-10C4h]
  idStr v125; // [sp+50h] [-1090h] BYREF
  __int64 v126; // [sp+70h] [-1070h] BYREF
  idStr v127; // [sp+80h] [-1060h] BYREF
  va v128; // [sp+A0h] [-1040h] BYREF

  HIDWORD(v2) = allocationCurrent[242];
  timeString_0[0] = 0;
  if ( timeStamp != -1 )
  {
    LODWORD(v2) = timeStamp;
    v126 = v2;
    v125.len = 0;
    v125.allocedAndFlag = 20;
    v4 = localtime64(ptime: &v126);
    v125.data = v125.baseBuffer;
    v125.baseBuffer[0] = 0;
    idStr::idStr(this: &v127, text: sys_lang.valueString.data);
    if ( idStr::Icmp(s1: v127.data, s2: "english") != 0 )
    {
      HIDWORD(v7) = v4->tm_mday;
      if ( padded )
      {
        v28 = va::va(
                this: &v128,
                fmt: "%02d",
                a3: v7,
                a4: v6,
                a5: v5,
                a6: v59,
                a7: v70,
                a8: v81,
                a9: v92,
                a10: v103,
                a11: v114);
        idStr::operator=(this: &v125, text: v28);
        idStr::Append(this: &v125, text: "/");
        HIDWORD(v29) = v4->tm_mon + 1;
        v32 = va::va(
                this: &v128,
                fmt: "%02d",
                a3: v29,
                a4: v31,
                a5: v30,
                a6: v63,
                a7: v74,
                a8: v85,
                a9: v96,
                a10: v107,
                a11: v118);
        idStr::Append(this: &v125, text: v32);
        idStr::Append(this: &v125, text: "/");
        HIDWORD(v33) = 0x82000000;
        HIDWORD(v34) = v4->tm_year + 1900;
        v36 = va::va(
                this: &v128,
                fmt: "%d",
                a3: v34,
                a4: v35,
                a5: v33,
                a6: v64,
                a7: v75,
                a8: v86,
                a9: v97,
                a10: v108,
                a11: v119);
        idStr::Append(this: &v125, text: v36);
        idStr::Append(this: &v125, text: "  ");
        HIDWORD(v37) = v4->tm_hour;
        v40 = va::va(
                this: &v128,
                fmt: "%02d",
                a3: v37,
                a4: v39,
                a5: v38,
                a6: v65,
                a7: v76,
                a8: v87,
                a9: v98,
                a10: v109,
                a11: v120);
        idStr::Append(this: &v125, text: v40);
        idStr::Append(this: &v125, text: ":");
      }
      else
      {
        v44 = va::va(
                this: &v128,
                fmt: "%d",
                a3: v7,
                a4: v6,
                a5: v5,
                a6: v59,
                a7: v70,
                a8: v81,
                a9: v92,
                a10: v103,
                a11: v114);
        idStr::operator=(this: &v125, text: v44);
        idStr::Append(this: &v125, text: "/");
        HIDWORD(v45) = v4->tm_mon + 1;
        v48 = va::va(
                this: &v128,
                fmt: "%d",
                a3: v45,
                a4: v47,
                a5: v46,
                a6: v67,
                a7: v78,
                a8: v89,
                a9: v100,
                a10: v111,
                a11: v122);
        idStr::Append(this: &v125, text: v48);
        idStr::Append(this: &v125, text: "/");
        HIDWORD(v49) = v4->tm_year + 1900;
        v52 = va::va(
                this: &v128,
                fmt: "%d",
                a3: v49,
                a4: v51,
                a5: v50,
                a6: v68,
                a7: v79,
                a8: v90,
                a9: v101,
                a10: v112,
                a11: v123);
        idStr::Append(this: &v125, text: v52);
        idStr::Append(this: &v125, text: "  ");
        HIDWORD(v53) = v4->tm_hour;
        v56 = va::va(
                this: &v128,
                fmt: "%d",
                a3: v53,
                a4: v55,
                a5: v54,
                a6: v69,
                a7: v80,
                a8: v91,
                a9: v102,
                a10: v113,
                a11: v124);
        idStr::Append(this: &v125, text: v56);
        idStr::Append(this: &v125, text: ":");
        HIDWORD(v42) = &unk_82390000;
      }
      HIDWORD(v43) = v4->tm_min;
      v57 = va::va(
              this: &v128,
              fmt: "%02d",
              a3: v43,
              a4: v42,
              a5: v41,
              a6: v66,
              a7: v77,
              a8: v88,
              a9: v99,
              a10: v110,
              a11: v121);
      idStr::Append(this: &v125, text: v57);
      goto LABEL_22;
    }
    LODWORD(v5) = 0x82000000;
    v8 = "%02d";
    if ( !padded )
      v8 = "%d";
    HIDWORD(v7) = v4->tm_mon + 1;
    v9 = va::va(this: &v128, fmt: v8, a3: v7, a4: v6, a5: v5, a6: v59, a7: v70, a8: v81, a9: v92, a10: v103, a11: v114);
    idStr::operator=(this: &v125, text: v9);
    idStr::Append(this: &v125, text: "/");
    v13 = "%02d";
    if ( !padded )
      v13 = "%d";
    HIDWORD(v12) = v4->tm_mday;
    v14 = va::va(
            this: &v128,
            fmt: v13,
            a3: v12,
            a4: v11,
            a5: v10,
            a6: v60,
            a7: v71,
            a8: v82,
            a9: v93,
            a10: v104,
            a11: v115);
    idStr::Append(this: &v125, text: v14);
    idStr::Append(this: &v125, text: "/");
    HIDWORD(v15) = v4->tm_year + 1900;
    v18 = va::va(
            this: &v128,
            fmt: "%d",
            a3: v15,
            a4: v17,
            a5: v16,
            a6: v61,
            a7: v72,
            a8: v83,
            a9: v94,
            a10: v105,
            a11: v116);
    idStr::Append(this: &v125, text: v18);
    idStr::Append(this: &v125, text: "  ");
    HIDWORD(v21) = v4->tm_hour;
    if ( SHIDWORD(v21) <= 12 )
    {
      if ( HIDWORD(v21) == 0 )
      {
        idStr::Append(this: &v125, text: "12");
        goto LABEL_15;
      }
      v22 = "%02d";
      if ( padded )
      {
LABEL_14:
        v25 = va::va(
                this: &v128,
                fmt: v22,
                a3: v21,
                a4: v20,
                a5: v19,
                a6: v62,
                a7: v73,
                a8: v84,
                a9: v95,
                a10: v106,
                a11: v117);
        idStr::Append(this: &v125, text: v25);
LABEL_15:
        LODWORD(v26) = v4->tm_sec;
        HIDWORD(v26) = v4->tm_min;
        v27 = va::va(
                this: &v128,
                fmt: ":%02d:%02d",
                a3: v26,
                a4: v24,
                a5: v23,
                a6: v62,
                a7: v73,
                a8: v84,
                a9: v95,
                a10: v106,
                a11: v117);
        idStr::Append(this: &v125, text: v27);
        if ( v4->tm_hour < 12 )
          idStr::Append(this: &v125, text: "am");
        else
          idStr::Append(this: &v125, text: "pm");
LABEL_22:
        idStr::Copynz(dest: timeString_0, src: v125.data, destsize: 128);
        idStr::FreeData(this: &v127);
        idStr::FreeData(this: &v125);
        return timeString_0;
      }
    }
    else
    {
      HIDWORD(v21) -= 12;
      if ( padded )
      {
        v22 = "%02d";
        goto LABEL_14;
      }
    }
    v22 = "%d";
    goto LABEL_14;
  }
  return timeString_0;
}


// ========================================================================
// __unwind$114415
// EA  : 0x82F8229C
// RVA : 0x00F8229C
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

void _unwind_114415()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 80));
}


// ========================================================================
// __unwind$114416
// EA  : 0x82F822C4
// RVA : 0x00F822C4
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

void _unwind_114416()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 128));
}


// ========================================================================
// ?Sys_DateStr@@YAPBD_N@Z
// EA  : 0x82F822F0
// RVA : 0x00F822F0
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

char *__fastcall Sys_DateStr(bool padded)
{
  int v2; // r3

  v2 = (unsigned __int64)time64(timeptr: nullptr) >> 32;
  return Sys_TimeStampToStr(timeStamp: v2, padded);
}


// ========================================================================
// ?Sys_SecToStr@@YA?AVidStr@@H@Z
// EA  : 0x82F82338
// RVA : 0x00F82338
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

idStr *__fastcall Sys_SecToStr(idStr *result, int sec)
{
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r8
  int v7; // r29
  va *v8; // r3
  va *v9; // r3
  va *v10; // r3
  __int64 v11; // r10
  int v12; // r30
  __int64 v13; // r8
  __int64 v14; // r6
  va *v15; // r3
  __int64 v16; // r6
  __int64 v17; // r10
  __int64 v18; // r8
  va *v19; // r3
  int v21; // [sp+8h] [-1088h]
  int v22; // [sp+8h] [-1088h]
  int v23; // [sp+8h] [-1088h]
  int v24; // [sp+Ch] [-1084h]
  int v25; // [sp+Ch] [-1084h]
  int v26; // [sp+Ch] [-1084h]
  int v27; // [sp+10h] [-1080h]
  int v28; // [sp+10h] [-1080h]
  int v29; // [sp+10h] [-1080h]
  int v30; // [sp+14h] [-107Ch]
  int v31; // [sp+14h] [-107Ch]
  int v32; // [sp+14h] [-107Ch]
  int v33; // [sp+18h] [-1078h]
  int v34; // [sp+18h] [-1078h]
  int v35; // [sp+18h] [-1078h]
  int v36; // [sp+1Ch] [-1074h]
  int v37; // [sp+1Ch] [-1074h]
  int v38; // [sp+1Ch] [-1074h]
  va v39; // [sp+60h] [-1030h] BYREF

  idStr::idStr(this: result, text: &byte_8200D768);
  HIDWORD(v5) = 589824;
  LODWORD(v6) = 1;
  v7 = sec / 604800;
  if ( sec / 604800 > 0 )
  {
    HIDWORD(v4) = sec / 604800;
    v8 = va::va(
           this: &v39,
           fmt: "%dw, ",
           a3: v4,
           a4: v6,
           a5: v5,
           a6: v21,
           a7: v24,
           a8: v27,
           a9: v30,
           a10: v33,
           a11: v36);
    idStr::Append(this: result, text: v8);
    LODWORD(v5) = 604800 * v7;
    sec %= 604800;
  }
  if ( v7 > 0 || sec / 86400 > 0 )
  {
    HIDWORD(v4) = sec / 86400;
    v9 = va::va(
           this: &v39,
           fmt: "%dd, ",
           a3: v4,
           a4: v6,
           a5: v5,
           a6: v21,
           a7: v24,
           a8: v27,
           a9: v30,
           a10: v33,
           a11: v36);
    idStr::Append(this: result, text: v9);
    sec %= 86400;
  }
  LODWORD(v5) = &unk_821F0000;
  HIDWORD(v4) = sec / 3600;
  v10 = va::va(this: &v39, fmt: "%d:", a3: v4, a4: v6, a5: v5, a6: v21, a7: v24, a8: v27, a9: v30, a10: v33, a11: v36);
  idStr::Append(this: result, text: v10);
  HIDWORD(v11) = 3600 * (sec / 3600);
  v12 = sec % 3600;
  LODWORD(v13) = 60;
  HIDWORD(v13) = &unk_82390000;
  HIDWORD(v14) = v12 / 60;
  v15 = va::va(
          this: &v39,
          fmt: "%02d",
          a3: v14,
          a4: v13,
          a5: v11,
          a6: v22,
          a7: v25,
          a8: v28,
          a9: v31,
          a10: v34,
          a11: v37);
  idStr::Append(this: result, text: v15);
  LODWORD(v16) = 60 * (v12 / 60);
  HIDWORD(v16) = v12 % 60;
  v19 = va::va(
          this: &v39,
          fmt: ":%02d",
          a3: v16,
          a4: v18,
          a5: v17,
          a6: v23,
          a7: v26,
          a8: v29,
          a9: v32,
          a10: v35,
          a11: v38);
  idStr::Append(this: result, text: v19);
  return result;
}


// ========================================================================
// __unwind$114817
// EA  : 0x82F82478
// RVA : 0x00F82478
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

void _unwind_114817()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4240;
  if ( (*(_DWORD *)(v0 - 4240 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 4260));
  }
}


// ========================================================================
// `dynamic initializer for 'sys_langJapanese''
// EA  : 0x83396C68
// RVA : 0x01396C68
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sys_langJapanese__()
{
  idCVar::idCVar(
    this: &sys_langJapanese,
    name: "sys_langJapanese",
    value: "0",
    flags: 17,
    description: "uses to store if we are using japanese or not so we don't have to do a string compare when rendering text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sys_langJapanese__);
}


// ========================================================================
// `dynamic initializer for 'sys_langPolish''
// EA  : 0x83396CC0
// RVA : 0x01396CC0
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sys_langPolish__()
{
  idCVar::idCVar(
    this: &sys_langPolish,
    name: "sys_langPolish",
    value: "0",
    flags: 17,
    description: "uses to store if we are using polish or not so we don't have to do a string compare when rendering text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sys_langPolish__);
}


// ========================================================================
// `dynamic initializer for 'sys_lang''
// EA  : 0x83396D18
// RVA : 0x01396D18
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sys_lang__()
{
  idCVar::idCVar(
    this: &sys_lang,
    name: "sys_lang",
    value: "english",
    flags: 16,
    description: &byte_8200D768,
    valueStrings: sysLanguageNames,
    valueCompletion: idCmdSystem::ArgCompletion_String<&char const * * sysLanguageNames>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sys_lang__);
}


// ========================================================================
// `dynamic initializer for 'sys_localization''
// EA  : 0x83396D78
// RVA : 0x01396D78
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sys_localization__()
{
  idCVar::idCVar(
    this: &sys_localization,
    name: "sys_localization",
    value: "0",
    flags: 17,
    description: "if 1, strings and vo can live outside a retail package",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sys_localization__);
}


// ========================================================================
// `dynamic initializer for 'sys_langSingle''
// EA  : 0x83396DD0
// RVA : 0x01396DD0
// PDB : w:\tech5\shared\idlib\sys\sys_time.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sys_langSingle__()
{
  idCVar::idCVar(
    this: &sys_langSingle,
    name: "sys_langSingle",
    value: "0",
    flags: 2,
    description: "if not -1, select single language (works most of the time)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sys_langSingle__);
}

