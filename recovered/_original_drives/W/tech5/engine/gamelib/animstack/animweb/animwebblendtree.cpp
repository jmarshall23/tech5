
// ========================================================================
// ?UsesAnyScalarIndices@idAnimWebBlendTree@@QBA_NPBVidAnimator_AnimWeb@@ABV?$idList@H$04@@@Z
// EA  : 0x826F6690
// RVA : 0x006F6690
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

int __fastcall idAnimWebBlendTree::UsesAnyScalarIndices(
        idAnimWebBlendTree *this,
        const idAnimator_AnimWeb *web,
        const idList<int,5> *testScalars)
{
  int num; // r31
  int v4; // r4
  int v5; // r6
  idAnimWebScalarPair *i; // r7
  int v7; // r10
  int v8; // r11

  num = this->scalarPairs.num;
  v4 = 0;
  if ( num <= 0 )
    return 0;
  v5 = testScalars->num;
  for ( i = this->scalarPairs.list; ; ++i )
  {
    v7 = 0;
    if ( v5 > 0 )
      break;
LABEL_7:
    if ( ++v4 >= num )
      return 0;
  }
  v8 = 0;
  while ( testScalars->list[v8] != i->scalarIndex )
  {
    ++v7;
    ++v8;
    if ( v7 >= v5 )
      goto LABEL_7;
  }
  return 1;
}


// ========================================================================
// ?StartTreePlaying_r@idAnimWebBlendTree@@AAAXPAVidAnimator_AnimWeb@@PBVidDeclMD6@@PBVidMD6AnimProps@@HHHPAVidMD6Node@@@Z
// EA  : 0x826F6708
// RVA : 0x006F6708
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void __fastcall idAnimWebBlendTree::StartTreePlaying_r(
        idAnimWebBlendTree *this,
        idAnimator_AnimWeb *web,
        const idDeclMD6 *md6Decl,
        idMD6AnimProps *animProps,
        int numAnimProps,
        int curTime,
        int ticksPerSec,
        idMD6Node *node)
{
  idMD6Node *i; // r31
  int type; // r10
  char v17; // r11
  idMD6Node *v18; // r10
  int v19; // r25
  int v20; // r29
  idMD6Node *v21; // r10
  int v22; // r25
  int v23; // r29
  idMD6Node *v24; // r10
  int v25; // r30
  idMD6AnimProps *j; // r29
  const idMD6Anim *v27; // r25
  char v28; // r11

  for ( i = node; i->type != 3; i = *(idMD6Node **)&i[8].type )
  {
    type = i->type;
    if ( type == 4 || type == 5 )
      break;
    if ( i->type == 0 || (v17 = 0, type == 3) )
      v17 = 1;
    if ( v17 == 0 )
    {
      if ( type == 6 )
      {
        v22 = 0;
        if ( *(int *)&i[8].type > 0 )
        {
          v23 = 0;
          do
          {
            v24 = *(idMD6Node **)(*(_DWORD *)&i[4].type + v23);
            if ( v24 != nullptr )
              idAnimWebBlendTree::StartTreePlaying_r(
                this,
                web,
                md6Decl,
                animProps,
                numAnimProps,
                curTime,
                ticksPerSec,
                node: v24);
            ++v22;
            v23 += 4;
          }
          while ( v22 < *(_DWORD *)&i[8].type );
        }
      }
      else if ( type == 2 )
      {
        v25 = 0;
        if ( numAnimProps > 0 )
        {
          for ( j = animProps; ; ++j )
          {
            v27 = *(const idMD6Anim **)&i[4].type;
            if ( idMD6AnimProps::SelectAnim(this: j, declMD6: md6Decl, index: 0) == v27 )
              break;
            if ( ++v25 >= numAnimProps )
              return;
          }
          if ( &animProps[v25] != nullptr )
          {
            idMD6LeafPlay::Restart(
              this: (idMD6LeafPlay *)i,
              gameTime: curTime,
              ticksPerSec,
              inFrame: 0,
              inWrapMode: (const idMD6Leaf::wrapMode_t)animProps[v25].wrap);
            i[10].type = (curTime >> 4) % 255;
            if ( web->channelWeightAnimator.baseAnimation.animation == nullptr
              || web->channelWeightAnimator.leaves.num <= 0
              || (v28 = 1, web->channelWeightAnimator.userChannelToLeafMap.num <= 0) )
            {
              v28 = 0;
            }
            if ( v28 != 0 )
              idAnimator_ChannelWeight::SetControlAnimation(
                this: &web->channelWeightAnimator,
                animation: (const idMD6LeafPlay *)i,
                lockOwner_: nullptr);
          }
        }
      }
      return;
    }
    idAnimWebBlendTree::StartTreePlaying_r(
      this,
      web,
      md6Decl,
      animProps,
      numAnimProps,
      curTime,
      ticksPerSec,
      node: *(idMD6Node **)&i[4].type);
  }
  if ( i->type == 4 )
  {
    v18 = *(idMD6Node **)&i[80].type;
    if ( v18 != nullptr )
      idAnimWebBlendTree::StartTreePlaying_r(
        this,
        web,
        md6Decl,
        animProps,
        numAnimProps,
        curTime,
        ticksPerSec,
        node: v18);
  }
  v19 = 0;
  if ( *(int *)&i[60].type > 0 )
  {
    v20 = 0;
    do
    {
      v21 = *(idMD6Node **)(v20 + *(_DWORD *)&i[56].type);
      if ( v21 != nullptr )
        idAnimWebBlendTree::StartTreePlaying_r(
          this,
          web,
          md6Decl,
          animProps,
          numAnimProps,
          curTime,
          ticksPerSec,
          node: v21);
      ++v19;
      v20 += 4;
    }
    while ( v19 < *(_DWORD *)&i[60].type );
  }
}


// ========================================================================
// ?GetAnimLength@idAnimWebBlendTree@@QBA_NHHW4wrapMode_t@idMD6Leaf@@_NAAH22@Z
// EA  : 0x826F69A8
// RVA : 0x006F69A8
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

unsigned int __fastcall idAnimWebBlendTree::GetAnimLength(
        idAnimWebBlendTree *this,
        int curTime,
        int ticksPerSec,
        const idMD6Leaf::wrapMode_t wrapMode,
        const bool ignoreAdditive,
        int *curFrame,
        int *numFrames,
        int *frameRate)
{
  idMD6Node *tree; // r11
  int v16; // r29
  idMD6LeafPlay **v17; // r30
  idMD6LeafPlay *v18; // r31
  int type; // r11
  char v20; // r11
  bool v21; // zf
  const idMD6Node *anim; // r4
  const idMD6Node *v23; // r4
  unsigned int v24; // r11
  const idMD6Anim *v25; // r9
  int v26; // r11
  char v27; // r11
  const idMD6Anim *v28; // r10
  int animData; // r11
  int v30; // r11
  int v31; // r11
  idMD6AnimData *v32; // r11
  int v33; // r11
  idMD6Node *v35; // [sp+50h] [-E0h] BYREF

  tree = this->tree;
  *numFrames = 0;
  v35 = tree;
  v16 = 0;
  v17 = (idMD6LeafPlay **)&v35;
  do
  {
    v18 = *v17;
    type = (*v17)->type;
    if ( (*v17)->type == 0 || type == 3 || type == 4 || (v21 = type != 5, v20 = 0, !v21) )
      v20 = 1;
    if ( v20 != 0 )
    {
      anim = (const idMD6Node *)v18->anim;
      --v16;
      --v17;
      if ( anim != nullptr && !idMD6Branch::IsChildBlendedOut(this: (idMD6Branch *)v18, child: anim) )
      {
        ++v16;
        *++v17 = (idMD6LeafPlay *)v18->anim;
      }
      v23 = *(const idMD6Node **)&v18->weightGroup;
      if ( v23 != nullptr && !idMD6Branch::IsChildBlendedOut(this: (idMD6Branch *)v18, child: v23) )
      {
        ++v16;
        *++v17 = *(idMD6LeafPlay **)&v18->weightGroup;
      }
    }
    else if ( v18->type == 6 )
    {
      v24 = *(_DWORD *)&v18->weightGroup;
      --v16;
      --v17;
      if ( v24 != 0 )
      {
        v25 = v18->anim;
        if ( *(idMD6Anim_vtbl **)((char *)&v25->__vftable
                                + ((4
                                  * (((__PAIR64__(v24 >> 31, HIWORD(v18[3].rateScale)) - v24) >> 32)
                                   & HIWORD(v18[3].rateScale)))
                                 & 0x3FFFC)) != nullptr )
        {
          ++v16;
          *++v17 = *(idMD6LeafPlay **)((char *)&v25->__vftable
                                     + ((4
                                       * (((__PAIR64__(v24 >> 31, HIWORD(v18[3].rateScale)) - v24) >> 32)
                                        & HIWORD(v18[3].rateScale)))
                                      & 0x3FFFC));
        }
      }
    }
    else
    {
      v26 = v18->type;
      if ( v26 == 1 || (v21 = v26 != 2, v27 = 0, !v21) )
        v27 = 1;
      if ( v27 != 0 )
      {
        v28 = v18->anim;
        animData = (int)v28->animData;
        if ( animData != 0 )
          animData = *(unsigned __int16 *)(animData + 8);
        if ( animData > *numFrames
          && (wrapMode == WRAP_MAX || v18->wrapMode == wrapMode)
          && (!ignoreAdditive || (v28->animData->flags & 1) == 0) )
        {
          v30 = v18->type;
          if ( v30 == 2 )
          {
            *curFrame = idMD6LeafPlay::GetFrame(this: *v17, gameTime: curTime, ticksPerSec);
          }
          else if ( v30 == 1 )
          {
            *curFrame = (int)*(float *)&v18[2].anim;
          }
          v31 = (int)v18->anim->animData;
          if ( v31 != 0 )
            v31 = *(unsigned __int16 *)(v31 + 8);
          *numFrames = v31;
          v32 = v18->anim->animData;
          if ( v32 != nullptr )
            v33 = v32->frameRate;
          else
            v33 = 30;
          *frameRate = v33;
        }
        --v16;
        --v17;
      }
    }
  }
  while ( v16 >= 0 );
  return (-*numFrames & (unsigned int)~*numFrames) >> 31;
}


// ========================================================================
// ??0idAnimWebBlendTree@@QAA@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x826F6C30
// RVA : 0x006F6C30
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

idAnimWebBlendTree *__fastcall idAnimWebBlendTree::idAnimWebBlendTree(
        idAnimWebBlendTree *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *_nodeIndex)
{
  this->nodeIndex.value = (__int16)_nodeIndex;
  this->tree = nullptr;
  this->modelIndex = 0;
  this->web = nullptr;
  this->scalarPairs.list = nullptr;
  this->scalarPairs.granularity = 0;
  this->scalarPairs.memTag = 33;
  this->scalarPairs.listStatic = 0;
  this->scalarPairs.size = 0;
  this->scalarPairs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalarPairs);
  this->leaves.list = nullptr;
  this->leaves.granularity = 0;
  this->leaves.memTag = 33;
  this->leaves.listStatic = 0;
  this->leaves.size = 0;
  this->leaves.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->leaves);
  return this;
}


// ========================================================================
// __unwind$248630
// EA  : 0x826F6CAC
// RVA : 0x006F6CAC
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_248630()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 12));
}


// ========================================================================
// ?CopyScalars@idAnimWebBlendTree@@QBAXPBVidAnimator_AnimWeb@@HHE@Z
// EA  : 0x826F6CE0
// RVA : 0x006F6CE0
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void __fastcall idAnimWebBlendTree::CopyScalars(
        idAnimWebBlendTree *this,
        const idAnimator_AnimWeb *web,
        int curTime,
        int ticksPerSec,
        const unsigned __int8 fieldFlags)
{
  int v9; // r18
  idAnimWebScalarPair *v10; // r30
  idMD6Node *node; // r28
  int type; // r11
  char v13; // r11
  bool v14; // zf
  int v15; // r11
  char v16; // r11
  int fieldType; // r11
  double Scalar; // fp1
  int v19; // r27
  __int64 v20; // r10
  __int64 v21; // r8
  bfx::Orienter *v22; // r30
  double VolumeAdjustment; // fp1
  int v24; // r29
  float m_maxFlockAccDist; // r11
  const bfx::MoverTune *m_pTune; // r11
  int v27; // r30
  float v28; // r11
  const char *v29; // r29
  unsigned __int16 Frame; // r3
  int num; // r5
  int v32; // r30
  int v33; // r29
  int v34; // r11
  __int64 v35; // r6
  va *v36; // r3
  int v37; // r11
  int v38; // r27
  __int64 v39; // r10
  __int64 v40; // r8
  const idMD6LeafPlay *v41; // r11
  double v42; // fp1
  __int64 v43; // r11
  int v44; // r5
  int v45; // r30
  int v46; // r29
  int v47; // r11
  __int64 v48; // r6
  va *v49; // r3
  int v50; // [sp+8h] [-1148h]
  int v51; // [sp+Ch] [-1144h]
  int v52; // [sp+10h] [-1140h]
  int v53; // [sp+14h] [-113Ch]
  int v54; // [sp+18h] [-1138h]
  int v55; // [sp+1Ch] [-1134h]
  int v56; // [sp+58h] [-10F8h]
  idStr v58; // [sp+70h] [-10E0h] BYREF
  idStr v59; // [sp+90h] [-10C0h] BYREF
  va v60; // [sp+B0h] [-10A0h] BYREF

  v56 = 0;
  if ( this->scalarPairs.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = &this->scalarPairs.list[v9];
      if ( (fieldFlags & v10->fieldFlags) != 0 )
      {
        node = v10->node;
        if ( node->type == 3 || node->type == 5 )
        {
          if ( v10->fieldType == 4 )
            *(float *)(4 * v10->coordinateIndex + *(_DWORD *)&node[72].type) = idAnimWebScalar::GetScalar(
                                                                                 this: &web->scalars.list[v10->scalarIndex],
                                                                                 memBlock: &web->scalarMem);
        }
        else if ( node->type == 4 )
        {
          if ( v10->fieldType == 4 )
            *(float *)&node[72].type = idAnimWebScalar::GetScalar(
                                         this: &web->scalars.list[v10->scalarIndex],
                                         memBlock: &web->scalarMem);
        }
        else
        {
          type = node->type;
          if ( node->type == 0 || type == 3 || type == 4 || (v14 = type != 5, v13 = 0, !v14) )
            v13 = 1;
          if ( v13 != 0 )
          {
            if ( v10->fieldType == 0 )
            {
              *(float *)&node[24].type = idAnimWebScalar::GetScalar(
                                           this: &web->scalars.list[v10->scalarIndex],
                                           memBlock: &web->scalarMem);
              *(float *)&node[28].type = idAnimWebScalar::GetScalar(
                                           this: &web->scalars.list[v10->scalarIndex],
                                           memBlock: &web->scalarMem);
              *(float *)&node[32].type = 0.0;
            }
          }
          else if ( node->type == 6 )
          {
            if ( v10->fieldType == 0
              && (v10->fieldFlags & 0x10) != 0
              && __fabs(idAnimWebScalar::GetScalar(this: &web->scalars.list[v10->scalarIndex], memBlock: &web->scalarMem)) >= idMath::FLT_SMALLEST_NON_DENORMAL )
            {
              *(_DWORD *)&node[76].type |= 1 << v10->data1;
            }
          }
          else
          {
            v15 = node->type;
            if ( v15 == 1 || (v14 = v15 != 2, v16 = 0, !v14) )
              v16 = 1;
            if ( v16 != 0 )
            {
              if ( node->type == 2 )
              {
                fieldType = v10->fieldType;
                if ( fieldType == 1 )
                {
                  Scalar = idAnimWebScalar::GetScalar(
                             this: &web->scalars.list[v10->scalarIndex],
                             memBlock: &web->scalarMem);
                  idMD6LeafPlay::SetRateScale(this: (idMD6LeafPlay *)node, gameTime: curTime, rs: Scalar);
                }
                else if ( fieldType == 2 )
                {
                  v19 = (int)idAnimWebScalar::GetScalar(
                               this: &web->scalars.list[v10->scalarIndex],
                               memBlock: &web->scalarMem);
                  if ( (v10->fieldFlags & 4) != 0 )
                  {
                    HIDWORD(v20) = v10->data1;
                    HIDWORD(v21) = v19 / SHIDWORD(v20);
                    LODWORD(v21) = __ROL4__(v19, 1) - 1;
                    __twllei(HIDWORD(v20), 0);
                    __twlgei(HIDWORD(v20) & ~(_DWORD)v21, 0xFFFFFFFF);
                    v19 %= SHIDWORD(v20);
                  }
                  if ( (v10->fieldFlags & 8) != 0 )
                    v19 += v10->data2;
                  if ( v19 < 0 || v19 >= this->leaves.num )
                  {
                    v59.allocedAndFlag = 20;
                    v59.len = 0;
                    v59.data = v59.baseBuffer;
                    v59.baseBuffer[0] = 0;
                    v32 = 0;
                    num = this->leaves.num;
                    if ( num > 0 )
                    {
                      v33 = 0;
                      do
                      {
                        LODWORD(v20) = this->leaves.list[v33];
                        v34 = *(_DWORD *)(v20 + 4);
                        if ( v34 != 0 )
                        {
                          LODWORD(v35) = *(_DWORD *)(v34 + 8);
                          HIDWORD(v35) = v32;
                          v36 = va::va(
                                  this: &v60,
                                  fmt: "\tanim %d: %s\n",
                                  a3: v35,
                                  a4: v21,
                                  a5: v20,
                                  a6: v50,
                                  a7: v51,
                                  a8: v52,
                                  a9: v53,
                                  a10: v54,
                                  a11: v55);
                          idStr::Append(this: &v59, text: v36);
                        }
                        ++v32;
                        ++v33;
                        num = this->leaves.num;
                      }
                      while ( v32 < num );
                    }
                    idLib::Warning(
                      fmt: "Anim array index out of range! Index = %d, range = [0,%d)%s",
                      v19,
                      num,
                      v59.data);
                    idStr::FreeData(this: &v59);
                  }
                  else
                  {
                    v22 = (bfx::Orienter *)this->leaves.list[v19];
                    if ( v22 != nullptr )
                    {
                      *(_DWORD *)&node[4].type = v22->m_pTune;
                      VolumeAdjustment = idSoundEmitterLocal::GetVolumeAdjustment(this: v22);
                      idMD6LeafPlay::SetRateScale(this: (idMD6LeafPlay *)node, gameTime: curTime, rs: VolumeAdjustment);
                      v24 = 0;
                      m_maxFlockAccDist = v22->m_pTune->m_maxFlockAccDist;
                      if ( m_maxFlockAccDist != 0.0 )
                        v24 = *(unsigned __int16 *)(LODWORD(m_maxFlockAccDist) + 8);
                      if ( idMD6LeafPlay::GetFrame(this: (idMD6LeafPlay *)node, gameTime: curTime, ticksPerSec) >= v24 )
                      {
                        m_pTune = v22->m_pTune;
                        v27 = 0;
                        v28 = m_pTune->m_maxFlockAccDist;
                        if ( v28 != 0.0 )
                          v27 = *(unsigned __int16 *)(LODWORD(v28) + 8);
                        v29 = *(const char **)(*(_DWORD *)&node[4].type + 8);
                        Frame = idMD6LeafPlay::GetFrame(this: (idMD6LeafPlay *)node, gameTime: curTime, ticksPerSec);
                        idLib::Warning(
                          fmt: "Leaf '%s' current frame is out of range for indexed anim '%s'! Cur = %d, range = [0, %d)",
                          v29,
                          v29,
                          Frame,
                          v27);
                      }
                    }
                  }
                }
              }
              else if ( node->type == 1 )
              {
                v37 = v10->fieldType;
                if ( v37 == 3 )
                {
                  *(float *)&node[52].type = idAnimWebScalar::GetScalar(
                                               this: &web->scalars.list[v10->scalarIndex],
                                               memBlock: &web->scalarMem);
                }
                else if ( v37 == 2 )
                {
                  v38 = (int)idAnimWebScalar::GetScalar(
                               this: &web->scalars.list[v10->scalarIndex],
                               memBlock: &web->scalarMem);
                  if ( (v10->fieldFlags & 4) != 0 )
                  {
                    HIDWORD(v39) = v10->data1;
                    HIDWORD(v40) = v38 / SHIDWORD(v39);
                    LODWORD(v40) = __ROL4__(v38, 1) - 1;
                    __twllei(HIDWORD(v39), 0);
                    __twlgei(HIDWORD(v39) & ~(_DWORD)v40, 0xFFFFFFFF);
                    v38 %= SHIDWORD(v39);
                  }
                  if ( (v10->fieldFlags & 8) != 0 )
                    v38 += v10->data2;
                  if ( v38 < 0 || v38 >= this->leaves.num )
                  {
                    v58.allocedAndFlag = 20;
                    v58.len = 0;
                    v58.data = v58.baseBuffer;
                    v58.baseBuffer[0] = 0;
                    v45 = 0;
                    v44 = this->leaves.num;
                    if ( v44 > 0 )
                    {
                      v46 = 0;
                      do
                      {
                        LODWORD(v39) = this->leaves.list[v46];
                        v47 = *(_DWORD *)(v39 + 4);
                        if ( v47 != 0 )
                        {
                          LODWORD(v48) = *(_DWORD *)(v47 + 8);
                          HIDWORD(v48) = v45;
                          v49 = va::va(
                                  this: &v60,
                                  fmt: "\tanim %d: %s\n",
                                  a3: v48,
                                  a4: v40,
                                  a5: v39,
                                  a6: v50,
                                  a7: v51,
                                  a8: v52,
                                  a9: v53,
                                  a10: v54,
                                  a11: v55);
                          idStr::Append(this: &v58, text: v49);
                        }
                        ++v45;
                        ++v46;
                        v44 = this->leaves.num;
                      }
                      while ( v45 < v44 );
                    }
                    idLib::Warning(
                      fmt: "Anim array index out of range! Index = %d, range = [0,%d)%s",
                      v38,
                      v44,
                      v58.data);
                    idStr::FreeData(this: &v58);
                  }
                  else
                  {
                    v41 = this->leaves.list[v38];
                    if ( v41 != nullptr )
                    {
                      HIDWORD(v43) = v41->anim;
                      v42 = *(float *)&node[52].type;
                      *(_DWORD *)&node[4].type = HIDWORD(v43);
                      LODWORD(v43) = v41->anim->animData;
                      LODWORD(v43) = (_DWORD)v43 != 0 ? *(unsigned __int16 *)(v43 + 8) : 0;
                      if ( v42 >= (float)v43 )
                        idLib::Warning(
                          fmt: "Leaf '%s' current frame is out of range for indexed anim '%s'! Cur = %f, range = [0, %d)",
                          *(const char **)(*(_DWORD *)&node[4].type + 8),
                          *(const char **)(*(_DWORD *)&node[4].type + 8),
                          v42,
                          LODWORD(v42));
                    }
                  }
                }
              }
            }
          }
        }
      }
      ++v9;
      ++v56;
    }
    while ( v56 < this->scalarPairs.num );
  }
}


// ========================================================================
// __unwind$248682
// EA  : 0x826F73BC
// RVA : 0x006F73BC
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_248682()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 144));
}


// ========================================================================
// __unwind$248683
// EA  : 0x826F73E4
// RVA : 0x006F73E4
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_248683()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 112));
}


// ========================================================================
// ?BeginPlaying@idAnimWebBlendTree@@QAAXPAVidAnimator_AnimWeb@@PBVidMD6AnimProps@@HHH@Z
// EA  : 0x826F74E0
// RVA : 0x006F74E0
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void __fastcall idAnimWebBlendTree::BeginPlaying(
        idAnimWebBlendTree *this,
        idAnimator_AnimWeb *web,
        idMD6AnimProps *animProps,
        int numAnimProps,
        int curTime,
        int ticksPerSec)
{
  idAnimWebBlendTree::CopyScalars(this, web, curTime, ticksPerSec, fieldFlags: 2u);
  idAnimWebBlendTree::StartTreePlaying_r(
    this,
    web,
    md6Decl: web->modelDecls.list[this->modelIndex],
    animProps,
    numAnimProps,
    curTime,
    ticksPerSec,
    node: this->tree);
}


// ========================================================================
// ?PreBlendTree@idAnimWebBlendTree@@QBAXPBVidAnimator_AnimWeb@@HH@Z
// EA  : 0x826F7550
// RVA : 0x006F7550
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void __fastcall idAnimWebBlendTree::PreBlendTree(
        idAnimWebBlendTree *this,
        const idAnimator_AnimWeb *web,
        int curTime,
        int ticksPerSec)
{
  idAnimWebBlendTree::CopyScalars(this, web, curTime, ticksPerSec, fieldFlags: 1u);
}


// ========================================================================
// ?GetUsedScalarIndices@idAnimWebBlendTree@@QBAXPBVidAnimator_AnimWeb@@AAV?$idList@H$04@@HH@Z
// EA  : 0x826F7558
// RVA : 0x006F7558
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void __fastcall idAnimWebBlendTree::GetUsedScalarIndices(
        idAnimWebBlendTree *this,
        const idAnimator_AnimWeb *web,
        idList<enum encounterGroupRole_t,5> *usedScalars,
        encounterGroupRole_t minIndex,
        encounterGroupRole_t maxIndex)
{
  int v9; // r27
  int v10; // r29
  const encounterGroupRole_t *v11; // r4
  int num; // r7
  int v13; // r10
  int v14; // r11

  v9 = 0;
  if ( this->scalarPairs.num > 0 )
  {
    v10 = 0;
    do
    {
      v11 = (const encounterGroupRole_t *)&this->scalarPairs.list[v10];
      if ( (minIndex < ROLE_NONE || *v11 >= minIndex) && (maxIndex <= ROLE_NONE || *v11 <= maxIndex) )
      {
        num = usedScalars->num;
        v13 = 0;
        if ( num <= 0 )
          goto LABEL_13;
        v14 = 0;
        while ( usedScalars->list[v14] != *v11 )
        {
          ++v13;
          ++v14;
          if ( v13 >= num )
            goto LABEL_13;
        }
        if ( v13 < 0 )
LABEL_13:
          idList<idAnimWebBlendTree *,5>::Append(this: usedScalars, obj: v11);
      }
      ++v9;
      ++v10;
    }
    while ( v9 < this->scalarPairs.num );
  }
}


// ========================================================================
// ?EnumerateTree_r@idAnimWebBlendTree@@AAAXPAVidMD6Node@@AAV?$idStaticList@PBVidMD6Node@@$0CA@@@@Z
// EA  : 0x826F7620
// RVA : 0x006F7620
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void __fastcall idAnimWebBlendTree::EnumerateTree_r(
        idAnimWebBlendTree *this,
        const idVoiceEvent *node,
        idList<idVoiceEvent const *,5> *list,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        const idVoiceEvent *a14)
{
  const idVoiceEvent *i; // r31
  int v17; // r10
  char v18; // r11
  unsigned int v19; // r10
  int startMS; // r9

  a14 = node;
  for ( i = node; i != nullptr; a14 = i )
  {
    idList<idDeclMD6 const *,5>::AddUnique(this: list, obj: &a14);
    v17 = HIBYTE(i->__vftable);
    if ( HIBYTE(i->__vftable) == 0 || v17 == 3 || v17 == 4 || (v18 = 0, v17 == 5) )
      v18 = 1;
    if ( v18 != 0 )
    {
      idAnimWebBlendTree::EnumerateTree_r(
        this,
        node: *(idMD6Node **)&i->durationMS,
        (idStaticList<idMD6Node const *,32> *)list);
      i = (const idVoiceEvent *)i->startMS;
    }
    else
    {
      if ( v17 != 6 )
        return;
      v19 = *(_DWORD *)&i->durationMS;
      if ( v19 == 0 )
        return;
      startMS = i->startMS;
      if ( *(_DWORD *)(((4 * (((__PAIR64__(v19 >> 31, HIWORD(i[7].startMS)) - v19) >> 32) & HIWORD(i[7].startMS)))
                      & 0x3FFFC)
                     + startMS) == 0 )
        return;
      i = *(const idVoiceEvent **)(((4
                                   * (((__PAIR64__(v19 >> 31, HIWORD(i[7].startMS)) - v19) >> 32) & HIWORD(i[7].startMS)))
                                  & 0x3FFFC)
                                 + startMS);
    }
  }
}


// ========================================================================
// ?Free@idAnimWebBlendTree@@QAAXXZ
// EA  : 0x826F7728
// RVA : 0x006F7728
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void __fastcall idAnimWebBlendTree::Free(idAnimWebBlendTree *this)
{
  int v2; // r7
  int v3; // r6
  idMD6Node *tree; // r4
  int v5; // r29
  int v6; // r30
  int v7; // [sp+8h] [-108h]
  int v8; // [sp+Ch] [-104h]
  int v9; // [sp+10h] [-100h]
  int v10; // [sp+14h] [-FCh]
  int v11; // [sp+18h] [-F8h]
  const idVoiceEvent *v12; // [sp+1Ch] [-F4h]
  idList<idVoiceEvent const *,5> v13; // [sp+50h] [-C0h] BYREF
  _BYTE v14[176]; // [sp+60h] [-B0h] BYREF

  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->leaves);
  tree = this->tree;
  if ( this->tree != nullptr )
  {
    v13.granularity = 1;
    v13.num = 0;
    v13.size = 32;
    v13.list = (const idVoiceEvent **)v14;
    v13.memTag = 5;
    v13.listStatic = 1;
    idAnimWebBlendTree::EnumerateTree_r(
      this,
      node: (const idVoiceEvent *)tree,
      list: &v13,
      a4: v3,
      a5: v2,
      a6: 5,
      a7: (int)v14,
      a8: 32,
      a9: v7,
      a10: v8,
      a11: v9,
      a12: v10,
      a13: v11,
      a14: v12);
    v5 = 0;
    if ( v13.num > 0 )
    {
      v6 = 0;
      do
      {
        this->web->md6Allocator->Free(this: this->web->md6Allocator, a2: (idMD6Node *)v13.list[v6]);
        ++v5;
        v13.list[v6++] = nullptr;
      }
      while ( v5 < v13.num );
    }
    this->tree = nullptr;
    if ( (v13.listStatic == 0 || v13.listStatic == 2) && v13.list != nullptr )
      idMem::Free(this: &mem, ptr: v13.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$249496
// EA  : 0x826F7814
// RVA : 0x006F7814
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249496()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 80));
}


// ========================================================================
// ??1idAnimWebBlendTree@@QAA@XZ
// EA  : 0x826F7848
// RVA : 0x006F7848
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void __fastcall idAnimWebBlendTree::~idAnimWebBlendTree(idAnimWebBlendTree *this)
{
  idAnimWebBlendTree::Free(this);
  this->web = nullptr;
  this->tree = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->leaves);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalarPairs);
}


// ========================================================================
// __unwind$249603
// EA  : 0x826F78A0
// RVA : 0x006F78A0
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249603()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// __unwind$249604
// EA  : 0x826F78CC
// RVA : 0x006F78CC
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249604()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 28));
}


// ========================================================================
// ?Init@idAnimWebBlendTree@@QAA_NPAVidAnimator_AnimWeb@@PBVidDeclAnimWebNode@@V?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@PBDABVidModelInfo@3@H@Z
// EA  : 0x826F7900
// RVA : 0x006F7900
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

int __fastcall idAnimWebBlendTree::Init(
        idAnimWebBlendTree *this,
        idAnimator_AnimWeb *web,
        const idDeclAnimWebNode *node,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex,
        const char *blendEq,
        const idDeclAnimWebNode::idModelInfo *modelInfo,
        int ticksPerSec)
{
  idDeclAnimWebNode *v9; // r19
  __int16 v10; // r28
  const char *v11; // r24
  const idDeclAnimWebNode::idModelInfo *v12; // r27
  unsigned __int64 v13; // r6
  const char *v14; // r7
  int v15; // r21
  idMD6Allocator *md6Allocator; // r26
  const idDeclMD6 **list; // r6
  int v18; // r25
  unsigned __int64 v19; // r6
  const char *v20; // r7
  int num; // r4
  idList<idMD6AnimProps,32> *p_animProps; // r22
  int v23; // r10
  int v24; // r28
  idPLog::logEntry_t *v25; // r29
  __int64 v26; // r3
  idMD6LeafPlay *v27; // r24
  idPLog::logEntry_t *v28; // r29
  int v29; // r3
  int parent; // r11
  __int64 v31; // r9
  int v32; // r26
  idPLog::logEntry_t *v33; // r29
  __int64 v34; // r3
  int v35; // r11
  idAnimWebBlendEquation::existingNode_t *v36; // r27
  int v37; // r28
  idPLog::logEntry_t *v38; // r29
  __int64 v39; // r3
  idPLog::logEntry_t *v40; // r29
  int v41; // r3
  int v42; // r11
  __int64 v43; // r9
  idPLog::logEntry_t *v44; // r29
  int v45; // r3
  int v46; // r11
  __int64 v47; // r9
  const idDeclMD6 *v48; // r26
  idMD6AnimProps *v49; // r11
  int value; // r9
  int v51; // r29
  idPLog::logEntry_t *v52; // r28
  __int64 v53; // r3
  const idMD6Anim *v54; // r28
  idPLog::logEntry_t *v55; // r29
  int v56; // r3
  int v57; // r11
  __int64 v58; // r9
  const idMD6Anim *defaultAnim; // r10
  const idMD6Skel *skeleton; // r11
  const char *v61; // r29
  idMD6Leaf::wrapMode_t v62; // r8
  int v63; // r27
  idPLog::logEntry_t *v64; // r26
  __int64 v65; // r3
  int v66; // r29
  idPLog::logEntry_t *v67; // r28
  __int64 v68; // r3
  idPLog::logEntry_t *v69; // r29
  int v70; // r3
  int v71; // r11
  __int64 v72; // r9
  idPLog::logEntry_t *v73; // r29
  int v74; // r3
  int v75; // r11
  __int64 v76; // r9
  int v77; // r10
  idPLog *v78; // r29
  idPLog::logEntry_t *v79; // r30
  int v80; // r3
  __int64 v81; // r11
  __int64 v82; // r9
  const idMD6Model *model; // r30
  idPLog *v84; // r29
  idPLog::logEntry_t *v85; // r30
  int v86; // r3
  __int64 v87; // r11
  __int64 v88; // r9
  idPLog *pLog; // r29
  idPLog::logEntry_t *v91; // r30
  int v92; // r3
  __int64 totalTicks; // r11
  __int64 v94; // r9
  idPLog *v95; // r29
  idPLog::logEntry_t *v96; // r30
  int v97; // r3
  __int64 v98; // r11
  __int64 v99; // r9
  idPLog *v100; // r29
  idPLog::logEntry_t *v101; // r30
  int v102; // r3
  __int64 v103; // r11
  __int64 v104; // r9
  idList<idAnimWebBlendEquation::existingNode_t,5> *v105; // [sp+8h] [-618h]
  idMD6Node **v106; // [sp+Ch] [-614h]
  idList<idAnimWebScalarPair,33> *v107; // [sp+10h] [-610h]
  int v108; // [sp+14h] [-60Ch]
  int v109; // [sp+18h] [-608h]
  int v110; // [sp+1Ch] [-604h]
  int v111; // [sp+20h] [-600h]
  int v112; // [sp+24h] [-5FCh]
  int v113; // [sp+28h] [-5F8h]
  int v114; // [sp+2Ch] [-5F4h]
  int v115; // [sp+30h] [-5F0h]
  int v116; // [sp+34h] [-5ECh]
  int v117; // [sp+38h] [-5E8h]
  int v118; // [sp+3Ch] [-5E4h]
  int v119; // [sp+40h] [-5E0h]
  int v120; // [sp+44h] [-5DCh]
  int v121; // [sp+48h] [-5D8h]
  int v122; // [sp+4Ch] [-5D4h]
  int v123; // [sp+50h] [-5D0h]
  int v124; // [sp+58h] [-5C8h]
  int v125; // [sp+60h] [-5C0h]
  __int16 v126; // [sp+70h] [-5B0h] BYREF
  int v127; // [sp+74h] [-5ACh]
  idPLogScope v128; // [sp+78h] [-5A8h] BYREF
  idMD6Allocator *v129; // [sp+80h] [-5A0h]
  const idDeclMD6 *v130; // [sp+84h] [-59Ch]
  idPLogScope v131; // [sp+88h] [-598h] BYREF
  int v132; // [sp+90h] [-590h]
  idPLog *v133; // [sp+94h] [-58Ch]
  const char *v134; // [sp+98h] [-588h]
  int v135; // [sp+A0h] [-580h]
  idPLog *v136; // [sp+A4h] [-57Ch]
  encounterGroupRole_t v137[4]; // [sp+A8h] [-578h] BYREF
  int v138; // [sp+B8h] [-568h]
  int v139; // [sp+C0h] [-560h]
  idPLog *v140; // [sp+C4h] [-55Ch]
  const char *v141; // [sp+C8h] [-558h]
  int v142; // [sp+D0h] [-550h]
  idPLog *v143; // [sp+D4h] [-54Ch]
  int v144; // [sp+D8h] [-548h]
  idPLog *v145; // [sp+DCh] [-544h]
  idMD6AnimProps *v146; // [sp+E0h] [-540h]
  int v147; // [sp+E4h] [-53Ch]
  idList<enum encounterGroupRole_t,5> *p_leaves; // [sp+E8h] [-538h]
  const char *v149; // [sp+ECh] [-534h]
  idStr v150; // [sp+F0h] [-530h] BYREF
  idStr v151; // [sp+110h] [-510h] BYREF
  idStr v152; // [sp+130h] [-4F0h] BYREF
  idAnimWebBlendEquation v153; // [sp+150h] [-4D0h] BYREF
  idList<idAnimWebBlendEquation::existingNode_t,5> v154; // [sp+270h] [-3B0h] BYREF
  int v155; // [sp+280h] [-3A0h] BYREF
  __int16 v157; // [sp+64Eh] [+2Eh]

  v157 = (__int16)modelIndex;
  v9 = node;
  v10 = (__int16)modelIndex;
  v11 = blendEq;
  v12 = modelInfo;
  RD_EventBegin(name: "idAnimWebBlendTree::Init");
  LODWORD(v13) = "idAnimWebBlendTree::Init";
  HIDWORD(v13) = 2;
  idPLogScope::idPLogScope(this: &v128, pl: &::pLog, gMask: v13, label: v14);
  idAnimWebBlendTree::Free(this);
  this->web = web;
  v15 = 0;
  *(_QWORD *)&v154.num = 64;
  v154.list = (idAnimWebBlendEquation::existingNode_t *)&v155;
  *(_DWORD *)&v154.granularity = 66817;
  md6Allocator = web->md6Allocator;
  v129 = md6Allocator;
  list = web->modelDecls.list;
  v18 = 4 * v10;
  v138 = v18;
  v130 = *(const idDeclMD6 **)((char *)list + v18);
  RD_EventBegin(name: "idAnimWebBlendTree::Init - alloc leaves");
  LODWORD(v19) = "idAnimWebBlendTree::Init - alloc leaves";
  HIDWORD(v19) = 2;
  idPLogScope::idPLogScope(this: &v131, pl: &::pLog, gMask: v19, label: v20);
  num = v12->animProps.num;
  p_animProps = &v12->animProps;
  p_leaves = (idList<enum encounterGroupRole_t,5> *)&this->leaves;
  if ( num > this->leaves.size )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->leaves, newsize: num);
  v23 = v12->animProps.num;
  v127 = 0;
  if ( v23 > 0 )
  {
    v145 = &::pLog;
    v136 = &::pLog;
    v133 = &::pLog;
    v137[3] = (encounterGroupRole_t)&::pLog;
    v147 = -2091122688;
    v149 = "idAnimWebBlendTree::Init - leaf->Init";
    v134 = "idAnimWebBlendTree::Init - invalid or missing animation specified in blend equation '%s' in animWeb '%s', node '%s'";
    v141 = "anim%d";
    while ( 1 )
    {
      RD_EventBegin(name: "idAnimWebBlendTree::Init - allocator->Alloc");
      v24 = -1;
      v144 = -1;
      if ( (::pLog.groupMask & 2) != 0 )
      {
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
          this: &::pLog.logEntries,
          newSize: ::pLog.logEntries.num + 1);
        if ( ::pLog.logEntries.num >= ::pLog.logEntries.size )
          v25 = &::pLog.logEntries.list[::pLog.logEntries.size - 1];
        else
          v25 = &::pLog.logEntries.list[::pLog.logEntries.num++];
        idMem::PopHeap(this: &mem);
        v25->label = "idAnimWebBlendTree::Init - allocator->Alloc";
        v25->parent = ::pLog.lastEntry;
        v24 = ::pLog.logEntries.num - 1;
        ::pLog.lastEntry = ::pLog.logEntries.num - 1;
        v144 = ::pLog.logEntries.num - 1;
        LODWORD(v26) = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v25->totalTicks = v26;
      }
      v27 = (idMD6LeafPlay *)md6Allocator->Alloc(this: md6Allocator, a2: NODE_LEAF_PLAY);
      v137[0] = (encounterGroupRole_t)v27;
      if ( v24 >= 0 )
      {
        v28 = &::pLog.logEntries.list[v24];
        v29 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        parent = v28->parent;
        LODWORD(v31) = v29 - LODWORD(v28->totalTicks);
        v144 = -1;
        v28->totalTicks = v31;
        ::pLog.lastEntry = parent;
      }
      RD_EventEnd();
      if ( (node->customFlags & 0x100) != 0 )
      {
        v27->syncEnabled = 1;
        v27->syncGroup = 1;
      }
      RD_EventBegin(name: "idAnimWebBlendTree::Init - existingNodes->Alloc()");
      v32 = -1;
      v135 = -1;
      if ( (::pLog.groupMask & 2) != 0 )
      {
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
          this: &::pLog.logEntries,
          newSize: ::pLog.logEntries.num + 1);
        if ( ::pLog.logEntries.num >= ::pLog.logEntries.size )
          v33 = &::pLog.logEntries.list[::pLog.logEntries.size - 1];
        else
          v33 = &::pLog.logEntries.list[::pLog.logEntries.num++];
        idMem::PopHeap(this: &mem);
        v33->label = "idAnimWebBlendTree::Init - existingNodes->Alloc()";
        v33->parent = ::pLog.lastEntry;
        v32 = ::pLog.logEntries.num - 1;
        ::pLog.lastEntry = ::pLog.logEntries.num - 1;
        v135 = ::pLog.logEntries.num - 1;
        LODWORD(v34) = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v33->totalTicks = v34;
      }
      idList<idParallelJobList_Threads::job_t,96>::PreAllocateWithGranularity(
        this: (idList<presentableObject_t,5> *)&v154,
        newSize: v154.num + 1);
      v35 = v154.num;
      if ( v154.num >= v154.size )
      {
        v36 = &v154.list[v154.size - 1];
      }
      else
      {
        ++v154.num;
        v36 = &v154.list[v35];
      }
      v36->node = v27;
      RD_EventBegin(name: "idAnimWebBlendTree::Init - va");
      v37 = -1;
      v132 = -1;
      if ( (::pLog.groupMask & 2) != 0 )
      {
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
          this: &::pLog.logEntries,
          newSize: ::pLog.logEntries.num + 1);
        if ( ::pLog.logEntries.num >= ::pLog.logEntries.size )
          v38 = &::pLog.logEntries.list[::pLog.logEntries.size - 1];
        else
          v38 = &::pLog.logEntries.list[::pLog.logEntries.num++];
        idMem::PopHeap(this: &mem);
        v38->label = "idAnimWebBlendTree::Init - va";
        v38->parent = ::pLog.lastEntry;
        v37 = ::pLog.logEntries.num - 1;
        ::pLog.lastEntry = ::pLog.logEntries.num - 1;
        v132 = ::pLog.logEntries.num - 1;
        LODWORD(v39) = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v38->totalTicks = v39;
      }
      idStr::snPrintf(dest: v36->name, size: 8, fmt: v141, v127);
      if ( v37 >= 0 )
      {
        v40 = &::pLog.logEntries.list[v37];
        v41 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v42 = v40->parent;
        LODWORD(v43) = v41 - LODWORD(v40->totalTicks);
        v132 = -1;
        v40->totalTicks = v43;
        ::pLog.lastEntry = v42;
      }
      RD_EventEnd();
      if ( v32 >= 0 )
      {
        v44 = &::pLog.logEntries.list[v32];
        v45 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v46 = v44->parent;
        LODWORD(v47) = v45 - LODWORD(v44->totalTicks);
        v135 = -1;
        v44->totalTicks = v47;
        ::pLog.lastEntry = v46;
      }
      RD_EventEnd();
      v48 = v130;
      v49 = &p_animProps->list[v15];
      v146 = v49;
      value = v49->aliasHandle.value;
      if ( value != 0xFFFF )
      {
        v146 = v49;
        v126 = value;
        (*(void (__fastcall **)(_DWORD, const idDeclMD6 *, __int16 *))(**(_DWORD **)(v147 - 1896) + 128))(
          a1: *(_DWORD *)(v147 - 1896),
          a2: v130,
          a3: &v126);
      }
      RD_EventBegin(name: "idAnimWebBlendTree::Init - FindMD6Anim");
      v51 = -1;
      v137[2] = -1;
      if ( (::pLog.groupMask & 2) != 0 )
      {
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
          this: &::pLog.logEntries,
          newSize: ::pLog.logEntries.num + 1);
        if ( ::pLog.logEntries.num >= ::pLog.logEntries.size )
          v52 = &::pLog.logEntries.list[::pLog.logEntries.size - 1];
        else
          v52 = &::pLog.logEntries.list[::pLog.logEntries.num++];
        idMem::PopHeap(this: &mem);
        v52->label = "idAnimWebBlendTree::Init - FindMD6Anim";
        v52->parent = ::pLog.lastEntry;
        v51 = ::pLog.logEntries.num - 1;
        ::pLog.lastEntry = ::pLog.logEntries.num - 1;
        v137[2] = ::pLog.logEntries.num - 1;
        LODWORD(v53) = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v52->totalTicks = v53;
      }
      v54 = idMD6AnimProps::SelectAnim(this: &p_animProps->list[v15], declMD6: v48, index: 0);
      if ( v51 >= 0 )
      {
        v55 = &::pLog.logEntries.list[v51];
        v56 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v57 = v55->parent;
        LODWORD(v58) = v56 - LODWORD(v55->totalTicks);
        v137[2] = -1;
        v55->totalTicks = v58;
        ::pLog.lastEntry = v57;
      }
      RD_EventEnd();
      if ( v54 == nullptr )
      {
        defaultAnim = nullptr;
        skeleton = v48->model->skeleton;
        if ( skeleton != nullptr )
          defaultAnim = skeleton->defaultAnim;
        v54 = defaultAnim;
        if ( p_animProps->list[v15].aliasHandle.value == 0xFFFF )
        {
          v150.len = 0;
          v150.baseBuffer[0] = 0;
          v150.data = v150.baseBuffer;
          v150.allocedAndFlag = 20;
          idDeclAnimWebNode::GetName(this: node, web: web->decl, name: &v150);
          idLib::Warning(fmt: v134, blendEq, web->decl->name.str, v150.data);
          idStr::FreeData(this: &v150);
        }
        if ( v54 == nullptr )
          break;
      }
      v61 = v149;
      RD_EventBegin(name: v149);
      v63 = -1;
      v143 = &::pLog;
      v142 = -1;
      if ( (::pLog.groupMask & 2) != 0 )
      {
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        v64 = idList<idPLog::logEntry_t,44>::Alloc(this: &::pLog.logEntries);
        idMem::PopHeap(this: &mem);
        v64->label = v61;
        v64->parent = ::pLog.lastEntry;
        v63 = ::pLog.logEntries.num - 1;
        ::pLog.lastEntry = ::pLog.logEntries.num - 1;
        v142 = ::pLog.logEntries.num - 1;
        LODWORD(v65) = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v64->totalTicks = v65;
      }
      idMD6LeafPlay::Init(
        this: v27,
        anim: v54,
        gameTime: 0,
        ticksPerSec: 0,
        frame: 0,
        rateScale: p_animProps->list[v15].rate,
        wrapMode: v62,
        weightGroup: (const md6WeightGroup_t)p_animProps->list[v15].wrap);
      RD_EventBegin(name: "idAnimWebBlendTree::Init - leaves.Append");
      v66 = -1;
      v140 = &::pLog;
      v139 = -1;
      if ( (::pLog.groupMask & 2) != 0 )
      {
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        v67 = idList<idPLog::logEntry_t,44>::Alloc(this: &::pLog.logEntries);
        idMem::PopHeap(this: &mem);
        v67->label = "idAnimWebBlendTree::Init - leaves.Append";
        v67->parent = ::pLog.lastEntry;
        v66 = ::pLog.logEntries.num - 1;
        ::pLog.lastEntry = ::pLog.logEntries.num - 1;
        v139 = ::pLog.logEntries.num - 1;
        LODWORD(v68) = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v67->totalTicks = v68;
      }
      idList<idAnimWebBlendTree *,5>::Append(this: p_leaves, obj: v137);
      if ( v66 >= 0 )
      {
        v69 = &::pLog.logEntries.list[v66];
        v70 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v71 = v69->parent;
        LODWORD(v72) = v70 - LODWORD(v69->totalTicks);
        v139 = -1;
        v69->totalTicks = v72;
        ::pLog.lastEntry = v71;
      }
      RD_EventEnd();
      if ( v63 >= 0 )
      {
        v73 = &::pLog.logEntries.list[v63];
        v74 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v75 = v73->parent;
        LODWORD(v76) = v74 - LODWORD(v73->totalTicks);
        v142 = -1;
        v73->totalTicks = v76;
        ::pLog.lastEntry = v75;
      }
      RD_EventEnd();
      ++v15;
      v77 = p_animProps->num;
      md6Allocator = v129;
      if ( ++v127 >= v77 )
      {
        v11 = blendEq;
        v10 = v157;
        v12 = modelInfo;
        v18 = v138;
        v9 = node;
        goto LABEL_56;
      }
    }
    v152.len = 0;
    v152.baseBuffer[0] = 0;
    v152.data = v152.baseBuffer;
    v152.allocedAndFlag = 20;
    idDeclAnimWebNode::GetName(this: node, web: web->decl, name: &v152);
    idLib::Warning(
      fmt: "idAnimWebBlendTree::Init - failed to load default anim in blend equation '%s' for md6def '%s' in animWeb '%s', node '%s'",
      blendEq,
      v48->name.str,
      web->decl->name.str,
      v152.data);
    idStr::FreeData(this: &v152);
    if ( v131.logIndex >= 0 )
    {
      pLog = v131.pLog;
      v91 = &v131.pLog->logEntries.list[v131.logIndex];
      v92 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v91->totalTicks;
      HIDWORD(totalTicks) = v91->parent;
      LODWORD(v94) = v92 - totalTicks;
      v91->totalTicks = v94;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
    if ( v154.listStatic == 0 || v154.listStatic == 2 )
    {
      if ( v154.list != nullptr )
        idMem::Free(this: &mem, ptr: v154.list, align: ALIGN_16);
      v154.list = nullptr;
      v154.size = 0;
    }
    v154.num = 0;
    if ( v128.logIndex >= 0 )
    {
      v95 = v128.pLog;
      v96 = &v128.pLog->logEntries.list[v128.logIndex];
      v97 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v98 = v96->totalTicks;
      HIDWORD(v98) = v96->parent;
      LODWORD(v99) = v97 - v98;
      v96->totalTicks = v99;
      v95->lastEntry = HIDWORD(v98);
    }
    goto LABEL_71;
  }
LABEL_56:
  if ( v131.logIndex >= 0 )
  {
    v78 = v131.pLog;
    v79 = &v131.pLog->logEntries.list[v131.logIndex];
    v80 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v81 = v79->totalTicks;
    HIDWORD(v81) = v79->parent;
    LODWORD(v82) = v80 - v81;
    v79->totalTicks = v82;
    v78->lastEntry = HIDWORD(v81);
  }
  RD_EventEnd();
  this->modelIndex = v10;
  model = (*(const idDeclMD6 **)((char *)web->decl->models.list + v18))->model;
  this->tree = nullptr;
  idAnimWebBlendEquation::idAnimWebBlendEquation(this: &v153);
  if ( (unsigned __int8)idAnimWebBlendEquation::Parse(
                          this: &v153,
                          modelInfo: v12,
                          model,
                          allocator: md6Allocator,
                          time: 0,
                          ticksPerSec_: ticksPerSec,
                          equation: v11,
                          scalars: (idList<idAnimWebScalar,5> *)&web->scalars,
                          existingNodes: v105,
                          root: v106,
                          scalarPairs: v107,
                          a12: v108,
                          a13: v109,
                          a14: v110,
                          a15: v111,
                          a16: v112,
                          a17: v113,
                          a18: v114,
                          a19: v115,
                          a20: v116,
                          a21: v117,
                          a22: v118,
                          a23: v119,
                          a24: v120,
                          a25: v121,
                          a26: v122,
                          a27: v123,
                          a28: &v154,
                          a29: v124,
                          a30: &this->tree,
                          a31: v125,
                          a32: (idList<idAnimWebScalarPair,5> *)&this->scalarPairs) == 0 )
  {
    idAnimWebBlendTree::Free(this);
    v151.len = 0;
    v151.data = v151.baseBuffer;
    v151.allocedAndFlag = 20;
    v151.baseBuffer[0] = 0;
    idDeclAnimWebNode::GetName(this: v9, web: web->decl, name: &v151);
    idLib::Warning(
      fmt: "idAnimWebBlendTree::Init - failed parsing blend equation '%s' in animWeb '%s', node '%s'",
      v11,
      web->decl->name.str,
      v151.data);
    idStr::FreeData(this: &v151);
    if ( v153.allocatedNodes.listStatic == 0 || v153.allocatedNodes.listStatic == 2 )
    {
      if ( v153.allocatedNodes.list != nullptr )
        idMem::Free(this: &mem, ptr: v153.allocatedNodes.list, align: ALIGN_16);
      v153.allocatedNodes.list = nullptr;
      v153.allocatedNodes.size = 0;
    }
    v153.allocatedNodes.num = 0;
    if ( v154.listStatic == 0 || v154.listStatic == 2 )
    {
      if ( v154.list != nullptr )
        idMem::Free(this: &mem, ptr: v154.list, align: ALIGN_16);
      v154.list = nullptr;
      v154.size = 0;
    }
    v154.num = 0;
    if ( v128.logIndex >= 0 )
    {
      v84 = v128.pLog;
      v85 = &v128.pLog->logEntries.list[v128.logIndex];
      v86 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v87 = v85->totalTicks;
      HIDWORD(v87) = v85->parent;
      LODWORD(v88) = v86 - v87;
      v85->totalTicks = v88;
      v84->lastEntry = HIDWORD(v87);
    }
LABEL_71:
    RD_EventEnd();
    return 0;
  }
  this->nodeIndex.value = v9->nodeIndex.value;
  if ( v153.allocatedNodes.listStatic == 0 || v153.allocatedNodes.listStatic == 2 )
  {
    if ( v153.allocatedNodes.list != nullptr )
      idMem::Free(this: &mem, ptr: v153.allocatedNodes.list, align: ALIGN_16);
    v153.allocatedNodes.list = nullptr;
    v153.allocatedNodes.size = 0;
  }
  v153.allocatedNodes.num = 0;
  if ( v154.listStatic == 0 || v154.listStatic == 2 )
  {
    if ( v154.list != nullptr )
      idMem::Free(this: &mem, ptr: v154.list, align: ALIGN_16);
    v154.list = nullptr;
    v154.size = 0;
  }
  v154.num = 0;
  if ( v128.logIndex >= 0 )
  {
    v100 = v128.pLog;
    v101 = &v128.pLog->logEntries.list[v128.logIndex];
    v102 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v103 = v101->totalTicks;
    HIDWORD(v103) = v101->parent;
    LODWORD(v104) = v102 - v103;
    v101->totalTicks = v104;
    v100->lastEntry = HIDWORD(v103);
  }
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$249639
// EA  : 0x826F8474
// RVA : 0x006F8474
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249639()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1568 + 1408));
}


// ========================================================================
// __unwind$249640
// EA  : 0x826F849C
// RVA : 0x006F849C
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249640()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1568 + 120));
}


// ========================================================================
// __unwind$249641
// EA  : 0x826F84C4
// RVA : 0x006F84C4
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249641()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1568 + 624));
}


// ========================================================================
// __unwind$249642
// EA  : 0x826F84EC
// RVA : 0x006F84EC
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249642()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1568 + 1409));
}


// ========================================================================
// __unwind$249643
// EA  : 0x826F8514
// RVA : 0x006F8514
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249643()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1568 + 136));
}


// ========================================================================
// __unwind$249644
// EA  : 0x826F853C
// RVA : 0x006F853C
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249644()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1568 + 1410));
}


// ========================================================================
// __unwind$249645
// EA  : 0x826F8564
// RVA : 0x006F8564
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249645()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1568 + 216));
}


// ========================================================================
// __unwind$249646
// EA  : 0x826F858C
// RVA : 0x006F858C
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249646()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1568 + 1411));
}


// ========================================================================
// __unwind$249647
// EA  : 0x826F85B4
// RVA : 0x006F85B4
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249647()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1568 + 160));
}


// ========================================================================
// __unwind$249648
// EA  : 0x826F85DC
// RVA : 0x006F85DC
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249648()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1568 + 1412));
}


// ========================================================================
// __unwind$249649
// EA  : 0x826F8604
// RVA : 0x006F8604
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249649()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1568 + 144));
}


// ========================================================================
// __unwind$249650
// EA  : 0x826F862C
// RVA : 0x006F862C
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249650()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1568 + 1413));
}


// ========================================================================
// __unwind$249651
// EA  : 0x826F8654
// RVA : 0x006F8654
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249651()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1568 + 176));
}


// ========================================================================
// __unwind$249652
// EA  : 0x826F867C
// RVA : 0x006F867C
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249652()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1568 + 240));
}


// ========================================================================
// __unwind$249653
// EA  : 0x826F86A4
// RVA : 0x006F86A4
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249653()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1568 + 1414));
}


// ========================================================================
// __unwind$249654
// EA  : 0x826F86CC
// RVA : 0x006F86CC
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249654()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1568 + 208));
}


// ========================================================================
// __unwind$249655
// EA  : 0x826F86F4
// RVA : 0x006F86F4
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249655()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1568 + 1415));
}


// ========================================================================
// __unwind$249656
// EA  : 0x826F871C
// RVA : 0x006F871C
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249656()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1568 + 192));
}


// ========================================================================
// __unwind$249658
// EA  : 0x826F8744
// RVA : 0x006F8744
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249658()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(v0 - 1568 + 336));
}


// ========================================================================
// __unwind$249659
// EA  : 0x826F876C
// RVA : 0x006F876C
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249659()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1568 + 272));
}


// ========================================================================
// __unwind$249657
// EA  : 0x826F8794
// RVA : 0x006F8794
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.cpp
// ========================================================================

void _unwind_249657()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1568 + 304));
}

