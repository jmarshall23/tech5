
// ========================================================================
// ?Update@idRenderModelDiscreteAnimation@@QAAXXZ
// EA  : 0x827D0D60
// RVA : 0x007D0D60
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

// attributes: thunk
void __fastcall idRenderModelDiscreteAnimation::Update(idRenderModelDiscreteAnimation *this)
{
  idRenderModel::CommitThisFrame(this);
}


// ========================================================================
// ?SerializeSnapshot@idRenderModelDiscreteAnimation@@UAAXAAVidSerializer@@_N@Z
// EA  : 0x827D0D68
// RVA : 0x007D0D68
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

// attributes: thunk
void __fastcall idRenderModelDiscreteAnimation::SerializeSnapshot(
        idRenderModelDiscreteAnimation *this,
        idSerializer *ser,
        bool serializeParmBlock)
{
  idRenderModel::SerializeSnapshot(this, ser, serializeParmBlock);
}


// ========================================================================
// ?Save@idRenderModelDiscreteAnimation@@MBAXPAVidFile@@@Z
// EA  : 0x827D0D70
// RVA : 0x007D0D70
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void __fastcall idRenderModelDiscreteAnimation::Save(idRenderModelDiscreteAnimation *this, idFile *fp)
{
  idFile_vtbl *v4; // r10
  int v5; // r29
  int v6; // r28
  int num; // [sp+50h] [-30h] BYREF

  idRenderModel::Save(this, fp);
  v4 = fp->__vftable;
  num = this->transforms.num;
  v4->Write(this: fp, a2: &num, a3: 4u);
  v5 = 0;
  if ( this->transforms.num > 0 )
  {
    v6 = 0;
    do
    {
      fp->Write(this: fp, a2: &this->transforms.list[v6], a3: 48u);
      ++v5;
      ++v6;
    }
    while ( v5 < this->transforms.num );
  }
  fp->Write(this: fp, a2: this->collapsed.list, a3: this->collapsed.num);
}


// ========================================================================
// ?GetPiecePosition@idRenderModelDiscreteAnimation@@QBAXHAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x827D0E18
// RVA : 0x007D0E18
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void __fastcall idRenderModelDiscreteAnimation::GetPiecePosition(
        idRenderModelDiscreteAnimation *this,
        const int index,
        idVec3 *position,
        idMat3 *orientation)
{
  idJointMat *v4; // r11
  double v5; // fp13
  double v6; // fp12
  double v7; // fp11
  double v8; // fp10
  double v9; // fp9
  double v10; // fp8
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4

  v4 = &this->transforms.list[index];
  v5 = v4->mat[7];
  v6 = v4->mat[11];
  position->x = v4->mat[3];
  position->y = v5;
  position->z = v6;
  v7 = v4->mat[10];
  v8 = v4->mat[6];
  v9 = v4->mat[2];
  v10 = v4->mat[9];
  v11 = v4->mat[5];
  v12 = v4->mat[1];
  v13 = v4->mat[8];
  v14 = v4->mat[4];
  orientation->mat[0].x = v4->mat[0];
  orientation->mat[1].x = v12;
  orientation->mat[0].y = v14;
  orientation->mat[0].z = v13;
  orientation->mat[1].y = v11;
  orientation->mat[1].z = v10;
  orientation->mat[2].x = v9;
  orientation->mat[2].y = v8;
  orientation->mat[2].z = v7;
}


// ========================================================================
// ?SetPiecePosition@idRenderModelDiscreteAnimation@@QAAXHABVidVec3@@ABVidMat3@@@Z
// EA  : 0x827D0E90
// RVA : 0x007D0E90
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void __fastcall idRenderModelDiscreteAnimation::SetPiecePosition(
        idRenderModelDiscreteAnimation *this,
        const int index,
        const idVec3 *position,
        const idMat3 *orientation)
{
  idJointMat *v4; // r11
  idJointMat *v5; // r11

  v4 = &this->transforms.list[index];
  v4->mat[3] = position->x;
  v4->mat[7] = position->y;
  v4->mat[11] = position->z;
  v5 = &this->transforms.list[index];
  v5->mat[0] = orientation->mat[0].x;
  v5->mat[1] = orientation->mat[1].x;
  v5->mat[2] = orientation->mat[2].x;
  v5->mat[4] = orientation->mat[0].y;
  v5->mat[5] = orientation->mat[1].y;
  v5->mat[6] = orientation->mat[2].y;
  v5->mat[8] = orientation->mat[0].z;
  v5->mat[9] = orientation->mat[1].z;
  v5->mat[10] = orientation->mat[2].z;
  this->collapsed.list[index] = false;
  this->changed = true;
}


// ========================================================================
// ?CollapsePiece@idRenderModelDiscreteAnimation@@QAAXH@Z
// EA  : 0x827D0F28
// RVA : 0x007D0F28
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void __fastcall idRenderModelDiscreteAnimation::CollapsePiece(idRenderModelDiscreteAnimation *this, const int index)
{
  idJointMat *v2; // r11
  idJointMat *v3; // r11

  v2 = &this->transforms.list[index];
  v2->mat[3] = vec3_origin.x;
  v2->mat[7] = vec3_origin.y;
  v2->mat[11] = vec3_origin.z;
  v3 = &this->transforms.list[index];
  v3->mat[0] = mat3_zero.mat[0].x;
  v3->mat[1] = mat3_zero.mat[1].x;
  v3->mat[2] = mat3_zero.mat[2].x;
  v3->mat[4] = mat3_zero.mat[0].y;
  v3->mat[5] = mat3_zero.mat[1].y;
  v3->mat[6] = mat3_zero.mat[2].y;
  v3->mat[8] = mat3_zero.mat[0].z;
  v3->mat[9] = mat3_zero.mat[1].z;
  v3->mat[10] = mat3_zero.mat[2].z;
  this->collapsed.list[index] = true;
  this->changed = true;
}


// ========================================================================
// ?CommitSubclass@idRenderModelDiscreteAnimation@@EAA_NXZ
// EA  : 0x827D0FC8
// RVA : 0x007D0FC8
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

int __fastcall idRenderModelDiscreteAnimation::CommitSubclass(idRenderModelDiscreteAnimation *this)
{
  bool *p_changed; // r26
  int num; // r5
  int v8; // r9
  int v9; // r10
  idJointMat *list; // r4
  int v23; // r11
  int v24; // r30
  int v25; // r28
  int v26; // r29
  idDiscreteAnimationModelSurface *v27; // r5
  const idDiscreteAnimationModelData *modelData; // r11
  double maxRadius; // fp0
  double v30; // fp9
  double v31; // fp7
  double v32; // fp5
  double v33; // fp4
  double v34; // fp3
  float v36[20]; // [sp+50h] [-50h] BYREF

  p_changed = &this->changed;
  if ( this->changed )
  {
    num = this->transforms.num;
    _R7 = &vector_float_posInfinity;
    _R6 = &vector_float_negInfinity;
    _R8 = 16;
    v8 = 0;
    __asm
    {
      lvx128    v63, r0, r7
      lvx128    v60, r0, r6
      vor128    v62, v95, v63
      vor128    v59, v92, v60
      vor128    v61, v95, v63
      vor128    v58, v92, v60
    }
    if ( num > 0 )
    {
      v9 = 0;
      _R7 = 32;
      do
      {
        if ( !this->collapsed.list[v8] )
        {
          _R11 = &this->transforms.list[v9];
          __asm
          {
            lvx128    v57, r0, r11
            lvx128    v56, r11, r8
            vminfp128 v63, v95, v57
            lvx128    v55, r11, r7
            vminfp128 v62, v94, v56
            vminfp128 v61, v93, v55
            vmaxfp128 v60, v92, v57
            vmaxfp128 v59, v91, v56
            vmaxfp128 v58, v90, v55
          }
        }
        ++v8;
        ++v9;
      }
      while ( v8 < num );
    }
    __asm { vspltw128 v54, v63, 3 }
    _R11 = v36;
    __asm { vspltw128 v53, v62, 3 }
    _R10 = v36;
    _R9 = 4;
    __asm
    {
      vspltw128 v52, v61, 3
      vspltw128 v51, v60, 3
    }
    _R7 = v36;
    __asm { vspltw128 v50, v59, 3 }
    _R6 = 8;
    __asm { vspltw128 v49, v58, 3 }
    _R4 = v36;
    _R3 = 12;
    __asm { stvewx128 v54, r0, r11 }
    _R30 = v36;
    __asm { stvewx128 v53, r10, r9 }
    _R11 = v36;
    _R10 = 20;
    __asm { stvewx128 v52, r7, r6 }
    __asm
    {
      stvewx128 v51, r4, r3
      stvewx128 v50, r30, r8
      stvewx128 v49, r11, r10
    }
    list = this->transforms.list;
    v23 = this->currentJointBuffer + 1;
    this->currentJointBuffer = v23 % 2;
    idJointBuffer::Update(this: &this->jointBuffers[v23 % 2], joints: list->mat, numUpdateJoints: num);
    v24 = 0;
    if ( this->modelData->surfaces.num > 0 )
    {
      v25 = 0;
      v26 = 0;
      do
      {
        v27 = this->modelData->surfaces.list[v26];
        idJointBuffer::Reference(
          this: this->surfaces.list[v25].joints,
          other: &this->jointBuffers[this->currentJointBuffer],
          jointRefOffset: v27->jointOffset,
          numRefJoints: v27->numJoints);
        ++v24;
        ++v26;
        ++v25;
      }
      while ( v24 < this->modelData->surfaces.num );
    }
    modelData = this->modelData;
    if ( modelData->timestamp != this->modelTimestamp )
    {
      idRenderModel::FinishSurfaces(this);
      modelData = this->modelData;
      this->modelTimestamp = modelData->timestamp;
    }
    maxRadius = modelData->maxRadius;
    v30 = (float)(v36[1] - modelData->maxRadius);
    v31 = (float)(v36[2] - modelData->maxRadius);
    v32 = (float)(v36[3] + modelData->maxRadius);
    v33 = v36[5];
    v34 = (float)(v36[4] + modelData->maxRadius);
    this->referenceBounds.b[0].x = v36[0] - modelData->maxRadius;
    this->referenceBounds.b[0].y = v30;
    this->referenceBounds.b[0].z = v31;
    this->referenceBounds.b[1].x = v32;
    this->referenceBounds.b[1].y = v34;
    this->referenceBounds.b[1].z = (float)v33 + (float)maxRadius;
    *p_changed = false;
  }
  return 1;
}


// ========================================================================
// ?SetBasePiecePosition@idRenderModelDiscreteAnimation@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x827D1200
// RVA : 0x007D1200
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void __fastcall idRenderModelDiscreteAnimation::SetBasePiecePosition(
        idRenderModelDiscreteAnimation *this,
        const idVec3 *position,
        const idMat3 *orientation)
{
  int num; // r11
  idJointMat *v4; // r11
  idJointMat *v5; // r11

  num = this->modelData->traceModels.num;
  if ( this->transforms.num > num )
  {
    v4 = &this->transforms.list[num];
    v4->mat[3] = position->x;
    v4->mat[7] = position->y;
    v4->mat[11] = position->z;
    v5 = &this->transforms.list[this->modelData->traceModels.num];
    v5->mat[0] = orientation->mat[0].x;
    v5->mat[1] = orientation->mat[1].x;
    v5->mat[2] = orientation->mat[2].x;
    v5->mat[4] = orientation->mat[0].y;
    v5->mat[5] = orientation->mat[1].y;
    v5->mat[6] = orientation->mat[2].y;
    v5->mat[8] = orientation->mat[0].z;
    v5->mat[9] = orientation->mat[1].z;
    v5->mat[10] = orientation->mat[2].z;
    this->collapsed.list[this->modelData->traceModels.num] = false;
    this->changed = true;
  }
}


// ========================================================================
// ?GetPieceTraceModel@idRenderModelDiscreteAnimation@@QAAXHAAVidTraceModel@@@Z
// EA  : 0x827D12C8
// RVA : 0x007D12C8
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void __fastcall idRenderModelDiscreteAnimation::GetPieceTraceModel(
        idRenderModelDiscreteAnimation *this,
        const int index,
        idTraceModel *traceModel)
{
  idTraceModel::operator=(this: traceModel, __that: &this->modelData->traceModels.list[index]);
}


// ========================================================================
// ??1idRenderModelDiscreteAnimation@@MAA@XZ
// EA  : 0x827D12F0
// RVA : 0x007D12F0
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void __fastcall idRenderModelDiscreteAnimation::~idRenderModelDiscreteAnimation(idRenderModelDiscreteAnimation *this)
{
  idJointBuffer *jointBuffers; // r27
  int v3; // r29
  idJointBuffer *v4; // r28
  bool *list; // r4
  idJointMat *v6; // r4

  this->__vftable = (idRenderModelDiscreteAnimation_vtbl *)&idRenderModelDiscreteAnimation::`vftable';
  jointBuffers = this->jointBuffers;
  v3 = 2;
  v4 = this->jointBuffers;
  do
  {
    idJointBuffer::FreeBufferObject(this: v4);
    --v3;
    ++v4;
  }
  while ( v3 != 0 );
  if ( this->collapsed.listStatic == 0 || this->collapsed.listStatic == 2 )
  {
    list = this->collapsed.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->collapsed.list = nullptr;
    this->collapsed.size = 0;
  }
  this->collapsed.num = 0;
  if ( this->transforms.listStatic == 0 || this->transforms.listStatic == 2 )
  {
    v6 = this->transforms.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->transforms.list = nullptr;
    this->transforms.size = 0;
  }
  this->transforms.num = 0;
  `eh vector destructor iterator'(
    ptr: jointBuffers,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idJointBuffer::~idJointBuffer);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$221703_0
// EA  : 0x827D13E0
// RVA : 0x007D13E0
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void _unwind_221703_0()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$221704
// EA  : 0x827D1408
// RVA : 0x007D1408
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void _unwind_221704()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 2044),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idJointBuffer::~idJointBuffer);
}


// ========================================================================
// __unwind$221705
// EA  : 0x827D1444
// RVA : 0x007D1444
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void _unwind_221705()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2080));
}


// ========================================================================
// __unwind$221706
// EA  : 0x827D1470
// RVA : 0x007D1470
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void _unwind_221706()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2096));
}


// ========================================================================
// ?LoadModelData@idRenderModelDiscreteAnimation@@AAAXXZ
// EA  : 0x827D1508
// RVA : 0x007D1508
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void __fastcall idRenderModelDiscreteAnimation::LoadModelData(idRenderModelDiscreteAnimation *this)
{
  const idDiscreteAnimationModelData *modelData; // r11
  idList<idJointMat,59> *p_transforms; // r26
  dimShadow_t v4; // r28
  int v5; // r29
  int v6; // r27
  idJointBuffer *jointBuffers; // r27
  int i; // r29
  int v9; // r27
  int v10; // r29
  idJointBuffer *v11; // r3
  idJointBuffer *v12; // r3

  modelData = this->modelData;
  if ( modelData != nullptr )
  {
    p_transforms = &this->transforms;
    this->modelTimestamp = modelData->timestamp;
    idList<idJointMat,59>::SetNum(this: &this->transforms, newNum: modelData->transforms.num);
    idList<unsigned char,19>::SetNum(
      this: (idList<unsigned char,37> *)&this->collapsed,
      newNum: this->modelData->transforms.num);
    v4 = DIMSHADOW_OFF;
    v5 = 0;
    if ( this->transforms.num > 0 )
    {
      v6 = 0;
      do
      {
        memcpy(
          Dst: &p_transforms->list[v6],
          Src: &this->modelData->transforms.list[v6],
          Size: sizeof(p_transforms->list[v6]));
        ++v6;
        this->collapsed.list[v5++] = false;
      }
      while ( v5 < this->transforms.num );
    }
    jointBuffers = this->jointBuffers;
    this->currentJointBuffer = 0;
    for ( i = 2; i != 0; --i )
      idJointBuffer::AllocBufferObject(
        this: jointBuffers++,
        joints: p_transforms->list->mat,
        numAllocJoints: this->transforms.num);
    v9 = 0;
    if ( this->modelData->surfaces.num > 0 )
    {
      v10 = 0;
      do
      {
        v11 = (idJointBuffer *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x10u,
                                 tag: TAG_RENDERMODEL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
        if ( v11 != nullptr )
          v12 = idJointBuffer::idJointBuffer(this: v11);
        else
          v12 = nullptr;
        idJointBuffer::Reference(
          this: v12,
          other: &this->jointBuffers[this->currentJointBuffer],
          jointRefOffset: this->modelData->surfaces.list[v10]->jointOffset,
          numRefJoints: this->modelData->surfaces.list[v10]->numJoints);
        idRenderModel::AddSurface(this, surf: nullptr);
        ++v9;
        ++v10;
      }
      while ( v9 < this->modelData->surfaces.num );
    }
    if ( !this->declBreakable->settings.noShadows && r_noBreakableShadows.valueInteger == 0 )
      v4 = DIMSHADOW_ON;
    this->g.castDimShadows = v4;
    idRenderModel::FinishSurfaces(this);
  }
}


// ========================================================================
// __unwind$222018
// EA  : 0x827D1728
// RVA : 0x007D1728
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void _unwind_222018()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 96), tag: TAG_RENDERMODEL);
}


// ========================================================================
// ?Load@idRenderModelDiscreteAnimation@@MAA_NPAVidFile@@@Z
// EA  : 0x827D1758
// RVA : 0x007D1758
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

int __fastcall idRenderModelDiscreteAnimation::Load(idRenderModelDiscreteAnimation *this, idFile *fp)
{
  int v5; // r4
  int v6; // r29
  int v7; // r31
  int v8; // r30
  int size; // r11
  int v10; // [sp+50h] [-40h] BYREF

  if ( !idRenderModel::Load(this, fp) || fp->Read(this: fp, a2: &v10, a3: 4u) == 0 )
    return 0;
  idList<idJointMat,59>::SetNum(this: &this->transforms, newNum: v10);
  v5 = v10;
  v6 = 0;
  if ( v10 > 0 )
  {
    v7 = 0;
    while ( fp->Read(this: fp, a2: &this->transforms.list[v7], a3: 48u) != 0 )
    {
      v5 = v10;
      ++v6;
      ++v7;
      if ( v6 >= v10 )
        goto LABEL_8;
    }
    return 0;
  }
LABEL_8:
  v8 = v5;
  if ( v5 <= this->collapsed.size
    || idList<unsigned char,25>::Resize(this: (idList<unsigned char,37> *)&this->collapsed, newsize: v5) )
  {
    size = this->collapsed.size;
    if ( v8 < size )
      size = v8;
    this->collapsed.num = size;
  }
  if ( fp->Read(this: fp, a2: this->collapsed.list, a3: this->collapsed.num) == 0 )
    return 0;
  this->changed = true;
  return 1;
}


// ========================================================================
// ?Reset@idRenderModelDiscreteAnimation@@QAAXXZ
// EA  : 0x827D1880
// RVA : 0x007D1880
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void __fastcall idRenderModelDiscreteAnimation::Reset(idRenderModelDiscreteAnimation *this)
{
  const idDiscreteAnimationModelData *modelData; // r11
  idList<idJointMat,59> *p_transforms; // r28
  int num; // r31
  int size; // r11
  int v6; // r30
  int v7; // r31

  modelData = this->modelData;
  p_transforms = &this->transforms;
  num = modelData->transforms.num;
  if ( num <= this->transforms.size
    || (unsigned __int8)idList<idJointMat,59>::Resize(this: &this->transforms, newsize: modelData->transforms.num) != 0 )
  {
    size = p_transforms->size;
    if ( num < size )
      size = num;
    p_transforms->num = size;
  }
  v6 = 0;
  if ( this->transforms.num > 0 )
  {
    v7 = 0;
    do
    {
      memcpy(
        Dst: &p_transforms->list[v7],
        Src: &this->modelData->transforms.list[v7],
        Size: sizeof(p_transforms->list[v7]));
      ++v6;
      ++v7;
    }
    while ( v6 < this->transforms.num );
  }
  this->changed = true;
  idRenderModel::CommitThisFrame(this);
}


// ========================================================================
// ?LoadModel@idRenderModelDiscreteAnimation@@AAA_NPBD@Z
// EA  : 0x827D1930
// RVA : 0x007D1930
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

int __fastcall idRenderModelDiscreteAnimation::LoadModel(idRenderModelDiscreteAnimation *this, char *modelName)
{
  const idDiscreteAnimationModelData *v5; // r3

  if ( this->modelData != nullptr )
    return 0;
  idRenderModel::SetName(this, name_: modelName);
  v5 = (const idDiscreteAnimationModelData *)idResourceList::Load(
                                               this: &idDiscreteAnimationModelData::resourceList,
                                               name: modelName,
                                               makeDefault: false,
                                               skipStaleCheck: false);
  this->modelData = v5;
  if ( v5 == nullptr )
    idLib::Error(
      fmt: "idRenderModelDiscreteAnimation - failed to load model '%s'. A map rebuild may be required.",
      modelName);
  idRenderModelDiscreteAnimation::LoadModelData(this);
  return 1;
}


// ========================================================================
// ??0idRenderModelDiscreteAnimation@@QAA@PBDPBVidDecl@@@Z
// EA  : 0x827D19D0
// RVA : 0x007D19D0
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

idRenderModelDiscreteAnimation *__fastcall idRenderModelDiscreteAnimation::idRenderModelDiscreteAnimation(
        idRenderModelDiscreteAnimation *this,
        char *modelName,
        idDecl *decl)
{
  idRenderModel::idRenderModel(this);
  this->__vftable = (idRenderModelDiscreteAnimation_vtbl *)&idRenderModelDiscreteAnimation::`vftable';
  `eh vector constructor iterator'(
    ptr: this->jointBuffers,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idJointBuffer::idJointBuffer,
    pDtor: (void (__fastcall *)(void *))idJointBuffer::~idJointBuffer);
  this->transforms.list = nullptr;
  this->transforms.granularity = 0;
  this->transforms.memTag = 59;
  this->transforms.listStatic = 0;
  this->transforms.size = 0;
  this->transforms.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->transforms);
  this->collapsed.list = nullptr;
  this->collapsed.granularity = 0;
  this->collapsed.memTag = 59;
  this->collapsed.listStatic = 0;
  this->collapsed.size = 0;
  this->collapsed.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->collapsed);
  this->modelData = nullptr;
  this->declBreakable = (const idDeclBreakable *)_RTDynamicCast(
                                                   inptr: decl,
                                                   VfDelta: 0,
                                                   SrcType: &idDecl `RTTI Type Descriptor',
                                                   TargetType: (void *)&idDeclBreakable `RTTI Type Descriptor',
                                                   isReference: 0);
  this->modelTimestamp = -1;
  this->changed = false;
  this->currentJointBuffer = 0;
  idRenderModelDiscreteAnimation::LoadModel(this, modelName);
  if ( !this->deferredPositionInitialized || !this->useDeferredPosition )
    this->g.origin = vec3_origin;
  this->deferredOrigin = vec3_origin;
  idRenderModel::SetAxis(this, a: &mat3_identity);
  *((_BYTE *)&this->g + 107) |= 0x40u;
  return this;
}


// ========================================================================
// __unwind$222307_0
// EA  : 0x827D1B30
// RVA : 0x007D1B30
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void _unwind_222307_0()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$222308
// EA  : 0x827D1B58
// RVA : 0x007D1B58
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void _unwind_222308()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 2044),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idJointBuffer::~idJointBuffer);
}


// ========================================================================
// __unwind$222309
// EA  : 0x827D1B94
// RVA : 0x007D1B94
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void _unwind_222309()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2080));
}


// ========================================================================
// __unwind$222310
// EA  : 0x827D1BC0
// RVA : 0x007D1BC0
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void _unwind_222310()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2096));
}


// ========================================================================
// `dynamic initializer for 'r_noBreakableShadows''
// EA  : 0x83342888
// RVA : 0x01342888
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_noBreakableShadows__()
{
  idCVar::idCVar(
    this: &r_noBreakableShadows,
    name: "r_noBreakableShadows",
    value: "0",
    flags: 1,
    description: "if 1, don't allow any dimshadows on breakables",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_noBreakableShadows__);
}


// ========================================================================
// `dynamic initializer for 'vector_float_posInfinity''
// EA  : 0x833428E0
// RVA : 0x013428E0
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void _dynamic_initializer_for__vector_float_posInfinity__()
{
  vector_float_posInfinity.vector4_f32[0] = 1.0e30;
  vector_float_posInfinity.vector4_f32[1] = 1.0e30;
  vector_float_posInfinity.vector4_f32[2] = 1.0e30;
  vector_float_posInfinity.vector4_f32[3] = 1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vector_float_negInfinity''
// EA  : 0x83342908
// RVA : 0x01342908
// PDB : w:\tech5\engine\models\discreteanimation\rendermodeldiscreteanimation.cpp
// ========================================================================

void _dynamic_initializer_for__vector_float_negInfinity__()
{
  vector_float_negInfinity.vector4_f32[0] = -1.0e30;
  vector_float_negInfinity.vector4_f32[1] = -1.0e30;
  vector_float_negInfinity.vector4_f32[2] = -1.0e30;
  vector_float_negInfinity.vector4_f32[3] = -1.0e30;
}

