
// ========================================================================
// ?ResetSnapshots@idRenderWorldLocal@@UAAXXZ
// EA  : 0x82966940
// RVA : 0x00966940
// PDB : w:\tech5\engine\renderer\renderworld_state.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::ResetSnapshots(idRenderWorldLocal *this)
{
  int v1; // r9
  int v2; // r11
  idRenderModel *v3; // r10
  int v4; // r9
  int v5; // r11
  idRenderLight *v6; // r10

  v1 = 0;
  if ( this->renderModels.num > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this->renderModels.list[v2];
      if ( v3 != nullptr )
        v3->needWriteToSnapshot = true;
      ++v1;
      ++v2;
    }
    while ( v1 < this->renderModels.num );
  }
  v4 = 0;
  if ( this->renderLights.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this->renderLights.list[v5];
      if ( v6 != nullptr )
        v6->needWriteToSnapshot = true;
      ++v4;
      ++v5;
    }
    while ( v4 < this->renderLights.num );
  }
}


// ========================================================================
// ?SaveGame@idRenderWorldLocal@@UAAXPAVidFile@@@Z
// EA  : 0x829669C0
// RVA : 0x009669C0
// PDB : w:\tech5\engine\renderer\renderworld_state.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::SaveGame(idRenderWorldLocal *this, idFile *fp)
{
  idFile_vtbl *v3; // r10
  int v5; // r29
  int v6; // r25
  int v7; // r26
  idRenderModel *v8; // r27
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  idFile_vtbl *v10; // r10
  int v11; // r25
  int v12; // r26
  idRenderLight *v13; // r27
  unsigned int (__fastcall *v14)(idFile *, const void *, unsigned int); // ctr
  idFile_vtbl *v15; // r10
  int i; // r28
  char v17; // [sp+50h] [-60h] BYREF
  char v18; // [sp+51h] [-5Fh] BYREF
  char v19; // [sp+52h] [-5Eh] BYREF
  char v20; // [sp+53h] [-5Dh] BYREF
  int num; // [sp+54h] [-5Ch] BYREF
  int v22; // [sp+58h] [-58h] BYREF
  int v23; // [sp+5Ch] [-54h] BYREF

  v3 = fp->__vftable;
  num = this->renderModels.num;
  v3->Write(this: fp, a2: &num, a3: 4u);
  v5 = 0;
  v6 = 0;
  if ( this->renderModels.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = this->renderModels.list[v7];
      Write = fp->Write;
      if ( v8 != nullptr )
      {
        v18 = 1;
        Write(this: fp, a2: &v18, a3: 1u);
        idFile::WriteString(this: fp, string: v8->name.str);
        v8->Save(this: v8, a2: fp);
      }
      else
      {
        v17 = 0;
        Write(this: fp, a2: &v17, a3: 1u);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->renderModels.num );
  }
  v10 = fp->__vftable;
  v22 = this->renderLights.num;
  v10->Write(this: fp, a2: &v22, a3: 4u);
  v11 = 0;
  if ( this->renderLights.num > 0 )
  {
    v12 = 0;
    do
    {
      v13 = this->renderLights.list[v12];
      v14 = fp->Write;
      if ( v13 != nullptr )
      {
        v20 = 1;
        v14(this: fp, a2: &v20, a3: 1u);
        idRenderLight::Save(this: v13, fp);
      }
      else
      {
        v19 = 0;
        v14(this: fp, a2: &v19, a3: 1u);
      }
      ++v11;
      ++v12;
    }
    while ( v11 < this->renderLights.num );
  }
  v15 = fp->__vftable;
  v23 = this->dynamicEnvironments.num;
  v15->Write(this: fp, a2: &v23, a3: 4u);
  for ( i = 0; i < this->dynamicEnvironments.num; ++v5 )
  {
    fp->Write(this: fp, a2: &this->dynamicEnvironments.list[v5], a3: 24u);
    idFile::WriteString(this: fp, string: this->dynamicEnvironments.list[v5].env->name.str);
    ++i;
  }
}


// ========================================================================
// ?WriteToSnapshot@idRenderWorldLocal@@UBAXAAVidSnapShot@@PBV2@@Z
// EA  : 0x82966BB8
// RVA : 0x00966BB8
// PDB : w:\tech5\engine\renderer\renderworld_state.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::WriteToSnapshot(idRenderWorldLocal *this, idSnapShot *ss, idSnapShot *oldss)
{
  unsigned __int64 v3; // r30
  int v7; // r15
  idStaticList<idRenderLight *,4096> *p_serializedLights; // r27
  int v9; // r14
  int v10; // r28
  idLobbyBase *v11; // r3
  __int64 v12; // r3
  double clockTicks; // fp30
  __int64 v14; // r3
  idConsole_vtbl *v15; // r27
  double v16; // fp30
  unsigned int v17; // r3
  int v18; // r3
  int v19; // r23
  int v20; // r25
  int v21; // r27
  int v22; // r28
  int NetworkID; // r3
  int i; // r29
  int v25; // r30
  __int64 v26; // r5
  idConsole_vtbl *v27; // r29
  int v28; // r30
  unsigned int v29; // r3
  idBitMsg v30; // [sp+50h] [-2050h] BYREF
  idStaticList<idRenderLight *,4096> *v31; // [sp+78h] [-2028h]
  __int64 v32; // [sp+80h] [-2020h]
  idSerializer v33; // [sp+88h] [-2018h] BYREF
  idTimer v34; // [sp+90h] [-2010h] BYREF
  _BYTE v35[4080]; // [sp+B0h] [-1FF0h] BYREF

  LODWORD(v3) = 0;
  memset(&v30.curSize, 0, 18);
  v30.tempValue = v3;
  v30.writeData = v35;
  v30.readData = v35;
  v30.maxSize = 8000;
  idBitMsg::WriteBits(this: &v30, value: 0, numBits: 8);
  idSnapShot::S_AddObject(
    this: ss,
    objectNum: 10020,
    visMask: 0xFFFFFFFF,
    data: (const char *)v30.readData,
    _size: (v30.writeBit != 0) + v30.curSize,
    tag: nullptr);
  v7 = 0;
  if ( this->serializedLights.num > 0 )
  {
    p_serializedLights = &this->serializedLights;
    v31 = &this->serializedLights;
    v9 = 0;
    do
    {
      HIDWORD(v3) = p_serializedLights->list[v9];
      if ( HIDWORD(v3) != 0 )
      {
        if ( *(_BYTE *)(HIDWORD(v3) + 1059) != 0 )
        {
          this->MarkLightSerialized(this, a2: p_serializedLights->list[v9], a3: false, a4: false);
        }
        else
        {
          v10 = idRenderLight::GetIndex(this: p_serializedLights->list[v9]) + 10021;
          if ( oldss == nullptr || *(_BYTE *)(HIDWORD(v3) + 1058) != 0 )
          {
LABEL_11:
            *(_BYTE *)(HIDWORD(v3) + 1058) = 0;
            v34.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
            v34.clockTicks = v3;
            v34.state = TS_STARTED;
            LODWORD(v12) = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v34.start = v12;
            v30.writeData = v35;
            v30.readData = v35;
            v30.maxSize = 8000;
            memset(&v30.curSize, 0, 18);
            v30.tempValue = v3;
            v33.writing = true;
            v33.msg = &v30;
            idRenderLight::SerializeSnapshot(this: (idRenderLight *)HIDWORD(v3), ser: &v33);
            idSnapShot::S_AddObject(
              this: ss,
              objectNum: v10,
              visMask: 0xFFFFFFFF,
              data: (const char *)v30.readData,
              _size: (v30.writeBit != 0) + v30.curSize,
              tag: "lights");
            idTimer::Stop(this: &v34);
            if ( com_drawSnapshots.valueInteger == 3 )
            {
              clockTicks = (float)v34.clockTicks;
              LODWORD(v14) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
              v32 = v14;
              v15 = console->__vftable;
              HIDWORD(v3) = (v30.writeBit != 0) + v30.curSize;
              v16 = (float)((float)clockTicks / (float)((float)v14 * (float)0.001));
              v17 = idSnapShot::CompareObject(this: ss, oldss, objectNum: v10, start: 0, end: 0, oldStart: 0);
              v15->AddSnapObject(this: console, a2: "lights", a3: HIDWORD(v3), a4: v17, a5: v16);
              p_serializedLights = v31;
            }
            v34.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
            goto LABEL_14;
          }
          v11 = session->GetActingGameStateLobbyBase(this: session);
          if ( v11->AllPeersHaveStaleSnapObj(this: v11, a2: v10) )
          {
            this->MarkLightSerialized(this, a2: (idRenderLight *)HIDWORD(v3), a3: false, a4: false);
          }
          else if ( (unsigned __int8)idSnapShot::CopyObject(this: ss, oldss, objectNum: v10, forceStale: true) == 0 )
          {
            goto LABEL_11;
          }
        }
      }
LABEL_14:
      ++v7;
      ++v9;
    }
    while ( v7 < this->serializedLights.num );
  }
  v18 = Sys_Milliseconds();
  v30.maxSize = 8000;
  v30.writeData = v35;
  v19 = v18;
  v30.readData = v35;
  memset(&v30.curSize, 0, 18);
  v30.tempValue = v3;
  idBitMsg::WriteBits(this: &v30, value: this->dynamicEnvironments.num, numBits: 8);
  v20 = 0;
  if ( this->dynamicEnvironments.num > 0 )
  {
    v21 = 0;
    v22 = 0;
    do
    {
      NetworkID = idResource::GetNetworkID(this: &this->dynamicEnvironments.list[v22].env->idDecl, alloc: true);
      idBitMsg::WriteBits(this: &v30, value: NetworkID, numBits: -16);
      for ( i = 0; i < 6; ++i )
      {
        v31 = *((idStaticList<idRenderLight *,4096> **)&this->dynamicEnvironments.list[v21].bounds.b[0].x + i);
        idBitMsg::WriteBits(this: &v30, value: (int)v31, numBits: 32);
      }
      ++v20;
      ++v22;
      ++v21;
    }
    while ( v20 < this->dynamicEnvironments.num );
  }
  v25 = Sys_Milliseconds();
  idSnapShot::S_AddObject(
    this: ss,
    objectNum: 15020,
    visMask: 0xFFFFFFFF,
    data: (const char *)v30.readData,
    _size: (v30.writeBit != 0) + v30.curSize,
    tag: nullptr);
  if ( com_drawSnapshots.valueInteger == 3 )
  {
    LODWORD(v26) = v25 - v19;
    v32 = v26;
    v27 = console->__vftable;
    v28 = (v30.writeBit != 0) + v30.curSize;
    v29 = idSnapShot::CompareObject(this: ss, oldss, objectNum: 15020, start: 0, end: 0, oldStart: 0);
    v27->AddSnapObject(this: console, a2: "environments", a3: v28, a4: v29, a5: (float)v32);
  }
}


// ========================================================================
// __unwind$230423
// EA  : 0x82967058
// RVA : 0x00967058
// PDB : w:\tech5\engine\renderer\renderworld_state.cpp
// ========================================================================

void _unwind_230423()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 8352 + 144));
}


// ========================================================================
// ?LoadGame@idRenderWorldLocal@@UAA_NPAVidFile@@@Z
// EA  : 0x82967088
// RVA : 0x00967088
// PDB : w:\tech5\engine\renderer\renderworld_state.cpp
// ========================================================================

int __fastcall idRenderWorldLocal::LoadGame(idRenderWorldLocal *this, idFile *fp)
{
  idFile_vtbl *v2; // r11
  int v5; // r29
  int v6; // r28
  idRenderModel *v7; // r30
  int v8; // r29
  int v9; // r28
  idRenderLight *v10; // r3
  idRenderLight *v11; // r30
  int v13; // r4
  idStaticList<dynamicEnvironment_t,128> *p_dynamicEnvironments; // r29
  int v15; // r30
  char v16; // r3
  int size; // r11
  int v18; // r28
  int i; // r30
  const idDecl *v20; // r3
  char v21; // [sp+50h] [-C0h] BYREF
  _BYTE v22[3]; // [sp+51h] [-BFh] BYREF
  int v23; // [sp+54h] [-BCh] BYREF
  int v24; // [sp+58h] [-B8h] BYREF
  idRenderLight *v25; // [sp+5Ch] [-B4h] BYREF
  idStr v26; // [sp+60h] [-B0h] BYREF
  idStr v27[4]; // [sp+80h] [-90h] BYREF

  v2 = fp->__vftable;
  v23 = 0;
  if ( v2->Read(this: fp, a2: &v23, a3: 4u) == 0 )
    return 0;
  v25 = nullptr;
  idList<idRenderModelCommitted *,5>::SetNum(
    this: (idList<int,5> *)&this->renderModels,
    newNum: v23,
    initValue: (int *)&v25);
  v5 = 0;
  if ( v23 > 0 )
  {
    v6 = 0;
    while ( fp->Read(this: fp, a2: &v21, a3: 1u) != 0 )
    {
      if ( v21 != 0 )
      {
        v26.allocedAndFlag = 20;
        v26.len = 0;
        v26.data = v26.baseBuffer;
        v26.baseBuffer[0] = 0;
        if ( idFile::ReadString(this: fp, string: &v26) == 0 )
        {
          idStr::FreeData(this: &v26);
          return 0;
        }
        v7 = this->renderModels.list[v6];
        if ( v7 == nullptr && (v7 = this->AllocRenderModel(this, a2: v26.data, a3: 1, a4: v5)) == nullptr
          || !v7->Load(this: v7, a2: fp) )
        {
          idStr::FreeData(this: &v26);
          return 0;
        }
        if ( !v7->unlinked )
          idRenderModel::CommitThisFrame(this: v7);
        idStr::FreeData(this: &v26);
      }
      ++v5;
      ++v6;
      if ( v5 >= v23 )
        goto LABEL_14;
    }
    return 0;
  }
LABEL_14:
  if ( fp->Read(this: fp, a2: &v23, a3: 4u) == 0 )
    return 0;
  v25 = nullptr;
  idList<idRenderModelCommitted *,5>::SetNum(
    this: (idList<int,5> *)&this->renderLights,
    newNum: v23,
    initValue: (int *)&v25);
  v8 = 0;
  if ( v23 > 0 )
  {
    v9 = 0;
    while ( fp->Read(this: fp, a2: v22, a3: 1u) != 0 )
    {
      if ( v22[0] != 0 )
      {
        v10 = (idRenderLight *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x430u,
                                 tag: TAG_RENDERMODEL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
        v25 = v10;
        if ( v10 != nullptr )
          v11 = idRenderLight::idRenderLight(this: v10);
        else
          v11 = nullptr;
        this->renderLights.list[v9] = v11;
        v11->committed->world = this;
        v11->committed->index.index = (1 << (v8 & 7)) | (v8 << 8);
        if ( (unsigned __int8)idRenderLight::Load(this: v11, fp) == 0 )
          return 0;
        if ( !v11->unlinked )
          idRenderLight::CommitThisFrame(this: v11);
      }
      ++v8;
      ++v9;
      if ( v8 >= v23 )
        goto LABEL_30;
    }
    return 0;
  }
LABEL_30:
  if ( fp->Read(this: fp, a2: &v24, a3: 4u) == 0 )
    return 0;
  v13 = v24;
  p_dynamicEnvironments = &this->dynamicEnvironments;
  v15 = v24;
  if ( v24 <= this->dynamicEnvironments.size
    || (v16 = idList<dynamicEnvironment_t,5>::Resize(this: &this->dynamicEnvironments, newsize: v24), v13 = v24, v16 != 0) )
  {
    size = this->dynamicEnvironments.size;
    if ( v15 < size )
      size = v15;
    this->dynamicEnvironments.num = size;
  }
  v18 = 0;
  if ( v13 <= 0 )
    return 1;
  for ( i = 0; ; ++i )
  {
    v27[0].allocedAndFlag = 20;
    v27[0].len = 0;
    v27[0].data = v27[0].baseBuffer;
    v27[0].baseBuffer[0] = 0;
    if ( fp->Read(this: fp, a2: &p_dynamicEnvironments->list[i], a3: 24u) == 0
      || idFile::ReadString(this: fp, string: v27) == 0 )
    {
      break;
    }
    if ( v27[0].data != nullptr )
      v20 = idDeclInfo::FindWithInheritance(this: &idDeclEnv::resourceList, name: v27[0].data, makeDefault: true);
    else
      v20 = nullptr;
    p_dynamicEnvironments->list[i].env = (const idDeclEnv *)v20;
    idStr::FreeData(this: v27);
    if ( ++v18 >= v24 )
      return 1;
  }
  idStr::FreeData(this: v27);
  return 0;
}


// ========================================================================
// __unwind$230806_0
// EA  : 0x82967490
// RVA : 0x00967490
// PDB : w:\tech5\engine\renderer\renderworld_state.cpp
// ========================================================================

void _unwind_230806_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$230807_0
// EA  : 0x829674B8
// RVA : 0x009674B8
// PDB : w:\tech5\engine\renderer\renderworld_state.cpp
// ========================================================================

void _unwind_230807_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 272 + 92), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$230808
// EA  : 0x829674E4
// RVA : 0x009674E4
// PDB : w:\tech5\engine\renderer\renderworld_state.cpp
// ========================================================================

void _unwind_230808()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// ?ReadFromSnapshot@idRenderWorldLocal@@UAAXAAVidSnapShot@@PBV2@@Z
// EA  : 0x82967518
// RVA : 0x00967518
// PDB : w:\tech5\engine\renderer\renderworld_state.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::ReadFromSnapshot(idRenderWorldLocal *this, idSnapShot *ss, idSnapShot *oldss)
{
  unsigned __int64 v3; // r26
  int ObjectIndexByID; // r30
  int v8; // r3
  int v9; // r20
  int v10; // r24
  int ObjectMsgByIndex; // r3
  int v12; // r28
  int num; // r11
  idStaticList<idRenderLight *,4096> *p_renderLights; // r29
  idRenderLight **list; // r11
  int v16; // r30
  idRenderLight *v17; // r9
  char v18; // r10
  idRenderLight *v19; // r3
  idRenderLight *v20; // r3
  int v21; // r3
  idConsole_vtbl *v22; // r29
  int v23; // r30
  unsigned int v24; // r3
  unsigned __int8 v25; // r3
  int v26; // r30
  idStaticList<dynamicEnvironment_t,128> *p_dynamicEnvironments; // r29
  int size; // r11
  int v29; // r27
  int v30; // r28
  int i; // r25
  __int16 v32; // r3
  dynamicEnvironment_t *v33; // r30
  const idDeclEnv *v34; // r3
  int j; // r30
  float v36; // r3
  dynamicEnvironment_t *v37; // r10
  int v38; // r9
  idConsole_vtbl *v39; // r29
  int v40; // r30
  unsigned int v41; // r3
  float v42[2]; // [sp+50h] [-100h] BYREF
  idSerializer v43; // [sp+58h] [-F8h] BYREF
  idBitMsg v44; // [sp+60h] [-F0h] BYREF
  idBitMsg v45; // [sp+90h] [-C0h] BYREF

  ObjectIndexByID = idSnapShot::FindObjectIndexByID(this: ss, objectNum: 10020);
  v8 = idSnapShot::FindObjectIndexByID(this: ss, objectNum: 15020);
  v9 = v8;
  if ( ObjectIndexByID != -1 && v8 != -1 )
  {
    LODWORD(v3) = 0;
    v10 = ObjectIndexByID;
    if ( ObjectIndexByID < v8 )
    {
      HIDWORD(v3) = "lights";
      do
      {
        memset(&v44, 0, 30);
        v44.tempValue = v3;
        ObjectMsgByIndex = idSnapShot::GetObjectMsgByIndex(this: ss, i: v10, msg: &v44, ignoreIfStale: false);
        v12 = ObjectMsgByIndex - 10021;
        if ( ObjectMsgByIndex != 10020 )
        {
          num = this->renderLights.num;
          v42[0] = 0.0;
          if ( num <= v12 + 1 )
            num = v12 + 1;
          p_renderLights = &this->renderLights;
          idList<idRenderModelCommitted *,5>::SetNum(
            this: (idList<int,5> *)&this->renderLights,
            newNum: num,
            initValue: (int *)v42);
          list = this->renderLights.list;
          v16 = v12;
          v17 = list[v12];
          if ( v17 == nullptr || (v18 = 0, !v17->skipAutoReplication) )
            v18 = 1;
          if ( v18 == 0 )
          {
            idLib::Error(fmt: "Light skipping replication in invalid slot");
            _LN121();
            return;
          }
          if ( (v44.writeBit != 0) + v44.curSize != 0 )
          {
            if ( v17 == nullptr )
            {
              v19 = (idRenderLight *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x430u,
                                       tag: TAG_RENDERMODEL,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
              v42[0] = *(float *)&v19;
              if ( v19 != nullptr )
                v20 = idRenderLight::idRenderLight(this: v19);
              else
                v20 = nullptr;
              p_renderLights->list[v16] = v20;
              p_renderLights->list[v16]->committed->world = this;
              p_renderLights->list[v16]->committed->index.index = (1 << (v12 & 7)) | (v12 << 8);
LABEL_21:
              v21 = idSnapShot::ObjectChangedCountByIndex(this: ss, i: v10);
              if ( v21 != p_renderLights->list[v16]->serializedChangeCount )
              {
                p_renderLights->list[v16]->serializedChangeCount = v21;
                v43.writing = false;
                v43.msg = &v44;
                idRenderLight::SerializeSnapshot(this: p_renderLights->list[v16], ser: &v43);
                if ( com_drawSnapshots.valueInteger == 3 )
                {
                  v22 = console->__vftable;
                  v23 = (v44.writeBit != 0) + v44.curSize;
                  v24 = idSnapShot::CompareObject(
                          this: ss,
                          oldss,
                          objectNum: v12 + 10021,
                          start: 0,
                          end: 0,
                          oldStart: 0);
                  v22->AddSnapObject(this: console, a2: "lights", a3: v23, a4: v24, a5: 0.0);
                }
              }
              goto LABEL_24;
            }
            if ( !list[v16]->deleteOnSync )
              goto LABEL_21;
          }
          else if ( v17 != nullptr )
          {
            idRenderLight::Delete(this: list[v16]);
          }
        }
LABEL_24:
        ++v10;
      }
      while ( v10 < v9 );
    }
    memset(&v45, 0, 30);
    v45.tempValue = v3;
    idSnapShot::GetObjectMsgByIndex(this: ss, i: v9, msg: &v45, ignoreIfStale: false);
    v25 = idBitMsg::ReadBits(this: &v45, numBits: 8);
    v26 = v25;
    p_dynamicEnvironments = &this->dynamicEnvironments;
    if ( v25 <= this->dynamicEnvironments.size
      || (unsigned __int8)idList<dynamicEnvironment_t,5>::Resize(this: &this->dynamicEnvironments, newsize: v25) != 0 )
    {
      size = this->dynamicEnvironments.size;
      if ( v26 < size )
        size = v26;
      this->dynamicEnvironments.num = size;
    }
    if ( v26 > 0 )
    {
      v29 = 0;
      v30 = 0;
      for ( i = v26; i != 0; --i )
      {
        v32 = idBitMsg::ReadBits(this: &v45, numBits: -16);
        v33 = &p_dynamicEnvironments->list[v30];
        idResourceList::GetNetworkResource(networkID: v32);
        v33->env = v34;
        for ( j = 0; j < 6; ++j )
        {
          v36 = COERCE_FLOAT(idBitMsg::ReadBits(this: &v45, numBits: 32));
          v37 = p_dynamicEnvironments->list;
          v38 = 4 * (v29 + j);
          v42[0] = v36;
          *(float *)((char *)&v37->bounds.b[0].x + v38) = v36;
        }
        ++v30;
        v29 += 7;
      }
    }
    if ( com_drawSnapshots.valueInteger == 3 )
    {
      v39 = console->__vftable;
      v40 = (v45.writeBit != 0) + v45.curSize;
      v41 = idSnapShot::CompareObject(this: ss, oldss, objectNum: 15020, start: 0, end: 0, oldStart: 0);
      v39->AddSnapObject(this: console, a2: "environments", a3: v40, a4: v41, a5: 0.0);
    }
  }
}


// ========================================================================
// $LN121
// EA  : 0x82967944
// RVA : 0x00967944
// PDB : w:\tech5\engine\renderer\renderworld_state.cpp
// ========================================================================

void _LN121()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 336 + 80), tag: TAG_RENDERMODEL);
}

