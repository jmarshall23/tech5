
// ========================================================================
// ?GetCrosshairInfo@idCrosshairInfo@@SAABV1@W4usableState_t@@@Z
// EA  : 0x82DF95F8
// RVA : 0x00DF95F8
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

const idCrosshairInfo *__fastcall idCrosshairInfo::GetCrosshairInfo(const usableState_t ut)
{
  return &idCrosshairInfo::crosshairInfos[ut];
}


// ========================================================================
// ??0idCrosshairInfo@@QAA@XZ
// EA  : 0x82DF9618
// RVA : 0x00DF9618
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

idCrosshairInfo *__fastcall idCrosshairInfo::idCrosshairInfo(idCrosshairInfo *this)
{
  idStaticList<idCrosshairCustomIcon,3> *p_icons; // r28
  int size; // r29

  this->color = idCrosshairInfo::DEFAULT_COLOR;
  this->textColor = idCrosshairInfo::DEFAULT_TEXT_COLOR;
  p_icons = &this->icons;
  idStrId::Set(this: &this->text, key: &byte_8200D768);
  size = 1;
  this->material = CHMATERIAL_DEFAULT;
  this->colorState = CROSSHAIR_COLOR_NORMAL;
  this->textColorState = CROSSHAIR_TEXT_COLOR_NORMAL;
  this->hideCrossHairInfo = false;
  this->hoverSound = nullptr;
  this->icons.list = this->icons.staticList;
  this->icons.size = 3;
  this->icons.num = 0;
  this->icons.granularity = 1;
  this->icons.memTag = 5;
  this->icons.listStatic = 1;
  this->icons.staticList[0].material = nullptr;
  this->icons.staticList[0].itemCount = 0;
  this->icons.staticList[0].usable = true;
  this->icons.staticList[1].material = nullptr;
  this->icons.staticList[1].itemCount = 0;
  this->icons.staticList[1].usable = true;
  this->icons.staticList[2].material = nullptr;
  this->icons.staticList[2].itemCount = 0;
  this->icons.staticList[2].usable = true;
  this->useAmount = -1.0;
  if ( this->icons.size >= 1
    || (unsigned __int8)idList<idCrosshairCustomIcon,5>::Resize(this: &this->icons, newsize: 1) != 0 )
  {
    if ( this->icons.size <= 1 )
      size = p_icons->size;
    this->icons.num = size;
  }
  return this;
}


// ========================================================================
// __unwind$487456
// EA  : 0x82DF9754
// RVA : 0x00DF9754
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487456()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// ??0idCrosshairInfo@@QAA@ABVidColor@@0PBDW4crosshairMaterial_t@@W4crosshairColorState_t@@W4crosshairTextColorState_t@@PBVidMaterial@@PBVidSoundShader@@@Z
// EA  : 0x82DF9788
// RVA : 0x00DF9788
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

idCrosshairInfo *__fastcall idCrosshairInfo::idCrosshairInfo(
        idCrosshairInfo *this,
        const idColor *color_,
        const idColor *textColor_,
        const char *text_,
        crosshairMaterial_t material_,
        crosshairColorState_t colorState_,
        crosshairTextColorState_t textColorState_,
        const idMaterial *customMaterial_,
        const idSoundShader *hoverSound_,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idSoundShader *a28)
{
  idStaticList<idCrosshairCustomIcon,3> *p_icons; // r27
  int size; // r28

  this->color = *color_;
  this->textColor = *textColor_;
  p_icons = &this->icons;
  idStrId::Set(this: &this->text, key: text_);
  this->material = material_;
  this->colorState = colorState_;
  size = 1;
  this->textColorState = textColorState_;
  this->hideCrossHairInfo = false;
  this->hoverSound = a28;
  this->icons.num = 0;
  this->icons.size = 3;
  this->icons.granularity = 1;
  this->icons.list = this->icons.staticList;
  this->icons.memTag = 5;
  this->icons.listStatic = 1;
  this->icons.staticList[0].material = nullptr;
  this->icons.staticList[0].itemCount = 0;
  this->icons.staticList[0].usable = true;
  this->icons.staticList[1].material = nullptr;
  this->icons.staticList[1].itemCount = 0;
  this->icons.staticList[1].usable = true;
  this->icons.staticList[2].material = nullptr;
  this->icons.staticList[2].itemCount = 0;
  this->icons.staticList[2].usable = true;
  this->useAmount = -1.0;
  if ( this->icons.size >= 1
    || (unsigned __int8)idList<idCrosshairCustomIcon,5>::Resize(this: &this->icons, newsize: 1) != 0 )
  {
    if ( this->icons.size <= 1 )
      size = p_icons->size;
    this->icons.num = size;
  }
  this->useCheckbox = false;
  return this;
}


// ========================================================================
// __unwind$487532_0
// EA  : 0x82DF98C4
// RVA : 0x00DF98C4
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487532_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 64));
}


// ========================================================================
// `dynamic initializer for 'idCrosshairInfo::crosshairInfos''
// EA  : 0x83387010
// RVA : 0x01387010
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idCrosshairInfo::crosshairInfos__()
{
  const idSoundShader *v0; // [sp+8h] [-88h]
  const idSoundShader *v1; // [sp+8h] [-88h]
  const idSoundShader *v2; // [sp+8h] [-88h]
  const idSoundShader *v3; // [sp+8h] [-88h]
  const idSoundShader *v4; // [sp+8h] [-88h]
  const idSoundShader *v5; // [sp+8h] [-88h]
  const idSoundShader *v6; // [sp+8h] [-88h]
  const idSoundShader *v7; // [sp+8h] [-88h]
  const idSoundShader *v8; // [sp+8h] [-88h]
  const idSoundShader *v9; // [sp+8h] [-88h]
  const idSoundShader *v10; // [sp+8h] [-88h]
  int v11; // [sp+Ch] [-84h]
  int v12; // [sp+Ch] [-84h]
  int v13; // [sp+Ch] [-84h]
  int v14; // [sp+Ch] [-84h]
  int v15; // [sp+Ch] [-84h]
  int v16; // [sp+Ch] [-84h]
  int v17; // [sp+Ch] [-84h]
  int v18; // [sp+Ch] [-84h]
  int v19; // [sp+Ch] [-84h]
  int v20; // [sp+Ch] [-84h]
  int v21; // [sp+Ch] [-84h]
  int v22; // [sp+10h] [-80h]
  int v23; // [sp+10h] [-80h]
  int v24; // [sp+10h] [-80h]
  int v25; // [sp+10h] [-80h]
  int v26; // [sp+10h] [-80h]
  int v27; // [sp+10h] [-80h]
  int v28; // [sp+10h] [-80h]
  int v29; // [sp+10h] [-80h]
  int v30; // [sp+10h] [-80h]
  int v31; // [sp+10h] [-80h]
  int v32; // [sp+10h] [-80h]
  int v33; // [sp+14h] [-7Ch]
  int v34; // [sp+14h] [-7Ch]
  int v35; // [sp+14h] [-7Ch]
  int v36; // [sp+14h] [-7Ch]
  int v37; // [sp+14h] [-7Ch]
  int v38; // [sp+14h] [-7Ch]
  int v39; // [sp+14h] [-7Ch]
  int v40; // [sp+14h] [-7Ch]
  int v41; // [sp+14h] [-7Ch]
  int v42; // [sp+14h] [-7Ch]
  int v43; // [sp+14h] [-7Ch]
  int v44; // [sp+18h] [-78h]
  int v45; // [sp+18h] [-78h]
  int v46; // [sp+18h] [-78h]
  int v47; // [sp+18h] [-78h]
  int v48; // [sp+18h] [-78h]
  int v49; // [sp+18h] [-78h]
  int v50; // [sp+18h] [-78h]
  int v51; // [sp+18h] [-78h]
  int v52; // [sp+18h] [-78h]
  int v53; // [sp+18h] [-78h]
  int v54; // [sp+18h] [-78h]
  int v55; // [sp+1Ch] [-74h]
  int v56; // [sp+1Ch] [-74h]
  int v57; // [sp+1Ch] [-74h]
  int v58; // [sp+1Ch] [-74h]
  int v59; // [sp+1Ch] [-74h]
  int v60; // [sp+1Ch] [-74h]
  int v61; // [sp+1Ch] [-74h]
  int v62; // [sp+1Ch] [-74h]
  int v63; // [sp+1Ch] [-74h]
  int v64; // [sp+1Ch] [-74h]
  int v65; // [sp+1Ch] [-74h]
  int v66; // [sp+20h] [-70h]
  int v67; // [sp+20h] [-70h]
  int v68; // [sp+20h] [-70h]
  int v69; // [sp+20h] [-70h]
  int v70; // [sp+20h] [-70h]
  int v71; // [sp+20h] [-70h]
  int v72; // [sp+20h] [-70h]
  int v73; // [sp+20h] [-70h]
  int v74; // [sp+20h] [-70h]
  int v75; // [sp+20h] [-70h]
  int v76; // [sp+20h] [-70h]
  int v77; // [sp+24h] [-6Ch]
  int v78; // [sp+24h] [-6Ch]
  int v79; // [sp+24h] [-6Ch]
  int v80; // [sp+24h] [-6Ch]
  int v81; // [sp+24h] [-6Ch]
  int v82; // [sp+24h] [-6Ch]
  int v83; // [sp+24h] [-6Ch]
  int v84; // [sp+24h] [-6Ch]
  int v85; // [sp+24h] [-6Ch]
  int v86; // [sp+24h] [-6Ch]
  int v87; // [sp+24h] [-6Ch]
  int v88; // [sp+28h] [-68h]
  int v89; // [sp+28h] [-68h]
  int v90; // [sp+28h] [-68h]
  int v91; // [sp+28h] [-68h]
  int v92; // [sp+28h] [-68h]
  int v93; // [sp+28h] [-68h]
  int v94; // [sp+28h] [-68h]
  int v95; // [sp+28h] [-68h]
  int v96; // [sp+28h] [-68h]
  int v97; // [sp+28h] [-68h]
  int v98; // [sp+28h] [-68h]
  int v99; // [sp+2Ch] [-64h]
  int v100; // [sp+2Ch] [-64h]
  int v101; // [sp+2Ch] [-64h]
  int v102; // [sp+2Ch] [-64h]
  int v103; // [sp+2Ch] [-64h]
  int v104; // [sp+2Ch] [-64h]
  int v105; // [sp+2Ch] [-64h]
  int v106; // [sp+2Ch] [-64h]
  int v107; // [sp+2Ch] [-64h]
  int v108; // [sp+2Ch] [-64h]
  int v109; // [sp+2Ch] [-64h]
  int v110; // [sp+30h] [-60h]
  int v111; // [sp+30h] [-60h]
  int v112; // [sp+30h] [-60h]
  int v113; // [sp+30h] [-60h]
  int v114; // [sp+30h] [-60h]
  int v115; // [sp+30h] [-60h]
  int v116; // [sp+30h] [-60h]
  int v117; // [sp+30h] [-60h]
  int v118; // [sp+30h] [-60h]
  int v119; // [sp+30h] [-60h]
  int v120; // [sp+30h] [-60h]
  int v121; // [sp+34h] [-5Ch]
  int v122; // [sp+34h] [-5Ch]
  int v123; // [sp+34h] [-5Ch]
  int v124; // [sp+34h] [-5Ch]
  int v125; // [sp+34h] [-5Ch]
  int v126; // [sp+34h] [-5Ch]
  int v127; // [sp+34h] [-5Ch]
  int v128; // [sp+34h] [-5Ch]
  int v129; // [sp+34h] [-5Ch]
  int v130; // [sp+34h] [-5Ch]
  int v131; // [sp+34h] [-5Ch]
  int v132; // [sp+38h] [-58h]
  int v133; // [sp+38h] [-58h]
  int v134; // [sp+38h] [-58h]
  int v135; // [sp+38h] [-58h]
  int v136; // [sp+38h] [-58h]
  int v137; // [sp+38h] [-58h]
  int v138; // [sp+38h] [-58h]
  int v139; // [sp+38h] [-58h]
  int v140; // [sp+38h] [-58h]
  int v141; // [sp+38h] [-58h]
  int v142; // [sp+38h] [-58h]
  int v143; // [sp+3Ch] [-54h]
  int v144; // [sp+3Ch] [-54h]
  int v145; // [sp+3Ch] [-54h]
  int v146; // [sp+3Ch] [-54h]
  int v147; // [sp+3Ch] [-54h]
  int v148; // [sp+3Ch] [-54h]
  int v149; // [sp+3Ch] [-54h]
  int v150; // [sp+3Ch] [-54h]
  int v151; // [sp+3Ch] [-54h]
  int v152; // [sp+3Ch] [-54h]
  int v153; // [sp+3Ch] [-54h]
  int v154; // [sp+40h] [-50h]
  int v155; // [sp+40h] [-50h]
  int v156; // [sp+40h] [-50h]
  int v157; // [sp+40h] [-50h]
  int v158; // [sp+40h] [-50h]
  int v159; // [sp+40h] [-50h]
  int v160; // [sp+40h] [-50h]
  int v161; // [sp+40h] [-50h]
  int v162; // [sp+40h] [-50h]
  int v163; // [sp+40h] [-50h]
  int v164; // [sp+40h] [-50h]
  int v165; // [sp+44h] [-4Ch]
  int v166; // [sp+44h] [-4Ch]
  int v167; // [sp+44h] [-4Ch]
  int v168; // [sp+44h] [-4Ch]
  int v169; // [sp+44h] [-4Ch]
  int v170; // [sp+44h] [-4Ch]
  int v171; // [sp+44h] [-4Ch]
  int v172; // [sp+44h] [-4Ch]
  int v173; // [sp+44h] [-4Ch]
  int v174; // [sp+44h] [-4Ch]
  int v175; // [sp+44h] [-4Ch]
  int v176; // [sp+48h] [-48h]
  int v177; // [sp+48h] [-48h]
  int v178; // [sp+48h] [-48h]
  int v179; // [sp+48h] [-48h]
  int v180; // [sp+48h] [-48h]
  int v181; // [sp+48h] [-48h]
  int v182; // [sp+48h] [-48h]
  int v183; // [sp+48h] [-48h]
  int v184; // [sp+48h] [-48h]
  int v185; // [sp+48h] [-48h]
  int v186; // [sp+48h] [-48h]
  int v187; // [sp+4Ch] [-44h]
  int v188; // [sp+4Ch] [-44h]
  int v189; // [sp+4Ch] [-44h]
  int v190; // [sp+4Ch] [-44h]
  int v191; // [sp+4Ch] [-44h]
  int v192; // [sp+4Ch] [-44h]
  int v193; // [sp+4Ch] [-44h]
  int v194; // [sp+4Ch] [-44h]
  int v195; // [sp+4Ch] [-44h]
  int v196; // [sp+4Ch] [-44h]
  int v197; // [sp+4Ch] [-44h]
  int v198; // [sp+50h] [-40h]
  int v199; // [sp+50h] [-40h]
  int v200; // [sp+50h] [-40h]
  int v201; // [sp+50h] [-40h]
  int v202; // [sp+50h] [-40h]
  int v203; // [sp+50h] [-40h]
  int v204; // [sp+50h] [-40h]
  int v205; // [sp+50h] [-40h]
  int v206; // [sp+50h] [-40h]
  int v207; // [sp+50h] [-40h]
  int v208; // [sp+50h] [-40h]

  idCrosshairInfo::idCrosshairInfo(this: (idCrosshairInfo *)idCrosshairInfo::crosshairInfos);
  idCrosshairInfo::idCrosshairInfo(
    this: (idCrosshairInfo *)&idCrosshairInfo::crosshairInfos[1],
    color_: &idCrosshairInfo::DEFAULT_COLOR,
    textColor_: &idCrosshairInfo::DEFAULT_TEXT_COLOR,
    text_: &byte_8200D768,
    material_: CHMATERIAL_LOOT,
    colorState_: CROSSHAIR_COLOR_NORMAL,
    textColorState_: CROSSHAIR_TEXT_COLOR_NORMAL,
    customMaterial_: nullptr,
    hoverSound_: v0,
    a10: v11,
    a11: v22,
    a12: v33,
    a13: v44,
    a14: v55,
    a15: v66,
    a16: v77,
    a17: v88,
    a18: v99,
    a19: v110,
    a20: v121,
    a21: v132,
    a22: v143,
    a23: v154,
    a24: v165,
    a25: v176,
    a26: v187,
    a27: v198,
    a28: nullptr);
  idCrosshairInfo::idCrosshairInfo(
    this: (idCrosshairInfo *)&idCrosshairInfo::crosshairInfos[2],
    color_: &idCrosshairInfo::DEFAULT_COLOR,
    textColor_: &idCrosshairInfo::DEFAULT_TEXT_COLOR,
    text_: &byte_8200D768,
    material_: CHMATERIAL_PROP,
    colorState_: CROSSHAIR_COLOR_NORMAL,
    textColorState_: CROSSHAIR_TEXT_COLOR_NORMAL,
    customMaterial_: nullptr,
    hoverSound_: v1,
    a10: v12,
    a11: v23,
    a12: v34,
    a13: v45,
    a14: v56,
    a15: v67,
    a16: v78,
    a17: v89,
    a18: v100,
    a19: v111,
    a20: v122,
    a21: v133,
    a22: v144,
    a23: v155,
    a24: v166,
    a25: v177,
    a26: v188,
    a27: v199,
    a28: nullptr);
  idCrosshairInfo::idCrosshairInfo(
    this: (idCrosshairInfo *)&idCrosshairInfo::crosshairInfos[3],
    color_: &idCrosshairInfo::DEFAULT_COLOR,
    textColor_: &idCrosshairInfo::DEFAULT_TEXT_COLOR,
    text_: &byte_8200D768,
    material_: CHMATERIAL_TALK,
    colorState_: CROSSHAIR_COLOR_NORMAL,
    textColorState_: CROSSHAIR_TEXT_COLOR_NORMAL,
    customMaterial_: nullptr,
    hoverSound_: v2,
    a10: v13,
    a11: v24,
    a12: v35,
    a13: v46,
    a14: v57,
    a15: v68,
    a16: v79,
    a17: v90,
    a18: v101,
    a19: v112,
    a20: v123,
    a21: v134,
    a22: v145,
    a23: v156,
    a24: v167,
    a25: v178,
    a26: v189,
    a27: v200,
    a28: nullptr);
  idCrosshairInfo::idCrosshairInfo(
    this: (idCrosshairInfo *)&idCrosshairInfo::crosshairInfos[4],
    color_: &idCrosshairInfo::DEFAULT_COLOR,
    textColor_: &idCrosshairInfo::DEFAULT_TEXT_COLOR,
    text_: &byte_8200D768,
    material_: CHMATERIAL_TOWN,
    colorState_: CROSSHAIR_COLOR_NORMAL,
    textColorState_: CROSSHAIR_TEXT_COLOR_NORMAL,
    customMaterial_: nullptr,
    hoverSound_: v3,
    a10: v14,
    a11: v25,
    a12: v36,
    a13: v47,
    a14: v58,
    a15: v69,
    a16: v80,
    a17: v91,
    a18: v102,
    a19: v113,
    a20: v124,
    a21: v135,
    a22: v146,
    a23: v157,
    a24: v168,
    a25: v179,
    a26: v190,
    a27: v201,
    a28: nullptr);
  idCrosshairInfo::idCrosshairInfo(
    this: (idCrosshairInfo *)&idCrosshairInfo::crosshairInfos[5],
    color_: &idCrosshairInfo::DEFAULT_COLOR,
    textColor_: &idCrosshairInfo::DEFAULT_TEXT_COLOR,
    text_: &byte_8200D768,
    material_: CHMATERIAL_TAGGABLE,
    colorState_: CROSSHAIR_COLOR_NORMAL,
    textColorState_: CROSSHAIR_TEXT_COLOR_NORMAL,
    customMaterial_: nullptr,
    hoverSound_: v4,
    a10: v15,
    a11: v26,
    a12: v37,
    a13: v48,
    a14: v59,
    a15: v70,
    a16: v81,
    a17: v92,
    a18: v103,
    a19: v114,
    a20: v125,
    a21: v136,
    a22: v147,
    a23: v158,
    a24: v169,
    a25: v180,
    a26: v191,
    a27: v202,
    a28: nullptr);
  idCrosshairInfo::idCrosshairInfo(
    this: (idCrosshairInfo *)&idCrosshairInfo::crosshairInfos[6],
    color_: &idCrosshairInfo::DEFAULT_COLOR,
    textColor_: &idCrosshairInfo::DEFAULT_TEXT_COLOR,
    text_: &byte_8200D768,
    material_: CHMATERIAL_DOOR,
    colorState_: CROSSHAIR_COLOR_NORMAL,
    textColorState_: CROSSHAIR_TEXT_COLOR_NORMAL,
    customMaterial_: nullptr,
    hoverSound_: v5,
    a10: v16,
    a11: v27,
    a12: v38,
    a13: v49,
    a14: v60,
    a15: v71,
    a16: v82,
    a17: v93,
    a18: v104,
    a19: v115,
    a20: v126,
    a21: v137,
    a22: v148,
    a23: v159,
    a24: v170,
    a25: v181,
    a26: v192,
    a27: v203,
    a28: nullptr);
  idCrosshairInfo::idCrosshairInfo(
    this: (idCrosshairInfo *)&idCrosshairInfo::crosshairInfos[7],
    color_: &idCrosshairInfo::DEFAULT_COLOR,
    textColor_: &idCrosshairInfo::DEFAULT_TEXT_COLOR,
    text_: &byte_8200D768,
    material_: CHMATERIAL_MOVER,
    colorState_: CROSSHAIR_COLOR_NORMAL,
    textColorState_: CROSSHAIR_TEXT_COLOR_NORMAL,
    customMaterial_: nullptr,
    hoverSound_: v6,
    a10: v17,
    a11: v28,
    a12: v39,
    a13: v50,
    a14: v61,
    a15: v72,
    a16: v83,
    a17: v94,
    a18: v105,
    a19: v116,
    a20: v127,
    a21: v138,
    a22: v149,
    a23: v160,
    a24: v171,
    a25: v182,
    a26: v193,
    a27: v204,
    a28: nullptr);
  idCrosshairInfo::idCrosshairInfo(
    this: (idCrosshairInfo *)&idCrosshairInfo::crosshairInfos[8],
    color_: &idCrosshairInfo::DEFAULT_COLOR,
    textColor_: &idCrosshairInfo::DEFAULT_TEXT_COLOR,
    text_: &byte_8200D768,
    material_: CHMATERIAL_RC_PICKUP,
    colorState_: CROSSHAIR_COLOR_NORMAL,
    textColorState_: CROSSHAIR_TEXT_COLOR_NORMAL,
    customMaterial_: nullptr,
    hoverSound_: v7,
    a10: v18,
    a11: v29,
    a12: v40,
    a13: v51,
    a14: v62,
    a15: v73,
    a16: v84,
    a17: v95,
    a18: v106,
    a19: v117,
    a20: v128,
    a21: v139,
    a22: v150,
    a23: v161,
    a24: v172,
    a25: v183,
    a26: v194,
    a27: v205,
    a28: nullptr);
  idCrosshairInfo::idCrosshairInfo(
    this: (idCrosshairInfo *)&idCrosshairInfo::crosshairInfos[9],
    color_: &idCrosshairInfo::DEFAULT_COLOR,
    textColor_: &idCrosshairInfo::DEFAULT_TEXT_COLOR,
    text_: &byte_8200D768,
    material_: CHMATERIAL_VEHICLE_DRIVE,
    colorState_: CROSSHAIR_COLOR_NORMAL,
    textColorState_: CROSSHAIR_TEXT_COLOR_NORMAL,
    customMaterial_: nullptr,
    hoverSound_: v8,
    a10: v19,
    a11: v30,
    a12: v41,
    a13: v52,
    a14: v63,
    a15: v74,
    a16: v85,
    a17: v96,
    a18: v107,
    a19: v118,
    a20: v129,
    a21: v140,
    a22: v151,
    a23: v162,
    a24: v173,
    a25: v184,
    a26: v195,
    a27: v206,
    a28: nullptr);
  idCrosshairInfo::idCrosshairInfo(
    this: (idCrosshairInfo *)&idCrosshairInfo::crosshairInfos[10],
    color_: &idCrosshairInfo::DEFAULT_COLOR,
    textColor_: &idCrosshairInfo::DEFAULT_TEXT_COLOR,
    text_: &byte_8200D768,
    material_: CHMATERIAL_VEHICLE_GUNNER,
    colorState_: CROSSHAIR_COLOR_NORMAL,
    textColorState_: CROSSHAIR_TEXT_COLOR_NORMAL,
    customMaterial_: nullptr,
    hoverSound_: v9,
    a10: v20,
    a11: v31,
    a12: v42,
    a13: v53,
    a14: v64,
    a15: v75,
    a16: v86,
    a17: v97,
    a18: v108,
    a19: v119,
    a20: v130,
    a21: v141,
    a22: v152,
    a23: v163,
    a24: v174,
    a25: v185,
    a26: v196,
    a27: v207,
    a28: nullptr);
  idCrosshairInfo::idCrosshairInfo(
    this: (idCrosshairInfo *)&idCrosshairInfo::crosshairInfos[11],
    color_: &idCrosshairInfo::DEFAULT_COLOR,
    textColor_: &idCrosshairInfo::DEFAULT_TEXT_COLOR,
    text_: &byte_8200D768,
    material_: CHMATERIAL_DISASSEMBLE,
    colorState_: CROSSHAIR_COLOR_NORMAL,
    textColorState_: CROSSHAIR_TEXT_COLOR_NORMAL,
    customMaterial_: nullptr,
    hoverSound_: v10,
    a10: v21,
    a11: v32,
    a12: v43,
    a13: v54,
    a14: v65,
    a15: v76,
    a16: v87,
    a17: v98,
    a18: v109,
    a19: v120,
    a20: v131,
    a21: v142,
    a22: v153,
    a23: v164,
    a24: v175,
    a25: v186,
    a26: v197,
    a27: v208,
    a28: nullptr);
  `eh vector constructor iterator'(
    ptr: (char *)&idCrosshairInfo::crosshairInfos[12],
    size: 0x74u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idCrosshairInfo::idCrosshairInfo,
    pDtor: (void (__fastcall *)(void *))idCrosshairInfo::~idCrosshairInfo);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idCrosshairInfo::crosshairInfos__);
}


// ========================================================================
// __unwind$487638
// EA  : 0x83387238
// RVA : 0x01387238
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487638()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)idCrosshairInfo::crosshairInfos);
}


// ========================================================================
// __unwind$487639
// EA  : 0x83387260
// RVA : 0x01387260
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487639()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)&idCrosshairInfo::crosshairInfos[1]);
}


// ========================================================================
// __unwind$487640
// EA  : 0x8338728C
// RVA : 0x0138728C
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487640()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)&idCrosshairInfo::crosshairInfos[2]);
}


// ========================================================================
// __unwind$487641
// EA  : 0x833872B8
// RVA : 0x013872B8
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487641()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)&idCrosshairInfo::crosshairInfos[3]);
}


// ========================================================================
// __unwind$487642
// EA  : 0x833872E4
// RVA : 0x013872E4
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487642()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)&idCrosshairInfo::crosshairInfos[4]);
}


// ========================================================================
// __unwind$487643
// EA  : 0x83387310
// RVA : 0x01387310
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487643()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)&idCrosshairInfo::crosshairInfos[5]);
}


// ========================================================================
// __unwind$487644
// EA  : 0x8338733C
// RVA : 0x0138733C
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487644()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)&idCrosshairInfo::crosshairInfos[6]);
}


// ========================================================================
// __unwind$487645
// EA  : 0x83387368
// RVA : 0x01387368
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487645()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)&idCrosshairInfo::crosshairInfos[7]);
}


// ========================================================================
// __unwind$487646_0
// EA  : 0x83387394
// RVA : 0x01387394
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487646_0()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)&idCrosshairInfo::crosshairInfos[8]);
}


// ========================================================================
// __unwind$487647
// EA  : 0x833873C0
// RVA : 0x013873C0
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487647()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)&idCrosshairInfo::crosshairInfos[9]);
}


// ========================================================================
// __unwind$487648
// EA  : 0x833873EC
// RVA : 0x013873EC
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487648()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)&idCrosshairInfo::crosshairInfos[10]);
}


// ========================================================================
// __unwind$487649
// EA  : 0x83387418
// RVA : 0x01387418
// PDB : w:\tech5\tungsten\game\player\crosshairinfo.cpp
// ========================================================================

void _unwind_487649()
{
  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)&idCrosshairInfo::crosshairInfos[11]);
}

