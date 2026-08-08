
// ========================================================================
// ?SetupForSubModel@idModelCheckCounts@@QAAXPBUcm_subModelData_t@@@Z
// EA  : 0x825E6B78
// RVA : 0x005E6B78
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_cache.cpp
// ========================================================================

void __fastcall idModelCheckCounts::SetupForSubModel(idModelCheckCounts *this, const cm_subModelData_t *subModelData)
{
  unsigned __int8 *v2; // r11
  unsigned __int8 *v3; // r11

  this->vertexCheckCounts = (unsigned __int8 *)this;
  v2 = &this->baseCheckCounts[(int)((subModelData->numVertices + 7) & 0xFFFFFFF8) >> 3];
  this->edgeCheckCounts = v2;
  v3 = &v2[(int)((subModelData->numEdges + 7) & 0xFFFFFFF8) / 8];
  this->polygonCheckCounts = v3;
  this->polytopeCheckCounts = &v3[(int)((subModelData->numPolygons + 7) & 0xFFFFFFF8) >> 3];
  XMemSet(
    dest: this,
    c: 0,
    count: (((int)((subModelData->numPolytopes + 7) & 0xFFFFFFF8) >> 3)
   + ((int)((subModelData->numVertices + 7) & 0xFFFFFFF8) >> 3)
   + ((int)((subModelData->numPolygons + 7) & 0xFFFFFFF8) >> 3)
   + ((int)((subModelData->numEdges + 7) & 0xFFFFFFF8) >> 3)
   + 15)
  & 0xFFFFFFF0);
}


// ========================================================================
// ?Init@idTraceWork@@QAAXXZ
// EA  : 0x825E6C40
// RVA : 0x005E6C40
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_cache.cpp
// ========================================================================

void __fastcall idTraceWork::Init(idTraceWork *this)
{
  this->numVerts = 0;
  this->numEdges = 0;
  this->numPolys = 0;
  this->contents = 0;
  this->start.w = 0.0;
  this->start.z = 0.0;
  this->start.y = 0.0;
  this->start.x = 0.0;
  this->end.w = 0.0;
  this->end.z = 0.0;
  this->end.y = 0.0;
  this->end.x = 0.0;
  this->dir.w = 0.0;
  this->dir.z = 0.0;
  this->dir.y = 0.0;
  this->dir.x = 0.0;
  this->negDir.w = 0.0;
  this->negDir.z = 0.0;
  this->negDir.y = 0.0;
  this->negDir.x = 0.0;
  this->trmTransform.mat[0] = 0.0;
  this->trmTransform.mat[1] = 0.0;
  this->trmTransform.mat[2] = 0.0;
  this->trmTransform.mat[3] = 0.0;
  this->trmTransform.mat[4] = 0.0;
  this->trmTransform.mat[5] = 0.0;
  this->trmTransform.mat[6] = 0.0;
  this->trmTransform.mat[7] = 0.0;
  this->trmTransform.mat[8] = 0.0;
  this->trmTransform.mat[9] = 0.0;
  this->trmTransform.mat[10] = 0.0;
  this->trmTransform.mat[11] = 0.0;
  this->trmBoundsMin.w = 0.0;
  this->trmBoundsMin.z = 0.0;
  this->trmBoundsMin.y = 0.0;
  this->trmBoundsMin.x = 0.0;
  this->trmBoundsMax.w = 0.0;
  this->trmBoundsMax.z = 0.0;
  this->trmBoundsMax.y = 0.0;
  this->trmBoundsMax.x = 0.0;
  this->trmExtents.w = 0.0;
  this->trmExtents.z = 0.0;
  this->trmExtents.y = 0.0;
  this->trmExtents.x = 0.0;
  this->traceBoundsMin.w = 0.0;
  this->traceBoundsMin.z = 0.0;
  this->traceBoundsMin.y = 0.0;
  this->traceBoundsMin.x = 0.0;
  this->traceBoundsMax.w = 0.0;
  this->traceBoundsMax.z = 0.0;
  this->traceBoundsMax.y = 0.0;
  this->traceBoundsMax.x = 0.0;
  *(_DWORD *)&this->traceBoundsShort.b[1][1] = 0;
  *(_DWORD *)&this->traceBoundsShort.b[0][2] = 0;
  this->traceBoundsShort.b[0][1] = 0;
  this->traceBoundsShort.b[0][0] = 0;
  this->heartPlane1.d = 0.0;
  this->heartPlane1.c = 0.0;
  this->heartPlane1.b = 0.0;
  this->heartPlane1.a = 0.0;
  this->heartPlane2.d = 0.0;
  this->heartPlane2.c = 0.0;
  this->heartPlane2.b = 0.0;
  this->heartPlane2.a = 0.0;
  this->maxDistFromHeartPlane1 = 0.0;
  this->maxDistFromHeartPlane2 = 0.0;
  this->fraction = 0.0;
  this->angle = 0.0;
  this->negAngle = 0.0;
  this->maxTan = 0.0;
  this->initialTan = 0.0;
  this->origin.w = 0.0;
  this->origin.z = 0.0;
  this->origin.y = 0.0;
  this->origin.x = 0.0;
  this->axis.w = 0.0;
  this->axis.z = 0.0;
  this->axis.y = 0.0;
  this->axis.x = 0.0;
  this->ZAxisTransform.mat[0] = 0.0;
  this->ZAxisTransform.mat[1] = 0.0;
  this->ZAxisTransform.mat[2] = 0.0;
  this->ZAxisTransform.mat[3] = 0.0;
  this->ZAxisTransform.mat[4] = 0.0;
  this->ZAxisTransform.mat[5] = 0.0;
  this->ZAxisTransform.mat[6] = 0.0;
  this->ZAxisTransform.mat[7] = 0.0;
  this->ZAxisTransform.mat[8] = 0.0;
  this->ZAxisTransform.mat[9] = 0.0;
  this->ZAxisTransform.mat[10] = 0.0;
  this->ZAxisTransform.mat[11] = 0.0;
  this->endTransform.mat[0] = 0.0;
  this->endTransform.mat[1] = 0.0;
  this->endTransform.mat[2] = 0.0;
  this->endTransform.mat[3] = 0.0;
  this->endTransform.mat[4] = 0.0;
  this->endTransform.mat[5] = 0.0;
  this->endTransform.mat[6] = 0.0;
  this->endTransform.mat[7] = 0.0;
  this->endTransform.mat[8] = 0.0;
  this->endTransform.mat[9] = 0.0;
  this->endTransform.mat[10] = 0.0;
  this->endTransform.mat[11] = 0.0;
  this->traceType = TRACE_TRANSLATION;
  this->contactDepth = 0.0;
  this->isConvex = false;
  this->quickExit = false;
  XMemSet(dest: &this->modelCheckCounts, c: 0, count: 0x3A0u);
  this->modelCheckCounts.checkCount = 0;
  this->modelCheckCounts.vertexCheckCounts = nullptr;
  this->modelCheckCounts.edgeCheckCounts = nullptr;
  this->modelCheckCounts.polygonCheckCounts = nullptr;
  this->modelCheckCounts.polytopeCheckCounts = nullptr;
  this->traceResult = nullptr;
  this->contactsResult = nullptr;
  this->clipResult = nullptr;
  this->pad = 0;
  this->subModelNum = 0;
  this->polygonSideCache.side = 0;
  XMemSet(dest: this, c: 0, count: 0x200u);
  XMemSet(dest: this->edges, c: 0, count: 0x200u);
  XMemSet(dest: this->polys, c: 0, count: 0x400u);
  XMemSet(dest: this->vertexPosition, c: 0, count: 0x200u);
  XMemSet(dest: this->vertexEndPosition, c: 0, count: 0x200u);
  XMemSet(dest: this->vertexPluecker, c: 0, count: 0x300u);
  XMemSet(dest: this->edgePluecker, c: 0, count: 0x300u);
  XMemSet(dest: this->edgeZAxisPluecker, c: 0, count: 0x300u);
  XMemSet(dest: this->edgeNormal, c: 0, count: 0x200u);
  XMemSet(dest: this->vertIsUsed, c: 0, count: 0x20u);
  XMemSet(dest: this->edgeIsUsed, c: 0, count: 0x20u);
  XMemSet(dest: this->polyIsUsed, c: 0, count: 0x10u);
  XMemSet(dest: this->polygonEdgeSideCache, c: 0, count: 0x50u);
  XMemSet(dest: this->polygonVertexSideCache, c: 0, count: 0x50u);
  XMemSet(dest: this->polygonEdgePlueckerCache, c: 0, count: 0x180u);
  XMemSet(dest: this->polygonVertexPlueckerCache, c: 0, count: 0x180u);
  XMemSet(dest: &this->subModelPtrs, c: 0, count: 0x28u);
  XMemSet(dest: this->profile, c: 0, count: 0x14u);
}


// ========================================================================
// ?AllocTraceWork@idPolygonModelCollisionDetection@@SAPAVidTraceWork@@XZ
// EA  : 0x825E6F90
// RVA : 0x005E6F90
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_cache.cpp
// ========================================================================

idTraceWork *__fastcall idPolygonModelCollisionDetection::AllocTraceWork()
{
  idTraceWork *v0; // r31

  v0 = (idTraceWork *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\engine\\cm\\jobs\\polygonmodel\\PolygonModel_cache.cpp(150) : TAG_COLLISION",
                        size: 0x241Cu,
                        tag: TAG_COLLISION,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  idTraceWork::Init(this: v0);
  return v0;
}


// ========================================================================
// ?GetTraceWorkSPUSize@idPolygonModelCollisionDetection@@SAHXZ
// EA  : 0x825E6FE8
// RVA : 0x005E6FE8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_cache.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::GetTraceWorkSPUSize()
{
  return 9244;
}

