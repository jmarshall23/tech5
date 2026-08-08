
// ========================================================================
// ASE_GetToken
// EA  : 0x828799B0
// RVA : 0x008799B0
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

int __fastcall ASE_GetToken(bool restOfLine)
{
  int v1; // r6
  const char *curpos; // r11
  int v4; // r9
  char *v5; // r9
  int v6; // r8

  v1 = 0;
  if ( ase.buffer == nullptr )
    return 0;
  curpos = ase.curpos;
  v4 = ase.curpos - ase.buffer;
  if ( ase.curpos - ase.buffer == ase.len )
    return 0;
  if ( ase.curpos - ase.buffer < ase.len )
  {
    do
    {
      if ( *curpos > 32 )
        break;
      v4 = ++curpos - ase.buffer;
      ase.curpos = curpos;
    }
    while ( curpos - ase.buffer < ase.len );
  }
  if ( v4 < ase.len )
  {
    v5 = (char *)&ase.len + 3;
    while ( 1 )
    {
      ++v1;
      v5[1] = *curpos;
      curpos = ++ase.curpos;
      v6 = *++v5;
      if ( v6 <= 32 && !restOfLine )
        break;
      if ( v6 == 10 || v6 == 13 )
        break;
      if ( curpos - ase.buffer >= ase.len )
      {
        ase.token[v1] = 0;
        return 1;
      }
    }
    ase.token[v1 - 1] = 0;
  }
  ase.token[v1] = 0;
  return 1;
}


// ========================================================================
// ASE_ParseBracedBlock
// EA  : 0x82879AA0
// RVA : 0x00879AA0
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_ParseBracedBlock(void (__fastcall *parser)(const char *))
{
  int v2; // r27
  int v3; // r7
  const char *curpos; // r11
  int v5; // r10
  char *v6; // r10
  const char *v7; // r10
  char *token; // r11
  int v9; // r9
  int v10; // r9
  bool v11; // zf
  const char *v12; // r10
  char *v13; // r11
  int v14; // r9
  int v15; // r9

  v2 = 0;
  while ( 1 )
  {
    v3 = 0;
    if ( ase.buffer == nullptr )
      break;
    curpos = ase.curpos;
    v5 = ase.curpos - ase.buffer;
    if ( ase.curpos - ase.buffer == ase.len )
      break;
    if ( ase.curpos - ase.buffer < ase.len )
    {
      do
      {
        if ( *curpos > 32 )
          break;
        v5 = ++curpos - ase.buffer;
        ase.curpos = curpos;
      }
      while ( curpos - ase.buffer < ase.len );
    }
    if ( v5 < ase.len )
    {
      v6 = (char *)&ase.len + 3;
      while ( 1 )
      {
        ++v3;
        v6[1] = *curpos;
        curpos = ++ase.curpos;
        if ( *++v6 <= 32 )
          break;
        if ( curpos - ase.buffer >= ase.len )
          goto LABEL_13;
      }
      ase.token[v3 - 1] = 0;
    }
LABEL_13:
    v7 = "{";
    token = ase.token;
    ase.token[v3] = 0;
    do
    {
      v9 = (unsigned __int8)*token;
      v11 = v9 == 0;
      v10 = v9 - *(unsigned __int8 *)v7;
      if ( v11 )
        break;
      ++token;
      ++v7;
    }
    while ( v10 == 0 );
    if ( v10 != 0 )
    {
      v12 = "}";
      v13 = ase.token;
      do
      {
        v14 = (unsigned __int8)*v13;
        v11 = v14 == 0;
        v15 = v14 - *(unsigned __int8 *)v12;
        if ( v11 )
          break;
        ++v13;
        ++v12;
      }
      while ( v15 == 0 );
      if ( v15 != 0 )
      {
_LN49_4:
        if ( parser != nullptr )
          parser(a1: ase.token);
      }
      else
      {
        if ( --v2 == 0 )
          return;
        if ( v2 < 0 )
        {
          idLib::Error(fmt: "Unexpected '}'");
          goto _LN49_4;
        }
      }
    }
    else
    {
      ++v2;
    }
  }
}


// ========================================================================
// ASE_SkipEnclosingBraces
// EA  : 0x82879C38
// RVA : 0x00879C38
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void ASE_SkipEnclosingBraces()
{
  int v0; // r31
  int v1; // r6
  const char *curpos; // r11
  int v3; // r9
  char *v4; // r9
  const char *v5; // r9
  char *token; // r11
  int v7; // r8
  int v8; // r8
  bool v9; // zf
  const char *v10; // r9
  char *v11; // r11
  int v12; // r8
  int v13; // r8

  v0 = 0;
  while ( 1 )
  {
    v1 = 0;
    if ( ase.buffer == nullptr )
      break;
    curpos = ase.curpos;
    v3 = ase.curpos - ase.buffer;
    if ( ase.curpos - ase.buffer == ase.len )
      break;
    if ( ase.curpos - ase.buffer < ase.len )
    {
      do
      {
        if ( *curpos > 32 )
          break;
        v3 = ++curpos - ase.buffer;
        ase.curpos = curpos;
      }
      while ( curpos - ase.buffer < ase.len );
    }
    if ( v3 < ase.len )
    {
      v4 = (char *)&ase.len + 3;
      while ( 1 )
      {
        ++v1;
        v4[1] = *curpos;
        curpos = ++ase.curpos;
        if ( *++v4 <= 32 )
          break;
        if ( curpos - ase.buffer >= ase.len )
          goto LABEL_13;
      }
      ase.token[v1 - 1] = 0;
    }
LABEL_13:
    v5 = "{";
    token = ase.token;
    ase.token[v1] = 0;
    do
    {
      v7 = (unsigned __int8)*token;
      v9 = v7 == 0;
      v8 = v7 - *(unsigned __int8 *)v5;
      if ( v9 )
        break;
      ++token;
      ++v5;
    }
    while ( v8 == 0 );
    if ( v8 != 0 )
    {
      v10 = "}";
      v11 = ase.token;
      do
      {
        v12 = (unsigned __int8)*v11;
        v9 = v12 == 0;
        v13 = v12 - *(unsigned __int8 *)v10;
        if ( v9 )
          break;
        ++v11;
        ++v10;
      }
      while ( v13 == 0 );
      if ( v13 == 0 )
      {
        if ( --v0 == 0 )
          return;
        if ( v0 < 0 )
        {
          idLib::Error(fmt: "Unexpected '}'", "{");
          return;
        }
      }
    }
    else
    {
      ++v0;
    }
  }
}


// ========================================================================
// ASE_KeyMESH_FACE_LIST
// EA  : 0x82879DC8
// RVA : 0x00879DC8
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyMESH_FACE_LIST(const char *token)
{
  const char *v1; // r10
  const char *v2; // r11
  idASEMesh *currentMesh; // r30
  int v4; // r9
  int v5; // r9
  bool v6; // zf

  v1 = "*MESH_FACE";
  v2 = token;
  currentMesh = ase.currentMesh;
  do
  {
    v4 = *(unsigned __int8 *)v2;
    v6 = v4 == 0;
    v5 = v4 - *(unsigned __int8 *)v1;
    if ( v6 )
      break;
    ++v2;
    ++v1;
  }
  while ( v5 == 0 );
  if ( v5 != 0 )
  {
    idLib::Error(fmt: "Unknown token '%s' while parsing MESH_FACE_LIST", token);
    JUMPOUT(0x82879EE4);
  }
  ASE_GetToken(restOfLine: false);
  ASE_GetToken(restOfLine: false);
  ASE_GetToken(restOfLine: false);
  currentMesh->faces[ase.currentFace].vertexNum[0] = atol(nptr: ase.token);
  ASE_GetToken(restOfLine: false);
  ASE_GetToken(restOfLine: false);
  currentMesh->faces[ase.currentFace].vertexNum[2] = atol(nptr: ase.token);
  ASE_GetToken(restOfLine: false);
  ASE_GetToken(restOfLine: false);
  currentMesh->faces[ase.currentFace].vertexNum[1] = atol(nptr: ase.token);
  ASE_GetToken(restOfLine: true);
  ++ase.currentFace;
}


// ========================================================================
// ASE_KeyTFACE_LIST
// EA  : 0x82879EE8
// RVA : 0x00879EE8
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyTFACE_LIST(const char *token)
{
  const char *v1; // r10
  const char *v2; // r11
  idASEMesh *currentMesh; // r30
  int v4; // r9
  int v5; // r9
  bool v6; // zf
  int v7; // r29
  int v8; // r28
  int v9; // r3

  v1 = "*MESH_TFACE";
  v2 = token;
  currentMesh = ase.currentMesh;
  do
  {
    v4 = *(unsigned __int8 *)v2;
    v6 = v4 == 0;
    v5 = v4 - *(unsigned __int8 *)v1;
    if ( v6 )
      break;
    ++v2;
    ++v1;
  }
  while ( v5 == 0 );
  if ( v5 != 0 )
  {
    idLib::Error(fmt: "Unknown token '%s' in MESH_TFACE", token);
    JUMPOUT(0x82879FD8);
  }
  ASE_GetToken(restOfLine: false);
  ASE_GetToken(restOfLine: false);
  v7 = atol(nptr: ase.token);
  ASE_GetToken(restOfLine: false);
  v8 = atol(nptr: ase.token);
  ASE_GetToken(restOfLine: false);
  v9 = atol(nptr: ase.token);
  currentMesh->faces[ase.currentFace].tVertexNum[0] = v7;
  currentMesh->faces[ase.currentFace].tVertexNum[1] = v9;
  currentMesh->faces[ase.currentFace++].tVertexNum[2] = v8;
}


// ========================================================================
// ASE_KeyMAP_DIFFUSE
// EA  : 0x82879FE0
// RVA : 0x00879FE0
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyMAP_DIFFUSE(const char *token)
{
  const char *v1; // r11
  const char *v2; // r10
  const char *v3; // r9
  int v4; // r8
  int v5; // r8
  bool v6; // zf
  char *v7; // r3
  const char *v8; // r10
  const char *v9; // r9
  int v10; // r8
  int v11; // r8
  idASEMaterial *v12; // r29
  long double v13; // fp2
  const char *v14; // r10
  const char *v15; // r9
  int v16; // r8
  int v17; // r8
  idASEMaterial *v18; // r29
  long double v19; // fp2
  const char *v20; // r10
  const char *v21; // r9
  int v22; // r8
  int v23; // r8
  idASEMaterial *v24; // r29
  long double v25; // fp2
  const char *v26; // r10
  const char *v27; // r9
  int v28; // r8
  int v29; // r8
  idASEMaterial *v30; // r29
  long double v31; // fp2
  const char *v32; // r10
  int v33; // r9
  int v34; // r9
  idASEMaterial *v35; // r29
  long double v36; // fp2
  idStr v37; // [sp+50h] [-140h] BYREF
  char v38[288]; // [sp+70h] [-120h] BYREF

  v1 = token;
  v2 = token;
  v3 = "*BITMAP";
  do
  {
    v4 = *(unsigned __int8 *)v2;
    v6 = v4 == 0;
    v5 = v4 - *(unsigned __int8 *)v3;
    if ( v6 )
      break;
    ++v2;
    ++v3;
  }
  while ( v5 == 0 );
  if ( v5 != 0 )
  {
    v8 = token;
    v9 = "*UVW_U_OFFSET";
    do
    {
      v10 = *(unsigned __int8 *)v8;
      v6 = v10 == 0;
      v11 = v10 - *(unsigned __int8 *)v9;
      if ( v6 )
        break;
      ++v8;
      ++v9;
    }
    while ( v11 == 0 );
    if ( v11 != 0 )
    {
      v14 = token;
      v15 = "*UVW_V_OFFSET";
      do
      {
        v16 = *(unsigned __int8 *)v14;
        v6 = v16 == 0;
        v17 = v16 - *(unsigned __int8 *)v15;
        if ( v6 )
          break;
        ++v14;
        ++v15;
      }
      while ( v17 == 0 );
      if ( v17 != 0 )
      {
        v20 = token;
        v21 = "*UVW_U_TILING";
        do
        {
          v22 = *(unsigned __int8 *)v20;
          v6 = v22 == 0;
          v23 = v22 - *(unsigned __int8 *)v21;
          if ( v6 )
            break;
          ++v20;
          ++v21;
        }
        while ( v23 == 0 );
        if ( v23 != 0 )
        {
          v26 = token;
          v27 = "*UVW_V_TILING";
          do
          {
            v28 = *(unsigned __int8 *)v26;
            v6 = v28 == 0;
            v29 = v28 - *(unsigned __int8 *)v27;
            if ( v6 )
              break;
            ++v26;
            ++v27;
          }
          while ( v29 == 0 );
          if ( v29 != 0 )
          {
            v32 = "*UVW_ANGLE";
            do
            {
              v33 = *(unsigned __int8 *)v1;
              v6 = v33 == 0;
              v34 = v33 - *(unsigned __int8 *)v32;
              if ( v6 )
                break;
              ++v1;
              ++v32;
            }
            while ( v34 == 0 );
            if ( v34 == 0 )
            {
              v35 = ase.model->materials.list[ase.model->materials.num - 1];
              ASE_GetToken(restOfLine: false);
              v36 = atof(nptr: ase.token);
              v35->angle = *(double *)&v36;
            }
          }
          else
          {
            v30 = ase.model->materials.list[ase.model->materials.num - 1];
            ASE_GetToken(restOfLine: false);
            v31 = atof(nptr: ase.token);
            v30->vTiling = *(double *)&v31;
          }
        }
        else
        {
          v24 = ase.model->materials.list[ase.model->materials.num - 1];
          ASE_GetToken(restOfLine: false);
          v25 = atof(nptr: ase.token);
          v24->uTiling = *(double *)&v25;
        }
      }
      else
      {
        v18 = ase.model->materials.list[ase.model->materials.num - 1];
        ASE_GetToken(restOfLine: false);
        v19 = atof(nptr: ase.token);
        v18->vOffset = *(double *)&v19;
      }
    }
    else
    {
      v12 = ase.model->materials.list[ase.model->materials.num - 1];
      ASE_GetToken(restOfLine: false);
      v13 = atof(nptr: ase.token);
      v12->uOffset = *(double *)&v13;
    }
  }
  else
  {
    v37.len = 0;
    v37.allocedAndFlag = 20;
    v37.data = v37.baseBuffer;
    v37.baseBuffer[0] = 0;
    ASE_GetToken(restOfLine: false);
    v7 = strstr(str1: &ase.token[1], str2: "\"");
    if ( v7 != nullptr )
      *v7 = 0;
    idStr::operator=(this: &v37, text: &ase.token[1]);
    idStr::BackSlashesToSlashes(this: &v37);
    fileSystem->OSPathToRelativePath(this: fileSystem, a2: v37.data, a3: v38, a4: 256);
    idStr::operator=(this: &ase.currentMaterial->name, text: v38);
    idStr::FreeData(this: &v37);
  }
}


// ========================================================================
// __unwind$221335
// EA  : 0x8287A308
// RVA : 0x0087A308
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void _unwind_221335()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 80));
}


// ========================================================================
// ASE_KeyMATERIAL
// EA  : 0x8287A330
// RVA : 0x0087A330
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyMATERIAL(const char *token)
{
  const char *v2; // r10
  int v3; // r9
  int v4; // r9
  bool v5; // zf

  v2 = "*MAP_DIFFUSE";
  do
  {
    v3 = *(unsigned __int8 *)token;
    v5 = v3 == 0;
    v4 = v3 - *(unsigned __int8 *)v2;
    if ( v5 )
      break;
    ++token;
    ++v2;
  }
  while ( v4 == 0 );
  if ( v4 == 0 )
    ASE_ParseBracedBlock(parser: ASE_KeyMAP_DIFFUSE);
}


// ========================================================================
// ASE_KeyNODE_TM
// EA  : 0x8287A378
// RVA : 0x0087A378
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyNODE_TM(const char *token)
{
  const char *v1; // r11
  const char *v2; // r10
  const char *v3; // r9
  int v4; // r8
  int v5; // r8
  bool v6; // zf
  int m; // r31
  float *v8; // r29
  long double v9; // fp2
  const char *v10; // r10
  const char *v11; // r9
  int v12; // r8
  int v13; // r8
  int k; // r31
  float *v15; // r29
  long double v16; // fp2
  const char *v17; // r10
  const char *v18; // r9
  int v19; // r8
  int v20; // r8
  int j; // r31
  float *v22; // r29
  long double v23; // fp2
  const char *v24; // r10
  int v25; // r9
  int v26; // r9
  int i; // r31
  float *v28; // r29
  long double v29; // fp2

  v1 = token;
  v2 = token;
  v3 = "*TM_ROW0";
  do
  {
    v4 = *(unsigned __int8 *)v2;
    v6 = v4 == 0;
    v5 = v4 - *(unsigned __int8 *)v3;
    if ( v6 )
      break;
    ++v2;
    ++v3;
  }
  while ( v5 == 0 );
  if ( v5 != 0 )
  {
    v10 = token;
    v11 = "*TM_ROW1";
    do
    {
      v12 = *(unsigned __int8 *)v10;
      v6 = v12 == 0;
      v13 = v12 - *(unsigned __int8 *)v11;
      if ( v6 )
        break;
      ++v10;
      ++v11;
    }
    while ( v13 == 0 );
    if ( v13 != 0 )
    {
      v17 = token;
      v18 = "*TM_ROW2";
      do
      {
        v19 = *(unsigned __int8 *)v17;
        v6 = v19 == 0;
        v20 = v19 - *(unsigned __int8 *)v18;
        if ( v6 )
          break;
        ++v17;
        ++v18;
      }
      while ( v20 == 0 );
      if ( v20 != 0 )
      {
        v24 = "*TM_ROW3";
        do
        {
          v25 = *(unsigned __int8 *)v1;
          v6 = v25 == 0;
          v26 = v25 - *(unsigned __int8 *)v24;
          if ( v6 )
            break;
          ++v1;
          ++v24;
        }
        while ( v26 == 0 );
        if ( v26 == 0 )
        {
          for ( i = 88; i < 100; i += 4 )
          {
            ASE_GetToken(restOfLine: false);
            v28 = (float *)((char *)&ase.currentObject->name.len + i);
            v29 = atof(nptr: ase.token);
            *v28 = *(double *)&v29;
          }
        }
      }
      else
      {
        for ( j = 76; j < 88; j += 4 )
        {
          ASE_GetToken(restOfLine: false);
          v22 = (float *)((char *)&ase.currentObject->name.len + j);
          v23 = atof(nptr: ase.token);
          *v22 = *(double *)&v23;
        }
      }
    }
    else
    {
      for ( k = 64; k < 76; k += 4 )
      {
        ASE_GetToken(restOfLine: false);
        v15 = (float *)((char *)&ase.currentObject->name.len + k);
        v16 = atof(nptr: ase.token);
        *v15 = *(double *)&v16;
      }
    }
  }
  else
  {
    for ( m = 52; m < 64; m += 4 )
    {
      ASE_GetToken(restOfLine: false);
      v8 = (float *)((char *)&ase.currentObject->name.len + m);
      v9 = atof(nptr: ase.token);
      *v8 = *(double *)&v9;
    }
  }
}


// ========================================================================
// ASE_KeyMESH_VERTEX_LIST
// EA  : 0x8287A568
// RVA : 0x0087A568
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyMESH_VERTEX_LIST(const char *token)
{
  const char *v1; // r10
  const char *v2; // r4
  const char *v3; // r11
  idASEMesh *currentMesh; // r30
  int v5; // r9
  int v6; // r9
  bool v7; // zf
  int currentVertex; // r29
  idVec3 *list; // r28
  long double v10; // fp2
  int v11; // r29
  long double v12; // fp2
  int v13; // r29
  long double v14; // fp2

  v1 = "*MESH_VERTEX";
  v2 = token;
  v3 = token;
  currentMesh = ase.currentMesh;
  do
  {
    v5 = *(unsigned __int8 *)v3;
    v7 = v5 == 0;
    v6 = v5 - *(unsigned __int8 *)v1;
    if ( v7 )
      break;
    ++v3;
    ++v1;
  }
  while ( v6 == 0 );
  if ( v6 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    ASE_GetToken(restOfLine: false);
    currentVertex = ase.currentVertex;
    list = currentMesh->vertexes.list;
    v10 = atof(nptr: ase.token);
    list[currentVertex].x = *(double *)&v10;
    ASE_GetToken(restOfLine: false);
    v11 = (int)&currentMesh->vertexes.list[ase.currentVertex];
    v12 = atof(nptr: ase.token);
    *(float *)(v11 + 4) = *(double *)&v12;
    ASE_GetToken(restOfLine: false);
    v13 = (int)&currentMesh->vertexes.list[ase.currentVertex];
    v14 = atof(nptr: ase.token);
    *(float *)(v13 + 8) = *(double *)&v14;
    if ( ++ase.currentVertex <= currentMesh->vertexes.num )
      return;
    idLib::Error(fmt: "ase.currentVertex >= pMesh->vertexes.Num");
  }
  idLib::Error(fmt: "Unknown token '%s' while parsing MESH_VERTEX_LIST", v2);
}


// ========================================================================
// ASE_KeyCFACE_LIST
// EA  : 0x8287A688
// RVA : 0x0087A688
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyCFACE_LIST(const char *token)
{
  const char *v1; // r10
  const char *v2; // r11
  idASEMesh *currentMesh; // r30
  int v4; // r9
  int v5; // r9
  bool v6; // zf
  int *v7; // r31
  int v8; // r8
  int v9; // r11
  char v10; // r9
  int v11; // r11
  char v12; // r7
  int v13; // r11
  char v14; // r8
  int v15; // r6

  v1 = "*MESH_CFACE";
  v2 = token;
  currentMesh = ase.currentMesh;
  do
  {
    v4 = *(unsigned __int8 *)v2;
    v6 = v4 == 0;
    v5 = v4 - *(unsigned __int8 *)v1;
    if ( v6 )
      break;
    ++v2;
    ++v1;
  }
  while ( v5 == 0 );
  if ( v5 != 0 )
  {
    idLib::Error(fmt: "Unknown token '%s' in MESH_CFACE", token);
    JUMPOUT(0x8287A85C);
  }
  ASE_GetToken(restOfLine: false);
  v7 = remap;
  do
  {
    ASE_GetToken(restOfLine: false);
    v8 = atol(nptr: ase.token);
    v9 = (int)(float)(currentMesh->cvertexes.list[v8].x * (float)255.0);
    if ( v9 >= 0 )
    {
      v10 = -1;
      if ( v9 <= 255 )
        v10 = (int)(float)(currentMesh->cvertexes.list[v8].x * (float)255.0);
    }
    else
    {
      v10 = 0;
    }
    currentMesh->faces[ase.currentFace].vertexColors[*v7][0] = v10;
    v11 = (int)(float)(currentMesh->cvertexes.list[v8].y * (float)255.0);
    if ( v11 >= 0 )
    {
      v12 = -1;
      if ( v11 <= 255 )
        v12 = (int)(float)(currentMesh->cvertexes.list[v8].y * (float)255.0);
    }
    else
    {
      v12 = 0;
    }
    currentMesh->faces[ase.currentFace].vertexColors[*v7][1] = v12;
    v13 = (int)(float)(currentMesh->cvertexes.list[v8].z * (float)255.0);
    if ( v13 >= 0 )
    {
      v14 = -1;
      if ( v13 <= 255 )
        v14 = v13;
    }
    else
    {
      v14 = 0;
    }
    v15 = 21 * ase.currentFace + *v7++;
    currentMesh->faces->vertexColors[v15][2] = v14;
  }
  while ( (int)v7 < (int)&dword_835C00AC );
  ++ase.currentFace;
}


// ========================================================================
// ASE_KeyMESH_TVERTLIST
// EA  : 0x8287A860
// RVA : 0x0087A860
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyMESH_TVERTLIST(const char *token)
{
  const char *v1; // r10
  const char *v2; // r4
  const char *v3; // r11
  idASEMesh *currentMesh; // r30
  int v5; // r9
  int v6; // r9
  bool v7; // zf
  int currentVertex; // r28
  idVec2 *list; // r29
  long double v10; // fp2
  int v11; // r29
  long double v12; // fp2
  char v13[80]; // [sp+50h] [-120h] BYREF
  char v14[80]; // [sp+A0h] [-D0h] BYREF
  char v15; // [sp+F0h] [-80h] BYREF

  v1 = "*MESH_TVERT";
  v2 = token;
  v3 = token;
  currentMesh = ase.currentMesh;
  do
  {
    v5 = *(unsigned __int8 *)v3;
    v7 = v5 == 0;
    v6 = v5 - *(unsigned __int8 *)v1;
    if ( v7 )
      break;
    ++v3;
    ++v1;
  }
  while ( v6 == 0 );
  if ( v6 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    ASE_GetToken(restOfLine: false);
    idStr::Copynz(dest: v14, src: ase.token, destsize: 80);
    ASE_GetToken(restOfLine: false);
    idStr::Copynz(dest: v13, src: ase.token, destsize: 80);
    ASE_GetToken(restOfLine: false);
    idStr::Copynz(dest: &v15, src: ase.token, destsize: 80);
    currentVertex = ase.currentVertex;
    list = currentMesh->tvertexes.list;
    v10 = atof(nptr: v14);
    list[currentVertex].x = *(double *)&v10;
    v11 = (int)&currentMesh->tvertexes.list[ase.currentVertex];
    v12 = atof(nptr: v13);
    *(float *)(v11 + 4) = 1.0 - *(double *)&v12;
    if ( ++ase.currentVertex <= currentMesh->tvertexes.num )
      return;
    idLib::Error(fmt: "ase.currentVertex > pMesh->tvertexes.Num");
  }
  idLib::Error(fmt: "Unknown token '%s' while parsing MESH_TVERTLIST", v2);
}


// ========================================================================
// ASE_KeyMESH_CVERTLIST
// EA  : 0x8287A988
// RVA : 0x0087A988
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyMESH_CVERTLIST(const char *token)
{
  const char *v1; // r29
  const char *v2; // r11
  const char *v3; // r10
  idASEMesh *currentMesh; // r30
  int v5; // r9
  int v6; // r9
  bool v7; // zf
  int currentVertex; // r28
  idVec3 *list; // r27
  long double v10; // fp2
  int v11; // r28
  long double v12; // fp2
  const char *v13; // r3
  long double v14; // fp2

  v1 = token;
  v2 = token;
  v3 = "*MESH_VERTCOL";
  currentMesh = ase.currentMesh;
  ase.currentMesh->colorsParsed = true;
  do
  {
    v5 = *(unsigned __int8 *)v2;
    v7 = v5 == 0;
    v6 = v5 - *(unsigned __int8 *)v3;
    if ( v7 )
      break;
    ++v2;
    ++v3;
  }
  while ( v6 == 0 );
  if ( v6 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    ASE_GetToken(restOfLine: false);
    currentVertex = ase.currentVertex;
    list = currentMesh->cvertexes.list;
    v10 = atof(nptr: v1);
    list[currentVertex].x = *(double *)&v10;
    ASE_GetToken(restOfLine: false);
    v11 = (int)&currentMesh->cvertexes.list[ase.currentVertex];
    v12 = atof(nptr: v1);
    *(float *)(v11 + 4) = *(double *)&v12;
    ASE_GetToken(restOfLine: false);
    v13 = v1;
    v1 = (const char *)&currentMesh->cvertexes.list[ase.currentVertex];
    v14 = atof(nptr: v13);
    *((float *)v1 + 2) = *(double *)&v14;
    if ( ++ase.currentVertex <= currentMesh->cvertexes.num )
      return;
    idLib::Error(fmt: "ase.currentVertex > pMesh->cvertexes.Num");
  }
  idLib::Error(fmt: "Unknown token '%s' while parsing MESH_CVERTLIST", v1);
}


// ========================================================================
// ASE_KeyMESH_NORMALS
// EA  : 0x8287AAB8
// RVA : 0x0087AAB8
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyMESH_NORMALS(const char *token)
{
  const char *v1; // r11
  const char *v2; // r10
  idASEMesh *currentMesh; // r31
  idVec3 *v4; // r29
  int v5; // r9
  int v6; // r9
  bool v7; // zf
  int v8; // r3
  long double v9; // fp2
  double v10; // fp31
  long double v11; // fp2
  double v12; // fp30
  long double v13; // fp2
  const char *v14; // r11
  const char *v15; // r10
  int v16; // r9
  int v17; // r9
  int v18; // r3
  int v19; // r29
  int vertexNum; // r28
  _DWORD *v21; // r11
  long double v22; // fp2
  double v23; // fp31
  long double v24; // fp2
  double v25; // fp30
  long double v26; // fp2
  idVec3 *v27; // r3
  int v28; // r11

  v1 = token;
  v2 = "*MESH_FACENORMAL";
  currentMesh = ase.currentMesh;
  ase.currentMesh->normalsParsed = true;
  v4 = (idVec3 *)&currentMesh->faces[ase.currentFace];
  do
  {
    v5 = *(unsigned __int8 *)v1;
    v7 = v5 == 0;
    v6 = v5 - *(unsigned __int8 *)v2;
    if ( v7 )
      break;
    ++v1;
    ++v2;
  }
  while ( v6 == 0 );
  if ( v6 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    v8 = atol(nptr: ase.token);
    if ( v8 < currentMesh->numFaces && v8 >= 0 )
    {
      if ( v8 != ase.currentFace )
        idLib::Error(fmt: "MESH_NORMALS face index != currentFace", v8);
      ASE_GetToken(restOfLine: false);
      v9 = atof(nptr: ase.token);
      v10 = (float)*(double *)&v9;
      ASE_GetToken(restOfLine: false);
      v11 = atof(nptr: ase.token);
      v12 = (float)*(double *)&v11;
      ASE_GetToken(restOfLine: false);
      v13 = atof(nptr: ase.token);
      v4[2].x = (float)(currentMesh->transform[0].x * (float)v10)
              + (float)((float)(currentMesh->transform[2].x * (float)*(double *)&v13)
                      + (float)(currentMesh->transform[1].x * (float)v12));
      v4[2].y = (float)(currentMesh->transform[0].y * (float)v10)
              + (float)((float)(currentMesh->transform[2].y * (float)*(double *)&v13)
                      + (float)(currentMesh->transform[1].y * (float)v12));
      v4[2].z = (float)(currentMesh->transform[0].z * (float)v10)
              + (float)((float)(currentMesh->transform[2].z * (float)*(double *)&v13)
                      + (float)(currentMesh->transform[1].z * (float)v12));
      idVec3::NormalizeFast(this: v4 + 2);
      ++ase.currentFace;
      return;
    }
    idLib::Error(fmt: "MESH_NORMALS face index out of range: %i", v8);
  }
  v14 = token;
  v15 = "*MESH_VERTEXNORMAL";
  do
  {
    v16 = *(unsigned __int8 *)v14;
    v7 = v16 == 0;
    v17 = v16 - *(unsigned __int8 *)v15;
    if ( v7 )
      break;
    ++v14;
    ++v15;
  }
  while ( v17 == 0 );
  if ( v17 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    v18 = atol(nptr: ase.token);
    if ( v18 >= currentMesh->vertexes.num || v18 < 0 )
    {
      idLib::Error(fmt: "MESH_NORMALS vertex index out of range: %i", v18);
      JUMPOUT(0x8287ADA8);
    }
    v19 = 0;
    vertexNum = (int)currentMesh->faces[ase.currentFace - 1].vertexNum;
    v21 = (_DWORD *)vertexNum;
    do
    {
      if ( v18 == *v21 )
        break;
      ++v19;
      ++v21;
    }
    while ( v19 < 3 );
    if ( v19 == 3 )
      idLib::Error(fmt: "MESH_NORMALS vertex index doesn't match face", v18);
    ASE_GetToken(restOfLine: false);
    v22 = atof(nptr: ase.token);
    v23 = (float)*(double *)&v22;
    ASE_GetToken(restOfLine: false);
    v24 = atof(nptr: ase.token);
    v25 = (float)*(double *)&v24;
    ASE_GetToken(restOfLine: false);
    v26 = atof(nptr: ase.token);
    v27 = (idVec3 *)(12 * (v19 + 3) + vertexNum);
    v28 = 12 * v19 + vertexNum;
    v27->x = (float)(currentMesh->transform[0].x * (float)v23)
           + (float)((float)(currentMesh->transform[2].x * (float)*(double *)&v26)
                   + (float)(currentMesh->transform[1].x * (float)v25));
    *(float *)(v28 + 40) = (float)(currentMesh->transform[0].y * (float)v23)
                         + (float)((float)(currentMesh->transform[2].y * (float)*(double *)&v26)
                                 + (float)(currentMesh->transform[1].y * (float)v25));
    *(float *)(v28 + 44) = (float)(currentMesh->transform[0].z * (float)v23)
                         + (float)((float)(currentMesh->transform[2].z * (float)*(double *)&v26)
                                 + (float)(currentMesh->transform[1].z * (float)v25));
    idVec3::NormalizeFast(this: v27);
  }
}


// ========================================================================
// ASE_KeyMATERIAL_LIST
// EA  : 0x8287B2C0
// RVA : 0x0087B2C0
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyMATERIAL_LIST(const char *token)
{
  const char *v1; // r11
  const char *v2; // r10
  const char *v3; // r9
  int v4; // r8
  int v5; // r8
  bool v6; // zf
  const char *v7; // r10
  int v8; // r9
  int v9; // r9
  idASEMaterial *v10; // r3
  idASEMaterial *v11; // r11

  v1 = token;
  v2 = token;
  v3 = "*MATERIAL_COUNT";
  do
  {
    v4 = *(unsigned __int8 *)v2;
    v6 = v4 == 0;
    v5 = v4 - *(unsigned __int8 *)v3;
    if ( v6 )
      break;
    ++v2;
    ++v3;
  }
  while ( v5 == 0 );
  if ( v5 != 0 )
  {
    v7 = "*MATERIAL";
    do
    {
      v8 = *(unsigned __int8 *)v1;
      v6 = v8 == 0;
      v9 = v8 - *(unsigned __int8 *)v7;
      if ( v6 )
        break;
      ++v1;
      ++v7;
    }
    while ( v9 == 0 );
    if ( v9 == 0 )
    {
      if ( ase.verbose )
        idLib::Printf(fmt: "..material %d\n", ase.model->materials.num);
      v10 = (idASEMaterial *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                               size: 0x34u,
                               tag: TAG_NEW,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
      if ( v10 != nullptr )
      {
        v10->name.len = 0;
        v10->name.data = v10->name.baseBuffer;
        v11 = v10;
        v10->name.allocedAndFlag = 20;
        v10->name.baseBuffer[0] = 0;
        v10->vOffset = 0.0;
        v10->uOffset = 0.0;
        v10->vTiling = 0.0;
        v10->uTiling = 0.0;
        v10->angle = 0.0;
      }
      else
      {
        v11 = nullptr;
      }
      ase.currentMaterial = v11;
      v11->uTiling = 1.0;
      ase.currentMaterial->vTiling = 1.0;
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)ase.model,
        obj: (const encounterGroupRole_t *)&ase.currentMaterial);
      ASE_ParseBracedBlock(parser: ASE_KeyMATERIAL);
    }
  }
  else
  {
    ASE_GetToken(restOfLine: false);
    if ( ase.verbose )
      idLib::Printf(fmt: "..num materials: %s\n", ase.token);
  }
}


// ========================================================================
// ASE_KeyMESH
// EA  : 0x8287B460
// RVA : 0x0087B460
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyMESH(const char *token)
{
  const char *v1; // r10
  const char *v2; // r11
  idASEMesh *currentMesh; // r30
  int v4; // r9
  int v5; // r9
  bool v6; // zf
  int v7; // r3
  const char *v8; // r11
  const char *v9; // r10
  int v10; // r9
  int v11; // r9
  int v12; // r3
  const char *v13; // r11
  const char *v14; // r10
  int v15; // r9
  int v16; // r9
  int v17; // r3
  const char *v18; // r11
  const char *v19; // r10
  int v20; // r9
  int v21; // r9
  int v22; // r3
  const char *v23; // r11
  const char *v24; // r10
  int v25; // r9
  int v26; // r9
  int v27; // r3
  const char *v28; // r11
  const char *v29; // r10
  int v30; // r9
  int v31; // r9
  int v32; // r3
  int v33; // r4
  const char *v34; // r11
  const char *v35; // r10
  int v36; // r9
  int v37; // r9
  int v38; // r3
  int v39; // r4
  const char *v40; // r11
  const char *v41; // r10
  int v42; // r9
  int v43; // r9
  void (__fastcall *v44)(const char *); // r3
  const char *v45; // r11
  const char *v46; // r10
  int v47; // r9
  int v48; // r9
  const char *v49; // r11
  const char *v50; // r10
  int v51; // r9
  int v52; // r9
  const char *v53; // r11
  const char *v54; // r10
  int v55; // r9
  int v56; // r9
  unsigned int numFaces; // r11
  unsigned int v58; // r5
  const char *v59; // r11
  const char *v60; // r10
  int v61; // r9
  int v62; // r9
  const char *v63; // r11
  const char *v64; // r10
  int v65; // r9
  int v66; // r9
  const char *v67; // r11
  const char *v68; // r10
  int v69; // r9
  int v70; // r9

  v1 = "*TIMEVALUE";
  v2 = token;
  currentMesh = ase.currentMesh;
  do
  {
    v4 = *(unsigned __int8 *)v2;
    v6 = v4 == 0;
    v5 = v4 - *(unsigned __int8 *)v1;
    if ( v6 )
      break;
    ++v2;
    ++v1;
  }
  while ( v5 == 0 );
  if ( v5 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    v7 = atol(nptr: ase.token);
    currentMesh->timeValue = v7;
    if ( ase.verbose )
      idLib::Printf(fmt: ".....timevalue: %d\n", v7);
    return;
  }
  v8 = token;
  v9 = "*MESH_NUMVERTEX";
  do
  {
    v10 = *(unsigned __int8 *)v8;
    v6 = v10 == 0;
    v11 = v10 - *(unsigned __int8 *)v9;
    if ( v6 )
      break;
    ++v8;
    ++v9;
  }
  while ( v11 == 0 );
  if ( v11 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    v12 = atol(nptr: ase.token);
    idList<idVec3,37>::SetNum(this: &currentMesh->vertexes, newNum: v12);
    if ( ase.verbose )
      idLib::Printf(fmt: ".....num vertexes: %d\n", currentMesh->vertexes.num);
    return;
  }
  v13 = token;
  v14 = "*MESH_NUMTVERTEX";
  do
  {
    v15 = *(unsigned __int8 *)v13;
    v6 = v15 == 0;
    v16 = v15 - *(unsigned __int8 *)v14;
    if ( v6 )
      break;
    ++v13;
    ++v14;
  }
  while ( v16 == 0 );
  if ( v16 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    v17 = atol(nptr: ase.token);
    idList<idVec2,72>::SetNum(this: (idList<idVec2,72> *)&currentMesh->tvertexes, newNum: v17);
    if ( ase.verbose )
      idLib::Printf(fmt: ".....num tvertexes: %d\n", currentMesh->tvertexes.num);
    return;
  }
  v18 = token;
  v19 = "*MESH_NUMCVERTEX";
  do
  {
    v20 = *(unsigned __int8 *)v18;
    v6 = v20 == 0;
    v21 = v20 - *(unsigned __int8 *)v19;
    if ( v6 )
      break;
    ++v18;
    ++v19;
  }
  while ( v21 == 0 );
  if ( v21 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    v22 = atol(nptr: ase.token);
    idList<idVec3,37>::SetNum(this: &currentMesh->cvertexes, newNum: v22);
    if ( ase.verbose )
      idLib::Printf(fmt: ".....num cvertexes: %d\n", currentMesh->cvertexes.num);
    return;
  }
  v23 = token;
  v24 = "*MESH_NUMFACES";
  do
  {
    v25 = *(unsigned __int8 *)v23;
    v6 = v25 == 0;
    v26 = v25 - *(unsigned __int8 *)v24;
    if ( v6 )
      break;
    ++v23;
    ++v24;
  }
  while ( v26 == 0 );
  if ( v26 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    v27 = atol(nptr: ase.token);
    currentMesh->numFaces = v27;
    if ( ase.verbose )
      idLib::Printf(fmt: ".....num faces: %d\n", v27);
    return;
  }
  v28 = token;
  v29 = "*MESH_NUMTVFACES";
  do
  {
    v30 = *(unsigned __int8 *)v28;
    v6 = v30 == 0;
    v31 = v30 - *(unsigned __int8 *)v29;
    if ( v6 )
      break;
    ++v28;
    ++v29;
  }
  while ( v31 == 0 );
  if ( v31 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    v32 = atol(nptr: ase.token);
    currentMesh->numTVFaces = v32;
    v33 = v32;
    if ( ase.verbose )
      idLib::Printf(fmt: ".....num tvfaces: %d\n", v32);
    if ( currentMesh->numTVFaces == currentMesh->numFaces )
      return;
    idLib::Error(fmt: "MESH_NUMTVFACES != MESH_NUMFACES", v33);
  }
  v34 = token;
  v35 = "*MESH_NUMCVFACES";
  do
  {
    v36 = *(unsigned __int8 *)v34;
    v6 = v36 == 0;
    v37 = v36 - *(unsigned __int8 *)v35;
    if ( v6 )
      break;
    ++v34;
    ++v35;
  }
  while ( v37 == 0 );
  if ( v37 != 0 )
  {
_LN103_2:
    v40 = token;
    v41 = "*MESH_VERTEX_LIST";
    do
    {
      v42 = *(unsigned __int8 *)v40;
      v6 = v42 == 0;
      v43 = v42 - *(unsigned __int8 *)v41;
      if ( v6 )
        break;
      ++v40;
      ++v41;
    }
    while ( v43 == 0 );
    if ( v43 != 0 )
    {
      v45 = token;
      v46 = "*MESH_TVERTLIST";
      do
      {
        v47 = *(unsigned __int8 *)v45;
        v6 = v47 == 0;
        v48 = v47 - *(unsigned __int8 *)v46;
        if ( v6 )
          break;
        ++v45;
        ++v46;
      }
      while ( v48 == 0 );
      if ( v48 != 0 )
      {
        v49 = token;
        v50 = "*MESH_CVERTLIST";
        do
        {
          v51 = *(unsigned __int8 *)v49;
          v6 = v51 == 0;
          v52 = v51 - *(unsigned __int8 *)v50;
          if ( v6 )
            break;
          ++v49;
          ++v50;
        }
        while ( v52 == 0 );
        if ( v52 != 0 )
        {
          v53 = token;
          v54 = "*MESH_FACE_LIST";
          do
          {
            v55 = *(unsigned __int8 *)v53;
            v6 = v55 == 0;
            v56 = v55 - *(unsigned __int8 *)v54;
            if ( v6 )
              break;
            ++v53;
            ++v54;
          }
          while ( v56 == 0 );
          if ( v56 != 0 )
          {
            v59 = token;
            v60 = "*MESH_TFACELIST";
            do
            {
              v61 = *(unsigned __int8 *)v59;
              v6 = v61 == 0;
              v62 = v61 - *(unsigned __int8 *)v60;
              if ( v6 )
                break;
              ++v59;
              ++v60;
            }
            while ( v62 == 0 );
            if ( v62 != 0 )
            {
              v63 = token;
              v64 = "*MESH_CFACELIST";
              do
              {
                v65 = *(unsigned __int8 *)v63;
                v6 = v65 == 0;
                v66 = v65 - *(unsigned __int8 *)v64;
                if ( v6 )
                  break;
                ++v63;
                ++v64;
              }
              while ( v66 == 0 );
              if ( v66 != 0 )
              {
                v67 = token;
                v68 = "*MESH_NORMALS";
                do
                {
                  v69 = *(unsigned __int8 *)v67;
                  v6 = v69 == 0;
                  v70 = v69 - *(unsigned __int8 *)v68;
                  if ( v6 )
                    break;
                  ++v67;
                  ++v68;
                }
                while ( v70 == 0 );
                if ( v70 != 0 )
                  return;
                if ( currentMesh->faces == nullptr )
                  idLib::Warning(fmt: "*MESH_NORMALS before *MESH_FACE_LIST");
                ase.currentFace = 0;
                if ( ase.verbose )
                  idLib::Printf(fmt: ".....parsing MESH_NORMALS\n");
                v44 = ASE_KeyMESH_NORMALS;
              }
              else
              {
                if ( currentMesh->faces == nullptr )
                  idLib::Error(fmt: "*MESH_CFACELIST before *MESH_FACE_LIST");
                ase.currentFace = 0;
                if ( ase.verbose )
                  idLib::Printf(fmt: ".....parsing MESH_CFACE_LIST\n");
                v44 = ASE_KeyCFACE_LIST;
              }
            }
            else
            {
              if ( currentMesh->faces == nullptr )
                idLib::Error(fmt: "*MESH_TFACELIST before *MESH_FACE_LIST");
              ase.currentFace = 0;
              if ( ase.verbose )
                idLib::Printf(fmt: ".....parsing MESH_TFACE_LIST\n");
              v44 = ASE_KeyTFACE_LIST;
            }
          }
          else
          {
            numFaces = currentMesh->numFaces;
            v58 = 84 * numFaces;
            if ( numFaces > 0x30C30C3 )
              v58 = -1;
            currentMesh->faces = (aseFace_t *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                                size: v58,
                                                tag: TAG_NEW,
                                                zeroBuffer: false,
                                                align: ALIGN_16,
                                                heap: HEAP_DEFAULTHEAP);
            ase.currentFace = 0;
            if ( ase.verbose )
              idLib::Printf(fmt: ".....parsing MESH_FACE_LIST\n");
            v44 = ASE_KeyMESH_FACE_LIST;
          }
        }
        else
        {
          ase.currentVertex = 0;
          if ( ase.verbose )
            idLib::Printf(fmt: ".....parsing MESH_CVERTLIST\n");
          v44 = ASE_KeyMESH_CVERTLIST;
        }
      }
      else
      {
        ase.currentVertex = 0;
        if ( ase.verbose )
          idLib::Printf(fmt: ".....parsing MESH_TVERTLIST\n");
        v44 = ASE_KeyMESH_TVERTLIST;
      }
    }
    else
    {
      ase.currentVertex = 0;
      if ( ase.verbose )
        idLib::Printf(fmt: ".....parsing MESH_VERTEX_LIST\n");
      v44 = ASE_KeyMESH_VERTEX_LIST;
    }
    ASE_ParseBracedBlock(parser: v44);
    return;
  }
  ASE_GetToken(restOfLine: false);
  v38 = atol(nptr: ase.token);
  currentMesh->numCVFaces = v38;
  v39 = v38;
  if ( ase.verbose )
    idLib::Printf(fmt: ".....num cvfaces: %d\n", v38);
  if ( currentMesh->numTVFaces != currentMesh->numFaces )
  {
    idLib::Error(fmt: "MESH_NUMCVFACES != MESH_NUMFACES", v39);
    goto _LN103_2;
  }
}


// ========================================================================
// ASE_KeyMESH_ANIMATION
// EA  : 0x8287BB28
// RVA : 0x0087BB28
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyMESH_ANIMATION(const char *token)
{
  const char *v1; // r11
  const char *v2; // r10
  int v3; // r9
  int v4; // r9
  bool v5; // zf
  idASEMesh *v6; // r3
  idASEMesh *v7; // r3
  idASEMesh *v8; // [sp+50h] [-20h] BYREF

  v1 = token;
  v2 = "*MESH";
  do
  {
    v3 = *(unsigned __int8 *)v1;
    v5 = v3 == 0;
    v4 = v3 - *(unsigned __int8 *)v2;
    if ( v5 )
      break;
    ++v1;
    ++v2;
  }
  while ( v4 == 0 );
  if ( v4 != 0 )
  {
    idLib::Error(fmt: "Unknown token '%s' while parsing MESH_ANIMATION", token);
    _LN20_3();
  }
  else
  {
    if ( ase.verbose )
      idLib::Printf(fmt: "...found MESH\n", token);
    v6 = (idASEMesh *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x78u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
    v8 = v6;
    if ( v6 != nullptr )
      v7 = idASEMesh::idASEMesh(this: v6);
    else
      v7 = nullptr;
    v8 = v7;
    ase.currentMesh = v7;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&ase.currentObject->frames,
      obj: (const encounterGroupRole_t *)&v8);
    ASE_ParseBracedBlock(parser: ASE_KeyMESH);
  }
}


// ========================================================================
// $LN20_3
// EA  : 0x8287BC24
// RVA : 0x0087BC24
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall _LN20_3(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ASE_KeyGEOMOBJECT
// EA  : 0x8287BC50
// RVA : 0x0087BC50
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyGEOMOBJECT(const char *token)
{
  const char *v1; // r10
  const char *v2; // r11
  idASEObject *currentObject; // r31
  int v4; // r9
  int v5; // r9
  bool v6; // zf
  const char *v7; // r11
  const char *v8; // r10
  int v9; // r9
  int v10; // r9
  const char *v11; // r11
  const char *v12; // r10
  int v13; // r9
  int v14; // r9
  const char *v15; // r11
  const char *v16; // r10
  int v17; // r9
  int v18; // r9
  const char *v19; // r11
  const char *v20; // r10
  int v21; // r9
  int v22; // r9
  void (__fastcall *v23)(const char *); // r3
  const char *v24; // r11
  const char *v25; // r10
  int v26; // r9
  int v27; // r9
  const char *v28; // r11
  const char *v29; // r10
  int v30; // r9
  int v31; // r9
  const char *v32; // r11
  const char *v33; // r10
  int v34; // r9
  int v35; // r9
  const char *v36; // r11
  const char *v37; // r10
  int v38; // r9
  int v39; // r9
  const char *v40; // r11
  const char *v41; // r10
  int v42; // r9
  int v43; // r9

  v1 = "*NODE_NAME";
  v2 = token;
  currentObject = ase.currentObject;
  do
  {
    v4 = *(unsigned __int8 *)v2;
    v6 = v4 == 0;
    v5 = v4 - *(unsigned __int8 *)v1;
    if ( v6 )
      break;
    ++v2;
    ++v1;
  }
  while ( v5 == 0 );
  if ( v5 == 0 )
  {
    ASE_GetToken(restOfLine: true);
    if ( ase.verbose )
      idLib::Printf(fmt: " %s\n", ase.token);
    idStr::operator=(this: &currentObject->name, text: ase.token);
    return;
  }
  v7 = token;
  v8 = "*NODE_PARENT";
  do
  {
    v9 = *(unsigned __int8 *)v7;
    v6 = v9 == 0;
    v10 = v9 - *(unsigned __int8 *)v8;
    if ( v6 )
      break;
    ++v7;
    ++v8;
  }
  while ( v10 == 0 );
  if ( v10 == 0 )
    goto LABEL_49;
  v11 = token;
  v12 = "*NODE_TM";
  do
  {
    v13 = *(unsigned __int8 *)v11;
    v6 = v13 == 0;
    v14 = v13 - *(unsigned __int8 *)v12;
    if ( v6 )
      break;
    ++v11;
    ++v12;
  }
  while ( v14 == 0 );
  if ( v14 == 0 )
    goto LABEL_50;
  v15 = token;
  v16 = "*TM_ANIMATION";
  do
  {
    v17 = *(unsigned __int8 *)v15;
    v6 = v17 == 0;
    v18 = v17 - *(unsigned __int8 *)v16;
    if ( v6 )
      break;
    ++v15;
    ++v16;
  }
  while ( v18 == 0 );
  if ( v18 == 0 )
  {
LABEL_50:
    v23 = ASE_KeyNODE_TM;
    goto LABEL_51;
  }
  v19 = token;
  v20 = "*MESH";
  do
  {
    v21 = *(unsigned __int8 *)v19;
    v6 = v21 == 0;
    v22 = v21 - *(unsigned __int8 *)v20;
    if ( v6 )
      break;
    ++v19;
    ++v20;
  }
  while ( v22 == 0 );
  if ( v22 == 0 )
  {
    ase.currentMesh = &ase.currentObject->mesh;
    memset(Dst: &ase.currentObject->mesh, Val: 0, Size: sizeof(ase.currentObject->mesh));
    v23 = ASE_KeyMESH;
LABEL_51:
    ASE_ParseBracedBlock(parser: v23);
    return;
  }
  v24 = token;
  v25 = "*MATERIAL_REF";
  do
  {
    v26 = *(unsigned __int8 *)v24;
    v6 = v26 == 0;
    v27 = v26 - *(unsigned __int8 *)v25;
    if ( v6 )
      break;
    ++v24;
    ++v25;
  }
  while ( v27 == 0 );
  if ( v27 == 0 )
  {
    ASE_GetToken(restOfLine: false);
    currentObject->materialRef = atol(nptr: ase.token);
    return;
  }
  v28 = token;
  v29 = "*MESH_ANIMATION";
  do
  {
    v30 = *(unsigned __int8 *)v28;
    v6 = v30 == 0;
    v31 = v30 - *(unsigned __int8 *)v29;
    if ( v6 )
      break;
    ++v28;
    ++v29;
  }
  while ( v31 == 0 );
  if ( v31 == 0 )
  {
    if ( ase.verbose )
      idLib::Printf(fmt: "..found MESH_ANIMATION\n");
    v23 = ASE_KeyMESH_ANIMATION;
    goto LABEL_51;
  }
  v32 = token;
  v33 = "*PROP_MOTIONBLUR";
  do
  {
    v34 = *(unsigned __int8 *)v32;
    v6 = v34 == 0;
    v35 = v34 - *(unsigned __int8 *)v33;
    if ( v6 )
      break;
    ++v32;
    ++v33;
  }
  while ( v35 == 0 );
  if ( v35 == 0 )
    goto LABEL_49;
  v36 = token;
  v37 = "*PROP_CASTSHADOW";
  do
  {
    v38 = *(unsigned __int8 *)v36;
    v6 = v38 == 0;
    v39 = v38 - *(unsigned __int8 *)v37;
    if ( v6 )
      break;
    ++v36;
    ++v37;
  }
  while ( v39 == 0 );
  if ( v39 == 0 )
    goto LABEL_49;
  v40 = token;
  v41 = "*PROP_RECVSHADOW";
  do
  {
    v42 = *(unsigned __int8 *)v40;
    v6 = v42 == 0;
    v43 = v42 - *(unsigned __int8 *)v41;
    if ( v6 )
      break;
    ++v40;
    ++v41;
  }
  while ( v43 == 0 );
  if ( v43 == 0 )
LABEL_49:
    ASE_GetToken(restOfLine: true);
}


// ========================================================================
// ?ASE_ParseGeomObject@@YAXXZ
// EA  : 0x8287BF68
// RVA : 0x0087BF68
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_ParseGeomObject()
{
  idASEObject *v0; // r3
  idASEObject *v1; // r30
  idASEObject *v2; // [sp+50h] [-30h] BYREF

  if ( ase.verbose )
    idLib::Printf(fmt: "GEOMOBJECT");
  v0 = (idASEObject *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0xACu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v2 = v0;
  if ( v0 != nullptr )
    v1 = idASEObject::idASEObject(this: v0);
  else
    v1 = nullptr;
  v2 = v1;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&ase.model->objects,
    obj: (const encounterGroupRole_t *)&v2);
  ase.currentObject = v1;
  if ( v1->frames.size < 32 )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v1->frames, newsize: 32);
  ASE_ParseBracedBlock(parser: ASE_KeyGEOMOBJECT);
}


// ========================================================================
// __unwind$223166
// EA  : 0x8287C020
// RVA : 0x0087C020
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall _unwind_223166(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ASE_KeyGROUP
// EA  : 0x8287C048
// RVA : 0x0087C048
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_KeyGROUP(const char *token)
{
  const char *v2; // r10
  int v3; // r9
  int v4; // r9
  bool v5; // zf

  v2 = "*GEOMOBJECT";
  do
  {
    v3 = *(unsigned __int8 *)token;
    v5 = v3 == 0;
    v4 = v3 - *(unsigned __int8 *)v2;
    if ( v5 )
      break;
    ++token;
    ++v2;
  }
  while ( v4 == 0 );
  if ( v4 == 0 )
    ASE_ParseGeomObject();
}


// ========================================================================
// ?ASE_Parse@@YAPAVidASEModel@@PBD_N@Z
// EA  : 0x8287C090
// RVA : 0x0087C090
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

idASEModel *__fastcall ASE_Parse(const char *buffer, bool verbose)
{
  int v4; // r11
  idASEModel *v5; // r3
  idASEModel *model; // r11
  const char *v7; // r10
  char *token; // r11
  int v9; // r9
  int v10; // r9
  bool v11; // zf
  const char *v12; // r10
  char *v13; // r11
  int v14; // r9
  int v15; // r9
  const char *v16; // r10
  char *v17; // r11
  int v18; // r9
  int v19; // r9
  const char *v20; // r10
  char *v21; // r11
  int v22; // r9
  int v23; // r9
  const char *v24; // r10
  char *v25; // r11
  int v26; // r9
  int v27; // r9
  const char *v28; // r10
  char *v29; // r11
  int v30; // r9
  int v31; // r9
  const char *v32; // r10
  char *v33; // r11
  int v34; // r9
  int v35; // r9
  const char *v36; // r10
  char *v37; // r11
  int v38; // r9
  int v39; // r9

  memset(Dst: &ase, Val: 0, Size: sizeof(ase));
  ase.verbose = verbose;
  ase.buffer = buffer;
  v4 = 0;
  if ( *buffer != 0 )
  {
    do
      ++v4;
    while ( buffer[v4] != 0 );
  }
  ase.len = v4;
  ase.curpos = buffer;
  ase.currentObject = nullptr;
  v5 = (idASEModel *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                       size: 0x20u,
                       tag: TAG_NEW,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    model = vehicleAiSetup_t::encounter_t::encounter_t(this: v5);
  else
    model = nullptr;
  ase.model = model;
  if ( model->objects.size < 32 )
  {
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&model->objects, newsize: 32);
    model = ase.model;
  }
  if ( model->materials.size < 32 )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)model, newsize: 32);
  if ( ASE_GetToken(restOfLine: false) != 0 )
  {
    while ( 1 )
    {
      v7 = "*3DSMAX_ASCIIEXPORT";
      token = ase.token;
      do
      {
        v9 = (unsigned __int8)*token;
        v11 = v9 == 0;
        v10 = v9 - *(unsigned __int8 *)v7;
        if ( v11 )
          break;
        ++token;
        ++v7;
      }
      while ( v10 == 0 );
      if ( v10 == 0 )
        goto LABEL_52;
      v12 = "*COMMENT";
      v13 = ase.token;
      do
      {
        v14 = (unsigned __int8)*v13;
        v11 = v14 == 0;
        v15 = v14 - *(unsigned __int8 *)v12;
        if ( v11 )
          break;
        ++v13;
        ++v12;
      }
      while ( v15 == 0 );
      if ( v15 == 0 )
      {
LABEL_52:
        ASE_GetToken(restOfLine: true);
        goto LABEL_53;
      }
      v16 = "*SCENE";
      v17 = ase.token;
      do
      {
        v18 = (unsigned __int8)*v17;
        v11 = v18 == 0;
        v19 = v18 - *(unsigned __int8 *)v16;
        if ( v11 )
          break;
        ++v17;
        ++v16;
      }
      while ( v19 == 0 );
      if ( v19 == 0 )
        goto LABEL_37;
      v20 = "*GROUP";
      v21 = ase.token;
      do
      {
        v22 = (unsigned __int8)*v21;
        v11 = v22 == 0;
        v23 = v22 - *(unsigned __int8 *)v20;
        if ( v11 )
          break;
        ++v21;
        ++v20;
      }
      while ( v23 == 0 );
      if ( v23 != 0 )
        break;
      ASE_GetToken(restOfLine: false);
      ASE_ParseBracedBlock(parser: ASE_KeyGROUP);
LABEL_53:
      if ( ASE_GetToken(restOfLine: false) == 0 )
        return ase.model;
    }
    v24 = "*SHAPEOBJECT";
    v25 = ase.token;
    do
    {
      v26 = (unsigned __int8)*v25;
      v11 = v26 == 0;
      v27 = v26 - *(unsigned __int8 *)v24;
      if ( v11 )
        break;
      ++v25;
      ++v24;
    }
    while ( v27 == 0 );
    if ( v27 != 0 )
    {
      v28 = "*CAMERAOBJECT";
      v29 = ase.token;
      do
      {
        v30 = (unsigned __int8)*v29;
        v11 = v30 == 0;
        v31 = v30 - *(unsigned __int8 *)v28;
        if ( v11 )
          break;
        ++v29;
        ++v28;
      }
      while ( v31 == 0 );
      if ( v31 != 0 )
      {
        v32 = "*MATERIAL_LIST";
        v33 = ase.token;
        do
        {
          v34 = (unsigned __int8)*v33;
          v11 = v34 == 0;
          v35 = v34 - *(unsigned __int8 *)v32;
          if ( v11 )
            break;
          ++v33;
          ++v32;
        }
        while ( v35 == 0 );
        if ( v35 != 0 )
        {
          v36 = "*GEOMOBJECT";
          v37 = ase.token;
          do
          {
            v38 = (unsigned __int8)*v37;
            v11 = v38 == 0;
            v39 = v38 - *(unsigned __int8 *)v36;
            if ( v11 )
              break;
            ++v37;
            ++v36;
          }
          while ( v39 == 0 );
          if ( v39 != 0 )
          {
            if ( ase.token[0] != 0 )
              idLib::Printf(fmt: "Unknown token '%s'\n", ase.token);
          }
          else
          {
            ASE_ParseGeomObject();
          }
        }
        else
        {
          if ( ase.verbose )
            idLib::Printf(fmt: "MATERIAL_LIST\n");
          ASE_ParseBracedBlock(parser: ASE_KeyMATERIAL_LIST);
        }
        goto LABEL_53;
      }
    }
LABEL_37:
    ASE_SkipEnclosingBraces();
    goto LABEL_53;
  }
  return ase.model;
}


// ========================================================================
// __unwind$223201
// EA  : 0x8287C410
// RVA : 0x0087C410
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall _unwind_223201(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 192 + 80), tag: a2);
}


// ========================================================================
// ?ASE_Load@@YAPAVidASEModel@@PBD@Z
// EA  : 0x8287C438
// RVA : 0x0087C438
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

idASEModel *__fastcall ASE_Load(const char *fileName)
{
  idASEModel *result; // r3
  idASEModel *v2; // r31
  idASEModel *v3; // [sp+50h] [-20h] BYREF

  fileSystem->ReadFile(this: fileSystem, a2: fileName, a3: (void **)&v3, a4: nullptr);
  result = v3;
  if ( v3 != nullptr )
  {
    v2 = ASE_Parse(buffer: (const char *)v3, verbose: false);
    fileSystem->FreeFile(this: fileSystem, a2: v3);
    return v2;
  }
  return result;
}


// ========================================================================
// ?ASE_Free@@YAXPAVidASEModel@@@Z
// EA  : 0x8287C628
// RVA : 0x0087C628
// PDB : w:\tech5\engine\models\static\staticmodel_ase.cpp
// ========================================================================

void __fastcall ASE_Free(idASEModel *aseModel)
{
  if ( aseModel != nullptr )
  {
    idASEModel::~idASEModel(this: aseModel);
    idMem::Free(this: &mem, ptr: aseModel, align: ALIGN_16);
  }
}

