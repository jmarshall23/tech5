
// ========================================================================
// ?AddRef@idSerializerLog@@QAAXXZ
// EA  : 0x8289FD68
// RVA : 0x0089FD68
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall idSerializerLog::AddRef(idSerializerLog *this)
{
  ++this->refCount;
}


// ========================================================================
// ?ProcessEvent@idSnapshotMetrics@@QAAXPBUsysEvent_t@@@Z
// EA  : 0x8289FD78
// RVA : 0x0089FD78
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall idSnapshotMetrics::ProcessEvent(idSnapshotMetrics *this, const sysEvent_t *ev)
{
  int evValue; // r11
  int v5; // r11

  if ( ev != nullptr && ev->evType == SE_KEY && ev->evValue2 != 0 && this->nextKeyEvent < Sys_Milliseconds() )
  {
    evValue = ev->evValue;
    if ( evValue == 201 )
    {
      v5 = this->guiOffset - 1;
    }
    else
    {
      if ( evValue != 209 )
        return;
      v5 = this->guiOffset + 1;
    }
    this->guiOffset = v5;
    this->nextKeyEvent = Sys_Milliseconds() + 100;
  }
}


// ========================================================================
// ?net_snapshot_metrics_print_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8289FE18
// RVA : 0x0089FE18
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall net_snapshot_metrics_print_f(const idCmdArgs *args)
{
  snapshotMetrics.printNextReport = true;
}


// ========================================================================
// ?ShouldShowEntry@idSnapshotMetrics@@AAA_NPAVidSerializerLog@@ABUlogEntry_t@2@@Z
// EA  : 0x8289FE30
// RVA : 0x0089FE30
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

int __fastcall idSnapshotMetrics::ShouldShowEntry(
        idSnapshotMetrics *this,
        idSerializerLog *log,
        const idSerializerLog::logEntry_t *entry)
{
  char v6; // r25
  char v7; // r27
  int v8; // r28
  int v9; // r30
  int v10; // r28
  int v11; // r30
  int v12; // r28
  int i; // r30
  idSerializerLog::logEntry_t *v14; // r5

  v6 = 0;
  if ( this->watchList.num > 0 )
  {
    v7 = 0;
    v8 = 0;
    v9 = 0;
    while ( idStr::Find(
              searchIn: this->ignoreList.list[v9].data,
              searchFor: entry->typeName.data,
              casesensitive: false,
              start: 0,
              end: this->ignoreList.list[v9].len) == -1
         && idStr::Find(
              searchIn: this->ignoreList.list[v9].data,
              searchFor: entry->instanceName.data,
              casesensitive: false,
              start: 0,
              end: this->ignoreList.list[v9].len) == -1 )
    {
      ++v8;
      ++v9;
      if ( v8 >= this->watchList.num )
        goto LABEL_8;
    }
    v7 = 1;
LABEL_8:
    if ( v7 == 0 )
      v6 = 1;
  }
  v10 = 0;
  if ( this->ignoreList.num > 0 )
  {
    v11 = 0;
    do
    {
      if ( idStr::Find(
             searchIn: this->ignoreList.list[v11].data,
             searchFor: entry->typeName.data,
             casesensitive: false,
             start: 0,
             end: this->ignoreList.list[v11].len) != -1
        || idStr::Find(
             searchIn: this->ignoreList.list[v11].data,
             searchFor: entry->instanceName.data,
             casesensitive: false,
             start: 0,
             end: this->ignoreList.list[v11].len) != -1 )
      {
        v6 = 1;
      }
      ++v10;
      ++v11;
    }
    while ( v10 < this->ignoreList.num );
  }
  if ( v6 != 0 && log != nullptr )
  {
    v12 = 0;
    if ( log->logEntries.num <= 0 )
      return 0;
    for ( i = 0; ; ++i )
    {
      v14 = &log->logEntries.list[i];
      if ( v14->parentObjID == entry->objID && idSnapshotMetrics::ShouldShowEntry(this, log, entry: v14) )
        break;
      if ( ++v12 >= log->logEntries.num )
        return 0;
    }
  }
  return 1;
}


// ========================================================================
// ?SerializeEntry@idSnapshotMetricRecord@idSnapshotMetrics@@UBAXPAVidMetricFile@@@Z
// EA  : 0x828A01A8
// RVA : 0x008A01A8
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall idSnapshotMetrics::idSnapshotMetricRecord::SerializeEntry(
        idSnapshotMetrics::idSnapshotMetricRecord *this,
        idMetricFile *metricFile)
{
  unsigned __int64 v4; // r11
  char *data; // r4
  idBitMsg v6; // [sp+50h] [-1450h] BYREF
  _BYTE v7[1056]; // [sp+80h] [-1420h] BYREF

  if ( metricFile->fileHandle != nullptr )
  {
    idMetricRecord::SerializeEntry(this, metricFile);
    LODWORD(v4) = 0;
    HIDWORD(v4) = v7;
    data = this->text.data;
    memset(&v6.curSize, 0, 18);
    v6.writeData = v7;
    v6.readData = v7;
    v6.maxSize = 5120;
    v6.tempValue = v4;
    idBitMsg::WriteString(this: &v6, s: data, maxLength: -1, make7Bit: true);
    metricFile->fileHandle->Write(this: metricFile->fileHandle, a2: v6.writeData, a3: (v6.writeBit != 0) + v6.curSize);
  }
}


// ========================================================================
// ?WriteHeader@idSnapshotMetricRecord@idSnapshotMetrics@@UBAXPAVidMetricFile@@@Z
// EA  : 0x828A0268
// RVA : 0x008A0268
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall idSnapshotMetrics::idSnapshotMetricRecord::WriteHeader(
        idSnapshotMetrics::idSnapshotMetricRecord *this,
        idMetricFile *metricFile)
{
  unsigned __int64 v3; // r11
  idBitMsg v4; // [sp+50h] [-C0h] BYREF
  _BYTE v5[128]; // [sp+80h] [-90h] BYREF

  if ( metricFile->fileHandle != nullptr )
  {
    idMetricRecord::WriteHeader(this, metricFile);
    LODWORD(v3) = 0;
    HIDWORD(v3) = v5;
    memset(&v4.curSize, 0, 18);
    v4.writeData = v5;
    v4.readData = v5;
    v4.maxSize = 128;
    v4.tempValue = v3;
    idBitMsg::WriteBits(this: &v4, value: 1, numBits: 32);
    idBitMsg::WriteString(this: &v4, s: "SnapshotReport", maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v4, value: 6, numBits: 32);
    metricFile->fileHandle->Write(this: metricFile->fileHandle, a2: v4.writeData, a3: (v4.writeBit != 0) + v4.curSize);
  }
}


// ========================================================================
// ?NewLine@idSnapshotMetrics@@AAAX_NPAVidRenderModelGui@@PAVidStr@@@Z
// EA  : 0x828A0340
// RVA : 0x008A0340
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall idSnapshotMetrics::NewLine(idSnapshotMetrics *this, bool print, idRenderModelGui *gui, idStr *outStr)
{
  int v5; // r11

  if ( gui != nullptr )
  {
    v5 = this->height + 1;
    this->curY = this->SNAPSHOTS_Y_SPACING + this->curY;
    this->height = v5;
  }
  if ( print )
    idLib::Printf(fmt: "\n");
  if ( outStr != nullptr )
    idStr::Append(this: outStr, text: "\n");
}


// ========================================================================
// ?net_snapshot_metrics_clear_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828A03C8
// RVA : 0x008A03C8
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall net_snapshot_metrics_clear_f(const idCmdArgs *args)
{
  if ( snapshotMetrics.ignoreList.listStatic == 0 || snapshotMetrics.ignoreList.listStatic == 2 )
  {
    if ( snapshotMetrics.ignoreList.list != nullptr )
      idListArrayDelete<idStr>(ptr: snapshotMetrics.ignoreList.list, num: snapshotMetrics.ignoreList.size);
    snapshotMetrics.ignoreList.list = nullptr;
    snapshotMetrics.ignoreList.size = 0;
  }
  snapshotMetrics.ignoreList.num = 0;
  if ( snapshotMetrics.watchList.listStatic != 0 && snapshotMetrics.watchList.listStatic != 2 )
  {
    snapshotMetrics.watchList.num = 0;
  }
  else
  {
    if ( snapshotMetrics.watchList.list != nullptr )
      idListArrayDelete<idStr>(ptr: snapshotMetrics.watchList.list, num: snapshotMetrics.watchList.size);
    snapshotMetrics.watchList.list = nullptr;
    snapshotMetrics.watchList.size = 0;
    snapshotMetrics.watchList.num = 0;
  }
}


// ========================================================================
// ?OutputLine@idSnapshotMetrics@@AAAHPBD_NVidColor@@PAVidRenderModelGui@@PAVidStr@@@Z
// EA  : 0x828A0550
// RVA : 0x008A0550
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idSnapshotMetrics::OutputLine(
        idSnapshotMetrics *this,
        char *str,
        bool print,
        __int64 gui,
        idRenderModelGui *outStr,
        idStr *a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14)
{
  int v19; // r28
  int StringWidth; // r3
  __int128 v21; // r9
  __int64 v22; // fp10
  const idVec4 *v23; // r5
  const char *v24; // r4

  a13 = *(__int64 *)((char *)&gui + 4);
  a14 = gui;
  v19 = 0;
  if ( outStr != nullptr )
  {
    StringWidth = idRenderModelGui::GetStringWidth(this: outStr, string: str, scale: this->SNAPSHOTS_DRAW_SCALE);
    LODWORD(v21) = (int)this->curY;
    v22 = v21;
    DWORD2(v21) = (int)this->SNAPSHOTS_X_OFFSET;
    v19 = StringWidth;
    idRenderModelGui::DrawString(
      this: outStr,
      x: (float)*(__int64 *)((char *)&v21 + 4),
      y: (float)v22,
      string: v24,
      defaultColor: v23,
      forceColor: (unsigned __int8 *)str,
      scale: this->SNAPSHOTS_DRAW_SCALE,
      a8: (const idVec4 *)&a13,
      a9: 0);
  }
  if ( a6 != nullptr )
    idStr::Append(this: a6, text: str);
  if ( print )
    idLib::Printf(fmt: str);
  idSnapshotMetrics::NewLine(this, print, gui: outStr, outStr: a6);
  return v19;
}


// ========================================================================
// ?GenerateReport@idSnapshotMetrics@@QAAXAAVidSnapShot@@PBV2@HHHPAVidRenderModelGui@@_N3@Z
// EA  : 0x828A0648
// RVA : 0x008A0648
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSnapshotMetrics::GenerateReport(
        idSnapshotMetrics *this,
        idSnapShot *ss,
        idSnapShot *oldss,
        int seq,
        unsigned int baseSeq,
        int peer,
        idRenderModelGui *gui,
        bool reportMetrics,
        bool printConsole,
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
        char a28)
{
  idSnapShot *v29; // r26
  idSnapShot *v30; // r25
  int v31; // r15
  idSerializerLog *serializeLog; // r11
  idSerializerLog *v35; // r23
  char v36; // r11
  bool v37; // r21
  double SNAPSHOTS_Y_OFFSET; // fp12
  __int64 v39; // r10
  __int64 v40; // r6
  BOOL v41; // r14
  __int64 v42; // r8
  double v43; // fp10
  idRenderModelGui *v44; // r20
  va *v45; // r3
  idStr *v46; // r10
  __int64 v47; // r4 OVERLAPPED
  double SNAPSHOTS_Y_SPACING; // fp12
  double curY; // fp11
  double SNAPSHOTS_X_OFFSET; // fp10
  int v51; // r5
  idColor *v52; // r27
  char *v53; // r29
  int num; // r10
  int v55; // r17
  int guiOffset; // r11
  int v57; // r19
  int v58; // r10
  int v59; // r10
  int v60; // r18
  char *v61; // r28
  int v62; // r27
  const idSerializerLog::logEntry_t *v63; // r30
  int parent; // r11
  __int64 v65; // r10
  __int64 v66; // r8
  char *v67; // r4
  int v68; // r3
  int v69; // r11
  int j; // r29
  __int64 v71; // r6
  va *v72; // r3
  __int64 v73; // r10
  __int64 v74; // r8
  __int64 v75; // r6
  va *v76; // r3
  int objID; // r8
  __int64 v78; // r29
  int v79; // r10
  idSerializerLog::compressionEntry_t *list; // r9
  int v81; // r11
  __int64 v82; // r10
  __int64 v83; // r8
  int v84; // r5
  int v85; // r4
  va *v86; // r3
  int parentObjID; // r4
  idSerializerLog *v88; // r28
  int v89; // r29
  __int64 v90; // r10
  __int64 v91; // r8
  int end; // r5
  int start; // r4
  __int64 v94; // r8
  unsigned int v95; // r3
  __int64 v96; // r10
  __int64 v97; // r6
  va *v98; // r3
  int v99; // r6
  __int64 v100; // r6
  va *v101; // r3
  __int64 v102; // r6
  va *v103; // r3
  __int64 v104; // r10
  __int64 v105; // r6
  va *v106; // r3
  char *v107; // r8
  int v108; // r7
  int v109; // r6
  __int64 v110; // r6
  __int64 v111; // r8
  int v112; // r3
  int width; // r11
  int v114; // r11
  int v115; // r28
  idStr *v116; // r10
  int v117; // r11
  idSerializerLog::compressionEntry_t *v118; // r9
  __int64 v119; // r10
  __int64 v120; // r8
  __int64 v121; // r6
  __int64 v122; // r8
  char *v123; // r6
  int v124; // r30
  unsigned int v125; // r11
  unsigned int v126; // r30
  int v127; // r28
  va *v128; // r3
  idStr *v129; // r10
  __int64 v130; // r10
  __int64 v131; // r6
  __int64 v132; // r8
  va *v133; // r3
  idStr *v134; // r10
  __int64 v135; // r10
  __int64 v136; // r6
  __int64 v137; // r8
  va *v138; // r3
  idStr *v139; // r10
  __int64 v140; // r6
  __int64 v141; // r8
  __int64 v142; // r10
  va *v143; // r3
  __int128 v144; // r8
  idStr *v145; // r10
  __int64 v146; // r6
  __int64 v147; // r8
  va *v148; // r3
  __int128 v149; // r8
  idStr *v150; // r10
  __int64 v151; // r6
  __int64 v152; // r10
  __int64 v153; // r8
  va *v154; // r3
  __int128 v155; // r8
  idStr *v156; // r10
  int v157; // r3
  __int64 v158; // r10
  __int64 v159; // r6
  __int64 v160; // r8
  va *v161; // r3
  __int128 v162; // r8
  idStr *v163; // r10
  int v164; // [sp+8h] [-2258h]
  int v165; // [sp+8h] [-2258h]
  int v166; // [sp+8h] [-2258h]
  int v167; // [sp+8h] [-2258h]
  int v168; // [sp+8h] [-2258h]
  int v169; // [sp+8h] [-2258h]
  int v170; // [sp+8h] [-2258h]
  int v171; // [sp+8h] [-2258h]
  int v172; // [sp+8h] [-2258h]
  int v173; // [sp+8h] [-2258h]
  int v174; // [sp+8h] [-2258h]
  int v175; // [sp+8h] [-2258h]
  int v176; // [sp+8h] [-2258h]
  int v177; // [sp+8h] [-2258h]
  int v178; // [sp+8h] [-2258h]
  int v179; // [sp+8h] [-2258h]
  int v180; // [sp+8h] [-2258h]
  int v181; // [sp+8h] [-2258h]
  int v182; // [sp+8h] [-2258h]
  int v183; // [sp+Ch] [-2254h]
  int v184; // [sp+Ch] [-2254h]
  int v185; // [sp+Ch] [-2254h]
  int v186; // [sp+Ch] [-2254h]
  int v187; // [sp+Ch] [-2254h]
  int v188; // [sp+Ch] [-2254h]
  int v189; // [sp+Ch] [-2254h]
  int v190; // [sp+Ch] [-2254h]
  int v191; // [sp+Ch] [-2254h]
  int v192; // [sp+Ch] [-2254h]
  int v193; // [sp+10h] [-2250h]
  __int64 v194; // [sp+10h] [-2250h]
  __int64 v195; // [sp+10h] [-2250h]
  __int64 v196; // [sp+10h] [-2250h]
  int v197; // [sp+10h] [-2250h]
  __int64 v198; // [sp+10h] [-2250h]
  __int64 v199; // [sp+10h] [-2250h]
  int v200; // [sp+10h] [-2250h]
  __int64 v201; // [sp+10h] [-2250h]
  int v202; // [sp+10h] [-2250h]
  __int64 v203; // [sp+10h] [-2250h]
  int v204; // [sp+10h] [-2250h]
  __int64 v205; // [sp+10h] [-2250h]
  int v206; // [sp+10h] [-2250h]
  __int64 v207; // [sp+10h] [-2250h]
  int v208; // [sp+10h] [-2250h]
  __int64 v209; // [sp+10h] [-2250h]
  int v210; // [sp+10h] [-2250h]
  __int64 v211; // [sp+10h] [-2250h]
  int v212; // [sp+14h] [-224Ch]
  int v213; // [sp+14h] [-224Ch]
  int v214; // [sp+14h] [-224Ch]
  int v215; // [sp+14h] [-224Ch]
  int v216; // [sp+14h] [-224Ch]
  int v217; // [sp+14h] [-224Ch]
  int v218; // [sp+14h] [-224Ch]
  int v219; // [sp+14h] [-224Ch]
  int v220; // [sp+18h] [-2248h]
  __int64 v221; // [sp+18h] [-2248h]
  __int64 v222; // [sp+18h] [-2248h]
  __int64 v223; // [sp+18h] [-2248h]
  int v224; // [sp+18h] [-2248h]
  __int64 v225; // [sp+18h] [-2248h]
  __int64 v226; // [sp+18h] [-2248h]
  int v227; // [sp+18h] [-2248h]
  __int64 v228; // [sp+18h] [-2248h]
  int v229; // [sp+18h] [-2248h]
  __int64 v230; // [sp+18h] [-2248h]
  int v231; // [sp+18h] [-2248h]
  __int64 v232; // [sp+18h] [-2248h]
  int v233; // [sp+18h] [-2248h]
  __int64 v234; // [sp+18h] [-2248h]
  int v235; // [sp+18h] [-2248h]
  __int64 v236; // [sp+18h] [-2248h]
  int v237; // [sp+18h] [-2248h]
  __int64 v238; // [sp+18h] [-2248h]
  int v239; // [sp+1Ch] [-2244h]
  int v240; // [sp+1Ch] [-2244h]
  int v241; // [sp+1Ch] [-2244h]
  int v242; // [sp+1Ch] [-2244h]
  int v243; // [sp+1Ch] [-2244h]
  int v244; // [sp+1Ch] [-2244h]
  int v245; // [sp+1Ch] [-2244h]
  int v246; // [sp+1Ch] [-2244h]
  __int64 v247; // [sp+20h] [-2240h]
  __int64 v248; // [sp+20h] [-2240h]
  __int64 v249; // [sp+20h] [-2240h]
  __int64 v250; // [sp+20h] [-2240h]
  __int64 v251; // [sp+20h] [-2240h]
  __int64 v252; // [sp+20h] [-2240h]
  __int64 v253; // [sp+20h] [-2240h]
  __int64 v254; // [sp+20h] [-2240h]
  __int64 v255; // [sp+20h] [-2240h]
  __int64 v256; // [sp+20h] [-2240h]
  __int64 v257; // [sp+28h] [-2238h]
  __int64 v258; // [sp+28h] [-2238h]
  __int64 v259; // [sp+28h] [-2238h]
  __int64 v260; // [sp+28h] [-2238h]
  __int64 v261; // [sp+28h] [-2238h]
  __int64 v262; // [sp+28h] [-2238h]
  __int64 v263; // [sp+28h] [-2238h]
  __int64 v264; // [sp+28h] [-2238h]
  __int64 v265; // [sp+28h] [-2238h]
  __int64 v266; // [sp+28h] [-2238h]
  __int64 v267; // [sp+30h] [-2230h]
  __int64 v268; // [sp+30h] [-2230h]
  __int64 v269; // [sp+30h] [-2230h]
  __int64 v270; // [sp+30h] [-2230h]
  __int64 v271; // [sp+30h] [-2230h]
  __int64 v272; // [sp+30h] [-2230h]
  __int64 v273; // [sp+30h] [-2230h]
  __int64 v274; // [sp+30h] [-2230h]
  __int64 v275; // [sp+30h] [-2230h]
  __int64 v276; // [sp+30h] [-2230h]
  __int64 v277; // [sp+38h] [-2228h]
  __int64 v278; // [sp+38h] [-2228h]
  __int64 v279; // [sp+38h] [-2228h]
  __int64 v280; // [sp+38h] [-2228h]
  __int64 v281; // [sp+38h] [-2228h]
  __int64 v282; // [sp+38h] [-2228h]
  __int64 v283; // [sp+38h] [-2228h]
  __int64 v284; // [sp+38h] [-2228h]
  __int64 v285; // [sp+38h] [-2228h]
  __int64 v286; // [sp+38h] [-2228h]
  __int64 v287; // [sp+40h] [-2220h]
  __int64 v288; // [sp+40h] [-2220h]
  __int64 v289; // [sp+40h] [-2220h]
  __int64 v290; // [sp+40h] [-2220h]
  __int64 v291; // [sp+40h] [-2220h]
  __int64 v292; // [sp+40h] [-2220h]
  __int64 v293; // [sp+40h] [-2220h]
  __int64 v294; // [sp+40h] [-2220h]
  __int64 v295; // [sp+40h] [-2220h]
  __int64 v296; // [sp+40h] [-2220h]
  char v297; // [sp+50h] [-2210h]
  int len; // [sp+54h] [-220Ch]
  idStr v299; // [sp+60h] [-2200h] BYREF
  idStr v300; // [sp+80h] [-21E0h] BYREF
  const char *v301; // [sp+A0h] [-21C0h]
  const char *v302; // [sp+A4h] [-21BCh]
  idColor *v303; // [sp+A8h] [-21B8h]
  const char *v304; // [sp+ACh] [-21B4h]
  const char *v305; // [sp+B0h] [-21B0h]
  const char *v306; // [sp+B4h] [-21ACh]
  const char *v307; // [sp+B8h] [-21A8h]
  const char *i; // [sp+BCh] [-21A4h]
  int *v309; // [sp+C0h] [-21A0h]
  const char *v310; // [sp+C4h] [-219Ch]
  idCVar *v311; // [sp+C8h] [-2198h]
  const char *v312; // [sp+CCh] [-2194h]
  idSerializerLog *v313; // [sp+D0h] [-2190h]
  const char *v314; // [sp+D4h] [-218Ch]
  BOOL v315; // [sp+D8h] [-2188h]
  const char *v316; // [sp+DCh] [-2184h]
  idStr v317; // [sp+E0h] [-2180h] BYREF
  idStr v318; // [sp+100h] [-2160h] BYREF
  idVec4 v319; // [sp+120h] [-2140h] BYREF
  idStr v320; // [sp+130h] [-2130h] BYREF
  idSnapshotMetrics::idSnapshotMetricRecord v321; // [sp+150h] [-2110h] BYREF
  va v322; // [sp+1C0h] [-20A0h] BYREF
  va v323; // [sp+11C0h] [-10A0h] BYREF

  v29 = ss;
  v30 = oldss;
  v31 = seq;
  if ( oldss != nullptr )
  {
    serializeLog = oldss->serializeLog;
    v35 = ss->serializeLog;
    v313 = serializeLog;
    if ( v35 != nullptr && serializeLog != nullptr )
    {
      this->lastReportMS = Sys_Milliseconds();
      if ( a28 != 0 || (v36 = 0, this->printNextReport) )
        v36 = 1;
      this->printNextReport = false;
      v37 = v36;
      idSnapshotMetrics::idSnapshotMetricRecord::idSnapshotMetricRecord(this: &v321);
      SNAPSHOTS_Y_OFFSET = this->SNAPSHOTS_Y_OFFSET;
      HIDWORD(v39) = &net_snapshot_gui_scale;
      HIDWORD(v40) = this->nameLen;
      v41 = reportMetrics;
      LODWORD(v42) = &unk_821F0000;
      HIDWORD(v42) = -reportMetrics;
      v315 = reportMetrics;
      v43 = (float)(net_snapshot_gui_scale.valueFloat * (float)15.0);
      this->SNAPSHOTS_DRAW_SCALE = net_snapshot_gui_scale.valueFloat;
      this->SNAPSHOTS_Y_SPACING = v43;
      LODWORD(v39) = &v321.text;
      this->curY = SNAPSHOTS_Y_OFFSET;
      LODWORD(v40) = "Object";
      v44 = !reportMetrics ? nullptr : (idRenderModelGui *)&v321.text;
      v45 = va::va(
              this: &v323,
              fmt: "%-*s | obj sz| delta | compr | ",
              a3: v40,
              a4: v42,
              a5: v39,
              a6: v164,
              a7: v183,
              a8: v193,
              a9: v212,
              a10: v220,
              a11: v239);
      HIDWORD(v47) = idStr::idStr(this: &v320, text: v45);
      if ( gui != nullptr )
      {
        SNAPSHOTS_Y_SPACING = this->SNAPSHOTS_Y_SPACING;
        curY = this->curY;
        SNAPSHOTS_X_OFFSET = this->SNAPSHOTS_X_OFFSET;
        v51 = this->height + 6;
        LODWORD(v47) = this->width + 20;
        v319.x = 0.0;
        v319.y = 0.0;
        v319.z = 0.0;
        v319.w = 0.85000002;
        idRenderModelGui::DrawFilled(
          this: gui,
          color: &v319,
          x: (float)((float)SNAPSHOTS_X_OFFSET - (float)10.0),
          y: (float)((float)curY - (float)10.0),
          w: (float)v47,
          h: (float)((float)((float)*(__int64 *)((char *)&v47 - 4) * (float)SNAPSHOTS_Y_SPACING) + (float)20.0));
        this->width = 0;
        this->height = 0;
      }
      v52 = &idColor::colorWhite;
      v303 = &idColor::colorWhite;
      idSnapshotMetrics::OutputLine(
        this,
        str: v320.data,
        print: SLOBYTE(idColor::colorWhite.r),
        gui: __SPAIR64__(LODWORD(idColor::colorWhite.a), (unsigned int)gui),
        outStr: v44,
        a6: v46,
        a7: v165,
        a8: v194,
        a9: v221,
        a10: v247,
        a11: v257,
        a12: v267,
        a13: v277,
        a14: v287);
      v53 = "---------------------------------------------------------------------------";
      v302 = "---------------------------------------------------------------------------";
      idSnapshotMetrics::OutputLine(
        this,
        str: "---------------------------------------------------------------------------",
        print: SLOBYTE(idColor::colorMdGrey.r),
        gui: __SPAIR64__(LODWORD(idColor::colorMdGrey.a), (unsigned int)gui),
        outStr: v44,
        a6: (idStr *)&idColor::colorMdGrey,
        a7: v166,
        a8: v195,
        a9: v222,
        a10: v248,
        a11: v258,
        a12: v268,
        a13: v278,
        a14: v288);
      num = v35->logEntries.num;
      v35->finalUncompressedSize = 0;
      v55 = 0;
      guiOffset = this->guiOffset;
      v57 = 0;
      len = 0;
      v58 = num - 1;
      v297 = 0;
      if ( guiOffset >= 1 )
      {
        if ( guiOffset > v58 )
          guiOffset = v58;
      }
      else
      {
        guiOffset = 1;
      }
      this->guiOffset = guiOffset;
      v59 = v35->logEntries.num;
      v60 = 1;
      *(_DWORD *)&v299.baseBuffer[16] = &idColor::colorRed;
      *(_DWORD *)&v299.baseBuffer[4] = &idColor::colorGreen;
      if ( v59 > 1 )
      {
        *(_DWORD *)&v299.baseBuffer[12] = 92;
        *(_DWORD *)&v299.baseBuffer[8] = "NEW";
        v311 = &net_snapshot_metrics_skipZero;
        v314 = "%5d |       | %s";
        v312 = "%5d / %5d | %s";
        v301 = "SIZE CHANGE (%d != %d) ";
        v310 = "END WRITEBIT (%d != %d) ";
        v306 = "START WRITEBIT (%d != %d) ";
        v309 = (int *)&idColor::colorCyan;
        v304 = "START OFF (%d != %d) ";
        v316 = "%5d | %5d | %s";
        v61 = "   ";
        v307 = "%-*s | %5d | ";
        v305 = "%s: %s";
        for ( i = "   "; ; v61 = (char *)i )
        {
          v62 = *(_DWORD *)&v299.baseBuffer[12];
          v63 = (idSerializerLog::logEntry_t *)((char *)v35->logEntries.list + *(_DWORD *)&v299.baseBuffer[12]);
          parent = v63->parent;
          if ( parent <= v57 )
          {
            for ( ; parent < v57; v57 = v35->logEntries.list[v57].parent )
              --v55;
          }
          else
          {
            ++v55;
          }
          v57 = v63->parent;
          if ( v60 > 0 && v55 == 0 && v297 != 0 )
          {
            idSnapshotMetrics::NewLine(
              this,
              print: v37,
              gui: __CFADD__(v60 - this->guiOffset, this->guiOffset ^ 0x80000000) ? nullptr : gui,
              outStr: (idStr *)v44);
            v297 = 0;
          }
          LODWORD(v65) = v317.baseBuffer;
          v317.len = 0;
          v317.baseBuffer[0] = 0;
          v317.data = v317.baseBuffer;
          v317.allocedAndFlag = 20;
          HIDWORD(v65) = v318.baseBuffer;
          v318.allocedAndFlag = 20;
          v318.data = v318.baseBuffer;
          v318.len = 0;
          v318.baseBuffer[0] = 0;
          LODWORD(v66) = v300.baseBuffer;
          v300.allocedAndFlag = 20;
          v300.data = v300.baseBuffer;
          v300.len = 0;
          v300.baseBuffer[0] = 0;
          HIDWORD(v66) = &v299;
          v67 = *(char **)(*(_DWORD *)&v299.baseBuffer[4] + 4);
          v68 = *(_DWORD *)(*(_DWORD *)&v299.baseBuffer[4] + 8);
          v69 = *(_DWORD *)(*(_DWORD *)&v299.baseBuffer[4] + 12);
          v299.len = **(_DWORD **)&v299.baseBuffer[4];
          v299.data = v67;
          v299.allocedAndFlag = v68;
          *(_DWORD *)v299.baseBuffer = v69;
          if ( v55 > 0 )
          {
            for ( j = v55; j != 0; --j )
              idStr::Append(this: &v318, text: v61);
          }
          LODWORD(v71) = v63->instanceName.data;
          HIDWORD(v71) = v63->typeName.data;
          v72 = va::va(
                  this: &v322,
                  fmt: v305,
                  a3: v71,
                  a4: v66,
                  a5: v65,
                  a6: v167,
                  a7: v184,
                  a8: SHIDWORD(v196),
                  a9: v196,
                  a10: SHIDWORD(v223),
                  a11: v223);
          idStr::Append(this: &v318, text: v72);
          if ( len <= v318.len )
            len = v318.len;
          LODWORD(v73) = v63->start;
          HIDWORD(v75) = this->nameLen;
          HIDWORD(v74) = v63->end - v73;
          LODWORD(v75) = v318.data;
          v76 = va::va(
                  this: &v322,
                  fmt: v307,
                  a3: v75,
                  a4: v74,
                  a5: v73,
                  a6: v168,
                  a7: v185,
                  a8: v197,
                  a9: v213,
                  a10: v224,
                  a11: v240);
          idStr::Append(this: &v317, text: v76);
          objID = v63->objID;
          if ( objID < 0 )
          {
            parentObjID = v63->parentObjID;
            if ( parentObjID < 0 )
              goto _M222018_0;
            v88 = v313;
            v89 = idSerializerLog::Find(
                    this: v313,
                    parentObjID,
                    typeName: v63->typeName.data,
                    instanceName: v63->instanceName.data);
            if ( v89 < 0 )
            {
              idStr::operator=(this: &v300, text: *(const char **)&v299.baseBuffer[8]);
              *(float *)&v90 = idColor::colorYellow.r;
              LODWORD(v90) = &v299;
              v91 = __PAIR64__(LODWORD(idColor::colorYellow.b), LODWORD(idColor::colorYellow.g));
              end = v63->end;
              start = v63->start;
              v299.len = LODWORD(idColor::colorYellow.r);
              v299.data = (char *)LODWORD(idColor::colorYellow.g);
              HIDWORD(v78) = end - start;
              v299.allocedAndFlag = LODWORD(idColor::colorYellow.b);
              *(float *)v299.baseBuffer = idColor::colorYellow.a;
LABEL_43:
              v86 = va::va(
                      this: &v322,
                      fmt: v314,
                      a3: __SPAIR64__(HIDWORD(v78), (unsigned int)v300.data),
                      a4: v91,
                      a5: v90,
                      a6: v167,
                      a7: v184,
                      a8: SHIDWORD(v196),
                      a9: v196,
                      a10: SHIDWORD(v223),
                      a11: v223);
              goto LABEL_44;
            }
            v95 = idSnapShot::CompareObject(
                    this: ss,
                    oldss,
                    objectNum: v63->parentObjID,
                    start: v63->start,
                    end: v63->end,
                    oldStart: v63->start);
            LODWORD(v96) = 92 * v89;
            HIDWORD(v97) = v63->start;
            LODWORD(v78) = &v88->logEntries.list[v89];
            HIDWORD(v78) = v95;
            LODWORD(v97) = *(_DWORD *)(v78 + 76);
            if ( (_DWORD)v97 != HIDWORD(v97) )
            {
              v98 = va::va(
                      this: &v322,
                      fmt: v304,
                      a3: v97,
                      a4: v94,
                      a5: v96,
                      a6: v167,
                      a7: v184,
                      a8: SHIDWORD(v196),
                      a9: v196,
                      a10: SHIDWORD(v223),
                      a11: v223);
              idStr::operator=(this: &v300, text: v98);
              LODWORD(v96) = &v299;
              HIDWORD(v96) = *v309;
              LODWORD(v94) = v309[1];
              HIDWORD(v94) = v309[2];
              v99 = v309[3];
              v299.len = *v309;
              v299.allocedAndFlag = HIDWORD(v94);
              v299.data = (char *)v94;
              *(_DWORD *)v299.baseBuffer = v99;
            }
            LODWORD(v100) = *(_DWORD *)(v78 + 84);
            HIDWORD(v100) = v63->startWriteBit;
            if ( HIDWORD(v100) != (_DWORD)v100 )
            {
              v101 = va::va(
                       this: &v322,
                       fmt: v306,
                       a3: v100,
                       a4: v94,
                       a5: v96,
                       a6: v167,
                       a7: v184,
                       a8: SHIDWORD(v196),
                       a9: v196,
                       a10: SHIDWORD(v223),
                       a11: v223);
              idStr::Append(this: &v300, text: v101);
              *(float *)&v96 = idColor::colorOrange.r;
              LODWORD(v96) = &v299;
              v94 = __PAIR64__(LODWORD(idColor::colorOrange.b), LODWORD(idColor::colorOrange.g));
              v299.len = LODWORD(idColor::colorOrange.r);
              v299.data = (char *)LODWORD(idColor::colorOrange.g);
              v299.allocedAndFlag = LODWORD(idColor::colorOrange.b);
              *(float *)v299.baseBuffer = idColor::colorOrange.a;
            }
            LODWORD(v102) = *(_DWORD *)(v78 + 88);
            HIDWORD(v102) = v63->endWriteBit;
            if ( HIDWORD(v102) != (_DWORD)v102 )
            {
              v103 = va::va(
                       this: &v322,
                       fmt: v310,
                       a3: v102,
                       a4: v94,
                       a5: v96,
                       a6: v167,
                       a7: v184,
                       a8: SHIDWORD(v196),
                       a9: v196,
                       a10: SHIDWORD(v223),
                       a11: v223);
              idStr::Append(this: &v300, text: v103);
              *(float *)&v94 = idColor::colorOrange.b;
              v299.len = LODWORD(idColor::colorOrange.r);
              v299.data = (char *)LODWORD(idColor::colorOrange.g);
              v299.allocedAndFlag = LODWORD(idColor::colorOrange.b);
              *(float *)v299.baseBuffer = idColor::colorOrange.a;
            }
            LODWORD(v104) = *(_DWORD *)(v78 + 76);
            HIDWORD(v104) = v63->end;
            LODWORD(v94) = v63->start;
            LODWORD(v105) = *(_DWORD *)(v78 + 80) - v104;
            if ( HIDWORD(v104) - (_DWORD)v94 != (_DWORD)v105 )
            {
              HIDWORD(v105) = HIDWORD(v104) - v94;
              v106 = va::va(
                       this: &v322,
                       fmt: v301,
                       a3: v105,
                       a4: v94,
                       a5: v104,
                       a6: v167,
                       a7: v184,
                       a8: SHIDWORD(v196),
                       a9: v196,
                       a10: SHIDWORD(v223),
                       a11: v223);
              idStr::Append(this: &v300, text: v106);
              v107 = *(char **)(*(_DWORD *)&v299.baseBuffer[16] + 4);
              v108 = *(_DWORD *)(*(_DWORD *)&v299.baseBuffer[16] + 8);
              v109 = *(_DWORD *)(*(_DWORD *)&v299.baseBuffer[16] + 12);
              v299.len = **(_DWORD **)&v299.baseBuffer[16];
              v299.data = v107;
              v299.allocedAndFlag = v108;
              *(_DWORD *)v299.baseBuffer = v109;
            }
            LODWORD(v110) = idSnapShot::CompareObject(
                              this: ss,
                              oldss,
                              objectNum: v63->parentObjID,
                              start: v63->start,
                              end: v63->end,
                              oldStart: *(_DWORD *)(v78 + 76));
            if ( (_DWORD)v110 == HIDWORD(v78) )
              goto LABEL_43;
            HIDWORD(v110) = HIDWORD(v78);
            HIDWORD(v91) = v300.data;
            v86 = va::va(
                    this: &v322,
                    fmt: v312,
                    a3: v110,
                    a4: v91,
                    a5: v90,
                    a6: v167,
                    a7: v184,
                    a8: SHIDWORD(v196),
                    a9: v196,
                    a10: SHIDWORD(v223),
                    a11: v223);
          }
          else
          {
            LODWORD(v78) = 0;
            v79 = 0;
            if ( v35->compressionEntries.num > 0 )
            {
              list = v35->compressionEntries.list;
              v81 = 0;
              while ( list[v81].objID != objID )
              {
                ++v79;
                ++v81;
                if ( v79 >= v35->compressionEntries.num )
                  goto LABEL_36;
              }
              LODWORD(v78) = list[v79].csize;
            }
LABEL_36:
            v35->finalUncompressedSize = v35->finalUncompressedSize - v63->start + v63->end;
            if ( idSnapShot::FindObjectIndexByID(this: oldss, objectNum: v63->objID) < 0 )
            {
              idStr::operator=(this: &v300, text: *(const char **)&v299.baseBuffer[8]);
              *(float *)&v82 = idColor::colorYellow.r;
              LODWORD(v82) = &v299;
              LODWORD(v83) = LODWORD(idColor::colorYellow.g);
              v84 = v63->end;
              v85 = v63->start;
              v299.len = LODWORD(idColor::colorYellow.r);
              v299.data = (char *)LODWORD(idColor::colorYellow.g);
              HIDWORD(v78) = v84 - v85;
              v299.allocedAndFlag = LODWORD(idColor::colorYellow.b);
              *(float *)v299.baseBuffer = idColor::colorYellow.a;
            }
            else
            {
              HIDWORD(v78) = idSnapShot::CompareObject(
                               this: ss,
                               oldss,
                               objectNum: v63->objID,
                               start: 0,
                               end: 0,
                               oldStart: 0);
            }
            HIDWORD(v83) = v300.data;
            v86 = va::va(
                    this: &v322,
                    fmt: v316,
                    a3: v78,
                    a4: v83,
                    a5: v82,
                    a6: v167,
                    a7: v184,
                    a8: SHIDWORD(v196),
                    a9: v196,
                    a10: SHIDWORD(v223),
                    a11: v223);
          }
LABEL_44:
          idStr::Append(this: &v317, text: v86);
          if ( v311->valueInteger != 0 && HIDWORD(v78) == 0
            || (unsigned __int8)idSnapshotMetrics::ShouldShowEntry(this, log: v35, entry: v63) == 0 )
          {
_M222018_0:
            idStr::FreeData(this: &v300);
            idStr::FreeData(this: &v318);
            goto LABEL_62;
          }
          HIDWORD(v111) = *(_DWORD *)v299.baseBuffer;
          v297 = 1;
          LODWORD(v111) = __CFADD__(v60 - this->guiOffset, this->guiOffset ^ 0x80000000) ? nullptr : gui;
          v112 = idSnapshotMetrics::OutputLine(
                   this,
                   str: v317.data,
                   print: v37,
                   gui: v111,
                   outStr: v44,
                   a6: (idStr *)1,
                   a7: v167,
                   a8: v196,
                   a9: v223,
                   a10: v249,
                   a11: v259,
                   a12: v269,
                   a13: v279,
                   a14: v289);
          width = this->width;
          if ( v112 > width )
            width = v112;
          this->width = width;
          idStr::FreeData(this: &v300);
          idStr::FreeData(this: &v318);
LABEL_62:
          idStr::FreeData(this: &v317);
          v114 = v35->logEntries.num;
          ++v60;
          *(_DWORD *)&v299.baseBuffer[12] = v62 + 92;
          if ( v60 >= v114 )
          {
            v41 = v315;
            v53 = (char *)v302;
            v52 = v303;
            v29 = ss;
            v30 = oldss;
            v31 = seq;
            break;
          }
        }
      }
      this->nameLen = len;
      if ( v35->finalCompressedSize > 0 && v35->finalUncompressedSize > 0 )
      {
        v115 = 0;
        v116 = nullptr;
        if ( v35->compressionEntries.num > 0 )
        {
          v117 = 0;
          v118 = v35->compressionEntries.list;
          do
          {
            v116 = (idStr *)((char *)v116 + 1);
            ++v117;
            v115 += v118->csize;
            v118 = &v35->compressionEntries.list[v117];
          }
          while ( (int)v116 < v35->compressionEntries.num );
        }
        idSnapshotMetrics::OutputLine(
          this,
          str: v53,
          print: v37,
          gui: __SPAIR64__(LODWORD(idColor::colorMdGrey.a), (unsigned int)gui),
          outStr: v44,
          a6: v116,
          a7: v167,
          a8: v196,
          a9: v223,
          a10: v249,
          a11: v259,
          a12: v269,
          a13: v279,
          a14: v289);
        idSnapshotMetrics::NewLine(this, print: v37, gui, outStr: (idStr *)v44);
        LODWORD(v119) = &v299;
        HIDWORD(v121) = v35->fragmented;
        HIDWORD(v119) = **(_DWORD **)&v299.baseBuffer[4];
        LODWORD(v120) = *(_DWORD *)(*(_DWORD *)&v299.baseBuffer[4] + 4);
        HIDWORD(v120) = *(_DWORD *)(*(_DWORD *)&v299.baseBuffer[4] + 8);
        LODWORD(v121) = *(_DWORD *)(*(_DWORD *)&v299.baseBuffer[4] + 12);
        v299.len = **(_DWORD **)&v299.baseBuffer[4];
        v299.allocedAndFlag = HIDWORD(v120);
        v299.data = (char *)v120;
        *(_DWORD *)v299.baseBuffer = v121;
        if ( HIDWORD(v121) != 0 )
        {
          LODWORD(v122) = gui;
          v123 = *(char **)(*(_DWORD *)&v299.baseBuffer[16] + 4);
          v124 = *(_DWORD *)(*(_DWORD *)&v299.baseBuffer[16] + 8);
          v125 = *(_DWORD *)(*(_DWORD *)&v299.baseBuffer[16] + 12);
          v299.len = **(_DWORD **)&v299.baseBuffer[16];
          v299.data = v123;
          v299.allocedAndFlag = v124;
          *(_DWORD *)v299.baseBuffer = v125;
          v126 = v125;
          HIDWORD(v122) = v125;
          v127 = v299.len;
          idSnapshotMetrics::OutputLine(
            this,
            str: "FRAGMENTED",
            print: v37,
            gui: v122,
            outStr: v44,
            a6: &v299,
            a7: v169,
            a8: v198,
            a9: v225,
            a10: v250,
            a11: v260,
            a12: v270,
            a13: v280,
            a14: v290);
          idSnapshotMetrics::NewLine(this, print: v37, gui, outStr: (idStr *)v44);
        }
        else
        {
          v126 = *(_DWORD *)v299.baseBuffer;
          v127 = v299.len;
        }
        HIDWORD(v121) = v35->finalUncompressedSize;
        v128 = va::va(
                 this: &v322,
                 fmt: "Total Size:       %6d",
                 a3: v121,
                 a4: v120,
                 a5: v119,
                 a6: v169,
                 a7: v186,
                 a8: SHIDWORD(v198),
                 a9: v198,
                 a10: SHIDWORD(v225),
                 a11: v225);
        idSnapshotMetrics::OutputLine(
          this,
          str: v128->buffer,
          print: v37,
          gui: __SPAIR64__(v126, (unsigned int)gui),
          outStr: v44,
          a6: v129,
          a7: v170,
          a8: v199,
          a9: v226,
          a10: v250,
          a11: v260,
          a12: v270,
          a13: v280,
          a14: v290);
        LODWORD(v130) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
        HIDWORD(v131) = v127;
        v133 = va::va(
                 this: &v322,
                 fmt: "RLE Compressed:   %6d",
                 a3: v131,
                 a4: v132,
                 a5: v130,
                 a6: v171,
                 a7: v187,
                 a8: v200,
                 a9: v214,
                 a10: v227,
                 a11: v241);
        idSnapshotMetrics::OutputLine(
          this,
          str: v133->buffer,
          print: v37,
          gui: __SPAIR64__(v126, (unsigned int)gui),
          outStr: v44,
          a6: v134,
          a7: v172,
          a8: v201,
          a9: v228,
          a10: v251,
          a11: v261,
          a12: v271,
          a13: v281,
          a14: v291);
        HIDWORD(v135) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
        HIDWORD(v136) = v35->finalCompressedSize;
        v138 = va::va(
                 this: &v322,
                 fmt: "Final Compressed: %6d",
                 a3: v136,
                 a4: v137,
                 a5: v135,
                 a6: v173,
                 a7: v188,
                 a8: v202,
                 a9: v215,
                 a10: v229,
                 a11: v242);
        idSnapshotMetrics::OutputLine(
          this,
          str: v138->buffer,
          print: v37,
          gui: __SPAIR64__(v126, (unsigned int)gui),
          outStr: v44,
          a6: v139,
          a7: v174,
          a8: v203,
          a9: v230,
          a10: v252,
          a11: v262,
          a12: v272,
          a13: v282,
          a14: v292);
        idSnapshotMetrics::NewLine(this, print: v37, gui, outStr: (idStr *)v44);
        HIDWORD(v140) = v29->time;
        HIDWORD(v141) = v30->time;
        LODWORD(v141) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
        LODWORD(v140) = HIDWORD(v140) - HIDWORD(v141);
        v143 = va::va(
                 this: &v322,
                 fmt: "Time: %6d  Delta: %4d",
                 a3: v140,
                 a4: v141,
                 a5: v142,
                 a6: v175,
                 a7: v189,
                 a8: v204,
                 a9: v216,
                 a10: v231,
                 a11: v243);
        *(_QWORD *)((char *)&v144 + 4) = *(_QWORD *)&v52->b;
        LODWORD(v144) = gui;
        idSnapshotMetrics::OutputLine(
          this,
          str: v143->buffer,
          print: v37,
          gui: v144,
          outStr: v44,
          a6: v145,
          a7: v176,
          a8: v205,
          a9: v232,
          a10: v253,
          a11: v263,
          a12: v273,
          a13: v283,
          a14: v293);
        LODWORD(v146) = v31 - baseSeq;
        HIDWORD(v146) = v31;
        v148 = va::va(
                 this: &v322,
                 fmt: "Seq:  %6d  Delta: %4d",
                 a3: v146,
                 a4: v147,
                 a5: __SPAIR64__("ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY", baseSeq),
                 a6: v177,
                 a7: v190,
                 a8: v206,
                 a9: v217,
                 a10: v233,
                 a11: v244);
        LODWORD(v149) = gui;
        *(_QWORD *)((char *)&v149 + 4) = *(_QWORD *)&v52->b;
        idSnapshotMetrics::OutputLine(
          this,
          str: v148->buffer,
          print: v37,
          gui: v149,
          outStr: v44,
          a6: v150,
          a7: v178,
          a8: v207,
          a9: v234,
          a10: v254,
          a11: v264,
          a12: v274,
          a13: v284,
          a14: v294);
        LODWORD(v151) = v35->compressionEntries.num;
        HIDWORD(v151) = v29->objectStates.num;
        v154 = va::va(
                 this: &v322,
                 fmt: "Objs: %6d  Compr: %4d",
                 a3: v151,
                 a4: v153,
                 a5: v152,
                 a6: v179,
                 a7: v191,
                 a8: v208,
                 a9: v218,
                 a10: v235,
                 a11: v245);
        *(_QWORD *)((char *)&v155 + 4) = *(_QWORD *)&v52->b;
        LODWORD(v155) = gui;
        idSnapshotMetrics::OutputLine(
          this,
          str: v154->buffer,
          print: v37,
          gui: v155,
          outStr: v44,
          a6: v156,
          a7: v180,
          a8: v209,
          a9: v236,
          a10: v255,
          a11: v265,
          a12: v275,
          a13: v285,
          a14: v295);
        v157 = Sys_Milliseconds();
        LODWORD(v158) = this->lastReportMS;
        HIDWORD(v158) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
        HIDWORD(v159) = peer;
        LODWORD(v159) = v157 - v158;
        v161 = va::va(
                 this: &v322,
                 fmt: "Peer[%d]    Time: %d",
                 a3: v159,
                 a4: v160,
                 a5: v158,
                 a6: v181,
                 a7: v192,
                 a8: v210,
                 a9: v219,
                 a10: v237,
                 a11: v246);
        LODWORD(v162) = gui;
        *(_QWORD *)((char *)&v162 + 4) = *(_QWORD *)&v52->b;
        idSnapshotMetrics::OutputLine(
          this,
          str: v161->buffer,
          print: v37,
          gui: v162,
          outStr: v44,
          a6: v163,
          a7: v182,
          a8: v211,
          a9: v238,
          a10: v256,
          a11: v266,
          a12: v276,
          a13: v286,
          a14: v296);
      }
      if ( v41 )
        idMetricRecord::Serialize(this: &v321);
      idStr::FreeData(this: &v320);
      idStr::FreeData(this: &v321.text);
      idMetricRecord::~idMetricRecord(this: &v321);
    }
  }
}


// ========================================================================
// __unwind$221639
// EA  : 0x828A1278
// RVA : 0x008A1278
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void _unwind_221639()
{
  int v0; // r12

  idSnapshotMetrics::idSnapshotMetricRecord::~idSnapshotMetricRecord(this: (idSnapshotMetrics::idSnapshotMetricRecord *)(v0 - 8800 + 336));
}


// ========================================================================
// __unwind$221640
// EA  : 0x828A12A0
// RVA : 0x008A12A0
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void _unwind_221640()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8800 + 304));
}


// ========================================================================
// __unwind$221641
// EA  : 0x828A12C8
// RVA : 0x008A12C8
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void _unwind_221641()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8800 + 224));
}


// ========================================================================
// __unwind$221642_1
// EA  : 0x828A12F0
// RVA : 0x008A12F0
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void _unwind_221642_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8800 + 256));
}


// ========================================================================
// __unwind$221643_0
// EA  : 0x828A1318
// RVA : 0x008A1318
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void _unwind_221643_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8800 + 128));
}


// ========================================================================
// __unwind$221964
// EA  : 0x828A1340
// RVA : 0x008A1340
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void _unwind_221964()
{
  int v0; // r12

  idMetricRecord::~idMetricRecord(this: (idMetricRecord *)(v0 - 8800 + 336));
}


// ========================================================================
// ?net_snapshot_metrics_watch_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828A1370
// RVA : 0x008A1370
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall net_snapshot_metrics_watch_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idStr v2; // [sp+50h] [-30h] BYREF

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  idStr::idStr(this: &v2, text: v1);
  idList<idStr,5>::Append(this: &snapshotMetrics.watchList, obj: &v2);
  idStr::FreeData(this: &v2);
}


// ========================================================================
// __unwind$222060
// EA  : 0x828A13D8
// RVA : 0x008A13D8
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void _unwind_222060()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 128 + 80));
}


// ========================================================================
// ?net_snapshot_metrics_ignore_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828A1408
// RVA : 0x008A1408
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall net_snapshot_metrics_ignore_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idStr v2; // [sp+50h] [-30h] BYREF

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  idStr::idStr(this: &v2, text: v1);
  idList<idStr,5>::Append(this: &snapshotMetrics.ignoreList, obj: &v2);
  idStr::FreeData(this: &v2);
}


// ========================================================================
// __unwind$222088
// EA  : 0x828A146C
// RVA : 0x008A146C
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void _unwind_222088()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 128 + 80));
}


// ========================================================================
// ??0idSnapshotMetrics@@QAA@XZ
// EA  : 0x828A15D0
// RVA : 0x008A15D0
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

idSnapshotMetrics *__fastcall idSnapshotMetrics::idSnapshotMetrics(idSnapshotMetrics *this)
{
  double v2; // fp13
  int *p_nextKeyEvent; // r10
  int v4; // ctr

  idStaticList<idStr,16>::idStaticList<idStr,16>(this: &this->ignoreList);
  idStaticList<idStr,16>::idStaticList<idStr,16>(this: &this->watchList);
  this->guiOffset = 0;
  this->nextKeyEvent = 0;
  this->width = 400;
  this->height = 50;
  this->nameLen = 30;
  v2 = (float)(net_snapshot_gui_scale.valueFloat * (float)15.0);
  this->SNAPSHOTS_DRAW_SCALE = net_snapshot_gui_scale.valueFloat;
  p_nextKeyEvent = &this->nextKeyEvent;
  this->SNAPSHOTS_Y_OFFSET = 25.0;
  this->printNextReport = false;
  this->SNAPSHOTS_X_OFFSET = 20.0;
  v4 = 6;
  this->SNAPSHOTS_Y_SPACING = v2;
  this->lastReportMS = 0;
  do
  {
    *++p_nextKeyEvent = 0;
    --v4;
  }
  while ( v4 != 0 );
  return this;
}


// ========================================================================
// __unwind$222206
// EA  : 0x828A1690
// RVA : 0x008A1690
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void _unwind_222206()
{
  int v0; // r12

  idStaticList<idStr,16>::~idStaticList<idStr,16>(this: *(idStaticList<idStr,16> **)(v0 - 112 + 132));
}


// ========================================================================
// ?LogSnapshotDelta@idSnapshotMetrics@@QAAXAAVidSnapShot@@PBV2@HHHH_N@Z
// EA  : 0x828A16B8
// RVA : 0x008A16B8
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall idSnapshotMetrics::LogSnapshotDelta(
        idSnapshotMetrics *this,
        idSnapShot *ss,
        idSnapShot *oldss,
        int seq,
        idStr *baseSeq,
        int peer,
        int size,
        bool fullSnap)
{
  char v15; // r9
  int valueInteger; // r28
  int v17; // r25
  bool v18; // [sp+Bh] [-A5h]
  int v19; // [sp+Ch] [-A4h]
  int v20; // [sp+10h] [-A0h]
  int v21; // [sp+14h] [-9Ch]
  int v22; // [sp+18h] [-98h]
  int v23; // [sp+1Ch] [-94h]
  int v24; // [sp+20h] [-90h]
  int v25; // [sp+24h] [-8Ch]
  int v26; // [sp+28h] [-88h]
  int v27; // [sp+2Ch] [-84h]
  int v28; // [sp+30h] [-80h]
  int v29; // [sp+34h] [-7Ch]
  int v30; // [sp+38h] [-78h]
  int v31; // [sp+3Ch] [-74h]
  int v32; // [sp+40h] [-70h]
  int v33; // [sp+44h] [-6Ch]
  int v34; // [sp+48h] [-68h]
  int v35; // [sp+4Ch] [-64h]
  int v36; // [sp+50h] [-60h]

  v15 = 0;
  if ( seq > net_snapshot_metrics_report_seq.valueInteger )
  {
    if ( (int)abs32(size) <= net_snapshot_metrics_report_size.valueInteger )
    {
      if ( fullSnap || net_snapshot_metrics_report_fragment.valueInteger == 0 )
        goto LABEL_8;
      idLib::Printf(fmt: "\n^2Snapshot delta for peer %d fragmented. Delta Size: %d\n", peer, size);
    }
    else
    {
      idLib::Printf(fmt: "\n^2Snapshot delta for peer %d exceeded warn size. Delta Size: %d\n", peer, size);
    }
    v15 = 1;
  }
LABEL_8:
  if ( v15 != 0 )
  {
    valueInteger = net_snapshot_metrics_report_wait.valueInteger;
    if ( this->lastReportMS + valueInteger <= Sys_Milliseconds() )
    {
      v17 = 4 * (peer + 276);
      if ( ((int)*(idStr **)((char *)&this->ignoreList.list + v17) < (int)baseSeq
         || net_snapshot_metrics_report_once_per_deltaseq.valueInteger == 0)
        && (!common->IsServer(this: common) || (net_snapshot_metrics_report_netrole.valueInteger & 1) != 0)
        && (!common->IsClient(this: common) || (net_snapshot_metrics_report_netrole.valueInteger & 2) != 0) )
      {
        *(idStr **)((char *)&this->ignoreList.list + v17) = baseSeq;
        idSnapshotMetrics::GenerateReport(
          this,
          ss,
          oldss,
          seq,
          (unsigned int)baseSeq,
          peer,
          gui: nullptr,
          reportMetrics: (-(net_snapshot_metrics_report_mode.valueInteger & 2) & ~(net_snapshot_metrics_report_mode.valueInteger & 2)) < 0,
          printConsole: v18,
          a10: v19,
          a11: v20,
          a12: v21,
          a13: v22,
          a14: v23,
          a15: v24,
          a16: v25,
          a17: v26,
          a18: v27,
          a19: v28,
          a20: v29,
          a21: v30,
          a22: v31,
          a23: v32,
          a24: v33,
          a25: v34,
          a26: v35,
          a27: v36,
          a28: (-(net_snapshot_metrics_report_mode.valueInteger & 1) & ~(net_snapshot_metrics_report_mode.valueInteger & 1)) < 0);
      }
    }
  }
  console->AddSnapshots(this: console, a2: ss, a3: oldss, a4: size, a5: peer, a6: seq, a7: (int)baseSeq);
}


// ========================================================================
// ??1idSerializerLog@@QAA@XZ
// EA  : 0x828A1918
// RVA : 0x008A1918
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall idSerializerLog::~idSerializerLog(idSerializerLog *this)
{
  if ( globalSerLog == this )
    globalSerLog = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->compressionEntries);
  if ( this->logEntries.listStatic == 0 || this->logEntries.listStatic == 2 )
  {
    if ( this->logEntries.list != nullptr )
      idListArrayDelete<idSerializerLog::logEntry_t>(ptr: &this->logEntries.list->typeName, num: this->logEntries.size);
    this->logEntries.list = nullptr;
    this->logEntries.size = 0;
  }
  this->logEntries.num = 0;
}


// ========================================================================
// __unwind$222399_0
// EA  : 0x828A1990
// RVA : 0x008A1990
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void _unwind_222399_0()
{
  int v0; // r12

  idList<idSerializerLog::logEntry_t,44>::~idList<idSerializerLog::logEntry_t,44>(this: *(idList<idSerializerLog::logEntry_t,44> **)(v0 - 112 + 132));
}


// ========================================================================
// ?AddCompressionLog@idSerializerLog@@QAAXHH@Z
// EA  : 0x828A19C0
// RVA : 0x008A19C0
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall idSerializerLog::AddCompressionLog(idSerializerLog *this, int objID, int csize)
{
  idSerializerLog::compressionEntry_t *v6; // r3

  if ( objID > 0 && csize > 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v6 = idList<idSerializerLog::compressionEntry_t,44>::Alloc(this: &this->compressionEntries);
    v6->objID = objID;
    v6->csize = csize;
    idMem::PopHeap(this: &mem);
  }
}


// ========================================================================
// __unwind$222446
// EA  : 0x828A1A20
// RVA : 0x008A1A20
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void _unwind_222446()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 144 + 80));
}


// ========================================================================
// ?Release@idSerializerLog@@QAAXXZ
// EA  : 0x828A1A48
// RVA : 0x008A1A48
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __fastcall idSerializerLog::Release(idSerializerLog *this)
{
  int v2; // r11

  v2 = this->refCount - 1;
  this->refCount = v2;
  if ( v2 <= 0 )
  {
    idSerializerLog::~idSerializerLog(this);
    idMem::Free(this: &mem, ptr: this, align: ALIGN_16);
  }
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics''
// EA  : 0x83345D18
// RVA : 0x01345D18
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapshot_metrics__()
{
  idCVar::idCVar(
    this: &net_snapshot_metrics,
    name: "net_snapshot_metrics",
    value: "1",
    flags: 1,
    description: "Enables snapshot metrics",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapshot_metrics__);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_report_mode''
// EA  : 0x83345D70
// RVA : 0x01345D70
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapshot_metrics_report_mode__()
{
  idCVar::idCVar(
    this: &net_snapshot_metrics_report_mode,
    name: "net_snapshot_metrics_report_mode",
    value: "3",
    flags: 2,
    description: "What to do when we report metrics: 0=Nothing, 1=Print to console log, 2=Log to network metrics server, 3=both",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapshot_metrics_report_mode__);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_report_netrole''
// EA  : 0x83345DC8
// RVA : 0x01345DC8
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapshot_metrics_report_netrole__()
{
  idCVar::idCVar(
    this: &net_snapshot_metrics_report_netrole,
    name: "net_snapshot_metrics_report_netrole",
    value: "3",
    flags: 2,
    description: "Who should do the reporting. 0=No one, 1=Server only, 2=Clients only, 3=Both",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapshot_metrics_report_netrole__);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_report_seq''
// EA  : 0x83345E20
// RVA : 0x01345E20
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapshot_metrics_report_seq__()
{
  idCVar::idCVar(
    this: &net_snapshot_metrics_report_seq,
    name: "net_snapshot_metrics_report_seq",
    value: "100",
    flags: 2,
    description: "Minimum snap sequence to report. Used to not report initial snapshots",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapshot_metrics_report_seq__);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_report_size''
// EA  : 0x83345E78
// RVA : 0x01345E78
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapshot_metrics_report_size__()
{
  idCVar::idCVar(
    this: &net_snapshot_metrics_report_size,
    name: "net_snapshot_metrics_report_size",
    value: "2000",
    flags: 2,
    description: "Report snapshot metrics snapshot delta is greater than this size",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapshot_metrics_report_size__);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_report_fragment''
// EA  : 0x83345ED0
// RVA : 0x01345ED0
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapshot_metrics_report_fragment__()
{
  idCVar::idCVar(
    this: &net_snapshot_metrics_report_fragment,
    name: "net_snapshot_metrics_report_fragment",
    value: "1",
    flags: 1,
    description: "Report snapshot metrics when delta fragments",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapshot_metrics_report_fragment__);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_report_wait''
// EA  : 0x83345F28
// RVA : 0x01345F28
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapshot_metrics_report_wait__()
{
  idCVar::idCVar(
    this: &net_snapshot_metrics_report_wait,
    name: "net_snapshot_metrics_report_wait",
    value: "30000",
    flags: 2,
    description: "Minimum time to wait between generating snapshot reports",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapshot_metrics_report_wait__);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_report_once_per_deltaseq''
// EA  : 0x83345F80
// RVA : 0x01345F80
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapshot_metrics_report_once_per_deltaseq__()
{
  idCVar::idCVar(
    this: &net_snapshot_metrics_report_once_per_deltaseq,
    name: "net_snapshot_metrics_report_once_per_deltaseq",
    value: "1",
    flags: 1,
    description: "If true, only generate reports one time per base sequence per peer. Prevents spam if base states arent being ACKd",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapshot_metrics_report_once_per_deltaseq__);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_skipZero''
// EA  : 0x83345FD8
// RVA : 0x01345FD8
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapshot_metrics_skipZero__()
{
  idCVar::idCVar(
    this: &net_snapshot_metrics_skipZero,
    name: "net_snapshot_metrics_skipZero",
    value: "1",
    flags: 1,
    description: "Skips objects that didnt change in metric report",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapshot_metrics_skipZero__);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_gui_scale''
// EA  : 0x83346030
// RVA : 0x01346030
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapshot_gui_scale__()
{
  idCVar::idCVar(
    this: &net_snapshot_gui_scale,
    name: "net_snapshot_gui_scale",
    value: "0.75",
    flags: 4,
    description: "GUI scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapshot_gui_scale__);
}


// ========================================================================
// `dynamic initializer for 'snapshotMetrics''
// EA  : 0x83346088
// RVA : 0x01346088
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__snapshotMetrics__()
{
  idSnapshotMetrics::idSnapshotMetrics(this: &snapshotMetrics);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__snapshotMetrics__);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_watch_v''
// EA  : 0x833460C0
// RVA : 0x013460C0
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__net_snapshot_metrics_watch_v__()
{
  return idCommandLink::idCommandLink(
           this: &net_snapshot_metrics_watch_v,
           cmdName: "net_snapshot_metrics_watch",
           function: net_snapshot_metrics_watch_f,
           description: "Only show snapshot metrics containg this",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_ignore_v''
// EA  : 0x833460E8
// RVA : 0x013460E8
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__net_snapshot_metrics_ignore_v__()
{
  return idCommandLink::idCommandLink(
           this: &net_snapshot_metrics_ignore_v,
           cmdName: "net_snapshot_metrics_ignore",
           function: net_snapshot_metrics_ignore_f,
           description: "Ignore snapshot metrics containing this name",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_clear_v''
// EA  : 0x83346110
// RVA : 0x01346110
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__net_snapshot_metrics_clear_v__()
{
  return idCommandLink::idCommandLink(
           this: &net_snapshot_metrics_clear_v,
           cmdName: "net_snapshot_metrics_clear",
           function: net_snapshot_metrics_clear_f,
           description: "Clear named watch/ignore",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_metrics_print_v''
// EA  : 0x83346138
// RVA : 0x01346138
// PDB : w:\tech5\engine\network\snapshotmetrics.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__net_snapshot_metrics_print_v__()
{
  return idCommandLink::idCommandLink(
           this: &net_snapshot_metrics_print_v,
           cmdName: "net_snapshot_metrics_print",
           function: net_snapshot_metrics_print_f,
           description: "Prints next snapshot report to console log",
           argCompletion: nullptr);
}

