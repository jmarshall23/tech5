
// ========================================================================
// ?Write@idEyeInfo@@QAAXPBVidDeclMD6@@AAVidFile_String@@PBD@Z
// EA  : 0x82819F60
// RVA : 0x00819F60
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEyeInfo::Write(
        idEyeInfo *this,
        const idDeclMD6 *declMD6,
        idFile_String *out,
        const char *indent,
        __int64 a5,
        __int64 a6)
{
  __int64 v10; // r6
  va *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  va *v15; // r3
  __int64 v16; // r10
  __int64 v17; // r8
  va *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  va *v21; // r3
  __int64 v22; // r8
  __int64 v23; // r10
  va *v24; // r3
  __int64 v25; // r8
  __int64 v26; // r10
  va *v27; // r3
  __int64 v28; // r10
  __int64 v29; // r8
  va *v30; // r3
  __int64 v31; // r10
  __int64 v32; // r8
  va *v33; // r3
  __int64 v34; // r10
  __int64 v35; // r8
  va *v36; // r3
  __int64 v37; // r10
  __int64 v38; // r8
  va *v39; // r3
  __int64 v40; // r10
  __int64 v41; // r8
  idEyeInfo::perEyeInfo_t *perEyeInfo; // r29
  const char **v43; // r28
  __int64 v44; // r6
  va *v45; // r3
  unsigned int i; // r5
  __int64 v47; // r10
  __int64 v48; // r8
  va *v49; // r3
  unsigned int j; // r5
  __int64 v51; // r10
  __int64 v52; // r8
  va *v53; // r3
  unsigned int k; // r5
  __int64 v55; // r10
  __int64 v56; // r8
  va *v57; // r3
  unsigned int m; // r5
  __int64 v59; // r10
  __int64 v60; // r8
  va *v61; // r3
  unsigned int n; // r5
  __int64 v63; // r10
  __int64 v64; // r8
  va *v65; // r3
  unsigned int ii; // r5
  __int64 v67; // r10
  __int64 v68; // r8
  va *v69; // r3
  unsigned int jj; // r5
  __int128 v71; // r7 OVERLAPPED
  int v72; // r8
  __int64 v73; // r10
  va *v74; // r3
  unsigned int kk; // r5
  __int64 v76; // r6
  __int64 v77; // r10
  __int64 v78; // r8
  va *v79; // r3
  unsigned int mm; // r5
  __int64 v81; // r6
  va *v82; // r3
  unsigned int nn; // r5
  int v84; // [sp+8h] [-10C8h]
  int v85; // [sp+8h] [-10C8h]
  int v86; // [sp+8h] [-10C8h]
  int v87; // [sp+8h] [-10C8h]
  int v88; // [sp+8h] [-10C8h]
  int v89; // [sp+8h] [-10C8h]
  int v90; // [sp+8h] [-10C8h]
  int v91; // [sp+8h] [-10C8h]
  int v92; // [sp+8h] [-10C8h]
  int v93; // [sp+8h] [-10C8h]
  int v94; // [sp+8h] [-10C8h]
  int v95; // [sp+8h] [-10C8h]
  int v96; // [sp+8h] [-10C8h]
  int v97; // [sp+8h] [-10C8h]
  int v98; // [sp+8h] [-10C8h]
  int v99; // [sp+8h] [-10C8h]
  int v100; // [sp+8h] [-10C8h]
  int v101; // [sp+8h] [-10C8h]
  int v102; // [sp+8h] [-10C8h]
  int v103; // [sp+Ch] [-10C4h]
  int v104; // [sp+Ch] [-10C4h]
  int v105; // [sp+Ch] [-10C4h]
  int v106; // [sp+Ch] [-10C4h]
  int v107; // [sp+Ch] [-10C4h]
  int v108; // [sp+Ch] [-10C4h]
  int v109; // [sp+Ch] [-10C4h]
  int v110; // [sp+Ch] [-10C4h]
  int v111; // [sp+Ch] [-10C4h]
  int v112; // [sp+Ch] [-10C4h]
  int v113; // [sp+Ch] [-10C4h]
  int v114; // [sp+Ch] [-10C4h]
  int v115; // [sp+Ch] [-10C4h]
  int v116; // [sp+Ch] [-10C4h]
  int v117; // [sp+Ch] [-10C4h]
  int v118; // [sp+Ch] [-10C4h]
  int v119; // [sp+Ch] [-10C4h]
  int v120; // [sp+Ch] [-10C4h]
  int v121; // [sp+Ch] [-10C4h]
  int v122; // [sp+10h] [-10C0h]
  int v123; // [sp+10h] [-10C0h]
  int v124; // [sp+10h] [-10C0h]
  int v125; // [sp+10h] [-10C0h]
  int v126; // [sp+10h] [-10C0h]
  int v127; // [sp+10h] [-10C0h]
  int v128; // [sp+10h] [-10C0h]
  int v129; // [sp+10h] [-10C0h]
  int v130; // [sp+10h] [-10C0h]
  int v131; // [sp+10h] [-10C0h]
  int v132; // [sp+10h] [-10C0h]
  int v133; // [sp+10h] [-10C0h]
  int v134; // [sp+10h] [-10C0h]
  int v135; // [sp+10h] [-10C0h]
  int v136; // [sp+10h] [-10C0h]
  int v137; // [sp+10h] [-10C0h]
  int v138; // [sp+10h] [-10C0h]
  int v139; // [sp+10h] [-10C0h]
  int v140; // [sp+10h] [-10C0h]
  int v141; // [sp+14h] [-10BCh]
  int v142; // [sp+14h] [-10BCh]
  int v143; // [sp+14h] [-10BCh]
  int v144; // [sp+14h] [-10BCh]
  int v145; // [sp+14h] [-10BCh]
  int v146; // [sp+14h] [-10BCh]
  int v147; // [sp+14h] [-10BCh]
  int v148; // [sp+14h] [-10BCh]
  int v149; // [sp+14h] [-10BCh]
  int v150; // [sp+14h] [-10BCh]
  int v151; // [sp+14h] [-10BCh]
  int v152; // [sp+14h] [-10BCh]
  int v153; // [sp+14h] [-10BCh]
  int v154; // [sp+14h] [-10BCh]
  int v155; // [sp+14h] [-10BCh]
  int v156; // [sp+14h] [-10BCh]
  int v157; // [sp+14h] [-10BCh]
  int v158; // [sp+14h] [-10BCh]
  int v159; // [sp+14h] [-10BCh]
  int v160; // [sp+18h] [-10B8h]
  int v161; // [sp+18h] [-10B8h]
  int v162; // [sp+18h] [-10B8h]
  int v163; // [sp+18h] [-10B8h]
  int v164; // [sp+18h] [-10B8h]
  int v165; // [sp+18h] [-10B8h]
  int v166; // [sp+18h] [-10B8h]
  int v167; // [sp+18h] [-10B8h]
  int v168; // [sp+18h] [-10B8h]
  int v169; // [sp+18h] [-10B8h]
  int v170; // [sp+18h] [-10B8h]
  int v171; // [sp+18h] [-10B8h]
  int v172; // [sp+18h] [-10B8h]
  int v173; // [sp+18h] [-10B8h]
  int v174; // [sp+18h] [-10B8h]
  int v175; // [sp+18h] [-10B8h]
  int v176; // [sp+18h] [-10B8h]
  int v177; // [sp+18h] [-10B8h]
  int v178; // [sp+18h] [-10B8h]
  int v179; // [sp+1Ch] [-10B4h]
  int v180; // [sp+1Ch] [-10B4h]
  int v181; // [sp+1Ch] [-10B4h]
  int v182; // [sp+1Ch] [-10B4h]
  int v183; // [sp+1Ch] [-10B4h]
  int v184; // [sp+1Ch] [-10B4h]
  int v185; // [sp+1Ch] [-10B4h]
  int v186; // [sp+1Ch] [-10B4h]
  int v187; // [sp+1Ch] [-10B4h]
  int v188; // [sp+1Ch] [-10B4h]
  int v189; // [sp+1Ch] [-10B4h]
  int v190; // [sp+1Ch] [-10B4h]
  int v191; // [sp+1Ch] [-10B4h]
  int v192; // [sp+1Ch] [-10B4h]
  int v193; // [sp+1Ch] [-10B4h]
  int v194; // [sp+1Ch] [-10B4h]
  int v195; // [sp+1Ch] [-10B4h]
  int v196; // [sp+1Ch] [-10B4h]
  int v197; // [sp+1Ch] [-10B4h]
  double roll; // [sp+38h] [-1098h]
  va v199; // [sp+50h] [-1080h] BYREF

  HIDWORD(v10) = indent;
  LODWORD(v10) = this->name.data;
  v11 = va::va(
          this: &v199,
          fmt: "%seyeInfo \"%s\" {\n",
          a3: v10,
          a4: a5,
          a5: a6,
          a6: v84,
          a7: v103,
          a8: v122,
          a9: v141,
          a10: v160,
          a11: v179);
  idFile_String::operator+=(this: out, str: v11->buffer);
  if ( declMD6 != nullptr )
    LODWORD(v14) = idDeclMD6::GetJointName(
                     this: declMD6,
                     idx: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->basisJointIndex.value);
  else
    LODWORD(v14) = &byte_8200D768;
  HIDWORD(v14) = indent;
  v15 = va::va(
          this: &v199,
          fmt: "%s\tbasisJoint \"%s\"\n",
          a3: v14,
          a4: v13,
          a5: v12,
          a6: v85,
          a7: v104,
          a8: v123,
          a9: v142,
          a10: v161,
          a11: v180);
  idFile_String::operator+=(this: out, str: v15->buffer);
  LODWORD(v16) = &unk_82210000;
  v18 = va::va(
          this: &v199,
          fmt: "%s\tminPitch %g\n",
          a3: __SPAIR64__((unsigned int)indent, COERCE_UNSIGNED_INT64(this->minEyePitch)),
          a4: v17,
          a5: v16,
          a6: v86,
          a7: v105,
          a8: v124,
          a9: v143,
          a10: v162,
          a11: v181);
  idFile_String::operator+=(this: out, str: v18->buffer);
  HIDWORD(v19) = &unk_82210000;
  v21 = va::va(
          this: &v199,
          fmt: "%s\tmaxPitch %g\n",
          a3: __SPAIR64__((unsigned int)indent, COERCE_UNSIGNED_INT64(this->maxEyePitch)),
          a4: v20,
          a5: v19,
          a6: v87,
          a7: v106,
          a8: v125,
          a9: v144,
          a10: v163,
          a11: v182);
  idFile_String::operator+=(this: out, str: v21->buffer);
  LODWORD(v22) = &unk_82210000;
  v24 = va::va(
          this: &v199,
          fmt: "%s\tminYaw %g\n",
          a3: __SPAIR64__((unsigned int)indent, COERCE_UNSIGNED_INT64(this->minEyeYaw)),
          a4: v22,
          a5: v23,
          a6: v88,
          a7: v107,
          a8: v126,
          a9: v145,
          a10: v164,
          a11: v183);
  idFile_String::operator+=(this: out, str: v24->buffer);
  HIDWORD(v25) = &unk_82210000;
  v27 = va::va(
          this: &v199,
          fmt: "%s\tmaxYaw %g\n",
          a3: __SPAIR64__((unsigned int)indent, COERCE_UNSIGNED_INT64(this->maxEyeYaw)),
          a4: v25,
          a5: v26,
          a6: v89,
          a7: v108,
          a8: v127,
          a9: v146,
          a10: v165,
          a11: v184);
  idFile_String::operator+=(this: out, str: v27->buffer);
  v30 = va::va(
          this: &v199,
          fmt: "%s\tlidMinPitch %g\n",
          a3: __SPAIR64__((unsigned int)indent, COERCE_UNSIGNED_INT64(this->lidMinPitch)),
          a4: v29,
          a5: v28,
          a6: v90,
          a7: v109,
          a8: v128,
          a9: v147,
          a10: v166,
          a11: v185);
  idFile_String::operator+=(this: out, str: v30->buffer);
  v33 = va::va(
          this: &v199,
          fmt: "%s\tlidMaxPitch %g\n",
          a3: __SPAIR64__((unsigned int)indent, COERCE_UNSIGNED_INT64(this->lidMaxPitch)),
          a4: v32,
          a5: v31,
          a6: v91,
          a7: v110,
          a8: v129,
          a9: v148,
          a10: v167,
          a11: v186);
  idFile_String::operator+=(this: out, str: v33->buffer);
  v36 = va::va(
          this: &v199,
          fmt: "%s\tlidMinYaw %g\n",
          a3: COERCE__INT64(this->lidMinYaw),
          a4: v35,
          a5: v34,
          a6: v92,
          a7: v111,
          a8: v130,
          a9: v149,
          a10: v168,
          a11: v187);
  idFile_String::operator+=(this: out, str: v36->buffer);
  LODWORD(v37) = &unk_82210000;
  v39 = va::va(
          this: &v199,
          fmt: "%s\tlidMaxYaw %g\n",
          a3: __SPAIR64__((unsigned int)indent, COERCE_UNSIGNED_INT64(this->lidMaxYaw)),
          a4: v38,
          a5: v37,
          a6: v93,
          a7: v112,
          a8: v131,
          a9: v150,
          a10: v169,
          a11: v188);
  idFile_String::operator+=(this: out, str: v39->buffer);
  LODWORD(v40) = &unk_82210000;
  HIDWORD(v40) = &unk_82210000;
  LODWORD(v41) = &unk_82210000;
  HIDWORD(v41) = &unk_82210000;
  perEyeInfo = this->perEyeInfo;
  v43 = idEyeInfo::eyeNames;
  do
  {
    LODWORD(v44) = *v43;
    HIDWORD(v44) = indent;
    v45 = va::va(
            this: &v199,
            fmt: "%s\t%s {\n",
            a3: v44,
            a4: v41,
            a5: v40,
            a6: v94,
            a7: v113,
            a8: v132,
            a9: v151,
            a10: v170,
            a11: v189);
    for ( i = 0; v45->buffer[i] != 0; ++i )
      ;
    out->Write(this: out, a2: v45, a3: i);
    v49 = va::va(
            this: &v199,
            fmt: "%s\t\tfocusScale %g\n",
            a3: __SPAIR64__((unsigned int)indent, COERCE_UNSIGNED_INT64(perEyeInfo->focusScale)),
            a4: v48,
            a5: v47,
            a6: v95,
            a7: v114,
            a8: v133,
            a9: v152,
            a10: v171,
            a11: v190);
    for ( j = 0; v49->buffer[j] != 0; ++j )
      ;
    out->Write(this: out, a2: v49, a3: j);
    v53 = va::va(
            this: &v199,
            fmt: "%s\t\twanderRate %g\n",
            a3: __SPAIR64__((unsigned int)indent, COERCE_UNSIGNED_INT64(perEyeInfo->wanderRate)),
            a4: v52,
            a5: v51,
            a6: v96,
            a7: v115,
            a8: v134,
            a9: v153,
            a10: v172,
            a11: v191);
    for ( k = 0; v53->buffer[k] != 0; ++k )
      ;
    out->Write(this: out, a2: v53, a3: k);
    v57 = va::va(
            this: &v199,
            fmt: "%s\t\tmaxWanderPitch %g\n",
            a3: __SPAIR64__((unsigned int)indent, COERCE_UNSIGNED_INT64(perEyeInfo->maxWanderPitch)),
            a4: v56,
            a5: v55,
            a6: v97,
            a7: v116,
            a8: v135,
            a9: v154,
            a10: v173,
            a11: v192);
    for ( m = 0; v57->buffer[m] != 0; ++m )
      ;
    out->Write(this: out, a2: v57, a3: m);
    v61 = va::va(
            this: &v199,
            fmt: "%s\t\tmaxWanderYaw %g\n",
            a3: COERCE__INT64(perEyeInfo->maxWanderYaw),
            a4: v60,
            a5: v59,
            a6: v98,
            a7: v117,
            a8: v136,
            a9: v155,
            a10: v174,
            a11: v193);
    for ( n = 0; v61->buffer[n] != 0; ++n )
      ;
    out->Write(this: out, a2: v61, a3: n);
    v65 = va::va(
            this: &v199,
            fmt: "%s\t\tjitterScale %g\n",
            a3: COERCE__INT64(perEyeInfo->jitterScale),
            a4: v64,
            a5: v63,
            a6: v99,
            a7: v118,
            a8: v137,
            a9: v156,
            a10: v175,
            a11: v194);
    for ( ii = 0; v65->buffer[ii] != 0; ++ii )
      ;
    out->Write(this: out, a2: v65, a3: ii);
    v69 = va::va(
            this: &v199,
            fmt: "%s\t\tslerpScale %g\n",
            a3: COERCE__INT64(perEyeInfo->slerpScale),
            a4: v68,
            a5: v67,
            a6: v100,
            a7: v119,
            a8: v138,
            a9: v157,
            a10: v176,
            a11: v195);
    for ( jj = 0; v69->buffer[jj] != 0; ++jj )
      ;
    out->Write(this: out, a2: v69, a3: jj);
    DWORD1(v71) = indent;
    roll = perEyeInfo->angleOffset.roll;
    v72 = LODWORD(roll);
    *((double *)&v71 + 1) = perEyeInfo->angleOffset.yaw;
    v74 = va::va(
            this: &v199,
            fmt: "%s\t\tangleOffset ( %g %g %g )\n",
            a3: *(__int64 *)((char *)&v71 + 4),
            a4: *(__int64 *)((char *)&v71 - 4),
            a5: v73,
            a6: v101,
            a7: v120,
            a8: v139,
            a9: v158,
            a10: v177,
            a11: v196);
    for ( kk = 0; v74->buffer[kk] != 0; ++kk )
      ;
    out->Write(this: out, a2: v74, a3: kk);
    HIDWORD(v76) = indent;
    v79 = va::va(
            this: &v199,
            fmt: "%s\t}\n",
            a3: v76,
            a4: v78,
            a5: v77,
            a6: v102,
            a7: v121,
            a8: v140,
            a9: v159,
            a10: v178,
            a11: v197);
    for ( mm = 0; v79->buffer[mm] != 0; ++mm )
      ;
    out->Write(this: out, a2: v79, a3: mm);
    ++v43;
    HIDWORD(v40) = &idEyeInfoCollection::DEFAULT_NAME;
    ++perEyeInfo;
  }
  while ( (int)v43 < (int)&idEyeInfoCollection::DEFAULT_NAME );
  HIDWORD(v81) = indent;
  v82 = va::va(
          this: &v199,
          fmt: "%s}\n",
          a3: v81,
          a4: v41,
          a5: v40,
          a6: v94,
          a7: v113,
          a8: v132,
          a9: v151,
          a10: v170,
          a11: v189);
  for ( nn = 0; v82->buffer[nn] != 0; ++nn )
    ;
  out->Write(this: out, a2: v82, a3: nn);
}


// ========================================================================
// ?FindEyeInfoIndex@idEyeInfoCollection@@ABAHABV?$idHandle@GW4invalidEyeInfo_t@@$0PPPP@@@@Z
// EA  : 0x8281A500
// RVA : 0x0081A500
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

int __fastcall idEyeInfoCollection::FindEyeInfoIndex(
        idEyeInfoCollection *this,
        const idHandle<unsigned short,enum invalidEyeInfo_t,65535> *handle)
{
  int num; // r7
  int v3; // r10
  int v4; // r11
  idEyeInfo *list; // r9

  num = this->eyeInfos.num;
  v3 = 0;
  if ( num <= 0 )
    return -1;
  v4 = 0;
  list = this->eyeInfos.list;
  while ( list->handle.value != handle->value )
  {
    ++v3;
    list = &this->eyeInfos.list[++v4];
    if ( v3 >= num )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?FindEyeInfoIndex@idEyeInfoCollection@@ABAHPBD@Z
// EA  : 0x8281A550
// RVA : 0x0081A550
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

int __fastcall idEyeInfoCollection::FindEyeInfoIndex(idEyeInfoCollection *this, const char *name)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->eyeInfos.num <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: this->eyeInfos.list[i].name.data, s2: name) != 0; ++i )
  {
    if ( ++v4 >= this->eyeInfos.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?IsInherited@idEyeInfoCollection@@ABA_NABVidEyeInfo@@PBV1@@Z
// EA  : 0x8281A5C0
// RVA : 0x0081A5C0
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

int __fastcall idEyeInfoCollection::IsInherited(
        idEyeInfoCollection *this,
        const idEyeInfo *info,
        const idEyeInfoCollection *parentCollection)
{
  int v5; // r27
  int i; // r29
  idEyeInfo *v7; // r31
  char v8; // r11

  if ( parentCollection == nullptr )
    return 0;
  v5 = 0;
  if ( parentCollection->eyeInfos.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v7 = &parentCollection->eyeInfos.list[i];
    if ( idStr::Cmp(s1: info->name.data, s2: v7->name.data) != 0
      || info->basisJointIndex.value != v7->basisJointIndex.value
      || info->minEyePitch != v7->minEyePitch
      || info->maxEyePitch != v7->maxEyePitch
      || info->minEyeYaw != v7->minEyeYaw
      || info->maxEyeYaw != v7->maxEyeYaw
      || info->lidMinPitch != v7->lidMinPitch
      || info->lidMaxPitch != v7->lidMaxPitch
      || info->lidMinYaw != v7->lidMinYaw
      || (v8 = 1, info->lidMaxYaw != v7->lidMaxYaw) )
    {
      v8 = 0;
    }
    if ( v8 != 0 )
      break;
    if ( ++v5 >= parentCollection->eyeInfos.num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ??0idEyeInfo@@QAA@XZ
// EA  : 0x8281A6E0
// RVA : 0x0081A6E0
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

idEyeInfo *__fastcall idEyeInfo::idEyeInfo(idEyeInfo *this)
{
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->handle.value = -1;
  this->basisJointIndex.value = -1;
  this->minEyePitch = -16.0;
  this->maxEyePitch = 16.0;
  this->minEyeYaw = -23.0;
  this->maxEyeYaw = 23.0;
  this->lidMinPitch = -15.0;
  this->lidMaxPitch = 15.0;
  this->lidMinYaw = -21.0;
  this->lidMaxYaw = 21.0;
  this->perEyeInfo[0].focusScale = 0.25;
  this->perEyeInfo[0].wanderRate = 0.0;
  this->perEyeInfo[0].maxWanderPitch = 15.0;
  this->perEyeInfo[0].maxWanderYaw = 15.0;
  this->perEyeInfo[0].jitterScale = 1.0;
  this->perEyeInfo[0].slerpScale = 0.5;
  this->perEyeInfo[0].angleOffset = ang_zero;
  this->perEyeInfo[1].focusScale = 0.25;
  this->perEyeInfo[1].wanderRate = 0.0;
  this->perEyeInfo[1].maxWanderPitch = 15.0;
  this->perEyeInfo[1].maxWanderYaw = 15.0;
  this->perEyeInfo[1].jitterScale = 1.0;
  this->perEyeInfo[1].slerpScale = 0.5;
  this->perEyeInfo[1].angleOffset = ang_zero;
  return this;
}


// ========================================================================
// ?Parse@idEyeInfo@@QAAXPBVidDeclMD6@@AAVidParser@@AAH@Z
// EA  : 0x8281A808
// RVA : 0x0081A808
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

void __fastcall idEyeInfo::Parse(idEyeInfo *this, const idDeclMD6 *declmd6, idParser *src, int *loadErrors)
{
  size_t v7; // r29
  const idMD6Model *model; // r11
  const char **v9; // r30
  int v10; // r29
  idIndex<short,enum invalidJointIndex_t> *skeleton; // [sp+54h] [-10Ch]
  idMD6Skel v12; // [sp+5Ah] [-106h] BYREF
  int v13; // [sp+A0h] [-C0h]
  int v14; // [sp+A4h] [-BCh]
  int v15; // [sp+B4h] [-ACh]
  float v16; // [sp+B8h] [-A8h]
  int v17; // [sp+BCh] [-A4h]
  int v18; // [sp+C0h] [-A0h]
  int v19; // [sp+C4h] [-9Ch]

  *(const idMD6Anim **)((char *)&v12.defaultAnim + 2) = nullptr;
  *(unsigned int *)((char *)&v12.timestamp + 2) = 20;
  v16 = -3.4028235e38;
  *(idMD6SkelData **)((char *)&v12.data + 2) = (idMD6SkelData *)&v12.jointConversionChecksum;
  HIBYTE(v12.jointConversionChecksum.value) = 0;
  v15 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: (idToken *)((char *)&v12.defaultAnim + 2));
  v7 = *(size_t *)((char *)&v12.defaultAnim + 2);
  idStr::EnsureAlloced(
    this: &this->name,
    amount: (int)&(*(const idMD6Anim **)((char *)&v12.defaultAnim + 2))->__vftable + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->name.data, Src: *(const void **)((char *)&v12.data + 2), Size: v7);
  this->name.data[v7] = 0;
  this->name.len = v7;
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: (idToken *)((char *)&v12.defaultAnim + 2));
  if ( idParser::ReadToken(this: src, token: (idToken *)((char *)&v12.defaultAnim + 2)) )
  {
    *(const char **)((char *)&v12.resourceError + 2) = "lidMinPitch";
    *(const char **)((char *)&v12.name.str + 2) = "maxPitch";
    *(idResourceList **)((char *)&v12.resourceListPtr + 2) = (idResourceList *)"maxYaw";
    *(idResource **)((char *)&v12.nextOnHashChain + 2) = (idResource *)"minYaw";
    *(int *)((char *)&v12.trackedMemory + 2) = (int)"minPitch";
    *(idMD6Skel_vtbl **)((char *)&v12.__vftable + 2) = (idMD6Skel_vtbl *)"basisJoint";
    do
    {
      if ( v13 == 5 && v14 == 47 )
        break;
      if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: *(const char **)((char *)&v12.__vftable + 2)) != 0 )
      {
        if ( idStr::Cmp(
               s1: *(const char **)((char *)&v12.data + 2),
               s2: *(const char **)((char *)&v12.trackedMemory + 2)) != 0 )
        {
          if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: *(const char **)((char *)&v12.name.str + 2)) != 0 )
          {
            if ( idStr::Cmp(
                   s1: *(const char **)((char *)&v12.data + 2),
                   s2: *(const char **)((char *)&v12.nextOnHashChain + 2)) != 0 )
            {
              if ( idStr::Cmp(
                     s1: *(const char **)((char *)&v12.data + 2),
                     s2: *(const char **)((char *)&v12.resourceListPtr + 2)) != 0 )
              {
                if ( idStr::Cmp(
                       s1: *(const char **)((char *)&v12.data + 2),
                       s2: *(const char **)((char *)&v12.resourceError + 2)) != 0 )
                {
                  if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: "lidMaxPitch") != 0 )
                  {
                    if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: "lidMinYaw") != 0 )
                    {
                      if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: "lidMaxYaw") != 0 )
                      {
                        if ( v13 != 4 )
                          goto LABEL_53;
                        v9 = idEyeInfo::eyeNames;
                        v10 = 0;
                        while ( idStr::Icmp(s1: *(const char **)((char *)&v12.data + 2), s2: *v9) != 0 )
                        {
                          ++v9;
                          ++v10;
                          if ( (int)v9 >= (int)&idEyeInfoCollection::DEFAULT_NAME )
                            goto LABEL_53;
                        }
                        idParser::ExpectTokenType(
                          this: src,
                          type: 5,
                          subtype: 46,
                          token: (idToken *)((char *)&v12.defaultAnim + 2));
                        while ( idParser::ReadToken(this: src, token: (idToken *)((char *)&v12.defaultAnim + 2)) )
                        {
                          if ( v13 == 5 && v14 == 47 )
                            break;
                          if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: "focusScale") != 0 )
                          {
                            if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: "wanderRate") != 0 )
                            {
                              if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: "maxWanderPitch") != 0 )
                              {
                                if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: "maxWanderYaw") != 0 )
                                {
                                  if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: "jitterScale") != 0 )
                                  {
                                    if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: "slerpScale") != 0 )
                                    {
                                      if ( idStr::Cmp(s1: *(const char **)((char *)&v12.data + 2), s2: "angleOffset") != 0 )
                                        idParser::Error(
                                          this: src,
                                          str: "Unknown token '%s' in modeldef '%s' eyeInfo '%s'",
                                          *(const char **)((char *)&v12.data + 2),
                                          declmd6->name.str,
                                          this->name.data);
                                      else
                                        idParser::Parse1DMatrix(
                                          this: src,
                                          x: 3,
                                          m: &this->perEyeInfo[v10].angleOffset.pitch);
                                    }
                                    else
                                    {
                                      this->perEyeInfo[v10].slerpScale = idParser::ParseFloat(
                                                                           this: src,
                                                                           errorFlag: nullptr);
                                    }
                                  }
                                  else
                                  {
                                    this->perEyeInfo[v10].jitterScale = idParser::ParseFloat(
                                                                          this: src,
                                                                          errorFlag: nullptr);
                                  }
                                }
                                else
                                {
                                  this->perEyeInfo[v10].maxWanderYaw = idParser::ParseFloat(
                                                                         this: src,
                                                                         errorFlag: nullptr);
                                }
                              }
                              else
                              {
                                this->perEyeInfo[v10].maxWanderPitch = idParser::ParseFloat(
                                                                         this: src,
                                                                         errorFlag: nullptr);
                              }
                            }
                            else
                            {
                              this->perEyeInfo[v10].wanderRate = idParser::ParseFloat(this: src, errorFlag: nullptr);
                            }
                          }
                          else
                          {
                            this->perEyeInfo[v10].focusScale = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          }
                        }
                        if ( v10 >= 2 )
LABEL_53:
                          idParser::Error(
                            this: src,
                            str: "Unknown token '%s' in modeldef '%s' eyeInfo '%s'",
                            *(const char **)((char *)&v12.data + 2),
                            declmd6->name.str,
                            this->name.data);
                      }
                      else
                      {
                        this->lidMaxYaw = idParser::ParseFloat(this: src, errorFlag: nullptr);
                      }
                    }
                    else
                    {
                      this->lidMinYaw = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    }
                  }
                  else
                  {
                    this->lidMaxPitch = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  this->lidMinPitch = idParser::ParseFloat(this: src, errorFlag: nullptr);
                }
              }
              else
              {
                this->maxEyeYaw = idParser::ParseFloat(this: src, errorFlag: nullptr);
              }
            }
            else
            {
              this->minEyeYaw = idParser::ParseFloat(this: src, errorFlag: nullptr);
            }
          }
          else
          {
            this->maxEyePitch = idParser::ParseFloat(this: src, errorFlag: nullptr);
          }
        }
        else
        {
          this->minEyePitch = idParser::ParseFloat(this: src, errorFlag: nullptr);
        }
      }
      else
      {
        idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: (idToken *)((char *)&v12.defaultAnim + 2));
        if ( declmd6 != nullptr )
        {
          model = declmd6->model;
          if ( model != nullptr && (skeleton = (idIndex<short,enum invalidJointIndex_t> *)model->skeleton) != nullptr )
            this->basisJointIndex = (idIndex<short,enum invalidJointIndex_t>)idMD6Skel::GetJointIndex(
                                                                               this: &v12,
                                                                               result: skeleton,
                                                                               name: *(const char **)((char *)&v12.data + 2))->value;
          else
            this->basisJointIndex.value = -1;
        }
        else
        {
          this->basisJointIndex.value = -1;
        }
      }
    }
    while ( idParser::ReadToken(this: src, token: (idToken *)((char *)&v12.defaultAnim + 2)) );
  }
  idStr::FreeData(this: (idStr *)((char *)&v12.defaultAnim + 2));
}


// ========================================================================
// __unwind$220579
// EA  : 0x8281ADA8
// RVA : 0x0081ADA8
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

void _unwind_220579()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 128));
}


// ========================================================================
// ?Write@idEyeInfoCollection@@QAAXPBVidDeclMD6@@AAVidFile_String@@PBD@Z
// EA  : 0x8281ADD8
// RVA : 0x0081ADD8
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

void __fastcall idEyeInfoCollection::Write(
        idEyeInfoCollection *this,
        const idDeclMD6 *declmd6,
        idFile_String *out,
        const char *indent,
        __int64 a5,
        __int64 a6)
{
  __int64 v10; // r6
  va *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  char *data; // r4
  const idDecl *v16; // r3
  const idEyeInfoCollection *p_staleCount; // r28
  va *v18; // r3
  __int64 v19; // r8
  __int64 v20; // r6
  __int64 v21; // r10
  int v22; // r27
  int v23; // r29
  va *v24; // r3
  unsigned int i; // r5
  int v26; // [sp+8h] [-20B8h]
  int v27; // [sp+8h] [-20B8h]
  int v28; // [sp+8h] [-20B8h]
  int v29; // [sp+Ch] [-20B4h]
  int v30; // [sp+Ch] [-20B4h]
  int v31; // [sp+Ch] [-20B4h]
  int v32; // [sp+10h] [-20B0h]
  int v33; // [sp+10h] [-20B0h]
  int v34; // [sp+10h] [-20B0h]
  int v35; // [sp+14h] [-20ACh]
  int v36; // [sp+14h] [-20ACh]
  int v37; // [sp+14h] [-20ACh]
  int v38; // [sp+18h] [-20A8h]
  int v39; // [sp+18h] [-20A8h]
  int v40; // [sp+18h] [-20A8h]
  int v41; // [sp+1Ch] [-20A4h]
  int v42; // [sp+1Ch] [-20A4h]
  int v43; // [sp+1Ch] [-20A4h]
  idStr v44; // [sp+50h] [-2070h] BYREF
  va v45; // [sp+70h] [-2050h] BYREF
  va v46; // [sp+1070h] [-1050h] BYREF

  HIDWORD(v10) = indent;
  LODWORD(v10) = this->eyeInfos.num;
  v11 = va::va(
          this: &v45,
          fmt: "%seyeInfoCollection %d {\n",
          a3: v10,
          a4: a5,
          a5: a6,
          a6: v26,
          a7: v29,
          a8: v32,
          a9: v35,
          a10: v38,
          a11: v41);
  idFile_String::operator+=(this: out, str: v11->buffer);
  data = declmd6->parent.data;
  if ( data == nullptr
    || (v16 = idDeclInfo::FindWithInheritance(this: &idDeclMD6::resourceList, name: data, makeDefault: false),
        p_staleCount = (const idEyeInfoCollection *)&v16[7].staleCount,
        v16 == nullptr) )
  {
    p_staleCount = nullptr;
  }
  HIDWORD(v14) = indent;
  v18 = va::va(
          this: &v45,
          fmt: "%s\t",
          a3: v14,
          a4: v13,
          a5: v12,
          a6: v27,
          a7: v30,
          a8: v33,
          a9: v36,
          a10: v39,
          a11: v42);
  idStr::idStr(this: &v44, text: v18);
  LODWORD(v21) = this->eyeInfos.num;
  v22 = 0;
  if ( (int)v21 > 0 )
  {
    v23 = 0;
    do
    {
      if ( p_staleCount == nullptr
        || (unsigned __int8)idEyeInfoCollection::IsInherited(
                              this,
                              info: &this->eyeInfos.list[v23],
                              parentCollection: p_staleCount) == 0 )
      {
        idEyeInfo::Write(this: &this->eyeInfos.list[v23], declMD6: declmd6, out, indent: v44.data, a5: v19, a6: v21);
      }
      ++v22;
      ++v23;
    }
    while ( v22 < this->eyeInfos.num );
  }
  HIDWORD(v20) = indent;
  v24 = va::va(
          this: &v46,
          fmt: "%s}\n",
          a3: v20,
          a4: v19,
          a5: v21,
          a6: v28,
          a7: v31,
          a8: v34,
          a9: v37,
          a10: v40,
          a11: v43);
  for ( i = 0; v24->buffer[i] != 0; ++i )
    ;
  out->Write(this: out, a2: v24, a3: i);
  idStr::FreeData(this: &v44);
}


// ========================================================================
// __unwind$220819_0
// EA  : 0x8281AF34
// RVA : 0x0081AF34
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

void _unwind_220819_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8384 + 80));
}


// ========================================================================
// ?GetEyeInfo@idEyeInfoCollection@@QBAPBVidEyeInfo@@ABV?$idHandle@GW4invalidEyeInfo_t@@$0PPPP@@@@Z
// EA  : 0x8281AF60
// RVA : 0x0081AF60
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

const idEyeInfo *__fastcall idEyeInfoCollection::GetEyeInfo(
        idEyeInfoCollection *this,
        const idHandle<unsigned short,enum invalidEyeInfo_t,65535> *handle)
{
  int v2; // r5
  int EyeInfoIndex; // r3

  EyeInfoIndex = idEyeInfoCollection::FindEyeInfoIndex(this, handle);
  if ( EyeInfoIndex >= 0 )
    return (const idEyeInfo *)(140 * EyeInfoIndex + *(_DWORD *)(v2 + 4));
  else
    return nullptr;
}


// ========================================================================
// ?FindEyeInfoHandle@idEyeInfoCollection@@QBA?AV?$idHandle@GW4invalidEyeInfo_t@@$0PPPP@@@PBD@Z
// EA  : 0x8281AFB0
// RVA : 0x0081AFB0
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

idEyeInfoCollection *__fastcall idEyeInfoCollection::FindEyeInfoHandle(
        idEyeInfoCollection *this,
        idEyeInfoCollection *result,
        const char *name)
{
  int EyeInfoIndex; // r3

  EyeInfoIndex = idEyeInfoCollection::FindEyeInfoIndex(this: result, name);
  if ( EyeInfoIndex >= 0 )
    this->curHandle = result->eyeInfos.list[EyeInfoIndex].handle.value;
  else
    this->curHandle = NULL_EYE_INFO_5.value;
  return this;
}


// ========================================================================
// ?Free@idEyeInfoCollection@@QAAXXZ
// EA  : 0x8281B088
// RVA : 0x0081B088
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

void __fastcall idEyeInfoCollection::Free(idEyeInfoCollection *this)
{
  idEyeInfo *list; // r3

  if ( this->eyeInfos.listStatic == 0 || this->eyeInfos.listStatic == 2 )
  {
    list = this->eyeInfos.list;
    if ( list != nullptr )
      idListArrayDelete<idEyeInfo>(ptr: &list->name, num: this->eyeInfos.size);
    this->eyeInfos.list = nullptr;
    this->eyeInfos.size = 0;
  }
  this->eyeInfos.num = 0;
  this->curHandle = 0;
}


// ========================================================================
// ??0idEyeInfoCollection@@QAA@XZ
// EA  : 0x8281B1B8
// RVA : 0x0081B1B8
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

idEyeInfoCollection *__fastcall idEyeInfoCollection::idEyeInfoCollection(idEyeInfoCollection *this)
{
  this->curHandle = 0;
  this->eyeInfos.granularity = 0;
  this->eyeInfos.memTag = 5;
  this->eyeInfos.listStatic = 0;
  this->eyeInfos.list = nullptr;
  this->eyeInfos.size = 0;
  this->eyeInfos.num = 0;
  return this;
}


// ========================================================================
// ??1idEyeInfoCollection@@QAA@XZ
// EA  : 0x8281B1E0
// RVA : 0x0081B1E0
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

void __fastcall idEyeInfoCollection::~idEyeInfoCollection(idEyeInfoCollection *this)
{
  idEyeInfo *list; // r3

  if ( this->eyeInfos.listStatic == 0 || this->eyeInfos.listStatic == 2 )
  {
    list = this->eyeInfos.list;
    if ( list != nullptr )
      idListArrayDelete<idEyeInfo>(ptr: &list->name, num: this->eyeInfos.size);
    this->eyeInfos.list = nullptr;
    this->eyeInfos.size = 0;
  }
  this->eyeInfos.num = 0;
}


// ========================================================================
// ?AddEyeInfo@idEyeInfoCollection@@QAA?AV?$idHandle@GW4invalidEyeInfo_t@@$0PPPP@@@ABVidEyeInfo@@@Z
// EA  : 0x8281B3C0
// RVA : 0x0081B3C0
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

idEyeInfoCollection *__fastcall idEyeInfoCollection::AddEyeInfo(
        idEyeInfoCollection *this,
        idHandle<unsigned short,enum invalidEyeInfo_t,65535> *result,
        const idEyeInfo *info)
{
  int v5; // r7
  int v6; // r11
  unsigned __int16 value; // r8

  idList<idEyeInfo,5>::Append(this: (idList<idEyeInfo,5> *)&result[2], obj: info);
  v5 = *(_DWORD *)&result[4].value;
  v6 = *(_DWORD *)&result[2].value;
  value = result->value;
  this->curHandle = result->value;
  result->value = value + 1;
  *(_WORD *)(140 * v5 + v6 - 108) = value;
  return this;
}


// ========================================================================
// ?DuplicateInherited@idEyeInfoCollection@@QAAXPBVidDeclMD6@@PBV1@@Z
// EA  : 0x8281B430
// RVA : 0x0081B430
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

void __fastcall idEyeInfoCollection::DuplicateInherited(
        idEyeInfoCollection *this,
        const idDeclMD6 *declmd6,
        const idEyeInfoCollection *parentCollection)
{
  int v5; // r24
  int v6; // r26
  char v7; // r27
  int v8; // r29
  idEyeInfo *v9; // r28
  int v10; // r30
  unsigned __int16 curHandle; // r8
  idEyeInfo *v12; // r5

  v5 = 0;
  if ( parentCollection->eyeInfos.num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = 0;
      v8 = 0;
      v9 = &parentCollection->eyeInfos.list[v6];
      if ( this->eyeInfos.num > 0 )
      {
        v10 = 0;
        while ( idStr::Icmp(s1: this->eyeInfos.list[v10].name.data, s2: v9->name.data) != 0 )
        {
          ++v8;
          ++v10;
          if ( v8 >= this->eyeInfos.num )
            goto LABEL_9;
        }
        v7 = 1;
      }
LABEL_9:
      if ( v7 == 0 )
      {
        idList<idEyeInfo,5>::Append(this: &this->eyeInfos, obj: v9);
        curHandle = this->curHandle;
        v12 = &this->eyeInfos.list[this->eyeInfos.num];
        ++this->curHandle;
        v12[-1].handle.value = curHandle;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < parentCollection->eyeInfos.num );
  }
}


// ========================================================================
// ?Parse@idEyeInfoCollection@@QAAXPBVidDeclMD6@@AAVidParser@@AAH@Z
// EA  : 0x8281B510
// RVA : 0x0081B510
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

void __fastcall idEyeInfoCollection::Parse(
        idEyeInfoCollection *this,
        const idDeclMD6 *decl,
        idParser *src,
        int *loadErrors)
{
  int v8; // r4
  idList<idEyeInfo,5> *p_eyeInfos; // r29
  int v10; // r11
  unsigned __int16 v11; // [sp+50h] [-140h]
  idToken v12; // [sp+60h] [-130h] BYREF
  idEyeInfo v13; // [sp+B0h] [-E0h] BYREF

  v12.len = 0;
  v12.allocedAndFlag = 20;
  v12.floatvalue = -3.4028235e38;
  v12.data = v12.baseBuffer;
  v12.baseBuffer[0] = 0;
  v12.intvalue = 0;
  memset(&v12.whiteSpaceStart_p, 0, 12);
  p_eyeInfos = &this->eyeInfos;
  v8 = idParser::ParseInt(this: src);
  if ( v8 > this->eyeInfos.size )
    idList<idEyeInfo,5>::Resize(this: &this->eyeInfos, newsize: v8);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v12);
  while ( idParser::ReadToken(this: src, token: &v12) )
  {
    if ( v12.type == 5 && v12.subtype == 47 )
      break;
    if ( idStr::Cmp(s1: v12.data, s2: "eyeInfo") != 0 )
    {
      idParser::Error(
        this: src,
        str: "Unknown token '%s' in model def '%s' in eye info collection.",
        v12.data,
        decl->name.str);
    }
    else
    {
      idEyeInfo::idEyeInfo(this: &v13);
      idEyeInfo::Parse(this: &v13, declmd6: decl, src, loadErrors);
      idList<idEyeInfo,5>::Append(this: &this->eyeInfos, obj: &v13);
      v10 = (int)&p_eyeInfos->list[this->eyeInfos.num];
      v11 = this->curHandle++;
      *(_WORD *)(v10 - 108) = v11;
      idStr::FreeData(this: &v13.name);
    }
  }
  idList<idEyeInfo,5>::Resize(this: &this->eyeInfos, newsize: this->eyeInfos.num);
  idStr::FreeData(this: &v12);
}


// ========================================================================
// __unwind$221408
// EA  : 0x8281B69C
// RVA : 0x0081B69C
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

void _unwind_221408()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 96));
}


// ========================================================================
// __unwind$221409
// EA  : 0x8281B6C4
// RVA : 0x0081B6C4
// PDB : w:\tech5\engine\models\skeletalanimation\eyeinfocollection.cpp
// ========================================================================

void _unwind_221409()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 176));
}

