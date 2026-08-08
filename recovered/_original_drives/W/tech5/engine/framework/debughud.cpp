
// ========================================================================
// ?Printf@idDebugHUDLocal@@UAAXHHABVidColor@@MHPBDPAD@Z
// EA  : 0x826717E8
// RVA : 0x006717E8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::Printf(
        idDebugHUDLocal *this,
        int x,
        int y,
        const idColor *color,
        double scale,
        const int flags,
        const char *fmt,
        char *argptr)
{
  ((void (__fastcall *)(idDebugHUDLocal *, int, int, const idColor *, idColor *, const char *, const char *, char *, double))this->Printf_11)(
    a1: this,
    a2: x,
    a3: y,
    a4: color,
    a5: &idColor::colorBlack,
    a6: fmt,
    a7: fmt,
    a8: argptr,
    a9: scale);
}


// ========================================================================
// ?Printf@idDebugHUDLocal@@UAAXHHABVidColor@@0MPBDZZ
// EA  : 0x82671838
// RVA : 0x00671838
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void idDebugHUDLocal::Printf(
        idDebugHUDLocal *this,
        int x,
        int y,
        const idColor *color,
        const idColor *backgroundColor,
        double scale,
        const char *fmt,
        __int64 a8,
        ...)
{
  __int64 v8; // [sp+C8h] [+48h] BYREF

  v8 = a8;
  ((void (__fastcall *)(idDebugHUDLocal *, int, int, const idColor *, const idColor *, __int64 *, int, _DWORD, double))this->Printf_11)(
    a1: this,
    a2: x,
    a3: y,
    a4: color,
    a5: backgroundColor,
    a6: &v8,
    a7: 39,
    a8: HIDWORD(a8),
    a9: scale);
}


// ========================================================================
// ?Printf@idDebugHUDLocal@@UAAXHHABVidColor@@MPBDZZ
// EA  : 0x82671890
// RVA : 0x00671890
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idDebugHUDLocal::Printf(
        idDebugHUDLocal *this,
        int x,
        int y,
        const idColor *color,
        double scale,
        const char *fmt,
        int a7,
        __int64 a8,
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
        int a21,
        int a22,
        ...)
{
  __int64 v22; // [sp+C0h] [+40h] BYREF
  va_list va; // [sp+C0h] [+40h]
  __int64 v24; // [sp+C8h] [+48h]
  va_list va1; // [sp+D0h] [+50h] BYREF

  va_start(va1, a22);
  va_start(va, a22);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v22 = *(__int64 *)((char *)&a8 + 4);
  v24 = a8;
  ((void (__fastcall *)(idDebugHUDLocal *, int, int, const idColor *, idColor *, __int64 *, int, int, double))this->Printf_11)(
    a1: this,
    a2: x,
    a3: y,
    a4: color,
    a5: &idColor::colorBlack,
    a6: (__int64 *)va,
    a7: 7,
    a8: a7,
    a9: scale);
}


// ========================================================================
// ?Printf@idDebugHUDLocal@@UAAXHHABVidColor@@PBDPAD@Z
// EA  : 0x826718F8
// RVA : 0x006718F8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::Printf(
        idDebugHUDLocal *this,
        int x,
        int y,
        const idColor *color,
        const char *fmt,
        char *argptr)
{
  ((void (__fastcall *)(idDebugHUDLocal *, int, int, const idColor *, idColor *, char *, int, const char *, double))this->Printf_11)(
    a1: this,
    a2: x,
    a3: y,
    a4: color,
    a5: &idColor::colorBlack,
    a6: argptr,
    a7: 5,
    a8: fmt,
    a9: 1.0);
}


// ========================================================================
// ?Printf@idDebugHUDLocal@@UAAXHHABVidColor@@PBDZZ
// EA  : 0x82671948
// RVA : 0x00671948
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idDebugHUDLocal::Printf(
        idDebugHUDLocal *this,
        int x,
        int y,
        const idColor *color,
        __int64 fmt,
        __int64 a6,
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
        ...)
{
  __int64 v18; // [sp+B8h] [+38h] BYREF
  va_list va; // [sp+B8h] [+38h]
  __int64 v20; // [sp+C0h] [+40h]
  __int64 v21; // [sp+C8h] [+48h]
  va_list va1; // [sp+D0h] [+50h] BYREF

  va_start(va1, a18);
  va_start(va, a18);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v18 = fmt;
  v20 = *(__int64 *)((char *)&a6 + 4);
  v21 = a6;
  ((void (__fastcall *)(idDebugHUDLocal *, int, int, const idColor *, idColor *, __int64 *, int, _DWORD, double))this->Printf_11)(
    a1: this,
    a2: x,
    a3: y,
    a4: color,
    a5: &idColor::colorBlack,
    a6: (__int64 *)va,
    a7: 5,
    a8: HIDWORD(fmt),
    a9: 1.0);
}


// ========================================================================
// ?Printf@idDebugHUDLocal@@UAAXHHABVidColor@@0PBDPAD@Z
// EA  : 0x826719C0
// RVA : 0x006719C0
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::Printf(
        idDebugHUDLocal *this,
        int x,
        int y,
        const idColor *color,
        const idColor *backgroundColor,
        const char *fmt,
        char *argptr)
{
  ((void (__fastcall *)(idDebugHUDLocal *, int, int, const idColor *, const idColor *, void (__fastcall *)(struct idDebugHUDLocal *, int, int, const idColor *, const idColor *, const float, const int, const char *, char *), int, const char *, double))this->Printf_11)(
    a1: this,
    a2: x,
    a3: y,
    a4: color,
    a5: backgroundColor,
    a6: this->Printf_11,
    a7: 37,
    a8: fmt,
    a9: 1.0);
}


// ========================================================================
// ?Printf@idDebugHUDLocal@@UAAXHHABVidColor@@0PBDZZ
// EA  : 0x82671A08
// RVA : 0x00671A08
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idDebugHUDLocal::Printf(
        idDebugHUDLocal *this,
        int x,
        int y,
        const idColor *color,
        const idColor *backgroundColor,
        const char *fmt,
        __int64 a7,
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
        int a21,
        ...)
{
  __int64 v21; // [sp+C0h] [+40h] BYREF
  va_list va; // [sp+C0h] [+40h]
  __int64 v23; // [sp+C8h] [+48h]
  va_list va1; // [sp+D0h] [+50h] BYREF

  va_start(va1, a21);
  va_start(va, a21);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v21 = *(__int64 *)((char *)&a7 + 4);
  v23 = a7;
  ((void (__fastcall *)(idDebugHUDLocal *, int, int, const idColor *, const idColor *, __int64 *, int, const char *, double))this->Printf_11)(
    a1: this,
    a2: x,
    a3: y,
    a4: color,
    a5: backgroundColor,
    a6: (__int64 *)va,
    a7: 37,
    a8: fmt,
    a9: 1.0);
}


// ========================================================================
// ?Printf@idDebugHUDLocal@@UAAXHHPBDPAD@Z
// EA  : 0x82671A78
// RVA : 0x00671A78
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::Printf(idDebugHUDLocal *this, int x, int y, const char *fmt, char *argptr)
{
  ((void (__fastcall *)(idDebugHUDLocal *, int, int, idColor *, double))this->Printf_9)(
    a1: this,
    a2: x,
    a3: y,
    a4: &this->curColor,
    a5: 1.0);
}


// ========================================================================
// ?Printf@idDebugHUDLocal@@UAAXHHPBDZZ
// EA  : 0x82671AC8
// RVA : 0x00671AC8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void idDebugHUDLocal::Printf(idDebugHUDLocal *this, int x, int y, const char *fmt, ...)
{
  ((void (__fastcall *)(idDebugHUDLocal *, int, int, idColor *, double))this->Printf_9)(
    a1: this,
    a2: x,
    a3: y,
    a4: &this->curColor,
    a5: 1.0);
}


// ========================================================================
// ?Printf@idDebugHUDLocal@@UAAXPBDZZ
// EA  : 0x82671B38
// RVA : 0x00671B38
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void idDebugHUDLocal::Printf(idDebugHUDLocal *this, const char *fmt, ...)
{
  ((void (__fastcall *)(idDebugHUDLocal *, int, int, idColor *, double))this->Printf_9)(
    a1: this,
    a2: this->curX,
    a3: this->curY,
    a4: &this->curColor,
    a5: 1.0);
}


// ========================================================================
// ?SetLeftAlign@idDebugHUDLocal@@UAAXXZ
// EA  : 0x82671BB8
// RVA : 0x00671BB8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::SetLeftAlign(idDebugHUDLocal *this)
{
  this->alignRight = false;
}


// ========================================================================
// ?SetRightAlign@idDebugHUDLocal@@UAAXXZ
// EA  : 0x82671BC8
// RVA : 0x00671BC8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::SetRightAlign(idDebugHUDLocal *this)
{
  this->alignRight = true;
}


// ========================================================================
// ?SetTextPosition@idDebugHUDLocal@@UAAXHH@Z
// EA  : 0x82671BD8
// RVA : 0x00671BD8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::SetTextPosition(idDebugHUDLocal *this, int x, int y)
{
  this->curX = x;
  this->curY = y;
  this->startX = x;
}


// ========================================================================
// ?SetTextScale@idDebugHUDLocal@@UAAXM@Z
// EA  : 0x82671BE8
// RVA : 0x00671BE8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::SetTextScale(idDebugHUDLocal *this, double scale)
{
  this->curScale = scale;
}


// ========================================================================
// ?SetTextColor@idDebugHUDLocal@@UAAXABVidColor@@@Z
// EA  : 0x82671BF0
// RVA : 0x00671BF0
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::SetTextColor(idDebugHUDLocal *this, const idColor *color)
{
  this->curColor = *color;
}


// ========================================================================
// ?Frame@idDebugHUDLocal@@UAAXXZ
// EA  : 0x82671C80
// RVA : 0x00671C80
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::Frame(idDebugHUDLocal *this)
{
  if ( g_stopTime.valueInteger == 0 )
    this->Clear(this, a2: false);
}


// ========================================================================
// ?Render@idDebugHUDLocal@@UAAXPAVidRenderModelGui@@@Z
// EA  : 0x82671CB0
// RVA : 0x00671CB0
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDebugHUDLocal::Render(idDebugHUDLocal *this, idRenderModelGui *gui)
{
  __int64 v4; // r11
  int v5; // r25
  int v6; // r27
  idDebugHUDLocal::debugText_t *v7; // r31
  __int64 v8; // r10
  double v9; // fp29
  __int64 v10; // r5 OVERLAPPED
  int flags; // r11
  const idMaterial *white; // r10
  __int128 v13; // r6
  __int64 v14; // r8
  __int64 v15; // fp11
  double a; // fp0
  double g; // fp12
  double r; // fp11
  __int64 v19; // r10
  double v20; // fp3
  idRenderModelGui *v21; // r3 OVERLAPPED
  double v22; // fp11
  double v23; // fp2
  double v24; // fp1
  __int128 v25; // r7
  __int64 v26; // fp9
  double v27; // fp0
  double v28; // fp13
  double v29; // fp12
  int v30; // r25
  int v31; // r27
  idDebugHUDLocal::debugText_t *v32; // r31
  __int64 v33; // r5
  int v34; // r11
  const idMaterial *v35; // r10
  double scale; // fp12
  double curScale; // fp13
  __int64 v38; // r9
  double v39; // fp11
  double v40; // fp12
  double v41; // fp13
  double v42; // fp12
  idRenderModelGui *v43; // r3
  double v44; // fp11
  __int128 v45; // r11
  double v46; // fp3
  double y; // fp6
  double v48; // fp1
  __int64 v49; // r9 OVERLAPPED
  double v50; // fp11
  double v51; // fp12
  __int64 v52; // r11 OVERLAPPED
  int v53; // [sp+8h] [-1F8h]
  int v54; // [sp+Ch] [-1F4h]
  int v55; // [sp+10h] [-1F0h]
  int v56; // [sp+14h] [-1ECh]
  int v57; // [sp+18h] [-1E8h]
  int v58; // [sp+1Ch] [-1E4h]
  int v59; // [sp+20h] [-1E0h]
  int v60; // [sp+24h] [-1DCh]
  int v61; // [sp+28h] [-1D8h]
  int v62; // [sp+2Ch] [-1D4h]
  int v63; // [sp+30h] [-1D0h]
  int v64; // [sp+34h] [-1CCh]
  int v65; // [sp+38h] [-1C8h]
  int v66; // [sp+3Ch] [-1C4h]
  int v67; // [sp+40h] [-1C0h]
  int v68; // [sp+44h] [-1BCh]
  int v69; // [sp+48h] [-1B8h]
  int v70; // [sp+4Ch] [-1B4h]
  int v71; // [sp+50h] [-1B0h]
  int v72; // [sp+54h] [-1ACh]
  int v73; // [sp+58h] [-1A8h]
  __int64 v74; // [sp+60h] [-1A0h]
  __int64 v75; // [sp+90h] [-170h]
  __int64 v76; // [sp+B8h] [-148h]
  idVec4 v77; // [sp+E0h] [-120h] BYREF
  float v78; // [sp+F0h] [-110h]
  float v79; // [sp+F4h] [-10Ch]
  float b; // [sp+F8h] [-108h]
  float v81; // [sp+FCh] [-104h]
  float v82; // [sp+100h] [-100h]
  float v83; // [sp+104h] [-FCh]
  float v84; // [sp+108h] [-F8h]
  float v85; // [sp+10Ch] [-F4h]
  idVec4 v86; // [sp+110h] [-F0h] BYREF
  idVec4 v87; // [sp+120h] [-E0h] BYREF
  idVec4 v88; // [sp+130h] [-D0h] BYREF
  idVec4 v89; // [sp+140h] [-C0h] BYREF
  idVec4 v90; // [sp+150h] [-B0h] BYREF
  idVec4 v91; // [sp+160h] [-A0h] BYREF
  float v92; // [sp+170h] [-90h]
  float v93; // [sp+174h] [-8Ch]
  float v94; // [sp+178h] [-88h]
  float v95; // [sp+17Ch] [-84h]
  idVec4 v96; // [sp+180h] [-80h] BYREF
  __int64 v97; // [sp+190h] [-70h]

  if ( com_debugHUD.valueInteger != 0 )
  {
    if ( this->white == nullptr )
      this->white = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                          this: &idMaterial::resourceList,
                                          name: "_white",
                                          makeDefault: true);
    HIDWORD(v4) = 0x82000000;
    v5 = 0;
    if ( this->debugText.num > 0 )
    {
      v6 = 0;
      do
      {
        v7 = &this->debugText.list[v6];
        gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&idColor::colorWhite);
        LODWORD(v8) = v7->y;
        v9 = (float)((float)(this->curScale * v7->scale) * SMALLCHAR_HEIGHT);
        v97 = v8;
        if ( (float)v8 <= (double)(float)(idRenderModelGui::GetVirtualHeight(this: gui) - (float)v9) )
        {
          HIDWORD(v4) = v7->y;
          if ( (float)((float)*(__int64 *)((char *)&v4 + 4) + (float)v9) >= 0.0 )
          {
            flags = v7->flags;
            white = this->white;
            if ( (flags & 8) != 0 )
            {
              if ( white != nullptr && (flags & 0x20) != 0 )
              {
                gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&v7->backgroundColor);
                LODWORD(v13) = v7->len;
                HIDWORD(v14) = v7->y;
                LODWORD(v14) = v7->x;
                v15 = v13;
                DWORD2(v13) = HIDWORD(v14);
                idRenderModelGui::DrawStretchPic(
                  this: gui,
                  x: (float)((float)v14
                        - (float)((float)((float)(this->curScale * v7->scale) * SMALLCHAR_WIDTH) * (float)v15)),
                  y: (float)*(__int64 *)((char *)&v13 + 4),
                  w: (float)((float)((float)(this->curScale * v7->scale) * SMALLCHAR_WIDTH) * (float)v15),
                  h: (float)((float)(this->curScale * v7->scale) * SMALLCHAR_HEIGHT),
                  s1: 0.0,
                  t1: 0.0,
                  s2: 1.0,
                  t2: 1.0,
                  material: (const idMaterial *)DWORD1(v13),
                  a11: SHIDWORD(v14),
                  a12: v13,
                  a13: SHIDWORD(v14),
                  a14: v14,
                  a15: v13,
                  a16: (int)this->white,
                  a17: v53,
                  a18: v54,
                  a19: v55,
                  a20: v56,
                  a21: v57,
                  a22: v58,
                  a23: v59,
                  a24: v60,
                  a25: v61,
                  a26: v62,
                  a27: v63,
                  a28: v64,
                  a29: v65,
                  a30: v66,
                  a31: v67,
                  a32: v68,
                  a33: v69,
                  a34: v70,
                  a35: v71,
                  a36: v72,
                  a37: v73,
                  a38: this->white);
              }
              a = v7->color.a;
              g = v7->color.g;
              r = v7->color.r;
              b = v7->color.b;
              v78 = r;
              v81 = a;
              v79 = g;
              LODWORD(v10) = v7->x;
              HIDWORD(v19) = v7->y;
              LODWORD(v19) = v7->len;
              v20 = (float)(this->curScale * v7->scale);
              v22 = (float)-(float)((float)((float)((float)(this->curScale * v7->scale) * SMALLCHAR_WIDTH) * (float)v19)
                                  - (float)v10);
              *(__int64 *)((char *)&v10 + 4) = __PAIR64__((unsigned int)gui, HIDWORD(v19));
              LODWORD(v19) = (int)v22;
              v23 = (float)__SPAIR64__((unsigned int)gui, HIDWORD(v19));
              v24 = (float)v19;
            }
            else
            {
              if ( white != nullptr && (flags & 0x20) != 0 )
              {
                gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&v7->backgroundColor);
                LODWORD(v25) = v7->len;
                DWORD1(v25) = v7->x;
                v26 = v25;
                DWORD2(v25) = v7->y;
                idRenderModelGui::DrawStretchPic(
                  this: gui,
                  x: (float)*(__int64 *)&v25,
                  y: (float)*(__int64 *)((char *)&v25 + 4),
                  w: (float)((float)((float)((float)v26 * v7->scale) * this->curScale) * SMALLCHAR_WIDTH),
                  h: (float)((float)(v7->scale * this->curScale) * SMALLCHAR_HEIGHT),
                  s1: 0.0,
                  t1: 0.0,
                  s2: 1.0,
                  t2: 1.0,
                  material: (const idMaterial *)HIDWORD(v25),
                  a11: SDWORD1(v25),
                  a12: SDWORD2(v25),
                  a13: v25,
                  a14: (int)this->white,
                  a15: SDWORD1(v25),
                  a16: SDWORD2(v25),
                  a17: v53,
                  a18: v54,
                  a19: v55,
                  a20: v56,
                  a21: v57,
                  a22: v58,
                  a23: v59,
                  a24: v60,
                  a25: v61,
                  a26: v62,
                  a27: v63,
                  a28: v64,
                  a29: v65,
                  a30: v66,
                  a31: v67,
                  a32: v68,
                  a33: v69,
                  a34: v70,
                  a35: v71,
                  a36: v72,
                  a37: v73,
                  a38: this->white);
              }
              v27 = v7->color.a;
              v28 = v7->color.b;
              v29 = v7->color.g;
              v21 = gui;
              v92 = v7->color.r;
              v93 = v29;
              v95 = v27;
              v94 = v28;
              LODWORD(v10) = v7->x;
              v20 = (float)(this->curScale * v7->scale);
              v23 = (float)*(__int64 *)&v7->x;
              v24 = (float)v10;
            }
            idRenderModelGui::DrawString(
              this: v21,
              x: v24,
              y: v23,
              string: (const char *)HIDWORD(v10),
              defaultColor: (const idVec4 *)v10,
              forceColor: (bool)v7->text.data,
              scale: v20);
          }
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->debugText.num );
    }
    v30 = 0;
    if ( this->persistentText.num > 0 )
    {
      v31 = 0;
      do
      {
        v32 = &this->persistentText.list[v31];
        LODWORD(v4) = v32->y;
        if ( (int)v4 <= 480
          && (float)((float)((float)(v32->scale * this->curScale) * SMALLCHAR_HEIGHT) + (float)v4) >= 0.0 )
        {
          gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&idColor::colorWhite);
          v34 = v32->flags;
          v35 = this->white;
          if ( (v34 & 8) != 0 )
          {
            if ( v35 != nullptr && (v34 & 0x20) != 0 )
            {
              gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&v32->backgroundColor);
              scale = v32->scale;
              curScale = this->curScale;
              HIDWORD(v38) = this->white;
              LODWORD(v38) = v32->len;
              v39 = (float)(v32->scale * SMALLCHAR_WIDTH);
              v74 = *(_QWORD *)&v32->x;
              v76 = v38;
              LODWORD(v38) = v32->x;
              v86.z = 0.0;
              v86.w = 1.0;
              v88.z = 1.0;
              v88.w = 1.0;
              v77.z = 1.0;
              v77.w = 0.0;
              v90.z = 0.0;
              v90.w = 0.0;
              v77.y = (float)v74;
              v90.y = v77.y;
              v86.y = v77.y + (float)((float)((float)scale * (float)curScale) * SMALLCHAR_HEIGHT);
              v88.y = v86.y;
              v40 = (float)((float)v39 * (float)v76);
              v86.x = (float)v38 - (float)((float)((float)v39 * (float)v76) * (float)curScale);
              v90.x = v86.x;
              v88.x = (float)((float)v38 - (float)((float)v40 * (float)curScale))
                    + (float)((float)v40 * (float)curScale);
              v77.x = v88.x;
              idRenderModelGui::DrawStretchPic(
                this: gui,
                topLeft: &v90,
                topRight: &v77,
                bottomRight: &v88,
                bottomLeft: &v86,
                material: (const idMaterial *)HIDWORD(v38));
            }
            v41 = v32->color.b;
            v42 = v32->color.g;
            v43 = gui;
            v44 = v32->color.r;
            v85 = v32->color.a;
            v82 = v44;
            v83 = v42;
            v84 = v41;
            DWORD1(v45) = v32->x;
            DWORD2(v45) = v32->len;
            HIDWORD(v33) = v32->y;
            LODWORD(v33) = DWORD1(v45);
            v46 = (float)(v32->scale * this->curScale);
            LODWORD(v45) = HIDWORD(v33);
            y = (double)(__int64)v45;
            v48 = (float)(unsigned int)(int)(float)-(float)((float)((float)((float)(v32->scale * SMALLCHAR_WIDTH)
                                                                          * (float)*(__int64 *)((char *)&v45 + 4))
                                                                  * this->curScale)
                                                          - (float)v33);
          }
          else
          {
            if ( v35 != nullptr && (v34 & 0x20) != 0 )
            {
              gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&v32->backgroundColor);
              HIDWORD(v49) = v32->len;
              v50 = v32->scale;
              v51 = this->curScale;
              LODWORD(v49) = v32->y;
              v52 = *(_QWORD *)&v32->len;
              v75 = v49;
              v89.z = 0.0;
              v89.w = 1.0;
              v91.z = 1.0;
              HIDWORD(v49) = this->white;
              v91.w = 1.0;
              v96.z = 1.0;
              v96.w = 0.0;
              v87.z = 0.0;
              v87.w = 0.0;
              v96.y = (float)v75;
              v87.y = v96.y;
              v89.x = (float)v52;
              v87.x = v89.x;
              v89.y = v96.y + (float)((float)((float)v50 * (float)v51) * SMALLCHAR_HEIGHT);
              v91.y = v89.y;
              v91.x = v89.x
                    + (float)((float)((float)((float)*(__int64 *)((char *)&v49 - 4) * (float)v50) * (float)v51)
                            * SMALLCHAR_WIDTH);
              v96.x = v91.x;
              idRenderModelGui::DrawStretchPic(
                this: gui,
                topLeft: &v87,
                topRight: &v96,
                bottomRight: &v91,
                bottomLeft: &v89,
                material: (const idMaterial *)HIDWORD(v49));
            }
            v43 = gui;
            v46 = (float)(v32->scale * this->curScale);
            LODWORD(v33) = v32->x;
            y = (double)(unsigned int)v32->y;
            v48 = (float)v33;
          }
          idRenderModelGui::DrawString(
            this: v43,
            x: v48,
            (float)y,
            string: (const char *)HIDWORD(v33),
            defaultColor: (const idVec4 *)v33,
            forceColor: (bool)v32->text.data,
            scale: v46);
        }
        ++v30;
        ++v31;
      }
      while ( v30 < this->persistentText.num );
    }
  }
  else
  {
    this->Clear(this, a2: false);
  }
}


// ========================================================================
// ?RemovePersistentText@idDebugHUDLocal@@UAAXHH@Z
// EA  : 0x82672818
// RVA : 0x00672818
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::RemovePersistentText(idDebugHUDLocal *this, int x, int y)
{
  int v5; // r30
  idList<idDebugHUDLocal::debugText_t,5> *p_persistentText; // r31
  int v7; // r29
  idDebugHUDLocal::debugText_t *v8; // r11
  int num; // r11
  int v10; // r11

  v5 = this->persistentText.num - 1;
  if ( v5 >= 0 )
  {
    p_persistentText = &this->persistentText;
    v7 = v5;
    do
    {
      v8 = &p_persistentText->list[v7];
      if ( v8->x == x && v8->y == y )
      {
        num = p_persistentText->num;
        if ( v5 < num )
        {
          v10 = num - 1;
          p_persistentText->num = v10;
          if ( v5 != v10 )
            idDebugHUDLocal::debugText_t::operator=(
              this: &p_persistentText->list[v7],
              __that: &p_persistentText->list[v10]);
        }
      }
      --v5;
      --v7;
    }
    while ( v5 >= 0 );
  }
}


// ========================================================================
// ?Clear@idDebugHUDLocal@@UAAX_N@Z
// EA  : 0x82672B00
// RVA : 0x00672B00
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::Clear(idDebugHUDLocal *this, bool clearPersistent)
{
  int num; // r11
  int v5; // r29
  int v6; // r30
  idDebugHUDLocal::debugText_t *list; // r3
  int v8; // r29
  int v9; // r30
  idDebugHUDLocal::debugText_t *v10; // r28
  int size; // r30
  idDebugHUDLocal::debugText_t *v12; // r29

  if ( g_stopTime.valueInteger == 0 )
  {
    num = this->debugText.num;
    this->startX = 0;
    v5 = 0;
    this->curX = 0;
    this->curY = 0;
    this->alignRight = false;
    if ( num > 0 )
    {
      v6 = 0;
      do
      {
        idStr::FreeData(this: &this->debugText.list[v6].text);
        ++v5;
        ++v6;
      }
      while ( v5 < this->debugText.num );
    }
    if ( this->debugText.listStatic == 0 || this->debugText.listStatic == 2 )
    {
      list = this->debugText.list;
      if ( list != nullptr )
        idListArrayDelete<idDebugHUDLocal::debugText_t>(ptr: &list->text, num: this->debugText.size);
      this->debugText.list = nullptr;
      this->debugText.size = 0;
    }
    this->debugText.num = 0;
    if ( clearPersistent )
    {
      v8 = 0;
      if ( this->persistentText.num > 0 )
      {
        v9 = 0;
        do
        {
          idStr::FreeData(this: &this->persistentText.list[v9].text);
          ++v8;
          ++v9;
        }
        while ( v8 < this->persistentText.num );
      }
      if ( this->persistentText.listStatic == 0 || this->persistentText.listStatic == 2 )
      {
        v10 = this->persistentText.list;
        if ( v10 != nullptr )
        {
          size = this->persistentText.size;
          if ( size > 0 )
          {
            v12 = this->persistentText.list;
            do
            {
              idStr::FreeData(this: &v12->text);
              --size;
              ++v12;
            }
            while ( size != 0 );
          }
          idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
        }
        this->persistentText.list = nullptr;
        this->persistentText.size = 0;
      }
      this->persistentText.num = 0;
    }
  }
}


// ========================================================================
// ?Render@idGUIRect@@QAAXAAVidDeviceContext@@HHM@Z
// EA  : 0x82672C50
// RVA : 0x00672C50
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGUIRect::Render(
        idGUIRect *this,
        idDeviceContext *context,
        __int64 y,
        double scale,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v10; // r6 OVERLAPPED
  const char *v11; // r4
  int v12; // r3
  int borderHeight; // r10
  int v14; // r24
  int v15; // r11
  BOOL v16; // r21
  int num; // r8
  int v18; // r27
  int v19; // r28
  int v20; // r23
  int v21; // r22
  int v22; // r26
  idGUILine *v23; // r30
  int v24; // r29
  const char *v25; // r4
  int v26; // r3
  int v27; // r11
  int v28; // r11
  int v29; // r7
  int v30; // r11
  const char *v31; // r29
  int borderWidth; // r26
  __int64 v33; // r11
  __int64 v34; // r7
  __int64 v35; // r9
  __int64 v36; // r5
  int v37; // r28
  __int64 v38; // r11
  int v39; // r27
  double v40; // fp29
  idGUILine *v41; // r30
  __int64 v42; // r11
  float a; // r5
  double v44; // fp13
  float v45; // r4
  double textAlpha; // fp0
  float v47; // r9
  float v48; // r7
  float v49; // r6
  float v50; // r3
  float v51; // r23
  double v52; // fp10
  __int64 v53; // r9
  double v54; // fp28
  const char *v55; // r5
  const idVec4 *v56; // r4
  char *list; // r3
  float b; // [sp+68h] [-B8h]
  float r; // [sp+70h] [-B0h] BYREF
  float g; // [sp+74h] [-ACh]
  float v61; // [sp+78h] [-A8h]
  float v62; // [sp+7Ch] [-A4h]
  float v63; // [sp+80h] [-A0h]
  float v64; // [sp+84h] [-9Ch]
  float v65; // [sp+88h] [-98h]
  float v66; // [sp+8Ch] [-94h]

  LODWORD(a7) = HIDWORD(y);
  *(_QWORD *)&this->left = y;
  context->uiOffset.y = (float)y;
  context->uiOffset.x = (float)a7;
  v12 = idDeviceContext::TextHeight(this: context, scale);
  borderHeight = this->borderHeight;
  v14 = v12;
  v15 = borderHeight;
  v16 = this->title.len != 0;
  if ( this->title.len == 0 )
    v15 = borderHeight + v12;
  num = this->lines.num;
  v18 = v15;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  this->height = num * v12 + borderHeight + v15;
  if ( num > 0 )
  {
    v22 = 0;
    do
    {
      v23 = &this->lines.list[v22];
      v24 = idDeviceContext::TextWidth(this: context, scale, text: v11, limit: (int)v23->heading.data);
      v26 = idDeviceContext::TextWidth(this: context, scale, text: v25, limit: (int)v23->text.data);
      if ( v24 > v19 )
        v19 = v24;
      if ( v26 > v20 )
        v20 = v26;
      if ( (v23->flags & 1) != 0 )
        v18 = v23->y;
      else
        v18 += v14;
      v27 = this->borderHeight + v18 + v14;
      if ( v27 > this->height )
        this->height = v27;
      ++v21;
      ++v22;
    }
    while ( v21 < this->lines.num );
  }
  LODWORD(v10) = this->height;
  v28 = 2 * (this->borderWidth + 4) + v20 + v19;
  b = this->bgColor.b;
  this->width = v28;
  v29 = v28;
  idDeviceContext::DrawFilledRect(
    this: context,
    x: 0.0,
    y: 0.0,
    w: (float)*(__int64 *)((char *)&v10 - 4),
    h: (float)v10,
    color: (const idVec4 *)LODWORD(b));
  v30 = this->borderHeight;
  v31 = (const char *)((v30 >> 1) + v14);
  borderWidth = this->borderWidth;
  if ( v16 > 0 )
  {
    HIDWORD(v33) = this->width;
    *(float *)&v34 = this->titleBarColor.g;
    LODWORD(v34) = HIDWORD(v33);
    LODWORD(v33) = 2 * v30 + v14;
    idDeviceContext::DrawFilledRect(
      this: context,
      x: 0.0,
      y: 0.0,
      w: (float)v34,
      h: (float)v33,
      color: (const idVec4 *)LODWORD(this->titleBarColor.a));
    LODWORD(v35) = borderWidth;
    *(float *)&v36 = this->titleTextColor.r;
    LODWORD(v36) = v31;
    idDeviceContext::DrawTextA(
      this: context,
      x: (float)v35,
      y: (float)v36,
      scale,
      color: (const idVec4 *)HIDWORD(v36),
      text: v31);
    v31 += this->borderHeight - (this->borderHeight >> 1) + v14;
  }
  HIDWORD(v38) = this->lines.num;
  LODWORD(v38) = borderWidth + v19 + 8;
  v37 = 0;
  if ( SHIDWORD(v38) > 0 )
  {
    v39 = 0;
    v40 = (float)v38;
    do
    {
      v41 = &this->lines.list[v39];
      if ( (v41->flags & 1) != 0 )
        v31 = (const char *)v41->y;
      v66 = -1.0;
      v64 = -1.0;
      v62 = -1.0;
      v65 = -1.0;
      v63 = -1.0;
      r = -1.0;
      v61 = -1.0;
      g = -1.0;
      HIDWORD(v42) = &r;
      if ( (v41->flags & 2) != 0 )
      {
        r = v41->headerColor.r;
        g = v41->headerColor.g;
        v61 = v41->headerColor.b;
        a = v41->headerColor.a;
        v62 = a;
        v44 = a;
        v45 = v41->textColor.r;
        v63 = v45;
        v64 = v41->textColor.g;
        v65 = v41->textColor.b;
        *(float *)&v42 = v41->textColor.a;
        v66 = *(float *)&v42;
        textAlpha = *(float *)&v42;
      }
      else
      {
        v47 = this->titleTextColor.g;
        v48 = this->titleTextColor.b;
        textAlpha = this->textAlpha;
        v49 = this->titleTextColor.a;
        v44 = textAlpha;
        v45 = this->textColor.r;
        v50 = this->textColor.g;
        a = this->textColor.b;
        v51 = this->textColor.a;
        r = this->titleTextColor.r;
        g = v47;
        v61 = v48;
        v62 = v49;
        v63 = v45;
        v64 = v50;
        v65 = a;
        v66 = v51;
      }
      LODWORD(v42) = v31;
      v52 = (float)(this->alpha * (float)textAlpha);
      v62 = this->alpha * (float)v44;
      v66 = v52;
      HIDWORD(v53) = v41->heading.data;
      LODWORD(v53) = v41->x + borderWidth;
      v54 = (float)v42;
      idDeviceContext::DrawTextA(
        this: context,
        x: (float)v53,
        y: v54,
        scale,
        color: (const idVec4 *)LODWORD(v45),
        text: (const char *)LODWORD(a));
      idDeviceContext::DrawTextA(this: context, x: v40, y: v54, scale, color: v56, text: v55);
      ++v37;
      v31 += v14;
      ++v39;
    }
    while ( v37 < this->lines.num );
  }
  if ( this->lines.listStatic == 0 || this->lines.listStatic == 2 )
  {
    list = (char *)this->lines.list;
    if ( list != nullptr )
      idListArrayDelete<idGUILine>(ptr: list, num: this->lines.size);
    this->lines.list = nullptr;
    this->lines.size = 0;
  }
  this->lines.num = 0;
}


// ========================================================================
// ??0idDebugHUDLocal@@QAA@XZ
// EA  : 0x826732F8
// RVA : 0x006732F8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

idDebugHUDLocal *__fastcall idDebugHUDLocal::idDebugHUDLocal(idDebugHUDLocal *this)
{
  this->__vftable = (idDebugHUDLocal_vtbl *)&idDebugHUDLocal::`vftable';
  this->debugText.granularity = 0;
  this->debugText.memTag = 5;
  this->debugText.listStatic = 0;
  this->debugText.list = nullptr;
  this->debugText.size = 0;
  this->debugText.num = 0;
  this->persistentText.granularity = 0;
  this->persistentText.memTag = 5;
  this->persistentText.listStatic = 0;
  this->persistentText.list = nullptr;
  this->persistentText.size = 0;
  this->persistentText.num = 0;
  this->curColor.r = 1.0;
  this->curColor.g = 1.0;
  this->curColor.b = 1.0;
  this->curColor.a = 1.0;
  this->curX = 0;
  this->curY = 0;
  this->curScale = 0.75;
  this->startX = 0;
  this->alignRight = false;
  this->white = nullptr;
  return this;
}


// ========================================================================
// __unwind$221671
// EA  : 0x826733A4
// RVA : 0x006733A4
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void _unwind_221671()
{
  int v0; // r12

  idDebugHUD::~idDebugHUD(this: *(idDebugHUD **)(v0 - 32 + 52));
}


// ========================================================================
// __unwind$221672
// EA  : 0x826733CC
// RVA : 0x006733CC
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void _unwind_221672()
{
  int v0; // r12

  idList<idDebugHUDLocal::debugText_t,5>::~idList<idDebugHUDLocal::debugText_t,5>(this: (idList<idDebugHUDLocal::debugText_t,5> *)(*(_DWORD *)(v0 - 32 + 52) + 4));
}


// ========================================================================
// ??1idDebugHUDLocal@@UAA@XZ
// EA  : 0x82673400
// RVA : 0x00673400
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::~idDebugHUDLocal(idDebugHUDLocal *this)
{
  idDebugHUDLocal::debugText_t *list; // r3
  idDebugHUDLocal::debugText_t *v3; // r3

  this->__vftable = (idDebugHUDLocal_vtbl *)&idDebugHUDLocal::`vftable';
  idDebugHUDLocal::Clear(this, clearPersistent: true);
  if ( this->persistentText.listStatic == 0 || this->persistentText.listStatic == 2 )
  {
    list = this->persistentText.list;
    if ( list != nullptr )
      idListArrayDelete<idDebugHUDLocal::debugText_t>(ptr: &list->text, num: this->persistentText.size);
    this->persistentText.list = nullptr;
    this->persistentText.size = 0;
  }
  this->persistentText.num = 0;
  if ( this->debugText.listStatic == 0 || this->debugText.listStatic == 2 )
  {
    v3 = this->debugText.list;
    if ( v3 != nullptr )
      idListArrayDelete<idDebugHUDLocal::debugText_t>(ptr: &v3->text, num: this->debugText.size);
    this->debugText.list = nullptr;
    this->debugText.size = 0;
  }
  this->debugText.num = 0;
  this->__vftable = (idDebugHUDLocal_vtbl *)&idDebugHUD::`vftable';
}


// ========================================================================
// __unwind$221730
// EA  : 0x826734AC
// RVA : 0x006734AC
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void _unwind_221730()
{
  int v0; // r12

  idDebugHUD::~idDebugHUD(this: *(idDebugHUD **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$221731
// EA  : 0x826734D4
// RVA : 0x006734D4
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void _unwind_221731()
{
  int v0; // r12

  idList<idDebugHUDLocal::debugText_t,5>::~idList<idDebugHUDLocal::debugText_t,5>(this: (idList<idDebugHUDLocal::debugText_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$221732
// EA  : 0x82673500
// RVA : 0x00673500
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void _unwind_221732()
{
  int v0; // r12

  idList<idDebugHUDLocal::debugText_t,5>::~idList<idDebugHUDLocal::debugText_t,5>(this: (idList<idDebugHUDLocal::debugText_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// ??0idGUIRect@@QAA@PBDHHABVidColor@@111MM@Z
// EA  : 0x82673538
// RVA : 0x00673538
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

idGUIRect *__fastcall idGUIRect::idGUIRect(
        idGUIRect *this,
        const char *title_,
        int borderWidth_,
        int borderHeight_,
        const idColor *bgColor_,
        const idColor *textColor_,
        const idColor *titleBarColor_,
        const idColor *titleTextColor_,
        double alpha_,
        double textAlpha_)
{
  float a; // r5
  double alpha; // fp0

  idStr::idStr(this: &this->title, text: title_);
  this->borderWidth = borderWidth_;
  this->borderHeight = borderHeight_;
  this->bgColor = *bgColor_;
  this->textColor = *textColor_;
  this->titleBarColor = *titleBarColor_;
  this->titleTextColor.r = titleTextColor_->r;
  this->titleTextColor.g = titleTextColor_->g;
  this->titleTextColor.b = titleTextColor_->b;
  a = titleTextColor_->a;
  this->alpha = alpha_;
  this->titleTextColor.a = a;
  this->textAlpha = textAlpha_;
  this->lines.granularity = 0;
  this->lines.memTag = 5;
  this->lines.listStatic = 0;
  this->lines.list = nullptr;
  this->lines.size = 0;
  this->lines.num = 0;
  alpha = this->alpha;
  this->bgColor.a = this->alpha;
  this->left = 0;
  this->textColor.a = alpha;
  this->top = 0;
  this->titleBarColor.a = alpha;
  this->width = 0;
  this->titleTextColor.a = alpha;
  this->height = 0;
  return this;
}


// ========================================================================
// __unwind$221791
// EA  : 0x82673668
// RVA : 0x00673668
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void _unwind_221791()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 176 + 196));
}


// ========================================================================
// ??1idGUIRect@@QAA@XZ
// EA  : 0x82673698
// RVA : 0x00673698
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idGUIRect::~idGUIRect(idGUIRect *this)
{
  char *list; // r3

  if ( this->lines.listStatic == 0 || this->lines.listStatic == 2 )
  {
    list = (char *)this->lines.list;
    if ( list != nullptr )
      idListArrayDelete<idGUILine>(ptr: list, num: this->lines.size);
    this->lines.list = nullptr;
    this->lines.size = 0;
  }
  this->lines.num = 0;
  idStr::FreeData(this: &this->title);
}


// ========================================================================
// __unwind$221823
// EA  : 0x826736F8
// RVA : 0x006736F8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void _unwind_221823()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ?Printf@idGUIRect@@QAAXPBD0ZZ
// EA  : 0x82673870
// RVA : 0x00673870
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idGUIRect::Printf(
        idGUIRect *this,
        const char *heading,
        __int64 fmt,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        ...)
{
  idGUILine *v14; // r31
  const char *v15; // [sp+94h] [+24h]
  __int64 v16; // [sp+98h] [+28h] BYREF
  va_list va; // [sp+98h] [+28h]
  __int64 v18; // [sp+A0h] [+30h]
  __int64 v19; // [sp+A8h] [+38h]
  __int64 v20; // [sp+B0h] [+40h]
  __int64 v21; // [sp+B8h] [+48h]
  va_list va1; // [sp+C0h] [+50h] BYREF

  va_start(va1, a13);
  va_start(va, a13);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v16 = fmt;
  v18 = *(__int64 *)((char *)&a4 + 4);
  v19 = a4;
  v20 = *(__int64 *)((char *)&a5 + 4);
  v21 = a5;
  v15 = (const char *)HIDWORD(fmt);
  v14 = idList<idGUILine,5>::Alloc(this: &this->lines);
  v14->flags = 0;
  idStr::operator=(this: &v14->heading, text: heading);
  idStr::VFormat(this: &v14->text, fmt: v15, argptr: va);
}


// ========================================================================
// ?Printf@idDebugHUDLocal@@UAAXHHABVidColor@@0MHPBDPAD@Z
// EA  : 0x826738F8
// RVA : 0x006738F8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __fastcall idDebugHUDLocal::Printf(
        idDebugHUDLocal *this,
        int x,
        int y,
        const idColor *color,
        const idColor *backgroundColor,
        double scale,
        const int flags,
        unsigned int fmt,
        char *argptr,
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
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        char *a29)
{
  char v36; // r6
  char *v37; // r11
  char *v38; // r4
  int v39; // r19
  char *v40; // r8
  int v41; // r5
  char *v42; // r9
  int *v43; // r10
  int v44; // r5
  int v45; // r5
  int v46; // r20
  int v47; // r22
  int v48; // r26
  const char *v49; // r27
  int *v50; // r28
  idList<idDebugHUDLocal::debugText_t,5> *p_debugText; // r30
  int num; // r11
  int size; // r10
  int v54; // r31
  BOOL alignRight; // r10
  int v56; // r11
  int startX; // r10
  char v58; // [sp+4Fh] [-A1h] BYREF
  _BYTE v59[8]; // [sp+50h] [-A0h] BYREF
  int v61; // [sp+5Ch] [-94h]
  _DWORD v62[4]; // [sp+60h] [-90h] BYREF

  if ( com_debugHUD.valueInteger != 0 && g_stopTime.valueInteger == 0 )
  {
    idStr::vsnPrintf(dest: idDebugHUDLocal::buff, size: 1024, fmt: argptr, argptr: a29);
    v36 = idDebugHUDLocal::buff[0];
    v62[0] = 0;
    v59[0] = 0;
    v37 = lines[0];
    v38 = idDebugHUDLocal::buff;
    v39 = 0;
    if ( idDebugHUDLocal::buff[0] != 0 )
    {
      v40 = &v58;
      v41 = idDebugHUDLocal::buff[0];
      v42 = lines[0];
      v43 = v62;
      do
      {
        if ( v41 == 10 )
        {
          v42 += 1024;
          *v37 = 0;
          *++v40 = 1;
          ++v37;
          ++v39;
          ++v43;
          if ( (int)v42 >= (int)&com_showDebugMenu )
            break;
          v44 = (unsigned __int8)v38[1];
          v37 = v42;
          *v43 = 0;
          v40[1] = 0;
          if ( v44 == 0 )
            break;
        }
        else
        {
          v45 = *v43;
          *v37++ = v36;
          *v43 = v45 + 1;
        }
        v36 = *++v38;
        v41 = *v38;
      }
      while ( *v38 != 0 );
    }
    *v37 = 0;
    v46 = (int)(float)((float)(this->curScale * SMALLCHAR_HEIGHT) * (float)scale);
    v61 = (int)(float)((float)(this->curScale * SMALLCHAR_WIDTH) * (float)scale);
    v47 = v61;
    if ( (fmt & 4) != 0 )
    {
      this->startX = x;
      this->curX = x;
      this->curY = y;
    }
    v48 = 0;
    if ( v39 >= 0 )
    {
      v49 = lines[0];
      v50 = v62;
      do
      {
        if ( (int)v49 >= (int)&com_showDebugMenu )
          break;
        if ( *v49 != 0 )
        {
          p_debugText = &this->debugText;
          idList<idDebugHUDLocal::debugText_t,5>::PreAllocateWithGranularity(
            this: &this->debugText,
            newSize: this->debugText.num + 1);
          num = this->debugText.num;
          size = this->debugText.size;
          if ( num >= size )
          {
            v54 = (int)&p_debugText->list[size - 1];
          }
          else
          {
            v54 = (int)&p_debugText->list[num];
            this->debugText.num = num + 1;
          }
          idStr::operator=(this: (idStr *)v54, text: v49);
          alignRight = this->alignRight;
          *(float *)(v54 + 64) = scale;
          v56 = *v50;
          *(_DWORD *)(v54 + 60) = (!alignRight ? 0 : 8) | fmt;
          *(_DWORD *)(v54 + 36) = this->curX;
          *(_DWORD *)(v54 + 40) = this->curY;
          *(float *)(v54 + 44) = color->r;
          *(float *)(v54 + 48) = color->g;
          *(float *)(v54 + 52) = color->b;
          *(float *)(v54 + 56) = color->a;
          *(_DWORD *)(v54 + 32) = v56;
          *(float *)(v54 + 68) = backgroundColor->r;
          *(float *)(v54 + 72) = backgroundColor->g;
          *(float *)(v54 + 76) = backgroundColor->b;
          *(float *)(v54 + 80) = backgroundColor->a;
        }
        if ( v59[v48] == 1 )
        {
          startX = this->startX;
          this->curY += v46;
          this->curX = startX;
        }
        else
        {
          this->curX += *v50 * v47;
        }
        ++v48;
        v49 += 1024;
        ++v50;
      }
      while ( v48 <= v39 );
    }
  }
}


// ========================================================================
// ?AddPersistentText@idDebugHUDLocal@@UAAXHHABVidColor@@MPBDZZ
// EA  : 0x82673BC8
// RVA : 0x00673BC8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idDebugHUDLocal::AddPersistentText(
        idDebugHUDLocal *this,
        int x,
        int y,
        const idColor *color,
        double scale,
        const char *fmt,
        const char *a7,
        __int64 a8,
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
        int a21,
        int a22,
        ...)
{
  idDebugHUDLocal::debugText_t *v27; // r26
  BOOL alignRight; // r5
  int len; // r11
  __int64 v30; // [sp+E0h] [+40h] BYREF
  va_list va; // [sp+E0h] [+40h]
  __int64 v32; // [sp+E8h] [+48h]
  va_list va1; // [sp+F0h] [+50h] BYREF

  va_start(va1, a22);
  va_start(va, a22);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v30 = *(__int64 *)((char *)&a8 + 4);
  v32 = a8;
  idStr::vsnPrintf(dest: idDebugHUDLocal::buff, size: 1024, fmt: a7, argptr: va);
  this->RemovePersistentText(this, a2: x, a3: y);
  v27 = idList<idDebugHUDLocal::debugText_t,5>::Alloc(this: &this->persistentText);
  idStr::operator=(this: &v27->text, text: idDebugHUDLocal::buff);
  alignRight = this->alignRight;
  v27->scale = scale;
  v27->x = x;
  v27->y = y;
  len = v27->text.len;
  v27->flags = (!alignRight ? 0 : 8) | 0x17;
  v27->color = *color;
  v27->len = len;
}


// ========================================================================
// `dynamic initializer for 'debugHUDLocal''
// EA  : 0x8333B6E8
// RVA : 0x0133B6E8
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__debugHUDLocal__()
{
  idDebugHUDLocal::idDebugHUDLocal(this: &debugHUDLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__debugHUDLocal__);
}


// ========================================================================
// `dynamic initializer for 'com_debugHUD''
// EA  : 0x8333B720
// RVA : 0x0133B720
// PDB : w:\tech5\engine\framework\debughud.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_debugHUD__()
{
  idCVar::idCVar(
    this: &com_debugHUD,
    name: "com_debugHUD",
    value: "0",
    flags: 2,
    description: "1 = show debug HUD",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_debugHUD__);
}

