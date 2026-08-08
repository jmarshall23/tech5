
// ========================================================================
// ?PointAreaNum@idSoundBSPFile@@QBAHABVidVec3@@@Z
// EA  : 0x82989EC8
// RVA : 0x00989EC8
// PDB : w:\tech5\engine\sound\soundbspfile.cpp
// ========================================================================

int __fastcall idSoundBSPFile::PointAreaNum(idSoundBSPFile *this, const idVec3 *point)
{
  int v2; // r11
  sbspNode_t *v3; // r10
  idPlane *v4; // r11
  double v5; // fp0

  if ( this->nodes.num == 1 )
    return 0;
  v2 = 1;
  while ( 1 )
  {
    v3 = &this->nodes.list[v2];
    v4 = &this->planes.list[v3->planeNum];
    v5 = (float)((float)((float)(v4->a * point->x) + (float)((float)(v4->b * point->y) + (float)(v4->c * point->z)))
               + v4->d);
    if ( v5 > 0.0 || v5 >= -0.0 )
      LOWORD(v2) = v3->children[0];
    else
      LOWORD(v2) = v3->children[1];
    v2 = (__int16)v2;
    if ( (v2 & 0x8000u) != 0 )
      break;
    if ( (_WORD)v2 == 0 )
      return 0;
  }
  return -(__int16)v2;
}


// ========================================================================
// ?Clear@idSoundBSPFile@@QAAXXZ
// EA  : 0x8298A240
// RVA : 0x0098A240
// PDB : w:\tech5\engine\sound\soundbspfile.cpp
// ========================================================================

void __fastcall idSoundBSPFile::Clear(idSoundBSPFile *this)
{
  idList<idVec3,39> *p_vertices; // r31
  int size; // r11
  _DWORD *p_x; // r11
  int v5; // r11
  __int16 *v6; // r11
  int i; // ctr
  idList<sbspArea_t,39> *p_areas; // r31
  int v9; // r11
  sbspArea_t *list; // r11
  idList<idSkinMapping,46> *p_nodes; // r30
  int v12; // r11
  idSkinMapping *v13; // r11

  p_vertices = &this->vertices;
  if ( this->vertices.size >= 1
    || (unsigned __int8)idList<idVec3,59>::Resize(this: (idList<idVec3,5> *)&this->vertices, newsize: 1) != 0 )
  {
    size = p_vertices->size;
    if ( size > 1 )
      size = 1;
    p_vertices->num = size;
  }
  p_x = (_DWORD *)&p_vertices->list->x;
  *p_x = 0;
  p_x[1] = 0;
  p_x[2] = 0;
  if ( this->faces.size >= 1
    || (unsigned __int8)idList<animMapOffsets_t,5>::Resize(this: (idList<cm_polygon_t,5> *)&this->faces, newsize: 1) != 0 )
  {
    v5 = this->faces.size;
    if ( v5 > 1 )
      v5 = 1;
    this->faces.num = v5;
  }
  v6 = &this->faces.list[-1].faceAreas[1];
  for ( i = 8; i != 0; --i )
    *++v6 = 0;
  p_areas = &this->areas;
  if ( this->areas.size >= 1
    || (unsigned __int8)idList<detailPaletteEntry_t,5>::Resize(
                          this: (idList<detailPaletteEntry_t,5> *)&this->areas,
                          newsize: 1) != 0 )
  {
    v9 = this->areas.size;
    if ( v9 > 1 )
      v9 = 1;
    this->areas.num = v9;
  }
  list = p_areas->list;
  p_nodes = (idList<idSkinMapping,46> *)&this->nodes;
  list->numFaces = 0;
  list->firstFace = 0;
  list->environment = 0;
  list->door = 0;
  p_areas->list->door = -1;
  if ( p_nodes->size >= 1 || (unsigned __int8)idList<idDeclMD6::includeDecl_t,5>::Resize(this: p_nodes, newsize: 1) != 0 )
  {
    v12 = p_nodes->size;
    if ( v12 > 1 )
      v12 = 1;
    p_nodes->num = v12;
  }
  v13 = p_nodes->list;
  v13->from = nullptr;
  v13->to = nullptr;
}


// ========================================================================
// ?Read@idSoundBSPFile@@QAA_NPBD@Z
// EA  : 0x8298A3B0
// RVA : 0x0098A3B0
// PDB : w:\tech5\engine\sound\soundbspfile.cpp
// ========================================================================

int __fastcall idSoundBSPFile::Read(idSoundBSPFile *this, char *filename)
{
  idResource *v4; // r3
  idFileResource *v5; // r19
  idFile_Memory *File; // r3
  idFile_Memory *v7; // r30
  idList<sbspFace_t,39> *p_faces; // r27
  int v9; // r26
  int v10; // r28
  idList<sbspArea_t,39> *p_areas; // r26
  int v12; // r25
  int v13; // r28
  idList<sbspNode_t,39> *p_nodes; // r24
  int v15; // r25
  int v16; // r28
  sbspFace_t *list; // r5
  sbspArea_t *v18; // r3
  int num; // r9
  idVec3 *v20; // r7
  int *v21; // r6
  int *v22; // r4
  sbspNode_t *v23; // r11
  int v24; // r10
  int v25; // r28
  int v26; // r27
  int v27; // r26
  int v28; // r25
  int v30; // [sp+50h] [-A0h] BYREF
  _DWORD v31[3]; // [sp+54h] [-9Ch] BYREF
  idStr v32[4]; // [sp+60h] [-90h] BYREF

  v4 = idResourceList::Load(
         this: &idFileResource::resourceList,
         name: filename,
         makeDefault: true,
         skipStaleCheck: false);
  v5 = (idFileResource *)v4;
  if ( v4 == nullptr || v4[1].trackedMemory <= 0 )
  {
    idStr::idStr(this: v32, text: filename);
    idStr::StripFileExtension(this: v32);
    idStr::Append(this: v32, text: "/soundworld.sbsp");
    v5 = (idFileResource *)idResourceList::Load(
                             this: &idFileResource::resourceList,
                             name: v32[0].data,
                             makeDefault: true,
                             skipStaleCheck: false);
    idStr::FreeData(this: v32);
  }
  if ( v5 == nullptr )
    return 0;
  if ( (int)v5->length <= 0 )
    return 0;
  File = idFileResource::GetFile(this: v5);
  v7 = File;
  if ( File == nullptr )
    return 0;
  if ( (int)File->Length(this: File) <= 0 )
    return 0;
  v7->Read(this: v7, a2: v31, a3: 4u);
  if ( v31[0] != 1397638153 )
    return 0;
  v7->Read(this: v7, a2: &v30, a3: 4u);
  idList<parmValue_t,56>::SetNum((idList<idPlane,37> *)this, newNum: v30);
  v7->Read(this: v7, a2: this->planes.list, a3: 16 * this->planes.num);
  v7->Read(this: v7, a2: &v30, a3: 4u);
  idList<idVec3,37>::SetNum(this: (idList<idVec3,5> *)&this->vertices, newNum: v30);
  v7->Read(this: v7, a2: this->vertices.list, a3: 12 * this->vertices.num);
  v7->Read(this: v7, a2: &v30, a3: 4u);
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->vertIndex, newNum: v30);
  v7->Read(this: v7, a2: this->vertIndex.list, a3: 4 * this->vertIndex.num);
  v7->Read(this: v7, a2: &v30, a3: 4u);
  p_faces = &this->faces;
  idList<sbspFace_t,39>::SetNum(this: &this->faces, newNum: v30);
  v9 = 0;
  if ( this->faces.num > 0 )
  {
    v10 = 0;
    do
    {
      v7->Read(this: v7, a2: &p_faces->list[v10].planeNum, a3: 2u);
      v7->Read(this: v7, a2: &p_faces->list[v10].numVerts, a3: 2u);
      v7->Read(this: v7, a2: &p_faces->list[v10].firstVert, a3: 2u);
      v7->Read(this: v7, a2: p_faces->list[v10].faceAreas, a3: 4u);
      v7->Read(this: v7, a2: &p_faces->list[v10], a3: 6u);
      ++v9;
      ++v10;
    }
    while ( v9 < this->faces.num );
  }
  v7->Read(this: v7, a2: &v30, a3: 4u);
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->faceIndex, newNum: v30);
  v7->Read(this: v7, a2: this->faceIndex.list, a3: 4 * this->faceIndex.num);
  v7->Read(this: v7, a2: &v30, a3: 4u);
  p_areas = &this->areas;
  idList<sbspArea_t,39>::SetNum(this: (idList<expOp_t,56> *)&this->areas, newNum: v30);
  v12 = 0;
  if ( this->areas.num > 0 )
  {
    v13 = 0;
    do
    {
      v7->Read(this: v7, a2: &p_areas->list[v13], a3: 2u);
      v7->Read(this: v7, a2: &p_areas->list[v13].firstFace, a3: 2u);
      v7->Read(this: v7, a2: &p_areas->list[v13].environment, a3: 2u);
      v7->Read(this: v7, a2: &p_areas->list[v13].door, a3: 2u);
      ++v12;
      ++v13;
    }
    while ( v12 < this->areas.num );
  }
  v7->Read(this: v7, a2: &v30, a3: 4u);
  p_nodes = &this->nodes;
  idList<idSWFSpriteInstance::swfAction_t,72>::SetNum(
    this: (idList<idSWFSpriteInstance::swfAction_t,72> *)&this->nodes,
    newNum: v30);
  v15 = 0;
  if ( this->nodes.num > 0 )
  {
    v16 = 0;
    do
    {
      v7->Read(this: v7, a2: &p_nodes->list[v16], a3: 4u);
      v7->Read(this: v7, a2: p_nodes->list[v16].children, a3: 4u);
      ++v15;
      ++v16;
    }
    while ( v15 < this->nodes.num );
  }
  v7->Read(this: v7, a2: &this->numEnvironments, a3: 4u);
  v7->Read(this: v7, a2: &this->numDoors, a3: 4u);
  v7->Read(this: v7, a2: v31, a3: 4u);
  if ( v31[0] != 1397638153 )
    return 0;
  ((void (__fastcall *)(idFile_Memory *, int))v7->dtr_idFile)(a1: v7, a2: 1);
  list = p_faces->list;
  v18 = p_areas->list;
  num = this->areas.num;
  v20 = this->vertices.list;
  v21 = this->vertIndex.list;
  v22 = this->faceIndex.list;
  v23 = p_nodes->list;
  v24 = this->planes.num;
  this->flatBSP.planes = this->planes.list;
  this->flatBSP.vertices = v20;
  this->flatBSP.vertIndex = v21;
  this->flatBSP.faces = list;
  this->flatBSP.faceIndex = v22;
  this->flatBSP.areas = v18;
  this->flatBSP.nodes = v23;
  this->flatBSP.numPlanes = v24;
  this->flatBSP.numAreas = num;
  v25 = this->vertIndex.num;
  v26 = this->faces.num;
  v27 = this->faceIndex.num;
  v28 = this->nodes.num;
  this->flatBSP.numVertices = this->vertices.num;
  this->flatBSP.numVertIndex = v25;
  this->flatBSP.numFaces = v26;
  this->flatBSP.numFaceIndex = v27;
  this->flatBSP.numNodes = v28;
  if ( num > 4096 )
    idLib::Error(fmt: "RouteToGoal: areas > MAX_SBSP_AREAS! Please increase it.");
  ((void (__fastcall *)(idFileResource *, int))v5->dtr_idResource)(a1: v5, a2: 1);
  return 1;
}


// ========================================================================
// $LN226_1
// EA  : 0x8298A984
// RVA : 0x0098A984
// PDB : w:\tech5\engine\sound\soundbspfile.cpp
// ========================================================================

void _LN226_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}

