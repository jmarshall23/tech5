
// ========================================================================
// ?SendReport@idHansoftReport@@QAAXPADHPBD@Z
// EA  : 0x82894AB0
// RVA : 0x00894AB0
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void __fastcall idHansoftReport::SendReport(
        idHansoftReport *this,
        char *report,
        unsigned int byteSize,
        const char *targetPlatform)
{
  idMQChannel *Channel; // r27
  __int64 v8; // r10
  __int64 v9; // r8
  va *v10; // r3
  int v11; // [sp+8h] [-11F8h]
  int v12; // [sp+Ch] [-11F4h]
  int v13; // [sp+10h] [-11F0h]
  int v14; // [sp+14h] [-11ECh]
  int v15; // [sp+18h] [-11E8h]
  int v16; // [sp+1Ch] [-11E4h]
  idStr v17; // [sp+50h] [-11B0h] BYREF
  idMQConnection v18; // [sp+70h] [-1190h] BYREF
  idStr v19; // [sp+B0h] [-1150h] BYREF
  idStr v20; // [sp+D0h] [-1130h] BYREF
  idStr v21; // [sp+F0h] [-1110h] BYREF
  idStr v22; // [sp+110h] [-10F0h] BYREF
  amqpEndpoint_t v23; // [sp+130h] [-10D0h] BYREF
  va v24; // [sp+1D0h] [-1030h] BYREF

  amqpEndpoint_t::amqpEndpoint_t(this: &v23);
  idStr::operator=(this: &v23.host, text: mq_host.valueString.data);
  v23.port = mq_port.valueInteger;
  idStr::operator=(this: &v23.username, text: mq_user.valueString.data);
  idStr::operator=(this: &v23.password, text: mq_pw.valueString.data);
  idStr::operator=(this: &v23.vhost, text: mq_vhost.valueString.data);
  idMQConnection::idMQConnection(this: &v18);
  idMQConnection::Init(this: &v18, _endpoint: &v23);
  if ( idMQConnection::Connect(this: &v18) )
  {
    idStr::idStr(this: &v17, text: "idtech5");
    Channel = idMQConnection::GetChannel(this: &v18);
    idStr::idStr(this: &v20, text: "topic");
    idStr::idStr(this: &v21, text: v17.data);
    idMQChannel::ExchangeDeclare(this: Channel, exchange: &v21, type: &v20, durable: true);
    idStr::FreeData(this: &v21);
    idStr::FreeData(this: &v20);
    HIDWORD(v8) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
    LODWORD(v9) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
    v10 = va::va(
            this: &v24,
            fmt: "%s.%s",
            a3: __SPAIR64__("idtech5.crash_reports.Tungsten", (unsigned int)targetPlatform),
            a4: v9,
            a5: v8,
            a6: v11,
            a7: v12,
            a8: v13,
            a9: v14,
            a10: v15,
            a11: v16);
    idStr::idStr(this: &v22, text: v10);
    idStr::idStr(this: &v19, text: v17.data);
    idMQChannel::BasicPublish(
      this: Channel,
      exchange: &v19,
      routingKey: &v22,
      mandatory: false,
      immediate: false,
      data: report,
      size: byteSize);
    idStr::FreeData(this: &v19);
    idStr::FreeData(this: &v22);
    idStr::FreeData(this: &v17);
  }
  idMQConnection::Close(this: &v18);
  idMQConnection::~idMQConnection(this: &v18);
  amqpEndpoint_t::~amqpEndpoint_t(this: &v23);
}


// ========================================================================
// __unwind$263400
// EA  : 0x82894C48
// RVA : 0x00894C48
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_263400()
{
  int v0; // r12

  amqpEndpoint_t::~amqpEndpoint_t(this: (amqpEndpoint_t *)(v0 - 4608 + 304));
}


// ========================================================================
// __unwind$263401
// EA  : 0x82894C70
// RVA : 0x00894C70
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_263401()
{
  int v0; // r12

  idMQConnection::~idMQConnection(this: (idMQConnection *)(v0 - 4608 + 112));
}


// ========================================================================
// __unwind$263402
// EA  : 0x82894C98
// RVA : 0x00894C98
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_263402()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4608 + 80));
}


// ========================================================================
// __unwind$263403
// EA  : 0x82894CC0
// RVA : 0x00894CC0
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_263403()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4608 + 208));
}


// ========================================================================
// __unwind$263404
// EA  : 0x82894CE8
// RVA : 0x00894CE8
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_263404()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4608 + 240));
}


// ========================================================================
// __unwind$263405
// EA  : 0x82894D10
// RVA : 0x00894D10
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_263405()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4608 + 272));
}


// ========================================================================
// __unwind$263406
// EA  : 0x82894D38
// RVA : 0x00894D38
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_263406()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4608 + 176));
}


// ========================================================================
// ?CombineLines@idHansoftReport@@SA?AVidStr@@AAV2@@Z
// EA  : 0x828950B0
// RVA : 0x008950B0
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

idStr *__fastcall idHansoftReport::CombineLines(idStr *result, idStr *src)
{
  idStr *list; // r24
  idStr *v5; // r25
  int i; // r26
  char v7; // r10
  int v8; // r11
  char v10; // r11
  bool v11; // zf
  char *data; // r9
  int v13; // r11
  char *v14; // r9
  int v15; // r11
  int size; // r29
  idStr *v17; // r28
  idList<idStr,5> v19; // [sp+60h] [-80h] BYREF
  idStr v20[3]; // [sp+70h] [-70h] BYREF

  idStr::idStr(this: result, text: &byte_8200D768);
  *(_WORD *)&v19.memTag = 1280;
  memset(&v19, 0, 14);
  idStrListBreakupString(list: &v19, string: src->data, separator: 10);
  list = v19.list;
  if ( v19.num > 0 )
  {
    v5 = v19.list;
    for ( i = v19.num; i != 0; --i )
    {
      idStr::idStr(this: v20, text: v5);
      idStr::StripLeadingWhiteSpace(this: v20);
      idStr::StripTrailingWhitespace(this: v20);
      if ( v20[0].len != 0 )
      {
        idStr::Append(this: result, text: v20);
        v7 = v20[0].data[v20[0].len - 1];
        v8 = v7;
        if ( v7 >= 97 && v7 <= 122 || v7 >= 65 && v7 <= 90 )
          goto LABEL_15;
        if ( v8 > 57 || (v11 = v8 >= 48, v10 = 1, !v11) )
          v10 = 0;
        if ( v10 != 0 )
        {
LABEL_15:
          idStr::EnsureAlloced(this: result, amount: result->len + 2, keepold: true, geometricGrowth: true);
          result->data[result->len] = 46;
          data = result->data;
          v13 = result->len + 1;
          result->len = v13;
          data[v13] = 0;
        }
        idStr::EnsureAlloced(this: result, amount: result->len + 2, keepold: true, geometricGrowth: true);
        result->data[result->len] = 32;
        v14 = result->data;
        v15 = result->len + 1;
        result->len = v15;
        v14[v15] = 0;
      }
      idStr::FreeData(this: v20);
      ++v5;
    }
  }
  if ( (v19.listStatic == 0 || v19.listStatic == 2) && list != nullptr )
  {
    size = v19.size;
    if ( v19.size > 0 )
    {
      v17 = list;
      do
      {
        idStr::FreeData(this: v17);
        --size;
        ++v17;
      }
      while ( size != 0 );
    }
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
  return result;
}


// ========================================================================
// __unwind$264213
// EA  : 0x828952CC
// RVA : 0x008952CC
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_264213()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 224;
  if ( (*(_DWORD *)(v0 - 224 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 244));
  }
}


// ========================================================================
// __unwind$264216
// EA  : 0x82895310
// RVA : 0x00895310
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_264216()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$264217
// EA  : 0x82895338
// RVA : 0x00895338
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_264217()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?Write360Report@idHansoftReport@@QAAXPAX@Z
// EA  : 0x82896840
// RVA : 0x00896840
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void __fastcall idHansoftReport::Write360Report(idHansoftReport *this, unsigned int **pExPtrs_)
{
  const char *v4; // r4
  int v5; // r3
  const char *v6; // r3
  idreports::Xbox360KitInfo *v7; // r3
  idreports::Xbox360KitInfo *v8; // r28
  size_t v9; // r5
  char *v10; // r11
  DWORD v11; // r11
  unsigned int v12; // r11
  int v13; // r10
  HRESULT SystemInfo; // r4
  idreports::Xbox360VersionInfo *v15; // r3
  unsigned int v16; // r8
  unsigned int Minor; // r4
  int v18; // r10
  unsigned int Build; // r8
  int v20; // r7
  unsigned int Qfe; // r5
  idreports::Xbox360VersionInfo *v22; // r3
  unsigned int v23; // r9
  unsigned int v24; // r5
  int v25; // r11
  unsigned int v26; // r9
  int v27; // r8
  unsigned int v28; // r6
  idreports::Xbox360VersionInfo *v29; // r3
  unsigned int Major; // r4
  int v31; // r9
  unsigned int v32; // r7
  int v33; // r11
  unsigned int v34; // r4
  unsigned int v35; // r9
  unsigned int dmSystemInfoFlags; // r8
  HRESULT v37; // r4
  idreports::XenonMemoryInfo *v38; // r3
  unsigned int TotalPages; // r11
  int v40; // r8
  unsigned int AvailablePages; // r7
  unsigned int StackPages; // r5
  int v43; // r11
  int v44; // r10
  unsigned int VirtualPageTablePages; // r9
  unsigned int PoolPages; // r6
  int v47; // r5
  int v48; // r4
  unsigned int VirtualMappedPages; // r11
  unsigned int ImagePages; // r10
  unsigned int FileCachePages; // r9
  unsigned int ContiguousPages; // r8
  unsigned int DebuggerPages; // r7
  HRESULT v54; // r4
  idreports::XenonMemoryInfo *v55; // r3
  int v56; // r9
  int v57; // r6
  int v58; // r4
  int v59; // r11
  unsigned int v60; // r7
  unsigned int v61; // r5
  int v62; // r7
  int v63; // r6
  unsigned int v64; // r10
  int v65; // r5
  unsigned int v66; // r4
  unsigned int v67; // r11
  unsigned int v68; // r10
  unsigned int v69; // r9
  unsigned int v70; // r8
  unsigned int v71; // r7
  unsigned int v72; // r11
  unsigned int v73; // r11
  const char *v74; // r4
  unsigned int v75; // r11
  unsigned int v76; // r11
  unsigned int v77; // r11
  idreports::ExceptionInfo *v78; // r3
  __int64 v79; // r10
  __int64 v80; // r6
  idreports::ExceptionInfo *v81; // r29
  __int64 v82; // r8
  va *v83; // r3
  __int64 v84; // r8
  __int64 v85; // r10
  __int64 v86; // r6
  int v87; // r5
  va *v88; // r3
  idreports::XenonRegisterInfo *v89; // r3
  __int64 v90; // r10
  idreports::XenonRegisterInfo *v91; // r26
  __int64 v92; // r6
  __int64 v93; // r8
  va *v94; // r3
  __int64 v95; // r8
  __int64 v96; // r6
  __int64 v97; // r10
  va *v98; // r3
  __int64 v99; // r8
  __int64 v100; // r6
  __int64 v101; // r10
  va *v102; // r3
  __int128 v103; // r6
  __int64 v104; // r10
  __int64 v105; // r8
  va *v106; // r3
  __int64 v107; // r6
  __int64 v108; // r10
  __int64 v109; // r8
  va *v110; // r3
  __int64 v111; // r10
  __int64 v112; // r6
  __int64 v113; // r8
  va *v114; // r3
  __int64 v115; // r10
  __int64 v116; // r6
  __int64 v117; // r8
  va *v118; // r3
  __int64 v119; // r8
  __int64 v120; // r6
  __int64 v121; // r10
  va *v122; // r3
  __int64 v123; // r8
  __int128 v124; // r6
  __int64 v125; // r10
  va *v126; // r27
  std::string *v127; // r3
  va *v128; // r11
  int v129; // r10
  __int64 v130; // r10
  __int128 v131; // r6
  __int64 v132; // r8
  va *v133; // r27
  std::string *v134; // r3
  va *v135; // r11
  int v136; // r10
  __int64 v137; // r10
  __int128 v138; // r6
  __int64 v139; // r8
  va *v140; // r27
  std::string *v141; // r3
  va *v142; // r11
  int v143; // r10
  __int64 v144; // r10
  __int128 v145; // r6
  __int64 v146; // r8
  va *v147; // r27
  std::string *v148; // r3
  va *v149; // r11
  int v150; // r10
  __int64 v151; // r10
  __int128 v152; // r6
  __int64 v153; // r8
  va *v154; // r27
  std::string *v155; // r3
  va *v156; // r11
  int v157; // r10
  __int64 v158; // r10
  __int128 v159; // r6
  __int64 v160; // r8
  va *v161; // r27
  std::string *v162; // r3
  va *v163; // r11
  int v164; // r10
  __int64 v165; // r10
  __int128 v166; // r6
  __int64 v167; // r8
  va *v168; // r27
  std::string *v169; // r3
  va *v170; // r11
  int v171; // r10
  __int64 v172; // r10
  __int128 v173; // r6
  __int64 v174; // r8
  va *v175; // r27
  std::string *v176; // r3
  va *v177; // r11
  int v178; // r10
  __int64 v179; // r10
  __int128 v180; // r6
  __int64 v181; // r8
  va *v182; // r27
  std::string *v183; // r3
  va *v184; // r11
  int v185; // r10
  __int64 v186; // r10
  __int128 v187; // r6
  __int64 v188; // r8
  va *v189; // r27
  std::string *v190; // r3
  va *v191; // r11
  int v192; // r10
  __int64 v193; // r10
  __int128 v194; // r6
  __int64 v195; // r8
  va *v196; // r27
  std::string *v197; // r3
  va *v198; // r11
  int v199; // r10
  __int64 v200; // r10
  __int128 v201; // r6
  __int64 v202; // r8
  va *v203; // r27
  std::string *v204; // r3
  va *v205; // r11
  int v206; // r10
  __int64 v207; // r10
  __int128 v208; // r6
  __int64 v209; // r8
  va *v210; // r27
  std::string *v211; // r3
  va *v212; // r11
  int v213; // r10
  __int64 v214; // r10
  __int128 v215; // r6
  __int64 v216; // r8
  va *v217; // r27
  std::string *v218; // r3
  va *v219; // r11
  int v220; // r10
  __int64 v221; // r10
  __int128 v222; // r6
  __int64 v223; // r8
  va *v224; // r27
  std::string *v225; // r3
  va *v226; // r11
  int v227; // r10
  __int64 v228; // r10
  __int128 v229; // r6
  __int64 v230; // r8
  va *v231; // r27
  std::string *v232; // r3
  va *v233; // r11
  int v234; // r10
  __int64 v235; // r10
  __int128 v236; // r6
  __int64 v237; // r8
  va *v238; // r27
  std::string *v239; // r3
  va *v240; // r11
  int v241; // r10
  __int64 v242; // r10
  __int128 v243; // r6
  __int64 v244; // r8
  va *v245; // r27
  std::string *v246; // r3
  va *v247; // r11
  int v248; // r10
  __int64 v249; // r10
  __int128 v250; // r6
  __int64 v251; // r8
  va *v252; // r27
  std::string *v253; // r3
  va *v254; // r11
  int v255; // r10
  __int64 v256; // r10
  __int128 v257; // r6
  __int64 v258; // r8
  va *v259; // r27
  std::string *v260; // r3
  va *v261; // r11
  int v262; // r10
  __int64 v263; // r10
  __int128 v264; // r6
  __int64 v265; // r8
  va *v266; // r27
  std::string *v267; // r3
  va *v268; // r11
  int v269; // r10
  __int64 v270; // r10
  __int128 v271; // r6
  __int64 v272; // r8
  va *v273; // r27
  std::string *v274; // r3
  va *v275; // r11
  int v276; // r10
  __int64 v277; // r10
  __int128 v278; // r6
  __int64 v279; // r8
  va *v280; // r27
  std::string *v281; // r3
  va *v282; // r11
  int v283; // r10
  __int64 v284; // r10
  __int128 v285; // r6
  __int64 v286; // r8
  va *v287; // r27
  std::string *v288; // r3
  va *v289; // r11
  int v290; // r10
  __int64 v291; // r10
  __int128 v292; // r6
  __int64 v293; // r8
  va *v294; // r27
  std::string *v295; // r3
  va *v296; // r11
  int v297; // r10
  __int64 v298; // r10
  __int128 v299; // r6
  __int64 v300; // r8
  va *v301; // r27
  std::string *v302; // r3
  va *v303; // r11
  int v304; // r10
  __int64 v305; // r10
  __int128 v306; // r6
  __int64 v307; // r8
  va *v308; // r27
  std::string *v309; // r3
  va *v310; // r11
  int v311; // r10
  __int64 v312; // r10
  __int128 v313; // r6
  __int64 v314; // r8
  va *v315; // r27
  std::string *v316; // r3
  va *v317; // r11
  int v318; // r10
  __int64 v319; // r10
  __int128 v320; // r6
  __int64 v321; // r8
  va *v322; // r27
  std::string *v323; // r3
  va *v324; // r11
  int v325; // r10
  __int64 v326; // r10
  __int128 v327; // r6
  __int64 v328; // r8
  va *v329; // r27
  std::string *v330; // r3
  va *v331; // r11
  int v332; // r10
  __int64 v333; // r10
  __int128 v334; // r6
  __int64 v335; // r8
  va *v336; // r27
  std::string *v337; // r3
  va *v338; // r11
  int v339; // r10
  __int64 v340; // r10
  __int128 v341; // r6
  __int64 v342; // r8
  va *v343; // r29
  std::string *v344; // r3
  va *v345; // r11
  int v346; // r10
  __int64 v347; // r10
  __int64 v348; // r6
  __int64 v349; // r8
  va *v350; // r27
  std::string *v351; // r3
  va *v352; // r11
  int v353; // r10
  __int64 v354; // r10
  __int64 v355; // r6
  __int64 v356; // r8
  va *v357; // r27
  std::string *v358; // r3
  va *v359; // r11
  int v360; // r10
  __int64 v361; // r10
  __int64 v362; // r6
  __int64 v363; // r8
  va *v364; // r27
  std::string *v365; // r3
  va *v366; // r11
  int v367; // r10
  __int64 v368; // r10
  __int64 v369; // r6
  __int64 v370; // r8
  va *v371; // r27
  std::string *v372; // r3
  va *v373; // r11
  int v374; // r10
  __int64 v375; // r10
  __int64 v376; // r6
  __int64 v377; // r8
  va *v378; // r27
  std::string *v379; // r3
  va *v380; // r11
  int v381; // r10
  __int64 v382; // r10
  __int64 v383; // r6
  __int64 v384; // r8
  va *v385; // r27
  std::string *v386; // r3
  va *v387; // r11
  int v388; // r10
  __int64 v389; // r10
  __int64 v390; // r6
  __int64 v391; // r8
  va *v392; // r27
  std::string *v393; // r3
  va *v394; // r11
  int v395; // r10
  __int64 v396; // r10
  __int64 v397; // r6
  __int64 v398; // r8
  va *v399; // r27
  std::string *v400; // r3
  va *v401; // r11
  int v402; // r10
  __int64 v403; // r10
  __int64 v404; // r6
  __int64 v405; // r8
  va *v406; // r27
  std::string *v407; // r3
  va *v408; // r11
  int v409; // r10
  __int64 v410; // r10
  __int64 v411; // r6
  __int64 v412; // r8
  va *v413; // r27
  std::string *v414; // r3
  va *v415; // r11
  int v416; // r10
  __int64 v417; // r10
  __int64 v418; // r6
  __int64 v419; // r8
  va *v420; // r27
  std::string *v421; // r3
  va *v422; // r11
  int v423; // r10
  __int64 v424; // r10
  __int64 v425; // r6
  __int64 v426; // r8
  va *v427; // r27
  std::string *v428; // r3
  va *v429; // r11
  int v430; // r10
  __int64 v431; // r10
  __int64 v432; // r6
  __int64 v433; // r8
  va *v434; // r27
  std::string *v435; // r3
  va *v436; // r11
  int v437; // r10
  __int64 v438; // r10
  __int64 v439; // r6
  __int64 v440; // r8
  va *v441; // r27
  std::string *v442; // r3
  va *v443; // r11
  int v444; // r10
  __int64 v445; // r10
  __int64 v446; // r6
  __int64 v447; // r8
  va *v448; // r27
  std::string *v449; // r3
  va *v450; // r11
  int v451; // r10
  __int64 v452; // r10
  __int64 v453; // r6
  __int64 v454; // r8
  va *v455; // r27
  std::string *v456; // r3
  va *v457; // r11
  int v458; // r10
  __int64 v459; // r10
  __int64 v460; // r6
  __int64 v461; // r8
  va *v462; // r27
  std::string *v463; // r3
  va *v464; // r11
  int v465; // r10
  __int64 v466; // r10
  __int64 v467; // r6
  __int64 v468; // r8
  va *v469; // r27
  std::string *v470; // r3
  va *v471; // r11
  int v472; // r10
  __int64 v473; // r10
  __int64 v474; // r6
  __int64 v475; // r8
  va *v476; // r27
  std::string *v477; // r3
  va *v478; // r11
  int v479; // r10
  __int64 v480; // r10
  __int64 v481; // r6
  __int64 v482; // r8
  va *v483; // r27
  std::string *v484; // r3
  va *v485; // r11
  int v486; // r10
  __int64 v487; // r10
  __int64 v488; // r6
  __int64 v489; // r8
  va *v490; // r27
  std::string *v491; // r3
  va *v492; // r11
  int v493; // r10
  __int64 v494; // r10
  __int64 v495; // r6
  __int64 v496; // r8
  va *v497; // r27
  std::string *v498; // r3
  va *v499; // r11
  int v500; // r10
  __int64 v501; // r10
  __int64 v502; // r6
  __int64 v503; // r8
  va *v504; // r27
  std::string *v505; // r3
  va *v506; // r11
  int v507; // r10
  __int64 v508; // r10
  __int64 v509; // r6
  __int64 v510; // r8
  va *v511; // r27
  std::string *v512; // r3
  va *v513; // r11
  int v514; // r10
  __int64 v515; // r10
  __int64 v516; // r6
  __int64 v517; // r8
  va *v518; // r27
  std::string *v519; // r3
  va *v520; // r11
  int v521; // r10
  __int64 v522; // r10
  __int64 v523; // r6
  __int64 v524; // r8
  va *v525; // r27
  std::string *v526; // r3
  va *v527; // r11
  int v528; // r10
  __int64 v529; // r10
  __int64 v530; // r6
  __int64 v531; // r8
  va *v532; // r27
  std::string *v533; // r3
  va *v534; // r11
  int v535; // r10
  __int64 v536; // r10
  __int64 v537; // r6
  __int64 v538; // r8
  va *v539; // r27
  std::string *v540; // r3
  va *v541; // r11
  int v542; // r10
  __int64 v543; // r10
  __int64 v544; // r6
  __int64 v545; // r8
  va *v546; // r27
  std::string *v547; // r3
  va *v548; // r11
  int v549; // r10
  __int64 v550; // r10
  __int64 v551; // r6
  __int64 v552; // r8
  va *v553; // r27
  std::string *v554; // r3
  va *v555; // r11
  int v556; // r10
  __int64 v557; // r10
  __int64 v558; // r6
  __int64 v559; // r8
  va *v560; // r27
  std::string *v561; // r3
  va *v562; // r11
  int v563; // r10
  __int64 v564; // r10
  __int64 v565; // r6
  __int64 v566; // r8
  va *v567; // r30
  std::string *v568; // r3
  va *v569; // r11
  int v570; // r10
  __int64 v571; // r10
  __int64 v572; // r8
  __int64 v573; // r6
  int v574; // r29
  PVOID *v575; // r28
  va *v576; // r30
  std::string *v577; // r3
  va *v578; // r11
  int v579; // r10
  unsigned int v580; // r3
  void *v581; // r30
  int v582; // r3
  unsigned int v583; // r3
  int v584; // [sp+8h] [-2368h]
  int v585; // [sp+8h] [-2368h]
  int v586; // [sp+8h] [-2368h]
  int v587; // [sp+8h] [-2368h]
  int v588; // [sp+8h] [-2368h]
  int v589; // [sp+8h] [-2368h]
  int v590; // [sp+8h] [-2368h]
  int v591; // [sp+8h] [-2368h]
  int v592; // [sp+8h] [-2368h]
  int v593; // [sp+8h] [-2368h]
  int v594; // [sp+8h] [-2368h]
  int v595; // [sp+8h] [-2368h]
  int v596; // [sp+8h] [-2368h]
  int v597; // [sp+8h] [-2368h]
  int v598; // [sp+8h] [-2368h]
  int v599; // [sp+8h] [-2368h]
  int v600; // [sp+8h] [-2368h]
  int v601; // [sp+8h] [-2368h]
  int v602; // [sp+8h] [-2368h]
  int v603; // [sp+8h] [-2368h]
  int v604; // [sp+8h] [-2368h]
  int v605; // [sp+8h] [-2368h]
  int v606; // [sp+8h] [-2368h]
  int v607; // [sp+8h] [-2368h]
  int v608; // [sp+8h] [-2368h]
  int v609; // [sp+8h] [-2368h]
  int v610; // [sp+8h] [-2368h]
  int v611; // [sp+8h] [-2368h]
  int v612; // [sp+8h] [-2368h]
  int v613; // [sp+8h] [-2368h]
  int v614; // [sp+8h] [-2368h]
  int v615; // [sp+8h] [-2368h]
  int v616; // [sp+8h] [-2368h]
  int v617; // [sp+8h] [-2368h]
  int v618; // [sp+8h] [-2368h]
  int v619; // [sp+8h] [-2368h]
  int v620; // [sp+8h] [-2368h]
  int v621; // [sp+8h] [-2368h]
  int v622; // [sp+8h] [-2368h]
  int v623; // [sp+8h] [-2368h]
  int v624; // [sp+8h] [-2368h]
  int v625; // [sp+8h] [-2368h]
  int v626; // [sp+8h] [-2368h]
  int v627; // [sp+8h] [-2368h]
  int v628; // [sp+8h] [-2368h]
  int v629; // [sp+8h] [-2368h]
  int v630; // [sp+8h] [-2368h]
  int v631; // [sp+8h] [-2368h]
  int v632; // [sp+8h] [-2368h]
  int v633; // [sp+8h] [-2368h]
  int v634; // [sp+8h] [-2368h]
  int v635; // [sp+8h] [-2368h]
  int v636; // [sp+8h] [-2368h]
  int v637; // [sp+8h] [-2368h]
  int v638; // [sp+8h] [-2368h]
  int v639; // [sp+8h] [-2368h]
  int v640; // [sp+8h] [-2368h]
  int v641; // [sp+8h] [-2368h]
  int v642; // [sp+8h] [-2368h]
  int v643; // [sp+8h] [-2368h]
  int v644; // [sp+8h] [-2368h]
  int v645; // [sp+8h] [-2368h]
  int v646; // [sp+8h] [-2368h]
  int v647; // [sp+8h] [-2368h]
  int v648; // [sp+8h] [-2368h]
  int v649; // [sp+8h] [-2368h]
  int v650; // [sp+8h] [-2368h]
  int v651; // [sp+8h] [-2368h]
  int v652; // [sp+8h] [-2368h]
  int v653; // [sp+8h] [-2368h]
  int v654; // [sp+8h] [-2368h]
  int v655; // [sp+8h] [-2368h]
  int v656; // [sp+8h] [-2368h]
  int v657; // [sp+8h] [-2368h]
  int v658; // [sp+Ch] [-2364h]
  int v659; // [sp+Ch] [-2364h]
  int v660; // [sp+Ch] [-2364h]
  int v661; // [sp+Ch] [-2364h]
  int v662; // [sp+Ch] [-2364h]
  int v663; // [sp+Ch] [-2364h]
  int v664; // [sp+Ch] [-2364h]
  int v665; // [sp+Ch] [-2364h]
  int v666; // [sp+Ch] [-2364h]
  int v667; // [sp+Ch] [-2364h]
  int v668; // [sp+Ch] [-2364h]
  int v669; // [sp+Ch] [-2364h]
  int v670; // [sp+Ch] [-2364h]
  int v671; // [sp+Ch] [-2364h]
  int v672; // [sp+Ch] [-2364h]
  int v673; // [sp+Ch] [-2364h]
  int v674; // [sp+Ch] [-2364h]
  int v675; // [sp+Ch] [-2364h]
  int v676; // [sp+Ch] [-2364h]
  int v677; // [sp+Ch] [-2364h]
  int v678; // [sp+Ch] [-2364h]
  int v679; // [sp+Ch] [-2364h]
  int v680; // [sp+Ch] [-2364h]
  int v681; // [sp+Ch] [-2364h]
  int v682; // [sp+Ch] [-2364h]
  int v683; // [sp+Ch] [-2364h]
  int v684; // [sp+Ch] [-2364h]
  int v685; // [sp+Ch] [-2364h]
  int v686; // [sp+Ch] [-2364h]
  int v687; // [sp+Ch] [-2364h]
  int v688; // [sp+Ch] [-2364h]
  int v689; // [sp+Ch] [-2364h]
  int v690; // [sp+Ch] [-2364h]
  int v691; // [sp+Ch] [-2364h]
  int v692; // [sp+Ch] [-2364h]
  int v693; // [sp+Ch] [-2364h]
  int v694; // [sp+Ch] [-2364h]
  int v695; // [sp+Ch] [-2364h]
  int v696; // [sp+Ch] [-2364h]
  int v697; // [sp+Ch] [-2364h]
  int v698; // [sp+Ch] [-2364h]
  int v699; // [sp+Ch] [-2364h]
  int v700; // [sp+Ch] [-2364h]
  int v701; // [sp+Ch] [-2364h]
  int v702; // [sp+Ch] [-2364h]
  int v703; // [sp+Ch] [-2364h]
  int v704; // [sp+Ch] [-2364h]
  int v705; // [sp+Ch] [-2364h]
  int v706; // [sp+Ch] [-2364h]
  int v707; // [sp+Ch] [-2364h]
  int v708; // [sp+Ch] [-2364h]
  int v709; // [sp+Ch] [-2364h]
  int v710; // [sp+Ch] [-2364h]
  int v711; // [sp+Ch] [-2364h]
  int v712; // [sp+Ch] [-2364h]
  int v713; // [sp+Ch] [-2364h]
  int v714; // [sp+Ch] [-2364h]
  int v715; // [sp+Ch] [-2364h]
  int v716; // [sp+Ch] [-2364h]
  int v717; // [sp+Ch] [-2364h]
  int v718; // [sp+Ch] [-2364h]
  int v719; // [sp+Ch] [-2364h]
  int v720; // [sp+Ch] [-2364h]
  int v721; // [sp+Ch] [-2364h]
  int v722; // [sp+Ch] [-2364h]
  int v723; // [sp+Ch] [-2364h]
  int v724; // [sp+Ch] [-2364h]
  int v725; // [sp+Ch] [-2364h]
  int v726; // [sp+Ch] [-2364h]
  int v727; // [sp+Ch] [-2364h]
  int v728; // [sp+Ch] [-2364h]
  int v729; // [sp+Ch] [-2364h]
  int v730; // [sp+Ch] [-2364h]
  int v731; // [sp+Ch] [-2364h]
  int v732; // [sp+10h] [-2360h]
  int v733; // [sp+10h] [-2360h]
  int v734; // [sp+10h] [-2360h]
  int v735; // [sp+10h] [-2360h]
  int v736; // [sp+10h] [-2360h]
  int v737; // [sp+10h] [-2360h]
  int v738; // [sp+10h] [-2360h]
  int v739; // [sp+10h] [-2360h]
  int v740; // [sp+10h] [-2360h]
  int v741; // [sp+10h] [-2360h]
  int v742; // [sp+10h] [-2360h]
  int v743; // [sp+10h] [-2360h]
  int v744; // [sp+10h] [-2360h]
  int v745; // [sp+10h] [-2360h]
  int v746; // [sp+10h] [-2360h]
  int v747; // [sp+10h] [-2360h]
  int v748; // [sp+10h] [-2360h]
  int v749; // [sp+10h] [-2360h]
  int v750; // [sp+10h] [-2360h]
  int v751; // [sp+10h] [-2360h]
  int v752; // [sp+10h] [-2360h]
  int v753; // [sp+10h] [-2360h]
  int v754; // [sp+10h] [-2360h]
  int v755; // [sp+10h] [-2360h]
  int v756; // [sp+10h] [-2360h]
  int v757; // [sp+10h] [-2360h]
  int v758; // [sp+10h] [-2360h]
  int v759; // [sp+10h] [-2360h]
  int v760; // [sp+10h] [-2360h]
  int v761; // [sp+10h] [-2360h]
  int v762; // [sp+10h] [-2360h]
  int v763; // [sp+10h] [-2360h]
  int v764; // [sp+10h] [-2360h]
  int v765; // [sp+10h] [-2360h]
  int v766; // [sp+10h] [-2360h]
  int v767; // [sp+10h] [-2360h]
  int v768; // [sp+10h] [-2360h]
  int v769; // [sp+10h] [-2360h]
  int v770; // [sp+10h] [-2360h]
  int v771; // [sp+10h] [-2360h]
  int v772; // [sp+10h] [-2360h]
  int v773; // [sp+10h] [-2360h]
  int v774; // [sp+10h] [-2360h]
  int v775; // [sp+10h] [-2360h]
  int v776; // [sp+10h] [-2360h]
  int v777; // [sp+10h] [-2360h]
  int v778; // [sp+10h] [-2360h]
  int v779; // [sp+10h] [-2360h]
  int v780; // [sp+10h] [-2360h]
  int v781; // [sp+10h] [-2360h]
  int v782; // [sp+10h] [-2360h]
  int v783; // [sp+10h] [-2360h]
  int v784; // [sp+10h] [-2360h]
  int v785; // [sp+10h] [-2360h]
  int v786; // [sp+10h] [-2360h]
  int v787; // [sp+10h] [-2360h]
  int v788; // [sp+10h] [-2360h]
  int v789; // [sp+10h] [-2360h]
  int v790; // [sp+10h] [-2360h]
  int v791; // [sp+10h] [-2360h]
  int v792; // [sp+10h] [-2360h]
  int v793; // [sp+10h] [-2360h]
  int v794; // [sp+10h] [-2360h]
  int v795; // [sp+10h] [-2360h]
  int v796; // [sp+10h] [-2360h]
  int v797; // [sp+10h] [-2360h]
  int v798; // [sp+10h] [-2360h]
  int v799; // [sp+10h] [-2360h]
  int v800; // [sp+10h] [-2360h]
  int v801; // [sp+10h] [-2360h]
  int v802; // [sp+10h] [-2360h]
  int v803; // [sp+10h] [-2360h]
  int v804; // [sp+10h] [-2360h]
  int v805; // [sp+10h] [-2360h]
  int v806; // [sp+14h] [-235Ch]
  int v807; // [sp+14h] [-235Ch]
  int v808; // [sp+14h] [-235Ch]
  int v809; // [sp+14h] [-235Ch]
  int v810; // [sp+14h] [-235Ch]
  int v811; // [sp+14h] [-235Ch]
  int v812; // [sp+14h] [-235Ch]
  int v813; // [sp+14h] [-235Ch]
  int v814; // [sp+14h] [-235Ch]
  int v815; // [sp+14h] [-235Ch]
  int v816; // [sp+14h] [-235Ch]
  int v817; // [sp+14h] [-235Ch]
  int v818; // [sp+14h] [-235Ch]
  int v819; // [sp+14h] [-235Ch]
  int v820; // [sp+14h] [-235Ch]
  int v821; // [sp+14h] [-235Ch]
  int v822; // [sp+14h] [-235Ch]
  int v823; // [sp+14h] [-235Ch]
  int v824; // [sp+14h] [-235Ch]
  int v825; // [sp+14h] [-235Ch]
  int v826; // [sp+14h] [-235Ch]
  int v827; // [sp+14h] [-235Ch]
  int v828; // [sp+14h] [-235Ch]
  int v829; // [sp+14h] [-235Ch]
  int v830; // [sp+14h] [-235Ch]
  int v831; // [sp+14h] [-235Ch]
  int v832; // [sp+14h] [-235Ch]
  int v833; // [sp+14h] [-235Ch]
  int v834; // [sp+14h] [-235Ch]
  int v835; // [sp+14h] [-235Ch]
  int v836; // [sp+14h] [-235Ch]
  int v837; // [sp+14h] [-235Ch]
  int v838; // [sp+14h] [-235Ch]
  int v839; // [sp+14h] [-235Ch]
  int v840; // [sp+14h] [-235Ch]
  int v841; // [sp+14h] [-235Ch]
  int v842; // [sp+14h] [-235Ch]
  int v843; // [sp+14h] [-235Ch]
  int v844; // [sp+14h] [-235Ch]
  int v845; // [sp+14h] [-235Ch]
  int v846; // [sp+14h] [-235Ch]
  int v847; // [sp+14h] [-235Ch]
  int v848; // [sp+14h] [-235Ch]
  int v849; // [sp+14h] [-235Ch]
  int v850; // [sp+14h] [-235Ch]
  int v851; // [sp+14h] [-235Ch]
  int v852; // [sp+14h] [-235Ch]
  int v853; // [sp+14h] [-235Ch]
  int v854; // [sp+14h] [-235Ch]
  int v855; // [sp+14h] [-235Ch]
  int v856; // [sp+14h] [-235Ch]
  int v857; // [sp+14h] [-235Ch]
  int v858; // [sp+14h] [-235Ch]
  int v859; // [sp+14h] [-235Ch]
  int v860; // [sp+14h] [-235Ch]
  int v861; // [sp+14h] [-235Ch]
  int v862; // [sp+14h] [-235Ch]
  int v863; // [sp+14h] [-235Ch]
  int v864; // [sp+14h] [-235Ch]
  int v865; // [sp+14h] [-235Ch]
  int v866; // [sp+14h] [-235Ch]
  int v867; // [sp+14h] [-235Ch]
  int v868; // [sp+14h] [-235Ch]
  int v869; // [sp+14h] [-235Ch]
  int v870; // [sp+14h] [-235Ch]
  int v871; // [sp+14h] [-235Ch]
  int v872; // [sp+14h] [-235Ch]
  int v873; // [sp+14h] [-235Ch]
  int v874; // [sp+14h] [-235Ch]
  int v875; // [sp+14h] [-235Ch]
  int v876; // [sp+14h] [-235Ch]
  int v877; // [sp+14h] [-235Ch]
  int v878; // [sp+14h] [-235Ch]
  int v879; // [sp+14h] [-235Ch]
  int v880; // [sp+18h] [-2358h]
  int v881; // [sp+18h] [-2358h]
  int v882; // [sp+18h] [-2358h]
  int v883; // [sp+18h] [-2358h]
  int v884; // [sp+18h] [-2358h]
  int v885; // [sp+18h] [-2358h]
  int v886; // [sp+18h] [-2358h]
  int v887; // [sp+18h] [-2358h]
  int v888; // [sp+18h] [-2358h]
  int v889; // [sp+18h] [-2358h]
  int v890; // [sp+18h] [-2358h]
  int v891; // [sp+18h] [-2358h]
  int v892; // [sp+18h] [-2358h]
  int v893; // [sp+18h] [-2358h]
  int v894; // [sp+18h] [-2358h]
  int v895; // [sp+18h] [-2358h]
  int v896; // [sp+18h] [-2358h]
  int v897; // [sp+18h] [-2358h]
  int v898; // [sp+18h] [-2358h]
  int v899; // [sp+18h] [-2358h]
  int v900; // [sp+18h] [-2358h]
  int v901; // [sp+18h] [-2358h]
  int v902; // [sp+18h] [-2358h]
  int v903; // [sp+18h] [-2358h]
  int v904; // [sp+18h] [-2358h]
  int v905; // [sp+18h] [-2358h]
  int v906; // [sp+18h] [-2358h]
  int v907; // [sp+18h] [-2358h]
  int v908; // [sp+18h] [-2358h]
  int v909; // [sp+18h] [-2358h]
  int v910; // [sp+18h] [-2358h]
  int v911; // [sp+18h] [-2358h]
  int v912; // [sp+18h] [-2358h]
  int v913; // [sp+18h] [-2358h]
  int v914; // [sp+18h] [-2358h]
  int v915; // [sp+18h] [-2358h]
  int v916; // [sp+18h] [-2358h]
  int v917; // [sp+18h] [-2358h]
  int v918; // [sp+18h] [-2358h]
  int v919; // [sp+18h] [-2358h]
  int v920; // [sp+18h] [-2358h]
  int v921; // [sp+18h] [-2358h]
  int v922; // [sp+18h] [-2358h]
  int v923; // [sp+18h] [-2358h]
  int v924; // [sp+18h] [-2358h]
  int v925; // [sp+18h] [-2358h]
  int v926; // [sp+18h] [-2358h]
  int v927; // [sp+18h] [-2358h]
  int v928; // [sp+18h] [-2358h]
  int v929; // [sp+18h] [-2358h]
  int v930; // [sp+18h] [-2358h]
  int v931; // [sp+18h] [-2358h]
  int v932; // [sp+18h] [-2358h]
  int v933; // [sp+18h] [-2358h]
  int v934; // [sp+18h] [-2358h]
  int v935; // [sp+18h] [-2358h]
  int v936; // [sp+18h] [-2358h]
  int v937; // [sp+18h] [-2358h]
  int v938; // [sp+18h] [-2358h]
  int v939; // [sp+18h] [-2358h]
  int v940; // [sp+18h] [-2358h]
  int v941; // [sp+18h] [-2358h]
  int v942; // [sp+18h] [-2358h]
  int v943; // [sp+18h] [-2358h]
  int v944; // [sp+18h] [-2358h]
  int v945; // [sp+18h] [-2358h]
  int v946; // [sp+18h] [-2358h]
  int v947; // [sp+18h] [-2358h]
  int v948; // [sp+18h] [-2358h]
  int v949; // [sp+18h] [-2358h]
  int v950; // [sp+18h] [-2358h]
  int v951; // [sp+18h] [-2358h]
  int v952; // [sp+18h] [-2358h]
  int v953; // [sp+18h] [-2358h]
  int v954; // [sp+1Ch] [-2354h]
  int v955; // [sp+1Ch] [-2354h]
  int v956; // [sp+1Ch] [-2354h]
  int v957; // [sp+1Ch] [-2354h]
  int v958; // [sp+1Ch] [-2354h]
  int v959; // [sp+1Ch] [-2354h]
  int v960; // [sp+1Ch] [-2354h]
  int v961; // [sp+1Ch] [-2354h]
  int v962; // [sp+1Ch] [-2354h]
  int v963; // [sp+1Ch] [-2354h]
  int v964; // [sp+1Ch] [-2354h]
  int v965; // [sp+1Ch] [-2354h]
  int v966; // [sp+1Ch] [-2354h]
  int v967; // [sp+1Ch] [-2354h]
  int v968; // [sp+1Ch] [-2354h]
  int v969; // [sp+1Ch] [-2354h]
  int v970; // [sp+1Ch] [-2354h]
  int v971; // [sp+1Ch] [-2354h]
  int v972; // [sp+1Ch] [-2354h]
  int v973; // [sp+1Ch] [-2354h]
  int v974; // [sp+1Ch] [-2354h]
  int v975; // [sp+1Ch] [-2354h]
  int v976; // [sp+1Ch] [-2354h]
  int v977; // [sp+1Ch] [-2354h]
  int v978; // [sp+1Ch] [-2354h]
  int v979; // [sp+1Ch] [-2354h]
  int v980; // [sp+1Ch] [-2354h]
  int v981; // [sp+1Ch] [-2354h]
  int v982; // [sp+1Ch] [-2354h]
  int v983; // [sp+1Ch] [-2354h]
  int v984; // [sp+1Ch] [-2354h]
  int v985; // [sp+1Ch] [-2354h]
  int v986; // [sp+1Ch] [-2354h]
  int v987; // [sp+1Ch] [-2354h]
  int v988; // [sp+1Ch] [-2354h]
  int v989; // [sp+1Ch] [-2354h]
  int v990; // [sp+1Ch] [-2354h]
  int v991; // [sp+1Ch] [-2354h]
  int v992; // [sp+1Ch] [-2354h]
  int v993; // [sp+1Ch] [-2354h]
  int v994; // [sp+1Ch] [-2354h]
  int v995; // [sp+1Ch] [-2354h]
  int v996; // [sp+1Ch] [-2354h]
  int v997; // [sp+1Ch] [-2354h]
  int v998; // [sp+1Ch] [-2354h]
  int v999; // [sp+1Ch] [-2354h]
  int v1000; // [sp+1Ch] [-2354h]
  int v1001; // [sp+1Ch] [-2354h]
  int v1002; // [sp+1Ch] [-2354h]
  int v1003; // [sp+1Ch] [-2354h]
  int v1004; // [sp+1Ch] [-2354h]
  int v1005; // [sp+1Ch] [-2354h]
  int v1006; // [sp+1Ch] [-2354h]
  int v1007; // [sp+1Ch] [-2354h]
  int v1008; // [sp+1Ch] [-2354h]
  int v1009; // [sp+1Ch] [-2354h]
  int v1010; // [sp+1Ch] [-2354h]
  int v1011; // [sp+1Ch] [-2354h]
  int v1012; // [sp+1Ch] [-2354h]
  int v1013; // [sp+1Ch] [-2354h]
  int v1014; // [sp+1Ch] [-2354h]
  int v1015; // [sp+1Ch] [-2354h]
  int v1016; // [sp+1Ch] [-2354h]
  int v1017; // [sp+1Ch] [-2354h]
  int v1018; // [sp+1Ch] [-2354h]
  int v1019; // [sp+1Ch] [-2354h]
  int v1020; // [sp+1Ch] [-2354h]
  int v1021; // [sp+1Ch] [-2354h]
  int v1022; // [sp+1Ch] [-2354h]
  int v1023; // [sp+1Ch] [-2354h]
  int v1024; // [sp+1Ch] [-2354h]
  int v1025; // [sp+1Ch] [-2354h]
  int v1026; // [sp+1Ch] [-2354h]
  int v1027; // [sp+1Ch] [-2354h]
  double v1028; // [sp+20h] [-2350h]
  idStr v1029; // [sp+50h] [-2320h] BYREF
  DWORD v1030; // [sp+70h] [-2300h] BYREF
  unsigned int v1031[3]; // [sp+74h] [-22FCh] BYREF
  _DM_SYSTEM_INFO v1032; // [sp+80h] [-22F0h] BYREF
  _DM_MEMORY_STATISTICS v1033; // [sp+A0h] [-22D0h] BYREF
  idStr v1034; // [sp+D0h] [-22A0h] BYREF
  idreports::Xbox360CrashReport v1035; // [sp+F0h] [-2280h] BYREF
  _DM_MEMORY_STATISTICS v1036; // [sp+160h] [-2210h] BYREF
  va v1037; // [sp+190h] [-21E0h] BYREF
  va v1038; // [sp+1190h] [-11E0h] BYREF
  PVOID v1039[120]; // [sp+2190h] [-1E0h] BYREF

  v1030 = 0;
  v1034.allocedAndFlag = 20;
  v1034.data = v1034.baseBuffer;
  v1034.len = 0;
  v1034.baseBuffer[0] = 0;
  if ( common->IsMultiplayer(this: common) )
    v4 = "RageMP: ";
  else
    v4 = "RageSP: ";
  idStr::operator=(this: &v1034, text: v4);
  idreports::Xbox360CrashReport::Xbox360CrashReport(this: &v1035);
  idreports::Xbox360CrashReport::set_game(this: &v1035, value: "Tungsten");
  idreports::Xbox360CrashReport::set_username(this: &v1035, value: reportData.userName.data);
  idreports::Xbox360CrashReport::set_platform(this: &v1035, value: reportData.platform.data);
  v1035.buildnumbermajor_ = reportData.buildNumberMajor;
  v1035.buildnumberminor_ = reportData.buildNumberMinor;
  v1035._has_bits_[0] |= 0x18u;
  idreports::Xbox360CrashReport::set_buildstring(this: &v1035, value: reportData.buildMessage.data);
  v5 = (unsigned __int64)time64(timeptr: nullptr) >> 32;
  v6 = Sys_TimeStampToLogFormat(timeStamp: v5);
  idreports::Xbox360CrashReport::set_timestamp(this: &v1035, value: v6);
  idreports::Xbox360CrashReport::set_launchcommand(this: &v1035, value: reportData.launchCommand.data);
  idreports::Xbox360CrashReport::set_vtfilepath(this: &v1035, value: reportData.vtFilePathCvar.data);
  idreports::Xbox360CrashReport::set_vtfilepathvmtroverride(
    this: &v1035,
    value: reportData.vtFilePathVmtrOverrideCvar.data);
  idreports::Xbox360CrashReport::set_mappath(this: &v1035, value: reportData.mapPath.data);
  v7 = idreports::Xbox360CrashReport::mutable_kitinfo(this: &v1035);
  v1031[0] = 64;
  v8 = v7;
  DmGetXboxName(a1: szMachineName, a2: v1031);
  v9 = 0;
  if ( szMachineName[0] != 0 )
  {
    v10 = szMachineName;
    do
    {
      ++v10;
      ++v9;
    }
    while ( *v10 != 0 );
  }
  idreports::Xbox360KitInfo::set_consolename(this: v8, value: szMachineName, size: v9);
  if ( DmGetConsoleType(pdwConsoleType: &v1030) == 47841280 )
  {
    v11 = v1030;
    if ( v1030 != 0 )
    {
      v13 = 1;
      v8->_has_bits_[0] |= 1u;
      if ( v11 != 1 )
        v13 = 2;
      v8->kittype_ = v13;
    }
    else
    {
      v12 = v8->_has_bits_[0];
      v8->kittype_ = 0;
      v8->_has_bits_[0] = v12 | 1;
    }
  }
  v1032.SizeOfStruct = 32;
  SystemInfo = DmGetSystemInfo(pdmGetSystemInfo: &v1032);
  if ( SystemInfo == 47841280 )
  {
    v15 = idreports::Xbox360KitInfo::mutable_basekernelversion(this: v8);
    v16 = v15->_has_bits_[0];
    v15->major_ = v1032.BaseKernelVersion.Major;
    v15->_has_bits_[0] = v16 | 1;
    Minor = v1032.BaseKernelVersion.Minor;
    v18 = v16 | 7;
    v15->_has_bits_[0] = v16 | 3;
    v15->minor_ = Minor;
    v20 = v16 | 0xF;
    Build = v1032.BaseKernelVersion.Build;
    v15->_has_bits_[0] = v18;
    v15->build_ = Build;
    Qfe = v1032.BaseKernelVersion.Qfe;
    v15->_has_bits_[0] = v20;
    v15->qfe_ = Qfe;
    v22 = idreports::Xbox360KitInfo::mutable_kernelversion(this: v8);
    v23 = v22->_has_bits_[0];
    v22->major_ = v1032.KernelVersion.Major;
    v22->_has_bits_[0] = v23 | 1;
    v24 = v1032.KernelVersion.Minor;
    v25 = v23 | 7;
    v22->_has_bits_[0] = v23 | 3;
    v22->minor_ = v24;
    v27 = v23 | 0xF;
    v26 = v1032.KernelVersion.Build;
    v22->_has_bits_[0] = v25;
    v22->build_ = v26;
    v28 = v1032.KernelVersion.Qfe;
    v22->_has_bits_[0] = v27;
    v22->qfe_ = v28;
    v29 = idreports::Xbox360KitInfo::mutable_xdkversion(this: v8);
    Major = v1032.XDKVersion.Major;
    v31 = v29->_has_bits_[0] | 3;
    v29->_has_bits_[0] |= 1u;
    v29->major_ = Major;
    v32 = v1032.XDKVersion.Minor;
    v29->_has_bits_[0] = v31;
    v33 = v31 | 0xC;
    v29->minor_ = v32;
    v34 = v1032.XDKVersion.Build;
    v29->_has_bits_[0] = v31 | 4;
    v29->build_ = v34;
    v35 = v1032.XDKVersion.Qfe;
    v29->_has_bits_[0] = v33;
    v29->qfe_ = v35;
    dmSystemInfoFlags = v1032.dmSystemInfoFlags;
    v8->_has_bits_[0] |= 0x10u;
    v8->systeminfoflags_ = dmSystemInfoFlags;
  }
  else
  {
    idLib::Warning(fmt: "CrashHandler: Failed to get system information %08X", SystemInfo);
  }
  v1033.cbSize = 48;
  v37 = DmQueryMemoryStatistics(MemStat: &v1033);
  if ( v37 == 47841280 )
  {
    v38 = idreports::Xbox360CrashReport::mutable_consolememory(this: &v1035);
    TotalPages = v1033.TotalPages;
    v40 = v38->_has_bits_[0] | 3;
    v38->_has_bits_[0] |= 1u;
    v38->totalpages_ = TotalPages;
    AvailablePages = v1033.AvailablePages;
    v38->_has_bits_[0] = v40;
    v38->availablepages_ = AvailablePages;
    StackPages = v1033.StackPages;
    v43 = v40 | 0x2C;
    v38->_has_bits_[0] = v40 | 4;
    v38->stackpages_ = StackPages;
    v44 = v40 | 0x6C;
    VirtualPageTablePages = v1033.VirtualPageTablePages;
    v38->_has_bits_[0] = v40 | 0xC;
    v40 |= 0xECu;
    v38->virtualpagetablepages_ = VirtualPageTablePages;
    PoolPages = v1033.PoolPages;
    v47 = v40 | 0x300;
    v38->_has_bits_[0] = v43;
    v38->poolpages_ = PoolPages;
    v48 = v40 | 0x700;
    VirtualMappedPages = v1033.VirtualMappedPages;
    v38->_has_bits_[0] = v44;
    v38->virtualmappedpages_ = VirtualMappedPages;
    ImagePages = v1033.ImagePages;
    v38->_has_bits_[0] = v40;
    v38->imagepages_ = ImagePages;
    FileCachePages = v1033.FileCachePages;
    v38->_has_bits_[0] = v40 | 0x100;
    v38->filecachepages_ = FileCachePages;
    ContiguousPages = v1033.ContiguousPages;
    v38->_has_bits_[0] = v47;
    v38->contiguouspages_ = ContiguousPages;
    DebuggerPages = v1033.DebuggerPages;
    v38->_has_bits_[0] = v48;
    v38->debuggerpages_ = DebuggerPages;
  }
  else
  {
    idLib::Warning(fmt: "CrashHandler: Failed to get kit memory stats %08X", v37);
  }
  v1036.cbSize = 48;
  v54 = DmQueryTitleMemoryStatistics(MemStat: &v1036);
  if ( v54 == 47841280 )
  {
    v55 = idreports::Xbox360CrashReport::mutable_titlememory(this: &v1035);
    v56 = v55->_has_bits_[0] | 1;
    v55->totalpages_ = v1033.TotalPages;
    v55->_has_bits_[0] = v56;
    v57 = v56 | 6;
    v58 = v56 | 0xE;
    v59 = v56 | 0x2E;
    v60 = v1033.AvailablePages;
    v55->_has_bits_[0] = v56 | 2;
    v56 |= 0x6Eu;
    v55->availablepages_ = v60;
    v61 = v1033.StackPages;
    v62 = v56 | 0x180;
    v55->_has_bits_[0] = v57;
    v55->stackpages_ = v61;
    v63 = v56 | 0x380;
    v64 = v1033.VirtualPageTablePages;
    v65 = v56 | 0x780;
    v55->_has_bits_[0] = v58;
    v55->virtualpagetablepages_ = v64;
    v66 = v1033.PoolPages;
    v55->_has_bits_[0] = v59;
    v55->poolpages_ = v66;
    v67 = v1033.VirtualMappedPages;
    v55->_has_bits_[0] = v56;
    v55->virtualmappedpages_ = v67;
    v68 = v1033.ImagePages;
    v55->_has_bits_[0] = v56 | 0x80;
    v55->imagepages_ = v68;
    v69 = v1033.FileCachePages;
    v55->_has_bits_[0] = v62;
    v55->filecachepages_ = v69;
    v70 = v1033.ContiguousPages;
    v55->_has_bits_[0] = v63;
    v55->contiguouspages_ = v70;
    v71 = v1033.DebuggerPages;
    v55->_has_bits_[0] = v65;
    v55->debuggerpages_ = v71;
  }
  else
  {
    idLib::Warning(fmt: "CrashHandler: Failed to get title memory stats %08X", v54);
  }
  if ( pExPtrs_ != nullptr )
  {
    idStr::idStr(this: &v1029, text: "Unknown Exception");
    v72 = **pExPtrs_;
    if ( v72 > 0xC000008D )
    {
      if ( v72 > 0xC00000FD )
        goto LABEL_73;
      if ( v72 == -1073741571 )
      {
        v74 = "EXCEPTION_STACK_OVERFLOW";
      }
      else
      {
        v77 = v72 + 1073741682;
        if ( v77 > 8 )
          goto LABEL_73;
        switch ( v77 )
        {
          case 1u:
            v74 = "EXCEPTION_FLT_INEXACT_RESULT";
            break;
          case 2u:
            v74 = "EXCEPTION_FLT_INVALID_OPERATION";
            break;
          case 3u:
            v74 = "EXCEPTION_FLT_OVERFLOW";
            break;
          case 4u:
            v74 = "EXCEPTION_FLT_STACK_CHECK";
            break;
          case 5u:
            v74 = "EXCEPTION_FLT_UNDERFLOW";
            break;
          case 6u:
            v74 = "EXCEPTION_INT_DIVIDE_BY_ZERO";
            break;
          case 7u:
            v74 = "EXCEPTION_INT_OVERFLOW";
            break;
          default:
            if ( v77 != 0 )
              v74 = "EXCEPTION_PRIV_INSTRUCTION";
            else
              v74 = "EXCEPTION_FLT_DIVIDE_BY_ZERO";
            break;
        }
      }
    }
    else if ( v72 == -1073741683 )
    {
      v74 = "EXCEPTION_FLT_DENORMAL_OPERAND";
    }
    else if ( v72 > 0xC0000006 )
    {
      if ( v72 > 0xC0000025 )
      {
        v76 = v72 + 1073741786;
        if ( v76 != 0 )
        {
          if ( v76 != 102 )
            goto LABEL_73;
          v74 = "EXCEPTION_ARRAY_BOUNDS_EXCEEDED";
        }
        else
        {
          v74 = "EXCEPTION_INVALID_DISPOSITION";
        }
      }
      else if ( v72 == -1073741787 )
      {
        v74 = "EXCEPTION_NONCONTINUABLE_EXCEPTION";
      }
      else
      {
        v75 = v72 + 1073741816;
        if ( v75 != 0 )
        {
          if ( v75 != 21 )
            goto LABEL_73;
          v74 = "EXCEPTION_ILLEGAL_INSTRUCTION";
        }
        else
        {
          v74 = "EXCEPTION_INVALID_HANDLE";
        }
      }
    }
    else if ( v72 == -1073741818 )
    {
      v74 = "EXCEPTION_IN_PAGE_ERROR";
    }
    else if ( v72 > 0x80000003 )
    {
      if ( v72 == -2147483644 )
      {
        v74 = "EXCEPTION_SINGLE_STEP";
      }
      else
      {
        if ( v72 != -1073741819 )
          goto LABEL_73;
        v74 = "EXCEPTION_ACCESS_VIOLATION";
      }
    }
    else if ( v72 == -2147483645 )
    {
      v74 = "EXCEPTION_BREAKPOINT";
    }
    else
    {
      v73 = v72 + 0x7FFFFFFF;
      if ( v73 != 0 )
      {
        if ( v73 != 1 )
          goto LABEL_73;
        v74 = "EXCEPTION_DATATYPE_MISALIGNMENT";
      }
      else
      {
        v74 = "EXCEPTION_GUARD_PAGE";
      }
    }
    idStr::operator=(this: &v1029, text: v74);
LABEL_73:
    v78 = idreports::Xbox360CrashReport::mutable_exception(this: &v1035);
    LODWORD(v79) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
    LODWORD(v80) = v1029.data;
    v81 = v78;
    HIDWORD(v80) = **pExPtrs_;
    v83 = va::va(
            this: &v1037,
            fmt: "0x%08X (%s)",
            a3: v80,
            a4: v82,
            a5: v79,
            a6: v584,
            a7: v658,
            a8: v732,
            a9: v806,
            a10: v880,
            a11: v954);
    idreports::ExceptionInfo::set_expcode(this: v81, value: v83->buffer);
    LODWORD(v84) = *pExPtrs_;
    HIDWORD(v84) = v81->_has_bits_[0];
    HIDWORD(v85) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
    LODWORD(v86) = HIDWORD(v84) | 2;
    v87 = (*pExPtrs_)[1];
    v81->_has_bits_[0] = HIDWORD(v84) | 2;
    v81->expflags_ = v87;
    HIDWORD(v86) = (*pExPtrs_)[3];
    v88 = va::va(
            this: &v1037,
            fmt: "0x%016p",
            a3: v86,
            a4: v84,
            a5: v85,
            a6: v585,
            a7: v659,
            a8: v733,
            a9: v807,
            a10: v881,
            a11: v955);
    idreports::ExceptionInfo::set_expaddress(this: v81, value: v88->buffer);
    v89 = idreports::Xbox360CrashReport::mutable_registers(this: &v1035);
    LODWORD(v90) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
    HIDWORD(v90) = pExPtrs_[1];
    v91 = v89;
    HIDWORD(v92) = *(_DWORD *)(HIDWORD(v90) + 4);
    v94 = va::va(
            this: &v1037,
            fmt: "0x%08X",
            a3: v92,
            a4: v93,
            a5: v90,
            a6: v586,
            a7: v660,
            a8: v734,
            a9: v808,
            a10: v882,
            a11: v956);
    idreports::XenonRegisterInfo::set_msr(this: v91, value: v94->buffer);
    LODWORD(v95) = pExPtrs_[1];
    HIDWORD(v96) = *(_DWORD *)(v95 + 8);
    v98 = va::va(
            this: &v1037,
            fmt: "0x%08X",
            a3: v96,
            a4: v95,
            a5: v97,
            a6: v587,
            a7: v661,
            a8: v735,
            a9: v809,
            a10: v883,
            a11: v957);
    idreports::XenonRegisterInfo::set_iar(this: v91, value: v98->buffer);
    HIDWORD(v99) = pExPtrs_[1];
    HIDWORD(v100) = *(_DWORD *)(HIDWORD(v99) + 12);
    v102 = va::va(
             this: &v1037,
             fmt: "0x%08X",
             a3: v100,
             a4: v99,
             a5: v101,
             a6: v588,
             a7: v662,
             a8: v736,
             a9: v810,
             a10: v884,
             a11: v958);
    idreports::XenonRegisterInfo::set_lr(this: v91, value: v102->buffer);
    LODWORD(v103) = pExPtrs_[1];
    *(_QWORD *)((char *)&v103 + 4) = *(_QWORD *)(v103 + 16);
    v106 = va::va(
             this: &v1037,
             fmt: *(const char **)(v103 + 16),
             a3: v103,
             a4: v105,
             a5: v104,
             a6: v589,
             a7: v663,
             a8: v737,
             a9: v811,
             a10: v885,
             a11: v959);
    idreports::XenonRegisterInfo::set_ctr(this: v91, value: v106->buffer);
    HIDWORD(v107) = pExPtrs_[1][73];
    v110 = va::va(
             this: &v1037,
             fmt: (const char *)pExPtrs_[1][72],
             a3: v107,
             a4: v109,
             a5: v108,
             a6: v590,
             a7: v664,
             a8: v738,
             a9: v812,
             a10: v886,
             a11: v960);
    idreports::XenonRegisterInfo::set_fpscr(this: v91, value: v110->buffer);
    LODWORD(v111) = pExPtrs_[1];
    HIDWORD(v112) = *(_DWORD *)(v111 + 280);
    v114 = va::va(
             this: &v1037,
             fmt: "0x%08X",
             a3: v112,
             a4: v113,
             a5: v111,
             a6: v591,
             a7: v665,
             a8: v739,
             a9: v813,
             a10: v887,
             a11: v961);
    idreports::XenonRegisterInfo::set_cr(this: v91, value: v114->buffer);
    HIDWORD(v115) = pExPtrs_[1];
    HIDWORD(v116) = *(_DWORD *)(HIDWORD(v115) + 284);
    v118 = va::va(
             this: &v1037,
             fmt: "0x%08X",
             a3: v116,
             a4: v117,
             a5: v115,
             a6: v592,
             a7: v666,
             a8: v740,
             a9: v814,
             a10: v888,
             a11: v962);
    idreports::XenonRegisterInfo::set_xer(this: v91, value: v118->buffer);
    LODWORD(v119) = pExPtrs_[1];
    v1028 = *(float *)(v119 + 560);
    HIDWORD(v120) = LODWORD(v1028);
    v122 = va::va(
             this: &v1037,
             fmt: (const char *)HIDWORD(v1028),
             a3: v120,
             a4: v119,
             a5: v121,
             a6: v593,
             a7: v667,
             a8: v741,
             a9: v815,
             a10: v889,
             a11: v963);
    idreports::XenonRegisterInfo::set_vscr(this: v91, value: v122->buffer);
    google::protobuf::internal::RepeatedPtrFieldBase::Clear<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    HIDWORD(v123) = pExPtrs_[1];
    *(_QWORD *)((char *)&v124 + 4) = *(_QWORD *)(HIDWORD(v123) + 24);
    v126 = va::va(
             this: &v1037,
             fmt: *(const char **)(HIDWORD(v123) + 24),
             a3: v124,
             a4: v123,
             a5: v125,
             a6: v594,
             a7: v668,
             a8: v742,
             a9: v816,
             a10: v890,
             a11: v964);
    v127 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v128 = v126;
    do
    {
      v129 = (unsigned __int8)v128->buffer[0];
      v128 = (va *)((char *)v128 + 1);
    }
    while ( v129 != 0 );
    std::string::assign(this: v127, _Ptr: v126->buffer, _Count: (char *)v128 - (char *)v126 - 1);
    LODWORD(v130) = pExPtrs_[1];
    *(_QWORD *)((char *)&v131 + 4) = *(_QWORD *)(v130 + 32);
    v133 = va::va(
             this: &v1037,
             fmt: *(const char **)(v130 + 32),
             a3: v131,
             a4: v132,
             a5: v130,
             a6: v595,
             a7: v669,
             a8: v743,
             a9: v817,
             a10: v891,
             a11: v965);
    v134 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v135 = v133;
    do
    {
      v136 = (unsigned __int8)v135->buffer[0];
      v135 = (va *)((char *)v135 + 1);
    }
    while ( v136 != 0 );
    std::string::assign(this: v134, _Ptr: v133->buffer, _Count: (char *)v135 - (char *)v133 - 1);
    LODWORD(v137) = pExPtrs_[1];
    *(_QWORD *)((char *)&v138 + 4) = *(_QWORD *)(v137 + 40);
    v140 = va::va(
             this: &v1037,
             fmt: *(const char **)(v137 + 40),
             a3: v138,
             a4: v139,
             a5: v137,
             a6: v596,
             a7: v670,
             a8: v744,
             a9: v818,
             a10: v892,
             a11: v966);
    v141 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v142 = v140;
    do
    {
      v143 = (unsigned __int8)v142->buffer[0];
      v142 = (va *)((char *)v142 + 1);
    }
    while ( v143 != 0 );
    std::string::assign(this: v141, _Ptr: v140->buffer, _Count: (char *)v142 - (char *)v140 - 1);
    LODWORD(v144) = pExPtrs_[1];
    *(_QWORD *)((char *)&v145 + 4) = *(_QWORD *)(v144 + 48);
    v147 = va::va(
             this: &v1037,
             fmt: *(const char **)(v144 + 48),
             a3: v145,
             a4: v146,
             a5: v144,
             a6: v597,
             a7: v671,
             a8: v745,
             a9: v819,
             a10: v893,
             a11: v967);
    v148 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v149 = v147;
    do
    {
      v150 = (unsigned __int8)v149->buffer[0];
      v149 = (va *)((char *)v149 + 1);
    }
    while ( v150 != 0 );
    std::string::assign(this: v148, _Ptr: v147->buffer, _Count: (char *)v149 - (char *)v147 - 1);
    LODWORD(v151) = pExPtrs_[1];
    *(_QWORD *)((char *)&v152 + 4) = *(_QWORD *)(v151 + 56);
    v154 = va::va(
             this: &v1037,
             fmt: *(const char **)(v151 + 56),
             a3: v152,
             a4: v153,
             a5: v151,
             a6: v598,
             a7: v672,
             a8: v746,
             a9: v820,
             a10: v894,
             a11: v968);
    v155 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v156 = v154;
    do
    {
      v157 = (unsigned __int8)v156->buffer[0];
      v156 = (va *)((char *)v156 + 1);
    }
    while ( v157 != 0 );
    std::string::assign(this: v155, _Ptr: v154->buffer, _Count: (char *)v156 - (char *)v154 - 1);
    LODWORD(v158) = pExPtrs_[1];
    *(_QWORD *)((char *)&v159 + 4) = *(_QWORD *)(v158 + 64);
    v161 = va::va(
             this: &v1037,
             fmt: *(const char **)(v158 + 64),
             a3: v159,
             a4: v160,
             a5: v158,
             a6: v599,
             a7: v673,
             a8: v747,
             a9: v821,
             a10: v895,
             a11: v969);
    v162 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v163 = v161;
    do
    {
      v164 = (unsigned __int8)v163->buffer[0];
      v163 = (va *)((char *)v163 + 1);
    }
    while ( v164 != 0 );
    std::string::assign(this: v162, _Ptr: v161->buffer, _Count: (char *)v163 - (char *)v161 - 1);
    LODWORD(v165) = pExPtrs_[1];
    *(_QWORD *)((char *)&v166 + 4) = *(_QWORD *)(v165 + 72);
    v168 = va::va(
             this: &v1037,
             fmt: *(const char **)(v165 + 72),
             a3: v166,
             a4: v167,
             a5: v165,
             a6: v600,
             a7: v674,
             a8: v748,
             a9: v822,
             a10: v896,
             a11: v970);
    v169 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v170 = v168;
    do
    {
      v171 = (unsigned __int8)v170->buffer[0];
      v170 = (va *)((char *)v170 + 1);
    }
    while ( v171 != 0 );
    std::string::assign(this: v169, _Ptr: v168->buffer, _Count: (char *)v170 - (char *)v168 - 1);
    LODWORD(v172) = pExPtrs_[1];
    *(_QWORD *)((char *)&v173 + 4) = *(_QWORD *)(v172 + 80);
    v175 = va::va(
             this: &v1037,
             fmt: *(const char **)(v172 + 80),
             a3: v173,
             a4: v174,
             a5: v172,
             a6: v601,
             a7: v675,
             a8: v749,
             a9: v823,
             a10: v897,
             a11: v971);
    v176 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v177 = v175;
    do
    {
      v178 = (unsigned __int8)v177->buffer[0];
      v177 = (va *)((char *)v177 + 1);
    }
    while ( v178 != 0 );
    std::string::assign(this: v176, _Ptr: v175->buffer, _Count: (char *)v177 - (char *)v175 - 1);
    LODWORD(v179) = pExPtrs_[1];
    *(_QWORD *)((char *)&v180 + 4) = *(_QWORD *)(v179 + 88);
    v182 = va::va(
             this: &v1037,
             fmt: *(const char **)(v179 + 88),
             a3: v180,
             a4: v181,
             a5: v179,
             a6: v602,
             a7: v676,
             a8: v750,
             a9: v824,
             a10: v898,
             a11: v972);
    v183 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v184 = v182;
    do
    {
      v185 = (unsigned __int8)v184->buffer[0];
      v184 = (va *)((char *)v184 + 1);
    }
    while ( v185 != 0 );
    std::string::assign(this: v183, _Ptr: v182->buffer, _Count: (char *)v184 - (char *)v182 - 1);
    LODWORD(v186) = pExPtrs_[1];
    *(_QWORD *)((char *)&v187 + 4) = *(_QWORD *)(v186 + 96);
    v189 = va::va(
             this: &v1037,
             fmt: *(const char **)(v186 + 96),
             a3: v187,
             a4: v188,
             a5: v186,
             a6: v603,
             a7: v677,
             a8: v751,
             a9: v825,
             a10: v899,
             a11: v973);
    v190 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v191 = v189;
    do
    {
      v192 = (unsigned __int8)v191->buffer[0];
      v191 = (va *)((char *)v191 + 1);
    }
    while ( v192 != 0 );
    std::string::assign(this: v190, _Ptr: v189->buffer, _Count: (char *)v191 - (char *)v189 - 1);
    LODWORD(v193) = pExPtrs_[1];
    *(_QWORD *)((char *)&v194 + 4) = *(_QWORD *)(v193 + 104);
    v196 = va::va(
             this: &v1037,
             fmt: *(const char **)(v193 + 104),
             a3: v194,
             a4: v195,
             a5: v193,
             a6: v604,
             a7: v678,
             a8: v752,
             a9: v826,
             a10: v900,
             a11: v974);
    v197 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v198 = v196;
    do
    {
      v199 = (unsigned __int8)v198->buffer[0];
      v198 = (va *)((char *)v198 + 1);
    }
    while ( v199 != 0 );
    std::string::assign(this: v197, _Ptr: v196->buffer, _Count: (char *)v198 - (char *)v196 - 1);
    LODWORD(v200) = pExPtrs_[1];
    *(_QWORD *)((char *)&v201 + 4) = *(_QWORD *)(v200 + 112);
    v203 = va::va(
             this: &v1037,
             fmt: *(const char **)(v200 + 112),
             a3: v201,
             a4: v202,
             a5: v200,
             a6: v605,
             a7: v679,
             a8: v753,
             a9: v827,
             a10: v901,
             a11: v975);
    v204 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v205 = v203;
    do
    {
      v206 = (unsigned __int8)v205->buffer[0];
      v205 = (va *)((char *)v205 + 1);
    }
    while ( v206 != 0 );
    std::string::assign(this: v204, _Ptr: v203->buffer, _Count: (char *)v205 - (char *)v203 - 1);
    LODWORD(v207) = pExPtrs_[1];
    *(_QWORD *)((char *)&v208 + 4) = *(_QWORD *)(v207 + 120);
    v210 = va::va(
             this: &v1037,
             fmt: *(const char **)(v207 + 120),
             a3: v208,
             a4: v209,
             a5: v207,
             a6: v606,
             a7: v680,
             a8: v754,
             a9: v828,
             a10: v902,
             a11: v976);
    v211 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v212 = v210;
    do
    {
      v213 = (unsigned __int8)v212->buffer[0];
      v212 = (va *)((char *)v212 + 1);
    }
    while ( v213 != 0 );
    std::string::assign(this: v211, _Ptr: v210->buffer, _Count: (char *)v212 - (char *)v210 - 1);
    LODWORD(v214) = pExPtrs_[1];
    *(_QWORD *)((char *)&v215 + 4) = *(_QWORD *)(v214 + 128);
    v217 = va::va(
             this: &v1037,
             fmt: *(const char **)(v214 + 128),
             a3: v215,
             a4: v216,
             a5: v214,
             a6: v607,
             a7: v681,
             a8: v755,
             a9: v829,
             a10: v903,
             a11: v977);
    v218 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v219 = v217;
    do
    {
      v220 = (unsigned __int8)v219->buffer[0];
      v219 = (va *)((char *)v219 + 1);
    }
    while ( v220 != 0 );
    std::string::assign(this: v218, _Ptr: v217->buffer, _Count: (char *)v219 - (char *)v217 - 1);
    LODWORD(v221) = pExPtrs_[1];
    *(_QWORD *)((char *)&v222 + 4) = *(_QWORD *)(v221 + 136);
    v224 = va::va(
             this: &v1037,
             fmt: *(const char **)(v221 + 136),
             a3: v222,
             a4: v223,
             a5: v221,
             a6: v608,
             a7: v682,
             a8: v756,
             a9: v830,
             a10: v904,
             a11: v978);
    v225 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v226 = v224;
    do
    {
      v227 = (unsigned __int8)v226->buffer[0];
      v226 = (va *)((char *)v226 + 1);
    }
    while ( v227 != 0 );
    std::string::assign(this: v225, _Ptr: v224->buffer, _Count: (char *)v226 - (char *)v224 - 1);
    LODWORD(v228) = pExPtrs_[1];
    *(_QWORD *)((char *)&v229 + 4) = *(_QWORD *)(v228 + 144);
    v231 = va::va(
             this: &v1037,
             fmt: *(const char **)(v228 + 144),
             a3: v229,
             a4: v230,
             a5: v228,
             a6: v609,
             a7: v683,
             a8: v757,
             a9: v831,
             a10: v905,
             a11: v979);
    v232 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v233 = v231;
    do
    {
      v234 = (unsigned __int8)v233->buffer[0];
      v233 = (va *)((char *)v233 + 1);
    }
    while ( v234 != 0 );
    std::string::assign(this: v232, _Ptr: v231->buffer, _Count: (char *)v233 - (char *)v231 - 1);
    LODWORD(v235) = pExPtrs_[1];
    *(_QWORD *)((char *)&v236 + 4) = *(_QWORD *)(v235 + 152);
    v238 = va::va(
             this: &v1037,
             fmt: *(const char **)(v235 + 152),
             a3: v236,
             a4: v237,
             a5: v235,
             a6: v610,
             a7: v684,
             a8: v758,
             a9: v832,
             a10: v906,
             a11: v980);
    v239 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v240 = v238;
    do
    {
      v241 = (unsigned __int8)v240->buffer[0];
      v240 = (va *)((char *)v240 + 1);
    }
    while ( v241 != 0 );
    std::string::assign(this: v239, _Ptr: v238->buffer, _Count: (char *)v240 - (char *)v238 - 1);
    LODWORD(v242) = pExPtrs_[1];
    *(_QWORD *)((char *)&v243 + 4) = *(_QWORD *)(v242 + 160);
    v245 = va::va(
             this: &v1038,
             fmt: *(const char **)(v242 + 160),
             a3: v243,
             a4: v244,
             a5: v242,
             a6: v611,
             a7: v685,
             a8: v759,
             a9: v833,
             a10: v907,
             a11: v981);
    v246 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v247 = v245;
    do
    {
      v248 = (unsigned __int8)v247->buffer[0];
      v247 = (va *)((char *)v247 + 1);
    }
    while ( v248 != 0 );
    std::string::assign(this: v246, _Ptr: v245->buffer, _Count: (char *)v247 - (char *)v245 - 1);
    LODWORD(v249) = pExPtrs_[1];
    *(_QWORD *)((char *)&v250 + 4) = *(_QWORD *)(v249 + 168);
    v252 = va::va(
             this: &v1037,
             fmt: *(const char **)(v249 + 168),
             a3: v250,
             a4: v251,
             a5: v249,
             a6: v612,
             a7: v686,
             a8: v760,
             a9: v834,
             a10: v908,
             a11: v982);
    v253 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v254 = v252;
    do
    {
      v255 = (unsigned __int8)v254->buffer[0];
      v254 = (va *)((char *)v254 + 1);
    }
    while ( v255 != 0 );
    std::string::assign(this: v253, _Ptr: v252->buffer, _Count: (char *)v254 - (char *)v252 - 1);
    LODWORD(v256) = pExPtrs_[1];
    *(_QWORD *)((char *)&v257 + 4) = *(_QWORD *)(v256 + 176);
    v259 = va::va(
             this: &v1038,
             fmt: *(const char **)(v256 + 176),
             a3: v257,
             a4: v258,
             a5: v256,
             a6: v613,
             a7: v687,
             a8: v761,
             a9: v835,
             a10: v909,
             a11: v983);
    v260 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v261 = v259;
    do
    {
      v262 = (unsigned __int8)v261->buffer[0];
      v261 = (va *)((char *)v261 + 1);
    }
    while ( v262 != 0 );
    std::string::assign(this: v260, _Ptr: v259->buffer, _Count: (char *)v261 - (char *)v259 - 1);
    LODWORD(v263) = pExPtrs_[1];
    *(_QWORD *)((char *)&v264 + 4) = *(_QWORD *)(v263 + 184);
    v266 = va::va(
             this: &v1037,
             fmt: *(const char **)(v263 + 184),
             a3: v264,
             a4: v265,
             a5: v263,
             a6: v614,
             a7: v688,
             a8: v762,
             a9: v836,
             a10: v910,
             a11: v984);
    v267 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v268 = v266;
    do
    {
      v269 = (unsigned __int8)v268->buffer[0];
      v268 = (va *)((char *)v268 + 1);
    }
    while ( v269 != 0 );
    std::string::assign(this: v267, _Ptr: v266->buffer, _Count: (char *)v268 - (char *)v266 - 1);
    LODWORD(v270) = pExPtrs_[1];
    *(_QWORD *)((char *)&v271 + 4) = *(_QWORD *)(v270 + 192);
    v273 = va::va(
             this: &v1038,
             fmt: *(const char **)(v270 + 192),
             a3: v271,
             a4: v272,
             a5: v270,
             a6: v615,
             a7: v689,
             a8: v763,
             a9: v837,
             a10: v911,
             a11: v985);
    v274 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v275 = v273;
    do
    {
      v276 = (unsigned __int8)v275->buffer[0];
      v275 = (va *)((char *)v275 + 1);
    }
    while ( v276 != 0 );
    std::string::assign(this: v274, _Ptr: v273->buffer, _Count: (char *)v275 - (char *)v273 - 1);
    LODWORD(v277) = pExPtrs_[1];
    *(_QWORD *)((char *)&v278 + 4) = *(_QWORD *)(v277 + 200);
    v280 = va::va(
             this: &v1037,
             fmt: *(const char **)(v277 + 200),
             a3: v278,
             a4: v279,
             a5: v277,
             a6: v616,
             a7: v690,
             a8: v764,
             a9: v838,
             a10: v912,
             a11: v986);
    v281 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v282 = v280;
    do
    {
      v283 = (unsigned __int8)v282->buffer[0];
      v282 = (va *)((char *)v282 + 1);
    }
    while ( v283 != 0 );
    std::string::assign(this: v281, _Ptr: v280->buffer, _Count: (char *)v282 - (char *)v280 - 1);
    LODWORD(v284) = pExPtrs_[1];
    *(_QWORD *)((char *)&v285 + 4) = *(_QWORD *)(v284 + 208);
    v287 = va::va(
             this: &v1038,
             fmt: *(const char **)(v284 + 208),
             a3: v285,
             a4: v286,
             a5: v284,
             a6: v617,
             a7: v691,
             a8: v765,
             a9: v839,
             a10: v913,
             a11: v987);
    v288 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v289 = v287;
    do
    {
      v290 = (unsigned __int8)v289->buffer[0];
      v289 = (va *)((char *)v289 + 1);
    }
    while ( v290 != 0 );
    std::string::assign(this: v288, _Ptr: v287->buffer, _Count: (char *)v289 - (char *)v287 - 1);
    LODWORD(v291) = pExPtrs_[1];
    *(_QWORD *)((char *)&v292 + 4) = *(_QWORD *)(v291 + 216);
    v294 = va::va(
             this: &v1037,
             fmt: *(const char **)(v291 + 216),
             a3: v292,
             a4: v293,
             a5: v291,
             a6: v618,
             a7: v692,
             a8: v766,
             a9: v840,
             a10: v914,
             a11: v988);
    v295 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v296 = v294;
    do
    {
      v297 = (unsigned __int8)v296->buffer[0];
      v296 = (va *)((char *)v296 + 1);
    }
    while ( v297 != 0 );
    std::string::assign(this: v295, _Ptr: v294->buffer, _Count: (char *)v296 - (char *)v294 - 1);
    LODWORD(v298) = pExPtrs_[1];
    *(_QWORD *)((char *)&v299 + 4) = *(_QWORD *)(v298 + 224);
    v301 = va::va(
             this: &v1038,
             fmt: *(const char **)(v298 + 224),
             a3: v299,
             a4: v300,
             a5: v298,
             a6: v619,
             a7: v693,
             a8: v767,
             a9: v841,
             a10: v915,
             a11: v989);
    v302 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v303 = v301;
    do
    {
      v304 = (unsigned __int8)v303->buffer[0];
      v303 = (va *)((char *)v303 + 1);
    }
    while ( v304 != 0 );
    std::string::assign(this: v302, _Ptr: v301->buffer, _Count: (char *)v303 - (char *)v301 - 1);
    LODWORD(v305) = pExPtrs_[1];
    *(_QWORD *)((char *)&v306 + 4) = *(_QWORD *)(v305 + 232);
    v308 = va::va(
             this: &v1037,
             fmt: *(const char **)(v305 + 232),
             a3: v306,
             a4: v307,
             a5: v305,
             a6: v620,
             a7: v694,
             a8: v768,
             a9: v842,
             a10: v916,
             a11: v990);
    v309 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v310 = v308;
    do
    {
      v311 = (unsigned __int8)v310->buffer[0];
      v310 = (va *)((char *)v310 + 1);
    }
    while ( v311 != 0 );
    std::string::assign(this: v309, _Ptr: v308->buffer, _Count: (char *)v310 - (char *)v308 - 1);
    LODWORD(v312) = pExPtrs_[1];
    *(_QWORD *)((char *)&v313 + 4) = *(_QWORD *)(v312 + 240);
    v315 = va::va(
             this: &v1038,
             fmt: *(const char **)(v312 + 240),
             a3: v313,
             a4: v314,
             a5: v312,
             a6: v621,
             a7: v695,
             a8: v769,
             a9: v843,
             a10: v917,
             a11: v991);
    v316 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v317 = v315;
    do
    {
      v318 = (unsigned __int8)v317->buffer[0];
      v317 = (va *)((char *)v317 + 1);
    }
    while ( v318 != 0 );
    std::string::assign(this: v316, _Ptr: v315->buffer, _Count: (char *)v317 - (char *)v315 - 1);
    LODWORD(v319) = pExPtrs_[1];
    *(_QWORD *)((char *)&v320 + 4) = *(_QWORD *)(v319 + 248);
    v322 = va::va(
             this: &v1037,
             fmt: *(const char **)(v319 + 248),
             a3: v320,
             a4: v321,
             a5: v319,
             a6: v622,
             a7: v696,
             a8: v770,
             a9: v844,
             a10: v918,
             a11: v992);
    v323 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v324 = v322;
    do
    {
      v325 = (unsigned __int8)v324->buffer[0];
      v324 = (va *)((char *)v324 + 1);
    }
    while ( v325 != 0 );
    std::string::assign(this: v323, _Ptr: v322->buffer, _Count: (char *)v324 - (char *)v322 - 1);
    LODWORD(v326) = pExPtrs_[1];
    *(_QWORD *)((char *)&v327 + 4) = *(_QWORD *)(v326 + 256);
    v329 = va::va(
             this: &v1038,
             fmt: *(const char **)(v326 + 256),
             a3: v327,
             a4: v328,
             a5: v326,
             a6: v623,
             a7: v697,
             a8: v771,
             a9: v845,
             a10: v919,
             a11: v993);
    v330 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v331 = v329;
    do
    {
      v332 = (unsigned __int8)v331->buffer[0];
      v331 = (va *)((char *)v331 + 1);
    }
    while ( v332 != 0 );
    std::string::assign(this: v330, _Ptr: v329->buffer, _Count: (char *)v331 - (char *)v329 - 1);
    LODWORD(v333) = pExPtrs_[1];
    *(_QWORD *)((char *)&v334 + 4) = *(_QWORD *)(v333 + 264);
    v336 = va::va(
             this: &v1037,
             fmt: *(const char **)(v333 + 264),
             a3: v334,
             a4: v335,
             a5: v333,
             a6: v624,
             a7: v698,
             a8: v772,
             a9: v846,
             a10: v920,
             a11: v994);
    v337 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v338 = v336;
    do
    {
      v339 = (unsigned __int8)v338->buffer[0];
      v338 = (va *)((char *)v338 + 1);
    }
    while ( v339 != 0 );
    std::string::assign(this: v337, _Ptr: v336->buffer, _Count: (char *)v338 - (char *)v336 - 1);
    LODWORD(v340) = pExPtrs_[1];
    *(_QWORD *)((char *)&v341 + 4) = *(_QWORD *)(v340 + 272);
    v343 = va::va(
             this: &v1038,
             fmt: *(const char **)(v340 + 272),
             a3: v341,
             a4: v342,
             a5: v340,
             a6: v625,
             a7: v699,
             a8: v773,
             a9: v847,
             a10: v921,
             a11: v995);
    v344 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->gpr_);
    v345 = v343;
    do
    {
      v346 = (unsigned __int8)v345->buffer[0];
      v345 = (va *)((char *)v345 + 1);
    }
    while ( v346 != 0 );
    std::string::assign(this: v344, _Ptr: v343->buffer, _Count: (char *)v345 - (char *)v343 - 1);
    google::protobuf::internal::RepeatedPtrFieldBase::Clear<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    LODWORD(v347) = pExPtrs_[1];
    HIDWORD(v348) = *(_DWORD *)(v347 + 300);
    v350 = va::va(
             this: &v1037,
             fmt: *(const char **)(v347 + 296),
             a3: v348,
             a4: v349,
             a5: v347,
             a6: v626,
             a7: v700,
             a8: v774,
             a9: v848,
             a10: v922,
             a11: v996);
    v351 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v352 = v350;
    do
    {
      v353 = (unsigned __int8)v352->buffer[0];
      v352 = (va *)((char *)v352 + 1);
    }
    while ( v353 != 0 );
    std::string::assign(this: v351, _Ptr: v350->buffer, _Count: (char *)v352 - (char *)v350 - 1);
    LODWORD(v354) = pExPtrs_[1];
    HIDWORD(v355) = *(_DWORD *)(v354 + 300);
    v357 = va::va(
             this: &v1038,
             fmt: *(const char **)(v354 + 296),
             a3: v355,
             a4: v356,
             a5: v354,
             a6: v627,
             a7: v701,
             a8: v775,
             a9: v849,
             a10: v923,
             a11: v997);
    v358 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v359 = v357;
    do
    {
      v360 = (unsigned __int8)v359->buffer[0];
      v359 = (va *)((char *)v359 + 1);
    }
    while ( v360 != 0 );
    std::string::assign(this: v358, _Ptr: v357->buffer, _Count: (char *)v359 - (char *)v357 - 1);
    LODWORD(v361) = pExPtrs_[1];
    HIDWORD(v362) = *(_DWORD *)(v361 + 300);
    v364 = va::va(
             this: &v1037,
             fmt: *(const char **)(v361 + 296),
             a3: v362,
             a4: v363,
             a5: v361,
             a6: v628,
             a7: v702,
             a8: v776,
             a9: v850,
             a10: v924,
             a11: v998);
    v365 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v366 = v364;
    do
    {
      v367 = (unsigned __int8)v366->buffer[0];
      v366 = (va *)((char *)v366 + 1);
    }
    while ( v367 != 0 );
    std::string::assign(this: v365, _Ptr: v364->buffer, _Count: (char *)v366 - (char *)v364 - 1);
    LODWORD(v368) = pExPtrs_[1];
    HIDWORD(v369) = *(_DWORD *)(v368 + 300);
    v371 = va::va(
             this: &v1038,
             fmt: *(const char **)(v368 + 296),
             a3: v369,
             a4: v370,
             a5: v368,
             a6: v629,
             a7: v703,
             a8: v777,
             a9: v851,
             a10: v925,
             a11: v999);
    v372 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v373 = v371;
    do
    {
      v374 = (unsigned __int8)v373->buffer[0];
      v373 = (va *)((char *)v373 + 1);
    }
    while ( v374 != 0 );
    std::string::assign(this: v372, _Ptr: v371->buffer, _Count: (char *)v373 - (char *)v371 - 1);
    LODWORD(v375) = pExPtrs_[1];
    HIDWORD(v376) = *(_DWORD *)(v375 + 300);
    v378 = va::va(
             this: &v1037,
             fmt: *(const char **)(v375 + 296),
             a3: v376,
             a4: v377,
             a5: v375,
             a6: v630,
             a7: v704,
             a8: v778,
             a9: v852,
             a10: v926,
             a11: v1000);
    v379 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v380 = v378;
    do
    {
      v381 = (unsigned __int8)v380->buffer[0];
      v380 = (va *)((char *)v380 + 1);
    }
    while ( v381 != 0 );
    std::string::assign(this: v379, _Ptr: v378->buffer, _Count: (char *)v380 - (char *)v378 - 1);
    LODWORD(v382) = pExPtrs_[1];
    HIDWORD(v383) = *(_DWORD *)(v382 + 300);
    v385 = va::va(
             this: &v1038,
             fmt: *(const char **)(v382 + 296),
             a3: v383,
             a4: v384,
             a5: v382,
             a6: v631,
             a7: v705,
             a8: v779,
             a9: v853,
             a10: v927,
             a11: v1001);
    v386 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v387 = v385;
    do
    {
      v388 = (unsigned __int8)v387->buffer[0];
      v387 = (va *)((char *)v387 + 1);
    }
    while ( v388 != 0 );
    std::string::assign(this: v386, _Ptr: v385->buffer, _Count: (char *)v387 - (char *)v385 - 1);
    LODWORD(v389) = pExPtrs_[1];
    HIDWORD(v390) = *(_DWORD *)(v389 + 300);
    v392 = va::va(
             this: &v1037,
             fmt: *(const char **)(v389 + 296),
             a3: v390,
             a4: v391,
             a5: v389,
             a6: v632,
             a7: v706,
             a8: v780,
             a9: v854,
             a10: v928,
             a11: v1002);
    v393 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v394 = v392;
    do
    {
      v395 = (unsigned __int8)v394->buffer[0];
      v394 = (va *)((char *)v394 + 1);
    }
    while ( v395 != 0 );
    std::string::assign(this: v393, _Ptr: v392->buffer, _Count: (char *)v394 - (char *)v392 - 1);
    LODWORD(v396) = pExPtrs_[1];
    HIDWORD(v397) = *(_DWORD *)(v396 + 300);
    v399 = va::va(
             this: &v1038,
             fmt: *(const char **)(v396 + 296),
             a3: v397,
             a4: v398,
             a5: v396,
             a6: v633,
             a7: v707,
             a8: v781,
             a9: v855,
             a10: v929,
             a11: v1003);
    v400 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v401 = v399;
    do
    {
      v402 = (unsigned __int8)v401->buffer[0];
      v401 = (va *)((char *)v401 + 1);
    }
    while ( v402 != 0 );
    std::string::assign(this: v400, _Ptr: v399->buffer, _Count: (char *)v401 - (char *)v399 - 1);
    LODWORD(v403) = pExPtrs_[1];
    HIDWORD(v404) = *(_DWORD *)(v403 + 300);
    v406 = va::va(
             this: &v1037,
             fmt: *(const char **)(v403 + 296),
             a3: v404,
             a4: v405,
             a5: v403,
             a6: v634,
             a7: v708,
             a8: v782,
             a9: v856,
             a10: v930,
             a11: v1004);
    v407 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v408 = v406;
    do
    {
      v409 = (unsigned __int8)v408->buffer[0];
      v408 = (va *)((char *)v408 + 1);
    }
    while ( v409 != 0 );
    std::string::assign(this: v407, _Ptr: v406->buffer, _Count: (char *)v408 - (char *)v406 - 1);
    LODWORD(v410) = pExPtrs_[1];
    HIDWORD(v411) = *(_DWORD *)(v410 + 300);
    v413 = va::va(
             this: &v1038,
             fmt: *(const char **)(v410 + 296),
             a3: v411,
             a4: v412,
             a5: v410,
             a6: v635,
             a7: v709,
             a8: v783,
             a9: v857,
             a10: v931,
             a11: v1005);
    v414 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v415 = v413;
    do
    {
      v416 = (unsigned __int8)v415->buffer[0];
      v415 = (va *)((char *)v415 + 1);
    }
    while ( v416 != 0 );
    std::string::assign(this: v414, _Ptr: v413->buffer, _Count: (char *)v415 - (char *)v413 - 1);
    LODWORD(v417) = pExPtrs_[1];
    HIDWORD(v418) = *(_DWORD *)(v417 + 300);
    v420 = va::va(
             this: &v1037,
             fmt: *(const char **)(v417 + 296),
             a3: v418,
             a4: v419,
             a5: v417,
             a6: v636,
             a7: v710,
             a8: v784,
             a9: v858,
             a10: v932,
             a11: v1006);
    v421 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v422 = v420;
    do
    {
      v423 = (unsigned __int8)v422->buffer[0];
      v422 = (va *)((char *)v422 + 1);
    }
    while ( v423 != 0 );
    std::string::assign(this: v421, _Ptr: v420->buffer, _Count: (char *)v422 - (char *)v420 - 1);
    LODWORD(v424) = pExPtrs_[1];
    HIDWORD(v425) = *(_DWORD *)(v424 + 300);
    v427 = va::va(
             this: &v1038,
             fmt: *(const char **)(v424 + 296),
             a3: v425,
             a4: v426,
             a5: v424,
             a6: v637,
             a7: v711,
             a8: v785,
             a9: v859,
             a10: v933,
             a11: v1007);
    v428 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v429 = v427;
    do
    {
      v430 = (unsigned __int8)v429->buffer[0];
      v429 = (va *)((char *)v429 + 1);
    }
    while ( v430 != 0 );
    std::string::assign(this: v428, _Ptr: v427->buffer, _Count: (char *)v429 - (char *)v427 - 1);
    LODWORD(v431) = pExPtrs_[1];
    HIDWORD(v432) = *(_DWORD *)(v431 + 300);
    v434 = va::va(
             this: &v1037,
             fmt: *(const char **)(v431 + 296),
             a3: v432,
             a4: v433,
             a5: v431,
             a6: v638,
             a7: v712,
             a8: v786,
             a9: v860,
             a10: v934,
             a11: v1008);
    v435 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v436 = v434;
    do
    {
      v437 = (unsigned __int8)v436->buffer[0];
      v436 = (va *)((char *)v436 + 1);
    }
    while ( v437 != 0 );
    std::string::assign(this: v435, _Ptr: v434->buffer, _Count: (char *)v436 - (char *)v434 - 1);
    LODWORD(v438) = pExPtrs_[1];
    HIDWORD(v439) = *(_DWORD *)(v438 + 300);
    v441 = va::va(
             this: &v1038,
             fmt: *(const char **)(v438 + 296),
             a3: v439,
             a4: v440,
             a5: v438,
             a6: v639,
             a7: v713,
             a8: v787,
             a9: v861,
             a10: v935,
             a11: v1009);
    v442 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v443 = v441;
    do
    {
      v444 = (unsigned __int8)v443->buffer[0];
      v443 = (va *)((char *)v443 + 1);
    }
    while ( v444 != 0 );
    std::string::assign(this: v442, _Ptr: v441->buffer, _Count: (char *)v443 - (char *)v441 - 1);
    LODWORD(v445) = pExPtrs_[1];
    HIDWORD(v446) = *(_DWORD *)(v445 + 300);
    v448 = va::va(
             this: &v1037,
             fmt: *(const char **)(v445 + 296),
             a3: v446,
             a4: v447,
             a5: v445,
             a6: v640,
             a7: v714,
             a8: v788,
             a9: v862,
             a10: v936,
             a11: v1010);
    v449 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v450 = v448;
    do
    {
      v451 = (unsigned __int8)v450->buffer[0];
      v450 = (va *)((char *)v450 + 1);
    }
    while ( v451 != 0 );
    std::string::assign(this: v449, _Ptr: v448->buffer, _Count: (char *)v450 - (char *)v448 - 1);
    LODWORD(v452) = pExPtrs_[1];
    HIDWORD(v453) = *(_DWORD *)(v452 + 300);
    v455 = va::va(
             this: &v1038,
             fmt: *(const char **)(v452 + 296),
             a3: v453,
             a4: v454,
             a5: v452,
             a6: v641,
             a7: v715,
             a8: v789,
             a9: v863,
             a10: v937,
             a11: v1011);
    v456 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v457 = v455;
    do
    {
      v458 = (unsigned __int8)v457->buffer[0];
      v457 = (va *)((char *)v457 + 1);
    }
    while ( v458 != 0 );
    std::string::assign(this: v456, _Ptr: v455->buffer, _Count: (char *)v457 - (char *)v455 - 1);
    LODWORD(v459) = pExPtrs_[1];
    HIDWORD(v460) = *(_DWORD *)(v459 + 300);
    v462 = va::va(
             this: &v1037,
             fmt: *(const char **)(v459 + 296),
             a3: v460,
             a4: v461,
             a5: v459,
             a6: v642,
             a7: v716,
             a8: v790,
             a9: v864,
             a10: v938,
             a11: v1012);
    v463 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v464 = v462;
    do
    {
      v465 = (unsigned __int8)v464->buffer[0];
      v464 = (va *)((char *)v464 + 1);
    }
    while ( v465 != 0 );
    std::string::assign(this: v463, _Ptr: v462->buffer, _Count: (char *)v464 - (char *)v462 - 1);
    LODWORD(v466) = pExPtrs_[1];
    HIDWORD(v467) = *(_DWORD *)(v466 + 300);
    v469 = va::va(
             this: &v1038,
             fmt: *(const char **)(v466 + 296),
             a3: v467,
             a4: v468,
             a5: v466,
             a6: v643,
             a7: v717,
             a8: v791,
             a9: v865,
             a10: v939,
             a11: v1013);
    v470 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v471 = v469;
    do
    {
      v472 = (unsigned __int8)v471->buffer[0];
      v471 = (va *)((char *)v471 + 1);
    }
    while ( v472 != 0 );
    std::string::assign(this: v470, _Ptr: v469->buffer, _Count: (char *)v471 - (char *)v469 - 1);
    LODWORD(v473) = pExPtrs_[1];
    HIDWORD(v474) = *(_DWORD *)(v473 + 300);
    v476 = va::va(
             this: &v1037,
             fmt: *(const char **)(v473 + 296),
             a3: v474,
             a4: v475,
             a5: v473,
             a6: v644,
             a7: v718,
             a8: v792,
             a9: v866,
             a10: v940,
             a11: v1014);
    v477 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v478 = v476;
    do
    {
      v479 = (unsigned __int8)v478->buffer[0];
      v478 = (va *)((char *)v478 + 1);
    }
    while ( v479 != 0 );
    std::string::assign(this: v477, _Ptr: v476->buffer, _Count: (char *)v478 - (char *)v476 - 1);
    LODWORD(v480) = pExPtrs_[1];
    HIDWORD(v481) = *(_DWORD *)(v480 + 300);
    v483 = va::va(
             this: &v1038,
             fmt: *(const char **)(v480 + 296),
             a3: v481,
             a4: v482,
             a5: v480,
             a6: v645,
             a7: v719,
             a8: v793,
             a9: v867,
             a10: v941,
             a11: v1015);
    v484 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v485 = v483;
    do
    {
      v486 = (unsigned __int8)v485->buffer[0];
      v485 = (va *)((char *)v485 + 1);
    }
    while ( v486 != 0 );
    std::string::assign(this: v484, _Ptr: v483->buffer, _Count: (char *)v485 - (char *)v483 - 1);
    LODWORD(v487) = pExPtrs_[1];
    HIDWORD(v488) = *(_DWORD *)(v487 + 300);
    v490 = va::va(
             this: &v1037,
             fmt: *(const char **)(v487 + 296),
             a3: v488,
             a4: v489,
             a5: v487,
             a6: v646,
             a7: v720,
             a8: v794,
             a9: v868,
             a10: v942,
             a11: v1016);
    v491 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v492 = v490;
    do
    {
      v493 = (unsigned __int8)v492->buffer[0];
      v492 = (va *)((char *)v492 + 1);
    }
    while ( v493 != 0 );
    std::string::assign(this: v491, _Ptr: v490->buffer, _Count: (char *)v492 - (char *)v490 - 1);
    LODWORD(v494) = pExPtrs_[1];
    HIDWORD(v495) = *(_DWORD *)(v494 + 300);
    v497 = va::va(
             this: &v1038,
             fmt: *(const char **)(v494 + 296),
             a3: v495,
             a4: v496,
             a5: v494,
             a6: v647,
             a7: v721,
             a8: v795,
             a9: v869,
             a10: v943,
             a11: v1017);
    v498 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v499 = v497;
    do
    {
      v500 = (unsigned __int8)v499->buffer[0];
      v499 = (va *)((char *)v499 + 1);
    }
    while ( v500 != 0 );
    std::string::assign(this: v498, _Ptr: v497->buffer, _Count: (char *)v499 - (char *)v497 - 1);
    LODWORD(v501) = pExPtrs_[1];
    HIDWORD(v502) = *(_DWORD *)(v501 + 300);
    v504 = va::va(
             this: &v1037,
             fmt: *(const char **)(v501 + 296),
             a3: v502,
             a4: v503,
             a5: v501,
             a6: v648,
             a7: v722,
             a8: v796,
             a9: v870,
             a10: v944,
             a11: v1018);
    v505 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v506 = v504;
    do
    {
      v507 = (unsigned __int8)v506->buffer[0];
      v506 = (va *)((char *)v506 + 1);
    }
    while ( v507 != 0 );
    std::string::assign(this: v505, _Ptr: v504->buffer, _Count: (char *)v506 - (char *)v504 - 1);
    LODWORD(v508) = pExPtrs_[1];
    HIDWORD(v509) = *(_DWORD *)(v508 + 300);
    v511 = va::va(
             this: &v1038,
             fmt: *(const char **)(v508 + 296),
             a3: v509,
             a4: v510,
             a5: v508,
             a6: v649,
             a7: v723,
             a8: v797,
             a9: v871,
             a10: v945,
             a11: v1019);
    v512 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v513 = v511;
    do
    {
      v514 = (unsigned __int8)v513->buffer[0];
      v513 = (va *)((char *)v513 + 1);
    }
    while ( v514 != 0 );
    std::string::assign(this: v512, _Ptr: v511->buffer, _Count: (char *)v513 - (char *)v511 - 1);
    LODWORD(v515) = pExPtrs_[1];
    HIDWORD(v516) = *(_DWORD *)(v515 + 300);
    v518 = va::va(
             this: &v1037,
             fmt: *(const char **)(v515 + 296),
             a3: v516,
             a4: v517,
             a5: v515,
             a6: v650,
             a7: v724,
             a8: v798,
             a9: v872,
             a10: v946,
             a11: v1020);
    v519 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v520 = v518;
    do
    {
      v521 = (unsigned __int8)v520->buffer[0];
      v520 = (va *)((char *)v520 + 1);
    }
    while ( v521 != 0 );
    std::string::assign(this: v519, _Ptr: v518->buffer, _Count: (char *)v520 - (char *)v518 - 1);
    LODWORD(v522) = pExPtrs_[1];
    HIDWORD(v523) = *(_DWORD *)(v522 + 300);
    v525 = va::va(
             this: &v1038,
             fmt: *(const char **)(v522 + 296),
             a3: v523,
             a4: v524,
             a5: v522,
             a6: v651,
             a7: v725,
             a8: v799,
             a9: v873,
             a10: v947,
             a11: v1021);
    v526 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v527 = v525;
    do
    {
      v528 = (unsigned __int8)v527->buffer[0];
      v527 = (va *)((char *)v527 + 1);
    }
    while ( v528 != 0 );
    std::string::assign(this: v526, _Ptr: v525->buffer, _Count: (char *)v527 - (char *)v525 - 1);
    LODWORD(v529) = pExPtrs_[1];
    HIDWORD(v530) = *(_DWORD *)(v529 + 300);
    v532 = va::va(
             this: &v1037,
             fmt: *(const char **)(v529 + 296),
             a3: v530,
             a4: v531,
             a5: v529,
             a6: v652,
             a7: v726,
             a8: v800,
             a9: v874,
             a10: v948,
             a11: v1022);
    v533 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v534 = v532;
    do
    {
      v535 = (unsigned __int8)v534->buffer[0];
      v534 = (va *)((char *)v534 + 1);
    }
    while ( v535 != 0 );
    std::string::assign(this: v533, _Ptr: v532->buffer, _Count: (char *)v534 - (char *)v532 - 1);
    LODWORD(v536) = pExPtrs_[1];
    HIDWORD(v537) = *(_DWORD *)(v536 + 300);
    v539 = va::va(
             this: &v1038,
             fmt: *(const char **)(v536 + 296),
             a3: v537,
             a4: v538,
             a5: v536,
             a6: v653,
             a7: v727,
             a8: v801,
             a9: v875,
             a10: v949,
             a11: v1023);
    v540 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v541 = v539;
    do
    {
      v542 = (unsigned __int8)v541->buffer[0];
      v541 = (va *)((char *)v541 + 1);
    }
    while ( v542 != 0 );
    std::string::assign(this: v540, _Ptr: v539->buffer, _Count: (char *)v541 - (char *)v539 - 1);
    LODWORD(v543) = pExPtrs_[1];
    HIDWORD(v544) = *(_DWORD *)(v543 + 300);
    v546 = va::va(
             this: &v1037,
             fmt: *(const char **)(v543 + 296),
             a3: v544,
             a4: v545,
             a5: v543,
             a6: v654,
             a7: v728,
             a8: v802,
             a9: v876,
             a10: v950,
             a11: v1024);
    v547 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v548 = v546;
    do
    {
      v549 = (unsigned __int8)v548->buffer[0];
      v548 = (va *)((char *)v548 + 1);
    }
    while ( v549 != 0 );
    std::string::assign(this: v547, _Ptr: v546->buffer, _Count: (char *)v548 - (char *)v546 - 1);
    LODWORD(v550) = pExPtrs_[1];
    HIDWORD(v551) = *(_DWORD *)(v550 + 300);
    v553 = va::va(
             this: &v1038,
             fmt: *(const char **)(v550 + 296),
             a3: v551,
             a4: v552,
             a5: v550,
             a6: v655,
             a7: v729,
             a8: v803,
             a9: v877,
             a10: v951,
             a11: v1025);
    v554 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v555 = v553;
    do
    {
      v556 = (unsigned __int8)v555->buffer[0];
      v555 = (va *)((char *)v555 + 1);
    }
    while ( v556 != 0 );
    std::string::assign(this: v554, _Ptr: v553->buffer, _Count: (char *)v555 - (char *)v553 - 1);
    LODWORD(v557) = pExPtrs_[1];
    HIDWORD(v558) = *(_DWORD *)(v557 + 300);
    v560 = va::va(
             this: &v1037,
             fmt: *(const char **)(v557 + 296),
             a3: v558,
             a4: v559,
             a5: v557,
             a6: v656,
             a7: v730,
             a8: v804,
             a9: v878,
             a10: v952,
             a11: v1026);
    v561 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v562 = v560;
    do
    {
      v563 = (unsigned __int8)v562->buffer[0];
      v562 = (va *)((char *)v562 + 1);
    }
    while ( v563 != 0 );
    std::string::assign(this: v561, _Ptr: v560->buffer, _Count: (char *)v562 - (char *)v560 - 1);
    LODWORD(v564) = pExPtrs_[1];
    HIDWORD(v565) = *(_DWORD *)(v564 + 300);
    v567 = va::va(
             this: &v1038,
             fmt: *(const char **)(v564 + 296),
             a3: v565,
             a4: v566,
             a5: v564,
             a6: v657,
             a7: v731,
             a8: v805,
             a9: v879,
             a10: v953,
             a11: v1027);
    v568 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v91->fpr_);
    v569 = v567;
    do
    {
      v570 = (unsigned __int8)v569->buffer[0];
      v569 = (va *)((char *)v569 + 1);
    }
    while ( v570 != 0 );
    std::string::assign(this: v568, _Ptr: v567->buffer, _Count: (char *)v569 - (char *)v567 - 1);
    idStr::FreeData(this: &v1029);
  }
  google::protobuf::internal::RepeatedPtrFieldBase::Clear<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v1035.callstack_);
  DmCaptureStackBackTrace(FramesToCapture: 0x64u, BackTrace: v1039);
  v574 = 0;
  v575 = v1039;
  do
  {
    if ( *v575 == nullptr )
      break;
    HIDWORD(v573) = *v575;
    v576 = va::va(
             this: &v1038,
             fmt: "0x%p",
             a3: v573,
             a4: v572,
             a5: v571,
             a6: v584,
             a7: v658,
             a8: v732,
             a9: v806,
             a10: v880,
             a11: v954);
    v577 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this: &v1035.callstack_);
    v578 = v576;
    do
    {
      v579 = (unsigned __int8)v578->buffer[0];
      v578 = (va *)((char *)v578 + 1);
    }
    while ( v579 != 0 );
    std::string::assign(this: v577, _Ptr: v576->buffer, _Count: (char *)v578 - (char *)v576 - 1);
    ++v574;
    ++v575;
  }
  while ( v574 < 100 );
  v580 = idreports::Xbox360CrashReport::ByteSize(this: &v1035);
  v581 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
           size: v580,
           tag: TAG_NEW,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
  v582 = idreports::Xbox360CrashReport::ByteSize(this: &v1035);
  google::protobuf::MessageLite::SerializeToArray(this: &v1035, data: v581, size: v582);
  v583 = idreports::Xbox360CrashReport::ByteSize(this: &v1035);
  idHansoftReport::SendReport(this, report: (char *)v581, byteSize: v583, targetPlatform: "xbox360");
  idreports::Xbox360CrashReport::~Xbox360CrashReport(this: &v1035);
  idStr::FreeData(this: &v1034);
}


// ========================================================================
// __unwind$267090
// EA  : 0x828984F8
// RVA : 0x008984F8
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_267090()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 208));
}


// ========================================================================
// __unwind$267091
// EA  : 0x82898520
// RVA : 0x00898520
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_267091()
{
  int v0; // r12

  idreports::Xbox360CrashReport::~Xbox360CrashReport(this: (idreports::Xbox360CrashReport *)(v0 - 9072 + 240));
}


// ========================================================================
// __unwind$267092
// EA  : 0x82898548
// RVA : 0x00898548
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void _unwind_267092()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 80));
}


// ========================================================================
// `dynamic initializer for 'hansoft_email''
// EA  : 0x833456C8
// RVA : 0x013456C8
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hansoft_email__()
{
  idCVar::idCVar(
    this: &hansoft_email,
    name: "hansoft_email",
    value: "hansoftbug",
    flags: 0,
    description: "Mailbox to use for sending hansoft reports (for debugging purposes)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hansoft_email__);
}


// ========================================================================
// `dynamic initializer for 'hansoftReport''
// EA  : 0x83345720
// RVA : 0x01345720
// PDB : w:\tech5\engine\network\hansoftreport.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hansoftReport__()
{
  hansoftReport.attachFileName.allocedAndFlag = 20;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hansoftReport__);
}

