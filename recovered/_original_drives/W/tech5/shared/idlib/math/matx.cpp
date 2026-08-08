
// ========================================================================
// ?CopyLowerToUpperTriangle@idMatX@@QAAXXZ
// EA  : 0x82F37908
// RVA : 0x00F37908
// PDB : w:\tech5\shared\idlib\math\matx.cpp
// ========================================================================

void __fastcall idMatX::CopyLowerToUpperTriangle(idMatX *this)
{
  int v1; // r11
  int numRows; // r25
  int v6; // r9
  int v7; // r24
  int v8; // r23
  int numColumns; // r9
  int v12; // r5
  int v16; // r27
  int v17; // r28
  unsigned int v20; // r19
  int v22; // r17
  int v23; // r26
  unsigned int v32; // ctr
  _DWORD v43[4]; // [sp+0h] [-E0h] BYREF
  int v44; // [sp+10h] [-D0h] BYREF
  int v45; // [sp+14h] [-CCh]
  int v46; // [sp+18h] [-C8h]
  int v47; // [sp+1Ch] [-C4h]
  int back_chain; // [sp+20h] [-C0h] BYREF
  int v49; // [sp+24h] [-BCh]
  int v50; // [sp+28h] [-B8h]
  int v51; // [sp+2Ch] [-B4h]
  int v52; // [sp+30h] [-B0h]
  int v53; // [sp+34h] [-ACh]
  int v54; // [sp+38h] [-A8h]
  int v55; // [sp+3Ch] [-A4h]
  int v56; // [sp+40h] [-A0h] BYREF
  int v57; // [sp+44h] [-9Ch]
  int v58; // [sp+48h] [-98h]
  int v59; // [sp+4Ch] [-94h]

  numRows = this->numRows;
  _R31 = this->mat;
  _R28 = &back_chain;
  v6 = this->numRows - 1;
  v49 = v1;
  v50 = v1;
  v51 = 0;
  v46 = 0;
  v7 = (numRows >> 1) & 1;
  v8 = (v6 >> 1) & 1;
  v43[2] = 0;
  v43[3] = 0;
  _R30 = v43;
  v44 = v1;
  _R29 = &v44;
  v45 = v1;
  v47 = 0;
  numColumns = this->numColumns;
  v56 = v1;
  v12 = -v7 & numColumns;
  v57 = v1;
  v58 = v1;
  v59 = v1;
  _R6 = 4 * numColumns;
  _R7 = 8 * numColumns;
  _R8 = 12 * numColumns;
  v16 = 4 * numColumns;
  __asm { lvx128    v61, r0, r28 }
  v17 = numRows - 3;
  back_chain = 0;
  _R21 = 4 * v12;
  v49 = 0;
  _R20 = 4 * ((-v8 & numColumns) + v12);
  v50 = 0;
  __asm { lvx128    v63, r0, r30 }
  v52 = v1;
  v53 = v1;
  v54 = v1;
  __asm { lvx128    v62, r0, r29 }
  v55 = v1;
  if ( numRows - 3 > 0 )
  {
    v20 = ((unsigned int)(numRows - 4) >> 2) + 1;
    _R11 = &v56;
    v22 = 4 * (v16 + 4);
    v23 = 4;
    _R29 = &_R31[_R8 / 4u];
    _R22 = _R6 - _R8;
    __asm { lvx128    v60, r0, r11 }
    _R18 = _R7 - _R8;
    do
    {
      __asm { lvx128    v59, r0, r31 }
      _R10 = (char *)_R29 + _R18;
      __asm
      {
        lvx128    v58, r22, r29
        vand128   v57, v91, v63
        lvx128    v56, r0, r29
        vand128   v55, v90, v62
        lvx128    v54, r18, r29
        vand128   v53, v88, v60
        vand128   v52, v86, v61
      }
      _R11 = _R31;
      _R9 = _R31;
      __asm
      {
        vmrghw128 v51, v87, v53
        vmrghw128 v50, v89, v52
        vmrglw128 v49, v87, v53
        vmrglw128 v48, v89, v52
        vmrghw128 v47, v82, v51
        vmrglw128 v46, v82, v51
        vmrghw128 v45, v80, v49
        vmrglw128 v44, v80, v49
        vor128    v43, v89, v47
        vor128    v42, v87, v46
        vor128    v41, v84, v45
        vor128    v40, v85, v44
        stvx128   v43, r0, r31
        stvx128   v42, r22, r29
        stvx128   v41, r18, r29
        stvx128   v40, r0, r29
      }
      if ( v23 < v17 )
      {
        _R4 = _R6 - _R7;
        _R3 = _R8 - _R7;
        v32 = ((unsigned int)(v17 - v23 - 1) >> 2) + 1;
        do
        {
          _R11 += v16;
          _R9 += 4;
          _R10 += 16;
          __asm
          {
            lvx128    v39, r0, r11
            lvx128    v38, r11, r6
            lvx128    v37, r11, r7
            lvx128    v36, r11, r8
            vmrghw128 v35, v71, v37
            vmrghw128 v34, v70, v36
            vmrglw128 v33, v71, v37
            vmrglw128 v32, v70, v36
            vmrghw128 v59, v67, v34
            vmrglw128 v58, v67, v34
            vmrghw128 v57, v65, v32
            vmrglw128 v56, v65, v32
            stvx128   v59, r0, r9
            stvx128   v58, r4, r10
            stvx128   v57, r0, r10
            stvx128   v56, r3, r10
          }
          --v32;
        }
        while ( v32 != 0 );
      }
      if ( (numRows & 3) != 0 )
      {
        __asm { vspltisw128 v55, 0 }
        _R5 = 16 * v7;
        _R10 = &_R11[v16];
        _R4 = &back_chain;
        _R3 = 16 * v8;
        _R30 = &back_chain;
        _R11 = _R9 + 4;
        __asm
        {
          lvx128    v54, r10, r21
          lvx128    v53, r5, r4
          lvx128    v52, r10, r20
          vand128   v51, v86, v53
          lvx128    v50, r3, r30
          vand128   v49, v84, v50
          lvx128    v48, r0, r10
          vmrghw128 v47, v83, v55
          vmrglw128 v46, v83, v55
          vmrghw128 v45, v80, v49
          vmrglw128 v44, v80, v49
          vmrghw128 v43, v77, v47
          vmrglw128 v42, v77, v47
          vmrghw128 v41, v76, v46
          vmrglw128 v40, v76, v46
          stvx128   v43, r0, r11
          stvx128   v42, r11, r6
          stvx128   v41, r11, r7
          stvx128   v40, r11, r8
        }
      }
      --v20;
      _R31 = (float *)((char *)_R31 + v22);
      _R29 = (float *)((char *)_R29 + v22);
      v23 += 4;
    }
    while ( v20 != 0 );
  }
  if ( (numRows & 3) != 0 )
  {
    _R11 = 16 * v7;
    __asm { lvx128    v39, r0, r31 }
    _R10 = &back_chain;
    __asm { vand128   v36, v71, v63 }
    _R9 = 16 * v8;
    __asm { lvx128    v38, r31, r21 }
    _R8 = &back_chain;
    __asm
    {
      lvx128    v37, r31, r20
      vspltisw128 v35, 0
      lvx128    v34, r11, r10
      vand128   v33, v94, v34
      lvx128    v32, r9, r8
      vand128   v63, v93, v32
      vand128   v62, v70, v33
      vand128   v61, v69, v63
      vmrglw128 v60, v94, v35
      vmrghw128 v59, v94, v35
      vmrglw128 v58, v68, v61
      vmrghw128 v57, v68, v61
      vmrghw128 v56, v90, v60
      vmrglw128 v55, v89, v59
      vmrghw128 v54, v89, v59
      vor128    v53, v93, v56
      vor128    v52, v94, v55
      vor128    v51, v68, v54
      stvx128   v53, r31, r20
      stvx128   v52, r31, r21
      stvx128   v51, r0, r31
    }
  }
}


// ========================================================================
// ?HouseholderReduction@idMatX@@AAAXAAVidVecX@@0@Z
// EA  : 0x82F37C08
// RVA : 0x00F37C08
// PDB : w:\tech5\shared\idlib\math\matx.cpp
// ========================================================================

void __fastcall idMatX::HouseholderReduction(idMatX *this, idVecX *diag, idVecX *subd)
{
  int v6; // r9
  int v7; // r24
  int v8; // r23
  double v9; // fp8
  double v10; // fp11
  double v11; // fp0
  int v12; // r11
  double v13; // fp13
  int v14; // r10
  float *v15; // r10
  double v16; // fp10
  double v17; // fp0
  int v18; // r11
  double v19; // fp13
  float *mat; // r10
  int v21; // r8
  float *v22; // r10
  double v23; // fp2
  int v24; // r7
  int v25; // r8
  int v26; // r3
  float *v27; // r10
  double v28; // fp11
  int v29; // r7
  double v30; // fp13
  double v31; // fp0
  int v32; // r10
  int v33; // r26
  double v34; // fp9
  int v35; // r25
  double v36; // fp10
  double v37; // fp0
  double v38; // fp13
  double v39; // fp11
  int v40; // r11
  int numColumns; // r5
  float *v42; // r6
  float *v43; // r8
  float *v44; // r7
  int v45; // r27
  double v46; // fp0
  double v47; // fp13
  int v48; // r11
  int v49; // r5
  float *v50; // r7
  int v51; // r8
  int v52; // r3
  int v53; // r21
  int v54; // r4
  int v55; // r5
  int v56; // r8
  int v57; // r28
  int v58; // r11
  float *p; // r10
  float *v60; // r6
  int v61; // r4
  double v62; // fp0
  double v63; // fp13
  int v64; // r10
  int v65; // r5
  int v66; // r4
  int v67; // r5
  int v68; // r7
  int v69; // ctr
  int v70; // r4
  int v71; // r3
  int v72; // r4
  int v73; // r11
  int numRows; // r10
  int v75; // r26
  int v76; // r27
  int i; // r9
  double v78; // fp0
  int v79; // r10
  double v80; // fp13
  double v81; // fp11
  int v82; // r6
  float *v83; // r8
  float *v84; // r7
  int v85; // r4
  int v86; // r5
  int v87; // r10
  double v88; // fp0
  int v89; // r8
  int v90; // r6
  int v91; // r6
  int v92; // ctr
  int v93; // r7
  int v94; // r10
  int v95; // r9
  int v96; // ctr
  int v97; // r3
  int v98; // r9
  int v99; // r11
  float *v100; // r8

  idVecX::SetSize(this: diag, newSize: this->numRows);
  idVecX::SetSize(this: subd, newSize: this->numRows);
  v6 = this->numRows - 1;
  v7 = this->numRows - 2;
  if ( v6 >= 1 )
  {
    v8 = v6;
    do
    {
      v9 = 0.0;
      v10 = 0.0;
      if ( v7 <= 0 )
        goto LABEL_42;
      v11 = 0.0;
      v12 = 0;
      v13 = 0.0;
      if ( v7 + 1 >= 2 )
      {
        do
        {
          v14 = this->numColumns * v6 + v12;
          v12 += 2;
          v15 = &this->mat[v14];
          v11 = (float)((float)__fabs(*v15) + (float)v11);
          v13 = (float)((float)__fabs(v15[1]) + (float)v13);
        }
        while ( v12 <= v7 - 1 );
      }
      if ( v12 <= v7 )
        v10 = __fabs(this->mat[this->numColumns * v6 + v12]);
      v16 = (float)((float)((float)v13 + (float)v11) + (float)v10);
      if ( v16 == 0.0 )
      {
LABEL_42:
        subd->p[v8] = this->mat[this->numColumns * v6 + v7];
      }
      else
      {
        v17 = 0.0;
        v18 = 0;
        v19 = 0.0;
        if ( v7 + 1 >= 2 )
        {
          mat = this->mat;
          v21 = this->numColumns * v6;
          do
          {
            mat[v21 + v18] = (float)((float)1.0 / (float)v16) * mat[v21 + v18];
            v22 = &this->mat[this->numColumns * v6 + v18];
            v23 = *v22;
            v22[1] = (float)((float)1.0 / (float)v16) * v22[1];
            mat = this->mat;
            v21 = this->numColumns * v6;
            v17 = (float)((float)((float)v23 * (float)v23) + (float)v17);
            v24 = v21 + v18 + 1;
            v18 += 2;
            v19 = (float)((float)(mat[v24] * mat[v24]) + (float)v19);
          }
          while ( v18 <= v7 - 1 );
        }
        if ( v18 <= v7 )
        {
          v25 = this->numColumns * v6 + v18;
          this->mat[v25] = (float)((float)1.0 / (float)v16) * this->mat[v25];
          v26 = this->numColumns * v6 + v18;
          v9 = (float)(this->mat[v26] * this->mat[v26]);
        }
        v27 = this->mat;
        v28 = (float)((float)((float)v19 + (float)v17) + (float)v9);
        v29 = this->numColumns * v6 + v7;
        v30 = v27[v29];
        v31 = __fsqrts(v28);
        if ( v30 > 0.0 )
          v31 = -v31;
        v9 = (float)-(float)((float)((float)v31 * v27[v29]) - (float)v28);
        v32 = 0;
        v33 = 0;
        v34 = 0.0;
        v35 = v7;
        subd->p[v8] = (float)v31 * (float)v16;
        v36 = (float)((float)1.0 / (float)-(float)((float)((float)v31 * (float)v30) - (float)v28));
        this->mat[this->numColumns * v6 + v7] = (float)v30 - (float)v31;
        do
        {
          v37 = 0.0;
          v38 = 0.0;
          v39 = 0.0;
          v40 = 0;
          this->mat[this->numColumns * v32 + v6] = this->mat[this->numColumns * v6 + v32] * (float)v36;
          if ( v32 >= 0 )
          {
            if ( v32 + 1 >= 2 )
            {
              numColumns = this->numColumns;
              v42 = this->mat;
              do
              {
                v43 = &v42[numColumns * v32 + v40];
                v44 = &v42[numColumns * v6 + v40];
                v40 += 2;
                v37 = (float)((float)(*v43 * *v44) + (float)v37);
                v38 = (float)((float)(v44[1] * v43[1]) + (float)v38);
              }
              while ( v40 <= v32 - 1 );
            }
            if ( v40 <= v32 )
              v39 = (float)(this->mat[this->numColumns * v32 + v40] * this->mat[this->numColumns * v6 + v40]);
            v39 = (float)((float)((float)v38 + (float)v37) + (float)v39);
          }
          v45 = v32 + 1;
          v46 = 0.0;
          v47 = 0.0;
          v48 = v32 + 1;
          if ( v32 + 1 <= v7 )
          {
            if ( v35 >= 2 )
            {
              v49 = this->numColumns;
              v50 = this->mat;
              v51 = v32 + 2;
              do
              {
                v52 = v49 * v6 + v48;
                v53 = v49 * v48 + v32;
                v54 = v51 * v49 + v32;
                v48 += 2;
                v51 += 2;
                v46 = (float)((float)(v50[v53] * v50[v52]) + (float)v46);
                v47 = (float)((float)(v50[v54] * v50[v52 + 1]) + (float)v47);
              }
              while ( v48 <= v7 - 1 );
            }
            if ( v48 <= v7 )
              v39 = (float)((float)(this->mat[this->numColumns * v48 + v32] * this->mat[this->numColumns * v6 + v48])
                          + (float)v39);
            v39 = (float)((float)((float)v47 + (float)v46) + (float)v39);
          }
          --v35;
          subd->p[v33] = (float)v36 * (float)v39;
          v55 = this->numColumns * v6 + v32++;
          v34 = (float)((float)(this->mat[v55] * subd->p[v33++]) + (float)v34);
        }
        while ( v45 <= v7 );
        v56 = 0;
        v57 = 0;
        do
        {
          v58 = 0;
          p = subd->p;
          v60 = this->mat;
          v61 = this->numColumns * v6 + v56;
          v62 = v60[v61];
          v63 = (float)-(float)((float)((float)((float)((float)v36 * (float)v34) * (float)0.5) * v60[v61]) - p[v57]);
          p[v57] = -(float)((float)((float)((float)((float)v36 * (float)v34) * (float)0.5) * v60[v61]) - p[v57]);
          if ( v56 >= 0 )
          {
            if ( v56 - 3 + 4 >= 4 )
            {
              v64 = 0;
              do
              {
                this->mat[this->numColumns * v56 + v58] = this->mat[this->numColumns * v56 + v58]
                                                        - (float)((float)(this->mat[this->numColumns * v6 + v58]
                                                                        * (float)v63)
                                                                + (float)(subd->p[v64] * (float)v62));
                this->mat[this->numColumns * v56 + 1 + v58] = this->mat[this->numColumns * v56 + 1 + v58]
                                                            - (float)((float)(this->mat[this->numColumns * v6 + 1 + v58]
                                                                            * (float)v63)
                                                                    + (float)(subd->p[v64 + 1] * (float)v62));
                this->mat[this->numColumns * v56 + 2 + v58] = this->mat[this->numColumns * v56 + 2 + v58]
                                                            - (float)((float)(this->mat[this->numColumns * v6 + 2 + v58]
                                                                            * (float)v63)
                                                                    + (float)(subd->p[v64 + 2] * (float)v62));
                v65 = this->numColumns;
                v66 = v65 * v6 + v58 + 3;
                v67 = v65 * v56 + v58 + 3;
                v58 += 4;
                this->mat[v67] = this->mat[v67]
                               - (float)((float)(this->mat[v66] * (float)v63) + (float)(subd->p[v64 + 3] * (float)v62));
                v64 += 4;
              }
              while ( v58 <= v56 - 3 );
            }
            if ( v58 <= v56 )
            {
              v68 = v58;
              v69 = v56 - v58 + 1;
              do
              {
                v70 = this->numColumns;
                v71 = v70 * v6 + v58;
                v72 = v70 * v56 + v58++;
                this->mat[v72] = this->mat[v72]
                               - (float)((float)(this->mat[v71] * (float)v63) + (float)(subd->p[v68++] * (float)v62));
                --v69;
              }
              while ( v69 != 0 );
            }
          }
          ++v56;
          ++v57;
        }
        while ( v56 <= v7 );
      }
      --v6;
      --v7;
      diag->p[v8--] = v9;
    }
    while ( v6 >= 1 );
  }
  v73 = 0;
  *diag->p = 0.0;
  *subd->p = 0.0;
  numRows = this->numRows;
  if ( this->numRows - 1 >= 0 )
  {
    v75 = 0;
    do
    {
      if ( diag->p[v75] != 0.0 )
      {
        v76 = v73 - 1;
        for ( i = 0; i <= v76; ++i )
        {
          v78 = 0.0;
          v79 = 0;
          v80 = 0.0;
          v81 = 0.0;
          if ( v73 >= 2 )
          {
            v82 = this->numColumns;
            v83 = this->mat;
            do
            {
              v84 = &v83[v82 * v73 + v79];
              v85 = v82 * v79 + i;
              v86 = (v79 + 1) * v82 + i;
              v79 += 2;
              v78 = (float)((float)(v83[v85] * *v84) + (float)v78);
              v80 = (float)((float)(v83[v86] * v84[1]) + (float)v80);
            }
            while ( v79 <= v73 - 2 );
          }
          if ( v79 <= v76 )
            v81 = (float)(this->mat[this->numColumns * v79 + i] * this->mat[this->numColumns * v73 + v79]);
          v87 = 0;
          v88 = (float)((float)((float)v80 + (float)v78) + (float)v81);
          if ( v73 >= 4 )
          {
            v89 = 2;
            do
            {
              v90 = this->numColumns * v87;
              v87 += 4;
              this->mat[v90 + i] = -(float)((float)(this->mat[v90 + v73] * (float)v88) - this->mat[v90 + i]);
              this->mat[(v89 - 1) * this->numColumns + i] = -(float)((float)(this->mat[(v89 - 1) * this->numColumns
                                                                                     + v73]
                                                                           * (float)v88)
                                                                   - this->mat[(v89 - 1) * this->numColumns + i]);
              this->mat[this->numColumns * v89 + i] = -(float)((float)(this->mat[this->numColumns * v89 + v73]
                                                                     * (float)v88)
                                                             - this->mat[this->numColumns * v89 + i]);
              v91 = (v89 + 1) * this->numColumns;
              v89 += 4;
              this->mat[v91 + i] = -(float)((float)(this->mat[v91 + v73] * (float)v88) - this->mat[v91 + i]);
            }
            while ( v87 <= v73 - 4 );
          }
          if ( v87 <= v76 )
          {
            v92 = v73 - v87;
            do
            {
              v93 = this->numColumns * v87++;
              this->mat[v93 + i] = -(float)((float)(this->mat[v93 + v73] * (float)v88) - this->mat[v93 + i]);
              --v92;
            }
            while ( v92 != 0 );
          }
        }
      }
      v94 = 0;
      diag->p[v75] = this->mat[(this->numColumns + 1) * v73];
      this->mat[(this->numColumns + 1) * v73] = 1.0;
      if ( v73 - 1 >= 0 )
      {
        if ( v73 >= 4 )
        {
          do
          {
            this->mat[this->numColumns * v94 + v73] = 0.0;
            this->mat[this->numColumns * v73 + v94] = 0.0;
            this->mat[(v94 + 1) * this->numColumns + v73] = 0.0;
            this->mat[this->numColumns * v73 + 1 + v94] = 0.0;
            this->mat[(v94 + 2) * this->numColumns + v73] = 0.0;
            this->mat[this->numColumns * v73 + 2 + v94] = 0.0;
            this->mat[(v94 + 3) * this->numColumns + v73] = 0.0;
            v95 = this->numColumns * v73 + v94;
            v94 += 4;
            this->mat[v95 + 3] = 0.0;
          }
          while ( v94 <= v73 - 4 );
        }
        if ( v94 <= v73 - 1 )
        {
          v96 = v73 - v94;
          do
          {
            this->mat[this->numColumns * v94 + v73] = 0.0;
            v97 = this->numColumns * v73 + v94++;
            this->mat[v97] = 0.0;
            --v96;
          }
          while ( v96 != 0 );
        }
      }
      numRows = this->numRows;
      ++v73;
      ++v75;
    }
    while ( v73 <= this->numRows - 1 );
  }
  v98 = 1;
  if ( numRows > 1 )
  {
    v99 = 1;
    do
    {
      ++v98;
      v100 = &subd->p[v99++];
      *(v100 - 1) = *v100;
      numRows = this->numRows;
    }
    while ( v98 < this->numRows );
  }
  subd->p[numRows - 1] = 0.0;
}


// ========================================================================
// ?QL@idMatX@@AAA_NAAVidVecX@@0@Z
// EA  : 0x82F38670
// RVA : 0x00F38670
// PDB : w:\tech5\shared\idlib\math\matx.cpp
// ========================================================================

int __fastcall idMatX::QL(idMatX *this, idVecX *diag, idVecX *subd)
{
  int v3; // r27
  int i; // r28
  int v5; // r26
  int v6; // r31
  int v7; // r30
  float *v8; // r9
  int v9; // r11
  float *v10; // r6
  double v11; // fp12
  double v12; // fp13
  double v13; // fp9
  double v14; // fp0
  double v15; // fp13
  double v16; // fp12
  double v17; // fp13
  double v18; // fp0
  double v19; // fp10
  double v20; // fp0
  double v21; // fp10
  float *p; // r9
  int v23; // r11
  double v24; // fp13
  double v25; // fp9
  int v26; // r29
  float *v27; // r6
  double v28; // fp0
  double v29; // fp12
  double v30; // fp0
  int v31; // r8
  double v32; // fp13
  double v33; // fp0
  double v34; // fp12
  double v35; // fp9
  float *v36; // r10
  float *v37; // r9
  float *v38; // r31
  float *v39; // r7
  float *v40; // r6
  int v41; // r30
  double v42; // fp11
  double v43; // fp10
  double v44; // fp0
  double v45; // fp12
  double v46; // fp13
  double v47; // fp5
  double v48; // fp5
  int v49; // r11
  float *v50; // r10
  double v51; // fp4
  int v52; // r9
  float *v53; // r10

  v3 = 0;
  if ( this->numRows <= 0 )
    return 1;
  for ( i = 0; ; ++i )
  {
    v5 = 0;
    do
    {
      v6 = v3;
      v7 = this->numRows - 2;
      if ( v3 > v7 )
        break;
      if ( v7 - v3 + 1 < 4 )
      {
LABEL_12:
        if ( v6 <= v7 )
        {
          p = diag->p;
          v23 = v6;
          do
          {
            v24 = __fabs(p[v23]);
            v25 = __fabs(p[v23 + 1]);
            if ( (float)((float)__fabs(subd->p[v23]) + (float)((float)v25 + (float)v24)) == (float)((float)v25
                                                                                                  + (float)v24) )
              break;
            ++v6;
            ++v23;
          }
          while ( v6 <= v7 );
        }
      }
      else
      {
        v8 = diag->p;
        v9 = i * 4 + 8;
        v10 = subd->p;
        while ( 1 )
        {
          v11 = __fabs(*(float *)((char *)v8 + v9 - 8));
          v12 = *(float *)((char *)v8 + v9 - 4);
          v13 = __fabs(v12);
          if ( (float)((float)__fabs(*(float *)((char *)v10 + v9 - 8)) + (float)((float)v11 + (float)v13)) == (float)((float)v11 + (float)v13) )
            break;
          v14 = *(float *)((char *)v8 + v9);
          v15 = __fabs(v12);
          v16 = __fabs(v14);
          if ( (float)((float)__fabs(*(float *)((char *)v10 + v9 - 4)) + (float)((float)v15 + (float)v16)) == (float)((float)v15 + (float)v16) )
          {
            ++v6;
            break;
          }
          v17 = __fabs(v14);
          v18 = *(float *)((char *)v8 + v9 + 4);
          v19 = __fabs(v18);
          if ( (float)((float)__fabs(*(float *)((char *)v10 + v9)) + (float)((float)v17 + (float)v19)) == (float)((float)v17 + (float)v19) )
          {
            v6 += 2;
            break;
          }
          v20 = __fabs(v18);
          v21 = __fabs(*(float *)((char *)v8 + v9 + 8));
          if ( (float)((float)__fabs(*(float *)((char *)v10 + v9 + 4)) + (float)((float)v21 + (float)v20)) == (float)((float)v21 + (float)v20) )
          {
            v6 += 3;
            break;
          }
          v6 += 4;
          v9 += 16;
          if ( v6 > this->numRows - 5 )
            goto LABEL_12;
        }
      }
      if ( v6 == v3 )
        break;
      v26 = v6;
      v27 = subd->p;
      v28 = (float)((float)(diag->p[i + 1] - diag->p[i]) / (float)(v27[i] * (float)2.0));
      v29 = __fsqrts((float)((float)((float)v28 * (float)v28) + (float)1.0));
      if ( v28 >= 0.0 )
        v30 = (float)((float)v29 + (float)((float)(diag->p[i + 1] - diag->p[i]) / (float)(v27[i] * (float)2.0)));
      else
        v30 = (float)((float)((float)(diag->p[i + 1] - diag->p[i]) / (float)(v27[i] * (float)2.0)) - (float)v29);
      v31 = v6 - 1;
      v32 = 1.0;
      v34 = (float)((float)(diag->p[v6] - diag->p[i]) + (float)(v27[i] / (float)v30));
      v33 = 1.0;
      v35 = 0.0;
      if ( v6 - 1 >= v3 )
      {
        v36 = diag->p;
        v37 = subd->p;
        v38 = &v37[v31];
        v39 = &v36[v31 + 1];
        v40 = &v27[v31 + 1];
        v41 = (char *)v36 - (char *)v37;
        do
        {
          v42 = (float)(*v38 * (float)v32);
          v43 = (float)(*v38 * (float)v33);
          if ( __fabs(v42) < __fabs(v34) )
          {
            v46 = (float)((float)(*v38 * (float)v32) / (float)v34);
            v47 = __fsqrts((float)((float)((float)((float)v42 / (float)v34) * (float)((float)v42 / (float)v34))
                                 + (float)1.0));
            v33 = (float)((float)1.0 / (float)v47);
            *v40 = (float)v47 * (float)v34;
            v32 = (float)((float)((float)1.0 / (float)v47) * (float)v46);
          }
          else
          {
            v44 = (float)((float)v34 / (float)(*v38 * (float)v32));
            v45 = __fsqrts((float)((float)((float)((float)v34 / (float)(*v38 * (float)v32))
                                         * (float)((float)v34 / (float)(*v38 * (float)v32)))
                                 + (float)1.0));
            v32 = (float)((float)1.0 / (float)v45);
            *v40 = (float)v42 * (float)v45;
            v33 = (float)((float)v44 * (float)((float)1.0 / (float)v45));
          }
          v48 = (float)(*v39 - (float)v35);
          v49 = 0;
          v34 = (float)((float)((float)v33
                              * (float)((float)((float)(*(float *)((char *)v38 + v41) - (float)(*v39 - (float)v35))
                                              * (float)v32)
                                      + (float)((float)((float)v43 * (float)v33) * (float)2.0)))
                      - (float)v43);
          v35 = (float)((float)v32
                      * (float)((float)((float)(*(float *)((char *)v38 + v41) - (float)(*v39 - (float)v35)) * (float)v32)
                              + (float)((float)((float)v43 * (float)v33) * (float)2.0)));
          for ( *v39 = (float)v35 + (float)v48;
                v49 < this->numRows;
                this->mat[v52] = (float)(this->mat[v52] * (float)v33) - (float)v51 )
          {
            v50 = &this->mat[v49 * this->numColumns + v31];
            v51 = (float)(v50[1] * (float)v32);
            v50[1] = (float)(*v50 * (float)v32) + (float)(v50[1] * (float)v33);
            v52 = v49 * this->numColumns + v31;
            ++v49;
          }
          --v31;
          --v38;
          --v40;
          --v39;
        }
        while ( v31 >= v3 );
      }
      ++v5;
      v53 = subd->p;
      diag->p[i] = diag->p[i] - (float)v35;
      v53[i] = v34;
      v53[v26] = 0.0;
    }
    while ( v5 < 32 );
    if ( v5 == 32 )
      break;
    if ( ++v3 >= this->numRows )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?Eigen_SolveSymmetric@idMatX@@QAA_NAAVidVecX@@@Z
// EA  : 0x82F38A08
// RVA : 0x00F38A08
// PDB : w:\tech5\shared\idlib\math\matx.cpp
// ========================================================================

int __fastcall idMatX::Eigen_SolveSymmetric(idMatX *this, idVecX *eigenValues)
{
  int v4; // r12
  int v5; // r4
  int v6; // r30
  _DWORD back_chain[20]; // [sp+0h] [-80h]
  idVecX v9; // [sp+50h] [-30h] BYREF

  memset(&v9, 0, sizeof(v9));
  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v4) = back_chain[0];
  idVecX::SetData(this: &v9, length: v5, data: (float *)&v9.size);
  idVecX::SetSize(this: eigenValues, newSize: this->numRows);
  idMatX::HouseholderReduction(this, diag: eigenValues, subd: &v9);
  v6 = idMatX::QL(this, diag: eigenValues, subd: &v9);
  if ( v9.p != nullptr && (v9.p < idVecX::tempPtr || v9.p >= idVecX::tempPtr + 1024) && v9.alloced != -1 )
    idMem::Free(this: &mem, ptr: v9.p, align: ALIGN_16);
  return v6;
}


// ========================================================================
// __unwind$120143
// EA  : 0x82F38AF0
// RVA : 0x00F38AF0
// PDB : w:\tech5\shared\idlib\math\matx.cpp
// ========================================================================

void _unwind_120143()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 128 + 80));
}


// ========================================================================
// ?Eigen_SortIncreasing@idMatX@@QAAXAAVidVecX@@@Z
// EA  : 0x82F38B18
// RVA : 0x00F38B18
// PDB : w:\tech5\shared\idlib\math\matx.cpp
// ========================================================================

void __fastcall idMatX::Eigen_SortIncreasing(idMatX *this, idVecX *eigenValues)
{
  int numRows; // r7
  int v3; // r30
  float *p; // r31
  int v5; // r6
  int v6; // r29
  double v7; // fp0
  int v8; // r8
  int v9; // r11
  int v10; // r10
  int v11; // r10
  int v12; // ctr
  float *v13; // r11
  int v14; // r10
  int v15; // r9
  double v16; // fp0
  float *i; // r11
  double v18; // fp0

  numRows = this->numRows;
  v3 = 0;
  if ( this->numRows - 2 >= 0 )
  {
    p = eigenValues->p;
    v5 = 0;
    do
    {
      v6 = v3 + 1;
      v7 = p[v5];
      v8 = v3;
      v9 = v3 + 1;
      if ( v3 + 1 < numRows )
      {
        if ( numRows - v6 >= 4 )
        {
          v10 = v5 * 4 + 12;
          do
          {
            if ( *(float *)((char *)p + v10 - 8) < v7 )
            {
              v8 = v9;
              v7 = *(float *)((char *)p + v10 - 8);
            }
            if ( *(float *)((char *)p + v10 - 4) < v7 )
            {
              v8 = v9 + 1;
              v7 = *(float *)((char *)p + v10 - 4);
            }
            if ( *(float *)((char *)p + v10) < v7 )
            {
              v8 = v9 + 2;
              v7 = *(float *)((char *)p + v10);
            }
            if ( *(float *)((char *)p + v10 + 4) < v7 )
            {
              v8 = v9 + 3;
              v7 = *(float *)((char *)p + v10 + 4);
            }
            v9 += 4;
            v10 += 16;
          }
          while ( v9 < numRows - 3 );
        }
        if ( v9 < numRows )
        {
          v11 = v9;
          v12 = numRows - v9;
          do
          {
            if ( p[v11] < v7 )
            {
              v8 = v9;
              v7 = p[v11];
            }
            ++v9;
            ++v11;
            --v12;
          }
          while ( v12 != 0 );
        }
        if ( v8 != v3 )
        {
          v13 = eigenValues->p;
          v14 = v8;
          v15 = 0;
          v16 = v13[v5];
          v13[v5] = v13[v8];
          v13[v8] = v16;
          numRows = this->numRows;
          for ( i = this->mat; v15 < this->numRows; i += this->numColumns )
          {
            v18 = i[v5];
            ++v15;
            i[v5] = i[v14];
            i[v14] = v18;
            numRows = this->numRows;
          }
        }
      }
      ++v3;
      ++v5;
    }
    while ( v6 <= numRows - 2 );
  }
}

