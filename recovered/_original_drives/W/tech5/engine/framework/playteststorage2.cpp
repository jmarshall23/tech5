
// ========================================================================
// ?WriteTextFile@idPlaytestStorage@@QAAXABVidStr@@0ABV?$idList@VidStr@@$04@@@Z
// EA  : 0x8268DA20
// RVA : 0x0068DA20
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void __fastcall idPlaytestStorage::WriteTextFile(
        idPlaytestStorage *this,
        const idStr *fileName,
        const idStr *mapName,
        const idList<idStr,5> *mapLayersSpawned)
{
  fsPath_t v8; // r5
  const char *v9; // r3
  int v10; // r30
  int v11; // r29
  idStr *ReadableTimeString; // r3
  int v13; // r25
  int v14; // r29
  int v15; // r27
  idList<idPlaytestStorage::playerButtonInfo_t,5> *v16; // r11
  int v17; // r30
  int v18; // r19
  idPlaytestStorage::playerMainBreadCrumbInfo_t *v19; // r11
  int v20; // r25
  idPlaytestStorage::playerMainBreadCrumbInfo_t *v21; // r11
  int v22; // r23
  idPlaytestStorage::playerNormalBreadCrumbList_t *v23; // r27
  int v24; // r29
  int v25; // r26
  idPlaytestStorage::playerNormalBreadCrumbInfo_t *v26; // r30
  int v27; // r25
  int v28; // r23
  idPlaytestStorage::playerMiscControlBreadCrumbList_t *v29; // r29
  int v30; // r27
  int v31; // r26
  idPlaytestStorage::playerMiscControlBreadCrumbInfo_t *v32; // r30
  int v33; // r25
  int v34; // r23
  idPlaytestStorage::playerVehicleBreadCrumbList_t *v35; // r29
  int v36; // r27
  int v37; // r26
  idPlaytestStorage::playerVehicleBreadCrumbInfo_t *v38; // r30
  idPlaytestStorage::ai2Info_t *v39; // r26
  idStr *v40; // r3
  int v41; // r23
  int v42; // r25
  int v43; // r29
  idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5> *v44; // r11
  int v45; // r27
  idPlaytestStorage::ai2BreadCrumbInfo_t *v46; // r30
  int v47; // r23
  int v48; // r22
  int *p_timestamp; // r30
  idStr *v50; // r29
  idStr *v51; // r3
  int v52; // r27
  int v53; // r25
  _DWORD *v54; // r29
  int v55; // r30
  int v56; // r29
  int v57; // r25
  int v58; // r23
  idPlaytestStorage::aiVehicleInfo_t *v59; // r29
  idStr *v60; // r3
  int v61; // r27
  int v62; // r26
  idPlaytestStorage::aiVehicleBreadCrumbInfo_t *v63; // r30
  int v64; // r25
  int v65; // r27
  int v66; // r30
  idList<idPlaytestStorage::itemInfo_t,5> *v67; // r11
  int v68; // r29
  idPlaytestStorage::itemInfo_t *v69; // r11
  int v70; // r25
  int v71; // r27
  int v72; // r30
  idList<idPlaytestStorage::useFocusInfo_t,5> *v73; // r11
  int v74; // r29
  idPlaytestStorage::useFocusInfo_t *v75; // r11
  int v76; // r25
  int v77; // r27
  int v78; // r30
  idList<idPlaytestStorage::quickItemInfo_t,5> *v79; // r11
  int v80; // r29
  float *p_x; // r11
  int v82; // r25
  int v83; // r27
  int v84; // r30
  idList<idPlaytestStorage::equipItemInfo_t,5> *v85; // r11
  int v86; // r29
  float *v87; // r11
  int v88; // r20
  int v89; // r25
  idList<idPlaytestStorage::inventoryInfo_t,5> *list; // r11
  int v91; // r26
  int v92; // r23
  int *v93; // r30
  idStr *v94; // r3
  int v95; // r29
  int v96; // r27
  int v97; // r25
  int v98; // r27
  int v99; // r30
  idList<idPlaytestStorage::deathInfo_t,5> *v100; // r11
  int v101; // r29
  float *v102; // r11
  int v103; // r25
  int v104; // r27
  int v105; // r30
  idList<idPlaytestStorage::weaponFireInfo_t,5> *v106; // r11
  int v107; // r29
  idPlaytestStorage::weaponFireInfo_t *v108; // r11
  int v109; // r27
  int v110; // r26
  idPlaytestStorage::radiusDamageInfo_t *v111; // r30
  int v112; // r30
  int v113; // r29
  idPlaytestStorage::deathInfo_t *v114; // r11
  int v115; // r30
  int v116; // r29
  idPlaytestStorage::weaponFireInfo_t *v117; // r11
  idFile_vtbl *v118; // r30
  char *filePtr; // r28
  unsigned int v120; // r3
  int v121; // [sp+94h] [-32Ch]
  int v122; // [sp+94h] [-32Ch]
  int v123; // [sp+9Ch] [-324h]
  idFile *v124; // [sp+B8h] [-308h]
  idFile_Memory v125; // [sp+100h] [-2C0h] BYREF
  const char *v126; // [sp+24Ch] [-174h]
  const char *v127; // [sp+250h] [-170h]
  const char *v128; // [sp+254h] [-16Ch]
  const char *v129; // [sp+258h] [-168h]
  const char *v130; // [sp+25Ch] [-164h]
  idStr v131; // [sp+260h] [-160h] BYREF
  idStr v132; // [sp+280h] [-140h] BYREF
  idStr v133; // [sp+2A0h] [-120h] BYREF
  idStr v134; // [sp+2C0h] [-100h] BYREF
  idStr v135; // [sp+2E0h] [-E0h] BYREF
  idStr v136[6]; // [sp+300h] [-C0h] BYREF

  idFile_Memory::idFile_Memory(this: &v125);
  if ( playtest_save_useSavePath.valueInteger != 0 )
    v8 = FSPATH_SAVE;
  else
    v8 = FSPATH_BASE;
  v124 = fileSystem->OpenFileWrite(this: fileSystem, a2: fileName->data, a3: v8);
  if ( v124 != nullptr )
  {
    idFile::Printf(this: &v125, fmt: "PLAYTEST FILE:\n---\n");
    idFile::Printf(this: &v125, fmt: "PT VERSION:\t%d\n", this->version);
    idFile::Printf(this: &v125, fmt: "BUILD VERSION: %s\n", com_version.valueString.data);
    v9 = sys->GetMachineName(this: sys);
    idFile::Printf(this: &v125, fmt: "MACHINE NAME: %s\n", v9);
    idFile::Printf(this: &v125, fmt: "MAP:\t\t\t%s\n", mapName->data);
    idFile::Printf(this: &v125, fmt: "LAYERS:\t\t%d\n", mapLayersSpawned->num);
    v10 = 0;
    if ( mapLayersSpawned->num > 0 )
    {
      v11 = 0;
      do
      {
        idFile::Printf(this: &v125, fmt: "\t\t\t\t%s\n", mapLayersSpawned->list[v11].data);
        ++v10;
        ++v11;
      }
      while ( v10 < mapLayersSpawned->num );
    }
    idFile::Printf(this: &v125, fmt: "BeginTime: %d ms\n", this->beginTime);
    idFile::Printf(this: &v125, fmt: "LastTime: %d ms\n", this->lastTime);
    ReadableTimeString = idPlaytestStorage::CreateReadableTimeString(
                           result: v136,
                           timeMS: this->lastTime - this->beginTime + 1);
    idFile::Printf(this: &v125, fmt: "Total Time: %s\n", ReadableTimeString->data);
    idStr::FreeData(this: v136);
    idFile::Printf(this: &v125, fmt: "PLAYER BUTTON INFO\n---\n");
    v13 = 0;
    if ( this->numPlayers > 0 )
    {
      v14 = 0;
      do
      {
        if ( this->playerButtonInfo.list[v14].num > 0 )
        {
          idFile::Printf(this: &v125, fmt: "PLAYER : %d\n", v13);
          idFile::Printf(this: &v125, fmt: "NUM BUTTON LOGS: %d\n", this->playerButtonInfo.list[v14].num);
          idFile::Printf(this: &v125, fmt: "time\tlastTime\tbutton\tup\tright\tforward\n---\n");
          v15 = 0;
          v16 = &this->playerButtonInfo.list[v14];
          if ( v16->num > 0 )
          {
            v17 = 0;
            do
            {
              idFile::Printf(this: &v125, fmt: "%d\t", v16->list[v17].timestamp);
              idFile::Printf(this: &v125, fmt: "%d\t\t", this->playerButtonInfo.list[v14].list[v17].lastTimestamp);
              idFile::Printf(this: &v125, fmt: "%d\t\t", this->playerButtonInfo.list[v14].list[v17].buttons);
              idFile::Printf(this: &v125, fmt: "%d\t", this->playerButtonInfo.list[v14].list[v17].upmove);
              idFile::Printf(this: &v125, fmt: "%d\t", this->playerButtonInfo.list[v14].list[v17].rightmove);
              idFile::Printf(this: &v125, fmt: "%d\t\n", this->playerButtonInfo.list[v14].list[v17].forwardmove);
              ++v15;
              v16 = &this->playerButtonInfo.list[v14];
              ++v17;
            }
            while ( v15 < v16->num );
          }
          idFile::Printf(this: &v125, fmt: "---\n");
        }
        ++v13;
        ++v14;
      }
      while ( v13 < this->numPlayers );
    }
    idFile::Printf(this: &v125, fmt: "PLAYER BREAD CRUMB INFORMATION:\n---\n");
    v128 = "%.1f\t";
    v121 = 0;
    if ( this->numPlayers > 0 )
    {
      v126 = "NUM VEHICLE PATHS: %d\n---\n";
      v129 = "NUM MISC    PATHS: %d\n";
      v18 = 0;
      v127 = "\tIn interaction %s with entity %s\n";
      v130 = "PLAYER NORMAL PATH INFO %d\n";
      do
      {
        v19 = &this->playerBreadCrumbs.list[v18];
        if ( v19->normalBreadCrumbs.num > 0 || v19->miscBreadCrumbs.num > 0 || v19->vehicleBreadCrumbs.num > 0 )
        {
          idFile::Printf(this: &v125, fmt: "PLAYER : %d\n", v121);
          idFile::Printf(
            this: &v125,
            fmt: "NUM NORMAL  PATHS: %d\n",
            this->playerBreadCrumbs.list[v18].normalBreadCrumbs.num);
          idFile::Printf(this: &v125, fmt: v129, this->playerBreadCrumbs.list[v18].miscBreadCrumbs.num);
          idFile::Printf(this: &v125, fmt: v126, this->playerBreadCrumbs.list[v18].vehicleBreadCrumbs.num);
          idFile::Printf(this: &v125, fmt: "---\n");
          v20 = 0;
          v21 = &this->playerBreadCrumbs.list[v18];
          if ( v21->normalBreadCrumbs.num > 0 )
          {
            v22 = 0;
            do
            {
              idFile::Printf(this: &v125, fmt: v130, v20);
              v23 = &this->playerBreadCrumbs.list[v18].normalBreadCrumbs.list[v22];
              if ( v23->inInteraction )
                idFile::Printf(this: &v125, fmt: v127, v23->interactionName.data, v23->interactionEntity.data);
              idFile::Printf(this: &v125, fmt: "time\t");
              idFile::Printf(this: &v125, fmt: "count\t");
              idFile::Printf(this: &v125, fmt: "lastTime\t");
              idFile::Printf(this: &v125, fmt: "health\t");
              idFile::Printf(this: &v125, fmt: "healthPercent\t");
              idFile::Printf(this: &v125, fmt: "speed\t");
              idFile::Printf(this: &v125, fmt: "ammo\t");
              idFile::Printf(this: &v125, fmt: "combatHud\t");
              idFile::Printf(this: &v125, fmt: "crouch\t");
              idFile::Printf(this: &v125, fmt: "zoom\t");
              idFile::Printf(this: &v125, fmt: "cooking\t");
              idFile::Printf(this: &v125, fmt: "location\t\t\t");
              idFile::Printf(this: &v125, fmt: "direction\n---\n");
              v24 = 0;
              if ( v23->breadCrumbs.num > 0 )
              {
                v25 = 0;
                do
                {
                  v26 = &v23->breadCrumbs.list[v25];
                  idFile::Printf(this: &v125, fmt: "%d\t", v26->timestamp);
                  idFile::Printf(this: &v125, fmt: "%d\t", v26->count);
                  idFile::Printf(this: &v125, fmt: "%d\t\t", v26->lastTimeStamp);
                  idFile::Printf(this: &v125, fmt: "%.1f\t\t", (unsigned int)COERCE_UNSIGNED_INT64(v26->health));
                  idFile::Printf(this: &v125, fmt: "%g\t\t\t", (unsigned int)COERCE_UNSIGNED_INT64(v26->healthPercent));
                  idFile::Printf(this: &v125, fmt: "%.1f\t", v26->speed);
                  idFile::Printf(this: &v125, fmt: "%d\t", v26->mainAmmoCount);
                  idFile::Printf(this: &v125, fmt: "%d\t", v26->combatHud);
                  idFile::Printf(this: &v125, fmt: "%d\t", v26->isCrouching);
                  idFile::Printf(this: &v125, fmt: "%d\t", v26->isZooming);
                  idFile::Printf(this: &v125, fmt: "%d\t", v26->isCooking);
                  idFile::Printf(
                    this: &v125,
                    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v26->loc.x)),
                    (unsigned int)COERCE_UNSIGNED_INT64(v26->loc.x),
                    (unsigned int)COERCE_UNSIGNED_INT64(v26->loc.y),
                    (unsigned int)COERCE_UNSIGNED_INT64(v26->loc.z));
                  idFile::Printf(
                    this: &v125,
                    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v26->dir.x)),
                    (unsigned int)COERCE_UNSIGNED_INT64(v26->dir.x),
                    (unsigned int)COERCE_UNSIGNED_INT64(v26->dir.y),
                    (unsigned int)COERCE_UNSIGNED_INT64(v26->dir.z));
                  ++v24;
                  ++v25;
                }
                while ( v24 < v23->breadCrumbs.num );
              }
              idFile::Printf(this: &v125, fmt: "---\n");
              ++v20;
              v21 = &this->playerBreadCrumbs.list[v18];
              ++v22;
            }
            while ( v20 < v21->normalBreadCrumbs.num );
          }
          v27 = 0;
          if ( v21->miscBreadCrumbs.num > 0 )
          {
            v28 = 0;
            do
            {
              idFile::Printf(this: &v125, fmt: "PLAYER MISC PATH INFO %d\n", v27);
              v29 = &this->playerBreadCrumbs.list[v18].miscBreadCrumbs.list[v28];
              idFile::Printf(
                this: &v125,
                fmt: "CONTROL:\t%s\t\tINTERACTION: %d\n---\n",
                v29->controlName.data,
                v29->isInteraction);
              idFile::Printf(this: &v125, fmt: "time\t");
              idFile::Printf(this: &v125, fmt: "count\t");
              idFile::Printf(this: &v125, fmt: "lastTime\t");
              idFile::Printf(this: &v125, fmt: "speed\t");
              idFile::Printf(this: &v125, fmt: "location\t\t\t");
              idFile::Printf(this: &v125, fmt: "direction\n---\n");
              v30 = 0;
              if ( v29->breadCrumbs.num > 0 )
              {
                v31 = 0;
                do
                {
                  v32 = &v29->breadCrumbs.list[v31];
                  idFile::Printf(this: &v125, fmt: "%d\t", v32->timestamp);
                  idFile::Printf(this: &v125, fmt: "%d\t", v32->count);
                  idFile::Printf(this: &v125, fmt: "%d\t\t", v32->lastTimeStamp);
                  idFile::Printf(this: &v125, fmt: "%.1f\t", v32->speed);
                  idFile::Printf(
                    this: &v125,
                    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v32->loc.x)),
                    v32->loc.y,
                    (unsigned int)COERCE_UNSIGNED_INT64(v32->loc.z));
                  idFile::Printf(
                    this: &v125,
                    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v32->dir.x)),
                    (unsigned int)COERCE_UNSIGNED_INT64(v32->dir.x),
                    (unsigned int)COERCE_UNSIGNED_INT64(v32->dir.y),
                    (unsigned int)COERCE_UNSIGNED_INT64(v32->dir.z));
                  ++v30;
                  ++v31;
                }
                while ( v30 < v29->breadCrumbs.num );
              }
              idFile::Printf(this: &v125, fmt: "---\n");
              ++v27;
              v21 = &this->playerBreadCrumbs.list[v18];
              ++v28;
            }
            while ( v27 < v21->miscBreadCrumbs.num );
          }
          v33 = 0;
          if ( v21->vehicleBreadCrumbs.num > 0 )
          {
            v34 = 0;
            do
            {
              idFile::Printf(this: &v125, fmt: "PLAYER VEHICLE PATH INFO %d\n", v33);
              v35 = &this->playerBreadCrumbs.list[v18].vehicleBreadCrumbs.list[v34];
              idFile::Printf(this: &v125, fmt: "VEHICLE: %s\t\tbomb?: %d\n---\n", v35->vehicleName.data, v35->isRCBomb);
              idFile::Printf(this: &v125, fmt: "time\t");
              idFile::Printf(this: &v125, fmt: "count\t");
              idFile::Printf(this: &v125, fmt: "lastTime\t");
              idFile::Printf(this: &v125, fmt: "health\t");
              idFile::Printf(this: &v125, fmt: "healthPercent\t");
              idFile::Printf(this: &v125, fmt: "speed\t");
              idFile::Printf(this: &v125, fmt: "ammo\t");
              idFile::Printf(this: &v125, fmt: "boost\t");
              idFile::Printf(this: &v125, fmt: "combatHud\t");
              idFile::Printf(this: &v125, fmt: "location\t\t\t");
              idFile::Printf(this: &v125, fmt: "direction\n---\n");
              v36 = 0;
              if ( v35->breadCrumbs.num > 0 )
              {
                v37 = 0;
                do
                {
                  v38 = &v35->breadCrumbs.list[v37];
                  idFile::Printf(this: &v125, fmt: "%d\t", v38->timestamp);
                  idFile::Printf(this: &v125, fmt: "%d\t", v38->count);
                  idFile::Printf(this: &v125, fmt: "%d\t\t", v38->lastTimeStamp);
                  idFile::Printf(
                    this: &v125,
                    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v38->health)),
                    (unsigned int)COERCE_UNSIGNED_INT64(v38->health));
                  idFile::Printf(this: &v125, fmt: "%g\t\t\t", (unsigned int)COERCE_UNSIGNED_INT64(v38->healthPercent));
                  idFile::Printf(this: &v125, fmt: "%.1f\t", v38->speed);
                  idFile::Printf(this: &v125, fmt: "%d\t", v38->ammo);
                  idFile::Printf(
                    this: &v125,
                    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v38->boost)),
                    (unsigned int)COERCE_UNSIGNED_INT64(v38->boost));
                  idFile::Printf(this: &v125, fmt: "%d\t\t", v38->combatHud);
                  idFile::Printf(
                    this: &v125,
                    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v38->loc.x)),
                    (unsigned int)COERCE_UNSIGNED_INT64(v38->loc.x),
                    (unsigned int)COERCE_UNSIGNED_INT64(v38->loc.y),
                    (unsigned int)COERCE_UNSIGNED_INT64(v38->loc.z));
                  idFile::Printf(
                    this: &v125,
                    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v38->dir.x)),
                    (unsigned int)COERCE_UNSIGNED_INT64(v38->dir.x),
                    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v38->dir.z)),
                    (unsigned int)COERCE_UNSIGNED_INT64(v38->dir.z));
                  ++v36;
                  ++v37;
                }
                while ( v36 < v35->breadCrumbs.num );
              }
              idFile::Printf(this: &v125, fmt: "---\n");
              ++v33;
              ++v34;
            }
            while ( v33 < this->playerBreadCrumbs.list[v18].vehicleBreadCrumbs.num );
          }
        }
        ++v18;
        ++v121;
      }
      while ( v121 < this->numPlayers );
    }
    idFile::Printf(this: &v125, fmt: "AI2 BREADCRUMB INFORMATION:\n---\n");
    idFile::Printf(this: &v125, fmt: "NUMBER OF AI2 LOGS:\t%d\n", this->ai2Info.num);
    v122 = 0;
    if ( this->ai2Info.num > 0 )
    {
      v123 = 0;
      do
      {
        v39 = &this->ai2Info.list[v123];
        idFile::Printf(this: &v125, fmt: "AI2 %d:\t%s\t\t%d\n", v122, v39->entName.data, v39->entNum);
        v40 = idPlaytestStorage::CreateReadableTimeString(result: &v131, timeMS: v39->creationTimeStamp);
        idFile::Printf(this: &v125, fmt: "Creation Time:\t%s\n", v40->data);
        idStr::FreeData(this: &v131);
        idFile::Printf(this: &v125, fmt: "NUM PATHS: %d\n---\n", v39->breadCrumbs.num);
        v41 = 0;
        if ( v39->breadCrumbs.num > 0 )
        {
          v42 = 0;
          do
          {
            idFile::Printf(this: &v125, fmt: "PATH: %d\n", v41);
            idFile::Printf(this: &v125, fmt: "time\t");
            idFile::Printf(this: &v125, fmt: "count\t");
            idFile::Printf(this: &v125, fmt: "lastTime\t");
            idFile::Printf(this: &v125, fmt: "hostile\t");
            idFile::Printf(this: &v125, fmt: "talking\t\t");
            idFile::Printf(this: &v125, fmt: "health\t");
            idFile::Printf(this: &v125, fmt: "healthPercent\t");
            idFile::Printf(this: &v125, fmt: "speed\t");
            idFile::Printf(this: &v125, fmt: "loc\t");
            idFile::Printf(this: &v125, fmt: "\t\t\tdir\n---\n");
            v43 = 0;
            v44 = &v39->breadCrumbs.list[v42];
            if ( v44->num > 0 )
            {
              v45 = 0;
              do
              {
                v46 = &v44->list[v45];
                idFile::Printf(this: &v125, fmt: "%d\t", v46->timestamp);
                idFile::Printf(this: &v125, fmt: "%d\t", v46->count);
                idFile::Printf(this: &v125, fmt: "%d\t\t", v46->lastTimeStamp);
                idFile::Printf(this: &v125, fmt: "%d\t\t", v46->isHostile);
                idFile::Printf(this: &v125, fmt: "%d\t\t", v46->isTalking);
                idFile::Printf(this: &v125, fmt: "\t%.1f\t", v46->health);
                idFile::Printf(
                  this: &v125,
                  fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v46->healthPercent)),
                  (unsigned int)COERCE_UNSIGNED_INT64(v46->healthPercent));
                idFile::Printf(
                  this: &v125,
                  fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v46->speed)),
                  (unsigned int)COERCE_UNSIGNED_INT64(v46->speed));
                idFile::Printf(
                  this: &v125,
                  fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v46->loc.x)),
                  (unsigned int)COERCE_UNSIGNED_INT64(v46->loc.x),
                  (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v46->loc.z)),
                  (unsigned int)COERCE_UNSIGNED_INT64(v46->loc.z));
                idFile::Printf(
                  this: &v125,
                  fmt: "%.1f %.1f %.1f\n",
                  (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v46->dir.y)),
                  (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v46->dir.z)),
                  (unsigned int)COERCE_UNSIGNED_INT64(v46->dir.z));
                ++v43;
                v44 = &v39->breadCrumbs.list[v42];
                ++v45;
              }
              while ( v43 < v44->num );
            }
            idFile::Printf(this: &v125, fmt: "---\n");
            ++v41;
            ++v42;
          }
          while ( v41 < v39->breadCrumbs.num );
        }
        idFile::Printf(this: &v125, fmt: "NUM STATES: %d\n---\n", v39->stateLog.num);
        v47 = 0;
        if ( v39->stateLog.num > 0 )
        {
          v48 = 0;
          do
          {
            p_timestamp = &v39->stateLog.list[v48].timestamp;
            v50 = idPlaytestStorage::CreateReadableTimeString(result: &v135, timeMS: p_timestamp[1]);
            v51 = idPlaytestStorage::CreateReadableTimeString(result: &v133, timeMS: *p_timestamp);
            idFile::Printf(
              this: &v125,
              fmt: "Log %d:\t\tTIME: %s\t\tCOUNT: %d\t\tLAST TIME: %s\t\tNUM STATES: %d\n",
              v47,
              v51->data,
              p_timestamp[2],
              v50->data,
              p_timestamp[4]);
            idStr::FreeData(this: &v133);
            idStr::FreeData(this: &v135);
            v52 = 0;
            if ( p_timestamp[4] > 0 )
            {
              v53 = 0;
              do
              {
                v54 = (_DWORD *)(v53 + p_timestamp[3]);
                idFile::Printf(this: &v125, fmt: "FSM: %s\t\t", v54[1]);
                idFile::Printf(this: &v125, fmt: "LAST TRANS: %s\n", v54[17]);
                idFile::Printf(this: &v125, fmt: "STATE: %s\t\t", v54[9]);
                ++v52;
                v53 += 96;
              }
              while ( v52 < p_timestamp[4] );
            }
            idFile::Printf(this: &v125, fmt: "---\n");
            ++v47;
            ++v48;
          }
          while ( v47 < v39->stateLog.num );
        }
        idFile::Printf(this: &v125, fmt: "DORMANT TIME STAMPS: %d\n---\n", v39->dormantTimeStamps.num);
        v55 = 0;
        if ( v39->dormantTimeStamps.num > 0 )
        {
          v56 = 0;
          do
          {
            idFile::Printf(this: &v125, fmt: "%d\n", v39->dormantTimeStamps.list[v56]);
            ++v55;
            ++v56;
          }
          while ( v55 < v39->dormantTimeStamps.num );
        }
        idFile::Printf(this: &v125, fmt: "---\n");
        ++v122;
        ++v123;
      }
      while ( v122 < this->ai2Info.num );
    }
    idFile::Printf(this: &v125, fmt: "AI VEHICLE BREADCRUMB INFORMATION:\n");
    idFile::Printf(this: &v125, fmt: "NUMBER OF AI VEHICLE LOGS:\t%d\n---\n", this->aiVehicleInfo.num);
    v57 = 0;
    if ( this->aiVehicleInfo.num > 0 )
    {
      v58 = 0;
      do
      {
        v59 = &this->aiVehicleInfo.list[v58];
        idFile::Printf(this: &v125, fmt: "AI VEHICLE %d:\t%s\t\t%d\n", v57, v59->entName.data, v59->entNum);
        v60 = idPlaytestStorage::CreateReadableTimeString(result: &v132, timeMS: v59->creationTimeStamp);
        idFile::Printf(this: &v125, fmt: "Creation Time:\t%s\n", v60->data);
        idStr::FreeData(this: &v132);
        idFile::Printf(this: &v125, fmt: "NUM BREAD CRUMBS:\t%d\n", v59->breadCrumbs.num);
        idFile::Printf(this: &v125, fmt: "time\t");
        idFile::Printf(this: &v125, fmt: "count\t");
        idFile::Printf(this: &v125, fmt: "lastTime\t");
        idFile::Printf(this: &v125, fmt: "car\t");
        idFile::Printf(this: &v125, fmt: "bomb\t");
        idFile::Printf(this: &v125, fmt: "health\t");
        idFile::Printf(this: &v125, fmt: "healthPercent\t");
        idFile::Printf(this: &v125, fmt: "speed\t");
        idFile::Printf(this: &v125, fmt: "boost\t");
        idFile::Printf(this: &v125, fmt: "ammo\t");
        idFile::Printf(this: &v125, fmt: "loc\t");
        idFile::Printf(this: &v125, fmt: "\t\t\tdir\n---\n");
        v61 = 0;
        if ( v59->breadCrumbs.num > 0 )
        {
          v62 = 0;
          do
          {
            v63 = &v59->breadCrumbs.list[v62];
            idFile::Printf(this: &v125, fmt: "%d\t", v63->timestamp);
            idFile::Printf(this: &v125, fmt: "%d\t", v63->count);
            idFile::Printf(this: &v125, fmt: "%d\t\t", v63->lastTimeStamp);
            idFile::Printf(this: &v125, fmt: "%d\t", v63->hasCar);
            idFile::Printf(this: &v125, fmt: "%d\t", v63->isRCBomb);
            idFile::Printf(
              this: &v125,
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v63->health)),
              (unsigned int)COERCE_UNSIGNED_INT64(v63->health));
            idFile::Printf(
              this: &v125,
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v63->healthPercent)),
              (unsigned int)COERCE_UNSIGNED_INT64(v63->healthPercent));
            idFile::Printf(this: &v125, fmt: "\t\t%.1f\t", v63->speed);
            idFile::Printf(
              this: &v125,
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v63->boost)),
              (unsigned int)COERCE_UNSIGNED_INT64(v63->boost));
            idFile::Printf(this: &v125, fmt: "%d\t", v63->ammo);
            idFile::Printf(
              this: &v125,
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v63->loc.x)),
              (unsigned int)COERCE_UNSIGNED_INT64(v63->loc.x),
              (unsigned int)COERCE_UNSIGNED_INT64(v63->loc.y),
              (unsigned int)COERCE_UNSIGNED_INT64(v63->loc.z));
            idFile::Printf(
              this: &v125,
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v63->dir.x)),
              (unsigned int)COERCE_UNSIGNED_INT64(v63->dir.x),
              (unsigned int)COERCE_UNSIGNED_INT64(v63->dir.y),
              (unsigned int)COERCE_UNSIGNED_INT64(v63->dir.z));
            ++v61;
            ++v62;
          }
          while ( v61 < v59->breadCrumbs.num );
        }
        idFile::Printf(this: &v125, fmt: "---\n");
        ++v57;
        ++v58;
      }
      while ( v57 < this->aiVehicleInfo.num );
    }
    idFile::Printf(this: &v125, fmt: "PLAYER ITEM INFORMATION:\n---\n");
    v64 = 0;
    if ( this->numPlayers > 0 )
    {
      v65 = 0;
      do
      {
        if ( this->playerItemInfo.list[v65].num > 0 )
        {
          idFile::Printf(this: &v125, fmt: "PLAYER: %d\n", v64);
          idFile::Printf(this: &v125, fmt: "time\tcount\tname\tmaterial\tlocation\n---\n");
          v66 = 0;
          v67 = &this->playerItemInfo.list[v65];
          if ( v67->num > 0 )
          {
            v68 = 0;
            do
            {
              v69 = &v67->list[v68];
              idFile::Printf(
                this: &v125,
                fmt: "%d\t%d\t%s\t%s\t%g %g %g\n",
                v69->timestamp,
                v69->count,
                v69->itemName.data,
                (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v69->loc.x)),
                v69->loc.x,
                v69->loc.y,
                v69->loc.z);
              ++v66;
              v67 = &this->playerItemInfo.list[v65];
              ++v68;
            }
            while ( v66 < v67->num );
          }
          idFile::Printf(this: &v125, fmt: "---\n");
        }
        ++v64;
        ++v65;
      }
      while ( v64 < this->numPlayers );
    }
    idFile::Printf(this: &v125, fmt: "PLAYER USE FOCUS INFORMATION:\n---\n");
    v70 = 0;
    if ( this->numPlayers > 0 )
    {
      v71 = 0;
      do
      {
        if ( this->playerUseFocusInfo.list[v71].num > 0 )
        {
          idFile::Printf(this: &v125, fmt: "PLAYER: %d\n", v70);
          idFile::Printf(this: &v125, fmt: "time\tfocus name\tlocation\tdirection\n---\n");
          v72 = 0;
          v73 = &this->playerUseFocusInfo.list[v71];
          if ( v73->num > 0 )
          {
            v74 = 0;
            do
            {
              v75 = &v73->list[v74];
              idFile::Printf(
                this: &v125,
                fmt: "%d\t%s\t%g %g %g\t%g %g %g\n",
                v75->timestamp,
                (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v75->loc.x)),
                v75->loc.x,
                v75->loc.y,
                v75->loc.z,
                v75->dir.x,
                v75->dir.y,
                v75->dir.z);
              ++v72;
              v73 = &this->playerUseFocusInfo.list[v71];
              ++v74;
            }
            while ( v72 < v73->num );
          }
          idFile::Printf(this: &v125, fmt: "---\n");
        }
        ++v70;
        ++v71;
      }
      while ( v70 < this->numPlayers );
    }
    idFile::Printf(this: &v125, fmt: "PLAYER USE QUICK ITEM INFORMATION:\n---\n");
    v76 = 0;
    if ( this->numPlayers > 0 )
    {
      v77 = 0;
      do
      {
        if ( this->playerUseQuickItemInfo.list[v77].num > 0 )
        {
          idFile::Printf(this: &v125, fmt: "PLAYER: %d\n", v76);
          idFile::Printf(this: &v125, fmt: "time\tlocation\tquick item\tquick item material\n");
          v78 = 0;
          v79 = &this->playerUseQuickItemInfo.list[v77];
          if ( v79->num > 0 )
          {
            v80 = 0;
            do
            {
              p_x = &v79->list[v80].loc.x;
              idFile::Printf(
                this: &v125,
                fmt: "%d\t%g %g %g\t%s\t%s\n",
                (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*p_x)),
                *p_x,
                p_x[1],
                p_x[2],
                (const char *)COERCE_UNSIGNED_INT64(*p_x),
                (const char *)COERCE_UNSIGNED_INT64(p_x[1]));
              ++v78;
              v79 = &this->playerUseQuickItemInfo.list[v77];
              ++v80;
            }
            while ( v78 < v79->num );
          }
          idFile::Printf(this: &v125, fmt: "---\n");
        }
        ++v76;
        ++v77;
      }
      while ( v76 < this->numPlayers );
    }
    idFile::Printf(this: &v125, fmt: "PLAYER EQUIP ITEM INFORMATION:\n---\n");
    v82 = 0;
    if ( this->numPlayers > 0 )
    {
      v83 = 0;
      do
      {
        if ( this->playerEquipItemInfo.list[v83].num > 0 )
        {
          idFile::Printf(this: &v125, fmt: "PLAYER: %d\n", v82);
          idFile::Printf(this: &v125, fmt: "time\tlocation\tequiped item\tequip item material\n");
          v84 = 0;
          v85 = &this->playerEquipItemInfo.list[v83];
          if ( v85->num > 0 )
          {
            v86 = 0;
            do
            {
              v87 = &v85->list[v86].loc.x;
              idFile::Printf(
                this: &v125,
                fmt: "%d\t%g %g %g\t%s\t%s\n",
                (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*v87)),
                *v87,
                v87[1],
                v87[2],
                (const char *)COERCE_UNSIGNED_INT64(*v87),
                (const char *)COERCE_UNSIGNED_INT64(v87[1]));
              ++v84;
              v85 = &this->playerEquipItemInfo.list[v83];
              ++v86;
            }
            while ( v84 < v85->num );
          }
          idFile::Printf(this: &v125, fmt: "---\n");
        }
        ++v82;
        ++v83;
      }
      while ( v82 < this->numPlayers );
    }
    idFile::Printf(this: &v125, fmt: "PLAYER INVENTORY INFORMATION:\n---\n");
    v88 = 0;
    if ( this->numPlayers > 0 )
    {
      v89 = 0;
      do
      {
        if ( this->playerInventoryInfo.list[v89].num > 0 )
        {
          idFile::Printf(this: &v125, fmt: "PLAYER: %d\n", v88);
          idFile::Printf(this: &v125, fmt: "NUM INVENTORY LOGS: %d\n", this->playerInventoryInfo.list[v89].num);
          list = this->playerInventoryInfo.list;
          v91 = 0;
          if ( list[v89].num > 0 )
          {
            v92 = 0;
            do
            {
              v93 = &list[v89].list[v92].timestamp;
              idFile::Printf(this: &v125, fmt: "---\n");
              v94 = idPlaytestStorage::CreateReadableTimeString(result: &v134, timeMS: *v93);
              idFile::Printf(this: &v125, fmt: "%d: LOG AT %s\n---\n", v91, v94->data);
              idStr::FreeData(this: &v134);
              v95 = 0;
              if ( v93[5] > 0 )
              {
                v96 = 0;
                do
                {
                  idFile::Printf(
                    this: &v125,
                    fmt: "%d\t%s\t\t%s\n",
                    *(_DWORD *)(v96 + v93[4] + 64),
                    *(const char **)(v96 + v93[4] + 4),
                    *(const char **)(v96 + v93[4] + 36));
                  ++v95;
                  v96 += 68;
                }
                while ( v95 < v93[5] );
              }
              list = this->playerInventoryInfo.list;
              ++v91;
              ++v92;
            }
            while ( v91 < list[v89].num );
          }
          idFile::Printf(this: &v125, fmt: "---\n");
        }
        ++v88;
        ++v89;
      }
      while ( v88 < this->numPlayers );
    }
    idFile::Printf(this: &v125, fmt: "PLAYER DEATH INFORMATION:\n---\n");
    v97 = 0;
    if ( this->numPlayers > 0 )
    {
      v98 = 0;
      do
      {
        if ( this->playerDeathInfo.list[v98].num > 0 )
        {
          idFile::Printf(this: &v125, fmt: "PLAYER: %d\n", v97);
          idFile::Printf(this: &v125, fmt: "time\tlocation\tkiller\tkiller Location\tKiller name\tDamage Name\n---\n");
          v99 = 0;
          v100 = &this->playerDeathInfo.list[v98];
          if ( v100->num > 0 )
          {
            v101 = 0;
            do
            {
              v102 = &v100->list[v101].loc.x;
              idFile::Printf(
                this: &v125,
                fmt: "%d\t%g %g %g\t%d\t%g %g %g\t%s\t%s\n",
                (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*v102)),
                *v102,
                v102[1],
                v102[2],
                (unsigned int)COERCE_UNSIGNED_INT64(*v102),
                v102[3],
                v102[4],
                v102[5],
                (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v102[2])),
                (const char *)COERCE_UNSIGNED_INT64(v102[2]));
              ++v99;
              v100 = &this->playerDeathInfo.list[v98];
              ++v101;
            }
            while ( v99 < v100->num );
          }
          idFile::Printf(this: &v125, fmt: "---\n");
        }
        ++v97;
        ++v98;
      }
      while ( v97 < this->numPlayers );
    }
    idFile::Printf(this: &v125, fmt: "PLAYER WEAPON FIRE INFORMATION:\n---\n");
    v103 = 0;
    if ( this->numPlayers > 0 )
    {
      v104 = 0;
      do
      {
        if ( this->playerWeaponFireInfo.list[v104].num > 0 )
        {
          idFile::Printf(this: &v125, fmt: "PLAYER: %d\n", v103);
          idFile::Printf(this: &v125, fmt: "time\ttarget\tspread\tlocation\tdirection\tweapon\tprojectile\n");
          v105 = 0;
          v106 = &this->playerWeaponFireInfo.list[v104];
          if ( v106->num > 0 )
          {
            v107 = 0;
            do
            {
              v108 = &v106->list[v107];
              idFile::Printf(
                this: &v125,
                fmt: "%d\t%d\t%g\t%g %g %g\t%g %g %g\t%s\t%s\n",
                v108->timestamp,
                v108->targetNum,
                v108->spread,
                v108->start.x,
                v108->start.y,
                v108->start.z,
                v108->dir.x,
                v108->dir.y,
                v108->dir.z,
                (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v108->start.x)),
                (const char *)COERCE_UNSIGNED_INT64(v108->start.x));
              ++v105;
              v106 = &this->playerWeaponFireInfo.list[v104];
              ++v107;
            }
            while ( v105 < v106->num );
          }
          idFile::Printf(this: &v125, fmt: "---\n");
        }
        ++v103;
        ++v104;
      }
      while ( v103 < this->numPlayers );
    }
    idFile::Printf(this: &v125, fmt: "RADIUS DAMAGE EVENTS...  EXPLOSIONS:\t%d\n", this->radiusDamageInfo.num);
    idFile::Printf(this: &v125, fmt: "time\t");
    idFile::Printf(this: &v125, fmt: "radius\t");
    idFile::Printf(this: &v125, fmt: "minDamage\t");
    idFile::Printf(this: &v125, fmt: "maxDamage\t");
    idFile::Printf(this: &v125, fmt: "playerScale\t");
    idFile::Printf(this: &v125, fmt: "location\t\t");
    idFile::Printf(this: &v125, fmt: "damageDef\t\t");
    idFile::Printf(this: &v125, fmt: "attacker\t");
    idFile::Printf(this: &v125, fmt: "inflictor\n---\n");
    v109 = 0;
    if ( this->radiusDamageInfo.num > 0 )
    {
      v110 = 0;
      do
      {
        v111 = &this->radiusDamageInfo.list[v110];
        idFile::Printf(this: &v125, fmt: "%d\t", v111->timestamp);
        idFile::Printf(
          this: &v125,
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v111->radius)),
          (unsigned int)COERCE_UNSIGNED_INT64(v111->radius));
        idFile::Printf(
          this: &v125,
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v111->minDamage)),
          (unsigned int)COERCE_UNSIGNED_INT64(v111->minDamage));
        idFile::Printf(
          this: &v125,
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v111->maxDamage)),
          (unsigned int)COERCE_UNSIGNED_INT64(v111->maxDamage));
        idFile::Printf(
          this: &v125,
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v111->playerDamageScale)),
          (unsigned int)COERCE_UNSIGNED_INT64(v111->playerDamageScale));
        idFile::Printf(
          this: &v125,
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v111->loc.x)),
          v111->loc.y,
          (unsigned int)COERCE_UNSIGNED_INT64(v111->loc.z));
        idFile::Printf(this: &v125, fmt: "%s\t", v111->damageDefName.data);
        idFile::Printf(this: &v125, fmt: "%s\t", v111->attackerName.data);
        idFile::Printf(this: &v125, fmt: "%s\n", v111->inflictorName.data);
        ++v109;
        ++v110;
      }
      while ( v109 < this->radiusDamageInfo.num );
    }
    idFile::Printf(this: &v125, fmt: "---\n");
    idFile::Printf(this: &v125, fmt: "OTHER DEATH INFORMATION:\n");
    idFile::Printf(
      this: &v125,
      fmt: "time\tentNum\tname\tLocation\tkiller\tKiller Location\tKiller Name\tDamage Name\n---\n");
    v112 = 0;
    if ( this->otherDeathInfo.num > 0 )
    {
      v113 = 0;
      do
      {
        v114 = &this->otherDeathInfo.list[v113];
        idFile::Printf(
          this: &v125,
          fmt: "%d\t%d\t%s\t%g %g %g\t%d\t%g %g %g\t%s\t%s\n",
          v114->timestamp,
          v114->entityNum,
          (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v114->loc.x)),
          v114->loc.x,
          v114->loc.y,
          v114->loc.z,
          (unsigned int)COERCE_UNSIGNED_INT64(v114->loc.x),
          v114->killerLoc.x,
          v114->killerLoc.y,
          v114->killerLoc.z,
          (const char *)COERCE_UNSIGNED_INT64(v114->loc.y),
          (const char *)COERCE_UNSIGNED_INT64(v114->loc.z));
        ++v112;
        ++v113;
      }
      while ( v112 < this->otherDeathInfo.num );
    }
    idFile::Printf(this: &v125, fmt: "---\n");
    idFile::Printf(this: &v125, fmt: "OTHER WEAPON FIRE INFORMATION:\n");
    idFile::Printf(this: &v125, fmt: "time\tentNum\tname\ttarget\tspread\tlocation\tdirection\tweapon\tprocectile\n");
    v115 = 0;
    if ( this->otherWeaponFireInfo.num > 0 )
    {
      v116 = 0;
      do
      {
        v117 = &this->otherWeaponFireInfo.list[v116];
        idFile::Printf(
          this: &v125,
          fmt: "%d\t%d\t%s\t%d\t%g\t%g %g %g\t%g %g %g\t%s\t%s\n",
          v117->timestamp,
          v117->attackerNum,
          v117->attackerName.data,
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v117->spread)),
          v117->spread,
          v117->start.x,
          v117->start.y,
          v117->start.z,
          v117->dir.x,
          v117->dir.y,
          v117->dir.z,
          (const char *)COERCE_UNSIGNED_INT64(v117->spread),
          (const char *)COERCE_UNSIGNED_INT64(v117->start.x));
        ++v115;
        ++v116;
      }
      while ( v115 < this->otherWeaponFireInfo.num );
    }
    idFile::Printf(this: &v125, fmt: "---\n");
    v118 = v124->__vftable;
    filePtr = v125.filePtr;
    v120 = (unsigned __int64)idFile_Memory::Length(this: &v125) >> 32;
    v118->Write(this: v124, a2: filePtr, a3: v120);
    ((void (__fastcall *)(idFile *, int))v124->dtr_idFile)(a1: v124, a2: 1);
  }
  idFile_Memory::~idFile_Memory(this: &v125);
}


// ========================================================================
// __unwind$226972_0
// EA  : 0x8268F910
// RVA : 0x0068F910
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_226972_0()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 960 + 256));
}


// ========================================================================
// __unwind$226973
// EA  : 0x8268F938
// RVA : 0x0068F938
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_226973()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 960 + 768));
}


// ========================================================================
// __unwind$226974
// EA  : 0x8268F960
// RVA : 0x0068F960
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_226974()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 960 + 608));
}


// ========================================================================
// __unwind$226975
// EA  : 0x8268F988
// RVA : 0x0068F988
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_226975()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 960 + 736));
}


// ========================================================================
// __unwind$226976
// EA  : 0x8268F9B0
// RVA : 0x0068F9B0
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_226976()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 960 + 672));
}


// ========================================================================
// __unwind$226977_0
// EA  : 0x8268F9D8
// RVA : 0x0068F9D8
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_226977_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 960 + 640));
}


// ========================================================================
// __unwind$226978
// EA  : 0x8268FA00
// RVA : 0x0068FA00
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_226978()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 960 + 704));
}


// ========================================================================
// ?ReadBinaryFile@idPlaytestStorage@@QAA_NABVidStr@@@Z
// EA  : 0x8268FC68
// RVA : 0x0068FC68
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

int __fastcall idPlaytestStorage::ReadBinaryFile(idPlaytestStorage *this, const idStr *fileName)
{
  int len; // r30
  int v5; // r29
  idFile *v6; // r3
  idFile *v7; // r30
  int version; // r11
  int *p_numPlayers; // r17
  int i; // r26
  int v11; // r11
  int j; // r26
  idPlaytestStorage::playerButtonInfo_t *list; // r27
  int v14; // r28
  int v15; // r24
  int k; // r26
  int m; // r27
  int n; // r26
  int ii; // r27
  int jj; // r26
  int kk; // r27
  int mm; // r22
  int nn; // r24
  idPlaytestStorage::playerButtonInfo_t *v24; // r26
  int v25; // r27
  int i1; // r23
  int i2; // r27
  testReportField_t *v28; // r26
  int size; // r27
  idPlaytestStorage::ai2FSMStateInfo_t *v30; // r24
  int i3; // r27
  int i4; // r26
  int i5; // r27
  int v34; // r11
  int i6; // r24
  char *v36; // r26
  int v37; // r27
  int i7; // r22
  idPlaytestStorage::playerButtonInfo_t *v39; // r23
  int v40; // r24
  int v41; // r27
  idStr *p_timestamp; // r26
  int i8; // r27
  int i9; // r24
  char *v45; // r26
  int v46; // r27
  int i10; // r24
  char *v48; // r26
  int v49; // r27
  int i11; // r24
  char *v51; // r27
  int v52; // r26
  int i12; // r27
  int i13; // r22
  idPlaytestStorage::playerButtonInfo_t *v55; // r23
  int v56; // r24
  int v57; // r27
  idPlaytestStorage::deathInfo_t *v58; // r26
  int i14; // r27
  int v60; // r22
  idPlaytestStorage::playerButtonInfo_t *v61; // r23
  int v62; // r24
  int v63; // r27
  idPlaytestStorage::weaponFireInfo_t *v64; // r26
  int i15; // r27
  int v66; // r11
  int i16; // r27
  int i17; // r27
  int i18; // r27
  idList<idPlaytestStorage::playerButtonInfo_t,5> v71; // [sp+50h] [-940h] BYREF
  int v72; // [sp+60h] [-930h] BYREF
  int v73; // [sp+64h] [-92Ch] BYREF
  int v74; // [sp+68h] [-928h] BYREF
  int v75; // [sp+6Ch] [-924h] BYREF
  int v76; // [sp+70h] [-920h] BYREF
  int v77; // [sp+74h] [-91Ch] BYREF
  int v78; // [sp+78h] [-918h] BYREF
  int v79; // [sp+7Ch] [-914h] BYREF
  int v80; // [sp+80h] [-910h] BYREF
  int v81; // [sp+84h] [-90Ch] BYREF
  int v82; // [sp+88h] [-908h] BYREF
  int v83; // [sp+8Ch] [-904h] BYREF
  int v84; // [sp+90h] [-900h] BYREF
  int v85; // [sp+94h] [-8FCh] BYREF
  int v86; // [sp+98h] [-8F8h] BYREF
  int v87; // [sp+9Ch] [-8F4h] BYREF
  int v88; // [sp+A0h] [-8F0h] BYREF
  int v89[3]; // [sp+A4h] [-8ECh] BYREF
  idPlaytestStorage::playerButtonInfo_t v90; // [sp+B0h] [-8E0h] BYREF
  int v91; // [sp+C0h] [-8D0h] BYREF
  int v92; // [sp+C4h] [-8CCh] BYREF
  int v93; // [sp+C8h] [-8C8h] BYREF
  int v94; // [sp+CCh] [-8C4h] BYREF
  int v95; // [sp+D0h] [-8C0h] BYREF
  int v96; // [sp+D4h] [-8BCh] BYREF
  int v97; // [sp+D8h] [-8B8h] BYREF
  int v98; // [sp+DCh] [-8B4h] BYREF
  int v99[4]; // [sp+E0h] [-8B0h] BYREF
  idPlaytestStorage::ai2StateInfo_t v100; // [sp+F0h] [-8A0h] BYREF
  idPlaytestStorage::inventoryInfo_t v101; // [sp+110h] [-880h] BYREF
  idPlaytestStorage::playerNormalBreadCrumbInfo_t v102; // [sp+130h] [-860h] BYREF
  idPlaytestStorage::aiVehicleBreadCrumbInfo_t v103; // [sp+170h] [-820h] BYREF
  idPlaytestStorage::ai2BreadCrumbInfo_t v104; // [sp+1B0h] [-7E0h] BYREF
  idPlaytestStorage::playerVehicleBreadCrumbInfo_t v105; // [sp+1F0h] [-7A0h] BYREF
  idPlaytestStorage::playerMiscControlBreadCrumbInfo_t v106; // [sp+230h] [-760h] BYREF
  idPlaytestStorage::playerVehicleBreadCrumbList_t v107; // [sp+260h] [-730h] BYREF
  idPlaytestStorage::useFocusInfo_t v108; // [sp+2A0h] [-6F0h] BYREF
  idPlaytestStorage::itemInfo_t v109; // [sp+2E0h] [-6B0h] BYREF
  idPlaytestStorage::equipItemInfo_t v110; // [sp+340h] [-650h] BYREF
  idPlaytestStorage::equipItemInfo_t v111; // [sp+390h] [-600h] BYREF
  idPlaytestStorage::radiusDamageInfo_t v112; // [sp+3E0h] [-5B0h] BYREF
  idStr v113; // [sp+460h] [-530h] BYREF
  idPlaytestStorage::deathInfo_t v114; // [sp+480h] [-510h] BYREF
  idPlaytestStorage::weaponFireInfo_t v115; // [sp+510h] [-480h] BYREF
  idPlaytestStorage::deathInfo_t v116; // [sp+5A0h] [-3F0h] BYREF
  idPlaytestStorage::weaponFireInfo_t v117; // [sp+630h] [-360h] BYREF
  idPlaytestStorage::inventoryElement_t v118; // [sp+6C0h] [-2D0h] BYREF
  testReportField_t v119; // [sp+710h] [-280h] BYREF
  idPlaytestStorage::aiVehicleInfo_t v120; // [sp+770h] [-220h] BYREF
  idPlaytestStorage::playerMiscControlBreadCrumbList_t v121; // [sp+7B0h] [-1E0h] BYREF
  idPlaytestStorage::playerMainBreadCrumbInfo_t v122; // [sp+7F0h] [-1A0h] BYREF
  idPlaytestStorage::ai2Info_t v123; // [sp+830h] [-160h] BYREF
  idPlaytestStorage::playerNormalBreadCrumbList_t v124; // [sp+890h] [-100h] BYREF

  idPlaytestStorage::FullClear(this);
  len = fileName->len;
  idStr::EnsureAlloced(this: &this->fileName, amount: fileName->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->fileName.data, Src: fileName->data, Size: len);
  v5 = 0;
  this->fileName.data[len] = 0;
  this->fileName.len = len;
  v6 = fileSystem->OpenFileRead(this: fileSystem, a2: fileName->data, a3: 1, a4: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v6->Read(this: v6, a2: &this->version, a3: 4u);
    version = this->version;
    if ( version <= 3 && version >= 1 )
    {
      if ( version >= 3 )
      {
        idFile::ReadString(this: v7, string: &this->buildVersionString);
        v7->Read(this: v7, a2: &this->buildNumberMajor, a3: 4u);
        v7->Read(this: v7, a2: &this->buildNumberMinor, a3: 4u);
        idFile::ReadString(this: v7, string: &this->machineName);
      }
      p_numPlayers = &this->numPlayers;
      v7->Read(this: v7, a2: &this->numPlayers, a3: 4u);
      v7->Read(this: v7, a2: &this->beginTime, a3: 4u);
      v7->Read(this: v7, a2: &this->lastTime, a3: 4u);
      idFile::ReadString(this: v7, string: &this->playMapName);
      if ( this->version >= 2 )
      {
        v7->Read(this: v7, a2: &this->numActiveLayers, a3: 4u);
        for ( i = 0; i < this->numActiveLayers; ++i )
        {
          v113.allocedAndFlag = 20;
          v113.len = 0;
          v113.data = v113.baseBuffer;
          v113.baseBuffer[0] = 0;
          idFile::ReadString(this: v7, string: &v113);
          if ( idList<idStr,5>::FindIndex(this: &this->activeLayers, obj: &v113, startIndex: 0) < 0 )
            idList<idStr,5>::Append(this: &this->activeLayers, obj: &v113);
          idStr::FreeData(this: &v113);
        }
      }
      v11 = *p_numPlayers;
      for ( j = 0; j < v11; v71.num = 0 )
      {
        list = nullptr;
        *(_WORD *)&v71.memTag = 1280;
        memset(&v71, 0, 14);
        v89[0] = 0;
        v7->Read(this: v7, a2: v89, a3: 4u);
        v14 = 0;
        if ( v89[0] > 0 )
        {
          do
          {
            v90.buttons = 0;
            v90.forwardmove = 0;
            v90.rightmove = 0;
            v90.upmove = 0;
            v90.timestamp = 0;
            v90.lastTimestamp = 0;
            v7->Read(this: v7, a2: &v90, a3: 4u);
            v7->Read(this: v7, a2: &v90.forwardmove, a3: 1u);
            v7->Read(this: v7, a2: &v90.rightmove, a3: 1u);
            v7->Read(this: v7, a2: &v90.upmove, a3: 1u);
            v7->Read(this: v7, a2: &v90.timestamp, a3: 4u);
            v7->Read(this: v7, a2: &v90.lastTimestamp, a3: 4u);
            idList<idPlaytestStorage::playerButtonInfo_t,5>::Append(this: &v71, obj: &v90);
            ++v14;
          }
          while ( v14 < v89[0] );
          list = v71.list;
        }
        idList<idList<idPlaytestStorage::playerButtonInfo_t,5>,5>::Append(this: &this->playerButtonInfo, obj: &v71);
        if ( v71.listStatic == 0 || v71.listStatic == 2 )
        {
          if ( list != nullptr )
            idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
          v71.list = nullptr;
          v71.size = 0;
        }
        v11 = *p_numPlayers;
        ++j;
      }
      v15 = 0;
      if ( v11 > 0 )
      {
        do
        {
          idPlaytestStorage::playerMainBreadCrumbInfo_t::playerMainBreadCrumbInfo_t(this: &v122);
          v7->Read(this: v7, a2: &v122, a3: 4u);
          v81 = 0;
          v7->Read(this: v7, a2: &v81, a3: 4u);
          for ( k = 0; k < v81; ++k )
          {
            idPlaytestStorage::playerNormalBreadCrumbList_t::playerNormalBreadCrumbList_t(this: &v124);
            v7->Read(this: v7, a2: &v124, a3: 1u);
            idFile::ReadString(this: v7, string: &v124.interactionName);
            idFile::ReadString(this: v7, string: &v124.interactionEntity);
            v82 = 0;
            v7->Read(this: v7, a2: &v82, a3: 4u);
            for ( m = 0; m < v82; ++m )
            {
              v102.combatHud = false;
              v102.isCrouching = false;
              v102.loc.y = vec3_origin.y;
              v102.count = 1;
              v102.dir = vec3_origin;
              v102.lastTimeStamp = 0;
              v102.loc.z = vec3_origin.z;
              v102.isCooking = false;
              v102.isZooming = false;
              v102.loc.x = vec3_origin.x;
              v102.mainAmmoCount = 0;
              v102.healthPercent = 0.0;
              v102.timestamp = 0;
              v102.speed = 0.0;
              v102.health = 0.0;
              v7->Read(this: v7, a2: &v102, a3: 12u);
              v7->Read(this: v7, a2: &v102.dir, a3: 12u);
              v7->Read(this: v7, a2: &v102.health, a3: 4u);
              v7->Read(this: v7, a2: &v102.healthPercent, a3: 4u);
              v7->Read(this: v7, a2: &v102.speed, a3: 4u);
              v7->Read(this: v7, a2: &v102.mainAmmoCount, a3: 4u);
              v7->Read(this: v7, a2: &v102.combatHud, a3: 1u);
              v7->Read(this: v7, a2: &v102.isCrouching, a3: 1u);
              v7->Read(this: v7, a2: &v102.isZooming, a3: 1u);
              v7->Read(this: v7, a2: &v102.isCooking, a3: 1u);
              v7->Read(this: v7, a2: &v102.count, a3: 4u);
              v7->Read(this: v7, a2: &v102.timestamp, a3: 4u);
              v7->Read(this: v7, a2: &v102.lastTimeStamp, a3: 4u);
              idList<idPlaytestStorage::playerNormalBreadCrumbInfo_t,5>::Append(this: &v124.breadCrumbs, obj: &v102);
            }
            idList<idPlaytestStorage::playerNormalBreadCrumbList_t,5>::Append(this: &v122.normalBreadCrumbs, obj: &v124);
            idPlaytestStorage::playerNormalBreadCrumbList_t::~playerNormalBreadCrumbList_t(this: &v124);
          }
          v86 = 0;
          v7->Read(this: v7, a2: &v86, a3: 4u);
          for ( n = 0; n < v86; ++n )
          {
            idPlaytestStorage::playerMiscControlBreadCrumbList_t::playerMiscControlBreadCrumbList_t(this: &v121);
            v7->Read(this: v7, a2: &v121.isInteraction, a3: 1u);
            idFile::ReadString(this: v7, string: &v121.controlName);
            v75 = 0;
            v7->Read(this: v7, a2: &v75, a3: 4u);
            for ( ii = 0; ii < v75; ++ii )
            {
              v106.timestamp = 0;
              v106.loc.z = vec3_origin.z;
              v106.lastTimeStamp = 0;
              v106.speed = 0.0;
              v106.count = 1;
              v106.dir.z = vec3_origin.z;
              v106.loc.y = vec3_origin.y;
              v106.loc.x = vec3_origin.x;
              v106.dir.x = vec3_origin.x;
              v106.dir.y = vec3_origin.y;
              v7->Read(this: v7, a2: &v106, a3: 12u);
              v7->Read(this: v7, a2: &v106.dir, a3: 12u);
              v7->Read(this: v7, a2: &v106.speed, a3: 4u);
              v7->Read(this: v7, a2: &v106.count, a3: 4u);
              v7->Read(this: v7, a2: &v106.timestamp, a3: 4u);
              v7->Read(this: v7, a2: &v106.lastTimeStamp, a3: 4u);
              idList<idPlaytestStorage::playerMiscControlBreadCrumbInfo_t,5>::Append(
                this: &v121.breadCrumbs,
                obj: &v106);
            }
            idList<idPlaytestStorage::playerMiscControlBreadCrumbList_t,5>::Append(
              this: &v122.miscBreadCrumbs,
              obj: &v121);
            if ( v121.breadCrumbs.listStatic == 0 || v121.breadCrumbs.listStatic == 2 )
            {
              if ( v121.breadCrumbs.list != nullptr )
                idMem::Free(this: &mem, ptr: v121.breadCrumbs.list, align: ALIGN_16);
              v121.breadCrumbs.list = nullptr;
              v121.breadCrumbs.size = 0;
            }
            v121.breadCrumbs.num = 0;
            idStr::FreeData(this: &v121.controlName);
          }
          v84 = 0;
          v7->Read(this: v7, a2: &v84, a3: 4u);
          for ( jj = 0; jj < v84; ++jj )
          {
            v107.vehicleName.allocedAndFlag = 20;
            v107.vehicleName.len = 0;
            v107.vehicleName.data = v107.vehicleName.baseBuffer;
            v107.vehicleName.baseBuffer[0] = 0;
            v107.breadCrumbs.memTag = 5;
            v107.breadCrumbs.listStatic = 0;
            memset(&v107.breadCrumbs, 0, 14);
            v107.isRCBomb = false;
            v7->Read(this: v7, a2: &v107.isRCBomb, a3: 1u);
            idFile::ReadString(this: v7, string: &v107.vehicleName);
            v77 = 0;
            v7->Read(this: v7, a2: &v77, a3: 4u);
            for ( kk = 0; kk < v77; ++kk )
            {
              v105.count = 1;
              v105.ammo = 0;
              v105.loc.z = vec3_origin.z;
              memset(&v105.timestamp, 0, 9);
              v105.speed = 0.0;
              v105.healthPercent = 1.0;
              v105.loc.x = vec3_origin.x;
              v105.loc.y = vec3_origin.y;
              v105.dir = vec3_origin;
              v105.boost = 0.0;
              v105.health = 0.0;
              v7->Read(this: v7, a2: &v105, a3: 12u);
              v7->Read(this: v7, a2: &v105.dir, a3: 12u);
              v7->Read(this: v7, a2: &v105.health, a3: 4u);
              v7->Read(this: v7, a2: &v105.healthPercent, a3: 4u);
              v7->Read(this: v7, a2: &v105.speed, a3: 4u);
              v7->Read(this: v7, a2: &v105.boost, a3: 4u);
              v7->Read(this: v7, a2: &v105.ammo, a3: 4u);
              v7->Read(this: v7, a2: &v105.count, a3: 4u);
              v7->Read(this: v7, a2: &v105.timestamp, a3: 4u);
              v7->Read(this: v7, a2: &v105.lastTimeStamp, a3: 4u);
              v7->Read(this: v7, a2: &v105.combatHud, a3: 1u);
              idList<idPlaytestStorage::playerVehicleBreadCrumbInfo_t,5>::Append(this: &v107.breadCrumbs, obj: &v105);
            }
            idList<idPlaytestStorage::playerVehicleBreadCrumbList_t,5>::Append(
              this: &v122.vehicleBreadCrumbs,
              obj: &v107);
            if ( v107.breadCrumbs.listStatic == 0 || v107.breadCrumbs.listStatic == 2 )
            {
              if ( v107.breadCrumbs.list != nullptr )
                idMem::Free(this: &mem, ptr: v107.breadCrumbs.list, align: ALIGN_16);
              v107.breadCrumbs.list = nullptr;
              v107.breadCrumbs.size = 0;
            }
            v107.breadCrumbs.num = 0;
            idStr::FreeData(this: &v107.vehicleName);
          }
          idList<idPlaytestStorage::playerMainBreadCrumbInfo_t,5>::Append(this: &this->playerBreadCrumbs, obj: &v122);
          idPlaytestStorage::playerMainBreadCrumbInfo_t::~playerMainBreadCrumbInfo_t(this: &v122);
          ++v15;
        }
        while ( v15 < *p_numPlayers );
      }
      v76 = 0;
      v7->Read(this: v7, a2: &v76, a3: 4u);
      for ( mm = 0; mm < v76; ++mm )
      {
        idPlaytestStorage::ai2Info_t::ai2Info_t(this: &v123);
        v7->Read(this: v7, a2: &v123.creationTimeStamp, a3: 4u);
        v7->Read(this: v7, a2: &v123, a3: 4u);
        v7->Read(this: v7, a2: &v123.isDormant, a3: 1u);
        idFile::ReadString(this: v7, string: &v123.entName);
        v88 = 0;
        v7->Read(this: v7, a2: &v88, a3: 4u);
        for ( nn = 0; nn < v88; v71.num = 0 )
        {
          v24 = nullptr;
          *(_WORD *)&v71.memTag = 1280;
          memset(&v71, 0, 14);
          v79 = 0;
          v7->Read(this: v7, a2: &v79, a3: 4u);
          v25 = 0;
          if ( v79 > 0 )
          {
            do
            {
              v104.isHostile = false;
              v104.isTalking = false;
              v104.count = 1;
              v104.loc.x = vec3_origin.x;
              v104.timestamp = 0;
              v104.loc.y = vec3_origin.y;
              v104.loc.z = vec3_origin.z;
              v104.dir = vec3_origin;
              v104.health = 0.0;
              v104.healthPercent = 1.0;
              v104.speed = 0.0;
              v7->Read(this: v7, a2: &v104.timestamp, a3: 4u);
              v7->Read(this: v7, a2: &v104.lastTimeStamp, a3: 4u);
              v7->Read(this: v7, a2: &v104.count, a3: 4u);
              v7->Read(this: v7, a2: &v104.isHostile, a3: 1u);
              v7->Read(this: v7, a2: &v104.isTalking, a3: 1u);
              v7->Read(this: v7, a2: &v104.health, a3: 4u);
              v7->Read(this: v7, a2: &v104.healthPercent, a3: 4u);
              v7->Read(this: v7, a2: &v104.speed, a3: 4u);
              v7->Read(this: v7, a2: &v104, a3: 12u);
              v7->Read(this: v7, a2: &v104.dir, a3: 12u);
              idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>::Append(
                this: (idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5> *)&v71,
                obj: &v104);
              ++v25;
            }
            while ( v25 < v79 );
            v24 = v71.list;
          }
          idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5>::Append(
            this: &v123.breadCrumbs,
            obj: (const idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5> *)&v71);
          if ( v71.listStatic == 0 || v71.listStatic == 2 )
          {
            if ( v24 != nullptr )
              idMem::Free(this: &mem, ptr: v24, align: ALIGN_16);
            v71.list = nullptr;
            v71.size = 0;
          }
          ++nn;
        }
        v73 = 0;
        v7->Read(this: v7, a2: &v73, a3: 4u);
        for ( i1 = 0; i1 < v73; v100.states.num = 0 )
        {
          v100.states.memTag = 5;
          v100.states.listStatic = 0;
          memset(&v100.states, 0, 14);
          v100.timestamp = -1;
          v100.lastTimeStamp = -1;
          v100.count = 1;
          v7->Read(this: v7, a2: &v100, a3: 4u);
          v7->Read(this: v7, a2: &v100.lastTimeStamp, a3: 4u);
          v7->Read(this: v7, a2: &v100.count, a3: 4u);
          v72 = 0;
          v7->Read(this: v7, a2: &v72, a3: 4u);
          for ( i2 = 0; i2 < v72; ++i2 )
          {
            v119.name.allocedAndFlag = 20;
            v119.name.data = v119.name.baseBuffer;
            v119.name.len = 0;
            v119.name.baseBuffer[0] = 0;
            v119.type.data = v119.type.baseBuffer;
            v119.type.len = 0;
            v119.type.baseBuffer[0] = 0;
            v119.value.data = v119.value.baseBuffer;
            v119.value.len = 0;
            v119.value.baseBuffer[0] = 0;
            v119.type.allocedAndFlag = 20;
            v119.value.allocedAndFlag = 20;
            idFile::ReadString(this: v7, string: &v119.name);
            idFile::ReadString(this: v7, string: &v119.type);
            idFile::ReadString(this: v7, string: &v119.value);
            idList<idPlaytestStorage::ai2FSMStateInfo_t,5>::Append(
              this: &v100.states,
              obj: (const idPlaytestStorage::ai2FSMStateInfo_t *)&v119);
            keyBindings_t::~keyBindings_t(this: &v119);
          }
          idList<idPlaytestStorage::ai2StateInfo_t,5>::Append(this: &v123.stateLog, obj: &v100);
          if ( v100.states.listStatic == 0 || v100.states.listStatic == 2 )
          {
            v28 = (testReportField_t *)v100.states.list;
            if ( v100.states.list != nullptr )
            {
              size = v100.states.size;
              v30 = v100.states.list;
              if ( v100.states.size > 0 )
              {
                do
                {
                  keyBindings_t::~keyBindings_t(this: v28);
                  --size;
                  ++v28;
                }
                while ( size != 0 );
              }
              idMem::Free(this: &mem, ptr: v30, align: ALIGN_16);
            }
            v100.states.list = nullptr;
            v100.states.size = 0;
          }
          ++i1;
        }
        v74 = 0;
        v7->Read(this: v7, a2: &v74, a3: 4u);
        for ( i3 = 0; i3 < v74; ++i3 )
        {
          v93 = 0;
          v7->Read(this: v7, a2: &v93, a3: 4u);
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&v123.dormantTimeStamps,
            obj: (const encounterGroupRole_t *)&v93);
        }
        idList<idPlaytestStorage::ai2Info_t,5>::Append(this: &this->ai2Info, obj: &v123);
        idPlaytestStorage::ai2Info_t::~ai2Info_t(this: &v123);
      }
      v80 = 0;
      v7->Read(this: v7, a2: &v80, a3: 4u);
      for ( i4 = 0; i4 < v80; ++i4 )
      {
        idPlaytestStorage::aiVehicleInfo_t::aiVehicleInfo_t(this: &v120);
        v7->Read(this: v7, a2: &v120.creationTimeStamp, a3: 4u);
        v7->Read(this: v7, a2: &v120, a3: 4u);
        idFile::ReadString(this: v7, string: &v120.entName);
        v78 = 0;
        v7->Read(this: v7, a2: &v78, a3: 4u);
        for ( i5 = 0; i5 < v78; ++i5 )
        {
          v103.count = 1;
          memset(&v103.timestamp, 0, 10);
          v103.dir.y = vec3_origin.y;
          v103.dir.z = vec3_origin.z;
          v103.ammo = 0;
          v103.health = 0.0;
          v103.healthPercent = 1.0;
          v103.speed = 0.0;
          v103.boost = 0.0;
          v103.loc.x = vec3_origin.x;
          v103.loc.y = vec3_origin.y;
          v103.loc.z = vec3_origin.z;
          v103.dir.x = vec3_origin.x;
          v7->Read(this: v7, a2: &v103, a3: 12u);
          v7->Read(this: v7, a2: &v103.dir, a3: 12u);
          v7->Read(this: v7, a2: &v103.health, a3: 4u);
          v7->Read(this: v7, a2: &v103.healthPercent, a3: 4u);
          v7->Read(this: v7, a2: &v103.speed, a3: 4u);
          v7->Read(this: v7, a2: &v103.boost, a3: 4u);
          v7->Read(this: v7, a2: &v103.ammo, a3: 4u);
          v7->Read(this: v7, a2: &v103.count, a3: 4u);
          v7->Read(this: v7, a2: &v103.timestamp, a3: 4u);
          v7->Read(this: v7, a2: &v103.lastTimeStamp, a3: 4u);
          v7->Read(this: v7, a2: &v103.hasCar, a3: 1u);
          v7->Read(this: v7, a2: &v103.isRCBomb, a3: 1u);
          idList<idPlaytestStorage::aiVehicleBreadCrumbInfo_t,5>::Append(this: &v120.breadCrumbs, obj: &v103);
        }
        idList<idPlaytestStorage::aiVehicleInfo_t,5>::Append(this: &this->aiVehicleInfo, obj: &v120);
        if ( v120.breadCrumbs.listStatic == 0 || v120.breadCrumbs.listStatic == 2 )
        {
          if ( v120.breadCrumbs.list != nullptr )
            idMem::Free(this: &mem, ptr: v120.breadCrumbs.list, align: ALIGN_16);
          v120.breadCrumbs.list = nullptr;
          v120.breadCrumbs.size = 0;
        }
        v120.breadCrumbs.num = 0;
        idStr::FreeData(this: &v120.entName);
      }
      v34 = *p_numPlayers;
      for ( i6 = 0; i6 < v34; v71.num = 0 )
      {
        v36 = nullptr;
        *(_WORD *)&v71.memTag = 1280;
        memset(&v71, 0, 14);
        v7->Read(this: v7, a2: &v95, a3: 4u);
        v37 = 0;
        if ( v95 > 0 )
        {
          do
          {
            v109.loc.x = vec3_origin.x;
            v109.loc.y = vec3_origin.y;
            v109.itemName.data = v109.itemName.baseBuffer;
            v109.loc.z = vec3_origin.z;
            v109.itemName.len = 0;
            v109.itemName.baseBuffer[0] = 0;
            v109.materialName.data = v109.materialName.baseBuffer;
            v109.materialName.len = 0;
            v109.materialName.baseBuffer[0] = 0;
            v109.count = 0;
            v109.timestamp = 0;
            v109.itemName.allocedAndFlag = 20;
            v109.materialName.allocedAndFlag = 20;
            v7->Read(this: v7, a2: &v109.timestamp, a3: 4u);
            v7->Read(this: v7, a2: &v109.count, a3: 4u);
            idFile::ReadString(this: v7, string: &v109.itemName);
            idFile::ReadString(this: v7, string: &v109.materialName);
            v7->Read(this: v7, a2: &v109, a3: 12u);
            idList<idPlaytestStorage::itemInfo_t,5>::Append(
              this: (idList<idPlaytestStorage::itemInfo_t,5> *)&v71,
              obj: &v109);
            idStr::FreeData(this: &v109.materialName);
            idStr::FreeData(this: &v109.itemName);
            ++v37;
          }
          while ( v37 < v95 );
          v36 = (char *)v71.list;
        }
        idList<idList<idPlaytestStorage::itemInfo_t,5>,5>::Append(
          this: &this->playerItemInfo,
          obj: (const idList<idPlaytestStorage::itemInfo_t,5> *)&v71);
        if ( v71.listStatic == 0 || v71.listStatic == 2 )
        {
          if ( v36 != nullptr )
            idListArrayDelete<idPlaytestStorage::itemInfo_t>(ptr: v36, num: v71.size);
          v71.list = nullptr;
          v71.size = 0;
        }
        v34 = *p_numPlayers;
        ++i6;
      }
      for ( i7 = 0; i7 < v34; v71.num = 0 )
      {
        v39 = nullptr;
        v40 = 0;
        *(_WORD *)&v71.memTag = 1280;
        memset(&v71, 0, 14);
        v7->Read(this: v7, a2: &v97, a3: 4u);
        v41 = 0;
        if ( v97 > 0 )
        {
          do
          {
            v108.focusName.len = 0;
            v108.focusName.data = v108.focusName.baseBuffer;
            v108.loc.x = vec3_origin.x;
            v108.loc.y = vec3_origin.y;
            v108.focusName.baseBuffer[0] = 0;
            v108.loc.z = vec3_origin.z;
            v108.timestamp = 0;
            v108.dir = vec3_origin;
            v108.focusName.allocedAndFlag = 20;
            v7->Read(this: v7, a2: &v108.timestamp, a3: 4u);
            v7->Read(this: v7, a2: &v108, a3: 12u);
            v7->Read(this: v7, a2: &v108.dir, a3: 12u);
            idFile::ReadString(this: v7, string: &v108.focusName);
            idList<idPlaytestStorage::useFocusInfo_t,5>::Append(
              this: (idList<idPlaytestStorage::useFocusInfo_t,5> *)&v71,
              obj: &v108);
            idStr::FreeData(this: &v108.focusName);
            ++v41;
          }
          while ( v41 < v97 );
          v40 = v71.size;
          v39 = v71.list;
        }
        idList<idList<idPlaytestStorage::useFocusInfo_t,5>,5>::Append(
          this: &this->playerUseFocusInfo,
          obj: (const idList<idPlaytestStorage::useFocusInfo_t,5> *)&v71);
        if ( v71.listStatic == 0 || v71.listStatic == 2 )
        {
          if ( v39 != nullptr )
          {
            if ( v40 > 0 )
            {
              p_timestamp = (idStr *)&v39[1].timestamp;
              for ( i8 = v40; i8 != 0; --i8 )
              {
                idStr::FreeData(this: p_timestamp);
                p_timestamp = (idStr *)((char *)p_timestamp + 60);
              }
            }
            idMem::Free(this: &mem, ptr: v39, align: ALIGN_16);
          }
          v71.list = nullptr;
          v71.size = 0;
        }
        v34 = *p_numPlayers;
        ++i7;
      }
      for ( i9 = 0; i9 < v34; v71.num = 0 )
      {
        v45 = nullptr;
        *(_WORD *)&v71.memTag = 1280;
        memset(&v71, 0, 14);
        v7->Read(this: v7, a2: v99, a3: 4u);
        v46 = 0;
        if ( v99[0] > 0 )
        {
          do
          {
            v111.loc.x = vec3_origin.x;
            v111.loc.y = vec3_origin.y;
            v111.equipedItemName.data = v111.equipedItemName.baseBuffer;
            v111.loc.z = vec3_origin.z;
            v111.equipedItemName.len = 0;
            v111.equipedItemName.baseBuffer[0] = 0;
            v111.equipedItemMaterial.data = v111.equipedItemMaterial.baseBuffer;
            v111.equipedItemMaterial.len = 0;
            v111.equipedItemMaterial.baseBuffer[0] = 0;
            v111.timestamp = 0;
            v111.equipedItemName.allocedAndFlag = 20;
            v111.equipedItemMaterial.allocedAndFlag = 20;
            v7->Read(this: v7, a2: &v111.timestamp, a3: 4u);
            v7->Read(this: v7, a2: &v111, a3: 12u);
            idFile::ReadString(this: v7, string: &v111.equipedItemName);
            idFile::ReadString(this: v7, string: &v111.equipedItemMaterial);
            idList<idPlaytestStorage::equipItemInfo_t,5>::Append(
              this: (idList<idPlaytestStorage::equipItemInfo_t,5> *)&v71,
              obj: &v111);
            idStr::FreeData(this: &v111.equipedItemMaterial);
            idStr::FreeData(this: &v111.equipedItemName);
            ++v46;
          }
          while ( v46 < v99[0] );
          v45 = (char *)v71.list;
        }
        idList<idList<idPlaytestStorage::quickItemInfo_t,5>,5>::Append(
          this: (idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5> *)&this->playerUseQuickItemInfo,
          obj: (const idList<idPlaytestStorage::equipItemInfo_t,5> *)&v71);
        if ( v71.listStatic == 0 || v71.listStatic == 2 )
        {
          if ( v45 != nullptr )
            idListArrayDelete<idPlaytestStorage::quickItemInfo_t>(ptr: v45, num: v71.size);
          v71.list = nullptr;
          v71.size = 0;
        }
        v34 = *p_numPlayers;
        ++i9;
      }
      for ( i10 = 0; i10 < v34; v71.num = 0 )
      {
        v48 = nullptr;
        *(_WORD *)&v71.memTag = 1280;
        memset(&v71, 0, 14);
        v7->Read(this: v7, a2: &v94, a3: 4u);
        v49 = 0;
        if ( v94 > 0 )
        {
          do
          {
            v110.loc.x = vec3_origin.x;
            v110.loc.y = vec3_origin.y;
            v110.equipedItemName.data = v110.equipedItemName.baseBuffer;
            v110.loc.z = vec3_origin.z;
            v110.equipedItemName.len = 0;
            v110.equipedItemName.baseBuffer[0] = 0;
            v110.equipedItemMaterial.data = v110.equipedItemMaterial.baseBuffer;
            v110.equipedItemMaterial.len = 0;
            v110.equipedItemMaterial.baseBuffer[0] = 0;
            v110.timestamp = 0;
            v110.equipedItemName.allocedAndFlag = 20;
            v110.equipedItemMaterial.allocedAndFlag = 20;
            v7->Read(this: v7, a2: &v110.timestamp, a3: 4u);
            v7->Read(this: v7, a2: &v110, a3: 12u);
            idFile::ReadString(this: v7, string: &v110.equipedItemName);
            idFile::ReadString(this: v7, string: &v110.equipedItemMaterial);
            idList<idPlaytestStorage::equipItemInfo_t,5>::Append(
              this: (idList<idPlaytestStorage::equipItemInfo_t,5> *)&v71,
              obj: &v110);
            idStr::FreeData(this: &v110.equipedItemMaterial);
            idStr::FreeData(this: &v110.equipedItemName);
            ++v49;
          }
          while ( v49 < v94 );
          v48 = (char *)v71.list;
        }
        idList<idList<idPlaytestStorage::quickItemInfo_t,5>,5>::Append(
          this: &this->playerEquipItemInfo,
          obj: (const idList<idPlaytestStorage::equipItemInfo_t,5> *)&v71);
        if ( v71.listStatic == 0 || v71.listStatic == 2 )
        {
          if ( v48 != nullptr )
            idListArrayDelete<idPlaytestStorage::quickItemInfo_t>(ptr: v48, num: v71.size);
          v71.list = nullptr;
          v71.size = 0;
        }
        v34 = *p_numPlayers;
        ++i10;
      }
      for ( i11 = 0; i11 < v34; v71.num = 0 )
      {
        v51 = nullptr;
        *(_WORD *)&v71.memTag = 1280;
        memset(&v71, 0, 14);
        v85 = 0;
        v7->Read(this: v7, a2: &v85, a3: 4u);
        v52 = 0;
        if ( v85 > 0 )
        {
          do
          {
            v101.inventoryList.memTag = 5;
            v101.inventoryList.listStatic = 0;
            v101.loc.x = vec3_origin.x;
            memset(&v101.inventoryList, 0, 14);
            v101.loc.y = vec3_origin.y;
            v101.loc.z = vec3_origin.z;
            v101.timestamp = -1;
            v7->Read(this: v7, a2: &v101, a3: 4u);
            v7->Read(this: v7, a2: &v101.loc, a3: 12u);
            v83 = 0;
            v7->Read(this: v7, a2: &v83, a3: 4u);
            for ( i12 = 0; i12 < v83; ++i12 )
            {
              v118.itemName.allocedAndFlag = 20;
              v118.itemName.data = v118.itemName.baseBuffer;
              v118.itemName.len = 0;
              v118.itemName.baseBuffer[0] = 0;
              v118.materialName.data = v118.materialName.baseBuffer;
              v118.materialName.len = 0;
              v118.materialName.baseBuffer[0] = 0;
              v118.count = 1;
              v118.materialName.allocedAndFlag = 20;
              v7->Read(this: v7, a2: &v118.count, a3: 4u);
              idFile::ReadString(this: v7, string: &v118.itemName);
              idFile::ReadString(this: v7, string: &v118.materialName);
              idList<idPlaytestStorage::inventoryElement_t,5>::Append(this: &v101.inventoryList, obj: &v118);
              idStr::FreeData(this: &v118.materialName);
              idStr::FreeData(this: &v118.itemName);
            }
            idList<idPlaytestStorage::inventoryInfo_t,5>::Append(
              this: (idList<idPlaytestStorage::inventoryInfo_t,5> *)&v71,
              obj: &v101);
            if ( v101.inventoryList.listStatic == 0 || v101.inventoryList.listStatic == 2 )
            {
              if ( v101.inventoryList.list != nullptr )
                idListArrayDelete<idDeclRollBones::idDeclRollBoneInstance>(
                  ptr: v101.inventoryList.list,
                  num: v101.inventoryList.size);
              v101.inventoryList.list = nullptr;
              v101.inventoryList.size = 0;
            }
            ++v52;
            v101.inventoryList.num = 0;
          }
          while ( v52 < v85 );
          v51 = (char *)v71.list;
        }
        idList<idList<idPlaytestStorage::inventoryInfo_t,5>,5>::Append(
          this: &this->playerInventoryInfo,
          obj: (const idList<idPlaytestStorage::inventoryInfo_t,5> *)&v71);
        if ( v71.listStatic == 0 || v71.listStatic == 2 )
        {
          if ( v51 != nullptr )
            idListArrayDelete<idPlaytestStorage::inventoryInfo_t>(ptr: v51, num: v71.size);
          v71.list = nullptr;
          v71.size = 0;
        }
        v34 = *p_numPlayers;
        ++i11;
      }
      for ( i13 = 0; i13 < v34; v71.num = 0 )
      {
        v55 = nullptr;
        v56 = 0;
        *(_WORD *)&v71.memTag = 1280;
        memset(&v71, 0, 14);
        v7->Read(this: v7, a2: &v98, a3: 4u);
        v57 = 0;
        if ( v98 > 0 )
        {
          do
          {
            v116.loc.x = vec3_origin.x;
            v116.loc.y = vec3_origin.y;
            v116.loc.z = vec3_origin.z;
            v116.killerLoc.x = vec3_origin.x;
            v116.entityName.data = v116.entityName.baseBuffer;
            v116.killerLoc.y = vec3_origin.y;
            v116.entityName.len = 0;
            v116.killerLoc.z = vec3_origin.z;
            v116.entityName.baseBuffer[0] = 0;
            v116.killerName.data = v116.killerName.baseBuffer;
            v116.killerName.len = 0;
            v116.killerName.baseBuffer[0] = 0;
            v116.damageName.data = v116.damageName.baseBuffer;
            v116.damageName.len = 0;
            v116.damageName.baseBuffer[0] = 0;
            v116.entityNum = -1;
            v116.killerEntityNum = -1;
            v116.timestamp = 0;
            v116.entityName.allocedAndFlag = 20;
            v116.killerName.allocedAndFlag = 20;
            v116.damageName.allocedAndFlag = 20;
            v7->Read(this: v7, a2: &v116.timestamp, a3: 4u);
            v7->Read(this: v7, a2: &v116.entityNum, a3: 4u);
            v7->Read(this: v7, a2: &v116, a3: 12u);
            v7->Read(this: v7, a2: &v116.killerEntityNum, a3: 4u);
            v7->Read(this: v7, a2: &v116.killerLoc, a3: 12u);
            idFile::ReadString(this: v7, string: &v116.killerName);
            idFile::ReadString(this: v7, string: &v116.damageName);
            idList<idPlaytestStorage::deathInfo_t,5>::Append(
              this: (idList<idPlaytestStorage::deathInfo_t,5> *)&v71,
              obj: &v116);
            idPlaytestStorage::deathInfo_t::~deathInfo_t(this: &v116);
            ++v57;
          }
          while ( v57 < v98 );
          v56 = v71.size;
          v55 = v71.list;
        }
        idList<idList<idPlaytestStorage::deathInfo_t,5>,5>::Append(
          this: &this->playerDeathInfo,
          obj: (const idList<idPlaytestStorage::deathInfo_t,5> *)&v71);
        if ( v71.listStatic == 0 || v71.listStatic == 2 )
        {
          if ( v55 != nullptr )
          {
            if ( v56 > 0 )
            {
              v58 = (idPlaytestStorage::deathInfo_t *)v55;
              for ( i14 = v56; i14 != 0; --i14 )
                idPlaytestStorage::deathInfo_t::~deathInfo_t(this: v58++);
            }
            idMem::Free(this: &mem, ptr: v55, align: ALIGN_16);
          }
          v71.list = nullptr;
          v71.size = 0;
        }
        v34 = *p_numPlayers;
        ++i13;
      }
      v60 = 0;
      if ( v34 > 0 )
      {
        do
        {
          v61 = nullptr;
          v62 = 0;
          *(_WORD *)&v71.memTag = 1280;
          memset(&v71, 0, 14);
          v7->Read(this: v7, a2: &v96, a3: 4u);
          v63 = 0;
          if ( v96 > 0 )
          {
            do
            {
              v117.spread = 0.0;
              v117.start.x = vec3_origin.x;
              v117.start.y = vec3_origin.y;
              v117.weaponName.allocedAndFlag = 20;
              v117.start.z = vec3_origin.z;
              v117.weaponName.data = v117.weaponName.baseBuffer;
              v117.dir = vec3_origin;
              v117.weaponName.len = 0;
              v117.weaponName.baseBuffer[0] = 0;
              v117.projectileName.data = v117.projectileName.baseBuffer;
              v117.projectileName.len = 0;
              v117.projectileName.baseBuffer[0] = 0;
              v117.attackerName.data = v117.attackerName.baseBuffer;
              v117.attackerName.len = 0;
              v117.attackerName.baseBuffer[0] = 0;
              v117.attackerNum = -1;
              v117.targetNum = -1;
              v117.timestamp = 0;
              v117.projectileName.allocedAndFlag = 20;
              v117.attackerName.allocedAndFlag = 20;
              v7->Read(this: v7, a2: &v117.timestamp, a3: 4u);
              v7->Read(this: v7, a2: &v117.attackerNum, a3: 4u);
              v7->Read(this: v7, a2: &v117.targetNum, a3: 4u);
              v7->Read(this: v7, a2: &v117.spread, a3: 4u);
              v7->Read(this: v7, a2: &v117.start, a3: 12u);
              v7->Read(this: v7, a2: &v117.dir, a3: 12u);
              idFile::ReadString(this: v7, string: &v117.weaponName);
              idFile::ReadString(this: v7, string: &v117.projectileName);
              idList<idPlaytestStorage::weaponFireInfo_t,5>::Append(
                this: (idList<idPlaytestStorage::weaponFireInfo_t,5> *)&v71,
                obj: &v117);
              idPlaytestStorage::weaponFireInfo_t::~weaponFireInfo_t(this: &v117);
              ++v63;
            }
            while ( v63 < v96 );
            v62 = v71.size;
            v61 = v71.list;
          }
          idList<idList<idPlaytestStorage::weaponFireInfo_t,5>,5>::Append(
            this: &this->playerWeaponFireInfo,
            obj: (const idList<idPlaytestStorage::weaponFireInfo_t,5> *)&v71);
          if ( v71.listStatic == 0 || v71.listStatic == 2 )
          {
            if ( v61 != nullptr )
            {
              if ( v62 > 0 )
              {
                v64 = (idPlaytestStorage::weaponFireInfo_t *)v61;
                for ( i15 = v62; i15 != 0; --i15 )
                  idPlaytestStorage::weaponFireInfo_t::~weaponFireInfo_t(this: v64++);
              }
              idMem::Free(this: &mem, ptr: v61, align: ALIGN_16);
            }
            v71.list = nullptr;
            v71.size = 0;
          }
          v66 = *p_numPlayers;
          ++v60;
          v71.num = 0;
        }
        while ( v60 < v66 );
      }
      v87 = 0;
      v7->Read(this: v7, a2: &v87, a3: 4u);
      for ( i16 = 0; i16 < v87; ++i16 )
      {
        v112.loc.x = vec3_origin.x;
        v112.loc.y = vec3_origin.y;
        v112.loc.z = vec3_origin.z;
        v112.radius = 1.0;
        v112.inflictorName.data = v112.inflictorName.baseBuffer;
        v112.minDamage = 0.0;
        v112.inflictorName.len = 0;
        v112.maxDamage = 0.0;
        v112.inflictorName.baseBuffer[0] = 0;
        v112.playerDamageScale = 0.0;
        v112.attackerName.data = v112.attackerName.baseBuffer;
        v112.attackerName.len = 0;
        v112.attackerName.baseBuffer[0] = 0;
        v112.damageDefName.data = v112.damageDefName.baseBuffer;
        v112.damageDefName.len = 0;
        v112.damageDefName.baseBuffer[0] = 0;
        v112.inflictorName.allocedAndFlag = 20;
        v112.attackerName.allocedAndFlag = 20;
        v112.damageDefName.allocedAndFlag = 20;
        v7->Read(this: v7, a2: &v112, a3: 12u);
        v7->Read(this: v7, a2: &v112.radius, a3: 4u);
        v7->Read(this: v7, a2: &v112.minDamage, a3: 4u);
        v7->Read(this: v7, a2: &v112.maxDamage, a3: 4u);
        v7->Read(this: v7, a2: &v112.playerDamageScale, a3: 4u);
        idFile::ReadString(this: v7, string: &v112.inflictorName);
        idFile::ReadString(this: v7, string: &v112.attackerName);
        idFile::ReadString(this: v7, string: &v112.damageDefName);
        v7->Read(this: v7, a2: &v112.timestamp, a3: 4u);
        idList<idPlaytestStorage::radiusDamageInfo_t,5>::Append(this: &this->radiusDamageInfo, obj: &v112);
        idPlaytestStorage::radiusDamageInfo_t::~radiusDamageInfo_t(this: &v112);
      }
      v7->Read(this: v7, a2: &v92, a3: 4u);
      for ( i17 = 0; i17 < v92; ++i17 )
      {
        v114.loc.x = vec3_origin.x;
        v114.loc.y = vec3_origin.y;
        v114.loc.z = vec3_origin.z;
        v114.killerLoc.x = vec3_origin.x;
        v114.entityName.data = v114.entityName.baseBuffer;
        v114.killerLoc.y = vec3_origin.y;
        v114.entityName.len = 0;
        v114.killerLoc.z = vec3_origin.z;
        v114.entityName.baseBuffer[0] = 0;
        v114.killerName.data = v114.killerName.baseBuffer;
        v114.killerName.len = 0;
        v114.killerName.baseBuffer[0] = 0;
        v114.damageName.data = v114.damageName.baseBuffer;
        v114.damageName.len = 0;
        v114.damageName.baseBuffer[0] = 0;
        v114.entityNum = -1;
        v114.killerEntityNum = -1;
        v114.timestamp = 0;
        v114.entityName.allocedAndFlag = 20;
        v114.killerName.allocedAndFlag = 20;
        v114.damageName.allocedAndFlag = 20;
        v7->Read(this: v7, a2: &v114.timestamp, a3: 4u);
        v7->Read(this: v7, a2: &v114.entityNum, a3: 4u);
        idFile::ReadString(this: v7, string: &v114.entityName);
        v7->Read(this: v7, a2: &v114, a3: 12u);
        v7->Read(this: v7, a2: &v114.killerEntityNum, a3: 4u);
        v7->Read(this: v7, a2: &v114.killerLoc, a3: 12u);
        idFile::ReadString(this: v7, string: &v114.killerName);
        idFile::ReadString(this: v7, string: &v114.damageName);
        idList<idPlaytestStorage::deathInfo_t,5>::Append(this: &this->otherDeathInfo, obj: &v114);
        idPlaytestStorage::deathInfo_t::~deathInfo_t(this: &v114);
      }
      v7->Read(this: v7, a2: &v91, a3: 4u);
      for ( i18 = 0; i18 < v91; ++i18 )
      {
        v115.spread = 0.0;
        v115.start.x = vec3_origin.x;
        v115.start.y = vec3_origin.y;
        v115.weaponName.allocedAndFlag = 20;
        v115.start.z = vec3_origin.z;
        v115.weaponName.data = v115.weaponName.baseBuffer;
        v115.dir = vec3_origin;
        v115.weaponName.len = 0;
        v115.weaponName.baseBuffer[0] = 0;
        v115.projectileName.data = v115.projectileName.baseBuffer;
        v115.projectileName.len = 0;
        v115.projectileName.baseBuffer[0] = 0;
        v115.attackerName.data = v115.attackerName.baseBuffer;
        v115.attackerName.len = 0;
        v115.attackerName.baseBuffer[0] = 0;
        v115.attackerNum = -1;
        v115.targetNum = -1;
        v115.timestamp = 0;
        v115.projectileName.allocedAndFlag = 20;
        v115.attackerName.allocedAndFlag = 20;
        v7->Read(this: v7, a2: &v115.timestamp, a3: 4u);
        v7->Read(this: v7, a2: &v115.attackerNum, a3: 4u);
        idFile::ReadString(this: v7, string: &v115.attackerName);
        v7->Read(this: v7, a2: &v115.targetNum, a3: 4u);
        v7->Read(this: v7, a2: &v115.spread, a3: 4u);
        v7->Read(this: v7, a2: &v115.start, a3: 12u);
        v7->Read(this: v7, a2: &v115.dir, a3: 12u);
        idFile::ReadString(this: v7, string: &v115.weaponName);
        idFile::ReadString(this: v7, string: &v115.projectileName);
        idList<idPlaytestStorage::weaponFireInfo_t,5>::Append(this: &this->otherWeaponFireInfo, obj: &v115);
        idPlaytestStorage::weaponFireInfo_t::~weaponFireInfo_t(this: &v115);
      }
      v5 = 1;
    }
    ((void (__fastcall *)(idFile *, int))v7->dtr_idFile)(a1: v7, a2: 1);
  }
  return v5;
}


// ========================================================================
// __unwind$240248
// EA  : 0x82692204
// RVA : 0x00692204
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240248()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2448 + 1120));
}


// ========================================================================
// __unwind$240249
// EA  : 0x8269222C
// RVA : 0x0069222C
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240249()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2448 + 80));
}


// ========================================================================
// __unwind$240250
// EA  : 0x82692254
// RVA : 0x00692254
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240250()
{
  int v0; // r12

  idPlaytestStorage::playerMainBreadCrumbInfo_t::~playerMainBreadCrumbInfo_t(this: (idPlaytestStorage::playerMainBreadCrumbInfo_t *)(v0 - 2448 + 2032));
}


// ========================================================================
// __unwind$240251
// EA  : 0x8269227C
// RVA : 0x0069227C
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240251()
{
  int v0; // r12

  idPlaytestStorage::playerNormalBreadCrumbList_t::~playerNormalBreadCrumbList_t(this: (idPlaytestStorage::playerNormalBreadCrumbList_t *)(v0 - 2448 + 2192));
}


// ========================================================================
// __unwind$240252
// EA  : 0x826922A4
// RVA : 0x006922A4
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240252()
{
  int v0; // r12

  idPlaytestStorage::playerVehicleBreadCrumbList_t::~playerVehicleBreadCrumbList_t(this: (idPlaytestStorage::playerMiscControlBreadCrumbList_t *)(v0 - 2448 + 1968));
}


// ========================================================================
// __unwind$240833
// EA  : 0x826922CC
// RVA : 0x006922CC
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240833()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2448 + 1968));
}


// ========================================================================
// __unwind$240903
// EA  : 0x826922F4
// RVA : 0x006922F4
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240903()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2448 + 608));
}


// ========================================================================
// __unwind$240253
// EA  : 0x8269231C
// RVA : 0x0069231C
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240253()
{
  int v0; // r12

  idPlaytestStorage::playerVehicleBreadCrumbList_t::~playerVehicleBreadCrumbList_t(this: (idPlaytestStorage::playerMiscControlBreadCrumbList_t *)(v0 - 2448 + 608));
}


// ========================================================================
// __unwind$241128
// EA  : 0x82692344
// RVA : 0x00692344
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_241128()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2448 + 608));
}


// ========================================================================
// __unwind$240254
// EA  : 0x8269236C
// RVA : 0x0069236C
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240254()
{
  int v0; // r12

  idPlaytestStorage::ai2Info_t::~ai2Info_t(this: (idPlaytestStorage::ai2Info_t *)(v0 - 2448 + 2096));
}


// ========================================================================
// __unwind$240255
// EA  : 0x82692394
// RVA : 0x00692394
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240255()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2448 + 80));
}


// ========================================================================
// __unwind$240256
// EA  : 0x826923BC
// RVA : 0x006923BC
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240256()
{
  int v0; // r12

  idPlaytestStorage::ai2StateInfo_t::~ai2StateInfo_t(this: (idPlaytestStorage::ai2StateInfo_t *)(v0 - 2448 + 240));
}


// ========================================================================
// __unwind$240257
// EA  : 0x826923E4
// RVA : 0x006923E4
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240257()
{
  int v0; // r12

  keyBindings_t::~keyBindings_t(this: (testReportField_t *)(v0 - 2448 + 1808));
}


// ========================================================================
// __unwind$240258
// EA  : 0x8269240C
// RVA : 0x0069240C
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240258()
{
  int v0; // r12

  idPlaytestStorage::aiVehicleInfo_t::~aiVehicleInfo_t(this: (idPlaytestStorage::aiVehicleInfo_t *)(v0 - 2448 + 1904));
}


// ========================================================================
// __unwind$241943
// EA  : 0x82692434
// RVA : 0x00692434
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_241943()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2448 + 1908));
}


// ========================================================================
// __unwind$240259
// EA  : 0x82692460
// RVA : 0x00692460
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240259()
{
  int v0; // r12

  idList<idPlaytestStorage::itemInfo_t,5>::Clear(this: (idList<idPlaytestStorage::itemInfo_t,5> *)(v0 - 2448 + 80));
}


// ========================================================================
// __unwind$240260_0
// EA  : 0x82692488
// RVA : 0x00692488
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240260_0()
{
  int v0; // r12

  idPlaytestStorage::itemInfo_t::~itemInfo_t(this: (idPlaytestStorage::itemInfo_t *)(v0 - 2448 + 736));
}


// ========================================================================
// __unwind$242128
// EA  : 0x826924B0
// RVA : 0x006924B0
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_242128()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2448 + 748));
}


// ========================================================================
// __unwind$240261
// EA  : 0x826924DC
// RVA : 0x006924DC
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240261()
{
  int v0; // r12

  idList<idPlaytestStorage::useFocusInfo_t,5>::~idList<idPlaytestStorage::useFocusInfo_t,5>(this: (idList<idPlaytestStorage::useFocusInfo_t,5> *)(v0 - 2448 + 80));
}


// ========================================================================
// __unwind$240262
// EA  : 0x82692504
// RVA : 0x00692504
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240262()
{
  int v0; // r12

  idPlaytestStorage::useFocusInfo_t::~useFocusInfo_t(this: (idPlaytestStorage::useFocusInfo_t *)(v0 - 2448 + 672));
}


// ========================================================================
// __unwind$240263
// EA  : 0x8269252C
// RVA : 0x0069252C
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240263()
{
  int v0; // r12

  idList<idPlaytestStorage::quickItemInfo_t,5>::Clear(this: (idList<idPlaytestStorage::equipItemInfo_t,5> *)(v0 - 2448 + 80));
}


// ========================================================================
// __unwind$240264
// EA  : 0x82692554
// RVA : 0x00692554
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240264()
{
  int v0; // r12

  idPlaytestStorage::equipItemInfo_t::~equipItemInfo_t(this: (idPlaytestStorage::equipItemInfo_t *)(v0 - 2448 + 912));
}


// ========================================================================
// __unwind$242536
// EA  : 0x8269257C
// RVA : 0x0069257C
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_242536()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2448 + 924));
}


// ========================================================================
// __unwind$240265
// EA  : 0x826925A8
// RVA : 0x006925A8
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240265()
{
  int v0; // r12

  idList<idPlaytestStorage::quickItemInfo_t,5>::Clear(this: (idList<idPlaytestStorage::equipItemInfo_t,5> *)(v0 - 2448 + 80));
}


// ========================================================================
// __unwind$240266
// EA  : 0x826925D0
// RVA : 0x006925D0
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240266()
{
  int v0; // r12

  idPlaytestStorage::equipItemInfo_t::~equipItemInfo_t(this: (idPlaytestStorage::equipItemInfo_t *)(v0 - 2448 + 832));
}


// ========================================================================
// __unwind$242680
// EA  : 0x826925F8
// RVA : 0x006925F8
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_242680()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2448 + 844));
}


// ========================================================================
// __unwind$240267
// EA  : 0x82692624
// RVA : 0x00692624
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240267()
{
  int v0; // r12

  idList<idPlaytestStorage::inventoryInfo_t,5>::~idList<idPlaytestStorage::inventoryInfo_t,5>(this: (idList<idPlaytestStorage::inventoryInfo_t,5> *)(v0 - 2448 + 80));
}


// ========================================================================
// __unwind$240268
// EA  : 0x8269264C
// RVA : 0x0069264C
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240268()
{
  int v0; // r12

  idPlaytestStorage::inventoryInfo_t::~inventoryInfo_t(this: (idPlaytestStorage::inventoryInfo_t *)(v0 - 2448 + 272));
}


// ========================================================================
// __unwind$240269
// EA  : 0x82692674
// RVA : 0x00692674
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240269()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 2448 + 1728));
}


// ========================================================================
// __unwind$242872
// EA  : 0x8269269C
// RVA : 0x0069269C
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_242872()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2448 + 1728));
}


// ========================================================================
// __unwind$240270
// EA  : 0x826926C4
// RVA : 0x006926C4
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240270()
{
  int v0; // r12

  idList<idPlaytestStorage::deathInfo_t,5>::~idList<idPlaytestStorage::deathInfo_t,5>(this: (idList<idPlaytestStorage::deathInfo_t,5> *)(v0 - 2448 + 80));
}


// ========================================================================
// __unwind$240271
// EA  : 0x826926EC
// RVA : 0x006926EC
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240271()
{
  int v0; // r12

  idPlaytestStorage::deathInfo_t::~deathInfo_t(this: (idPlaytestStorage::deathInfo_t *)(v0 - 2448 + 1440));
}


// ========================================================================
// __unwind$240272
// EA  : 0x82692714
// RVA : 0x00692714
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240272()
{
  int v0; // r12

  idList<idPlaytestStorage::weaponFireInfo_t,5>::Clear(this: (idList<idPlaytestStorage::weaponFireInfo_t,5> *)(v0 - 2448 + 80));
}


// ========================================================================
// __unwind$240273
// EA  : 0x8269273C
// RVA : 0x0069273C
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240273()
{
  int v0; // r12

  idPlaytestStorage::weaponFireInfo_t::~weaponFireInfo_t(this: (idPlaytestStorage::weaponFireInfo_t *)(v0 - 2448 + 1584));
}


// ========================================================================
// __unwind$240274
// EA  : 0x82692764
// RVA : 0x00692764
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240274()
{
  int v0; // r12

  idPlaytestStorage::radiusDamageInfo_t::~radiusDamageInfo_t(this: (idPlaytestStorage::radiusDamageInfo_t *)(v0 - 2448 + 992));
}


// ========================================================================
// __unwind$240275
// EA  : 0x8269278C
// RVA : 0x0069278C
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240275()
{
  int v0; // r12

  idPlaytestStorage::deathInfo_t::~deathInfo_t(this: (idPlaytestStorage::deathInfo_t *)(v0 - 2448 + 1152));
}


// ========================================================================
// __unwind$240276
// EA  : 0x826927B4
// RVA : 0x006927B4
// PDB : w:\tech5\engine\framework\playteststorage2.cpp
// ========================================================================

void _unwind_240276()
{
  int v0; // r12

  idPlaytestStorage::weaponFireInfo_t::~weaponFireInfo_t(this: (idPlaytestStorage::weaponFireInfo_t *)(v0 - 2448 + 1296));
}

