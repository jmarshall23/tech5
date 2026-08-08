
// ========================================================================
// ?AllocPresentable@idCuttable@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C18548
// RVA : 0x00C18548
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

idPresentableCuttable *__fastcall idCuttable::AllocPresentable(idCuttable *this, idTreeAnimator *renderModel_)
{
  idPresentableCuttable *v4; // r3

  v4 = (idPresentableCuttable *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x4B0u,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    return idPresentableCuttable::idPresentableCuttable(this: v4, entity: this, renderModel: renderModel_);
  else
    return nullptr;
}


// ========================================================================
// __unwind$490247
// EA  : 0x82C185B0
// RVA : 0x00C185B0
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __fastcall _unwind_490247(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?CreateStateInfo@idCuttable@@QBAXAAUcuttableStateInfo_t@@@Z
// EA  : 0x82C185D8
// RVA : 0x00C185D8
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __fastcall idCuttable::CreateStateInfo(idCuttable *this, cuttableStateInfo_t *state)
{
  idStr::operator=(this: &state->name, text: this->name.data);
  state->graphValid = this->graphHandle >= 0;
}


// ========================================================================
// ?GetPolygon@idCuttable@@QAA_NAAV?$idList@VidVec2i@@$04@@PAVidCutterClip@@@Z
// EA  : 0x82C18628
// RVA : 0x00C18628
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

int __fastcall idCuttable::GetPolygon(idCuttable *this, idList<idVehicleState *,5> *points, idCutterClip *cutterClip)
{
  int NumPolygons; // r3
  int nestedPolygons; // r30
  int v8; // r28
  int v9; // r11
  int connectedPolygons; // r30
  int num; // r11

  NumPolygons = idCutterClip::GetNumPolygons(this: cutterClip);
  nestedPolygons = this->nestedPolygons;
  v8 = NumPolygons;
  if ( nestedPolygons >= NumPolygons )
  {
LABEL_4:
    connectedPolygons = this->connectedPolygons;
    if ( connectedPolygons >= idCutterClip::GetConnectedPolygons(this: cutterClip) )
      return 0;
    while ( 1 )
    {
      idCutterClip::GetConnectedPolygon(this: cutterClip, index: connectedPolygons, list: points);
      num = points->num;
      ++this->connectedPolygons;
      if ( num > 0 )
        break;
      if ( ++connectedPolygons >= idCutterClip::GetConnectedPolygons(this: cutterClip) )
        return 0;
    }
  }
  else
  {
    while ( 1 )
    {
      idCutterClip::GetPolygon(this: cutterClip, id: nestedPolygons, list: points);
      v9 = points->num;
      ++this->nestedPolygons;
      if ( v9 > 0 )
        break;
      if ( ++nestedPolygons >= v8 )
        goto LABEL_4;
    }
  }
  return 1;
}


// ========================================================================
// ??0idCuttable@@QAA@XZ
// EA  : 0x82C186F8
// RVA : 0x00C186F8
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

idCuttable *__fastcall idCuttable::idCuttable(idCuttable *this)
{
  idLinkList<idCuttable> *head; // r4

  idEntity::idEntity(this);
  this->physicsObj = nullptr;
  this->__vftable = (idCuttable_vtbl *)&idCuttable::`vftable';
  this->cuttableNode.owner = nullptr;
  this->cuttableNode.head = &this->cuttableNode;
  this->cuttableNode.next = &this->cuttableNode;
  this->cuttableNode.prev = &this->cuttableNode;
  this->collisionGrid = nullptr;
  this->cutModel = nullptr;
  this->beamModel = nullptr;
  this->clipModel = nullptr;
  this->gridClipModel = nullptr;
  this->collisionModel = nullptr;
  this->gridCollisionModel = nullptr;
  this->graphHandle = -1;
  this->infoHandle = -1;
  this->impactTable = nullptr;
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  this->cuttableNode.owner = this;
  head = gameLocal->cuttableEntities.head;
  this->cuttableNode.prev->next = this->cuttableNode.next;
  this->cuttableNode.next->prev = this->cuttableNode.prev;
  this->cuttableNode.prev = &this->cuttableNode;
  this->cuttableNode.head = &this->cuttableNode;
  this->cuttableNode.next = head;
  this->cuttableNode.prev = head->prev;
  head->prev = &this->cuttableNode;
  this->cuttableNode.prev->next = &this->cuttableNode;
  this->cuttableNode.head = head->head;
  return this;
}


// ========================================================================
// ??1idCuttable@@UAA@XZ
// EA  : 0x82C187E8
// RVA : 0x00C187E8
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __fastcall idCuttable::~idCuttable(idCuttable *this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  void **v8; // r10
  int infoHandle; // r4
  int graphHandle; // r4
  idRenderModelCuttableSurface *cutModel; // r3
  idRenderModelCuttableBeams *beamModel; // r3
  idPhysics *Physics; // r3
  idPhysics *physicsObj; // r3
  idCollisionModel *collisionModel; // r3
  idCollisionModel *gridCollisionModel; // r3

  v8 = &idCuttable::`vftable';
  this->__vftable = (idCuttable_vtbl *)&idCuttable::`vftable';
  infoHandle = this->infoHandle;
  if ( infoHandle >= 0 )
  {
    if ( &gameLocal[1].gameSpawnInfo.layersActive.staticList[65].buffer[88] != (char *)15040 )
      idCuttableManager::ClearCuttable(this: &gameLocal->cuttableManager, index: infoHandle);
    this->infoHandle = -1;
  }
  graphHandle = this->graphHandle;
  if ( graphHandle >= 0 )
  {
    if ( &gameLocal[1].gameSpawnInfo.layersActive.staticList[65].buffer[88] != (char *)15488 )
      idCutterGraphManager::FreeGraph(
        this: &gameLocal->graphManager,
        id: graphHandle,
        a3,
        a4,
        a5,
        a6,
        num: a7,
        a8: (int)v8);
    this->graphHandle = -1;
  }
  this->cuttableNode.prev->next = this->cuttableNode.next;
  this->cuttableNode.next->prev = this->cuttableNode.prev;
  this->cuttableNode.next = &this->cuttableNode;
  this->cuttableNode.prev = &this->cuttableNode;
  this->cuttableNode.head = &this->cuttableNode;
  cutModel = this->cutModel;
  if ( cutModel != nullptr )
  {
    cutModel->unlinked = true;
    cutModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: cutModel);
    this->cutModel = nullptr;
  }
  beamModel = this->beamModel;
  if ( beamModel != nullptr )
  {
    beamModel->unlinked = true;
    beamModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: beamModel);
    this->beamModel = nullptr;
  }
  if ( idEntity::GetPhysics(this) != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->UnlinkClip(this: Physics);
  }
  physicsObj = this->physicsObj;
  if ( physicsObj != nullptr )
  {
    ((void (__fastcall *)(idPhysics *, int))physicsObj->dtr_idPhysics)(a1: physicsObj, a2: 1);
    this->physicsObj = nullptr;
  }
  collisionModel = this->collisionModel;
  if ( collisionModel != nullptr )
  {
    ((void (__fastcall *)(idCollisionModel *, int))collisionModel->dtr_idResource)(a1: collisionModel, a2: 1);
    this->collisionModel = nullptr;
  }
  gridCollisionModel = this->gridCollisionModel;
  if ( gridCollisionModel != nullptr )
  {
    ((void (__fastcall *)(idCollisionModel *, int))gridCollisionModel->dtr_idResource)(a1: gridCollisionModel, a2: 1);
    this->gridCollisionModel = nullptr;
  }
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->cuttableNode);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$491238_0
// EA  : 0x82C18988
// RVA : 0x00C18988
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_491238_0()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$491239_0
// EA  : 0x82C189B0
// RVA : 0x00C189B0
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_491239_0()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                           + 804));
}


// ========================================================================
// ?WriteLevelStateToFile@idCuttable@@SAXPAVidFile@@AAV?$idList@UcuttableStateInfo_t@@$04@@AAVidCutterGraphState@@@Z
// EA  : 0x82C18A40
// RVA : 0x00C18A40
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __fastcall idCuttable::WriteLevelStateToFile(
        idFile *file,
        idList<cuttableStateInfo_t,5> *stateInfo,
        idCutterGraphState *graphState)
{
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  bool v7; // r29
  idFile_vtbl *v8; // r10
  int v9; // r29
  int v10; // r28
  idFile_vtbl *v11; // r10
  int v12; // r28
  int v13; // r30
  cuttableStateInfo_t *v14; // r29
  unsigned int (__fastcall *v15)(idFile *, const void *, unsigned int); // r8
  char v16; // r11
  char v17; // r7
  bool v18[4]; // [sp+50h] [-40h] BYREF
  unsigned int len; // [sp+54h] [-3Ch] BYREF
  int num; // [sp+58h] [-38h] BYREF
  int v21; // [sp+5Ch] [-34h] BYREF

  Write = file->Write;
  v7 = g_saveCuttableState.valueInteger != 0;
  v18[0] = g_saveCuttableState.valueInteger != 0;
  Write(this: file, a2: v18, a3: 1u);
  if ( v7 )
  {
    v8 = file->__vftable;
    num = graphState->graphHandles.num;
    v8->Write(this: file, a2: &num, a3: 4u);
    v9 = 0;
    if ( graphState->graphHandles.num > 0 )
    {
      v10 = 0;
      do
      {
        idCutterGraphManager::Write(manager: graphState->manager, file, graphHandle: graphState->graphHandles.list[v10]);
        ++v9;
        ++v10;
      }
      while ( v9 < graphState->graphHandles.num );
    }
    v11 = file->__vftable;
    v21 = stateInfo->num;
    v11->Write(this: file, a2: &v21, a3: 4u);
    v12 = 0;
    if ( stateInfo->num > 0 )
    {
      v13 = 0;
      do
      {
        v14 = &stateInfo->list[v13];
        v15 = file->Write;
        len = v14->name.len;
        v16 = BYTE1(len);
        v17 = HIBYTE(len);
        BYTE1(len) = BYTE2(len);
        HIBYTE(len) = len;
        LOBYTE(len) = v17;
        BYTE2(len) = v16;
        v15(this: file, a2: &len, a3: 4u);
        file->Write(this: file, a2: v14->name.data, a3: v14->name.len);
        file->Write(this: file, a2: &stateInfo->list[v13].graphValid, a3: 1u);
        ++v12;
        ++v13;
      }
      while ( v12 < stateInfo->num );
    }
  }
}


// ========================================================================
// ?BuildClipModel@idCuttable@@AAAXXZ
// EA  : 0x82C18E68
// RVA : 0x00C18E68
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __fastcall idCuttable::BuildClipModel(idCuttable *this)
{
  idPhysics *v2; // r3
  idPhysics *Physics; // r3
  float *v4; // r3
  idPhysics *v5; // r3
  float *v6; // r3
  idPhysics *v7; // r3
  idPhysics *v8; // r3
  float *v9; // r3
  idPhysics *v10; // r3
  float *v11; // r3
  idPhysics *v12; // r3
  idCollisionModel *collisionModel; // r3
  idCollisionModel *gridCollisionModel; // r3
  idCollisionModelLocal *v15; // r3
  idRenderModelCuttableSurface *cutModel; // r11
  int v17; // r29
  idRenderModelSurface *list; // r11
  idTriangles *geometry; // r3
  idClipModel *v20; // r3
  idClipModel *v21; // r3
  idCollisionGrid *collisionGrid; // r11
  idPhysics *v23; // r3
  idPhysics *v24; // r3
  idPhysics *v25; // r3
  Contour *InnerContour; // r28
  ContourEdge_t *i; // r29
  idClipModel *v28; // r3
  idClipModel *v29; // r3
  idPhysics *v30; // r3
  idPhysics *v31; // r3
  idPhysics *v32; // r3
  idPhysics *v33; // r3
  idPhysics *v34; // r3
  idPhysics *v35; // r3
  idPhysics *v36; // r3
  idPhysics *v37; // r3
  idCollisionGridState v38; // [sp+60h] [-930h] BYREF
  float v39[3]; // [sp+80h] [-910h] BYREF
  float v40[5]; // [sp+8Ch] [-904h] BYREF
  float v41[9]; // [sp+A0h] [-8F0h] BYREF
  float v42[11]; // [sp+C4h] [-8CCh] BYREF
  idStr v43; // [sp+F0h] [-8A0h] BYREF
  idList<idSkinMapping,46> v44; // [sp+110h] [-880h] BYREF
  int v45; // [sp+120h] [-870h] BYREF

  if ( this->graphHandle >= 0 )
  {
    idStr::idStr(this: &v43, text: this->cutModel->name.str);
    Physics = idEntity::GetPhysics(this);
    v4 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v39[0] = *v4;
    v39[1] = v4[1];
    v39[2] = v4[2];
    v5 = idEntity::GetPhysics(this);
    v6 = (float *)v5->GetAxis(this: v5, a2: 0);
    v41[0] = *v6;
    v41[1] = v6[1];
    v41[2] = v6[2];
    v41[3] = v6[3];
    v41[4] = v6[4];
    v41[5] = v6[5];
    v41[6] = v6[6];
    v41[7] = v6[7];
    v41[8] = v6[8];
    v7 = idEntity::GetPhysics(this);
    ((void (__fastcall *)(idPhysics *, _DWORD, double))v7->SetClipModel)(a1: v7, a2: 0, a3: 1.0);
    if ( this->collisionGrid != nullptr )
    {
      v8 = idEntity::GetPhysics(this);
      v9 = (float *)v8->GetOrigin(this: v8, a2: 1);
      v40[0] = *v9;
      v40[1] = v9[1];
      v40[2] = v9[2];
      v10 = idEntity::GetPhysics(this);
      v11 = (float *)v10->GetAxis(this: v10, a2: 1);
      v42[0] = *v11;
      v42[1] = v11[1];
      v42[2] = v11[2];
      v42[3] = v11[3];
      v42[4] = v11[4];
      v42[5] = v11[5];
      v42[6] = v11[6];
      v42[7] = v11[7];
      v42[8] = v11[8];
      v12 = idEntity::GetPhysics(this);
      ((void (__fastcall *)(idPhysics *, _DWORD, double))v12->SetClipModel)(a1: v12, a2: 0, a3: 1.0);
    }
    collisionModel = this->collisionModel;
    if ( collisionModel != nullptr )
    {
      ((void (__fastcall *)(idCollisionModel *, int))collisionModel->dtr_idResource)(a1: collisionModel, a2: 1);
      this->collisionModel = nullptr;
    }
    gridCollisionModel = this->gridCollisionModel;
    if ( gridCollisionModel != nullptr )
    {
      ((void (__fastcall *)(idCollisionModel *, int))gridCollisionModel->dtr_idResource)(a1: gridCollisionModel, a2: 1);
      this->gridCollisionModel = nullptr;
    }
    v15 = idCollisionModelManager::ModelFromRender(
            this: collisionModelManager,
            modelName: v43.data,
            renderModel: this->cutModel);
    cutModel = this->cutModel;
    v17 = 0;
    this->collisionModel = v15;
    if ( cutModel->surfaces.num > 0 )
    {
      do
      {
        list = this->cutModel->surfaces.list;
        if ( list != nullptr )
        {
          geometry = list->geometry;
          if ( geometry != nullptr )
            idTriangles::FreeCPUData(this: geometry);
        }
        ++v17;
      }
      while ( v17 < this->cutModel->surfaces.num );
    }
    v20 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 0xD8u,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v20 != nullptr )
      v21 = idClipModel::idClipModel(this: v20, clip: &clientGame->clip, model: this->collisionModel);
    else
      v21 = nullptr;
    collisionGrid = this->collisionGrid;
    this->clipModel = v21;
    if ( collisionGrid != nullptr )
    {
      idCollisionGridState::idCollisionGridState(this: &v38);
      this->collisionGrid->CreateState(this: this->collisionGrid, a2: &v38);
      InnerContour = idCutterGraphManager::GetInnerContour(this: &gameLocal->graphManager, id: this->graphHandle);
      if ( InnerContour != nullptr && this->collisionGrid != nullptr )
      {
        do
        {
          v44.size = 256;
          v44.granularity = 1;
          v44.num = 0;
          v44.memTag = 5;
          v44.list = (idSkinMapping *)&v45;
          v44.listStatic = 1;
          for ( i = InnerContour->edges; i != nullptr; i = i->next )
            idList<cachedPageFile_t,5>::Append(this: &v44, obj: (const idSkinMapping *)&i->node->pos);
          this->collisionGrid->InactivateFill(
            this: this->collisionGrid,
            a2: (const idVec2i *)v44.list,
            a3: v44.num,
            a4: &v38);
          InnerContour = InnerContour->next;
          if ( v44.listStatic == 0 || v44.listStatic == 2 )
          {
            if ( v44.list != nullptr )
              idMem::Free(this: &mem, ptr: v44.list, align: ALIGN_16);
            v44.list = nullptr;
            v44.size = 0;
          }
          v44.num = 0;
        }
        while ( InnerContour != nullptr );
      }
      this->gridCollisionModel = idCollisionModelManager::ModelFromGrid(
                                   this: collisionModelManager,
                                   modelName: v43.data,
                                   grid: this->collisionGrid,
                                   state: &v38,
                                   material: nullptr);
      v28 = (idClipModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0xD8u,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      if ( v28 != nullptr )
        v29 = idClipModel::idClipModel(this: v28, clip: &clientGame->clip, model: this->gridCollisionModel);
      else
        v29 = nullptr;
      this->gridClipModel = v29;
      idClipModel::SetContents(this: this->clipModel, newContents: 464);
      idClipModel::SetContents(this: this->gridClipModel, newContents: 40);
      v30 = idEntity::GetPhysics(this);
      ((void (__fastcall *)(idPhysics *, idClipModel *, double))v30->SetClipModel)(
        a1: v30,
        a2: this->clipModel,
        a3: 1.0);
      v31 = idEntity::GetPhysics(this);
      v31->SetOrigin(this: v31, a2: (const idVec3 *)v39, a3: 0);
      v32 = idEntity::GetPhysics(this);
      v32->SetAxis(this: v32, a2: (const idMat3 *)v41, a3: 0);
      v33 = idEntity::GetPhysics(this);
      ((void (__fastcall *)(idPhysics *, idClipModel *, double))v33->SetClipModel)(
        a1: v33,
        a2: this->gridClipModel,
        a3: 1.0);
      v34 = idEntity::GetPhysics(this);
      v34->SetOrigin(this: v34, a2: (const idVec3 *)v40, a3: 1);
      v35 = idEntity::GetPhysics(this);
      v35->SetAxis(this: v35, a2: (const idMat3 *)v42, a3: 1);
      if ( v38.active.buffer != nullptr && v38.active.free )
      {
        idMem::Free(this: &mem, ptr: v38.active.buffer, align: ALIGN_16);
        v38.active.buffer = nullptr;
        v38.active.bits = 0;
        v38.active.free = false;
      }
    }
    else
    {
      idClipModel::SetContents(this: v21, newContents: 504);
      v23 = idEntity::GetPhysics(this);
      ((void (__fastcall *)(idPhysics *, idClipModel *, double))v23->SetClipModel)(
        a1: v23,
        a2: this->clipModel,
        a3: 1.0);
      v24 = idEntity::GetPhysics(this);
      v24->SetOrigin(this: v24, a2: (const idVec3 *)v39, a3: 0);
      v25 = idEntity::GetPhysics(this);
      v25->SetAxis(this: v25, a2: (const idMat3 *)v41, a3: 0);
    }
    v36 = idEntity::GetPhysics(this);
    v36->LinkClip(this: v36);
    v37 = idEntity::GetPhysics(this);
    v37->EnableClip(this: v37);
    idStr::FreeData(this: &v43);
  }
  else
  {
    v2 = idEntity::GetPhysics(this);
    v2->UnlinkClip(this: v2);
  }
}


// ========================================================================
// __unwind$492092
// EA  : 0x82C194CC
// RVA : 0x00C194CC
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492092()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2448 + 240));
}


// ========================================================================
// __unwind$492093
// EA  : 0x82C194F4
// RVA : 0x00C194F4
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __fastcall _unwind_492093(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 2448 + 80), tag: a2);
}


// ========================================================================
// __unwind$492094
// EA  : 0x82C1951C
// RVA : 0x00C1951C
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492094()
{
  int v0; // r12

  idCollisionGridState::~idCollisionGridState(this: (idCollisionGridState *)(v0 - 2448 + 96));
}


// ========================================================================
// __unwind$492095
// EA  : 0x82C19544
// RVA : 0x00C19544
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492095()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2448 + 272));
}


// ========================================================================
// __unwind$492096
// EA  : 0x82C1956C
// RVA : 0x00C1956C
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __fastcall _unwind_492096(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 2448 + 80), tag: a2);
}


// ========================================================================
// ?Spawn@idCuttable@@QAAXXZ
// EA  : 0x82C19660
// RVA : 0x00C19660
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __fastcall idCuttable::Spawn(idCuttable *this)
{
  const char *v2; // r3
  idRenderModel *v3; // r3
  idRenderModelCuttableSurface *v4; // r3
  idPhysics *v5; // r3
  idPhysics *v6; // r3
  const char *v7; // r3
  idCollisionGrid *Grid; // r3
  idCollisionGrid *collisionGrid; // r3
  idVec3 *p_spawnPosition; // r28
  idPhysics_StaticMulti *v11; // r3
  idPhysics_StaticMulti *v12; // r29
  idCuttableManager *p_cuttableManager; // r29
  idPhysics *Physics; // r3
  idCutterGraphManager *p_graphManager; // r29
  int v16; // r29
  idPhysics *v17; // r3
  idPhysics *v18; // r3
  idPhysics *v19; // r3
  idPhysics *v20; // r3
  idRenderModel *v21; // r3
  idRenderModelCuttableBeams *v22; // r3
  const idMaterial *v23; // r27
  const idMaterial *v24; // r3
  idRenderModel *RenderModelFromPresentable; // r3
  idPhysics *v26; // r29
  const idMat3 *v27; // r27
  const idBounds *v28; // r3
  idRenderModelCuttableBeams *beamModel; // r11
  idBounds v30; // [sp+60h] [-110h] BYREF
  idStr v31; // [sp+80h] [-F0h] BYREF
  idStr v32; // [sp+A0h] [-D0h] BYREF
  idStr v33; // [sp+C0h] [-B0h] BYREF
  idStr v34; // [sp+E0h] [-90h] BYREF
  idMat3 v35[3]; // [sp+100h] [-70h] BYREF

  v2 = clientGame->renderWorld->GetName(this: clientGame->renderWorld);
  idStr::idStr(this: &v31, text: v2);
  idStr::Append(this: &v31, text: "/");
  idStr::Append(this: &v31, text: this->name.data);
  idStr::SetFileExtension(this: &v31, extension: "csurf");
  v3 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: v31.data, a3: 0, a4: -1);
  v4 = (idRenderModelCuttableSurface *)_RTDynamicCast(
                                         inptr: v3,
                                         VfDelta: 0,
                                         SrcType: &idRenderModel `RTTI Type Descriptor',
                                         TargetType: &idRenderModelCuttableSurface `RTTI Type Descriptor',
                                         isReference: 0);
  this->cutModel = v4;
  if ( v4->surfaces.num != 0 )
  {
    v7 = clientGame->renderWorld->GetName(this: clientGame->renderWorld);
    idStr::idStr(this: &v32, text: v7);
    idStr::Append(this: &v32, text: "/");
    idStr::Append(this: &v32, text: this->name.data);
    idStr::SetFileExtension(this: &v32, extension: "cgrid");
    Grid = idCollisionModelManager::LoadGrid(this: collisionModelManager, modelName: v32.data);
    this->collisionGrid = Grid;
    if ( Grid != nullptr && !Grid->IsValid(this: Grid) )
    {
      collisionGrid = this->collisionGrid;
      if ( collisionGrid != nullptr )
        ((void (__fastcall *)(idCollisionGrid *, int))collisionGrid->dtr_idResource)(a1: collisionGrid, a2: 1);
      this->collisionGrid = nullptr;
    }
    p_spawnPosition = &this->spawnPosition;
    this->SetModel(this, a2: this->cutModel);
    v11 = (idPhysics_StaticMulti *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x98u,
                                     tag: TAG_GAME,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
    if ( v11 != nullptr )
      v12 = idPhysics_StaticMulti::idPhysics_StaticMulti(this: v11);
    else
      v12 = nullptr;
    idPhysics::InitPhysics(
      this: v12,
      clip_: &clientGame->clip,
      callbacks_: &this->physicsCallbacks,
      entityNumber_: this->entityNumber);
    v12->SetGravity(this: v12, a2: &gameLocal->clientGame.gravity);
    this->physicsObj = v12;
    idEntity::SetPhysics(this, phys: v12);
    p_cuttableManager = &gameLocal->cuttableManager;
    idStr::idStr(this: &v34, text: this->name.data);
    Physics = idEntity::GetPhysics(this);
    this->infoHandle = idCuttableManager::AllocateCuttable(
                         this: p_cuttableManager,
                         name: &v34,
                         renderModel_: this->cutModel,
                         physics: Physics);
    idStr::FreeData(this: &v34);
    p_graphManager = &gameLocal->graphManager;
    idStr::idStr(this: &v33, text: this->name.data);
    this->graphHandle = idCutterGraphManager::AllocateGraph(
                          this: p_graphManager,
                          name: &v33,
                          position: &this->spawnPosition,
                          orientation: &this->spawnOrientation,
                          normal: &this->cutModel->triangleInterpolator->refNormal,
                          points: &this->cutModel->modelResource->contourBound);
    idStr::FreeData(this: &v33);
    idCuttable::BuildClipModel(this);
    v16 = 0;
    v17 = idEntity::GetPhysics(this);
    if ( v17->GetNumClipModels(this: v17) > 0 )
    {
      do
      {
        v18 = idEntity::GetPhysics(this);
        v18->SetOrigin(this: v18, a2: &this->spawnPosition, a3: v16);
        v19 = idEntity::GetPhysics(this);
        v19->SetAxis(this: v19, a2: &this->spawnOrientation, a3: v16++);
        v20 = idEntity::GetPhysics(this);
      }
      while ( v16 < v20->GetNumClipModels(this: v20) );
    }
    v21 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: "_cuttablebeams", a3: 1, a4: -1);
    v22 = (idRenderModelCuttableBeams *)_RTDynamicCast(
                                          inptr: v21,
                                          VfDelta: 0,
                                          SrcType: &idRenderModel `RTTI Type Descriptor',
                                          TargetType: &idRenderModelCuttableBeams `RTTI Type Descriptor',
                                          isReference: 0);
    this->beamModel = v22;
    if ( v22 != nullptr )
    {
      v23 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                  this: &idMaterial::resourceList,
                                  name: "textures/w_sfx/lasercutter/incision",
                                  makeDefault: true);
      v24 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                  this: &idMaterial::resourceList,
                                  name: "textures/w_sfx/lasercutter/incisioncross",
                                  makeDefault: true);
      idRenderModelCuttableBeams::Create(this: this->beamModel, materialIncision_: v23, materialIncisionCross_: v24);
      RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
      if ( RenderModelFromPresentable != nullptr )
      {
        v30.b[0].x = RenderModelFromPresentable->referenceBounds.b[0].x;
        v30.b[0].y = RenderModelFromPresentable->referenceBounds.b[0].y;
        v30.b[0].z = RenderModelFromPresentable->referenceBounds.b[0].z;
        v30.b[1] = RenderModelFromPresentable->referenceBounds.b[1];
      }
      else
      {
        v26 = idEntity::GetPhysics(this);
        v27 = idMat3::Inverse(this: v35, result: &this->spawnOrientation);
        v28 = v26->GetBounds(this: v26, a2: -1);
        idBounds::FromTransformedBounds(this: &v30, bounds: v28, origin: &vec3_origin, axis: v27);
      }
      idRenderModelCuttableBeams::SetBounds(this: this->beamModel, bounds: &v30);
      beamModel = this->beamModel;
      if ( !beamModel->deferredPositionInitialized || !beamModel->useDeferredPosition )
      {
        beamModel->g.origin.x = p_spawnPosition->x;
        beamModel->g.origin.y = this->spawnPosition.y;
        beamModel->g.origin.z = this->spawnPosition.z;
      }
      beamModel->deferredOrigin.x = p_spawnPosition->x;
      beamModel->deferredOrigin.y = this->spawnPosition.y;
      beamModel->deferredOrigin.z = this->spawnPosition.z;
      idRenderModel::SetAxis(this: this->beamModel, a: &this->spawnOrientation);
    }
    idEntity::UpdateVisuals(this);
    idEntity::BecomeActive(this, flags: 1);
    idStr::FreeData(this: &v32);
  }
  else
  {
    v5 = idEntity::GetPhysics(this);
    v5->DisableClip(this: v5);
    v6 = idEntity::GetPhysics(this);
    v6->UnlinkClip(this: v6);
    this->Hide_2(this);
  }
  idStr::FreeData(this: &v31);
}


// ========================================================================
// __unwind$492413
// EA  : 0x82C19BAC
// RVA : 0x00C19BAC
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492413()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 128));
}


// ========================================================================
// __unwind$492414
// EA  : 0x82C19BD4
// RVA : 0x00C19BD4
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492414()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 160));
}


// ========================================================================
// __unwind$492415
// EA  : 0x82C19BFC
// RVA : 0x00C19BFC
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492415()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 368 + 80), tag: TAG_GAME);
}


// ========================================================================
// __unwind$492416
// EA  : 0x82C19C28
// RVA : 0x00C19C28
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492416()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 224));
}


// ========================================================================
// __unwind$492417
// EA  : 0x82C19C50
// RVA : 0x00C19C50
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492417()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 192));
}


// ========================================================================
// ?Think@idCuttable@@UAAXXZ
// EA  : 0x82C19C78
// RVA : 0x00C19C78
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __fastcall idCuttable::Think(idCuttable *this)
{
  idCutterGraphManager *p_graphManager; // r30
  idPhysics *Physics; // r28
  idPhysics *v4; // r27
  const idMat3 *v5; // r28
  const idVec3 *v6; // r3
  __int64 v7; // r6
  idPhysics *v8; // r3
  float *v9; // r3
  idRenderModelCuttableBeams *beamModel; // r11
  idPhysics *v11; // r3
  const idMat3 *v12; // r3

  if ( (this->thinkFlags & 1) != 0 )
  {
    if ( this->graphHandle >= 0 )
    {
      if ( this->clipModel == nullptr )
        idCuttable::BuildClipModel(this);
      p_graphManager = &gameLocal->graphManager;
      if ( &gameLocal[1].gameSpawnInfo.layersActive.staticList[65].buffer[88] != (char *)15488 )
      {
        Physics = idEntity::GetPhysics(this);
        v4 = idEntity::GetPhysics(this);
        v5 = Physics->GetAxis(this: Physics, a2: 0);
        v6 = v4->GetOrigin(this: v4, a2: 0);
        idCutterGraphManager::SetPosition(this: p_graphManager, id: this->graphHandle, position: v6, orientation: v5);
        if ( g_debugCuttable.valueInteger != 0 )
        {
          LODWORD(v7) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
          HIDWORD(v7) = clientGame->renderWorld;
          idCutterGraphManager::DebugDraw(this: p_graphManager, id: this->graphHandle, lifeTime: v7);
        }
      }
      if ( this->beamModel != nullptr )
      {
        v8 = idEntity::GetPhysics(this);
        v9 = (float *)v8->GetOrigin(this: v8, a2: 0);
        beamModel = this->beamModel;
        if ( !beamModel->deferredPositionInitialized || !beamModel->useDeferredPosition )
        {
          beamModel->g.origin.x = *v9;
          beamModel->g.origin.y = v9[1];
          beamModel->g.origin.z = v9[2];
        }
        beamModel->deferredOrigin.x = *v9;
        beamModel->deferredOrigin.y = v9[1];
        beamModel->deferredOrigin.z = v9[2];
        v11 = idEntity::GetPhysics(this);
        v12 = v11->GetAxis(this: v11, a2: 0);
        idRenderModel::SetAxis(this: this->beamModel, a: v12);
        idRenderModelCuttableBeams::Update(
          this: this->beamModel,
          graphManager_: p_graphManager,
          graphHandle_: this->graphHandle);
      }
    }
    else
    {
      idEntity::BecomeInactive(this, flags: 1);
    }
  }
  idEntity::RunPhysics(this);
  this->UpdateFX(this);
}


// ========================================================================
// ?ApplyStateInfo@idCuttable@@QAAXABUcuttableStateInfo_t@@@Z
// EA  : 0x82C19E50
// RVA : 0x00C19E50
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __fastcall idCuttable::ApplyStateInfo(idCuttable *this, const cuttableStateInfo_t *state)
{
  if ( !state->graphValid )
    this->graphHandle = -1;
  idCuttable::BuildClipModel(this);
}


// ========================================================================
// ?PushCut@idCuttable@@AAAXVidVec3@@ABV2@@Z
// EA  : 0x82C19E70
// RVA : 0x00C19E70
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCuttable::PushCut(
        idCuttable *this,
        __int64 dir3d,
        float *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        idCuttable *a11,
        __int64 a12,
        __int64 a13,
        __int64 a14)
{
  idCuttable *v15; // r21
  idGameLocal **v16; // r19
  idCutterGraphManager *p_graphManager; // r23
  idCutterClip *p_clipHelper; // r30
  idSkinMapping *v20; // r4
  Contour *Contour; // r29
  const Contour *v22; // r28
  Contour *v23; // r27
  int v24; // r6
  Contour *v25; // r3
  int v26; // r6
  Contour *v27; // r4
  __int64 v28; // r8
  int v29; // r5
  int size; // r10
  int NumPolygons; // r28
  int v32; // r27
  int v33; // r29
  __int64 v34; // r8
  int v35; // r5
  __int64 v36; // r8
  int v37; // r5
  ContourEdge_t *i; // r30
  float *triangleInterpolator; // r11
  float v40; // r9
  float v41; // r8
  float v42; // r7
  double v43; // fp31
  double v44; // fp30
  double v45; // fp29
  int v46; // r30
  int v47; // r29
  float *Local3D; // r3
  double v49; // fp12
  double v50; // fp10
  float *p_z; // r10
  int v52; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  idCutterGraphManager::Node_t **v54; // r3
  idPhysics *Physics; // r3
  int v56; // r3
  float v57; // r4
  float v58; // r11
  idPhysics *v59; // r3
  int v60; // r3
  idList<idCutterGraphManager::graph_t,5> *p_graphs; // r10
  idCutterGraphManager::graph_t **v62; // r9
  int j; // ctr
  double v64; // fp13
  idRenderModelCuttableSurface *cutModel; // r11
  double v66; // fp12
  double v67; // fp11
  double v68; // fp26
  double v69; // fp25
  int num; // r8
  int *list; // r11
  double v72; // fp24
  double v73; // fp21
  double v74; // fp23
  double v75; // fp22
  int v76; // r9
  int v77; // r11
  int v78; // r28
  idCuttable *v79; // r27
  int v80; // r29
  idDrawVert *v81; // r30
  idVec2 *v82; // r6
  int v83; // r15
  int v84; // r20
  int v85; // r21
  idDrawVert *v90; // r30
  idVec2 *v92; // r10
  idDrawVert *v93; // r11
  idVec2 *v98; // r11
  __int64 v99; // fp7
  double v100; // fp12
  double v101; // fp10
  double v102; // fp8
  double v105; // fp2
  double v110; // fp6
  __int64 v112; // fp10
  double v113; // fp3
  double v114; // fp12
  double v115; // fp11
  double v118; // fp5
  double v119; // fp9
  __int128 v120; // r6
  __int64 v121; // r11
  __int64 v122; // r9
  double v123; // fp3
  double v124; // fp2
  __int64 v125; // fp13
  double v126; // fp4
  double v127; // fp12
  double v128; // fp10
  double v129; // fp8
  double v132; // fp11
  double v133; // fp13
  double v134; // fp9
  char v135; // r11
  double v136; // fp7
  double v137; // fp6
  double v138; // fp11
  double v140; // fp10
  double v141; // fp12
  double v142; // fp8
  double v144; // fp6
  double v145; // fp6
  double v146; // fp0
  double v147; // fp11
  double v148; // fp9
  int v149; // r10
  int v150; // r30
  unsigned int v151; // r29
  const idDeclImpactSound *impactTable; // r4
  idGameLocal *v153; // r11
  int *p_graphHandle; // r29
  Contour *OuterContour; // r30
  Contour *InnerContour; // r6
  int v157; // r10
  int v158; // r9
  int v159; // r8
  int v160; // r7
  int v161; // r6
  int v162; // r5
  idRenderModelCuttableSurface *v163; // r10
  idPhysics *v164; // r3
  char v166; // [sp+50h] [-2C10h]
  _DWORD v167[2]; // [sp+58h] [-2C08h] BYREF
  idList<idVec2,5> v168; // [sp+60h] [-2C00h] BYREF
  idList<idDrawVert,44> v169; // [sp+70h] [-2BF0h] BYREF
  idList<idVec2,72> v170; // [sp+80h] [-2BE0h] BYREF
  idList<unsigned short,5> v171; // [sp+90h] [-2BD0h] BYREF
  idVec3 v172; // [sp+A0h] [-2BC0h] BYREF
  idVec3 v173; // [sp+B0h] [-2BB0h] BYREF
  int v174; // [sp+BCh] [-2BA4h]
  idGameLocal **v175; // [sp+C0h] [-2BA0h]
  int v176; // [sp+C4h] [-2B9Ch]
  idCutterGraphManager v177; // [sp+C8h] [-2B98h] BYREF
  float v178; // [sp+174h] [-2AECh]
  float v179; // [sp+178h] [-2AE8h]
  float v180; // [sp+17Ch] [-2AE4h]
  float v181; // [sp+180h] [-2AE0h]
  float v182; // [sp+184h] [-2ADCh]
  idCutterGraphManager::Node_t **v183; // [sp+188h] [-2AD8h]
  int v184; // [sp+18Ch] [-2AD4h]
  float v185; // [sp+190h] [-2AD0h]
  __int64 v186; // [sp+198h] [-2AC8h]
  __int64 v187; // [sp+1A0h] [-2AC0h]
  __int64 v188; // [sp+1A8h] [-2AB8h]
  __int64 v189; // [sp+1B0h] [-2AB0h]
  __int64 v190; // [sp+1B8h] [-2AA8h]
  __int64 v191; // [sp+1C0h] [-2AA0h]
  idCutterGraphManager v192; // [sp+1C8h] [-2A98h] BYREF
  idDrawVert v193[5]; // [sp+310h] [-2950h] BYREF
  idList<idVec3,5> v194; // [sp+3C0h] [-28A0h] BYREF
  int v195; // [sp+3D0h] [-2890h] BYREF
  idTraceModel v196; // [sp+550h] [-2710h] BYREF
  idList<idSkinMapping,46> v197; // [sp+B50h] [-2110h] BYREF
  int v198; // [sp+B60h] [-2100h] BYREF

  _R12 = -256;
  __asm { stvx128   v127, r1, r12 }
  a13 = *(__int64 *)((char *)&dir3d + 4);
  HIDWORD(dir3d) = this->graphHandle;
  v15 = this;
  v16 = &gameLocal;
  a11 = this;
  a14 = dir3d;
  v175 = &gameLocal;
  p_graphManager = &gameLocal->graphManager;
  p_clipHelper = &gameLocal->clipHelper;
  *(_DWORD *)&v177.savedNodes.granularity = p_graphManager;
  idCutterGraphManager::Acquire(this: p_graphManager, id: SHIDWORD(dir3d));
  idCutterGraphManager::GetLocal2D(this: &v192, result: (idVec2i *)p_graphManager, point: (const idVec3 *)&a13);
  if ( !idCutterGraphManager::BuildEdge(this: p_graphManager, dst: (idVec2i *)&v192) )
    goto LABEL_158;
  v197.granularity = 1;
  v197.num = 0;
  v197.memTag = 5;
  v197.size = 1024;
  v197.list = (idSkinMapping *)&v198;
  v197.listStatic = 1;
  if ( (unsigned __int8)idCutterGraphManager::PathFind(this: p_graphManager, points: &v197) != 0 )
  {
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)p_graphManager);
    Contour = idCutterGraphManager::CreateContour(this: p_graphManager, points: (const idList<idVec2i,5> *)&v197);
    v22 = idCutterGraphManager::IntersectContours(this: p_graphManager, contour: Contour);
    v23 = nullptr;
    idCutterClip::Prepare(this: p_clipHelper);
    idCutterClip::PreAllocate(this: p_clipHelper);
    if ( Contour != nullptr && v22 != nullptr )
    {
      idCutterClip::AddContour(this: p_clipHelper, contours: Contour, polyType: POLYTYPE_SUBJECT);
      idCutterClip::AddContour(this: p_clipHelper, contours: v22, polyType: POLYTYPE_CLIP);
      idCutterClip::Clip(this: p_clipHelper, clipMode_: CLIPMODE_UNION, fillType: FILLTYPE_NON_ZERO);
      v15->connectedPolygons = 0;
      for ( v15->nestedPolygons = 0;
            (unsigned __int8)idCuttable::GetPolygon(
                               this: v15,
                               points: (idList<idVehicleState *,5> *)&v197,
                               cutterClip: p_clipHelper) != 0;
            v23 = v25 )
      {
        v25 = idCutterGraphManager::CreateContour(this: p_graphManager, points: (const idList<idVec2i,5> *)&v197);
        v25->next = v23;
      }
      Contour->next = (Contour *)v22;
      if ( v23 != nullptr )
      {
        idCutterClip::Prepare(this: p_clipHelper);
        idCutterClip::AddContour(this: p_clipHelper, contours: v23, polyType: POLYTYPE_SUBJECT);
        idCutterClip::AddContour(this: p_clipHelper, contours: v22, polyType: POLYTYPE_CLIP);
        idCutterClip::Clip(this: p_clipHelper, clipMode_: CLIPMODE_DIFFERENCE, fillType: FILLTYPE_NON_ZERO);
      }
      idCutterGraphManager::MergeContours(this: p_graphManager, contour: Contour);
      v166 = idCutterGraphManager::AddContour(this: p_graphManager, contours: v23, mergedContours: Contour, y: v26);
      do
      {
        v27 = Contour;
        Contour = Contour->next;
        idCutterGraphManager::FreeContour(this: p_graphManager, contour: v27);
      }
      while ( Contour != nullptr );
    }
    else
    {
      v166 = idCutterGraphManager::AddContour(this: p_graphManager, contours: Contour, mergedContours: Contour, y: v24);
    }
    idEarClipTriangulate::idEarClipTriangulate(this: (idEarClipTriangulate *)&v193[0].st.y);
    v192.graphs.size = 0;
    *(_DWORD *)&v192.graphs.granularity = 32;
    v192.graphs.num = (int)&v192.linksPoolBlock.num;
    v192.linksPoolBlock.list = (idCutterGraphManager::Link_t **)66817;
    size = v197.size;
    if ( v197.size >= 0 || v197.listStatic != 0 && v197.listStatic != 2 )
    {
      v197.num = 0;
      if ( v197.size > 0 )
        goto LABEL_25;
    }
    else
    {
      if ( v197.list != nullptr )
        idMem::Free(this: &mem, ptr: v197.list, align: ALIGN_16);
      size = 0;
      v197.list = nullptr;
      v197.size = 0;
    }
    v197.num = size;
LABEL_25:
    if ( v23 != nullptr )
    {
      NumPolygons = idCutterClip::GetNumPolygons(this: p_clipHelper);
      v32 = 0;
      v33 = 0;
      if ( NumPolygons <= 0 )
        goto LABEL_40;
      do
      {
        idCutterClip::GetPolygon(this: p_clipHelper, id: v33, list: (idList<idVehicleState *,5> *)&v197);
        if ( v197.num > 0 && ++v32 <= 1 )
        {
          idEarClipTriangulate::SetOuterFromPoints(
            this: (idEarClipTriangulate *)&v193[0].st.y,
            points: (const idList<idVec2i,5> *)&v197,
            a3: v35,
            a4: v34);
          idConvexHull::Create(
            this: (idConvexHull *)&v192.graphs.num,
            points: (const idList<idVec2i,5> *)&v197,
            shrink: 2.0);
          while ( idCutterClip::HasInnerPolygon(this: p_clipHelper) )
          {
            idCutterClip::GetInnerPolygon(this: p_clipHelper, list: (idList<idVehicleState *,5> *)&v197);
            idEarClipTriangulate::AddInnerFromPoints(
              this: (idEarClipTriangulate *)&v193[0].st.y,
              points: (const idList<idVec2i,5> *)&v197,
              a3: v37,
              a4: v36);
          }
        }
        ++v33;
      }
      while ( v33 < NumPolygons );
      if ( v32 > 1 )
      {
        idLib::Printf(fmt: "Discarding cut piece because of multiple outer hulls (num %d)\n", v32);
        if ( LOBYTE(v192.linksPoolBlock.list) == 0 || LOBYTE(v192.linksPoolBlock.list) == 2 )
        {
          if ( v192.graphs.num != 0 )
            idMem::Free(this: &mem, ptr: (void *)v192.graphs.num, align: ALIGN_16);
          v192.graphs.num = 0;
          *(_DWORD *)&v192.graphs.granularity = 0;
        }
        v192.graphs.size = 0;
        goto LABEL_149;
      }
      if ( v32 <= 0 )
      {
LABEL_40:
        idLib::Printf(fmt: "Discarding cut piece because of no outer hull\n");
        if ( LOBYTE(v192.linksPoolBlock.list) == 0 || LOBYTE(v192.linksPoolBlock.list) == 2 )
        {
          if ( v192.graphs.num != 0 )
            idMem::Free(this: &mem, ptr: (void *)v192.graphs.num, align: ALIGN_16);
          v192.graphs.num = 0;
          *(_DWORD *)&v192.graphs.granularity = 0;
        }
        v192.graphs.size = 0;
        goto LABEL_149;
      }
    }
    else
    {
      for ( i = Contour->edges; i != nullptr; i = i->next )
        idList<cachedPageFile_t,5>::Append(this: &v197, obj: (const idSkinMapping *)&i->node->pos);
      if ( v197.num <= 0 )
      {
        idLib::Printf(fmt: "Discarding cut physics piece because no outer contour could be generated.\n");
        if ( LOBYTE(v192.linksPoolBlock.list) == 0 || LOBYTE(v192.linksPoolBlock.list) == 2 )
        {
          if ( v192.graphs.num != 0 )
            idMem::Free(this: &mem, ptr: (void *)v192.graphs.num, align: ALIGN_16);
          v192.graphs.num = 0;
          *(_DWORD *)&v192.graphs.granularity = 0;
        }
        v192.graphs.size = 0;
        goto LABEL_149;
      }
      idEarClipTriangulate::SetOuterFromPoints(
        this: (idEarClipTriangulate *)&v193[0].st.y,
        points: (const idList<idVec2i,5> *)&v197,
        a3: v29,
        a4: v28);
      idConvexHull::Create(
        this: (idConvexHull *)&v192.graphs.num,
        points: (const idList<idVec2i,5> *)&v197,
        shrink: 2.0);
    }
    triangleInterpolator = (float *)v15->cutModel->triangleInterpolator;
    v40 = triangleInterpolator[12];
    v41 = triangleInterpolator[13];
    v42 = triangleInterpolator[14];
    v194.num = 0;
    v194.list = (idVec3 *)&v195;
    v172.x = v40;
    v43 = v40;
    v172.y = v41;
    v44 = v41;
    v172.z = v42;
    v45 = v42;
    v194.size = 32;
    v194.granularity = 1;
    v194.memTag = 5;
    v194.listStatic = 1;
    v46 = 0;
    if ( v192.graphs.size > 0 )
    {
      v47 = 0;
      do
      {
        Local3D = (float *)idCutterGraphManager::GetLocal3D(
                             this: &v177,
                             result: (idVec3 *)p_graphManager,
                             point2d: (const idVec2 *)(v192.graphs.num + v47));
        v49 = (float)(Local3D[2] + (float)v45);
        v50 = (float)(Local3D[1] + (float)v44);
        v173.x = *Local3D + (float)v43;
        v173.z = v49;
        v173.y = v50;
        idList<idAngles,5>::Append(this: &v194, obj: &v173);
        ++v46;
        v47 += 8;
      }
      while ( v46 < v192.graphs.size );
    }
    memset(&v196.type, 0, 20);
    p_z = &v196.offset.z;
    v52 = 6;
    p_viewNoteMutex = &analysisClient.viewNoteMutex;
    v196.offset.x = 0.0;
    v196.offset.y = 0.0;
    v196.offset.z = 0.0;
    do
    {
      ++p_viewNoteMutex;
      *++p_z = *(float *)&p_viewNoteMutex->handle;
      --v52;
    }
    while ( v52 != 0 );
    v196.isConvex = false;
    v196.pad[2] = 0;
    v196.radius = 0.0;
    v196.pad[1] = 0;
    v196.pad[0] = 0;
    *(float *)&v177.invalidNodes.granularity = v172.z * (float)-2.0;
    *(float *)&v177.invalidNodes.size = v172.y * (float)-2.0;
    *(float *)&v177.invalidNodes.num = v172.x * (float)-2.0;
    idTraceModel::SetupPolygonVolume(
      this: &v196,
      v: v194.list,
      count: v194.num,
      dir: (const idVec3 *)&v177.invalidNodes.num);
    idEarClipTriangulate::Triangulate(this: (idEarClipTriangulate *)&v193[0].st.y);
    *(_WORD *)&v170.memTag = 1280;
    memset(&v170, 0, 14);
    *(_WORD *)&v171.memTag = 1280;
    memset(&v171, 0, 14);
    idEarClipTriangulate::BuildGeometry(
      this: (idEarClipTriangulate *)&v193[0].st.y,
      normal: &v172,
      pos: &v170,
      idx: &v171);
    if ( v170.num <= 64 && v171.num <= 192 )
    {
      v54 = (idCutterGraphManager::Node_t **)gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v177.savedNodes.size = v15->entityNumber;
      v177.invalidNodes.list = v54;
      Physics = idEntity::GetPhysics(this: v15);
      v56 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      v57 = *(float *)(v56 + 4);
      v58 = *(float *)(v56 + 8);
      v173.x = *(float *)v56;
      v173.y = v57;
      v173.z = v58;
      v59 = idEntity::GetPhysics(this: v15);
      v60 = (int)v59->GetAxis(this: v59, a2: 0);
      p_graphs = &v177.graphs;
      v62 = (idCutterGraphManager::graph_t **)(v60 - 4);
      for ( j = 9; j != 0; --j )
      {
        ++v62;
        p_graphs = (idList<idCutterGraphManager::graph_t,5> *)((char *)p_graphs + 4);
        p_graphs->list = *v62;
      }
      v64 = *a3;
      cutModel = v15->cutModel;
      v66 = a3[2];
      v67 = a3[1];
      v68 = *(float *)&a13;
      v69 = *((float *)&a13 + 1);
      v176 = 0;
      num = cutModel->surfaces.num;
      list = (int *)cutModel->surfaces.list;
      v72 = *(float *)&a14;
      v73 = (float)((float)((float)v64 * (float)-1.0) * (float)25.0);
      v74 = (float)((float)((float)v66 * (float)-1.0) * (float)25.0);
      v75 = (float)((float)((float)v67 * (float)-1.0) * (float)25.0);
      if ( num <= 1 )
      {
        v174 = *list;
      }
      else
      {
        v76 = list[14];
        v176 = *list;
        v174 = v76;
      }
      *(_WORD *)&v169.memTag = 1280;
      memset(&v169, 0, 14);
      *(_WORD *)&v168.memTag = 1280;
      memset(&v168, 0, 14);
      v77 = v170.num;
      if ( 2 * v170.num > 0 )
      {
        idList<idDrawVert,44>::Resize(this: &v169, newsize: 2 * v170.num);
        v77 = v170.num;
      }
      if ( 2 * v77 > v168.size )
      {
        idList<idVec2,72>::Resize(this: (idList<idVec2,72> *)&v168, newsize: 2 * v77);
        v77 = v170.num;
      }
      v78 = 0;
      if ( v77 > 0 )
      {
        v79 = a11;
        v80 = 0;
        do
        {
          idList<idDrawVert,5>::PreAllocateWithGranularity(this: (idList<idDrawVert,5> *)&v169, newSize: v169.num + 1);
          if ( v169.num >= v169.size )
            v81 = &v169.list[v169.size - 1];
          else
            v81 = &v169.list[v169.num++];
          idList<idVec2,5>::PreAllocateWithGranularity(this: &v168, newSize: v168.num + 1);
          if ( v168.num >= v168.size )
            v82 = &v168.list[v168.size - 1];
          else
            v82 = &v168.list[v168.num++];
          idTriangleInterpolator::Interpolate(
            this: (idTriangleInterpolator *)v79->cutModel->triangleInterpolator,
            point: &v170.list[v80],
            vert: v81,
            st: v82);
          v77 = v170.num;
          ++v78;
          ++v80;
        }
        while ( v78 < v170.num );
      }
      v83 = 0;
      if ( v77 > 0 )
      {
        __asm { vspltisw128 v127, 0 }
        v84 = 0;
        v85 = 0;
        _R16 = 2;
        _R19 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
        _R18 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
        _R17 = &_vmx_3f8000003f8000003f8000003f800000;
        do
        {
          idList<idDrawVert,5>::PreAllocateWithGranularity(this: (idList<idDrawVert,5> *)&v169, newSize: v169.num + 1);
          if ( v169.num >= v169.size )
            v90 = &v169.list[v169.size - 1];
          else
            v90 = &v169.list[v169.num++];
          idList<idVec2,5>::PreAllocateWithGranularity(this: &v168, newSize: v168.num + 1);
          if ( v168.num >= v168.size )
            v92 = &v168.list[v168.size - 1];
          else
            v92 = &v168.list[v168.num++];
          v93 = &v169.list[v85];
          v167[0] = &v90->st;
          _R28 = v90->normal;
          v90->xyz.x = v169.list[v85].xyz.x;
          v167[0] = &v93->st;
          v90->xyz.y = v93->xyz.y;
          _R29 = v90->tangent;
          v90->xyz.z = v93->xyz.z;
          v90->st.x = v93->st.x;
          v90->st.y = v93->st.y;
          v90->normal[0] = v93->normal[0];
          v90->normal[1] = v93->normal[1];
          v90->normal[2] = v93->normal[2];
          v90->normal[3] = v93->normal[3];
          v90->tangent[0] = v93->tangent[0];
          v90->tangent[1] = v93->tangent[1];
          v90->tangent[2] = v93->tangent[2];
          DWORD2(_R7) = v93->tangent[3];
          v90->tangent[3] = BYTE11(_R7);
          v90->color[0] = v93->color[0];
          v90->color[1] = v93->color[1];
          HIDWORD(_R7) = &v177.savedNodes;
          v90->color[2] = v93->color[2];
          _R3 = &v177.savedContours.granularity;
          v90->color[3] = v93->color[3];
          v98 = v168.list;
          v92->x = v168.list[v84].x;
          v92->y = v98[v84].y;
          DWORD1(_R7) = v90->normal[2];
          LODWORD(_R7) = v90->normal[1];
          v189 = _R7;
          v99 = _R7;
          v191 = *(_QWORD *)&_R7;
          DWORD2(_R7) = v90->normal[0];
          *(_QWORD *)&v192.invalidNodes.granularity = *(_QWORD *)((char *)&_R7 + 4);
          v100 = (float)((float)((float)v99 * (float)0.0078431377) - (float)1.0);
          v101 = (float)((float)((float)*(__int64 *)((char *)&_R7 + 4) * (float)0.0078431377) - (float)1.0);
          v102 = (float)((float)((float)*(__int64 *)&_R7 * (float)0.0078431377) - (float)1.0);
          _FP5 = (float)((float)((float)((float)v102 * (float)v102)
                               + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f3, f5, f6, f0 }
          v105 = __frsqrte(_FP3);
          __asm { vmr128    v62, v127 }
          _R10 = &v177.savedNodes.num;
          __asm
          {
            lvx128    v63, r0, r17
            lvx128    v13, r0, r19
          }
          _R11 = 1;
          __asm { lvx128    v0, r0, r18 }
          _R9 = &v177.savedContours.num;
          __asm { vmr128    v56, v127 }
          _R8 = &v177;
          v110 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v105
                                                                                               * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5))
                                                                                       * (float)v105)
                                                                               - (float)1.5)
                                                               * (float)v105)
                                                       * (float)((float)((float)((float)v102 * (float)v102)
                                                                       + (float)((float)((float)v101 * (float)v101)
                                                                               + (float)((float)v100 * (float)v100)))
                                                               * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)v105
                                                                                       * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100)))
                                                                                               * (float)0.5))
                                                                               * (float)v105)
                                                                       - (float)1.5)
                                                       * (float)v105))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)v105
                                                               * (float)((float)((float)((float)v102 * (float)v102)
                                                                               + (float)((float)((float)v101
                                                                                               * (float)v101)
                                                                                       + (float)((float)v100
                                                                                               * (float)v100)))
                                                                       * (float)0.5))
                                                       * (float)v105)
                                               - (float)1.5)
                               * (float)v105));
          *(float *)&v177.savedNodes.num = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105) * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105)) - (float)1.5)
                                                                                                  * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105))
                                                                                          * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v110)
                                                                          - (float)1.5)
                                                          * (float)v110)
                                                  * (float)v102);
          *(float *)&v177.savedContours.granularity = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105) * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105)) - (float)1.5) * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105)) * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5))
                                                                                             * (float)v110)
                                                                                     - (float)1.5)
                                                                     * (float)v110)
                                                             * (float)v101);
          *(float *)&v177.savedNodes.list = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105) * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105)) - (float)1.5) * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105))
                                                                                           * (float)((float)((float)((float)v102 * (float)v102) + (float)((float)((float)v101 * (float)v101) + (float)((float)v100 * (float)v100))) * (float)0.5))
                                                                                   * (float)v110)
                                                                           - (float)1.5)
                                                           * (float)v110)
                                                   * (float)v100);
          __asm
          {
            lvlx128   v61, r0, r4
            lvlx128   v60, r0, r3
            vrlimi128 v62, v60, 8, 0
            vrlimi128 v62, v61, 4, 3
            lvlx128   v59, r0, r10
          }
          _R10 = &v177.savedContours;
          __asm
          {
            vrlimi128 v62, v59, 2, 2
            vaddfp128 v12, v94, v63
            vmaddfp   v0, v12, v0, v13
            vcfpsxws128 v58, v0, 0
            vpkswss128 v57, v90, v58
            vpkshus128 v0, v89, v57
            stvebx    v0, 0, r28
            stvebx    v0, r28, r11
            stvebx    v0, r28, r16
          }
          HIDWORD(_R7) = v90->tangent[1];
          DWORD2(_R7) = v90->tangent[0];
          __asm { lvx128    v63, r0, r17 }
          *(_QWORD *)&v192.savedNodes.granularity = *(_QWORD *)((char *)&_R7 + 4);
          v112 = *(_QWORD *)((char *)&_R7 + 4);
          *(_QWORD *)&v192.savedNodes.num = *(_QWORD *)((char *)&_R7 + 12);
          DWORD1(_R7) = v90->tangent[2];
          *(_QWORD *)&v192.savedContours.num = *(_QWORD *)&_R7;
          __asm { lvx128    v13, r0, r19 }
          v113 = (float)((float)((float)v112 * (float)0.0078431377) - (float)1.0);
          v114 = (float)((float)((float)*(__int64 *)&_R7 * (float)0.0078431377) - (float)1.0);
          v115 = (float)((float)((float)*(__int64 *)((char *)&_R7 + 12) * (float)0.0078431377) - (float)1.0);
          _FP8 = (float)((float)((float)((float)v115 * (float)v115)
                               + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f6, f8, f9, f0 }
          v118 = __frsqrte(_FP6);
          v119 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118
                                                                                               * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5))
                                                                                       * (float)v118)
                                                                               - (float)1.5)
                                                               * (float)v118)
                                                       * (float)((float)((float)((float)v115 * (float)v115)
                                                                       + (float)((float)((float)v114 * (float)v114)
                                                                               + (float)((float)v113 * (float)v113)))
                                                               * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)v118
                                                                                       * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113)))
                                                                                               * (float)0.5))
                                                                               * (float)v118)
                                                                       - (float)1.5)
                                                       * (float)v118))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)v118
                                                               * (float)((float)((float)((float)v115 * (float)v115)
                                                                               + (float)((float)((float)v114
                                                                                               * (float)v114)
                                                                                       + (float)((float)v113
                                                                                               * (float)v113)))
                                                                       * (float)0.5))
                                                       * (float)v118)
                                               - (float)1.5)
                               * (float)v118));
          __asm { lvx128    v0, r0, r18 }
          *(float *)&v177.__vftable = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118 * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)v118) - (float)1.5) * (float)v118) * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v118 * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)v118) - (float)1.5) * (float)v118)) - (float)1.5)
                                                                                             * (float)((float)-(float)((float)((float)((float)v118 * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)v118) - (float)1.5) * (float)v118))
                                                                                     * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113)))
                                                                                             * (float)0.5))
                                                                             * (float)v119)
                                                                     - (float)1.5)
                                                     * (float)v119)
                                             * (float)v113);
          *(float *)&v177.savedContours.list = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118 * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)v118) - (float)1.5) * (float)v118) * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v118 * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)v118) - (float)1.5) * (float)v118)) - (float)1.5) * (float)((float)-(float)((float)((float)((float)v118 * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)v118) - (float)1.5) * (float)v118))
                                                                                              * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5))
                                                                                      * (float)v119)
                                                                              - (float)1.5)
                                                              * (float)v119)
                                                      * (float)v115);
          *(float *)&v177.savedContours.num = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118 * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)v118) - (float)1.5) * (float)v118) * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v118 * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)v118) - (float)1.5) * (float)v118)) - (float)1.5) * (float)((float)-(float)((float)((float)((float)v118 * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5)) * (float)v118) - (float)1.5) * (float)v118))
                                                                                             * (float)((float)((float)((float)v115 * (float)v115) + (float)((float)((float)v114 * (float)v114) + (float)((float)v113 * (float)v113))) * (float)0.5))
                                                                                     * (float)v119)
                                                                             - (float)1.5)
                                                             * (float)v119)
                                                     * (float)((float)((float)*(__int64 *)&_R7 * (float)0.0078431377)
                                                             - (float)1.0));
          __asm
          {
            lvlx128   v53, r0, r8
            vrlimi128 v56, v53, 8, 0
            lvlx128   v54, r0, r9
            lvlx128   v55, r0, r10
            vrlimi128 v56, v55, 4, 3
            vrlimi128 v56, v54, 2, 2
            vaddfp128 v12, v88, v63
            vmaddfp   v0, v12, v0, v13
            vcfpsxws128 v52, v0, 0
            vpkswss128 v51, v84, v52
            vpkshus128 v0, v83, v51
            stvebx    v0, 0, r29
            stvebx    v0, r29, r11
            stvebx    v0, r29, r16
          }
          HIDWORD(v120) = idDrawVert::GetBiTangent(
                            this: v193,
                            result: &v90->xyz,
                            a3: SDWORD1(_R7),
                            a4: SDWORD2(_R7),
                            a5: *(__int64 *)((char *)&_R7 - 4));
          DWORD2(v120) = v90->tangent[0];
          LODWORD(v121) = v90->tangent[2];
          LODWORD(v122) = v90->tangent[1];
          v123 = -*(float *)(HIDWORD(v120) + 8);
          LODWORD(v120) = v90->normal[2];
          v124 = -*(float *)(HIDWORD(v120) + 4);
          v187 = *(_QWORD *)((char *)&v120 + 4);
          v125 = *(_QWORD *)((char *)&v120 + 4);
          v188 = v121;
          v190 = v122;
          v126 = *(float *)HIDWORD(v120);
          v186 = v120;
          DWORD2(v120) = v90->normal[1];
          DWORD1(v120) = v90->normal[0];
          *(_QWORD *)&v192.savedContours.granularity = *(_QWORD *)((char *)&v120 + 4);
          *(_QWORD *)&v192.invalidNodes.num = *(_QWORD *)&v120;
          v127 = (float)((float)((float)v122 * (float)0.0078431377) - (float)1.0);
          v128 = (float)((float)((float)v125 * (float)0.0078431377) - (float)1.0);
          v129 = (float)((float)((float)v121 * (float)0.0078431377) - (float)1.0);
          _FP5 = (float)((float)((float)((float)v129 * (float)v129)
                               + (float)((float)((float)v128 * (float)v128) + (float)((float)v127 * (float)v127)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f13, f5, f6, f0 }
          v132 = __frsqrte(_FP13);
          v133 = (float)((float)((float)v186 * (float)0.0078431377) - (float)1.0);
          v134 = (float)((float)((float)*(__int64 *)((char *)&v120 + 4) * (float)0.0078431377) - (float)1.0);
          v136 = (float)((float)((float)*(__int64 *)&v120 * (float)0.0078431377) - (float)1.0);
          v137 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v132
                                                                                               * (float)((float)((float)((float)v129 * (float)v129) + (float)((float)((float)v128 * (float)v128) + (float)((float)v127 * (float)v127))) * (float)0.5))
                                                                                       * (float)v132)
                                                                               - (float)1.5)
                                                               * (float)v132)
                                                       * (float)((float)((float)((float)v129 * (float)v129)
                                                                       + (float)((float)((float)v128 * (float)v128)
                                                                               + (float)((float)v127 * (float)v127)))
                                                               * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)v132
                                                                                       * (float)((float)((float)((float)v129 * (float)v129) + (float)((float)((float)v128 * (float)v128) + (float)((float)v127 * (float)v127)))
                                                                                               * (float)0.5))
                                                                               * (float)v132)
                                                                       - (float)1.5)
                                                       * (float)v132))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)v132
                                                               * (float)((float)((float)((float)v129 * (float)v129)
                                                                               + (float)((float)((float)v128
                                                                                               * (float)v128)
                                                                                       + (float)((float)v127
                                                                                               * (float)v127)))
                                                                       * (float)0.5))
                                                       * (float)v132)
                                               - (float)1.5)
                               * (float)v132));
          v138 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v132 * (float)((float)((float)((float)v129 * (float)v129) + (float)((float)((float)v128 * (float)v128) + (float)((float)v127 * (float)v127))) * (float)0.5)) * (float)v132) - (float)1.5) * (float)v132)
                                                                                               * (float)((float)((float)((float)v129 * (float)v129) + (float)((float)((float)v128 * (float)v128) + (float)((float)v127 * (float)v127))) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v132 * (float)((float)((float)((float)v129 * (float)v129) + (float)((float)((float)v128 * (float)v128) + (float)((float)v127 * (float)v127))) * (float)0.5)) * (float)v132) - (float)1.5)
                                                                                               * (float)v132))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v132 * (float)((float)((float)((float)v129 * (float)v129) + (float)((float)((float)v128 * (float)v128) + (float)((float)v127 * (float)v127))) * (float)0.5))
                                                                                               * (float)v132)
                                                                                       - (float)1.5)
                                                                       * (float)v132))
                                                       * (float)((float)((float)((float)v129 * (float)v129)
                                                                       + (float)((float)((float)v128 * (float)v128)
                                                                               + (float)((float)v127 * (float)v127)))
                                                               * (float)0.5))
                                               * (float)v137)
                                       - (float)1.5)
                       * (float)v137);
          _FP6 = (float)((float)((float)((float)v133 * (float)v133)
                               + (float)((float)((float)v136 * (float)v136) + (float)((float)v134 * (float)v134)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          v140 = (float)((float)v138 * (float)v128);
          v141 = (float)((float)v138 * (float)((float)((float)v122 * (float)0.0078431377) - (float)1.0));
          v142 = (float)((float)v138 * (float)((float)((float)v121 * (float)0.0078431377) - (float)1.0));
          v135 = 0;
          __asm { fsel      f11, f6, f4, f0 }
          v144 = __frsqrte(_FP11);
          v145 = (float)((float)-(float)((float)((float)((float)v144
                                                       * (float)((float)((float)((float)v133 * (float)v133)
                                                                       + (float)((float)((float)v136 * (float)v136)
                                                                               + (float)((float)v134 * (float)v134)))
                                                               * (float)0.5))
                                               * (float)v144)
                                       - (float)1.5)
                       * (float)v144);
          v146 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v145 * (float)((float)((float)((float)v133 * (float)v133) + (float)((float)((float)v136 * (float)v136) + (float)((float)v134 * (float)v134))) * (float)0.5))
                                                                                               * (float)v145)
                                                                                       - (float)1.5)
                                                                       * (float)v145)
                                                               * (float)((float)((float)((float)v133 * (float)v133)
                                                                               + (float)((float)((float)v136
                                                                                               * (float)v136)
                                                                                       + (float)((float)v134
                                                                                               * (float)v134)))
                                                                       * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)v145
                                                                                               * (float)((float)((float)((float)v133 * (float)v133) + (float)((float)((float)v136 * (float)v136) + (float)((float)v134 * (float)v134))) * (float)0.5))
                                                                                       * (float)v145)
                                                                               - (float)1.5)
                                                               * (float)v145))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)v145
                                                                       * (float)((float)((float)((float)v133
                                                                                               * (float)v133)
                                                                                       + (float)((float)((float)v136 * (float)v136)
                                                                                               + (float)((float)v134 * (float)v134)))
                                                                               * (float)0.5))
                                                               * (float)v145)
                                                       - (float)1.5)
                                       * (float)v145))
                       * (float)v136);
          v147 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v145 * (float)((float)((float)((float)v133 * (float)v133) + (float)((float)((float)v136 * (float)v136) + (float)((float)v134 * (float)v134))) * (float)0.5))
                                                                                               * (float)v145)
                                                                                       - (float)1.5)
                                                                       * (float)v145)
                                                               * (float)((float)((float)((float)v133 * (float)v133)
                                                                               + (float)((float)((float)v136
                                                                                               * (float)v136)
                                                                                       + (float)((float)v134
                                                                                               * (float)v134)))
                                                                       * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)v145
                                                                                               * (float)((float)((float)((float)v133 * (float)v133) + (float)((float)((float)v136 * (float)v136) + (float)((float)v134 * (float)v134))) * (float)0.5))
                                                                                       * (float)v145)
                                                                               - (float)1.5)
                                                               * (float)v145))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)v145
                                                                       * (float)((float)((float)((float)v133
                                                                                               * (float)v133)
                                                                                       + (float)((float)((float)v136 * (float)v136)
                                                                                               + (float)((float)v134 * (float)v134)))
                                                                               * (float)0.5))
                                                               * (float)v145)
                                                       - (float)1.5)
                                       * (float)v145))
                       * (float)v134);
          v148 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v145 * (float)((float)((float)((float)v133 * (float)v133) + (float)((float)((float)v136 * (float)v136) + (float)((float)v134 * (float)v134))) * (float)0.5))
                                                                                               * (float)v145)
                                                                                       - (float)1.5)
                                                                       * (float)v145)
                                                               * (float)((float)((float)((float)v133 * (float)v133)
                                                                               + (float)((float)((float)v136
                                                                                               * (float)v136)
                                                                                       + (float)((float)v134
                                                                                               * (float)v134)))
                                                                       * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)v145
                                                                                               * (float)((float)((float)((float)v133 * (float)v133) + (float)((float)((float)v136 * (float)v136) + (float)((float)v134 * (float)v134))) * (float)0.5))
                                                                                       * (float)v145)
                                                                               - (float)1.5)
                                                               * (float)v145))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)v145
                                                                       * (float)((float)((float)((float)v133
                                                                                               * (float)v133)
                                                                                       + (float)((float)((float)v136 * (float)v136)
                                                                                               + (float)((float)v134 * (float)v134)))
                                                                               * (float)0.5))
                                                               * (float)v145)
                                                       - (float)1.5)
                                       * (float)v145))
                       * (float)v133);
          if ( (float)((float)((float)((float)((float)v147 * (float)v142) - (float)((float)v148 * (float)v141))
                             * (float)-v126)
                     + (float)((float)((float)v123
                                     * (float)((float)((float)v146 * (float)v141) - (float)((float)v140 * (float)v147)))
                             + (float)((float)v124
                                     * (float)((float)((float)v140 * (float)v148) - (float)((float)v146 * (float)v142))))) >= 0.0 )
            v135 = -1;
          ++v83;
          v90->tangent[3] = v135;
          LOWORD(v77) = v170.num;
          ++v85;
          ++v84;
        }
        while ( v83 < v170.num );
      }
      v149 = 3 * (v171.num / 3);
      if ( v149 > 0 )
      {
        v150 = 0;
        v151 = (v149 - 1) / 3u + 1;
        while ( 1 )
        {
          HIWORD(v167[0]) = v171.list[v150] + v77;
          idList<unsigned short,72>::Append(this: &v171, obj: (unsigned __int16 *)v167);
          HIWORD(v167[0]) = v171.list[v150 + 2] + LOWORD(v170.num);
          idList<unsigned short,72>::Append(this: &v171, obj: (unsigned __int16 *)v167);
          HIWORD(v167[0]) = v171.list[v150 + 1] + LOWORD(v170.num);
          idList<unsigned short,72>::Append(this: &v171, obj: (unsigned __int16 *)v167);
          --v151;
          v150 += 3;
          if ( v151 == 0 )
            break;
          LOWORD(v77) = v170.num;
        }
      }
      impactTable = a11->impactTable;
      v183 = v177.invalidNodes.list;
      v184 = v177.savedNodes.size;
      v177.edgesPoolBlock.num = v174;
      v177.edgesPoolBlock.size = v176;
      *(_DWORD *)&v177.edgesPoolBlock.granularity = impactTable;
      v177.linksPool.list = (idCutterGraphManager::Link_t **)&v196;
      v180 = v73;
      v181 = v75;
      v182 = v74;
      v153 = *v175;
      *(float *)&v177.graph = v68;
      v178 = v69;
      v179 = v72;
      *(float *)&v177.edgesPool.size = v173.x;
      *(float *)&v177.edgesPool.granularity = v173.y;
      *(float *)&v177.contourManager = v173.z;
      v177.linksPool.num = v177.graphs.num;
      v177.linksPool.size = v177.graphs.size;
      *(float *)&v177.linksPool.granularity = *(float *)&v177.graphs.granularity;
      v177.nodesPool.list = (idCutterGraphManager::Node_t **)v177.linksPoolBlock.list;
      v177.nodesPool.num = v177.linksPoolBlock.num;
      v177.nodesPool.size = v177.linksPoolBlock.size;
      *(float *)&v177.nodesPool.granularity = *(float *)&v177.linksPoolBlock.granularity;
      v177.edgesPool.list = (idCutterGraphManager::Edge_t **)v177.nodesPoolBlock.list;
      v177.edgesPool.num = v177.nodesPoolBlock.num;
      v185 = 3025.0;
      idCuttableManager::Emit(
        this: &v153->cuttableManager,
        emitInfo: (const cuttablePhysicsEmitInfo_t *)&v177.edgesPoolBlock.num,
        vertices: (const idList<idDrawVert,5> *)&v169,
        st: &v168,
        indices: &v171);
      if ( v168.listStatic == 0 || v168.listStatic == 2 )
      {
        if ( v168.list != nullptr )
          idMem::Free(this: &mem, ptr: v168.list, align: ALIGN_16);
        v168.list = nullptr;
        v168.size = 0;
      }
      v168.num = 0;
      if ( v169.listStatic == 0 || v169.listStatic == 2 )
      {
        if ( v169.list != nullptr )
          idMem::Free(this: &mem, ptr: v169.list, align: ALIGN_16);
        v169.list = nullptr;
        v169.size = 0;
      }
      v169.num = 0;
      if ( v171.listStatic == 0 || v171.listStatic == 2 )
      {
        if ( v171.list != nullptr )
          idMem::Free(this: &mem, ptr: v171.list, align: ALIGN_16);
        v171.list = nullptr;
        v171.size = 0;
      }
      v171.num = 0;
      if ( v170.listStatic == 0 || v170.listStatic == 2 )
      {
        if ( v170.list != nullptr )
          idMem::Free(this: &mem, ptr: v170.list, align: ALIGN_16);
        v170.list = nullptr;
        v170.size = 0;
      }
      v170.num = 0;
      if ( v194.listStatic == 0 || v194.listStatic == 2 )
      {
        if ( v194.list != nullptr )
          idMem::Free(this: &mem, ptr: v194.list, align: ALIGN_16);
        v194.list = nullptr;
        v194.size = 0;
      }
      v194.num = 0;
      if ( LOBYTE(v192.linksPoolBlock.list) == 0 || LOBYTE(v192.linksPoolBlock.list) == 2 )
      {
        if ( v192.graphs.num != 0 )
          idMem::Free(this: &mem, ptr: (void *)v192.graphs.num, align: ALIGN_16);
        v192.graphs.num = 0;
        *(_DWORD *)&v192.graphs.granularity = 0;
      }
      v192.graphs.size = 0;
      idEarClipTriangulate::~idEarClipTriangulate(this: (idEarClipTriangulate *)&v193[0].st.y);
      v16 = v175;
      p_graphManager = *(idCutterGraphManager **)&v177.savedNodes.granularity;
      v15 = a11;
LABEL_150:
      p_graphHandle = &v15->graphHandle;
      OuterContour = idCutterGraphManager::GetOuterContour(this: p_graphManager, id: v15->graphHandle);
      InnerContour = idCutterGraphManager::GetInnerContour(this: p_graphManager, id: v15->graphHandle);
      if ( OuterContour != nullptr && v166 != 0 )
      {
        idCuttableManager::UpdateModel(
          this: &(*v16)->cuttableManager,
          infoHandle: v15->infoHandle,
          outer: OuterContour,
          inner: InnerContour);
        idCuttable::BuildClipModel(this: v15);
      }
      else
      {
        idCutterGraphManager::ReleaseGraph(this: p_graphManager, id: *p_graphHandle);
        idCutterGraphManager::FreeGraph(
          this: p_graphManager,
          id: *p_graphHandle,
          a3: v162,
          a4: v161,
          a5: v160,
          a6: v159,
          num: v158,
          a8: v157);
        v163 = v15->cutModel;
        *p_graphHandle = -1;
        v163->surfaces.list->geometry->numVerts = 0;
        v15->cutModel->surfaces.list->geometry->numIndexes = 0;
        v164 = idEntity::GetPhysics(this: v15);
        v164->UnlinkClip(this: v164);
      }
      if ( v197.listStatic == 0 || v197.listStatic == 2 )
      {
        v20 = v197.list;
        if ( v197.list != nullptr )
          goto LABEL_157;
      }
      goto LABEL_158;
    }
    idLib::Printf(
      fmt: "Discarding cut physics piece due to excess amount of vertices and/or indices.\n"
      "  Vertices  %d/64\n"
      "  Indices  %d/192\n",
      v170.num,
      v171.num);
    if ( v171.listStatic == 0 || v171.listStatic == 2 )
    {
      if ( v171.list != nullptr )
        idMem::Free(this: &mem, ptr: v171.list, align: ALIGN_16);
      v171.list = nullptr;
      v171.size = 0;
    }
    v171.num = 0;
    if ( v170.listStatic == 0 || v170.listStatic == 2 )
    {
      if ( v170.list != nullptr )
        idMem::Free(this: &mem, ptr: v170.list, align: ALIGN_16);
      v170.list = nullptr;
      v170.size = 0;
    }
    v170.num = 0;
    if ( v194.listStatic == 0 || v194.listStatic == 2 )
    {
      if ( v194.list != nullptr )
        idMem::Free(this: &mem, ptr: v194.list, align: ALIGN_16);
      v194.list = nullptr;
      v194.size = 0;
    }
    v194.num = 0;
    if ( LOBYTE(v192.linksPoolBlock.list) == 0 || LOBYTE(v192.linksPoolBlock.list) == 2 )
    {
      if ( v192.graphs.num != 0 )
        idMem::Free(this: &mem, ptr: (void *)v192.graphs.num, align: ALIGN_16);
      v192.graphs.num = 0;
      *(_DWORD *)&v192.graphs.granularity = 0;
    }
    v192.graphs.size = 0;
LABEL_149:
    idEarClipTriangulate::~idEarClipTriangulate(this: (idEarClipTriangulate *)&v193[0].st.y);
    goto LABEL_150;
  }
  if ( v197.listStatic == 0 || v197.listStatic == 2 )
  {
    v20 = v197.list;
    if ( v197.list != nullptr )
LABEL_157:
      idMem::Free(this: &mem, ptr: v20, align: ALIGN_16);
  }
LABEL_158:
  _R0 = -256;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// __unwind$492714_0
// EA  : 0x82C1B1CC
// RVA : 0x00C1B1CC
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492714_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 11360 + 2896));
}


// ========================================================================
// __unwind$492715
// EA  : 0x82C1B1F4
// RVA : 0x00C1B1F4
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492715()
{
  int v0; // r12

  idEarClipTriangulate::~idEarClipTriangulate(this: (idEarClipTriangulate *)(v0 - 11360 + 800));
}


// ========================================================================
// __unwind$492716
// EA  : 0x82C1B21C
// RVA : 0x00C1B21C
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492716()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 11360 + 512));
}


// ========================================================================
// __unwind$492717
// EA  : 0x82C1B244
// RVA : 0x00C1B244
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492717()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 11360 + 960));
}


// ========================================================================
// __unwind$492718
// EA  : 0x82C1B26C
// RVA : 0x00C1B26C
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492718()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 11360 + 128));
}


// ========================================================================
// __unwind$492719
// EA  : 0x82C1B294
// RVA : 0x00C1B294
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492719()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 11360 + 144));
}


// ========================================================================
// __unwind$492720
// EA  : 0x82C1B2BC
// RVA : 0x00C1B2BC
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492720()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 11360 + 112));
}


// ========================================================================
// __unwind$492721
// EA  : 0x82C1B2E4
// RVA : 0x00C1B2E4
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void _unwind_492721()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 11360 + 96));
}


// ========================================================================
// ?Damage@idCuttable@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82C1B310
// RVA : 0x00C1B310
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

float __fastcall idCuttable::Damage(
        idCuttable *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        int a8)
{
  float x; // r10
  float y; // r9
  int v12; // r8
  __int64 v13; // r6
  int v14; // r10
  int v15; // r9
  float *v16; // r7
  double v17; // fp1
  int v19; // [sp+8h] [-78h]
  int v20; // [sp+Ch] [-74h]
  int v21; // [sp+10h] [-70h]
  int v22; // [sp+14h] [-6Ch]
  idCuttable *v23; // [sp+18h] [-68h]
  __int64 v24; // [sp+20h] [-60h]
  __int64 v25; // [sp+28h] [-58h]
  __int64 v26; // [sp+30h] [-50h]
  idVec3 v27[2]; // [sp+50h] [-30h] BYREF

  if ( damageDef != nullptr && this->graphHandle >= 0 && (damageDef->damageTypes & 0x4000) != 0 )
  {
    x = trace->endpos.x;
    y = trace->endpos.y;
    v27[0].x = trace->fraction;
    v27[0].y = x;
    v27[0].z = y;
    idVec3::NormalizeFast(this: v27);
    v12 = *(_DWORD *)(a8 + 64);
    LODWORD(v13) = v27;
    HIDWORD(v13) = __ROL4__(v12, 32);
    idCuttable::PushCut(
      this,
      dir3d: v13,
      a3: v16,
      a4: v12,
      a5: v15,
      a6: v14,
      a7: v19,
      a8: v20,
      a9: v21,
      a10: v22,
      a11: v23,
      a12: v24,
      a13: v25,
      a14: v26);
    v17 = 0.0;
  }
  else
  {
    v17 = 0.0;
  }
  return *((float *)&v17 + 1);
}


// ========================================================================
// ?ReadLevelStateFromFile@idCuttable@@SAXPAVidFile@@AAV?$idList@UcuttableStateInfo_t@@$04@@AAVidCutterGraphState@@@Z
// EA  : 0x82C1B3B8
// RVA : 0x00C1B3B8
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __fastcall idCuttable::ReadLevelStateFromFile(
        idFile *file,
        idList<cuttableStateInfo_t,5> *stateInfo,
        idCutterGraphState *graphState)
{
  idFile_vtbl *v3; // r10
  int v7; // r30
  idFile_vtbl *v8; // r11
  idCutterGraphManager *v9; // r26
  int i; // r28
  int v11; // r4
  int v12; // r28
  char v13; // r3
  int size; // r11
  int v15; // r29
  char v16[4]; // [sp+50h] [-50h] BYREF
  int v17; // [sp+54h] [-4Ch] BYREF
  int v18; // [sp+58h] [-48h] BYREF

  v3 = file->__vftable;
  v16[0] = 1;
  v3->Read(this: file, a2: v16, a3: 1u);
  if ( v16[0] != 0 )
  {
    v7 = 0;
    v8 = file->__vftable;
    v9 = g_saveCuttableState.valueInteger == 0 ? nullptr : graphState->manager;
    v18 = 0;
    ((void (__fastcall *)(idFile *, int *, int, int))v8->Read)(
      a1: file,
      a2: &v18,
      a3: 4,
      a4: -g_saveCuttableState.valueInteger);
    for ( i = 0; i < v18; ++i )
      idCutterGraphManager::Read(manager: v9, file);
    v17 = 0;
    file->Read(this: file, a2: &v17, a3: 4u);
    v11 = v17;
    v12 = v17;
    if ( v17 <= stateInfo->size
      || (v13 = idList<cuttableStateInfo_t,5>::Resize(this: stateInfo, newsize: v17), v11 = v17, v13 != 0) )
    {
      size = stateInfo->size;
      if ( v12 < size )
        size = v12;
      stateInfo->num = size;
    }
    v15 = 0;
    if ( v11 > 0 )
    {
      do
      {
        idFile::ReadString(this: file, string: &stateInfo->list[v7].name);
        file->Read(this: file, a2: &stateInfo->list[v7].graphValid, a3: 1u);
        ++v15;
        ++v7;
      }
      while ( v15 < v17 );
    }
  }
}


// ========================================================================
// `dynamic initializer for 'g_profileCuttable''
// EA  : 0x833759F8
// RVA : 0x013759F8
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_profileCuttable__()
{
  idCVar::idCVar(
    this: &g_profileCuttable,
    name: "g_profileCuttable",
    value: "0",
    flags: 1,
    description: "If true, show and measure cuttable operation.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_profileCuttable__);
}


// ========================================================================
// `dynamic initializer for 'g_debugCuttable''
// EA  : 0x83375A50
// RVA : 0x01375A50
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugCuttable__()
{
  idCVar::idCVar(
    this: &g_debugCuttable,
    name: "g_debugCuttable",
    value: "0",
    flags: 1,
    description: "If true, show graph debug lines.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugCuttable__);
}


// ========================================================================
// `dynamic initializer for 'g_saveCuttableState''
// EA  : 0x83375AA8
// RVA : 0x01375AA8
// PDB : w:\tech5\tungsten\game\entities\cuttable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_saveCuttableState__()
{
  idCVar::idCVar(
    this: &g_saveCuttableState,
    name: "g_saveCuttableState",
    value: "1",
    flags: 1,
    description: "If true, cuttables state will be saved during checkpoints and layer transitions.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_saveCuttableState__);
}

