
// ========================================================================
// MinJointInVertexesWithAlignment
// EA  : 0x82847F08
// RVA : 0x00847F08
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

int __fastcall MinJointInVertexesWithAlignment(const idList<processVert_t,5> *verts)
{
  unsigned __int8 v1; // r10
  processVert_t *list; // r7
  int v3; // r8
  int num; // ctr
  processVert_t *v5; // r11
  unsigned __int8 *jointIdxs; // r10
  bool v7; // zf
  unsigned int v8; // r9
  unsigned __int8 *v9; // r10
  unsigned int v10; // r9
  unsigned __int8 *v11; // r10
  unsigned __int8 *v12; // r11
  _BYTE back_chain[16]; // [sp+0h] [-10h] BYREF

  v1 = -1;
  if ( verts->num > 0 )
  {
    list = verts->list;
    v3 = 0;
    num = verts->num;
    do
    {
      v5 = &list[v3];
      v7 = list[v3].jointIdxs[0] < (unsigned int)v1;
      jointIdxs = list[v3].jointIdxs;
      if ( !v7 )
        jointIdxs = back_chain;
      v8 = *jointIdxs;
      v9 = &v5->jointIdxs[1];
      if ( v5->jointIdxs[1] >= v8 )
        v9 = back_chain;
      v10 = *v9;
      v11 = &v5->jointIdxs[2];
      if ( v5->jointIdxs[2] >= v10 )
        v11 = back_chain;
      v12 = &v5->jointIdxs[3];
      if ( *v12 >= (unsigned int)*v11 )
        v12 = back_chain;
      v1 = *v12;
      ++v3;
      --num;
    }
    while ( num != 0 );
  }
  return v1 & 0xF0;
}


// ========================================================================
// MaxJointInVertexes
// EA  : 0x82847FC0
// RVA : 0x00847FC0
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

int __fastcall MaxJointInVertexes(const idList<processVert_t,5> *verts)
{
  unsigned __int8 v1; // r10
  processVert_t *list; // r7
  int v3; // r8
  int num; // ctr
  processVert_t *v5; // r11
  unsigned __int8 *jointIdxs; // r10
  bool v7; // zf
  unsigned int v8; // r9
  unsigned __int8 *v9; // r10
  unsigned int v10; // r9
  unsigned __int8 *v11; // r10
  unsigned __int8 *v12; // r11
  _BYTE back_chain[16]; // [sp+0h] [-10h] BYREF

  v1 = 0;
  if ( verts->num > 0 )
  {
    list = verts->list;
    v3 = 0;
    num = verts->num;
    do
    {
      v5 = &list[v3];
      v7 = v1 < (unsigned int)list[v3].jointIdxs[0];
      jointIdxs = list[v3].jointIdxs;
      if ( !v7 )
        jointIdxs = back_chain;
      v8 = *jointIdxs;
      v9 = &v5->jointIdxs[1];
      if ( v8 >= v5->jointIdxs[1] )
        v9 = back_chain;
      v10 = *v9;
      v11 = &v5->jointIdxs[2];
      if ( v10 >= v5->jointIdxs[2] )
        v11 = back_chain;
      v12 = &v5->jointIdxs[3];
      if ( *v11 >= (unsigned int)*v12 )
        v12 = back_chain;
      v1 = *v12;
      ++v3;
      --num;
    }
    while ( num != 0 );
  }
  return v1;
}


// ========================================================================
// ?MatchMorphVerts@@YA_NABV?$idList@UvertexMorphOffset_t@@$04@@AAV?$idList@UprocessVert_t@@$04@@@Z
// EA  : 0x82848078
// RVA : 0x00848078
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

BOOL __fastcall MatchMorphVerts(
        const idList<vertexMorphOffset_t,5> *vertexMorphOffsets,
        idList<processVert_t,5> *vertexes)
{
  int num; // r11
  int v3; // r25
  int v4; // r26
  int v5; // r5
  int v6; // r31
  int v7; // r11
  double v8; // fp0
  int v9; // r6
  vertexMorphOffset_t *list; // r7
  int v11; // r8
  processVert_t *v12; // r10
  double x; // fp13
  double y; // fp12
  double z; // fp11
  float *p_x; // r10
  double v17; // fp6
  double v18; // fp4
  double v19; // fp2
  double v20; // fp6
  double v21; // fp4
  double v22; // fp2
  int v23; // r9
  vertexMorphOffset_t *v24; // r10
  double v25; // fp6
  double v26; // fp4
  double v27; // fp2
  double v28; // fp6
  double v29; // fp4
  double v30; // fp2
  vertexMorphOffset_t *v31; // r8
  processVert_t *v32; // r10
  int v33; // r9
  int v34; // ctr
  double v35; // fp6
  double v36; // fp4
  double v37; // fp2
  int v38; // r9
  int v39; // r11
  unsigned __int8 v40; // r10
  int v41; // r11
  unsigned __int8 v42; // r10
  int v43; // r11

  num = vertexes->num;
  v3 = 0;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = 0;
      v7 = 0;
      vertexes->list[v5].morph[3] = 0;
      v8 = 1.0e30;
      v9 = vertexMorphOffsets->num;
      if ( v9 >= 4 )
      {
        list = vertexMorphOffsets->list;
        v11 = 0;
        v12 = &vertexes->list[v5];
        x = v12->xyz.x;
        y = v12->xyz.y;
        z = v12->xyz.z;
        do
        {
          p_x = &list[v11].xyz.x;
          v17 = (float)(list[v11].xyz.x - (float)x);
          v18 = (float)(list[v11].xyz.z - (float)z);
          v19 = (float)(list[v11].xyz.y - (float)y);
          if ( (float)((float)((float)v19 * (float)v19)
                     + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) < v8 )
          {
            v8 = (float)((float)((float)v19 * (float)v19)
                       + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)));
            v6 = v7;
          }
          v20 = (float)(p_x[6] - (float)x);
          v21 = (float)(p_x[8] - (float)z);
          v22 = (float)(p_x[7] - (float)y);
          if ( (float)((float)((float)v22 * (float)v22)
                     + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))) < v8 )
          {
            v8 = (float)((float)((float)v22 * (float)v22)
                       + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)));
            v6 = v7 + 1;
          }
          v23 = v11 * 24 + 72;
          v24 = &list[v11 + 3];
          v25 = (float)(v24[-1].xyz.x - (float)x);
          v26 = (float)(v24[-1].xyz.z - (float)z);
          v27 = (float)(v24[-1].xyz.y - (float)y);
          if ( (float)((float)((float)v27 * (float)v27)
                     + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) < v8 )
          {
            v8 = (float)((float)((float)v27 * (float)v27)
                       + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)));
            v6 = v7 + 2;
          }
          v28 = (float)(*(float *)((char *)&list->xyz.x + v23) - (float)x);
          v29 = (float)(*(float *)((char *)&list->xyz.z + v23) - (float)z);
          v30 = (float)(*(float *)((char *)&list->xyz.y + v23) - (float)y);
          if ( (float)((float)((float)v30 * (float)v30)
                     + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28))) < v8 )
          {
            v8 = (float)((float)((float)v30 * (float)v30)
                       + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)));
            v6 = v7 + 3;
          }
          v7 += 4;
          v11 += 4;
        }
        while ( v7 < v9 - 3 );
      }
      if ( v7 < v9 )
      {
        v31 = vertexMorphOffsets->list;
        v32 = &vertexes->list[v5];
        v33 = v7;
        v34 = v9 - v7;
        do
        {
          v35 = (float)(v31[v33].xyz.x - v32->xyz.x);
          v36 = (float)(v31[v33].xyz.z - v32->xyz.z);
          v37 = (float)(v31[v33].xyz.y - v32->xyz.y);
          if ( (float)((float)((float)v37 * (float)v37)
                     + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) < v8 )
          {
            v8 = (float)((float)((float)v37 * (float)v37)
                       + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35)));
            v6 = v7;
          }
          ++v7;
          ++v33;
          --v34;
        }
        while ( v34 != 0 );
      }
      if ( v8 <= 0.1 )
      {
        v38 = v6;
        v39 = (int)(float)((float)(vertexMorphOffsets->list[v6].offset.x * (float)4.0) + (float)128.0);
        if ( v39 >= 0 )
        {
          v40 = -1;
          if ( v39 <= 255 )
            v40 = (int)(float)((float)(vertexMorphOffsets->list[v6].offset.x * (float)4.0) + (float)128.0);
        }
        else
        {
          v40 = 0;
        }
        vertexes->list[v5].morph[0] = v40;
        v41 = (int)(float)((float)(vertexMorphOffsets->list[v38].offset.y * (float)4.0) + (float)128.0);
        if ( v41 >= 0 )
        {
          v42 = -1;
          if ( v41 <= 255 )
            v42 = (int)(float)((float)(vertexMorphOffsets->list[v38].offset.y * (float)4.0) + (float)128.0);
        }
        else
        {
          v42 = 0;
        }
        vertexes->list[v5].morph[1] = v42;
        v43 = (int)(float)((float)(vertexMorphOffsets->list[v38].offset.z * (float)4.0) + (float)128.0);
        if ( v43 >= 0 )
        {
          if ( v43 > 255 )
            LOBYTE(v43) = -1;
        }
        else
        {
          LOBYTE(v43) = 0;
        }
        ++v3;
        vertexes->list[v5].morph[2] = v43;
      }
      else
      {
        vertexes->list[v5].morph[0] = 0x80;
        vertexes->list[v5].morph[1] = 0x80;
        vertexes->list[v5].morph[2] = 0x80;
      }
      num = vertexes->num;
      ++v4;
      ++v5;
    }
    while ( v4 < num );
  }
  return (_cntlzw(num - v3) & 0x20) != 0;
}


// ========================================================================
// ?ProcessVertsHaveTexCoordsOutsideRange@@YA_NABV?$idList@UprocessST_t@@$04@@MM@Z
// EA  : 0x828483B8
// RVA : 0x008483B8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

int __fastcall ProcessVertsHaveTexCoordsOutsideRange(const idList<processST_t,5> *uvs, double min, double max)
{
  int num; // r4
  int v4; // r5
  int v5; // r7
  processST_t *i; // r6
  int v7; // r9
  idVec2 *list; // r8
  int v9; // r11
  double x; // fp13
  double y; // fp0

  num = uvs->num;
  if ( num == 0 )
    return 0;
  v4 = 0;
  v5 = uvs->list->st.num;
  if ( num <= 0 )
    return 0;
  for ( i = uvs->list; ; ++i )
  {
    v7 = 0;
    if ( v5 > 0 )
      break;
LABEL_11:
    if ( ++v4 >= num )
      return 0;
  }
  list = i->st.list;
  v9 = 0;
  while ( 1 )
  {
    x = list[v9].x;
    if ( x < min )
      return 1;
    y = list[v9].y;
    if ( y < min || x > max || y > max )
      return 1;
    ++v7;
    ++v9;
    if ( v7 >= v5 )
      goto LABEL_11;
  }
}


// ========================================================================
// ?CreateHashST@idMD6BinaryGenerator@@QAAXXZ
// EA  : 0x82848880
// RVA : 0x00848880
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall idMD6BinaryGenerator::CreateHashST(idMD6BinaryGenerator *this)
{
  int v2; // r23
  int v3; // r25
  idProcessSurface *v4; // r11
  idProcessMesh *p_mesh; // r28
  char *v6; // r3
  int v7; // r29
  int v8; // r30
  char *v9; // r3
  char *data; // r9
  int v11; // r11
  unsigned __int8 i; // r8
  char v13[16]; // [sp+50h] [-180h] BYREF
  idStr v14; // [sp+60h] [-170h] BYREF
  char v15; // [sp+80h] [-150h] BYREF

  v14.baseBuffer[0] = 0;
  v15 = 0;
  v14.len = 0;
  v14.data = &v15;
  v14.allocedAndFlag = -2147483392;
  v2 = 0;
  if ( this->surfaces.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->surfaces.list[v3];
      if ( v4 != nullptr )
      {
        p_mesh = &v4->mesh;
        if ( v4->mesh.uvs.num > 0 )
        {
          idStr::Clear(this: &v14);
          v6 = itoa(a: v13, i: p_mesh->uvs.num);
          idStr::Append(this: &v14, text: v6);
          v7 = 0;
          if ( p_mesh->uvs.num > 0 )
          {
            v8 = 0;
            do
            {
              idStr::Append(this: &v14, text: "_");
              v9 = itoa(a: v13, i: p_mesh->uvs.list[v8].slot);
              idStr::Append(this: &v14, text: v9);
              ++v7;
              ++v8;
            }
            while ( v7 < p_mesh->uvs.num );
          }
          data = v14.data;
          v11 = 0;
          for ( i = *v14.data; *data != 0; i = *data )
          {
            ++data;
            v11 = 31 * v11 + i;
          }
          p_mesh->hashST = v11;
        }
        else
        {
          v4->mesh.hashST = 0;
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->surfaces.num );
  }
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$232213_0
// EA  : 0x828489D0
// RVA : 0x008489D0
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_232213_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 96));
}


// ========================================================================
// ?WriteBinaryFile@idMD6BinaryGenerator@@QAA_NPBD@Z
// EA  : 0x82848A00
// RVA : 0x00848A00
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
int __fastcall idMD6BinaryGenerator::WriteBinaryFile(idMD6BinaryGenerator *this, const char *filename)
{
  __int64 v3; // r4
  int v4; // r23
  const char *v5; // r30
  int result; // r3
  idFile_vtbl *v7; // r10
  float *v8; // r30
  int v9; // r6
  int v10; // r7
  int v11; // r10
  int v12; // r8
  int v13; // r9
  double v14; // fp13
  float *v15; // r11
  double v16; // fp12
  double v17; // fp11
  double v18; // fp10
  double v19; // fp9
  unsigned int v33; // r10
  unsigned int v39; // r9
  float *v40; // r11
  double v47; // fp23
  double v48; // fp22
  float *v85; // r11
  unsigned int v86; // ctr
  double v93; // fp5
  double v94; // fp4
  idFile *file; // r3
  double v96; // fp3
  double v97; // fp29
  double v98; // fp28
  double v99; // fp31
  double v100; // fp30
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  double v114; // fp12
  double v115; // fp10
  char v116; // r11
  char v117; // r8
  int v118; // r4
  int v123; // r30
  _DWORD *v124; // r29
  _DWORD *v125; // r18
  int v126; // r20
  char v127; // r10
  char v128; // r6
  int *v129; // r22
  int v131; // r9
  int v137; // r10
  float *v138; // r11
  float *v151; // r11
  float *v164; // r11
  float *v177; // r11
  int v184; // r10
  int v185; // ctr
  float *v186; // r11
  int *v193; // r21
  int v194; // r26
  int v195; // r10
  int v196; // r11
  int v197; // r7
  char *v198; // r3
  char *v200; // r19
  int v201; // r28
  int v202; // r27
  int v204; // r25
  int v205; // r11
  float *v206; // r10
  char v213; // r10
  int v214; // r10
  int v215; // r9
  int v216; // r10
  int v217; // r9
  int v218; // r10
  int v219; // r9
  const char *v220; // r25
  idMem *v221; // r24
  unsigned int v222; // r30
  char *v223; // r3
  void *v224; // r26
  int v225; // r11
  int v226; // r10
  char *v227; // r9
  __int16 v228; // r6
  int v229; // r27
  int v230; // r28
  int v231; // r30
  unsigned int v232; // r30
  char *v233; // r3
  void *v234; // r28
  int v235; // r11
  int v236; // ctr
  char *v237; // r10
  char v238; // r9
  int v239; // r8
  int v240; // r29
  int v241; // r30
  int *v242; // r9
  _DWORD *v243; // r10
  int i; // ctr
  idFileLocal v246; // [sp+50h] [-7190h] BYREF
  unsigned int v247; // [sp+54h] [-718Ch] BYREF
  int v248; // [sp+58h] [-7188h] BYREF
  char v249; // [sp+5Ch] [-7184h] BYREF
  char v250[3]; // [sp+5Dh] [-7183h] BYREF
  float v251[5]; // [sp+60h] [-7180h] BYREF
  float v252; // [sp+74h] [-716Ch]
  int v253; // [sp+78h] [-7168h]
  int v254; // [sp+7Ch] [-7164h]
  int v255; // [sp+80h] [-7160h] BYREF
  idMem *v256; // [sp+84h] [-715Ch]
  const char *v257; // [sp+88h] [-7158h]
  __vector4 *v258; // [sp+8Ch] [-7154h]
  int v259; // [sp+90h] [-7150h] BYREF
  int v260; // [sp+94h] [-714Ch] BYREF
  cmType_t ScriptP; // [sp+98h] [-7148h] BYREF
  float *v262; // [sp+9Ch] [-7144h]
  const unsigned int *v263; // [sp+A0h] [-7140h]
  int v264; // [sp+A4h] [-713Ch] BYREF
  int v265; // [sp+A8h] [-7138h] BYREF
  int v266; // [sp+ACh] [-7134h] BYREF
  idCollisionModelLocal *v267; // [sp+B0h] [-7130h]
  int v268; // [sp+B8h] [-7128h] BYREF
  int v269; // [sp+BCh] [-7124h] BYREF
  int v270; // [sp+C0h] [-7120h] BYREF
  int v271; // [sp+C4h] [-711Ch]
  char *v272; // [sp+C8h] [-7118h]
  int v273; // [sp+CCh] [-7114h]
  char *v274; // [sp+D0h] [-7110h]
  unsigned int v275; // [sp+D4h] [-710Ch]
  char *v276; // [sp+D8h] [-7108h]
  int v277; // [sp+DCh] [-7104h]
  float v278[3072]; // [sp+E0h] [-7100h] BYREF
  float v279; // [sp+30E0h] [-4100h] BYREF

  _R12 = -256;
  __asm { stvx128   v127, r1, r12 }
  v3 = ((__int64 (*)(void))RtlCheckStack12)();
  v4 = HIDWORD(v3);
  v5 = (const char *)v3;
  v246.file = fileSystem->OpenFileWrite(this: fileSystem, a2: v3, a3: 0);
  if ( v246.file != nullptr )
  {
    idLib::Printf(fmt: "Writing %s\n", v5);
    v7 = v246.file->__vftable;
    v263 = &MD6_MESH_MAGIC;
    ((void (__fastcall *)(idFile *))v7->Write)(a1: v246.file);
    v246.file->Write(this: v246.file, a2: (const void *)(v4 + 32), a3: 4u);
    v246.file->Write(this: v246.file, a2: (const void *)(v4 + 36), a3: 4u);
    idFile::WriteString(this: v246.file, string: *(const char **)(*(_DWORD *)(v4 + 124) + 8));
    v8 = (float *)(v4 + 40);
    v262 = (float *)&idMath::INFINITY;
    v9 = 0;
    *(float *)(v4 + 48) = 1.0e30;
    *(float *)(v4 + 44) = 1.0e30;
    *(float *)(v4 + 40) = 1.0e30;
    *(float *)(v4 + 60) = -1.0e30;
    *(float *)(v4 + 56) = -1.0e30;
    *(float *)(v4 + 52) = -1.0e30;
    if ( *(int *)(v4 + 148) > 0 )
    {
      v10 = 0;
      do
      {
        v11 = 0;
        v12 = *(_DWORD *)(v10 + *(_DWORD *)(v4 + 144));
        if ( *(int *)(v12 + 48) > 0 )
        {
          v13 = 0;
          do
          {
            v14 = *(float *)(v4 + 44);
            ++v11;
            v15 = (float *)(v13 + *(_DWORD *)(v12 + 44));
            v16 = *(float *)(v4 + 48);
            v17 = *(float *)(v4 + 52);
            v13 += 52;
            v18 = *(float *)(v4 + 56);
            v19 = *(float *)(v4 + 60);
            _FP7 = (float)(*v8 - *v15);
            __asm { fsel      f6, f7, f8, f0 }
            *v8 = _FP6;
            _FP4 = (float)((float)v14 - v15[1]);
            __asm { fsel      f3, f4, f5, f13 }
            *(float *)(v4 + 44) = _FP3;
            _FP1 = (float)((float)v16 - v15[2]);
            __asm { fsel      f0, f1, f2, f12 }
            *(float *)(v4 + 48) = _FP0;
            _FP12 = (float)(*v15 - (float)v17);
            __asm { fsel      f11, f12, f13, f11 }
            *(float *)(v4 + 52) = _FP11;
            _FP7 = (float)(v15[1] - (float)v18);
            __asm { fsel      f6, f7, f8, f10 }
            *(float *)(v4 + 56) = _FP6;
            _FP4 = (float)(v15[2] - (float)v19);
            __asm { fsel      f3, f4, f5, f9 }
            *(float *)(v4 + 60) = _FP3;
          }
          while ( v11 < *(_DWORD *)(v12 + 48) );
        }
        ++v9;
        v10 += 4;
      }
      while ( v9 < *(_DWORD *)(v4 + 148) );
    }
    idMD6Blend::DecodeBasePose(
      skeleton: *(const idMD6SkelData **)(*(_DWORD *)(v4 + 124) + 40),
      temp: &v279,
      tempSize: 0x4000u,
      originOffset: &vec3_origin.x,
      offsetAdd: 1u,
      outPose: v278);
    _FP0 = 1.0e30;
    v33 = 0;
    _FP12 = -1.0e30;
    _FP13 = 1.0e30;
    _FP10 = 1.0e30;
    _FP11 = -1.0e30;
    _FP9 = -1.0e30;
    v39 = *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v4 + 124) + 40) + 2);
    if ( v39 >= 4 )
    {
      v40 = (float *)&v269;
      do
      {
        v33 += 4;
        _FP5 = (float)((float)_FP10 - v40[12]);
        _FP3 = (float)(v40[12] - (float)_FP9);
        _FP2 = (float)((float)_FP13 - v40[16]);
        _FP31 = (float)((float)_FP0 - v40[20]);
        _FP29 = (float)(v40[16] - (float)_FP12);
        _FP27 = (float)(v40[20] - (float)_FP11);
        v47 = v40[56];
        v48 = v40[52];
        __asm { fsel      f10, f5, f7, f10 }
        __asm
        {
          fsel      f9, f3, f7, f9
          fsel      f7, f2, f6, f13
          fsel      f5, f31, f4, f0
          fsel      f3, f29, f6, f12
          fsel      f2, f27, f4, f11
        }
        _FP0 = (float)((float)_FP10 - v40[24]);
        _FP13 = (float)(v40[24] - (float)_FP9);
        _FP12 = (float)((float)_FP7 - v40[28]);
        _FP11 = (float)((float)_FP5 - v40[32]);
        _FP6 = (float)(v40[28] - (float)_FP3);
        _FP4 = (float)(v40[32] - (float)_FP2);
        __asm
        {
          fsel      f0, f0, f1, f10
          fsel      f13, f13, f1, f9
          fsel      f12, f12, f30, f7
          fsel      f11, f11, f28, f5
          fsel      f10, f6, f30, f3
          fsel      f9, f4, f28, f2
        }
        _FP7 = (float)((float)_FP0 - v40[36]);
        _FP6 = (float)(v40[36] - (float)_FP13);
        _FP5 = (float)((float)_FP12 - v40[40]);
        _FP4 = (float)((float)_FP11 - v40[44]);
        _FP3 = (float)(v40[40] - (float)_FP10);
        _FP2 = (float)(v40[44] - (float)_FP9);
        v40 += 48;
        __asm
        {
          fsel      f1, f7, f26, f0
          fsel      f0, f6, f26, f13
          fsel      f13, f5, f25, f12
          fsel      f12, f4, f24, f11
          fsel      f11, f3, f25, f10
          fsel      f7, f2, f24, f9
        }
        _FP6 = (float)((float)_FP1 - *v40);
        _FP5 = (float)(*v40 - (float)_FP0);
        _FP4 = (float)((float)_FP13 - (float)v48);
        _FP3 = (float)((float)_FP12 - (float)v47);
        _FP2 = (float)((float)v48 - (float)_FP11);
        _FP31 = (float)((float)v47 - (float)_FP7);
        __asm
        {
          fsel      f10, f6, f8, f1
          fsel      f9, f5, f8, f0
          fsel      f13, f4, f22, f13
          fsel      f0, f3, f23, f12
          fsel      f12, f2, f22, f11
          fsel      f11, f31, f23, f7
        }
      }
      while ( v33 < v39 - 3 );
    }
    if ( v33 < v39 )
    {
      v85 = &v278[12 * v33 - 9];
      v86 = v39 - v33;
      do
      {
        _FP5 = (float)((float)_FP0 - v85[20]);
        _FP4 = (float)((float)_FP13 - v85[16]);
        _FP3 = (float)(v85[16] - (float)_FP12);
        _FP2 = (float)(v85[20] - (float)_FP11);
        v85 += 12;
        _FP1 = (float)((float)_FP10 - *v85);
        _FP31 = (float)(*v85 - (float)_FP9);
        __asm
        {
          fsel      f0, f5, f7, f0
          fsel      f13, f4, f6, f13
          fsel      f12, f3, f6, f12
          fsel      f11, f2, f7, f11
          fsel      f10, f1, f8, f10
          fsel      f9, f31, f8, f9
        }
        --v86;
      }
      while ( v86 != 0 );
    }
    v93 = *v8;
    v94 = *(float *)(v4 + 48);
    file = v246.file;
    v96 = *(float *)(v4 + 44);
    v97 = *(float *)(v4 + 52);
    v98 = *(float *)(v4 + 56);
    v254 = v4 + 52;
    v99 = *(float *)(v4 + 72);
    v100 = *(float *)(v4 + 76);
    Write = v246.file->Write;
    _FP8 = (float)(vec3_origin.z - (float)((float)v94 - (float)((float)_FP0 - (float)16.0)));
    _FP4 = (float)(vec3_origin.x - (float)((float)v97 - (float)((float)_FP9 + (float)16.0)));
    _FP9 = (float)(vec3_origin.y - (float)((float)v96 - (float)((float)_FP13 - (float)16.0)));
    _FP29 = (float)(vec3_origin.y - (float)((float)v98 - (float)((float)_FP12 + (float)16.0)));
    _FP28 = (float)(vec3_origin.z - (float)(*(float *)(v4 + 60) - (float)((float)_FP11 + (float)16.0)));
    _FP11 = (float)(vec3_origin.x - (float)((float)v93 - (float)((float)_FP10 - (float)16.0)));
    __asm
    {
      fsel      f11, f11, f5, f10
      fsel      f9, f9, f3, f7
      fsel      f8, f8, f2, f6
      fsel      f5, f4, f10, f1
      fsel      f4, f29, f7, f0
      fsel      f3, f28, f6, f12
    }
    *(float *)(v4 + 68) = (float)_FP11 + *(float *)(v4 + 68);
    *(float *)(v4 + 72) = (float)_FP9 + (float)v99;
    *(float *)(v4 + 76) = (float)_FP8 + (float)v100;
    v114 = *(float *)(v4 + 84);
    v115 = (float)((float)_FP3 + *(float *)(v4 + 88));
    *(float *)(v4 + 80) = (float)_FP5 + *(float *)(v4 + 80);
    *(float *)(v4 + 84) = (float)_FP4 + (float)v114;
    *(float *)(v4 + 88) = v115;
    Write(this: file, a2: (const void *)(v4 + 68), a3: 12u);
    v246.file->Write(this: v246.file, a2: (const void *)(v4 + 80), a3: 12u);
    v246.file->Write(this: v246.file, a2: (const void *)(v4 + 64), a3: 1u);
    v248 = *(_DWORD *)(v4 + 92);
    v116 = BYTE2(v248);
    v117 = HIBYTE(v248);
    HIBYTE(v248) = v248;
    BYTE2(v248) = BYTE1(v248);
    BYTE1(v248) = v116;
    LOBYTE(v248) = v117;
    v246.file->Write(this: v246.file, a2: &v248, a3: 4u);
    v246.file->Write(this: v246.file, a2: *(const void **)(v4 + 96), a3: *(_DWORD *)(v4 + 92));
    v246.file->Write(this: v246.file, a2: *(const void **)(v4 + 128), a3: *(_DWORD *)(v4 + 132));
    v246.file->Write(this: v246.file, a2: (const void *)(v4 + 40), a3: 24u);
    v265 = *(_DWORD *)(v4 + 148);
    v246.file->Write(this: v246.file, a2: &v265, a3: 4u);
    v118 = *(_DWORD *)(v4 + 148);
    v254 = 0;
    if ( v118 > 0 )
    {
      v253 = 0;
      v258 = &_vmx_3f8000003f8000003f8000003f800000;
      _R16 = 4;
      v257 = "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP";
      _R17 = 8;
      v256 = &mem;
      _R15 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
      _R14 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
      do
      {
        v123 = *(_DWORD *)(v253 + *(_DWORD *)(v4 + 144));
        v124 = (_DWORD *)(v123 + 44);
        v125 = (_DWORD *)(v123 + 48);
        v126 = *(_DWORD *)(v123 + 48);
        v247 = *(_DWORD *)v123;
        v127 = BYTE1(v247);
        v128 = HIBYTE(v247);
        BYTE1(v247) = BYTE2(v247);
        HIBYTE(v247) = v247;
        LOBYTE(v247) = v128;
        BYTE2(v247) = v127;
        v246.file->Write(this: v246.file, a2: &v247, a3: 4u);
        v246.file->Write(this: v246.file, a2: *(const void **)(v123 + 4), a3: *(_DWORD *)v123);
        idFile::WriteString(this: v246.file, string: *(const char **)(*(_DWORD *)(v123 + 32) + 8));
        v246.file->Write(this: v246.file, a2: (const void *)(v123 + 37), a3: 1u);
        v246.file->Write(this: v246.file, a2: (const void *)(v123 + 40), a3: 4u);
        v264 = *(_DWORD *)(v123 + 48);
        v246.file->Write(this: v246.file, a2: &v264, a3: 4u);
        v259 = *(_DWORD *)(v123 + 80) / 3;
        v129 = (int *)(v123 + 80);
        v246.file->Write(this: v246.file, a2: &v259, a3: 4u);
        _FP0 = *v262;
        v131 = 0;
        v251[2] = *v262;
        v251[1] = _FP0;
        _FP12 = _FP0;
        v251[0] = _FP0;
        _FP11 = -_FP0;
        _FP13 = _FP0;
        v252 = -_FP0;
        _FP9 = -_FP0;
        v251[4] = v252;
        _FP10 = -_FP0;
        v251[3] = v252;
        if ( v126 >= 4 )
        {
          v137 = 0;
          do
          {
            v131 += 4;
            v138 = (float *)(*v124 + v137);
            _FP7 = (float)((float)_FP0 - *v138);
            __asm { fsel      f0, f7, f8, f0 }
            v251[0] = _FP0;
            _FP5 = (float)((float)_FP13 - v138[1]);
            __asm { fsel      f13, f5, f6, f13 }
            v251[1] = _FP13;
            _FP3 = (float)((float)_FP12 - v138[2]);
            __asm { fsel      f12, f3, f4, f12 }
            v251[2] = _FP12;
            _FP1 = (float)(*v138 - (float)_FP11);
            __asm { fsel      f11, f1, f2, f11 }
            v251[3] = _FP11;
            _FP7 = (float)(v138[1] - (float)_FP10);
            __asm { fsel      f10, f7, f8, f10 }
            v251[4] = _FP10;
            _FP5 = (float)(v138[2] - (float)_FP9);
            __asm { fsel      f9, f5, f6, f9 }
            v252 = _FP9;
            v151 = (float *)(*v124 + v137 + 52);
            _FP3 = (float)((float)_FP0 - *v151);
            __asm { fsel      f0, f3, f4, f0 }
            v251[0] = _FP0;
            _FP1 = (float)((float)_FP13 - v151[1]);
            __asm { fsel      f13, f1, f2, f13 }
            v251[1] = _FP13;
            _FP7 = (float)((float)_FP12 - v151[2]);
            __asm { fsel      f12, f7, f8, f12 }
            v251[2] = _FP12;
            _FP5 = (float)(*v151 - (float)_FP11);
            __asm { fsel      f11, f5, f6, f11 }
            v251[3] = _FP11;
            _FP3 = (float)(v151[1] - (float)_FP10);
            __asm { fsel      f10, f3, f4, f10 }
            v251[4] = _FP10;
            _FP1 = (float)(v151[2] - (float)_FP9);
            __asm { fsel      f9, f1, f2, f9 }
            v252 = _FP9;
            v164 = (float *)(*v124 + v137 + 156 - 52);
            _FP7 = (float)((float)_FP0 - *v164);
            __asm { fsel      f0, f7, f8, f0 }
            v251[0] = _FP0;
            _FP5 = (float)((float)_FP13 - v164[1]);
            __asm { fsel      f13, f5, f6, f13 }
            v251[1] = _FP13;
            _FP3 = (float)((float)_FP12 - v164[2]);
            __asm { fsel      f12, f3, f4, f12 }
            v251[2] = _FP12;
            _FP1 = (float)(*v164 - (float)_FP11);
            __asm { fsel      f11, f1, f2, f11 }
            v251[3] = _FP11;
            _FP7 = (float)(v164[1] - (float)_FP10);
            __asm { fsel      f10, f7, f8, f10 }
            v251[4] = _FP10;
            _FP5 = (float)(v164[2] - (float)_FP9);
            __asm { fsel      f9, f5, f6, f9 }
            v252 = _FP9;
            v177 = (float *)(*v124 + v137 + 156);
            v137 += 208;
            _FP3 = (float)((float)_FP0 - *v177);
            __asm { fsel      f0, f3, f4, f0 }
            v251[0] = _FP0;
            _FP1 = (float)((float)_FP13 - v177[1]);
            __asm { fsel      f13, f1, f2, f13 }
            v251[1] = _FP13;
            _FP7 = (float)((float)_FP12 - v177[2]);
            __asm { fsel      f12, f7, f8, f12 }
            v251[2] = _FP12;
            _FP5 = (float)(*v177 - (float)_FP11);
            __asm { fsel      f11, f5, f6, f11 }
            v251[3] = _FP11;
            _FP3 = (float)(v177[1] - (float)_FP10);
            __asm { fsel      f10, f3, f4, f10 }
            v251[4] = _FP10;
            _FP1 = (float)(v177[2] - (float)_FP9);
            __asm { fsel      f9, f1, f2, f9 }
            v252 = _FP9;
          }
          while ( v131 < v126 - 3 );
        }
        if ( v131 < v126 )
        {
          v184 = 52 * v131;
          v185 = v126 - v131;
          do
          {
            v186 = (float *)(*v124 + v184);
            v184 += 52;
            _FP7 = (float)((float)_FP0 - *v186);
            __asm { fsel      f0, f7, f8, f0 }
            v251[0] = _FP0;
            _FP5 = (float)((float)_FP13 - v186[1]);
            __asm { fsel      f13, f5, f6, f13 }
            v251[1] = _FP13;
            _FP3 = (float)((float)_FP12 - v186[2]);
            __asm { fsel      f12, f3, f4, f12 }
            v251[2] = _FP12;
            _FP1 = (float)(*v186 - (float)_FP11);
            __asm { fsel      f11, f1, f2, f11 }
            v251[3] = _FP11;
            _FP7 = (float)(v186[1] - (float)_FP10);
            __asm { fsel      f10, f7, f8, f10 }
            v251[4] = _FP10;
            _FP5 = (float)(v186[2] - (float)_FP9);
            __asm { fsel      f9, f5, f6, f9 }
            v252 = _FP9;
            --v185;
          }
          while ( v185 != 0 );
        }
        v246.file->Write(this: v246.file, a2: v251, a3: 24u);
        v193 = (int *)(v123 + 64);
        v194 = -1;
        v195 = 0;
        v271 = *(_DWORD *)(v123 + 64);
        if ( v271 > 0 )
        {
          v196 = 0;
          v197 = *(_DWORD *)(v123 + 60);
          while ( *(_BYTE *)(v197 + 16) != 0 )
          {
            ++v195;
            v196 += 20;
            v197 = *(_DWORD *)(v123 + 60) + v196;
            if ( v195 >= v271 )
              goto LABEL_29;
          }
          v194 = v195;
        }
LABEL_29:
        v255 = v271;
        if ( v194 != -1 )
          v255 = v271 - 1;
        v277 = v126;
        v198 = (char *)idMem::AllocWithLocation(
                         this: v256,
                         location: v257,
                         size: 32 * v126,
                         tag: TAG_TEMP,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
        v200 = v198;
        v276 = v198;
        if ( v126 > 0 )
        {
          __asm { vspltisw128 v127, 0 }
          v201 = 0;
          v202 = 0;
          _R30 = (float *)(v198 + 16);
          v204 = v126;
          do
          {
            v205 = *v124 + v202;
            *(_R30 - 4) = *(float *)v205;
            *(_R30 - 3) = *(float *)(v205 + 4);
            *(_R30 - 2) = *(float *)(v205 + 8);
            *_R30 = 0.0;
            *(_R30 - 1) = 0.0;
            if ( v194 != -1 )
            {
              v206 = (float *)(*(_DWORD *)(20 * v194 + v124[4]) + v201);
              *(_R30 - 1) = *v206;
              *_R30 = v206[1];
            }
            _R10 = v205 + 12;
            __asm { vmr128    v62, v127 }
            _R9 = v258;
            __asm
            {
              lvx128    v13, r0, r15
              lvx128    v0, r0, r14
            }
            _R8 = 0x600000005LL;
            __asm { vmr128    v61, v127 }
            _R5 = 9;
            __asm { lvlx128   v60, r0, r10 }
            _R4 = 10;
            __asm
            {
              vrlimi128 v62, v60, 8, 0
              lvlx128   v59, r10, r16
              lvlx128   v58, r10, r17
            }
            _R10 = v205 + 24;
            __asm { lvx128    v63, r0, r9 }
            __asm
            {
              vrlimi128 v62, v59, 4, 3
              vrlimi128 v62, v58, 2, 2
              vaddfp128 v12, v94, v63
              vmaddfp   v0, v12, v0, v13
              vcfpsxws128 v57, v0, 0
              vpkswss128 v56, v89, v57
              vpkshus128 v0, v88, v56
              stvebx    v0, r30, r16
              stvebx    v0, r30, r8
              stvebx    v0, r30, r7
              lvx128    v0, r0, r14
              lvx128    v13, r0, r15
              lvlx128   v54, r0, r10
              vrlimi128 v61, v54, 8, 0
              lvlx128   v55, r10, r16
              lvlx128   v53, r10, r17
            }
            v213 = 0;
            __asm
            {
              lvx128    v63, r0, r9
              vrlimi128 v61, v55, 4, 3
              vrlimi128 v61, v53, 2, 2
              vaddfp128 v12, v93, v63
              vmaddfp   v0, v12, v0, v13
              vcfpsxws128 v52, v0, 0
              vpkswss128 v51, v84, v52
              vpkshus128 v0, v83, v51
              stvebx    v0, r30, r17
              stvebx    v0, r30, r5
              stvebx    v0, r30, r4
            }
            if ( *(float *)(v205 + 36) >= 0.0 )
              v213 = -1;
            *((_BYTE *)_R30 + 11) = v213;
            if ( *(_BYTE *)(v205 + 44) != 0 )
            {
              v214 = *(unsigned __int8 *)(v205 + 48);
              v215 = v124[16];
              LODWORD(_R8) = v214 - v215;
              *((_BYTE *)_R30 + 12) = v214 - v215;
            }
            else
            {
              *((_BYTE *)_R30 + 12) = *((_BYTE *)_R30 + 12);
            }
            if ( *(_BYTE *)(v205 + 45) != 0 )
            {
              v216 = *(unsigned __int8 *)(v205 + 49);
              v217 = v124[16];
              LODWORD(_R8) = v216 - v217;
              *((_BYTE *)_R30 + 13) = v216 - v217;
            }
            else
            {
              *((_BYTE *)_R30 + 13) = *((_BYTE *)_R30 + 12);
            }
            if ( *(_BYTE *)(v205 + 46) != 0 )
            {
              v218 = *(unsigned __int8 *)(v205 + 50);
              v219 = v124[16];
              LODWORD(_R8) = v218 - v219;
              *((_BYTE *)_R30 + 14) = v218 - v219;
            }
            else
            {
              *((_BYTE *)_R30 + 14) = *((_BYTE *)_R30 + 12);
            }
            if ( *(_BYTE *)(v205 + 47) != 0 )
              *((_BYTE *)_R30 + 15) = *(_BYTE *)(v205 + 51) - v124[16];
            else
              *((_BYTE *)_R30 + 15) = *((_BYTE *)_R30 + 12);
            *((_BYTE *)_R30 + 7) = CompressWeightsToByte(
                                     weights: (const unsigned __int8 *)(v205 + 44),
                                     a2: 10,
                                     a3: 9,
                                     a4: _R8);
            --v204;
            v202 += 52;
            _R30 += 8;
            v201 += 8;
          }
          while ( v204 != 0 );
        }
        v246.file->Write(this: v246.file, a2: v200, a3: 32 * v126);
        v220 = v257;
        v221 = v256;
        v222 = 2 * *v129;
        v273 = *v129;
        v223 = (char *)idMem::AllocWithLocation(
                         this: v256,
                         location: v257,
                         size: v222,
                         tag: TAG_TEMP,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
        v224 = v223;
        v272 = v223;
        v225 = 0;
        if ( *v129 > 0 )
        {
          v226 = 0;
          v227 = v223 - 2;
          do
          {
            ++v225;
            v228 = *(_DWORD *)(v226 + v124[8]);
            v226 += 4;
            v227 += 2;
            *(_WORD *)v227 = v228;
          }
          while ( v225 < *v129 );
        }
        v246.file->Write(this: v246.file, a2: v223, a3: v222);
        v246.file->Write(this: v246.file, a2: v124 + 16, a3: 4u);
        v266 = v124[17] - v124[16] + 1;
        v246.file->Write(this: v246.file, a2: &v266, a3: 4u);
        v246.file->Write(this: v246.file, a2: &v255, a3: 4u);
        v229 = 0;
        if ( *v193 > 0 )
        {
          v230 = 0;
          do
          {
            v231 = v230 + v124[4];
            if ( *(_BYTE *)(v231 + 16) != 0 )
            {
              v246.file->Write(this: v246.file, a2: (const void *)(v231 + 16), a3: 1u);
              v246.file->Write(this: v246.file, a2: *(const void **)v231, a3: 8 * *(_DWORD *)(v231 + 4));
            }
            ++v229;
            v230 += 20;
          }
          while ( v229 < *v193 );
        }
        if ( *(_DWORD *)(v4 + 92) != 0 )
        {
          v249 = 1;
          v246.file->Write(this: v246.file, a2: &v249, a3: 1u);
          v232 = 4 * *v125;
          v275 = v232;
          v233 = (char *)idMem::AllocWithLocation(
                           this: v221,
                           location: v220,
                           size: v232,
                           tag: TAG_TEMP,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
          v234 = v233;
          v274 = v233;
          if ( v126 > 0 )
          {
            v235 = 0;
            v236 = v126;
            v237 = v233 - 1;
            do
            {
              v237[1] = *(_BYTE *)(v235 + *v124 + 40);
              v237[2] = *(_BYTE *)(v235 + *v124 + 41);
              v237[3] = *(_BYTE *)(v235 + *v124 + 42);
              v238 = *(_BYTE *)(v235 + *v124 + 43);
              v235 += 52;
              v237 += 4;
              *v237 = v238;
              --v236;
            }
            while ( v236 != 0 );
          }
          v246.file->Write(this: v246.file, a2: v233, a3: v232);
          if ( v234 != nullptr )
            idMem::Free(this: v221, ptr: v234, align: ALIGN_16);
        }
        else
        {
          v250[0] = 0;
          v246.file->Write(this: v246.file, a2: v250, a3: 1u);
        }
        if ( v224 != nullptr )
          idMem::Free(this: v221, ptr: v224, align: ALIGN_16);
        if ( v200 != nullptr )
          idMem::Free(this: v221, ptr: v200, align: ALIGN_16);
        v239 = *(_DWORD *)(v4 + 148);
        ++v254;
        v253 += 4;
      }
      while ( v254 < v239 );
    }
    v260 = *(_DWORD *)(v4 + 164);
    v246.file->Write(this: v246.file, a2: &v260, a3: 4u);
    v240 = 0;
    if ( *(int *)(v4 + 164) > 0 )
    {
      v241 = 0;
      do
      {
        v242 = &v266;
        v243 = (_DWORD *)(v241 + *(_DWORD *)(v4 + 160) - 4);
        for ( i = 5; i != 0; --i )
          *++v242 = *++v243;
        idFile::WriteString(this: v246.file, string: v267->name.str);
        ScriptP = idLexer::GetScriptP(this: v267);
        v246.file->Write(this: v246.file, a2: &ScriptP, a3: 4u);
        v246.file->Write(this: v246.file, a2: &v268, a3: 4u);
        v246.file->Write(this: v246.file, a2: &v269, a3: 4u);
        v246.file->Write(this: v246.file, a2: &v270, a3: 4u);
        ++v240;
        v241 += 20;
      }
      while ( v240 < *(_DWORD *)(v4 + 164) );
    }
    v246.file->Write(this: v246.file, a2: v263, a3: 4u);
    idFileLocal::~idFileLocal(this: &v246);
    result = 1;
  }
  else
  {
    idLib::Warning(fmt: "Could not open %s", v5);
    idFileLocal::~idFileLocal(this: &v246);
    result = 0;
  }
  _R0 = -256;
  __asm { lvx128    v127, r1, r0 }
  return result;
}


// ========================================================================
// __unwind$232358
// EA  : 0x82849ABC
// RVA : 0x00849ABC
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_232358()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 29152 + 80));
}


// ========================================================================
// __unwind$232359
// EA  : 0x82849AE4
// RVA : 0x00849AE4
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_232359()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 29152 + 216));
}


// ========================================================================
// __unwind$232360
// EA  : 0x82849B0C
// RVA : 0x00849B0C
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_232360()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 29152 + 200));
}


// ========================================================================
// __unwind$232361
// EA  : 0x82849B34
// RVA : 0x00849B34
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_232361()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 29152 + 208));
}


// ========================================================================
// SetupJointRemap
// EA  : 0x8284A318
// RVA : 0x0084A318
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall SetupJointRemap(
        __int64 usedJoints,
        __int64 jointRemap,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14)
{
  int v14; // r26
  int v15; // r11
  int v16; // r10
  idList<unsigned char,37> *v17; // r23
  int v18; // r30
  int v19; // r24
  int size; // r11
  int v21; // r11
  int i; // ctr
  int v23; // r29
  int v24; // r11
  int v25; // r30
  int v26; // r11
  int v27; // r11
  int v28; // r10
  int v29; // r11
  int v30; // r25
  int num; // r27
  idIndex<short,enum invalidUserChannelIndex_t> *j; // r28
  int v33; // r29
  int v34; // r30
  int v35; // r11
  __int16 value; // r9
  int v37; // r10
  idIndex<short,enum invalidUserChannelIndex_t> *v38; // r11
  int v39; // r29
  int v40; // r11
  int v41; // r30
  int v42; // r11
  idIndex<short,enum invalidUserChannelIndex_t> *v43; // r9
  int k; // ctr
  int v45; // r11
  int v46; // r11
  _DWORD v47[4]; // [sp+50h] [-80h] BYREF
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5> v48[7]; // [sp+60h] [-70h] BYREF

  a8 = usedJoints;
  v14 = HIDWORD(usedJoints);
  v15 = *(_DWORD *)(HIDWORD(usedJoints) + 40);
  a9 = *(__int64 *)((char *)&jointRemap + 4);
  a10 = jointRemap;
  a11 = *(__int64 *)((char *)&a3 + 4);
  a12 = a3;
  a13 = *(__int64 *)((char *)&a4 + 4);
  a14 = a4;
  v16 = *(unsigned __int16 *)(v15 + 2);
  v17 = (idList<unsigned char,37> *)STACK[0x1FC];
  v18 = (v16 + 7) & 0xFFF8;
  v19 = (unsigned __int16)v16;
  HIWORD(v47[0]) = *(_WORD *)(v15 + 2);
  if ( v18 <= v17->size || idList<unsigned char,25>::Resize(this: v17, newsize: (v16 + 7) & 0xFFF8) )
  {
    size = v17->size;
    if ( v18 < size )
      size = v18;
    v17->num = size;
  }
  v21 = 0;
  if ( v18 > 0 )
  {
    for ( i = v18; i != 0; --i )
      v17->list[v21++] = 0;
  }
  if ( HIBYTE(STACK[0x1F7]) != 0 )
  {
    v48[0].listStatic = 0;
    v48[0].memTag = 5;
    memset(v48, 0, 14);
    if ( v18 > 0 )
      idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,5>::Resize(this: v48, newsize: v18);
    HIWORD(v47[0]) = 0;
    idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
      this: v48,
      obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)v47);
    v30 = 0;
    num = v48[0].num;
    for ( j = v48[0].list; v30 < num; ++v30 )
    {
      v33 = 0;
      if ( v19 > 0 )
      {
        v34 = v30;
        do
        {
          v35 = *(_DWORD *)(v14 + 40);
          value = j[v34].value;
          v47[0] = &j[v34];
          if ( *(__int16 *)(*(unsigned __int16 *)(v35 + 14) + 2 * (__int16)v33 + v35) == value )
          {
            HIWORD(v47[0]) = v33;
            v37 = 0;
            if ( num <= 0 )
              goto LABEL_36;
            v38 = j;
            while ( v38->value != (__int16)v33 )
            {
              ++v37;
              ++v38;
              if ( v37 >= num )
                goto LABEL_36;
            }
            if ( v37 < 0 )
            {
LABEL_36:
              idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
                this: v48,
                obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)v47);
              num = v48[0].num;
              j = v48[0].list;
            }
          }
          ++v33;
        }
        while ( v33 < v19 );
      }
    }
    v39 = 0;
    v40 = *(unsigned __int16 *)(*(_DWORD *)(v14 + 40) + 2);
    v41 = (v40 + 7) & 0xFFF8;
    if ( v41 <= v17->size || idList<unsigned char,25>::Resize(this: v17, newsize: (v40 + 7) & 0xFFF8) )
    {
      v42 = v17->size;
      if ( v41 < v42 )
        v42 = v41;
      v17->num = v42;
    }
    if ( num > 0 )
    {
      v43 = j;
      for ( k = num; k != 0; --k )
      {
        v45 = v43->value;
        if ( *((_BYTE *)&a8 + v45) != 0 )
          v17->list[v45] = v39++;
        ++v43;
      }
    }
    v46 = 0;
    if ( ((*(unsigned __int16 *)(*(_DWORD *)(v14 + 40) + 2) + 7) & 0xFFF8) != 0 )
    {
      do
      {
        if ( *((_BYTE *)&a8 + v46) == 0 )
          v17->list[v46] = v39++;
        ++v46;
      }
      while ( v46 < ((*(unsigned __int16 *)(*(_DWORD *)(v14 + 40) + 2) + 7) & 0xFFF8) );
    }
    if ( (v48[0].listStatic == 0 || v48[0].listStatic == 2) && j != nullptr )
      idMem::Free(this: &mem, ptr: j, align: ALIGN_16);
  }
  else
  {
    v23 = 0;
    v24 = *(unsigned __int16 *)(*(_DWORD *)(v14 + 40) + 2);
    v25 = (v24 + 7) & 0xFFF8;
    if ( v25 <= v17->size || idList<unsigned char,25>::Resize(this: v17, newsize: (v24 + 7) & 0xFFF8) )
    {
      v26 = v17->size;
      if ( v25 < v26 )
        v26 = v25;
      v17->num = v26;
    }
    v27 = 0;
    v28 = (*(unsigned __int16 *)(*(_DWORD *)(v14 + 40) + 2) + 7) & 0xFFF8;
    if ( v28 != 0 )
    {
      do
      {
        if ( *((_BYTE *)&a8 + v27) != 0 )
          v17->list[v27] = v23++;
        ++v27;
        v28 = (*(unsigned __int16 *)(*(_DWORD *)(v14 + 40) + 2) + 7) & 0xFFF8;
      }
      while ( v27 < v28 );
    }
    v29 = 0;
    if ( v28 > 0 )
    {
      do
      {
        if ( *((_BYTE *)&a8 + v29) == 0 )
          v17->list[v29] = v23++;
        ++v29;
      }
      while ( v29 < ((*(unsigned __int16 *)(*(_DWORD *)(v14 + 40) + 2) + 7) & 0xFFF8) );
    }
  }
}


// ========================================================================
// __unwind$235003
// EA  : 0x8284A6F4
// RVA : 0x0084A6F4
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_235003()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ?LoadMorphMap@idMD6BinaryGenerator@@QAAXPBDABVidVec3@@AAV?$idList@UvertexMorphOffset_t@@$04@@@Z
// EA  : 0x8284B150
// RVA : 0x0084B150
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall idMD6BinaryGenerator::LoadMorphMap(
        idMD6BinaryGenerator *this,
        char *fileName,
        const idVec3 *offset,
        idList<eboltControlNode_t,5> *vertexMorphOffsets)
{
  st_lwObject *Object; // r3
  st_lwObject *v7; // r20
  st_lwLayer *layer; // r27
  int count; // r4
  int v10; // r21
  int v11; // r26
  int v12; // r22
  st_lwVMapList *ptVMaps; // r11
  st_lwVMapList *v14; // r28
  int v15; // r25
  int v16; // r29
  st_lwVMapPt *v17; // r11
  float *pos; // r31
  float *v19; // r19
  vertexMorphOffset_t *v20; // r3
  double v21; // fp0
  double v22; // fp10
  double v23; // fp13
  double v24; // fp4
  double v25; // fp3
  int v26; // [sp+54h] [-7Ch] BYREF

  if ( fileName != nullptr && *fileName != 0 )
  {
    Object = lwGetObject(filename: fileName, forceSmooth: 0.0, failID: (unsigned int *)fileName, failpos: &v26);
    v7 = Object;
    if ( Object != nullptr )
    {
      layer = Object->layer;
      count = layer->point.count;
      if ( count > vertexMorphOffsets->size )
        idList<idTestEntity::test_t,5>::Resize(this: vertexMorphOffsets, newsize: count);
      v10 = 0;
      if ( layer->point.count > 0 )
      {
        v11 = 0;
        v12 = 0;
        do
        {
          ptVMaps = layer->point.ptVMaps;
          if ( ptVMaps != nullptr )
          {
            v14 = &ptVMaps[v12];
            v15 = 0;
            if ( ptVMaps[v12].nvmaps > 0 )
            {
              v16 = 0;
              do
              {
                v17 = &v14->vm[v16];
                if ( v17->vmap->type == 1297044038 )
                {
                  pos = layer->point.pt[v11].pos;
                  v19 = v17->vmap->val[v17->index];
                  v20 = idList<vertexMorphOffset_t,5>::Alloc(this: (idList<vertexMorphOffset_t,5> *)vertexMorphOffsets);
                  v21 = pos[1];
                  v22 = *pos;
                  v23 = pos[2];
                  v20->xyz.x = *pos;
                  v20->xyz.y = v23;
                  v20->xyz.z = v21;
                  v20->xyz.x = (float)v22 + offset->x;
                  v20->xyz.y = offset->y + (float)v23;
                  v20->xyz.z = offset->z + (float)v21;
                  v24 = v19[1];
                  v25 = v19[2];
                  v20->offset.x = *v19;
                  v20->offset.y = v25;
                  v20->offset.z = v24;
                }
                ++v15;
                ++v16;
              }
              while ( v15 < v14->nvmaps );
            }
          }
          ++v10;
          ++v12;
          ++v11;
        }
        while ( v10 < layer->point.count );
      }
      lwFreeObject(object: v7);
    }
  }
}


// ========================================================================
// ?ParseMD6MeshToSurfaces@@YAXHAAVidLexer@@H_NABV?$idList@F$04@@AAV?$idList@PAUidProcessSurface@@$04@@@Z
// EA  : 0x8284B5C8
// RVA : 0x0084B5C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ParseMD6MeshToSurfaces(
        int md6Version,
        idLexer *parser,
        int numJoints,
        bool hasExportedNormals,
        const idList<short,5> *remapTable,
        idList<enum encounterGroupRole_t,5> *surfaces)
{
  int v6; // r22
  int v7; // r23
  bool v10; // r21
  idList<enum encounterGroupRole_t,5> *v12; // r19
  int len; // r30
  const char *v15; // r24
  int v16; // r30
  const idDecl *v17; // r3
  const idDecl *v18; // r3
  bool v19; // r3
  int v20; // r25
  int v21; // r3
  int v22; // r11
  bool v23; // cr56
  int v24; // r29
  int i; // r30
  processST_t *v26; // r28
  int size; // r11
  bool v28; // cr57
  int v29; // r17
  int v30; // r30
  int j; // r28
  processST_t *v32; // r29
  int v33; // r11
  int v34; // r11
  bool v35; // cr56
  char v36; // r3
  BOOL v37; // r18
  int v38; // r21
  processVert_t *v39; // r23
  int v40; // r30
  int v41; // r29
  int v42; // r29
  unsigned __int8 *jointIdxs; // r24
  unsigned __int8 *weights; // r25
  float *v45; // r26
  unsigned __int8 v46; // r11
  int v47; // r30
  char v48; // r11
  char v49; // r28
  __int16 v50; // r8
  int v51; // r8
  int k; // r7
  int v53; // r11
  unsigned __int8 *v54; // r10
  int v55; // ctr
  unsigned int v56; // r9
  unsigned __int8 v57; // r4
  unsigned __int8 v58; // r9
  int v59; // r3
  int v60; // r10
  int v61; // r28
  int v62; // r25
  bool v63; // cr56
  int v64; // r30
  int *list; // r29
  int *v66; // r29
  int *v67; // r29
  int numVerts; // r5
  int v70; // r9
  int v72; // r10
  idDrawVert *v76; // r7
  processVert_t *v77; // r8
  processVert_t *v78; // r8
  int v79; // r11
  processST_t *v80; // r4
  int v81; // r8
  int v82; // r9
  int v83; // r10
  float *p_x; // r7
  idDrawVert *v85; // r11
  int v86; // r7
  int v87; // r8
  int v88; // r9
  int numIndexes; // r4
  int v98; // r9
  int v99; // r10
  int v100; // r11
  int v101; // r6
  int v102; // r2 OVERLAPPED
  int v103; // r5
  int v104; // r8
  __int64 v105; // r10
  __int64 v106; // r7
  processVert_t *v107; // r11
  __int64 v108; // r4
  double v109; // fp1
  double v110; // fp5
  double v111; // fp4
  double v114; // fp3
  double v115; // fp11
  __int64 v116; // fp1
  processVert_t *v117; // r11
  double v118; // fp2
  double v119; // fp6
  double v120; // fp5
  double v123; // fp4
  double v124; // fp1
  double v125; // fp11
  int listStatic; // r11
  encounterGroupRole_t *v127; // r4
  int num; // r11
  int v129; // r15
  encounterGroupRole_t *v130; // r14
  char *v131; // r3
  char *v132; // r30
  char *v133; // r24
  int v134; // r11
  size_t v135; // r30
  int v136; // r4
  _DWORD *v137; // r22
  int v138; // r17
  int v139; // r11
  int v140; // r11
  int v141; // ctr
  processST_t *v142; // r10
  int v143; // r9
  idSpawnArea::GeneratedPosition **v144; // r19
  int v145; // r11
  int v146; // r30
  char v147; // r3
  int v148; // r10
  idSpawnArea::GeneratedPosition **v149; // r11
  int m; // ctr
  int v151; // r18
  int v152; // r21
  int v153; // r20
  int v154; // r26
  int n; // r25
  int v156; // r30
  encounterGroupRole_t *v157; // r27
  int v158; // r28
  int v159; // r30
  int ii; // r29
  char v161; // [sp+50h] [-260h]
  bool v162; // [sp+51h] [-25Fh]
  __int64 v163; // [sp+58h] [-258h] BYREF
  __int64 v164; // [sp+60h] [-250h] BYREF
  __int64 v165; // [sp+68h] [-248h]
  int v166; // [sp+70h] [-240h]
  idList<enum encounterGroupRole_t,5> v167; // [sp+80h] [-230h] BYREF
  idProcessMesh v168; // [sp+90h] [-220h] BYREF
  idList<idSpawnArea::GeneratedPosition *,5> v169; // [sp+E0h] [-1D0h] BYREF
  int v170; // [sp+F0h] [-1C0h] BYREF
  __int64 v171; // [sp+100h] [-1B0h]
  __int64 v172; // [sp+108h] [-1A8h]
  idStr v173; // [sp+110h] [-1A0h] BYREF
  idToken v174; // [sp+130h] [-180h] BYREF
  idTriangles v175; // [sp+180h] [-130h] BYREF

  v6 = 0;
  v174.len = 0;
  v7 = md6Version;
  v174.allocedAndFlag = 20;
  v174.floatvalue = -3.4028235e38;
  v10 = hasExportedNormals;
  v174.data = v174.baseBuffer;
  v174.baseBuffer[0] = 0;
  v12 = surfaces;
  v174.intvalue = 0;
  memset(&v174.whiteSpaceStart_p, 0, 12);
  v173.allocedAndFlag = 20;
  v173.data = v173.baseBuffer;
  v173.len = 0;
  v173.baseBuffer[0] = 0;
  _R20 = 1;
  v161 = 0;
  idProcessMesh::idProcessMesh(this: &v168);
  idLexer::ExpectTokenString(this: parser, string: "{");
  idLexer::ExpectTokenString(this: parser, string: "name");
  idLexer::ReadToken(this: parser, token: &v174);
  len = v174.len;
  idStr::EnsureAlloced(this: &v173, amount: v174.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v173.data, Src: v174.data, Size: len);
  v167.list = nullptr;
  *(_DWORD *)&v167.granularity = 1280;
  v173.data[len] = 0;
  *(_QWORD *)&v167.num = 0;
  v173.len = len;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v167);
  v15 = "}";
  HIDWORD(v165) = "}";
  if ( v7 < 5 )
  {
    idLexer::ExpectTokenString(this: parser, string: "shader");
    idLexer::ReadToken(this: parser, token: &v174);
    if ( v174.data != nullptr )
      v18 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: v174.data, makeDefault: true);
    else
      v18 = nullptr;
    HIDWORD(v163) = v18;
    idList<idAnimWebBlendTree *,5>::Append(this: &v167, obj: (const encounterGroupRole_t *)&v163);
  }
  else
  {
    idLexer::ExpectTokenString(this: parser, string: "shaders");
    v16 = idLexer::ParseInt(this: parser);
    memset(Dst: v168.vertexes.list, Val: 0, Size: 52 * v168.vertexes.size);
    idLexer::ExpectTokenString(this: parser, string: "{");
    if ( v16 > 0 )
    {
      do
      {
        idLexer::ExpectTokenString(this: parser, string: "shader");
        idLexer::ParseInt(this: parser);
        idLexer::ReadToken(this: parser, token: &v174);
        if ( v174.data != nullptr )
          v17 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: v174.data, makeDefault: true);
        else
          v17 = nullptr;
        HIDWORD(v163) = v17;
        idList<idAnimWebBlendTree *,5>::Append(this: &v167, obj: (const encounterGroupRole_t *)&v163);
        --v16;
      }
      while ( v16 != 0 );
    }
    idLexer::ExpectTokenString(this: parser, string: "}");
  }
  if ( idLexer::CheckTokenString(this: parser, string: "discrete")
    || idLexer::CheckTokenString(this: parser, string: "nomerge") )
  {
    v161 = 1;
  }
  v19 = idLexer::CheckTokenString(this: parser, string: "noSkinRemapping");
  v166 = 1;
  v162 = !v19;
  v20 = 1;
  if ( !idLexer::CheckTokenString(this: parser, string: "uvsets") )
  {
    size = v168.uvs.size;
    v28 = v168.uvs.size > 1;
    if ( v168.uvs.size < 1 )
    {
      if ( (unsigned __int8)idList<processST_t,5>::Resize(this: &v168.uvs, newsize: 1) == 0 )
      {
LABEL_30:
        v168.uvs.list->slot = 0;
        goto LABEL_31;
      }
      size = v168.uvs.size;
      v28 = v168.uvs.size > 1;
    }
    v168.uvs.num = 1;
    if ( !v28 )
      v168.uvs.num = size;
    goto LABEL_30;
  }
  v21 = idLexer::ParseInt(this: parser);
  v22 = v168.uvs.size;
  v20 = v21;
  v166 = v21;
  v23 = v21 < v168.uvs.size;
  if ( v21 <= v168.uvs.size )
    goto LABEL_19;
  if ( (unsigned __int8)idList<processST_t,5>::Resize(this: &v168.uvs, newsize: v21) != 0 )
  {
    v22 = v168.uvs.size;
    v23 = v20 < v168.uvs.size;
LABEL_19:
    v168.uvs.num = v20;
    if ( !v23 )
      v168.uvs.num = v22;
  }
  idLexer::ExpectTokenString(this: parser, string: "{");
  if ( v20 > 0 )
  {
    v24 = 0;
    for ( i = v20; i != 0; --i )
    {
      v26 = &v168.uvs.list[v24];
      idLexer::ExpectTokenString(this: parser, string: "name");
      v26->slot = idLexer::ParseInt(this: parser);
      idLexer::ReadToken(this: parser, token: &v174);
      ++v24;
    }
  }
  idLexer::ExpectTokenString(this: parser, string: "}");
LABEL_31:
  idLexer::ExpectTokenString(this: parser, string: "verts");
  v29 = idLexer::ParseInt(this: parser);
  if ( v20 > 0 )
  {
    v30 = 0;
    for ( j = v20; j != 0; --j )
    {
      v32 = &v168.uvs.list[v30];
      if ( v29 <= v168.uvs.list[v30].st.size
        || (unsigned __int8)idList<idVec2,72>::Resize(this: (idList<idVec2,72> *)&v168.uvs.list[v30], newsize: v29) != 0 )
      {
        v33 = v32->st.size;
        if ( v29 < v33 )
          v33 = v29;
        v32->st.num = v33;
      }
      memset(Dst: v168.uvs.list[v30].st.list, Val: 0, Size: 8 * v168.uvs.list[v30].st.size);
      ++v30;
    }
  }
  v34 = v168.vertexes.size;
  v35 = v29 < v168.vertexes.size;
  if ( v29 > v168.vertexes.size )
  {
    v36 = idList<processVert_t,5>::Resize(this: &v168.vertexes, newsize: v29);
    v34 = v168.vertexes.size;
    if ( v36 == 0 )
      goto LABEL_44;
    v35 = v29 < v168.vertexes.size;
  }
  v168.vertexes.num = v29;
  if ( !v35 )
    v168.vertexes.num = v34;
LABEL_44:
  memset(Dst: v168.vertexes.list, Val: 0, Size: 52 * v34);
  idLexer::ExpectTokenString(this: parser, string: "{");
  if ( v29 > 0 )
  {
    v37 = v10;
    v38 = 0;
    do
    {
      idLexer::ExpectTokenString(this: parser, string: "vert");
      idLexer::ParseInt(this: parser);
      v39 = &v168.vertexes.list[v38];
      idLexer::Parse1DMatrix(this: parser, x: 3, m: &v168.vertexes.list[v38].xyz.x, expectCommas: false);
      if ( v37 )
        idLexer::Parse1DMatrix(this: parser, x: 3, m: &v39->normal.x, expectCommas: false);
      v40 = v166;
      if ( v166 > 0 )
      {
        v41 = 0;
        do
        {
          idLexer::Parse1DMatrix(this: parser, x: 2, m: &v168.uvs.list[v41].st.list[v6].x, expectCommas: false);
          --v40;
          ++v41;
        }
        while ( v40 != 0 );
      }
      idLexer::Parse1DMatrix(this: parser, x: 8, m: (float *)&v169, expectCommas: false);
      v42 = 0;
      jointIdxs = v39->jointIdxs;
      weights = v39->weights;
      v45 = (float *)&v170;
      do
      {
        LODWORD(v164) = (int)*(v45 - 4);
        if ( (int)v164 >= 0 )
        {
          if ( (int)v164 <= 255 )
            v46 = v164;
          else
            v46 = -1;
        }
        else
        {
          v46 = 0;
        }
        v47 = v46;
        LODWORD(v164) = (int)(float)(*v45 * (float)255.0);
        if ( (int)v164 >= 0 )
        {
          if ( (int)v164 <= 255 )
            v48 = v164;
          else
            v48 = -1;
        }
        else
        {
          v48 = 0;
        }
        v49 = v48;
        if ( v47 >= numJoints )
          idLexer::Error(this: parser, str: "Joint index out of range(%d): %d", numJoints, v47);
        ++v45;
        v50 = remapTable->list[v47];
        weights[v42] = v49;
        jointIdxs[v42++] = v50;
      }
      while ( v42 < 4 );
      v51 = 1;
      for ( k = 3; k != 0; --k )
      {
        v53 = v51;
        if ( v51 < 4 )
        {
          v54 = &v39[-1].jointIdxs[v51 + 3];
          v55 = 4 - v51;
          do
          {
            v56 = weights[v53];
            if ( v56 > v54[44] )
            {
              v57 = v54[44];
              v54[44] = v56;
              HIDWORD(v164) = v54 + 48;
              weights[v53] = v57;
              v58 = v54[48];
              v54[48] = jointIdxs[v53];
              jointIdxs[v53] = v58;
            }
            ++v53;
            --v55;
          }
          while ( v55 != 0 );
        }
        ++v51;
      }
      ++v6;
      ++v38;
      *weights = -1 - v39->weights[3] - v39->weights[2] - v39->weights[1];
    }
    while ( v6 < v29 );
    v7 = md6Version;
    _R20 = 1;
    v15 = (const char *)HIDWORD(v165);
    v10 = hasExportedNormals;
    v12 = surfaces;
  }
  idLexer::ExpectTokenString(this: parser, string: v15);
  idLexer::ExpectTokenString(this: parser, string: "tris");
  v59 = idLexer::ParseInt(this: parser);
  v60 = v168.indexes.size;
  v61 = v59;
  v62 = 3 * v59;
  v63 = 3 * v59 < v168.indexes.size;
  if ( 3 * v59 > v168.indexes.size )
  {
    if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(
                            this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v168.indexes,
                            newsize: 3 * v59) == 0 )
      goto LABEL_79;
    v60 = v168.indexes.size;
    v63 = v62 < v168.indexes.size;
  }
  v168.indexes.num = v62;
  if ( !v63 )
    v168.indexes.num = v60;
LABEL_79:
  idLexer::ExpectTokenString(this: parser, string: "{");
  if ( v61 > 0 )
  {
    v64 = 0;
    do
    {
      idLexer::ExpectTokenString(this: parser, string: "tri");
      idLexer::ParseInt(this: parser);
      HIDWORD(v163) = 0;
      if ( v7 >= 5 )
        HIDWORD(v163) = idLexer::ParseInt(this: parser);
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&v168.faceMaterialIndex,
        obj: (const encounterGroupRole_t *)&v163);
      list = v168.indexes.list;
      list[v64] = idLexer::ParseInt(this: parser);
      v66 = &v168.indexes.list[v64];
      v66[1] = idLexer::ParseInt(this: parser);
      v67 = &v168.indexes.list[v64];
      --v61;
      v67[2] = idLexer::ParseInt(this: parser);
      v64 += 3;
    }
    while ( v61 != 0 );
  }
  idLexer::ExpectTokenString(this: parser, string: v15);
  idLexer::ExpectTokenString(this: parser, string: v15);
  idTriangles::idTriangles(this: &v175);
  v175.numVerts = v29;
  v175.numIndexes = v62;
  v175.generateNormals = (_cntlzw(v10) & 0x20) != 0;
  idTriangles::AllocStaticTriSurfVerts(this: &v175, numVerts: v29);
  idTriangles::AllocStaticTriSurfIndexes(this: &v175, numIndexes: v175.numIndexes);
  numVerts = v175.numVerts;
  v70 = 0;
  if ( v175.numVerts > 0 )
  {
    __asm { vspltisw128 v63, 0 }
    _R11 = 0;
    v72 = 0;
    _R4 = 16;
    __asm
    {
      vcmpequw128 v62, v95, v63
      vsldoi128 v62, v95, v62, 4
    }
    do
    {
      _R8 = v175.verts;
      ++v70;
      _R7 = &v175.verts[_R11];
      __asm
      {
        stvx128   v63, r11, r8
        stvx128   v62, r7, r4
      }
      v76 = &v175.verts[_R11];
      v77 = v168.vertexes.list;
      v76->xyz.x = v168.vertexes.list[v72].xyz.x;
      v78 = &v77[v72++];
      v76->xyz.y = v78->xyz.y;
      ++_R11;
      v76->xyz.z = v78->xyz.z;
      numVerts = v175.numVerts;
    }
    while ( v70 < v175.numVerts );
  }
  v79 = 0;
  if ( v168.uvs.num > 0 )
  {
    v80 = v168.uvs.list;
    while ( v80->slot != 0 )
    {
      ++v79;
      ++v80;
      if ( v79 >= v168.uvs.num )
        goto LABEL_95;
    }
    v81 = 0;
    if ( numVerts > 0 )
    {
      v82 = 0;
      v83 = 0;
      do
      {
        ++v81;
        p_x = &v80->st.list[v83].x;
        v85 = &v175.verts[v82];
        ++v83;
        ++v82;
        v85->st.x = *p_x;
        v85->st.y = p_x[1];
        numVerts = v175.numVerts;
      }
      while ( v81 < v175.numVerts );
    }
  }
LABEL_95:
  if ( v10 )
  {
    v86 = 0;
    if ( numVerts > 0 )
    {
      __asm { vspltisw128 v62, 0 }
      v87 = 0;
      v88 = 0;
      _R28 = 4;
      _R29 = 8;
      _R30 = 2;
      _R6 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
      _R4 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
      _R3 = &_vmx_3f8000003f8000003f8000003f800000;
      do
      {
        __asm
        {
          vor128    v61, v94, v62
          lvx128    v63, r0, r3
        }
        __asm
        {
          lvx128    v0, r0, r4
          lvx128    v13, r0, r6
        }
        _R11 = &v168.vertexes.list[v88].normal;
        _R10 = v175.verts[v87].normal;
        ++v86;
        ++v88;
        ++v87;
        __asm
        {
          lvlx128   v60, r0, r11
          vrlimi128 v61, v60, 8, 0
          lvlx128   v59, r11, r28
          lvlx128   v58, r11, r29
          vrlimi128 v61, v59, 4, 3
          vrlimi128 v61, v58, 2, 2
          vaddfp128 v12, v93, v63
          vmaddfp   v0, v12, v0, v13
          vcfpsxws128 v57, v0, 0
          vpkswss128 v56, v89, v57
          vpkshus128 v0, v88, v56
          stvebx    v0, 0, r10
          stvebx    v0, r10, r20
          stvebx    v0, r10, r30
        }
        numVerts = v175.numVerts;
      }
      while ( v86 < v175.numVerts );
    }
  }
  numIndexes = v175.numIndexes;
  v98 = 0;
  if ( v175.numIndexes > 0 )
  {
    v99 = 0;
    v100 = 0;
    do
    {
      ++v98;
      v101 = v168.indexes.list[v100++];
      v175.indexes[v99++] = v101;
      numIndexes = v175.numIndexes;
    }
    while ( v98 < v175.numIndexes );
    numVerts = v175.numVerts;
  }
  idTriangles::RangeCheckIndexes(indexes: v175.indexes, numIndexes, numVerts);
  idTriangles::DeriveTangents(this: &v175);
  v103 = 0;
  if ( v175.numVerts > 0 )
  {
    v104 = 0;
    HIDWORD(v105) = 0;
    HIDWORD(v106) = &si_vector_decode_cat_0[184];
    do
    {
      v107 = &v168.vertexes.list[v104];
      HIDWORD(v108) = v175.verts->normal[HIDWORD(v105)];
      LODWORD(v106) = v175.verts->normal[HIDWORD(v105) + 2];
      LODWORD(v105) = v175.verts->normal[HIDWORD(v105) + 1];
      v164 = *(_QWORD *)(&v102 - 1);
      v171 = v106;
      v172 = v105;
      v109 = (float)((float)((float)v105 * (float)0.0078431377) - (float)1.0);
      v110 = (float)((float)((float)*(__int64 *)(&v102 - 1) * (float)0.0078431377) - (float)1.0);
      v111 = (float)((float)((float)v106 * (float)0.0078431377) - (float)1.0);
      _FP8 = (float)((float)((float)((float)v111 * (float)v111)
                           + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f6, f8, f2, f11 }
      v114 = __frsqrte(_FP6);
      v115 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v114
                                                                                           * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5))
                                                                                   * (float)v114)
                                                                           - (float)1.5)
                                                           * (float)v114)
                                                   * (float)((float)((float)((float)v111 * (float)v111)
                                                                   + (float)((float)((float)v110 * (float)v110)
                                                                           + (float)((float)v109 * (float)v109)))
                                                           * (float)0.5))
                                           * (float)((float)-(float)((float)((float)((float)v114
                                                                                   * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109)))
                                                                                           * (float)0.5))
                                                                           * (float)v114)
                                                                   - (float)1.5)
                                                   * (float)v114))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v114
                                                           * (float)((float)((float)((float)v111 * (float)v111)
                                                                           + (float)((float)((float)v110 * (float)v110)
                                                                                   + (float)((float)v109 * (float)v109)))
                                                                   * (float)0.5))
                                                   * (float)v114)
                                           - (float)1.5)
                           * (float)v114));
      v107->normal.y = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5)) * (float)v114) - (float)1.5) * (float)v114) * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5)) * (float)v114) - (float)1.5) * (float)v114))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5)) * (float)v114)
                                                                                             - (float)1.5)
                                                                             * (float)v114))
                                                             * (float)((float)((float)((float)v111 * (float)v111)
                                                                             + (float)((float)((float)v110 * (float)v110)
                                                                                     + (float)((float)v109 * (float)v109)))
                                                                     * (float)0.5))
                                                     * (float)v115)
                                             - (float)1.5)
                             * (float)v115)
                     * (float)v109;
      v107->normal.z = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5)) * (float)v114) - (float)1.5) * (float)v114) * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5)) * (float)v114) - (float)1.5) * (float)v114))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5)) * (float)v114)
                                                                                             - (float)1.5)
                                                                             * (float)v114))
                                                             * (float)((float)((float)((float)v111 * (float)v111)
                                                                             + (float)((float)((float)v110 * (float)v110)
                                                                                     + (float)((float)v109 * (float)v109)))
                                                                     * (float)0.5))
                                                     * (float)v115)
                                             - (float)1.5)
                             * (float)v115)
                     * (float)v111;
      v107->normal.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5)) * (float)v114) - (float)1.5) * (float)v114) * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5)) * (float)v114) - (float)1.5) * (float)v114))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v114 * (float)((float)((float)((float)v111 * (float)v111) + (float)((float)((float)v110 * (float)v110) + (float)((float)v109 * (float)v109))) * (float)0.5)) * (float)v114)
                                                                                             - (float)1.5)
                                                                             * (float)v114))
                                                             * (float)((float)((float)((float)v111 * (float)v111)
                                                                             + (float)((float)((float)v110 * (float)v110)
                                                                                     + (float)((float)v109 * (float)v109)))
                                                                     * (float)0.5))
                                                     * (float)v115)
                                             - (float)1.5)
                             * (float)v115)
                     * (float)v110;
      LODWORD(v105) = v175.verts->tangent[HIDWORD(v105) + 2];
      LODWORD(v108) = v175.verts->tangent[HIDWORD(v105) + 1];
      v165 = v108;
      v116 = v108;
      *(_QWORD *)&v169.list = v105;
      HIDWORD(v108) = v175.verts->tangent[HIDWORD(v105)];
      v163 = *(_QWORD *)(&v102 - 1);
      v117 = &v168.vertexes.list[v104];
      v118 = (float)((float)((float)v116 * (float)0.0078431377) - (float)1.0);
      v119 = (float)((float)((float)*(__int64 *)(&v102 - 1) * (float)0.0078431377) - (float)1.0);
      v120 = (float)((float)((float)v105 * (float)0.0078431377) - (float)1.0);
      _FP1 = (float)((float)((float)((float)v120 * (float)v120)
                           + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f7, f1, f3, f11 }
      v123 = __frsqrte(_FP7);
      v124 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123
                                                                                           * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5))
                                                                                   * (float)v123)
                                                                           - (float)1.5)
                                                           * (float)v123)
                                                   * (float)((float)((float)((float)v120 * (float)v120)
                                                                   + (float)((float)((float)v119 * (float)v119)
                                                                           + (float)((float)v118 * (float)v118)))
                                                           * (float)0.5))
                                           * (float)((float)-(float)((float)((float)((float)v123
                                                                                   * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118)))
                                                                                           * (float)0.5))
                                                                           * (float)v123)
                                                                   - (float)1.5)
                                                   * (float)v123))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v123
                                                           * (float)((float)((float)((float)v120 * (float)v120)
                                                                           + (float)((float)((float)v119 * (float)v119)
                                                                                   + (float)((float)v118 * (float)v118)))
                                                                   * (float)0.5))
                                                   * (float)v123)
                                           - (float)1.5)
                           * (float)v123));
      v117->tangent.z = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123) - (float)1.5) * (float)v123) * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123) - (float)1.5) * (float)v123))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123)
                                                                                              - (float)1.5)
                                                                              * (float)v123))
                                                              * (float)((float)((float)((float)v120 * (float)v120)
                                                                              + (float)((float)((float)v119 * (float)v119)
                                                                                      + (float)((float)v118 * (float)v118)))
                                                                      * (float)0.5))
                                                      * (float)v124)
                                              - (float)1.5)
                              * (float)v124)
                      * (float)v120;
      v117->tangent.y = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123) - (float)1.5) * (float)v123) * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123) - (float)1.5) * (float)v123))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123)
                                                                                              - (float)1.5)
                                                                              * (float)v123))
                                                              * (float)((float)((float)((float)v120 * (float)v120)
                                                                              + (float)((float)((float)v119 * (float)v119)
                                                                                      + (float)((float)v118 * (float)v118)))
                                                                      * (float)0.5))
                                                      * (float)v124)
                                              - (float)1.5)
                              * (float)v124)
                      * (float)v118;
      v117->tangent.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123) - (float)1.5) * (float)v123) * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123) - (float)1.5) * (float)v123))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)v120 * (float)v120) + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) * (float)0.5)) * (float)v123)
                                                                                              - (float)1.5)
                                                                              * (float)v123))
                                                              * (float)((float)((float)((float)v120 * (float)v120)
                                                                              + (float)((float)((float)v119 * (float)v119)
                                                                                      + (float)((float)v118 * (float)v118)))
                                                                      * (float)0.5))
                                                      * (float)v124)
                                              - (float)1.5)
                              * (float)v124)
                      * (float)((float)((float)*(__int64 *)(&v102 - 1) * (float)0.0078431377) - (float)1.0);
      if ( v175.verts->tangent[HIDWORD(v105) + 3] >= 0x80u )
        v125 = 1.0;
      else
        v125 = -1.0;
      ++v103;
      HIDWORD(v105) += 32;
      v168.vertexes.list[v104++].tangent.w = v125;
    }
    while ( v103 < v175.numVerts );
  }
  listStatic = v12->listStatic;
  HIDWORD(v163) = &mem;
  if ( listStatic == 0 || listStatic == 2 )
  {
    v127 = v12->list;
    if ( v12->list != nullptr )
    {
      HIDWORD(v164) = v12->list;
      idMem::Free(this: &mem, ptr: v127, align: ALIGN_16);
    }
    v12->list = nullptr;
    v12->size = 0;
  }
  num = v167.num;
  v129 = 0;
  v12->num = 0;
  if ( num > 0 )
  {
    v130 = v167.list;
    HIDWORD(v171) = "w:\\tech5\\shared\\idlib\\text/Str.h";
    HIDWORD(v172) = "amount <= GetAlloced()";
    HIDWORD(v165) = "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW";
    while ( 1 )
    {
      v131 = (char *)idMem::AllocWithLocation(
                       this: (idMem *)HIDWORD(v163),
                       location: (const char *)HIDWORD(v165),
                       size: 0x78u,
                       tag: TAG_NEW,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
      v132 = v131;
      HIDWORD(v164) = v131;
      if ( v131 != nullptr )
      {
        *(_DWORD *)v131 = 0;
        *((_DWORD *)v131 + 1) = v131 + 12;
        *((_DWORD *)v131 + 2) = 20;
        v131[12] = 0;
        *((_DWORD *)v131 + 8) = 0;
        *((_WORD *)v131 + 18) = 1;
        *((_DWORD *)v131 + 10) = 1;
        idProcessMesh::idProcessMesh(this: (idProcessMesh *)(v131 + 44));
        v133 = v132;
      }
      else
      {
        v133 = nullptr;
      }
      v134 = *((_DWORD *)v133 + 2);
      v135 = v173.len;
      HIDWORD(v164) = v133;
      v136 = v173.len + 1;
      if ( v134 >= 0 )
      {
        if ( v136 > (v134 & 0x7FFFFFFF) )
          idStr::ReAllocate(this: (idStr *)v133, amount: v136, keepold: false);
      }
      else if ( v136 > (v134 & 0x7FFFFFFF)
             && AssertFailed(
                  file: (const char *)HIDWORD(v171),
                  line: 463,
                  expression: (const char *)HIDWORD(v172),
                  inlineBreak: true) )
      {
        __trap();
      }
      memcpy(Dst: *((void **)v133 + 1), Src: v173.data, Size: v135);
      v137 = v133 + 60;
      v138 = v166;
      *(_BYTE *)(v135 + *((_DWORD *)v133 + 1)) = 0;
      *(_DWORD *)v133 = v135;
      v133[36] = v161;
      v133[37] = v162;
      *((encounterGroupRole_t *)v133 + 8) = *v130;
      if ( v138 <= *((_DWORD *)v133 + 17)
        || (unsigned __int8)idList<processST_t,5>::Resize(this: (idList<processST_t,5> *)(v133 + 60), newsize: v138) != 0 )
      {
        v139 = *((_DWORD *)v133 + 17);
        if ( v138 < v139 )
          v139 = v138;
        *((_DWORD *)v133 + 16) = v139;
      }
      if ( v138 > 0 )
      {
        v140 = 0;
        v141 = v138;
        v142 = v168.uvs.list;
        do
        {
          v143 = v140 * 20 + *v137;
          ++v140;
          *(_BYTE *)(v143 + 16) = v142->slot;
          v142 = &v168.uvs.list[v140];
          --v141;
        }
        while ( v141 != 0 );
      }
      if ( idParmBlock::GetInteger(this: (idParmBlock *)(*((_DWORD *)v133 + 8) + 84), parm: rp->discrete) != 0 )
        v133[36] = 1;
      idList<idAnimWebBlendTree *,5>::Append(this: surfaces, obj: (const encounterGroupRole_t *)&v164);
      v144 = nullptr;
      v145 = 0;
      *(_WORD *)&v169.memTag = 1280;
      memset(&v169, 0, 14);
      v146 = v168.vertexes.num;
      if ( v168.vertexes.num <= 0 )
        goto LABEL_138;
      v147 = idList<idNavSpline *,5>::Resize(this: &v169, newsize: v168.vertexes.num);
      v144 = v169.list;
      if ( v147 != 0 )
        break;
      v148 = v169.num;
LABEL_142:
      if ( v148 > 0 )
      {
        v149 = v144 - 1;
        for ( m = v148; m != 0; --m )
          *++v149 = (idSpawnArea::GeneratedPosition *)-1;
      }
      v151 = 0;
      if ( v168.faceMaterialIndex.num > 0 )
      {
        v152 = 0;
        v153 = 0;
        do
        {
          if ( v168.faceMaterialIndex.list[v153] == v129 )
          {
            v154 = v152;
            for ( n = 3; n != 0; --n )
            {
              v156 = *(int *)((char *)v168.indexes.list + v154);
              v157 = (encounterGroupRole_t *)&v144[v156];
              if ( *v157 == -1 )
              {
                *v157 = *((encounterGroupRole_t *)v133 + 12);
                idList<processVert_t,5>::Append(
                  this: (idList<processVert_t,5> *)(v133 + 44),
                  obj: &v168.vertexes.list[v156]);
                if ( v138 > 0 )
                {
                  v158 = v156;
                  v159 = 0;
                  for ( ii = v138; ii != 0; --ii )
                  {
                    idList<idVec2,72>::Append(
                      this: (idList<idVec2,72> *)(v159 * 20 + *v137),
                      obj: &v168.uvs.list[v159].st.list[v158]);
                    ++v159;
                  }
                }
              }
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)(v133 + 76),
                obj: v157);
              v154 += 4;
            }
          }
          ++v151;
          ++v153;
          v152 += 12;
        }
        while ( v151 < v168.faceMaterialIndex.num );
      }
      if ( v169.listStatic == 0 || v169.listStatic == 2 )
      {
        if ( v144 != nullptr )
          idMem::Free(this: (idMem *)HIDWORD(v163), ptr: v144, align: ALIGN_16);
        v169.list = nullptr;
        v169.size = 0;
      }
      ++v129;
      ++v130;
      v169.num = 0;
      if ( v129 >= v167.num )
        goto LABEL_161;
    }
    v145 = v169.size;
LABEL_138:
    if ( v146 >= v145 )
    {
      v148 = v145;
      v169.num = v145;
    }
    else
    {
      v148 = v146;
      v169.num = v146;
    }
    goto LABEL_142;
  }
LABEL_161:
  idTriangles::~idTriangles(this: &v175);
  if ( (v167.listStatic == 0 || v167.listStatic == 2) && v167.list != nullptr )
    idMem::Free(this: (idMem *)HIDWORD(v163), ptr: v167.list, align: ALIGN_16);
  idProcessMesh::~idProcessMesh(this: &v168);
  idStr::FreeData(this: &v173);
  idStr::FreeData(this: &v174);
}


// ========================================================================
// __unwind$236128
// EA  : 0x8284C680
// RVA : 0x0084C680
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_236128()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 688 + 304));
}


// ========================================================================
// __unwind$236129
// EA  : 0x8284C6A8
// RVA : 0x0084C6A8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_236129()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 688 + 272));
}


// ========================================================================
// __unwind$236130
// EA  : 0x8284C6D0
// RVA : 0x0084C6D0
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_236130()
{
  int v0; // r12

  idProcessMesh::~idProcessMesh(this: (idProcessMesh *)(v0 - 688 + 144));
}


// ========================================================================
// __unwind$236131
// EA  : 0x8284C6F8
// RVA : 0x0084C6F8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_236131()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 688 + 128));
}


// ========================================================================
// __unwind$236132
// EA  : 0x8284C720
// RVA : 0x0084C720
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_236132()
{
  int v0; // r12

  idTriangles::~idTriangles(this: (idTriangles *)(v0 - 688 + 384));
}


// ========================================================================
// __unwind$236133
// EA  : 0x8284C748
// RVA : 0x0084C748
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall _unwind_236133(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 688 + 96), tag: a2);
}


// ========================================================================
// __unwind$236689
// EA  : 0x8284C770
// RVA : 0x0084C770
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_236689()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 688 + 96));
}


// ========================================================================
// __unwind$236134
// EA  : 0x8284C798
// RVA : 0x0084C798
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_236134()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 688 + 224));
}


// ========================================================================
// ?MergeMeshesAndBuildSourceSurfaces@idMD6BinaryGenerator@@QAAXH@Z
// EA  : 0x8284CB60
// RVA : 0x0084CB60
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall idMD6BinaryGenerator::MergeMeshesAndBuildSourceSurfaces(
        idMD6BinaryGenerator *this,
        int maxJointsPerSurface)
{
  int num; // r30
  idMD6BinaryGenerator *v3; // r26
  int v4; // r25
  idList<sourceSurface_t,5> *p_sourceSurfaces; // r21
  int size; // r11
  int v7; // r11
  int v8; // r27
  int v9; // r28
  int v10; // r29
  idProcessSurface *v11; // r30
  const idMaterial *v12; // r3
  encounterGroupRole_t *list; // r18
  int v14; // r20
  int v15; // r23
  int v16; // r14
  int v17; // r22
  idProcessSurface *v18; // r29
  encounterGroupRole_t *v19; // r9
  encounterGroupRole_t v20; // r30
  int *p_minJoint; // r11
  int *p_maxJoint; // r11
  unsigned __int8 v23; // r10
  int v24; // r7
  int v25; // r24
  int v26; // r25
  int v27; // r28
  int v28; // r27
  int v29; // r10
  int v30; // r11
  _DWORD *v31; // r9
  idStr *v32; // r3
  idStr *v33; // r30
  int allocedAndFlag; // r11
  int len; // r28
  int v36; // r4
  char *v37; // r10
  int v38; // r9
  char v39; // r11
  int v40; // [sp+50h] [-D0h]
  idStr *v41; // [sp+5Ch] [-C4h] BYREF
  idList<enum encounterGroupRole_t,5> v42; // [sp+60h] [-C0h] BYREF

  num = this->surfaces.num;
  v3 = this;
  v4 = maxJointsPerSurface;
  p_sourceSurfaces = &this->sourceSurfaces;
  if ( num <= this->sourceSurfaces.size
    || (unsigned __int8)idList<sourceSurface_t,5>::Resize(
                          this: (idList<cm_buildMaterial_t,13> *)&this->sourceSurfaces,
                          newsize: num) != 0 )
  {
    size = p_sourceSurfaces->size;
    if ( num < size )
      size = num;
    p_sourceSurfaces->num = size;
  }
  v8 = 0;
  v7 = v3->surfaces.num;
  if ( v7 > 0 )
  {
    v9 = 0;
    v10 = 0;
    do
    {
      v11 = v3->surfaces.list[v10];
      p_sourceSurfaces->list[v9].mtr = v11->material;
      if ( (unsigned __int8)ProcessVertsHaveTexCoordsOutsideRange(uvs: &v11->mesh.uvs, min: -0.0099999998, max: 1.01) == 0 )
      {
        v12 = idMaterial::CompatibleGenericMaterial(this: v11->material);
        if ( v12 != nullptr )
          v11->material = v12;
      }
      ++v8;
      ++v10;
      ++v9;
      v7 = v3->surfaces.num;
    }
    while ( v8 < v7 );
  }
  list = nullptr;
  v42.listStatic = 0;
  v14 = 0;
  v42.memTag = 5;
  memset(&v42, 0, 14);
  v41 = (idStr *)v7;
  v40 = 0;
  if ( v7 > 0 )
  {
    v15 = 0;
    v16 = 0;
    while ( 1 )
    {
      v17 = 0;
      v18 = v3->surfaces.list[v16];
      if ( !v18->discrete && v14 > 0 )
      {
        v19 = list;
        while ( 1 )
        {
          v20 = *v19;
          if ( *(_BYTE *)(*v19 + 36) == 0
            && *(const idMaterial **)(v20 + 32) == v18->material
            && *(unsigned __int8 *)(v20 + 37) == v18->allowSkinRemapping
            && *(_DWORD *)(v20 + 116) == v18->mesh.hashST )
          {
            p_minJoint = &v18->mesh.minJoint;
            if ( *(_DWORD *)(v20 + 108) < v18->mesh.minJoint )
              p_minJoint = (int *)(v20 + 108);
            v23 = *p_minJoint;
            p_maxJoint = &v18->mesh.maxJoint;
            if ( v18->mesh.maxJoint < *(_DWORD *)(v20 + 112) )
              p_maxJoint = (int *)(v20 + 112);
            v24 = (unsigned __int8)*p_maxJoint;
            if ( v24 - v23 <= v4 && v18->mesh.indexes.num + *(_DWORD *)(v20 + 80) < 0x10000 )
              break;
          }
          ++v17;
          ++v19;
          if ( v17 >= v14 )
            goto LABEL_37;
        }
        p_sourceSurfaces->list[v15].renderSurface = v17;
        p_sourceSurfaces->list[v15].firstVertex = *(_DWORD *)(v20 + 48);
        p_sourceSurfaces->list[v15].lastVertex = *(_DWORD *)(v20 + 48) + v18->mesh.vertexes.num - 1;
        *(_DWORD *)(v20 + 108) = v23;
        *(_DWORD *)(v20 + 112) = v24;
        v25 = *(_DWORD *)(v20 + 80);
        v26 = *(_DWORD *)(v20 + 48);
        idList<processVert_t,5>::Append(this: (idList<processVert_t,5> *)(v20 + 44), other: &v18->mesh.vertexes);
        idList<idMD6Filter *,5>::Append(
          this: (idList<idMD6Filter *,5> *)(v20 + 76),
          other: (const idList<idMD6Filter *,5> *)&v18->mesh.indexes);
        v27 = 0;
        if ( v18->mesh.uvs.num > 0 )
        {
          v28 = 0;
          do
          {
            idList<idVec2,5>::Append(
              this: (idList<idVec2,5> *)(v28 * 20 + *(_DWORD *)(v20 + 60)),
              other: &v18->mesh.uvs.list[v28].st);
            ++v27;
            ++v28;
          }
          while ( v27 < v18->mesh.uvs.num );
        }
        v29 = v25;
        if ( v25 < *(_DWORD *)(v20 + 80) )
        {
          v30 = 4 * v25;
          do
          {
            ++v29;
            v31 = (_DWORD *)(*(_DWORD *)(v20 + 76) + v30);
            v30 += 4;
            *v31 += v26;
          }
          while ( v29 < *(_DWORD *)(v20 + 80) );
        }
        v3 = this;
      }
LABEL_37:
      if ( v18->discrete || v17 == v14 )
      {
        p_sourceSurfaces->list[v15].renderSurface = v14;
        p_sourceSurfaces->list[v15].firstVertex = 0;
        p_sourceSurfaces->list[v15].lastVertex = v18->mesh.vertexes.num - 1;
        v32 = (idStr *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x78u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
        v33 = v32;
        v41 = v32;
        if ( v32 != nullptr )
        {
          v32->len = 0;
          v32->data = v32->baseBuffer;
          v32->allocedAndFlag = 20;
          v32->baseBuffer[0] = 0;
          allocedAndFlag = v32->allocedAndFlag;
          len = v18->name.len;
          v36 = v18->name.len + 1;
          if ( allocedAndFlag >= 0 )
          {
            if ( v36 > (allocedAndFlag & 0x7FFFFFFF) )
              idStr::ReAllocate(this: v32, amount: v36, keepold: true);
          }
          else if ( v36 > (allocedAndFlag & 0x7FFFFFFF)
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          v37 = v18->name.data - 1;
          v38 = (int)(v33->data - 1);
          do
          {
            v39 = *++v37;
            *(_BYTE *)++v38 = *v37;
          }
          while ( v39 != 0 );
          v33->len = len;
          v33[1].len = (int)v18->material;
          HIBYTE(v33[1].data) = v18->discrete;
          BYTE1(v33[1].data) = v18->allowSkinRemapping;
          v33[1].allocedAndFlag = v18->numTexCoordSets;
          idProcessMesh::idProcessMesh(this: (idProcessMesh *)v33[1].baseBuffer, __that: &v18->mesh);
        }
        else
        {
          v33 = nullptr;
        }
        v41 = v33;
        idList<idAnimWebBlendTree *,5>::Append(this: &v42, obj: (const encounterGroupRole_t *)&v41);
        v14 = v42.num;
        list = v42.list;
      }
      ++v16;
      ++v15;
      if ( ++v40 >= v3->surfaces.num )
        break;
      v4 = maxJointsPerSurface;
    }
  }
  idList<idProcessSurface *,5>::DeleteContents(this: &v3->surfaces);
  idList<idMaterial const *,59>::operator=(
    this: (idList<idMD6Node *,5> *)&v3->surfaces,
    other: (const idList<idMD6Node *,5> *)&v42);
  if ( (v42.listStatic == 0 || v42.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// __unwind$237376
// EA  : 0x8284D064
// RVA : 0x0084D064
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_237376()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$237377
// EA  : 0x8284D08C
// RVA : 0x0084D08C
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall _unwind_237377(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 288 + 92), tag: a2);
}


// ========================================================================
// __unwind$237558
// EA  : 0x8284D0B4
// RVA : 0x0084D0B4
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_237558()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 288 + 92));
}


// ========================================================================
// SplitMeshForJointLimits
// EA  : 0x8284D330
// RVA : 0x0084D330
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

int __fastcall SplitMeshForJointLimits(
        idProcessMesh *inputMesh,
        int maxJointsPerMesh,
        idList<idProcessMesh,5> *outputMeshes)
{
  idProcessMesh *v3; // r26
  int v4; // r28
  int v5; // r29
  unsigned __int64 v6; // r10
  int v7; // r8
  int v8; // r7
  int v9; // r6
  int v10; // r30
  usedJoints_t *list; // r14
  int v12; // r5
  __int16 *v13; // r11
  int v14; // r6
  int m; // ctr
  int v16; // r27
  unsigned __int8 *v17; // r7
  __int16 *v18; // r8
  bool v19; // zf
  __int16 *v20; // r8
  int v21; // r3
  __int16 *v22; // r8
  __int16 *v23; // r8
  int num; // r16
  int v25; // r21
  idIndex<short,enum invalidJointIndex_t> *p_lastJoint; // r20
  int size; // r11
  int v28; // r30
  int v29; // r10
  int v30; // r11
  processST_t *v31; // r9
  int v32; // r8
  int v33; // r30
  char *v34; // r3
  char *v35; // r23
  char *v36; // r11
  int i; // ctr
  usedJoints_t *v38; // r24
  int j; // r22
  int k; // r25
  int v41; // r30
  encounterGroupRole_t *v42; // r27
  int v43; // r29
  int v44; // r28
  int v45; // r30
  int v46; // r3
  __int16 v48; // [sp+50h] [-120h] BYREF
  idSort_Quick<usedJoints_t,idSort_MeshTris> v49; // [sp+54h] [-11Ch] BYREF
  int v50; // [sp+58h] [-118h]
  char *v51; // [sp+60h] [-110h]
  int v52; // [sp+64h] [-10Ch]
  idList<idVehicleState *,5> v53; // [sp+70h] [-100h] BYREF
  idProcessMesh v54[3]; // [sp+80h] [-F0h] BYREF

  v3 = inputMesh;
  v4 = maxJointsPerMesh;
  v5 = inputMesh->indexes.num / 3;
  v50 = v5;
  if ( v5 == 0 )
    goto _M238141_0;
  memset(&v53, 0, 14);
  *(_WORD *)&v53.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v53);
  idList<usedJoints_t,5>::SetNum(this: (idList<usedJoints_t,5> *)&v53, newNum: v5);
  v10 = 0;
  list = (usedJoints_t *)v53.list;
  if ( v5 <= 0 )
  {
LABEL_24:
    v49.__vftable = (idSort_Quick<usedJoints_t,idSort_MeshTris>_vtbl *)&idSort_MeshTris::`vftable';
    num = v53.num;
    if ( list != nullptr )
      idSort_Quick<usedJoints_t,idSort_MeshTris>::Sort(
        this: &v49,
        base: list,
        num: v53.num,
        a4: v9,
        a5: v8,
        a6: v7,
        a7: v6);
    v25 = 0;
    v49.__vftable = (idSort_Quick<usedJoints_t,idSort_MeshTris>_vtbl *)&idSort<usedJoints_t>::`vftable';
    if ( v5 >= 0 )
    {
      p_lastJoint = &list->lastJoint;
      while ( v25 < num && p_lastJoint->value - list->firstJoint.value < v4 )
      {
LABEL_54:
        ++v25;
        p_lastJoint += 4;
        if ( v25 > v5 )
          goto LABEL_55;
      }
      idProcessMesh::idProcessMesh(this: v54);
      size = v54[0].uvs.size;
      v28 = v3->uvs.num;
      if ( v28 > v54[0].uvs.size )
      {
        if ( (unsigned __int8)idList<processST_t,5>::Resize(this: &v54[0].uvs, newsize: v3->uvs.num) == 0 )
        {
LABEL_35:
          v29 = 0;
          if ( v54[0].uvs.num > 0 )
          {
            v30 = 0;
            v31 = v54[0].uvs.list;
            do
            {
              ++v29;
              v32 = (int)&v3->uvs.list[v30++];
              v31->slot = *(_BYTE *)(v32 + 16);
              v31 = &v54[0].uvs.list[v30];
            }
            while ( v29 < v54[0].uvs.num );
          }
          v33 = v3->vertexes.num;
          v52 = v33;
          v34 = (char *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                          size: 4 * v33,
                          tag: TAG_TEMP,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
          v35 = v34;
          v51 = v34;
          if ( v33 != 0 )
          {
            v36 = v34 - 4;
            for ( i = v33; i != 0; --i )
            {
              v36 += 4;
              *(_DWORD *)v36 = -1;
            }
          }
          if ( v25 > 0 )
          {
            v38 = list;
            for ( j = v25; j != 0; --j )
            {
              for ( k = 0; k < 3; ++k )
              {
                v41 = v3->indexes.list[3 * v38->triNum + k];
                v42 = (encounterGroupRole_t *)&v35[4 * v41];
                if ( *v42 == -1 )
                {
                  *v42 = (encounterGroupRole_t)v54[0].vertexes.num;
                  idList<processVert_t,5>::Append(this: &v54[0].vertexes, obj: &v3->vertexes.list[v41]);
                  v43 = 0;
                  if ( v3->uvs.num > 0 )
                  {
                    v44 = v41;
                    v45 = 0;
                    do
                    {
                      idList<idVec2,72>::Append(
                        this: (idList<idVec2,72> *)&v54[0].uvs.list[v45],
                        obj: &v3->uvs.list[v45].st.list[v44]);
                      ++v43;
                      ++v45;
                    }
                    while ( v43 < v3->uvs.num );
                  }
                }
                idList<idAnimWebBlendTree *,5>::Append(
                  this: (idList<enum encounterGroupRole_t,5> *)&v54[0].indexes,
                  obj: v42);
              }
              ++v38;
            }
            v4 = maxJointsPerMesh;
            v5 = v50;
          }
          v54[0].minJoint = MinJointInVertexesWithAlignment(verts: &v54[0].vertexes);
          v46 = MaxJointInVertexes(verts: &v54[0].vertexes);
          v54[0].hashST = v3->hashST;
          v54[0].maxJoint = v46;
          idList<idProcessMesh,5>::Append(this: outputMeshes, obj: v54);
          if ( v35 != nullptr )
            idMem::Free(this: &mem, ptr: v35, align: ALIGN_16);
          idProcessMesh::~idProcessMesh(this: v54);
          goto LABEL_54;
        }
        size = v54[0].uvs.size;
      }
      v54[0].uvs.num = v28;
      if ( v28 >= size )
        v54[0].uvs.num = size;
      goto LABEL_35;
    }
LABEL_55:
    if ( (v53.listStatic == 0 || v53.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    inputMesh = v3;
_M238141_0:
    idProcessMesh::~idProcessMesh(this: inputMesh);
    return -1;
  }
  v12 = 0;
  v13 = (__int16 *)v53.list + 3;
  while ( 1 )
  {
    *(_DWORD *)(v13 - 3) = v10;
    LODWORD(v6) = v13 - 1;
    *(v13 - 1) = 0x7FFF;
    v14 = 0;
    *v13 = 0;
    for ( m = 3; m != 0; --m )
    {
      v16 = *(__int16 *)v6;
      v17 = (unsigned __int8 *)&v3->vertexes.list[v3->indexes.list[v12 + v14]];
      v18 = &v48;
      HIDWORD(v6) = v17[48];
      v48 = v17[48];
      if ( SHIDWORD(v6) >= v16 )
        v18 = v13 - 1;
      *(_WORD *)v6 = *v18;
      v19 = *v13 < SHIDWORD(v6);
      HIDWORD(v6) = &v48;
      if ( !v19 )
        HIDWORD(v6) = v13;
      *v13 = *(_WORD *)HIDWORD(v6);
      HIDWORD(v6) = v17[49];
      v48 = v17[49];
      v20 = &v48;
      if ( SHIDWORD(v6) >= *(__int16 *)v6 )
        v20 = v13 - 1;
      *(_WORD *)v6 = *v20;
      v19 = *v13 < SHIDWORD(v6);
      HIDWORD(v6) = &v48;
      if ( !v19 )
        HIDWORD(v6) = v13;
      *v13 = *(_WORD *)HIDWORD(v6);
      v21 = *(__int16 *)v6;
      HIDWORD(v6) = v17[50];
      v22 = &v48;
      v48 = v17[50];
      if ( SHIDWORD(v6) >= v21 )
        v22 = v13 - 1;
      *(_WORD *)v6 = *v22;
      v19 = *v13 < SHIDWORD(v6);
      HIDWORD(v6) = &v48;
      if ( !v19 )
        HIDWORD(v6) = v13;
      *v13 = *(_WORD *)HIDWORD(v6);
      HIDWORD(v6) = v17[51];
      v48 = v17[51];
      v23 = &v48;
      if ( SHIDWORD(v6) >= *(__int16 *)v6 )
        v23 = v13 - 1;
      *(_WORD *)v6 = *v23;
      v19 = *v13 < SHIDWORD(v6);
      HIDWORD(v6) = &v48;
      if ( !v19 )
        HIDWORD(v6) = v13;
      WORD1(v6) = *(_WORD *)HIDWORD(v6);
      ++v14;
      *v13 = WORD1(v6);
    }
    HIDWORD(v6) = WORD1(v6);
    v7 = *(__int16 *)v6;
    v8 = SWORD1(v6);
    LODWORD(v6) = SWORD1(v6) - v7;
    v9 = v6 + 1;
    if ( (int)v6 + 1 > v4 )
      break;
    ++v10;
    v13 += 4;
    v12 += 3;
    if ( v10 >= v5 )
      goto LABEL_24;
  }
  if ( (v53.listStatic == 0 || v53.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  idProcessMesh::~idProcessMesh(this: v3);
  return v10;
}


// ========================================================================
// __unwind$237783
// EA  : 0x8284D858
// RVA : 0x0084D858
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_237783()
{
  int v0; // r12

  idProcessMesh::~idProcessMesh(this: *(idProcessMesh **)(v0 - 368 + 388));
}


// ========================================================================
// __unwind$237784
// EA  : 0x8284D880
// RVA : 0x0084D880
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_237784()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 368 + 112));
}


// ========================================================================
// __unwind$237785
// EA  : 0x8284D8A8
// RVA : 0x0084D8A8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_237785()
{
  int v0; // r12

  idSort_MeshTris::~idSort_MeshTris(this: (idSort_MeshTris *)(v0 - 368 + 84));
}


// ========================================================================
// __unwind$237786
// EA  : 0x8284D8D0
// RVA : 0x0084D8D0
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_237786()
{
  int v0; // r12

  idProcessMesh::~idProcessMesh(this: (idProcessMesh *)(v0 - 368 + 128));
}


// ========================================================================
// __unwind$237787
// EA  : 0x8284D8F8
// RVA : 0x0084D8F8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_237787()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 368 + 96));
}


// ========================================================================
// ?SplitMeshesForJointLimit@idMD6BinaryGenerator@@QAAXH@Z
// EA  : 0x8284D928
// RVA : 0x0084D928
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall idMD6BinaryGenerator::SplitMeshesForJointLimit(idMD6BinaryGenerator *this, int maxJointsPerSurface)
{
  int v4; // r15
  int v5; // r22
  idProcessSurface **list; // r11
  idProcessSurface *v7; // r26
  idProcessMesh *v8; // r3
  int v9; // r3
  int v10; // r28
  __int64 v11; // r24
  const idList<idMD6Node *,5> *p_indexes; // r29
  idProcessSurface *v13; // r3
  idProcessSurface *v14; // r30
  bool allowSkinRemapping; // r11
  size_t len; // r27
  int allocedAndFlag; // r11
  int v18; // r4
  int size; // r30
  idProcessMesh *v20; // r29
  int num; // r11
  int v22; // r30
  int v23; // r27
  int v24; // r25
  int v25; // r3
  int v26; // r24
  int v27; // r23
  int v28; // r22
  int v29; // r20
  const char *v30; // r3
  idProcessSurface *v31; // [sp+50h] [-120h] BYREF
  idList<idProcessMesh,5> v32; // [sp+60h] [-110h] BYREF
  idList<enum encounterGroupRole_t,5> v33; // [sp+70h] [-100h] BYREF
  idProcessMesh v34[3]; // [sp+80h] [-F0h] BYREF

  memset(&v33, 0, 14);
  *(_WORD *)&v33.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33);
  v4 = 0;
  if ( this->surfaces.num <= 0 )
  {
LABEL_25:
    idList<idProcessSurface *,5>::DeleteContents(this: &this->surfaces);
    idList<idMaterial const *,59>::operator=(
      this: (idList<idMD6Node *,5> *)&this->surfaces,
      other: (const idList<idMD6Node *,5> *)&v33);
    if ( (v33.listStatic == 0 || v33.listStatic == 2) && v33.list != nullptr )
      idMem::Free(this: &mem, ptr: v33.list, align: ALIGN_16);
  }
  else
  {
    v5 = 0;
    while ( 1 )
    {
      list = this->surfaces.list;
      *(_WORD *)&v32.memTag = 1280;
      memset(&v32, 0, 14);
      v7 = list[v5];
      v8 = idProcessMesh::idProcessMesh(this: v34, __that: &v7->mesh);
      v9 = SplitMeshForJointLimits(inputMesh: v8, maxJointsPerMesh: maxJointsPerSurface, outputMeshes: &v32);
      v10 = v9;
      if ( v9 != -1 )
        break;
      v11 = *(_QWORD *)&v32.list;
      if ( v32.num > 0 )
      {
        p_indexes = (const idList<idMD6Node *,5> *)&v32.list->indexes;
        do
        {
          v13 = (idProcessSurface *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0x78u,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
          v31 = v13;
          if ( v13 != nullptr )
            v14 = idProcessSurface::idProcessSurface(this: v13);
          else
            v14 = nullptr;
          allowSkinRemapping = v7->allowSkinRemapping;
          v31 = v14;
          v14->allowSkinRemapping = allowSkinRemapping;
          v14->discrete = v7->discrete;
          v14->material = v7->material;
          len = v7->name.len;
          allocedAndFlag = v14->name.allocedAndFlag;
          v18 = v7->name.len + 1;
          if ( allocedAndFlag >= 0 )
          {
            if ( v18 > (allocedAndFlag & 0x7FFFFFFF) )
              idStr::ReAllocate(this: &v14->name, amount: v18, keepold: false);
          }
          else if ( v18 > (allocedAndFlag & 0x7FFFFFFF)
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: v14->name.data, Src: v7->name.data, Size: len);
          v14->name.data[len] = 0;
          v14->name.len = len;
          idList<processVert_t,5>::operator=(
            this: &v14->mesh.vertexes,
            other: (const idList<processVert_t,5> *)&p_indexes[-2]);
          idList<processST_t,5>::operator=(this: &v14->mesh.uvs, other: (const idList<processST_t,5> *)&p_indexes[-1]);
          idList<idMaterial const *,59>::operator=(this: (idList<idMD6Node *,5> *)&v14->mesh.indexes, other: p_indexes);
          idList<idMaterial const *,59>::operator=(
            this: (idList<idMD6Node *,5> *)&v14->mesh.faceMaterialIndex,
            other: p_indexes + 1);
          v14->mesh.minJoint = (int)p_indexes[2].list;
          v14->mesh.maxJoint = p_indexes[2].num;
          v14->mesh.hashST = p_indexes[2].size;
          idList<idAnimWebBlendTree *,5>::Append(this: &v33, obj: (const encounterGroupRole_t *)&v31);
          LODWORD(v11) = v11 - 1;
          p_indexes = (const idList<idMD6Node *,5> *)((char *)p_indexes + 76);
        }
        while ( (_DWORD)v11 != 0 );
      }
      if ( v32.listStatic == 0 || v32.listStatic == 2 )
      {
        if ( HIDWORD(v11) != 0 )
        {
          size = v32.size;
          if ( v32.size > 0 )
          {
            v20 = (idProcessMesh *)HIDWORD(v11);
            do
            {
              idProcessMesh::~idProcessMesh(this: v20);
              --size;
              ++v20;
            }
            while ( size != 0 );
          }
          idMem::Free(this: &mem, ptr: (void *)HIDWORD(v11), align: ALIGN_16);
        }
        v32.list = nullptr;
        v32.size = 0;
      }
      num = this->surfaces.num;
      ++v4;
      ++v5;
      v32.num = 0;
      if ( v4 >= num )
        goto LABEL_25;
    }
    v22 = 0;
    v23 = 3 * v9;
    do
    {
      v24 = v7->mesh.indexes.list[v23 + v22];
      v25 = (int)&v7->mesh.vertexes.list[v24];
      v26 = *(unsigned __int8 *)(v25 + 51);
      v27 = *(unsigned __int8 *)(v25 + 50);
      v28 = *(unsigned __int8 *)(v25 + 49);
      v29 = *(unsigned __int8 *)(v25 + 48);
      v30 = idVec3::ToString(this: (idAngles *)v25, precision: 2);
      idLib::Printf(
        fmt: "vert %i info:\n  xyz = %s\n  weight joints: joint %d, joint %d, joint %d, joint %d\n",
        v24,
        v30,
        v29,
        v28,
        v27,
        v26);
      ++v22;
    }
    while ( v22 < 3 );
    idLib::Error(
      fmt: "model '%s' has surface '%s' with triangle %d that uses joints that are more than %d apart in the joint array.",
      this->sourceFileName.data,
      this->surfaces.list[v4]->name.data,
      v10,
      maxJointsPerSurface);
    _LN139();
  }
}


// ========================================================================
// $LN139
// EA  : 0x8284DC8C
// RVA : 0x0084DC8C
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _LN139()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 368 + 112));
}


// ========================================================================
// __unwind$238182
// EA  : 0x8284DCB4
// RVA : 0x0084DCB4
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238182()
{
  int v0; // r12

  idList<idProcessMesh,5>::~idList<idProcessMesh,5>(this: (idList<idProcessMesh,5> *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$238184
// EA  : 0x8284DCDC
// RVA : 0x0084DCDC
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall _unwind_238184(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 368 + 80), tag: a2);
}


// ========================================================================
// SplitMeshForIndexLimit
// EA  : 0x8284DD10
// RVA : 0x0084DD10
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall SplitMeshForIndexLimit(
        idProcessMesh *inputMesh,
        int maxIndexesPerMesh,
        idList<idProcessMesh,5> *outputMeshes)
{
  int num; // r17
  int v6; // r29
  char *v7; // r3
  char *v8; // r19
  char *v9; // r11
  int i; // ctr
  int v11; // r11
  int size; // r10
  idProcessMesh *v13; // r26
  int v14; // r30
  idList<processST_t,5> *p_uvs; // r24
  int v16; // r11
  int v17; // r10
  int v18; // r11
  processST_t *v19; // r9
  int v20; // r8
  int v21; // r23
  int j; // r18
  int v23; // r11
  int v24; // r10
  idProcessMesh *list; // r9
  char *v26; // r11
  int k; // ctr
  int v28; // r30
  int v29; // r11
  int v30; // r10
  int v31; // r11
  processST_t *v32; // r8
  int v33; // r7
  int m; // r22
  int v35; // r30
  encounterGroupRole_t *v36; // r25
  int v37; // r29
  int v38; // r27
  int v39; // r30

  if ( outputMeshes->listStatic == 0 || outputMeshes->listStatic == 2 )
  {
    if ( outputMeshes->list != nullptr )
      idListArrayDelete<idProcessMesh>(ptr: outputMeshes->list, num: outputMeshes->size);
    outputMeshes->list = nullptr;
    outputMeshes->size = 0;
  }
  outputMeshes->num = 0;
  num = inputMesh->vertexes.num;
  v6 = inputMesh->indexes.num / 3;
  v7 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                 size: 4 * num,
                 tag: TAG_TEMP,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v8 = v7;
  if ( num != 0 )
  {
    v9 = v7 - 4;
    for ( i = num; i != 0; --i )
    {
      v9 += 4;
      *(_DWORD *)v9 = -1;
    }
  }
  idList<idProcessMesh,5>::PreAllocateWithGranularity(this: outputMeshes, newSize: outputMeshes->num + 1);
  v11 = outputMeshes->num;
  size = outputMeshes->size;
  if ( v11 >= size )
  {
    v13 = &outputMeshes->list[size - 1];
  }
  else
  {
    v13 = &outputMeshes->list[v11];
    outputMeshes->num = v11 + 1;
  }
  v14 = inputMesh->uvs.num;
  p_uvs = &v13->uvs;
  if ( v14 <= v13->uvs.size
    || (unsigned __int8)idList<processST_t,5>::Resize(this: &v13->uvs, newsize: inputMesh->uvs.num) != 0 )
  {
    v16 = v13->uvs.size;
    if ( v14 < v16 )
      v16 = v14;
    v13->uvs.num = v16;
  }
  v17 = 0;
  if ( v13->uvs.num > 0 )
  {
    v18 = 0;
    do
    {
      ++v17;
      v19 = &inputMesh->uvs.list[v18];
      v20 = (int)&p_uvs->list[v18++];
      *(_BYTE *)(v20 + 16) = v19->slot;
    }
    while ( v17 < v13->uvs.num );
  }
  if ( v6 > 0 )
  {
    v21 = 0;
    for ( j = v6; j != 0; --j )
    {
      if ( v13->indexes.num + 3 > maxIndexesPerMesh )
      {
        v13->minJoint = MinJointInVertexesWithAlignment(verts: &v13->vertexes);
        v13->maxJoint = MaxJointInVertexes(verts: &v13->vertexes);
        v13->hashST = inputMesh->hashST;
        idList<idProcessMesh,5>::PreAllocateWithGranularity(this: outputMeshes, newSize: outputMeshes->num + 1);
        v23 = outputMeshes->num;
        v24 = outputMeshes->size;
        list = outputMeshes->list;
        if ( v23 >= v24 )
        {
          v13 = &list[v24 - 1];
        }
        else
        {
          v13 = &list[v23];
          outputMeshes->num = v23 + 1;
        }
        if ( num != 0 )
        {
          v26 = v8 - 4;
          for ( k = num; k != 0; --k )
          {
            v26 += 4;
            *(_DWORD *)v26 = -1;
          }
        }
        v28 = inputMesh->uvs.num;
        p_uvs = &v13->uvs;
        if ( v28 <= v13->uvs.size
          || (unsigned __int8)idList<processST_t,5>::Resize(this: &v13->uvs, newsize: inputMesh->uvs.num) != 0 )
        {
          v29 = v13->uvs.size;
          if ( v28 < v29 )
            v29 = v28;
          v13->uvs.num = v29;
        }
        v30 = 0;
        if ( v13->uvs.num > 0 )
        {
          v31 = 0;
          do
          {
            ++v30;
            v32 = &inputMesh->uvs.list[v31];
            v33 = (int)&p_uvs->list[v31++];
            *(_BYTE *)(v33 + 16) = v32->slot;
          }
          while ( v30 < v13->uvs.num );
        }
      }
      for ( m = 3; m != 0; --m )
      {
        v35 = inputMesh->indexes.list[v21];
        v36 = (encounterGroupRole_t *)&v8[4 * v35];
        if ( *v36 == -1 )
        {
          *v36 = (encounterGroupRole_t)v13->vertexes.num;
          idList<processVert_t,5>::Append(this: &v13->vertexes, obj: &inputMesh->vertexes.list[v35]);
          v37 = 0;
          if ( inputMesh->uvs.num > 0 )
          {
            v38 = v35;
            v39 = 0;
            do
            {
              idList<idVec2,72>::Append(
                this: (idList<idVec2,72> *)&p_uvs->list[v39],
                obj: &inputMesh->uvs.list[v39].st.list[v38]);
              ++v37;
              ++v39;
            }
            while ( v37 < inputMesh->uvs.num );
          }
        }
        idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v13->indexes, obj: v36);
        ++v21;
      }
    }
  }
  v13->minJoint = MinJointInVertexesWithAlignment(verts: &v13->vertexes);
  v13->maxJoint = MaxJointInVertexes(verts: &v13->vertexes);
  v13->hashST = inputMesh->hashST;
  if ( v8 != nullptr )
    idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
  idProcessMesh::~idProcessMesh(this: inputMesh);
}


// ========================================================================
// __unwind$238484
// EA  : 0x8284E0A8
// RVA : 0x0084E0A8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238484()
{
  int v0; // r12

  idProcessMesh::~idProcessMesh(this: *(idProcessMesh **)(v0 - 240 + 260));
}


// ========================================================================
// __unwind$238485
// EA  : 0x8284E0D0
// RVA : 0x0084E0D0
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238485()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 240 + 80));
}


// ========================================================================
// ?SplitMeshesForIndexLimit@idMD6BinaryGenerator@@QAAXH@Z
// EA  : 0x8284E100
// RVA : 0x0084E100
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall idMD6BinaryGenerator::SplitMeshesForIndexLimit(idMD6BinaryGenerator *this, int maxIndexesPerSurface)
{
  int v4; // r18
  int v5; // r21
  idProcessSurface **list; // r11
  idProcessSurface *v7; // r26
  idProcessMesh *v8; // r3
  idProcessMesh *v9; // r23
  const idList<idMD6Node *,5> *p_indexes; // r29
  int i; // r24
  idProcessSurface *v12; // r3
  idProcessSurface *v13; // r30
  bool allowSkinRemapping; // r11
  size_t len; // r27
  int allocedAndFlag; // r11
  int v17; // r4
  int size; // r30
  idProcessMesh *v19; // r29
  int num; // r11
  idProcessSurface *v21; // [sp+50h] [-120h] BYREF
  idList<idProcessMesh,5> v22; // [sp+60h] [-110h] BYREF
  idList<enum encounterGroupRole_t,5> v23; // [sp+70h] [-100h] BYREF
  idProcessMesh v24[3]; // [sp+80h] [-F0h] BYREF

  memset(&v23, 0, 14);
  *(_WORD *)&v23.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v23);
  v4 = 0;
  if ( this->surfaces.num > 0 )
  {
    v5 = 0;
    do
    {
      list = this->surfaces.list;
      *(_WORD *)&v22.memTag = 1280;
      memset(&v22, 0, 14);
      v7 = list[v5];
      v8 = idProcessMesh::idProcessMesh(this: v24, __that: &v7->mesh);
      SplitMeshForIndexLimit(inputMesh: v8, maxIndexesPerMesh: maxIndexesPerSurface, outputMeshes: &v22);
      v9 = v22.list;
      if ( v22.num > 0 )
      {
        p_indexes = (const idList<idMD6Node *,5> *)&v22.list->indexes;
        for ( i = v22.num; i != 0; --i )
        {
          v12 = (idProcessSurface *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0x78u,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
          v21 = v12;
          if ( v12 != nullptr )
            v13 = idProcessSurface::idProcessSurface(this: v12);
          else
            v13 = nullptr;
          allowSkinRemapping = v7->allowSkinRemapping;
          v21 = v13;
          v13->allowSkinRemapping = allowSkinRemapping;
          v13->discrete = v7->discrete;
          v13->material = v7->material;
          len = v7->name.len;
          allocedAndFlag = v13->name.allocedAndFlag;
          v17 = v7->name.len + 1;
          if ( allocedAndFlag >= 0 )
          {
            if ( v17 > (allocedAndFlag & 0x7FFFFFFF) )
              idStr::ReAllocate(this: &v13->name, amount: v17, keepold: false);
          }
          else if ( v17 > (allocedAndFlag & 0x7FFFFFFF)
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: v13->name.data, Src: v7->name.data, Size: len);
          v13->name.data[len] = 0;
          v13->name.len = len;
          idList<processVert_t,5>::operator=(
            this: &v13->mesh.vertexes,
            other: (const idList<processVert_t,5> *)&p_indexes[-2]);
          idList<processST_t,5>::operator=(this: &v13->mesh.uvs, other: (const idList<processST_t,5> *)&p_indexes[-1]);
          idList<idMaterial const *,59>::operator=(this: (idList<idMD6Node *,5> *)&v13->mesh.indexes, other: p_indexes);
          idList<idMaterial const *,59>::operator=(
            this: (idList<idMD6Node *,5> *)&v13->mesh.faceMaterialIndex,
            other: p_indexes + 1);
          v13->mesh.minJoint = (int)p_indexes[2].list;
          v13->mesh.maxJoint = p_indexes[2].num;
          v13->mesh.hashST = p_indexes[2].size;
          idList<idAnimWebBlendTree *,5>::Append(this: &v23, obj: (const encounterGroupRole_t *)&v21);
          p_indexes = (const idList<idMD6Node *,5> *)((char *)p_indexes + 76);
        }
      }
      if ( v22.listStatic == 0 || v22.listStatic == 2 )
      {
        if ( v9 != nullptr )
        {
          size = v22.size;
          if ( v22.size > 0 )
          {
            v19 = v9;
            do
            {
              idProcessMesh::~idProcessMesh(this: v19);
              --size;
              ++v19;
            }
            while ( size != 0 );
          }
          idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
        }
        v22.list = nullptr;
        v22.size = 0;
      }
      num = this->surfaces.num;
      ++v4;
      ++v5;
      v22.num = 0;
    }
    while ( v4 < num );
  }
  idList<idProcessSurface *,5>::DeleteContents(this: &this->surfaces);
  idList<idMaterial const *,59>::operator=(
    this: (idList<idMD6Node *,5> *)&this->surfaces,
    other: (const idList<idMD6Node *,5> *)&v23);
  if ( (v23.listStatic == 0 || v23.listStatic == 2) && v23.list != nullptr )
    idMem::Free(this: &mem, ptr: v23.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$238686
// EA  : 0x8284E3BC
// RVA : 0x0084E3BC
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238686()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 368 + 112));
}


// ========================================================================
// __unwind$238687
// EA  : 0x8284E3E4
// RVA : 0x0084E3E4
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238687()
{
  int v0; // r12

  idList<idProcessMesh,5>::~idList<idProcessMesh,5>(this: (idList<idProcessMesh,5> *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$238689
// EA  : 0x8284E40C
// RVA : 0x0084E40C
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall _unwind_238689(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 368 + 80), tag: a2);
}


// ========================================================================
// ?LoadAndProcessText@idMD6BinaryGenerator@@QAA_NPBD@Z
// EA  : 0x8284E440
// RVA : 0x0084E440
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

int __fastcall idMD6BinaryGenerator::LoadAndProcessText(idMD6BinaryGenerator *this, char *sourceModel)
{
  int v4; // r30
  idMD6Skel *v6; // r3
  idStr *p_morphSkinName; // r3
  idMD6Skel *skeleton; // r11
  int numJoints; // r29
  const idDeclVehicleUpgrade **list; // r18
  const idDeclVehicleUpgrade **v11; // r30
  idIndex<short,enum invalidJointIndex_t> *JointIndex; // r3
  int value; // r9
  idMD6Skel *v14; // r11
  idMD6SkelData *data; // r11
  int v16; // r10
  int basePoseOffset; // r6
  int v18; // r5
  char *v19; // r10
  double v20; // fp13
  double v21; // fp12
  encounterGroupRole_t *v22; // r24
  int num; // r30
  encounterGroupRole_t *v24; // r27
  encounterGroupRole_t *v25; // r29
  int v26; // r29
  const char *resourceError; // r27
  int v28; // r30
  int v29; // r6
  int v30; // r7
  int v31; // r8
  idProcessSurface *v32; // r11
  idProcessMesh *p_mesh; // r10
  int v34; // r9
  processVert_t *v35; // r11
  int v36; // r30
  idProcessSurface **v37; // r3
  int v38; // r29
  idProcessSurface *v39; // r11
  int v40; // r8
  int v41; // r7
  processVert_t *v42; // r6
  int v43; // r10
  int v44; // r26
  int v45; // r25
  int v46; // r24
  int v47; // r11
  int v48; // r4
  int v49; // r10
  int i; // ctr
  char *v51; // r11
  idList<unsigned char,5> *p_jointRemap; // r30
  __int64 v53; // r4
  int v54; // r28
  int v55; // r29
  int v56; // r9
  idProcessSurface *v57; // r11
  const idList<processVert_t,5> *p_vertexes; // r4
  int v59; // r11
  unsigned __int8 *v60; // r8
  int v61; // r3
  const idList<processVert_t,5> *v62; // r4
  int v63; // r3
  int v64; // r4
  int v65; // r24
  int v66; // r25
  idProcessSurface *v67; // r11
  idProcessMesh *v68; // r30
  unsigned int v69; // r29
  encounterGroupRole_t *v70; // r3
  unsigned __int16 *v71; // r27
  int v72; // r11
  int v73; // r10
  int v74; // r9
  _WORD *v75; // r8
  __int16 v76; // r6
  idMD6Skel_vtbl *v77; // r28
  int v78; // r11
  int v79; // r10
  unsigned __int16 *v80; // r9
  __int64 v81; // [sp+8h] [-5C8h]
  __int64 v82; // [sp+10h] [-5C0h]
  __int64 v83; // [sp+18h] [-5B8h]
  __int64 v84; // [sp+20h] [-5B0h]
  __int64 v85; // [sp+28h] [-5A8h]
  __int64 v86; // [sp+30h] [-5A0h]
  __int64 v87; // [sp+38h] [-598h]
  __int64 v88; // [sp+40h] [-590h]
  __int64 v89; // [sp+48h] [-588h]
  __int64 v90; // [sp+50h] [-580h]
  _DWORD v91[54]; // [sp+58h] [-578h] BYREF
  bool v92; // [sp+130h] [-4A0h]
  int v93; // [sp+134h] [-49Ch]
  idList<enum encounterGroupRole_t,5> v94; // [sp+140h] [-490h] BYREF
  idMD6Skel v95; // [sp+150h] [-480h] BYREF
  int v96; // [sp+190h] [-440h]
  int v97; // [sp+194h] [-43Ch]
  int v98; // [sp+1A4h] [-42Ch]
  float v99; // [sp+1A8h] [-428h]
  int v100; // [sp+1ACh] [-424h]
  int v101; // [sp+1B0h] [-420h]
  int v102; // [sp+1B4h] [-41Ch]
  idStr v103; // [sp+1C0h] [-410h] BYREF
  idLexer v104; // [sp+1E0h] [-3F0h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v105; // [sp+270h] [-360h] BYREF
  idToken v106; // [sp+280h] [-350h] BYREF
  idToken v107; // [sp+2D0h] [-300h] BYREF
  __int64 v108[32]; // [sp+320h] [-2B0h] BYREF
  char v109[256]; // [sp+420h] [-1B0h] BYREF

  idLexer::idLexer(this: &v104, flags_: 560);
  if ( !idLexer::LoadFile(this: &v104, filename_: sourceModel, OSPath: false) )
  {
LABEL_5:
    idLexer::~idLexer(this: &v104);
    return 0;
  }
  while ( 1 )
  {
    idLexer::ExpectTokenString(this: &v104, string: MD6_VERSION_STRING);
    v4 = idLexer::ParseInt(this: &v104);
    if ( v4 == 5 )
      break;
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)sourceModel) == 0 )
    {
      idLexer::Error(this: &v104, str: "Invalid version %d.  Should be version %d\n", v4, 5);
      idLexer::~idLexer(this: &v104);
      return 0;
    }
    idLexer::FreeSource(this: &v104);
    if ( !idLexer::LoadFile(this: &v104, filename_: sourceModel, OSPath: false) )
      goto LABEL_5;
  }
  v92 = false;
  v103.allocedAndFlag = 20;
  v103.data = v103.baseBuffer;
  v103.len = 0;
  this->timestamp = v104.fileTime;
  v93 = 0;
  v94.list = nullptr;
  v103.baseBuffer[0] = 0;
  v95.data = (idMD6SkelData *)20;
  *((_DWORD *)&v95.idResource + 8) = 0;
  v95.defaultAnim = (const idMD6Anim *)&v95.timestamp;
  HIBYTE(v95.timestamp) = 0;
  v98 = 0;
  v99 = -3.4028235e38;
  v100 = 0;
  v101 = 0;
  v102 = 0;
  idLexer::ExpectTokenString(this: &v104, string: "init");
  idLexer::ExpectTokenType(this: &v104, type: 5, subtype: 46, token: (idToken *)((char *)&v95.idResource + 32));
  if ( !idLexer::ReadToken(this: &v104, token: (idToken *)((char *)&v95.idResource + 32)) )
  {
LABEL_40:
    idLexer::Error(this: &v104, str: "Invalid number of meshes: %d", v94.list);
    idStr::FreeData(this: (idStr *)&v95.idResource + 1);
    idStr::FreeData(this: &v103);
    idLexer::~idLexer(this: &v104);
    return 0;
  }
  while ( v96 != 5 || v97 != 47 )
  {
    if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "commandLine") != 0 )
    {
      if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "skeleton") == 0 )
      {
        v106.floatvalue = -3.4028235e38;
        v106.allocedAndFlag = 20;
        v106.data = v106.baseBuffer;
        v106.len = 0;
        v106.baseBuffer[0] = 0;
        v106.intvalue = 0;
        memset(&v106.whiteSpaceStart_p, 0, 12);
        idLexer::ExpectTokenType(this: &v104, type: 1, subtype: 0, token: &v106);
        if ( !fileSystem->IsRelativePath(this: fileSystem, a2: v106.data) )
        {
          fileSystem->OSPathToRelativePath(this: fileSystem, a2: v106.data, a3: v109, a4: 256);
          idStr::operator=(this: &v106, text: v109);
        }
        v6 = (idMD6Skel *)idResourceList::Load(
                            this: &idMD6Skel::resourceList,
                            name: v106.data,
                            makeDefault: false,
                            skipStaleCheck: false);
        this->skeleton = v6;
        if ( v6 == nullptr )
        {
          idLexer::Error(this: &v104, str: "Unable to load skeleton: %s", v106.data);
          idStr::FreeData(this: &v106);
          idStr::FreeData(this: (idStr *)&v95.idResource + 1);
          idStr::FreeData(this: &v103);
          idLexer::~idLexer(this: &v104);
          return 0;
        }
        this->skelTimestamp = fileSystem->GetTimestamp(this: fileSystem, a2: v6->name.str, a3: false);
        idStr::FreeData(this: &v106);
        goto LABEL_38;
      }
      if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "sourceFile") != 0 )
      {
        if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "numMeshes") != 0 )
        {
          if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "numJoints") != 0 )
          {
            if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "numUserChannels") != 0
              && idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "numWeightSets") != 0 )
            {
              if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "remapForSkinning") != 0 )
              {
                if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "exportNormals") != 0 )
                {
                  if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "minExpand") != 0 )
                  {
                    if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "maxExpand") != 0 )
                    {
                      if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "morphMap") != 0 )
                      {
                        if ( idStr::Icmp(s1: (const char *)v95.defaultAnim, s2: "morphSkin") != 0 )
                        {
                          idLexer::Error(this: &v104, str: "Unknown token: %s", (const char *)v95.defaultAnim);
                          idStr::FreeData(this: (idStr *)&v95.idResource + 1);
                          idStr::FreeData(this: &v103);
                          idLexer::~idLexer(this: &v104);
                          return 0;
                        }
                        idLexer::ExpectTokenType(
                          this: &v104,
                          type: 1,
                          subtype: 0,
                          token: (idToken *)((char *)&v95.idResource + 32));
                        p_morphSkinName = &this->morphSkinName;
                      }
                      else
                      {
                        idLexer::ExpectTokenType(
                          this: &v104,
                          type: 1,
                          subtype: 0,
                          token: (idToken *)((char *)&v95.idResource + 32));
                        p_morphSkinName = &v103;
                      }
                      idStr::operator=(this: p_morphSkinName, text: (const idStr *)&v95.idResource + 1);
                    }
                    else
                    {
                      idLexer::Parse1DMatrix(this: &v104, x: 3, m: &this->maxBoundsExpansion.x, expectCommas: false);
                    }
                  }
                  else
                  {
                    idLexer::Parse1DMatrix(this: &v104, x: 3, m: &this->minBoundsExpansion.x, expectCommas: false);
                  }
                }
                else
                {
                  v92 = idLexer::ParseBool(this: &v104);
                }
              }
              else
              {
                this->remapForSkinning = idLexer::ParseBool(this: &v104);
              }
            }
            else
            {
              idLexer::ParseInt(this: &v104);
            }
          }
          else
          {
            v93 = idLexer::ParseInt(this: &v104);
          }
        }
        else
        {
          v94.list = (encounterGroupRole_t *)idLexer::ParseInt(this: &v104);
        }
        goto LABEL_38;
      }
    }
    idLexer::ExpectTokenType(this: &v104, type: 1, subtype: 0, token: (idToken *)((char *)&v95.idResource + 32));
LABEL_38:
    if ( !idLexer::ReadToken(this: &v104, token: (idToken *)((char *)&v95.idResource + 32)) )
      break;
  }
  if ( (int)v94.list <= 0 )
    goto LABEL_40;
  skeleton = this->skeleton;
  if ( skeleton != nullptr )
  {
    numJoints = v93;
    if ( v93 == 0 )
    {
      numJoints = skeleton->data->numJoints;
      v93 = numJoints;
    }
    idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v105);
    idList<unsigned short,115>::SetNum(this: (idList<unsigned short,72> *)&v105, newNum: numJoints);
    idLexer::ExpectTokenString(this: &v104, string: "joints");
    idLexer::ExpectTokenType(this: &v104, type: 5, subtype: 46, token: (idToken *)((char *)&v95.idResource + 32));
    list = v105.list;
    if ( numJoints > 0 )
    {
      v11 = v105.list;
      do
      {
        v107.floatvalue = -3.4028235e38;
        v107.allocedAndFlag = 20;
        v107.data = v107.baseBuffer;
        v107.len = 0;
        v107.baseBuffer[0] = 0;
        v107.intvalue = 0;
        memset(&v107.whiteSpaceStart_p, 0, 12);
        idLexer::ReadToken(this: &v104, token: &v107);
        JointIndex = idMD6Skel::GetJointIndex(
                       this: &v95,
                       result: (idIndex<short,enum invalidJointIndex_t> *)this->skeleton,
                       name: v107.data);
        value = (unsigned __int16)JointIndex->value;
        *(idIndex<short,enum invalidJointIndex_t> *)v11 = (idIndex<short,enum invalidJointIndex_t>)JointIndex->value;
        if ( value == 0xFFFF )
          idLexer::Error(
            this: &v104,
            str: "Model joint '%s' doesn't exist in skeleton: '%s'",
            (const char *)v95.defaultAnim,
            this->skeleton->name.str);
        idStr::FreeData(this: &v107);
        --numJoints;
        v11 = (const idDeclVehicleUpgrade **)((char *)v11 + 2);
      }
      while ( numJoints != 0 );
    }
    idLexer::ExpectTokenType(this: &v104, type: 5, subtype: 47, token: (idToken *)((char *)&v95.idResource + 32));
    memset(&v95.resourceListPtr, 0, 12);
    v14 = this->skeleton;
    v95.staleCount = 1280;
    data = v14->data;
    v16 = data->numJoints;
    v95.__vftable = (idMD6Skel_vtbl *)data;
    basePoseOffset = data->basePoseOffset;
    v18 = (v16 + 7) & 0xFFF8;
    v19 = (char *)data + 28 * (((_WORD)v16 + 7) & 0xFFF8) + basePoseOffset;
    v20 = *((float *)v19 + 1);
    v21 = *(float *)((char *)&data->size + 28 * v18 + basePoseOffset);
    v95.name.str = *((const char **)v19 + 2);
    *(float *)&v95.__vftable = v21;
    *(float *)&v95.trackedMemory = v20;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v95.resourceListPtr);
    idMD6BinaryGenerator::LoadMorphMap(
      this,
      fileName: v103.data,
      offset: (const idVec3 *)&v95,
      vertexMorphOffsets: (idList<eboltControlNode_t,5> *)&v95.resourceListPtr);
    v22 = v94.list;
    v94.list = (encounterGroupRole_t *)&this->defaultBounds;
    this->defaultBounds.b[0].z = 1.0e30;
    this->defaultBounds.b[0].y = 1.0e30;
    this->defaultBounds.b[0].x = 1.0e30;
    this->defaultBounds.b[1].z = -1.0e30;
    this->defaultBounds.b[1].y = -1.0e30;
    this->defaultBounds.b[1].x = -1.0e30;
    if ( (int)v22 > 0 )
    {
      do
      {
        idLexer::ExpectTokenString(this: &v104, string: "mesh");
        *(_WORD *)&v94.memTag = 1280;
        memset(&v94, 0, 14);
        ParseMD6MeshToSurfaces(
          md6Version: 5,
          parser: &v104,
          numJoints: v93,
          hasExportedNormals: v92,
          remapTable: (const idList<short,5> *)&v105,
          surfaces: &v94);
        v24 = v94.list;
        num = v94.num;
        if ( v94.num > 0 )
        {
          v25 = v94.list;
          do
          {
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->surfaces,
              obj: v25);
            --num;
            ++v25;
          }
          while ( num != 0 );
        }
        if ( v94.listStatic == 0 || v94.listStatic == 2 )
        {
          if ( v24 != nullptr )
            idMem::Free(this: &mem, ptr: v24, align: ALIGN_16);
          v94.list = nullptr;
          v94.size = 0;
        }
        v22 = (encounterGroupRole_t *)((char *)v22 - 1);
        v94.num = 0;
      }
      while ( v22 != nullptr );
    }
    v26 = 0;
    if ( this->surfaces.num > 0 )
    {
      resourceError = v95.resourceError;
      v28 = 0;
      do
      {
        if ( (int)resourceError > 0
          && !MatchMorphVerts(
                vertexMorphOffsets: (const idList<vertexMorphOffset_t,5> *)&v95.resourceListPtr,
                vertexes: &this->surfaces.list[v28]->mesh.vertexes) )
        {
          idLib::Warning(
            fmt: "could not match all vertices from mesh '%s' on '%s' with morph offsets from the source LWO (models are possi"
            "bly offset differently)",
            this->surfaces.list[v28]->name.data,
            sourceModel);
        }
        ++v26;
        ++v28;
      }
      while ( v26 < this->surfaces.num );
    }
    idMD6BinaryGenerator::CreateHashST(this);
    v29 = 0;
    if ( this->surfaces.num > 0 )
    {
      v30 = 0;
      do
      {
        v31 = 0;
        v32 = this->surfaces.list[v30];
        p_mesh = &v32->mesh;
        if ( v32->mesh.vertexes.num > 0 )
        {
          v34 = 0;
          do
          {
            v35 = &p_mesh->vertexes.list[v34];
            if ( v35->weights[1] == 0 )
              v35->jointIdxs[1] = v35->jointIdxs[0];
            if ( v35->weights[2] == 0 )
              v35->jointIdxs[2] = v35->jointIdxs[0];
            if ( v35->weights[3] == 0 )
              v35->jointIdxs[3] = v35->jointIdxs[0];
            ++v31;
            ++v34;
          }
          while ( v31 < p_mesh->vertexes.num );
        }
        ++v29;
        ++v30;
      }
      while ( v29 < this->surfaces.num );
    }
    memset(Dst: v108, Val: 0, Size: sizeof(v108));
    v36 = 0;
    if ( this->surfaces.num > 0 )
    {
      v37 = this->surfaces.list;
      v38 = this->surfaces.num;
      do
      {
        v39 = *v37;
        v40 = 0;
        v93 = (*v37)->mesh.vertexes.num;
        v41 = v93;
        if ( v93 > 0 )
        {
          v42 = v39->mesh.vertexes.list;
          v43 = 0;
          do
          {
            ++v40;
            v44 = v42[v43].jointIdxs[0];
            v45 = v42[v43].jointIdxs[1];
            v46 = v42[v43].jointIdxs[2];
            v47 = v42[v43++].jointIdxs[3];
            *((_BYTE *)v108 + v44) = 1;
            *((_BYTE *)v108 + v45) = 1;
            *((_BYTE *)v108 + v46) = 1;
            *((_BYTE *)v108 + v47) = 1;
          }
          while ( v40 < v41 );
        }
        ++v36;
        ++v37;
      }
      while ( v36 < v38 );
    }
    HIBYTE(v108[0]) = 1;
    v48 = 0;
    v49 = 0;
    for ( i = 64; i != 0; --i )
    {
      v51 = (char *)v108 + v49 + 1;
      if ( *((_BYTE *)v108 + v49) != 0 )
        ++v48;
      if ( *v51 != 0 )
        ++v48;
      if ( v51[1] != 0 )
        ++v48;
      if ( v51[2] != 0 )
        ++v48;
      v49 += 4;
    }
    idLib::Printf(fmt: "Used joints: %i / %i\n", v48, this->skeleton->data->numJoints);
    p_jointRemap = &this->jointRemap;
    LOBYTE(v91[51]) = this->remapForSkinning;
    v91[53] = &this->jointRemap;
    memcpy(Dst: v91, Src: &v108[7], Size: 0xC8u);
    HIDWORD(v53) = this->skeleton;
    LODWORD(v53) = HIDWORD(v108[1]);
    SetupJointRemap(
      usedJoints: v53,
      jointRemap: __SPAIR64__(HIDWORD(v108[2]), HIDWORD(v108[3])),
      a3: __SPAIR64__(HIDWORD(v108[4]), HIDWORD(v108[5])),
      a4: v108[6],
      a5: v81,
      a6: v82,
      a7: v83,
      a8: v84,
      a9: v85,
      a10: v86,
      a11: v87,
      a12: v88,
      a13: v89,
      a14: v90);
    v54 = 0;
    if ( this->surfaces.num > 0 )
    {
      v55 = 0;
      do
      {
        v56 = 0;
        v57 = this->surfaces.list[v55];
        p_vertexes = &v57->mesh.vertexes;
        if ( v57->mesh.vertexes.num > 0 )
        {
          v59 = 0;
          do
          {
            ++v56;
            p_vertexes->list[v59].jointIdxs[0] = p_jointRemap->list[p_vertexes->list[v59].jointIdxs[0]];
            p_vertexes->list[v59].jointIdxs[1] = p_jointRemap->list[p_vertexes->list[v59].jointIdxs[1]];
            p_vertexes->list[v59].jointIdxs[2] = p_jointRemap->list[p_vertexes->list[v59].jointIdxs[2]];
            v60 = &p_vertexes->list[v59++].jointIdxs[3];
            *v60 = p_jointRemap->list[*v60];
          }
          while ( v56 < p_vertexes->num );
        }
        v61 = MinJointInVertexesWithAlignment(verts: p_vertexes);
        v62[4].list = (processVert_t *)v61;
        v63 = MaxJointInVertexes(verts: v62);
        ++v54;
        *(_DWORD *)(v64 + 68) = v63;
        ++v55;
      }
      while ( v54 < this->surfaces.num );
    }
    idMD6BinaryGenerator::SplitMeshesForJointLimit(this, maxJointsPerSurface: 145);
    idMD6BinaryGenerator::SplitMeshesForIndexLimit(this, maxIndexesPerSurface: 0xFFFF);
    v65 = 0;
    if ( this->surfaces.num > 0 )
    {
      v66 = 0;
      do
      {
        v67 = this->surfaces.list[v66];
        v68 = &v67->mesh;
        v94.num = v67->mesh.indexes.num;
        v69 = v94.num;
        v70 = (encounterGroupRole_t *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                                        size: 2 * v94.num,
                                        tag: TAG_TEMP,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
        v71 = (unsigned __int16 *)v70;
        v94.list = v70;
        v73 = 0;
        v93 = v68->indexes.num;
        v72 = v93;
        if ( v93 > 0 )
        {
          v74 = 0;
          v75 = (_WORD *)v70 - 1;
          do
          {
            ++v73;
            v76 = v68->indexes.list[v74++];
            *++v75 = v76;
            v93 = v68->indexes.num;
            v72 = v93;
          }
          while ( v73 < v93 );
        }
        v93 = v72;
        v95.trackedMemory = v72;
        v77 = (idMD6Skel_vtbl *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                                  size: 2 * v72,
                                  tag: TAG_TEMP,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
        v95.__vftable = v77;
        MeshOptimizer(
          indexes: v71,
          numIndexes: v69,
          outputIndexes: (unsigned __int16 *)v77,
          k1: 1.0,
          k2: 0.0,
          k3: 0.80000001);
        v78 = 0;
        if ( v68->indexes.num > 0 )
        {
          v79 = 0;
          v80 = (unsigned __int16 *)&v77[-1].List + 1;
          do
          {
            ++v80;
            ++v78;
            v68->indexes.list[v79++] = *v80;
          }
          while ( v78 < v68->indexes.num );
        }
        if ( v77 != nullptr )
          idMem::Free(this: &mem, ptr: v77, align: ALIGN_16);
        if ( v71 != nullptr )
          idMem::Free(this: &mem, ptr: v71, align: ALIGN_16);
        ++v65;
        ++v66;
      }
      while ( v65 < this->surfaces.num );
    }
    idMD6BinaryGenerator::MergeMeshesAndBuildSourceSurfaces(this, maxJointsPerSurface: 145);
    if ( (LOBYTE(v95.staleCount) == 0 || LOBYTE(v95.staleCount) == 2) && v95.resourceListPtr != nullptr )
      idMem::Free(this: &mem, ptr: v95.resourceListPtr, align: ALIGN_16);
    if ( (v105.listStatic == 0 || v105.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    idStr::FreeData(this: (idStr *)&v95.idResource + 1);
    idStr::FreeData(this: &v103);
    idLexer::~idLexer(this: &v104);
    return 1;
  }
  else
  {
    idLexer::Error(this: &v104, str: "No skeleton");
    idStr::FreeData(this: (idStr *)&v95.idResource + 1);
    idStr::FreeData(this: &v103);
    idLexer::~idLexer(this: &v104);
    return 0;
  }
}


// ========================================================================
// __unwind$238961_0
// EA  : 0x8284F2A8
// RVA : 0x0084F2A8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238961_0()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 1488 + 480));
}


// ========================================================================
// __unwind$238962_0
// EA  : 0x8284F2D0
// RVA : 0x0084F2D0
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238962_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1488 + 448));
}


// ========================================================================
// __unwind$238963
// EA  : 0x8284F2F8
// RVA : 0x0084F2F8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238963()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1488 + 368));
}


// ========================================================================
// __unwind$238964
// EA  : 0x8284F320
// RVA : 0x0084F320
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238964()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1488 + 640));
}


// ========================================================================
// __unwind$238965
// EA  : 0x8284F348
// RVA : 0x0084F348
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238965()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1488 + 624));
}


// ========================================================================
// __unwind$238966_0
// EA  : 0x8284F370
// RVA : 0x0084F370
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238966_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1488 + 720));
}


// ========================================================================
// __unwind$238967_0
// EA  : 0x8284F398
// RVA : 0x0084F398
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238967_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1488 + 352));
}


// ========================================================================
// __unwind$238968_0
// EA  : 0x8284F3C0
// RVA : 0x0084F3C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238968_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1488 + 320));
}


// ========================================================================
// __unwind$238969_0
// EA  : 0x8284F3E8
// RVA : 0x0084F3E8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238969_0()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 1488 + 320));
}


// ========================================================================
// __unwind$238970
// EA  : 0x8284F410
// RVA : 0x0084F410
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_238970()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 1488 + 336));
}


// ========================================================================
// ?CreateBinaryMD6Model_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8284F440
// RVA : 0x0084F440
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall CreateBinaryMD6Model_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v2; // r4
  idStr *v3; // r3
  idStr v4; // [sp+60h] [-120h] BYREF
  idStr v5; // [sp+80h] [-100h] BYREF
  idStr v6; // [sp+A0h] [-E0h] BYREF
  idMD6BinaryGenerator v7; // [sp+C0h] [-C0h] BYREF

  argc = args->argc;
  if ( args->argc == 2 || argc == 3 )
  {
    if ( argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    idStr::idStr(this: &v5, text: v2);
    v4.len = 0;
    v4.allocedAndFlag = 20;
    v4.data = v4.baseBuffer;
    v4.baseBuffer[0] = 0;
    v3 = idStr::GetWithoutExtension(this: &v6, result: &v5);
    idStr::Format(this: &v4, fmt: "generated/%s.bmd6model", v3->data);
    idStr::FreeData(this: &v6);
    idMD6BinaryGenerator::idMD6BinaryGenerator(this: &v7);
    if ( (unsigned __int8)idMD6BinaryGenerator::LoadAndProcessText(this: &v7, sourceModel: v5.data) != 0 )
      idMD6BinaryGenerator::WriteBinaryFile(this: &v7, filename: v4.data);
    else
      idLib::Printf(fmt: "Failed to load md6 model '%s'.", v5.data);
    idMD6BinaryGenerator::~idMD6BinaryGenerator(this: &v7);
    idStr::FreeData(this: &v4);
    idStr::FreeData(this: &v5);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: CreateBinaryMD6Model <sourceModel>n");
  }
}


// ========================================================================
// __unwind$239932
// EA  : 0x8284F560
// RVA : 0x0084F560
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_239932()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 128));
}


// ========================================================================
// __unwind$239933
// EA  : 0x8284F588
// RVA : 0x0084F588
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_239933()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$239934
// EA  : 0x8284F5B0
// RVA : 0x0084F5B0
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_239934()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 160));
}


// ========================================================================
// __unwind$239935
// EA  : 0x8284F5D8
// RVA : 0x0084F5D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_239935()
{
  int v0; // r12

  idMD6BinaryGenerator::~idMD6BinaryGenerator(this: (idMD6BinaryGenerator *)(v0 - 384 + 192));
}


// ========================================================================
// ?ProcessAllMD6Models_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8284F608
// RVA : 0x0084F608
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void __fastcall ProcessAllMD6Models_f(const idCmdArgs *args)
{
  idFileList *v1; // r27
  int v2; // r19
  int v3; // r23
  idMD6Model *v4; // r30
  const idMD6Model *v5; // r28
  idStr v6; // [sp+50h] [-170h] BYREF
  idStr v7; // [sp+70h] [-150h] BYREF
  idFileList *v8; // [sp+90h] [-130h]
  idMD6BinaryGenerator v9; // [sp+A0h] [-120h] BYREF

  v1 = fileSystem->ListFilesTree(this: fileSystem, a2: "md6", a3: ".md6mesh", a4: 0);
  v8 = v1;
  v2 = 0;
  if ( v1->list.num <= 0 )
  {
LABEL_8:
    idFileList::~idFileList(this: v1);
  }
  else
  {
    v3 = 0;
    while ( 1 )
    {
      idStr::idStr(this: &v7, text: v1->list.list[v3].data);
      idLib::Printf(fmt: "%s\n", v7.data);
      v6.allocedAndFlag = 20;
      v6.len = 0;
      v6.data = v6.baseBuffer;
      v6.baseBuffer[0] = 0;
      idStr::operator=(this: &v6, text: "generated/test/");
      idStr::Append(this: &v6, text: &v7);
      idStr::StripFileExtension(this: &v6);
      idStr::Append(this: &v6, text: ".bmd6model");
      v4 = (idMD6Model *)idResourceList::Load(
                           this: &idMD6Model::resourceList,
                           name: v7.data,
                           makeDefault: false,
                           skipStaleCheck: false);
      if ( v4 == nullptr )
      {
        idLib::Printf(fmt: "Couldn't load '%s'\n", v7.data);
        idStr::FreeData(this: &v6);
        idStr::FreeData(this: &v7);
        idFileList::~idFileList(this: v1);
        goto LABEL_9;
      }
      idMD6BinaryGenerator::idMD6BinaryGenerator(this: &v9);
      if ( (unsigned __int8)idMD6BinaryGenerator::LoadAndProcessText(this: &v9, sourceModel: v7.data) == 0 )
        break;
      idMD6BinaryGenerator::WriteBinaryFile(this: &v9, filename: v6.data);
      v5 = (const idMD6Model *)idResourceList::Load(
                                 this: &idMD6Model::resourceList,
                                 name: v6.data,
                                 makeDefault: false,
                                 skipStaleCheck: false);
      if ( (unsigned __int8)idMD6Model::Equals(this: v4, other: v5) == 0 )
      {
        idLib::Printf(fmt: "Failed equal test on %s\n", v7.data);
        idMD6Model::Equals(this: v4, other: v5);
      }
      idMD6BinaryGenerator::~idMD6BinaryGenerator(this: &v9);
      idStr::FreeData(this: &v6);
      idStr::FreeData(this: &v7);
      ++v2;
      ++v3;
      if ( v2 >= v1->list.num )
        goto LABEL_8;
    }
    idLib::Printf(fmt: "Failed to load md6 model '%s'.", v7.data);
    idMD6BinaryGenerator::~idMD6BinaryGenerator(this: &v9);
    idStr::FreeData(this: &v6);
    idStr::FreeData(this: &v7);
    idFileList::~idFileList(this: v1);
  }
LABEL_9:
  idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
}


// ========================================================================
// __unwind$240053
// EA  : 0x8284F844
// RVA : 0x0084F844
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_240053()
{
  int v0; // r12

  std::auto_ptr<idFileList>::~auto_ptr<idFileList>(this: (std::auto_ptr<idFileList> *)(v0 - 448 + 144));
}


// ========================================================================
// __unwind$240054
// EA  : 0x8284F86C
// RVA : 0x0084F86C
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_240054()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 112));
}


// ========================================================================
// __unwind$240055
// EA  : 0x8284F894
// RVA : 0x0084F894
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_240055()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 80));
}


// ========================================================================
// __unwind$240056
// EA  : 0x8284F8BC
// RVA : 0x0084F8BC
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

void _unwind_240056()
{
  int v0; // r12

  idMD6BinaryGenerator::~idMD6BinaryGenerator(this: (idMD6BinaryGenerator *)(v0 - 448 + 160));
}


// ========================================================================
// `dynamic initializer for 'CreateBinaryMD6Model_v''
// EA  : 0x83344418
// RVA : 0x01344418
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__CreateBinaryMD6Model_v__()
{
  return idCommandLink::idCommandLink(
           this: &CreateBinaryMD6Model_v,
           cmdName: "CreateBinaryMD6Model",
           function: CreateBinaryMD6Model_f,
           description: "Converts text md6 files from the maya exporter to binary files for the game",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ProcessAllMD6Models_v''
// EA  : 0x83344440
// RVA : 0x01344440
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ProcessAllMD6Models_v__()
{
  return idCommandLink::idCommandLink(
           this: &ProcessAllMD6Models_v,
           cmdName: "ProcessAllMD6Models",
           function: ProcessAllMD6Models_f,
           description: "Try loading all MD6 models with the new code",
           argCompletion: nullptr);
}

