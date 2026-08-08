
// ========================================================================
// ?DrawStretchPic@idRenderModelGui@@QAAXMMMMMMMMPBVidMaterial@@@Z
// EA  : 0x82670760
// RVA : 0x00670760
// PDB : w:\tech5\engine\models\rendermodelgui.h
// ========================================================================

void __fastcall idRenderModelGui::DrawStretchPic(
        idRenderModelGui *this,
        double x,
        double y,
        double w,
        double h,
        double s1,
        double t1,
        double s2,
        double t2,
        const idMaterial *material,
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
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        const idMaterial *a38)
{
  idVec4 v38; // [sp+50h] [-50h] BYREF
  idVec4 v39; // [sp+60h] [-40h] BYREF
  idVec4 v40; // [sp+70h] [-30h] BYREF
  idVec4 v41; // [sp+80h] [-20h] BYREF

  v38.x = x;
  v38.z = s1;
  v38.w = t2;
  v39.z = s2;
  v39.w = t2;
  v40.y = y;
  v40.z = s2;
  v40.w = t1;
  v38.y = (float)y + (float)h;
  v39.x = (float)x + (float)w;
  v39.y = v38.y;
  v40.x = v39.x;
  v41.x = x;
  v41.y = y;
  v41.z = s1;
  v41.w = t1;
  idRenderModelGui::DrawStretchPic(
    this,
    topLeft: &v41,
    topRight: &v40,
    bottomRight: &v39,
    bottomLeft: &v38,
    material: a38);
}


// ========================================================================
// ?DrawStretchPic@idRenderModelGui@@QAAXABVidVec4@@0PBVidMaterial@@@Z
// EA  : 0x826707E0
// RVA : 0x006707E0
// PDB : w:\tech5\engine\models\rendermodelgui.h
// ========================================================================

void __fastcall idRenderModelGui::DrawStretchPic(
        idRenderModelGui *this,
        const idVec4 *rect,
        const idVec4 *st,
        const idMaterial *material)
{
  double y; // fp0
  double x; // fp13
  double v6; // fp10
  double w; // fp9
  double v8; // fp8
  double z; // fp7
  double v10; // fp6
  double v11; // fp5
  idVec4 v12; // [sp+50h] [-50h] BYREF
  idVec4 v13; // [sp+60h] [-40h] BYREF
  idVec4 v14; // [sp+70h] [-30h] BYREF
  idVec4 v15; // [sp+80h] [-20h] BYREF

  y = rect->y;
  x = rect->x;
  v6 = (float)(rect->y + rect->w);
  w = st->w;
  v8 = (float)(rect->x + rect->z);
  z = st->z;
  v10 = st->y;
  v11 = st->x;
  v14.y = rect->y;
  v12.x = x;
  v12.w = w;
  v13.z = z;
  v13.w = w;
  v12.z = v11;
  v14.z = z;
  v14.w = v10;
  v15.x = x;
  v15.y = y;
  v12.y = v6;
  v13.x = v8;
  v13.y = v6;
  v14.x = v8;
  v15.z = v11;
  v15.w = v10;
  idRenderModelGui::DrawStretchPic(this, topLeft: &v15, topRight: &v14, bottomRight: &v13, bottomLeft: &v12, material);
}

