
// ========================================================================
// ?CompareSubdivElems@bfx@@YAHPBX0@Z
// EA  : 0x8287C670
// RVA : 0x0087C670
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall bfx::CompareSubdivElems(float *a, float *b)
{
  double v2; // fp0
  double v3; // fp13
  int result; // r3

  v2 = a[3];
  v3 = b[3];
  if ( v2 > v3 )
    return 1;
  result = -1;
  if ( v2 >= v3 )
    return 0;
  return result;
}


// ========================================================================
// ?lwListFree@@YAXPAXP6AX0@Z@Z
// EA  : 0x8287C6A0
// RVA : 0x0087C6A0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwListFree(void **list, void (*freeNode)(void))
{
  void **v3; // r31

  if ( list != nullptr )
  {
    do
    {
      v3 = (void **)*list;
      freeNode();
      list = v3;
    }
    while ( v3 != nullptr );
  }
}


// ========================================================================
// ?lwListInsert@@YAXPAPAXPAXP6AH11@Z@Z
// EA  : 0x8287C6F0
// RVA : 0x0087C6F0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwListInsert(void **vlist, _DWORD *vitem, int (__fastcall *compare)(void *, void *))
{
  _DWORD *v3; // r31
  _DWORD *v7; // r29

  v3 = *vlist;
  if ( *vlist != nullptr )
  {
    v7 = nullptr;
    do
    {
      if ( compare(a1: v3, a2: vitem) > 0 )
        break;
      v7 = v3;
      v3 = (_DWORD *)*v3;
    }
    while ( v3 != nullptr );
    if ( v7 != nullptr )
    {
      if ( v3 != nullptr )
      {
        *vitem = v3;
        vitem[1] = v7;
        *v7 = vitem;
        v3[1] = vitem;
      }
      else
      {
        *v7 = vitem;
        vitem[1] = v7;
      }
    }
    else
    {
      *vlist = vitem;
      v3[1] = vitem;
      *vitem = v3;
    }
  }
  else
  {
    *vlist = vitem;
  }
}


// ========================================================================
// ?getU1@@YAEPAVidFile@@@Z
// EA  : 0x8287C798
// RVA : 0x0087C798
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall getU1(idFile *fp)
{
  int result; // r3
  idFile_vtbl *v2; // r10
  int v3; // r11
  _BYTE v4[16]; // [sp+50h] [-20h] BYREF

  if ( flen == -9999 )
    return 0;
  v2 = fp->__vftable;
  v4[0] = 0;
  if ( v2->Read(this: fp, a2: v4, a3: 1u) == 1 )
  {
    result = v4[0];
    v3 = flen + 1;
  }
  else
  {
    v3 = -9999;
    result = 0;
  }
  flen = v3;
  return result;
}


// ========================================================================
// ?getVX@@YAHPAVidFile@@@Z
// EA  : 0x8287C828
// RVA : 0x0087C828
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall getVX(idFile *fp)
{
  idFile_vtbl *v3; // r11
  int v4; // r11
  idFile *v5; // r3
  bool v6; // zf
  int v7; // r31
  unsigned int (__fastcall *Read)(idFile *, void *, unsigned int); // ctr
  int v9; // r28
  idFile *v10; // r3
  int v11; // r9
  int v12; // r31
  unsigned int (__fastcall *v13)(idFile *, void *, unsigned int); // ctr
  _BYTE v14[48]; // [sp+50h] [-30h] BYREF

  if ( flen == -9999 )
    return 0;
  v3 = fp->__vftable;
  v14[0] = 0;
  if ( v3->Read(this: fp, a2: v14, a3: 1u) == 0 )
    return 0;
  v4 = v14[0];
  v5 = fp;
  v6 = v14[0] == 255;
  v14[0] = 0;
  if ( !v6 )
  {
    Read = fp->Read;
    v7 = v4 << 8;
    if ( Read(this: v5, a2: v14, a3: 1u) != 0 )
    {
      flen += 2;
      return v14[0] | v7;
    }
    return 0;
  }
  if ( fp->Read(this: fp, a2: v14, a3: 1u) == 0 )
    return 0;
  v9 = __ROL4__(v14[0], 16);
  v14[0] = 0;
  if ( fp->Read(this: fp, a2: v14, a3: 1u) == 0 )
    return 0;
  v10 = fp;
  v11 = __ROL4__(v14[0], 8);
  v14[0] = 0;
  v13 = fp->Read;
  v12 = v11 | v9;
  if ( v13(this: v10, a2: v14, a3: 1u) == 0 )
    return 0;
  flen += 4;
  return v14[0] | v12;
}


// ========================================================================
// ?sgetVX@@YAHPAPAE@Z
// EA  : 0x8287C970
// RVA : 0x0087C970
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall sgetVX(unsigned __int8 **bp)
{
  unsigned __int8 *v1; // r11
  int v3; // r9
  int v5; // r7
  int v6; // r6
  int v7; // r5
  int v8; // r9
  int v9; // r4
  int v10; // r3

  v1 = *bp;
  v3 = flen;
  if ( flen == -9999 )
    return 0;
  v5 = *v1;
  if ( v5 == 255 )
  {
    v7 = v1[2];
    v8 = flen + 4;
    v9 = __ROL4__(v1[1], 8);
    v10 = v1[3];
    *bp = v1 + 4;
    flen = v8;
    return ((v9 | v7) << 8) | v10;
  }
  else
  {
    v6 = v1[1];
    *bp = v1 + 2;
    flen = v3 + 2;
    return v6 | (v5 << 8);
  }
}


// ========================================================================
// ?lwGetBoundingBox@@YAXPAUst_lwPointList@@QAM@Z
// EA  : 0x8287C9F0
// RVA : 0x0087C9F0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwGetBoundingBox(st_lwPointList *point, float *bbox)
{
  int v2; // r11
  float *i; // r10
  int v4; // r9
  int v5; // r11
  st_lwPoint *pt; // r10
  st_lwPoint *v7; // r10
  st_lwPoint *v8; // r10
  st_lwPoint *v9; // r10
  st_lwPoint *v10; // r8

  if ( point->count != 0 )
  {
    v2 = 0;
    for ( i = bbox; *i == 0.0; ++i )
    {
      if ( ++v2 >= 6 )
      {
        v4 = 0;
        *bbox = 1.0e20;
        bbox[2] = 1.0e20;
        bbox[1] = 1.0e20;
        bbox[5] = -1.0e20;
        bbox[4] = -1.0e20;
        bbox[3] = -1.0e20;
        if ( point->count > 0 )
        {
          v5 = 0;
          do
          {
            pt = point->pt;
            if ( *bbox > (double)pt[v5].pos[0] )
              *bbox = pt[v5].pos[0];
            v7 = point->pt;
            if ( bbox[3] < (double)v7[v5].pos[0] )
              bbox[3] = v7[v5].pos[0];
            v8 = &point->pt[v5];
            if ( bbox[1] > (double)v8->pos[1] )
              bbox[1] = v8->pos[1];
            v9 = &point->pt[v5];
            if ( bbox[4] < (double)v9->pos[1] )
              bbox[4] = v9->pos[1];
            if ( bbox[2] > (double)point->pt[v5].pos[2] )
              bbox[2] = point->pt[v5].pos[2];
            v10 = point->pt;
            if ( bbox[5] < (double)v10[v5].pos[2] )
              bbox[5] = v10[v5].pos[2];
            ++v4;
            ++v5;
          }
          while ( v4 < point->count );
        }
        return;
      }
    }
  }
}


// ========================================================================
// compare_shaders
// EA  : 0x8287CB18
// RVA : 0x0087CB18
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall compare_shaders(st_lwPlugin *a, st_lwPlugin *b)
{
  char *ord; // r11
  char *v3; // r10
  int result; // r3

  ord = a->ord;
  if ( ord == nullptr )
    return 1;
  v3 = b->ord;
  if ( v3 == nullptr )
    return 1;
  do
  {
    result = (unsigned __int8)*ord - (unsigned __int8)*v3;
    if ( *ord == 0 )
      break;
    ++ord;
    ++v3;
  }
  while ( result == 0 );
  return result;
}


// ========================================================================
// add_texture
// EA  : 0x8287CB60
// RVA : 0x0087CB60
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall add_texture(st_lwSurface *surf, st_lwTexture *tex)
{
  unsigned int chan; // r11
  void **p_tex; // r3

  chan = tex->chan;
  if ( chan > 0x5245464C )
  {
    if ( chan > 0x5452414E )
    {
      if ( chan == 1414680140 )
      {
        p_tex = (void **)&surf->translucency.tex;
        goto LABEL_25;
      }
    }
    else
    {
      switch ( chan )
      {
        case 0x5452414Eu:
          p_tex = (void **)&surf->transparency.val.tex;
          goto LABEL_25;
        case 0x52494E44u:
          p_tex = (void **)&surf->eta.tex;
          goto LABEL_25;
        case 0x53504543u:
          p_tex = (void **)&surf->specularity.tex;
          goto LABEL_25;
        default:
          break;
      }
    }
    return 0;
  }
  if ( chan == 1380271692 )
  {
    p_tex = (void **)&surf->reflection.val.tex;
    goto LABEL_25;
  }
  if ( chan > 0x44494646 )
  {
    if ( chan == 1196183379 )
    {
      p_tex = (void **)&surf->glossiness.tex;
      goto LABEL_25;
    }
    if ( chan == 1280658761 )
    {
      p_tex = (void **)&surf->luminosity.tex;
      goto LABEL_25;
    }
    return 0;
  }
  if ( chan == 1145652806 )
  {
    p_tex = (void **)&surf->diffuse.tex;
    goto LABEL_25;
  }
  if ( chan == 1112886608 )
  {
    p_tex = (void **)&surf->bump.tex;
    goto LABEL_25;
  }
  if ( chan != 1129270354 )
    return 0;
  p_tex = (void **)&surf->color.tex;
LABEL_25:
  lwListInsert(vlist: p_tex, vitem: tex, compare: (int (__fastcall *)(void *, void *))compare_shaders);
  return 1;
}


// ========================================================================
// ?getU2@@YAGPAVidFile@@@Z
// EA  : 0x8287CCA0
// RVA : 0x0087CCA0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall getU2(idFile *fp)
{
  int result; // r3
  idFile_vtbl *v2; // r10
  int v3; // r11
  _WORD v4[8]; // [sp+50h] [-20h] BYREF

  if ( flen == -9999 )
    return 0;
  v2 = fp->__vftable;
  v4[0] = 0;
  if ( v2->Read(this: fp, a2: v4, a3: 2u) == 2 )
  {
    result = v4[0];
    v3 = flen + 2;
  }
  else
  {
    v3 = -9999;
    result = 0;
  }
  flen = v3;
  return result;
}


// ========================================================================
// ?getU4@@YAIPAVidFile@@@Z
// EA  : 0x8287CD30
// RVA : 0x0087CD30
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

unsigned int __fastcall getU4(idFile *fp)
{
  unsigned int result; // r3
  idFile_vtbl *v2; // r10
  int v3; // r11
  unsigned int v4[4]; // [sp+50h] [-20h] BYREF

  if ( flen == -9999 )
    return 0;
  v2 = fp->__vftable;
  v4[0] = 0;
  if ( v2->Read(this: fp, a2: v4, a3: 4u) == 4 )
  {
    result = v4[0];
    v3 = flen + 4;
  }
  else
  {
    v3 = -9999;
    result = 0;
  }
  flen = v3;
  return result;
}


// ========================================================================
// ?getF4@@YAMPAVidFile@@@Z
// EA  : 0x8287CDC0
// RVA : 0x0087CDC0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

float __fastcall getF4(idFile *fp)
{
  double v1; // fp1
  char v2; // r11
  float v4[4]; // [sp+50h] [-20h] BYREF

  if ( flen != -9999 )
  {
    if ( fp->Read(this: fp, a2: v4, a3: 4u) != 4 )
    {
      flen = -9999;
      v1 = 0.0;
      return *((float *)&v1 + 1);
    }
    v1 = v4[0];
    flen += 4;
    if ( (LODWORD(v4[0]) & 0x7F800000) != 0 || (v2 = 1, (LODWORD(v4[0]) & 0x7FFFFF) == 0) )
      v2 = 0;
    if ( v2 == 0 )
      return *((float *)&v1 + 1);
  }
  v1 = 0.0;
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?lwForceSmoothSurfaces@@YAXPAUst_lwSurface@@M@Z
// EA  : 0x8287CE88
// RVA : 0x0087CE88
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall lwForceSmoothSurfaces(st_lwSurface *surf, double smooth)
{
  double v2; // fp31
  st_lwSurface *i; // r31
  long double v4; // fp2

  v2 = smooth;
  if ( smooth > 0.0 )
  {
    for ( i = surf; i != nullptr; i = i->next )
    {
      if ( i->smooth <= 0.0 )
      {
        i->smooth = v2;
        *(double *)&v4 = v2;
        *(long double *)(&smooth - 1) = cos(x: v4);
        i->smoothCos = smooth;
      }
    }
  }
}


// ========================================================================
// ?lwGetPolygonTags@@YAHPAVidFile@@HPAUst_lwTagList@@PAUst_lwPolygonList@@@Z
// EA  : 0x8287CF08
// RVA : 0x0087CF08
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetPolygonTags(idFile *fp, int cksize, st_lwTagList *tlist, st_lwPolygonList *plist)
{
  unsigned int U4; // r3
  unsigned int v9; // r27
  int v11; // r31
  int VX; // r3
  int v13; // r8
  st_lwSurface *v14; // r11

  flen = 0;
  U4 = getU4(fp);
  v9 = U4;
  if ( flen < 0 )
    return 0;
  if ( U4 != 1398100550 && U4 != 1346458196 && U4 != 1397573456 )
  {
    fp->Seek(this: fp, a2: cksize - 4, a3: FS_SEEK_CUR);
    return 1;
  }
  if ( plist->count > 0xFFFFFF )
  {
    idLib::Warning(
      fmt: "LWO model has %i polygons, which can't be indexed with 24 bit indexes.  Consider exporting in obj format.",
      plist->count);
    return 0;
  }
  if ( flen < cksize )
  {
    while ( 1 )
    {
      v11 = getVX(fp) + plist->offset;
      VX = getVX(fp);
      v13 = flen;
      v14 = (st_lwSurface *)(VX + tlist->offset);
      if ( flen < 0 || flen > cksize )
        break;
      switch ( v9 )
      {
        case 0x50415254u:
          plist->pol[v11].part = (int)v14;
          break;
        case 0x534D4750u:
          plist->pol[v11].smoothgrp = (int)v14;
          break;
        case 0x53555246u:
          plist->pol[v11].surf = v14;
          break;
        default:
          break;
      }
      if ( v13 >= cksize )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?lwGetPolyNormals@@YAXPAUst_lwPointList@@PAUst_lwPolygonList@@@Z
// EA  : 0x8287D080
// RVA : 0x0087D080
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwGetPolyNormals(st_lwPointList *point, st_lwPolygonList *polygon)
{
  int v2; // r28
  int v3; // r9
  st_lwPolygon *pol; // r11
  st_lwPolVert *polVerts; // r6
  st_lwPoint *pt; // r11
  float *v7; // r10
  int vindex; // r7
  int nverts; // r8
  int v10; // r5
  st_lwPolVert *v11; // r30
  int index; // r7
  int v13; // r6
  int v14; // r8
  int v15; // r7
  int v16; // r31
  int v17; // r6
  int v18; // r30
  st_lwPoint *v19; // r8
  double v20; // fp9
  int v21; // r5
  double v22; // fp8
  double v23; // fp4
  double v24; // fp11
  double v25; // fp10
  double v26; // fp6
  double v27; // fp5
  st_lwPolygon *v28; // r11
  double v29; // fp10
  double v30; // fp9
  double v32; // fp4
  double v34; // fp2
  double v35; // fp3
  double v36; // fp2

  v2 = 0;
  if ( polygon->count > 0 )
  {
    v3 = 0;
    do
    {
      if ( polygon->pol[v3].nverts >= 3 )
      {
        pol = polygon->pol;
        polVerts = polygon->polVerts;
        v7 = (float *)&pol[v3];
        vindex = pol[v3].vindex;
        nverts = pol[v3].nverts;
        pt = point->pt;
        v10 = vindex;
        v11 = &polVerts[nverts + vindex];
        index = polVerts[vindex].index;
        v13 = polVerts[v10 + 1].index;
        v14 = index;
        v15 = v13;
        v16 = v13;
        v17 = v11[-1].index;
        v18 = v11[-1].index;
        v20 = (float)(pt[v16].pos[0] - pt[v14].pos[0]);
        v21 = v14 * 3 + 2;
        v22 = (float)(pt[v18].pos[0] - pt[v14].pos[0]);
        v19 = &pt[v14];
        v23 = (float)(pt[v16].pos[1] - v19->pos[1]);
        v24 = (float)(pt[v15].pos[2] - pt->pos[v21]);
        v25 = (float)(pt[v17].pos[2] - pt->pos[v21]);
        v26 = (float)((float)(pt[v18].pos[1] - v19->pos[1]) * (float)(pt[v15].pos[2] - pt->pos[v21]));
        v27 = (float)((float)(pt[v17].pos[2] - pt->pos[v21]) * (float)v20);
        v7[7] = (float)((float)(pt[v18].pos[1] - v19->pos[1]) * (float)v20)
              - (float)((float)(pt[v16].pos[1] - v19->pos[1]) * (float)v22);
        v7[5] = (float)((float)v25 * (float)v23) - (float)v26;
        v7[6] = (float)((float)v24 * (float)v22) - (float)v27;
        v28 = &polygon->pol[v3];
        v29 = v28->norm[2];
        v30 = v28->norm[1];
        _FP5 = (float)((float)((float)(v28->norm[2] * v28->norm[2])
                             + (float)((float)(v28->norm[0] * v28->norm[0]) + (float)(v28->norm[1] * v28->norm[1])))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v32 = (float)((float)((float)(v28->norm[2] * v28->norm[2])
                            + (float)((float)(v28->norm[0] * v28->norm[0]) + (float)(v28->norm[1] * v28->norm[1])))
                    * (float)0.5);
        __asm { fsel      f3, f5, f6, f13 }
        v34 = __frsqrte(_FP3);
        v35 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34
                                                                                            * (float)((float)((float)(v28->norm[2] * v28->norm[2]) + (float)((float)(v28->norm[0] * v28->norm[0]) + (float)(v28->norm[1] * v28->norm[1]))) * (float)0.5))
                                                                                    * (float)v34)
                                                                            - (float)1.5)
                                                            * (float)v34)
                                                    * (float)((float)((float)(v28->norm[2] * v28->norm[2])
                                                                    + (float)((float)(v28->norm[0] * v28->norm[0])
                                                                            + (float)(v28->norm[1] * v28->norm[1])))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v34
                                                                                    * (float)((float)((float)(v28->norm[2] * v28->norm[2]) + (float)((float)(v28->norm[0] * v28->norm[0]) + (float)(v28->norm[1] * v28->norm[1])))
                                                                                            * (float)0.5))
                                                                            * (float)v34)
                                                                    - (float)1.5)
                                                    * (float)v34))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v34
                                                            * (float)((float)((float)(v28->norm[2] * v28->norm[2])
                                                                            + (float)((float)(v28->norm[0] * v28->norm[0])
                                                                                    + (float)(v28->norm[1] * v28->norm[1])))
                                                                    * (float)0.5))
                                                    * (float)v34)
                                            - (float)1.5)
                            * (float)v34));
        v36 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34 * (float)((float)((float)(v28->norm[2] * v28->norm[2]) + (float)((float)(v28->norm[0] * v28->norm[0]) + (float)(v28->norm[1] * v28->norm[1]))) * (float)0.5))
                                                                                            * (float)v34)
                                                                                    - (float)1.5)
                                                                    * (float)v34)
                                                            * (float)((float)((float)(v28->norm[2] * v28->norm[2])
                                                                            + (float)((float)(v28->norm[0] * v28->norm[0])
                                                                                    + (float)(v28->norm[1] * v28->norm[1])))
                                                                    * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)v34
                                                                                            * (float)((float)((float)(v28->norm[2] * v28->norm[2]) + (float)((float)(v28->norm[0] * v28->norm[0]) + (float)(v28->norm[1] * v28->norm[1]))) * (float)0.5))
                                                                                    * (float)v34)
                                                                            - (float)1.5)
                                                            * (float)v34))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v34
                                                                    * (float)((float)((float)(v28->norm[2] * v28->norm[2])
                                                                                    + (float)((float)(v28->norm[0] * v28->norm[0])
                                                                                            + (float)(v28->norm[1] * v28->norm[1])))
                                                                            * (float)0.5))
                                                            * (float)v34)
                                                    - (float)1.5)
                                    * (float)v34))
                    * (float)v32);
        v28->norm[0] = v28->norm[0]
                     * (float)((float)-(float)((float)((float)v36 * (float)v35) - (float)1.5) * (float)v35);
        v28->norm[1] = (float)v30 * (float)((float)-(float)((float)((float)v36 * (float)v35) - (float)1.5) * (float)v35);
        v28->norm[2] = (float)v29 * (float)((float)-(float)((float)((float)v36 * (float)v35) - (float)1.5) * (float)v35);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < polygon->count );
  }
}


// ========================================================================
// ?lwGetVertNormals@@YAXPAUst_lwPointList@@PAUst_lwPolygonList@@@Z
// EA  : 0x8287D240
// RVA : 0x0087D240
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwGetVertNormals(st_lwPointList *point, st_lwPolygonList *polygon)
{
  int v2; // r24
  int v3; // r6
  int v4; // r27
  st_lwPolygon *pol; // r11
  int v6; // r29
  st_lwPolygon *v7; // r10
  double v8; // fp0
  float *norm; // r11
  st_lwPolygon *v10; // r10
  int v11; // r28
  st_lwPointPoly *v12; // r31
  int v13; // r30
  int v14; // r7
  st_lwPolygon *v15; // r8
  double v16; // fp10
  double v17; // fp9
  double v18; // fp10
  double v19; // fp7
  double v22; // fp1
  double v23; // fp1
  double v24; // fp6

  v2 = 0;
  if ( polygon->count > 0 )
  {
    v3 = 0;
    v4 = 24;
    do
    {
      pol = polygon->pol;
      v6 = 0;
      if ( pol[v3].nverts > 0 )
      {
        v7 = &pol[v3];
        do
        {
          v8 = *(float *)((char *)pol + v4 - 4);
          norm = polygon->polVerts[v7->vindex + v6].norm;
          *norm = v8;
          norm[1] = *(float *)((char *)&polygon->pol->surf + v4);
          norm[2] = *(float *)((char *)&polygon->pol->part + v4);
          v10 = &polygon->pol[v3];
          if ( v10->surf->smooth > 0.0 && v10->smoothgrp != 511 )
          {
            v11 = 0;
            v12 = &point->ptPoly[polygon->polVerts[v10->vindex + v6].index];
            if ( v12->npols > 0 )
            {
              v13 = 0;
              do
              {
                v14 = v12->pol[v13];
                if ( v14 != v2 && polygon->pol[v3].smoothgrp == polygon->pol[v14].smoothgrp )
                {
                  v15 = polygon->pol;
                  if ( (float)((float)(v15[v3].norm[0] * v15[v14].norm[0])
                             + (float)((float)(v15[v3].norm[2] * v15[v14].norm[2])
                                     + (float)(v15[v3].norm[1] * v15[v14].norm[1]))) > (double)v15[v3].surf->smoothCos )
                  {
                    v16 = norm[1];
                    v17 = norm[2];
                    *norm = polygon->pol[v14].norm[0] + *norm;
                    norm[1] = polygon->pol[v14].norm[1] + (float)v16;
                    norm[2] = polygon->pol[v14].norm[2] + (float)v17;
                  }
                }
                ++v11;
                ++v13;
              }
              while ( v11 < v12->npols );
            }
            v18 = norm[1];
            v19 = norm[2];
            _FP4 = (float)((float)((float)(norm[2] * norm[2])
                                 + (float)((float)(*norm * *norm) + (float)(norm[1] * norm[1])))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f2, f4, f5, f0 }
            v22 = __frsqrte(_FP2);
            v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                                * (float)((float)((float)(norm[2] * norm[2]) + (float)((float)(*norm * *norm) + (float)(norm[1] * norm[1]))) * (float)0.5))
                                                                                        * (float)v22)
                                                                                - (float)1.5)
                                                                * (float)v22)
                                                        * (float)((float)((float)(norm[2] * norm[2])
                                                                        + (float)((float)(*norm * *norm)
                                                                                + (float)(norm[1] * norm[1])))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)(norm[2] * norm[2]) + (float)((float)(*norm * *norm) + (float)(norm[1] * norm[1])))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v22
                                                                * (float)((float)((float)(norm[2] * norm[2])
                                                                                + (float)((float)(*norm * *norm)
                                                                                        + (float)(norm[1] * norm[1])))
                                                                        * (float)0.5))
                                                        * (float)v22)
                                                - (float)1.5)
                                * (float)v22));
            v24 = (float)((float)-(float)((float)((float)((float)v23
                                                        * (float)((float)((float)(norm[2] * norm[2])
                                                                        + (float)((float)(*norm * *norm)
                                                                                + (float)(norm[1] * norm[1])))
                                                                * (float)0.5))
                                                * (float)v23)
                                        - (float)1.5)
                        * (float)v23);
            *norm = *norm
                  * (float)((float)-(float)((float)((float)((float)v23
                                                          * (float)((float)((float)(norm[2] * norm[2])
                                                                          + (float)((float)(*norm * *norm)
                                                                                  + (float)(norm[1] * norm[1])))
                                                                  * (float)0.5))
                                                  * (float)v23)
                                          - (float)1.5)
                          * (float)v23);
            norm[1] = (float)v18 * (float)v24;
            norm[2] = (float)v19 * (float)v24;
          }
          pol = polygon->pol;
          ++v6;
          v7 = &pol[v3];
        }
        while ( v6 < pol[v3].nverts );
      }
      ++v2;
      v4 += 40;
      ++v3;
    }
    while ( v2 < polygon->count );
  }
}


// ========================================================================
// ?lwFree@@YAXPAX@Z
// EA  : 0x8287D9B8
// RVA : 0x0087D9B8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFree(idDynamicBlock<unsigned char,60> *data)
{
  ++lwAllocator.numFrees;
  if ( data != nullptr )
  {
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32(data[-1].size);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(this: &lwAllocator, block: data - 1);
  }
}


// ========================================================================
// ?lwFreePolygons@@YAXPAUst_lwPolygonList@@@Z
// EA  : 0x8287DA10
// RVA : 0x0087DA10
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreePolygons(st_lwPolygonList *plist)
{
  st_lwPolygon *pol; // r11
  int v3; // r27
  int v4; // r29
  st_lwPolygon *v5; // r10
  int v6; // r30
  st_lwPolygon *v7; // r10
  st_lwVMapPt *vm; // r11
  st_lwVMapList *polVertVMaps; // r11
  st_lwPolVert *polVerts; // r11
  st_lwPolygon *v11; // r11
  st_lwVMapList **p_polVertVMaps; // r11
  int i; // ctr

  if ( plist != nullptr )
  {
    pol = plist->pol;
    if ( pol != nullptr )
    {
      if ( plist->polVertVMaps != nullptr )
      {
        v3 = 0;
        if ( plist->count > 0 )
        {
          v4 = 0;
          v5 = plist->pol;
          do
          {
            v6 = 0;
            if ( v5->nverts > 0 )
            {
              v7 = &pol[v4];
              do
              {
                vm = plist->polVertVMaps[v7->vindex + v6].vm;
                if ( vm != nullptr )
                {
                  ++lwAllocator.numFrees;
                  --lwAllocator.numUsedBlocks;
                  lwAllocator.usedBlockMemory -= abs32((int)vm[-2].vmap);
                  idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
                    this: &lwAllocator,
                    block: (idDynamicBlock<unsigned char,60> *)&vm[-2]);
                }
                pol = plist->pol;
                ++v6;
                v7 = &pol[v4];
              }
              while ( v6 < pol[v4].nverts );
            }
            ++v3;
            v5 = &pol[++v4];
          }
          while ( v3 < plist->count );
        }
        polVertVMaps = plist->polVertVMaps;
        ++lwAllocator.numFrees;
        if ( polVertVMaps != nullptr )
        {
          --lwAllocator.numUsedBlocks;
          lwAllocator.usedBlockMemory -= abs32(polVertVMaps[-2].nvmaps);
          idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
            this: &lwAllocator,
            block: (idDynamicBlock<unsigned char,60> *)&polVertVMaps[-2]);
        }
      }
      polVerts = plist->polVerts;
      if ( polVerts != nullptr )
      {
        ++lwAllocator.numFrees;
        --lwAllocator.numUsedBlocks;
        lwAllocator.usedBlockMemory -= abs32(polVerts[-1].index);
        idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
          this: &lwAllocator,
          block: (idDynamicBlock<unsigned char,60> *)&polVerts[-1]);
      }
      v11 = plist->pol;
      ++lwAllocator.numFrees;
      if ( v11 != nullptr )
      {
        --lwAllocator.numUsedBlocks;
        lwAllocator.usedBlockMemory -= abs32(LODWORD(v11[-1].norm[1]));
        idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
          this: &lwAllocator,
          block: (idDynamicBlock<unsigned char,60> *)&v11[-1].norm[1]);
      }
    }
    p_polVertVMaps = &plist[-1].polVertVMaps;
    for ( i = 7; i != 0; --i )
      *++p_polVertVMaps = nullptr;
  }
}


// ========================================================================
// ?lwFreePointPolygons@@YAXPAUst_lwPointList@@@Z
// EA  : 0x8287DC20
// RVA : 0x0087DC20
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreePointPolygons(st_lwPointList *point)
{
  st_lwPointPoly *ptPoly; // r11
  int *pointPolyIndices; // r11

  ptPoly = point->ptPoly;
  if ( ptPoly != nullptr )
  {
    ++lwAllocator.numFrees;
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32(ptPoly[-2].npols);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: &lwAllocator,
      block: (idDynamicBlock<unsigned char,60> *)&ptPoly[-2]);
    point->ptPoly = nullptr;
  }
  pointPolyIndices = point->pointPolyIndices;
  if ( pointPolyIndices != nullptr )
  {
    ++lwAllocator.numFrees;
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32(*(pointPolyIndices - 4));
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: &lwAllocator,
      block: (idDynamicBlock<unsigned char,60> *)pointPolyIndices - 1);
    point->pointPolyIndices = nullptr;
  }
}


// ========================================================================
// ?lwFreeTags@@YAXPAUst_lwTagList@@@Z
// EA  : 0x8287DCF8
// RVA : 0x0087DCF8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreeTags(st_lwTagList *tlist)
{
  int v2; // r28
  int v3; // r30
  char **tag; // r11
  char *v5; // r11
  char **v6; // r11

  if ( tlist != nullptr )
  {
    if ( tlist->tag != nullptr )
    {
      v2 = 0;
      if ( tlist->count > 0 )
      {
        v3 = 0;
        do
        {
          tag = tlist->tag;
          if ( tag[v3] != nullptr )
          {
            v5 = tag[v3];
            ++lwAllocator.numFrees;
            if ( v5 != nullptr )
            {
              --lwAllocator.numUsedBlocks;
              lwAllocator.usedBlockMemory -= abs32(*((_DWORD *)v5 - 4));
              idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
                this: &lwAllocator,
                block: (idDynamicBlock<unsigned char,60> *)v5 - 1);
            }
          }
          ++v2;
          ++v3;
        }
        while ( v2 < tlist->count );
      }
      v6 = tlist->tag;
      ++lwAllocator.numFrees;
      if ( v6 != nullptr )
      {
        --lwAllocator.numUsedBlocks;
        lwAllocator.usedBlockMemory -= abs32((int)*(v6 - 4));
        idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
          this: &lwAllocator,
          block: (idDynamicBlock<unsigned char,60> *)v6 - 1);
      }
    }
    tlist->count = 0;
    tlist->offset = 0;
    tlist->tag = nullptr;
  }
}


// ========================================================================
// ?lwFreePlugin@@YAXPAUst_lwPlugin@@@Z
// EA  : 0x8287DE10
// RVA : 0x0087DE10
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreePlugin(st_lwPlugin *p)
{
  char *ord; // r3
  char *name; // r3
  idDynamicBlock<unsigned char,60> *data; // r3

  if ( p != nullptr )
  {
    ord = p->ord;
    if ( ord != nullptr )
      lwFree(data: (idDynamicBlock<unsigned char,60> *)ord);
    name = p->name;
    if ( name != nullptr )
      lwFree(data: (idDynamicBlock<unsigned char,60> *)name);
    data = (idDynamicBlock<unsigned char,60> *)p->data;
    if ( data != nullptr )
      lwFree(data);
    ++lwAllocator.numFrees;
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32((int)p[-1].ord);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: &lwAllocator,
      block: (idDynamicBlock<unsigned char,60> *)&p[-1].ord);
  }
}


// ========================================================================
// ?lwFreeTexture@@YAXPAUst_lwTexture@@@Z
// EA  : 0x8287DEB8
// RVA : 0x0087DEB8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreeTexture(st_lwTexture *t)
{
  char *ord; // r3
  unsigned int type; // r11
  char *name; // r3
  idDynamicBlock<unsigned char,60> *ikey; // r3
  st_lwGradKey *key; // r3
  char *ref_object; // r3

  if ( t == nullptr )
    return;
  ord = t->ord;
  if ( ord != nullptr )
    lwFree(data: (idDynamicBlock<unsigned char,60> *)ord);
  type = t->type;
  switch ( type )
  {
    case 0x47524144u:
      key = t->param.grad.key;
      if ( key != nullptr )
        lwFree(data: (idDynamicBlock<unsigned char,60> *)key);
      ikey = (idDynamicBlock<unsigned char,60> *)t->param.grad.ikey;
      goto LABEL_14;
    case 0x494D4150u:
      ikey = (idDynamicBlock<unsigned char,60> *)t->param.imap.vmap_name;
LABEL_14:
      if ( ikey != nullptr )
        lwFree(data: ikey);
      break;
    case 0x50524F43u:
      name = t->param.proc.name;
      if ( name != nullptr )
        lwFree(data: (idDynamicBlock<unsigned char,60> *)name);
      ikey = (idDynamicBlock<unsigned char,60> *)t->param.proc.data;
      goto LABEL_14;
    default:
      break;
  }
  ref_object = t->tmap.ref_object;
  if ( ref_object != nullptr )
    lwFree(data: (idDynamicBlock<unsigned char,60> *)ref_object);
  ++lwAllocator.numFrees;
  --lwAllocator.numUsedBlocks;
  lwAllocator.usedBlockMemory -= abs32(t[-1].tmap.falloff.eindex);
  idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
    this: &lwAllocator,
    block: (idDynamicBlock<unsigned char,60> *)&t[-1].tmap.falloff.eindex);
}


// ========================================================================
// ?lwFreeSurface@@YAXPAUst_lwSurface@@@Z
// EA  : 0x8287DFC8
// RVA : 0x0087DFC8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreeSurface(st_lwSurface *surf)
{
  char *name; // r3
  char *srcname; // r3

  if ( surf != nullptr )
  {
    name = surf->name;
    if ( name != nullptr )
      lwFree(data: (idDynamicBlock<unsigned char,60> *)name);
    srcname = surf->srcname;
    if ( srcname != nullptr )
      lwFree(data: (idDynamicBlock<unsigned char,60> *)srcname);
    lwListFree(list: (void **)&surf->shader->next, freeNode: (void (*)(void))lwFreePlugin);
    lwListFree(list: (void **)&surf->color.tex->next, freeNode: (void (*)(void))lwFreeTexture);
    lwListFree(list: (void **)&surf->luminosity.tex->next, freeNode: (void (*)(void))lwFreeTexture);
    lwListFree(list: (void **)&surf->diffuse.tex->next, freeNode: (void (*)(void))lwFreeTexture);
    lwListFree(list: (void **)&surf->specularity.tex->next, freeNode: (void (*)(void))lwFreeTexture);
    lwListFree(list: (void **)&surf->glossiness.tex->next, freeNode: (void (*)(void))lwFreeTexture);
    lwListFree(list: (void **)&surf->reflection.val.tex->next, freeNode: (void (*)(void))lwFreeTexture);
    lwListFree(list: (void **)&surf->transparency.val.tex->next, freeNode: (void (*)(void))lwFreeTexture);
    lwListFree(list: (void **)&surf->eta.tex->next, freeNode: (void (*)(void))lwFreeTexture);
    lwListFree(list: (void **)&surf->translucency.tex->next, freeNode: (void (*)(void))lwFreeTexture);
    lwListFree(list: (void **)&surf->bump.tex->next, freeNode: (void (*)(void))lwFreeTexture);
    ++lwAllocator.numFrees;
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32(LODWORD(surf[-1].line.size.val));
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: &lwAllocator,
      block: (idDynamicBlock<unsigned char,60> *)&surf[-1].line.size);
  }
}


// ========================================================================
// ?lwFreeVMap@@YAXPAUst_lwVMap@@@Z
// EA  : 0x8287E110
// RVA : 0x0087E110
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreeVMap(st_lwVMap *vmap)
{
  char *name; // r3
  idDynamicBlock<unsigned char,60> *vindex; // r3
  idDynamicBlock<unsigned char,60> *pindex; // r3
  float **val; // r11

  if ( vmap != nullptr )
  {
    name = vmap->name;
    if ( name != nullptr )
      lwFree(data: (idDynamicBlock<unsigned char,60> *)name);
    vindex = (idDynamicBlock<unsigned char,60> *)vmap->vindex;
    if ( vindex != nullptr )
      lwFree(data: vindex);
    pindex = (idDynamicBlock<unsigned char,60> *)vmap->pindex;
    if ( pindex != nullptr )
      lwFree(data: pindex);
    val = vmap->val;
    if ( val != nullptr )
    {
      if ( *val != nullptr )
        lwFree(data: (idDynamicBlock<unsigned char,60> *)*val);
      lwFree(data: (idDynamicBlock<unsigned char,60> *)vmap->val);
    }
    ++lwAllocator.numFrees;
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32((int)vmap[-1].vindex);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: &lwAllocator,
      block: (idDynamicBlock<unsigned char,60> *)&vmap[-1].vindex);
  }
}


// ========================================================================
// ?lwFreeClip@@YAXPAUst_lwClip@@@Z
// EA  : 0x8287E1E0
// RVA : 0x0087E1E0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreeClip(st_lwClip *clip)
{
  unsigned int type; // r11

  if ( clip != nullptr )
  {
    lwListFree(list: (void **)&clip->ifilter->next, freeNode: (void (*)(void))lwFreePlugin);
    lwListFree(list: (void **)&clip->pfilter->next, freeNode: (void (*)(void))lwFreePlugin);
    type = clip->type;
    if ( type > 0x53544343 )
    {
      if ( type != 1398032716 && type != 1481786694 )
        goto LABEL_10;
    }
    else if ( type != 1398031171 )
    {
      if ( type != 1095649613 && type != 1230194001 )
        goto LABEL_10;
      lwFree(data: (idDynamicBlock<unsigned char,60> *)clip->source.seq.suffix);
    }
    lwFree(data: (idDynamicBlock<unsigned char,60> *)clip->source.still.name);
LABEL_10:
    ++lwAllocator.numFrees;
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32((int)clip[-1].ifilter);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: &lwAllocator,
      block: (idDynamicBlock<unsigned char,60> *)&clip[-1].ifilter);
  }
}


// ========================================================================
// ?lwFreeEnvelope@@YAXPAUst_lwEnvelope@@@Z
// EA  : 0x8287E2E8
// RVA : 0x0087E2E8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreeEnvelope(st_lwEnvelope *env)
{
  char *name; // r3

  if ( env != nullptr )
  {
    name = env->name;
    if ( name != nullptr )
      lwFree(data: (idDynamicBlock<unsigned char,60> *)name);
    lwListFree(list: (void **)&env->key->next, freeNode: (void (*)(void))lwFree);
    lwListFree(list: (void **)&env->cfilter->next, freeNode: (void (*)(void))lwFreePlugin);
    ++lwAllocator.numFrees;
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32(env[-1].behavior[0]);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: &lwAllocator,
      block: (idDynamicBlock<unsigned char,60> *)env[-1].behavior);
  }
}


// ========================================================================
// ?getbytes@@YAPAXPAVidFile@@H@Z
// EA  : 0x8287E390
// RVA : 0x0087E390
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

idDynamicBlock<unsigned char,60> *__fastcall getbytes(idFile *fp, int size)
{
  idDynamicBlock<unsigned char,60> *result; // r3
  idDynamicBlock<unsigned char,60> *v5; // r3
  idDynamicBlock<unsigned char,60> *v6; // r29
  bool v7; // zf

  if ( flen == -9999 )
    return nullptr;
  if ( size < 0
    || (v5 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: size),
        v6 = v5,
        v5 == nullptr) )
  {
    flen = -9999;
    return nullptr;
  }
  v7 = size == fp->Read(this: fp, a2: v5, a3: size);
  result = v6;
  if ( !v7 )
  {
    flen = -9999;
    lwFree(data: v6);
    return nullptr;
  }
  flen += size;
  return result;
}


// ========================================================================
// ?getS0@@YAPADPAVidFile@@@Z
// EA  : 0x8287E440
// RVA : 0x0087E440
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

idDynamicBlock<unsigned char,60> *__fastcall getS0(idFile *fp)
{
  int v3; // r3
  idFile_vtbl *v4; // r9
  int v5; // r27
  int v6; // r30
  unsigned int v7; // r30
  idDynamicBlock<unsigned char,60> *v8; // r29
  _DWORD v9[16]; // [sp+50h] [-40h] BYREF

  if ( flen == -9999 )
    return nullptr;
  v3 = fp->Tell(this: fp);
  v4 = fp->__vftable;
  v5 = v3;
  v9[0] = 0;
  v6 = 1;
  if ( v4->Read(this: fp, a2: v9, a3: 1u) == 0 )
    goto LABEL_6;
  while ( v9[0] != 0 )
  {
    v9[0] = 0;
    ++v6;
    if ( fp->Read(this: fp, a2: v9, a3: 1u) == 0 )
      goto LABEL_6;
  }
  v7 = (v6 & 1) + v6;
  v8 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: v7);
  if ( v8 != nullptr && fp->Seek(this: fp, a2: v5, a3: FS_SEEK_SET) == 0 && v7 == fp->Read(this: fp, a2: v8, a3: v7) )
  {
    flen += v7;
    return v8;
  }
  else
  {
LABEL_6:
    flen = -9999;
    return nullptr;
  }
}


// ========================================================================
// ?sgetS0@@YAPADPAPAE@Z
// EA  : 0x8287E588
// RVA : 0x0087E588
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

idDynamicBlock<unsigned char,60> *__fastcall sgetS0(unsigned __int8 **bp)
{
  _BYTE *v1; // r27
  idDynamicBlock<unsigned char,60> *result; // r3
  int v4; // r11
  int v5; // r31
  idDynamicBlock<unsigned char,60> *v6; // r30

  v1 = *bp;
  if ( flen == -9999 )
    return nullptr;
  v4 = 0;
  if ( *v1 != 0 )
  {
    do
      ++v4;
    while ( v1[v4] != 0 );
  }
  v5 = ((v4 + 1) & 1) + v4 + 1;
  result = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: v5);
  v6 = result;
  if ( result != nullptr )
  {
    memcpy(Dst: result, Src: v1, Size: v5);
    flen += v5;
    *bp += v5;
    return v6;
  }
  else
  {
    flen = -9999;
  }
  return result;
}


// ========================================================================
// add_clip
// EA  : 0x8287E648
// RVA : 0x0087E648
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

float *__fastcall add_clip(char *s, st_lwClip **clist, int *nclips)
{
  float *result; // r3
  st_lwClip *v7; // r31
  char *v8; // r3
  int v9; // r11
  st_lwClip *v10; // r11
  st_lwClip *v11; // r10

  result = (float *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 116);
  v7 = (st_lwClip *)result;
  if ( result != nullptr )
  {
    result[14] = 1.0;
    result[16] = 1.0;
    result[18] = 1.0;
    result[22] = 1.0;
    v8 = strstr(str1: s, str2: "(sequence)");
    if ( v8 != nullptr )
    {
      *(v8 - 1) = 0;
      v7->type = 1230194001;
      v7->source.seq.digits = 3;
    }
    else
    {
      v7->type = 1398032716;
    }
    v7->source.still.name = s;
    v9 = *nclips + 1;
    *nclips = v9;
    v7->index = v9;
    v10 = *clist;
    if ( *clist != nullptr )
    {
      do
      {
        v11 = v10;
        v10 = v10->next;
      }
      while ( v10 != nullptr );
      v11->next = v7;
      result = (float *)v7->index;
      v7->prev = v11;
    }
    else
    {
      *clist = v7;
      return (float *)v7->index;
    }
  }
  return result;
}


// ========================================================================
// add_tvel
// EA  : 0x8287E738
// RVA : 0x0087E738
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall add_tvel(float *pos, float *vel, st_lwEnvelope **elist, int *nenvs)
{
  int v6; // r26
  float *v7; // r25
  int v8; // r23
  idDynamicBlock<unsigned char,60> *v9; // r4
  st_lwEnvelope *v10; // r29
  idDynamicBlock<unsigned char,60> *v11; // r3
  idDynamicBlock<unsigned char,60> *v12; // r30
  idDynamicBlock<unsigned char,60> *v13; // r4
  st_lwKey *v14; // r30
  idDynamicBlock<unsigned char,60> *v15; // r3
  idDynamicBlock<unsigned char,60> *v16; // r4
  st_lwKey *v17; // r11
  idDynamicBlock<unsigned char,60> *v18; // r3
  idDynamicBlock<unsigned char,60> *v19; // r28
  int v20; // r9
  char *v21; // r3
  st_lwEnvelope *v22; // r11
  st_lwEnvelope *v23; // r10

  v6 = 0;
  v7 = pos;
  v8 = (char *)vel - (char *)pos;
  while ( 1 )
  {
    ++lwAllocator.numAllocs;
    v9 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::AllocInternal(this: &lwAllocator, num: 44);
    if ( v9 != nullptr )
    {
      v11 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::ResizeInternal(this: &lwAllocator, block: v9, num: 44);
      v12 = v11;
      if ( v11 != nullptr )
      {
        ++lwAllocator.numUsedBlocks;
        lwAllocator.usedBlockMemory += abs32(v11->size);
        if ( lwAllocator.clearAllocs )
          memset(Dst: &v11[1], Val: 0, Size: 0x2Cu);
        v10 = (st_lwEnvelope *)&v12[1];
      }
      else
      {
        v10 = nullptr;
      }
    }
    else
    {
      v10 = nullptr;
    }
    ++lwAllocator.numAllocs;
    v13 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::AllocInternal(this: &lwAllocator, num: 48);
    if ( v13 != nullptr )
    {
      v15 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::ResizeInternal(this: &lwAllocator, block: v13, num: 48);
      v14 = (st_lwKey *)v15;
      if ( v15 != nullptr )
      {
        ++lwAllocator.numUsedBlocks;
        lwAllocator.usedBlockMemory += abs32(v15->size);
        if ( lwAllocator.clearAllocs )
          memset(Dst: &v15[1], Val: 0, Size: 0x30u);
        v14 = (st_lwKey *)((char *)v14 + 16);
      }
    }
    else
    {
      v14 = nullptr;
    }
    ++lwAllocator.numAllocs;
    v16 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::AllocInternal(this: &lwAllocator, num: 48);
    if ( v16 != nullptr )
    {
      v18 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::ResizeInternal(this: &lwAllocator, block: v16, num: 48);
      v19 = v18;
      if ( v18 != nullptr )
      {
        ++lwAllocator.numUsedBlocks;
        lwAllocator.usedBlockMemory += abs32(v18->size);
        if ( lwAllocator.clearAllocs )
          memset(Dst: &v18[1], Val: 0, Size: 0x30u);
        v17 = (st_lwKey *)&v19[1];
      }
      else
      {
        v17 = nullptr;
      }
    }
    else
    {
      v17 = nullptr;
    }
    if ( v10 == nullptr || v14 == nullptr || v17 == nullptr )
      break;
    v14->next = v17;
    v14->value = *v7;
    v14->time = 0.0;
    v17->prev = v14;
    v17->value = (float)(*(float *)((char *)v7 + v8) * (float)30.0) + *v7;
    v17->shape = 1279872581;
    v17->time = 1.0;
    v14->shape = 1279872581;
    v20 = *nenvs + v6 + 1;
    v10->type = v6 + 769;
    v10->index = v20;
    v21 = (char *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 11);
    v10->name = v21;
    if ( v21 != nullptr )
    {
      strcpy(v21, "Position.X");
      v10->name[9] += v6;
    }
    v10->key = v14;
    v10->behavior[0] = 5;
    v10->nkeys = 2;
    v10->behavior[1] = 5;
    v22 = *elist;
    if ( *elist != nullptr )
    {
      do
      {
        v23 = v22;
        v22 = v22->next;
      }
      while ( v22 != nullptr );
      v23->next = v10;
      v10->prev = v23;
    }
    else
    {
      *elist = v10;
    }
    ++v6;
    ++v7;
    if ( v6 >= 3 )
    {
      *nenvs += 3;
      return v10->index - 2;
    }
  }
  return 0;
}


// ========================================================================
// get_texture
// EA  : 0x8287EA78
// RVA : 0x0087EA78
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

idDynamicBlock<unsigned char,60> *__fastcall get_texture(idDynamicBlock<unsigned char,60> *s)
{
  idDynamicBlock<unsigned char,60> *result; // r3
  st_lwTexture *v3; // r31
  int v4; // r11

  result = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 232);
  v3 = (st_lwTexture *)result;
  if ( result != nullptr )
  {
    LOWORD(result[1].node) = 1;
    *(float *)&result[10].prev = 1.0;
    *(float *)&result[10].size = 1.0;
    *(float *)&result[9].node = 1.0;
    *(float *)&result[1].prev = 1.0;
    if ( strstr(str1: (const char *)s, str2: "Image Map") != nullptr )
    {
      v3->type = 1229799760;
      if ( strstr(str1: (const char *)s, str2: "Planar") != nullptr )
      {
        v4 = 0;
      }
      else
      {
        if ( strstr(str1: (const char *)s, str2: "Cylindrical") != nullptr )
        {
          v3->param.imap.aa_strength = 1.0;
          v3->param.imap.projection = 1;
          v3->param.imap.amplitude.val = 1.0;
          lwFree(data: s);
          return (idDynamicBlock<unsigned char,60> *)v3;
        }
        if ( strstr(str1: (const char *)s, str2: "Spherical") != nullptr )
        {
          v4 = 2;
        }
        else if ( strstr(str1: (const char *)s, str2: "Cubic") != nullptr )
        {
          v4 = 3;
        }
        else
        {
          if ( strstr(str1: (const char *)s, str2: "Front") == nullptr )
          {
LABEL_14:
            v3->param.imap.aa_strength = 1.0;
            v3->param.imap.amplitude.val = 1.0;
            lwFree(data: s);
            return (idDynamicBlock<unsigned char,60> *)v3;
          }
          v4 = 4;
        }
      }
      v3->param.imap.projection = v4;
      goto LABEL_14;
    }
    v3->param.proc.name = (char *)s;
    v3->type = 1347571523;
    return (idDynamicBlock<unsigned char,60> *)v3;
  }
  return result;
}


// ========================================================================
// ?lwGetSurface5@@YAPAUst_lwSurface@@PAVidFile@@HPAUst_lwObject@@@Z
// EA  : 0x8287EBF8
// RVA : 0x0087EBF8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

st_lwSurface *__fastcall lwGetSurface5(idFile *fp, unsigned int cksize, st_lwObject *obj)
{
  st_lwObject *v4; // r30
  idDynamicBlock<unsigned char,60> *v5; // r28
  idDynamicBlock<unsigned char,60> *v6; // r20
  int v7; // r25
  idDynamicBlock<unsigned char,60> *v8; // r3
  st_lwSurface *v9; // r27
  unsigned int U4; // r31
  __int16 U2; // r3
  int v12; // r9
  unsigned __int16 v13; // r26
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  idDynamicBlock<unsigned char,60> *v17; // r3
  idDynamicBlock<unsigned char,60> *v18; // r3
  st_lwTexture *v19; // r11
  idDynamicBlock<unsigned char,60> **v20; // r10
  idDynamicBlock<unsigned char,60> *v21; // r3
  idDynamicBlock<unsigned char,60> *v22; // r3
  st_lwTexture *v23; // r11
  idDynamicBlock<unsigned char,60> **v24; // r10
  __int64 v25; // r10
  idDynamicBlock<unsigned char,60> *v26; // r3
  idDynamicBlock<unsigned char,60> *v27; // r3
  st_lwTexture *v28; // r11
  idDynamicBlock<unsigned char,60> **v29; // r10
  __int64 v30; // r10
  long double v31; // fp2
  long double v32; // fp2
  __int16 v33; // r3
  idDynamicBlock<unsigned char,60> *v34; // r3
  idDynamicBlock<unsigned char,60> *v35; // r3
  st_lwTexture *v36; // r11
  idDynamicBlock<unsigned char,60> **v37; // r10
  __int64 v38; // r10
  __int64 v39; // r10
  char *v40; // r3
  idDynamicBlock<unsigned char,60> *v41; // r3
  idDynamicBlock<unsigned char,60> *v42; // r3
  st_lwTexture *v43; // r11
  idDynamicBlock<unsigned char,60> **v44; // r10
  st_lwPlugin *shader; // r11
  idDynamicBlock<unsigned char,60> **v46; // r10
  __int64 v47; // r10
  idDynamicBlock<unsigned char,60> *v48; // r3
  idDynamicBlock<unsigned char,60> *v49; // r3
  st_lwTexture *v50; // r11
  idDynamicBlock<unsigned char,60> **v51; // r10
  float *v52; // r30
  int v53; // r31
  __int64 v54; // r10
  float *v55; // r30
  int v56; // r31
  float *v57; // r30
  int v58; // r31
  char v59; // r3
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *node; // r9
  char *S0; // r3
  __int64 v62; // r10
  float *p_next; // r30
  int v64; // r31
  idDynamicBlock<unsigned char,60> *v65; // r3
  idDynamicBlock<unsigned char,60> *texture; // r3
  st_lwTexture *tex; // r11
  idDynamicBlock<unsigned char,60> **v68; // r10
  __int64 v69; // r10
  int v70; // r31
  float *v71; // r30
  long double v72; // fp2
  long double v74; // fp2
  int v75; // [sp+54h] [-13Ch]
  __int64 v76; // [sp+A8h] [-E8h] BYREF
  float v77[18]; // [sp+B0h] [-E0h] BYREF

  v4 = obj;
  v5 = nullptr;
  v6 = nullptr;
  v7 = 0;
  v8 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 248);
  v9 = (st_lwSurface *)v8;
  if ( v8 == nullptr )
    return nullptr;
  v8[11].size = 1;
  *(float *)&v8[9].node = 1.0;
  *(float *)&v8[1].size = 0.78430998;
  flen = 0;
  *(float *)&v8[1].prev = 0.78430998;
  *(float *)&v8[1].next = 0.78430998;
  *(float *)&v8[3].size = 1.0;
  *(float *)&v8[4].next = 0.40000001;
  *(float *)&v8[8].prev = 1.0;
  v75 = fp->Tell(this: fp);
  v9->name = (char *)getS0(fp);
  U4 = getU4(fp);
  U2 = getU2(fp);
  if ( flen < 0 )
  {
Fail:
    lwFreeSurface(surf: v9);
    return nullptr;
  }
  while ( 1 )
  {
    v12 = 0;
    flen = 0;
    v13 = (U2 & 1) + U2;
    if ( U4 > 0x53544558 )
    {
      if ( U4 > 0x544F5043 )
      {
        if ( U4 > 0x5456414C )
        {
          if ( U4 > 0x564C554D )
          {
            if ( U4 != 1448300611 )
              goto LABEL_162;
            v9->specularity.val = getF4(fp);
          }
          else
          {
            switch ( U4 )
            {
              case 0x564C554Du:
                v9->luminosity.val = getF4(fp);
                break;
              case 0x5456454Cu:
                v70 = 3;
                v71 = (float *)&v76 + 1;
                v7 = 3;
                do
                {
                  *++v71 = getF4(fp);
                  --v70;
                }
                while ( v70 != 0 );
                v5[11].next = (idDynamicBlock<unsigned char,60> *)add_tvel(
                                                                    pos: (float *)&v5[10].node,
                                                                    vel: v77,
                                                                    elist: &obj->env,
                                                                    nenvs: &obj->nenvs);
                break;
              case 0x56444946u:
                v9->diffuse.val = getF4(fp);
                break;
              default:
                goto LABEL_162;
            }
          }
        }
        else if ( U4 == 1414938956 )
        {
          LODWORD(v69) = (__int16)getU2(fp);
          LODWORD(v76) = v69;
          *(float *)&v5[6].node = (float)v69 * (float)0.00390625;
        }
        else if ( U4 > 0x5453495A )
        {
          if ( U4 != 1414808920 )
            goto LABEL_162;
          v65 = getbytes(fp, size: (unsigned __int16)((U2 & 1) + U2));
          texture = get_texture(s: v65);
          tex = v9->transparency.val.tex;
          v5 = texture;
          if ( tex != nullptr )
          {
            do
            {
              v68 = (idDynamicBlock<unsigned char,60> **)tex;
              tex = tex->next;
            }
            while ( tex != nullptr );
            *v68 = texture;
            texture->prev = (idDynamicBlock<unsigned char,60> *)v68;
          }
          else
          {
            v9->transparency.val.tex = (st_lwTexture *)texture;
          }
        }
        else
        {
          switch ( U4 )
          {
            case 0x5453495Au:
              p_next = (float *)&v5[9].next;
              v64 = 3;
              v7 = 3;
              do
              {
                *++p_next = getF4(fp);
                --v64;
              }
              while ( v64 != 0 );
              break;
            case 0x5452414Eu:
              LODWORD(v62) = (__int16)getU2(fp);
              v9->transparency.val.val = (float)v62 * (float)0.00390625;
              break;
            case 0x54524546u:
              v5[14].size = (int)getbytes(fp, size: (unsigned __int16)((U2 & 1) + U2));
              break;
            default:
              goto LABEL_162;
          }
        }
      }
      else if ( U4 == 1414484035 )
      {
        *(float *)&v5[1].prev = getF4(fp);
      }
      else if ( U4 > 0x5446414C )
      {
        if ( U4 > 0x54465031 )
        {
          if ( U4 != 1414090055 )
            goto LABEL_162;
          S0 = (char *)getS0(fp);
          v5[2].prev = (idDynamicBlock<unsigned char,60> *)add_clip(s: S0, clist: &v4->clip, nclips: &v4->nclips);
        }
        else if ( U4 == 1413894193 )
        {
          if ( v5->node != (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1229799760 )
            goto LABEL_162;
          *(float *)&v5[4].prev = getF4(fp);
        }
        else if ( U4 == 1413893191 )
        {
          v59 = getU2(fp);
          v7 = (v59 & 1) != 0 ? 0 : v7;
          if ( (v59 & 2) != 0 )
            v7 = 1;
          if ( (v59 & 4) != 0 )
            v7 = 2;
          node = v5->node;
          LOWORD(v5[2].size) = v7;
          if ( node == (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1229799760 )
            v5[3].size = v7;
          else
            v5[6].next = (idDynamicBlock<unsigned char,60> *)v7;
          if ( (v59 & 8) != 0 )
            v5[14].prev = (idDynamicBlock<unsigned char,60> *)1;
          if ( (v59 & 0x10) != 0 )
            HIWORD(v5[2].size) = 1;
          if ( (v59 & 0x20) != 0 )
            v5[5].prev = (idDynamicBlock<unsigned char,60> *)1;
          if ( (v59 & 0x40) != 0 )
          {
            *(float *)&v5[4].node = 1.0;
            v5[5].size = 1;
          }
        }
        else
        {
          if ( U4 != 1413894192 || v5->node != (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1229799760 )
            goto LABEL_162;
          *(float *)&v5[3].node = getF4(fp);
        }
      }
      else if ( U4 == 1413890380 )
      {
        v57 = (float *)&v5[12].next;
        v58 = 3;
        v7 = 3;
        do
        {
          *++v57 = getF4(fp);
          --v58;
        }
        while ( v58 != 0 );
      }
      else if ( U4 > 0x54434C52 )
      {
        if ( U4 != 1413698642 )
          goto LABEL_162;
        v55 = (float *)&v5[10].next;
        v56 = 3;
        v7 = 3;
        do
        {
          *++v55 = getF4(fp);
          --v56;
        }
        while ( v56 != 0 );
      }
      else if ( U4 == 1413696594 )
      {
        if ( v5->node != (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1347571523 )
          goto LABEL_162;
        v52 = (float *)&v5[6].next;
        v53 = 3;
        v7 = 3;
        do
        {
          --v53;
          LODWORD(v54) = (unsigned __int8)getU1(fp);
          *++v52 = (float)v54 * (float)0.0039215689;
        }
        while ( v53 != 0 );
      }
      else if ( U4 == 1413562707 )
      {
        *(float *)&v5[4].node = getF4(fp);
        v5[5].size = 1;
      }
      else
      {
        if ( U4 != 1413565776 || v5->node != (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1229799760 )
          goto LABEL_162;
        *(float *)&v5[6].size = getF4(fp);
      }
    }
    else if ( U4 == 1398031704 )
    {
      v48 = getbytes(fp, size: (unsigned __int16)((U2 & 1) + U2));
      v49 = get_texture(s: v48);
      v50 = v9->specularity.tex;
      v5 = v49;
      if ( v50 != nullptr )
      {
        do
        {
          v51 = (idDynamicBlock<unsigned char,60> **)v50;
          v50 = v50->next;
        }
        while ( v50 != nullptr );
        *v51 = v49;
        v49->prev = (idDynamicBlock<unsigned char,60> *)v51;
      }
      else
      {
        v9->specularity.tex = (st_lwTexture *)v49;
      }
    }
    else if ( U4 > 0x5245464C )
    {
      if ( U4 > 0x52544558 )
      {
        if ( U4 > 0x534D414E )
        {
          if ( U4 != 1397769539 )
            goto LABEL_162;
          LODWORD(v47) = (__int16)getU2(fp);
          v9->specularity.val = (float)v47 * (float)0.00390625;
        }
        else
        {
          switch ( U4 )
          {
            case 0x534D414Eu:
              v9->smooth = getF4(fp);
              break;
            case 0x53444154u:
              v6[1].prev = getbytes(fp, size: (unsigned __int16)((U2 & 1) + U2));
              break;
            case 0x53484452u:
              v6 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 24);
              if ( v6 == nullptr )
                goto Fail;
              v6->node = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)getbytes(fp, size: v13);
              shader = v9->shader;
              if ( shader != nullptr )
              {
                do
                {
                  v46 = (idDynamicBlock<unsigned char,60> **)shader;
                  shader = shader->next;
                }
                while ( shader != nullptr );
                *v46 = v6;
                v6->prev = (idDynamicBlock<unsigned char,60> *)v46;
                ++v9->nshaders;
              }
              else
              {
                v9->shader = (st_lwPlugin *)v6;
                ++v9->nshaders;
              }
              break;
            default:
              goto LABEL_162;
          }
        }
      }
      else if ( U4 == 1381254488 )
      {
        v41 = getbytes(fp, size: (unsigned __int16)((U2 & 1) + U2));
        v42 = get_texture(s: v41);
        v43 = v9->reflection.val.tex;
        v5 = v42;
        if ( v43 != nullptr )
        {
          do
          {
            v44 = (idDynamicBlock<unsigned char,60> **)v43;
            v43 = v43->next;
          }
          while ( v43 != nullptr );
          *v44 = v42;
          v42->prev = (idDynamicBlock<unsigned char,60> *)v44;
        }
        else
        {
          v9->reflection.val.tex = (st_lwTexture *)v42;
        }
      }
      else if ( U4 > 0x52494E44 )
      {
        if ( U4 != 1381187918 )
          goto LABEL_162;
        v9->reflection.seam_angle = getF4(fp);
      }
      else
      {
        switch ( U4 )
        {
          case 0x52494E44u:
            v9->eta.val = getF4(fp);
            break;
          case 0x52464C54u:
            v9->reflection.options = (unsigned __int16)getU2(fp);
            break;
          case 0x52494D47u:
            v40 = (char *)getS0(fp);
            v9->reflection.cindex = (int)add_clip(s: v40, clist: &v4->clip, nclips: &v4->nclips);
            v9->reflection.options = 3;
            break;
          default:
            goto LABEL_162;
        }
      }
    }
    else if ( U4 == 1380271692 )
    {
      LODWORD(v39) = (__int16)getU2(fp);
      v9->reflection.val.val = (float)v39 * (float)0.00390625;
    }
    else if ( U4 > 0x44544558 )
    {
      if ( U4 > 0x4C544558 )
      {
        if ( U4 != 1280658761 )
          goto LABEL_162;
        LODWORD(v38) = (__int16)getU2(fp);
        v9->luminosity.val = (float)v38 * (float)0.00390625;
      }
      else
      {
        switch ( U4 )
        {
          case 0x4C544558u:
            v34 = getbytes(fp, size: (unsigned __int16)((U2 & 1) + U2));
            v35 = get_texture(s: v34);
            v36 = v9->luminosity.tex;
            v5 = v35;
            if ( v36 != nullptr )
            {
              do
              {
                v37 = (idDynamicBlock<unsigned char,60> **)v36;
                v36 = v36->next;
              }
              while ( v36 != nullptr );
              *v37 = v35;
              v35->prev = (idDynamicBlock<unsigned char,60> *)v37;
            }
            else
            {
              v9->luminosity.tex = (st_lwTexture *)v35;
            }
            break;
          case 0x464C4147u:
            v33 = getU2(fp);
            if ( (v33 & 4) != 0 )
              v9->smooth = 1.56207;
            if ( (v33 & 8) != 0 )
              v9->color_hilite.val = 1.0;
            if ( (v33 & 0x10) != 0 )
              v9->color_filter.val = 1.0;
            if ( (v33 & 0x80) != 0 )
              v9->dif_sharp.val = 0.5;
            if ( (v33 & 0x100) != 0 )
              v9->sideflags = 3;
            if ( (v33 & 0x200) != 0 )
              v9->add_trans.val = 1.0;
            break;
          case 0x474C4F53u:
            LODWORD(v30) = (unsigned __int16)getU2(fp);
            *(double *)&v31 = (float)v30;
            v32 = log(x: v31);
            v9->glossiness.val = (float)*(double *)&v32 * (float)0.048089873;
            break;
          default:
            goto LABEL_162;
        }
      }
    }
    else if ( U4 == 1146373464 )
    {
      v26 = getbytes(fp, size: (unsigned __int16)((U2 & 1) + U2));
      v27 = get_texture(s: v26);
      v28 = v9->diffuse.tex;
      v5 = v27;
      if ( v28 != nullptr )
      {
        do
        {
          v29 = (idDynamicBlock<unsigned char,60> **)v28;
          v28 = v28->next;
        }
        while ( v28 != nullptr );
        *v29 = v27;
        v27->prev = (idDynamicBlock<unsigned char,60> *)v29;
      }
      else
      {
        v9->diffuse.tex = (st_lwTexture *)v27;
      }
    }
    else if ( U4 > 0x43544558 )
    {
      if ( U4 != 1145652806 )
        goto LABEL_162;
      LODWORD(v25) = (__int16)getU2(fp);
      v9->diffuse.val = (float)v25 * (float)0.00390625;
    }
    else
    {
      switch ( U4 )
      {
        case 0x43544558u:
          v21 = getbytes(fp, size: (unsigned __int16)((U2 & 1) + U2));
          v22 = get_texture(s: v21);
          v23 = v9->color.tex;
          v5 = v22;
          if ( v23 != nullptr )
          {
            do
            {
              v24 = (idDynamicBlock<unsigned char,60> **)v23;
              v23 = v23->next;
            }
            while ( v23 != nullptr );
            *v24 = v22;
            v22->prev = (idDynamicBlock<unsigned char,60> *)v24;
          }
          else
          {
            v9->color.tex = (st_lwTexture *)v22;
          }
          break;
        case 0x42544558u:
          v17 = getbytes(fp, size: (unsigned __int16)((U2 & 1) + U2));
          v18 = get_texture(s: v17);
          v19 = v9->bump.tex;
          v5 = v18;
          if ( v19 != nullptr )
          {
            do
            {
              v20 = (idDynamicBlock<unsigned char,60> **)v19;
              v19 = v19->next;
            }
            while ( v19 != nullptr );
            *v20 = v18;
            v18->prev = (idDynamicBlock<unsigned char,60> *)v20;
          }
          else
          {
            v9->bump.tex = (st_lwTexture *)v18;
          }
          break;
        case 0x434F4C52u:
          LODWORD(v14) = (unsigned __int8)getU1(fp);
          v9->color.rgb[0] = (float)v14 * (float)0.0039215689;
          LODWORD(v15) = (unsigned __int8)getU1(fp);
          v9->color.rgb[1] = (float)v15 * (float)0.0039215689;
          LODWORD(v16) = (unsigned __int8)getU1(fp);
          v9->color.rgb[2] = (float)v16 * (float)0.0039215689;
          break;
        default:
          goto LABEL_162;
      }
    }
    v12 = flen;
    if ( flen < 0 )
      goto Fail;
    v4 = obj;
LABEL_162:
    if ( v12 > v13 )
      goto Fail;
    if ( v12 < v13 )
      fp->Seek(this: fp, a2: v13 - v12, a3: FS_SEEK_CUR);
    if ( cksize <= (int)fp->Tell(this: fp) - v75 )
      break;
    flen = 0;
    U4 = getU4(fp);
    U2 = getU2(fp);
    if ( flen != 6 )
      goto Fail;
  }
  *(double *)&v72 = v9->smooth;
  v74 = cos(x: v72);
  v9->smoothCos = *(double *)&v74;
  return v9;
}


// ========================================================================
// ?lwFreePoints@@YAXPAUst_lwPointList@@@Z
// EA  : 0x8287F7C8
// RVA : 0x0087F7C8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreePoints(st_lwPointList *point)
{
  st_lwPoint *pt; // r3
  int v3; // r28
  int v4; // r29
  st_lwVMapPt *vm; // r11
  st_lwVMapList *ptVMaps; // r11
  int **p_pointPolyIndices; // r11
  int i; // ctr

  if ( point != nullptr )
  {
    pt = point->pt;
    if ( pt != nullptr )
      lwFree(data: (idDynamicBlock<unsigned char,60> *)pt);
    if ( point->ptVMaps != nullptr )
    {
      v3 = 0;
      if ( point->count > 0 )
      {
        v4 = 0;
        do
        {
          vm = point->ptVMaps[v4].vm;
          if ( vm != nullptr )
          {
            ++lwAllocator.numFrees;
            --lwAllocator.numUsedBlocks;
            lwAllocator.usedBlockMemory -= abs32((int)vm[-2].vmap);
            idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
              this: &lwAllocator,
              block: (idDynamicBlock<unsigned char,60> *)&vm[-2]);
          }
          ++v3;
          ++v4;
        }
        while ( v3 < point->count );
      }
      ptVMaps = point->ptVMaps;
      ++lwAllocator.numFrees;
      if ( ptVMaps != nullptr )
      {
        --lwAllocator.numUsedBlocks;
        lwAllocator.usedBlockMemory -= abs32(ptVMaps[-2].nvmaps);
        idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
          this: &lwAllocator,
          block: (idDynamicBlock<unsigned char,60> *)&ptVMaps[-2]);
      }
    }
    lwFreePointPolygons(point);
    p_pointPolyIndices = &point[-1].pointPolyIndices;
    for ( i = 6; i != 0; --i )
      *++p_pointPolyIndices = nullptr;
  }
}


// ========================================================================
// ?lwGetPoints@@YAHPAVidFile@@HPAUst_lwPointList@@@Z
// EA  : 0x8287F900
// RVA : 0x0087F900
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetPoints(idFile *fp, int cksize, st_lwPointList *point)
{
  idDynamicBlock<unsigned char,60> *pt; // r29
  int v7; // r30
  int v8; // r11
  st_lwPoint *v9; // r3
  idDynamicBlock<unsigned char,60> *v11; // r3
  int v12; // r9
  int v13; // r7
  int v14; // r10
  float *p_node; // r11
  int v16; // r11
  float *v17; // r10
  int v18; // ctr

  if ( cksize != 1 )
  {
    pt = (idDynamicBlock<unsigned char,60> *)point->pt;
    v7 = cksize / 12;
    v8 = point->count + cksize / 12;
    point->offset = point->count;
    point->count = v8;
    v9 = (st_lwPoint *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 12 * v8);
    point->pt = v9;
    if ( v9 == nullptr )
      return 0;
    if ( pt != nullptr )
    {
      memcpy(Dst: v9, Src: pt, Size: 12 * point->offset);
      lwFree(data: pt);
    }
    memset(Dst: &point->pt[point->offset], Val: 0, Size: 12 * v7);
    v11 = getbytes(fp, size: cksize);
    if ( v11 == nullptr )
      return 0;
    v12 = 0;
    v13 = 0;
    if ( v7 >= 4 )
    {
      v14 = 0;
      p_node = (float *)&v11[-1].node;
      do
      {
        v12 += 4;
        v13 += 3;
        point->pt[v14].pos[0] = p_node[1];
        point->pt[v14].pos[1] = p_node[2];
        point->pt[v14].pos[2] = p_node[3];
        point->pt[v14 + 1].pos[0] = p_node[4];
        point->pt[v14 + 1].pos[1] = p_node[5];
        point->pt[v14 + 1].pos[2] = p_node[6];
        point->pt[v14 + 2].pos[0] = p_node[7];
        point->pt[v14 + 2].pos[1] = p_node[8];
        point->pt[v14 + 2].pos[2] = p_node[9];
        point->pt[v14 + 3].pos[0] = p_node[10];
        point->pt[v14 + 3].pos[1] = p_node[11];
        p_node += 12;
        point->pt[v14 + 3].pos[2] = *p_node;
        v14 += 4;
      }
      while ( v12 < v7 - 3 );
    }
    if ( v12 < v7 )
    {
      v16 = v12;
      v17 = (float *)&v11[v13 - 1].node;
      v18 = v7 - v12;
      do
      {
        point->pt[v16].pos[0] = v17[1];
        point->pt[v16].pos[1] = v17[2];
        v17 += 3;
        point->pt[v16++].pos[2] = *v17;
        --v18;
      }
      while ( v18 != 0 );
    }
    --lwAllocator.numUsedBlocks;
    ++lwAllocator.numFrees;
    lwAllocator.usedBlockMemory -= abs32(v11[-1].size);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(this: &lwAllocator, block: v11 - 1);
  }
  return 1;
}


// ========================================================================
// ?lwAllocPolygons@@YAHPAUst_lwPolygonList@@HH@Z
// EA  : 0x8287FB70
// RVA : 0x0087FB70
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwAllocPolygons(st_lwPolygonList *plist, int npols, int nverts)
{
  int count; // r10
  idDynamicBlock<unsigned char,60> *pol; // r28
  int v6; // r11
  st_lwPolygon *v9; // r3
  int vcount; // r10
  idDynamicBlock<unsigned char,60> *polVerts; // r30
  st_lwPolVert *v13; // r3
  int v14; // r10
  int v15; // r9
  st_lwPolygon *v16; // r11

  count = plist->count;
  pol = (idDynamicBlock<unsigned char,60> *)plist->pol;
  v6 = plist->count + npols;
  plist->count = v6;
  plist->offset = count;
  v9 = (st_lwPolygon *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 40 * v6);
  plist->pol = v9;
  if ( v9 == nullptr )
    return 0;
  if ( pol != nullptr )
  {
    memcpy(Dst: v9, Src: pol, Size: 40 * plist->offset);
    lwFree(data: pol);
  }
  memset(Dst: &plist->pol[plist->offset], Val: 0, Size: 40 * npols);
  vcount = plist->vcount;
  plist->vcount = vcount + nverts;
  plist->voffset = vcount;
  polVerts = (idDynamicBlock<unsigned char,60> *)plist->polVerts;
  v13 = (st_lwPolVert *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(
                          this: &lwAllocator,
                          num: 16 * (vcount + nverts));
  plist->polVerts = v13;
  if ( v13 == nullptr )
    return 0;
  if ( polVerts != nullptr )
  {
    memcpy(Dst: v13, Src: polVerts, Size: 16 * plist->voffset);
    lwFree(data: polVerts);
  }
  memset(Dst: &plist->polVerts[plist->voffset], Val: 0, Size: 16 * nverts);
  v14 = 1;
  if ( plist->offset > 1 )
  {
    v15 = 1;
    do
    {
      ++v14;
      v16 = &plist->pol[v15++];
      v16->vindex = v16[-1].nverts + v16[-1].vindex;
    }
    while ( v14 < plist->offset );
  }
  return 1;
}


// ========================================================================
// ?lwGetPolygons@@YAHPAVidFile@@HPAUst_lwPolygonList@@H@Z
// EA  : 0x8287FCD8
// RVA : 0x0087FCD8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetPolygons(idFile *fp, int cksize, st_lwPolygonList *plist, int ptoffset)
{
  unsigned int U4; // r27
  idDynamicBlock<unsigned char,60> *v9; // r3
  int v10; // r11
  unsigned __int8 *v11; // r30
  int v12; // r5
  unsigned int v13; // r8
  int v14; // r31
  idDynamicBlock<unsigned char,60> *v15; // r10
  __int16 v16; // r9
  int size_high; // r9
  __int16 v18; // r7
  int v19; // r9
  int i; // ctr
  st_lwPolygon *pol; // r10
  unsigned __int8 *v23; // r11
  int v24; // r9
  st_lwPolygon *v25; // r10
  st_lwPolVert *v26; // r5
  unsigned int *p_type; // r7
  int v28; // r10
  __int16 v29; // r9
  int v30; // r9
  __int16 v31; // r8
  int v32; // r8
  st_lwPolVert *v33; // r6
  int v34; // ctr
  int v35; // r9
  int v36; // r9
  int v37; // r4
  int v38; // r3
  int v39; // r9

  if ( cksize != 0 )
  {
    flen = 0;
    U4 = getU4(fp);
    v9 = getbytes(fp, size: cksize - 4);
    v10 = flen;
    v11 = (unsigned __int8 *)v9;
    if ( cksize != flen )
      return 0;
    v12 = 0;
    v13 = (unsigned int)v9 + cksize - 4;
    v14 = 0;
    v15 = v9;
    if ( (unsigned int)v9 < v13 )
    {
      do
      {
        if ( v10 == -9999 )
        {
          v16 = 0;
        }
        else
        {
          size_high = HIBYTE(v15->size);
          v10 += 2;
          v18 = BYTE1(v15->size);
          v15 = (idDynamicBlock<unsigned char,60> *)((char *)v15 + 2);
          v16 = __ROL4__(size_high, 8) | v18;
        }
        v19 = v16 & 0x3FF;
        ++v14;
        v12 += v19;
        if ( v19 > 0 )
        {
          for ( i = v19; i != 0; --i )
          {
            if ( v10 != -9999 )
            {
              if ( HIBYTE(v15->size) == 255 )
              {
                v10 += 4;
                v15 = (idDynamicBlock<unsigned char,60> *)((char *)v15 + 4);
              }
              else
              {
                v10 += 2;
                v15 = (idDynamicBlock<unsigned char,60> *)((char *)v15 + 2);
              }
              flen = v10;
            }
          }
        }
      }
      while ( (unsigned int)v15 < v13 );
      flen = v10;
    }
    if ( lwAllocPolygons(plist, npols: v14, nverts: v12) == 0 )
    {
      ++lwAllocator.numFrees;
      if ( v11 != nullptr )
      {
        --lwAllocator.numUsedBlocks;
        lwAllocator.usedBlockMemory -= abs32(*((_DWORD *)v11 - 4));
        idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
          this: &lwAllocator,
          block: (idDynamicBlock<unsigned char,60> *)v11 - 1);
      }
      lwFreePolygons(plist);
      return 0;
    }
    pol = plist->pol;
    v23 = v11;
    v24 = pol->vindex + plist->voffset;
    v25 = &pol[plist->offset];
    v26 = &plist->polVerts[v24];
    if ( v14 > 0 )
    {
      p_type = &v25->type;
      v28 = flen;
      do
      {
        if ( v28 == -9999 )
        {
          v29 = 0;
        }
        else
        {
          v30 = *v23;
          v28 += 2;
          v31 = v23[1];
          v23 += 2;
          v29 = __ROL4__(v30, 8) | v31;
        }
        v32 = v29 & 0x3FF;
        *p_type = U4;
        p_type[4] = v32;
        *(p_type - 1) = v29 & 0xFC00;
        p_type[5] = v26 - plist->polVerts;
        if ( (v29 & 0x3FF) != 0 )
        {
          v33 = v26 - 1;
          v34 = v29 & 0x3FF;
          do
          {
            if ( v28 == -9999 )
            {
              v35 = 0;
            }
            else
            {
              v36 = *v23;
              if ( v36 == 255 )
              {
                v28 += 4;
                v37 = v23[2];
                v38 = __ROL4__(v23[1], 8);
                v39 = v23[3];
                v23 += 4;
                v35 = ((v38 | v37) << 8) | v39;
              }
              else
              {
                v28 += 2;
                v35 = v23[1] | (v36 << 8);
                v23 += 2;
              }
              flen = v28;
            }
            ++v33;
            v33->index = v35 + ptoffset;
            --v34;
          }
          while ( v34 != 0 );
        }
        --v14;
        p_type += 10;
        v26 += v32;
      }
      while ( v14 != 0 );
      flen = v28;
    }
    ++lwAllocator.numFrees;
    if ( v11 != nullptr )
    {
      --lwAllocator.numUsedBlocks;
      lwAllocator.usedBlockMemory -= abs32(*((_DWORD *)v11 - 4));
      idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
        this: &lwAllocator,
        block: (idDynamicBlock<unsigned char,60> *)v11 - 1);
    }
  }
  return 1;
}


// ========================================================================
// ?lwGetPointPolygons@@YAHPAUst_lwPointList@@PAUst_lwPolygonList@@@Z
// EA  : 0x8287FFB8
// RVA : 0x0087FFB8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetPointPolygons(st_lwPointList *point, st_lwPolygonList *polygon)
{
  int v4; // r29
  int v5; // r6
  st_lwPolygon *pol; // r10
  int v7; // r8
  st_lwPolygon *v8; // r11
  int nverts; // r9
  int v10; // r11
  int v11; // r4
  int index; // r10
  idDynamicBlock<unsigned char,60> *v13; // r3
  int v15; // r9
  int v16; // r6
  int v17; // r11
  st_lwPointPoly *v18; // r7
  st_lwPointPoly *ptPoly; // r10
  int v20; // r6
  st_lwPolygon *v21; // r9
  int v22; // r7
  st_lwPolygon *v23; // r10
  int i; // r11
  int v25; // r5
  int v26; // r10

  v4 = 0;
  point->ptPoly = (st_lwPointPoly *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(
                                      this: &lwAllocator,
                                      num: 8 * point->count);
  v5 = 0;
  if ( polygon->count > 0 )
  {
    pol = polygon->pol;
    v7 = 0;
    v8 = pol;
    do
    {
      nverts = v8->nverts;
      v10 = 0;
      if ( nverts > 0 )
      {
        do
        {
          ++v4;
          v11 = polygon->pol[v7].vindex + v10++;
          index = polygon->polVerts[v11].index;
          ++point->ptPoly[index].npols;
          pol = polygon->pol;
        }
        while ( v10 < pol[v7].nverts );
      }
      ++v5;
      v8 = &pol[++v7];
    }
    while ( v5 < polygon->count );
    if ( v4 != 0 )
    {
      v13 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 4 * v4);
      point->pointPolyIndices = &v13->size;
      if ( v13 == nullptr )
        return 0;
      v15 = 0;
      v16 = 0;
      if ( point->count > 0 )
      {
        v17 = 0;
        do
        {
          v18 = &point->ptPoly[v17];
          if ( v18->npols != 0 )
          {
            v18->pol = &point->pointPolyIndices[v15];
            ptPoly = point->ptPoly;
            v15 += ptPoly[v17].npols;
            ptPoly[v17].npols = 0;
          }
          ++v16;
          ++v17;
        }
        while ( v16 < point->count );
      }
      v20 = 0;
      if ( polygon->count > 0 )
      {
        v21 = polygon->pol;
        v22 = 0;
        do
        {
          v23 = &v21[v22];
          for ( i = 0; i < v21[v22].nverts; v23 = &v21[v22] )
          {
            v25 = v23->vindex + i++;
            v26 = polygon->polVerts[v25].index;
            point->ptPoly[v26].pol[point->ptPoly[v26].npols++] = v20;
            v21 = polygon->pol;
          }
          ++v20;
          ++v22;
        }
        while ( v20 < polygon->count );
      }
    }
  }
  return 1;
}


// ========================================================================
// ?lwGetTags@@YAHPAVidFile@@HPAUst_lwTagList@@@Z
// EA  : 0x828801B0
// RVA : 0x008801B0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetTags(idFile *fp, int cksize, st_lwTagList *tlist)
{
  idDynamicBlock<unsigned char,60> *v5; // r3
  idDynamicBlock<unsigned char,60> *v6; // r27
  int v7; // r30
  idDynamicBlock<unsigned char,60> *i; // r11
  int v9; // r10
  int count; // r10
  int v11; // r11
  idDynamicBlock<unsigned char,60> *v12; // r3
  char **v13; // r29
  char **tag; // r4
  int offset; // r11
  int j; // r29
  char *v18; // r3
  int v19; // r8
  idDynamicBlock<unsigned char,60> *v20; // [sp+50h] [-40h] BYREF

  if ( cksize != 0 )
  {
    flen = 0;
    v5 = getbytes(fp, size: cksize);
    v6 = v5;
    if ( v5 == nullptr )
      return 0;
    v7 = 0;
    for ( i = v5;
          i < (idDynamicBlock<unsigned char,60> *)((char *)v5 + cksize);
          i = (idDynamicBlock<unsigned char,60> *)((char *)i + ((v9 + 1) & 1) + v9 + 1) )
    {
      v9 = 0;
      if ( HIBYTE(i->size) != 0 )
      {
        do
          ++v9;
        while ( *((_BYTE *)&i->size + v9) != 0 );
      }
      ++v7;
    }
    count = tlist->count;
    v11 = tlist->count + v7;
    tlist->count = v11;
    tlist->offset = count;
    v12 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 4 * v11);
    v13 = (char **)v12;
    if ( v12 == nullptr )
    {
      lwFree(data: v6);
      return 0;
    }
    tag = tlist->tag;
    if ( tag != nullptr )
    {
      memcpy(Dst: v12, Src: tag, Size: 4 * tlist->offset);
      lwFree(data: (idDynamicBlock<unsigned char,60> *)tlist->tag);
    }
    offset = tlist->offset;
    tlist->tag = v13;
    memset(Dst: &v13[offset], Val: 0, Size: 4 * v7);
    v20 = v6;
    for ( j = 0; j < v7; tlist->tag[v19] = v18 )
    {
      v18 = (char *)sgetS0(bp: (unsigned __int8 **)&v20);
      v19 = tlist->offset + j++;
    }
    ++lwAllocator.numFrees;
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32(v6[-1].size);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(this: &lwAllocator, block: v6 - 1);
  }
  return 1;
}


// ========================================================================
// ?lwGetTHeader@@YAHPAVidFile@@HPAUst_lwTexture@@@Z
// EA  : 0x82880340
// RVA : 0x00880340
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetTHeader(idFile *fp, unsigned int hsz, st_lwTexture *tex)
{
  idFile_vtbl *v3; // r10
  int v7; // r24
  unsigned int U4; // r30
  __int16 U2; // r3
  int v10; // r11
  unsigned __int16 v11; // r28
  _DWORD v13[32]; // [sp+50h] [-80h] BYREF

  v3 = fp->__vftable;
  flen = 0;
  v7 = ((int (*)(void))v3->Tell)();
  tex->ord = (char *)getS0(fp);
  U4 = getU4(fp);
  U2 = getU2(fp);
  if ( flen < 0 )
    return 0;
  while ( 1 )
  {
    flen = 0;
    v10 = 0;
    v11 = (U2 & 1) + U2;
    if ( U4 > 0x454E4142 )
    {
      if ( U4 == 1313163073 )
      {
        tex->negative = getU2(fp);
      }
      else
      {
        if ( U4 != 1330659651 )
          goto LABEL_14;
        tex->opac_type = getU2(fp);
        tex->opacity.val = getF4(fp);
        tex->opacity.eindex = getVX(fp);
      }
    }
    else
    {
      switch ( U4 )
      {
        case 0x454E4142u:
          tex->enabled = getU2(fp);
          break;
        case 0x41584953u:
          tex->axis = getU2(fp);
          break;
        case 0x4348414Eu:
          tex->chan = getU4(fp);
          break;
        default:
          goto LABEL_14;
      }
    }
    v10 = flen;
    if ( flen < 0 )
      return 0;
LABEL_14:
    if ( v10 > v11 )
      return 0;
    if ( v10 < v11 )
      fp->Seek(this: fp, a2: v11 - v10, a3: FS_SEEK_CUR);
    if ( hsz <= (int)fp->Tell(this: fp) - v7 )
      break;
    v13[0] = 0;
    flen = 0;
    if ( fp->Read(this: fp, a2: v13, a3: 4u) != 4 )
      goto LABEL_23;
    U4 = v13[0];
    flen += 4;
    if ( flen == -9999 )
      return 0;
    HIWORD(v13[0]) = 0;
    if ( fp->Read(this: fp, a2: v13, a3: 2u) != 2 )
    {
LABEL_23:
      flen = -9999;
      return 0;
    }
    U2 = HIWORD(v13[0]);
    flen += 2;
    if ( flen != 6 )
      return 0;
  }
  flen = fp->Tell(this: fp) - v7;
  return 1;
}


// ========================================================================
// ?lwGetTMap@@YAHPAVidFile@@HPAUst_lwTMap@@@Z
// EA  : 0x828805B0
// RVA : 0x008805B0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetTMap(idFile *fp, unsigned int tmapsz, st_lwTMap *tmap)
{
  int v6; // r24
  unsigned int U4; // r30
  __int16 U2; // r3
  int v9; // r11
  unsigned __int16 v10; // r26
  int *v11; // r29
  int m; // r30
  int *v13; // r29
  int k; // r30
  float *p_coord_sys; // r29
  int j; // r30
  int *p_eindex; // r29
  int i; // r30

  v6 = fp->Tell(this: fp);
  U4 = getU4(fp);
  U2 = getU2(fp);
  if ( flen < 0 )
    return 0;
  while ( 1 )
  {
    v9 = 0;
    flen = 0;
    v10 = (U2 & 1) + U2;
    if ( U4 > 0x4F524546 )
    {
      if ( U4 == 1380930625 )
      {
        p_eindex = &tmap->center.eindex;
        for ( i = 3; i != 0; --i )
          *(float *)++p_eindex = getF4(fp);
        tmap->rotate.eindex = getVX(fp);
      }
      else
      {
        if ( U4 != 1397316165 )
          goto LABEL_24;
        p_coord_sys = (float *)&tmap[-1].coord_sys;
        for ( j = 3; j != 0; --j )
          *++p_coord_sys = getF4(fp);
        tmap->size.eindex = getVX(fp);
      }
    }
    else
    {
      switch ( U4 )
      {
        case 0x4F524546u:
          tmap->ref_object = (char *)getS0(fp);
          break;
        case 0x434E5452u:
          v13 = &tmap->size.eindex;
          for ( k = 3; k != 0; --k )
            *(float *)++v13 = getF4(fp);
          tmap->center.eindex = getVX(fp);
          break;
        case 0x43535953u:
          tmap->coord_sys = (unsigned __int16)getU2(fp);
          break;
        case 0x46414C4Cu:
          v11 = &tmap->rotate.eindex;
          tmap->fall_type = (unsigned __int16)getU2(fp);
          for ( m = 3; m != 0; --m )
            *(float *)++v11 = getF4(fp);
          tmap->falloff.eindex = getVX(fp);
          break;
        default:
          goto LABEL_24;
      }
    }
    v9 = flen;
    if ( flen < 0 )
      return 0;
LABEL_24:
    if ( v9 > v10 )
      return 0;
    if ( v9 < v10 )
      fp->Seek(this: fp, a2: v10 - v9, a3: FS_SEEK_CUR);
    if ( tmapsz <= (int)fp->Tell(this: fp) - v6 )
      break;
    flen = 0;
    U4 = getU4(fp);
    U2 = getU2(fp);
    if ( flen != 6 )
      return 0;
  }
  flen = fp->Tell(this: fp) - v6;
  return 1;
}


// ========================================================================
// ?lwGetImageMap@@YAHPAVidFile@@HPAUst_lwTexture@@@Z
// EA  : 0x82880820
// RVA : 0x00880820
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetImageMap(idFile *fp, unsigned int rsz, st_lwTexture *tex)
{
  int v5; // r21
  unsigned int U4; // r31
  __int16 U2; // r3
  int v8; // r9
  unsigned __int16 v9; // r27
  _DWORD v11[40]; // [sp+50h] [-A0h] BYREF

  v5 = fp->Tell(this: fp);
  U4 = getU4(fp);
  U2 = getU2(fp);
  if ( flen < 0 )
    return 0;
  v11[0] = 1464991744;
  while ( 1 )
  {
    flen = 0;
    v8 = 0;
    v9 = (U2 & 1) + U2;
    if ( U4 > 0x54414D50 )
    {
      if ( U4 > 0x57524150 )
      {
        if ( U4 == 1465012296 )
        {
          tex->param.imap.wraph.val = getF4(fp);
          tex->param.imap.wraph.eindex = getVX(fp);
        }
        else
        {
          if ( U4 != 1465012311 )
            goto LABEL_32;
          tex->param.imap.wrapw.val = getF4(fp);
          tex->param.imap.wrapw.eindex = getVX(fp);
        }
      }
      else
      {
        switch ( U4 )
        {
          case 0x57524150u:
            tex->param.imap.wrapw_type = (unsigned __int16)getU2(fp);
            tex->param.imap.wraph_type = (unsigned __int16)getU2(fp);
            break;
          case 0x544D4150u:
            if ( lwGetTMap(fp, tmapsz: (unsigned __int16)((U2 & 1) + U2), tmap: &tex->tmap) == 0 )
              return 0;
            break;
          case 0x564D4150u:
            tex->param.imap.vmap_name = (char *)getS0(fp);
            break;
          default:
            goto LABEL_32;
        }
      }
    }
    else if ( U4 == 1413565776 )
    {
      tex->param.imap.amplitude.val = getF4(fp);
      tex->param.imap.amplitude.eindex = getVX(fp);
    }
    else if ( U4 > 0x50495842 )
    {
      if ( U4 == 1347571530 )
      {
        tex->param.imap.projection = (unsigned __int16)getU2(fp);
      }
      else
      {
        if ( U4 != 1398031179 )
          goto LABEL_32;
        tex->param.imap.stck.val = getF4(fp);
        tex->param.imap.stck.eindex = getVX(fp);
      }
    }
    else
    {
      switch ( U4 )
      {
        case 0x50495842u:
          tex->param.imap.pblend = (unsigned __int16)getU2(fp);
          break;
        case 0x41415354u:
          tex->param.imap.aas_flags = (unsigned __int16)getU2(fp);
          tex->param.imap.aa_strength = getF4(fp);
          break;
        case 0x41584953u:
          tex->param.imap.axis = (unsigned __int16)getU2(fp);
          break;
        case 0x494D4147u:
          tex->param.imap.cindex = getVX(fp);
          break;
        default:
          goto LABEL_32;
      }
    }
    v8 = flen;
    if ( flen < 0 )
      return 0;
LABEL_32:
    if ( v8 > v9 )
      return 0;
    if ( v8 < v9 )
      fp->Seek(this: fp, a2: v9 - v8, a3: FS_SEEK_CUR);
    if ( rsz <= (int)fp->Tell(this: fp) - v5 )
      break;
    v11[0] = 0;
    flen = 0;
    if ( fp->Read(this: fp, a2: v11, a3: 4u) != 4 )
      goto LABEL_41;
    U4 = v11[0];
    flen += 4;
    if ( flen == -9999 )
      return 0;
    HIWORD(v11[0]) = 0;
    if ( fp->Read(this: fp, a2: v11, a3: 2u) != 2 )
    {
LABEL_41:
      flen = -9999;
      return 0;
    }
    U2 = HIWORD(v11[0]);
    flen += 2;
    if ( flen != 6 )
      return 0;
  }
  flen = fp->Tell(this: fp) - v5;
  return 1;
}


// ========================================================================
// ?lwGetProcedural@@YAHPAVidFile@@HPAUst_lwTexture@@@Z
// EA  : 0x82880BC0
// RVA : 0x00880BC0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetProcedural(idFile *fp, unsigned int rsz, st_lwTexture *tex)
{
  int v6; // r24
  unsigned int U4; // r30
  __int16 U2; // r3
  int v9; // r11
  unsigned __int16 v10; // r28
  _DWORD v12[28]; // [sp+50h] [-70h] BYREF

  v6 = fp->Tell(this: fp);
  U4 = getU4(fp);
  U2 = getU2(fp);
  if ( flen < 0 )
    return 0;
  while ( 1 )
  {
    flen = 0;
    v9 = 0;
    v10 = (U2 & 1) + U2;
    if ( U4 > 0x544D4150 )
    {
      if ( U4 != 1447119957 )
        goto LABEL_16;
      tex->param.proc.value[0] = getF4(fp);
      if ( v10 >= 8u )
        tex->param.proc.value[1] = getF4(fp);
      if ( v10 >= 0xCu )
        tex->param.proc.value[2] = getF4(fp);
    }
    else
    {
      switch ( U4 )
      {
        case 0x544D4150u:
          if ( lwGetTMap(fp, tmapsz: (unsigned __int16)((U2 & 1) + U2), tmap: &tex->tmap) == 0 )
            return 0;
          break;
        case 0x41584953u:
          tex->param.proc.axis = (unsigned __int16)getU2(fp);
          break;
        case 0x46554E43u:
          tex->param.proc.name = (char *)getS0(fp);
          tex->param.proc.data = getbytes(fp, size: v10 - flen);
          break;
        default:
          goto LABEL_16;
      }
    }
    v9 = flen;
    if ( flen < 0 )
      return 0;
LABEL_16:
    if ( v9 > v10 )
      return 0;
    if ( v9 < v10 )
      fp->Seek(this: fp, a2: v10 - v9, a3: FS_SEEK_CUR);
    if ( rsz <= (int)fp->Tell(this: fp) - v6 )
      break;
    v12[0] = 0;
    flen = 0;
    if ( fp->Read(this: fp, a2: v12, a3: 4u) != 4 )
      goto LABEL_25;
    U4 = v12[0];
    flen += 4;
    if ( flen == -9999 )
      return 0;
    HIWORD(v12[0]) = 0;
    if ( fp->Read(this: fp, a2: v12, a3: 2u) != 2 )
    {
LABEL_25:
      flen = -9999;
      return 0;
    }
    U2 = HIWORD(v12[0]);
    flen += 2;
    if ( flen != 6 )
      return 0;
  }
  flen = fp->Tell(this: fp) - v6;
  return 1;
}


// ========================================================================
// ?lwGetGradient@@YAHPAVidFile@@HPAUst_lwTexture@@@Z
// EA  : 0x82880E40
// RVA : 0x00880E40
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetGradient(idFile *fp, unsigned int rsz, st_lwTexture *tex)
{
  int v5; // r28
  unsigned int U4; // r31
  __int16 U2; // r3
  int v8; // r9
  unsigned __int16 v9; // r25
  st_lwGradKey *v10; // r3
  int v11; // r28
  int v12; // r29
  unsigned int v13; // r27
  int v14; // r31
  double F4; // fp1
  int v16; // r9
  int v17; // r31
  __int16 *v18; // r3
  int v19; // r29
  int v21; // [sp+50h] [-A0h]

  v5 = fp->Tell(this: fp);
  v21 = v5;
  U4 = getU4(fp);
  U2 = getU2(fp);
  if ( flen < 0 )
    return 0;
  while ( 1 )
  {
    v8 = 0;
    flen = 0;
    v9 = (U2 & 1) + U2;
    if ( U4 > 0x494B4559 )
    {
      switch ( U4 )
      {
        case 0x494E414Du:
          tex->param.grad.itemname = (char *)getS0(fp);
          break;
        case 0x504E414Du:
          tex->param.grad.paramname = (char *)getS0(fp);
          break;
        case 0x544D4150u:
          if ( lwGetTMap(fp, tmapsz: (unsigned __int16)((U2 & 1) + U2), tmap: &tex->tmap) == 0 )
            return 0;
          break;
        default:
          goto LABEL_32;
      }
    }
    else if ( U4 == 1229669721 )
    {
      v17 = v9 >> 1;
      v18 = (__int16 *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: v9 & 0xFFFE);
      tex->param.grad.ikey = v18;
      if ( v18 == nullptr )
        return 0;
      if ( v9 >> 1 != 0 )
      {
        v19 = 0;
        do
        {
          --v17;
          tex->param.grad.ikey[v19++] = getU2(fp);
        }
        while ( v17 != 0 );
      }
    }
    else if ( U4 > 0x47525054 )
    {
      if ( U4 != 1196577620 )
        goto LABEL_32;
      tex->param.grad.start = getF4(fp);
    }
    else
    {
      switch ( U4 )
      {
        case 0x47525054u:
          tex->param.grad.repeat = (unsigned __int16)getU2(fp);
          break;
        case 0x464B4559u:
          v10 = (st_lwGradKey *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(
                                  this: &lwAllocator,
                                  num: 28 * ((unsigned __int16)((U2 & 1) + U2) / 0x1Cu));
          tex->param.grad.key = v10;
          if ( v10 == nullptr )
            return 0;
          if ( v9 / 0x1Cu != 0 )
          {
            v11 = 0;
            v12 = 3;
            v13 = v9 / 0x1Cu;
            do
            {
              v14 = 0;
              tex->param.grad.key[v11].value = getF4(fp);
              do
              {
                F4 = getF4(fp);
                v16 = 4 * (v12 + v14++);
                *(float *)((char *)&tex->param.grad.key->next + v16) = F4;
              }
              while ( v14 < 4 );
              --v13;
              ++v11;
              v12 += 7;
            }
            while ( v13 != 0 );
            v5 = v21;
          }
          break;
        case 0x4752454Eu:
          tex->param.grad.end = getF4(fp);
          break;
        default:
          goto LABEL_32;
      }
    }
    v8 = flen;
    if ( flen < 0 )
      return 0;
LABEL_32:
    if ( v8 > v9 )
      return 0;
    if ( v8 < v9 )
      fp->Seek(this: fp, a2: v9 - v8, a3: FS_SEEK_CUR);
    if ( rsz <= (int)fp->Tell(this: fp) - v5 )
      break;
    flen = 0;
    U4 = getU4(fp);
    U2 = getU2(fp);
    if ( flen != 6 )
      return 0;
  }
  flen = fp->Tell(this: fp) - v5;
  return 1;
}


// ========================================================================
// ?lwGetTexture@@YAPAUst_lwTexture@@PAVidFile@@HI@Z
// EA  : 0x82881148
// RVA : 0x00881148
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

idDynamicBlock<unsigned char,60> *__fastcall lwGetTexture(
        idFile *fp,
        int bloksz,
        idBTreeNode<idDynamicBlock<unsigned char,60>,int> *type)
{
  idDynamicBlock<unsigned char,60> *v6; // r3
  idDynamicBlock<unsigned char,60> *v7; // r31
  unsigned int U2; // r28
  idDynamicBlock<unsigned char,60> *result; // r3
  int Gradient; // r3
  bool v11; // zf

  v6 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 232);
  v7 = v6;
  if ( v6 == nullptr )
    return nullptr;
  v6->node = type;
  LOWORD(v6[1].node) = 1;
  *(float *)&v6[10].prev = 1.0;
  *(float *)&v6[10].size = 1.0;
  *(float *)&v6[9].node = 1.0;
  *(float *)&v6[1].prev = 1.0;
  U2 = (unsigned __int16)getU2(fp);
  if ( lwGetTHeader(fp, hsz: U2, tex: (st_lwTexture *)v7) == 0 )
  {
    lwFree(data: v7);
    return nullptr;
  }
  if ( type == (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1196572996 )
  {
    Gradient = lwGetGradient(fp, rsz: (unsigned __int16)(bloksz - U2 - 6), tex: (st_lwTexture *)v7);
  }
  else if ( type == (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1229799760 )
  {
    Gradient = lwGetImageMap(fp, rsz: (unsigned __int16)(bloksz - U2 - 6), tex: (st_lwTexture *)v7);
  }
  else if ( type == (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1347571523 )
  {
    Gradient = lwGetProcedural(fp, rsz: (unsigned __int16)(bloksz - U2 - 6), tex: (st_lwTexture *)v7);
  }
  else
  {
    Gradient = (_cntlzw(fp->Seek(this: fp, a2: (unsigned __int16)(bloksz - U2 - 6), a3: FS_SEEK_CUR)) & 0x20) != 0;
  }
  v11 = Gradient != 0;
  result = v7;
  if ( v11 )
  {
    flen = bloksz;
  }
  else
  {
    lwFreeTexture(t: (st_lwTexture *)v7);
    return nullptr;
  }
  return result;
}


// ========================================================================
// ?lwGetShader@@YAPAUst_lwPlugin@@PAVidFile@@H@Z
// EA  : 0x828812A8
// RVA : 0x008812A8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

st_lwPlugin *__fastcall lwGetShader(idFile *fp, unsigned int bloksz)
{
  st_lwPlugin *v4; // r26
  int v5; // r25
  int U2; // r29
  unsigned int U4; // r28
  __int16 v8; // r3
  unsigned int v9; // r29
  __int16 v10; // r3
  int v11; // r11
  unsigned __int16 v12; // r29
  bool v13; // zf
  idDynamicBlock<unsigned char,60> *v14; // r3

  v4 = (st_lwPlugin *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 24);
  if ( v4 != nullptr )
  {
    v5 = fp->Tell(this: fp);
    flen = 0;
    U2 = (unsigned __int16)getU2(fp);
    v4->ord = (char *)getS0(fp);
    U4 = getU4(fp);
    v8 = getU2(fp);
    if ( flen >= 0 )
    {
      if ( U2 > 0 )
      {
        while ( 1 )
        {
          U2 -= (unsigned __int16)((v8 & 1) + v8);
          if ( U4 == 1162756418 )
            break;
          fp->Seek(this: fp, a2: (unsigned __int16)((v8 & 1) + v8), a3: FS_SEEK_CUR);
          U4 = getU4(fp);
          v8 = getU2(fp);
          if ( U2 <= 0 )
            goto LABEL_8;
        }
        v4->flags = (unsigned __int16)getU2(fp);
      }
LABEL_8:
      v9 = getU4(fp);
      v10 = getU2(fp);
      if ( flen >= 0 )
      {
        do
        {
          v11 = 0;
          flen = 0;
          v13 = v9 != 1179995715;
          v12 = (v10 & 1) + v10;
          if ( !v13 )
          {
            v4->name = (char *)getS0(fp);
            v14 = getbytes(fp, size: v12 - flen);
            v11 = flen;
            v4->data = v14;
            if ( v11 < 0 )
              break;
          }
          if ( v11 > v12 )
            break;
          if ( v11 < v12 )
            fp->Seek(this: fp, a2: v12 - v11, a3: FS_SEEK_CUR);
          if ( bloksz <= (int)fp->Tell(this: fp) - v5 )
          {
            flen = fp->Tell(this: fp) - v5;
            return v4;
          }
          flen = 0;
          v9 = getU4(fp);
          v10 = getU2(fp);
        }
        while ( flen == 6 );
      }
    }
    lwFreePlugin(p: v4);
  }
  return nullptr;
}


// ========================================================================
// ?lwDefaultSurface@@YAPAUst_lwSurface@@XZ
// EA  : 0x828814E0
// RVA : 0x008814E0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

idDynamicBlock<unsigned char,60> *__fastcall lwDefaultSurface()
{
  idDynamicBlock<unsigned char,60> *result; // r3

  result = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 248);
  if ( result != nullptr )
  {
    result[11].size = 1;
    *(float *)&result[1].size = 0.78430998;
    *(float *)&result[1].prev = 0.78430998;
    *(float *)&result[1].next = 0.78430998;
    *(float *)&result[3].size = 1.0;
    *(float *)&result[4].next = 0.40000001;
    *(float *)&result[9].node = 1.0;
    *(float *)&result[8].prev = 1.0;
  }
  return result;
}


// ========================================================================
// ?lwGetSurface@@YAPAUst_lwSurface@@PAVidFile@@H@Z
// EA  : 0x82881560
// RVA : 0x00881560
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

st_lwSurface *__fastcall lwGetSurface(idFile *fp, unsigned int cksize)
{
  idDynamicBlock<unsigned char,60> *v3; // r3
  st_lwSurface *v4; // r29
  unsigned int U4; // r31
  __int16 U2; // r3
  unsigned __int16 v7; // r27
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v8; // r3
  st_lwTexture *Texture; // r3
  st_lwTexture *v10; // r31
  st_lwPlugin *Shader; // r4
  int v12; // r9
  unsigned int v13; // r31
  long double v14; // fp2
  long double v16; // fp2
  int v17; // [sp+54h] [-9Ch]

  v3 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 248);
  v4 = (st_lwSurface *)v3;
  if ( v3 == nullptr )
    return nullptr;
  v3[11].size = 1;
  *(float *)&v3[1].size = 0.78430998;
  *(float *)&v3[1].prev = 0.78430998;
  flen = 0;
  *(float *)&v3[1].next = 0.78430998;
  *(float *)&v3[3].size = 1.0;
  *(float *)&v3[4].next = 0.40000001;
  *(float *)&v3[9].node = 1.0;
  *(float *)&v3[8].prev = 1.0;
  v17 = fp->Tell(this: fp);
  v4->name = (char *)getS0(fp);
  v4->srcname = (char *)getS0(fp);
  U4 = getU4(fp);
  U2 = getU2(fp);
  if ( flen < 0 )
  {
Fail_1:
    lwFreeSurface(surf: v4);
    return nullptr;
  }
  while ( 1 )
  {
    flen = 0;
    v7 = (U2 & 1) + U2;
    if ( U4 > 0x5245464C )
    {
      if ( U4 > 0x534D414E )
      {
        if ( U4 > 0x5452414E )
        {
          if ( U4 == 1414680140 )
          {
            v4->translucency.val = getF4(fp);
            v4->translucency.eindex = getVX(fp);
          }
          else
          {
            if ( U4 != 1414680400 )
              goto LABEL_78;
            v4->transparency.options = (unsigned __int16)getU2(fp);
          }
        }
        else
        {
          switch ( U4 )
          {
            case 0x5452414Eu:
              v4->transparency.val.val = getF4(fp);
              v4->transparency.val.eindex = getVX(fp);
              break;
            case 0x53504543u:
              v4->specularity.val = getF4(fp);
              v4->specularity.eindex = getVX(fp);
              break;
            case 0x54494D47u:
              v4->transparency.cindex = getVX(fp);
              break;
            default:
              goto LABEL_78;
          }
        }
      }
      else if ( U4 == 1397571918 )
      {
        v4->smooth = getF4(fp);
      }
      else if ( U4 > 0x5253414E )
      {
        if ( U4 == 1397248592 )
        {
          v4->dif_sharp.val = getF4(fp);
          v4->dif_sharp.eindex = getVX(fp);
        }
        else
        {
          if ( U4 != 1397310533 )
            goto LABEL_78;
          v4->sideflags = (unsigned __int16)getU2(fp);
        }
      }
      else
      {
        switch ( U4 )
        {
          case 0x5253414Eu:
            v4->reflection.seam_angle = getF4(fp);
            break;
          case 0x52464F50u:
            v4->reflection.options = (unsigned __int16)getU2(fp);
            break;
          case 0x52494D47u:
            v4->reflection.cindex = getVX(fp);
            break;
          case 0x52494E44u:
            v4->eta.val = getF4(fp);
            v4->eta.eindex = getVX(fp);
            break;
          default:
            goto LABEL_78;
        }
      }
    }
    else if ( U4 == 1380271692 )
    {
      v4->reflection.val.val = getF4(fp);
      v4->reflection.val.eindex = getVX(fp);
    }
    else if ( U4 > 0x434C5248 )
    {
      if ( U4 > 0x4756414C )
      {
        if ( U4 == 1279872581 )
        {
          v13 = (unsigned __int16)((U2 & 1) + U2);
          v4->line.enabled = 1;
          if ( v13 >= 2 )
            v4->line.flags = getU2(fp);
          if ( v13 >= 6 )
            v4->line.size.val = getF4(fp);
          if ( v13 >= 8 )
            v4->line.size.eindex = getVX(fp);
        }
        else
        {
          if ( U4 != 1280658761 )
            goto LABEL_78;
          v4->luminosity.val = getF4(fp);
          v4->luminosity.eindex = getVX(fp);
        }
      }
      else
      {
        switch ( U4 )
        {
          case 0x4756414Cu:
            v4->glow.val = getF4(fp);
            v4->glow.eindex = getVX(fp);
            break;
          case 0x434F4C52u:
            v4->color.rgb[0] = getF4(fp);
            v4->color.rgb[1] = getF4(fp);
            v4->color.rgb[2] = getF4(fp);
            v4->color.eindex = getVX(fp);
            break;
          case 0x44494646u:
            v4->diffuse.val = getF4(fp);
            v4->diffuse.eindex = getVX(fp);
            break;
          case 0x474C4F53u:
            v4->glossiness.val = getF4(fp);
            v4->glossiness.eindex = getVX(fp);
            break;
          default:
            goto LABEL_78;
        }
      }
    }
    else if ( U4 == 1129075272 )
    {
      v4->color_hilite.val = getF4(fp);
      v4->color_hilite.eindex = getVX(fp);
    }
    else if ( U4 > 0x424C4F4B )
    {
      if ( U4 == 1112886608 )
      {
        v4->bump.val = getF4(fp);
        v4->bump.eindex = getVX(fp);
      }
      else
      {
        if ( U4 != 1129075270 )
          goto LABEL_78;
        v4->color_filter.val = getF4(fp);
        v4->color_filter.eindex = getVX(fp);
      }
    }
    else
    {
      switch ( U4 )
      {
        case 0x424C4F4Bu:
          v8 = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)getU4(fp);
          if ( (unsigned int)v8 > 0x50524F43 )
          {
            if ( v8 == (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1397245010 )
            {
              Shader = lwGetShader(fp, bloksz: v7 - 4);
              if ( Shader == nullptr )
                goto Fail_1;
              lwListInsert(
                vlist: (void **)&v4->shader,
                vitem: Shader,
                compare: (int (__fastcall *)(void *, void *))compare_shaders);
              v12 = flen + 4;
              ++v4->nshaders;
              flen = v12;
            }
          }
          else if ( v8 == (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1347571523
                 || v8 == (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1196572996
                 || v8 == (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)1229799760 )
          {
            Texture = (st_lwTexture *)lwGetTexture(fp, bloksz: v7 - 4, type: v8);
            v10 = Texture;
            if ( Texture == nullptr )
              goto Fail_1;
            if ( add_texture(surf: v4, tex: Texture) == 0 )
              lwFreeTexture(t: v10);
            flen += 4;
          }
          break;
        case 0x41445452u:
          v4->add_trans.val = getF4(fp);
          v4->add_trans.eindex = getVX(fp);
          break;
        case 0x414C5048u:
          v4->alpha_mode = (unsigned __int16)getU2(fp);
          v4->alpha = getF4(fp);
          break;
        case 0x4156414Cu:
          v4->alpha = getF4(fp);
          break;
        default:
          goto LABEL_78;
      }
    }
    if ( flen < 0 )
      goto Fail_1;
LABEL_78:
    if ( flen > v7 )
      goto Fail_1;
    if ( flen < v7 )
      fp->Seek(this: fp, a2: v7 - flen, a3: FS_SEEK_CUR);
    if ( cksize <= (int)fp->Tell(this: fp) - v17 )
      break;
    flen = 0;
    U4 = getU4(fp);
    U2 = getU2(fp);
    if ( flen != 6 )
      goto Fail_1;
  }
  *(double *)&v14 = v4->smooth;
  v16 = cos(x: v14);
  v4->smoothCos = *(double *)&v16;
  return v4;
}


// ========================================================================
// ?lwGetVMap@@YAPAUst_lwVMap@@PAVidFile@@HHHH@Z
// EA  : 0x82881C50
// RVA : 0x00881C50
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

st_lwVMap *__fastcall lwGetVMap(
        idFile *fp,
        int cksize,
        int ptoffset,
        int poloffset,
        idDynamicBlock<unsigned char,60> *perpoly)
{
  idDynamicBlock<unsigned char,60> *v7; // r24
  idDynamicBlock<unsigned char,60> *v8; // r3
  st_lwVMap *v9; // r31
  __int16 v11; // r7
  __int16 v12; // r4
  idDynamicBlock<unsigned char,60> *v13; // r3
  int v14; // r10
  unsigned __int8 *v15; // r11
  unsigned __int8 *v16; // r29
  int v17; // r27
  int v18; // r30
  bool v19; // zf
  int v20; // r28
  idDynamicBlock<unsigned char,60> *v21; // r3
  idDynamicBlock<unsigned char,60> *v22; // r3
  idDynamicBlock<unsigned char,60> *v23; // r3
  idDynamicBlock<unsigned char,60> *v24; // r3
  int v25; // r10
  int v26; // r11
  int i; // ctr
  int v28; // r9
  int v29; // r29
  double v30; // fp13
  int v31; // r9
  unsigned __int8 *v32; // r7
  int v33; // r10
  int v34; // r8
  double v35; // fp0
  char v36; // r11
  unsigned __int8 *v37; // [sp+50h] [-60h] BYREF
  float v38; // [sp+54h] [-5Ch]

  flen = 0;
  v7 = getbytes(fp, size: cksize);
  if ( v7 == nullptr )
    return nullptr;
  v8 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 44);
  v9 = (st_lwVMap *)v8;
  if ( v8 == nullptr )
  {
    lwFree(data: v7);
    return nullptr;
  }
  v8[1].next = perpoly;
  v8->node = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)v7->size;
  v11 = BYTE1(v7->prev);
  v12 = __ROL4__(HIBYTE(v7->prev), 8);
  flen = 6;
  v37 = (unsigned __int8 *)&v7->prev + 2;
  v8[1].size = (unsigned __int16)(v12 | v11);
  v13 = sgetS0(bp: &v37);
  v14 = flen;
  v15 = v37;
  v16 = (unsigned __int8 *)v7 + cksize;
  v9->name = (char *)v13;
  v17 = v14;
  v19 = v15 >= (unsigned __int8 *)v7 + cksize;
  v18 = 0;
  if ( !v19 )
  {
    v20 = 4 * v9->dim;
    do
    {
      if ( v14 != -9999 )
      {
        if ( *v15 == 255 )
        {
          v14 += 4;
          v15 += 4;
        }
        else
        {
          v14 += 2;
          v15 += 2;
        }
        v37 = v15;
        flen = v14;
      }
      if ( perpoly != nullptr )
      {
        sgetVX(bp: &v37);
        v15 = v37;
        v14 = flen;
      }
      v15 += v20;
      ++v18;
      v37 = v15;
    }
    while ( v15 < v16 );
  }
  v9->nverts = v18;
  v21 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 4 * v18);
  v9->vindex = &v21->size;
  if ( v21 == nullptr )
    goto Fail_2;
  if ( perpoly != nullptr )
  {
    v22 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 4 * v18);
    v9->pindex = &v22->size;
    if ( v22 == nullptr )
      goto Fail_2;
  }
  if ( v9->dim > 0 )
  {
    v23 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 4 * v18);
    v9->val = (float **)v23;
    if ( v23 == nullptr
      || (v24 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 4 * v9->dim * v18)) == nullptr )
    {
Fail_2:
      lwFree(data: v7);
      lwFreeVMap(vmap: v9);
      return nullptr;
    }
    v25 = 0;
    if ( v18 > 0 )
    {
      v26 = 0;
      for ( i = v18; i != 0; --i )
      {
        v28 = 4 * v9->dim * v25++;
        v9->val[v26++] = (float *)((char *)&v24->size + v28);
      }
    }
  }
  v37 = (unsigned __int8 *)v7 + v17;
  if ( v18 > 0 )
  {
    v29 = 0;
    do
    {
      v9->vindex[v29] = sgetVX(bp: &v37);
      if ( perpoly != nullptr )
        v9->pindex[v29] = sgetVX(bp: &v37);
      v31 = 0;
      if ( v9->dim > 0 )
      {
        v32 = v37;
        v33 = 0;
        v34 = flen;
        do
        {
          if ( v34 == -9999 )
            goto LABEL_36;
          v34 += 4;
          v38 = *(float *)v32;
          v32 += 4;
          v35 = v38;
          *(float *)&v37 = v38;
          if ( (LODWORD(v38) & 0x7F800000) != 0 || (v36 = 1, (LODWORD(v38) & 0x7FFFFF) == 0) )
            v36 = 0;
          if ( v36 != 0 )
LABEL_36:
            v35 = v30;
          ++v31;
          v9->val[v29][v33++] = v35;
        }
        while ( v31 < v9->dim );
        v37 = v32;
        flen = v34;
      }
      --v18;
      ++v29;
    }
    while ( v18 != 0 );
  }
  ++lwAllocator.numFrees;
  --lwAllocator.numUsedBlocks;
  lwAllocator.usedBlockMemory -= abs32(v7[-1].size);
  idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(this: &lwAllocator, block: v7 - 1);
  return v9;
}


// ========================================================================
// ?lwGetPointVMaps@@YAHPAUst_lwPointList@@PAUst_lwVMap@@@Z
// EA  : 0x82881F88
// RVA : 0x00881F88
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetPointVMaps(st_lwPointList *point, st_lwVMap *vmap)
{
  st_lwVMap *v4; // r7
  int v5; // r10
  int v6; // r11
  int v7; // r6
  int v8; // r29
  int v9; // r30
  int v10; // r11
  st_lwVMapList *v11; // r11
  st_lwVMap *v12; // r9
  int v13; // r10
  int v14; // r8
  int v15; // r6
  st_lwVMapList *v16; // r7
  st_lwVMapPt *vm; // r4
  int nvmaps; // r7

  if ( vmap == nullptr )
    return 1;
  point->ptVMaps = (st_lwVMapList *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(
                                      this: &lwAllocator,
                                      num: 8 * point->count);
  v4 = vmap;
  do
  {
    if ( v4->perpoly == 0 )
    {
      v5 = 0;
      if ( v4->nverts > 0 )
      {
        v6 = 0;
        do
        {
          ++v5;
          v7 = v4->vindex[v6++];
          ++point->ptVMaps[v7].nvmaps;
        }
        while ( v5 < v4->nverts );
      }
    }
    v4 = v4->next;
  }
  while ( v4 != nullptr );
  v8 = 0;
  if ( point->count <= 0 )
  {
LABEL_14:
    v12 = vmap;
    do
    {
      if ( v12->perpoly == 0 )
      {
        v13 = 0;
        if ( v12->nverts > 0 )
        {
          v14 = 0;
          do
          {
            v15 = v12->vindex[v14++];
            v16 = &point->ptVMaps[v15];
            vm = v16->vm;
            nvmaps = v16->nvmaps;
            vm[nvmaps].vmap = v12;
            point->ptVMaps[v15].vm[nvmaps].index = v13++;
            ++point->ptVMaps[v15].nvmaps;
          }
          while ( v13 < v12->nverts );
        }
      }
      v12 = v12->next;
    }
    while ( v12 != nullptr );
    return 1;
  }
  v9 = 0;
  while ( 1 )
  {
    v10 = point->ptVMaps[v9].nvmaps;
    if ( v10 != 0 )
      break;
LABEL_13:
    ++v8;
    ++v9;
    if ( v8 >= point->count )
      goto LABEL_14;
  }
  point->ptVMaps[v9].vm = (st_lwVMapPt *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(
                                           this: &lwAllocator,
                                           num: 8 * v10);
  v11 = &point->ptVMaps[v9];
  if ( v11->vm != nullptr )
  {
    v11->nvmaps = 0;
    goto LABEL_13;
  }
  return 0;
}


// ========================================================================
// ?lwGetPolyVMaps@@YAHPAUst_lwPolygonList@@PAUst_lwVMap@@@Z
// EA  : 0x82882130
// RVA : 0x00882130
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetPolyVMaps(st_lwPolygonList *polygon, st_lwVMap *vmap)
{
  st_lwVMap *v4; // r7
  int v5; // r30
  int v6; // r9
  int v7; // r10
  st_lwPolygon *pol; // r6
  int v9; // r3
  int v10; // r11
  int v11; // r11
  int index; // r8
  int v13; // r27
  int v14; // r29
  int i; // r30
  st_lwVMapList *v16; // r31
  idDynamicBlock<unsigned char,60> *v17; // r3
  st_lwVMap *v18; // r7
  int v19; // r30
  int v20; // r8
  int v21; // r10
  st_lwPolygon *v22; // r6
  int v23; // r31
  int v24; // r11
  st_lwVMapList *v25; // r11
  int v26; // r9

  if ( vmap != nullptr )
  {
    polygon->polVertVMaps = (st_lwVMapList *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(
                                               this: &lwAllocator,
                                               num: 8 * polygon->vcount);
    v4 = vmap;
    do
    {
      if ( v4->perpoly != 0 )
      {
        v5 = 0;
        if ( v4->nverts > 0 )
        {
          v6 = 0;
          do
          {
            v7 = 0;
            pol = polygon->pol;
            v9 = v4->pindex[v6];
            if ( pol[v9].nverts > 0 )
            {
              while ( 1 )
              {
                v10 = pol[v4->pindex[v6]].vindex + v7;
                index = polygon->polVerts[v10].index;
                v11 = v10;
                if ( v4->vindex[v6] == index )
                  break;
                if ( ++v7 >= polygon->pol[v9].nverts )
                  goto LABEL_11;
              }
              ++polygon->polVertVMaps[v11].nvmaps;
            }
LABEL_11:
            ++v5;
            ++v6;
          }
          while ( v5 < v4->nverts );
        }
      }
      v4 = v4->next;
    }
    while ( v4 != nullptr );
    v13 = 0;
    if ( polygon->count > 0 )
    {
      v14 = 0;
      do
      {
        for ( i = 0; i < polygon->pol[v14].nverts; ++i )
        {
          v16 = &polygon->polVertVMaps[polygon->pol[v14].vindex + i];
          if ( v16->nvmaps != 0 )
          {
            v17 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 8 * v16->nvmaps);
            v16->vm = (st_lwVMapPt *)v17;
            if ( v17 == nullptr )
              return 0;
            v16->nvmaps = 0;
          }
        }
        ++v13;
        ++v14;
      }
      while ( v13 < polygon->count );
    }
    v18 = vmap;
    do
    {
      if ( v18->perpoly != 0 )
      {
        v19 = 0;
        if ( v18->nverts > 0 )
        {
          v20 = 0;
          do
          {
            v21 = 0;
            v22 = polygon->pol;
            v23 = v18->pindex[v20];
            if ( v22[v23].nverts > 0 )
            {
              while ( 1 )
              {
                v24 = v22[v18->pindex[v20]].vindex + v21;
                v26 = polygon->polVerts[v24].index;
                v25 = &polygon->polVertVMaps[v24];
                if ( v18->vindex[v20] == v26 )
                  break;
                if ( ++v21 >= polygon->pol[v23].nverts )
                  goto LABEL_31;
              }
              v25->vm[v25->nvmaps].vmap = v18;
              v25->vm[v25->nvmaps++].index = v19;
            }
LABEL_31:
            ++v19;
            ++v20;
          }
          while ( v19 < v18->nverts );
        }
      }
      v18 = v18->next;
    }
    while ( v18 != nullptr );
  }
  return 1;
}


// ========================================================================
// ?lwGetClip@@YAPAUst_lwClip@@PAVidFile@@H@Z
// EA  : 0x82882400
// RVA : 0x00882400
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

st_lwClip *__fastcall lwGetClip(idFile *fp, int cksize)
{
  st_lwClip *v4; // r28
  int v5; // r15
  __int16 U2; // r3
  unsigned int type; // r10
  int v8; // r11
  unsigned __int16 v9; // r30
  int v10; // r3
  unsigned int U4; // r30
  __int16 v13; // r3
  int v14; // r9
  unsigned __int16 v15; // r26
  idDynamicBlock<unsigned char,60> *v16; // r29
  unsigned __int16 v17; // r3
  int v18; // r11
  st_lwPlugin *ifilter; // r11
  idDynamicBlock<unsigned char,60> **v20; // r10
  st_lwPlugin *pfilter; // r11
  idDynamicBlock<unsigned char,60> **v22; // r10
  int v23; // r3

  v4 = (st_lwClip *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 116);
  if ( v4 == nullptr )
    goto Fail_3;
  v4->contrast.val = 1.0;
  flen = 0;
  v4->brightness.val = 1.0;
  v4->saturation.val = 1.0;
  v4->gamma.val = 1.0;
  v5 = fp->Tell(this: fp);
  v4->index = getU4(fp);
  v4->type = getU4(fp);
  U2 = getU2(fp);
  if ( flen < 0 )
    goto Fail_3;
  type = v4->type;
  v8 = 0;
  flen = 0;
  v9 = (U2 & 1) + U2;
  if ( type > 0x53544343 )
  {
    if ( type != 1398032716 )
    {
      if ( type != 1481786694 )
        goto LABEL_15;
      v4->source.xref.index = getU4(fp);
    }
    goto LABEL_13;
  }
  switch ( type )
  {
    case 0x53544343u:
      v4->source.xref.index = (__int16)getU2(fp);
      v4->source.seq.digits = (__int16)getU2(fp);
LABEL_13:
      v4->source.still.name = (char *)getS0(fp);
LABEL_14:
      v8 = flen;
      if ( flen < 0 )
        goto Fail_3;
      break;
    case 0x414E494Du:
      v4->source.still.name = (char *)getS0(fp);
      v4->source.xref.index = (int)getS0(fp);
      v4->source.seq.digits = (int)getbytes(fp, size: v9 - flen);
      goto LABEL_14;
    case 0x49534551u:
      v4->source.seq.digits = (unsigned __int8)getU1(fp);
      v4->source.seq.flags = (unsigned __int8)getU1(fp);
      v4->source.seq.offset = (__int16)getU2(fp);
      v4->source.seq.start = (__int16)getU2(fp);
      v4->source.seq.end = (__int16)getU2(fp);
      v4->source.still.name = (char *)getS0(fp);
      v4->source.xref.index = (int)getS0(fp);
      goto LABEL_14;
    default:
      break;
  }
LABEL_15:
  if ( v8 <= v9 )
  {
    if ( v8 < v9 )
      fp->Seek(this: fp, a2: v9 - v8, a3: FS_SEEK_CUR);
    v10 = fp->Tell(this: fp);
    if ( cksize >= v10 - v5 )
    {
      if ( cksize == v10 - v5 )
        return v4;
      U4 = getU4(fp);
      v13 = getU2(fp);
      if ( flen >= 0 )
      {
        while ( 1 )
        {
          v14 = 0;
          flen = 0;
          v15 = (v13 & 1) + v13;
          if ( U4 > 0x49464C54 )
            break;
          if ( U4 == 1229343828 )
            goto LABEL_37;
          if ( U4 > 0x47414D4D )
          {
            if ( U4 != 1213547808 )
              goto LABEL_52;
            v4->hue.val = getF4(fp);
            v4->hue.eindex = getVX(fp);
          }
          else
          {
            switch ( U4 )
            {
              case 0x47414D4Du:
                v4->gamma.val = getF4(fp);
                v4->gamma.eindex = getVX(fp);
                break;
              case 0x42524954u:
                v4->brightness.val = getF4(fp);
                v4->brightness.eindex = getVX(fp);
                break;
              case 0x434F4E54u:
                v4->contrast.val = getF4(fp);
                v4->contrast.eindex = getVX(fp);
                break;
              default:
                goto LABEL_52;
            }
          }
LABEL_51:
          v14 = flen;
          if ( flen < 0 )
            goto Fail_3;
LABEL_52:
          if ( v14 <= v15 )
          {
            if ( v14 < v15 )
              fp->Seek(this: fp, a2: v15 - v14, a3: FS_SEEK_CUR);
            v23 = fp->Tell(this: fp);
            if ( cksize >= v23 - v5 )
            {
              if ( cksize == v23 - v5 )
                return v4;
              flen = 0;
              U4 = getU4(fp);
              v13 = getU2(fp);
              if ( flen == 6 )
                continue;
            }
          }
          goto Fail_3;
        }
        if ( U4 > 0x53415452 )
        {
          if ( U4 != 1414090053 )
            goto LABEL_52;
          v4->start_time = getF4(fp);
          v4->duration = getF4(fp);
          v4->frame_rate = getF4(fp);
          goto LABEL_51;
        }
        if ( U4 == 1396790354 )
        {
          v4->saturation.val = getF4(fp);
          v4->saturation.eindex = getVX(fp);
          goto LABEL_51;
        }
        if ( U4 == 1313163073 )
        {
          v4->negative = (unsigned __int16)getU2(fp);
          goto LABEL_51;
        }
        if ( U4 != 1346784340 )
          goto LABEL_52;
LABEL_37:
        v16 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 24);
        if ( v16 == nullptr )
          goto Fail_3;
        v16->node = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)getS0(fp);
        v17 = getU2(fp);
        v18 = flen;
        v16[1].size = v17;
        v16[1].prev = getbytes(fp, size: v15 - v18);
        if ( U4 == 1229343828 )
        {
          ifilter = v4->ifilter;
          if ( ifilter != nullptr )
          {
            do
            {
              v20 = (idDynamicBlock<unsigned char,60> **)ifilter;
              ifilter = ifilter->next;
            }
            while ( ifilter != nullptr );
            *v20 = v16;
            v16->prev = (idDynamicBlock<unsigned char,60> *)v20;
            ++v4->nifilters;
          }
          else
          {
            v4->ifilter = (st_lwPlugin *)v16;
            ++v4->nifilters;
          }
        }
        else
        {
          pfilter = v4->pfilter;
          if ( pfilter != nullptr )
          {
            do
            {
              v22 = (idDynamicBlock<unsigned char,60> **)pfilter;
              pfilter = pfilter->next;
            }
            while ( pfilter != nullptr );
            *v22 = v16;
            v16->prev = (idDynamicBlock<unsigned char,60> *)v22;
            ++v4->npfilters;
          }
          else
          {
            v4->pfilter = (st_lwPlugin *)v16;
            ++v4->npfilters;
          }
        }
        goto LABEL_51;
      }
    }
  }
Fail_3:
  lwFreeClip(clip: v4);
  return nullptr;
}


// ========================================================================
// ?lwGetEnvelope@@YAPAUst_lwEnvelope@@PAVidFile@@H@Z
// EA  : 0x82882978
// RVA : 0x00882978
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

st_lwEnvelope *__fastcall lwGetEnvelope(idFile *fp, unsigned int cksize)
{
  unsigned int v3; // r30
  idDynamicBlock<unsigned char,60> *v4; // r26
  st_lwEnvelope *v5; // r24
  idFile_vtbl *v6; // r10
  int v7; // r19
  unsigned int U4; // r31
  __int16 U2; // r3
  unsigned __int16 v10; // r25
  idDynamicBlock<unsigned char,60> *v11; // r31
  unsigned __int16 v12; // r3
  int v13; // r11
  st_lwPlugin *cfilter; // r11
  idDynamicBlock<unsigned char,60> **v15; // r10
  int v16; // r29
  int v17; // r31
  float *v18; // r30
  unsigned int size; // r11
  unsigned int v20; // r11
  int v21; // r11
  float *v22; // r10
  float *p_node; // r9
  double v24; // fp13
  double v25; // fp12
  double v26; // fp11
  double v27; // fp0
  double v28; // fp13
  double v29; // fp12
  int v30; // r3
  char v32; // [sp+5Ch] [-B4h] BYREF
  float v33[44]; // [sp+60h] [-B0h] BYREF

  v3 = cksize;
  v4 = nullptr;
  v5 = (st_lwEnvelope *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 44);
  if ( v5 != nullptr )
  {
    v6 = fp->__vftable;
    flen = 0;
    v7 = v6->Tell(this: fp);
    v5->index = getVX(fp);
    U4 = getU4(fp);
    U2 = getU2(fp);
    if ( flen >= 0 )
    {
      while ( 1 )
      {
        flen = 0;
        v10 = (U2 & 1) + U2;
        if ( U4 > 0x504F5354 )
          break;
        switch ( U4 )
        {
          case 0x504F5354u:
            v5->behavior[1] = (unsigned __int16)getU2(fp);
            break;
          case 0x4348414Eu:
            v11 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 24);
            if ( v11 == nullptr )
              goto Fail_4;
            v11->node = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)getS0(fp);
            v12 = getU2(fp);
            v13 = flen;
            v11[1].size = v12;
            v11[1].prev = getbytes(fp, size: v10 - v13);
            cfilter = v5->cfilter;
            if ( cfilter != nullptr )
            {
              do
              {
                v15 = (idDynamicBlock<unsigned char,60> **)cfilter;
                cfilter = cfilter->next;
              }
              while ( cfilter != nullptr );
              *v15 = v11;
              v11->prev = (idDynamicBlock<unsigned char,60> *)v15;
              ++v5->ncfilters;
            }
            else
            {
              v5->cfilter = (st_lwPlugin *)v11;
              ++v5->ncfilters;
            }
            break;
          case 0x4B455920u:
            v4 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 48);
            if ( v4 == nullptr )
              goto Fail_4;
            *(float *)&v4->node = getF4(fp);
            *(float *)&v4->next = getF4(fp);
            lwListInsert(
              vlist: (void **)&v5->key,
              vitem: v4,
              compare: (int (__fastcall *)(void *, void *))bfx::CompareSubdivElems);
            ++v5->nkeys;
            break;
          case 0x4E414D45u:
            v5->name = (char *)getS0(fp);
            break;
          default:
            break;
        }
LABEL_40:
        if ( flen > (unsigned int)v10 )
          goto Fail_4;
        if ( flen < (unsigned int)v10 )
          fp->Seek(this: fp, a2: v10 - flen, a3: FS_SEEK_CUR);
        v30 = fp->Tell(this: fp);
        if ( v3 < v30 - v7 )
          goto Fail_4;
        if ( v3 == v30 - v7 )
          return v5;
        flen = 0;
        U4 = getU4(fp);
        U2 = getU2(fp);
        if ( flen != 6 )
          goto Fail_4;
      }
      if ( U4 == 1347568928 )
      {
        v5->behavior[0] = (unsigned __int16)getU2(fp);
        goto LABEL_40;
      }
      if ( U4 != 1397768526 )
      {
        if ( U4 == 1415139397 )
          v5->type = (unsigned __int16)getU2(fp);
        goto LABEL_40;
      }
      if ( v4 == nullptr )
        goto Fail_4;
      v4[1].size = getU4(fp);
      v16 = ((v10 - 4) >> 2) + (v10 < 4u && ((v10 - 4) & 3) != 0);
      if ( v16 <= 4 )
      {
        if ( v16 <= 0 )
          goto LABEL_28;
      }
      else
      {
        v16 = 4;
      }
      v17 = v16;
      v18 = (float *)&v32;
      do
      {
        *++v18 = getF4(fp);
        --v17;
      }
      while ( v17 != 0 );
      v3 = cksize;
LABEL_28:
      size = v4[1].size;
      if ( size > 0x4845524D )
      {
        if ( size == 1413693984 )
        {
          v28 = v33[1];
          v29 = v33[2];
          *(float *)&v4[1].prev = v33[0];
          *(float *)&v4[1].next = v28;
          *(float *)&v4[1].node = v29;
        }
      }
      else if ( size == 1212502605 || (v20 = size - 1111841330) == 0 || v20 == 23 )
      {
        v21 = 0;
        if ( v16 >= 4 )
        {
          v22 = (float *)&v32;
          p_node = (float *)&v4[1].node;
          do
          {
            v21 += 4;
            v24 = v22[1];
            v25 = v22[2];
            v26 = v22[3];
            v22 += 4;
            v27 = *v22;
            p_node[1] = v24;
            p_node[2] = v25;
            p_node[3] = v26;
            p_node += 4;
            *p_node = v27;
          }
          while ( v21 < v16 - 3 );
        }
        if ( v21 < v16 )
          blkmov(a1: &v4[v21 / 4u + 2], a2: &v33[v21], a3: 4 * (v16 - v21));
      }
      goto LABEL_40;
    }
  }
Fail_4:
  lwFreeEnvelope(env: v5);
  return nullptr;
}


// ========================================================================
// ?lwFreeLayer@@YAXPAUst_lwLayer@@@Z
// EA  : 0x82882DB0
// RVA : 0x00882DB0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreeLayer(st_lwLayer *layer)
{
  char *name; // r3

  if ( layer != nullptr )
  {
    name = layer->name;
    if ( name != nullptr )
      lwFree(data: (idDynamicBlock<unsigned char,60> *)name);
    lwFreePoints(point: &layer->point);
    lwFreePolygons(plist: &layer->polygon);
    lwListFree(list: (void **)&layer->vmap->next, freeNode: (void (*)(void))lwFreeVMap);
    ++lwAllocator.numFrees;
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32((int)layer[-1].polygon.polVerts);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: &lwAllocator,
      block: (idDynamicBlock<unsigned char,60> *)&layer[-1].polygon.polVerts);
  }
}


// ========================================================================
// ?lwFreeObject@@YAXPAUst_lwObject@@@Z
// EA  : 0x82882E58
// RVA : 0x00882E58
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __fastcall lwFreeObject(st_lwObject *object)
{
  if ( object != nullptr )
  {
    lwListFree(list: (void **)&object->layer->next, freeNode: (void (*)(void))lwFreeLayer);
    lwListFree(list: (void **)&object->env->next, freeNode: (void (*)(void))lwFreeEnvelope);
    lwListFree(list: (void **)&object->clip->next, freeNode: (void (*)(void))lwFreeClip);
    lwListFree(list: (void **)&object->surf->next, freeNode: (void (*)(void))lwFreeSurface);
    lwFreeTags(tlist: &object->taglist);
    ++lwAllocator.numFrees;
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32(object[-1].nlayers);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: &lwAllocator,
      block: (idDynamicBlock<unsigned char,60> *)&object[-1].nlayers);
  }
  idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeEmptyBaseBlocks(this: &lwAllocator);
}


// ========================================================================
// ?lwGetPolygons5@@YAHPAVidFile@@HPAUst_lwPolygonList@@H@Z
// EA  : 0x82882F28
// RVA : 0x00882F28
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwGetPolygons5(idFile *fp, int cksize, st_lwPolygonList *plist, int ptoffset)
{
  idDynamicBlock<unsigned char,60> *v7; // r3
  idDynamicBlock<unsigned char,60> *v8; // r28
  idDynamicBlock<unsigned char,60> *v9; // r7
  int v10; // r5
  int v11; // r31
  idDynamicBlock<unsigned char,60> *v12; // r11
  bool v13; // zf
  int v14; // r10
  int v15; // r9
  int size_high; // r9
  __int16 v17; // r8
  __int16 v18; // r9
  st_lwPolygon *pol; // r10
  idDynamicBlock<unsigned char,60> *v21; // r11
  int v22; // r9
  st_lwPolygon *v23; // r10
  st_lwPolVert *v24; // r5
  st_lwPolygon *v25; // r6
  int v26; // r8
  unsigned __int16 v27; // r10
  int v28; // r10
  __int16 v29; // r9
  int v30; // r7
  st_lwPolVert *v31; // r9
  int v32; // ctr
  unsigned __int16 v33; // r10
  int v34; // r10
  __int16 v35; // r3
  int v36; // r10

  if ( cksize != 0 )
  {
    flen = 0;
    v7 = getbytes(fp, size: cksize);
    v8 = v7;
    if ( v7 == nullptr )
      return 0;
    v9 = (idDynamicBlock<unsigned char,60> *)((char *)v7 + cksize);
    v10 = 0;
    v12 = v7;
    v13 = v7 >= (idDynamicBlock<unsigned char,60> *)((char *)v7 + cksize);
    v11 = 0;
    if ( !v13 )
    {
      v14 = flen;
      do
      {
        if ( v14 == -9999 )
        {
          v15 = 0;
        }
        else
        {
          size_high = HIBYTE(v12->size);
          v14 += 2;
          v17 = BYTE1(v12->size);
          v12 = (idDynamicBlock<unsigned char,60> *)((char *)v12 + 2);
          v15 = (unsigned __int16)(__ROL4__(size_high, 8) | v17);
        }
        v10 += (unsigned __int16)v15;
        ++v11;
        v12 = (idDynamicBlock<unsigned char,60> *)((char *)v12 + ((2 * v15) & 0x1FFFE));
        if ( v14 == -9999 )
        {
          v18 = 0;
        }
        else
        {
          v14 += 2;
          v18 = HIWORD(v12->size);
          v12 = (idDynamicBlock<unsigned char,60> *)((char *)v12 + 2);
          flen = v14;
        }
        if ( v18 < 0 )
          v12 = (idDynamicBlock<unsigned char,60> *)((char *)v12 + 2);
      }
      while ( v12 < v9 );
      flen = v14;
    }
    if ( lwAllocPolygons(plist, npols: v11, nverts: v10) == 0 )
    {
      lwFree(data: v8);
      lwFreePolygons(plist);
      return 0;
    }
    pol = plist->pol;
    v21 = v8;
    v22 = pol->vindex + plist->voffset;
    v23 = &pol[plist->offset];
    v24 = &plist->polVerts[v22];
    if ( v11 > 0 )
    {
      v25 = v23 - 1;
      v26 = flen;
      do
      {
        if ( v26 == -9999 )
        {
          v27 = 0;
        }
        else
        {
          v28 = HIBYTE(v21->size);
          v26 += 2;
          v29 = BYTE1(v21->size);
          v21 = (idDynamicBlock<unsigned char,60> *)((char *)v21 + 2);
          v27 = __ROL4__(v28, 8) | v29;
        }
        v30 = v27;
        v25[1].type = 1178682181;
        v25[1].nverts = v27;
        v25[1].vindex = v24 - plist->polVerts;
        if ( v27 != 0 )
        {
          v31 = v24 - 1;
          v32 = v27;
          do
          {
            if ( v26 == -9999 )
            {
              v33 = 0;
            }
            else
            {
              v34 = HIBYTE(v21->size);
              v26 += 2;
              v35 = BYTE1(v21->size);
              v21 = (idDynamicBlock<unsigned char,60> *)((char *)v21 + 2);
              flen = v26;
              v33 = __ROL4__(v34, 8) | v35;
            }
            ++v31;
            v31->index = v33 + ptoffset;
            --v32;
          }
          while ( v32 != 0 );
        }
        if ( v26 == -9999 )
        {
          LOWORD(v36) = 0;
        }
        else
        {
          v26 += 2;
          LOWORD(v36) = HIWORD(v21->size);
          v21 = (idDynamicBlock<unsigned char,60> *)((char *)v21 + 2);
          flen = v26;
        }
        v36 = (__int16)v36;
        if ( (v36 & 0x8000u) != 0 )
        {
          v36 = -(__int16)v36;
          v21 = (idDynamicBlock<unsigned char,60> *)((char *)v21 + 2);
        }
        --v11;
        ++v25;
        v25->surf = (st_lwSurface *)(v36 - 1);
        v24 += v30;
      }
      while ( v11 != 0 );
      flen = v26;
    }
    ++lwAllocator.numFrees;
    --lwAllocator.numUsedBlocks;
    lwAllocator.usedBlockMemory -= abs32(v8[-1].size);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(this: &lwAllocator, block: v8 - 1);
  }
  return 1;
}


// ========================================================================
// ?lwResolvePolySurfaces@@YAHPAUst_lwPolygonList@@PAUst_lwTagList@@PAPAUst_lwSurface@@PAH@Z
// EA  : 0x828831B8
// RVA : 0x008831B8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

int __fastcall lwResolvePolySurfaces(st_lwPolygonList *polygon, st_lwTagList *tlist, st_lwSurface **surf, int *nsurfs)
{
  idDynamicBlock<unsigned char,60> *v8; // r3
  idDynamicBlock<unsigned char,60> *v9; // r28
  int v11; // r5
  int v12; // r6
  st_lwSurface *v13; // r8
  char *name; // r11
  char *v15; // r10
  int v16; // r9
  int v17; // r9
  bool v18; // zf
  int v19; // r29
  int v20; // r30
  int v21; // r11
  unsigned int v22; // r31
  idDynamicBlock<unsigned char,60> *v23; // r3
  int v24; // r11
  char *v25; // r10
  int v26; // r11
  int v27; // r9
  char *v28; // r10
  char v29; // r11
  st_lwSurface *v30; // r11
  st_lwSurface *v31; // r9
  st_lwSurface *v32; // r10

  if ( tlist->count != 0 )
  {
    v8 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 4 * tlist->count);
    v9 = v8;
    if ( v8 == nullptr )
      return 0;
    v11 = 0;
    if ( tlist->count > 0 )
    {
      v12 = 0;
      do
      {
        v13 = *surf;
        if ( *surf != nullptr )
        {
          while ( 1 )
          {
            name = v13->name;
            v15 = tlist->tag[v12];
            do
            {
              v16 = (unsigned __int8)*name;
              v18 = v16 == 0;
              v17 = v16 - (unsigned __int8)*v15;
              if ( v18 )
                break;
              ++name;
              ++v15;
            }
            while ( v17 == 0 );
            if ( v17 == 0 )
              break;
            v13 = v13->next;
            if ( v13 == nullptr )
              goto LABEL_14;
          }
          *(int *)((char *)&v8->size + v12 * 4) = (int)v13;
        }
LABEL_14:
        ++v11;
        ++v12;
      }
      while ( v11 < tlist->count );
    }
    v19 = 0;
    if ( polygon->count > 0 )
    {
      v20 = 0;
      do
      {
        v21 = (int)polygon->pol[v20].surf;
        if ( v21 < 0 || v21 > tlist->count )
          return 0;
        v22 = 4 * v21;
        if ( *(&v9->size + v21) == 0 )
        {
          v23 = lwDefaultSurface();
          *(int *)((char *)&v9->size + v22) = (int)v23;
          if ( v23 == nullptr )
            return 0;
          v24 = 0;
          v25 = tlist->tag[v22 / 4];
          if ( *v25 != 0 )
          {
            do
              ++v24;
            while ( v25[v24] != 0 );
          }
          *(_DWORD *)(*(int *)((char *)&v9->size + v22) + 8) = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(
                                                                 this: &lwAllocator,
                                                                 num: v24 + 1);
          v26 = *(_DWORD *)(*(int *)((char *)&v9->size + v22) + 8);
          if ( v26 == 0 )
            return 0;
          v27 = v26 - 1;
          v28 = tlist->tag[v22 / 4] - 1;
          do
          {
            v29 = *++v28;
            *(_BYTE *)++v27 = *v28;
          }
          while ( v29 != 0 );
          v30 = *surf;
          v31 = *(st_lwSurface **)((char *)&v9->size + v22);
          if ( *surf != nullptr )
          {
            do
            {
              v32 = v30;
              v30 = v30->next;
            }
            while ( v30 != nullptr );
            v32->next = v31;
            v31->prev = v32;
          }
          else
          {
            *surf = v31;
          }
          ++*nsurfs;
        }
        ++v19;
        polygon->pol[v20++].surf = *(st_lwSurface **)((char *)&v9->size + v22);
      }
      while ( v19 < polygon->count );
    }
    --lwAllocator.numUsedBlocks;
    ++lwAllocator.numFrees;
    lwAllocator.usedBlockMemory -= abs32(v9[-1].size);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(this: &lwAllocator, block: v9 - 1);
  }
  return 1;
}


// ========================================================================
// ?lwGetObject5@@YAPAUst_lwObject@@PBDMPAIPAH@Z
// EA  : 0x828833F8
// RVA : 0x008833F8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

st_lwObject *__fastcall lwGetObject5(
        const char *filename,
        double forceSmooth,
        unsigned int *failID,
        int *failpos,
        _DWORD *a5)
{
  idFile *v8; // r3
  idFile *v9; // r31
  int U4; // r26
  unsigned int v11; // r23
  unsigned int v12; // r3
  st_lwObject *v14; // r27
  idDynamicBlock<unsigned char,60> *v15; // r3
  idDynamicBlock<unsigned char,60> *v16; // r25
  unsigned int v17; // r3
  unsigned int v18; // r4
  st_lwSurface *Surface5; // r3
  st_lwSurface *surf; // r11
  st_lwSurface *v21; // r10
  st_lwPolygonList *v22; // r4
  st_lwPointList *v23; // r3
  st_lwPointList *v24; // r3

  v8 = fileSystem->OpenFileRead(this: fileSystem, a2: filename, a3: 1, a4: 0);
  v9 = v8;
  if ( v8 == nullptr )
    return nullptr;
  flen = 0;
  U4 = getU4(fp: v8);
  v11 = getU4(fp: v9);
  v12 = getU4(fp: v9);
  if ( flen != 12 )
  {
    ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
    return nullptr;
  }
  if ( U4 != 1179603533 || v12 != 1280790338 )
  {
    ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
    if ( a5 != nullptr )
      *a5 = 12;
    return nullptr;
  }
  v14 = (st_lwObject *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 48);
  if ( v14 == nullptr )
    goto Fail2;
  v15 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 120);
  v16 = v15;
  if ( v15 == nullptr )
    goto Fail2;
  v14->layer = (st_lwLayer *)v15;
  v14->nlayers = 1;
  U4 = getU4(fp: v9);
  v17 = getU4(fp: v9);
  if ( flen < 0 )
    goto Fail2;
  while ( 1 )
  {
    v18 = (v17 & 1) + v17;
    if ( U4 > 1397900883 )
    {
      if ( U4 != 1398100550 )
      {
LABEL_26:
        v9->Seek(this: v9, a2: v18, a3: FS_SEEK_CUR);
        goto LABEL_33;
      }
      Surface5 = lwGetSurface5(fp: v9, cksize: v18, obj: v14);
      if ( Surface5 == nullptr )
        goto Fail2;
      surf = v14->surf;
      if ( surf != nullptr )
      {
        do
        {
          v21 = surf;
          surf = surf->next;
        }
        while ( surf != nullptr );
        v21->next = Surface5;
        Surface5->prev = v21;
      }
      else
      {
        v14->surf = Surface5;
      }
      ++v14->nsurfs;
    }
    else
    {
      switch ( U4 )
      {
        case 1397900883:
          if ( lwGetTags(fp: v9, cksize: v18, tlist: &v14->taglist) == 0 )
            goto Fail2;
          break;
        case 1347310675:
          if ( lwGetPoints(fp: v9, cksize: v18, point: (st_lwPointList *)&v16[3].node) == 0 )
            goto Fail2;
          break;
        case 1347374163:
          if ( lwGetPolygons5(fp: v9, cksize: v18, plist: (st_lwPolygonList *)&v16[5].prev, ptoffset: v16[4].size) == 0 )
            goto Fail2;
          break;
        default:
          goto LABEL_26;
      }
    }
LABEL_33:
    if ( v11 <= (int)v9->Tell(this: v9) - 8 )
      break;
    flen = 0;
    U4 = getU4(fp: v9);
    v17 = getU4(fp: v9);
    if ( flen != 8 )
      goto Fail2;
  }
  ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
  v9 = nullptr;
  lwForceSmoothSurfaces(surf: v14->surf, smooth: forceSmooth);
  lwGetBoundingBox(point: (st_lwPointList *)&v16[3].node, bbox: (float *)&v16[2].prev);
  if ( lwResolvePolySurfaces(
         polygon: (st_lwPolygonList *)&v16[5].prev,
         tlist: &v14->taglist,
         surf: &v14->surf,
         nsurfs: &v14->nsurfs) != 0
    && lwGetPointPolygons(point: (st_lwPointList *)&v16[3].node, polygon: (st_lwPolygonList *)&v16[5].prev) != 0 )
  {
    lwGetPolyNormals(point: (st_lwPointList *)&v16[3].node, polygon: (st_lwPolygonList *)&v16[5].prev);
    lwGetVertNormals(point: v23, polygon: v22);
    lwFreePointPolygons(point: v24);
    return v14;
  }
Fail2:
  if ( failpos != nullptr )
    *failpos = U4;
  if ( v9 != nullptr )
  {
    if ( a5 != nullptr )
      *a5 = v9->Tell(this: v9);
    ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
  }
  lwFreeObject(object: v14);
  return nullptr;
}


// ========================================================================
// ?lwGetObject@@YAPAUst_lwObject@@PBDMPAIPAH@Z
// EA  : 0x828837A8
// RVA : 0x008837A8
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

st_lwObject *__fastcall lwGetObject(
        const char *filename,
        double forceSmooth,
        unsigned int *failID,
        int *failpos,
        _DWORD *a5)
{
  signed int v9; // r29
  idFile_Memory *v10; // r3
  idFile_Memory *v11; // r30
  int U4; // r23
  unsigned int v13; // r3
  unsigned int v14; // r29
  unsigned int *v15; // r4
  st_lwObject *v17; // r24
  idDynamicBlock<unsigned char,60> *v18; // r3
  idDynamicBlock<unsigned char,60> *v19; // r26
  unsigned int v20; // r3
  int v21; // r27
  st_lwClip *Clip; // r3
  st_lwClip *v23; // r11
  st_lwClip *v24; // r10
  float *p_size; // r28
  int i; // r29
  st_lwEnvelope *Envelope; // r3
  st_lwEnvelope *env; // r11
  st_lwEnvelope *v29; // r10
  idFile_Memory *v30; // r30
  idDynamicBlock<unsigned char,60> *v31; // r3
  st_lwLayer *layer; // r11
  idDynamicBlock<unsigned char,60> **v33; // r10
  int v34; // r10
  idDynamicBlock<unsigned char,60> *S0; // r3
  int v36; // r11
  unsigned __int16 U2; // r3
  st_lwSurface *Surface; // r3
  st_lwSurface *surf; // r11
  st_lwSurface *v40; // r10
  st_lwVMap *VMap; // r3
  idDynamicBlock<unsigned char,60> *prev; // r11
  st_lwVMap *v43; // r10
  int v44; // r3
  st_lwLayer *v45; // r29
  st_lwPolygonList *v46; // r4
  st_lwPointList *v47; // r3
  st_lwPointList *v48; // r3
  char *v49; // [sp+50h] [-B0h] BYREF
  idFile_Memory *v50; // [sp+54h] [-ACh]
  idDynamicBlockAlloc<unsigned char,1048576,16,60> *v51; // [sp+58h] [-A8h]
  unsigned int v52; // [sp+5Ch] [-A4h]

  v9 = fileSystem->ReadFile(this: fileSystem, a2: filename, a3: (void **)&v49, a4: nullptr);
  if ( v9 <= 0 )
    return nullptr;
  v10 = (idFile_Memory *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x14Cu,
                           tag: TAG_FILE,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v52 = (unsigned int)v10;
  if ( v10 != nullptr )
    v11 = idFile_Memory::idFile_Memory(this: v10, name: filename);
  else
    v11 = nullptr;
  v50 = v11;
  idFile_Memory::SetReadOnlyData(this: v11, data: v49, length: v9);
  flen = 0;
  U4 = getU4(fp: v11);
  v52 = getU4(fp: v11);
  v13 = getU4(fp: v11);
  v14 = v13;
  if ( flen != 12 )
  {
    if ( v11 != nullptr )
      ((void (__fastcall *)(idFile_Memory *, int))v11->dtr_idFile)(a1: v11, a2: 1);
    fileSystem->FreeFile(this: fileSystem, a2: v49);
    return nullptr;
  }
  if ( U4 != 1179603533 )
  {
    if ( v11 != nullptr )
      ((void (__fastcall *)(idFile_Memory *, int))v11->dtr_idFile)(a1: v11, a2: 1);
    fileSystem->FreeFile(this: fileSystem, a2: v49);
    goto LABEL_13;
  }
  if ( v13 != 1280790322 )
  {
    if ( v11 != nullptr )
      ((void (__fastcall *)(idFile_Memory *, int))v11->dtr_idFile)(a1: v11, a2: 1);
    fileSystem->FreeFile(this: fileSystem, a2: v49);
    if ( v14 == 1280790338 )
      return lwGetObject5(filename, forceSmooth, failID: v15, failpos, a5);
LABEL_13:
    if ( a5 != nullptr )
      *a5 = 12;
    return nullptr;
  }
  v51 = &lwAllocator;
  v17 = (st_lwObject *)idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 48);
  if ( v17 == nullptr )
    goto Fail_5;
  v18 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: &lwAllocator, num: 120);
  v19 = v18;
  if ( v18 == nullptr )
    goto Fail_5;
  v17->layer = (st_lwLayer *)v18;
  v17->timeStamp = v11->Timestamp(this: v11);
  U4 = getU4(fp: v11);
  v20 = getU4(fp: v11);
  if ( flen < 0 )
    goto Fail_5;
  while ( 1 )
  {
    v21 = (v20 & 1) + v20;
    if ( U4 > 1347374163 )
    {
      if ( U4 > 1413564243 )
      {
        if ( U4 != 1447903556 && U4 != 1447903568 )
        {
LABEL_87:
          v11->Seek(this: v11, a2: (v20 & 1) + v20, a3: FS_SEEK_CUR);
          goto LABEL_94;
        }
        VMap = lwGetVMap(
                 fp: v11,
                 cksize: (v20 & 1) + v20,
                 ptoffset: v19[4].size,
                 poloffset: (int)v19[5].next,
                 perpoly: (idDynamicBlock<unsigned char,60> *)((_cntlzw(1447903556 - U4) & 0x20) != 0));
        if ( VMap == nullptr )
          goto Fail_5;
        prev = v19[7].prev;
        if ( prev != nullptr )
        {
          do
          {
            v43 = (st_lwVMap *)prev;
            prev = (idDynamicBlock<unsigned char,60> *)prev->size;
          }
          while ( prev != nullptr );
          v43->next = VMap;
          VMap->prev = v43;
        }
        else
        {
          v19[7].prev = (idDynamicBlock<unsigned char,60> *)VMap;
        }
        ++v19[7].size;
      }
      else
      {
        switch ( U4 )
        {
          case 1413564243:
            if ( lwGetTags(fp: v11, cksize: (v20 & 1) + v20, tlist: &v17->taglist) == 0 )
              goto Fail_5;
            break;
          case 1347699015:
            if ( lwGetPolygonTags(
                   fp: v11,
                   cksize: (v20 & 1) + v20,
                   tlist: &v17->taglist,
                   plist: (st_lwPolygonList *)&v19[5].prev) == 0 )
              goto Fail_5;
            break;
          case 1398100550:
            Surface = lwGetSurface(fp: v11, cksize: (v20 & 1) + v20);
            if ( Surface == nullptr )
              goto Fail_5;
            surf = v17->surf;
            if ( surf != nullptr )
            {
              do
              {
                v40 = surf;
                surf = surf->next;
              }
              while ( surf != nullptr );
              v40->next = Surface;
              Surface->prev = v40;
              ++v17->nsurfs;
            }
            else
            {
              v17->surf = Surface;
              ++v17->nsurfs;
            }
            break;
          default:
            goto LABEL_87;
        }
      }
    }
    else if ( U4 == 1347374163 )
    {
      if ( lwGetPolygons(
             fp: v11,
             cksize: (v20 & 1) + v20,
             plist: (st_lwPolygonList *)&v19[5].prev,
             ptoffset: v19[4].size) == 0 )
        goto Fail_5;
    }
    else if ( U4 > 1162761804 )
    {
      if ( U4 == 1279351122 )
      {
        if ( v17->nlayers > 0 )
        {
          v31 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(this: v51, num: 120);
          v19 = v31;
          if ( v31 == nullptr )
            goto Fail_5;
          layer = v17->layer;
          if ( layer != nullptr )
          {
            do
            {
              v33 = (idDynamicBlock<unsigned char,60> **)layer;
              layer = layer->next;
            }
            while ( layer != nullptr );
            *v33 = v31;
            v31->prev = (idDynamicBlock<unsigned char,60> *)v33;
          }
          else
          {
            v17->layer = (st_lwLayer *)v31;
          }
        }
        v34 = v17->nlayers + 1;
        flen = 0;
        v17->nlayers = v34;
        v19->node = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)(unsigned __int16)getU2(fp: v11);
        v19[1].prev = (idDynamicBlock<unsigned char,60> *)(unsigned __int16)getU2(fp: v11);
        *(float *)&v19[1].next = getF4(fp: v11);
        *(float *)&v19[1].node = getF4(fp: v11);
        *(float *)&v19[2].size = getF4(fp: v11);
        S0 = getS0(fp: v11);
        v36 = flen;
        v19->next = S0;
        if ( v36 < 0 || v36 > v21 )
          goto Fail_5;
        if ( v36 <= v21 - 2 )
        {
          U2 = getU2(fp: v11);
          v36 = flen;
          v19[1].size = U2;
        }
        if ( v36 < v21 )
          v11->Seek(this: v11, a2: v21 - v36, a3: FS_SEEK_CUR);
      }
      else
      {
        if ( U4 != 1347310675 )
          goto LABEL_87;
        if ( lwGetPoints(fp: v11, cksize: (v20 & 1) + v20, point: (st_lwPointList *)&v19[3].node) == 0 )
          goto Fail_5;
      }
    }
    else
    {
      switch ( U4 )
      {
        case 1162761804:
          Envelope = lwGetEnvelope(fp: v11, cksize: (v20 & 1) + v20);
          if ( Envelope == nullptr )
            goto Fail_5;
          env = v17->env;
          if ( env != nullptr )
          {
            do
            {
              v29 = env;
              env = env->next;
            }
            while ( env != nullptr );
            v29->next = Envelope;
            Envelope->prev = v29;
            ++v17->nenvs;
          }
          else
          {
            v17->env = Envelope;
            ++v17->nenvs;
          }
          break;
        case 1111641944:
          p_size = (float *)&v19[2].size;
          flen = 0;
          for ( i = 6; i != 0; --i )
            *++p_size = getF4(fp: v11);
          if ( flen < 0 || flen > v21 )
            goto Fail_5;
          if ( flen < v21 )
            v11->Seek(this: v11, a2: v21 - flen, a3: FS_SEEK_CUR);
          break;
        case 1129072976:
          Clip = lwGetClip(fp: v11, cksize: (v20 & 1) + v20);
          if ( Clip == nullptr )
            goto Fail_5;
          v23 = v17->clip;
          if ( v23 != nullptr )
          {
            do
            {
              v24 = v23;
              v23 = v23->next;
            }
            while ( v23 != nullptr );
            v24->next = Clip;
            Clip->prev = v24;
            ++v17->nclips;
          }
          else
          {
            v17->clip = Clip;
            ++v17->nclips;
          }
          break;
        default:
          goto LABEL_87;
      }
    }
LABEL_94:
    v44 = v11->Tell(this: v11);
    if ( v52 <= v44 - 8 )
      break;
    flen = 0;
    U4 = getU4(fp: v11);
    v20 = getU4(fp: v11);
    if ( flen != 8 )
      goto Fail_5;
  }
  ((void (__fastcall *)(idFile_Memory *, int))v11->dtr_idFile)(a1: v11, a2: 1);
  v50 = nullptr;
  fileSystem->FreeFile(this: fileSystem, a2: v49);
  v49 = nullptr;
  if ( v17->nlayers == 0 )
    v17->nlayers = 1;
  lwForceSmoothSurfaces(surf: v17->surf, smooth: forceSmooth);
  v45 = v17->layer;
  if ( v45 == nullptr )
    return v17;
  while ( 1 )
  {
    lwGetBoundingBox(point: &v45->point, bbox: v45->bbox);
    if ( lwResolvePolySurfaces(polygon: &v45->polygon, tlist: &v17->taglist, surf: &v17->surf, nsurfs: &v17->nsurfs) == 0 )
      break;
    if ( lwGetPointPolygons(point: &v45->point, polygon: &v45->polygon) == 0 )
      break;
    lwGetPolyNormals(point: &v45->point, polygon: &v45->polygon);
    lwGetVertNormals(point: v47, polygon: v46);
    lwFreePointPolygons(point: v48);
    if ( lwGetPointVMaps(point: &v45->point, vmap: v45->vmap) == 0
      || lwGetPolyVMaps(polygon: &v45->polygon, vmap: v45->vmap) == 0 )
    {
      break;
    }
    v45 = v45->next;
    if ( v45 == nullptr )
      return v17;
  }
Fail_5:
  if ( failpos != nullptr )
    *failpos = U4;
  v30 = v50;
  if ( v50 != nullptr )
  {
    if ( a5 != nullptr )
      *a5 = v50->Tell(this: v50);
    ((void (__fastcall *)(idFile_Memory *, int))v30->dtr_idFile)(a1: v30, a2: 1);
  }
  if ( v49 != nullptr )
  {
    ((void (__fastcall *)(idFileSystem *))fileSystem->FreeFile)(a1: fileSystem);
    v49 = nullptr;
  }
  lwFreeObject(object: v17);
  return nullptr;
}


// ========================================================================
// __unwind$226510_0
// EA  : 0x82884050
// RVA : 0x00884050
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void _unwind_226510_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 92), tag: TAG_FILE);
}


// ========================================================================
// `dynamic initializer for 'lwAllocator''
// EA  : 0x83344FD0
// RVA : 0x01344FD0
// PDB : w:\tech5\engine\models\static\staticmodel_lwo.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__lwAllocator__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__lwAllocator__);
}

