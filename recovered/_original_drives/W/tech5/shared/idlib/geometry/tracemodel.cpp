
// ========================================================================
// ??2idTraceModel@@SAPAXI@Z
// EA  : 0x82F25568
// RVA : 0x00F25568
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void *__fastcall idTraceModel::operator new(unsigned int size)
{
  return idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\geometry\\TraceModel.cpp(16) : TAG_COLLISION",
           size,
           tag: TAG_COLLISION,
           zeroBuffer: false,
           align: ALIGN_128,
           heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ??3idTraceModel@@SAXPAX@Z
// EA  : 0x82F25590
// RVA : 0x00F25590
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::operator delete(void *p)
{
  if ( p != nullptr )
    idMem::Free(this: &mem, ptr: p, align: ALIGN_128);
}


// ========================================================================
// ?ClearUnused@idTraceModel@@QAAXXZ
// EA  : 0x82F255B0
// RVA : 0x00F255B0
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::ClearUnused(idTraceModel *this)
{
  unsigned int numPolys; // r5
  unsigned int v3; // r6
  int v4; // r8
  unsigned int *numPolyEdges; // r9
  unsigned int v6; // r11
  unsigned int v7; // ctr

  memset(Dst: &this->vertsX[this->numVerts], Val: 0, Size: 4 * (32 - this->numVerts));
  memset(Dst: &this->vertsY[this->numVerts], Val: 0, Size: 4 * (32 - this->numVerts));
  memset(Dst: &this->vertsZ[this->numVerts], Val: 0, Size: 4 * (32 - this->numVerts));
  memset(Dst: &this->edgeNormalX[this->numEdges], Val: 0, Size: 4 * (32 - this->numEdges));
  memset(Dst: &this->edgeNormalY[this->numEdges], Val: 0, Size: 4 * (32 - this->numEdges));
  memset(Dst: &this->edgeNormalZ[this->numEdges], Val: 0, Size: 4 * (32 - this->numEdges));
  memset(Dst: &this->polyPlaneX[this->numPolys], Val: 0, Size: 4 * (16 - this->numPolys));
  memset(Dst: &this->polyPlaneY[this->numPolys], Val: 0, Size: 4 * (16 - this->numPolys));
  memset(Dst: &this->polyPlaneZ[this->numPolys], Val: 0, Size: 4 * (16 - this->numPolys));
  memset(Dst: &this->polyPlaneW[this->numPolys], Val: 0, Size: 4 * (16 - this->numPolys));
  memset(Dst: &this->edges[this->numEdges], Val: 0, Size: 4 * (32 - this->numEdges));
  memset(Dst: &this->numPolyEdges[this->numPolys], Val: 0, Size: 4 * (16 - this->numPolys));
  memset(Dst: this->polyEdges[this->numPolys], Val: 0, Size: 16 * (16 - this->numPolys));
  numPolys = this->numPolys;
  v3 = 0;
  this->maxPolyEdges = 0;
  if ( numPolys != 0 )
  {
    v4 = 256;
    numPolyEdges = this->numPolyEdges;
    do
    {
      if ( *numPolyEdges > this->maxPolyEdges )
        this->maxPolyEdges = *numPolyEdges;
      v6 = *numPolyEdges;
      if ( *numPolyEdges < 0x10 )
      {
        v7 = 16 - v6;
        do
        {
          *((_BYTE *)&this->vertsX[v4] + v6) = *((_BYTE *)this->vertsX + v4 * 4 - *numPolyEdges + v6);
          ++v6;
          --v7;
        }
        while ( v7 != 0 );
      }
      ++v3;
      ++numPolyEdges;
      v4 += 4;
    }
    while ( v3 < this->numPolys );
  }
}


// ========================================================================
// ?IsClosedSurface@idTraceModel@@QBA_NXZ
// EA  : 0x82F257F0
// RVA : 0x00F257F0
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

int __fastcall idTraceModel::IsClosedSurface(idTraceModel *this, int a2, int a3, int a4, int a5, __int64 a6)
{
  char *p_back_chain; // r11
  int i; // ctr
  unsigned __int8 *v8; // r7
  unsigned int *numPolyEdges; // r6
  unsigned int numPolys; // r5
  int v11; // r11
  unsigned int v12; // ctr
  int v13; // r10
  unsigned int numEdges; // r9
  int v15; // r11
  _DWORD *j; // r10
  char back_chain; // [sp+0h] [-88h] BYREF
  _DWORD v19[32]; // [sp+8h] [-80h] BYREF

  p_back_chain = &back_chain;
  LODWORD(a6) = 0;
  for ( i = 16; i != 0; --i )
  {
    p_back_chain += 8;
    *(_QWORD *)p_back_chain = a6;
  }
  if ( this->numPolys != 0 )
  {
    v8 = this->polyEdges[0];
    numPolyEdges = this->numPolyEdges;
    numPolys = this->numPolys;
    do
    {
      v11 = 0;
      if ( *numPolyEdges != 0 )
      {
        v12 = *numPolyEdges;
        do
        {
          v13 = v8[v11++];
          ++v19[v13 & 0xFFFFFF7F];
          --v12;
        }
        while ( v12 != 0 );
      }
      --numPolys;
      ++numPolyEdges;
      v8 += 16;
    }
    while ( numPolys != 0 );
  }
  numEdges = this->numEdges;
  v15 = 0;
  if ( numEdges == 0 )
    return 1;
  for ( j = v19; *j == 2; ++j )
  {
    if ( ++v15 >= numEdges )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?HasFlaps@idTraceModel@@QBA_NXZ
// EA  : 0x82F258A8
// RVA : 0x00F258A8
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

int __fastcall idTraceModel::HasFlaps(idTraceModel *this)
{
  char *v2; // r11
  __int64 v3; // r9
  int i; // ctr
  unsigned int numPolys; // r3
  unsigned int v6; // r6
  unsigned __int8 *v7; // r5
  unsigned int *numPolyEdges; // r4
  int v9; // r11
  unsigned int v10; // ctr
  unsigned int v11; // r9
  int v12; // r7
  int v13; // r9
  int v14; // r10
  unsigned int numVerts; // r9
  int v16; // r11
  int *j; // r10
  char v19; // [sp+48h] [-8A8h] BYREF
  _BYTE v20[2184]; // [sp+50h] [-8A0h] BYREF

  memset(Dst: &v20[128], Val: 0, Size: 0x800u);
  v2 = &v19;
  LODWORD(v3) = 0;
  for ( i = 16; i != 0; --i )
  {
    v2 += 8;
    *(_QWORD *)v2 = v3;
  }
  numPolys = this->numPolys;
  v6 = 0;
  if ( numPolys != 0 )
  {
    v7 = this->polyEdges[0];
    numPolyEdges = this->numPolyEdges;
    do
    {
      v9 = 0;
      if ( *numPolyEdges != 0 )
      {
        v10 = *numPolyEdges;
        do
        {
          v11 = v7[v9++];
          v12 = this->edges[v11 & 0x7F].v[v11 >> 7];
          v13 = __ROL4__(v12, 2);
          v14 = *(_DWORD *)&v20[v13];
          *(_DWORD *)&v20[v13] = v14 + 1;
          *(_DWORD *)&v20[4 * __ROL4__(v12, 4) + 128 + 4 * v14] = v6;
          --v10;
        }
        while ( v10 != 0 );
      }
      ++v6;
      ++numPolyEdges;
      v7 += 16;
    }
    while ( v6 < numPolys );
  }
  numVerts = this->numVerts;
  v16 = 0;
  if ( numVerts == 0 )
    return 0;
  for ( j = (int *)v20; *j > 2; ++j )
  {
    if ( ++v16 >= numVerts )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?InitOctahedron@idTraceModel@@AAAXXZ
// EA  : 0x82F259D0
// RVA : 0x00F259D0
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::InitOctahedron(idTraceModel *this)
{
  this->numEdges = 12;
  this->maxPolyEdges = 3;
  this->type = TRM_OCTAHEDRON;
  this->edges[0].v[0] = 4;
  this->edges[0].v[1] = 0;
  this->edges[1].v[0] = 0;
  this->edges[1].v[1] = 2;
  this->numVerts = 6;
  this->numPolys = 8;
  this->edges[2].v[0] = 2;
  this->edges[2].v[1] = 4;
  this->edges[3].v[0] = 2;
  this->edges[3].v[1] = 1;
  this->edges[4].v[0] = 1;
  this->edges[4].v[1] = 4;
  this->edges[5].v[0] = 1;
  this->edges[5].v[1] = 3;
  this->edges[6].v[0] = 3;
  this->edges[6].v[1] = 4;
  this->edges[7].v[0] = 3;
  this->edges[7].v[1] = 0;
  this->edges[8].v[0] = 5;
  this->edges[8].v[1] = 2;
  this->edges[9] = (traceModelEdge_t)5;
  this->edges[10].v[0] = 5;
  this->edges[10].v[1] = 1;
  this->edges[11].v[0] = 5;
  this->edges[11].v[1] = 3;
  this->numPolyEdges[0] = 3;
  *(_WORD *)&this->polyEdges[0][0] = 1;
  this->polyEdges[0][2] = 2;
  this->numPolyEdges[1] = 3;
  this->polyEdges[1][0] = -126;
  this->polyEdges[1][1] = 3;
  this->polyEdges[1][2] = 4;
  this->numPolyEdges[2] = 3;
  this->polyEdges[2][0] = -124;
  this->polyEdges[2][1] = 5;
  this->polyEdges[2][2] = 6;
  this->numPolyEdges[3] = 3;
  this->polyEdges[3][0] = -122;
  this->polyEdges[3][1] = 7;
  this->polyEdges[3][2] = 0x80;
  this->numPolyEdges[4] = 3;
  this->polyEdges[4][0] = 8;
  this->polyEdges[4][1] = -127;
  this->polyEdges[4][2] = 9;
  this->numPolyEdges[5] = 3;
  this->polyEdges[5][0] = 10;
  this->polyEdges[5][1] = -125;
  this->polyEdges[5][2] = -120;
  this->numPolyEdges[6] = 3;
  this->polyEdges[6][0] = 11;
  this->polyEdges[6][1] = -123;
  this->polyEdges[6][2] = -118;
  this->numPolyEdges[7] = 3;
  this->polyEdges[7][0] = -119;
  this->polyEdges[7][1] = -121;
  this->polyEdges[7][2] = -117;
  this->isConvex = true;
  idTraceModel::ClearUnused(this);
}


// ========================================================================
// ?InitDodecahedron@idTraceModel@@AAAXXZ
// EA  : 0x82F25B48
// RVA : 0x00F25B48
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::InitDodecahedron(idTraceModel *this)
{
  this->numPolys = 12;
  this->type = TRM_DODECAHEDRON;
  this->maxPolyEdges = 5;
  this->edges[0].v[0] = 0;
  this->edges[1].v[1] = 9;
  this->edges[2].v[0] = 9;
  this->edges[3].v[1] = 16;
  this->edges[0].v[1] = 8;
  this->edges[1].v[0] = 8;
  this->edges[2].v[1] = 4;
  this->edges[3].v[0] = 4;
  this->edges[4].v[0] = 16;
  this->edges[4].v[1] = 0;
  this->edges[5].v[0] = 16;
  this->edges[5].v[1] = 17;
  this->edges[6].v[0] = 17;
  this->edges[6].v[1] = 2;
  this->edges[7].v[0] = 2;
  this->edges[7].v[1] = 12;
  this->edges[8].v[0] = 12;
  this->numVerts = 20;
  this->numEdges = 30;
  this->edges[8].v[1] = 0;
  this->edges[9].v[0] = 2;
  this->edges[9].v[1] = 10;
  this->edges[10].v[0] = 10;
  this->edges[10].v[1] = 3;
  this->edges[11].v[0] = 3;
  this->edges[11].v[1] = 13;
  this->edges[12].v[0] = 13;
  this->edges[12].v[1] = 12;
  this->edges[13].v[0] = 9;
  this->edges[13].v[1] = 5;
  this->edges[14].v[0] = 5;
  this->edges[14].v[1] = 15;
  this->edges[15].v[0] = 15;
  this->edges[15].v[1] = 14;
  this->edges[16].v[0] = 14;
  this->edges[16].v[1] = 4;
  this->edges[17].v[0] = 3;
  this->edges[17].v[1] = 19;
  this->edges[18].v[0] = 19;
  this->edges[18].v[1] = 18;
  this->edges[19].v[0] = 18;
  this->edges[19].v[1] = 1;
  this->edges[20].v[0] = 1;
  this->edges[20].v[1] = 13;
  this->edges[21].v[0] = 7;
  this->edges[21].v[1] = 11;
  this->edges[22].v[0] = 11;
  this->edges[22].v[1] = 6;
  this->edges[23].v[0] = 6;
  this->edges[23].v[1] = 14;
  this->edges[24].v[0] = 15;
  this->edges[24].v[1] = 7;
  this->edges[25].v[0] = 1;
  this->edges[25].v[1] = 8;
  this->edges[26].v[0] = 18;
  this->polyEdges[0][4] = 4;
  this->polyEdges[0][3] = 3;
  this->polyEdges[3][4] = -126;
  this->polyEdges[1][0] = -124;
  this->polyEdges[1][4] = 8;
  this->edges[27].v[0] = 6;
  this->edges[28].v[0] = 11;
  this->edges[28].v[1] = 10;
  this->edges[29].v[1] = 7;
  this->polyEdges[0][0] = 0;
  this->polyEdges[0][1] = 1;
  this->polyEdges[0][2] = 2;
  this->polyEdges[1][2] = 6;
  this->polyEdges[1][3] = 7;
  this->polyEdges[2][0] = -121;
  this->polyEdges[2][1] = 9;
  this->polyEdges[2][2] = 10;
  this->polyEdges[2][3] = 11;
  this->polyEdges[2][4] = 12;
  this->edges[26].v[1] = 5;
  this->edges[27].v[1] = 17;
  this->edges[29].v[0] = 19;
  this->numPolyEdges[0] = 5;
  this->numPolyEdges[1] = 5;
  this->polyEdges[1][1] = 5;
  this->numPolyEdges[2] = 5;
  this->numPolyEdges[3] = 5;
  this->polyEdges[3][0] = 13;
  this->polyEdges[3][1] = 14;
  this->polyEdges[3][2] = 15;
  this->polyEdges[3][3] = 16;
  this->numPolyEdges[4] = 5;
  this->polyEdges[4][0] = 17;
  this->polyEdges[4][1] = 18;
  this->polyEdges[4][2] = 19;
  this->polyEdges[4][3] = 20;
  this->polyEdges[4][4] = -117;
  this->numPolyEdges[5] = 5;
  this->polyEdges[5][0] = 21;
  this->polyEdges[5][1] = 22;
  this->polyEdges[5][2] = 23;
  this->polyEdges[5][3] = -113;
  this->polyEdges[5][4] = 24;
  this->numPolyEdges[6] = 5;
  this->polyEdges[6][0] = -120;
  this->polyEdges[6][1] = -116;
  this->polyEdges[6][2] = -108;
  this->polyEdges[6][3] = 25;
  this->polyEdges[6][4] = 0x80;
  this->numPolyEdges[7] = 5;
  this->polyEdges[7][0] = -103;
  this->polyEdges[7][1] = -109;
  this->polyEdges[7][2] = 26;
  this->polyEdges[7][3] = -115;
  this->polyEdges[7][4] = -127;
  this->numPolyEdges[8] = 5;
  this->polyEdges[8][0] = -125;
  this->polyEdges[8][1] = -112;
  this->polyEdges[8][2] = -105;
  this->polyEdges[8][3] = 27;
  this->polyEdges[8][4] = -123;
  this->numPolyEdges[9] = 5;
  this->polyEdges[9][0] = -106;
  this->polyEdges[9][1] = 28;
  this->polyEdges[9][2] = -119;
  this->polyEdges[9][3] = -122;
  this->polyEdges[9][4] = -101;
  this->numPolyEdges[10] = 5;
  this->polyEdges[10][0] = -104;
  this->polyEdges[10][1] = -114;
  this->polyEdges[10][2] = -102;
  this->polyEdges[10][3] = -110;
  this->polyEdges[10][4] = 29;
  this->numPolyEdges[11] = 5;
  this->polyEdges[11][0] = -99;
  this->polyEdges[11][1] = -111;
  this->polyEdges[11][2] = -118;
  this->polyEdges[11][3] = -100;
  this->polyEdges[11][4] = -107;
  this->isConvex = true;
  idTraceModel::ClearUnused(this);
}


// ========================================================================
// ?InitBone@idTraceModel@@AAAXXZ
// EA  : 0x82F25EB8
// RVA : 0x00F25EB8
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::InitBone(idTraceModel *this)
{
  this->numEdges = 9;
  this->maxPolyEdges = 3;
  this->type = TRM_BONE;
  this->numVerts = 5;
  this->numPolys = 6;
  this->edges[0].v[1] = 1;
  this->edges[0].v[0] = 0;
  this->edges[3].v[0] = 1;
  this->edges[3].v[1] = 2;
  this->edges[6].v[0] = 1;
  this->edges[6].v[1] = 4;
  this->edges[1].v[0] = 0;
  this->edges[1].v[1] = 2;
  this->edges[4].v[0] = 2;
  this->edges[4].v[1] = 3;
  this->edges[7].v[0] = 2;
  this->edges[7].v[1] = 4;
  this->edges[2] = (traceModelEdge_t)3;
  this->edges[5].v[0] = 3;
  this->edges[5].v[1] = 1;
  this->edges[8].v[0] = 3;
  this->edges[8].v[1] = 4;
  this->numPolyEdges[0] = 3;
  this->polyEdges[0][0] = 1;
  this->polyEdges[0][1] = -125;
  this->polyEdges[0][2] = 0x80;
  this->numPolyEdges[1] = 3;
  this->polyEdges[1][0] = 2;
  this->polyEdges[1][1] = -124;
  this->polyEdges[1][2] = -127;
  this->numPolyEdges[2] = 3;
  *(_WORD *)&this->polyEdges[2][0] = 133;
  this->polyEdges[2][2] = -126;
  this->numPolyEdges[3] = 3;
  this->polyEdges[3][0] = 3;
  this->polyEdges[3][1] = 7;
  this->polyEdges[3][2] = -122;
  this->numPolyEdges[4] = 3;
  this->polyEdges[4][0] = 4;
  this->polyEdges[4][1] = 8;
  this->polyEdges[4][2] = -121;
  this->numPolyEdges[5] = 3;
  this->polyEdges[5][0] = 5;
  this->polyEdges[5][1] = 6;
  this->polyEdges[5][2] = -120;
  this->isConvex = true;
  idTraceModel::ClearUnused(this);
}


// ========================================================================
// ?GenerateEdgeNormals@idTraceModel@@QAAHXZ
// EA  : 0x82F25FE0
// RVA : 0x00F25FE0
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

int __fastcall idTraceModel::GenerateEdgeNormals(idTraceModel *this)
{
  double v2; // fp12
  double v3; // fp11
  unsigned int v4; // r7
  double v5; // fp10
  float *v6; // r10
  int v7; // r5
  int v8; // r4
  int v9; // r3
  int v10; // r31
  int v11; // r5
  int v12; // r4
  double v13; // fp6
  int v14; // r3
  int v15; // r9
  double v16; // fp3
  double v17; // fp2
  double v18; // fp1
  double v21; // fp8
  double v22; // fp6
  int result; // r3
  unsigned int v24; // r9
  _DWORD *v25; // r8
  float *v26; // r10
  unsigned int numPolys; // r31
  unsigned __int8 *v28; // r6
  unsigned int *numPolyEdges; // r5
  unsigned int v30; // r4
  int v31; // r10
  unsigned int v32; // ctr
  int v33; // r8
  unsigned int v34; // r28
  unsigned __int8 *v35; // r31
  float *polyPlaneY; // r30
  double v37; // fp0
  double v38; // fp13
  unsigned int v39; // r7
  double i; // fp12
  int v41; // r9
  int v42; // r6
  int v43; // r5
  int v44; // r4
  traceModelEdge_t *v45; // r8
  unsigned int v46; // r10
  int v47; // r9
  int v48; // r10
  int v49; // r26
  int v50; // r25
  double v51; // fp10
  int v52; // r8
  int v53; // r10
  int v54; // r9
  double v55; // fp9
  double v56; // fp1
  double v57; // fp10
  double v60; // fp8
  double v61; // fp8
  double v62; // fp8
  double v63; // fp8
  double v64; // fp10
  double v65; // fp1
  double v66; // fp9
  double v67; // fp8
  double v68; // fp10
  double v70; // fp30
  double v72; // fp10
  double v73; // fp11
  double v74; // fp10
  double v75; // fp9
  int v76; // r10
  int v77; // r9
  int v78; // r26
  int v79; // r25
  int v80; // r24
  int v81; // r8
  double v82; // fp30
  double v83; // fp28
  double v84; // fp26
  double v85; // fp9
  double v86; // fp8
  double v87; // fp1
  double v88; // fp10
  _BYTE v89[204]; // [sp+0h] [-114h] BYREF

  if ( this->type == TRM_POLYGON )
  {
    v2 = this->polyPlaneX[0];
    v3 = this->polyPlaneY[0];
    v4 = 0;
    v5 = this->polyPlaneZ[0];
    if ( this->numEdges != 0 )
    {
      v6 = &this->edgeNormalY[31];
      do
      {
        v7 = *((unsigned __int16 *)v6 + 355);
        v8 = *((unsigned __int16 *)v6 + 354);
        ++v4;
        v9 = v7 + 64;
        v10 = v8 + 64;
        v11 = __ROL4__(v7, 2);
        v12 = __ROL4__(v8, 2);
        v13 = (float)(this->vertsX[v10] - this->vertsX[v9]);
        v15 = *((unsigned __int16 *)v6 + 354) + 32;
        v16 = (float)((float)((float)v5
                            * (float)(*(float *)((char *)this->vertsX + v12) - *(float *)((char *)this->vertsX + v11)))
                    - (float)((float)(this->vertsX[v10] - this->vertsX[v9]) * (float)v2));
        v14 = *((unsigned __int16 *)v6 + 355) + 32;
        v17 = (float)((float)((float)(this->vertsX[v15] - this->vertsX[v14]) * (float)v2)
                    - (float)((float)v3
                            * (float)(*(float *)((char *)this->vertsX + v12) - *(float *)((char *)this->vertsX + v11))));
        v18 = (float)((float)((float)v13 * (float)v3)
                    - (float)((float)(this->vertsX[v15] - this->vertsX[v14]) * (float)v5));
        _FP5 = (float)((float)((float)((float)v18 * (float)v18)
                             + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f13, f5, f6, f13 }
        v21 = __frsqrte(_FP13);
        v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                            * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                    * (float)v21)
                                                                            - (float)1.5)
                                                            * (float)v21)
                                                    * (float)((float)((float)((float)v18 * (float)v18)
                                                                    + (float)((float)((float)v17 * (float)v17)
                                                                            + (float)((float)v16 * (float)v16)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v21
                                                                                    * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                                                                                            * (float)0.5))
                                                                            * (float)v21)
                                                                    - (float)1.5)
                                                    * (float)v21))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v21
                                                            * (float)((float)((float)((float)v18 * (float)v18)
                                                                            + (float)((float)((float)v17 * (float)v17)
                                                                                    + (float)((float)v16 * (float)v16)))
                                                                    * (float)0.5))
                                                    * (float)v21)
                                            - (float)1.5)
                            * (float)v21));
        *(v6 - 63) = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21)
                                                                                           - (float)1.5)
                                                                           * (float)v21))
                                                           * (float)((float)((float)((float)v18 * (float)v18)
                                                                           + (float)((float)((float)v17 * (float)v17)
                                                                                   + (float)((float)v16 * (float)v16)))
                                                                   * (float)0.5))
                                                   * (float)v22)
                                           - (float)1.5)
                           * (float)v22)
                   * (float)v18;
        *(v6 - 31) = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21)
                                                                                           - (float)1.5)
                                                                           * (float)v21))
                                                           * (float)((float)((float)((float)v18 * (float)v18)
                                                                           + (float)((float)((float)v17 * (float)v17)
                                                                                   + (float)((float)v16 * (float)v16)))
                                                                   * (float)0.5))
                                                   * (float)v22)
                                           - (float)1.5)
                           * (float)v22)
                   * (float)v16;
        *++v6 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21)
                                                                                              * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                              * (float)v21))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                              * (float)v21)
                                                                                      - (float)1.5)
                                                                      * (float)v21))
                                                      * (float)((float)((float)((float)v18 * (float)v18)
                                                                      + (float)((float)((float)v17 * (float)v17)
                                                                              + (float)((float)v16 * (float)v16)))
                                                              * (float)0.5))
                                              * (float)v22)
                                      - (float)1.5)
                      * (float)v22)
              * (float)v17;
      }
      while ( v4 < this->numEdges );
    }
    return 0;
  }
  else
  {
    v24 = 0;
    if ( this->numEdges != 0 )
    {
      v25 = v89;
      v26 = &this->edgeNormalY[31];
      do
      {
        *(v26 - 63) = 0.0;
        ++v24;
        *(v26 - 31) = 0.0;
        *++v25 = 0;
        *++v26 = 0.0;
      }
      while ( v24 < this->numEdges );
    }
    numPolys = this->numPolys;
    if ( numPolys != 0 )
    {
      v28 = this->polyEdges[0];
      numPolyEdges = this->numPolyEdges;
      v30 = this->numPolys;
      do
      {
        v31 = 0;
        if ( *numPolyEdges != 0 )
        {
          v32 = *numPolyEdges;
          do
          {
            v33 = v28[v31++];
            ++*(_DWORD *)&v89[4 * (v33 & 0xFFFFFF7F) + 4];
            --v32;
          }
          while ( v32 != 0 );
        }
        --v30;
        ++numPolyEdges;
        v28 += 16;
      }
      while ( v30 != 0 );
    }
    result = 0;
    v34 = 0;
    if ( numPolys != 0 )
    {
      v35 = this->polyEdges[0];
      polyPlaneY = this->polyPlaneY;
      do
      {
        v37 = *(polyPlaneY - 16);
        v38 = *polyPlaneY;
        v39 = 0;
        for ( i = polyPlaneY[16]; v39 < *((_DWORD *)polyPlaneY + 112); this->vertsX[v42] = v73 )
        {
          v41 = v35[v39];
          v42 = (v41 & 0x7F) + 96;
          v43 = (v41 & 0x7F) + 128;
          v44 = (v41 & 0x7F) + 160;
          v45 = &this->edges[v41 & 0x7F];
          if ( this->vertsX[v42] == 0.0 && this->vertsX[v43] == 0.0 && this->vertsX[v44] == 0.0 )
          {
            if ( *(_DWORD *)&v89[4 * (v41 & 0x7F) + 4] == 1 )
            {
              v46 = ((unsigned int)~v41 >> 6) & 2;
              v47 = *(unsigned __int16 *)((char *)v45->v + ((v35[v39] >> 6) & 2));
              v48 = *(unsigned __int16 *)((char *)v45->v + v46);
              v49 = __ROL4__(v48, 2);
              v50 = v48 + 32;
              v51 = *(float *)((char *)this->vertsX + __ROL4__(v47, 2));
              v52 = v47 + 32;
              v53 = v48 + 64;
              v54 = v47 + 64;
              v55 = (float)((float)((float)(this->vertsX[v52] - this->vertsX[v50]) * (float)v37)
                          - (float)((float)v38 * (float)((float)v51 - *(float *)((char *)this->vertsX + v49))));
              v56 = (float)((float)((float)(this->vertsX[v54] - this->vertsX[v53]) * (float)v38)
                          - (float)((float)(this->vertsX[v52] - this->vertsX[v50]) * (float)i));
              v57 = (float)((float)((float)i * (float)((float)v51 - *(float *)((char *)this->vertsX + v49)))
                          - (float)((float)(this->vertsX[v54] - this->vertsX[v53]) * (float)v37));
              _FP31 = (float)((float)((float)((float)v57 * (float)v57)
                                    + (float)((float)((float)v56 * (float)v56) + (float)((float)v55 * (float)v55)))
                            - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f8, f31, f8, f11 }
              v60 = __frsqrte(_FP8);
              v61 = (float)((float)-(float)((float)((float)((float)v60
                                                          * (float)((float)((float)((float)v57 * (float)v57)
                                                                          + (float)((float)((float)v56 * (float)v56)
                                                                                  + (float)((float)v55 * (float)v55)))
                                                                  * (float)0.5))
                                                  * (float)v60)
                                          - (float)1.5)
                          * (float)v60);
              v62 = (float)((float)-(float)((float)((float)((float)v61
                                                          * (float)((float)((float)((float)v57 * (float)v57)
                                                                          + (float)((float)((float)v56 * (float)v56)
                                                                                  + (float)((float)v55 * (float)v55)))
                                                                  * (float)0.5))
                                                  * (float)v61)
                                          - (float)1.5)
                          * (float)v61);
              v63 = (float)((float)-(float)((float)((float)((float)v62
                                                          * (float)((float)((float)((float)v57 * (float)v57)
                                                                          + (float)((float)((float)v56 * (float)v56)
                                                                                  + (float)((float)v55 * (float)v55)))
                                                                  * (float)0.5))
                                                  * (float)v62)
                                          - (float)1.5)
                          * (float)v62);
              v64 = (float)((float)v57 * (float)v63);
              v65 = (float)((float)v38 + (float)v64);
              v66 = (float)((float)i + (float)((float)v55 * (float)v63));
              v67 = (float)((float)v37
                          + (float)((float)((float)((float)(this->vertsX[v54] - this->vertsX[v53]) * (float)v38)
                                          - (float)((float)(this->vertsX[v52] - this->vertsX[v50]) * (float)i))
                                  * (float)v63));
              v68 = (float)((float)((float)v67 * (float)v67)
                          + (float)((float)((float)v66 * (float)v66)
                                  + (float)((float)((float)v38 + (float)v64) * (float)((float)v38 + (float)v64))));
              _FP31 = (float)((float)v68 - idMath::FLT_SMALLEST_NON_DENORMAL);
              v70 = (float)((float)v68 * (float)0.5);
              __asm { fsel      f11, f31, f10, f11 }
              v72 = __frsqrte(_FP11);
              v73 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5) * (float)v72) * (float)v70)
                                                                                                  * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5) * (float)v72))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72)
                                                                                                  - (float)1.5)
                                                                                  * (float)v72))
                                                                  * (float)v70)
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5) * (float)v72)
                                                                                                  * (float)v70)
                                                                                          * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5)
                                                                                                  * (float)v72))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v72 * (float)v70)
                                                                                                  * (float)v72)
                                                                                          - (float)1.5)
                                                                          * (float)v72)))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72)
                                                                                                  - (float)1.5)
                                                                                  * (float)v72)
                                                                          * (float)v70)
                                                                  * (float)((float)-(float)((float)((float)((float)v72 * (float)v70)
                                                                                                  * (float)v72)
                                                                                          - (float)1.5)
                                                                          * (float)v72))
                                                          - (float)1.5)
                                          * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72)
                                                                  - (float)1.5)
                                                  * (float)v72)))
                          * (float)v67);
              v75 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5) * (float)v72) * (float)v70)
                                                                                                  * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5) * (float)v72))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72)
                                                                                                  - (float)1.5)
                                                                                  * (float)v72))
                                                                  * (float)v70)
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5) * (float)v72)
                                                                                                  * (float)v70)
                                                                                          * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5)
                                                                                                  * (float)v72))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v72 * (float)v70)
                                                                                                  * (float)v72)
                                                                                          - (float)1.5)
                                                                          * (float)v72)))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72)
                                                                                                  - (float)1.5)
                                                                                  * (float)v72)
                                                                          * (float)v70)
                                                                  * (float)((float)-(float)((float)((float)((float)v72 * (float)v70)
                                                                                                  * (float)v72)
                                                                                          - (float)1.5)
                                                                          * (float)v72))
                                                          - (float)1.5)
                                          * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72)
                                                                  - (float)1.5)
                                                  * (float)v72)))
                          * (float)v66);
              v74 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5) * (float)v72) * (float)v70)
                                                                                                  * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5) * (float)v72))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72)
                                                                                                  - (float)1.5)
                                                                                  * (float)v72))
                                                                  * (float)v70)
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5) * (float)v72)
                                                                                                  * (float)v70)
                                                                                          * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72) - (float)1.5)
                                                                                                  * (float)v72))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v72 * (float)v70)
                                                                                                  * (float)v72)
                                                                                          - (float)1.5)
                                                                          * (float)v72)))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72)
                                                                                                  - (float)1.5)
                                                                                  * (float)v72)
                                                                          * (float)v70)
                                                                  * (float)((float)-(float)((float)((float)((float)v72 * (float)v70)
                                                                                                  * (float)v72)
                                                                                          - (float)1.5)
                                                                          * (float)v72))
                                                          - (float)1.5)
                                          * (float)((float)-(float)((float)((float)((float)v72 * (float)v70) * (float)v72)
                                                                  - (float)1.5)
                                                  * (float)v72)))
                          * (float)v65);
            }
            else
            {
              v73 = v37;
              v74 = v38;
              v75 = i;
            }
          }
          else if ( (float)((float)((float)v37 * this->vertsX[v42])
                          + (float)((float)((float)i * this->vertsX[v44]) + (float)((float)v38 * this->vertsX[v43]))) >= -0.69999999 )
          {
            v73 = (float)((float)((float)v37 + this->vertsX[v42])
                        * (float)((float)1.0
                                / (float)((float)((float)((float)v37 * this->vertsX[v42])
                                                + (float)((float)((float)i * this->vertsX[v44])
                                                        + (float)((float)v38 * this->vertsX[v43])))
                                        + (float)1.0)));
            v74 = (float)((float)((float)v38 + this->vertsX[v43])
                        * (float)((float)1.0
                                / (float)((float)((float)((float)v37 * this->vertsX[v42])
                                                + (float)((float)((float)i * this->vertsX[v44])
                                                        + (float)((float)v38 * this->vertsX[v43])))
                                        + (float)1.0)));
            v75 = (float)((float)((float)i + this->vertsX[v44])
                        * (float)((float)1.0
                                / (float)((float)((float)((float)v37 * this->vertsX[v42])
                                                + (float)((float)((float)i * this->vertsX[v44])
                                                        + (float)((float)v38 * this->vertsX[v43])))
                                        + (float)1.0)));
          }
          else
          {
            ++result;
            v76 = *(unsigned __int16 *)((char *)v45->v + ((v35[v39] >> 6) & 2));
            v77 = *(unsigned __int16 *)((char *)v45->v + (((unsigned int)~v41 >> 6) & 2));
            v78 = v77 + 64;
            v79 = __ROL4__(v76, 2);
            v80 = __ROL4__(v77, 2);
            v77 += 32;
            v81 = v76 + 32;
            v82 = -(float)(this->vertsX[v78] - this->vertsZ[v76]);
            v83 = -(float)(*(float *)((char *)this->vertsX + v80) - *(float *)((char *)this->vertsX + v79));
            v84 = -(float)(this->vertsX[v77] - this->vertsX[v81]);
            v85 = (float)((float)((float)((float)(*(float *)((char *)this->vertsX + v80)
                                                - *(float *)((char *)this->vertsX + v79))
                                        * this->vertsX[v44])
                                - (float)((float)(this->vertsX[v78] - this->vertsZ[v76]) * this->vertsX[v42]))
                        + (float)((float)((float)i * (float)v83) - (float)((float)v82 * (float)v37)));
            v87 = (float)((float)((float)((float)(this->vertsX[v78] - this->vertsZ[v76]) * this->vertsX[v43])
                                - (float)((float)(this->vertsX[v77] - this->vertsX[v81]) * this->vertsX[v44]))
                        + (float)((float)((float)v82 * (float)v38) - (float)((float)v84 * (float)i)));
            v86 = (float)((float)((float)((float)(this->vertsX[v77] - this->vertsX[v81]) * this->vertsX[v42])
                                - (float)((float)(*(float *)((char *)this->vertsX + v80)
                                                - *(float *)((char *)this->vertsX + v79))
                                        * this->vertsX[v43]))
                        + (float)((float)((float)v84 * (float)v37) - (float)((float)v38 * (float)v83)));
            v88 = __fsqrts((float)((float)((float)v87 * (float)v87)
                                 + (float)((float)((float)v86 * (float)v86) + (float)((float)v85 * (float)v85))));
            v73 = (float)((float)((float)((float)((float)(this->vertsX[v78] - this->vertsZ[v76]) * this->vertsX[v43])
                                        - (float)((float)(this->vertsX[v77] - this->vertsX[v81]) * this->vertsX[v44]))
                                + (float)((float)((float)v82 * (float)v38) - (float)((float)v84 * (float)i)))
                        * (float)((float)3.3333333 / (float)v88));
            v75 = (float)((float)((float)((float)((float)(this->vertsX[v77] - this->vertsX[v81]) * this->vertsX[v42])
                                        - (float)((float)(*(float *)((char *)this->vertsX + v80)
                                                        - *(float *)((char *)this->vertsX + v79))
                                                * this->vertsX[v43]))
                                + (float)((float)((float)v84 * (float)v37) - (float)((float)v38 * (float)v83)))
                        * (float)((float)3.3333333 / (float)v88));
            v74 = (float)((float)((float)((float)((float)(*(float *)((char *)this->vertsX + v80)
                                                        - *(float *)((char *)this->vertsX + v79))
                                                * this->vertsX[v44])
                                        - (float)((float)(this->vertsX[v78] - this->vertsZ[v76]) * this->vertsX[v42]))
                                + (float)((float)((float)i * (float)v83) - (float)((float)v82 * (float)v37)))
                        * (float)((float)3.3333333 / (float)v88));
          }
          ++v39;
          this->vertsX[v44] = v75;
          this->vertsX[v43] = v74;
        }
        ++v34;
        v35 += 16;
        ++polyPlaneY;
      }
      while ( v34 < this->numPolys );
    }
  }
  return result;
}


// ========================================================================
// ?CalculatePolygonPlanes@idTraceModel@@AAAXXZ
// EA  : 0x82F26510
// RVA : 0x00F26510
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::CalculatePolygonPlanes(idTraceModel *this)
{
  unsigned int v1; // r4
  float *v2; // r11
  char *v3; // r7
  unsigned int v4; // r6
  int v5; // r10
  int v6; // r8
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r6
  int v11; // r29
  int v12; // r9
  double v13; // fp6
  int v14; // r30
  double v15; // fp10
  double v16; // fp4
  double v17; // fp2
  double v18; // fp9
  double v19; // fp7
  double v20; // fp5
  double v23; // fp3
  double v24; // fp13
  double v25; // fp6
  double v26; // fp5

  v1 = 0;
  if ( this->numPolys != 0 )
  {
    v2 = &this->polyPlaneZ[15];
    v3 = (char *)&this->polyPlaneW[12] + 1;
    do
    {
      v4 = (unsigned __int8)v3[15];
      v3 += 16;
      ++v1;
      v5 = 2 * ((v4 & 0x7F) + 336);
      v6 = ((~(_BYTE)v4 & 0x80) != 0) + v5;
      v7 = *((unsigned __int16 *)this->vertsX + (v4 >> 7) + v5);
      v8 = this->edges[*v3 & 0x7F].v[(~*v3 & 0x80) != 0];
      v9 = *((unsigned __int16 *)this->vertsX + v6);
      v10 = __ROL4__(v7, 2);
      v11 = __ROL4__(v9, 2);
      v13 = (float)(this->vertsZ[v8] - this->vertsZ[v7]);
      v14 = v8 + 32;
      v12 = __ROL4__(v8, 2);
      v15 = *(float *)((char *)this->vertsX + v10);
      v16 = this->vertsZ[v7];
      v17 = this->vertsY[v7];
      v18 = (float)((float)((float)(this->vertsZ[v9] - this->vertsZ[v7])
                          * (float)(*(float *)((char *)this->vertsX + v12) - *(float *)((char *)this->vertsX + v10)))
                  - (float)((float)v13
                          * (float)(*(float *)((char *)this->vertsX + v11) - *(float *)((char *)this->vertsX + v10))));
      v20 = (float)((float)((float)(this->vertsX[v14] - this->vertsY[v7])
                          * (float)(*(float *)((char *)this->vertsX + v11) - *(float *)((char *)this->vertsX + v10)))
                  - (float)((float)(this->vertsY[v9] - this->vertsY[v7])
                          * (float)(*(float *)((char *)this->vertsX + v12) - *(float *)((char *)this->vertsX + v10))));
      v19 = (float)((float)((float)(this->vertsY[v9] - this->vertsY[v7]) * (float)v13)
                  - (float)((float)(this->vertsZ[v9] - this->vertsZ[v7]) * (float)(this->vertsX[v14] - this->vertsY[v7])));
      _FP11 = (float)((float)((float)((float)v20 * (float)v20)
                            + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f6, f11, f1, f13 }
      v23 = __frsqrte(_FP6);
      v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23
                                                                                          * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v23)
                                                                          - (float)1.5)
                                                          * (float)v23)
                                                  * (float)((float)((float)((float)v20 * (float)v20)
                                                                  + (float)((float)((float)v19 * (float)v19)
                                                                          + (float)((float)v18 * (float)v18)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v23
                                                                                  * (float)((float)((float)((float)v20 * (float)v20)
                                                                                                  + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)))
                                                                                          * (float)0.5))
                                                                          * (float)v23)
                                                                  - (float)1.5)
                                                  * (float)v23))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v23
                                                          * (float)((float)((float)((float)v20 * (float)v20)
                                                                          + (float)((float)((float)v19 * (float)v19)
                                                                                  + (float)((float)v18 * (float)v18)))
                                                                  * (float)0.5))
                                                  * (float)v23)
                                          - (float)1.5)
                          * (float)v23));
      v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) * (float)0.5)) * (float)v23) - (float)1.5)
                                                                                                  * (float)v23)
                                                                                          * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) * (float)0.5)) * (float)v23) - (float)1.5)
                                                                                          * (float)v23))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v23
                                                                                                  * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) * (float)0.5))
                                                                                          * (float)v23)
                                                                                  - (float)1.5)
                                                                  * (float)v23))
                                                  * (float)((float)((float)((float)v20 * (float)v20)
                                                                  + (float)((float)((float)v19 * (float)v19)
                                                                          + (float)((float)v18 * (float)v18)))
                                                          * (float)0.5))
                                          * (float)v24)
                                  - (float)1.5)
                  * (float)v24);
      v26 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23)
                                                                                                  * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) * (float)0.5)) * (float)v23) - (float)1.5)
                                                                                                  * (float)v23))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) * (float)0.5))
                                                                                                  * (float)v23)
                                                                                          - (float)1.5)
                                                                          * (float)v23))
                                                          * (float)((float)((float)((float)v20 * (float)v20)
                                                                          + (float)((float)((float)v19 * (float)v19)
                                                                                  + (float)((float)v18 * (float)v18)))
                                                                  * (float)0.5))
                                                  * (float)v24)
                                          - (float)1.5)
                          * (float)v24)
                  * (float)v20);
      *(v2 - 15) = v26;
      *(v2 - 31) = (float)v25 * (float)v18;
      *(v2 - 47) = (float)v25 * (float)v19;
      *++v2 = -(float)((float)((float)v15 * (float)((float)v25 * (float)v19))
                     + (float)((float)((float)v17 * (float)((float)v25 * (float)v18)) + (float)((float)v16 * (float)v26)));
    }
    while ( v1 < this->numPolys );
  }
}


// ========================================================================
// ?CalculateInsetSphereRadius@idTraceModel@@QAAXXZ
// EA  : 0x82F266C0
// RVA : 0x00F266C0
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::CalculateInsetSphereRadius(idTraceModel *this)
{
  double v1; // fp13
  double v2; // fp12
  double v3; // fp0
  double v4; // fp11
  double v5; // fp12
  double v6; // fp0
  double v7; // fp13

  v1 = __fabs(this->bounds.b[0].y);
  v2 = __fabs(this->bounds.b[0].x);
  v3 = __fabs(this->bounds.b[0].z);
  if ( v2 >= v1 )
  {
    if ( v1 < v3 )
    {
      v4 = v1;
      goto LABEL_7;
    }
  }
  else if ( v2 < v3 )
  {
    v4 = v2;
    goto LABEL_7;
  }
  v4 = v3;
LABEL_7:
  v5 = __fabs(this->bounds.b[1].x);
  v6 = __fabs(this->bounds.b[1].y);
  v7 = __fabs(this->bounds.b[1].z);
  if ( v5 < v6 )
  {
    if ( v5 < v7 )
    {
      _FP13 = (float)((float)v4 - (float)v5);
      __asm { fsel      f12, f13, f12, f11 }
      this->radius = _FP12;
      return;
    }
    goto LABEL_11;
  }
  if ( v6 >= v7 )
LABEL_11:
    v6 = v7;
  _FP13 = (float)((float)v4 - (float)v6);
  __asm { fsel      f12, f13, f0, f11 }
  this->radius = _FP12;
}


// ========================================================================
// ?TestConvexity@idTraceModel@@QAAXXZ
// EA  : 0x82F26760
// RVA : 0x00F26760
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::TestConvexity(idTraceModel *this)
{
  unsigned int numPolys; // r11
  unsigned int v2; // r7
  unsigned int numVerts; // r8
  float *polyPlaneY; // r9
  unsigned int v5; // r10
  float *vertsZ; // r11

  numPolys = this->numPolys;
  v2 = 0;
  this->isConvex = true;
  if ( numPolys != 0 )
  {
    numVerts = this->numVerts;
    polyPlaneY = this->polyPlaneY;
    do
    {
      v5 = 0;
      if ( numVerts != 0 )
      {
        vertsZ = this->vertsZ;
        while ( (float)((float)((float)(*(vertsZ - 32) * *polyPlaneY)
                              + (float)((float)(*(vertsZ - 64) * *(polyPlaneY - 16)) + (float)(*vertsZ * polyPlaneY[16])))
                      + polyPlaneY[32]) <= 0.0099999998 )
        {
          ++v5;
          ++vertsZ;
          if ( v5 >= this->numVerts )
            goto LABEL_9;
        }
        this->isConvex = false;
LABEL_9:
        if ( v5 < numVerts )
          break;
      }
      ++v2;
      ++polyPlaneY;
    }
    while ( v2 < this->numPolys );
  }
}


// ========================================================================
// ?Translate@idTraceModel@@QAAXABVidVec3@@@Z
// EA  : 0x82F26810
// RVA : 0x00F26810
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::Translate(idTraceModel *this, const idVec3 *translation)
{
  unsigned int v2; // r10
  float *v3; // r11
  double v4; // fp11
  double v5; // fp8
  unsigned int v6; // r10
  float *v7; // r11
  double v8; // fp4
  double y; // fp5
  double z; // fp4
  double v11; // fp10
  double v12; // fp9

  v2 = 0;
  if ( this->numVerts != 0 )
  {
    v3 = &this->vertsY[31];
    do
    {
      ++v2;
      v4 = *(v3 - 31);
      *(v3 - 63) = translation->x + *(v3 - 63);
      v5 = v3[1];
      *(v3 - 31) = translation->y + (float)v4;
      *++v3 = translation->z + (float)v5;
    }
    while ( v2 < this->numVerts );
  }
  v6 = 0;
  if ( this->numPolys != 0 )
  {
    v7 = &this->polyPlaneZ[15];
    do
    {
      ++v6;
      v8 = (float)(v7[1]
                 - (float)((float)(translation->x * *(v7 - 47))
                         + (float)((float)(translation->z * *(v7 - 15)) + (float)(translation->y * *(v7 - 31)))));
      *++v7 = v8;
    }
    while ( v6 < this->numPolys );
  }
  this->offset.x = this->offset.x + translation->x;
  this->offset.y = this->offset.y + translation->y;
  this->offset.z = translation->z + this->offset.z;
  y = this->bounds.b[0].y;
  z = this->bounds.b[0].z;
  this->bounds.b[0].x = translation->x + this->bounds.b[0].x;
  this->bounds.b[0].y = (float)y + translation->y;
  this->bounds.b[0].z = (float)z + translation->z;
  v11 = this->bounds.b[1].y;
  v12 = this->bounds.b[1].z;
  this->bounds.b[1].x = translation->x + this->bounds.b[1].x;
  this->bounds.b[1].y = (float)v11 + translation->y;
  this->bounds.b[1].z = (float)v12 + translation->z;
}


// ========================================================================
// ?Rotate@idTraceModel@@QAAXABVidMat3@@@Z
// EA  : 0x82F26958
// RVA : 0x00F26958
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::Rotate(idTraceModel *this, const idMat3 *rotation)
{
  idBounds *p_bounds; // r11
  unsigned int v3; // r9
  float *v4; // r10
  double v5; // fp3
  double y; // fp1
  double z; // fp12
  double v8; // fp10
  double v9; // fp9
  double v10; // fp8
  double v11; // fp6
  idTraceModel *v24; // r3
  idTraceModel *v25; // r3

  p_bounds = &this->bounds;
  v3 = 0;
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  if ( this->numVerts != 0 )
  {
    v4 = &this->vertsY[31];
    do
    {
      ++v3;
      v5 = *(v4 - 63);
      y = rotation->mat[0].y;
      z = rotation->mat[0].z;
      v8 = (float)((float)(rotation->mat[1].y * *(v4 - 31)) + (float)(v4[1] * rotation->mat[2].y));
      v9 = (float)((float)(rotation->mat[1].z * *(v4 - 31)) + (float)(rotation->mat[2].z * v4[1]));
      v10 = (float)((float)(rotation->mat[0].x * *(v4 - 63))
                  + (float)((float)(rotation->mat[2].x * v4[1]) + (float)(rotation->mat[1].x * *(v4 - 31))));
      *(v4 - 63) = (float)(rotation->mat[0].x * *(v4 - 63))
                 + (float)((float)(rotation->mat[2].x * v4[1]) + (float)(rotation->mat[1].x * *(v4 - 31)));
      *(v4 - 31) = (float)((float)v5 * (float)y) + (float)v8;
      v11 = (float)((float)((float)z * (float)v5) + (float)v9);
      *++v4 = (float)((float)z * (float)v5) + (float)v9;
      _FP13 = (float)(this->bounds.b[0].y - (float)((float)((float)v5 * (float)y) + (float)v8));
      _FP11 = (float)(this->bounds.b[0].z - (float)((float)((float)z * (float)v5) + (float)v9));
      _FP12 = (float)(p_bounds->b[0].x - (float)v10);
      _FP9 = (float)((float)((float)((float)v5 * (float)y) + (float)v8) - this->bounds.b[1].y);
      _FP10 = (float)((float)v10 - this->bounds.b[1].x);
      _FP31 = (float)((float)v11 - this->bounds.b[1].z);
      __asm { fsel      f0, f13, f7, f0 }
      this->bounds.b[0].y = _FP0;
      __asm { fsel      f13, f12, f8, f1 }
      p_bounds->b[0].x = _FP13;
      __asm { fsel      f12, f11, f6, f5 }
      this->bounds.b[0].z = _FP12;
      __asm { fsel      f11, f10, f8, f4 }
      this->bounds.b[1].x = _FP11;
      __asm { fsel      f10, f9, f7, f3 }
      this->bounds.b[1].y = _FP10;
      __asm { fsel      f9, f31, f6, f2 }
      this->bounds.b[1].z = _FP9;
    }
    while ( v3 < this->numVerts );
  }
  idTraceModel::CalculateInsetSphereRadius(this);
  idTraceModel::CalculatePolygonPlanes(this: v24);
  idTraceModel::GenerateEdgeNormals(this: v25);
}


// ========================================================================
// ?Scale@idTraceModel@@QAAXABVidVec3@@@Z
// EA  : 0x82F26AA0
// RVA : 0x00F26AA0
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::Scale(idTraceModel *this, const idVec3 *scale)
{
  idBounds *p_bounds; // r11
  unsigned int v3; // r9
  float *v4; // r10
  double v5; // fp12
  double v6; // fp6
  idTraceModel *v19; // r3
  idTraceModel *v20; // r3

  p_bounds = &this->bounds;
  v3 = 0;
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  if ( this->numVerts != 0 )
  {
    v4 = &this->vertsX[31];
    do
    {
      ++v3;
      v5 = (float)(*(v4 - 31) * scale->x);
      *(v4 - 31) = *(v4 - 31) * scale->x;
      v4[1] = scale->y * v4[1];
      v6 = (float)(v4[33] * scale->z);
      v4[33] = v4[33] * scale->z;
      _FP10 = (float)(this->bounds.b[0].y - *++v4);
      _FP8 = (float)(p_bounds->b[0].x - (float)v5);
      _FP7 = (float)((float)v5 - this->bounds.b[1].x);
      _FP12 = (float)(this->bounds.b[0].z - (float)v6);
      _FP31 = (float)((float)v6 - this->bounds.b[1].z);
      _FP6 = (float)(*v4 - this->bounds.b[1].y);
      __asm { fsel      f13, f12, f4, f13 }
      this->bounds.b[0].z = _FP13;
      __asm { fsel      f1, f10, f0, f1 }
      this->bounds.b[0].y = _FP1;
      __asm { fsel      f12, f8, f5, f11 }
      p_bounds->b[0].x = _FP12;
      __asm { fsel      f11, f7, f5, f3 }
      this->bounds.b[1].x = _FP11;
      __asm { fsel      f10, f6, f0, f2 }
      this->bounds.b[1].y = _FP10;
      __asm { fsel      f9, f31, f4, f9 }
      this->bounds.b[1].z = _FP9;
    }
    while ( v3 < this->numVerts );
  }
  idTraceModel::CalculateInsetSphereRadius(this);
  idTraceModel::CalculatePolygonPlanes(this: v19);
  idTraceModel::GenerateEdgeNormals(this: v20);
}


// ========================================================================
// ?Compare@idTraceModel@@QBA_NABV1@@Z
// EA  : 0x82F26BC8
// RVA : 0x00F26BC8
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

int __fastcall idTraceModel::Compare(idTraceModel *this, const idTraceModel *trm)
{
  traceModel_t type; // r29
  unsigned int numVerts; // r28
  char v6; // r11
  unsigned int v7; // r9
  idTraceModel *v8; // r10
  float *i; // r11

  type = this->type;
  if ( type == trm->type )
  {
    numVerts = trm->numVerts;
    if ( this->numVerts == numVerts
      && this->numEdges == trm->numEdges
      && this->numPolys == trm->numPolys
      && (unsigned __int8)idBounds::Compare(this: &this->bounds, a: &trm->bounds) != 0 )
    {
      if ( this->offset.x != trm->offset.x
        || this->offset.y != trm->offset.y
        || (v6 = 1, this->offset.z != trm->offset.z) )
      {
        v6 = 0;
      }
      if ( v6 != 0 )
      {
        if ( type < TRM_BONE )
          return 1;
        if ( type > TRM_CUSTOM )
          return 1;
        v7 = 0;
        if ( numVerts == 0 )
          return 1;
        v8 = this;
        for ( i = trm->vertsY;
              v8->vertsX[0] == *(i - 32)
           && *(float *)((char *)i + (char *)this - (char *)trm) == *i
           && v8->vertsZ[0] == i[32];
              ++i )
        {
          ++v7;
          v8 = (idTraceModel *)((char *)v8 + 4);
          if ( v7 >= numVerts )
            return 1;
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?ProjectionIntegrals@idTraceModel@@ABAXHHHAAUprojectionIntegrals_t@@@Z
// EA  : 0x82F26D00
// RVA : 0x00F26D00
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::ProjectionIntegrals(
        idTraceModel *this,
        int polyNum,
        int a,
        int b,
        projectionIntegrals_t *integrals)
{
  _DWORD *p_Pbbb; // r10
  int i; // ctr
  unsigned int v7; // r9
  int v8; // r29
  int v9; // r8
  unsigned __int8 *v10; // r4
  int v11; // r6
  unsigned int v12; // r10
  float *v13; // r28
  float *v14; // r27
  double P1; // fp11
  double Pb; // fp8
  double Pbb; // fp7
  double Pa; // fp10
  double Paa; // fp9
  int v20; // r11
  double Paaa; // fp6
  double Pbbb; // fp5
  int v23; // r5
  int v24; // r11
  int v25; // r10
  double v26; // fp2
  double v27; // fp1
  double v28; // fp30
  double v29; // fp1
  double v30; // fp3
  double v31; // fp2
  double v32; // fp4
  double v33; // fp25
  double v34; // fp30
  double v35; // fp29
  double v36; // fp24
  double v37; // fp23
  double v38; // fp31
  double v39; // fp21
  double v40; // fp19
  double v41; // fp20
  double v42; // fp27
  double v43; // fp26
  double v44; // fp22
  double v45; // fp9
  double v46; // fp10
  double Pab; // fp31
  double v48; // fp7
  double Paab; // fp28
  double v50; // fp11
  double v51; // fp27
  double v52; // fp30
  double Pabb; // fp29
  double v54; // fp21
  double v55; // fp8
  double v56; // fp2
  double v57; // fp4
  double v58; // fp8
  double v59; // fp1
  double v60; // fp0
  double v61; // fp13
  double v62; // fp6
  double v63; // fp3
  double v64; // fp12
  float v65[4]; // [sp+0h] [-E0h] BYREF
  float v66[34]; // [sp+10h] [-D0h] BYREF

  p_Pbbb = (_DWORD *)&integrals[-1].Pbbb;
  for ( i = 10; i != 0; --i )
    *++p_Pbbb = 0;
  v7 = 0;
  v8 = polyNum + 320;
  if ( LODWORD(this->vertsX[v8]) != 0 )
  {
    v9 = a;
    v10 = this->polyEdges[polyNum];
    v11 = b;
    do
    {
      v12 = v10[v7];
      v13 = v65;
      v14 = v65;
      P1 = integrals->P1;
      Pb = integrals->Pb;
      Pbb = integrals->Pbb;
      Pa = integrals->Pa;
      Paa = integrals->Paa;
      v20 = 2 * ((v12 & 0x7F) + 336);
      Paaa = integrals->Paaa;
      Pbbb = integrals->Pbbb;
      v23 = ((~(_BYTE)v12 & 0x80) != 0) + v20;
      v24 = *((unsigned __int16 *)this->vertsX + (v12 >> 7) + v20);
      v25 = *((unsigned __int16 *)this->vertsX + v23);
      v26 = this->vertsZ[v24];
      v27 = *(float *)((char *)this->vertsX + __ROL4__(v25, 2));
      v28 = this->vertsZ[v25];
      v66[1] = this->vertsY[v25];
      v66[2] = v28;
      v65[2] = v26;
      v66[0] = v27;
      v29 = v66[v11];
      v30 = v65[v9];
      v31 = v65[v11];
      v32 = v66[v9];
      v33 = (float)(v66[v9] * v66[v9]);
      v34 = (float)(v13[v9] * v13[v9]);
      v35 = (float)(v14[v11] * v14[v11]);
      v36 = (float)(v66[v11] - v65[v11]);
      v37 = (float)(v66[v9] - v65[v9]);
      v38 = (float)(v66[v11] * v66[v11]);
      v39 = (float)((float)(v13[v9] * v13[v9]) * v13[v9]);
      v40 = (float)((float)((float)(v66[v9] + v13[v9]) * v66[v9]) + (float)(v13[v9] * v13[v9]));
      v41 = (float)((float)(v14[v11] * v14[v11]) * v14[v11]);
      v42 = (float)((float)((float)(v66[v11] + v14[v11]) * v66[v11]) + (float)(v14[v11] * v14[v11]));
      v43 = (float)((float)(v66[v9] * v65[v9]) * (float)2.0);
      integrals->P1 = (float)((float)(v66[v9] + v65[v9]) * (float)(v66[v11] - v65[v11])) + (float)P1;
      v44 = (float)((float)v38 * (float)v29);
      integrals->Pa = (float)((float)v40 * (float)v36) + (float)Pa;
      integrals->Pb = (float)((float)v42 * (float)v37) + (float)Pb;
      integrals->Paa = (float)((float)((float)((float)v40 * (float)v32) + (float)v39) * (float)v36) + (float)Paa;
      integrals->Pbb = (float)((float)((float)((float)v42 * (float)v29) + (float)v41) * (float)v37) + (float)Pbb;
      v45 = (float)((float)((float)((float)v33 * (float)3.0) + (float)v43) + (float)v34);
      v46 = (float)((float)((float)((float)v34 * (float)3.0) + (float)v43) + (float)v33);
      v48 = (float)((float)((float)v39 * (float)v30)
                  + (float)((float)((float)((float)v40 * (float)v32) + (float)v39) * (float)v32));
      Paab = integrals->Paab;
      v50 = (float)((float)((float)v41 * (float)v31)
                  + (float)((float)((float)((float)v42 * (float)v29) + (float)v41) * (float)v29));
      ++v7;
      v51 = (float)((float)v39 * (float)4.0);
      v52 = (float)((float)v35 * (float)v29);
      Pabb = integrals->Pabb;
      v54 = (float)((float)((float)v38 * (float)v31) * (float)3.0);
      v55 = (float)((float)((float)v38 * (float)v31) * (float)2.0);
      Pab = integrals->Pab;
      integrals->Paaa = (float)((float)v48 * (float)v36) + (float)Paaa;
      integrals->Pbbb = (float)((float)v50 * (float)v37) + (float)Pbbb;
      integrals->Pab = (float)((float)((float)((float)v45 * (float)v29) + (float)((float)v46 * (float)v31)) * (float)v36)
                     + (float)Pab;
      integrals->Paab = (float)((float)((float)((float)((float)((float)((float)v33 * (float)v32) * (float)4.0)
                                                      + (float)((float)v45 * (float)v30))
                                              * (float)v29)
                                      + (float)((float)((float)((float)v46 * (float)v32) + (float)v51) * (float)v31))
                              * (float)v36)
                      + (float)Paab;
      integrals->Pabb = (float)((float)((float)((float)((float)((float)((float)v41 * (float)4.0)
                                                              + (float)((float)((float)v52 * (float)3.0) + (float)v55))
                                                      + (float)v44)
                                              * (float)v30)
                                      + (float)((float)((float)((float)((float)v44 * (float)4.0)
                                                              + (float)((float)((float)v52 * (float)2.0) + (float)v54))
                                                      + (float)v41)
                                              * (float)v32))
                              * (float)v37)
                      + (float)Pabb;
    }
    while ( v7 < LODWORD(this->vertsX[v8]) );
  }
  v56 = (float)(integrals->Paa * (float)0.083333336);
  v57 = (float)(integrals->Pa * (float)0.16666667);
  v58 = (float)(integrals->Paaa * (float)0.050000001);
  v59 = (float)(integrals->Pbbb * (float)-0.050000001);
  v60 = (float)(integrals->Pab * (float)0.041666668);
  v61 = (float)(integrals->Paab * (float)0.016666668);
  v62 = (float)(integrals->Pb * (float)-0.16666667);
  v63 = (float)(integrals->Pbb * (float)-0.083333336);
  v64 = (float)(integrals->Pabb * (float)-0.016666668);
  integrals->P1 = integrals->P1 * (float)0.5;
  integrals->Pa = v57;
  integrals->Paa = v56;
  integrals->Paaa = v58;
  integrals->Pb = v62;
  integrals->Pbb = v63;
  integrals->Pbbb = v59;
  integrals->Pab = v60;
  integrals->Paab = v61;
  integrals->Pabb = v64;
}


// ========================================================================
// ?PolygonIntegrals@idTraceModel@@ABAXHHHHAAUpolygonIntegrals_t@@@Z
// EA  : 0x82F27030
// RVA : 0x00F27030
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::PolygonIntegrals(
        idTraceModel *this,
        int polyNum,
        int a,
        int b,
        int c,
        polygonIntegrals_t *integrals)
{
  double Pa; // fp10
  double Paa; // fp11
  double Pab; // fp5
  double Pbb; // fp12
  double Paaa; // fp9
  double Pbbb; // fp7
  float *v18; // r4
  double v19; // fp13
  double v20; // fp8
  double v21; // fp4
  int v22; // r6
  double v23; // fp2
  double v24; // fp3
  double v25; // fp31
  double v26; // fp26
  double v27; // fp29
  double v28; // fp1
  double Pabb; // fp8
  double v30; // fp30
  double v31; // fp24
  double v32; // fp27
  double v33; // fp21
  double v34; // fp27
  double v35; // fp25
  double v36; // fp16
  double v37; // fp30
  double v38; // fp11
  double v39; // fp22
  double v40; // fp5
  double v41; // fp8
  double v42; // fp4
  double v43; // fp28
  float v44[4]; // [sp+50h] [-F0h] BYREF
  projectionIntegrals_t v45; // [sp+60h] [-E0h] BYREF

  idTraceModel::ProjectionIntegrals(this, polyNum, a, b, integrals: &v45);
  Pa = v45.Pa;
  Paa = v45.Paa;
  Pab = v45.Pab;
  Pbb = v45.Pbb;
  Paaa = v45.Paaa;
  Pbbb = v45.Pbbb;
  v18 = v44;
  v19 = this->polyPlaneY[polyNum];
  v20 = this->polyPlaneZ[polyNum];
  v44[0] = this->polyPlaneX[polyNum];
  v44[1] = v19;
  v44[2] = v20;
  v21 = v44[a];
  v22 = polyNum + 240;
  v23 = v44[b];
  v24 = (float)((float)1.0 / v44[c]);
  v25 = this->vertsX[v22];
  v26 = (float)(v44[a] * v44[b]);
  v27 = (float)(v45.P1 * this->vertsX[v22]);
  v28 = (float)((float)(v44[a] * v45.Pa) + (float)(v44[b] * v45.Pb));
  Pabb = v45.Pabb;
  v30 = (float)(v44[b] * v44[b]);
  v31 = (float)(v18[a] * v18[a]);
  v32 = (float)((float)(v18[a] * v18[a]) * v45.Paa);
  integrals->Fb = v45.Pb * (float)((float)1.0 / v44[c]);
  integrals->Faa = (float)Paa * (float)v24;
  integrals->Fbb = (float)Pbb * (float)v24;
  integrals->Faaa = (float)Paaa * (float)v24;
  integrals->Fbbb = (float)Pbbb * (float)v24;
  integrals->Fa = (float)Pa * (float)v24;
  v33 = (float)((float)((float)((float)v21 * (float)v23) * (float)Pab) * (float)2.0);
  v35 = (float)((float)((float)((float)v30 * (float)Pbb) + (float)v32)
              + (float)((float)((float)((float)v21 * (float)v23) * (float)Pab) * (float)2.0));
  v34 = (float)((float)((float)v26 * (float)v23) * (float)Pabb);
  v36 = (float)((float)v21 * (float)v21);
  v37 = (float)((float)((float)v31 * (float)Paa)
              + (float)((float)((float)((float)((float)v28 * (float)2.0) + (float)v27) * (float)v25)
                      + (float)((float)v30 * (float)Pbb)));
  v38 = (float)((float)((float)v21 * (float)Paa) + (float)((float)v23 * (float)Pab));
  v39 = (float)((float)((float)v23 * (float)v23) * (float)Pabb);
  v40 = (float)((float)((float)v21 * (float)v21) * (float)v21);
  v41 = (float)((float)((float)v21 * (float)Pabb) + (float)((float)v23 * (float)Pbbb));
  v43 = (float)((float)((float)((float)v23 * (float)v21) * (float)v21) * v45.Paab);
  v42 = (float)((float)((float)v21 * (float)v23) * v45.Paab);
  integrals->Faab = v45.Paab * (float)v24;
  integrals->Fc = -(float)((float)((float)v27 + (float)v28) * (float)((float)v24 * (float)v24));
  integrals->Fcc = (float)((float)v37 + (float)v33) * (float)((float)((float)v24 * (float)v24) * (float)v24);
  integrals->Fbbc = -(float)((float)((float)((float)Pbb * (float)v25) + (float)v41) * (float)((float)v24 * (float)v24));
  integrals->Fcca = (float)((float)((float)v42 * (float)2.0)
                          + (float)((float)((float)v36 * (float)Paaa)
                                  + (float)((float)((float)((float)((float)v38 * (float)2.0)
                                                          + (float)((float)Pa * (float)v25))
                                                  * (float)v25)
                                          + (float)v39)))
                  * (float)((float)((float)v24 * (float)v24) * (float)v24);
  integrals->Fccc = -(float)((float)((float)((float)((float)((float)v23 * (float)v23) * (float)v23) * (float)Pbbb)
                                   + (float)((float)((float)v40 * (float)Paaa)
                                           + (float)((float)((float)v43 * (float)3.0)
                                                   + (float)((float)((float)((float)((float)v35 * (float)3.0)
                                                                           + (float)((float)((float)((float)v28 * (float)3.0)
                                                                                           + (float)v27)
                                                                                   * (float)v25))
                                                                   * (float)v25)
                                                           + (float)((float)v34 * (float)3.0)))))
                           * (float)((float)((float)((float)v24 * (float)v24) * (float)v24) * (float)v24));
}


// ========================================================================
// ?VolumeIntegrals@idTraceModel@@ABAXAAUvolumeIntegrals_t@@@Z
// EA  : 0x82F27260
// RVA : 0x00F27260
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::VolumeIntegrals(idTraceModel *this, volumeIntegrals_t *integrals)
{
  _DWORD *p_z; // r11
  int i; // ctr
  unsigned int v6; // r27
  float *polyPlaneY; // r24
  double v8; // fp31
  double v9; // fp30
  double v10; // fp0
  double v11; // fp13
  double v12; // fp29
  double v13; // fp12
  int v14; // r29
  int v15; // r30
  int v16; // r28
  double Fc; // fp0
  double Fbb; // fp10
  double Fcc; // fp9
  double Faaa; // fp8
  double Fbbb; // fp7
  double Fccc; // fp6
  double v23; // fp5
  double Faab; // fp4
  double v25; // fp3
  double Fbbc; // fp2
  double Fcca; // fp1
  double v28; // fp0
  double y; // fp12
  double z; // fp11
  double v31; // fp6
  double v32; // fp2
  double v33; // fp12
  double v34; // fp9
  float v35[4]; // [sp+50h] [-A0h] BYREF
  polygonIntegrals_t v36; // [sp+60h] [-90h] BYREF

  p_z = (_DWORD *)&integrals[-1].TP.z;
  for ( i = 10; i != 0; --i )
    *++p_z = 0;
  v6 = 0;
  if ( this->numPolys != 0 )
  {
    polyPlaneY = this->polyPlaneY;
    do
    {
      v8 = *(polyPlaneY - 16);
      v9 = *polyPlaneY;
      v10 = __fabs(v8);
      v11 = __fabs(v9);
      v12 = polyPlaneY[16];
      v13 = __fabs(v12);
      if ( v10 <= v11 || v10 <= v13 )
      {
        v14 = 1;
        if ( v11 <= v13 )
          v14 = 2;
      }
      else
      {
        v14 = 0;
      }
      v15 = (v14 + 1) % 3;
      v16 = (v15 + 1) % 3;
      idTraceModel::PolygonIntegrals(this, polyNum: v6, a: v15, b: v16, c: v14, integrals: &v36);
      v35[0] = v8;
      v35[1] = v9;
      v35[2] = v12;
      if ( v15 != 0 )
      {
        if ( v16 != 0 )
          Fc = v36.Fc;
        else
          Fc = v36.Fb;
      }
      else
      {
        Fc = v36.Fa;
      }
      integrals->T0 = (float)((float)Fc * (float)v8) + integrals->T0;
      Fbb = v36.Fbb;
      Fcc = v36.Fcc;
      Faaa = v36.Faaa;
      Fbbb = v36.Fbbb;
      Fccc = v36.Fccc;
      v23 = v35[v15];
      Faab = v36.Faab;
      v25 = v35[v16];
      Fbbc = v36.Fbbc;
      Fcca = v36.Fcca;
      v28 = v35[v14];
      ++v6;
      *(&integrals->T1.x + v15) = (float)(v35[v15] * v36.Faa) + *(&integrals->T1.x + v15);
      *(&integrals->T1.x + v16) = (float)((float)v25 * (float)Fbb) + *(&integrals->T1.x + v16);
      *(&integrals->T1.x + v14) = (float)((float)v28 * (float)Fcc) + *(&integrals->T1.x + v14);
      *(&integrals->T2.x + v15) = (float)((float)v23 * (float)Faaa) + *(&integrals->T2.x + v15);
      *(&integrals->T2.x + v16) = (float)((float)v25 * (float)Fbbb) + *(&integrals->T2.x + v16);
      *(&integrals->T2.x + v14) = (float)((float)v28 * (float)Fccc) + *(&integrals->T2.x + v14);
      ++polyPlaneY;
      *(&integrals->TP.x + v15) = (float)((float)v23 * (float)Faab) + *(&integrals->TP.x + v15);
      *(&integrals->TP.x + v16) = (float)((float)v25 * (float)Fbbc) + *(&integrals->TP.x + v16);
      *(&integrals->TP.x + v14) = (float)((float)v28 * (float)Fcca) + *(&integrals->TP.x + v14);
    }
    while ( v6 < this->numPolys );
  }
  y = integrals->T1.y;
  z = integrals->T1.z;
  integrals->T1.x = integrals->T1.x * (float)0.5;
  integrals->T1.y = (float)y * (float)0.5;
  integrals->T1.z = (float)z * (float)0.5;
  v31 = integrals->T2.y;
  v32 = (float)(integrals->T2.z * (float)0.33333334);
  integrals->T2.x = integrals->T2.x * (float)0.33333334;
  integrals->T2.y = (float)v31 * (float)0.33333334;
  integrals->T2.z = v32;
  v33 = (float)(integrals->TP.y * (float)0.5);
  v34 = (float)(integrals->TP.z * (float)0.5);
  integrals->TP.x = integrals->TP.x * (float)0.5;
  integrals->TP.y = v33;
  integrals->TP.z = v34;
}


// ========================================================================
// ?ContainsPoint@idTraceModel@@QBA_NABVidVec3@@@Z
// EA  : 0x82F27530
// RVA : 0x00F27530
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

int __fastcall idTraceModel::ContainsPoint(idTraceModel *this, const idVec3 *point)
{
  unsigned int numPolys; // r9
  int v3; // r10
  float *i; // r11

  numPolys = this->numPolys;
  v3 = 0;
  if ( numPolys == 0 )
    return 1;
  for ( i = this->polyPlaneY;
        (float)((float)((float)(point->z * i[16]) + (float)((float)(point->x * *(i - 16)) + (float)(point->y * *i)))
              + i[32]) <= 0.0;
        ++i )
  {
    if ( ++v3 >= numPolys )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?InitBox@idTraceModel@@AAAXXZ
// EA  : 0x82F275A0
// RVA : 0x00F275A0
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::InitBox(idTraceModel *this)
{
  int v2; // r10
  _WORD *v3; // r11
  __int16 v4; // r8

  this->numEdges = 12;
  this->maxPolyEdges = 4;
  this->type = TRM_BOX;
  this->numVerts = 8;
  this->numPolys = 6;
  v2 = 4;
  v3 = (_WORD *)&this->edges[7] + 1;
  do
  {
    v4 = ((_BYTE)v2 + 1) & 3;
    *(v3 - 14) = v4;
    *(v3 - 7) = v2;
    *(v3 - 15) = v2 - 4;
    *(v3 - 6) = v4 + 4;
    v3[1] = v2 - 4;
    v3 += 2;
    *v3 = v2++;
  }
  while ( v2 - 4 < 4 );
  this->numPolyEdges[0] = 4;
  this->polyEdges[0][0] = -125;
  this->polyEdges[0][1] = -126;
  this->polyEdges[0][2] = -127;
  this->polyEdges[0][3] = 0x80;
  this->polyPlaneX[0] = 0.0;
  this->polyPlaneY[0] = 0.0;
  this->polyPlaneZ[0] = -1.0;
  this->polyPlaneW[0] = 0.0;
  this->polyEdges[1][1] = 5;
  this->polyEdges[1][2] = 6;
  this->polyEdges[1][3] = 7;
  this->numPolyEdges[1] = 4;
  this->polyEdges[1][0] = 4;
  this->polyPlaneX[1] = 0.0;
  this->polyPlaneY[1] = 0.0;
  this->polyPlaneZ[1] = 1.0;
  this->polyPlaneW[1] = 0.0;
  this->polyEdges[2][0] = 0;
  this->polyEdges[2][1] = 9;
  this->polyEdges[2][2] = -124;
  this->polyEdges[2][3] = -120;
  this->numPolyEdges[2] = 4;
  this->polyPlaneX[2] = 0.0;
  this->polyPlaneY[2] = -1.0;
  this->polyPlaneZ[2] = 0.0;
  this->polyPlaneW[2] = 0.0;
  this->numPolyEdges[3] = 4;
  this->polyEdges[3][0] = 1;
  this->polyEdges[3][1] = 10;
  this->polyEdges[3][2] = -123;
  this->polyEdges[3][3] = -119;
  this->polyPlaneX[3] = 1.0;
  this->polyPlaneY[3] = 0.0;
  this->polyPlaneZ[3] = 0.0;
  this->polyPlaneW[3] = 0.0;
  this->numPolyEdges[4] = 4;
  this->polyEdges[4][0] = 2;
  this->polyEdges[4][1] = 11;
  this->polyEdges[4][2] = -122;
  this->polyEdges[4][3] = -118;
  this->polyPlaneX[4] = 0.0;
  this->polyPlaneY[4] = 1.0;
  this->polyPlaneZ[4] = 0.0;
  this->polyPlaneW[4] = 0.0;
  this->numPolyEdges[5] = 4;
  this->polyEdges[5][0] = 3;
  this->polyEdges[5][1] = 8;
  this->polyEdges[5][2] = -121;
  this->polyEdges[5][3] = -117;
  this->polyPlaneX[5] = -1.0;
  this->polyPlaneY[5] = 0.0;
  this->polyPlaneZ[5] = 0.0;
  this->polyPlaneW[5] = 0.0;
  this->isConvex = true;
  idTraceModel::GenerateEdgeNormals(this);
  idTraceModel::ClearUnused(this);
}


// ========================================================================
// ?SetupOctahedron@idTraceModel@@QAAXABVidBounds@@@Z
// EA  : 0x82F27788
// RVA : 0x00F27788
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::SetupOctahedron(idTraceModel *this, const idBounds *octBounds)
{
  unsigned int v4; // r6
  double v5; // fp8
  double v6; // fp6
  double v7; // fp5
  double y; // fp7
  double x; // fp13
  double v10; // fp0
  double z; // fp11
  double v12; // fp6
  double v13; // fp4
  double v14; // fp8
  float *v15; // r11
  char *v16; // r7
  unsigned int v17; // r5
  int v18; // r10
  int v19; // r8
  int v20; // r10
  int v21; // r9
  int v22; // r8
  int v23; // r5
  int v24; // r27
  int v25; // r28
  double v26; // fp10
  double v27; // fp7
  double v28; // fp4
  double v29; // fp2
  double v30; // fp9
  double v31; // fp7
  double v32; // fp5
  double v35; // fp3
  double v36; // fp13
  double v37; // fp6
  double v38; // fp5
  idTraceModel *v39; // r3

  if ( this->type != TRM_OCTAHEDRON )
    idTraceModel::InitOctahedron(this);
  v4 = 0;
  v5 = (float)(octBounds->b[1].y + octBounds->b[0].y);
  v6 = (float)(octBounds->b[0].z + octBounds->b[1].z);
  v7 = (float)((float)(octBounds->b[0].x + octBounds->b[1].x) * (float)0.5);
  this->offset.x = (float)(octBounds->b[0].x + octBounds->b[1].x) * (float)0.5;
  this->offset.y = (float)v5 * (float)0.5;
  this->offset.z = (float)v6 * (float)0.5;
  y = this->offset.y;
  x = octBounds->b[1].x;
  v10 = octBounds->b[1].y;
  z = octBounds->b[1].z;
  this->vertsZ[0] = (float)v6 * (float)0.5;
  this->vertsY[0] = (float)v5 * (float)0.5;
  v12 = this->offset.z;
  this->vertsX[0] = (float)v7 + (float)((float)x - (float)v7);
  v13 = this->offset.x;
  this->vertsZ[1] = v12;
  this->vertsX[1] = (float)v13 - (float)((float)x - (float)v7);
  this->vertsY[1] = y;
  v14 = this->offset.x;
  this->vertsZ[2] = v12;
  this->vertsY[2] = (float)y + (float)((float)v10 - (float)y);
  this->vertsX[2] = v14;
  this->vertsX[3] = this->offset.x;
  this->vertsZ[3] = v12;
  this->vertsY[3] = (float)y - (float)((float)v10 - (float)y);
  this->vertsX[4] = this->offset.x;
  this->vertsY[4] = y;
  this->vertsZ[4] = (float)v12 + (float)((float)z - (float)v12);
  this->vertsX[5] = this->offset.x;
  this->vertsY[5] = y;
  this->vertsZ[5] = (float)v12 - (float)((float)z - (float)v12);
  if ( this->numPolys != 0 )
  {
    v15 = &this->polyPlaneZ[15];
    v16 = (char *)&this->polyPlaneW[12] + 1;
    do
    {
      v17 = (unsigned __int8)v16[15];
      v16 += 16;
      ++v4;
      v18 = 2 * ((v17 & 0x7F) + 336);
      v19 = ((~(_BYTE)v17 & 0x80) != 0) + v18;
      v20 = *((unsigned __int16 *)this->vertsX + (v17 >> 7) + v18);
      v21 = this->edges[*v16 & 0x7F].v[(~*v16 & 0x80) != 0];
      v22 = *((unsigned __int16 *)this->vertsX + v19);
      v23 = __ROL4__(v20, 2);
      v24 = __ROL4__(v22, 2);
      v25 = v21 + 32;
      v26 = *(float *)((char *)this->vertsX + v23);
      v27 = (float)(*(float *)((char *)this->vertsX + __ROL4__(v21, 2)) - *(float *)((char *)this->vertsX + v23));
      v28 = this->vertsZ[v20];
      v29 = this->vertsY[v20];
      v30 = (float)((float)((float)(this->vertsZ[v22] - this->vertsZ[v20]) * (float)v27)
                  - (float)((float)(this->vertsZ[v21] - this->vertsZ[v20])
                          * (float)(*(float *)((char *)this->vertsX + v24) - *(float *)((char *)this->vertsX + v23))));
      v32 = (float)((float)((float)(this->vertsX[v25] - this->vertsY[v20])
                          * (float)(*(float *)((char *)this->vertsX + v24) - *(float *)((char *)this->vertsX + v23)))
                  - (float)((float)(this->vertsY[v22] - this->vertsY[v20]) * (float)v27));
      v31 = (float)((float)((float)(this->vertsY[v22] - this->vertsY[v20])
                          * (float)(this->vertsZ[v21] - this->vertsZ[v20]))
                  - (float)((float)(this->vertsZ[v22] - this->vertsZ[v20])
                          * (float)(this->vertsX[v25] - this->vertsY[v20])));
      _FP11 = (float)((float)((float)((float)v32 * (float)v32)
                            + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f6, f11, f1, f13 }
      v35 = __frsqrte(_FP6);
      v36 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                                                          * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v35)
                                                                          - (float)1.5)
                                                          * (float)v35)
                                                  * (float)((float)((float)((float)v32 * (float)v32)
                                                                  + (float)((float)((float)v31 * (float)v31)
                                                                          + (float)((float)v30 * (float)v30)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v35
                                                                                  * (float)((float)((float)((float)v32 * (float)v32)
                                                                                                  + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30)))
                                                                                          * (float)0.5))
                                                                          * (float)v35)
                                                                  - (float)1.5)
                                                  * (float)v35))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v35
                                                          * (float)((float)((float)((float)v32 * (float)v32)
                                                                          + (float)((float)((float)v31 * (float)v31)
                                                                                  + (float)((float)v30 * (float)v30)))
                                                                  * (float)0.5))
                                                  * (float)v35)
                                          - (float)1.5)
                          * (float)v35));
      v37 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30))) * (float)0.5)) * (float)v35) - (float)1.5)
                                                                                                  * (float)v35)
                                                                                          * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30)))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30))) * (float)0.5)) * (float)v35) - (float)1.5)
                                                                                          * (float)v35))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v35
                                                                                                  * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30))) * (float)0.5))
                                                                                          * (float)v35)
                                                                                  - (float)1.5)
                                                                  * (float)v35))
                                                  * (float)((float)((float)((float)v32 * (float)v32)
                                                                  + (float)((float)((float)v31 * (float)v31)
                                                                          + (float)((float)v30 * (float)v30)))
                                                          * (float)0.5))
                                          * (float)v36)
                                  - (float)1.5)
                  * (float)v36);
      v38 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30))) * (float)0.5)) * (float)v35) - (float)1.5) * (float)v35)
                                                                                                  * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30))) * (float)0.5)) * (float)v35) - (float)1.5)
                                                                                                  * (float)v35))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30))) * (float)0.5))
                                                                                                  * (float)v35)
                                                                                          - (float)1.5)
                                                                          * (float)v35))
                                                          * (float)((float)((float)((float)v32 * (float)v32)
                                                                          + (float)((float)((float)v31 * (float)v31)
                                                                                  + (float)((float)v30 * (float)v30)))
                                                                  * (float)0.5))
                                                  * (float)v36)
                                          - (float)1.5)
                          * (float)v36)
                  * (float)v32);
      *(v15 - 15) = v38;
      *(v15 - 31) = (float)v37 * (float)v30;
      *(v15 - 47) = (float)v37 * (float)v31;
      *++v15 = -(float)((float)((float)v26 * (float)((float)v37 * (float)v31))
                      + (float)((float)((float)v29 * (float)((float)v37 * (float)v30)) + (float)((float)v28 * (float)v38)));
    }
    while ( v4 < this->numPolys );
  }
  this->bounds.b[0].x = octBounds->b[0].x;
  this->bounds.b[0].y = octBounds->b[0].y;
  this->bounds.b[0].z = octBounds->b[0].z;
  this->bounds.b[1].x = octBounds->b[1].x;
  this->bounds.b[1].y = octBounds->b[1].y;
  this->bounds.b[1].z = octBounds->b[1].z;
  idTraceModel::CalculateInsetSphereRadius(this);
  idTraceModel::GenerateEdgeNormals(this: v39);
}


// ========================================================================
// ?SetupDodecahedron@idTraceModel@@QAAXABVidBounds@@@Z
// EA  : 0x82F27AA0
// RVA : 0x00F27AA0
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::SetupDodecahedron(idTraceModel *this, const idBounds *dodBounds)
{
  double v4; // fp6
  double v5; // fp5
  double v6; // fp2
  double v7; // fp1
  double v8; // fp10
  double v9; // fp11
  double v10; // fp12
  double v11; // fp13
  double v12; // fp10
  double v13; // fp5
  double v14; // fp6
  double y; // fp4
  double v16; // fp11
  double v17; // fp7
  double v18; // fp4
  double x; // fp11
  double v20; // fp4
  double v21; // fp11
  double v22; // fp3
  double z; // fp3
  double v24; // fp4
  double v25; // fp4
  double v26; // fp7
  double v27; // fp7
  double v28; // fp9
  double v29; // fp2
  double v30; // fp4
  double v31; // fp4
  double v32; // fp3
  double v33; // fp7
  double v34; // fp2
  double v35; // fp3
  double v36; // fp1
  double v37; // fp8
  double v38; // fp5
  double v39; // fp1
  double v40; // fp9
  unsigned int v41; // r6
  double v42; // fp7
  double v43; // fp4
  double v44; // fp9
  double v45; // fp1
  double v46; // fp10
  double v47; // fp3
  double v48; // fp5
  double v49; // fp11
  double v50; // fp10
  double v51; // fp8
  double v52; // fp5
  double v53; // fp3
  double v54; // fp1
  double v55; // fp12
  float *v56; // r11
  char *v57; // r7
  unsigned int v58; // r5
  int v59; // r10
  int v60; // r8
  int v61; // r10
  int v62; // r9
  int v63; // r8
  int v64; // r5
  int v65; // r27
  int v66; // r28
  double v67; // fp10
  double v68; // fp7
  double v69; // fp4
  double v70; // fp2
  double v71; // fp9
  double v72; // fp7
  double v73; // fp5
  double v76; // fp3
  double v77; // fp12
  double v78; // fp6
  double v79; // fp5
  idTraceModel *v80; // r3

  if ( this->type != TRM_DODECAHEDRON )
    idTraceModel::InitDodecahedron(this);
  v4 = (float)(dodBounds->b[1].y + dodBounds->b[0].y);
  v5 = (float)(dodBounds->b[1].z + dodBounds->b[0].z);
  v6 = (float)(dodBounds->b[1].y - dodBounds->b[0].y);
  v7 = (float)(dodBounds->b[1].z - dodBounds->b[0].z);
  v8 = (float)((float)(dodBounds->b[1].x - dodBounds->b[0].x) * (float)0.53523314);
  v9 = (float)((float)(dodBounds->b[0].x + dodBounds->b[1].x) * (float)0.5);
  this->offset.x = (float)(dodBounds->b[0].x + dodBounds->b[1].x) * (float)0.5;
  this->offset.y = (float)v4 * (float)0.5;
  this->offset.z = (float)v5 * (float)0.5;
  v10 = (float)((float)((float)v6 * (float)0.53523314) * (float)0.3568221);
  v11 = (float)((float)((float)v7 * (float)0.53523314) * (float)0.3568221);
  this->vertsX[0] = (float)v9 + (float)((float)v8 * (float)0.57735026);
  this->vertsY[0] = (float)((float)((float)v6 * (float)0.53523314) * (float)0.57735026)
                  + (float)((float)v4 * (float)0.5);
  this->vertsZ[0] = (float)((float)((float)v7 * (float)0.53523314) * (float)0.57735026)
                  + (float)((float)v5 * (float)0.5);
  v13 = (float)((float)((float)v6 * (float)0.53523314) * (float)0.93417233);
  v14 = (float)((float)((float)v7 * (float)0.53523314) * (float)0.93417233);
  y = this->offset.y;
  v16 = (float)(this->offset.x + (float)((float)v8 * (float)0.57735026));
  this->vertsZ[1] = this->offset.z - (float)((float)((float)v7 * (float)0.53523314) * (float)0.57735026);
  this->vertsY[1] = (float)((float)((float)v6 * (float)0.53523314) * (float)0.57735026) + (float)y;
  this->vertsX[1] = v16;
  v17 = this->offset.y;
  v18 = (float)((float)((float)((float)v7 * (float)0.53523314) * (float)0.57735026) + this->offset.z);
  this->vertsX[2] = this->offset.x + (float)((float)v8 * (float)0.57735026);
  this->vertsZ[2] = v18;
  this->vertsY[2] = (float)v17 - (float)((float)((float)v6 * (float)0.53523314) * (float)0.57735026);
  x = this->offset.x;
  v20 = (float)(this->offset.z - (float)((float)((float)v7 * (float)0.53523314) * (float)0.57735026));
  this->vertsY[3] = this->offset.y - (float)((float)((float)v6 * (float)0.53523314) * (float)0.57735026);
  this->vertsX[3] = (float)x + (float)((float)v8 * (float)0.57735026);
  this->vertsZ[3] = v20;
  v21 = this->offset.y;
  v22 = (float)((float)((float)((float)v7 * (float)0.53523314) * (float)0.57735026) + this->offset.z);
  this->vertsX[4] = this->offset.x - (float)((float)v8 * (float)0.57735026);
  this->vertsY[4] = (float)((float)((float)v6 * (float)0.53523314) * (float)0.57735026) + (float)v21;
  this->vertsZ[4] = v22;
  z = this->offset.z;
  v24 = (float)(this->offset.x - (float)((float)v8 * (float)0.57735026));
  this->vertsY[5] = (float)((float)((float)v6 * (float)0.53523314) * (float)0.57735026) + this->offset.y;
  this->vertsX[5] = v24;
  this->vertsZ[5] = (float)z - (float)((float)((float)v7 * (float)0.53523314) * (float)0.57735026);
  v25 = this->offset.z;
  v26 = (float)(this->offset.x - (float)((float)v8 * (float)0.57735026));
  this->vertsY[6] = this->offset.y - (float)((float)((float)v6 * (float)0.53523314) * (float)0.57735026);
  this->vertsZ[6] = (float)((float)((float)v7 * (float)0.53523314) * (float)0.57735026) + (float)v25;
  this->vertsX[6] = v26;
  v27 = this->offset.x;
  v28 = (float)(this->offset.z - (float)((float)((float)v7 * (float)0.53523314) * (float)0.57735026));
  this->vertsY[7] = this->offset.y - (float)((float)((float)v6 * (float)0.53523314) * (float)0.57735026);
  this->vertsZ[7] = v28;
  this->vertsX[7] = (float)v27 - (float)((float)v8 * (float)0.57735026);
  v30 = (float)((float)((float)((float)v6 * (float)0.53523314) * (float)0.93417233) + this->offset.y);
  v29 = this->offset.z;
  this->vertsX[8] = this->offset.x + (float)((float)v8 * (float)0.3568221);
  this->vertsY[8] = v30;
  this->vertsZ[8] = v29;
  v31 = (float)((float)v13 + this->offset.y);
  v32 = (float)(this->offset.x - (float)((float)v8 * (float)0.3568221));
  this->vertsZ[9] = this->offset.z;
  this->vertsX[9] = v32;
  this->vertsY[9] = v31;
  v33 = (float)(this->offset.y - (float)v13);
  v34 = this->offset.z;
  this->vertsX[10] = this->offset.x + (float)((float)v8 * (float)0.3568221);
  this->vertsZ[10] = v34;
  this->vertsY[10] = v33;
  v35 = (float)(this->offset.x - (float)((float)v8 * (float)0.3568221));
  v12 = (float)((float)v8 * (float)0.93417233);
  v36 = (float)(this->offset.y - (float)v13);
  this->vertsZ[11] = this->offset.z;
  this->vertsX[11] = v35;
  this->vertsY[11] = v36;
  v37 = (float)(this->offset.x + (float)v12);
  v38 = (float)((float)v11 + this->offset.z);
  this->vertsY[12] = this->offset.y;
  this->vertsX[12] = v37;
  this->vertsZ[12] = v38;
  v39 = this->offset.x;
  v40 = (float)(this->offset.z - (float)v11);
  this->vertsY[13] = this->offset.y;
  this->vertsZ[13] = v40;
  this->vertsX[13] = (float)v39 + (float)v12;
  v41 = 0;
  v42 = (float)((float)v11 + this->offset.z);
  v43 = (float)(this->offset.x - (float)v12);
  this->vertsY[14] = this->offset.y;
  this->vertsZ[14] = v42;
  this->vertsX[14] = v43;
  v44 = this->offset.y;
  v45 = (float)(this->offset.x - (float)v12);
  v46 = (float)(this->offset.z - (float)v11);
  this->vertsX[15] = v45;
  this->vertsY[15] = v44;
  this->vertsZ[15] = v46;
  v47 = (float)((float)v14 + this->offset.z);
  v48 = (float)((float)v10 + this->offset.y);
  this->vertsX[16] = this->offset.x;
  this->vertsY[16] = v48;
  this->vertsZ[16] = v47;
  v49 = (float)((float)v14 + this->offset.z);
  v50 = this->offset.x;
  this->vertsY[17] = this->offset.y - (float)v10;
  this->vertsX[17] = v50;
  this->vertsZ[17] = v49;
  v51 = (float)((float)v10 + this->offset.y);
  v52 = (float)(this->offset.z - (float)v14);
  this->vertsX[18] = this->offset.x;
  this->vertsY[18] = v51;
  this->vertsZ[18] = v52;
  v53 = this->offset.x;
  v54 = (float)(this->offset.y - (float)v10);
  v55 = (float)(this->offset.z - (float)v14);
  this->vertsY[19] = v54;
  this->vertsX[19] = v53;
  this->vertsZ[19] = v55;
  if ( this->numPolys != 0 )
  {
    v56 = &this->polyPlaneZ[15];
    v57 = (char *)&this->polyPlaneW[12] + 1;
    do
    {
      v58 = (unsigned __int8)v57[15];
      v57 += 16;
      ++v41;
      v59 = 2 * ((v58 & 0x7F) + 336);
      v60 = ((~(_BYTE)v58 & 0x80) != 0) + v59;
      v61 = *((unsigned __int16 *)this->vertsX + (v58 >> 7) + v59);
      v62 = this->edges[*v57 & 0x7F].v[(~*v57 & 0x80) != 0];
      v63 = *((unsigned __int16 *)this->vertsX + v60);
      v64 = __ROL4__(v61, 2);
      v65 = __ROL4__(v63, 2);
      v66 = v62 + 32;
      v67 = *(float *)((char *)this->vertsX + v64);
      v68 = (float)(*(float *)((char *)this->vertsX + __ROL4__(v62, 2)) - *(float *)((char *)this->vertsX + v64));
      v69 = this->vertsZ[v61];
      v70 = this->vertsY[v61];
      v71 = (float)((float)((float)(this->vertsZ[v63] - this->vertsZ[v61]) * (float)v68)
                  - (float)((float)(this->vertsZ[v62] - this->vertsZ[v61])
                          * (float)(*(float *)((char *)this->vertsX + v65) - *(float *)((char *)this->vertsX + v64))));
      v73 = (float)((float)((float)(this->vertsX[v66] - this->vertsY[v61])
                          * (float)(*(float *)((char *)this->vertsX + v65) - *(float *)((char *)this->vertsX + v64)))
                  - (float)((float)(this->vertsY[v63] - this->vertsY[v61]) * (float)v68));
      v72 = (float)((float)((float)(this->vertsY[v63] - this->vertsY[v61])
                          * (float)(this->vertsZ[v62] - this->vertsZ[v61]))
                  - (float)((float)(this->vertsZ[v63] - this->vertsZ[v61])
                          * (float)(this->vertsX[v66] - this->vertsY[v61])));
      _FP11 = (float)((float)((float)((float)v73 * (float)v73)
                            + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f6, f11, f1, f12 }
      v76 = __frsqrte(_FP6);
      v77 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v76
                                                                                          * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v76)
                                                                          - (float)1.5)
                                                          * (float)v76)
                                                  * (float)((float)((float)((float)v73 * (float)v73)
                                                                  + (float)((float)((float)v72 * (float)v72)
                                                                          + (float)((float)v71 * (float)v71)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v76
                                                                                  * (float)((float)((float)((float)v73 * (float)v73)
                                                                                                  + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
                                                                                          * (float)0.5))
                                                                          * (float)v76)
                                                                  - (float)1.5)
                                                  * (float)v76))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v76
                                                          * (float)((float)((float)((float)v73 * (float)v73)
                                                                          + (float)((float)((float)v72 * (float)v72)
                                                                                  + (float)((float)v71 * (float)v71)))
                                                                  * (float)0.5))
                                                  * (float)v76)
                                          - (float)1.5)
                          * (float)v76));
      v78 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v76 * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5)) * (float)v76) - (float)1.5)
                                                                                                  * (float)v76)
                                                                                          * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v76 * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5)) * (float)v76) - (float)1.5)
                                                                                          * (float)v76))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v76
                                                                                                  * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5))
                                                                                          * (float)v76)
                                                                                  - (float)1.5)
                                                                  * (float)v76))
                                                  * (float)((float)((float)((float)v73 * (float)v73)
                                                                  + (float)((float)((float)v72 * (float)v72)
                                                                          + (float)((float)v71 * (float)v71)))
                                                          * (float)0.5))
                                          * (float)v77)
                                  - (float)1.5)
                  * (float)v77);
      v79 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v76 * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5)) * (float)v76) - (float)1.5) * (float)v76)
                                                                                                  * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v76 * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5)) * (float)v76) - (float)1.5)
                                                                                                  * (float)v76))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v76 * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5))
                                                                                                  * (float)v76)
                                                                                          - (float)1.5)
                                                                          * (float)v76))
                                                          * (float)((float)((float)((float)v73 * (float)v73)
                                                                          + (float)((float)((float)v72 * (float)v72)
                                                                                  + (float)((float)v71 * (float)v71)))
                                                                  * (float)0.5))
                                                  * (float)v77)
                                          - (float)1.5)
                          * (float)v77)
                  * (float)v73);
      *(v56 - 15) = v79;
      *(v56 - 31) = (float)v78 * (float)v71;
      *(v56 - 47) = (float)v78 * (float)v72;
      *++v56 = -(float)((float)((float)v67 * (float)((float)v78 * (float)v72))
                      + (float)((float)((float)v70 * (float)((float)v78 * (float)v71)) + (float)((float)v69 * (float)v79)));
    }
    while ( v41 < this->numPolys );
  }
  this->bounds.b[0].x = dodBounds->b[0].x;
  this->bounds.b[0].y = dodBounds->b[0].y;
  this->bounds.b[0].z = dodBounds->b[0].z;
  this->bounds.b[1].x = dodBounds->b[1].x;
  this->bounds.b[1].y = dodBounds->b[1].y;
  this->bounds.b[1].z = dodBounds->b[1].z;
  idTraceModel::CalculateInsetSphereRadius(this);
  idTraceModel::GenerateEdgeNormals(this: v80);
}


// ========================================================================
// ?SetupCylinder@idTraceModel@@QAAXABVidBounds@@H@Z
// EA  : 0x82F27FF8
// RVA : 0x00F27FF8
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idTraceModel::SetupCylinder(idTraceModel *this, idBounds *cylBounds, int numSides)
{
  float *v4; // r28
  signed int v5; // r29
  float *v6; // r7
  int v7; // r30
  double v8; // fp7
  double v9; // fp8
  double v10; // fp3
  long double v11; // fp2
  double v12; // fp30
  double v13; // fp31
  double v14; // fp29
  signed int v15; // r11
  double v16; // fp28
  __int64 v17; // r10 OVERLAPPED
  int v18; // r25
  char *v19; // r18
  char *v20; // r27
  _WORD *v21; // r26
  unsigned __int8 *v22; // r28
  double v23; // fp26
  long double v24; // fp2
  double v25; // fp4
  double v26; // fp0
  int v27; // r10
  signed int v28; // ctr
  float *v29; // r11
  float *v30; // r9
  double v31; // fp13
  double v32; // fp11
  double v33; // fp10
  double v34; // fp9
  double v35; // fp8
  double v36; // fp7
  double v37; // fp5
  double v38; // fp6
  double v39; // fp13
  int v40; // r4
  int v41; // r8
  double v42; // fp3
  double v43; // fp12
  double v44; // fp6
  double v45; // fp4
  double v46; // fp3
  double v49; // fp2
  double v50; // fp1
  double v51; // fp8
  double v52; // fp5
  double v53; // fp6
  double v54; // fp12
  double v55; // fp13
  double v56; // fp0
  double v57; // fp12
  double v58; // fp11
  double v59; // fp9
  double v60; // fp10
  float *v63; // [sp+60h] [-E0h]

  v4 = (float *)cylBounds;
  v5 = numSides;
  if ( numSides < 3 )
    v5 = 3;
  if ( 2 * v5 > 32 )
  {
    idLib::Printf(fmt: "WARNING: idTraceModel::SetupCylinder: too many vertices\n");
    v5 = 16;
  }
  if ( 3 * v5 > 32 )
  {
    idLib::Printf(fmt: "WARNING: idTraceModel::SetupCylinder: too many sides\n");
    v5 = 10;
  }
  if ( v5 + 2 > 16 )
  {
    idLib::Printf(fmt: "WARNING: idTraceModel::SetupCylinder: too many polygons\n");
    v5 = 14;
  }
  this->maxPolyEdges = v5;
  v6 = v4 + 3;
  v63 = v4 + 3;
  this->numVerts = 2 * v5;
  this->numEdges = 3 * v5;
  this->type = TRM_CYLINDER;
  this->numPolys = v5 + 2;
  v7 = 0;
  v8 = (float)(v4[4] + v4[1]);
  v9 = (float)(v4[5] + v4[2]);
  v10 = (float)((float)(*v4 + v4[3]) * (float)0.5);
  this->offset.x = (float)(*v4 + v4[3]) * (float)0.5;
  this->offset.y = (float)v8 * (float)0.5;
  this->offset.z = (float)v9 * (float)0.5;
  *((double *)&v11 + 1) = v4[3];
  v12 = (float)(v4[3] - (float)v10);
  v13 = (float)(v4[5] - (float)((float)v9 * (float)0.5));
  v14 = (float)(v4[4] - (float)((float)v8 * (float)0.5));
  if ( v5 > 0 )
  {
    v15 = v5;
    LODWORD(v17) = 2 * v5;
    v16 = (float)*(__int64 *)((char *)&v17 - 4);
    HIDWORD(v17) = 16 * (v5 + 65);
    v18 = 2 * v5;
    v19 = (char *)this + HIDWORD(v17);
    v20 = (char *)&this->polyPlaneW[12] + 3;
    v21 = (_WORD *)&this->numPolyEdges[v5 + 15] + 1;
    v22 = &this->polyEdges[15][12];
    do
    {
      LODWORD(v17) = v7;
      v23 = (float)((float)((float)v17 * idMath::TWO_PI) / (float)v16);
      *(double *)&v11 = v23;
      v24 = cos(x: v11);
      *((float *)v22 - 319) = (float)((float)v12 * (float)*(double *)&v24) + this->offset.x;
      *(double *)&v24 = v23;
      v11 = sin(x: v24);
      v25 = *((float *)v22 - 319);
      *((float *)v22 - 287) = (float)((float)v14 * (float)*(double *)&v11) + this->offset.y;
      *((double *)&v11 + 1) = this->offset.z;
      *((float *)v22 - 255) = this->offset.z - (float)v13;
      *(float *)(v21 - 671) = v25;
      v26 = *((float *)v22 - 287);
      __twllei(v5, 0);
      this->vertsY[v5 + v7] = v26;
      this->vertsZ[v5 + v7] = this->offset.z + (float)v13;
      *((_WORD *)v22 + 35) = (v7 + 1) % v5;
      *((_WORD *)v22 + 34) = v7;
      this->edges[v5 + v7].v[0] = v5 + v7;
      v21 += 2;
      *v21 = *((_WORD *)v22 + 35) + v5;
      this->edges[v18 + v7].v[0] = v7;
      this->edges[v18 + v7].v[1] = v7 + v5;
      v22 += 4;
      *(_DWORD *)v22 = 4;
      v20[14] = ((v7 + 1) % v5 + v18) & 0x7F;
      v20[13] = v7 & 0x7F;
      __twlgei(v5 & ~(__ROL4__(v7 + 1, 1) - 1), 0xFFFFFFFF);
      v20[15] = (v7 + v5) | 0x80;
      v20 += 16;
      *v20 = (v18 + v7) | 0x80;
      HIDWORD(v17) = ((_BYTE)v5 - (_BYTE)v7 - 1) & 0x7F | 0x80;
      v19[v7] = (v7 + v5) & 0x7F;
      this->polyEdges[v5][v7++] = BYTE3(v17);
    }
    while ( v7 < v5 );
    v6 = v63;
    v4 = (float *)cylBounds;
  }
  v27 = 0;
  this->numPolyEdges[v5 + 1] = v5;
  this->numPolyEdges[v5] = v5;
  if ( v5 > 0 )
  {
    v28 = v5;
    v29 = &this->polyPlaneZ[15];
    v30 = &this->vertsY[v5 + 31];
    do
    {
      ++v27;
      v31 = *(v30 - 63);
      v32 = *(v30 - 31);
      __twllei(v5, 0);
      ++v30;
      v33 = *(v29 - 239);
      v34 = *(v29 - 175);
      v35 = (float)(*v30 - *(v29 - 175));
      v36 = *(v29 - 207);
      v37 = (float)((float)v32 - *(v29 - 207));
      v38 = (float)((float)v31 - *(v29 - 239));
      v39 = idMath::FLT_SMALLEST_NON_DENORMAL;
      v40 = v27 % v5 + 64;
      v41 = v27 % v5 + 32;
      v42 = (float)(this->vertsX[v27 % v5] - *(v29 - 239));
      __twlgei(v5 & ~(__ROL4__(v27, 1) - 1), 0xFFFFFFFF);
      v43 = (float)((float)(this->vertsX[v41] - (float)v36) * (float)v38);
      v44 = (float)((float)((float)(this->vertsX[v40] - (float)v34) * (float)v38) - (float)((float)v35 * (float)v42));
      v45 = (float)((float)((float)(this->vertsX[v41] - (float)v36) * (float)v35)
                  - (float)((float)(this->vertsX[v40] - (float)v34) * (float)v37));
      v46 = (float)((float)((float)v37 * (float)v42) - (float)v43);
      _FP11 = (float)((float)((float)((float)v46 * (float)v46)
                            + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44)))
                    - (float)v39);
      __asm { fsel      f5, f11, f12, f13 }
      v49 = __frsqrte(_FP5);
      v50 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v49
                                                                                          * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v49)
                                                                          - (float)1.5)
                                                          * (float)v49)
                                                  * (float)((float)((float)((float)v46 * (float)v46)
                                                                  + (float)((float)((float)v45 * (float)v45)
                                                                          + (float)((float)v44 * (float)v44)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v49
                                                                                  * (float)((float)((float)((float)v46 * (float)v46)
                                                                                                  + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44)))
                                                                                          * (float)0.5))
                                                                          * (float)v49)
                                                                  - (float)1.5)
                                                  * (float)v49))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v49
                                                          * (float)((float)((float)((float)v46 * (float)v46)
                                                                          + (float)((float)((float)v45 * (float)v45)
                                                                                  + (float)((float)v44 * (float)v44)))
                                                                  * (float)0.5))
                                                  * (float)v49)
                                          - (float)1.5)
                          * (float)v49));
      v51 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5)) * (float)v49) - (float)1.5) * (float)v49)
                                                                                                  * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5)) * (float)v49) - (float)1.5)
                                                                                                  * (float)v49))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5))
                                                                                                  * (float)v49)
                                                                                          - (float)1.5)
                                                                          * (float)v49))
                                                          * (float)((float)((float)((float)v46 * (float)v46)
                                                                          + (float)((float)((float)v45 * (float)v45)
                                                                                  + (float)((float)v44 * (float)v44)))
                                                                  * (float)0.5))
                                                  * (float)v50)
                                          - (float)1.5)
                          * (float)v50)
                  * (float)v46);
      *(v29 - 15) = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5)) * (float)v49) - (float)1.5) * (float)v49)
                                                                                                  * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5)) * (float)v49) - (float)1.5)
                                                                                                  * (float)v49))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5))
                                                                                                  * (float)v49)
                                                                                          - (float)1.5)
                                                                          * (float)v49))
                                                          * (float)((float)((float)((float)v46 * (float)v46)
                                                                          + (float)((float)((float)v45 * (float)v45)
                                                                                  + (float)((float)v44 * (float)v44)))
                                                                  * (float)0.5))
                                                  * (float)v50)
                                          - (float)1.5)
                          * (float)v50)
                  * (float)v46;
      v52 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5)) * (float)v49) - (float)1.5) * (float)v49)
                                                                                                  * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5)) * (float)v49) - (float)1.5)
                                                                                                  * (float)v49))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5))
                                                                                                  * (float)v49)
                                                                                          - (float)1.5)
                                                                          * (float)v49))
                                                          * (float)((float)((float)((float)v46 * (float)v46)
                                                                          + (float)((float)((float)v45 * (float)v45)
                                                                                  + (float)((float)v44 * (float)v44)))
                                                                  * (float)0.5))
                                                  * (float)v50)
                                          - (float)1.5)
                          * (float)v50)
                  * (float)v45);
      *(v29 - 47) = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5)) * (float)v49) - (float)1.5) * (float)v49)
                                                                                                  * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5)) * (float)v49) - (float)1.5)
                                                                                                  * (float)v49))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5))
                                                                                                  * (float)v49)
                                                                                          - (float)1.5)
                                                                          * (float)v49))
                                                          * (float)((float)((float)((float)v46 * (float)v46)
                                                                          + (float)((float)((float)v45 * (float)v45)
                                                                                  + (float)((float)v44 * (float)v44)))
                                                                  * (float)0.5))
                                                  * (float)v50)
                                          - (float)1.5)
                          * (float)v50)
                  * (float)v45;
      v53 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5)) * (float)v49) - (float)1.5) * (float)v49)
                                                                                                  * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5)) * (float)v49) - (float)1.5)
                                                                                                  * (float)v49))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)v46 * (float)v46) + (float)((float)((float)v45 * (float)v45) + (float)((float)v44 * (float)v44))) * (float)0.5))
                                                                                                  * (float)v49)
                                                                                          - (float)1.5)
                                                                          * (float)v49))
                                                          * (float)((float)((float)((float)v46 * (float)v46)
                                                                          + (float)((float)((float)v45 * (float)v45)
                                                                                  + (float)((float)v44 * (float)v44)))
                                                                  * (float)0.5))
                                                  * (float)v50)
                                          - (float)1.5)
                          * (float)v50)
                  * (float)v44);
      *(v29 - 31) = v53;
      *++v29 = -(float)((float)((float)v33 * (float)v52)
                      + (float)((float)((float)v36 * (float)v53) + (float)((float)v34 * (float)v51)));
      --v28;
    }
    while ( v28 != 0 );
  }
  this->polyPlaneW[v5] = v4[2];
  this->polyPlaneY[v5] = 0.0;
  this->polyPlaneX[v5] = 0.0;
  this->polyPlaneZ[v5] = -1.0;
  v54 = v4[5];
  this->polyPlaneX[v5 + 1] = 0.0;
  this->polyPlaneY[v5 + 1] = 0.0;
  this->polyPlaneZ[v5 + 1] = 1.0;
  this->polyPlaneW[v5 + 1] = -v54;
  this->bounds.b[0].x = *v4;
  this->bounds.b[0].y = v4[1];
  this->bounds.b[0].z = v4[2];
  this->bounds.b[1].x = *v6;
  this->bounds.b[1].y = v6[1];
  this->bounds.b[1].z = v6[2];
  v55 = __fabs(this->bounds.b[0].x);
  v56 = __fabs(this->bounds.b[0].y);
  v57 = __fabs(this->bounds.b[0].z);
  if ( v55 >= v56 )
  {
    if ( v56 < v57 )
      goto LABEL_21;
  }
  else if ( v55 < v57 )
  {
    v56 = v55;
    goto LABEL_21;
  }
  v56 = v57;
LABEL_21:
  v58 = __fabs(this->bounds.b[1].y);
  v59 = __fabs(this->bounds.b[1].x);
  v60 = __fabs(this->bounds.b[1].z);
  if ( v59 >= v58 )
  {
    if ( v58 < v60 )
      goto LABEL_26;
LABEL_25:
    v58 = v60;
    goto LABEL_26;
  }
  if ( v59 >= v60 )
    goto LABEL_25;
  v58 = v59;
LABEL_26:
  _FP13 = (float)((float)v56 - (float)v58);
  this->isConvex = true;
  __asm { fsel      f12, f13, f11, f0 }
  this->radius = _FP12;
  idTraceModel::GenerateEdgeNormals(this);
  idTraceModel::ClearUnused(this);
}


// ========================================================================
// ?SetupCylinder@idTraceModel@@QAAXMMH@Z
// EA  : 0x82F285A0
// RVA : 0x00F285A0
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::SetupCylinder(
        idTraceModel *this,
        double height,
        double width,
        const int numSides,
        int a5,
        int a6)
{
  idBounds v6; // [sp+50h] [-20h] BYREF

  v6.b[1].x = (float)width * (float)0.5;
  v6.b[1].y = v6.b[1].x;
  v6.b[1].z = (float)height * (float)0.5;
  v6.b[0].x = -v6.b[1].x;
  v6.b[0].z = -v6.b[1].z;
  v6.b[0].y = v6.b[0].x;
  idTraceModel::SetupCylinder(this, cylBounds: &v6, numSides: a6);
}


// ========================================================================
// ?SetupCone@idTraceModel@@QAAXABVidBounds@@H@Z
// EA  : 0x82F285F8
// RVA : 0x00F285F8
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idTraceModel::SetupCone(idTraceModel *this, const idBounds *coneBounds, int numSides)
{
  signed int v5; // r31
  __int64 v6; // r10 OVERLAPPED
  int v7; // r15
  double v8; // fp8
  double v9; // fp7
  int v10; // r14
  double v11; // fp3
  char *v12; // r18
  int v13; // r29
  long double v14; // fp2
  double v15; // fp30
  double v16; // fp31
  double y; // fp10
  double v18; // fp29
  double v19; // fp28
  char *v20; // r27
  unsigned __int8 *v21; // r28
  int v22; // r11
  double v23; // fp25
  long double v24; // fp2
  __int16 v25; // r3
  double z; // fp3
  int v27; // r10
  signed int v28; // ctr
  float *v29; // r11
  double v30; // fp13
  double v31; // fp12
  double v32; // fp11
  double v33; // fp10
  double v34; // fp7
  double v35; // fp6
  double v36; // fp5
  double v37; // fp13
  double v38; // fp3
  double v39; // fp1
  double v40; // fp8
  double v41; // fp9
  double v42; // fp6
  double v43; // fp4
  double v44; // fp3
  double v47; // fp2
  double v48; // fp1
  double v49; // fp8
  double v50; // fp5
  double v51; // fp6
  double v52; // fp13
  double v53; // fp12
  double v54; // fp0
  double v55; // fp13
  double v56; // fp11
  double v57; // fp9
  double v58; // fp10

  v5 = numSides;
  if ( numSides < 2 )
    v5 = 3;
  if ( v5 + 1 > 32 )
  {
    idLib::Printf(fmt: "WARNING: idTraceModel::SetupCone: too many vertices\n");
    v5 = 31;
  }
  if ( 2 * v5 > 32 )
  {
    idLib::Printf(fmt: "WARNING: idTraceModel::SetupCone: too many edges\n");
    v5 = 16;
  }
  if ( v5 + 1 > 16 )
  {
    idLib::Printf(fmt: "WARNING: idTraceModel::SetupCone: too many polygons\n");
    v5 = 15;
  }
  this->maxPolyEdges = v5;
  this->numVerts = v5 + 1;
  this->numPolys = v5 + 1;
  this->type = TRM_CONE;
  this->numEdges = 2 * v5;
  v7 = v5 + 32;
  v8 = (float)(coneBounds->b[0].z + coneBounds->b[1].z);
  v9 = (float)(coneBounds->b[1].y + coneBounds->b[0].y);
  v10 = v5 + 64;
  v11 = (float)((float)(coneBounds->b[0].x + coneBounds->b[1].x) * (float)0.5);
  this->offset.x = (float)(coneBounds->b[0].x + coneBounds->b[1].x) * (float)0.5;
  v12 = (char *)&this->vertsX[v5];
  v13 = 0;
  this->offset.z = (float)v8 * (float)0.5;
  this->offset.y = (float)v9 * (float)0.5;
  *((double *)&v14 + 1) = coneBounds->b[1].z;
  v15 = (float)(coneBounds->b[1].x - (float)v11);
  v16 = (float)(coneBounds->b[1].z - (float)((float)v8 * (float)0.5));
  y = coneBounds->b[1].y;
  *(float *)v12 = 0.0;
  this->vertsX[v7] = 0.0;
  this->vertsX[v10] = (float)v16 + (float)((float)v8 * (float)0.5);
  v18 = (float)((float)y - (float)((float)v9 * (float)0.5));
  if ( v5 > 0 )
  {
    LODWORD(v6) = v5;
    HIDWORD(v6) = 2 * v5;
    v19 = (float)v6;
    v20 = (char *)&this->polyPlaneW[12] + 2;
    v21 = &this->polyEdges[15][12];
    do
    {
      v22 = v13;
      v23 = (float)((float)((float)*(__int64 *)((char *)&v6 - 4) * idMath::TWO_PI) / (float)v19);
      *(double *)&v14 = v23;
      v24 = cos(x: v14);
      *((float *)v21 - 319) = (float)((float)*(double *)&v24 * (float)v15) + this->offset.x;
      *(double *)&v24 = v23;
      v14 = sin(x: v24);
      *((float *)v21 - 287) = (float)((float)v18 * (float)*(double *)&v14) + this->offset.y;
      v25 = (v13 + 1) % v5;
      LODWORD(v6) = ((_BYTE)v25 + (_BYTE)v5) & 0x7F;
      z = this->offset.z;
      *((_WORD *)v21 + 35) = v25;
      *((double *)&v14 + 1) = (float)((float)z - (float)v16);
      *((float *)v21 - 255) = (float)z - (float)v16;
      *((_WORD *)v21 + 34) = v13;
      this->edges[v5 + v13].v[0] = v13;
      __twllei(v5, 0);
      *((_WORD *)v12 + 673) = v5;
      v21 += 4;
      *(_DWORD *)v21 = 3;
      __twlgei(v5 & ~(__ROL4__(v13 + 1, 1) - 1), 0xFFFFFFFF);
      v20[14] = v13 & 0x7F;
      v20[15] = v6;
      v20 += 16;
      *v20 = (v13 + v5) | 0x80;
      this->polyEdges[v5][v13] = (v5 - v13 - 1) & 0x7F | 0x80;
      ++v13;
    }
    while ( v13 < v5 );
  }
  v27 = 0;
  this->numPolyEdges[v5] = v5;
  if ( v5 > 0 )
  {
    v28 = v5;
    v29 = &this->polyPlaneZ[15];
    do
    {
      ++v27;
      v30 = this->vertsX[v10];
      v31 = *(v29 - 239);
      __twllei(v5, 0);
      v32 = *(v29 - 175);
      v33 = (float)((float)v30 - *(v29 - 175));
      v34 = *(v29 - 207);
      v35 = (float)(*(float *)v12 - (float)v31);
      v36 = (float)(this->vertsX[v7] - *(v29 - 207));
      v37 = idMath::FLT_SMALLEST_NON_DENORMAL;
      v38 = (float)(this->vertsX[v27 % v5] - (float)v31);
      v39 = (float)(this->vertsZ[v27 % v5] - *(v29 - 175));
      v40 = (float)(this->vertsY[v27 % v5] - *(v29 - 207));
      __twlgei(v5 & ~(__ROL4__(v27, 1) - 1), 0xFFFFFFFF);
      v41 = (float)((float)v40 * (float)v35);
      v42 = (float)((float)((float)v39 * (float)v35) - (float)((float)v33 * (float)v38));
      v43 = (float)((float)((float)v40 * (float)v33) - (float)((float)v39 * (float)v36));
      v44 = (float)((float)((float)v36 * (float)v38) - (float)v41);
      _FP9 = (float)((float)((float)((float)v44 * (float)v44)
                           + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42)))
                   - (float)v37);
      __asm { fsel      f5, f9, f10, f13 }
      v47 = __frsqrte(_FP5);
      v48 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v47
                                                                                          * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v47)
                                                                          - (float)1.5)
                                                          * (float)v47)
                                                  * (float)((float)((float)((float)v44 * (float)v44)
                                                                  + (float)((float)((float)v43 * (float)v43)
                                                                          + (float)((float)v42 * (float)v42)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v47
                                                                                  * (float)((float)((float)((float)v44 * (float)v44)
                                                                                                  + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42)))
                                                                                          * (float)0.5))
                                                                          * (float)v47)
                                                                  - (float)1.5)
                                                  * (float)v47))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v47
                                                          * (float)((float)((float)((float)v44 * (float)v44)
                                                                          + (float)((float)((float)v43 * (float)v43)
                                                                                  + (float)((float)v42 * (float)v42)))
                                                                  * (float)0.5))
                                                  * (float)v47)
                                          - (float)1.5)
                          * (float)v47));
      v49 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5)) * (float)v47) - (float)1.5) * (float)v47)
                                                                                                  * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5)) * (float)v47) - (float)1.5)
                                                                                                  * (float)v47))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5))
                                                                                                  * (float)v47)
                                                                                          - (float)1.5)
                                                                          * (float)v47))
                                                          * (float)((float)((float)((float)v44 * (float)v44)
                                                                          + (float)((float)((float)v43 * (float)v43)
                                                                                  + (float)((float)v42 * (float)v42)))
                                                                  * (float)0.5))
                                                  * (float)v48)
                                          - (float)1.5)
                          * (float)v48)
                  * (float)v42);
      *(v29 - 31) = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5)) * (float)v47) - (float)1.5) * (float)v47)
                                                                                                  * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5)) * (float)v47) - (float)1.5)
                                                                                                  * (float)v47))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5))
                                                                                                  * (float)v47)
                                                                                          - (float)1.5)
                                                                          * (float)v47))
                                                          * (float)((float)((float)((float)v44 * (float)v44)
                                                                          + (float)((float)((float)v43 * (float)v43)
                                                                                  + (float)((float)v42 * (float)v42)))
                                                                  * (float)0.5))
                                                  * (float)v48)
                                          - (float)1.5)
                          * (float)v48)
                  * (float)v42;
      v50 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5)) * (float)v47) - (float)1.5) * (float)v47)
                                                                                                  * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5)) * (float)v47) - (float)1.5)
                                                                                                  * (float)v47))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5))
                                                                                                  * (float)v47)
                                                                                          - (float)1.5)
                                                                          * (float)v47))
                                                          * (float)((float)((float)((float)v44 * (float)v44)
                                                                          + (float)((float)((float)v43 * (float)v43)
                                                                                  + (float)((float)v42 * (float)v42)))
                                                                  * (float)0.5))
                                                  * (float)v48)
                                          - (float)1.5)
                          * (float)v48)
                  * (float)v43);
      *(v29 - 47) = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5)) * (float)v47) - (float)1.5) * (float)v47)
                                                                                                  * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5)) * (float)v47) - (float)1.5)
                                                                                                  * (float)v47))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5))
                                                                                                  * (float)v47)
                                                                                          - (float)1.5)
                                                                          * (float)v47))
                                                          * (float)((float)((float)((float)v44 * (float)v44)
                                                                          + (float)((float)((float)v43 * (float)v43)
                                                                                  + (float)((float)v42 * (float)v42)))
                                                                  * (float)0.5))
                                                  * (float)v48)
                                          - (float)1.5)
                          * (float)v48)
                  * (float)v43;
      v51 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5)) * (float)v47) - (float)1.5) * (float)v47)
                                                                                                  * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5)) * (float)v47) - (float)1.5)
                                                                                                  * (float)v47))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v47 * (float)((float)((float)((float)v44 * (float)v44) + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42))) * (float)0.5))
                                                                                                  * (float)v47)
                                                                                          - (float)1.5)
                                                                          * (float)v47))
                                                          * (float)((float)((float)((float)v44 * (float)v44)
                                                                          + (float)((float)((float)v43 * (float)v43)
                                                                                  + (float)((float)v42 * (float)v42)))
                                                                  * (float)0.5))
                                                  * (float)v48)
                                          - (float)1.5)
                          * (float)v48)
                  * (float)v44);
      *(v29 - 15) = v51;
      *++v29 = -(float)((float)((float)v31 * (float)v50)
                      + (float)((float)((float)v32 * (float)v51) + (float)((float)v34 * (float)v49)));
      --v28;
    }
    while ( v28 != 0 );
  }
  v52 = coneBounds->b[0].z;
  this->polyPlaneX[v5] = 0.0;
  this->polyPlaneZ[v5] = -1.0;
  this->polyPlaneW[v5] = v52;
  this->polyPlaneY[v5] = 0.0;
  this->bounds.b[0].x = coneBounds->b[0].x;
  this->bounds.b[0].y = coneBounds->b[0].y;
  this->bounds.b[0].z = coneBounds->b[0].z;
  this->bounds.b[1].x = coneBounds->b[1].x;
  this->bounds.b[1].y = coneBounds->b[1].y;
  this->bounds.b[1].z = coneBounds->b[1].z;
  v53 = __fabs(this->bounds.b[0].z);
  v54 = __fabs(this->bounds.b[0].x);
  v55 = __fabs(this->bounds.b[0].y);
  if ( v54 < v55 )
  {
    if ( v54 < v53 )
      goto LABEL_18;
    goto LABEL_17;
  }
  if ( v55 >= v53 )
  {
LABEL_17:
    v54 = v53;
    goto LABEL_18;
  }
  v54 = v55;
LABEL_18:
  v56 = __fabs(this->bounds.b[1].y);
  v57 = __fabs(this->bounds.b[1].x);
  v58 = __fabs(this->bounds.b[1].z);
  if ( v57 >= v56 )
  {
    if ( v56 < v58 )
      goto LABEL_25;
LABEL_24:
    v56 = v58;
    goto LABEL_25;
  }
  if ( v57 >= v58 )
    goto LABEL_24;
  v56 = v57;
LABEL_25:
  _FP13 = (float)((float)v54 - (float)v56);
  this->isConvex = true;
  __asm { fsel      f12, f13, f11, f0 }
  this->radius = _FP12;
  idTraceModel::GenerateEdgeNormals(this);
  idTraceModel::ClearUnused(this);
}


// ========================================================================
// ?SetupBone@idTraceModel@@QAAXMM@Z
// EA  : 0x82F28AC0
// RVA : 0x00F28AC0
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::SetupBone(idTraceModel *this, double length, double width)
{
  double v5; // fp29
  double v6; // fp11
  double v7; // fp13
  double v8; // fp0
  double v9; // fp9
  double v10; // fp6
  double v11; // fp10
  double v12; // fp8
  double v13; // fp5
  double v16; // fp2
  double v17; // fp2
  double v18; // fp1
  double v19; // fp12
  double v20; // fp11
  double v21; // fp4
  double v22; // fp13
  double v23; // fp11
  double v26; // fp4
  double v27; // fp6
  double v28; // fp3
  double v29; // fp2
  double v30; // fp0
  double v31; // fp1
  double v32; // fp9
  int v33; // r11
  double v34; // fp13
  double v35; // fp3
  double v36; // fp1
  double v37; // fp2
  double v38; // fp0
  double v39; // fp12
  double v40; // fp11
  double v41; // fp8
  double v42; // fp7
  double v43; // fp4
  double v44; // fp10
  int v45; // r11
  int v46; // r11
  int v47; // r11
  int v48; // r11
  double v49; // fp11
  double v50; // fp9
  int v51; // r11

  v5 = (float)((float)length * (float)0.5);
  if ( this->type != TRM_BONE )
    idTraceModel::InitBone(this);
  this->offset.x = 0.0;
  this->offset.y = 0.0;
  this->offset.z = 0.0;
  this->vertsX[0] = 0.0;
  this->vertsY[0] = 0.0;
  this->vertsZ[0] = -v5;
  this->vertsX[1] = 0.0;
  this->vertsY[1] = (float)width * (float)-0.5;
  this->vertsZ[1] = 0.0;
  this->vertsX[2] = (float)width * (float)0.5;
  this->vertsY[2] = (float)width * (float)0.25;
  this->vertsZ[2] = 0.0;
  this->vertsX[3] = (float)width * (float)-0.5;
  this->vertsY[3] = (float)width * (float)0.25;
  this->vertsZ[3] = 0.0;
  this->vertsX[4] = 0.0;
  this->vertsY[4] = 0.0;
  this->vertsZ[4] = v5;
  this->bounds.b[0].x = (float)width * (float)-0.5;
  this->bounds.b[0].y = (float)width * (float)-0.5;
  this->bounds.b[0].z = -v5;
  this->bounds.b[1].x = (float)width * (float)0.5;
  this->bounds.b[1].y = (float)width * (float)0.25;
  this->bounds.b[1].z = v5;
  idTraceModel::CalculateInsetSphereRadius(this);
  v6 = this->vertsX[1];
  v7 = this->vertsZ[2];
  v8 = idMath::FLT_SMALLEST_NON_DENORMAL;
  this->polyPlaneW[0] = v9;
  this->polyPlaneW[2] = v9;
  this->polyPlaneW[3] = v9;
  this->polyPlaneW[5] = v9;
  v10 = (float)((float)v7 - this->vertsZ[0]);
  v11 = (float)((float)((float)((float)v7 - this->vertsZ[0]) * (float)((float)v6 - this->vertsX[0]))
              - (float)((float)(this->vertsZ[1] - this->vertsZ[0]) * (float)(this->vertsX[2] - this->vertsX[0])));
  v12 = (float)((float)((float)(this->vertsY[2] - this->vertsY[0]) * (float)(this->vertsZ[1] - this->vertsZ[0]))
              - (float)((float)((float)v7 - this->vertsZ[0]) * (float)(this->vertsY[1] - this->vertsY[0])));
  v13 = (float)((float)((float)(this->vertsY[1] - this->vertsY[0]) * (float)(this->vertsX[2] - this->vertsX[0]))
              - (float)((float)(this->vertsY[2] - this->vertsY[0]) * (float)((float)v6 - this->vertsX[0])));
  _FP13 = (float)((float)((float)((float)v13 * (float)v13)
                        + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                - (float)v8);
  __asm { fsel      f3, f13, f2, f0 }
  v16 = __frsqrte(_FP3);
  v18 = (float)((float)((float)(this->vertsY[3] - this->vertsY[0]) * (float)v10)
              - (float)((float)(this->vertsZ[3] - this->vertsZ[0]) * (float)(this->vertsY[2] - this->vertsY[0])));
  v19 = (float)((float)((float)(this->vertsZ[3] - this->vertsZ[0]) * (float)(this->vertsX[2] - this->vertsX[0]))
              - (float)((float)v10 * (float)(this->vertsX[3] - this->vertsX[0])));
  v20 = (float)((float)-(float)((float)((float)((float)v16
                                              * (float)((float)((float)((float)v13 * (float)v13)
                                                              + (float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v11 * (float)v11)))
                                                      * (float)0.5))
                                      * (float)v16)
                              - (float)1.5)
              * (float)v16);
  v17 = (float)((float)((float)(this->vertsY[2] - this->vertsY[0]) * (float)(this->vertsX[3] - this->vertsX[0]))
              - (float)((float)(this->vertsY[3] - this->vertsY[0]) * (float)(this->vertsX[2] - this->vertsX[0])));
  v21 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                              * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                      * (float)v20)
                                                                              - (float)1.5)
                                                              * (float)v20)
                                                      * (float)((float)((float)((float)v13 * (float)v13)
                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v11 * (float)v11)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v20
                                                                                      * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                                                                                              * (float)0.5))
                                                                              * (float)v20)
                                                                      - (float)1.5)
                                                      * (float)v20))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v20
                                                              * (float)((float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)((float)v12 * (float)v12)
                                                                                      + (float)((float)v11 * (float)v11)))
                                                                      * (float)0.5))
                                                      * (float)v20)
                                              - (float)1.5)
                              * (float)v20))
              * (float)v12);
  this->polyPlaneX[0] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                              * (float)v20)
                                                                                      - (float)1.5)
                                                                      * (float)v20)
                                                              * (float)((float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)((float)v12 * (float)v12)
                                                                                      + (float)((float)v11 * (float)v11)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                                              * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                      * (float)v20)
                                                                              - (float)1.5)
                                                              * (float)v20))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v20
                                                                      * (float)((float)((float)((float)v13 * (float)v13)
                                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                                              + (float)((float)v11 * (float)v11)))
                                                                              * (float)0.5))
                                                              * (float)v20)
                                                      - (float)1.5)
                                      * (float)v20))
                      * (float)v12;
  v22 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                              * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                      * (float)v20)
                                                                              - (float)1.5)
                                                              * (float)v20)
                                                      * (float)((float)((float)((float)v13 * (float)v13)
                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v11 * (float)v11)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v20
                                                                                      * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                                                                                              * (float)0.5))
                                                                              * (float)v20)
                                                                      - (float)1.5)
                                                      * (float)v20))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v20
                                                              * (float)((float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)((float)v12 * (float)v12)
                                                                                      + (float)((float)v11 * (float)v11)))
                                                                      * (float)0.5))
                                                      * (float)v20)
                                              - (float)1.5)
                              * (float)v20))
              * (float)v13);
  this->polyPlaneZ[0] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                              * (float)v20)
                                                                                      - (float)1.5)
                                                                      * (float)v20)
                                                              * (float)((float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)((float)v12 * (float)v12)
                                                                                      + (float)((float)v11 * (float)v11)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                                              * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                      * (float)v20)
                                                                              - (float)1.5)
                                                              * (float)v20))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v20
                                                                      * (float)((float)((float)((float)v13 * (float)v13)
                                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                                              + (float)((float)v11 * (float)v11)))
                                                                              * (float)0.5))
                                                              * (float)v20)
                                                      - (float)1.5)
                                      * (float)v20))
                      * (float)v13;
  this->polyPlaneZ[2] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                              * (float)v20)
                                                                                      - (float)1.5)
                                                                      * (float)v20)
                                                              * (float)((float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)((float)v12 * (float)v12)
                                                                                      + (float)((float)v11 * (float)v11)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                                              * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                      * (float)v20)
                                                                              - (float)1.5)
                                                              * (float)v20))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v20
                                                                      * (float)((float)((float)((float)v13 * (float)v13)
                                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                                              + (float)((float)v11 * (float)v11)))
                                                                              * (float)0.5))
                                                              * (float)v20)
                                                      - (float)1.5)
                                      * (float)v20))
                      * (float)v13;
  this->polyPlaneX[3] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                              * (float)v20)
                                                                                      - (float)1.5)
                                                                      * (float)v20)
                                                              * (float)((float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)((float)v12 * (float)v12)
                                                                                      + (float)((float)v11 * (float)v11)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                                              * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                      * (float)v20)
                                                                              - (float)1.5)
                                                              * (float)v20))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v20
                                                                      * (float)((float)((float)((float)v13 * (float)v13)
                                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                                              + (float)((float)v11 * (float)v11)))
                                                                              * (float)0.5))
                                                              * (float)v20)
                                                      - (float)1.5)
                                      * (float)v20))
                      * (float)v12;
  v23 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                              * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                      * (float)v20)
                                                                              - (float)1.5)
                                                              * (float)v20)
                                                      * (float)((float)((float)((float)v13 * (float)v13)
                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v11 * (float)v11)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v20
                                                                                      * (float)((float)((float)((float)v13 * (float)v13) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                                                                                              * (float)0.5))
                                                                              * (float)v20)
                                                                      - (float)1.5)
                                                      * (float)v20))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v20
                                                              * (float)((float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)((float)v12 * (float)v12)
                                                                                      + (float)((float)v11 * (float)v11)))
                                                                      * (float)0.5))
                                                      * (float)v20)
                                              - (float)1.5)
                              * (float)v20))
              * (float)v11);
  this->polyPlaneY[0] = v23;
  this->polyPlaneY[2] = v23;
  this->polyPlaneY[3] = v23;
  this->polyPlaneY[5] = v23;
  this->polyPlaneX[2] = -v21;
  this->polyPlaneZ[3] = -v22;
  this->polyPlaneX[5] = -v21;
  this->polyPlaneZ[5] = -v22;
  _FP6 = (float)((float)((float)((float)v19 * (float)v19)
                       + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f5, f6, f7, f13 }
  this->polyPlaneW[1] = v9;
  this->polyPlaneW[4] = v9;
  v26 = __frsqrte(_FP5);
  v27 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26
                                                                                      * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
                                                                                              * (float)0.5))
                                                                              * (float)v26)
                                                                      - (float)1.5)
                                                      * (float)v26)
                                              * (float)((float)((float)((float)v19 * (float)v19)
                                                              + (float)((float)((float)v18 * (float)v18)
                                                                      + (float)((float)v17 * (float)v17)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v26
                                                                              * (float)((float)((float)((float)v19 * (float)v19)
                                                                                              + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
                                                                                      * (float)0.5))
                                                                      * (float)v26)
                                                              - (float)1.5)
                                              * (float)v26))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v26
                                                      * (float)((float)((float)((float)v19 * (float)v19)
                                                                      + (float)((float)((float)v18 * (float)v18)
                                                                              + (float)((float)v17 * (float)v17)))
                                                              * (float)0.5))
                                              * (float)v26)
                                      - (float)1.5)
                      * (float)v26));
  v28 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5)) * (float)v26) - (float)1.5)
                                                                                              * (float)v26)
                                                                                      * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5)) * (float)v26) - (float)1.5)
                                                                                      * (float)v26))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v26
                                                                                              * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5))
                                                                                      * (float)v26)
                                                                              - (float)1.5)
                                                              * (float)v26))
                                              * (float)((float)((float)((float)v19 * (float)v19)
                                                              + (float)((float)((float)v18 * (float)v18)
                                                                      + (float)((float)v17 * (float)v17)))
                                                      * (float)0.5))
                                      * (float)v27)
                              - (float)1.5)
              * (float)v27);
  v29 = (float)((float)v17
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5)) * (float)v26) - (float)1.5) * (float)v26)
                                                                                              * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5)) * (float)v26) - (float)1.5)
                                                                                              * (float)v26))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5))
                                                                                              * (float)v26)
                                                                                      - (float)1.5)
                                                                      * (float)v26))
                                                      * (float)((float)((float)((float)v19 * (float)v19)
                                                                      + (float)((float)((float)v18 * (float)v18)
                                                                              + (float)((float)v17 * (float)v17)))
                                                              * (float)0.5))
                                              * (float)v27)
                                      - (float)1.5)
                      * (float)v27));
  this->polyPlaneZ[1] = v29;
  v30 = (float)((float)v19 * (float)v28);
  this->polyPlaneY[1] = (float)v19 * (float)v28;
  v31 = (float)((float)v18 * (float)v28);
  this->polyPlaneX[1] = v31;
  this->polyPlaneX[4] = v31;
  this->polyPlaneY[4] = (float)v19 * (float)v28;
  this->polyPlaneZ[4] = -v29;
  v32 = v29;
  v33 = this->edges[this->polyEdges[0][0] & 0x7F].v[0];
  v34 = this->polyPlaneY[2];
  v35 = v31;
  v36 = this->polyPlaneZ[2];
  v37 = v30;
  v38 = this->polyPlaneX[2];
  v39 = this->polyPlaneZ[3];
  v40 = this->polyPlaneX[3];
  v41 = this->polyPlaneY[3];
  v42 = this->polyPlaneZ[4];
  this->polyPlaneW[0] = -(float)((float)(this->polyPlaneY[0] * this->vertsY[v33])
                               + (float)((float)(this->polyPlaneX[0]
                                               * *(float *)((char *)this->vertsX + __ROL4__(v33, 2)))
                                       + (float)(this->polyPlaneZ[0] * this->vertsZ[v33])));
  v43 = this->polyPlaneY[4];
  v44 = this->polyPlaneZ[5];
  v45 = this->edges[this->polyEdges[1][0] & 0x7F].v[0];
  this->polyPlaneW[1] = -(float)((float)((float)v37 * this->vertsY[v45])
                               + (float)((float)((float)v35 * *(float *)((char *)this->vertsX + __ROL4__(v45, 2)))
                                       + (float)((float)v32 * this->vertsZ[v45])));
  v46 = this->edges[this->polyEdges[2][0] & 0x7F].v[0];
  this->polyPlaneW[2] = -(float)((float)((float)v34 * this->vertsY[v46])
                               + (float)((float)((float)v38 * *(float *)((char *)this->vertsX + __ROL4__(v46, 2)))
                                       + (float)((float)v36 * this->vertsZ[v46])));
  v47 = this->edges[this->polyEdges[3][0] & 0x7F].v[0];
  this->polyPlaneW[3] = -(float)((float)((float)v41 * this->vertsY[v47])
                               + (float)((float)((float)v40 * *(float *)((char *)this->vertsX + __ROL4__(v47, 2)))
                                       + (float)((float)v39 * this->vertsZ[v47])));
  v48 = this->edges[this->polyEdges[4][0] & 0x7F].v[0];
  v49 = this->polyPlaneX[5];
  v50 = this->polyPlaneY[5];
  this->polyPlaneW[4] = -(float)((float)((float)v43 * this->vertsY[v48])
                               + (float)((float)((float)v35 * *(float *)((char *)this->vertsX + __ROL4__(v48, 2)))
                                       + (float)((float)v42 * this->vertsZ[v48])));
  v51 = this->edges[this->polyEdges[5][0] & 0x7F].v[0];
  this->polyPlaneW[5] = -(float)((float)((float)v50 * this->vertsY[v51])
                               + (float)((float)((float)v49 * *(float *)((char *)this->vertsX + __ROL4__(v51, 2)))
                                       + (float)((float)v44 * this->vertsZ[v51])));
  idTraceModel::GenerateEdgeNormals(this);
}


// ========================================================================
// ?SetupPolygon@idTraceModel@@QAAXPBVidVec3@@H@Z
// EA  : 0x82F28F40
// RVA : 0x00F28F40
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::SetupPolygon(idTraceModel *this, const idVec3 *v, unsigned int count)
{
  unsigned int numVerts; // r9
  idBounds *p_bounds; // r11
  double z; // fp4
  double x; // fp11
  double y; // fp7
  double v10; // fp10
  double v11; // fp8
  double v12; // fp9
  double v15; // fp12
  double v16; // fp6
  double v17; // fp0
  double v18; // fp13
  double v19; // fp5
  double v20; // fp2
  unsigned int v21; // r7
  __int64 v22; // r9
  double v23; // fp12
  double v24; // fp0
  double v25; // fp13
  float *vertsY; // r10
  unsigned int v27; // r6
  unsigned int v28; // r7
  double v29; // fp9
  idTraceModel *v42; // r3

  this->numVerts = count;
  this->type = TRM_POLYGON;
  if ( 3 * count > 0x20 )
  {
    idLib::Printf(fmt: "WARNING: idTraceModel::SetupPolygon: too many vertices\n");
    this->numVerts = 10;
  }
  numVerts = this->numVerts;
  this->numPolys = 2;
  this->numEdges = numVerts;
  this->maxPolyEdges = numVerts;
  p_bounds = &this->bounds;
  this->numPolyEdges[0] = numVerts;
  this->numPolyEdges[1] = numVerts;
  z = v->z;
  x = v->x;
  y = v->y;
  v10 = (float)((float)((float)(v[1].z - v->z) * (float)(v[2].x - v->x))
              - (float)((float)(v[2].z - v->z) * (float)(v[1].x - v->x)));
  v11 = (float)((float)((float)(v[2].y - v->y) * (float)(v[1].x - v->x))
              - (float)((float)(v[1].y - v->y) * (float)(v[2].x - v->x)));
  v12 = (float)((float)((float)(v[1].y - v->y) * (float)(v[2].z - v->z))
              - (float)((float)(v[1].z - v->z) * (float)(v[2].y - v->y)));
  _FP2 = (float)((float)((float)((float)v11 * (float)v11)
                       + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f2, f3, f13 }
  v15 = __frsqrte(_FP1);
  v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15)
                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                              + (float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v10 * (float)v10)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                                                              + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                                                                                      * (float)0.5))
                                                                      * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v10 * (float)v10)))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  this->polyPlaneX[0] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15) * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15)
                                                                                              - (float)1.5)
                                                                              * (float)v15))
                                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                                              + (float)((float)((float)v12 * (float)v12)
                                                                                      + (float)((float)v10 * (float)v10)))
                                                                      * (float)0.5))
                                                      * (float)v16)
                                              - (float)1.5)
                              * (float)v16)
                      * (float)v12;
  v17 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15)
                                                                                              * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                              * (float)v15)
                                                                                      - (float)1.5)
                                                                      * (float)v15))
                                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v10 * (float)v10)))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16)
              * (float)v10);
  this->polyPlaneY[0] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15) * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15)
                                                                                              - (float)1.5)
                                                                              * (float)v15))
                                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                                              + (float)((float)((float)v12 * (float)v12)
                                                                                      + (float)((float)v10 * (float)v10)))
                                                                      * (float)0.5))
                                                      * (float)v16)
                                              - (float)1.5)
                              * (float)v16)
                      * (float)v10;
  v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15)
                                                                                              * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                              * (float)v15)
                                                                                      - (float)1.5)
                                                                      * (float)v15))
                                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v10 * (float)v10)))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16)
              * (float)v11);
  this->polyPlaneZ[0] = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15) * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15)
                                                                                              - (float)1.5)
                                                                              * (float)v15))
                                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                                              + (float)((float)((float)v12 * (float)v12)
                                                                                      + (float)((float)v10 * (float)v10)))
                                                                      * (float)0.5))
                                                      * (float)v16)
                                              - (float)1.5)
                              * (float)v16)
                      * (float)v11;
  this->polyPlaneW[0] = -(float)((float)((float)z * (float)v18)
                               + (float)((float)((float)y * (float)v17)
                                       + (float)((float)x
                                               * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15) * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15)) - (float)1.5) * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15))
                                                                                               * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                       * (float)v16)
                                                                               - (float)1.5)
                                                               * (float)v16)
                                                       * (float)v12))));
  v19 = v->x;
  v20 = (float)((float)(v->y * (float)v17)
              + (float)(v->z
                      * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15) * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                      * (float)v15))
                                                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                                              + (float)((float)v10 * (float)v10)))
                                                                              * (float)0.5))
                                                              * (float)v16)
                                                      - (float)1.5)
                                      * (float)v16)
                              * (float)v11)));
  this->polyPlaneX[1] = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15) * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15))
                                                                                               - (float)1.5)
                                                                               * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                       * (float)v15))
                                                                       * (float)((float)((float)((float)v11 * (float)v11)
                                                                                       + (float)((float)((float)v12 * (float)v12)
                                                                                               + (float)((float)v10 * (float)v10)))
                                                                               * (float)0.5))
                                                               * (float)v16)
                                                       - (float)1.5)
                                       * (float)v16)
                               * (float)v12);
  this->polyPlaneY[1] = -v17;
  this->polyPlaneZ[1] = -v18;
  this->polyPlaneW[1] = (float)((float)v19
                              * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15) * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15)) - (float)1.5)
                                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15))
                                                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                                                              + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                                                                                      * (float)0.5))
                                                                      * (float)v16)
                                                              - (float)1.5)
                                              * (float)v16)
                                      * (float)v12))
                      + (float)v20;
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  LODWORD(v22) = 0;
  this->bounds.b[0].x = 1.0e30;
  v21 = 1;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  this->bounds.b[1].z = -1.0e30;
  *(float *)&v22 = vec3_origin.y;
  v23 = vec3_origin.x;
  v24 = vec3_origin.z;
  v25 = vec3_origin.y;
  if ( this->numVerts != 0 )
  {
    HIDWORD(v22) = (char *)v - 4;
    vertsY = this->vertsY;
    do
    {
      v27 = this->numVerts;
      *(vertsY - 32) = *(float *)(HIDWORD(v22) + 4);
      v28 = v21 >= v27 ? 0 : v21;
      *vertsY = *(float *)(HIDWORD(v22) + 8);
      v29 = *(float *)(HIDWORD(v22) + 12);
      *((_WORD *)vertsY + 609) = v28;
      v21 = v28 + 1;
      vertsY[32] = v29;
      *((_WORD *)vertsY + 608) = v22;
      this->polyEdges[0][v22] = v22 & 0x7F;
      this->polyEdges[1][v22] = (this->numVerts - v22 - 1) & 0x7F | 0x80;
      LODWORD(v22) = v22 + 1;
      _FP10 = (float)(p_bounds->b[0].x - *(vertsY - 32));
      _FP31 = (float)(this->bounds.b[0].y - *vertsY);
      _FP1 = (float)(*(vertsY - 32) - this->bounds.b[1].x);
      _FP29 = (float)(*vertsY - this->bounds.b[1].y);
      _FP30 = (float)(this->bounds.b[0].z - vertsY[32]);
      _FP28 = (float)(vertsY[32] - this->bounds.b[1].z);
      ++vertsY;
      __asm { fsel      f10, f10, f3, f5 }
      p_bounds->b[0].x = _FP10;
      __asm { fsel      f4, f31, f8, f4 }
      this->bounds.b[0].y = _FP4;
      __asm { fsel      f5, f1, f3, f2 }
      this->bounds.b[1].x = _FP5;
      __asm { fsel      f3, f29, f8, f11 }
      this->bounds.b[1].y = _FP3;
      __asm { fsel      f4, f30, f7, f9 }
      this->bounds.b[0].z = _FP4;
      __asm { fsel      f2, f28, f7, f6 }
      this->bounds.b[1].z = _FP2;
      v23 = (float)(*(float *)(HIDWORD(v22) + 4) + (float)v23);
      v25 = (float)(*(float *)(HIDWORD(v22) + 8) + (float)v25);
      HIDWORD(v22) += 12;
      v24 = (float)(*(float *)HIDWORD(v22) + (float)v24);
    }
    while ( (unsigned int)v22 < this->numVerts );
  }
  LODWORD(v22) = this->numVerts;
  this->offset.x = (float)((float)1.0 / (float)v22) * (float)v23;
  this->offset.y = (float)v25 * (float)((float)1.0 / (float)v22);
  this->offset.z = (float)v24 * (float)((float)1.0 / (float)v22);
  idTraceModel::CalculateInsetSphereRadius(this);
  this->isConvex = false;
  idTraceModel::GenerateEdgeNormals(this: v42);
  idTraceModel::ClearUnused(this);
}


// ========================================================================
// ?ExtendPolygonToVolume@idTraceModel@@AAAXABVidVec3@@@Z
// EA  : 0x82F29298
// RVA : 0x00F29298
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::ExtendPolygonToVolume(idTraceModel *this, const idVec3 *dir)
{
  int numEdges; // r7
  signed int numVerts; // r6
  float *p_bounds; // r11
  int v6; // r9
  int v7; // ctr
  _WORD *v8; // r28
  int v9; // r27
  float *v10; // r5
  unsigned __int8 *v11; // r3
  float *v12; // r10
  int v13; // r30
  double v14; // fp3
  int v15; // r20
  double v16; // fp2
  int v17; // r30
  double v18; // fp9
  double v19; // fp1
  double v20; // fp5
  double v21; // fp11
  double v22; // fp2
  double v25; // fp10
  double v26; // fp7
  double v27; // fp0
  double v28; // fp10
  double v29; // fp3
  double v30; // fp2
  double v46; // fp2
  double v48; // fp8
  idTraceModel *v57; // r3

  numEdges = this->numEdges;
  numVerts = this->numVerts;
  this->type = TRM_POLYGONVOLUME;
  this->numEdges = 3 * numEdges;
  this->numVerts = 2 * numVerts;
  p_bounds = (float *)&this->bounds;
  this->numPolys = numEdges + 2;
  this->bounds.b[0].z = 1.0e30;
  v6 = 0;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  if ( numEdges > 0 )
  {
    v7 = numEdges;
    v8 = (_WORD *)&this->numPolyEdges[numEdges + 15] + 1;
    v9 = 2 * numEdges;
    v10 = &this->vertsX[numVerts];
    v11 = &this->polyEdges[1][3];
    v12 = &this->vertsY[31];
    do
    {
      *v10 = dir->x + *(v12 - 63);
      v13 = (v6 + 1) % numVerts;
      this->vertsY[numVerts + v6] = dir->y + *(v12 - 31);
      this->vertsZ[numVerts + v6] = dir->z + v12[1];
      this->edges[numEdges + v6].v[0] = v6 + numVerts;
      v8 += 2;
      *v8 = v13 + numVerts;
      this->edges[v9 + v6].v[1] = v6 + numVerts;
      this->edges[2 * numEdges + v6].v[0] = v6;
      this->polyEdges[1][v6] = (numEdges - v6 + numVerts - 1) & 0x7F | 0x80;
      *((_DWORD *)v12 + 259) = 4;
      v11[14] = (v9 + v6) & 0x7F;
      v11[13] = v6 | 0x80;
      v11[15] = (v6 + numEdges) & 0x7F;
      v11 += 16;
      *v11 = ((v6 + 1) % numEdges + v9) | 0x80;
      __twllei(numVerts, 0);
      __twllei(numEdges, 0);
      v14 = *(v12 - 63);
      v15 = v13 + 32;
      v16 = this->vertsX[v13];
      v17 = v13 + 64;
      __twlgei(numVerts & ~(__ROL4__(v6 + 1, 1) - 1), 0xFFFFFFFF);
      __twlgei(numEdges & ~(__ROL4__(v6 + 1, 1) - 1), 0xFFFFFFFF);
      v18 = v12[1];
      v19 = *(v12 - 31);
      v20 = (float)((float)(dir->x * (float)(this->vertsX[v15] - *(v12 - 31)))
                  - (float)(dir->y * (float)((float)v16 - (float)v14)));
      v21 = (float)((float)(dir->z * (float)((float)v16 - (float)v14))
                  - (float)(dir->x * (float)(this->vertsX[v17] - v12[1])));
      v22 = (float)((float)(dir->y * (float)(this->vertsX[v17] - v12[1]))
                  - (float)(dir->z * (float)(this->vertsX[v15] - *(v12 - 31))));
      _FP6 = (float)((float)((float)((float)v20 * (float)v20)
                           + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f0, f6, f7, f0 }
      v25 = __frsqrte(_FP0);
      v26 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25
                                                                                          * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v25)
                                                                          - (float)1.5)
                                                          * (float)v25)
                                                  * (float)((float)((float)((float)v20 * (float)v20)
                                                                  + (float)((float)((float)v22 * (float)v22)
                                                                          + (float)((float)v21 * (float)v21)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v25
                                                                                  * (float)((float)((float)((float)v20 * (float)v20)
                                                                                                  + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)))
                                                                                          * (float)0.5))
                                                                          * (float)v25)
                                                                  - (float)1.5)
                                                  * (float)v25))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v25
                                                          * (float)((float)((float)((float)v20 * (float)v20)
                                                                          + (float)((float)((float)v22 * (float)v22)
                                                                                  + (float)((float)v21 * (float)v21)))
                                                                  * (float)0.5))
                                                  * (float)v25)
                                          - (float)1.5)
                          * (float)v25));
      v27 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v25) - (float)1.5)
                                                                                                  * (float)v25)
                                                                                          * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v25) - (float)1.5)
                                                                                          * (float)v25))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v25
                                                                                                  * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5))
                                                                                          * (float)v25)
                                                                                  - (float)1.5)
                                                                  * (float)v25))
                                                  * (float)((float)((float)((float)v20 * (float)v20)
                                                                  + (float)((float)((float)v22 * (float)v22)
                                                                          + (float)((float)v21 * (float)v21)))
                                                          * (float)0.5))
                                          * (float)v26)
                                  - (float)1.5)
                  * (float)v26);
      v28 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v25) - (float)1.5) * (float)v25)
                                                                                                  * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v25) - (float)1.5)
                                                                                                  * (float)v25))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5))
                                                                                                  * (float)v25)
                                                                                          - (float)1.5)
                                                                          * (float)v25))
                                                          * (float)((float)((float)((float)v20 * (float)v20)
                                                                          + (float)((float)((float)v22 * (float)v22)
                                                                                  + (float)((float)v21 * (float)v21)))
                                                                  * (float)0.5))
                                                  * (float)v26)
                                          - (float)1.5)
                          * (float)v26)
                  * (float)v20);
      v12[163] = v28;
      v12[147] = (float)v27 * (float)v21;
      v12[131] = (float)v27 * (float)v22;
      v12[179] = -(float)((float)((float)v14 * (float)((float)v27 * (float)v22))
                        + (float)((float)((float)v19 * (float)((float)v27 * (float)v21))
                                + (float)((float)v18 * (float)v28)));
      v29 = *(v12 - 63);
      v30 = *(v12 - 31);
      _FP6 = (float)(p_bounds[2] - *++v12);
      _FP5 = (float)(*p_bounds - (float)v29);
      _FP4 = (float)(p_bounds[1] - (float)v30);
      _FP31 = (float)((float)v30 - p_bounds[4]);
      _FP29 = (float)(*v12 - p_bounds[5]);
      _FP30 = (float)((float)v29 - p_bounds[3]);
      __asm { fsel      f7, f6, f0, f7 }
      p_bounds[2] = _FP7;
      __asm { fsel      f6, f5, f3, f11 }
      *p_bounds = _FP6;
      __asm { fsel      f5, f4, f2, f1 }
      p_bounds[1] = _FP5;
      __asm { fsel      f4, f31, f2, f10 }
      p_bounds[4] = _FP4;
      __asm { fsel      f2, f29, f0, f9 }
      p_bounds[5] = _FP2;
      __asm { fsel      f3, f30, f3, f8 }
      p_bounds[3] = _FP3;
      _FP7 = (float)((float)_FP6 - *v10);
      _FP10 = (float)(v10[64] - (float)_FP2);
      __asm { fsel      f5, f7, f1, f8 }
      v46 = v10[32];
      _FP3 = (float)(*v10 - (float)_FP3);
      v48 = p_bounds[1];
      _FP7 = (float)(p_bounds[2] - v10[64]);
      *p_bounds = _FP5;
      _FP31 = (float)((float)v48 - (float)v46);
      _FP5 = (float)((float)v46 - (float)_FP4);
      ++v6;
      ++v10;
      __asm { fsel      f3, f3, f1, f9 }
      p_bounds[3] = _FP3;
      __asm { fsel      f1, f10, f0, f11 }
      p_bounds[5] = _FP1;
      __asm { fsel      f0, f7, f0, f6 }
      p_bounds[2] = _FP0;
      __asm { fsel      f11, f31, f2, f8 }
      p_bounds[1] = _FP11;
      __asm { fsel      f10, f5, f2, f4 }
      p_bounds[4] = _FP10;
      --v7;
    }
    while ( v7 != 0 );
  }
  this->polyPlaneW[1] = -(float)((float)(this->polyPlaneX[1] * this->vertsX[numEdges])
                               + (float)((float)(this->polyPlaneZ[1] * this->vertsZ[numEdges])
                                       + (float)(this->polyPlaneY[1] * this->vertsY[numEdges])));
  idTraceModel::CalculateInsetSphereRadius(this);
  this->isConvex = true;
  idTraceModel::GenerateEdgeNormals(this: v57);
  idTraceModel::ClearUnused(this);
}


// ========================================================================
// ?SetupPolygonVolume@idTraceModel@@QAAXPBVidVec3@@HABV2@@Z
// EA  : 0x82F296B8
// RVA : 0x00F296B8
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::SetupPolygonVolume(
        idTraceModel *this,
        const idVec3 *v,
        unsigned int count,
        const idVec3 *dir)
{
  idTraceModel::SetupPolygon(this, v, count);
  idTraceModel::ExtendPolygonToVolume(this, dir);
}


// ========================================================================
// ?Shrink@idTraceModel@@QAAXM@Z
// EA  : 0x82F29700
// RVA : 0x00F29700
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::Shrink(idTraceModel *this, double m)
{
  unsigned int v4; // r7
  unsigned __int8 *v5; // r6
  double v6; // fp0
  unsigned int v7; // r10
  int v8; // r9
  traceModelEdge_t *v9; // r11
  int v10; // r10
  int v11; // r9
  int v12; // r4
  int v13; // r3
  int v14; // r10
  double v15; // fp10
  int v16; // r9
  double v17; // fp5
  double v18; // fp2
  double v21; // fp3
  double v22; // fp12
  double v23; // fp4
  double v24; // fp3
  double v25; // fp11
  double v26; // fp12
  double v27; // fp10
  int v28; // r10
  int v29; // r10
  int v30; // r11
  float *v31; // r11
  __int64 v32; // r9
  int i; // ctr
  unsigned int v34; // r6
  unsigned int *numPolyEdges; // r3
  unsigned __int8 *v36; // r5
  unsigned int v37; // r10
  unsigned int j; // r11
  unsigned int v39; // r8
  int v40; // r7
  int v41; // r9
  int v42; // r8
  unsigned int v43; // r27
  int v44; // r29
  int *v45; // r28
  _DWORD *v46; // r26
  float *vertsZ; // r30
  double v48; // fp10
  int v49; // r9
  int v50; // r10
  double v51; // fp0
  double v52; // fp13
  double v53; // fp12
  double v54; // fp3
  int v55; // r11
  double v56; // fp11
  double v57; // fp7
  double v58; // fp11
  double v59; // fp7
  double v60; // fp26
  bool v61; // r11
  double v62; // fp8
  double v63; // fp7
  double v64; // fp6
  double v65; // fp1
  double v66; // fp1
  double v67; // fp3
  double v68; // fp9
  double v69; // fp5
  double v70; // fp4
  double v71; // fp11
  double v72; // fp10
  double v73; // fp9
  double v74; // fp11
  double v75; // fp7
  double v76; // fp13
  int v77; // r10
  int v78; // r11
  double v79; // fp0
  float v80; // [sp+50h] [-930h]
  float v81; // [sp+54h] [-92Ch]
  float v82; // [sp+58h] [-928h]
  float v83; // [sp+5Ch] [-924h]
  float v84; // [sp+70h] [-910h]
  float v85; // [sp+74h] [-90Ch]
  float v86; // [sp+78h] [-908h] BYREF
  float v87; // [sp+7Ch] [-904h]
  _BYTE v88[128]; // [sp+80h] [-900h] BYREF
  _DWORD v89[524]; // [sp+100h] [-880h] BYREF

  if ( this->type == TRM_POLYGON )
  {
    v4 = 0;
    if ( this->numEdges != 0 )
    {
      v5 = this->polyEdges[0];
      v6 = idMath::FLT_SMALLEST_NON_DENORMAL;
      do
      {
        v7 = v5[v4];
        v8 = (v7 >> 6) & 2;
        v9 = &this->edges[v7 & 0x7F];
        v10 = *(unsigned __int16 *)((char *)v9->v + ((~v7 >> 6) & 2));
        v11 = *(unsigned __int16 *)((char *)v9->v + v8);
        v12 = v10 + 64;
        v13 = v11 + 64;
        v15 = (float)(this->vertsY[v11] - this->vertsY[v10]);
        v14 = __ROL4__(v10, 2);
        v16 = __ROL4__(v11, 2);
        v17 = (float)(this->vertsX[v13] - this->vertsX[v12]);
        v18 = (float)(*(float *)((char *)this->vertsX + v16) - *(float *)((char *)this->vertsX + v14));
        _FP7 = (float)((float)((float)((float)v18 * (float)v18)
                             + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15)))
                     - (float)v6);
        __asm { fsel      f4, f7, f11, f0 }
        v21 = __frsqrte(_FP4);
        v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                            * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                    * (float)v21)
                                                                            - (float)1.5)
                                                            * (float)v21)
                                                    * (float)((float)((float)((float)v18 * (float)v18)
                                                                    + (float)((float)((float)v17 * (float)v17)
                                                                            + (float)((float)v15 * (float)v15)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v21
                                                                                    * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15)))
                                                                                            * (float)0.5))
                                                                            * (float)v21)
                                                                    - (float)1.5)
                                                    * (float)v21))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v21
                                                            * (float)((float)((float)((float)v18 * (float)v18)
                                                                            + (float)((float)((float)v17 * (float)v17)
                                                                                    + (float)((float)v15 * (float)v15)))
                                                                    * (float)0.5))
                                                    * (float)v21)
                                            - (float)1.5)
                            * (float)v21));
        v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21)
                                                                                            * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                            * (float)v21))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                            * (float)v21)
                                                                                    - (float)1.5)
                                                                    * (float)v21))
                                                    * (float)((float)((float)((float)v18 * (float)v18)
                                                                    + (float)((float)((float)v17 * (float)v17)
                                                                            + (float)((float)v15 * (float)v15)))
                                                            * (float)0.5))
                                            * (float)v22)
                                    - (float)1.5)
                    * (float)v22);
        v25 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v21)
                                                                                            - (float)1.5)
                                                                            * (float)v21))
                                                            * (float)((float)((float)((float)v18 * (float)v18)
                                                                            + (float)((float)((float)v17 * (float)v17)
                                                                                    + (float)((float)v15 * (float)v15)))
                                                                    * (float)0.5))
                                                    * (float)v22)
                                            - (float)1.5)
                            * (float)v22)
                    * (float)v15);
        v24 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v21)
                                                                                            - (float)1.5)
                                                                            * (float)v21))
                                                            * (float)((float)((float)((float)v18 * (float)v18)
                                                                            + (float)((float)((float)v17 * (float)v17)
                                                                                    + (float)((float)v15 * (float)v15)))
                                                                    * (float)0.5))
                                                    * (float)v22)
                                            - (float)1.5)
                            * (float)v22)
                    * (float)((float)((float)v18 * (float)v18)
                            + (float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))));
        v26 = (float)((float)v23
                    * (float)(*(float *)((char *)this->vertsX + v16) - *(float *)((char *)this->vertsX + v14)));
        v27 = (float)((float)v23 * (float)(this->vertsX[v13] - this->vertsX[v12]));
        if ( v24 >= (float)((float)m * (float)2.0) )
        {
          v28 = __ROL4__(v9->v[0], 2);
          *(float *)((char *)this->vertsX + v28) = *(float *)((char *)this->vertsX + v28)
                                                 - (float)((float)v26 * (float)m);
          this->vertsY[v9->v[0]] = this->vertsY[v9->v[0]] - (float)((float)v25 * (float)m);
          this->vertsZ[v9->v[0]] = this->vertsZ[v9->v[0]] - (float)((float)v27 * (float)m);
          v29 = __ROL4__(v9->v[1], 2);
          *(float *)((char *)this->vertsX + v29) = (float)((float)v26 * (float)m)
                                                 + *(float *)((char *)this->vertsX + v29);
          this->vertsY[v9->v[1]] = this->vertsY[v9->v[1]] + (float)((float)v25 * (float)m);
          v30 = v9->v[1] + 64;
          this->vertsX[v30] = (float)((float)v27 * (float)m) + this->vertsX[v30];
          v6 = idMath::FLT_SMALLEST_NON_DENORMAL;
        }
        ++v4;
      }
      while ( v4 < this->numEdges );
    }
  }
  else
  {
    memset(Dst: v89, Val: 0, Size: 0x800u);
    v31 = &v86;
    LODWORD(v32) = 0;
    for ( i = 16; i != 0; --i )
    {
      v31 += 2;
      *(_QWORD *)v31 = v32;
    }
    v34 = 0;
    if ( this->numPolys != 0 )
    {
      numPolyEdges = this->numPolyEdges;
      v36 = this->polyEdges[0];
      do
      {
        v37 = *numPolyEdges;
        *((float *)numPolyEdges - 80) = *((float *)numPolyEdges - 80) + (float)m;
        for ( j = 0; j < v37; v89[__ROL4__(v40, 4) + v42] = v34 )
        {
          v39 = v36[j++];
          v40 = this->edges[v39 & 0x7F].v[v39 >> 7];
          v41 = __ROL4__(v40, 2);
          v42 = *(_DWORD *)&v88[v41];
          *(_DWORD *)&v88[v41] = v42 + 1;
        }
        ++v34;
        v36 += 16;
        ++numPolyEdges;
      }
      while ( v34 < this->numPolys );
    }
    v43 = 0;
    if ( this->numVerts != 0 )
    {
      v44 = 0;
      v45 = (int *)v88;
      v46 = v89;
      vertsZ = this->vertsZ;
      do
      {
        v48 = 1.0;
        v49 = *v45;
        v50 = 1;
        v51 = this->polyPlaneX[*v46];
        v52 = this->polyPlaneY[*v46];
        v53 = this->polyPlaneZ[*v46];
        v54 = this->polyPlaneW[*v46];
        if ( *v45 <= 1 )
          goto LABEL_22;
        do
        {
          v55 = v89[v44 + v50];
          v56 = __fabs((float)((float)(this->polyPlaneY[v55] * (float)v52)
                             + (float)((float)(this->polyPlaneX[v55] * (float)v51)
                                     + (float)(this->polyPlaneZ[v55] * (float)v53))));
          if ( v56 < v48 )
          {
            v48 = v56;
            v57 = this->polyPlaneW[v55];
            v85 = this->polyPlaneY[v55];
            v84 = this->polyPlaneX[v55];
            v86 = this->polyPlaneZ[v55];
            v87 = v57;
            v83 = v87;
            v81 = v85;
            v82 = v86;
            v80 = v84;
          }
          ++v50;
        }
        while ( v50 < v49 );
        if ( v48 <= 0.99989998 )
        {
          v60 = -v83;
          v61 = false;
          v62 = (float)((float)(v82 * (float)v52) - (float)(v81 * (float)v53));
          v63 = (float)((float)((float)v53 * v80) - (float)(v82 * (float)v51));
          v64 = (float)((float)(v81 * (float)v51) - (float)((float)v52 * v80));
          v65 = (float)((float)(v82 * (float)v53) + (float)((float)(v80 * (float)v51) + (float)(v81 * (float)v52)));
          v66 = (float)((float)1.0 / (float)-(float)((float)((float)v65 * (float)v65) - (float)1.0));
          v68 = (float)(v80
                      * (float)((float)((float)v60
                                      - (float)-(float)((float)v54
                                                      * (float)((float)(v82 * (float)v53)
                                                              + (float)((float)(v80 * (float)v51)
                                                                      + (float)(v81 * (float)v52)))))
                              * (float)v66));
          v69 = (float)(v81
                      * (float)((float)((float)v60
                                      - (float)-(float)((float)v54
                                                      * (float)((float)(v82 * (float)v53)
                                                              + (float)((float)(v80 * (float)v51)
                                                                      + (float)(v81 * (float)v52)))))
                              * (float)v66));
          v70 = (float)(v82
                      * (float)((float)((float)v60
                                      - (float)-(float)((float)v54
                                                      * (float)((float)(v82 * (float)v53)
                                                              + (float)((float)(v80 * (float)v51)
                                                                      + (float)(v81 * (float)v52)))))
                              * (float)v66));
          v67 = (float)((float)((float)-v54
                              - (float)-(float)(v83
                                              * (float)((float)(v82 * (float)v53)
                                                      + (float)((float)(v80 * (float)v51) + (float)(v81 * (float)v52)))))
                      * (float)v66);
          v71 = (float)((float)((float)v51 * (float)v67) + (float)v68);
          v72 = (float)((float)((float)v52 * (float)v67) + (float)v69);
          if ( __fabs((float)((float)((float)(v82 * (float)v52) - (float)(v81 * (float)v53)) - vec3_origin.x)) <= 0.0000099999997
            && __fabs((float)((float)((float)((float)v53 * v80) - (float)(v82 * (float)v51)) - vec3_origin.y)) <= 0.0000099999997 )
          {
            v61 = __fabs((float)((float)((float)(v81 * (float)v51) - (float)((float)v52 * v80)) - vec3_origin.z)) <= 0.0000099999997;
          }
          if ( v61 )
          {
            v74 = *vertsZ;
            v75 = *(vertsZ - 32);
            *(vertsZ - 64) = *(vertsZ - 64) - (float)((float)v51 * (float)m);
            *(vertsZ - 32) = (float)v75 - (float)((float)v52 * (float)m);
            *vertsZ = (float)v74 - (float)((float)v53 * (float)m);
            idLib::Warning(
              fmt: "WARNING: idTraceModel::Shrink(): Moving vertex %d along normal of polygon because it only has neighboring "
              "polygons that are coplanar to itself",
              v43);
          }
          else
          {
            v76 = 0.0;
            v77 = 1;
            do
            {
              v78 = v89[v44 + v77];
              v79 = __fabs((float)((float)(this->polyPlaneX[v78] * (float)v62)
                                 + (float)((float)(this->polyPlaneZ[v78] * (float)v64)
                                         + (float)(this->polyPlaneY[v78] * (float)v63))));
              if ( v79 > v76 )
              {
                v76 = v79;
                v82 = this->polyPlaneZ[v78];
                v80 = this->polyPlaneX[v78];
                v83 = this->polyPlaneW[v78];
                v81 = this->polyPlaneY[v78];
              }
              ++v77;
            }
            while ( v77 < v49 );
            *(vertsZ - 64) = (float)v71
                           - (float)((float)((float)((float)((float)((float)v71 * v80)
                                                           + (float)((float)((float)v72 * v81)
                                                                   + (float)((float)((float)((float)v53 * (float)v67)
                                                                                   + (float)v70)
                                                                           * v82)))
                                                   - (float)-v83)
                                           / (float)((float)((float)v62 * v80)
                                                   + (float)((float)((float)v63 * v81) + (float)((float)v64 * v82))))
                                   * (float)v62);
            *(vertsZ - 32) = (float)v72
                           - (float)((float)v63
                                   * (float)((float)((float)((float)((float)v71 * v80)
                                                           + (float)((float)((float)v72 * v81)
                                                                   + (float)((float)((float)((float)v53 * (float)v67)
                                                                                   + (float)v70)
                                                                           * v82)))
                                                   - (float)-v83)
                                           / (float)((float)((float)v62 * v80)
                                                   + (float)((float)((float)v63 * v81) + (float)((float)v64 * v82)))));
            v73 = (float)((float)((float)v53 * (float)v67) + (float)v70);
            *vertsZ = (float)v73
                    - (float)((float)v64
                            * (float)((float)((float)((float)((float)v71 * v80)
                                                    + (float)((float)((float)v72 * v81) + (float)((float)v73 * v82)))
                                            - (float)-v83)
                                    / (float)((float)((float)v62 * v80)
                                            + (float)((float)((float)v63 * v81) + (float)((float)v64 * v82)))));
          }
        }
        else
        {
LABEL_22:
          v58 = *vertsZ;
          v59 = *(vertsZ - 32);
          *(vertsZ - 64) = *(vertsZ - 64) - (float)((float)v51 * (float)m);
          *(vertsZ - 32) = (float)v59 - (float)((float)v52 * (float)m);
          *vertsZ = (float)v58 - (float)((float)v53 * (float)m);
          idLib::Warning(
            fmt: "WARNING: idTraceModel::Shrink(): no suitable orthogonal polygon found for vertex %d",
            v43);
        }
        ++v43;
        v46 += 16;
        v44 += 16;
        ++v45;
        ++vertsZ;
      }
      while ( v43 < this->numVerts );
    }
  }
}


// ========================================================================
// ?GetMassProperties@idTraceModel@@QBAXMAAMAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82F29DD8
// RVA : 0x00F29DD8
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::GetMassProperties(
        idTraceModel *this,
        double density,
        float *mass,
        idVec3 *centerOfMass,
        idMat3 *inertiaTensor,
        float *a6)
{
  float *p_z; // r9
  int v12; // ctr
  idSysMutex *p_viewNoteMutex; // r10
  double v14; // fp10
  double v15; // fp9
  float *v16; // r4
  double T0; // fp13
  double v18; // fp2
  double v19; // fp1
  double v20; // fp13
  double y; // fp12
  double z; // fp11
  double v23; // fp10
  double v24; // fp9
  double v25; // fp8
  double v26; // fp7
  double v27; // fp6
  double v28; // fp3
  double v29; // fp11
  double v30; // fp5
  idVec3 v31; // [sp+50h] [-670h] BYREF
  volumeIntegrals_t v32; // [sp+60h] [-660h] BYREF
  idTraceModel v33; // [sp+90h] [-630h] BYREF

  if ( this->type == TRM_POLYGON )
  {
    p_z = &v33.offset.z;
    v12 = 6;
    memset(&v33.type, 0, 20);
    v33.offset.x = 0.0;
    v33.offset.y = 0.0;
    v33.offset.z = 0.0;
    p_viewNoteMutex = &analysisClient.viewNoteMutex;
    do
    {
      ++p_viewNoteMutex;
      *++p_z = *(float *)&p_viewNoteMutex->handle;
      --v12;
    }
    while ( v12 != 0 );
    v33.radius = 0.0;
    v33.isConvex = false;
    v33.pad[2] = 0;
    v33.pad[1] = 0;
    v33.pad[0] = 0;
    idTraceModel::operator=(this: &v33, __that: this);
    v14 = this->polyPlaneZ[0];
    v15 = (float)(this->polyPlaneY[0] * (float)-1.0);
    v31.x = this->polyPlaneX[0] * (float)-1.0;
    v31.y = v15;
    v31.z = (float)v14 * (float)-1.0;
    idTraceModel::ExtendPolygonToVolume(this: &v33, dir: &v31);
    idTraceModel::GetMassProperties(this: &v33, density, mass: v16, centerOfMass, inertiaTensor);
  }
  else
  {
    idTraceModel::VolumeIntegrals(this, integrals: &v32);
    T0 = v32.T0;
    if ( v32.T0 == 0.0 )
    {
      centerOfMass->x = 1065353216;
      inertiaTensor->mat[0].z = 0.0;
      inertiaTensor->mat[0].y = 0.0;
      inertiaTensor->mat[0].x = 0.0;
      a6[8] = 1.0;
      a6[4] = 1.0;
      *a6 = 1.0;
      a6[5] = 0.0;
      a6[2] = 0.0;
      a6[1] = 0.0;
      a6[7] = 0.0;
      a6[6] = 0.0;
      a6[3] = 0.0;
    }
    else
    {
      centerOfMass->x = v32.T0 * (float)density;
      v18 = (float)(1.0 / (float)T0);
      v19 = (float)(v32.TP.y * (float)density);
      y = v32.T1.y;
      z = v32.T1.z;
      v23 = (float)((float)(v32.T2.z + v32.T2.y) * (float)density);
      v24 = (float)((float)(v32.T2.x + v32.T2.z) * (float)density);
      v25 = (float)((float)(v32.T2.x + v32.T2.y) * (float)density);
      v26 = -(float)(v32.TP.x * (float)density);
      v27 = (float)((float)(1.0 / (float)T0) * v32.T1.x);
      v20 = (float)(v32.TP.z * (float)density);
      inertiaTensor->mat[0].x = v27;
      inertiaTensor->mat[0].y = (float)y * (float)v18;
      inertiaTensor->mat[0].z = (float)z * (float)v18;
      a6[5] = -v19;
      *a6 = v23;
      a6[4] = v24;
      a6[7] = -v19;
      a6[1] = v26;
      a6[2] = -v20;
      a6[6] = -v20;
      a6[8] = v25;
      a6[3] = v26;
      *a6 = -(float)((float)((float)((float)(inertiaTensor->mat[0].y * inertiaTensor->mat[0].y)
                                   + (float)(inertiaTensor->mat[0].z * inertiaTensor->mat[0].z))
                           * centerOfMass->x)
                   - (float)v23);
      a6[4] = -(float)((float)((float)((float)(inertiaTensor->mat[0].x * inertiaTensor->mat[0].x)
                                     + (float)(inertiaTensor->mat[0].z * inertiaTensor->mat[0].z))
                             * centerOfMass->x)
                     - a6[4]);
      a6[8] = -(float)((float)((float)((float)(inertiaTensor->mat[0].x * inertiaTensor->mat[0].x)
                                     + (float)(inertiaTensor->mat[0].y * inertiaTensor->mat[0].y))
                             * centerOfMass->x)
                     - a6[8]);
      v28 = (float)((float)((float)(centerOfMass->x * inertiaTensor->mat[0].x) * inertiaTensor->mat[0].y) + a6[3]);
      a6[3] = (float)((float)(centerOfMass->x * inertiaTensor->mat[0].x) * inertiaTensor->mat[0].y) + a6[3];
      a6[1] = v28;
      v29 = (float)((float)((float)(inertiaTensor->mat[0].z * centerOfMass->x) * inertiaTensor->mat[0].y) + a6[7]);
      a6[7] = (float)((float)(inertiaTensor->mat[0].z * centerOfMass->x) * inertiaTensor->mat[0].y) + a6[7];
      a6[5] = v29;
      v30 = (float)((float)((float)(inertiaTensor->mat[0].z * centerOfMass->x) * inertiaTensor->mat[0].x) + a6[2]);
      a6[2] = (float)((float)(inertiaTensor->mat[0].z * centerOfMass->x) * inertiaTensor->mat[0].x) + a6[2];
      a6[6] = v30;
    }
  }
}


// ========================================================================
// ?SetupBox@idTraceModel@@QAAXABVidBounds@@@Z
// EA  : 0x82F2A0A8
// RVA : 0x00F2A0A8
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::SetupBox(idTraceModel *this, const idBounds *boxBounds)
{
  double v4; // fp8
  double v5; // fp6

  if ( this->type != TRM_BOX )
    idTraceModel::InitBox(this);
  v4 = (float)(boxBounds->b[1].y + boxBounds->b[0].y);
  v5 = (float)(boxBounds->b[0].z + boxBounds->b[1].z);
  this->offset.x = (float)(boxBounds->b[0].x + boxBounds->b[1].x) * (float)0.5;
  this->offset.y = (float)v4 * (float)0.5;
  this->offset.z = (float)v5 * (float)0.5;
  this->vertsX[0] = boxBounds->b[0].x;
  this->vertsY[0] = boxBounds->b[0].y;
  this->vertsZ[0] = boxBounds->b[0].z;
  this->vertsX[1] = boxBounds->b[1].x;
  this->vertsY[1] = boxBounds->b[0].y;
  this->vertsZ[1] = boxBounds->b[0].z;
  this->vertsX[2] = boxBounds->b[1].x;
  this->vertsY[2] = boxBounds->b[1].y;
  this->vertsZ[2] = boxBounds->b[0].z;
  this->vertsX[3] = boxBounds->b[0].x;
  this->vertsY[3] = boxBounds->b[1].y;
  this->vertsZ[3] = boxBounds->b[0].z;
  this->vertsX[4] = boxBounds->b[0].x;
  this->vertsY[4] = boxBounds->b[0].y;
  this->vertsZ[4] = boxBounds->b[1].z;
  this->vertsX[5] = boxBounds->b[1].x;
  this->vertsY[5] = boxBounds->b[0].y;
  this->vertsZ[5] = boxBounds->b[1].z;
  this->vertsX[6] = boxBounds->b[1].x;
  this->vertsY[6] = boxBounds->b[1].y;
  this->vertsZ[6] = boxBounds->b[1].z;
  this->vertsX[7] = boxBounds->b[0].x;
  this->vertsY[7] = boxBounds->b[1].y;
  this->vertsZ[7] = boxBounds->b[1].z;
  this->polyPlaneW[0] = boxBounds->b[0].z;
  this->polyPlaneW[1] = -boxBounds->b[1].z;
  this->polyPlaneW[2] = boxBounds->b[0].y;
  this->polyPlaneW[3] = -boxBounds->b[1].x;
  this->polyPlaneW[4] = -boxBounds->b[1].y;
  this->polyPlaneW[5] = boxBounds->b[0].x;
  this->bounds.b[0].x = boxBounds->b[0].x;
  this->bounds.b[0].y = boxBounds->b[0].y;
  this->bounds.b[0].z = boxBounds->b[0].z;
  this->bounds.b[1].x = boxBounds->b[1].x;
  this->bounds.b[1].y = boxBounds->b[1].y;
  this->bounds.b[1].z = boxBounds->b[1].z;
  idTraceModel::CalculateInsetSphereRadius(this);
}


// ========================================================================
// ?SetupBox@idTraceModel@@QAAXM@Z
// EA  : 0x82F2A270
// RVA : 0x00F2A270
// PDB : w:\tech5\shared\idlib\geometry\tracemodel.cpp
// ========================================================================

void __fastcall idTraceModel::SetupBox(idTraceModel *this, double size)
{
  idBounds v2; // [sp+50h] [-20h] BYREF

  v2.b[1].x = (float)size * (float)0.5;
  v2.b[1].y = v2.b[1].x;
  v2.b[1].z = v2.b[1].x;
  v2.b[0].x = -v2.b[1].x;
  v2.b[0].y = v2.b[0].x;
  v2.b[0].z = v2.b[0].x;
  idTraceModel::SetupBox(this, boxBounds: &v2);
}

