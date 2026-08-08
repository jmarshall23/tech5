
// ========================================================================
// ?GetNumLinks@idRenderModelChain@@QBAHXZ
// EA  : 0x827F83D8
// RVA : 0x007F83D8
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

int __fastcall idRenderModelChain::GetNumLinks(idRenderModelChain *this)
{
  return this->numLinks;
}


// ========================================================================
// ?GetLinkPosition@idRenderModelChain@@QBAABVidJointMat@@H@Z
// EA  : 0x827F83E0
// RVA : 0x007F83E0
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

const idJointMat *__fastcall idRenderModelChain::GetLinkPosition(idRenderModelChain *this, int id)
{
  return &this->transforms.list[id];
}


// ========================================================================
// ?SetLinkPosition@idRenderModelChain@@QAAXHVidVec3@@VidMat3@@@Z
// EA  : 0x827F83F8
// RVA : 0x007F83F8
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void __fastcall idRenderModelChain::SetLinkPosition(
        idRenderModelChain *this,
        int id,
        idVec3 *origin,
        idMat3 *axis,
        int a5,
        int a6,
        int a7,
        int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35)
{
  idJointMat *v27; // r11
  idJointMat *v28; // r11

  v27 = &this->transforms.list[id];
  v27->mat[1] = *(float *)&a6;
  v27->mat[2] = *(float *)&a7;
  v27->mat[4] = *(float *)&a5;
  v27->mat[5] = *(float *)&a6;
  v27->mat[6] = *(float *)&a8;
  v27->mat[8] = *(float *)&a5;
  v27->mat[9] = *(float *)&a7;
  v27->mat[10] = a35;
  v27->mat[0] = *(float *)&axis;
  v28 = &this->transforms.list[id];
  v28->mat[3] = *(float *)&id;
  v28->mat[7] = *(float *)&origin;
  v28->mat[11] = *(float *)&origin;
  *((_BYTE *)this + 2204) |= 0x40u;
}


// ========================================================================
// ?SetLinkMorphAmount@idRenderModelChain@@QAAXHM@Z
// EA  : 0x827F84A0
// RVA : 0x007F84A0
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void __fastcall idRenderModelChain::SetLinkMorphAmount(idRenderModelChain *this, int id, double amount)
{
  int numMorphLinkVertices; // r10
  int v4; // r7
  int v5; // r11
  unsigned __int8 v6; // r8
  int v7; // r11
  int v8; // r10
  unsigned __int8 *v9; // r9

  if ( this->numMorphVertices > 0 )
  {
    numMorphLinkVertices = this->numMorphLinkVertices;
    v4 = 4 * numMorphLinkVertices * id;
    v5 = (int)(float)((float)amount * (float)255.89999);
    if ( v5 >= 0 )
    {
      if ( v5 > 255 )
        LOBYTE(v5) = -1;
    }
    else
    {
      LOBYTE(v5) = 0;
    }
    v6 = v5;
    v7 = 0;
    if ( numMorphLinkVertices > 0 )
    {
      v8 = 0;
      do
      {
        ++v7;
        v9 = &this->morphMap.list[v8];
        v8 += 4;
        v9[v4 + 3] = v6;
      }
      while ( v7 < this->numMorphLinkVertices );
    }
    *((_BYTE *)this + 2204) |= 0x80u;
  }
}


// ========================================================================
// ?RemoveSmoothSkinning@idRenderModelChain@@QAAXH@Z
// EA  : 0x827F8638
// RVA : 0x007F8638
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderModelChain::RemoveSmoothSkinning(idRenderModelChain *this, int id)
{
  idRenderModelSurface *list; // r10
  idJointMat *v5; // r11
  double v6; // fp12
  double v7; // fp9
  double v8; // fp6
  double v9; // fp31
  idTriangles *geometry; // r29
  __int64 v11; // r5 OVERLAPPED
  void *v12; // r3 OVERLAPPED
  int numVerts; // r10
  signed int numLinks; // r9
  int v15; // r11
  int v16; // r10
  int v17; // r11
  unsigned int v18; // r6
  int v19; // r7
  int v20; // r8
  int v21; // r11
  double v22; // fp13
  int v23; // r4
  double v24; // fp13
  int v25; // r4
  double v26; // fp13
  int v27; // r4
  double v28; // fp13
  int v29; // r11
  int v30; // ctr
  double v31; // fp13
  int v32; // r6
  double v33; // fp11

  if ( this->surfaces.num > 0 && id != this->numLinks - 1 )
  {
    list = this->surfaces.list;
    v5 = &this->transforms.list[id];
    v6 = (float)(v5[1].mat[7] - v5->mat[7]);
    v7 = (float)(v5[1].mat[11] - v5->mat[11]);
    v8 = (float)(v5[1].mat[3] - v5->mat[3]);
    v9 = __fsqrts((float)((float)((float)v8 * (float)v8)
                        + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))));
    if ( list != nullptr )
    {
      geometry = list->geometry;
      if ( geometry != nullptr )
      {
        v12 = idVertexBuffer::MapBuffer(this: &geometry->vertexBuffer, mapType: BM_WRITE);
        if ( v12 != nullptr )
        {
          numVerts = geometry->numVerts;
          numLinks = this->numLinks;
          v15 = __ROL4__(numVerts, 1);
          v16 = numVerts / numLinks;
          v18 = numLinks & ~(v15 - 1);
          v17 = v16 * id;
          v19 = v16 * id + v16;
          __twllei(numLinks, 0);
          __twlgei(v18, 0xFFFFFFFF);
          v20 = v16 * id;
          if ( v16 * id < v19 )
          {
            LODWORD(v11) = v19 - v17;
            if ( v19 - v17 >= 4 )
            {
              v21 = (int)v12 + 32 * v17 - 5;
              do
              {
                v22 = 0.0;
                if ( *(unsigned __int8 *)(v21 + 33) != id )
                {
                  LODWORD(v11) = 255 - *(unsigned __int8 *)(v21 + 32);
                  HIDWORD(v11) = v11;
                  v22 = (float)((float)((float)*(__int64 *)((char *)&v11 + 4) * (float)v9) * (float)0.0039215689);
                }
                HIDWORD(v11) = *(unsigned __int8 *)(v21 + 34);
                if ( HIDWORD(v11) != id )
                {
                  LODWORD(v11) = *(unsigned __int8 *)(v21 + 32);
                  v22 = (float)((float)((float)((float)v11 * (float)v9) * (float)0.0039215689) + (float)v22);
                }
                v23 = *(unsigned __int8 *)(v21 + 65);
                *(float *)(v21 + 13) = *(float *)(v21 + 13) + (float)v22;
                *(_BYTE *)(v21 + 33) = id;
                v24 = 0.0;
                *(_BYTE *)(v21 + 34) = id;
                *(_BYTE *)(v21 + 35) = id;
                *(_BYTE *)(v21 + 36) = id;
                *(_BYTE *)(v21 + 28) = 0;
                *(_BYTE *)(v21 + 32) = 0;
                if ( v23 != id )
                {
                  LODWORD(v11) = 255 - *(unsigned __int8 *)(v21 + 64);
                  HIDWORD(v11) = v11;
                  v24 = (float)((float)((float)*(__int64 *)((char *)&v11 + 4) * (float)v9) * (float)0.0039215689);
                }
                HIDWORD(v11) = *(unsigned __int8 *)(v21 + 66);
                if ( HIDWORD(v11) != id )
                {
                  LODWORD(v11) = *(unsigned __int8 *)(v21 + 64);
                  v24 = (float)((float)((float)((float)v11 * (float)v9) * (float)0.0039215689) + (float)v24);
                }
                v25 = *(unsigned __int8 *)(v21 + 97);
                *(float *)(v21 + 45) = *(float *)(v21 + 45) + (float)v24;
                *(_BYTE *)(v21 + 65) = id;
                v26 = 0.0;
                *(_BYTE *)(v21 + 66) = id;
                *(_BYTE *)(v21 + 67) = id;
                *(_BYTE *)(v21 + 68) = id;
                *(_BYTE *)(v21 + 60) = 0;
                *(_BYTE *)(v21 + 64) = 0;
                if ( v25 != id )
                {
                  LODWORD(v11) = 255 - *(unsigned __int8 *)(v21 + 96);
                  HIDWORD(v11) = v11;
                  v26 = (float)((float)((float)*(__int64 *)((char *)&v11 + 4) * (float)v9) * (float)0.0039215689);
                }
                HIDWORD(v11) = *(unsigned __int8 *)(v21 + 98);
                if ( HIDWORD(v11) != id )
                {
                  LODWORD(v11) = *(unsigned __int8 *)(v21 + 96);
                  v26 = (float)((float)((float)((float)v11 * (float)v9) * (float)0.0039215689) + (float)v26);
                }
                v27 = *(unsigned __int8 *)(v21 + 129);
                *(float *)(v21 + 77) = *(float *)(v21 + 77) + (float)v26;
                *(_BYTE *)(v21 + 97) = id;
                v28 = 0.0;
                *(_BYTE *)(v21 + 98) = id;
                *(_BYTE *)(v21 + 99) = id;
                *(_BYTE *)(v21 + 100) = id;
                *(_BYTE *)(v21 + 92) = 0;
                *(_BYTE *)(v21 + 96) = 0;
                if ( v27 != id )
                {
                  LODWORD(v11) = 255 - *(unsigned __int8 *)(v21 + 128);
                  HIDWORD(v11) = v11;
                  v28 = (float)((float)((float)*(__int64 *)((char *)&v11 + 4) * (float)v9) * (float)0.0039215689);
                }
                HIDWORD(v11) = *(unsigned __int8 *)(v21 + 130);
                if ( HIDWORD(v11) != id )
                {
                  LODWORD(v11) = *(unsigned __int8 *)(v21 + 128);
                  v28 = (float)((float)((float)((float)v11 * (float)v9) * (float)0.0039215689) + (float)v28);
                }
                v20 += 4;
                *(float *)(v21 + 109) = *(float *)(v21 + 109) + (float)v28;
                *(_BYTE *)(v21 + 129) = id;
                *(_BYTE *)(v21 + 130) = id;
                *(_BYTE *)(v21 + 131) = id;
                *(_BYTE *)(v21 + 132) = id;
                *(_BYTE *)(v21 + 124) = 0;
                v21 += 128;
                *(_BYTE *)v21 = 0;
              }
              while ( v20 < v19 - 3 );
            }
            if ( v20 < v19 )
            {
              v29 = (int)v12 + 32 * v20 - 5;
              v30 = v19 - v20;
              do
              {
                v31 = 0.0;
                if ( *(unsigned __int8 *)(v29 + 33) != id )
                {
                  LODWORD(v11) = 255 - *(unsigned __int8 *)(v29 + 32);
                  v31 = (float)((float)((float)v11 * (float)v9) * (float)0.0039215689);
                }
                if ( *(unsigned __int8 *)(v29 + 34) != id )
                {
                  v32 = *(unsigned __int8 *)(v29 + 32);
                  v31 = (float)((float)((float)((float)*(__int64 *)((char *)&v11 - 4) * (float)v9) * (float)0.0039215689)
                              + (float)v31);
                }
                v33 = *(float *)(v29 + 13);
                *(_BYTE *)(v29 + 33) = id;
                *(float *)(v29 + 13) = (float)v33 + (float)v31;
                *(_BYTE *)(v29 + 34) = id;
                *(_BYTE *)(v29 + 35) = id;
                *(_BYTE *)(v29 + 36) = id;
                *(_BYTE *)(v29 + 28) = 0;
                v29 += 32;
                *(_BYTE *)v29 = 0;
                --v30;
              }
              while ( v30 != 0 );
            }
          }
          idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&geometry->vertexBuffer);
        }
      }
    }
  }
}


// ========================================================================
// ?Save@idRenderModelChain@@UBAXPAVidFile@@@Z
// EA  : 0x827F8A10
// RVA : 0x007F8A10
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void __fastcall idRenderModelChain::Save(idRenderModelChain *this, idFile *fp)
{
  idFile_vtbl *v4; // r10
  const idMaterial *morphMaterial; // r11
  idFile_vtbl *v6; // r10
  int v7; // r29
  int v8; // r28
  idRenderModelChain::splinePoint_t *v9; // r27
  int *p_numLinks; // r27
  int v11; // r28
  int v12; // r29
  idJointMat *v13; // r11
  double v14; // fp0
  double v15; // fp13
  double v16; // fp12
  double v17; // fp11
  double v18; // fp10
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  double v20; // fp9
  double v21; // fp8
  double v22; // fp7
  idJointMat *v23; // r11
  unsigned int (__fastcall *v24)(idFile *, const void *, unsigned int); // r7
  double v25; // fp5
  double v26; // fp4
  idFile_vtbl *v27; // r10
  int i; // r29
  unsigned int (__fastcall *v29)(idFile *, const void *, unsigned int); // ctr
  bool v30; // [sp+50h] [-80h] BYREF
  unsigned __int8 v31[3]; // [sp+51h] [-7Fh] BYREF
  int num; // [sp+54h] [-7Ch] BYREF
  float v33[6]; // [sp+58h] [-78h] BYREF
  float v34[24]; // [sp+70h] [-60h] BYREF

  idRenderModel::Save(this, fp);
  v4 = fp->__vftable;
  v30 = this->morphMaterial != nullptr;
  v4->Write(this: fp, a2: &v30, a3: 1u);
  morphMaterial = this->morphMaterial;
  if ( morphMaterial != nullptr )
    idFile::WriteString(this: fp, string: morphMaterial->name.str);
  idFile::WriteString(this: fp, string: &this->chainLinkModel);
  v6 = fp->__vftable;
  num = this->splineSettings.num;
  v6->Write(this: fp, a2: &num, a3: 4u);
  v7 = 0;
  if ( num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = &this->splineSettings.list[v8];
      fp->Write(this: fp, a2: v9, a3: 12u);
      fp->Write(this: fp, a2: &v9->time, a3: 4u);
      ++v7;
      ++v8;
    }
    while ( v7 < num );
  }
  fp->Write(this: fp, a2: &this->genInfo, a3: 1u);
  fp->Write(this: fp, a2: &this->genInfo.smoothSkinning, a3: 1u);
  fp->Write(this: fp, a2: &this->genInfo.startRotation, a3: 4u);
  p_numLinks = &this->numLinks;
  fp->Write(this: fp, a2: &this->numLinks, a3: 4u);
  v11 = 0;
  if ( this->numLinks > 0 )
  {
    v12 = 0;
    do
    {
      v13 = &this->transforms.list[v12];
      v14 = v13->mat[10];
      v15 = v13->mat[6];
      v16 = v13->mat[2];
      v17 = v13->mat[9];
      v18 = v13->mat[5];
      Write = fp->Write;
      v20 = v13->mat[1];
      v21 = v13->mat[8];
      v22 = v13->mat[4];
      v34[0] = v13->mat[0];
      v34[1] = v22;
      v34[2] = v21;
      v34[3] = v20;
      v34[4] = v18;
      v34[5] = v17;
      v34[6] = v16;
      v34[7] = v15;
      v34[8] = v14;
      Write(this: fp, a2: v34, a3: 36u);
      v23 = &this->transforms.list[v12];
      v24 = fp->Write;
      v25 = v23->mat[11];
      v26 = v23->mat[7];
      v33[0] = v23->mat[3];
      v33[1] = v26;
      v33[2] = v25;
      v24(this: fp, a2: v33, a3: 12u);
      ++v11;
      ++v12;
    }
    while ( v11 < *p_numLinks );
  }
  v27 = fp->__vftable;
  v30 = this->numMorphVertices != 0;
  v27->Write(this: fp, a2: &v30, a3: 1u);
  if ( this->numMorphVertices != 0 )
  {
    for ( i = 0; i < *p_numLinks; ++i )
    {
      v29 = fp->Write;
      v31[0] = this->morphMap.list[4 * i * this->numMorphLinkVertices + 3];
      v29(this: fp, a2: v31, a3: 1u);
    }
  }
}


// ========================================================================
// ?CommitSubclass@idRenderModelChain@@EAA_NXZ
// EA  : 0x827F8CE0
// RVA : 0x007F8CE0
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

int __fastcall idRenderModelChain::CommitSubclass(idRenderModelChain *this)
{
  int num; // r5
  idJointMat *list; // r4
  int v4; // r11
  int v5; // r30
  int v6; // r29
  int v7; // r9
  idJointMat *v14; // r8
  int v15; // r10
  int v22; // r5
  unsigned __int8 *v23; // r4
  int v24; // r11
  int v25; // r29
  int v26; // r30
  idRenderModelSurface *v27; // r10
  idTriangles *geometry; // r11
  int numVerts; // r9
  idVertexBuffer *morphMap; // r3

  if ( (*((_BYTE *)this + 2204) & 0x40) != 0 )
  {
    num = this->transforms.num;
    list = this->transforms.list;
    v4 = (this->currentJointBuffer + 1) % 2;
    this->currentJointBuffer = v4;
    idJointBuffer::Update(this: &this->jointBuffers[v4], joints: list->mat, numUpdateJoints: num);
    v5 = 0;
    if ( this->surfaces.num > 0 )
    {
      v6 = 0;
      do
      {
        idJointBuffer::Reference(
          this: this->surfaces.list[v6].joints,
          other: &this->jointBuffers[this->currentJointBuffer],
          jointRefOffset: 0,
          numRefJoints: this->transforms.num);
        ++v5;
        ++v6;
      }
      while ( v5 < this->surfaces.num );
    }
    v7 = 0;
    _FP0 = 1.0e30;
    _FP11 = -1.0e30;
    _FP12 = 1.0e30;
    _FP13 = 1.0e30;
    _FP9 = -1.0e30;
    _FP10 = -1.0e30;
    if ( this->transforms.num > 0 )
    {
      v14 = this->transforms.list;
      v15 = 0;
      do
      {
        ++v7;
        _FP6 = (float)((float)_FP0 - v14[v15].mat[3]);
        _FP4 = (float)((float)_FP13 - v14[v15].mat[7]);
        _FP3 = (float)((float)_FP12 - v14[v15].mat[11]);
        _FP2 = (float)(v14[v15].mat[3] - (float)_FP11);
        _FP1 = (float)(v14[v15].mat[7] - (float)_FP10);
        _FP31 = (float)(v14[v15++].mat[11] - (float)_FP9);
        __asm
        {
          fsel      f0, f6, f8, f0
          fsel      f13, f4, f7, f13
          fsel      f12, f3, f5, f12
          fsel      f11, f2, f8, f11
          fsel      f10, f1, f7, f10
          fsel      f9, f31, f5, f9
        }
      }
      while ( v7 < this->transforms.num );
    }
    this->referenceBounds.b[0].x = (float)_FP0 - (float)8.0;
    this->referenceBounds.b[0].y = (float)_FP13 - (float)8.0;
    this->referenceBounds.b[0].z = (float)_FP12 - (float)8.0;
    this->referenceBounds.b[1].x = (float)_FP11 + (float)8.0;
    this->referenceBounds.b[1].y = (float)_FP10 + (float)8.0;
    this->referenceBounds.b[1].z = (float)_FP9 + (float)8.0;
    *((_BYTE *)this + 2204) &= ~0x40u;
  }
  if ( (*((_BYTE *)this + 2204) & 0x80) != 0 )
  {
    v22 = this->morphMap.num;
    v23 = this->morphMap.list;
    v24 = (this->currentMorphBuffer + 1) % 2;
    this->currentMorphBuffer = v24;
    idVertexBuffer::Update(this: &this->morphBuffers[v24], data: v23, updateSize: v22, vertexMask: 4);
    v25 = 0;
    if ( this->surfaces.num > 0 )
    {
      v26 = 0;
      do
      {
        v27 = &this->surfaces.list[v26];
        geometry = v27->geometry;
        if ( geometry != nullptr )
          numVerts = geometry->numVerts;
        else
          numVerts = 0;
        morphMap = v27->morphMap;
        if ( morphMap != nullptr )
          idVertexBuffer::Reference(
            this: morphMap,
            other: &this->morphBuffers[this->currentMorphBuffer],
            refOffset: 0,
            refSize: 4 * numVerts);
        ++v25;
        ++v26;
      }
      while ( v25 < this->surfaces.num );
    }
    *((_BYTE *)this + 2204) &= ~0x80u;
  }
  return 1;
}


// ========================================================================
// ??0idRenderModelChain@@QAA@XZ
// EA  : 0x827F90C8
// RVA : 0x007F90C8
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

idRenderModelChain *__fastcall idRenderModelChain::idRenderModelChain(idRenderModelChain *this)
{
  char v2; // r10

  idRenderModel::idRenderModel(this);
  this->__vftable = (idRenderModelChain_vtbl *)&idRenderModelChain::`vftable';
  `eh vector constructor iterator'(
    ptr: this->jointBuffers,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idJointBuffer::idJointBuffer,
    pDtor: (void (__fastcall *)(void *))idJointBuffer::~idJointBuffer);
  `eh vector constructor iterator'(
    ptr: this->morphBuffers,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  this->currentJointBuffer = 0;
  this->currentMorphBuffer = 0;
  this->numMorphVertices = 0;
  this->linkSize = 0.0;
  this->numMorphLinkVertices = 0;
  this->numLinks = 0;
  this->transforms.list = nullptr;
  this->transforms.granularity = 0;
  this->transforms.memTag = 85;
  this->transforms.listStatic = 0;
  this->transforms.size = 0;
  this->transforms.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->transforms);
  this->morphMap.list = nullptr;
  this->morphMap.granularity = 0;
  this->morphMap.memTag = 85;
  this->morphMap.listStatic = 0;
  this->morphMap.size = 0;
  this->morphMap.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->morphMap);
  this->splineSettings.list = nullptr;
  this->splineSettings.granularity = 0;
  this->splineSettings.memTag = 85;
  this->splineSettings.listStatic = 0;
  this->splineSettings.size = 0;
  this->splineSettings.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineSettings);
  idStr::idStr(this: &this->chainLinkModel, text: &byte_8200D768);
  v2 = *((_BYTE *)this + 2204);
  this->morphMaterial = nullptr;
  *((_BYTE *)this + 2204) = v2 & 0x3F;
  this->genInfo.startRotation = 0.0;
  this->genInfo.rotateRandom = true;
  this->genInfo.smoothSkinning = false;
  return this;
}


// ========================================================================
// __unwind$227403
// EA  : 0x827F9204
// RVA : 0x007F9204
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227403()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$227404
// EA  : 0x827F922C
// RVA : 0x007F922C
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227404()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 2032),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idJointBuffer::~idJointBuffer);
}


// ========================================================================
// __unwind$227405
// EA  : 0x827F9268
// RVA : 0x007F9268
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227405()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 2064),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$227406
// EA  : 0x827F92A4
// RVA : 0x007F92A4
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227406()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2120));
}


// ========================================================================
// __unwind$227407
// EA  : 0x827F92D0
// RVA : 0x007F92D0
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227407()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2136));
}


// ========================================================================
// __unwind$227408
// EA  : 0x827F92FC
// RVA : 0x007F92FC
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227408()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2152));
}


// ========================================================================
// ??1idRenderModelChain@@UAA@XZ
// EA  : 0x827F9330
// RVA : 0x007F9330
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void __fastcall idRenderModelChain::~idRenderModelChain(idRenderModelChain *this)
{
  this->__vftable = (idRenderModelChain_vtbl *)&idRenderModelChain::`vftable';
  idStr::FreeData(this: &this->chainLinkModel);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineSettings);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->morphMap);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->transforms);
  `eh vector destructor iterator'(
    ptr: this->morphBuffers,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  `eh vector destructor iterator'(
    ptr: this->jointBuffers,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idJointBuffer::~idJointBuffer);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$227532
// EA  : 0x827F93CC
// RVA : 0x007F93CC
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227532()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$227533
// EA  : 0x827F93F4
// RVA : 0x007F93F4
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227533()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 2032),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idJointBuffer::~idJointBuffer);
}


// ========================================================================
// __unwind$227534
// EA  : 0x827F9430
// RVA : 0x007F9430
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227534()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 2064),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$227535
// EA  : 0x827F946C
// RVA : 0x007F946C
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227535()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 2120));
}


// ========================================================================
// __unwind$227536
// EA  : 0x827F9498
// RVA : 0x007F9498
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227536()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 2136));
}


// ========================================================================
// __unwind$227537
// EA  : 0x827F94C4
// RVA : 0x007F94C4
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_227537()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 2152));
}


// ========================================================================
// ?BuildModel@idRenderModelChain@@AAAXABV?$idCurve_NURBS@VidVec3@@@@@Z
// EA  : 0x827F9B30
// RVA : 0x007F9B30
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void __fastcall idRenderModelChain::BuildModel(idRenderModelChain *this, idVec3 *spline)
{
  const idStaticModel *v4; // r3
  const idStaticModel *v5; // r15
  int *v6; // r10
  bool *p_modelIsAutosprite; // r11
  int i; // ctr
  double v9; // fp31
  double v10; // fp28
  double v11; // fp29
  double v12; // fp25
  double v13; // fp30
  double v14; // fp1
  double v16; // fp26
  int x_low; // r10
  encounterGroupRole_t *list; // r9
  signed int numIndexes; // r27
  char v21; // r26
  int v22; // r28
  int v23; // r29
  idTriangles *StandardTriangles; // r3
  BOOL smoothSkinning; // r11
  idTriangles *v26; // r30
  int numVerts; // r11
  bool v28; // zf
  int v29; // r6
  int v30; // r11
  double v31; // fp0
  unsigned __int8 v32; // r10
  char v33; // r8
  char v34; // r9
  unsigned __int8 v35; // r7
  int v36; // r10
  int v37; // r11
  int v38; // r10
  int numLinks; // r11
  int num; // r10
  int v41; // r9
  idJointBuffer *jointBuffers; // r29
  int j; // r30
  idVertexBuffer *morphBuffers; // r29
  int k; // r30
  idList<unsigned char,85> *p_morphMap; // r30
  int m; // r11
  unsigned __int8 *v48; // r6
  idList<idJointMat,85> *p_transforms; // r30
  int v50; // r4
  char *data; // r10
  int v52; // r28
  unsigned __int8 n; // r9
  double v54; // fp13
  double v55; // fp24
  idVec3 *z_low; // r11
  idVec3 *v57; // r10
  float z; // r8
  float x; // r7
  float v60; // r6
  float v61; // r11
  float y; // r10
  double v63; // fp27
  double v64; // fp28
  double v65; // fp26
  double v67; // fp1
  double v69; // fp12
  double v70; // fp8
  double v71; // fp13
  double v72; // fp12
  double v73; // fp29
  double v74; // fp30
  double v75; // fp31
  double v76; // fp25
  int v77; // r29
  __int64 v78; // r8
  double v79; // fp25
  double v80; // fp23
  double v81; // fp22
  double v82; // fp21
  double v83; // fp20
  double v84; // fp19
  double v85; // fp18
  __int64 v86; // r11
  double v87; // fp29
  double v88; // fp31
  double v89; // fp30
  const idMat3 *v90; // r3
  int size; // r10
  int v92; // r11
  idJointMat *v93; // r9
  float *mat; // r11
  double v95; // fp13
  double v96; // fp11
  double v97; // fp10
  double v98; // fp9
  double v99; // fp8
  double v100; // fp7
  double v101; // fp6
  int v102; // r29
  int v103; // r10
  double v104; // fp26
  __int64 v105; // r11
  int v106; // r27
  double TimeForLength; // fp29
  __int64 v108; // r10
  double v109; // fp28
  double v110; // fp6
  double v111; // fp3
  double v112; // fp13
  double v115; // fp5
  double v116; // fp10
  double v117; // fp29
  double v118; // fp28
  double v119; // fp27
  const idMat3 *v120; // r3
  idJointMat *v121; // r9
  double v122; // fp13
  double v123; // fp12
  double v124; // fp11
  double v125; // fp10
  double v126; // fp9
  double v127; // fp8
  double v128; // fp6
  int ii; // r19
  encounterGroupRole_t v130; // r30
  int v131; // r20
  idTriangles *v132; // r3
  idTriangles *v133; // r27
  idJointBuffer *v134; // r3
  idJointBuffer *v135; // r21
  int v136; // r10
  int v137; // r25
  int v138; // r23
  int jj; // r26
  int v140; // r10
  int v141; // r7
  int v142; // r8
  int v143; // r11
  int v144; // r7
  int v145; // r10
  int v146; // r28
  int v147; // r11
  int v148; // r29
  int v149; // r10
  char v150; // r7
  char v151; // r4
  char v152; // r7
  char v153; // r5
  int v154; // r6
  __int16 v155; // r8
  int v156; // r10
  int v157; // r7
  int v158; // r11
  float v159; // r9
  float v160; // r8
  __int64 v161; // r28
  idIndexBuffer *v162; // r3
  idVertexBuffer *v163; // r29
  idJointBuffer *v164; // r3
  idIndexBuffer *v165; // r3
  idVertexBuffer *v166; // r29
  const idMaterial *morphMaterial; // r8
  __int64 v168; // r8
  __int64 v169; // [sp+8h] [-368h]
  __int64 v170; // [sp+10h] [-360h]
  __int64 v171; // [sp+18h] [-358h]
  __int64 v172; // [sp+20h] [-350h]
  __int64 v173; // [sp+28h] [-348h]
  __int64 v174; // [sp+30h] [-340h]
  __int64 v175; // [sp+38h] [-338h]
  __int64 v176; // [sp+40h] [-330h]
  __int64 v177; // [sp+48h] [-328h]
  __int64 v178; // [sp+50h] [-320h]
  bool v179; // [sp+60h] [-310h] BYREF
  idVec3 v180; // [sp+68h] [-308h] BYREF
  __int64 v181; // [sp+78h] [-2F8h]
  float v182; // [sp+80h] [-2F0h]
  idVec3 v183; // [sp+88h] [-2E8h] BYREF
  idMat3 v184; // [sp+A0h] [-2D0h] BYREF
  int v185; // [sp+C4h] [-2ACh]
  float v186; // [sp+C8h] [-2A8h]
  float v187; // [sp+CCh] [-2A4h]
  __int64 v188; // [sp+D0h] [-2A0h]
  idVec3 v189; // [sp+D8h] [-298h] BYREF
  float v190[6]; // [sp+E8h] [-288h] BYREF
  idMat3 v191; // [sp+100h] [-270h] BYREF
  int v192; // [sp+12Ch] [-244h] BYREF
  float v193; // [sp+130h] [-240h] BYREF
  float v194; // [sp+134h] [-23Ch]
  float v195; // [sp+138h] [-238h]
  float v196; // [sp+13Ch] [-234h]
  float v197; // [sp+140h] [-230h]
  float v198; // [sp+144h] [-22Ch]
  idVec3 v199[2]; // [sp+148h] [-228h] BYREF
  idMat3 v200; // [sp+160h] [-210h] BYREF
  int v201; // [sp+184h] [-1ECh]
  unsigned int v202; // [sp+188h] [-1E8h]
  float v203; // [sp+18Ch] [-1E4h]
  __int64 v204; // [sp+190h] [-1E0h]
  float v205[4]; // [sp+198h] [-1D8h] BYREF
  idVec3 v206; // [sp+1A8h] [-1C8h] BYREF
  idVec3 v207; // [sp+1B8h] [-1B8h] BYREF
  idList<enum encounterGroupRole_t,5> v208; // [sp+1D0h] [-1A0h] BYREF
  _BYTE v209[256]; // [sp+1E0h] [-190h] BYREF

  this->FreeSurfaces(this);
  v4 = staticModelManager->FindStaticModel(this: staticModelManager, a2: this->chainLinkModel.data, a3: true);
  v5 = v4;
  if ( v4 == nullptr )
    return;
  v6 = &v192;
  p_modelIsAutosprite = &v4->modelIsAutosprite;
  for ( i = 6; i != 0; --i )
  {
    p_modelIsAutosprite += 4;
    *++v6 = *(_DWORD *)p_modelIsAutosprite;
  }
  v9 = (float)(v197 - v194);
  v10 = v195;
  v11 = (float)(v198 - v195);
  v12 = (float)(v196 - v193);
  v13 = (float)-(float)((float)((float)(v197 - v194) * (float)2.0) - (float)(v198 - v195));
  v14 = ((double (__fastcall *)(idVec3 *, double))*(_DWORD *)(LODWORD(spline->x) + 36))(
          a1: spline,
          a2: *(float *)(4 * LODWORD(spline[2].x) + LODWORD(spline->y) - 4));
  _FP9 = (float)((float)v12 - (float)v13);
  v16 = v14;
  __asm { fsel      f0, f9, f25, f30 }
  if ( _FP0 > v9 )
  {
    if ( _FP0 > v11 )
      goto LABEL_7;
    goto LABEL_6;
  }
  if ( v9 <= v11 )
  {
LABEL_6:
    _FP0 = v11;
    goto LABEL_7;
  }
  _FP0 = v9;
LABEL_7:
  this->linkSize = _FP0;
  this->numLinks = 1;
  if ( v14 > v11 )
  {
    LODWORD(v180.y) = (int)(float)((float)((float)((float)v14 - (float)v11) / (float)v13) + (float)0.94999999);
    this->numLinks = abs32(SLODWORD(v180.y)) + 1;
  }
  if ( this->numLinks >= 1 )
  {
    x_low = LODWORD(spline[2].x);
    v208.granularity = 1;
    v208.listStatic = 1;
    v208.num = 0;
    v208.size = 32;
    list = (encounterGroupRole_t *)v209;
    numIndexes = 0;
    v208.memTag = 5;
    v208.list = (encounterGroupRole_t *)v209;
    v21 = ((unsigned int)x_low <= 2) + (x_low < 0);
    v22 = 0;
    if ( v5->surfaces.num > 0 )
    {
      v23 = 0;
      do
      {
        StandardTriangles = idTriangles::CreateStandardTriangles(this: v5->surfaces.list[v23].geometry);
        smoothSkinning = this->genInfo.smoothSkinning;
        v26 = StandardTriangles;
        LODWORD(v180.x) = StandardTriangles;
        v28 = !smoothSkinning;
        numVerts = StandardTriangles->numVerts;
        if ( v28 )
        {
          v36 = 0;
          if ( numVerts > 0 )
          {
            v37 = 0;
            do
            {
              ++v36;
              StandardTriangles->verts[v37].color[0] = 0;
              StandardTriangles->verts[v37].color[1] = 0;
              StandardTriangles->verts[v37].color[2] = 0;
              StandardTriangles->verts[v37].color[3] = 0;
              StandardTriangles->verts[v37].tangent[3] = 0;
              StandardTriangles->verts[v37++].normal[3] = 0;
            }
            while ( v36 < StandardTriangles->numVerts );
          }
        }
        else
        {
          v29 = 0;
          if ( numVerts > 0 )
          {
            v30 = 0;
            do
            {
              v31 = (float)((float)(StandardTriangles->verts[v30].xyz.z - (float)v10) * (float)((float)1.0 / (float)v11));
              if ( v31 >= 0.0 )
              {
                if ( v31 > 1.0 )
                  v31 = 1.0;
              }
              else
              {
                v31 = 0.0;
              }
              LODWORD(v181) = (int)(float)((float)v31 * (float)255.10001);
              v32 = v181;
              if ( (int)v181 >= 0 )
              {
                if ( (int)v181 > 255 )
                  v32 = -1;
              }
              else
              {
                v32 = 0;
              }
              v33 = 0;
              v34 = 1;
              v35 = -1 - v32;
              if ( v32 > 0x7Fu )
              {
                v35 = v32;
                v32 = -1 - v32;
                v33 = 1;
                v34 = 0;
              }
              if ( v35 == 255 )
              {
                v32 = 0;
                v34 = v33;
              }
              ++v29;
              StandardTriangles->verts[v30].color[0] = v33;
              StandardTriangles->verts[v30].color[1] = v34;
              StandardTriangles->verts[v30].color[2] = v33;
              StandardTriangles->verts[v30].color[3] = v33;
              StandardTriangles->verts[v30].tangent[3] = v32;
              StandardTriangles->verts[v30++].normal[3] = 0;
            }
            while ( v29 < StandardTriangles->numVerts );
          }
        }
        idList<idAnimWebBlendTree *,5>::Append(this: &v208, obj: (const encounterGroupRole_t *)&v180);
        if ( numIndexes <= v26->numIndexes )
          numIndexes = v26->numIndexes;
        ++v22;
        ++v23;
      }
      while ( v22 < v5->surfaces.num );
      list = v208.list;
    }
    __twllei(numIndexes, 0);
    v38 = 0x10000 / numIndexes;
    if ( 0x10000 / numIndexes >= 256 )
      v38 = 256;
    numLinks = this->numLinks;
    if ( numLinks >= v38 )
      numLinks = v38;
    num = v208.num;
    this->numLinks = numLinks;
    if ( num > 0 && this->morphMaterial != nullptr )
    {
      v41 = *(_DWORD *)(*list + 32);
      this->numMorphVertices = v41 * numLinks;
      this->numMorphLinkVertices = v41;
    }
    jointBuffers = this->jointBuffers;
    for ( j = 2; j != 0; --j )
      idJointBuffer::AllocBufferObject(this: jointBuffers++, joints: nullptr, numAllocJoints: this->numLinks);
    if ( this->numMorphVertices > 0 )
    {
      morphBuffers = this->morphBuffers;
      for ( k = 2; k != 0; --k )
        idVertexBuffer::AllocBufferObject(
          this: morphBuffers++,
          data: nullptr,
          allocSize: 4 * this->numMorphVertices,
          vertexMask: 4,
          allocUsage: BU_DYNAMIC);
      v179 = false;
      p_morphMap = &this->morphMap;
      idList<bool,5>::SetNum(
        this: (idList<bool,5> *)&this->morphMap,
        newNum: 4 * this->numMorphVertices,
        initValue: &v179);
      for ( m = 0; m < this->morphMap.num; v48[3] = 0 )
      {
        p_morphMap->list[m] = 127;
        p_morphMap->list[m + 1] = 127;
        p_morphMap->list[m + 2] = 127;
        v48 = &p_morphMap->list[m];
        m += 4;
      }
      *((_BYTE *)this + 2204) |= 0x80u;
    }
    p_transforms = &this->transforms;
    v50 = this->numLinks;
    *((_BYTE *)this + 2204) |= 0x40u;
    if ( v50 > this->transforms.size )
      idList<idJointMat,59>::Resize(this: (idList<idJointMat,59> *)&this->transforms, newsize: v50);
    data = this->chainLinkModel.data;
    v52 = 0;
    for ( n = *data; *data != 0; n = *data )
    {
      ++data;
      v52 = 31 * v52 + n;
    }
    if ( this->genInfo.rotateRandom )
      v54 = 90.0;
    else
      v54 = 0.0;
    v55 = (float)(this->genInfo.startRotation * idMath::M_DEG2RAD);
    v195 = (float)v54 * idMath::M_DEG2RAD;
    v193 = (float)((float)v54 * (float)0.0) * idMath::M_DEG2RAD;
    v194 = (float)((float)v54 * (float)2.0) * idMath::M_DEG2RAD;
    v196 = (float)((float)v54 * (float)3.0) * idMath::M_DEG2RAD;
    if ( v21 != 0 )
    {
      z_low = (idVec3 *)LODWORD(spline[1].z);
      v57 = &z_low[LODWORD(spline[2].x)];
      z = z_low->z;
      x = z_low->x;
      LODWORD(v181) = LODWORD(z_low->y);
      v60 = v57[-1].z;
      v61 = v57[-1].x;
      y = v57[-1].y;
      v182 = z;
      *(float *)&v181 = x;
      v63 = x;
      v183.z = v60;
      v183.x = v61;
      v183.y = y;
      v64 = *((float *)&v181 + 1);
      v65 = z;
      _FP2 = (float)((float)((float)((float)(v60 - z) * (float)(v60 - z))
                           + (float)((float)((float)(v61 - x) * (float)(v61 - x))
                                   + (float)((float)(y - *((float *)&v181 + 1)) * (float)(y - *((float *)&v181 + 1)))))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v67 = (float)((float)((float)((float)(v60 - z) * (float)(v60 - z))
                          + (float)((float)((float)(v61 - x) * (float)(v61 - x))
                                  + (float)((float)(y - *((float *)&v181 + 1)) * (float)(y - *((float *)&v181 + 1)))))
                  * (float)0.5);
      __asm { fsel      f13, f2, f3, f13 }
      v69 = __frsqrte(_FP13);
      v70 = (float)-(float)((float)((float)((float)v69
                                          * (float)((float)((float)((float)(v60 - z) * (float)(v60 - z))
                                                          + (float)((float)((float)(v61 - x) * (float)(v61 - x))
                                                                  + (float)((float)(y - *((float *)&v181 + 1))
                                                                          * (float)(y - *((float *)&v181 + 1)))))
                                                  * (float)0.5))
                                  * (float)v69)
                          - (float)1.5);
      v71 = (float)((float)-(float)((float)((float)((float)((float)v70 * (float)v69)
                                                  * (float)((float)((float)((float)(v60 - z) * (float)(v60 - z))
                                                                  + (float)((float)((float)(v61 - x) * (float)(v61 - x))
                                                                          + (float)((float)(y - *((float *)&v181 + 1))
                                                                                  * (float)(y - *((float *)&v181 + 1)))))
                                                          * (float)0.5))
                                          * (float)((float)v70 * (float)v69))
                                  - (float)1.5)
                  * (float)((float)v70 * (float)v69));
      v72 = (float)((float)((float)-(float)((float)((float)((float)((float)v70 * (float)v69) * (float)v67)
                                                  * (float)((float)v70 * (float)v69))
                                          - (float)1.5)
                          * (float)((float)v70 * (float)v69))
                  * (float)v67);
      v73 = (float)((float)(v61 - x)
                  * (float)((float)-(float)((float)((float)v72 * (float)v71) - (float)1.5) * (float)v71));
      v189.x = (float)(v61 - x) * (float)((float)-(float)((float)((float)v72 * (float)v71) - (float)1.5) * (float)v71);
      v74 = (float)((float)(y - *((float *)&v181 + 1))
                  * (float)((float)-(float)((float)((float)v72 * (float)v71) - (float)1.5) * (float)v71));
      v189.y = (float)(y - *((float *)&v181 + 1))
             * (float)((float)-(float)((float)((float)v72 * (float)v71) - (float)1.5) * (float)v71);
      v75 = (float)((float)(v60 - z)
                  * (float)((float)-(float)((float)((float)v72 * (float)v71) - (float)1.5) * (float)v71));
      v189.z = (float)(v60 - z) * (float)((float)-(float)((float)((float)v72 * (float)v71) - (float)1.5) * (float)v71);
      v76 = (float)((float)((float)-(float)((float)((float)v72 * (float)v71) - (float)1.5) * (float)v71)
                  * (float)((float)((float)(v60 - z) * (float)(v60 - z))
                          + (float)((float)((float)(v61 - x) * (float)(v61 - x))
                                  + (float)((float)(y - *((float *)&v181 + 1)) * (float)(y - *((float *)&v181 + 1))))));
      idVec3::NormalVectors(this: &v189, left: &v183, down: &v180);
      v77 = 0;
      LODWORD(v78) = this->numLinks;
      v181 = v78;
      v79 = (float)((float)v76 / (float)v78);
      if ( (int)v78 > 0 )
      {
        v80 = v183.z;
        v81 = v183.y;
        v82 = v183.x;
        v83 = v180.z;
        v84 = v180.y;
        v85 = v180.x;
        while ( 1 )
        {
          v191.mat[2].x = v73;
          v191.mat[2].y = v74;
          v191.mat[2].z = v75;
          v191.mat[0].x = v85;
          v191.mat[0].y = v84;
          v191.mat[0].z = v83;
          v191.mat[1].x = v82;
          v191.mat[1].y = v81;
          v191.mat[1].z = v80;
          v52 = 1103515245 * v52 + 12345;
          LODWORD(v86) = v77;
          HIDWORD(v86) = v52 >> 16;
          v181 = v86;
          v180.x = *(&v193 + 2 * (v77 % 2) + ((v52 >> 16) & 0x7FFF) - 2 * (((v52 >> 16) & 0x7FFF) >> 1)) + (float)v55;
          v87 = (float)((float)((float)v73 * (float)((float)v86 * (float)v79)) + (float)v63);
          v88 = (float)((float)v65 + (float)((float)v75 * (float)((float)v86 * (float)v79)));
          v89 = (float)((float)v64 + (float)((float)v74 * (float)((float)v86 * (float)v79)));
          v90 = idMat3::idMat3(
                  this: &v200,
                  axis: &v189,
                  angle: (const idTypesafeNumber<float,enum RadiansUnique_t> *)&v180);
          idMat3::operator*(this: &v184, result: &v191, a: v90);
          idList<idJointMat,85>::PreAllocateWithGranularity(this: &this->transforms, newSize: this->transforms.num + 1);
          size = this->transforms.size;
          v92 = this->transforms.num;
          v93 = p_transforms->list;
          if ( v92 >= size )
          {
            mat = v93[size - 1].mat;
          }
          else
          {
            this->transforms.num = v92 + 1;
            mat = v93[v92].mat;
          }
          ++v77;
          v95 = v184.mat[2].x;
          v96 = v184.mat[0].x;
          v97 = v184.mat[1].x;
          mat[4] = v184.mat[0].y;
          mat[11] = v88;
          mat[2] = v95;
          *mat = v96;
          mat[1] = v97;
          v98 = v184.mat[2].z;
          v99 = v184.mat[1].y;
          v100 = v184.mat[2].y;
          v101 = v184.mat[1].z;
          mat[8] = v184.mat[0].z;
          mat[3] = v87;
          mat[7] = v89;
          mat[10] = v98;
          mat[5] = v99;
          mat[6] = v100;
          mat[9] = v101;
          if ( v77 >= this->numLinks )
            break;
          v75 = v189.z;
          v74 = v189.y;
          v73 = v189.x;
        }
      }
    }
    else
    {
      v102 = 0;
      v103 = this->numLinks;
      v181 = (unsigned int)v103;
      v104 = (float)((float)v16 / (float)(unsigned int)v103);
      if ( v103 > 0 )
      {
        HIDWORD(v105) = 0x82000000;
        do
        {
          LODWORD(v105) = v102;
          v181 = v105;
          v106 = v102 + 1;
          TimeForLength = idCurve<idVec3>::GetTimeForLength(
                            this: (idCurve<idVec3> *)spline,
                            length: (float)((float)v105 * (float)v104),
                            epsilon: 0.1);
          LODWORD(v108) = v102 + 1;
          *(_QWORD *)&v183.x = v108;
          v109 = idCurve<idVec3>::GetTimeForLength(
                   this: (idCurve<idVec3> *)spline,
                   length: (float)((float)v108 * (float)v104),
                   epsilon: 0.1);
          (*(void (__fastcall **)(float *, idVec3 *, double))(LODWORD(spline->x) + 20))(
            a1: v190,
            a2: spline,
            a3: TimeForLength);
          (*(void (__fastcall **)(float *, idVec3 *, double))(LODWORD(spline->x) + 20))(a1: v205, a2: spline, a3: v109);
          v110 = (float)(v205[1] - v190[1]);
          v111 = (float)(v205[0] - v190[0]);
          v112 = (float)(v205[2] - v190[2]);
          _FP9 = (float)((float)((float)((float)(v205[2] - v190[2]) * (float)(v205[2] - v190[2]))
                               + (float)((float)((float)(v205[0] - v190[0]) * (float)(v205[0] - v190[0]))
                                       + (float)((float)(v205[1] - v190[1]) * (float)(v205[1] - v190[1]))))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f7, f9, f10, f0 }
          v115 = __frsqrte(_FP7);
          v116 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v115
                                                                                               * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                       * (float)v115)
                                                                               - (float)1.5)
                                                               * (float)v115)
                                                       * (float)((float)((float)((float)v112 * (float)v112)
                                                                       + (float)((float)((float)v111 * (float)v111)
                                                                               + (float)((float)v110 * (float)v110)))
                                                               * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)v115
                                                                                       * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110)))
                                                                                               * (float)0.5))
                                                                               * (float)v115)
                                                                       - (float)1.5)
                                                       * (float)v115))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)v115
                                                               * (float)((float)((float)((float)v112 * (float)v112)
                                                                               + (float)((float)((float)v111
                                                                                               * (float)v111)
                                                                                       + (float)((float)v110
                                                                                               * (float)v110)))
                                                                       * (float)0.5))
                                                       * (float)v115)
                                               - (float)1.5)
                               * (float)v115));
          v117 = (float)((float)v111
                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115) * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                               * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115)
                                                                                               - (float)1.5)
                                                                               * (float)v115))
                                                               * (float)((float)((float)((float)v112 * (float)v112)
                                                                               + (float)((float)((float)v111
                                                                                               * (float)v111)
                                                                                       + (float)((float)v110
                                                                                               * (float)v110)))
                                                                       * (float)0.5))
                                                       * (float)v116)
                                               - (float)1.5)
                               * (float)v116));
          v199[0].x = (float)v111
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115) * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115)
                                                                                            - (float)1.5)
                                                                            * (float)v115))
                                                            * (float)((float)((float)((float)v112 * (float)v112)
                                                                            + (float)((float)((float)v111 * (float)v111)
                                                                                    + (float)((float)v110 * (float)v110)))
                                                                    * (float)0.5))
                                                    * (float)v116)
                                            - (float)1.5)
                            * (float)v116);
          v118 = (float)((float)v110
                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115) * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                               * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115)
                                                                                               - (float)1.5)
                                                                               * (float)v115))
                                                               * (float)((float)((float)((float)v112 * (float)v112)
                                                                               + (float)((float)((float)v111
                                                                                               * (float)v111)
                                                                                       + (float)((float)v110
                                                                                               * (float)v110)))
                                                                       * (float)0.5))
                                                       * (float)v116)
                                               - (float)1.5)
                               * (float)v116));
          v199[0].y = (float)v110
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115) * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115)
                                                                                            - (float)1.5)
                                                                            * (float)v115))
                                                            * (float)((float)((float)((float)v112 * (float)v112)
                                                                            + (float)((float)((float)v111 * (float)v111)
                                                                                    + (float)((float)v110 * (float)v110)))
                                                                    * (float)0.5))
                                                    * (float)v116)
                                            - (float)1.5)
                            * (float)v116);
          v119 = (float)((float)v112
                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115) * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                               * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115)
                                                                                               - (float)1.5)
                                                                               * (float)v115))
                                                               * (float)((float)((float)((float)v112 * (float)v112)
                                                                               + (float)((float)((float)v111
                                                                                               * (float)v111)
                                                                                       + (float)((float)v110
                                                                                               * (float)v110)))
                                                                       * (float)0.5))
                                                       * (float)v116)
                                               - (float)1.5)
                               * (float)v116));
          v199[0].z = (float)v112
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115) * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115) - (float)1.5) * (float)v115))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v115 * (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) * (float)0.5)) * (float)v115)
                                                                                            - (float)1.5)
                                                                            * (float)v115))
                                                            * (float)((float)((float)((float)v112 * (float)v112)
                                                                            + (float)((float)((float)v111 * (float)v111)
                                                                                    + (float)((float)v110 * (float)v110)))
                                                                    * (float)0.5))
                                                    * (float)v116)
                                            - (float)1.5)
                            * (float)v116);
          idVec3::NormalVectors(this: v199, left: &v206, down: &v207);
          v52 = 1103515245 * v52 + 12345;
          v184.mat[0].x = v207.x;
          v184.mat[0].y = v207.y;
          v184.mat[0].z = v207.z;
          v184.mat[1].x = v206.x;
          v184.mat[1].y = v206.y;
          v184.mat[1].z = v206.z;
          v180.x = *(&v193 + 2 * (v102 % 2) + ((v52 >> 16) & 0x7FFF) - 2 * (((v52 >> 16) & 0x7FFF) >> 1)) + (float)v55;
          v184.mat[2].x = v117;
          v184.mat[2].y = v118;
          v184.mat[2].z = v119;
          v120 = idMat3::idMat3(
                   this: &v200,
                   axis: v199,
                   angle: (const idTypesafeNumber<float,enum RadiansUnique_t> *)&v180);
          idMat3::operator*(this: &v191, result: &v184, a: v120);
          idList<idJointMat,85>::PreAllocateWithGranularity(this: &this->transforms, newSize: this->transforms.num + 1);
          HIDWORD(v105) = this->transforms.size;
          LODWORD(v105) = this->transforms.num;
          v121 = p_transforms->list;
          if ( (int)v105 >= SHIDWORD(v105) )
          {
            LODWORD(v105) = &v121[HIDWORD(v105) - 1];
          }
          else
          {
            HIDWORD(v105) = 2 * v105;
            this->transforms.num = v105 + 1;
            LODWORD(v105) = &v121[v105];
          }
          ++v102;
          v122 = v191.mat[1].x;
          v123 = v191.mat[2].x;
          v124 = v191.mat[0].y;
          v125 = v191.mat[1].y;
          v126 = v191.mat[1].z;
          v127 = v191.mat[2].z;
          v128 = v191.mat[2].y;
          *(float *)v105 = v191.mat[0].x;
          *(float *)(v105 + 4) = v122;
          *(float *)(v105 + 8) = v123;
          *(float *)(v105 + 16) = v124;
          *(float *)(v105 + 20) = v125;
          *(float *)(v105 + 36) = v126;
          *(float *)(v105 + 40) = v127;
          *(float *)(v105 + 24) = v128;
          *(float *)(v105 + 32) = v191.mat[0].z;
          *(float *)(v105 + 12) = v190[0];
          *(float *)(v105 + 28) = v190[1];
          *(float *)(v105 + 44) = v190[2];
        }
        while ( v106 < this->numLinks );
      }
    }
    for ( ii = 0; ii < v5->surfaces.num; ++ii )
    {
      v130 = v208.list[ii];
      v131 = (int)&v5->surfaces.list[ii];
      if ( v130 == ROLE_NONE )
        continue;
      v132 = (idTriangles *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x84u,
                              tag: TAG_TRIANGLES,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      LODWORD(v180.x) = v132;
      v133 = v132 != nullptr ? idTriangles::idTriangles(this: v132) : nullptr;
      if ( v133 == nullptr )
        continue;
      v134 = (idJointBuffer *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x10u,
                                tag: TAG_RENDERMODEL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      LODWORD(v180.x) = v134;
      v135 = v134 != nullptr ? idJointBuffer::idJointBuffer(this: v134) : nullptr;
      if ( v135 == nullptr )
        continue;
      idJointBuffer::Reference(
        this: v135,
        other: &this->jointBuffers[this->currentJointBuffer],
        jointRefOffset: 0,
        numRefJoints: this->numLinks);
      v136 = this->numLinks;
      v137 = v136 * *(_DWORD *)(v130 + 32);
      v138 = v136 * *(_DWORD *)(v130 + 28);
      idTriangles::AllocStaticTriSurfVerts(this: v133, numVerts: v137);
      idTriangles::AllocStaticTriSurfIndexes(this: v133, numIndexes: v138);
      for ( jj = 0; jj < this->numLinks; ++jj )
      {
        v140 = *(_DWORD *)(v130 + 32);
        v141 = (int)&v133->verts[v140 * jj];
        if ( jj == this->numLinks - 1 )
        {
          v142 = 0;
          if ( v140 > 0 )
          {
            v143 = v141 + 4;
            v144 = -4 - v141;
            do
            {
              ++v142;
              v145 = v144 + *(_DWORD *)(v130 + 88) + v143;
              LODWORD(v180.x) = v145 + 12;
              *(float *)(v143 - 4) = *(float *)v145;
              *(float *)v143 = *(float *)(v145 + 4);
              *(float *)(v143 + 4) = *(float *)(v145 + 8);
              *(float *)(v143 + 8) = *(float *)(v145 + 12);
              *(float *)(v143 + 12) = *(float *)(v145 + 16);
              *(_BYTE *)(v143 + 16) = *(_BYTE *)(v145 + 20);
              *(_BYTE *)(v143 + 17) = *(_BYTE *)(v145 + 21);
              *(_BYTE *)(v143 + 18) = *(_BYTE *)(v145 + 22);
              *(_BYTE *)(v143 + 19) = *(_BYTE *)(v145 + 23);
              *(_BYTE *)(v143 + 20) = *(_BYTE *)(v145 + 24);
              *(_BYTE *)(v143 + 21) = *(_BYTE *)(v145 + 25);
              *(_BYTE *)(v143 + 22) = *(_BYTE *)(v145 + 26);
              *(_BYTE *)(v143 + 23) = *(_BYTE *)(v145 + 27);
              *(_BYTE *)(v143 + 24) = *(_BYTE *)(v145 + 28);
              *(_BYTE *)(v143 + 25) = *(_BYTE *)(v145 + 29);
              *(_BYTE *)(v143 + 26) = *(_BYTE *)(v145 + 30);
              *(_BYTE *)(v143 + 27) = *(_BYTE *)(v145 + 31);
              *(_BYTE *)(v143 + 24) = jj;
              *(_BYTE *)(v143 + 25) = jj;
              *(_BYTE *)(v143 + 26) = jj;
              *(_BYTE *)(v143 + 27) = jj;
              *(_BYTE *)(v143 + 19) = 0;
              *(_BYTE *)(v143 + 23) = 0;
              v143 += 32;
              v140 = *(_DWORD *)(v130 + 32);
            }
            while ( v142 < v140 );
          }
        }
        else
        {
          v146 = 0;
          if ( v140 > 0 )
          {
            v147 = v141 + 4;
            v148 = -4 - v141;
            do
            {
              v149 = v148 + v147 + *(_DWORD *)(v130 + 88);
              LODWORD(v180.x) = v149 + 12;
              *(float *)(v147 - 4) = *(float *)v149;
              *(float *)v147 = *(float *)(v149 + 4);
              *(float *)(v147 + 4) = *(float *)(v149 + 8);
              *(float *)(v147 + 8) = *(float *)(v149 + 12);
              *(float *)(v147 + 12) = *(float *)(v149 + 16);
              *(_BYTE *)(v147 + 16) = *(_BYTE *)(v149 + 20);
              *(_BYTE *)(v147 + 17) = *(_BYTE *)(v149 + 21);
              *(_BYTE *)(v147 + 18) = *(_BYTE *)(v149 + 22);
              *(_BYTE *)(v147 + 19) = *(_BYTE *)(v149 + 23);
              *(_BYTE *)(v147 + 20) = *(_BYTE *)(v149 + 24);
              *(_BYTE *)(v147 + 21) = *(_BYTE *)(v149 + 25);
              *(_BYTE *)(v147 + 22) = *(_BYTE *)(v149 + 26);
              *(_BYTE *)(v147 + 23) = *(_BYTE *)(v149 + 27);
              *(_BYTE *)(v147 + 24) = *(_BYTE *)(v149 + 28);
              v150 = *(_BYTE *)(v149 + 29);
              *(_BYTE *)(v147 + 25) = v150;
              *(_BYTE *)(v147 + 26) = *(_BYTE *)(v149 + 30);
              LOBYTE(v149) = *(_BYTE *)(v149 + 31);
              v151 = v150 + jj;
              *(_BYTE *)(v147 + 27) = v149;
              v152 = *(_BYTE *)(v147 + 26);
              v153 = *(_BYTE *)(v147 + 24);
              *(_BYTE *)(v147 + 25) = v151;
              *(_BYTE *)(v147 + 27) = v149 + jj;
              *(_BYTE *)(v147 + 26) = v152 + jj;
              *(_BYTE *)(v147 + 24) = v153 + jj;
              if ( this->genInfo.smoothSkinning )
                *(float *)(v147 + 4) = 0.0;
              v140 = *(_DWORD *)(v130 + 32);
              ++v146;
              v147 += 32;
            }
            while ( v146 < v140 );
          }
        }
        v154 = *(_DWORD *)(v130 + 28);
        v155 = v140 * jj;
        v156 = 0;
        v157 = (int)&v133->indexes[v154 * jj];
        if ( v154 > 0 )
        {
          v158 = 0;
          do
          {
            ++v156;
            *(_WORD *)(v158 + v157) = *(_WORD *)(v158 + *(_DWORD *)(v130 + 92)) + v155;
            v158 += 2;
          }
          while ( v156 < *(_DWORD *)(v130 + 28) );
        }
      }
      v133->numIndexes = v138;
      v133->numVerts = v137;
      LODWORD(v180.x) = &v133->bounds.b[1];
      v133->bounds.b[0].x = *(float *)v130;
      v133->bounds.b[0].y = *(float *)(v130 + 4);
      v133->bounds.b[0].z = *(float *)(v130 + 8);
      v133->bounds.b[1].x = *(float *)(v130 + 12);
      v133->bounds.b[1].y = *(float *)(v130 + 16);
      v133->bounds.b[1].z = *(float *)(v130 + 20);
      idTriangles::UpdateVertexBuffer(this: v133);
      idTriangles::UpdateIndexBuffer(this: v133);
      v159 = *(float *)v131;
      v160 = *(float *)(v131 + 4);
      *(float *)&v202 = 0.0;
      v203 = 0.0;
      *(float *)&v204 = 0.0;
      *((float *)&v204 + 1) = 0.0;
      HIWORD(v200.mat[1].z) = 0;
      v200.mat[2].x = 0.0;
      v200.mat[2].z = 0.0;
      v201 = 0;
      LODWORD(v200.mat[1].y) = v133;
      LODWORD(v200.mat[2].y) = v135;
      v200.mat[0].x = v159;
      v200.mat[0].y = v160;
      v161 = *(_QWORD *)(v131 + 8);
      if ( ii == 0 && this->numMorphVertices > 0 )
      {
        v162 = (idIndexBuffer *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x10u,
                                  tag: TAG_RENDERMODEL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
        LODWORD(v180.x) = v162;
        if ( v162 != nullptr )
          v163 = (idVertexBuffer *)idIndexBuffer::idIndexBuffer(this: v162);
        else
          v163 = nullptr;
        if ( v163 != nullptr )
          idVertexBuffer::Reference(
            this: v163,
            other: &this->morphBuffers[this->currentMorphBuffer],
            refOffset: 0,
            refSize: 4 * this->numMorphVertices);
        LODWORD(v200.mat[2].z) = v163;
      }
      idRenderModel::AddSurface(
        this,
        surf: (idRenderModelSurface *)LODWORD(v200.mat[0].y),
        a3: __SPAIR64__(LODWORD(v200.mat[1].y), LODWORD(v200.mat[2].x)),
        a4: __SPAIR64__(LODWORD(v200.mat[2].z), v202),
        a5: v204,
        a6: v169,
        a7: v170,
        a8: v171,
        a9: v172,
        a10: v173,
        a11: v174,
        a12: v175,
        a13: v176,
        a14: v177,
        a15: v178);
      if ( ii == 0 && this->numMorphVertices > 0 )
      {
        v164 = (idJointBuffer *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x10u,
                                  tag: TAG_RENDERMODEL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
        LODWORD(v180.x) = v164;
        if ( v164 != nullptr )
          LODWORD(v161) = idJointBuffer::idJointBuffer(this: v164);
        else
          LODWORD(v161) = 0;
        if ( (_DWORD)v161 == 0 )
          continue;
        v165 = (idIndexBuffer *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x10u,
                                  tag: TAG_RENDERMODEL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
        LODWORD(v180.x) = v165;
        v166 = v165 != nullptr ? (idVertexBuffer *)idIndexBuffer::idIndexBuffer(this: v165) : nullptr;
        if ( v166 == nullptr )
          continue;
        idJointBuffer::Reference(
          this: (idJointBuffer *)v161,
          other: &this->jointBuffers[this->currentJointBuffer],
          jointRefOffset: 0,
          numRefJoints: this->numLinks);
        idVertexBuffer::Reference(
          this: v166,
          other: &this->morphBuffers[this->currentMorphBuffer],
          refOffset: 0,
          refSize: 4 * this->numMorphVertices);
        morphMaterial = this->morphMaterial;
        v186 = 0.0;
        v184.mat[0].y = 0.0;
        v187 = 0.0;
        HIWORD(v184.mat[1].z) = 256;
        *(float *)&v188 = 0.0;
        v185 = 0;
        *((float *)&v188 + 1) = 0.0;
        LODWORD(v184.mat[2].z) = v166;
        LODWORD(v184.mat[0].x) = morphMaterial;
        v184.mat[1].y = *(float *)&v161;
        LODWORD(v184.mat[2].y) = v161;
        v184.mat[2].x = 0.0;
        LODWORD(v168) = 0;
        HIDWORD(v168) = v161;
        idRenderModel::AddSurface(
          this: (idRenderModel *)LODWORD(v184.mat[0].x),
          surf: nullptr,
          a3: *(__int64 *)&v184.mat[1].y,
          a4: v168,
          a5: v188,
          a6: v169,
          a7: v170,
          a8: v171,
          a9: v172,
          a10: v173,
          a11: v174,
          a12: v175,
          a13: v176,
          a14: v177,
          a15: v178);
      }
      idTriangles::FreeCPUData(this: (idTriangles *)HIDWORD(v161));
      idTriangles::FreeCPUData(this: (idTriangles *)v130);
      idTriangles::~idTriangles(this: (idTriangles *)v130);
      idMem::Free(this: &mem, ptr: (void *)v130, align: ALIGN_16);
    }
    if ( v208.listStatic == 0 || v208.listStatic == 2 )
    {
      if ( v208.list != nullptr )
        idMem::Free(this: &mem, ptr: v208.list, align: ALIGN_16);
      v208.list = nullptr;
      v208.size = 0;
    }
    v208.num = 0;
    idRenderModel::FinishSurfaces(this);
    if ( (v208.listStatic == 0 || v208.listStatic == 2) && v208.list != nullptr )
      idMem::Free(this: &mem, ptr: v208.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$228996_0
// EA  : 0x827FAD68
// RVA : 0x007FAD68
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_228996_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 880 + 464));
}


// ========================================================================
// __unwind$228997_0
// EA  : 0x827FAD90
// RVA : 0x007FAD90
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_228997_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 880 + 104), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$228998_0
// EA  : 0x827FADBC
// RVA : 0x007FADBC
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_228998_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 880 + 104), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$228999
// EA  : 0x827FADE8
// RVA : 0x007FADE8
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_228999()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 880 + 104), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$229000
// EA  : 0x827FAE14
// RVA : 0x007FAE14
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_229000()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 880 + 104), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$229001
// EA  : 0x827FAE40
// RVA : 0x007FAE40
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_229001()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 880 + 104), tag: TAG_RENDERMODEL);
}


// ========================================================================
// ?Load@idRenderModelChain@@UAA_NPAVidFile@@@Z
// EA  : 0x827FB618
// RVA : 0x007FB618
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

int __fastcall idRenderModelChain::Load(idRenderModelChain *this, idFile *fp)
{
  idFile_vtbl *v4; // r11
  const idMaterial *v6; // r3
  int v7; // r4
  int v8; // r29
  idRenderModelChain::splinePoint_t *v9; // r30
  const idVec3 *v10; // r4
  double v11; // fp8
  double v12; // fp7
  double v13; // fp6
  double v14; // fp5
  double v15; // fp4
  double v16; // fp3
  double v17; // fp2
  int v18; // r29
  int v19; // r30
  int v20; // r29
  int v21; // r30
  idJointMat *v22; // r11
  idJointMat *v23; // r11
  char v24; // r11
  int v25; // r30
  float v26; // [sp+8h] [-148h]
  float v27; // [sp+Ch] [-144h]
  float v28; // [sp+10h] [-140h]
  float v29; // [sp+14h] [-13Ch]
  float v30; // [sp+18h] [-138h]
  float v31; // [sp+1Ch] [-134h]
  char v32; // [sp+50h] [-100h] BYREF
  unsigned __int8 v33; // [sp+51h] [-FFh] BYREF
  _BYTE v34[2]; // [sp+52h] [-FEh] BYREF
  int v35; // [sp+54h] [-FCh] BYREF
  int v36; // [sp+58h] [-F8h] BYREF
  float v37[4]; // [sp+60h] [-F0h] BYREF
  idStr v38; // [sp+70h] [-E0h] BYREF
  float v39[12]; // [sp+90h] [-C0h] BYREF
  idCurve_NURBS<idVec3> v40[2]; // [sp+C0h] [-90h] BYREF

  if ( (unsigned __int8)idRenderModel::Load(this, fp) == 0 )
    return 0;
  v4 = fp->__vftable;
  v34[0] = 0;
  if ( v4->Read(this: fp, a2: v34, a3: 1u) == 0 )
    return 0;
  if ( v34[0] != 0 )
  {
    v38.len = 0;
    v38.baseBuffer[0] = 0;
    v38.allocedAndFlag = 20;
    v38.data = v38.baseBuffer;
    if ( idFile::ReadString(this: fp, string: &v38) == 0 )
    {
      idStr::FreeData(this: &v38);
      return 0;
    }
    if ( v38.data != nullptr )
      v6 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                 this: &idMaterial::resourceList,
                                 name: v38.data,
                                 makeDefault: true);
    else
      v6 = nullptr;
    this->morphMaterial = v6;
    idStr::FreeData(this: &v38);
  }
  if ( idFile::ReadString(this: fp, string: &this->chainLinkModel) == 0 )
    return 0;
  v35 = 0;
  if ( fp->Read(this: fp, a2: &v35, a3: 4u) == 0 )
    return 0;
  v7 = v35;
  if ( v35 > this->splineSettings.size )
  {
    idList<idRenderModelChain::splinePoint_t,85>::Resize(
      this: (idList<idSphere,81> *)&this->splineSettings,
      newsize: v35);
    v7 = v35;
  }
  v8 = 0;
  if ( v7 > 0 )
  {
    do
    {
      v9 = idList<idVec4,5>::Alloc(this: &this->splineSettings);
      if ( fp->Read(this: fp, a2: v9, a3: 12u) == 0 || fp->Read(this: fp, a2: &v9->time, a3: 4u) == 0 )
        return 0;
    }
    while ( ++v8 < v35 );
  }
  if ( fp->Read(this: fp, a2: &this->genInfo, a3: 1u) == 0
    || fp->Read(this: fp, a2: &this->genInfo.smoothSkinning, a3: 1u) == 0
    || fp->Read(this: fp, a2: &this->genInfo.startRotation, a3: 4u) == 0 )
  {
    return 0;
  }
  idCurve_NURBS<idVec3>::idCurve_NURBS<idVec3>(this: v40);
  v18 = 0;
  if ( v35 > 0 )
  {
    v19 = 0;
    do
    {
      idCurve_NURBS<idVec3>::AddValue(
        this: v40,
        time: this->splineSettings.list[v19].time,
        value: v10,
        a4: &this->splineSettings.list[v19].value,
        a5: v17,
        a6: v16,
        a7: v15,
        a8: v14,
        a9: v13,
        a10: v12,
        a11: v11,
        a12: v26,
        a13: v27,
        a14: v28,
        a15: v29,
        a16: v30,
        a17: v31);
      ++v18;
      ++v19;
    }
    while ( v18 < v35 );
  }
  idRenderModelChain::BuildModel(this, spline: (idVec3 *)v40);
  v36 = 0;
  if ( fp->Read(this: fp, a2: &v36, a3: 4u) == 0 )
    goto LABEL_45;
  v20 = 0;
  if ( v36 > 0 )
  {
    v21 = 0;
    while ( fp->Read(this: fp, a2: v39, a3: 36u) != 0 && fp->Read(this: fp, a2: v37, a3: 12u) != 0 )
    {
      if ( v20 < this->numLinks )
      {
        v22 = &this->transforms.list[v21];
        v22->mat[0] = v39[0];
        v22->mat[1] = v39[3];
        v22->mat[2] = v39[6];
        v22->mat[4] = v39[1];
        v22->mat[5] = v39[4];
        v22->mat[6] = v39[7];
        v22->mat[8] = v39[2];
        v22->mat[9] = v39[5];
        v22->mat[10] = v39[8];
        v23 = &this->transforms.list[v21];
        v23->mat[3] = v37[0];
        v23->mat[7] = v37[1];
        v23->mat[11] = v37[2];
      }
      ++v20;
      ++v21;
      if ( v20 >= v36 )
        goto LABEL_33;
    }
    goto LABEL_45;
  }
LABEL_33:
  v24 = *((_BYTE *)this + 2204);
  v32 = 0;
  *((_BYTE *)this + 2204) = v24 | 0x40;
  if ( fp->Read(this: fp, a2: &v32, a3: 1u) != 0 )
  {
    if ( v32 != 0 )
    {
      v25 = 0;
      if ( v36 > 0 )
      {
        do
        {
          v33 = 0;
          if ( fp->Read(this: fp, a2: &v33, a3: 1u) == 0 )
            goto LABEL_45;
          if ( this->numMorphVertices != 0 )
            this->morphMap.list[4 * this->numMorphLinkVertices * v25 + 3] = v33;
        }
        while ( ++v25 < v36 );
      }
      *((_BYTE *)this + 2204) |= 0x80u;
    }
    idCurve_NURBS<idVec3>::~idCurve_NURBS<idVec3>(this: v40);
    return 1;
  }
LABEL_45:
  idCurve_NURBS<idVec3>::~idCurve_NURBS<idVec3>(this: v40);
  return 0;
}


// ========================================================================
// __unwind$231101_0
// EA  : 0x827FBAA0
// RVA : 0x007FBAA0
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_231101_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 112));
}


// ========================================================================
// __unwind$231102_0
// EA  : 0x827FBAC8
// RVA : 0x007FBAC8
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void _unwind_231102_0()
{
  int v0; // r12

  idCurve_NURBS<idVec3>::~idCurve_NURBS<idVec3>(this: (idCurve_NURBS<idVec3> *)(v0 - 336 + 192));
}


// ========================================================================
// ?Build@idRenderModelChain@@QAAXABUchainGenerateInfo_t@@ABVidStr@@PBVidMaterial@@ABV?$idCurve_NURBS@VidVec3@@@@@Z
// EA  : 0x827FBAF0
// RVA : 0x007FBAF0
// PDB : w:\tech5\engine\models\rendermodelchain.cpp
// ========================================================================

void __fastcall idRenderModelChain::Build(
        idRenderModelChain *this,
        const chainGenerateInfo_t *genInfo_,
        const idStr *modelName,
        const idMaterial *morphMaterial_,
        idVec3 *spline)
{
  idList<idSphere,81> *p_splineSettings; // r31
  int x_low; // r30
  int v12; // r28
  int v13; // r29
  int num; // r11
  int size; // r10
  idSphere *list; // r9
  float *p_x; // r11
  idVec3 *v18; // r10
  double x; // fp13
  unsigned int allocedAndFlag; // r11
  int len; // r30
  int v22; // r4
  int v23; // r11
  bool v24; // zf
  float y; // [sp+54h] [-5Ch]

  p_splineSettings = (idList<idSphere,81> *)&this->splineSettings;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineSettings);
  x_low = LODWORD(spline[2].x);
  if ( x_low > this->splineSettings.size )
    idList<idRenderModelChain::splinePoint_t,85>::Resize(this: p_splineSettings, newsize: LODWORD(spline[2].x));
  if ( x_low > 0 )
  {
    v12 = 0;
    v13 = 0;
    do
    {
      idList<idSphere,81>::PreAllocateWithGranularity(this: p_splineSettings, newSize: p_splineSettings->num + 1);
      num = p_splineSettings->num;
      size = p_splineSettings->size;
      list = p_splineSettings->list;
      if ( num >= size )
      {
        p_x = &list[size - 1].origin.x;
      }
      else
      {
        p_splineSettings->num = num + 1;
        p_x = &list[num].origin.x;
      }
      --x_low;
      v18 = (idVec3 *)(v13 + LODWORD(spline[1].z));
      v13 += 12;
      x = v18->x;
      y = v18->y;
      p_x[2] = v18->z;
      p_x[1] = y;
      *p_x = x;
      p_x[3] = *(float *)(LODWORD(spline->y) + v12);
      v12 += 4;
    }
    while ( x_low != 0 );
  }
  allocedAndFlag = this->chainLinkModel.allocedAndFlag;
  len = modelName->len;
  v22 = modelName->len + 1;
  v24 = allocedAndFlag >> 31 == 0;
  v23 = allocedAndFlag & 0x7FFFFFFF;
  if ( v24 )
  {
    if ( v22 > v23 )
      idStr::ReAllocate(this: &this->chainLinkModel, amount: v22, keepold: false);
  }
  else if ( v22 > v23
         && AssertFailed(
              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
              line: 463,
              expression: "amount <= GetAlloced()",
              inlineBreak: true) )
  {
    __trap();
  }
  memcpy(Dst: this->chainLinkModel.data, Src: modelName->data, Size: len);
  this->chainLinkModel.data[len] = 0;
  this->chainLinkModel.len = len;
  this->morphMaterial = morphMaterial_;
  *(_DWORD *)&this->genInfo.rotateRandom = *(_DWORD *)&genInfo_->rotateRandom;
  this->genInfo.startRotation = genInfo_->startRotation;
  idRenderModelChain::BuildModel(this, spline);
}

