
// ========================================================================
// ?TestVMTR_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294B6A8
// RVA : 0x0094B6A8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall TestVMTR_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v3; // r27
  int v4; // r4

  idCVar::SetString(this: &r_currentMaterial, newValue: nullptr, force: true);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_testVMTR", a3: 0, a4: 0);
  argc = args->argc;
  if ( args->argc == 2 || argc == 3 )
  {
    if ( argc <= 1 )
    {
      v3 = &byte_8200D768;
    }
    else
    {
      v3 = args->argv[1];
      if ( v3 == nullptr )
        return;
    }
    v4 = 0;
    if ( argc == 3 )
      v4 = atol(nptr: args->argv[2]);
    idCVar::SetInteger(this: &r_testVMTRLod, newValue: v4, force: true);
    idCVar::SetString(this: &r_currentMaterial, newValue: v3, force: true);
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_testVMTR", a3: 1, a4: 0);
  }
}


// ========================================================================
// ?R_ScreenshotFilename@@YAXAAHPBDAAVidStr@@W4screenshotFormat_t@@@Z
// EA  : 0x8294B790
// RVA : 0x0094B790
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall R_ScreenshotFilename(int *lastNumber, const char *base, idStr *fileName, screenshotFormat_t format)
{
  int v5; // r11
  const char *v8; // [sp+8h] [-C8h]

  v5 = *lastNumber + 1;
  *lastNumber = v5;
  if ( v5 <= 99999 )
  {
    for ( ; v5 < 99999; *lastNumber = v5 )
    {
      idStr::Format(
        this: fileName,
        fmt: "%s%i%i%i%i%i.%s",
        base,
        v5 / 10000,
        v5 % 10000 / 1000,
        v5 % 10000 % 1000 / 100,
        v5 % 10000 % 1000 % 100 / 10,
        v5 % 10000 % 1000 % 100 % 10,
        v8);
      if ( *lastNumber == 99999 )
        break;
      if ( !fileSystem->FileExists(this: fileSystem, a2: fileName->data, a3: false) )
        break;
      v5 = *lastNumber + 1;
    }
  }
  else
  {
    *lastNumber = 99999;
  }
}


// ========================================================================
// ?R_SampleCubeMap@@YAXABVidVec3@@HQAPAEQAE@Z
// EA  : 0x8294B8C0
// RVA : 0x0094B8C0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall R_SampleCubeMap(const idVec3 *dir, int size, unsigned __int8 **buffers, unsigned __int8 *result)
{
  int v4; // r30 OVERLAPPED
  double y; // fp13
  double v6; // fp11
  double x; // fp0
  double z; // fp10
  double v9; // fp9
  double v10; // fp12
  int v11; // r7
  idMat3 *v12; // r8
  int v14; // r10
  int v15; // r9
  int v16; // r10

  y = dir->y;
  v6 = __fabs(y);
  x = dir->x;
  z = dir->z;
  v9 = __fabs(x);
  v10 = __fabs(z);
  if ( x < v6 || x < v10 )
  {
    if ( -x < v6 || -x < v10 )
    {
      if ( y < v9 || y < v10 )
      {
        if ( -y < v9 || -y < v10 )
        {
          if ( z < v6 || (v11 = 4, z < v10) )
            v11 = 5;
        }
        else
        {
          v11 = 3;
        }
      }
      else
      {
        v11 = 2;
      }
    }
    else
    {
      v11 = 1;
    }
  }
  else
  {
    v11 = 0;
  }
  v12 = &cubeAxis_0[v11];
  v14 = (int)(float)((float)((float)((float)-(float)((float)((float)(cubeAxis_0[v11].mat[1].x * dir->x)
                                                           + (float)((float)(cubeAxis_0[v11].mat[1].y * dir->y)
                                                                   + (float)(cubeAxis_0[v11].mat[1].z * dir->z)))
                                                   / (float)((float)(v12->mat[0].x * dir->x)
                                                           + (float)((float)(v12->mat[0].y * dir->y)
                                                                   + (float)(v12->mat[0].z * dir->z))))
                                   + (float)1.0)
                           * (float)*(__int64 *)(&v4 - 1))
                   * (float)0.5);
  v15 = (int)(float)((float)((float)((float)-(float)((float)((float)(dir->x * cubeAxis_0[v11].mat[2].x)
                                                           + (float)((float)(cubeAxis_0[v11].mat[2].y * dir->y)
                                                                   + (float)(cubeAxis_0[v11].mat[2].z * dir->z)))
                                                   / (float)((float)(v12->mat[0].x * dir->x)
                                                           + (float)((float)(v12->mat[0].y * dir->y)
                                                                   + (float)(v12->mat[0].z * dir->z))))
                                   + (float)1.0)
                           * (float)*(__int64 *)(&v4 - 1))
                   * (float)0.5);
  if ( v14 >= 0 )
  {
    if ( v14 >= size )
      v14 = size - 1;
  }
  else
  {
    v14 = 0;
  }
  if ( v15 >= 0 )
  {
    if ( v15 >= size )
      v15 = size - 1;
  }
  else
  {
    v15 = 0;
  }
  v16 = 4 * (v15 * size + v14);
  *result = buffers[v11][v16];
  result[1] = buffers[v11][v16 + 1];
  result[2] = buffers[v11][v16 + 2];
  result[3] = buffers[v11][v16 + 3];
}


// ========================================================================
// ?MakeAmbientMap_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294BAD0
// RVA : 0x0094BAD0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall MakeAmbientMap_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v3; // r3
  int v4; // r11
  idVec3 *v5; // r28
  int v6; // r10
  const char *v7; // r25
  int v8; // r11
  int v9; // r24
  int v10; // r16
  idMem *v11; // r23
  unsigned __int8 **v12; // r30
  int v13; // r26
  int v14; // r4
  int v15; // r5
  unsigned __int8 *v16; // r22
  int v17; // r10
  int v18; // r12
  __int64 v19; // r10 OVERLAPPED
  _DWORD *v20; // r18
  float *p_z; // r28
  int v22; // r22
  char *v23; // r21
  double v24; // fp19
  int v25; // r11
  int v26; // r26
  _BYTE *v27; // r27
  double v28; // fp24
  int v29; // r11
  double v30; // fp13
  double v31; // fp12
  double v32; // fp20
  double v33; // fp21
  double v34; // fp22
  double v35; // fp5
  double v36; // fp12
  double v37; // fp11
  double v38; // fp10
  double v41; // fp3
  double v42; // fp7
  double v43; // fp30
  double v44; // fp29
  double v45; // fp28
  double v46; // fp26
  int v47; // r30
  void **v48; // r29
  int v49; // r25
  int v50; // r30
  float *v51; // r29
  __int64 v52; // r10
  double x; // fp11
  double v54; // fp0
  double v57; // fp6
  double v58; // fp13
  __int64 v59; // r3 OVERLAPPED
  __int64 v60; // r5 OVERLAPPED
  int v61; // r6
  const char *v62; // r4
  void **v63; // r30
  int i; // r29
  _DWORD back_chain[20]; // [sp+0h] [-640h]
  int v66; // [sp+50h] [-5F0h] BYREF
  int v67; // [sp+54h] [-5ECh] BYREF
  unsigned __int8 v68[4]; // [sp+58h] [-5E8h] BYREF
  char *v69; // [sp+5Ch] [-5E4h] BYREF
  idVec3 v70; // [sp+60h] [-5E0h] BYREF
  const char *v71; // [sp+6Ch] [-5D4h]
  const char *v72; // [sp+70h] [-5D0h]
  const char *v73; // [sp+74h] [-5CCh]
  idMem *v74; // [sp+78h] [-5C8h]
  const char *v75; // [sp+7Ch] [-5C4h]
  const char *v76; // [sp+80h] [-5C0h]
  int v78; // [sp+8Ch] [-5B4h]
  _QWORD v79[12]; // [sp+90h] [-5B0h] BYREF
  unsigned __int8 *v80[8]; // [sp+F0h] [-550h] BYREF
  char v81[1176]; // [sp+110h] [-530h] BYREF

  argc = args->argc;
  if ( args->argc < 2 || argc > 4 )
  {
    idLib::Printf(fmt: "USAGE: MakeAmbientMap [camera] <basename> [size]\n");
  }
  else
  {
    HIDWORD(v79[0]) = "_px.tga";
    LODWORD(v70.z) = "_left.tga";
    LODWORD(v79[0]) = "_nx.tga";
    HIDWORD(v79[1]) = "_py.tga";
    LODWORD(v79[1]) = "_ny.tga";
    HIDWORD(v79[2]) = "_pz.tga";
    LODWORD(v79[2]) = "_nz.tga";
    LODWORD(v70.x) = "_forward.tga";
    LODWORD(v70.y) = "_back.tga";
    v71 = "_right.tga";
    v72 = "_up.tga";
    v73 = "_down.tga";
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    if ( idStr::Icmp(s1: v3, s2: "camera") != 0 )
    {
      v4 = 1;
      v5 = (idVec3 *)v79;
    }
    else
    {
      v4 = 2;
      v5 = &v70;
    }
    v6 = args->argc;
    if ( v4 >= args->argc )
    {
      v69 = &byte_8200D768;
      v7 = &byte_8200D768;
    }
    else
    {
      v7 = args->argv[v4];
      v69 = (char *)v7;
    }
    if ( v6 == v4 + 2 )
    {
      v8 = v4 + 1;
      if ( v8 < 0 || v8 >= v6 )
        v9 = atol(nptr: &byte_8200D768);
      else
        v9 = atol(nptr: args->argv[v8]);
    }
    else
    {
      v9 = 32;
    }
    memset(Dst: cubeAxis_0, Val: 0, Size: sizeof(cubeAxis_0));
    v10 = 0;
    cubeAxis_0[0].mat[0].x = 1.0;
    v11 = &mem;
    cubeAxis_0[0].mat[1].z = 1.0;
    cubeAxis_0[0].mat[2].y = 1.0;
    v66 = 0;
    cubeAxis_0[1].mat[0].x = -1.0;
    v12 = v80;
    cubeAxis_0[1].mat[1].z = -1.0;
    v67 = 0;
    cubeAxis_0[1].mat[2].y = 1.0;
    v13 = 0;
    cubeAxis_0[2].mat[0].y = 1.0;
    cubeAxis_0[2].mat[1].x = -1.0;
    v74 = &mem;
    cubeAxis_0[2].mat[2].z = -1.0;
    cubeAxis_0[3].mat[0].y = -1.0;
    cubeAxis_0[3].mat[1].x = -1.0;
    cubeAxis_0[3].mat[2].z = 1.0;
    cubeAxis_0[4].mat[0].z = 1.0;
    cubeAxis_0[4].mat[1].x = -1.0;
    cubeAxis_0[4].mat[2].y = 1.0;
    cubeAxis_0[5].mat[0].z = -1.0;
    cubeAxis_0[5].mat[1].x = 1.0;
    cubeAxis_0[5].mat[2].y = 1.0;
    while ( 1 )
    {
      sprintf_0(string: v81, format: "env/%s%s", v7, *(const char **)((char *)v12 + (char *)v5 - (char *)v80));
      idLib::Printf(fmt: "loading %s\n", v81);
      common->UpdateConsoleDisplay(this: common, a2: true);
      R_LoadImage(cname: v81, pic: v12, width: &v66, height: &v67, timestamp: nullptr);
      if ( *v12 == nullptr )
        break;
      v14 = v66;
      if ( v66 > 32 )
      {
        v15 = v67;
        do
        {
          v16 = R_MipMap(in: *v12, width: v14, height: v15);
          idMem::Free(this: &mem, ptr: *v12, align: ALIGN_16);
          v17 = v67;
          v14 = v66 >> 1;
          *v12 = v16;
          v15 = v17 >> 1;
          v66 = v14;
          v67 = v17 >> 1;
        }
        while ( v14 > 32 );
      }
      ++v13;
      ++v12;
      if ( v13 >= 6 )
      {
        ((void (*)(void))RtlCheckStack12)();
        *(_DWORD *)((char *)back_chain + v18) = back_chain[0];
        HIDWORD(v19) = "Mips";
        v75 = "env/%s_spec%s";
        v76 = "env/%s_amb%s";
        do
        {
          v20 = v79;
          p_z = &cubeAxis_0[0].mat[2].z;
          do
          {
            v22 = 0;
            if ( v9 > 0 )
            {
              LODWORD(v19) = v9 - 1;
              v23 = (char *)&v66 + 2;
              v79[6] = v19;
              v24 = (float)v19;
              do
              {
                v25 = v22;
                v26 = 0;
                v79[4] = *(__int64 *)((char *)&v19 - 4);
                v27 = v23;
                v28 = -(float)((float)((float)((float)*(__int64 *)((char *)&v19 - 4) * (float)2.0) / (float)v24)
                             - (float)1.0);
                do
                {
                  v29 = v26;
                  v30 = (float)(*(p_z - 3) * (float)v28);
                  v31 = *(p_z - 5);
                  v79[3] = *(__int64 *)((char *)&v19 - 4);
                  v32 = 0.0;
                  v33 = 0.0;
                  v34 = 0.0;
                  v35 = -(float)((float)((float)((float)*(__int64 *)((char *)&v19 - 4) * (float)2.0) / (float)v24)
                               - (float)1.0);
                  v37 = (float)((float)(*(p_z - 8) + (float)((float)v28 * (float)v31)) + (float)(*(p_z - 2) * (float)v35));
                  v36 = (float)((float)(*(p_z - 6) + (float)v30) + (float)(*p_z * (float)v35));
                  v38 = (float)((float)(*(p_z - 7) + (float)(*(p_z - 4) * (float)v28)) + (float)(*(p_z - 1) * (float)v35));
                  _FP6 = (float)((float)((float)((float)v38 * (float)v38)
                                       + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                               - idMath::FLT_SMALLEST_NON_DENORMAL);
                  __asm { fsel      f4, f6, f7, f0 }
                  v41 = __frsqrte(_FP4);
                  v42 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5))
                                                                                              * (float)v41)
                                                                                      - (float)1.5)
                                                                      * (float)v41)
                                                              * (float)((float)((float)((float)v38 * (float)v38)
                                                                              + (float)((float)((float)v37 * (float)v37)
                                                                                      + (float)((float)v36 * (float)v36)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v41
                                                                                              * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5))
                                                                                      * (float)v41)
                                                                              - (float)1.5)
                                                              * (float)v41))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v41
                                                                      * (float)((float)((float)((float)v38 * (float)v38)
                                                                                      + (float)((float)((float)v37 * (float)v37)
                                                                                              + (float)((float)v36 * (float)v36)))
                                                                              * (float)0.5))
                                                              * (float)v41)
                                                      - (float)1.5)
                                      * (float)v41));
                  v43 = (float)((float)v37
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41) * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                      * (float)v41))
                                                                      * (float)((float)((float)((float)v38 * (float)v38)
                                                                                      + (float)((float)((float)v37 * (float)v37)
                                                                                              + (float)((float)v36 * (float)v36)))
                                                                              * (float)0.5))
                                                              * (float)v42)
                                                      - (float)1.5)
                                      * (float)v42));
                  v44 = (float)((float)v38
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41) * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                      * (float)v41))
                                                                      * (float)((float)((float)((float)v38 * (float)v38)
                                                                                      + (float)((float)((float)v37 * (float)v37)
                                                                                              + (float)((float)v36 * (float)v36)))
                                                                              * (float)0.5))
                                                              * (float)v42)
                                                      - (float)1.5)
                                      * (float)v42));
                  v45 = (float)((float)v36
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41) * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                      * (float)v41))
                                                                      * (float)((float)((float)((float)v38 * (float)v38)
                                                                                      + (float)((float)((float)v37 * (float)v37)
                                                                                              + (float)((float)v36 * (float)v36)))
                                                                              * (float)0.5))
                                                              * (float)v42)
                                                      - (float)1.5)
                                      * (float)v42));
                  if ( v10 != 0 )
                    v46 = 0.94999999;
                  else
                    v46 = 0.25;
                  v49 = 0;
                  while ( 1 )
                  {
                    v50 = 3;
                    v51 = (float *)&v69;
                    do
                    {
                      --v50;
                      LODWORD(v52) = (2 * rand()) & 0xFFFE;
                      v79[8] = v52;
                      *++v51 = (float)((float)v52 * (float)0.000030518509) - (float)1.0;
                    }
                    while ( v50 != 0 );
                    x = v70.x;
                    v54 = (float)((float)(v70.z * v70.z) + (float)((float)(v70.x * v70.x) + (float)(v70.y * v70.y)));
                    if ( __fsqrts(v54) <= 1.0 )
                    {
                      _FP8 = (float)((float)((float)(v70.z * v70.z)
                                           + (float)((float)(v70.x * v70.x) + (float)(v70.y * v70.y)))
                                   - idMath::FLT_SMALLEST_NON_DENORMAL);
                      __asm { fsel      f7, f8, f0, f13 }
                      v57 = __frsqrte(_FP7);
                      v58 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5))
                                                                                                  * (float)v57)
                                                                                          - (float)1.5)
                                                                          * (float)v57)
                                                                  * (float)((float)v54 * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)((float)v57
                                                                                                  * (float)((float)v54 * (float)0.5))
                                                                                          * (float)v57)
                                                                                  - (float)1.5)
                                                                  * (float)v57))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5))
                                                                  * (float)v57)
                                                          - (float)1.5)
                                          * (float)v57));
                      v70.z = v70.z
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57) * (float)((float)v54 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57))
                                                                                            - (float)1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5)
                                                                                    * (float)v57))
                                                                    * (float)((float)v54 * (float)0.5))
                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57) * (float)((float)v54 * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57)
                                                                                            - (float)1.5)
                                                                            * (float)v57)))
                                                    - (float)1.5)
                                    * (float)v58);
                      v70.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57) * (float)((float)v54 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57))
                                                                                            - (float)1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5)
                                                                                    * (float)v57))
                                                                    * (float)((float)v54 * (float)0.5))
                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57) * (float)((float)v54 * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57)
                                                                                            - (float)1.5)
                                                                            * (float)v57)))
                                                    - (float)1.5)
                                    * (float)v58)
                            * v70.x;
                      v70.y = v70.y
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57) * (float)((float)v54 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57))
                                                                                            - (float)1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5)
                                                                                    * (float)v57))
                                                                    * (float)((float)v54 * (float)0.5))
                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57) * (float)((float)v54 * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57)
                                                                                            - (float)1.5)
                                                                            * (float)v57)))
                                                    - (float)1.5)
                                    * (float)v58);
                      if ( (float)((float)(v70.y * (float)v44)
                                 + (float)((float)((float)v43
                                                 * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57) * (float)((float)v54 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57)) - (float)1.5) * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57))
                                                                                                 * (float)((float)v54 * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57) * (float)((float)v54 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57)) - (float)1.5)
                                                                                                 * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)v54 * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57)))
                                                                                 - (float)1.5)
                                                                 * (float)v58)
                                                         * (float)x))
                                         + (float)(v70.z * (float)v45))) > v46 )
                      {
                        R_SampleCubeMap(dir: &v70, size: v66, buffers: v80, result: v68);
                        ++v49;
                        LODWORD(v59) = v68[2];
                        LODWORD(v60) = v68[1];
                        v79[7] = v59;
                        v79[9] = v60;
                        v61 = v68[0];
                        v79[5] = *(__int64 *)((char *)&v60 - 4);
                        v34 = (float)((float)*(__int64 *)((char *)&v60 - 4) + (float)v34);
                        v32 = (float)((float)v59 + (float)v32);
                        v33 = (float)((float)v60 + (float)v33);
                        if ( v49 >= 500 )
                          break;
                      }
                    }
                  }
                  ++v26;
                  v27[1] = -1;
                  LODWORD(v19) = (int)(float)((float)v32 * (float)0.0020000001);
                  LODWORD(v79[10]) = (int)(float)((float)v34 * (float)0.0020000001);
                  v78 = (int)(float)((float)v33 * (float)0.0020000001);
                  *v27 = v19;
                  *(v27 - 2) = (int)(float)((float)v34 * (float)0.0020000001);
                  *(v27 - 1) = (int)(float)((float)v33 * (float)0.0020000001);
                  v27 += 4 * v9;
                }
                while ( v26 < v9 );
                ++v22;
                v23 += 4;
              }
              while ( v22 < v9 );
              v7 = v69;
              v11 = v74;
            }
            v62 = v76;
            if ( v10 != 0 )
              v62 = v75;
            sprintf_0(string: v81, format: v62, v7, *v20);
            idLib::Printf(fmt: "Writing %s\n", v81);
            common->UpdateConsoleDisplay(this: common, a2: true);
            R_WriteTGA(
              filename: v81,
              data: (char *)&v66,
              width: v9,
              height: v9,
              depth: 4,
              flipVertical: false,
              swapRGB: true,
              basePath: FSPATH_BASE);
            p_z += 9;
            HIDWORD(v19) = &GfxInfo_v.description_;
            ++v20;
          }
          while ( (int)p_z < (int)&GfxInfo_v.description_ );
          ++v10;
        }
        while ( v10 < 2 );
        v63 = (void **)v80;
        for ( i = 6; i != 0; --i )
        {
          if ( *v63 != nullptr )
            idMem::Free(this: v11, ptr: *v63, align: ALIGN_16);
          ++v63;
        }
        return;
      }
    }
    idLib::Printf(fmt: "failed.\n");
    v47 = v13 - 1;
    if ( v13 - 1 >= 0 )
    {
      v48 = (void **)&v80[v47 + 1];
      do
      {
        idMem::Free(this: &mem, ptr: *--v48, align: ALIGN_16);
        --v47;
      }
      while ( v47 >= 0 );
    }
  }
}


// ========================================================================
// ?ArgCompletion_ImageName@@YAXAAVidAutoComplete@@@Z
// EA  : 0x8294C270
// RVA : 0x0094C270
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall ArgCompletion_ImageName(idAutoComplete *autoComplete)
{
  int i; // r28
  const char *str; // r30
  int v4; // r29
  char *v5; // r10
  char *v6; // r9
  char v7; // r11
  idStr v8[3]; // [sp+50h] [-70h] BYREF

  for ( i = 0; i < idImage::resourceList.num; ++i )
  {
    str = idResourceList::Index(this: &idImage::resourceList, index: i)->name.str;
    if ( *str == 95 )
    {
      v8[0].allocedAndFlag = 20;
      v8[0].len = 0;
      v4 = 0;
      v8[0].data = v8[0].baseBuffer;
      v8[0].baseBuffer[0] = 0;
      if ( *str != 0 )
      {
        do
          ++v4;
        while ( str[v4] != 0 );
      }
      idStr::EnsureAlloced(this: v8, amount: v4 + 1, keepold: true, geometricGrowth: false);
      v5 = (char *)(str - 1);
      v6 = v8[0].data - 1;
      do
      {
        v7 = *++v5;
        *++v6 = *v5;
      }
      while ( v7 != 0 );
      v8[0].len = v4;
      idAutoComplete::Append(this: autoComplete, suggestion: v8, completingArg: -1);
      idStr::FreeData(this: v8);
    }
  }
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "/", a4: "tga", a5: true);
}


// ========================================================================
// __unwind$234785
// EA  : 0x8294C38C
// RVA : 0x0094C38C
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_234785()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?R_TestImage_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294C3B8
// RVA : 0x0094C3B8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall R_TestImage_f(const idCmdArgs *inArgs)
{
  char v1; // r20
  double v3; // fp31
  char v4; // r21
  int v5; // r31
  int argc; // r10
  int v7; // r29
  char **argv; // r30
  const char **v9; // r28
  const char *v10; // r3
  const char *v11; // r3
  const char *v12; // r3
  const char *v13; // r3
  long double v14; // fp2
  const char *v15; // r4
  const char *v16; // r3
  const char *v17; // r3
  int v18; // r4
  char *v19; // r4
  const char *v20; // r4
  long double v21; // fp2
  idDeclRenderParm *v22; // r3
  idDeclRenderParm *v23; // r3
  idPlane v24; // [sp+50h] [-990h] BYREF
  idCmdArgs v25; // [sp+60h] [-980h] BYREF

  v1 = 0;
  v25.argc = 0;
  v3 = 0.0;
  tr.testImage = nullptr;
  v4 = 0;
  tr.testMaterial = nullptr;
  v5 = 0;
  argc = inArgs->argc;
  if ( inArgs->argc <= 0 )
    goto LABEL_34;
  v7 = 1;
  argv = inArgs->argv;
  v9 = (const char **)&v25.argv[1];
  do
  {
    if ( v5 < 0 || v5 >= argc )
      v10 = &byte_8200D768;
    else
      v10 = *argv;
    if ( idStr::Icmp(s1: v10, s2: "-flipX") != 0 )
    {
      if ( v5 < 0 || v5 >= inArgs->argc )
        v11 = &byte_8200D768;
      else
        v11 = *argv;
      if ( idStr::Icmp(s1: v11, s2: "-flipY") != 0 )
      {
        if ( v5 < 0 || v5 >= inArgs->argc )
          v12 = &byte_8200D768;
        else
          v12 = *argv;
        if ( idStr::Icmp(s1: v12, s2: "-lod") != 0 )
        {
          if ( v5 < 0 || v5 >= inArgs->argc )
            v15 = &byte_8200D768;
          else
            v15 = *argv;
          idCmdArgs::AppendArg(this: &v25, text: v15);
        }
        else
        {
          if ( v7 < 0 || v7 >= v25.argc )
            v13 = &byte_8200D768;
          else
            v13 = *v9;
          v14 = atof(nptr: v13);
          v3 = (float)*(double *)&v14;
          ++v7;
          ++v5;
          ++v9;
          ++argv;
        }
      }
      else
      {
        v1 = 1;
      }
    }
    else
    {
      v4 = 1;
    }
    argc = inArgs->argc;
    ++v7;
    ++v9;
    ++argv;
    ++v5;
  }
  while ( v5 < inArgs->argc );
  if ( v25.argc != 1 )
  {
    if ( v25.argc != 2 && v25.argc != 3 )
    {
LABEL_34:
      idLib::Printf(fmt: "usage: testImage [-flipX] [-flipY] [-lod val] image\n");
      return;
    }
    idDeclInfo::FindWithInheritance(this: &idDeclRenderProg::resourceList, name: "cubeImageOnly", makeDefault: true);
    idDeclInfo::FindWithInheritance(this: &idDeclRenderProg::resourceList, name: "testImage", makeDefault: true);
    v16 = v25.argv[1];
    if ( v25.argc <= 1 )
      v16 = &byte_8200D768;
    if ( idStr::IsNumeric(s: v16) )
    {
      v17 = v25.argv[1];
      if ( v25.argc <= 1 )
        v17 = &byte_8200D768;
      v18 = atol(nptr: v17);
      if ( v18 >= 0 && v18 < idImage::resourceList.num )
        tr.testImage = (idImage *)idResourceList::Index(this: &idImage::resourceList, index: v18);
    }
    else
    {
      v19 = v25.argv[1];
      if ( v25.argc <= 1 )
        v19 = &byte_8200D768;
      tr.testImage = idImageManager::ImageFromFile(this: globalImages, _name: v19, opts_p: nullptr, makeDefault: false);
      if ( tr.testImage == nullptr )
      {
        v20 = v25.argv[1];
        if ( v25.argc <= 1 )
          v20 = &byte_8200D768;
        idLib::Printf(fmt: "Couldn't load '%s'\n", v20);
      }
    }
    if ( v25.argc == 3 )
    {
      v21 = atof(nptr: v25.argv[2]);
      v3 = (float)*(double *)&v21;
    }
    v22 = (idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                this: &idDeclRenderParm::resourceList,
                                name: "testImageLOD",
                                makeDefault: true);
    if ( v22 != nullptr )
      idDeclRenderParm::Set(this: v22, v: v3);
    v23 = (idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                this: &idDeclRenderParm::resourceList,
                                name: "testImageFlip",
                                makeDefault: true);
    if ( v23 != nullptr )
    {
      v24.a = 1.0;
      v24.b = 1.0;
      v24.c = 1.0;
      v24.d = 1.0;
      if ( v4 != 0 )
        v24.a = -1.0;
      if ( v1 != 0 )
        v24.b = -1.0;
      idDeclRenderParm::Set(this: v23, plane: &v24);
    }
  }
}


// ========================================================================
// ?TestCubeImage_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294C728
// RVA : 0x0094C728
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall TestCubeImage_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v3; // r3
  bool IsNumeric; // r3
  int v5; // r11
  const char *v6; // r3
  int v7; // r4
  char *v8; // r4
  const char *v9; // r4
  double v10; // fp31
  long double v11; // fp2
  idDeclRenderParm *v12; // r3

  tr.testCubeImage = nullptr;
  argc = args->argc;
  if ( args->argc == 2 || argc == 3 )
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    IsNumeric = idStr::IsNumeric(s: v3);
    v5 = args->argc;
    if ( IsNumeric )
    {
      if ( v5 <= 1 )
        v6 = &byte_8200D768;
      else
        v6 = args->argv[1];
      v7 = atol(nptr: v6);
      if ( v7 >= 0 && v7 < idImage::resourceList.num )
        tr.testCubeImage = (idImage *)idResourceList::Index(this: &idImage::resourceList, index: v7);
    }
    else
    {
      if ( v5 <= 1 )
        v8 = &byte_8200D768;
      else
        v8 = args->argv[1];
      tr.testCubeImage = idImageManager::ImageFromFile(
                           this: globalImages,
                           _name: v8,
                           opts_p: nullptr,
                           makeDefault: false);
      if ( tr.testCubeImage == nullptr )
      {
        if ( args->argc <= 1 )
          v9 = &byte_8200D768;
        else
          v9 = args->argv[1];
        idLib::Printf(fmt: "Couldn't load '%s'\n", v9);
      }
    }
    v10 = 0.0;
    if ( args->argc == 3 )
    {
      v11 = atof(nptr: args->argv[2]);
      v10 = (float)*(double *)&v11;
    }
    v12 = (idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                this: &idDeclRenderParm::resourceList,
                                name: "testEnvLOD",
                                makeDefault: true);
    if ( v12 != nullptr )
      idDeclRenderParm::Set(this: v12, v: v10);
  }
}


// ========================================================================
// ?TestMaterial_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294C880
// RVA : 0x0094C880
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall TestMaterial_f(const idCmdArgs *args)
{
  const char *v2; // r4
  const idMaterial *v3; // r3
  const char *v4; // r4

  tr.testImage = nullptr;
  tr.testMaterial = nullptr;
  if ( args->argc == 2 )
  {
    v2 = args->argv[1];
    v3 = v2 != nullptr
       ? (const idMaterial *)idDeclInfo::FindWithInheritance(
                               this: &idMaterial::resourceList,
                               name: v2,
                               makeDefault: false)
       : nullptr;
    tr.testMaterial = v3;
    if ( v3 == nullptr )
    {
      if ( args->argc <= 1 )
        v4 = &byte_8200D768;
      else
        v4 = args->argv[1];
      idLib::Printf(fmt: "Couldn't load '%s'\n", v4);
    }
  }
}


// ========================================================================
// ?TakeScreenshotToBuffer@idRenderSystemLocal@@QAAXHHPAVidRenderWorld@@PAPAVidRenderModel@@HHPAEH_N3@Z
// EA  : 0x8294C938
// RVA : 0x0094C938
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::TakeScreenshotToBuffer(
        idRenderSystemLocal *this,
        int width,
        int height,
        idRenderWorld *world,
        idRenderModel **guiList,
        int numGuis,
        int blends,
        unsigned __int8 *outBuffer,
        int primes,
        bool fillAlphaWith255,
        bool skipPostProcessing,
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
        unsigned __int8 a30,
        int a31,
        char a32)
{
  int v38; // r14
  int v40; // r11
  signed int v41; // r29
  size_t v42; // r30
  int v43; // r16
  int v44; // r30
  int v45; // r26
  idRenderSystemLocal_vtbl *v46; // r28
  void *v47; // r3
  __int64 v48; // r9
  double v49; // r4
  idRenderSystemLocal_vtbl *v50; // r30
  void *v51; // r3
  char *v52; // r30
  unsigned __int8 *v53; // r8
  unsigned __int8 *v54; // r9
  int i; // r6
  unsigned __int8 *v56; // r10
  signed int v57; // ctr
  unsigned __int8 *v58; // r11
  unsigned __int8 v59; // r3
  unsigned __int8 *v60; // r10
  int j; // r9
  unsigned __int8 *v62; // r11
  signed int k; // ctr
  int v64; // r11
  char *v65; // r10
  __int16 v66; // r8
  __int16 v67; // r8
  __int64 v68; // r7
  double v69; // r4
  void *v70; // r4
  int v71; // r11
  char *v72; // r10
  int v73; // r9
  const void *v74; // [sp+8h] [-188h]
  const tagRECT *v75; // [sp+Ch] [-184h]
  int v76; // [sp+70h] [-120h]
  idODSObject<idRenderDestination> v77[2]; // [sp+78h] [-118h] BYREF
  int v78; // [sp+80h] [-110h]
  __int64 v79; // [sp+88h] [-108h]
  idCVar *v80; // [sp+90h] [-100h]
  idCVar *v81; // [sp+94h] [-FCh]
  int v82; // [sp+98h] [-F8h]
  int valueInteger; // [sp+9Ch] [-F4h]
  char *v84; // [sp+A0h] [-F0h]
  int v85; // [sp+A4h] [-ECh]
  _XGTEXTURE_DESC v86; // [sp+B0h] [-E0h] BYREF
  signed int v87; // [sp+1D4h] [+44h]

  v87 = blends;
  v38 = blends;
  valueInteger = rs_enable.valueInteger;
  idCVar::SetInteger(this: &rs_enable, newValue: 0, force: true);
  v40 = width * height;
  v41 = width & 0xFFFFFFFC;
  if ( v38 <= 1 )
  {
    v87 = 1;
    v38 = 1;
  }
  v42 = 8 * v40;
  v43 = 4 * v40;
  v85 = 4 * v40;
  v84 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                  size: 8 * v40,
                  tag: TAG_TEMP,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  memset(Dst: v84, Val: 0, Size: v42);
  v80 = &r_jitter;
  if ( v38 > 1 )
    idCVar::SetBool(this: &r_jitter, newValue: true, force: true);
  v81 = &r_skipPostProcess;
  v82 = r_skipPostProcess.valueInteger;
  idCVar::SetInteger(this: &r_skipPostProcess, newValue: a32 != 0, force: true);
  if ( world != nullptr )
    world->RenderViewForIndex(this: world, a2: 0);
  v44 = a28;
  v45 = Sys_Milliseconds();
  if ( a28 > 0 )
  {
    do
    {
      v46 = this->__vftable;
      v47 = renderSystem->GetGameWindow(this: renderSystem);
      ((void (__fastcall *)(idRenderSystemLocal *, void *, signed int, int, idRenderWorld *, idRenderModel **, int, _DWORD))v46->EndFrame)(
        a1: this,
        a2: v47,
        a3: v41,
        a4: height,
        a5: world,
        a6: guiList,
        a7: numGuis,
        a8: 0);
      --v44;
    }
    while ( v44 != 0 );
  }
  LODWORD(v48) = Sys_Milliseconds() - v45;
  HIDWORD(v48) = "Mips";
  LODWORD(v79) = v48;
  v49 = (float)((float)v48 * (float)0.001);
  idLib::Printf(fmt: (const char *)HIDWORD(v49), LODWORD(v49));
  HIDWORD(v79) = Sys_Milliseconds();
  v76 = v38;
  v78 = a30;
  do
  {
    v50 = this->__vftable;
    v51 = renderSystem->GetGameWindow(this: renderSystem);
    ((void (__fastcall *)(idRenderSystemLocal *, void *, signed int, int, idRenderWorld *, idRenderModel **, int, _DWORD))v50->EndFrame)(
      a1: this,
      a2: v51,
      a3: v41,
      a4: height,
      a5: world,
      a6: guiList,
      a7: numGuis,
      a8: 0);
    v77[0].objectPtr = renderDestNative;
    GL_ResolveTarget(target: RESOLVE_TARGET_COLOR0, destination: v77);
    D3DDevice_BlockUntilIdle(pDevice: d3d);
    XGGetTextureDesc(pTexture: renderDestNative->targetImage[0]->d3dTexture, Level: 0, pDesc: &v86);
    v77[1] = (idODSObject<idRenderDestination>)renderDestNative->targetImage[0]->lockRect[0].pBits;
    v52 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                    size: 4 * v86.Height * v86.Width,
                    tag: TAG_TEMP,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    XGUntileTextureLevel(
      Width: v86.Width,
      Height: v86.Height,
      Level: 0,
      GpuFormat: v86.Format & 0x3F,
      Flags: 0,
      pDestination: v52,
      RowPitch: 4 * v86.Width,
      pPoint: nullptr,
      pSource: v74,
      pRect: v75);
    if ( height > 0 )
    {
      v53 = outBuffer;
      v54 = (unsigned __int8 *)&v52[(4 * height - 4) * v41];
      for ( i = height; i != 0; --i )
      {
        if ( v41 > 0 )
        {
          v56 = v53 - 1;
          v57 = v41;
          v58 = v54 + 1;
          do
          {
            v56[1] = v58[1];
            v58[v53 - v54] = *v58;
            v56[3] = *(v58 - 1);
            v59 = v58[2];
            v58 += 4;
            v56 += 4;
            *v56 = v59;
            --v57;
          }
          while ( v57 != 0 );
        }
        v54 -= 4 * v41;
        v53 += 4 * v41;
      }
    }
    if ( v78 != 0 && height > 0 )
    {
      v60 = outBuffer + 3;
      for ( j = height; j != 0; --j )
      {
        if ( v41 > 0 )
        {
          v62 = v60 - 4;
          for ( k = v41; k != 0; --k )
          {
            v62 += 4;
            *v62 = -1;
          }
        }
        v60 += 4 * v41;
      }
    }
    v64 = 0;
    if ( v43 > 0 )
    {
      v65 = v84 - 2;
      do
      {
        v66 = outBuffer[v64++];
        v67 = v66 + *((_WORD *)v65 + 1);
        v65 += 2;
        *(_WORD *)v65 = v67;
      }
      while ( v64 < v43 );
    }
    if ( v52 != nullptr )
      idMem::Free(this: &mem, ptr: v52, align: ALIGN_16);
    --v76;
  }
  while ( v76 != 0 );
  LODWORD(v68) = Sys_Milliseconds() - HIDWORD(v79);
  v79 = v68;
  v69 = (float)((float)v68 * (float)0.001);
  idLib::Printf(fmt: (const char *)HIDWORD(v69), LODWORD(v69));
  idCVar::SetBool(this: v80, newValue: false, force: true);
  idCVar::SetInteger(this: v81, newValue: v82, force: true);
  idCVar::SetInteger(this: &rs_enable, newValue: valueInteger, force: true);
  v70 = v84;
  v71 = 0;
  if ( v43 > 0 )
  {
    v72 = v84 - 2;
    do
    {
      v72 += 2;
      v73 = *(unsigned __int16 *)v72;
      __twllei(v87, 0);
      outBuffer[v71++] = v73 / v87;
      __twlgei(v87 & ~(__ROL4__(v73, 1) - 1), 0xFFFFFFFF);
    }
    while ( v71 < v43 );
  }
  if ( v70 != nullptr )
    idMem::Free(this: &mem, ptr: v70, align: ALIGN_16);
}


// ========================================================================
// __unwind$235198
// EA  : 0x8294CE34
// RVA : 0x0094CE34
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_235198()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 400 + 160));
}


// ========================================================================
// ?R_RenameRenderProg_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294CE60
// RVA : 0x0094CE60
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall R_RenameRenderProg_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v3; // r4
  const idDecl *v4; // r3
  const idDecl *v5; // r31
  const char *v6; // r4
  const idDecl *v7; // r3
  const char *v8; // r5

  argc = args->argc;
  if ( args->argc < 2 || argc > 3 )
  {
    idLib::Printf(fmt: "USAGE: renameRenderProg <renderProg> [newProg]\n");
    return;
  }
  if ( argc <= 1 )
  {
    v3 = &byte_8200D768;
  }
  else
  {
    v3 = args->argv[1];
    if ( v3 == nullptr )
      goto LABEL_6;
  }
  v4 = idDeclInfo::FindWithInheritance(this: &idDeclRenderProg::resourceList, name: v3, makeDefault: false);
  v5 = v4;
  if ( v4 == nullptr )
  {
LABEL_6:
    if ( args->argc > 1 )
    {
      idLib::Printf(fmt: "Renderprog '%s' not found\n", args->argv[1]);
      return;
    }
    goto LABEL_9;
  }
  if ( args->argc == 2 )
  {
    if ( (const idDecl *)v4[1].__vftable == v4 )
    {
      idLib::Printf(fmt: "Renderprog '%s' was not renamed.\n", args->argv[1]);
    }
    else
    {
      v4[1].__vftable = (idDecl_vtbl *)v4;
      if ( args->argc <= 1 )
        idLib::Printf(fmt: "Renderprog '%s' was returned to normal.\n", &byte_8200D768);
      else
        idLib::Printf(fmt: "Renderprog '%s' was returned to normal.\n", args->argv[1]);
    }
    return;
  }
  if ( args->argc <= 2 )
  {
    v6 = &byte_8200D768;
  }
  else
  {
    v6 = args->argv[2];
    if ( v6 == nullptr )
      goto LABEL_19;
  }
  v7 = idDeclInfo::FindWithInheritance(this: &idDeclRenderProg::resourceList, name: v6, makeDefault: false);
  if ( v7 != nullptr )
  {
    v5[1].__vftable = (idDecl_vtbl *)v7;
    if ( args->argc <= 2 )
      v8 = &byte_8200D768;
    else
      v8 = args->argv[2];
    if ( args->argc <= 1 )
      idLib::Printf(fmt: "Renderprog '%s' was renamed to '%s'.\n", &byte_8200D768, v8);
    else
      idLib::Printf(fmt: "Renderprog '%s' was renamed to '%s'.\n", args->argv[1], v8);
    return;
  }
LABEL_19:
  if ( args->argc <= 2 )
  {
LABEL_9:
    idLib::Printf(fmt: "Renderprog '%s' not found\n", &byte_8200D768);
    return;
  }
  idLib::Printf(fmt: "Renderprog '%s' not found\n", args->argv[2]);
}


// ========================================================================
// ?R_RP_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294D038
// RVA : 0x0094D038
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall R_RP_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v3; // r4
  const idDecl *v4; // r3
  idDeclRenderParm *v5; // r29
  int v6; // r11
  const char *v7; // r30
  int v8; // r5
  float v9; // r8
  float v10; // r6
  float v11; // r5
  const char *v12; // r3
  long double v13; // fp2
  int v14; // r11
  const char *v15; // r3
  long double v16; // fp2
  int v17; // r11
  long double v18; // fp2
  long double v19; // fp2
  idPlane v20; // [sp+60h] [-2D0h] BYREF
  idParser v21; // [sp+70h] [-2C0h] BYREF

  argc = args->argc;
  if ( args->argc < 2 || argc > 6 )
  {
    idLib::Printf(fmt: "USAGE: rp <renderParmName> [value]\n");
    return;
  }
  if ( argc <= 1 )
  {
    v3 = &byte_8200D768;
  }
  else
  {
    v3 = args->argv[1];
    if ( v3 == nullptr )
      goto LABEL_6;
  }
  v4 = idDeclInfo::FindWithInheritance(this: &idDeclRenderParm::resourceList, name: v3, makeDefault: false);
  v5 = (idDeclRenderParm *)v4;
  if ( v4 == nullptr )
  {
LABEL_6:
    if ( args->argc <= 1 )
      idLib::Printf(fmt: "RenderParm '%s' not found\n", &byte_8200D768);
    else
      idLib::Printf(fmt: "RenderParm '%s' not found\n", args->argv[1]);
    return;
  }
  v6 = args->argc;
  if ( args->argc == 2 )
  {
    v4->Print(this: (struct idDecl *)v4);
  }
  else if ( v4[1].trackedMemory != 0 )
  {
    v7 = idCmdArgs::Args(this: args, start: 2, end: -1, quoteArgs: false, escapeArgs: false);
    idParser::idParser(this: &v21, flags: 156216);
    v8 = 0;
    if ( *v7 != 0 )
    {
      do
        ++v8;
      while ( v7[v8] != 0 );
    }
    idParser::LoadMemory(this: &v21, ptr: v7, length: v8, name: "command line");
    idDeclRenderParm::ParseValue(this: v5, src: &v21, value: &renderThreadParmState->values[v5->parmIndex]);
    idParser::~idParser(this: &v21);
  }
  else
  {
    v9 = *(float *)&v4[1].resourceError;
    v10 = *(float *)&v4[1].networkID;
    v11 = *(float *)&v4[1].staleCount;
    LODWORD(v20.a) = v4[1].resourceListPtr;
    v20.b = v9;
    v20.c = v10;
    v20.d = v11;
    if ( v6 <= 2 )
      v12 = &byte_8200D768;
    else
      v12 = args->argv[2];
    v13 = atof(nptr: v12);
    v14 = args->argc;
    v20.a = *(double *)&v13;
    if ( v14 == 3 )
    {
      v20.c = *(double *)&v13;
      v20.b = *(double *)&v13;
      v20.d = *(double *)&v13;
      idDeclRenderParm::Set(this: v5, plane: &v20);
    }
    else
    {
      if ( v14 <= 3 )
        v15 = &byte_8200D768;
      else
        v15 = args->argv[3];
      v16 = atof(nptr: v15);
      v17 = args->argc;
      v20.b = *(double *)&v16;
      if ( v17 > 4 )
      {
        v18 = atof(nptr: args->argv[4]);
        v20.c = *(double *)&v18;
      }
      if ( args->argc > 5 )
      {
        v19 = atof(nptr: args->argv[5]);
        v20.d = *(double *)&v19;
      }
      idDeclRenderParm::Set(this: v5, plane: &v20);
    }
  }
}


// ========================================================================
// __unwind$235457_0
// EA  : 0x8294D288
// RVA : 0x0094D288
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_235457_0()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 816 + 112));
}


// ========================================================================
// ?ReportWorldSurfaces_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294D2B0
// RVA : 0x0094D2B0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall ReportWorldSurfaces_f(const idCmdArgs *args)
{
  int v1; // r4
  int v2; // r27
  int v3; // r28
  int v4; // r31
  int v5; // r30
  int v6; // r29
  idRenderModel **list; // r5
  int num; // r3
  idRenderModel *v9; // r10
  int v10; // r11
  int v11; // r7
  int v12; // ctr
  _DWORD *v13; // r8
  _DWORD *v14; // r11
  _DWORD *v15; // r11
  _DWORD *v16; // r11
  _DWORD *v17; // r11
  _DWORD *v18; // r11
  _DWORD *v19; // r11
  _DWORD *v20; // r11
  _DWORD *v21; // r11

  if ( tr.primaryWorld != nullptr )
  {
    v1 = 0;
    v2 = 0;
    v3 = 0;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    if ( tr.primaryWorld->renderModels.num > 0 )
    {
      list = tr.primaryWorld->renderModels.list;
      num = tr.primaryWorld->renderModels.num;
      do
      {
        v9 = *list;
        if ( *list != nullptr )
        {
          v10 = v9->surfaces.num;
          ++v1;
          if ( v10 > 0 )
          {
            v11 = 0;
            v12 = v9->surfaces.num;
            v2 += v10;
            do
            {
              v13 = &v9->surfaces.list[v11].material->__vftable;
              if ( v13 != nullptr )
              {
                v14 = (_DWORD *)v13[44];
                if ( v14 != nullptr )
                {
                  ++v3;
                  v4 += v14[51];
                  v5 += v14[68];
                  v6 += v14[77];
                }
                v15 = (_DWORD *)v13[45];
                if ( v15 != nullptr )
                {
                  ++v3;
                  v4 += v15[51];
                  v5 += v15[68];
                  v6 += v15[77];
                }
                v16 = (_DWORD *)v13[46];
                if ( v16 != nullptr )
                {
                  ++v3;
                  v4 += v16[51];
                  v5 += v16[68];
                  v6 += v16[77];
                }
                v17 = (_DWORD *)v13[47];
                if ( v17 != nullptr )
                {
                  ++v3;
                  v4 += v17[51];
                  v5 += v17[68];
                  v6 += v17[77];
                }
                v18 = (_DWORD *)v13[48];
                if ( v18 != nullptr )
                {
                  ++v3;
                  v4 += v18[51];
                  v5 += v18[68];
                  v6 += v18[77];
                }
                v19 = (_DWORD *)v13[49];
                if ( v19 != nullptr )
                {
                  ++v3;
                  v4 += v19[51];
                  v5 += v19[68];
                  v6 += v19[77];
                }
                v20 = (_DWORD *)v13[50];
                if ( v20 != nullptr )
                {
                  ++v3;
                  v4 += v20[51];
                  v5 += v20[68];
                  v6 += v20[77];
                }
                v21 = (_DWORD *)v13[51];
                if ( v21 != nullptr )
                {
                  ++v3;
                  v4 += v21[51];
                  v5 += v21[68];
                  v6 += v21[77];
                }
              }
              ++v11;
              --v12;
            }
            while ( v12 != 0 );
          }
        }
        --num;
        ++list;
      }
      while ( num != 0 );
    }
    idLib::Printf(fmt: "%8i models\n", v1);
    idLib::Printf(fmt: "%8i surfs\n", v2);
    idLib::Printf(fmt: "%8i progs\n", v3);
    idLib::Printf(fmt: "%8i vertex parms\n", v4);
    idLib::Printf(fmt: "%8i fragment parms\n", v5);
    idLib::Printf(fmt: "%8i texture parms\n", v6);
    idLib::Printf(fmt: "EstimatedSurfaceMemory: %i\n", 4 * (4 * (v5 + v4) + v6));
  }
  else
  {
    idLib::Printf(fmt: "No primaryWorld.\n");
  }
}


// ========================================================================
// ?FindTriangleData_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294D520
// RVA : 0x0094D520
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall FindTriangleData_f(const idCmdArgs *args)
{
  int v1; // r24
  idRenderWorldLocal *i; // r28
  int v3; // r25
  int v4; // r26
  idRenderModel *v5; // r31
  int v6; // r30
  int v7; // r29
  idRenderModelSurface *v8; // r11
  idTriangles *geometry; // r10
  const char *str; // r23
  const char *v11; // r22
  const char *v12; // r3

  v1 = 0;
  for ( i = tr.worlds; i != nullptr; i = i->nextOnWorldList )
  {
    v3 = 0;
    if ( i->renderModels.num > 0 )
    {
      v4 = 0;
      do
      {
        v5 = i->renderModels.list[v4];
        if ( v5 != nullptr )
        {
          v6 = 0;
          if ( v5->surfaces.num > 0 )
          {
            v7 = 0;
            do
            {
              v8 = &v5->surfaces.list[v7];
              if ( v8 != nullptr )
              {
                geometry = v8->geometry;
                if ( geometry != nullptr )
                {
                  ++v1;
                  if ( geometry->verts != nullptr || geometry->indexes != nullptr )
                  {
                    str = v5->name.str;
                    v11 = v8->material->name.str;
                    v12 = i->GetName(this: i);
                    idLib::Printf(fmt: "%s : %s : (%i)%s : holds CPU data\n", v12, str, v6, v11);
                  }
                }
              }
              ++v6;
              ++v7;
            }
            while ( v6 < v5->surfaces.num );
          }
        }
        ++v3;
        ++v4;
      }
      while ( v3 < i->renderModels.num );
    }
  }
  idLib::Printf(fmt: "%i total idTriangles in all renderWorlds\n", v1);
}


// ========================================================================
// ?testEnv_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294D640
// RVA : 0x0094D640
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall testEnv_f(const idCmdArgs *args)
{
  idRenderWorldLocal *primaryWorld; // r10
  const char *v3; // r4
  const idDecl *v4; // r3
  const idDeclEnv *testEnv; // r11
  char *v6; // r4
  char *v7; // r4

  primaryWorld = tr.primaryWorld;
  if ( tr.primaryWorld != nullptr )
  {
    if ( args->argc == 2 )
    {
      v3 = args->argv[1];
      if ( v3 != nullptr )
      {
        v4 = idDeclInfo::FindWithInheritance(this: &idDeclEnv::resourceList, name: v3, makeDefault: false);
        primaryWorld = tr.primaryWorld;
      }
      else
      {
        v4 = nullptr;
      }
      primaryWorld->testEnv = (const idDeclEnv *)v4;
      testEnv = tr.primaryWorld->testEnv;
      if ( testEnv != nullptr )
      {
        idParmBlock::Print(this: &testEnv->parmBlock);
        if ( args->argc <= 1 )
          v7 = &byte_8200D768;
        else
          v7 = args->argv[1];
        idLib::Printf(fmt: "Forcing env '%s'\n", v7);
      }
      else
      {
        if ( args->argc <= 1 )
          v6 = &byte_8200D768;
        else
          v6 = args->argv[1];
        idLib::Printf(fmt: "'%s' not found.\n", v6);
      }
    }
    else
    {
      idLib::Printf(fmt: "Canceling testEnv.\n");
      tr.primaryWorld->testEnv = nullptr;
    }
  }
  else
  {
    idLib::Printf(fmt: "No primaryWorld.\n");
  }
}


// ========================================================================
// ?DrawPlayerCollision_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294D778
// RVA : 0x0094D778
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall DrawPlayerCollision_f(const idCmdArgs *args, int a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  va *v7; // r3
  int v8; // [sp+8h] [-1078h]
  int v9; // [sp+Ch] [-1074h]
  int v10; // [sp+10h] [-1070h]
  int v11; // [sp+14h] [-106Ch]
  int v12; // [sp+18h] [-1068h]
  int v13; // [sp+1Ch] [-1064h]
  idStr v14; // [sp+50h] [-1030h] BYREF
  va v15; // [sp+70h] [-1010h] BYREF

  HIDWORD(a7) = -1;
  v7 = va::va(
         this: &v15,
         fmt: "DrawCollision %d %d %d %d %d",
         a3: 0,
         a4: 0x900000000LL,
         a5: a7,
         a6: v8,
         a7: v9,
         a8: v10,
         a9: v11,
         a10: v12,
         a11: v13);
  idStr::idStr(this: &v14, text: v7);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v14.data);
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$235816
// EA  : 0x8294D7F8
// RVA : 0x0094D7F8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_235816()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4224 + 80));
}


// ========================================================================
// ?DrawPlayerClip_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294D828
// RVA : 0x0094D828
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall DrawPlayerClip_f(const idCmdArgs *args, int a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  va *v7; // r3
  int v8; // [sp+8h] [-1078h]
  int v9; // [sp+Ch] [-1074h]
  int v10; // [sp+10h] [-1070h]
  int v11; // [sp+14h] [-106Ch]
  int v12; // [sp+18h] [-1068h]
  int v13; // [sp+1Ch] [-1064h]
  idStr v14; // [sp+50h] [-1030h] BYREF
  va v15; // [sp+70h] [-1010h] BYREF

  HIDWORD(a7) = -1;
  v7 = va::va(
         this: &v15,
         fmt: "DrawCollision %d %d %d %d %d",
         a3: 0,
         a4: 0x800000000LL,
         a5: a7,
         a6: v8,
         a7: v9,
         a8: v10,
         a9: v11,
         a10: v12,
         a11: v13);
  idStr::idStr(this: &v14, text: v7);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v14.data);
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$235846
// EA  : 0x8294D8A8
// RVA : 0x0094D8A8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_235846()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4224 + 80));
}


// ========================================================================
// ?DrawMonsterCollision_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294D8D8
// RVA : 0x0094D8D8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall DrawMonsterCollision_f(const idCmdArgs *args, int a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  va *v7; // r3
  int v8; // [sp+8h] [-1078h]
  int v9; // [sp+Ch] [-1074h]
  int v10; // [sp+10h] [-1070h]
  int v11; // [sp+14h] [-106Ch]
  int v12; // [sp+18h] [-1068h]
  int v13; // [sp+1Ch] [-1064h]
  idStr v14; // [sp+50h] [-1030h] BYREF
  va v15; // [sp+70h] [-1010h] BYREF

  HIDWORD(a7) = -1;
  v7 = va::va(
         this: &v15,
         fmt: "DrawCollision %d %d %d %d %d",
         a3: 0,
         a4: 0x1100000000LL,
         a5: a7,
         a6: v8,
         a7: v9,
         a8: v10,
         a9: v11,
         a10: v12,
         a11: v13);
  idStr::idStr(this: &v14, text: v7);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v14.data);
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$235876_0
// EA  : 0x8294D958
// RVA : 0x0094D958
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_235876_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4224 + 80));
}


// ========================================================================
// ?DrawMonsterClip_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294D988
// RVA : 0x0094D988
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall DrawMonsterClip_f(const idCmdArgs *args, int a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  va *v7; // r3
  int v8; // [sp+8h] [-1078h]
  int v9; // [sp+Ch] [-1074h]
  int v10; // [sp+10h] [-1070h]
  int v11; // [sp+14h] [-106Ch]
  int v12; // [sp+18h] [-1068h]
  int v13; // [sp+1Ch] [-1064h]
  idStr v14; // [sp+50h] [-1030h] BYREF
  va v15; // [sp+70h] [-1010h] BYREF

  HIDWORD(a7) = -1;
  v7 = va::va(
         this: &v15,
         fmt: "DrawCollision %d %d %d %d %d",
         a3: 0,
         a4: 0x1000000000LL,
         a5: a7,
         a6: v8,
         a7: v9,
         a8: v10,
         a9: v11,
         a10: v12,
         a11: v13);
  idStr::idStr(this: &v14, text: v7);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v14.data);
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$235906
// EA  : 0x8294DA08
// RVA : 0x0094DA08
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_235906()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4224 + 80));
}


// ========================================================================
// ?DrawShotIKClip_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294DA38
// RVA : 0x0094DA38
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall DrawShotIKClip_f(const idCmdArgs *args, int a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  va *v7; // r3
  int v8; // [sp+8h] [-1078h]
  int v9; // [sp+Ch] [-1074h]
  int v10; // [sp+10h] [-1070h]
  int v11; // [sp+14h] [-106Ch]
  int v12; // [sp+18h] [-1068h]
  int v13; // [sp+1Ch] [-1064h]
  idStr v14; // [sp+50h] [-1030h] BYREF
  va v15; // [sp+70h] [-1010h] BYREF

  HIDWORD(a7) = -1;
  v7 = va::va(
         this: &v15,
         fmt: "DrawCollision %d %d %d %d %d",
         a3: 0,
         a4: 0x18000000000LL,
         a5: a7,
         a6: v8,
         a7: v9,
         a8: v10,
         a9: v11,
         a10: v12,
         a11: v13);
  idStr::idStr(this: &v14, text: v7);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v14.data);
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$235936_1
// EA  : 0x8294DAB8
// RVA : 0x0094DAB8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_235936_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4224 + 80));
}


// ========================================================================
// ?DrawShotIKCollision_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294DAE8
// RVA : 0x0094DAE8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall DrawShotIKCollision_f(const idCmdArgs *args, int a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  va *v7; // r3
  int v8; // [sp+8h] [-1078h]
  int v9; // [sp+Ch] [-1074h]
  int v10; // [sp+10h] [-1070h]
  int v11; // [sp+14h] [-106Ch]
  int v12; // [sp+18h] [-1068h]
  int v13; // [sp+1Ch] [-1064h]
  idStr v14; // [sp+50h] [-1030h] BYREF
  va v15; // [sp+70h] [-1010h] BYREF

  HIDWORD(a7) = -1;
  v7 = va::va(
         this: &v15,
         fmt: "DrawCollision %d %d %d %d %d",
         a3: 0,
         a4: 0x18100000000LL,
         a5: a7,
         a6: v8,
         a7: v9,
         a8: v10,
         a9: v11,
         a10: v12,
         a11: v13);
  idStr::idStr(this: &v14, text: v7);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v14.data);
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$235966
// EA  : 0x8294DB68
// RVA : 0x0094DB68
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_235966()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4224 + 80));
}


// ========================================================================
// ?DrawVehicleCollision_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294DB98
// RVA : 0x0094DB98
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall DrawVehicleCollision_f(const idCmdArgs *args, int a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  va *v7; // r3
  int v8; // [sp+8h] [-1078h]
  int v9; // [sp+Ch] [-1074h]
  int v10; // [sp+10h] [-1070h]
  int v11; // [sp+14h] [-106Ch]
  int v12; // [sp+18h] [-1068h]
  int v13; // [sp+1Ch] [-1064h]
  idStr v14; // [sp+50h] [-1030h] BYREF
  va v15; // [sp+70h] [-1010h] BYREF

  HIDWORD(a7) = -1;
  v7 = va::va(
         this: &v15,
         fmt: "DrawCollision %d %d %d %d %d",
         a3: 0,
         a4: 0x2100000000LL,
         a5: a7,
         a6: v8,
         a7: v9,
         a8: v10,
         a9: v11,
         a10: v12,
         a11: v13);
  idStr::idStr(this: &v14, text: v7);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v14.data);
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$235996
// EA  : 0x8294DC18
// RVA : 0x0094DC18
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_235996()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4224 + 80));
}


// ========================================================================
// ?DrawVehicleClip_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294DC48
// RVA : 0x0094DC48
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall DrawVehicleClip_f(const idCmdArgs *args, int a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  va *v7; // r3
  int v8; // [sp+8h] [-1078h]
  int v9; // [sp+Ch] [-1074h]
  int v10; // [sp+10h] [-1070h]
  int v11; // [sp+14h] [-106Ch]
  int v12; // [sp+18h] [-1068h]
  int v13; // [sp+1Ch] [-1064h]
  idStr v14; // [sp+50h] [-1030h] BYREF
  va v15; // [sp+70h] [-1010h] BYREF

  HIDWORD(a7) = -1;
  v7 = va::va(
         this: &v15,
         fmt: "DrawCollision %d %d %d %d %d",
         a3: 0,
         a4: 0x2000000000LL,
         a5: a7,
         a6: v8,
         a7: v9,
         a8: v10,
         a9: v11,
         a10: v12,
         a11: v13);
  idStr::idStr(this: &v14, text: v7);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v14.data);
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$236026_0
// EA  : 0x8294DCC8
// RVA : 0x0094DCC8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236026_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4224 + 80));
}


// ========================================================================
// R_ReloadSurface_f
// EA  : 0x8294DD48
// RVA : 0x0094DD48
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall R_ReloadSurface_f(const idCmdArgs *args)
{
  const char *v1; // r3
  const idDecl *v2; // r3
  idMaterial *v3; // r30
  idRenderView *v4; // r3
  double x; // fp9
  double v6; // fp6
  double v7; // fp10
  double y; // fp5
  double v9; // fp4
  double v10; // fp1
  double v11; // fp8
  char *data; // r4
  const idDecl *v13; // r3
  const idDecl *v14; // r30
  float v15; // [sp+50h] [-9D0h] BYREF
  __int16 v16; // [sp+54h] [-9CCh]
  __int16 v17; // [sp+56h] [-9CAh]
  int v18; // [sp+58h] [-9C8h]
  idStr v19; // [sp+60h] [-9C0h] BYREF
  float v20[4]; // [sp+80h] [-9A0h] BYREF
  float v21; // [sp+90h] [-990h] BYREF
  float v22; // [sp+94h] [-98Ch]
  float v23; // [sp+98h] [-988h]
  idVec3 *p_vieworg; // [sp+9Ch] [-984h]
  _DWORD v25[16]; // [sp+A0h] [-980h] BYREF
  idCmdArgs v26; // [sp+E0h] [-940h] BYREF

  if ( tr.primaryWorld != nullptr )
  {
    v1 = idCmdArgs::Args(this: args, start: 0, end: -1, quoteArgs: false, escapeArgs: false);
    idLib::Printf(
      fmt: "----------------------------------------------------\n"
      "Running Command: %s\n"
      "----------------------------------------------------\n",
      v1);
    v19.len = 0;
    v19.allocedAndFlag = 20;
    v19.data = v19.baseBuffer;
    v19.baseBuffer[0] = 0;
    if ( r_currentMaterial.valueString.data != nullptr )
      v2 = idDeclInfo::FindWithInheritance(
             this: &idMaterial::resourceList,
             name: r_currentMaterial.valueString.data,
             makeDefault: false);
    else
      v2 = nullptr;
    v3 = (idMaterial *)v2;
    if ( r_showSurfaceInfo.valueInteger == 0 || v2 == nullptr || idStr::Cmpn(s1: v2->name.str, s2: "generic", n: 7) == 0 )
    {
      v4 = tr.primaryWorld->RenderViewForIndex(this: tr.primaryWorld, a2: 0);
      x = v4->g.vieworg.x;
      v6 = (float)(v4->g.viewaxis.mat[0].y * (float)16.0);
      v7 = (float)(v4->g.viewaxis.mat[0].x * (float)16.0);
      y = v4->g.vieworg.y;
      v9 = (float)(v4->g.vieworg.z + (float)(v4->g.viewaxis.mat[0].z * (float)16.0));
      v23 = v4->g.vieworg.z + (float)(v4->g.viewaxis.mat[0].z * (float)16.0);
      p_vieworg = &v4->g.vieworg;
      v22 = (float)y + (float)v6;
      v21 = (float)x + (float)v7;
      v10 = (float)(v4->g.viewaxis.mat[0].y * (float)1024.0);
      v11 = (float)(v4->g.viewaxis.mat[0].z * (float)1024.0);
      v20[0] = (float)(v4->g.viewaxis.mat[0].x * (float)1024.0) + v21;
      v15 = 0.0;
      v20[2] = (float)v11 + (float)v9;
      v20[1] = (float)v10 + v22;
      v16 = 256;
      v18 = 0;
      v17 = 0;
      if ( !tr.primaryWorld->Trace(
              this: tr.primaryWorld,
              a2: (modelTrace_t *)v25,
              a3: (const idVec3 *)&v21,
              a4: (const idVec3 *)v20,
              a5: (const idTraceOpts *)&v15) )
        goto LABEL_9;
      v3 = *(idMaterial **)v25[11];
      if ( v25[12] != 0 )
      {
        idStr::operator=(this: &v19, text: *(const char **)(v25[12] + 16));
        idLib::Printf(fmt: "reloading materials for '%s'\n", v19.data);
      }
    }
    if ( v3 != nullptr )
    {
      if ( idStr::Cmpn(s1: v3->name.str, s2: "generic", n: 7) != 0 || v19.len == 0 )
      {
        idLib::Printf(fmt: "Reloading material %s\n", v3->name.str);
        declManager->Reload(this: declManager, a2: false);
        idMaterial::ReloadImages(this: v3, force: false);
        staticModelManager->ReloadModels(this: staticModelManager);
        goto LABEL_22;
      }
      data = v19.data;
      if ( v19.data != nullptr )
      {
        v13 = idDeclInfo::FindWithInheritance(this: &idDeclMD6::resourceList, name: v19.data, makeDefault: true);
        v14 = v13;
        if ( v13 != nullptr && v13[1].trackedMemory != 0 )
        {
          v26.argc = 0;
          idCmdArgs::AppendArg(this: &v26, text: "reloadVirtualMaterials");
          idCmdArgs::AppendArg(this: &v26, text: *(const char **)(v14[1].trackedMemory + 8));
          goto LABEL_22;
        }
        data = v19.data;
      }
      idLib::Printf(fmt: "Couldn't find md6 model: %s\n", data);
      goto LABEL_22;
    }
LABEL_9:
    idLib::Printf(fmt: "No surfaces in range!\n");
LABEL_22:
    idStr::FreeData(this: &v19);
  }
}


// ========================================================================
// __unwind$236126
// EA  : 0x8294E05C
// RVA : 0x0094E05C
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236126()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2592 + 96));
}


// ========================================================================
// ?TakeScreenshot@idRenderSystemLocal@@QAAXHHPAVidRenderWorld@@PAPAVidRenderModel@@HPBDHW4fsPath_t@@W4screenshotFormat_t@@H_N5@Z
// EA  : 0x8294E090
// RVA : 0x0094E090
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::TakeScreenshot(
        idRenderSystemLocal *this,
        int width,
        int height,
        idRenderWorld *world,
        idRenderModel **guiList,
        int numGuis,
        const char *fileName,
        int blends,
        fsPath_t fsPath,
        screenshotFormat_t format,
        int primes,
        bool fillAlphaWith255,
        bool skipPostProcessing,
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
        fsPath_t a28,
        int a29,
        unsigned int a30,
        int a31,
        int a32,
        int a33,
        unsigned __int8 a34,
        int a35,
        char fsPath_3)
{
  unsigned int v36; // r29
  unsigned __int8 *v44; // r28
  int v45; // [sp+8h] [-D8h]
  bool v46; // [sp+Fh] [-D1h]
  bool v47; // [sp+13h] [-CDh]
  int v48; // [sp+14h] [-CCh]
  int v49; // [sp+18h] [-C8h]
  int v50; // [sp+1Ch] [-C4h]
  int v51; // [sp+20h] [-C0h]
  int v52; // [sp+24h] [-BCh]
  int v53; // [sp+28h] [-B8h]
  int v54; // [sp+2Ch] [-B4h]
  int v55; // [sp+30h] [-B0h]
  int v56; // [sp+34h] [-ACh]
  int v57; // [sp+38h] [-A8h]
  int v58; // [sp+3Ch] [-A4h]
  int v59; // [sp+40h] [-A0h]
  int v60; // [sp+44h] [-9Ch]
  int v61; // [sp+48h] [-98h]
  int v62; // [sp+4Ch] [-94h]
  int v63; // [sp+50h] [-90h]
  int v64; // [sp+58h] [-88h]
  int v65; // [sp+60h] [-80h]

  v36 = width & 0xFFFFFFFC;
  v44 = (unsigned __int8 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                             size: 4 * (width & 0xFFFFFFFC) * height,
                             tag: TAG_TEMP,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  idRenderSystemLocal::TakeScreenshotToBuffer(
    this,
    width: v36,
    height,
    world,
    guiList,
    numGuis,
    blends,
    outBuffer: v44,
    primes: v45,
    fillAlphaWith255: v46,
    skipPostProcessing: v47,
    a12: v48,
    a13: v49,
    a14: v50,
    a15: v51,
    a16: v52,
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
    a28: a32,
    a29: v64,
    a30: a34,
    a31: v65,
    a32: fsPath_3);
  if ( a30 != 0 )
  {
    if ( a30 == 1 )
    {
      R_WriteJPG(filename: fileName, data: v44, width: v36, height, basePath: a28, useMarkers: true);
    }
    else if ( a30 < 3 )
    {
      R_WritePNG(filename: fileName, data: v44, width: v36, height, flipVertical: true, basePath: a28);
    }
  }
  else
  {
    R_WriteTGA(
      filename: fileName,
      data: (char *)v44,
      width: v36,
      height,
      depth: 4,
      flipVertical: true,
      swapRGB: true,
      basePath: a28);
  }
  if ( v44 != nullptr )
    idMem::Free(this: &mem, ptr: v44, align: ALIGN_16);
}


// ========================================================================
// __unwind$236396
// EA  : 0x8294E1D4
// RVA : 0x0094E1D4
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236396()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 224 + 112));
}


// ========================================================================
// ?R_ScreenShot_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294E208
// RVA : 0x0094E208
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall R_ScreenShot_f(const idCmdArgs *args)
{
  int valueInteger; // r18
  char v3; // r14
  char v4; // r15
  screenshotFormat_t v5; // r16
  int argc; // r11
  int v7; // r30
  int v8; // r27
  const char **v9; // r29
  const char **v10; // r26
  const char *v11; // r3
  const char *v12; // r3
  const char *v13; // r3
  const char *v14; // r3
  const char *v15; // r3
  const char *v16; // r3
  const char *v17; // r3
  const char *v18; // r4
  idStr *v19; // r29
  size_t len; // r30
  bool v21; // r28
  idRenderWorldLocal *primaryWorld; // r6
  fsPath_t v23; // [sp+8h] [-2B8h]
  screenshotFormat_t v24; // [sp+Ch] [-2B4h]
  int v25; // [sp+10h] [-2B0h]
  bool v26; // [sp+17h] [-2A9h]
  bool v27; // [sp+1Bh] [-2A5h]
  int v28; // [sp+1Ch] [-2A4h]
  int v29; // [sp+20h] [-2A0h]
  int v30; // [sp+24h] [-29Ch]
  int v31; // [sp+28h] [-298h]
  int v32; // [sp+2Ch] [-294h]
  int v33; // [sp+30h] [-290h]
  int v34; // [sp+34h] [-28Ch]
  int v35; // [sp+38h] [-288h]
  int v36; // [sp+3Ch] [-284h]
  int v37; // [sp+40h] [-280h]
  int v38; // [sp+44h] [-27Ch]
  int v39; // [sp+48h] [-278h]
  int v40; // [sp+4Ch] [-274h]
  int v41; // [sp+50h] [-270h]
  int v42; // [sp+58h] [-268h]
  int v43; // [sp+60h] [-260h]
  int v44; // [sp+68h] [-258h]
  int v45; // [sp+70h] [-250h]
  idStr v46; // [sp+90h] [-230h] BYREF
  idStr v47; // [sp+B0h] [-210h] BYREF
  int v48; // [sp+D0h] [-1F0h]
  idStr v49; // [sp+E0h] [-1E0h] BYREF
  idStr v50; // [sp+100h] [-1C0h] BYREF
  char v51[416]; // [sp+120h] [-1A0h] BYREF

  v46.len = 0;
  valueInteger = com_captureSamples.valueInteger;
  v3 = 0;
  v4 = 0;
  v46.allocedAndFlag = 20;
  v46.data = v46.baseBuffer;
  v46.baseBuffer[0] = 0;
  v48 = com_capturePrimes.valueInteger;
  v47.allocedAndFlag = 20;
  v5 = SSFMT_JPG;
  v47.data = v47.baseBuffer;
  v47.len = 0;
  v47.baseBuffer[0] = 0;
  idStr::idStr(this: &v49, text: "screenshots/");
  argc = args->argc;
  v7 = 1;
  if ( args->argc > 1 )
  {
    v8 = 2;
    v9 = (const char **)&args->argv[1];
    v10 = (const char **)&args->argv[2];
    do
    {
      if ( v7 < 0 || v7 >= argc )
        v11 = &byte_8200D768;
      else
        v11 = *v9;
      if ( idStr::Icmp(s1: v11, s2: "tga") != 0 )
      {
        if ( v7 < 0 || v7 >= args->argc )
          v12 = &byte_8200D768;
        else
          v12 = *v9;
        if ( idStr::Icmp(s1: v12, s2: "png") != 0 )
        {
          if ( v7 < 0 || v7 >= args->argc )
            v13 = &byte_8200D768;
          else
            v13 = *v9;
          if ( idStr::Icmp(s1: v13, s2: "loadTextures") != 0 )
          {
            if ( v7 < 0 || v7 >= args->argc )
              v14 = &byte_8200D768;
            else
              v14 = *v9;
            if ( idStr::Icmp(s1: v14, s2: "noGuis") != 0 )
            {
              if ( v7 < 0 || v7 >= args->argc )
                v15 = &byte_8200D768;
              else
                v15 = *v9;
              if ( idStr::Icmp(s1: v15, s2: "drawConsole") != 0 )
              {
                if ( v7 < 0 || v7 >= args->argc )
                  v16 = &byte_8200D768;
                else
                  v16 = *v9;
                if ( idStr::Icmp(s1: v16, s2: "blends") != 0 )
                {
                  if ( v7 < args->argc - 1 )
                  {
                    idLib::Printf(fmt: "usage: screenshot [noGuis] [loadTextures] [blends <num>] [tga] [filename]\n");
                    idStr::FreeData(this: &v49);
                    idStr::FreeData(this: &v47);
                    goto LABEL_76;
                  }
                  if ( v7 < 0 || v7 >= args->argc )
                    v18 = &byte_8200D768;
                  else
                    v18 = *v9;
                  idStr::operator=(this: &v46, text: v18);
                }
                else
                {
                  if ( v8 < 0 || v8 >= args->argc )
                    v17 = &byte_8200D768;
                  else
                    v17 = *v10;
                  valueInteger = atol(nptr: v17);
                  ++v7;
                  ++v8;
                  ++v10;
                  ++v9;
                }
              }
              else
              {
                v4 = 1;
              }
            }
          }
          else
          {
            v3 = 1;
          }
        }
        else
        {
          v5 = SSFMT_PNG;
        }
      }
      else
      {
        v5 = SSFMT_TGA;
      }
      ++v8;
      ++v10;
      ++v9;
      argc = args->argc;
      ++v7;
    }
    while ( v7 < args->argc );
  }
  idStr::Append(this: &v49, text: com_capturePath.valueString.data);
  if ( v46.len != 0 )
  {
    if ( idStr::Find(searchIn: v46.data, searchFor: ".tga", casesensitive: false, start: 0, end: v46.len) < 0 )
    {
      if ( idStr::Find(searchIn: v46.data, searchFor: ".png", casesensitive: false, start: 0, end: v46.len) < 0 )
        idStr::SetFileExtension(this: &v46, extension: "jpg");
      else
        v5 = SSFMT_PNG;
    }
    else
    {
      v5 = SSFMT_TGA;
    }
    if ( idStr::Find(searchIn: v46.data, searchFor: "/", casesensitive: false, start: 0, end: v46.len) >= 0 )
      idStr::operator=(this: &v49, text: &byte_8200D768);
    v19 = operator+(result: &v50, a: &v49, b: &v46);
    len = v19->len;
    idStr::EnsureAlloced(this: &v47, amount: v19->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v47.data, Src: v19->data, Size: len);
    v47.data[len] = 0;
    v47.len = len;
    idStr::FreeData(this: &v50);
  }
  else
  {
    idStr::AppendPath(this: &v49, text: "shot");
    R_ScreenshotFilename(lastNumber: &lastNumber, base: v49.data, fileName: &v47, format: v5);
  }
  v21 = idStr::Find(searchIn: v47.data, searchFor: "viewnote", casesensitive: false, start: 0, end: v47.len) >= 0;
  if ( com_captureFrames.valueInteger == 0 )
  {
    if ( v4 == 0 )
      console->Close(this: console, a2: (_cntlzw(v21) & 0x20) != 0);
    common->UpdateConsoleDisplay(this: common, a2: true);
    if ( v21 || v4 != 0 )
      console->Draw(this: console, a2: false, a3: false);
  }
  if ( v3 != 0 || v21 )
  {
    primaryWorld = tr.primaryWorld;
    if ( tr.primaryWorld == nullptr )
      goto LABEL_71;
    tr.primaryWorld->RenderViewForIndex(this: tr.primaryWorld, a2: 0)->g.forceFullVirtualTextureLoad = true;
  }
  primaryWorld = tr.primaryWorld;
LABEL_71:
  idRenderSystemLocal::TakeScreenshot(
    this: &tr,
    width: tr.windowWidth,
    height: tr.windowHeight,
    world: primaryWorld,
    guiList: nullptr,
    numGuis: 0,
    fileName: v47.data,
    blends: valueInteger,
    fsPath: v23,
    format: v24,
    primes: v25,
    fillAlphaWith255: v26,
    skipPostProcessing: v27,
    a14: v28,
    a15: v29,
    a16: v30,
    a17: v31,
    a18: v32,
    a19: v33,
    a20: v34,
    a21: v35,
    a22: v36,
    a23: v37,
    a24: v38,
    a25: v39,
    a26: v40,
    a27: v41,
    a28: FSPATH_SAVE,
    a29: v42,
    a30: v5,
    a31: v43,
    a32: v48,
    a33: v44,
    a34: 1u,
    a35: v45,
    fsPath_3: r_skipPostProcess.valueInteger != 0);
  if ( (v3 != 0 || v21) && tr.primaryWorld != nullptr )
    tr.primaryWorld->RenderViewForIndex(this: tr.primaryWorld, a2: 0)->g.forceFullVirtualTextureLoad = false;
  fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v47.data, a3: v51, a4: 256, a5: FSPATH_SAVE);
  idLib::Printf(fmt: "Wrote %s\n", v51);
  idStr::FreeData(this: &v49);
  idStr::FreeData(this: &v47);
LABEL_76:
  idStr::FreeData(this: &v46);
}


// ========================================================================
// __unwind$236442_0
// EA  : 0x8294E7E8
// RVA : 0x0094E7E8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236442_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 144));
}


// ========================================================================
// __unwind$236443_0
// EA  : 0x8294E810
// RVA : 0x0094E810
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236443_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 176));
}


// ========================================================================
// __unwind$236444_0
// EA  : 0x8294E838
// RVA : 0x0094E838
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236444_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 224));
}


// ========================================================================
// __unwind$236445
// EA  : 0x8294E860
// RVA : 0x0094E860
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236445()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 256));
}


// ========================================================================
// ?MegaScreenShot_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294E890
// RVA : 0x0094E890
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall MegaScreenShot_f(const idCmdArgs *args)
{
  screenshotFormat_t v2; // r17
  int argc; // r11
  int v4; // r30
  int v5; // r28
  const char **v6; // r29
  const char **v7; // r27
  const char *v8; // r3
  const char *v9; // r3
  const char *v10; // r3
  const char *v11; // r3
  const char *v12; // r3
  const char *v13; // r3
  const char *v14; // r3
  const char *v15; // r3
  const char *v16; // r3
  const char *v17; // r4
  idStr *v18; // r29
  size_t len; // r30
  idStr v20; // [sp+60h] [-120h] BYREF
  idStr v21; // [sp+80h] [-100h] BYREF
  idStr v22; // [sp+A0h] [-E0h] BYREF
  idStr v23[6]; // [sp+C0h] [-C0h] BYREF

  idStr::idStr(this: &v22, text: "megascreenshots/");
  v20.len = 0;
  v20.allocedAndFlag = 20;
  v2 = SSFMT_JPG;
  v20.data = v20.baseBuffer;
  v20.baseBuffer[0] = 0;
  argc = args->argc;
  v4 = 1;
  if ( args->argc > 1 )
  {
    v5 = 2;
    v6 = (const char **)&args->argv[1];
    v7 = (const char **)&args->argv[2];
    do
    {
      if ( v4 < 0 || v4 >= argc )
        v8 = &byte_8200D768;
      else
        v8 = *v6;
      if ( idStr::Icmp(s1: v8, s2: "tga") != 0 )
      {
        if ( v4 < 0 || v4 >= args->argc )
          v9 = &byte_8200D768;
        else
          v9 = *v6;
        if ( idStr::Icmp(s1: v9, s2: "png") != 0 )
        {
          if ( v4 < 0 || v4 >= args->argc )
            v10 = &byte_8200D768;
          else
            v10 = *v6;
          if ( idStr::Icmp(s1: v10, s2: "jpg") != 0 )
          {
            if ( v4 < 0 || v4 >= args->argc )
              v11 = &byte_8200D768;
            else
              v11 = *v6;
            if ( idStr::Icmp(s1: v11, s2: "width") == 0 )
            {
              if ( v5 >= 0 && v5 < args->argc )
              {
                v12 = *v7;
LABEL_30:
                atol(nptr: v12);
                ++v5;
                ++v4;
                ++v7;
                ++v6;
                goto LABEL_63;
              }
LABEL_29:
              v12 = &byte_8200D768;
              goto LABEL_30;
            }
            if ( v4 < 0 || v4 >= args->argc )
              v13 = &byte_8200D768;
            else
              v13 = *v6;
            if ( idStr::Icmp(s1: v13, s2: "height") == 0 )
            {
              if ( v5 >= 0 && v5 < args->argc )
              {
                v12 = *v7;
                goto LABEL_30;
              }
              goto LABEL_29;
            }
            if ( v4 < 0 || v4 >= args->argc )
              v14 = &byte_8200D768;
            else
              v14 = *v6;
            if ( idStr::Icmp(s1: v14, s2: "blends") == 0 )
            {
              if ( v5 >= 0 && v5 < args->argc )
              {
                v12 = *v7;
                goto LABEL_30;
              }
              goto LABEL_29;
            }
            if ( v4 < 0 || v4 >= args->argc )
              v15 = &byte_8200D768;
            else
              v15 = *v6;
            if ( idStr::Icmp(s1: v15, s2: "stitch") != 0 )
            {
              v16 = v4 < 0 || v4 >= args->argc ? &byte_8200D768 : *v6;
              if ( idStr::Icmp(s1: v16, s2: "noFog") != 0 )
              {
                if ( v4 < args->argc - 1 )
                {
                  idLib::Printf(
                    fmt: "usage: megaScreenshot [width <num>] [height <num>] [stitch] [blends <num>] [tga|png|jpg] [filename]\n");
                  idStr::FreeData(this: &v20);
                  goto LABEL_77;
                }
                if ( v4 < 0 || v4 >= args->argc )
                  v17 = &byte_8200D768;
                else
                  v17 = *v6;
                idStr::operator=(this: &v20, text: v17);
              }
            }
          }
          else
          {
            v2 = SSFMT_JPG;
          }
        }
        else
        {
          v2 = SSFMT_PNG;
        }
      }
      else
      {
        v2 = SSFMT_TGA;
      }
LABEL_63:
      ++v5;
      ++v7;
      ++v6;
      argc = args->argc;
      ++v4;
    }
    while ( v4 < args->argc );
  }
  idStr::Append(this: &v22, text: com_capturePath.valueString.data);
  v21.allocedAndFlag = 20;
  v21.len = 0;
  v21.data = v21.baseBuffer;
  v21.baseBuffer[0] = 0;
  if ( v20.len != 0 )
  {
    if ( idStr::Find(searchIn: v20.data, searchFor: ".tga", casesensitive: false, start: 0, end: v20.len) < 0
      && idStr::Find(searchIn: v20.data, searchFor: ".png", casesensitive: false, start: 0, end: v20.len) < 0 )
    {
      idStr::SetFileExtension(this: &v20, extension: "jpg");
    }
    if ( idStr::Find(searchIn: v20.data, searchFor: "/", casesensitive: false, start: 0, end: v20.len) >= 0 )
      idStr::operator=(this: &v22, text: &byte_8200D768);
    v18 = operator+(result: v23, a: &v22, b: &v20);
    len = v18->len;
    idStr::EnsureAlloced(this: &v21, amount: v18->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v21.data, Src: v18->data, Size: len);
    v21.data[len] = 0;
    v21.len = len;
    idStr::FreeData(this: v23);
  }
  else
  {
    idStr::AppendPath(this: &v22, text: "shot");
    R_ScreenshotFilename(lastNumber: &lastNumber_0, base: v22.data, fileName: &v21, format: v2);
  }
  if ( tr.primaryWorld != nullptr )
  {
    tr.primaryWorld->RenderViewForIndex(this: tr.primaryWorld, a2: 0)->g.forceFullVirtualTextureLoad = true;
    if ( tr.primaryWorld != nullptr )
      tr.primaryWorld->RenderViewForIndex(this: tr.primaryWorld, a2: 0)->g.forceFullVirtualTextureLoad = false;
  }
  idStr::FreeData(this: &v21);
  idStr::FreeData(this: &v20);
LABEL_77:
  idStr::FreeData(this: &v22);
}


// ========================================================================
// __unwind$236708
// EA  : 0x8294ED58
// RVA : 0x0094ED58
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236708()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 160));
}


// ========================================================================
// __unwind$236709
// EA  : 0x8294ED80
// RVA : 0x0094ED80
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236709()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$236710
// EA  : 0x8294EDA8
// RVA : 0x0094EDA8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236710()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 128));
}


// ========================================================================
// __unwind$236711
// EA  : 0x8294EDD0
// RVA : 0x0094EDD0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236711()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 192));
}


// ========================================================================
// ?R_EnvShot_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294EE00
// RVA : 0x0094EE00
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall R_EnvShot_f(const idCmdArgs *args)
{
  int argc; // r11
  idRenderWorldLocal *primaryWorld; // r30
  idRenderWorldLocal *v4; // r28
  int v5; // r27
  int v6; // r29
  idRenderModel *v7; // r30
  int v8; // r24
  int v9; // r3
  int v10; // r14
  int v11; // r3
  idRenderView *(__fastcall *RenderViewForIndex)(idRenderWorld *, int); // r8
  int v13; // r25
  double Float; // fp1
  double v15; // fp31
  char **v16; // r21
  float *v17; // r30
  double v18; // fp13
  double v19; // fp12
  double v20; // fp6
  char v21; // r22
  unsigned __int8 *v22; // r29
  int v23; // [sp+8h] [-258h]
  bool v24; // [sp+Fh] [-251h]
  bool v25; // [sp+13h] [-24Dh]
  int v26; // [sp+14h] [-24Ch]
  int v27; // [sp+18h] [-248h]
  int v28; // [sp+1Ch] [-244h]
  int v29; // [sp+20h] [-240h]
  int v30; // [sp+24h] [-23Ch]
  int v31; // [sp+28h] [-238h]
  int v32; // [sp+2Ch] [-234h]
  int v33; // [sp+30h] [-230h]
  int v34; // [sp+34h] [-22Ch]
  int v35; // [sp+38h] [-228h]
  int v36; // [sp+3Ch] [-224h]
  int v37; // [sp+40h] [-220h]
  int v38; // [sp+44h] [-21Ch]
  int v39; // [sp+48h] [-218h]
  int v40; // [sp+4Ch] [-214h]
  int v41; // [sp+50h] [-210h]
  int v42; // [sp+58h] [-208h]
  int v43; // [sp+60h] [-200h]
  char *data; // [sp+74h] [-1ECh]
  char *v45; // [sp+78h] [-1E8h]
  parmValue_t v46; // [sp+80h] [-1E0h] BYREF
  int v47; // [sp+90h] [-1D0h]
  idCodeResource<idDeclRenderParm> *v48; // [sp+94h] [-1CCh]
  idRenderSystemLocal *v49; // [sp+98h] [-1C8h]
  idRenderWorldLocal *v50; // [sp+9Ch] [-1C4h]
  idStr v51; // [sp+A0h] [-1C0h] BYREF
  float v52[64]; // [sp+C0h] [-1A0h] BYREF

  argc = args->argc;
  if ( args->argc == 2 || argc == 3 || argc == 4 )
  {
    LODWORD(v52[0]) = "_px.tga";
    LODWORD(v52[2]) = "_py.tga";
    LODWORD(v52[1]) = "_nx.tga";
    LODWORD(v52[3]) = "_ny.tga";
    LODWORD(v52[4]) = "_pz.tga";
    LODWORD(v52[5]) = "_nz.tga";
    if ( argc <= 1 )
      v45 = &byte_8200D768;
    else
      v45 = args->argv[1];
    v49 = &tr;
    primaryWorld = tr.primaryWorld;
    v4 = tr.primaryWorld;
    v50 = tr.primaryWorld;
    if ( tr.primaryWorld != nullptr )
    {
      v5 = 0;
      if ( tr.primaryWorld->renderModels.num > 0 )
      {
        v6 = 0;
        do
        {
          v7 = v4->renderModels.list[v6];
          if ( v7 != nullptr
            && (v7->g.allowSurfaceOnlyInViewID != 0
             || v7->g.suppressSurfaceInViewID != 0
             || v7->g.suppressShadowInViewID != 0
             || v7->g.suppressShadowInLightIndex != -1)
            && !v7->unlinked )
          {
            idRenderModel::CommitThisFrame(this: v7);
            v7->unlinked = true;
          }
          ++v5;
          ++v6;
        }
        while ( v5 < v4->renderModels.num );
        primaryWorld = tr.primaryWorld;
      }
      if ( args->argc == 4 )
      {
        v8 = atol(nptr: args->argv[2]);
        if ( args->argc <= 3 )
          v9 = atol(nptr: &byte_8200D768);
        else
          v9 = atol(nptr: args->argv[3]);
        primaryWorld = tr.primaryWorld;
        v10 = v9;
      }
      else
      {
        if ( args->argc == 3 )
        {
          v11 = atol(nptr: args->argv[2]);
          primaryWorld = tr.primaryWorld;
          v8 = v11;
        }
        else
        {
          v8 = 128;
        }
        v10 = 16;
      }
      memset(Dst: &v52[8], Val: 0, Size: 0xD8u);
      RenderViewForIndex = primaryWorld->RenderViewForIndex;
      v52[8] = 1.0;
      v52[13] = 1.0;
      v52[15] = 1.0;
      v52[17] = -1.0;
      v52[22] = -1.0;
      v52[24] = 1.0;
      v52[27] = 1.0;
      v52[29] = -1.0;
      v52[34] = -1.0;
      v52[36] = -1.0;
      v52[38] = -1.0;
      v52[43] = 1.0;
      v52[46] = 1.0;
      v52[47] = -1.0;
      v52[51] = 1.0;
      v52[55] = -1.0;
      v52[56] = 1.0;
      v52[60] = 1.0;
      v13 = (int)RenderViewForIndex(this: primaryWorld, a2: 0);
      *(float *)(v13 + 16) = 90.0;
      *(float *)(v13 + 20) = 90.0;
      v48 = &cbShowOverlay;
      Float = idParmBlock::GetFloat(this: (idParmBlock *)(v13 + 160), parm: (const idDeclRenderParm *)cbShowOverlay.r);
      v46.value[3] = 0.0;
      v46.value[2] = 0.0;
      v46.value[1] = 0.0;
      v15 = Float;
      v46.value[0] = 0.0;
      idParmBlock::SetParm(
        this: (idParmBlock *)(v13 + 160),
        parm: (const idDeclRenderParm *)cbShowOverlay.r,
        parmValue: &v46);
      v51.len = 0;
      v51.allocedAndFlag = 20;
      v51.data = v51.baseBuffer;
      v51.baseBuffer[0] = 0;
      v47 = 6;
      v46.swizzle[1] = 4 * (v8 & 0xFFFFFFFC) * v8;
      v16 = (char **)v52;
      v17 = &v52[10];
      do
      {
        idStr::operator=(this: &v51, text: "env/");
        idStr::Append(this: &v51, text: v45);
        idStr::Append(this: &v51, text: *v16);
        *(float *)(v13 + 108) = *(v17 - 2);
        v18 = *(v17 - 1);
        v19 = *v17;
        *(float *)(v13 + 120) = v17[1];
        *(float *)(v13 + 112) = v18;
        *(float *)(v13 + 116) = v19;
        *(float *)(v13 + 124) = v17[2];
        *(float *)(v13 + 128) = v17[3];
        *(float *)(v13 + 132) = v17[4];
        v20 = v17[6];
        *(float *)(v13 + 136) = v17[5];
        *(float *)(v13 + 140) = v20;
        *(_BYTE *)(v13 + 92) = 0;
        v21 = r_skipPostProcess.valueInteger != 0;
        data = v51.data;
        v22 = (unsigned __int8 *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                                   size: 4 * (v8 & 0xFFFFFFFC) * v8,
                                   tag: TAG_TEMP,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
        v46.swizzle[0] = (int)v22;
        idRenderSystemLocal::TakeScreenshotToBuffer(
          this: v49,
          width: v8 & 0xFFFFFFFC,
          height: v8,
          world: v50,
          guiList: nullptr,
          numGuis: 0,
          blends: v10,
          outBuffer: v22,
          primes: v23,
          fillAlphaWith255: v24,
          skipPostProcessing: v25,
          a12: v26,
          a13: v27,
          a14: v28,
          a15: v29,
          a16: v30,
          a17: v31,
          a18: v32,
          a19: v33,
          a20: v34,
          a21: v35,
          a22: v36,
          a23: v37,
          a24: v38,
          a25: v39,
          a26: v40,
          a27: v41,
          a28: 0,
          a29: v42,
          a30: 1u,
          a31: v43,
          a32: v21);
        R_WriteTGA(
          filename: data,
          data: (char *)v22,
          width: v8 & 0xFFFFFFFC,
          height: v8,
          depth: 4,
          flipVertical: true,
          swapRGB: true,
          basePath: FSPATH_BASE);
        if ( v22 != nullptr )
          idMem::Free(this: &mem, ptr: v22, align: ALIGN_16);
        ++v16;
        v17 += 9;
        --v47;
      }
      while ( v47 != 0 );
      v46.value[3] = v15;
      v46.value[2] = v15;
      v46.value[1] = v15;
      v46.value[0] = v15;
      idParmBlock::SetParm(this: (idParmBlock *)(v13 + 160), parm: (const idDeclRenderParm *)v48->r, parmValue: &v46);
      idLib::Printf(fmt: "Wrote %s, etc\n", v51.data);
      idStr::FreeData(this: &v51);
    }
  }
  else
  {
    idLib::Printf(fmt: "USAGE: envshot <basename> [size] [blends]\n");
  }
}


// ========================================================================
// __unwind$236978
// EA  : 0x8294F2D0
// RVA : 0x0094F2D0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_236978()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 160));
}


// ========================================================================
// __unwind$237328
// EA  : 0x8294F2F8
// RVA : 0x0094F2F8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_237328()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 608 + 128));
}


// ========================================================================
// ?ShowTexLod_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294F328
// RVA : 0x0094F328
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall ShowTexLod_f(const idCmdArgs *args)
{
  idRenderWorldLocal *primaryWorld; // r29
  const char *v2; // r3
  char v3; // r25
  int v4; // r27
  int v5; // r28
  idRenderModel *v6; // r30
  idRenderModel *v7; // r3
  idRenderModel *v8; // r3
  idStr v9; // [sp+50h] [-90h] BYREF
  idStr v10[3]; // [sp+70h] [-70h] BYREF

  primaryWorld = tr.primaryWorld;
  if ( tr.primaryWorld != nullptr )
  {
    v2 = tr.primaryWorld->GetName(this: tr.primaryWorld);
    idStr::idStr(this: &v9, text: v2);
    idStr::StripFileExtension(this: &v9);
    idStr::Append(this: &v9, text: "/texlod.lwo");
    if ( fileSystem->FileExists(this: fileSystem, a2: v9.data, a3: false) )
    {
      idStr::idStr(this: v10, text: &v9);
      idStr::StripFileExtension(this: v10);
      idStr::Append(this: v10, text: "_crumbs.bmodel");
      v3 = 0;
      v4 = 0;
      if ( primaryWorld->renderModels.num > 0 )
      {
        v5 = 0;
        do
        {
          v6 = primaryWorld->renderModels.list[v5];
          if ( v6 != nullptr
            && (idStr::Icmp(s1: v6->name.str, s2: v9.data) == 0 || idStr::Icmp(s1: v6->name.str, s2: v10[0].data) == 0) )
          {
            v6->unlinked = true;
            v6->deleteOnSync = true;
            v3 = 1;
            idRenderModel::CommitThisFrame(this: v6);
          }
          ++v4;
          ++v5;
        }
        while ( v4 < primaryWorld->renderModels.num );
      }
      if ( v3 != 0 )
      {
        idLib::Printf(fmt: "Removed texLod models.\n");
        idStr::FreeData(this: v10);
      }
      else
      {
        v7 = primaryWorld->AllocRenderModel(this: primaryWorld, a2: v9.data, a3: true, a4: -1);
        if ( !v7->deferredPositionInitialized || !v7->useDeferredPosition )
          v7->g.origin = vec3_origin;
        v7->deferredOrigin = vec3_origin;
        idRenderModel::CommitThisFrame(this: v7);
        idLib::Printf(fmt: "Added %s.\n", v9.data);
        if ( fileSystem->FileExists(this: fileSystem, a2: v10[0].data, a3: false) )
        {
          v8 = primaryWorld->AllocRenderModel(this: primaryWorld, a2: v10[0].data, a3: true, a4: -1);
          if ( !v8->deferredPositionInitialized || !v8->useDeferredPosition )
            v8->g.origin = vec3_origin;
          v8->deferredOrigin = vec3_origin;
          idRenderModel::CommitThisFrame(this: v8);
          idLib::Printf(fmt: "Added %s.\n", v10[0].data);
        }
        idStr::FreeData(this: v10);
      }
    }
    else
    {
      idLib::Warning(fmt: "Texlod model '%s' could not be found!", v9.data);
    }
    idStr::FreeData(this: &v9);
  }
}


// ========================================================================
// __unwind$237437_0
// EA  : 0x8294F5C0
// RVA : 0x0094F5C0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_237437_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$237438_0
// EA  : 0x8294F5E8
// RVA : 0x0094F5E8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_237438_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?TestTransImageAtlas_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294F618
// RVA : 0x0094F618
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall TestTransImageAtlas_f(const idCmdArgs *args)
{
  int argc; // r11
  int v2; // r28
  int v4; // r30
  const char **v5; // r29
  const char *v6; // r3
  idRenderWorldLocal *primaryWorld; // r30
  char *v8; // r3
  idImageAtlas *transSortImageAtlas; // r18
  idImage *atlas; // r15
  idImageData *ImageData; // r21
  idFile *v12; // r22
  idResource *v13; // r3
  __int64 v14; // r7
  float v15; // r5
  int v16; // r26
  float v17; // r4
  int ATLAS_HEIGHT; // r11
  const char *str; // r25
  int v20; // r24
  int v21; // r30
  int v22; // r23
  int v23; // r29
  int v24; // r27
  __int64 v25; // r9
  unsigned int (*Printf)(idFile *, const char *, ...); // r10
  unsigned __int8 *data; // r4
  float *floatData; // r4
  int i; // r29
  char *v30; // r3
  __int64 v31; // r6
  __int64 v32; // r10
  __int64 v33; // r8
  va *v34; // r3
  idImageData *v35; // r30
  unsigned __int8 *v36; // r4
  float *v37; // r4
  int v38; // [sp+8h] [-1238h]
  int v39; // [sp+Ch] [-1234h]
  int v40; // [sp+10h] [-1230h]
  int v41; // [sp+14h] [-122Ch]
  int v42; // [sp+18h] [-1228h]
  int v43; // [sp+1Ch] [-1224h]
  char v44; // [sp+50h] [-11F0h]
  idStr v45; // [sp+70h] [-11D0h] BYREF
  unsigned int trackedMemory; // [sp+90h] [-11B0h]
  int v47; // [sp+94h] [-11ACh]
  float v48; // [sp+98h] [-11A8h]
  float v49; // [sp+9Ch] [-11A4h]
  __int64 v50; // [sp+A0h] [-11A0h]
  unsigned __int64 v51; // [sp+A8h] [-1198h]
  idStr v52; // [sp+B0h] [-1190h] BYREF
  idStr v53; // [sp+D0h] [-1170h] BYREF
  idStr v54; // [sp+F0h] [-1150h] BYREF
  char v55[128]; // [sp+110h] [-1130h] BYREF
  va v56; // [sp+190h] [-10B0h] BYREF

  v2 = 0;
  v4 = 1;
  argc = args->argc;
  v44 = 0;
  if ( args->argc > 1 )
  {
    v5 = (const char **)&args->argv[1];
    do
    {
      if ( v4 < 0 || v4 >= argc )
        v6 = &byte_8200D768;
      else
        v6 = *v5;
      if ( idStr::Icmp(s1: v6, s2: "showMips") != 0 )
      {
        if ( v4 < args->argc - 1 )
        {
          idLib::Printf(fmt: "USAGE: testTransImageAtlas [showMips]\n");
          return;
        }
      }
      else
      {
        v44 = 1;
      }
      argc = args->argc;
      ++v4;
      ++v5;
    }
    while ( v4 < args->argc );
  }
  v45.len = 0;
  v45.baseBuffer[0] = 0;
  v45.allocedAndFlag = 20;
  v45.data = v45.baseBuffer;
  primaryWorld = tr.primaryWorld;
  if ( tr.primaryWorld != nullptr )
  {
    idStr::operator=(this: &v45, text: "atlasShots/");
    v8 = (char *)primaryWorld->GetName(this: primaryWorld);
    idStr::Append(this: &v45, text: v8);
  }
  else
  {
    idStr::operator=(this: &v45, text: "atlasShots/default");
  }
  transSortImageAtlas = globalImages->transSortImageAtlas;
  if ( transSortImageAtlas != nullptr )
  {
    atlas = transSortImageAtlas->atlas;
    if ( atlas != nullptr )
    {
      ImageData = idImage::GetImageData(this: transSortImageAtlas->atlas, mipLevel: 0, z: 0);
      if ( ImageData != nullptr )
      {
        idStr::idStr(this: &v54, text: &v45);
        idStr::SetFileExtension(this: &v54, extension: ".txt");
        idStr::idStr(this: &v53, text: &v45);
        idStr::SetFileExtension(this: &v53, extension: ".tga");
        v12 = fileSystem->OpenFileWrite(this: fileSystem, a2: v54.data, a3: 0);
        if ( v12 != nullptr )
        {
          if ( idAtlasResource::resourceList.num > 0 )
          {
            do
            {
              v13 = idResourceList::Index(this: &idAtlasResource::resourceList, index: v2);
              if ( v13 != nullptr )
              {
                HIDWORD(v14) = v13[1].name.str;
                LODWORD(v14) = transSortImageAtlas->ATLAS_WIDTH;
                v15 = *(float *)&v13[1].nextOnHashChain;
                v16 = 10;
                v17 = *(float *)&v13[1].resourceListPtr;
                ATLAS_HEIGHT = transSortImageAtlas->ATLAS_HEIGHT;
                trackedMemory = v13[1].trackedMemory;
                v47 = HIDWORD(v14);
                v48 = v15;
                v49 = v17;
                v51 = __PAIR64__(trackedMemory, ATLAS_HEIGHT);
                str = v13->name.str;
                v20 = (int)(float)((float)__SPAIR64__(trackedMemory, ATLAS_HEIGHT) * v17);
                v21 = (int)(float)((float)__SPAIR64__(trackedMemory, ATLAS_HEIGHT) * *(float *)&v14);
                v22 = (int)(float)((float)v14 * v15);
                v23 = (int)(float)((float)v14 * *(float *)&trackedMemory);
                if ( (int)(float)(*(float *)&trackedMemory * (float)256.0) <= 10 )
                  v16 = (int)(float)(*(float *)&trackedMemory * (float)256.0);
                v24 = (int)(float)(*(float *)&v14 * (float)256.0);
                if ( v24 > 10 )
                  v24 = 10;
                sprintf_0(string: v55, format: "%d", v2);
                DrawPixelNumber(
                  dest: &ImageData->data[4 * transSortImageAtlas->ATLAS_WIDTH * v20 + 4 * v22],
                  byteStride: 4 * transSortImageAtlas->ATLAS_WIDTH,
                  text: v55,
                  scaleX: v16,
                  scaleY: v24,
                  pixelStride: 4,
                  frontColor: 10,
                  backColor: 2);
                LODWORD(v25) = v21 * v23;
                Printf = v12->Printf;
                v50 = v25;
                Printf(
                  this: v12,
                  a2: "[%d] %s : %dx%d, totalSize %d kb\n",
                  v2,
                  str,
                  v23,
                  v21,
                  (int)(float)((float)v25 * (float)0.0009765625));
              }
              ++v2;
            }
            while ( v2 < idAtlasResource::resourceList.num );
          }
          ((void (__fastcall *)(idFile *, int))v12->dtr_idFile)(a1: v12, a2: 1);
        }
        idLib::Printf(fmt: "Writing %ix%i image to %s\n", ImageData->width, ImageData->height, v53.data);
        idImageData::WriteTGA(this: ImageData, filename: v53.data);
        data = ImageData->data;
        if ( data != nullptr )
          idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
        floatData = ImageData->floatData;
        if ( floatData != nullptr )
          idMem::Free(this: &mem, ptr: floatData, align: ALIGN_16);
        idMem::Free(this: &mem, ptr: ImageData, align: ALIGN_16);
        if ( v44 != 0 )
        {
          for ( i = 1; i < transSortImageAtlas->ATLAS_MIP_LEVELS; ++i )
          {
            v30 = idCmdArgs::Argv(this: args, arg: 1);
            idStr::idStr(this: &v52, text: v30);
            idStr::StripFileExtension(this: &v52);
            HIDWORD(v31) = i;
            v34 = va::va(
                    this: &v56,
                    fmt: "_%d",
                    a3: v31,
                    a4: v33,
                    a5: v32,
                    a6: v38,
                    a7: v39,
                    a8: v40,
                    a9: v41,
                    a10: v42,
                    a11: v43);
            idStr::Append(this: &v52, text: v34);
            idStr::SetFileExtension(this: &v52, extension: ".tga");
            v35 = idImage::GetImageData(this: atlas, mipLevel: i, z: 0);
            idLib::Printf(fmt: "Writing %ix%i image to %s\n", v35->width, v35->height, v52.data);
            idImageData::WriteTGA(this: v35, filename: v52.data);
            v36 = v35->data;
            if ( v36 != nullptr )
              idMem::Free(this: &mem, ptr: v36, align: ALIGN_16);
            v37 = v35->floatData;
            if ( v37 != nullptr )
              idMem::Free(this: &mem, ptr: v37, align: ALIGN_16);
            idMem::Free(this: &mem, ptr: v35, align: ALIGN_16);
            idStr::FreeData(this: &v52);
          }
        }
        idStr::FreeData(this: &v53);
        idStr::FreeData(this: &v54);
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "Could not load transparency image atlas\n");
  }
  idStr::FreeData(this: &v45);
}


// ========================================================================
// __unwind$237630
// EA  : 0x8294FB88
// RVA : 0x0094FB88
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_237630()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4672 + 112));
}


// ========================================================================
// __unwind$237631
// EA  : 0x8294FBB0
// RVA : 0x0094FBB0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_237631()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4672 + 240));
}


// ========================================================================
// __unwind$237632
// EA  : 0x8294FBD8
// RVA : 0x0094FBD8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_237632()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4672 + 208));
}


// ========================================================================
// __unwind$237633
// EA  : 0x8294FC00
// RVA : 0x0094FC00
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_237633()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4672 + 176));
}


// ========================================================================
// ?DrawCollision_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8294FC30
// RVA : 0x0094FC30
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall DrawCollision_f(const idCmdArgs *args)
{
  __int64 v2; // r19
  __int64 v3; // r17
  int v4; // r20
  const char *v5; // r3
  bool v6; // cr58
  int (*GetName)(void); // ctr
  const char *v8; // r3
  idRenderWorldLocal *primaryWorld; // r3
  int v10; // r3
  __int64 v11; // r10
  __int64 v12; // r6
  __int64 v13; // r8
  va *v14; // r3
  const char *v15; // r3
  unsigned int v16; // r22
  unsigned int v17; // r3
  idRenderModel *v18; // r23
  const char *v19; // r3
  char v20; // r28
  int v21; // r29
  int v22; // r30
  __int64 v23; // r10
  va *v24; // r3
  char v25; // r10
  bool v26; // r4
  idRenderModel *v27; // r30
  int v28; // [sp+8h] [-2148h]
  int v29; // [sp+8h] [-2148h]
  int v30; // [sp+Ch] [-2144h]
  int v31; // [sp+Ch] [-2144h]
  int v32; // [sp+10h] [-2140h]
  int v33; // [sp+10h] [-2140h]
  int v34; // [sp+14h] [-213Ch]
  int v35; // [sp+14h] [-213Ch]
  int v36; // [sp+18h] [-2138h]
  int v37; // [sp+18h] [-2138h]
  int v38; // [sp+1Ch] [-2134h]
  int v39; // [sp+1Ch] [-2134h]
  idStr v40; // [sp+60h] [-20F0h] BYREF
  idStr v41; // [sp+80h] [-20D0h] BYREF
  idStr v42; // [sp+A0h] [-20B0h] BYREF
  va v43; // [sp+C0h] [-2090h] BYREF
  va v44; // [sp+10C0h] [-1090h] BYREF

  if ( tr.primaryWorld == nullptr )
  {
    idLib::Printf(fmt: "No primaryWorld.\n");
    return;
  }
  if ( (_S15_0 & 1) == 0 )
  {
    _S15_0 |= 1u;
    mapName_0.allocedAndFlag = 20;
    mapName_0.data = mapName_0.baseBuffer;
    mapName_0.len = 0;
    mapName_0.baseBuffer[0] = 0;
    atexit(func: (void (__fastcall *)())_DrawCollision_f_::_5_::_dynamic_atexit_destructor_for__mapName__);
  }
  v2 = 0;
  v3 = 0;
  v4 = -1;
  if ( args->argc > 1 )
    HIDWORD(v3) = atol(nptr: args->argv[1]);
  if ( args->argc > 2 )
    LODWORD(v3) = atol(nptr: args->argv[2]);
  if ( args->argc > 3 )
    HIDWORD(v2) = atol(nptr: args->argv[3]);
  if ( args->argc > 4 )
    LODWORD(v2) = atol(nptr: args->argv[4]);
  if ( args->argc > 5 )
    v4 = atol(nptr: args->argv[5]);
  v5 = tr.primaryWorld->GetName(this: tr.primaryWorld);
  v6 = idStr::Cmp(s1: mapName_0.data, s2: v5) == 0;
  GetName = (int (*)(void))tr.primaryWorld->GetName;
  if ( !v6 )
  {
    v8 = (const char *)GetName();
    idStr::operator=(this: &mapName_0, text: v8);
    renderModel_0 = nullptr;
LABEL_17:
    primaryWorld = tr.primaryWorld;
    goto LABEL_18;
  }
  v19 = (const char *)GetName();
  if ( idStr::Cmp(s1: mapName_0.data, s2: v19) != 0 || renderModel_0 == nullptr )
    goto LABEL_17;
  v20 = 0;
  v21 = 0;
  if ( tr.primaryWorld->GetNumRenderModels(this: tr.primaryWorld) <= 0 )
  {
LABEL_32:
    primaryWorld = tr.primaryWorld;
  }
  else
  {
    v22 = 0;
    while ( 1 )
    {
      primaryWorld = tr.primaryWorld;
      if ( renderModel_0 == tr.primaryWorld->renderModels.list[v22] )
        break;
      ++v21;
      ++v22;
      if ( v21 >= tr.primaryWorld->GetNumRenderModels(this: tr.primaryWorld) )
        goto LABEL_32;
    }
    v20 = 1;
  }
  renderModel_0 = v20 == 0 ? nullptr : renderModel_0;
LABEL_18:
  v10 = (int)primaryWorld->GetName(this: primaryWorld);
  HIDWORD(v11) = &off_82230000;
  HIDWORD(v12) = v10;
  v14 = va::va(
          this: &v43,
          fmt: "generated/%s",
          a3: v12,
          a4: v13,
          a5: v11,
          a6: v28,
          a7: v30,
          a8: v32,
          a9: v34,
          a10: v36,
          a11: v38);
  idStr::idStr(this: &v40, text: v14);
  idStr::StripFileExtension(this: &v40);
  idStr::Append(this: &v40, text: "/_combo/collision.bmodel");
  v15 = tr.primaryWorld->GetName(this: tr.primaryWorld);
  idStr::idStr(this: &v41, text: v15);
  idStr::Append(this: &v41, text: "/_combo/world.bcm");
  v16 = fileSystem->GetTimestamp(this: fileSystem, a2: v41.data, a3: false);
  v17 = fileSystem->GetTimestamp(this: fileSystem, a2: v40.data, a3: false);
  v18 = renderModel_0;
  if ( renderModel_0 == nullptr )
  {
LABEL_37:
    idLib::Printf(fmt: "Regenerating collision static model\n");
    common->UpdateConsoleDisplay(this: common, a2: true);
    idStr::idStr(this: &v42, text: "exportCollisionModel ");
    idStr::Append(this: &v42, text: &v41);
    HIDWORD(v23) = v4;
    v24 = va::va(
            this: &v44,
            fmt: " %d %d %d %d %d",
            a3: v3,
            a4: v2,
            a5: v23,
            a6: v29,
            a7: v31,
            a8: v33,
            a9: v35,
            a10: v37,
            a11: v39);
    idStr::Append(this: &v42, text: v24);
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v42.data);
    ++idResourceList::staleCount;
    renderModel_0 = tr.primaryWorld->AllocRenderModel(this: tr.primaryWorld, a2: v40.data, a3: 1, a4: -1);
    exportedContentIncludeFlags = HIDWORD(v2);
    exportedContentExcludeFlags = v2;
    exportedSurfaceIncludeFlags = HIDWORD(v3);
    exportedSurfaceExcludeFlags = v3;
    exportedSurfaceType = v4;
    showingCollision = false;
    idStr::FreeData(this: &v42);
    goto LABEL_38;
  }
  if ( v17 == -1
    || v17 < v16
    || HIDWORD(v3) != exportedSurfaceIncludeFlags
    || __PAIR64__(HIDWORD(v2), v3) != __PAIR64__(exportedContentIncludeFlags, exportedSurfaceExcludeFlags)
    || (_DWORD)v2 != exportedContentExcludeFlags
    || v4 != exportedSurfaceType )
  {
    if ( !renderModel_0->unlinked )
    {
      idRenderModel::CommitThisFrame(this: renderModel_0);
      v18->unlinked = true;
    }
    goto LABEL_37;
  }
  idLib::Printf(fmt: "%s is up to date with %s\n", v40.data, v41.data);
LABEL_38:
  idStr::FreeData(this: &v41);
  idStr::FreeData(this: &v40);
  v25 = _cntlzw(showingCollision);
  showingCollision = (v25 & 0x20) != 0;
  if ( (v25 & 0x20) != 0 )
  {
    idRenderModel::CommitThisFrame(this: renderModel_0);
    idCVar::SetBool(this: &r_skipWorld, newValue: true, force: true);
    idCVar::SetBool(this: &r_skipFoliage, newValue: true, force: true);
    v26 = true;
  }
  else
  {
    v27 = renderModel_0;
    if ( !renderModel_0->unlinked )
    {
      idRenderModel::CommitThisFrame(this: renderModel_0);
      v27->unlinked = true;
    }
    idCVar::SetBool(this: &r_skipWorld, newValue: false, force: true);
    idCVar::SetBool(this: &r_skipFoliage, newValue: false, force: true);
    v26 = false;
  }
  idCVar::SetBool(this: &r_skipParticles, newValue: v26, force: true);
}


// ========================================================================
// __unwind$237928
// EA  : 0x82950180
// RVA : 0x00950180
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_237928()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8528 + 96));
}


// ========================================================================
// __unwind$237929
// EA  : 0x829501A8
// RVA : 0x009501A8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_237929()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8528 + 128));
}


// ========================================================================
// __unwind$237930
// EA  : 0x829501D0
// RVA : 0x009501D0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_237930()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8528 + 160));
}


// ========================================================================
// ?GenerateOrthoMap_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82950420
// RVA : 0x00950420
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall GenerateOrthoMap_f(const idCmdArgs *args)
{
  double v2; // fp24
  double v3; // fp26
  double v4; // fp25
  __int64 v5; // r14
  int v6; // r16
  int v7; // r30
  char *v8; // r11
  const char *v9; // r3
  int v10; // r11
  int v11; // r10
  bool v12; // cr56
  const char *v13; // r3
  int v14; // r4
  const char *v15; // r3
  int v16; // r11
  int v17; // r10
  bool v18; // cr56
  const char *v19; // r3
  long double v20; // fp2
  const char *v21; // r3
  int v22; // r11
  int v23; // r10
  bool v24; // cr56
  const char *v25; // r3
  long double v26; // fp2
  const char *v27; // r3
  int v28; // r11
  int v29; // r10
  bool v30; // cr56
  const char *v31; // r3
  int v32; // r4
  const char *v33; // r3
  int v34; // r11
  int v35; // r10
  bool v36; // cr56
  const char *v37; // r3
  int v38; // r4
  const char *v39; // r3
  int v40; // r11
  int v41; // r10
  bool v42; // cr56
  const char *v43; // r3
  int v44; // r11
  bool v45; // cr56
  float *v46; // r16
  int v47; // r30
  int v48; // r7
  int v49; // r6
  const char *v50; // r3
  long double v51; // fp2
  double v52; // fp27
  int v53; // r30
  const char *v54; // r3
  long double v55; // fp2
  double v56; // fp28
  float v57; // r10
  int v58; // r30
  float v59; // r9
  const char *v60; // r3
  long double v61; // fp2
  double v62; // fp29
  const char *v63; // r3
  long double v64; // fp2
  double v65; // fp30
  const char *v66; // r3
  const char *v67; // r3
  int argc; // r11
  int v69; // r10
  bool v70; // cr56
  const char *v71; // r3
  long double v72; // fp2
  const char *v73; // r3
  bool v74; // cr56
  const char *v75; // r3
  const char *v76; // r4
  int v77; // r17
  idRenderWorldLocal *primaryWorld; // r3
  idRenderWorldLocal *v79; // r20
  int v80; // r28
  int v81; // r29
  idRenderModel *v82; // r30
  idRenderModel *skyModel; // r30
  int v84; // r30
  idParmBlock *v85; // r15
  double Float; // fp1
  double v87; // fp23
  const char *v88; // r29
  double v89; // fp1
  double v90; // fp22
  double v92; // fp10
  double v93; // fp9
  double v94; // fp8
  __int64 v95; // r11
  double v128; // fp29
  double v129; // fp25
  double v130; // fp27
  const char *v131; // r3
  int v132; // r22
  __int64 v133; // r11
  float *v134; // r29
  unsigned int v135; // r28
  int v136; // r26
  double v137; // fp28
  char *v138; // r27
  __int64 v139; // r11
  int *v140; // r27
  int v141; // r17
  char v142; // r16
  idFile *v143; // r3
  idFile *v144; // r25
  int v145; // r27
  void *v146; // r3
  int *list; // r22
  int v148; // r24
  void *v149; // r26
  int v150; // r29
  int *v151; // r28
  idFile *v152; // r3
  idFile *v153; // r30
  int i; // r28
  int v155; // r30
  int *v156; // r29
  int v157; // r29
  int *v158; // r30
  idRenderModel *v159; // r3
  const char *v160; // r3
  int v161; // r29
  int v162; // r28
  int j; // r30
  int v164; // [sp+8h] [-348h]
  int v165; // [sp+8h] [-348h]
  bool v166; // [sp+Fh] [-341h]
  bool v167; // [sp+Fh] [-341h]
  bool v168; // [sp+13h] [-33Dh]
  bool v169; // [sp+13h] [-33Dh]
  int v170; // [sp+14h] [-33Ch]
  int v171; // [sp+14h] [-33Ch]
  double v172; // [sp+18h] [-338h]
  int v173; // [sp+18h] [-338h]
  int v174; // [sp+1Ch] [-334h]
  double v175; // [sp+20h] [-330h]
  int v176; // [sp+20h] [-330h]
  int v177; // [sp+24h] [-32Ch]
  double v178; // [sp+28h] [-328h]
  int v179; // [sp+28h] [-328h]
  int v180; // [sp+2Ch] [-324h]
  double v181; // [sp+30h] [-320h]
  int v182; // [sp+30h] [-320h]
  int v183; // [sp+34h] [-31Ch]
  int v184; // [sp+38h] [-318h]
  int v185; // [sp+38h] [-318h]
  int v186; // [sp+3Ch] [-314h]
  int v187; // [sp+3Ch] [-314h]
  int v188; // [sp+40h] [-310h]
  int v189; // [sp+40h] [-310h]
  int v190; // [sp+44h] [-30Ch]
  int v191; // [sp+44h] [-30Ch]
  int v192; // [sp+48h] [-308h]
  int v193; // [sp+48h] [-308h]
  int v194; // [sp+4Ch] [-304h]
  int v195; // [sp+4Ch] [-304h]
  int v196; // [sp+50h] [-300h]
  int v197; // [sp+50h] [-300h]
  int v198; // [sp+58h] [-2F8h]
  int v199; // [sp+58h] [-2F8h]
  int v200; // [sp+60h] [-2F0h]
  int v201; // [sp+60h] [-2F0h]
  char v202; // [sp+70h] [-2E0h]
  unsigned __int8 v203; // [sp+71h] [-2DFh]
  int v204; // [sp+74h] [-2DCh]
  int v205; // [sp+78h] [-2D8h]
  __int64 v206; // [sp+80h] [-2D0h] BYREF
  idList<int,5> v207; // [sp+90h] [-2C0h] BYREF
  bool v208; // [sp+A0h] [-2B0h]
  bool v209; // [sp+A1h] [-2AFh]
  bool v210; // [sp+A2h] [-2AEh]
  bool v211; // [sp+A3h] [-2ADh]
  float v212; // [sp+B0h] [-2A0h] BYREF
  float v213; // [sp+B4h] [-29Ch]
  float v214; // [sp+B8h] [-298h]
  float v215; // [sp+BCh] [-294h]
  float v216; // [sp+C0h] [-290h]
  float v217; // [sp+C4h] [-28Ch]
  fsPath_t v218; // [sp+C8h] [-288h]
  idCVar *v219; // [sp+CCh] [-284h]
  int v220; // [sp+D0h] [-280h]
  idCVar *v221; // [sp+D4h] [-27Ch]
  const char *valueInteger; // [sp+D8h] [-278h]
  idCVar *v223; // [sp+DCh] [-274h]
  const char *v224; // [sp+E0h] [-270h]
  idCVar *v225; // [sp+E4h] [-26Ch]
  idCVar *v226; // [sp+E8h] [-268h]
  const char *v227; // [sp+ECh] [-264h]
  char *v228; // [sp+F0h] [-260h]
  unsigned int v229; // [sp+F4h] [-25Ch]
  idStr v230; // [sp+100h] [-250h] BYREF
  idVec3 v231; // [sp+120h] [-230h] BYREF
  __int64 v232; // [sp+130h] [-220h]
  idBounds v233; // [sp+140h] [-210h] BYREF
  idStr v234; // [sp+160h] [-1F0h] BYREF
  _BYTE v235[13]; // [sp+180h] [-1D0h] BYREF
  __int16 v236; // [sp+18Dh] [-1C3h]
  char v237; // [sp+18Fh] [-1C1h]
  __int16 v238; // [sp+190h] [-1C0h]
  idMat3 v239; // [sp+1A0h] [-1B0h] BYREF
  idVec3 v240; // [sp+1C8h] [-188h] BYREF
  idStr v241; // [sp+1E0h] [-170h] BYREF
  idStr v242; // [sp+200h] [-150h] BYREF
  idStr v243; // [sp+220h] [-130h] BYREF
  idStr v244[3]; // [sp+240h] [-110h] BYREF

  LODWORD(v5) = 0;
  v230.len = 0;
  v230.data = v230.baseBuffer;
  v230.allocedAndFlag = 20;
  v230.baseBuffer[0] = 0;
  v202 = 0;
  v203 = 0;
  v2 = 10000.0;
  HIDWORD(v232) = &vec3_origin;
  v3 = 0.0099999998;
  v204 = 200;
  v233.b[0] = vec3_origin;
  v220 = 16;
  v205 = 6;
  v4 = 0.0;
  v233.b[1] = vec3_origin;
  idStr::idStr(this: &v234, text: "genMap");
  v7 = 1;
  HIDWORD(v206) = args->argc;
  v6 = HIDWORD(v206);
  v218 = FSPATH_SAVE;
  if ( SHIDWORD(v206) > 1 )
  {
    v228 = "GenerateOrthoMap: Using custom output prefix %s\n";
    v225 = (idCVar *)"GenerateOrthoMap: Using %s as path\n";
    v223 = (idCVar *)"textures/guis/minimap";
    v221 = (idCVar *)"-saveToBasePath";
    v219 = (idCVar *)"GenerateOrthoMap: Using custom world bounds padding %.2f\n";
    v226 = (idCVar *)"-worldBoundsPadding";
    valueInteger = "GenerateOrthoMap: Using world bounds\n";
    v227 = "-useWorldBounds";
    v224 = "GenerateOrthoMap: Using custom bounds TopLeft: [ %f, %f ] BottomRight: [ %f, %f ]\n";
    do
    {
      v8 = v7 < 0 || v7 >= v6 ? &byte_8200D768 : args->argv[v7];
      if ( *v8 != 45 )
        break;
      if ( v7 < 0 || v7 >= v6 )
        v9 = &byte_8200D768;
      else
        v9 = args->argv[v7];
      if ( idStr::Icmp(s1: v9, s2: "-size") != 0 )
      {
        if ( v7 < 0 || v7 >= args->argc )
          v15 = &byte_8200D768;
        else
          v15 = args->argv[v7];
        if ( idStr::Icmp(s1: v15, s2: "-deltaZ") != 0 )
        {
          if ( v7 < 0 || v7 >= args->argc )
            v21 = &byte_8200D768;
          else
            v21 = args->argv[v7];
          if ( idStr::Icmp(s1: v21, s2: "-axisOffset") != 0 )
          {
            if ( v7 < 0 || v7 >= args->argc )
              v27 = &byte_8200D768;
            else
              v27 = args->argv[v7];
            if ( idStr::Icmp(s1: v27, s2: "-numBlends") != 0 )
            {
              if ( v7 < 0 || v7 >= args->argc )
                v33 = &byte_8200D768;
              else
                v33 = args->argv[v7];
              if ( idStr::Icmp(s1: v33, s2: "-numSteps") != 0 )
              {
                if ( v7 < 0 || v7 >= args->argc )
                  v39 = &byte_8200D768;
                else
                  v39 = args->argv[v7];
                if ( idStr::Icmp(s1: v39, s2: "-outputPrefix") != 0 )
                {
                  if ( v7 < 0 || v7 >= args->argc )
                    v43 = &byte_8200D768;
                  else
                    v43 = args->argv[v7];
                  if ( idStr::Icmp(s1: v43, s2: "-useCustomBounds") != 0 )
                  {
                    if ( v7 < 0 || v7 >= args->argc )
                      v66 = &byte_8200D768;
                    else
                      v66 = args->argv[v7];
                    if ( idStr::Icmp(s1: v66, s2: v227) != 0 )
                    {
                      if ( v7 < 0 || v7 >= args->argc )
                        v67 = &byte_8200D768;
                      else
                        v67 = args->argv[v7];
                      if ( idStr::Icmp(s1: v67, s2: (const char *)v226) != 0 )
                      {
                        if ( v7 < 0 || v7 >= args->argc )
                          v73 = &byte_8200D768;
                        else
                          v73 = args->argv[v7];
                        if ( idStr::Icmp(s1: v73, s2: (const char *)v221) != 0 )
                        {
                          if ( v7 < 0 || v7 >= args->argc )
                            v75 = &byte_8200D768;
                          else
                            v75 = args->argv[v7];
                          if ( idStr::Icmp(s1: v75, s2: "-help") != 0 )
                          {
                            if ( v7 < 0 || v7 >= args->argc )
                              v76 = &byte_8200D768;
                            else
                              v76 = args->argv[v7];
                            idLib::Warning(fmt: "GenerateOrthoMap: Unrecognized parameter %s", v76);
                            break;
                          }
                          goto LABEL_138;
                        }
                        idStr::operator=(this: &v234, text: (const char *)v223);
                        v218 = FSPATH_BASE;
                        idLib::Printf(fmt: (const char *)v225, v234.data);
                      }
                      else
                      {
                        argc = args->argc;
                        v69 = v7 + 1;
                        v70 = v7 + 1 < args->argc;
                        HIDWORD(v206) = args->argc;
                        if ( !v70 )
                          break;
                        ++v7;
                        if ( v69 < 0 || v69 >= argc )
                          v71 = &byte_8200D768;
                        else
                          v71 = args->argv[v69];
                        v72 = atof(nptr: v71);
                        v4 = (float)*(double *)&v72;
                        if ( v4 < 0.0 )
                        {
                          idLib::Warning(fmt: (const char *)HIDWORD(v4), LODWORD(v4));
                          idStr::FreeData(this: &v234);
                          goto LABEL_221;
                        }
                        v172 = v4;
                        idLib::Printf(fmt: (const char *)v219, LODWORD(v4), v4, *((double *)&v72 + 1));
                      }
                    }
                    else
                    {
                      if ( v203 != 0 )
                        goto _M240000;
                      v202 = 1;
                      idLib::Printf(fmt: valueInteger);
                    }
                  }
                  else
                  {
                    v44 = args->argc;
                    v45 = v7 + 4 < args->argc;
                    HIDWORD(v206) = args->argc;
                    if ( !v45 )
                      break;
                    if ( v202 != 0 )
                    {
_M240000:
                      idLib::Warning(fmt: "GenerateOrthoMap: Cannot use both world bounds AND custom bounds");
                      break;
                    }
                    v46 = (float *)HIDWORD(v232);
                    v47 = v7 + 1;
                    v203 = 1;
                    v48 = *(_DWORD *)(HIDWORD(v232) + 4);
                    v49 = *(_DWORD *)(HIDWORD(v232) + 8);
                    v207.list = *(int **)HIDWORD(v232);
                    v207.num = v48;
                    v207.size = v49;
                    if ( v47 < 0 || v47 >= v44 )
                      v50 = &byte_8200D768;
                    else
                      v50 = args->argv[v47];
                    v51 = atof(nptr: v50);
                    v52 = (float)*(double *)&v51;
                    *(float *)&v207.num = *(double *)&v51;
                    v53 = v47 + 1;
                    if ( v53 < 0 || v53 >= args->argc )
                      v54 = &byte_8200D768;
                    else
                      v54 = args->argv[v53];
                    v55 = atof(nptr: v54);
                    v56 = (float)*(double *)&v55;
                    *(float *)&v207.list = *(double *)&v55;
                    idBounds::AddPoint(this: &v233, v: (const idVec3 *)&v207);
                    v57 = v46[1];
                    v58 = v53 + 1;
                    v59 = v46[2];
                    v231.x = *v46;
                    v231.y = v57;
                    v231.z = v59;
                    if ( v58 < 0 || v58 >= args->argc )
                      v60 = &byte_8200D768;
                    else
                      v60 = args->argv[v58];
                    v61 = atof(nptr: v60);
                    v62 = (float)*(double *)&v61;
                    v231.y = *(double *)&v61;
                    v7 = v58 + 1;
                    if ( v7 < 0 || v7 >= args->argc )
                      v63 = &byte_8200D768;
                    else
                      v63 = args->argv[v7];
                    v64 = atof(nptr: v63);
                    v65 = (float)*(double *)&v64;
                    v231.x = *(double *)&v64;
                    v178 = v65;
                    idBounds::AddPoint(this: &v233, v: &v231);
                    v175 = v52;
                    v172 = v56;
                    v181 = v62;
                    idLib::Printf(fmt: v224, LODWORD(v56), LODWORD(v52), HIDWORD(v62), LODWORD(v62), v56, v52, v65, v62);
                  }
                }
                else
                {
                  v40 = args->argc;
                  v41 = v7 + 1;
                  v42 = v7 + 1 < args->argc;
                  HIDWORD(v206) = args->argc;
                  if ( !v42 )
                    break;
                  ++v7;
                  if ( v41 < 0 || v41 >= v40 )
                  {
                    idStr::operator=(this: &v230, text: &byte_8200D768);
                    idLib::Printf(fmt: v228, v230.data);
                  }
                  else
                  {
                    idStr::operator=(this: &v230, text: args->argv[v41]);
                    idLib::Printf(fmt: v228, v230.data);
                  }
                }
              }
              else
              {
                v34 = args->argc;
                v35 = v7 + 1;
                v36 = v7 + 1 < args->argc;
                HIDWORD(v206) = args->argc;
                if ( !v36 )
                  break;
                ++v7;
                if ( v35 < 0 || v35 >= v34 )
                  v37 = &byte_8200D768;
                else
                  v37 = args->argv[v35];
                v38 = atol(nptr: v37);
                v205 = v38;
                if ( v38 < 1 )
                {
                  idLib::Warning(fmt: "GenerateOrthoMap: -numSteps cannot be less than 1 (got %d)", v38);
                  idStr::FreeData(this: &v234);
                  goto LABEL_221;
                }
                idLib::Printf(fmt: "GenerateOrthoMap: Using custom numSteps %d\n", v38);
              }
            }
            else
            {
              v28 = args->argc;
              v29 = v7 + 1;
              v30 = v7 + 1 < args->argc;
              HIDWORD(v206) = args->argc;
              if ( !v30 )
                break;
              ++v7;
              if ( v29 < 0 || v29 >= v28 )
                v31 = &byte_8200D768;
              else
                v31 = args->argv[v29];
              v32 = atol(nptr: v31);
              v220 = v32;
              if ( v32 < 0 )
              {
                idLib::Warning(fmt: "GenerateOrthoMap: -numBlends cannot be less than 0 (got %d)", v32);
                idStr::FreeData(this: &v234);
                goto LABEL_221;
              }
              idLib::Printf(fmt: "GenerateOrthoMap: Using custom numBlends %d\n", v32);
            }
          }
          else
          {
            v22 = args->argc;
            v23 = v7 + 1;
            v24 = v7 + 1 < args->argc;
            HIDWORD(v206) = args->argc;
            if ( !v24 )
              break;
            ++v7;
            if ( v23 < 0 || v23 >= v22 )
              v25 = &byte_8200D768;
            else
              v25 = args->argv[v23];
            v26 = atof(nptr: v25);
            v3 = (float)*(double *)&v26;
            v172 = v3;
            idLib::Printf(fmt: "GenerateOrthoMap: Using custom axisOffset %f\n", v3);
          }
        }
        else
        {
          v16 = args->argc;
          v17 = v7 + 1;
          v18 = v7 + 1 < args->argc;
          HIDWORD(v206) = args->argc;
          if ( !v18 )
            break;
          ++v7;
          if ( v17 < 0 || v17 >= v16 )
            v19 = &byte_8200D768;
          else
            v19 = args->argv[v17];
          v20 = atof(nptr: v19);
          v2 = (float)*(double *)&v20;
          v172 = v2;
          idLib::Printf(fmt: "GenerateOrthoMap: Using custom deltaZ %f\n", v2);
        }
      }
      else
      {
        v10 = args->argc;
        v11 = v7 + 1;
        v12 = v7 + 1 < args->argc;
        HIDWORD(v206) = args->argc;
        if ( !v12 )
          break;
        ++v7;
        if ( v11 < 0 || v11 >= v10 )
          v13 = &byte_8200D768;
        else
          v13 = args->argv[v11];
        v14 = atol(nptr: v13);
        v204 = v14;
        if ( v14 < 0 )
        {
          idLib::Warning(fmt: "GenerateOrthoMap: -size cannot be 0 or smaller (got %d)", v14);
          idStr::FreeData(this: &v234);
          goto LABEL_221;
        }
        idLib::Printf(fmt: "GenerateOrthoMap: Using custom size %d\n", v14);
      }
      v6 = args->argc;
      v74 = ++v7 < args->argc;
      HIDWORD(v206) = args->argc;
    }
    while ( v74 );
  }
  v77 = v204;
  if ( v7 < args->argc )
  {
LABEL_138:
    idLib::Printf(
      fmt: "generateOrthoMap [options]\n"
      "    -useWorldBounds               Use the bounds of the actual world geometry when creating the screenshot. By def"
      "ault uses [-64000, 64000]\n"
      "    -useCustomBounds T L B R      Specifies the Top, Left, Bottom, and Right bounds to use\n"
      "    -saveToBasePath               Uses the standard minimap textures folder as the output path. Default: saves to "
      "fs_savepath under the genMap folder\n"
      "    -outputPrefix STRING          Filename prefix for the output file. Defaults to the map's name.\n"
      "    -size INTEGER                 Dimension of each screenshot. Default: 200\n"
      "    -numSteps INTEGER             Number of rows/columns for output. Default: 6\n"
      "    -numBlends INTEGER            Number of blends on each screenshot. Default: 16\n"
      "    -worldBoundsPadding FLOAT     Fraction padding to add to the world bounds to get a margin around the output im"
      "age. Default: 0    -deltaZ FLOAT                 Distance from origin to either z-plane. Default: 10000\n"
      "    -axisOffset FLOAT             Angle to rotate eye basis (on +x axis) to help with precision issues. Default: 0"
      ".01\n"
      "    -help                         Shows this message\n");
    idStr::FreeData(this: &v234);
  }
  else if ( tr.windowWidth < v204 || tr.windowHeight < v204 )
  {
    idLib::Printf(fmt: "Window cannot be smaller than %d x %d\n", v204, v204);
    idStr::FreeData(this: &v234);
  }
  else
  {
    primaryWorld = tr.primaryWorld;
    v79 = tr.primaryWorld;
    if ( tr.primaryWorld != nullptr )
    {
      v80 = 0;
      if ( tr.primaryWorld->renderModels.num > 0 )
      {
        v81 = 0;
        do
        {
          v82 = v79->renderModels.list[v81];
          if ( v82 != nullptr
            && (v82->g.allowSurfaceOnlyInViewID != 0
             || v82->g.suppressSurfaceInViewID != 0
             || v82->g.suppressShadowInViewID != 0
             || v82->g.suppressShadowInLightIndex != -1)
            && !v82->unlinked )
          {
            idRenderModel::CommitThisFrame(this: v82);
            v82->unlinked = true;
          }
          ++v80;
          ++v81;
        }
        while ( v80 < v79->renderModels.num );
        primaryWorld = tr.primaryWorld;
      }
      skyModel = v79->skyModel;
      if ( skyModel != nullptr && !skyModel->unlinked )
      {
        idRenderModel::CommitThisFrame(this: v79->skyModel);
        skyModel->unlinked = true;
        primaryWorld = tr.primaryWorld;
      }
      v84 = (int)primaryWorld->RenderViewForIndex(this: primaryWorld, a2: 0);
      *(float *)(v84 + 20) = 90.0;
      *(_BYTE *)(v84 + 11) = 1;
      *(float *)(v84 + 16) = 90.0;
      *(_BYTE *)(v84 + 9) = 1;
      *(_BYTE *)(v84 + 12) = 1;
      *(_BYTE *)(v84 + 8) = 1;
      v225 = &rs_enable;
      v211 = rs_enable.valueInteger != 0;
      idCVar::SetBool(this: &rs_enable, newValue: false, force: true);
      v223 = &r_skipFlares;
      v210 = r_skipFlares.valueInteger != 0;
      idCVar::SetBool(this: &r_skipFlares, newValue: true, force: true);
      v221 = &r_useDynamicEnvironment;
      v209 = r_useDynamicEnvironment.valueInteger != 0;
      idCVar::SetBool(this: &r_useDynamicEnvironment, newValue: false, force: true);
      v219 = &r_skipParticles;
      v208 = r_skipParticles.valueInteger != 0;
      idCVar::SetBool(this: &r_skipParticles, newValue: true, force: true);
      v226 = &r_extraClears;
      valueInteger = (const char *)r_extraClears.valueInteger;
      idCVar::SetInteger(this: &r_extraClears, newValue: 1, force: true);
      v85 = (idParmBlock *)(v84 + 160);
      v227 = (const char *)&cbShowOverlay;
      Float = idParmBlock::GetFloat(this: (idParmBlock *)(v84 + 160), parm: (const idDeclRenderParm *)cbShowOverlay.r);
      *(float *)&v207.granularity = 0.0;
      *(float *)&v207.size = 0.0;
      *(float *)&v207.num = 0.0;
      *(float *)&v207.list = 0.0;
      v87 = Float;
      idParmBlock::SetParm(
        this: (idParmBlock *)(v84 + 160),
        parm: (const idDeclRenderParm *)cbShowOverlay.r,
        parmValue: (const parmValue_t *)&v207);
      v88 = (const char *)idDeclInfo::FindWithInheritance(
                            this: &idDeclRenderParm::resourceList,
                            name: "fogScale",
                            makeDefault: true);
      v224 = v88;
      v89 = idParmBlock::GetFloat(this: (idParmBlock *)(v84 + 160), parm: (const idDeclRenderParm *)v88);
      *(float *)&v207.granularity = 0.0;
      *(float *)&v207.size = 0.0;
      *(float *)&v207.num = 0.0;
      *(float *)&v207.list = 0.0;
      v90 = v89;
      idParmBlock::SetParm(
        this: (idParmBlock *)(v84 + 160),
        parm: (const idDeclRenderParm *)v88,
        parmValue: (const parmValue_t *)&v207);
      v240.y = 0.0;
      v240.z = 0.0;
      *(_QWORD *)&v239.mat[0].x = v5;
      *(_QWORD *)&v239.mat[1].y = v5;
      v239.mat[2].x = *(float *)&v5;
      v239.mat[2].z = 0.0;
      v240.x = 1.0;
      v239.mat[0].z = -1.0;
      v239.mat[1].x = -1.0;
      v239.mat[2].y = 1.0;
      idMat3::RotateSelf(this: &v239, axis: &v240, angle: v3);
      *(float *)(v84 + 108) = v239.mat[0].x;
      *(float *)(v84 + 112) = v239.mat[0].y;
      *(float *)(v84 + 116) = v239.mat[0].z;
      *(float *)(v84 + 120) = v239.mat[1].x;
      HIDWORD(v206) = v84 + 132;
      *(float *)(v84 + 124) = v239.mat[1].y;
      *(float *)(v84 + 128) = v239.mat[1].z;
      *(idVec3 *)(v84 + 132) = v239.mat[2];
      _FP0 = 1.0e30;
      v92 = -1.0e30;
      v214 = 1.0e30;
      v213 = 1.0e30;
      v212 = 1.0e30;
      v93 = -1.0e30;
      v217 = -1.0e30;
      v94 = -1.0e30;
      v216 = v217;
      v215 = v217;
      if ( v202 != 0 )
      {
        v79->GetStaticWorldBounds(this: v79, a2: (idBounds *)&v212);
        _FP13 = v216;
        _FP0 = v215;
        _FP12 = v213;
        _FP11 = v212;
      }
      else
      {
        HIDWORD(v95) = v203;
        if ( v203 != 0 )
        {
          _FP2 = (float)((float)1.0e30 - v233.b[0].z);
          _FP21 = (float)(v233.b[1].z - (float)v92);
          _FP1 = (float)((float)1.0e30 - v233.b[0].x);
          _FP29 = (float)((float)1.0e30 - v233.b[0].y);
          _FP27 = (float)(v233.b[1].x - (float)v94);
          _FP26 = (float)(v233.b[1].y - (float)v93);
          __asm { fsel      f0, f2, f5, f0 }
          v214 = _FP0;
          __asm { fsel      f10, f21, f7, f10 }
          v217 = _FP10;
          __asm
          {
            fsel      f11, f1, f3, f11
            fsel      f12, f29, f4, f12
            fsel      f0, f27, f6, f8
            fsel      f13, f26, f13, f9
          }
        }
        else
        {
          __asm { fsel      f7, f0, f31, f0 }
          _FP6 = -v92;
          HIDWORD(v95) = "Mips";
          _FP5 = (float)((float)1.0e30 - (float)-32000.0);
          _FP4 = _FP5;
          _FP3 = (float)((float)-32000.0 - (float)v94);
          _FP2 = (float)((float)-32000.0 - (float)v93);
          __asm { fsel      f1, f7, f31, f7 }
          v214 = _FP1;
          __asm
          {
            fsel      f10, f6, f31, f10
            fsel      f7, f5, f0, f11
            fsel      f6, f4, f0, f12
            fsel      f5, f3, f0, f8
            fsel      f4, f2, f0, f9
          }
          _FP3 = -_FP10;
          _FP2 = (float)((float)_FP7 - (float)32000.0);
          _FP1 = (float)((float)_FP6 - (float)32000.0);
          _FP0 = (float)((float)32000.0 - (float)_FP5);
          _FP9 = (float)((float)32000.0 - (float)_FP4);
          __asm { fsel      f8, f3, f31, f10 }
          v217 = _FP8;
          __asm
          {
            fsel      f11, f2, f13, f7
            fsel      f12, f1, f13, f6
            fsel      f0, f0, f13, f5
            fsel      f13, f9, f13, f4
          }
        }
        v216 = _FP13;
        v215 = _FP0;
        v213 = _FP12;
        v212 = _FP11;
      }
      if ( v4 != 0.0 )
      {
        _FP11 = (float)((float)((float)v4 + (float)1.0) * (float)_FP11);
        v212 = _FP11;
        _FP12 = (float)((float)((float)v4 + (float)1.0) * (float)_FP12);
        v213 = _FP12;
        v214 = (float)((float)v4 + (float)1.0) * v214;
        _FP0 = (float)((float)((float)v4 + (float)1.0) * (float)_FP0);
        v215 = _FP0;
        _FP13 = (float)((float)((float)v4 + (float)1.0) * (float)_FP13);
        v216 = _FP13;
        v217 = (float)((float)v4 + (float)1.0) * v217;
      }
      LODWORD(v95) = v205;
      *(_BYTE *)(v84 + 92) = 1;
      v206 = v95;
      _FP9 = (float)((float)((float)_FP0 - (float)_FP11) - (float)((float)_FP13 - (float)_FP12));
      __asm { fsel      f26, f9, f12, f13 }
      v128 = (float)((float)_FP26 / (float)v95);
      memset(Dst: (void *)(v84 + 28), Val: 0, Size: 0x40u);
      *(float *)(v84 + 88) = 1.0;
      *(float *)(v84 + 68) = (float)-1.0 / (float)v2;
      *(float *)(v84 + 48) = (float)2.0 / (float)v128;
      *(float *)(v84 + 28) = (float)2.0 / (float)v128;
      v129 = (float)((float)((float)(v212 + v215) * (float)0.5) - (float)((float)_FP26 * (float)0.5));
      v130 = (float)((float)((float)_FP26 * (float)0.5) + (float)((float)(v216 + v213) * (float)0.5));
      v131 = v79->GetName(this: v79);
      idStr::idStr(this: v244, text: v131);
      if ( v230.len == 0 )
        idStr::ExtractFileName(this: v244, dest: &v230);
      v132 = 0;
      if ( v205 > 0 )
      {
        HIDWORD(v133) = &off_82040000;
        v134 = (float *)(v84 + 96);
        v135 = v204 & 0xFFFFFFFC;
        do
        {
          LODWORD(v133) = v132;
          v136 = 0;
          v232 = v133;
          v137 = (float)((float)((float)((float)v133 + (float)0.5) * (float)v128) + (float)v129);
          do
          {
            v243.allocedAndFlag = 20;
            v243.len = 0;
            v243.data = v243.baseBuffer;
            v243.baseBuffer[0] = 0;
            idStr::Format(this: &v243, fmt: "%s/%s_%d_%d.tga", v234.data, v230.data, v136, v132);
            *v134 = 0.0;
            *(float *)(v84 + 100) = 0.0;
            *(float *)(v84 + 104) = 100000.0;
            *(_BYTE *)(v84 + 9) = 1;
            *(_BYTE *)(v84 + 8) = 1;
            HIDWORD(v206) = v243.data;
            v229 = 4 * v135 * v77;
            v138 = (char *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                             size: v229,
                             tag: TAG_TEMP,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
            v228 = v138;
            idRenderSystemLocal::TakeScreenshotToBuffer(
              this: &tr,
              width: v135,
              height: v77,
              world: v79,
              guiList: nullptr,
              numGuis: 0,
              blends: v220,
              outBuffer: (unsigned __int8 *)v138,
              primes: v164,
              fillAlphaWith255: v166,
              skipPostProcessing: v168,
              a12: v170,
              a13: SHIDWORD(v172),
              a14: SLODWORD(v172),
              a15: SHIDWORD(v175),
              a16: SLODWORD(v175),
              a17: SHIDWORD(v178),
              a18: SLODWORD(v178),
              a19: SHIDWORD(v181),
              a20: SLODWORD(v181),
              a21: v184,
              a22: v186,
              a23: v188,
              a24: v190,
              a25: v192,
              a26: v194,
              a27: v196,
              a28: 3,
              a29: v198,
              a30: 1u,
              a31: v200,
              a32: 0);
            R_WriteTGA(
              filename: (const char *)HIDWORD(v206),
              data: v138,
              width: v135,
              height: v204,
              depth: 4,
              flipVertical: true,
              swapRGB: true,
              basePath: v218);
            if ( v138 != nullptr )
              idMem::Free(this: &mem, ptr: v138, align: ALIGN_16);
            LODWORD(v139) = v136;
            *v134 = v137;
            *(float *)(v84 + 104) = 0.0;
            HIDWORD(v139) = v135 * v204;
            *(_QWORD *)&v231.x = v139;
            v207.num = 4 * v135 * v204;
            *(float *)(v84 + 100) = -(float)((float)((float)((float)v139 + (float)0.5) * (float)v128) - (float)v130);
            *(_BYTE *)(v84 + 9) = 1;
            *(_BYTE *)(v84 + 8) = 1;
            HIDWORD(v206) = v243.data;
            v140 = (int *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                            size: 4 * v135 * v204,
                            tag: TAG_TEMP,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
            v207.list = v140;
            idRenderSystemLocal::TakeScreenshotToBuffer(
              this: &tr,
              width: v135,
              height: v204,
              world: v79,
              guiList: nullptr,
              numGuis: 0,
              blends: v220,
              outBuffer: (unsigned __int8 *)v140,
              primes: v165,
              fillAlphaWith255: v167,
              skipPostProcessing: v169,
              a12: v171,
              a13: v173,
              a14: v174,
              a15: v176,
              a16: v177,
              a17: v179,
              a18: v180,
              a19: v182,
              a20: v183,
              a21: v185,
              a22: v187,
              a23: v189,
              a24: v191,
              a25: v193,
              a26: v195,
              a27: v197,
              a28: 3,
              a29: v199,
              a30: 1u,
              a31: v201,
              a32: 0);
            v77 = v204;
            R_WriteTGA(
              filename: (const char *)HIDWORD(v206),
              data: (char *)v140,
              width: v135,
              height: v204,
              depth: 4,
              flipVertical: true,
              swapRGB: true,
              basePath: v218);
            if ( v140 != nullptr )
              idMem::Free(this: &mem, ptr: v140, align: ALIGN_16);
            idStr::FreeData(this: &v243);
            ++v136;
          }
          while ( v136 < v205 );
          ++v132;
        }
        while ( v132 < v205 );
      }
      v242.allocedAndFlag = 20;
      v141 = v205 * v204;
      v242.len = 0;
      v242.baseBuffer[0] = 0;
      *(_DWORD *)v235 = 512;
      *(_DWORD *)&v235[4] = 0;
      v235[8] = 0;
      v238 = 0x2000;
      HIDWORD(v206) = v205 * v204;
      *(_DWORD *)&v235[9] = (unsigned __int8)(v205 * v204);
      v142 = 0;
      v236 = v205 * v204;
      v237 = (unsigned __int16)(v205 * v204) >> 8;
      v242.data = v242.baseBuffer;
      idStr::Format(this: &v242, fmt: "%s/%s.tga", v234.data, v230.data);
      v143 = fileSystem->OpenFileWrite(this: fileSystem, a2: v242.data, a3: v218);
      v144 = v143;
      HIDWORD(v232) = v143;
      if ( v143 != nullptr )
      {
        v143->Write(this: v143, a2: v235, a3: 18u);
        *(_WORD *)&v207.memTag = 1280;
        memset(&v207, 0, 14);
        HIDWORD(v206) = 0;
        idList<idRenderModelCommitted *,5>::SetNum(this: &v207, newNum: v205, initValue: (const int *)&v206);
        v145 = 4 * v204;
        v146 = idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                 size: 4 * v204,
                 tag: TAG_NEW,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
        list = v207.list;
        v148 = v205 - 1;
        v149 = v146;
        while ( v148 >= 0 )
        {
          v150 = 0;
          if ( v205 > 0 )
          {
            v151 = list - 1;
            while ( 1 )
            {
              v241.len = 0;
              v241.baseBuffer[0] = 0;
              v241.data = v241.baseBuffer;
              v241.allocedAndFlag = 20;
              idStr::Format(this: &v241, fmt: "%s/%s_%d_%d.tga", v234.data, v230.data, v148, v150);
              v152 = fileSystem->OpenFileRead(this: fileSystem, a2: v241.data, a3: 1, a4: 0);
              v153 = v152;
              if ( v152 == nullptr )
                break;
              v152->Seek(this: v152, a2: 18, a3: FS_SEEK_SET);
              *++v151 = (int)v153;
              idStr::FreeData(this: &v241);
              if ( ++v150 >= v205 )
                goto LABEL_190;
            }
            idLib::Warning(fmt: "Unable to read from %s", v241.data);
            v142 = 1;
            idStr::FreeData(this: &v241);
            if ( v150 < v205 )
              break;
          }
LABEL_190:
          if ( v204 > 0 )
          {
            for ( i = v204; i != 0; --i )
            {
              if ( v205 > 0 )
              {
                v155 = v205;
                v156 = list - 1;
                do
                {
                  ++v156;
                  (*(void (__fastcall **)(int, void *, int))(*(_DWORD *)*v156 + 12))(a1: *v156, a2: v149, a3: v145);
                  v144->Write(this: v144, a2: v149, a3: v145);
                  --v155;
                }
                while ( v155 != 0 );
              }
            }
          }
          v157 = v205;
          if ( v205 > 0 )
          {
            v158 = list;
            do
            {
              if ( *v158 != 0 )
                (**(void (__fastcall ***)(int, int))*v158)(a1: *v158, a2: 1);
              --v157;
              ++v158;
            }
            while ( v157 != 0 );
          }
          --v148;
        }
        idMem::Free(this: &mem, ptr: v149, align: ALIGN_16);
        if ( (v207.listStatic == 0 || v207.listStatic == 2) && list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      }
      else
      {
        idLib::Warning(fmt: "Unable to write to %s", v242.data);
        v142 = 1;
      }
      idCVar::SetBool(this: v225, newValue: v211, force: true);
      idCVar::SetBool(this: v223, newValue: v210, force: true);
      idCVar::SetBool(this: v221, newValue: v209, force: true);
      idCVar::SetBool(this: v219, newValue: v208, force: true);
      idCVar::SetInteger(this: v226, newValue: (const int)valueInteger, force: true);
      *(float *)&v207.granularity = v87;
      *(float *)&v207.size = v87;
      *(float *)&v207.num = v87;
      *(float *)&v207.list = v87;
      idParmBlock::SetParm(
        this: v85,
        parm: *((const idDeclRenderParm **)v227 + 2),
        parmValue: (const parmValue_t *)&v207);
      *(float *)&v207.granularity = v90;
      *(float *)&v207.size = v90;
      *(float *)&v207.num = v90;
      *(float *)&v207.list = v90;
      idParmBlock::SetParm(this: v85, parm: (const idDeclRenderParm *)v224, parmValue: (const parmValue_t *)&v207);
      v159 = v79->skyModel;
      if ( v159 != nullptr )
        idRenderModel::CommitThisFrame(this: v159);
      if ( v142 != 0 )
      {
        idLib::Warning(fmt: "GenerateOrthoMap failed. See error messages above.");
      }
      else
      {
        v160 = v79->GetName(this: v79);
        idLib::Printf(fmt: "Wrote minimap for %s\n", v160);
        idLib::Printf(fmt: "minimapInfo = {\n");
        idLib::Printf(fmt: "\thasMinimap = true;\n");
        idLib::Printf(fmt: "\tminimapPrefix = \"%s\";\n", v230.data);
        idLib::Printf(fmt: "\tminimapWidth = %d;\n", v141);
        idLib::Printf(fmt: "\tminimapHeight = %d;\n", v141);
        idLib::Printf(fmt: "\tworldLeftBound = %f;\n", v129);
        idLib::Printf(
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v129 + (float)_FP26))),
          (unsigned int)COERCE_UNSIGNED_INT64((float)((float)v129 + (float)_FP26)));
        idLib::Printf(fmt: "\tworldTopBound = %f;\n", (float)((float)v130 - (float)_FP26));
        idLib::Printf(fmt: "\tworldBottomBound = %f;\n", v130);
        idLib::Printf(fmt: "\tmapRows = %d;\n", v205);
        idLib::Printf(fmt: "\tmapCols = %d;\n", v205);
        idLib::Printf(fmt: "\tblockSize = %d;\n", v204);
        idLib::Printf(fmt: "\tmapImages = {\n");
        idLib::Printf(fmt: "\t\tnum = %d;\n", v205 * v205);
        v161 = 0;
        if ( v205 > 0 )
        {
          v162 = 0;
          do
          {
            for ( j = 0; j < v205; ++j )
              idLib::Printf(
                fmt: "\t\titem[%d] = \"textures/guis/minimap/%s_%d_%d.tga\";\n",
                v162 + j,
                v230.data,
                v161,
                j);
            ++v161;
            v162 += v205;
          }
          while ( v161 < v205 );
        }
        idLib::Printf(fmt: "\t}\n");
        idLib::Printf(fmt: "}\n");
      }
      if ( v144 != nullptr )
        ((void (__fastcall *)(idFile *, int))v144->dtr_idFile)(a1: v144, a2: 1);
      idStr::FreeData(this: &v242);
      idStr::FreeData(this: v244);
      idStr::FreeData(this: &v234);
    }
    else
    {
      idStr::FreeData(this: &v234);
    }
  }
LABEL_221:
  idStr::FreeData(this: &v230);
}


// ========================================================================
// __unwind$238291
// EA  : 0x82951B58
// RVA : 0x00951B58
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_238291()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 848 + 256));
}


// ========================================================================
// __unwind$238292
// EA  : 0x82951B80
// RVA : 0x00951B80
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_238292()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 848 + 352));
}


// ========================================================================
// __unwind$238293
// EA  : 0x82951BA8
// RVA : 0x00951BA8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_238293()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 848 + 576));
}


// ========================================================================
// __unwind$238294_0
// EA  : 0x82951BD0
// RVA : 0x00951BD0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_238294_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 848 + 544));
}


// ========================================================================
// __unwind$239560
// EA  : 0x82951BF8
// RVA : 0x00951BF8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_239560()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 848 + 240));
}


// ========================================================================
// __unwind$239628
// EA  : 0x82951C20
// RVA : 0x00951C20
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_239628()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 848 + 144));
}


// ========================================================================
// __unwind$238295
// EA  : 0x82951C48
// RVA : 0x00951C48
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_238295()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 848 + 512));
}


// ========================================================================
// __unwind$238296
// EA  : 0x82951C70
// RVA : 0x00951C70
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_238296()
{
  int v0; // r12

  idLoadScreen::Shutdown(this: (idLoadScreen *)(v0 - 848 + 304));
}


// ========================================================================
// __unwind$238297
// EA  : 0x82951C98
// RVA : 0x00951C98
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_238297()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 848 + 144));
}


// ========================================================================
// __unwind$238298
// EA  : 0x82951CC0
// RVA : 0x00951CC0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_238298()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 848 + 480));
}


// ========================================================================
// ?filmStripper_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82951DB0
// RVA : 0x00951DB0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall filmStripper_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v3; // r4
  const char *v4; // r4
  idFileList *v5; // r17
  int v6; // r26
  int v7; // r30
  char *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r6
  __int64 v11; // r8
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  va *v16; // r3
  va *v17; // r3
  va *v18; // r3
  int num; // r30
  encounterGroupRole_t *v20; // r27
  void **v21; // r29
  const char *v22; // r3
  signed int v23; // r3
  signed int v24; // r11
  int v25; // r22
  int v26; // r10
  int v27; // r30
  int v28; // r20
  void *v29; // r28
  encounterGroupRole_t *list; // r16
  int v31; // r24
  int v32; // r25
  int v33; // r23
  int v34; // r29
  int v35; // r3
  encounterGroupRole_t v36; // r5
  int v37; // r7
  int v38; // r8
  int i; // r4
  int v40; // r11
  int j; // ctr
  int v42; // r15
  int v43; // r10
  int v44; // r30
  void **v45; // r29
  idStr *v46; // r28
  int size; // r30
  idStr *v48; // r29
  int v49; // [sp+8h] [-1138h]
  int v50; // [sp+Ch] [-1134h]
  int v51; // [sp+10h] [-1130h]
  int v52; // [sp+14h] [-112Ch]
  int v53; // [sp+18h] [-1128h]
  int v54; // [sp+1Ch] [-1124h]
  idFileList *v55; // [sp+50h] [-10F0h] BYREF
  unsigned __int8 *v56; // [sp+54h] [-10ECh] BYREF
  int v57; // [sp+58h] [-10E8h] BYREF
  int v58; // [sp+5Ch] [-10E4h] BYREF
  idStr v59; // [sp+60h] [-10E0h] BYREF
  idList<enum encounterGroupRole_t,5> v60; // [sp+80h] [-10C0h] BYREF
  idStr v61; // [sp+90h] [-10B0h] BYREF
  va v62; // [sp+B0h] [-1090h] BYREF

  argc = args->argc;
  v56 = (unsigned __int8 *)args->argc;
  if ( v56 != (unsigned __int8 *)3 )
  {
    idLib::Printf(fmt: "usage: filmStripper [input directory] [columns]\n");
    return;
  }
  if ( argc <= 1 )
    v3 = &byte_8200D768;
  else
    v3 = args->argv[1];
  idStr::idStr(this: &v61, text: v3);
  idStr::Append(this: &v61, text: "/output.tga");
  fileSystem->RemoveFile(this: fileSystem, a2: v61.data, a3: FSPATH_BASE);
  if ( args->argc <= 1 )
    v4 = &byte_8200D768;
  else
    v4 = args->argv[1];
  v5 = fileSystem->ListFiles(this: fileSystem, a2: v4, a3: "tga", a4: 1, a5: 0);
  if ( v5->list.num == 0 )
  {
    idLib::Printf(fmt: "error: no files were found in that directory...\n");
    fileSystem->FreeFileList(this: fileSystem, a2: v5);
    goto LABEL_66;
  }
  idList<unsigned char *,87>::idList<unsigned char *,87>(this: (idList<unsigned char *,87> *)&v60);
  v6 = 0;
  v7 = 0;
  if ( v5->list.num <= 0 )
    goto LABEL_23;
  while ( 1 )
  {
    v8 = idCmdArgs::Argv(this: args, arg: 1);
    idStr::idStr(this: &v59, text: v8);
    idStr::EnsureAlloced(this: &v59, amount: v59.len + 2, keepold: true, geometricGrowth: true);
    v9 = __PAIR64__((unsigned int)v59.data, v59.len);
    HIDWORD(v10) = v7;
    v59.data[v59.len] = 47;
    v11 = *(_QWORD *)&v59.len;
    v59.data[++v59.len] = 0;
    v12 = va::va(
            this: &v62,
            fmt: "%d",
            a3: v10,
            a4: v11,
            a5: v9,
            a6: v49,
            a7: v50,
            a8: v51,
            a9: v52,
            a10: v53,
            a11: v54);
    idStr::Append(this: &v59, text: v12);
    R_LoadImage(cname: v59.data, pic: &v56, width: &v57, height: &v58, timestamp: (unsigned int *)&v55);
    if ( v57 == 0 )
    {
      HIDWORD(v15) = v59.data;
      v16 = va::va(
              this: &v62,
              fmt: "error: invalid image '%s'",
              a3: v15,
              a4: v14,
              a5: v13,
              a6: v49,
              a7: v50,
              a8: v51,
              a9: v52,
              a10: v53,
              a11: v54);
      idLib::Printf(fmt: v16->buffer);
      goto _M240553;
    }
    LODWORD(v13) = v58;
    if ( v57 != v58 )
    {
      v17 = va::va(
              this: &v62,
              fmt: "error: only square textures are supported",
              a3: v15,
              a4: v14,
              a5: v13,
              a6: v49,
              a7: v50,
              a8: v51,
              a9: v52,
              a10: v53,
              a11: v54);
      idLib::Printf(fmt: v17->buffer);
      goto _M240553;
    }
    if ( v6 != 0 )
      break;
    v6 = v57;
LABEL_17:
    idList<idAnimWebBlendTree *,5>::Append(this: &v60, obj: (const encounterGroupRole_t *)&v56);
    idStr::FreeData(this: &v59);
    if ( ++v7 >= v5->list.num )
      goto LABEL_23;
  }
  if ( v6 == v57 )
    goto LABEL_17;
  v18 = va::va(
          this: &v62,
          fmt: "error: image sizes don't match",
          a3: v15,
          a4: v14,
          a5: v13,
          a6: v49,
          a7: v50,
          a8: v51,
          a9: v52,
          a10: v53,
          a11: v54);
  idLib::Printf(fmt: v18->buffer);
_M240553:
  idStr::FreeData(this: &v59);
LABEL_23:
  num = v60.num;
  if ( v60.num == v5->list.num )
  {
    if ( args->argc <= 2 )
      v22 = &byte_8200D768;
    else
      v22 = args->argv[2];
    v23 = atol(nptr: v22);
    v24 = v5->list.num;
    v25 = v23;
    if ( v23 >= v24 )
      v25 = v5->list.num;
    v55 = (idFileList *)v5->list.num;
    __twllei(v23, 0);
    v26 = v24 + v23 - 1;
    v27 = v26 / v23;
    __twlgei(v23 & ~(__ROL4__(v26, 1) - 1), 0xFFFFFFFF);
    if ( v26 / v23 < 1 )
      v27 = 1;
    v28 = v27 * v6;
    v29 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
            size: 4 * v27 * v6 * v25 * v6,
            tag: TAG_NEW,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    memset(Dst: v29, Val: 0, Size: 4 * v27 * v6 * v25 * v6);
    list = v60.list;
    v31 = 0;
    if ( v27 > 0 )
    {
      v32 = 0;
      v33 = 0;
      do
      {
        v34 = 0;
        if ( v25 > 0 )
        {
          v35 = 0;
          do
          {
            if ( v31 >= v5->list.num )
              break;
            v36 = list[v33 + v34];
            if ( v6 > 0 )
            {
              v37 = 0;
              v38 = 0;
              for ( i = v6; i != 0; --i )
              {
                v40 = 0;
                for ( j = v6; j != 0; --j )
                {
                  v42 = 4 * (v38 + v40);
                  v43 = v32 + v35 + v37 + v40++;
                  *((_DWORD *)v29 + v43) = *(_DWORD *)(v42 + v36);
                }
                v38 += v6;
                v37 += v25 * v6;
              }
            }
            ++v34;
            v35 += v6;
            ++v31;
          }
          while ( v34 < v25 );
        }
        --v27;
        v33 += v25;
        v32 += v25 * v6 * v6;
      }
      while ( v27 != 0 );
    }
    R_WriteTGA(
      filename: v61.data,
      data: (char *)v29,
      width: v25 * v6,
      height: v28,
      depth: 4,
      flipVertical: false,
      swapRGB: true,
      basePath: FSPATH_BASE);
    v44 = 0;
    if ( v5->list.num > 0 )
    {
      v45 = (void **)(list - 1);
      do
      {
        idMem::Free(this: &mem, ptr: *++v45, align: ALIGN_16);
        ++v44;
      }
      while ( v44 < v5->list.num );
    }
    idMem::Free(this: &mem, ptr: v29, align: ALIGN_16);
    v55 = v5;
    if ( v5->list.listStatic == 0 || v5->list.listStatic == 2 )
    {
      v46 = v5->list.list;
      if ( v46 != nullptr )
      {
        size = v5->list.size;
        if ( size > 0 )
        {
          v48 = v5->list.list;
          do
          {
            idStr::FreeData(this: v48);
            --size;
            ++v48;
          }
          while ( size != 0 );
        }
        idMem::Free(this: &mem, ptr: v46, align: ALIGN_16);
      }
      v5->list.list = nullptr;
      v5->list.size = 0;
    }
    v5->list.num = 0;
    idStr::FreeData(this: &v5->basePath);
    idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    if ( (v60.listStatic == 0 || v60.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
  else
  {
    v20 = v60.list;
    if ( v60.num > 0 )
    {
      v21 = (void **)(v60.list - 1);
      do
      {
        idMem::Free(this: &mem, ptr: *++v21, align: ALIGN_16);
        --num;
      }
      while ( num != 0 );
    }
    if ( (v60.listStatic == 0 || v60.listStatic == 2) && v20 != nullptr )
      idMem::Free(this: &mem, ptr: v20, align: ALIGN_16);
  }
LABEL_66:
  idStr::FreeData(this: &v61);
}


// ========================================================================
// __unwind$240102
// EA  : 0x82952300
// RVA : 0x00952300
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_240102()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4416 + 144));
}


// ========================================================================
// __unwind$240103
// EA  : 0x82952328
// RVA : 0x00952328
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_240103()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4416 + 128));
}


// ========================================================================
// __unwind$240104
// EA  : 0x82952350
// RVA : 0x00952350
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_240104()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4416 + 96));
}


// ========================================================================
// __unwind$240344
// EA  : 0x82952378
// RVA : 0x00952378
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _unwind_240344()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4416 + 80));
}


// ========================================================================
// ?TestWorld_f@idRenderSystemLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82952410
// RVA : 0x00952410
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::TestWorld_f(const idCmdArgs *args)
{
  idRenderWorldLocal *primaryWorld; // r11
  int v2; // r30
  const char *v3; // r3
  idRenderWorldLocal *v4; // r11
  int v5; // r8
  int v6; // r9
  int v7; // r11
  dynamicEnvironment_t *v8; // r10
  const idDeclEnv *v9; // r7
  double v10; // fp13
  int v11; // r27
  int v12; // r28
  idRenderModel *v13; // r30
  idRenderModel *v14; // r29
  int v15; // r27
  int v16; // r28
  idRenderLight *v17; // r29
  idRenderLight *v18; // r30

  primaryWorld = tr.primaryWorld;
  if ( tr.primaryWorld != nullptr )
  {
    if ( tr.testWorld != nullptr )
    {
      ((void (__fastcall *)(idRenderWorldLocal *, int))tr.testWorld->dtr_idRenderWorld)(a1: tr.testWorld, a2: 1);
      primaryWorld = tr.primaryWorld;
    }
    v2 = ((int (__fastcall *)(idRenderWorldLocal *))primaryWorld->IsComboMap)(a1: primaryWorld);
    v3 = tr.primaryWorld->GetName(this: tr.primaryWorld);
    tr.testWorld = idRenderSystemLocal::AllocRenderWorld(this: &tr, mapName: v3, comboMap: v2);
    tr.testWorld->specificationCompleteHasBeenCalled = true;
    idList<dynamicEnvironment_t,5>::SetNum(
      this: &tr.testWorld->dynamicEnvironments,
      newNum: tr.primaryWorld->dynamicEnvironments.num);
    v4 = tr.primaryWorld;
    v5 = 0;
    if ( tr.primaryWorld->dynamicEnvironments.num > 0 )
    {
      v6 = 0;
      do
      {
        ++v5;
        v7 = (int)&v4->dynamicEnvironments.list[v6];
        v8 = &tr.testWorld->dynamicEnvironments.list[v6];
        v9 = *(const idDeclEnv **)(v7 + 24);
        ++v6;
        v8->bounds.b[0].x = *(float *)v7;
        v10 = *(float *)(v7 + 4);
        v8->env = v9;
        v8->bounds.b[0].y = v10;
        v8->bounds.b[0].z = *(float *)(v7 + 8);
        v8->bounds.b[1].x = *(float *)(v7 + 12);
        v8->bounds.b[1].y = *(float *)(v7 + 16);
        v8->bounds.b[1].z = *(float *)(v7 + 20);
        v4 = tr.primaryWorld;
      }
      while ( v5 < tr.primaryWorld->dynamicEnvironments.num );
    }
    v11 = 0;
    if ( v4->renderModels.num > 0 )
    {
      v12 = 0;
      do
      {
        v13 = v4->renderModels.list[v12];
        if ( v13 != nullptr && !v13->unlinked )
        {
          if ( _RTDynamicCast(
                 inptr: v13,
                 VfDelta: 0,
                 SrcType: &idRenderModel `RTTI Type Descriptor',
                 TargetType: &idRenderModelStatic `RTTI Type Descriptor',
                 isReference: 0) != nullptr )
          {
            v14 = tr.testWorld->AllocRenderModel(this: tr.testWorld, a2: v13->name.str, a3: 1, a4: -1);
            idStaticParmBlock<32>::operator=(this: &v14->gameParmBlock, __that: &v13->gameParmBlock);
            idRenderModelParms::operator=(this: &v14->g, __that: &v13->g);
            if ( (*((_BYTE *)&v13->g + 104) & 0x20) != 0 )
              *((_BYTE *)&v14->g + 104) |= 0x20u;
            idRenderModel::CommitThisFrame(this: v14);
          }
          v4 = tr.primaryWorld;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < v4->renderModels.num );
    }
    v15 = 0;
    if ( v4->renderLights.num > 0 )
    {
      v16 = 0;
      do
      {
        v17 = v4->renderLights.list[v16];
        if ( v17 != nullptr && !v17->unlinked )
        {
          v18 = tr.testWorld->AllocRenderLight(this: tr.testWorld, a2: 0);
          idStaticParmBlock<32>::operator=(this: &v18->gameParmBlock, __that: &v17->gameParmBlock);
          idRenderLightParms::operator=(this: &v18->g, __that: &v17->g);
          idRenderLight::CommitThisFrame(this: v18);
          v4 = tr.primaryWorld;
        }
        ++v15;
        ++v16;
      }
      while ( v15 < v4->renderLights.num );
    }
    idLib::Printf(fmt: "world duplicated, set r_testWorld 1 to view it.\n");
  }
  else
  {
    idLib::Printf(fmt: "No primaryWorld.\n");
  }
}


// ========================================================================
// ?InitCommands@idRenderSystemLocal@@QAAXXZ
// EA  : 0x829526B8
// RVA : 0x009526B8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::InitCommands(idRenderSystemLocal *this)
{
  cmdSystem->AddCommand(this: cmdSystem, a2: "screenshot", a3: R_ScreenShot_f, a4: "takes a screenshot", a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "envshot", a3: R_EnvShot_f, a4: "takes an environment shot", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "testImage",
    a3: R_TestImage_f,
    a4: "displays the given image centered on screen",
    a5: ArgCompletion_ImageName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listRenderModels",
    a3: idRenderWorldLocal::ListRenderModels_f,
    a4: "lists the renderModels",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listRenderLights",
    a3: idRenderWorldLocal::ListRenderLights_f,
    a4: "lists the renderLights",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "reloadSurface",
    a3: R_ReloadSurface_f,
    a4: "reloads the decl and images for selected surface",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "renameRenderProg",
    a3: R_RenameRenderProg_f,
    a4: "temporarily replace a renderProg with a different one",
    a5: idDeclManager::ArgCompletion_Decl<idDeclRenderProg>);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "rp",
    a3: R_RP_f,
    a4: "Displays or modifies a renderparm",
    a5: idDeclManager::ArgCompletion_Decl<idDeclRenderParm>);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "testWorld",
    a3: idRenderSystemLocal::TestWorld_f,
    a4: "copies current world to the testWorld",
    a5: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestCubeImage_v''
// EA  : 0x8335D558
// RVA : 0x0135D558
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestCubeImage_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestCubeImage_v,
           cmdName: "TestCubeImage",
           function: TestCubeImage_f,
           description: "displays the given cube image mapped to a sphere",
           argCompletion: ArgCompletion_ImageName);
}


// ========================================================================
// `dynamic initializer for 'TestMaterial_v''
// EA  : 0x8335D588
// RVA : 0x0135D588
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestMaterial_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestMaterial_v,
           cmdName: "TestMaterial",
           function: TestMaterial_f,
           description: "displays the given material centered on screen",
           argCompletion: idDeclManager::ArgCompletion_Decl<idMaterial>);
}


// ========================================================================
// `dynamic initializer for 'TestVMTR_v''
// EA  : 0x8335D5B8
// RVA : 0x0135D5B8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestVMTR_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestVMTR_v,
           cmdName: "TestVMTR",
           function: TestVMTR_f,
           description: "displays the given vmtr centered on the screen",
           argCompletion: idDeclManager::ArgCompletion_Decl<idMaterial>);
}


// ========================================================================
// `dynamic initializer for 'filmStripper_v''
// EA  : 0x8335D5E8
// RVA : 0x0135D5E8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__filmStripper_v__()
{
  return idCommandLink::idCommandLink(
           this: &filmStripper_v,
           cmdName: "filmStripper",
           function: filmStripper_f,
           description: "generate a texture film strip from all the textures in a specified directory",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'cbShowOverlay''
// EA  : 0x8335D610
// RVA : 0x0135D610
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

void _dynamic_initializer_for__cbShowOverlay__()
{
  cbShowOverlay.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&cbShowOverlay;
}


// ========================================================================
// `dynamic initializer for 'MegaScreenShot_v''
// EA  : 0x8335D630
// RVA : 0x0135D630
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MegaScreenShot_v__()
{
  return idCommandLink::idCommandLink(
           this: &MegaScreenShot_v,
           cmdName: "MegaScreenShot",
           function: MegaScreenShot_f,
           description: "take a mega-screenshot",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'GenerateOrthoMap_v''
// EA  : 0x8335D658
// RVA : 0x0135D658
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__GenerateOrthoMap_v__()
{
  return idCommandLink::idCommandLink(
           this: &GenerateOrthoMap_v,
           cmdName: "GenerateOrthoMap",
           function: GenerateOrthoMap_f,
           description: "creates high-res map images of the current map",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'MakeAmbientMap_v''
// EA  : 0x8335D680
// RVA : 0x0135D680
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MakeAmbientMap_v__()
{
  return idCommandLink::idCommandLink(
           this: &MakeAmbientMap_v,
           cmdName: "MakeAmbientMap",
           function: MakeAmbientMap_f,
           description: "makes an ambient map",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'GfxInfo_v''
// EA  : 0x8335D6A8
// RVA : 0x0135D6A8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__GfxInfo_v__()
{
  return idCommandLink::idCommandLink(
           this: &GfxInfo_v,
           cmdName: "GfxInfo",
           function: (void (__fastcall *)(const idCmdArgs *))idPhysics_StaticMulti::UpdateTime,
           description: "show graphics info",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ReportWorldSurfaces_v''
// EA  : 0x8335D6D0
// RVA : 0x0135D6D0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ReportWorldSurfaces_v__()
{
  return idCommandLink::idCommandLink(
           this: &ReportWorldSurfaces_v,
           cmdName: "ReportWorldSurfaces",
           function: ReportWorldSurfaces_f,
           description: "Reports the total surface and parm count",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ShowTexLod_v''
// EA  : 0x8335D6F8
// RVA : 0x0135D6F8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ShowTexLod_v__()
{
  return idCommandLink::idCommandLink(
           this: &ShowTexLod_v,
           cmdName: "ShowTexLod",
           function: ShowTexLod_f,
           description: "Adds or removes the models generated by texLod for the current map",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'FindTriangleData_v''
// EA  : 0x8335D720
// RVA : 0x0135D720
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__FindTriangleData_v__()
{
  return idCommandLink::idCommandLink(
           this: &FindTriangleData_v,
           cmdName: "FindTriangleData",
           function: FindTriangleData_f,
           description: "Scans for models that still hold CPU side data",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestTransImageAtlas_v''
// EA  : 0x8335D748
// RVA : 0x0135D748
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestTransImageAtlas_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestTransImageAtlas_v,
           cmdName: "TestTransImageAtlas",
           function: TestTransImageAtlas_f,
           description: "image atlas tools",
           argCompletion: idCmdSystem::ArgCompletion_ImageName);
}


// ========================================================================
// `dynamic initializer for 'testEnv_v''
// EA  : 0x8335D778
// RVA : 0x0135D778
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testEnv_v__()
{
  return idCommandLink::idCommandLink(
           this: &testEnv_v,
           cmdName: "testEnv",
           function: testEnv_f,
           description: "overrides default dynamic environment processing with a specific declEnv",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclEnv>);
}


// ========================================================================
// `dynamic initializer for 'DrawCollision_v''
// EA  : 0x8335D7A8
// RVA : 0x0135D7A8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DrawCollision_v__()
{
  return idCommandLink::idCommandLink(
           this: &DrawCollision_v,
           cmdName: "DrawCollision",
           function: DrawCollision_f,
           description: "Visualize the collision model for the world",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DrawPlayerCollision_v''
// EA  : 0x8335D7D0
// RVA : 0x0135D7D0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DrawPlayerCollision_v__()
{
  return idCommandLink::idCommandLink(
           this: &DrawPlayerCollision_v,
           cmdName: "DrawPlayerCollision",
           function: (void (__fastcall *)(const idCmdArgs *))DrawPlayerCollision_f,
           description: "Visualize the player collision model for the world",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DrawPlayerClip_v''
// EA  : 0x8335D7F8
// RVA : 0x0135D7F8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DrawPlayerClip_v__()
{
  return idCommandLink::idCommandLink(
           this: &DrawPlayerClip_v,
           cmdName: "DrawPlayerClip",
           function: (void (__fastcall *)(const idCmdArgs *))DrawPlayerClip_f,
           description: "Visualize the player clip model for the world",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DrawMonsterCollision_v''
// EA  : 0x8335D820
// RVA : 0x0135D820
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DrawMonsterCollision_v__()
{
  return idCommandLink::idCommandLink(
           this: &DrawMonsterCollision_v,
           cmdName: "DrawMonsterCollision",
           function: (void (__fastcall *)(const idCmdArgs *))DrawMonsterCollision_f,
           description: "Visualize the monster collision model for the world",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DrawMonsterClip_v''
// EA  : 0x8335D848
// RVA : 0x0135D848
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DrawMonsterClip_v__()
{
  return idCommandLink::idCommandLink(
           this: &DrawMonsterClip_v,
           cmdName: "DrawMonsterClip",
           function: (void (__fastcall *)(const idCmdArgs *))DrawMonsterClip_f,
           description: "Visualize the monster clip model for the world",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DrawShotIKClip_v''
// EA  : 0x8335D870
// RVA : 0x0135D870
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DrawShotIKClip_v__()
{
  return idCommandLink::idCommandLink(
           this: &DrawShotIKClip_v,
           cmdName: "DrawShotIKClip",
           function: (void (__fastcall *)(const idCmdArgs *))DrawShotIKClip_f,
           description: "Visualize the ShotIK clip model for the world",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DrawShotIKCollision_v''
// EA  : 0x8335D898
// RVA : 0x0135D898
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DrawShotIKCollision_v__()
{
  return idCommandLink::idCommandLink(
           this: &DrawShotIKCollision_v,
           cmdName: "DrawShotIKCollision",
           function: (void (__fastcall *)(const idCmdArgs *))DrawShotIKCollision_f,
           description: "Visualize the ShotIK collision model for the world",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DrawVehicleCollision_v''
// EA  : 0x8335D8C0
// RVA : 0x0135D8C0
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DrawVehicleCollision_v__()
{
  return idCommandLink::idCommandLink(
           this: &DrawVehicleCollision_v,
           cmdName: "DrawVehicleCollision",
           function: (void (__fastcall *)(const idCmdArgs *))DrawVehicleCollision_f,
           description: "Visualize the vehicle collision model for the world",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DrawVehicleClip_v''
// EA  : 0x8335D8E8
// RVA : 0x0135D8E8
// PDB : w:\tech5\engine\renderer\rendersystem_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DrawVehicleClip_v__()
{
  return idCommandLink::idCommandLink(
           this: &DrawVehicleClip_v,
           cmdName: "DrawVehicleClip",
           function: (void (__fastcall *)(const idCmdArgs *))DrawVehicleClip_f,
           description: "Visualize the vehicle clip model for the world",
           argCompletion: nullptr);
}

