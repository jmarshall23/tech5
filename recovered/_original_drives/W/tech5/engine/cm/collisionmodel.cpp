
// ========================================================================
// ?SetupStreamAreaPtrs@@YAXPAUstreamAreasHeader_t@@AAUstreamAreasPtrs_t@@@Z
// EA  : 0x825C0358
// RVA : 0x005C0358
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void __fastcall SetupStreamAreaPtrs(streamAreasHeader_t *header, streamAreasPtrs_t *ptrs)
{
  unsigned __int16 *v2; // r11

  ptrs->streamAreas = (streamArea_t *)&header[1];
  v2 = (unsigned __int16 *)&header[1] + 30 * header->numStreamAreas;
  ptrs->streamAreaSubModels = v2;
  ptrs->streamAreaNameBytes = (char *)&v2[header->numStreamAreaSubModels];
}


// ========================================================================
// ?AcquireSubModelData@@YAPBUcm_subModelData_t@@ABUcm_subModel_t@@@Z
// EA  : 0x825C0388
// RVA : 0x005C0388
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

const cm_subModelData_t *__fastcall AcquireSubModelData(const cm_subModel_t *subModel)
{
  int *p_numUsers; // r30

  p_numUsers = &subModel->numUsers;
  Sys_InterlockedIncrement(value: &subModel->numUsers);
  if ( *subModel->state == 1 )
    return subModel->data;
  Sys_InterlockedDecrement(value: p_numUsers);
  return (const cm_subModelData_t *)subModel;
}


// ========================================================================
// ?ReleaseSubModelData@@YAXABUcm_subModel_t@@PBUcm_subModelData_t@@@Z
// EA  : 0x825C03E8
// RVA : 0x005C03E8
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void __fastcall ReleaseSubModelData(const cm_subModelData_t *subModel, const cm_subModelData_t *data)
{
  if ( data != subModel )
    Sys_InterlockedDecrement(value: &subModel->nodeOffset);
}


// ========================================================================
// ?GetContents@idCollisionModelLocal@@UBA_NAAH@Z
// EA  : 0x825C0400
// RVA : 0x005C0400
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::GetContents(idCollisionModelLocal *this, int *contents)
{
  *contents = this->contents;
  return 1;
}


// ========================================================================
// ?GetPolytope@idCollisionModelLocal@@UBAHHPAVidPlane@@H@Z
// EA  : 0x825C0410
// RVA : 0x005C0410
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::GetPolytope(
        idCollisionModelLocal *this,
        int polytopeFeature,
        idPlane *polytopePlanes,
        int maxPlanes)
{
  int v8; // r28
  const cm_subModelData_t *v9; // r3
  cm_subModel_t *v10; // r30
  cm_subModel_t *v11; // r11
  int v13; // r11
  int v14; // r31
  char *v15; // r10
  idPlane *v16; // r8
  idPlane *v17; // r11
  int v18; // r9
  float *p_a; // r7
  cm_subModel_t *v20; // r11
  cm_subModelPtrs_t v21; // [sp+50h] [-60h] BYREF

  if ( this->modelType == CM_SPHEREMODEL )
    return 0;
  v8 = (polytopeFeature >> 16) & 0x1FFF;
  v9 = AcquireSubModelData(subModel: &this->polygonModel.subModels[v8]);
  v10 = (cm_subModel_t *)v9;
  if ( v9->header.loadedSize == 32 )
  {
    v11 = &this->polygonModel.subModels[v8];
    if ( v9 != (const cm_subModelData_t *)v11 )
      Sys_InterlockedDecrement(value: &v11->numUsers);
    return 0;
  }
  idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(subModelPtrs: &v21, subModelData: v9);
  v13 = (16 * polytopeFeature) & 0xFFFF0;
  v14 = 0;
  v15 = (char *)v21.polytopes + v13;
  if ( *(&v21.polytopes->numPlanes + v13) != 0 )
  {
    v16 = v21.polytopePlanes;
    v17 = polytopePlanes;
    do
    {
      if ( v14 >= maxPlanes )
        break;
      v18 = *((unsigned __int16 *)v15 + 7) + v14++;
      p_a = &v16[v18].a;
      v17->a = *p_a;
      v17->b = p_a[1];
      v17->c = p_a[2];
      v17->d = p_a[3];
      ++v17;
    }
    while ( v14 < (unsigned __int8)v15[13] );
  }
  v20 = &this->polygonModel.subModels[v8];
  if ( v10 != v20 )
    Sys_InterlockedDecrement(value: &v20->numUsers);
  return v14;
}


// ========================================================================
// ?GetPolytopes@idCollisionModelLocal@@UBAHPAHHPAVidPlane@@H@Z
// EA  : 0x825C0530
// RVA : 0x005C0530
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::GetPolytopes(
        idCollisionModelLocal *this,
        int *polytopeNumPlanes,
        int maxPolytopes,
        idPlane *polytopePlanes,
        int maxPlanes)
{
  int v11; // r28
  int v12; // r31
  int v13; // r23
  int v14; // r26
  cm_subModel_t *v15; // r30
  int v16; // r5
  idPlane *v17; // r7
  unsigned __int8 *p_numPlanes; // r9
  int *v19; // r6
  int v20; // r11
  int v21; // r10
  idPlane *v22; // r11
  int v23; // r8
  float *p_a; // r4
  cm_subModel_t *v25; // r11
  cm_subModelPtrs_t v26; // [sp+50h] [-90h] BYREF

  if ( this->modelType == CM_SPHEREMODEL )
    return 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  if ( this->polygonModel.numSubModels > 0 )
  {
    v14 = 0;
    do
    {
      v15 = &this->polygonModel.subModels[v14];
      Sys_InterlockedIncrement(value: &v15->numUsers);
      if ( *v15->state == 1 )
        v15 = (cm_subModel_t *)v15->data;
      else
        Sys_InterlockedDecrement(value: &v15->numUsers);
      if ( v15->header.loadedSize != 32 )
      {
        idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
          subModelPtrs: &v26,
          subModelData: (const cm_subModelData_t *)v15);
        v16 = 0;
        if ( (int)v15[1].state > 0 )
        {
          v17 = v26.polytopePlanes;
          p_numPlanes = &v26.polytopes->numPlanes;
          v19 = &polytopeNumPlanes[v11 - 1];
          do
          {
            if ( v11 >= maxPolytopes )
              break;
            v20 = *p_numPlanes;
            if ( v20 + v12 <= maxPlanes )
            {
              *++v19 = v20;
              ++v11;
              v21 = 0;
              if ( *p_numPlanes != 0 )
              {
                v22 = &polytopePlanes[v12];
                do
                {
                  if ( v12 >= maxPlanes )
                    break;
                  ++v12;
                  v23 = *(unsigned __int16 *)(p_numPlanes + 1) + v21++;
                  p_a = &v17[v23].a;
                  v22->a = *p_a;
                  v22->b = p_a[1];
                  v22->c = p_a[2];
                  v22->d = p_a[3];
                  ++v22;
                }
                while ( v21 < *p_numPlanes );
              }
            }
            ++v16;
            p_numPlanes += 16;
          }
          while ( v16 < (int)v15[1].state );
        }
      }
      v25 = &this->polygonModel.subModels[v14];
      if ( v15 != v25 )
        Sys_InterlockedDecrement(value: &v25->numUsers);
      ++v13;
      ++v14;
    }
    while ( v13 < this->polygonModel.numSubModels );
  }
  return v11;
}


// ========================================================================
// ?GetTotalMemory@idCollisionModelLocal@@QBAHXZ
// EA  : 0x825C06D0
// RVA : 0x005C06D0
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::GetTotalMemory(idCollisionModelLocal *this)
{
  int numSubModels; // r4
  int v2; // r9
  int v3; // r8
  int v4; // r11
  int v5; // r30
  cm_subModel_t *subModels; // r7
  int v7; // r10
  int totalSize; // r6

  numSubModels = this->polygonModel.numSubModels;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 16 * (3 * numSubModels + this->polygonModel.numModelTreeNodes) + 116;
  if ( numSubModels >= 2 )
  {
    subModels = this->polygonModel.subModels;
    v7 = 0;
    do
    {
      v4 += 2;
      v2 += subModels[v7].header.totalSize;
      totalSize = subModels[v7 + 1].header.totalSize;
      v7 += 2;
      v3 += totalSize;
    }
    while ( v4 < numSubModels - 1 );
  }
  if ( v4 >= numSubModels )
    return v3 + v2 + v5;
  else
    return v3 + v2 + this->polygonModel.subModels[v4].header.totalSize + v5;
}


// ========================================================================
// ?GetLoadedMemory@idCollisionModelLocal@@QBAHXZ
// EA  : 0x825C0780
// RVA : 0x005C0780
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::GetLoadedMemory(idCollisionModelLocal *this)
{
  int numSubModels; // r11
  int v3; // r26
  int v4; // r27
  int v5; // r29
  cm_subModel_t *v6; // r30
  cm_subModel_t *v7; // r11

  numSubModels = this->polygonModel.numSubModels;
  v3 = 0;
  v4 = 16 * (3 * numSubModels + this->polygonModel.numModelTreeNodes) + 116;
  if ( numSubModels > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->polygonModel.subModels[v5];
      Sys_InterlockedIncrement(value: &v6->numUsers);
      if ( *v6->state == 1 )
        v6 = (cm_subModel_t *)v6->data;
      else
        Sys_InterlockedDecrement(value: &v6->numUsers);
      v7 = &this->polygonModel.subModels[v5];
      v4 += v6->header.loadedSize;
      if ( v6 != v7 )
        Sys_InterlockedDecrement(value: &v7->numUsers);
      ++v3;
      ++v5;
    }
    while ( v3 < this->polygonModel.numSubModels );
  }
  return v4;
}


// ========================================================================
// ??0idCollisionModelLocal@@QAA@XZ
// EA  : 0x825C08A8
// RVA : 0x005C08A8
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

idCollisionModelLocal *__fastcall idCollisionModelLocal::idCollisionModelLocal(idCollisionModelLocal *this)
{
  idResource::idResource(this);
  this->modelType = CM_POLYGONMODEL;
  this->__vftable = (idCollisionModelLocal_vtbl *)&idCollisionModelLocal::`vftable';
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  this->contents = 0;
  this->isWorldModel = false;
  this->isTraceModel = false;
  this->isConvex = false;
  this->isStreamed = false;
  this->streamFilePtr = nullptr;
  this->binaryFileTime = -1;
  this->sourceFileTime = -1;
  this->polygonModel.numModelTreeNodes = 0;
  this->polygonModel.numSubModels = 0;
  this->polygonModel.modelTreeNodes = nullptr;
  this->polygonModel.subModels = nullptr;
  this->polygonModel.subModelState = nullptr;
  this->sphereModel = nullptr;
  this->streamAreas = nullptr;
  this->memoryMappedFile = nullptr;
  return this;
}


// ========================================================================
// ?MakeDefault@idCollisionModelLocal@@QAAXXZ
// EA  : 0x825C0970
// RVA : 0x005C0970
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void __fastcall idCollisionModelLocal::MakeDefault(idCollisionModelLocal *this)
{
  idBounds *p_bounds; // r28
  idAutoRenderParms *v3; // r11
  unsigned __int8 *v4; // r3
  cm_subModel_t *subModels; // r30

  p_bounds = &this->bounds;
  this->bounds.b[0].x = -8.0;
  this->bounds.b[0].y = -8.0;
  v3 = rp;
  this->bounds.b[0].z = -8.0;
  this->bounds.b[1].x = 8.0;
  this->bounds.b[1].y = 8.0;
  this->bounds.b[1].z = 8.0;
  this->contents = idParmBlock::GetInteger(
                     this: (idParmBlock *)&mtrTraceModel.r[2].nextOnHashChain,
                     parm: v3->contentFlags);
  this->isWorldModel = false;
  this->isConvex = true;
  this->isTraceModel = false;
  this->polygonModel.numModelTreeNodes = 0;
  this->polygonModel.modelTreeNodes = nullptr;
  this->polygonModel.numSubModels = 1;
  this->polygonModel.subModels = (cm_subModel_t *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\engine\\cm\\CollisionModel.cpp(543) : TAG_COLLISION",
                                                    size: 0x30u,
                                                    tag: TAG_COLLISION,
                                                    zeroBuffer: false,
                                                    align: ALIGN_16,
                                                    heap: HEAP_DEFAULTHEAP);
  this->polygonModel.subModelState = (volatile char *)idMem::AllocWithLocation(
                                                        this: &mem,
                                                        location: "w:\\tech5\\engine\\cm\\CollisionModel.cpp(544) : TAG_COLLISION",
                                                        size: this->polygonModel.numSubModels,
                                                        tag: TAG_COLLISION,
                                                        zeroBuffer: false,
                                                        align: ALIGN_16,
                                                        heap: HEAP_DEFAULTHEAP);
  v4 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\cm\\CollisionModel.cpp(546) : TAG_COLLISION",
                            size: 0x300u,
                            tag: TAG_COLLISION,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  subModels = this->polygonModel.subModels;
  subModels->header.bounds = this->bounds;
  subModels->header.totalSize = 768;
  subModels->header.loadedSize = 768;
  subModels->data = idPolygonModelCollisionDetection::SetupSubModelForBounds(data: v4, size: 768, bounds: p_bounds);
  subModels->fileOffset = -1;
  subModels->numUsers = 0;
  subModels->state = this->polygonModel.subModelState;
  *this->polygonModel.subModelState = 1;
}


// ========================================================================
// ?GetBounds@idCollisionModelLocal@@UBA_NAAVidBounds@@@Z
// EA  : 0x825C0AE8
// RVA : 0x005C0AE8
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::GetBounds(idCollisionModelLocal *this, idBounds *bounds)
{
  *bounds = this->bounds;
  return 1;
}


// ========================================================================
// ?GetVertex@idCollisionModelLocal@@UBA_NHAAVidVec3@@@Z
// EA  : 0x825C0B28
// RVA : 0x005C0B28
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::GetVertex(idCollisionModelLocal *this, int vertexFeature, idVec3 *vertex)
{
  int v6; // r30
  const cm_subModelData_t *v7; // r3
  cm_subModel_t *v8; // r31
  cm_subModel_t *v9; // r11
  float *v11; // r11
  cm_subModel_t *v12; // r11
  cm_subModelPtrs_t v13; // [sp+50h] [-60h] BYREF

  if ( this->modelType == CM_SPHEREMODEL )
    return 0;
  v6 = (vertexFeature >> 16) & 0x1FFF;
  v7 = AcquireSubModelData(subModel: &this->polygonModel.subModels[v6]);
  v8 = (cm_subModel_t *)v7;
  if ( v7->header.loadedSize == 32 )
  {
    v9 = &this->polygonModel.subModels[v6];
    if ( v7 != (const cm_subModelData_t *)v9 )
      Sys_InterlockedDecrement(value: &v9->numUsers);
    return 0;
  }
  idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(subModelPtrs: &v13, subModelData: v7);
  v11 = (float *)((char *)&v13.vertices->p.x + ((16 * vertexFeature) & 0xFFFF0));
  vertex->x = *v11;
  vertex->y = v11[1];
  vertex->z = v11[2];
  v12 = &this->polygonModel.subModels[v6];
  if ( v8 != v12 )
    Sys_InterlockedDecrement(value: &v12->numUsers);
  return 1;
}


// ========================================================================
// ?GetEdge@idCollisionModelLocal@@UBA_NHAAVidVec3@@0@Z
// EA  : 0x825C0BF8
// RVA : 0x005C0BF8
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::GetEdge(idCollisionModelLocal *this, int edgeFeature, idVec3 *start, idVec3 *end)
{
  int v8; // r27
  const cm_subModelData_t *v9; // r3
  cm_subModel_t *v10; // r31
  cm_subModel_t *v11; // r11
  cm_vertex_t *vertices; // r9
  cm_edge_t *v14; // r10
  float *v15; // r11
  float *v16; // r11
  cm_subModel_t *v17; // r11
  cm_subModelPtrs_t v18; // [sp+50h] [-60h] BYREF

  if ( this->modelType == CM_SPHEREMODEL )
    return 0;
  v8 = (edgeFeature >> 16) & 0x1FFF;
  v9 = AcquireSubModelData(subModel: &this->polygonModel.subModels[v8]);
  v10 = (cm_subModel_t *)v9;
  if ( v9->header.loadedSize == 32 )
  {
    v11 = &this->polygonModel.subModels[v8];
    if ( v9 != (const cm_subModelData_t *)v11 )
      Sys_InterlockedDecrement(value: &v11->numUsers);
    return 0;
  }
  idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(subModelPtrs: &v18, subModelData: v9);
  vertices = v18.vertices;
  v14 = (cm_edge_t *)((char *)v18.edges + ((4 * edgeFeature) & 0x3FFFC));
  v15 = (float *)((char *)&v18.vertices->p.x + __ROL4__(v14->vertexNum[0], 4));
  start->x = *v15;
  start->y = v15[1];
  start->z = v15[2];
  v16 = (float *)((char *)&vertices->p.x + __ROL4__(v14->vertexNum[1], 4));
  end->x = *v16;
  end->y = v16[1];
  end->z = v16[2];
  v17 = &this->polygonModel.subModels[v8];
  if ( v10 != v17 )
    Sys_InterlockedDecrement(value: &v17->numUsers);
  return 1;
}


// ========================================================================
// ?GetJoint@idCollisionModelLocal@@UBA?AV?$idIndex@FW4invalidJointIndex_t@@@@H@Z
// EA  : 0x825C0D00
// RVA : 0x005C0D00
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

idCollisionModelLocal *__fastcall idCollisionModelLocal::GetJoint(
        idCollisionModelLocal *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        int sphereFeature)
{
  int v3; // r11

  v3 = *(_DWORD *)&result[52].value;
  if ( v3 != 0 && (sphereFeature >= 0 || sphereFeature < *(unsigned __int16 *)(v3 + 36)) )
    HIWORD(this->__vftable) = *(unsigned __int8 *)(*(unsigned __int16 *)(*(_DWORD *)&result[52].value + 40)
                                                 + *(_DWORD *)&result[52].value
                                                 + sphereFeature);
  else
    HIWORD(this->__vftable) = NULL_JOINT_INDEX;
  return this;
}


// ========================================================================
// ?GetMaxResidentMemory@idCollisionModelLocal@@QBAHPAVidVec3@@@Z
// EA  : 0x825C0D48
// RVA : 0x005C0D48
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::GetMaxResidentMemory(idCollisionModelLocal *this, idVec3 *location)
{
  if ( location != nullptr )
  {
    location->z = 0.0;
    location->y = 0.0;
    location->x = 0.0;
  }
  return idCollisionModelLocal::GetTotalMemory(this);
}


// ========================================================================
// ?GetBinaryFileName@idCollisionModelLocal@@SAXPBDAAVidStr@@AA_N2@Z
// EA  : 0x825C0D78
// RVA : 0x005C0D78
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void __fastcall idCollisionModelLocal::GetBinaryFileName(
        const char *modelName,
        idStr *binaryFileName,
        bool *inMapFolder,
        bool *isWorld)
{
  int v8; // r11
  int v9; // r3
  bool v10; // r11
  char v11[304]; // [sp+50h] [-130h] BYREF

  if ( idStr::Icmpn(s1: modelName, s2: "maps/", n: 5) != 0 )
  {
    *isWorld = false;
    *inMapFolder = false;
    fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bcm", a4: modelName, a5: v11, a6: 256);
    idStr::operator=(this: binaryFileName, text: v11);
  }
  else
  {
    v8 = 0;
    if ( *modelName != 0 )
    {
      do
        ++v8;
      while ( modelName[v8] != 0 );
    }
    *inMapFolder = true;
    if ( v8 < 5 || (v9 = idStr::Icmp(s1: &modelName[v8 - 5], s2: "world"), v10 = true, v9 != 0) )
      v10 = false;
    *isWorld = v10;
    idStr::operator=(this: binaryFileName, text: modelName);
    idStr::SetFileExtension(this: binaryFileName, extension: "bcm");
  }
}


// ========================================================================
// ?ReloadIfStale@idCollisionModelLocal@@UAA_NXZ
// EA  : 0x825C0FE0
// RVA : 0x005C0FE0
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::ReloadIfStale(idCollisionModelLocal *this)
{
  unsigned int v2; // r28
  bool v4; // [sp+50h] [-60h] BYREF
  bool v5; // [sp+51h] [-5Fh] BYREF
  idStr v6[2]; // [sp+60h] [-50h] BYREF

  v6[0].len = 0;
  v6[0].allocedAndFlag = 20;
  v6[0].data = v6[0].baseBuffer;
  v6[0].baseBuffer[0] = 0;
  idCollisionModelLocal::GetBinaryFileName(
    modelName: this->name.str,
    binaryFileName: v6,
    inMapFolder: &v4,
    isWorld: &v5);
  v2 = fileSystem->GetTimestamp(this: fileSystem, a2: v6[0].data, a3: false);
  if ( v2 == -1 && idCollisionModelBuilder::IsAnimatedRenderModel(fileName: this->name.str) )
    goto LABEL_7;
  if ( v2 == this->binaryFileTime )
  {
    if ( v4 || fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false) == this->sourceFileTime )
    {
LABEL_7:
      idStr::FreeData(this: v6);
      return 0;
    }
    fileSystem->RemoveFile(this: fileSystem, a2: v6[0].data, a3: FSPATH_BASE);
  }
  this->LoadResource(this);
  idStr::FreeData(this: v6);
  return 1;
}


// ========================================================================
// __unwind$227309
// EA  : 0x825C1118
// RVA : 0x005C1118
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void _unwind_227309()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?FreeData@idCollisionModelLocal@@QAAXXZ
// EA  : 0x825C1140
// RVA : 0x005C1140
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void __fastcall idCollisionModelLocal::FreeData(idCollisionModelLocal *this)
{
  idMemoryMappedFile *memoryMappedFile; // r30
  int v3; // r28
  int v4; // r30
  cm_subModelData_t *data; // r4
  idFile *streamFilePtr; // r11
  idFile *v7; // r30

  if ( this->isStreamed )
    idStreamFileCache::Flush(this: streamFileCache);
  memoryMappedFile = this->memoryMappedFile;
  if ( memoryMappedFile != nullptr )
  {
    idMemoryMappedFile::~idMemoryMappedFile(this: this->memoryMappedFile);
    idMem::Free(this: &mem, ptr: memoryMappedFile, align: ALIGN_16);
    this->memoryMappedFile = nullptr;
  }
  else
  {
    v3 = 0;
    if ( this->polygonModel.numSubModels > 0 )
    {
      v4 = 0;
      do
      {
        data = this->polygonModel.subModels[v4].data;
        if ( data != nullptr )
          idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
        ++v3;
        ++v4;
      }
      while ( v3 < this->polygonModel.numSubModels );
    }
  }
  idMem::Free(this: &mem, ptr: this->polygonModel.modelTreeNodes, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->polygonModel.subModels, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: (void *)this->polygonModel.subModelState, align: ALIGN_16);
  this->polygonModel.numModelTreeNodes = 0;
  this->polygonModel.numSubModels = 0;
  this->polygonModel.modelTreeNodes = nullptr;
  this->polygonModel.subModels = nullptr;
  this->polygonModel.subModelState = nullptr;
  idMem::Free(this: &mem, ptr: this->sphereModel, align: ALIGN_16);
  this->sphereModel = nullptr;
  idMem::Free(this: &mem, ptr: this->streamAreas, align: ALIGN_16);
  streamFilePtr = this->streamFilePtr;
  this->streamAreas = nullptr;
  if ( streamFilePtr != nullptr )
  {
    v7 = this->streamFilePtr;
    if ( v7 != resourceManager->GetCacheFile(this: resourceManager) && v7 != nullptr )
      ((void (__fastcall *)(idFile *, int))v7->dtr_idFile)(a1: v7, a2: 1);
  }
  this->streamFilePtr = nullptr;
  this->binaryFileTime = -1;
  this->sourceFileTime = -1;
}


// ========================================================================
// ?GetPolygon@idCollisionModelLocal@@UBA_NHAAVidFixedWinding@@@Z
// EA  : 0x825C12C0
// RVA : 0x005C12C0
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::GetPolygon(
        idCollisionModelLocal *this,
        int polygonFeature,
        idFixedWinding *winding)
{
  int v6; // r26
  const cm_subModelData_t *v7; // r3
  cm_subModel_t *v8; // r27
  int v9; // r30
  int v10; // r31
  char *v11; // r11
  __int128 v12; // r8
  float *v13; // r11
  double v14; // fp13
  double v15; // fp12
  cm_subModel_t *v16; // r11
  cm_subModel_t *v18; // r11
  idVec5 v19; // [sp+60h] [-90h] BYREF
  cm_subModelPtrs_t v20; // [sp+80h] [-70h] BYREF

  if ( this->modelType == CM_SPHEREMODEL )
    return 0;
  v6 = (polygonFeature >> 16) & 0x1FFF;
  v7 = AcquireSubModelData(subModel: &this->polygonModel.subModels[v6]);
  v8 = (cm_subModel_t *)v7;
  if ( v7 == nullptr || v7->header.loadedSize == 32 )
  {
    v18 = &this->polygonModel.subModels[v6];
    if ( v7 != (const cm_subModelData_t *)v18 )
      Sys_InterlockedDecrement(value: &v18->numUsers);
    return 0;
  }
  idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(subModelPtrs: &v20, subModelData: v7);
  winding->Clear(this: winding);
  v9 = (16 * polygonFeature) & 0xFFFF0;
  v10 = 0;
  if ( *(&v20.polygons->numEdges + v9) != 0 )
  {
    v11 = (char *)v20.polygons + v9;
    do
    {
      HIDWORD(v12) = v20.polygonEdges[*((unsigned __int16 *)v11 + 7) + v10];
      DWORD1(v12) = 2 * ((HIDWORD(v12) >> 15) + 2 * (WORD1(v12) & 0x3FFF));
      v13 = (float *)((char *)&v20.vertices->p.x
                    + __ROL4__(*(unsigned __int16 *)((char *)v20.edges->vertexNum + DWORD1(v12)), 4));
      v14 = v13[1];
      DWORD2(v12) = *((unsigned __int16 *)v13 + 6);
      v15 = v13[2];
      LODWORD(v12) = *((unsigned __int16 *)v13 + 7);
      v19.x = *v13;
      v19.y = v14;
      v19.z = v15;
      v19.t = (float)(__int64)v12;
      v19.s = (float)*(__int64 *)((char *)&v12 + 4);
      idWinding::AddPoint(this: winding, v: &v19);
      ++v10;
      v11 = (char *)v20.polygons + v9;
    }
    while ( v10 < *(&v20.polygons->numEdges + v9) );
  }
  v16 = &this->polygonModel.subModels[v6];
  if ( v8 != v16 )
    Sys_InterlockedDecrement(value: &v16->numUsers);
  return 1;
}


// ========================================================================
// ??1idCollisionModelLocal@@UAA@XZ
// EA  : 0x825C1460
// RVA : 0x005C1460
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void __fastcall idCollisionModelLocal::~idCollisionModelLocal(idCollisionModelLocal *this)
{
  this->__vftable = (idCollisionModelLocal_vtbl *)&idCollisionModelLocal::`vftable';
  idCollisionModelLocal::FreeData(this);
  this->__vftable = (idCollisionModelLocal_vtbl *)&idCollisionModel::`vftable';
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$227818
// EA  : 0x825C14BC
// RVA : 0x005C14BC
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void _unwind_227818()
{
  int v0; // r12

  idCollisionModel::~idCollisionModel(this: *(idCollisionModel **)(v0 - 112 + 132));
}


// ========================================================================
// ?Write_Binary@idCollisionModelLocal@@QAA_NXZ
// EA  : 0x825C14F0
// RVA : 0x005C14F0
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::Write_Binary(idCollisionModelLocal *this)
{
  idFile *v2; // r29
  idFile *v4; // r25
  idFile *v5; // r23
  int v6; // r22
  int v7; // r26
  cm_subModel_t *subModels; // r11
  cm_subModelData_t *data; // r30
  int numNodes; // r10
  int i; // r11
  int numPrimitiveIndices; // r10
  int j; // r11
  int numMaterials; // r10
  int k; // r11
  int numPolygons; // r10
  int m; // r11
  int numPolygonEdges; // r10
  int n; // r11
  int numEdges; // r10
  int ii; // r11
  int numVertices; // r10
  int jj; // r11
  int numPolytopes; // r10
  int kk; // r11
  int numPolytopePlanes; // r10
  int mm; // r11
  cm_subModelData_t *v28; // r30
  int v29; // r11
  int nn; // r10
  int v31; // r10
  int i1; // r11
  int v33; // r10
  int i2; // r11
  int v35; // r10
  int i3; // r11
  int v37; // r10
  int i4; // r11
  int v39; // r10
  int i5; // r11
  int v41; // r10
  int i6; // r11
  int v43; // r10
  int i7; // r11
  int v45; // r10
  int i8; // r11
  bool v47; // [sp+50h] [-E0h] BYREF
  bool v48; // [sp+51h] [-DFh] BYREF
  int v49; // [sp+54h] [-DCh] BYREF
  int totalSize; // [sp+58h] [-D8h] BYREF
  idStr v51; // [sp+60h] [-D0h] BYREF
  idStr v52; // [sp+80h] [-B0h] BYREF
  cm_subModelPtrs_t v53[3]; // [sp+A0h] [-90h] BYREF

  v51.len = 0;
  v51.allocedAndFlag = 20;
  v51.data = v51.baseBuffer;
  v51.baseBuffer[0] = 0;
  idCollisionModelLocal::GetBinaryFileName(
    modelName: this->name.str,
    binaryFileName: &v51,
    inMapFolder: &v48,
    isWorld: &v47);
  v2 = fileSystem->OpenFileWrite(this: fileSystem, a2: v51.data, a3: 0);
  if ( v2 == nullptr )
  {
    idLib::Warning(fmt: "Could not open %s", v51.data);
    idStr::FreeData(this: &v51);
    return 0;
  }
  idLib::Printf(fmt: "writing %s...\n", v51.data);
  v4 = v2;
  v5 = v2;
  if ( this->isStreamed )
  {
    idStr::idStr(this: &v52, text: &v51);
    idStr::SetFileExtension(this: &v52, extension: "sbcm");
    v4 = fileSystem->OpenFileWrite(this: fileSystem, a2: v52.data, a3: 0);
    if ( v4 == nullptr )
    {
      idLib::Warning(fmt: "Could not open %s", v52.data);
      ((void (__fastcall *)(idFile *, int))v2->dtr_idFile)(a1: v2, a2: 1);
      idStr::FreeData(this: &v52);
      idStr::FreeData(this: &v51);
      return 0;
    }
    idStr::SetFileExtension(this: &v52, extension: "tbcm");
    v5 = fileSystem->OpenFileWrite(this: fileSystem, a2: v52.data, a3: 0);
    if ( v5 == nullptr )
    {
      idLib::Warning(fmt: "Could not open %s", v52.data);
      ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
      ((void (__fastcall *)(idFile *, int))v2->dtr_idFile)(a1: v2, a2: 1);
      idStr::FreeData(this: &v52);
      idStr::FreeData(this: &v51);
      return 0;
    }
    idStr::FreeData(this: &v52);
  }
  v2->Write(this: v2, a2: &BCM_FILE_ID, a3: 4u);
  v2->Write(this: v2, a2: &this->sourceFileTime, a3: 4u);
  v2->Write(this: v2, a2: &this->bounds, a3: 24u);
  v2->Write(this: v2, a2: &this->contents, a3: 4u);
  v2->Write(this: v2, a2: &this->isWorldModel, a3: 1u);
  v2->Write(this: v2, a2: &this->isTraceModel, a3: 1u);
  v2->Write(this: v2, a2: &this->isConvex, a3: 1u);
  v2->Write(this: v2, a2: &this->isStreamed, a3: 1u);
  v2->Write(this: v2, a2: &this->polygonModel, a3: 4u);
  v2->Write(this: v2, a2: this->polygonModel.modelTreeNodes, a3: 16 * this->polygonModel.numModelTreeNodes);
  v2->Write(this: v2, a2: &this->polygonModel.numSubModels, a3: 4u);
  v6 = 0;
  if ( this->polygonModel.numSubModels > 0 )
  {
    v7 = 0;
    do
    {
      v2->Write(this: v2, a2: &this->polygonModel.subModels[v7], a3: 32u);
      subModels = this->polygonModel.subModels;
      data = subModels[v7].data;
      if ( data != nullptr )
      {
        idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(subModelPtrs: v53, subModelData: subModels[v7].data);
        numNodes = data->numNodes;
        for ( i = 0; i < numNodes; ++i )
          ;
        numPrimitiveIndices = data->numPrimitiveIndices;
        for ( j = 0; j < numPrimitiveIndices; ++j )
          ;
        numMaterials = data->numMaterials;
        for ( k = 0; k < numMaterials; ++k )
          ;
        numPolygons = data->numPolygons;
        for ( m = 0; m < numPolygons; ++m )
          ;
        numPolygonEdges = data->numPolygonEdges;
        for ( n = 0; n < numPolygonEdges; ++n )
          ;
        numEdges = data->numEdges;
        for ( ii = 0; ii < numEdges; ++ii )
          ;
        numVertices = data->numVertices;
        for ( jj = 0; jj < numVertices; ++jj )
          ;
        numPolytopes = data->numPolytopes;
        for ( kk = 0; kk < numPolytopes; ++kk )
          ;
        numPolytopePlanes = data->numPolytopePlanes;
        for ( mm = 0; mm < numPolytopePlanes; ++mm )
          ;
        v4->Write(
          this: v4,
          a2: this->polygonModel.subModels[v7].data,
          a3: this->polygonModel.subModels[v7].header.totalSize);
        v28 = this->polygonModel.subModels[v7].data;
        idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(subModelPtrs: v53, subModelData: v28);
        v29 = v28->numNodes;
        for ( nn = 0; nn < v29; ++nn )
          ;
        v31 = v28->numPrimitiveIndices;
        for ( i1 = 0; i1 < v31; ++i1 )
          ;
        v33 = v28->numMaterials;
        for ( i2 = 0; i2 < v33; ++i2 )
          ;
        v35 = v28->numPolygons;
        for ( i3 = 0; i3 < v35; ++i3 )
          ;
        v37 = v28->numPolygonEdges;
        for ( i4 = 0; i4 < v37; ++i4 )
          ;
        v39 = v28->numEdges;
        for ( i5 = 0; i5 < v39; ++i5 )
          ;
        v41 = v28->numVertices;
        for ( i6 = 0; i6 < v41; ++i6 )
          ;
        v43 = v28->numPolytopes;
        for ( i7 = 0; i7 < v43; ++i7 )
          ;
        v45 = v28->numPolytopePlanes;
        for ( i8 = 0; i8 < v45; ++i8 )
          ;
        if ( v5 != v2 )
          v5->Write(
            this: v5,
            a2: this->polygonModel.subModels[v7].data,
            a3: this->polygonModel.subModels[v7].header.totalSize);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->polygonModel.numSubModels );
  }
  if ( this->isStreamed )
  {
    totalSize = this->streamAreas->totalSize;
    v2->Write(this: v2, a2: &BCM_FILE_ID, a3: 4u);
    v2->Write(this: v2, a2: &totalSize, a3: 4u);
    v2->Write(this: v2, a2: this->streamAreas, a3: totalSize);
  }
  v2->Write(this: v2, a2: &BCM_FILE_ID, a3: 4u);
  if ( v4 != v2 )
  {
    v4->Write(this: v4, a2: &BCM_FILE_ID, a3: 4u);
    ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
  }
  if ( v5 != v2 )
  {
    v49 = 911033154;
    v5->Write(this: v5, a2: &v49, a3: 4u);
    ((void (__fastcall *)(idFile *, int))v5->dtr_idFile)(a1: v5, a2: 1);
  }
  ((void (__fastcall *)(idFile *, int))v2->dtr_idFile)(a1: v2, a2: 1);
  idStr::FreeData(this: &v51);
  return 1;
}


// ========================================================================
// __unwind$227867
// EA  : 0x825C1C28
// RVA : 0x005C1C28
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void _unwind_227867()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 96));
}


// ========================================================================
// __unwind$227868
// EA  : 0x825C1C50
// RVA : 0x005C1C50
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void _unwind_227868()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 128));
}


// ========================================================================
// ?Load_Binary@idCollisionModelLocal@@QAA_NXZ
// EA  : 0x825C1C80
// RVA : 0x005C1C80
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::Load_Binary(idCollisionModelLocal *this)
{
  const char *str; // r3
  idFile *v3; // r3
  idFile *v4; // r27
  bool *p_isStreamed; // r15
  int *p_numSubModels; // r21
  volatile char *v8; // r3
  int numSubModels; // r11
  int v10; // r20
  int v11; // r26
  int v12; // r29
  cm_subModel_t *v13; // r11
  cm_subModelData_t *data; // r28
  int numNodes; // r11
  int i; // r10
  int numPrimitiveIndices; // r10
  int j; // r11
  int numMaterials; // r10
  int k; // r11
  int numPolygons; // r10
  int m; // r11
  int numPolygonEdges; // r10
  int n; // r11
  int numEdges; // r10
  int ii; // r11
  int numVertices; // r10
  int jj; // r11
  int numPolytopes; // r10
  int kk; // r11
  int numPolytopePlanes; // r10
  int mm; // r11
  streamAreasHeader_t *v33; // r3
  signed int v34; // r5
  idFile *v35; // r3
  idFile *v36; // r3
  idFile *v37; // r3
  int v38; // r10
  int v39; // r9
  cm_subModel_t *v40; // r11
  __int64 v41; // r8
  idMemoryMappedFile *v42; // r3
  idMemoryMappedFile *v43; // r3
  int v44; // r11
  int v45; // r28
  int v46; // r29
  idFile *streamFilePtr; // r29
  int v48; // [sp+50h] [-150h] BYREF
  signed int v49; // [sp+54h] [-14Ch] BYREF
  bool v50; // [sp+58h] [-148h] BYREF
  bool v51; // [sp+59h] [-147h] BYREF
  idStr v52; // [sp+60h] [-140h] BYREF
  unsigned int v53; // [sp+80h] [-120h] BYREF
  _DWORD v54[2]; // [sp+88h] [-118h] BYREF
  int v55; // [sp+90h] [-110h] BYREF
  _DWORD v56[3]; // [sp+94h] [-10Ch] BYREF
  idStr v57; // [sp+A0h] [-100h] BYREF
  idStr v58; // [sp+C0h] [-E0h] BYREF
  cm_subModelPtrs_t v59[4]; // [sp+E0h] [-C0h] BYREF

  v52.len = 0;
  str = this->name.str;
  v52.allocedAndFlag = 20;
  v52.data = v52.baseBuffer;
  v52.baseBuffer[0] = 0;
  idCollisionModelLocal::GetBinaryFileName(modelName: str, binaryFileName: &v52, inMapFolder: &v50, isWorld: &v51);
  v3 = fileSystem->OpenFileRead(this: fileSystem, a2: v52.data, a3: 1, a4: 0);
  v4 = v3;
  if ( v3 == nullptr )
  {
    idStr::FreeData(this: &v52);
    return 0;
  }
  this->binaryFileTime = v3->Timestamp(this: v3);
  v4->Read(this: v4, a2: &v48, a3: 4u);
  if ( v48 != 1111706934 && v48 != 1111706933 )
  {
    idLib::Warning(fmt: "%s is not a binary collision model file", v52.data);
    ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
    idCollisionModelLocal::FreeData(this);
    idStr::FreeData(this: &v52);
    return 0;
  }
  v4->Read(this: v4, a2: &this->sourceFileTime, a3: 4u);
  v4->Read(this: v4, a2: &this->bounds, a3: 24u);
  v4->Read(this: v4, a2: &this->contents, a3: 4u);
  v4->Read(this: v4, a2: &this->isWorldModel, a3: 1u);
  v4->Read(this: v4, a2: &this->isTraceModel, a3: 1u);
  v4->Read(this: v4, a2: &this->isConvex, a3: 1u);
  p_isStreamed = &this->isStreamed;
  v4->Read(this: v4, a2: &this->isStreamed, a3: 1u);
  if ( v48 == 1111706933 )
    *p_isStreamed = false;
  v4->Read(this: v4, a2: &this->polygonModel, a3: 4u);
  this->polygonModel.modelTreeNodes = (cm_modelTreeNode_t *)idMem::AllocWithLocation(
                                                              this: &mem,
                                                              location: "w:\\tech5\\engine\\cm\\CollisionModel.cpp(1313) : TAG_COLLISION",
                                                              size: 16 * this->polygonModel.numModelTreeNodes,
                                                              tag: TAG_COLLISION,
                                                              zeroBuffer: false,
                                                              align: ALIGN_16,
                                                              heap: HEAP_DEFAULTHEAP);
  ((void (__fastcall *)(idFile *))v4->Read)(a1: v4);
  p_numSubModels = &this->polygonModel.numSubModels;
  v4->Read(this: v4, a2: &this->polygonModel.numSubModels, a3: 4u);
  this->polygonModel.subModels = (cm_subModel_t *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\engine\\cm\\CollisionModel.cpp(1318) : TAG_COLLISION",
                                                    size: 48 * this->polygonModel.numSubModels,
                                                    tag: TAG_COLLISION,
                                                    zeroBuffer: false,
                                                    align: ALIGN_16,
                                                    heap: HEAP_DEFAULTHEAP);
  v8 = (volatile char *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\engine\\cm\\CollisionModel.cpp(1319) : TAG_COLLISION",
                          size: this->polygonModel.numSubModels,
                          tag: TAG_COLLISION,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  numSubModels = this->polygonModel.numSubModels;
  this->polygonModel.subModelState = v8;
  v10 = 0;
  v11 = 0;
  if ( numSubModels > 0 )
  {
    v12 = 0;
    do
    {
      v4->Read(this: v4, a2: &this->polygonModel.subModels[v12], a3: 32u);
      this->polygonModel.subModels[v12].data = nullptr;
      this->polygonModel.subModels[v12].fileOffset = -1;
      this->polygonModel.subModels[v12].numUsers = 0;
      this->polygonModel.subModels[v12].state = &this->polygonModel.subModelState[v11];
      this->polygonModel.subModelState[v11] = -1;
      v13 = &this->polygonModel.subModels[v12];
      if ( v13->header.totalSize != 32 )
      {
        if ( *p_isStreamed )
        {
          v13->fileOffset = v10;
          v10 += this->polygonModel.subModels[v12].header.totalSize;
        }
        else
        {
          this->polygonModel.subModels[v12].data = (cm_subModelData_t *)idMem::AllocWithLocation(
                                                                          this: &mem,
                                                                          location: "w:\\tech5\\engine\\cm\\CollisionModel.cpp(1358"
                                                                          ") : TAG_COLLISION",
                                                                          size: v13->header.totalSize,
                                                                          tag: TAG_COLLISION,
                                                                          zeroBuffer: false,
                                                                          align: ALIGN_16,
                                                                          heap: HEAP_DEFAULTHEAP);
          this->polygonModel.subModelState[v11] = 1;
          v4->Read(
            this: v4,
            a2: this->polygonModel.subModels[v12].data,
            a3: this->polygonModel.subModels[v12].header.totalSize);
          data = this->polygonModel.subModels[v12].data;
          idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(subModelPtrs: v59, subModelData: data);
          numNodes = data->numNodes;
          for ( i = 0; i < numNodes; ++i )
            ;
          numPrimitiveIndices = data->numPrimitiveIndices;
          for ( j = 0; j < numPrimitiveIndices; ++j )
            ;
          numMaterials = data->numMaterials;
          for ( k = 0; k < numMaterials; ++k )
            ;
          numPolygons = data->numPolygons;
          for ( m = 0; m < numPolygons; ++m )
            ;
          numPolygonEdges = data->numPolygonEdges;
          for ( n = 0; n < numPolygonEdges; ++n )
            ;
          numEdges = data->numEdges;
          for ( ii = 0; ii < numEdges; ++ii )
            ;
          numVertices = data->numVertices;
          for ( jj = 0; jj < numVertices; ++jj )
            ;
          numPolytopes = data->numPolytopes;
          for ( kk = 0; kk < numPolytopes; ++kk )
            ;
          numPolytopePlanes = data->numPolytopePlanes;
          for ( mm = 0; mm < numPolytopePlanes; ++mm )
            ;
        }
      }
      ++v11;
      ++v12;
    }
    while ( v11 < *p_numSubModels );
  }
  v4->Read(this: v4, a2: &v48, a3: 4u);
  if ( v48 != 1111706934 && v48 != 1111706933 )
    goto LABEL_34;
  if ( !*p_isStreamed )
    goto LABEL_64;
  v49 = 0;
  v4->Read(this: v4, a2: &v49, a3: 4u);
  if ( v49 <= 0 )
  {
    idLib::Warning(fmt: "%s has to stream areas", v52.data);
    ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
    idCollisionModelLocal::FreeData(this);
    idStr::FreeData(this: &v52);
    return 0;
  }
  v33 = (streamAreasHeader_t *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\engine\\cm\\CollisionModel.cpp(1416) : TAG_COLLISION",
                                 size: v49,
                                 tag: TAG_COLLISION,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  v34 = v49;
  this->streamAreas = v33;
  v4->Read(this: v4, a2: v33, a3: v34);
  v4->Read(this: v4, a2: &v48, a3: 4u);
  if ( v48 != 1111706934 && v48 != 1111706933 )
  {
LABEL_34:
    idLib::Warning(fmt: "%s is invalid (possibly corrupt)", v52.data);
    ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
    idCollisionModelLocal::FreeData(this);
    idStr::FreeData(this: &v52);
    return 0;
  }
  if ( idLib::production == PROD_BUILDING )
  {
    idStr::idStr(this: &v58, text: &v52);
    resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 14u);
    idStr::SetFileExtension(this: &v58, extension: "sbcm");
    v35 = fileSystem->OpenFileRead(this: fileSystem, a2: v58.data, a3: 1, a4: 0);
    if ( v35 != nullptr )
      ((void (__fastcall *)(idFile *, int))v35->dtr_idFile)(a1: v35, a2: 1);
    resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
    resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 9u);
    idStr::SetFileExtension(this: &v58, extension: "tbcm");
    v36 = fileSystem->OpenFileRead(this: fileSystem, a2: v58.data, a3: 1, a4: 0);
    if ( v36 != nullptr )
      ((void (__fastcall *)(idFile *, int))v36->dtr_idFile)(a1: v36, a2: 1);
    resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
    idStr::FreeData(this: &v58);
  }
  idStr::idStr(this: &v57, text: &v52);
  idStr::SetFileExtension(this: &v57, extension: "sbcm");
  v37 = resourceManager->GetCacheFile(this: resourceManager);
  this->streamFilePtr = v37;
  if ( v37 != nullptr )
  {
    resourceManager->GetCacheFileInfo(
      this: resourceManager,
      a2: v57.data,
      a3: (__int64 *)v54,
      a4: (unsigned int *)&v55,
      a5: &v53,
      a6: v56,
      a7: false);
    v38 = 0;
    if ( *p_numSubModels > 0 )
    {
      v39 = 0;
      do
      {
        ++v38;
        v40 = &this->polygonModel.subModels[v39++];
        v40->fileOffset += v54[1];
      }
      while ( v38 < *p_numSubModels );
    }
    if ( cm_memoryMap.valueInteger != 0 )
    {
      v42 = (idMemoryMappedFile *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                    size: 0x28u,
                                    tag: TAG_NEW,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
      v56[1] = v42;
      if ( v42 != nullptr )
        v43 = idMemoryMappedFile::idMemoryMappedFile(
                this: v42,
                file_: this->streamFilePtr,
                fileOffset: __SPAIR64__(v54[1], v53),
                length: v41);
      else
        v43 = nullptr;
      this->memoryMappedFile = v43;
    }
    goto LABEL_55;
  }
  resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 0);
  this->streamFilePtr = fileSystem->OpenFileRead(this: fileSystem, a2: v57.data, a3: 1, a4: 0);
  resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
  if ( this->streamFilePtr != nullptr )
  {
LABEL_55:
    if ( cm_enableStreaming.valueInteger == 0 )
    {
      v44 = *p_numSubModels;
      v45 = 0;
      *p_isStreamed = false;
      if ( v44 > 0 )
      {
        v46 = 0;
        do
        {
          this->polygonModel.subModels[v46].data = (cm_subModelData_t *)idMem::AllocWithLocation(
                                                                          this: &mem,
                                                                          location: "w:\\tech5\\engine\\cm\\CollisionModel.cpp(1498"
                                                                          ") : TAG_COLLISION",
                                                                          size: this->polygonModel.subModels[v46].header.totalSize,
                                                                          tag: TAG_COLLISION,
                                                                          zeroBuffer: false,
                                                                          align: ALIGN_16,
                                                                          heap: HEAP_DEFAULTHEAP);
          this->polygonModel.subModelState[v45] = 1;
          this->streamFilePtr->ReadOfs(
            this: this->streamFilePtr,
            a2: this->polygonModel.subModels[v46].fileOffset,
            a3: this->polygonModel.subModels[v46].data,
            a4: this->polygonModel.subModels[v46].header.totalSize);
          ++v45;
          ++v46;
        }
        while ( v45 < *p_numSubModels );
      }
      streamFilePtr = this->streamFilePtr;
      if ( streamFilePtr != resourceManager->GetCacheFile(this: resourceManager) && streamFilePtr != nullptr )
        ((void (__fastcall *)(idFile *, int))streamFilePtr->dtr_idFile)(a1: streamFilePtr, a2: 1);
      this->streamFilePtr = nullptr;
    }
    idStr::FreeData(this: &v57);
LABEL_64:
    ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
    idStr::FreeData(this: &v52);
    return 1;
  }
  idLib::Warning(fmt: "Could not open %s", v57.data);
  ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
  idCollisionModelLocal::FreeData(this);
  idStr::FreeData(this: &v57);
  idStr::FreeData(this: &v52);
  return 0;
}


// ========================================================================
// __unwind$228366
// EA  : 0x825C2730
// RVA : 0x005C2730
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void _unwind_228366()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$228367
// EA  : 0x825C2758
// RVA : 0x005C2758
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void _unwind_228367()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 192));
}


// ========================================================================
// __unwind$228368
// EA  : 0x825C2780
// RVA : 0x005C2780
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void _unwind_228368()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 160));
}


// ========================================================================
// __unwind$228369
// EA  : 0x825C27A8
// RVA : 0x005C27A8
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void __fastcall _unwind_228369(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 416 + 152), tag: a2);
}


// ========================================================================
// ?LoadResource@idCollisionModelLocal@@UAAXXZ
// EA  : 0x825C2830
// RVA : 0x005C2830
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void __fastcall idCollisionModelLocal::LoadResource(idCollisionModelLocal *this)
{
  const char *v2; // r4
  const idStaticModel *v3; // r4
  const char *str; // r4
  const idDeclMD6 *v5; // r4

  idCollisionModelLocal::FreeData(this);
  if ( (unsigned __int8)idCollisionModelLocal::Load_Binary(this) == 0 )
  {
    if ( idStr::Icmpn(s1: this->name.str, s2: "maps/", n: 5) != 0
      || idStr::Find(searchIn: this->name.str, searchFor: "/megabreakable", casesensitive: true, start: 0, end: -1) != -1 )
    {
      if ( idCollisionModelBuilder::IsStaticRenderModel(fileName: this->name.str) )
      {
        v3 = staticModelManager->FindStaticModel(this: staticModelManager, a2: this->name.str, a3: false);
        if ( v3 == nullptr )
        {
          idResource::SetResourceError(this, fmt: "Missing model '%s' while generating collision", this->name.str);
LABEL_18:
          idCollisionModelLocal::MakeDefault(this);
          return;
        }
        if ( idCollisionModelBuilder::BuildForStaticModel(
               model: this,
               staticModel: v3,
               submodelIndices: nullptr,
               numSubmodelIndices: 0,
               optionalModelName: nullptr) )
        {
          return;
        }
        v2 = "idCollisionModelBuilder::BuildForStaticModel failed for '%s'";
      }
      else if ( idCollisionModelBuilder::IsAnimatedRenderModel(fileName: this->name.str) )
      {
        str = this->name.str;
        if ( str != nullptr
          && (v5 = (const idDeclMD6 *)idDeclInfo::FindWithInheritance(
                                        this: &idDeclMD6::resourceList,
                                        name: str,
                                        makeDefault: false)) != nullptr )
        {
          if ( idCollisionModelBuilder::BuildForDeclMD6(model: this, md6Decl: v5) )
            return;
          v2 = "idCollisionModelBuilder::BuildForDeclMD6 failed for '%s'";
        }
        else
        {
          v2 = "Missing model '%s' while generating collision";
        }
      }
      else
      {
        v2 = "idCollisionModelBuilder cannot create collision model for '%s'";
      }
    }
    else
    {
      v2 = "map collision model load failed '%s'";
    }
    idResource::SetResourceError(this, fmt: v2, this->name.str);
    goto LABEL_18;
  }
}


// ========================================================================
// ?GetBox@idCollisionModelLocal@@UBA_NAAVidBox@@@Z
// EA  : 0x825C29C0
// RVA : 0x005C29C0
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

int __fastcall idCollisionModelLocal::GetBox(idCollisionModelLocal *this, idBox *box)
{
  double y; // fp1
  double z; // fp31
  double x; // fp2
  double v7; // fp13
  double v8; // fp12
  double v9; // fp10
  double v10; // fp8
  double v11; // fp30
  double v12; // fp11
  double v13; // fp28
  double v14; // fp7
  double v15; // fp6
  double v16; // fp9
  double v17; // fp3
  double v18; // fp0
  int v19; // r21
  int v20; // r24
  cm_subModel_t *v21; // r30
  const cm_subModelData_t *data; // r27
  int v23; // r26
  int v24; // r28
  int v25; // r30
  cm_polygon_t *v26; // r29
  unsigned int v27; // r6
  cm_subModel_t *v28; // r11
  idVec3 *list; // r30
  idList<idVec3,5> v31; // [sp+60h] [-C0h] BYREF
  cm_subModelPtrs_t v32; // [sp+70h] [-B0h] BYREF

  if ( this->modelType == CM_SPHEREMODEL )
  {
    y = this->bounds.b[1].y;
    z = this->bounds.b[1].z;
    x = this->bounds.b[1].x;
    v7 = mat3_identity.mat[0].x;
    v8 = mat3_identity.mat[0].y;
    v9 = mat3_identity.mat[1].x;
    v10 = mat3_identity.mat[1].z;
    v11 = (float)((float)(this->bounds.b[0].x + this->bounds.b[1].x) * (float)0.5);
    v12 = mat3_identity.mat[0].z;
    v13 = (float)((float)(this->bounds.b[0].y + this->bounds.b[1].y) * (float)0.5);
    v14 = mat3_identity.mat[2].x;
    v15 = mat3_identity.mat[2].z;
    v16 = mat3_identity.mat[1].y;
    v17 = (float)((float)(this->bounds.b[0].z + this->bounds.b[1].z) * (float)0.5);
    v18 = mat3_identity.mat[2].y;
    box->center.y = (float)(this->bounds.b[0].y + this->bounds.b[1].y) * (float)0.5;
    box->center.x = v11;
    box->center.z = v17;
    box->extents.x = (float)x - (float)v11;
    box->extents.y = (float)y - (float)v13;
    box->extents.z = (float)z - (float)v17;
    box->axis.mat[0].x = v7;
    box->axis.mat[1].x = v9;
    box->axis.mat[0].y = v8;
    box->axis.mat[0].z = v12;
    box->axis.mat[1].y = v16;
    box->axis.mat[1].z = v10;
    box->axis.mat[2].x = v14;
    box->axis.mat[2].y = v18;
    box->axis.mat[2].z = v15;
  }
  else
  {
    memset(&v31, 0, 14);
    *(_WORD *)&v31.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
    v19 = 0;
    if ( this->polygonModel.numSubModels > 0 )
    {
      v20 = 0;
      do
      {
        v21 = &this->polygonModel.subModels[v20];
        Sys_InterlockedIncrement(value: &v21->numUsers);
        if ( *v21->state == 1 )
        {
          data = v21->data;
        }
        else
        {
          Sys_InterlockedDecrement(value: &v21->numUsers);
          data = (const cm_subModelData_t *)v21;
        }
        if ( data->header.loadedSize != 32 )
        {
          idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(subModelPtrs: &v32, subModelData: data);
          v23 = 0;
          if ( data->numPolygons > 0 )
          {
            v24 = 0;
            do
            {
              v25 = 0;
              v26 = &v32.polygons[v24];
              if ( v32.polygons[v24].numEdges != 0 )
              {
                do
                {
                  v27 = v32.polygonEdges[v26->firstEdge + v25];
                  idList<idAngles,5>::Append(
                    this: &v31,
                    obj: (const idVec3 *)((char *)&v32.vertices->p
                                   + __ROL4__(
                                       *(unsigned __int16 *)((char *)v32.edges->vertexNum
                                                           + ((4 * v27) & 0xFFFC)
                                                           + ((v27 >> 14) & 2)),
                                       4)));
                  ++v25;
                }
                while ( v25 < v26->numEdges );
              }
              ++v23;
              ++v24;
            }
            while ( v23 < data->numPolygons );
          }
        }
        v28 = &this->polygonModel.subModels[v20];
        if ( data != (const cm_subModelData_t *)v28 )
          Sys_InterlockedDecrement(value: &v28->numUsers);
        ++v19;
        ++v20;
      }
      while ( v19 < this->polygonModel.numSubModels );
    }
    list = v31.list;
    if ( v31.num != 0 )
    {
      idBox::FromPoints(this: box, points: v31.list, numPoints: v31.num);
    }
    else
    {
      idLib::Warning(fmt: "idCollisionModel::GetBox: collision model %s has no vertices", this->name.str);
      box->center.z = 0.0;
      box->center.y = 0.0;
      box->center.x = 0.0;
      box->extents.z = -1.0e30;
      box->extents.y = -1.0e30;
      box->extents.x = -1.0e30;
      box->axis.mat[2].z = 1.0;
      box->axis.mat[1].y = 1.0;
      box->axis.mat[0].x = 1.0;
      box->axis.mat[1].z = 0.0;
      box->axis.mat[0].z = 0.0;
      box->axis.mat[0].y = 0.0;
      box->axis.mat[2].y = 0.0;
      box->axis.mat[2].x = 0.0;
      box->axis.mat[1].x = 0.0;
    }
    if ( (v31.listStatic == 0 || v31.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
  return 1;
}


// ========================================================================
// __unwind$228962
// EA  : 0x825C2CEC
// RVA : 0x005C2CEC
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void _unwind_228962()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 288 + 96));
}


// ========================================================================
// `dynamic initializer for 'idCollisionModelLocal::resourceList''
// EA  : 0x83335188
// RVA : 0x01335188
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idCollisionModelLocal::resourceList__()
{
  idResourceList::idResourceList(this: &idCollisionModelLocal::resourceList, typeName: "cm");
  idCollisionModelLocal::resourceList.__vftable = (idTypedResourceList<idCollisionModelLocal>_vtbl *)&idTypedResourceList<idCollisionModelLocal>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idCollisionModelLocal::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'mtrTraceModel''
// EA  : 0x833351D8
// RVA : 0x013351D8
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void _dynamic_initializer_for__mtrTraceModel__()
{
  mtrTraceModel.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &mtrTraceModel;
}


// ========================================================================
// `dynamic initializer for 'cm_enableStreaming''
// EA  : 0x833351F8
// RVA : 0x013351F8
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_enableStreaming__()
{
  idCVar::idCVar(
    this: &cm_enableStreaming,
    name: "cm_enableStreaming",
    value: "1",
    flags: 1,
    description: "enable streaming",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_enableStreaming__);
}


// ========================================================================
// `dynamic initializer for 'cm_memoryMap''
// EA  : 0x83335250
// RVA : 0x01335250
// PDB : w:\tech5\engine\cm\collisionmodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_memoryMap__()
{
  idCVar::idCVar(
    this: &cm_memoryMap,
    name: "cm_memoryMap",
    value: "1",
    flags: 1,
    description: "enable the memory mapped file streaming",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_memoryMap__);
}

