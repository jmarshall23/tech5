
// ========================================================================
// ?SwapVertexBuffer@@YAHPAXHH@Z
// EA  : 0x82977028
// RVA : 0x00977028
// PDB : w:\tech5\engine\renderer\triverts.cpp
// ========================================================================

int __fastcall SwapVertexBuffer(char *buf, int numVerts, __int16 vertexMask)
{
  char *v3; // r11
  int i; // ctr

  v3 = buf;
  if ( numVerts > 0 )
  {
    for ( i = numVerts; i != 0; --i )
    {
      if ( (vertexMask & 0x20) != 0 )
      {
        v3 += 8;
      }
      else if ( (vertexMask & 1) != 0 )
      {
        v3 += 12;
      }
      if ( (vertexMask & 0x1000) != 0 )
        v3 += 12;
      if ( (vertexMask & 0x40) != 0 )
      {
        v3 += 4;
      }
      else if ( (vertexMask & 2) != 0 )
      {
        v3 += 8;
      }
      if ( (vertexMask & 0x800) != 0 )
      {
        v3 += 4;
      }
      else if ( (vertexMask & 0x400) != 0 )
      {
        v3 += 8;
      }
      if ( (vertexMask & 4) != 0 )
        v3 += 4;
      if ( (vertexMask & 0x10) != 0 )
        v3 += 4;
      if ( (vertexMask & 8) != 0 )
        v3 += 4;
    }
  }
  return v3 - buf;
}


// ========================================================================
// ?PackToVertexFormat@@YAXPBVidDrawVert@@PAXHH@Z
// EA  : 0x82977100
// RVA : 0x00977100
// PDB : w:\tech5\engine\renderer\triverts.cpp
// ========================================================================

void __fastcall PackToVertexFormat(const idDrawVert *dv, _WORD *packed, int numVerts, char vertexMask)
{
  const idDrawVert *v6; // r30
  int v7; // r21
  int v8; // r26
  int v9; // r25
  int v10; // r24
  int v11; // r23
  float *p_z; // r29
  int i; // r27
  int v14; // r11
  int v15; // r11
  int v16; // r11
  int v17; // r11
  int v18; // r11
  char *v19; // r11
  char *v20; // r10
  int j; // ctr

  v6 = dv;
  if ( numVerts > 0 )
  {
    v7 = vertexMask & 1;
    v8 = vertexMask & 2;
    v9 = vertexMask & 4;
    v10 = vertexMask & 0x10;
    v11 = vertexMask & 8;
    p_z = &dv->xyz.z;
    for ( i = numVerts; i != 0; --i )
    {
      if ( v7 != 0 )
      {
        if ( (vertexMask & 0x20) != 0 )
        {
          v14 = (int)*(p_z - 2);
          if ( v14 >= -32768 )
          {
            if ( v14 > 0x7FFF )
              LOWORD(v14) = 0x7FFF;
          }
          else
          {
            LOWORD(v14) = 0x8000;
          }
          *packed = v14;
          v15 = (int)*(p_z - 1);
          if ( v15 >= -32768 )
          {
            if ( v15 > 0x7FFF )
              LOWORD(v15) = 0x7FFF;
          }
          else
          {
            LOWORD(v15) = 0x8000;
          }
          packed[1] = v15;
          v16 = (int)*p_z;
          if ( v16 >= -32768 )
          {
            if ( v16 <= 0x7FFF )
              packed[2] = v16;
            else
              packed[2] = 0x7FFF;
            packed[3] = 1;
            packed += 4;
          }
          else
          {
            packed[2] = 0x8000;
            packed[3] = 1;
            packed += 4;
          }
        }
        else
        {
          memcpy(Dst: packed, Src: v6, Size: 0xCu);
          packed += 6;
        }
      }
      if ( v8 != 0 )
      {
        if ( (vertexMask & 0x40) != 0 )
        {
          v17 = (int)p_z[1];
          if ( v17 >= -32768 )
          {
            if ( v17 > 0x7FFF )
              LOWORD(v17) = 0x7FFF;
          }
          else
          {
            LOWORD(v17) = 0x8000;
          }
          *packed = v17;
          v18 = (int)p_z[2];
          if ( v18 >= -32768 )
          {
            if ( v18 <= 0x7FFF )
              packed[1] = v18;
            else
              packed[1] = 0x7FFF;
            packed += 2;
          }
          else
          {
            packed[1] = 0x8000;
            packed += 2;
          }
        }
        else
        {
          v19 = (char *)&v6->xyz.z + 3;
          v20 = (char *)packed - 1;
          for ( j = 8; j != 0; --j )
            *++v20 = *++v19;
          packed += 4;
        }
      }
      if ( v9 != 0 )
      {
        *(_BYTE *)packed = v6->normal[0];
        *((_BYTE *)packed + 1) = v6->normal[1];
        *((_BYTE *)packed + 2) = v6->normal[2];
        *((_BYTE *)packed + 3) = v6->normal[3];
        packed += 2;
      }
      if ( v10 != 0 )
      {
        *(_BYTE *)packed = v6->tangent[0];
        *((_BYTE *)packed + 1) = v6->tangent[1];
        *((_BYTE *)packed + 2) = v6->tangent[2];
        *((_BYTE *)packed + 3) = v6->tangent[3];
        packed += 2;
      }
      if ( v11 != 0 )
      {
        *(_BYTE *)packed = v6->color[0];
        *((_BYTE *)packed + 1) = v6->color[1];
        *((_BYTE *)packed + 2) = v6->color[2];
        *((_BYTE *)packed + 3) = v6->color[3];
        packed += 2;
      }
      ++v6;
      p_z += 8;
    }
  }
}


// ========================================================================
// ?TransferVerts@@YAXHHPBVidVertexScaleAndBias@@H_NPBXPAX@Z
// EA  : 0x829773A0
// RVA : 0x009773A0
// PDB : w:\tech5\engine\renderer\triverts.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall TransferVerts(
        __int16 inputMask,
        const int outputMask,
        __int64 vertexCount,
        const bool byteSwap,
        float *inputBuffer,
        float *outputBuffer,
        long double a7)
{
  int v7; // r2 OVERLAPPED
  __int16 v9; // r4
  __int16 v10; // r25
  float *v11; // r24
  int v12; // r14
  int v15; // r15
  int v16; // r16
  int v17; // r17
  int v18; // r21
  int v19; // r20
  char v20; // r4
  int v21; // r19
  int v22; // r18
  __int16 v23; // r9
  __int16 v24; // r8
  float v25; // r9
  float v26; // r8
  float v27; // r9
  float v28; // r8
  __int16 v29; // r9
  float v30; // r9
  __int16 v31; // r9
  double v32; // fp7
  double v33; // fp10
  double v34; // fp0
  int v35; // r3
  double v36; // fp13
  double v37; // fp12
  __int16 *v38; // r30
  float *v39; // r31
  int i; // r29
  __int16 v41; // r11
  double v42; // fp0
  double v43; // fp13
  int v44; // r7
  double v45; // fp12
  double v46; // fp11
  __int16 *v47; // r30
  float *v48; // r29
  float *v49; // r31
  int v50; // r28
  __int16 v51; // r11
  __int16 v52; // r9
  __int16 v53; // r8
  float v54; // r9
  float v55; // r8
  float v56; // r9
  float v57; // r8
  __int16 v58; // r9
  float v59; // r9
  __int16 v60; // r9
  float v61; // r9
  __int16 v62; // [sp+50h] [-130h] BYREF
  __int16 v63; // [sp+52h] [-12Eh]
  __int64 v64; // [sp+58h] [-128h]
  __int64 v65; // [sp+60h] [-120h]
  __int64 v66; // [sp+68h] [-118h]
  __int16 v67; // [sp+70h] [-110h]
  __int16 v68; // [sp+72h] [-10Eh]
  int v69; // [sp+74h] [-10Ch]
  __int16 v70; // [sp+78h] [-108h] BYREF
  __int16 v71; // [sp+7Ah] [-106h]
  __int16 v72; // [sp+7Ch] [-104h]
  float v73; // [sp+80h] [-100h] BYREF
  float v74; // [sp+84h] [-FCh]
  float v75; // [sp+88h] [-F8h]
  float v76; // [sp+8Ch] [-F4h]
  int v78; // [sp+94h] [-ECh]
  __int64 v79; // [sp+98h] [-E8h]
  __int64 v80; // [sp+A0h] [-E0h]
  float v81; // [sp+A8h] [-D8h] BYREF
  float v82; // [sp+ACh] [-D4h]
  float v83; // [sp+B0h] [-D0h]
  float v84; // [sp+B8h] [-C8h]
  float v85; // [sp+BCh] [-C4h]
  float v86; // [sp+C0h] [-C0h]

  v10 = v9;
  v67 = 0;
  v11 = (float *)HIDWORD(vertexCount);
  v68 = 0;
  v12 = vertexCount;
  v81 = 0.0;
  v82 = 0.0;
  v83 = 0.0;
  v84 = 0.0;
  v70 = 0;
  v85 = 0.0;
  v71 = 0;
  v86 = 0.0;
  v73 = 0.0;
  v72 = 0;
  v74 = 0.0;
  v75 = 0.0;
  v62 = 0;
  v76 = 0.0;
  v63 = 0;
  HIDWORD(v64) = 0;
  v69 = 0;
  HIDWORD(v65) = 0;
  HIDWORD(v66) = 0;
  if ( (int)vertexCount > 0 )
  {
    v15 = HIDWORD(v64);
    v16 = HIDWORD(v65);
    v17 = HIDWORD(v66);
    v18 = inputMask & 0x20;
    v19 = inputMask & 0x40;
    v21 = v20 & 0x20;
    v22 = v20 & 0x40;
    do
    {
      if ( v18 != 0 )
      {
        v23 = *((_WORD *)inputBuffer + 1);
        v24 = *((_WORD *)inputBuffer + 2);
        v70 = *(_WORD *)inputBuffer;
        inputBuffer += 2;
        v71 = v23;
        v72 = v24;
      }
      else if ( (inputMask & 1) != 0 )
      {
        v25 = inputBuffer[1];
        v26 = inputBuffer[2];
        v81 = *inputBuffer;
        inputBuffer += 3;
        v82 = v25;
        v83 = v26;
      }
      if ( (inputMask & 0x1000) != 0 )
      {
        v27 = inputBuffer[1];
        v28 = inputBuffer[2];
        v84 = *inputBuffer;
        inputBuffer += 3;
        v85 = v27;
        v86 = v28;
      }
      if ( v19 != 0 )
      {
        v29 = *((_WORD *)inputBuffer + 1);
        v62 = *(_WORD *)inputBuffer++;
        v63 = v29;
      }
      else if ( (inputMask & 2) != 0 )
      {
        v30 = inputBuffer[1];
        v73 = *inputBuffer;
        inputBuffer += 2;
        v74 = v30;
      }
      if ( (inputMask & 0x800) != 0 )
      {
        v31 = *((_WORD *)inputBuffer + 1);
        v67 = *(_WORD *)inputBuffer++;
        v68 = v31;
      }
      if ( (inputMask & 4) != 0 )
        v15 = *(_DWORD *)inputBuffer++;
      if ( (inputMask & 0x10) != 0 )
        v16 = *(_DWORD *)inputBuffer++;
      if ( (inputMask & 8) != 0 )
        v17 = *(_DWORD *)inputBuffer++;
      if ( v21 != 0 )
      {
        if ( v18 == 0 )
        {
          v38 = &v70;
          v39 = v11;
          for ( i = 3; i != 0; --i )
          {
            *(double *)&a7 = (float)(*(float *)((char *)v39 + (char *)&v81 - (char *)v11) * (float)4.0);
            a7 = floor(x: a7);
            if ( *v39 == 0.0 )
            {
              *v38 = 0;
            }
            else
            {
              *(double *)&a7 = (float)((float)((float)((float)((float)*(double *)&a7 * (float)0.25) - v39[3]) / *v39)
                                     + (float)0.5);
              a7 = floor(x: a7);
              v78 = (int)(float)*(double *)&a7;
              v41 = v78;
              if ( v78 >= -32768 )
              {
                if ( v78 > 0x7FFF )
                  v41 = 0x7FFF;
              }
              else
              {
                v41 = 0x8000;
              }
              *v38 = v41;
            }
            ++v39;
            ++v38;
          }
        }
      }
      else if ( v18 != 0 )
      {
        v32 = v11[5];
        v33 = v11[2];
        LODWORD(vertexCount) = v70;
        HIDWORD(vertexCount) = v71;
        v34 = *v11;
        v66 = vertexCount;
        v65 = *(__int64 *)((char *)&vertexCount + 4);
        v35 = v72;
        v36 = v11[3];
        v37 = v11[1];
        v64 = *(_QWORD *)(&v7 - 1);
        *((double *)&a7 + 1) = (float)*(__int64 *)(&v7 - 1);
        v82 = (float)((float)v37 * (float)*(__int64 *)((char *)&vertexCount + 4)) + v11[4];
        v83 = (float)((float)v33 * (float)*(__int64 *)(&v7 - 1)) + (float)v32;
        v81 = (float)((float)vertexCount * (float)v34) + (float)v36;
      }
      if ( v22 != 0 )
      {
        if ( v19 == 0 )
        {
          v47 = &v62;
          v48 = &v73;
          v49 = v11 + 6;
          v50 = 2;
          do
          {
            if ( *v49 == 0.0 )
            {
              *v47 = 0;
            }
            else
            {
              *(double *)&a7 = (float)((float)((float)(*v48 - v49[2]) / *v49) + (float)0.5);
              a7 = floor(x: a7);
              v78 = (int)(float)*(double *)&a7;
              v51 = v78;
              if ( v78 >= -32768 )
              {
                if ( v78 > 0x7FFF )
                  v51 = 0x7FFF;
              }
              else
              {
                v51 = 0x8000;
              }
              *v47 = v51;
            }
            --v50;
            ++v49;
            ++v48;
            ++v47;
          }
          while ( v50 != 0 );
        }
      }
      else if ( v19 != 0 )
      {
        v42 = v11[6];
        v43 = v11[8];
        v44 = v63;
        v45 = v11[7];
        LODWORD(vertexCount) = v62;
        v46 = v11[9];
        v80 = *(__int64 *)((char *)&vertexCount - 4);
        v79 = vertexCount;
        v73 = (float)((float)v42 * (float)vertexCount) + (float)v43;
        v74 = (float)((float)v45 * (float)*(__int64 *)((char *)&vertexCount - 4)) + (float)v46;
      }
      if ( v21 != 0 )
      {
        v52 = v71;
        v53 = v72;
        *(_WORD *)outputBuffer = v70;
        *((_WORD *)outputBuffer + 1) = v52;
        *((_WORD *)outputBuffer + 2) = v53;
        outputBuffer += 2;
      }
      else if ( (v10 & 1) != 0 )
      {
        v54 = v82;
        v55 = v83;
        *outputBuffer = v81;
        outputBuffer[1] = v54;
        outputBuffer[2] = v55;
        outputBuffer += 3;
      }
      if ( (v10 & 0x1000) != 0 )
      {
        v56 = v85;
        v57 = v86;
        *outputBuffer = v84;
        outputBuffer[1] = v56;
        outputBuffer[2] = v57;
        outputBuffer += 3;
      }
      if ( v22 != 0 )
      {
        v58 = v63;
        *(_WORD *)outputBuffer = v62;
        *((_WORD *)outputBuffer++ + 1) = v58;
      }
      else if ( (v10 & 2) != 0 )
      {
        v59 = v74;
        *outputBuffer = v73;
        outputBuffer[1] = v59;
        outputBuffer += 2;
      }
      if ( (v10 & 0x800) != 0 )
      {
        v60 = v68;
        *(_WORD *)outputBuffer = v67;
        *((_WORD *)outputBuffer++ + 1) = v60;
      }
      else if ( (v10 & 0x400) != 0 )
      {
        v61 = v76;
        *outputBuffer = v75;
        outputBuffer[1] = v61;
        outputBuffer += 2;
      }
      if ( (v10 & 4) != 0 )
        *(_DWORD *)outputBuffer++ = v15;
      if ( (v10 & 0x10) != 0 )
        *(_DWORD *)outputBuffer++ = v16;
      if ( (v10 & 8) != 0 )
        *(_DWORD *)outputBuffer++ = v17;
      ++v69;
    }
    while ( v69 < v12 );
  }
}

