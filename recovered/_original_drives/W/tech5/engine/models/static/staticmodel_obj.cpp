
// ========================================================================
// ParseFaceLine
// EA  : 0x828847D8
// RVA : 0x008847D8
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

int __fastcall ParseFaceLine(const char *line2, int (*attributes)[3])
{
  char *data; // r10
  signed int v4; // r29
  int v5; // r11
  signed int i; // ctr
  int v7; // r27
  int *v8; // r29
  unsigned int intvalue; // r11
  unsigned int v10; // r11
  unsigned int v11; // r11
  idToken v13; // [sp+50h] [-140h] BYREF
  idStr v14; // [sp+A0h] [-F0h] BYREF
  idLexer v15; // [sp+C0h] [-D0h] BYREF

  idStr::idStr(this: &v14, text: line2);
  data = v14.data;
  v4 = 0;
  if ( *v14.data != 0 )
  {
    do
      ++v4;
    while ( v14.data[v4] != 0 );
  }
  v5 = 0;
  if ( v4 > 0 )
  {
    for ( i = v4; i != 0; --i )
    {
      if ( data[v5] == 47 )
      {
        data[v5] = 92;
        data = v14.data;
      }
      ++v5;
    }
  }
  idLexer::idLexer(this: &v15, flags_: 4);
  idLexer::LoadMemory(this: &v15, ptr: v14.data, length_: v4, name: "obj face line");
  v13.len = 0;
  v13.baseBuffer[0] = 0;
  v13.allocedAndFlag = 20;
  v7 = 0;
  v13.data = v13.baseBuffer;
  v13.intvalue = 0;
  v13.floatvalue = -3.4028235e38;
  memset(&v13.whiteSpaceStart_p, 0, 12);
  if ( !idLexer::ReadToken(this: &v15, token: &v13) )
    goto LABEL_59;
  v8 = &(*attributes)[2];
  while ( 1 )
  {
    if ( v7 >= 8 )
    {
      idLib::Printf(fmt: "exceeded MAX_FACE_VERTS\n");
      idStr::FreeData(this: &v13);
      idLexer::~idLexer(this: &v15);
      idStr::FreeData(this: &v14);
      return -1;
    }
    if ( idStr::Cmp(s1: v13.data, s2: "-") != 0 )
    {
      if ( v13.type == 3 )
      {
        if ( (v13.subtype & 0x10000) == 0 )
          idToken::NumberValue(this: &v13);
        intvalue = v13.intvalue;
      }
      else
      {
        intvalue = 0;
      }
    }
    else
    {
      idLexer::ReadToken(this: &v15, token: &v13);
      if ( v13.type == 3 )
      {
        if ( (v13.subtype & 0x10000) == 0 )
          idToken::NumberValue(this: &v13);
        intvalue = -v13.intvalue;
      }
      else
      {
        intvalue = 0;
      }
    }
    *(v8 - 2) = intvalue;
    if ( idLexer::ReadToken(this: &v15, token: &v13) )
      break;
    *(v8 - 1) = 0;
    *v8 = 0;
LABEL_55:
    idStr::FreeData(this: &v13);
    v13.floatvalue = -3.4028235e38;
    v13.allocedAndFlag = 20;
    ++v7;
    v13.data = v13.baseBuffer;
    v8 += 3;
    v13.len = 0;
    v13.baseBuffer[0] = 0;
    v13.intvalue = 0;
    memset(&v13.whiteSpaceStart_p, 0, 12);
    if ( !idLexer::ReadToken(this: &v15, token: &v13) )
      goto LABEL_59;
  }
  if ( idStr::Cmp(s1: v13.data, s2: "\\") != 0 )
  {
    *(v8 - 1) = 0;
    *v8 = 0;
    idLexer::UnreadToken(this: &v15);
    goto LABEL_55;
  }
  idLexer::ReadToken(this: &v15, token: &v13);
  if ( idStr::Cmp(s1: v13.data, s2: "\\") != 0 )
  {
    if ( idStr::Cmp(s1: v13.data, s2: "-") != 0 )
    {
      if ( v13.type == 3 )
      {
        if ( (v13.subtype & 0x10000) == 0 )
          idToken::NumberValue(this: &v13);
        v10 = v13.intvalue;
      }
      else
      {
        v10 = 0;
      }
    }
    else
    {
      idLexer::ReadToken(this: &v15, token: &v13);
      if ( v13.type == 3 )
      {
        if ( (v13.subtype & 0x10000) == 0 )
          idToken::NumberValue(this: &v13);
        v10 = -v13.intvalue;
      }
      else
      {
        v10 = 0;
      }
    }
    *(v8 - 1) = v10;
    idLexer::ReadToken(this: &v15, token: &v13);
  }
  else
  {
    *(v8 - 1) = 0;
  }
  if ( idStr::Cmp(s1: v13.data, s2: "\\") == 0 )
  {
    idLexer::ReadToken(this: &v15, token: &v13);
    if ( idStr::Cmp(s1: v13.data, s2: "-") != 0 )
    {
      if ( v13.type == 3 )
      {
        if ( (v13.subtype & 0x10000) == 0 )
          idToken::NumberValue(this: &v13);
        v11 = v13.intvalue;
      }
      else
      {
        v11 = 0;
      }
    }
    else
    {
      idLexer::ReadToken(this: &v15, token: &v13);
      if ( v13.type == 3 )
      {
        if ( (v13.subtype & 0x10000) == 0 )
          idToken::NumberValue(this: &v13);
        v11 = -v13.intvalue;
      }
      else
      {
        v11 = 0;
      }
    }
    *v8 = v11;
    goto LABEL_55;
  }
  *v8 = 0;
  if ( !idLexer::EndOfFile(this: &v15) )
  {
    idLexer::UnreadToken(this: &v15);
    goto LABEL_55;
  }
  ++v7;
LABEL_59:
  idStr::FreeData(this: &v13);
  idLexer::~idLexer(this: &v15);
  idStr::FreeData(this: &v14);
  return v7;
}


// ========================================================================
// __unwind$233650
// EA  : 0x82884C08
// RVA : 0x00884C08
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_233650()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 160));
}


// ========================================================================
// __unwind$233651
// EA  : 0x82884C30
// RVA : 0x00884C30
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_233651()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 400 + 192));
}


// ========================================================================
// __unwind$233652
// EA  : 0x82884C58
// RVA : 0x00884C58
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_233652()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 80));
}


// ========================================================================
// ?TestParseFaceLine_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82884C80
// RVA : 0x00884C80
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void __fastcall TestParseFaceLine_f(const idCmdArgs *args)
{
  const char *v1; // r31
  int v2; // r25
  int v3; // r30
  int *v4; // r31
  int v5; // r4
  int v6; // r5
  _DWORD v7[11]; // [sp+50h] [-D0h] BYREF
  int v8[41]; // [sp+7Ch] [-A4h] BYREF

  v1 = "1 2 3";
  v7[0] = "1 2 3";
  v7[1] = "1/2 3/4 5/6";
  v7[2] = "1//2 4//6 7//9";
  v7[3] = "1/2/3 4/5/6 7/8/9";
  v7[4] = "1/2/3 4/5/6 7/8/9 10/11/12";
  v7[5] = " 1 2 3";
  v2 = 0;
  v7[8] = 0;
  v7[6] = "1 2 3 ";
  v7[7] = "1//2 4//6 7//9 ";
  do
  {
    idLib::Printf(fmt: "Source: %s\n", v1);
    v3 = ParseFaceLine(line2: v1, attributes: (int (*)[3])&v8[1]);
    idLib::Printf(fmt: "Parsed: ");
    if ( v3 > 0 )
    {
      v4 = v8;
      do
      {
        v5 = v4[1];
        v6 = v4[2];
        v4 += 3;
        idLib::Printf(fmt: "%i/%i/%i ", v5, v6, *v4);
        --v3;
      }
      while ( v3 != 0 );
    }
    idLib::Printf(fmt: "\n");
    v1 = (const char *)v7[++v2];
  }
  while ( v1 != nullptr );
}


// ========================================================================
// ?Save@idOBJModel@@QAA_NPBD@Z
// EA  : 0x82884D98
// RVA : 0x00884D98
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

int __fastcall idOBJModel::Save(idOBJModel *this, const char *fileName)
{
  int v5; // r28
  int num; // r29
  int v7; // r17
  int v8; // r30
  int v9; // r15
  idFile_vtbl *v10; // r10
  int v11; // r18
  idOBJMesh *list; // r11
  int v13; // r29
  int v14; // r27
  int v15; // r26
  idStr *p_materialName; // r25
  int v17; // r23
  char *data; // r4
  int v19; // r5
  int v20; // ctr
  char *v21; // r11
  char *v22; // r9
  int v23; // r6
  int v24; // r9
  int *v25; // r9
  bool v26; // zf
  int v27; // r7
  int v28; // r9
  int *v29; // r9
  int v30; // r8
  int v31; // r9
  int *v32; // r9
  int v33; // r6
  int v34; // r9
  int *v35; // r9
  int v36; // r7
  int v37; // r9
  int *v38; // r9
  int v39; // r8
  int v40; // r9
  int *v41; // r9
  int *v42; // r10
  int v43; // r9
  int *v44; // r11
  int v45; // r10
  size_t len; // r30
  int v47; // r30
  int v48; // r29
  int v49; // r30
  int v50; // r29
  int v51; // r30
  int v52; // r29
  int v53; // r29
  int i; // r30
  char *v55; // r11
  idParsedMtl *v56; // r30
  idFileLocal v57; // [sp+70h] [-170h] BYREF
  int v58; // [sp+74h] [-16Ch] BYREF
  int v59; // [sp+78h] [-168h] BYREF
  int v60; // [sp+7Ch] [-164h] BYREF
  idFileLocal v61; // [sp+80h] [-160h] BYREF
  unsigned int v62; // [sp+84h] [-15Ch]
  int v63; // [sp+88h] [-158h]
  const char *v64; // [sp+8Ch] [-154h]
  const char *v65; // [sp+90h] [-150h]
  const char *v66; // [sp+94h] [-14Ch]
  const char *v67; // [sp+98h] [-148h]
  int v68; // [sp+9Ch] [-144h]
  idStr v69; // [sp+A0h] [-140h] BYREF
  idStr v70; // [sp+C0h] [-120h] BYREF
  idStr v71; // [sp+E0h] [-100h] BYREF
  idStr v72; // [sp+100h] [-E0h] BYREF
  idStr v73; // [sp+120h] [-C0h] BYREF

  v57.file = (idFile *)((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
  if ( v57.file != nullptr )
  {
    idStr::idStr(this: &v72, text: fileName);
    idStr::StripFileExtension(this: &v72);
    v5 = 0;
    v69.len = 0;
    v69.data = v69.baseBuffer;
    v69.allocedAndFlag = 20;
    v69.baseBuffer[0] = 0;
    idStr::ExtractFileBase(this: &v72, dest: &v69);
    idStr::SetFileExtension(this: &v72, extension: ".mtl");
    v61.file = fileSystem->OpenFileWrite(this: fileSystem, a2: v72.data, a3: 0);
    if ( v61.file != nullptr )
    {
      num = this->materials.num;
      v7 = 0;
      v8 = this->meshes.num;
      v9 = 0;
      v10 = v57.file->__vftable;
      v11 = 0;
      v68 = num;
      v10->Printf(this: v57.file, a2: "# id Software OBJ file\n# %i meshes\n\nmtllib %s.mtl\n", v8, v69.data);
      idStr::idStr(this: &v71, text: &byte_8200D768);
      if ( v8 > 0 )
      {
        v63 = v8;
        v62 = 0;
        v66 = "\nusemtl %s\n";
        v65 = "\n# %i normals\n";
        v64 = "\n# %i texture coords\n";
        v67 = "\n# %i vertices\n";
        do
        {
          list = this->meshes.list;
          v13 = 0;
          v14 = 0;
          v15 = 0;
          v60 = 0;
          p_materialName = &list[v62 / 0x54].materialName;
          v59 = 0;
          v58 = 0;
          v17 = list[v62 / 0x54].f.num;
          if ( v17 > 0 )
          {
            data = p_materialName[2].data;
            v19 = 0;
            v20 = list[v62 / 0x54].f.num;
            do
            {
              v21 = &data[v19];
              v22 = &data[v19];
              if ( v13 >= *(_DWORD *)&data[v19] )
                v22 = (char *)&v60;
              v23 = *(_DWORD *)v22;
              v24 = *((_DWORD *)v21 + 3);
              v60 = v23;
              v26 = v14 < v24;
              v25 = (int *)(v21 + 12);
              if ( !v26 )
                v25 = &v59;
              v27 = *v25;
              v28 = *((_DWORD *)v21 + 6);
              v59 = v27;
              v26 = v15 < v28;
              v29 = (int *)(v21 + 24);
              if ( !v26 )
                v29 = &v58;
              v30 = *v29;
              v31 = *((_DWORD *)v21 + 1);
              v58 = v30;
              v26 = v23 < v31;
              v32 = (int *)(v21 + 4);
              if ( !v26 )
                v32 = &v60;
              v33 = *v32;
              v34 = *((_DWORD *)v21 + 4);
              v60 = v33;
              v26 = v27 < v34;
              v35 = (int *)(v21 + 16);
              if ( !v26 )
                v35 = &v59;
              v36 = *v35;
              v37 = *((_DWORD *)v21 + 7);
              v59 = v36;
              v26 = v30 < v37;
              v38 = (int *)(v21 + 28);
              if ( !v26 )
                v38 = &v58;
              v39 = *v38;
              v40 = *((_DWORD *)v21 + 2);
              v58 = v39;
              v26 = v33 < v40;
              v41 = (int *)(v21 + 8);
              if ( !v26 )
                v41 = &v60;
              v13 = *v41;
              v42 = (int *)(v21 + 20);
              v43 = *((_DWORD *)v21 + 5);
              v60 = v13;
              if ( v36 >= v43 )
                v42 = &v59;
              v44 = (int *)(v21 + 32);
              v14 = *v42;
              v45 = *v44;
              v59 = v14;
              if ( v39 >= v45 )
                v44 = &v58;
              v15 = *v44;
              v19 += 36;
              v58 = *v44;
              --v20;
            }
            while ( v20 != 0 );
          }
          if ( p_materialName[1].len <= 0 )
          {
            v70.len = 0;
            v70.baseBuffer[0] = 0;
            v70.data = v70.baseBuffer;
            v70.allocedAndFlag = 20;
            idStr::ExtractFileBase(this: p_materialName, dest: &v70);
            v57.file->Printf(this: v57.file, a2: "\ng %s\n", v70.data);
            idStr::FreeData(this: &v70);
          }
          else if ( idStr::Cmp(s1: p_materialName[1].data, s2: v71.data) != 0 )
          {
            len = p_materialName[1].len;
            idStr::EnsureAlloced(this: &v71, amount: len + 1, keepold: false, geometricGrowth: false);
            memcpy(Dst: v71.data, Src: p_materialName[1].data, Size: len);
            v71.data[len] = 0;
            v71.len = len;
            v57.file->Printf(this: v57.file, a2: "\ng %s\n", p_materialName[1].data);
          }
          if ( v13 > v7 )
          {
            v47 = v13 - v7;
            v57.file->Printf(this: v57.file, a2: v67, v13 - v7);
            v48 = v7;
            v7 += v47;
            do
            {
              v57.file->Printf(
                this: v57.file,
                a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(this->v.list[v48].x)),
                COERCE_UNSIGNED_INT64(this->v.list[v48].x),
                COERCE_UNSIGNED_INT64(this->v.list[v48].z),
                COERCE_UNSIGNED_INT64(-this->v.list[v48].y));
              --v47;
              ++v48;
            }
            while ( v47 != 0 );
          }
          if ( v14 > v9 )
          {
            v49 = v14 - v9;
            v57.file->Printf(this: v57.file, a2: v64, v14 - v9);
            v50 = v9;
            v9 = v14;
            do
            {
              v57.file->Printf(
                this: v57.file,
                a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(this->vt.list[v50].x)),
                COERCE_UNSIGNED_INT64(this->vt.list[v50].x),
                COERCE_UNSIGNED_INT64((float)((float)1.0 - this->vt.list[v50].y)));
              --v49;
              ++v50;
            }
            while ( v49 != 0 );
          }
          if ( v15 > v11 )
          {
            v51 = v15 - v11;
            v57.file->Printf(this: v57.file, a2: v65, v15 - v11);
            v52 = v11;
            v11 = v15;
            do
            {
              v57.file->Printf(
                this: v57.file,
                a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(this->vn.list[v52].x)),
                COERCE_UNSIGNED_INT64(this->vn.list[v52].x),
                HIDWORD(COERCE_UNSIGNED_INT64(-this->vn.list[v52].y)),
                COERCE_UNSIGNED_INT64(-this->vn.list[v52].y));
              --v51;
              ++v52;
            }
            while ( v51 != 0 );
          }
          v57.file->Printf(this: v57.file, a2: v66, p_materialName->data);
          v57.file->Printf(this: v57.file, a2: "\n# %i faces\n", v17);
          if ( v17 > 0 )
          {
            v53 = 0;
            for ( i = v17; i != 0; --i )
            {
              v55 = &p_materialName[2].data[v53];
              v57.file->Printf(
                this: v57.file,
                a2: "f %i/%i/%i %i/%i/%i %i/%i/%i\n",
                *(_DWORD *)v55,
                *((_DWORD *)v55 + 3),
                *((_DWORD *)v55 + 6),
                *((_DWORD *)v55 + 1),
                *((_DWORD *)v55 + 4),
                *((_DWORD *)v55 + 7));
              v53 += 36;
            }
          }
          --v63;
          v62 += 84;
        }
        while ( v63 != 0 );
        num = v68;
      }
      v61.file->Printf(this: v61.file, a2: "# id Software MTL file\n# %i materials\n", num);
      if ( num > 0 )
      {
        do
        {
          v56 = &this->materials.list[v5];
          idStr::idStr(this: &v73, text: v56->map_Kd.data);
          idStr::BackSlashesToSlashes(this: &v73);
          idStr::DefaultFileExtension(this: &v73, extension: "tga");
          v61.file->Printf(
            this: v61.file,
            a2: "\n\nnewmtl %s\n\tNs 0\n\td 1\n\tillum 2\n\tKd 0 0 0 \n\tKs 0.22 0.22 0.22 \n\tKa 0 0 0 \n\tmap_Kd %s\n",
            v56->mtlName.data,
            v73.data);
          idStr::FreeData(this: &v73);
          --num;
          ++v5;
        }
        while ( num != 0 );
      }
      idStr::FreeData(this: &v71);
      idFileLocal::~idFileLocal(this: &v61);
      idStr::FreeData(this: &v69);
      idStr::FreeData(this: &v72);
      idFileLocal::~idFileLocal(this: &v57);
      return 1;
    }
    else
    {
      idFileLocal::~idFileLocal(this: &v61);
      idStr::FreeData(this: &v69);
      idStr::FreeData(this: &v72);
      idFileLocal::~idFileLocal(this: &v57);
      return 0;
    }
  }
  else
  {
    idFileLocal::~idFileLocal(this: &v57);
    return 0;
  }
}


// ========================================================================
// __unwind$233919
// EA  : 0x8288549C
// RVA : 0x0088549C
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_233919()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 480 + 112));
}


// ========================================================================
// __unwind$233920
// EA  : 0x828854C4
// RVA : 0x008854C4
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_233920()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 256));
}


// ========================================================================
// __unwind$233921
// EA  : 0x828854EC
// RVA : 0x008854EC
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_233921()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 160));
}


// ========================================================================
// __unwind$233922
// EA  : 0x82885514
// RVA : 0x00885514
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_233922()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 480 + 128));
}


// ========================================================================
// __unwind$233923
// EA  : 0x8288553C
// RVA : 0x0088553C
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_233923()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 224));
}


// ========================================================================
// __unwind$233924
// EA  : 0x82885564
// RVA : 0x00885564
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_233924()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 192));
}


// ========================================================================
// __unwind$233925
// EA  : 0x8288558C
// RVA : 0x0088558C
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_233925()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 288));
}


// ========================================================================
// ?OBJ_Parse@@YAXPAVidOBJModel@@AAVidLexer@@ABVidStr@@@Z
// EA  : 0x828882C0
// RVA : 0x008882C0
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void __fastcall OBJ_Parse(idOBJModel *model, idLexer *src, const idStr *path)
{
  idLexer *v4; // r24
  idOBJMesh *v5; // r17
  idVec3 *v6; // r3
  idVec2 *v7; // r3
  idVec3 *v8; // r3
  int v9; // r3
  int v10; // r27
  char **p_data; // r30
  int i; // r28
  int v13; // r29
  bool v14; // cr56
  int v15; // r10
  bool v16; // cr56
  int v17; // r10
  int v18; // r28
  int allocedAndFlag; // r27
  char *data; // r26
  int len; // r25
  int *p_allocedAndFlag; // r30
  int size; // r10
  int num; // r11
  idOBJFace *list; // r9
  int *v; // r11
  int v27; // r9
  int v28; // r8
  int v29; // r7
  int v30; // r6
  int v31; // r5
  int v32; // r10
  __int64 v33; // r10
  __int64 v34; // r8
  __int64 v35; // r6
  va *v36; // r3
  char *v37; // r11
  int v38; // r10
  int v39; // r10
  char *v40; // r30
  int j; // r29
  int v42; // r11
  char v43; // r9
  int v44; // r11
  char v45; // r10
  int v46; // r11
  char v47; // r9
  int v48; // r11
  char v49; // r10
  int v50; // r11
  char v51; // r9
  int v52; // r11
  char v53; // r10
  int v54; // r11
  char v55; // r10
  int v56; // r11
  char v57; // r11
  bool v58; // zf
  size_t v59; // r30
  int v60; // r30
  int v61; // r29
  char v62; // r11
  int v63; // r10
  int v64; // r9
  bool *p_hasTexCoords; // r8
  bool v66; // r6
  int v67; // r10
  int v68; // r9
  int v69; // r8
  int v70; // r7
  int v71; // r6
  int v72; // r5
  int v73; // r4
  int v74; // r3
  int v75; // [sp+8h] [-1448h]
  int v76; // [sp+Ch] [-1444h]
  int v77; // [sp+10h] [-1440h]
  int v78; // [sp+14h] [-143Ch]
  int v79; // [sp+18h] [-1438h]
  int v80; // [sp+1Ch] [-1434h]
  const char *v81; // [sp+50h] [-1400h] BYREF
  char *v82; // [sp+54h] [-13FCh] BYREF
  float v83; // [sp+58h] [-13F8h] BYREF
  float v84; // [sp+5Ch] [-13F4h] BYREF
  float v85; // [sp+60h] [-13F0h] BYREF
  const char *v86; // [sp+64h] [-13ECh]
  const char *v87; // [sp+68h] [-13E8h]
  const char *v88; // [sp+6Ch] [-13E4h]
  const char *v89; // [sp+70h] [-13E0h]
  const char *v90; // [sp+74h] [-13DCh]
  const char *v91; // [sp+78h] [-13D8h]
  const char *v92; // [sp+7Ch] [-13D4h]
  const char *v93; // [sp+80h] [-13D0h]
  const char *v94; // [sp+84h] [-13CCh]
  const char *v95; // [sp+88h] [-13C8h]
  const char *v96; // [sp+8Ch] [-13C4h]
  const char *v97; // [sp+90h] [-13C0h]
  const char *v98; // [sp+94h] [-13BCh]
  idMem *v99; // [sp+98h] [-13B8h]
  const char *v100; // [sp+9Ch] [-13B4h]
  const char *v101; // [sp+A0h] [-13B0h]
  const char *v102; // [sp+A4h] [-13ACh]
  idToken v103; // [sp+B0h] [-13A0h] BYREF
  idStr v104; // [sp+100h] [-1350h] BYREF
  idStr v105; // [sp+120h] [-1330h] BYREF
  idStr v106; // [sp+140h] [-1310h] BYREF
  idStr v107; // [sp+160h] [-12F0h] BYREF
  idToken v108; // [sp+180h] [-12D0h] BYREF
  idStr v109; // [sp+1D0h] [-1280h] BYREF
  int v110; // [sp+204h] [-124Ch]
  float v111; // [sp+208h] [-1248h]
  int v112; // [sp+20Ch] [-1244h]
  int v113; // [sp+210h] [-1240h]
  int v114; // [sp+214h] [-123Ch]
  idStr v115[4]; // [sp+220h] [-1230h] BYREF
  _BYTE v116[256]; // [sp+2A0h] [-11B0h] BYREF
  va v117; // [sp+3A0h] [-10B0h] BYREF

  v103.len = 0;
  v103.allocedAndFlag = 20;
  v4 = src;
  v103.floatvalue = -3.4028235e38;
  v103.data = v103.baseBuffer;
  v103.baseBuffer[0] = 0;
  v103.intvalue = 0;
  memset(&v103.whiteSpaceStart_p, 0, 12);
  v111 = -3.4028235e38;
  v109.allocedAndFlag = 20;
  v109.data = v109.baseBuffer;
  v109.len = 0;
  v109.baseBuffer[0] = 0;
  v110 = 0;
  v112 = 0;
  v113 = 0;
  v114 = 0;
  v5 = idList<idOBJMesh,5>::Alloc(this: &model->meshes);
  v5->hasNormals = true;
  v5->hasTexCoords = true;
  if ( idLexer::ReadToken(this: v4, token: &v103) )
  {
    v81 = "%s/%s";
    v82 = "Bad vertex index";
    v4 = src;
    v98 = "f";
    v89 = "%s: Unknown token %s";
    v87 = "MRGB";
    v96 = "#";
    v86 = "%s: Missing token after usemtl";
    v88 = "%s: Unknown v token";
    v91 = "vn";
    v93 = "vt";
    v101 = "usemtl";
    v97 = "%s: Missing token after mtllib";
    v99 = &mem;
    v94 = "%s: Could not parse %s";
    v95 = "%s: Could not find %s";
    v102 = "mtllib";
    v92 = "s";
    v100 = "g";
    v90 = "Face with < 3 verts";
    while ( 1 )
    {
      if ( *v103.data == 118 )
      {
        v83 = 0.0;
        v84 = 0.0;
        v104.allocedAndFlag = 20;
        v85 = 0.0;
        v104.data = v104.baseBuffer;
        v104.len = 0;
        v104.baseBuffer[0] = 0;
        idLexer::ParseRestOfLine(this: src, out: &v104);
        ignoredReturnValue = sscanf(string: v104.data, format: "%f %f %f", &v83, &v84, &v85);
        if ( idStr::Cmp(s1: v103.data, s2: "v") != 0 )
        {
          if ( idStr::Cmp(s1: v103.data, s2: v93) != 0 )
          {
            if ( idStr::Cmp(s1: v103.data, s2: v91) != 0 )
            {
              idLib::Warning(fmt: v88, src->filename.data);
            }
            else
            {
              v8 = idList<idVec3,5>::Alloc(this: &model->vn);
              v8->x = v83;
              v8->y = -v85;
              v8->z = v84;
            }
          }
          else
          {
            v7 = idList<idVec2,5>::Alloc(this: &model->vt);
            v7->x = v83;
            v7->y = (float)1.0 - v84;
          }
        }
        else
        {
          v6 = idList<idVec3,5>::Alloc(this: &model->v);
          v6->x = v83;
          v6->y = -v85;
          v6->z = v84;
        }
        idStr::FreeData(this: &v104);
        goto LABEL_144;
      }
      if ( idStr::Cmp(s1: v103.data, s2: v98) == 0 )
      {
        v105.allocedAndFlag = 20;
        v105.len = 0;
        v105.data = v105.baseBuffer;
        v105.baseBuffer[0] = 0;
        idLexer::ParseRestOfLine(this: src, out: &v105);
        v9 = ParseFaceLine(line2: v105.data, attributes: (int (*)[3])&v115[1]);
        v10 = v9;
        if ( v9 > 0 )
        {
          p_data = &v115[1].data;
          for ( i = v9; i != 0; --i )
          {
            v13 = (int)*(p_data - 1);
            v14 = v13 < 0;
            if ( v13 == 0 )
            {
              idLexer::Error(this: src, str: "Bad vertex index");
              v14 = false;
            }
            if ( v14 )
              *(p_data - 1) = (char *)(v13 + model->v.num + 1);
            v15 = (int)*p_data;
            v16 = (int)*p_data < 0;
            if ( *p_data != nullptr )
            {
              v5->hasTexCoords = true;
              if ( v16 )
                *p_data = (char *)(v15 + model->vt.num + 1);
            }
            else
            {
              v5->hasTexCoords = false;
            }
            v17 = (int)p_data[1];
            if ( v17 != 0 )
            {
              v5->hasNormals = true;
              if ( v17 < 0 )
                p_data[1] = (char *)(v17 + model->vn.num + 1);
            }
            else
            {
              v5->hasNormals = false;
            }
            p_data += 3;
          }
        }
        if ( v10 >= 3 )
        {
          v18 = v10 - 2;
          allocedAndFlag = v115[1].allocedAndFlag;
          data = v115[1].data;
          len = v115[1].len;
          p_allocedAndFlag = &v115[1].allocedAndFlag;
          do
          {
            idList<idOBJFace,5>::PreAllocateWithGranularity(this: &v5->f, newSize: v5->f.num + 1);
            size = v5->f.size;
            num = v5->f.num;
            list = v5->f.list;
            if ( num >= size )
            {
              v = list[size - 1].v;
            }
            else
            {
              v5->f.num = num + 1;
              v = list[num].v;
            }
            v27 = p_allocedAndFlag[4];
            --v18;
            v28 = p_allocedAndFlag[5];
            v29 = p_allocedAndFlag[6];
            v30 = p_allocedAndFlag[1];
            v31 = p_allocedAndFlag[2];
            p_allocedAndFlag += 3;
            v32 = *p_allocedAndFlag;
            *v = len;
            v[3] = (int)data;
            v[6] = allocedAndFlag;
            v[1] = v27;
            v[4] = v28;
            v[7] = v29;
            v[2] = v30;
            v[5] = v31;
            v[8] = v32;
          }
          while ( v18 != 0 );
        }
        else
        {
          idLexer::Warning(this: src, str: v90);
        }
        idStr::FreeData(this: &v105);
        goto LABEL_144;
      }
      if ( idStr::Cmp(s1: v103.data, s2: v100) == 0 || idStr::Cmp(s1: v103.data, s2: v92) == 0 )
        break;
      if ( idStr::Cmp(s1: v103.data, s2: v102) != 0 )
      {
        if ( idStr::Cmp(s1: v103.data, s2: v101) == 0 )
        {
          if ( v5->f.num > 0 )
          {
            v5 = idList<idOBJMesh,5>::Alloc(this: &model->meshes);
            v5->hasNormals = true;
            v5->hasTexCoords = true;
          }
          if ( idLexer::ParseRestOfLine(this: src, out: &v103) != nullptr )
            idStr::operator=(this: &v5->materialName, text: &v103);
          else
            idLib::Warning(fmt: v86, src->filename.data);
          goto LABEL_144;
        }
        if ( idStr::Cmp(s1: v103.data, s2: v96) == 0 )
        {
          if ( idLexer::PeekTokenString(this: src, string: v87) )
          {
            v108.floatvalue = -3.4028235e38;
            v108.allocedAndFlag = 20;
            v108.data = v108.baseBuffer;
            v108.len = 0;
            v108.baseBuffer[0] = 0;
            v108.intvalue = 0;
            memset(&v108.whiteSpaceStart_p, 0, 12);
            idLexer::ReadToken(this: src, token: &v108);
            v106.allocedAndFlag = 20;
            v106.data = v106.baseBuffer;
            v106.len = 0;
            v106.baseBuffer[0] = 0;
            idLexer::ParseCompleteLine(this: src, out: &v106);
            v37 = v106.data;
            if ( *v106.data == 32 )
              v37 = v106.data + 1;
            v38 = 0;
            if ( *v37 != 0 )
            {
              do
                ++v38;
              while ( v37[v38] != 0 );
            }
            v39 = v38 / 8;
            if ( v39 > 0 )
            {
              v40 = v37 + 2;
              for ( j = v39; j != 0; --j )
              {
                v42 = *(v40 - 2);
                if ( v42 < 48 || v42 > 57 )
                {
                  if ( v42 < 97 || v42 > 102 )
                  {
                    if ( v42 < 65 || (v43 = v42 - 55, v42 > 70) )
                      v43 = 0;
                  }
                  else
                  {
                    v43 = v42 - 87;
                  }
                }
                else
                {
                  v43 = v42 - 48;
                }
                v44 = *(v40 - 1);
                if ( v44 < 48 || v44 > 57 )
                {
                  if ( v44 < 97 || v44 > 102 )
                  {
                    if ( v44 < 65 || (v45 = v44 - 55, v44 > 70) )
                      v45 = 0;
                  }
                  else
                  {
                    v45 = v44 - 87;
                  }
                }
                else
                {
                  v45 = v44 - 48;
                }
                v46 = *v40;
                HIBYTE(v81) = 16 * v43 + v45;
                if ( v46 < 48 || v46 > 57 )
                {
                  if ( v46 < 97 || v46 > 102 )
                  {
                    if ( v46 < 65 || (v47 = v46 - 55, v46 > 70) )
                      v47 = 0;
                  }
                  else
                  {
                    v47 = v46 - 87;
                  }
                }
                else
                {
                  v47 = v46 - 48;
                }
                v48 = v40[1];
                if ( v48 < 48 || v48 > 57 )
                {
                  if ( v48 < 97 || v48 > 102 )
                  {
                    if ( v48 < 65 || (v49 = v48 - 55, v48 > 70) )
                      v49 = 0;
                  }
                  else
                  {
                    v49 = v48 - 87;
                  }
                }
                else
                {
                  v49 = v48 - 48;
                }
                v50 = v40[2];
                BYTE1(v81) = 16 * v47 + v49;
                if ( v50 < 48 || v50 > 57 )
                {
                  if ( v50 < 97 || v50 > 102 )
                  {
                    if ( v50 < 65 || (v51 = v50 - 55, v50 > 70) )
                      v51 = 0;
                  }
                  else
                  {
                    v51 = v50 - 87;
                  }
                }
                else
                {
                  v51 = v50 - 48;
                }
                v52 = v40[3];
                if ( v52 < 48 || v52 > 57 )
                {
                  if ( v52 < 97 || v52 > 102 )
                  {
                    if ( v52 < 65 || (v53 = v52 - 55, v52 > 70) )
                      v53 = 0;
                  }
                  else
                  {
                    v53 = v52 - 87;
                  }
                }
                else
                {
                  v53 = v52 - 48;
                }
                v54 = v40[4];
                BYTE2(v81) = 16 * v51 + v53;
                if ( v54 < 48 || v54 > 57 )
                {
                  if ( v54 < 97 || v54 > 102 )
                  {
                    if ( v54 < 65 || (v55 = v54 - 55, v54 > 70) )
                      v55 = 0;
                  }
                  else
                  {
                    v55 = v54 - 87;
                  }
                }
                else
                {
                  v55 = v54 - 48;
                }
                v56 = v40[5];
                if ( v56 < 48 || v56 > 57 )
                {
                  if ( v56 < 97 || v56 > 102 )
                  {
                    if ( v56 < 65 || (v58 = v56 <= 70, v57 = v56 - 55, !v58) )
                      v57 = 0;
                  }
                  else
                  {
                    v57 = v56 - 87;
                  }
                }
                else
                {
                  v57 = v56 - 48;
                }
                LOBYTE(v81) = 16 * v55 + v57;
                idList<mrgb_t,5>::Append(this: &model->mrgb, obj: (const mrgb_t *)&v81);
                v40 += 8;
              }
            }
            idStr::FreeData(this: &v106);
            idStr::FreeData(this: &v108);
          }
          else
          {
            v107.allocedAndFlag = 20;
            v107.len = 0;
            v107.data = v107.baseBuffer;
            v107.baseBuffer[0] = 0;
            idLexer::ParseCompleteLine(this: src, out: &v107);
            idStr::FreeData(this: &v107);
          }
          goto LABEL_144;
        }
        idLib::Warning(fmt: v89, src->filename.data, v103.data);
        goto LABEL_143;
      }
      if ( idLexer::ParseRestOfLine(this: src, out: &v103) != nullptr )
      {
        if ( model->materials.num != 0 )
        {
          idLib::Error(fmt: "%s: multiple mtllib statements\n", src->filename.data);
          _LN413(a1: v74, a2: v73, a3: v72, a4: v71, a5: v70, a6: v69, a7: v68, a8: v67);
          return;
        }
        LODWORD(v35) = v103.data;
        HIDWORD(v35) = path->data;
        v36 = va::va(
                this: &v117,
                fmt: "%s/%s",
                a3: v35,
                a4: v34,
                a5: v33,
                a6: v75,
                a7: v76,
                a8: v77,
                a9: v78,
                a10: v79,
                a11: v80);
        if ( fileSystem->ReadFile(this: fileSystem, a2: (const char *)v36, a3: (void **)&v82, a4: nullptr) <= 0
          && fileSystem->ReadFile(this: fileSystem, a2: v103.data, a3: (void **)&v82, a4: nullptr) <= 0
          && (!fileSystem->OSPathToRelativePath(this: fileSystem, a2: v103.data, a3: v116, a4: 256)
           || fileSystem->ReadFile(this: fileSystem, a2: v116, a3: (void **)&v82, a4: nullptr) <= 0) )
        {
          idLib::Warning(fmt: v95, src->filename.data, v103.data);
        }
        if ( v82 != nullptr )
        {
          if ( (unsigned __int8)ParseMtlFile(mtlText: v82, parsedMtls: &model->materials) == 0 )
            idLib::Warning(fmt: v94, src->filename.data, v103.data);
          idMem::Free(this: v99, ptr: v82, align: ALIGN_16);
        }
      }
      else
      {
        idLib::Warning(fmt: v97, src->filename.data);
      }
LABEL_144:
      if ( !idLexer::ReadToken(this: src, token: &v103) )
        goto LABEL_145;
    }
    if ( v5->f.num > 0 )
    {
      idStr::idStr(this: v115, text: &v5->materialName);
      v5 = idList<idOBJMesh,5>::Alloc(this: &model->meshes);
      v59 = v115[0].len;
      idStr::EnsureAlloced(this: &v5->materialName, amount: v115[0].len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v5->materialName.data, Src: v115[0].data, Size: v59);
      v5->materialName.data[v59] = 0;
      v5->materialName.len = v59;
      v5->hasNormals = true;
      v5->hasTexCoords = true;
      idStr::FreeData(this: v115);
    }
LABEL_143:
    idLexer::SkipRestOfLine(this: src);
    goto LABEL_144;
  }
LABEL_145:
  v60 = model->meshes.num - 1;
  if ( v60 >= 0 )
  {
    v61 = v60;
    do
    {
      if ( model->meshes.list[v61].f.num == 0 )
        idList<idOBJMesh,5>::RemoveIndex(this: &model->meshes, index: v60);
      --v60;
      --v61;
    }
    while ( v60 >= 0 );
  }
  if ( model->vt.num == 0 )
  {
    v62 = 0;
    v63 = 0;
    if ( model->meshes.num > 0 )
    {
      v64 = 0;
      do
      {
        ++v63;
        p_hasTexCoords = &model->meshes.list[v64++].hasTexCoords;
        v66 = *p_hasTexCoords;
        *p_hasTexCoords = false;
        v62 |= v66;
      }
      while ( v63 < model->meshes.num );
    }
    if ( v62 != 0 )
      idLib::Warning(fmt: "%s: meshes use texture coords that do not exist", v4->filename.data);
  }
  idStr::FreeData(this: &v109);
  idStr::FreeData(this: &v103);
}


// ========================================================================
// $LN413
// EA  : 0x82888EB0
// RVA : 0x00888EB0
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _LN413()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5200 + 176));
}


// ========================================================================
// __unwind$243315
// EA  : 0x82888ED8
// RVA : 0x00888ED8
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_243315()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5200 + 464));
}


// ========================================================================
// __unwind$243316
// EA  : 0x82888F00
// RVA : 0x00888F00
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_243316()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5200 + 256));
}


// ========================================================================
// __unwind$243317
// EA  : 0x82888F28
// RVA : 0x00888F28
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_243317()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5200 + 288));
}


// ========================================================================
// __unwind$243319_0
// EA  : 0x82888F50
// RVA : 0x00888F50
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_243319_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5200 + 384));
}


// ========================================================================
// __unwind$243320
// EA  : 0x82888F78
// RVA : 0x00888F78
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_243320()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5200 + 320));
}


// ========================================================================
// __unwind$243321
// EA  : 0x82888FA0
// RVA : 0x00888FA0
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_243321()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5200 + 352));
}


// ========================================================================
// __unwind$243318_0
// EA  : 0x82888FC8
// RVA : 0x00888FC8
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_243318_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5200 + 544));
}


// ========================================================================
// ?Load@idOBJModel@@QAA_NPBD@Z
// EA  : 0x82888FF8
// RVA : 0x00888FF8
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

int __fastcall idOBJModel::Load(idOBJModel *this, const char *fileName)
{
  idStr v5; // [sp+50h] [-D0h] BYREF
  idLexer v6; // [sp+70h] [-B0h] BYREF

  idLexer::idLexer(this: &v6, flags_: 8724);
  if ( idLexer::LoadFile(this: &v6, filename_: fileName, OSPath: false) )
  {
    idStr::idStr(this: &v5, text: fileName);
    idStr::StripFilename(this: &v5);
    OBJ_Parse(model: this, src: &v6, path: &v5);
    idStr::FreeData(this: &v5);
    idLexer::~idLexer(this: &v6);
    return 1;
  }
  else
  {
    idLexer::~idLexer(this: &v6);
    return 0;
  }
}


// ========================================================================
// __unwind$243975
// EA  : 0x82889088
// RVA : 0x00889088
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_243975()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$243976
// EA  : 0x828890B0
// RVA : 0x008890B0
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_243976()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 80));
}


// ========================================================================
// ?AddGroupGeometry@idOBJModel@@QAA_NPBDABV?$idList@PAVidTriangles@@$04@@ABV?$idList@PBVidMaterial@@$04@@@Z
// EA  : 0x828890F0
// RVA : 0x008890F0
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

int __fastcall idOBJModel::AddGroupGeometry(
        idOBJModel *this,
        const char *groupName,
        const idList<idTriangles *,5> *tris,
        const idList<idMaterial const *,5> *mats)
{
  const idList<idTriangles *,5> *v4; // r27
  int num; // r30
  const idList<idMaterial const *,5> *v7; // r24
  BOOL freeOnDelete; // r10
  int v9; // r9
  int v10; // r8
  int v11; // r7
  const idMaterial *v12; // r18
  idMem *v13; // r26
  int v14; // r15
  idList<idOBJMesh,5> *p_meshes; // r17
  int v16; // r16
  const idMaterial *v17; // r10
  int v18; // r11
  const idMaterial **v19; // r10
  idParsedMtl *v20; // r30
  idStr *v21; // r25
  size_t len; // r29
  int v23; // r11
  int size; // r10
  int v25; // r22
  idTriangles *standardTris; // r25
  int v27; // r21
  int v28; // r24
  int *v29; // r29
  int v30; // r27
  int i; // r26
  __int128 v32; // r11
  int v33; // r30
  __int64 v34; // r6
  double v35; // fp5
  double v36; // fp3
  double v37; // fp1
  double v40; // fp8
  double v41; // fp12
  std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > *v42; // r3
  float v43; // r10
  float v44; // r9
  float v45; // r8
  std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node *v46; // r3
  float *v47; // r28
  std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node *v48; // r3
  double v49; // fp0
  char v50; // r11
  double x; // fp13
  std::_Tree_nod<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> >::_Node **p_Myhead; // r11
  idVec2 v53; // r10
  std::_Tree_nod<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> >::_Node *v54; // r3
  std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > *v55; // r3
  std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node *v56; // r3
  int v57; // r10
  int v58; // r9
  int v59; // r8
  int v60; // r7
  int v61; // r10
  int v62; // r9
  int v63; // r8
  int v64; // r7
  int v66; // [sp+8h] [-248h]
  int v67; // [sp+8h] [-248h]
  int v68; // [sp+8h] [-248h]
  int v69; // [sp+Ch] [-244h]
  int v70; // [sp+Ch] [-244h]
  int v71; // [sp+Ch] [-244h]
  int v72; // [sp+10h] [-240h]
  int v73; // [sp+10h] [-240h]
  int v74; // [sp+10h] [-240h]
  int v75; // [sp+14h] [-23Ch]
  int v76; // [sp+14h] [-23Ch]
  int v77; // [sp+14h] [-23Ch]
  int v78; // [sp+18h] [-238h]
  int v79; // [sp+18h] [-238h]
  int v80; // [sp+18h] [-238h]
  int v81; // [sp+1Ch] [-234h]
  int v82; // [sp+1Ch] [-234h]
  int v83; // [sp+1Ch] [-234h]
  int v84; // [sp+20h] [-230h]
  int v85; // [sp+20h] [-230h]
  int v86; // [sp+20h] [-230h]
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >,std::_Iterator_base0> *v87; // [sp+24h] [-22Ch]
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> >,std::_Iterator_base0> *v88; // [sp+24h] [-22Ch]
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >,std::_Iterator_base0> *v89; // [sp+24h] [-22Ch]
  std::allocator<std::pair<idVec3 const ,int> > v90; // [sp+50h] [-200h] BYREF
  std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > v91; // [sp+54h] [-1FCh] BYREF
  int v92; // [sp+64h] [-1ECh]
  int v93; // [sp+68h] [-1E8h]
  __int16 v94; // [sp+6Ch] [-1E4h]
  char v95; // [sp+6Eh] [-1E2h]
  char v96; // [sp+6Fh] [-1E1h]
  int v97; // [sp+70h] [-1E0h]
  idVec3 v98[2]; // [sp+78h] [-1D8h] BYREF
  std::_Tree_val<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> > v99; // [sp+90h] [-1C0h] BYREF
  std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > v100; // [sp+A0h] [-1B0h] BYREF
  std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > v101; // [sp+B0h] [-1A0h] BYREF
  idMem *v102; // [sp+C0h] [-190h]
  std::_Tree_nod<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> >::_Node *Myhead; // [sp+C4h] [-18Ch] BYREF
  const char *v104; // [sp+C8h] [-188h]
  idAutoStandardTriangles v105; // [sp+D0h] [-180h] BYREF
  std::pair<idVec3 const ,int> v106; // [sp+E0h] [-170h] BYREF
  std::pair<idVec3 const ,int> v107; // [sp+F0h] [-160h] BYREF
  __int64 v108; // [sp+100h] [-150h]
  __int64 v109; // [sp+108h] [-148h]
  __int64 v110; // [sp+110h] [-140h]
  std::pair<idVec2 const ,int> v111; // [sp+118h] [-138h] BYREF
  std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > v112; // [sp+124h] [-12Ch] BYREF
  int v113; // [sp+134h] [-11Ch]
  int v114; // [sp+138h] [-118h]
  int v115; // [sp+144h] [-10Ch] BYREF
  std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > v116; // [sp+158h] [-F8h] BYREF
  std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > v117[5]; // [sp+168h] [-E8h] BYREF

  v4 = tris;
  num = tris->num;
  v7 = mats;
  std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>(
    this: &v100,
    _Parg: (const std::less<idVec3> *)&v90,
    _Al: &v90);
  std::_Tree_val<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const,int>>,0>>::_Tree_val<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const,int>>,0>>(
    this: &v99,
    _Parg: (const std::less<idVec2> *)&v90,
    _Al: (std::allocator<std::pair<idVec2 const ,int> > *)&v90);
  std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>(
    this: &v101,
    _Parg: (const std::less<idVec3> *)&v90,
    _Al: &v90);
  *(_DWORD *)&v91._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node> = 0;
  v94 = 0;
  v96 = 0;
  v93 = 0;
  v92 = 0;
  v95 = 5;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v91._Alnod);
  v12 = nullptr;
  v13 = &mem;
  v102 = &mem;
  if ( num > 0 )
  {
    v14 = v92;
    v97 = num;
    p_meshes = &this->meshes;
    v16 = 0;
    v104 = "_default";
    do
    {
      v17 = v7->list[v16];
      if ( v12 != v17 )
      {
        v12 = v7->list[v16];
        v91._Myhead = (std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node *)v12;
        if ( v17 != nullptr )
        {
          v18 = 0;
          if ( v14 <= 0 )
            goto LABEL_12;
          v19 = *(const idMaterial ***)&v91._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node>;
          while ( *v19 != v12 )
          {
            ++v18;
            ++v19;
            if ( v18 >= v14 )
              goto LABEL_12;
          }
          if ( v18 < 0
            || 4 * v18
             + *(_DWORD *)&v91._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node> == 0 )
          {
LABEL_12:
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&v91._Alnod,
              obj: (const encounterGroupRole_t *)&v91._Myhead);
            v20 = idList<idParsedMtl,5>::Alloc(this: &this->materials);
            idStr::operator=(this: &v20->mtlName, text: v12->name.str);
            v21 = fileSystem->RelativePathToOSPath(
                    this: &v117[0]._Mysize,
                    result: fileSystem,
                    a3: v20->mtlName.data,
                    a4: 0);
            len = v21->len;
            idStr::EnsureAlloced(this: &v20->map_Kd, amount: v21->len + 1, keepold: false, geometricGrowth: false);
            memcpy(Dst: v20->map_Kd.data, Src: v21->data, Size: len);
            v20->map_Kd.data[len] = 0;
            v20->map_Kd.len = len;
            idStr::FreeData(this: (idStr *)&v117[0]._Mysize);
            idStr::DefaultFileExtension(this: &v20->map_Kd, extension: "tga");
            v14 = v92;
          }
        }
      }
      idList<idOBJMesh,5>::PreAllocateWithGranularity(this: &this->meshes, newSize: this->meshes.num + 1);
      v23 = this->meshes.num;
      size = this->meshes.size;
      if ( v23 >= size )
      {
        v25 = (int)&p_meshes->list[size - 1];
      }
      else
      {
        v25 = (int)&p_meshes->list[v23];
        this->meshes.num = v23 + 1;
      }
      *(_BYTE *)(v25 + 65) = 1;
      *(_BYTE *)(v25 + 64) = 1;
      if ( v12 != nullptr )
      {
        idStr::operator=(this: (idStr *)v25, text: v12->name.str);
        idStr::MakeNameCanonical(this: (idStr *)v25);
      }
      else
      {
        idStr::operator=(this: (idStr *)v25, text: v104);
      }
      idStr::operator=(this: (idStr *)(v25 + 32), text: groupName);
      idAutoStandardTriangles::idAutoStandardTriangles(this: &v105, tri: v4->list[v16]);
      standardTris = (idTriangles *)v105.standardTris;
      v27 = 0;
      if ( v105.standardTris->numIndexes > 0 )
      {
        v28 = 4;
        do
        {
          v114 = 0;
          v29 = &v115;
          v113 = 0;
          v30 = v28;
          *(_DWORD *)&v112._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node> = 0;
          for ( i = 3; i != 0; --i )
          {
            DWORD1(v32) = *(unsigned __int16 *)((char *)standardTris->indexes + v30);
            v33 = (int)standardTris->verts + __ROL4__(DWORD1(v32), 5);
            HIDWORD(v34) = v33;
            LODWORD(v34) = *(unsigned __int8 *)(v33 + 20);
            LODWORD(v32) = *(unsigned __int8 *)(v33 + 22);
            DWORD2(v32) = *(unsigned __int8 *)(v33 + 21);
            v109 = v34;
            v108 = v32;
            v110 = *(_QWORD *)((char *)&v32 + 4);
            v35 = (float)((float)((float)*(__int64 *)((char *)&v32 + 4) * (float)0.0078431377) - (float)1.0);
            v36 = (float)((float)((float)v34 * (float)0.0078431377) - (float)1.0);
            v37 = (float)((float)((float)(__int64)v32 * (float)0.0078431377) - (float)1.0);
            _FP11 = (float)((float)((float)((float)v37 * (float)v37)
                                  + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35)))
                          - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f9, f11, f12, f0 }
            v40 = __frsqrte(_FP9);
            v41 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40
                                                                                                * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5))
                                                                                        * (float)v40)
                                                                                - (float)1.5)
                                                                * (float)v40)
                                                        * (float)((float)((float)((float)v37 * (float)v37)
                                                                        + (float)((float)((float)v36 * (float)v36)
                                                                                + (float)((float)v35 * (float)v35)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v40
                                                                                        * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35)))
                                                                                                * (float)0.5))
                                                                                * (float)v40)
                                                                        - (float)1.5)
                                                        * (float)v40))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v40
                                                                * (float)((float)((float)((float)v37 * (float)v37)
                                                                                + (float)((float)((float)v36 * (float)v36)
                                                                                        + (float)((float)v35 * (float)v35)))
                                                                        * (float)0.5))
                                                        * (float)v40)
                                                - (float)1.5)
                                * (float)v40));
            v98[0].x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5)) * (float)v40) - (float)1.5) * (float)v40) * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5)) * (float)v40) - (float)1.5) * (float)v40))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5)) * (float)v40)
                                                                                             - (float)1.5)
                                                                             * (float)v40))
                                                             * (float)((float)((float)((float)v37 * (float)v37)
                                                                             + (float)((float)((float)v36 * (float)v36)
                                                                                     + (float)((float)v35 * (float)v35)))
                                                                     * (float)0.5))
                                                     * (float)v41)
                                             - (float)1.5)
                             * (float)v41)
                     * (float)v36;
            v98[0].y = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5)) * (float)v40) - (float)1.5) * (float)v40) * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5)) * (float)v40) - (float)1.5) * (float)v40))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5)) * (float)v40)
                                                                                             - (float)1.5)
                                                                             * (float)v40))
                                                             * (float)((float)((float)((float)v37 * (float)v37)
                                                                             + (float)((float)((float)v36 * (float)v36)
                                                                                     + (float)((float)v35 * (float)v35)))
                                                                     * (float)0.5))
                                                     * (float)v41)
                                             - (float)1.5)
                             * (float)v41)
                     * (float)v35;
            v98[0].z = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5)) * (float)v40) - (float)1.5) * (float)v40) * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5)) * (float)v40) - (float)1.5) * (float)v40))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v37 * (float)v37) + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) * (float)0.5)) * (float)v40)
                                                                                             - (float)1.5)
                                                                             * (float)v40))
                                                             * (float)((float)((float)((float)v37 * (float)v37)
                                                                             + (float)((float)((float)v36 * (float)v36)
                                                                                     + (float)((float)v35 * (float)v35)))
                                                                     * (float)0.5))
                                                     * (float)v41)
                                             - (float)1.5)
                             * (float)v41)
                     * (float)v37;
            v42 = std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::find(
                    this: &v112,
                    result: (std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > *)&v100,
                    _Keyval: (const idVec3 *)v33);
            if ( *(std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node **)&v42->comp.std::binary_function<idVec3,idVec3,bool> == v100._Myhead )
            {
              v43 = *(float *)v33;
              v44 = *(float *)(v33 + 4);
              v45 = *(float *)(v33 + 8);
              v107.second = this->v.num;
              v107.first.x = v43;
              v107.first.y = v44;
              v107.first.z = v45;
              v46 = std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::_Buynode<std::pair<idVec3 const,int>>(
                      this: &v100,
                      _Val: &v107);
              std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::_Linsert(
                this: &v116,
                result: (std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > *)&v100,
                _Node: v46,
                _Leftish: false);
              idList<idAngles,5>::Append(this: &this->v, obj: (const idVec3 *)v33);
            }
            v47 = (float *)(v33 + 12);
            v48 = (std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node *)std::_Tree<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const,int>>,0>>::_Lbound(this: (std::_Tree<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> > *)&v99, _Keyval: (const idVec2 *)(v33 + 12));
            v91._Myhead = v48;
            if ( v48 == (std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node *)v99._Myhead )
              goto LABEL_31;
            v49 = *v47;
            v50 = 1;
            x = v48->_Myval.first.x;
            if ( v49 == x )
            {
              v49 = *(float *)(v33 + 16);
              x = v48->_Myval.first.y;
            }
            if ( v49 >= x )
              v50 = 0;
            if ( v50 != 0 )
            {
LABEL_31:
              Myhead = v99._Myhead;
              p_Myhead = &Myhead;
            }
            else
            {
              p_Myhead = (std::_Tree_nod<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> >::_Node **)&v91._Myhead;
            }
            if ( *p_Myhead == v99._Myhead )
            {
              v53 = *(idVec2 *)v47;
              v111.second = this->vt.num;
              v111.first = v53;
              v54 = std::_Tree_val<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const,int>>,0>>::_Buynode<std::pair<idVec2 const,int>>(
                      this: &v99,
                      _Val: &v111);
              std::_Tree<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const,int>>,0>>::_Linsert(
                this: (std::_Tree<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> > *)&v116._Mysize,
                result: (std::_Tree<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> > *)&v99,
                _Node: v54,
                _Leftish: false);
              idList<idVec2,72>::Append(this: (idList<idVec2,72> *)&this->vt, obj: (const idVec2 *)(v33 + 12));
            }
            v55 = std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::find(
                    this: &v91,
                    result: (std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > *)&v101,
                    _Keyval: v98);
            if ( *(std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node **)&v55->comp.std::binary_function<idVec3,idVec3,bool> == v101._Myhead )
            {
              v106.second = this->vn.num;
              v106.first = v98[0];
              v56 = std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::_Buynode<std::pair<idVec3 const,int>>(
                      this: &v101,
                      _Val: &v106);
              std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::_Linsert(
                this: v117,
                result: (std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > *)&v101,
                _Node: v56,
                _Leftish: false);
              idList<idAngles,5>::Append(this: &this->vn, obj: v98);
            }
            *(v29 - 5) = *std::map<idVec3,int>::operator[](
                            this: (std::map<idVec3,int> *)&v100,
                            _Keyval: (const idVec3 *)v33)
                       + 1;
            *(v29 - 2) = *std::map<idVec2,int>::operator[](
                            this: (std::map<idVec2,int> *)&v99,
                            _Keyval: (const idVec2 *)(v33 + 12))
                       + 1;
            v30 -= 2;
            *++v29 = *std::map<idVec3,int>::operator[](this: (std::map<idVec3,int> *)&v101, _Keyval: v98) + 1;
          }
          v9 = *(_DWORD *)&v112._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node>;
          if ( *(_DWORD *)&v112._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node> != v113
            && v113 != v114
            && *(_DWORD *)&v112._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node> != v114 )
          {
            idList<idOBJFace,5>::Append(this: (idList<idOBJFace,5> *)(v25 + 68), obj: (const idOBJFace *)&v112._Alnod);
          }
          v27 += 3;
          v28 += 6;
        }
        while ( v27 < standardTris->numIndexes );
        v4 = tris;
        v7 = mats;
        v13 = v102;
      }
      freeOnDelete = v105.freeOnDelete;
      if ( v105.freeOnDelete )
      {
        idTriangles::~idTriangles(this: standardTris);
        idMem::Free(this: v13, ptr: standardTris, align: ALIGN_16);
      }
      ++v16;
      --v97;
    }
    while ( v97 != 0 );
  }
  if ( (v96 == 0 || v96 == 2)
    && *(_DWORD *)&v91._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node> != 0 )
  {
    idMem::Free(
      this: v13,
      ptr: *(void **)&v91._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> >::_Node>,
      align: ALIGN_16);
  }
  *(_DWORD *)&v91.comp.std::binary_function<idVec3,idVec3,bool> = v101._Myhead;
  std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::erase(
    this: &v91,
    result: (std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > *)&v101,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > > *)v101._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > > *)v101._Myhead,
    a5: v11,
    a6: v10,
    a7: v9,
    a8: freeOnDelete,
    a9: v66,
    a10: v69,
    a11: v72,
    a12: v75,
    a13: v78,
    a14: v81,
    a15: v84,
    a16: v87);
  idMem::Free(this: v13, ptr: v101._Myhead, align: ALIGN_16);
  *(_DWORD *)&v91.comp.std::binary_function<idVec3,idVec3,bool> = v99._Myhead;
  std::_Tree<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const,int>>,0>>::erase(
    this: (std::_Tree<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> > *)&v91,
    result: (std::_Tree<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> > *)&v99,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> > > *)v99._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<idVec2,int,std::less<idVec2>,std::allocator<std::pair<idVec2 const ,int> >,0> > > *)v99._Myhead,
    a5: v60,
    a6: v59,
    a7: v58,
    a8: v57,
    a9: v67,
    a10: v70,
    a11: v73,
    a12: v76,
    a13: v79,
    a14: v82,
    a15: v85,
    a16: v88);
  idMem::Free(this: v13, ptr: v99._Myhead, align: ALIGN_16);
  *(_DWORD *)&v91.comp.std::binary_function<idVec3,idVec3,bool> = v100._Myhead;
  std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::erase(
    this: &v91,
    result: (std::_Tree<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > *)&v100,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > > *)v100._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const ,int> >,0> > > *)v100._Myhead,
    a5: v64,
    a6: v63,
    a7: v62,
    a8: v61,
    a9: v68,
    a10: v71,
    a11: v74,
    a12: v77,
    a13: v80,
    a14: v83,
    a15: v86,
    a16: v89);
  idMem::Free(this: v13, ptr: v100._Myhead, align: ALIGN_16);
  return 1;
}


// ========================================================================
// __unwind$244088
// EA  : 0x82889788
// RVA : 0x00889788
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void __fastcall _unwind_244088(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r12

  std::map<idVec3,int>::~map<idVec3,int>(this: (std::map<idVec3,int> *)(v8 - 592 + 160), a2, a3, a4, a5, a6, a7, a8);
}


// ========================================================================
// __unwind$244089
// EA  : 0x828897B0
// RVA : 0x008897B0
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void __fastcall _unwind_244089(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r12

  std::map<idVec2,int>::~map<idVec2,int>(this: (std::map<idVec2,int> *)(v8 - 592 + 144), a2, a3, a4, a5, a6, a7, a8);
}


// ========================================================================
// __unwind$244090
// EA  : 0x828897D8
// RVA : 0x008897D8
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void __fastcall _unwind_244090(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r12

  std::map<idVec3,int>::~map<idVec3,int>(this: (std::map<idVec3,int> *)(v8 - 592 + 176), a2, a3, a4, a5, a6, a7, a8);
}


// ========================================================================
// __unwind$244091
// EA  : 0x82889800
// RVA : 0x00889800
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_244091()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 592 + 96));
}


// ========================================================================
// __unwind$244092
// EA  : 0x82889828
// RVA : 0x00889828
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_244092()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 592 + 368));
}


// ========================================================================
// __unwind$244093
// EA  : 0x82889850
// RVA : 0x00889850
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_244093()
{
  int v0; // r12

  idAutoStandardTriangles::~idAutoStandardTriangles(this: (idAutoStandardTriangles *)(v0 - 592 + 208));
}


// ========================================================================
// __unwind$244814_0
// EA  : 0x82889878
// RVA : 0x00889878
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_244814_0()
{
  int v0; // r12

  std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::~_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>(this: (std::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > *)(v0 - 592 + 176));
}


// ========================================================================
// __unwind$245036
// EA  : 0x828898A0
// RVA : 0x008898A0
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_245036()
{
  int v0; // r12

  std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::~_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>(this: (std::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > *)(v0 - 592 + 144));
}


// ========================================================================
// __unwind$245258
// EA  : 0x828898C8
// RVA : 0x008898C8
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void _unwind_245258()
{
  int v0; // r12

  std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::~_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>(this: (std::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > *)(v0 - 592 + 160));
}


// ========================================================================
// ?OBJ_Load@@YAPAVidOBJModel@@PBD@Z
// EA  : 0x828898F8
// RVA : 0x008898F8
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

idOBJModel *__fastcall OBJ_Load(const char *fileName)
{
  idOBJModel *v2; // r3
  idOBJModel *v3; // r30

  v2 = (idOBJModel *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                       size: 0x60u,
                       tag: TAG_NEW,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idOBJModel::idOBJModel(this: v2);
  else
    v3 = nullptr;
  if ( (unsigned __int8)idOBJModel::Load(this: v3, fileName) != 0 )
    return v3;
  if ( v3 != nullptr )
  {
    idOBJModel::~idOBJModel(this: v3);
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
  }
  return nullptr;
}


// ========================================================================
// __unwind$245564
// EA  : 0x828899A0
// RVA : 0x008899A0
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void __fastcall _unwind_245564(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?TestObjLoader_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828899D0
// RVA : 0x008899D0
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void __fastcall TestObjLoader_f(const idCmdArgs *args)
{
  int v2; // r27
  const char *v3; // r29
  idOBJModel *v4; // r3
  idOBJModel *v5; // r30
  idStaticModel *v6; // r3
  idStaticModel *v7; // r30
  __int64 v8; // r9
  double v9; // r4

  v2 = Sys_Milliseconds();
  if ( args->argc == 1 )
  {
    v3 = "zbrush/lowhead_color.obj";
  }
  else if ( args->argc <= 1 )
  {
    v3 = &byte_8200D768;
  }
  else
  {
    v3 = args->argv[1];
  }
  v4 = OBJ_Load(fileName: v3);
  v5 = v4;
  if ( v4 != nullptr )
  {
    idOBJModel::~idOBJModel(this: v4);
    idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
  }
  v6 = (idStaticModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x194u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
    v7 = idStaticModel::idStaticModel(this: v6);
  else
    v7 = nullptr;
  idResource::SetName(this: v7, _name: v3);
  idStaticModel::PristineLoadResource(this: v7);
  LODWORD(v8) = Sys_Milliseconds() - v2;
  HIDWORD(v8) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  v9 = (float)((float)v8 * (float)0.001);
  idLib::Printf(fmt: (const char *)HIDWORD(v9), LODWORD(v9), v3);
}


// ========================================================================
// __unwind$245604
// EA  : 0x82889AE8
// RVA : 0x00889AE8
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

void __fastcall _unwind_245604(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// `dynamic initializer for 'TestParseFaceLine_v''
// EA  : 0x83344FE0
// RVA : 0x01344FE0
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestParseFaceLine_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestParseFaceLine_v,
           cmdName: "TestParseFaceLine",
           function: TestParseFaceLine_f,
           description: "Tests part of the obj file parsing",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestObjLoader_v''
// EA  : 0x83345008
// RVA : 0x01345008
// PDB : w:\tech5\engine\models\static\staticmodel_obj.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestObjLoader_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestObjLoader_v,
           cmdName: "TestObjLoader",
           function: TestObjLoader_f,
           description: "Tests the new obj file loader",
           argCompletion: nullptr);
}

