
// ========================================================================
// ?CM_R_CountChildren@@YAHPAUcm_buildNode_t@@@Z
// EA  : 0x825C2D18
// RVA : 0x005C2D18
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall CM_R_CountChildren(cm_buildNode_t *node)
{
  int v3; // r30

  if ( node->planeType == -1 )
    return 0;
  v3 = CM_R_CountChildren(node: node->children[1]);
  return v3 + CM_R_CountChildren(node: node->children[0]) + 2;
}


// ========================================================================
// ?CM_R_TestOptimisation@@YAXPAUcm_buildNode_t@@AAH1@Z
// EA  : 0x825C2D78
// RVA : 0x005C2D78
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall CM_R_TestOptimisation(cm_buildNode_t *node, int *numSavedPolygonIndices, int *numSavedPolytopeIndices)
{
  int planeType; // r9
  cm_buildNode_t *i; // r31
  cm_buildPolygonRef_t *polygons; // r11
  int j; // r10
  cm_buildPolytopeRef_t *polytopes; // r11
  int k; // r8
  int v11; // r11
  int v12; // r3
  int v13; // r9
  int v14; // r11

  planeType = node->planeType;
  for ( i = node; i->planeType != -1; planeType = i->planeType )
  {
    polygons = i->polygons;
    for ( j = 0; polygons != nullptr; ++j )
      polygons = polygons->next;
    polytopes = i->polytopes;
    for ( k = 0; polytopes != nullptr; ++k )
      polytopes = polytopes->next;
    if ( j != 0 || k != 0 )
    {
      if ( planeType == -1 )
      {
        v11 = 0;
      }
      else
      {
        CM_R_CountChildren(node: i->children[1]);
        v12 = CM_R_CountChildren(node: i->children[0]);
        v11 = v13 + v12 + 2;
      }
      v14 = v11 - 1;
      *numSavedPolygonIndices += v14 * j;
      *numSavedPolytopeIndices += v14 * k;
    }
    CM_R_TestOptimisation(node: i->children[0], numSavedPolygonIndices, numSavedPolytopeIndices);
    i = i->children[1];
  }
}


// ========================================================================
// ?AllocNode@idCollisionModelBuilder@@CAPAUcm_buildNode_t@@PAUcm_buildModel_t@@H@Z
// EA  : 0x825C2E68
// RVA : 0x005C2E68
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

cm_buildNode_t *__fastcall idCollisionModelBuilder::AllocNode(cm_buildModel_t *model, int blockSize)
{
  cm_buildNodeBlock_t *nodeBlocks; // r11
  unsigned int v5; // r30
  cm_buildNodeBlock_t *v6; // r3
  cm_buildNode_t *nextNode; // r11
  int v8; // ctr
  cm_buildNodeBlock_t *v9; // r11
  cm_buildNode_t *result; // r3

  nodeBlocks = model->nodeBlocks;
  if ( nodeBlocks == nullptr || nodeBlocks->nextNode == nullptr )
  {
    v5 = 100 * blockSize + 12;
    v6 = (cm_buildNodeBlock_t *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(645) : TAG_COLLISION",
                                  size: v5,
                                  tag: TAG_COLLISION,
                                  zeroBuffer: true,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    v6->size = v5;
    v6->nextNode = (cm_buildNode_t *)&v6[1];
    v6->next = model->nodeBlocks;
    model->nodeBlocks = v6;
    nextNode = v6->nextNode;
    if ( blockSize - 1 > 0 )
    {
      v8 = blockSize - 1;
      do
      {
        nextNode->parent = nextNode + 1;
        ++nextNode;
        --v8;
      }
      while ( v8 != 0 );
    }
    nextNode->parent = nullptr;
  }
  v9 = model->nodeBlocks;
  result = v9->nextNode;
  v9->nextNode = result->parent;
  result->children[1] = nullptr;
  result->planeType = -1;
  result->parent = nullptr;
  result->polygons = nullptr;
  result->children[0] = nullptr;
  result->polytopes = nullptr;
  ++model->numNodes;
  return result;
}


// ========================================================================
// ?AllocPolygonReference@idCollisionModelBuilder@@CAPAUcm_buildPolygonRef_t@@PAUcm_buildModel_t@@H@Z
// EA  : 0x825C2F48
// RVA : 0x005C2F48
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

cm_buildPolygonRef_t *__fastcall idCollisionModelBuilder::AllocPolygonReference(cm_buildModel_t *model, int blockSize)
{
  cm_buildPolygonRefBlock_t *polygonRefBlocks; // r11
  unsigned int v5; // r31
  cm_buildPolygonRefBlock_t *v6; // r3
  cm_buildPolygonRef_t *nextRef; // r11
  int v8; // ctr
  cm_buildPolygonRefBlock_t *v9; // r11
  cm_buildPolygonRef_t *result; // r3

  polygonRefBlocks = model->polygonRefBlocks;
  if ( polygonRefBlocks == nullptr || polygonRefBlocks->nextRef == nullptr )
  {
    v5 = 8 * blockSize + 12;
    v6 = (cm_buildPolygonRefBlock_t *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(684) : TAG_COLLISION",
                                        size: v5,
                                        tag: TAG_COLLISION,
                                        zeroBuffer: true,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
    v6->size = v5;
    v6->nextRef = (cm_buildPolygonRef_t *)&v6[1];
    v6->next = model->polygonRefBlocks;
    model->polygonRefBlocks = v6;
    nextRef = v6->nextRef;
    if ( blockSize - 1 > 0 )
    {
      v8 = blockSize - 1;
      do
      {
        nextRef->next = nextRef + 1;
        ++nextRef;
        --v8;
      }
      while ( v8 != 0 );
    }
    nextRef->next = nullptr;
  }
  v9 = model->polygonRefBlocks;
  result = v9->nextRef;
  v9->nextRef = result->next;
  return result;
}


// ========================================================================
// ?AllocPolytopeReference@idCollisionModelBuilder@@CAPAUcm_buildPolytopeRef_t@@PAUcm_buildModel_t@@H@Z
// EA  : 0x825C3000
// RVA : 0x005C3000
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

cm_buildPolytopeRef_t *__fastcall idCollisionModelBuilder::AllocPolytopeReference(
        cm_buildModel_t *model,
        int blockSize)
{
  cm_buildPolytopeRefBlock_t *polytopeRefBlocks; // r11
  unsigned int v5; // r31
  cm_buildPolytopeRefBlock_t *v6; // r3
  cm_buildPolytopeRef_t *nextRef; // r11
  int v8; // ctr
  cm_buildPolytopeRefBlock_t *v9; // r11
  cm_buildPolytopeRef_t *result; // r3

  polytopeRefBlocks = model->polytopeRefBlocks;
  if ( polytopeRefBlocks == nullptr || polytopeRefBlocks->nextRef == nullptr )
  {
    v5 = 8 * blockSize + 12;
    v6 = (cm_buildPolytopeRefBlock_t *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(714) : TAG_COLLISION",
                                         size: v5,
                                         tag: TAG_COLLISION,
                                         zeroBuffer: true,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
    v6->size = v5;
    v6->nextRef = (cm_buildPolytopeRef_t *)&v6[1];
    v6->next = model->polytopeRefBlocks;
    model->polytopeRefBlocks = v6;
    nextRef = v6->nextRef;
    if ( blockSize - 1 > 0 )
    {
      v8 = blockSize - 1;
      do
      {
        nextRef->next = nextRef + 1;
        ++nextRef;
        --v8;
      }
      while ( v8 != 0 );
    }
    nextRef->next = nullptr;
  }
  v9 = model->polytopeRefBlocks;
  result = v9->nextRef;
  v9->nextRef = result->next;
  return result;
}


// ========================================================================
// ?AllocPolygon@idCollisionModelBuilder@@CAPAUcm_buildPolygon_t@@PAUcm_buildModel_t@@H@Z
// EA  : 0x825C30B8
// RVA : 0x005C30B8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

cm_buildPolygon_t *__fastcall idCollisionModelBuilder::AllocPolygon(cm_buildModel_t *model, int numEdges)
{
  int maxPolygons; // r11
  int v5; // r11
  cm_buildPolygon_t *polygons; // r30
  cm_buildPolygon_t *v7; // r3
  int numPolygons; // r11
  int maxPolygonEdges; // r10
  int v10; // r7
  cm_buildPolygon_t *v11; // r28
  int *polygonEdges; // r30
  int *v13; // r3

  maxPolygons = model->maxPolygons;
  if ( model->numPolygons + 1 > maxPolygons )
  {
    v5 = maxPolygons + 1024;
    polygons = model->polygons;
    model->maxPolygons = v5;
    v7 = (cm_buildPolygon_t *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(744) : TAG_COLLISION",
                                size: 68 * v5,
                                tag: TAG_COLLISION,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    model->polygons = v7;
    if ( polygons != nullptr )
    {
      memcpy(Dst: v7, Src: polygons, Size: 68 * model->numPolygons);
      idMem::Free(this: &mem, ptr: polygons, align: ALIGN_16);
    }
  }
  numPolygons = model->numPolygons;
  maxPolygonEdges = model->maxPolygonEdges;
  v10 = numEdges + model->numPolygonEdges;
  v11 = &model->polygons[numPolygons];
  model->numPolygons = numPolygons + 1;
  if ( v10 > maxPolygonEdges )
  {
    polygonEdges = model->polygonEdges;
    model->maxPolygonEdges = maxPolygonEdges + 1024;
    v13 = (int *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(757) : TAG_COLLISION",
                   size: 4 * (maxPolygonEdges + 1024),
                   tag: TAG_COLLISION,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    model->polygonEdges = v13;
    if ( polygonEdges != nullptr )
    {
      memcpy(Dst: v13, Src: polygonEdges, Size: 4 * model->numPolygonEdges);
      idMem::Free(this: &mem, ptr: polygonEdges, align: ALIGN_16);
    }
  }
  v11->numEdges = numEdges;
  v11->firstEdge = model->numPolygonEdges;
  model->numPolygonEdges += numEdges;
  return v11;
}


// ========================================================================
// ?AllocPolytope@idCollisionModelBuilder@@CAPAUcm_buildPolytope_t@@PAUcm_buildModel_t@@H@Z
// EA  : 0x825C31F0
// RVA : 0x005C31F0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

cm_buildPolytope_t *__fastcall idCollisionModelBuilder::AllocPolytope(cm_buildModel_t *model, int numPlanes)
{
  int maxPolytopes; // r11
  cm_buildPolytope_t *polytopes; // r30
  int v6; // r10
  int v7; // r11
  cm_buildPolytope_t *v8; // r3
  int numPolytopes; // r11
  int maxPolytopePlanes; // r7
  int v11; // r8
  cm_buildPolytope_t *v12; // r28
  idPlane *polytopePlanes; // r30
  int v14; // r11
  int v15; // r10
  int v16; // r11
  idPlane *v17; // r3

  maxPolytopes = model->maxPolytopes;
  if ( model->numPolytopes + 1 > maxPolytopes )
  {
    polytopes = model->polytopes;
    v6 = model->maxPolytopes;
    if ( maxPolytopes <= 256 )
    {
      if ( maxPolytopes == 0 )
        v6 = 4;
    }
    else
    {
      v6 = 256;
    }
    v7 = maxPolytopes + v6;
    model->maxPolytopes = v7;
    v8 = (cm_buildPolytope_t *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(788) : TAG_COLLISION",
                                 size: 52 * v7,
                                 tag: TAG_COLLISION,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
    model->polytopes = v8;
    if ( polytopes != nullptr )
    {
      memcpy(Dst: v8, Src: polytopes, Size: 52 * model->numPolytopes);
      idMem::Free(this: &mem, ptr: polytopes, align: ALIGN_16);
    }
  }
  numPolytopes = model->numPolytopes;
  maxPolytopePlanes = model->maxPolytopePlanes;
  v11 = model->numPolytopePlanes + numPlanes;
  v12 = &model->polytopes[numPolytopes];
  model->numPolytopes = numPolytopes + 1;
  if ( v11 > maxPolytopePlanes )
  {
    polytopePlanes = model->polytopePlanes;
    v14 = maxPolytopePlanes;
    if ( maxPolytopePlanes <= 256 )
    {
      if ( maxPolytopePlanes == 0 )
        v14 = 8;
    }
    else
    {
      v14 = 256;
    }
    if ( v11 > maxPolytopePlanes + v14 )
    {
      do
      {
        v15 = v14;
        if ( v14 > 256 )
          v15 = 256;
        v14 += v15;
      }
      while ( model->numPolytopePlanes + numPlanes > model->maxPolytopePlanes + v14 );
    }
    v16 = maxPolytopePlanes + v14;
    model->maxPolytopePlanes = v16;
    v17 = (idPlane *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(818) : TAG_COLLISION",
                       size: 16 * v16,
                       tag: TAG_COLLISION,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
    model->polytopePlanes = v17;
    if ( polytopePlanes != nullptr )
    {
      memcpy(Dst: v17, Src: polytopePlanes, Size: 16 * model->numPolytopePlanes);
      idMem::Free(this: &mem, ptr: polytopePlanes, align: ALIGN_16);
    }
  }
  v12->numPlanes = numPlanes;
  v12->firstPlane = model->numPolytopePlanes;
  model->numPolytopePlanes += numPlanes;
  return v12;
}


// ========================================================================
// ?AddPolygonToNode@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildNode_t@@PAUcm_buildPolygon_t@@@Z
// EA  : 0x825C33A0
// RVA : 0x005C33A0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::AddPolygonToNode(
        cm_buildModel_t *model,
        cm_buildNode_t *node,
        cm_buildPolygon_t *p)
{
  int v6; // r4
  cm_buildPolygonRef_t *v7; // r3

  v6 = 8;
  if ( model->numPolygonRefs >= 8 )
    v6 = 256;
  v7 = idCollisionModelBuilder::AllocPolygonReference(model, blockSize: v6);
  v7->polygonNum = p - model->polygons;
  v7->next = node->polygons;
  node->polygons = v7;
  ++model->numPolygonRefs;
}


// ========================================================================
// ?AddPolytopeToNode@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildNode_t@@PAUcm_buildPolytope_t@@@Z
// EA  : 0x825C3408
// RVA : 0x005C3408
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::AddPolytopeToNode(
        cm_buildModel_t *model,
        cm_buildNode_t *node,
        cm_buildPolytope_t *b)
{
  int v6; // r4
  cm_buildPolytopeRef_t *v7; // r3

  v6 = 8;
  if ( model->numPolytopeRefs >= 8 )
    v6 = 256;
  v7 = idCollisionModelBuilder::AllocPolytopeReference(model, blockSize: v6);
  v7->polytopeNum = b - model->polytopes;
  v7->next = node->polytopes;
  node->polytopes = v7;
  ++model->numPolytopeRefs;
}


// ========================================================================
// ?GetPrimitiveCounts@idCollisionModelBuilder@@CAXPBUcm_buildNode_t@@AAH1@Z
// EA  : 0x825C3470
// RVA : 0x005C3470
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::GetPrimitiveCounts(
        const cm_buildNode_t *node,
        int *polygonCount,
        int *polytopeCount)
{
  cm_buildPolygonRef_t *i; // r11
  cm_buildPolytopeRef_t *j; // r11

  *polygonCount = 0;
  for ( i = node->polygons; i != nullptr; i = i->next )
    ++*polygonCount;
  *polytopeCount = 0;
  for ( j = node->polytopes; j != nullptr; j = j->next )
    ++*polytopeCount;
}


// ========================================================================
// ?GetNodeContents@idCollisionModelBuilder@@CAHPBUcm_buildModel_t@@PBUcm_buildNode_t@@@Z
// EA  : 0x825C34C8
// RVA : 0x005C34C8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::GetNodeContents(const cm_buildModel_t *model, const cm_buildNode_t *node)
{
  int i; // r31
  cm_buildPolygonRef_t *j; // r11
  int polygonNum; // r10
  cm_buildPolytopeRef_t *k; // r11
  int polytopeNum; // r10
  int NodeContents; // r3

  for ( i = 0; ; i |= NodeContents )
  {
    for ( j = node->polygons; j != nullptr; i |= model->polygons[polygonNum].contents )
    {
      polygonNum = j->polygonNum;
      j = j->next;
    }
    for ( k = node->polytopes; k != nullptr; i |= model->polytopes[polytopeNum].contents )
    {
      polytopeNum = k->polytopeNum;
      k = k->next;
    }
    if ( node->planeType == -1 )
      break;
    NodeContents = idCollisionModelBuilder::GetNodeContents(model, node: node->children[1]);
    node = node->children[0];
  }
  return i;
}


// ========================================================================
// ?SetupSubModelData@idCollisionModelBuilder@@CAHAAUcm_subModelData_t@@AAUcm_buildNodeStats_t@@@Z
// EA  : 0x825C3570
// RVA : 0x005C3570
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::SetupSubModelData(cm_subModelData_t *data, cm_buildNodeStats_t *stats)
{
  int numNodes; // r5
  int numPrimitiveIndices; // r10
  int numMaterials; // r8
  int v5; // r11
  int v6; // r9
  int numPolygons; // r5
  int v8; // r10
  int v9; // r6
  int v10; // r11
  int numPolygonEdges; // r5
  int numPolytopePlanes; // r4
  int numVertices; // r10
  int numPolytopes; // r30
  int numEdges; // r31
  int v16; // r11
  int v17; // r11
  int v18; // r11
  int v19; // r11
  int v20; // r11
  int v21; // r11
  int v22; // r11

  data->isConvex = 0;
  numNodes = stats->numNodes;
  data->numNodes = stats->numNodes;
  numPrimitiveIndices = stats->numPrimitiveIndices;
  data->numPrimitiveIndices = numPrimitiveIndices;
  numMaterials = stats->numMaterials;
  v5 = 16 * numNodes + 113;
  data->numMaterials = numMaterials;
  v6 = 2 * numPrimitiveIndices;
  numPolygons = stats->numPolygons;
  data->numPolygons = numPolygons;
  data->numPolygonEdges = stats->numPolygonEdges;
  v8 = v5 - v5 % 2;
  data->numEdges = stats->numEdges;
  v9 = 16 * numPolygons;
  data->numVertices = stats->numVertices;
  v10 = v6 + v8 + 15;
  numPolygonEdges = data->numPolygonEdges;
  data->numPolytopes = stats->numPolytopes;
  numPolytopePlanes = stats->numPolytopePlanes;
  data->primitiveIndexOffset = v8;
  numVertices = data->numVertices;
  data->nodeOffset = 112;
  numPolytopes = data->numPolytopes;
  numEdges = data->numEdges;
  v16 = v10 - v10 % 16;
  data->numPolytopePlanes = numPolytopePlanes;
  data->materialOffset = v16;
  v17 = 16 * numMaterials + v16 + 15 - (16 * numMaterials + v16 + 15) % 16;
  data->polygonOffset = v17;
  v18 = v9 + v17 + 1 - (v9 + v17 + 1) % 2;
  data->polygonEdgeOffset = v18;
  v19 = 2 * numPolygonEdges + v18 + 3 - (2 * numPolygonEdges + v18 + 3) % 4;
  data->edgeOffset = v19;
  v20 = 4 * numEdges + v19 + 15 - (4 * numEdges + v19 + 15) % 16;
  data->vertexOffset = v20;
  v21 = 16 * numVertices + v20 + 15 - (16 * numVertices + v20 + 15) % 16;
  data->polytopeOffset = v21;
  v22 = 16 * numPolytopes + v21 + 15 - (16 * numPolytopes + v21 + 15) % 16;
  data->polytopePlaneOffset = v22;
  return 16 * numPolytopePlanes + v22;
}


// ========================================================================
// ?FindSubModels_r@idCollisionModelBuilder@@CAXPBUcm_buildModel_t@@PAUcm_buildNode_t@@AAH2@Z
// EA  : 0x825C3720
// RVA : 0x005C3720
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::FindSubModels_r(
        const cm_buildModel_t *buildModel,
        cm_buildNode_t *buildNode,
        int *numModelTreeNodes,
        int *numSubModels)
{
  cm_buildNode_t *v5; // r31

  v5 = buildNode;
  if ( buildNode->stats.canCreateSubModel )
  {
LABEL_4:
    ++*numSubModels;
  }
  else
  {
    while ( 1 )
    {
      ++*numModelTreeNodes;
      if ( v5->planeType == -1 )
        break;
      idCollisionModelBuilder::FindSubModels_r(buildModel, buildNode: v5->children[0], numModelTreeNodes, numSubModels);
      v5 = v5->children[1];
      if ( v5->stats.canCreateSubModel )
        goto LABEL_4;
    }
  }
}


// ========================================================================
// CM_R_InsideAllChildren
// EA  : 0x825C3AC0
// RVA : 0x005C3AC0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall CM_R_InsideAllChildren(cm_buildNode_t *node, const idBounds *bounds)
{
  int planeType; // r11
  double planeDist; // fp0
  int result; // r3
  bool v7; // zf

  planeType = node->planeType;
  if ( node->planeType == -1 )
    return 1;
  planeDist = node->planeDist;
  if ( *(&bounds->b[0].x + planeType) >= planeDist
    || *(&bounds->b[1].x + planeType) <= planeDist
    || CM_R_InsideAllChildren(node: node->children[0], bounds) == 0 )
  {
    return 0;
  }
  v7 = CM_R_InsideAllChildren(node: node->children[1], bounds) == 0;
  result = 0;
  if ( !v7 )
    return 1;
  return result;
}


// ========================================================================
// ?ParseProcNodes@idCollisionModelBuilder@@CAXPAVidLexer@@@Z
// EA  : 0x825C3B60
// RVA : 0x005C3B60
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::ParseProcNodes(idLexer *src)
{
  int numProcNodes; // r3
  cm_procNode_t *procNodes; // r3
  int v4; // r29
  int v5; // r27
  cm_procNode_t *v6; // r31

  idLexer::ExpectTokenString(this: src, string: "{");
  numProcNodes = idLexer::ParseInt(this: src);
  buildData.numProcNodes = numProcNodes;
  if ( numProcNodes < 0 )
  {
    idLexer::Error(this: src, str: "ParseProcNodes: bad numProcNodes");
    numProcNodes = buildData.numProcNodes;
  }
  procNodes = (cm_procNode_t *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(297) : TAG_COLLISION",
                                 size: 24 * numProcNodes,
                                 tag: TAG_COLLISION,
                                 zeroBuffer: true,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  v4 = 0;
  buildData.procNodes = procNodes;
  if ( buildData.numProcNodes > 0 )
  {
    v5 = 0;
    while ( 1 )
    {
      v6 = &procNodes[v5];
      idLexer::Parse1DMatrix(this: src, x: 4, m: &procNodes[v5].plane.a, expectCommas: false);
      v6->children[0] = idLexer::ParseInt(this: src);
      ++v4;
      v6->children[1] = idLexer::ParseInt(this: src);
      ++v5;
      if ( v4 >= buildData.numProcNodes )
        break;
      procNodes = buildData.procNodes;
    }
  }
  idLexer::ExpectTokenString(this: src, string: "}");
}


// ========================================================================
// ?FreeModelMemory@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@@Z
// EA  : 0x825C3C58
// RVA : 0x005C3C58
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::FreeModelMemory(cm_buildModel_t *model)
{
  cm_buildPolygonRefBlock_t *i; // r4
  cm_buildPolytopeRefBlock_t *j; // r4
  cm_buildNodeBlock_t *k; // r4

  for ( i = model->polygonRefBlocks; i != nullptr; i = model->polygonRefBlocks )
  {
    model->polygonRefBlocks = i->next;
    idMem::Free(this: &mem, ptr: i, align: ALIGN_16);
  }
  for ( j = model->polytopeRefBlocks; j != nullptr; j = model->polytopeRefBlocks )
  {
    model->polytopeRefBlocks = j->next;
    idMem::Free(this: &mem, ptr: j, align: ALIGN_16);
  }
  for ( k = model->nodeBlocks; k != nullptr; k = model->nodeBlocks )
  {
    model->nodeBlocks = k->next;
    idMem::Free(this: &mem, ptr: k, align: ALIGN_16);
  }
  idMem::Free(this: &mem, ptr: model->polygonEdges, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: model->polygons, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: model->polytopePlanes, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: model->polytopes, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: model->edges, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: model->vertices, align: ALIGN_16);
  model->isWorldModel = false;
  model->checkCount = 0;
  model->maxVertices = 0;
  model->numVertices = 0;
  model->vertices = nullptr;
  model->maxEdges = 0;
  model->numEdges = 0;
  model->edges = nullptr;
  model->maxPolygonEdges = 0;
  model->numPolygonEdges = 0;
  model->polygonEdges = nullptr;
  model->maxPolygons = 0;
  model->numPolygons = 0;
  model->polygons = nullptr;
  model->maxPolytopePlanes = 0;
  model->numPolytopePlanes = 0;
  model->polytopePlanes = nullptr;
  model->maxPolytopes = 0;
  model->numPolytopes = 0;
  model->polytopes = nullptr;
  model->numNodes = 0;
  model->node = nullptr;
  model->nodeBlocks = nullptr;
  model->polygonRefBlocks = nullptr;
  model->polytopeRefBlocks = nullptr;
  model->numMergedPolys = 0;
  model->numRemovedPolys = 0;
  model->numSharpEdges = 0;
  model->numInternalEdges = 0;
  model->numPolygonRefs = 0;
  model->numPolytopeRefs = 0;
}


// ========================================================================
// ?GenerateEdgeNormals_r@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildNode_t@@@Z
// EA  : 0x825C3DF8
// RVA : 0x005C3DF8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::GenerateEdgeNormals_r(cm_buildModel_t *model, cm_buildNode_t *node)
{
  cm_buildPolygonRef_t *i; // r3
  int checkCount; // r11
  cm_buildPolygon_t *v6; // r10
  int numEdges; // r9
  int v8; // r4
  unsigned int v9; // r9
  cm_buildEdge_t *v10; // r8
  float *p_x; // r11
  cm_buildVertex_t *v12; // r7
  double v13; // fp12
  unsigned int v14; // r6
  double v15; // fp0
  float *v16; // r9
  float *v17; // r8
  double v18; // fp3
  double v19; // fp5
  double v20; // fp2
  double v21; // fp1
  double v22; // fp8
  double v23; // fp10
  double v24; // fp9
  double v27; // fp11
  double v28; // fp1
  double v29; // fp12
  double v30; // fp11
  double v31; // fp4
  double v32; // fp2
  double v33; // fp0
  double v34; // fp13
  double v36; // fp7
  double v38; // fp4
  double v39; // fp8
  double v40; // fp7
  double y; // fp10
  double b; // fp0
  double a; // fp12
  double z; // fp9
  double c; // fp11
  cm_buildVertex_t *vertices; // r7
  unsigned int v47; // r28
  float *v48; // r9
  float *v49; // r8
  double v50; // fp1
  double v51; // fp7
  double v52; // fp5
  double v53; // fp9
  double v54; // fp8
  double v55; // fp2
  double v56; // fp0
  double v57; // fp13
  double v58; // fp12
  double v59; // fp2
  double v60; // fp8

  while ( 1 )
  {
    for ( i = node->polygons; i != nullptr; i = i->next )
    {
      checkCount = model->checkCount;
      v6 = &model->polygons[i->polygonNum];
      if ( v6->checkCount != checkCount )
      {
        numEdges = v6->numEdges;
        v8 = 0;
        v6->checkCount = checkCount;
        if ( numEdges > 0 )
        {
          do
          {
            v9 = model->polygonEdges[v6->firstEdge + v8];
            v10 = &model->edges[abs32(v9)];
            p_x = &v10->normal.x;
            if ( ((LODWORD(v10->normal.x) | LODWORD(v10->normal.y) | LODWORD(v10->normal.z)) & 0x7FFFFFFF) != 0 )
            {
              y = v10->normal.y;
              b = v6->plane.b;
              a = v6->plane.a;
              z = v10->normal.z;
              c = v6->plane.c;
              if ( (float)((float)(v6->plane.c * v10->normal.z)
                         + (float)((float)(v6->plane.a * v10->normal.x) + (float)(v6->plane.b * v10->normal.y))) >= -0.69999999 )
              {
                v60 = (float)((float)((float)(v6->plane.c * v10->normal.z)
                                    + (float)((float)(v6->plane.a * v10->normal.x) + (float)(v6->plane.b * v10->normal.y)))
                            + (float)1.0);
                *p_x = (float)(v6->plane.a + *p_x)
                     * (float)((float)1.0
                             / (float)((float)((float)(v6->plane.c * p_x[2])
                                             + (float)((float)(v6->plane.a * *p_x) + (float)(v6->plane.b * p_x[1])))
                                     + (float)1.0));
                v10->normal.y = (float)((float)b + (float)y) * (float)((float)1.0 / (float)v60);
                v10->normal.z = (float)((float)c + (float)z) * (float)((float)1.0 / (float)v60);
              }
              else
              {
                vertices = model->vertices;
                v47 = ((-v9 & ~v9) >> 29) & 4;
                v48 = &vertices[*(int *)((char *)v10->vertexNum + ((v9 >> 29) & 4))].p.x;
                v49 = &vertices[*(int *)((char *)v10->vertexNum + v47)].p.x;
                v50 = (float)(v49[1] - v48[1]);
                v51 = -(float)(*v49 - *v48);
                v52 = -(float)(v49[2] - v48[2]);
                v54 = (float)((float)((float)(v49[2] - v48[2]) * p_x[1]) - (float)(p_x[2] * (float)(v49[1] - v48[1])));
                v53 = (float)((float)(p_x[2] * (float)(*v49 - *v48)) - (float)((float)(v49[2] - v48[2]) * *p_x));
                v55 = (float)((float)(v6->plane.b * (float)v52) - (float)(v6->plane.c * (float)-v50));
                v56 = (float)((float)((float)((float)(v49[1] - v48[1]) * *p_x) - (float)(p_x[1] * (float)(*v49 - *v48)))
                            + (float)((float)(v6->plane.a * (float)-v50) - (float)(v6->plane.b * (float)v51)));
                p_x[2] = (float)((float)((float)(v49[1] - v48[1]) * *p_x) - (float)(p_x[1] * (float)(*v49 - *v48)))
                       + (float)((float)(v6->plane.a * (float)-v50) - (float)(v6->plane.b * (float)v51));
                v57 = (float)((float)v54 + (float)v55);
                *p_x = (float)v54 + (float)v55;
                p_x[1] = (float)v53 + (float)((float)((float)c * (float)v51) - (float)((float)a * (float)v52));
                v58 = (float)((float)v53 + (float)((float)((float)c * (float)v51) - (float)((float)a * (float)v52)));
                v59 = __fsqrts((float)((float)((float)((float)v54 + (float)v55) * (float)((float)v54 + (float)v55))
                                     + (float)((float)((float)v58 * (float)v58) + (float)((float)v56 * (float)v56))));
                *p_x = (float)v57 * (float)((float)3.3333333 / (float)v59);
                p_x[1] = (float)v58 * (float)((float)3.3333333 / (float)v59);
                p_x[2] = (float)((float)3.3333333 / (float)v59) * (float)v56;
                ++model->numSharpEdges;
              }
            }
            else if ( v10->numUsers == 1 )
            {
              v12 = model->vertices;
              v13 = v6->plane.a;
              v14 = (~v9 >> 29) & 4;
              v15 = v6->plane.b;
              v16 = &v12[*(int *)((char *)v10->vertexNum + ((v9 >> 29) & 4))].p.x;
              v17 = &v12[*(int *)((char *)v10->vertexNum + v14)].p.x;
              v18 = (float)(v16[2] - v17[2]);
              v19 = (float)(v16[1] - v17[1]);
              v20 = (float)(v6->plane.b * (float)(*v16 - *v17));
              v21 = (float)(v6->plane.c * (float)(v16[1] - v17[1]));
              v22 = (float)((float)(v6->plane.c * (float)(*v16 - *v17)) - (float)(v6->plane.a * (float)(v16[2] - v17[2])));
              p_x[1] = (float)(v6->plane.c * (float)(*v16 - *v17)) - (float)(v6->plane.a * (float)(v16[2] - v17[2]));
              v23 = (float)((float)((float)v13 * (float)v19) - (float)v20);
              p_x[2] = (float)((float)v13 * (float)v19) - (float)v20;
              v24 = (float)((float)((float)v15 * (float)v18) - (float)v21);
              *p_x = (float)((float)v15 * (float)v18) - (float)v21;
              _FP1 = (float)((float)((float)((float)v23 * (float)v23)
                                   + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22)))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f12, f1, f2, f0 }
              v27 = __frsqrte(_FP12);
              v28 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27
                                                                                                  * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22))) * (float)0.5))
                                                                                          * (float)v27)
                                                                                  - (float)1.5)
                                                                  * (float)v27)
                                                          * (float)((float)((float)((float)v23 * (float)v23)
                                                                          + (float)((float)((float)v24 * (float)v24)
                                                                                  + (float)((float)v22 * (float)v22)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v27
                                                                                          * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v27)
                                                                          - (float)1.5)
                                                          * (float)v27))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v27
                                                                  * (float)((float)((float)((float)v23 * (float)v23)
                                                                                  + (float)((float)((float)v24
                                                                                                  * (float)v24)
                                                                                          + (float)((float)v22
                                                                                                  * (float)v22)))
                                                                          * (float)0.5))
                                                          * (float)v27)
                                                  - (float)1.5)
                                  * (float)v27));
              v29 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22))) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27)
                                                                                                  * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22))) * (float)0.5)) * (float)v27) - (float)1.5)
                                                                                                  * (float)v27))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22))) * (float)0.5))
                                                                                                  * (float)v27)
                                                                                          - (float)1.5)
                                                                          * (float)v27))
                                                          * (float)((float)((float)((float)v23 * (float)v23)
                                                                          + (float)((float)((float)v24 * (float)v24)
                                                                                  + (float)((float)v22 * (float)v22)))
                                                                  * (float)0.5))
                                                  * (float)v28)
                                          - (float)1.5)
                          * (float)v28);
              v30 = (float)((float)v24
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22))) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27) * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22))) * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22))) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22))) * (float)0.5)) * (float)v27)
                                                                                                  - (float)1.5)
                                                                                  * (float)v27))
                                                                  * (float)((float)((float)((float)v23 * (float)v23)
                                                                                  + (float)((float)((float)v24
                                                                                                  * (float)v24)
                                                                                          + (float)((float)v22
                                                                                                  * (float)v22)))
                                                                          * (float)0.5))
                                                          * (float)v28)
                                                  - (float)1.5)
                                  * (float)v28));
              *p_x = v30;
              p_x[1] = (float)v22 * (float)v29;
              p_x[2] = (float)v23 * (float)v29;
              v31 = (float)((float)v30 + v6->plane.a);
              *p_x = (float)v30 + v6->plane.a;
              v32 = (float)((float)((float)v22 * (float)v29) + v6->plane.b);
              p_x[1] = (float)((float)v22 * (float)v29) + v6->plane.b;
              v33 = (float)(v6->plane.c + (float)((float)v23 * (float)v29));
              p_x[2] = v6->plane.c + (float)((float)v23 * (float)v29);
              v34 = v31;
              _FP6 = (float)((float)((float)((float)v33 * (float)v33)
                                   + (float)((float)((float)v31 * (float)v31) + (float)((float)v32 * (float)v32)))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              v36 = (float)((float)((float)((float)v33 * (float)v33)
                                  + (float)((float)((float)v31 * (float)v31) + (float)((float)v32 * (float)v32)))
                          * (float)0.5);
              __asm { fsel      f5, f6, f8, f0 }
              v38 = __frsqrte(_FP5);
              v39 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38
                                                                                                  * (float)v36)
                                                                                          * (float)v38)
                                                                                  - (float)1.5)
                                                                  * (float)v38)
                                                          * (float)v36)
                                                  * (float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                  * (float)v38)
                                                                          - (float)1.5)
                                                          * (float)v38))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38) - (float)1.5)
                                  * (float)v38));
              v40 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)v36)
                                                                                                  * (float)v38)
                                                                                          - (float)1.5)
                                                                          * (float)v38)
                                                                  * (float)v36)
                                                          * (float)((float)-(float)((float)((float)((float)v38
                                                                                                  * (float)v36)
                                                                                          * (float)v38)
                                                                                  - (float)1.5)
                                                                  * (float)v38))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)v38 * (float)v36) * (float)v38)
                                                          - (float)1.5)
                                          * (float)v38))
                          * (float)v36);
              *p_x = (float)v34 * (float)((float)-(float)((float)((float)v40 * (float)v39) - (float)1.5) * (float)v39);
              p_x[1] = (float)v32 * (float)((float)-(float)((float)((float)v40 * (float)v39) - (float)1.5) * (float)v39);
              p_x[2] = (float)v33 * (float)((float)-(float)((float)((float)v40 * (float)v39) - (float)1.5) * (float)v39);
            }
            else
            {
              *p_x = v6->plane.a;
              v10->normal.y = v6->plane.b;
              v10->normal.z = v6->plane.c;
            }
            ++v8;
          }
          while ( v8 < v6->numEdges );
        }
      }
    }
    if ( node->planeType == -1 )
      break;
    idCollisionModelBuilder::GenerateEdgeNormals_r(model, node: node->children[1]);
    node = node->children[0];
  }
}


// ========================================================================
// ?ChoppedAwayByProcBSP_r@idCollisionModelBuilder@@CAHHPAVidFixedWinding@@ABVidVec3@@1M@Z
// EA  : 0x825C4248
// RVA : 0x005C4248
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::ChoppedAwayByProcBSP_r(
        int nodeNum,
        idFixedWinding *w,
        idFixedWinding *normal,
        const idVec3 *origin,
        double radius)
{
  cm_procNode_t *v9; // r30
  double v10; // fp0
  int v11; // r3
  int v12; // r3
  idFixedWinding v14; // [sp+50h] [-570h] BYREF

  v14.numPoints = 0;
  v14.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
  v14.p = v14.data;
  v14.allocedSize = 64;
  while ( 1 )
  {
    v9 = &buildData.procNodes[nodeNum];
    v10 = (float)((float)((float)(origin->z * v9->plane.c)
                        + (float)((float)(v9->plane.a * origin->x) + (float)(origin->y * v9->plane.b)))
                + v9->plane.d);
    if ( v10 > radius )
      goto LABEL_14;
    if ( v10 < -radius )
      goto LABEL_6;
    v11 = idFixedWinding::SplitInPlace(this: w, plane: &buildData.procNodes[nodeNum].plane, epsilon: 0.1, back: normal);
    if ( v11 == 0 )
      goto LABEL_14;
    if ( v11 == 1 )
    {
LABEL_6:
      nodeNum = v9->children[1];
      goto LABEL_15;
    }
    if ( v11 != 2 )
      break;
    if ( (float)((float)(v9->plane.a * *(float *)&normal->__vftable)
               + (float)((float)(*(float *)&normal->p * v9->plane.c)
                       + (float)(*(float *)&normal->numPoints * v9->plane.b))) > 0.0 )
      goto LABEL_14;
    nodeNum = v9->children[1];
LABEL_15:
    if ( nodeNum <= 0 )
    {
      if ( nodeNum >= 0 )
      {
        idFixedWinding::~idFixedWinding(this: &v14);
        return 1;
      }
_M235081:
      idFixedWinding::~idFixedWinding(this: &v14);
      return 0;
    }
  }
  if ( v9->children[0] >= 0 )
  {
    v12 = v9->children[1];
    if ( v12 >= 0 )
    {
      if ( v12 > 0
        && idCollisionModelBuilder::ChoppedAwayByProcBSP_r(
             nodeNum: v12,
             w: &v14,
             (const idVec3 *)normal,
             origin,
             radius) == 0 )
      {
        goto _M235081;
      }
LABEL_14:
      nodeNum = v9->children[0];
      goto LABEL_15;
    }
  }
  v14.p = nullptr;
  v14.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
  idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
  return 0;
}


// ========================================================================
// __unwind$235004
// EA  : 0x825C441C
// RVA : 0x005C441C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_235004()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 1472 + 80));
}


// ========================================================================
// ?ReplacePolygons@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildNode_t@@HHH@Z
// EA  : 0x825C4448
// RVA : 0x005C4448
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::ReplacePolygons(
        cm_buildModel_t *model,
        cm_buildNode_t *node,
        int polygonNum1,
        int polygonNum2,
        int newPolygonNum)
{
  cm_buildPolygonRef_t *polygons; // r11
  char v11; // r7
  cm_buildPolygonRef_t *v12; // r9
  cm_buildPolygonRef_t *next; // r8
  int planeType; // r7
  cm_buildPolygon_t *v15; // r11
  double planeDist; // fp0
  cm_buildPolygon_t *v17; // r9
  int v18; // r10
  cm_buildPolygon_t *v19; // r11
  int v20; // r10

  while ( 1 )
  {
    polygons = node->polygons;
    v11 = 0;
    v12 = nullptr;
    if ( polygons != nullptr )
    {
      do
      {
        next = polygons->next;
        if ( polygons->polygonNum == polygonNum1 || polygons->polygonNum == polygonNum2 )
        {
          if ( v11 != 0 )
          {
            if ( v12 != nullptr )
              v12->next = next;
            else
              node->polygons = next;
            --model->numPolygonRefs;
            goto LABEL_11;
          }
          polygons->polygonNum = newPolygonNum;
          v11 = 1;
        }
        v12 = polygons;
LABEL_11:
        polygons = next;
      }
      while ( next != nullptr );
    }
    planeType = node->planeType;
    if ( node->planeType == -1 )
      break;
    v15 = model->polygons;
    planeDist = node->planeDist;
    v17 = &v15[polygonNum1];
    v18 = 4 * (planeType + 4);
    v19 = &v15[polygonNum2];
    if ( *(float *)((char *)&v17->plane.a + v18) <= planeDist || *(float *)((char *)&v19->plane.a + v18) <= planeDist )
    {
      v20 = 4 * (planeType + 7);
      if ( *(float *)((char *)&v17->plane.a + v20) >= planeDist || *(float *)((char *)&v19->plane.a + v20) >= planeDist )
      {
        idCollisionModelBuilder::ReplacePolygons(
          model,
          node: node->children[1],
          polygonNum1,
          polygonNum2,
          newPolygonNum);
        node = node->children[0];
      }
      else
      {
        node = node->children[1];
      }
    }
    else
    {
      node = node->children[0];
    }
  }
}


// ========================================================================
// ?RemovePolygon@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildNode_t@@H@Z
// EA  : 0x825C4588
// RVA : 0x005C4588
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::RemovePolygon(cm_buildModel_t *model, cm_buildNode_t *node, int polygonNum)
{
  cm_buildPolygonRef_t *polygons; // r11
  cm_buildPolygonRef_t *v7; // r9
  cm_buildPolygonRef_t *next; // r10
  int planeType; // r9
  double planeDist; // fp0
  cm_buildPolygon_t *v11; // r11

  while ( 1 )
  {
    polygons = node->polygons;
    v7 = nullptr;
    if ( polygons != nullptr )
    {
      do
      {
        next = polygons->next;
        if ( polygons->polygonNum == polygonNum )
        {
          if ( v7 != nullptr )
            v7->next = next;
          else
            node->polygons = next;
          --model->numPolygonRefs;
        }
        else
        {
          v7 = polygons;
        }
        polygons = next;
      }
      while ( next != nullptr );
    }
    planeType = node->planeType;
    if ( node->planeType == -1 )
      break;
    planeDist = node->planeDist;
    v11 = &model->polygons[polygonNum];
    if ( *(&v11->bounds.b[0].x + planeType) <= planeDist )
    {
      if ( *(&v11->bounds.b[1].x + planeType) >= planeDist )
      {
        idCollisionModelBuilder::RemovePolygon(model, node: node->children[1], polygonNum);
        node = node->children[0];
      }
      else
      {
        node = node->children[1];
      }
    }
    else
    {
      node = node->children[0];
    }
  }
}


// ========================================================================
// ?PointInsidePolygon@idCollisionModelBuilder@@CA_NPAUcm_buildModel_t@@PAUcm_buildPolygon_t@@AAVidVec3@@@Z
// EA  : 0x825C4678
// RVA : 0x005C4678
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::PointInsidePolygon(cm_buildModel_t *model, cm_buildPolygon_t *p, idVec3 *v)
{
  int numEdges; // r28
  int v4; // r6
  cm_buildVertex_t *vertices; // r9
  double c; // fp0
  double b; // fp13
  double a; // fp12
  unsigned int v9; // r8
  cm_buildEdge_t *v10; // r11
  float *v11; // r11
  float *p_x; // r10

  numEdges = p->numEdges;
  v4 = 0;
  if ( numEdges <= 0 )
    return 1;
  vertices = model->vertices;
  while ( 1 )
  {
    v9 = model->polygonEdges[p->firstEdge + v4];
    v10 = &model->edges[abs32(v9)];
    p_x = &vertices[*(int *)((char *)v10->vertexNum + ((~v9 >> 29) & 4))].p.x;
    v11 = &vertices[*(int *)((char *)v10->vertexNum + ((v9 >> 29) & 4))].p.x;
    b = p->plane.b;
    a = p->plane.a;
    c = p->plane.c;
    if ( (float)((float)((float)((float)((float)a * (float)(p_x[2] - v11[2])) - (float)((float)c * (float)(*p_x - *v11)))
                       * (float)(v->y - v11[1]))
               + (float)((float)((float)((float)((float)c * (float)(p_x[1] - v11[1]))
                                       - (float)((float)b * (float)(p_x[2] - v11[2])))
                               * (float)(v->x - *v11))
                       + (float)((float)((float)((float)b * (float)(*p_x - *v11))
                                       - (float)((float)a * (float)(p_x[1] - v11[1])))
                               * (float)(v->z - v11[2])))) > 0.1 )
      break;
    if ( ++v4 >= numEdges )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?FindInternalEdgesOnPolygon@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildPolygon_t@@1@Z
// EA  : 0x825C47A8
// RVA : 0x005C47A8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::FindInternalEdgesOnPolygon(
        cm_buildModel_t *model,
        cm_buildPolygon_t *p1,
        cm_buildPolygon_t *p2)
{
  idBounds *p_bounds; // r24
  int v7; // r9
  idBounds *v8; // r10
  idVec3 *v9; // r11
  int i; // r23
  int *polygonEdges; // r28
  unsigned int v12; // r4
  unsigned int v13; // r27
  cm_buildEdge_t *v14; // r30
  cm_buildVertex_t *vertices; // r9
  int v16; // r3
  float *v17; // r8
  idVec3 *p_p; // r5
  idVec3 *v19; // r31
  float *p_x; // r11
  double v21; // fp0
  double v22; // fp13
  double v23; // fp12
  double v24; // fp0
  int numEdges; // r9
  int j; // r11

  p_bounds = &p2->bounds;
  v7 = 0;
  v8 = &p2->bounds;
  v9 = &p1->bounds.b[1];
  while ( v9[-1].x <= (double)*(float *)((char *)&v9->x + (char *)p2 - (char *)p1) && v9->x >= (double)v8->b[0].x )
  {
    ++v7;
    v9 = (idVec3 *)((char *)v9 + 4);
    v8 = (idBounds *)((char *)v8 + 4);
    if ( v7 >= 3 )
    {
      for ( i = 0; i < p1->numEdges; ++i )
      {
        polygonEdges = model->polygonEdges;
        v12 = polygonEdges[p1->firstEdge + i];
        v13 = abs32(v12);
        v14 = &model->edges[v13];
        if ( v14->internal == 0 )
        {
          vertices = model->vertices;
          v16 = 0;
          v17 = (float *)p_bounds;
          p_p = &vertices[*(int *)((char *)v14->vertexNum + ((v12 >> 29) & 4))].p;
          v19 = &vertices[*(int *)((char *)v14->vertexNum + ((~v12 >> 29) & 4))].p;
          p_x = &v19->x;
          while ( 1 )
          {
            v21 = (float)(v17[3] + (float)0.1);
            v22 = *(float *)((char *)p_x + (char *)p_p - (char *)v19);
            if ( v22 > v21 )
              break;
            v23 = *p_x;
            if ( v23 > v21 )
              break;
            v24 = (float)(*v17 - (float)0.1);
            if ( v22 < v24 || v23 < v24 )
              break;
            ++v16;
            ++v17;
            ++p_x;
            if ( v16 >= 3 )
            {
              numEdges = p2->numEdges;
              for ( j = 0; j < numEdges; ++j )
              {
                if ( v13 == abs32(polygonEdges[p2->firstEdge + j]) )
                  break;
              }
              if ( j >= numEdges )
              {
                if ( __fabs((float)((float)((float)(p2->plane.a * p_p->x)
                                          + (float)((float)(p_p->y * p2->plane.b) + (float)(p_p->z * p2->plane.c)))
                                  + p2->plane.d)) > 0.1
                  || __fabs((float)((float)((float)(p2->plane.a * v19->x)
                                          + (float)((float)(v19->y * p2->plane.b) + (float)(v19->z * p2->plane.c)))
                                  + p2->plane.d)) > 0.1 )
                {
                  break;
                }
              }
              else if ( v14->numUsers > 2u || v12 == polygonEdges[p2->firstEdge + j] )
              {
                break;
              }
              if ( (float)((float)(p2->plane.a
                                 * (float)((float)(p1->plane.b * (float)(v19->z - p_p->z))
                                         - (float)(p1->plane.c * (float)(v19->y - p_p->y))))
                         + (float)((float)(p2->plane.c
                                         * (float)((float)(p1->plane.a * (float)(v19->y - p_p->y))
                                                 - (float)(p1->plane.b * (float)(v19->x - p_p->x))))
                                 + (float)(p2->plane.b
                                         * (float)((float)(p1->plane.c * (float)(v19->x - p_p->x))
                                                 - (float)(p1->plane.a * (float)(v19->z - p_p->z)))))) < 0.0 )
                return;
              if ( j < numEdges
                || (unsigned __int8)idCollisionModelBuilder::PointInsidePolygon(model, p: p2, v: p_p) != 0
                && (unsigned __int8)idCollisionModelBuilder::PointInsidePolygon(model, p: p2, v: v19) != 0 )
              {
                v14->internal = 1;
                ++model->numInternalEdges;
              }
              break;
            }
          }
        }
      }
      return;
    }
  }
}


// ========================================================================
// ?FindInternalPolygonEdges@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildNode_t@@PAUcm_buildPolygon_t@@@Z
// EA  : 0x825C4AB0
// RVA : 0x005C4AB0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::FindInternalPolygonEdges(
        cm_buildModel_t *model,
        cm_buildNode_t *node,
        cm_buildPolygon_t *polygon)
{
  cm_buildPolygonRef_t *i; // r30
  cm_buildPolygon_t *v7; // r5
  int planeType; // r11
  double planeDist; // fp0

  while ( 1 )
  {
    for ( i = node->polygons; i != nullptr; i = i->next )
    {
      v7 = &model->polygons[i->polygonNum];
      if ( v7->material == polygon->material && v7->contents == polygon->contents && v7 != polygon )
        idCollisionModelBuilder::FindInternalEdgesOnPolygon(model, p1: polygon, p2: v7);
    }
    planeType = node->planeType;
    if ( node->planeType == -1 )
      break;
    planeDist = node->planeDist;
    if ( *(&polygon->bounds.b[0].x + planeType) <= planeDist )
    {
      if ( *(&polygon->bounds.b[1].x + planeType) >= planeDist )
      {
        idCollisionModelBuilder::FindInternalPolygonEdges(model, node: node->children[1], polygon);
        node = node->children[0];
      }
      else
      {
        node = node->children[1];
      }
    }
    else
    {
      node = node->children[0];
    }
  }
}


// ========================================================================
// ?FindInternalEdges@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildNode_t@@@Z
// EA  : 0x825C4B90
// RVA : 0x005C4B90
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::FindInternalEdges(cm_buildModel_t *model, cm_buildNode_t *node)
{
  cm_buildPolygonRef_t *i; // r27
  int checkCount; // r11
  cm_buildPolygon_t *v6; // r31
  cm_buildNode_t *v7; // r28
  cm_buildPolygonRef_t *j; // r30
  cm_buildPolygon_t *v9; // r5
  int planeType; // r11
  double planeDist; // fp0

  while ( 1 )
  {
    for ( i = node->polygons; i != nullptr; i = i->next )
    {
      checkCount = model->checkCount;
      v6 = &model->polygons[i->polygonNum];
      if ( v6->checkCount != checkCount )
      {
        v6->checkCount = checkCount;
        v7 = model->node;
        while ( 1 )
        {
          for ( j = v7->polygons; j != nullptr; j = j->next )
          {
            v9 = &model->polygons[j->polygonNum];
            if ( v9->material == v6->material && v9->contents == v6->contents && v9 != v6 )
              idCollisionModelBuilder::FindInternalEdgesOnPolygon(model, p1: v6, p2: v9);
          }
          planeType = v7->planeType;
          if ( v7->planeType == -1 )
            break;
          planeDist = v7->planeDist;
          if ( *(&v6->bounds.b[0].x + planeType) <= planeDist )
          {
            if ( *(&v6->bounds.b[1].x + planeType) >= planeDist )
            {
              idCollisionModelBuilder::FindInternalPolygonEdges(model, node: v7->children[1], polygon: v6);
              v7 = v7->children[0];
            }
            else
            {
              v7 = v7->children[1];
            }
          }
          else
          {
            v7 = v7->children[0];
          }
        }
      }
    }
    if ( node->planeType == -1 )
      break;
    idCollisionModelBuilder::FindInternalEdges(model, node: node->children[1]);
    node = node->children[0];
  }
}


// ========================================================================
// ?OffsetPolygonEdges@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildPolygon_t@@@Z
// EA  : 0x825C4CC8
// RVA : 0x005C4CC8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::OffsetPolygonEdges(cm_buildModel_t *model, cm_buildPolygon_t *p)
{
  signed int numEdges; // r26
  int v3; // r25
  int v4; // r6
  double v5; // fp10
  int firstEdge; // r5
  int *polygonEdges; // r30
  cm_buildEdge_t *edges; // r29
  cm_buildVertex_t *vertices; // r8
  int v10; // ctr
  int v11; // r10
  int v12; // r7
  unsigned int v13; // r9
  unsigned int v14; // r27
  cm_buildEdge_t *v15; // r10
  int v16; // r22
  int v17; // r7
  float *p_x; // r10
  int v19; // r9
  double x; // fp12
  double v21; // fp7
  float *v22; // r9
  double v23; // fp3
  double v24; // fp6
  double v25; // fp12
  double v26; // fp4
  double v29; // fp9
  double v30; // fp5
  double v31; // fp5
  double v32; // fp5
  double v33; // fp2
  double v34; // fp9
  double v35; // fp8
  double v38; // fp5
  double v39; // fp1
  double v40; // fp5
  double v41; // fp12
  int v42; // r4
  int v43; // r3
  int v44; // r10
  int v45; // r12
  signed int v46; // r11
  int *v47; // r9
  int v48; // r6
  signed int v49; // ctr
  int v50; // r5
  int v51; // r8
  int v52; // r11
  int *v53; // r10
  int v54; // r8
  _DWORD back_chain[19]; // [sp+0h] [-B0h]
  int v56; // [sp+4Ch] [-64h] BYREF

  numEdges = p->numEdges;
  v3 = 0;
  v4 = 0;
  v5 = 1.0;
  if ( numEdges > 0 )
  {
    firstEdge = p->firstEdge;
    polygonEdges = model->polygonEdges;
    edges = model->edges;
    vertices = model->vertices;
    v10 = p->numEdges;
    do
    {
      v11 = numEdges + v4 - 1;
      v12 = __ROL4__(v11, 1);
      v13 = polygonEdges[firstEdge + v4];
      v14 = polygonEdges[v11 % numEdges + firstEdge];
      v15 = &edges[abs32(v13)];
      v16 = v12 - 1;
      v17 = *(int *)((char *)v15->vertexNum + ((~v13 >> 29) & 4));
      p_x = &vertices[*(int *)((char *)v15->vertexNum + ((v13 >> 29) & 4))].p.x;
      v19 = edges[abs32(v14)].vertexNum[v14 >> 31];
      __twllei(numEdges, 0);
      x = vertices[v17].p.x;
      __twlgei(numEdges & ~v16, 0xFFFFFFFF);
      v21 = (float)((float)x - *p_x);
      v22 = &vertices[v19].p.x;
      v23 = (float)(vertices[v17].p.y - p_x[1]);
      v24 = (float)(v22[1] - p_x[1]);
      v25 = (float)(v22[2] - p_x[2]);
      v26 = (float)(vertices[v17].p.z - p_x[2]);
      _FP9 = (float)((float)((float)((float)v24 * (float)v24)
                           + (float)((float)((float)v25 * (float)v25)
                                   + (float)((float)(*v22 - *p_x) * (float)(*v22 - *p_x))))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f5, f9, f5, f13 }
      v29 = __frsqrte(_FP5);
      v30 = (float)((float)-(float)((float)((float)((float)v29
                                                  * (float)((float)((float)((float)v24 * (float)v24)
                                                                  + (float)((float)((float)v25 * (float)v25)
                                                                          + (float)((float)(*v22 - *p_x)
                                                                                  * (float)(*v22 - *p_x))))
                                                          * (float)0.5))
                                          * (float)v29)
                                  - (float)1.5)
                  * (float)v29);
      v31 = (float)((float)-(float)((float)((float)((float)v30
                                                  * (float)((float)((float)((float)v24 * (float)v24)
                                                                  + (float)((float)((float)v25 * (float)v25)
                                                                          + (float)((float)(*v22 - *p_x)
                                                                                  * (float)(*v22 - *p_x))))
                                                          * (float)0.5))
                                          * (float)v30)
                                  - (float)1.5)
                  * (float)v30);
      v32 = (float)((float)-(float)((float)((float)((float)v31
                                                  * (float)((float)((float)((float)v24 * (float)v24)
                                                                  + (float)((float)((float)v25 * (float)v25)
                                                                          + (float)((float)(*v22 - *p_x)
                                                                                  * (float)(*v22 - *p_x))))
                                                          * (float)0.5))
                                          * (float)v31)
                                  - (float)1.5)
                  * (float)v31);
      v33 = (float)((float)(*v22 - *p_x) * (float)v32);
      v34 = (float)((float)v32 * (float)(v22[1] - p_x[1]));
      v35 = (float)((float)(v22[2] - p_x[2]) * (float)v32);
      _FP1 = (float)((float)((float)((float)v21 * (float)v21)
                           + (float)((float)((float)v26 * (float)v26) + (float)((float)v23 * (float)v23)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f6, f1, f5, f13 }
      v38 = __frsqrte(_FP6);
      v39 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38
                                                                                          * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v26 * (float)v26) + (float)((float)v23 * (float)v23)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v38)
                                                                          - (float)1.5)
                                                          * (float)v38)
                                                  * (float)((float)((float)((float)v21 * (float)v21)
                                                                  + (float)((float)((float)v26 * (float)v26)
                                                                          + (float)((float)v23 * (float)v23)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v38
                                                                                  * (float)((float)((float)((float)v21 * (float)v21)
                                                                                                  + (float)((float)((float)v26 * (float)v26) + (float)((float)v23 * (float)v23)))
                                                                                          * (float)0.5))
                                                                          * (float)v38)
                                                                  - (float)1.5)
                                                  * (float)v38))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v38
                                                          * (float)((float)((float)((float)v21 * (float)v21)
                                                                          + (float)((float)((float)v26 * (float)v26)
                                                                                  + (float)((float)v23 * (float)v23)))
                                                                  * (float)0.5))
                                                  * (float)v38)
                                          - (float)1.5)
                          * (float)v38));
      v40 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v26 * (float)v26) + (float)((float)v23 * (float)v23))) * (float)0.5)) * (float)v38) - (float)1.5)
                                                                                                  * (float)v38)
                                                                                          * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v26 * (float)v26) + (float)((float)v23 * (float)v23)))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v26 * (float)v26) + (float)((float)v23 * (float)v23))) * (float)0.5)) * (float)v38) - (float)1.5)
                                                                                          * (float)v38))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v38
                                                                                                  * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v26 * (float)v26) + (float)((float)v23 * (float)v23))) * (float)0.5))
                                                                                          * (float)v38)
                                                                                  - (float)1.5)
                                                                  * (float)v38))
                                                  * (float)((float)((float)((float)v21 * (float)v21)
                                                                  + (float)((float)((float)v26 * (float)v26)
                                                                          + (float)((float)v23 * (float)v23)))
                                                          * (float)0.5))
                                          * (float)v39)
                                  - (float)1.5)
                  * (float)v39);
      v41 = __fabs((float)((float)((float)((float)(vertices[v17].p.y - p_x[1]) * (float)v40) * (float)v34)
                         + (float)((float)((float)((float)(vertices[v17].p.z - p_x[2]) * (float)v40) * (float)v35)
                                 + (float)((float)((float)v40 * (float)v21) * (float)v33))));
      if ( v41 < v5 )
      {
        v5 = v41;
        v3 = v4;
      }
      ++v4;
      --v10;
    }
    while ( v10 != 0 );
  }
  v43 = ((int (*)(void))RtlCheckStack12)();
  v44 = 0;
  *(_DWORD *)((char *)back_chain + v45) = back_chain[0];
  if ( numEdges > 0 )
  {
    v46 = *(_DWORD *)(v42 + 52);
    v47 = &v56;
    v48 = *(_DWORD *)(v42 + 56);
    v49 = numEdges;
    v50 = *(_DWORD *)(v43 + 64);
    do
    {
      v51 = v46 + v44++ + v3;
      __twllei(v46, 0);
      __twlgei(v46 & ~(__ROL4__(v51 - 1, 1) - 1), 0xFFFFFFFF);
      *++v47 = *(_DWORD *)(4 * ((v51 - 1) % v46 + v48) + v50);
      --v49;
    }
    while ( v49 != 0 );
  }
  v52 = 0;
  if ( numEdges > 0 )
  {
    v53 = &v56;
    do
    {
      ++v53;
      v54 = *(_DWORD *)(v42 + 56) + v52++;
      *(_DWORD *)(4 * v54 + *(_DWORD *)(v43 + 64)) = *v53;
    }
    while ( v52 < *(_DWORD *)(v42 + 52) );
  }
}


// ========================================================================
// ?OffsetPolygonEdges_r@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildNode_t@@@Z
// EA  : 0x825C4FA0
// RVA : 0x005C4FA0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::OffsetPolygonEdges_r(cm_buildModel_t *model, cm_buildNode_t *node)
{
  cm_buildPolygonRef_t *i; // r30
  int checkCount; // r11
  cm_buildPolygon_t *v6; // r4

  while ( 1 )
  {
    for ( i = node->polygons; i != nullptr; i = i->next )
    {
      checkCount = model->checkCount;
      v6 = &model->polygons[i->polygonNum];
      if ( v6->checkCount != checkCount )
      {
        v6->checkCount = checkCount;
        idCollisionModelBuilder::OffsetPolygonEdges(model, p: v6);
      }
    }
    if ( node->planeType == -1 )
      break;
    idCollisionModelBuilder::OffsetPolygonEdges_r(model, node: node->children[1]);
    node = node->children[0];
  }
}


// ========================================================================
// ?SplitterDividesPrimitives@idCollisionModelBuilder@@CA_NPAUcm_buildModel_t@@PBUcm_buildNode_t@@HM@Z
// EA  : 0x825C5020
// RVA : 0x005C5020
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::SplitterDividesPrimitives(
        cm_buildModel_t *model,
        const cm_buildNode_t *node,
        int planeType,
        double planeDist)
{
  char v4; // r6
  char v5; // r7
  cm_buildPolygonRef_t *i; // r10
  cm_buildPolygon_t *v7; // r11
  cm_buildPolytopeRef_t *j; // r10
  cm_buildPolytope_t *v9; // r11

  v4 = 0;
  v5 = 0;
  if ( node == nullptr )
    return 0;
  while ( 1 )
  {
    for ( i = node->polygons; i != nullptr; i = i->next )
    {
      v7 = &model->polygons[i->polygonNum];
      if ( *(&v7->bounds.b[0].x + planeType) < planeDist )
      {
        if ( *(&v7->bounds.b[1].x + planeType) <= planeDist )
          v5 = 1;
      }
      else
      {
        v4 = 1;
      }
    }
    for ( j = node->polytopes; j != nullptr; j = j->next )
    {
      v9 = &model->polytopes[j->polytopeNum];
      if ( *(&v9->bounds.b[0].x + planeType) < planeDist )
      {
        if ( *(&v9->bounds.b[1].x + planeType) <= planeDist )
          v5 = 1;
      }
      else
      {
        v4 = 1;
      }
    }
    if ( v4 != 0 && v5 != 0 )
      break;
    node = node->parent;
    if ( node == nullptr )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?FindSplitter@idCollisionModelBuilder@@CA_NPAUcm_buildModel_t@@PBUcm_buildNode_t@@ABVidBounds@@AAHAAM@Z
// EA  : 0x825C5128
// RVA : 0x005C5128
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::FindSplitter(
        cm_buildModel_t *model,
        const cm_buildNode_t *node,
        const idBounds *bounds,
        int *planeType,
        float *planeDist)
{
  cm_buildPolygonRef_t *polygons; // r11
  int v6; // r20
  int i; // r4
  cm_buildPolytopeRef_t *polytopes; // r11
  int j; // r5
  double y; // fp12
  double v16; // fp11
  double v17; // fp10
  double v18; // fp6
  int k; // r6
  int v20; // r11
  double v21; // fp0
  int v22; // r9
  unsigned __int8 v23; // r11
  double v24; // fp9
  int v25; // r19
  double v26; // fp10
  double v27; // fp11
  int v28; // r5
  double v29; // fp12
  const cm_buildNode_t *v30; // r25
  cm_buildPolytopeRef_t *v31; // r28
  int v32; // r29
  int v33; // r27
  int v34; // r30
  float *v35; // r31
  double v36; // fp1
  double v37; // fp13
  double v38; // fp1
  const cm_buildNode_t *v39; // r25
  cm_buildPolygonRef_t *v40; // r29
  int v41; // r27
  int v42; // r28
  int v43; // r30
  float *v44; // r31
  double v45; // fp1
  double v46; // fp13
  double v47; // fp1
  float v49; // [sp+50h] [-90h] BYREF
  float v50[3]; // [sp+54h] [-8Ch] BYREF
  int v51; // [sp+60h] [-80h] BYREF
  _DWORD v52[31]; // [sp+64h] [-7Ch] BYREF

  polygons = node->polygons;
  v6 = 0;
  for ( i = 0; polygons != nullptr; ++i )
    polygons = polygons->next;
  polytopes = node->polytopes;
  for ( j = 0; polytopes != nullptr; ++j )
    polytopes = polytopes->next;
  if ( i > 4 || j > 4 )
  {
    y = bounds->b[1].y;
    v16 = (float)(bounds->b[1].x - bounds->b[0].x);
    v17 = bounds->b[0].y;
    v51 = 0;
    v18 = (float)(bounds->b[1].z - bounds->b[0].z);
    v52[0] = 1;
    v49 = v16;
    v50[0] = (float)y - (float)v17;
    v52[1] = 2;
    v50[1] = v18;
    for ( k = 0; k < 2; ++k )
    {
      v20 = k;
      v21 = v50[k - 1];
      if ( v21 < v50[k] )
      {
        v50[v20 - 1] = v50[k];
        v50[v20] = v21;
        k = -1;
        v22 = v52[v20 - 1];
        v52[v20 - 1] = v52[v20];
        v52[v20] = v22;
      }
    }
    if ( i >= 32 || (v23 = 0, j >= 32) )
      v23 = 1;
    v24 = 128.0;
    if ( v49 >= 128.0 || v23 != 0 )
    {
      v25 = v23;
      v26 = 32.0;
      do
      {
        v27 = v50[v6 - 1];
        v28 = v52[v6 - 1];
        v29 = v27;
        if ( v25 == 0 && v27 < v24 )
          break;
        v30 = node;
        do
        {
          v31 = v30->polytopes;
          if ( v31 != nullptr )
          {
            v32 = 4 * v28;
            v33 = 4 * (v28 + 3);
            do
            {
              v34 = 2;
              v35 = (float *)((char *)&model->polytopes[v31->polytopeNum] + v32);
              do
              {
                v36 = *v35;
                if ( v36 < *(float *)((char *)&bounds->b[0].x + v33)
                  && v36 > *(float *)((char *)&bounds->b[0].x + v32)
                  && __fabs((float)((float)(*(float *)((char *)&bounds->b[0].x + v33) - *v35)
                                  - (float)(*v35 - *(float *)((char *)&bounds->b[0].x + v32)))) < v29
                  && (unsigned __int8)idCollisionModelBuilder::SplitterDividesPrimitives(
                                        model,
                                        node,
                                        planeType: v28,
                                        planeDist: v36) != 0 )
                {
                  *planeType = v28;
                  *planeDist = v38;
                  v29 = v37;
                }
                --v34;
                v35 += 3;
              }
              while ( v34 != 0 );
              v31 = v31->next;
            }
            while ( v31 != nullptr );
          }
          v30 = v30->parent;
        }
        while ( v30 != nullptr );
        v39 = node;
        do
        {
          v40 = v39->polygons;
          if ( v40 != nullptr )
          {
            v41 = 4 * (v28 + 3);
            v42 = 4 * (v28 + 4);
            do
            {
              v43 = 2;
              v44 = (float *)((char *)&model->polygons[v40->polygonNum].plane.a + v42);
              do
              {
                v45 = *v44;
                if ( v45 < *(float *)((char *)&bounds->b[0].x + v41)
                  && v45 > *(&bounds->b[0].x + v28)
                  && __fabs((float)((float)(*(float *)((char *)&bounds->b[0].x + v41) - *v44)
                                  - (float)(*v44 - *(&bounds->b[0].x + v28)))) < v29
                  && (unsigned __int8)idCollisionModelBuilder::SplitterDividesPrimitives(
                                        model,
                                        node,
                                        planeType: v28,
                                        planeDist: v45) != 0 )
                {
                  *planeType = v28;
                  *planeDist = v47;
                  v29 = v46;
                }
                --v43;
                v44 += 3;
              }
              while ( v43 != 0 );
              v40 = v40->next;
            }
            while ( v40 != nullptr );
          }
          v39 = v39->parent;
        }
        while ( v39 != nullptr );
        if ( v29 < v27
          && (v25 != 0
           || (float)(*planeDist - *(&bounds->b[0].x + v28)) >= v26
           && (float)(*(&bounds->b[1].x + v28) - *planeDist) >= v26) )
        {
          return 1;
        }
        ++v6;
      }
      while ( v6 < 3 );
    }
  }
  return 0;
}


// ========================================================================
// ?FilterPolygonIntoTree_r@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildNode_t@@PAUcm_buildPolygonRef_t@@PAUcm_buildPolygon_t@@@Z
// EA  : 0x825C5470
// RVA : 0x005C5470
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::FilterPolygonIntoTree_r(
        cm_buildModel_t *model,
        cm_buildNode_t *node,
        cm_buildPolygonRef_t *pref,
        cm_buildPolygon_t *p)
{
  cm_buildNode_t *v5; // r31
  idBounds *p_bounds; // r28
  double planeDist; // fp0

  v5 = node;
  if ( node->planeType != -1 )
  {
    p_bounds = &p->bounds;
    while ( 1 )
    {
      if ( CM_R_InsideAllChildren(node: v5, bounds: p_bounds) != 0 )
        goto LABEL_10;
      planeDist = v5->planeDist;
      if ( *(&p->bounds.b[0].x + v5->planeType) >= planeDist )
        goto LABEL_8;
      if ( *(&p->bounds.b[1].x + v5->planeType) > planeDist )
        break;
      v5 = v5->children[1];
LABEL_9:
      if ( v5->planeType == -1 )
        goto LABEL_10;
    }
    idCollisionModelBuilder::FilterPolygonIntoTree_r(model, node: v5->children[1], pref: nullptr, p);
LABEL_8:
    v5 = v5->children[0];
    goto LABEL_9;
  }
LABEL_10:
  if ( pref != nullptr )
  {
    pref->next = v5->polygons;
    v5->polygons = pref;
  }
  else
  {
    idCollisionModelBuilder::AddPolygonToNode(model, node: v5, p);
  }
}


// ========================================================================
// ?FilterPolytopeIntoTree_r@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildNode_t@@PAUcm_buildPolytopeRef_t@@PAUcm_buildPolytope_t@@@Z
// EA  : 0x825C5540
// RVA : 0x005C5540
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::FilterPolytopeIntoTree_r(
        cm_buildModel_t *model,
        cm_buildNode_t *node,
        cm_buildPolytopeRef_t *pref,
        cm_buildPolytope_t *b)
{
  cm_buildNode_t *v5; // r31
  double planeDist; // fp0

  v5 = node;
  if ( node->planeType != -1 )
  {
    while ( 1 )
    {
      if ( CM_R_InsideAllChildren(node: v5, bounds: &b->bounds) != 0 )
        goto LABEL_9;
      planeDist = v5->planeDist;
      if ( *(&b->bounds.b[0].x + v5->planeType) >= planeDist )
        goto LABEL_7;
      if ( *(&b->bounds.b[1].x + v5->planeType) > planeDist )
        break;
      v5 = v5->children[1];
LABEL_8:
      if ( v5->planeType == -1 )
        goto LABEL_9;
    }
    idCollisionModelBuilder::FilterPolytopeIntoTree_r(model, node: v5->children[1], pref: nullptr, b);
LABEL_7:
    v5 = v5->children[0];
    goto LABEL_8;
  }
LABEL_9:
  if ( pref != nullptr )
  {
    pref->next = v5->polytopes;
    v5->polytopes = pref;
  }
  else
  {
    idCollisionModelBuilder::AddPolytopeToNode(model, node: v5, b);
  }
}


// ========================================================================
// ?CreateAxialBSPTree_r@idCollisionModelBuilder@@CAPAUcm_buildNode_t@@PAUcm_buildModel_t@@PAU2@@Z
// EA  : 0x825C5608
// RVA : 0x005C5608
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

cm_buildNode_t *__fastcall idCollisionModelBuilder::CreateAxialBSPTree_r(cm_buildModel_t *model, cm_buildNode_t *node)
{
  idBounds *p_bounds; // r30
  cm_buildNode_t *v6; // r3
  cm_buildNode_t *v7; // r26
  int v8; // r29
  double v9; // fp31
  cm_buildNode_t *v10; // r3
  double y; // fp7
  cm_buildNode_t *v12; // r25
  cm_buildNode_t *v13; // r31
  cm_buildPolygonRef_t *polygons; // r5
  cm_buildPolygonRef_t *v15; // r29
  cm_buildPolygonRef_t *next; // r30
  cm_buildPolygon_t *v17; // r6
  cm_buildPolygonRef_t *v18; // r5
  cm_buildPolytopeRef_t *polytopes; // r5
  cm_buildPolytopeRef_t *v20; // r29
  int planeType; // r11
  cm_buildPolytopeRef_t *v22; // r30
  cm_buildPolytope_t *v23; // r6
  double planeDist; // fp0
  float v25; // [sp+50h] [-50h] BYREF
  int v26; // [sp+54h] [-4Ch] BYREF

  p_bounds = &node->bounds;
  if ( (unsigned __int8)idCollisionModelBuilder::FindSplitter(
                          model,
                          node,
                          bounds: &node->bounds,
                          planeType: &v26,
                          planeDist: &v25) != 0 )
  {
    v6 = idCollisionModelBuilder::AllocNode(model, blockSize: 256);
    v6->bounds.b[0].x = p_bounds->b[0].x;
    v7 = v6;
    v8 = v26;
    v6->bounds.b[0].y = p_bounds->b[0].y;
    v6->bounds.b[0].z = p_bounds->b[0].z;
    v6->parent = node;
    v6->bounds.b[1].x = node->bounds.b[1].x;
    v6->bounds.b[1].y = node->bounds.b[1].y;
    v9 = v25;
    v6->bounds.b[1].z = node->bounds.b[1].z;
    *(&v6->bounds.b[0].x + v8) = v9;
    v10 = idCollisionModelBuilder::AllocNode(model, blockSize: 256);
    v10->bounds.b[0].x = p_bounds->b[0].x;
    y = p_bounds->b[0].y;
    v10->parent = node;
    v10->bounds.b[0].y = y;
    v12 = v10;
    v10->bounds.b[0].z = p_bounds->b[0].z;
    v13 = node;
    v10->bounds.b[1] = node->bounds.b[1];
    *(&v10->bounds.b[1].x + v8) = v9;
    node->planeType = v8;
    node->planeDist = v9;
    node->children[0] = v7;
    node->children[1] = v10;
    do
    {
      polygons = v13->polygons;
      v15 = nullptr;
      if ( polygons != nullptr )
      {
        do
        {
          next = polygons->next;
          if ( CM_R_InsideAllChildren(node: v13, bounds: &model->polygons[polygons->polygonNum].bounds) != 0 )
          {
            v15 = v18;
          }
          else
          {
            idCollisionModelBuilder::FilterPolygonIntoTree_r(model, node: v13, pref: v18, p: v17);
            if ( v15 != nullptr )
              v15->next = next;
            else
              v13->polygons = next;
          }
          polygons = next;
        }
        while ( next != nullptr );
      }
      polytopes = v13->polytopes;
      v20 = nullptr;
      if ( polytopes != nullptr )
      {
        do
        {
          planeType = v13->planeType;
          v22 = polytopes->next;
          v23 = &model->polytopes[polytopes->polytopeNum];
          if ( v13->planeType == -1
            || (planeDist = v13->planeDist, *(&v23->bounds.b[0].x + planeType) < planeDist)
            && *(&v23->bounds.b[1].x + planeType) > planeDist
            && CM_R_InsideAllChildren(node: v13->children[0], bounds: &v23->bounds) != 0
            && CM_R_InsideAllChildren(node: v13->children[1], bounds: &v23->bounds) != 0 )
          {
            v20 = polytopes;
          }
          else
          {
            idCollisionModelBuilder::FilterPolytopeIntoTree_r(model, node: v13, pref: polytopes, b: v23);
            if ( v20 != nullptr )
              v20->next = v22;
            else
              v13->polytopes = v22;
          }
          polytopes = v22;
        }
        while ( v22 != nullptr );
      }
      v13 = v13->parent;
    }
    while ( v13 != nullptr );
    idCollisionModelBuilder::CreateAxialBSPTree_r(model, node: v7);
    idCollisionModelBuilder::CreateAxialBSPTree_r(model, node: v12);
    return node;
  }
  else
  {
    v25 = 0.0;
    v26 = 0;
    idCollisionModelBuilder::GetPrimitiveCounts(node, polygonCount: (int *)&v25, polytopeCount: &v26);
    if ( SLODWORD(v25) > 255 )
      idLib::Warning(fmt: "node has %d polygons", v25);
    if ( v26 > 255 )
      idLib::Warning(fmt: "node has %d polytopes", v26);
    node->planeType = -1;
    return node;
  }
}


// ========================================================================
// ?ClearHash@idCollisionModelBuilder@@CAXABVidBounds@@@Z
// EA  : 0x825C58C0
// RVA : 0x005C58C0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::ClearHash(const idBounds *bounds)
{
  double v2; // fp0
  int v3; // r10
  int v4; // r11
  int v5; // r9

  idHashIndex::Clear(this: buildData.cm_vertexHash);
  idHashIndex::Clear(this: buildData.cm_edgeHash);
  buildData.cm_modelBounds = *bounds;
  v2 = (float)(bounds->b[1].x - bounds->b[0].x);
  if ( (float)(bounds->b[1].y - bounds->b[0].y) > v2 )
    v2 = (float)(bounds->b[1].y - bounds->b[0].y);
  v3 = 0;
  v4 = 1;
  v5 = (int)(float)((float)v2 * (float)0.015625);
  if ( v5 <= 1 )
    goto LABEL_6;
  do
  {
    v4 = __ROL4__(v4, 1);
    ++v3;
  }
  while ( v4 < v5 );
  if ( v3 != 0 )
    buildData.cm_vertexShift = v3;
  else
LABEL_6:
    buildData.cm_vertexShift = 1;
}


// ========================================================================
// ?GetVertex@idCollisionModelBuilder@@CAHPAUcm_buildModel_t@@ABVidVec3@@PAH@Z
// EA  : 0x825C59B0
// RVA : 0x005C59B0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::GetVertex(
        cm_buildModel_t *model,
        const idVec3 *v,
        int *vertexNum,
        long double a4)
{
  int v4; // r28
  const idVec3 *v7; // r31
  int i; // r29
  double x; // fp29
  double v10; // fp28
  double v11; // fp30
  double v12; // fp29
  int lookupMask; // r7
  int *hash; // r6
  int v15; // r5
  int v16; // fp7
  int v17; // r27
  int v18; // r11
  cm_buildVertex_t *v19; // r9
  __int64 v20; // r11
  cm_buildVertex_t *vertices; // r29
  double v22; // fp11
  cm_buildVertex_t *v23; // r3
  cm_buildVertex_t *v24; // r11
  idHashIndex *cm_vertexHash; // r31
  int numVertices; // r29
  int indexSize; // r11
  int v29; // r6
  float v30; // [sp+58h] [-68h] BYREF
  int v31; // [sp+5Ch] [-64h]
  float v32; // [sp+60h] [-60h]

  v4 = (char *)&v30 - (char *)v;
  v7 = v;
  for ( i = 3; i != 0; --i )
  {
    x = v7->x;
    *(double *)&a4 = (float)(v7->x + (float)0.5);
    a4 = floor(x: a4);
    if ( __fabs((float)((float)x - (float)*(double *)&a4)) >= 0.0099999998 )
    {
      *(float *)((char *)&v7->x + v4) = v7->x;
    }
    else
    {
      *(double *)&a4 = (float)(v7->x + (float)0.5);
      a4 = floor(x: a4);
      *(float *)((char *)&v7->x + v4) = *(double *)&a4;
    }
    v7 = (const idVec3 *)((char *)v7 + 4);
  }
  v10 = *(float *)&v31;
  v11 = v32;
  v12 = v30;
  lookupMask = buildData.cm_vertexHash->lookupMask;
  hash = buildData.cm_vertexHash->hash;
  v15 = buildData.cm_vertexHash->hashMask & lookupMask;
  v16 = (int)(float)((float)(*(float *)&v31 - buildData.cm_modelBounds.b[0].y) + (float)0.5);
  v31 = (int)(float)((float)(v30 - buildData.cm_modelBounds.b[0].x) + (float)0.5);
  v17 = (((v16 + 2) >> 2 << 6)
       + (((int)(float)((float)(v32 - buildData.cm_modelBounds.b[0].z) + (float)0.5) + 2) >> 2)
       + ((v31 + 2) >> 2))
      & 0xFFF;
  v18 = hash[v15 & v17];
  if ( v18 == -1 )
  {
LABEL_11:
    LODWORD(v20) = model->maxVertices;
    if ( model->numVertices >= (int)v20 )
    {
      vertices = model->vertices;
      HIDWORD(v20) = 0x82000000;
      v22 = (float)((float)((float)v20 * (float)1.5) + (float)1.0);
      v31 = (int)v22;
      model->maxVertices = (int)v22;
      v23 = (cm_buildVertex_t *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(2620) : TAG_COLLISION",
                                  size: 24 * (int)v22,
                                  tag: TAG_COLLISION,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
      model->vertices = v23;
      if ( vertices != nullptr )
      {
        memcpy(Dst: v23, Src: vertices, Size: 24 * model->numVertices);
        idMem::Free(this: &mem, ptr: vertices, align: ALIGN_16);
      }
      idHashIndex::ResizeIndex(this: buildData.cm_vertexHash, newIndexSize: model->maxVertices);
    }
    v24 = &model->vertices[model->numVertices];
    v24->p.x = v12;
    v24->st[1] = 0;
    v24->p.z = v11;
    v24->st[0] = 0;
    v24->p.y = v10;
    v24->checkCount = 0;
    *vertexNum = model->numVertices;
    cm_vertexHash = buildData.cm_vertexHash;
    numVertices = model->numVertices;
    indexSize = buildData.cm_vertexHash->indexSize;
    if ( buildData.cm_vertexHash->hash == idHashIndex::INVALID_INDEX )
    {
      if ( numVertices >= indexSize )
        indexSize = numVertices + 1;
      idHashIndex::Allocate(
        this: buildData.cm_vertexHash,
        newHashSize: buildData.cm_vertexHash->hashSize,
        newIndexSize: indexSize);
    }
    else if ( numVertices >= indexSize )
    {
      idHashIndex::ResizeIndex(this: buildData.cm_vertexHash, newIndexSize: numVertices + 1);
    }
    v29 = cm_vertexHash->hashMask & v17;
    cm_vertexHash->indexChain[numVertices] = cm_vertexHash->hash[v29];
    cm_vertexHash->hash[v29] = numVertices;
    ++model->numVertices;
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v19 = &model->vertices[v18];
      if ( __fabs((float)(v32 - v19->p.z)) < 0.1
        && __fabs((float)((float)v12 - v19->p.x)) < 0.1
        && __fabs((float)((float)v10 - v19->p.y)) < 0.1 )
      {
        break;
      }
      v18 = buildData.cm_vertexHash->indexChain[lookupMask & v18];
      if ( v18 == -1 )
        goto LABEL_11;
    }
    *vertexNum = v18;
    return 1;
  }
}


// ========================================================================
// ?GetEdge@idCollisionModelBuilder@@CAHPAUcm_buildModel_t@@ABVidVec3@@1PAHH@Z
// EA  : 0x825C5D00
// RVA : 0x005C5D00
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::GetEdge(
        cm_buildModel_t *model,
        const idVec3 *v1,
        const idVec3 *v2,
        int *edgeNum,
        int v1num,
        long double a6,
        int a7,
        int a8,
        int a9,
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
        int a21)
{
  int numEdges; // r11
  int v25; // r28
  int v26; // r30
  int Vertex; // r3
  int v28; // r3
  int v29; // r29
  int hashMask; // r11
  int v32; // r27
  int lookupMask; // r8
  int v34; // r11
  cm_buildEdge_t *v35; // r10
  __int64 v36; // r11
  cm_buildEdge_t *edges; // r24
  unsigned int v38; // r5
  cm_buildEdge_t *v39; // r3
  cm_buildEdge_t *v40; // r11
  int v41; // [sp+50h] [-60h] BYREF
  int v42; // [sp+54h] [-5Ch]

  numEdges = model->numEdges;
  a21 = v1num;
  v25 = v1num;
  if ( numEdges == 0 )
    model->numEdges = 1;
  if ( v1num == -1 )
  {
    Vertex = idCollisionModelBuilder::GetVertex(model, v: v1, vertexNum: &a21, a4: a6);
    v25 = a21;
    v26 = Vertex;
  }
  else
  {
    v26 = 1;
  }
  v28 = idCollisionModelBuilder::GetVertex(model, v: v2, vertexNum: &v41, a4: a6);
  v29 = v41;
  if ( v25 == v41 )
  {
    *edgeNum = 0;
    return 1;
  }
  else
  {
    hashMask = buildData.cm_edgeHash->hashMask;
    v32 = (v41 + v25) & hashMask;
    if ( (v28 & v26) == 0 )
      goto LABEL_14;
    lookupMask = buildData.cm_edgeHash->lookupMask;
    v34 = buildData.cm_edgeHash->hash[lookupMask & hashMask & v32];
    if ( v34 != -1 )
    {
      while ( 1 )
      {
        v35 = &model->edges[v34];
        if ( v35->numUsers == 1 && v35->vertexNum[0] == v41 && v35->vertexNum[1] == v25 )
          break;
        v34 = buildData.cm_edgeHash->indexChain[lookupMask & v34];
        if ( v34 == -1 )
          goto LABEL_14;
      }
      *edgeNum = -v34;
    }
    if ( v34 >= 0 )
    {
      ++model->edges[v34].numUsers;
      return 1;
    }
    else
    {
LABEL_14:
      LODWORD(v36) = model->maxEdges;
      if ( model->numEdges >= (int)v36 )
      {
        edges = model->edges;
        HIDWORD(v36) = 0x82000000;
        v42 = (int)(float)((float)((float)v36 * (float)1.5) + (float)1.0);
        v38 = 32 * v42;
        model->maxEdges = v42;
        v39 = (cm_buildEdge_t *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(2706) : TAG_COLLISION",
                                  size: v38,
                                  tag: TAG_COLLISION,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
        model->edges = v39;
        memcpy(Dst: v39, Src: edges, Size: 32 * model->numEdges);
        idMem::Free(this: &mem, ptr: edges, align: ALIGN_16);
        idHashIndex::ResizeIndex(this: buildData.cm_edgeHash, newIndexSize: model->maxEdges);
      }
      v40 = &model->edges[model->numEdges];
      v40->vertexNum[0] = v25;
      v40->vertexNum[1] = v29;
      *(_WORD *)&v40->internal = 1;
      v40->normal.z = 0.0;
      v40->normal.y = 0.0;
      v40->normal.x = 0.0;
      v40->checkCount = 0;
      *edgeNum = model->numEdges;
      idHashIndex::Add(this: buildData.cm_edgeHash, key: v32, index: model->numEdges);
      ++model->numEdges;
      return 0;
    }
  }
}


// ========================================================================
// ?GetNodeBounds_r@idCollisionModelBuilder@@CAXPBUcm_buildModel_t@@PBUcm_buildNode_t@@AAVidBounds@@@Z
// EA  : 0x825C5F60
// RVA : 0x005C5F60
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::GetNodeBounds_r(
        const cm_buildModel_t *model,
        const cm_buildNode_t *node,
        idBounds *bounds)
{
  cm_buildPolygonRef_t *polygons; // r10
  cm_buildPolygon_t *v7; // r9
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v11; // fp10
  double v12; // fp9
  float *p_a; // r11
  double v23; // fp4
  float *v27; // r11
  double v28; // fp12
  double v29; // fp11
  double v30; // fp10
  cm_buildPolytopeRef_t *polytopes; // r10
  cm_buildPolytope_t *v44; // r9
  double v45; // fp13
  double v46; // fp12
  double v47; // fp11
  double v48; // fp10
  double v49; // fp9
  float *v50; // r11
  double v62; // fp1
  float *v64; // r11
  double v65; // fp12
  double v66; // fp13
  double v67; // fp11

  while ( 1 )
  {
    polygons = node->polygons;
    if ( polygons != nullptr )
    {
      v7 = model->polygons;
      do
      {
        y = bounds->b[0].y;
        z = bounds->b[0].z;
        x = bounds->b[1].x;
        v11 = bounds->b[1].y;
        v12 = bounds->b[1].z;
        p_a = &v7[polygons->polygonNum].plane.a;
        _FP7 = (float)(bounds->b[0].x - p_a[4]);
        __asm { fsel      f6, f7, f8, f0 }
        bounds->b[0].x = _FP6;
        _FP4 = (float)((float)y - p_a[5]);
        __asm { fsel      f3, f4, f5, f13 }
        bounds->b[0].y = _FP3;
        _FP1 = (float)((float)z - p_a[6]);
        __asm { fsel      f0, f1, f2, f12 }
        bounds->b[0].z = _FP0;
        _FP12 = (float)(p_a[4] - (float)x);
        __asm { fsel      f7, f12, f13, f11 }
        bounds->b[1].x = _FP7;
        _FP5 = (float)(p_a[5] - (float)v11);
        v23 = _FP3;
        __asm { fsel      f3, f5, f6, f10 }
        bounds->b[1].y = _FP3;
        _FP1 = (float)(p_a[6] - (float)v12);
        __asm { fsel      f13, f1, f2, f9 }
        bounds->b[1].z = _FP13;
        v27 = &v7[polygons->polygonNum].plane.a;
        v28 = _FP7;
        v29 = _FP3;
        v30 = _FP13;
        _FP7 = (float)((float)_FP6 - v27[7]);
        __asm { fsel      f6, f7, f9, f8 }
        bounds->b[0].x = _FP6;
        _FP3 = (float)((float)v23 - v27[8]);
        __asm { fsel      f2, f3, f5, f4 }
        bounds->b[0].y = _FP2;
        _FP13 = (float)((float)_FP0 - v27[9]);
        __asm { fsel      f9, f13, f1, f0 }
        bounds->b[0].z = _FP9;
        _FP7 = (float)(v27[7] - (float)v28);
        __asm { fsel      f6, f7, f8, f12 }
        bounds->b[1].x = _FP6;
        _FP4 = (float)(v27[8] - (float)v29);
        __asm { fsel      f3, f4, f5, f11 }
        bounds->b[1].y = _FP3;
        _FP1 = (float)(v27[9] - (float)v30);
        __asm { fsel      f0, f1, f2, f10 }
        bounds->b[1].z = _FP0;
        polygons = polygons->next;
      }
      while ( polygons != nullptr );
    }
    polytopes = node->polytopes;
    if ( polytopes != nullptr )
    {
      v44 = model->polytopes;
      do
      {
        v45 = bounds->b[0].y;
        v46 = bounds->b[0].z;
        v47 = bounds->b[1].x;
        v48 = bounds->b[1].y;
        v49 = bounds->b[1].z;
        v50 = (float *)&v44[polytopes->polytopeNum];
        _FP7 = (float)(bounds->b[0].x - *v50);
        __asm { fsel      f6, f7, f8, f0 }
        bounds->b[0].x = _FP6;
        _FP4 = (float)((float)v45 - v50[1]);
        __asm { fsel      f3, f4, f5, f13 }
        bounds->b[0].y = _FP3;
        _FP1 = (float)((float)v46 - v50[2]);
        __asm { fsel      f0, f1, f2, f12 }
        bounds->b[0].z = _FP0;
        _FP12 = (float)(*v50 - (float)v47);
        __asm { fsel      f11, f12, f13, f11 }
        bounds->b[1].x = _FP11;
        _FP7 = (float)(v50[1] - (float)v48);
        __asm { fsel      f5, f7, f8, f10 }
        bounds->b[1].y = _FP5;
        _FP2 = (float)(v50[2] - (float)v49);
        v62 = _FP0;
        __asm { fsel      f0, f2, f3, f9 }
        bounds->b[1].z = _FP0;
        v64 = (float *)&v44[polytopes->polytopeNum];
        v65 = _FP5;
        v66 = _FP11;
        v67 = _FP0;
        _FP9 = (float)((float)_FP6 - v64[3]);
        __asm { fsel      f8, f9, f10, f6 }
        bounds->b[0].x = _FP8;
        _FP6 = (float)((float)_FP3 - v64[4]);
        __asm { fsel      f5, f6, f7, f4 }
        bounds->b[0].y = _FP5;
        _FP3 = (float)((float)v62 - v64[5]);
        __asm { fsel      f2, f3, f4, f1 }
        bounds->b[0].z = _FP2;
        _FP0 = (float)(v64[3] - (float)v66);
        __asm { fsel      f13, f0, f1, f13 }
        bounds->b[1].x = _FP13;
        _FP9 = (float)(v64[4] - (float)v65);
        __asm { fsel      f8, f9, f10, f12 }
        bounds->b[1].y = _FP8;
        _FP6 = (float)(v64[5] - (float)v67);
        __asm { fsel      f5, f6, f7, f11 }
        bounds->b[1].z = _FP5;
        polytopes = polytopes->next;
      }
      while ( polytopes != nullptr );
    }
    if ( node->planeType == -1 )
      break;
    idCollisionModelBuilder::GetNodeBounds_r(model, node: node->children[1], bounds);
    node = node->children[0];
  }
}


// ========================================================================
// ?GetNodeBounds@idCollisionModelBuilder@@CAXPBUcm_buildModel_t@@PBUcm_buildNode_t@@AAVidBounds@@@Z
// EA  : 0x825C61F0
// RVA : 0x005C61F0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::GetNodeBounds(
        const cm_buildModel_t *model,
        const cm_buildNode_t *node,
        idBounds *bounds)
{
  float *v3; // r7

  bounds->b[0].z = 1.0e30;
  bounds->b[0].y = 1.0e30;
  bounds->b[0].x = 1.0e30;
  bounds->b[1].z = -1.0e30;
  bounds->b[1].y = -1.0e30;
  bounds->b[1].x = -1.0e30;
  idCollisionModelBuilder::GetNodeBounds_r(model, node, bounds);
  if ( *v3 > (double)v3[3] )
  {
    v3[5] = 0.0;
    v3[4] = 0.0;
    v3[3] = 0.0;
    v3[2] = 0.0;
    v3[1] = 0.0;
    *v3 = 0.0;
  }
}


// ========================================================================
// ?GetStatsFromNode@idCollisionModelBuilder@@CAXPBUcm_buildModel_t@@PBUcm_buildNode_t@@AAUcm_buildNodeStats_t@@@Z
// EA  : 0x825C6288
// RVA : 0x005C6288
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::GetStatsFromNode(
        const cm_buildModel_t *buildModel,
        const cm_buildNode_t *buildNode,
        cm_buildNodeStats_t *stats)
{
  cm_buildPolygonRef_t *i; // r30
  int checkCount; // r11
  cm_buildPolygon_t *v5; // r6
  int v6; // r31
  int v7; // r10
  cm_buildEdge_t *v8; // r11
  int v9; // r9
  cm_buildVertex_t *v10; // r10
  int v11; // r10
  cm_buildVertex_t *v12; // r11
  int v13; // r10
  cm_buildMaterial_t *v14; // r11
  cm_buildPolytopeRef_t *j; // r8
  int v16; // r9
  cm_buildPolytope_t *v17; // r11
  int numPolytopePlanes; // r9
  int v19; // r4
  cm_buildMaterial_t *v20; // r11

  for ( i = buildNode->polygons; i != nullptr; i = i->next )
  {
    ++stats->numPrimitiveIndices;
    checkCount = buildModel->checkCount;
    v5 = &buildModel->polygons[i->polygonNum];
    if ( v5->checkCount != checkCount )
    {
      v5->checkCount = checkCount;
      v6 = 0;
      ++stats->numPolygons;
      stats->numPolygonEdges += v5->numEdges;
      stats->lastNumPolygonEdges = v5->numEdges;
      if ( v5->numEdges > 0 )
      {
        do
        {
          v7 = buildModel->checkCount;
          v8 = &buildModel->edges[abs32(buildModel->polygonEdges[v6 + v5->firstEdge])];
          if ( v8->checkCount != v7 )
          {
            v8->checkCount = v7;
            ++stats->numEdges;
            v9 = buildModel->checkCount;
            v10 = &buildModel->vertices[v8->vertexNum[0]];
            if ( v10->checkCount != v9 )
            {
              v10->checkCount = v9;
              ++stats->numVertices;
            }
            v11 = buildModel->checkCount;
            v12 = &buildModel->vertices[v8->vertexNum[1]];
            if ( v12->checkCount != v11 )
            {
              v12->checkCount = v11;
              ++stats->numVertices;
            }
          }
          ++v6;
        }
        while ( v6 < v5->numEdges );
      }
      v13 = buildModel->checkCount;
      v14 = &buildModel->materials.list[v5->material];
      if ( v14->checkCount != v13 )
      {
        v14->checkCount = v13;
        ++stats->numMaterials;
      }
    }
  }
  for ( j = buildNode->polytopes; j != nullptr; j = j->next )
  {
    ++stats->numPrimitiveIndices;
    v16 = buildModel->checkCount;
    v17 = &buildModel->polytopes[j->polytopeNum];
    if ( v17->checkCount != v16 )
    {
      v17->checkCount = v16;
      numPolytopePlanes = stats->numPolytopePlanes;
      ++stats->numPolytopes;
      stats->numPolytopePlanes = v17->numPlanes + numPolytopePlanes;
      v19 = buildModel->checkCount;
      v20 = &buildModel->materials.list[v17->material];
      if ( v20->checkCount != v19 )
      {
        v20->checkCount = v19;
        ++stats->numMaterials;
      }
    }
  }
}


// ========================================================================
// ?CreateStatsForSubTree_r@idCollisionModelBuilder@@CAXPBUcm_buildModel_t@@PBUcm_buildNode_t@@AAUcm_buildNodeStats_t@@@Z
// EA  : 0x825C64C0
// RVA : 0x005C64C0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::CreateStatsForSubTree_r(
        const cm_buildModel_t *buildModel,
        const cm_buildNode_t *buildNode,
        cm_buildNodeStats_t *stats)
{
  cm_buildPolygonRef_t *i; // r4
  cm_buildPolygon_t *v7; // r6
  int checkCount; // r11
  int v9; // r5
  int v10; // r10
  cm_buildEdge_t *v11; // r11
  int v12; // r9
  cm_buildVertex_t *v13; // r10
  int v14; // r10
  cm_buildVertex_t *v15; // r11
  int v16; // r10
  cm_buildMaterial_t *v17; // r11
  cm_buildPolytopeRef_t *j; // r8
  int v19; // r7
  cm_buildPolytope_t *v20; // r11
  int numPolytopePlanes; // r9
  int v22; // r5
  cm_buildMaterial_t *v23; // r11

  while ( 1 )
  {
    ++stats->numNodes;
    for ( i = buildNode->polygons; i != nullptr; i = i->next )
    {
      ++stats->numPrimitiveIndices;
      v7 = &buildModel->polygons[i->polygonNum];
      checkCount = buildModel->checkCount;
      if ( v7->checkCount != checkCount )
      {
        v7->checkCount = checkCount;
        v9 = 0;
        ++stats->numPolygons;
        stats->numPolygonEdges += v7->numEdges;
        stats->lastNumPolygonEdges = v7->numEdges;
        if ( v7->numEdges > 0 )
        {
          do
          {
            v10 = buildModel->checkCount;
            v11 = &buildModel->edges[abs32(buildModel->polygonEdges[v7->firstEdge + v9])];
            if ( v11->checkCount != v10 )
            {
              v11->checkCount = v10;
              ++stats->numEdges;
              v12 = buildModel->checkCount;
              v13 = &buildModel->vertices[v11->vertexNum[0]];
              if ( v13->checkCount != v12 )
              {
                v13->checkCount = v12;
                ++stats->numVertices;
              }
              v14 = buildModel->checkCount;
              v15 = &buildModel->vertices[v11->vertexNum[1]];
              if ( v15->checkCount != v14 )
              {
                v15->checkCount = v14;
                ++stats->numVertices;
              }
            }
            ++v9;
          }
          while ( v9 < v7->numEdges );
        }
        v16 = buildModel->checkCount;
        v17 = &buildModel->materials.list[v7->material];
        if ( v17->checkCount != v16 )
        {
          v17->checkCount = v16;
          ++stats->numMaterials;
        }
      }
    }
    for ( j = buildNode->polytopes; j != nullptr; j = j->next )
    {
      ++stats->numPrimitiveIndices;
      v19 = buildModel->checkCount;
      v20 = &buildModel->polytopes[j->polytopeNum];
      if ( v20->checkCount != v19 )
      {
        v20->checkCount = v19;
        numPolytopePlanes = stats->numPolytopePlanes;
        ++stats->numPolytopes;
        stats->numPolytopePlanes = v20->numPlanes + numPolytopePlanes;
        v22 = buildModel->checkCount;
        v23 = &buildModel->materials.list[v20->material];
        if ( v23->checkCount != v22 )
        {
          v23->checkCount = v22;
          ++stats->numMaterials;
        }
      }
    }
    if ( buildNode->planeType == -1 )
      break;
    idCollisionModelBuilder::CreateStatsForSubTree_r(buildModel, buildNode: buildNode->children[0], stats);
    buildNode = buildNode->children[1];
  }
}


// ========================================================================
// ?TestBoundsRange@idCollisionModelBuilder@@CA_NPBDABVidBounds@@@Z
// EA  : 0x825C6738
// RVA : 0x005C6738
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::TestBoundsRange(const char *modelName, const idBounds *bounds)
{
  int v2; // r10
  const idBounds *i; // r11

  v2 = 0;
  for ( i = bounds; i->b[0].x >= -32768.0 && i->b[1].x <= 32767.0; i = (const idBounds *)((char *)i + 4) )
  {
    if ( ++v2 >= 3 )
      return 0;
  }
  idLib::Warning(
    fmt: "model '%s' [%1.0f, %1.0f, %1.0f] - [%1.0f, %1.0f, %1.0f] out of range [%d, %d, %d] - [%d %d %d]",
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(bounds->b[0].x)),
    (unsigned int)COERCE_UNSIGNED_INT64(bounds->b[0].x),
    (unsigned int)COERCE_UNSIGNED_INT64(bounds->b[0].y),
    (unsigned int)COERCE_UNSIGNED_INT64(bounds->b[0].z),
    (unsigned int)COERCE_UNSIGNED_INT64(bounds->b[1].x),
    (unsigned int)COERCE_UNSIGNED_INT64(bounds->b[1].y),
    (unsigned int)COERCE_UNSIGNED_INT64(bounds->b[1].z));
  return 1;
}


// ========================================================================
// ?AddBuildNodePrimitivesToSubModelNode@idCollisionModelBuilder@@CAXPBUcm_buildModel_t@@PAUcm_buildNode_t@@AAUcm_subModelPtrs_t@@AAUcm_subModelData_t@@AAUcm_node_t@@@Z
// EA  : 0x825C6830
// RVA : 0x005C6830
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::AddBuildNodePrimitivesToSubModelNode(
        const cm_buildModel_t *buildModel,
        cm_buildNode_t *buildNode,
        cm_subModelPtrs_t *subModelPtrs,
        cm_subModelData_t *counts,
        cm_node_t *node)
{
  cm_buildPolygonRef_t *polygons; // r20
  int *p_checkCount; // r25
  unsigned __int8 *p_numPolytopes; // r16
  unsigned __int16 *p_firstPrimitive; // r22
  unsigned __int16 **p_primitiveIndices; // r21
  unsigned __int8 *p_numPolygons; // r23
  cm_buildPolygon_t *v14; // r28
  int material; // r11
  cm_buildMaterial_t *v16; // r11
  int numMaterials; // r10
  int v18; // r29
  cm_material_t *v19; // r10
  int v24; // r29
  int v30; // r27
  cm_buildEdge_t *v31; // r11
  cm_buildVertex_t *v32; // r10
  int numVertices; // r9
  cm_vertex_t *vertices; // r31
  cm_vertex_t *v35; // r9
  cm_buildVertex_t *v36; // r10
  int v37; // r9
  cm_vertex_t *v38; // r8
  cm_vertex_t *v39; // r9
  int numEdges; // r10
  cm_edge_t *edges; // r9
  cm_edge_t *v42; // r10
  int index; // r10
  __int16 v44; // r10
  unsigned __int16 v45; // r10
  int v46; // r8
  int v47; // r11
  int v48; // ctr
  int v49; // r10
  cm_buildPolytopeRef_t *polytopes; // r27
  int *v51; // r28
  unsigned __int8 *v52; // r24
  unsigned __int16 *v53; // r23
  unsigned __int8 *v54; // r26
  int v56; // r10
  _DWORD *contentFlags; // r8
  cm_buildMaterial_t *v58; // r10
  int v59; // r9
  cm_material_t *materials; // r8
  cm_material_t *v61; // r9
  int v62; // r9
  int numPolytopes; // r10
  cm_polytope_t *v69; // r7
  idPlane *v71; // r31
  int v72; // r7
  idPlane *v73; // r30

  polygons = buildNode->polygons;
  _R19 = 8;
  _R15 = idBoundsShort::vector_int_zero;
  if ( polygons != nullptr )
  {
    p_checkCount = &buildModel->checkCount;
    p_numPolytopes = &node->numPolytopes;
    p_firstPrimitive = &node->firstPrimitive;
    p_primitiveIndices = &subModelPtrs->primitiveIndices;
    p_numPolygons = &node->numPolygons;
    do
    {
      v14 = &buildModel->polygons[polygons->polygonNum];
      if ( v14->checkCount != *p_checkCount )
      {
        material = v14->material;
        v14->checkCount = *p_checkCount;
        v16 = &buildModel->materials.list[material];
        if ( v16->checkCount != *p_checkCount )
        {
          v16->checkCount = *p_checkCount;
          v16->index = counts->numMaterials;
          numMaterials = counts->numMaterials;
          v18 = numMaterials + 1;
          v19 = &subModelPtrs->materials[numMaterials];
          counts->numMaterials = v18;
          v19->contentFlags = v16->contentFlags;
          v19->surfaceFlags = v16->surfaceFlags;
          v19->surfaceType = v16->surfaceType;
          v19->surfaceColor[2] = -1;
          v19->surfaceColor[1] = -1;
          v19->surfaceColor[0] = -1;
        }
        _R11 = &v14->bounds;
        _R26 = 24;
        _R14 = idBoundsShort::vector_int_max_ushort;
        _R30 = 16;
        __asm { vspltisw128 v61, 0 }
        v24 = 0;
        v14->index = counts->numPolygons;
        _R10 = counts->numPolygons;
        _R9 = subModelPtrs->polygons;
        counts->numPolygons = _R10 + 1;
        _R10 *= 16;
        __asm
        {
          lvrx128   v60, r26, r11
          lvlx128   v57, r19, r11
        }
        _R27 = &idBoundsShort::vector_float_max_ushort;
        __asm { lvlx128   v58, r0, r11 }
        __asm { lvx128    v0, r0, r14 }
        __asm { lvrx128   v59, r30, r11 }
        _R30 = (char *)_R9 + _R10;
        __asm
        {
          vor128    v56, v89, v60
          lvx128    v63, r0, r27
          vor128    v54, v90, v59
        }
        _R27 = 4;
        __asm
        {
          lvx128    v62, r0, r15
          vsldoi128 v55, v88, v61, 4
          vrlimi128 v54, v61, 1, 0
          vsubfp128 v53, v87, v63
          vaddfp128 v52, v86, v63
          vcfpsxws128 v13, v53, 0
          vcfpsxws128 v12, v52, 0
          vaddsws   v11, v13, v0
          vpkswss128 v51, v11, v62
          vsldoi128 v50, v93, v51, 0xA
          vsubsws   v10, v12, v0
          vpkswss128 v49, v10, v62
          vor128    v48, v81, v50
          vspltw128 v47, v48, 0
          vspltw128 v46, v48, 1
          vspltw128 v45, v48, 2
          stvewx128 v47, r9, r10
          stvewx128 v46, r30, r27
          stvewx128 v45, r30, r19
        }
        _R30[12] = buildModel->materials.list[v14->material].index;
        *((_WORD *)_R30 + 7) = counts->numPolygonEdges;
        _R30[13] = v14->numEdges;
        if ( v14->numEdges > 0 )
        {
          do
          {
            v30 = buildModel->polygonEdges[v14->firstEdge + v24];
            v31 = &buildModel->edges[abs32(v30)];
            if ( v31->checkCount != *p_checkCount )
            {
              v31->checkCount = *p_checkCount;
              v32 = &buildModel->vertices[v31->vertexNum[0]];
              if ( v32->checkCount != *p_checkCount )
              {
                v32->checkCount = *p_checkCount;
                v32->index = counts->numVertices;
                numVertices = counts->numVertices;
                vertices = subModelPtrs->vertices;
                counts->numVertices = numVertices + 1;
                vertices[numVertices].p.x = v32->p.x;
                v35 = &vertices[numVertices];
                v35->p.y = v32->p.y;
                v35->p.z = v32->p.z;
                v35->st[0] = v32->st[0];
                v35->st[1] = v32->st[1];
              }
              v36 = &buildModel->vertices[v31->vertexNum[1]];
              if ( v36->checkCount != *p_checkCount )
              {
                v36->checkCount = *p_checkCount;
                v36->index = counts->numVertices;
                v37 = counts->numVertices;
                v38 = subModelPtrs->vertices;
                counts->numVertices = v37 + 1;
                v39 = &v38[v37];
                v39->p.x = v36->p.x;
                v39->p.y = v36->p.y;
                v39->p.z = v36->p.z;
                v39->st[0] = v36->st[0];
                v39->st[1] = v36->st[1];
              }
              v31->index = counts->numEdges;
              numEdges = counts->numEdges;
              edges = subModelPtrs->edges;
              counts->numEdges = numEdges + 1;
              v42 = &edges[numEdges];
              v42->vertexNum[0] = buildModel->vertices[v31->vertexNum[0]].index;
              v42->vertexNum[1] = buildModel->vertices[v31->vertexNum[1]].index;
            }
            index = v31->index;
            if ( v30 <= 0 )
              v44 = index | 0x8000;
            else
              v44 = index & 0x7FFF;
            if ( v31->internal != 0 )
              v45 = v44 | 0x4000;
            else
              v45 = v44 & 0xBFFF;
            v46 = *((unsigned __int16 *)_R30 + 7) + v24++;
            subModelPtrs->polygonEdges[v46] = v45;
            ++counts->numPolygonEdges;
          }
          while ( v24 < v14->numEdges );
        }
      }
      v47 = *p_numPolytopes;
      if ( *p_numPolytopes != 0 )
      {
        v48 = *p_numPolytopes;
        do
        {
          v49 = *p_numPolygons + *p_firstPrimitive + v47--;
          (*p_primitiveIndices)[v49] = (*p_primitiveIndices)[v49 - 1];
          --v48;
        }
        while ( v48 != 0 );
      }
      (*p_primitiveIndices)[(*p_numPolygons)++ + *p_firstPrimitive] = v14->index;
      ++counts->numPrimitiveIndices;
      polygons = polygons->next;
    }
    while ( polygons != nullptr );
  }
  polytopes = buildNode->polytopes;
  if ( polytopes != nullptr )
  {
    v51 = &buildModel->checkCount;
    v52 = &node->numPolygons;
    v53 = &node->firstPrimitive;
    v54 = &node->numPolytopes;
    do
    {
      _R11 = &buildModel->polytopes[polytopes->polytopeNum];
      if ( _R11->checkCount != *v51 )
      {
        v56 = _R11->material;
        _R11->checkCount = *v51;
        contentFlags = (_DWORD *)*v51;
        v58 = &buildModel->materials.list[v56];
        if ( v58->checkCount != *v51 )
        {
          v58->checkCount = (int)contentFlags;
          v58->index = counts->numMaterials;
          v59 = counts->numMaterials;
          materials = subModelPtrs->materials;
          counts->numMaterials = v59 + 1;
          v61 = &materials[v59];
          contentFlags = (_DWORD *)v58->contentFlags;
          v61->contentFlags = v58->contentFlags;
          v61->surfaceFlags = v58->surfaceFlags;
          v61->surfaceType = v58->surfaceType;
          v61->surfaceColor[2] = -1;
          v61->surfaceColor[1] = -1;
          v61->surfaceColor[0] = -1;
        }
        v62 = 0;
        _R16 = idBoundsShort::vector_int_max_ushort;
        _R30 = 24;
        _R20 = 16;
        __asm { vspltisw128 v44, 0 }
        _R18 = &idBoundsShort::vector_float_max_ushort;
        _R17 = 4;
        _R11->index = counts->numPolytopes;
        numPolytopes = counts->numPolytopes;
        v69 = subModelPtrs->polytopes;
        counts->numPolytopes = numPolytopes + 1;
        _R10 = &v69[numPolytopes];
        __asm
        {
          lvx128    v0, r0, r16
          lvlx128   v43, r19, r11
          lvrx128   v42, r30, r11
          vor128    v37, v75, v42
          lvlx128   v41, r0, r11
          lvrx128   v40, r20, r11
          vor128    v39, v73, v40
          lvx128    v63, r0, r18
          lvx128    v62, r0, r15
          vsldoi128 v36, v69, v44, 4
          vrlimi128 v39, v44, 1, 0
          vsubfp128 v35, v68, v63
          vaddfp128 v38, v71, v63
          vcfpsxws128 v11, v35, 0
          vcfpsxws128 v13, v38, 0
          vaddsws   v10, v11, v0
          vpkswss128 v33, v10, v62
          vsldoi128 v32, v76, v33, 0xA
          vsubsws   v12, v13, v0
          vpkswss128 v34, v12, v62
          vor128    v63, v66, v32
          vspltw128 v62, v63, 0
          vspltw128 v61, v63, 1
          vspltw128 v60, v63, 2
          stvewx128 v62, r0, r10
          stvewx128 v61, r10, r17
          stvewx128 v60, r10, r19
        }
        _R10->material = buildModel->materials.list[_R11->material].index;
        _R10->firstPlane = counts->numPolytopePlanes;
        _R10->numPlanes = _R11->numPlanes;
        if ( _R11->numPlanes > 0 )
        {
          do
          {
            v71 = &buildModel->polytopePlanes[v62 + _R11->firstPlane];
            v72 = _R10->firstPlane + v62++;
            v73 = &subModelPtrs->polytopePlanes[v72];
            v73->a = v71->a;
            v73->b = v71->b;
            v73->c = v71->c;
            v73->d = v71->d;
          }
          while ( v62 < *contentFlags );
        }
        counts->numPolytopePlanes += *contentFlags;
      }
      subModelPtrs->primitiveIndices[*v52 + *v53 + (*v54)++] = _R11->index;
      ++counts->numPrimitiveIndices;
      polytopes = polytopes->next;
    }
    while ( polytopes != nullptr );
  }
}


// ========================================================================
// ?CreateSingleSubModel_r@idCollisionModelBuilder@@CAXPBUcm_buildModel_t@@PAUcm_buildNode_t@@AAUcm_subModelPtrs_t@@AAUcm_subModelData_t@@PAUcm_node_t@@@Z
// EA  : 0x825C6F28
// RVA : 0x005C6F28
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::CreateSingleSubModel_r(
        const cm_buildModel_t *buildModel,
        cm_buildNode_t *buildNode,
        cm_subModelPtrs_t *subModelPtrs,
        cm_subModelData_t *counts,
        cm_node_t *parent)
{
  int numNodes; // r11
  cm_node_t *v11; // r31
  cm_buildNode_t *i; // r28
  cm_subModelData_t *v13; // r6
  cm_subModelPtrs_t *v14; // r5
  const cm_buildModel_t *v15; // r3

  while ( 1 )
  {
    numNodes = counts->numNodes;
    v11 = &subModelPtrs->nodes[numNodes];
    counts->numNodes = numNodes + 1;
    v11->planeType = buildNode->planeType;
    v11->planeDist = buildNode->planeDist;
    v11->children[0] = 0;
    v11->children[1] = 0;
    v11->firstPrimitive = counts->numPrimitiveIndices;
    v11->numPolygons = 0;
    v11->numPolytopes = 0;
    if ( parent != nullptr )
    {
      parent->children[(_cntlzw((char *)buildNode - (char *)buildNode->parent->children[1]) & 0x20) != 0] = counts->numNodes - 1;
    }
    else
    {
      for ( i = buildNode->parent; i != nullptr; i = i->parent )
        idCollisionModelBuilder::AddBuildNodePrimitivesToSubModelNode(
          buildModel,
          buildNode: i,
          subModelPtrs,
          counts,
          node: v11);
    }
    idCollisionModelBuilder::AddBuildNodePrimitivesToSubModelNode(
      buildModel,
      buildNode,
      subModelPtrs,
      counts,
      node: v11);
    if ( buildNode->planeType == -1 )
      break;
    parent = v11;
    idCollisionModelBuilder::CreateSingleSubModel_r(
      buildModel: v15,
      buildNode: buildNode->children[0],
      subModelPtrs: v14,
      counts: v13,
      parent: v11);
    buildNode = buildNode->children[1];
  }
}


// ========================================================================
// ?CountModelTreeNodes_r@idCollisionModelBuilder@@CAHPAVidCollisionModelLocal@@HAAVidBounds@@@Z
// EA  : 0x825C7040
// RVA : 0x005C7040
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::CountModelTreeNodes_r(
        idCollisionModelLocal *model,
        int nodeNum,
        idBounds *bounds)
{
  cm_subModel_t *subModels; // r10
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v10; // fp10
  cm_subModel_t *v11; // r11
  double v12; // fp9
  cm_modelTreeNode_t *v25; // r29
  int v26; // r28

  if ( nodeNum >= 0 )
  {
    v25 = &model->polygonModel.modelTreeNodes[nodeNum];
    if ( v25->planeType == -1 )
    {
      return 1;
    }
    else
    {
      v26 = idCollisionModelBuilder::CountModelTreeNodes_r(model, nodeNum: v25->children[1], bounds);
      return v26 + idCollisionModelBuilder::CountModelTreeNodes_r(model, nodeNum: v25->children[0], bounds) + 1;
    }
  }
  else
  {
    subModels = model->polygonModel.subModels;
    y = bounds->b[0].y;
    z = bounds->b[0].z;
    x = bounds->b[1].x;
    v10 = bounds->b[1].y;
    v11 = &subModels[-nodeNum];
    v12 = bounds->b[1].z;
    _FP7 = (float)(bounds->b[0].x - v11[-1].header.bounds.b[0].x);
    __asm { fsel      f6, f7, f8, f0 }
    bounds->b[0].x = _FP6;
    _FP4 = (float)((float)y - v11[-1].header.bounds.b[0].y);
    __asm { fsel      f3, f4, f5, f13 }
    bounds->b[0].y = _FP3;
    _FP1 = (float)((float)z - v11[-1].header.bounds.b[0].z);
    __asm { fsel      f0, f1, f2, f12 }
    bounds->b[0].z = _FP0;
    _FP12 = (float)(v11[-1].header.bounds.b[1].x - (float)x);
    __asm { fsel      f11, f12, f13, f11 }
    bounds->b[1].x = _FP11;
    _FP7 = (float)(v11[-1].header.bounds.b[1].y - (float)v10);
    __asm { fsel      f6, f7, f8, f10 }
    bounds->b[1].y = _FP6;
    _FP4 = (float)(v11[-1].header.bounds.b[1].z - (float)v12);
    __asm { fsel      f3, f4, f5, f9 }
    bounds->b[1].z = _FP3;
    return 0;
  }
}


// ========================================================================
// ?AddMapModelEstimates@idCollisionModelBuilder@@CAXABVidStaticModelGeometry@1@HHAAH11AAVidBounds@@@Z
// EA  : 0x825C7738
// RVA : 0x005C7738
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::AddMapModelEstimates(
        const idCollisionModelBuilder::idStaticModelGeometry *modelGeom,
        int groupNum,
        int primitiveNum,
        int *numVerts,
        int *numEdges,
        int *numPolys,
        idBounds *bounds)
{
  int v13; // r17
  int v14; // r16
  idMapPrimitive *JobNote; // r3
  D3DXShader::CTErrors *v16; // r28
  idPlane *v17; // r21
  int v18; // r26
  float *p_c; // r29
  idMapBrushSide *LocalUserByIndex; // r3
  const idPlane *Plane; // r3
  double y; // fp7
  double z; // fp6
  double v24; // fp5
  double v25; // fp0
  double v26; // fp10
  double v27; // fp3
  double v28; // fp1
  int v29; // r3
  float *v30; // r3
  double v32; // fp13
  double v33; // fp12
  double x; // fp11
  double v35; // fp8
  double v36; // fp7
  int v48; // r11
  int v49; // r10
  int type; // [sp+50h] [-100h]
  unsigned int NumLocalUsers; // [sp+5Ch] [-F4h]
  idBounds v64; // [sp+60h] [-F0h] BYREF
  idBounds v65[2]; // [sp+80h] [-D0h] BYREF

  v13 = 0;
  if ( (int)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)modelGeom->mapModel) > 0 )
  {
    v14 = 0;
    do
    {
      if ( modelGeom->primitiveGroupNumbers.list[v14] == groupNum )
      {
        JobNote = idJob::GetJobNote(this: (idMapModel *)modelGeom->mapModel, i: v13);
        v16 = (D3DXShader::CTErrors *)JobNote;
        type = JobNote->type;
        if ( type != 0 )
        {
          if ( type == 1 )
          {
            v48 = *(_DWORD *)&JobNote[3].groupList.granularity;
            v49 = JobNote[3].type;
            *numVerts += v49 * v48;
            *numEdges += (v48 - 1) * v49 + (v49 - 1) * v48 + (v48 - 1) * (v49 - 1);
            *numPolys += v49 * v48;
            idSurface::GetBounds(this: (idSurface *)&JobNote[1], bounds: &v64);
            _FP2 = (float)(bounds->b[0].x - v64.b[0].x);
            _FP1 = (float)(bounds->b[0].y - v64.b[0].y);
            _FP31 = (float)(bounds->b[0].z - v64.b[0].z);
            _FP30 = (float)(v64.b[1].x - bounds->b[1].x);
            _FP29 = (float)(v64.b[1].y - bounds->b[1].y);
            _FP28 = (float)(v64.b[1].z - bounds->b[1].z);
            __asm { fsel      f0, f2, f0, f8 }
            bounds->b[0].x = _FP0;
            __asm { fsel      f13, f1, f13, f7 }
            bounds->b[0].y = _FP13;
            __asm { fsel      f12, f31, f12, f6 }
            bounds->b[0].z = _FP12;
            __asm { fsel      f11, f30, f11, f5 }
            bounds->b[1].x = _FP11;
            __asm { fsel      f10, f29, f10, f4 }
            bounds->b[1].y = _FP10;
            __asm { fsel      f9, f28, f9, f3 }
            bounds->b[1].z = _FP9;
          }
        }
        else
        {
          *numVerts += 2 * (idSignInManagerXbox::GetNumLocalUsers(this: (D3DXShader::CTErrors *)JobNote) - 2);
          *numEdges += 3 * (idSignInManagerXbox::GetNumLocalUsers(this: v16) - 2);
          *numPolys += idSignInManagerXbox::GetNumLocalUsers(this: v16);
          NumLocalUsers = idSignInManagerXbox::GetNumLocalUsers(this: v16);
          v17 = (idPlane *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                             size: 16 * NumLocalUsers,
                             tag: TAG_TEMP,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
          v18 = 0;
          if ( (int)idSignInManagerXbox::GetNumLocalUsers(this: v16) > 0 )
          {
            p_c = &v17->c;
            do
            {
              LocalUserByIndex = idSignInManagerXbox::GetLocalUserByIndex(this: (idMapBrush *)v16, i: v18);
              Plane = idMapBrushSide::GetPlane(this: LocalUserByIndex);
              ++v18;
              *(p_c - 2) = Plane->a;
              *(p_c - 1) = Plane->b;
              *p_c = Plane->c;
              p_c[1] = Plane->d;
              y = modelGeom->axis.mat[1].y;
              z = modelGeom->axis.mat[1].z;
              v24 = *(p_c - 1);
              v25 = p_c[1];
              v26 = (float)((float)(*p_c * modelGeom->axis.mat[2].y) + (float)(modelGeom->axis.mat[0].y * *(p_c - 2)));
              v27 = (float)((float)(*p_c * modelGeom->axis.mat[2].z) + (float)(modelGeom->axis.mat[0].z * *(p_c - 2)));
              v28 = (float)((float)(*(p_c - 1) * modelGeom->axis.mat[1].x)
                          + (float)((float)(modelGeom->axis.mat[0].x * *(p_c - 2))
                                  + (float)(*p_c * modelGeom->axis.mat[2].x)));
              *(p_c - 2) = (float)(*(p_c - 1) * modelGeom->axis.mat[1].x)
                         + (float)((float)(modelGeom->axis.mat[0].x * *(p_c - 2))
                                 + (float)(*p_c * modelGeom->axis.mat[2].x));
              *(p_c - 1) = (float)((float)y * (float)v24) + (float)v26;
              *p_c = (float)((float)v24 * (float)z) + (float)v27;
              p_c[1] = (float)v25
                     - (float)((float)((float)v28 * modelGeom->origin.x)
                             + (float)((float)((float)((float)((float)v24 * (float)z) + (float)v27) * modelGeom->origin.z)
                                     + (float)((float)((float)((float)y * (float)v24) + (float)v26) * modelGeom->origin.y)));
              p_c += 4;
            }
            while ( v18 < (int)idSignInManagerXbox::GetNumLocalUsers(this: v16) );
          }
          v29 = idSignInManagerXbox::GetNumLocalUsers(this: v16);
          v30 = (float *)idPlane::ConvexPolytopeBounds(result: v65, planes: v17, numPlanes: v29);
          _FP9 = (float)(bounds->b[0].x - *v30);
          v32 = bounds->b[0].y;
          v33 = bounds->b[0].z;
          x = bounds->b[1].x;
          v35 = bounds->b[1].y;
          v36 = bounds->b[1].z;
          __asm { fsel      f6, f9, f10, f0 }
          bounds->b[0].x = _FP6;
          _FP4 = (float)((float)v32 - v30[1]);
          __asm { fsel      f3, f4, f5, f13 }
          bounds->b[0].y = _FP3;
          _FP1 = (float)((float)v33 - v30[2]);
          __asm { fsel      f0, f1, f2, f12 }
          bounds->b[0].z = _FP0;
          _FP12 = (float)(v30[3] - (float)x);
          __asm { fsel      f11, f12, f13, f11 }
          bounds->b[1].x = _FP11;
          _FP9 = (float)(v30[4] - (float)v35);
          __asm { fsel      f8, f9, f10, f8 }
          bounds->b[1].y = _FP8;
          _FP5 = (float)(v30[5] - (float)v36);
          __asm { fsel      f4, f5, f6, f7 }
          bounds->b[1].z = _FP4;
          if ( v17 != nullptr )
            idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
        }
      }
      ++v13;
      ++v14;
    }
    while ( v13 < (int)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)modelGeom->mapModel) );
  }
}


// ========================================================================
// __unwind$238713
// EA  : 0x825C7AE8
// RVA : 0x005C7AE8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_238713()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 336 + 88));
}


// ========================================================================
// ?AddRenderModelEstimates@idCollisionModelBuilder@@CAXABVidStaticModelGeometry@1@HHAAH11AAVidBounds@@@Z
// EA  : 0x825C7B10
// RVA : 0x005C7B10
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::AddRenderModelEstimates(
        const idCollisionModelBuilder::idStaticModelGeometry *modelGeom,
        int groupNum,
        int primitiveNum,
        int *numVerts,
        int *numEdges,
        int *numPolys,
        idBounds *bounds)
{
  const idStaticModel *staticModel; // r11
  int v14; // r24
  int v15; // r30
  int v16; // r25
  idStaticModelSurface *v17; // r11
  int *v18; // r7
  int v19; // ctr
  bool *p_modelIsAutosprite; // r11
  double z; // fp9
  const idRenderModel *renderModel; // r11
  int v35; // r22
  int v36; // r25
  int v37; // r24
  idRenderModelSurface *v38; // r30
  idTriangles *geometry; // r11
  char *verts; // r3
  idTriangles *v42; // r7
  int v44; // r10
  int v47; // r9
  float *v50; // r11
  double v84; // fp25
  double v85; // fp23
  double v86; // fp26
  double v88; // fp24
  double v91; // fp28
  double v92; // fp29
  double v93; // fp26
  float *v100; // r11
  int v101; // ctr
  double v102; // fp26
  double v103; // fp25
  double v104; // fp24
  double v105; // fp23
  double v106; // fp8
  double v107; // fp26
  double v108; // fp25
  double v109; // fp8
  idBounds v128; // [sp+60h] [-130h] BYREF
  int v129; // [sp+7Ch] [-114h] BYREF
  idBounds v130[7]; // [sp+80h] [-110h] BYREF

  staticModel = modelGeom->staticModel;
  if ( modelGeom->staticModel != nullptr )
  {
    v14 = 0;
    if ( staticModel->surfaces.num > 0 )
    {
      v15 = 0;
      v16 = 0;
      do
      {
        if ( modelGeom->primitiveGroupNumbers.list[v16] == groupNum )
        {
          v17 = &staticModel->surfaces.list[v15];
          v18 = &v129;
          v19 = 6;
          *numVerts += v17->geometry->numVerts;
          *numEdges += v17->geometry->numIndexes / 2;
          *numPolys += v17->geometry->numIndexes / 3;
          p_modelIsAutosprite = &modelGeom->staticModel->modelIsAutosprite;
          do
          {
            p_modelIsAutosprite += 4;
            *++v18 = *(_DWORD *)p_modelIsAutosprite;
            --v19;
          }
          while ( v19 != 0 );
          idBounds::FromTransformedBounds(this: &v128, bounds: v130, origin: &modelGeom->origin, axis: &modelGeom->axis);
          _FP6 = (float)(bounds->b[0].x - v128.b[0].x);
          _FP4 = (float)(bounds->b[0].y - v128.b[0].y);
          _FP2 = (float)(bounds->b[0].z - v128.b[0].z);
          _FP31 = (float)(v128.b[1].x - bounds->b[1].x);
          z = v128.b[1].z;
          _FP29 = (float)(v128.b[1].y - bounds->b[1].y);
          __asm { fsel      f0, f6, f0, f8 }
          bounds->b[0].x = _FP0;
          __asm { fsel      f13, f4, f13, f7 }
          bounds->b[0].y = _FP13;
          __asm { fsel      f12, f2, f12, f5 }
          bounds->b[0].z = _FP12;
          __asm { fsel      f11, f31, f11, f3 }
          bounds->b[1].x = _FP11;
          __asm { fsel      f10, f29, f10, f1 }
          _FP28 = (float)((float)z - bounds->b[1].z);
          bounds->b[1].y = _FP10;
          __asm { fsel      f9, f28, f9, f30 }
          bounds->b[1].z = _FP9;
        }
        staticModel = modelGeom->staticModel;
        ++v14;
        ++v16;
        ++v15;
      }
      while ( v14 < modelGeom->staticModel->surfaces.num );
    }
  }
  else
  {
    renderModel = modelGeom->renderModel;
    v35 = 0;
    if ( renderModel->surfaces.num > 0 )
    {
      v36 = 0;
      v37 = 0;
      do
      {
        if ( modelGeom->primitiveGroupNumbers.list[v37] == groupNum )
        {
          v38 = &renderModel->surfaces.list[v36];
          *numVerts += v38->geometry->numVerts;
          *numEdges += v38->geometry->numIndexes / 2;
          *numPolys += v38->geometry->numIndexes / 3;
          geometry = v38->geometry;
          verts = (char *)geometry->verts;
          if ( verts == nullptr )
            verts = (char *)idVertexBuffer::MapBuffer(this: &geometry->vertexBuffer, mapType: BM_READ);
          _FP0 = 1.0e30;
          v42 = v38->geometry;
          _FP11 = -1.0e30;
          v44 = 0;
          _FP12 = 1.0e30;
          _FP13 = 1.0e30;
          v47 = v42->numVerts;
          _FP9 = -1.0e30;
          _FP10 = -1.0e30;
          if ( v47 >= 4 )
          {
            v50 = (float *)(verts - 32);
            do
            {
              _FP18 = (float)((float)_FP0
                            - (float)(modelGeom->origin.x
                                    + (float)((float)(v50[10] * modelGeom->axis.mat[2].x)
                                            + (float)((float)(v50[8] * modelGeom->axis.mat[0].x)
                                                    + (float)(v50[9] * modelGeom->axis.mat[1].x)))));
              _FP17 = (float)((float)_FP13
                            - (float)(modelGeom->origin.y
                                    + (float)((float)(v50[10] * modelGeom->axis.mat[2].y)
                                            + (float)((float)(v50[8] * modelGeom->axis.mat[0].y)
                                                    + (float)(v50[9] * modelGeom->axis.mat[1].y)))));
              _FP16 = (float)((float)_FP12
                            - (float)(modelGeom->origin.z
                                    + (float)((float)(v50[10] * modelGeom->axis.mat[2].z)
                                            + (float)((float)(v50[8] * modelGeom->axis.mat[0].z)
                                                    + (float)(v50[9] * modelGeom->axis.mat[1].z)))));
              _FP15 = (float)((float)(modelGeom->origin.x
                                    + (float)((float)(v50[10] * modelGeom->axis.mat[2].x)
                                            + (float)((float)(v50[8] * modelGeom->axis.mat[0].x)
                                                    + (float)(v50[9] * modelGeom->axis.mat[1].x))))
                            - (float)_FP11);
              _FP14 = (float)((float)(modelGeom->origin.y
                                    + (float)((float)(v50[10] * modelGeom->axis.mat[2].y)
                                            + (float)((float)(v50[8] * modelGeom->axis.mat[0].y)
                                                    + (float)(v50[9] * modelGeom->axis.mat[1].y))))
                            - (float)_FP10);
              _FP29 = (float)((float)(modelGeom->origin.z
                                    + (float)((float)(v50[10] * modelGeom->axis.mat[2].z)
                                            + (float)((float)(v50[8] * modelGeom->axis.mat[0].z)
                                                    + (float)(v50[9] * modelGeom->axis.mat[1].z))))
                            - (float)_FP9);
              __asm
              {
                fsel      f0, f18, f27, f0
                fsel      f13, f17, f25, f13
                fsel      f12, f16, f26, f12
                fsel      f11, f15, f27, f11
                fsel      f10, f14, f25, f10
                fsel      f9, f29, f26, f9
              }
              _FP27 = (float)((float)_FP0
                            - (float)(modelGeom->origin.x
                                    + (float)((float)(v50[18] * modelGeom->axis.mat[2].x)
                                            + (float)((float)(v50[17] * modelGeom->axis.mat[1].x)
                                                    + (float)(v50[16] * modelGeom->axis.mat[0].x)))));
              _FP26 = (float)((float)_FP13
                            - (float)(modelGeom->origin.y
                                    + (float)((float)(v50[17] * modelGeom->axis.mat[1].y)
                                            + (float)((float)(v50[16] * modelGeom->axis.mat[0].y)
                                                    + (float)(v50[18] * modelGeom->axis.mat[2].y)))));
              _FP25 = (float)((float)_FP12
                            - (float)(modelGeom->origin.z
                                    + (float)((float)(v50[17] * modelGeom->axis.mat[1].z)
                                            + (float)((float)(v50[16] * modelGeom->axis.mat[0].z)
                                                    + (float)(v50[18] * modelGeom->axis.mat[2].z)))));
              _FP21 = (float)((float)(modelGeom->origin.x
                                    + (float)((float)(v50[18] * modelGeom->axis.mat[2].x)
                                            + (float)((float)(v50[17] * modelGeom->axis.mat[1].x)
                                                    + (float)(v50[16] * modelGeom->axis.mat[0].x))))
                            - (float)_FP11);
              _FP18 = (float)((float)(modelGeom->origin.y
                                    + (float)((float)(v50[17] * modelGeom->axis.mat[1].y)
                                            + (float)((float)(v50[16] * modelGeom->axis.mat[0].y)
                                                    + (float)(v50[18] * modelGeom->axis.mat[2].y))))
                            - (float)_FP10);
              _FP17 = (float)((float)(modelGeom->origin.z
                                    + (float)((float)(v50[17] * modelGeom->axis.mat[1].z)
                                            + (float)((float)(v50[16] * modelGeom->axis.mat[0].z)
                                                    + (float)(v50[18] * modelGeom->axis.mat[2].z))))
                            - (float)_FP9);
              __asm
              {
                fsel      f0, f27, f23, f0
                fsel      f13, f26, f24, f13
                fsel      f12, f25, f22, f12
                fsel      f11, f21, f23, f11
                fsel      f10, f18, f24, f10
                fsel      f9, f17, f22, f9
              }
              _FP27 = (float)((float)_FP0
                            - (float)(modelGeom->origin.x
                                    + (float)((float)(v50[26] * modelGeom->axis.mat[2].x)
                                            + (float)((float)(v50[24] * modelGeom->axis.mat[0].x)
                                                    + (float)(v50[25] * modelGeom->axis.mat[1].x)))));
              _FP26 = (float)((float)_FP13
                            - (float)(modelGeom->origin.y
                                    + (float)((float)(v50[26] * modelGeom->axis.mat[2].y)
                                            + (float)((float)(v50[24] * modelGeom->axis.mat[0].y)
                                                    + (float)(v50[25] * modelGeom->axis.mat[1].y)))));
              _FP25 = (float)((float)_FP12
                            - (float)(modelGeom->origin.z
                                    + (float)((float)(v50[26] * modelGeom->axis.mat[2].z)
                                            + (float)((float)(v50[24] * modelGeom->axis.mat[0].z)
                                                    + (float)(v50[25] * modelGeom->axis.mat[1].z)))));
              _FP24 = (float)((float)(modelGeom->origin.x
                                    + (float)((float)(v50[26] * modelGeom->axis.mat[2].x)
                                            + (float)((float)(v50[24] * modelGeom->axis.mat[0].x)
                                                    + (float)(v50[25] * modelGeom->axis.mat[1].x))))
                            - (float)_FP11);
              _FP23 = (float)((float)(modelGeom->origin.y
                                    + (float)((float)(v50[26] * modelGeom->axis.mat[2].y)
                                            + (float)((float)(v50[24] * modelGeom->axis.mat[0].y)
                                                    + (float)(v50[25] * modelGeom->axis.mat[1].y))))
                            - (float)_FP10);
              __asm { fsel      f13, f26, f19, f13 }
              __asm { fsel      f12, f25, f28, f12 }
              _FP22 = (float)((float)(modelGeom->origin.z
                                    + (float)((float)(v50[26] * modelGeom->axis.mat[2].z)
                                            + (float)((float)(v50[24] * modelGeom->axis.mat[0].z)
                                                    + (float)(v50[25] * modelGeom->axis.mat[1].z))))
                            - (float)_FP9);
              v44 += 4;
              __asm { fsel      f10, f23, f19, f10 }
              v84 = (float)(v50[33] * modelGeom->axis.mat[1].x);
              v85 = (float)(v50[33] * modelGeom->axis.mat[1].y);
              v86 = (float)(v50[33] * modelGeom->axis.mat[1].z);
              __asm { fsel      f11, f24, f20, f11 }
              v88 = v50[34];
              __asm { fsel      f27, f27, f20, f0 }
              v50 += 32;
              __asm { fsel      f9, f22, f28, f9 }
              v91 = (float)(modelGeom->origin.x
                          + (float)((float)((float)v88 * modelGeom->axis.mat[2].x)
                                  + (float)((float)(*v50 * modelGeom->axis.mat[0].x) + (float)v84)));
              v92 = (float)(modelGeom->origin.y
                          + (float)((float)((float)v88 * modelGeom->axis.mat[2].y)
                                  + (float)((float)(*v50 * modelGeom->axis.mat[0].y) + (float)v85)));
              v93 = (float)(modelGeom->origin.z
                          + (float)((float)((float)v88 * modelGeom->axis.mat[2].z)
                                  + (float)((float)(*v50 * modelGeom->axis.mat[0].z) + (float)v86)));
              _FP0 = (float)((float)_FP27
                           - (float)(modelGeom->origin.x
                                   + (float)((float)((float)v88 * modelGeom->axis.mat[2].x)
                                           + (float)((float)(*v50 * modelGeom->axis.mat[0].x) + (float)v84))));
              _FP25 = (float)((float)_FP13
                            - (float)(modelGeom->origin.y
                                    + (float)((float)((float)v88 * modelGeom->axis.mat[2].y)
                                            + (float)((float)(*v50 * modelGeom->axis.mat[0].y) + (float)v85))));
              _FP24 = (float)((float)_FP12 - (float)v93);
              _FP23 = (float)((float)v91 - (float)_FP11);
              _FP22 = (float)((float)v92 - (float)_FP10);
              _FP21 = (float)((float)v93 - (float)_FP9);
              __asm
              {
                fsel      f0, f0, f28, f27
                fsel      f13, f25, f29, f13
                fsel      f12, f24, f26, f12
                fsel      f11, f23, f28, f11
                fsel      f10, f22, f29, f10
                fsel      f9, f21, f26, f9
              }
            }
            while ( v44 < v47 - 3 );
          }
          if ( v44 < v47 )
          {
            v100 = (float *)&verts[32 * v44 - 32];
            v101 = v47 - v44;
            do
            {
              v102 = v100[10];
              v103 = (float)(modelGeom->axis.mat[2].x * v100[10]);
              v104 = v100[9];
              v105 = (float)(modelGeom->axis.mat[2].y * v100[10]);
              v100 += 8;
              v106 = (float)((float)(modelGeom->axis.mat[0].z * *v100) + (float)(modelGeom->axis.mat[2].z * (float)v102));
              v107 = (float)(modelGeom->origin.x
                           + (float)((float)(modelGeom->axis.mat[1].x * (float)v104)
                                   + (float)((float)(modelGeom->axis.mat[0].x * *v100) + (float)v103)));
              v108 = (float)(modelGeom->origin.y
                           + (float)((float)(modelGeom->axis.mat[1].y * (float)v104)
                                   + (float)((float)(modelGeom->axis.mat[0].y * *v100) + (float)v105)));
              v109 = (float)(modelGeom->origin.z + (float)((float)(modelGeom->axis.mat[1].z * (float)v104) + (float)v106));
              _FP23 = (float)((float)_FP13
                            - (float)(modelGeom->origin.y
                                    + (float)((float)(modelGeom->axis.mat[1].y * (float)v104)
                                            + (float)((float)(modelGeom->axis.mat[0].y * *v100) + (float)v105))));
              _FP24 = (float)((float)_FP0 - (float)v107);
              _FP22 = (float)((float)_FP12 - (float)v109);
              _FP21 = (float)((float)v107 - (float)_FP11);
              _FP20 = (float)((float)v108 - (float)_FP10);
              _FP19 = (float)((float)v109 - (float)_FP9);
              __asm
              {
                fsel      f0, f24, f26, f0
                fsel      f13, f23, f25, f13
                fsel      f12, f22, f8, f12
                fsel      f11, f21, f26, f11
                fsel      f10, f20, f25, f10
                fsel      f9, f19, f8, f9
              }
              --v101;
            }
            while ( v101 != 0 );
          }
          _FP7 = (float)(bounds->b[0].x - (float)_FP0);
          _FP4 = (float)((float)_FP9 - bounds->b[1].z);
          _FP31 = (float)((float)_FP11 - bounds->b[1].x);
          _FP2 = (float)(bounds->b[0].y - (float)_FP13);
          _FP29 = (float)((float)_FP10 - bounds->b[1].y);
          _FP28 = (float)(bounds->b[0].z - (float)_FP12);
          __asm { fsel      f0, f7, f0, f8 }
          bounds->b[0].x = _FP0;
          __asm { fsel      f9, f4, f9, f6 }
          bounds->b[1].z = _FP9;
          __asm { fsel      f7, f31, f11, f3 }
          bounds->b[1].x = _FP7;
          __asm { fsel      f8, f2, f13, f5 }
          bounds->b[0].y = _FP8;
          __asm { fsel      f6, f29, f10, f1 }
          bounds->b[1].y = _FP6;
          __asm { fsel      f5, f28, f12, f30 }
          bounds->b[0].z = _FP5;
          if ( verts != (char *)v42->verts )
            idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&v42->vertexBuffer);
        }
        renderModel = modelGeom->renderModel;
        ++v35;
        ++v37;
        ++v36;
      }
      while ( v35 < renderModel->surfaces.num );
    }
  }
}


// ========================================================================
// ?GetMapModelBrushBounds@idCollisionModelBuilder@@CAXABVidStaticModelGeometry@1@HAAVidBounds@@@Z
// EA  : 0x825C80E8
// RVA : 0x005C80E8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::GetMapModelBrushBounds(
        const idCollisionModelBuilder::idStaticModelGeometry *modelGeom,
        int groupNum,
        idBounds *bounds)
{
  int v6; // r21
  int v7; // r20
  D3DXShader::CTErrors *JobNote; // r3
  idMapBrush *v9; // r27
  idPlane *v10; // r25
  int v11; // r28
  float *p_c; // r30
  idMapBrushSide *LocalUserByIndex; // r3
  const idPlane *Plane; // r3
  double v15; // fp7
  double y; // fp5
  double z; // fp4
  double v18; // fp0
  double v19; // fp10
  double v20; // fp9
  double v21; // fp8
  int v22; // r3
  float *v23; // r3
  double v25; // fp13
  double v26; // fp12
  double x; // fp11
  double v28; // fp8
  double v29; // fp7
  unsigned int NumLocalUsers; // [sp+54h] [-9Ch]
  idBounds v42[6]; // [sp+60h] [-90h] BYREF

  v6 = 0;
  if ( (int)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)modelGeom->mapModel) > 0 )
  {
    v7 = 0;
    do
    {
      if ( modelGeom->primitiveGroupNumbers.list[v7] == groupNum )
      {
        JobNote = (D3DXShader::CTErrors *)idJob::GetJobNote(this: (idMapModel *)modelGeom->mapModel, i: v6);
        v9 = (idMapBrush *)JobNote;
        if ( JobNote->m_pErrors == nullptr )
        {
          NumLocalUsers = idSignInManagerXbox::GetNumLocalUsers(this: JobNote);
          v10 = (idPlane *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                             size: 16 * NumLocalUsers,
                             tag: TAG_TEMP,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
          v11 = 0;
          if ( (int)idSignInManagerXbox::GetNumLocalUsers(this: (D3DXShader::CTErrors *)v9) > 0 )
          {
            p_c = &v10->c;
            do
            {
              LocalUserByIndex = idSignInManagerXbox::GetLocalUserByIndex(this: v9, i: v11);
              Plane = idMapBrushSide::GetPlane(this: LocalUserByIndex);
              ++v11;
              *(p_c - 2) = Plane->a;
              *(p_c - 1) = Plane->b;
              *p_c = Plane->c;
              p_c[1] = Plane->d;
              v15 = *p_c;
              y = modelGeom->axis.mat[2].y;
              z = modelGeom->axis.mat[2].z;
              v18 = p_c[1];
              v19 = (float)((float)(*(p_c - 2) * modelGeom->axis.mat[0].y)
                          + (float)(*(p_c - 1) * modelGeom->axis.mat[1].y));
              v20 = (float)((float)(*(p_c - 2) * modelGeom->axis.mat[0].z)
                          + (float)(modelGeom->axis.mat[1].z * *(p_c - 1)));
              v21 = (float)((float)(modelGeom->axis.mat[1].x * *(p_c - 1))
                          + (float)((float)(*p_c * modelGeom->axis.mat[2].x)
                                  + (float)(modelGeom->axis.mat[0].x * *(p_c - 2))));
              *(p_c - 2) = (float)(modelGeom->axis.mat[1].x * *(p_c - 1))
                         + (float)((float)(*p_c * modelGeom->axis.mat[2].x)
                                 + (float)(modelGeom->axis.mat[0].x * *(p_c - 2)));
              *(p_c - 1) = (float)((float)v15 * (float)y) + (float)v19;
              *p_c = (float)((float)z * (float)v15) + (float)v20;
              p_c[1] = (float)v18
                     - (float)((float)((float)v21 * modelGeom->origin.x)
                             + (float)((float)(modelGeom->origin.y * (float)((float)((float)v15 * (float)y) + (float)v19))
                                     + (float)(modelGeom->origin.z * (float)((float)((float)z * (float)v15) + (float)v20))));
              p_c += 4;
            }
            while ( v11 < (int)idSignInManagerXbox::GetNumLocalUsers(this: (D3DXShader::CTErrors *)v9) );
          }
          v22 = idSignInManagerXbox::GetNumLocalUsers(this: (D3DXShader::CTErrors *)v9);
          v23 = (float *)idPlane::ConvexPolytopeBounds(result: v42, planes: v10, numPlanes: v22);
          _FP9 = (float)(bounds->b[0].x - *v23);
          v25 = bounds->b[0].y;
          v26 = bounds->b[0].z;
          x = bounds->b[1].x;
          v28 = bounds->b[1].y;
          v29 = bounds->b[1].z;
          __asm { fsel      f6, f9, f10, f0 }
          bounds->b[0].x = _FP6;
          _FP4 = (float)((float)v25 - v23[1]);
          __asm { fsel      f3, f4, f5, f13 }
          bounds->b[0].y = _FP3;
          _FP1 = (float)((float)v26 - v23[2]);
          __asm { fsel      f0, f1, f2, f12 }
          bounds->b[0].z = _FP0;
          _FP12 = (float)(v23[3] - (float)x);
          __asm { fsel      f11, f12, f13, f11 }
          bounds->b[1].x = _FP11;
          _FP9 = (float)(v23[4] - (float)v28);
          __asm { fsel      f8, f9, f10, f8 }
          bounds->b[1].y = _FP8;
          _FP5 = (float)(v23[5] - (float)v29);
          __asm { fsel      f4, f5, f6, f7 }
          bounds->b[1].z = _FP4;
          if ( v10 != nullptr )
            idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
        }
      }
      ++v6;
      ++v7;
    }
    while ( v6 < (int)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)modelGeom->mapModel) );
  }
}


// ========================================================================
// __unwind$239387
// EA  : 0x825C834C
// RVA : 0x005C834C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_239387()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 240 + 80));
}


// ========================================================================
// ?LoadProcBSP@idCollisionModelBuilder@@CAXPBD@Z
// EA  : 0x825C8380
// RVA : 0x005C8380
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::LoadProcBSP(const char *name)
{
  idLexer *v1; // r30
  idLexer *v2; // r3
  idStr v3; // [sp+60h] [-C0h] BYREF
  idToken v4[2]; // [sp+80h] [-A0h] BYREF

  v1 = nullptr;
  v3.len = 0;
  v3.allocedAndFlag = 20;
  v3.data = v3.baseBuffer;
  v3.baseBuffer[0] = 0;
  v4[0].allocedAndFlag = 20;
  v4[0].len = 0;
  v4[0].data = v4[0].baseBuffer;
  v4[0].baseBuffer[0] = 0;
  v4[0].intvalue = 0;
  v4[0].floatvalue = -3.4028235e38;
  v4[0].whiteSpaceStart_p = nullptr;
  v4[0].whiteSpaceEnd_p = nullptr;
  v4[0].next = nullptr;
  idStr::operator=(this: &v3, text: name);
  idStr::SetFileExtension(this: &v3, extension: "proc");
  v2 = (idLexer *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                    size: 0x88u,
                    tag: TAG_NEW,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v1 = idLexer::idLexer(this: v2, flags_: 80);
  idLexer::LoadFile(this: v1, filename_: v3.data, OSPath: false);
  if ( !v1->loaded )
  {
    idLib::Warning(fmt: "idCollisionModelBuilder::LoadProcBSP: couldn't load %s", v3.data);
    idLexer::~idLexer(this: v1);
    idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
    idStr::FreeData(this: &v4[0]);
    goto LABEL_23;
  }
  if ( !idLexer::ReadToken(this: v1, token: v4) )
  {
    idLib::Warning(fmt: "idCollisionModelBuilder::LoadProcBSP: couldn't read proc file id");
    idLexer::~idLexer(this: v1);
    idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
    idStr::FreeData(this: &v4[0]);
    goto LABEL_23;
  }
  if ( idStr::Icmp(s1: v4[0].data, s2: "mapProcFile006") != 0 && idStr::Icmp(s1: v4[0].data, s2: "mapProcFile005") != 0 )
  {
    idLib::Warning(
      fmt: "idCollisionModelBuilder::LoadProcBSP: bad id '%s' instead of '%s'",
      v4[0].data,
      "mapProcFile006");
    idLexer::~idLexer(this: v1);
    idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
    idStr::FreeData(this: &v4[0]);
    goto LABEL_23;
  }
  if ( idLexer::ReadToken(this: v1, token: v4) )
  {
    while ( idStr::Cmp(s1: v4[0].data, s2: "model") == 0
         || idStr::Cmp(s1: v4[0].data, s2: "shadowModel") == 0
         || idStr::Cmp(s1: v4[0].data, s2: "interAreaPortals") == 0
         || idStr::Cmp(s1: v4[0].data, s2: "areas") == 0 )
    {
      idLexer::SkipBracedSection(this: v1, parseFirstBrace: true);
LABEL_19:
      if ( !idLexer::ReadToken(this: v1, token: v4) )
        goto LABEL_22;
    }
    if ( idStr::Cmp(s1: v4[0].data, s2: "nodes") != 0 )
    {
      idLexer::Error(this: v1, str: "idCollisionModelBuilder::LoadProcBSP: bad token \"%s\"", v4[0].data);
      goto LABEL_19;
    }
    idCollisionModelBuilder::ParseProcNodes(src: v1);
  }
LABEL_22:
  idLexer::~idLexer(this: v1);
  idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
  idStr::FreeData(this: &v4[0]);
LABEL_23:
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$239590
// EA  : 0x825C868C
// RVA : 0x005C868C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_239590()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$239591
// EA  : 0x825C86B4
// RVA : 0x005C86B4
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_239591()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$239592
// EA  : 0x825C86DC
// RVA : 0x005C86DC
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall _unwind_239592(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 288 + 80), tag: a2);
}


// ========================================================================
// ?ChopWindingListWithPolytope@idCollisionModelBuilder@@CAXPAUcm_windingList_t@@PBUcm_buildModel_t@@PBUcm_buildPolytope_t@@@Z
// EA  : 0x825C8788
// RVA : 0x005C8788
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::ChopWindingListWithPolytope(
        cm_windingList_t *list,
        const cm_buildModel_t *model,
        const cm_buildPolytope_t *b)
{
  int numPlanes; // r11
  int v7; // r28
  idVec3 *p_origin; // r29
  float *p_radius; // r27
  int *v10; // r30
  double v11; // fp0
  idPlane *v12; // r11
  double v13; // fp13
  int v14; // r3
  int v15; // r16
  idFixedWinding *w; // r25
  int v17; // r21
  char v18; // r27
  int numWindings; // r20
  unsigned int v20; // r9
  int v21; // r28
  cm_windingList_t *cm_tmpList; // r11
  int v23; // r10
  int v24; // r30
  int v25; // r3
  idPlane *v26; // r11
  idPlane *v27; // r10
  int v28; // r30
  int v29; // r28
  int v30; // r9
  cm_windingList_t *cm_outList; // r11
  int v32; // r28
  int v33; // r10
  int v34; // r30
  idPlane v35; // [sp+60h] [-BD0h] BYREF
  idFixedWinding v36; // [sp+70h] [-BC0h] BYREF
  idFixedWinding v37; // [sp+580h] [-6B0h] BYREF
  _DWORD v38[66]; // [sp+A90h] [-1A0h] BYREF
  idPlane v39; // 0:^50.16
  idPlane v40; // 0:^50.16

  v37.numPoints = 0;
  v37.allocedSize = 64;
  v37.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
  v37.p = v37.data;
  v36.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
  v36.numPoints = 0;
  v36.p = v36.data;
  v36.allocedSize = 64;
  numPlanes = b->numPlanes;
  if ( numPlanes > 64 )
    goto LABEL_2;
  v7 = 0;
  if ( numPlanes > 0 )
  {
    p_origin = &list->origin;
    p_radius = &list->radius;
    v10 = v38;
    do
    {
      v11 = *p_radius;
      v12 = &model->polytopePlanes[b->firstPlane + v7];
      v39.a = -v12->a;
      v39.b = -v12->b;
      v39.d = -v12->d;
      v39.c = -v12->c;
      v13 = (float)((float)((float)(v39.c * list->origin.z)
                          + (float)((float)(p_origin->x * v39.a) + (float)(v39.b * list->origin.y)))
                  + v39.d);
      v35 = v39;
      if ( v13 <= v11 )
      {
        if ( v13 >= -v11 )
        {
          v14 = idBounds::PlaneSide(this: &list->bounds, plane: &v35, epsilon: 0.1);
          *v10 = v14;
          if ( v14 != 0 )
          {
            if ( v14 == 1 )
              *v10 = 1;
            else
              *v10 = 3;
          }
          else
          {
            *v10 = 0;
          }
        }
        else
        {
          *v10 = 1;
        }
      }
      else
      {
        *v10 = 0;
      }
      ++v7;
      ++v10;
    }
    while ( v7 < b->numPlanes );
  }
  v15 = 0;
  buildData.cm_outList->numWindings = 0;
  if ( list->numWindings <= 0 )
    goto LABEL_45;
  w = list->w;
  while ( 2 )
  {
    v17 = 0;
    v18 = 0;
    numWindings = b->numPlanes + 1;
LABEL_18:
    idFixedWinding::operator=(this: &v36, __that: w);
    v20 = v17;
    v21 = 0;
    buildData.cm_tmpList->numWindings = 0;
    cm_tmpList = buildData.cm_tmpList;
    v23 = b->numPlanes;
    if ( v23 <= 0 )
      goto LABEL_34;
    while ( 1 )
    {
      v24 = ((__PAIR64__((unsigned int)v23 >> 31, v20) - __PAIR64__(v20 >> 31, v23)) >> 32) & v20;
      v25 = v38[v24];
      if ( v25 == 3 )
      {
        v26 = &model->polytopePlanes[b->firstPlane + v24];
        v40.a = -v26->a;
        v40.d = -v26->d;
        v40.c = -v26->c;
        v40.b = -v26->b;
        v35 = v40;
        v25 = idFixedWinding::SplitInPlace(
                this: &v36,
                plane: &v35,
                epsilon: 0.1,
                back: (idFixedWinding *)LODWORD(v40.a));
        cm_tmpList = buildData.cm_tmpList;
      }
      if ( v25 == 2 )
      {
        if ( list->primitiveNum >= 0 )
        {
          v27 = &model->polytopePlanes[b->firstPlane + v24];
          if ( (float)((float)(v27->a * list->normal.x)
                     + (float)((float)(v27->c * list->normal.z) + (float)(v27->b * list->normal.y))) > 0.0 )
            goto LABEL_2;
        }
        goto LABEL_29;
      }
      if ( v25 == 1 )
        break;
      if ( v25 == 3 )
      {
        if ( cm_tmpList->numWindings >= 256 )
          goto LABEL_2;
        idFixedWinding::operator=(this: &cm_tmpList->w[cm_tmpList->numWindings], __that: &v37);
        v18 = 1;
        ++buildData.cm_tmpList->numWindings;
        cm_tmpList = buildData.cm_tmpList;
      }
LABEL_29:
      if ( cm_tmpList->numWindings >= numWindings )
        goto LABEL_40;
      v23 = b->numPlanes;
      ++v21;
      v20 = v24 + 1;
      if ( v21 >= v23 )
        goto LABEL_34;
    }
    if ( buildData.cm_outList->numWindings >= 256 )
      goto LABEL_2;
    idFixedWinding::operator=(this: &buildData.cm_outList->w[buildData.cm_outList->numWindings], __that: w);
    v18 = 0;
    ++buildData.cm_outList->numWindings;
    cm_tmpList = buildData.cm_tmpList;
LABEL_34:
    if ( cm_tmpList->numWindings >= numWindings )
      goto LABEL_40;
    numWindings = cm_tmpList->numWindings;
    v28 = 0;
    if ( cm_tmpList->numWindings <= 0 )
    {
LABEL_39:
      if ( numWindings == 1 )
        goto LABEL_42;
LABEL_40:
      ++v17;
      if ( v18 == 0 || v17 >= b->numPlanes )
      {
LABEL_42:
        if ( v18 != 0 )
          buildData.cm_outList->numWindings += numWindings;
        ++v15;
        ++w;
        if ( v15 >= list->numWindings )
        {
LABEL_45:
          cm_outList = buildData.cm_outList;
          v32 = 0;
          v33 = buildData.cm_outList->numWindings;
          if ( buildData.cm_outList->numWindings > 0 )
          {
            v34 = 0;
            do
            {
              idFixedWinding::operator=(this: &list->w[v34], __that: &cm_outList->w[v34]);
              cm_outList = buildData.cm_outList;
              ++v32;
              ++v34;
              v33 = buildData.cm_outList->numWindings;
            }
            while ( v32 < buildData.cm_outList->numWindings );
          }
          list->numWindings = v33;
          v36.p = nullptr;
          v36.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
          idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
          v36.p = nullptr;
          goto _M240199;
        }
        continue;
      }
      goto LABEL_18;
    }
    break;
  }
  v29 = 0;
  while ( 1 )
  {
    v30 = buildData.cm_outList->numWindings + v28;
    if ( v30 >= 256 )
      break;
    idFixedWinding::operator=(this: &buildData.cm_outList->w[v30], __that: &cm_tmpList->w[v29]);
    cm_tmpList = buildData.cm_tmpList;
    ++v28;
    ++v29;
    if ( v28 >= buildData.cm_tmpList->numWindings )
      goto LABEL_39;
  }
LABEL_2:
  v36.p = nullptr;
  v36.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
  idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
  v36.p = nullptr;
_M240199:
  v37.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
  v37.p = nullptr;
  idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
}


// ========================================================================
// __unwind$239839
// EA  : 0x825C8D80
// RVA : 0x005C8D80
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_239839()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 3120 + 1408));
}


// ========================================================================
// __unwind$239840
// EA  : 0x825C8DA8
// RVA : 0x005C8DA8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_239840()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 3120 + 112));
}


// ========================================================================
// ?ChopWindingListWithTreePolytopes_r@idCollisionModelBuilder@@CAXPAUcm_windingList_t@@PBUcm_buildModel_t@@PBUcm_buildNode_t@@@Z
// EA  : 0x825C8DD0
// RVA : 0x005C8DD0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::ChopWindingListWithTreePolytopes_r(
        cm_windingList_t *list,
        const cm_buildModel_t *model,
        const cm_buildNode_t *node)
{
  cm_buildPolytopeRef_t *i; // r30
  int checkCount; // r11
  cm_buildPolytope_t *v8; // r5
  int primitiveNum; // r10
  int v10; // r9
  float *v11; // r10
  idVec3 *v12; // r11
  int planeType; // r11
  double planeDist; // fp0

  while ( 1 )
  {
    for ( i = node->polytopes; i != nullptr; i = i->next )
    {
      checkCount = model->checkCount;
      v8 = &model->polytopes[i->polytopeNum];
      if ( v8->checkCount != checkCount )
      {
        primitiveNum = v8->primitiveNum;
        v8->checkCount = checkCount;
        if ( primitiveNum != list->primitiveNum && v8->contents == list->contents )
        {
          v10 = 0;
          v11 = (float *)v8;
          v12 = &list->bounds.b[1];
          while ( v12[-1].x <= (double)v11[3] && v12->x >= (double)*v11 )
          {
            ++v10;
            v12 = (idVec3 *)((char *)v12 + 4);
            ++v11;
            if ( v10 >= 3 )
            {
              idCollisionModelBuilder::ChopWindingListWithPolytope(list, model, b: v8);
              if ( list->numWindings == 0 )
                return;
              break;
            }
          }
        }
      }
    }
    planeType = node->planeType;
    if ( node->planeType == -1 )
      break;
    planeDist = node->planeDist;
    if ( *(&list->bounds.b[0].x + planeType) <= planeDist )
    {
      if ( *(&list->bounds.b[1].x + planeType) >= planeDist )
      {
        idCollisionModelBuilder::ChopWindingListWithTreePolytopes_r(list, model, node: node->children[1]);
        if ( list->numWindings == 0 )
          return;
        node = node->children[0];
      }
      else
      {
        node = node->children[1];
      }
    }
    else
    {
      node = node->children[0];
    }
  }
}


// ========================================================================
// ?TryMergePolygons@idCollisionModelBuilder@@CAPAUcm_buildPolygon_t@@PAUcm_buildModel_t@@HH@Z
// EA  : 0x825C8F48
// RVA : 0x005C8F48
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

cm_buildPolygon_t *__fastcall idCollisionModelBuilder::TryMergePolygons(
        cm_buildModel_t *model,
        int polygonNum1,
        int polygonNum2)
{
  cm_buildPolygon_t *polygons; // r11
  cm_buildPolygon_t *v4; // r28
  cm_buildPolygon_t *v5; // r17
  int v7; // r9
  float *p_a; // r10
  float *p_x; // r11
  int numEdges; // r25
  int v11; // r9
  unsigned int v12; // r4
  cm_buildVertex_t *v13; // r11
  signed int v14; // r26
  int v15; // r15
  int v16; // r16
  int v17; // r24
  int v18; // r18
  int v19; // r3
  signed int v20; // r27
  int v21; // r4
  int v22; // r29
  signed int v23; // r10
  int firstEdge; // r6
  int v25; // r5
  int *polygonEdges; // r11
  int v27; // r9
  int v28; // r8
  int v29; // r23
  int v30; // r22
  int v31; // r21
  int v32; // r7
  int v33; // r9
  int v34; // r8
  int v35; // r6
  int *v36; // r10
  int v37; // r5
  cm_buildEdge_t *edges; // r11
  int v39; // r29
  cm_buildVertex_t *vertices; // r7
  int v41; // r27
  unsigned int v42; // r26
  unsigned int v43; // r8
  cm_buildEdge_t *v44; // r9
  unsigned int v45; // r22
  int v46; // r21
  unsigned int v47; // r23
  float *v48; // r9
  float *v49; // r8
  cm_buildEdge_t *v50; // r9
  double v51; // fp3
  double v52; // fp2
  double v53; // fp1
  double v56; // fp4
  double v57; // fp10
  double v58; // fp7
  float *v59; // r9
  float *v60; // r8
  double v61; // fp7
  double v62; // fp9
  int v63; // r4
  bool v64; // r25
  cm_buildVertex_t *v65; // r6
  unsigned int v66; // r3
  unsigned int v67; // r9
  cm_buildEdge_t *v68; // r10
  int v69; // r26
  unsigned int v70; // r23
  unsigned int v71; // r5
  float *v72; // r10
  float *v73; // r9
  cm_buildEdge_t *v74; // r8
  double v75; // fp4
  double v76; // fp1
  double v77; // fp3
  float *v78; // r10
  double v79; // fp31
  double v80; // fp2
  double v81; // fp1
  double v82; // fp13
  double v85; // fp12
  double v86; // fp12
  double v87; // fp6
  double v88; // fp5
  double v89; // fp4
  cm_buildVertex_t *v90; // r10
  long double v91; // fp2
  double v92; // fp0
  double v93; // fp0
  int v94; // r20
  int v95; // r19
  bool v96; // r26
  int *v97; // r10
  int v98; // r8
  unsigned int v99; // r5
  unsigned int v100; // r4
  BOOL v101; // r10
  unsigned int v102; // r8
  int *v103; // r8
  cm_buildEdge_t *v104; // r4
  int v105; // r5
  unsigned int v106; // r8
  int v107; // r11
  int v108; // r10
  int v109; // r10
  int v110; // r5
  BOOL v111; // r21
  int v112; // r29
  int v113; // r12
  BOOL v114; // r4
  int v115; // r11
  BOOL v116; // r22
  BOOL v117; // r6
  int v118; // r8
  int *v119; // r7
  int *v120; // r9
  int *v121; // r9
  int v122; // ctr
  int v123; // r3
  int v124; // r8
  int v125; // r10
  int *v126; // r7
  int *v127; // r9
  int *v128; // r9
  int v129; // ctr
  int v130; // r6
  int v131; // r9
  int v132; // r8
  int *v133; // r7
  int *v134; // r10
  int *v135; // r10
  int v136; // ctr
  int v137; // r3
  int v138; // r11
  int v139; // r8
  int *v140; // r7
  int *v141; // r9
  int *v142; // r9
  int v143; // ctr
  int v144; // r6
  int v145; // r8
  int *v146; // r7
  int *v147; // r9
  int *v148; // r9
  int v149; // ctr
  int v150; // r6
  int v151; // r7
  int v152; // r9
  int *v153; // r8
  int *v154; // r10
  int *v155; // r10
  int v156; // ctr
  int v157; // r6
  cm_buildPolygon_t *v158; // r3
  cm_buildPolygon_t *v159; // r11
  cm_buildPolygon_t *v160; // r28
  float *p_bounds; // r26
  cm_buildPolygon_t *v162; // r27
  float *v163; // r23
  float *v164; // r25
  float *v165; // r24
  int v166; // r7
  int i; // r9
  int v168; // r11
  cm_buildEdge_t *v169; // r11
  _DWORD back_chain[2]; // [sp+0h] [-120h]
  int v184; // [sp+8h] [-118h]
  int v185; // [sp+Ch] [-114h]
  int v186; // [sp+10h] [-110h]
  int v187; // [sp+14h] [-10Ch]
  int v188; // [sp+18h] [-108h]
  int v189; // [sp+1Ch] [-104h]
  int v190; // [sp+20h] [-100h]
  int v191; // [sp+24h] [-FCh]
  int v192; // [sp+28h] [-F8h]
  int v193; // [sp+2Ch] [-F4h]
  int v194; // [sp+30h] [-F0h]
  int v195; // [sp+34h] [-ECh]
  int v196; // [sp+50h] [-D0h] BYREF
  int v197; // [sp+54h] [-CCh] BYREF
  int v198; // [sp+58h] [-C8h]
  int v199; // [sp+5Ch] [-C4h]

  polygons = model->polygons;
  v199 = 68 * polygonNum2;
  v198 = 68 * polygonNum1;
  v4 = &polygons[polygonNum1];
  v5 = &polygons[polygonNum2];
  ++c_numTryMergePolygons;
  if ( v4->material != v5->material || __fabs((float)((float)-v4->plane.d - (float)-v5->plane.d)) > 0.0099999998 )
    return nullptr;
  v7 = 0;
  p_a = &polygons[polygonNum2].plane.a;
  p_x = &v4->bounds.b[1].x;
  do
  {
    if ( __fabs((float)(*(p_x - 7) - *p_a)) > 0.000099999997
      || *(p_x - 3) > (double)*(float *)((char *)p_x + (char *)v5 - (char *)v4)
      || *p_x < (double)p_a[4] )
    {
      return nullptr;
    }
    ++v7;
    ++p_a;
    ++p_x;
  }
  while ( v7 < 3 );
  numEdges = v5->numEdges;
  v11 = 0;
  if ( numEdges > 0 )
  {
    do
    {
      v12 = model->polygonEdges[v5->firstEdge + v11];
      v13 = &model->vertices[model->edges[abs32(v12)].vertexNum[v12 >> 31]];
      if ( __fabs((float)((float)((float)(v4->plane.a * v13->p.x)
                                + (float)((float)(v13->p.y * v4->plane.b) + (float)(v13->p.z * v4->plane.c)))
                        + v4->plane.d)) > 0.1 )
        return nullptr;
    }
    while ( ++v11 < numEdges );
  }
  v14 = v4->numEdges;
  v15 = -1;
  v16 = -1;
  v17 = -1;
  v18 = -1;
  v19 = 0;
  if ( v14 <= 0 )
    return nullptr;
  do
  {
    v20 = v19 + 1;
    v21 = 0;
    __twllei(v14, 0);
    v22 = (v19 + 1) % v14;
    __twlgei(v14 & ~(__ROL4__(v19 + 1, 1) - 1), 0xFFFFFFFF);
    if ( numEdges <= 0 )
      goto LABEL_23;
    v23 = v5->numEdges;
    firstEdge = v5->firstEdge;
    v25 = v4->firstEdge;
    while ( 1 )
    {
      polygonEdges = model->polygonEdges;
      v27 = v25 + v19;
      v28 = firstEdge + v21;
      __twllei(v23, 0);
      v29 = v23 + v21 - 1;
      v30 = polygonEdges[v27];
      v31 = polygonEdges[v28];
      __twlgei(v23 & ~(__ROL4__(v29, 1) - 1), 0xFFFFFFFF);
      v32 = v29 % v23;
      if ( abs32(v30) != abs32(v31) )
        break;
      if ( model->polygonEdges[v27] != model->polygonEdges[v28]
        && abs32(polygonEdges[v25 + v22]) != abs32(polygonEdges[firstEdge + v32]) )
      {
        v17 = (v19 + 1) % v14;
        v16 = v29 % v23;
        goto LABEL_23;
      }
LABEL_20:
      if ( ++v21 >= numEdges )
        goto LABEL_23;
    }
    v33 = v25 + v22;
    v34 = firstEdge + v32;
    if ( abs32(polygonEdges[v33]) != abs32(polygonEdges[v34]) )
      goto LABEL_20;
    if ( model->polygonEdges[v33] != model->polygonEdges[v34] )
    {
      v18 = v19;
      v15 = v21;
    }
LABEL_23:
    ++v19;
  }
  while ( v20 < v14 );
  if ( v18 < 0 )
    return nullptr;
  if ( v17 < 0 )
    return nullptr;
  if ( v16 < 0 )
    return nullptr;
  if ( v15 < 0 )
    return nullptr;
  v35 = v4->firstEdge;
  v36 = model->polygonEdges;
  v37 = v5->firstEdge;
  edges = model->edges;
  v39 = v35 + v18;
  vertices = model->vertices;
  v41 = v37 + v15;
  v42 = v36[v39];
  v43 = v36[v41];
  v44 = &edges[abs32(v42)];
  v45 = ~v43;
  v46 = (v43 >> 29) & 4;
  v47 = abs32(v43);
  v49 = &vertices[*(int *)((char *)v44->vertexNum + ((~v42 >> 29) & 4))].p.x;
  v48 = &vertices[*(int *)((char *)v44->vertexNum + ((v42 >> 29) & 4))].p.x;
  v52 = (float)((float)(v4->plane.a * (float)(v49[1] - v48[1])) - (float)(v4->plane.b * (float)(*v49 - *v48)));
  v51 = (float)((float)(v4->plane.c * (float)(*v49 - *v48)) - (float)(v4->plane.a * (float)(v49[2] - v48[2])));
  v53 = (float)((float)(v4->plane.b * (float)(v49[2] - v48[2])) - (float)(v4->plane.c * (float)(v49[1] - v48[1])));
  v50 = &edges[v47];
  _FP7 = (float)((float)((float)((float)v53 * (float)v53)
                       + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f5, f7, f8, f12 }
  v56 = __frsqrte(_FP5);
  v57 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56
                                                                                      * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51)))
                                                                                              * (float)0.5))
                                                                              * (float)v56)
                                                                      - (float)1.5)
                                                      * (float)v56)
                                              * (float)((float)((float)((float)v53 * (float)v53)
                                                              + (float)((float)((float)v52 * (float)v52)
                                                                      + (float)((float)v51 * (float)v51)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v56
                                                                              * (float)((float)((float)((float)v53 * (float)v53)
                                                                                              + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51)))
                                                                                      * (float)0.5))
                                                                      * (float)v56)
                                                              - (float)1.5)
                                              * (float)v56))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v56
                                                      * (float)((float)((float)((float)v53 * (float)v53)
                                                                      + (float)((float)((float)v52 * (float)v52)
                                                                              + (float)((float)v51 * (float)v51)))
                                                              * (float)0.5))
                                              * (float)v56)
                                      - (float)1.5)
                      * (float)v56));
  v58 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5)
                                                                                              * (float)v56)
                                                                                      * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5)
                                                                                      * (float)v56))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v56
                                                                                              * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56))
                                              * (float)((float)((float)((float)v53 * (float)v53)
                                                              + (float)((float)((float)v52 * (float)v52)
                                                                      + (float)((float)v51 * (float)v51)))
                                                      * (float)0.5))
                                      * (float)v57)
                              - (float)1.5)
              * (float)v57);
  v60 = &vertices[*(int *)((char *)v50->vertexNum + ((v45 >> 29) & 4))].p.x;
  v59 = &vertices[*(int *)((char *)v50->vertexNum + v46)].p.x;
  v61 = (float)((float)((float)(*v60 - *v59) * (float)((float)v53 * (float)v58))
              + (float)((float)(v60[2] - v59[2])
                      * (float)((float)v52
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56) * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5)
                                                                                      * (float)v56))
                                                                      * (float)((float)((float)((float)v53 * (float)v53)
                                                                                      + (float)((float)((float)v52 * (float)v52)
                                                                                              + (float)((float)v51 * (float)v51)))
                                                                              * (float)0.5))
                                                              * (float)v57)
                                                      - (float)1.5)
                                      * (float)v57))));
  v62 = (float)((float)((float)(v60[1] - v59[1])
                      * (float)((float)v51
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56) * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5)
                                                                                      * (float)v56))
                                                                      * (float)((float)((float)((float)v53 * (float)v53)
                                                                                      + (float)((float)((float)v52 * (float)v52)
                                                                                              + (float)((float)v51 * (float)v51)))
                                                                              * (float)0.5))
                                                              * (float)v57)
                                                      - (float)1.5)
                                      * (float)v57)))
              + (float)v61);
  if ( v62 < -0.0049999999 )
    return nullptr;
  v63 = v35 + v17;
  v64 = v62 > 0.0049999999;
  v65 = model->vertices;
  v66 = v36[v37 + v16];
  v67 = v36[v63];
  v68 = &edges[abs32(v66)];
  v69 = (v67 >> 29) & 4;
  v70 = ~v67;
  v71 = abs32(v67);
  v73 = &v65[*(int *)((char *)v68->vertexNum + ((~v66 >> 29) & 4))].p.x;
  v72 = &v65[*(int *)((char *)v68->vertexNum + ((v66 >> 29) & 4))].p.x;
  v74 = &edges[v71];
  v75 = (float)(v73[2] - v72[2]);
  v76 = (float)(*v73 - *v72);
  v77 = (float)(v73[1] - v72[1]);
  v78 = &v65[*(int *)((char *)v74->vertexNum + v69)].p.x;
  v79 = v78[2];
  v80 = (float)((float)(v4->plane.c * (float)v76) - (float)(v4->plane.a * (float)v75));
  v81 = (float)((float)(v4->plane.a * (float)v77) - (float)(v4->plane.b * (float)v76));
  v82 = (float)((float)(v4->plane.b * (float)v75) - (float)(v4->plane.c * (float)v77));
  _FP5 = (float)((float)((float)((float)v82 * (float)v82)
                       + (float)((float)((float)v81 * (float)v81) + (float)((float)v80 * (float)v80)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v85 = __frsqrte(_FP3);
  v86 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v85
                                                                                      * (float)((float)((float)((float)v82 * (float)v82) + (float)((float)((float)v81 * (float)v81) + (float)((float)v80 * (float)v80)))
                                                                                              * (float)0.5))
                                                                              * (float)v85)
                                                                      - (float)1.5)
                                                      * (float)v85)
                                              * (float)((float)((float)((float)v82 * (float)v82)
                                                              + (float)((float)((float)v81 * (float)v81)
                                                                      + (float)((float)v80 * (float)v80)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v85
                                                                              * (float)((float)((float)((float)v82 * (float)v82)
                                                                                              + (float)((float)((float)v81 * (float)v81) + (float)((float)v80 * (float)v80)))
                                                                                      * (float)0.5))
                                                                      * (float)v85)
                                                              - (float)1.5)
                                              * (float)v85))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v85
                                                      * (float)((float)((float)((float)v82 * (float)v82)
                                                                      + (float)((float)((float)v81 * (float)v81)
                                                                              + (float)((float)v80 * (float)v80)))
                                                              * (float)0.5))
                                              * (float)v85)
                                      - (float)1.5)
                      * (float)v85));
  v87 = (float)((float)v82
              * (float)((float)-(float)((float)((float)((float)v86
                                                      * (float)((float)((float)((float)v82 * (float)v82)
                                                                      + (float)((float)((float)v81 * (float)v81)
                                                                              + (float)((float)v80 * (float)v80)))
                                                              * (float)0.5))
                                              * (float)v86)
                                      - (float)1.5)
                      * (float)v86));
  v88 = (float)((float)v80
              * (float)((float)-(float)((float)((float)((float)v86
                                                      * (float)((float)((float)((float)v82 * (float)v82)
                                                                      + (float)((float)((float)v81 * (float)v81)
                                                                              + (float)((float)v80 * (float)v80)))
                                                              * (float)0.5))
                                              * (float)v86)
                                      - (float)1.5)
                      * (float)v86));
  v89 = (float)((float)v81
              * (float)((float)-(float)((float)((float)((float)v86
                                                      * (float)((float)((float)((float)v82 * (float)v82)
                                                                      + (float)((float)((float)v81 * (float)v81)
                                                                              + (float)((float)v80 * (float)v80)))
                                                              * (float)0.5))
                                              * (float)v86)
                                      - (float)1.5)
                      * (float)v86));
  *((double *)&v91 + 1) = v78[1];
  *(double *)&v91 = v65[*(int *)((char *)v74->vertexNum + ((v70 >> 29) & 4))].p.x;
  v92 = (float)(v65[*(int *)((char *)v74->vertexNum + ((v70 >> 29) & 4))].p.x - *v78);
  v90 = &v65[*(int *)((char *)v74->vertexNum + ((v70 >> 29) & 4))];
  v93 = (float)((float)((float)(v90->p.y - (float)*((double *)&v91 + 1)) * (float)v88)
              + (float)((float)((float)v92 * (float)v87) + (float)((float)(v90->p.z - (float)v79) * (float)v89)));
  if ( v93 < -0.0049999999 )
    return nullptr;
  v94 = 0;
  v95 = 0;
  v197 = 0;
  v96 = v93 > 0.0049999999;
  v196 = 0;
  if ( v62 <= 0.0049999999 )
  {
    v97 = model->polygonEdges;
    v98 = v97[v41];
    v99 = v97[v39];
    v100 = abs32(v98);
    v101 = v98 >= 0;
    v102 = 3 * edges[abs32(v99)].vertexNum[v99 >> 31];
    idCollisionModelBuilder::GetEdge(
      model,
      v1: &model->vertices[v102 / 3].p,
      v2: &model->vertices[edges[v100].vertexNum[v101]].p,
      edgeNum: &v196,
      v1num: -1,
      a6: v91,
      a7: v102,
      a8: (int)model->vertices,
      a9: 8 * v102,
      a10: v184,
      a11: v185,
      a12: v186,
      a13: v187,
      a14: v188,
      a15: v189,
      a16: v190,
      a17: v191,
      a18: v192,
      a19: v193,
      a20: v194,
      a21: v195);
    v95 = v196;
    if ( v196 == 0 )
      v64 = true;
  }
  if ( !v96 )
  {
    v103 = model->polygonEdges;
    v104 = model->edges;
    v105 = v103[v4->firstEdge + v17];
    v106 = v103[v5->firstEdge + v16];
    v107 = v104[abs32(v105)].vertexNum[v105 >= 0];
    v108 = v104[abs32(v106)].vertexNum[v106 >> 31];
    idCollisionModelBuilder::GetEdge(
      model,
      v1: &model->vertices[v108].p,
      v2: &model->vertices[v107].p,
      edgeNum: &v197,
      v1num: -1,
      a6: v91,
      a7: 2 * v107,
      a8: (int)model->vertices,
      a9: 24 * v108,
      a10: v184,
      a11: v185,
      a12: v186,
      a13: v187,
      a14: v188,
      a15: v189,
      a16: v190,
      a17: v191,
      a18: v192,
      a19: v193,
      a20: v194,
      a21: v195);
    v94 = v197;
    if ( v197 == 0 )
      v96 = true;
  }
  ((void (*)(void))RtlCheckStack12)();
  v111 = v96;
  v112 = 0;
  *(_DWORD *)((char *)back_chain + v113) = back_chain[0];
  if ( !v96 )
  {
    v196 = v94;
    v112 = 1;
  }
  v114 = (_cntlzw(v96) & 0x20) != 0;
  v115 = v114 + v17;
  if ( v17 >= v18 )
  {
    if ( v115 < v109 )
    {
      v124 = v4->firstEdge;
      v125 = v109 - v115;
      v126 = model->polygonEdges;
      v127 = &v196 + v112;
      v112 += v125;
      v128 = v127 - 1;
      v129 = v125;
      do
      {
        v130 = v124 + v115++;
        *++v128 = v126[v130];
        --v129;
      }
      while ( v129 != 0 );
    }
    v116 = v64;
    v131 = 0;
    v117 = (_cntlzw(v64) & 0x20) != 0;
    if ( v18 - v117 >= 0 )
    {
      v132 = v4->firstEdge;
      v133 = model->polygonEdges;
      v134 = &v196 + v112;
      v112 += v18 - v117 + 1;
      v135 = v134 - 1;
      v136 = v18 - v117 + 1;
      do
      {
        v137 = v132 + v131++;
        *++v135 = v133[v137];
        --v136;
      }
      while ( v136 != 0 );
    }
  }
  else
  {
    v116 = v64;
    v117 = (_cntlzw(v64) & 0x20) != 0;
    if ( v115 <= v18 - v117 )
    {
      v118 = v4->firstEdge;
      v119 = model->polygonEdges;
      v120 = &v196 + v112;
      v112 += v18 - v117 - v115 + 1;
      v121 = v120 - 1;
      v122 = v18 - v117 - v115 + 1;
      do
      {
        v123 = v118 + v115++;
        *++v121 = v119[v123];
        --v122;
      }
      while ( v122 != 0 );
    }
  }
  if ( !v116 )
    *(&v196 + v112++) = v95;
  v138 = v117 + v15;
  if ( v15 >= v16 )
  {
    if ( v138 < v110 )
    {
      v145 = v5->firstEdge;
      v146 = model->polygonEdges;
      v147 = &v196 + v112;
      v112 += v110 - v138;
      v148 = v147 - 1;
      v149 = v110 - v138;
      do
      {
        v150 = v145 + v138++;
        *++v148 = v146[v150];
        --v149;
      }
      while ( v149 != 0 );
    }
    v151 = 0;
    if ( v16 - v114 >= 0 )
    {
      v152 = v5->firstEdge;
      v153 = model->polygonEdges;
      v154 = &v196 + v112;
      v112 += v16 - v114 + 1;
      v155 = v154 - 1;
      v156 = v16 - v114 + 1;
      do
      {
        v157 = v152 + v151++;
        *++v155 = v153[v157];
        --v156;
      }
      while ( v156 != 0 );
    }
  }
  else if ( v138 <= v16 - v114 )
  {
    v139 = v5->firstEdge;
    v140 = model->polygonEdges;
    v141 = &v196 + v112;
    v112 += v16 - v114 - v138 + 1;
    v142 = v141 - 1;
    v143 = v16 - v114 - v138 + 1;
    do
    {
      v144 = v139 + v138++;
      *++v142 = v140[v144];
      --v143;
    }
    while ( v143 != 0 );
  }
  v158 = idCollisionModelBuilder::AllocPolygon(model, numEdges: v112);
  v159 = model->polygons;
  v160 = v158;
  p_bounds = (float *)&v158->bounds;
  v162 = &v159[v198 / 0x44u];
  v163 = &v159[v199 / 0x44u].plane.a;
  v164 = &v159[v198 / 0x44u].bounds.b[1].x;
  v165 = &v158->bounds.b[1].x;
  v158->bounds = v159[v198 / 0x44u].bounds;
  v158->contents = v162->contents;
  v158->material = v162->material;
  v166 = v158->firstEdge;
  v158->primitiveNum = v162->primitiveNum;
  v158->plane.a = v162->plane.a;
  v158->plane.b = v162->plane.b;
  v158->plane.c = v162->plane.c;
  v158->plane.d = v162->plane.d;
  v158->numEdges = v112;
  memcpy(Dst: &model->polygonEdges[v166], Src: &v196, Size: 4 * v112);
  for ( i = 0; i < v160->numEdges; ++i )
  {
    v168 = model->polygonEdges[v160->firstEdge + i];
    if ( (v116 || v168 != v95) && (v111 || v168 != v94) )
    {
      v169 = &model->edges[abs32(v168)];
      ++v169->numUsers;
    }
  }
  _FP11 = (float)(v162->bounds.b[0].x - v163[4]);
  _FP6 = (float)(v162->bounds.b[0].y - v163[5]);
  _FP4 = (float)(v162->bounds.b[0].z - v163[6]);
  _FP2 = (float)(v163[7] - *v164);
  _FP30 = (float)(v163[8] - v162->bounds.b[1].y);
  _FP28 = (float)(v163[9] - v162->bounds.b[1].z);
  __asm { fsel      f0, f11, f13, f0 }
  *p_bounds = _FP0;
  __asm { fsel      f13, f6, f8, f12 }
  p_bounds[1] = _FP13;
  __asm { fsel      f12, f4, f7, f10 }
  p_bounds[2] = _FP12;
  __asm { fsel      f11, f2, f5, f9 }
  *v165 = _FP11;
  __asm { fsel      f10, f30, f1, f3 }
  v165[1] = _FP10;
  __asm { fsel      f9, f28, f29, f31 }
  v165[2] = _FP9;
  return v160;
}


// ========================================================================
// ?MergePolygonWithTreePolygons@idCollisionModelBuilder@@CA_NPAUcm_buildModel_t@@PAUcm_buildNode_t@@H_N@Z
// EA  : 0x825C9B40
// RVA : 0x005C9B40
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::MergePolygonWithTreePolygons(
        cm_buildModel_t *model,
        cm_buildNode_t *node,
        int polygonNum,
        bool mergePrimitives)
{
  int v4; // r25
  cm_buildPolygon_t *v9; // r27
  cm_buildPolygonRef_t *polygons; // r29
  int v11; // r5
  cm_buildPolygon_t *v12; // r3
  int planeType; // r11
  double planeDist; // fp0
  cm_buildPolygon_t *v15; // r11
  int v16; // r5
  cm_buildNode_t *v17; // r4
  int v18; // r6
  cm_buildPolygon_t *v19; // r30
  cm_buildPolygon_t *v20; // r29
  int i; // r11
  int v22; // r6
  cm_buildEdge_t *v23; // r10
  int j; // r11
  int v25; // r6
  cm_buildEdge_t *v26; // r10

  v4 = polygonNum;
  v9 = &model->polygons[polygonNum];
  while ( 1 )
  {
    polygons = node->polygons;
    if ( polygons != nullptr )
    {
      while ( 1 )
      {
        v11 = polygons->polygonNum;
        if ( polygons->polygonNum != polygonNum
          && (mergePrimitives || model->polygons[v11].primitiveNum == v9->primitiveNum) )
        {
          v12 = idCollisionModelBuilder::TryMergePolygons(model, polygonNum1: polygonNum, polygonNum2: v11);
          if ( v12 != nullptr )
            break;
        }
        polygons = polygons->next;
        if ( polygons == nullptr )
          goto LABEL_8;
      }
      v15 = model->polygons;
      v16 = polygonNum;
      v17 = model->node;
      ++model->numMergedPolys;
      v18 = polygons->polygonNum;
      v19 = &v15[v4];
      v20 = &v15[polygons->polygonNum];
      idCollisionModelBuilder::ReplacePolygons(
        model,
        node: v17,
        polygonNum1: v16,
        polygonNum2: v18,
        newPolygonNum: v12 - v15);
      for ( i = 0; i < v19->numEdges; --v23->numUsers )
      {
        v22 = v19->firstEdge + i++;
        v23 = &model->edges[abs32(model->polygonEdges[v22])];
      }
      for ( j = 0; j < v20->numEdges; --v26->numUsers )
      {
        v25 = v20->firstEdge + j++;
        v26 = &model->edges[abs32(model->polygonEdges[v25])];
      }
      v19->numEdges = 0;
      v20->numEdges = 0;
      return 1;
    }
LABEL_8:
    planeType = node->planeType;
    if ( node->planeType == -1 )
      return 0;
    planeDist = node->planeDist;
    if ( *(&v9->bounds.b[0].x + planeType) <= planeDist )
    {
      if ( *(&v9->bounds.b[1].x + planeType) >= planeDist )
      {
        if ( idCollisionModelBuilder::MergePolygonWithTreePolygons(
               model,
               node: node->children[1],
               polygonNum,
               mergePrimitives) )
        {
          return 1;
        }
        node = node->children[0];
      }
      else
      {
        node = node->children[1];
      }
    }
    else
    {
      node = node->children[0];
    }
  }
}


// ========================================================================
// ?MergeTreePolygons@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAUcm_buildNode_t@@_N@Z
// EA  : 0x825C9D58
// RVA : 0x005C9D58
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::MergeTreePolygons(
        cm_buildModel_t *model,
        cm_buildNode_t *node,
        bool mergePrimitives)
{
  cm_buildPolygonRef_t *polygons; // r25
  char v7; // r21
  int checkCount; // r11
  cm_buildPolygon_t *v9; // r10
  int polygonNum; // r30
  int v11; // r26
  cm_buildNode_t *v12; // r28
  cm_buildPolygon_t *v13; // r27
  int *p_polygonNum; // r29
  int v15; // r5
  cm_buildPolygon_t *v16; // r3
  int planeType; // r11
  double planeDist; // fp0
  int v19; // r5
  cm_buildPolygon_t *v20; // r11
  cm_buildNode_t *v21; // r4
  int v22; // r6
  cm_buildPolygon_t *v23; // r30
  cm_buildPolygon_t *v24; // r29
  int i; // r11
  int v26; // r7
  cm_buildEdge_t *v27; // r10
  int j; // r11
  int v29; // r7
  cm_buildEdge_t *v30; // r10
  char v31; // r11

  while ( 1 )
  {
    do
    {
      polygons = node->polygons;
      v7 = 0;
      if ( polygons != nullptr )
      {
        while ( 1 )
        {
          checkCount = model->checkCount;
          v9 = &model->polygons[polygons->polygonNum];
          if ( v9->checkCount != checkCount )
          {
            v9->checkCount = checkCount;
            polygonNum = polygons->polygonNum;
            v11 = polygons->polygonNum;
            v12 = model->node;
            v13 = &model->polygons[v11];
            while ( 1 )
            {
              p_polygonNum = &v12->polygons->polygonNum;
              if ( p_polygonNum != nullptr )
              {
                while ( 1 )
                {
                  v15 = *p_polygonNum;
                  if ( *p_polygonNum != polygonNum
                    && (mergePrimitives || model->polygons[v15].primitiveNum == v13->primitiveNum) )
                  {
                    v16 = idCollisionModelBuilder::TryMergePolygons(model, polygonNum1: polygonNum, polygonNum2: v15);
                    if ( v16 != nullptr )
                      break;
                  }
                  p_polygonNum = (int *)p_polygonNum[1];
                  if ( p_polygonNum == nullptr )
                    goto LABEL_10;
                }
                v19 = polygonNum;
                v20 = model->polygons;
                v21 = model->node;
                ++model->numMergedPolys;
                v22 = *p_polygonNum;
                v23 = &v20[v11];
                v24 = &v20[*p_polygonNum];
                idCollisionModelBuilder::ReplacePolygons(
                  model,
                  node: v21,
                  polygonNum1: v19,
                  polygonNum2: v22,
                  newPolygonNum: v16 - v20);
                for ( i = 0; i < v23->numEdges; --v27->numUsers )
                {
                  v26 = v23->firstEdge + i++;
                  v27 = &model->edges[abs32(model->polygonEdges[v26])];
                }
                for ( j = 0; j < v24->numEdges; --v30->numUsers )
                {
                  v29 = v24->firstEdge + j++;
                  v30 = &model->edges[abs32(model->polygonEdges[v29])];
                }
                v23->numEdges = 0;
                v24->numEdges = 0;
LABEL_22:
                v31 = 1;
                goto LABEL_23;
              }
LABEL_10:
              planeType = v12->planeType;
              if ( v12->planeType == -1 )
                break;
              planeDist = v12->planeDist;
              if ( *(&v13->bounds.b[0].x + planeType) <= planeDist )
              {
                if ( *(&v13->bounds.b[1].x + planeType) >= planeDist )
                {
                  if ( (unsigned __int8)idCollisionModelBuilder::MergePolygonWithTreePolygons(
                                          model,
                                          node: v12->children[1],
                                          polygonNum,
                                          mergePrimitives) != 0 )
                    goto LABEL_22;
                  v12 = v12->children[0];
                }
                else
                {
                  v12 = v12->children[1];
                }
              }
              else
              {
                v12 = v12->children[0];
              }
            }
            v31 = 0;
LABEL_23:
            if ( v31 != 0 )
              break;
          }
          polygons = polygons->next;
          if ( polygons == nullptr )
            goto LABEL_28;
        }
        v7 = 1;
      }
LABEL_28:
      ;
    }
    while ( v7 != 0 );
    if ( node->planeType == -1 )
      break;
    idCollisionModelBuilder::MergeTreePolygons(model, node: node->children[1], mergePrimitives);
    node = node->children[0];
  }
}


// ========================================================================
// ?SplitPolygon@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@H@Z
// EA  : 0x825CA000
// RVA : 0x005CA000
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::SplitPolygon(cm_buildModel_t *model, int polygonNum)
{
  cm_buildPolygon_t *v2; // r30
  int numEdges; // r11
  int v5; // r21
  int v6; // r17
  int v7; // r27
  double v8; // fp10
  int firstEdge; // r3
  int *polygonEdges; // r29
  cm_buildEdge_t *edges; // r28
  cm_buildVertex_t *vertices; // r10
  signed int v13; // r11
  int v14; // r4
  int v15; // r9
  unsigned int v16; // r22
  int v17; // r23
  cm_buildEdge_t *v18; // r8
  int v19; // r7
  int v20; // r8
  unsigned int v21; // r16
  unsigned int v22; // r15
  unsigned int v23; // r14
  double v24; // fp5
  double v25; // fp4
  cm_buildEdge_t *v26; // r6
  cm_buildEdge_t *v27; // r11
  cm_buildEdge_t *v28; // r7
  double v29; // fp1
  int v30; // r8
  int v31; // r24
  float *p_x; // r11
  float *v33; // r9
  float *v34; // r8
  float *v35; // r6
  float *v36; // r5
  float *v37; // r4
  double v38; // fp7
  double v39; // fp11
  double v40; // fp8
  double v41; // fp2
  double v42; // fp31
  double v43; // fp30
  float *v44; // r9
  double v45; // fp24
  double v46; // fp23
  double v53; // fp28
  double v54; // fp27
  double v55; // fp26
  double v56; // fp28
  double v57; // fp27
  double v58; // fp26
  double v59; // fp28
  double v60; // fp27
  double v61; // fp26
  double v62; // fp28
  double v63; // fp27
  double v64; // fp26
  double v65; // fp1
  double v66; // fp4
  double v67; // fp5
  double v68; // fp3
  double v69; // fp7
  double v70; // fp11
  double v71; // fp8
  double v72; // fp6
  double v73; // fp2
  double v78; // fp27
  double v79; // fp28
  double v80; // fp27
  double v81; // fp28
  double v82; // fp27
  double v83; // fp28
  double v84; // fp27
  double v85; // fp28
  double v86; // fp28
  double v87; // fp3
  double v88; // fp5
  double v89; // fp1
  double v90; // fp11
  int v97; // r11
  int *v98; // r7
  cm_buildEdge_t *v99; // r29
  unsigned int v100; // r8
  __int64 v101; // r11
  int v102; // r27
  int v103; // r25
  int v104; // r11
  cm_buildEdge_t *v105; // r3
  cm_buildEdge_t *v106; // r11
  idHashIndex *cm_edgeHash; // r29
  int v108; // r28
  int v109; // r27
  int indexSize; // r11
  signed int v111; // r25
  int v112; // r6
  int *v113; // r3
  int *v114; // r27
  int v117; // r11
  int v122; // r11
  int v123; // r28
  int v124; // r10
  int *v125; // r6
  int v126; // r5
  int v127; // r4
  signed int v128; // r8
  int v129; // r9
  unsigned int v130; // r11
  unsigned int v131; // r3
  cm_buildVertex_t *v132; // r11
  cm_buildPolygon_t *v139; // r3
  cm_buildPolygon_t *polygons; // r10
  int v141; // r8
  cm_buildPolygon_t *v142; // r29
  int v143; // [sp+58h] [-138h] BYREF
  int v144; // [sp+5Ch] [-134h]
  int *v145; // [sp+60h] [-130h]
  int v146; // [sp+64h] [-12Ch]

  v2 = &model->polygons[polygonNum];
  numEdges = v2->numEdges;
  v5 = polygonNum;
  v6 = 0;
  v7 = 0;
  v143 = 0;
  v8 = 1.0;
  v144 = numEdges / 2;
  if ( numEdges > 0 )
  {
    firstEdge = v2->firstEdge;
    polygonEdges = model->polygonEdges;
    edges = model->edges;
    vertices = model->vertices;
    do
    {
      v13 = v2->numEdges;
      v14 = v13 + v7 - 1;
      v15 = v13 / 2 + v7;
      v16 = polygonEdges[firstEdge + v14 % v13];
      v17 = v15 % v13;
      v18 = &edges[abs32(v16)];
      v19 = *(int *)((char *)v18->vertexNum + ((~v16 >> 29) & 4));
      v20 = *(int *)((char *)v18->vertexNum + ((v16 >> 29) & 4));
      __twllei(v13, 0);
      v21 = polygonEdges[firstEdge + v7];
      v22 = polygonEdges[firstEdge + (v15 - 1) % v13];
      v23 = polygonEdges[firstEdge + v15 % v13];
      v24 = (float)(vertices[v20].p.z - vertices[v19].p.z);
      v25 = (float)(vertices[v20].p.y - vertices[v19].p.y);
      __twllei(v13, 0);
      __twllei(v13, 0);
      v26 = &edges[abs32(v22)];
      __twlgei(v13 & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
      __twlgei(v13 & ~(__ROL4__(v15 - 1, 1) - 1), 0xFFFFFFFF);
      __twlgei(v13 & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
      v27 = &edges[abs32(v21)];
      v29 = (float)(vertices[v20].p.x - vertices[v19].p.x);
      v28 = &edges[abs32(v23)];
      v30 = *(int *)((char *)v27->vertexNum + ((~v21 >> 29) & 4));
      v31 = *(int *)((char *)v27->vertexNum + ((v21 >> 29) & 4));
      p_x = &vertices[v31].p.x;
      v33 = &vertices[v30].p.x;
      v34 = &vertices[*(int *)((char *)v26->vertexNum + ((~v22 >> 29) & 4))].p.x;
      v35 = &vertices[*(int *)((char *)v26->vertexNum + ((v22 >> 29) & 4))].p.x;
      v36 = &vertices[*(int *)((char *)v28->vertexNum + ((v23 >> 29) & 4))].p.x;
      v37 = &vertices[*(int *)((char *)v28->vertexNum + ((~v23 >> 29) & 4))].p.x;
      v38 = (float)(v33[1] - p_x[1]);
      v39 = (float)(v33[2] - p_x[2]);
      v40 = (float)(v35[2] - v34[2]);
      v41 = (float)(v35[1] - v34[1]);
      v42 = (float)(v37[2] - v36[2]);
      v43 = (float)(v37[1] - v36[1]);
      v45 = (float)(v36[1] - p_x[1]);
      v46 = (float)(v36[2] - p_x[2]);
      _FP20 = (float)((float)((float)((float)v24 * (float)v24)
                            + (float)((float)((float)v29 * (float)v29) + (float)((float)v25 * (float)v25)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      _FP19 = (float)((float)((float)((float)v39 * (float)v39)
                            + (float)((float)((float)(*v33 - *p_x) * (float)(*v33 - *p_x))
                                    + (float)((float)v38 * (float)v38)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      _FP18 = (float)((float)((float)((float)v40 * (float)v40)
                            + (float)((float)((float)(*v35 - *v34) * (float)(*v35 - *v34))
                                    + (float)((float)v41 * (float)v41)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm
      {
        fsel      f28, f20, f28, f13
        fsel      f27, f19, f27, f13
        fsel      f26, f18, f26, f13
      }
      v53 = __frsqrte(_FP28);
      v54 = __frsqrte(_FP27);
      v55 = __frsqrte(_FP26);
      v56 = (float)((float)-(float)((float)((float)((float)v53
                                                  * (float)((float)((float)((float)v24 * (float)v24)
                                                                  + (float)((float)((float)v29 * (float)v29)
                                                                          + (float)((float)v25 * (float)v25)))
                                                          * (float)0.5))
                                          * (float)v53)
                                  - (float)1.5)
                  * (float)v53);
      v57 = (float)((float)-(float)((float)((float)((float)v54
                                                  * (float)((float)((float)((float)v39 * (float)v39)
                                                                  + (float)((float)((float)(*v33 - *p_x)
                                                                                  * (float)(*v33 - *p_x))
                                                                          + (float)((float)v38 * (float)v38)))
                                                          * (float)0.5))
                                          * (float)v54)
                                  - (float)1.5)
                  * (float)v54);
      v58 = (float)((float)-(float)((float)((float)((float)v55
                                                  * (float)((float)((float)((float)v40 * (float)v40)
                                                                  + (float)((float)((float)(*v35 - *v34)
                                                                                  * (float)(*v35 - *v34))
                                                                          + (float)((float)v41 * (float)v41)))
                                                          * (float)0.5))
                                          * (float)v55)
                                  - (float)1.5)
                  * (float)v55);
      v59 = (float)((float)-(float)((float)((float)((float)v56
                                                  * (float)((float)((float)((float)v24 * (float)v24)
                                                                  + (float)((float)((float)v29 * (float)v29)
                                                                          + (float)((float)v25 * (float)v25)))
                                                          * (float)0.5))
                                          * (float)v56)
                                  - (float)1.5)
                  * (float)v56);
      v60 = (float)((float)-(float)((float)((float)((float)v57
                                                  * (float)((float)((float)((float)v39 * (float)v39)
                                                                  + (float)((float)((float)(*v33 - *p_x)
                                                                                  * (float)(*v33 - *p_x))
                                                                          + (float)((float)v38 * (float)v38)))
                                                          * (float)0.5))
                                          * (float)v57)
                                  - (float)1.5)
                  * (float)v57);
      v61 = (float)((float)-(float)((float)((float)((float)v58
                                                  * (float)((float)((float)((float)v40 * (float)v40)
                                                                  + (float)((float)((float)(*v35 - *v34)
                                                                                  * (float)(*v35 - *v34))
                                                                          + (float)((float)v41 * (float)v41)))
                                                          * (float)0.5))
                                          * (float)v58)
                                  - (float)1.5)
                  * (float)v58);
      v62 = (float)((float)-(float)((float)((float)((float)v59
                                                  * (float)((float)((float)((float)v24 * (float)v24)
                                                                  + (float)((float)((float)v29 * (float)v29)
                                                                          + (float)((float)v25 * (float)v25)))
                                                          * (float)0.5))
                                          * (float)v59)
                                  - (float)1.5)
                  * (float)v59);
      v63 = (float)((float)-(float)((float)((float)((float)v60
                                                  * (float)((float)((float)((float)v39 * (float)v39)
                                                                  + (float)((float)((float)(*v33 - *p_x)
                                                                                  * (float)(*v33 - *p_x))
                                                                          + (float)((float)v38 * (float)v38)))
                                                          * (float)0.5))
                                          * (float)v60)
                                  - (float)1.5)
                  * (float)v60);
      v64 = (float)((float)-(float)((float)((float)((float)v61
                                                  * (float)((float)((float)((float)v40 * (float)v40)
                                                                  + (float)((float)((float)(*v35 - *v34)
                                                                                  * (float)(*v35 - *v34))
                                                                          + (float)((float)v41 * (float)v41)))
                                                          * (float)0.5))
                                          * (float)v61)
                                  - (float)1.5)
                  * (float)v61);
      v65 = (float)((float)v62 * (float)v29);
      v66 = (float)((float)v62 * (float)v25);
      v67 = (float)((float)v62 * (float)v24);
      v68 = (float)((float)v63 * (float)(*v33 - *p_x));
      v69 = (float)((float)v63 * (float)(v33[1] - p_x[1]));
      v70 = (float)((float)v63 * (float)(v33[2] - p_x[2]));
      v44 = v36;
      v71 = (float)((float)v64 * (float)(v35[2] - v34[2]));
      v72 = (float)((float)v64 * (float)(*v35 - *v34));
      v73 = (float)((float)v64 * (float)(v35[1] - v34[1]));
      _FP26 = (float)((float)((float)((float)v42 * (float)v42)
                            + (float)((float)((float)(*v37 - *v36) * (float)(*v37 - *v36))
                                    + (float)((float)v43 * (float)v43)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      _FP21 = (float)((float)((float)((float)v46 * (float)v46)
                            + (float)((float)((float)(*v44 - *p_x) * (float)(*v44 - *p_x))
                                    + (float)((float)v45 * (float)v45)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f27, f26, f27, f13 }
      __asm { fsel      f28, f21, f28, f13 }
      v78 = __frsqrte(_FP27);
      v79 = __frsqrte(_FP28);
      v80 = (float)((float)-(float)((float)((float)((float)v78
                                                  * (float)((float)((float)((float)v42 * (float)v42)
                                                                  + (float)((float)((float)(*v37 - *v36)
                                                                                  * (float)(*v37 - *v36))
                                                                          + (float)((float)v43 * (float)v43)))
                                                          * (float)0.5))
                                          * (float)v78)
                                  - (float)1.5)
                  * (float)v78);
      v81 = (float)((float)-(float)((float)((float)((float)v79
                                                  * (float)((float)((float)((float)v46 * (float)v46)
                                                                  + (float)((float)((float)(*v44 - *p_x)
                                                                                  * (float)(*v44 - *p_x))
                                                                          + (float)((float)v45 * (float)v45)))
                                                          * (float)0.5))
                                          * (float)v79)
                                  - (float)1.5)
                  * (float)v79);
      v82 = (float)((float)-(float)((float)((float)((float)v80
                                                  * (float)((float)((float)((float)v42 * (float)v42)
                                                                  + (float)((float)((float)(*v37 - *v36)
                                                                                  * (float)(*v37 - *v36))
                                                                          + (float)((float)v43 * (float)v43)))
                                                          * (float)0.5))
                                          * (float)v80)
                                  - (float)1.5)
                  * (float)v80);
      v83 = (float)((float)-(float)((float)((float)((float)v81
                                                  * (float)((float)((float)((float)v46 * (float)v46)
                                                                  + (float)((float)((float)(*v44 - *p_x)
                                                                                  * (float)(*v44 - *p_x))
                                                                          + (float)((float)v45 * (float)v45)))
                                                          * (float)0.5))
                                          * (float)v81)
                                  - (float)1.5)
                  * (float)v81);
      v84 = (float)((float)-(float)((float)((float)((float)v82
                                                  * (float)((float)((float)((float)v42 * (float)v42)
                                                                  + (float)((float)((float)(*v37 - *v36)
                                                                                  * (float)(*v37 - *v36))
                                                                          + (float)((float)v43 * (float)v43)))
                                                          * (float)0.5))
                                          * (float)v82)
                                  - (float)1.5)
                  * (float)v82);
      v85 = (float)((float)-(float)((float)((float)((float)v83
                                                  * (float)((float)((float)((float)v46 * (float)v46)
                                                                  + (float)((float)((float)(*v44 - *p_x)
                                                                                  * (float)(*v44 - *p_x))
                                                                          + (float)((float)v45 * (float)v45)))
                                                          * (float)0.5))
                                          * (float)v83)
                                  - (float)1.5)
                  * (float)v83);
      v87 = (float)((float)((float)((float)v85 * (float)(*v44 - *p_x)) * (float)v68)
                  + (float)((float)((float)v85 * (float)(v44[2] - p_x[2])) * (float)v70));
      v88 = (float)((float)((float)((float)v85 * (float)(*v44 - *p_x)) * (float)v65)
                  + (float)((float)((float)v85 * (float)(v44[2] - p_x[2])) * (float)v67));
      v89 = (float)((float)((float)((float)v85 * (float)(*v44 - *p_x)) * (float)v72)
                  + (float)((float)((float)v85 * (float)(v44[2] - p_x[2])) * (float)v71));
      v90 = (float)((float)((float)((float)v85 * (float)(*v44 - *p_x)) * (float)((float)v84 * (float)(*v37 - *v36)))
                  + (float)((float)((float)v85 * (float)(v44[2] - p_x[2]))
                          * (float)((float)v84 * (float)(v37[2] - v36[2]))));
      v86 = (float)((float)v85 * (float)(v36[1] - p_x[1]));
      _FP4 = (float)((float)((float)((float)v86 * (float)v66) + (float)v88)
                   - (float)((float)((float)v86 * (float)v69) + (float)v87));
      _FP3 = (float)((float)-(float)((float)((float)v86 * (float)v73) + (float)v89)
                   - (float)-(float)((float)((float)v86 * (float)((float)v84 * (float)(v37[1] - v36[1]))) + (float)v90));
      __asm
      {
        fsel      f2, f4, f8, f7
        fsel      f1, f3, f6, f5
      }
      _FP11 = (float)((float)_FP2 - (float)_FP1);
      __asm { fsel      f11, f11, f2, f1 }
      if ( _FP11 < v8 )
      {
        v6 = v7;
        v8 = _FP11;
        v144 = v17;
      }
      ++v7;
    }
    while ( v7 < v2->numEdges );
    v5 = polygonNum;
    v143 = v6;
  }
  v97 = v2->firstEdge;
  v98 = model->polygonEdges;
  v99 = model->edges;
  HIDWORD(v101) = v98[v97 + v6];
  v100 = v98[v97 + v144];
  LODWORD(v101) = model->maxEdges;
  v102 = v99[abs32(SHIDWORD(v101))].vertexNum[HIDWORD(v101) >> 31];
  v103 = v99[abs32(v100)].vertexNum[v100 >> 31];
  if ( model->numEdges >= (int)v101 )
  {
    HIDWORD(v101) = &unk_821B0000;
    v104 = (int)(float)((float)((float)v101 * (float)1.5) + (float)1.0);
    model->maxEdges = v104;
    v105 = (cm_buildEdge_t *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(1703) : TAG_COLLISION",
                               size: 32 * v104,
                               tag: TAG_COLLISION,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    model->edges = v105;
    memcpy(Dst: v105, Src: v99, Size: 32 * model->numEdges);
    idMem::Free(this: &mem, ptr: v99, align: ALIGN_16);
    idHashIndex::ResizeIndex(this: buildData.cm_edgeHash, newIndexSize: model->maxEdges);
  }
  v106 = &model->edges[model->numEdges];
  v106->vertexNum[0] = v102;
  v106->vertexNum[1] = v103;
  v106->internal = 0;
  v106->numUsers = 2;
  v106->normal.z = 0.0;
  v106->normal.y = 0.0;
  v106->normal.x = 0.0;
  v106->checkCount = 0;
  cm_edgeHash = buildData.cm_edgeHash;
  v108 = model->numEdges;
  v109 = (v103 + v102) & buildData.cm_edgeHash->hashMask;
  indexSize = buildData.cm_edgeHash->indexSize;
  if ( buildData.cm_edgeHash->hash == idHashIndex::INVALID_INDEX )
  {
    if ( v108 >= indexSize )
      indexSize = v108 + 1;
    idHashIndex::Allocate(
      this: buildData.cm_edgeHash,
      newHashSize: buildData.cm_edgeHash->hashSize,
      newIndexSize: indexSize);
  }
  else if ( v108 >= indexSize )
  {
    idHashIndex::ResizeIndex(this: buildData.cm_edgeHash, newIndexSize: v108 + 1);
  }
  v111 = 0;
  v112 = cm_edgeHash->hashMask & v109;
  cm_edgeHash->indexChain[v108] = cm_edgeHash->hash[v112];
  cm_edgeHash->hash[v112] = v108;
  ++model->numEdges;
  do
  {
    v146 = v2->numEdges;
    v113 = (int *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                    size: 4 * v146,
                    tag: TAG_TEMP,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    v114 = v113;
    v145 = v113;
    _FP31 = 1.0e30;
    _FP28 = -1.0e30;
    v117 = model->numEdges;
    _FP29 = 1.0e30;
    _FP30 = 1.0e30;
    _FP26 = -1.0e30;
    _FP27 = -1.0e30;
    if ( v111 != 0 )
      v122 = v117 - 1;
    else
      v122 = 1 - v117;
    *v113 = v122;
    v123 = 1;
    v124 = 0;
    if ( v2->numEdges > 0 )
    {
      v125 = v113;
      v126 = *(&v143 + v111);
      v127 = *(int *)((char *)&v143 + ((_cntlzw(v111) >> 3) & 4));
      do
      {
        v128 = v2->numEdges;
        v129 = (v126 + v124) % v128;
        __twllei(v128, 0);
        __twlgei(v128 & ~(__ROL4__(v126 + v124, 1) - 1), 0xFFFFFFFF);
        if ( v129 == v127 )
          break;
        ++v124;
        ++v123;
        v130 = model->polygonEdges[v2->firstEdge + v129];
        *++v125 = v130;
        v131 = abs32(v130);
        ++model->edges[v131].numUsers;
        v132 = &model->vertices[model->edges[v131].vertexNum[v130 >> 31]];
        _FP8 = (float)((float)_FP30 - v132->p.y);
        _FP9 = (float)((float)_FP31 - v132->p.x);
        _FP7 = (float)((float)_FP29 - v132->p.z);
        _FP6 = (float)(v132->p.y - (float)_FP27);
        _FP5 = (float)(v132->p.x - (float)_FP28);
        _FP4 = (float)(v132->p.z - (float)_FP26);
        __asm
        {
          fsel      f30, f8, f0, f30
          fsel      f31, f9, f10, f31
          fsel      f29, f7, f13, f29
          fsel      f27, f6, f0, f27
          fsel      f28, f5, f10, f28
          fsel      f26, f4, f13, f26
        }
      }
      while ( v124 < v2->numEdges );
    }
    v139 = idCollisionModelBuilder::AllocPolygon(model, numEdges: v123);
    polygons = model->polygons;
    v139->bounds.b[0].x = _FP31;
    v139->bounds.b[0].y = _FP30;
    v139->bounds.b[0].z = _FP29;
    v139->bounds.b[1].x = _FP28;
    v139->bounds.b[1].y = _FP27;
    v139->bounds.b[1].z = _FP26;
    v141 = v139->firstEdge;
    v2 = &polygons[v5];
    v142 = v139;
    v139->contents = v2->contents;
    v139->material = v2->material;
    v139->primitiveNum = v2->primitiveNum;
    v139->plane.a = v2->plane.a;
    v139->plane.b = v2->plane.b;
    v139->plane.c = v2->plane.c;
    v139->plane.d = v2->plane.d;
    v139->numEdges = v123;
    memcpy(Dst: &model->polygonEdges[v141], Src: v114, Size: 4 * v123);
    idCollisionModelBuilder::FilterPolygonIntoTree_r(model, node: model->node, pref: nullptr, p: v142);
    idMem::Free(this: &mem, ptr: v114, align: ALIGN_16);
    ++v111;
  }
  while ( v111 < 2 );
  idCollisionModelBuilder::RemovePolygon(model, node: model->node, polygonNum: v5);
  v2->numEdges = 0;
}


// ========================================================================
// __unwind$241012
// EA  : 0x825CA9DC
// RVA : 0x005CA9DC
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_241012()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 400 + 96));
}


// ========================================================================
// ?SplitPolygons@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@@Z
// EA  : 0x825CAA08
// RVA : 0x005CAA08
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::SplitPolygons(cm_buildModel_t *model)
{
  int v2; // r30
  int v3; // r29

  v2 = 0;
  if ( model->numPolygons > 0 )
  {
    v3 = 0;
    do
    {
      if ( model->polygons[v3].numEdges > 16 )
        idCollisionModelBuilder::SplitPolygon(model, polygonNum: v2);
      ++v2;
      ++v3;
    }
    while ( v2 < model->numPolygons );
  }
}


// ========================================================================
// ?CreateAxialBSPTree@idCollisionModelBuilder@@CAPAUcm_buildNode_t@@PAUcm_buildModel_t@@@Z
// EA  : 0x825CAA68
// RVA : 0x005CAA68
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

cm_buildNode_t *__fastcall idCollisionModelBuilder::CreateAxialBSPTree(cm_buildModel_t *model)
{
  cm_buildPolygonRefBlock_t *i; // r4
  cm_buildPolytopeRefBlock_t *j; // r4
  cm_buildNodeBlock_t *k; // r4
  cm_buildNode_t *v5; // r3
  int v6; // r29
  int v7; // r30
  cm_buildPolygon_t *v8; // r10
  float *p_bounds; // r11
  double y; // fp11
  double z; // fp10
  double x; // fp9
  double v14; // fp8
  double v15; // fp7
  int v27; // r29
  int v28; // r30
  cm_buildPolytope_t *v29; // r10
  float *v30; // r11
  double v32; // fp11
  double v33; // fp10
  double v34; // fp9
  double v35; // fp8
  double v36; // fp7
  cm_buildNode_t *AxialBSPTree_r; // r3
  int v49; // r7
  int v51; // [sp+50h] [-30h] BYREF
  int v52; // [sp+54h] [-2Ch] BYREF

  for ( i = model->polygonRefBlocks; i != nullptr; i = model->polygonRefBlocks )
  {
    model->polygonRefBlocks = i->next;
    idMem::Free(this: &mem, ptr: i, align: ALIGN_16);
  }
  for ( j = model->polytopeRefBlocks; j != nullptr; j = model->polytopeRefBlocks )
  {
    model->polytopeRefBlocks = j->next;
    idMem::Free(this: &mem, ptr: j, align: ALIGN_16);
  }
  for ( k = model->nodeBlocks; k != nullptr; k = model->nodeBlocks )
  {
    model->nodeBlocks = k->next;
    idMem::Free(this: &mem, ptr: k, align: ALIGN_16);
  }
  v5 = idCollisionModelBuilder::AllocNode(model, blockSize: 256);
  model->node = v5;
  v6 = 0;
  v5->bounds.b[0].z = 1.0e30;
  v5->bounds.b[0].y = 1.0e30;
  v5->bounds.b[0].x = 1.0e30;
  v5->bounds.b[1].z = -1.0e30;
  v5->bounds.b[1].y = -1.0e30;
  v5->bounds.b[1].x = -1.0e30;
  if ( model->numPolygons > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &model->polygons[v7];
      if ( v8->numEdges != 0 )
      {
        p_bounds = (float *)&model->node->bounds;
        _FP12 = (float)(*p_bounds - v8->bounds.b[0].x);
        y = model->node->bounds.b[0].y;
        z = model->node->bounds.b[0].z;
        x = model->node->bounds.b[1].x;
        v14 = model->node->bounds.b[1].y;
        v15 = model->node->bounds.b[1].z;
        __asm { fsel      f6, f12, f0, f13 }
        *p_bounds = _FP6;
        _FP4 = (float)((float)y - v8->bounds.b[0].y);
        __asm { fsel      f3, f4, f5, f11 }
        p_bounds[1] = _FP3;
        _FP1 = (float)((float)z - v8->bounds.b[0].z);
        __asm { fsel      f0, f1, f2, f10 }
        p_bounds[2] = _FP0;
        _FP12 = (float)(v8->bounds.b[1].x - (float)x);
        __asm { fsel      f11, f12, f13, f9 }
        p_bounds[3] = _FP11;
        _FP9 = (float)(v8->bounds.b[1].y - (float)v14);
        __asm { fsel      f8, f9, f10, f8 }
        p_bounds[4] = _FP8;
        _FP5 = (float)(v8->bounds.b[1].z - (float)v15);
        __asm { fsel      f4, f5, f6, f7 }
        p_bounds[5] = _FP4;
        idCollisionModelBuilder::FilterPolygonIntoTree_r(
          model,
          node: model->node,
          pref: nullptr,
          p: &model->polygons[v7]);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < model->numPolygons );
  }
  v27 = 0;
  if ( model->numPolytopes > 0 )
  {
    v28 = 0;
    do
    {
      v29 = &model->polytopes[v28];
      if ( v29->numPlanes != 0 )
      {
        v30 = (float *)&model->node->bounds;
        _FP12 = (float)(*v30 - v29->bounds.b[0].x);
        v32 = model->node->bounds.b[0].y;
        v33 = model->node->bounds.b[0].z;
        v34 = model->node->bounds.b[1].x;
        v35 = model->node->bounds.b[1].y;
        v36 = model->node->bounds.b[1].z;
        __asm { fsel      f6, f12, f0, f13 }
        *v30 = _FP6;
        _FP4 = (float)((float)v32 - v29->bounds.b[0].y);
        __asm { fsel      f3, f4, f5, f11 }
        v30[1] = _FP3;
        _FP1 = (float)((float)v33 - v29->bounds.b[0].z);
        __asm { fsel      f0, f1, f2, f10 }
        v30[2] = _FP0;
        _FP12 = (float)(v29->bounds.b[1].x - (float)v34);
        __asm { fsel      f11, f12, f13, f9 }
        v30[3] = _FP11;
        _FP9 = (float)(v29->bounds.b[1].y - (float)v35);
        __asm { fsel      f8, f9, f10, f8 }
        v30[4] = _FP8;
        _FP5 = (float)(v29->bounds.b[1].z - (float)v36);
        __asm { fsel      f4, f5, f6, f7 }
        v30[5] = _FP4;
        idCollisionModelBuilder::FilterPolytopeIntoTree_r(
          model,
          node: model->node,
          pref: nullptr,
          b: &model->polytopes[v28]);
      }
      ++v27;
      ++v28;
    }
    while ( v27 < model->numPolytopes );
  }
  AxialBSPTree_r = idCollisionModelBuilder::CreateAxialBSPTree_r(model, node: model->node);
  v52 = 0;
  model->node = AxialBSPTree_r;
  v51 = 0;
  CM_R_TestOptimisation(node: AxialBSPTree_r, numSavedPolygonIndices: &v52, numSavedPolytopeIndices: &v51);
  return (cm_buildNode_t *)v49;
}


// ========================================================================
// ?SetupHash@idCollisionModelBuilder@@CAXXZ
// EA  : 0x825CAD30
// RVA : 0x005CAD30
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

static void __fastcall idCollisionModelBuilder::SetupHash()
{
  idHashIndex *v0; // r3
  idHashIndex *v1; // r30
  idHashIndex *v2; // r3
  idHashIndex *v3; // r30
  cm_windingList_t *v4; // r3
  cm_windingList_t *v5; // r30
  cm_windingList_t *v6; // r3
  cm_windingList_t *v7; // r30
  cm_windingList_t *v8; // r3
  cm_windingList_t *v9; // r30

  if ( buildData.cm_vertexHash == nullptr )
  {
    v0 = (idHashIndex *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x20u,
                          tag: TAG_COLLISION,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v1 = v0;
    if ( v0 != nullptr )
    {
      v0->memTag = TAG_HASHINDEX;
      idHashIndex::InternalInit(this: v0, initialHashSize: 4096, initialIndexSize: 1024);
    }
    else
    {
      v1 = nullptr;
    }
    buildData.cm_vertexHash = v1;
  }
  if ( buildData.cm_edgeHash == nullptr )
  {
    v2 = (idHashIndex *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x20u,
                          tag: TAG_COLLISION,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v3 = v2;
    if ( v2 != nullptr )
    {
      v2->memTag = TAG_HASHINDEX;
      idHashIndex::InternalInit(this: v2, initialHashSize: 0x4000, initialIndexSize: 1024);
    }
    else
    {
      v3 = nullptr;
    }
    buildData.cm_edgeHash = v3;
  }
  if ( buildData.cm_windingList == nullptr )
  {
    v4 = (cm_windingList_t *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x51040u,
                               tag: TAG_COLLISION,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    v5 = v4;
    if ( v4 != nullptr )
      `eh vector constructor iterator'(
        ptr: v4->w,
        size: 0x510u,
        count: 256,
        pCtor: (void (__fastcall *)(void *))idFixedWinding::idFixedWinding,
        pDtor: (void (__fastcall *)(void *))idFixedWinding::~idFixedWinding);
    else
      v5 = nullptr;
    buildData.cm_windingList = v5;
  }
  if ( buildData.cm_outList == nullptr )
  {
    v6 = (cm_windingList_t *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x51040u,
                               tag: TAG_COLLISION,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    v7 = v6;
    if ( v6 != nullptr )
      `eh vector constructor iterator'(
        ptr: v6->w,
        size: 0x510u,
        count: 256,
        pCtor: (void (__fastcall *)(void *))idFixedWinding::idFixedWinding,
        pDtor: (void (__fastcall *)(void *))idFixedWinding::~idFixedWinding);
    else
      v7 = nullptr;
    buildData.cm_outList = v7;
  }
  if ( buildData.cm_tmpList == nullptr )
  {
    v8 = (cm_windingList_t *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x51040u,
                               tag: TAG_COLLISION,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    v9 = v8;
    if ( v8 != nullptr )
      `eh vector constructor iterator'(
        ptr: v8->w,
        size: 0x510u,
        count: 256,
        pCtor: (void (__fastcall *)(void *))idFixedWinding::idFixedWinding,
        pDtor: (void (__fastcall *)(void *))idFixedWinding::~idFixedWinding);
    else
      v9 = nullptr;
    buildData.cm_tmpList = v9;
  }
}


// ========================================================================
// __unwind$241862
// EA  : 0x825CAF54
// RVA : 0x005CAF54
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_241862()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_COLLISION);
}


// ========================================================================
// __unwind$241863
// EA  : 0x825CAF80
// RVA : 0x005CAF80
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_241863()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_COLLISION);
}


// ========================================================================
// __unwind$241864
// EA  : 0x825CAFAC
// RVA : 0x005CAFAC
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_241864()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_COLLISION);
}


// ========================================================================
// __unwind$241865
// EA  : 0x825CAFD8
// RVA : 0x005CAFD8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_241865()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_COLLISION);
}


// ========================================================================
// __unwind$241866
// EA  : 0x825CB004
// RVA : 0x005CB004
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_241866()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_COLLISION);
}


// ========================================================================
// ?SetupBuildGroups@idCollisionModelBuilder@@CAHAAVidCollisionModelGeometry@1@@Z
// EA  : 0x825CB030
// RVA : 0x005CB030
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::SetupBuildGroups(
        idCollisionModelBuilder::idCollisionModelGeometry *collisionModelGeometry)
{
  int v2; // r22
  int v3; // r18
  int v4; // r19
  idCollisionModelBuilder::idStaticModelGeometry *v5; // r28
  LEAPCORE::CXboxRendererConnection *mapModel; // r3
  int v7; // r30
  int v8; // r31
  char v9; // r23
  int num; // r27
  int v11; // r29
  int v12; // r30
  int v13; // r31
  int v14; // r11
  int v15; // r30
  int v16; // r26
  int v17; // r29
  idStaticModelSurface *v18; // r31

  v2 = 1;
  v3 = 0;
  if ( collisionModelGeometry->models.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = &collisionModelGeometry->models.list[v4];
      mapModel = (LEAPCORE::CXboxRendererConnection *)v5->mapModel;
      if ( mapModel != nullptr )
      {
        v7 = 0;
        if ( (int)idLobby::PeerIndexOnHost(this: mapModel) > 0 )
        {
          v8 = 0;
          do
          {
            ++v7;
            v5->primitiveGroupNumbers.list[v8++] = 0;
          }
          while ( v7 < (int)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)v5->mapModel) );
        }
      }
      else
      {
        v9 = 0;
        if ( v5->staticModel != nullptr )
          num = v5->staticModel->surfaces.num;
        else
          num = v5->renderModel->surfaces.num;
        v11 = 0;
        if ( num > 0 )
        {
          v12 = 0;
          v13 = 0;
          while ( 1 )
          {
            v14 = v5->staticModel != nullptr
                ? (int)&v5->staticModel->surfaces.list[v13]
                : (int)&v5->renderModel->surfaces.list[v12];
            if ( (idParmBlock::GetInteger(this: (idParmBlock *)(*(_DWORD *)v14 + 84), parm: rp->surfaceFlags) & 0x40) != 0 )
              break;
            ++v11;
            ++v13;
            ++v12;
            if ( v11 >= num )
              goto LABEL_20;
          }
          v9 = 1;
LABEL_20:
          v15 = 0;
          v16 = 0;
          v17 = 0;
          do
          {
            if ( v5->staticModel != nullptr )
              v18 = &v5->staticModel->surfaces.list[v17];
            else
              v18 = (idStaticModelSurface *)&v5->renderModel->surfaces.list[v16];
            if ( (idParmBlock::GetInteger(this: &v18->material->parmBlock, parm: rp->contentFlags) & 0xEBFFFFFF) != 0 )
            {
              if ( v9 == 0
                || (idParmBlock::GetInteger(this: &v18->material->parmBlock, parm: rp->surfaceFlags) & 0x40) != 0 )
              {
                if ( collisionModelGeometry->allowDiscrete
                  && idParmBlock::GetInteger(this: &v18->material->parmBlock, parm: rp->discrete) != 0 )
                {
                  v5->primitiveGroupNumbers.list[v15] = v2++;
                }
                else
                {
                  v5->primitiveGroupNumbers.list[v15] = 0;
                }
              }
              else
              {
                v5->primitiveGroupNumbers.list[v15] = -1;
              }
            }
            else
            {
              v5->primitiveGroupNumbers.list[v15] = -1;
            }
            --num;
            ++v17;
            ++v16;
            ++v15;
          }
          while ( num != 0 );
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 < collisionModelGeometry->models.num );
  }
  return v2;
}


// ========================================================================
// ?IsStaticRenderModel@idCollisionModelBuilder@@SA_NPBD@Z
// EA  : 0x825CB258
// RVA : 0x005CB258
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::IsStaticRenderModel(const char *fileName)
{
  idStr *v1; // r3
  int v2; // r3
  unsigned __int8 v3; // r11
  int v4; // r30
  idStr v6; // [sp+50h] [-60h] BYREF
  idStr v7; // [sp+70h] [-40h] BYREF

  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  v1 = idStr::idStr(this: &v7, text: fileName);
  idStr::ExtractFileExtension(this: v1, dest: &v6);
  idStr::FreeData(this: &v7);
  if ( idStr::Icmp(s1: v6.data, s2: "ase") == 0
    || idStr::Icmp(s1: v6.data, s2: "lwo") == 0
    || idStr::Icmp(s1: v6.data, s2: "obj") == 0
    || idStr::Icmp(s1: v6.data, s2: "model") == 0
    || (v2 = idStr::Icmp(s1: v6.data, s2: "bmodel"), v3 = 0, v2 == 0) )
  {
    v3 = 1;
  }
  v4 = v3;
  idStr::FreeData(this: &v6);
  return v4;
}


// ========================================================================
// __unwind$242110
// EA  : 0x825CB350
// RVA : 0x005CB350
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_242110()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$242111
// EA  : 0x825CB378
// RVA : 0x005CB378
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_242111()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// ?ChoppedAwayByProcBSP@idCollisionModelBuilder@@CAHABVidFixedWinding@@ABVidPlane@@H@Z
// EA  : 0x825CB738
// RVA : 0x005CB738
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::ChoppedAwayByProcBSP(
        const idFixedWinding *w,
        idFixedWinding *plane,
        char contents)
{
  int v4; // r30
  idVec3 v6; // [sp+50h] [-560h] BYREF
  idBounds v7; // [sp+60h] [-550h] BYREF
  idFixedWinding v8; // [sp+80h] [-530h] BYREF

  v8.numPoints = 0;
  v8.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
  v8.p = v8.data;
  v8.allocedSize = 64;
  if ( buildData.procNodes != nullptr && buildData.numProcNodes != 0 )
  {
    if ( (contents & 1) != 0 )
    {
      idFixedWinding::operator=(this: &v8, __that: w);
      idWinding::GetBounds(this: &v8, bounds: &v7);
      v6.y = v7.b[0].y + (float)((float)(v7.b[1].y - v7.b[0].y) * (float)0.5);
      v6.x = v7.b[0].x + (float)((float)(v7.b[1].x - v7.b[0].x) * (float)0.5);
      v6.z = v7.b[0].z + (float)((float)(v7.b[1].z - v7.b[0].z) * (float)0.5);
      v4 = idCollisionModelBuilder::ChoppedAwayByProcBSP_r(
             nodeNum: 0,
             w: &v8,
             normal: plane,
             origin: &v6,
             radius: (float)((float)__fsqrts((float)((float)((float)((float)(v7.b[1].z - v7.b[0].z) * (float)0.5)
                                                   * (float)((float)(v7.b[1].z - v7.b[0].z) * (float)0.5))
                                           + (float)((float)((float)((float)(v7.b[1].x - v7.b[0].x) * (float)0.5)
                                                           * (float)((float)(v7.b[1].x - v7.b[0].x) * (float)0.5))
                                                   + (float)((float)((float)(v7.b[1].y - v7.b[0].y) * (float)0.5)
                                                           * (float)((float)(v7.b[1].y - v7.b[0].y) * (float)0.5)))))
                   + (float)0.1));
      idFixedWinding::~idFixedWinding(this: &v8);
      return v4;
    }
    idFixedWinding::~idFixedWinding(this: &v8);
  }
  else
  {
    v8.p = nullptr;
    v8.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
    idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
  }
  return 0;
}


// ========================================================================
// __unwind$242687
// EA  : 0x825CB89C
// RVA : 0x005CB89C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_242687()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 1456 + 128));
}


// ========================================================================
// ?WindingOutsidePolytopes@idCollisionModelBuilder@@CAPAVidFixedWinding@@PAUcm_buildModel_t@@PAV2@ABVidPlane@@HH@Z
// EA  : 0x825CB8C8
// RVA : 0x005CB8C8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

idFixedWinding *__fastcall idCollisionModelBuilder::WindingOutsidePolytopes(
        cm_buildModel_t *model,
        idFixedWinding *w,
        idFixedWinding *plane,
        int contents,
        int primitiveNum)
{
  float *p_bounds; // r7
  int v11; // r9
  int v12; // r8
  idVec5 *v13; // r10
  float *v14; // r6
  double y; // fp11
  double z; // fp10
  double x; // fp9
  double v19; // fp8
  double v20; // fp7
  float *p_numWindings; // r9
  double v33; // fp8
  double v34; // fp6
  cm_windingList_t *cm_windingList; // r11
  double v36; // fp6
  double v37; // fp3
  double v38; // fp1
  idBounds *v39; // r11
  double v40; // fp10
  double v41; // fp8
  idVec3 *v42; // r10
  double v43; // fp1
  double v44; // fp0
  idVec3 *p_normal; // r3
  cm_buildNode_t *node; // r5
  cm_windingList_t *v47; // r11
  int numWindings; // r10
  int v50; // r25
  int v51; // r27
  int v52; // r30

  p_bounds = (float *)&buildData.cm_windingList->bounds;
  v11 = 0;
  buildData.cm_windingList->bounds.b[0].z = 1.0e30;
  p_bounds[1] = 1.0e30;
  *p_bounds = 1.0e30;
  p_bounds[5] = -1.0e30;
  p_bounds[4] = -1.0e30;
  p_bounds[3] = -1.0e30;
  if ( w->numPoints > 0 )
  {
    v12 = 0;
    do
    {
      ++v11;
      v13 = &w->p[v12];
      v14 = (float *)&buildData.cm_windingList->bounds;
      ++v12;
      _FP12 = (float)(buildData.cm_windingList->bounds.b[0].x - v13->x);
      y = buildData.cm_windingList->bounds.b[0].y;
      z = buildData.cm_windingList->bounds.b[0].z;
      x = buildData.cm_windingList->bounds.b[1].x;
      v19 = buildData.cm_windingList->bounds.b[1].y;
      v20 = buildData.cm_windingList->bounds.b[1].z;
      __asm { fsel      f6, f12, f13, f0 }
      buildData.cm_windingList->bounds.b[0].x = _FP6;
      _FP4 = (float)((float)y - v13->y);
      __asm { fsel      f3, f4, f5, f11 }
      v14[1] = _FP3;
      _FP1 = (float)((float)z - v13->z);
      __asm { fsel      f0, f1, f2, f10 }
      v14[2] = _FP0;
      _FP12 = (float)(v13->x - (float)x);
      __asm { fsel      f11, f12, f13, f9 }
      v14[3] = _FP11;
      _FP9 = (float)(v13->y - (float)v19);
      __asm { fsel      f8, f9, f10, f8 }
      v14[4] = _FP8;
      _FP5 = (float)(v13->z - (float)v20);
      __asm { fsel      f4, f5, f6, f7 }
      v14[5] = _FP4;
    }
    while ( v11 < w->numPoints );
  }
  p_numWindings = (float *)&buildData.cm_windingList->numWindings;
  v33 = (float)(p_numWindings[82953] - p_numWindings[82950]);
  v34 = (float)(p_numWindings[82952] - p_numWindings[82949]);
  buildData.cm_windingList->origin.x = (float)(buildData.cm_windingList->bounds.b[1].x
                                             - buildData.cm_windingList->bounds.b[0].x)
                                     * (float)0.5;
  p_numWindings[82956] = (float)v33 * (float)0.5;
  p_numWindings[82955] = (float)v34 * (float)0.5;
  buildData.cm_windingList->radius = (float)__fsqrts((float)((float)(buildData.cm_windingList->origin.z
                                                                   * buildData.cm_windingList->origin.z)
                                                           + (float)((float)(buildData.cm_windingList->origin.x
                                                                           * buildData.cm_windingList->origin.x)
                                                                   + (float)(buildData.cm_windingList->origin.y
                                                                           * buildData.cm_windingList->origin.y))))
                                   + (float)0.1;
  cm_windingList = buildData.cm_windingList;
  v36 = buildData.cm_windingList->origin.z;
  v37 = buildData.cm_windingList->bounds.b[0].z;
  v38 = (float)(cm_windingList->origin.y + cm_windingList->bounds.b[0].y);
  buildData.cm_windingList->origin.x = buildData.cm_windingList->origin.x + buildData.cm_windingList->bounds.b[0].x;
  cm_windingList->origin.y = v38;
  cm_windingList->origin.z = (float)v36 + (float)v37;
  v39 = &buildData.cm_windingList->bounds;
  v40 = buildData.cm_windingList->bounds.b[0].y;
  v41 = (float)(buildData.cm_windingList->bounds.b[0].z - (float)0.1);
  buildData.cm_windingList->bounds.b[0].x = buildData.cm_windingList->bounds.b[0].x - (float)0.1;
  v39->b[0].y = (float)v40 - (float)0.1;
  v39->b[0].z = v41;
  v42 = &buildData.cm_windingList->bounds.b[1];
  v43 = (float)(buildData.cm_windingList->bounds.b[1].y + (float)0.1);
  v44 = (float)(buildData.cm_windingList->bounds.b[1].z + (float)0.1);
  buildData.cm_windingList->bounds.b[1].x = buildData.cm_windingList->bounds.b[1].x + (float)0.1;
  v42->y = v43;
  v42->z = v44;
  idFixedWinding::operator=(this: buildData.cm_windingList->w, __that: w);
  buildData.cm_windingList->numWindings = 1;
  p_normal = &buildData.cm_windingList->normal;
  p_normal->x = *(float *)&plane->__vftable;
  p_normal->y = *(float *)&plane->numPoints;
  p_normal->z = *(float *)&plane->p;
  buildData.cm_windingList->contents = contents;
  buildData.cm_windingList->primitiveNum = primitiveNum;
  node = model->node;
  ++model->checkCount;
  idCollisionModelBuilder::ChopWindingListWithTreePolytopes_r(list: buildData.cm_windingList, model, node);
  v47 = buildData.cm_windingList;
  numWindings = buildData.cm_windingList->numWindings;
  if ( buildData.cm_windingList->numWindings != 0 )
  {
    if ( numWindings == 1 )
      return v47->w;
    if ( !model->isWorldModel )
      return w;
    v50 = -1;
    v51 = 0;
    if ( numWindings > 0 )
    {
      v52 = 0;
      do
      {
        if ( idCollisionModelBuilder::ChoppedAwayByProcBSP(w: &v47->w[v52], plane, contents) == 0 )
        {
          if ( v50 >= 0 )
            return w;
          v50 = v51;
        }
        v47 = buildData.cm_windingList;
        ++v51;
        ++v52;
      }
      while ( v51 < buildData.cm_windingList->numWindings );
      if ( v50 >= 0 )
      {
        v47 = (cm_windingList_t *)((char *)buildData.cm_windingList + 1296 * v50);
        return v47->w;
      }
    }
  }
  return nullptr;
}


// ========================================================================
// ?ShutdownHash@idCollisionModelBuilder@@CAXXZ
// EA  : 0x825CBC48
// RVA : 0x005CBC48
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

static void __fastcall idCollisionModelBuilder::ShutdownHash()
{
  idHashIndex *cm_vertexHash; // r30
  idHashIndex *cm_edgeHash; // r30
  cm_windingList_t *cm_tmpList; // r30
  cm_windingList_t *cm_outList; // r30
  cm_windingList_t *cm_windingList; // r30

  cm_vertexHash = buildData.cm_vertexHash;
  if ( buildData.cm_vertexHash != nullptr )
  {
    idHashIndex::Free(this: buildData.cm_vertexHash);
    idMem::Free(this: &mem, ptr: cm_vertexHash, align: ALIGN_16);
  }
  cm_edgeHash = buildData.cm_edgeHash;
  buildData.cm_vertexHash = nullptr;
  if ( buildData.cm_edgeHash != nullptr )
  {
    idHashIndex::Free(this: buildData.cm_edgeHash);
    idMem::Free(this: &mem, ptr: cm_edgeHash, align: ALIGN_16);
  }
  cm_tmpList = buildData.cm_tmpList;
  buildData.cm_edgeHash = nullptr;
  if ( buildData.cm_tmpList != nullptr )
  {
    `eh vector destructor iterator'(
      ptr: buildData.cm_tmpList->w,
      size: 0x510u,
      count: 256,
      pDtor: (void (__fastcall *)(void *))idFixedWinding::~idFixedWinding);
    idMem::Free(this: &mem, ptr: cm_tmpList, align: ALIGN_16);
  }
  cm_outList = buildData.cm_outList;
  buildData.cm_tmpList = nullptr;
  if ( buildData.cm_outList != nullptr )
  {
    `eh vector destructor iterator'(
      ptr: buildData.cm_outList->w,
      size: 0x510u,
      count: 256,
      pDtor: (void (__fastcall *)(void *))idFixedWinding::~idFixedWinding);
    idMem::Free(this: &mem, ptr: cm_outList, align: ALIGN_16);
  }
  cm_windingList = buildData.cm_windingList;
  buildData.cm_outList = nullptr;
  if ( buildData.cm_windingList != nullptr )
  {
    `eh vector destructor iterator'(
      ptr: buildData.cm_windingList->w,
      size: 0x510u,
      count: 256,
      pDtor: (void (__fastcall *)(void *))idFixedWinding::~idFixedWinding);
    idMem::Free(this: &mem, ptr: cm_windingList, align: ALIGN_16);
  }
  buildData.cm_windingList = nullptr;
}


// ========================================================================
// ?CalculateSubModelDataSize@idCollisionModelBuilder@@CAXAAUcm_buildNodeStats_t@@@Z
// EA  : 0x825CBD78
// RVA : 0x005CBD78
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::CalculateSubModelDataSize(cm_buildNodeStats_t *stats)
{
  int v2; // r3
  int numNodes; // r10
  cm_subModelData_t v4; // [sp+50h] [-80h] BYREF

  v2 = idCollisionModelBuilder::SetupSubModelData(data: &v4, stats);
  numNodes = stats->numNodes;
  stats->totalMemory = v2;
  if ( numNodes <= 0x10000
    && stats->numPrimitiveIndices <= 0x10000
    && stats->numMaterials <= 256
    && stats->numPolygons <= 0x10000
    && stats->numPolygonEdges <= 0x10000
    && stats->numEdges <= 0x4000
    && stats->numVertices <= 0x10000
    && stats->numPolytopes <= 0x10000
    && stats->numPolytopePlanes <= 0x10000
    && v2 <= 0x10000 )
  {
    stats->canCreateSubModel = true;
  }
}


// ========================================================================
// ?AllocSubModelData@idCollisionModelBuilder@@CAXAAUcm_buildNodeStats_t@@ABVidBounds@@AAUcm_subModel_t@@AAUcm_subModelPtrs_t@@@Z
// EA  : 0x825CBE30
// RVA : 0x005CBE30
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::AllocSubModelData(
        cm_buildNodeStats_t *stats,
        const idBounds *bounds,
        cm_subModel_t *subModel,
        cm_subModelPtrs_t *subModelPtrs)
{
  cm_subModelData_t *v8; // r3
  volatile char *state; // r11

  idCollisionModelBuilder::CalculateSubModelDataSize(stats);
  subModel->header.bounds = *bounds;
  subModel->header.totalSize = stats->totalMemory;
  subModel->header.loadedSize = 32;
  v8 = (cm_subModelData_t *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(3366) : TAG_COLLISION",
                              size: stats->totalMemory,
                              tag: TAG_COLLISION,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  state = subModel->state;
  subModel->data = v8;
  subModel->fileOffset = -1;
  subModel->numUsers = 0;
  *state = 1;
  idCollisionModelBuilder::SetupSubModelData(data: subModel->data, stats);
  idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(subModelPtrs, subModelData: subModel->data);
}


// ========================================================================
// ?BuildForTrm@idCollisionModelBuilder@@SA_NPAVidCollisionModelLocal@@PBDABVidTraceModel@@PBVidMaterial@@@Z
// EA  : 0x825CBF00
// RVA : 0x005CBF00
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::BuildForTrm(
        idCollisionModelLocal *model,
        const char *modelName,
        const idTraceModel *trm,
        const idMaterial *material)
{
  const idMaterial *r; // r30
  idParmBlock *p_parmBlock; // r29
  idAutoRenderParms *v8; // r11
  const idDeclRenderParm *contentFlags; // r4
  unsigned int *p_numPolys; // r22
  int v12; // r9
  unsigned int numPolys; // r11
  BOOL isConvex; // r10
  unsigned __int8 *v15; // r10
  unsigned int i; // ctr
  BOOL v17; // r8
  unsigned int numEdges; // r7
  int v20; // r14
  volatile char *v21; // r3
  int numSubModels; // r7
  int v23; // r11
  int v24; // r10
  cm_subModel_t *subModels; // r8
  cm_subModelData_t *data; // r11
  cm_node_t *nodes; // r11
  unsigned __int8 *p_numPolygons; // r15
  unsigned __int16 *p_firstPrimitive; // r19
  cm_material_t *materials; // r31
  int Integer; // r3
  unsigned int v33; // r8
  int v34; // r9
  float *v35; // r10
  double v36; // fp13
  double v37; // fp12
  cm_vertex_t *v38; // r11
  double v39; // fp0
  unsigned int v40; // r10
  _WORD *v41; // r11
  _WORD *v42; // r9
  int v46; // r3
  unsigned int v47; // r5
  int v51; // r4
  unsigned __int8 *v52; // r8
  unsigned int v53; // r10
  int v55; // r6
  int v57; // r7
  int v63; // r11
  int v64; // r6
  unsigned int v65; // r11
  int v66; // r7
  int v67; // r7
  int v78; // r11
  int j; // ctr
  unsigned int v80; // r10
  unsigned __int16 *p_firstPlane; // r8
  unsigned int v83; // r5
  float *v84; // r11
  int v85; // r9
  idPlane *v86; // r9
  int v88; // [sp+50h] [-120h]
  unsigned __int8 *v89; // [sp+54h] [-11Ch]
  cm_buildNodeStats_t v90; // [sp+60h] [-110h] BYREF
  cm_subModelPtrs_t v91; // [sp+90h] [-E0h] BYREF

  r = material;
  if ( material == nullptr )
    r = (const idMaterial *)mtrTraceModel_0.r;
  idResource::SetName(this: model, _name: modelName);
  model->bounds.b[0].x = trm->bounds.b[0].x;
  model->bounds.b[0].y = trm->bounds.b[0].y;
  p_parmBlock = &r->parmBlock;
  v8 = rp;
  model->bounds.b[0].z = trm->bounds.b[0].z;
  contentFlags = v8->contentFlags;
  model->bounds.b[1].x = trm->bounds.b[1].x;
  _R20 = &trm->bounds;
  model->bounds.b[1].y = trm->bounds.b[1].y;
  model->bounds.b[1].z = trm->bounds.b[1].z;
  model->contents = idParmBlock::GetInteger(this: &r->parmBlock, parm: contentFlags);
  model->isConvex = trm->isConvex;
  *(_WORD *)&model->isWorldModel = 1;
  p_numPolys = &trm->numPolys;
  model->polygonModel.numModelTreeNodes = 0;
  v12 = 0;
  model->polygonModel.modelTreeNodes = nullptr;
  numPolys = trm->numPolys;
  isConvex = trm->isConvex;
  v90.numNodes = 1;
  v90.numMaterials = 1;
  v90.numPolygons = numPolys;
  v90.numPrimitiveIndices = isConvex + numPolys;
  if ( numPolys != 0 )
  {
    v15 = &trm->polyEdges[15][12];
    for ( i = numPolys; i != 0; --i )
    {
      v15 += 4;
      v12 += *(_DWORD *)v15;
    }
  }
  v17 = trm->isConvex;
  _R16 = 4;
  numEdges = trm->numEdges;
  v90.numVertices = trm->numVerts;
  v90.numPolytopes = v17;
  v90.numEdges = numEdges;
  v90.numPolytopePlanes = !v17 ? 0 : numPolys;
  if ( numPolys != 0 )
    v20 = 4 - (*(_DWORD *)&trm->polyEdges[15][4 * numPolys + 12] & 3);
  else
    v20 = 4;
  model->polygonModel.numSubModels = 1;
  v88 = v20;
  v90.numPolygonEdges = v20 + v12;
  model->polygonModel.subModels = (cm_subModel_t *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(3425) : TAG_COLLISION",
                                                     size: 0x30u,
                                                     tag: TAG_COLLISION,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
  v21 = (volatile char *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(3426) : TAG_COLLISION",
                           size: model->polygonModel.numSubModels,
                           tag: TAG_COLLISION,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  numSubModels = model->polygonModel.numSubModels;
  model->polygonModel.subModelState = v21;
  v23 = 0;
  if ( numSubModels > 0 )
  {
    v24 = 0;
    do
    {
      model->polygonModel.subModelState[v23] = 1;
      model->polygonModel.subModels[v24++].state = &model->polygonModel.subModelState[v23++];
    }
    while ( v23 < model->polygonModel.numSubModels );
  }
  idCollisionModelBuilder::AllocSubModelData(
    stats: &v90,
    bounds: &trm->bounds,
    subModel: model->polygonModel.subModels,
    subModelPtrs: &v91);
  subModels = model->polygonModel.subModels;
  data = subModels->data;
  data->header.totalSize = subModels->header.totalSize;
  data->header.loadedSize = subModels->header.loadedSize;
  data->header.bounds.b[0].x = subModels->header.bounds.b[0].x;
  data->header.bounds.b[0].y = subModels->header.bounds.b[0].y;
  data->header.bounds.b[0].z = subModels->header.bounds.b[0].z;
  data->header.bounds.b[1].x = subModels->header.bounds.b[1].x;
  data->header.bounds.b[1].y = subModels->header.bounds.b[1].y;
  data->header.bounds.b[1].z = subModels->header.bounds.b[1].z;
  model->polygonModel.subModels->data->header.loadedSize = model->polygonModel.subModels->data->header.totalSize;
  model->polygonModel.subModels->data->isConvex = trm->isConvex;
  nodes = v91.nodes;
  p_numPolygons = &v91.nodes->numPolygons;
  v91.nodes->planeDist = 0.0;
  nodes->planeType = -1;
  nodes->children[0] = 0;
  p_firstPrimitive = &nodes->firstPrimitive;
  nodes->children[1] = 0;
  nodes->firstPrimitive = 0;
  *p_numPolygons = 0;
  nodes->numPolytopes = 0;
  v89 = p_numPolygons;
  if ( trm->type == TRM_INVALID || *p_numPolys == 0 )
    return 0;
  materials = v91.materials;
  materials->contentFlags = idParmBlock::GetInteger(this: p_parmBlock, parm: rp->contentFlags);
  materials->surfaceFlags = idParmBlock::GetInteger(this: p_parmBlock, parm: rp->surfaceFlags);
  Integer = idParmBlock::GetInteger(this: p_parmBlock, parm: rp->surfaceType);
  materials->surfaceColor[0] = -1;
  v33 = 0;
  materials->surfaceType = Integer;
  materials->surfaceColor[1] = -1;
  materials->surfaceColor[2] = -1;
  if ( trm->numVerts != 0 )
  {
    v34 = 0;
    v35 = &trm->vertsY[31];
    do
    {
      v36 = *(v35 - 63);
      v37 = *(v35 - 31);
      ++v33;
      v38 = &v91.vertices[v34];
      v39 = *++v35;
      v38->p.x = v36;
      ++v34;
      v38->p.y = v37;
      v38->st[0] = 0;
      v38->p.z = v39;
      v38->st[1] = 0;
    }
    while ( v33 < trm->numVerts );
  }
  v40 = 0;
  if ( trm->numEdges != 0 )
  {
    v41 = (_WORD *)trm->edges + 1;
    do
    {
      ++v40;
      v42 = (_WORD *)((char *)v41 + (unsigned int)v91.edges + -1346 - (_DWORD)trm);
      *v42 = *(v41 - 1);
      v42[1] = *v41;
      v41 += 2;
    }
    while ( v40 < trm->numEdges );
  }
  _R23 = 24;
  _R31 = 8;
  _R24 = 16;
  v91.nodes->numPolygons = *p_numPolys;
  v46 = 0;
  v47 = 0;
  _R28 = idBoundsShort::vector_int_zero;
  _R26 = idBoundsShort::vector_int_max_ushort;
  _R25 = &idBoundsShort::vector_float_max_ushort;
  if ( *p_numPolys != 0 )
  {
    __asm { vspltisw128 v63, 0 }
    v51 = 0;
    v52 = &trm->polyEdges[15][12];
    do
    {
      v53 = 0;
      _R9 = &v91.polygons[v51];
      _R9->material = 0;
      v55 = *((_DWORD *)v52 + 1);
      _R9->firstEdge = v46;
      _R9->numEdges = v55;
      _FP0 = 1.0e30;
      v57 = *((_DWORD *)v52 + 1);
      _FP11 = -1.0e30;
      *(float *)&v90.numMaterials = 1.0e30;
      *(float *)&v90.numEdges = -1.0e30;
      _FP12 = 1.0e30;
      *(float *)&v90.numPrimitiveIndices = 1.0e30;
      _FP13 = 1.0e30;
      v90.numPolygonEdges = v90.numEdges;
      *(float *)&v90.numNodes = 1.0e30;
      _FP9 = -1.0e30;
      v90.numPolygons = v90.numEdges;
      _FP10 = -1.0e30;
      if ( v57 != 0 )
      {
        do
        {
          v63 = trm->polyEdges[v51][v53];
          v64 = ~v63 & 0x80;
          v65 = v63 & 0xFFFFFF7F;
          if ( v64 == 0 )
            v65 |= 0x8000u;
          v66 = _R9->firstEdge + v53++;
          v91.polygonEdges[v66] = v65;
          v67 = __ROL4__(v91.edges->vertexNum[((2 * v65) & 0x7FFE) + ((v65 & 0x8000) != 0)], 4);
          _FP3 = (float)((float)_FP13 - *(float *)((char *)&v91.vertices->p.y + v67));
          _FP1 = (float)((float)_FP12 - *(float *)((char *)&v91.vertices->p.z + v67));
          _FP5 = (float)((float)_FP0 - *(float *)((char *)&v91.vertices->p.x + v67));
          _FP31 = (float)(*(float *)((char *)&v91.vertices->p.x + v67) - (float)_FP11);
          _FP30 = (float)(*(float *)((char *)&v91.vertices->p.y + v67) - (float)_FP10);
          _FP29 = (float)(*(float *)((char *)&v91.vertices->p.z + v67) - (float)_FP9);
          __asm
          {
            fsel      f13, f3, f6, f13
            fsel      f12, f1, f8, f12
            fsel      f0, f5, f7, f0
            fsel      f11, f31, f7, f11
            fsel      f10, f30, f6, f10
            fsel      f9, f29, f8, f9
          }
        }
        while ( v53 < *((_DWORD *)v52 + 1) );
        p_numPolygons = v89;
        *(float *)&v90.numEdges = _FP9;
        v20 = v88;
        *(float *)&v90.numPolygonEdges = _FP10;
        *(float *)&v90.numPolygons = _FP11;
        *(float *)&v90.numMaterials = _FP12;
        *(float *)&v90.numPrimitiveIndices = _FP13;
        *(float *)&v90.numNodes = _FP0;
      }
      _R11 = &v90;
      __asm { lvx128    v62, r0, r25 }
      _R10 = &v90;
      __asm { lvx128    v0, r0, r26 }
      _R7 = &v90;
      __asm { lvx128    v61, r0, r28 }
      _R6 = &v90;
      __asm { lvrx128   v60, r23, r11 }
      ++v51;
      __asm
      {
        lvlx128   v59, r31, r10
        vor128    v58, v91, v60
        lvrx128   v57, r24, r7
        lvlx128   v56, r0, r6
        vor128    v55, v88, v57
        vsldoi128 v54, v90, v63, 4
        vrlimi128 v55, v63, 1, 0
        vsubfp128 v53, v86, v62
        vaddfp128 v52, v87, v62
        vcfpsxws128 v13, v53, 0
        vcfpsxws128 v12, v52, 0
        vaddsws   v11, v13, v0
        vsubsws   v10, v12, v0
        vpkswss128 v51, v11, v61
        vpkswss128 v50, v10, v61
        vsldoi128 v49, v95, v51, 0xA
        vor128    v48, v82, v49
        vspltw128 v47, v48, 0
        vspltw128 v46, v48, 1
        vspltw128 v45, v48, 2
        stvewx128 v47, r0, r9
        stvewx128 v46, r9, r16
        stvewx128 v45, r9, r31
      }
      v91.primitiveIndices[*p_firstPrimitive + v47] = v47;
      ++v47;
      v52 += 4;
      v46 += *(_DWORD *)v52;
    }
    while ( v47 < *p_numPolys );
  }
  if ( v20 > 0 )
  {
    v78 = v46;
    for ( j = v20; j != 0; --j )
    {
      v91.polygonEdges[v78] = v91.polygonEdges[v78 - 1];
      ++v78;
    }
  }
  if ( trm->isConvex )
  {
    __asm { vspltisw128 v44, 0 }
    v80 = 0;
    v91.primitiveIndices[*p_numPolygons + *p_firstPrimitive] = 0;
    v91.nodes->numPolytopes = 1;
    __asm
    {
      lvx128    v63, r0, r25
      lvx128    v0, r0, r26
    }
    _R11 = v91.polytopes;
    __asm
    {
      lvlx128   v42, r31, r20
      lvrx128   v41, r23, r20
      vor128    v40, v74, v41
      lvlx128   v43, r0, r20
      vsldoi128 v38, v72, v44, 4
      lvrx128   v39, r24, r20
    }
    p_firstPlane = &v91.polytopes->firstPlane;
    __asm
    {
      vor128    v37, v75, v39
      lvx128    v62, r0, r28
      vsubfp128 v36, v70, v63
      vrlimi128 v37, v44, 1, 0
      vaddfp128 v35, v69, v63
      vcfpsxws128 v13, v36, 0
      vcfpsxws128 v12, v35, 0
      vaddsws   v11, v13, v0
      vpkswss128 v34, v11, v62
      vsubsws   v10, v12, v0
      vsldoi128 v33, v76, v34, 0xA
      vpkswss128 v32, v10, v62
      vor128    v63, v64, v33
      vspltw128 v62, v63, 0
      vspltw128 v61, v63, 1
      vspltw128 v60, v63, 2
      stvewx128 v62, r0, r11
      stvewx128 v61, r11, r16
      stvewx128 v60, r11, r31
    }
    v91.polytopes->material = 0;
    v83 = *p_numPolys;
    _R11->firstPlane = 0;
    _R11->numPlanes = v83;
    if ( *p_numPolys != 0 )
    {
      v84 = &trm->polyPlaneZ[15];
      do
      {
        v85 = *p_firstPlane + v80++;
        v86 = &v91.polytopePlanes[v85];
        v86->a = *(v84 - 47);
        v86->b = *(v84 - 31);
        v86->c = *(v84 - 15);
        v86->d = *++v84;
      }
      while ( v80 < *p_numPolys );
    }
  }
  return 1;
}


// ========================================================================
// ?CreateNodeStats_r@idCollisionModelBuilder@@CAXPBUcm_buildModel_t@@PAUcm_buildNode_t@@@Z
// EA  : 0x825CC668
// RVA : 0x005CC668
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::CreateNodeStats_r(
        const cm_buildModel_t *buildModel,
        cm_buildNode_t *buildNode)
{
  cm_buildNode_t *i; // r31

  while ( 1 )
  {
    ++buildModel->checkCount;
    memset(Dst: &buildNode->stats, Val: 0, Size: sizeof(buildNode->stats));
    for ( i = buildNode->parent; i != nullptr; i = i->parent )
      idCollisionModelBuilder::GetStatsFromNode(buildModel, buildNode: i, stats: &buildNode->stats);
    idCollisionModelBuilder::CreateStatsForSubTree_r(buildModel, buildNode, stats: &buildNode->stats);
    if ( buildNode->stats.lastNumPolygonEdges > 0 )
      buildNode->stats.numPolygonEdges = buildNode->stats.numPolygonEdges
                                       - (buildNode->stats.lastNumPolygonEdges & 3)
                                       + 4;
    idCollisionModelBuilder::CalculateSubModelDataSize(stats: &buildNode->stats);
    if ( buildNode->planeType == -1 )
      break;
    idCollisionModelBuilder::CreateNodeStats_r(buildModel, buildNode: buildNode->children[0]);
    buildNode = buildNode->children[1];
  }
}


// ========================================================================
// ?CreateSubModels_r@idCollisionModelBuilder@@CAXPBUcm_buildModel_t@@PAUcm_buildNode_t@@PAVidCollisionModelLocal@@PAUcm_modelTreeNode_t@@@Z
// EA  : 0x825CC728
// RVA : 0x005CC728
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::CreateSubModels_r(
        const cm_buildModel_t *buildModel,
        cm_buildNode_t *buildNode,
        idCollisionModelLocal *model,
        cm_modelTreeNode_t *parent)
{
  cm_buildNode_t *v5; // r31
  int numModelTreeNodes; // r11
  cm_modelTreeNode_t *v9; // r6
  cm_subModel_t *v10; // r29
  char *v11; // r11
  __int64 v12; // r9
  int i; // ctr
  int checkCount; // r10
  int v15; // ctr
  int numPolygonEdges; // r11
  cm_subModelData_t *data; // r11
  int v18; // r11
  cm_subModelPtrs_t v19; // [sp+50h] [-E0h] BYREF
  char v20; // [sp+78h] [-B8h] BYREF
  cm_subModelData_t v21; // [sp+80h] [-B0h] BYREF

  v5 = buildNode;
  if ( buildNode->stats.canCreateSubModel )
  {
LABEL_6:
    v10 = &model->polygonModel.subModels[model->polygonModel.numSubModels];
    idCollisionModelBuilder::AllocSubModelData(
      stats: &v5->stats,
      bounds: &v5->bounds,
      subModel: v10,
      subModelPtrs: &v19);
    v11 = &v20;
    LODWORD(v12) = 0;
    for ( i = 13; i != 0; --i )
    {
      v11 += 8;
      *(_QWORD *)v11 = v12;
    }
    checkCount = buildModel->checkCount;
    *((_DWORD *)v11 + 2) = 0;
    buildModel->checkCount = checkCount + 1;
    idCollisionModelBuilder::CreateSingleSubModel_r(
      buildModel,
      buildNode: v5,
      subModelPtrs: &v19,
      counts: &v21,
      parent: nullptr);
    if ( v21.numPolygons > 0 )
    {
      v15 = 4 - (v19.polygons[v21.numPolygons - 1].numEdges & 3);
      numPolygonEdges = v21.numPolygonEdges;
      do
      {
        v19.polygonEdges[numPolygonEdges] = v19.polygonEdges[numPolygonEdges - 1];
        numPolygonEdges = ++v21.numPolygonEdges;
        --v15;
      }
      while ( v15 != 0 );
    }
    data = v10->data;
    data->header.totalSize = v10->header.totalSize;
    data->header.loadedSize = v10->header.loadedSize;
    data->header.bounds.b[0].x = v10->header.bounds.b[0].x;
    data->header.bounds.b[0].y = v10->header.bounds.b[0].y;
    data->header.bounds.b[0].z = v10->header.bounds.b[0].z;
    data->header.bounds.b[1].x = v10->header.bounds.b[1].x;
    data->header.bounds.b[1].y = v10->header.bounds.b[1].y;
    data->header.bounds.b[1].z = v10->header.bounds.b[1].z;
    v10->data->header.loadedSize = v10->data->header.totalSize;
    v18 = model->polygonModel.numSubModels + 1;
    model->polygonModel.numSubModels = v18;
    if ( parent != nullptr )
      parent->children[(_cntlzw((char *)v5 - (char *)v5->parent->children[1]) & 0x20) != 0] = -v18;
  }
  else
  {
    while ( 1 )
    {
      numModelTreeNodes = model->polygonModel.numModelTreeNodes;
      v9 = &model->polygonModel.modelTreeNodes[numModelTreeNodes];
      model->polygonModel.numModelTreeNodes = numModelTreeNodes + 1;
      v9->planeType = v5->planeType;
      v9->planeDist = v5->planeDist;
      v9->children[0] = 0;
      v9->children[1] = 0;
      if ( parent != nullptr )
        parent->children[(_cntlzw((char *)v5 - (char *)v5->parent->children[1]) & 0x20) != 0] = model->polygonModel.numModelTreeNodes
                                                                                              - 1;
      if ( v5->planeType == -1 )
        break;
      parent = v9;
      idCollisionModelBuilder::CreateSubModels_r(buildModel, buildNode: v5->children[0], model, parent: v9);
      v5 = v5->children[1];
      if ( v5->stats.canCreateSubModel )
        goto LABEL_6;
    }
  }
}


// ========================================================================
// ?AddSubModelsToCollisionModel@idCollisionModelBuilder@@CAXPAVidCollisionModelLocal@@PBUcm_buildModel_t@@@Z
// EA  : 0x825CC940
// RVA : 0x005CC940
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::AddSubModelsToCollisionModel(
        idCollisionModelLocal *model,
        const cm_buildModel_t *buildModel)
{
  cm_buildNode_t *node; // r4
  double z; // fp9
  int v18; // r26
  int v19; // r11
  signed int v20; // r29
  cm_modelTreeNode_t *modelTreeNodes; // r27
  cm_modelTreeNode_t *v22; // r3
  cm_subModel_t *subModels; // r27
  volatile char *v24; // r3
  int v25; // r10
  int v26; // r11
  int v27; // r10
  int v28; // r11
  int v29; // r10
  signed int i; // ctr
  volatile char *v31; // r8
  int v32; // [sp+50h] [-90h] BYREF
  int v33[3]; // [sp+54h] [-8Ch] BYREF
  idBounds v34; // [sp+60h] [-80h] BYREF

  idCollisionModelBuilder::GetNodeBounds(model: buildModel, node: buildModel->node, bounds: &v34);
  node = buildModel->node;
  _FP6 = (float)(model->bounds.b[0].x - v34.b[0].x);
  _FP4 = (float)(model->bounds.b[0].y - v34.b[0].y);
  _FP2 = (float)(model->bounds.b[0].z - v34.b[0].z);
  _FP31 = (float)(v34.b[1].x - model->bounds.b[1].x);
  z = v34.b[1].z;
  _FP29 = (float)(v34.b[1].y - model->bounds.b[1].y);
  __asm { fsel      f0, f6, f0, f8 }
  model->bounds.b[0].x = _FP0;
  __asm { fsel      f13, f4, f13, f7 }
  model->bounds.b[0].y = _FP13;
  __asm { fsel      f12, f2, f12, f5 }
  model->bounds.b[0].z = _FP12;
  __asm { fsel      f11, f31, f11, f3 }
  model->bounds.b[1].x = _FP11;
  __asm { fsel      f10, f29, f10, f1 }
  _FP28 = (float)((float)z - model->bounds.b[1].z);
  model->bounds.b[1].y = _FP10;
  __asm { fsel      f9, f28, f9, f30 }
  model->bounds.b[1].z = _FP9;
  model->contents |= idCollisionModelBuilder::GetNodeContents(model: buildModel, node);
  idCollisionModelBuilder::CreateNodeStats_r(buildModel, buildNode: buildModel->node);
  v33[0] = 0;
  v32 = 0;
  idCollisionModelBuilder::FindSubModels_r(
    buildModel,
    buildNode: buildModel->node,
    numModelTreeNodes: v33,
    numSubModels: &v32);
  v18 = v33[0];
  v19 = model->polygonModel.numModelTreeNodes + v33[0];
  v20 = model->polygonModel.numSubModels + v32;
  if ( v19 > 0x8000 )
    idLib::Error(fmt: "%d model tree nodes (max = %d)", model->polygonModel.numModelTreeNodes + v33[0], 0x8000);
  if ( v20 > 0x4000 )
    idLib::Error(fmt: "%d sub models (max = %d)", v20, 0x4000);
  modelTreeNodes = model->polygonModel.modelTreeNodes;
  if ( modelTreeNodes != nullptr )
  {
    v22 = (cm_modelTreeNode_t *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(4324) : TAG_COLLISION",
                                  size: 16 * v19,
                                  tag: TAG_COLLISION,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    model->polygonModel.modelTreeNodes = v22;
    memcpy(Dst: v22, Src: modelTreeNodes, Size: 16 * model->polygonModel.numModelTreeNodes);
    idMem::Free(this: &mem, ptr: modelTreeNodes, align: ALIGN_16);
  }
  else
  {
    model->polygonModel.modelTreeNodes = (cm_modelTreeNode_t *)idMem::AllocWithLocation(
                                                                 this: &mem,
                                                                 location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(4321) : TAG_COLLISION",
                                                                 size: 16 * v18,
                                                                 tag: TAG_COLLISION,
                                                                 zeroBuffer: false,
                                                                 align: ALIGN_16,
                                                                 heap: HEAP_DEFAULTHEAP);
  }
  subModels = model->polygonModel.subModels;
  if ( subModels != nullptr )
  {
    idMem::Free(this: &mem, ptr: (void *)model->polygonModel.subModelState, align: ALIGN_16);
    model->polygonModel.subModels = (cm_subModel_t *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(4340) : TAG_COLLISION",
                                                       size: 48 * v20,
                                                       tag: TAG_COLLISION,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
    model->polygonModel.subModelState = (volatile char *)idMem::AllocWithLocation(
                                                           this: &mem,
                                                           location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(4341) : TAG_COLLISION",
                                                           size: v20,
                                                           tag: TAG_COLLISION,
                                                           zeroBuffer: false,
                                                           align: ALIGN_16,
                                                           heap: HEAP_DEFAULTHEAP);
    memcpy(Dst: model->polygonModel.subModels, Src: subModels, Size: 48 * model->polygonModel.numSubModels);
    v28 = 0;
    if ( v20 > 0 )
    {
      v29 = 0;
      for ( i = v20; i != 0; --i )
      {
        model->polygonModel.subModelState[v28] = 1;
        v31 = &model->polygonModel.subModelState[v28++];
        model->polygonModel.subModels[v29++].state = v31;
      }
    }
    idMem::Free(this: &mem, ptr: subModels, align: ALIGN_16);
  }
  else
  {
    model->polygonModel.subModels = (cm_subModel_t *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(4330) : TAG_COLLISION",
                                                       size: 48 * v32,
                                                       tag: TAG_COLLISION,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
    v24 = (volatile char *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(4331) : TAG_COLLISION",
                             size: v32,
                             tag: TAG_COLLISION,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
    v25 = v32;
    model->polygonModel.subModelState = v24;
    v26 = 0;
    if ( v25 > 0 )
    {
      v27 = 0;
      do
      {
        model->polygonModel.subModelState[v26] = 1;
        model->polygonModel.subModels[v27++].state = &model->polygonModel.subModelState[v26++];
      }
      while ( v26 < v32 );
    }
  }
  idCollisionModelBuilder::CreateSubModels_r(buildModel, buildNode: buildModel->node, model, parent: nullptr);
}


// ========================================================================
// ?CreateStreamAreas@idCollisionModelBuilder@@CAXPAVidCollisionModelLocal@@ABV?$idList@VidCollisionModelGeometry@idCollisionModelBuilder@@$04@@@Z
// EA  : 0x825CCCB0
// RVA : 0x005CCCB0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::CreateStreamAreas(
        idCollisionModelLocal *model,
        const idList<idCollisionModelBuilder::idCollisionModelGeometry,5> *entityCollisionGeometry)
{
  const idList<idCollisionModelBuilder::idCollisionModelGeometry,5> *v3; // r31
  idTraceWork *v4; // r19
  int v5; // r21
  int v6; // r18
  char *v7; // r14
  char *v8; // r15
  memTag_t v9; // r4
  size_t v10; // r20
  bool *p_isConvex; // r30
  idCollisionModelBuilder::idCollisionModelGeometry *v12; // r11
  idCollisionModelLocal *collisionModel; // r25
  const idVec3 *p_streamVolumeOrigin; // r28
  idMat3 *p_streamVolumeAxis; // r31
  const char *str; // r4
  int v17; // r11
  int v18; // r24
  int v19; // r26
  int v20; // r27
  char *v21; // r22
  float *p_totalSize; // r11
  const idBounds *v23; // r29
  double v24; // fp0
  char v25; // r11
  const char *v26; // r4
  int v27; // r11
  int v28; // r29
  double y; // fp13
  double z; // fp12
  double v31; // fp10
  double v32; // fp9
  double x; // fp5
  double v34; // fp4
  double v35; // fp3
  streamAreasHeader_t *v36; // r3
  int v37; // [sp+50h] [-2560h]
  int v38; // [sp+54h] [-255Ch]
  streamAreasPtrs_t v39; // [sp+60h] [-2550h] BYREF
  idBounds v40; // [sp+70h] [-2540h] BYREF
  trace_t v41; // [sp+90h] [-2520h] BYREF
  idTraceModel v42; // [sp+110h] [-24A0h] BYREF
  char v43[36]; // [sp+710h] [-1EA0h] BYREF

  v3 = entityCollisionGeometry;
  v4 = idPolygonModelCollisionDetection::AllocTraceWork();
  v5 = 0;
  v6 = 0;
  v7 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(4738) : TAG_COLLISION",
                 size: model->polygonModel.numSubModels << 8,
                 tag: TAG_COLLISION,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v8 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(4741) : TAG_COLLISION",
                 size: 0x8000u,
                 tag: TAG_COLLISION,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v38 = 0;
  v10 = 0;
  if ( v3->num > 0 )
  {
    v37 = 0;
    p_isConvex = &v42.isConvex;
    do
    {
      v12 = &v3->list[v37];
      if ( v12->isStreamArea )
      {
        collisionModel = v12->collisionModel;
        p_streamVolumeOrigin = &v12->streamVolumeOrigin;
        p_streamVolumeAxis = &v12->streamVolumeAxis;
        if ( v6 >= 128 )
        {
          idLib::Error(fmt: "more than %d stream areas", 128);
_LN143:
          idLib::Error(fmt: "stream area collision model name '%s' too long", str);
          JUMPOUT(0x825CD0BC);
        }
        str = collisionModel->name.str;
        v17 = 0;
        if ( *str != 0 )
        {
          do
            ++v17;
          while ( str[v17] != 0 );
          if ( v17 >= 256 )
            goto _LN143;
        }
        idBounds::FromTransformedBounds(
          this: &v40,
          bounds: &collisionModel->bounds,
          origin: p_streamVolumeOrigin,
          axis: p_streamVolumeAxis);
        v18 = 0;
        v19 = 0;
        if ( model->polygonModel.numSubModels > 0 )
        {
          v20 = 0;
          v21 = &v7[2 * v5 - 2];
          do
          {
            p_totalSize = (float *)&model->polygonModel.subModels[v20].header.totalSize;
            v23 = (const idBounds *)(p_totalSize + 2);
            if ( p_totalSize[5] < (double)v40.b[0].x
              || p_totalSize[6] < (double)v40.b[0].y
              || p_totalSize[7] < (double)v40.b[0].z
              || v23->b[0].x > (double)v40.b[1].x
              || p_totalSize[3] > (double)v40.b[1].y
              || (v24 = p_totalSize[4], v25 = 1, v24 > v40.b[1].z) )
            {
              v25 = 0;
            }
            if ( v25 != 0 )
            {
              idTraceModel::InitBox(this: &v42);
              idTraceModel::SetupBox(this: &v42, boxBounds: v23);
              idPolygonModelCollisionDetection::StartContents(
                tw: v4,
                result: &v41,
                start: &vec3_origin,
                trm: &v42,
                trmAxis: &mat3_identity,
                contentMask: -1,
                modelOrigin: p_streamVolumeOrigin,
                modelAxis: p_streamVolumeAxis);
              idPolygonModelCollisionDetection::TraceThroughModel(tw: v4, model: &collisionModel->polygonModel);
              idPolygonModelCollisionDetection::FinishContents(
                tw: v4,
                modelOrigin: p_streamVolumeOrigin,
                modelAxis: p_streamVolumeAxis,
                modelEntityNum: 0,
                modelPhysicsId: 0,
                modelId: 0,
                selfId: 0,
                modelContentsOverride: 0);
              if ( v41.c.contentFlags != 0 )
              {
                ++v18;
                v21 += 2;
                *(_WORD *)v21 = v19;
              }
            }
            ++v19;
            ++v20;
          }
          while ( v19 < model->polygonModel.numSubModels );
        }
        v26 = collisionModel->name.str;
        v27 = 0;
        if ( *v26 != 0 )
        {
          do
            ++v27;
          while ( v26[v27] != 0 );
        }
        v28 = v27 + 1;
        memcpy(Dst: &v8[v10], Src: v26, Size: v27 + 1);
        *((_DWORD *)p_isConvex + 1) = v10;
        v10 += v28;
        y = p_streamVolumeOrigin->y;
        z = p_streamVolumeOrigin->z;
        ++v6;
        *((float *)p_isConvex + 2) = p_streamVolumeOrigin->x;
        *((float *)p_isConvex + 3) = y;
        *((float *)p_isConvex + 4) = z;
        *((float *)p_isConvex + 5) = p_streamVolumeAxis->mat[0].x;
        v31 = p_streamVolumeAxis->mat[0].y;
        v32 = p_streamVolumeAxis->mat[0].z;
        *((float *)p_isConvex + 8) = p_streamVolumeAxis->mat[1].x;
        *((float *)p_isConvex + 6) = v31;
        *((float *)p_isConvex + 7) = v32;
        *((float *)p_isConvex + 9) = p_streamVolumeAxis->mat[1].y;
        x = p_streamVolumeAxis->mat[2].x;
        *((float *)p_isConvex + 10) = p_streamVolumeAxis->mat[1].z;
        v34 = p_streamVolumeAxis->mat[2].y;
        *((float *)p_isConvex + 11) = x;
        v35 = p_streamVolumeAxis->mat[2].z;
        v3 = entityCollisionGeometry;
        *((float *)p_isConvex + 12) = v34;
        *((float *)p_isConvex + 13) = v35;
        *((_DWORD *)p_isConvex + 14) = v18;
        p_isConvex += 60;
        *(_DWORD *)p_isConvex = v5;
        v5 += v18;
      }
      ++v37;
      ++v38;
    }
    while ( v38 < v3->num );
  }
  operator delete(p: v4, tag: v9);
  v36 = (streamAreasHeader_t *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(4808) : TAG_COLLISION",
                                 size: 2 * (30 * v6 + v5 + 8) + v10,
                                 tag: TAG_COLLISION,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  model->streamAreas = v36;
  v36->totalSize = 2 * (30 * v6 + v5 + 8) + v10;
  model->streamAreas->numStreamAreas = v6;
  model->streamAreas->numStreamAreaSubModels = v5;
  model->streamAreas->numStreamAreaNameBytes = v10;
  SetupStreamAreaPtrs(header: model->streamAreas, ptrs: &v39);
  memcpy(Dst: v39.streamAreas, Src: v43, Size: 60 * v6);
  memcpy(Dst: v39.streamAreaSubModels, Src: v7, Size: 2 * v5);
  memcpy(Dst: v39.streamAreaNameBytes, Src: v8, Size: v10);
  idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
}


// ========================================================================
// ?AllocBuildModel@idCollisionModelBuilder@@CAPAUcm_buildModel_t@@XZ
// EA  : 0x825CD600
// RVA : 0x005CD600
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

cm_buildModel_t *__fastcall idCollisionModelBuilder::AllocBuildModel()
{
  cm_buildModel_t *v0; // r3
  cm_buildModel_t *result; // r3

  v0 = (cm_buildModel_t *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                            size: 0xB0u,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v0 != nullptr )
    result = cm_buildModel_t::cm_buildModel_t(this: v0);
  else
    result = nullptr;
  result->isWorldModel = false;
  result->checkCount = 0;
  result->maxVertices = 0;
  result->numVertices = 0;
  result->vertices = nullptr;
  result->maxEdges = 0;
  result->numEdges = 0;
  result->edges = nullptr;
  result->maxPolygonEdges = 0;
  result->numPolygonEdges = 0;
  result->polygonEdges = nullptr;
  result->maxPolygons = 0;
  result->numPolygons = 0;
  result->polygons = nullptr;
  result->maxPolytopePlanes = 0;
  result->numPolytopePlanes = 0;
  result->polytopePlanes = nullptr;
  result->maxPolytopes = 0;
  result->numPolytopes = 0;
  result->polytopes = nullptr;
  result->numNodes = 0;
  result->node = nullptr;
  result->nodeBlocks = nullptr;
  result->polygonRefBlocks = nullptr;
  result->polytopeRefBlocks = nullptr;
  result->numMergedPolys = 0;
  result->numRemovedPolys = 0;
  result->numSharpEdges = 0;
  result->numInternalEdges = 0;
  result->numPolygonRefs = 0;
  result->numPolytopeRefs = 0;
  return result;
}


// ========================================================================
// __unwind$244554
// EA  : 0x825CD6F0
// RVA : 0x005CD6F0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall _unwind_244554(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?FindMaterial@idCollisionModelBuilder@@CAHPAUcm_buildModel_t@@HHH@Z
// EA  : 0x825CD718
// RVA : 0x005CD718
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::FindMaterial(
        cm_buildModel_t *model,
        int contentFlags,
        int surfaceFlags,
        int surfaceType)
{
  int num; // r8
  int v5; // r9
  cm_buildMaterial_t *list; // r7
  int v7; // r10
  cm_buildMaterial_t *v8; // r11
  cm_buildMaterial_t v10; // [sp+50h] [-30h] BYREF

  num = model->materials.num;
  v5 = 0;
  if ( num <= 0 )
  {
LABEL_7:
    v10.contentFlags = contentFlags;
    v10.surfaceFlags = surfaceFlags;
    v10.surfaceType = surfaceType;
    v10.checkCount = 0;
    return idList<sourceSurface_t,59>::Append(this: &model->materials, obj: &v10);
  }
  else
  {
    list = model->materials.list;
    v7 = 0;
    while ( 1 )
    {
      v8 = &list[v7];
      if ( list[v7].contentFlags == contentFlags && v8->surfaceFlags == surfaceFlags && v8->surfaceType == surfaceType )
        return v5;
      ++v5;
      ++v7;
      if ( v5 >= num )
        goto LABEL_7;
    }
  }
}


// ========================================================================
// ?CreatePolygon@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAVidFixedWinding@@ABVidPlane@@PBVidMaterial@@H@Z
// EA  : 0x825CD7C8
// RVA : 0x005CD7C8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::CreatePolygon(
        cm_buildModel_t *model,
        idFixedWinding *w,
        const idPlane *plane,
        const idMaterial *material,
        int primitiveNum,
        long double a6)
{
  int numPoints; // r10
  int v12; // r29
  int v13; // r27
  int v14; // r24
  unsigned int v15; // r11
  int v16; // r28
  int *v17; // r30
  int v18; // r31
  int v19; // r11
  int v20; // r11
  int *i; // r7
  int v22; // r9
  int v23; // r10
  int *v24; // r11
  unsigned int v25; // r8
  cm_buildPolygon_t *v26; // r3
  cm_buildPolygon_t *v27; // r31
  idAutoRenderParms *v28; // r11
  const idDeclRenderParm *contentFlags; // r4
  int Integer; // r27
  int v31; // r28
  int v32; // r3
  int v33; // r11
  int *v34; // r10
  int j; // ctr
  int v36; // r8
  int v37; // [sp+8h] [-1C8h]
  int v38; // [sp+Ch] [-1C4h]
  int v39; // [sp+10h] [-1C0h]
  int v40; // [sp+14h] [-1BCh]
  int v41; // [sp+18h] [-1B8h]
  int v42; // [sp+1Ch] [-1B4h]
  int v43; // [sp+20h] [-1B0h]
  int v44; // [sp+24h] [-1ACh]
  int v45; // [sp+28h] [-1A8h]
  int v46; // [sp+2Ch] [-1A4h]
  int v47; // [sp+30h] [-1A0h]
  int v48; // [sp+34h] [-19Ch]
  idBounds v49; // [sp+50h] [-180h] BYREF
  char v50; // [sp+6Ch] [-164h] BYREF
  _BYTE v51[352]; // [sp+70h] [-160h] BYREF

  numPoints = w->numPoints;
  v12 = 0;
  v13 = -1;
  v14 = 0;
  v15 = 1;
  if ( numPoints > 0 )
  {
    v16 = 0;
    v17 = (int *)v51;
    do
    {
      v18 = ((__PAIR64__((unsigned int)numPoints >> 31, v15) - __PAIR64__(v15 >> 31, numPoints)) >> 32) & v15;
      idCollisionModelBuilder::GetEdge(
        model,
        v1: (const idVec3 *)&w->p[v16],
        v2: (const idVec3 *)&w->p[v18],
        edgeNum: v17,
        v1num: v13,
        a6,
        a7: v15 - numPoints,
        a8: (int)w->p,
        a9: numPoints,
        a10: v37,
        a11: v38,
        a12: v39,
        a13: v40,
        a14: v41,
        a15: v42,
        a16: v43,
        a17: v44,
        a18: v45,
        a19: v46,
        a20: v47,
        a21: v48);
      v19 = *v17;
      if ( *v17 != 0 )
      {
        ++v12;
        ++v17;
        v13 = model->edges[abs32(v19)].vertexNum[v19 >= 0];
      }
      numPoints = w->numPoints;
      ++v14;
      ++v16;
      v15 = v18 + 1;
    }
    while ( v14 < numPoints );
    if ( v12 >= 3 )
    {
      v20 = 0;
      for ( i = (int *)v51; ; ++i )
      {
        v22 = v20 + 1;
        v23 = v20 + 1;
        if ( v20 + 1 < v12 )
          break;
LABEL_12:
        v20 = v22;
        if ( v22 >= v12 )
        {
          idWinding::GetBounds(this: w, bounds: &v49);
          v26 = idCollisionModelBuilder::AllocPolygon(model, numEdges: v12);
          v26->bounds.b[0].x = v49.b[0].x;
          v27 = v26;
          v26->bounds.b[0].y = v49.b[0].y;
          v28 = rp;
          v26->bounds.b[0].z = v49.b[0].z;
          v26->bounds.b[1].x = v49.b[1].x;
          contentFlags = v28->contentFlags;
          v26->bounds.b[1].y = v49.b[1].y;
          v26->bounds.b[1].z = v49.b[1].z;
          v26->contents = idParmBlock::GetInteger(this: &material->parmBlock, parm: contentFlags);
          Integer = idParmBlock::GetInteger(this: &material->parmBlock, parm: rp->surfaceType);
          v31 = idParmBlock::GetInteger(this: &material->parmBlock, parm: rp->surfaceFlags);
          v32 = idParmBlock::GetInteger(this: &material->parmBlock, parm: rp->contentFlags);
          v27->material = idCollisionModelBuilder::FindMaterial(
                            model,
                            contentFlags: v32,
                            surfaceFlags: v31,
                            surfaceType: Integer);
          v27->plane.a = plane->a;
          v27->plane.b = plane->b;
          v33 = 0;
          v27->plane.c = plane->c;
          v27->plane.d = plane->d;
          v27->primitiveNum = abs32(primitiveNum);
          v27->numEdges = v12;
          v27->checkCount = 0;
          v34 = (int *)&v50;
          for ( j = v12; j != 0; --j )
          {
            ++v34;
            v36 = v27->firstEdge + v33++;
            model->polygonEdges[v36] = *v34;
          }
          idCollisionModelBuilder::FilterPolygonIntoTree_r(model, node: model->node, pref: nullptr, p: v27);
          return;
        }
      }
      v24 = i + 1;
      v25 = abs32(*i);
      while ( v25 != abs32(*v24) )
      {
        ++v23;
        ++v24;
        if ( v23 >= v12 )
          goto LABEL_12;
      }
    }
  }
}


// ========================================================================
// ?PolygonFromWinding@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PAVidFixedWinding@@ABVidPlane@@PBVidMaterial@@H@Z
// EA  : 0x825CDA60
// RVA : 0x005CDA60
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::PolygonFromWinding(
        cm_buildModel_t *model,
        idFixedWinding *w,
        idPlane *plane,
        const idMaterial *material,
        int primitiveNum)
{
  int Integer; // r3
  int v11; // r28
  idFixedWinding *v12; // r3
  idFixedWinding *v13; // r30
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  long double v17; // fp2
  int v18; // r29
  int v19; // r28
  va *v20; // r3
  const char *v21; // r4
  va *v22; // r3
  int v23; // [sp+8h] [-10B8h]
  int v24; // [sp+Ch] [-10B4h]
  int v25; // [sp+10h] [-10B0h]
  int v26; // [sp+14h] [-10ACh]
  int v27; // [sp+18h] [-10A8h]
  int v28; // [sp+1Ch] [-10A4h]
  double v29; // [sp+30h] [-1090h]
  float *p_x; // [sp+50h] [-1070h]
  idStr v31; // [sp+60h] [-1060h] BYREF
  va v32; // [sp+80h] [-1040h] BYREF

  Integer = idParmBlock::GetInteger(this: &material->parmBlock, parm: rp->contentFlags);
  v11 = Integer;
  if ( model->isWorldModel
    && idCollisionModelBuilder::ChoppedAwayByProcBSP(w, (idFixedWinding *)plane, contents: Integer) != 0
    || (v12 = idCollisionModelBuilder::WindingOutsidePolytopes(
                model,
                w,
                (idFixedWinding *)plane,
                contents: v11,
                primitiveNum),
        v13 = v12,
        v12 == nullptr) )
  {
    ++model->numRemovedPolys;
  }
  else if ( idWinding::IsHuge(this: v12, radius: 131072.0) )
  {
    v18 = 0;
    LODWORD(v14) = v31.baseBuffer;
    v31.len = 0;
    v31.allocedAndFlag = 20;
    v31.data = v31.baseBuffer;
    v31.baseBuffer[0] = 0;
    if ( v13->numPoints <= 0 )
    {
      v21 = " no points on winding\n";
    }
    else
    {
      v19 = 0;
      do
      {
        p_x = &v13->p[v18].x;
        v29 = p_x[2];
        HIDWORD(v15) = LODWORD(v29);
        v20 = va::va(
                this: &v32,
                fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(*p_x)),
                a3: __SPAIR64__(COERCE_UNSIGNED_INT64(*p_x), COERCE_UNSIGNED_INT64(p_x[1])),
                a4: v15,
                a5: v14,
                a6: v23,
                a7: v24,
                a8: v25,
                a9: v26,
                a10: v27,
                a11: v28);
        idStr::Append(this: &v31, text: v20);
        ++v19;
        ++v18;
      }
      while ( v19 < v13->numPoints );
      v21 = "\n";
    }
    v22 = va::va(
            this: &v32,
            fmt: v21,
            a3: v16,
            a4: v15,
            a5: v14,
            a6: v23,
            a7: v24,
            a8: v25,
            a9: v26,
            a10: v27,
            a11: v28);
    idStr::Append(this: &v31, text: v22);
    idLib::Warning(
      fmt: "PolygonFromWinding: model %s primitive %d is degenerate,%s",
      model->name.data,
      abs32(primitiveNum),
      v31.data);
    idStr::FreeData(this: &v31);
  }
  else
  {
    idCollisionModelBuilder::CreatePolygon(model, w: v13, plane, material, primitiveNum, a6: v17);
  }
}


// ========================================================================
// __unwind$244692
// EA  : 0x825CDC24
// RVA : 0x005CDC24
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_244692()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 96));
}


// ========================================================================
// ?CreatePatchPolygons@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@ABVidSurface_Patch@@ABVidVec3@@ABVidMat3@@2PBVidMaterial@@H@Z
// EA  : 0x825CDC58
// RVA : 0x005CDC58
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::CreatePatchPolygons(
        cm_buildModel_t *model,
        const idSurface_Patch *mesh,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *scale,
        const idMaterial *material,
        int primitiveNum)
{
  int v14; // r28
  int v15; // r29
  int width; // r11
  double z; // fp13
  idDrawVert *list; // r10
  double x; // fp12
  double v20; // fp11
  double y; // fp10
  double v22; // fp9
  double v23; // fp8
  double v24; // fp7
  double v25; // fp6
  double v26; // fp5
  double v27; // fp4
  double v28; // fp3
  double v29; // fp2
  double v30; // fp1
  double v31; // fp25
  double v32; // fp24
  idDrawVert *v33; // r8
  idDrawVert *v34; // r9
  double v35; // fp30
  double v36; // fp28
  double v37; // fp20
  double v38; // fp31
  idDrawVert *v39; // r9
  double v40; // fp23
  double v41; // fp16
  double v42; // fp29
  double v43; // fp18
  double v44; // fp26
  double v45; // fp23
  double v46; // fp20
  double v47; // fp28
  double v48; // fp0
  double v49; // fp19
  double v50; // fp31
  double v51; // fp30
  double v52; // fp27
  double v53; // fp19
  float *p_x; // r11
  double v55; // fp0
  double v56; // fp13
  double v57; // fp23
  double v58; // fp29
  double v59; // fp12
  double v60; // fp8
  double v61; // fp20
  double v62; // fp23
  double v63; // fp29
  double v64; // fp28
  double v65; // fp11
  double v66; // fp25
  double v67; // fp24
  double v68; // fp26
  idPlane v69; // [sp+60h] [-1090h] BYREF
  idPlane v70; // [sp+70h] [-1080h] BYREF
  idVec3 v71; // [sp+80h] [-1070h] BYREF
  idVec3 v72; // [sp+90h] [-1060h] BYREF
  idVec3 v73; // [sp+A0h] [-1050h] BYREF
  idVec3 v74; // [sp+B0h] [-1040h] BYREF
  idFixedWinding v75; // [sp+C0h] [-1030h] BYREF
  idFixedWinding v76; // [sp+5D0h] [-B20h] BYREF
  idFixedWinding v77; // [sp+AE0h] [-610h] BYREF

  v14 = 0;
  if ( mesh->width - 1 > 0 )
  {
    while ( 1 )
    {
      v15 = 0;
      if ( mesh->height - 1 > 0 )
        break;
LABEL_10:
      if ( ++v14 >= mesh->width - 1 )
        return;
    }
    while ( 1 )
    {
      width = mesh->width;
      z = scale->z;
      list = mesh->verts.list;
      x = scale->x;
      v20 = axis->mat[2].z;
      y = axis->mat[2].y;
      v22 = axis->mat[2].x;
      v23 = scale->y;
      v24 = axis->mat[0].z;
      v25 = axis->mat[0].y;
      v26 = axis->mat[0].x;
      v27 = axis->mat[1].z;
      v28 = axis->mat[1].y;
      v29 = axis->mat[1].x;
      v30 = origin->z;
      v31 = origin->y;
      v32 = origin->x;
      v33 = &mesh->verts.list[width * v15 + 1 + v14];
      v34 = &mesh->verts.list[width * v15 + v14];
      v35 = (float)(v34->xyz.x * scale->x);
      v36 = (float)(v34->xyz.y * scale->y);
      v37 = (float)((float)(v34->xyz.z * scale->z) * axis->mat[2].y);
      v38 = (float)((float)(v34->xyz.z * scale->z) * axis->mat[2].x);
      v40 = (float)((float)((float)(v34->xyz.x * scale->x) * axis->mat[0].z)
                  + (float)((float)(v34->xyz.z * scale->z) * axis->mat[2].z));
      v39 = &mesh->verts.list[width * v15 + 1 + width + v14];
      v41 = v39->xyz.x;
      v42 = (float)(v39->xyz.z * scale->z);
      v43 = (float)(v39->xyz.y * scale->y);
      v44 = (float)((float)((float)v36 * axis->mat[1].z) + (float)v40);
      v45 = (float)((float)((float)v36 * axis->mat[1].y) + (float)((float)((float)v35 * axis->mat[0].y) + (float)v37));
      v46 = (float)((float)((float)(v33->xyz.y * scale->y) * axis->mat[1].y)
                  + (float)((float)((float)(v33->xyz.x * scale->x) * axis->mat[0].y)
                          + (float)((float)(v33->xyz.z * scale->z) * axis->mat[2].y)));
      v47 = (float)((float)((float)v36 * axis->mat[1].x) + (float)((float)((float)v35 * axis->mat[0].x) + (float)v38));
      v48 = (float)((float)((float)(v33->xyz.y * scale->y) * axis->mat[1].x)
                  + (float)((float)((float)(v33->xyz.x * scale->x) * axis->mat[0].x)
                          + (float)((float)(v33->xyz.z * scale->z) * axis->mat[2].x)));
      v49 = (float)((float)((float)((float)(v33->xyz.y * scale->y) * axis->mat[1].z)
                          + (float)((float)((float)(v33->xyz.x * scale->x) * axis->mat[0].z)
                                  + (float)((float)(v33->xyz.z * scale->z) * axis->mat[2].z)))
                  + origin->z);
      v50 = (float)((float)v44 + origin->z);
      v74.z = (float)((float)((float)(v33->xyz.y * scale->y) * axis->mat[1].z)
                    + (float)((float)((float)(v33->xyz.x * scale->x) * axis->mat[0].z)
                            + (float)((float)(v33->xyz.z * scale->z) * axis->mat[2].z)))
            + origin->z;
      v72.z = (float)v44 + (float)v30;
      v51 = (float)((float)v45 + (float)v31);
      v72.y = (float)v45 + (float)v31;
      v74.y = (float)v46 + (float)v31;
      v52 = (float)((float)v47 + (float)v32);
      v72.x = (float)v47 + (float)v32;
      v74.x = (float)v48 + (float)v32;
      v53 = (float)((float)v49 - v72.z);
      p_x = &list[width * v15 + width + v14].xyz.x;
      v55 = (float)((float)((float)v43 * (float)v29)
                  + (float)((float)((float)((float)v41 * (float)x) * (float)v26) + (float)((float)v42 * (float)v22)));
      v56 = (float)(p_x[2] * (float)z);
      v57 = (float)((float)((float)v43 * (float)v27)
                  + (float)((float)((float)((float)v41 * (float)x) * (float)v24) + (float)((float)v42 * (float)v20)));
      v58 = (float)((float)((float)v43 * (float)v28)
                  + (float)((float)((float)((float)v41 * (float)x) * (float)v25) + (float)((float)v42 * (float)y)));
      v59 = (float)(*p_x * (float)x);
      v60 = (float)(p_x[1] * (float)v23);
      v71.x = (float)v55 + (float)v32;
      v71.z = (float)v57 + (float)v30;
      v61 = (float)((float)v58 + (float)v31);
      v71.y = (float)v58 + (float)v31;
      v65 = (float)((float)((float)v60 * (float)v27)
                  + (float)((float)((float)v59 * (float)v24) + (float)((float)v56 * (float)v20)));
      v63 = (float)(v71.z - (float)v50);
      v69.b = (float)((float)(v71.x - v72.x) * (float)v53)
            - (float)((float)(v71.z - (float)v50) * (float)(v74.x - v72.x));
      v64 = (float)(v71.y - (float)v51);
      v66 = (float)((float)((float)((float)v60 * (float)v28)
                          + (float)((float)((float)v59 * (float)v25) + (float)((float)v56 * (float)y)))
                  + (float)v31);
      v73.y = v66;
      v67 = (float)((float)((float)((float)v60 * (float)v29)
                          + (float)((float)((float)v59 * (float)v26) + (float)((float)v56 * (float)v22)))
                  + (float)v32);
      v73.x = v67;
      v69.c = (float)((float)((float)v61 - (float)v51) * (float)(v74.x - v72.x))
            - (float)((float)(v71.x - (float)v52) * (float)(v74.y - v72.y));
      v69.a = (float)((float)(v71.z - (float)v50) * (float)(v74.y - v72.y))
            - (float)((float)((float)v61 - (float)v51) * (float)v53);
      v62 = (float)(v71.x - (float)v52);
      v68 = (float)((float)v65 + (float)v30);
      v73.z = (float)v65 + (float)v30;
      if ( idPlane::Normalize(this: &v69, fixDegenerate: true) == 0.0 )
        goto _M245297;
      v69.d = -(float)((float)(v69.a * (float)v52) + (float)((float)(v69.b * (float)v51) + (float)(v69.c * (float)v50)));
      if ( __fabs((float)((float)((float)((float)v67 * v69.a)
                                + (float)((float)(v69.b * (float)v66) + (float)(v69.c * (float)v68)))
                        - (float)((float)(v69.a * (float)v52)
                                + (float)((float)(v69.b * (float)v51) + (float)(v69.c * (float)v50))))) >= 0.1 )
        break;
      v75.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
      v75.numPoints = 0;
      v75.p = v75.data;
      v75.allocedSize = 64;
      idWinding::AddPoint(this: &v75, v: &v72);
      idWinding::AddPoint(this: &v75, v: &v74);
      idWinding::AddPoint(this: &v75, v: &v71);
      idWinding::AddPoint(this: &v75, v: &v73);
      idCollisionModelBuilder::PolygonFromWinding(model, w: &v75, plane: &v69, material, primitiveNum: -primitiveNum);
      v75.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
      v75.p = nullptr;
      idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
      v75.p = nullptr;
_M245299:
      if ( ++v15 >= mesh->height - 1 )
        goto LABEL_10;
    }
    v76.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
    v76.numPoints = 0;
    v76.p = v76.data;
    v76.allocedSize = 64;
    idWinding::AddPoint(this: &v76, v: &v72);
    idWinding::AddPoint(this: &v76, v: &v74);
    idWinding::AddPoint(this: &v76, v: &v71);
    idCollisionModelBuilder::PolygonFromWinding(model, w: &v76, plane: &v69, material, primitiveNum: -primitiveNum);
    v76.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
    v76.p = nullptr;
    idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
    v76.p = nullptr;
_M245297:
    v70.c = (float)((float)((float)v66 - (float)v51) * (float)v62)
          - (float)((float)((float)v67 - (float)v52) * (float)v64);
    v70.b = (float)((float)((float)v67 - (float)v52) * (float)v63)
          - (float)((float)((float)v68 - (float)v50) * (float)v62);
    v70.a = (float)((float)((float)v68 - (float)v50) * (float)v64)
          - (float)((float)((float)v66 - (float)v51) * (float)v63);
    if ( idPlane::Normalize(this: &v70, fixDegenerate: true) != 0.0 )
    {
      v77.numPoints = 0;
      v77.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
      v77.p = v77.data;
      v77.allocedSize = 64;
      v70.d = -(float)((float)(v70.a * (float)v52) + (float)((float)(v70.b * (float)v51) + (float)(v70.c * (float)v50)));
      idWinding::AddPoint(this: &v77, v: &v72);
      idWinding::AddPoint(this: &v77, v: &v71);
      idWinding::AddPoint(this: &v77, v: &v73);
      idCollisionModelBuilder::PolygonFromWinding(model, w: &v77, plane: &v70, material, primitiveNum: -primitiveNum);
      v77.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
      v77.p = nullptr;
      idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
      v77.p = nullptr;
    }
    goto _M245299;
  }
}


// ========================================================================
// __unwind$244795
// EA  : 0x825CE164
// RVA : 0x005CE164
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_244795()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 4336 + 192));
}


// ========================================================================
// __unwind$244796
// EA  : 0x825CE18C
// RVA : 0x005CE18C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_244796()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 4336 + 1488));
}


// ========================================================================
// __unwind$244797
// EA  : 0x825CE1B4
// RVA : 0x005CE1B4
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_244797()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 4336 + 2784));
}


// ========================================================================
// ?ConvertBrushSides@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PBVidMapBrush@@ABVidVec3@@ABVidMat3@@2PBVidMaterial@@H@Z
// EA  : 0x825CE1E8
// RVA : 0x005CE1E8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::ConvertBrushSides(
        cm_buildModel_t *model,
        D3DXShader::CTErrors *mapBrush,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *scale,
        const idMaterial *overrideClipMaterial,
        int primitiveNum)
{
  float *v12; // r23
  int v13; // r28
  float *v14; // r30
  idMapBrushSide *LocalUserByIndex; // r3
  const idPlane *Plane; // r3
  double v17; // fp6
  double y; // fp1
  double v19; // fp11
  double v20; // fp10
  double z; // fp0
  double v22; // fp12
  double v23; // fp9
  int v24; // r24
  float *v25; // r27
  bfx::Planner3D *v26; // r3
  const idMaterial *v27; // r25
  const char *TypeDef; // r4
  const idDecl *v29; // r3
  double v30; // fp12
  double v31; // fp10
  double v32; // fp8
  signed int v33; // r30
  bool v34; // r5
  float *v35; // r29
  double v36; // fp12
  double v37; // fp10
  double v38; // fp8
  unsigned int NumLocalUsers; // [sp+54h] [-5ECh]
  idVec3 v40; // [sp+60h] [-5E0h] BYREF
  float v41; // [sp+6Ch] [-5D4h]
  idPlane v42; // [sp+70h] [-5D0h] BYREF
  idFixedWinding v43; // [sp+80h] [-5C0h] BYREF

  NumLocalUsers = idSignInManagerXbox::GetNumLocalUsers(this: mapBrush);
  v12 = (float *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                   size: 16 * NumLocalUsers,
                   tag: TAG_TEMP,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v13 = 0;
  if ( (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) > 0 )
  {
    v14 = v12 + 2;
    do
    {
      LocalUserByIndex = idSignInManagerXbox::GetLocalUserByIndex(this: (idMapBrush *)mapBrush, i: v13);
      Plane = idMapBrushSide::GetPlane(this: LocalUserByIndex);
      *(v14 - 2) = Plane->a;
      *(v14 - 1) = Plane->b;
      *v14 = Plane->c;
      v14[1] = Plane->d;
      idPlane::FixDegeneracies(this: (idPlane *)(v14 - 2), distEpsilon: 0.000099999997);
      v17 = *(v14 - 2);
      ++v13;
      y = axis->mat[0].y;
      v19 = (float)((float)(*(v14 - 1) * axis->mat[1].y) + (float)(*v14 * axis->mat[2].y));
      v20 = (float)((float)(*(v14 - 1) * axis->mat[1].z) + (float)(*v14 * axis->mat[2].z));
      z = axis->mat[0].z;
      v22 = v14[1];
      v23 = (float)((float)(*(v14 - 1) * axis->mat[1].x)
                  + (float)((float)(*(v14 - 2) * axis->mat[0].x) + (float)(*v14 * axis->mat[2].x)));
      *(v14 - 2) = (float)(*(v14 - 1) * axis->mat[1].x)
                 + (float)((float)(*(v14 - 2) * axis->mat[0].x) + (float)(*v14 * axis->mat[2].x));
      *(v14 - 1) = (float)((float)v17 * (float)y) + (float)v19;
      *v14 = (float)((float)v17 * (float)z) + (float)v20;
      v14[1] = (float)v22
             - (float)((float)((float)((float)((float)v17 * (float)z) + (float)v20) * origin->z)
                     + (float)((float)(origin->x * (float)v23)
                             + (float)(origin->y * (float)((float)((float)v17 * (float)y) + (float)v19))));
      v14 += 4;
    }
    while ( v13 < (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) );
  }
  v24 = 0;
  if ( (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) > 0 )
  {
    v25 = v12 + 2;
    do
    {
      v26 = (bfx::Planner3D *)idSignInManagerXbox::GetLocalUserByIndex(this: (idMapBrush *)mapBrush, i: v24);
      if ( overrideClipMaterial != nullptr )
      {
        v27 = overrideClipMaterial;
      }
      else
      {
        TypeDef = (const char *)idScriptObject::GetTypeDef(this: v26);
        if ( TypeDef != nullptr )
          v29 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: TypeDef, makeDefault: true);
        else
          v29 = nullptr;
        v27 = (const idMaterial *)v29;
      }
      if ( (idParmBlock::GetInteger(this: &v27->parmBlock, parm: rp->contentFlags) & 0xEBFFFFFF) != 0 )
      {
        v43.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
        v43.numPoints = 0;
        v43.p = v43.data;
        v43.allocedSize = 64;
        v30 = -v25[1];
        v31 = -*v25;
        v32 = -*(v25 - 1);
        v40.x = -*(v25 - 2);
        v41 = v30;
        v40.z = v31;
        v40.y = v32;
        idWinding::BaseForPlane(this: &v43, normal: &v40, dist: -v30, radius: 131072.0);
        v33 = 0;
        if ( (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) <= 0 )
        {
LABEL_19:
          if ( v43.numPoints != 0 )
            idCollisionModelBuilder::PolygonFromWinding(
              model,
              w: &v43,
              plane: (idPlane *)(v25 - 2),
              material: v27,
              primitiveNum);
        }
        else
        {
          v35 = v12 + 2;
          while ( v43.numPoints != 0 )
          {
            if ( v24 != v33 )
            {
              v36 = -v35[1];
              v37 = -*v35;
              v38 = -*(v35 - 1);
              v42.a = -*(v35 - 2);
              v42.d = v36;
              v42.c = v37;
              v42.b = v38;
              idWinding::ClipInPlace(this: &v43, plane: &v42, epsilon: 0.0, keepOn: v34);
            }
            ++v33;
            v35 += 4;
            if ( v33 >= (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) )
              goto LABEL_19;
          }
        }
        v43.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
        v43.p = nullptr;
        idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
        v43.p = nullptr;
      }
      ++v24;
      v25 += 4;
    }
    while ( v24 < (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) );
  }
  if ( v12 != nullptr )
    idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
}


// ========================================================================
// __unwind$245674
// EA  : 0x825CE574
// RVA : 0x005CE574
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_245674()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 1600 + 80));
}


// ========================================================================
// __unwind$245675
// EA  : 0x825CE59C
// RVA : 0x005CE59C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_245675()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 1600 + 128));
}


// ========================================================================
// ?ConvertBrush@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PBVidMapBrush@@ABVidVec3@@ABVidMat3@@2PBVidMaterial@@H@Z
// EA  : 0x825CE5D0
// RVA : 0x005CE5D0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::ConvertBrush(
        cm_buildModel_t *model,
        D3DXShader::CTErrors *mapBrush,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *scale,
        const idMaterial *overrideClipMaterial,
        int primitiveNum)
{
  signed int v8; // r27
  int v16; // r23
  int v18; // r22
  float *v21; // r19
  int v22; // r26
  float *v23; // r30
  idMapBrushSide *LocalUserByIndex; // r3
  const idPlane *Plane; // r3
  double v26; // fp0
  double v27; // fp6
  double y; // fp1
  double v29; // fp9
  double v30; // fp8
  double z; // fp12
  double v32; // fp11
  double v33; // fp7
  double v34; // fp6
  int v35; // r21
  float *v36; // r29
  bfx::Planner3D *v37; // r3
  const idMaterial *v38; // r10
  const char *TypeDef; // r4
  idParmBlock *p_parmBlock; // r30
  int Integer; // r3
  int v42; // r24
  double v43; // fp0
  double v44; // fp13
  double v45; // fp11
  signed int v46; // r30
  bool v47; // r5
  float *v48; // r26
  double v49; // fp0
  double v50; // fp13
  double v51; // fp11
  idVec5 *p; // r11
  int i; // ctr
  float *v60; // r4
  int v61; // r3
  cm_buildPolytope_t *v62; // r30
  float *v63; // r29
  int v64; // r11
  idPlane *v65; // r8
  float v66; // r5
  int v67; // r4
  cm_buildNode_t *node; // r29
  cm_buildPolytopeRef_t *v69; // r3
  unsigned int NumLocalUsers; // [sp+5Ch] [-624h]
  idVec3 v71; // [sp+60h] [-620h] BYREF
  float v72; // [sp+6Ch] [-614h]
  idPlane v73; // [sp+70h] [-610h] BYREF
  idVec3 *v74; // [sp+80h] [-600h]
  idWinding v75; // [sp+90h] [-5F0h] BYREF
  int v76; // [sp+A0h] [-5E0h] BYREF

  v8 = 0;
  _FP31 = 1.0e30;
  _FP30 = -1.0e30;
  _FP29 = 1.0e30;
  v16 = 0;
  _FP28 = 1.0e30;
  v18 = 0;
  _FP26 = -1.0e30;
  _FP27 = -1.0e30;
  NumLocalUsers = idSignInManagerXbox::GetNumLocalUsers(this: mapBrush);
  v21 = (float *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                   size: 16 * NumLocalUsers,
                   tag: TAG_TEMP,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v22 = 0;
  if ( (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) > 0 )
  {
    v23 = v21 + 2;
    do
    {
      LocalUserByIndex = idSignInManagerXbox::GetLocalUserByIndex(this: (idMapBrush *)mapBrush, i: v22);
      Plane = idMapBrushSide::GetPlane(this: LocalUserByIndex);
      *(v23 - 2) = Plane->a;
      *(v23 - 1) = Plane->b;
      *v23 = Plane->c;
      v23[1] = Plane->d;
      idPlane::FixDegeneracies(this: (idPlane *)(v23 - 2), distEpsilon: 0.000099999997);
      v26 = *v23;
      ++v22;
      v27 = *(v23 - 2);
      y = axis->mat[0].y;
      v29 = (float)((float)(axis->mat[1].y * *(v23 - 1)) + (float)(axis->mat[2].y * *v23));
      v30 = (float)((float)(*(v23 - 2) * axis->mat[0].z) + (float)(axis->mat[1].z * *(v23 - 1)));
      z = axis->mat[2].z;
      v32 = v23[1];
      v33 = (float)((float)(axis->mat[0].x * *(v23 - 2))
                  + (float)((float)(axis->mat[1].x * *(v23 - 1)) + (float)(axis->mat[2].x * *v23)));
      *(v23 - 2) = (float)(axis->mat[0].x * *(v23 - 2))
                 + (float)((float)(axis->mat[1].x * *(v23 - 1)) + (float)(axis->mat[2].x * *v23));
      v34 = (float)((float)((float)y * (float)v27) + (float)v29);
      *(v23 - 1) = v34;
      *v23 = (float)((float)z * (float)v26) + (float)v30;
      v23[1] = (float)v32
             - (float)((float)((float)v34 * origin->y)
                     + (float)((float)(origin->x * (float)v33)
                             + (float)((float)((float)((float)z * (float)v26) + (float)v30) * origin->z)));
      v23 += 4;
    }
    while ( v22 < (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) );
  }
  v35 = 0;
  if ( (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) <= 0 )
    goto LABEL_22;
  v36 = v21 + 2;
  do
  {
    v37 = (bfx::Planner3D *)idSignInManagerXbox::GetLocalUserByIndex(this: (idMapBrush *)mapBrush, i: v35);
    if ( overrideClipMaterial != nullptr )
    {
      v38 = overrideClipMaterial;
    }
    else
    {
      TypeDef = (const char *)idScriptObject::GetTypeDef(this: v37);
      if ( TypeDef != nullptr )
        v38 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                    this: &idMaterial::resourceList,
                                    name: TypeDef,
                                    makeDefault: true);
      else
        v38 = nullptr;
    }
    p_parmBlock = &v38->parmBlock;
    v16 |= idParmBlock::GetInteger(this: &v38->parmBlock, parm: rp->contentFlags) & 0xEBFFFFFF;
    v18 |= idParmBlock::GetInteger(this: p_parmBlock, parm: rp->surfaceFlags);
    Integer = idParmBlock::GetInteger(this: p_parmBlock, parm: rp->surfaceType);
    v75.__vftable = (idWinding_vtbl *)&idFixedWinding::`vftable';
    v75.numPoints = 0;
    v42 = Integer;
    v75.p = (idVec5 *)&v76;
    v75.allocedSize = 64;
    v43 = v36[1];
    v44 = *v36;
    v45 = *(v36 - 1);
    v71.x = -*(v36 - 2);
    v72 = -v43;
    v71.z = -v44;
    v71.y = -v45;
    idWinding::BaseForPlane(this: &v75, normal: &v71, dist: --v43, radius: 131072.0);
    v46 = 0;
    if ( (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) <= 0 )
    {
LABEL_17:
      if ( v75.numPoints > 0 )
      {
        p = v75.p;
        for ( i = v75.numPoints; i != 0; --i )
        {
          _FP6 = (float)((float)_FP28 - p->y);
          _FP10 = (float)((float)_FP29 - p->z);
          _FP12 = (float)((float)_FP31 - p->x);
          _FP8 = (float)(p->x - (float)_FP30);
          _FP5 = (float)(p->y - (float)_FP27);
          _FP3 = (float)(p->z - (float)_FP26);
          ++p;
          __asm
          {
            fsel      f28, f6, f9, f28
            fsel      f29, f10, f13, f29
            fsel      f31, f12, f0, f31
            fsel      f30, f8, f0, f30
            fsel      f27, f5, f9, f27
            fsel      f26, f3, f13, f26
          }
        }
      }
    }
    else
    {
      v48 = v21 + 2;
      while ( v75.numPoints != 0 )
      {
        if ( v35 != v46 )
        {
          v49 = v48[1];
          v50 = *v48;
          v51 = *(v48 - 1);
          v73.a = -*(v48 - 2);
          v73.d = -v49;
          v73.c = -v50;
          v73.b = -v51;
          idWinding::ClipInPlace(this: &v75, plane: &v73, epsilon: 0.0, keepOn: v47);
        }
        ++v46;
        v48 += 4;
        if ( v46 >= (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) )
          goto LABEL_17;
      }
    }
    v75.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
    v75.p = nullptr;
    idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
    v75.p = nullptr;
    ++v35;
    v36 += 4;
  }
  while ( v35 < (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) );
  if ( v16 == 0 )
  {
LABEL_22:
    if ( v21 == nullptr )
      return;
    v60 = v21;
    goto LABEL_34;
  }
  if ( _FP31 > _FP30 )
  {
    idLib::Warning(fmt: "primitive %d has inside out bounds", primitiveNum);
    v60 = v21;
    if ( v21 == nullptr )
      return;
    goto LABEL_34;
  }
  v61 = idSignInManagerXbox::GetNumLocalUsers(this: mapBrush);
  v62 = idCollisionModelBuilder::AllocPolytope(model, numPlanes: v61);
  v62->bounds.b[0].x = _FP31;
  v74 = &v62->bounds.b[1];
  v62->bounds.b[0].y = _FP28;
  v62->bounds.b[0].z = _FP29;
  v62->bounds.b[1].x = _FP30;
  v62->bounds.b[1].y = _FP27;
  v62->bounds.b[1].z = _FP26;
  v62->contents = v16;
  v62->material = idCollisionModelBuilder::FindMaterial(model, contentFlags: v16, surfaceFlags: v18, surfaceType: v42);
  v62->primitiveNum = primitiveNum;
  v62->numPlanes = idSignInManagerXbox::GetNumLocalUsers(this: mapBrush);
  if ( (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) > 0 )
  {
    v63 = v21;
    do
    {
      v64 = v62->firstPlane + v8++;
      v65 = &model->polytopePlanes[v64];
      v65->a = *v63;
      v65->b = v63[1];
      v65->c = v63[2];
      v66 = v63[3];
      v63 += 4;
      v65->d = v66;
    }
    while ( v8 < (int)idSignInManagerXbox::GetNumLocalUsers(this: mapBrush) );
  }
  v67 = 8;
  node = model->node;
  if ( model->numPolytopeRefs >= 8 )
    v67 = 256;
  v69 = idCollisionModelBuilder::AllocPolytopeReference(model, blockSize: v67);
  v69->polytopeNum = v62 - model->polytopes;
  v69->next = node->polytopes;
  node->polytopes = v69;
  ++model->numPolytopeRefs;
  if ( v21 != nullptr )
  {
    v60 = v21;
LABEL_34:
    idMem::Free(this: &mem, ptr: v60, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$245883
// EA  : 0x825CEB64
// RVA : 0x005CEB64
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_245883()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 1664 + 88));
}


// ========================================================================
// __unwind$245884
// EA  : 0x825CEB8C
// RVA : 0x005CEB8C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_245884()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 1664 + 144));
}


// ========================================================================
// ?ConvertMapModelPolytopes@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@ABVidStaticModelGeometry@1@HH@Z
// EA  : 0x825CEBB8
// RVA : 0x005CEBB8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::ConvertMapModelPolytopes(
        cm_buildModel_t *model,
        const idCollisionModelBuilder::idStaticModelGeometry *modelGeom,
        int groupNum,
        int primitiveNum)
{
  double v5; // fp7
  double v6; // fp5
  double v8; // fp3
  double v9; // fp1
  double v11; // fp12
  double v12; // fp10
  double v13; // fp6
  double v14; // fp4
  idMat3 *p_axis; // r28
  idVec3 *p_scale; // r26
  int v18; // r29
  int v19; // r27
  D3DXShader::CTErrors *JobNote; // r4
  idMat3 v21; // [sp+50h] [-70h] BYREF

  v5 = (float)(modelGeom->axis.mat[1].y * modelGeom->scale.y);
  v6 = (float)(modelGeom->axis.mat[1].z * modelGeom->scale.y);
  v8 = (float)(modelGeom->axis.mat[0].x * modelGeom->scale.x);
  v9 = (float)(modelGeom->axis.mat[0].y * modelGeom->scale.x);
  v11 = (float)(modelGeom->axis.mat[0].z * modelGeom->scale.x);
  v12 = (float)(modelGeom->scale.z * modelGeom->axis.mat[2].x);
  v13 = (float)(modelGeom->axis.mat[2].y * modelGeom->scale.z);
  v14 = (float)(modelGeom->axis.mat[2].z * modelGeom->scale.z);
  v21.mat[1].x = modelGeom->axis.mat[1].x * modelGeom->scale.y;
  v21.mat[1].y = v5;
  v21.mat[1].z = v6;
  p_axis = &modelGeom->axis;
  v21.mat[0].x = v8;
  p_scale = &modelGeom->scale;
  v21.mat[0].y = v9;
  v21.mat[0].z = v11;
  v21.mat[2].x = v12;
  v21.mat[2].y = v13;
  v21.mat[2].z = v14;
  if ( idMat3::Determinant(this: &v21) <= 0.0 )
    idLib::Error(fmt: "map model %s is inverted", model->name.data);
  v18 = 0;
  if ( (int)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)modelGeom->mapModel) > 0 )
  {
    v19 = 0;
    do
    {
      if ( modelGeom->primitiveGroupNumbers.list[v19] == groupNum )
      {
        JobNote = (D3DXShader::CTErrors *)idJob::GetJobNote(this: (idMapModel *)modelGeom->mapModel, i: v18);
        if ( JobNote->m_pErrors == nullptr )
          idCollisionModelBuilder::ConvertBrush(
            model,
            mapBrush: JobNote,
            origin: &modelGeom->origin,
            axis: p_axis,
            scale: p_scale,
            overrideClipMaterial: modelGeom->overrideClipMaterial,
            primitiveNum);
      }
      ++v18;
      ++v19;
      ++primitiveNum;
    }
    while ( v18 < (int)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)modelGeom->mapModel) );
  }
}


// ========================================================================
// ?ConvertRenderModelSurfaces@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@ABVidStaticModelGeometry@1@HH@Z
// EA  : 0x825CED20
// RVA : 0x005CED20
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::ConvertRenderModelSurfaces(
        cm_buildModel_t *model,
        const idCollisionModelBuilder::idStaticModelGeometry *modelGeom,
        int groupNum,
        int primitiveNum)
{
  double v4; // fp9
  double v6; // fp5
  double v7; // fp1
  double v8; // fp7
  double v9; // fp3
  double v10; // fp10
  double v11; // fp2
  double v12; // fp0
  int num; // r11
  int v16; // r29
  int v17; // r16
  int v18; // r17
  int v19; // r15
  idStaticModelSurface *v20; // r30
  idTriangles *StandardTriangles; // r3
  idTriangles *v22; // r26
  idDrawVert *verts; // r28
  const idMaterial *overrideClipMaterial; // r24
  int v25; // r27
  idVec3 *p_origin; // r30
  unsigned __int16 *v27; // r29
  float *v28; // r11
  double y; // fp12
  double x; // fp31
  double v31; // fp7
  double v32; // fp6
  float *v33; // r11
  double v34; // fp0
  double v35; // fp31
  double v36; // fp9
  double v37; // fp8
  const idVec3 *v38; // r4
  double v39; // fp3
  double v40; // fp2
  float *v41; // r11
  double v42; // fp12
  double v43; // fp11
  float *v44; // r11
  double v45; // fp0
  double v46; // fp31
  double v47; // fp9
  double v48; // fp8
  double v49; // fp3
  double v50; // fp2
  float *v51; // r11
  double v52; // fp12
  double v53; // fp11
  bool v54; // [sp+50h] [-670h]
  idMat3 v55; // [sp+60h] [-660h] BYREF
  idFixedWinding_vtbl *v56; // [sp+84h] [-63Ch]
  int v57; // [sp+88h] [-638h]
  idPlane v58; // [sp+90h] [-630h] BYREF
  idVec3 v59; // [sp+A0h] [-620h] BYREF
  idVec3 v60; // [sp+B0h] [-610h] BYREF
  idVec3 v61; // [sp+C0h] [-600h] BYREF
  idVec3 v62; // [sp+D0h] [-5F0h] BYREF
  float v63[4]; // [sp+E0h] [-5E0h] BYREF
  float v64[4]; // [sp+F0h] [-5D0h] BYREF
  idPlane v65; // [sp+100h] [-5C0h]
  idFixedWinding v66; // [sp+110h] [-5B0h] BYREF

  v4 = (float)(modelGeom->axis.mat[0].z * modelGeom->scale.x);
  v6 = (float)(modelGeom->axis.mat[1].z * modelGeom->scale.y);
  v7 = (float)(modelGeom->axis.mat[2].z * modelGeom->scale.z);
  v8 = (float)(modelGeom->axis.mat[0].y * modelGeom->scale.x);
  v9 = (float)(modelGeom->axis.mat[1].y * modelGeom->scale.y);
  v10 = (float)(modelGeom->axis.mat[2].y * modelGeom->scale.z);
  v11 = (float)(modelGeom->axis.mat[1].x * modelGeom->scale.y);
  v12 = (float)(modelGeom->axis.mat[2].x * modelGeom->scale.z);
  v55.mat[0].x = modelGeom->axis.mat[0].x * modelGeom->scale.x;
  v55.mat[1].x = v11;
  v55.mat[2].x = v12;
  v55.mat[0].z = v4;
  v55.mat[0].y = v8;
  v55.mat[1].z = v6;
  v55.mat[1].y = v9;
  v55.mat[2].z = v7;
  v56 = (idFixedWinding_vtbl *)&modelGeom->axis.mat[2];
  v55.mat[2].y = v10;
  v54 = idMat3::Determinant(this: &v55) < 0.0;
  if ( modelGeom->staticModel != nullptr )
    num = modelGeom->staticModel->surfaces.num;
  else
    num = modelGeom->renderModel->surfaces.num;
  if ( num > 0 )
  {
    v57 = num;
    v16 = num;
    v17 = 0;
    v18 = 0;
    v56 = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
    v19 = 0;
    do
    {
      if ( modelGeom->primitiveGroupNumbers.list[v19] == groupNum )
      {
        v20 = modelGeom->staticModel != nullptr
            ? &modelGeom->staticModel->surfaces.list[v18]
            : (idStaticModelSurface *)&modelGeom->renderModel->surfaces.list[v17];
        StandardTriangles = idTriangles::CreateStandardTriangles(this: v20->geometry);
        v22 = StandardTriangles;
        if ( StandardTriangles != nullptr )
        {
          verts = StandardTriangles->verts;
          overrideClipMaterial = modelGeom->overrideClipMaterial;
          if ( overrideClipMaterial == nullptr )
            overrideClipMaterial = v20->material;
          v25 = 0;
          if ( StandardTriangles->numIndexes > 0 )
          {
            p_origin = &modelGeom->origin;
            v27 = StandardTriangles->indexes + 1;
            do
            {
              v66.p = v66.data;
              v66.allocedSize = 64;
              v66.__vftable = v56;
              v66.numPoints = 0;
              v28 = (float *)((char *)&verts->xyz.x + __ROL4__(v27[1], 5));
              y = modelGeom->origin.y;
              x = p_origin->x;
              v31 = (float)((float)(v55.mat[1].y * v28[1])
                          + (float)((float)(v55.mat[0].y * *v28) + (float)(v55.mat[2].y * v28[2])));
              v32 = (float)((float)(v55.mat[0].x * *v28)
                          + (float)((float)(v55.mat[2].x * v28[2]) + (float)(v55.mat[1].x * v28[1])));
              if ( v54 )
              {
                v61.z = modelGeom->origin.z
                      + (float)((float)(v55.mat[1].z * v28[1])
                              + (float)((float)(v55.mat[0].z * *v28) + (float)(v55.mat[2].z * v28[2])));
                v61.y = (float)y + (float)v31;
                v61.x = (float)x + (float)v32;
                idWinding::AddPoint(this: &v66, v: &v61);
                v33 = (float *)((char *)&verts->xyz.x + __ROL4__(*(v27 - 1), 5));
                v34 = modelGeom->origin.y;
                v35 = p_origin->x;
                v36 = (float)((float)(v55.mat[1].y * v33[1])
                            + (float)((float)(v55.mat[0].y * *v33) + (float)(v55.mat[2].y * v33[2])));
                v37 = (float)((float)(v55.mat[0].x * *v33)
                            + (float)((float)(v55.mat[2].x * v33[2]) + (float)(v55.mat[1].x * v33[1])));
                v60.z = modelGeom->origin.z
                      + (float)((float)(v55.mat[1].z * v33[1])
                              + (float)((float)(v55.mat[0].z * *v33) + (float)(v55.mat[2].z * v33[2])));
                v60.y = (float)v34 + (float)v36;
                v60.x = (float)v35 + (float)v37;
                idWinding::AddPoint(this: &v66, v: &v60);
                v38 = (const idVec3 *)v63;
                v39 = modelGeom->origin.y;
                v40 = p_origin->x;
                v41 = (float *)((char *)&verts->xyz.x + __ROL4__(*v27, 5));
                v42 = (float)((float)(v55.mat[1].y * v41[1])
                            + (float)((float)(v55.mat[0].y * *v41) + (float)(v55.mat[2].y * v41[2])));
                v43 = (float)((float)(v55.mat[0].x * *v41)
                            + (float)((float)(v55.mat[2].x * v41[2]) + (float)(v55.mat[1].x * v41[1])));
                v63[2] = modelGeom->origin.z
                       + (float)((float)(v55.mat[1].z * v41[1])
                               + (float)((float)(v55.mat[0].z * *v41) + (float)(v55.mat[2].z * v41[2])));
                v63[1] = (float)v39 + (float)v42;
                v63[0] = (float)v40 + (float)v43;
              }
              else
              {
                v59.z = (float)((float)(v55.mat[1].z * v28[1])
                              + (float)((float)(v55.mat[0].z * *v28) + (float)(v55.mat[2].z * v28[2])))
                      + modelGeom->origin.z;
                v59.y = (float)y + (float)v31;
                v59.x = (float)v32 + (float)x;
                idWinding::AddPoint(this: &v66, v: &v59);
                v44 = (float *)((char *)&verts->xyz.x + __ROL4__(*v27, 5));
                v45 = modelGeom->origin.y;
                v46 = p_origin->x;
                v47 = (float)((float)(v55.mat[1].y * v44[1])
                            + (float)((float)(v55.mat[0].y * *v44) + (float)(v55.mat[2].y * v44[2])));
                v48 = (float)((float)(v55.mat[0].x * *v44)
                            + (float)((float)(v55.mat[2].x * v44[2]) + (float)(v55.mat[1].x * v44[1])));
                v62.z = (float)((float)(v55.mat[1].z * v44[1])
                              + (float)((float)(v55.mat[0].z * *v44) + (float)(v55.mat[2].z * v44[2])))
                      + modelGeom->origin.z;
                v62.y = (float)v45 + (float)v47;
                v62.x = (float)v48 + (float)v46;
                idWinding::AddPoint(this: &v66, v: &v62);
                v38 = (const idVec3 *)v64;
                v49 = modelGeom->origin.y;
                v50 = p_origin->x;
                v51 = (float *)((char *)&verts->xyz.x + __ROL4__(*(v27 - 1), 5));
                v52 = (float)((float)(v55.mat[1].y * v51[1])
                            + (float)((float)(v55.mat[0].y * *v51) + (float)(v55.mat[2].y * v51[2])));
                v53 = (float)((float)(v55.mat[0].x * *v51)
                            + (float)((float)(v55.mat[2].x * v51[2]) + (float)(v55.mat[1].x * v51[1])));
                v64[2] = (float)((float)(v55.mat[1].z * v51[1])
                               + (float)((float)(v55.mat[0].z * *v51) + (float)(v55.mat[2].z * v51[2])))
                       + modelGeom->origin.z;
                v64[1] = (float)v49 + (float)v52;
                v64[0] = (float)v53 + (float)v50;
              }
              idWinding::AddPoint(this: &v66, v: v38);
              idWinding::GetPlane(this: &v66, plane: &v58);
              v65.a = -v58.a;
              v65.d = -v58.d;
              v65.c = -v58.c;
              v65.b = -v58.b;
              v58 = v65;
              idCollisionModelBuilder::PolygonFromWinding(
                model,
                w: &v66,
                plane: &v58,
                material: overrideClipMaterial,
                primitiveNum);
              v66.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
              v66.p = nullptr;
              idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
              v25 += 3;
              v66.p = nullptr;
              v27 += 3;
            }
            while ( v25 < v22->numIndexes );
            v16 = v57;
          }
          idTriangles::~idTriangles(this: v22);
          idMem::Free(this: &mem, ptr: v22, align: ALIGN_16);
        }
      }
      --v16;
      ++v19;
      v57 = v16;
      ++v18;
      ++v17;
      ++primitiveNum;
    }
    while ( v16 != 0 );
  }
}


// ========================================================================
// __unwind$246441
// EA  : 0x825CF348
// RVA : 0x005CF348
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_246441()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 1728 + 272));
}


// ========================================================================
// ?BuildForGrid@idCollisionModelBuilder@@SA_NPAVidCollisionModelLocal@@PBDABVidGenGridModel@@ABVidCollisionGridState@@PBVidMaterial@@@Z
// EA  : 0x825CF378
// RVA : 0x005CF378
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idCollisionModelBuilder::BuildForGrid(
        idCollisionModelLocal *model,
        const char *modelName,
        const idGenGridModel *genModel,
        idCollisionGridState *state,
        const idMaterial *material)
{
  const idMaterial *r; // r29
  idParmBlock *p_parmBlock; // r23
  int numActive; // r27
  volatile char *v11; // r3
  cm_subModel_t *subModels; // r8
  cm_subModel_t *v13; // r5
  cm_subModel_t *v14; // r11
  cm_subModelData_t *v15; // r10
  int numPrimitiveIndices; // r11
  int num; // r18
  int v19; // r21
  int v20; // r20
  int numEdges; // r25
  int v23; // r26
  int v25; // r27
  int v26; // r29
  __int64 v31; // r4 OVERLAPPED
  int v32; // r11
  int v33; // r11
  int v34; // r10
  cm_gridPart_t *v35; // r11
  int numPolygons; // r9
  __int64 v37; // r8 OVERLAPPED
  int v38; // r9
  cm_polygon_t *list; // r6
  int v40; // r8
  __int64 v41; // r6
  int v42; // r9
  __int64 v43; // fp10
  int v50; // r16
  cm_subModel_t *v51; // r29
  int v52; // r9
  cm_subModelData_t *data; // r11
  cm_material_t *materials; // r29
  int v55; // r7
  int v56; // r9
  int v57; // r10
  idVec3 *v58; // r8
  cm_vertex_t *v59; // r11
  idVec3 *v60; // r8
  cm_vertex_t *v61; // r11
  idVec3 *v62; // r8
  cm_vertex_t *v63; // r11
  idVec3 *v64; // r8
  cm_vertex_t *v65; // r11
  int v66; // r9
  int v67; // r8
  int v68; // ctr
  idVec3 *v69; // r10
  cm_vertex_t *v70; // r11
  double z; // fp12
  int v72; // r11
  int v73; // r10
  cm_edge_t *v74; // r8
  cm_edge_t *v75; // r7
  int v76; // r6
  int v77; // ctr
  int v78; // r10
  int v79; // r7
  int v80; // r8
  cm_gridNodeBSP_t *v81; // r9
  cm_node_t *v82; // r11
  int v83; // r24
  int v84; // r27
  int Active; // r3
  int v86; // r11
  int v87; // r11
  int v88; // r7
  int *v89; // r6
  cm_gridPart_t *v90; // r8
  int v91; // r11
  int v92; // r10
  int v93; // r6
  int v94; // r29
  int v95; // ctr
  cm_polygon_t *v96; // r11
  unsigned __int16 *p_firstEdge; // r10
  unsigned __int16 *v98; // r9
  int v99; // r10
  int v100; // r9
  int v101; // r5
  int v102; // r10
  int v103; // r10
  int v104; // r26
  int v105; // r29
  int v106; // r25
  cm_node_t *nodes; // r10
  int firstPrimitive; // r10
  int v109; // r11
  int v110; // r4
  int v111; // r30
  int v112; // r3
  int v113; // r11
  int v114; // ctr
  unsigned __int16 v115; // r5
  char *v116; // r7
  cm_polygon_t *v117; // r9
  char *v118; // r11
  unsigned __int16 *v119; // r10
  int v120; // r11
  int v121; // r10
  unsigned __int16 v122; // r10
  int v123; // r6
  unsigned __int16 v124; // r10
  int v125; // r11
  int i; // ctr
  double y; // fp13
  double v128; // fp12
  double x; // fp11
  double v130; // fp10
  double v131; // fp9
  __int64 v132; // [sp+50h] [-11D0h] BYREF
  idBounds v133; // [sp+60h] [-11C0h] BYREF
  cm_subModelPtrs_t v134; // [sp+80h] [-11A0h] BYREF
  cm_buildNodeStats_t v135; // [sp+B0h] [-1170h] BYREF
  __int64 v136; // [sp+E0h] [-1140h]
  __int64 v137; // [sp+E8h] [-1138h]
  __int64 v138; // [sp+F0h] [-1130h]
  __int64 v139; // [sp+F8h] [-1128h]
  __int64 v140; // [sp+100h] [-1120h]
  cm_buildNodeStats_t v141; // [sp+110h] [-1110h] BYREF
  idList<int,5> v142; // [sp+140h] [-10E0h] BYREF
  int v143; // [sp+150h] [-10D0h] BYREF

  r = material;
  if ( material == nullptr )
    r = (const idMaterial *)mtrGridModel.r;
  idResource::SetName(this: model, _name: modelName);
  p_parmBlock = &r->parmBlock;
  model->contents = idParmBlock::GetInteger(this: &r->parmBlock, parm: rp->contentFlags);
  model->isConvex = false;
  model->isWorldModel = false;
  model->isTraceModel = false;
  model->polygonModel.numModelTreeNodes = 0;
  model->polygonModel.modelTreeNodes = nullptr;
  numActive = state->numActive;
  model->polygonModel.numSubModels = 1;
  model->polygonModel.subModels = (cm_subModel_t *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(3595) : TAG_COLLISION",
                                                     size: 0x30u,
                                                     tag: TAG_COLLISION,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
  v11 = (volatile char *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(3596) : TAG_COLLISION",
                           size: 1u,
                           tag: TAG_COLLISION,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  subModels = model->polygonModel.subModels;
  model->polygonModel.subModelState = v11;
  subModels->state = v11;
  *model->polygonModel.subModelState = 1;
  if ( numActive > 0 )
  {
    *(_QWORD *)&v142.num = 1024;
    v142.list = &v143;
    *(_DWORD *)&v142.granularity = 66817;
    HIDWORD(v132) = 0;
    num = genModel->nodes.num;
    v19 = genModel->vertices.num;
    v20 = genModel->edges.num;
    v135.numMaterials = 1;
    LOBYTE(numEdges) = 0;
    _FP29 = 1.0e30;
    v23 = 0;
    _FP31 = -1.0e30;
    v133.b[0].z = 1.0e30;
    v133.b[1].z = -1.0e30;
    v135.numNodes = num;
    v133.b[0].y = 1.0e30;
    v135.numEdges = v20;
    v133.b[0].x = 1.0e30;
    v25 = 0;
    v133.b[1].y = v133.b[1].z;
    v135.numVertices = v19;
    v133.b[1].x = v133.b[1].z;
    v26 = 0;
    memset(&v135.numPolytopes, 0, 12);
    _FP28 = 1.0e30;
    _FP26 = 1.0e30;
    _FP30 = -1.0e30;
    _FP27 = -1.0e30;
    idList<idRenderModelCommitted *,5>::SetNum(this: &v142, newNum: num, initValue: (const int *)&v132);
    HIDWORD(v31) = idCollisionGridState::FirstActive(this: state);
    if ( v31 >= 0 )
    {
      v32 = HIDWORD(v31);
      do
      {
        v33 = genModel->indices.list[v32];
        if ( v33 != idGenGridModel::INVALID_INDEX )
        {
          v34 = 0;
          v35 = &genModel->parts.list[v33];
          numPolygons = v35->numPolygons;
          HIDWORD(v37) = __ROL4__(v35->nodeIndex, 2);
          v25 += numPolygons;
          v23 += numPolygons;
          *(int *)((char *)v142.list + HIDWORD(v37)) += __ROL4__(numPolygons, 1);
          v38 = v35->numPolygons;
          if ( v35->numPolygons != 0 )
          {
            HIDWORD(v37) = v35->firstPolygonIndex;
            list = genModel->polygons.list;
            do
            {
              v40 = HIDWORD(v37) + v34++;
              numEdges = list[v40].numEdges;
              v26 += numEdges;
              v135.lastNumPolygonEdges = numEdges;
            }
            while ( v34 < v38 );
          }
          LODWORD(v41) = v35->bounds.b[0][2];
          HIDWORD(v41) = v35->bounds.b[0][1];
          LOWORD(v37) = v35->bounds.b[1][2];
          LODWORD(v31) = v35->bounds.b[0][0];
          v42 = v35->bounds.b[1][0];
          v140 = v41;
          LODWORD(v37) = (__int16)v37;
          v139 = *(__int64 *)((char *)&v31 - 4);
          v136 = *(__int64 *)((char *)&v37 - 4);
          v138 = v37;
          v43 = v37;
          v137 = v31;
          HIDWORD(v37) = v35->bounds.b[1][1];
          v132 = *(__int64 *)((char *)&v37 + 4);
          _FP7 = (float)((float)*(__int64 *)((char *)&v37 + 4) - (float)_FP30);
          _FP10 = (float)((float)v43 - (float)_FP31);
          _FP9 = (float)((float)_FP26 - (float)v31);
          _FP8 = (float)((float)*(__int64 *)((char *)&v37 - 4) - (float)_FP27);
          _FP6 = (float)((float)_FP29 - (float)v41);
          _FP5 = (float)((float)_FP28 - (float)*(__int64 *)((char *)&v31 - 4));
          __asm
          {
            fsel      f30, f7, f13, f30
            fsel      f31, f10, f2, f31
            fsel      f26, f9, f1, f26
            fsel      f27, f8, f0, f27
            fsel      f29, f6, f12, f29
            fsel      f28, f5, f11, f28
          }
        }
        HIDWORD(v31) = idCollisionGridState::NextActive(this: state, id: SHIDWORD(v31));
        v32 = HIDWORD(v31);
      }
      while ( v31 >= 0 );
      v133.b[0].y = _FP28;
      v133.b[0].z = _FP29;
      v133.b[1].y = _FP30;
      v133.b[1].x = _FP27;
      v133.b[1].z = _FP31;
      v133.b[0].x = _FP26;
    }
    v50 = 0;
    if ( v26 > 0 )
      v50 = 4 - (numEdges & 3);
    v52 = v50 + 2 * v26;
    v51 = model->polygonModel.subModels;
    v135.numPolygons = 2 * v25;
    v135.numPolygonEdges = v52;
    v135.numPrimitiveIndices = 2 * v23;
    idCollisionModelBuilder::AllocSubModelData(stats: &v135, bounds: &v133, subModel: v51, subModelPtrs: &v134);
    data = v51->data;
    data->header.totalSize = v51->header.totalSize;
    HIDWORD(v132) = &data->header.bounds.b[1];
    data->header.loadedSize = v51->header.loadedSize;
    data->header.bounds.b[0].x = v51->header.bounds.b[0].x;
    data->header.bounds.b[0].y = v51->header.bounds.b[0].y;
    data->header.bounds.b[0].z = v51->header.bounds.b[0].z;
    data->header.bounds.b[1].x = v51->header.bounds.b[1].x;
    data->header.bounds.b[1].y = v51->header.bounds.b[1].y;
    data->header.bounds.b[1].z = v51->header.bounds.b[1].z;
    v51->data->header.loadedSize = v51->data->header.totalSize;
    v51->data->isConvex = 0;
    materials = v134.materials;
    materials->contentFlags = idParmBlock::GetInteger(this: p_parmBlock, parm: rp->contentFlags);
    materials->surfaceFlags = idParmBlock::GetInteger(this: p_parmBlock, parm: rp->surfaceFlags);
    materials->surfaceType = idParmBlock::GetInteger(this: p_parmBlock, parm: rp->surfaceType);
    v55 = 0;
    materials->surfaceColor[0] = -1;
    materials->surfaceColor[1] = -1;
    materials->surfaceColor[2] = -1;
    if ( v19 >= 4 )
    {
      v56 = 0;
      v57 = 0;
      do
      {
        v58 = &genModel->vertices.list[v56];
        v59 = &v134.vertices[v57];
        v55 += 4;
        v59->p.x = v58->x;
        v59->p.y = v58->y;
        v59->p.z = v58->z;
        v59->st[0] = 0;
        v59->st[1] = 0;
        v60 = &genModel->vertices.list[v56];
        v61 = &v134.vertices[v57];
        v61[1].p.x = v60[1].x;
        v61[1].p.y = v60[1].y;
        v61[1].p.z = v60[1].z;
        v61[1].st[0] = 0;
        v61[1].st[1] = 0;
        v62 = &genModel->vertices.list[v56 + 3];
        v63 = &v134.vertices[v57 + 3];
        v63[-1].p.x = v62[-1].x;
        v63[-1].p.y = v62[-1].y;
        v63[-1].p.z = v62[-1].z;
        v63[-1].st[0] = 0;
        v63[-1].st[1] = 0;
        v64 = &genModel->vertices.list[v56 + 3];
        v56 += 4;
        v65 = &v134.vertices[v57 + 3];
        v65->p.x = v64->x;
        v57 += 4;
        v65->p.y = v64->y;
        v65->p.z = v64->z;
        v65->st[0] = 0;
        v65->st[1] = 0;
      }
      while ( v55 < v19 - 3 );
    }
    if ( v55 < v19 )
    {
      v66 = v55;
      v67 = v55;
      v68 = v19 - v55;
      do
      {
        v69 = &genModel->vertices.list[v67];
        v70 = &v134.vertices[v66++];
        ++v67;
        v70->p.x = v69->x;
        v70->p.y = v69->y;
        z = v69->z;
        v70->st[0] = 0;
        v70->p.z = z;
        v70->st[1] = 0;
        --v68;
      }
      while ( v68 != 0 );
    }
    if ( v20 > 0 )
    {
      v72 = 0;
      v73 = v20;
      do
      {
        --v73;
        v74 = &genModel->edges.list[v72];
        v75 = &v134.edges[v72++];
        v75->vertexNum[0] = v74->vertexNum[0];
        v75->vertexNum[1] = v74->vertexNum[1];
      }
      while ( v73 != 0 );
    }
    v76 = 0;
    if ( num > 0 )
    {
      v77 = num;
      v78 = 0;
      v79 = 0;
      v80 = 0;
      do
      {
        v81 = &genModel->nodes.list[v79];
        v82 = &v134.nodes[v80++];
        ++v79;
        v82->children[0] = v81->children[0];
        v82->children[1] = v81->children[1];
        v82->planeDist = v81->planeDist;
        v82->planeType = v81->planeType;
        v82->numPolygons = v142.list[v78];
        v82->firstPrimitive = v76;
        v82->numPolytopes = 0;
        v76 += v142.list[v78];
        v142.list[v78++] = 0;
        --v77;
      }
      while ( v77 != 0 );
    }
    v83 = 0;
    v84 = 0;
    Active = idCollisionGridState::FirstActive(this: state);
    if ( Active >= 0 )
    {
      v86 = Active;
      do
      {
        v87 = genModel->indices.list[v86];
        if ( v87 != idGenGridModel::INVALID_INDEX )
        {
          v88 = 0;
          v89 = v142.list;
          v90 = &genModel->parts.list[v87];
          v91 = v90->numPolygons;
          v92 = *(int *)((char *)v142.list + __ROL4__(v90->nodeIndex, 2))
              + *(unsigned __int16 *)((char *)&v134.nodes->children[2] + __ROL4__(v90->nodeIndex, 4));
          if ( v90->numPolygons != 0 )
          {
            v93 = v84;
            v94 = v92;
            do
            {
              v134.primitiveIndices[v94] = v84++;
              v95 = 8;
              v96 = &v134.polygons[v93];
              p_firstEdge = &genModel->polygons.list[v90->firstPolygonIndex - 1 + v88].firstEdge;
              v98 = &v134.polygons[v93++ - 1].firstEdge;
              do
              {
                *++v98 = *++p_firstEdge;
                --v95;
              }
              while ( v95 != 0 );
              v99 = 0;
              if ( v96->numEdges != 0 )
              {
                v100 = v83;
                do
                {
                  v101 = v96->firstEdge + v99++;
                  v134.polygonEdges[v100++] = genModel->polygonEdges.list[v101];
                }
                while ( v99 < v96->numEdges );
              }
              v102 = v96->numEdges;
              ++v88;
              v96->firstEdge = v83;
              v83 += v102;
              v91 = v90->numPolygons;
              ++v94;
            }
            while ( v88 < v91 );
            v89 = v142.list;
          }
          v103 = __ROL4__(v90->nodeIndex, 2);
          *(int *)((char *)v89 + v103) += v91;
        }
        Active = idCollisionGridState::NextActive(this: state, id: Active);
        v86 = Active;
      }
      while ( Active >= 0 );
    }
    if ( num > 0 )
    {
      v104 = 0;
      v105 = 0;
      v106 = num;
      nodes = v134.nodes;
      do
      {
        firstPrimitive = nodes->firstPrimitive;
        v109 = v142.list[v105];
        if ( v109 > 0 )
        {
          v110 = firstPrimitive;
          v111 = v109 + firstPrimitive;
          v112 = v142.list[v105];
          do
          {
            v113 = v134.primitiveIndices[v110];
            v114 = 8;
            v115 = v113 + v84;
            v116 = (char *)v134.polygons + __ROL4__(v113, 4);
            v117 = &v134.polygons[v113 + v84];
            v118 = v116 - 2;
            v119 = &v117[-1].firstEdge;
            do
            {
              v118 += 2;
              *++v119 = *(_WORD *)v118;
              --v114;
            }
            while ( v114 != 0 );
            v117->firstEdge = v83;
            v120 = 0;
            v121 = (unsigned __int8)v116[13];
            if ( v116[13] != 0 )
            {
              do
              {
                v122 = v134.polygonEdges[*((unsigned __int16 *)v116 + 7) - v120 - 1 + v121];
                v123 = v117->firstEdge + v120;
                if ( (~v122 & 0x8000) != 0 )
                  v124 = v122 & 0x3FFF | 0x8000;
                else
                  v124 = v122 & 0x3FFF;
                ++v120;
                v134.polygonEdges[v123] = v124;
                v121 = (unsigned __int8)v116[13];
              }
              while ( v120 < v121 );
            }
            --v112;
            ++v110;
            v83 += v117->numEdges;
            v134.primitiveIndices[v111++] = v115;
          }
          while ( v112 != 0 );
        }
        ++v104;
        --v106;
        ++v105;
        nodes = &v134.nodes[v104];
      }
      while ( v106 != 0 );
    }
    if ( v50 > 0 )
    {
      v125 = v83;
      for ( i = v50; i != 0; --i )
        v134.polygonEdges[v125++] = v134.polygonEdges[v83 - 1];
    }
    y = v133.b[0].y;
    v128 = v133.b[0].z;
    x = v133.b[1].x;
    model->bounds.b[0].x = v133.b[0].x;
    HIDWORD(v132) = &model->bounds.b[1];
    v130 = v133.b[1].y;
    model->bounds.b[0].y = y;
    model->bounds.b[0].z = v128;
    model->bounds.b[1].x = x;
    v131 = v133.b[1].z;
    model->bounds.b[1].y = v130;
    model->bounds.b[1].z = v131;
    if ( (v142.listStatic == 0 || v142.listStatic == 2) && v142.list != nullptr )
      idMem::Free(this: &mem, ptr: v142.list, align: ALIGN_16);
    return 1;
  }
  else
  {
    v141.numNodes = 1;
    v141.numMaterials = 1;
    v141.numPrimitiveIndices = 1;
    v141.numPolygons = 1;
    v141.numEdges = 3;
    v141.numPolygonEdges = 4;
    v141.numVertices = 3;
    v133.b[0].x = -1.0;
    v141.numPolytopes = 0;
    v133.b[0].y = -1.0;
    v141.numPolytopePlanes = 0;
    v133.b[0].z = -1.0;
    v133.b[1].x = 1.0;
    v133.b[1].y = 1.0;
    v13 = model->polygonModel.subModels;
    v133.b[1].z = 1.0;
    idCollisionModelBuilder::AllocSubModelData(
      stats: &v141,
      bounds: &v133,
      subModel: v13,
      subModelPtrs: (cm_subModelPtrs_t *)&v135);
    v14 = model->polygonModel.subModels;
    HIDWORD(v132) = &v14->header.bounds;
    v15 = v14->data;
    v15->header.totalSize = v14->header.totalSize;
    HIDWORD(v132) = &v15->header.bounds.b[1];
    v15->header.loadedSize = v14->header.loadedSize;
    v15->header.bounds.b[0].x = v14->header.bounds.b[0].x;
    v15->header.bounds.b[0].y = v14->header.bounds.b[0].y;
    v15->header.bounds.b[0].z = v14->header.bounds.b[0].z;
    v15->header.bounds.b[1].x = v14->header.bounds.b[1].x;
    v15->header.bounds.b[1].y = v14->header.bounds.b[1].y;
    v15->header.bounds.b[1].z = v14->header.bounds.b[1].z;
    model->polygonModel.subModels->data->header.loadedSize = model->polygonModel.subModels->data->header.totalSize;
    model->polygonModel.subModels->data->isConvex = 0;
    numPrimitiveIndices = v135.numPrimitiveIndices;
    *(float *)(v135.numPrimitiveIndices + 4) = 0.0;
    *(_DWORD *)numPrimitiveIndices = -1;
    *(_WORD *)(numPrimitiveIndices + 8) = 0;
    *(_WORD *)(numPrimitiveIndices + 10) = 0;
    *(_WORD *)(numPrimitiveIndices + 12) = 0;
    *(_BYTE *)(numPrimitiveIndices + 14) = 0;
    *(_BYTE *)(numPrimitiveIndices + 15) = 0;
    return 0;
  }
}


// ========================================================================
// __unwind$246843
// EA  : 0x825CFE24
// RVA : 0x005CFE24
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_246843()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4640 + 320));
}


// ========================================================================
// ?ConvertPatch@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@PBVidMapPatch@@ABVidVec3@@ABVidMat3@@2PBVidMaterial@@H@Z
// EA  : 0x825D03F0
// RVA : 0x005D03F0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::ConvertPatch(
        cm_buildModel_t *model,
        idPhysics_AF *patch,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *scale,
        const idMaterial *overrideClipMaterial,
        int primitiveNum)
{
  const idMaterial *v13; // r28
  const char *Material; // r3
  idSurface_Patch *v15; // r3
  idSurface_Patch *p_clip; // r4
  idSurface_Patch *v17; // r30
  bool v18; // r4
  int NumConstraints; // r21
  int HorzSubdivisions; // r3

  if ( overrideClipMaterial != nullptr )
  {
    v13 = overrideClipMaterial;
  }
  else
  {
    Material = (const char *)idMapPatch::GetMaterial(hSSMDev: (void *)patch);
    if ( Material != nullptr )
      Material = (const char *)idDeclInfo::FindWithInheritance(
                                 this: &idMaterial::resourceList,
                                 name: Material,
                                 makeDefault: true);
    v13 = (const idMaterial *)Material;
  }
  if ( (idParmBlock::GetInteger(this: &v13->parmBlock, parm: rp->contentFlags) & 0xEBFFFFFF) != 0 )
  {
    v15 = (idSurface_Patch *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                               size: 0x54u,
                               tag: TAG_NEW,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    if ( v15 != nullptr )
    {
      p_clip = (idSurface_Patch *)&patch->clip;
      if ( patch == nullptr )
        p_clip = nullptr;
      v17 = idSurface_Patch::idSurface_Patch(this: v15, patch: p_clip);
    }
    else
    {
      v17 = nullptr;
    }
    if ( idMapPatch::GetExplicitlySubdivided(this: (idMapPatch *)patch) )
    {
      NumConstraints = idPhysics_AF::GetNumConstraints(this: patch);
      HorzSubdivisions = idMapPatch::GetHorzSubdivisions(this: (idMapPatch *)patch);
      idSurface_Patch::SubdivideExplicit(
        this: v17,
        horzSubdivisions: HorzSubdivisions,
        vertSubdivisions: NumConstraints,
        genNormals: false,
        removeLinear: true);
    }
    else
    {
      idSurface_Patch::Subdivide(
        this: v17,
        maxHorizontalError: 24.0,
        maxVerticalError: 24.0,
        maxLength: -1.0,
        genNormals: v18);
    }
    idCollisionModelBuilder::CreatePatchPolygons(model, mesh: v17, origin, axis, scale, material: v13, primitiveNum);
    if ( v17 != nullptr )
    {
      idSurface::~idSurface(this: (splineMoverModifier_t::splineMoverModifierSound_t *)v17);
      idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$247638
// EA  : 0x825D0578
// RVA : 0x005D0578
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall _unwind_247638(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 192 + 80), tag: a2);
}


// ========================================================================
// ?ConvertMapModelPrimitives@idCollisionModelBuilder@@CAXPAUcm_buildModel_t@@ABVidStaticModelGeometry@1@HH@Z
// EA  : 0x825D05A0
// RVA : 0x005D05A0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::ConvertMapModelPrimitives(
        cm_buildModel_t *model,
        const idCollisionModelBuilder::idStaticModelGeometry *modelGeom,
        int groupNum,
        int primitiveNum)
{
  double v5; // fp7
  double v6; // fp5
  double v8; // fp3
  double v9; // fp1
  double v11; // fp12
  double v12; // fp10
  double v13; // fp6
  double v14; // fp4
  idMat3 *p_axis; // r29
  idVec3 *p_scale; // r28
  int v18; // r27
  int v19; // r25
  idPhysics_AF *JobNote; // r3
  idPhysics *nextInHash; // r11
  idMat3 v22; // [sp+50h] [-70h] BYREF

  v5 = (float)(modelGeom->axis.mat[1].y * modelGeom->scale.y);
  v6 = (float)(modelGeom->axis.mat[1].z * modelGeom->scale.y);
  v8 = (float)(modelGeom->axis.mat[0].x * modelGeom->scale.x);
  v9 = (float)(modelGeom->axis.mat[0].y * modelGeom->scale.x);
  v11 = (float)(modelGeom->axis.mat[0].z * modelGeom->scale.x);
  v12 = (float)(modelGeom->scale.z * modelGeom->axis.mat[2].x);
  v13 = (float)(modelGeom->axis.mat[2].y * modelGeom->scale.z);
  v14 = (float)(modelGeom->axis.mat[2].z * modelGeom->scale.z);
  v22.mat[1].x = modelGeom->axis.mat[1].x * modelGeom->scale.y;
  v22.mat[1].y = v5;
  v22.mat[1].z = v6;
  p_axis = &modelGeom->axis;
  v22.mat[0].x = v8;
  p_scale = &modelGeom->scale;
  v22.mat[0].y = v9;
  v22.mat[0].z = v11;
  v22.mat[2].x = v12;
  v22.mat[2].y = v13;
  v22.mat[2].z = v14;
  if ( idMat3::Determinant(this: &v22) <= 0.0 )
    idLib::Error(fmt: "map model %s is inverted", model->name.data);
  v18 = 0;
  if ( (int)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)modelGeom->mapModel) > 0 )
  {
    v19 = 0;
    do
    {
      if ( modelGeom->primitiveGroupNumbers.list[v19] == groupNum )
      {
        JobNote = (idPhysics_AF *)idJob::GetJobNote(this: (idMapModel *)modelGeom->mapModel, i: v18);
        nextInHash = JobNote->nextInHash;
        if ( nextInHash != nullptr )
        {
          if ( nextInHash == (idPhysics *)1 )
            idCollisionModelBuilder::ConvertPatch(
              model,
              patch: JobNote,
              origin: &modelGeom->origin,
              axis: p_axis,
              scale: p_scale,
              overrideClipMaterial: modelGeom->overrideClipMaterial,
              primitiveNum);
        }
        else
        {
          idCollisionModelBuilder::ConvertBrushSides(
            model,
            mapBrush: (D3DXShader::CTErrors *)JobNote,
            origin: &modelGeom->origin,
            axis: p_axis,
            scale: p_scale,
            overrideClipMaterial: modelGeom->overrideClipMaterial,
            primitiveNum);
        }
      }
      ++v18;
      ++v19;
      ++primitiveNum;
    }
    while ( v18 < (int)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)modelGeom->mapModel) );
  }
}


// ========================================================================
// ?AddCollisionModelGeometry@idCollisionModelBuilder@@CAXPAVidCollisionModelLocal@@ABVidCollisionModelGeometry@1@H@Z
// EA  : 0x825D0730
// RVA : 0x005D0730
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::AddCollisionModelGeometry(
        idCollisionModelLocal *model,
        const idCollisionModelBuilder::idCollisionModelGeometry *collisionModelGeometry,
        int groupNum)
{
  int num; // r10
  int v7; // r29
  int v8; // r27
  int v9; // r28
  idCollisionModelBuilder::idStaticModelGeometry *v10; // r30
  int v11; // r11
  int v12; // r29
  cm_buildModel_t *v13; // r30
  cm_buildNode_t *v14; // r3
  int v15; // r9
  int v16; // r27
  int v17; // r28
  idCollisionModelBuilder::idStaticModelGeometry *v18; // r29
  char *v19; // r10
  int numPrimitives; // r10
  int v21; // r27
  int v22; // r28
  int v23; // r6
  idCollisionModelBuilder::idStaticModelGeometry *v24; // r29
  char *v25; // r10
  int v26; // r10
  cm_buildNode_t *node; // r4
  cm_buildNode_t *v28; // r4
  cm_buildNode_t *v29; // r4
  cm_buildNode_t *v30; // r4
  cm_buildMaterial_t *list; // r4
  int v32; // [sp+50h] [-80h] BYREF
  cm_buildMaterial_t *v33; // [sp+54h] [-7Ch] BYREF
  int v34[2]; // [sp+58h] [-78h] BYREF
  idBounds v35[4]; // [sp+60h] [-70h] BYREF

  num = collisionModelGeometry->models.num;
  v32 = 0;
  v33 = nullptr;
  v35[0].b[0].z = 1.0e30;
  v35[0].b[0].y = 1.0e30;
  v7 = 0;
  v35[0].b[0].x = 1.0e30;
  v34[0] = 0;
  v35[0].b[1].z = -1.0e30;
  v8 = 0;
  v35[0].b[1].y = v35[0].b[1].z;
  v35[0].b[1].x = v35[0].b[1].z;
  if ( num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = &collisionModelGeometry->models.list[v9];
      if ( v10->mapModel != nullptr )
      {
        idCollisionModelBuilder::AddMapModelEstimates(
          modelGeom: v10,
          groupNum,
          primitiveNum: v7,
          numVerts: &v32,
          numEdges: (int *)&v33,
          numPolys: v34,
          bounds: v35);
        v7 += (int)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)v10->mapModel);
      }
      else
      {
        idCollisionModelBuilder::AddRenderModelEstimates(
          modelGeom: v10,
          groupNum,
          primitiveNum: v7,
          numVerts: &v32,
          numEdges: (int *)&v33,
          numPolys: v34,
          bounds: v35);
        if ( v10->staticModel != nullptr )
          v11 = v10->staticModel->surfaces.num;
        else
          v11 = v10->renderModel->surfaces.num;
        v7 += v11;
      }
      ++v8;
      ++v9;
    }
    while ( v8 < collisionModelGeometry->models.num );
    v12 = v32;
    if ( v32 != 0 )
    {
      v13 = idCollisionModelBuilder::AllocBuildModel();
      idStr::operator=(this: &v13->name, text: model->name.str);
      v14 = idCollisionModelBuilder::AllocNode(model: v13, blockSize: 8);
      v15 = (int)v33;
      v13->node = v14;
      v13->isWorldModel = collisionModelGeometry->isWorldEntity;
      v13->maxEdges = v15;
      v13->maxVertices = v12;
      v13->numVertices = 0;
      v13->vertices = (cm_buildVertex_t *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(4398) : TAG_COLLISION",
                                            size: 24 * v12,
                                            tag: TAG_COLLISION,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      v13->numEdges = 0;
      v13->edges = (cm_buildEdge_t *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder.cpp(4400) : TAG_COLLISION",
                                       size: 32 * v13->maxEdges,
                                       tag: TAG_COLLISION,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
      idHashIndex::ResizeIndex(this: buildData.cm_vertexHash, newIndexSize: v13->maxVertices);
      idHashIndex::ResizeIndex(this: buildData.cm_edgeHash, newIndexSize: v13->maxEdges);
      v13->numPrimitives = 0;
      v16 = 0;
      if ( collisionModelGeometry->models.num > 0 )
      {
        v17 = 0;
        while ( 1 )
        {
          v18 = &collisionModelGeometry->models.list[v17];
          if ( v18->mapModel != nullptr )
            break;
          numPrimitives = v13->numPrimitives;
          if ( v18->staticModel == nullptr )
          {
            v19 = (char *)(numPrimitives + v18->renderModel->surfaces.num);
            goto LABEL_18;
          }
          v13->numPrimitives = numPrimitives + v18->staticModel->surfaces.num;
LABEL_19:
          ++v16;
          ++v17;
          if ( v16 >= collisionModelGeometry->models.num )
            goto LABEL_20;
        }
        idCollisionModelBuilder::ConvertMapModelPolytopes(
          model: v13,
          modelGeom: &collisionModelGeometry->models.list[v17],
          groupNum,
          primitiveNum: v13->numPrimitives);
        v19 = (char *)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)v18->mapModel)
            + v13->numPrimitives;
LABEL_18:
        v13->numPrimitives = (int)v19;
        goto LABEL_19;
      }
LABEL_20:
      if ( v13->numPolytopes > 1 )
        idCollisionModelBuilder::CreateAxialBSPTree(model: v13);
      idCollisionModelBuilder::ClearHash(bounds: v35);
      v13->numPrimitives = 0;
      v21 = 0;
      if ( collisionModelGeometry->models.num > 0 )
      {
        v22 = 0;
        while ( 1 )
        {
          v23 = v13->numPrimitives;
          v24 = &collisionModelGeometry->models.list[v22];
          if ( v24->mapModel != nullptr )
            break;
          idCollisionModelBuilder::ConvertRenderModelSurfaces(model: v13, modelGeom: v24, groupNum, primitiveNum: v23);
          v26 = v13->numPrimitives;
          if ( v24->staticModel == nullptr )
          {
            v25 = (char *)(v26 + v24->renderModel->surfaces.num);
            goto LABEL_29;
          }
          v13->numPrimitives = v26 + v24->staticModel->surfaces.num;
LABEL_30:
          ++v21;
          ++v22;
          if ( v21 >= collisionModelGeometry->models.num )
            goto LABEL_31;
        }
        idCollisionModelBuilder::ConvertMapModelPrimitives(model: v13, modelGeom: v24, groupNum, primitiveNum: v23);
        v25 = (char *)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)v24->mapModel)
            + v13->numPrimitives;
LABEL_29:
        v13->numPrimitives = (int)v25;
        goto LABEL_30;
      }
LABEL_31:
      idCollisionModelBuilder::CreateAxialBSPTree(model: v13);
      node = v13->node;
      ++v13->checkCount;
      idCollisionModelBuilder::MergeTreePolygons(model: v13, node, mergePrimitives: true);
      ++v13->checkCount;
      idCollisionModelBuilder::SplitPolygons(model: v13);
      v28 = v13->node;
      ++v13->checkCount;
      idCollisionModelBuilder::FindInternalEdges(model: v13, node: v28);
      v29 = v13->node;
      ++v13->checkCount;
      idCollisionModelBuilder::GenerateEdgeNormals_r(model: v13, node: v29);
      v30 = v13->node;
      ++v13->checkCount;
      idCollisionModelBuilder::OffsetPolygonEdges_r(model: v13, node: v30);
      idCollisionModelBuilder::CreateAxialBSPTree(model: v13);
      idCollisionModelBuilder::TestBoundsRange(modelName: model->name.str, bounds: v35);
      idCollisionModelBuilder::AddSubModelsToCollisionModel(model, buildModel: v13);
      idCollisionModelBuilder::FreeModelMemory(model: v13);
      v34[0] = (int)v13;
      if ( v13->materials.listStatic == 0 || v13->materials.listStatic == 2 )
      {
        list = v13->materials.list;
        if ( list != nullptr )
        {
          v33 = v13->materials.list;
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        }
        v13->materials.list = nullptr;
        v13->materials.size = 0;
      }
      v13->materials.num = 0;
      idStr::FreeData(this: &v13->name);
      idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$247993
// EA  : 0x825D0B38
// RVA : 0x005D0B38
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_247993()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 208 + 88));
}


// ========================================================================
// ?MergeModelTrees@idCollisionModelBuilder@@CAXPAVidCollisionModelLocal@@@Z
// EA  : 0x825D0DD8
// RVA : 0x005D0DD8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::MergeModelTrees(idCollisionModelLocal *model)
{
  int v1; // r29
  int num; // r7
  idVehicleState **v4; // r11
  idVehicleState **list; // r6
  idVehicleState **v6; // r4
  idList<idVehicleState *,5> v7[4]; // [sp+50h] [-40h] BYREF

  v1 = 0;
  memset(v7, 0, 14);
  v7[0].listStatic = 0;
  v7[0].memTag = 13;
  idList<idThread *,58>::Clear(this: v7);
  if ( model->polygonModel.numModelTreeNodes <= 0 )
  {
    num = v7[0].num;
    list = v7[0].list;
  }
  else
  {
    num = v7[0].num;
    do
    {
      idList<modelTree_t,13>::PreAllocateWithGranularity(this: (idList<modelTree_t,13> *)v7, newSize: num + 1);
      if ( v7[0].num >= v7[0].size )
        v4 = &v7[0].list[7 * v7[0].size - 7];
      else
        v4 = &v7[0].list[7 * v7[0].num++];
      *v4 = (idVehicleState *)v1;
      *((float *)v4 + 3) = 1900671690;
      *((float *)v4 + 2) = 1900671690;
      *((float *)v4 + 1) = 1900671690;
      *((float *)v4 + 6) = -1.0e30;
      *((float *)v4 + 5) = -1.0e30;
      *((float *)v4 + 4) = -1.0e30;
      v1 += idCollisionModelBuilder::CountModelTreeNodes_r(model, nodeNum: (int)*v4, bounds: (idBounds *)(v4 + 1)) + 1;
    }
    while ( v1 < model->polygonModel.numModelTreeNodes );
  }
  if ( num > 1 )
  {
    if ( (v7[0].listStatic == 0 || v7[0].listStatic == 2) && list != nullptr )
    {
      v6 = list;
      goto LABEL_18;
    }
  }
  else if ( (v7[0].listStatic == 0 || v7[0].listStatic == 2) && list != nullptr )
  {
    v6 = list;
LABEL_18:
    idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$248212
// EA  : 0x825D0F38
// RVA : 0x005D0F38
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_248212()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 144 + 80));
}


// ========================================================================
// ?BuildCollisionModelForGeometry@idCollisionModelBuilder@@CAXPAVidCollisionModelLocal@@AAVidCollisionModelGeometry@1@PBHHPBD@Z
// EA  : 0x825D0F60
// RVA : 0x005D0F60
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall idCollisionModelBuilder::BuildCollisionModelForGeometry(
        idCollisionModelLocal *model,
        idCollisionModelBuilder::idCollisionModelGeometry *collisionModelGeometry,
        const int *submodelIndices,
        int numSubmodelIndices,
        char *optionalModelName)
{
  char *data; // r4
  int v11; // r30
  int v12; // r3
  int v13; // r28
  char v14; // r11
  int *v15; // r28
  int i; // r30
  int v17; // r11

  if ( optionalModelName != nullptr )
  {
    idLib::Printf(fmt: "building %s...", optionalModelName);
    data = optionalModelName;
  }
  else
  {
    idLib::Printf(fmt: "building %s...", collisionModelGeometry->modelName.data);
    data = collisionModelGeometry->modelName.data;
  }
  idResource::SetName(this: model, _name: data);
  v11 = 0;
  model->modelType = CM_POLYGONMODEL;
  model->bounds.b[0].z = 1.0e30;
  model->bounds.b[0].y = 1.0e30;
  model->bounds.b[0].x = 1.0e30;
  model->bounds.b[1].z = -1.0e30;
  model->bounds.b[1].y = -1.0e30;
  model->bounds.b[1].x = -1.0e30;
  model->contents = 0;
  model->sourceFileTime = collisionModelGeometry->fileTime;
  model->isWorldModel = collisionModelGeometry->isWorldEntity;
  model->isTraceModel = false;
  model->isConvex = false;
  model->isStreamed = collisionModelGeometry->isStreamed;
  v12 = idCollisionModelBuilder::SetupBuildGroups(collisionModelGeometry);
  v13 = v12;
  if ( submodelIndices == nullptr || (v14 = 1, numSubmodelIndices <= 0) )
    v14 = 0;
  if ( v14 != 0 )
  {
    if ( numSubmodelIndices > 0 )
    {
      v15 = (int *)(submodelIndices - 1);
      for ( i = numSubmodelIndices; i != 0; --i )
        idCollisionModelBuilder::AddCollisionModelGeometry(model, collisionModelGeometry, groupNum: *++v15);
    }
  }
  else if ( v12 > 0 )
  {
    do
      idCollisionModelBuilder::AddCollisionModelGeometry(model, collisionModelGeometry, groupNum: v11++);
    while ( v11 < v13 );
  }
  idCollisionModelBuilder::MergeModelTrees(model);
  v17 = idCollisionModelLocal::GetTotalMemory(this: model) >> 10;
  if ( v17 == 0 )
    v17 = 1;
  idLib::Printf(fmt: " (%d kB)\n", v17);
}


// ========================================================================
// ?BuildForRenderModel@idCollisionModelBuilder@@SA_NPAVidCollisionModelLocal@@PBVidRenderModel@@@Z
// EA  : 0x825D11F8
// RVA : 0x005D11F8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::BuildForRenderModel(
        idCollisionModelLocal *model,
        const idRenderModel *renderModel)
{
  int num; // r4
  int v6; // [sp+50h] [-110h] BYREF
  idCollisionModelBuilder::idStaticModelGeometry v7; // [sp+60h] [-100h] BYREF
  idCollisionModelBuilder::idCollisionModelGeometry v8; // [sp+C0h] [-A0h] BYREF

  memset(&v7.primitiveGroupNumbers, 0, 14);
  v7.primitiveGroupNumbers.memTag = 13;
  v7.primitiveGroupNumbers.listStatic = 0;
  v7.renderModel = renderModel;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v7.primitiveGroupNumbers);
  if ( renderModel != nullptr )
  {
    v7.staticModel = nullptr;
    v7.mapModel = nullptr;
    v6 = 0;
    num = renderModel->surfaces.num;
    v7.origin.z = 0.0;
    v7.origin.y = 0.0;
    v7.origin.x = 0.0;
    v7.axis.mat[2].z = 1.0;
    v7.axis.mat[1].y = 1.0;
    v7.axis.mat[0].x = 1.0;
    v7.axis.mat[1].z = 0.0;
    v7.axis.mat[0].z = 0.0;
    v7.axis.mat[0].y = 0.0;
    v7.axis.mat[2].y = 0.0;
    v7.axis.mat[2].x = 0.0;
    v7.axis.mat[1].x = 0.0;
    v7.scale.x = 1.0;
    v7.scale.y = 1.0;
    v7.scale.z = 1.0;
    idList<idRenderModelCommitted *,5>::SetNum(
      this: (idList<int,5> *)&v7.primitiveGroupNumbers,
      newNum: num,
      initValue: &v6);
    v7.overrideClipMaterial = nullptr;
    v8.modelName.len = 0;
    v8.modelName.baseBuffer[0] = 0;
    v8.modelName.data = v8.modelName.baseBuffer;
    v8.modelName.allocedAndFlag = 20;
    v8.models.memTag = 13;
    v8.models.listStatic = 0;
    memset(&v8.models, 0, 14);
    idStr::operator=(this: &v8.modelName, text: renderModel->name.str);
    v8.isWorldEntity = false;
    v8.fileTime = -1;
    v8.isStreamed = false;
    v8.allowDiscrete = true;
    idList<idCollisionModelBuilder::idStaticModelGeometry,13>::Append(this: &v8.models, obj: &v7);
    idCollisionModelBuilder::SetupHash();
    idCollisionModelBuilder::BuildCollisionModelForGeometry(
      model,
      collisionModelGeometry: &v8,
      submodelIndices: nullptr,
      numSubmodelIndices: 0,
      optionalModelName: nullptr);
    idCollisionModelBuilder::ShutdownHash();
    idLib::Printf(fmt: "loaded collision model %s\n", model->name.str);
    idCollisionModelBuilder::idCollisionModelGeometry::~idCollisionModelGeometry(this: &v8);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v7.primitiveGroupNumbers);
    return 1;
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v7.primitiveGroupNumbers);
    return 0;
  }
}


// ========================================================================
// __unwind$248596
// EA  : 0x825D1378
// RVA : 0x005D1378
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_248596()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 352 + 96));
}


// ========================================================================
// __unwind$248754
// EA  : 0x825D13A0
// RVA : 0x005D13A0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_248754()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 196));
}


// ========================================================================
// __unwind$248597
// EA  : 0x825D13CC
// RVA : 0x005D13CC
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_248597()
{
  int v0; // r12

  idCollisionModelBuilder::idCollisionModelGeometry::~idCollisionModelGeometry(this: (idCollisionModelBuilder::idCollisionModelGeometry *)(v0 - 352 + 192));
}


// ========================================================================
// ?BuildForStaticModel@idCollisionModelBuilder@@SA_NPAVidCollisionModelLocal@@PBVidStaticModel@@PBHHPBD@Z
// EA  : 0x825D1540
// RVA : 0x005D1540
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::BuildForStaticModel(
        idCollisionModelLocal *model,
        const idStaticModel *staticModel,
        const int *submodelIndices,
        int numSubmodelIndices,
        char *optionalModelName)
{
  int num; // r4
  unsigned int sourceTimeStamp; // r11
  int v13; // [sp+50h] [-130h] BYREF
  idCollisionModelBuilder::idStaticModelGeometry v14; // [sp+60h] [-120h] BYREF
  idCollisionModelBuilder::idCollisionModelGeometry v15; // [sp+C0h] [-C0h] BYREF

  memset(&v14.primitiveGroupNumbers, 0, 14);
  v14.primitiveGroupNumbers.memTag = 13;
  v14.primitiveGroupNumbers.listStatic = 0;
  v14.staticModel = staticModel;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14.primitiveGroupNumbers);
  if ( staticModel != nullptr )
  {
    v14.mapModel = nullptr;
    v14.renderModel = nullptr;
    v13 = 0;
    num = staticModel->surfaces.num;
    v14.origin.z = 0.0;
    v14.origin.y = 0.0;
    v14.origin.x = 0.0;
    v14.axis.mat[2].z = 1.0;
    v14.axis.mat[1].y = 1.0;
    v14.axis.mat[0].x = 1.0;
    v14.axis.mat[1].z = 0.0;
    v14.axis.mat[0].z = 0.0;
    v14.axis.mat[0].y = 0.0;
    v14.axis.mat[2].y = 0.0;
    v14.axis.mat[2].x = 0.0;
    v14.axis.mat[1].x = 0.0;
    v14.scale.x = 1.0;
    v14.scale.y = 1.0;
    v14.scale.z = 1.0;
    idList<idRenderModelCommitted *,5>::SetNum(
      this: (idList<int,5> *)&v14.primitiveGroupNumbers,
      newNum: num,
      initValue: &v13);
    v14.overrideClipMaterial = nullptr;
    v15.modelName.len = 0;
    v15.modelName.baseBuffer[0] = 0;
    v15.modelName.data = v15.modelName.baseBuffer;
    v15.modelName.allocedAndFlag = 20;
    v15.models.memTag = 13;
    v15.models.listStatic = 0;
    memset(&v15.models, 0, 14);
    idStr::operator=(this: &v15.modelName, text: staticModel->name.str);
    sourceTimeStamp = staticModel->sourceTimeStamp;
    v15.isWorldEntity = false;
    v15.isStreamed = false;
    v15.allowDiscrete = true;
    v15.fileTime = sourceTimeStamp;
    idList<idCollisionModelBuilder::idStaticModelGeometry,13>::Append(this: &v15.models, obj: &v14);
    idCollisionModelBuilder::SetupHash();
    idCollisionModelBuilder::BuildCollisionModelForGeometry(
      model,
      collisionModelGeometry: &v15,
      submodelIndices,
      numSubmodelIndices,
      optionalModelName);
    idCollisionModelBuilder::ShutdownHash();
    idCollisionModelLocal::Write_Binary(this: model);
    idLib::Printf(fmt: "loaded collision model %s\n", model->name.str);
    idCollisionModelBuilder::idCollisionModelGeometry::~idCollisionModelGeometry(this: &v15);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14.primitiveGroupNumbers);
    return 1;
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14.primitiveGroupNumbers);
    return 0;
  }
}


// ========================================================================
// __unwind$248974
// EA  : 0x825D16D4
// RVA : 0x005D16D4
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_248974()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$249132
// EA  : 0x825D16FC
// RVA : 0x005D16FC
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249132()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 196));
}


// ========================================================================
// __unwind$248975
// EA  : 0x825D1728
// RVA : 0x005D1728
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_248975()
{
  int v0; // r12

  idCollisionModelBuilder::idCollisionModelGeometry::~idCollisionModelGeometry(this: (idCollisionModelBuilder::idCollisionModelGeometry *)(v0 - 384 + 192));
}


// ========================================================================
// ?BuildForMapFile@idCollisionModelBuilder@@SAXPBVidMapFile@@_N1@Z
// EA  : 0x825D1B58
// RVA : 0x005D1B58
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCollisionModelBuilder::BuildForMapFile(
        idDeclEntityDef *mapFile,
        bool inlineStatic,
        bool mapModelOnly)
{
  __int64 v5; // r10
  int v6; // r7
  __int64 v7; // r6
  idStr *MapModelName; // r28
  size_t len; // r29
  unsigned int textLength; // r7
  __int64 v11; // r11
  int v12; // r22
  __int64 v13; // r9
  _exception *v14; // r3
  idMapEntity *Entity; // r26
  char v16; // r25
  int v17; // r27
  int v18; // r28
  idDeclEntityDef *entityDef; // r29
  int v20; // r28
  const char *v21; // r3
  const idMaterial *v22; // r3
  const char *v23; // r28
  void *v24; // r3
  void *v25; // r3
  const char *TypeDef; // r3
  void *num; // r4
  const idStaticModel *v28; // r3
  const char *str; // r4
  unsigned int sourceTimeStamp; // r11
  int v31; // r27
  int v32; // r29
  char **p_data; // r28
  char *list; // r23
  int v35; // r24
  idMem *v36; // r25
  __int64 v37; // r10 OVERLAPPED
  __int64 v38; // r10
  __int64 v39; // r8
  va *v40; // r3
  idCollisionModelLocal *v41; // r3
  idCollisionModelLocal *v42; // r3
  double x; // fp0
  float *collisionModel; // r10
  double y; // fp12
  double z; // fp11
  double v47; // fp10
  double v48; // fp9
  int v49; // r28
  idCollisionModelBuilder::idCollisionModelGeometry *v50; // r29
  int v51; // r11
  _exception *v52; // r3
  idCollisionModelLocal *v53; // r3
  idCollisionModelLocal *v54; // r3
  idCollisionModelLocal *v55; // r3
  idCollisionModelLocal **v56; // r29
  int i; // r28
  __int64 v58; // [sp+8h] [-13B8h]
  int v59; // [sp+8h] [-13B8h]
  int v60; // [sp+Ch] [-13B4h]
  int v61; // [sp+10h] [-13B0h]
  int v62; // [sp+14h] [-13ACh]
  int v63; // [sp+18h] [-13A8h]
  int v64; // [sp+1Ch] [-13A4h]
  int v65; // [sp+50h] [-1370h] BYREF
  idMem *v66; // [sp+54h] [-136Ch]
  const char *v67; // [sp+58h] [-1368h]
  idCollisionModelLocal *v68; // [sp+5Ch] [-1364h]
  idList<idCollisionModelBuilder::idCollisionModelGeometry,13> v69; // [sp+60h] [-1360h] BYREF
  idCollisionModelBuilder::idStaticModelGeometry v70; // [sp+70h] [-1350h] BYREF
  __int64 v71; // [sp+D0h] [-12F0h]
  idTypeInfoTree v72; // [sp+E0h] [-12E0h] BYREF
  idBounds v73; // [sp+100h] [-12C0h] BYREF
  idStr v74; // [sp+120h] [-12A0h] BYREF
  idStr v75; // [sp+140h] [-1280h] BYREF
  const char *v76; // [sp+160h] [-1260h]
  bfx::BinaryReplayLogOut *v77; // [sp+164h] [-125Ch]
  idTypeInfoVariable_StrPtr *v78; // [sp+168h] [-1258h]
  const char *v79; // [sp+16Ch] [-1254h]
  const char *v80; // [sp+170h] [-1250h]
  idTypeInfoVariable_idVec3 *v81; // [sp+174h] [-124Ch]
  idDeclInfoTemplate<idMaterial> *v82; // [sp+178h] [-1248h]
  const char *v83; // [sp+17Ch] [-1244h]
  idCollisionModelBuilder::idCollisionModelGeometry v84; // [sp+180h] [-1240h] BYREF
  idCollisionModelBuilder::idCollisionModelGeometry v85; // [sp+1F0h] [-11D0h] BYREF
  idStr v86; // [sp+260h] [-1160h] BYREF
  __int64 v87; // [sp+280h] [-1140h]
  idStr v88; // [sp+290h] [-1130h] BYREF
  idStr v89; // [sp+2B0h] [-1110h] BYREF
  idStr v90; // [sp+2D0h] [-10F0h] BYREF
  idStr v91; // [sp+2F0h] [-10D0h] BYREF
  va v92; // [sp+310h] [-10B0h] BYREF

  if ( idPhysics_Static::GetNumContactPhysics(this: mapFile) != nullptr )
  {
    v84.modelName.len = 0;
    v84.modelName.baseBuffer[0] = 0;
    v84.modelName.data = v84.modelName.baseBuffer;
    v84.modelName.allocedAndFlag = 20;
    v84.models.memTag = 13;
    v84.models.listStatic = 0;
    memset(&v84.models, 0, 14);
    *(_WORD *)&v69.memTag = 3328;
    memset(&v69, 0, 14);
    idStr::idStr(this: &v90, text: mapFile->name.str);
    v68 = (idCollisionModelLocal *)inlineStatic;
    if ( inlineStatic )
      idStr::AppendPath(this: &v90, text: "_combo");
    v84.collisionModel = nullptr;
    HIDWORD(v7) = "world";
    MapModelName = idMapFile::GetMapModelName(result: &v91, entityName: v7, a3: v6, a4: v5, a5: v58);
    len = MapModelName->len;
    idStr::EnsureAlloced(this: &v84.modelName, amount: MapModelName->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v84.modelName.data, Src: MapModelName->data, Size: len);
    v84.modelName.data[len] = 0;
    v84.modelName.len = len;
    idStr::FreeData(this: &v91);
    textLength = mapFile->textLength;
    v84.isStreamed = false;
    v84.isStreamArea = false;
    v84.isWorldEntity = true;
    v84.allowDiscrete = false;
    v84.fileTime = textLength;
    v67 = nullptr;
    v73.b[0].z = 1.0e30;
    v73.b[0].y = 1.0e30;
    v73.b[0].x = 1.0e30;
    v73.b[1].z = -1.0e30;
    v73.b[1].y = v73.b[1].z;
    v73.b[1].x = v73.b[1].z;
    v66 = &mem;
    if ( (int)idPhysics_Static::GetNumContactPhysics(this: mapFile) > 0 )
    {
      v77 = (bfx::BinaryReplayLogOut *)"Populating model list";
      v79 = "clipModelInfo";
      v76 = "CLIPMODEL_CUSTOM";
      v80 = "idWorldClipBounds";
      v83 = "overrideClipMaterial '%s' not found";
      v82 = &idMaterial::resourceList;
      HIDWORD(v11) = "CLIPMODEL_RENDERMODEL";
      v78 = &TIV_idEntity_clipModelInfo_overrideClipMaterial;
      v12 = 0;
      v81 = &TIV_idEntity_renderModelInfo_scale;
      v67 = "CLIPMODEL_RENDERMODEL";
      while ( 1 )
      {
        LODWORD(v11) = v12;
        v87 = v11;
        LODWORD(v13) = idPhysics_Static::GetNumContactPhysics(this: mapFile) - 1;
        v71 = v13;
        idPhysics_StaticMulti::UpdateTime(this: v77);
        if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: v14) != 0 )
          break;
        Entity = idMapFile::GetEntity(this: (idMapFile *)mapFile, i: v12);
        v16 = 0;
        v17 = 0;
        if ( Entity->layerList.num > 0 )
        {
          v18 = 0;
          while ( idStr::Cmp(s1: Entity->layerList.list[v18].data, s2: "layer/exclude") != 0 )
          {
            ++v17;
            ++v18;
            if ( v17 >= Entity->layerList.num )
              goto LABEL_13;
          }
          v16 = 1;
        }
LABEL_13:
        if ( v16 != 0 )
          goto LABEL_76;
        entityDef = Entity->entityDef;
        v20 = entityDef->GetEntityStateLength(this: entityDef);
        v21 = entityDef->GetEntityState(this: entityDef);
        idTypeInfoTree::idTypeInfoTree(this: &v72, text: v21, length: v20);
        v70.primitiveGroupNumbers.memTag = 13;
        v70.primitiveGroupNumbers.listStatic = 0;
        v70.origin.z = 0.0;
        memset(&v70, 0, 26);
        v70.origin.y = 0.0;
        v70.origin.x = 0.0;
        v70.axis.mat[2].z = 1.0;
        v70.overrideClipMaterial = nullptr;
        v70.axis.mat[1].y = 1.0;
        v74.allocedAndFlag = 20;
        v70.axis.mat[0].x = 1.0;
        v74.data = v74.baseBuffer;
        v70.axis.mat[1].z = 0.0;
        v74.len = 0;
        v70.axis.mat[0].z = 0.0;
        v74.baseBuffer[0] = 0;
        v70.axis.mat[0].y = 0.0;
        v70.axis.mat[2].y = 0.0;
        v70.axis.mat[2].x = 0.0;
        v70.axis.mat[1].x = 0.0;
        v70.scale.x = 1.0;
        v70.scale.y = 1.0;
        v70.scale.z = 1.0;
        v75.allocedAndFlag = 20;
        v75.data = v75.baseBuffer;
        v75.len = 0;
        v75.baseBuffer[0] = 0;
        v86.allocedAndFlag = 20;
        v86.data = v86.baseBuffer;
        v86.len = 0;
        v86.baseBuffer[0] = 0;
        idTypeInfoTree::GetVec3(this: &v72, path: TIV_idEntity_spawnPosition.path, value: &v70.origin);
        idTypeInfoTree::GetMat3(this: &v72, path: TIV_idEntity_spawnOrientation.path, value: &v70.axis);
        idTypeInfoTree::GetStrType(this: &v72, path: TIV_idEntity_clipModelInfo_type.path, value: &v74);
        idTypeInfoTree::GetStrType(this: &v72, path: TIV_idEntity_clipModelInfo_clipModelName.path, value: &v75);
        if ( idStr::Cmp(s1: v74.data, s2: &byte_8200D768) == 0 && v75.len > 0 )
          idStr::operator=(this: &v74, text: v67);
        if ( idStr::Cmp(s1: v74.data, s2: v67) == 0
          && !idTypeInfoTree::GetVec3(this: &v72, path: v81->path, value: &v70.scale) )
        {
          v70.scale.x = 1.0;
          v70.scale.y = 1.0;
          v70.scale.z = 1.0;
        }
        idTypeInfoTree::GetStrType(this: &v72, path: v78->path, value: &v86);
        if ( v86.len != 0 )
        {
          v22 = v86.data != nullptr
              ? (const idMaterial *)idDeclInfo::FindWithInheritance(this: v82, name: v86.data, makeDefault: false)
              : nullptr;
          v70.overrideClipMaterial = v22;
          if ( v22 == nullptr )
            idLib::Warning(fmt: v83);
        }
        idStr::FreeData(this: &v86);
        v23 = Entity->entityDef->GetClass(this: Entity->entityDef);
        if ( idStr::Cmp(s1: v23, s2: "idWorldspawn") == 0 )
        {
          v65 = 0;
          v70.mapModel = &Entity->model;
          v24 = idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)&Entity->model);
          idList<idRenderModelCommitted *,5>::SetNum(
            this: (idList<int,5> *)&v70.primitiveGroupNumbers,
            newNum: (int)v24,
            initValue: &v65);
          idList<idCollisionModelBuilder::idStaticModelGeometry,13>::Append(this: &v84.models, obj: &v70);
          idStr::FreeData(this: &v75);
          idStr::FreeData(this: &v74);
          if ( v70.primitiveGroupNumbers.listStatic == 0 || v70.primitiveGroupNumbers.listStatic == 2 )
          {
            if ( v70.primitiveGroupNumbers.list != nullptr )
              idMem::Free(this: v66, ptr: v70.primitiveGroupNumbers.list, align: ALIGN_16);
            v70.primitiveGroupNumbers.list = nullptr;
            v70.primitiveGroupNumbers.size = 0;
          }
LABEL_75:
          v70.primitiveGroupNumbers.num = 0;
          idTypeInfoTree::Clear(this: &v72);
          idBlockAlloc<idTypeInfoNode,32,114>::Shutdown(this: &v72.nodeBlockAlloc);
          goto LABEL_76;
        }
        if ( idStr::Cmp(s1: v23, s2: v80) == 0 )
        {
          v65 = 0;
          v70.mapModel = &Entity->model;
          v25 = idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)&Entity->model);
          idList<idRenderModelCommitted *,5>::SetNum(
            this: (idList<int,5> *)&v70.primitiveGroupNumbers,
            newNum: (int)v25,
            initValue: &v65);
          idCollisionModelBuilder::GetMapModelBrushBounds(modelGeom: &v70, groupNum: 0, bounds: &v73);
          idStr::FreeData(this: &v75);
          idStr::FreeData(this: &v74);
          if ( v70.primitiveGroupNumbers.listStatic == 0 || v70.primitiveGroupNumbers.listStatic == 2 )
          {
            if ( v70.primitiveGroupNumbers.list != nullptr )
              idMem::Free(this: v66, ptr: v70.primitiveGroupNumbers.list, align: ALIGN_16);
            v70.primitiveGroupNumbers.list = nullptr;
            v70.primitiveGroupNumbers.size = 0;
          }
          goto LABEL_75;
        }
        if ( idStr::Cmp(s1: v74.data, s2: v76) != 0 && idStr::Cmp(s1: v74.data, s2: v67) != 0 )
        {
LABEL_42:
          idStr::FreeData(this: &v75);
          idStr::FreeData(this: &v74);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v70.primitiveGroupNumbers);
          idTypeInfoTree::~idTypeInfoTree(this: &v72);
          goto LABEL_76;
        }
        if ( idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)&Entity->model) != nullptr )
        {
          TypeDef = (const char *)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)&Entity->model);
          if ( idStr::Icmp(s1: v75.data, s2: TypeDef) != 0 )
          {
            idLib::Error(
              fmt: "entity '%s' has a map model but clipModelInfo.clipModelName is not set to the map model name (if clipModel"
              "Info.type is set to CLIPMODEL_RENDERMODEL then saving the map from the editor will fix the problem)",
              Entity->entityDef->name.str);
_LN766:
            idLib::Error(
              fmt: "couldn't find collision model '%s' for entity '%s'",
              v75.data,
              Entity->entityDef->name.str);
            break;
          }
          v70.mapModel = &Entity->model;
          v65 = 0;
          num = idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)&Entity->model);
        }
        else
        {
          if ( (unsigned __int8)idCollisionModelBuilder::IsStaticRenderModel(fileName: v75.data) == 0 )
            goto LABEL_50;
          v28 = staticModelManager->FindStaticModel(this: staticModelManager, a2: v75.data, a3: false);
          v70.staticModel = v28;
          if ( v28 == nullptr )
            goto _LN766;
          num = (void *)v28->surfaces.num;
          v65 = 0;
        }
        idList<idRenderModelCommitted *,5>::SetNum(
          this: (idList<int,5> *)&v70.primitiveGroupNumbers,
          newNum: (int)num,
          initValue: &v65);
LABEL_50:
        if ( v70.staticModel == nullptr && v70.mapModel == nullptr )
          goto LABEL_42;
        if ( !idTypeInfoTree::IsSkipped(this: &v72, path: v79) || v68 == nullptr )
        {
          idCollisionModelBuilder::idCollisionModelGeometry::idCollisionModelGeometry(this: &v85);
          v85.collisionModel = nullptr;
          if ( v70.mapModel != nullptr )
            str = (const char *)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v70.mapModel);
          else
            str = v70.staticModel->name.str;
          idStr::operator=(this: &v85.modelName, text: str);
          if ( v70.mapModel != nullptr )
            sourceTimeStamp = mapFile->textLength;
          else
            sourceTimeStamp = v70.staticModel->sourceTimeStamp;
          v85.streamVolumeOrigin.z = 0.0;
          v85.streamVolumeOrigin.y = 0.0;
          v85.fileTime = sourceTimeStamp;
          v85.streamVolumeOrigin.x = 0.0;
          v85.isWorldEntity = false;
          v85.streamVolumeAxis.mat[2].z = 1.0;
          v85.isStreamed = false;
          v85.streamVolumeAxis.mat[1].y = 1.0;
          v85.isStreamArea = false;
          v85.streamVolumeAxis.mat[0].x = 1.0;
          v85.allowDiscrete = true;
          v85.streamVolumeAxis.mat[1].z = 0.0;
          v85.streamVolumeAxis.mat[0].z = 0.0;
          v85.streamVolumeAxis.mat[0].y = 0.0;
          v85.streamVolumeAxis.mat[2].y = 0.0;
          v85.streamVolumeAxis.mat[2].x = 0.0;
          v85.streamVolumeAxis.mat[1].x = 0.0;
          if ( idStr::Cmp(s1: v23, s2: "idCollisionStreamArea") == 0 )
          {
            v84.isStreamed = true;
            v85.isStreamArea = true;
            v85.streamVolumeOrigin.x = v70.origin.x;
            v85.streamVolumeOrigin.y = v70.origin.y;
            v85.streamVolumeOrigin.z = v70.origin.z;
            v85.streamVolumeAxis.mat[0].x = v70.axis.mat[0].x;
            v85.streamVolumeAxis.mat[0].y = v70.axis.mat[0].y;
            v85.streamVolumeAxis.mat[0].z = v70.axis.mat[0].z;
            v85.streamVolumeAxis.mat[1].x = v70.axis.mat[1].x;
            v85.streamVolumeAxis.mat[1].y = v70.axis.mat[1].y;
            v85.streamVolumeAxis.mat[1].z = v70.axis.mat[1].z;
            v85.streamVolumeAxis.mat[2].x = v70.axis.mat[2].x;
            v85.streamVolumeAxis.mat[2].y = v70.axis.mat[2].y;
            v85.streamVolumeAxis.mat[2].z = v70.axis.mat[2].z;
          }
          v70.origin.z = 0.0;
          v70.overrideClipMaterial = nullptr;
          v70.origin.y = 0.0;
          v70.origin.x = 0.0;
          v70.axis.mat[2].z = 1.0;
          v70.axis.mat[1].y = 1.0;
          v70.axis.mat[0].x = 1.0;
          v70.axis.mat[1].z = 0.0;
          v70.axis.mat[0].z = 0.0;
          v70.axis.mat[0].y = 0.0;
          v70.axis.mat[2].y = 0.0;
          v70.axis.mat[2].x = 0.0;
          v70.axis.mat[1].x = 0.0;
          v70.scale.x = 1.0;
          v70.scale.y = 1.0;
          v70.scale.z = 1.0;
          idList<idCollisionModelBuilder::idStaticModelGeometry,13>::Append(this: &v85.models, obj: &v70);
          v31 = v69.num;
          v32 = 0;
          if ( v69.num <= 0 )
            goto LABEL_69;
          p_data = &v69.list->modelName.data;
          while ( idStr::Cmp(s1: v85.modelName.data, s2: *p_data) != 0 )
          {
            ++v32;
            p_data += 27;
            if ( v32 >= v31 )
              goto LABEL_69;
          }
          if ( v32 >= v31 )
LABEL_69:
            idList<idCollisionModelBuilder::idCollisionModelGeometry,13>::Append(this: &v69, obj: &v85);
          idCollisionModelBuilder::idCollisionModelGeometry::~idCollisionModelGeometry(this: &v85);
          idStr::FreeData(this: &v75);
          idStr::FreeData(this: &v74);
          if ( v70.primitiveGroupNumbers.listStatic == 0 || v70.primitiveGroupNumbers.listStatic == 2 )
          {
            if ( v70.primitiveGroupNumbers.list != nullptr )
              idMem::Free(this: v66, ptr: v70.primitiveGroupNumbers.list, align: ALIGN_16);
            v70.primitiveGroupNumbers.list = nullptr;
            v70.primitiveGroupNumbers.size = 0;
          }
          goto LABEL_75;
        }
        idList<idCollisionModelBuilder::idStaticModelGeometry,13>::Append(this: &v84.models, obj: &v70);
        idStr::FreeData(this: &v75);
        idStr::FreeData(this: &v74);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v70.primitiveGroupNumbers);
        idTypeInfoTree::~idTypeInfoTree(this: &v72);
LABEL_76:
        if ( ++v12 >= (int)idPhysics_Static::GetNumContactPhysics(this: mapFile) )
        {
          list = (char *)v69.list;
          v35 = v69.num;
          v36 = v66;
          goto LABEL_81;
        }
      }
    }
    list = (char *)v69.list;
    v35 = v69.num;
    v36 = v66;
LABEL_81:
    idCollisionModelBuilder::SetupHash();
    HIDWORD(v37) = mapModelOnly;
    if ( !mapModelOnly )
    {
      v88.allocedAndFlag = 20;
      v88.len = 0;
      v88.data = v88.baseBuffer;
      v88.baseBuffer[0] = 0;
      idStr::idStr(this: &v89, text: mapFile->name.str);
      idStr::StripFileExtension(this: &v89);
      idStr::ExtractFileBase(this: &v89, dest: &v88);
      LODWORD(v38) = &unk_821B0000;
      v40 = va::va(
              this: &v92,
              fmt: "%s/%s",
              a3: __SPAIR64__((unsigned int)v89.data, (unsigned int)v88.data),
              a4: v39,
              a5: v38,
              a6: v59,
              a7: v60,
              a8: v61,
              a9: v62,
              a10: v63,
              a11: v64);
      idStr::operator=(this: &v89, text: v40);
      idCollisionModelBuilder::LoadProcBSP(name: v89.data);
      v41 = (idCollisionModelLocal *)idMem::AllocWithLocation(
                                       this: v36,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                       size: 0x74u,
                                       tag: TAG_NEW,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
      v68 = v41;
      if ( v41 != nullptr )
        v42 = idCollisionModelLocal::idCollisionModelLocal(this: v41);
      else
        v42 = nullptr;
      v84.collisionModel = v42;
      idCollisionModelBuilder::BuildCollisionModelForGeometry(
        model: v42,
        collisionModelGeometry: &v84,
        submodelIndices: nullptr,
        numSubmodelIndices: 0,
        optionalModelName: nullptr);
      x = v73.b[1].x;
      if ( v73.b[0].x <= (double)v73.b[1].x )
      {
        collisionModel = (float *)v84.collisionModel;
        y = v73.b[0].y;
        z = v73.b[0].z;
        v47 = v73.b[1].y;
        v48 = v73.b[1].z;
        v84.collisionModel->bounds.b[0].x = v73.b[0].x;
        collisionModel[13] = y;
        v68 = (idCollisionModelLocal *)(collisionModel + 15);
        collisionModel[14] = z;
        collisionModel[15] = x;
        collisionModel[16] = v47;
        collisionModel[17] = v48;
      }
      idMem::Free(this: v36, ptr: buildData.procNodes, align: ALIGN_16);
      buildData.procNodes = nullptr;
      idStr::FreeData(this: &v89);
      idStr::FreeData(this: &v88);
    }
    v49 = 0;
    if ( v35 > 0 )
    {
      v50 = (idCollisionModelBuilder::idCollisionModelGeometry *)list;
      LODWORD(v37) = v35 - 1;
      v71 = v37;
      do
      {
        v51 = v49;
        v71 = *(__int64 *)((char *)&v37 - 4);
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)"entity collision models");
        if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: v52) != 0 )
          break;
        v53 = (idCollisionModelLocal *)idMem::AllocWithLocation(
                                         this: v36,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                         size: 0x74u,
                                         tag: TAG_NEW,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
        v68 = v53;
        v54 = v53 != nullptr ? idCollisionModelLocal::idCollisionModelLocal(this: v53) : nullptr;
        v50->collisionModel = v54;
        idCollisionModelBuilder::BuildCollisionModelForGeometry(
          model: v54,
          collisionModelGeometry: v50,
          submodelIndices: nullptr,
          numSubmodelIndices: 0,
          optionalModelName: nullptr);
        ++v49;
        ++v50;
      }
      while ( v49 < v35 );
    }
    idCollisionModelBuilder::ShutdownHash();
    v55 = v84.collisionModel;
    if ( v84.collisionModel != nullptr && v84.isStreamed )
    {
      idCollisionModelBuilder::CreateStreamAreas(
        model: v84.collisionModel,
        entityCollisionGeometry: (const idList<idCollisionModelBuilder::idCollisionModelGeometry,5> *)&v69);
      v55 = v84.collisionModel;
    }
    if ( v35 > 0 )
    {
      v56 = (idCollisionModelLocal **)list;
      for ( i = v35; i != 0; --i )
      {
        if ( *v56 != nullptr )
        {
          idCollisionModelLocal::Write_Binary(this: *v56);
          if ( *v56 != nullptr )
            ((void (__fastcall *)(idCollisionModelLocal *, int))(*v56)->dtr_idResource)(a1: *v56, a2: 1);
        }
        v56 += 27;
      }
      v55 = v84.collisionModel;
    }
    if ( v55 != nullptr )
    {
      idCollisionModelLocal::Write_Binary(this: v55);
      if ( v84.collisionModel != nullptr )
        ((void (__fastcall *)(idCollisionModelLocal *, int))v84.collisionModel->dtr_idResource)(
          a1: v84.collisionModel,
          a2: 1);
    }
    idStr::FreeData(this: &v90);
    if ( (v69.listStatic == 0 || v69.listStatic == 2) && list != nullptr )
      idListArrayDelete<idCollisionModelBuilder::idCollisionModelGeometry>(ptr: list, num: v69.size);
    if ( v84.models.listStatic == 0 || v84.models.listStatic == 2 )
    {
      if ( v84.models.list != nullptr )
        idListArrayDelete<idCollisionModelBuilder::idStaticModelGeometry>(
          ptr: (char *)v84.models.list,
          num: v84.models.size);
      v84.models.list = nullptr;
      v84.models.size = 0;
    }
    v84.models.num = 0;
    idStr::FreeData(this: &v84.modelName);
  }
}


// ========================================================================
// $LN668
// EA  : 0x825D28A4
// RVA : 0x005D28A4
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _LN668()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5056 + 388));
}


// ========================================================================
// __unwind$249410
// EA  : 0x825D28D0
// RVA : 0x005D28D0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249410()
{
  int v0; // r12

  idCollisionModelBuilder::idCollisionModelGeometry::~idCollisionModelGeometry(this: (idCollisionModelBuilder::idCollisionModelGeometry *)(v0 - 5056 + 384));
}


// ========================================================================
// __unwind$249411
// EA  : 0x825D28F8
// RVA : 0x005D28F8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249411()
{
  int v0; // r12

  idList<idCollisionModelBuilder::idCollisionModelGeometry,13>::Clear(this: (idList<idCollisionModelBuilder::idCollisionModelGeometry,13> *)(v0 - 5056 + 96));
}


// ========================================================================
// __unwind$249412
// EA  : 0x825D2920
// RVA : 0x005D2920
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249412()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5056 + 720));
}


// ========================================================================
// __unwind$249413
// EA  : 0x825D2948
// RVA : 0x005D2948
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249413()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5056 + 752));
}


// ========================================================================
// __unwind$249414
// EA  : 0x825D2970
// RVA : 0x005D2970
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249414()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 5056 + 224));
}


// ========================================================================
// __unwind$249415
// EA  : 0x825D2998
// RVA : 0x005D2998
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249415()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 5056 + 112));
}


// ========================================================================
// __unwind$249416
// EA  : 0x825D29C0
// RVA : 0x005D29C0
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249416()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5056 + 288));
}


// ========================================================================
// __unwind$249417
// EA  : 0x825D29E8
// RVA : 0x005D29E8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249417()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5056 + 320));
}


// ========================================================================
// __unwind$249418
// EA  : 0x825D2A10
// RVA : 0x005D2A10
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249418()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5056 + 608));
}


// ========================================================================
// __unwind$250017
// EA  : 0x825D2A38
// RVA : 0x005D2A38
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_250017()
{
  int v0; // r12

  idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(this: (idBlockAlloc<idTypeInfoNode,32,114> *)(v0 - 5056 + 228));
}


// ========================================================================
// __unwind$250091
// EA  : 0x825D2A64
// RVA : 0x005D2A64
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_250091()
{
  int v0; // r12

  idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(this: (idBlockAlloc<idTypeInfoNode,32,114> *)(v0 - 5056 + 228));
}


// ========================================================================
// __unwind$249419
// EA  : 0x825D2A90
// RVA : 0x005D2A90
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249419()
{
  int v0; // r12

  idCollisionModelBuilder::idCollisionModelGeometry::~idCollisionModelGeometry(this: (idCollisionModelBuilder::idCollisionModelGeometry *)(v0 - 5056 + 496));
}


// ========================================================================
// __unwind$250573
// EA  : 0x825D2AB8
// RVA : 0x005D2AB8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_250573()
{
  int v0; // r12

  idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(this: (idBlockAlloc<idTypeInfoNode,32,114> *)(v0 - 5056 + 228));
}


// ========================================================================
// __unwind$249420
// EA  : 0x825D2AE4
// RVA : 0x005D2AE4
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249420()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5056 + 656));
}


// ========================================================================
// __unwind$249421
// EA  : 0x825D2B0C
// RVA : 0x005D2B0C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_249421()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5056 + 688));
}


// ========================================================================
// __unwind$249422
// EA  : 0x825D2B34
// RVA : 0x005D2B34
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall _unwind_249422(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 5056 + 92), tag: a2);
}


// ========================================================================
// __unwind$249423
// EA  : 0x825D2B5C
// RVA : 0x005D2B5C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void __fastcall _unwind_249423(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 5056 + 92), tag: a2);
}


// ========================================================================
// __unwind$250750
// EA  : 0x825D2B84
// RVA : 0x005D2B84
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _unwind_250750()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5056 + 388));
}


// ========================================================================
// `dynamic initializer for 'mtrTraceModel''_0
// EA  : 0x833352A8
// RVA : 0x013352A8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _dynamic_initializer_for__mtrTraceModel___0()
{
  mtrTraceModel_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &mtrTraceModel_0;
}


// ========================================================================
// `dynamic initializer for 'mtrGridModel''
// EA  : 0x833352C8
// RVA : 0x013352C8
// PDB : w:\tech5\engine\cm\collisionmodelbuilder.cpp
// ========================================================================

void _dynamic_initializer_for__mtrGridModel__()
{
  mtrGridModel.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &mtrGridModel;
}

