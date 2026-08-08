
// ========================================================================
// adler32
// EA  : 0x83225348
// RVA : 0x01225348
// PDB : w:\tech5\libs\zlib\adler32.c
// ========================================================================

unsigned int __fastcall adler32(unsigned int adler, const unsigned __int8 *buf, unsigned int len)
{
  unsigned int v3; // r10
  unsigned int v4; // r11
  unsigned int v6; // ctr
  const unsigned __int8 *v7; // r9
  unsigned int v8; // r25
  int i; // ctr
  unsigned int v10; // r11
  unsigned int v11; // r10
  unsigned int v12; // r11
  int v13; // r26
  int v14; // r27
  unsigned int v15; // r10
  int v16; // r28
  unsigned int v17; // r11
  int v18; // r29
  int v19; // r30
  unsigned int v20; // r10
  int v21; // r31
  unsigned int v22; // r11
  int v23; // r3
  int v24; // r6
  unsigned int v25; // r10
  int v26; // r7
  unsigned int v27; // r11
  int v28; // r8
  int v29; // r9
  unsigned int v30; // r10
  int v31; // r11
  int v32; // r10
  int v33; // r11
  int v34; // r10
  int v35; // r11
  int v36; // r10
  int v37; // r11
  int v38; // r10
  int v39; // r11
  int v40; // r10
  int v41; // r11
  int v42; // r10
  int v43; // r11
  int v44; // r10
  int v45; // r11
  int v46; // r10
  int v47; // r11
  int v48; // r10
  int v49; // r11
  int v50; // r10
  unsigned int v51; // ctr
  unsigned int v52; // r11
  unsigned int v53; // r10
  unsigned int v54; // r11
  int v55; // r26
  int v56; // r27
  unsigned int v57; // r10
  int v58; // r28
  unsigned int v59; // r11
  int v60; // r29
  int v61; // r30
  unsigned int v62; // r10
  int v63; // r31
  unsigned int v64; // r11
  int v65; // r3
  int v66; // r6
  unsigned int v67; // r10
  int v68; // r7
  unsigned int v69; // r11
  int v70; // r8
  int v71; // r9
  unsigned int v72; // r10
  int v73; // r11
  int v74; // r10
  int v75; // r11
  int v76; // r10
  int v77; // r11
  int v78; // r10
  int v79; // r11
  int v80; // r10
  int v81; // r11
  int v82; // r10
  int v83; // r11
  int v84; // r10
  int v85; // r11
  int v86; // r10
  int v87; // r11
  int v88; // r10
  int v89; // r11
  int v90; // r10
  int v91; // r11
  int v92; // r10
  unsigned int v93; // ctr
  const unsigned __int8 *v94; // r9

  v3 = HIWORD(adler);
  v4 = (unsigned __int16)adler;
  if ( len == 1 )
  {
    v4 = *buf + (unsigned __int16)adler;
    if ( v4 >= 0xFFF1 )
      v4 -= 65521;
    v3 += v4;
    if ( v3 >= 0xFFF1 )
      return ((v3 - 65521) << 16) | v4;
    return (v3 << 16) | v4;
  }
  if ( buf == nullptr )
    return 1;
  if ( len >= 0x10 )
  {
    if ( len >= 0x15B0 )
    {
      v8 = len / 0x15B0;
      do
      {
        len -= 5552;
        for ( i = 347; i != 0; --i )
        {
          v10 = *buf + v4;
          v11 = v3 + v10;
          v12 = buf[1] + v10;
          v13 = buf[5];
          v14 = buf[6];
          v15 = v11 + v12;
          v16 = buf[7];
          v17 = buf[2] + v12;
          v18 = buf[8];
          v19 = buf[9];
          v20 = v15 + v17;
          v21 = buf[10];
          v22 = buf[3] + v17;
          v23 = buf[11];
          v24 = buf[12];
          v25 = v20 + v22;
          v26 = buf[13];
          v27 = buf[4] + v22;
          v28 = buf[14];
          v29 = buf[15];
          buf += 16;
          v30 = v25 + v27;
          v31 = v13 + v27;
          v32 = v30 + v31;
          v33 = v14 + v31;
          v34 = v32 + v33;
          v35 = v16 + v33;
          v36 = v34 + v35;
          v37 = v18 + v35;
          v38 = v36 + v37;
          v39 = v19 + v37;
          v40 = v38 + v39;
          v41 = v21 + v39;
          v42 = v40 + v41;
          v43 = v23 + v41;
          v44 = v42 + v43;
          v45 = v24 + v43;
          v46 = v44 + v45;
          v47 = v26 + v45;
          v48 = v46 + v47;
          v49 = v28 + v47;
          v50 = v48 + v49;
          v4 = v29 + v49;
          v3 = v50 + v4;
        }
        --v8;
        v4 %= 0xFFF1u;
        v3 %= 0xFFF1u;
      }
      while ( v8 != 0 );
    }
    if ( len != 0 )
    {
      if ( len >= 0x10 )
      {
        v51 = len >> 4;
        do
        {
          len -= 16;
          v52 = *buf + v4;
          v53 = v3 + v52;
          v54 = buf[1] + v52;
          v55 = buf[5];
          v56 = buf[6];
          v57 = v53 + v54;
          v58 = buf[7];
          v59 = buf[2] + v54;
          v60 = buf[8];
          v61 = buf[9];
          v62 = v57 + v59;
          v63 = buf[10];
          v64 = buf[3] + v59;
          v65 = buf[11];
          v66 = buf[12];
          v67 = v62 + v64;
          v68 = buf[13];
          v69 = buf[4] + v64;
          v70 = buf[14];
          v71 = buf[15];
          buf += 16;
          v72 = v67 + v69;
          v73 = v55 + v69;
          v74 = v72 + v73;
          v75 = v56 + v73;
          v76 = v74 + v75;
          v77 = v58 + v75;
          v78 = v76 + v77;
          v79 = v60 + v77;
          v80 = v78 + v79;
          v81 = v61 + v79;
          v82 = v80 + v81;
          v83 = v63 + v81;
          v84 = v82 + v83;
          v85 = v65 + v83;
          v86 = v84 + v85;
          v87 = v66 + v85;
          v88 = v86 + v87;
          v89 = v68 + v87;
          v90 = v88 + v89;
          v91 = v70 + v89;
          v92 = v90 + v91;
          v4 = v71 + v91;
          v3 = v92 + v4;
          --v51;
        }
        while ( v51 != 0 );
      }
      if ( len != 0 )
      {
        v93 = len;
        v94 = buf - 1;
        do
        {
          v4 += *++v94;
          v3 += v4;
          --v93;
        }
        while ( v93 != 0 );
      }
      v4 %= 0xFFF1u;
      v3 %= 0xFFF1u;
    }
    return (v3 << 16) | v4;
  }
  if ( len != 0 )
  {
    v6 = len;
    v7 = buf - 1;
    do
    {
      v4 += *++v7;
      v3 += v4;
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( v4 >= 0xFFF1 )
    v4 -= 65521;
  return ((v3 % 0xFFF1) << 16) | v4;
}

