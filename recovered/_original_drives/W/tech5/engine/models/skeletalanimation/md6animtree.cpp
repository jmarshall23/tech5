
// ========================================================================
// ?Init@idMD6TagFilter@@QAAXEIEPBVidDeclAnimWebTagGroup@@@Z
// EA  : 0x8283D258
// RVA : 0x0083D258
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6TagFilter::Init(
        idMD6TagFilter *this,
        unsigned __int8 inputTagBias,
        unsigned int inputTagMask,
        unsigned __int8 inputTagGroupIndex,
        const idDeclAnimWebTagGroup *inputTagGroup)
{
  this->tagGroup = inputTagGroup;
  this->tagMask = inputTagMask;
  this->tagGroupIndex = inputTagGroupIndex;
  this->tagBias = inputTagBias;
}


// ========================================================================
// ?Clear@idMD6LeafPause@@QAAXXZ
// EA  : 0x8283D270
// RVA : 0x0083D270
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPause::Clear(idMD6LeafPause *this)
{
  this->anim = nullptr;
  this->weightGroup = 8;
  this->wrapMode = 2;
  this->frame = 0.0;
  this->flags = 0;
}


// ========================================================================
// ?Init@idMD6LeafPause@@QAAXPBVidMD6Anim@@MW4wrapMode_t@idMD6Leaf@@W4md6WeightGroup_t@@@Z
// EA  : 0x8283D2A0
// RVA : 0x0083D2A0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPause::Init(
        idMD6LeafPause *this,
        const idMD6Anim *anim,
        double frame,
        const idMD6Leaf::wrapMode_t wrapMode,
        const md6WeightGroup_t weightGroup,
        unsigned __int8 a6)
{
  this->frame = frame;
  this->anim = anim;
  this->flags = 0;
  this->weightGroup = a6;
  this->wrapMode = weightGroup;
}


// ========================================================================
// ?SetUseStackTop@idMD6LeafPause@@QAAX_N@Z
// EA  : 0x8283D2C0
// RVA : 0x0083D2C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPause::SetUseStackTop(idMD6LeafPause *this, const bool set)
{
  if ( set )
    this->flags |= 1u;
  else
    this->flags &= ~1u;
}


// ========================================================================
// ?SetClearNonModWeights@idMD6LeafPause@@QAAX_N@Z
// EA  : 0x8283D2F0
// RVA : 0x0083D2F0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPause::SetClearNonModWeights(idMD6LeafPause *this, const bool set)
{
  if ( set )
    this->flags |= 2u;
  else
    this->flags &= ~2u;
}


// ========================================================================
// ?SetOverrideFrameBounds@idMD6LeafPause@@QAAX_N@Z
// EA  : 0x8283D320
// RVA : 0x0083D320
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPause::SetOverrideFrameBounds(idMD6LeafPause *this, const bool set)
{
  if ( set )
    this->flags |= 0x10u;
  else
    this->flags &= ~0x10u;
}


// ========================================================================
// ?Clear@idMD6LeafPlay@@QAAXXZ
// EA  : 0x8283D350
// RVA : 0x0083D350
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPlay::Clear(idMD6LeafPlay *this)
{
  this->anim = nullptr;
  this->weightGroup = 8;
  this->wrapMode = 2;
  this->rateScale = 1.0;
  this->startTime = 0;
  this->initCounter = 0;
}


// ========================================================================
// ?SetFrameTime@idMD6LeafPlay@@QAAXHH@Z
// EA  : 0x8283D380
// RVA : 0x0083D380
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPlay::SetFrameTime(
        idMD6LeafPlay *this,
        unsigned int gameTime,
        unsigned int targetTime,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  LODWORD(a7) = targetTime;
  this->startTime = (int)(float)((float)__SPAIR64__(targetTime, gameTime) - (float)((float)a7 / this->rateScale));
}


// ========================================================================
// ?IsBlendFinished@idMD6Branch@@QBA_NXZ
// EA  : 0x8283D3C8
// RVA : 0x0083D3C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

int __fastcall idMD6Branch::IsBlendFinished(idMD6Branch *this)
{
  unsigned __int8 v1; // r11

  if ( this->alphaRate == 0.0 )
    return 1;
  v1 = 0;
  if ( this->currentAlpha == this->targetAlpha )
    return 1;
  return v1;
}


// ========================================================================
// ?IsChildBlendedOut@idMD6Branch@@QBA_NPBVidMD6Node@@@Z
// EA  : 0x8283D400
// RVA : 0x0083D400
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

int __fastcall idMD6Branch::IsChildBlendedOut(idMD6Branch *this, const idMD6Node *child)
{
  double targetAlpha; // fp0
  unsigned __int8 v4; // r11

  if ( child == nullptr )
    return 1;
  targetAlpha = this->targetAlpha;
  if ( targetAlpha > 0.0 && targetAlpha < 1.0 || this->filterGroup != 0 )
    return 0;
  if ( this->left == child )
    return this->currentAlpha >= 1.0;
  if ( this->right != child )
    return 0;
  v4 = 1;
  if ( this->currentAlpha <= 0.0 )
    return v4;
  return 0;
}


// ========================================================================
// ?IsBlendingOut@idMD6Branch@@QBA_NXZ
// EA  : 0x8283D498
// RVA : 0x0083D498
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

int __fastcall idMD6Branch::IsBlendingOut(idMD6Branch *this)
{
  unsigned __int8 v1; // r11

  if ( this->currentAlpha <= 0.0 )
    return 0;
  if ( this->targetAlpha != 0.0 )
    return 0;
  v1 = 1;
  if ( this->alphaRate == 0.0 )
    return 0;
  return v1;
}


// ========================================================================
// ?IsBlendingIn@idMD6Branch@@QBA_NXZ
// EA  : 0x8283D4D8
// RVA : 0x0083D4D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

int __fastcall idMD6Branch::IsBlendingIn(idMD6Branch *this)
{
  unsigned __int8 v1; // r11

  if ( this->currentAlpha >= 1.0 )
    return 0;
  if ( this->targetAlpha < 1.0 )
    return 0;
  v1 = 1;
  if ( this->alphaRate == 0.0 )
    return 0;
  return v1;
}


// ========================================================================
// ?Init@idMD6Branch@@QAAXPAVidMD6Node@@0W4blendOp_t@idMD6Blend@@W4originBlend_t@4@MMMW4md6WeightGroup_t@@W4blendType_t@1@@Z
// EA  : 0x8283D520
// RVA : 0x0083D520
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6Branch::Init(
        idMD6Branch *this,
        idMD6Node *left,
        idMD6Node *right,
        const idMD6Blend::blendOp_t op,
        const idMD6Blend::originBlend_t originBlend,
        double startAlpha,
        double targetAlpha,
        double alphaRate,
        const md6WeightGroup_t filterGroup,
        const idMD6Branch::blendType_t blendType,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        unsigned __int8 a31,
        int a32,
        idMD6Branch::blendType_t a33)
{
  this->currentAlpha = startAlpha;
  this->targetAlpha = targetAlpha;
  this->alphaRate = alphaRate;
  this->op = op;
  this->originBlend = originBlend;
  this->filterGroup = a31;
  this->left = left;
  this->right = right;
  this->blendType = a33;
}


// ========================================================================
// ?UpdateCurrentAlpha@idMD6Branch@@QAAXHHH@Z
// EA  : 0x8283D558
// RVA : 0x0083D558
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6Branch::UpdateCurrentAlpha(
        idMD6Branch *this,
        const int timeMSec,
        const int lastTimeMSec,
        unsigned int ticksPerSec,
        int a5,
        __int64 a6)
{
  unsigned int v6; // r11
  double targetAlpha; // fp0
  double v8; // fp11

  v6 = timeMSec - lastTimeMSec;
  if ( timeMSec - lastTimeMSec > 0 )
  {
    LODWORD(a6) = timeMSec - lastTimeMSec;
    targetAlpha = this->targetAlpha;
    v8 = (float)(this->targetAlpha - this->currentAlpha);
    if ( v8 <= 0.0 )
    {
      if ( v8 >= 0.0 )
        return;
      if ( (float)-(float)((float)(this->alphaRate * (float)((float)a6 / (float)__SPAIR64__(v6, ticksPerSec)))
                         - this->currentAlpha) >= (double)(float)(this->targetAlpha + (float)0.000001) )
        targetAlpha = (float)-(float)((float)(this->alphaRate * (float)((float)a6 / (float)__SPAIR64__(v6, ticksPerSec)))
                                    - this->currentAlpha);
    }
    else if ( (float)((float)(this->alphaRate * (float)((float)a6 / (float)__SPAIR64__(v6, ticksPerSec)))
                    + this->currentAlpha) <= (double)(float)(this->targetAlpha - (float)0.000001) )
    {
      this->currentAlpha = (float)(this->alphaRate * (float)((float)a6 / (float)__SPAIR64__(v6, ticksPerSec)))
                         + this->currentAlpha;
      return;
    }
    this->currentAlpha = targetAlpha;
  }
}


// ========================================================================
// ??0idMD6TagFilter@@QAA@XZ
// EA  : 0x8283D658
// RVA : 0x0083D658
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

idMD6TagFilter *__fastcall idMD6TagFilter::idMD6TagFilter(idMD6TagFilter *this)
{
  this->tagGroup = nullptr;
  this->type = 7;
  this->tagMask = 0;
  this->tagGroupIndex = 0;
  this->tagBias = 0;
  return this;
}


// ========================================================================
// ?Filter@idMD6TagFilter@@IBA_NIABV?$idList@PAVidMD6Node@@$04@@ABV?$idList@I$04@@ABUidMD6DebugFilterLogicHelper_t@@AAV?$idArray@_N$0BAA@@@@Z
// EA  : 0x8283D678
// RVA : 0x0083D678
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

int __fastcall idMD6TagFilter::Filter(
        idMD6TagFilter *this,
        const unsigned int desiredTag,
        const idList<idMD6Node *,5> *leafList,
        const idList<unsigned int,5> *tagList,
        const idMD6DebugFilterLogicHelper_t *debugFilterLogicHelper,
        idArray<bool,256> *skipList)
{
  unsigned int tagMask; // r10
  int result; // r3
  unsigned int v9; // r7
  int v10; // r9
  bool v11; // r31
  int v12; // r10
  int num; // ctr
  unsigned int v14; // r11
  bool v15; // r11

  tagMask = this->tagMask;
  result = 0;
  v9 = desiredTag & tagMask;
  v10 = 0;
  v11 = (_cntlzw(desiredTag & tagMask) & 0x20) != 0;
  if ( tagList->num > 0 )
  {
    v12 = 0;
    num = tagList->num;
    do
    {
      if ( !skipList->ptr[v10] )
      {
        v14 = tagList->list[v12];
        if ( v11 )
          v15 = (v14 & this->tagMask) != 0;
        else
          v15 = (_cntlzw(v14 & v9) & 0x20) != 0;
        if ( v15 )
          skipList->ptr[v10] = true;
        else
          result = 1;
      }
      ++v10;
      ++v12;
      --num;
    }
    while ( num != 0 );
  }
  return result;
}


// ========================================================================
// ??0idMD6Leaf@@QAA@W4nodeType_t@idMD6Node@@@Z
// EA  : 0x8283D728
// RVA : 0x0083D728
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

idMD6Leaf *__fastcall idMD6Leaf::idMD6Leaf(idMD6Leaf *this, const idMD6Node::nodeType_t type_)
{
  this->type = type_;
  this->anim = nullptr;
  this->weightGroup = 8;
  this->wrapMode = 2;
  this->initCounter = 0;
  return this;
}


// ========================================================================
// ?GetFrameRate@idMD6Leaf@@QBAHXZ
// EA  : 0x8283D750
// RVA : 0x0083D750
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

int __fastcall idMD6Leaf::GetFrameRate(idMD6Leaf *this)
{
  const idMD6Anim *anim; // r11
  int result; // r3
  idMD6AnimData *animData; // r11

  anim = this->anim;
  result = 30;
  if ( anim != nullptr )
  {
    animData = anim->animData;
    if ( animData != nullptr )
      return animData->frameRate;
  }
  return result;
}


// ========================================================================
// ?SetFloatFrame@idMD6LeafPlay@@QAAXHHM@Z
// EA  : 0x8283D778
// RVA : 0x0083D778
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMD6LeafPlay::SetFloatFrame(
        idMD6LeafPlay *this,
        const int gameTime,
        const int ticksPerSec,
        double targetFrame)
{
  __int64 v4; // r11 OVERLAPPED
  const idMD6Anim *anim; // r11
  idMD6AnimData *animData; // r11

  anim = this->anim;
  if ( anim != nullptr && (animData = anim->animData) != nullptr )
    LODWORD(v4) = animData->frameRate;
  else
    LODWORD(v4) = 30;
  HIDWORD(v4) = ticksPerSec;
  this->startTime = gameTime
                  - (int)(float)((float)((float)((float)*(__int64 *)((char *)&v4 + 4) * (float)targetFrame) / (float)v4)
                               / this->rateScale);
}


// ========================================================================
// ?SetFrame@idMD6LeafPlay@@QAAXHHG@Z
// EA  : 0x8283D7F0
// RVA : 0x0083D7F0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPlay::SetFrame(
        idMD6LeafPlay *this,
        const int gameTime,
        const int ticksPerSec,
        const unsigned __int16 targetFrame)
{
  const idMD6Anim *anim; // r11
  signed int frameRate; // r11
  idMD6AnimData *animData; // r11
  double rateScale; // fp0
  __int64 v8; // r9
  __int64 v9; // r6

  anim = this->anim;
  if ( anim != nullptr && (animData = anim->animData) != nullptr )
    frameRate = animData->frameRate;
  else
    frameRate = 30;
  rateScale = this->rateScale;
  LODWORD(v8) = gameTime;
  HIDWORD(v8) = targetFrame * ticksPerSec;
  LODWORD(v9) = SHIDWORD(v8) / frameRate;
  HIDWORD(v9) = __ROL4__(HIDWORD(v8), 1) - 1;
  __twllei(frameRate, 0);
  __twlgei(frameRate & ~HIDWORD(v9), 0xFFFFFFFF);
  this->startTime = (int)(float)((float)v8 - (float)((float)v9 / (float)rateScale));
}


// ========================================================================
// ?GetFrameTime@idMD6LeafPlay@@QBAHH@Z
// EA  : 0x8283D878
// RVA : 0x0083D878
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

int __fastcall idMD6LeafPlay::GetFrameTime(
        idMD6LeafPlay *this,
        int gameTime,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  int startTime; // r11

  startTime = this->startTime;
  if ( gameTime < startTime )
    return 0;
  LODWORD(a7) = gameTime - startTime;
  return (int)(float)((float)a7 * this->rateScale);
}


// ========================================================================
// ?GetFrameTicks@idMD6LeafPlay@@QBA?AV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@H@Z
// EA  : 0x8283D8C0
// RVA : 0x0083D8C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

idMD6LeafPlay *__fastcall idMD6LeafPlay::GetFrameTicks(
        idMD6LeafPlay *this,
        idTypesafeNumber<int,enum gameTimeUnique_t> *result,
        const int gameTime,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  int value; // r11

  value = result[3].value;
  if ( gameTime >= value )
  {
    LODWORD(a7) = gameTime - value;
    *(_DWORD *)&this->type = (int)(float)((float)a7 * *(float *)&result[4].value);
  }
  else
  {
    *(_DWORD *)&this->type = 0;
  }
  return this;
}


// ========================================================================
// ?SetRateScale@idMD6LeafPlay@@QAAXHM@Z
// EA  : 0x8283D910
// RVA : 0x0083D910
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMD6LeafPlay::SetRateScale(
        idMD6LeafPlay *this,
        const int gameTime,
        double rs,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  int startTime; // r11

  if ( this->rateScale != rs )
  {
    startTime = this->startTime;
    if ( gameTime >= startTime )
    {
      LODWORD(a8) = gameTime - startTime;
      LODWORD(a8) = (int)(float)((float)a8 * this->rateScale);
    }
    else
    {
      LODWORD(a8) = 0;
    }
    if ( rs >= 0.0 )
      this->rateScale = rs;
    else
      this->rateScale = 1.0;
    this->startTime = (int)(float)((float)*(__int64 *)((char *)&a8 - 4) - (float)((float)a8 / this->rateScale));
  }
}


// ========================================================================
// ?GetAnimLength@idMD6LeafPlay@@QBAHH_N@Z
// EA  : 0x8283D9D8
// RVA : 0x0083D9D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

int __fastcall idMD6LeafPlay::GetAnimLength(idMD6LeafPlay *this, const int ticksPerSec, const bool applyRateScale)
{
  const idMD6Anim *anim; // r11
  idMD6AnimData *animData; // r10
  idMD6AnimData *v6; // r11
  signed int frameRate; // r11
  int v8; // r7

  anim = this->anim;
  if ( anim == nullptr )
    return 0;
  animData = anim->animData;
  if ( animData != nullptr )
    animData = (idMD6AnimData *)animData->numFrames;
  v6 = anim->animData;
  if ( v6 != nullptr )
    frameRate = v6->frameRate;
  else
    frameRate = 30;
  v8 = ((_DWORD)animData - 1) * ticksPerSec;
  __twllei(frameRate, 0);
  __twlgei(frameRate & ~(__ROL4__(v8, 1) - 1), 0xFFFFFFFF);
  if ( applyRateScale )
    return (int)(float)((float)((float)1.0 / this->rateScale) * (float)__SPAIR64__(0x82000000, v8 / frameRate));
  else
    return v8 / frameRate;
}


// ========================================================================
// ?GetAnimTicks@idMD6LeafPlay@@QBA?AV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@H@Z
// EA  : 0x8283DA80
// RVA : 0x0083DA80
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

idMD6LeafPlay *__fastcall idMD6LeafPlay::GetAnimTicks(idMD6LeafPlay *this, idMD6LeafPlay *result, int ticksPerSec)
{
  *(_DWORD *)&this->type = idMD6LeafPlay::GetAnimLength(this: result, ticksPerSec, applyRateScale: true);
  return this;
}


// ========================================================================
// ?GetPointSide@idMD6BlendBranch@@IBA?AW4pointSide_t@idGeometry@@ABV?$idArray@M$05@@00@Z
// EA  : 0x8283DE68
// RVA : 0x0083DE68
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

idGeometry::pointSide_t __fastcall idMD6BlendBranch::GetPointSide(
        idMD6BlendBranch *this,
        const idArray<float,6> *p0,
        const idArray<float,6> *point,
        const idArray<float,6> *normal)
{
  int v4; // r11
  const unsigned int *v5; // r11
  double v6; // fp0
  idGeometry::pointSide_t result; // r3

  v4 = __ROL4__(this->numDimensions, 2);
  v5 = &idMD6BlendBranch::crossIndexTable[*(const unsigned int *)((char *)idMD6BlendBranch::crossIndexTableBase + v4)
                                        - 4
                                        + v4];
  v6 = (float)((float)((float)(point->ptr[v5[1]] - p0->ptr[v5[1]]) * normal->ptr[*v5])
             - (float)((float)(point->ptr[v5[3]] - p0->ptr[v5[3]]) * normal->ptr[v5[2]]));
  if ( v6 == 0.0 )
    return POINTSIDE_ON;
  result = POINTSIDE_LEFT;
  if ( v6 <= 0.0 )
    return POINTSIDE_RIGHT;
  return result;
}


// ========================================================================
// ?Solve_Gaussian@idMD6BlendBranch@@IBAXAAV?$idArray@M$05@@AAV?$idArray@M$0CE@@@0@Z
// EA  : 0x8283E0D0
// RVA : 0x0083E0D0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6BlendBranch::Solve_Gaussian(
        idMD6BlendBranch *this,
        idArray<float,6> *v,
        idArray<float,36> *m,
        idArray<float,6> *out)
{
  unsigned int numDimensions; // r11
  unsigned int v5; // r23
  unsigned int v6; // r28
  int *v7; // r24
  int v8; // r30
  unsigned int v9; // r25
  unsigned int v10; // r7
  unsigned int v11; // r8
  double v12; // fp11
  double v13; // fp0
  _DWORD *v14; // r10
  unsigned int v15; // r9
  double v16; // fp12
  unsigned int v17; // r9
  double v18; // fp12
  unsigned int v19; // r9
  double v20; // fp12
  unsigned int v21; // r9
  double v22; // fp12
  _DWORD *v23; // r9
  unsigned int v24; // ctr
  unsigned int v25; // r10
  double v26; // fp12
  double v27; // fp12
  int v28; // r26
  unsigned int v29; // r29
  int v30; // r27
  int *v31; // r7
  int v32; // r31
  bool v33; // cr56
  unsigned int v34; // r10
  int v35; // r11
  unsigned int v36; // r30
  double v37; // fp13
  float *v38; // r9
  float *v39; // r11
  double v40; // fp8
  int v41; // r29
  signed int v42; // r7
  float *v43; // r31
  int v44; // r28
  signed int v45; // r11
  int v46; // r8
  int v47; // r30
  int v48; // r6
  float *v49; // r10
  float *v50; // r11
  double v51; // fp0
  _DWORD v52[28]; // [sp+0h] [-70h] BYREF

  numDimensions = this->numDimensions;
  v52[2] = 2;
  v52[3] = 3;
  v5 = numDimensions - 1;
  v52[4] = 4;
  v6 = 0;
  v52[5] = 5;
  if ( numDimensions != 1 )
  {
    v7 = v52;
    do
    {
      v8 = *v7;
      v9 = v6 + 1;
      v10 = v6;
      v11 = v6 + 1;
      v12 = m->ptr[numDimensions * *v7 + v6];
      v13 = __fabs(v12);
      if ( v6 + 1 < numDimensions )
      {
        if ( (int)(numDimensions - v9) >= 4 )
        {
          v14 = v7 + 2;
          do
          {
            v15 = numDimensions * *(v14 - 1) + v6;
            v16 = __fabs(m->ptr[v15]);
            if ( v16 > v13 )
            {
              v12 = m->ptr[v15];
              v10 = v11;
              v13 = v16;
            }
            v17 = numDimensions * *v14 + v6;
            v18 = __fabs(m->ptr[v17]);
            if ( v18 > v13 )
            {
              v12 = m->ptr[v17];
              v10 = v11 + 1;
              v13 = v18;
            }
            v19 = numDimensions * v14[1] + v6;
            v20 = __fabs(m->ptr[v19]);
            if ( v20 > v13 )
            {
              v12 = m->ptr[v19];
              v10 = v11 + 2;
              v13 = v20;
            }
            v21 = numDimensions * v14[2] + v6;
            v22 = __fabs(m->ptr[v21]);
            if ( v22 > v13 )
            {
              v12 = m->ptr[v21];
              v10 = v11 + 3;
              v13 = v22;
            }
            v11 += 4;
            v14 += 4;
          }
          while ( v11 < numDimensions - 3 );
        }
        if ( v11 < numDimensions )
        {
          v23 = &v52[v11];
          v24 = numDimensions - v11;
          do
          {
            v25 = numDimensions * *v23 + v6;
            v26 = __fabs(m->ptr[v25]);
            if ( v26 > v13 )
            {
              v12 = m->ptr[v25];
              v10 = v11;
              v13 = v26;
            }
            ++v11;
            ++v23;
            --v24;
          }
          while ( v24 != 0 );
        }
        if ( v6 != v10 )
        {
          *v7 = v52[v10];
          v52[v10] = v8;
          v8 = *v7;
        }
      }
      if ( v13 >= idMath::FLT_SMALLEST_NON_DENORMAL )
        v27 = (float)((float)1.0 / (float)v12);
      else
        v27 = 0.0;
      v28 = numDimensions * v8;
      v29 = v6 + 1;
      if ( v9 < numDimensions )
      {
        v30 = v8;
        v31 = v7 + 1;
        do
        {
          v32 = *v31;
          v33 = v9 < numDimensions;
          v34 = v6 + 1;
          v35 = numDimensions * *v31;
          v36 = v35 + v6;
          v37 = (float)(m->ptr[v36] * (float)v27);
          if ( v33 )
          {
            v39 = &m->ptr[v9 - 1 + v35];
            v38 = &m->ptr[v9 - 1 + v28];
            do
            {
              ++v34;
              v40 = (float)-(float)((float)(*++v38 * (float)v37) - v39[1]);
              *++v39 = v40;
            }
            while ( v34 < this->numDimensions );
          }
          ++v29;
          ++v31;
          v->ptr[v32] = -(float)((float)(v->ptr[v30] * (float)v37) - v->ptr[v32]);
          m->ptr[v36] = 0.0;
          numDimensions = this->numDimensions;
        }
        while ( v29 < numDimensions );
      }
      ++v6;
      ++v7;
    }
    while ( v9 < v5 );
  }
  v41 = numDimensions - 1;
  if ( (int)(numDimensions - 1) >= 0 )
  {
    v42 = numDimensions;
    v43 = &out->ptr[v41];
    v44 = (char *)v52 - (char *)out;
    do
    {
      v45 = this->numDimensions;
      v46 = v42;
      v47 = *(_DWORD *)((char *)v43 + v44);
      v48 = v45 * v47;
      if ( v42 < v45 )
      {
        v49 = v43;
        v50 = &m->ptr[v42 - 1 + v48];
        do
        {
          ++v50;
          ++v46;
          v->ptr[v47] = -(float)((float)(*v50 * *++v49) - v->ptr[v47]);
        }
        while ( v46 < this->numDimensions );
      }
      if ( __fabs(m->ptr[v48 + v41]) >= idMath::FLT_SMALLEST_NON_DENORMAL )
        v51 = (float)(v->ptr[v47] / m->ptr[v48 + v41]);
      else
        v51 = 0.0;
      *v43 = v51;
      --v41;
      --v42;
      --v43;
    }
    while ( v41 >= 0 );
  }
}


// ========================================================================
// ?UpdateMasterNodeAndTotalScaledDuration@idMD6FusionBranch@@IBAXPAVidMD6Node@@MHAAPAV2@AAM2@Z
// EA  : 0x8283E440
// RVA : 0x0083E440
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6FusionBranch::UpdateMasterNodeAndTotalScaledDuration(
        idMD6FusionBranch *this,
        idMD6Node *node,
        double alpha,
        const int ticksPerSec,
        idMD6Node **masterNode,
        float *masterNodeWeight,
        float *totalScaledDuration,
        float *a8)
{
  __int64 v8; // r11
  int v9; // r5
  int v10; // r11
  signed int v11; // r10
  int v12; // r5

  HIDWORD(v8) = node->type;
  LODWORD(v8) = 0;
  if ( HIDWORD(v8) == 2 )
  {
    v9 = 0;
    v10 = *(_DWORD *)(*(_DWORD *)&node[4].type + 40);
    if ( v10 != 0 )
    {
      v9 = *(unsigned __int16 *)(v10 + 8);
      v11 = *(unsigned __int16 *)(v10 + 10);
    }
    else
    {
      v11 = 30;
    }
    __twllei(v11, 0);
    v12 = (v9 - 1) * (_DWORD)masterNode;
    LODWORD(v8) = v12 / v11;
    HIDWORD(v8) = v11 & ~(__ROL4__(v12, 1) - 1);
    __twlgei(HIDWORD(v8), 0xFFFFFFFF);
  }
  *a8 = (float)((float)v8 * (float)alpha) + *a8;
  if ( alpha > *totalScaledDuration )
  {
    *totalScaledDuration = alpha;
    *(_DWORD *)masterNodeWeight = node;
  }
}


// ========================================================================
// ?IsValid@idMD6Node@@QBA_NXZ
// EA  : 0x8283E748
// RVA : 0x0083E748
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

unsigned int __fastcall idMD6Node::IsValid(idMD6Node *this)
{
  int type; // r11
  char v2; // r10
  char v4; // r11
  bool v5; // zf
  unsigned __int8 v6; // r11

  if ( this == nullptr )
    return 0;
  type = this->type;
  if ( type == 1 || (v2 = 0, type == 2) )
    v2 = 1;
  if ( v2 != 0 )
    return *((unsigned __int8 *)this + 8) - 8 - (*((unsigned __int8 *)this + 8) - 9 + (*((_BYTE *)this + 8) == 8));
  if ( type == 6 )
    return (-*((_DWORD *)this + 2) & (unsigned int)~*((_DWORD *)this + 2)) >> 31;
  if ( this->type == 0 || type == 3 || type == 4 || (v5 = type != 5, v4 = 0, !v5) )
    v4 = 1;
  if ( v4 == 0 )
    return 0;
  if ( *((_DWORD *)this + 2) == 0 )
    return 0;
  v6 = 1;
  if ( *((_DWORD *)this + 1) == 0 )
    return 0;
  return v6;
}


// ========================================================================
// ?Update@idMD6TagFilter@@QBAXIIABV?$idList@PAVidMD6Node@@$04@@ABV?$idList@I$04@@ABUidMD6DebugFilterLogicHelper_t@@AAV?$idArray@_N$0BAA@@@@Z
// EA  : 0x8283E810
// RVA : 0x0083E810
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6TagFilter::Update(
        idMD6TagFilter *this,
        unsigned int desiredTag,
        unsigned int defaultTag,
        const idList<idMD6Node *,5> *leafList,
        const idList<unsigned int,5> *tagList,
        const idMD6DebugFilterLogicHelper_t *debugFilterLogicHelper,
        idArray<bool,256> *skipList)
{
  char v13; // r3
  idArray<bool,256> v14; // [sp+50h] [-140h]

  v14 = *skipList;
  v13 = idMD6TagFilter::Filter(this, desiredTag, leafList, tagList, debugFilterLogicHelper, skipList);
  if ( v13 == 0 )
  {
    *skipList = v14;
    v13 = idMD6TagFilter::Filter(this, desiredTag: defaultTag, leafList, tagList, debugFilterLogicHelper, skipList);
  }
  if ( v13 == 0 )
    *skipList = v14;
}


// ========================================================================
// ?GetLength@idMD6Leaf@@QBAHH@Z
// EA  : 0x8283E8C0
// RVA : 0x0083E8C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idMD6Leaf::GetLength(idMD6Leaf *this, const int ticksPerSec, int a3, __int64 a4)
{
  const idMD6Anim *anim; // r10
  idMD6AnimData *animData; // r11
  int numFrames; // r9
  idMD6AnimData *v8; // r11
  int frameRate; // r11
  __int64 v10; // r9
  __int64 v11; // fp13

  anim = this->anim;
  if ( anim == nullptr )
    return 0;
  animData = anim->animData;
  numFrames = 0;
  if ( animData != nullptr )
    numFrames = animData->numFrames;
  v8 = anim->animData;
  if ( v8 != nullptr )
    frameRate = v8->frameRate;
  else
    frameRate = 30;
  HIDWORD(v10) = numFrames - 1;
  LODWORD(v10) = frameRate;
  v11 = *(__int64 *)((char *)&a4 - 4);
  LODWORD(a4) = ticksPerSec;
  return (int)(float)((float)((float)v11 * (float)a4) / (float)v10);
}


// ========================================================================
// ?Restart@idMD6LeafPlay@@QAAXHHHW4wrapMode_t@idMD6Leaf@@@Z
// EA  : 0x8283E958
// RVA : 0x0083E958
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPlay::Restart(
        idMD6LeafPlay *this,
        int gameTime,
        int ticksPerSec,
        unsigned __int16 inFrame,
        const idMD6Leaf::wrapMode_t inWrapMode)
{
  unsigned __int8 initCounter; // r11

  initCounter = this->initCounter;
  this->wrapMode = inWrapMode;
  this->initCounter = initCounter + 1;
  idMD6LeafPlay::SetFrame(this, gameTime, ticksPerSec, targetFrame: inFrame);
}


// ========================================================================
// ?Init@idMD6LeafPlay@@QAAXPBVidMD6Anim@@HHHMW4wrapMode_t@idMD6Leaf@@W4md6WeightGroup_t@@@Z
// EA  : 0x8283E970
// RVA : 0x0083E970
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPlay::Init(
        idMD6LeafPlay *this,
        const idMD6Anim *anim,
        int gameTime,
        int ticksPerSec,
        unsigned __int16 frame,
        double rateScale,
        const idMD6Leaf::wrapMode_t wrapMode,
        const md6WeightGroup_t weightGroup,
        unsigned __int8 a9)
{
  this->anim = anim;
  this->rateScale = rateScale;
  this->initCounter = 1;
  this->weightGroup = a9;
  this->wrapMode = weightGroup;
  this->startTime = 0;
  idMD6LeafPlay::SetFrame(this, gameTime, ticksPerSec, targetFrame: frame);
}


// ========================================================================
// ?GetLoopCount@idMD6LeafPlay@@QBAHHH@Z
// EA  : 0x8283E9A8
// RVA : 0x0083E9A8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

unsigned int __fastcall idMD6LeafPlay::GetLoopCount(idMD6LeafPlay *this, const int gameTime, signed int ticksPerSec)
{
  __int64 v3; // r10
  int startTime; // r11
  int v6; // r11
  int v7; // r11
  int v8; // r8
  int v9; // r11
  unsigned int v10; // r11

  HIDWORD(v3) = this->anim;
  if ( HIDWORD(v3) == 0 || this->wrapMode == 0 )
    return 0;
  startTime = this->startTime;
  if ( gameTime >= startTime )
  {
    LODWORD(v3) = gameTime - startTime;
    LODWORD(v3) = (int)(float)((float)v3 * this->rateScale);
  }
  else
  {
    LODWORD(v3) = 0;
  }
  v6 = *(_DWORD *)(HIDWORD(v3) + 40);
  if ( v6 != 0 )
    v7 = *(unsigned __int16 *)(v6 + 10);
  else
    v7 = 30;
  v8 = v3 * v7;
  LODWORD(v3) = __ROL4__(v3 * v7, 1);
  v9 = *(_DWORD *)(HIDWORD(v3) + 40);
  HIDWORD(v3) = v8 / ticksPerSec;
  __twllei(ticksPerSec, 0);
  __twlgei(ticksPerSec & ~(v3 - 1), 0xFFFFFFFF);
  if ( v9 != 0 )
  {
    v10 = *(unsigned __int16 *)(v9 + 8) - 1;
    __twllei(v10, 0);
    return HIDWORD(v3) / v10;
  }
  else
  {
    __twllei(0xFFFFFFFF, 0);
    return HIDWORD(v3) / 0xFFFFFFFF;
  }
}


// ========================================================================
// ?GetFloatFrame@idMD6LeafPlay@@QBAMHH@Z
// EA  : 0x8283EA70
// RVA : 0x0083EA70
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

float __fastcall idMD6LeafPlay::GetFloatFrame(
        idMD6LeafPlay *this,
        const int gameTime,
        unsigned int ticksPerSec,
        double a4,
        double a5,
        long double a6,
        int a7,
        __int64 a8,
        __int64 a9)
{
  int startTime; // r11
  int v11; // r11
  int v12; // r11
  long double v13; // fp2
  __int64 v14; // r11
  long double v16; // fp2

  LODWORD(a8) = this->anim;
  if ( (_DWORD)a8 != 0 )
  {
    startTime = this->startTime;
    if ( gameTime >= startTime )
    {
      LODWORD(a9) = gameTime - startTime;
      HIDWORD(a9) = (int)(float)((float)a9 * this->rateScale);
    }
    else
    {
      HIDWORD(a9) = 0;
    }
    v11 = *(_DWORD *)(a8 + 40);
    LODWORD(a9) = 30;
    if ( v11 != 0 )
      LODWORD(a9) = *(unsigned __int16 *)(v11 + 10);
    v12 = *(_DWORD *)(a8 + 40);
    LODWORD(a8) = ticksPerSec;
    *(double *)&v13 = (float)((float)__SPAIR64__(ticksPerSec, HIDWORD(a9) * (int)a9) / (float)a8);
    if ( v12 != 0 )
      LODWORD(v14) = *(unsigned __int16 *)(v12 + 8);
    else
      LODWORD(v14) = 0;
    HIDWORD(v14) = this->wrapMode;
    *((double *)&v13 + 1) = (float)v14;
    if ( this->wrapMode != 0 )
    {
      v16 = fmod(dX: v13, dY: a6);
      _FP1 = (float)*(double *)&v16;
    }
    else
    {
      _FP13 = (float)((float)*(double *)&v13 - (float)((float)*((double *)&v13 + 1) - (float)1.0));
      __asm { fsel      f1, f13, f0, f1 }
    }
  }
  else
  {
    _FP1 = 0.0;
  }
  return *((float *)&_FP1 + 1);
}


// ========================================================================
// ?GetFrame@idMD6LeafPlay@@QBAGHH@Z
// EA  : 0x8283EB98
// RVA : 0x0083EB98
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

int __fastcall idMD6LeafPlay::GetFrame(
        idMD6LeafPlay *this,
        const int gameTime,
        signed int ticksPerSec,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  const idMD6Anim *anim; // r8
  int startTime; // r11
  idMD6AnimData *animData; // r11
  int frameRate; // r11
  int v12; // r10
  int wrapMode; // r7
  unsigned int v14; // r9
  idMD6AnimData *v15; // r11
  idMD6AnimData *v16; // r11
  int numFrames; // r10
  unsigned int v18; // r10
  idMD6AnimData *v19; // r11
  int v20; // r10

  anim = this->anim;
  if ( anim == nullptr )
    return 0;
  startTime = this->startTime;
  if ( gameTime >= startTime )
  {
    LODWORD(a7) = gameTime - startTime;
    LODWORD(a7) = (int)(float)((float)a7 * this->rateScale);
  }
  else
  {
    LODWORD(a7) = 0;
  }
  animData = anim->animData;
  if ( animData != nullptr )
    frameRate = animData->frameRate;
  else
    frameRate = 30;
  v12 = a7 * frameRate;
  wrapMode = this->wrapMode;
  v14 = v12 / ticksPerSec;
  v15 = anim->animData;
  __twllei(ticksPerSec, 0);
  __twlgei(ticksPerSec & ~(__ROL4__(v12, 1) - 1), 0xFFFFFFFF);
  if ( wrapMode != 0 )
  {
    numFrames = 0;
    if ( v15 != nullptr )
      numFrames = v15->numFrames;
    v18 = numFrames - 1;
    v19 = anim->animData;
    __twllei(v18, 0);
    v20 = v14 / v18;
    if ( v19 != nullptr )
      LOWORD(v19) = v19->numFrames;
    LOWORD(v14) = v14 - ((_WORD)v19 - 1) * v20;
  }
  else if ( v15 == nullptr || v14 >= v15->numFrames )
  {
    v16 = anim->animData;
    if ( v16 != nullptr )
      return (unsigned __int16)(v16->numFrames - 1);
    else
      return 0xFFFF;
  }
  return (unsigned __int16)v14;
}


// ========================================================================
// ?FindAnimation@idMD6BlendAdditiveBranch@@ABAXAAPAVidMD6Node@@AAM@Z
// EA  : 0x8283ED30
// RVA : 0x0083ED30
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6BlendAdditiveBranch::FindAnimation(
        idMD6BlendAdditiveBranch *this,
        idMD6Node **rightAnimation,
        float *alpha)
{
  float *list; // r31
  double currentCoordinate; // fp0
  int num; // r30
  unsigned int v6; // r10
  int v7; // r11
  int v8; // r9
  int v9; // r6
  int v10; // r7
  int v11; // r8
  int v12; // r8
  double v13; // fp11
  unsigned int v14; // r10
  float *v15; // r7
  double v16; // fp12
  int v17; // [sp+4h] [-1Ch]

  list = this->coordinateList.list;
  currentCoordinate = this->currentCoordinate;
  num = this->animationList.num;
  v6 = 0;
  v7 = 1;
  v8 = (int)__fabs((float)(*list - this->currentCoordinate));
  if ( num > 1 )
  {
    if ( num - 1 < 4 )
    {
LABEL_9:
      if ( v7 < num )
      {
        v12 = v7;
        do
        {
          v13 = __fabs((float)(list[v12] - this->currentCoordinate));
          if ( (int)v13 >= v8 )
            break;
          v6 = v7++;
          v8 = (int)v13;
          ++v12;
        }
        while ( v7 < num );
      }
    }
    else
    {
      v9 = 1;
      while ( 1 )
      {
        v10 = (int)__fabs((float)(list[v9] - this->currentCoordinate));
        if ( v10 >= v8 )
          break;
        v6 = v7;
        v11 = (int)__fabs((float)(list[v9 + 1] - this->currentCoordinate));
        if ( v11 >= v10 )
          break;
        v6 = v7 + 1;
        v17 = (int)__fabs((float)(list[v9 + 2] - this->currentCoordinate));
        if ( v17 >= v11 )
          break;
        v6 = v7 + 2;
        v8 = (int)__fabs((float)(list[v9 + 3] - this->currentCoordinate));
        if ( v8 >= v17 )
          break;
        v6 = v7 + 3;
        v7 += 4;
        v9 += 4;
        if ( v7 >= num - 3 )
          goto LABEL_9;
      }
    }
  }
  v14 = v6;
  *rightAnimation = this->animationList.list[v14];
  v15 = this->coordinateList.list;
  v16 = v15[v14];
  if ( v16 >= 0.0 )
  {
    if ( currentCoordinate >= 0.0 )
    {
      if ( currentCoordinate > v16 )
      {
LABEL_16:
        *alpha = v15[v14] / v15[v14];
        return;
      }
      goto LABEL_20;
    }
LABEL_19:
    currentCoordinate = 0.0;
    goto LABEL_20;
  }
  if ( currentCoordinate < v16 )
    goto LABEL_16;
  if ( currentCoordinate > 0.0 )
    goto LABEL_19;
LABEL_20:
  *alpha = (float)currentCoordinate / v15[v14];
}


// ========================================================================
// ??0idMD6BestLeaf@@QAA@XZ
// EA  : 0x8283F1C0
// RVA : 0x0083F1C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

idMD6BestLeaf *__fastcall idMD6BestLeaf::idMD6BestLeaf(idMD6BestLeaf *this)
{
  this->type = 6;
  this->leafList.list = nullptr;
  this->leafList.granularity = 0;
  this->leafList.memTag = 30;
  this->leafList.listStatic = 0;
  this->leafList.size = 0;
  this->leafList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->leafList);
  this->tagList.list = nullptr;
  this->tagList.granularity = 0;
  this->tagList.memTag = 30;
  this->tagList.listStatic = 0;
  this->tagList.size = 0;
  this->tagList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tagList);
  this->filterList.list = nullptr;
  this->filterList.granularity = 0;
  this->filterList.memTag = 30;
  this->filterList.listStatic = 0;
  this->filterList.size = 0;
  this->filterList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->filterList);
  this->tagGroupFilter.tagGroup = nullptr;
  this->tagGroupFilter.type = 7;
  this->tagGroupFilter.tagMask = 0;
  this->tagGroupFilter.tagGroupIndex = 0;
  this->tagGroupFilter.tagBias = 0;
  this->tagGroup = nullptr;
  this->desiredTag = 0;
  this->activeTag = 0;
  this->defaultTag = 0;
  this->bestLeafIndex = -1;
  this->tagBias = 0;
  this->tagGroupIndex = 0;
  return this;
}


// ========================================================================
// __unwind$226484
// EA  : 0x8283F294
// RVA : 0x0083F294
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_226484()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$226485
// EA  : 0x8283F2C0
// RVA : 0x0083F2C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_226485()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 20));
}


// ========================================================================
// ?Init@idMD6BestLeaf@@QAAXEIEABV?$idList@PAVidMD6Node@@$04@@ABV?$idList@I$04@@ABV?$idList@PAVidMD6Filter@@$04@@IPBVidDeclAnimWebTagGroup@@@Z
// EA  : 0x8283F2F0
// RVA : 0x0083F2F0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6BestLeaf::Init(
        idMD6BestLeaf *this,
        unsigned __int8 inputTagBias,
        unsigned int inputTagMask,
        unsigned __int8 inputTagGroupIndex,
        const idList<idMD6Node *,5> *leaves,
        const idList<idMD6Node *,5> *tags,
        const idList<idMD6Node *,5> *filters,
        unsigned int inputDefaultTag,
        const idDeclAnimWebTagGroup *inputTagGroup,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idDeclAnimWebTagGroup *a28)
{
  idList<idMaterial const *,59>::operator=(this: (idList<idMD6Node *,5> *)&this->leafList, other: leaves);
  idList<idMaterial const *,59>::operator=(this: (idList<idMD6Node *,5> *)&this->tagList, other: tags);
  idList<idMaterial const *,59>::operator=(this: (idList<idMD6Node *,5> *)&this->filterList, other: filters);
  this->defaultTag = inputDefaultTag;
  this->tagBias = inputTagBias;
  this->desiredTag = 0;
  this->activeTag = 0;
  this->tagGroup = a28;
  this->bestLeafIndex = -1;
  this->tagGroupIndex = inputTagGroupIndex;
  this->tagGroupFilter.tagGroup = a28;
  this->tagGroupFilter.tagMask = inputTagMask;
  this->tagGroupFilter.tagGroupIndex = inputTagGroupIndex;
  this->tagGroupFilter.tagBias = inputTagBias;
}


// ========================================================================
// ??1idMD6LeafPause@@QAA@XZ
// EA  : 0x8283F388
// RVA : 0x0083F388
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPause::~idMD6LeafPause(idMD6LeafPause *this)
{
  const idMD6Anim **p_anim; // r30
  int i; // r29
  const idMD6Anim *v4; // r4

  p_anim = &this->anim;
  for ( i = 2; i != 0; --i )
  {
    if ( *((_BYTE *)p_anim + 27) == 0 || *((_BYTE *)p_anim + 27) == 2 )
    {
      v4 = p_anim[3];
      if ( v4 != nullptr )
        idMem::Free(this: &mem, ptr: (void *)v4, align: ALIGN_16);
      p_anim[3] = nullptr;
      p_anim[5] = nullptr;
    }
    p_anim += 4;
    *p_anim = nullptr;
  }
  `eh vector destructor iterator'(
    ptr: this->animMods,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$226658
// EA  : 0x8283F418
// RVA : 0x0083F418
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_226658()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 16),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// ?IsPlaying@idMD6LeafPlay@@QBA_NHH@Z
// EA  : 0x8283F458
// RVA : 0x0083F458
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

BOOL __fastcall idMD6LeafPlay::IsPlaying(
        idMD6LeafPlay *this,
        int gameTime,
        int ticksPerSec,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  const idMD6Anim *anim; // r11
  idMD6AnimData *animData; // r11
  signed int frameRate; // r31
  int AnimLength; // r3
  int v13; // r4
  int v14; // r5
  BOOL result; // r3
  idMD6AnimData *v16; // r11
  int numFrames; // r31
  bool v18; // zf

  anim = this->anim;
  if ( anim == nullptr )
    return false;
  if ( this->wrapMode != 0 )
    return true;
  LODWORD(a7) = anim->animData;
  if ( (_DWORD)a7 != 0 )
  {
    LODWORD(a7) = *(unsigned __int16 *)(a7 + 6);
    HIDWORD(a7) = a7 & 0x1E;
    if ( (a7 & 0x1E) != 0 )
    {
      animData = anim->animData;
      frameRate = 30;
      if ( animData != nullptr )
        frameRate = animData->frameRate;
      AnimLength = idMD6LeafPlay::GetAnimLength(this, ticksPerSec, applyRateScale: true);
      v14 = gameTime - this->startTime;
      __twllei(frameRate, 0);
      __twlgei(frameRate & ~(__ROL4__(v13, 1) - 1), 0xFFFFFFFF);
      return v14 < AnimLength + v13 / frameRate;
    }
  }
  v16 = anim->animData;
  numFrames = 0;
  if ( v16 != nullptr )
    numFrames = v16->numFrames;
  v18 = (unsigned __int16)idMD6LeafPlay::GetFrame(this, gameTime, ticksPerSec, a4, a5, a6, a7) >= numFrames - 1;
  result = false;
  if ( !v18 )
    return true;
  return result;
}


// ========================================================================
// ?IsPlaying@idMD6LeafPlay@@QBA_NHH_N@Z
// EA  : 0x8283F540
// RVA : 0x0083F540
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

BOOL __fastcall idMD6LeafPlay::IsPlaying(
        idMD6LeafPlay *this,
        int gameTime,
        int ticksPerSec,
        const bool clampIgnoreExtraFrame,
        int a5,
        int a6,
        __int64 a7)
{
  const idMD6Anim *anim; // r11
  signed int v10; // r31
  int AnimLength; // r3
  int v12; // r4
  int v13; // r5
  BOOL result; // r3
  idMD6AnimData *animData; // r11
  int numFrames; // r31
  bool v17; // zf

  anim = this->anim;
  if ( anim == nullptr )
    return false;
  if ( this->wrapMode != 0 )
    return true;
  LODWORD(a7) = clampIgnoreExtraFrame;
  if ( !clampIgnoreExtraFrame )
  {
    LODWORD(a7) = anim->animData;
    HIDWORD(a7) = *(unsigned __int16 *)(a7 + 6);
    a6 = BYTE3(a7) & 0x1E;
    if ( (a7 & 0x1E00000000LL) != 0 )
    {
      v10 = 30;
      if ( (_DWORD)a7 != 0 )
        v10 = *(unsigned __int16 *)(a7 + 10);
      AnimLength = idMD6LeafPlay::GetAnimLength(this, ticksPerSec, applyRateScale: true);
      v13 = gameTime - this->startTime;
      __twllei(v10, 0);
      __twlgei(v10 & ~(__ROL4__(v12, 1) - 1), 0xFFFFFFFF);
      return v13 < AnimLength + v12 / v10;
    }
  }
  animData = anim->animData;
  numFrames = 0;
  if ( animData != nullptr )
    numFrames = animData->numFrames;
  v17 = (unsigned __int16)idMD6LeafPlay::GetFrame(this, gameTime, ticksPerSec, a4: clampIgnoreExtraFrame, a5, a6, a7) >= numFrames - 1;
  result = false;
  if ( !v17 )
    return true;
  return result;
}


// ========================================================================
// ?IsPlaying@idMD6LeafPlay@@QBA_NHHW4wrapMode_t@idMD6Leaf@@@Z
// EA  : 0x8283F630
// RVA : 0x0083F630
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

BOOL __fastcall idMD6LeafPlay::IsPlaying(
        idMD6LeafPlay *this,
        int gameTime,
        int ticksPerSec,
        const idMD6Leaf::wrapMode_t inWrapMode,
        int a5)
{
  const idMD6Anim *anim; // r11
  __int64 v8; // r10
  signed int v9; // r31
  int AnimLength; // r3
  int v11; // r4
  int v12; // r5
  BOOL result; // r3
  int v14; // r31
  bool v15; // zf

  anim = this->anim;
  if ( anim == nullptr )
    return false;
  if ( inWrapMode != WRAP_CLAMP )
    return true;
  LODWORD(v8) = anim->animData;
  HIDWORD(v8) = *(unsigned __int16 *)(v8 + 6);
  if ( (v8 & 0x1E00000000LL) != 0 )
  {
    v9 = 30;
    if ( (_DWORD)v8 != 0 )
      v9 = *(unsigned __int16 *)(v8 + 10);
    AnimLength = idMD6LeafPlay::GetAnimLength(this, ticksPerSec, applyRateScale: true);
    v12 = gameTime - this->startTime;
    __twllei(v9, 0);
    __twlgei(v9 & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF);
    return v12 < AnimLength + v11 / v9;
  }
  v14 = 0;
  if ( (_DWORD)v8 != 0 )
    v14 = *(unsigned __int16 *)(v8 + 8);
  v15 = (unsigned __int16)idMD6LeafPlay::GetFrame(this, gameTime, ticksPerSec, a4: 0, a5, a6: 0, a7: v8) >= v14 - 1;
  result = false;
  if ( !v15 )
    return true;
  return result;
}


// ========================================================================
// ?BuildPointList@idMD6BlendBranch@@IBA_NAAV?$idList@H$04@@AAV?$idArray@M$05@@_N@Z
// EA  : 0x8283F708
// RVA : 0x0083F708
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

BOOL __fastcall idMD6BlendBranch::BuildPointList(
        idMD6BlendBranch *this,
        idList<enum encounterGroupRole_t,5> *indices,
        idArray<float,6> *normal,
        char isFillerPoint)
{
  idList<enum encounterGroupRole_t,5> *v5; // r16
  int num; // r15
  int v9; // r17
  encounterGroupRole_t *list; // r10
  int v11; // r11
  int i; // ctr
  encounterGroupRole_t v13; // r8
  idGeometry::pointSide_t PointSide; // r20
  int numDimensions; // r8
  float *v16; // r10
  const idArray<float,6> *v17; // r31
  const idArray<float,6> *v18; // r5
  unsigned int v19; // r10
  float *v20; // r11
  char *v21; // r10
  _DWORD *v22; // r11
  int j; // ctr
  int v24; // r14
  int v25; // r18
  char v26; // r27
  int v27; // r28
  int v28; // r30
  double v29; // fp30
  _DWORD *v30; // r29
  unsigned int v31; // r3
  double v32; // fp0
  signed int v33; // r9
  double v34; // fp13
  int v35; // r31
  double v36; // fp12
  float *v37; // r8
  float *v38; // r7
  int v39; // r11
  int v40; // r10
  double v41; // fp9
  double v42; // fp6
  double v43; // fp10
  double v44; // fp0
  encounterGroupRole_t *v46; // r24
  int v47; // r23
  int v48; // r28
  float *v49; // r29
  const idArray<float,6> *v50; // r31
  int *v51; // r21
  int v52; // r10
  int v53; // r11
  const idArray<float,6> *v54; // r5
  const unsigned int *v55; // r11
  double v56; // fp0
  int v57; // r11
  char v58; // r11
  bool v59; // zf
  unsigned int v60; // r9
  float *v61; // r8
  float *v62; // r10
  float *v63; // r11
  double v64; // fp13
  double v65; // fp6
  double v66; // fp5
  double v67; // fp4
  float *v68; // r11
  unsigned int v69; // ctr
  idGeometry::pointSide_t v70; // r3
  char v71; // r4
  int v72; // r5
  int v73; // r6
  int v74; // r7
  int v75; // r8
  float *v76; // r10
  const unsigned int *v77; // r11
  double v78; // fp0
  int v79; // r11
  char v80; // r11
  char v81; // [sp+50h] [-500h] BYREF
  int v82; // [sp+54h] [-4FCh] BYREF
  int v83; // [sp+58h] [-4F8h] BYREF
  int v84; // [sp+5Ch] [-4F4h]
  idArray<float,6> v85; // [sp+60h] [-4F0h] BYREF
  char v86; // [sp+7Ch] [-4D4h] BYREF
  idArray<float,6> v87; // [sp+80h] [-4D0h] BYREF
  _DWORD v88[258]; // [sp+A0h] [-4B0h] BYREF

  v5 = indices;
  memset(Dst: v88, Val: 0, Size: 0x400u);
  num = this->animationList.num;
  v9 = v5->num;
  v83 = num;
  if ( v9 > 0 )
  {
    list = v5->list;
    v11 = 0;
    for ( i = v9; i != 0; --i )
    {
      v13 = list[v11++];
      v88[v13] = 1;
    }
  }
  PointSide = POINTSIDE_ON;
  if ( v9 >= 2 )
  {
    numDimensions = this->numDimensions;
    v16 = this->coordinateList.list;
    v17 = (const idArray<float,6> *)&v16[numDimensions * *v5->list];
    v18 = (const idArray<float,6> *)&v16[v5->list[v9 - 1] * numDimensions];
    if ( v9 == 2 )
    {
      v19 = 0;
      if ( this->numDimensions != 0 )
      {
        v20 = (float *)v17;
        do
        {
          ++v19;
          *(float *)((char *)v20 + (char *)normal - (char *)v17) = *(float *)((char *)v20 + (char *)v18 - (char *)v17)
                                                                 - *v20;
          ++v20;
        }
        while ( v19 < this->numDimensions );
      }
    }
    else
    {
      v21 = &v86;
      v22 = (_DWORD *)&normal[-1].ptr[5];
      for ( j = 6; j != 0; --j )
      {
        ++v22;
        v21 += 4;
        *(_DWORD *)v21 = *v22;
      }
      idMD6BlendBranch::UpdateNormal(this, p0: v17, p1: v18, inNormal: &v87, outNormal: normal);
    }
    PointSide = idMD6BlendBranch::GetPointSide(
                  this,
                  p0: v17,
                  point: (const idArray<float,6> *)this->currentCoordinate.list,
                  normal);
    if ( PointSide == POINTSIDE_ON )
      isFillerPoint = 1;
  }
  v24 = (unsigned __int8)isFillerPoint;
  v84 = (unsigned __int8)isFillerPoint;
  if ( isFillerPoint == 0 || (v25 = 2, PointSide != POINTSIDE_ON) )
    v25 = 1;
  v26 = 0;
  v81 = 0;
  if ( PointSide == POINTSIDE_ON && isFillerPoint == 0 )
  {
    v26 = 1;
    goto LABEL_21;
  }
  v46 = v5->list;
  v47 = 0;
  v48 = this->numDimensions;
  v49 = this->coordinateList.list;
  v82 = 0;
  v50 = (const idArray<float,6> *)&v49[v48 * *v46];
  if ( num > 0 )
  {
    v51 = v88;
LABEL_39:
    if ( *v51 != 0 )
      goto LABEL_87;
    v52 = this->numDimensions;
    v53 = __ROL4__(v52, 2);
    v54 = (const idArray<float,6> *)&v49[v52 * v47];
    v55 = &idMD6BlendBranch::crossIndexTable[*(const unsigned int *)((char *)idMD6BlendBranch::crossIndexTableBase + v53)
                                           - 4
                                           + v53];
    v56 = (float)((float)((float)(v54->ptr[v55[1]] - v50->ptr[v55[1]]) * normal->ptr[*v55])
                - (float)((float)(v54->ptr[v55[3]] - v50->ptr[v55[3]]) * normal->ptr[v55[2]]));
    if ( v56 == 0.0 )
    {
      v57 = 0;
    }
    else
    {
      v57 = 1;
      if ( v56 <= 0.0 )
        v57 = 2;
    }
    if ( v24 != 0 )
    {
      if ( v57 == 0 || PointSide != POINTSIDE_ON && v57 != PointSide )
      {
        v58 = 0;
LABEL_52:
        if ( v58 == 0 )
        {
          *v51 = v25;
          goto LABEL_87;
        }
        if ( v9 != v48 )
          goto LABEL_85;
        if ( v9 == 2 )
        {
          v60 = 0;
          if ( v48 >= 4 )
          {
            v61 = (float *)&v81;
            v62 = &v54[-1].ptr[5];
            v63 = &v50->ptr[1];
            do
            {
              v64 = v62[1];
              v60 += 4;
              v65 = (float)(v62[3] - v63[1]);
              v62 += 4;
              v66 = *(v63 - 1);
              v67 = (float)(*v62 - v63[2]);
              *(float *)((char *)v63 + (char *)&v85 - (char *)v50) = *(float *)((char *)v63 + (char *)v54 - (char *)v50)
                                                                   - *v63;
              *(float *)((char *)v63 + (char *)&v85.ptr[1] - (char *)v50) = v65;
              *(float *)((char *)v63 + (char *)&v85.ptr[2] - (char *)v50) = v67;
              v63 += 4;
              v61 += 4;
              *v61 = (float)v64 - (float)v66;
            }
            while ( v60 < v48 - 3 );
          }
          if ( v60 < v48 )
          {
            v68 = &v50->ptr[v60];
            v69 = v48 - v60;
            do
            {
              *(float *)((char *)v68 + (char *)&v85 - (char *)v50) = *(float *)((char *)v68 + (char *)v54 - (char *)v50)
                                                                   - *v68;
              ++v68;
              --v69;
            }
            while ( v69 != 0 );
          }
        }
        else
        {
          idMD6BlendBranch::UpdateNormal(this, p0: v50, p1: v54, inNormal: &v87, outNormal: &v85);
        }
        v70 = idMD6BlendBranch::GetPointSide(
                this,
                p0: v50,
                point: (const idArray<float,6> *)this->currentCoordinate.list,
                normal: &v85);
        v71 = 1;
        v72 = 1;
        if ( v48 <= 1 )
          goto LABEL_83;
        v73 = this->numDimensions;
        v74 = 1;
        v75 = __ROL4__(v73, 2);
        while ( 1 )
        {
          v76 = &v49[v46[v74] * v73];
          v77 = &idMD6BlendBranch::crossIndexTable[*(const unsigned int *)((char *)idMD6BlendBranch::crossIndexTableBase
                                                                         + v75)
                                                 - 4
                                                 + v75];
          v78 = (float)((float)((float)(v76[v77[1]] - v50->ptr[v77[1]]) * v85.ptr[*v77])
                      - (float)((float)(v76[v77[3]] - v50->ptr[v77[3]]) * v85.ptr[v77[2]]));
          if ( v78 == 0.0 )
          {
            v79 = 0;
          }
          else
          {
            v79 = 1;
            if ( v78 <= 0.0 )
              v79 = 2;
          }
          v24 = v84;
          if ( v84 != 0 )
            break;
          if ( v70 == POINTSIDE_ON )
            goto LABEL_77;
          v59 = v79 != v70;
          v80 = 0;
          if ( !v59 )
            goto LABEL_77;
LABEL_78:
          if ( v80 == 0 )
          {
            v71 = 0;
LABEL_82:
            v5 = indices;
            num = v83;
LABEL_83:
            if ( v71 == 0 )
            {
              *v51 = 2;
              goto LABEL_87;
            }
LABEL_85:
            if ( v24 == 0 )
            {
              v81 = 1;
LABEL_87:
              ++v47;
              ++v51;
              if ( v47 >= num )
              {
                v26 = v81;
                v82 = v47;
                goto LABEL_21;
              }
              goto LABEL_39;
            }
            v82 = v47;
            idList<idAnimWebBlendTree *,5>::Append(this: v5, obj: (const encounterGroupRole_t *)&v82);
            return true;
          }
          ++v72;
          ++v74;
          if ( v72 >= v48 )
            goto LABEL_82;
        }
        if ( v70 == POINTSIDE_ON || v79 != 0 && v70 != v79 )
        {
          v80 = 0;
          goto LABEL_78;
        }
LABEL_77:
        v80 = 1;
        goto LABEL_78;
      }
    }
    else if ( v57 != 0 )
    {
      v59 = PointSide != v57;
      v58 = 0;
      if ( v59 )
        goto LABEL_52;
    }
    v58 = 1;
    goto LABEL_52;
  }
LABEL_21:
  v27 = -1;
  v28 = 0;
  v83 = -1;
  v82 = 0;
  v29 = 3.4028235e38;
  if ( num <= 0 )
    return true;
  v30 = v88;
  do
  {
    if ( *v30 != 1 && (v26 == 0 || *v30 != 2) )
    {
      if ( v24 != 0 )
      {
        v82 = v28;
        v83 = v27;
        idList<idAnimWebBlendTree *,5>::Append(this: v5, obj: (const encounterGroupRole_t *)&v82);
        return true;
      }
      v31 = this->numDimensions;
      v32 = 0.0;
      v33 = 0;
      v34 = 0.0;
      v35 = v31 * v28;
      v36 = 0.0;
      if ( v31 >= 2 )
      {
        v37 = this->currentCoordinate.list;
        v38 = this->coordinateList.list;
        v39 = 0;
        v40 = v35;
        do
        {
          v41 = (float)(v37[v39] - v38[v40]);
          v33 += 2;
          v42 = (float)(v37[v39 + 1] - v38[v40 + 1]);
          v39 += 2;
          v40 += 2;
          v32 = (float)((float)((float)v41 * (float)v41) + (float)v32);
          v34 = (float)((float)((float)v42 * (float)v42) + (float)v34);
        }
        while ( v33 < (int)(v31 - 1) );
      }
      if ( v33 < (int)v31 )
      {
        v43 = (float)(this->currentCoordinate.list[v33] - this->coordinateList.list[v33 + v35]);
        v36 = (float)((float)v43 * (float)v43);
      }
      v44 = (float)((float)((float)v34 + (float)v36) + (float)v32);
      if ( v44 < v29 )
      {
        v27 = v28;
        v29 = v44;
      }
    }
    ++v28;
    ++v30;
  }
  while ( v28 < num );
  v82 = v28;
  v83 = v27;
  if ( v27 < 0 )
    return true;
  idList<idAnimWebBlendTree *,5>::Append(this: v5, obj: (const encounterGroupRole_t *)&v83);
  return __fabs(v29) < idMath::FLT_SMALLEST_NON_DENORMAL;
}


// ========================================================================
// ?FindAnimation@idMD6BlendBranch@@IAAX_NAAPAVidMD6Node@@1AAM@Z
// EA  : 0x8283FDE0
// RVA : 0x0083FDE0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6BlendBranch::FindAnimation(
        idMD6BlendBranch *this,
        const bool isSorted,
        idMD6Node **leftAnimation,
        idMD6Node **rightAnimation,
        float *alpha)
{
  int num; // r29
  double v11; // fp31
  idList<int,30> *p_activeIndices; // r28
  int *list; // r10
  int numDimensions; // r9
  float *v15; // r8
  int v16; // r11
  int v17; // r10
  int v18; // r7
  double v19; // fp0
  double v20; // fp12
  double v21; // fp13
  int v22; // r11
  int v23; // r9
  float *v24; // r8
  idMD6Node *v25; // r7
  int v26; // r10
  int v27; // r6
  double v28; // fp12
  double v29; // fp13
  int v30; // r4
  int v31; // r5
  double v32; // fp12
  int v33; // r8
  double v34; // fp13
  int v35; // r7
  float *v36; // r6
  int v37; // r9
  double v38; // fp0
  double v39; // fp0
  double v40; // fp0
  double v41; // fp0
  int v42; // r10
  float *v43; // r9
  int v44; // ctr
  double v45; // fp0
  int v46; // r11
  float *v47; // r10
  int v48; // r7
  int v49; // r6
  double v50; // fp0
  double v51; // fp0

  num = this->animationList.num;
  v11 = *this->currentCoordinate.list;
  p_activeIndices = &this->activeIndices;
  if ( this->activeIndices.num < 2 )
  {
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->activeIndices, newNum: 2);
    goto LABEL_10;
  }
  list = this->activeIndices.list;
  numDimensions = this->numDimensions;
  v15 = this->coordinateList.list;
  v16 = *list;
  v18 = numDimensions * *list;
  v17 = list[1];
  v19 = v15[v18];
  if ( v19 > v11 || v11 > v15[numDimensions * v17] )
  {
LABEL_10:
    if ( isSorted )
    {
      v22 = 1;
      if ( num <= 1 )
      {
LABEL_15:
        *alpha = 0.0;
        v25 = this->animationList.list[num - 1];
        *leftAnimation = v25;
        *rightAnimation = v25;
        *p_activeIndices->list = num - 1;
        p_activeIndices->list[1] = num - 1;
      }
      else
      {
        v23 = this->numDimensions;
        v24 = this->coordinateList.list;
        while ( v11 > v24[v23 * v22] )
        {
          if ( ++v22 >= num )
            goto LABEL_15;
        }
        v26 = v22 - 1;
        v27 = v23 * (v22 - 1);
        v28 = 0.0;
        if ( (float)(v24[v23 * v22] - v24[v27]) > 0.0 )
        {
          if ( v11 >= v24[v27] )
            v29 = v11;
          else
            v29 = v24[v27];
          v28 = (float)((float)((float)v29 - v24[v27]) / (float)(v24[v23 * v22] - v24[v27]));
        }
        *alpha = v28;
        *leftAnimation = this->animationList.list[v26];
        *rightAnimation = this->animationList.list[v22];
        *p_activeIndices->list = v26;
        p_activeIndices->list[1] = v22;
      }
    }
    else
    {
      v30 = -1;
      v31 = -1;
      v32 = 3.4028235e38;
      v33 = 0;
      v34 = -3.4028235e38;
      if ( num >= 4 )
      {
        v35 = this->numDimensions;
        v36 = this->coordinateList.list;
        v37 = 2;
        do
        {
          v38 = (float)((float)v11 - v36[v35 * v33]);
          if ( v38 < 0.0 )
          {
            if ( v38 > v34 )
            {
              v34 = (float)((float)v11 - v36[v35 * v33]);
              v31 = v33;
            }
          }
          else if ( v38 < v32 )
          {
            v32 = (float)((float)v11 - v36[v35 * v33]);
            v30 = v33;
          }
          v39 = (float)((float)v11 - v36[(v37 - 1) * v35]);
          if ( v39 < 0.0 )
          {
            if ( v39 > v34 )
            {
              v34 = (float)((float)v11 - v36[(v37 - 1) * v35]);
              v31 = v37 - 1;
            }
          }
          else if ( v39 < v32 )
          {
            v32 = (float)((float)v11 - v36[(v37 - 1) * v35]);
            v30 = v37 - 1;
          }
          v40 = (float)((float)v11 - v36[v37 * v35]);
          if ( v40 < 0.0 )
          {
            if ( v40 > v34 )
            {
              v34 = (float)((float)v11 - v36[v37 * v35]);
              v31 = v37;
            }
          }
          else if ( v40 < v32 )
          {
            v32 = (float)((float)v11 - v36[v37 * v35]);
            v30 = v37;
          }
          v41 = (float)((float)v11 - v36[(v37 + 1) * v35]);
          if ( v41 < 0.0 )
          {
            if ( v41 > v34 )
            {
              v34 = (float)((float)v11 - v36[(v37 + 1) * v35]);
              v31 = v37 + 1;
            }
          }
          else if ( v41 < v32 )
          {
            v32 = (float)((float)v11 - v36[(v37 + 1) * v35]);
            v30 = v37 + 1;
          }
          v33 += 4;
          v37 += 4;
        }
        while ( v33 < num - 3 );
      }
      if ( v33 < num )
      {
        v44 = num - v33;
        do
        {
          v42 = this->numDimensions;
          v43 = this->coordinateList.list;
          v45 = (float)((float)v11 - v43[v42 * v33]);
          if ( v45 < 0.0 )
          {
            if ( v45 > v34 )
            {
              v34 = (float)((float)v11 - v43[v42 * v33]);
              v31 = v33;
            }
          }
          else if ( v45 < v32 )
          {
            v32 = (float)((float)v11 - v43[v42 * v33]);
            v30 = v33;
          }
          ++v33;
          --v44;
        }
        while ( v44 != 0 );
      }
      v46 = this->numDimensions;
      v47 = this->coordinateList.list;
      v48 = v46 * v30;
      v49 = v46 * v31;
      v50 = v47[v49];
      if ( (float)(v47[v49] - v47[v48]) <= 0.0 )
      {
        v51 = 0.0;
      }
      else if ( v11 >= v47[v48] )
      {
        if ( v11 <= v50 )
          v50 = v11;
        v51 = (float)((float)((float)v50 - v47[v48]) / (float)(v47[v49] - v47[v48]));
      }
      else
      {
        v51 = (float)((float)(v47[v48] - v47[v48]) / (float)(v47[v49] - v47[v48]));
      }
      *alpha = v51;
      *leftAnimation = this->animationList.list[v30];
      *rightAnimation = this->animationList.list[v31];
      *p_activeIndices->list = v30;
      p_activeIndices->list[1] = v31;
    }
    return;
  }
  v20 = (float)(v15[numDimensions * v17] - v15[v18]);
  v21 = 0.0;
  *leftAnimation = this->animationList.list[v16];
  *rightAnimation = this->animationList.list[v17];
  if ( v20 > 0.0 )
  {
    if ( v11 < v19 )
    {
      *alpha = (float)((float)v19 - (float)v19) / (float)v20;
      return;
    }
    v21 = (float)((float)((float)v11 - (float)v19) / (float)v20);
  }
  *alpha = v21;
}


// ========================================================================
// ?Update@idMD6BlendAdditiveBranch@@QAAX_N@Z
// EA  : 0x82840280
// RVA : 0x00840280
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6BlendAdditiveBranch::Update(idMD6BlendAdditiveBranch *this, const bool forceUpdate)
{
  int num; // r11
  idMD6Node *baseAnimation; // r10
  int v4; // r3
  int v5; // r9
  idMD6Node *v6; // r8
  idMD6Node *v7; // [sp+50h] [-10h] BYREF
  float v8; // [sp+54h] [-Ch] BYREF

  if ( forceUpdate
    || __fabs((float)(this->currentCoordinate - this->activeCoordinate)) >= idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    num = this->animationList.num;
    this->activeCoordinate = this->currentCoordinate;
    if ( num > 0 )
    {
      v8 = 0.0;
      v7 = nullptr;
      idMD6BlendAdditiveBranch::FindAnimation(this, rightAnimation: &v7, alpha: &v8);
      v5 = *(_DWORD *)(v4 + 80);
      v6 = v7;
      *(float *)(v4 + 24) = v8;
      *(_DWORD *)(v4 + 4) = v5;
      *(_DWORD *)(v4 + 8) = v6;
    }
    else
    {
      baseAnimation = this->baseAnimation;
      this->currentAlpha = 0.0;
      this->left = baseAnimation;
      this->right = baseAnimation;
    }
  }
}


// ========================================================================
// ?Update@idMD6BestLeaf@@QAAXXZ
// EA  : 0x82840760
// RVA : 0x00840760
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6BestLeaf::Update(idMD6BestLeaf *this)
{
  unsigned int v1; // r24
  int v3; // r29
  unsigned int v4; // r27
  int v5; // r29
  int v6; // r28
  idMD6TagFilter *v7; // r3
  unsigned __int8 *list; // r4
  unsigned int v9; // r25
  int v10; // r28
  unsigned int v11; // r8
  signed int v12; // r11
  int v13; // r11
  int v14; // r3
  signed int v15; // r11
  int v16; // r11
  unsigned int v17; // r29
  bool v18; // cr56
  unsigned int desiredTag; // r10
  signed int v20; // r11
  unsigned int seed; // r8
  unsigned int v22; // r5
  int v23; // r3
  unsigned __int8 v24[4]; // [sp+50h] [-280h] BYREF
  int num; // [sp+54h] [-27Ch]
  idList<unsigned char,37> v26; // [sp+60h] [-270h] BYREF
  int v27; // [sp+70h] [-260h] BYREF
  idArray<bool,256> v28; // [sp+170h] [-160h] BYREF

  num = this->leafList.num;
  v1 = num;
  if ( num > 0 && this->bestLeafIndex != 0xFFFF && this->desiredTag == this->activeTag )
  {
    this->desiredTag = 0;
    return;
  }
  v26.granularity = 1;
  v26.num = 0;
  v26.size = 256;
  v26.list = (unsigned __int8 *)&v27;
  v26.memTag = 5;
  v26.listStatic = 1;
  v3 = this->filterList.num;
  v4 = 0;
  memset(Dst: &v28, Val: 0, Size: sizeof(v28));
  v5 = v3 - 1;
  if ( v5 >= 0 )
  {
    v6 = v5;
    do
    {
      v7 = (idMD6TagFilter *)this->filterList.list[v6];
      if ( v7->type == 7 )
        idMD6TagFilter::Update(
          this: v7,
          desiredTag: this->desiredTag,
          defaultTag: this->defaultTag,
          leafList: (const idList<idMD6Node *,5> *)&this->leafList,
          tagList: (const idList<unsigned int,5> *)&this->tagList,
          debugFilterLogicHelper: &this->debugFilterLogicHelper,
          skipList: &v28);
      --v5;
      --v6;
    }
    while ( v5 >= 0 );
  }
  idMD6TagFilter::Update(
    this: &this->tagGroupFilter,
    desiredTag: this->desiredTag,
    defaultTag: this->defaultTag,
    leafList: (const idList<idMD6Node *,5> *)&this->leafList,
    tagList: (const idList<unsigned int,5> *)&this->tagList,
    debugFilterLogicHelper: &this->debugFilterLogicHelper,
    skipList: &v28);
  list = v26.list;
  if ( num != 0 )
  {
    v9 = 0;
    v10 = 0;
    do
    {
      if ( !v28.ptr[v9] )
      {
        v11 = this->tagList.list[v10];
        v12 = ~(this->desiredTag ^ v11) - (((int)~(this->desiredTag ^ v11) >> 1) & 0x55555555);
        v13 = (((((v12 >> 2) & 0x33333333) + (v12 & 0x33333333)) >> 4) + ((v12 >> 2) & 0x33333333) + (v12 & 0x33333333))
            & 0xF0F0F0F;
        v14 = ((unsigned __int8)((unsigned int)((v13 >> 8) + v13) >> 16) + BYTE2(v13) + (_BYTE)v13) & 0x3F;
        v15 = (((int)(~(this->defaultTag ^ v11) - (((int)~(this->defaultTag ^ v11) >> 1) & 0x55555555)) >> 2)
             & 0x33333333)
            + ((~(this->defaultTag ^ v11) - (((int)~(this->defaultTag ^ v11) >> 1) & 0x55555555)) & 0x33333333);
        v16 = ((((v15 >> 4) + v15) & 0xF0F0F0F) >> 8) + (((v15 >> 4) + v15) & 0xF0F0F0F);
        v17 = (((v16 >> 16) + v16) & 0x3F) + 100 * v14;
        v18 = v17 < v4;
        if ( v17 > v4 )
        {
          if ( v26.listStatic == 0 || v26.listStatic == 2 )
          {
            if ( list != nullptr )
              idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
            list = nullptr;
            v26.size = 0;
            v26.list = nullptr;
          }
          v26.num = 0;
          v18 = v17 < v4;
        }
        if ( !v18 )
        {
          v24[0] = v9;
          v4 = v17;
          idList<unsigned char,25>::Append(this: &v26, obj: v24);
          list = v26.list;
        }
      }
      ++v9;
      ++v10;
    }
    while ( v9 < v1 );
  }
  desiredTag = this->desiredTag;
  v20 = v26.num;
  this->desiredTag = 0;
  this->activeTag = desiredTag;
  if ( v20 != 0 )
  {
    seed = animation->randomNumberGenerator.seed;
    __twllei(v20, 0);
    v22 = 1664525 * seed + 1013904223;
    v23 = (v22 >> 10) & 0x7FFF;
    animation->randomNumberGenerator.seed = v22;
    list = v26.list;
    __twlgei(v20 & ~(__ROL4__(v23, 1) - 1), 0xFFFFFFFF);
    this->bestLeafIndex = list[v23 % v20];
    if ( (v26.listStatic == 0 || v26.listStatic == 2) && list != nullptr )
      goto LABEL_31;
  }
  else
  {
    this->bestLeafIndex = -1;
    if ( (v26.listStatic == 0 || v26.listStatic == 2) && list != nullptr )
LABEL_31:
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$227580
// EA  : 0x82840AB0
// RVA : 0x00840AB0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_227580()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 720 + 96));
}


// ========================================================================
// ?InitCoordinateNodePairs@idMD6BlendBranch_Base@@IAAXHABV?$idList@M$04@@ABV?$idList@PAVidMD6Node@@$04@@H@Z
// EA  : 0x82840BA0
// RVA : 0x00840BA0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6BlendBranch_Base::InitCoordinateNodePairs(
        idMD6BlendBranch_Base *this,
        int numDimensions,
        const idList<float,32> *inCoordinates,
        const idList<idMD6Node *,5> *inAnimations,
        char flags)
{
  int num; // r24
  int v11; // r28
  int v12; // r29
  int v13; // r27
  int v14; // r30
  idMD6Node **list; // r10
  int v16; // r3
  int v17; // r27
  idPair<unsigned short,idAnimRecorder::NameStruct_t> *v18; // r10
  int v19; // r29
  int v20; // r24
  int v21; // r11
  double v22; // fp13
  double v23; // fp12
  bool v26; // zf
  int v27; // r25
  int v28; // r26
  idPair<unsigned short,idAnimRecorder::NameStruct_t> *v29; // r28
  double v30; // fp13
  double v31; // fp0
  int v32; // r29
  int v33; // r30
  int objectName; // r7
  int v35; // r28
  const idPair<unsigned short,idAnimRecorder::NameStruct_t> *v36; // r30
  int v37; // r3
  int v38; // r28
  idList<float,30> *p_coordinateList; // r30
  int v40; // r29
  int size; // r11
  int v42; // r11
  int v43; // r23
  int v44; // r25
  int v45; // r27
  int v46; // r6
  int v47; // r24
  int v48; // r11
  idPair<unsigned short,idAnimRecorder::NameStruct_t> *v49; // r28
  const char *typeName; // r8
  int v51; // r10
  int v52; // r9
  int v53; // r20
  int v54; // r5
  const char *v55; // r9
  int v56; // r11
  int v57; // r10
  int v58; // ctr
  idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair> v59; // [sp+50h] [-3100h] BYREF
  idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair> v60; // [sp+54h] [-30FCh] BYREF
  __int64 v61; // [sp+58h] [-30F8h] BYREF
  idPair<unsigned short,idAnimRecorder::NameStruct_t> v62; // [sp+60h] [-30F0h] BYREF
  aas2Edge_t v63; // [sp+70h] [-30E0h] BYREF
  idList<idPair<unsigned short,idAnimRecorder::NameStruct_t>,5> v64; // [sp+80h] [-30D0h] BYREF
  int v65; // [sp+90h] [-30C0h] BYREF
  idList<aas2Edge_t,37> v66; // [sp+C90h] [-24C0h] BYREF
  int v67; // [sp+CA0h] [-24B0h] BYREF
  idList<float,13> v68; // [sp+18A0h] [-18B0h] BYREF
  int v69; // [sp+18B0h] [-18A0h] BYREF

  num = inAnimations->num;
  if ( numDimensions <= 1 || (flags & 1) != 0 )
  {
    v64.granularity = 1;
    v64.size = 256;
    v64.memTag = 5;
    v64.num = 0;
    v64.list = (idPair<unsigned short,idAnimRecorder::NameStruct_t> *)&v65;
    v64.listStatic = 1;
    if ( num > 0 )
    {
      HIDWORD(v61) = numDimensions;
      v11 = 0;
      v12 = 0;
      v13 = 4 * numDimensions;
      v14 = num;
      do
      {
        list = inAnimations->list;
        LODWORD(v61) = (char *)inCoordinates->list + v12;
        *(_QWORD *)&v62.first = v61;
        v62.second.objectName = (const char *)list[v11];
        v60.__vftable = (idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair>_vtbl *)&idMD6BlendBranch_Base::idSearch_CoordinateNodePair::`vftable';
        v16 = idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair>::Search_FirstGreaterEqual(
                this: &v60,
                base: (const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *)v64.list,
                num: v64.num,
                value: (const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *)&v62);
        idList<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,5>::Insert(this: &v64, obj: &v62, index: v16);
        --v14;
        v60.__vftable = (idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair>_vtbl *)&idSearch<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>>::`vftable';
        v12 += v13;
        ++v11;
      }
      while ( v14 != 0 );
    }
    v68.num = 0;
    v68.granularity = 1;
    v68.size = 1536;
    v68.list = (float *)&v69;
    v68.listStatic = 1;
    v68.memTag = 5;
    if ( (flags & 1) != 0 && num > 1 )
    {
      v17 = num - 1;
      v18 = v64.list;
      v19 = 0;
      v21 = num - 1;
      v22 = __fabs(*(float *)v64.list->second.typeName);
      v23 = *(float *)v64.list[v21].second.typeName;
      v66.num = 0;
      v66.list = (aas2Edge_t *)&v67;
      v66.listStatic = 1;
      v66.size = 256;
      v66.granularity = 1;
      v66.memTag = 5;
      _FP10 = (float)((float)v22 - (float)__fabs(v23));
      __asm { fsel      f31, f10, f13, f11 }
      v26 = num - 1 <= 0;
      v20 = 0;
      if ( !v26 )
      {
        v27 = v21 * 12;
        v28 = 0;
        while ( 1 )
        {
          v29 = (idPair<unsigned short,idAnimRecorder::NameStruct_t> *)((char *)v18 + v27);
          v30 = __fabs(*(float *)v18[v28].second.typeName);
          v31 = __fabs(**(float **)((char *)&v18->second.typeName + v27));
          if ( v30 != _FP31 && v31 != _FP31 )
            break;
          if ( v30 != v31 )
          {
            if ( v30 >= v31 )
              v29 = &v18[v28];
            *(float *)&v61 = -*(float *)v29->second.typeName;
            idList<float,13>::Append(this: &v68, obj: (float *)&v61);
            if ( numDimensions > 1 )
            {
              v32 = 4;
              v33 = numDimensions - 1;
              do
              {
                idList<float,13>::Append(this: &v68, obj: (float *)&v29->second.typeName[v32]);
                --v33;
                v32 += 4;
              }
              while ( v33 != 0 );
            }
            objectName = (int)v29->second.objectName;
            v63.vertexNum[0] = *(_DWORD *)&v29->first;
            v63.flags = objectName;
            v63.vertexNum[1] = (int)&v68.list[v68.num - numDimensions];
            idList<idRenderModelEffects::deferredStage_t,5>::Append(this: &v66, obj: &v63);
          }
          ++v20;
          --v17;
          ++v28;
          v27 -= 12;
          if ( v20 >= v17 )
            break;
          v18 = v64.list;
        }
        v19 = v66.num;
      }
      if ( v19 > 0 )
      {
        v35 = 0;
        do
        {
          v59.__vftable = (idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair>_vtbl *)&idMD6BlendBranch_Base::idSearch_CoordinateNodePair::`vftable';
          v36 = (const idPair<unsigned short,idAnimRecorder::NameStruct_t> *)&v66.list[v35];
          v37 = idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair>::Search_FirstGreaterEqual(
                  this: &v59,
                  base: (const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *)v64.list,
                  num: v64.num,
                  value: (const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *)&v66.list[v35]);
          idList<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,5>::Insert(this: &v64, obj: v36, index: v37);
          --v19;
          v59.__vftable = (idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair>_vtbl *)&idSearch<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>>::`vftable';
          ++v35;
        }
        while ( v19 != 0 );
      }
      if ( v66.listStatic == 0 || v66.listStatic == 2 )
      {
        if ( v66.list != nullptr )
          idMem::Free(this: &mem, ptr: v66.list, align: ALIGN_16);
        v66.list = nullptr;
        v66.size = 0;
      }
      v66.num = 0;
    }
    v38 = v64.num;
    p_coordinateList = &this->coordinateList;
    v40 = v64.num * numDimensions;
    if ( v64.num * numDimensions <= this->coordinateList.size
      || (unsigned __int8)idList<float,116>::Resize(
                            this: (idList<float,13> *)&this->coordinateList,
                            newsize: v64.num * numDimensions) != 0 )
    {
      size = this->coordinateList.size;
      if ( v40 < size )
        size = v38 * numDimensions;
      this->coordinateList.num = size;
    }
    if ( v38 <= this->animationList.size
      || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                            this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->animationList,
                            newsize: v38) != 0 )
    {
      v42 = this->animationList.size;
      if ( v38 < v42 )
        v42 = v38;
      this->animationList.num = v42;
    }
    if ( v38 > 0 )
    {
      v43 = 0;
      v44 = 0;
      v45 = 0;
      v46 = 3;
      v47 = v38;
      do
      {
        v48 = 0;
        v49 = &v64.list[v44];
        if ( numDimensions >= 4 )
        {
          typeName = v49->second.typeName;
          v51 = 0;
          v52 = v45;
          do
          {
            v53 = v46 - 1 + v48;
            *(float *)((char *)p_coordinateList->list + v52) = *(float *)&typeName[v51];
            v54 = v46 + v48;
            v48 += 4;
            *(float *)((char *)p_coordinateList->list + v52 + 4) = *(float *)&typeName[v51 + 4];
            p_coordinateList->list[v53] = *(float *)&typeName[v51 + 8];
            p_coordinateList->list[v54] = *(float *)&typeName[v51 + 12];
            v51 += 16;
            v52 += 16;
          }
          while ( v48 < numDimensions - 3 );
        }
        if ( v48 < numDimensions )
        {
          v55 = v49->second.typeName;
          v57 = v48 + v46 - 3;
          v58 = numDimensions - v48;
          v56 = 4 * v48;
          do
          {
            p_coordinateList->list[v57] = *(float *)&v55[v56];
            v56 += 4;
            ++v57;
            --v58;
          }
          while ( v58 != 0 );
        }
        --v47;
        ++v44;
        v46 += numDimensions;
        v45 += 4 * numDimensions;
        this->animationList.list[v43++] = (idMD6Node *)v49->second.objectName;
      }
      while ( v47 != 0 );
    }
    if ( v68.listStatic == 0 || v68.listStatic == 2 )
    {
      if ( v68.list != nullptr )
        idMem::Free(this: &mem, ptr: v68.list, align: ALIGN_16);
      v68.list = nullptr;
      v68.size = 0;
    }
    v68.num = 0;
    if ( (v64.listStatic == 0 || v64.listStatic == 2) && v64.list != nullptr )
      idMem::Free(this: &mem, ptr: v64.list, align: ALIGN_16);
  }
  else
  {
    idList<float,32>::operator=(this: (idList<float,32> *)&this->coordinateList, other: inCoordinates);
    idList<idMaterial const *,59>::operator=(this: (idList<idMD6Node *,5> *)&this->animationList, other: inAnimations);
  }
}


// ========================================================================
// __unwind$227913
// EA  : 0x828410D4
// RVA : 0x008410D4
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_227913()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 12624 + 128));
}


// ========================================================================
// __unwind$227914
// EA  : 0x828410FC
// RVA : 0x008410FC
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_227914()
{
  int v0; // r12

  idMD6BlendBranch_Base::idSearch_CoordinateNodePair::~idSearch_CoordinateNodePair(this: (idMD6BlendBranch_Base::idSearch_CoordinateNodePair *)(v0 - 12624 + 84));
}


// ========================================================================
// __unwind$227915
// EA  : 0x82841124
// RVA : 0x00841124
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_227915()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 12624 + 6304));
}


// ========================================================================
// __unwind$227916
// EA  : 0x8284114C
// RVA : 0x0084114C
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_227916()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 12624 + 3216));
}


// ========================================================================
// __unwind$227917
// EA  : 0x82841174
// RVA : 0x00841174
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_227917()
{
  int v0; // r12

  idMD6BlendBranch_Base::idSearch_CoordinateNodePair::~idSearch_CoordinateNodePair(this: (idMD6BlendBranch_Base::idSearch_CoordinateNodePair *)(v0 - 12624 + 80));
}


// ========================================================================
// ?FindBarycentric@idMD6BlendBranch@@IAAXAAV?$idList@V?$idPair@MPAVidMD6Node@@@@$04@@@Z
// EA  : 0x828411A8
// RVA : 0x008411A8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6BlendBranch::FindBarycentric(idMD6BlendBranch *this, idList<idSkinMapping,46> *leaves)
{
  unsigned int numDimensions; // r27
  unsigned int v4; // r21
  char v6; // r19
  idList<idMD6Filter *,5> *p_activeIndices; // r20
  int *list; // r9
  float *v9; // r11
  unsigned int v10; // r10
  int v11; // r5
  const idArray<float,6> *v12; // r22
  float *v13; // r9
  float *v14; // r11
  int v15; // r9
  const idArray<float,6> *v16; // r25
  idGeometry::pointSide_t PointSide; // r28
  unsigned int v18; // r26
  idMD6Filter **v19; // r24
  int v20; // r29
  float *v21; // r23
  const idArray<float,6> *v22; // r4
  idGeometry::pointSide_t v23; // r3
  char v24; // r11
  int *v25; // r10
  idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair> *v26; // r11
  int i; // ctr
  int v28; // r8
  float *v29; // r10
  unsigned int v30; // r9
  int v31; // r11
  int v32; // r8
  float *v33; // r7
  const idArray<float,6> *v34; // r4
  float *v35; // r11
  idGeometry::pointSide_t v36; // r29
  const idArray<float,6> *v37; // r4
  idGeometry::pointSide_t v38; // r3
  char v39; // r11
  unsigned int v40; // r29
  idMD6Node **v41; // r9
  encounterGroupRole_t v42; // r28
  const idMaterial *v43; // r30
  int v44; // r29
  unsigned int v45; // r30
  unsigned int v46; // r29
  unsigned int v47; // r9
  unsigned int v48; // r6
  float *v49; // r3
  float *v50; // r5
  encounterGroupRole_t *v51; // r4
  unsigned int v52; // r11
  float *v53; // r10
  char *v54; // r7
  unsigned int v55; // r8
  unsigned int v56; // r10
  float *v57; // r11
  char *v58; // r8
  unsigned int v59; // r28
  double v60; // fp29
  unsigned int v61; // r11
  int v62; // r29
  double v63; // fp0
  idMD6Node **v64; // r10
  int num; // r5
  idPair<float,idMD6Node *> *v66; // r4
  encounterGroupRole_t v67; // r7
  int v68; // r3
  int v69; // r3
  idSkinMapping v70; // [sp+50h] [-1C0h] BYREF
  idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair> v71; // [sp+58h] [-1B8h] BYREF
  idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair> v72; // [sp+5Ch] [-1B4h] BYREF
  idArray<float,6> v73; // [sp+60h] [-1B0h] BYREF
  idPair<float,idMD6Node *> v74; // [sp+78h] [-198h] BYREF
  idPair<float,idMD6Node *> v75[2]; // [sp+80h] [-190h] BYREF
  idList<enum encounterGroupRole_t,5> v76; // [sp+90h] [-180h] BYREF
  int v77; // [sp+A0h] [-170h] BYREF
  int v78; // [sp+BCh] [-154h] BYREF
  idArray<float,6> v79; // [sp+C0h] [-150h] BYREF
  idArray<float,36> v80; // [sp+E0h] [-130h] BYREF

  numDimensions = this->numDimensions;
  v4 = numDimensions + 1;
  v6 = 1;
  p_activeIndices = (idList<idMD6Filter *,5> *)&this->activeIndices;
  if ( this->activeIndices.num < numDimensions + 1 )
  {
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->activeIndices, newNum: numDimensions + 1);
LABEL_26:
    v6 = 0;
    goto LABEL_27;
  }
  list = this->activeIndices.list;
  v9 = this->coordinateList.list;
  v10 = 0;
  v11 = this->numDimensions * *list;
  v12 = (const idArray<float,6> *)&v9[v11];
  v13 = &v9[list[1] * this->numDimensions];
  if ( this->numDimensions != 0 )
  {
    v14 = &v9[v11];
    v15 = (char *)v13 - (char *)v12;
    do
    {
      ++v10;
      *(float *)((char *)v14 + (char *)&v73 - (char *)v12) = *(float *)((char *)v14 + v15) - *v14;
      ++v14;
    }
    while ( v10 < numDimensions );
  }
  v16 = (const idArray<float,6> *)this->currentCoordinate.list;
  PointSide = idMD6BlendBranch::GetPointSide(this, p0: v12, point: v16, normal: &v73);
  v18 = 2;
  if ( v4 > 2 )
  {
    v19 = p_activeIndices->list;
    v20 = 2;
    v21 = this->coordinateList.list;
    while ( 1 )
    {
      v23 = idMD6BlendBranch::GetPointSide(
              this,
              p0: (const idArray<float,6> *)&v21[(_DWORD)v19[v20] * numDimensions],
              point: v16,
              normal: &v73);
      if ( v23 == POINTSIDE_ON || (v24 = 0, PointSide == v23) )
        v24 = 1;
      if ( v24 == 0 )
        break;
      v25 = &v78;
      v26 = &v72;
      for ( i = 6; i != 0; --i )
      {
        ++v26;
        *++v25 = (int)v26->__vftable;
      }
      idMD6BlendBranch::UpdateNormal(this, p0: v12, p1: v22, inNormal: &v79, outNormal: &v73);
      ++v18;
      PointSide = idMD6BlendBranch::GetPointSide(this, p0: v12, point: v16, normal: &v73);
      ++v20;
      if ( v18 >= v4 )
        goto LABEL_16;
    }
    v6 = 0;
  }
LABEL_16:
  if ( v6 != 0 )
  {
    v28 = this->numDimensions;
    v29 = this->coordinateList.list;
    v30 = 0;
    v31 = (int)p_activeIndices->list[v4 - 1] * v28;
    v32 = (int)p_activeIndices->list[numDimensions - 1] * v28;
    v33 = &v29[v31];
    v34 = (const idArray<float,6> *)&v29[v32];
    if ( numDimensions != 0 )
    {
      v35 = &v29[v32];
      do
      {
        ++v30;
        *(float *)((char *)v35 + (char *)&v73 - (char *)v34) = *(float *)((char *)v35 + (char *)v33 - (char *)v34)
                                                             - *v35;
        ++v35;
      }
      while ( v30 < numDimensions );
    }
    v36 = idMD6BlendBranch::GetPointSide(this, p0: v34, point: v16, normal: &v73);
    v38 = idMD6BlendBranch::GetPointSide(this, p0: v37, point: v12, normal: &v73);
    if ( v36 == POINTSIDE_ON || (v39 = 0, v38 == v36) )
      v39 = 1;
    if ( v39 == 0 )
      goto LABEL_26;
  }
LABEL_27:
  v76.granularity = 1;
  v76.listStatic = 1;
  v76.size = 7;
  v76.list = (encounterGroupRole_t *)&v77;
  v76.memTag = 5;
  v76.num = 0;
  if ( v6 != 0 )
  {
    idList<idMD6Filter *,5>::Append(this: (idList<idMD6Filter *,5> *)&v76, other: p_activeIndices);
  }
  else
  {
    v40 = 0;
    do
    {
      if ( idMD6BlendBranch::BuildPointList(this, indices: &v76, normal: &v73, isFillerPoint: 0) )
        break;
      ++v40;
    }
    while ( v40 < v4 );
  }
  if ( v76.num == 1 )
  {
    v41 = this->animationList.list;
    v42 = *v76.list;
    *(float *)&v70.from = 1.0;
    v43 = (const idMaterial *)v41[v42];
    v70.to = v43;
    idList<cachedPageFile_t,5>::Append(this: leaves, obj: &v70);
    *p_activeIndices->list = (idMD6Filter *)v42;
    if ( v4 > 1 )
    {
      v70.to = v43;
      v44 = 1;
      v45 = numDimensions;
      *(float *)&v70.from = 0.0;
      do
      {
        idList<cachedPageFile_t,5>::Append(this: leaves, obj: &v70);
        --v45;
        p_activeIndices->list[v44++] = (idMD6Filter *)v42;
      }
      while ( v45 != 0 );
    }
  }
  else
  {
    if ( v76.num < v4 )
    {
      v46 = v4 - v76.num;
      do
      {
        idMD6BlendBranch::BuildPointList(this, indices: &v76, normal: &v73, isFillerPoint: 1);
        --v46;
      }
      while ( v46 != 0 );
    }
    idList<idMaterial const *,59>::operator=(
      this: (idList<idMD6Node *,5> *)p_activeIndices,
      other: (const idList<idMD6Node *,5> *)&v76);
    v47 = this->numDimensions;
    v48 = 0;
    v49 = this->coordinateList.list;
    v50 = &v49[*(encounterGroupRole_t *)((char *)v76.list + __ROL4__(v47, 2)) * v47];
    if ( this->numDimensions != 0 )
    {
      v51 = v76.list;
      do
      {
        v52 = 0;
        v53 = v50;
        v54 = (char *)((char *)&v49[v47 * *v51] - (char *)v50);
        do
        {
          v55 = v47 * v52++ + v48;
          v80.ptr[v55] = *(float *)((char *)v53 + (_DWORD)v54) - *v53;
          ++v53;
        }
        while ( v52 < v47 );
        ++v48;
        ++v51;
      }
      while ( v48 < v47 );
    }
    v56 = 0;
    if ( v47 != 0 )
    {
      v57 = v50;
      v58 = (char *)((char *)this->currentCoordinate.list - (char *)v50);
      do
      {
        ++v56;
        *(float *)((char *)v57 + (char *)&v79 - (char *)v50) = *(float *)((char *)v57 + (_DWORD)v58) - *v57;
        ++v57;
      }
      while ( v56 < v47 );
    }
    idMD6BlendBranch::Solve_Gaussian(this, v: &v79, m: &v80, out: &v73);
    v59 = 0;
    v60 = 0.0;
    v61 = this->numDimensions;
    if ( this->numDimensions != 0 )
    {
      v62 = 0;
      do
      {
        v63 = v73.ptr[v62];
        if ( v63 >= 0.0 )
        {
          if ( v63 > 1.0 )
            v63 = 1.0;
        }
        else
        {
          v63 = 0.0;
        }
        v60 = (float)((float)v63 + (float)v60);
        v72.__vftable = (idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>_vtbl *)&idMD6BlendBranch::idSearch_AlphaNodePair::`vftable';
        v64 = this->animationList.list;
        num = leaves->num;
        v66 = (idPair<float,idMD6Node *> *)leaves->list;
        v67 = v76.list[v62];
        v75[0].first = v63;
        v70.from = (const idMaterial *)&v76.list[v62];
        v75[0].second = v64[v67];
        v68 = idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>::Search_FirstGreaterEqual(
                this: &v72,
                base: v66,
                num,
                value: v75);
        idList<idPair<float,idMD6Node *>,5>::Insert(
          this: (idList<idPair<float,idMD6Node *>,5> *)leaves,
          obj: v75,
          index: v68);
        v61 = this->numDimensions;
        ++v59;
        v72.__vftable = (idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>_vtbl *)&idSearch<idPair<float,idMD6Node *>>::`vftable';
        ++v62;
      }
      while ( v59 < v61 );
    }
    v74.second = this->animationList.list[v76.list[v61]];
    v71.__vftable = (idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>_vtbl *)&idMD6BlendBranch::idSearch_AlphaNodePair::`vftable';
    v74.first = (float)1.0 - (float)v60;
    v69 = idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>::Search_FirstGreaterEqual(
            this: &v71,
            base: (const idPair<float,idMD6Node *> *)leaves->list,
            num: leaves->num,
            value: &v74);
    idList<idPair<float,idMD6Node *>,5>::Insert(
      this: (idList<idPair<float,idMD6Node *>,5> *)leaves,
      obj: &v74,
      index: v69);
    v71.__vftable = (idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>_vtbl *)&idSearch<idPair<float,idMD6Node *>>::`vftable';
  }
  if ( (v76.listStatic == 0 || v76.listStatic == 2) && v76.list != nullptr )
    idMem::Free(this: &mem, ptr: v76.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$228454
// EA  : 0x828417A0
// RVA : 0x008417A0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_228454()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 144));
}


// ========================================================================
// __unwind$228455
// EA  : 0x828417C8
// RVA : 0x008417C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_228455()
{
  int v0; // r12

  idMD6BlendBranch::idSearch_AlphaNodePair::~idSearch_AlphaNodePair(this: (idMD6BlendBranch::idSearch_AlphaNodePair *)(v0 - 528 + 92));
}


// ========================================================================
// __unwind$228456
// EA  : 0x828417F0
// RVA : 0x008417F0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_228456()
{
  int v0; // r12

  idMD6BlendBranch::idSearch_AlphaNodePair::~idSearch_AlphaNodePair(this: (idMD6BlendBranch::idSearch_AlphaNodePair *)(v0 - 528 + 88));
}


// ========================================================================
// ?Init@idMD6BlendAdditiveBranch@@QAAXPAVidMD6Node@@ABV?$idList@M$04@@ABV?$idList@PAVidMD6Node@@$04@@MW4md6WeightGroup_t@@@Z
// EA  : 0x82841818
// RVA : 0x00841818
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6BlendAdditiveBranch::Init(
        idMD6BlendAdditiveBranch *this,
        idMD6Node *baseAnimation_,
        const idList<float,32> *coordinates,
        const idList<idMD6Node *,5> *animations,
        double currentCoordinate_,
        const md6WeightGroup_t weightGroup,
        unsigned __int8 a7)
{
  idMD6Node *right; // r7
  idMD6Node *left; // r6
  double currentAlpha; // fp0

  this->baseAnimation = baseAnimation_;
  this->currentCoordinate = currentCoordinate_;
  idMD6BlendBranch_Base::InitCoordinateNodePairs(
    this,
    numDimensions: 1,
    inCoordinates: coordinates,
    inAnimations: animations,
    flags: 0);
  idMD6BlendAdditiveBranch::Update(this, forceUpdate: true);
  right = this->right;
  left = this->left;
  this->originBlend = 0;
  this->filterGroup = a7;
  this->op = 8;
  this->alphaRate = 0.0;
  this->blendType = BLEND_LINEAR;
  this->right = right;
  this->left = left;
  currentAlpha = this->currentAlpha;
  this->currentAlpha = this->currentAlpha;
  this->targetAlpha = currentAlpha;
}


// ========================================================================
// ?SetNumAnimMods@idMD6LeafPause@@QAAXH@Z
// EA  : 0x82841958
// RVA : 0x00841958
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6LeafPause::SetNumAnimMods(idMD6LeafPause *this, int n, int a3, int a4, int a5, __int64 a6)
{
  idList<idMD6Blend::jointMod_t,30> *animMods; // r28
  int i; // r29
  char *v9; // r11
  int j; // ctr
  char v11; // [sp+48h] [-88h] BYREF
  idMD6Blend::jointMod_t v12; // [sp+50h] [-80h] BYREF

  if ( n != this->animMods[0].num )
  {
    animMods = this->animMods;
    for ( i = 2; i != 0; --i )
    {
      v12.joint.value = -1;
      v9 = &v11;
      v12.flags = 0;
      LODWORD(a6) = 0;
      for ( j = 6; j != 0; --j )
      {
        v9 += 8;
        *(_QWORD *)v9 = a6;
      }
      v12.s[2] = 0.0;
      v12.s[1] = 0.0;
      v12.s[0] = 0.0;
      idList<idMD6Blend::jointMod_t,30>::SetNum(this: animMods++, newNum: n, initValue: &v12);
    }
  }
}


// ========================================================================
// ?Update@idMD6BlendBranch@@QAAX_N0@Z
// EA  : 0x828419F0
// RVA : 0x008419F0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6BlendBranch::Update(idMD6BlendBranch *this, const bool forceUpdate, bool isSorted)
{
  char v5; // r8
  int v6; // r9
  double v7; // fp13
  int num; // r11
  idMD6Node **list; // r10
  idMD6Node *v10; // r10
  idMD6Node *v11; // r9
  idMD6BlendBranch *v12; // r8
  int v13; // r10
  int v14; // r5
  double v15; // fp0
  int v16; // r6
  int v17; // r7
  idSkinMapping *v18; // r9
  idMD6Node *v21; // [sp+50h] [-90h] BYREF
  float v22; // [sp+54h] [-8Ch] BYREF
  idMD6Node *v23; // [sp+58h] [-88h] BYREF
  idList<idSkinMapping,46> v24; // [sp+60h] [-80h] BYREF
  int v25; // [sp+70h] [-70h] BYREF

  if ( forceUpdate )
    goto LABEL_9;
  v5 = 0;
  v6 = 0;
  if ( this->numDimensions != 0 )
  {
    v7 = __fabs((float)(*this->currentCoordinate.list - *this->activeCoordinate.list));
    while ( v7 < idMath::FLT_SMALLEST_NON_DENORMAL )
    {
      if ( ++v6 >= (unsigned int)this->numDimensions )
        goto LABEL_8;
    }
    v5 = 1;
  }
LABEL_8:
  if ( v5 != 0 )
  {
LABEL_9:
    idList<float,32>::operator=(
      this: (idList<float,32> *)&this->activeCoordinate,
      other: (const idList<float,32> *)&this->currentCoordinate);
    num = this->animationList.num;
    if ( num > 0 )
    {
      if ( num == 1 )
      {
        list = this->animationList.list;
        this->currentAlpha = 0.0;
        this->left = *list;
        this->right = *list;
      }
      else if ( this->numDimensions == 1 )
      {
        v21 = nullptr;
        v23 = nullptr;
        v22 = 0.0;
        idMD6BlendBranch::FindAnimation(this, isSorted, leftAnimation: &v21, rightAnimation: &v23, alpha: &v22);
        v10 = v21;
        v11 = v23;
        this->currentAlpha = v22;
        this->left = v10;
        this->right = v11;
      }
      else
      {
        v24.num = 0;
        v24.granularity = 1;
        v24.size = 7;
        v24.list = (idSkinMapping *)&v25;
        v24.memTag = 5;
        v24.listStatic = 1;
        idMD6BlendBranch::FindBarycentric(this, leaves: &v24);
        v12 = this;
        v13 = 0;
        v14 = this->numDimensions - 1;
        v15 = 1.0;
        if ( this->numDimensions != 0 )
        {
          v16 = 0;
          v17 = 0;
          do
          {
            v18 = &v24.list[v17];
            if ( __fabs(v15) >= idMath::FLT_SMALLEST_NON_DENORMAL )
            {
              _FP9 = -(float)((float)((float)v15 - *(float *)&v18->from) / (float)v15);
              __asm { fsel      f13, f9, f12, f10 }
            }
            else
            {
              _FP13 = 0.0;
            }
            v12->currentAlpha = _FP13;
            v12->left = (idMD6Node *)v18->to;
            if ( v13 < v14 )
            {
              v15 = (float)((float)_FP13 * (float)v15);
              v12 = (idMD6BlendBranch *)&this->branchList.list[v16];
            }
            ++v13;
            ++v17;
            ++v16;
          }
          while ( v13 < this->numDimensions );
        }
        v12->right = *(idMD6Node **)((char *)&v24.list->to + __ROL4__(this->numDimensions, 3));
        if ( (v24.listStatic == 0 || v24.listStatic == 2) && v24.list != nullptr )
          idMem::Free(this: &mem, ptr: v24.list, align: ALIGN_16);
      }
    }
    else
    {
      this->left = nullptr;
      this->right = nullptr;
      this->currentAlpha = 0.0;
    }
  }
}


// ========================================================================
// __unwind$228937
// EA  : 0x82841C70
// RVA : 0x00841C70
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void _unwind_228937()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 224 + 96));
}


// ========================================================================
// ?Update@idMD6FusionBranch@@QAAX_NHHPBVidMD6Skel@@@Z
// EA  : 0x82841C98
// RVA : 0x00841C98
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6FusionBranch::Update(
        idMD6FusionBranch *this,
        const bool forceUpdate,
        int gameTime,
        int ticksPerSec,
        __int64 skeleton)
{
  __int64 v5; // r11
  idMD6Node *v6; // r22
  double v8; // fp31
  double v10; // fp8
  double v12; // fp13
  int v14; // r20
  idMD6FusionBranch *right; // r4
  double v16; // fp12
  double v17; // fp11
  double i; // fp0
  double v19; // fp1
  double v20; // fp0
  int v21; // r9
  int v22; // r9
  int type; // r11
  char v24; // r11
  bool v25; // zf
  int v26; // r11
  __int128 v27; // r11
  int v28; // r7
  int v29; // r6
  int v30; // r5
  __int64 v31; // r10
  __int64 v32; // r8
  int v33; // r6
  int v34; // r4
  idMD6LeafPlay *v35; // r3
  long double v36; // fp4
  double v37; // fp2
  double v38; // fp1
  double FloatFrame; // fp30
  idMD6PhaseTrack *v40; // r11
  signed int v41; // r31
  phaseTrackData_t *data; // r10
  idMD6PhaseTrack *v43; // r30
  int v44; // r4
  unsigned int v45; // r31
  long double v46; // fp2
  unsigned int v47; // r30
  long double v48; // fp2
  int v49; // r5
  int v50; // r3
  int num; // r24
  int v52; // r25
  int v53; // r29
  unsigned __int16 v54; // r27
  int v55; // r26
  idMD6Node *v56; // r31
  unsigned __int16 *list; // r9
  __int64 v58; // r11
  __int64 v59; // r8
  int v60; // r30
  __int128 v61; // r11
  int v62; // r7
  int v63; // r6
  int v64; // r5
  __int64 v65; // r10
  int v66; // r8
  int v67; // r7
  int v68; // r6
  int v69; // r4
  idMD6LeafPlay *v70; // r3
  int Frame; // r9
  int v72; // r11
  int v73; // r10
  int v74; // r11
  int v75; // r10
  __int64 v76; // r11
  const idMD6SkelData *v77; // r3
  int v78; // r11
  int v79; // r10
  float *v80; // r9
  __int16 value; // r6
  bool v82; // r4
  int v83; // r10
  md6WeightGroup_t v84; // r9
  const idList<float,5> *v85; // r8
  const idList<idMD6Node *,5> *v86; // r7
  const idList<float,5> *v87; // r6
  const idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *v88; // r5
  unsigned __int8 v89; // r4
  idMD6BlendBranch *v90; // r3
  unsigned __int8 v91[8]; // [sp+50h] [-4E0h] BYREF
  __int64 v92; // [sp+58h] [-4D8h] BYREF
  __int64 v93; // [sp+60h] [-4D0h] BYREF
  __int64 v94; // [sp+68h] [-4C8h] BYREF
  float v95[272]; // [sp+70h] [-4C0h] BYREF

  HIDWORD(v5) = 0x82000000;
  v6 = nullptr;
  v8 = 0.0;
  v10 = 1.0;
  v12 = idMath::FLT_SMALLEST_NON_DENORMAL;
  *(float *)&v93 = 0.0;
  v14 = HIDWORD(skeleton);
  *(float *)&v92 = 0.0;
  right = this;
  HIDWORD(v94) = 0;
  v16 = 0.0;
  v17 = 0.0;
  for ( i = 1.0; ; i = v19 )
  {
    LODWORD(skeleton) = right->left;
    v19 = (float)(right->currentAlpha * (float)i);
    v20 = (float)((float)i - (float)(right->currentAlpha * (float)i));
    if ( __fabs(v20) >= v12 )
    {
      v21 = 0;
      if ( *(_BYTE *)skeleton == 2 )
      {
        v5 = *(unsigned int *)(*(_DWORD *)(skeleton + 4) + 40);
        if ( (_DWORD)v5 != 0 )
        {
          HIDWORD(v5) = *(unsigned __int16 *)(v5 + 8);
          LODWORD(v5) = *(unsigned __int16 *)(v5 + 10);
        }
        else
        {
          LODWORD(v5) = 30;
        }
        __twllei(v5, 0);
        v22 = (HIDWORD(v5) - 1) * ticksPerSec;
        HIDWORD(v5) = __ROL4__(v22, 1);
        v21 = v22 / (int)v5;
        HIDWORD(skeleton) = HIDWORD(v5) - 1;
        __twlgei(v5 & ~(HIDWORD(v5) - 1), 0xFFFFFFFF);
      }
      LODWORD(v5) = v21;
      v92 = v5;
      v16 = (float)((float)((float)v5 * (float)v20) + (float)v16);
      if ( v20 > v17 )
      {
        v17 = v20;
        v6 = (idMD6Node *)skeleton;
      }
    }
    if ( __fabs(v19) < v12 )
      break;
    right = (idMD6FusionBranch *)right->right;
    type = right->type;
    if ( right->type == 0 || type == 3 || type == 4 || (v25 = type != 5, v24 = 0, !v25) )
      v24 = 1;
    if ( v24 == 0 )
    {
      *(float *)&v92 = v17;
      *(float *)&v93 = v16;
      HIDWORD(v94) = v6;
      idMD6FusionBranch::UpdateMasterNodeAndTotalScaledDuration(
        this,
        node: right,
        alpha: v19,
        ticksPerSec: gameTime,
        masterNode: (idMD6Node **)ticksPerSec,
        masterNodeWeight: (float *)&v94,
        totalScaledDuration: (float *)&v92,
        a8: (float *)&v93);
      v16 = *(float *)&v93;
      v12 = idMath::FLT_SMALLEST_NON_DENORMAL;
      v6 = (idMD6Node *)HIDWORD(v94);
      goto LABEL_21;
    }
  }
  *(float *)&v92 = v17;
  HIDWORD(v94) = v6;
  *(float *)&v93 = v16;
LABEL_21:
  if ( __fabs(v16) >= v12 )
    v8 = (float)((float)v10 / (float)v16);
  v26 = v6->type;
  if ( v26 == 2 )
  {
    LODWORD(v27) = idMD6Leaf::GetLength(this: (idMD6Leaf *)v6, ticksPerSec, a3: gameTime, a4: skeleton);
    v92 = v27;
    idMD6LeafPlay::SetRateScale(
      this: (idMD6LeafPlay *)v6,
      gameTime,
      rs: (float)((float)(__int64)v27 * (float)v8),
      a4: v30,
      a5: v29,
      a6: v28,
      a7: SHIDWORD(v27),
      a8: *(__int64 *)((char *)&v27 + 4));
    FloatFrame = idMD6LeafPlay::GetFloatFrame(
                   this: v35,
                   gameTime: v34,
                   ticksPerSec,
                   a4: v38,
                   a5: v37,
                   a6: v36,
                   a7: v33,
                   a8: v32,
                   a9: v31);
  }
  else
  {
    if ( v26 != 1 )
    {
      idLib::FatalError(fmt: "idMD6FusionBranch::Update - Invalid master node");
      idMD6BlendBranch::Init(
        this: v90,
        numDimensions_: v89,
        userChannelIndices_: v88,
        coordinates: v87,
        animations: v86,
        currentCoordinate_: v85,
        weightGroup: v84,
        flags: v83);
      return;
    }
    FloatFrame = *(float *)&v6[52].type;
  }
  v40 = *(idMD6PhaseTrack **)&v6[4].type;
  v41 = 0;
  data = v40[10].data;
  if ( data != nullptr )
    v41 = *(unsigned __int16 *)data->pad;
  LODWORD(v92) = (int)FloatFrame;
  v43 = v40 + 11;
  idMD6PhaseTrack::GetPhase(this: v40 + 11, frame: (int)FloatFrame, phase: v91);
  v44 = ((int)FloatFrame + 1) % v41;
  __twllei(v41, 0);
  __twlgei(v41 & ~(__ROL4__((int)FloatFrame + 1, 1) - 1), 0xFFFFFFFF);
  v45 = v91[0];
  idMD6PhaseTrack::GetPhase(this: v43, frame: v44, phase: v91);
  *(double *)&v46 = FloatFrame;
  v47 = v91[0];
  v48 = floor(x: v46);
  v50 = WrappedLerp<int>(
          rangeMin: 0,
          rangeMax: 0xFFu,
          b: __SPAIR64__(v45, v47),
          f: (float)((float)FloatFrame - (float)*(double *)&v48));
  num = this->animationList.num;
  v52 = v50;
  v53 = 0;
  if ( num > 0 )
  {
    v54 = 0;
    v55 = 0;
    do
    {
      v56 = this->animationList.list[v55];
      if ( v56 != v6 )
      {
        HIDWORD(v58) = v54;
        list = this->phaseToFrameLookupData.list;
        LODWORD(v58) = v56->type;
        LODWORD(v59) = v54 + v52;
        v60 = list[(_DWORD)v59];
        if ( (_DWORD)v58 == 2 )
        {
          HIDWORD(v59) = 2 * v59;
          LODWORD(v61) = idMD6Leaf::GetLength(this: (idMD6Leaf *)v56, ticksPerSec, a3: v49, a4: v59);
          v92 = v61;
          idMD6LeafPlay::SetRateScale(
            this: (idMD6LeafPlay *)v56,
            gameTime,
            rs: (float)((float)(__int64)v61 * (float)v8),
            a4: v64,
            a5: v63,
            a6: v62,
            a7: SHIDWORD(v61),
            a8: *(__int64 *)((char *)&v61 + 4));
          Frame = (unsigned __int16)idMD6LeafPlay::GetFrame(
                                      this: v70,
                                      gameTime: v69,
                                      ticksPerSec,
                                      a4: v68,
                                      a5: v67,
                                      a6: v66,
                                      a7: v65);
          v72 = *(_DWORD *)(*(_DWORD *)&v56[4].type + 40);
          v73 = 0;
          if ( v72 != 0 )
            v73 = *(unsigned __int16 *)(v72 + 8);
          v74 = abs32(v60 - Frame);
          v75 = v73 - v74 - 1;
          if ( v74 >= v75 )
            v74 = v75;
          if ( v74 > 3 )
            idMD6LeafPlay::SetFrame(this: (idMD6LeafPlay *)v56, gameTime, ticksPerSec, targetFrame: v60);
        }
        else if ( (_DWORD)v58 == 1 )
        {
          LODWORD(v58) = list[(_DWORD)v59];
          v93 = v58;
          *(float *)&v56[52].type = (float)v58;
        }
        if ( this->userChannelIndices.num > 0 )
        {
          LODWORD(v76) = v60;
          HIDWORD(v76) = *(_DWORD *)&v56[4].type;
          v77 = *(const idMD6SkelData **)(v14 + 40);
          v94 = v76;
          idMD6Blend::DecodeUserChannelsForAnimFrame(
            skeleton: v77,
            animData: *(const idMD6AnimData **)(HIDWORD(v76) + 40),
            frame: (float)v76,
            outUserChannels: (float *)v49,
            outUserChannelsSize: v95);
          v78 = 0;
          if ( this->numDimensions != 0 )
          {
            v79 = 0;
            v80 = &this->coordinateList.list[this->numDimensions * v53 - 1];
            do
            {
              ++v78;
              value = this->userChannelIndices.list[v79++].value;
              v49 = value;
              *++v80 = v95[value];
            }
            while ( v78 < this->numDimensions );
          }
        }
      }
      ++v53;
      ++v55;
      v54 += 256;
    }
    while ( v53 < num );
  }
  if ( !forceUpdate || (v82 = true, v6->type != 2) )
    v82 = false;
  idMD6BlendBranch::Update(
    this,
    forceUpdate: v82,
    isSorted: (this->userChannelIndices.num | (this->userChannelIndices.num - 1)) < 0);
}


// ========================================================================
// ?Init@idMD6BlendBranch@@QAAXEABV?$idList@V?$idIndex@FW4invalidUserChannelIndex_t@@@@$04@@ABV?$idList@M$04@@ABV?$idList@PAVidMD6Node@@$04@@1W4md6WeightGroup_t@@H@Z
// EA  : 0x82842158
// RVA : 0x00842158
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6BlendBranch::Init(
        idMD6BlendBranch *this,
        unsigned __int8 numDimensions_,
        const idList<idIndex<short,enum invalidJointIndex_t>,30> *userChannelIndices_,
        const idList<float,32> *coordinates,
        const idList<idMD6Node *,5> *animations,
        const idList<float,32> *currentCoordinate_,
        const md6WeightGroup_t weightGroup,
        char flags)
{
  unsigned __int8 v12; // r27
  int numDimensions; // r11
  idList<idMD6Branch,30> *p_branchList; // r30
  int v16; // r28
  int size; // r11
  int v18; // r11
  int v19; // r5
  int v20; // r9
  unsigned int v21; // ctr
  idMD6Branch *v22; // r10
  int v23; // r11
  int v24; // r4
  int v25; // r11
  int v26; // r10
  int v27; // r9
  int v28; // ctr
  idMD6Branch *v29; // r10
  int v30; // r4
  idMD6Node *right; // r8
  idMD6Node *left; // r7
  double currentAlpha; // fp0

  this->numDimensions = numDimensions_;
  v12 = weightGroup;
  idList<idIndex<short,enum invalidJointIndex_t>,30>::operator=(
    this: (idList<idIndex<short,enum invalidJointIndex_t>,30> *)&this->userChannelIndices,
    other: userChannelIndices_);
  idList<float,32>::operator=(this: (idList<float,32> *)&this->currentCoordinate, other: currentCoordinate_);
  numDimensions = this->numDimensions;
  p_branchList = &this->branchList;
  v16 = numDimensions - 1;
  if ( numDimensions - 1 <= this->branchList.size
    || (unsigned __int8)idList<idMD6Branch,30>::Resize(
                          this: (idList<idMD6Branch,5> *)&this->branchList,
                          newsize: numDimensions - 1) != 0 )
  {
    size = this->branchList.size;
    if ( v16 < size )
      size = v16;
    this->branchList.num = size;
  }
  if ( v16 > 0 )
  {
    v18 = 0;
    v19 = v16 - 1;
    if ( v16 >= 4 )
    {
      v20 = v19;
      v21 = (unsigned int)v16 >> 2;
      v19 -= v16 & 0xFFFFFFFC;
      do
      {
        v22 = &p_branchList->list[v20];
        v22->filterGroup = v12;
        v22->op = 1;
        v22->originBlend = 0;
        v22->left = nullptr;
        v22->right = (idMD6Node *)v18;
        v22->currentAlpha = 0.0;
        v22->targetAlpha = 0.0;
        v22->alphaRate = 0.0;
        v22->blendType = BLEND_LINEAR;
        v23 = (int)&p_branchList->list[v20 - 1];
        v24 = v23;
        *(_BYTE *)(v23 + 20) = v12;
        *(_BYTE *)(v23 + 21) = 1;
        *(_BYTE *)(v23 + 22) = 0;
        *(_DWORD *)(v23 + 4) = 0;
        *(_DWORD *)(v23 + 8) = v22;
        *(float *)(v23 + 24) = 0.0;
        *(float *)(v23 + 28) = 0.0;
        *(float *)(v23 + 32) = 0.0;
        *(_DWORD *)(v23 + 36) = 0;
        v25 = (int)&p_branchList->list[v20 - 3];
        *(_BYTE *)(v25 + 60) = v12;
        v26 = v25 + 40;
        *(_BYTE *)(v25 + 61) = 1;
        *(_BYTE *)(v25 + 62) = 0;
        *(_DWORD *)(v25 + 44) = 0;
        *(_DWORD *)(v25 + 48) = v24;
        *(float *)(v25 + 64) = 0.0;
        *(float *)(v25 + 68) = 0.0;
        *(float *)(v25 + 72) = 0.0;
        *(_DWORD *)(v25 + 76) = 0;
        v18 = (int)&p_branchList->list[v20 - 3];
        v20 -= 4;
        *(_BYTE *)(v18 + 20) = v12;
        *(_BYTE *)(v18 + 21) = 1;
        *(_BYTE *)(v18 + 22) = 0;
        *(_DWORD *)(v18 + 4) = 0;
        *(_DWORD *)(v18 + 8) = v26;
        *(float *)(v18 + 24) = 0.0;
        *(float *)(v18 + 28) = 0.0;
        *(float *)(v18 + 32) = 0.0;
        *(_DWORD *)(v18 + 36) = 0;
        --v21;
      }
      while ( v21 != 0 );
    }
    if ( v19 >= 0 )
    {
      v27 = v19;
      v28 = v19 + 1;
      do
      {
        v29 = &p_branchList->list[v27--];
        v29->right = (idMD6Node *)v18;
        v29->currentAlpha = 0.0;
        v29->targetAlpha = 0.0;
        v29->filterGroup = v12;
        v29->alphaRate = 0.0;
        v29->op = 1;
        v29->originBlend = 0;
        v18 = (int)v29;
        v29->left = nullptr;
        v29->blendType = BLEND_LINEAR;
        --v28;
      }
      while ( v28 != 0 );
    }
    this->right = p_branchList->list;
  }
  v30 = this->numDimensions;
  this->isAngleWrapped = flags & 1;
  idMD6BlendBranch_Base::InitCoordinateNodePairs(
    this,
    numDimensions: v30,
    inCoordinates: coordinates,
    inAnimations: animations,
    flags);
  idMD6BlendBranch::Update(this, forceUpdate: true, isSorted: true);
  right = this->right;
  left = this->left;
  currentAlpha = this->currentAlpha;
  this->filterGroup = v12;
  this->alphaRate = 0.0;
  this->op = 7;
  this->currentAlpha = currentAlpha;
  this->originBlend = 0;
  this->targetAlpha = currentAlpha;
  this->blendType = BLEND_LINEAR;
  this->right = right;
  this->left = left;
}


// ========================================================================
// ?Init@idMD6FusionBranch@@QAAXEABV?$idList@V?$idIndex@FW4invalidUserChannelIndex_t@@@@$04@@ABV?$idList@M$04@@ABV?$idList@PAVidMD6Node@@$04@@1W4md6WeightGroup_t@@H@Z
// EA  : 0x828423D8
// RVA : 0x008423D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __fastcall idMD6FusionBranch::Init(
        idMD6FusionBranch *this,
        unsigned __int8 numDimensions_,
        const idList<idIndex<short,enum invalidJointIndex_t>,30> *userChannelIndices_,
        const idList<float,32> *coordinates,
        const idList<idMD6Node *,5> *animations,
        const idList<float,32> *currentCoordinate_,
        md6WeightGroup_t weightGroup,
        char flags)
{
  idList<unsigned short,30> *p_phaseToFrameLookupData; // r26
  int num; // r19
  int v11; // r21
  unsigned __int16 v12; // r23
  int v13; // r22
  idMD6Node *v14; // r11
  const idMD6Anim *v15; // r31
  idMD6PhaseTrack *p_phaseTrack; // r29
  int numFrames; // r28
  int v18; // r31
  unsigned __int16 *list; // r8
  int v20; // r9
  int v21; // r7
  unsigned int v22; // r11
  int v23; // r5
  int v24; // r10
  unsigned __int16 v25; // r25
  unsigned __int16 v26; // r10
  unsigned int v27; // r29
  unsigned int v28; // r4
  int v29; // r11
  signed int v30; // r31
  int v31; // r3
  int v32; // r5
  int v33; // r7
  unsigned int v34; // r8
  int v35; // r9
  int v36; // r11
  int v37; // r18
  int v38; // r11
  int v39; // r5
  unsigned int v40; // r4
  signed int v41; // r31
  int v42; // r3
  int v43; // r7
  unsigned int v44; // r8
  int v45; // r9
  int v46; // r11
  int v47; // r27
  unsigned __int8 v48[656]; // [sp+50h] [-290h] BYREF

  idMD6BlendBranch::Init(
    this,
    numDimensions_,
    userChannelIndices_,
    coordinates,
    animations,
    currentCoordinate_,
    weightGroup,
    flags);
  this->op = 9;
  p_phaseToFrameLookupData = &this->phaseToFrameLookupData;
  num = this->animationList.num;
  idList<short,5>::SetNum(
    this: (idList<short,5> *)&this->phaseToFrameLookupData,
    newNum: num << 8,
    initValue: (__int16 *)&idMD6FusionBranch::invalidFrame);
  v11 = 0;
  if ( num > 0 )
  {
    v12 = 0;
    v13 = 0;
    do
    {
      v14 = this->animationList.list[v13];
      if ( v14 != nullptr )
        v15 = *(const idMD6Anim **)&v14[4].type;
      else
        v15 = nullptr;
      if ( v15 != nullptr )
      {
        p_phaseTrack = &v15->phaseTrack;
        if ( !idMD6PhaseTrack::IsValid(this: &v15->phaseTrack, anim: v15) )
        {
          idLib::Error(fmt: "idMD6FusionBranch::Init - animation '%s' has no phase track", v15->name.str);
          JUMPOUT(0x8284277C);
        }
        memset(Dst: &v48[16], Val: 0, Size: 0x200u);
        numFrames = p_phaseTrack->data->numFrames;
        if ( p_phaseTrack->data->numFrames != 0 )
        {
          v18 = 0;
          do
          {
            idMD6PhaseTrack::GetPhase(this: p_phaseTrack, frame: v18, phase: v48);
            list = p_phaseToFrameLookupData->list;
            v20 = __ROL4__(v48[0], 1);
            v21 = v12 + v48[0];
            v22 = (unsigned __int16)(v18 + 1);
            v23 = *(unsigned __int16 *)&v48[v20 + 16];
            *(_WORD *)&v48[v20 + 16] = v23 + 1;
            __twllei(v23 + 1, 0);
            v24 = list[v21] * v23 + v18;
            v18 = v22;
            list[v21] = v24 / (v23 + 1);
            __twlgei((v23 + 1) & ~(__ROL4__(v24, 1) - 1), 0xFFFFFFFF);
          }
          while ( v22 < numFrames );
        }
        v25 = -1;
        v26 = -1;
        LOWORD(v27) = 0;
        v28 = 0;
        do
        {
          v29 = p_phaseToFrameLookupData->list[v28 + v12];
          if ( v29 != 0xFFFF )
          {
            if ( v26 == 0xFFFF )
            {
              v26 = v27;
              v25 = v27;
            }
            else
            {
              v30 = v28 - v26;
              if ( v30 > 1 )
              {
                v31 = p_phaseToFrameLookupData->list[v26 + v12];
                if ( (int)abs32(v29 - v31) > (int)abs32(numFrames + v29 - v31) )
                  v29 += numFrames;
                v32 = v29 - v31;
                v33 = 1;
                v34 = (unsigned __int16)(v26 + 1);
                if ( v34 < v28 )
                {
                  v35 = v29 - v31;
                  do
                  {
                    v36 = v35 / v30 + v31;
                    __twllei(v30, 0);
                    __twlgei(v30 & ~(__ROL4__(v35, 1) - 1), 0xFFFFFFFF);
                    for ( ; v36 >= numFrames; v36 -= numFrames )
                      ;
                    for ( ; v36 < 0; v36 += numFrames )
                      ;
                    v37 = (unsigned __int16)v33++ + v26 + v12;
                    v35 += v32;
                    v34 = (unsigned __int16)(v34 + 1);
                    p_phaseToFrameLookupData->list[v37] = v36;
                  }
                  while ( v34 < v28 );
                }
              }
              v26 = v27;
            }
          }
          v27 = (unsigned __int16)(v28 + 1);
          v28 = v27;
        }
        while ( v27 < 0x100 );
        v38 = p_phaseToFrameLookupData->list[v25 + v12];
        v39 = p_phaseToFrameLookupData->list[v26 + v12];
        v40 = (unsigned __int16)(v25 + 256);
        v41 = v40 - v26;
        if ( (int)abs32(v38 - v39) > (int)abs32(numFrames + v38 - v39) )
          v38 += numFrames;
        v42 = v38 - v39;
        v43 = 1;
        v44 = (unsigned __int16)(v26 + 1);
        if ( v44 < v40 )
        {
          v45 = v38 - v39;
          do
          {
            v46 = v45 / v41 + v39;
            __twllei(v41, 0);
            __twlgei(v41 & ~(__ROL4__(v45, 1) - 1), 0xFFFFFFFF);
            for ( ; v46 >= numFrames; v46 -= numFrames )
              ;
            for ( ; v46 < 0; v46 += numFrames )
              ;
            v47 = (unsigned __int16)v43++ + v26 + v12;
            v45 += v42;
            v44 = (unsigned __int16)(v44 + 1);
            p_phaseToFrameLookupData->list[v47] = v46;
          }
          while ( v44 < v40 );
        }
      }
      ++v11;
      ++v13;
      v12 += 256;
    }
    while ( v11 < num );
  }
}


// ========================================================================
// `dynamic initializer for 'anim_debugFilterLogic''
// EA  : 0x83344248
// RVA : 0x01344248
// PDB : w:\tech5\engine\models\skeletalanimation\md6animtree.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_debugFilterLogic__()
{
  idCVar::idCVar(
    this: &anim_debugFilterLogic,
    name: "anim_debugFilterLogic",
    value: "0",
    flags: 1,
    description: "This outputs debugging information on the selection logic for idMD6BestLeaf and idMD6TagFilter",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_debugFilterLogic__);
}

