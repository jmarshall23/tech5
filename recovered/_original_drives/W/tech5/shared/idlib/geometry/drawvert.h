
// ========================================================================
// ??4idDrawVert@@QAAAAV0@ABV0@@Z
// EA  : 0x82560FC0
// RVA : 0x00560FC0
// PDB : w:\tech5\shared\idlib\geometry\drawvert.h
// ========================================================================

idDrawVert *__fastcall idDrawVert::operator=(idDrawVert *this, const idDrawVert *rhs)
{
  *this = *rhs;
  return this;
}


// ========================================================================
// ?GetNormal@idDrawVert@@QBA?BVidVec3@@XZ
// EA  : 0x82613A98
// RVA : 0x00613A98
// PDB : w:\tech5\shared\idlib\geometry\drawvert.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
const idVec3 *__fastcall idDrawVert::GetNormal(idDrawVert *this, const idVec3 *result, int a3, __int64 a4)
{
  __int128 v4; // r5
  double v5; // fp3
  double v6; // fp8
  double v7; // fp7
  double v10; // fp0
  double v11; // fp4
  double v12; // fp0
  const idVec3 *v13; // r3

  LODWORD(a4) = BYTE2(result[1].z);
  LODWORD(v4) = HIBYTE(result[1].z);
  DWORD2(v4) = BYTE1(result[1].z);
  v5 = (float)((float)((float)*(__int64 *)((char *)&v4 + 4) * (float)0.0078431377) - (float)1.0);
  v6 = (float)((float)((float)a4 * (float)0.0078431377) - (float)1.0);
  v7 = (float)((float)((float)(__int64)v4 * (float)0.0078431377) - (float)1.0);
  _FP4 = (float)((float)((float)((float)v7 * (float)v7)
                       + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f4, f5, f11 }
  v10 = __frsqrte(_FP1);
  v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10)
                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                              + (float)((float)((float)v6 * (float)v6)
                                                                      + (float)((float)v5 * (float)v5)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                                                              + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                      * (float)0.5))
                                                                      * (float)v10)
                                                              - (float)1.5)
                                              * (float)v10))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v10
                                                      * (float)((float)((float)((float)v7 * (float)v7)
                                                                      + (float)((float)((float)v6 * (float)v6)
                                                                              + (float)((float)v5 * (float)v5)))
                                                              * (float)0.5))
                                              * (float)v10)
                                      - (float)1.5)
                      * (float)v10));
  v12 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                              * (float)v10)
                                                                                      * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                      * (float)v10))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                                              * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5))
                                                                                      * (float)v10)
                                                                              - (float)1.5)
                                                              * (float)v10))
                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                              + (float)((float)((float)v6 * (float)v6)
                                                                      + (float)((float)v5 * (float)v5)))
                                                      * (float)0.5))
                                      * (float)v11)
                              - (float)1.5)
              * (float)v11);
  *(float *)DWORD1(v4) = (float)((float)((float)(__int64)v4 * (float)0.0078431377) - (float)1.0) * (float)v12;
  *(float *)(DWORD1(v4) + 4) = (float)((float)((float)*(__int64 *)((char *)&v4 + 4) * (float)0.0078431377) - (float)1.0)
                             * (float)v12;
  *(float *)(DWORD1(v4) + 8) = (float)((float)((float)a4 * (float)0.0078431377) - (float)1.0) * (float)v12;
  return v13;
}


// ========================================================================
// ?GetTangent@idDrawVert@@QBA?BVidVec3@@XZ
// EA  : 0x8279E838
// RVA : 0x0079E838
// PDB : w:\tech5\shared\idlib\geometry\drawvert.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
const idVec3 *__fastcall idDrawVert::GetTangent(idDrawVert *this, const idVec3 *result, int a3, __int64 a4)
{
  __int128 v4; // r5
  double v5; // fp3
  double v6; // fp8
  double v7; // fp7
  double v10; // fp0
  double v11; // fp4
  double v12; // fp0
  const idVec3 *v13; // r3

  LODWORD(a4) = BYTE2(result[2].x);
  LODWORD(v4) = HIBYTE(result[2].x);
  DWORD2(v4) = BYTE1(result[2].x);
  v5 = (float)((float)((float)*(__int64 *)((char *)&v4 + 4) * (float)0.0078431377) - (float)1.0);
  v6 = (float)((float)((float)a4 * (float)0.0078431377) - (float)1.0);
  v7 = (float)((float)((float)(__int64)v4 * (float)0.0078431377) - (float)1.0);
  _FP4 = (float)((float)((float)((float)v7 * (float)v7)
                       + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f4, f5, f11 }
  v10 = __frsqrte(_FP1);
  v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10)
                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                              + (float)((float)((float)v6 * (float)v6)
                                                                      + (float)((float)v5 * (float)v5)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                                                              + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                      * (float)0.5))
                                                                      * (float)v10)
                                                              - (float)1.5)
                                              * (float)v10))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v10
                                                      * (float)((float)((float)((float)v7 * (float)v7)
                                                                      + (float)((float)((float)v6 * (float)v6)
                                                                              + (float)((float)v5 * (float)v5)))
                                                              * (float)0.5))
                                              * (float)v10)
                                      - (float)1.5)
                      * (float)v10));
  v12 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                              * (float)v10)
                                                                                      * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                      * (float)v10))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                                              * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5))
                                                                                      * (float)v10)
                                                                              - (float)1.5)
                                                              * (float)v10))
                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                              + (float)((float)((float)v6 * (float)v6)
                                                                      + (float)((float)v5 * (float)v5)))
                                                      * (float)0.5))
                                      * (float)v11)
                              - (float)1.5)
              * (float)v11);
  *(float *)DWORD1(v4) = (float)((float)((float)(__int64)v4 * (float)0.0078431377) - (float)1.0) * (float)v12;
  *(float *)(DWORD1(v4) + 4) = (float)((float)((float)*(__int64 *)((char *)&v4 + 4) * (float)0.0078431377) - (float)1.0)
                             * (float)v12;
  *(float *)(DWORD1(v4) + 8) = (float)((float)((float)a4 * (float)0.0078431377) - (float)1.0) * (float)v12;
  return v13;
}


// ========================================================================
// ?SetBiTangent@idDrawVert@@QAAXABVidVec3@@@Z
// EA  : 0x827AD8E8
// RVA : 0x007AD8E8
// PDB : w:\tech5\shared\idlib\geometry\drawvert.h
// ========================================================================

void __fastcall idDrawVert::SetBiTangent(idDrawVert *this, const idVec3 *t, int a3, int a4, __int64 a5)
{
  const idVec3 *Tangent; // r29
  __int64 v8; // r8
  int v9; // r5
  const idVec3 *Normal; // r3
  unsigned __int8 v11; // r11
  idDrawVert v12[2]; // [sp+50h] [-40h] BYREF

  Tangent = idDrawVert::GetTangent(this: v12, result: &this->xyz, a3, a4: a5);
  Normal = idDrawVert::GetNormal(this: (idDrawVert *)&v12[0].st.y, result: &this->xyz, a3: v9, a4: v8);
  v11 = 0;
  if ( (float)((float)(t->x * (float)((float)(Tangent->z * Normal->y) - (float)(Tangent->y * Normal->z)))
             + (float)((float)(t->z * (float)((float)(Normal->x * Tangent->y) - (float)(Tangent->x * Normal->y)))
                     + (float)(t->y * (float)((float)(Tangent->x * Normal->z) - (float)(Normal->x * Tangent->z))))) >= 0.0 )
    v11 = -1;
  this->tangent[3] = v11;
}


// ========================================================================
// ?GetBiTangent@idDrawVert@@QBA?BVidVec3@@XZ
// EA  : 0x827C8950
// RVA : 0x007C8950
// PDB : w:\tech5\shared\idlib\geometry\drawvert.h
// ========================================================================

idDrawVert *__fastcall idDrawVert::GetBiTangent(idDrawVert *this, const idVec3 *result, int a3, int a4, __int64 a5)
{
  const idVec3 *Tangent; // r29
  __int64 v8; // r8
  int v9; // r5
  const idVec3 *Normal; // r3
  double z; // fp0
  unsigned int x_low; // r11
  double x; // fp11
  double y; // fp10
  double v15; // fp9
  double v16; // fp6
  double v17; // fp5
  double v18; // fp13
  double v19; // fp12
  double v20; // fp11
  double v21; // fp0
  idDrawVert v23[2]; // [sp+50h] [-40h] BYREF

  Tangent = idDrawVert::GetTangent(this: v23, result, a3, a4: a5);
  Normal = idDrawVert::GetNormal(this: (idDrawVert *)&v23[0].st.y, result, a3: v9, a4: v8);
  z = Tangent->z;
  x_low = LOBYTE(result[2].x);
  x = Tangent->x;
  y = Normal->y;
  v15 = Normal->z;
  v16 = (float)(Tangent->y * Normal->z);
  v17 = (float)(Normal->x * Tangent->z);
  v18 = (float)((float)(Normal->x * Tangent->y) - (float)(Tangent->x * Normal->y));
  this->xyz.z = (float)(Normal->x * Tangent->y) - (float)(Tangent->x * Normal->y);
  v19 = (float)((float)((float)z * (float)y) - (float)v16);
  this->xyz.x = (float)((float)z * (float)y) - (float)v16;
  v20 = (float)((float)((float)x * (float)v15) - (float)v17);
  this->xyz.y = v20;
  if ( x_low >= 0x80 )
    v21 = 1.0;
  else
    v21 = -1.0;
  this->xyz.x = (float)v19 * (float)v21;
  this->xyz.y = (float)v20 * (float)v21;
  this->xyz.z = (float)v18 * (float)v21;
  return this;
}


// ========================================================================
// ?LerpAll@idDrawVert@@QAAXABV1@0M@Z
// EA  : 0x827F3748
// RVA : 0x007F3748
// PDB : w:\tech5\shared\idlib\geometry\drawvert.h
// ========================================================================

void __fastcall idDrawVert::LerpAll(idDrawVert *this, const idDrawVert *a, const idDrawVert *b, double f)
{
  __int64 v5; // r8
  float z; // r9
  float y; // r6
  float x; // r10
  double v12; // fp3
  idVec2 st; // r5
  double v14; // fp7
  const idVec3 *Normal; // r3
  __int64 v16; // r8
  int v17; // r5
  const idVec3 *v18; // r3
  double v19; // fp2
  float v20; // r10
  int y_low; // r5
  double v22; // fp30
  double v23; // fp29
  double v24; // fp28
  __int64 v25; // r8
  const idVec3 *Tangent; // r3
  __int64 v27; // r8
  float v28; // r6
  int v29; // r5
  const idVec3 *v30; // r3
  double v31; // fp4
  float v32; // r9
  float v33; // r11
  double v34; // fp26
  double v35; // fp27
  double v36; // fp25
  __int64 v37; // r8
  int v38; // r6
  __int64 v39; // r8
  int v40; // r6
  int v41; // r5
  idDrawVert *BiTangent; // r3
  double v43; // fp5
  float v44; // r9
  float v45; // r8
  double v46; // fp7
  double v57; // fp6
  double v59; // fp5
  double v60; // fp4
  double v61; // fp1
  double v64; // fp13
  double v65; // fp11
  double v66; // fp11
  double v67; // fp10
  double v69; // fp10
  __int64 v75; // r7
  __int64 v76; // r4
  __int64 v77; // r9
  unsigned __int8 v78; // r11
  __int64 v79; // r10
  unsigned __int8 v80; // r11
  __int64 v81; // r11
  unsigned __int8 v82; // r11
  __int64 v83; // r11
  unsigned __int8 v84; // r11
  idDrawVert v85; // [sp+50h] [-C0h] BYREF
  idDrawVert v86; // [sp+70h] [-A0h] BYREF
  idDrawVert v87[2]; // [sp+90h] [-80h] BYREF

  *(float *)&v5 = b->xyz.y;
  LODWORD(v5) = LODWORD(b->xyz.x);
  z = a->xyz.z;
  y = a->xyz.y;
  *(float *)v85.tangent = b->xyz.z;
  *(_DWORD *)v85.normal = HIDWORD(v5);
  x = a->xyz.x;
  v85.xyz.z = z;
  v85.xyz.y = y;
  LODWORD(v85.st.y) = v5;
  v85.xyz.x = x;
  v12 = (float)((float)(*(float *)v85.tangent - z) * (float)f);
  this->xyz.x = (float)((float)(*((float *)&v5 + 1) - x) * (float)f) + x;
  this->xyz.y = (float)((float)(*(float *)&v5 - y) * (float)f) + y;
  this->xyz.z = (float)v12 + z;
  st = a->st;
  *(_QWORD *)&v85.xyz.x = *(_QWORD *)(LODWORD(st.x) + 12);
  *(idVec2 *)&v85.st.y = st;
  v14 = (float)((float)(v85.xyz.y - st.y) * (float)f);
  this->st.x = (float)((float)(v85.xyz.x - st.x) * (float)f) + st.x;
  this->st.y = (float)v14 + st.y;
  Normal = idDrawVert::GetNormal(this: &v85, result: (const idVec3 *)LODWORD(st.x), a3: SLODWORD(st.y), a4: v5);
  LODWORD(v16) = LODWORD(Normal->y);
  *(float *)&v16 = Normal->z;
  v85.st.y = Normal->x;
  *(_DWORD *)v85.tangent = HIDWORD(v16);
  *(_DWORD *)v85.normal = v16;
  v18 = idDrawVert::GetNormal(this: &v86, result: &a->xyz, a3: v17, a4: v16);
  v19 = *(float *)v85.tangent;
  v20 = v18->x;
  y_low = SLODWORD(v18->y);
  *(float *)v85.tangent = v18->z;
  v22 = (float)((float)((float)(v85.st.y - v20) * (float)f) + v20);
  v85.st.y = v20;
  v23 = (float)((float)((float)(*(float *)v85.normal - *(float *)&y_low) * (float)f) + *(float *)&y_low);
  *(_DWORD *)v85.normal = y_low;
  v24 = (float)((float)((float)((float)v19 - *(float *)v85.tangent) * (float)f) + *(float *)v85.tangent);
  Tangent = idDrawVert::GetTangent(this: (idDrawVert *)&v86.st.y, result: &b->xyz, a3: y_low, a4: v25);
  *(float *)&v27 = Tangent->y;
  v28 = Tangent->z;
  v85.st.y = Tangent->x;
  LODWORD(v27) = LODWORD(v85.st.y);
  *(_DWORD *)v85.normal = HIDWORD(v27);
  *(float *)v85.tangent = v28;
  v30 = idDrawVert::GetTangent(this: &v86, result: &a->xyz, a3: v29, a4: v27);
  v31 = *(float *)v85.tangent;
  v32 = v30->x;
  v33 = v30->y;
  *(float *)v85.tangent = v30->z;
  v34 = (float)((float)((float)(*(float *)v85.normal - v33) * (float)f) + v33);
  *(float *)v85.normal = v33;
  v35 = (float)((float)((float)(v85.st.y - v32) * (float)f) + v32);
  v85.st.y = v32;
  v36 = (float)((float)((float)((float)v31 - *(float *)v85.tangent) * (float)f) + *(float *)v85.tangent);
  LODWORD(v39) = idDrawVert::GetBiTangent(this: &v85, result: &b->xyz, a3: (int)v30, a4: v38, a5: v37);
  v40 = *(_DWORD *)(v39 + 4);
  v41 = *(_DWORD *)(v39 + 8);
  v85.st.y = *(float *)v39;
  *(float *)&v39 = v85.st.y;
  *(_DWORD *)v85.normal = v40;
  *(_DWORD *)v85.tangent = v41;
  BiTangent = idDrawVert::GetBiTangent(this: v87, result: &a->xyz, a3: v41, a4: v40, a5: v39);
  v43 = v85.st.y;
  v44 = BiTangent->xyz.y;
  v45 = BiTangent->xyz.z;
  v85.st.y = BiTangent->xyz.x;
  v46 = (float)((float)v43 - v85.st.y);
  _FP5 = (float)((float)((float)((float)v23 * (float)v23)
                       + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  _FP4 = (float)((float)((float)((float)v34 * (float)v34)
                       + (float)((float)((float)v35 * (float)v35) + (float)((float)v36 * (float)v36)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f0, f5, f0, f13 }
  __asm
  {
    fsel      f8, f4, f8, f13
    vspltisw128 v63, 0
  }
  _R6 = &v85.st.y;
  _R5 = v85.normal;
  _R4 = v85.tangent;
  __asm { vor128    v62, v95, v63 }
  _R10 = 2;
  _R11 = this->normal;
  v57 = __frsqrte(_FP8);
  HIDWORD(_R8) = v85.tangent;
  v59 = (float)((float)((float)(*(float *)v85.tangent - v45) * (float)f) + v45);
  LODWORD(_R8) = v85.normal;
  v60 = (float)((float)((float)v46 * (float)f) + v85.st.y);
  v61 = (float)((float)((float)(*(float *)v85.normal - v44) * (float)f) + v44);
  _R9 = 1;
  _FP10 = (float)((float)((float)((float)v61 * (float)v61)
                        + (float)((float)((float)v60 * (float)v60) + (float)((float)v59 * (float)v59)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f10, f10, f7, f13 }
  v64 = __frsqrte(_FP10);
  v65 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57
                                                                                      * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v35 * (float)v35) + (float)((float)v36 * (float)v36)))
                                                                                              * (float)0.5))
                                                                              * (float)v57)
                                                                      - (float)1.5)
                                                      * (float)v57)
                                              * (float)((float)((float)((float)v34 * (float)v34)
                                                              + (float)((float)((float)v35 * (float)v35)
                                                                      + (float)((float)v36 * (float)v36)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v57
                                                                              * (float)((float)((float)((float)v34 * (float)v34)
                                                                                              + (float)((float)((float)v35 * (float)v35) + (float)((float)v36 * (float)v36)))
                                                                                      * (float)0.5))
                                                                      * (float)v57)
                                                              - (float)1.5)
                                              * (float)v57))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v57
                                                      * (float)((float)((float)((float)v34 * (float)v34)
                                                                      + (float)((float)((float)v35 * (float)v35)
                                                                              + (float)((float)v36 * (float)v36)))
                                                              * (float)0.5))
                                              * (float)v57)
                                      - (float)1.5)
                      * (float)v57));
  v66 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v35 * (float)v35) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v57) - (float)1.5)
                                                                                              * (float)v57)
                                                                                      * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v35 * (float)v35) + (float)((float)v36 * (float)v36)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v35 * (float)v35) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v57) - (float)1.5)
                                                                                      * (float)v57))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v57
                                                                                              * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v35 * (float)v35) + (float)((float)v36 * (float)v36))) * (float)0.5))
                                                                                      * (float)v57)
                                                                              - (float)1.5)
                                                              * (float)v57))
                                              * (float)((float)((float)((float)v34 * (float)v34)
                                                              + (float)((float)((float)v35 * (float)v35)
                                                                      + (float)((float)v36 * (float)v36)))
                                                      * (float)0.5))
                                      * (float)v65)
                              - (float)1.5)
              * (float)v65);
  v67 = (float)((float)-(float)((float)((float)((float)v64
                                              * (float)((float)((float)((float)v61 * (float)v61)
                                                              + (float)((float)((float)v60 * (float)v60)
                                                                      + (float)((float)v59 * (float)v59)))
                                                      * (float)0.5))
                                      * (float)v64)
                              - (float)1.5)
              * (float)v64);
  __asm { lvlx128   v61, r0, r6 }
  __asm { lvlx128   v59, r0, r4 }
  __asm { vrlimi128 v62, v61, 8, 0 }
  __asm { lvlx128   v60, r0, r5 }
  v85.st.y = (float)v66 * (float)v35;
  *(float *)v85.normal = (float)v34 * (float)v66;
  *(float *)v85.tangent = (float)v36 * (float)v66;
  v69 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64
                                                                                      * (float)((float)((float)((float)v61 * (float)v61) + (float)((float)((float)v60 * (float)v60) + (float)((float)v59 * (float)v59)))
                                                                                              * (float)0.5))
                                                                              * (float)v64)
                                                                      - (float)1.5)
                                                      * (float)v64)
                                              * (float)((float)((float)((float)v61 * (float)v61)
                                                              + (float)((float)((float)v60 * (float)v60)
                                                                      + (float)((float)v59 * (float)v59)))
                                                      * (float)0.5))
                                      * (float)v67)
                              - (float)1.5)
              * (float)v67);
  v85.xyz.x = (float)((float)-(float)((float)((float)((float)v69
                                                    * (float)((float)((float)((float)v61 * (float)v61)
                                                                    + (float)((float)((float)v60 * (float)v60)
                                                                            + (float)((float)v59 * (float)v59)))
                                                            * (float)0.5))
                                            * (float)v69)
                                    - (float)1.5)
                    * (float)v69)
            * (float)v60;
  v85.xyz.y = (float)v61
            * (float)((float)-(float)((float)((float)((float)v69
                                                    * (float)((float)((float)((float)v61 * (float)v61)
                                                                    + (float)((float)((float)v60 * (float)v60)
                                                                            + (float)((float)v59 * (float)v59)))
                                                            * (float)0.5))
                                            * (float)v69)
                                    - (float)1.5)
                    * (float)v69);
  __asm { vrlimi128 v62, v60, 4, 3 }
  _R6 = &_vmx_3f8000003f8000003f8000003f800000;
  __asm { vor128    v58, v95, v63 }
  v85.xyz.z = (float)v59
            * (float)((float)-(float)((float)((float)((float)v69
                                                    * (float)((float)((float)((float)v61 * (float)v61)
                                                                    + (float)((float)((float)v60 * (float)v60)
                                                                            + (float)((float)v59 * (float)v59)))
                                                            * (float)0.5))
                                            * (float)v69)
                                    - (float)1.5)
                    * (float)v69);
  _R28 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
  __asm { vrlimi128 v62, v59, 2, 2 }
  _R5 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
  __asm { lvx128    v63, r0, r6 }
  _R27 = &v85.st.y;
  __asm
  {
    vaddfp128 v12, v94, v63
    lvx128    v13, r0, r28
    lvx128    v0, r0, r5
    vmaddfp   v0, v12, v0, v13
    vcfpsxws128 v57, v0, 0
    vpkswss128 v56, v89, v57
    vpkshus128 v0, v88, v56
    stvebx    v0, 0, r11
    stvebx    v0, r11, r9
    stvebx    v0, r11, r10
  }
  _R11 = this->tangent;
  __asm
  {
    lvlx128   v55, r0, r7
    lvx128    v0, r0, r5
    lvx128    v13, r0, r28
    lvlx128   v54, r0, r27
    vrlimi128 v58, v54, 8, 0
    lvx128    v63, r0, r6
    lvlx128   v53, r0, r8
    vrlimi128 v58, v53, 4, 3
    vrlimi128 v58, v55, 2, 2
    vaddfp128 v12, v90, v63
    vmaddfp   v0, v12, v0, v13
    vcfpsxws128 v52, v0, 0
    vpkswss128 v51, v84, v52
    vpkshus128 v0, v83, v51
    stvebx    v0, 0, r11
    stvebx    v0, r11, r9
    stvebx    v0, r11, r10
  }
  idDrawVert::SetBiTangent(
    this,
    t: &v85.xyz,
    a3: (int)&`VertexFloatToByte'::`2'::SIMD_SP_half,
    a4: (int)&_vmx_3f8000003f8000003f8000003f800000,
    a5: _R8);
  LODWORD(v76) = a->color[0];
  HIDWORD(v76) = b->color[0];
  LODWORD(v77) = HIDWORD(v76) - v76;
  *(_DWORD *)v85.normal = (int)(float)((float)((float)v77 * (float)f) + (float)v76);
  v78 = v85.normal[3];
  if ( *(int *)v85.normal >= 0 )
  {
    if ( *(int *)v85.normal > 255 )
      v78 = -1;
  }
  else
  {
    v78 = 0;
  }
  this->color[0] = v78;
  LODWORD(v79) = a->color[1];
  HIDWORD(v79) = v79;
  LODWORD(v75) = b->color[1] - (_DWORD)v79;
  *(_DWORD *)v85.normal = (int)(float)((float)((float)v75 * (float)f) + (float)v79);
  v80 = v85.normal[3];
  if ( *(int *)v85.normal >= 0 )
  {
    if ( *(int *)v85.normal > 255 )
      v80 = -1;
  }
  else
  {
    v80 = 0;
  }
  this->color[1] = v80;
  LODWORD(v81) = a->color[2];
  HIDWORD(v81) = b->color[2];
  LODWORD(v75) = HIDWORD(v81) - v81;
  *(_DWORD *)v85.normal = (int)(float)((float)((float)v75 * (float)f) + (float)v81);
  v82 = v85.normal[3];
  if ( *(int *)v85.normal >= 0 )
  {
    if ( *(int *)v85.normal > 255 )
      v82 = -1;
  }
  else
  {
    v82 = 0;
  }
  this->color[2] = v82;
  LODWORD(v83) = a->color[3];
  HIDWORD(v83) = b->color[3];
  LODWORD(v75) = HIDWORD(v83) - v83;
  *(_DWORD *)v85.normal = (int)(float)((float)((float)v75 * (float)f) + (float)v83);
  v84 = v85.normal[3];
  if ( *(int *)v85.normal >= 0 )
  {
    if ( *(int *)v85.normal > 255 )
      v84 = -1;
    this->color[3] = v84;
  }
  else
  {
    this->color[3] = 0;
  }
}

