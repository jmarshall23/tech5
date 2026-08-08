
// ========================================================================
// ?SetFont@idDeviceContext@@QAAXPBVidFont@@@Z
// EA  : 0x8276BA58
// RVA : 0x0076BA58
// PDB : w:\tech5\engine\guis\devicecontext.cpp
// ========================================================================

void __fastcall idDeviceContext::SetFont(idDeviceContext *this, const idFont *font)
{
  this->activeFont = font;
}


// ========================================================================
// ?DrawStretchPic@idDeviceContext@@QAAXMMMMMMMMPBVidMaterial@@M@Z
// EA  : 0x8276BA60
// RVA : 0x0076BA60
// PDB : w:\tech5\engine\guis\devicecontext.cpp
// ========================================================================

void __fastcall idDeviceContext::DrawStretchPic(
        idDeviceContext *this,
        double x,
        double y,
        double w,
        double h,
        double s1,
        double t1,
        double s2,
        double t2,
        const idMaterial *shader,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        float angle,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        const idMaterial *a38)
{
  double v38; // fp12
  double v39; // fp10
  double v40; // fp4
  double v41; // fp3
  idRenderModelGui *gui; // r3
  idVec3 *p_origin; // r9
  unsigned int currentVertexColor; // r6
  int v45; // ctr
  float *v46; // r11
  double v47; // fp12
  double v48; // fp9
  double v49; // fp13
  double v50; // fp6
  double v51; // fp11
  double z; // fp10
  double v53; // fp2
  double v54; // fp1
  double v55; // fp0
  double v56; // fp12
  double v57; // fp6
  double v58; // fp4
  double v59; // fp12
  double v60; // fp10
  idVec4 v61; // [sp+50h] [-50h] BYREF
  idVec4 v62; // [sp+60h] [-40h] BYREF
  idVec4 v63; // [sp+70h] [-30h] BYREF
  idVec4 v64; // [sp+80h] [-20h] BYREF

  if ( this->identityMatrix )
  {
    v38 = (float)(this->uiScale.y * (float)h);
    v39 = (float)(this->uiScale.x * (float)w);
    v40 = (float)((float)(this->uiScale.y * (float)y) + this->uiOffset.y);
    v41 = (float)((float)(this->uiScale.x * (float)x) + this->uiOffset.x);
    v62.z = s1;
    v62.w = t2;
    v63.z = s2;
    v63.w = t2;
    v64.z = s2;
    v64.w = t1;
    gui = this->gui;
    v61.z = s1;
    v61.w = t1;
    v62.x = v41;
    v64.y = v40;
    v61.x = v41;
    v61.y = v40;
    v62.y = (float)v40 + (float)v38;
    v63.x = (float)v41 + (float)v39;
    v63.y = v62.y;
    v64.x = v63.x;
    idRenderModelGui::DrawStretchPic(
      this: gui,
      topLeft: &v61,
      topRight: &v64,
      bottomRight: &v63,
      bottomLeft: &v62,
      material: a38);
  }
  else
  {
    p_origin = &this->origin;
    currentVertexColor = this->gui->currentVertexColor;
    v45 = 4;
    this->stretchPicVerts[0].xyz.x = x;
    this->stretchPicVerts[0].xyz.y = y;
    this->stretchPicVerts[0].st.x = s1;
    this->stretchPicVerts[0].st.y = t1;
    this->stretchPicVerts[0].color[3] = HIBYTE(currentVertexColor);
    this->stretchPicVerts[0].color[2] = BYTE1(currentVertexColor);
    this->stretchPicVerts[0].color[1] = BYTE2(currentVertexColor);
    this->stretchPicVerts[0].color[0] = currentVertexColor;
    this->stretchPicVerts[0].tangent[3] = 127;
    this->stretchPicVerts[0].tangent[2] = 127;
    this->stretchPicVerts[0].tangent[1] = 127;
    this->stretchPicVerts[0].tangent[0] = 127;
    this->stretchPicVerts[1].xyz.x = (float)x + (float)w;
    this->stretchPicVerts[1].xyz.y = y;
    this->stretchPicVerts[1].st.x = s2;
    this->stretchPicVerts[1].st.y = t1;
    this->stretchPicVerts[1].color[3] = HIBYTE(currentVertexColor);
    this->stretchPicVerts[1].color[2] = BYTE1(currentVertexColor);
    this->stretchPicVerts[1].color[1] = BYTE2(currentVertexColor);
    this->stretchPicVerts[1].color[0] = currentVertexColor;
    this->stretchPicVerts[1].tangent[3] = 127;
    this->stretchPicVerts[1].tangent[2] = 127;
    this->stretchPicVerts[1].tangent[1] = 127;
    this->stretchPicVerts[1].tangent[0] = 127;
    this->stretchPicVerts[2].xyz.x = (float)x + (float)w;
    this->stretchPicVerts[2].xyz.y = (float)y + (float)h;
    this->stretchPicVerts[2].st.x = s2;
    this->stretchPicVerts[2].st.y = t2;
    this->stretchPicVerts[2].color[3] = HIBYTE(currentVertexColor);
    this->stretchPicVerts[2].color[2] = BYTE1(currentVertexColor);
    this->stretchPicVerts[2].color[1] = BYTE2(currentVertexColor);
    this->stretchPicVerts[2].color[0] = currentVertexColor;
    this->stretchPicVerts[2].tangent[3] = 127;
    this->stretchPicVerts[2].tangent[2] = 127;
    this->stretchPicVerts[2].tangent[1] = 127;
    this->stretchPicVerts[2].tangent[0] = 127;
    this->stretchPicVerts[3].xyz.x = x;
    this->stretchPicVerts[3].xyz.y = (float)y + (float)h;
    this->stretchPicVerts[3].st.x = s1;
    this->stretchPicVerts[3].st.y = t2;
    this->stretchPicVerts[3].color[3] = HIBYTE(currentVertexColor);
    this->stretchPicVerts[3].color[2] = BYTE1(currentVertexColor);
    this->stretchPicVerts[3].color[1] = BYTE2(currentVertexColor);
    this->stretchPicVerts[3].color[0] = currentVertexColor;
    this->stretchPicVerts[3].tangent[3] = 127;
    this->stretchPicVerts[3].tangent[2] = 127;
    this->stretchPicVerts[3].tangent[1] = 127;
    this->stretchPicVerts[3].tangent[0] = 127;
    v46 = (float *)((char *)this - 12);
    do
    {
      v47 = (float)(v46[7] - p_origin->x);
      v46[7] = v46[7] - p_origin->x;
      v48 = (float)(v46[8] - this->origin.y);
      v46[8] = v46[8] - this->origin.y;
      v49 = v47;
      v50 = (float)(v46[9] - this->origin.z);
      v46[9] = v46[9] - this->origin.z;
      v51 = this->axis.mat[0].y;
      z = this->axis.mat[0].z;
      v53 = (float)((float)((float)v48 * this->axis.mat[1].y) + (float)((float)v50 * this->axis.mat[2].y));
      v54 = (float)((float)((float)v48 * this->axis.mat[1].z) + (float)((float)v50 * this->axis.mat[2].z));
      v55 = (float)((float)((float)v50 * this->axis.mat[2].x)
                  + (float)((float)((float)v47 * this->axis.mat[0].x) + (float)((float)v48 * this->axis.mat[1].x)));
      v46[7] = (float)((float)v50 * this->axis.mat[2].x)
             + (float)((float)((float)v47 * this->axis.mat[0].x) + (float)((float)v48 * this->axis.mat[1].x));
      v56 = (float)((float)((float)v51 * (float)v47) + (float)v53);
      v46[8] = v56;
      v46[9] = (float)((float)v49 * (float)z) + (float)v54;
      v57 = (float)((float)v55 + p_origin->x);
      v46[7] = (float)v55 + p_origin->x;
      v58 = (float)((float)v56 + this->origin.y);
      v46[8] = (float)v56 + this->origin.y;
      v46[9] = (float)((float)((float)v49 * (float)z) + (float)v54) + this->origin.z;
      v59 = (float)((float)v57 * this->uiScale.x);
      v46[7] = (float)v57 * this->uiScale.x;
      v60 = (float)((float)v58 * this->uiScale.y);
      v46[8] = (float)v58 * this->uiScale.y;
      v46[7] = (float)v59 + this->uiOffset.x;
      v46 += 8;
      *v46 = this->uiOffset.y + (float)v60;
      --v45;
    }
    while ( v45 != 0 );
    idRenderModelGui::DrawTris(
      this: this->gui,
      verts: this->stretchPicVerts,
      numVerts: 4,
      indexes: this->stretchPicIndices,
      numIndexes: 6,
      material: a38);
  }
}


// ========================================================================
// ?TextWidth@idDeviceContext@@QAAHMPBDH@Z
// EA  : 0x8276BD30
// RVA : 0x0076BD30
// PDB : w:\tech5\engine\guis\devicecontext.cpp
// ========================================================================

int __fastcall idDeviceContext::TextWidth(
        idDeviceContext *this,
        double scale,
        const char *text,
        const unsigned __int8 *limit,
        int a5)
{
  double v10; // fp31
  double v11; // fp30
  int v12; // r10
  const unsigned __int8 *v13; // r11
  int v14; // r11
  char v15; // r11
  bool v16; // zf
  unsigned int v17; // r3
  __int64 v18; // r9
  __int64 v19; // [sp+50h] [-40h] BYREF
  __int64 v20; // [sp+58h] [-38h]

  if ( limit == nullptr )
    return 0;
  v19 = __PAIR64__(byte_821B0000, idFont::GetPointSize(this: this->activeFont));
  v11 = (float)((float)((float)scale * (float)48.0) / (float)v19);
  v10 = 0.0;
  if ( a5 <= 0 )
    a5 = 999999999;
  v12 = 0;
  HIDWORD(v19) = 0;
  if ( *limit != 0 )
  {
    do
    {
      if ( v12 >= a5 )
        break;
      v13 = &limit[v12];
      if ( &limit[v12] != nullptr && *v13 == 94 )
      {
        v14 = *((char *)v13 + 1);
        if ( v14 != 0 )
        {
          v16 = v14 != 32;
          v15 = 1;
          if ( v16 )
            continue;
        }
      }
      v15 = 0;
      if ( v15 != 0 )
      {
        HIDWORD(v19) = ++v12;
      }
      else
      {
        v17 = idStr::UTF8Char(s: limit, idx: (int *)&v19);
        LODWORD(v18) = idFont::GetGlyph(this: this->activeFont, idx: v17)->xSkip;
        v12 = HIDWORD(v19);
        v20 = v18;
        v10 = (float)((float)((float)v18 * (float)v11) + (float)v10);
      }
    }
    while ( limit[v12] != 0 );
  }
  LODWORD(v20) = (int)(float)((float)v10 + (float)0.5);
  return v20;
}


// ========================================================================
// ?TextHeight@idDeviceContext@@QAAHM@Z
// EA  : 0x8276BE88
// RVA : 0x0076BE88
// PDB : w:\tech5\engine\guis\devicecontext.cpp
// ========================================================================

int __fastcall idDeviceContext::TextHeight(idDeviceContext *this, double scale)
{
  double v3; // fp31
  int Ascender; // r30
  __int64 v5; // r8

  v3 = (float)((float)((float)scale * 48.0)
             / (float)__SPAIR64__(byte_821B0000, idFont::GetPointSize(this: this->activeFont)));
  Ascender = idFont::GetAscender(this: this->activeFont);
  LODWORD(v5) = Ascender - idFont::GetDescender(this: this->activeFont);
  return (int)(float)((float)v5 * (float)v3);
}


// ========================================================================
// ??0idDeviceContext@@QAA@PAVidRenderModelGui@@@Z
// EA  : 0x8276BF30
// RVA : 0x0076BF30
// PDB : w:\tech5\engine\guis\devicecontext.cpp
// ========================================================================

idDeviceContext *__fastcall idDeviceContext::idDeviceContext(idDeviceContext *this, idRenderModelGui *guiModel)
{
  int v6; // ctr
  int v7; // r11
  unsigned __int8 *v8; // r10
  int i; // ctr

  this->gui = guiModel;
  this->uiScale.x = 1.0;
  this->uiScale.y = 1.0;
  this->uiOffset.x = 0.0;
  this->uiOffset.y = 0.0;
  this->whiteMaterial = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                              this: &idMaterial::resourceList,
                                              name: "_white",
                                              makeDefault: true);
  __asm { vspltisw128 v63, 0 }
  __asm { vcmpequw128 v62, v95, v63 }
  this->activeFont = (const idFont *)idResourceList::Load(
                                       this: &idFont::resourceList,
                                       name: (char *)idFont::DEFAULT_FONT,
                                       makeDefault: true,
                                       skipStaleCheck: false);
  this->axis.mat[2].z = 1.0;
  _R11 = this->stretchPicVerts;
  this->axis.mat[1].y = 1.0;
  _R9 = 16;
  this->axis.mat[0].x = 1.0;
  __asm { vsldoi128 v62, v95, v62, 4 }
  this->axis.mat[1].z = 0.0;
  v6 = 32;
  this->axis.mat[0].z = 0.0;
  this->axis.mat[0].y = 0.0;
  this->axis.mat[2].y = 0.0;
  this->axis.mat[2].x = 0.0;
  this->axis.mat[1].x = 0.0;
  this->origin.z = 0.0;
  this->origin.y = 0.0;
  this->origin.x = 0.0;
  this->identityMatrix = true;
  do
  {
    __asm
    {
      stvx128   v63, r0, r11
      stvx128   v62, r11, r9
    }
    _R11->xyz.x = 0.0;
    _R11->xyz.y = 0.0;
    _R11->xyz.z = 0.0;
    _R11->st.x = 0.0;
    _R11->st.y = 0.0;
    ++_R11;
    --v6;
  }
  while ( v6 != 0 );
  v7 = 2;
  v8 = &this->stretchPicVerts[31].color[2];
  for ( i = 30; i != 0; --i )
  {
    *((_WORD *)v8 + 1) = 0;
    *((_WORD *)v8 + 2) = v7 - 1;
    v8 += 6;
    *(_WORD *)v8 = v7++;
  }
  return this;
}


// ========================================================================
// ?DrawWindingMaterial@idDeviceContext@@QAAXAAVidWinding2D@@PBVidMaterial@@ABVidVec4@@@Z
// EA  : 0x8276C080
// RVA : 0x0076C080
// PDB : w:\tech5\engine\guis\devicecontext.cpp
// ========================================================================

void __fastcall idDeviceContext::DrawWindingMaterial(
        idDeviceContext *this,
        idWinding2D *winding,
        const idMaterial *material,
        const idVec4 *color)
{
  idRenderModelGui *gui; // r30
  int v8; // r8
  int numPoints; // r5
  unsigned int currentVertexColor; // r30
  char v11; // r3
  float *p_y; // r9
  const idFont **p_activeFont; // r11
  int v14; // ctr
  float *v15; // r9
  const idFont **v16; // r11

  gui = this->gui;
  gui->currentVertexColor = idColor::PackColor(color);
  v8 = 0;
  numPoints = winding->numPoints;
  currentVertexColor = this->gui->currentVertexColor;
  if ( winding->numPoints >= 4 )
  {
    v11 = this->gui->currentVertexColor;
    p_y = &winding->p[31].y;
    p_activeFont = &this->activeFont;
    do
    {
      v8 += 4;
      *((float *)p_activeFont + 2) = (float)(this->uiScale.x * *(p_y - 63)) + this->uiOffset.x;
      *((float *)p_activeFont + 3) = (float)(this->uiScale.y * *(p_y - 62)) + this->uiOffset.y;
      p_activeFont[5] = *((const idFont **)p_y + 1);
      p_activeFont[6] = *((const idFont **)p_y + 2);
      *((_BYTE *)p_activeFont + 39) = HIBYTE(currentVertexColor);
      *((_BYTE *)p_activeFont + 38) = BYTE1(currentVertexColor);
      *((_BYTE *)p_activeFont + 37) = BYTE2(currentVertexColor);
      *((_BYTE *)p_activeFont + 36) = v11;
      *((_BYTE *)p_activeFont + 35) = 127;
      *((_BYTE *)p_activeFont + 34) = 127;
      *((_BYTE *)p_activeFont + 33) = 127;
      *((_BYTE *)p_activeFont + 32) = 127;
      *((float *)p_activeFont + 10) = (float)(this->uiScale.x * *(p_y - 61)) + this->uiOffset.x;
      *((float *)p_activeFont + 11) = (float)(this->uiScale.y * *(p_y - 60)) + this->uiOffset.y;
      p_activeFont[13] = *((const idFont **)p_y + 3);
      p_activeFont[14] = *((const idFont **)p_y + 4);
      *((_BYTE *)p_activeFont + 71) = HIBYTE(currentVertexColor);
      *((_BYTE *)p_activeFont + 70) = BYTE1(currentVertexColor);
      *((_BYTE *)p_activeFont + 69) = BYTE2(currentVertexColor);
      *((_BYTE *)p_activeFont + 68) = v11;
      *((_BYTE *)p_activeFont + 67) = 127;
      *((_BYTE *)p_activeFont + 66) = 127;
      *((_BYTE *)p_activeFont + 65) = 127;
      *((_BYTE *)p_activeFont + 64) = 127;
      *((float *)p_activeFont + 18) = (float)(this->uiScale.x * *(p_y - 59)) + this->uiOffset.x;
      *((float *)p_activeFont + 19) = (float)(this->uiScale.y * *(p_y - 58)) + this->uiOffset.y;
      p_activeFont[21] = *((const idFont **)p_y + 5);
      p_activeFont[22] = *((const idFont **)p_y + 6);
      *((_BYTE *)p_activeFont + 103) = HIBYTE(currentVertexColor);
      *((_BYTE *)p_activeFont + 102) = BYTE1(currentVertexColor);
      *((_BYTE *)p_activeFont + 101) = BYTE2(currentVertexColor);
      *((_BYTE *)p_activeFont + 100) = v11;
      *((_BYTE *)p_activeFont + 99) = 127;
      *((_BYTE *)p_activeFont + 98) = 127;
      *((_BYTE *)p_activeFont + 97) = 127;
      *((_BYTE *)p_activeFont + 96) = 127;
      *((float *)p_activeFont + 26) = (float)(this->uiScale.x * *(p_y - 57)) + this->uiOffset.x;
      *((float *)p_activeFont + 27) = (float)(this->uiScale.y * *(p_y - 56)) + this->uiOffset.y;
      p_activeFont[29] = *((const idFont **)p_y + 7);
      p_y += 8;
      p_activeFont[30] = *(const idFont **)p_y;
      *((_BYTE *)p_activeFont + 135) = HIBYTE(currentVertexColor);
      *((_BYTE *)p_activeFont + 134) = BYTE1(currentVertexColor);
      *((_BYTE *)p_activeFont + 133) = BYTE2(currentVertexColor);
      *((_BYTE *)p_activeFont + 132) = v11;
      *((_BYTE *)p_activeFont + 131) = 127;
      *((_BYTE *)p_activeFont + 130) = 127;
      *((_BYTE *)p_activeFont + 129) = 127;
      p_activeFont += 32;
      *(_BYTE *)p_activeFont = 127;
    }
    while ( v8 < numPoints - 3 );
  }
  if ( v8 < numPoints )
  {
    v14 = numPoints - v8;
    v15 = &winding->p[v8 + 31].y;
    v16 = &this->activeFont + 8 * v8;
    do
    {
      *((float *)v16 + 2) = (float)(this->uiScale.x * *(v15 - 63)) + this->uiOffset.x;
      *((float *)v16 + 3) = (float)(this->uiScale.y * *(v15 - 62)) + this->uiOffset.y;
      v16[5] = *((const idFont **)v15 + 1);
      v15 += 2;
      v16[6] = *(const idFont **)v15;
      *((_BYTE *)v16 + 39) = HIBYTE(currentVertexColor);
      *((_BYTE *)v16 + 38) = BYTE1(currentVertexColor);
      *((_BYTE *)v16 + 37) = BYTE2(currentVertexColor);
      *((_BYTE *)v16 + 36) = currentVertexColor;
      *((_BYTE *)v16 + 35) = 127;
      *((_BYTE *)v16 + 34) = 127;
      *((_BYTE *)v16 + 33) = 127;
      v16 += 8;
      *(_BYTE *)v16 = 127;
      --v14;
    }
    while ( v14 != 0 );
  }
  idRenderModelGui::DrawTris(
    this: this->gui,
    verts: this->stretchPicVerts,
    numVerts: numPoints,
    indexes: this->stretchPicIndices,
    numIndexes: 3 * (numPoints - 2),
    material);
}


// ========================================================================
// ?DrawFilledRect@idDeviceContext@@QAAXMMMMABVidVec4@@@Z
// EA  : 0x8276C308
// RVA : 0x0076C308
// PDB : w:\tech5\engine\guis\devicecontext.cpp
// ========================================================================

void __fastcall idDeviceContext::DrawFilledRect(
        idDeviceContext *this,
        double x,
        double y,
        double w,
        double h,
        const idVec4 *color,
        int a7,
        int a8,
        int a9,
        const idVec4 *a10)
{
  idRenderModelGui *gui; // r30
  int v16; // r10
  int v17; // r9
  int v18; // r8
  int v19; // r7
  int v20; // r6
  int v21; // r5
  const idMaterial *v22; // r4
  float v23; // [sp+8h] [-A8h]
  float v24; // [sp+Ch] [-A4h]
  float v25; // [sp+10h] [-A0h]
  float v26; // [sp+14h] [-9Ch]
  float v27; // [sp+18h] [-98h]
  float v28; // [sp+1Ch] [-94h]
  float v29; // [sp+20h] [-90h]
  float v30; // [sp+24h] [-8Ch]
  float v31; // [sp+28h] [-88h]
  float v32; // [sp+2Ch] [-84h]
  float v33; // [sp+30h] [-80h]
  float v34; // [sp+34h] [-7Ch]
  float v35; // [sp+38h] [-78h]
  float v36; // [sp+3Ch] [-74h]
  float v37; // [sp+40h] [-70h]
  float v38; // [sp+44h] [-6Ch]
  float v39; // [sp+48h] [-68h]
  float v40; // [sp+4Ch] [-64h]
  float v41; // [sp+50h] [-60h]
  float v42; // [sp+54h] [-5Ch]
  float v43; // [sp+58h] [-58h]

  if ( a10->w != 0.0 )
  {
    gui = this->gui;
    gui->currentVertexColor = idColor::PackColor(color: a10);
    idDeviceContext::DrawStretchPic(
      this,
      x,
      y,
      w,
      h,
      s1: 0.0,
      t1: 0.0,
      s2: 0.0,
      t2: 0.0,
      shader: v22,
      a11: v21,
      a12: v20,
      a13: v19,
      a14: v18,
      a15: v17,
      a16: v16,
      angle: v23,
      a18: v24,
      a19: v25,
      a20: v26,
      a21: v27,
      a22: v28,
      a23: v29,
      a24: v30,
      a25: v31,
      a26: v32,
      a27: v33,
      a28: v34,
      a29: v35,
      a30: v36,
      a31: v37,
      a32: v38,
      a33: v39,
      a34: v40,
      a35: v41,
      a36: v42,
      a37: v43,
      a38: this->whiteMaterial);
  }
}


// ========================================================================
// ?DrawRect@idDeviceContext@@QAAXMMMMMABVidVec4@@@Z
// EA  : 0x8276C3B0
// RVA : 0x0076C3B0
// PDB : w:\tech5\engine\guis\devicecontext.cpp
// ========================================================================

void __fastcall idDeviceContext::DrawRect(
        idDeviceContext *this,
        double x,
        double y,
        double w,
        double h,
        double size,
        const idVec4 *color,
        int a8,
        int a9,
        int a10,
        int a11,
        const idVec4 *a12)
{
  idRenderModelGui *gui; // r30
  int v19; // r9
  int v20; // r8
  int v21; // r7
  int v22; // r6
  int v23; // r5
  const idMaterial *v24; // r4
  int v25; // r10
  int v26; // r8
  int v27; // r7
  int v28; // r6
  int v29; // r5
  const idMaterial *v30; // r4
  int v31; // r10
  int v32; // r9
  int v33; // r7
  int v34; // r6
  int v35; // r5
  const idMaterial *v36; // r4
  int v37; // r10
  int v38; // r9
  int v39; // r8
  int v40; // r6
  int v41; // r5
  const idMaterial *v42; // r4
  float v43; // [sp+8h] [-B8h]
  float v44; // [sp+8h] [-B8h]
  float v45; // [sp+8h] [-B8h]
  float v46; // [sp+8h] [-B8h]
  float v47; // [sp+Ch] [-B4h]
  float v48; // [sp+Ch] [-B4h]
  float v49; // [sp+Ch] [-B4h]
  float v50; // [sp+Ch] [-B4h]
  float v51; // [sp+10h] [-B0h]
  float v52; // [sp+10h] [-B0h]
  float v53; // [sp+10h] [-B0h]
  float v54; // [sp+10h] [-B0h]
  float v55; // [sp+14h] [-ACh]
  float v56; // [sp+14h] [-ACh]
  float v57; // [sp+14h] [-ACh]
  float v58; // [sp+14h] [-ACh]
  float v59; // [sp+18h] [-A8h]
  float v60; // [sp+18h] [-A8h]
  float v61; // [sp+18h] [-A8h]
  float v62; // [sp+18h] [-A8h]
  float v63; // [sp+1Ch] [-A4h]
  float v64; // [sp+1Ch] [-A4h]
  float v65; // [sp+1Ch] [-A4h]
  float v66; // [sp+1Ch] [-A4h]
  float v67; // [sp+20h] [-A0h]
  float v68; // [sp+20h] [-A0h]
  float v69; // [sp+20h] [-A0h]
  float v70; // [sp+20h] [-A0h]
  float v71; // [sp+24h] [-9Ch]
  float v72; // [sp+24h] [-9Ch]
  float v73; // [sp+24h] [-9Ch]
  float v74; // [sp+24h] [-9Ch]
  float v75; // [sp+28h] [-98h]
  float v76; // [sp+28h] [-98h]
  float v77; // [sp+28h] [-98h]
  float v78; // [sp+28h] [-98h]
  float v79; // [sp+2Ch] [-94h]
  float v80; // [sp+2Ch] [-94h]
  float v81; // [sp+2Ch] [-94h]
  float v82; // [sp+2Ch] [-94h]
  float v83; // [sp+30h] [-90h]
  float v84; // [sp+30h] [-90h]
  float v85; // [sp+30h] [-90h]
  float v86; // [sp+30h] [-90h]
  float v87; // [sp+34h] [-8Ch]
  float v88; // [sp+34h] [-8Ch]
  float v89; // [sp+34h] [-8Ch]
  float v90; // [sp+34h] [-8Ch]
  float v91; // [sp+38h] [-88h]
  float v92; // [sp+38h] [-88h]
  float v93; // [sp+38h] [-88h]
  float v94; // [sp+38h] [-88h]
  float v95; // [sp+3Ch] [-84h]
  float v96; // [sp+3Ch] [-84h]
  float v97; // [sp+3Ch] [-84h]
  float v98; // [sp+3Ch] [-84h]
  float v99; // [sp+40h] [-80h]
  float v100; // [sp+40h] [-80h]
  float v101; // [sp+40h] [-80h]
  float v102; // [sp+40h] [-80h]
  float v103; // [sp+44h] [-7Ch]
  float v104; // [sp+44h] [-7Ch]
  float v105; // [sp+44h] [-7Ch]
  float v106; // [sp+44h] [-7Ch]
  float v107; // [sp+48h] [-78h]
  float v108; // [sp+48h] [-78h]
  float v109; // [sp+48h] [-78h]
  float v110; // [sp+48h] [-78h]
  float v111; // [sp+4Ch] [-74h]
  float v112; // [sp+4Ch] [-74h]
  float v113; // [sp+4Ch] [-74h]
  float v114; // [sp+4Ch] [-74h]
  float v115; // [sp+50h] [-70h]
  float v116; // [sp+50h] [-70h]
  float v117; // [sp+50h] [-70h]
  float v118; // [sp+50h] [-70h]
  float v119; // [sp+54h] [-6Ch]
  float v120; // [sp+54h] [-6Ch]
  float v121; // [sp+54h] [-6Ch]
  float v122; // [sp+54h] [-6Ch]
  float v123; // [sp+58h] [-68h]
  float v124; // [sp+58h] [-68h]
  float v125; // [sp+58h] [-68h]
  float v126; // [sp+58h] [-68h]

  if ( a12->w != 0.0 && size != 0.0 )
  {
    gui = this->gui;
    gui->currentVertexColor = idColor::PackColor(color: a12);
    idDeviceContext::DrawStretchPic(
      this,
      x,
      y: (float)((float)y + (float)size),
      w: size,
      h: (float)((float)h - (float)((float)size * (float)2.0)),
      s1: 0.0,
      t1: 0.0,
      s2: 0.0,
      t2: 0.0,
      shader: v24,
      a11: v23,
      a12: v22,
      a13: v21,
      a14: v20,
      a15: v19,
      a16: (int)&off_82010000,
      angle: v43,
      a18: v47,
      a19: v51,
      a20: v55,
      a21: v59,
      a22: v63,
      a23: v67,
      a24: v71,
      a25: v75,
      a26: v79,
      a27: v83,
      a28: v87,
      a29: v91,
      a30: v95,
      a31: v99,
      a32: v103,
      a33: v107,
      a34: v111,
      a35: v115,
      a36: v119,
      a37: v123,
      a38: this->whiteMaterial);
    idDeviceContext::DrawStretchPic(
      this,
      x: (float)((float)((float)x + (float)w) - (float)size),
      y: (float)((float)y + (float)size),
      w: size,
      h: (float)((float)h - (float)((float)size * (float)2.0)),
      s1: 0.0,
      t1: 0.0,
      s2: 0.0,
      t2: 0.0,
      shader: v30,
      a11: v29,
      a12: v28,
      a13: v27,
      a14: v26,
      a15: (int)this->whiteMaterial,
      a16: v25,
      angle: v44,
      a18: v48,
      a19: v52,
      a20: v56,
      a21: v60,
      a22: v64,
      a23: v68,
      a24: v72,
      a25: v76,
      a26: v80,
      a27: v84,
      a28: v88,
      a29: v92,
      a30: v96,
      a31: v100,
      a32: v104,
      a33: v108,
      a34: v112,
      a35: v116,
      a36: v120,
      a37: v124,
      a38: this->whiteMaterial);
    idDeviceContext::DrawStretchPic(
      this,
      x,
      y,
      w,
      h: size,
      s1: 0.0,
      t1: 0.0,
      s2: 0.0,
      t2: 0.0,
      shader: v36,
      a11: v35,
      a12: v34,
      a13: v33,
      a14: (int)this->whiteMaterial,
      a15: v32,
      a16: v31,
      angle: v45,
      a18: v49,
      a19: v53,
      a20: v57,
      a21: v61,
      a22: v65,
      a23: v69,
      a24: v73,
      a25: v77,
      a26: v81,
      a27: v85,
      a28: v89,
      a29: v93,
      a30: v97,
      a31: v101,
      a32: v105,
      a33: v109,
      a34: v113,
      a35: v117,
      a36: v121,
      a37: v125,
      a38: this->whiteMaterial);
    idDeviceContext::DrawStretchPic(
      this,
      x,
      y: (float)((float)((float)y + (float)h) - (float)size),
      w,
      h: size,
      s1: 0.0,
      t1: 0.0,
      s2: 0.0,
      t2: 0.0,
      shader: v42,
      a11: v41,
      a12: v40,
      a13: (int)this->whiteMaterial,
      a14: v39,
      a15: v38,
      a16: v37,
      angle: v46,
      a18: v50,
      a19: v54,
      a20: v58,
      a21: v62,
      a22: v66,
      a23: v70,
      a24: v74,
      a25: v78,
      a26: v82,
      a27: v86,
      a28: v90,
      a29: v94,
      a30: v98,
      a31: v102,
      a32: v106,
      a33: v110,
      a34: v114,
      a35: v118,
      a36: v122,
      a37: v126,
      a38: this->whiteMaterial);
  }
}


// ========================================================================
// ?DrawTextA@idDeviceContext@@QAAHMMMABVidVec4@@PBD@Z
// EA  : 0x8276C518
// RVA : 0x0076C518
// PDB : w:\tech5\engine\guis\devicecontext.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idDeviceContext::DrawTextA(
        idDeviceContext *this,
        double x,
        double y,
        double scale,
        const idVec4 *color,
        const char *text,
        int a7,
        const idVec4 *a8,
        const unsigned __int8 *a9)
{
  __int64 v15; // r11
  idFont *activeFont; // r3
  double v17; // fp31
  __int64 v18; // r9
  idFont *v19; // r3
  double v20; // fp29
  double v21; // fp27
  __int64 v22; // r7
  idRenderModelGui *gui; // r31
  double v24; // fp26
  int v25; // r28
  unsigned int v26; // r3
  const glyphInfo_t *Glyph; // r3
  const glyphInfo_t *v28; // r31
  const unsigned __int8 *v29; // r11
  int v30; // r11
  char v31; // r11
  bool v32; // zf
  int v33; // r3
  double v34; // fp13
  idRenderModelGui *v35; // r31
  double z; // fp12
  double w; // fp11
  idVec4 *v38; // r3
  double v39; // fp0
  int top; // r5 OVERLAPPED
  __int64 v41; // r7 OVERLAPPED
  __int64 v42; // r11
  __int64 v43; // r9 OVERLAPPED
  __int64 v44; // fp12
  __int64 v45; // r4 OVERLAPPED
  __int64 v46; // fp0
  double v47; // fp23
  double v48; // fp22
  double v49; // fp21
  double v50; // fp20
  double v51; // fp16
  double v52; // fp19
  double v53; // fp18
  double v54; // fp17
  const idMaterial *Material; // r3
  int v56; // r10
  int v57; // r9
  int v58; // r8
  int v59; // r7
  int v60; // r6
  int v61; // r5
  const idMaterial *v62; // r4
  __int64 v63; // r4
  float v65; // [sp+8h] [-178h]
  float v66; // [sp+Ch] [-174h]
  float v67; // [sp+10h] [-170h]
  float v68; // [sp+14h] [-16Ch]
  float v69; // [sp+18h] [-168h]
  float v70; // [sp+1Ch] [-164h]
  float v71; // [sp+20h] [-160h]
  float v72; // [sp+24h] [-15Ch]
  float v73; // [sp+28h] [-158h]
  float v74; // [sp+2Ch] [-154h]
  float v75; // [sp+30h] [-150h]
  float v76; // [sp+34h] [-14Ch]
  float v77; // [sp+38h] [-148h]
  float v78; // [sp+3Ch] [-144h]
  float v79; // [sp+40h] [-140h]
  float v80; // [sp+44h] [-13Ch]
  float v81; // [sp+48h] [-138h]
  float v82; // [sp+4Ch] [-134h]
  float v83; // [sp+50h] [-130h]
  float v84; // [sp+54h] [-12Ch]
  float v85; // [sp+58h] [-128h]
  int v86; // [sp+70h] [-110h] BYREF
  __int64 v87; // [sp+78h] [-108h]
  __int64 v88; // [sp+80h] [-100h]
  __int64 v89; // [sp+88h] [-F8h]
  __int64 v90; // [sp+90h] [-F0h]
  __int64 v91; // [sp+98h] [-E8h]
  __int64 v92; // [sp+A0h] [-E0h]
  __int64 v93; // [sp+A8h] [-D8h]
  __int64 v94; // [sp+B0h] [-D0h]
  __int64 v95; // [sp+B8h] [-C8h]
  idVec4 v96; // [sp+C0h] [-C0h] BYREF

  if ( a9 == nullptr || a8->w == 0.0 )
    return 0;
  v15 = __PAIR64__(byte_821B0000, idFont::GetPointSize(this: this->activeFont));
  activeFont = this->activeFont;
  v87 = v15;
  v17 = (float)((float)((float)scale * *(float *)(HIDWORD(v15) - 14912)) / (float)v15);
  v18 = __PAIR64__(0x82000000, idFont::GetMaterialWidth(this: activeFont));
  v19 = this->activeFont;
  v87 = v18;
  v20 = *(float *)(HIDWORD(v18) + 2984);
  v21 = (float)(*(float *)(HIDWORD(v18) + 2984) / (float)v18);
  LODWORD(v22) = idFont::GetMaterialHeight(this: v19);
  gui = this->gui;
  v87 = v22;
  v24 = (float)((float)v20 / (float)v22);
  gui->currentVertexColor = idColor::PackColor(color: a8);
  v25 = 0;
  if ( *a9 != 0 )
  {
    do
      ++v25;
    while ( a9[v25] != 0 );
  }
  v86 = 0;
  while ( v86 < v25 )
  {
    v26 = idStr::UTF8Char(s: a9, idx: &v86);
    Glyph = idFont::GetGlyph(this: this->activeFont, idx: v26);
    v28 = Glyph;
    v29 = &a9[v86];
    if ( &a9[v86] == nullptr || *v29 != 94 || (v30 = *((char *)v29 + 1)) == 0 || (v32 = v30 != 32, v31 = 1, !v32) )
      v31 = 0;
    if ( v31 != 0 )
    {
      v33 = (char)a9[v86 + 1];
      if ( v33 == 48 )
      {
        v34 = a8->y;
        v35 = this->gui;
        z = a8->z;
        w = a8->w;
        v96.x = a8->x;
        v96.y = v34;
        v96.z = z;
        v96.w = w;
      }
      else
      {
        v38 = idStr::ColorForIndex(i: v33);
        v96.x = v38->x;
        v35 = this->gui;
        v96.y = v38->y;
        v39 = a8->w;
        v96.z = v38->z;
        v96.w = v39;
      }
      v35->currentVertexColor = idColor::PackColor(color: &v96);
    }
    else
    {
      top = (unsigned __int8)Glyph->top;
      LODWORD(v41) = Glyph->height;
      LODWORD(v42) = Glyph->width;
      HIDWORD(v42) = Glyph->s;
      LODWORD(v43) = Glyph->t;
      HIDWORD(v43) = v43 + v41;
      HIDWORD(v41) = v43 + v41;
      v90 = v41;
      v89 = v43;
      LODWORD(v41) = HIDWORD(v42) + v42;
      v44 = v43;
      LODWORD(v43) = (char)top;
      HIDWORD(v45) = (unsigned __int8)Glyph->left;
      LODWORD(v45) = HIDWORD(v42);
      v88 = *(__int64 *)((char *)&v41 - 4);
      HIDWORD(v41) = HIDWORD(v42) + v42;
      v91 = v42;
      v87 = v45;
      v46 = v45;
      v94 = *(_QWORD *)(&top - 1);
      v92 = v43;
      HIDWORD(v43) = SBYTE3(v45);
      HIDWORD(v45) = this->activeFont;
      v93 = *(__int64 *)((char *)&v41 - 4);
      v47 = (float)((float)v42 + (float)v20);
      v48 = (float)((float)v90 + (float)v20);
      v49 = (float)((float)v92 * (float)v17);
      v50 = (float)((float)*(__int64 *)((char *)&v41 - 4) * (float)v17);
      v51 = (float)((float)((float)v88 + (float)0.5) * (float)v24);
      v52 = (float)((float)((float)*(__int64 *)(&top - 1) + (float)0.5) * (float)v21);
      v53 = (float)((float)((float)v44 - (float)0.5) * (float)v24);
      v54 = (float)((float)((float)v46 - (float)0.5) * (float)v21);
      Material = idFont::GetMaterial(this: (idFont *)HIDWORD(v45));
      idDeviceContext::DrawStretchPic(
        this,
        x: (float)((float)v50 + (float)x),
        y: (float)((float)y - (float)v49),
        w: (float)((float)v47 * (float)v17),
        h: (float)((float)v48 * (float)v17),
        s1: v54,
        t1: v53,
        s2: v52,
        t2: v51,
        shader: v62,
        a11: v61,
        a12: v60,
        a13: v59,
        a14: v58,
        a15: v57,
        a16: v56,
        angle: v65,
        a18: v66,
        a19: v67,
        a20: v68,
        a21: v69,
        a22: v70,
        a23: v71,
        a24: v72,
        a25: v73,
        a26: v74,
        a27: v75,
        a28: v76,
        a29: v77,
        a30: v78,
        a31: v79,
        a32: v80,
        a33: v81,
        a34: v82,
        a35: v83,
        a36: v84,
        a37: v85,
        a38: Material);
      LODWORD(v63) = v28->xSkip;
      v95 = v63;
      x = (float)((float)((float)v63 * (float)v17) + (float)x);
    }
  }
  return v25;
}


// ========================================================================
// ?DrawLine@idDeviceContext@@QAAXABVidVec2@@0MABVidVec4@@@Z
// EA  : 0x8276C878
// RVA : 0x0076C878
// PDB : w:\tech5\engine\guis\devicecontext.cpp
// ========================================================================

void __fastcall idDeviceContext::DrawLine(
        idDeviceContext *this,
        const idVec2 *start,
        const idVec2 *end,
        double width,
        const idVec4 *color,
        const idVec4 *a6)
{
  double x; // fp9
  double v7; // fp8
  double v8; // fp7
  double y; // fp3
  double v10; // fp4
  const idMaterial *whiteMaterial; // r5
  double v13; // fp2
  double v16; // fp10
  double v17; // fp5
  double v18; // fp11
  double v19; // fp10
  idWinding2D v20; // [sp+50h] [-220h] BYREF

  x = end->x;
  v7 = start->x;
  v8 = (float)(end->x - start->x);
  y = start->y;
  v10 = (float)(end->y - start->y);
  v20.st[0].x = 1.0;
  v20.st[2].y = 1.0;
  v20.st[3].x = 1.0;
  v20.st[3].y = 1.0;
  whiteMaterial = this->whiteMaterial;
  v20.st[0].y = 0.0;
  v20.st[1].x = 0.0;
  v20.st[1].y = 0.0;
  v20.numPoints = 4;
  v20.st[2].x = 0.0;
  v13 = end->y;
  _FP0 = (float)((float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f11, f0, f5, f11 }
  v16 = __frsqrte(_FP11);
  v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                      * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8))
                                                                                              * (float)0.5))
                                                                              * (float)v16)
                                                                      - (float)1.5)
                                                      * (float)v16)
                                              * (float)((float)((float)((float)v10 * (float)v10)
                                                              + (float)((float)v8 * (float)v8))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v16
                                                                              * (float)((float)((float)((float)v10 * (float)v10)
                                                                                              + (float)((float)v8 * (float)v8))
                                                                                      * (float)0.5))
                                                                      * (float)v16)
                                                              - (float)1.5)
                                              * (float)v16))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v16
                                                      * (float)((float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v8 * (float)v8))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16));
  v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)) * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16)
                                                                                              * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)) * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                              * (float)v16))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)) * (float)0.5))
                                                                                              * (float)v16)
                                                                                      - (float)1.5)
                                                                      * (float)v16))
                                                      * (float)((float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v8 * (float)v8))
                                                              * (float)0.5))
                                              * (float)v17)
                                      - (float)1.5)
                      * (float)v17)
              * (float)v8);
  v19 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)) * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16)
                                                                                              * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)) * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                              * (float)v16))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)) * (float)0.5))
                                                                                              * (float)v16)
                                                                                      - (float)1.5)
                                                                      * (float)v16))
                                                      * (float)((float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v8 * (float)v8))
                                                              * (float)0.5))
                                              * (float)v17)
                                      - (float)1.5)
                      * (float)v17)
              * (float)v10);
  v20.p[2].x = (float)((float)v19 * (float)width) + (float)x;
  v20.p[3].x = (float)x - (float)((float)v19 * (float)width);
  v20.p[0].x = (float)v7 - (float)((float)v19 * (float)width);
  v20.p[1].x = (float)((float)v19 * (float)width) + (float)v7;
  v20.p[0].y = (float)y - (float)((float)-v18 * (float)width);
  v20.p[1].y = (float)((float)-v18 * (float)width) + (float)y;
  v20.p[2].y = (float)v13 + (float)((float)-v18 * (float)width);
  v20.p[3].y = (float)v13 - (float)((float)-v18 * (float)width);
  idDeviceContext::DrawWindingMaterial(this, winding: &v20, material: whiteMaterial, color: a6);
}

