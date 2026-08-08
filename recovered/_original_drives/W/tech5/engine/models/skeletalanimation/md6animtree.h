
// ========================================================================
// ??0idMD6LeafPlay@@QAA@XZ
// EA  : 0x82561050
// RVA : 0x00561050
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

idMD6LeafPlay *__fastcall idMD6LeafPlay::idMD6LeafPlay(idMD6LeafPlay *this)
{
  idMD6Leaf::idMD6Leaf(this, type_: NODE_LEAF_PLAY);
  this->startTime = 0;
  this->syncGroup = 0;
  this->syncEnabled = 0;
  this->rateScale = 1.0;
  return this;
}


// ========================================================================
// ??0idMD6LeafPause@@QAA@XZ
// EA  : 0x82592008
// RVA : 0x00592008
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

idMD6LeafPause *__fastcall idMD6LeafPause::idMD6LeafPause(idMD6LeafPause *this)
{
  idMD6Leaf::idMD6Leaf(this, type_: NODE_LEAF_PAUSE);
  this->currentDeferred = 0;
  `eh vector constructor iterator'(
    ptr: this->animMods,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idList<idMD6Blend::jointMod_t,30>::idList<idMD6Blend::jointMod_t,30>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  this->flags = 0;
  this->frame = 0.0;
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  return this;
}


// ========================================================================
// ??0idMD6BlendBranch_Base@@IAA@W4nodeType_t@idMD6Node@@@Z
// EA  : 0x82826F40
// RVA : 0x00826F40
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

idMD6BlendBranch_Base *__fastcall idMD6BlendBranch_Base::idMD6BlendBranch_Base(
        idMD6BlendBranch_Base *this,
        const idMD6Node::nodeType_t nodeType)
{
  this->type = nodeType;
  this->left = nullptr;
  this->currentAlpha = 0.0;
  this->targetAlpha = 0.0;
  this->right = nullptr;
  this->alphaRate = 0.0;
  this->leftTimeOverride = -1;
  this->rightTimeOverride = -1;
  this->filterGroup = 8;
  this->op = 10;
  this->originBlend = 0;
  this->blendType = BLEND_LINEAR;
  this->coordinateList.list = nullptr;
  this->coordinateList.granularity = 0;
  this->coordinateList.memTag = 30;
  this->coordinateList.listStatic = 0;
  this->coordinateList.size = 0;
  this->coordinateList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->coordinateList);
  this->animationList.list = nullptr;
  this->animationList.granularity = 0;
  this->animationList.memTag = 30;
  this->animationList.listStatic = 0;
  this->animationList.size = 0;
  this->animationList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animationList);
  return this;
}


// ========================================================================
// __unwind$220131
// EA  : 0x82826FF0
// RVA : 0x00826FF0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220131()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}


// ========================================================================
// ??0idMD6BlendAdditiveBranch@@QAA@XZ
// EA  : 0x82827020
// RVA : 0x00827020
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

idMD6BlendAdditiveBranch *__fastcall idMD6BlendAdditiveBranch::idMD6BlendAdditiveBranch(idMD6BlendAdditiveBranch *this)
{
  idMD6BlendBranch_Base::idMD6BlendBranch_Base(this, nodeType: NODE_BLENDA_BRANCH);
  this->baseAnimation = nullptr;
  this->currentCoordinate = 0.0;
  this->activeCoordinate = 0.0;
  return this;
}


// ========================================================================
// ??0idMD6BlendBranch@@QAA@XZ
// EA  : 0x828271C0
// RVA : 0x008271C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

idMD6BlendBranch *__fastcall idMD6BlendBranch::idMD6BlendBranch(idMD6BlendBranch *this)
{
  idMD6BlendBranch_Base::idMD6BlendBranch_Base(this, nodeType: NODE_BLEND_BRANCH);
  this->currentCoordinate.list = nullptr;
  this->currentCoordinate.granularity = 0;
  this->currentCoordinate.memTag = 30;
  this->currentCoordinate.listStatic = 0;
  this->currentCoordinate.size = 0;
  this->currentCoordinate.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->currentCoordinate);
  this->userChannelIndices.list = nullptr;
  this->userChannelIndices.granularity = 0;
  this->userChannelIndices.memTag = 30;
  this->userChannelIndices.listStatic = 0;
  this->userChannelIndices.size = 0;
  this->userChannelIndices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->userChannelIndices);
  this->activeCoordinate.list = nullptr;
  this->activeCoordinate.granularity = 0;
  this->activeCoordinate.memTag = 30;
  this->activeCoordinate.listStatic = 0;
  this->activeCoordinate.size = 0;
  this->activeCoordinate.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeCoordinate);
  this->activeIndices.list = nullptr;
  this->activeIndices.granularity = 0;
  this->activeIndices.memTag = 30;
  this->activeIndices.listStatic = 0;
  this->activeIndices.size = 0;
  this->activeIndices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeIndices);
  this->branchList.list = nullptr;
  this->branchList.granularity = 0;
  this->branchList.memTag = 30;
  this->branchList.listStatic = 0;
  this->branchList.size = 0;
  this->branchList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->branchList);
  this->isAngleWrapped = false;
  this->numDimensions = 1;
  return this;
}


// ========================================================================
// __unwind$220263
// EA  : 0x828272A0
// RVA : 0x008272A0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220263()
{
  int v0; // r12

  idSWFText::~idSWFText(this: *(idSWFText **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$220264
// EA  : 0x828272C8
// RVA : 0x008272C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220264()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 72));
}


// ========================================================================
// __unwind$220265
// EA  : 0x828272F4
// RVA : 0x008272F4
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220265()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 88));
}


// ========================================================================
// __unwind$220266
// EA  : 0x82827320
// RVA : 0x00827320
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220266()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 104));
}


// ========================================================================
// __unwind$220267
// EA  : 0x8282734C
// RVA : 0x0082734C
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220267()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 120));
}


// ========================================================================
// ??0idMD6BlendBranch@@IAA@W4nodeType_t@idMD6Node@@@Z
// EA  : 0x82827380
// RVA : 0x00827380
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

idMD6BlendBranch *__fastcall idMD6BlendBranch::idMD6BlendBranch(idMD6BlendBranch *this, idMD6Node::nodeType_t nodeType)
{
  idMD6BlendBranch_Base::idMD6BlendBranch_Base(this, nodeType);
  this->currentCoordinate.list = nullptr;
  this->currentCoordinate.granularity = 0;
  this->currentCoordinate.memTag = 30;
  this->currentCoordinate.listStatic = 0;
  this->currentCoordinate.size = 0;
  this->currentCoordinate.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->currentCoordinate);
  this->userChannelIndices.list = nullptr;
  this->userChannelIndices.granularity = 0;
  this->userChannelIndices.memTag = 30;
  this->userChannelIndices.listStatic = 0;
  this->userChannelIndices.size = 0;
  this->userChannelIndices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->userChannelIndices);
  this->activeCoordinate.list = nullptr;
  this->activeCoordinate.granularity = 0;
  this->activeCoordinate.memTag = 30;
  this->activeCoordinate.listStatic = 0;
  this->activeCoordinate.size = 0;
  this->activeCoordinate.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeCoordinate);
  this->activeIndices.list = nullptr;
  this->activeIndices.granularity = 0;
  this->activeIndices.memTag = 30;
  this->activeIndices.listStatic = 0;
  this->activeIndices.size = 0;
  this->activeIndices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeIndices);
  this->branchList.list = nullptr;
  this->branchList.granularity = 0;
  this->branchList.memTag = 30;
  this->branchList.listStatic = 0;
  this->branchList.size = 0;
  this->branchList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->branchList);
  this->numDimensions = 1;
  return this;
}


// ========================================================================
// __unwind$220325
// EA  : 0x82827458
// RVA : 0x00827458
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220325()
{
  int v0; // r12

  idSWFText::~idSWFText(this: *(idSWFText **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$220326
// EA  : 0x82827480
// RVA : 0x00827480
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220326()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 72));
}


// ========================================================================
// __unwind$220327
// EA  : 0x828274AC
// RVA : 0x008274AC
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220327()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 88));
}


// ========================================================================
// __unwind$220328
// EA  : 0x828274D8
// RVA : 0x008274D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220328()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 104));
}


// ========================================================================
// __unwind$220329
// EA  : 0x82827504
// RVA : 0x00827504
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220329()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 120));
}


// ========================================================================
// ??0idMD6FusionBranch@@QAA@XZ
// EA  : 0x82827538
// RVA : 0x00827538
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

idMD6FusionBranch *__fastcall idMD6FusionBranch::idMD6FusionBranch(idMD6FusionBranch *this)
{
  idMD6BlendBranch::idMD6BlendBranch(this, nodeType: NODE_FUSION_BRANCH);
  this->phaseToFrameLookupData.list = nullptr;
  this->phaseToFrameLookupData.granularity = 0;
  this->phaseToFrameLookupData.memTag = 30;
  this->phaseToFrameLookupData.listStatic = 0;
  this->phaseToFrameLookupData.size = 0;
  this->phaseToFrameLookupData.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->phaseToFrameLookupData);
  return this;
}


// ========================================================================
// __unwind$220387
// EA  : 0x828275A4
// RVA : 0x008275A4
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void _unwind_220387()
{
  int v0; // r12

  idMD6BlendBranch::~idMD6BlendBranch(this: *(idMD6BlendBranch **)(v0 - 112 + 132));
}


// ========================================================================
// ?Compare@idSearch_CoordinateNodePair@idMD6BlendBranch_Base@@QBAHABV?$idPair@UCoordinate_t@idMD6BlendBranch_Base@@PAVidMD6Node@@@@0@Z
// EA  : 0x8283DAC0
// RVA : 0x0083DAC0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

int __fastcall idMD6BlendBranch_Base::idSearch_CoordinateNodePair::Compare(
        idMD6BlendBranch_Base::idSearch_CoordinateNodePair *this,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *a,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *b)
{
  int v3; // r10
  int i; // r11
  double v5; // fp0
  double v6; // fp13

  v3 = 0;
  if ( a->first.size <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v5 = a->first.data[i];
    v6 = b->first.data[i];
    if ( v5 < v6 )
      return -1;
    if ( v5 > v6 )
      break;
    if ( ++v3 >= a->first.size )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?Cross@idMD6BlendBranch@@IBAXABV?$idArray@M$05@@0AAV2@@Z
// EA  : 0x8283E5C0
// RVA : 0x0083E5C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void __fastcall idMD6BlendBranch::Cross(
        idMD6BlendBranch *this,
        const idArray<float,6> *v1,
        const idArray<float,6> *v2,
        idArray<float,6> *out)
{
  unsigned int v4; // r10
  int v5; // r7
  float *v6; // r9
  const unsigned int *v7; // r11
  unsigned int v8; // r6
  unsigned int v9; // r31
  unsigned int v10; // r7

  v4 = 0;
  v5 = *(const unsigned int *)((char *)idMD6BlendBranch::crossIndexTableBase + __ROL4__(this->numDimensions, 2));
  if ( this->numDimensions != 0 )
  {
    v6 = &out[-1].ptr[5];
    v7 = &idMD6BlendBranch::crossIndexTable[v5 - 3];
    do
    {
      ++v4;
      v8 = v7[6];
      v9 = v7[3];
      v10 = v7[5];
      v7 += 4;
      *++v6 = (float)(v1->ptr[v9] * v2->ptr[*v7]) - (float)(v2->ptr[v8] * v1->ptr[v10]);
    }
    while ( v4 < this->numDimensions );
  }
}


// ========================================================================
// ?UpdateNormal@idMD6BlendBranch@@IBAXABV?$idArray@M$05@@00AAV2@@Z
// EA  : 0x8283E650
// RVA : 0x0083E650
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.h
// ========================================================================

void __fastcall idMD6BlendBranch::UpdateNormal(
        idMD6BlendBranch *this,
        const idArray<float,6> *p0,
        const idArray<float,6> *p1,
        const idArray<float,6> *inNormal,
        idArray<float,6> *outNormal)
{
  unsigned int numDimensions; // r25
  unsigned int v6; // r8
  float *v7; // r31
  float *v8; // r10
  float *v9; // r11
  double v10; // fp13
  double v11; // fp6
  double v12; // fp5
  double v13; // fp4
  float *v14; // r11
  unsigned int v15; // ctr
  int v16; // [sp+40h] [-70h] BYREF
  idArray<float,6> v17[4]; // [sp+50h] [-60h] BYREF

  numDimensions = this->numDimensions;
  v6 = 0;
  if ( numDimensions >= 4 )
  {
    v7 = (float *)&v16;
    v8 = &p1[-1].ptr[5];
    v9 = &p0->ptr[1];
    do
    {
      v10 = v8[1];
      v6 += 4;
      v11 = (float)(v8[3] - v9[1]);
      v8 += 4;
      v12 = *(v9 - 1);
      v13 = (float)(*v8 - v9[2]);
      *(float *)((char *)v9 + (char *)v17 - (char *)p0) = *(float *)((char *)v9 + (char *)p1 - (char *)p0) - *v9;
      *(float *)((char *)v9 + (char *)&v17[0].ptr[1] - (char *)p0) = v11;
      *(float *)((char *)v9 + (char *)&v17[0].ptr[2] - (char *)p0) = v13;
      v9 += 4;
      v7 += 4;
      *v7 = (float)v10 - (float)v12;
    }
    while ( v6 < numDimensions - 3 );
  }
  if ( v6 < numDimensions )
  {
    v14 = &p0->ptr[v6];
    v15 = numDimensions - v6;
    do
    {
      *(float *)((char *)v14 + (char *)v17 - (char *)p0) = *(float *)((char *)v14 + (char *)p1 - (char *)p0) - *v14;
      ++v14;
      --v15;
    }
    while ( v15 != 0 );
  }
  idMD6BlendBranch::Cross(this, v1: inNormal, v2: v17, out: outNormal);
}

