
// ========================================================================
// ?Stop@idEntityAnimRecorder@@UAAXXZ
// EA  : 0x82C46208
// RVA : 0x00C46208
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall idEntityAnimRecorder::Stop(idEntityAnimRecorder *this)
{
  idAnimRecorder::Stop(this);
  this->activeEntityNumber = -1;
  this->activeEntity = nullptr;
}


// ========================================================================
// ?ReadFrames@idEntityAnimRecorder@@UAAXH@Z
// EA  : 0x82C46248
// RVA : 0x00C46248
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall idEntityAnimRecorder::ReadFrames(idEntityAnimRecorder *this, int numFrames)
{
  idQuat *p_orientation; // r29
  idVec3 *p_position; // r28
  int i; // r30

  if ( numFrames > 0 )
  {
    p_orientation = &this->orientation;
    p_position = &this->position;
    for ( i = numFrames; i != 0; --i )
    {
      idAnimRecorder::ValidateFile(this, writing: false);
      idAnimRecorder::ValidateBlock(this, expectedBlockType: 3u);
      this->compressor->Read(this: this->compressor, a2: p_orientation, a3: 16u);
      this->compressor->Read(this: this->compressor, a2: p_position, a3: 12u);
      idAnimRecorder::ValidateBlock(this, expectedBlockType: 5u);
      idAnimRecorder::ReadFrames(this, numFrames: 1);
    }
  }
}


// ========================================================================
// ?RecordEntity@idEntityAnimRecorder@@QAAXAAVidEntity@@@Z
// EA  : 0x82C462E8
// RVA : 0x00C462E8
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall idEntityAnimRecorder::RecordEntity(idEntityAnimRecorder *this, idEntity *entity)
{
  idAnimStack *v4; // r3
  idTreeAnimator *treeAnimator; // r11
  int entityNumber; // r11
  idAnimStack *v7; // r3

  v4 = entity->GetAnimStack_2(this: entity);
  if ( v4 != nullptr )
    treeAnimator = v4->treeAnimator;
  else
    treeAnimator = nullptr;
  if ( treeAnimator != nullptr && treeAnimator->decl != nullptr )
  {
    entityNumber = entity->entityNumber;
    this->activeEntity = entity;
    this->activeEntityNumber = entityNumber;
    v7 = entity->GetAnimStack_2(this: entity);
    idAnimRecorder::RecordAnimStack(this, animStack: v7);
  }
  else
  {
    idLib::Warning(
      fmt: "idEntityAnimRecorder::RecordEntity - entity \"%s\" doesn't have a valid idDeclMD6",
      entity->name.data);
    this->Stop(this);
  }
}


// ========================================================================
// ?PlaybackEntity@idEntityAnimRecorder@@QAAXAAVidEntity@@@Z
// EA  : 0x82C463B0
// RVA : 0x00C463B0
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall idEntityAnimRecorder::PlaybackEntity(idEntityAnimRecorder *this, idEntity *entity)
{
  idAnimStack *v4; // r3
  idTreeAnimator *treeAnimator; // r11
  int entityNumber; // r11
  idAnimStack *v7; // r3

  v4 = entity->GetAnimStack_2(this: entity);
  if ( v4 != nullptr )
    treeAnimator = v4->treeAnimator;
  else
    treeAnimator = nullptr;
  if ( treeAnimator != nullptr && treeAnimator->decl != nullptr )
  {
    entityNumber = entity->entityNumber;
    this->activeEntity = entity;
    this->activeEntityNumber = entityNumber;
    v7 = entity->GetAnimStack_2(this: entity);
    idAnimRecorder::PlaybackAnimStack(this, animStack: v7);
  }
  else
  {
    idLib::Warning(
      fmt: "idEntityAnimRecorder::PlaybackEntity - entity \"%s\" doesn't have a valid idDeclMD6",
      entity->name.data);
    this->Stop(this);
  }
}


// ========================================================================
// ?WriteHeaderBlock@idEntityAnimRecorder@@MAAXXZ
// EA  : 0x82C46480
// RVA : 0x00C46480
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall idEntityAnimRecorder::WriteHeaderBlock(idEntityAnimRecorder *this)
{
  idFile *v2; // r3
  idAnimStack *activeAnimStack; // r11
  idTreeAnimator *treeAnimator; // r11
  const idDeclMD6 *decl; // r11
  unsigned __int8 *str; // r30
  unsigned __int8 *v7; // r11
  int v8; // r10
  char v9[4]; // [sp+50h] [-30h] BYREF
  idFileLocal v10; // [sp+54h] [-2Ch] BYREF
  unsigned int v11; // [sp+58h] [-28h] BYREF
  unsigned int v12[3]; // [sp+5Ch] [-24h] BYREF

  idAnimRecorder::WriteHeaderBlock(this);
  v2 = fileSystem->OpenFileAppend(this: fileSystem, a2: idAnimRecorder::inputFileName, a3: 0);
  v10.file = v2;
  if ( v2 == nullptr )
  {
    this->activeSerializer = nullptr;
    idLib::Error(fmt: "idEntityAnimRecorder::WriteHeaderBlock - Couldn't open file");
  }
  v9[0] = 4;
  v2->Write(this: v2, a2: v9, a3: 1u);
  v10.file->Write(this: v10.file, a2: &idEntityAnimRecorder::version, a3: 4u);
  activeAnimStack = this->activeAnimStack;
  if ( activeAnimStack != nullptr )
    treeAnimator = activeAnimStack->treeAnimator;
  else
    treeAnimator = nullptr;
  if ( treeAnimator != nullptr )
    decl = treeAnimator->decl;
  else
    decl = nullptr;
  if ( decl == nullptr )
    idLib::Error(
      fmt: "idEntityAnimRecorder::WriteHeaderBlock - entity \"%s\" doesn't have a valid idDeclMD6",
      this->activeEntity->name.data);
  str = (unsigned __int8 *)decl->name.str;
  v7 = str;
  do
    v8 = *v7++;
  while ( v8 != 0 );
  v11 = v7 - str;
  v10.file->Write(this: v10.file, a2: &v11, a3: 4u);
  v10.file->Write(this: v10.file, a2: str, a3: v11);
  v12[0] = v11 + 4;
  v10.file->Write(this: v10.file, a2: v12, a3: 4u);
  idFileLocal::~idFileLocal(this: &v10);
}


// ========================================================================
// $LN45_1
// EA  : 0x82C46618
// RVA : 0x00C46618
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void _LN45_1()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 128 + 84));
}


// ========================================================================
// ?Serialize@idEntityAnimRecorder@@UAAXAAHAAVidGameTimeManager@@_N@Z
// EA  : 0x82C46640
// RVA : 0x00C46640
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall idEntityAnimRecorder::Serialize(
        idEntityAnimRecorder *this,
        int *gameTime,
        idGameTimeManager *gameTimeManager,
        bool writing)
{
  idQuat *v8; // r3
  double w; // fp11
  idCompressor *compressor; // r3
  idEntity_vtbl *v11; // r30
  idMat3 *v12; // r3
  char v13; // [sp+50h] [-90h] BYREF
  char v14[15]; // [sp+51h] [-8Fh] BYREF
  idMat3 v15[3]; // [sp+60h] [-80h] BYREF

  if ( this->activeEntity == nullptr )
    idLib::Error(fmt: "idEntityAnimRecorder::Serialize - NULL entity");
  if ( writing )
  {
    idAnimRecorder::ValidateFile(this, writing: true);
    this->activeEntity->GetModelTransform(this: this->activeEntity, a2: &this->position, a3: (idMat3 *)&v15[0].mat[1].y);
    v8 = idMat3::ToQuat(this: v15, result: (idQuat *)&v15[0].mat[1].y);
    this->orientation.x = v8->x;
    this->orientation.y = v8->y;
    this->orientation.z = v8->z;
    w = v8->w;
    v13 = 3;
    this->orientation.w = w;
    this->compressor->Write(this: this->compressor, a2: &v13, a3: 1u);
    this->compressor->Write(this: this->compressor, a2: &this->orientation, a3: 16u);
    this->compressor->Write(this: this->compressor, a2: &this->position, a3: 12u);
    compressor = this->compressor;
    v14[0] = 5;
    compressor->Write(this: compressor, a2: v14, a3: 1u);
  }
  idAnimRecorder::Serialize(this, gameTime, gameTimeManager, writing);
  if ( !writing )
  {
    v11 = this->activeEntity->__vftable;
    v12 = idQuat::ToMat3(this: (idQuat *)&v15[0].mat[1].y, result: (idMat3 *)&this->orientation);
    v11->SetAxis(this: this->activeEntity, a2: v12);
    idEntity::SetOrigin(this: this->activeEntity, org: &this->position);
  }
}


// ========================================================================
// ?anim_recordEntity_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C467B8
// RVA : 0x00C467B8
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall anim_recordEntity_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v2; // r3
  int v3; // r3
  idLinkList<idEntity> *v4; // r11
  idEntity *owner; // r31
  idLinkList<idEntity> *next; // r11
  idAnimRecorder *v7; // r3
  idEntityAnimRecorder *Instance; // r3

  argc = args->argc;
  if ( args->argc == 1 || argc > 2 )
  {
    idLib::Printf(fmt: "USAGE: anim_recordEntity <entity number>\n");
  }
  else
  {
    if ( argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v3 = atol(nptr: v2);
    if ( v3 >= 0
      && gameLocal != nullptr
      && (v4 = gameLocal->spawnedEntities.next) != nullptr
      && v4 != gameLocal->spawnedEntities.head
      && (owner = v4->owner) != nullptr )
    {
      while ( owner->entityNumber != v3 )
      {
        next = owner->spawnNode.next;
        if ( next != nullptr && next != owner->spawnNode.head )
        {
          owner = next->owner;
          if ( owner != nullptr )
            continue;
        }
        goto LABEL_15;
      }
      Instance = (idEntityAnimRecorder *)idAnimRecorder::GetInstance();
      idEntityAnimRecorder::RecordEntity(this: Instance, entity: owner);
    }
    else
    {
LABEL_15:
      v7 = idAnimRecorder::instance;
      if ( idAnimRecorder::instance == nullptr )
      {
        v7 = idAnimRecorder::allocFunction();
        idAnimRecorder::instance = v7;
      }
      v7->Stop(this: v7);
    }
  }
}


// ========================================================================
// ?anim_playbackEntity_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C468F8
// RVA : 0x00C468F8
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall anim_playbackEntity_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v2; // r3
  int v3; // r3
  idLinkList<idEntity> *v4; // r11
  idEntity *owner; // r31
  idLinkList<idEntity> *next; // r11
  idAnimRecorder *v7; // r3
  idEntityAnimRecorder *Instance; // r3

  argc = args->argc;
  if ( args->argc == 1 || argc > 2 )
  {
    idLib::Printf(fmt: "USAGE: anim_playbackEntity <entity number>\n");
  }
  else
  {
    if ( argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v3 = atol(nptr: v2);
    if ( v3 >= 0
      && gameLocal != nullptr
      && (v4 = gameLocal->spawnedEntities.next) != nullptr
      && v4 != gameLocal->spawnedEntities.head
      && (owner = v4->owner) != nullptr )
    {
      while ( owner->entityNumber != v3 )
      {
        next = owner->spawnNode.next;
        if ( next != nullptr && next != owner->spawnNode.head )
        {
          owner = next->owner;
          if ( owner != nullptr )
            continue;
        }
        goto LABEL_15;
      }
      Instance = (idEntityAnimRecorder *)idAnimRecorder::GetInstance();
      idEntityAnimRecorder::PlaybackEntity(this: Instance, entity: owner);
    }
    else
    {
LABEL_15:
      v7 = idAnimRecorder::instance;
      if ( idAnimRecorder::instance == nullptr )
      {
        v7 = idAnimRecorder::allocFunction();
        idAnimRecorder::instance = v7;
      }
      v7->Stop(this: v7);
    }
  }
}


// ========================================================================
// ?anim_stop_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C46A38
// RVA : 0x00C46A38
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall anim_stop_f(const idCmdArgs *args)
{
  idAnimRecorder *v1; // r3

  if ( args->argc == 1 )
  {
    v1 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v1 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v1;
    }
    v1->Stop(this: v1);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: anim_stop\n");
  }
}


// ========================================================================
// ?anim_pausePlayback_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C46AC0
// RVA : 0x00C46AC0
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall anim_pausePlayback_f(const idCmdArgs *args)
{
  idAnimRecorder *v1; // r3

  if ( args->argc == 1 )
  {
    v1 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v1 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v1;
    }
    v1->isPaused = (_cntlzw(v1->isPaused) & 0x20) != 0;
  }
  else
  {
    idLib::Printf(fmt: "USAGE: anim_pausePlayback\n");
  }
}


// ========================================================================
// ?anim_frameStepPlayback_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C46B48
// RVA : 0x00C46B48
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall anim_frameStepPlayback_f(const idCmdArgs *args)
{
  idAnimRecorder *v2; // r11
  int v3; // r30
  const char *v4; // r3
  int v5; // r3
  idAnimRecorder *v6; // r3

  if ( args->argc <= 2 )
  {
    v2 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v2 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v2;
    }
    if ( v2->recordingFileMode == RECORDING_FILE_READ )
    {
      if ( args->argc == 1 )
      {
        v3 = 1;
      }
      else
      {
        if ( args->argc <= 1 )
          v4 = &byte_8200D768;
        else
          v4 = args->argv[1];
        v5 = atol(nptr: v4);
        v2 = idAnimRecorder::instance;
        v3 = v5;
      }
      if ( v2 == nullptr )
      {
        v2 = idAnimRecorder::allocFunction();
        idAnimRecorder::instance = v2;
      }
      v2->isPaused = true;
      v6 = idAnimRecorder::instance;
      if ( idAnimRecorder::instance == nullptr )
      {
        v6 = idAnimRecorder::allocFunction();
        idAnimRecorder::instance = v6;
      }
      v6->ReadFrames(this: v6, a2: v3);
    }
  }
  else
  {
    idLib::Printf(fmt: "USAGE: anim_frameStepPlayback [entity number]\n");
  }
}


// ========================================================================
// ?ReadHeaderBlock@idEntityAnimRecorder@@MAA_NXZ
// EA  : 0x82C46C40
// RVA : 0x00C46C40
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

BOOL __fastcall idEntityAnimRecorder::ReadHeaderBlock(idEntityAnimRecorder *this)
{
  idFile *file; // r3
  idFile *v4; // r3
  idAnimStack *activeAnimStack; // r11
  idTreeAnimator *treeAnimator; // r11
  const idDeclMD6 *decl; // r11
  const char *str; // r30
  unsigned int v9; // r30
  int v10; // r4
  unsigned int v11; // r3
  char v12; // r11
  BOOL v13; // r31
  unsigned __int8 v14[4]; // [sp+50h] [-130h] BYREF
  unsigned int v15; // [sp+54h] [-12Ch] BYREF
  int v16; // [sp+58h] [-128h] BYREF
  int v17; // [sp+5Ch] [-124h] BYREF
  char v18[288]; // [sp+60h] [-120h] BYREF

  if ( !idAnimRecorder::ReadHeaderBlock(this) )
    return false;
  file = this->file;
  v14[0] = 2;
  file->Read(this: file, a2: v14, a3: 1u);
  if ( v14[0] != 4 )
  {
    idLib::Warning(fmt: "idEntityAnimRecorder::ReadHeaderBlock - Wrong block type");
    return false;
  }
  v4 = this->file;
  v16 = -1;
  v4->Read(this: v4, a2: &v16, a3: 4u);
  if ( v16 != 1 )
  {
    idLib::Warning(fmt: "idEntityAnimRecorder::ReadHeaderBlock - File is version %i. Expected version is %i.", v16, 1);
    return false;
  }
  activeAnimStack = this->activeAnimStack;
  if ( activeAnimStack != nullptr )
    treeAnimator = activeAnimStack->treeAnimator;
  else
    treeAnimator = nullptr;
  if ( treeAnimator != nullptr )
    decl = treeAnimator->decl;
  else
    decl = nullptr;
  if ( decl == nullptr )
    idLib::Error(
      fmt: "idEntityAnimRecorder::WriteHeaderBlock - entity \"%s\" doesn't have a valid idDeclMD6",
      this->activeEntity->name.data);
  str = decl->name.str;
  v15 = -1;
  this->file->Read(this: this->file, a2: &v15, a3: 4u);
  this->file->Read(this: this->file, a2: v18, a3: v15);
  if ( idStr::Icmp(s1: v18, s2: str) != 0 )
  {
    idLib::Warning(
      fmt: "idEntityAnimRecorder::WriteHeaderBlock - Trying to apply a recording for \"%s\" on an entity using \"%s\"",
      v18,
      str);
    return false;
  }
  else
  {
    v17 = -1;
    v9 = v14[0] + v15;
    this->file->Read(this: this->file, a2: &v17, a3: 4u);
    v10 = this->file->Tell(this: this->file);
    v11 = v17 - v9;
    this->dataStart = v10;
    v12 = _cntlzw(v11);
    v13 = (v12 & 0x20) != 0;
    if ( (v12 & 0x20) == 0 )
      idLib::Warning(fmt: "idAnimRecorder::ReadHeaderBlock - Wrong end block marker");
    return v13;
  }
}


// ========================================================================
// ?AllocInstance@idEntityAnimRecorder@@KAPAVidAnimRecorder@@XZ
// EA  : 0x82C46E98
// RVA : 0x00C46E98
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

idAnimRecorder *__fastcall idEntityAnimRecorder::AllocInstance()
{
  idAnimRecorder *v0; // r3
  idAnimRecorder *v1; // r30

  v0 = (idAnimRecorder *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 0x560u,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  idAnimRecorder::idAnimRecorder(this: v0);
  *(_DWORD *)&v1[1].buffer.ptr[24] = -1;
  v1->__vftable = (idAnimRecorder_vtbl *)&idEntityAnimRecorder::`vftable';
  *(_DWORD *)&v1[1].buffer.ptr[28] = 0;
  return v1;
}


// ========================================================================
// __unwind$488322
// EA  : 0x82C46F2C
// RVA : 0x00C46F2C
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

void __fastcall _unwind_488322(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// `dynamic initializer for 'anim_recordEntity_v''
// EA  : 0x83376B48
// RVA : 0x01376B48
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_recordEntity_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_recordEntity_v,
           cmdName: "anim_recordEntity",
           function: anim_recordEntity_f,
           description: "Record animation state for a specific entity number",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'anim_playbackEntity_v''
// EA  : 0x83376B70
// RVA : 0x01376B70
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_playbackEntity_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_playbackEntity_v,
           cmdName: "anim_playbackEntity",
           function: anim_playbackEntity_f,
           description: "Playback animation recording for a specific entity number",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'anim_stop_v''
// EA  : 0x83376B98
// RVA : 0x01376B98
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_stop_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_stop_v,
           cmdName: "anim_stop",
           function: anim_stop_f,
           description: "Stops the animation recording or playback",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'anim_pausePlayback_v''
// EA  : 0x83376BC0
// RVA : 0x01376BC0
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_pausePlayback_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_pausePlayback_v,
           cmdName: "anim_pausePlayback",
           function: anim_pausePlayback_f,
           description: "Toggles pause state of animation recording playback",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'anim_frameStepPlayback_v''
// EA  : 0x83376BE8
// RVA : 0x01376BE8
// PDB : w:\tech5\tungsten\game\entities\entityanimrecorder.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_frameStepPlayback_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_frameStepPlayback_v,
           cmdName: "anim_frameStepPlayback",
           function: anim_frameStepPlayback_f,
           description: "Frame steps through the animation recording playback",
           argCompletion: nullptr);
}

