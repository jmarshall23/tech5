
// ========================================================================
// ?MD5_Transform@@YAXQAIQBE@Z
// EA  : 0x82F2BEE8
// RVA : 0x00F2BEE8
// PDB : w:\tech5\shared\idlib\hashing\md5.cpp
// ========================================================================

void __fastcall MD5_Transform(unsigned int *state, const unsigned __int8 *block)
{
  unsigned int v2; // r11
  unsigned int v3; // r5
  unsigned int v4; // r31
  int v5; // r10
  int v6; // ctr
  int *v7; // r9
  int v8; // r29
  int v9; // r8
  int v10; // r28
  int v11; // r27
  int v12; // r29
  unsigned int v13; // r10
  unsigned int v14; // r9
  unsigned int v15; // r8
  unsigned int v16; // r7
  unsigned int v17; // r10
  unsigned int v18; // r9
  unsigned int v19; // r8
  unsigned int v20; // r7
  unsigned int v21; // r10
  int v22; // r9
  int v23; // r8
  int v24; // r7
  int v25; // r10
  int v26; // r9
  int v27; // r6
  int v28; // r24
  int v29; // r9
  int v30; // r8
  int v31; // r10
  int v32; // r7
  int v33; // r9
  int v34; // r8
  int v35; // r10
  int v36; // r7
  int v37; // r9
  int v38; // r8
  int v39; // r10
  int v40; // r7
  int v41; // r9
  int v42; // r8
  int v43; // r10
  int v44; // r7
  int v45; // r9
  int v46; // r6
  int v47; // r23
  int v48; // r9
  int v49; // r10
  int v50; // r8
  int v51; // r7
  int v52; // r9
  int v53; // r10
  int v54; // r8
  int v55; // r7
  int v56; // r9
  int v57; // r10
  int v58; // r8
  int v59; // r7
  int v60; // r9
  int v61; // r10
  int v62; // r8
  int v63; // r7
  int v64; // r9
  int v65; // r10
  int v66; // r8
  int v67; // r7
  int v68; // r9
  int v69; // r10
  int v70; // r8
  int v71; // r7
  int v72; // r30
  int v73; // r9
  int v74; // r10
  int v75; // r8
  int v76; // r7
  int v77; // r4
  int v78; // r9
  int v79; // r10
  int v80; // r8
  int v81; // r7
  int back_chain; // [sp+0h] [-D0h] BYREF
  int v83; // [sp+4h] [-CCh]
  int v84; // [sp+8h] [-C8h]
  int v85; // [sp+Ch] [-C4h]
  int v86; // [sp+10h] [-C0h]
  int v87; // [sp+14h] [-BCh]
  int v88; // [sp+18h] [-B8h]
  int v89; // [sp+1Ch] [-B4h]
  int v90; // [sp+20h] [-B0h]
  int v91; // [sp+24h] [-ACh]
  int v92; // [sp+28h] [-A8h]
  int v93; // [sp+2Ch] [-A4h]
  int v94; // [sp+30h] [-A0h]
  int v95; // [sp+34h] [-9Ch]
  int v96; // [sp+38h] [-98h]
  int v97; // [sp+3Ch] [-94h]

  v2 = state[1];
  v3 = state[2];
  v4 = state[3];
  v5 = 0;
  v6 = 16;
  v7 = &back_chain - 1;
  do
  {
    v8 = block[v5 + 2];
    v9 = __ROL4__(block[v5 + 3], 8);
    v10 = block[v5 + 1];
    v11 = block[v5];
    v5 += 4;
    *++v7 = ((((v9 | v8) << 8) | v10) << 8) | v11;
    --v6;
  }
  while ( v6 != 0 );
  v12 = v84;
  v13 = __ROL4__(((v4 ^ v3) & v2 ^ v4) + back_chain + *state - 680876936, 7) + v2;
  v14 = __ROL4__(((v3 ^ v2) & v13 ^ v3) + v83 + v4 - 389564586, 12) + v13;
  v15 = __ROR4__(((v2 ^ v13) & v14 ^ v2) + v84 + v3 + 606105819, 15) + v14;
  v16 = __ROR4__(((v14 ^ v13) & v15 ^ v13) + v85 + v2 - 1044525330, 10) + v15;
  v17 = __ROL4__(((v14 ^ v15) & v16 ^ v14) + v86 + v13 - 176422912 + 4015, 7) + v16;
  v18 = __ROL4__(((v15 ^ v16) & v17 ^ v15) + v87 + v14 + 1200080426, 12) + v17;
  v19 = __ROR4__(((v16 ^ v17) & v18 ^ v16) + v88 + v15 - 1473249280 + 17939, 15) + v18;
  v20 = __ROR4__(((v18 ^ v17) & v19 ^ v17) + v89 + v16 - 45705983, 10) + v19;
  v21 = __ROL4__(((v18 ^ v19) & v20 ^ v18) + v90 + v17 + 1770035416, 7) + v20;
  v22 = __ROL4__(((v19 ^ v20) & v21 ^ v19) + v91 + v18 - 1958414417, 12) + v21;
  v23 = __ROR4__(((v20 ^ v21) & v22 ^ v20) + v92 + v19 - 0x10000 + 23473, 15) + v22;
  v24 = __ROR4__(((v22 ^ v21) & v23 ^ v21) + v93 + v20 - 1990404162, 10) + v23;
  v25 = __ROL4__(((v22 ^ v23) & v24 ^ v22) + v94 + v21 + 1804603682, 7) + v24;
  v26 = __ROL4__(((v23 ^ v24) & v25 ^ v23) + v95 + v22 - 40370176 + 29075, 12);
  v27 = v26 + v25;
  v28 = (v26 + v25) ^ v25;
  v29 = __ROR4__(((v24 ^ v25) & (v26 + v25) ^ v24) + v96 + v23 - 1502019584 + 17294, 15) + v26 + v25;
  v30 = __ROR4__((v28 & v29 ^ v25) + v97 + v24 + 1236535329, 10) + v29;
  v31 = __ROL4__(((v29 ^ v30) & v27 ^ v29) + v83 + v25 - 165806080 + 9570, 5) + v30;
  v32 = __ROL4__(((v30 ^ v31) & v29 ^ v30) + v88 + v27 - 1069501632, 9) + v31;
  v33 = __ROL4__(((v32 ^ v31) & v30 ^ v31) + v93 + v29 + 643717713, 14) + v32;
  v34 = __ROR4__(((v32 ^ v33) & v31 ^ v32) + back_chain + v30 - 373897302, 12) + v33;
  v35 = __ROL4__(((v33 ^ v34) & v32 ^ v33) + v87 + v31 - 701562880 + 4189, 5) + v34;
  v36 = __ROL4__(((v34 ^ v35) & v33 ^ v34) + v92 + v32 + 38016083, 9) + v35;
  v37 = __ROL4__(((v36 ^ v35) & v34 ^ v35) + v97 + v33 - 660478335, 14) + v36;
  v38 = __ROR4__(((v36 ^ v37) & v35 ^ v36) + v86 + v34 - 405537848, 12) + v37;
  v39 = __ROL4__(((v37 ^ v38) & v36 ^ v37) + v91 + v35 + 568446438, 5) + v38;
  v40 = __ROL4__(((v38 ^ v39) & v37 ^ v38) + v96 + v36 - 1019805696 + 2006, 9) + v39;
  v41 = __ROL4__(((v40 ^ v39) & v38 ^ v39) + v85 + v37 - 187367424 + 3463, 14) + v40;
  v42 = __ROR4__(((v40 ^ v41) & v39 ^ v40) + v90 + v38 + 1163531501, 12) + v41;
  v43 = __ROL4__(((v41 ^ v42) & v40 ^ v41) + v95 + v39 - 1444681467, 5) + v42;
  v44 = __ROL4__(((v42 ^ v43) & v41 ^ v42) + v84 + v40 - 51403784, 9) + v43;
  v45 = __ROL4__(((v44 ^ v43) & v42 ^ v43) + v89 + v41 + 1735328473, 14);
  v46 = v45 + v44;
  v47 = v44 ^ (v45 + v44);
  v48 = __ROR4__((v47 & v43 ^ v44) + v94 + v42 - 1926627328 + 19594, 12) + v45 + v44;
  v49 = __ROL4__((v47 ^ v48) + v87 + v43 - 393216 + 14658, 4) + v48;
  v50 = __ROL4__((v46 ^ v48 ^ v49) + v90 + v44 - 2022574463, 11) + v49;
  v51 = __ROL4__((v50 ^ v48 ^ v49) + v93 + v46 + 1839030562, 16) + v50;
  v52 = __ROR4__((v50 ^ v51 ^ v49) + v96 + v48 - 35323904 + 14348, 9) + v51;
  v53 = __ROL4__((v50 ^ v51 ^ v52) + v83 + v49 - 1530992060, 4) + v52;
  v54 = __ROL4__((v51 ^ v52 ^ v53) + v86 + v50 + 1272893353, 11) + v53;
  v55 = __ROL4__((v54 ^ v52 ^ v53) + v89 + v51 - 155516928 + 19296, 16) + v54;
  v56 = __ROR4__((v54 ^ v55 ^ v53) + v92 + v52 - 1094730640, 9) + v55;
  v57 = __ROL4__((v54 ^ v55 ^ v56) + v95 + v53 + 681279174, 4) + v56;
  v58 = __ROL4__((v55 ^ v56 ^ v57) + back_chain + v54 - 358547456 + 10234, 11) + v57;
  v59 = __ROL4__((v58 ^ v56 ^ v57) + v85 + v55 - 722534400 + 12421, 16) + v58;
  v60 = __ROR4__((v58 ^ v59 ^ v57) + v88 + v56 + 76029189, 9) + v59;
  v61 = __ROL4__((v58 ^ v59 ^ v60) + v91 + v57 - 640364487, 4) + v60;
  v62 = __ROL4__((v59 ^ v60 ^ v61) + v94 + v58 - 421815835, 11) + v61;
  v63 = __ROL4__((v62 ^ v60 ^ v61) + v97 + v59 + 530742520, 16) + v62;
  v64 = __ROR4__((v62 ^ v63 ^ v61) + v84 + v60 - 995360768 + 22117, 9) + v63;
  v65 = __ROL4__(((v64 | ~v62) ^ v63) + back_chain + v61 - 198639616 + 8772, 6) + v64;
  v66 = __ROL4__(((v65 | ~v63) ^ v64) + v89 + v62 + 1126891415, 10) + v65;
  v67 = __ROL4__(((v66 | ~v64) ^ v65) + v96 + v63 - 1416364032 + 9127, 15) + v66;
  v68 = __ROR4__(((v67 | ~v65) ^ v66) + v87 + v64 - 57434055, 11) + v67;
  v69 = __ROL4__(((v68 | ~v66) ^ v67) + v94 + v65 + 1700485571, 6) + v68;
  v70 = __ROL4__(((v69 | ~v67) ^ v68) + v85 + v66 - 1894986606, 10) + v69;
  v71 = __ROL4__(((v70 | ~v68) ^ v69) + v92 + v67 - 1051523, 15) + v70;
  v72 = v91;
  v73 = __ROR4__(((v71 | ~v69) ^ v70) + v83 + v68 - 2054946816 + 24017, 11) + v71;
  v74 = __ROL4__(((v73 | ~v70) ^ v71) + v90 + v69 + 1873313359, 6) + v73;
  v75 = __ROL4__(((v74 | ~v71) ^ v73) + v97 + v70 - 30611744, 10) + v74;
  v76 = __ROL4__(((v75 | ~v73) ^ v74) + v88 + v71 - 1560215552 + 17172, 15) + v75;
  v77 = v93;
  v78 = __ROR4__(((v76 | ~v74) ^ v75) + v95 + v73 + 1309151649, 11) + v76;
  v79 = __ROL4__(((v78 | ~v75) ^ v76) + v86 + v74 - 145555456 + 32386, 6) + v78;
  *state += v79;
  v80 = __ROL4__(((v79 | ~v76) ^ v78) + v77 + v75 - 1120210379, 10) + v79;
  state[3] = v4 + v80;
  v81 = __ROL4__(((v80 | ~v78) ^ v79) + v12 + v76 + 718787259, 15) + v80;
  state[2] = v3 + v81;
  state[1] = __ROR4__(((v81 | ~v79) ^ v80) + v72 + v78 - 343485551, 11) + v2 + v81;
}


// ========================================================================
// ?MD5_Init@@YAXPAUMD5_CTX@@@Z
// EA  : 0x82F2C890
// RVA : 0x00F2C890
// PDB : w:\tech5\shared\idlib\hashing\md5.cpp
// ========================================================================

void __fastcall MD5_Init(MD5_CTX *ctx)
{
  ctx->state[0] = 1732584193;
  ctx->bits[0] = 0;
  ctx->state[1] = -271733879;
  ctx->state[2] = -1732584194;
  ctx->state[3] = 271733878;
  ctx->bits[1] = 0;
}


// ========================================================================
// ?MD5_Update@@YAXPAUMD5_CTX@@PBEI@Z
// EA  : 0x82F2C8D0
// RVA : 0x00F2C8D0
// PDB : w:\tech5\shared\idlib\hashing\md5.cpp
// ========================================================================

void __fastcall MD5_Update(MD5_CTX *context, const unsigned __int8 *input, unsigned int inputLen)
{
  unsigned int v3; // r11
  unsigned int v4; // r10
  int v8; // r11
  size_t v9; // r28
  unsigned int i; // r29

  v3 = context->bits[0];
  v4 = 8 * inputLen + v3;
  context->bits[0] = v4;
  v8 = (v3 >> 3) & 0x3F;
  if ( v4 < 8 * inputLen )
    ++context->bits[1];
  v9 = 64 - v8;
  context->bits[1] += inputLen >> 29;
  if ( inputLen < 64 - v8 )
  {
    v9 = 0;
  }
  else
  {
    memcpy(Dst: &context->in[v8], Src: input, Size: v9);
    MD5_Transform(state: context->state, block: context->in);
    for ( i = v9 + 63; i < inputLen; v9 += 64 )
    {
      MD5_Transform(state: context->state, block: &input[i - 63]);
      i += 64;
    }
    v8 = 0;
  }
  memcpy(Dst: &context->in[v8], Src: &input[v9], Size: inputLen - v9);
}


// ========================================================================
// ?MD5_Final@@YAXPAUMD5_CTX@@QAE@Z
// EA  : 0x82F2C9A8
// RVA : 0x00F2C9A8
// PDB : w:\tech5\shared\idlib\hashing\md5.cpp
// ========================================================================

void __fastcall MD5_Final(MD5_CTX *context, unsigned __int8 *digest)
{
  int v4; // r9
  unsigned int *v5; // r11
  int i; // ctr
  unsigned int v7; // r6
  unsigned __int8 v8; // r5
  unsigned __int8 v9; // r4
  unsigned __int8 *v10; // r10
  unsigned __int8 v11; // r8
  unsigned int v12; // r11
  unsigned int v13; // r5
  int v14; // r10
  MD5_CTX *v15; // r11
  int j; // ctr
  unsigned __int8 v17[8]; // [sp+50h] [-20h] BYREF

  v4 = 0;
  v5 = &context->state[3];
  for ( i = 2; i != 0; --i )
  {
    v7 = v5[1];
    v8 = *((_BYTE *)v5 + 6);
    v9 = *((_BYTE *)v5 + 5);
    v10 = &v17[v4 + 1];
    v11 = *(_BYTE *)++v5;
    v4 += 4;
    *(v10 - 1) = v7;
    *v10 = v8;
    v10[1] = v9;
    v10[2] = v11;
  }
  v12 = (context->bits[0] >> 3) & 0x3F;
  v13 = 56 - v12;
  if ( v12 >= 0x38 )
    v13 = 120 - v12;
  MD5_Update(context, input: PADDING_0, inputLen: v13);
  MD5_Update(context, input: v17, inputLen: 8u);
  v14 = 0;
  v15 = context;
  for ( j = 4; j != 0; --j )
  {
    digest[v14] = v15->state[0];
    digest[v14 + 1] = BYTE2(v15->state[0]);
    digest[v14 + 2] = BYTE1(v15->state[0]);
    digest[v14 + 3] = HIBYTE(v15->state[0]);
    v15 = (MD5_CTX *)((char *)v15 + 4);
    v14 += 4;
  }
  memset(Dst: context, Val: 0, Size: sizeof(MD5_CTX));
}


// ========================================================================
// ?MD5_BlockChecksum@@YAIPBXI@Z
// EA  : 0x82F2CAB8
// RVA : 0x00F2CAB8
// PDB : w:\tech5\shared\idlib\hashing\md5.cpp
// ========================================================================

int __fastcall MD5_BlockChecksum(const unsigned __int8 *data, unsigned int length)
{
  unsigned __int8 v3[16]; // [sp+50h] [-70h] BYREF
  MD5_CTX v4; // [sp+60h] [-60h] BYREF

  v4.state[1] = -271733879;
  v4.state[0] = 1732584193;
  v4.bits[0] = 0;
  v4.state[2] = -1732584194;
  v4.state[3] = 271733878;
  v4.bits[1] = 0;
  MD5_Update(context: &v4, input: data, inputLen: length);
  MD5_Final(context: &v4, digest: v3);
  return (((((unsigned __int16)((v3[15] << 8) | v3[14]) << 8) | v3[13]) << 8) | v3[12])
       ^ (((((unsigned __int16)((v3[11] << 8) | v3[10]) << 8) | v3[9]) << 8) | v3[8])
       ^ (((((unsigned __int16)((v3[7] << 8) | v3[6]) << 8) | v3[5]) << 8) | v3[4])
       ^ (((((unsigned __int16)((v3[3] << 8) | v3[2]) << 8) | v3[1]) << 8) | v3[0]);
}

