
// ========================================================================
// ?CandelaAtAngle@idIESfile@@QAAMMM@Z
// EA  : 0x828C0C70
// RVA : 0x008C0C70
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

float __fastcall idIESfile::CandelaAtAngle(idIESfile *this, double horizAngle, double vertAngle)
{
  double v3; // fp0
  double v4; // fp1
  bool v5; // zf
  float *list; // r10
  double v7; // fp12
  int numHorizontalAngles; // r31
  double v9; // fp9
  int v10; // r4
  int v11; // r11
  float *v12; // r9
  double v13; // fp0
  int numVerticalAngles; // r11
  double v15; // fp13
  int v16; // r8
  int v17; // r10
  int v18; // r9
  int v19; // r10
  int v20; // r6
  float *v21; // r10
  int v22; // r6
  int v23; // r7
  int v24; // r6
  double v25; // fp10
  int v26; // r9
  int v27; // r7
  int v28; // r9
  double v29; // fp11
  int v30; // r7
  int v31; // r9
  int v32; // r7
  double v33; // fp12

  v3 = horizAngle;
  v5 = horizAngle >= 0.0;
  v4 = 0.0;
  if ( !v5 )
    v3 = (float)((float)v3 + (float)360.0);
  list = this->horizontalAngles.list;
  v7 = *list;
  if ( v7 != 0.0 || list[this->numHorizontalAngles - 1] != 0.0 )
  {
    if ( v7 == 0.0 && list[this->numHorizontalAngles - 1] == 90.0 )
    {
      if ( v3 <= 90.0 || v3 >= 180.0 )
      {
        if ( v3 >= 180.0 && v3 < 270.0 )
          v3 = (float)((float)540.0 - (float)v3);
      }
      else
      {
        v3 = (float)((float)180.0 - (float)v3);
      }
      if ( v3 >= 270.0 )
        v3 = (float)((float)360.0 - (float)v3);
    }
    else if ( v7 == 0.0 && list[this->numHorizontalAngles - 1] == 180.0 )
    {
      if ( v3 >= 180.0 )
        v3 = (float)((float)360.0 - (float)v3);
    }
    else if ( v7 != 0.0 || list[this->numHorizontalAngles - 1] != 360.0 )
    {
      if ( v7 == 90.0 && list[this->numHorizontalAngles - 1] == 270.0 )
      {
        if ( v3 >= 90.0 )
        {
          if ( v3 >= 270.0 )
            v3 = (float)((float)540.0 - (float)v3);
        }
        else
        {
          v3 = (float)((float)180.0 - (float)v3);
        }
      }
      else if ( v7 == -90.0 && list[this->numHorizontalAngles - 1] == 90.0 )
      {
        if ( v3 >= 180.0 )
          v3 = (float)((float)360.0 - (float)v3);
        v3 = (float)((float)v3 - (float)90.0);
      }
    }
  }
  numHorizontalAngles = this->numHorizontalAngles;
  v9 = 0.0;
  v10 = 1;
  if ( numHorizontalAngles > 1 )
  {
    v11 = 1;
    while ( v3 >= list[v11] )
    {
      ++v10;
      ++v11;
      if ( v10 >= numHorizontalAngles )
        goto LABEL_38;
    }
    v9 = (float)((float)((float)v3 - this->horizontalAngles.list[v10 - 1])
               / (float)(this->horizontalAngles.list[v10] - this->horizontalAngles.list[v10 - 1]));
  }
LABEL_38:
  v12 = this->verticalAngles.list;
  v13 = *v12;
  if ( v13 == 0.0 && (numVerticalAngles = this->numVerticalAngles, v12[numVerticalAngles - 1] == 90.0) )
  {
    if ( vertAngle > 90.0 )
      return *((float *)&v4 + 1);
  }
  else if ( v13 != 0.0 || (numVerticalAngles = this->numVerticalAngles, v12[numVerticalAngles - 1] != 180.0) )
  {
    if ( v13 == 90.0 && (numVerticalAngles = this->numVerticalAngles, v12[numVerticalAngles - 1] == 180.0) )
    {
      if ( vertAngle < 90.0 )
        return *((float *)&v4 + 1);
    }
    else if ( v13 == -90.0 && (numVerticalAngles = this->numVerticalAngles, v12[numVerticalAngles - 1] == 90.0) )
    {
      vertAngle = (float)((float)vertAngle - (float)90.0);
    }
    else
    {
      numVerticalAngles = this->numVerticalAngles;
      if ( numVerticalAngles == 1 )
        vertAngle = 0.0;
    }
  }
  v15 = 0.0;
  v16 = 1;
  if ( numVerticalAngles > 1 )
  {
    v17 = 1;
    while ( vertAngle >= v12[v17] )
    {
      ++v16;
      ++v17;
      if ( v16 >= numVerticalAngles )
        goto LABEL_59;
    }
    v15 = (float)((float)((float)vertAngle - this->verticalAngles.list[v16 - 1])
                / (float)(this->verticalAngles.list[v16] - this->verticalAngles.list[v16 - 1]));
  }
LABEL_59:
  v18 = v16 - 1;
  v19 = v10 - 1;
  v20 = v16 - 1;
  if ( v10 - 1 >= numHorizontalAngles )
    v19 = numHorizontalAngles - 1;
  if ( v18 >= numVerticalAngles )
    v20 = numVerticalAngles - 1;
  v22 = numVerticalAngles * v19 + v20;
  v21 = this->candela.list;
  v23 = v16 - 1;
  v25 = v21[v22];
  v24 = v10;
  if ( v10 >= numHorizontalAngles )
    v24 = numHorizontalAngles - 1;
  if ( v18 >= numVerticalAngles )
    v23 = numVerticalAngles - 1;
  v26 = numVerticalAngles * v24 + v23;
  v27 = v16;
  v29 = v21[v26];
  v28 = v10 - 1;
  if ( v10 - 1 >= numHorizontalAngles )
    v28 = numHorizontalAngles - 1;
  if ( v16 >= numVerticalAngles )
    v27 = numVerticalAngles - 1;
  v30 = numVerticalAngles * v28 + v27;
  v31 = v16;
  v33 = v21[v30];
  v32 = v10;
  if ( v10 >= numHorizontalAngles )
    v32 = numHorizontalAngles - 1;
  if ( v16 >= numVerticalAngles )
    v31 = numVerticalAngles - 1;
  v4 = (float)((1.0 - v15) * v29 * v9
             + (1.0 - v9) * v33 * v15
             + (1.0 - v15) * (1.0 - v9) * v25
             + (float)((float)(v21[numVerticalAngles * v32 + v31] * (float)v15) * (float)v9));
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?Print@idIESfile@@UBAXXZ
// EA  : 0x828C1090
// RVA : 0x008C1090
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void __fastcall idIESfile::Print(idIESfile *this)
{
  idLib::Printf(
    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(this->renderInfo.maxCandela)),
    (unsigned int)COERCE_UNSIGNED_INT64(this->renderInfo.maxCandela),
    (unsigned int)COERCE_UNSIGNED_INT64(this->renderInfo.lightArea.x),
    (unsigned int)COERCE_UNSIGNED_INT64(this->renderInfo.lightArea.y),
    (unsigned int)COERCE_UNSIGNED_INT64(this->renderInfo.lightArea.z),
    (unsigned int)COERCE_UNSIGNED_INT64(this->renderInfo.cutoffCosine));
}


// ========================================================================
// ?TestIES_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828C10F8
// RVA : 0x008C10F8
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void __fastcall TestIES_f(const idCmdArgs *args)
{
  idResource *v1; // r3

  v1 = idResourceList::Load(
         this: &idIESfile::resourceList,
         name: "ies/inc_elips.IES",
         makeDefault: true,
         skipStaleCheck: false);
  v1->Print(this: v1);
}


// ========================================================================
// ?TestRnd_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828C1520
// RVA : 0x008C1520
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void __fastcall TestRnd_f(const idCmdArgs *args)
{
  int v1; // r11
  idRandomMersenne *v2; // r10
  int i; // ctr
  int v4; // r9
  unsigned int index; // r31
  int j; // r30
  unsigned int v7; // r11
  unsigned int v8; // r8
  __int64 v9; // r6
  unsigned int v10; // r31
  bool v11; // zf
  double v12; // fp11
  unsigned int v13; // r5
  unsigned int v14; // r6
  idRandomMersenne v15; // [sp+60h] [-A00h] BYREF

  v1 = 1;
  v15.index = 0;
  v2 = &v15;
  v15.MT[0] = 0;
  for ( i = 623; i != 0; --i )
  {
    v4 = 1812433253 * ((v2->MT[0] >> 30) ^ v2->MT[0]) + v1++;
    v2 = (idRandomMersenne *)((char *)v2 + 4);
    v2->MT[0] = v4;
  }
  index = v15.index;
  for ( j = 100; j != 0; --j )
  {
    if ( index >= 0x270 )
    {
      v15.index = 0;
      idRandomMersenne::GenerateNumbers(this: &v15);
      index = v15.index;
    }
    v7 = index + 1;
    v8 = v15.MT[index];
    v15.index = index + 1;
    LODWORD(v9) = (v8 >> 11) ^ v8;
    HIDWORD(v9) = v9 & 0xFF3A58AD;
    v11 = index + 1 < 0x270;
    v10 = ((((v9 & 0xFF3A58AD) << 7) ^ (unsigned int)v9) << 15) & 0xEFC60000 ^ ((v9 & 0xFF3A58AD) << 7) ^ v9;
    if ( !v11 )
    {
      v15.index = 0;
      idRandomMersenne::GenerateNumbers(this: &v15);
      v7 = v15.index;
    }
    LODWORD(v9) = (v10 >> 18) ^ v10;
    index = v7 + 1;
    v12 = (float)v9;
    v13 = v15.MT[v7];
    v15.index = v7 + 1;
    v14 = ((((((v13 >> 11) ^ v13) & 0xFF3A58AD) << 7) ^ (v13 >> 11) ^ v13) << 15)
        & 0xEFC60000
        ^ ((((v13 >> 11) ^ v13) & 0xFF3A58AD) << 7)
        ^ (v13 >> 11)
        ^ v13;
    idLib::Printf(fmt: "%i / %f\n", (v14 >> 18) ^ v14, (float)((float)v12 * (float)2.3283064e-10));
  }
}


// ========================================================================
// ?BuildCandelaImage@idIESfile@@QAAXXZ
// EA  : 0x828C1730
// RVA : 0x008C1730
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void __fastcall idIESfile::BuildCandelaImage(idIESfile *this)
{
  unsigned __int8 *v2; // r3
  __int64 v3; // r11
  unsigned __int8 *v4; // r23
  int v5; // r27
  char *v6; // r25
  int v7; // r29
  char *v8; // r30
  double v9; // fp31
  __int64 v10; // [sp+60h] [-C0h]
  idStr v11[2]; // [sp+80h] [-A0h] BYREF

  v2 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\renderer\\IESfile.cpp(378) : TAG_IMAGE",
                            size: 0x40000u,
                            tag: TAG_IMAGE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  HIDWORD(v3) = &off_82230000;
  v4 = v2;
  v5 = 0;
  v6 = (char *)(v2 + 1);
  do
  {
    LODWORD(v3) = v5;
    v7 = 0;
    v8 = v6 - 1022;
    v9 = (float)((float)v3 * (float)1.40625);
    do
    {
      LODWORD(v3) = v7++;
      v10 = (__int64)(float)((float)(idIESfile::CandelaAtAngle(
                                       this,
                                       horizAngle: v9,
                                       vertAngle: (float)((float)v3 * (float)0.703125))
                                   / this->renderInfo.maxCandela)
                           * (float)255.0);
      HIDWORD(v3) = (unsigned __int8)v10;
      v8[1023] = v10;
      v8[1022] = v10;
      v8[1021] = v10;
      v8 += 1024;
      *v8 = -1;
    }
    while ( v7 < 256 );
    ++v5;
    v6 += 4;
  }
  while ( v5 < 256 );
  idStr::idStr(this: v11, text: this->name.str);
  idStr::StripFileExtension(this: v11);
  idStr::Append(this: v11, text: ".png");
  if ( !fileSystem->FileExists(this: fileSystem, a2: v11[0].data, a3: false) )
  {
    idLib::Printf(fmt: "Writing %s\n", v11[0].data);
    R_WritePNG(filename: v11[0].data, data: v4, width: 256, height: 256, flipVertical: false, basePath: FSPATH_BASE);
  }
  idStr::FreeData(this: v11);
  if ( v4 != nullptr )
    idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
}


// ========================================================================
// __unwind$221479_0
// EA  : 0x828C18F8
// RVA : 0x008C18F8
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_221479_0()
{
  int v0; // r12

  idImageData::~idImageData(this: (idImageData *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$221480_0
// EA  : 0x828C1920
// RVA : 0x008C1920
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_221480_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 128));
}


// ========================================================================
// ?BuildEditorModel@idIESfile@@QAAXXZ
// EA  : 0x828C1950
// RVA : 0x008C1950
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void __fastcall idIESfile::BuildEditorModel(idIESfile *this)
{
  idStaticModel *v2; // r3
  idStaticModel *v3; // r3
  idTriangles *v4; // r3
  idTriangles *v5; // r30
  float y; // r10
  float z; // r9
  float x; // r11
  double v9; // fp28
  double v10; // fp27
  double v11; // fp29
  double v12; // fp31
  double v13; // fp30
  double v14; // fp26
  int v15; // r16
  double v16; // fp29
  idTriangles *v17; // r3
  idTriangles *v18; // r30
  idDrawVert *verts; // r3
  int v20; // r17
  _BYTE v21[12]; // r11
  int v22; // r20
  int v23; // r21
  int v24; // r28
  int v25; // r22
  double v26; // fp30
  double v27; // fp27
  double v28; // fp26
  __int16 v29; // r29
  long double v30; // fp2
  long double v31; // fp2
  double v32; // fp25
  long double v33; // fp2
  double v34; // fp27
  long double v35; // fp2
  double v36; // fp24
  long double v37; // fp2
  double v38; // fp6
  double v39; // fp5
  idTriangles v40; // [sp+60h] [-2C0h] BYREF
  idVec3 v41; // [sp+E8h] [-238h] BYREF
  idVec3 v42; // [sp+F8h] [-228h] BYREF
  idVec3 v43; // [sp+108h] [-218h] BYREF
  idVec3 v44; // [sp+118h] [-208h] BYREF
  idVec3 v45; // [sp+128h] [-1F8h] BYREF
  idVec3 v46; // [sp+138h] [-1E8h] BYREF
  idVec3 v47; // [sp+148h] [-1D8h] BYREF
  idVec3 v48; // [sp+158h] [-1C8h] BYREF
  idVec3 v49; // [sp+168h] [-1B8h] BYREF
  idVec3 v50; // [sp+178h] [-1A8h] BYREF
  idVec3 v51; // [sp+188h] [-198h] BYREF
  idVec3 v52; // [sp+198h] [-188h] BYREF
  idVec3 v53; // [sp+1A8h] [-178h] BYREF
  idVec3 v54; // [sp+1B8h] [-168h] BYREF
  idVec3 v55; // [sp+1C8h] [-158h] BYREF
  idVec3 v56; // [sp+1D8h] [-148h] BYREF
  idVec3 v57; // [sp+1E8h] [-138h] BYREF
  idStaticModelSurface v58; // [sp+200h] [-120h] BYREF

  v2 = (idStaticModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x194u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idStaticModel::idStaticModel(this: v2);
  else
    v3 = nullptr;
  this->editorModel = v3;
  idResource::SetName(this: v3, _name: this->editorModelName.data);
  v4 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x84u,
                        tag: TAG_TRIANGLES,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idTriangles::idTriangles(this: v4);
  else
    v5 = nullptr;
  idTriangles::AllocStaticTriSurfVerts(this: v5, numVerts: 24);
  idTriangles::AllocStaticTriSurfIndexes(this: v5, numIndexes: 36);
  y = this->renderInfo.lightArea.y;
  z = this->renderInfo.lightArea.z;
  x = this->renderInfo.lightArea.x;
  v9 = -x;
  v45.x = v9;
  v10 = -y;
  v45.y = v10;
  v40.bounds.b[0].y = y;
  v11 = y;
  v40.bounds.b[0].z = z;
  v12 = z;
  v40.bounds.b[0].x = x;
  v13 = x;
  v47.y = v45.y;
  v53.x = v9;
  v47.x = x;
  v45.z = z;
  v47.z = z;
  v40.vsb.stScale.y = x;
  v40.vsb.stBias.x = y;
  v40.vsb.stBias.y = z;
  v53.y = y;
  v53.z = z;
  v14 = -this->renderInfo.lightArea.z;
  idTriangles::AddCubeFace(this: v5, v1: &v53, v2: (const idVec3 *)&v40.vsb.stScale.y, v3: &v47, v4: &v45);
  *(float *)&v40.vertexBuffer.offsetInOtherBuffer = v13;
  *(float *)&v40.vertexBuffer.apiObject = v11;
  *(float *)&v40.vertexBuffer.usage = v14;
  v49.x = v13;
  v49.y = v10;
  v49.z = v14;
  v41.x = v9;
  v41.y = v10;
  v41.z = v14;
  v57.x = v9;
  v57.y = v11;
  v57.z = v14;
  idTriangles::AddCubeFace(
    this: v5,
    v1: &v57,
    v2: &v41,
    v3: &v49,
    v4: (const idVec3 *)&v40.vertexBuffer.offsetInOtherBuffer);
  v43.x = v13;
  v43.y = v10;
  v43.z = v14;
  v51.x = v13;
  v51.y = v11;
  v51.z = v14;
  *(float *)&v40.generateNormals = v13;
  *(float *)&v40.numIndexes = v11;
  *(float *)&v40.numVerts = v12;
  v55.x = v13;
  v55.y = v10;
  v55.z = v12;
  idTriangles::AddCubeFace(this: v5, v1: &v55, v2: (const idVec3 *)&v40.generateNormals, v3: &v51, v4: &v43);
  *(float *)&v40.allowGpuHosting = v9;
  v40.vsb.xyzScale.x = v11;
  v40.vsb.xyzScale.y = v12;
  v40.vsb.xyzBias.x = v9;
  v40.vsb.xyzBias.y = v11;
  v40.vsb.xyzBias.z = v14;
  *(float *)&v40.verts = v9;
  *(float *)&v40.indexes = v10;
  *(float *)&v40.vertexMask = v14;
  *(float *)&v40.indexBuffer.offsetInOtherBuffer = v9;
  *(float *)&v40.indexBuffer.apiObject = v10;
  *(float *)&v40.indexBuffer.usage = v12;
  idTriangles::AddCubeFace(
    this: v5,
    v1: (const idVec3 *)&v40.indexBuffer.offsetInOtherBuffer,
    v2: (const idVec3 *)&v40.verts,
    v3: &v40.vsb.xyzBias,
    v4: (const idVec3 *)&v40.allowGpuHosting);
  v42.x = v9;
  v42.y = v10;
  v42.z = v14;
  v44.x = v13;
  v44.y = v10;
  v44.z = v14;
  v46.x = v13;
  v46.y = v10;
  v46.z = v12;
  v48.x = v9;
  v48.y = v10;
  v48.z = v12;
  idTriangles::AddCubeFace(this: v5, v1: &v48, v2: &v46, v3: &v44, v4: &v42);
  v50.x = v13;
  v50.y = v11;
  v50.z = v12;
  v52.x = v13;
  v52.y = v11;
  v52.z = v14;
  v54.x = v9;
  v54.y = v11;
  v54.z = v14;
  v56.x = v9;
  v56.y = v11;
  v56.z = v12;
  idTriangles::AddCubeFace(this: v5, v1: &v56, v2: &v54, v3: &v52, v4: &v50);
  v5->bounds = *idTriangles::BoundsFromVertScan(this: &v40, result: &v5->bounds);
  idTriangles::UpdateIndexBuffer(this: v5);
  idTriangles::UpdateVertexBuffer(this: v5);
  idStaticModelSurface::idStaticModelSurface(this: &v58);
  v58.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                       this: &idMaterial::resourceList,
                                       name: "_white",
                                       makeDefault: true);
  v58.geometry = v5;
  idStaticModel::AddSurface(this: this->editorModel, surf: &v58);
  if ( this->verticalAngles.list[this->numVerticalAngles - 1] > 90.0 )
  {
    v15 = 18;
    v16 = 180.0;
  }
  else
  {
    v15 = 9;
    v16 = 90.0;
  }
  v17 = (idTriangles *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x84u,
                         tag: TAG_TRIANGLES,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v17 != nullptr )
    v18 = idTriangles::idTriangles(this: v17);
  else
    v18 = nullptr;
  idTriangles::AllocStaticTriSurfVerts(this: v18, numVerts: 37 * (v15 + 1));
  verts = v18->verts;
  v18->numVerts = 37 * (v15 + 1);
  memset(Dst: verts, Val: 0, Size: 1184 * (v15 + 1));
  idTriangles::AllocStaticTriSurfIndexes(this: v18, numIndexes: 216 * v15);
  v18->numIndexes = 216 * v15;
  v20 = 0;
  *(_DWORD *)&v21[4] = &unk_821D0000;
  *(_DWORD *)v21 = 0;
  v22 = 0;
  v23 = -37;
  do
  {
    *(_DWORD *)&v21[8] = v20;
    v24 = 0;
    v25 = 0;
    v26 = (float)((float)((float)*(__int64 *)&v21[4] * (float)v16) / (float)__SPAIR64__(&unk_821D0000, v15));
    do
    {
      *(_DWORD *)&v21[4] = v25 / 36;
      *(_QWORD *)&v40.bounds.b[0].x = *(_QWORD *)v21;
      v27 = (float)*(__int64 *)v21;
      v28 = idIESfile::CandelaAtAngle(this, horizAngle: v27, vertAngle: v26);
      v29 = v22 + v24;
      *(double *)&v30 = (float)((float)((float)v27 * 3.1415927) * (float)0.0055555557);
      v31 = cos(x: v30);
      v32 = (float)*(double *)&v31;
      *(double *)&v31 = (float)((float)((float)v27 * 3.1415927) * (float)0.0055555557);
      v33 = sin(x: v31);
      v34 = (float)*(double *)&v33;
      *(double *)&v33 = (float)((float)((float)v26 * 3.1415927) * (float)0.0055555557);
      v35 = cos(x: v33);
      v36 = -(float)*(double *)&v35;
      *(double *)&v35 = (float)((float)((float)v26 * 3.1415927) * (float)0.0055555557);
      v37 = sin(x: v35);
      v38 = __fsqrts(v28);
      *(_DWORD *)&v21[4] = 32 * (v22 + v24);
      *(_DWORD *)&v21[8] = (char *)v18->verts + *(_DWORD *)&v21[4];
      v39 = (float)((float)v38 * ies_editorModelSurfaceCandela.valueFloat);
      *(float *)(*(_DWORD *)&v21[8] + 8) = (float)v36 * (float)((float)v38 * ies_editorModelSurfaceCandela.valueFloat);
      **(float **)&v21[8] = (float)((float)v32 * (float)*(double *)&v37) * (float)v39;
      *(float *)(*(_DWORD *)&v21[8] + 4) = (float)((float)v34 * (float)*(double *)&v37) * (float)v39;
      if ( v24 > 0 && v20 > 0 )
      {
        *(_DWORD *)&v21[8] = 12 * (v23 + v24);
        *(unsigned __int16 *)((char *)v18->indexes + *(_DWORD *)&v21[8]) = v29 - 38;
        *(unsigned __int16 *)((char *)v18->indexes + *(_DWORD *)&v21[8] + 2) = v29 - 37;
        *(unsigned __int16 *)((char *)v18->indexes + *(_DWORD *)&v21[8] + 4) = v29 - 1;
        *(unsigned __int16 *)((char *)v18->indexes + *(_DWORD *)&v21[8] + 6) = v29 - 1;
        *(_DWORD *)v21 = (char *)v18->indexes + *(_DWORD *)&v21[8];
        *(_WORD *)(*(_DWORD *)v21 + 8) = v29 - 37;
        *(_DWORD *)&v21[4] = v18->indexes;
        *(_WORD *)(*(_DWORD *)&v21[4] + *(_DWORD *)&v21[8] + 10) = v29;
      }
      v25 += 360;
      ++v24;
    }
    while ( v25 <= 12960 );
    ++v20;
    v22 += 37;
    v23 += 36;
  }
  while ( v20 <= v15 );
  v18->bounds = *idTriangles::BoundsFromVertScan(this: &v40, result: &v18->bounds);
  idTriangles::UpdateIndexBuffer(this: v18);
  idTriangles::UpdateVertexBuffer(this: v18);
  v58.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                       this: &idMaterial::resourceList,
                                       name: "_white",
                                       makeDefault: true);
  v58.geometry = v18;
  idStaticModel::AddSurface(this: this->editorModel, surf: &v58);
  idStaticModel::FinishStaticModel(this: this->editorModel, cleanup: false);
  if ( (v58.skinRemaps.listStatic == 0 || v58.skinRemaps.listStatic == 2) && v58.skinRemaps.list != nullptr )
    idMem::Free(this: &mem, ptr: v58.skinRemaps.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$221652
// EA  : 0x828C1FFC
// RVA : 0x008C1FFC
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void __fastcall _unwind_221652(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 800 + 80), tag: a2);
}


// ========================================================================
// __unwind$221653_0
// EA  : 0x828C2024
// RVA : 0x008C2024
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_221653_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 800 + 80), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$221654_0
// EA  : 0x828C2050
// RVA : 0x008C2050
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_221654_0()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 800 + 512));
}


// ========================================================================
// __unwind$221655_1
// EA  : 0x828C2078
// RVA : 0x008C2078
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_221655_1()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 800 + 80), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?LoadResource@idIESfile@@UAAXXZ
// EA  : 0x828C20B0
// RVA : 0x008C20B0
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void __fastcall idIESfile::LoadResource(idIESfile *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  int v5; // r11
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  int v12; // r3
  int v13; // r29
  int i; // r29
  idList<float,5> *p_verticalAngles; // r26
  float *list; // r4
  int j; // r29
  idList<float,5> *p_horizontalAngles; // r28
  float *v19; // r4
  int k; // r29
  int m; // r29
  int num; // r9
  int v23; // r10
  float *v24; // r9
  int v25; // r11
  int numHorizontalAngles; // r10
  int v27; // r11
  int v28; // r10
  float *v29; // r7
  double v30; // fp11
  idVec3 *p_lightArea; // r11
  double width; // fp13
  double v33; // fp12
  double v34; // fp8
  int unitsType; // r10
  double y; // fp12
  double z; // fp11
  double v38; // fp9
  double v39; // fp8
  double v40; // fp10
  double v41; // fp12
  double v42; // fp11
  int v43; // [sp+8h] [-1F8h]
  int v44; // [sp+Ch] [-1F4h]
  int v45; // [sp+10h] [-1F0h]
  int v46; // [sp+14h] [-1ECh]
  int v47; // [sp+18h] [-1E8h]
  int v48; // [sp+1Ch] [-1E4h]
  float v49[4]; // [sp+50h] [-1B0h] BYREF
  idStr v50; // [sp+60h] [-1A0h] BYREF
  idStr v51; // [sp+80h] [-180h] BYREF
  idToken v52; // [sp+A0h] [-160h] BYREF
  idLexer v53; // [sp+F0h] [-110h] BYREF
  idStr v54; // [sp+180h] [-80h] BYREF
  idStr v55[3]; // [sp+1A0h] [-60h] BYREF

  idLexer::idLexer(this: &v53, flags_: 0);
  if ( idLexer::LoadFile(this: &v53, filename_: this->name.str, OSPath: false) )
  {
    v52.len = 0;
    v52.allocedAndFlag = 20;
    v53.flags = 0x80000;
    v52.floatvalue = -3.4028235e38;
    v52.data = v52.baseBuffer;
    v52.baseBuffer[0] = 0;
    v52.intvalue = 0;
    memset(&v52.whiteSpaceStart_p, 0, 12);
    v51.allocedAndFlag = 20;
    v51.data = v51.baseBuffer;
    v51.len = 0;
    v51.baseBuffer[0] = 0;
    idLexer::ParseCompleteLine(this: &v53, out: &v51);
    if ( idStr::Cmpn(s1: v51.data, s2: "IESNA91", n: 7) != 0 )
    {
      if ( idStr::Cmpn(s1: v51.data, s2: "IESNA:LM-63-1995", n: 16) != 0 )
      {
        if ( idStr::Cmpn(s1: v51.data, s2: "IESNA:LM-63-2002", n: 16) != 0 )
        {
          idResource::SetResourceError(
            this: &this->idResource,
            fmt: "File wasn't IESNA 91 or 95",
            a3: v8,
            a4: v7,
            a5: v6,
            a6: v43,
            a7: v44,
            a8: v45,
            a9: v46,
            a10: v47,
            a11: v48);
          idStr::FreeData(this: &v51);
          idStr::FreeData(this: &v52);
          goto LABEL_80;
        }
        v5 = 2002;
      }
      else
      {
        v5 = 95;
      }
    }
    else
    {
      v5 = 91;
    }
    this->formatYear = v5;
    v50.allocedAndFlag = 20;
    v50.len = 0;
    v50.data = v50.baseBuffer;
    v50.baseBuffer[0] = 0;
    idLexer::ReadToken(this: &v53, token: &v52);
    while ( *v52.data == 91 )
    {
      idLexer::ReadToken(this: &v53, token: &v52);
      if ( idStr::Cmp(s1: v52.data, s2: "_CATEGORY") == 0 )
      {
        idLexer::ExpectTokenString(this: &v53, string: "]");
        idLexer::ReadToken(this: &v53, token: &v52);
      }
      idLexer::ParseRestOfLine(this: &v53, out: &v50);
      idStr::FreeData(this: &v50);
      v50.allocedAndFlag = 20;
      v50.data = v50.baseBuffer;
      v50.len = 0;
      v50.baseBuffer[0] = 0;
      idLexer::ReadToken(this: &v53, token: &v52);
    }
    idStr::FreeData(this: &v50);
    if ( idStr::Cmp(s1: v52.data, s2: "TILT") != 0 )
    {
      idResource::SetResourceError(
        this: &this->idResource,
        fmt: "TILT keyword not present",
        a3: v11,
        a4: v10,
        a5: v9,
        a6: v43,
        a7: v44,
        a8: v45,
        a9: v46,
        a10: v47,
        a11: v48);
      idStr::FreeData(this: &v51);
      idStr::FreeData(this: &v52);
      goto LABEL_80;
    }
    idLexer::ExpectTokenString(this: &v53, string: "=");
    idLexer::ReadToken(this: &v53, token: &v52);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->factorAngles);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->factorScales);
    if ( idStr::Cmpn(s1: v52.data, s2: "INCLUDE", n: 7) != 0 )
    {
      this->lampToLuminaireGeometry = 0;
      this->numAngleFactors = 0;
    }
    else
    {
      this->lampToLuminaireGeometry = idLexer::ParseInt(this: &v53);
      v12 = idLexer::ParseInt(this: &v53);
      v13 = 0;
      for ( this->numAngleFactors = v12; v13 < this->numAngleFactors; ++v13 )
      {
        v49[0] = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
        idList<float,13>::Append(this: (idList<float,13> *)&this->factorAngles, obj: v49);
      }
      for ( i = 0; i < this->numAngleFactors; ++i )
      {
        v49[0] = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
        idList<float,13>::Append(this: (idList<float,13> *)&this->factorScales, obj: v49);
      }
    }
    this->numLamps = idLexer::ParseInt(this: &v53);
    this->lumensPerLamp = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
    this->candelaMultiplier = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
    this->numVerticalAngles = idLexer::ParseInt(this: &v53);
    this->numHorizontalAngles = idLexer::ParseInt(this: &v53);
    this->photoMetricType = idLexer::ParseInt(this: &v53);
    this->unitsType = idLexer::ParseInt(this: &v53);
    this->width = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
    this->length = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
    this->height = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
    this->ballastFactor = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
    this->futureUse = idLexer::ParseInt(this: &v53);
    this->inputWats = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
    p_verticalAngles = &this->verticalAngles;
    if ( this->verticalAngles.listStatic == 0 || this->verticalAngles.listStatic == 2 )
    {
      list = p_verticalAngles->list;
      if ( p_verticalAngles->list != nullptr )
      {
        v49[0] = *(float *)&p_verticalAngles->list;
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      }
      p_verticalAngles->list = nullptr;
      this->verticalAngles.size = 0;
    }
    this->verticalAngles.num = 0;
    for ( j = 0; j < this->numVerticalAngles; ++j )
    {
      v49[0] = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
      idList<float,13>::Append(this: (idList<float,13> *)&this->verticalAngles, obj: v49);
    }
    p_horizontalAngles = &this->horizontalAngles;
    if ( this->horizontalAngles.listStatic == 0 || this->horizontalAngles.listStatic == 2 )
    {
      v19 = p_horizontalAngles->list;
      if ( p_horizontalAngles->list != nullptr )
      {
        v49[0] = *(float *)&p_horizontalAngles->list;
        idMem::Free(this: &mem, ptr: v19, align: ALIGN_16);
      }
      p_horizontalAngles->list = nullptr;
      this->horizontalAngles.size = 0;
    }
    this->horizontalAngles.num = 0;
    for ( k = 0; k < this->numHorizontalAngles; ++k )
    {
      v49[0] = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
      idList<float,13>::Append(this: (idList<float,13> *)&this->horizontalAngles, obj: v49);
    }
    for ( m = 0; m < this->numHorizontalAngles * this->numVerticalAngles; ++m )
    {
      v49[0] = idLexer::ParseFloat(this: &v53, errorFlag: nullptr);
      idList<float,13>::Append(this: (idList<float,13> *)&this->candela, obj: v49);
    }
    num = this->candela.num;
    v23 = 0;
    this->renderInfo.maxCandela = 0.0;
    if ( num > 0 )
    {
      v24 = this->candela.list;
      v25 = 0;
      do
      {
        if ( v24[v25] > (double)this->renderInfo.maxCandela )
          this->renderInfo.maxCandela = v24[v25];
        ++v23;
        ++v25;
      }
      while ( v23 < this->candela.num );
    }
    if ( p_verticalAngles->list[this->numVerticalAngles - 1] > 90.0 )
    {
      this->renderInfo.cutoffCosine = -1.0;
    }
    else
    {
      numHorizontalAngles = this->numHorizontalAngles;
      this->renderInfo.cutoffCosine = 0.0;
      v27 = 0;
      if ( numHorizontalAngles > 0 )
      {
        v28 = 4;
        do
        {
          ++v27;
          v29 = (float *)((char *)this->candela.list + v28 * this->numVerticalAngles);
          v28 += 4;
          *(v29 - 1) = 0.0;
        }
        while ( v27 < this->numHorizontalAngles );
      }
    }
    if ( (_S13_23 & 1) != 0 )
    {
      v30 = METERS_TO_UNITS;
    }
    else
    {
      _S13_23 |= 1u;
      v30 = 52.48;
      METERS_TO_UNITS = 52.48;
    }
    p_lightArea = &this->renderInfo.lightArea;
    this->renderInfo.lightArea.x = this->width;
    this->renderInfo.lightArea.y = this->length;
    this->renderInfo.lightArea.z = this->height;
    width = this->width;
    if ( width >= 0.0 && this->length >= 0.0 && this->height >= 0.0 )
    {
LABEL_73:
      unitsType = this->unitsType;
      if ( unitsType == 1 )
      {
        y = this->renderInfo.lightArea.y;
        z = this->renderInfo.lightArea.z;
        p_lightArea->x = p_lightArea->x * (float)16.0;
        v38 = (float)((float)y * (float)16.0);
        v39 = (float)((float)z * (float)16.0);
      }
      else
      {
        if ( unitsType != 2 )
        {
LABEL_78:
          v41 = this->renderInfo.lightArea.y;
          v42 = this->renderInfo.lightArea.z;
          p_lightArea->x = p_lightArea->x * (float)0.5;
          this->renderInfo.lightArea.y = (float)v41 * (float)0.5;
          this->renderInfo.lightArea.z = (float)v42 * (float)0.5;
          idStr::idStr(this: &v54, text: "generated/cloud/cpuImages/");
          idStr::Append(this: &v54, text: (char *)this->name.str);
          idStr::StripFileExtension(this: &v54);
          idStr::Append(this: &v54, text: ".cpuimage");
          strncpy(dest: this->renderInfo.projectMap, source: v54.data, count: 0xFFu);
          idIESfile::BuildCandelaImage(this);
          idStr::idStr(this: v55, text: "generated/models/");
          idStr::Append(this: v55, text: (char *)this->name.str);
          idStr::StripFileExtension(this: v55);
          idStr::Append(this: v55, text: ".bmodel");
          idIESfile::BuildEditorModel(this);
          idStr::FreeData(this: v55);
          idStr::FreeData(this: &v54);
          idStr::FreeData(this: &v51);
          idStr::FreeData(this: &v52);
          goto LABEL_80;
        }
        v40 = this->renderInfo.lightArea.z;
        v38 = (float)(this->renderInfo.lightArea.y * (float)v30);
        p_lightArea->x = (float)v30 * p_lightArea->x;
        v39 = (float)((float)v40 * (float)v30);
      }
      this->renderInfo.lightArea.z = v39;
      this->renderInfo.lightArea.y = v38;
      goto LABEL_78;
    }
    if ( (width >= 0.0 || this->length != 0.0 || this->height != 0.0)
      && (width >= 0.0 || this->length != 0.0 || this->height >= 0.0)
      && (width >= 0.0 || this->length != 0.0 || this->height <= 0.0) )
    {
      if ( width == 0.0 && this->length > 0.0 && this->height < 0.0 )
      {
        this->width = this->length;
LABEL_72:
        v33 = __fabs(this->renderInfo.lightArea.z);
        v34 = __fabs(this->renderInfo.lightArea.y);
        p_lightArea->x = __fabs(p_lightArea->x);
        this->renderInfo.lightArea.y = v34;
        this->renderInfo.lightArea.z = v33;
        goto LABEL_73;
      }
      if ( width <= 0.0 || this->length != 0.0 || this->height >= 0.0 )
        goto LABEL_72;
    }
    this->length = this->width;
    goto LABEL_72;
  }
  HIDWORD(v4) = this->name.str;
  idResource::SetResourceError(
    this: &this->idResource,
    fmt: "IES file not found '%s'!",
    a3: v4,
    a4: v3,
    a5: v2,
    a6: v43,
    a7: v44,
    a8: v45,
    a9: v46,
    a10: v47,
    a11: v48);
LABEL_80:
  idLexer::~idLexer(this: &v53);
}


// ========================================================================
// __unwind$222719
// EA  : 0x828C2928
// RVA : 0x008C2928
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_222719()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 512 + 240));
}


// ========================================================================
// __unwind$222720
// EA  : 0x828C2950
// RVA : 0x008C2950
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_222720()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 160));
}


// ========================================================================
// __unwind$222721
// EA  : 0x828C2978
// RVA : 0x008C2978
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_222721()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 128));
}


// ========================================================================
// __unwind$222722
// EA  : 0x828C29A0
// RVA : 0x008C29A0
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_222722()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 96));
}


// ========================================================================
// __unwind$222723
// EA  : 0x828C29C8
// RVA : 0x008C29C8
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_222723()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 384));
}


// ========================================================================
// __unwind$222724
// EA  : 0x828C29F0
// RVA : 0x008C29F0
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_222724()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 416));
}


// ========================================================================
// TestIES_r
// EA  : 0x828C2A20
// RVA : 0x008C2A20
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void __fastcall TestIES_r(const char *path)
{
  idFileList *v2; // r30
  int v3; // r29
  int v4; // r28
  char *data; // r21
  idFileList *v6; // r30
  int v7; // r29
  int v8; // r28
  char *v9; // r24
  idStr *list; // r27
  int size; // r29
  idStr *v12; // r28
  idStr v13; // [sp+60h] [-A0h] BYREF
  idStr v14[4]; // [sp+80h] [-80h] BYREF

  v2 = fileSystem->ListFiles(this: fileSystem, a2: path, a3: ".ies", a4: 0, a5: 0);
  v3 = 0;
  if ( v2->list.num > 0 )
  {
    v4 = 0;
    do
    {
      data = v2->list.list[v4].data;
      idStr::idStr(this: &v13, text: path);
      idStr::Append(this: &v13, text: "/");
      idStr::Append(this: &v13, text: data);
      idLib::Printf(fmt: "%s\n", v13.data);
      idResourceList::Load(this: &idIESfile::resourceList, name: v13.data, makeDefault: true, skipStaleCheck: false);
      idStr::FreeData(this: &v13);
      ++v3;
      ++v4;
    }
    while ( v3 < v2->list.num );
  }
  idFileList::~idFileList(this: v2);
  idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
  v6 = fileSystem->ListFiles(this: fileSystem, a2: path, a3: "/", a4: 0, a5: 0);
  v7 = 0;
  if ( v6->list.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = v6->list.list[v8].data;
      idStr::idStr(this: v14, text: path);
      idStr::Append(this: v14, text: "/");
      idStr::Append(this: v14, text: v9);
      TestIES_r(path: v14[0].data);
      idStr::FreeData(this: v14);
      ++v7;
      ++v8;
    }
    while ( v7 < v6->list.num );
  }
  if ( v6->list.listStatic == 0 || v6->list.listStatic == 2 )
  {
    list = v6->list.list;
    if ( list != nullptr )
    {
      size = v6->list.size;
      if ( size > 0 )
      {
        v12 = v6->list.list;
        do
        {
          idStr::FreeData(this: v12);
          --size;
          ++v12;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    v6->list.list = nullptr;
    v6->list.size = 0;
  }
  v6->list.num = 0;
  idStr::FreeData(this: &v6->basePath);
  idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
}


// ========================================================================
// __unwind$223154
// EA  : 0x828C2C34
// RVA : 0x008C2C34
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_223154()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$223155
// EA  : 0x828C2C5C
// RVA : 0x008C2C5C
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_223155()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$223265
// EA  : 0x828C2C84
// RVA : 0x008C2C84
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void _unwind_223265()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 256 + 80));
}


// ========================================================================
// ?TestAllIES_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828C2CB0
// RVA : 0x008C2CB0
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void __fastcall TestAllIES_f(const idCmdArgs *args)
{
  TestIES_r(path: "ies");
}


// ========================================================================
// `dynamic initializer for 'idIESfile::resourceList''
// EA  : 0x8334BBC0
// RVA : 0x0134BBC0
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idIESfile::resourceList__()
{
  idResourceList::idResourceList(this: &idIESfile::resourceList, typeName: "ies");
  idIESfile::resourceList.__vftable = (idTypedResourceList<idIESfile>_vtbl *)&idTypedResourceList<idIESfile>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idIESfile::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'ies_editorModelSurfaceCandela''
// EA  : 0x8334BC10
// RVA : 0x0134BC10
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ies_editorModelSurfaceCandela__()
{
  idCVar::idCVar(
    this: &ies_editorModelSurfaceCandela,
    name: "ies_editorModelSurfaceCandela",
    value: "4",
    flags: 4,
    description: "Smaller values will make larger light mesh models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ies_editorModelSurfaceCandela__);
}


// ========================================================================
// `dynamic initializer for 'TestIES_v''
// EA  : 0x8334BC68
// RVA : 0x0134BC68
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestIES_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestIES_v,
           cmdName: "TestIES",
           function: TestIES_f,
           description: "Tests the sampling of IES lights",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestAllIES_v''
// EA  : 0x8334BC90
// RVA : 0x0134BC90
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestAllIES_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestAllIES_v,
           cmdName: "TestAllIES",
           function: TestAllIES_f,
           description: "Loads every file in the ies directory",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestRnd_v''
// EA  : 0x8334BCB8
// RVA : 0x0134BCB8
// PDB : w:\tech5\engine\renderer\iesfile.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestRnd_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestRnd_v,
           cmdName: "TestRnd",
           function: TestRnd_f,
           description: "Tests random number generators",
           argCompletion: nullptr);
}

