
// ========================================================================
// ?Sort@?$idSort_Quick@V?$idIndex@FW4invalidLayerIndex_t@idDeclAnimWeb@@@@VidSort_LayerName@@@@UBAXPAV?$idIndex@FW4invalidLayerIndex_t@idDeclAnimWeb@@@@I@Z
// EA  : 0x825FF208
// RVA : 0x005FF208
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t>,idSort_LayerName>::Sort(
        idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t>,idSort_LayerName> *this,
        idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t> *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r21
  int v10; // r25
  int v11; // r22 OVERLAPPED
  __int64 v12; // r24
  _BYTE v13[12]; // r30 OVERLAPPED
  int v14; // r27
  __int128 v15; // r11
  idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t> *v16; // r27
  __int16 v17; // r9
  idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t> *j; // r27
  __int16 v19; // r9
  int v20; // r28
  int i; // r30
  __int16 value; // r8
  _QWORD v23[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v23[0] = v7;
    v23[128] = a7;
    do
    {
      v10 = v7;
      *(_QWORD *)(&v11 - 1) = v23[(_DWORD)v7];
      v12 = *(_QWORD *)(8 * v7 + v11);
      *(_DWORD *)&v13[4] = HIDWORD(v12);
      v14 = *(_DWORD *)(8 * v7 + v11 + 4);
      if ( (int)v12 - HIDWORD(v12) < 4 || (int)v7 >= 127 )
      {
        for ( ; v14 > SHIDWORD(v12); --v14 )
        {
          v20 = HIDWORD(v12);
          for ( i = HIDWORD(v12) + 1; i <= v14; ++i )
          {
            if ( idSort_LayerName::Compare((idSort_LayerName *)this, li1: &base[i], li2: &base[v20]) > 0 )
              v20 = i;
          }
          value = base[v20].value;
          base[v20] = base[v14];
          base[v14].value = value;
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v15) = v12 + HIDWORD(v12);
        DWORD2(v15) = 2 * v12;
        *(_DWORD *)v13 = &base[v12];
        LODWORD(v15) = ((unsigned __int64)v15 >> 63) + v12 + HIDWORD(v12);
        *(_DWORD *)&v13[8] = v12 - 1;
        *(_QWORD *)((char *)&v15 + 4) = (__int64)v15 >> 1;
        WORD3(v15) = **(_WORD **)v13;
        **(_WORD **)v13 = base[DWORD2(v15)].value;
        base[DWORD2(v15)] = *(idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t> *)((char *)&v15 + 6);
        while ( 1 )
        {
          if ( idSort_LayerName::Compare((idSort_LayerName *)this, li1: &base[*(_DWORD *)&v13[4]], li2: &base[v12]) < 0 )
          {
            do
              ++*(_DWORD *)&v13[4];
            while ( *(int *)&v13[4] < *(int *)&v13[8]
                 && idSort_LayerName::Compare((idSort_LayerName *)this, li1: &base[*(_DWORD *)&v13[4]], li2: &base[v12]) < 0 );
          }
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_LayerName::Compare((idSort_LayerName *)this, li1: v16, li2: &base[v12]) > 0 )
            break;
LABEL_12:
          if ( *(int *)&v13[4] < *(int *)&v13[8] )
          {
            --*(_DWORD *)&v13[8];
            v17 = base[*(_DWORD *)&v13[4]].value;
            base[(*(_DWORD *)&v13[4])++] = (idIndex<short,enum idDeclAnimWeb::invalidLayerIndex_t>)v16->value;
            v16->value = v17;
            if ( *(int *)&v13[4] < *(int *)&v13[8] )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --*(_DWORD *)&v13[8];
          if ( *(int *)&v13[8] <= *(int *)&v13[4] )
            break;
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_LayerName::Compare((idSort_LayerName *)this, li1: v16, li2: &base[v12]) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = &base[*(_DWORD *)&v13[4]];
              idSort_LayerName::Compare((idSort_LayerName *)this, li1: j, li2: &base[v12]) <= 0;
              j = &base[*(_DWORD *)&v13[4]] )
        {
          if ( *(int *)&v13[4] >= (int)v12 )
            break;
          ++*(_DWORD *)&v13[4];
        }
        for ( ;
              idSort_LayerName::Compare((idSort_LayerName *)this, li1: &base[*(_DWORD *)&v13[8]], li2: &base[v12]) >= 0;
              --*(_DWORD *)&v13[8] )
        {
          if ( SHIDWORD(v12) >= *(int *)&v13[8] )
            break;
        }
        v19 = **(_WORD **)v13;
        LODWORD(v7) = v7 + 1;
        **(_WORD **)v13 = j->value;
        v23[v10 + 129] = v12;
        j->value = v19;
        v23[v10 + 1] = *(_QWORD *)v13;
        *(_QWORD *)(v10 * 8 + v11) = *(_QWORD *)&v13[4];
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@VidSort_SubWebName@@@@UBAXPAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@I@Z
// EA  : 0x825FF498
// RVA : 0x005FF498
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,idSort_SubWebName>::Sort(
        idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,idSort_SubWebName> *this,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r21
  int v10; // r25
  int v11; // r22 OVERLAPPED
  __int64 v12; // r24
  _BYTE v13[12]; // r30 OVERLAPPED
  int v14; // r27
  __int128 v15; // r11
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v16; // r27
  __int16 v17; // r9
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *j; // r27
  __int16 v19; // r9
  int v20; // r28
  int i; // r30
  __int16 value; // r8
  _QWORD v23[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v23[0] = v7;
    v23[128] = a7;
    do
    {
      v10 = v7;
      *(_QWORD *)(&v11 - 1) = v23[(_DWORD)v7];
      v12 = *(_QWORD *)(8 * v7 + v11);
      *(_DWORD *)&v13[4] = HIDWORD(v12);
      v14 = *(_DWORD *)(8 * v7 + v11 + 4);
      if ( (int)v12 - HIDWORD(v12) < 4 || (int)v7 >= 127 )
      {
        for ( ; v14 > SHIDWORD(v12); --v14 )
        {
          v20 = HIDWORD(v12);
          for ( i = HIDWORD(v12) + 1; i <= v14; ++i )
          {
            if ( idSort_SubWebName::Compare((idSort_SubWebName *)this, sw1: &base[i], sw2: &base[v20]) > 0 )
              v20 = i;
          }
          value = base[v20].value;
          base[v20] = base[v14];
          base[v14].value = value;
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v15) = v12 + HIDWORD(v12);
        DWORD2(v15) = 2 * v12;
        *(_DWORD *)v13 = &base[v12];
        LODWORD(v15) = ((unsigned __int64)v15 >> 63) + v12 + HIDWORD(v12);
        *(_DWORD *)&v13[8] = v12 - 1;
        *(_QWORD *)((char *)&v15 + 4) = (__int64)v15 >> 1;
        WORD3(v15) = **(_WORD **)v13;
        **(_WORD **)v13 = base[DWORD2(v15)].value;
        base[DWORD2(v15)] = *(idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)((char *)&v15 + 6);
        while ( 1 )
        {
          if ( idSort_SubWebName::Compare((idSort_SubWebName *)this, sw1: &base[*(_DWORD *)&v13[4]], sw2: &base[v12]) < 0 )
          {
            do
              ++*(_DWORD *)&v13[4];
            while ( *(int *)&v13[4] < *(int *)&v13[8]
                 && idSort_SubWebName::Compare(
                      (idSort_SubWebName *)this,
                      sw1: &base[*(_DWORD *)&v13[4]],
                      sw2: &base[v12]) < 0 );
          }
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_SubWebName::Compare((idSort_SubWebName *)this, sw1: v16, sw2: &base[v12]) > 0 )
            break;
LABEL_12:
          if ( *(int *)&v13[4] < *(int *)&v13[8] )
          {
            --*(_DWORD *)&v13[8];
            v17 = base[*(_DWORD *)&v13[4]].value;
            base[(*(_DWORD *)&v13[4])++] = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>)v16->value;
            v16->value = v17;
            if ( *(int *)&v13[4] < *(int *)&v13[8] )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --*(_DWORD *)&v13[8];
          if ( *(int *)&v13[8] <= *(int *)&v13[4] )
            break;
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_SubWebName::Compare((idSort_SubWebName *)this, sw1: v16, sw2: &base[v12]) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = &base[*(_DWORD *)&v13[4]];
              idSort_SubWebName::Compare((idSort_SubWebName *)this, sw1: j, sw2: &base[v12]) <= 0;
              j = &base[*(_DWORD *)&v13[4]] )
        {
          if ( *(int *)&v13[4] >= (int)v12 )
            break;
          ++*(_DWORD *)&v13[4];
        }
        for ( ;
              idSort_SubWebName::Compare((idSort_SubWebName *)this, sw1: &base[*(_DWORD *)&v13[8]], sw2: &base[v12]) >= 0;
              --*(_DWORD *)&v13[8] )
        {
          if ( SHIDWORD(v12) >= *(int *)&v13[8] )
            break;
        }
        v19 = **(_WORD **)v13;
        LODWORD(v7) = v7 + 1;
        **(_WORD **)v13 = j->value;
        v23[v10 + 129] = v12;
        j->value = v19;
        v23[v10 + 1] = *(_QWORD *)v13;
        *(_QWORD *)(v10 * 8 + v11) = *(_QWORD *)&v13[4];
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@VidSort_StateName@@@@UBAXPAV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@I@Z
// EA  : 0x825FFA78
// RVA : 0x005FFA78
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idSort_StateName>::Sort(
        idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idSort_StateName> *this,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r21
  int v10; // r25
  int v11; // r22 OVERLAPPED
  __int64 v12; // r24
  _BYTE v13[12]; // r30 OVERLAPPED
  int v14; // r27
  __int128 v15; // r11
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v16; // r27
  __int16 v17; // r9
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *j; // r27
  __int16 v19; // r9
  int v20; // r28
  int i; // r30
  __int16 value; // r8
  _QWORD v23[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v23[0] = v7;
    v23[128] = a7;
    do
    {
      v10 = v7;
      *(_QWORD *)(&v11 - 1) = v23[(_DWORD)v7];
      v12 = *(_QWORD *)(8 * v7 + v11);
      *(_DWORD *)&v13[4] = HIDWORD(v12);
      v14 = *(_DWORD *)(8 * v7 + v11 + 4);
      if ( (int)v12 - HIDWORD(v12) < 4 || (int)v7 >= 127 )
      {
        for ( ; v14 > SHIDWORD(v12); --v14 )
        {
          v20 = HIDWORD(v12);
          for ( i = HIDWORD(v12) + 1; i <= v14; ++i )
          {
            if ( idSort_StateName::Compare((idSort_StateName *)this, ni1: &base[i], ni2: &base[v20]) > 0 )
              v20 = i;
          }
          value = base[v20].value;
          base[v20] = base[v14];
          base[v14].value = value;
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v15) = v12 + HIDWORD(v12);
        DWORD2(v15) = 2 * v12;
        *(_DWORD *)v13 = &base[v12];
        LODWORD(v15) = ((unsigned __int64)v15 >> 63) + v12 + HIDWORD(v12);
        *(_DWORD *)&v13[8] = v12 - 1;
        *(_QWORD *)((char *)&v15 + 4) = (__int64)v15 >> 1;
        WORD3(v15) = **(_WORD **)v13;
        **(_WORD **)v13 = base[DWORD2(v15)].value;
        base[DWORD2(v15)] = *(idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)((char *)&v15 + 6);
        while ( 1 )
        {
          if ( idSort_StateName::Compare((idSort_StateName *)this, ni1: &base[*(_DWORD *)&v13[4]], ni2: &base[v12]) < 0 )
          {
            do
              ++*(_DWORD *)&v13[4];
            while ( *(int *)&v13[4] < *(int *)&v13[8]
                 && idSort_StateName::Compare((idSort_StateName *)this, ni1: &base[*(_DWORD *)&v13[4]], ni2: &base[v12]) < 0 );
          }
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_StateName::Compare((idSort_StateName *)this, ni1: v16, ni2: &base[v12]) > 0 )
            break;
LABEL_12:
          if ( *(int *)&v13[4] < *(int *)&v13[8] )
          {
            --*(_DWORD *)&v13[8];
            v17 = base[*(_DWORD *)&v13[4]].value;
            base[(*(_DWORD *)&v13[4])++] = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>)v16->value;
            v16->value = v17;
            if ( *(int *)&v13[4] < *(int *)&v13[8] )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --*(_DWORD *)&v13[8];
          if ( *(int *)&v13[8] <= *(int *)&v13[4] )
            break;
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_StateName::Compare((idSort_StateName *)this, ni1: v16, ni2: &base[v12]) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = &base[*(_DWORD *)&v13[4]];
              idSort_StateName::Compare((idSort_StateName *)this, ni1: j, ni2: &base[v12]) <= 0;
              j = &base[*(_DWORD *)&v13[4]] )
        {
          if ( *(int *)&v13[4] >= (int)v12 )
            break;
          ++*(_DWORD *)&v13[4];
        }
        for ( ;
              idSort_StateName::Compare((idSort_StateName *)this, ni1: &base[*(_DWORD *)&v13[8]], ni2: &base[v12]) >= 0;
              --*(_DWORD *)&v13[8] )
        {
          if ( SHIDWORD(v12) >= *(int *)&v13[8] )
            break;
        }
        v19 = **(_WORD **)v13;
        LODWORD(v7) = v7 + 1;
        **(_WORD **)v13 = j->value;
        v23[v10 + 129] = v12;
        j->value = v19;
        v23[v10 + 1] = *(_QWORD *)v13;
        *(_QWORD *)(v10 * 8 + v11) = *(_QWORD *)&v13[4];
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@V?$idIndex@FW4invalidEdgeIndex_t@idDeclAnimWeb@@@@VidSort_EdgeDestName@@@@UBAXPAV?$idIndex@FW4invalidEdgeIndex_t@idDeclAnimWeb@@@@I@Z
// EA  : 0x82606A50
// RVA : 0x00606A50
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,idSort_EdgeDestName>::Sort(
        idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,idSort_EdgeDestName> *this,
        idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r21
  int v10; // r25
  int v11; // r22 OVERLAPPED
  __int64 v12; // r24
  _BYTE v13[12]; // r30 OVERLAPPED
  int v14; // r27
  __int128 v15; // r11
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *v16; // r27
  __int16 v17; // r9
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *j; // r27
  __int16 v19; // r9
  int v20; // r28
  int i; // r30
  __int16 value; // r8
  _QWORD v23[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v23[0] = v7;
    v23[128] = a7;
    do
    {
      v10 = v7;
      *(_QWORD *)(&v11 - 1) = v23[(_DWORD)v7];
      v12 = *(_QWORD *)(8 * v7 + v11);
      *(_DWORD *)&v13[4] = HIDWORD(v12);
      v14 = *(_DWORD *)(8 * v7 + v11 + 4);
      if ( (int)v12 - HIDWORD(v12) < 4 || (int)v7 >= 127 )
      {
        for ( ; v14 > SHIDWORD(v12); --v14 )
        {
          v20 = HIDWORD(v12);
          for ( i = HIDWORD(v12) + 1; i <= v14; ++i )
          {
            if ( idSort_EdgeDestName::Compare((idSort_EdgeDestName *)this, ei1: &base[i], ei2: &base[v20]) > 0 )
              v20 = i;
          }
          value = base[v20].value;
          base[v20] = base[v14];
          base[v14].value = value;
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v15) = v12 + HIDWORD(v12);
        DWORD2(v15) = 2 * v12;
        *(_DWORD *)v13 = &base[v12];
        LODWORD(v15) = ((unsigned __int64)v15 >> 63) + v12 + HIDWORD(v12);
        *(_DWORD *)&v13[8] = v12 - 1;
        *(_QWORD *)((char *)&v15 + 4) = (__int64)v15 >> 1;
        WORD3(v15) = **(_WORD **)v13;
        **(_WORD **)v13 = base[DWORD2(v15)].value;
        base[DWORD2(v15)] = *(idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *)((char *)&v15 + 6);
        while ( 1 )
        {
          if ( idSort_EdgeDestName::Compare(
                 (idSort_EdgeDestName *)this,
                 ei1: &base[*(_DWORD *)&v13[4]],
                 ei2: &base[v12]) < 0 )
          {
            do
              ++*(_DWORD *)&v13[4];
            while ( *(int *)&v13[4] < *(int *)&v13[8]
                 && idSort_EdgeDestName::Compare(
                      (idSort_EdgeDestName *)this,
                      ei1: &base[*(_DWORD *)&v13[4]],
                      ei2: &base[v12]) < 0 );
          }
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_EdgeDestName::Compare((idSort_EdgeDestName *)this, ei1: v16, ei2: &base[v12]) > 0 )
            break;
LABEL_12:
          if ( *(int *)&v13[4] < *(int *)&v13[8] )
          {
            --*(_DWORD *)&v13[8];
            v17 = base[*(_DWORD *)&v13[4]].value;
            base[(*(_DWORD *)&v13[4])++] = (idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>)v16->value;
            v16->value = v17;
            if ( *(int *)&v13[4] < *(int *)&v13[8] )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --*(_DWORD *)&v13[8];
          if ( *(int *)&v13[8] <= *(int *)&v13[4] )
            break;
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_EdgeDestName::Compare((idSort_EdgeDestName *)this, ei1: v16, ei2: &base[v12]) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = &base[*(_DWORD *)&v13[4]];
              idSort_EdgeDestName::Compare((idSort_EdgeDestName *)this, ei1: j, ei2: &base[v12]) <= 0;
              j = &base[*(_DWORD *)&v13[4]] )
        {
          if ( *(int *)&v13[4] >= (int)v12 )
            break;
          ++*(_DWORD *)&v13[4];
        }
        for ( ;
              idSort_EdgeDestName::Compare((idSort_EdgeDestName *)this, ei1: &base[*(_DWORD *)&v13[8]], ei2: &base[v12]) >= 0;
              --*(_DWORD *)&v13[8] )
        {
          if ( SHIDWORD(v12) >= *(int *)&v13[8] )
            break;
        }
        v19 = **(_WORD **)v13;
        LODWORD(v7) = v7 + 1;
        **(_WORD **)v13 = j->value;
        v23[v10 + 129] = v12;
        j->value = v19;
        v23[v10 + 1] = *(_QWORD *)v13;
        *(_QWORD *)(v10 * 8 + v11) = *(_QWORD *)&v13[4];
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ??$SwapValues@VidStr@@@@YAXAAVidStr@@0@Z
// EA  : 0x82629218
// RVA : 0x00629218
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<idStr>(idStr *a, idStr *b)
{
  int len; // r30
  int v5; // r30
  idStr v6[2]; // [sp+50h] [-50h] BYREF

  idStr::idStr(this: v6, text: a);
  len = b->len;
  idStr::EnsureAlloced(this: a, amount: b->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: a->data, Src: b->data, Size: len);
  a->data[len] = 0;
  a->len = len;
  v5 = v6[0].len;
  idStr::EnsureAlloced(this: b, amount: v6[0].len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: b->data, Src: v6[0].data, Size: v5);
  b->data[v5] = 0;
  b->len = v5;
  idStr::FreeData(this: v6);
}


// ========================================================================
// __unwind$219322
// EA  : 0x826292BC
// RVA : 0x006292BC
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_219322()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidStr@@V?$idSort_QuickDefault@VidStr@@@@@@UBAXPAVidStr@@I@Z
// EA  : 0x826292E8
// RVA : 0x006292E8
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idStr,idSort_QuickDefault<idStr>>::Sort(
        idSort_Quick<idStr,idSort_QuickDefault<idStr> > *this,
        idStr *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r30 OVERLAPPED
  int v8; // r21
  int v9; // r26
  __int64 v10; // r25
  int v11; // r31 OVERLAPPED
  __int64 v12; // r11
  const char **v13; // r27
  idStr *v14; // r28
  idStr *j; // r28
  int v16; // r27
  int i; // r28
  _BYTE v18[1016]; // [sp+58h] [-858h] BYREF
  _QWORD v19[140]; // [sp+450h] [-460h] BYREF

  HIDWORD(v7) = base;
  if ( num != 0 )
  {
    v8 = 0;
    LODWORD(a7) = num - 1;
    v19[0] = a7;
    do
    {
      v9 = v8;
      v10 = v19[v8];
      v11 = HIDWORD(v10);
      LODWORD(v7) = v19[v8];
      if ( (int)v10 - HIDWORD(v10) < 4 || v8 >= 127 )
      {
        for ( ; (int)v7 > SHIDWORD(v10); LODWORD(v7) = v7 - 1 )
        {
          v16 = HIDWORD(v10);
          for ( i = HIDWORD(v10) + 1; i <= (int)v7; ++i )
          {
            if ( idStr::Cmp(
                   s1: *(const char **)(32 * i + HIDWORD(v7) + 4),
                   s2: *(const char **)(32 * v16 + HIDWORD(v7) + 4)) > 0 )
              v16 = i;
          }
          SwapValues<idStr>(a: (idStr *)(32 * v16 + HIDWORD(v7)), b: (idStr *)(32 * v7 + HIDWORD(v7)));
        }
        --v8;
      }
      else
      {
        LODWORD(v12) = v10 + HIDWORD(v10);
        HIDWORD(v12) = 32 * v10;
        LODWORD(v12) = ((unsigned __int64)v12 >> 63) + v10 + HIDWORD(v10);
        SwapValues<idStr>(a: (idStr *)(32 * v10 + HIDWORD(v7)), b: (idStr *)(32 * (v12 >> 1) + HIDWORD(v7)));
        LODWORD(v7) = v7 - 1;
        v13 = (const char **)(32 * v10 + HIDWORD(v7) + 4);
        while ( 1 )
        {
          if ( idStr::Cmp(s1: *(const char **)(32 * v11 + HIDWORD(v7) + 4), s2: *v13) < 0 )
          {
            do
              ++v11;
            while ( v11 < (int)v7 && idStr::Cmp(s1: *(const char **)(32 * v11 + HIDWORD(v7) + 4), s2: *v13) < 0 );
          }
          v14 = (idStr *)(32 * v7 + HIDWORD(v7));
          if ( idStr::Cmp(s1: v14->data, s2: *v13) > 0 )
            break;
LABEL_12:
          if ( v11 < (int)v7 )
          {
            SwapValues<idStr>(a: (idStr *)(32 * v11++ + HIDWORD(v7)), b: v14);
            LODWORD(v7) = v7 - 1;
            if ( v11 < (int)v7 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v7) = v7 - 1;
          if ( (int)v7 <= v11 )
            break;
          v14 = (idStr *)(32 * v7 + HIDWORD(v7));
          if ( idStr::Cmp(s1: v14->data, s2: *v13) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = (idStr *)(32 * v11 + HIDWORD(v7));
              idStr::Cmp(s1: j->data, s2: *v13) <= 0;
              j = (idStr *)(32 * v11 + HIDWORD(v7)) )
        {
          if ( v11 >= (int)v10 )
            break;
          ++v11;
        }
        for ( ; idStr::Cmp(s1: *(const char **)(32 * v7 + HIDWORD(v7) + 4), s2: *v13) >= 0; LODWORD(v7) = v7 - 1 )
        {
          if ( SHIDWORD(v10) >= (int)v7 )
            break;
        }
        SwapValues<idStr>(a: (idStr *)(32 * v10 + HIDWORD(v7)), b: j);
        ++v8;
        v19[v9 + 1] = v10;
        *(_QWORD *)&v18[v9 * 8] = *(__int64 *)((char *)&v7 - 4);
        v19[v9] = v7;
      }
    }
    while ( v8 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidStr@@VidSort_vtr@@@@UBAXPAVidStr@@I@Z
// EA  : 0x8262D5E0
// RVA : 0x0062D5E0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idStr,idSort_vtr>::Sort(
        idSort_Quick<idStr,idSort_vtr> *this,
        idStr *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r30 OVERLAPPED
  int v8; // r21
  int v9; // r26
  __int64 v10; // r25
  int v11; // r31 OVERLAPPED
  __int64 v12; // r11
  const char **v13; // r27
  idStr *v14; // r28
  idStr *j; // r28
  int v16; // r27
  int i; // r28
  _BYTE v18[1016]; // [sp+58h] [-858h] BYREF
  _QWORD v19[140]; // [sp+450h] [-460h] BYREF

  HIDWORD(v7) = base;
  if ( num != 0 )
  {
    v8 = 0;
    LODWORD(a7) = num - 1;
    v19[0] = a7;
    do
    {
      v9 = v8;
      v10 = v19[v8];
      v11 = HIDWORD(v10);
      LODWORD(v7) = v19[v8];
      if ( (int)v10 - HIDWORD(v10) < 4 || v8 >= 127 )
      {
        for ( ; (int)v7 > SHIDWORD(v10); LODWORD(v7) = v7 - 1 )
        {
          v16 = HIDWORD(v10);
          for ( i = HIDWORD(v10) + 1; i <= (int)v7; ++i )
          {
            if ( idStr::Cmp(
                   s1: *(const char **)(32 * i + HIDWORD(v7) + 4),
                   s2: *(const char **)(32 * v16 + HIDWORD(v7) + 4)) > 0 )
              v16 = i;
          }
          SwapValues<idStr>(a: (idStr *)(32 * v16 + HIDWORD(v7)), b: (idStr *)(32 * v7 + HIDWORD(v7)));
        }
        --v8;
      }
      else
      {
        LODWORD(v12) = v10 + HIDWORD(v10);
        HIDWORD(v12) = 32 * v10;
        LODWORD(v12) = ((unsigned __int64)v12 >> 63) + v10 + HIDWORD(v10);
        SwapValues<idStr>(a: (idStr *)(32 * v10 + HIDWORD(v7)), b: (idStr *)(32 * (v12 >> 1) + HIDWORD(v7)));
        LODWORD(v7) = v7 - 1;
        v13 = (const char **)(32 * v10 + HIDWORD(v7) + 4);
        while ( 1 )
        {
          if ( idStr::Cmp(s1: *(const char **)(32 * v11 + HIDWORD(v7) + 4), s2: *v13) < 0 )
          {
            do
              ++v11;
            while ( v11 < (int)v7 && idStr::Cmp(s1: *(const char **)(32 * v11 + HIDWORD(v7) + 4), s2: *v13) < 0 );
          }
          v14 = (idStr *)(32 * v7 + HIDWORD(v7));
          if ( idStr::Cmp(s1: v14->data, s2: *v13) > 0 )
            break;
LABEL_12:
          if ( v11 < (int)v7 )
          {
            SwapValues<idStr>(a: (idStr *)(32 * v11++ + HIDWORD(v7)), b: v14);
            LODWORD(v7) = v7 - 1;
            if ( v11 < (int)v7 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v7) = v7 - 1;
          if ( (int)v7 <= v11 )
            break;
          v14 = (idStr *)(32 * v7 + HIDWORD(v7));
          if ( idStr::Cmp(s1: v14->data, s2: *v13) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = (idStr *)(32 * v11 + HIDWORD(v7));
              idStr::Cmp(s1: j->data, s2: *v13) <= 0;
              j = (idStr *)(32 * v11 + HIDWORD(v7)) )
        {
          if ( v11 >= (int)v10 )
            break;
          ++v11;
        }
        for ( ; idStr::Cmp(s1: *(const char **)(32 * v7 + HIDWORD(v7) + 4), s2: *v13) >= 0; LODWORD(v7) = v7 - 1 )
        {
          if ( SHIDWORD(v10) >= (int)v7 )
            break;
        }
        SwapValues<idStr>(a: (idStr *)(32 * v10 + HIDWORD(v7)), b: j);
        ++v8;
        v19[v9 + 1] = v10;
        *(_QWORD *)&v18[v9 * 8] = *(__int64 *)((char *)&v7 - 4);
        v19[v9] = v7;
      }
    }
    while ( v8 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@VvtrEventHandle_t@@VidSort_EventTime@@@@UBAXPAVvtrEventHandle_t@@I@Z
// EA  : 0x826373B0
// RVA : 0x006373B0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<vtrEventHandle_t,idSort_EventTime>::Sort(
        idSort_Quick<vtrEventHandle_t,idSort_EventTime> *this,
        vtrEventHandle_t *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r21
  _BYTE v8[12]; // r30 OVERLAPPED
  int v10; // r25
  int v11; // r22 OVERLAPPED
  __int64 v12; // r24
  __int128 v13; // r11
  vtrEventHandle_t *v14; // r26
  const idVoiceEvent *v15; // r27
  const idVoiceEvent *v16; // r27
  vtrEventHandle_t *v17; // r27
  const idVoiceEvent *v18; // r20
  const idVoiceEvent *v19; // r20
  vtrEventHandle_t *v20; // r11
  vtrEventHandle_t v21; // r9
  vtrEventHandle_t *v22; // r27
  const idVoiceEvent *v23; // r20
  const idVoiceEvent *v24; // r20
  const idVoiceEvent *v25; // r20
  const idVoiceEvent *v26; // r20
  const vtrEventHandle_t *v27; // r9
  int v28; // r25
  int v29; // r26
  int v30; // r27
  int v31; // r11
  const idVoiceEvent *Event; // r24
  vtrEventHandle_t *v33; // r11
  vtrEventHandle_t *v34; // r10
  vtrEventHandle_t v35; // r8
  _QWORD v36[270]; // [sp+50h] [-870h] BYREF

  *(_DWORD *)v8 = this;
  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v36[0] = v7;
    v36[128] = a7;
    do
    {
      v10 = v7;
      *(_QWORD *)(&v11 - 1) = v36[(_DWORD)v7];
      v12 = *(_QWORD *)(8 * v7 + v11);
      *(_DWORD *)&v8[8] = HIDWORD(v12);
      *(_DWORD *)&v8[4] = *(_DWORD *)(8 * v7 + v11 + 4);
      if ( (int)v12 - HIDWORD(v12) < 4 || (int)v7 >= 127 )
      {
        if ( SHIDWORD(v12) < *(int *)&v8[4] )
        {
          v28 = HIDWORD(v12) + 1;
          do
          {
            v29 = HIDWORD(v12);
            v30 = HIDWORD(v12) + 1;
            if ( v28 <= *(int *)&v8[4] )
            {
              v31 = v28;
              do
              {
                Event = idVoiceEventManager::GetEvent(
                          this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                          handle: *(const vtrEventHandle_t **)&base[v31]);
                if ( Event->startMS
                   - idVoiceEventManager::GetEvent(
                       this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                       handle: *(const vtrEventHandle_t **)&base[v29])->startMS > 0 )
                  v29 = v30;
                v31 = ++v30;
              }
              while ( v30 <= *(int *)&v8[4] );
            }
            v33 = &base[*(_DWORD *)&v8[4]];
            v34 = &base[v29];
            --*(_DWORD *)&v8[4];
            v35 = *v34;
            v34->eventType = v33->eventType;
            v34->index = v33->index;
            *v33 = v35;
          }
          while ( *(int *)&v8[4] > SHIDWORD(v12) );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v13) = v12 + HIDWORD(v12);
        DWORD2(v13) = 4 * v12;
        v14 = &base[v12];
        LODWORD(v13) = ((unsigned __int64)v13 >> 63) + v12 + HIDWORD(v12);
        --*(_DWORD *)&v8[4];
        *(_QWORD *)((char *)&v13 + 4) = (__int64)v13 >> 1;
        DWORD1(v13) = *v14;
        LODWORD(v13) = &base[DWORD2(v13)];
        v14->eventType = *(_WORD *)v13;
        v14->index = *(_WORD *)(v13 + 2);
        *(_DWORD *)v13 = DWORD1(v13);
        while ( 1 )
        {
          v15 = idVoiceEventManager::GetEvent(
                  this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                  handle: *(const vtrEventHandle_t **)&base[*(_DWORD *)&v8[8]]);
          if ( v15->startMS
             - idVoiceEventManager::GetEvent(
                 this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                 handle: *(const vtrEventHandle_t **)v14)->startMS < 0 )
          {
            do
            {
              ++*(_DWORD *)&v8[8];
              if ( *(int *)&v8[8] >= *(int *)&v8[4] )
                break;
              v16 = idVoiceEventManager::GetEvent(
                      this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                      handle: *(const vtrEventHandle_t **)&base[*(_DWORD *)&v8[8]]);
            }
            while ( v16->startMS
                  - idVoiceEventManager::GetEvent(
                      this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                      handle: *(const vtrEventHandle_t **)v14)->startMS < 0 );
          }
          v17 = &base[*(_DWORD *)&v8[4]];
          v18 = idVoiceEventManager::GetEvent(
                  this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                  handle: *(const vtrEventHandle_t **)v17);
          if ( v18->startMS
             - idVoiceEventManager::GetEvent(
                 this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                 handle: *(const vtrEventHandle_t **)v14)->startMS > 0 )
            break;
LABEL_12:
          if ( *(int *)&v8[8] < *(int *)&v8[4] )
          {
            v20 = &base[(*(_DWORD *)&v8[8])++];
            --*(_DWORD *)&v8[4];
            v21 = *v20;
            v20->eventType = v17->eventType;
            v20->index = v17->index;
            *v17 = v21;
            if ( *(int *)&v8[8] < *(int *)&v8[4] )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --*(_DWORD *)&v8[4];
          if ( *(int *)&v8[4] <= *(int *)&v8[8] )
            break;
          v17 = &base[*(_DWORD *)&v8[4]];
          v19 = idVoiceEventManager::GetEvent(
                  this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                  handle: *(const vtrEventHandle_t **)v17);
          if ( v19->startMS
             - idVoiceEventManager::GetEvent(
                 this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                 handle: *(const vtrEventHandle_t **)v14)->startMS <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v22 = &base[*(_DWORD *)&v8[8]];
        v23 = idVoiceEventManager::GetEvent(
                this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                handle: *(const vtrEventHandle_t **)v22);
        if ( v23->startMS
           - idVoiceEventManager::GetEvent(
               this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
               handle: *(const vtrEventHandle_t **)v14)->startMS <= 0 )
        {
          do
          {
            if ( *(int *)&v8[8] >= (int)v12 )
              break;
            v22 = &base[++*(_DWORD *)&v8[8]];
            v24 = idVoiceEventManager::GetEvent(
                    this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                    handle: *(const vtrEventHandle_t **)v22);
          }
          while ( v24->startMS
                - idVoiceEventManager::GetEvent(
                    this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                    handle: *(const vtrEventHandle_t **)v14)->startMS <= 0 );
        }
        v25 = idVoiceEventManager::GetEvent(
                this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                handle: *(const vtrEventHandle_t **)&base[*(_DWORD *)&v8[4]]);
        if ( v25->startMS
           - idVoiceEventManager::GetEvent(
               this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
               handle: *(const vtrEventHandle_t **)v14)->startMS >= 0 )
        {
          do
          {
            if ( SHIDWORD(v12) >= *(int *)&v8[4] )
              break;
            v26 = idVoiceEventManager::GetEvent(
                    this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                    handle: *(const vtrEventHandle_t **)&base[--*(_DWORD *)&v8[4]]);
          }
          while ( v26->startMS
                - idVoiceEventManager::GetEvent(
                    this: *(idVoiceEventManager **)(*(_DWORD *)v8 + 4),
                    handle: *(const vtrEventHandle_t **)v14)->startMS >= 0 );
        }
        v27 = (const vtrEventHandle_t *)*v14;
        LODWORD(v7) = v7 + 1;
        v14->eventType = v22->eventType;
        v14->index = v22->index;
        v36[v10 + 129] = v12;
        *v22 = (vtrEventHandle_t)v27;
        v36[v10 + 1] = *(_QWORD *)&v8[4];
        *(_QWORD *)(v10 * 8 + v11) = *(_QWORD *)v8;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidStr@@VidSort_Str@@@@UBAXPAVidStr@@I@Z
// EA  : 0x82648A98
// RVA : 0x00648A98
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idStr,idSort_Str>::Sort(
        idSort_Quick<idStr,idSort_Str> *this,
        idStr *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r30 OVERLAPPED
  int v8; // r21
  int v9; // r26
  __int64 v10; // r25
  int v11; // r31 OVERLAPPED
  __int64 v12; // r11
  const char **v13; // r27
  idStr *v14; // r28
  idStr *j; // r28
  int v16; // r27
  int i; // r28
  _BYTE v18[1016]; // [sp+58h] [-858h] BYREF
  _QWORD v19[140]; // [sp+450h] [-460h] BYREF

  HIDWORD(v7) = base;
  if ( num != 0 )
  {
    v8 = 0;
    LODWORD(a7) = num - 1;
    v19[0] = a7;
    do
    {
      v9 = v8;
      v10 = v19[v8];
      v11 = HIDWORD(v10);
      LODWORD(v7) = v19[v8];
      if ( (int)v10 - HIDWORD(v10) < 4 || v8 >= 127 )
      {
        for ( ; (int)v7 > SHIDWORD(v10); LODWORD(v7) = v7 - 1 )
        {
          v16 = HIDWORD(v10);
          for ( i = HIDWORD(v10) + 1; i <= (int)v7; ++i )
          {
            if ( idStr::Icmp(
                   s1: *(const char **)(32 * i + HIDWORD(v7) + 4),
                   s2: *(const char **)(32 * v16 + HIDWORD(v7) + 4)) > 0 )
              v16 = i;
          }
          SwapValues<idStr>(a: (idStr *)(32 * v16 + HIDWORD(v7)), b: (idStr *)(32 * v7 + HIDWORD(v7)));
        }
        --v8;
      }
      else
      {
        LODWORD(v12) = v10 + HIDWORD(v10);
        HIDWORD(v12) = 32 * v10;
        LODWORD(v12) = ((unsigned __int64)v12 >> 63) + v10 + HIDWORD(v10);
        SwapValues<idStr>(a: (idStr *)(32 * v10 + HIDWORD(v7)), b: (idStr *)(32 * (v12 >> 1) + HIDWORD(v7)));
        LODWORD(v7) = v7 - 1;
        v13 = (const char **)(32 * v10 + HIDWORD(v7) + 4);
        while ( 1 )
        {
          if ( idStr::Icmp(s1: *(const char **)(32 * v11 + HIDWORD(v7) + 4), s2: *v13) < 0 )
          {
            do
              ++v11;
            while ( v11 < (int)v7 && idStr::Icmp(s1: *(const char **)(32 * v11 + HIDWORD(v7) + 4), s2: *v13) < 0 );
          }
          v14 = (idStr *)(32 * v7 + HIDWORD(v7));
          if ( idStr::Icmp(s1: v14->data, s2: *v13) > 0 )
            break;
LABEL_12:
          if ( v11 < (int)v7 )
          {
            SwapValues<idStr>(a: (idStr *)(32 * v11++ + HIDWORD(v7)), b: v14);
            LODWORD(v7) = v7 - 1;
            if ( v11 < (int)v7 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v7) = v7 - 1;
          if ( (int)v7 <= v11 )
            break;
          v14 = (idStr *)(32 * v7 + HIDWORD(v7));
          if ( idStr::Icmp(s1: v14->data, s2: *v13) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = (idStr *)(32 * v11 + HIDWORD(v7));
              idStr::Icmp(s1: j->data, s2: *v13) <= 0;
              j = (idStr *)(32 * v11 + HIDWORD(v7)) )
        {
          if ( v11 >= (int)v10 )
            break;
          ++v11;
        }
        for ( ; idStr::Icmp(s1: *(const char **)(32 * v7 + HIDWORD(v7) + 4), s2: *v13) >= 0; LODWORD(v7) = v7 - 1 )
        {
          if ( SHIDWORD(v10) >= (int)v7 )
            break;
        }
        SwapValues<idStr>(a: (idStr *)(32 * v10 + HIDWORD(v7)), b: j);
        ++v8;
        v19[v9 + 1] = v10;
        *(_QWORD *)&v18[v9 * 8] = *(__int64 *)((char *)&v7 - 4);
        v19[v9] = v7;
      }
    }
    while ( v8 >= 0 );
  }
}


// ========================================================================
// ??$SwapValues@UshowSoundDebugInfo_t@@@@YAXAAUshowSoundDebugInfo_t@@0@Z
// EA  : 0x8266BE98
// RVA : 0x0066BE98
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<showSoundDebugInfo_t>(showSoundDebugInfo_t *a, showSoundDebugInfo_t *b)
{
  showSoundDebugInfo_t v4; // [sp+50h] [-140h] BYREF

  showSoundDebugInfo_t::showSoundDebugInfo_t(this: &v4, __that: a);
  showSoundDebugInfo_t::operator=(this: a, __that: b);
  showSoundDebugInfo_t::operator=(this: b, __that: &v4);
  showSoundDebugInfo_t::~showSoundDebugInfo_t(this: &v4);
}


// ========================================================================
// __unwind$235043
// EA  : 0x8266BEE4
// RVA : 0x0066BEE4
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_235043()
{
  int v0; // r12

  showSoundDebugInfo_t::~showSoundDebugInfo_t(this: (showSoundDebugInfo_t *)(v0 - 400 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@UshowSoundDebugInfo_t@@VidSort_DrawSound@@@@UBAXPAUshowSoundDebugInfo_t@@I@Z
// EA  : 0x8266C350
// RVA : 0x0066C350
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<showSoundDebugInfo_t,idSort_DrawSound>::Sort(
        idSort_Quick<showSoundDebugInfo_t,idSort_DrawSound> *this,
        showSoundDebugInfo_t *base,
        unsigned int num,
        int a4,
        int a5,
        __int64 a6)
{
  __int64 v6; // r22
  __int64 v7; // r11
  __int64 v8; // r10 OVERLAPPED
  int v9; // r18
  __int64 v10; // r15
  __int64 v11; // r17
  __int64 v12; // r20
  int v13; // r23
  int v14; // r11
  unsigned __int64 v15; // r10
  int v16; // r8
  showSoundDebugInfo_t *v17; // r30
  double v18; // fp0
  double v19; // fp13
  int v20; // r29
  double v21; // fp13
  int v22; // r30
  int v23; // r8
  int v24; // r7
  unsigned int v25; // r11
  int v26; // r11
  size_t v27; // r25
  int v28; // r4
  bool v29; // zf
  unsigned int v30; // r11
  int v31; // r11
  size_t v32; // r30
  int v33; // r4
  double v34; // fp0
  showSoundDebugInfo_t *v35; // r4
  double volume; // fp13
  double v37; // fp13
  int v38; // r8
  int v39; // r10
  int v40; // r11
  int v41; // r7
  double v42; // fp0
  double v43; // fp13
  int v44; // r30
  int v45; // r29
  int v46; // r27
  char *v47; // r9
  char *v48; // r10
  char v49; // r11
  int v50; // r9
  int v51; // r8
  unsigned int v52; // r11
  int v53; // r11
  size_t v54; // r26
  int v55; // r4
  unsigned int v56; // r11
  int v57; // r11
  size_t len; // r30
  int v59; // r4
  __int64 v60; // [sp+58h] [-AF8h]
  soundDebugInfo_t v61; // [sp+70h] [-AE0h] BYREF
  idStr v62; // [sp+C0h] [-A90h] BYREF
  _DWORD v63[44]; // [sp+E0h] [-A70h] BYREF
  soundDebugInfo_t v64; // [sp+190h] [-9C0h] BYREF
  idStr v65; // [sp+1E0h] [-970h] BYREF
  _DWORD v66[44]; // [sp+200h] [-950h] BYREF
  _QWORD v67[276]; // [sp+2B0h] [-8A0h] BYREF

  HIDWORD(v6) = base;
  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a6) = num - 1;
    HIDWORD(v7) = 0x82000000;
    v67[0] = v7;
    v67[128] = a6;
    HIDWORD(v7) = "w:\\tech5\\shared\\idlib\\text/Str.h";
    v60 = v7;
    do
    {
      v8 = v60;
      v9 = v60;
      v10 = v67[(_DWORD)v60];
      v11 = *(_QWORD *)(8 * v60 + HIDWORD(v10));
      LODWORD(v12) = v67[v60];
      v13 = *(_DWORD *)(8 * v60 + HIDWORD(v10) + 4);
      if ( (int)v11 - (int)v10 < 4 || (int)v60 >= 127 )
      {
        for ( ; v13 > (int)v12; --v13 )
        {
          v39 = v12;
          v40 = v12 + 1;
          if ( (int)v12 + 1 <= v13 )
          {
            v41 = v13 - v12;
            do
            {
              v42 = *(float *)(280 * v39 + HIDWORD(v6) + 8);
              v43 = *(float *)(280 * v40 + HIDWORD(v6) + 8);
              if ( v43 != v42 && v43 < v42 )
                v39 = v40;
              --v41;
              ++v40;
            }
            while ( v41 != 0 );
          }
          v44 = 280 * v39 + HIDWORD(v6);
          v45 = 280 * v13 + HIDWORD(v6);
          soundDebugInfo_t::soundDebugInfo_t(this: &v61, __that: (const soundDebugInfo_t *)v44);
          v62.baseBuffer[0] = 0;
          v62.len = 0;
          v62.data = v62.baseBuffer;
          v62.allocedAndFlag = 20;
          v46 = *(_DWORD *)(v44 + 80);
          if ( v46 + 1 > 20 )
            idStr::ReAllocate(this: &v62, amount: v46 + 1, keepold: true);
          v47 = v62.data - 1;
          v48 = (char *)(*(_DWORD *)(v44 + 84) - 1);
          do
          {
            v49 = *++v48;
            *++v47 = *v48;
          }
          while ( v49 != 0 );
          v62.len = v46;
          memcpy(Dst: v63, Src: (const void *)(v44 + 112), Size: 0x98u);
          v50 = *(_DWORD *)(v44 + 268);
          v51 = *(_DWORD *)(v44 + 272);
          v63[38] = *(_DWORD *)(v44 + 264);
          v63[39] = v50;
          v63[40] = v51;
          v63[41] = *(_DWORD *)(v44 + 276);
          soundDebugInfo_t::operator=(
            this: (soundDebugInfo_t *)v44,
            __that: (const soundDebugInfo_t *)(280 * v13 + HIDWORD(v6)));
          v52 = *(_DWORD *)(v44 + 88);
          v54 = *(_DWORD *)(v45 + 80);
          v55 = v54 + 1;
          v29 = v52 >> 31 == 0;
          v53 = v52 & 0x7FFFFFFF;
          if ( v29 )
          {
            if ( v55 > v53 )
              idStr::ReAllocate(this: (idStr *)(v44 + 80), amount: v55, keepold: false);
          }
          else if ( v55 > v53
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: *(void **)(v44 + 84), Src: *(const void **)(v45 + 84), Size: v54);
          *(_BYTE *)(*(_DWORD *)(v44 + 84) + v54) = 0;
          *(_DWORD *)(v44 + 80) = v54;
          memcpy(Dst: (void *)(v44 + 112), Src: (const void *)(v45 + 112), Size: 0xA8u);
          soundDebugInfo_t::operator=(this: (soundDebugInfo_t *)(280 * v13 + HIDWORD(v6)), __that: &v61);
          v56 = *(_DWORD *)(v45 + 88);
          len = v62.len;
          v59 = v62.len + 1;
          v29 = v56 >> 31 == 0;
          v57 = v56 & 0x7FFFFFFF;
          if ( v29 )
          {
            if ( v59 > v57 )
              idStr::ReAllocate(this: (idStr *)(v45 + 80), amount: v59, keepold: false);
          }
          else if ( v59 > v57
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: *(void **)(v45 + 84), Src: v62.data, Size: len);
          *(_BYTE *)(len + *(_DWORD *)(v45 + 84)) = 0;
          *(_DWORD *)(v45 + 80) = len;
          qmemcpy((void *)(v45 + 112), v63, 168);
          idStr::FreeData(this: &v62);
          idStr::FreeData(this: &v61.sample);
        }
        LODWORD(v8) = v60 - 1;
        v60 = v8;
      }
      else
      {
        v14 = v11 + v10;
        v15 = *(unsigned __int64 *)((char *)&v8 - 4) >> 63;
        v16 = v15 + v11 + v10;
        v17 = (showSoundDebugInfo_t *)(280 * HIDWORD(v15) + HIDWORD(v6));
        HIDWORD(v11) = v17;
        SwapValues<showSoundDebugInfo_t>(
          a: v17,
          b: (showSoundDebugInfo_t *)(280 * (*(__int64 *)(&a5 - 1) >> 1) + HIDWORD(v6)));
        LODWORD(v6) = v11 - 1;
        HIDWORD(v12) = &v17->info.volume;
        do
        {
          v18 = *(float *)HIDWORD(v12);
          do
          {
            v19 = *(float *)(280 * v12 + HIDWORD(v6) + 8);
            if ( v19 == v18 )
              break;
            if ( v19 < v18 )
              break;
            LODWORD(v12) = v12 + 1;
          }
          while ( (int)v12 < (int)v6 );
          while ( 1 )
          {
            v20 = 280 * v6 + HIDWORD(v6);
            v21 = *(float *)(v20 + 8);
            if ( v21 == v18 || v21 >= v18 )
              break;
            LODWORD(v6) = v6 - 1;
            if ( (int)v6 <= (int)v12 )
              goto LABEL_28;
          }
          if ( (int)v12 >= (int)v6 )
            break;
          v22 = 280 * v12 + HIDWORD(v6);
          soundDebugInfo_t::soundDebugInfo_t(this: &v64, __that: (const soundDebugInfo_t *)v22);
          idStr::idStr(this: &v65, text: (const idStr *)(v22 + 80));
          memcpy(Dst: v66, Src: (const void *)(v22 + 112), Size: 0x98u);
          v23 = *(_DWORD *)(v22 + 268);
          v24 = *(_DWORD *)(v22 + 272);
          v66[38] = *(_DWORD *)(v22 + 264);
          v66[39] = v23;
          v66[40] = v24;
          v66[41] = *(_DWORD *)(v22 + 276);
          soundDebugInfo_t::operator=(
            this: (soundDebugInfo_t *)v22,
            __that: (const soundDebugInfo_t *)(280 * v6 + HIDWORD(v6)));
          v25 = *(_DWORD *)(v22 + 88);
          v27 = *(_DWORD *)(v20 + 80);
          v28 = v27 + 1;
          v29 = v25 >> 31 == 0;
          v26 = v25 & 0x7FFFFFFF;
          if ( v29 )
          {
            if ( v28 > v26 )
              idStr::ReAllocate(this: (idStr *)(v22 + 80), amount: v28, keepold: false);
          }
          else if ( v28 > v26
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: *(void **)(v22 + 84), Src: *(const void **)(v20 + 84), Size: v27);
          *(_BYTE *)(v27 + *(_DWORD *)(v22 + 84)) = 0;
          *(_DWORD *)(v22 + 80) = v27;
          memcpy(Dst: (void *)(v22 + 112), Src: (const void *)(v20 + 112), Size: 0xA8u);
          soundDebugInfo_t::operator=(this: (soundDebugInfo_t *)(280 * v6 + HIDWORD(v6)), __that: &v64);
          v30 = *(_DWORD *)(v20 + 88);
          v32 = v65.len;
          v33 = v65.len + 1;
          v29 = v30 >> 31 == 0;
          v31 = v30 & 0x7FFFFFFF;
          if ( v29 )
          {
            if ( v33 > v31 )
              idStr::ReAllocate(this: (idStr *)(v20 + 80), amount: v33, keepold: false);
          }
          else if ( v33 > v31
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: *(void **)(v20 + 84), Src: v65.data, Size: v32);
          *(_BYTE *)(v32 + *(_DWORD *)(v20 + 84)) = 0;
          *(_DWORD *)(v20 + 80) = v32;
          qmemcpy((void *)(v20 + 112), v66, 168);
          idStr::FreeData(this: &v65);
          idStr::FreeData(this: &v64.sample);
          LODWORD(v12) = v12 + 1;
          LODWORD(v6) = v6 - 1;
        }
        while ( (int)v12 < (int)v6 );
LABEL_28:
        v34 = *(float *)HIDWORD(v12);
        while ( 1 )
        {
          v35 = (showSoundDebugInfo_t *)(280 * v12 + HIDWORD(v6));
          volume = v35->info.volume;
          if ( volume != v34 && volume < v34 )
            break;
          if ( (int)v12 >= (int)v11 )
            break;
          LODWORD(v12) = v12 + 1;
        }
        while ( 1 )
        {
          v37 = *(float *)(280 * v6 + HIDWORD(v6) + 8);
          if ( v37 != v34 && v37 >= v34 )
            break;
          if ( (int)v10 >= (int)v6 )
            break;
          LODWORD(v6) = v6 - 1;
        }
        SwapValues<showSoundDebugInfo_t>(a: (showSoundDebugInfo_t *)HIDWORD(v11), b: v35);
        v38 = v60 + 1;
        v67[v9 + 129] = v11;
        v60 = *(_QWORD *)(&a5 - 1);
        v67[v9 + 1] = v12;
        *(_QWORD *)(v9 * 8 + HIDWORD(v10)) = v6;
      }
    }
    while ( (int)v60 >= 0 );
  }
}


// ========================================================================
// __unwind$235255
// EA  : 0x8266CA6C
// RVA : 0x0066CA6C
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_235255()
{
  int v0; // r12

  idDialogInfo::~idDialogInfo(this: (idDialogInfo *)(v0 - 2896 + 400));
}


// ========================================================================
// __unwind$235253
// EA  : 0x8266CA94
// RVA : 0x0066CA94
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_235253()
{
  int v0; // r12

  showSoundDebugInfo_t::~showSoundDebugInfo_t(this: (showSoundDebugInfo_t *)(v0 - 2896 + 400));
}


// ========================================================================
// __unwind$235406
// EA  : 0x8266CABC
// RVA : 0x0066CABC
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_235406()
{
  int v0; // r12

  idDialogInfo::~idDialogInfo(this: (idDialogInfo *)(v0 - 2896 + 400));
}


// ========================================================================
// __unwind$235516_0
// EA  : 0x8266CAE4
// RVA : 0x0066CAE4
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_235516_0()
{
  int v0; // r12

  idDialogInfo::~idDialogInfo(this: (idDialogInfo *)(v0 - 2896 + 112));
}


// ========================================================================
// __unwind$235514_0
// EA  : 0x8266CB0C
// RVA : 0x0066CB0C
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_235514_0()
{
  int v0; // r12

  showSoundDebugInfo_t::~showSoundDebugInfo_t(this: (showSoundDebugInfo_t *)(v0 - 2896 + 112));
}


// ========================================================================
// __unwind$235758
// EA  : 0x8266CB34
// RVA : 0x0066CB34
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_235758()
{
  int v0; // r12

  idDialogInfo::~idDialogInfo(this: (idDialogInfo *)(v0 - 2896 + 112));
}


// ========================================================================
// ??$SwapValues@VweaponUsageReport_t@idPlaytestStorage@@@@YAXAAVweaponUsageReport_t@idPlaytestStorage@@0@Z
// EA  : 0x8267FD00
// RVA : 0x0067FD00
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<idPlaytestStorage::weaponUsageReport_t>(
        idPlaytestStorage::weaponUsageReport_t *a,
        idPlaytestStorage::weaponUsageReport_t *b)
{
  int time; // r11
  int projectilesSpawned; // r10
  int len; // r30
  int v7; // r11
  size_t v8; // r30
  int v9; // r5
  int v10; // r4
  idStr v11; // [sp+50h] [-60h] BYREF
  int v12; // [sp+70h] [-40h]
  float percentage; // [sp+74h] [-3Ch]
  int v14; // [sp+78h] [-38h]

  idStr::idStr(this: &v11, text: &a->weaponName);
  time = a->time;
  projectilesSpawned = a->projectilesSpawned;
  percentage = a->percentage;
  v12 = time;
  v14 = projectilesSpawned;
  len = b->weaponName.len;
  idStr::EnsureAlloced(this: &a->weaponName, amount: b->weaponName.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: a->weaponName.data, Src: b->weaponName.data, Size: len);
  a->weaponName.data[len] = 0;
  a->weaponName.len = len;
  a->time = b->time;
  v7 = v11.len;
  a->percentage = b->percentage;
  a->projectilesSpawned = b->projectilesSpawned;
  v8 = v7;
  idStr::EnsureAlloced(this: &b->weaponName, amount: v7 + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: b->weaponName.data, Src: v11.data, Size: v8);
  b->weaponName.data[v8] = 0;
  v9 = v12;
  b->percentage = percentage;
  v10 = v14;
  b->weaponName.len = v8;
  b->time = v9;
  b->projectilesSpawned = v10;
  idStr::FreeData(this: &v11);
}


// ========================================================================
// __unwind$240130
// EA  : 0x8267FDEC
// RVA : 0x0067FDEC
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_240130()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ??$SwapValues@VquickItemReport_t@idPlaytestStorage@@@@YAXAAVquickItemReport_t@idPlaytestStorage@@0@Z
// EA  : 0x8267FE20
// RVA : 0x0067FE20
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<idPlaytestStorage::quickItemReport_t>(
        idPlaytestStorage::quickItemReport_t *a,
        idPlaytestStorage::quickItemReport_t *b)
{
  int len; // r30
  int v5; // r11
  size_t v6; // r30
  int v7; // r7
  idStr v8; // [sp+50h] [-60h] BYREF
  int count; // [sp+70h] [-40h]

  idStr::idStr(this: &v8, text: &a->itemName);
  count = a->count;
  len = b->itemName.len;
  idStr::EnsureAlloced(this: &a->itemName, amount: b->itemName.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: a->itemName.data, Src: b->itemName.data, Size: len);
  a->itemName.data[len] = 0;
  v5 = v8.len;
  a->itemName.len = len;
  a->count = b->count;
  v6 = v5;
  idStr::EnsureAlloced(this: &b->itemName, amount: v5 + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: b->itemName.data, Src: v8.data, Size: v6);
  b->itemName.data[v6] = 0;
  v7 = count;
  b->itemName.len = v6;
  b->count = v7;
  idStr::FreeData(this: &v8);
}


// ========================================================================
// __unwind$240260
// EA  : 0x8267FEDC
// RVA : 0x0067FEDC
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_240260()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@VweaponUsageReport_t@idPlaytestStorage@@VidSort_WeaponUsageReport@2@@@UBAXPAVweaponUsageReport_t@idPlaytestStorage@@I@Z
// EA  : 0x82680B10
// RVA : 0x00680B10
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idPlaytestStorage::weaponUsageReport_t,idPlaytestStorage::idSort_WeaponUsageReport>::Sort(
        idSort_Quick<idPlaytestStorage::weaponUsageReport_t,idPlaytestStorage::idSort_WeaponUsageReport> *this,
        idPlaytestStorage::weaponUsageReport_t *base,
        unsigned int num,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v7; // r23
  int v8; // r28
  __int64 v9; // r27
  int v10; // r31
  int v11; // r11
  unsigned __int64 v12; // r10
  idPlaytestStorage::weaponUsageReport_t *v13; // r29
  idPlaytestStorage::weaponUsageReport_t *v14; // r25
  int v15; // r31 OVERLAPPED
  float *p_percentage; // r29
  idPlaytestStorage::weaponUsageReport_t *v17; // r4
  idPlaytestStorage::weaponUsageReport_t *v18; // r4
  int v19; // r29
  int v20; // r11
  int v21; // r9
  int v22; // r7
  idPlaytestStorage::weaponUsageReport_t *v23; // r10
  int v24; // r7
  _BYTE v25[1016]; // [sp+58h] [-858h] BYREF
  _QWORD v26[140]; // [sp+450h] [-460h] BYREF

  if ( num != 0 )
  {
    HIDWORD(v7) = 0;
    LODWORD(a6) = num - 1;
    v26[0] = a6;
    do
    {
      v8 = HIDWORD(v7);
      v9 = v26[HIDWORD(v7)];
      LODWORD(v7) = HIDWORD(v9);
      v10 = v26[HIDWORD(v7)];
      if ( (int)v9 - HIDWORD(v9) < 4 || SHIDWORD(v7) >= 127 )
      {
        if ( SHIDWORD(v9) < v10 )
        {
          v19 = v10 - 3;
          do
          {
            v20 = HIDWORD(v9);
            v21 = HIDWORD(v9) + 1;
            if ( HIDWORD(v9) + 1 <= v10 )
            {
              if ( 4 - (HIDWORD(v9) + 1) + v19 >= 4 )
              {
                v22 = HIDWORD(v9) + 3;
                do
                {
                  v23 = &base[v21];
                  if ( v23->percentage < (double)base[v20].percentage )
                    v20 = v21;
                  if ( v23[1].percentage < (double)base[v20].percentage )
                    v20 = v22 - 1;
                  if ( v23[2].percentage < (double)base[v20].percentage )
                    v20 = v22;
                  if ( v23[3].percentage < (double)base[v20].percentage )
                    v20 = v22 + 1;
                  v21 += 4;
                  v22 += 4;
                }
                while ( v21 <= v19 );
              }
              if ( v21 <= v10 )
              {
                v24 = v10 - v21 + 1;
                do
                {
                  if ( base[v21].percentage < (double)base[v20].percentage )
                    v20 = v21;
                  --v24;
                  ++v21;
                }
                while ( v24 != 0 );
              }
            }
            SwapValues<idPlaytestStorage::weaponUsageReport_t>(a: &base[v20], b: &base[v10--]);
            --v19;
          }
          while ( v10 > SHIDWORD(v9) );
        }
        --HIDWORD(v7);
      }
      else
      {
        v11 = v9 + HIDWORD(v9);
        v12 = *(unsigned __int64 *)((char *)&a6 - 4) >> 63;
        LODWORD(a5) = v12 + v9 + HIDWORD(v9);
        v13 = &base[HIDWORD(v12)];
        v14 = v13;
        SwapValues<idPlaytestStorage::weaponUsageReport_t>(a: v13, b: &base[a5 >> 1]);
        v15 = v10 - 1;
        p_percentage = &v13->percentage;
        do
        {
          while ( 1 )
          {
            v17 = &base[v15];
            if ( v17->percentage >= (double)*p_percentage )
              break;
            if ( --v15 <= (int)v7 )
              goto LABEL_11;
          }
          if ( (int)v7 >= v15 )
            break;
          SwapValues<idPlaytestStorage::weaponUsageReport_t>(a: &base[v7], b: v17);
          LODWORD(v7) = v7 + 1;
          --v15;
        }
        while ( (int)v7 < v15 );
LABEL_11:
        while ( 1 )
        {
          v18 = &base[v7];
          if ( v18->percentage < (double)*p_percentage || (int)v7 >= (int)v9 )
            break;
          LODWORD(v7) = v7 + 1;
        }
        while ( SHIDWORD(v9) < v15 )
          --v15;
        SwapValues<idPlaytestStorage::weaponUsageReport_t>(a: v14, b: v18);
        LODWORD(a6) = v25;
        ++HIDWORD(v7);
        v26[v8 + 1] = v9;
        *(_QWORD *)&v25[v8 * 8] = v7;
        v26[v8] = *(_QWORD *)(&base - 1);
      }
    }
    while ( v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@VkillReport_t@idPlaytestStorage@@VidSort_KillReport@2@@@UBAXPAVkillReport_t@idPlaytestStorage@@I@Z
// EA  : 0x82680DC0
// RVA : 0x00680DC0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idPlaytestStorage::killReport_t,idPlaytestStorage::idSort_KillReport>::Sort(
        idSort_Quick<idPlaytestStorage::quickItemReport_t,idPlaytestStorage::idSort_QuickItemReport> *this,
        idPlaytestStorage::quickItemReport_t *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r22
  int v9; // r27
  __int64 v10; // r24
  __int64 v11; // r26
  int v12; // r31 OVERLAPPED
  int v13; // r29
  int v14; // r11
  __int64 v15; // r11
  __int64 v16; // r29
  unsigned int v17; // r11
  idPlaytestStorage::quickItemReport_t *v18; // r4
  idPlaytestStorage::quickItemReport_t *i; // r4
  int v20; // r10
  int v21; // r11
  int v22; // r5
  __int64 v23; // [sp+50h] [-860h] BYREF
  _BYTE v24[1016]; // [sp+58h] [-858h] BYREF
  __int64 v25; // [sp+450h] [-460h]
  _BYTE v26[1112]; // [sp+458h] [-458h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v23 = v7;
    v25 = a7;
    do
    {
      v9 = 8 * v7;
      v10 = *(_QWORD *)&v24[8 * (_DWORD)v7 - 8];
      v11 = *(_QWORD *)(8 * v7 + HIDWORD(v10));
      v12 = *(_DWORD *)&v24[8 * v7 - 4];
      v13 = *(_DWORD *)(8 * v7 + HIDWORD(v10) + 4);
      if ( (int)v11 - (int)v10 < 4 || (int)v7 >= 127 )
      {
        for ( ; v13 > v12; --v13 )
        {
          v20 = v12;
          v21 = v12 + 1;
          if ( v12 + 1 <= v13 )
          {
            v22 = v13 - v12;
            do
            {
              if ( ((((base[v20].count ^ base[v21].count) >= 0) + (base[v21].count >= (unsigned int)base[v20].count)) & 1) != 0 )
                v20 = v21;
              --v22;
              ++v21;
            }
            while ( v22 != 0 );
          }
          SwapValues<idPlaytestStorage::quickItemReport_t>(a: &base[v20], b: &base[v13]);
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        v14 = v11 + v10;
        LODWORD(v15) = (*(unsigned __int64 *)((char *)&a7 - 4) >> 63) + v11 + v10;
        HIDWORD(v15) = 9 * v11;
        SwapValues<idPlaytestStorage::quickItemReport_t>(a: &base[v11], b: &base[v15 >> 1]);
        LODWORD(v16) = v13 - 1;
        HIDWORD(v16) = &base[v11].count;
        while ( 1 )
        {
          v17 = *(_DWORD *)HIDWORD(v16);
          v18 = &base[v16];
          if ( (((((v17 ^ v18->count) & 0x80000000) == 0) + (v18->count >= v17)) & 1) != 0 )
            break;
LABEL_9:
          if ( v12 < (int)v16 )
          {
            SwapValues<idPlaytestStorage::quickItemReport_t>(a: &base[v12++], b: v18);
            LODWORD(v16) = v16 - 1;
            if ( v12 < (int)v16 )
              continue;
          }
          goto LABEL_11;
        }
        while ( 1 )
        {
          LODWORD(v16) = v16 - 1;
          if ( (int)v16 <= v12 )
            break;
          v18 = &base[v16];
          if ( (((((v17 ^ v18->count) & 0x80000000) == 0) + (v18->count >= v17)) & 1) == 0 )
            goto LABEL_9;
        }
LABEL_11:
        for ( i = &base[v12];
              ((((*(_DWORD *)HIDWORD(v16) ^ i->count) >= 0) + (i->count >= *(_DWORD *)HIDWORD(v16))) & 1) == 0;
              i = &base[v12] )
        {
          if ( v12 >= (int)v11 )
            break;
          ++v12;
        }
        while ( (int)v10 < (int)v16 )
          LODWORD(v16) = v16 - 1;
        SwapValues<idPlaytestStorage::quickItemReport_t>(a: &base[v11], b: i);
        LODWORD(a7) = v24;
        LODWORD(v7) = v7 + 1;
        HIDWORD(v11) = &base[v11];
        *(_QWORD *)&v26[v9] = v11;
        *(_QWORD *)&v24[v9] = *(_QWORD *)(&base - 1);
        *(_QWORD *)(v9 + HIDWORD(v10)) = v16;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@PAVidResource@@VidSort_ResourceName@@@@UBAXPAPAVidResource@@I@Z
// EA  : 0x82694D30
// RVA : 0x00694D30
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idResource *,idSort_ResourceName>::Sort(
        idSort_Quick<idResource *,idSort_ResourceName> *this,
        __int64 num,
        int a3,
        int a4,
        int a5,
        unsigned __int64 a6)
{
  __int64 v6; // r26
  int v7; // r30 OVERLAPPED
  int v8; // r27 OVERLAPPED
  __int64 v9; // r29
  int v10; // r31 OVERLAPPED
  int v11; // r8
  __int128 v12; // r10
  int *v13; // r3
  unsigned __int8 *v14; // r10
  unsigned __int8 *v15; // r11
  int v16; // r9
  int v17; // r9
  bool v18; // zf
  unsigned __int8 *v19; // r10
  unsigned __int8 *v20; // r11
  int v21; // r9
  int v22; // r9
  unsigned __int8 *v23; // r10
  int v24; // r8
  unsigned __int8 *v25; // r11
  int v26; // r9
  int v27; // r9
  unsigned __int8 *v28; // r10
  unsigned __int8 *v29; // r11
  int v30; // r9
  int v31; // r9
  int v32; // r9
  int v33; // r6
  int v34; // r7
  unsigned __int8 *v35; // r10
  unsigned __int8 *v36; // r11
  int v37; // r9
  int v38; // r9
  unsigned __int8 *v39; // r10
  unsigned __int8 *v40; // r11
  int v41; // r9
  int v42; // r9
  unsigned __int8 *v43; // r10
  unsigned __int8 *v44; // r11
  int v45; // r9
  int v46; // r9
  unsigned __int8 *v47; // r10
  unsigned __int8 *v48; // r11
  int v49; // r9
  int v50; // r9
  int v51; // r3
  int v52; // r6
  int v53; // r7
  int v54; // r11
  int v55; // r5
  unsigned __int8 *v56; // r11
  unsigned __int8 *v57; // r10
  int v58; // r9
  int v59; // r9
  int v60; // r7
  __int64 v61; // [sp+10h] [-840h] BYREF
  _BYTE v62[1016]; // [sp+18h] [-838h] BYREF
  unsigned __int64 v63; // [sp+410h] [-440h]
  _BYTE v64[1080]; // [sp+418h] [-438h] BYREF

  if ( (_DWORD)num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v61 = v6;
    v63 = a6;
    do
    {
      v7 = 8 * v6;
      *(_QWORD *)(&v8 - 1) = *(_QWORD *)&v62[8 * (_DWORD)v6 - 8];
      v9 = *(_QWORD *)(8 * v6 + v8);
      v10 = HIDWORD(v9);
      v11 = *(_DWORD *)(8 * v6 + v8 + 4);
      if ( (int)v9 - HIDWORD(v9) < 4 || (int)v6 >= 127 )
      {
        if ( SHIDWORD(v9) < v11 )
        {
          v51 = HIDWORD(v9) + 1;
          do
          {
            v52 = HIDWORD(v9);
            v53 = HIDWORD(v9) + 1;
            if ( v51 <= v11 )
            {
              v54 = 4 * v51;
              v55 = v11 - HIDWORD(v9);
              do
              {
                v56 = *(unsigned __int8 **)(*(_DWORD *)(v54 + HIDWORD(num)) + 8);
                v57 = *(unsigned __int8 **)(*(_DWORD *)(4 * v52 + HIDWORD(num)) + 8);
                do
                {
                  v58 = *v56;
                  v18 = v58 == 0;
                  v59 = v58 - *v57;
                  if ( v18 )
                    break;
                  ++v56;
                  ++v57;
                }
                while ( v59 == 0 );
                if ( v59 > 0 )
                  v52 = v53;
                ++v53;
                --v55;
                v54 = 4 * v53;
              }
              while ( v55 != 0 );
            }
            HIDWORD(a6) = *(_DWORD *)(4 * v11 + HIDWORD(num));
            v60 = *(_DWORD *)(4 * v52 + HIDWORD(num));
            *(_DWORD *)(4 * v52 + HIDWORD(num)) = HIDWORD(a6);
            *(_DWORD *)(4 * v11-- + HIDWORD(num)) = v60;
          }
          while ( v11 > SHIDWORD(v9) );
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        LODWORD(a6) = v9 + HIDWORD(v9);
        *(_QWORD *)((char *)&v12 + 4) = a6 >> 63;
        LODWORD(v12) = DWORD2(v12) + v9 + HIDWORD(v9);
        LODWORD(num) = v9 - 1;
        *(_QWORD *)((char *)&v12 + 4) = (__int64)v12 >> 1;
        v13 = (int *)(4 * v9 + HIDWORD(num));
        DWORD1(v12) = *v13;
        *v13 = *(_DWORD *)(4 * DWORD2(v12) + HIDWORD(num));
        *(_DWORD *)(4 * DWORD2(v12) + HIDWORD(num)) = DWORD1(v12);
        while ( 1 )
        {
          v14 = *(unsigned __int8 **)(*v13 + 8);
          v15 = *(unsigned __int8 **)(*(_DWORD *)(4 * v10 + HIDWORD(num)) + 8);
          do
          {
            v16 = *v15;
            v18 = v16 == 0;
            v17 = v16 - *v14;
            if ( v18 )
              break;
            ++v15;
            ++v14;
          }
          while ( v17 == 0 );
          if ( v17 < 0 )
          {
            do
            {
              if ( ++v10 >= (int)num )
                break;
              v19 = *(unsigned __int8 **)(*v13 + 8);
              v20 = *(unsigned __int8 **)(*(_DWORD *)(4 * v10 + HIDWORD(num)) + 8);
              do
              {
                v21 = *v20;
                v18 = v21 == 0;
                v22 = v21 - *v19;
                if ( v18 )
                  break;
                ++v20;
                ++v19;
              }
              while ( v22 == 0 );
            }
            while ( v22 < 0 );
          }
          v23 = *(unsigned __int8 **)(*v13 + 8);
          v24 = 4 * num + HIDWORD(num);
          v25 = *(unsigned __int8 **)(*(_DWORD *)v24 + 8);
          do
          {
            v26 = *v25;
            v18 = v26 == 0;
            v27 = v26 - *v23;
            if ( v18 )
              break;
            ++v25;
            ++v23;
          }
          while ( v27 == 0 );
          if ( v27 > 0 )
            break;
LABEL_24:
          if ( v10 < (int)num )
          {
            LODWORD(num) = num - 1;
            v32 = *(_DWORD *)(4 * v10 + HIDWORD(num));
            *(_DWORD *)(4 * v10++ + HIDWORD(num)) = *(_DWORD *)v24;
            *(_DWORD *)v24 = v32;
            if ( v10 < (int)num )
              continue;
          }
          goto LABEL_26;
        }
        while ( 1 )
        {
          LODWORD(num) = num - 1;
          if ( (int)num <= v10 )
            break;
          v24 = 4 * num + HIDWORD(num);
          v28 = *(unsigned __int8 **)(*v13 + 8);
          v29 = *(unsigned __int8 **)(*(_DWORD *)v24 + 8);
          do
          {
            v30 = *v29;
            v18 = v30 == 0;
            v31 = v30 - *v28;
            if ( v18 )
              break;
            ++v29;
            ++v28;
          }
          while ( v31 == 0 );
          if ( v31 <= 0 )
            goto LABEL_24;
        }
LABEL_26:
        v33 = *v13;
        v34 = 4 * v10 + HIDWORD(num);
        v35 = *(unsigned __int8 **)(*v13 + 8);
        v36 = *(unsigned __int8 **)(*(_DWORD *)v34 + 8);
        do
        {
          v37 = *v36;
          v18 = v37 == 0;
          v38 = v37 - *v35;
          if ( v18 )
            break;
          ++v36;
          ++v35;
        }
        while ( v38 == 0 );
        if ( v38 <= 0 )
        {
          do
          {
            if ( v10 >= (int)v9 )
              break;
            ++v10;
            v34 = 4 * v10 + HIDWORD(num);
            v39 = *(unsigned __int8 **)(*v13 + 8);
            v40 = *(unsigned __int8 **)(*(_DWORD *)v34 + 8);
            do
            {
              v41 = *v40;
              v18 = v41 == 0;
              v42 = v41 - *v39;
              if ( v18 )
                break;
              ++v40;
              ++v39;
            }
            while ( v42 == 0 );
          }
          while ( v42 <= 0 );
        }
        v43 = *(unsigned __int8 **)(*v13 + 8);
        v44 = *(unsigned __int8 **)(*(_DWORD *)(4 * num + HIDWORD(num)) + 8);
        do
        {
          v45 = *v44;
          v18 = v45 == 0;
          v46 = v45 - *v43;
          if ( v18 )
            break;
          ++v44;
          ++v43;
        }
        while ( v46 == 0 );
        if ( v46 >= 0 )
        {
          do
          {
            if ( SHIDWORD(v9) >= (int)num )
              break;
            LODWORD(num) = num - 1;
            v47 = *(unsigned __int8 **)(*v13 + 8);
            v48 = *(unsigned __int8 **)(*(_DWORD *)(4 * num + HIDWORD(num)) + 8);
            do
            {
              v49 = *v48;
              v18 = v49 == 0;
              v50 = v49 - *v47;
              if ( v18 )
                break;
              ++v48;
              ++v47;
            }
            while ( v50 == 0 );
          }
          while ( v50 >= 0 );
        }
        HIDWORD(a6) = v62;
        LODWORD(v6) = v6 + 1;
        *v13 = *(_DWORD *)v34;
        *(_QWORD *)&v64[v7] = v9;
        *(_DWORD *)v34 = v33;
        *(_QWORD *)&v62[v7] = *(_QWORD *)&v10;
        *(_QWORD *)(v7 + v8) = num;
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@PAVidResource@@VidSort_ResourceMemory@@@@UBAXPAPAVidResource@@I@Z
// EA  : 0x82695110
// RVA : 0x00695110
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idResource *,idSort_ResourceMemory>::Sort(
        idSort_Quick<idResource *,idSort_ResourceMemory> *this,
        idResource **base,
        unsigned int num,
        int a4,
        unsigned __int64 a5,
        __int64 a6)
{
  __int64 v6; // r28
  int v7; // r3
  int v8; // r31 OVERLAPPED
  __int64 v9; // r30 OVERLAPPED
  __int64 v10; // r11 OVERLAPPED
  __int128 v11; // r8
  idResource **v12; // r8
  int trackedMemory; // r7
  idResource **v14; // r9
  idResource *v15; // r5
  idResource *v16; // r5
  idResource **v17; // r9 OVERLAPPED
  int v18; // r6
  int v19; // r3
  int v20; // r6
  int v21; // r9
  int v22; // r8
  int v23; // r5
  int v24; // r9
  idResource *v25; // r6
  __int64 v26; // [sp+10h] [-830h] BYREF
  _BYTE v27[1016]; // [sp+18h] [-828h] BYREF
  __int64 v28; // [sp+410h] [-430h]
  _BYTE v29[1064]; // [sp+418h] [-428h] BYREF

  if ( num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v26 = v6;
    v28 = a6;
    do
    {
      v7 = 8 * v6;
      v9 = *(_QWORD *)&v27[8 * (_DWORD)v6 - 8];
      *(_QWORD *)&v8 = *(_QWORD *)(8 * v6 + HIDWORD(v9));
      LODWORD(v10) = v9;
      HIDWORD(v10) = *(_DWORD *)(8 * v6 + HIDWORD(v9) + 4);
      if ( v8 - (int)v9 < 4 || (int)v6 >= 127 )
      {
        if ( (int)v9 < SHIDWORD(v10) )
        {
          v19 = v9 + 1;
          do
          {
            v20 = v9;
            v21 = v9 + 1;
            if ( v19 <= SHIDWORD(v10) )
            {
              v22 = v19;
              v23 = HIDWORD(v10) - v9;
              do
              {
                if ( base[v22]->trackedMemory - base[v20]->trackedMemory > 0 )
                  v20 = v21;
                ++v21;
                --v23;
                v22 = v21;
              }
              while ( v23 != 0 );
            }
            v24 = v20;
            HIDWORD(a5) = base[HIDWORD(v10)];
            v25 = base[v20];
            base[v24] = (idResource *)HIDWORD(a5);
            base[HIDWORD(v10)--] = v25;
          }
          while ( SHIDWORD(v10) > (int)v9 );
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        LODWORD(a5) = v8 + v9;
        *(_QWORD *)((char *)&v11 + 4) = a5 >> 63;
        LODWORD(v11) = DWORD2(v11) + v8 + v9;
        --HIDWORD(v10);
        *(_QWORD *)((char *)&v11 + 4) = (__int64)v11 >> 1;
        v12 = &base[v8];
        DWORD2(v11) *= 4;
        DWORD1(v11) = *v12;
        *v12 = *(idResource **)((char *)base + DWORD2(v11));
        *(idResource **)((char *)base + DWORD2(v11)) = (idResource *)DWORD1(v11);
        while ( 1 )
        {
          trackedMemory = (*v12)->trackedMemory;
          if ( base[(_DWORD)v10]->trackedMemory - trackedMemory < 0 )
          {
            do
              LODWORD(v10) = v10 + 1;
            while ( (int)v10 < SHIDWORD(v10) && base[(_DWORD)v10]->trackedMemory - (*v12)->trackedMemory < 0 );
          }
          v14 = &base[HIDWORD(v10)];
          if ( (*v14)->trackedMemory - trackedMemory > 0 )
            break;
LABEL_12:
          if ( (int)v10 < SHIDWORD(v10) )
          {
            --HIDWORD(v10);
            v15 = base[(_DWORD)v10];
            base[(_DWORD)v10] = *v14;
            LODWORD(v10) = v10 + 1;
            *v14 = v15;
            if ( (int)v10 < SHIDWORD(v10) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v10);
          if ( SHIDWORD(v10) <= (int)v10 )
            break;
          v14 = &base[HIDWORD(v10)];
          if ( (*v14)->trackedMemory - (*v12)->trackedMemory <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v16 = *v12;
        v17 = &base[v10];
        v18 = (*v12)->trackedMemory;
        if ( (*v17)->trackedMemory - v18 <= 0 )
        {
          do
          {
            if ( (int)v10 >= v8 )
              break;
            LODWORD(v10) = v10 + 1;
            v17 = &base[v10];
          }
          while ( (*v17)->trackedMemory - (*v12)->trackedMemory <= 0 );
        }
        if ( base[HIDWORD(v10)]->trackedMemory - v18 >= 0 )
        {
          do
          {
            if ( (int)v9 >= SHIDWORD(v10) )
              break;
            --HIDWORD(v10);
          }
          while ( base[HIDWORD(v10)]->trackedMemory - (*v12)->trackedMemory >= 0 );
        }
        HIDWORD(a5) = *v17;
        LODWORD(v9) = v27;
        LODWORD(v6) = v6 + 1;
        *v12 = *v17;
        *(_QWORD *)&v29[v7] = *(_QWORD *)&v8;
        *v17 = v16;
        *(_QWORD *)&v27[v7] = v10;
        *(_QWORD *)(v7 + HIDWORD(v9)) = *(__int64 *)((char *)&v10 + 4);
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// ??$SwapValues@VidAFJointMod@idAnimator_AF@@@@YAXAAVidAFJointMod@idAnimator_AF@@0@Z
// EA  : 0x826CB2B8
// RVA : 0x006CB2B8
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<idAnimator_AF::idAFJointMod>(idAnimator_AF::idAFJointMod *a, idAnimator_AF::idAFJointMod *b)
{
  idAnimator_AF::idAFJointMod v2; // 0:^50.60

  v2 = *a;
  *a = *b;
  *b = v2;
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidAFJointMod@idAnimator_AF@@VidSort_JointMods@@@@UBAXPAVidAFJointMod@idAnimator_AF@@I@Z
// EA  : 0x826CB660
// RVA : 0x006CB660
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idAnimator_AF::idAFJointMod,idSort_JointMods>::Sort(
        idSort_Quick<idAnimator_AF::idAFJointMod,idSort_JointMods> *this,
        idAnimator_AF::idAFJointMod *base,
        unsigned int num,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // r30 OVERLAPPED
  int v7; // r22
  int v8; // r27
  __int64 v9; // r26
  int v10; // r31 OVERLAPPED
  int v11; // r11
  unsigned __int64 v12; // r10
  idAnimator_AF::idAFJointMod *v13; // r28
  idAnimator_AF::idAFJointMod *v14; // r24
  idIndex<short,enum invalidJointIndex_t> *p_jointIndex; // r28
  int value; // r11
  idAnimator_AF::idAFJointMod *v17; // r4
  idAnimator_AF::idAFJointMod *v18; // r4
  int i; // r11
  int v20; // r8
  int v21; // r11
  int v22; // r7
  _BYTE v23[1016]; // [sp+58h] [-858h] BYREF
  _QWORD v24[140]; // [sp+450h] [-460h] BYREF

  HIDWORD(v6) = base;
  if ( num != 0 )
  {
    v7 = 0;
    LODWORD(a6) = num - 1;
    v24[0] = a6;
    do
    {
      v8 = v7;
      v9 = v24[v7];
      v10 = HIDWORD(v9);
      LODWORD(v6) = v24[v7];
      if ( (int)v9 - HIDWORD(v9) < 4 || v7 >= 127 )
      {
        for ( ; (int)v6 > SHIDWORD(v9); LODWORD(v6) = v6 - 1 )
        {
          v20 = HIDWORD(v9);
          v21 = HIDWORD(v9) + 1;
          if ( HIDWORD(v9) + 1 <= (int)v6 )
          {
            v22 = v6 - HIDWORD(v9);
            do
            {
              if ( *(__int16 *)(60 * v21 + HIDWORD(v6) + 52) - *(__int16 *)(60 * v20 + HIDWORD(v6) + 52) > 0 )
                v20 = v21;
              --v22;
              ++v21;
            }
            while ( v22 != 0 );
          }
          SwapValues<idAnimator_AF::idAFJointMod>(
            a: (idAnimator_AF::idAFJointMod *)(60 * v20 + HIDWORD(v6)),
            b: (idAnimator_AF::idAFJointMod *)(60 * v6 + HIDWORD(v6)));
        }
        --v7;
      }
      else
      {
        v11 = v9 + HIDWORD(v9);
        v12 = *(unsigned __int64 *)((char *)&a6 - 4) >> 63;
        LODWORD(a5) = v12 + v9 + HIDWORD(v9);
        v13 = (idAnimator_AF::idAFJointMod *)(60 * HIDWORD(v12) + HIDWORD(v6));
        v14 = v13;
        SwapValues<idAnimator_AF::idAFJointMod>(
          a: v13,
          b: (idAnimator_AF::idAFJointMod *)(60 * (a5 >> 1) + HIDWORD(v6)));
        LODWORD(v6) = v6 - 1;
        p_jointIndex = &v13->jointIndex;
        while ( 1 )
        {
          value = p_jointIndex->value;
          if ( *(__int16 *)(60 * v10 + HIDWORD(v6) + 52) - value < 0 )
          {
            do
              ++v10;
            while ( v10 < (int)v6 && *(__int16 *)(60 * v10 + HIDWORD(v6) + 52) - value < 0 );
          }
          v17 = (idAnimator_AF::idAFJointMod *)(60 * v6 + HIDWORD(v6));
          if ( v17->jointIndex.value - value > 0 )
            break;
LABEL_12:
          if ( v10 < (int)v6 )
          {
            SwapValues<idAnimator_AF::idAFJointMod>(
              a: (idAnimator_AF::idAFJointMod *)(60 * v10++ + HIDWORD(v6)),
              b: v17);
            LODWORD(v6) = v6 - 1;
            if ( v10 < (int)v6 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v6) = v6 - 1;
          if ( (int)v6 <= v10 )
            break;
          v17 = (idAnimator_AF::idAFJointMod *)(60 * v6 + HIDWORD(v6));
          if ( v17->jointIndex.value - value <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v18 = (idAnimator_AF::idAFJointMod *)(60 * v10 + HIDWORD(v6));
        for ( i = p_jointIndex->value;
              v18->jointIndex.value - i <= 0;
              v18 = (idAnimator_AF::idAFJointMod *)(60 * v10 + HIDWORD(v6)) )
        {
          if ( v10 >= (int)v9 )
            break;
          ++v10;
        }
        for ( ; *(__int16 *)(60 * v6 + HIDWORD(v6) + 52) - i >= 0; LODWORD(v6) = v6 - 1 )
        {
          if ( SHIDWORD(v9) >= (int)v6 )
            break;
        }
        SwapValues<idAnimator_AF::idAFJointMod>(a: v14, b: v18);
        LODWORD(a6) = v23;
        ++v7;
        v24[v8 + 1] = v9;
        *(_QWORD *)&v23[v8 * 8] = *(__int64 *)((char *)&v6 - 4);
        v24[v8] = v6;
      }
    }
    while ( v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@UearVert_t@@VidSort_Ears@@@@UBAXPAUearVert_t@@I@Z
// EA  : 0x8278D688
// RVA : 0x0078D688
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<earVert_t,idSort_Ears>::Sort(
        idSort_Quick<earVert_t,idSort_Ears> *this,
        earVert_t *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  __int64 v7; // r28
  int v8; // r2 OVERLAPPED
  int v9; // r31 OVERLAPPED
  int v10; // r30 OVERLAPPED
  __int64 v11; // r6
  int v12; // r3 OVERLAPPED
  earVert_t *v13; // r11
  __int64 v14; // r10
  unsigned __int64 v15; // r8 OVERLAPPED
  int i1; // r29
  int i2; // r26
  double v18; // fp13
  earVert_t *v19; // r11
  int v20; // r25
  int v21; // r24
  int v22; // r23
  double v23; // fp13
  earVert_t *v24; // r11
  double v25; // fp0
  int v26; // r31
  int v27; // r11
  int v28; // r10
  int v29; // r5
  earVert_t *v30; // r9
  int v31; // r7
  earVert_t *v32; // r11
  float v33; // r25
  __int64 v34; // [sp+10h] [-8A0h]
  __int64 v35; // [sp+18h] [-898h]
  int v36; // [sp+20h] [-890h]
  int v37; // [sp+24h] [-88Ch]
  int v38; // [sp+28h] [-888h]
  float v39; // [sp+3Ch] [-874h]
  int i3; // [sp+48h] [-868h]
  float cross; // [sp+4Ch] [-864h]
  _QWORD v42[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v42[0] = v7;
    v42[128] = a7;
    do
    {
      *(_QWORD *)&v9 = v42[(_DWORD)v7];
      v11 = *(_QWORD *)(8 * v7 + v10);
      v12 = v42[v7];
      if ( (int)v11 - v9 < 4 || (int)v7 >= 127 )
      {
        if ( v12 < (int)v11 )
        {
          v26 = v11 - 3;
          do
          {
            v27 = v12;
            v28 = v12 + 1;
            if ( v12 + 1 <= (int)v11 )
            {
              if ( 4 - (v12 + 1) + v26 >= 4 )
              {
                v29 = v12 + 3;
                do
                {
                  v30 = &base[v28];
                  if ( v30->cross > (double)base[v27].cross )
                    v27 = v28;
                  if ( v30[1].cross > (double)base[v27].cross )
                    v27 = v29 - 1;
                  if ( base[v28 + 2].cross > (double)base[v27].cross )
                    v27 = v29;
                  if ( base[v28 + 3].cross > (double)base[v27].cross )
                    v27 = v29 + 1;
                  v28 += 4;
                  v29 += 4;
                }
                while ( v28 <= v26 );
              }
              if ( v28 <= (int)v11 )
              {
                v31 = v11 - v28 + 1;
                do
                {
                  if ( base[v28].cross > (double)base[v27].cross )
                    v27 = v28;
                  --v31;
                  ++v28;
                }
                while ( v31 != 0 );
              }
            }
            LODWORD(a7) = &base[v27];
            v32 = &base[v11];
            LODWORD(v11) = v11 - 1;
            --v26;
            v33 = *(float *)(a7 + 12);
            v36 = *(_DWORD *)a7;
            v37 = *(_DWORD *)(a7 + 4);
            v38 = *(_DWORD *)(a7 + 8);
            *(_DWORD *)a7 = v32->i1;
            *(_DWORD *)(a7 + 4) = v32->i2;
            *(_DWORD *)(a7 + 8) = v32->i3;
            *(float *)&a7 = v32->cross;
            *(_DWORD *)(a7 + 12) = HIDWORD(a7);
            v32->i1 = v36;
            v32->i2 = v37;
            v32->i3 = v38;
            v32->cross = v33;
          }
          while ( (int)v11 > v12 );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        v13 = &base[v11];
        LODWORD(a7) = v11 + v9;
        v15 = a7 >> 63;
        LODWORD(v14) = (a7 >> 63) + v11 + v9;
        HIDWORD(v14) = v11 - 1;
        LODWORD(v15) = &v13->cross;
        a7 = v14 >> 1;
        i3 = v13->i3;
        LODWORD(a7) = &base[a7];
        cross = v13->cross;
        i1 = v13->i1;
        i2 = v13->i2;
        v13->i1 = *(_DWORD *)a7;
        v13->i2 = *(_DWORD *)(a7 + 4);
        v13->i3 = *(_DWORD *)(a7 + 8);
        v13->cross = *(float *)(a7 + 12);
        *(_DWORD *)a7 = i1;
        *(_DWORD *)(a7 + 4) = i2;
        *(_DWORD *)(a7 + 8) = i3;
        *(float *)(a7 + 12) = cross;
        do
        {
          v18 = *(float *)v15;
          do
          {
            if ( base[v12].cross >= v18 )
              break;
            ++v12;
          }
          while ( v12 < SHIDWORD(a7) );
          while ( 1 )
          {
            v19 = &base[HIDWORD(a7)];
            if ( v19->cross <= v18 )
              break;
            --HIDWORD(a7);
            if ( SHIDWORD(a7) <= v12 )
              goto LABEL_14;
          }
          if ( v12 >= SHIDWORD(a7) )
            break;
          LODWORD(a7) = &base[v12++];
          --HIDWORD(a7);
          v20 = *(_DWORD *)a7;
          v21 = *(_DWORD *)(a7 + 4);
          v22 = *(_DWORD *)(a7 + 8);
          *(_DWORD *)a7 = v19->i1;
          v39 = *(float *)(a7 + 12);
          *(_DWORD *)(a7 + 4) = v19->i2;
          *(_DWORD *)(a7 + 8) = v19->i3;
          *(float *)(a7 + 12) = v19->cross;
          v19->i1 = v20;
          v19->i2 = v21;
          v19->i3 = v22;
          v19->cross = v39;
        }
        while ( v12 < SHIDWORD(a7) );
LABEL_14:
        v23 = *(float *)v15;
        while ( 1 )
        {
          v24 = &base[v12];
          v25 = v24->cross;
          if ( v25 >= v23 && v25 > v23 )
            break;
          if ( v12 >= (int)v11 )
            break;
          ++v12;
        }
        while ( base[HIDWORD(a7)].cross >= v23 && v9 < SHIDWORD(a7) )
          --HIDWORD(a7);
        LODWORD(v7) = v7 + 1;
        v34 = *(_QWORD *)HIDWORD(v15);
        v35 = *(_QWORD *)(HIDWORD(v15) + 8);
        *(_QWORD *)HIDWORD(v15) = *(_QWORD *)&v24->i1;
        LODWORD(v15) = v35;
        HIDWORD(v7) = v24->i3;
        *(_QWORD *)((char *)&v42[129] + HIDWORD(v11)) = v11;
        *(_DWORD *)(HIDWORD(v15) + 8) = HIDWORD(v7);
        *(_QWORD *)(HIDWORD(v11) + v10) = *(unsigned __int64 *)((char *)&a7 + 4);
        *(float *)&a7 = v24->cross;
        *(_DWORD *)(HIDWORD(v15) + 12) = HIDWORD(a7);
        *(_QWORD *)((char *)&v42[1] + HIDWORD(v11)) = *(_QWORD *)(&v8 - 1);
        *(_QWORD *)&v24->i1 = v34;
        *(_QWORD *)&v24->i3 = v35;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@UswfDisplayEntry_t@@VidSort_SpriteDepth@@@@UBAXPAUswfDisplayEntry_t@@I@Z
// EA  : 0x827929C0
// RVA : 0x007929C0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<swfDisplayEntry_t,idSort_SpriteDepth>::Sort(
        idSort_Quick<swfDisplayEntry_t,idSort_SpriteDepth> *this,
        swfDisplayEntry_t *base,
        unsigned int num,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // r20
  __int64 v7; // r29
  int v8; // r25
  int v9; // r21 OVERLAPPED
  __int64 v10; // r23
  int v11; // r27
  int v12; // r11
  unsigned __int64 v13; // r10
  swfDisplayEntry_t *v14; // r31
  swfDisplayEntry_t *v15; // r30
  swfDisplayEntry_t *v16; // r24
  __int64 v17; // r27
  unsigned int v18; // r11
  int v19; // r30
  _WORD *v20; // r31
  __int16 v21; // r4
  __int16 v22; // r3
  double v23; // fp0
  double v24; // fp13
  double v25; // fp12
  __int16 v26; // r11
  __int16 v27; // r10
  float v28; // r9
  float v29; // r8
  double v30; // fp7
  double v31; // fp6
  double v32; // fp5
  double v33; // fp4
  double v34; // fp3
  double v35; // fp2
  double v36; // fp1
  double v37; // fp13
  double v38; // fp12
  double v39; // fp11
  double v40; // fp10
  unsigned int v41; // r11
  swfDisplayEntry_t *v42; // r31
  int v43; // r10
  int v44; // r11
  int v45; // r7
  _WORD *v46; // r31
  int v47; // r30
  __int16 v48; // r5
  __int16 v49; // r4
  __int16 v50; // r3
  double v51; // fp0
  double v52; // fp13
  double v53; // fp12
  double v54; // fp11
  double v55; // fp10
  double v56; // fp9
  __int16 v57; // r11
  double v58; // fp1
  double v59; // fp0
  double v60; // fp13
  double v61; // fp12
  double v62; // fp10
  double v63; // fp9
  double v64; // fp8
  double v65; // fp7
  float v66[19]; // [sp+50h] [-9B0h] BYREF
  float v67[19]; // [sp+A0h] [-960h] BYREF
  swfDisplayEntry_t v68; // [sp+F0h] [-910h] BYREF
  swfDisplayEntry_t v69; // [sp+140h] [-8C0h] BYREF
  __int64 v70; // [sp+190h] [-870h] BYREF
  _BYTE v71[1016]; // [sp+198h] [-868h] BYREF
  __int64 v72; // [sp+590h] [-470h]
  _BYTE v73[1128]; // [sp+598h] [-468h] BYREF

  HIDWORD(v7) = base;
  if ( num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v70 = v6;
    v72 = a6;
    do
    {
      v8 = 8 * v6;
      *(_QWORD *)(&v9 - 1) = *(_QWORD *)&v71[8 * (_DWORD)v6 - 8];
      v10 = *(_QWORD *)(8 * v6 + v9);
      LODWORD(v7) = HIDWORD(v10);
      v11 = *(_DWORD *)(8 * v6 + v9 + 4);
      if ( (int)v10 - HIDWORD(v10) < 4 || (int)v6 >= 127 )
      {
        for ( ; v11 > SHIDWORD(v10); *(_DWORD *)(v47 + 72) = a5 )
        {
          v43 = HIDWORD(v10);
          v44 = HIDWORD(v10) + 1;
          if ( HIDWORD(v10) + 1 <= v11 )
          {
            v45 = v11 - HIDWORD(v10);
            do
            {
              if ( *(unsigned __int16 *)(76 * v44 + HIDWORD(v7) + 2) > (unsigned int)*(unsigned __int16 *)(76 * v43 + HIDWORD(v7) + 2) )
                v43 = v44;
              --v45;
              ++v44;
            }
            while ( v45 != 0 );
          }
          v46 = (_WORD *)(76 * v43 + HIDWORD(v7));
          v47 = 76 * v11 + HIDWORD(v7);
          memcpy(Dst: v67, Src: v46, Size: sizeof(v67));
          v48 = HIWORD(v67[0]);
          v49 = LOWORD(v67[0]);
          v50 = HIWORD(v67[1]);
          --v11;
          v51 = v67[2];
          *v46 = *(_WORD *)v47;
          v52 = v67[3];
          v53 = v67[4];
          v46[1] = *(_WORD *)(v47 + 2);
          v54 = v67[5];
          v55 = v67[6];
          v46[2] = *(_WORD *)(v47 + 4);
          v56 = v67[7];
          LODWORD(a6) = *(unsigned __int16 *)(v47 + 6);
          v46[3] = a6;
          v57 = LOWORD(v67[1]);
          *((float *)v46 + 2) = *(float *)(v47 + 8);
          *(float *)&a6 = v67[17];
          *((float *)&a5 + 1) = v67[18];
          *((float *)v46 + 3) = *(float *)(v47 + 12);
          *((float *)v46 + 4) = *(float *)(v47 + 16);
          *((float *)v46 + 5) = *(float *)(v47 + 20);
          *((float *)v46 + 6) = *(float *)(v47 + 24);
          *((float *)v46 + 7) = *(float *)(v47 + 28);
          *((float *)v46 + 8) = *(float *)(v47 + 32);
          *((float *)v46 + 9) = *(float *)(v47 + 36);
          *((float *)v46 + 10) = *(float *)(v47 + 40);
          *((float *)v46 + 11) = *(float *)(v47 + 44);
          *((float *)v46 + 12) = *(float *)(v47 + 48);
          *((float *)v46 + 13) = *(float *)(v47 + 52);
          *((float *)v46 + 14) = *(float *)(v47 + 56);
          *((float *)v46 + 15) = *(float *)(v47 + 60);
          *((float *)v46 + 16) = *(float *)(v47 + 64);
          HIDWORD(a5) = *(_DWORD *)(v47 + 68);
          v58 = v67[8];
          *((_DWORD *)v46 + 17) = HIDWORD(a5);
          *((_DWORD *)v46 + 18) = *(_DWORD *)(v47 + 72);
          *(_WORD *)v47 = v48;
          *(_WORD *)(v47 + 2) = v49;
          *(_WORD *)(v47 + 4) = v50;
          *(_WORD *)(v47 + 6) = v57;
          *(float *)(v47 + 8) = v51;
          v59 = v67[9];
          *(float *)(v47 + 12) = v52;
          *(float *)(v47 + 16) = v53;
          *(float *)(v47 + 20) = v54;
          *(float *)(v47 + 24) = v55;
          *(float *)(v47 + 28) = v56;
          v60 = v67[10];
          v61 = v67[11];
          *(float *)(v47 + 32) = v58;
          *(float *)(v47 + 36) = v59;
          *(float *)(v47 + 40) = v60;
          *(float *)(v47 + 44) = v61;
          v62 = v67[13];
          v63 = v67[14];
          v64 = v67[15];
          v65 = v67[16];
          *(float *)(v47 + 48) = v67[12];
          *(float *)(v47 + 52) = v62;
          *(float *)(v47 + 56) = v63;
          *(float *)(v47 + 60) = v64;
          *(_DWORD *)(v47 + 68) = HIDWORD(a6);
          *(float *)(v47 + 64) = v65;
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        v12 = v10 + HIDWORD(v10);
        v13 = *(unsigned __int64 *)((char *)&a6 - 4) >> 63;
        LODWORD(a5) = v13 + v10 + HIDWORD(v10);
        v14 = (swfDisplayEntry_t *)(76 * HIDWORD(v13) + HIDWORD(v7));
        v15 = (swfDisplayEntry_t *)(76 * (a5 >> 1) + HIDWORD(v7));
        v68 = *v14;
        swfDisplayEntry_t::operator=(this: v14, __that: v15);
        swfDisplayEntry_t::operator=(this: v15, __that: &v68);
        v16 = v14;
        LODWORD(v17) = v11 - 1;
        HIDWORD(v17) = &v14->depth;
        while ( 1 )
        {
          v18 = (unsigned __int16)*(_WORD *)HIDWORD(v17);
          if ( *(unsigned __int16 *)(76 * v7 + HIDWORD(v7) + 2) < v18 )
          {
            do
              LODWORD(v7) = v7 + 1;
            while ( (int)v7 < (int)v17 && (int)(*(unsigned __int16 *)(76 * v7 + HIDWORD(v7) + 2) - v18) < 0 );
          }
          v19 = 76 * v17 + HIDWORD(v7);
          if ( (int)(*(unsigned __int16 *)(v19 + 2) - v18) > 0 )
            break;
LABEL_12:
          if ( (int)v7 < (int)v17 )
          {
            v20 = (_WORD *)(76 * v7 + HIDWORD(v7));
            memcpy(Dst: v66, Src: v20, Size: sizeof(v66));
            v21 = HIWORD(v66[0]);
            v22 = LOWORD(v66[0]);
            v23 = v66[2];
            v24 = v66[3];
            LODWORD(v7) = v7 + 1;
            *v20 = *(_WORD *)v19;
            v25 = v66[4];
            LODWORD(v17) = v17 - 1;
            v20[1] = *(_WORD *)(v19 + 2);
            v20[2] = *(_WORD *)(v19 + 4);
            v20[3] = *(_WORD *)(v19 + 6);
            *((float *)v20 + 2) = *(float *)(v19 + 8);
            v26 = HIWORD(v66[1]);
            v27 = LOWORD(v66[1]);
            *((float *)v20 + 3) = *(float *)(v19 + 12);
            v28 = v66[17];
            v29 = v66[18];
            *((float *)v20 + 4) = *(float *)(v19 + 16);
            *((float *)v20 + 5) = *(float *)(v19 + 20);
            *((float *)v20 + 6) = *(float *)(v19 + 24);
            *((float *)v20 + 7) = *(float *)(v19 + 28);
            *((float *)v20 + 8) = *(float *)(v19 + 32);
            *((float *)v20 + 9) = *(float *)(v19 + 36);
            *((float *)v20 + 10) = *(float *)(v19 + 40);
            *((float *)v20 + 11) = *(float *)(v19 + 44);
            *((float *)v20 + 12) = *(float *)(v19 + 48);
            *((float *)v20 + 13) = *(float *)(v19 + 52);
            *((float *)v20 + 14) = *(float *)(v19 + 56);
            *((float *)v20 + 15) = *(float *)(v19 + 60);
            *((float *)v20 + 16) = *(float *)(v19 + 64);
            v30 = v66[5];
            *((_DWORD *)v20 + 17) = *(_DWORD *)(v19 + 68);
            v31 = v66[6];
            v32 = v66[7];
            *((_DWORD *)v20 + 18) = *(_DWORD *)(v19 + 72);
            v33 = v66[8];
            *(_WORD *)v19 = v21;
            v34 = v66[9];
            *(_WORD *)(v19 + 2) = v22;
            v35 = v66[10];
            *(_WORD *)(v19 + 4) = v26;
            v36 = v66[11];
            *(_WORD *)(v19 + 6) = v27;
            *(float *)(v19 + 8) = v23;
            *(float *)(v19 + 12) = v24;
            *(float *)(v19 + 16) = v25;
            *(float *)(v19 + 20) = v30;
            *(float *)(v19 + 24) = v31;
            *(float *)(v19 + 28) = v32;
            *(float *)(v19 + 32) = v33;
            *(float *)(v19 + 36) = v34;
            *(float *)(v19 + 40) = v35;
            *(float *)(v19 + 44) = v36;
            v37 = v66[13];
            v38 = v66[14];
            v39 = v66[15];
            v40 = v66[16];
            *(float *)(v19 + 48) = v66[12];
            *(float *)(v19 + 52) = v37;
            *(float *)(v19 + 56) = v38;
            *(float *)(v19 + 60) = v39;
            *(float *)(v19 + 68) = v28;
            *(float *)(v19 + 64) = v40;
            *(float *)(v19 + 72) = v29;
            if ( (int)v7 < (int)v17 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v17) = v17 - 1;
          if ( (int)v17 <= (int)v7 )
            break;
          v19 = 76 * v17 + HIDWORD(v7);
          if ( (int)(*(unsigned __int16 *)(v19 + 2) - v18) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v41 = (unsigned __int16)*(_WORD *)HIDWORD(v17);
        v42 = (swfDisplayEntry_t *)(76 * v7 + HIDWORD(v7));
        if ( v42->depth <= v41 )
        {
          do
          {
            if ( (int)v7 >= (int)v10 )
              break;
            LODWORD(v7) = v7 + 1;
            v42 = (swfDisplayEntry_t *)(76 * v7 + HIDWORD(v7));
          }
          while ( (int)(v42->depth - v41) <= 0 );
        }
        for ( ; (int)(*(unsigned __int16 *)(76 * v17 + HIDWORD(v7) + 2) - v41) >= 0; LODWORD(v17) = v17 - 1 )
        {
          if ( SHIDWORD(v10) >= (int)v17 )
            break;
        }
        v69 = *v16;
        swfDisplayEntry_t::operator=(this: v16, __that: v42);
        swfDisplayEntry_t::operator=(this: v42, __that: &v69);
        LODWORD(a6) = v71;
        LODWORD(v6) = v6 + 1;
        *(_QWORD *)&v73[v8] = v10;
        *(_QWORD *)&v71[v8] = v7;
        *(_QWORD *)(v8 + v9) = v17;
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@PAUPolygon_t@idCutterClip@@VidSort_Polygons@2@@@UBAXPAPAUPolygon_t@idCutterClip@@I@Z
// EA  : 0x827B4D88
// RVA : 0x007B4D88
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idCutterClip::Polygon_t *,idCutterClip::idSort_Polygons>::Sort(
        idSort_Quick<idCutterClip::Polygon_t *,idCutterClip::idSort_Polygons> *this,
        idCutterClip::Polygon_t **base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r20
  int v10; // r24
  int v11; // r21 OVERLAPPED
  __int64 v12; // r23
  __int64 v13; // r30 OVERLAPPED
  __int128 v14; // r11
  const idCutterClip::Polygon_t **v15; // r27
  const idCutterClip::Polygon_t *v16; // r28
  const idCutterClip::Polygon_t **v17; // r28
  int v18; // r3
  idCutterClip::Polygon_t *v19; // r9
  const idCutterClip::Polygon_t *v20; // r26
  const idCutterClip::Polygon_t **i; // r28 OVERLAPPED
  int v22; // r26
  int v23; // r27
  int v24; // r28
  int v25; // r10
  idCutterClip::Polygon_t *v26; // r8
  _QWORD v27[270]; // [sp+50h] [-870h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v27[0] = v7;
    v27[128] = a7;
    do
    {
      v10 = v7;
      *(_QWORD *)(&v11 - 1) = v27[(_DWORD)v7];
      v12 = *(_QWORD *)(8 * v7 + v11);
      LODWORD(v13) = HIDWORD(v12);
      HIDWORD(v13) = *(_DWORD *)(8 * v7 + v11 + 4);
      if ( (int)v12 - HIDWORD(v12) < 4 || (int)v7 >= 127 )
      {
        if ( SHIDWORD(v12) < SHIDWORD(v13) )
        {
          v22 = HIDWORD(v12) + 1;
          do
          {
            v23 = HIDWORD(v12);
            v24 = HIDWORD(v12) + 1;
            if ( v22 <= SHIDWORD(v13) )
            {
              v25 = v22;
              do
              {
                if ( idCutterClip::idSort_Polygons::Compare(
                       (idCutterClip::idSort_Polygons *)this,
                       a: base[v25],
                       b: base[v23]) > 0 )
                  v23 = v24;
                v25 = ++v24;
              }
              while ( v24 <= SHIDWORD(v13) );
            }
            v26 = base[v23];
            base[v23] = base[HIDWORD(v13)];
            base[HIDWORD(v13)--] = v26;
          }
          while ( SHIDWORD(v13) > SHIDWORD(v12) );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v14) = v12 + HIDWORD(v12);
        DWORD2(v14) = 4 * v12;
        v15 = (const idCutterClip::Polygon_t **)&base[v12];
        LODWORD(v14) = ((unsigned __int64)v14 >> 63) + v12 + HIDWORD(v12);
        --HIDWORD(v13);
        *(_QWORD *)((char *)&v14 + 4) = (__int64)v14 >> 1;
        DWORD1(v14) = *v15;
        *v15 = base[DWORD2(v14)];
        base[DWORD2(v14)] = (idCutterClip::Polygon_t *)DWORD1(v14);
        while ( 1 )
        {
          v16 = *v15;
          if ( idCutterClip::idSort_Polygons::Compare(
                 (idCutterClip::idSort_Polygons *)this,
                 a: base[(_DWORD)v13],
                 b: *v15) < 0 )
          {
            do
              LODWORD(v13) = v13 + 1;
            while ( (int)v13 < SHIDWORD(v13)
                 && idCutterClip::idSort_Polygons::Compare(
                      (idCutterClip::idSort_Polygons *)this,
                      a: base[(_DWORD)v13],
                      b: *v15) < 0 );
          }
          v18 = idCutterClip::idSort_Polygons::Compare(
                  (idCutterClip::idSort_Polygons *)this,
                  a: base[HIDWORD(v13)],
                  b: v16);
          v17 = (const idCutterClip::Polygon_t **)&base[HIDWORD(v13)];
          if ( v18 > 0 )
            break;
LABEL_12:
          if ( (int)v13 < SHIDWORD(v13) )
          {
            --HIDWORD(v13);
            v19 = base[(_DWORD)v13];
            base[(_DWORD)v13] = (idCutterClip::Polygon_t *)*v17;
            LODWORD(v13) = v13 + 1;
            *v17 = v19;
            if ( (int)v13 < SHIDWORD(v13) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v13);
          if ( SHIDWORD(v13) <= (int)v13 )
            break;
          v17 = (const idCutterClip::Polygon_t **)&base[HIDWORD(v13)];
          if ( idCutterClip::idSort_Polygons::Compare((idCutterClip::idSort_Polygons *)this, a: *v17, b: *v15) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v20 = *v15;
        for ( i = (const idCutterClip::Polygon_t **)&base[v13];
              idCutterClip::idSort_Polygons::Compare((idCutterClip::idSort_Polygons *)this, a: *i, b: *v15) <= 0;
              i = (const idCutterClip::Polygon_t **)&base[v13] )
        {
          if ( (int)v13 >= (int)v12 )
            break;
          LODWORD(v13) = v13 + 1;
        }
        if ( idCutterClip::idSort_Polygons::Compare(
               (idCutterClip::idSort_Polygons *)this,
               a: base[HIDWORD(v13)],
               b: v20) >= 0 )
        {
          do
          {
            if ( SHIDWORD(v12) >= SHIDWORD(v13) )
              break;
            --HIDWORD(v13);
          }
          while ( idCutterClip::idSort_Polygons::Compare(
                    (idCutterClip::idSort_Polygons *)this,
                    a: base[HIDWORD(v13)],
                    b: *v15) >= 0 );
        }
        LODWORD(v7) = v7 + 1;
        *v15 = *i;
        v27[v10 + 129] = v12;
        *i = v20;
        v27[v10 + 1] = v13;
        *(_QWORD *)(v10 * 8 + v11) = *(__int64 *)((char *)&v13 + 4);
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@HVidSort_AnimEventSort@@@@UBAXPAHI@Z
// EA  : 0x8280EA80
// RVA : 0x0080EA80
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<int,idSort_AnimEventSort>::Sort(
        idSort_Quick<int,idSort_AnimEventSort> *this,
        int *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r21
  int v10; // r25
  int v11; // r22 OVERLAPPED
  __int64 v12; // r24
  _BYTE v13[12]; // r30 OVERLAPPED
  int v14; // r27
  __int128 v15; // r11
  int *v16; // r27
  int v17; // r9
  int *j; // r27
  int v19; // r9
  int v20; // r28
  int i; // r30
  int v22; // r8
  _QWORD v23[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v23[0] = v7;
    v23[128] = a7;
    do
    {
      v10 = v7;
      *(_QWORD *)(&v11 - 1) = v23[(_DWORD)v7];
      v12 = *(_QWORD *)(8 * v7 + v11);
      *(_DWORD *)&v13[4] = HIDWORD(v12);
      v14 = *(_DWORD *)(8 * v7 + v11 + 4);
      if ( (int)v12 - HIDWORD(v12) < 4 || (int)v7 >= 127 )
      {
        for ( ; v14 > SHIDWORD(v12); --v14 )
        {
          v20 = HIDWORD(v12);
          for ( i = HIDWORD(v12) + 1; i <= v14; ++i )
          {
            if ( idSort_AnimEventSort::Compare((idSort_AnimEventSort *)this, a: &base[i], b: &base[v20]) > 0 )
              v20 = i;
          }
          v22 = base[v20];
          base[v20] = base[v14];
          base[v14] = v22;
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v15) = v12 + HIDWORD(v12);
        DWORD2(v15) = 4 * v12;
        *(_DWORD *)v13 = &base[v12];
        LODWORD(v15) = ((unsigned __int64)v15 >> 63) + v12 + HIDWORD(v12);
        *(_DWORD *)&v13[8] = v12 - 1;
        *(_QWORD *)((char *)&v15 + 4) = (__int64)v15 >> 1;
        DWORD1(v15) = **(_DWORD **)v13;
        **(_DWORD **)v13 = base[DWORD2(v15)];
        base[DWORD2(v15)] = DWORD1(v15);
        while ( 1 )
        {
          if ( idSort_AnimEventSort::Compare((idSort_AnimEventSort *)this, a: &base[*(_DWORD *)&v13[4]], b: &base[v12]) < 0 )
          {
            do
              ++*(_DWORD *)&v13[4];
            while ( *(int *)&v13[4] < *(int *)&v13[8]
                 && idSort_AnimEventSort::Compare(
                      (idSort_AnimEventSort *)this,
                      a: &base[*(_DWORD *)&v13[4]],
                      b: &base[v12]) < 0 );
          }
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_AnimEventSort::Compare((idSort_AnimEventSort *)this, a: v16, b: &base[v12]) > 0 )
            break;
LABEL_12:
          if ( *(int *)&v13[4] < *(int *)&v13[8] )
          {
            --*(_DWORD *)&v13[8];
            v17 = base[*(_DWORD *)&v13[4]];
            base[(*(_DWORD *)&v13[4])++] = *v16;
            *v16 = v17;
            if ( *(int *)&v13[4] < *(int *)&v13[8] )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --*(_DWORD *)&v13[8];
          if ( *(int *)&v13[8] <= *(int *)&v13[4] )
            break;
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_AnimEventSort::Compare((idSort_AnimEventSort *)this, a: v16, b: &base[v12]) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = &base[*(_DWORD *)&v13[4]];
              idSort_AnimEventSort::Compare((idSort_AnimEventSort *)this, a: j, b: &base[v12]) <= 0;
              j = &base[*(_DWORD *)&v13[4]] )
        {
          if ( *(int *)&v13[4] >= (int)v12 )
            break;
          ++*(_DWORD *)&v13[4];
        }
        for ( ;
              idSort_AnimEventSort::Compare((idSort_AnimEventSort *)this, a: &base[*(_DWORD *)&v13[8]], b: &base[v12]) >= 0;
              --*(_DWORD *)&v13[8] )
        {
          if ( SHIDWORD(v12) >= *(int *)&v13[8] )
            break;
        }
        v19 = **(_DWORD **)v13;
        LODWORD(v7) = v7 + 1;
        **(_DWORD **)v13 = *j;
        v23[v10 + 129] = v12;
        *j = v19;
        v23[v10 + 1] = *(_QWORD *)v13;
        *(_QWORD *)(v10 * 8 + v11) = *(_QWORD *)&v13[4];
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ??$SwapValues@Umd6AncestryNode_t@@@@YAXAAUmd6AncestryNode_t@@0@Z
// EA  : 0x82816AC8
// RVA : 0x00816AC8
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<md6AncestryNode_t>(md6AncestryNode_t *a, md6AncestryNode_t *b)
{
  const idDeclMD6 *decl; // r10
  idList<md6AncestryNode_t,5> *p_children; // r28
  const idDeclMD6 *v6; // [sp+50h] [-50h]
  idList<md6AncestryNode_t,5> v7[4]; // [sp+54h] [-4Ch] BYREF

  decl = a->decl;
  p_children = &a->children;
  v7[0].list = nullptr;
  v7[0].listStatic = 0;
  v6 = decl;
  idList<md6AncestryNode_t,5>::operator=(this: v7, other: &a->children);
  a->decl = b->decl;
  idList<md6AncestryNode_t,5>::operator=(this: p_children, other: &b->children);
  b->decl = v6;
  idList<md6AncestryNode_t,5>::operator=(this: &b->children, other: v7);
  if ( (v7[0].listStatic == 0 || v7[0].listStatic == 2) && v7[0].list != nullptr )
    idListArrayDelete<md6AncestryNode_t>(ptr: (char *)v7[0].list, num: v7[0].size);
}


// ========================================================================
// __unwind$243680
// EA  : 0x82816B60
// RVA : 0x00816B60
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_243680()
{
  int v0; // r12

  md6AncestryNode_t::~md6AncestryNode_t(this: (md6AncestryNode_t *)(v0 - 160 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@Umd6AncestryNode_t@@VSortByName@1@@@UBAXPAUmd6AncestryNode_t@@I@Z
// EA  : 0x82819858
// RVA : 0x00819858
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName>::Sort(
        idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName> *this,
        md6AncestryNode_t *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r22
  __int64 v8; // r30 OVERLAPPED
  int v9; // r26
  int v10; // r23 OVERLAPPED
  __int64 v11; // r25
  int v12; // r31 OVERLAPPED
  int v13; // r11
  __int64 v14; // r11
  md6AncestryNode_t *v15; // r27
  md6AncestryNode_t *v16; // r28
  md6AncestryNode_t *j; // r28
  int v18; // r28
  int i; // r27
  __int64 v20; // [sp+50h] [-860h] BYREF
  _BYTE v21[1016]; // [sp+58h] [-858h] BYREF
  __int64 v22; // [sp+450h] [-460h]
  _BYTE v23[1112]; // [sp+458h] [-458h] BYREF

  HIDWORD(v8) = base;
  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v20 = v7;
    v22 = a7;
    do
    {
      v9 = 8 * v7;
      *(_QWORD *)(&v10 - 1) = *(_QWORD *)&v21[8 * (_DWORD)v7 - 8];
      v11 = *(_QWORD *)(8 * v7 + v10);
      v12 = HIDWORD(v11);
      LODWORD(v8) = *(_DWORD *)(8 * v7 + v10 + 4);
      if ( (int)v11 - HIDWORD(v11) < 4 || (int)v7 >= 127 )
      {
        for ( ; (int)v8 > SHIDWORD(v11); LODWORD(v8) = v8 - 1 )
        {
          v18 = HIDWORD(v11);
          for ( i = HIDWORD(v11) + 1; i <= (int)v8; ++i )
          {
            if ( idStr::Icmp(
                   s1: *(const char **)(*(_DWORD *)(20 * i + HIDWORD(v8)) + 8),
                   s2: *(const char **)(*(_DWORD *)(20 * v18 + HIDWORD(v8)) + 8)) > 0 )
              v18 = i;
          }
          SwapValues<md6AncestryNode_t>(
            a: (md6AncestryNode_t *)(20 * v18 + HIDWORD(v8)),
            b: (md6AncestryNode_t *)(20 * v8 + HIDWORD(v8)));
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        v13 = v11 + HIDWORD(v11);
        LODWORD(v14) = (*(unsigned __int64 *)((char *)&a7 - 4) >> 63) + v11 + HIDWORD(v11);
        HIDWORD(v14) = 5 * v11;
        v15 = (md6AncestryNode_t *)(20 * v11 + HIDWORD(v8));
        SwapValues<md6AncestryNode_t>(a: v15, b: (md6AncestryNode_t *)(20 * (v14 >> 1) + HIDWORD(v8)));
        LODWORD(v8) = v8 - 1;
        while ( 1 )
        {
          if ( idStr::Icmp(s1: *(const char **)(*(_DWORD *)(20 * v12 + HIDWORD(v8)) + 8), s2: v15->decl->name.str) < 0 )
          {
            do
              ++v12;
            while ( v12 < (int)v8
                 && idStr::Icmp(s1: *(const char **)(*(_DWORD *)(20 * v12 + HIDWORD(v8)) + 8), s2: v15->decl->name.str) < 0 );
          }
          v16 = (md6AncestryNode_t *)(20 * v8 + HIDWORD(v8));
          if ( idStr::Icmp(s1: v16->decl->name.str, s2: v15->decl->name.str) > 0 )
            break;
LABEL_12:
          if ( v12 < (int)v8 )
          {
            SwapValues<md6AncestryNode_t>(a: (md6AncestryNode_t *)(20 * v12++ + HIDWORD(v8)), b: v16);
            LODWORD(v8) = v8 - 1;
            if ( v12 < (int)v8 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v8) = v8 - 1;
          if ( (int)v8 <= v12 )
            break;
          v16 = (md6AncestryNode_t *)(20 * v8 + HIDWORD(v8));
          if ( idStr::Icmp(s1: v16->decl->name.str, s2: v15->decl->name.str) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = (md6AncestryNode_t *)(20 * v12 + HIDWORD(v8));
              idStr::Icmp(s1: j->decl->name.str, s2: v15->decl->name.str) <= 0;
              j = (md6AncestryNode_t *)(20 * v12 + HIDWORD(v8)) )
        {
          if ( v12 >= (int)v11 )
            break;
          ++v12;
        }
        for ( ;
              idStr::Icmp(s1: *(const char **)(*(_DWORD *)(20 * v8 + HIDWORD(v8)) + 8), s2: v15->decl->name.str) >= 0;
              LODWORD(v8) = v8 - 1 )
        {
          if ( SHIDWORD(v11) >= (int)v8 )
            break;
        }
        SwapValues<md6AncestryNode_t>(a: (md6AncestryNode_t *)(20 * v11 + HIDWORD(v8)), b: j);
        LODWORD(a7) = v21;
        LODWORD(v7) = v7 + 1;
        *(_QWORD *)&v23[v9] = v11;
        *(_QWORD *)&v21[v9] = *(__int64 *)((char *)&v8 - 4);
        *(_QWORD *)(v9 + v10) = v8;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@UusedJoints_t@@VidSort_MeshTris@@@@UBAXPAUusedJoints_t@@I@Z
// EA  : 0x82848450
// RVA : 0x00848450
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<usedJoints_t,idSort_MeshTris>::Sort(
        idSort_Quick<usedJoints_t,idSort_MeshTris> *this,
        usedJoints_t *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  __int64 v7; // r28
  int v8; // r2 OVERLAPPED
  int v9; // r31
  __int64 v10; // r30
  __int64 v11; // r6 OVERLAPPED
  int v12; // r3 OVERLAPPED
  __int128 v13; // r10
  int v14; // r7
  __int64 v15; // r9
  int v16; // r9
  usedJoints_t *v17; // r11
  int v18; // r10
  int v19; // r11
  usedJoints_t *v20; // r11
  int v21; // r10
  int v22; // r10
  usedJoints_t *v23; // r10
  usedJoints_t v24; // r27
  int v25; // r8
  int v26; // r11
  int v27; // r11
  usedJoints_t *v28; // r11
  int v29; // r10
  int v30; // r11
  __int64 v31; // r8
  int v32; // r7
  int v33; // r31
  usedJoints_t *v34; // r11
  usedJoints_t *v35; // r10
  int value; // r9
  int v37; // r8
  usedJoints_t *v38; // r11
  usedJoints_t v39; // r8
  _QWORD v40[262]; // [sp+10h] [-830h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v40[0] = v7;
    v40[128] = a7;
    do
    {
      v9 = v7;
      v10 = v40[(_DWORD)v7];
      v11 = *(_QWORD *)(8 * v7 + HIDWORD(v10));
      v12 = v40[v7];
      if ( (int)v11 - (int)v10 < 4 || (int)v7 >= 127 )
      {
        for ( ; (int)v11 > v12; *v38 = v39 )
        {
          HIDWORD(v11) = v12;
          v32 = v12 + 1;
          if ( v12 + 1 <= (int)v11 )
          {
            v33 = v11 - v12;
            do
            {
              v34 = &base[HIDWORD(v11)];
              v35 = &base[v32];
              value = v34->firstJoint.value;
              v37 = v35->firstJoint.value;
              if ( v37 == value )
              {
                value = v34->lastJoint.value;
                v37 = v35->lastJoint.value;
              }
              if ( v37 - value > 0 )
                HIDWORD(v11) = v32;
              --v33;
              ++v32;
            }
            while ( v33 != 0 );
          }
          v38 = &base[v11];
          LODWORD(a7) = &base[HIDWORD(v11)];
          LODWORD(v11) = v11 - 1;
          HIDWORD(a7) = v38->triNum;
          v39 = *(usedJoints_t *)a7;
          *(_DWORD *)a7 = v38->triNum;
          v39.triNum = *(_DWORD *)&v38->firstJoint.value;
          *(_DWORD *)(a7 + 4) = v39.triNum;
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(a7) = v11 + v10;
        *(_QWORD *)((char *)&v13 + 4) = a7 >> 63;
        LODWORD(v13) = DWORD2(v13) + v11 + v10;
        v14 = v11 - 1;
        HIDWORD(v11) = &base[v11];
        LODWORD(v13) = 8 * ((__int64)v13 >> 1);
        v15 = *(_QWORD *)HIDWORD(v11);
        HIDWORD(v15) = HIDWORD(v11) + 4;
        LODWORD(v13) = (char *)base + v13;
        *(_QWORD *)HIDWORD(v11) = *(_QWORD *)v13;
        *(_QWORD *)v13 = v15;
        do
        {
          v16 = (__int16)*(_WORD *)HIDWORD(v15);
          do
          {
            v17 = &base[v12];
            v18 = v17->firstJoint.value;
            if ( v18 == v16 )
              v19 = v17->lastJoint.value - *(__int16 *)(HIDWORD(v11) + 6);
            else
              v19 = v18 - v16;
            if ( v19 >= 0 )
              break;
            ++v12;
          }
          while ( v12 < v14 );
          while ( 1 )
          {
            v20 = &base[v14];
            v21 = v20->firstJoint.value;
            v22 = v21 == v16 ? v20->lastJoint.value - *(__int16 *)(HIDWORD(v11) + 6) : v21 - v16;
            if ( v22 <= 0 )
              break;
            if ( --v14 <= v12 )
              goto LABEL_20;
          }
          if ( v12 >= v14 )
            break;
          v23 = &base[v12++];
          --v14;
          v24 = *v23;
          v23->triNum = v20->triNum;
          *(_DWORD *)&v23->firstJoint.value = *(_DWORD *)&v20->firstJoint.value;
          *v20 = v24;
        }
        while ( v12 < v14 );
LABEL_20:
        v25 = (__int16)*(_WORD *)HIDWORD(v15);
        while ( 1 )
        {
          HIDWORD(a7) = &base[v12];
          v26 = *(__int16 *)(HIDWORD(a7) + 4);
          v27 = v26 == v25 ? *(__int16 *)(HIDWORD(a7) + 6) - *(__int16 *)(HIDWORD(v11) + 6) : v26 - v25;
          if ( v27 > 0 || v12 >= (int)v11 )
            break;
          ++v12;
        }
        while ( 1 )
        {
          v28 = &base[v14];
          v29 = v28->firstJoint.value;
          v30 = v29 == v25 ? v28->lastJoint.value - *(__int16 *)(HIDWORD(v11) + 6) : v29 - v25;
          if ( v30 < 0 || (int)v10 >= v14 )
            break;
          --v14;
        }
        v31 = *(_QWORD *)HIDWORD(v11);
        LODWORD(v7) = v7 + 1;
        *(_QWORD *)HIDWORD(v11) = *(_QWORD *)HIDWORD(a7);
        v40[v9 + 129] = v11;
        *(_QWORD *)HIDWORD(a7) = v31;
        v40[v9 + 1] = *(_QWORD *)(&v8 - 1);
        *(_QWORD *)(v9 * 8 + HIDWORD(v10)) = *(__int64 *)((char *)&v11 - 4);
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidSortedMaterial@@VidSort_SortedMaterial@@@@UBAXPAVidSortedMaterial@@I@Z
// EA  : 0x8286D6A0
// RVA : 0x0086D6A0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idSortedMaterial,idSort_SortedMaterial>::Sort(
        idSort_Quick<idSortedMaterial,idSort_SortedMaterial> *this,
        idSortedMaterial *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  __int64 v7; // r28
  int v8; // r2 OVERLAPPED
  int v9; // r31
  __int64 v10; // r30
  _BYTE v11[12]; // r7 OVERLAPPED
  int v12; // r3 OVERLAPPED
  idSortedMaterial *v13; // r11
  __int128 v14; // r10
  const idMaterial **p_material; // r8
  int materialNumber; // r25
  int v17; // r9
  idSortedMaterial *v18; // r11
  int v19; // r10
  int v20; // r11
  idSortedMaterial *v21; // r11
  int v22; // r10
  int v23; // r10
  idSortedMaterial *v24; // r10
  const char *name; // r25
  const idMaterial *v26; // r24
  int v27; // r23
  int v28; // r22
  int v29; // r8
  idSortedMaterial *v30; // r11
  int v31; // r10
  int v32; // r10
  idSortedMaterial *v33; // r10
  int v34; // r9
  int v35; // r10
  int v36; // r31
  idSortedMaterial *v37; // r11
  idSortedMaterial *v38; // r10
  int v39; // r9
  int v40; // r8
  int v41; // r11
  idSortedMaterial *v42; // r11
  __int64 v43; // [sp+10h] [-8A0h]
  __int64 v44; // [sp+18h] [-898h]
  const char *v45; // [sp+20h] [-890h]
  const idMaterial *v46; // [sp+24h] [-88Ch]
  int v47; // [sp+28h] [-888h]
  int v48; // [sp+2Ch] [-884h]
  const idMaterial *material; // [sp+44h] [-86Ch]
  int index; // [sp+4Ch] [-864h]
  _QWORD v51[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v51[0] = v7;
    v51[128] = a7;
    do
    {
      v9 = v7;
      v10 = v51[(_DWORD)v7];
      *(_QWORD *)v11 = *(_QWORD *)(8 * v7 + HIDWORD(v10));
      v12 = v51[v7];
      if ( *(_DWORD *)&v11[4] - (int)v10 < 4 || (int)v7 >= 127 )
      {
        for ( ; *(int *)&v11[4] > v12; v42->index = v48 )
        {
          *(_DWORD *)v11 = v12;
          *(_DWORD *)&v11[8] = v12 + 1;
          if ( v12 + 1 <= *(int *)&v11[4] )
          {
            v36 = *(_DWORD *)&v11[4] - v12;
            do
            {
              v37 = &base[*(_DWORD *)v11];
              v38 = &base[*(_DWORD *)&v11[8]];
              v39 = (_cntlzw(v37->material->coverage - 1) & 0x20) != 0;
              v40 = (_cntlzw(v38->material->coverage - 1) & 0x20) != 0;
              if ( v40 == v39 )
                v41 = v38->materialNumber - v37->materialNumber;
              else
                v41 = v40 - v39;
              if ( v41 > 0 )
                *(_DWORD *)v11 = *(_DWORD *)&v11[8];
              --v36;
              ++*(_DWORD *)&v11[8];
            }
            while ( v36 != 0 );
          }
          LODWORD(a7) = &base[*(_DWORD *)v11];
          v42 = &base[(*(_DWORD *)&v11[4])--];
          v45 = *(const char **)a7;
          v46 = *(const idMaterial **)(a7 + 4);
          v47 = *(_DWORD *)(a7 + 8);
          v48 = *(_DWORD *)(a7 + 12);
          *(_DWORD *)a7 = v42->name;
          *(_DWORD *)(a7 + 4) = v42->material;
          HIDWORD(a7) = v47;
          *(_DWORD *)(a7 + 8) = v42->materialNumber;
          *(_DWORD *)(a7 + 12) = v42->index;
          v42->name = v45;
          v42->material = v46;
          v42->materialNumber = v47;
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(a7) = *(_DWORD *)&v11[4] + v10;
        v13 = &base[*(_DWORD *)&v11[4]];
        *(_QWORD *)((char *)&v14 + 4) = a7 >> 63;
        LODWORD(v14) = DWORD2(v14) + *(_DWORD *)&v11[4] + v10;
        *(_DWORD *)v11 = v13;
        *(_DWORD *)&v11[8] = *(_DWORD *)&v11[4] - 1;
        LODWORD(v14) = &base[(__int64)v14 >> 1];
        p_material = &v13->material;
        material = v13->material;
        index = v13->index;
        materialNumber = v13->materialNumber;
        DWORD2(v14) = v13->name;
        v13->name = *(const char **)v14;
        v13->material = *(const idMaterial **)(v14 + 4);
        v13->materialNumber = *(_DWORD *)(v14 + 8);
        v13->index = *(_DWORD *)(v14 + 12);
        *(_DWORD *)v14 = DWORD2(v14);
        *(_DWORD *)(v14 + 4) = material;
        *(_DWORD *)(v14 + 8) = materialNumber;
        *(_DWORD *)(v14 + 12) = index;
        do
        {
          v17 = (_cntlzw((*p_material)->coverage - 1) & 0x20) != 0;
          do
          {
            v18 = &base[v12];
            v19 = (_cntlzw(v18->material->coverage - 1) & 0x20) != 0;
            if ( v19 == v17 )
              v20 = v18->materialNumber - *(_DWORD *)(*(_DWORD *)v11 + 8);
            else
              v20 = v19 - v17;
            if ( v20 >= 0 )
              break;
            ++v12;
          }
          while ( v12 < *(int *)&v11[8] );
          while ( 1 )
          {
            v21 = &base[*(_DWORD *)&v11[8]];
            v22 = (_cntlzw(v21->material->coverage - 1) & 0x20) != 0;
            v23 = v22 == v17 ? v21->materialNumber - *(_DWORD *)(*(_DWORD *)v11 + 8) : v22 - v17;
            if ( v23 <= 0 )
              break;
            --*(_DWORD *)&v11[8];
            if ( *(int *)&v11[8] <= v12 )
              goto LABEL_20;
          }
          if ( v12 >= *(int *)&v11[8] )
            break;
          v24 = &base[v12++];
          --*(_DWORD *)&v11[8];
          name = v24->name;
          v26 = v24->material;
          v27 = v24->materialNumber;
          v28 = v24->index;
          v24->name = v21->name;
          v24->material = v21->material;
          v24->materialNumber = v21->materialNumber;
          v24->index = v21->index;
          v21->name = name;
          v21->material = v26;
          v21->materialNumber = v27;
          v21->index = v28;
        }
        while ( v12 < *(int *)&v11[8] );
LABEL_20:
        v29 = (_cntlzw((*p_material)->coverage - 1) & 0x20) != 0;
        while ( 1 )
        {
          v30 = &base[v12];
          v31 = (_cntlzw(v30->material->coverage - 1) & 0x20) != 0;
          v32 = v31 == v29 ? v30->materialNumber - *(_DWORD *)(*(_DWORD *)v11 + 8) : v31 - v29;
          if ( v32 > 0 || v12 >= *(int *)&v11[4] )
            break;
          ++v12;
        }
        while ( 1 )
        {
          v33 = &base[*(_DWORD *)&v11[8]];
          v34 = (_cntlzw(v33->material->coverage - 1) & 0x20) != 0;
          v35 = v34 == v29 ? v33->materialNumber - *(_DWORD *)(*(_DWORD *)v11 + 8) : v34 - v29;
          if ( v35 < 0 || (int)v10 >= *(int *)&v11[8] )
            break;
          --*(_DWORD *)&v11[8];
        }
        LODWORD(v7) = v7 + 1;
        v43 = **(_QWORD **)v11;
        v44 = *(_QWORD *)(*(_DWORD *)v11 + 8);
        **(_QWORD **)v11 = *(_QWORD *)&v30->name;
        HIDWORD(a7) = v44;
        *(_QWORD *)(*(_DWORD *)v11 + 8) = *(_QWORD *)&v30->materialNumber;
        v51[v9 + 129] = *(_QWORD *)v11;
        v51[v9 + 1] = *(_QWORD *)(&v8 - 1);
        *(_QWORD *)(v9 * 8 + HIDWORD(v10)) = *(_QWORD *)&v11[4];
        *(_QWORD *)&v30->name = v43;
        *(_QWORD *)&v30->materialNumber = v44;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@UimageProperties_t@@VidSort_ImageProperties@@@@UBAXPAUimageProperties_t@@I@Z
// EA  : 0x82938DD0
// RVA : 0x00938DD0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<imageProperties_t,idSort_ImageProperties>::Sort(
        idSort_Quick<imageProperties_t,idSort_ImageProperties> *this,
        imageProperties_t *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r26
  __int64 v8; // r29
  __int64 v9; // r5
  int v10; // r31 OVERLAPPED
  __int64 v11; // r11
  int v12; // r7
  int v13; // ctr
  char *v14; // r10
  int v15; // r9
  _DWORD *v16; // r11
  _DWORD *v17; // r11
  _DWORD *v18; // r10
  int k; // ctr
  char *v20; // r11
  _DWORD *v21; // r10
  int m; // ctr
  int v23; // r30 OVERLAPPED
  __int64 v24; // r9
  _DWORD *v25; // r3
  int v26; // r11
  int *v27; // r6
  int v28; // r10
  int v29; // ctr
  _DWORD *v30; // r8
  _DWORD *v31; // r8
  _DWORD *v32; // r10
  int n; // ctr
  _DWORD *v34; // r10
  int *v35; // r11
  int ii; // ctr
  int jj; // r8
  _DWORD *v38; // r10
  _DWORD *v39; // r11
  int kk; // ctr
  _DWORD *v41; // r11
  _DWORD *v42; // r10
  int mm; // ctr
  _DWORD *v44; // r11
  _DWORD *v45; // r10
  int nn; // ctr
  int v47; // r11
  int v48; // r10
  int v49; // r3
  int v50; // r11
  _DWORD *v51; // r9
  int v52; // ctr
  int v53; // r8
  _DWORD *v54; // r10
  _DWORD *v55; // r10
  _DWORD *v56; // r11
  int i; // ctr
  _DWORD *v58; // r11
  _DWORD *v59; // r10
  int j; // ctr
  _BYTE v61[32]; // [sp+Ch] [-8C4h] BYREF
  _BYTE v62[32]; // [sp+2Ch] [-8A4h] BYREF
  int v63; // [sp+4Ch] [-884h] BYREF
  char v64; // [sp+6Ch] [-864h] BYREF
  _QWORD v65[128]; // [sp+90h] [-840h] BYREF
  _QWORD v66[136]; // [sp+490h] [-440h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v65[0] = v7;
    v66[0] = a7;
    do
    {
      v8 = v65[(_DWORD)v7];
      v9 = *(_QWORD *)((char *)v66 + HIDWORD(v8));
      v10 = v65[v7];
      if ( (int)v9 - (int)v8 < 4 || (int)v7 >= 127 )
      {
        for ( ; (int)v9 > v10; LODWORD(v9) = v9 - 1 )
        {
          v47 = v10;
          v48 = v10 + 1;
          if ( v10 + 1 <= (int)v9 )
          {
            v49 = v9 - v10;
            do
            {
              if ( *(_DWORD *)(24 * v47 + HIDWORD(v9) + 20) - *(_DWORD *)(24 * v48 + HIDWORD(v9) + 20) > 0 )
                v47 = v48;
              --v49;
              ++v48;
            }
            while ( v49 != 0 );
          }
          v50 = 24 * v47 + HIDWORD(v9);
          v51 = v62;
          v52 = 6;
          v53 = 24 * v9 + HIDWORD(v9);
          v54 = (_DWORD *)(v50 - 4);
          do
          {
            *++v51 = *++v54;
            --v52;
          }
          while ( v52 != 0 );
          v55 = (_DWORD *)(v53 - 4);
          v56 = (_DWORD *)(v50 - 4);
          for ( i = 6; i != 0; --i )
            *++v56 = *++v55;
          v58 = v62;
          v59 = (_DWORD *)(v53 - 4);
          for ( j = 6; j != 0; --j )
            *++v59 = *++v58;
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v11) = v9 + v8;
        HIDWORD(v11) = 2 * v9;
        LODWORD(v11) = ((unsigned __int64)v11 >> 63) + v9 + v8;
        LODWORD(v11) = v11 >> 1;
        v12 = 24 * v9 + HIDWORD(v9);
        v13 = 6;
        v14 = &v64;
        v15 = 24 * v11 + HIDWORD(v9);
        v16 = (_DWORD *)(v12 - 4);
        do
        {
          ++v16;
          v14 += 4;
          *(_DWORD *)v14 = *v16;
          --v13;
        }
        while ( v13 != 0 );
        v17 = (_DWORD *)(v15 - 4);
        v18 = (_DWORD *)(v12 - 4);
        for ( k = 6; k != 0; --k )
          *++v18 = *++v17;
        v20 = &v64;
        v21 = (_DWORD *)(v15 - 4);
        for ( m = 6; m != 0; --m )
        {
          v20 += 4;
          *++v21 = *(_DWORD *)v20;
        }
        v23 = 24 * v9 + HIDWORD(v9);
        LODWORD(v24) = v9 - 1;
        v25 = (_DWORD *)(v12 + 20);
        while ( 1 )
        {
          if ( *v25 - *(_DWORD *)(24 * v10 + HIDWORD(v9) + 20) < 0 )
          {
            do
              ++v10;
            while ( v10 < (int)v24 && *v25 - *(_DWORD *)(24 * v10 + HIDWORD(v9) + 20) < 0 );
          }
          v26 = 24 * v24 + HIDWORD(v9);
          if ( *v25 - *(_DWORD *)(v26 + 20) > 0 )
            break;
LABEL_18:
          if ( v10 < (int)v24 )
          {
            v27 = &v63;
            v28 = 24 * v10 + HIDWORD(v9);
            v29 = 6;
            v30 = (_DWORD *)(v28 - 4);
            do
            {
              *++v27 = *++v30;
              --v29;
            }
            while ( v29 != 0 );
            v31 = (_DWORD *)(v26 - 4);
            v32 = (_DWORD *)(v28 - 4);
            for ( n = 6; n != 0; --n )
              *++v32 = *++v31;
            v34 = (_DWORD *)(v26 - 4);
            v35 = &v63;
            for ( ii = 6; ii != 0; --ii )
              *++v34 = *++v35;
            ++v10;
            LODWORD(v24) = v24 - 1;
            if ( v10 < (int)v24 )
              continue;
          }
          goto LABEL_26;
        }
        while ( 1 )
        {
          LODWORD(v24) = v24 - 1;
          if ( (int)v24 <= v10 )
            break;
          v26 = 24 * v24 + HIDWORD(v9);
          if ( *v25 - *(_DWORD *)(v26 + 20) <= 0 )
            goto LABEL_18;
        }
LABEL_26:
        for ( jj = 24 * v10 + HIDWORD(v9); *v25 - *(_DWORD *)(jj + 20) <= 0; jj = 24 * v10 + HIDWORD(v9) )
        {
          if ( v10 >= (int)v9 )
            break;
          ++v10;
        }
        for ( ; *v25 - *(_DWORD *)(24 * v24 + HIDWORD(v9) + 20) >= 0; LODWORD(v24) = v24 - 1 )
        {
          if ( (int)v8 >= (int)v24 )
            break;
        }
        v38 = v61;
        v39 = (_DWORD *)(v23 - 4);
        for ( kk = 6; kk != 0; --kk )
          *++v38 = *++v39;
        v41 = (_DWORD *)(jj - 4);
        v42 = (_DWORD *)(v23 - 4);
        for ( mm = 6; mm != 0; --mm )
          *++v42 = *++v41;
        v44 = v61;
        v45 = (_DWORD *)(jj - 4);
        for ( nn = 6; nn != 0; --nn )
        {
          HIDWORD(v24) = *++v44;
          *++v45 = *v44;
        }
        LODWORD(v7) = v7 + 1;
        *(_QWORD *)((char *)&v66[1] + HIDWORD(v8)) = v9;
        *(_QWORD *)((char *)&v65[1] + HIDWORD(v8)) = *(_QWORD *)&v10;
        *(_QWORD *)((char *)v66 + HIDWORD(v8)) = v24;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@UrenderModelDetails_t@@VidSort_DetailSort@@@@UBAXPAUrenderModelDetails_t@@I@Z
// EA  : 0x82958080
// RVA : 0x00958080
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<renderModelDetails_t,idSort_DetailSort>::Sort(
        idSort_Quick<renderModelDetails_t,idSort_DetailSort> *this,
        renderModelDetails_t *base,
        unsigned int num,
        int a4,
        unsigned __int64 a5,
        __int64 a6)
{
  __int64 v6; // r28
  int v7; // r3
  int v8; // r31 OVERLAPPED
  __int64 v9; // r30 OVERLAPPED
  __int64 v10; // r11 OVERLAPPED
  __int128 v11; // r8
  renderModelDetails_t *v12; // r9
  renderModelDetails_t v13; // r6
  int *p_count; // r7
  renderModelDetails_t *v15; // r9
  renderModelDetails_t *v16; // r8
  renderModelDetails_t v17; // r27
  renderModelDetails_t *i; // r9 OVERLAPPED
  renderModelDetails_t v19; // r6
  int v20; // r6
  int v21; // r9
  int v22; // r5
  renderModelDetails_t *v23; // r9
  renderModelDetails_t v24; // r6
  __int64 v25; // [sp+10h] [-830h] BYREF
  _BYTE v26[1016]; // [sp+18h] [-828h] BYREF
  __int64 v27; // [sp+410h] [-430h]
  _BYTE v28[1064]; // [sp+418h] [-428h] BYREF

  if ( num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v25 = v6;
    v27 = a6;
    do
    {
      v7 = 8 * v6;
      v9 = *(_QWORD *)&v26[8 * (_DWORD)v6 - 8];
      *(_QWORD *)&v8 = *(_QWORD *)(8 * v6 + HIDWORD(v9));
      LODWORD(v10) = v9;
      HIDWORD(v10) = *(_DWORD *)(8 * v6 + HIDWORD(v9) + 4);
      if ( v8 - (int)v9 < 4 || (int)v6 >= 127 )
      {
        for ( ; SHIDWORD(v10) > (int)v9; *v23 = v24 )
        {
          v20 = v9;
          v21 = v9 + 1;
          if ( (int)v9 + 1 <= SHIDWORD(v10) )
          {
            v22 = HIDWORD(v10) - v9;
            do
            {
              if ( base[v21].count - base[v20].count > 0 )
                v20 = v21;
              --v22;
              ++v21;
            }
            while ( v22 != 0 );
          }
          v23 = &base[HIDWORD(v10)];
          LODWORD(a5) = &base[v20];
          --HIDWORD(v10);
          HIDWORD(a5) = v23->modelName;
          v24 = *(renderModelDetails_t *)a5;
          *(_DWORD *)a5 = v23->modelName;
          v24.modelName = (const char *)v23->count;
          *(_DWORD *)(a5 + 4) = v24.modelName;
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        LODWORD(a5) = v8 + v9;
        *(_QWORD *)((char *)&v11 + 4) = a5 >> 63;
        v12 = &base[v8];
        LODWORD(v11) = DWORD2(v11) + v8 + v9;
        --HIDWORD(v10);
        LODWORD(v11) = 8 * ((__int64)v11 >> 1);
        v13 = *v12;
        p_count = &v12->count;
        LODWORD(v11) = (char *)base + v11;
        v12->modelName = *(const char **)v11;
        v12->count = *(_DWORD *)(v11 + 4);
        *(renderModelDetails_t *)v11 = v13;
        while ( 1 )
        {
          if ( base[v10].count - *p_count < 0 )
          {
            do
              LODWORD(v10) = v10 + 1;
            while ( (int)v10 < SHIDWORD(v10) && base[v10].count - *p_count < 0 );
          }
          v15 = &base[HIDWORD(v10)];
          if ( v15->count - *p_count > 0 )
            break;
LABEL_12:
          if ( (int)v10 < SHIDWORD(v10) )
          {
            v16 = &base[v10];
            LODWORD(v10) = v10 + 1;
            --HIDWORD(v10);
            v17 = *v16;
            v16->modelName = v15->modelName;
            v16->count = v15->count;
            *v15 = v17;
            if ( (int)v10 < SHIDWORD(v10) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v10);
          if ( SHIDWORD(v10) <= (int)v10 )
            break;
          v15 = &base[HIDWORD(v10)];
          if ( v15->count - *p_count <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( i = &base[v10]; i->count - *p_count <= 0; i = &base[v10] )
        {
          if ( (int)v10 >= v8 )
            break;
          LODWORD(v10) = v10 + 1;
        }
        for ( ; base[HIDWORD(v10)].count - *p_count >= 0; --HIDWORD(v10) )
        {
          if ( (int)v9 >= SHIDWORD(v10) )
            break;
        }
        HIDWORD(a5) = v28;
        v19 = *(renderModelDetails_t *)v13.modelName;
        LODWORD(v9) = v26;
        LODWORD(v6) = v6 + 1;
        *(renderModelDetails_t *)v19.modelName = *i;
        *(_QWORD *)&v28[v7] = *(_QWORD *)&v8;
        *i = v19;
        *(_QWORD *)&v26[v7] = v10;
        *(_QWORD *)(v7 + HIDWORD(v9)) = *(__int64 *)((char *)&v10 + 4);
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidStr@@VidSort_PathStr@@@@UBAXPAVidStr@@I@Z
// EA  : 0x82980200
// RVA : 0x00980200
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idStr,idSort_PathStr>::Sort(
        idSort_Quick<idStr,idSort_PathStr> *this,
        idStr *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r30 OVERLAPPED
  int v8; // r21
  int v9; // r26
  __int64 v10; // r25
  int v11; // r31 OVERLAPPED
  __int64 v12; // r11
  const char **v13; // r27
  idStr *v14; // r28
  idStr *j; // r28
  int v16; // r27
  int i; // r28
  _BYTE v18[1016]; // [sp+58h] [-858h] BYREF
  _QWORD v19[140]; // [sp+450h] [-460h] BYREF

  HIDWORD(v7) = base;
  if ( num != 0 )
  {
    v8 = 0;
    LODWORD(a7) = num - 1;
    v19[0] = a7;
    do
    {
      v9 = v8;
      v10 = v19[v8];
      v11 = HIDWORD(v10);
      LODWORD(v7) = v19[v8];
      if ( (int)v10 - HIDWORD(v10) < 4 || v8 >= 127 )
      {
        for ( ; (int)v7 > SHIDWORD(v10); LODWORD(v7) = v7 - 1 )
        {
          v16 = HIDWORD(v10);
          for ( i = HIDWORD(v10) + 1; i <= (int)v7; ++i )
          {
            if ( idStr::IcmpPath(
                   s1: *(const char **)(32 * i + HIDWORD(v7) + 4),
                   s2: *(const char **)(32 * v16 + HIDWORD(v7) + 4)) > 0 )
              v16 = i;
          }
          SwapValues<idStr>(a: (idStr *)(32 * v16 + HIDWORD(v7)), b: (idStr *)(32 * v7 + HIDWORD(v7)));
        }
        --v8;
      }
      else
      {
        LODWORD(v12) = v10 + HIDWORD(v10);
        HIDWORD(v12) = 32 * v10;
        LODWORD(v12) = ((unsigned __int64)v12 >> 63) + v10 + HIDWORD(v10);
        SwapValues<idStr>(a: (idStr *)(32 * v10 + HIDWORD(v7)), b: (idStr *)(32 * (v12 >> 1) + HIDWORD(v7)));
        LODWORD(v7) = v7 - 1;
        v13 = (const char **)(32 * v10 + HIDWORD(v7) + 4);
        while ( 1 )
        {
          if ( idStr::IcmpPath(s1: *(const char **)(32 * v11 + HIDWORD(v7) + 4), s2: *v13) < 0 )
          {
            do
              ++v11;
            while ( v11 < (int)v7 && idStr::IcmpPath(s1: *(const char **)(32 * v11 + HIDWORD(v7) + 4), s2: *v13) < 0 );
          }
          v14 = (idStr *)(32 * v7 + HIDWORD(v7));
          if ( idStr::IcmpPath(s1: v14->data, s2: *v13) > 0 )
            break;
LABEL_12:
          if ( v11 < (int)v7 )
          {
            SwapValues<idStr>(a: (idStr *)(32 * v11++ + HIDWORD(v7)), b: v14);
            LODWORD(v7) = v7 - 1;
            if ( v11 < (int)v7 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v7) = v7 - 1;
          if ( (int)v7 <= v11 )
            break;
          v14 = (idStr *)(32 * v7 + HIDWORD(v7));
          if ( idStr::IcmpPath(s1: v14->data, s2: *v13) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = (idStr *)(32 * v11 + HIDWORD(v7));
              idStr::IcmpPath(s1: j->data, s2: *v13) <= 0;
              j = (idStr *)(32 * v11 + HIDWORD(v7)) )
        {
          if ( v11 >= (int)v10 )
            break;
          ++v11;
        }
        for ( ; idStr::IcmpPath(s1: *(const char **)(32 * v7 + HIDWORD(v7) + 4), s2: *v13) >= 0; LODWORD(v7) = v7 - 1 )
        {
          if ( SHIDWORD(v10) >= (int)v7 )
            break;
        }
        SwapValues<idStr>(a: (idStr *)(32 * v10 + HIDWORD(v7)), b: j);
        ++v8;
        v19[v9 + 1] = v10;
        *(_QWORD *)&v18[v9 * 8] = *(__int64 *)((char *)&v7 - 4);
        v19[v9] = v7;
      }
    }
    while ( v8 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidActiveChannel@@VidSort_activeEmitterChannels@@@@UBAXPAVidActiveChannel@@I@Z
// EA  : 0x82995048
// RVA : 0x00995048
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idActiveChannel,idSort_activeEmitterChannels>::Sort(
        idSort_Quick<idActiveChannel,idSort_activeEmitterChannels> *this,
        __int64 num,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  __int64 v6; // r28 OVERLAPPED
  int v7; // r7
  int v8; // r3 OVERLAPPED
  __int64 v9; // r6
  int v10; // r6
  int v11; // r11
  __int64 v12; // r9
  unsigned __int64 v13; // r11
  _DWORD *v14; // r8
  __int64 v15; // r30
  __int64 *v16; // r9
  double v17; // fp13
  int v18; // r6
  __int64 v19; // r30
  int v20; // r6
  int v21; // r30
  int v22; // r6
  int v23; // r31
  int v24; // r29
  int v25; // r11
  int v26; // r10
  int v27; // r6
  int v28; // r3
  _DWORD *v29; // r9
  int v30; // r6
  int v31; // r6
  int v32; // r8
  int v33; // r6
  _DWORD *v34; // r11
  int v35; // r10
  bool v36; // cr57
  __int64 v37; // r7
  __int64 v38; // [sp+10h] [-830h] BYREF
  _BYTE v39[1016]; // [sp+18h] [-828h] BYREF
  _QWORD v40[134]; // [sp+410h] [-430h] BYREF

  if ( (_DWORD)num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v38 = v6;
    v40[0] = a6;
    do
    {
      v7 = v6;
      *(_QWORD *)&v8 = *(_QWORD *)&v39[8 * (_DWORD)v6 - 8];
      v9 = v40[(_DWORD)v6];
      LODWORD(num) = v8;
      if ( (int)v9 - v8 < 4 || (int)v6 >= 127 )
      {
        if ( v8 < v20 )
        {
          v21 = v8 + 1;
          v23 = v22 - 3;
          v24 = 4 - (v8 + 1);
          do
          {
            v25 = num;
            v26 = num + 1;
            if ( v21 <= v27 )
            {
              if ( v24 + v23 >= 4 )
              {
                v28 = num + 3;
                do
                {
                  v29 = (_DWORD *)(8 * v26 + HIDWORD(num));
                  if ( (float)(*(float *)(*v29 + 216) - *(float *)(*(_DWORD *)(8 * v25 + HIDWORD(num)) + 216)) > 0.0 )
                    v25 = v26;
                  if ( (float)(*(float *)(v29[2] + 216) - *(float *)(*(_DWORD *)(8 * v25 + HIDWORD(num)) + 216)) > 0.0 )
                    v25 = v28 - 1;
                  if ( (float)(*(float *)(*(_DWORD *)(8 * (v26 + 2) + HIDWORD(num)) + 216)
                             - *(float *)(*(_DWORD *)(8 * v25 + HIDWORD(num)) + 216)) > 0.0 )
                    v25 = v28;
                  if ( (float)(*(float *)(*(_DWORD *)(8 * (v26 + 3) + HIDWORD(num)) + 216)
                             - *(float *)(*(_DWORD *)(8 * v25 + HIDWORD(num)) + 216)) > 0.0 )
                    v25 = v28 + 1;
                  v26 += 4;
                  v28 += 4;
                }
                while ( v26 <= v23 );
              }
              if ( v26 <= v30 )
              {
                v32 = v31 - v26 + 1;
                do
                {
                  if ( (float)(*(float *)(*(_DWORD *)(8 * v26 + HIDWORD(num)) + 216)
                             - *(float *)(*(_DWORD *)(8 * v25 + HIDWORD(num)) + 216)) > 0.0 )
                    v25 = v26;
                  --v32;
                  ++v26;
                }
                while ( v32 != 0 );
              }
            }
            v35 = 8 * v25 + HIDWORD(num);
            v34 = (_DWORD *)(8 * v33 + HIDWORD(num));
            --v23;
            v36 = v33 - 1 > (int)num;
            v37 = *(_QWORD *)v35;
            *(_DWORD *)v35 = *v34;
            *(_DWORD *)(v35 + 4) = v34[1];
            *(_QWORD *)v34 = v37;
          }
          while ( v36 );
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        v11 = v10 + v8;
        HIDWORD(v13) = 8 * v10;
        v12 = (unsigned int)(v13 >> 63) + v10 + v8;
        LODWORD(v13) = v10 - 1;
        v12 >>= 1;
        v14 = (_DWORD *)(8 * v10 + HIDWORD(num));
        v15 = *(_QWORD *)v14;
        LODWORD(v12) = 8 * v12 + HIDWORD(num);
        *v14 = *(_DWORD *)v12;
        HIDWORD(v15) = *(_DWORD *)(v12 + 4);
        v14[1] = HIDWORD(v15);
        *(_QWORD *)v12 = v15;
        do
        {
          do
          {
            if ( (float)(*(float *)(*(_DWORD *)(8 * num + HIDWORD(num)) + 216) - *(float *)(*v14 + 216)) >= 0.0 )
              break;
            LODWORD(num) = num + 1;
          }
          while ( (int)num < (int)v13 );
          while ( 1 )
          {
            HIDWORD(v13) = 8 * v13 + HIDWORD(num);
            if ( (float)(*(float *)(*(_DWORD *)HIDWORD(v13) + 216) - *(float *)(*v14 + 216)) <= 0.0 )
              break;
            LODWORD(v13) = v13 - 1;
            if ( (int)v13 <= (int)num )
              goto LABEL_13;
          }
          if ( (int)num >= (int)v13 )
            break;
          v16 = (__int64 *)(8 * num + HIDWORD(num));
          LODWORD(num) = num + 1;
          LODWORD(v13) = v13 - 1;
          *(__int64 *)((char *)&v6 - 4) = *v16;
          *v16 = *(_QWORD *)HIDWORD(v13);
          *(_QWORD *)HIDWORD(v13) = *(__int64 *)((char *)&v6 - 4);
        }
        while ( (int)num < (int)v13 );
LABEL_13:
        while ( 1 )
        {
          HIDWORD(v13) = 8 * num + HIDWORD(num);
          v17 = (float)(*(float *)(*(_DWORD *)HIDWORD(v13) + 216) - *(float *)(*v14 + 216));
          if ( v17 >= 0.0 && v17 > 0.0 )
            break;
          if ( (int)num >= v18 )
            break;
          LODWORD(num) = num + 1;
        }
        while ( (float)(*(float *)(*(_DWORD *)(8 * v13 + HIDWORD(num)) + 216) - *(float *)(*v14 + 216)) >= 0.0
             && v8 < (int)v13 )
          LODWORD(v13) = v13 - 1;
        v19 = *(_QWORD *)v14;
        HIDWORD(v19) = v39;
        LODWORD(v6) = v6 + 1;
        *(_QWORD *)v14 = *(_QWORD *)HIDWORD(v13);
        v40[v7 + 1] = *(__int64 *)((char *)&num - 4);
        *(_QWORD *)HIDWORD(v13) = v19;
        *(_QWORD *)&v39[v7 * 8] = num;
        v40[v7] = v13;
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// ??$SwapValues@VidSaveGameDetails@@@@YAXAAVidSaveGameDetails@@0@Z
// EA  : 0x829CDCE8
// RVA : 0x009CDCE8
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<idSaveGameDetails>(idSaveGameDetails *a, idSaveGameDetails *b)
{
  __int64 date; // r10
  char *data; // r3
  int len; // r11
  __int64 v7; // r6
  int v8; // r11
  char *v9; // r4
  idSaveGameDetails v10; // [sp+50h] [-C0h] BYREF

  idDict::idDict(this: &v10.descriptors, other: &a->descriptors);
  date = a->date;
  v10.damaged = a->damaged;
  v10.date = date;
  idStrStatic<64>::idStrStatic<64>(this: &v10.slotName, text: &a->slotName);
  idDict::operator=(this: &a->descriptors, other: &b->descriptors);
  a->damaged = b->damaged;
  a->date = b->date;
  data = a->slotName.data;
  len = b->slotName.len;
  a->slotName.len = len;
  memcpy(Dst: data, Src: b->slotName.data, Size: len + 1);
  idDict::operator=(this: &b->descriptors, other: &v10.descriptors);
  LODWORD(v7) = v10.date;
  v8 = v10.slotName.len;
  v9 = v10.slotName.data;
  HIDWORD(v7) = v10.slotName.len + 1;
  b->damaged = v10.damaged;
  b->date = v7;
  b->slotName.len = v8;
  memcpy(Dst: b->slotName.data, Src: v9, Size: HIDWORD(v7));
  idSaveGameDetails::~idSaveGameDetails(this: &v10);
}


// ========================================================================
// __unwind$242038
// EA  : 0x829CDDA4
// RVA : 0x009CDDA4
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_242038()
{
  int v0; // r12

  idDict::~idDict(this: (idDict *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$242036
// EA  : 0x829CDDCC
// RVA : 0x009CDDCC
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_242036()
{
  int v0; // r12

  idSaveGameDetails::~idSaveGameDetails(this: (idSaveGameDetails *)(v0 - 272 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidSaveGameDetails@@VidSort_EnumeratedSavegames@@@@UBAXPAVidSaveGameDetails@@I@Z
// EA  : 0x829CDEC0
// RVA : 0x009CDEC0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idSaveGameDetails,idSort_EnumeratedSavegames>::Sort(
        idSort_Quick<idSaveGameDetails,idSort_EnumeratedSavegames> *this,
        idSaveGameDetails *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r22
  int v9; // r27
  __int64 v10; // r24
  __int64 v11; // r26
  int v12; // r31 OVERLAPPED
  int v13; // r29
  int v14; // r11
  __int64 v15; // r11
  __int64 v16; // r29
  __int64 v17; // r11
  idSaveGameDetails *v18; // r4
  __int64 v19; // r11
  idSaveGameDetails *v20; // r4
  int v21; // r10
  int v22; // r11
  int v23; // r5
  __int64 v24; // [sp+50h] [-860h] BYREF
  _BYTE v25[1016]; // [sp+58h] [-858h] BYREF
  __int64 v26; // [sp+450h] [-460h]
  _BYTE v27[1112]; // [sp+458h] [-458h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v24 = v7;
    v26 = a7;
    do
    {
      v9 = 8 * v7;
      v10 = *(_QWORD *)&v25[8 * (_DWORD)v7 - 8];
      v11 = *(_QWORD *)(8 * v7 + HIDWORD(v10));
      v12 = *(_DWORD *)&v25[8 * v7 - 4];
      v13 = *(_DWORD *)(8 * v7 + HIDWORD(v10) + 4);
      if ( (int)v11 - (int)v10 < 4 || (int)v7 >= 127 )
      {
        for ( ; v13 > v12; --v13 )
        {
          v21 = v12;
          v22 = v12 + 1;
          if ( v12 + 1 <= v13 )
          {
            v23 = v13 - v12;
            do
            {
              if ( LODWORD(base[v21].date) - LODWORD(base[v22].date) > 0 )
                v21 = v22;
              --v23;
              ++v22;
            }
            while ( v23 != 0 );
          }
          SwapValues<idSaveGameDetails>(a: &base[v21], b: &base[v13]);
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        v14 = v11 + v10;
        LODWORD(v15) = (*(unsigned __int64 *)((char *)&a7 - 4) >> 63) + v11 + v10;
        HIDWORD(v15) = 5 * v11;
        SwapValues<idSaveGameDetails>(a: &base[v11], b: &base[v15 >> 1]);
        LODWORD(v16) = v13 - 1;
        HIDWORD(v16) = &base[v11].date;
        while ( 1 )
        {
          v17 = *(_QWORD *)HIDWORD(v16);
          if ( LODWORD(base[v11].date) - LODWORD(base[v12].date) < 0 )
          {
            do
              ++v12;
            while ( v12 < (int)v16 && (int)v17 - LODWORD(base[v12].date) < 0 );
          }
          v18 = &base[v16];
          if ( (int)v17 - LODWORD(v18->date) > 0 )
            break;
LABEL_12:
          if ( v12 < (int)v16 )
          {
            SwapValues<idSaveGameDetails>(a: &base[v12++], b: v18);
            LODWORD(v16) = v16 - 1;
            if ( v12 < (int)v16 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v16) = v16 - 1;
          if ( (int)v16 <= v12 )
            break;
          v18 = &base[v16];
          if ( (int)v17 - LODWORD(v18->date) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v19 = *(_QWORD *)HIDWORD(v16);
        v20 = &base[v12];
        if ( LODWORD(base[v11].date) - LODWORD(v20->date) <= 0 )
        {
          do
          {
            if ( v12 >= (int)v11 )
              break;
            v20 = &base[++v12];
          }
          while ( (int)v19 - LODWORD(v20->date) <= 0 );
        }
        for ( ; (int)v19 - LODWORD(base[v16].date) >= 0; LODWORD(v16) = v16 - 1 )
        {
          if ( (int)v10 >= (int)v16 )
            break;
        }
        SwapValues<idSaveGameDetails>(a: &base[v11], b: v20);
        LODWORD(a7) = v25;
        LODWORD(v7) = v7 + 1;
        HIDWORD(v11) = &base[v11];
        *(_QWORD *)&v27[v9] = v11;
        *(_QWORD *)&v25[v9] = *(_QWORD *)(&base - 1);
        *(_QWORD *)(v9 + HIDWORD(v10)) = v16;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@PAUsearchResult_t@idLobbyBackend360@@VidSort_SearchResults@?CI@??EndTask_QoS@2@AAA_NXZ@@@UBAXPAPAUsearchResult_t@idLobbyBackend360@@I@Z
// EA  : 0x829D55E8
// RVA : 0x009D55E8
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLobbyBackend360::UBAXPAPAUsearchResult_t::idSort_Quick<idLobbyBackend360::searchResult_t *,`idLobbyBackend360::EndTask_QoS'::`40'::idSort_SearchResults,A_NXZ &>::Sort(
        idSort_Quick<idLobbyBackend360::searchResult_t *,`idLobbyBackend360::EndTask_QoS'::`40'::idSort_SearchResults> *this,
        idLobbyBackend360::searchResult_t **base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r21
  int v9; // r25
  int v10; // r22 OVERLAPPED
  __int64 v11; // r24
  __int64 v12; // r28
  int v13; // r30
  __int128 v14; // r11
  __int64 v15; // r30
  int v16; // r26
  int v17; // r26
  int v18; // r26
  int v19; // r20
  int v20; // r26
  int v21; // r20
  idLobbyBackend360::searchResult_t *v22; // r9
  int v23; // r26
  int v24; // r20
  int v25; // r26
  int v26; // r20
  int v27; // r26
  int v28; // r20
  int v29; // r26
  int v30; // r20
  int v31; // r9
  int v32; // r25
  int v33; // r26
  int v34; // r27
  int v35; // r11
  idLobbyBackend360::searchResult_t *v36; // r29
  int v37; // r24
  idLobbyBackend360::searchResult_t *v38; // r8
  _QWORD v39[270]; // [sp+50h] [-870h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v39[0] = v7;
    v39[128] = a7;
    do
    {
      v9 = v7;
      *(_QWORD *)(&v10 - 1) = v39[(_DWORD)v7];
      v11 = *(_QWORD *)(8 * v7 + v10);
      LODWORD(v12) = HIDWORD(v11);
      v13 = *(_DWORD *)(8 * v7 + v10 + 4);
      if ( (int)v11 - HIDWORD(v11) < 4 || (int)v7 >= 127 )
      {
        if ( SHIDWORD(v11) < v13 )
        {
          v32 = HIDWORD(v11) + 1;
          do
          {
            v33 = HIDWORD(v11);
            v34 = HIDWORD(v11) + 1;
            if ( v32 <= v13 )
            {
              v35 = v32;
              do
              {
                v36 = base[v33];
                v37 = qosScore(qos: &base[v35]->qosInfo);
                if ( qosScore(qos: &v36->qosInfo) - v37 > 0 )
                  v33 = v34;
                v35 = ++v34;
              }
              while ( v34 <= v13 );
            }
            v38 = base[v33];
            base[v33] = base[v13];
            base[v13--] = v38;
          }
          while ( v13 > SHIDWORD(v11) );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v14) = v11 + HIDWORD(v11);
        DWORD2(v14) = 4 * v11;
        HIDWORD(v15) = &base[v11];
        LODWORD(v14) = ((unsigned __int64)v14 >> 63) + v11 + HIDWORD(v11);
        LODWORD(v15) = v13 - 1;
        *(_QWORD *)((char *)&v14 + 4) = (__int64)v14 >> 1;
        DWORD1(v14) = *(_DWORD *)HIDWORD(v15);
        *(_DWORD *)HIDWORD(v15) = base[DWORD2(v14)];
        base[DWORD2(v14)] = (idLobbyBackend360::searchResult_t *)DWORD1(v14);
        while ( 1 )
        {
          HIDWORD(v12) = *(_DWORD *)HIDWORD(v15);
          v16 = qosScore(qos: &base[(_DWORD)v12]->qosInfo);
          if ( qosScore(qos: (const XNQOSINFO *)(HIDWORD(v12) + 60)) - v16 < 0 )
          {
            do
            {
              LODWORD(v12) = v12 + 1;
              if ( (int)v12 >= (int)v15 )
                break;
              HIDWORD(v12) = *(_DWORD *)HIDWORD(v15);
              v17 = qosScore(qos: &base[(_DWORD)v12]->qosInfo);
            }
            while ( qosScore(qos: (const XNQOSINFO *)(HIDWORD(v12) + 60)) - v17 < 0 );
          }
          v18 = *(_DWORD *)HIDWORD(v15);
          HIDWORD(v12) = &base[v15];
          v19 = qosScore(qos: (const XNQOSINFO *)(*(_DWORD *)HIDWORD(v12) + 60));
          if ( qosScore(qos: (const XNQOSINFO *)(v18 + 60)) - v19 > 0 )
            break;
LABEL_12:
          if ( (int)v12 < (int)v15 )
          {
            LODWORD(v15) = v15 - 1;
            v22 = base[(_DWORD)v12];
            base[(_DWORD)v12] = *(idLobbyBackend360::searchResult_t **)HIDWORD(v12);
            LODWORD(v12) = v12 + 1;
            *(_DWORD *)HIDWORD(v12) = v22;
            if ( (int)v12 < (int)v15 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v15) = v15 - 1;
          if ( (int)v15 <= (int)v12 )
            break;
          v20 = *(_DWORD *)HIDWORD(v15);
          HIDWORD(v12) = &base[v15];
          v21 = qosScore(qos: (const XNQOSINFO *)(*(_DWORD *)HIDWORD(v12) + 60));
          if ( qosScore(qos: (const XNQOSINFO *)(v20 + 60)) - v21 <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v23 = *(_DWORD *)HIDWORD(v15);
        HIDWORD(v12) = &base[v12];
        v24 = qosScore(qos: (const XNQOSINFO *)(*(_DWORD *)HIDWORD(v12) + 60));
        if ( qosScore(qos: (const XNQOSINFO *)(v23 + 60)) - v24 <= 0 )
        {
          do
          {
            if ( (int)v12 >= (int)v11 )
              break;
            LODWORD(v12) = v12 + 1;
            v25 = *(_DWORD *)HIDWORD(v15);
            HIDWORD(v12) = &base[v12];
            v26 = qosScore(qos: (const XNQOSINFO *)(*(_DWORD *)HIDWORD(v12) + 60));
          }
          while ( qosScore(qos: (const XNQOSINFO *)(v25 + 60)) - v26 <= 0 );
        }
        v27 = *(_DWORD *)HIDWORD(v15);
        v28 = qosScore(qos: &base[(_DWORD)v15]->qosInfo);
        if ( qosScore(qos: (const XNQOSINFO *)(v27 + 60)) - v28 >= 0 )
        {
          do
          {
            if ( SHIDWORD(v11) >= (int)v15 )
              break;
            LODWORD(v15) = v15 - 1;
            v29 = *(_DWORD *)HIDWORD(v15);
            v30 = qosScore(qos: &base[(_DWORD)v15]->qosInfo);
          }
          while ( qosScore(qos: (const XNQOSINFO *)(v29 + 60)) - v30 >= 0 );
        }
        v31 = *(_DWORD *)HIDWORD(v15);
        LODWORD(v7) = v7 + 1;
        *(_DWORD *)HIDWORD(v15) = *(_DWORD *)HIDWORD(v12);
        v39[v9 + 129] = v11;
        *(_DWORD *)HIDWORD(v12) = v31;
        v39[v9 + 1] = v12;
        *(_QWORD *)(v9 * 8 + v10) = v15;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@PAVidAIEventPool@@VidSort_AIEventPoolsByNumAllocated@@@@UBAXPAPAVidAIEventPool@@I@Z
// EA  : 0x82A43788
// RVA : 0x00A43788
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idAIEventPool *,idSort_AIEventPoolsByNumAllocated>::Sort(
        idSort_Quick<idAIEventPool *,idSort_AIEventPoolsByNumAllocated> *this,
        idAIEventPool **base,
        unsigned int num,
        int a4,
        unsigned __int64 a5,
        __int64 a6)
{
  __int64 v6; // r28
  int v7; // r3
  int v8; // r31 OVERLAPPED
  __int64 v9; // r30 OVERLAPPED
  __int64 v10; // r11 OVERLAPPED
  __int128 v11; // r8
  idAIEventPool **v12; // r8
  int size; // r7
  idAIEventPool **v14; // r9
  idAIEventPool *v15; // r5
  idAIEventPool *v16; // r5
  idAIEventPool **v17; // r9 OVERLAPPED
  int v18; // r6
  int v19; // r3
  int v20; // r6
  int v21; // r9
  int v22; // r8
  int v23; // r5
  int v24; // r9
  idAIEventPool *v25; // r6
  __int64 v26; // [sp+10h] [-830h] BYREF
  _BYTE v27[1016]; // [sp+18h] [-828h] BYREF
  __int64 v28; // [sp+410h] [-430h]
  _BYTE v29[1064]; // [sp+418h] [-428h] BYREF

  if ( num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v26 = v6;
    v28 = a6;
    do
    {
      v7 = 8 * v6;
      v9 = *(_QWORD *)&v27[8 * (_DWORD)v6 - 8];
      *(_QWORD *)&v8 = *(_QWORD *)(8 * v6 + HIDWORD(v9));
      LODWORD(v10) = v9;
      HIDWORD(v10) = *(_DWORD *)(8 * v6 + HIDWORD(v9) + 4);
      if ( v8 - (int)v9 < 4 || (int)v6 >= 127 )
      {
        if ( (int)v9 < SHIDWORD(v10) )
        {
          v19 = v9 + 1;
          do
          {
            v20 = v9;
            v21 = v9 + 1;
            if ( v19 <= SHIDWORD(v10) )
            {
              v22 = v19;
              v23 = HIDWORD(v10) - v9;
              do
              {
                if ( base[v20]->freeEvents.size - base[v22]->freeEvents.size > 0 )
                  v20 = v21;
                ++v21;
                --v23;
                v22 = v21;
              }
              while ( v23 != 0 );
            }
            v24 = v20;
            HIDWORD(a5) = base[HIDWORD(v10)];
            v25 = base[v20];
            base[v24] = (idAIEventPool *)HIDWORD(a5);
            base[HIDWORD(v10)--] = v25;
          }
          while ( SHIDWORD(v10) > (int)v9 );
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        LODWORD(a5) = v8 + v9;
        *(_QWORD *)((char *)&v11 + 4) = a5 >> 63;
        LODWORD(v11) = DWORD2(v11) + v8 + v9;
        --HIDWORD(v10);
        *(_QWORD *)((char *)&v11 + 4) = (__int64)v11 >> 1;
        v12 = &base[v8];
        DWORD2(v11) *= 4;
        DWORD1(v11) = *v12;
        *v12 = *(idAIEventPool **)((char *)base + DWORD2(v11));
        *(idAIEventPool **)((char *)base + DWORD2(v11)) = (idAIEventPool *)DWORD1(v11);
        while ( 1 )
        {
          size = (*v12)->freeEvents.size;
          if ( size - base[(_DWORD)v10]->freeEvents.size < 0 )
          {
            do
              LODWORD(v10) = v10 + 1;
            while ( (int)v10 < SHIDWORD(v10) && (*v12)->freeEvents.size - base[(_DWORD)v10]->freeEvents.size < 0 );
          }
          v14 = &base[HIDWORD(v10)];
          if ( size - (*v14)->freeEvents.size > 0 )
            break;
LABEL_12:
          if ( (int)v10 < SHIDWORD(v10) )
          {
            --HIDWORD(v10);
            v15 = base[(_DWORD)v10];
            base[(_DWORD)v10] = *v14;
            LODWORD(v10) = v10 + 1;
            *v14 = v15;
            if ( (int)v10 < SHIDWORD(v10) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v10);
          if ( SHIDWORD(v10) <= (int)v10 )
            break;
          v14 = &base[HIDWORD(v10)];
          if ( (*v12)->freeEvents.size - (*v14)->freeEvents.size <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v16 = *v12;
        v17 = &base[v10];
        v18 = (*v12)->freeEvents.size;
        if ( v18 - (*v17)->freeEvents.size <= 0 )
        {
          do
          {
            if ( (int)v10 >= v8 )
              break;
            LODWORD(v10) = v10 + 1;
            v17 = &base[v10];
          }
          while ( (*v12)->freeEvents.size - (*v17)->freeEvents.size <= 0 );
        }
        if ( v18 - base[HIDWORD(v10)]->freeEvents.size >= 0 )
        {
          do
          {
            if ( (int)v9 >= SHIDWORD(v10) )
              break;
            --HIDWORD(v10);
          }
          while ( (*v12)->freeEvents.size - base[HIDWORD(v10)]->freeEvents.size >= 0 );
        }
        HIDWORD(a5) = *v17;
        LODWORD(v9) = v27;
        LODWORD(v6) = v6 + 1;
        *v12 = *v17;
        *(_QWORD *)&v29[v7] = *(_QWORD *)&v8;
        *v17 = v16;
        *(_QWORD *)&v27[v7] = v10;
        *(_QWORD *)(v7 + HIDWORD(v9)) = *(__int64 *)((char *)&v10 + 4);
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// ??$SwapValues@VidLayer@@@@YAXAAVidLayer@@0@Z
// EA  : 0x82B5DA80
// RVA : 0x00B5DA80
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<idLayer>(idLayer *a, idLayer *b)
{
  idStr *p_layerDeclName; // r27
  int len; // r28
  int v6; // r11
  size_t v7; // r29
  idLayer::layerState_t layerState; // r5
  idLayer v9[2]; // [sp+50h] [-60h] BYREF

  p_layerDeclName = &a->layerDeclName;
  v9[0].__vftable = (idLayer_vtbl *)&idLayer::`vftable';
  idStr::idStr(this: &v9[0].layerDeclName, text: &a->layerDeclName);
  v9[0].layerState = a->layerState;
  len = b->layerDeclName.len;
  idStr::EnsureAlloced(this: p_layerDeclName, amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: a->layerDeclName.data, Src: b->layerDeclName.data, Size: len);
  a->layerDeclName.data[len] = 0;
  v6 = v9[0].layerDeclName.len;
  a->layerDeclName.len = len;
  a->layerState = b->layerState;
  v7 = v6;
  idStr::EnsureAlloced(this: &b->layerDeclName, amount: v6 + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: b->layerDeclName.data, Src: v9[0].layerDeclName.data, Size: v7);
  b->layerDeclName.data[v7] = 0;
  layerState = v9[0].layerState;
  b->layerDeclName.len = v7;
  b->layerState = layerState;
  idRaceStatusMemory::~idRaceStatusMemory(this: v9);
}


// ========================================================================
// __unwind$491384
// EA  : 0x82B5DB50
// RVA : 0x00B5DB50
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_491384()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$491382
// EA  : 0x82B5DB78
// RVA : 0x00B5DB78
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_491382()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 176 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidLayer@@VidSort_GameLayer@@@@UBAXPAVidLayer@@I@Z
// EA  : 0x82B5DF38
// RVA : 0x00B5DF38
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idLayer,idSort_GameLayer>::Sort(
        idSort_Quick<idLayer,idSort_GameLayer> *this,
        idLayer *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r21
  int v10; // r25
  int v11; // r22 OVERLAPPED
  __int64 v12; // r24
  __int64 v13; // r30 OVERLAPPED
  int v14; // r11
  __int64 v15; // r11
  idLayer *v16; // r28
  idStr *v17; // r27
  idStr *j; // r27
  int v19; // r28
  int i; // r27
  __int64 v21; // [sp+50h] [-860h] BYREF
  _BYTE v22[1016]; // [sp+58h] [-858h] BYREF
  __int64 v23; // [sp+450h] [-460h]
  _BYTE v24[1112]; // [sp+458h] [-458h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v21 = v7;
    v23 = a7;
    do
    {
      v10 = 8 * v7;
      *(_QWORD *)(&v11 - 1) = *(_QWORD *)&v22[8 * (_DWORD)v7 - 8];
      v12 = *(_QWORD *)(8 * v7 + v11);
      LODWORD(v13) = HIDWORD(v12);
      HIDWORD(v13) = *(_DWORD *)(8 * v7 + v11 + 4);
      if ( (int)v12 - HIDWORD(v12) < 4 || (int)v7 >= 127 )
      {
        for ( ; SHIDWORD(v13) > SHIDWORD(v12); --HIDWORD(v13) )
        {
          v19 = HIDWORD(v12);
          for ( i = HIDWORD(v12) + 1; i <= SHIDWORD(v13); ++i )
          {
            if ( idSort_GameLayer::Compare((idSort_GameLayer *)this, a: (idStr *)&base[i], b: (idStr *)&base[v19]) > 0 )
              v19 = i;
          }
          SwapValues<idLayer>(a: &base[v19], b: &base[HIDWORD(v13)]);
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        v14 = v12 + HIDWORD(v12);
        LODWORD(v15) = (*(unsigned __int64 *)((char *)&a7 - 4) >> 63) + v12 + HIDWORD(v12);
        HIDWORD(v15) = 5 * v12;
        SwapValues<idLayer>(a: &base[v12], b: &base[v15 >> 1]);
        --HIDWORD(v13);
        while ( 1 )
        {
          if ( idSort_GameLayer::Compare((idSort_GameLayer *)this, a: (idStr *)&base[v13], b: (idStr *)&base[v12]) < 0 )
          {
            do
              LODWORD(v13) = v13 + 1;
            while ( (int)v13 < SHIDWORD(v13)
                 && idSort_GameLayer::Compare((idSort_GameLayer *)this, a: (idStr *)&base[v13], b: (idStr *)&base[v12]) < 0 );
          }
          v17 = (idStr *)&base[HIDWORD(v13)];
          if ( idSort_GameLayer::Compare((idSort_GameLayer *)this, a: v17, b: (idStr *)&base[v12]) > 0 )
            break;
LABEL_12:
          if ( (int)v13 < SHIDWORD(v13) )
          {
            SwapValues<idLayer>(a: &base[v13], b: (idLayer *)v17);
            LODWORD(v13) = v13 + 1;
            --HIDWORD(v13);
            if ( (int)v13 < SHIDWORD(v13) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v13);
          if ( SHIDWORD(v13) <= (int)v13 )
            break;
          v17 = (idStr *)&base[HIDWORD(v13)];
          if ( idSort_GameLayer::Compare((idSort_GameLayer *)this, a: v17, b: (idStr *)&base[v12]) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = (idStr *)&base[v13];
              idSort_GameLayer::Compare((idSort_GameLayer *)this, a: j, b: (idStr *)&base[v12]) <= 0;
              j = (idStr *)&base[v13] )
        {
          if ( (int)v13 >= (int)v12 )
            break;
          LODWORD(v13) = v13 + 1;
        }
        for ( ;
              idSort_GameLayer::Compare(
                (idSort_GameLayer *)this,
                a: (idStr *)&base[HIDWORD(v13)],
                b: (idStr *)&base[v12]) >= 0;
              --HIDWORD(v13) )
        {
          if ( SHIDWORD(v12) >= SHIDWORD(v13) )
            break;
        }
        SwapValues<idLayer>(a: &base[v12], b: (idLayer *)j);
        LODWORD(a7) = v22;
        LODWORD(v7) = v7 + 1;
        *(_QWORD *)&v24[v10] = v12;
        *(_QWORD *)&v22[v10] = v13;
        v16 = &base[v12];
        *(_QWORD *)(v10 + v11) = *(__int64 *)((char *)&v13 + 4);
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@UidTimeLineEvent@idComponentTimeLine@@VidSort_TimeLineEvent@@@@UBAXPAUidTimeLineEvent@idComponentTimeLine@@I@Z
// EA  : 0x82BB8770
// RVA : 0x00BB8770
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idComponentTimeLine::idTimeLineEvent,idSort_TimeLineEvent>::Sort(
        idSort_Quick<idComponentTimeLine::idTimeLineEvent,idSort_TimeLineEvent> *this,
        idComponentTimeLine::idTimeLineEvent *base,
        unsigned int num,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // r21
  __int64 v7; // r30 OVERLAPPED
  int v8; // r25
  int v9; // r22 OVERLAPPED
  __int64 v10; // r24
  int v11; // r31 OVERLAPPED
  int v12; // r11
  unsigned __int64 v13; // r10
  unsigned __int16 *v14; // r28
  void *v15; // r27
  unsigned __int16 *v16; // r27
  unsigned int v17; // r10
  unsigned __int16 *v18; // r28
  unsigned int v19; // r10
  unsigned __int16 *v20; // r28
  int v21; // r10
  int v22; // r11
  int v23; // r8
  void *v24; // r28
  _BYTE v25[168]; // [sp+50h] [-B20h] BYREF
  _BYTE v26[168]; // [sp+100h] [-A70h] BYREF
  _BYTE v27[168]; // [sp+1B0h] [-9C0h] BYREF
  _BYTE v28[168]; // [sp+260h] [-910h] BYREF
  __int64 v29; // [sp+310h] [-860h] BYREF
  _BYTE v30[1016]; // [sp+318h] [-858h] BYREF
  __int64 v31; // [sp+710h] [-460h]
  _BYTE v32[1112]; // [sp+718h] [-458h] BYREF

  HIDWORD(v7) = base;
  if ( num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v29 = v6;
    v31 = a6;
    do
    {
      v8 = 8 * v6;
      *(_QWORD *)(&v9 - 1) = *(_QWORD *)&v30[8 * (_DWORD)v6 - 8];
      v10 = *(_QWORD *)(8 * v6 + v9);
      v11 = HIDWORD(v10);
      LODWORD(v7) = *(_DWORD *)(8 * v6 + v9 + 4);
      if ( (int)v10 - HIDWORD(v10) < 4 || (int)v6 >= 127 )
      {
        for ( ; (int)v7 > SHIDWORD(v10); LODWORD(v7) = v7 - 1 )
        {
          v21 = HIDWORD(v10);
          v22 = HIDWORD(v10) + 1;
          if ( HIDWORD(v10) + 1 <= (int)v7 )
          {
            v23 = v7 - HIDWORD(v10);
            do
            {
              if ( *(unsigned __int16 *)(168 * v22 + HIDWORD(v7)) > (unsigned int)*(unsigned __int16 *)(168 * v21 + HIDWORD(v7)) )
                v21 = v22;
              --v23;
              ++v22;
            }
            while ( v23 != 0 );
          }
          v24 = (void *)(168 * v21 + HIDWORD(v7));
          memcpy(Dst: v26, Src: v24, Size: sizeof(v26));
          memcpy(Dst: v24, Src: (const void *)(168 * v7 + HIDWORD(v7)), Size: 0xA8u);
          memcpy(Dst: (void *)(168 * v7 + HIDWORD(v7)), Src: v26, Size: 0xA8u);
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        v12 = v10 + HIDWORD(v10);
        v13 = *(unsigned __int64 *)((char *)&a6 - 4) >> 63;
        LODWORD(a5) = v13 + v10 + HIDWORD(v10);
        v14 = (unsigned __int16 *)(168 * HIDWORD(v13) + HIDWORD(v7));
        v15 = (void *)(168 * (a5 >> 1) + HIDWORD(v7));
        memcpy(Dst: v28, Src: v14, Size: sizeof(v28));
        memcpy(Dst: v14, Src: v15, Size: 0xA8u);
        memcpy(Dst: v15, Src: v28, Size: 0xA8u);
        v16 = v14;
        LODWORD(v7) = v7 - 1;
        while ( 1 )
        {
          v17 = *v16;
          if ( *(unsigned __int16 *)(168 * v11 + HIDWORD(v7)) < v17 )
          {
            do
              ++v11;
            while ( v11 < (int)v7 && *(unsigned __int16 *)(168 * v11 + HIDWORD(v7)) < (unsigned int)*v16 );
          }
          v18 = (unsigned __int16 *)(168 * v7 + HIDWORD(v7));
          if ( (int)(*v18 - v17) > 0 )
            break;
LABEL_12:
          if ( v11 < (int)v7 )
          {
            memcpy(Dst: v27, Src: (const void *)(168 * v11 + HIDWORD(v7)), Size: sizeof(v27));
            memcpy(Dst: (void *)(168 * v11 + HIDWORD(v7)), Src: v18, Size: 0xA8u);
            memcpy(Dst: v18, Src: v27, Size: 0xA8u);
            ++v11;
            LODWORD(v7) = v7 - 1;
            if ( v11 < (int)v7 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v7) = v7 - 1;
          if ( (int)v7 <= v11 )
            break;
          v18 = (unsigned __int16 *)(168 * v7 + HIDWORD(v7));
          if ( *v18 <= (unsigned int)*v16 )
            goto LABEL_12;
        }
LABEL_14:
        v19 = *v16;
        v20 = (unsigned __int16 *)(168 * v11 + HIDWORD(v7));
        if ( *v20 <= v19 )
        {
          do
          {
            if ( v11 >= (int)v10 )
              break;
            ++v11;
            v20 = (unsigned __int16 *)(168 * v11 + HIDWORD(v7));
          }
          while ( *v20 <= (unsigned int)*v16 );
        }
        if ( (int)(*(unsigned __int16 *)(168 * v7 + HIDWORD(v7)) - v19) >= 0 )
        {
          do
          {
            if ( SHIDWORD(v10) >= (int)v7 )
              break;
            LODWORD(v7) = v7 - 1;
          }
          while ( *(unsigned __int16 *)(168 * v7 + HIDWORD(v7)) >= (unsigned int)*v16 );
        }
        memcpy(Dst: v25, Src: v16, Size: sizeof(v25));
        memcpy(Dst: v16, Src: v20, Size: 0xA8u);
        memcpy(Dst: v20, Src: v25, Size: 0xA8u);
        LODWORD(a6) = v30;
        LODWORD(v6) = v6 + 1;
        *(_QWORD *)&v32[v8] = v10;
        *(_QWORD *)&v30[v8] = *(__int64 *)((char *)&v7 - 4);
        *(_QWORD *)(v8 + v9) = v7;
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@UrageStatXpBonus@@VidSort_RageStatXpBonus@@@@UBAXPAUrageStatXpBonus@@I@Z
// EA  : 0x82BC89B8
// RVA : 0x00BC89B8
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<rageStatXpBonus,idSort_RageStatXpBonus>::Sort(
        idSort_Quick<rageStatXpBonus,idSort_RageStatXpBonus> *this,
        rageStatXpBonus *base,
        unsigned int num,
        int a4,
        unsigned __int64 a5,
        __int64 a6)
{
  __int64 v6; // r29
  int v7; // r31 OVERLAPPED
  int v8; // r30
  int v9; // r3 OVERLAPPED
  __int64 v10; // r11 OVERLAPPED
  __int128 v11; // r8
  rageStatXpBonus *v12; // r8
  rageStatXpBonus v13; // r6
  rageStatXpBonus *v14; // r9
  rageStatXpBonus *v15; // r7
  rageStatXpBonus v16; // r28
  rageStatXpBonus *i; // r9 OVERLAPPED
  rageStatXpBonus v18; // r31
  int v19; // r3
  int v20; // r6
  int v21; // r9
  int v22; // r8
  int v23; // r5
  rageStatXpBonus *v24; // r9
  rageStatXpBonus v25; // r6
  _QWORD v26[262]; // [sp+10h] [-830h] BYREF

  if ( num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v26[0] = v6;
    v26[128] = a6;
    do
    {
      *(_QWORD *)&v7 = v26[(_DWORD)v6];
      *(_QWORD *)&v9 = *(_QWORD *)(8 * v6 + v8);
      LODWORD(v10) = v26[v6];
      HIDWORD(v10) = *(_DWORD *)(8 * v6 + v8 + 4);
      if ( v9 - v7 < 4 || (int)v6 >= 127 )
      {
        if ( (int)v10 < SHIDWORD(v10) )
        {
          v19 = v10 + 1;
          do
          {
            v20 = v10;
            v21 = v10 + 1;
            if ( v19 <= SHIDWORD(v10) )
            {
              v22 = v19;
              v23 = HIDWORD(v10) - v10;
              do
              {
                if ( base[v20].min - base[v22].min > 0 )
                  v20 = v21;
                ++v21;
                --v23;
                v22 = v21;
              }
              while ( v23 != 0 );
            }
            v24 = &base[HIDWORD(v10)];
            LODWORD(a5) = &base[v20];
            --HIDWORD(v10);
            HIDWORD(a5) = v24->min;
            v25 = *(rageStatXpBonus *)a5;
            *(_DWORD *)a5 = v24->min;
            v25.min = v24->xp;
            *(_DWORD *)(a5 + 4) = v25.min;
            *v24 = v25;
          }
          while ( SHIDWORD(v10) > (int)v10 );
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        LODWORD(a5) = v9 + v7;
        *(_QWORD *)((char *)&v11 + 4) = a5 >> 63;
        LODWORD(v11) = DWORD2(v11) + v9 + v7;
        --HIDWORD(v10);
        *(_QWORD *)((char *)&v11 + 4) = (__int64)v11 >> 1;
        v12 = &base[v9];
        v13 = *v12;
        DWORD2(v11) = &base[DWORD2(v11)];
        *v12 = *(rageStatXpBonus *)DWORD2(v11);
        *(_QWORD *)DWORD2(v11) = v13;
        while ( 1 )
        {
          if ( v12->min - base[v10].min < 0 )
          {
            do
              LODWORD(v10) = v10 + 1;
            while ( (int)v10 < SHIDWORD(v10) && v12->min - base[v10].min < 0 );
          }
          v14 = &base[HIDWORD(v10)];
          if ( v12->min - v14->min > 0 )
            break;
LABEL_12:
          if ( (int)v10 < SHIDWORD(v10) )
          {
            v15 = &base[v10];
            LODWORD(v10) = v10 + 1;
            --HIDWORD(v10);
            v16 = *v15;
            v15->min = v14->min;
            v15->xp = v14->xp;
            *v14 = v16;
            if ( (int)v10 < SHIDWORD(v10) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v10);
          if ( SHIDWORD(v10) <= (int)v10 )
            break;
          v14 = &base[HIDWORD(v10)];
          if ( v12->min - v14->min <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( i = &base[v10]; v12->min - i->min <= 0; i = &base[v10] )
        {
          if ( (int)v10 >= v9 )
            break;
          LODWORD(v10) = v10 + 1;
        }
        for ( ; v12->min - base[HIDWORD(v10)].min >= 0; --HIDWORD(v10) )
        {
          if ( v7 >= SHIDWORD(v10) )
            break;
        }
        v18 = *v12;
        LODWORD(v6) = v6 + 1;
        v12->min = i->min;
        HIDWORD(a5) = i->xp;
        v12->xp = HIDWORD(a5);
        *(_QWORD *)((char *)&v26[129] + v13.min) = *(_QWORD *)&v9;
        *i = v18;
        *(_QWORD *)((char *)&v26[1] + v13.min) = v10;
        *(_QWORD *)(v13.min + v18.min) = *(__int64 *)((char *)&v10 + 4);
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@HV?$idSort_QuickDefault@H@@@@UBAXPAHI@Z
// EA  : 0x82C51828
// RVA : 0x00C51828
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<int,idSort_QuickDefault<int>>::Sort(
        idSort_Quick<int,idSort_QuickDefault<int> > *this,
        int *base,
        unsigned int num,
        int a4,
        unsigned __int64 a5,
        __int64 a6)
{
  __int64 v6; // r29
  int v7; // r5
  int v8; // r31 OVERLAPPED
  int v9; // r30 OVERLAPPED
  int v10; // r3 OVERLAPPED
  __int64 v11; // r11 OVERLAPPED
  __int128 v12; // r8
  int *v13; // r8
  int *v14; // r9
  int v15; // r28
  int v16; // r6
  int *i; // r9 OVERLAPPED
  int v18; // r3
  int v19; // r6
  int v20; // r9
  int v21; // r8
  int v22; // r5
  int v23; // r9
  int v24; // r6
  _QWORD v25[262]; // [sp+10h] [-830h] BYREF

  if ( num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v25[0] = v6;
    v25[128] = a6;
    do
    {
      v7 = v6;
      *(_QWORD *)&v8 = v25[(_DWORD)v6];
      *(_QWORD *)&v10 = *(_QWORD *)(8 * v6 + v9);
      LODWORD(v11) = v25[v6];
      HIDWORD(v11) = *(_DWORD *)(8 * v6 + v9 + 4);
      if ( v10 - v8 < 4 || (int)v6 >= 127 )
      {
        if ( (int)v11 < SHIDWORD(v11) )
        {
          v18 = v11 + 1;
          do
          {
            v19 = v11;
            v20 = v11 + 1;
            if ( v18 <= SHIDWORD(v11) )
            {
              v21 = v18;
              v22 = HIDWORD(v11) - v11;
              do
              {
                if ( base[v21] - base[v19] > 0 )
                  v19 = v20;
                ++v20;
                --v22;
                v21 = v20;
              }
              while ( v22 != 0 );
            }
            v23 = v19;
            HIDWORD(a5) = base[HIDWORD(v11)];
            v24 = base[v19];
            base[v23] = HIDWORD(a5);
            base[HIDWORD(v11)--] = v24;
          }
          while ( SHIDWORD(v11) > (int)v11 );
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        LODWORD(a5) = v10 + v8;
        *(_QWORD *)((char *)&v12 + 4) = a5 >> 63;
        LODWORD(v12) = DWORD2(v12) + v10 + v8;
        --HIDWORD(v11);
        *(_QWORD *)((char *)&v12 + 4) = (__int64)v12 >> 1;
        v13 = &base[v10];
        DWORD2(v12) *= 4;
        DWORD1(v12) = *v13;
        *v13 = *(int *)((char *)base + DWORD2(v12));
        *(int *)((char *)base + DWORD2(v12)) = DWORD1(v12);
        while ( 1 )
        {
          if ( base[(_DWORD)v11] - *v13 < 0 )
          {
            do
              LODWORD(v11) = v11 + 1;
            while ( (int)v11 < SHIDWORD(v11) && base[(_DWORD)v11] - *v13 < 0 );
          }
          v14 = &base[HIDWORD(v11)];
          if ( *v14 - *v13 > 0 )
            break;
LABEL_12:
          if ( (int)v11 < SHIDWORD(v11) )
          {
            --HIDWORD(v11);
            v15 = base[(_DWORD)v11];
            base[(_DWORD)v11] = *v14;
            LODWORD(v11) = v11 + 1;
            *v14 = v15;
            if ( (int)v11 < SHIDWORD(v11) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v11);
          if ( SHIDWORD(v11) <= (int)v11 )
            break;
          v14 = &base[HIDWORD(v11)];
          if ( *v14 - *v13 <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v16 = *v13;
        for ( i = &base[v11]; *i - *v13 <= 0; i = &base[v11] )
        {
          if ( (int)v11 >= v10 )
            break;
          LODWORD(v11) = v11 + 1;
        }
        if ( base[HIDWORD(v11)] - v16 >= 0 )
        {
          do
          {
            if ( v8 >= SHIDWORD(v11) )
              break;
            --HIDWORD(v11);
          }
          while ( base[HIDWORD(v11)] - *v13 >= 0 );
        }
        HIDWORD(a5) = *i;
        LODWORD(v6) = v6 + 1;
        *v13 = *i;
        v25[v7 + 129] = *(_QWORD *)&v10;
        *i = v16;
        v25[v7 + 1] = v11;
        *(_QWORD *)(v7 * 8 + v9) = *(__int64 *)((char *)&v11 + 4);
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@V?$idEntityPtr@VidEntity@@@@VidSort_SplineLoc@@@@UBAXPAV?$idEntityPtr@VidEntity@@@@I@Z
// EA  : 0x82C8C2C8
// RVA : 0x00C8C2C8
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idEntityPtr<idEntity>,idSort_SplineLoc>::Sort(
        idSort_Quick<idEntityPtr<idEntity>,idSort_SplineLoc> *this,
        idEntityPtr<idEntity> *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r21
  int v10; // r25
  int v11; // r22 OVERLAPPED
  __int64 v12; // r24
  _BYTE v13[12]; // r30 OVERLAPPED
  int v14; // r27
  __int128 v15; // r11
  idEntityPtr<idEntity> *v16; // r27
  int v17; // r9
  idEntityPtr<idEntity> *j; // r27
  int v19; // r9
  int v20; // r28
  int i; // r30
  int value; // r8
  _QWORD v23[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v23[0] = v7;
    v23[128] = a7;
    do
    {
      v10 = v7;
      *(_QWORD *)(&v11 - 1) = v23[(_DWORD)v7];
      v12 = *(_QWORD *)(8 * v7 + v11);
      *(_DWORD *)&v13[4] = HIDWORD(v12);
      v14 = *(_DWORD *)(8 * v7 + v11 + 4);
      if ( (int)v12 - HIDWORD(v12) < 4 || (int)v7 >= 127 )
      {
        for ( ; v14 > SHIDWORD(v12); --v14 )
        {
          v20 = HIDWORD(v12);
          for ( i = HIDWORD(v12) + 1; i <= v14; ++i )
          {
            if ( idSort_SplineLoc::Compare((idSort_SplineLoc *)this, a: &base[i], b: &base[v20]) > 0 )
              v20 = i;
          }
          value = base[v20].spawnId.value;
          base[v20] = base[v14];
          base[v14].spawnId.value = value;
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v15) = v12 + HIDWORD(v12);
        DWORD2(v15) = 4 * v12;
        *(_DWORD *)v13 = &base[v12];
        LODWORD(v15) = ((unsigned __int64)v15 >> 63) + v12 + HIDWORD(v12);
        *(_DWORD *)&v13[8] = v12 - 1;
        *(_QWORD *)((char *)&v15 + 4) = (__int64)v15 >> 1;
        DWORD1(v15) = **(_DWORD **)v13;
        **(_DWORD **)v13 = base[DWORD2(v15)].spawnId.value;
        base[DWORD2(v15)] = *(idEntityPtr<idEntity> *)((char *)&v15 + 4);
        while ( 1 )
        {
          if ( idSort_SplineLoc::Compare((idSort_SplineLoc *)this, a: &base[*(_DWORD *)&v13[4]], b: &base[v12]) < 0 )
          {
            do
              ++*(_DWORD *)&v13[4];
            while ( *(int *)&v13[4] < *(int *)&v13[8]
                 && idSort_SplineLoc::Compare((idSort_SplineLoc *)this, a: &base[*(_DWORD *)&v13[4]], b: &base[v12]) < 0 );
          }
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_SplineLoc::Compare((idSort_SplineLoc *)this, a: v16, b: &base[v12]) > 0 )
            break;
LABEL_12:
          if ( *(int *)&v13[4] < *(int *)&v13[8] )
          {
            --*(_DWORD *)&v13[8];
            v17 = base[*(_DWORD *)&v13[4]].spawnId.value;
            base[(*(_DWORD *)&v13[4])++] = (idEntityPtr<idEntity>)v16->spawnId.value;
            v16->spawnId.value = v17;
            if ( *(int *)&v13[4] < *(int *)&v13[8] )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --*(_DWORD *)&v13[8];
          if ( *(int *)&v13[8] <= *(int *)&v13[4] )
            break;
          v16 = &base[*(_DWORD *)&v13[8]];
          if ( idSort_SplineLoc::Compare((idSort_SplineLoc *)this, a: v16, b: &base[v12]) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = &base[*(_DWORD *)&v13[4]];
              idSort_SplineLoc::Compare((idSort_SplineLoc *)this, a: j, b: &base[v12]) <= 0;
              j = &base[*(_DWORD *)&v13[4]] )
        {
          if ( *(int *)&v13[4] >= (int)v12 )
            break;
          ++*(_DWORD *)&v13[4];
        }
        for ( ;
              idSort_SplineLoc::Compare((idSort_SplineLoc *)this, a: &base[*(_DWORD *)&v13[8]], b: &base[v12]) >= 0;
              --*(_DWORD *)&v13[8] )
        {
          if ( SHIDWORD(v12) >= *(int *)&v13[8] )
            break;
        }
        v19 = **(_DWORD **)v13;
        LODWORD(v7) = v7 + 1;
        **(_DWORD **)v13 = j->spawnId.value;
        v23[v10 + 129] = v12;
        j->spawnId.value = v19;
        v23[v10 + 1] = *(_QWORD *)v13;
        *(_QWORD *)(v10 * 8 + v11) = *(_QWORD *)&v13[4];
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ??$SwapValues@UsplineMoverModifier_t@@@@YAXAAUsplineMoverModifier_t@@0@Z
// EA  : 0x82C935F0
// RVA : 0x00C935F0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<splineMoverModifier_t>(splineMoverModifier_t *a, splineMoverModifier_t *b)
{
  splineMoverModifier_t v4; // [sp+50h] [-2B0h] BYREF

  splineMoverModifier_t::splineMoverModifier_t(this: &v4, __that: a);
  splineMoverModifier_t::operator=(this: a, __that: b);
  splineMoverModifier_t::operator=(this: b, __that: &v4);
  splineMoverModifier_t::~splineMoverModifier_t(this: &v4);
}


// ========================================================================
// __unwind$525209
// EA  : 0x82C9363C
// RVA : 0x00C9363C
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_525209()
{
  int v0; // r12

  splineMoverModifier_t::~splineMoverModifier_t(this: (splineMoverModifier_t *)(v0 - 768 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@UsplineMoverModifier_t@@VidSort_MoverModifier@@@@UBAXPAUsplineMoverModifier_t@@I@Z
// EA  : 0x82C94360
// RVA : 0x00C94360
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<splineMoverModifier_t,idSort_MoverModifier>::Sort(
        idSort_Quick<splineMoverModifier_t,idSort_MoverModifier> *this,
        splineMoverModifier_t *base,
        unsigned int num,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // r20
  int v8; // r24
  int v9; // r21 OVERLAPPED
  __int64 v10; // r23
  __int64 v11; // r27 OVERLAPPED
  int v12; // r11
  unsigned __int64 v13; // r10
  splineMoverModifier_t *v14; // r25 OVERLAPPED
  __int64 v15; // r29
  splineMoverModifier_t *i; // r4
  int v17; // r25
  int v18; // r11
  int v19; // r9
  int v20; // r6
  splineMoverModifier_t *v21; // r10
  int v22; // r8
  splineMoverModifier_t *v23; // r29
  splineMoverModifier_t v24; // [sp+60h] [-B00h] BYREF
  __int64 v25; // [sp+2F0h] [-870h] BYREF
  _QWORD v26[269]; // [sp+2F8h] [-868h] BYREF

  if ( num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v25 = v6;
    v26[127] = a6;
    do
    {
      v8 = v6;
      *(_QWORD *)(&v9 - 1) = v26[(int)v6 - 1];
      v10 = *(_QWORD *)(8 * v6 + v9);
      v11 = v10;
      if ( (int)v10 - HIDWORD(v10) < 4 || (int)v6 >= 127 )
      {
        if ( SHIDWORD(v10) < (int)v10 )
        {
          v17 = v10 - 3;
          do
          {
            v18 = HIDWORD(v10);
            v19 = HIDWORD(v10) + 1;
            if ( HIDWORD(v10) + 1 <= (int)v11 )
            {
              if ( 4 - (HIDWORD(v10) + 1) + v17 >= 4 )
              {
                v20 = HIDWORD(v10) + 3;
                do
                {
                  v21 = &base[v19];
                  if ( (int)(float)(v21->length - base[v18].length) > 0 )
                    v18 = v19;
                  if ( (int)(float)(v21[1].length - base[v18].length) > 0 )
                    v18 = v20 - 1;
                  if ( (int)(float)(base[v19 + 2].length - base[v18].length) > 0 )
                    v18 = v20;
                  if ( (int)(float)(base[v19 + 3].length - base[v18].length) > 0 )
                    v18 = v20 + 1;
                  v19 += 4;
                  v20 += 4;
                }
                while ( v19 <= v17 );
              }
              if ( v19 <= (int)v11 )
              {
                v22 = v11 - v19 + 1;
                do
                {
                  if ( (int)(float)(base[v19].length - base[v18].length) > 0 )
                    v18 = v19;
                  --v22;
                  ++v19;
                }
                while ( v22 != 0 );
              }
            }
            v23 = &base[v18];
            splineMoverModifier_t::splineMoverModifier_t(this: &v24, __that: v23);
            splineMoverModifier_t::operator=(this: v23, __that: &base[v11]);
            splineMoverModifier_t::operator=(this: &base[v11], __that: &v24);
            splineMoverModifier_t::~splineMoverModifier_t(this: &v24);
            LODWORD(v11) = v11 - 1;
            --v17;
          }
          while ( (int)v11 > SHIDWORD(v10) );
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        v12 = v10 + HIDWORD(v10);
        v13 = *(unsigned __int64 *)((char *)&a6 - 4) >> 63;
        LODWORD(a5) = v13 + v10 + HIDWORD(v10);
        v14 = &base[HIDWORD(v13)];
        SwapValues<splineMoverModifier_t>(a: v14, b: &base[a5 >> 1]);
        LODWORD(v15) = v10 - 1;
        while ( 1 )
        {
          if ( (int)(float)(base[HIDWORD(v11)].length - v14->length) < 0 )
          {
            do
              ++HIDWORD(v11);
            while ( SHIDWORD(v11) < (int)v15 && (int)(float)(base[HIDWORD(v11)].length - v14->length) < 0 );
          }
          HIDWORD(v15) = &base[v15];
          if ( (int)(float)(*(float *)HIDWORD(v15) - v14->length) > 0 )
            break;
LABEL_12:
          if ( SHIDWORD(v11) < (int)v15 )
          {
            splineMoverModifier_t::splineMoverModifier_t(this: &v24, __that: &base[HIDWORD(v11)]);
            splineMoverModifier_t::operator=(
              this: &base[HIDWORD(v11)],
              __that: (const splineMoverModifier_t *)HIDWORD(v15));
            splineMoverModifier_t::operator=(this: (splineMoverModifier_t *)HIDWORD(v15), __that: &v24);
            splineMoverModifier_t::~splineMoverModifier_t(this: &v24);
            ++HIDWORD(v11);
            LODWORD(v15) = v15 - 1;
            if ( SHIDWORD(v11) < (int)v15 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v15) = v15 - 1;
          if ( (int)v15 <= SHIDWORD(v11) )
            break;
          HIDWORD(v15) = &base[v15];
          if ( (int)(float)(*(float *)HIDWORD(v15) - v14->length) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( i = &base[HIDWORD(v11)]; (int)(float)(i->length - v14->length) <= 0; i = &base[HIDWORD(v11)] )
        {
          if ( SHIDWORD(v11) >= (int)v10 )
            break;
          ++HIDWORD(v11);
        }
        for ( ; (int)(float)(base[v15].length - v14->length) >= 0; LODWORD(v15) = v15 - 1 )
        {
          if ( SHIDWORD(v10) >= (int)v15 )
            break;
        }
        SwapValues<splineMoverModifier_t>(a: v14, b: i);
        LODWORD(a6) = v26;
        LODWORD(v6) = v6 + 1;
        v26[v8 + 128] = v10;
        v26[v8] = *(__int64 *)((char *)&v11 + 4);
        *(_QWORD *)(v8 * 8 + v9) = v15;
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// __unwind$526551
// EA  : 0x82C947A4
// RVA : 0x00C947A4
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_526551()
{
  int v0; // r12

  splineMoverModifier_t::~splineMoverModifier_t(this: (splineMoverModifier_t *)(v0 - 2912 + 96));
}


// ========================================================================
// __unwind$526567
// EA  : 0x82C947CC
// RVA : 0x00C947CC
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_526567()
{
  int v0; // r12

  splineMoverModifier_t::~splineMoverModifier_t(this: (splineMoverModifier_t *)(v0 - 2912 + 96));
}


// ========================================================================
// ??$SwapValues@VidTarget_TimedEvents_Event@idTarget_TimedEvents@@@@YAXAAVidTarget_TimedEvents_Event@idTarget_TimedEvents@@0@Z
// EA  : 0x82CD94E0
// RVA : 0x00CD94E0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<idTarget_TimedEvents::idTarget_TimedEvents_Event>(
        idTarget_TimedEvents::idTarget_TimedEvents_Event *a,
        idTarget_TimedEvents::idTarget_TimedEvents_Event *b)
{
  idStr *p_call; // r27
  int len; // r28
  int v6; // r11
  size_t v7; // r29
  float delay; // [sp+50h] [-60h]
  int value; // [sp+54h] [-5Ch]
  idStr v10[2]; // [sp+58h] [-58h] BYREF

  delay = a->delay;
  p_call = &a->call;
  value = a->target.spawnId.value;
  idStr::idStr(this: v10, text: &a->call);
  a->delay = b->delay;
  a->target.spawnId.value = b->target.spawnId.value;
  len = b->call.len;
  idStr::EnsureAlloced(this: p_call, amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: a->call.data, Src: b->call.data, Size: len);
  a->call.data[len] = 0;
  v6 = v10[0].len;
  a->call.len = len;
  b->delay = delay;
  b->target.spawnId.value = value;
  v7 = v6;
  idStr::EnsureAlloced(this: &b->call, amount: v6 + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: b->call.data, Src: v10[0].data, Size: v7);
  b->call.data[v7] = 0;
  b->call.len = v7;
  idStr::FreeData(this: v10);
}


// ========================================================================
// __unwind$518540
// EA  : 0x82CD95BC
// RVA : 0x00CD95BC
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_518540()
{
  int v0; // r12

  idAnimatedSimple::idHitDetection_t::~idHitDetection_t(this: (idTarget_TimedEvents::idTarget_TimedEvents_Event *)(v0 - 176 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidTarget_TimedEvents_Event@idTarget_TimedEvents@@V?$idSort_QuickDefault@VidTarget_TimedEvents_Event@idTarget_TimedEvents@@@@@@UBAXPAVidTarget_TimedEvents_Event@idTarget_TimedEvents@@I@Z
// EA  : 0x82CDC7B0
// RVA : 0x00CDC7B0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idTarget_TimedEvents::idTarget_TimedEvents_Event,idSort_QuickDefault<idTarget_TimedEvents::idTarget_TimedEvents_Event>>::Sort(
        idSort_Quick<idTarget_TimedEvents::idTarget_TimedEvents_Event,idSort_QuickDefault<idTarget_TimedEvents::idTarget_TimedEvents_Event> > *this,
        idTarget_TimedEvents::idTarget_TimedEvents_Event *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r23
  int v9; // r27 OVERLAPPED
  __int64 v10; // r25
  _BYTE v11[12]; // r30 OVERLAPPED
  int v12; // r11
  __int64 v13; // r11
  idTarget_TimedEvents::idTarget_TimedEvents_Event *v14; // r26
  double delay; // fp13
  double v16; // fp13
  double v17; // fp0
  int v18; // r11
  int v19; // r10
  int v20; // r4
  idTarget_TimedEvents::idTarget_TimedEvents_Event *v21; // r9
  int v22; // r5
  __int64 v23; // [sp+50h] [-850h] BYREF
  _BYTE v24[1016]; // [sp+58h] [-848h] BYREF
  __int64 v25; // [sp+450h] [-450h]
  _BYTE v26[1096]; // [sp+458h] [-448h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v23 = v7;
    v25 = a7;
    do
    {
      v9 = 8 * v7;
      v10 = *(_QWORD *)&v24[8 * (_DWORD)v7 - 8];
      *(_QWORD *)v11 = *(_QWORD *)(8 * v7 + HIDWORD(v10));
      *(_DWORD *)v11 = *(_DWORD *)&v24[8 * v7 - 4];
      if ( *(_DWORD *)&v11[4] - (int)v10 < 4 || (int)v7 >= 127 )
      {
        if ( *(int *)v11 < *(int *)&v11[4] )
        {
          *(_DWORD *)&v11[8] = *(_DWORD *)&v11[4] - 3;
          do
          {
            v18 = *(_DWORD *)v11;
            v19 = *(_DWORD *)v11 + 1;
            if ( *(_DWORD *)v11 + 1 <= *(int *)&v11[4] )
            {
              if ( 4 - (*(_DWORD *)v11 + 1) + *(_DWORD *)&v11[8] >= 4 )
              {
                v20 = *(_DWORD *)v11 + 3;
                do
                {
                  v21 = &base[v19];
                  if ( v21->delay > (double)base[v18].delay )
                    v18 = v19;
                  if ( v21[1].delay > (double)base[v18].delay )
                    v18 = v20 - 1;
                  if ( base[v19 + 2].delay > (double)base[v18].delay )
                    v18 = v20;
                  if ( base[v19 + 3].delay > (double)base[v18].delay )
                    v18 = v20 + 1;
                  v19 += 4;
                  v20 += 4;
                }
                while ( v19 <= *(int *)&v11[8] );
              }
              if ( v19 <= *(int *)&v11[4] )
              {
                v22 = *(_DWORD *)&v11[4] - v19 + 1;
                do
                {
                  if ( base[v19].delay > (double)base[v18].delay )
                    v18 = v19;
                  --v22;
                  ++v19;
                }
                while ( v22 != 0 );
              }
            }
            SwapValues<idTarget_TimedEvents::idTarget_TimedEvents_Event>(a: &base[v18], b: &base[*(_DWORD *)&v11[4]]);
            --*(_DWORD *)&v11[4];
            --*(_DWORD *)&v11[8];
          }
          while ( *(int *)&v11[4] > *(int *)v11 );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        v12 = *(_DWORD *)&v11[4] + v10;
        LODWORD(v13) = (*(unsigned __int64 *)((char *)&a7 - 4) >> 63) + *(_DWORD *)&v11[4] + v10;
        HIDWORD(v13) = 5 * *(_DWORD *)&v11[4];
        SwapValues<idTarget_TimedEvents::idTarget_TimedEvents_Event>(a: &base[*(_DWORD *)&v11[4]], b: &base[v13 >> 1]);
        v14 = &base[*(_DWORD *)&v11[4]];
        *(_DWORD *)&v11[8] = *(_DWORD *)&v11[4] - 1;
        do
        {
          delay = v14->delay;
          do
          {
            if ( base[*(_DWORD *)v11].delay >= delay )
              break;
            ++*(_DWORD *)v11;
          }
          while ( *(int *)v11 < *(int *)&v11[8] );
          while ( base[*(_DWORD *)&v11[8]].delay > delay )
          {
            --*(_DWORD *)&v11[8];
            if ( *(int *)&v11[8] <= *(int *)v11 )
              goto LABEL_14;
          }
          if ( *(int *)v11 >= *(int *)&v11[8] )
            break;
          SwapValues<idTarget_TimedEvents::idTarget_TimedEvents_Event>(
            a: &base[*(_DWORD *)v11],
            b: &base[*(_DWORD *)&v11[8]]);
          ++*(_DWORD *)v11;
          --*(_DWORD *)&v11[8];
        }
        while ( *(int *)v11 < *(int *)&v11[8] );
LABEL_14:
        v16 = v14->delay;
        while ( 1 )
        {
          v17 = base[*(_DWORD *)v11].delay;
          if ( v17 >= v16 && v17 > v16 )
            break;
          if ( *(int *)v11 >= *(int *)&v11[4] )
            break;
          ++*(_DWORD *)v11;
        }
        while ( base[*(_DWORD *)&v11[8]].delay >= v16 && (int)v10 < *(int *)&v11[8] )
          --*(_DWORD *)&v11[8];
        SwapValues<idTarget_TimedEvents::idTarget_TimedEvents_Event>(
          a: &base[*(_DWORD *)&v11[4]],
          b: &base[*(_DWORD *)v11]);
        LODWORD(a7) = v24;
        LODWORD(v7) = v7 + 1;
        *(_QWORD *)&v26[v9] = *(_QWORD *)v11;
        *(_QWORD *)&v24[v9] = *(_QWORD *)&v11[8];
        *(_QWORD *)(v9 + HIDWORD(v10)) = *(_QWORD *)&v11[4];
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@HVidSort_ClassTypeInfoByName@@@@UBAXPAHI@Z
// EA  : 0x82D62B98
// RVA : 0x00D62B98
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<int,idSort_ClassTypeInfoByName>::Sort(
        idSort_Quick<int,idSort_ClassTypeInfoByName> *this,
        int *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r21
  int v9; // r25
  int v10; // r22 OVERLAPPED
  __int64 v11; // r24
  __int64 v12; // r29 OVERLAPPED
  __int128 v13; // r11
  int *v14; // r26
  int *v15; // r27
  int v16; // r9
  int *i; // r27 OVERLAPPED
  int v18; // r9
  int v19; // r25
  int v20; // r26
  int v21; // r27
  int v22; // r10
  int v23; // r8
  _QWORD v24[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v24[0] = v7;
    v24[128] = a7;
    do
    {
      v9 = v7;
      *(_QWORD *)(&v10 - 1) = v24[(_DWORD)v7];
      v11 = *(_QWORD *)(8 * v7 + v10);
      v12 = v11;
      if ( (int)v11 - HIDWORD(v11) < 4 || (int)v7 >= 127 )
      {
        if ( SHIDWORD(v11) < (int)v11 )
        {
          v19 = HIDWORD(v11) + 1;
          do
          {
            v20 = HIDWORD(v11);
            v21 = HIDWORD(v11) + 1;
            if ( v19 <= (int)v12 )
            {
              v22 = v19;
              do
              {
                if ( idStr::Icmp(s1: classTypeInfo[base[v22]].name, s2: classTypeInfo[base[v20]].name) > 0 )
                  v20 = v21;
                v22 = ++v21;
              }
              while ( v21 <= (int)v12 );
            }
            v23 = base[v20];
            base[v20] = base[(_DWORD)v12];
            base[(_DWORD)v12] = v23;
            LODWORD(v12) = v12 - 1;
          }
          while ( (int)v12 > SHIDWORD(v11) );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v13) = v11 + HIDWORD(v11);
        DWORD2(v13) = 4 * v11;
        v14 = &base[v11];
        LODWORD(v13) = ((unsigned __int64)v13 >> 63) + v11 + HIDWORD(v11);
        LODWORD(v12) = v11 - 1;
        *(_QWORD *)((char *)&v13 + 4) = (__int64)v13 >> 1;
        DWORD1(v13) = *v14;
        *v14 = base[DWORD2(v13)];
        base[DWORD2(v13)] = DWORD1(v13);
        while ( 1 )
        {
          if ( idStr::Icmp(s1: classTypeInfo[base[HIDWORD(v12)]].name, s2: classTypeInfo[*v14].name) < 0 )
          {
            do
              ++HIDWORD(v12);
            while ( SHIDWORD(v12) < (int)v12
                 && idStr::Icmp(s1: classTypeInfo[base[HIDWORD(v12)]].name, s2: classTypeInfo[*v14].name) < 0 );
          }
          v15 = &base[v12];
          if ( idStr::Icmp(s1: classTypeInfo[*v15].name, s2: classTypeInfo[*v14].name) > 0 )
            break;
LABEL_12:
          if ( SHIDWORD(v12) < (int)v12 )
          {
            LODWORD(v12) = v12 - 1;
            v16 = base[HIDWORD(v12)];
            base[HIDWORD(v12)++] = *v15;
            *v15 = v16;
            if ( SHIDWORD(v12) < (int)v12 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v12) = v12 - 1;
          if ( (int)v12 <= SHIDWORD(v12) )
            break;
          v15 = &base[v12];
          if ( idStr::Icmp(s1: classTypeInfo[*v15].name, s2: classTypeInfo[*v14].name) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( i = &base[HIDWORD(v12)];
              idStr::Icmp(s1: classTypeInfo[*i].name, s2: classTypeInfo[*v14].name) <= 0;
              i = &base[HIDWORD(v12)] )
        {
          if ( SHIDWORD(v12) >= (int)v11 )
            break;
          ++HIDWORD(v12);
        }
        for ( ;
              idStr::Icmp(s1: classTypeInfo[base[(_DWORD)v12]].name, s2: classTypeInfo[*v14].name) >= 0;
              LODWORD(v12) = v12 - 1 )
        {
          if ( SHIDWORD(v11) >= (int)v12 )
            break;
        }
        v18 = *v14;
        LODWORD(v7) = v7 + 1;
        *v14 = *i;
        v24[v9 + 129] = v11;
        *i = v18;
        v24[v9 + 1] = *(__int64 *)((char *)&v12 + 4);
        *(_QWORD *)(v9 * 8 + v10) = v12;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@HVidSort_ClassTypeInfoBySize@@@@UBAXPAHI@Z
// EA  : 0x82D62EA0
// RVA : 0x00D62EA0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<int,idSort_ClassTypeInfoBySize>::Sort(
        idSort_Quick<int,idSort_ClassTypeInfoBySize> *this,
        int *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r27
  int v8; // r31
  int v9; // r28 OVERLAPPED
  __int64 v10; // r30
  __int64 v11; // r10 OVERLAPPED
  unsigned __int64 v12; // r8
  __int64 v13; // r8 OVERLAPPED
  int v14; // r5
  int size; // r6
  int v16; // r3
  int v17; // r3
  int v18; // r5
  int v19; // r31
  int v20; // r5
  int v21; // r8
  int v22; // r7
  int v23; // r3
  int v24; // r8
  int v25; // r5
  __int64 v26; // [sp+10h] [-840h] BYREF
  _BYTE v27[1016]; // [sp+18h] [-838h] BYREF
  __int64 v28; // [sp+410h] [-440h]
  _BYTE v29[1080]; // [sp+418h] [-438h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v26 = v7;
    v28 = a7;
    do
    {
      v8 = 8 * v7;
      *(_QWORD *)(&v9 - 1) = *(_QWORD *)&v27[8 * (_DWORD)v7 - 8];
      v10 = *(_QWORD *)(8 * v7 + v9);
      v11 = v10;
      if ( (int)v10 - HIDWORD(v10) < 4 || (int)v7 >= 127 )
      {
        if ( SHIDWORD(v10) < (int)v10 )
        {
          v19 = HIDWORD(v10) + 1;
          do
          {
            v20 = HIDWORD(v10);
            v21 = HIDWORD(v10) + 1;
            if ( v19 <= (int)v11 )
            {
              v22 = v19;
              v23 = v11 - HIDWORD(v10);
              do
              {
                if ( classTypeInfo[base[v22]].size - classTypeInfo[base[v20]].size > 0 )
                  v20 = v21;
                ++v21;
                --v23;
                v22 = v21;
              }
              while ( v23 != 0 );
            }
            v24 = v20;
            v25 = base[v20];
            base[v24] = base[(_DWORD)v11];
            base[(_DWORD)v11] = v25;
            LODWORD(v11) = v11 - 1;
          }
          while ( (int)v11 > SHIDWORD(v10) );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v12) = v10 + HIDWORD(v10);
        HIDWORD(v12) = 4 * v10;
        LODWORD(v12) = (v12 >> 63) + v10 + HIDWORD(v10);
        HIDWORD(v13) = &base[v10];
        LODWORD(v11) = v10 - 1;
        LODWORD(v13) = 4 * (v13 >> 1);
        v14 = *(_DWORD *)HIDWORD(v13);
        *(_DWORD *)HIDWORD(v13) = *(int *)((char *)base + v13);
        *(int *)((char *)base + v13) = v14;
        while ( 1 )
        {
          size = classTypeInfo[*(_DWORD *)HIDWORD(v13)].size;
          if ( classTypeInfo[base[HIDWORD(v11)]].size - size < 0 )
          {
            do
              ++HIDWORD(v11);
            while ( SHIDWORD(v11) < (int)v11
                 && classTypeInfo[base[HIDWORD(v11)]].size - classTypeInfo[*(_DWORD *)HIDWORD(v13)].size < 0 );
          }
          LODWORD(v13) = &base[v11];
          if ( classTypeInfo[*(_DWORD *)v13].size - size > 0 )
            break;
LABEL_12:
          if ( SHIDWORD(v11) < (int)v11 )
          {
            LODWORD(v11) = v11 - 1;
            v16 = base[HIDWORD(v11)];
            base[HIDWORD(v11)++] = *(_DWORD *)v13;
            *(_DWORD *)v13 = v16;
            if ( SHIDWORD(v11) < (int)v11 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v11) = v11 - 1;
          if ( (int)v11 <= SHIDWORD(v11) )
            break;
          LODWORD(v13) = &base[v11];
          if ( classTypeInfo[*(_DWORD *)v13].size - classTypeInfo[*(_DWORD *)HIDWORD(v13)].size <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v17 = *(_DWORD *)HIDWORD(v13);
        LODWORD(v13) = &base[HIDWORD(v11)];
        v18 = classTypeInfo[*(_DWORD *)HIDWORD(v13)].size;
        if ( classTypeInfo[*(_DWORD *)v13].size - v18 <= 0 )
        {
          do
          {
            if ( SHIDWORD(v11) >= (int)v10 )
              break;
            LODWORD(v13) = &base[++HIDWORD(v11)];
          }
          while ( classTypeInfo[*(_DWORD *)v13].size - classTypeInfo[*(_DWORD *)HIDWORD(v13)].size <= 0 );
        }
        if ( classTypeInfo[base[(_DWORD)v11]].size - v18 >= 0 )
        {
          do
          {
            if ( SHIDWORD(v10) >= (int)v11 )
              break;
            LODWORD(v11) = v11 - 1;
          }
          while ( classTypeInfo[base[(_DWORD)v11]].size - classTypeInfo[*(_DWORD *)HIDWORD(v13)].size >= 0 );
        }
        HIDWORD(v10) = v27;
        LODWORD(v7) = v7 + 1;
        *(_DWORD *)HIDWORD(v13) = *(_DWORD *)v13;
        *(_QWORD *)&v29[v8] = v10;
        *(_DWORD *)v13 = v17;
        *(_QWORD *)&v27[v8] = *(__int64 *)((char *)&v11 + 4);
        *(_QWORD *)(v8 + v9) = v11;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@HVidSort_ClassVariableInfoByName@@@@UBAXPAHI@Z
// EA  : 0x82D631B0
// RVA : 0x00D631B0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<int,idSort_ClassVariableInfoByName>::Sort(
        idSort_Quick<int,idSort_ClassVariableInfoByName> *this,
        int *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r21
  int v10; // r22 OVERLAPPED
  __int64 v11; // r24
  _BYTE v12[12]; // r27 OVERLAPPED
  int v13; // r29
  __int128 v14; // r11
  int *v15; // r30
  int *v16; // r29
  int v17; // r9
  int *i; // r29
  int v19; // r9
  int v20; // r25
  int v21; // r30
  int v22; // r27
  int v23; // r11
  int v24; // r8
  _QWORD v25[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v25[0] = v7;
    v25[128] = a7;
    do
    {
      *(_DWORD *)v12 = 8 * v7;
      *(_QWORD *)(&v10 - 1) = v25[(_DWORD)v7];
      v11 = *(_QWORD *)(8 * v7 + v10);
      *(_DWORD *)&v12[4] = HIDWORD(v11);
      v13 = *(_DWORD *)(8 * v7 + v10 + 4);
      if ( (int)v11 - HIDWORD(v11) < 4 || (int)v7 >= 127 )
      {
        if ( SHIDWORD(v11) < v13 )
        {
          v20 = HIDWORD(v11) + 1;
          do
          {
            v21 = HIDWORD(v11);
            v22 = HIDWORD(v11) + 1;
            if ( v20 <= v13 )
            {
              v23 = v20;
              do
              {
                if ( idStr::Icmp(
                       s1: *(const char **)(40 * base[v23] + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8),
                       s2: *(const char **)(40 * base[v21] + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8)) > 0 )
                  v21 = v22;
                v23 = ++v22;
              }
              while ( v22 <= v13 );
            }
            v24 = base[v21];
            base[v21] = base[v13];
            base[v13--] = v24;
          }
          while ( v13 > SHIDWORD(v11) );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v14) = v11 + HIDWORD(v11);
        DWORD2(v14) = 4 * v11;
        v15 = &base[v11];
        LODWORD(v14) = ((unsigned __int64)v14 >> 63) + v11 + HIDWORD(v11);
        *(_DWORD *)&v12[8] = v11 - 1;
        *(_QWORD *)((char *)&v14 + 4) = (__int64)v14 >> 1;
        DWORD1(v14) = *v15;
        *v15 = base[DWORD2(v14)];
        base[DWORD2(v14)] = DWORD1(v14);
        while ( 1 )
        {
          if ( idStr::Icmp(
                 s1: *(const char **)(40 * base[*(_DWORD *)&v12[4]] + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8),
                 s2: *(const char **)(40 * *v15 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8)) < 0 )
          {
            do
              ++*(_DWORD *)&v12[4];
            while ( *(int *)&v12[4] < *(int *)&v12[8]
                 && idStr::Icmp(
                      s1: *(const char **)(40 * base[*(_DWORD *)&v12[4]] + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8),
                      s2: *(const char **)(40 * *v15 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8)) < 0 );
          }
          v16 = &base[*(_DWORD *)&v12[8]];
          if ( idStr::Icmp(
                 s1: *(const char **)(40 * *v16 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8),
                 s2: *(const char **)(40 * *v15 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8)) > 0 )
            break;
LABEL_12:
          if ( *(int *)&v12[4] < *(int *)&v12[8] )
          {
            --*(_DWORD *)&v12[8];
            v17 = base[*(_DWORD *)&v12[4]];
            base[(*(_DWORD *)&v12[4])++] = *v16;
            *v16 = v17;
            if ( *(int *)&v12[4] < *(int *)&v12[8] )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --*(_DWORD *)&v12[8];
          if ( *(int *)&v12[8] <= *(int *)&v12[4] )
            break;
          v16 = &base[*(_DWORD *)&v12[8]];
          if ( idStr::Icmp(
                 s1: *(const char **)(40 * *v16 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8),
                 s2: *(const char **)(40 * *v15 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8)) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( i = &base[*(_DWORD *)&v12[4]];
              idStr::Icmp(
                s1: *(const char **)(40 * *i + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8),
                s2: *(const char **)(40 * *v15 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8)) <= 0;
              i = &base[*(_DWORD *)&v12[4]] )
        {
          if ( *(int *)&v12[4] >= (int)v11 )
            break;
          ++*(_DWORD *)&v12[4];
        }
        for ( ;
              idStr::Icmp(
                s1: *(const char **)(40 * base[*(_DWORD *)&v12[8]] + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8),
                s2: *(const char **)(40 * *v15 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 8)) >= 0;
              --*(_DWORD *)&v12[8] )
        {
          if ( SHIDWORD(v11) >= *(int *)&v12[8] )
            break;
        }
        v19 = *v15;
        LODWORD(v7) = v7 + 1;
        *v15 = *i;
        *(_QWORD *)((char *)&v25[129] + *(_DWORD *)v12) = v11;
        *i = v19;
        *(_QWORD *)((char *)&v25[1] + *(_DWORD *)v12) = *(_QWORD *)v12;
        *(_QWORD *)(*(_DWORD *)v12 + v10) = *(_QWORD *)&v12[4];
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@HVidSort_ClassVariableInfoBySize@@@@UBAXPAHI@Z
// EA  : 0x82D635D0
// RVA : 0x00D635D0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<int,idSort_ClassVariableInfoBySize>::Sort(
        idSort_Quick<int,idSort_ClassVariableInfoBySize> *this,
        int *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r25
  int v8; // r29
  int v9; // r26 OVERLAPPED
  __int64 v10; // r28
  _BYTE v11[12]; // r7 OVERLAPPED
  __int128 v12; // r11
  int *v13; // r8
  int v14; // r31
  int *v15; // r11
  int v16; // r30
  int *v17; // r9
  int v18; // r31
  int v19; // r29
  int v20; // r31
  int v21; // r11
  int v22; // r30
  int v23; // r8
  __int64 v24; // [sp+10h] [-850h] BYREF
  char v25; // [sp+18h] [-848h] BYREF
  __int64 v26; // [sp+410h] [-450h]
  _BYTE v27[1096]; // [sp+418h] [-448h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v24 = v7;
    v26 = a7;
    do
    {
      v8 = 8 * v7;
      *(_QWORD *)(&v9 - 1) = *(&v24 + (unsigned int)v7);
      v10 = *(_QWORD *)(8 * v7 + v9);
      *(_DWORD *)&v11[4] = HIDWORD(v10);
      *(_DWORD *)v11 = *(_DWORD *)(8 * v7 + v9 + 4);
      if ( (int)v10 - HIDWORD(v10) < 4 || (int)v7 >= 127 )
      {
        if ( SHIDWORD(v10) < *(int *)v11 )
        {
          v19 = HIDWORD(v10) + 1;
          do
          {
            *(_DWORD *)&v11[8] = HIDWORD(v10);
            v20 = HIDWORD(v10) + 1;
            if ( v19 <= *(int *)v11 )
            {
              v21 = v19;
              v22 = *(_DWORD *)v11 - HIDWORD(v10);
              do
              {
                if ( *(_DWORD *)(40 * base[v21] + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16)
                   - *(_DWORD *)(40 * base[*(_DWORD *)&v11[8]] + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16) > 0 )
                  *(_DWORD *)&v11[8] = v20;
                ++v20;
                --v22;
                v21 = v20;
              }
              while ( v22 != 0 );
            }
            v23 = base[*(_DWORD *)&v11[8]];
            base[*(_DWORD *)&v11[8]] = base[*(_DWORD *)v11];
            base[(*(_DWORD *)v11)--] = v23;
          }
          while ( *(int *)v11 > SHIDWORD(v10) );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v12) = v10 + HIDWORD(v10);
        DWORD2(v12) = 4 * v10;
        v13 = &base[v10];
        LODWORD(v12) = ((unsigned __int64)v12 >> 63) + v10 + HIDWORD(v10);
        *(_DWORD *)&v11[8] = v10 - 1;
        *(_QWORD *)((char *)&v12 + 4) = (__int64)v12 >> 1;
        DWORD1(v12) = *v13;
        *v13 = base[DWORD2(v12)];
        base[DWORD2(v12)] = DWORD1(v12);
        while ( 1 )
        {
          v14 = 40 * *v13;
          if ( *(_DWORD *)(40 * base[*(_DWORD *)&v11[4]] + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16)
             - *(_DWORD *)(v14 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16) < 0 )
          {
            do
              ++*(_DWORD *)&v11[4];
            while ( *(int *)&v11[4] < *(int *)&v11[8]
                 && *(_DWORD *)(40 * base[*(_DWORD *)&v11[4]] + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16)
                  - *(_DWORD *)(40 * *v13 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16) < 0 );
          }
          v15 = &base[*(_DWORD *)&v11[8]];
          if ( *(_DWORD *)(40 * *v15 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16)
             - *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 20) + v14 + 16) > 0 )
            break;
LABEL_12:
          if ( *(int *)&v11[4] < *(int *)&v11[8] )
          {
            --*(_DWORD *)&v11[8];
            *(_DWORD *)v11 = base[*(_DWORD *)&v11[4]];
            base[(*(_DWORD *)&v11[4])++] = *v15;
            *v15 = *(_DWORD *)v11;
            if ( *(int *)&v11[4] < *(int *)&v11[8] )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --*(_DWORD *)&v11[8];
          if ( *(int *)&v11[8] <= *(int *)&v11[4] )
            break;
          v15 = &base[*(_DWORD *)&v11[8]];
          if ( *(_DWORD *)(40 * *v15 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16)
             - *(_DWORD *)(40 * *v13 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v16 = *v13;
        v17 = &base[*(_DWORD *)&v11[4]];
        v18 = 40 * *v13;
        if ( *(_DWORD *)(40 * *v17 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16)
           - *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 20) + v18 + 16) <= 0 )
        {
          do
          {
            if ( *(int *)&v11[4] >= (int)v10 )
              break;
            v17 = &base[++*(_DWORD *)&v11[4]];
          }
          while ( *(_DWORD *)(40 * *v17 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16)
                - *(_DWORD *)(40 * *v13 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16) <= 0 );
        }
        if ( *(_DWORD *)(40 * base[*(_DWORD *)&v11[8]] + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16)
           - *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 20) + v18 + 16) >= 0 )
        {
          do
          {
            if ( SHIDWORD(v10) >= *(int *)&v11[8] )
              break;
            --*(_DWORD *)&v11[8];
          }
          while ( *(_DWORD *)(40 * base[*(_DWORD *)&v11[8]] + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16)
                - *(_DWORD *)(40 * *v13 + *(_DWORD *)(*((_DWORD *)this + 1) + 20) + 16) >= 0 );
        }
        *(_DWORD *)v11 = &v25;
        LODWORD(v7) = v7 + 1;
        *v13 = *v17;
        *(_QWORD *)&v27[v8] = v10;
        *v17 = v16;
        *(_QWORD *)(v8 + *(_DWORD *)v11) = *(_QWORD *)v11;
        *(_QWORD *)(v8 + v9) = *(_QWORD *)&v11[4];
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ??$SwapValues@Uparty_t@@@@YAXAAUparty_t@@0@Z
// EA  : 0x82D9FF88
// RVA : 0x00D9FF88
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<party_t>(party_t *a, party_t *b)
{
  party_t v4; // [sp+50h] [-50h] BYREF

  v4.token = a->token;
  idStaticList<int,6>::idStaticList<int,6>(this: &v4.users, other: (const idList<idMD6Node *,5> *)&a->users);
  party_t::operator=(this: a, __that: b);
  party_t::operator=(this: b, __that: &v4);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v4.users);
}


// ========================================================================
// __unwind$490689_1
// EA  : 0x82D9FFDC
// RVA : 0x00D9FFDC
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_490689_1()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 160 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@Uparty_t@@VidSortPartyBySize@@@@UBAXPAUparty_t@@I@Z
// EA  : 0x82DA0850
// RVA : 0x00DA0850
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<party_t,idSortPartyBySize>::Sort(
        idSort_Quick<party_t,idSortPartyBySize> *this,
        party_t *base,
        unsigned int num,
        int a4,
        __int64 a5,
        int a6)
{
  __int64 v6; // r16
  unsigned __int64 v7; // r11 OVERLAPPED
  int v9; // r17
  int v10; // r22
  __int64 v11; // r19
  __int64 v12; // r21
  __int64 v13; // r24
  __int64 v14; // r26
  unsigned __int64 v15; // r10
  party_t *v16; // r30
  party_t *v17; // r28
  party_t *v18; // r29
  int v19; // r11
  party_t *v20; // r4
  int v21; // r8
  int v22; // r11
  int v23; // r7
  party_t *v24; // r29
  party_t *v25; // r26
  int v26; // [sp+50h] [-900h]
  int token; // [sp+60h] [-8F0h]
  idStaticList<int,6> v28; // [sp+64h] [-8ECh] BYREF
  int v29; // [sp+90h] [-8C0h]
  idStaticList<int,6> v30; // [sp+94h] [-8BCh] BYREF
  __int64 v31; // [sp+C0h] [-890h] BYREF
  _QWORD v32[273]; // [sp+C8h] [-888h] BYREF

  if ( num != 0 )
  {
    LODWORD(v6) = 0;
    HIDWORD(v7) = num - 1;
    v31 = v6;
    v9 = 0;
    v32[127] = *(unsigned __int64 *)((char *)&v7 + 4);
    HIDWORD(v7) = allocationCurrent[242];
    do
    {
      v10 = v9;
      v11 = v32[v9 - 1];
      v12 = *(_QWORD *)(8 * v9 + HIDWORD(v11));
      LODWORD(v13) = v32[v9 - 1];
      HIDWORD(v14) = *(_DWORD *)(8 * v9 + HIDWORD(v11) + 4);
      if ( (int)v12 - (int)v11 < 4 || v9 >= 127 )
      {
        for ( ; SHIDWORD(v14) > (int)v13; v28.num = 0 )
        {
          v21 = v13;
          v22 = v13 + 1;
          if ( (int)v13 + 1 <= SHIDWORD(v14) )
          {
            v23 = HIDWORD(v14) - v13;
            do
            {
              if ( base[v21].users.num - base[v22].users.num > 0 )
                v21 = v22;
              --v23;
              ++v22;
            }
            while ( v23 != 0 );
          }
          v24 = &base[v21];
          token = v24->token;
          v25 = &base[HIDWORD(v14)];
          idStaticList<int,6>::idStaticList<int,6>(this: &v28, other: (const idList<idMD6Node *,5> *)&v24->users);
          v24->token = v25->token;
          idList<idMaterial const *,59>::operator=(
            this: (idList<idMD6Node *,5> *)&v24->users,
            other: (const idList<idMD6Node *,5> *)&v25->users);
          v24->users.staticList[0] = v25->users.staticList[0];
          v24->users.staticList[1] = v25->users.staticList[1];
          v24->users.staticList[2] = v25->users.staticList[2];
          v24->users.staticList[3] = v25->users.staticList[3];
          v24->users.staticList[4] = v25->users.staticList[4];
          v24->users.staticList[5] = v25->users.staticList[5];
          v25->token = token;
          idList<idMaterial const *,59>::operator=(
            this: (idList<idMD6Node *,5> *)&v25->users,
            other: (const idList<idMD6Node *,5> *)&v28);
          HIDWORD(a5) = v28.staticList[0];
          qmemcpy(v25->users.staticList, v28.staticList, sizeof(v25->users.staticList));
          if ( v28.listStatic == 0 || v28.listStatic == 2 )
          {
            if ( v28.list != nullptr )
              idMem::Free(this: &mem, ptr: v28.list, align: ALIGN_16);
            v28.list = nullptr;
            v28.size = 0;
          }
          --HIDWORD(v14);
        }
        --v9;
      }
      else
      {
        LODWORD(v7) = v12 + v11;
        v15 = v7 >> 63;
        LODWORD(a5) = v15 + v12 + v11;
        v16 = &base[HIDWORD(v15)];
        HIDWORD(v12) = v16;
        SwapValues<party_t>(a: v16, b: &base[a5 >> 1]);
        LODWORD(v14) = v12 - 1;
        HIDWORD(v13) = &v16->users.num;
        while ( 1 )
        {
          v26 = *(_DWORD *)HIDWORD(v13);
          if ( *(_DWORD *)HIDWORD(v13) - base[v13].users.num < 0 )
          {
            do
              LODWORD(v13) = v13 + 1;
            while ( (int)v13 < (int)v14 && v26 - base[v13].users.num < 0 );
          }
          v17 = &base[v14];
          if ( v26 - v17->users.num > 0 )
            break;
LABEL_12:
          if ( (int)v13 < (int)v14 )
          {
            v18 = &base[v13];
            v29 = v18->token;
            HIDWORD(v14) = &v18->users;
            idStaticList<int,6>::idStaticList<int,6>(this: &v30, other: (const idList<idMD6Node *,5> *)&v18->users);
            v18->token = v17->token;
            idList<idMaterial const *,59>::operator=(
              this: (idList<idMD6Node *,5> *)&v18->users,
              other: (const idList<idMD6Node *,5> *)&v17->users);
            v18->users.staticList[0] = v17->users.staticList[0];
            v18->users.staticList[1] = v17->users.staticList[1];
            v18->users.staticList[2] = v17->users.staticList[2];
            v18->users.staticList[3] = v17->users.staticList[3];
            v18->users.staticList[4] = v17->users.staticList[4];
            v18->users.staticList[5] = v17->users.staticList[5];
            v17->token = v29;
            idList<idMaterial const *,59>::operator=(
              this: (idList<idMD6Node *,5> *)&v17->users,
              other: (const idList<idMD6Node *,5> *)&v30);
            qmemcpy(v17->users.staticList, v30.staticList, sizeof(v17->users.staticList));
            if ( v30.listStatic == 0 || v30.listStatic == 2 )
            {
              if ( v30.list != nullptr )
                idMem::Free(this: &mem, ptr: v30.list, align: ALIGN_16);
              v30.list = nullptr;
              v30.size = 0;
            }
            LODWORD(v13) = v13 + 1;
            v30.num = 0;
            LODWORD(v14) = v14 - 1;
            if ( (int)v13 < (int)v14 )
              continue;
          }
          goto LABEL_19;
        }
        while ( 1 )
        {
          LODWORD(v14) = v14 - 1;
          if ( (int)v14 <= (int)v13 )
            break;
          v17 = &base[v14];
          if ( *(_DWORD *)HIDWORD(v13) - v17->users.num <= 0 )
            goto LABEL_12;
        }
LABEL_19:
        v19 = *(_DWORD *)HIDWORD(v13);
        v20 = &base[v13];
        if ( *(_DWORD *)HIDWORD(v13) - v20->users.num <= 0 )
        {
          do
          {
            if ( (int)v13 >= (int)v12 )
              break;
            LODWORD(v13) = v13 + 1;
            v20 = &base[v13];
          }
          while ( v19 - v20->users.num <= 0 );
        }
        for ( ; v19 - base[v14].users.num >= 0; LODWORD(v14) = v14 - 1 )
        {
          if ( (int)v11 >= (int)v14 )
            break;
        }
        SwapValues<party_t>(a: v16, b: v20);
        HIDWORD(v7) = v32;
        ++v9;
        v32[v10 + 128] = v12;
        v32[v10] = v13;
        *(_QWORD *)(v10 * 8 + HIDWORD(v11)) = v14;
      }
    }
    while ( v9 >= 0 );
  }
}


// ========================================================================
// __unwind$491004
// EA  : 0x82DA0CAC
// RVA : 0x00DA0CAC
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_491004()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 2384 + 144));
}


// ========================================================================
// __unwind$491203_0
// EA  : 0x82DA0CD4
// RVA : 0x00DA0CD4
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_491203_0()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 2384 + 96));
}


// ========================================================================
// ?Sort@?$idSort_Quick@PBVidDeclSecretType@@V?$idSort_Quick_SortId@PBVidDeclSecretType@@@@@@UBAXPAPBVidDeclSecretType@@I@Z
// EA  : 0x82DA3D78
// RVA : 0x00DA3D78
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idDeclSecretType const *,idSort_Quick_SortId<idDeclSecretType const *>>::Sort(
        idSort_Quick<idDeclAccolade const *,idSort_DeclAccoladePtr> *this,
        const idDeclAccolade **base,
        unsigned int num,
        int a4,
        unsigned __int64 a5,
        __int64 a6)
{
  __int64 v6; // r28
  int v7; // r3
  int v8; // r31 OVERLAPPED
  __int64 v9; // r30 OVERLAPPED
  __int64 v10; // r11 OVERLAPPED
  __int128 v11; // r8
  const idDeclAccolade **v12; // r8
  int ordinal; // r7
  const idDeclAccolade **v14; // r9
  const idDeclAccolade *v15; // r5
  const idDeclAccolade *v16; // r5
  const idDeclAccolade **v17; // r9 OVERLAPPED
  int v18; // r6
  int v19; // r3
  int v20; // r6
  int v21; // r9
  int v22; // r8
  int v23; // r5
  int v24; // r9
  const idDeclAccolade *v25; // r6
  __int64 v26; // [sp+10h] [-830h] BYREF
  _BYTE v27[1016]; // [sp+18h] [-828h] BYREF
  __int64 v28; // [sp+410h] [-430h]
  _BYTE v29[1064]; // [sp+418h] [-428h] BYREF

  if ( num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v26 = v6;
    v28 = a6;
    do
    {
      v7 = 8 * v6;
      v9 = *(_QWORD *)&v27[8 * (_DWORD)v6 - 8];
      *(_QWORD *)&v8 = *(_QWORD *)(8 * v6 + HIDWORD(v9));
      LODWORD(v10) = v9;
      HIDWORD(v10) = *(_DWORD *)(8 * v6 + HIDWORD(v9) + 4);
      if ( v8 - (int)v9 < 4 || (int)v6 >= 127 )
      {
        if ( (int)v9 < SHIDWORD(v10) )
        {
          v19 = v9 + 1;
          do
          {
            v20 = v9;
            v21 = v9 + 1;
            if ( v19 <= SHIDWORD(v10) )
            {
              v22 = v19;
              v23 = HIDWORD(v10) - v9;
              do
              {
                if ( base[v22]->ordinal - base[v20]->ordinal > 0 )
                  v20 = v21;
                ++v21;
                --v23;
                v22 = v21;
              }
              while ( v23 != 0 );
            }
            v24 = v20;
            HIDWORD(a5) = base[HIDWORD(v10)];
            v25 = base[v20];
            base[v24] = (const idDeclAccolade *)HIDWORD(a5);
            base[HIDWORD(v10)--] = v25;
          }
          while ( SHIDWORD(v10) > (int)v9 );
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        LODWORD(a5) = v8 + v9;
        *(_QWORD *)((char *)&v11 + 4) = a5 >> 63;
        LODWORD(v11) = DWORD2(v11) + v8 + v9;
        --HIDWORD(v10);
        *(_QWORD *)((char *)&v11 + 4) = (__int64)v11 >> 1;
        v12 = &base[v8];
        DWORD2(v11) *= 4;
        DWORD1(v11) = *v12;
        *v12 = *(const idDeclAccolade **)((char *)base + DWORD2(v11));
        *(const idDeclAccolade **)((char *)base + DWORD2(v11)) = (const idDeclAccolade *)DWORD1(v11);
        while ( 1 )
        {
          ordinal = (*v12)->ordinal;
          if ( base[(_DWORD)v10]->ordinal - ordinal < 0 )
          {
            do
              LODWORD(v10) = v10 + 1;
            while ( (int)v10 < SHIDWORD(v10) && base[(_DWORD)v10]->ordinal - (*v12)->ordinal < 0 );
          }
          v14 = &base[HIDWORD(v10)];
          if ( (*v14)->ordinal - ordinal > 0 )
            break;
LABEL_12:
          if ( (int)v10 < SHIDWORD(v10) )
          {
            --HIDWORD(v10);
            v15 = base[(_DWORD)v10];
            base[(_DWORD)v10] = *v14;
            LODWORD(v10) = v10 + 1;
            *v14 = v15;
            if ( (int)v10 < SHIDWORD(v10) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v10);
          if ( SHIDWORD(v10) <= (int)v10 )
            break;
          v14 = &base[HIDWORD(v10)];
          if ( (*v14)->ordinal - (*v12)->ordinal <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v16 = *v12;
        v17 = &base[v10];
        v18 = (*v12)->ordinal;
        if ( (*v17)->ordinal - v18 <= 0 )
        {
          do
          {
            if ( (int)v10 >= v8 )
              break;
            LODWORD(v10) = v10 + 1;
            v17 = &base[v10];
          }
          while ( (*v17)->ordinal - (*v12)->ordinal <= 0 );
        }
        if ( base[HIDWORD(v10)]->ordinal - v18 >= 0 )
        {
          do
          {
            if ( (int)v9 >= SHIDWORD(v10) )
              break;
            --HIDWORD(v10);
          }
          while ( base[HIDWORD(v10)]->ordinal - (*v12)->ordinal >= 0 );
        }
        HIDWORD(a5) = *v17;
        LODWORD(v9) = v27;
        LODWORD(v6) = v6 + 1;
        *v12 = *v17;
        *(_QWORD *)&v29[v7] = *(_QWORD *)&v8;
        *v17 = v16;
        *(_QWORD *)&v27[v7] = v10;
        *(_QWORD *)(v7 + HIDWORD(v9)) = *(__int64 *)((char *)&v10 + 4);
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// ??$SwapValues@UlobbyPlayerInfo_t@@@@YAXAAUlobbyPlayerInfo_t@@0@Z
// EA  : 0x82DC0078
// RVA : 0x00DC0078
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<lobbyPlayerInfo_t>(lobbyPlayerInfo_t *a, lobbyPlayerInfo_t *b)
{
  lobbyPlayerInfo_t v4; // [sp+50h] [-60h] BYREF

  lobbyPlayerInfo_t::lobbyPlayerInfo_t(this: &v4, __that: a);
  lobbyPlayerInfo_t::operator=(this: a, __that: b);
  lobbyPlayerInfo_t::operator=(this: b, __that: &v4);
  idStr::FreeData(this: &v4.name);
}


// ========================================================================
// __unwind$504132
// EA  : 0x82DC00C4
// RVA : 0x00DC00C4
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_504132()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@UlobbyPlayerInfo_t@@VidSort_LobbyPlayerInfoRef_ByPartyAndName@@@@UBAXPAUlobbyPlayerInfo_t@@I@Z
// EA  : 0x82DC1878
// RVA : 0x00DC1878
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<lobbyPlayerInfo_t,idSort_LobbyPlayerInfoRef_ByPartyAndName>::Sort(
        idSort_Quick<lobbyPlayerInfo_t,idSort_LobbyPlayerInfoRef_ByPartyAndName> *this,
        lobbyPlayerInfo_t *base,
        unsigned int num,
        int a4,
        __int64 a5)
{
  __int64 v5; // r18
  __int64 v7; // r10
  unsigned __int64 v8; // r11
  int v9; // r17
  __int64 v10; // r20
  __int64 v11; // r27 OVERLAPPED
  __int64 v12; // r22
  unsigned __int64 v13; // r10
  lobbyPlayerInfo_t *v14; // r30
  lobbyPlayerInfo_t *v15; // r23
  bool *p_isPartyMember; // r25 OVERLAPPED
  lobbyPlayerInfo_t *v17; // r11
  lobbyPlayerInfo_t *v18; // r29
  lobbyPlayerInfo_t *v19; // r30
  int v20; // r11
  size_t v21; // r28
  int v22; // r4
  unsigned int v23; // r11
  size_t v24; // r30
  int v25; // r4
  int v26; // r11
  bool v27; // zf
  lobbyPlayerInfo_t *v28; // r30
  lobbyPlayerInfo_t *v29; // r11
  int v30; // r29
  int v31; // r30
  lobbyPlayerInfo_t *v32; // r11
  lobbyPlayerInfo_t *v33; // r10
  lobbyPlayerInfo_t *v34; // r30
  lobbyPlayerInfo_t *v35; // r29
  int len; // r28
  int v37; // r4
  char *v38; // r9
  char *v39; // r10
  char v40; // r11
  int allocedAndFlag; // r11
  size_t v42; // r28
  int v43; // r4
  unsigned int v44; // r11
  size_t v45; // r30
  int v46; // r4
  int v47; // r11
  idStr v48; // [sp+50h] [-920h] BYREF
  bool isMasterLocalUser; // [sp+70h] [-900h]
  bool isPartyMember; // [sp+71h] [-8FFh]
  int partyToken; // [sp+74h] [-8FCh]
  int sessionUserIndex; // [sp+78h] [-8F8h]
  int level; // [sp+7Ch] [-8F4h]
  qosState_t qosState; // [sp+80h] [-8F0h]
  voiceStateDisplay_t voiceState; // [sp+84h] [-8ECh]
  idStr v56; // [sp+90h] [-8E0h] BYREF
  bool v57; // [sp+B0h] [-8C0h]
  bool v58; // [sp+B1h] [-8BFh]
  int v59; // [sp+B4h] [-8BCh]
  int v60; // [sp+B8h] [-8B8h]
  int v61; // [sp+BCh] [-8B4h]
  qosState_t v62; // [sp+C0h] [-8B0h]
  voiceStateDisplay_t v63; // [sp+C4h] [-8ACh]
  __int64 v64; // [sp+D0h] [-8A0h] BYREF
  _QWORD v65[275]; // [sp+D8h] [-898h] BYREF

  if ( num != 0 )
  {
    LODWORD(v5) = 0;
    LODWORD(v7) = num - 1;
    HIDWORD(v7) = 0x82000000;
    v64 = v5;
    v65[127] = v7;
    HIDWORD(v8) = 0x82000000;
    v9 = 0;
    while ( 1 )
    {
      HIDWORD(v12) = 8 * v9;
      v10 = v65[v9 - 1];
      v11 = *(_QWORD *)(8 * v9 + HIDWORD(v10));
      LODWORD(v12) = v65[v9 - 1];
      if ( (int)v11 - (int)v10 >= 4 && v9 < 127 )
        break;
      if ( (int)v12 < (int)v11 )
      {
        while ( 1 )
        {
          v30 = v12;
          v31 = v12 + 1;
          if ( (int)v12 + 1 <= (int)v11 )
            break;
LABEL_47:
          v48.allocedAndFlag = 20;
          v48.baseBuffer[0] = 0;
          v48.data = v48.baseBuffer;
          v48.len = 0;
          v34 = &base[v30];
          v35 = &base[v11];
          len = v34->name.len;
          v37 = v34->name.len + 1;
          if ( v37 > 20 )
            idStr::ReAllocate(this: &v48, amount: v37, keepold: true);
          v38 = v48.data - 1;
          v39 = v34->name.data - 1;
          do
          {
            v40 = *++v39;
            *++v38 = *v39;
          }
          while ( v40 != 0 );
          v48.len = len;
          isMasterLocalUser = v34->isMasterLocalUser;
          isPartyMember = v34->isPartyMember;
          partyToken = v34->partyToken;
          sessionUserIndex = v34->sessionUserIndex;
          level = v34->level;
          qosState = v34->qosState;
          voiceState = v34->voiceState;
          allocedAndFlag = v34->name.allocedAndFlag;
          v42 = v35->name.len;
          v43 = v35->name.len + 1;
          if ( allocedAndFlag >= 0 )
          {
            if ( v43 > (allocedAndFlag & 0x7FFFFFFF) )
              idStr::ReAllocate(this: &v34->name, amount: v43, keepold: false);
          }
          else if ( v43 > (allocedAndFlag & 0x7FFFFFFF)
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: v34->name.data, Src: v35->name.data, Size: v42);
          v34->name.data[v42] = 0;
          v34->name.len = v42;
          v34->isMasterLocalUser = v35->isMasterLocalUser;
          v34->isPartyMember = v35->isPartyMember;
          v34->partyToken = v35->partyToken;
          v34->sessionUserIndex = v35->sessionUserIndex;
          v34->level = v35->level;
          v34->qosState = v35->qosState;
          v34->voiceState = v35->voiceState;
          v44 = v35->name.allocedAndFlag;
          v45 = v48.len;
          v46 = v48.len + 1;
          v27 = v44 >> 31 == 0;
          v47 = v44 & 0x7FFFFFFF;
          if ( v27 )
          {
            if ( v46 > v47 )
              idStr::ReAllocate(this: &base[v11].name, amount: v46, keepold: false);
          }
          else if ( v46 > v47
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: v35->name.data, Src: v48.data, Size: v45);
          v35->name.data[v45] = 0;
          v35->name.len = v45;
          v35->isMasterLocalUser = isMasterLocalUser;
          v35->isPartyMember = isPartyMember;
          v35->partyToken = partyToken;
          v35->sessionUserIndex = sessionUserIndex;
          v35->level = level;
          v35->qosState = qosState;
          v35->voiceState = voiceState;
          idStr::FreeData(this: &v48);
          LODWORD(v11) = v11 - 1;
          if ( (int)v11 <= (int)v12 )
            goto LABEL_66;
        }
        while ( 2 )
        {
          v32 = &base[v30];
          v33 = &base[v31];
          if ( v33->isPartyMember == v32->isPartyMember )
          {
            if ( idStr::Icmp(s1: v33->name.data, s2: v32->name.data) > 0 )
              goto LABEL_45;
          }
          else if ( v33->isPartyMember )
          {
LABEL_45:
            v30 = v31;
          }
          if ( ++v31 > (int)v11 )
            goto LABEL_47;
          continue;
        }
      }
LABEL_66:
      --v9;
LABEL_67:
      if ( v9 < 0 )
        return;
    }
    LODWORD(v8) = v11 + v10;
    v13 = v8 >> 63;
    LODWORD(a5) = v13 + v11 + v10;
    v14 = &base[HIDWORD(v13)];
    v15 = v14;
    SwapValues<lobbyPlayerInfo_t>(a: v14, b: &base[a5 >> 1]);
    HIDWORD(v11) = v11 - 1;
    p_isPartyMember = &v14->isPartyMember;
LABEL_6:
    while ( 2 )
    {
      v17 = &base[v12];
      if ( v17->isPartyMember == *p_isPartyMember )
      {
        if ( idStr::Icmp(s1: v17->name.data, s2: v15->name.data) >= 0 )
          goto LABEL_9;
      }
      else if ( v17->isPartyMember )
      {
        while ( 1 )
        {
LABEL_9:
          v18 = &base[HIDWORD(v11)];
          if ( v18->isPartyMember == *p_isPartyMember )
          {
            if ( idStr::Icmp(s1: v18->name.data, s2: v15->name.data) <= 0 )
              goto LABEL_16;
          }
          else if ( !v18->isPartyMember )
          {
LABEL_16:
            if ( (int)v12 < SHIDWORD(v11) )
            {
              v19 = &base[v12];
              idStr::idStr(this: &v56, text: &v19->name);
              v57 = v19->isMasterLocalUser;
              v58 = v19->isPartyMember;
              v59 = v19->partyToken;
              v60 = v19->sessionUserIndex;
              v61 = v19->level;
              v62 = v19->qosState;
              v63 = v19->voiceState;
              v20 = v19->name.allocedAndFlag;
              v21 = v18->name.len;
              v22 = v18->name.len + 1;
              if ( v20 >= 0 )
              {
                if ( v22 > (v20 & 0x7FFFFFFF) )
                  idStr::ReAllocate(this: &base[v12].name, amount: v22, keepold: false);
              }
              else if ( v22 > (v20 & 0x7FFFFFFF)
                     && AssertFailed(
                          file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                          line: 463,
                          expression: "amount <= GetAlloced()",
                          inlineBreak: true) )
              {
                __trap();
              }
              memcpy(Dst: v19->name.data, Src: v18->name.data, Size: v21);
              v19->name.data[v21] = 0;
              v19->name.len = v21;
              v19->isMasterLocalUser = v18->isMasterLocalUser;
              v19->isPartyMember = v18->isPartyMember;
              v19->partyToken = v18->partyToken;
              v19->sessionUserIndex = v18->sessionUserIndex;
              v19->level = v18->level;
              v19->qosState = v18->qosState;
              v19->voiceState = v18->voiceState;
              v23 = v18->name.allocedAndFlag;
              v24 = v56.len;
              v25 = v56.len + 1;
              v27 = v23 >> 31 == 0;
              v26 = v23 & 0x7FFFFFFF;
              if ( v27 )
              {
                if ( v25 > v26 )
                  idStr::ReAllocate(this: &base[HIDWORD(v11)].name, amount: v25, keepold: false);
              }
              else if ( v25 > v26
                     && AssertFailed(
                          file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                          line: 463,
                          expression: "amount <= GetAlloced()",
                          inlineBreak: true) )
              {
                __trap();
              }
              memcpy(Dst: v18->name.data, Src: v56.data, Size: v24);
              v18->name.data[v24] = 0;
              v18->name.len = v24;
              v18->isMasterLocalUser = v57;
              v18->isPartyMember = v58;
              v18->partyToken = v59;
              v18->sessionUserIndex = v60;
              v18->level = v61;
              v18->qosState = v62;
              v18->voiceState = v63;
              idStr::FreeData(this: &v56);
              LODWORD(v12) = v12 + 1;
              --HIDWORD(v11);
              if ( (int)v12 < SHIDWORD(v11) )
                goto LABEL_6;
            }
            while ( 1 )
            {
LABEL_30:
              v28 = &base[v12];
              if ( v28->isPartyMember == *p_isPartyMember )
              {
                if ( idStr::Icmp(s1: v28->name.data, s2: v15->name.data) > 0 )
                  goto LABEL_35;
              }
              else if ( v28->isPartyMember )
              {
                while ( 1 )
                {
LABEL_35:
                  v29 = &base[HIDWORD(v11)];
                  if ( v29->isPartyMember == *p_isPartyMember )
                  {
                    if ( idStr::Icmp(s1: v29->name.data, s2: v15->name.data) < 0 )
                      goto LABEL_40;
                  }
                  else if ( !v29->isPartyMember )
                  {
LABEL_40:
                    SwapValues<lobbyPlayerInfo_t>(a: v15, b: &base[v12]);
                    HIDWORD(v8) = v65;
                    ++v9;
                    *(_QWORD *)((char *)&v65[128] + HIDWORD(v12)) = v11;
                    *(_QWORD *)((char *)v65 + HIDWORD(v12)) = v12;
                    *(_QWORD *)(HIDWORD(v12) + HIDWORD(v10)) = *(__int64 *)((char *)&v11 + 4);
                    goto LABEL_67;
                  }
                  if ( (int)v10 >= SHIDWORD(v11) )
                    goto LABEL_40;
                  --HIDWORD(v11);
                }
              }
              if ( (int)v12 >= (int)v11 )
                goto LABEL_35;
              LODWORD(v12) = v12 + 1;
            }
          }
          --HIDWORD(v11);
          if ( SHIDWORD(v11) <= (int)v12 )
            goto LABEL_30;
        }
      }
      LODWORD(v12) = v12 + 1;
      if ( (int)v12 >= SHIDWORD(v11) )
        goto LABEL_9;
      continue;
    }
  }
}


// ========================================================================
// __unwind$505853
// EA  : 0x82DC1F08
// RVA : 0x00DC1F08
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_505853()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2416 + 144));
}


// ========================================================================
// __unwind$506151
// EA  : 0x82DC1F30
// RVA : 0x00DC1F30
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_506151()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2416 + 80));
}


// ========================================================================
// ??$SwapValues@V?$idPair@UserverInfo_t@@H@@@@YAXAAV?$idPair@UserverInfo_t@@H@@0@Z
// EA  : 0x82DC2270
// RVA : 0x00DC2270
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<idPair<serverInfo_t,int>>(idPair<serverInfo_t,int> *a, idPair<serverInfo_t,int> *b)
{
  idPair<serverInfo_t,int> v4; // [sp+50h] [-60h] BYREF

  idPair<serverInfo_t,int>::idPair<serverInfo_t,int>(this: &v4, __that: a);
  serverInfo_t::operator=(this: &a->first, __that: &b->first);
  a->second = b->second;
  serverInfo_t::operator=(this: &b->first, __that: &v4.first);
  b->second = v4.second;
  idStr::FreeData(this: &v4.first.name);
}


// ========================================================================
// __unwind$506613
// EA  : 0x82DC22CC
// RVA : 0x00DC22CC
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_506613()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ??$SwapValues@UmpMapMode_t@@@@YAXAAUmpMapMode_t@@0@Z
// EA  : 0x82DC2300
// RVA : 0x00DC2300
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<mpMapMode_t>(mpMapMode_t *a, mpMapMode_t *b)
{
  mpMapMode_t v4; // [sp+50h] [-C0h] BYREF

  mpMapMode_t::mpMapMode_t(this: &v4, __that: a);
  mpMapMode_t::operator=(this: a, __that: b);
  mpMapMode_t::operator=(this: b, __that: &v4);
  mpMapMode_t::~mpMapMode_t(this: &v4);
}


// ========================================================================
// __unwind$506654
// EA  : 0x82DC234C
// RVA : 0x00DC234C
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_506654()
{
  int v0; // r12

  mpMapMode_t::~mpMapMode_t(this: (mpMapMode_t *)(v0 - 272 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@V?$idPair@UserverInfo_t@@H@@VidSort_PlayerGamesList@@@@UBAXPAV?$idPair@UserverInfo_t@@H@@I@Z
// EA  : 0x82DCBBF0
// RVA : 0x00DCBBF0
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idPair<serverInfo_t,int>,idSort_PlayerGamesList>::Sort(
        idSort_Quick<idPair<serverInfo_t,int>,idSort_PlayerGamesList> *this,
        idPair<serverInfo_t,int> *base,
        unsigned int num)
{
  __int64 v3; // r18
  __int64 v5; // r10
  int v6; // r17
  __int64 v7; // r20
  __int64 v8; // r22
  unsigned __int64 v9; // r11
  idPair<serverInfo_t,int> *v10; // r24
  bool *p_joinable; // r23
  BOOL v12; // r9
  idPair<serverInfo_t,int> *v13; // r11
  idPair<serverInfo_t,int> *v14; // r29
  idPair<serverInfo_t,int> *v15; // r30
  int v16; // r11
  size_t v17; // r28
  int v18; // r4
  unsigned int v19; // r11
  size_t v20; // r30
  int v21; // r4
  int v22; // r11
  bool v23; // zf
  BOOL v24; // r9
  idPair<serverInfo_t,int> *v25; // r4
  idPair<serverInfo_t,int> *v26; // r11
  int v27; // r7
  int v28; // r8
  int v29; // r6
  idPair<serverInfo_t,int> *v30; // r11
  idPair<serverInfo_t,int> *v31; // r10
  idPair<serverInfo_t,int> *v32; // r30
  idPair<serverInfo_t,int> *v33; // r29
  int len; // r28
  int v35; // r4
  char *v36; // r9
  char *v37; // r10
  char v38; // r11
  int allocedAndFlag; // r11
  size_t v40; // r28
  int v41; // r4
  unsigned int v42; // r11
  size_t v43; // r30
  int v44; // r4
  int v45; // r11
  __int64 v46; // r27 OVERLAPPED
  idStr v47; // [sp+50h] [-920h] BYREF
  int map; // [sp+70h] [-900h]
  int type; // [sp+74h] [-8FCh]
  int mode; // [sp+78h] [-8F8h]
  bool joinable; // [sp+7Ch] [-8F4h]
  int numPlayers; // [sp+80h] [-8F0h]
  int maxPlayers; // [sp+84h] [-8ECh]
  int second; // [sp+88h] [-8E8h]
  idStr v55; // [sp+90h] [-8E0h] BYREF
  int v56; // [sp+B0h] [-8C0h]
  int v57; // [sp+B4h] [-8BCh]
  int v58; // [sp+B8h] [-8B8h]
  bool v59; // [sp+BCh] [-8B4h]
  int v60; // [sp+C0h] [-8B0h]
  int v61; // [sp+C4h] [-8ACh]
  int v62; // [sp+C8h] [-8A8h]
  _QWORD v63[276]; // [sp+D0h] [-8A0h] BYREF

  if ( num != 0 )
  {
    LODWORD(v3) = 0;
    LODWORD(v5) = num - 1;
    HIDWORD(v5) = 0x82000000;
    v63[0] = v3;
    v63[128] = v5;
    v6 = 0;
    while ( 1 )
    {
      HIDWORD(v8) = 8 * v6;
      v7 = v63[v6];
      v46 = *(_QWORD *)(8 * v6 + HIDWORD(v7));
      LODWORD(v8) = v63[v6];
      if ( (int)v46 - (int)v7 >= 4 && v6 < 127 )
        break;
      if ( (int)v8 < (int)v46 )
      {
        while ( 1 )
        {
          v27 = v8;
          v28 = v8 + 1;
          if ( (int)v8 + 1 <= (int)v46 )
            break;
LABEL_50:
          v47.allocedAndFlag = 20;
          v47.len = 0;
          v47.data = v47.baseBuffer;
          v47.baseBuffer[0] = 0;
          v32 = &base[v27];
          v33 = &base[v46];
          len = v32->first.name.len;
          v35 = v32->first.name.len + 1;
          if ( v35 > 20 )
            idStr::ReAllocate(this: &v47, amount: v35, keepold: true);
          v36 = v47.data - 1;
          v37 = v32->first.name.data - 1;
          do
          {
            v38 = *++v37;
            *++v36 = *v37;
          }
          while ( v38 != 0 );
          v47.len = len;
          map = v32->first.map;
          type = v32->first.type;
          mode = v32->first.mode;
          joinable = v32->first.joinable;
          numPlayers = v32->first.numPlayers;
          maxPlayers = v32->first.maxPlayers;
          second = v32->second;
          allocedAndFlag = v32->first.name.allocedAndFlag;
          v40 = v33->first.name.len;
          v41 = v33->first.name.len + 1;
          if ( allocedAndFlag >= 0 )
          {
            if ( v41 > (allocedAndFlag & 0x7FFFFFFF) )
              idStr::ReAllocate(this: &v32->first.name, amount: v41, keepold: false);
          }
          else if ( v41 > (allocedAndFlag & 0x7FFFFFFF)
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: v32->first.name.data, Src: v33->first.name.data, Size: v40);
          v32->first.name.data[v40] = 0;
          v32->first.name.len = v40;
          v32->first.map = v33->first.map;
          v32->first.type = v33->first.type;
          v32->first.mode = v33->first.mode;
          v32->first.joinable = v33->first.joinable;
          v32->first.numPlayers = v33->first.numPlayers;
          v32->first.maxPlayers = v33->first.maxPlayers;
          v32->second = v33->second;
          v42 = v33->first.name.allocedAndFlag;
          v43 = v47.len;
          v44 = v47.len + 1;
          v23 = v42 >> 31 == 0;
          v45 = v42 & 0x7FFFFFFF;
          if ( v23 )
          {
            if ( v44 > v45 )
              idStr::ReAllocate(this: &base[v46].first.name, amount: v44, keepold: false);
          }
          else if ( v44 > v45
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: v33->first.name.data, Src: v47.data, Size: v43);
          v33->first.name.data[v43] = 0;
          v33->first.name.len = v43;
          v33->first.map = map;
          v33->first.type = type;
          v33->first.mode = mode;
          v33->first.joinable = joinable;
          v33->first.numPlayers = numPlayers;
          v33->first.maxPlayers = maxPlayers;
          v33->second = second;
          idStr::FreeData(this: &v47);
          LODWORD(v46) = v46 - 1;
          if ( (int)v46 <= (int)v8 )
            goto LABEL_69;
        }
        v29 = v46 - v8;
        while ( 2 )
        {
          v30 = &base[v27];
          v31 = &base[v28];
          if ( v31->first.joinable == v30->first.joinable )
          {
            if ( v31->first.type - v30->first.type > 0 )
              goto LABEL_48;
          }
          else if ( v31->first.joinable )
          {
LABEL_48:
            v27 = v28;
          }
          --v29;
          ++v28;
          if ( v29 == 0 )
            goto LABEL_50;
          continue;
        }
      }
LABEL_69:
      --v6;
LABEL_70:
      if ( v6 < 0 )
        return;
    }
    LODWORD(v9) = v46 + v7;
    HIDWORD(v9) = v46;
    SwapValues<idPair<serverInfo_t,int>>(
      a: &base[v46],
      b: &base[(__int64)((unsigned int)(v9 >> 63) + (_DWORD)v46 + (_DWORD)v7) >> 1]);
    v10 = &base[v46];
    HIDWORD(v46) = v46 - 1;
    p_joinable = &v10->first.joinable;
LABEL_6:
    v12 = *p_joinable;
    while ( 1 )
    {
      v13 = &base[v8];
      if ( v13->first.joinable == v12 )
      {
        if ( v13->first.type - v10->first.type >= 0 )
          goto LABEL_10;
      }
      else if ( v13->first.joinable )
      {
        while ( 1 )
        {
LABEL_10:
          v14 = &base[HIDWORD(v46)];
          if ( v14->first.joinable == v12 )
          {
            if ( v14->first.type - v10->first.type <= 0 )
              goto LABEL_17;
          }
          else if ( !v14->first.joinable )
          {
LABEL_17:
            if ( (int)v8 >= SHIDWORD(v46) )
              goto LABEL_31;
            v15 = &base[v8];
            idStr::idStr(this: &v55, text: &v15->first.name);
            v56 = v15->first.map;
            v57 = v15->first.type;
            v58 = v15->first.mode;
            v59 = v15->first.joinable;
            v60 = v15->first.numPlayers;
            v61 = v15->first.maxPlayers;
            v62 = v15->second;
            v16 = v15->first.name.allocedAndFlag;
            v17 = v14->first.name.len;
            v18 = v14->first.name.len + 1;
            if ( v16 >= 0 )
            {
              if ( v18 > (v16 & 0x7FFFFFFF) )
                idStr::ReAllocate(this: &base[v8].first.name, amount: v18, keepold: false);
            }
            else if ( v18 > (v16 & 0x7FFFFFFF)
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: "amount <= GetAlloced()",
                        inlineBreak: true) )
            {
              __trap();
            }
            memcpy(Dst: v15->first.name.data, Src: v14->first.name.data, Size: v17);
            v15->first.name.data[v17] = 0;
            v15->first.name.len = v17;
            v15->first.map = v14->first.map;
            v15->first.type = v14->first.type;
            v15->first.mode = v14->first.mode;
            v15->first.joinable = v14->first.joinable;
            v15->first.numPlayers = v14->first.numPlayers;
            v15->first.maxPlayers = v14->first.maxPlayers;
            v15->second = v14->second;
            v19 = v14->first.name.allocedAndFlag;
            v20 = v55.len;
            v21 = v55.len + 1;
            v23 = v19 >> 31 == 0;
            v22 = v19 & 0x7FFFFFFF;
            if ( v23 )
            {
              if ( v21 > v22 )
                idStr::ReAllocate(this: &base[HIDWORD(v46)].first.name, amount: v21, keepold: false);
            }
            else if ( v21 > v22
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: "amount <= GetAlloced()",
                        inlineBreak: true) )
            {
              __trap();
            }
            memcpy(Dst: v14->first.name.data, Src: v55.data, Size: v20);
            v14->first.name.data[v20] = 0;
            v14->first.name.len = v20;
            v14->first.map = v56;
            v14->first.type = v57;
            v14->first.mode = v58;
            v14->first.joinable = v59;
            v14->first.numPlayers = v60;
            v14->first.maxPlayers = v61;
            v14->second = v62;
            idStr::FreeData(this: &v55);
            LODWORD(v8) = v8 + 1;
            --HIDWORD(v46);
            if ( (int)v8 >= SHIDWORD(v46) )
            {
LABEL_31:
              v24 = *p_joinable;
              while ( 1 )
              {
                v25 = &base[v8];
                if ( v25->first.joinable == v24 )
                {
                  if ( v25->first.type - v10->first.type > 0 )
                    goto LABEL_37;
                }
                else if ( v25->first.joinable )
                {
                  while ( 1 )
                  {
LABEL_37:
                    v26 = &base[HIDWORD(v46)];
                    if ( v26->first.joinable == v24 )
                    {
                      if ( v26->first.type - v10->first.type < 0 )
                        goto LABEL_42;
                    }
                    else if ( !v26->first.joinable )
                    {
LABEL_42:
                      SwapValues<idPair<serverInfo_t,int>>(a: v10, b: v25);
                      ++v6;
                      *(_QWORD *)((char *)&v63[129] + HIDWORD(v8)) = v46;
                      *(_QWORD *)((char *)&v63[1] + HIDWORD(v8)) = v8;
                      *(_QWORD *)(HIDWORD(v8) + HIDWORD(v7)) = *(__int64 *)((char *)&v46 + 4);
                      goto LABEL_70;
                    }
                    if ( (int)v7 >= SHIDWORD(v46) )
                      goto LABEL_42;
                    --HIDWORD(v46);
                  }
                }
                if ( (int)v8 >= (int)v46 )
                  goto LABEL_37;
                LODWORD(v8) = v8 + 1;
              }
            }
            goto LABEL_6;
          }
          --HIDWORD(v46);
          if ( SHIDWORD(v46) <= (int)v8 )
            goto LABEL_31;
        }
      }
      LODWORD(v8) = v8 + 1;
      if ( (int)v8 >= SHIDWORD(v46) )
        goto LABEL_10;
    }
  }
}


// ========================================================================
// __unwind$515180
// EA  : 0x82DCC280
// RVA : 0x00DCC280
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_515180()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2416 + 144));
}


// ========================================================================
// __unwind$515466
// EA  : 0x82DCC2A8
// RVA : 0x00DCC2A8
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_515466()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2416 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@UmpMapMode_t@@VidSort_Modes_ByMenuIndex@@@@UBAXPAUmpMapMode_t@@I@Z
// EA  : 0x82DCC2D8
// RVA : 0x00DCC2D8
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<mpMapMode_t,idSort_Modes_ByMenuIndex>::Sort(
        idSort_Quick<mpMapMode_t,idSort_Modes_ByMenuIndex> *this,
        mpMapMode_t *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r19
  __int64 v8; // r30
  int v9; // r24
  int v10; // r20 OVERLAPPED
  __int64 v11; // r22
  int v12; // r28
  int v13; // r11
  __int64 v14; // r11
  mpMapMode_t *v15; // r23
  __int64 v16; // r28
  int *v17; // r25
  int v18; // r11
  int v19; // r11
  mpMapMode_t *v20; // r4
  int v21; // r11
  int v22; // r10
  int v23; // r5
  mpMapMode_t *v24; // r27
  mpMapMode_t v25; // [sp+50h] [-910h] BYREF
  __int64 v26; // [sp+F0h] [-870h] BYREF
  _QWORD v27[269]; // [sp+F8h] [-868h] BYREF

  HIDWORD(v8) = base;
  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v26 = v7;
    v27[127] = a7;
    do
    {
      v9 = v7;
      *(_QWORD *)(&v10 - 1) = v27[(int)v7 - 1];
      v11 = *(_QWORD *)(8 * v7 + v10);
      LODWORD(v8) = HIDWORD(v11);
      v12 = *(_DWORD *)(8 * v7 + v10 + 4);
      if ( (int)v11 - HIDWORD(v11) < 4 || (int)v7 >= 127 )
      {
        for ( ; v12 > SHIDWORD(v11); --v12 )
        {
          v21 = HIDWORD(v11);
          v22 = HIDWORD(v11) + 1;
          if ( HIDWORD(v11) + 1 <= v12 )
          {
            v23 = v12 - HIDWORD(v11);
            do
            {
              if ( *(_DWORD *)(160 * v22 + HIDWORD(v8) + 72) - *(_DWORD *)(160 * v21 + HIDWORD(v8) + 72) > 0 )
                v21 = v22;
              --v23;
              ++v22;
            }
            while ( v23 != 0 );
          }
          v24 = (mpMapMode_t *)(160 * v21 + HIDWORD(v8));
          mpMapMode_t::mpMapMode_t(this: &v25, __that: v24);
          mpMapMode_t::operator=(this: v24, __that: (const mpMapMode_t *)(160 * v12 + HIDWORD(v8)));
          mpMapMode_t::operator=(this: (mpMapMode_t *)(160 * v12 + HIDWORD(v8)), __that: &v25);
          mpMapMode_t::~mpMapMode_t(this: &v25);
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        v13 = v11 + HIDWORD(v11);
        LODWORD(v14) = (*(unsigned __int64 *)((char *)&a7 - 4) >> 63) + v11 + HIDWORD(v11);
        HIDWORD(v14) = 5 * v11;
        v14 >>= 1;
        HIDWORD(v16) = 32 * HIDWORD(v14) + HIDWORD(v8);
        v15 = (mpMapMode_t *)HIDWORD(v16);
        SwapValues<mpMapMode_t>(a: (mpMapMode_t *)HIDWORD(v16), b: (mpMapMode_t *)(160 * v14 + HIDWORD(v8)));
        LODWORD(v16) = v12 - 1;
        v17 = (int *)(HIDWORD(v16) + 72);
        while ( 1 )
        {
          v18 = *v17;
          if ( *(_DWORD *)(160 * v8 + HIDWORD(v8) + 72) - *v17 < 0 )
          {
            do
              LODWORD(v8) = v8 + 1;
            while ( (int)v8 < (int)v16 && *(_DWORD *)(160 * v8 + HIDWORD(v8) + 72) - v18 < 0 );
          }
          HIDWORD(v16) = 160 * v16 + HIDWORD(v8);
          if ( *(_DWORD *)(HIDWORD(v16) + 72) - v18 > 0 )
            break;
LABEL_12:
          if ( (int)v8 < (int)v16 )
          {
            mpMapMode_t::mpMapMode_t(this: &v25, __that: (const mpMapMode_t *)(160 * v8 + HIDWORD(v8)));
            mpMapMode_t::operator=(
              this: (mpMapMode_t *)(160 * v8 + HIDWORD(v8)),
              __that: (const mpMapMode_t *)HIDWORD(v16));
            mpMapMode_t::operator=(this: (mpMapMode_t *)HIDWORD(v16), __that: &v25);
            mpMapMode_t::~mpMapMode_t(this: &v25);
            LODWORD(v8) = v8 + 1;
            LODWORD(v16) = v16 - 1;
            if ( (int)v8 < (int)v16 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v16) = v16 - 1;
          if ( (int)v16 <= (int)v8 )
            break;
          HIDWORD(v16) = 160 * v16 + HIDWORD(v8);
          if ( *(_DWORD *)(HIDWORD(v16) + 72) - v18 <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v19 = *v17;
        v20 = (mpMapMode_t *)(160 * v8 + HIDWORD(v8));
        if ( v20->menuIndex - *v17 <= 0 )
        {
          do
          {
            if ( (int)v8 >= (int)v11 )
              break;
            LODWORD(v8) = v8 + 1;
            v20 = (mpMapMode_t *)(160 * v8 + HIDWORD(v8));
          }
          while ( v20->menuIndex - v19 <= 0 );
        }
        for ( ; *(_DWORD *)(160 * v16 + HIDWORD(v8) + 72) - v19 >= 0; LODWORD(v16) = v16 - 1 )
        {
          if ( SHIDWORD(v11) >= (int)v16 )
            break;
        }
        SwapValues<mpMapMode_t>(a: v15, b: v20);
        LODWORD(a7) = v27;
        LODWORD(v7) = v7 + 1;
        v27[v9 + 128] = v11;
        v27[v9] = v8;
        *(_QWORD *)(v9 * 8 + v10) = v16;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// __unwind$515944
// EA  : 0x82DCC620
// RVA : 0x00DCC620
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_515944()
{
  int v0; // r12

  mpMapMode_t::~mpMapMode_t(this: (mpMapMode_t *)(v0 - 2400 + 80));
}


// ========================================================================
// __unwind$515960
// EA  : 0x82DCC648
// RVA : 0x00DCC648
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_515960()
{
  int v0; // r12

  mpMapMode_t::~mpMapMode_t(this: (mpMapMode_t *)(v0 - 2400 + 80));
}


// ========================================================================
// ??$SwapValues@UmpMap_t@@@@YAXAAUmpMap_t@@0@Z
// EA  : 0x82DD2C78
// RVA : 0x00DD2C78
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<mpMap_t>(mpMap_t *a, mpMap_t *b)
{
  mpMap_t v4; // [sp+50h] [-AC0h] BYREF

  mpMap_t::mpMap_t(this: &v4, __that: a);
  mpMap_t::operator=(this: a, __that: b);
  mpMap_t::operator=(this: b, __that: &v4);
  mpMap_t::~mpMap_t(this: &v4);
}


// ========================================================================
// __unwind$522263
// EA  : 0x82DD2CC4
// RVA : 0x00DD2CC4
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_522263()
{
  int v0; // r12

  mpMap_t::~mpMap_t(this: (mpMap_t *)(v0 - 2832 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@UmpMap_t@@VidSort_MpMapsRef_ByMenuIndex@@@@UBAXPAUmpMap_t@@I@Z
// EA  : 0x82DD3378
// RVA : 0x00DD3378
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<mpMap_t,idSort_MpMapsRef_ByMenuIndex>::Sort(
        idSort_Quick<mpMap_t,idSort_MpMapsRef_ByMenuIndex> *this,
        mpMap_t *base,
        unsigned int num,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // r19
  int v8; // r24
  __int64 v9; // r21
  __int64 v10; // r23
  __int64 v11; // r29 OVERLAPPED
  int v12; // r11
  unsigned __int64 v13; // r10
  mpMap_t *v14; // r27
  int *p_menuIndex; // r25
  int v16; // r11
  mpMap_t *v17; // r27 OVERLAPPED
  int v18; // r11
  mpMap_t *v19; // r4
  int v20; // r8
  int v21; // r11
  int v22; // r7
  mpMap_t *v23; // r27
  __int64 v24; // [sp+50h] [-1310h] BYREF
  _BYTE v25[2040]; // [sp+58h] [-1308h] BYREF
  mpMap_t v26; // [sp+850h] [-B10h] BYREF

  if ( num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v24 = v6;
    *(_QWORD *)&v25[1016] = a6;
    do
    {
      v8 = 8 * v6;
      v9 = *(_QWORD *)&v25[8 * (_DWORD)v6 - 8];
      v10 = *(_QWORD *)(8 * v6 + HIDWORD(v9));
      LODWORD(v11) = *(_DWORD *)&v25[8 * v6 - 4];
      HIDWORD(v11) = *(_DWORD *)(8 * v6 + HIDWORD(v9) + 4);
      if ( (int)v10 - (int)v9 < 4 || (int)v6 >= 127 )
      {
        for ( ; SHIDWORD(v11) > (int)v11; --HIDWORD(v11) )
        {
          v20 = v11;
          v21 = v11 + 1;
          if ( (int)v11 + 1 <= SHIDWORD(v11) )
          {
            v22 = HIDWORD(v11) - v11;
            do
            {
              if ( base[v21].menuIndex - base[v20].menuIndex > 0 )
                v20 = v21;
              --v22;
              ++v21;
            }
            while ( v22 != 0 );
          }
          v23 = &base[v20];
          mpMap_t::mpMap_t(this: &v26, __that: v23);
          mpMap_t::operator=(this: v23, __that: &base[HIDWORD(v11)]);
          mpMap_t::operator=(this: &base[HIDWORD(v11)], __that: &v26);
          mpMap_t::~mpMap_t(this: &v26);
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        v12 = v10 + v9;
        v13 = *(unsigned __int64 *)((char *)&a6 - 4) >> 63;
        LODWORD(a5) = v13 + v10 + v9;
        v14 = &base[HIDWORD(v13)];
        HIDWORD(v10) = v14;
        SwapValues<mpMap_t>(a: v14, b: &base[a5 >> 1]);
        --HIDWORD(v11);
        p_menuIndex = &v14->menuIndex;
        while ( 1 )
        {
          v16 = *p_menuIndex;
          if ( base[v11].menuIndex - *p_menuIndex < 0 )
          {
            do
              LODWORD(v11) = v11 + 1;
            while ( (int)v11 < SHIDWORD(v11) && base[v11].menuIndex - v16 < 0 );
          }
          v17 = &base[HIDWORD(v11)];
          if ( v17->menuIndex - v16 > 0 )
            break;
LABEL_12:
          if ( (int)v11 < SHIDWORD(v11) )
          {
            mpMap_t::mpMap_t(this: &v26, __that: &base[v11]);
            mpMap_t::operator=(this: &base[v11], __that: v17);
            mpMap_t::operator=(this: v17, __that: &v26);
            mpMap_t::~mpMap_t(this: &v26);
            LODWORD(v11) = v11 + 1;
            --HIDWORD(v11);
            if ( (int)v11 < SHIDWORD(v11) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v11);
          if ( SHIDWORD(v11) <= (int)v11 )
            break;
          v17 = &base[HIDWORD(v11)];
          if ( v17->menuIndex - v16 <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        v18 = *p_menuIndex;
        v19 = &base[v11];
        if ( v19->menuIndex - *p_menuIndex <= 0 )
        {
          do
          {
            if ( (int)v11 >= (int)v10 )
              break;
            LODWORD(v11) = v11 + 1;
            v19 = &base[v11];
          }
          while ( v19->menuIndex - v18 <= 0 );
        }
        for ( ; base[HIDWORD(v11)].menuIndex - v18 >= 0; --HIDWORD(v11) )
        {
          if ( (int)v9 >= SHIDWORD(v11) )
            break;
        }
        SwapValues<mpMap_t>(a: (mpMap_t *)HIDWORD(v10), b: v19);
        LODWORD(a6) = v25;
        LODWORD(v6) = v6 + 1;
        *(_QWORD *)&v25[v8 + 1024] = v10;
        *(_QWORD *)&v25[v8] = v11;
        *(_QWORD *)(v8 + HIDWORD(v9)) = *(__int64 *)((char *)&v11 + 4);
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// __unwind$522833
// EA  : 0x82DD364C
// RVA : 0x00DD364C
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_522833()
{
  int v0; // r12

  mpMap_t::~mpMap_t(this: (mpMap_t *)(v0 - 4960 + 2128));
}


// ========================================================================
// __unwind$522849
// EA  : 0x82DD3674
// RVA : 0x00DD3674
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_522849()
{
  int v0; // r12

  mpMap_t::~mpMap_t(this: (mpMap_t *)(v0 - 4960 + 2128));
}


// ========================================================================
// ?Sort@?$idSort_Quick@UidPlayerCoverScore_t@@VidSort_PlayerCoverScores@@@@UBAXPAUidPlayerCoverScore_t@@I@Z
// EA  : 0x82E2CB68
// RVA : 0x00E2CB68
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idPlayerCoverScore_t,idSort_PlayerCoverScores>::Sort(
        idSort_Quick<idPlayerCoverScore_t,idSort_PlayerCoverScores> *this,
        idPlayerCoverScore_t *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r29
  int v8; // r31 OVERLAPPED
  int v9; // r30 OVERLAPPED
  int v10; // r3 OVERLAPPED
  __int64 v11; // r10
  int v12; // r8
  idPlayerCoverScore_t *v13; // r11
  __int64 v14; // r8 OVERLAPPED
  __int64 v15; // r10 OVERLAPPED
  unsigned __int64 v16; // r6
  float standingScore; // r26
  idPlayerCoverScore_t *v18; // r11
  int v19; // r26
  int v20; // r25
  float v21; // r24
  float v22; // r23
  idPlayerCoverScore_t *i; // r11
  int v24; // r3
  int v25; // r6
  int v26; // r11
  int v27; // r5
  idPlayerCoverScore_t *v28; // r11
  __int64 v29; // [sp+10h] [-890h]
  __int64 v30; // [sp+18h] [-888h]
  int v31; // [sp+20h] [-880h]
  int v32; // [sp+24h] [-87Ch]
  float v33; // [sp+28h] [-878h]
  float v34; // [sp+2Ch] [-874h]
  int coverState; // [sp+44h] [-85Ch]
  float firePointScore; // [sp+4Ch] [-854h]
  _QWORD v37[266]; // [sp+50h] [-850h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v37[0] = v7;
    v37[128] = a7;
    do
    {
      *(_QWORD *)&v8 = v37[(_DWORD)v7];
      *(_QWORD *)&v10 = *(_QWORD *)(8 * v7 + v9);
      HIDWORD(v11) = v37[v7];
      v12 = *(_DWORD *)(8 * v7 + v9 + 4);
      if ( v10 - v8 < 4 || (int)v7 >= 127 )
      {
        if ( SHIDWORD(v11) < v12 )
        {
          v24 = HIDWORD(v11) + 1;
          do
          {
            v25 = HIDWORD(v11);
            v26 = HIDWORD(v11) + 1;
            if ( v24 <= v12 )
            {
              LODWORD(v11) = 16 * v24;
              v27 = v12 - HIDWORD(v11);
              do
              {
                if ( *(int *)((char *)&base->coverIndex + v11) - base[v25].coverIndex > 0 )
                  v25 = v26;
                ++v26;
                --v27;
                LODWORD(v11) = 16 * v26;
              }
              while ( v27 != 0 );
            }
            LODWORD(v11) = &base[v25];
            v28 = &base[v12--];
            v31 = *(_DWORD *)v11;
            v32 = *(_DWORD *)(v11 + 4);
            v33 = *(float *)(v11 + 8);
            v34 = *(float *)(v11 + 12);
            *(_DWORD *)v11 = v28->coverIndex;
            *(_DWORD *)(v11 + 4) = v28->coverState;
            *(float *)(v11 + 8) = v28->standingScore;
            *(float *)(v11 + 12) = v28->firePointScore;
            v28->coverIndex = v31;
            v28->coverState = v32;
            v28->standingScore = v33;
            v28->firePointScore = v34;
          }
          while ( v12 > SHIDWORD(v11) );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v11) = v10 + v8;
        v13 = &base[v10];
        v16 = (unsigned __int64)v11 >> 63;
        LODWORD(v11) = ((unsigned __int64)v11 >> 63) + v10 + v8;
        v15 = v11 >> 1;
        HIDWORD(v14) = v13;
        LODWORD(v14) = v12 - 1;
        LODWORD(v15) = &base[v15];
        coverState = v13->coverState;
        firePointScore = v13->firePointScore;
        standingScore = v13->standingScore;
        LODWORD(v16) = v13->coverIndex;
        v13->coverIndex = *(_DWORD *)v15;
        v13->coverState = *(_DWORD *)(v15 + 4);
        v13->standingScore = *(float *)(v15 + 8);
        v13->firePointScore = *(float *)(v15 + 12);
        *(_DWORD *)v15 = v16;
        *(_DWORD *)(v15 + 4) = coverState;
        *(float *)(v15 + 8) = standingScore;
        *(float *)(v15 + 12) = firePointScore;
        while ( 1 )
        {
          if ( base[HIDWORD(v15)].coverIndex - *(_DWORD *)HIDWORD(v14) < 0 )
          {
            do
              ++HIDWORD(v15);
            while ( SHIDWORD(v15) < (int)v14 && base[HIDWORD(v15)].coverIndex - *(_DWORD *)HIDWORD(v14) < 0 );
          }
          v18 = &base[v14];
          if ( v18->coverIndex - *(_DWORD *)HIDWORD(v14) > 0 )
            break;
LABEL_12:
          if ( SHIDWORD(v15) < (int)v14 )
          {
            LODWORD(v15) = &base[HIDWORD(v15)++];
            LODWORD(v14) = v14 - 1;
            v19 = *(_DWORD *)v15;
            v20 = *(_DWORD *)(v15 + 4);
            v21 = *(float *)(v15 + 8);
            v22 = *(float *)(v15 + 12);
            *(_DWORD *)v15 = v18->coverIndex;
            *(_DWORD *)(v15 + 4) = v18->coverState;
            *(float *)(v15 + 8) = v18->standingScore;
            *(float *)(v15 + 12) = v18->firePointScore;
            v18->coverIndex = v19;
            v18->coverState = v20;
            v18->standingScore = v21;
            v18->firePointScore = v22;
            if ( SHIDWORD(v15) < (int)v14 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v14) = v14 - 1;
          if ( (int)v14 <= SHIDWORD(v15) )
            break;
          v18 = &base[v14];
          if ( v18->coverIndex - *(_DWORD *)HIDWORD(v14) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( i = &base[HIDWORD(v15)]; i->coverIndex - *(_DWORD *)HIDWORD(v14) <= 0; i = &base[HIDWORD(v15)] )
        {
          if ( SHIDWORD(v15) >= v10 )
            break;
          ++HIDWORD(v15);
        }
        for ( ; base[v14].coverIndex - *(_DWORD *)HIDWORD(v14) >= 0; LODWORD(v14) = v14 - 1 )
        {
          if ( v8 >= (int)v14 )
            break;
        }
        LODWORD(v7) = v7 + 1;
        v29 = *(_QWORD *)HIDWORD(v14);
        v30 = *(_QWORD *)(HIDWORD(v14) + 8);
        *(_QWORD *)HIDWORD(v14) = *(_QWORD *)&i->coverIndex;
        *(float *)(HIDWORD(v14) + 8) = i->standingScore;
        *(_QWORD *)((char *)&v37[129] + HIDWORD(v16)) = *(_QWORD *)&v10;
        *(float *)(HIDWORD(v14) + 12) = i->firePointScore;
        *(_QWORD *)((char *)&v37[1] + HIDWORD(v16)) = *(__int64 *)((char *)&v15 + 4);
        *(_QWORD *)(HIDWORD(v16) + v9) = v14;
        *(_QWORD *)&i->coverIndex = v29;
        *(_QWORD *)&i->standingScore = v30;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ??$SwapValues@VidSpawnLocation@@@@YAXAAVidSpawnLocation@@0@Z
// EA  : 0x82EA6818
// RVA : 0x00EA6818
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<idSpawnLocation>(idSpawnLocation *a, idSpawnLocation *b)
{
  char *p_back_chain; // r10
  _DWORD *p_sortValue; // r11
  int i; // ctr
  idSpawnNode *v5; // r10
  int v6; // r9
  double v7; // fp7
  double v8; // fp6
  double v9; // fp5
  double v10; // fp4
  double v11; // fp2
  double v12; // fp1
  double v13; // fp0
  double v14; // fp13
  char back_chain; // [sp+0h] [-34h] BYREF
  float v16; // [sp+4h] [-30h]
  float v17; // [sp+8h] [-2Ch]
  float v18; // [sp+Ch] [-28h]
  float v19; // [sp+10h] [-24h]
  float v20; // [sp+14h] [-20h]
  float v21; // [sp+18h] [-1Ch]
  float v22; // [sp+1Ch] [-18h]
  idSpawnNode *v23; // [sp+20h] [-14h]
  int v24; // [sp+24h] [-10h]
  float v25; // [sp+28h] [-Ch]

  p_back_chain = &back_chain;
  p_sortValue = (_DWORD *)&a[-1].sortValue;
  for ( i = 10; i != 0; --i )
  {
    ++p_sortValue;
    p_back_chain += 4;
    *(_DWORD *)p_back_chain = *p_sortValue;
  }
  v5 = v23;
  a->pos.x = b->pos.x;
  v6 = v24;
  a->pos.y = b->pos.y;
  a->pos.z = b->pos.z;
  a->facing = b->facing;
  a->valueModifier = b->valueModifier;
  v7 = v16;
  a->sourceNode = b->sourceNode;
  v8 = v17;
  v9 = v18;
  a->locationID = b->locationID;
  v10 = v19;
  a->sortValue = b->sortValue;
  v11 = v20;
  v12 = v21;
  b->pos.x = v7;
  b->pos.y = v8;
  b->pos.z = v9;
  v13 = v22;
  v14 = v25;
  b->facing.pitch = v10;
  b->facing.yaw = v11;
  b->facing.roll = v12;
  b->sourceNode = v5;
  b->valueModifier = v13;
  b->locationID = v6;
  b->sortValue = v14;
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidSpawnLocation@@VidSort_LocationValue@@@@UBAXPAVidSpawnLocation@@I@Z
// EA  : 0x82EA6F90
// RVA : 0x00EA6F90
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idSpawnLocation,idSort_LocationValue>::Sort(
        idSort_Quick<idSpawnLocation,idSort_LocationValue> *this,
        idSpawnLocation *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r23
  int v9; // r28
  __int64 v10; // r25 OVERLAPPED
  __int64 v11; // r27 OVERLAPPED
  int v12; // r30
  int v13; // r11
  __int64 v14; // r11
  __int64 v15; // r30
  float *v16; // r6
  double v17; // fp13
  idSpawnLocation *v18; // r11
  float *v19; // r7
  idSpawnLocation *v20; // r10
  int v21; // ctr
  _DWORD *p_sortValue; // r9
  float v23; // r8
  float v24; // r7
  double v25; // fp7
  double v26; // fp6
  double v27; // fp5
  double v28; // fp4
  double v29; // fp2
  double v30; // fp1
  double v31; // fp0
  double v32; // fp13
  double v33; // fp13
  idSpawnLocation *v34; // r4
  double sortValue; // fp0
  int v36; // r3
  int v37; // r11
  int v38; // r9
  int v39; // r4
  idSpawnLocation *v40; // r10
  int v41; // r5
  char *v42; // r8
  int v43; // ctr
  idSpawnLocation *v44; // r11
  idSpawnNode *v45; // r8
  int v46; // r7
  double v47; // fp10
  double v48; // fp9
  double v49; // fp8
  double v50; // fp7
  double v51; // fp6
  double v52; // fp5
  double v53; // fp4
  double v54; // fp3
  char v55; // [sp+4Ch] [-8B4h] BYREF
  float v56; // [sp+50h] [-8B0h]
  float v57; // [sp+54h] [-8ACh]
  float v58; // [sp+58h] [-8A8h]
  float v59; // [sp+5Ch] [-8A4h]
  float v60; // [sp+60h] [-8A0h]
  float v61; // [sp+64h] [-89Ch]
  float v62; // [sp+68h] [-898h]
  idSpawnNode *v63; // [sp+6Ch] [-894h]
  int v64; // [sp+70h] [-890h]
  float v65; // [sp+74h] [-88Ch]
  float v66[13]; // [sp+7Ch] [-884h] BYREF
  __int64 v67; // [sp+B0h] [-850h] BYREF
  _BYTE v68[1016]; // [sp+B8h] [-848h] BYREF
  __int64 v69; // [sp+4B0h] [-450h]
  _BYTE v70[1096]; // [sp+4B8h] [-448h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v67 = v7;
    v69 = a7;
    do
    {
      v9 = 8 * v7;
      v10 = *(_QWORD *)&v68[8 * (_DWORD)v7 - 8];
      v11 = *(_QWORD *)(8 * v7 + HIDWORD(v10));
      HIDWORD(v11) = *(_DWORD *)&v68[8 * v7 - 4];
      v12 = *(_DWORD *)(8 * v7 + HIDWORD(v10) + 4);
      if ( (int)v11 - (int)v10 < 4 || (int)v7 >= 127 )
      {
        if ( SHIDWORD(v11) < v12 )
        {
          v36 = v12 - 3;
          do
          {
            v37 = HIDWORD(v11);
            v38 = HIDWORD(v11) + 1;
            if ( HIDWORD(v11) + 1 <= v12 )
            {
              if ( 4 - (HIDWORD(v11) + 1) + v36 >= 4 )
              {
                v39 = HIDWORD(v11) + 3;
                do
                {
                  v40 = &base[v38];
                  if ( v40->sortValue < (double)base[v37].sortValue )
                    v37 = v38;
                  if ( v40[1].sortValue < (double)base[v37].sortValue )
                    v37 = v39 - 1;
                  if ( base[v38 + 2].sortValue < (double)base[v37].sortValue )
                    v37 = v39;
                  if ( base[v38 + 3].sortValue < (double)base[v37].sortValue )
                    v37 = v39 + 1;
                  v38 += 4;
                  v39 += 4;
                }
                while ( v38 <= v36 );
              }
              if ( v38 <= v12 )
              {
                v41 = v12 - v38 + 1;
                do
                {
                  if ( base[v38].sortValue < (double)base[v37].sortValue )
                    v37 = v38;
                  --v41;
                  ++v38;
                }
                while ( v41 != 0 );
              }
            }
            LODWORD(a7) = &base[v37];
            v42 = &v55;
            v43 = 10;
            v44 = &base[v12];
            HIDWORD(a7) = a7 - 4;
            do
            {
              HIDWORD(a7) += 4;
              v42 += 4;
              *(_DWORD *)v42 = *(_DWORD *)HIDWORD(a7);
              --v43;
            }
            while ( v43 != 0 );
            v45 = v63;
            *(float *)a7 = v44->pos.x;
            v46 = v64;
            v47 = v56;
            --v12;
            v48 = v57;
            v49 = v58;
            --v36;
            v50 = v59;
            v51 = v60;
            v52 = v61;
            v53 = v62;
            v54 = v65;
            *(float *)(a7 + 4) = v44->pos.y;
            *(float *)(a7 + 8) = v44->pos.z;
            *(float *)(a7 + 12) = v44->facing.pitch;
            *(float *)(a7 + 16) = v44->facing.yaw;
            *(float *)(a7 + 20) = v44->facing.roll;
            *(float *)(a7 + 24) = v44->valueModifier;
            *(_DWORD *)(a7 + 28) = v44->sourceNode;
            *(_DWORD *)(a7 + 32) = v44->locationID;
            *(float *)(a7 + 36) = v44->sortValue;
            v44->pos.x = v47;
            v44->pos.y = v48;
            v44->pos.z = v49;
            v44->facing.pitch = v50;
            v44->facing.yaw = v51;
            v44->facing.roll = v52;
            v44->sourceNode = v45;
            v44->valueModifier = v53;
            v44->locationID = v46;
            v44->sortValue = v54;
          }
          while ( v12 > SHIDWORD(v11) );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        v13 = v11 + v10;
        LODWORD(v14) = (*(unsigned __int64 *)((char *)&a7 - 4) >> 63) + v11 + v10;
        HIDWORD(v14) = 5 * v11;
        HIDWORD(v15) = &base[v11];
        SwapValues<idSpawnLocation>(a: (idSpawnLocation *)HIDWORD(v15), b: &base[v14 >> 1]);
        LODWORD(v15) = v12 - 1;
        v16 = (float *)(HIDWORD(v15) + 36);
        do
        {
          v17 = *v16;
          do
          {
            if ( base[HIDWORD(v11)].sortValue <= v17 )
              break;
            ++HIDWORD(v11);
          }
          while ( SHIDWORD(v11) < (int)v15 );
          while ( 1 )
          {
            v18 = &base[v15];
            if ( v18->sortValue >= v17 )
              break;
            LODWORD(v15) = v15 - 1;
            if ( (int)v15 <= SHIDWORD(v11) )
              goto LABEL_16;
          }
          if ( SHIDWORD(v11) >= (int)v15 )
            break;
          v19 = v66;
          v20 = &base[HIDWORD(v11)];
          v21 = 10;
          p_sortValue = (_DWORD *)&v20[-1].sortValue;
          do
          {
            *++v19 = *(float *)++p_sortValue;
            --v21;
          }
          while ( v21 != 0 );
          v23 = v66[8];
          v20->pos.x = v18->pos.x;
          v24 = v66[9];
          ++HIDWORD(v11);
          v20->pos.y = v18->pos.y;
          LODWORD(v15) = v15 - 1;
          v20->pos.z = v18->pos.z;
          v20->facing.pitch = v18->facing.pitch;
          v20->facing.yaw = v18->facing.yaw;
          v20->facing.roll = v18->facing.roll;
          v20->valueModifier = v18->valueModifier;
          v25 = v66[1];
          v20->sourceNode = v18->sourceNode;
          v26 = v66[2];
          v27 = v66[3];
          v20->locationID = v18->locationID;
          v28 = v66[4];
          v20->sortValue = v18->sortValue;
          v29 = v66[5];
          v30 = v66[6];
          v18->pos.x = v25;
          v18->pos.y = v26;
          v18->pos.z = v27;
          v31 = v66[7];
          v32 = v66[10];
          v18->facing.pitch = v28;
          v18->facing.yaw = v29;
          v18->facing.roll = v30;
          *(float *)&v18->sourceNode = v23;
          v18->valueModifier = v31;
          *(float *)&v18->locationID = v24;
          v18->sortValue = v32;
        }
        while ( SHIDWORD(v11) < (int)v15 );
LABEL_16:
        v33 = *v16;
        while ( 1 )
        {
          v34 = &base[HIDWORD(v11)];
          if ( v34->sortValue < v33 || SHIDWORD(v11) >= (int)v11 )
            break;
          ++HIDWORD(v11);
        }
        while ( 1 )
        {
          sortValue = base[v15].sortValue;
          if ( sortValue >= v33 && sortValue > v33 )
            break;
          if ( (int)v10 >= (int)v15 )
            break;
          LODWORD(v15) = v15 - 1;
        }
        SwapValues<idSpawnLocation>(a: &base[v11], b: v34);
        LODWORD(a7) = v68;
        LODWORD(v7) = v7 + 1;
        *(_QWORD *)&v70[v9] = v11;
        *(_QWORD *)&v68[v9] = *(__int64 *)((char *)&v11 + 4);
        *(_QWORD *)(v9 + HIDWORD(v10)) = v15;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@PAUentityListType_t@@VidSort_EntityType@@@@UBAXPAPAUentityListType_t@@I@Z
// EA  : 0x82EFC6B8
// RVA : 0x00EFC6B8
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<entityListType_t *,idSort_EntityType>::Sort(
        idSort_Quick<entityListType_t *,idSort_EntityType> *this,
        entityListType_t **base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r22
  int v9; // r26
  int v10; // r23 OVERLAPPED
  __int64 v11; // r25
  __int64 v12; // r30 OVERLAPPED
  __int128 v13; // r11
  entityListType_t **v14; // r27
  entityListType_t **v15; // r28
  entityListType_t *v16; // r9
  entityListType_t **i; // r28 OVERLAPPED
  entityListType_t *v18; // r9
  int v19; // r26
  int v20; // r27
  int v21; // r28
  int v22; // r11
  entityListType_t *v23; // r8
  _QWORD v24[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v24[0] = v7;
    v24[128] = a7;
    do
    {
      v9 = v7;
      *(_QWORD *)(&v10 - 1) = v24[(_DWORD)v7];
      v11 = *(_QWORD *)(8 * v7 + v10);
      LODWORD(v12) = HIDWORD(v11);
      HIDWORD(v12) = *(_DWORD *)(8 * v7 + v10 + 4);
      if ( (int)v11 - HIDWORD(v11) < 4 || (int)v7 >= 127 )
      {
        if ( SHIDWORD(v11) < SHIDWORD(v12) )
        {
          v19 = HIDWORD(v11) + 1;
          do
          {
            v20 = HIDWORD(v11);
            v21 = HIDWORD(v11) + 1;
            if ( v19 <= SHIDWORD(v12) )
            {
              v22 = v19;
              do
              {
                if ( idStr::Icmp(s1: base[v22]->defName.data, s2: base[v20]->defName.data) > 0 )
                  v20 = v21;
                v22 = ++v21;
              }
              while ( v21 <= SHIDWORD(v12) );
            }
            v23 = base[v20];
            base[v20] = base[HIDWORD(v12)];
            base[HIDWORD(v12)--] = v23;
          }
          while ( SHIDWORD(v12) > SHIDWORD(v11) );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v13) = v11 + HIDWORD(v11);
        DWORD2(v13) = 4 * v11;
        v14 = &base[v11];
        LODWORD(v13) = ((unsigned __int64)v13 >> 63) + v11 + HIDWORD(v11);
        --HIDWORD(v12);
        *(_QWORD *)((char *)&v13 + 4) = (__int64)v13 >> 1;
        DWORD1(v13) = *v14;
        *v14 = base[DWORD2(v13)];
        base[DWORD2(v13)] = (entityListType_t *)DWORD1(v13);
        while ( 1 )
        {
          if ( idStr::Icmp(s1: base[(_DWORD)v12]->defName.data, s2: (*v14)->defName.data) < 0 )
          {
            do
              LODWORD(v12) = v12 + 1;
            while ( (int)v12 < SHIDWORD(v12)
                 && idStr::Icmp(s1: base[(_DWORD)v12]->defName.data, s2: (*v14)->defName.data) < 0 );
          }
          v15 = &base[HIDWORD(v12)];
          if ( idStr::Icmp(s1: (*v15)->defName.data, s2: (*v14)->defName.data) > 0 )
            break;
LABEL_12:
          if ( (int)v12 < SHIDWORD(v12) )
          {
            --HIDWORD(v12);
            v16 = base[(_DWORD)v12];
            base[(_DWORD)v12] = *v15;
            LODWORD(v12) = v12 + 1;
            *v15 = v16;
            if ( (int)v12 < SHIDWORD(v12) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v12);
          if ( SHIDWORD(v12) <= (int)v12 )
            break;
          v15 = &base[HIDWORD(v12)];
          if ( idStr::Icmp(s1: (*v15)->defName.data, s2: (*v14)->defName.data) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( i = &base[v12]; idStr::Icmp(s1: (*i)->defName.data, s2: (*v14)->defName.data) <= 0; i = &base[v12] )
        {
          if ( (int)v12 >= (int)v11 )
            break;
          LODWORD(v12) = v12 + 1;
        }
        for ( ; idStr::Icmp(s1: base[HIDWORD(v12)]->defName.data, s2: (*v14)->defName.data) >= 0; --HIDWORD(v12) )
        {
          if ( SHIDWORD(v11) >= SHIDWORD(v12) )
            break;
        }
        v18 = *v14;
        LODWORD(v7) = v7 + 1;
        *v14 = *i;
        v24[v9 + 129] = v11;
        *i = v18;
        v24[v9 + 1] = v12;
        *(_QWORD *)(v9 * 8 + v10) = *(__int64 *)((char *)&v12 + 4);
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@PBVidCVar@@VidSort_CVarPtr@@@@UBAXPAPBVidCVar@@I@Z
// EA  : 0x82EFEB40
// RVA : 0x00EFEB40
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idCVar const *,idSort_CVarPtr>::Sort(
        idSort_Quick<idCVar const *,idSort_CVarPtr> *this,
        const idCVar **base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r22
  int v9; // r26
  int v10; // r23 OVERLAPPED
  __int64 v11; // r25
  __int64 v12; // r30 OVERLAPPED
  __int128 v13; // r11
  const idCVar **v14; // r27
  const idCVar **v15; // r28
  const idCVar *v16; // r9
  const idCVar **i; // r28 OVERLAPPED
  const idCVar *v18; // r9
  int v19; // r26
  int v20; // r27
  int v21; // r28
  int v22; // r11
  const idCVar *v23; // r8
  _QWORD v24[268]; // [sp+50h] [-860h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v24[0] = v7;
    v24[128] = a7;
    do
    {
      v9 = v7;
      *(_QWORD *)(&v10 - 1) = v24[(_DWORD)v7];
      v11 = *(_QWORD *)(8 * v7 + v10);
      LODWORD(v12) = HIDWORD(v11);
      HIDWORD(v12) = *(_DWORD *)(8 * v7 + v10 + 4);
      if ( (int)v11 - HIDWORD(v11) < 4 || (int)v7 >= 127 )
      {
        if ( SHIDWORD(v11) < SHIDWORD(v12) )
        {
          v19 = HIDWORD(v11) + 1;
          do
          {
            v20 = HIDWORD(v11);
            v21 = HIDWORD(v11) + 1;
            if ( v19 <= SHIDWORD(v12) )
            {
              v22 = v19;
              do
              {
                if ( idStr::Icmp(s1: base[v22]->name, s2: base[v20]->name) > 0 )
                  v20 = v21;
                v22 = ++v21;
              }
              while ( v21 <= SHIDWORD(v12) );
            }
            v23 = base[v20];
            base[v20] = base[HIDWORD(v12)];
            base[HIDWORD(v12)--] = v23;
          }
          while ( SHIDWORD(v12) > SHIDWORD(v11) );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(v13) = v11 + HIDWORD(v11);
        DWORD2(v13) = 4 * v11;
        v14 = &base[v11];
        LODWORD(v13) = ((unsigned __int64)v13 >> 63) + v11 + HIDWORD(v11);
        --HIDWORD(v12);
        *(_QWORD *)((char *)&v13 + 4) = (__int64)v13 >> 1;
        DWORD1(v13) = *v14;
        *v14 = base[DWORD2(v13)];
        base[DWORD2(v13)] = (const idCVar *)DWORD1(v13);
        while ( 1 )
        {
          if ( idStr::Icmp(s1: base[(_DWORD)v12]->name, s2: (*v14)->name) < 0 )
          {
            do
              LODWORD(v12) = v12 + 1;
            while ( (int)v12 < SHIDWORD(v12) && idStr::Icmp(s1: base[(_DWORD)v12]->name, s2: (*v14)->name) < 0 );
          }
          v15 = &base[HIDWORD(v12)];
          if ( idStr::Icmp(s1: (*v15)->name, s2: (*v14)->name) > 0 )
            break;
LABEL_12:
          if ( (int)v12 < SHIDWORD(v12) )
          {
            --HIDWORD(v12);
            v16 = base[(_DWORD)v12];
            base[(_DWORD)v12] = *v15;
            LODWORD(v12) = v12 + 1;
            *v15 = v16;
            if ( (int)v12 < SHIDWORD(v12) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v12);
          if ( SHIDWORD(v12) <= (int)v12 )
            break;
          v15 = &base[HIDWORD(v12)];
          if ( idStr::Icmp(s1: (*v15)->name, s2: (*v14)->name) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( i = &base[v12]; idStr::Icmp(s1: (*i)->name, s2: (*v14)->name) <= 0; i = &base[v12] )
        {
          if ( (int)v12 >= (int)v11 )
            break;
          LODWORD(v12) = v12 + 1;
        }
        for ( ; idStr::Icmp(s1: base[HIDWORD(v12)]->name, s2: (*v14)->name) >= 0; --HIDWORD(v12) )
        {
          if ( SHIDWORD(v11) >= SHIDWORD(v12) )
            break;
        }
        v18 = *v14;
        LODWORD(v7) = v7 + 1;
        *v14 = *i;
        v24[v9 + 129] = v11;
        *i = v18;
        v24[v9 + 1] = v12;
        *(_QWORD *)(v9 * 8 + v10) = *(__int64 *)((char *)&v12 + 4);
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ??$SwapValues@VidKeyValue@@@@YAXAAVidKeyValue@@0@Z
// EA  : 0x82F01E00
// RVA : 0x00F01E00
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void __fastcall SwapValues<idKeyValue>(idTarget_Cvar::keyVal_t *a, idTarget_Cvar::keyVal_t *b)
{
  idXMLAttribute v4; // [sp+50h] [-60h] BYREF

  idStr::idStr(this: &v4.name, text: &a->key);
  idStr::idStr(this: &v4.value, text: &a->val);
  idXMLAttribute::operator=(this: a, __that: b);
  idXMLAttribute::operator=(this: b, __that: (const idTarget_Cvar::keyVal_t *)&v4);
  idKeyValue::~idKeyValue(this: &v4);
}


// ========================================================================
// __unwind$114057
// EA  : 0x82F01E58
// RVA : 0x00F01E58
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_114057()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$114055
// EA  : 0x82F01E80
// RVA : 0x00F01E80
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

void _unwind_114055()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 176 + 80));
}


// ========================================================================
// ?Sort@?$idSort_Quick@VidKeyValue@@VidSort_KeyValue@@@@UBAXPAVidKeyValue@@I@Z
// EA  : 0x82F021D8
// RVA : 0x00F021D8
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<idKeyValue,idSort_KeyValue>::Sort(
        idSort_Quick<idKeyValue,idSort_KeyValue> *this,
        idKeyValue *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r30 OVERLAPPED
  int v8; // r21
  int v9; // r26
  __int64 v10; // r25
  int v11; // r31 OVERLAPPED
  __int64 v12; // r11
  const char **v13; // r27
  idTarget_Cvar::keyVal_t *v14; // r28
  idTarget_Cvar::keyVal_t *j; // r28
  int v16; // r27
  int i; // r28
  _BYTE v18[1016]; // [sp+58h] [-858h] BYREF
  _QWORD v19[140]; // [sp+450h] [-460h] BYREF

  HIDWORD(v7) = base;
  if ( num != 0 )
  {
    v8 = 0;
    LODWORD(a7) = num - 1;
    v19[0] = a7;
    do
    {
      v9 = v8;
      v10 = v19[v8];
      v11 = HIDWORD(v10);
      LODWORD(v7) = v19[v8];
      if ( (int)v10 - HIDWORD(v10) < 4 || v8 >= 127 )
      {
        for ( ; (int)v7 > SHIDWORD(v10); LODWORD(v7) = v7 - 1 )
        {
          v16 = HIDWORD(v10);
          for ( i = HIDWORD(v10) + 1; i <= (int)v7; ++i )
          {
            if ( idStr::Icmp(
                   s1: *(const char **)((i << 6) + HIDWORD(v7) + 4),
                   s2: *(const char **)((v16 << 6) + HIDWORD(v7) + 4)) > 0 )
              v16 = i;
          }
          SwapValues<idKeyValue>(
            a: (idTarget_Cvar::keyVal_t *)((v16 << 6) + HIDWORD(v7)),
            b: (idTarget_Cvar::keyVal_t *)(((_DWORD)v7 << 6) + HIDWORD(v7)));
        }
        --v8;
      }
      else
      {
        LODWORD(v12) = v10 + HIDWORD(v10);
        HIDWORD(v12) = (_DWORD)v10 << 6;
        LODWORD(v12) = ((unsigned __int64)v12 >> 63) + v10 + HIDWORD(v10);
        SwapValues<idKeyValue>(
          a: (idTarget_Cvar::keyVal_t *)(((_DWORD)v10 << 6) + HIDWORD(v7)),
          b: (idTarget_Cvar::keyVal_t *)(((unsigned int)(v12 >> 1) << 6) + HIDWORD(v7)));
        LODWORD(v7) = v7 - 1;
        v13 = (const char **)(((_DWORD)v10 << 6) + HIDWORD(v7) + 4);
        while ( 1 )
        {
          if ( idStr::Icmp(s1: *(const char **)((v11 << 6) + HIDWORD(v7) + 4), s2: *v13) < 0 )
          {
            do
              ++v11;
            while ( v11 < (int)v7 && idStr::Icmp(s1: *(const char **)((v11 << 6) + HIDWORD(v7) + 4), s2: *v13) < 0 );
          }
          v14 = (idTarget_Cvar::keyVal_t *)(((_DWORD)v7 << 6) + HIDWORD(v7));
          if ( idStr::Icmp(s1: v14->key.data, s2: *v13) > 0 )
            break;
LABEL_12:
          if ( v11 < (int)v7 )
          {
            SwapValues<idKeyValue>(a: (idTarget_Cvar::keyVal_t *)((v11++ << 6) + HIDWORD(v7)), b: v14);
            LODWORD(v7) = v7 - 1;
            if ( v11 < (int)v7 )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          LODWORD(v7) = v7 - 1;
          if ( (int)v7 <= v11 )
            break;
          v14 = (idTarget_Cvar::keyVal_t *)(((_DWORD)v7 << 6) + HIDWORD(v7));
          if ( idStr::Icmp(s1: v14->key.data, s2: *v13) <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( j = (idTarget_Cvar::keyVal_t *)((v11 << 6) + HIDWORD(v7));
              idStr::Icmp(s1: j->key.data, s2: *v13) <= 0;
              j = (idTarget_Cvar::keyVal_t *)((++v11 << 6) + HIDWORD(v7)) )
        {
          if ( v11 >= (int)v10 )
            break;
        }
        for ( ; idStr::Icmp(s1: *(const char **)(((_DWORD)v7 << 6) + HIDWORD(v7) + 4), s2: *v13) >= 0; LODWORD(v7) = v7 - 1 )
        {
          if ( SHIDWORD(v10) >= (int)v7 )
            break;
        }
        SwapValues<idKeyValue>(a: (idTarget_Cvar::keyVal_t *)(((_DWORD)v10 << 6) + HIDWORD(v7)), b: j);
        ++v8;
        v19[v9 + 1] = v10;
        *(_QWORD *)&v18[v9 * 8] = *(__int64 *)((char *)&v7 - 4);
        v19[v9] = v7;
      }
    }
    while ( v8 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@_JVidSort_Int64@@@@UBAXPA_JI@Z
// EA  : 0x82F0A888
// RVA : 0x00F0A888
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<__int64,idSort_Int64>::Sort(
        idSort_Quick<__int64,idSort_Int64> *this,
        __int64 *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r29
  int v8; // r31 OVERLAPPED
  int v9; // r30 OVERLAPPED
  _BYTE v10[12]; // r9 OVERLAPPED
  int v11; // r11
  __int64 v12; // r9
  unsigned __int64 v13; // r11 OVERLAPPED
  __int64 *v14; // r3
  __int64 v15; // r6
  __int64 v16; // r6 OVERLAPPED
  int v17; // r10
  __int64 v18; // r28
  int v19; // r6
  int v20; // r5
  __int64 v21; // r11
  __int64 v22; // r10
  int v23; // r10
  int v24; // r11
  bool v25; // cr57
  __int64 v26; // r6
  _QWORD v27[262]; // [sp+10h] [-830h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v27[0] = v7;
    v27[128] = a7;
    do
    {
      *(_QWORD *)&v8 = v27[(_DWORD)v7];
      *(_QWORD *)v10 = *(_QWORD *)(8 * v7 + v9);
      *(_DWORD *)v10 = v27[v7];
      if ( *(_DWORD *)&v10[4] - v8 < 4 || (int)v7 >= 127 )
      {
        if ( *(int *)v10 < *(int *)&v10[4] )
        {
          do
          {
            v19 = *(_DWORD *)v10;
            if ( *(_DWORD *)v10 + 1 <= *(int *)&v10[4] )
            {
              v20 = *(_DWORD *)&v10[4] - *(_DWORD *)v10;
              do
              {
                v21 = base[v19];
                v22 = *(__int64 *)((char *)base + HIDWORD(v21));
                if ( (int)v22 > (int)v21 )
                  v19 = HIDWORD(v22);
                --v20;
              }
              while ( v20 != 0 );
            }
            v23 = *(_DWORD *)&v10[4];
            v24 = v19;
            v25 = *(_DWORD *)&v10[4] - 1 > *(_DWORD *)v10;
            *(_QWORD *)&v10[4] = base[*(_DWORD *)&v10[4]];
            v26 = base[v19];
            base[v24] = *(_QWORD *)&v10[4];
            base[v23] = v26;
          }
          while ( v25 );
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        v11 = *(_DWORD *)&v10[4] + v8;
        HIDWORD(v13) = 8 * *(_DWORD *)&v10[4];
        v12 = (unsigned int)(v13 >> 63) + *(_DWORD *)&v10[4] + v8;
        LODWORD(v13) = -1;
        v14 = (__int64 *)((char *)base + HIDWORD(v13));
        LODWORD(v12) = 8 * (v12 >> 1);
        v15 = *(__int64 *)((char *)base + HIDWORD(v13));
        *(__int64 *)((char *)base + HIDWORD(v13)) = *(__int64 *)((char *)base + v12);
        *(__int64 *)((char *)base + v12) = v15;
        do
        {
          v16 = *v14;
          do
          {
            if ( SLODWORD(base[*(_DWORD *)v10]) >= (int)v16 )
              break;
            ++*(_DWORD *)v10;
          }
          while ( *(int *)v10 < (int)v13 );
          while ( 1 )
          {
            *(_QWORD *)&v10[-4] = base[(_DWORD)v13];
            if ( v17 <= (int)v16 )
              break;
            LODWORD(v13) = v13 - 1;
            if ( (int)v13 <= *(int *)v10 )
              goto LABEL_14;
          }
          if ( *(int *)v10 >= (int)v13 )
            break;
          v16 = *(__int64 *)((char *)base + *(_DWORD *)&v10[8]);
          LODWORD(v13) = v13 - 1;
          v18 = base[*(_DWORD *)v10];
          base[(*(_DWORD *)v10)++] = v16;
          *(__int64 *)((char *)base + *(_DWORD *)&v10[8]) = v18;
        }
        while ( *(int *)v10 < (int)v13 );
LABEL_14:
        *(unsigned __int64 *)((char *)&v13 + 4) = *v14;
        while ( 1 )
        {
          LODWORD(v16) = 8 * *(_DWORD *)v10;
          *(_QWORD *)&v10[4] = base[*(_DWORD *)v10];
          if ( *(int *)&v10[8] >= SHIDWORD(v13) && *(int *)&v10[8] > SHIDWORD(v13) )
            break;
          if ( *(int *)v10 >= *(int *)&v10[4] )
            break;
          ++*(_DWORD *)v10;
        }
        while ( SLODWORD(base[v13]) >= SHIDWORD(v13) && v8 < (int)v13 )
          LODWORD(v13) = v13 - 1;
        *(_QWORD *)&v10[4] = *(__int64 *)((char *)base + v16);
        LODWORD(v7) = v7 + 1;
        *v14 = *(_QWORD *)&v10[4];
        *(_QWORD *)((char *)&v27[129] + HIDWORD(v16)) = *(_QWORD *)v10;
        *(__int64 *)((char *)base + v16) = *(_QWORD *)&v10[-4];
        *(_QWORD *)((char *)&v27[1] + HIDWORD(v16)) = *(_QWORD *)&v10[8];
        *(_QWORD *)(HIDWORD(v16) + v9) = v13;
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@UsortedEntry_t@@VidSort_Unique@@@@UBAXPAUsortedEntry_t@@I@Z
// EA  : 0x82F3DA08
// RVA : 0x00F3DA08
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<sortedEntry_t,idSort_Unique>::Sort(
        idSort_Quick<sortedEntry_t,idSort_Unique> *this,
        sortedEntry_t *base,
        unsigned __int64 num,
        int a4,
        int a5,
        __int64 a6)
{
  __int64 v6; // r28 OVERLAPPED
  unsigned int v7; // r3
  int v8; // r31 OVERLAPPED
  __int64 v9; // r30 OVERLAPPED
  __int64 v10; // r11 OVERLAPPED
  int v11; // r9
  sortedEntry_t *v12; // r8
  __int128 v13; // r6
  __int64 totalTicks; // r9
  _DWORD *v15; // r7
  __int64 v16; // r5 OVERLAPPED
  int v17; // r9
  _QWORD *v18; // r8
  __int128 v19; // r26
  int i; // r9 OVERLAPPED
  __int64 v21; // r8
  _BYTE *v22; // r26
  __int64 v23; // r8
  int v24; // r3
  int v25; // r6
  int v26; // r10
  int v27; // r8
  int v28; // r5
  sortedEntry_t *v29; // r8
  __int128 v30; // r31
  __int64 v31; // r5
  int v32; // r7
  __int64 v33; // [sp+10h] [-880h] BYREF
  __int64 v34; // [sp+18h] [-878h]
  __int64 v35; // [sp+20h] [-870h]
  __int64 v36; // [sp+28h] [-868h]
  __int128 v37; // [sp+30h] [-860h] BYREF
  __int64 v38; // [sp+40h] [-850h]
  __int64 v39; // [sp+48h] [-848h]
  _QWORD v40[129]; // [sp+50h] [-840h] BYREF
  _BYTE v41[1080]; // [sp+458h] [-438h] BYREF

  if ( HIDWORD(num) != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = HIDWORD(num) - 1;
    v40[0] = v6;
    v40[128] = a6;
    do
    {
      v7 = 8 * v6;
      v9 = v40[(_DWORD)v6];
      *(_QWORD *)&v8 = *(_QWORD *)(8 * v6 + HIDWORD(v9));
      LODWORD(v10) = v9;
      v11 = *(_DWORD *)(8 * v6 + HIDWORD(v9) + 4);
      if ( v8 - (int)v9 < 4 || (int)v6 >= 127 )
      {
        if ( (int)v9 < v11 )
        {
          v24 = v9 + 1;
          do
          {
            v25 = v10;
            v26 = v10 + 1;
            if ( v24 <= v11 )
            {
              v27 = v24;
              v28 = v11 - v10;
              do
              {
                if ( base[v27].label - base[v25].label > 0 )
                  v25 = v26;
                ++v26;
                --v28;
                v27 = v26;
              }
              while ( v28 != 0 );
            }
            v29 = &base[v25];
            HIDWORD(v10) = &base[v11--];
            *((_QWORD *)&v30 + 1) = *(_QWORD *)&v29->label;
            v31 = *(_QWORD *)HIDWORD(v10);
            *(_QWORD *)((char *)&v30 + 4) = v29->totalTicks;
            v35 = v30;
            *(_QWORD *)&v29->label = v31;
            v36 = *(_QWORD *)((char *)&v30 + 4);
            *(_QWORD *)(&base - 1) = *(_QWORD *)(HIDWORD(v10) + 8);
            v32 = DWORD2(v30);
            num = *(_QWORD *)DWORD1(v30);
            v29->totalTicks = *(unsigned __int64 *)((char *)&num + 4);
            *(_QWORD *)(HIDWORD(v10) + 8) = *(unsigned __int64 *)((char *)&num - 4);
            *(_QWORD *)HIDWORD(v10) = num;
          }
          while ( v11 > (int)v10 );
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        LODWORD(num) = v8 + v9;
        v12 = &base[v8];
        *(_QWORD *)((char *)&v13 + 4) = num >> 63;
        LODWORD(v13) = DWORD2(v13) + v8 + v9;
        totalTicks = v12->totalTicks;
        HIDWORD(v10) = v8 - 1;
        v15 = (_DWORD *)HIDWORD(totalTicks);
        v38 = *(_QWORD *)(16 * v8 + DWORD1(v13));
        v39 = totalTicks;
        LODWORD(totalTicks) = 16 * ((__int64)v13 >> 1);
        LODWORD(v13) = v38;
        v16 = v39;
        LODWORD(totalTicks) = totalTicks + HIDWORD(v39);
        *(_QWORD *)HIDWORD(totalTicks) = *(_QWORD *)totalTicks;
        *(_QWORD *)(HIDWORD(totalTicks) + 8) = *(_QWORD *)(totalTicks + 8);
        *(_QWORD *)totalTicks = *(__int64 *)((char *)&v16 - 4);
        *(_QWORD *)(totalTicks + 8) = v16;
        while ( 1 )
        {
          if ( *(_DWORD *)(16 * v10 + HIDWORD(v16)) - *v15 < 0 )
          {
            do
              LODWORD(v10) = v10 + 1;
            while ( (int)v10 < SHIDWORD(v10) && *(_DWORD *)(16 * v10 + HIDWORD(v16)) - *v15 < 0 );
          }
          v17 = 16 * HIDWORD(v10) + HIDWORD(v16);
          if ( *(_DWORD *)v17 - *v15 > 0 )
            break;
LABEL_12:
          if ( (int)v10 < SHIDWORD(v10) )
          {
            *(__int64 *)((char *)&v16 - 4) = *(_QWORD *)v17;
            LODWORD(v16) = &v37;
            v18 = (_QWORD *)(16 * v10 + HIDWORD(v16));
            LODWORD(v10) = v10 + 1;
            --HIDWORD(v10);
            *((_QWORD *)&v19 + 1) = *v18;
            *(_QWORD *)((char *)&v19 + 4) = v18[1];
            *v18 = *(__int64 *)((char *)&v16 - 4);
            *(__int64 *)((char *)&v16 - 4) = *(_QWORD *)(v17 + 8);
            v18[1] = *(__int64 *)((char *)&v16 - 4);
            *(_QWORD *)v16 = v19;
            *(_QWORD *)(v16 + 8) = *(_QWORD *)((char *)&v19 + 4);
            HIDWORD(v16) = DWORD2(v37);
            v15 = (_DWORD *)HIDWORD(v37);
            *(_OWORD *)v17 = v37;
            if ( (int)v10 < SHIDWORD(v10) )
              continue;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
          --HIDWORD(v10);
          if ( SHIDWORD(v10) <= (int)v10 )
            break;
          v17 = 16 * HIDWORD(v10) + HIDWORD(v16);
          if ( *(_DWORD *)v17 - *v15 <= 0 )
            goto LABEL_12;
        }
LABEL_14:
        for ( i = 16 * v10 + HIDWORD(v16); *(_DWORD *)i - *v15 <= 0; i = 16 * v10 + HIDWORD(v16) )
        {
          if ( (int)v10 >= v8 )
            break;
          LODWORD(v10) = v10 + 1;
        }
        for ( ; *(_DWORD *)(16 * HIDWORD(v10) + HIDWORD(v16)) - *v15 >= 0; --HIDWORD(v10) )
        {
          if ( (int)v9 >= SHIDWORD(v10) )
            break;
        }
        v21 = *(_QWORD *)v15;
        LODWORD(v9) = &v33;
        *(__int64 *)((char *)&v6 + 4) = *(_QWORD *)i;
        v22 = v41;
        LODWORD(v6) = v6 + 1;
        v34 = *(_QWORD *)(HIDWORD(v21) + 8);
        v33 = v21;
        LODWORD(num) = v21;
        v23 = v34;
        *(_QWORD *)HIDWORD(v34) = *(__int64 *)((char *)&v6 + 4);
        *(unsigned __int64 *)((char *)&num + 4) = *(_QWORD *)(i + 8);
        *(_QWORD *)(HIDWORD(v23) + 8) = *(unsigned __int64 *)((char *)&num + 4);
        *(_QWORD *)&v41[v7] = *(_QWORD *)&v8;
        v40[v7 / 8 + 1] = v10;
        *(_QWORD *)(v7 + HIDWORD(v9)) = *(__int64 *)((char *)&v10 + 4);
        *(_QWORD *)i = num;
        *(_QWORD *)(i + 8) = v23;
      }
    }
    while ( (int)v6 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@HVidSort_EntryDepthAndTicks@@@@UBAXPAHI@Z
// EA  : 0x82F3DD08
// RVA : 0x00F3DD08
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<int,idSort_EntryDepthAndTicks>::Sort(
        idSort_Quick<int,idSort_EntryDepthAndTicks> *this,
        int *base,
        unsigned int num,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  __int64 v7; // r26
  int v8; // r31
  __int64 v9; // r28
  _BYTE v10[12]; // r6 OVERLAPPED
  __int64 v11; // r30
  __int128 v12; // r10
  __int64 v13; // r8
  int v14; // r9 OVERLAPPED
  __int64 v15; // r11 OVERLAPPED
  int v16; // r8
  int v17; // r9
  int v18; // r8
  int v19; // r7
  int v20; // r9 OVERLAPPED
  __int64 v21; // r11 OVERLAPPED
  int v22; // r7
  int v23; // r31
  int v24; // r11
  int v25; // r10
  int v26; // r9
  int v27; // r8
  int v28; // r11
  __int64 v29; // r10 OVERLAPPED
  int v30; // r11
  int v31; // r8
  __int64 v32; // [sp+10h] [-850h] BYREF
  _BYTE v33[1016]; // [sp+18h] [-848h] BYREF
  unsigned __int64 v34; // [sp+410h] [-450h]
  _BYTE v35[1096]; // [sp+418h] [-448h] BYREF

  if ( num != 0 )
  {
    LODWORD(v7) = 0;
    LODWORD(a7) = num - 1;
    v32 = v7;
    v34 = a7;
    do
    {
      v8 = 8 * v7;
      v9 = *(_QWORD *)&v33[8 * (_DWORD)v7 - 8];
      *(_QWORD *)v10 = *(_QWORD *)(8 * v7 + HIDWORD(v9));
      LODWORD(v11) = *(_DWORD *)&v33[8 * v7 - 4];
      if ( *(_DWORD *)&v10[4] - (int)v9 < 4 || (int)v7 >= 127 )
      {
        for ( ; *(int *)&v10[4] > (int)v11; --*(_DWORD *)&v10[4] )
        {
          *(_DWORD *)&v10[8] = v11;
          v22 = v11 + 1;
          if ( (int)v11 + 1 <= *(int *)&v10[4] )
          {
            v23 = *(_DWORD *)&v10[4] - v11;
            do
            {
              v24 = *(_DWORD *)(4 * *(_DWORD *)&v10[8] + *(_DWORD *)v10);
              v25 = *(_DWORD *)(4 * v22 + *(_DWORD *)v10);
              v26 = 4 * v24;
              if ( *(_DWORD *)(*((_DWORD *)this + 1) + 4 * v25) == *(_DWORD *)(4 * v24 + *((_DWORD *)this + 1)) )
              {
                v27 = 8 * v24;
                v28 = 8 * v25;
                v29 = *(_QWORD *)(v27 + *((_DWORD *)this + 2));
                *(__int64 *)((char *)&v29 + 4) = *(_QWORD *)(v28 + HIDWORD(v29));
              }
              else
              {
                v30 = *((_DWORD *)this + 1);
                LODWORD(v29) = *(_DWORD *)(v30 + 4 * v25);
                HIDWORD(v29) = *(_DWORD *)(v26 + v30);
              }
              if ( (int)v29 - HIDWORD(v29) > 0 )
                *(_DWORD *)&v10[8] = v22;
              --v23;
              ++v22;
            }
            while ( v23 != 0 );
          }
          HIDWORD(a7) = *(_DWORD *)(4 * *(_DWORD *)&v10[4] + *(_DWORD *)v10);
          v31 = *(_DWORD *)(4 * *(_DWORD *)&v10[8] + *(_DWORD *)v10);
          *(_DWORD *)(4 * *(_DWORD *)&v10[8] + *(_DWORD *)v10) = HIDWORD(a7);
          *(_DWORD *)(4 * *(_DWORD *)&v10[4] + *(_DWORD *)v10) = v31;
        }
        LODWORD(v7) = v7 - 1;
      }
      else
      {
        LODWORD(a7) = *(_DWORD *)&v10[4] + v9;
        *(_QWORD *)((char *)&v12 + 4) = a7 >> 63;
        LODWORD(v12) = DWORD2(v12) + *(_DWORD *)&v10[4] + v9;
        *(_DWORD *)&v10[8] = *(_DWORD *)&v10[4] - 1;
        *(_QWORD *)((char *)&v12 + 4) = (__int64)v12 >> 1;
        HIDWORD(v11) = 4 * *(_DWORD *)&v10[4] + *(_DWORD *)v10;
        DWORD1(v12) = *(_DWORD *)HIDWORD(v11);
        *(_DWORD *)HIDWORD(v11) = *(_DWORD *)(4 * DWORD2(v12) + *(_DWORD *)v10);
        *(_DWORD *)(4 * DWORD2(v12) + *(_DWORD *)v10) = DWORD1(v12);
        do
        {
          HIDWORD(v13) = *(_DWORD *)HIDWORD(v11);
          do
          {
            v14 = 4 * HIDWORD(v13);
            LODWORD(v15) = *(_DWORD *)(4 * v11 + *(_DWORD *)v10);
            if ( *(_DWORD *)(4 * v15 + *((_DWORD *)this + 1)) == *(_DWORD *)(4 * HIDWORD(v13) + *((_DWORD *)this + 1)) )
            {
              HIDWORD(v15) = *(this + 2);
              LODWORD(v13) = 8 * v15;
              LODWORD(v15) = 8 * HIDWORD(v13);
              v13 = *(_QWORD *)(v13 + HIDWORD(v15));
              LODWORD(v15) = *(_DWORD *)(v15 + HIDWORD(v15) + 4) - v13;
            }
            else
            {
              LODWORD(v15) = *(_DWORD *)(4 * v15 + *((_DWORD *)this + 1))
                           - *(_DWORD *)(*((_DWORD *)this + 1) + 4 * HIDWORD(v13));
            }
            if ( (int)v15 >= 0 )
              break;
            LODWORD(v11) = v11 + 1;
          }
          while ( (int)v11 < *(int *)&v10[8] );
          while ( 1 )
          {
            v16 = 4 * *(_DWORD *)&v10[8];
            LODWORD(v15) = *(_DWORD *)(4 * *(_DWORD *)&v10[8] + *(_DWORD *)v10);
            HIDWORD(v15) = 4 * v15;
            if ( *(_DWORD *)(4 * v15 + *((_DWORD *)this + 1)) == *(_DWORD *)(*((_DWORD *)this + 1) + v14) )
            {
              v15 = *(_QWORD *)(8 * v15 + *((_DWORD *)this + 2));
              *(__int64 *)((char *)&v15 + 4) = *(_QWORD *)(8 * HIDWORD(v13) + HIDWORD(v15));
            }
            else
            {
              LODWORD(v15) = *(this + 1);
              HIDWORD(v15) = *(_DWORD *)(HIDWORD(v15) + v15);
              LODWORD(v15) = *(_DWORD *)(v15 + v14);
            }
            if ( HIDWORD(v15) - (int)v15 <= 0 )
              break;
            --*(_DWORD *)&v10[8];
            if ( *(int *)&v10[8] <= (int)v11 )
              goto LABEL_20;
          }
          if ( (int)v11 >= *(int *)&v10[8] )
            break;
          --*(_DWORD *)&v10[8];
          v17 = *(_DWORD *)(4 * v11 + *(_DWORD *)v10);
          *(_DWORD *)(4 * v11 + *(_DWORD *)v10) = *(_DWORD *)(v16 + *(_DWORD *)v10);
          LODWORD(v11) = v11 + 1;
          *(_DWORD *)(v16 + *(_DWORD *)v10) = v17;
        }
        while ( (int)v11 < *(int *)&v10[8] );
LABEL_20:
        v18 = *(_DWORD *)HIDWORD(v11);
        while ( 1 )
        {
          v19 = 4 * v11;
          v20 = 4 * v18;
          LODWORD(v21) = *(_DWORD *)(4 * v11 + *(_DWORD *)v10);
          HIDWORD(v21) = 4 * v21;
          if ( *(_DWORD *)(4 * v21 + *((_DWORD *)this + 1)) == *(_DWORD *)(*((_DWORD *)this + 1) + 4 * v18) )
          {
            v21 = *(_QWORD *)(8 * v21 + *((_DWORD *)this + 2));
            *(__int64 *)((char *)&v21 + 4) = *(_QWORD *)(8 * v18 + HIDWORD(v21));
          }
          else
          {
            LODWORD(v21) = *(this + 1);
            HIDWORD(v21) = *(_DWORD *)(HIDWORD(v21) + v21);
            LODWORD(v21) = *(_DWORD *)(v21 + 4 * v18);
          }
          if ( HIDWORD(v21) - (int)v21 > 0 || (int)v11 >= *(int *)&v10[4] )
            break;
          LODWORD(v11) = v11 + 1;
        }
        while ( 1 )
        {
          LODWORD(v21) = *(_DWORD *)(4 * *(_DWORD *)&v10[8] + *(_DWORD *)v10);
          HIDWORD(v21) = 4 * v21;
          if ( *(_DWORD *)(4 * v21 + *((_DWORD *)this + 1)) == *(_DWORD *)(*((_DWORD *)this + 1) + v20) )
          {
            v21 = *(_QWORD *)(8 * v21 + *((_DWORD *)this + 2));
            *(__int64 *)((char *)&v21 + 4) = *(_QWORD *)(8 * v18 + HIDWORD(v21));
          }
          else
          {
            LODWORD(v21) = *(this + 1);
            HIDWORD(v21) = *(_DWORD *)(HIDWORD(v21) + v21);
            LODWORD(v21) = *(_DWORD *)(v21 + v20);
          }
          if ( HIDWORD(v21) - (int)v21 < 0 || (int)v9 >= *(int *)&v10[8] )
            break;
          --*(_DWORD *)&v10[8];
        }
        HIDWORD(a7) = v33;
        LODWORD(v7) = v7 + 1;
        *(_DWORD *)HIDWORD(v11) = *(_DWORD *)(v19 + *(_DWORD *)v10);
        *(_QWORD *)&v35[v8] = *(_QWORD *)v10;
        *(_DWORD *)(v19 + *(_DWORD *)v10) = v18;
        *(_QWORD *)&v33[v8] = v11;
        *(_QWORD *)(v8 + HIDWORD(v9)) = *(_QWORD *)&v10[4];
      }
    }
    while ( (int)v7 >= 0 );
  }
}


// ========================================================================
// ?Sort@?$idSort_Quick@HVidSortrects@@@@UBAXPAHI@Z
// EA  : 0x82F79998
// RVA : 0x00F79998
// PDB : w:\tech5\shared\idlib\containers\sort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSort_Quick<int,idSortrects>::Sort(
        idSort_Quick<int,idSortrects> *this,
        __int64 num,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  __int64 v6; // r23
  unsigned int v7; // r27
  int v8; // r24 OVERLAPPED
  __int64 v9; // r26
  int v10; // r31 OVERLAPPED
  int v11; // r30
  __int64 v12; // r11
  __int64 v13; // r10
  __int64 v14; // r8
  _DWORD *v15; // r11
  int v16; // r30
  __int64 v17; // r6
  __int64 v18; // r5 OVERLAPPED
  int v19; // r10
  int v20; // r6
  int v21; // r7
  int v22; // r6
  int *v23; // r11
  int v24; // r28
  int v25; // r29
  __int64 v26; // r7
  int v27; // r30 OVERLAPPED
  int v28; // r5
  int v29; // r6
  int v30; // r6
  int v31; // r11
  int v32; // r29
  __int128 v33; // r9
  int v34; // r8
  __int64 v35; // [sp+10h] [-870h]
  __int64 v36; // [sp+18h] [-868h]
  int v37; // [sp+1Ch] [-864h]
  _QWORD v38[129]; // [sp+20h] [-860h] BYREF
  _BYTE v39[1112]; // [sp+428h] [-458h] BYREF

  if ( (_DWORD)num != 0 )
  {
    LODWORD(v6) = 0;
    LODWORD(a6) = num - 1;
    v38[0] = v6;
    v38[128] = a6;
    do
    {
      v7 = 8 * v6;
      *(_QWORD *)(&v8 - 1) = v38[(_DWORD)v6];
      v9 = *(_QWORD *)(8 * v6 + v8);
      v10 = HIDWORD(v9);
      v11 = *(_DWORD *)(8 * v6 + v8 + 4);
      if ( (int)v9 - HIDWORD(v9) < 4 || (int)v6 >= 127 )
      {
        for ( ; v11 > SHIDWORD(v9); --v11 )
        {
          v30 = HIDWORD(v9);
          v31 = HIDWORD(v9) + 1;
          if ( HIDWORD(v9) + 1 <= v11 )
          {
            v32 = v11 - HIDWORD(v9);
            do
            {
              *((_QWORD *)&v33 + 1) = *(_QWORD *)(8 * *(_DWORD *)(4 * v31 + HIDWORD(num)) + **((_DWORD **)this + 1));
              *(_QWORD *)((char *)&v33 + 4) = *(_QWORD *)(8 * *(_DWORD *)(4 * v30 + HIDWORD(num)) + DWORD2(v33));
              if ( DWORD2(v33) * DWORD2(v33)
                 - (int)v33 * (int)v33
                 - DWORD2(v33) * DWORD2(v33)
                 + DWORD1(v33) * DWORD1(v33) > 0 )
                v30 = v31;
              --v32;
              ++v31;
            }
            while ( v32 != 0 );
          }
          v34 = *(_DWORD *)(4 * v30 + HIDWORD(num));
          *(_DWORD *)(4 * v30 + HIDWORD(num)) = *(_DWORD *)(4 * v11 + HIDWORD(num));
          *(_DWORD *)(4 * v11 + HIDWORD(num)) = v34;
        }
        LODWORD(v6) = v6 - 1;
      }
      else
      {
        LODWORD(v12) = v9 + HIDWORD(v9);
        HIDWORD(v12) = 4 * v9;
        LODWORD(v12) = ((unsigned __int64)v12 >> 63) + v9 + HIDWORD(v9);
        LODWORD(v14) = v9 - 1;
        v13 = v12 >> 1;
        HIDWORD(v14) = *(_DWORD *)HIDWORD(v13);
        *(_DWORD *)HIDWORD(v13) = *(_DWORD *)(4 * v13 + HIDWORD(num));
        *(_DWORD *)(4 * v13 + HIDWORD(num)) = HIDWORD(v14);
        while ( 1 )
        {
          v15 = *((_DWORD **)this + 1);
          v16 = 8 * *(_DWORD *)HIDWORD(v13);
          v17 = *(_QWORD *)(8 * *(_DWORD *)(4 * v10 + HIDWORD(num)) + *v15);
          v18 = *(_QWORD *)(HIDWORD(v17) + v16);
          if ( (int)v18 * (int)v18 - (int)v17 * (int)v17 - (int)v18 * (int)v18 + HIDWORD(v18) * HIDWORD(v18) < 0 )
          {
            LODWORD(v18) = *v15;
            do
            {
              if ( ++v10 >= (int)v14 )
                break;
              *(__int64 *)((char *)&v18 - 4) = *(_QWORD *)(8 * *(_DWORD *)(4 * v10 + HIDWORD(v18)) + v18);
              v19 = *(_DWORD *)(8 * *(_DWORD *)HIDWORD(v13) + *v15 + 4);
            }
            while ( v19 * v19 - v20 * v20 - (int)v18 * (int)v18 + v20 * v20 < 0 );
          }
          LODWORD(v13) = 4 * v14 + HIDWORD(v18);
          num = *(_QWORD *)(v16 + *v15);
          v21 = *(_DWORD *)(8 * *(_DWORD *)v13 + *v15 + 4);
          if ( (int)num * (int)num - v21 * v21 > 0 )
            break;
LABEL_13:
          if ( v10 < (int)v14 )
          {
            LODWORD(v14) = v14 - 1;
            v22 = *(_DWORD *)(4 * v10 + HIDWORD(num));
            *(_DWORD *)(4 * v10++ + HIDWORD(num)) = *(_DWORD *)v13;
            *(_DWORD *)v13 = v22;
            if ( v10 < (int)v14 )
              continue;
          }
          goto LABEL_15;
        }
        while ( 1 )
        {
          LODWORD(v14) = v14 - 1;
          if ( (int)v14 <= v10 )
            break;
          LODWORD(v13) = 4 * v14 + HIDWORD(num);
          v37 = *(_DWORD *)(8 * *(_DWORD *)HIDWORD(v13) + *v15 + 4);
          if ( v37 * v37 - *(_DWORD *)(8 * *(_DWORD *)v13 + *v15 + 4) * *(_DWORD *)(8 * *(_DWORD *)v13 + *v15 + 4) <= 0 )
            goto LABEL_13;
        }
LABEL_15:
        v23 = *((int **)this + 1);
        v24 = *(_DWORD *)HIDWORD(v13);
        LODWORD(v13) = 4 * v10 + HIDWORD(num);
        v25 = 8 * *(_DWORD *)HIDWORD(v13);
        if ( *(_DWORD *)(v25 + *v23 + 4) * *(_DWORD *)(v25 + *v23 + 4)
           - *(_DWORD *)(8 * *(_DWORD *)v13 + *(_DWORD *)(v25 + *v23) + 4)
           * *(_DWORD *)(8 * *(_DWORD *)v13 + *(_DWORD *)(v25 + *v23) + 4) <= 0 )
        {
          do
          {
            if ( v10 >= (int)v9 )
              break;
            ++v10;
            LODWORD(v13) = 4 * v10 + HIDWORD(num);
            v26 = *(_QWORD *)(8 * *(_DWORD *)HIDWORD(v13) + *v23);
          }
          while ( (int)v26 * (int)v26
                - *(_DWORD *)(8 * *(_DWORD *)v13 + *v23 + 4) * *(_DWORD *)(8 * *(_DWORD *)v13 + *v23 + 4)
                - *(_DWORD *)(8 * *(_DWORD *)v13 + *v23) * *(_DWORD *)(8 * *(_DWORD *)v13 + *v23)
                + *(_DWORD *)v13 * *(_DWORD *)v13 <= 0 );
        }
        v35 = *(_QWORD *)(v25 + *v23);
        v36 = *(_QWORD *)(8 * *(_DWORD *)(4 * v14 + HIDWORD(num)) + HIDWORD(v35));
        v27 = v35 * v35;
        if ( (int)v35 * (int)v35
           - (int)v36 * (int)v36
           - HIDWORD(v36) * HIDWORD(v36)
           + *(_DWORD *)(v25 + *v23) * *(_DWORD *)(v25 + *v23) >= 0 )
        {
          v27 = *v23;
          do
          {
            if ( SHIDWORD(v9) >= (int)v14 )
              break;
            LODWORD(v14) = v14 - 1;
            *(__int64 *)((char *)&num - 4) = *(_QWORD *)(8 * *(_DWORD *)HIDWORD(v13) + *v23);
            v28 = 8 * *(_DWORD *)(4 * v14 + HIDWORD(num));
          }
          while ( v29 * v29
                - *(_DWORD *)(v28 + v27 + 4) * *(_DWORD *)(v28 + v27 + 4)
                - *(_DWORD *)(v28 + v27) * *(_DWORD *)(v28 + v27)
                + v28 * v28 >= 0 );
        }
        HIDWORD(v14) = v39;
        LODWORD(v6) = v6 + 1;
        *(_DWORD *)HIDWORD(v13) = *(_DWORD *)v13;
        *(_QWORD *)&v39[v7] = v9;
        *(_DWORD *)v13 = v24;
        v38[v7 / 8 + 1] = *(_QWORD *)&v10;
        *(_QWORD *)(v7 + v8) = v14;
      }
    }
    while ( (int)v6 >= 0 );
  }
}

