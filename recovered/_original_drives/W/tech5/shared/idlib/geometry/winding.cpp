
// ========================================================================
// ?ReverseSelf@idWinding@@QAAXXZ
// EA  : 0x82F2A2C0
// RVA : 0x00F2A2C0
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

void __fastcall idWinding::ReverseSelf(idWinding *this)
{
  if ( (int)(this->numPoints & 0xFFFFFFFE) > 0 )
  {
    while ( 1 )
      ;
  }
}


// ========================================================================
// ?ReAllocate@idFixedWinding@@UAA_NH_N@Z
// EA  : 0x82F2A390
// RVA : 0x00F2A390
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

int __fastcall idFixedWinding::ReAllocate(idFixedWinding *this, int n, bool keep)
{
  if ( n <= 64 )
    return 1;
  idLib::Printf(fmt: "WARNING: idFixedWinding -> MAX_POINTS_ON_WINDING overflowed\n");
  return 0;
}


// ========================================================================
// ?ReAllocate@idWinding@@UAA_NH_N@Z
// EA  : 0x82F2A3D8
// RVA : 0x00F2A3D8
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

int __fastcall idWinding::ReAllocate(idWinding *this, int n, bool keep)
{
  idVec5 *p; // r30
  unsigned int v4; // r28
  unsigned int v7; // r5
  idVec5 *v8; // r3

  p = this->p;
  v4 = (n + 3) & 0xFFFFFFFC;
  if ( v4 > 0xCCCCCCC )
    v7 = -1;
  else
    v7 = 20 * v4;
  v8 = (idVec5 *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                   size: v7,
                   tag: TAG_NEW,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  this->p = v8;
  if ( p != nullptr )
  {
    if ( keep )
      memcpy(Dst: v8, Src: p, Size: 20 * this->numPoints);
    idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
  }
  this->allocedSize = v4;
  return 1;
}


// ========================================================================
// ?BaseForPlane@idWinding@@QAAXABVidVec3@@MM@Z
// EA  : 0x82F2A498
// RVA : 0x00F2A498
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

void __fastcall idWinding::BaseForPlane(idWinding *this, idVec3 *normal, double dist, double radius)
{
  double v8; // fp13
  double v9; // fp8
  idVec5 *p; // r10
  double v11; // fp5
  double v12; // fp2
  double v13; // fp1
  double v14; // fp12
  double v15; // fp7
  double v16; // fp11
  double v17; // fp10
  idVec5 *v18; // r11
  idVec5 *v19; // r11
  idVec5 *v20; // r11
  idVec3 v21; // [sp+50h] [-50h] BYREF
  idVec3 v22; // [sp+60h] [-40h] BYREF

  if ( this->allocedSize < 4 )
    this->ReAllocate(this, a2: 4, a3: false);
  this->numPoints = 4;
  idVec3::NormalVectors(this: normal, left: &v22, down: &v21);
  v8 = (float)(v22.x * (float)radius);
  v9 = (float)(v22.y * (float)radius);
  p = this->p;
  v11 = (float)((float)(normal->x * (float)dist) - (float)(v21.x * (float)radius));
  v12 = (float)((float)(normal->y * (float)dist) - (float)(v21.y * (float)radius));
  v13 = (float)((float)(normal->z * (float)dist) - (float)(v21.z * (float)radius));
  v14 = (float)((float)(normal->x * (float)dist) + (float)(v21.x * (float)radius));
  v15 = (float)(v22.z * (float)radius);
  v16 = (float)((float)(normal->y * (float)dist) + (float)(v21.y * (float)radius));
  v17 = (float)((float)(normal->z * (float)dist) + (float)(v21.z * (float)radius));
  p->x = (float)((float)(normal->x * (float)dist) - (float)(v21.x * (float)radius)) + (float)(v22.x * (float)radius);
  p->y = (float)v12 + (float)v9;
  p->z = (float)v13 + (float)v15;
  this->p->t = 0.0;
  this->p->s = 0.0;
  v18 = this->p;
  v18[1].x = (float)v14 + (float)v8;
  v18[1].y = (float)v16 + (float)v9;
  v18[1].z = (float)v17 + (float)v15;
  this->p[1].t = 0.0;
  this->p[1].s = 0.0;
  v19 = this->p;
  v19[2].x = (float)v14 - (float)v8;
  v19[2].y = (float)v16 - (float)v9;
  v19[2].z = (float)v17 - (float)v15;
  this->p[2].t = 0.0;
  this->p[2].s = 0.0;
  v20 = this->p;
  v20[3].x = (float)v11 - (float)v8;
  v20[3].y = (float)v12 - (float)v9;
  v20[3].z = (float)v13 - (float)v15;
  this->p[3].t = 0.0;
  this->p[3].s = 0.0;
}


// ========================================================================
// ?CalculateSides@@YAXPBVidVec5@@HABVidPlane@@MPAMPAEQAH@Z
// EA  : 0x82F2A638
// RVA : 0x00F2A638
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

void __fastcall CalculateSides(
        const idVec5 *points,
        int numPoints,
        const idPlane *plane,
        double epsilon,
        float *dists,
        float *sides,
        int *counts,
        _DWORD *a8)
{
  int v8; // r11
  int v9; // ctr
  float *v10; // r31
  float *p_y; // r6
  double v12; // fp0
  int v13; // r10
  int v14; // r10

  a8[2] = 0;
  v8 = 0;
  a8[1] = 0;
  *a8 = 0;
  if ( numPoints > 0 )
  {
    v9 = numPoints;
    v10 = sides;
    p_y = &points->y;
    do
    {
      v12 = (float)((float)((float)(plane->c * p_y[1])
                          + (float)((float)(plane->a * *(p_y - 1)) + (float)(plane->b * *p_y)))
                  + plane->d);
      *v10 = (float)((float)(plane->c * p_y[1]) + (float)((float)(plane->a * *(p_y - 1)) + (float)(plane->b * *p_y)))
           + plane->d;
      if ( v12 <= epsilon )
      {
        if ( v12 >= -epsilon )
          *((_BYTE *)counts + v8) = 2;
        else
          *((_BYTE *)counts + v8) = 1;
      }
      else
      {
        *((_BYTE *)counts + v8) = 0;
      }
      v13 = *((unsigned __int8 *)counts + v8++);
      p_y += 5;
      v14 = __ROL4__(v13, 2);
      ++v10;
      ++*(_DWORD *)((char *)a8 + v14);
      --v9;
    }
    while ( v9 != 0 );
  }
  *((_BYTE *)counts + numPoints) = *(_BYTE *)counts;
  sides[numPoints] = *sides;
}


// ========================================================================
// ?ClipInPlace@idWinding@@QAA_NABVidPlane@@M_N@Z
// EA  : 0x82F2A708
// RVA : 0x00F2A708
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

int __fastcall idWinding::ClipInPlace(
        idWinding *this,
        const idPlane *plane,
        double epsilon,
        const bool keepOn,
        char a5)
{
  int v7; // r3
  int v8; // r12
  __int64 v9; // r4
  int v10; // r12
  float *v11; // r7
  const idPlane *v12; // r5
  double v13; // fp1
  _BYTE *v15; // r8
  float *v16; // r7
  float *v17; // r5
  int v18; // r27
  int v19; // r28
  int v20; // r12
  int v21; // r10
  _BYTE *v22; // r3
  int v23; // r29
  float *v24; // r4
  int v25; // r26
  idVec5 *v26; // r6
  _DWORD *p_t; // r11
  float *v28; // r10
  int i; // ctr
  _DWORD *v30; // r11
  float *v31; // r10
  int j; // ctr
  int v33; // r10
  int v34; // r11
  signed int numPoints; // r24
  bool v36; // cr58
  idVec5 *p; // r9
  double v38; // fp0
  float *p_x; // r11
  double v40; // fp13
  double v41; // fp0
  double v42; // fp0
  double s; // fp0
  double t; // fp10
  double v45; // fp9
  double v46; // fp8
  double v47; // fp0
  double v48; // fp0
  int *v49; // r11
  float *v50; // r10
  int v51; // ctr
  float *back_chain[19]; // [sp+0h] [-C0h]
  int v54; // [sp+4Ch] [-74h] BYREF
  float v55; // [sp+50h] [-70h] BYREF
  float v56; // [sp+54h] [-6Ch]
  float v57; // [sp+58h] [-68h]
  float v58; // [sp+5Ch] [-64h]
  float v59; // [sp+60h] [-60h]

  v7 = ((int (*)(void))RtlCheckStack12)();
  *(float **)((char *)back_chain + v8) = back_chain[0];
  v9 = ((__int64 (__fastcall *)(int))RtlCheckStack12)(a1: v7);
  HIDWORD(v9) = *(_DWORD *)(HIDWORD(v9) + 8);
  *(float **)((char *)back_chain + v10) = back_chain[0];
  CalculateSides(
    points: (const idVec5 *)HIDWORD(v9),
    numPoints: v9,
    plane: v12,
    epsilon: v13,
    dists: back_chain[0],
    sides: v11,
    counts: (int *)&v55,
    a8: &v55);
  if ( a5 != 0 )
  {
    if ( v55 == 0.0 )
    {
      if ( v56 == 0.0 )
        return 1;
      goto LABEL_6;
    }
  }
  else if ( v55 == 0.0 )
  {
LABEL_6:
    this->numPoints = 0;
    return 0;
  }
  if ( v56 != 0.0 )
  {
    ((void (*)(void))RtlCheckStack12)();
    v18 = 0;
    v19 = 0;
    *(float **)((char *)back_chain + v20) = back_chain[0];
    if ( v21 > 0 )
    {
      v22 = v15;
      v23 = 0;
      v24 = &v55;
      v25 = 1 - (_DWORD)v15;
      do
      {
        v26 = &this->p[v23];
        if ( *v22 == 2 )
        {
          p_t = (_DWORD *)&v26[-1].t;
          v28 = v24 - 1;
          for ( i = 5; i != 0; --i )
            *++v28 = *(float *)++p_t;
        }
        else
        {
          if ( *v22 == 0 )
          {
            v30 = (_DWORD *)&v26[-1].t;
            v31 = v24 - 1;
            for ( j = 5; j != 0; --j )
              *++v31 = *(float *)++v30;
            ++v18;
            v24 += 5;
          }
          v33 = (unsigned __int8)v15[v19 + 1];
          if ( v33 == 2 )
            goto LABEL_56;
          v34 = (unsigned __int8)*v22;
          if ( v33 == v34 )
            goto LABEL_56;
          numPoints = this->numPoints;
          v36 = v34 == 0;
          p = this->p;
          v38 = *v17;
          __twllei(numPoints, 0);
          __twlgei(numPoints & ~(__ROL4__(&v22[v25], 1) - 1), 0xFFFFFFFF);
          p_x = &p[(int)&v22[v25] % numPoints].x;
          if ( v36 )
          {
            v40 = (float)(*v16 / (float)(*v16 - v16[1]));
            if ( v38 == 1.0 )
            {
              v55 = -v17[3];
            }
            else if ( v38 == -1.0 )
            {
              v55 = v17[3];
            }
            else
            {
              v55 = (float)((float)(*p_x - v26->x) * (float)(*v16 / (float)(*v16 - v16[1]))) + v26->x;
            }
            v41 = v17[1];
            if ( v41 == 1.0 )
            {
              v56 = -v17[3];
            }
            else if ( v41 == -1.0 )
            {
              v56 = v17[3];
            }
            else
            {
              v56 = (float)((float)(p_x[1] - v26->y) * (float)v40) + v26->y;
            }
            v42 = v17[2];
            if ( v42 == 1.0 )
            {
              v57 = -v17[3];
              s = v26->s;
              t = v26->t;
              v45 = p_x[3];
              v46 = p_x[4];
            }
            else
            {
              if ( v42 == -1.0 )
              {
                v57 = v17[3];
                s = v26->s;
                t = v26->t;
              }
              else
              {
                t = v26->t;
                v57 = (float)((float)(p_x[2] - v26->z) * (float)v40) + v26->z;
                s = v26->s;
              }
              v45 = p_x[3];
              v46 = p_x[4];
            }
          }
          else
          {
            v40 = (float)(v16[1] / (float)(v16[1] - *v16));
            if ( v38 == 1.0 )
            {
              v55 = -v17[3];
            }
            else if ( v38 == -1.0 )
            {
              v55 = v17[3];
            }
            else
            {
              v55 = (float)((float)(v26->x - *p_x) * (float)(v16[1] / (float)(v16[1] - *v16))) + *p_x;
            }
            v47 = v17[1];
            if ( v47 == 1.0 )
            {
              v56 = -v17[3];
            }
            else if ( v47 == -1.0 )
            {
              v56 = v17[3];
            }
            else
            {
              v56 = (float)((float)(v26->y - p_x[1]) * (float)v40) + p_x[1];
            }
            v48 = v17[2];
            if ( v48 == 1.0 )
            {
              v57 = -v17[3];
            }
            else if ( v48 == -1.0 )
            {
              v57 = v17[3];
            }
            else
            {
              v57 = (float)((float)(v26->z - p_x[2]) * (float)v40) + p_x[2];
            }
            s = p_x[3];
            t = p_x[4];
            v45 = v26->s;
            v46 = v26->t;
          }
          v49 = &v54;
          v50 = v24 - 1;
          v51 = 5;
          v59 = (float)((float)((float)v46 - (float)t) * (float)v40) + (float)t;
          v58 = (float)((float)((float)v45 - (float)s) * (float)v40) + (float)s;
          do
          {
            *(_DWORD *)++v50 = *++v49;
            --v51;
          }
          while ( v51 != 0 );
        }
        v24 += 5;
        ++v18;
LABEL_56:
        ++v19;
        ++v23;
        ++v22;
        ++v16;
      }
      while ( v19 < this->numPoints );
    }
    if ( v18 <= this->allocedSize || this->ReAllocate(this, a2: v18, a3: false) )
    {
      this->numPoints = v18;
      memcpy(Dst: this->p, Src: &v55, Size: 20 * v18);
    }
  }
  return 1;
}


// ========================================================================
// ?GetCenter@idWinding@@QBA?AVidVec3@@XZ
// EA  : 0x82F2ABA8
// RVA : 0x00F2ABA8
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

idWinding *__fastcall idWinding::GetCenter(idWinding *this, idVec3 *result)
{
  float y; // r31
  int v3; // r8
  float z; // r9
  int v5; // r10
  double v6; // fp13
  double v7; // fp0
  double v8; // fp10
  double v9; // fp4
  double v10; // fp8
  double v11; // fp6
  double v12; // fp3
  double v13; // fp11
  double v14; // fp1
  double v15; // fp10
  double v16; // fp12
  double v17; // fp4
  double v18; // fp2
  float *v19; // r11
  double v20; // fp3
  double v21; // fp12
  double v22; // fp7
  double v23; // fp10
  double v24; // fp13
  float v25; // r9
  int v26; // r10
  int v27; // ctr
  double v28; // fp7
  double v29; // fp6
  double v30; // fp12
  double v31; // fp9

  y = result->y;
  v3 = 0;
  *(float *)&this->__vftable = 0.0;
  *(float *)&this->numPoints = 0.0;
  *(float *)&this->p = 0.0;
  if ( SLODWORD(y) >= 4 )
  {
    z = result->z;
    v5 = 0;
    do
    {
      v6 = *(float *)&this->p;
      v7 = *(float *)&this->numPoints;
      v3 += 4;
      v8 = (float)(*(float *)(v5 + LODWORD(z)) + *(float *)&this->__vftable);
      *(float *)&this->__vftable = *(float *)(v5 + LODWORD(z)) + *(float *)&this->__vftable;
      v9 = (float)(*(float *)(v5 + LODWORD(z) + 8) + (float)v6);
      v10 = (float)(*(float *)(v5 + LODWORD(z) + 4) + (float)v7);
      v11 = *(float *)(v5 + LODWORD(z) + 24);
      v12 = *(float *)(v5 + LODWORD(z) + 20);
      *(float *)&this->p = *(float *)(v5 + LODWORD(z) + 8) + (float)v6;
      v13 = *(float *)(v5 + 60 + LODWORD(z) - 20);
      *(float *)&this->numPoints = v10;
      v14 = (float)((float)v12 + (float)v8);
      *(float *)&this->__vftable = (float)v12 + (float)v8;
      v15 = *(float *)(v5 + 60 + LODWORD(z) - 16);
      v16 = v9;
      v17 = *(float *)(v5 + LODWORD(z) + 28);
      v18 = *(float *)(v5 + 60 + LODWORD(z) - 12);
      *(float *)&this->numPoints = (float)v11 + (float)v10;
      v19 = (float *)(v5 + 60 + LODWORD(z));
      *(float *)&this->__vftable = (float)v13 + (float)v14;
      v20 = (float)((float)v17 + (float)v16);
      v21 = v19[1];
      v22 = (float)((float)v15 + (float)((float)v11 + (float)v10));
      v23 = v19[2];
      v24 = *v19;
      v5 += 80;
      *(float *)&this->numPoints = v22;
      *(float *)&this->p = v20;
      *(float *)&this->__vftable = (float)v24 + (float)((float)v13 + (float)v14);
      *(float *)&this->p = (float)v18 + (float)v20;
      *(float *)&this->numPoints = (float)v21 + (float)v22;
      *(float *)&this->p = (float)v23 + (float)((float)v18 + (float)v20);
    }
    while ( v3 < LODWORD(y) - 3 );
  }
  if ( v3 < SLODWORD(y) )
  {
    v25 = result->z;
    v26 = 20 * v3;
    v27 = LODWORD(y) - v3;
    do
    {
      v28 = (float)(*(float *)(v26 + LODWORD(v25) + 4) + *(float *)&this->numPoints);
      v29 = (float)(*(float *)(v26 + LODWORD(v25) + 8) + *(float *)&this->p);
      *(float *)&this->__vftable = *(float *)(v26 + LODWORD(v25)) + *(float *)&this->__vftable;
      v26 += 20;
      *(float *)&this->numPoints = v28;
      *(float *)&this->p = v29;
      --v27;
    }
    while ( v27 != 0 );
  }
  v30 = *(float *)&this->numPoints;
  v31 = *(float *)&this->p;
  *(float *)&this->__vftable = *(float *)&this->__vftable
                             * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, LODWORD(y)));
  *(float *)&this->numPoints = (float)v30 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, LODWORD(y)));
  *(float *)&this->p = (float)v31 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, LODWORD(y)));
  return this;
}


// ========================================================================
// ?GetBounds@idWinding@@QBAXAAVidBounds@@@Z
// EA  : 0x82F2AD68
// RVA : 0x00F2AD68
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

void __fastcall idWinding::GetBounds(idWinding *this, idBounds *bounds)
{
  idVec5 *p; // r11
  idVec3 *v3; // r9
  int v4; // r8
  double x; // fp0
  int v6; // r11
  idVec5 *v7; // r10
  double v8; // fp0
  idVec5 *v9; // r10
  double y; // fp0
  idVec5 *v11; // r10
  double z; // fp0

  if ( this->numPoints != 0 )
  {
    p = this->p;
    v3 = &bounds->b[1];
    v4 = 1;
    x = p->x;
    bounds->b[1].x = p->x;
    bounds->b[1].y = p->y;
    bounds->b[1].z = p->z;
    bounds->b[0].x = x;
    bounds->b[0].y = bounds->b[1].y;
    bounds->b[0].z = bounds->b[1].z;
    if ( this->numPoints > 1 )
    {
      v6 = 1;
      do
      {
        v7 = this->p;
        v8 = v7[v6].x;
        if ( v8 >= bounds->b[0].x )
        {
          if ( v8 > v3->x )
            v3->x = v7[v6].x;
        }
        else
        {
          bounds->b[0].x = v7[v6].x;
        }
        v9 = &this->p[v6];
        y = v9->y;
        if ( y >= bounds->b[0].y )
        {
          if ( y > bounds->b[1].y )
            bounds->b[1].y = v9->y;
        }
        else
        {
          bounds->b[0].y = v9->y;
        }
        v11 = &this->p[v6];
        z = v11->z;
        if ( z >= bounds->b[0].z )
        {
          if ( z > bounds->b[1].z )
            bounds->b[1].z = v11->z;
        }
        else
        {
          bounds->b[0].z = v11->z;
        }
        ++v4;
        ++v6;
      }
      while ( v4 < this->numPoints );
    }
  }
  else
  {
    bounds->b[0].z = 1.0e30;
    bounds->b[0].y = 1.0e30;
    bounds->b[0].x = 1.0e30;
    bounds->b[1].z = -1.0e30;
    bounds->b[1].y = -1.0e30;
    bounds->b[1].x = -1.0e30;
  }
}


// ========================================================================
// ?AddToConvexHull@idWinding@@QAAXABVidVec3@@0M@Z
// EA  : 0x82F2AE98
// RVA : 0x00F2AE98
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

void __fastcall idWinding::AddToConvexHull(idWinding *this, const idVec3 *point, const idVec3 *normal, double epsilon)
{
  unsigned int numPoints; // r10
  int v6; // r3
  int v7; // r12
  float *v8; // r5
  float *v9; // r4
  double v10; // fp1
  int v11; // r11
  int v12; // r12
  int v13; // r10
  int v14; // r10
  float *v15; // r9
  idVec5 *v16; // r8
  signed int v17; // r28
  double v18; // fp0
  double v19; // fp13
  double v20; // fp12
  double v21; // fp11
  double y; // fp10
  double z; // fp9
  float *v24; // r8
  double v25; // fp6
  double v26; // fp3
  double v27; // fp2
  double v28; // fp11
  double v29; // fp10
  signed int v30; // r10
  char v31; // r3
  signed int v32; // r7
  idVec5 *v33; // r6
  double v34; // fp13
  double v35; // fp12
  double v36; // fp11
  int v37; // r9
  float *v38; // r11
  double v39; // fp0
  int v40; // r8
  int v41; // r11
  int v42; // r5
  signed int v43; // r10
  int v44; // r12
  int v45; // r8
  float *v46; // r4
  double v47; // fp13
  double v48; // fp12
  int v49; // r4
  int v50; // r28
  int v51; // r7
  int v52; // r3
  int v53; // r6
  int *v54; // r5
  int v55; // r9
  int v56; // r9
  idVec5 *v57; // r8
  int v58; // ctr
  int *v59; // r9
  _DWORD *v60; // r11
  idVec5 *v62; // r3
  idVec5 *v63; // r11
  double x; // fp10
  bool v65; // r10
  float *p_x; // r9
  _DWORD *p_t; // r10
  _DWORD *v68; // r11
  int i; // ctr
  idVec5 *v70; // r11
  idVec5 *p; // r11
  bool v72; // r10
  idVec5 *v73; // r11
  _DWORD back_chain[19]; // [sp+0h] [-90h]
  _BYTE v75[4]; // [sp+4Ch] [-44h] BYREF
  float v76; // [sp+50h] [-40h] BYREF
  float v77[4]; // [sp+54h] [-3Ch] BYREF
  int v78; // [sp+64h] [-2Ch] BYREF

  numPoints = this->numPoints;
  if ( numPoints != 0 )
  {
    if ( numPoints == 1 )
    {
      p = this->p;
      v72 = false;
      if ( __fabs((float)(p->x - point->x)) <= epsilon && __fabs((float)(p->y - point->y)) <= epsilon )
        v72 = __fabs((float)(p->z - point->z)) <= epsilon;
      if ( !v72 )
      {
        *(idVec3 *)&p[1].x = *point;
        ++this->numPoints;
      }
    }
    else if ( numPoints < 3 )
    {
      v63 = this->p;
      v65 = false;
      if ( __fabs((float)(v63->x - point->x)) <= epsilon && __fabs((float)(v63->y - point->y)) <= epsilon )
        v65 = __fabs((float)(v63->z - point->z)) <= epsilon;
      if ( !v65 )
      {
        if ( __fabs((float)(v63[1].x - point->x)) <= epsilon && __fabs((float)(v63[1].y - point->y)) <= epsilon )
          v65 = __fabs((float)(v63[1].z - point->z)) <= epsilon;
        if ( !v65
          && ((float)((float)((float)(v63[1].z - v63->z) * (float)(point->y - v63->y))
                    - (float)((float)(v63[1].y - v63->y) * (float)(point->z - v63->z))) != 0.0
           || (float)((float)((float)(point->z - v63->z) * (float)(v63[1].x - v63->x))
                    - (float)((float)(v63[1].z - v63->z) * (float)(point->x - v63->x))) != 0.0
           || (float)((float)((float)(v63[1].y - v63->y) * (float)(point->x - v63->x))
                    - (float)((float)(point->y - v63->y) * (float)(v63[1].x - v63->x))) != 0.0) )
        {
          x = point->x;
          p_x = &v63[1].x;
          if ( (float)((float)(normal->x
                             * (float)((float)((float)(p_x[2] - v63->z) * (float)(point->y - v63->y))
                                     - (float)((float)(p_x[1] - v63->y) * (float)(point->z - v63->z))))
                     + (float)((float)(normal->z
                                     * (float)((float)((float)(p_x[1] - v63->y) * (float)((float)x - v63->x))
                                             - (float)((float)(point->y - v63->y) * (float)(*p_x - v63->x))))
                             + (float)(normal->y
                                     * (float)((float)((float)(point->z - v63->z) * (float)(*p_x - v63->x))
                                             - (float)((float)(p_x[2] - v63->z) * (float)((float)x - v63->x)))))) <= 0.0 )
          {
            p_t = (_DWORD *)&v63[1].t;
            v68 = (_DWORD *)&v63->t;
            for ( i = 5; i != 0; --i )
              *++p_t = *++v68;
            v70 = this->p;
            v70[1].x = point->x;
            v70[1].y = point->y;
            v70[1].z = point->z;
            ++this->numPoints;
          }
          else
          {
            *(idVec3 *)&v63[2].x = *point;
            ++this->numPoints;
          }
        }
      }
    }
    else
    {
      v6 = ((int (*)(void))RtlCheckStack12)();
      *(_DWORD *)((char *)back_chain + v7) = back_chain[0];
      ((void (__fastcall *)(int))RtlCheckStack12)(a1: v6);
      v11 = 0;
      *(_DWORD *)((char *)back_chain + v12) = back_chain[0];
      if ( v13 > 0 )
      {
        v14 = 0;
        v15 = (float *)v75;
        do
        {
          v16 = this->p;
          ++v11;
          v17 = this->numPoints;
          v18 = v8[2];
          v19 = *v8;
          v20 = v8[1];
          v21 = v16[v14].x;
          y = v16[v14].y;
          z = v16[v14].z;
          __twllei(v17, 0);
          __twlgei(v17 & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF);
          v24 = &v16[v11 % v17].x;
          ++v14;
          v25 = (float)(v24[1] - (float)y);
          v26 = (float)(*v24 - (float)v21);
          v27 = (float)((float)v18 * (float)(v24[1] - (float)y));
          v29 = (float)((float)v20 * (float)(*v24 - (float)v21));
          v28 = (float)((float)v19 * (float)(v24[2] - (float)z));
          v15[1] = (float)((float)v20 * (float)(v24[2] - (float)z)) - (float)v27;
          v15[2] = (float)((float)v18 * (float)v26) - (float)v28;
          v15 += 3;
          *v15 = (float)((float)v19 * (float)v25) - (float)v29;
        }
        while ( v11 < this->numPoints );
      }
      v30 = this->numPoints;
      v31 = 0;
      v32 = 0;
      if ( v30 > 0 )
      {
        v33 = this->p;
        v34 = *v9;
        v35 = v9[1];
        v36 = v9[2];
        v37 = 0;
        v38 = v77;
        do
        {
          v39 = (float)((float)(*(v38 - 1) * (float)((float)v34 - v33[v37].x))
                      + (float)((float)(*v38 * (float)((float)v35 - v33[v37].y))
                              + (float)(v38[1] * (float)((float)v36 - v33[v37].z))));
          if ( v39 >= v10 )
            v31 = 1;
          *((_BYTE *)&v77[-1] + v32++) = v39 >= -v10;
          ++v37;
          v38 += 3;
        }
        while ( v32 < v30 );
      }
      if ( v31 != 0 )
      {
        v40 = 0;
        if ( v30 > 0 )
        {
          v41 = 1;
          do
          {
            if ( v75[v41 + 3] == 0 )
            {
              __twllei(v30, 0);
              v42 = *((unsigned __int8 *)&v77[-1] + v41 % v30);
              __twlgei(v30 & ~(__ROL4__(v41, 1) - 1), 0xFFFFFFFF);
              if ( v42 != 0 )
                break;
            }
            ++v40;
            ++v41;
          }
          while ( v40 < this->numPoints );
        }
        if ( v40 < v30 )
        {
          ((void (*)(void))RtlCheckStack12)();
          *(_DWORD *)((char *)back_chain + v44) = back_chain[0];
          v47 = v46[1];
          v48 = v46[2];
          v76 = *v46;
          v77[0] = v47;
          v77[1] = v48;
          v49 = (v45 + 1) % v43;
          __twllei(v43, 0);
          v50 = 1;
          __twlgei(v43 & ~(__ROL4__(v45 + 1, 1) - 1), 0xFFFFFFFF);
          v77[3] = 0.0;
          v51 = 0;
          v77[2] = 0.0;
          if ( v43 > 0 )
          {
            v52 = this->numPoints;
            v53 = v49 + 1;
            v54 = &v78;
            do
            {
              __twllei(v43, 0);
              v55 = *((unsigned __int8 *)&v77[-1] + (v51 + v49) % v43);
              __twlgei(v43 & ~(__ROL4__(v51 + v49, 1) - 1), 0xFFFFFFFF);
              if ( v55 == 0
                || (__twllei(v43, 0),
                    v56 = *((unsigned __int8 *)&v77[-1] + (v53 + v51) % v43),
                    __twlgei(v43 & ~(__ROL4__(v53 + v51, 1) - 1), 0xFFFFFFFF),
                    v56 == 0) )
              {
                v57 = this->p;
                v58 = 5;
                __twllei(v43, 0);
                __twlgei(v43 & ~(__ROL4__(v53 + v51, 1) - 1), 0xFFFFFFFF);
                v59 = v54 - 1;
                v60 = (_DWORD *)&v57[(v53 + v51) % v43 - 1].t;
                do
                {
                  *++v59 = *++v60;
                  --v58;
                }
                while ( v58 != 0 );
                ++v50;
                v54 += 5;
              }
              ++v51;
            }
            while ( v51 < v52 );
          }
          if ( v50 <= this->allocedSize || this->ReAllocate(this, a2: v50, a3: false) )
          {
            v62 = this->p;
            this->numPoints = v50;
            memcpy(Dst: v62, Src: &v76, Size: 20 * v50);
          }
        }
      }
    }
  }
  else
  {
    v73 = this->p;
    v73->x = point->x;
    v73->y = point->y;
    v73->z = point->z;
    v73->t = 0.0;
    v73->s = 0.0;
    ++this->numPoints;
  }
}


// ========================================================================
// ?IsHuge@idWinding@@QBA_NM@Z
// EA  : 0x82F2B510
// RVA : 0x00F2B510
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

int __fastcall idWinding::IsHuge(idWinding *this, double radius)
{
  int numPoints; // r7
  int v3; // r8
  int v4; // r10
  int i; // r11
  double v6; // fp0

  numPoints = this->numPoints;
  v3 = 0;
  if ( numPoints > 0 )
  {
    v4 = 0;
    while ( 2 )
    {
      for ( i = 0; i < 3; ++i )
      {
        v6 = *(&this->p[v4].x + i);
        if ( v6 <= -radius || v6 >= radius )
          return 1;
      }
      ++v3;
      ++v4;
      if ( v3 < numPoints )
        continue;
      break;
    }
  }
  return 0;
}


// ========================================================================
// ?PointInside@idWinding@@QBA_NABVidVec3@@0M@Z
// EA  : 0x82F2B578
// RVA : 0x00F2B578
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

int __fastcall idWinding::PointInside(idWinding *this, const idVec3 *normal, const idVec3 *point, double epsilon)
{
  signed int numPoints; // r7
  signed int v5; // r11
  idVec5 *p; // r8
  double v7; // fp8
  int i; // r9
  signed int v9; // r10
  double x; // fp4
  double v11; // fp2
  double y; // fp1
  double z; // fp3
  double v14; // fp31
  double v15; // fp30
  float *p_x; // r11
  double v17; // fp4
  double v18; // fp1
  double v19; // fp3
  double v20; // fp27
  double v21; // fp3
  double v22; // fp4
  double v23; // fp1
  double v26; // fp29
  double v27; // fp29
  double v28; // fp29
  double v29; // fp29

  numPoints = this->numPoints;
  v5 = 0;
  if ( numPoints <= 0 )
    return 1;
  p = this->p;
  v7 = -epsilon;
  for ( i = 0; ; ++i )
  {
    v9 = v5 + 1;
    x = p[i].x;
    v11 = (float)(point->x - p[i].x);
    y = p[i].y;
    z = p[i].z;
    v14 = (float)(point->y - p[i].y);
    v15 = (float)(point->z - p[i].z);
    __twllei(numPoints, 0);
    __twlgei(numPoints & ~(__ROL4__(v5 + 1, 1) - 1), 0xFFFFFFFF);
    p_x = &p[(v5 + 1) % numPoints].x;
    v17 = (float)(*p_x - (float)x);
    v18 = (float)(p_x[1] - (float)y);
    v19 = (float)(p_x[2] - (float)z);
    v20 = (float)(normal->y * (float)v19);
    v21 = (float)((float)(normal->x * (float)v19) - (float)(normal->z * (float)v17));
    v22 = (float)((float)(normal->y * (float)v17) - (float)(normal->x * (float)v18));
    v23 = (float)((float)(normal->z * (float)v18) - (float)v20);
    _FP28 = (float)((float)((float)((float)v23 * (float)v23)
                          + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f29, f28, f29, f10 }
    v26 = __frsqrte(_FP29);
    v27 = (float)((float)-(float)((float)((float)((float)v26
                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                + (float)((float)((float)v22 * (float)v22)
                                                                        + (float)((float)v21 * (float)v21)))
                                                        * (float)0.5))
                                        * (float)v26)
                                - (float)1.5)
                * (float)v26);
    v28 = (float)((float)-(float)((float)((float)((float)v27
                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                + (float)((float)((float)v22 * (float)v22)
                                                                        + (float)((float)v21 * (float)v21)))
                                                        * (float)0.5))
                                        * (float)v27)
                                - (float)1.5)
                * (float)v27);
    v29 = (float)((float)-(float)((float)((float)((float)v28
                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                + (float)((float)((float)v22 * (float)v22)
                                                                        + (float)((float)v21 * (float)v21)))
                                                        * (float)0.5))
                                        * (float)v28)
                                - (float)1.5)
                * (float)v28);
    if ( (float)((float)((float)((float)v23 * (float)v29) * (float)v11)
               + (float)((float)((float)((float)v22 * (float)v29) * (float)v15)
                       + (float)((float)((float)v21 * (float)v29) * (float)v14))) < v7 )
      break;
    v5 = v9;
    if ( v9 >= numPoints )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?SplitInPlace@idFixedWinding@@QAAHABVidPlane@@MPAV1@@Z
// EA  : 0x82F2B710
// RVA : 0x00F2B710
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

int __fastcall idFixedWinding::SplitInPlace(
        idFixedWinding *this,
        const idPlane *plane,
        double epsilon,
        idFixedWinding *back,
        int a5)
{
  idFixedWinding_vtbl *v9; // r9
  int v10; // r11
  int numPoints; // r7
  int v12; // r25
  int v13; // r26
  float *v14; // r24
  idVec5 *v15; // r29
  char v16; // r3
  char v17; // r3
  char *v18; // r28
  int v19; // r6
  _DWORD *v20; // r9
  int v21; // ctr
  float *v22; // r11
  int v23; // r11
  _DWORD *v24; // r7
  int v25; // r8
  int v26; // ctr
  _DWORD *v27; // r11
  _DWORD *p_t; // r9
  int v29; // ctr
  float *v30; // r11
  _DWORD *v31; // r7
  int v32; // ctr
  _DWORD *v33; // r11
  int v34; // r10
  char v35; // r3
  char v36; // r3
  idVec5 *p; // r10
  double a; // fp0
  double v39; // fp13
  double b; // fp0
  double c; // fp0
  double t; // fp10
  double v43; // fp8
  int *v44; // r10
  int v45; // ctr
  float *v46; // r11
  int v47; // r11
  int *v48; // r8
  int v49; // r9
  int v50; // ctr
  _DWORD *v51; // r11
  int v52; // r7
  int v53; // r10
  float *v54; // r9
  float *v55; // r8
  int i; // ctr
  int v57; // [sp+5Ch] [-704h] BYREF
  float d; // [sp+60h] [-700h] BYREF
  float v59; // [sp+64h] [-6FCh]
  float v60; // [sp+68h] [-6F8h]
  float v61; // [sp+6Ch] [-6F4h]
  float v62; // [sp+70h] [-6F0h]
  int v63[20]; // [sp+80h] [-6E0h] BYREF
  idFixedWinding v64; // [sp+D0h] [-690h] BYREF
  float v65[68]; // [sp+5E0h] [-180h] BYREF

  CalculateSides(
    points: this->p,
    numPoints: this->numPoints,
    plane,
    epsilon,
    dists: (float *)a5,
    sides: v65,
    counts: v63,
    a8: &d);
  if ( v59 == 0.0 )
    return LODWORD(d) != 0 ? 0 : 2;
  if ( d == 0.0 )
    return 1;
  v9 = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
  v64.p = v64.data;
  v64.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
  v64.allocedSize = 64;
  *(_DWORD *)(a5 + 4) = 0;
  v10 = 0;
  numPoints = this->numPoints;
  v12 = 0;
  v64.numPoints = 0;
  if ( numPoints > 0 )
  {
    v13 = 0;
    v14 = v65;
    while ( 1 )
    {
      v15 = &this->p[v13];
      if ( v10 + 1 <= v64.allocedSize )
      {
        v16 = 1;
      }
      else
      {
        v16 = ((int (__fastcall *)(idFixedWinding *))v9->ReAllocate)(a1: &v64);
        v10 = v64.numPoints;
      }
      if ( v16 == 0 )
      {
        v64.p = nullptr;
        v64.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
        idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
        return 0;
      }
      if ( *(_DWORD *)(a5 + 4) + 1 <= *(_DWORD *)(a5 + 12) )
      {
        v17 = 1;
      }
      else
      {
        v17 = (*(int (__fastcall **)(int))(*(_DWORD *)a5 + 8))(a1: a5);
        v10 = v64.numPoints;
      }
      if ( v17 == 0 )
      {
LABEL_70:
        idFixedWinding::~idFixedWinding(this: &v64);
        return 0;
      }
      v18 = (char *)v63 + v12;
      v19 = *((unsigned __int8 *)v63 + v12);
      if ( v19 == 2 )
        break;
      if ( *((_BYTE *)v63 + v12) == 0 )
      {
        p_t = (_DWORD *)&v15[-1].t;
        v29 = 5;
        v30 = &v64.p[v10 - 1].t;
        do
        {
          *++v30 = *(float *)++p_t;
          --v29;
        }
        while ( v29 != 0 );
        v10 = ++v64.numPoints;
      }
      if ( v19 == 1 )
      {
        v31 = (_DWORD *)&v15[-1].t;
        v32 = 5;
        v33 = (_DWORD *)(20 * *(_DWORD *)(a5 + 4) + *(_DWORD *)(a5 + 8) - 4);
        do
        {
          *++v33 = *++v31;
          --v32;
        }
        while ( v32 != 0 );
        v10 = v64.numPoints;
        ++*(_DWORD *)(a5 + 4);
      }
      v34 = (unsigned __int8)v18[1];
      if ( v34 != 2 && v34 != v19 )
      {
        if ( v10 + 1 <= v64.allocedSize )
        {
          v35 = 1;
        }
        else
        {
          v35 = ((int (__fastcall *)(idFixedWinding *))v64.ReAllocate)(a1: &v64);
          v10 = v64.numPoints;
        }
        if ( v35 == 0 )
          goto LABEL_70;
        if ( *(_DWORD *)(a5 + 4) + 1 <= *(_DWORD *)(a5 + 12) )
        {
          v36 = 1;
        }
        else
        {
          v36 = (*(int (__fastcall **)(int))(*(_DWORD *)a5 + 8))(a1: a5);
          v10 = v64.numPoints;
        }
        if ( v36 == 0 )
          goto LABEL_70;
        p = this->p;
        if ( (int)&v18[1 - (_DWORD)v63] < this->numPoints )
          p = (idVec5 *)((char *)p + v13 * 20 + 20);
        a = plane->a;
        v39 = (float)(*v14 / (float)(*v14 - v14[1]));
        if ( a == 1.0 )
        {
          d = -plane->d;
        }
        else if ( a == -1.0 )
        {
          d = plane->d;
        }
        else
        {
          d = (float)((float)(p->x - v15->x) * (float)(*v14 / (float)(*v14 - v14[1]))) + v15->x;
        }
        b = plane->b;
        if ( b == 1.0 )
        {
          v59 = -plane->d;
        }
        else if ( b == -1.0 )
        {
          v59 = plane->d;
        }
        else
        {
          v59 = (float)((float)(p->y - v15->y) * (float)v39) + v15->y;
        }
        c = plane->c;
        if ( c == 1.0 )
        {
          v60 = -plane->d;
        }
        else if ( c == -1.0 )
        {
          v60 = plane->d;
        }
        else
        {
          v60 = (float)((float)(p->z - v15->z) * (float)v39) + v15->z;
        }
        t = v15->t;
        v43 = (float)(p->t - v15->t);
        v45 = 5;
        v46 = &v64.p[v10 - 1].t;
        v61 = (float)((float)(p->s - v15->s) * (float)v39) + v15->s;
        v44 = &v57;
        v62 = (float)((float)v43 * (float)v39) + (float)t;
        do
        {
          *(_DWORD *)++v46 = *++v44;
          --v45;
        }
        while ( v45 != 0 );
        v47 = *(_DWORD *)(a5 + 4);
        v48 = &v57;
        v49 = *(_DWORD *)(a5 + 8);
        ++v64.numPoints;
        v50 = 5;
        v51 = (_DWORD *)(20 * v47 + v49 - 4);
        do
        {
          *++v51 = *++v48;
          --v50;
        }
        while ( v50 != 0 );
        goto LABEL_61;
      }
LABEL_62:
      ++v12;
      ++v13;
      ++v14;
      if ( v12 >= this->numPoints )
        goto LABEL_63;
      v9 = v64.__vftable;
    }
    v20 = (_DWORD *)&v15[-1].t;
    v21 = 5;
    v22 = &v64.p[v10 - 1].t;
    do
    {
      *++v22 = *(float *)++v20;
      --v21;
    }
    while ( v21 != 0 );
    v23 = *(_DWORD *)(a5 + 4);
    v24 = (_DWORD *)&v15[-1].t;
    v25 = *(_DWORD *)(a5 + 8);
    ++v64.numPoints;
    v26 = 5;
    v27 = (_DWORD *)(20 * v23 + v25 - 4);
    do
    {
      *++v27 = *++v24;
      --v26;
    }
    while ( v26 != 0 );
LABEL_61:
    v10 = v64.numPoints;
    ++*(_DWORD *)(a5 + 4);
    goto LABEL_62;
  }
LABEL_63:
  v52 = 0;
  if ( v10 > 0 )
  {
    v53 = 0;
    do
    {
      v54 = &this->p[v53 - 1].t;
      v55 = &v64.p[v53 - 1].t;
      for ( i = 5; i != 0; --i )
        *++v54 = *++v55;
      v10 = v64.numPoints;
      ++v52;
      ++v53;
    }
    while ( v52 < v64.numPoints );
  }
  this->numPoints = v10;
  v64.p = nullptr;
  v64.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
  idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
  return 3;
}


// ========================================================================
// __unwind$116087
// EA  : 0x82F2BCD0
// RVA : 0x00F2BCD0
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

void _unwind_116087()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 1888 + 208));
}


// ========================================================================
// ?GetPlane@idWinding@@QBAXAAVidPlane@@@Z
// EA  : 0x82F2BCF8
// RVA : 0x00F2BCF8
// PDB : w:\tech5\shared\idlib\geometry\winding.cpp
// ========================================================================

void __fastcall idWinding::GetPlane(idWinding *this, idPlane *plane)
{
  idVec5 *p; // r11
  double v5; // fp5
  double v6; // fp3
  double v7; // fp7
  double v8; // fp1
  double v9; // fp12
  double v10; // fp11
  idWinding v11; // [sp+50h] [-30h] BYREF

  if ( this->numPoints >= 3 )
  {
    idWinding::GetCenter(this: &v11, result: (idVec3 *)this);
    p = this->p;
    v5 = (float)(p->z - *(float *)&v11.p);
    v6 = (float)(p[1].x - *(float *)&v11.__vftable);
    v7 = (float)(p->y - *(float *)&v11.numPoints);
    v8 = (float)(p[1].y - *(float *)&v11.numPoints);
    v9 = (float)((float)(p[1].y - *(float *)&v11.numPoints) * (float)(p->x - *(float *)&v11.__vftable));
    v10 = (float)((float)(p[1].z - *(float *)&v11.p) * (float)(p->y - *(float *)&v11.numPoints));
    plane->b = (float)((float)(p[1].z - *(float *)&v11.p) * (float)(p->x - *(float *)&v11.__vftable))
             - (float)((float)(p->z - *(float *)&v11.p) * (float)(p[1].x - *(float *)&v11.__vftable));
    plane->c = (float)((float)v7 * (float)v6) - (float)v9;
    plane->a = (float)((float)v8 * (float)v5) - (float)v10;
    idPlane::Normalize(this: plane, fixDegenerate: true);
    plane->d = -(float)((float)(plane->a * this->p->x)
                      + (float)((float)(this->p->z * plane->c) + (float)(this->p->y * plane->b)));
  }
  else
  {
    plane->d = 0.0;
    plane->c = 0.0;
    plane->b = 0.0;
    plane->a = 0.0;
  }
}

