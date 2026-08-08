
// ========================================================================
// inflate_table
// EA  : 0x83224E10
// RVA : 0x01224E10
// PDB : w:\tech5\libs\zlib\inftrees.c
// ========================================================================

int __fastcall inflate_table(
        codetype type,
        unsigned __int16 *lens,
        unsigned int codes,
        code **table,
        unsigned int *bits,
        unsigned __int16 *work)
{
  _WORD *v6; // r10
  int i; // ctr
  unsigned __int16 *v8; // r9
  unsigned int j; // ctr
  int v10; // r10
  unsigned int v11; // r14
  unsigned int v12; // r16
  _WORD *v13; // r11
  code *v15; // r11
  char *v16; // r11
  unsigned int v17; // r28
  int v18; // r10
  unsigned int v19; // r9
  unsigned __int16 *v20; // r11
  int v21; // r11
  int k; // ctr
  __int16 v23; // r10
  __int16 v24; // r9
  unsigned __int16 v25; // r31
  unsigned __int16 *v26; // r11
  unsigned int m; // ctr
  int v28; // r9
  int v29; // r23
  const unsigned __int16 *v30; // r18
  const unsigned __int16 *v31; // r19
  code *v32; // r26
  unsigned int v33; // r30
  unsigned int v34; // r27
  int v35; // r25
  int v36; // r29
  unsigned int v37; // r17
  int v38; // r15
  unsigned __int16 *v39; // r24
  int v40; // r11
  int v41; // r10
  int v42; // r11
  unsigned int n; // r11
  int v44; // r9
  int v45; // r31
  unsigned __int8 v46; // r11
  unsigned int v47; // r10
  int v48; // r8
  unsigned __int16 *v49; // r9
  int v50; // r8
  unsigned int v51; // r11
  code v52; // [sp+0h] [-F0h]
  code v53; // [sp+0h] [-F0h]
  _BYTE back_chain[4]; // [sp+Eh] [-E2h] BYREF
  _BYTE v55[2]; // [sp+12h] [-DEh] BYREF
  char v56; // [sp+14h] [-DCh] BYREF
  _BYTE v57[4]; // [sp+2Eh] [-C2h] BYREF
  _WORD v58[95]; // [sp+32h] [-BEh] BYREF

  v6 = back_chain;
  for ( i = 16; i != 0; --i )
    *++v6 = 0;
  if ( codes != 0 )
  {
    v8 = lens - 1;
    for ( j = codes; j != 0; --j )
    {
      v10 = __ROL4__(*++v8, 1);
      ++*(_WORD *)&back_chain[v10 + 2];
    }
  }
  v11 = *bits;
  v12 = 15;
  v13 = v57;
  do
  {
    if ( *v13 != 0 )
      break;
    --v12;
    --v13;
  }
  while ( v12 != 0 );
  if ( v11 > v12 )
    v11 = v12;
  if ( v12 == 0 )
  {
    **table = (code)1073807360;
    v15 = *table + 1;
    *table = v15;
    *v15 = (code)1073807360;
    ++*table;
    *bits = 1;
    return 0;
  }
  v16 = &v56;
  v17 = 1;
  while ( *((_WORD *)v16 - 1) == 0 )
  {
    if ( *(_WORD *)v16 != 0 )
    {
      ++v17;
      break;
    }
    if ( *((_WORD *)v16 + 1) != 0 )
    {
      v17 += 2;
      break;
    }
    if ( *((_WORD *)v16 + 2) != 0 )
    {
      v17 += 3;
      break;
    }
    if ( *((_WORD *)v16 + 3) != 0 )
    {
      v17 += 4;
      break;
    }
    v17 += 5;
    v16 += 10;
    if ( v17 > 0xF )
      break;
  }
  if ( v11 < v17 )
    v11 = v17;
  v18 = 1;
  v19 = 1;
  v20 = (unsigned __int16 *)v55;
  do
  {
    v18 = 2 * v18 - *v20;
    if ( v18 < 0 )
      return -1;
    ++v19;
    ++v20;
  }
  while ( v19 <= 0xF );
  if ( v18 > 0 && (type == CODES || v12 != 1) )
    return -1;
  v58[0] = 0;
  v21 = 1;
  for ( k = 7; k != 0; --k )
  {
    v23 = *(_WORD *)&v57[v21 * 2 + 2] + *(_WORD *)&back_chain[v21 * 2 + 2];
    v24 = *(_WORD *)&v55[v21 * 2] + v23;
    v58[v21] = v23;
    v58[v21 + 1] = v24;
    v21 += 2;
  }
  v25 = 0;
  if ( codes != 0 )
  {
    v26 = lens;
    for ( m = codes; m != 0; --m )
    {
      if ( *v26 != 0 )
      {
        *(unsigned __int16 *)((char *)work + __ROL4__(*(unsigned __int16 *)&v57[__ROL4__(*v26, 1) + 2], 1)) = v25;
        v28 = __ROL4__(*v26, 1);
        ++*(_WORD *)&v57[v28 + 2];
      }
      ++v25;
      ++v26;
    }
  }
  if ( type != CODES )
  {
    if ( type == LENS )
    {
      v29 = 256;
      v30 = (const unsigned __int16 *)"-2.4.1\\src\\google\\protobuf\\stubs\\common.cc";
      v31 = (const unsigned __int16 *)&unk_8240A7DE;
    }
    else
    {
      v29 = -1;
      v30 = dbase;
      v31 = dext;
    }
  }
  else
  {
    v31 = work;
    v30 = work;
    v29 = 19;
  }
  v32 = *table;
  v33 = 0;
  v34 = 0;
  v35 = -1;
  v36 = 1 << v11;
  v37 = 1 << v11;
  v38 = (1 << v11) - 1;
  if ( type == LENS && (unsigned int)(1 << v11) >= 0x5B0 )
    return 1;
  v39 = work;
  while ( 1 )
  {
    v40 = *v39;
    if ( v40 >= v29 )
    {
      if ( v40 <= v29 )
      {
        v52.op = 96;
        v52.val = 0;
      }
      else
      {
        v41 = __ROL4__(*v39, 1);
        v52.op = *(const unsigned __int16 *)((char *)v31 + v41);
        v52.val = *(const unsigned __int16 *)((char *)v30 + v41);
      }
    }
    else
    {
      v52.val = *v39;
      v52.op = 0;
    }
    v42 = v36;
    do
    {
      v42 -= 1 << (v17 - v34);
      v52.bits = v17 - v34;
      v32[(v33 >> v34) + v42] = v52;
    }
    while ( v42 != 0 );
    for ( n = 1 << (v17 - 1); (n & v33) != 0; n >>= 1 )
      ;
    if ( n != 0 )
      v33 = ((n - 1) & v33) + n;
    else
      v33 = 0;
    ++v39;
    v44 = (unsigned __int16)(*(_WORD *)&back_chain[2 * v17 + 2] - 1);
    *(_WORD *)&back_chain[2 * v17 + 2] = v44;
    if ( v44 == 0 )
    {
      if ( v17 == v12 )
        break;
      v17 = *(unsigned __int16 *)((char *)lens + __ROL4__(*v39, 1));
    }
    if ( v17 > v11 )
    {
      v45 = v38 & v33;
      if ( (v38 & v33) != v35 )
      {
        if ( v34 == 0 )
          v34 = v11;
        v46 = v17 - v34;
        v47 = v17;
        v32 += v36;
        v48 = 1 << (v17 - v34);
        if ( v17 < v12 )
        {
          v49 = (unsigned __int16 *)&back_chain[2 * v17 + 2];
          do
          {
            v50 = v48 - *v49;
            if ( v50 <= 0 )
              break;
            ++v47;
            ++v46;
            ++v49;
            v48 = 2 * v50;
          }
          while ( v47 < v12 );
        }
        v36 = 1 << v46;
        v37 += 1 << v46;
        if ( type == LENS && v37 >= 0x5B0 )
          return 1;
        v35 = v38 & v33;
        (*table)[v45].op = v46;
        (*table)[v45].bits = v11;
        (*table)[v45].val = v32 - *table;
      }
    }
  }
  v53.bits = v17 - v34;
  v53.val = 0;
  for ( v53.op = 64; v33 != 0; v33 = ((v51 - 1) & v33) + v51 )
  {
    if ( v34 != 0 && (v38 & v33) != v35 )
    {
      v32 = *table;
      v34 = 0;
      v53.bits = v11;
      LOBYTE(v17) = v11;
    }
    v51 = 1 << (v17 - 1);
    for ( v32[v33 >> v34] = v53; (v51 & v33) != 0; v51 >>= 1 )
      ;
    if ( v51 == 0 )
      break;
  }
  *table += v37;
  *bits = v11;
  return 0;
}

