
// ========================================================================
// ?CreateState@idCollisionGridLocal@@UBAXAAVidCollisionGridState@@@Z
// EA  : 0x825BDAA8
// RVA : 0x005BDAA8
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void __fastcall idCollisionGridLocal::CreateState(idCollisionGridLocal *this, idCollisionGridState *state)
{
  int v4; // r31
  int v5; // r29

  idCollisionGridState::Create(this: state, num: this->grid.indices.num, material_: nullptr);
  v4 = 0;
  if ( this->grid.indices.num > 0 )
  {
    v5 = 0;
    do
    {
      if ( this->grid.indices.list[v5] == idGenGridModel::INVALID_INDEX )
        idCollisionGridState::Inactivate(this: state, id: v4);
      else
        idCollisionGridState::Activate(this: state, id: v4);
      ++v4;
      ++v5;
    }
    while ( v4 < this->grid.indices.num );
  }
}


// ========================================================================
// ?IsValid@idCollisionGridLocal@@UBA_NXZ
// EA  : 0x825BDB28
// RVA : 0x005BDB28
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

unsigned int __fastcall idCollisionGridLocal::IsValid(idCollisionGridLocal *this)
{
  return (-this->grid.parts.num & (unsigned int)~this->grid.parts.num) >> 31;
}


// ========================================================================
// ?GetBinaryFileName@idCollisionGridLocal@@QBA?AVidStr@@PBD@Z
// EA  : 0x825BDC40
// RVA : 0x005BDC40
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

idCollisionGridLocal *__fastcall idCollisionGridLocal::GetBinaryFileName(
        idCollisionGridLocal *this,
        idStr *result,
        const char *modelName)
{
  char v6[288]; // [sp+60h] [-120h] BYREF

  this->name.str = (const char *)20;
  this->trackedMemory = (int)&this->nextOnHashChain;
  this->__vftable = nullptr;
  HIBYTE(this->nextOnHashChain) = 0;
  if ( idStr::Icmpn(s1: modelName, s2: "maps/", n: 5) != 0 )
  {
    fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bcg", a4: modelName, a5: v6, a6: 256);
    idStr::operator=((idStr *)this, text: v6);
  }
  else
  {
    idStr::operator=((idStr *)this, text: modelName);
    idStr::SetFileExtension((idStr *)this, extension: "bcg");
  }
  return this;
}


// ========================================================================
// __unwind$227548
// EA  : 0x825BDD0C
// RVA : 0x005BDD0C
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void _unwind_227548()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 384;
  if ( (*(_DWORD *)(v0 - 384 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 404));
  }
}


// ========================================================================
// ?ReloadIfStale@idCollisionGridLocal@@UAA_NXZ
// EA  : 0x825BDD58
// RVA : 0x005BDD58
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

int __fastcall idCollisionGridLocal::ReloadIfStale(idCollisionGridLocal *this)
{
  idStr v3[2]; // [sp+50h] [-40h] BYREF

  idCollisionGridLocal::GetBinaryFileName(
    this: (idCollisionGridLocal *)v3,
    result: (idStr *)this,
    modelName: this->name.str);
  if ( fileSystem->GetTimestamp(this: fileSystem, a2: v3[0].data, a3: false) == this->binaryTimeStamp )
  {
    if ( idStr::Icmpn(s1: v3[0].data, s2: "maps/", n: 5) == 0
      || fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false) == this->sourceTimeStamp )
    {
      idStr::FreeData(this: v3);
      return 0;
    }
    fileSystem->RemoveFile(this: fileSystem, a2: v3[0].data, a3: FSPATH_BASE);
  }
  this->LoadResource(this);
  idStr::FreeData(this: v3);
  return 1;
}


// ========================================================================
// __unwind$227593
// EA  : 0x825BDE50
// RVA : 0x005BDE50
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void _unwind_227593()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?FreeData@idCollisionGridLocal@@QAAXXZ
// EA  : 0x825BDE78
// RVA : 0x005BDE78
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void __fastcall idCollisionGridLocal::FreeData(idCollisionGridLocal *this)
{
  idList<idVehicleState *,5> *p_grid; // r31

  p_grid = (idList<idVehicleState *,5> *)&this->grid;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->grid.vertices);
  idList<idThread *,58>::Clear(this: p_grid + 2);
  idList<idThread *,58>::Clear(this: p_grid + 3);
  idList<idThread *,58>::Clear(this: p_grid + 4);
  idList<idThread *,58>::Clear(this: p_grid + 5);
  idList<idThread *,58>::Clear(this: p_grid);
  this->binaryTimeStamp = -1;
  this->sourceTimeStamp = -1;
}


// ========================================================================
// ??1idCollisionGridLocal@@UAA@XZ
// EA  : 0x825BE498
// RVA : 0x005BE498
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void __fastcall idCollisionGridLocal::~idCollisionGridLocal(idCollisionGridLocal *this)
{
  this->__vftable = (idCollisionGridLocal_vtbl *)&idCollisionGridLocal::`vftable';
  idCollisionGridLocal::FreeData(this);
  idSoundBSPFile::~idSoundBSPFile(this: &this->grid);
  this->__vftable = (idCollisionGridLocal_vtbl *)&idCollisionGrid::`vftable';
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$228114
// EA  : 0x825BE4FC
// RVA : 0x005BE4FC
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void _unwind_228114()
{
  int v0; // r12

  idCollisionGrid::~idCollisionGrid(this: *(idCollisionGrid **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$228115
// EA  : 0x825BE524
// RVA : 0x005BE524
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void _unwind_228115()
{
  int v0; // r12

  idSoundBSPFile::~idSoundBSPFile(this: (idGenGridModel *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// ??0idCollisionGridLocal@@QAA@XZ
// EA  : 0x825BED80
// RVA : 0x005BED80
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

idCollisionGridLocal *__fastcall idCollisionGridLocal::idCollisionGridLocal(idCollisionGridLocal *this)
{
  idResource::idResource(this);
  this->__vftable = (idCollisionGridLocal_vtbl *)&idCollisionGridLocal::`vftable';
  idGenGridModel::idGenGridModel(this: &this->grid);
  this->binaryTimeStamp = -1;
  this->sourceTimeStamp = -1;
  return this;
}


// ========================================================================
// __unwind$228767
// EA  : 0x825BEDE0
// RVA : 0x005BEDE0
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void _unwind_228767()
{
  int v0; // r12

  idCollisionGrid::~idCollisionGrid(this: *(idCollisionGrid **)(v0 - 112 + 132));
}


// ========================================================================
// ?RasterizePolygon@idGridRasterize@@SAXABVidGenGridModel@@AAVidCollisionGridState@@PBVidVec2i@@H@Z
// EA  : 0x825BF310
// RVA : 0x005BF310
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void __fastcall idGridRasterize::RasterizePolygon(__int64 state, const idVec2i *pos, int num, long double a4)
{
  int v4; // r16
  int v5; // r21
  double v8; // fp29
  int v9; // r15
  double v10; // fp24
  _DWORD *v11; // r18
  int v12; // r11
  const idVec2i *v13; // r20
  int v14; // r9
  int y; // r8
  int v16; // r4
  unsigned __int64 v17; // kr00_8
  unsigned __int64 v18; // kr08_8
  int v19; // r8
  int v20; // r25
  int v21; // r9
  __int64 v22; // r6
  int v23; // r23
  __int64 v24; // r7
  int v25; // r29
  int v26; // r26
  int v27; // r30
  int v28; // r30
  int v29; // r11
  double v30; // fp23
  __int64 v31; // r9
  double v32; // fp31
  double v33; // fp25
  long double v34; // fp2
  __int64 v35; // r5
  double v36; // fp28
  double v37; // fp30
  double v38; // fp27
  long double v39; // fp2
  double v40; // fp26
  gridRasterizeEdge_t *v41; // r3
  gridRasterizeEdge_t *v42; // r10
  double v43; // fp0
  char v44; // r11
  double v45; // fp0
  double v46; // fp0
  gridRasterizeEdge_t *i; // r11
  int v48; // r25
  gridRasterizeEdge_t *v49; // r26
  gridRasterizeEdge_t *v50; // r21
  gridRasterizeEdge_t *v51; // r10
  gridRasterizeEdge_t *next; // r7
  gridRasterizeEdge_t *prev; // r11
  gridRasterizeEdge_t *v54; // r11
  gridRasterizeEdge_t *j; // r9
  gridRasterizeEdge_t *k; // r28
  unsigned int x; // r11
  unsigned __int16 v58; // r9
  int v59; // r30
  int v60; // r29
  float *v61; // r30
  float *v62; // r27
  char v63; // r28
  int v64; // r29
  int v65; // r10
  char v66; // r11
  int v67; // r11
  _DWORD *v68; // r11
  _DWORD *v69; // r11
  int v70; // r9
  int v71; // r11
  int v72; // r7
  float **v73; // r11
  gridRasterizeEdge_t *v74; // [sp+50h] [-2550h]
  signed int v75; // [sp+60h] [-2540h]
  unsigned __int64 v76; // [sp+68h] [-2538h]
  int v77; // [sp+70h] [-2530h]
  signed int v78; // [sp+74h] [-252Ch]
  idList<gridRasterizeEdge_t,5> v79; // [sp+A0h] [-2500h] BYREF
  int v80; // [sp+B0h] [-24F0h] BYREF
  idCollisionGridState *v81; // [sp+25BCh] [+1Ch]

  v81 = (idCollisionGridState *)state;
  v4 = 0;
  v79.granularity = 1;
  v79.num = 0;
  v79.size = 256;
  v5 = HIDWORD(state);
  *(_WORD *)&v79.memTag = 1281;
  v79.list = (gridRasterizeEdge_t *)&v80;
  LODWORD(state) = *(_DWORD *)(HIDWORD(state) + 128);
  v74 = nullptr;
  v8 = (float)state;
  v78 = state;
  v9 = 0x7FFFFFFF;
  v77 = *(_DWORD *)(HIDWORD(state) + 112);
  v75 = 0x80000000;
  v10 = (float)((float)1.0 / (float)state);
  if ( num > 0 )
  {
    v11 = (_DWORD *)(HIDWORD(state) + 120);
    v12 = num - 1;
    v13 = pos;
    do
    {
      v14 = v11[1];
      y = v13->y;
      v16 = pos[v12].y;
      LODWORD(v76) = y - v14;
      v17 = __PAIR64__(v13->x - *v11, y - v14);
      v18 = __PAIR64__(pos[v12].x - *v11, v16 - v14);
      if ( v16 - v14 > y - v14 )
      {
        v17 = __PAIR64__(v76, v16 - v14);
        HIDWORD(v76) = v13->x - *v11;
        v18 = v76;
      }
      v19 = *(_DWORD *)(v5 + 112) - 1;
      __twllei(v78, 0);
      __twlgei(v78 & ~(__ROL4__(HIDWORD(v18), 1) - 1), 0xFFFFFFFF);
      v20 = SHIDWORD(v18) / v78;
      if ( SHIDWORD(v18) / v78 >= v19 )
        v20 = v19;
      v21 = *(_DWORD *)(v5 + 116);
      HIDWORD(v22) = v78 & ~(__ROL4__(v18, 1) - 1);
      __twllei(v78, 0);
      __twlgei(HIDWORD(v22), 0xFFFFFFFF);
      v23 = (int)v18 / v78;
      if ( (int)v18 / v78 >= v21 - 1 )
        v23 = v21 - 1;
      __twllei(v78, 0);
      HIDWORD(v24) = v78 & ~(__ROL4__(HIDWORD(v17), 1) - 1);
      __twlgei(HIDWORD(v24), 0xFFFFFFFF);
      v25 = SHIDWORD(v17) / v78;
      if ( SHIDWORD(v17) / v78 >= v19 )
        v25 = *(_DWORD *)(v5 + 112) - 1;
      __twllei(v78, 0);
      __twlgei(v78 & ~(__ROL4__(v17, 1) - 1), 0xFFFFFFFF);
      v26 = (int)v17 / v78;
      if ( (int)v17 / v78 >= v21 - 1 )
        v26 = v21 - 1;
      if ( v23 == v26 )
      {
        v27 = v20;
        if ( v20 >= v25 )
        {
          v27 = v25;
          if ( v20 > v25 )
            v25 = v20;
        }
        for ( ; v27 <= v25; ++v27 )
          idCollisionGridState::Inactivate(this: v81, id: v27 + v23 * v77);
      }
      else
      {
        v28 = HIDWORD(v17) - HIDWORD(v18);
        v29 = v17 - v18;
        if ( HIDWORD(v17) == HIDWORD(v18) )
        {
          v30 = 1.0e30;
        }
        else
        {
          LODWORD(v24) = abs32(v28);
          v30 = (float)((float)1.0 / (float)v24);
        }
        LODWORD(v31) = HIDWORD(v18);
        HIDWORD(v31) = v29 ^ (v29 >> 31);
        LODWORD(v22) = abs32(v29);
        v32 = (float)v31;
        *(double *)&a4 = (float)((float)v31 * (float)v10);
        v33 = (float)((float)1.0 / (float)v22);
        v34 = floor(x: a4);
        LODWORD(v35) = v18;
        v36 = (float)v35;
        v37 = (float)((float)*(double *)&v34 * (float)v8);
        v38 = (float)((float)((float)*(double *)&v34 * (float)v8) + (float)v8);
        *(double *)&v34 = (float)((float)v35 * (float)v10);
        v39 = floor(x: v34);
        v40 = (float)((float)*(double *)&v39 * (float)v8);
        v41 = idList<gridRasterizeEdge_t,5>::Alloc(this: &v79);
        v41->x = v20;
        v41->xEnd = v25;
        v41->y = v23;
        v41->yEnd = v26;
        if ( v28 != 0 )
        {
          v44 = 1;
          if ( SHIDWORD(v18) >= SHIDWORD(v17) )
            v44 = -1;
          v41->delta.x = (float)v30 * (float)v8;
          v41->xDir = v44;
          if ( SHIDWORD(v18) <= SHIDWORD(v17) )
            v45 = (float)((float)v38 - (float)v32);
          else
            v45 = (float)((float)v32 - (float)v37);
          v43 = (float)((float)v45 * (float)v30);
          v42 = nullptr;
        }
        else
        {
          v42 = nullptr;
          v41->xDir = 0;
          v41->delta.x = 1900671690;
          v43 = 1.0e30;
        }
        v41->t.x = v43;
        v41->delta.y = (float)v33 * (float)v8;
        if ( (int)v18 <= (int)v17 )
          v46 = (float)((float)v40 - (float)v36);
        else
          v46 = (float)((float)v36 - (float)v40);
        v41->t.y = (float)v46 * (float)v33;
        v41->next = nullptr;
        v41->prev = nullptr;
        if ( v23 < v9 )
          v9 = v23;
        if ( v26 > v75 )
          v75 = v26;
        for ( i = v74; i != nullptr; i = i->next )
        {
          if ( i->y >= (unsigned int)(unsigned __int16)v23 )
            break;
          v42 = i;
        }
        v41->next = i;
        v41->prev = v42;
        if ( i != nullptr )
          i->prev = v41;
        if ( v42 != nullptr )
          v42->next = v41;
        else
          v74 = v41;
      }
      v12 = v4++;
      ++v13;
    }
    while ( v4 < num );
  }
  v48 = v9 * v77;
  if ( v9 <= v75 )
  {
    v49 = nullptr;
    v50 = v74;
    do
    {
      v51 = v50;
      if ( v50 != nullptr )
      {
        do
        {
          if ( v51->y > v9 )
            break;
          next = v51->next;
          if ( v51->next != nullptr )
            next->prev = v51->prev;
          prev = v51->prev;
          if ( prev != nullptr )
            prev->next = v51->next;
          else
            v50 = v51->next;
          v54 = v49;
          for ( j = nullptr; v54 != nullptr; v54 = v54->next )
          {
            if ( v51->x < (int)v54->x )
              break;
            j = v54;
          }
          v51->next = v54;
          v51->prev = j;
          if ( v54 != nullptr )
            v54->prev = v51;
          if ( j != nullptr )
            j->next = v51;
          else
            v49 = v51;
          v51 = next;
        }
        while ( next != nullptr );
      }
      for ( k = v49; k != nullptr; k = k->next->next )
      {
        if ( k->next == nullptr )
          break;
        x = k->next->x;
        v58 = k->x;
        if ( v58 >= x )
          v58 = k->next->x;
        v59 = v58;
        if ( k->x > (unsigned int)k->next->x )
          LOWORD(x) = k->x;
        v60 = (unsigned __int16)x;
        if ( v58 <= (int)(unsigned __int16)x )
        {
          do
          {
            idCollisionGridState::Inactivate(this: v81, id: v59 + v48);
            ++v59;
          }
          while ( v59 <= v60 );
        }
      }
      v61 = (float *)v49;
      if ( v49 != nullptr )
      {
        do
        {
          v62 = *(float **)v61;
          v63 = 0;
          v64 = v48;
          while ( 1 )
          {
            while ( 1 )
            {
              idCollisionGridState::Inactivate(this: v81, id: *((unsigned __int16 *)v61 + 12) + v64);
              if ( v61[4] >= (double)v61[5] )
                break;
              v65 = *((unsigned __int16 *)v61 + 12);
              if ( v65 == *((unsigned __int16 *)v61 + 14) )
              {
                if ( *(_DWORD *)v61 != 0 )
                  *(float *)(*(_DWORD *)v61 + 4) = v61[1];
                v68 = *((_DWORD **)v61 + 1);
                if ( v68 != nullptr )
                {
                  *v68 = *(_DWORD *)v61;
                  goto LABEL_91;
                }
                goto LABEL_90;
              }
              v66 = *((_BYTE *)v61 + 32);
              v61[4] = v61[2] + v61[4];
              v63 = 1;
              *((_WORD *)v61 + 12) = v66 + (_WORD)v65;
            }
            v67 = *((unsigned __int16 *)v61 + 13);
            if ( v67 != v9 )
              break;
            v61[5] = v61[3] + v61[5];
            v64 += v77;
            *((_WORD *)v61 + 13) = v67 + 1;
          }
          if ( v67 == *((unsigned __int16 *)v61 + 15) )
          {
            if ( *(_DWORD *)v61 != 0 )
              *(float *)(*(_DWORD *)v61 + 4) = v61[1];
            v69 = *((_DWORD **)v61 + 1);
            if ( v69 != nullptr )
            {
              *v69 = *(_DWORD *)v61;
              goto LABEL_91;
            }
LABEL_90:
            v49 = *(gridRasterizeEdge_t **)v61;
LABEL_91:
            v63 = 0;
          }
          if ( v63 != 0 )
          {
            v70 = *((unsigned __int16 *)v61 + 12) * v78;
            while ( *((_DWORD *)v61 + 1) != 0 )
            {
              v71 = *((_DWORD *)v61 + 1);
              if ( *(unsigned __int16 *)(v71 + 24) * v78 < v70 )
                break;
              if ( *(_DWORD *)v61 != 0 )
                *(_DWORD *)(*(_DWORD *)v61 + 4) = v71;
              **((float **)v61 + 1) = *v61;
              v72 = *((_DWORD *)v61 + 1);
              *(_DWORD *)v61 = v72;
              v61[1] = *(float *)(v72 + 4);
              *(_DWORD *)(v72 + 4) = v61;
              v73 = *((float ***)v61 + 1);
              if ( v73 != nullptr )
                *v73 = v61;
              else
                v49 = (gridRasterizeEdge_t *)v61;
            }
          }
          v61 = v62;
        }
        while ( v62 != nullptr );
      }
      ++v9;
      v48 += v77;
    }
    while ( v9 <= v75 );
  }
  if ( (v79.listStatic == 0 || v79.listStatic == 2) && v79.list != nullptr )
    idMem::Free(this: &mem, ptr: v79.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$229331
// EA  : 0x825BFA54
// RVA : 0x005BFA54
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void _unwind_229331()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 9632 + 160));
}


// ========================================================================
// ?InactivateFill@idCollisionGridLocal@@UBAXPBVidVec2i@@HAAVidCollisionGridState@@@Z
// EA  : 0x825BFA80
// RVA : 0x005BFA80
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void __fastcall idCollisionGridLocal::InactivateFill(
        idCollisionGridLocal *this,
        const idVec2i *pos,
        int num,
        idCollisionGridState *state,
        long double a5)
{
  __int64 v8; // r4

  LODWORD(v8) = state;
  HIDWORD(v8) = &this->grid;
  idGridRasterize::RasterizePolygon(state: v8, pos, num, a4: a5);
}


// ========================================================================
// ?LoadBinary@idGenGridModel@@QAA_NPAVidFile@@@Z
// EA  : 0x825BFA98
// RVA : 0x005BFA98
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

int __fastcall idGenGridModel::LoadBinary(idGenGridModel *this, idFile *file)
{
  idFile_vtbl *v5; // r11
  idList<cm_gridPart_t,5> *p_parts; // r25
  idList<cm_gridNodeBSP_t,5> *p_nodes; // r24
  int i; // r31
  idVec3 *v9; // r3
  int j; // r28
  int num; // r11
  int size; // r10
  cm_edge_t *list; // r9
  int v14; // r31
  int k; // r31
  int v16; // r11
  int v17; // r10
  unsigned __int16 *v18; // r9
  unsigned __int16 *v19; // r4
  int m; // r29
  int v21; // r11
  int v22; // r10
  cm_polygon_t *v23; // r9
  int v24; // r31
  int n; // r29
  int v26; // r11
  int v27; // r10
  cm_gridPart_t *v28; // r10
  int v29; // r31
  int ii; // r31
  int v31; // r11
  int v32; // r10
  unsigned __int16 *v33; // r9
  unsigned __int16 *v34; // r4
  int jj; // r29
  int v36; // r11
  int v37; // r10
  cm_gridNodeBSP_t *v38; // r10
  int v39; // r31
  int v40; // [sp+50h] [-80h] BYREF
  int v41; // [sp+54h] [-7Ch] BYREF
  int v42; // [sp+58h] [-78h] BYREF
  int v43; // [sp+5Ch] [-74h] BYREF
  int v44; // [sp+60h] [-70h] BYREF
  int v45; // [sp+64h] [-6Ch] BYREF
  int v46; // [sp+68h] [-68h] BYREF

  if ( file == nullptr )
    return 0;
  v5 = file->__vftable;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v5->Read(this: file, a2: &v40, a3: 4u);
  file->Read(this: file, a2: &v41, a3: 4u);
  file->Read(this: file, a2: &v42, a3: 4u);
  file->Read(this: file, a2: &v43, a3: 4u);
  file->Read(this: file, a2: &v44, a3: 4u);
  file->Read(this: file, a2: &v45, a3: 4u);
  file->Read(this: file, a2: &v46, a3: 4u);
  if ( v40 > this->vertices.size )
    idList<idVec3,59>::Resize(this: &this->vertices, newsize: v40);
  if ( v41 > this->edges.size )
    idList<idEffectPhysicsBroadPhase::idSPMarker,59>::Resize(this: &this->edges, newsize: v41);
  if ( v42 > this->polygonEdges.size )
    idList<unsigned short,30>::Resize(this: &this->polygonEdges, newsize: v42);
  if ( v43 > this->polygons.size )
    idList<animMapOffsets_t,5>::Resize(this: &this->polygons, newsize: v43);
  p_parts = &this->parts;
  if ( v44 > this->parts.size )
    idList<cm_gridPart_t,5>::Resize(this: &this->parts, newsize: v44);
  if ( v45 > this->indices.size )
    idList<unsigned short,30>::Resize(this: &this->indices, newsize: v45);
  p_nodes = &this->nodes;
  if ( v46 > this->nodes.size )
    idList<cm_gridNodeBSP_t,5>::Resize(this: &this->nodes, newsize: v46);
  for ( i = 0; i < v40; ++i )
  {
    v9 = idList<idVec3,5>::Alloc(this: &this->vertices);
    file->Read(this: file, a2: v9, a3: 12u);
  }
  for ( j = 0; j < v41; ++j )
  {
    idList<idEffectPhysicsBroadPhase::idSPMarker,59>::PreAllocateWithGranularity(
      this: &this->edges,
      newSize: this->edges.num + 1);
    num = this->edges.num;
    size = this->edges.size;
    list = this->edges.list;
    if ( num >= size )
    {
      v14 = (int)&list[size - 1];
    }
    else
    {
      v14 = (int)&list[num];
      this->edges.num = num + 1;
    }
    file->Read(this: file, a2: (void *)v14, a3: 2u);
    file->Read(this: file, a2: (void *)(v14 + 2), a3: 2u);
  }
  for ( k = 0; k < v42; ++k )
  {
    idList<unsigned short,5>::PreAllocateWithGranularity(this: &this->polygonEdges, newSize: this->polygonEdges.num + 1);
    v16 = this->polygonEdges.num;
    v17 = this->polygonEdges.size;
    v18 = this->polygonEdges.list;
    if ( v16 >= v17 )
    {
      v19 = &v18[v17 - 1];
    }
    else
    {
      v19 = &v18[v16];
      this->polygonEdges.num = v16 + 1;
    }
    file->Read(this: file, a2: v19, a3: 2u);
  }
  for ( m = 0; m < v43; ++m )
  {
    idList<cm_polygon_t,5>::PreAllocateWithGranularity(this: &this->polygons, newSize: this->polygons.num + 1);
    v21 = this->polygons.num;
    v22 = this->polygons.size;
    v23 = this->polygons.list;
    if ( v21 >= v22 )
    {
      v24 = (int)&v23[v22 - 1];
    }
    else
    {
      v24 = (int)&v23[v21];
      this->polygons.num = v21 + 1;
    }
    file->Read(this: file, a2: (void *)(v24 + 12), a3: 1u);
    file->Read(this: file, a2: (void *)(v24 + 14), a3: 2u);
    file->Read(this: file, a2: (void *)(v24 + 13), a3: 1u);
    file->Read(this: file, a2: (void *)v24, a3: 12u);
  }
  for ( n = 0; n < v44; ++n )
  {
    idList<cm_gridPart_t,5>::PreAllocateWithGranularity(this: &this->parts, newSize: this->parts.num + 1);
    v26 = this->parts.num;
    v27 = this->parts.size;
    if ( v26 >= v27 )
    {
      v29 = (int)&p_parts->list[v27 - 1];
    }
    else
    {
      v28 = p_parts->list;
      this->parts.num = v26 + 1;
      v29 = (int)&v28[v26];
    }
    file->Read(this: file, a2: (void *)v29, a3: 12u);
    file->Read(this: file, a2: (void *)(v29 + 12), a3: 2u);
    file->Read(this: file, a2: (void *)(v29 + 14), a3: 2u);
    file->Read(this: file, a2: (void *)(v29 + 16), a3: 2u);
  }
  for ( ii = 0; ii < v45; ++ii )
  {
    idList<unsigned short,5>::PreAllocateWithGranularity(this: &this->indices, newSize: this->indices.num + 1);
    v31 = this->indices.num;
    v32 = this->indices.size;
    v33 = this->indices.list;
    if ( v31 >= v32 )
    {
      v34 = &v33[v32 - 1];
    }
    else
    {
      v34 = &v33[v31];
      this->indices.num = v31 + 1;
    }
    file->Read(this: file, a2: v34, a3: 2u);
  }
  for ( jj = 0; jj < v46; ++jj )
  {
    idList<cm_gridNodeBSP_t,5>::PreAllocateWithGranularity(this: &this->nodes, newSize: this->nodes.num + 1);
    v36 = this->nodes.num;
    v37 = this->nodes.size;
    if ( v36 >= v37 )
    {
      v39 = (int)&p_nodes->list[v37 - 1];
    }
    else
    {
      v38 = p_nodes->list;
      this->nodes.num = v36 + 1;
      v39 = (int)&v38[v36];
    }
    file->Read(this: file, a2: (void *)v39, a3: 24u);
    file->Read(this: file, a2: (void *)(v39 + 24), a3: 4u);
    file->Read(this: file, a2: (void *)(v39 + 28), a3: 2u);
    file->Read(this: file, a2: (void *)(v39 + 30), a3: 2u);
    file->Read(this: file, a2: (void *)(v39 + 32), a3: 1u);
  }
  file->Read(this: file, a2: &this->numX, a3: 4u);
  file->Read(this: file, a2: &this->numY, a3: 4u);
  file->Read(this: file, a2: &this->dimension, a3: 4u);
  file->Read(this: file, a2: &this->offset, a3: 8u);
  return 1;
}


// ========================================================================
// ?Load_Binary@idCollisionGridLocal@@QAA_NXZ
// EA  : 0x825C0180
// RVA : 0x005C0180
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

int __fastcall idCollisionGridLocal::Load_Binary(idCollisionGridLocal *this)
{
  idFile *v2; // r3
  idFile *v3; // r30
  int v5; // [sp+50h] [-50h] BYREF
  idStr v6[2]; // [sp+60h] [-40h] BYREF

  idCollisionGridLocal::GetBinaryFileName(
    this: (idCollisionGridLocal *)v6,
    result: (idStr *)this,
    modelName: this->name.str);
  v2 = fileSystem->OpenFileRead(this: fileSystem, a2: v6[0].data, a3: 1, a4: 0);
  v3 = v2;
  if ( v2 != nullptr )
  {
    this->binaryTimeStamp = v2->Timestamp(this: v2);
    v3->Read(this: v3, a2: &v5, a3: 4u);
    if ( v5 == 1111705347 )
    {
      v3->Read(this: v3, a2: &this->sourceTimeStamp, a3: 4u);
      if ( (unsigned __int8)idGenGridModel::LoadBinary(this: &this->grid, file: v3) != 0 )
      {
        ((void (__fastcall *)(idFile *, int))v3->dtr_idFile)(a1: v3, a2: 1);
        idStr::FreeData(this: v6);
        return 1;
      }
      else
      {
        ((void (__fastcall *)(idFile *, int))v3->dtr_idFile)(a1: v3, a2: 1);
        idStr::FreeData(this: v6);
        return 0;
      }
    }
    else
    {
      idLib::Warning(fmt: "%s is not a binary collision grid file", v6[0].data);
      ((void (__fastcall *)(idFile *, int))v3->dtr_idFile)(a1: v3, a2: 1);
      idCollisionGridLocal::FreeData(this);
      idStr::FreeData(this: v6);
      return 0;
    }
  }
  else
  {
    idStr::FreeData(this: v6);
    return 0;
  }
}


// ========================================================================
// __unwind$230739
// EA  : 0x825C02F4
// RVA : 0x005C02F4
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void _unwind_230739()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?LoadResource@idCollisionGridLocal@@UAAXXZ
// EA  : 0x825C0320
// RVA : 0x005C0320
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void __fastcall idCollisionGridLocal::LoadResource(idCollisionGridLocal *this)
{
  idCollisionGridLocal::FreeData(this);
  idCollisionGridLocal::Load_Binary(this);
}


// ========================================================================
// `dynamic initializer for 'idCollisionGridLocal::resourceList''
// EA  : 0x83335138
// RVA : 0x01335138
// PDB : w:\tech5\engine\cm\collisiongrid.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idCollisionGridLocal::resourceList__()
{
  idResourceList::idResourceList(this: &idCollisionGridLocal::resourceList, typeName: "cg");
  idCollisionGridLocal::resourceList.__vftable = (idTypedResourceList<idCollisionGridLocal>_vtbl *)&idTypedResourceList<idCollisionGridLocal>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idCollisionGridLocal::resourceList__);
}

