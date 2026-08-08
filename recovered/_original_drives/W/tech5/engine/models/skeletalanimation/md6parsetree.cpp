
// ========================================================================
// GetFrame
// EA  : 0x8284F8E8
// RVA : 0x0084F8E8
// PDB : w:\tech5\engine\models\skeletalanimation\md6parsetree.cpp
// ========================================================================

void __fastcall GetFrame(
        idMD6LeafPlay *leaf,
        int timeMSec,
        __int16 *frame,
        float *fraction,
        unsigned int *loops,
        const int ticksPerSec)
{
  __int64 v11; // r29
  double v12; // fp31
  int numFrames; // r27
  idMD6AnimData *animData; // r11
  int v15; // r8
  int v16; // r7
  int v17; // r6
  int v18; // r5
  int FrameRate; // r3
  _BYTE v20[12]; // r11
  int FrameTime; // r3
  unsigned int v22; // r8

  *loops = 0;
  HIDWORD(v11) = ticksPerSec;
  v12 = 0.0;
  numFrames = 0;
  animData = leaf->anim->animData;
  if ( animData != nullptr )
    numFrames = animData->numFrames;
  FrameRate = idMD6Leaf::GetFrameRate(this: leaf);
  *(_DWORD *)&v20[8] = leaf->type;
  LODWORD(v11) = FrameRate;
  if ( *(_DWORD *)&v20[8] == 1 )
  {
    v12 = *(float *)&leaf[2].anim;
  }
  else if ( *(_DWORD *)&v20[8] == 2 )
  {
    FrameTime = idMD6LeafPlay::GetFrameTime(
                  this: leaf,
                  gameTime: timeMSec,
                  a3: v18,
                  a4: v17,
                  a5: v16,
                  a6: v15,
                  a7: *(__int64 *)v20);
    *(_DWORD *)v20 = (unsigned int)(FrameTime * v11) / HIDWORD(v11);
    __twllei(HIDWORD(v11), 0);
    v22 = *(_DWORD *)v20 / (unsigned int)(numFrames - 1);
    __twllei(numFrames - 1, 0);
    *loops = v22;
    if ( v22 == 0 || leaf->wrapMode != 0 )
    {
      *(_QWORD *)v20 = v11;
      v12 = (float)((float)((float)((float)1.0 / (float)__SPAIR64__(0x82000000, HIDWORD(v11)))
                          * (float)__SPAIR64__(v11, FrameTime))
                  * (float)v11);
    }
    else
    {
      *(_DWORD *)&v20[4] = numFrames - 1;
      v12 = (float)*(__int64 *)v20;
    }
  }
  *(_DWORD *)&v20[4] = leaf->wrapMode;
  *(_WORD *)&v20[10] = 0;
  if ( leaf->wrapMode != 0 )
  {
    if ( *(_DWORD *)&v20[4] == 1 )
    {
      *(_DWORD *)&v20[8] = (int)v12;
      *(_DWORD *)&v20[4] = (int)v12;
      *fraction = (float)v12 - (float)*(__int64 *)v20;
      if ( numFrames > 1 )
      {
        __twllei(numFrames - 1, 0);
        __twlgei((numFrames - 1) & ~(__ROL4__(*(_DWORD *)&v20[8], 1) - 1), 0xFFFFFFFF);
        *frame = *(_DWORD *)&v20[8] % (numFrames - 1);
        return;
      }
    }
  }
  else
  {
    if ( v12 < 0.0 )
    {
      *fraction = 0.0;
      *frame = 0;
      return;
    }
    *(_DWORD *)&v20[8] = numFrames;
    if ( v12 >= (float)*(__int64 *)&v20[4] )
    {
      *fraction = 0.0;
      *frame = numFrames - 1;
      return;
    }
    *(_DWORD *)&v20[8] = (int)v12;
    *(_DWORD *)&v20[4] = (int)v12;
    *fraction = (float)v12 - (float)*(__int64 *)v20;
  }
  *frame = *(_WORD *)&v20[10];
}


// ========================================================================
// SetupCommandBlendInfo
// EA  : 0x8284FB28
// RVA : 0x0084FB28
// PDB : w:\tech5\engine\models\skeletalanimation\md6parsetree.cpp
// ========================================================================

md6AnimCommand_t *__fastcall SetupCommandBlendInfo(md6AnimCommand_t *cmd, idMD6Branch *branch)
{
  double currentAlpha; // fp0
  idMD6Branch::blendType_t blendType; // r11
  double v6; // fp31
  double v7; // fp0

  memset(Dst: cmd, Val: 0, Size: sizeof(md6AnimCommand_t));
  cmd->op = OP_POP_AND_BLEND;
  cmd->blendInfo.op = branch->op;
  cmd->blendInfo.filterGroup = branch->filterGroup;
  cmd->blendInfo.originBlend = branch->originBlend;
  currentAlpha = branch->currentAlpha;
  blendType = branch->blendType;
  if ( (unsigned int)blendType > BLEND_EASEIN_EASEOUT )
  {
    v6 = branch->currentAlpha;
    idLib::Warning(fmt: "SetupCommandBlendInfo - Invalid blend type");
    goto LABEL_14;
  }
  if ( blendType == BLEND_EASEIN )
  {
    if ( currentAlpha > branch->targetAlpha )
    {
LABEL_9:
      v6 = (float)((float)(branch->currentAlpha * (float)2.0) - (float)(branch->currentAlpha * branch->currentAlpha));
      goto LABEL_14;
    }
LABEL_7:
    v6 = (float)(branch->currentAlpha * branch->currentAlpha);
    goto LABEL_14;
  }
  if ( blendType == BLEND_EASEOUT )
  {
    if ( currentAlpha <= branch->targetAlpha )
      goto LABEL_9;
    goto LABEL_7;
  }
  if ( blendType != BLEND_LINEAR )
  {
    v7 = (float)(branch->currentAlpha * (float)2.0);
    if ( v7 >= 1.0 )
      v6 = (float)((float)((float)((float)((float)((float)v7 - (float)1.0) * (float)2.0)
                                 - (float)((float)((float)v7 - (float)1.0) * (float)((float)v7 - (float)1.0)))
                         + (float)1.0)
                 * 0.5);
    else
      v6 = (float)((float)((float)v7 * (float)v7) * 0.5);
  }
  else
  {
    v6 = branch->currentAlpha;
  }
LABEL_14:
  cmd->blendInfo.currentAlpha = v6;
  return cmd + 1;
}


// ========================================================================
// SetupCommandFrameInfo
// EA  : 0x8284FC80
// RVA : 0x0084FC80
// PDB : w:\tech5\engine\models\skeletalanimation\md6parsetree.cpp
// ========================================================================

md6AnimCommand_t *__fastcall SetupCommandFrameInfo(
        const idMD6Model *model,
        md6AnimCommand_t *cmd,
        idMD6LeafPlay *leaf,
        int lastTimeMSec,
        int timeMSec,
        idBounds *frameBounds,
        idBounds *translatedBounds,
        idBounds *normalizedBounds,
        md6OriginDelta_t *originDelta,
        const unsigned __int16 animatorFlags,
        const int ticksPerSec,
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
        char a28,
        int a29,
        int a30)
{
  __int16 v38; // r9
  unsigned __int16 flags; // r11
  const idMD6Anim *anim; // r3
  const idMD6AnimData *animData; // r30
  __int16 frame; // r7
  double frameFraction; // fp0
  char *v45; // r25
  unsigned __int16 nextSize; // r10
  char *v47; // r24
  __int16 *p_originFrame; // r28
  char *v49; // r11
  int v50; // r3
  int v51; // r11
  char *v52; // r27
  __int16 v53; // r9
  unsigned __int16 v54; // r11
  float *p_originFrameFraction; // r6
  __int16 *v56; // r5
  __int16 v57; // r10
  int v58; // r9
  __int16 v59; // r8
  char *v60; // r11
  int v61; // r10
  int v62; // r5
  idBounds *p_normalizedBounds; // r4
  char v64; // r11
  int v65; // r11
  __int16 v66; // [sp+50h] [-C0h] BYREF
  unsigned int v67; // [sp+54h] [-BCh] BYREF
  unsigned int v68; // [sp+58h] [-B8h] BYREF
  unsigned int v69; // [sp+5Ch] [-B4h] BYREF
  float v70; // [sp+60h] [-B0h] BYREF
  unsigned int v71[3]; // [sp+64h] [-ACh] BYREF
  idBounds v72[6]; // [sp+70h] [-A0h] BYREF

  if ( cmd == nullptr || model == nullptr || leaf == nullptr )
    return nullptr;
  memset(Dst: cmd, Val: 0, Size: sizeof(md6AnimCommand_t));
  cmd->op = OP_DECODE_AND_PUSH;
  cmd->frameInfo.weightGroup = leaf->weightGroup;
  if ( leaf->anim != nullptr )
  {
    GetFrame(leaf, timeMSec, frame: &v66, fraction: &v70, loops: &v68, ticksPerSec: a30);
    cmd->animName = leaf->anim->name.str;
    if ( leaf->type == 2 && leaf->startTime < timeMSec )
    {
      GetFrame(
        leaf,
        timeMSec: lastTimeMSec,
        frame: (__int16 *)&v67,
        fraction: (float *)v71,
        loops: &v69,
        ticksPerSec: a30);
      if ( v68 > v69 )
        cmd->frameInfo.flags |= 4u;
    }
    v38 = v66;
    flags = cmd->frameInfo.flags;
    cmd->frameInfo.frameFraction = v70;
    cmd->frameInfo.frame = v38;
    cmd->frameInfo.flags = ((a28 & 1) == 0 ? 0 : 8) | flags;
    anim = leaf->anim;
    animData = anim->animData;
    if ( !idMD6Anim::AnimIsOkForModel(this: anim, model) )
    {
      idLib::Warning(fmt: "Skeleton mismatch: model '%s', anim '%s'", model->name.str, leaf->anim->name.str);
      return nullptr;
    }
    frame = cmd->frameInfo.frame;
    frameFraction = cmd->frameInfo.frameFraction;
    v45 = (char *)animData + animData->frameSetTblOffset;
    nextSize = animData->nextSize;
    v47 = (char *)animData + animData->frameSetOffsetTblOffset;
    p_originFrame = &cmd->frameInfo.originFrame;
    v49 = &v47[__ROL4__((unsigned __int8)v45[frame], 2)];
    v50 = *((_DWORD *)v49 + 1);
    v51 = *(_DWORD *)v49;
    cmd->frameInfo.animData = animData;
    v51 *= 16;
    cmd->frameInfo.animInfoSize = animData->size;
    v52 = (char *)animData + v51;
    cmd->frameInfo.frameSetData = (const frameSetData_t *)((char *)animData + v51);
    cmd->frameInfo.frameSetSize = 16 * v50 + nextSize - v51;
    v53 = *(_WORD *)((char *)animData->startDelta + v51 + 2);
    cmd->frameInfo.originFrameFraction = frameFraction;
    cmd->frameInfo.originFrameSetData = nullptr;
    cmd->frameInfo.originFrame = frame;
    cmd->frameInfo.frameSetFrame = frame - v53;
    cmd->frameInfo.originFrameSetFrame = frame - v53;
    if ( (a28 & 1) == 0 || (animData->flags & 0x1E) == 0 )
      goto LABEL_19;
    v54 = cmd->frameInfo.flags | 0x20;
    cmd->frameInfo.flags = v54;
    p_originFrameFraction = &cmd->frameInfo.originFrameFraction;
    v56 = &cmd->frameInfo.originFrame;
    if ( (a28 & 2) != 0 )
    {
      cmd->frameInfo.flags = v54 | 0x40;
      GetFrame(
        leaf,
        timeMSec: 2 * timeMSec - lastTimeMSec,
        frame: v56,
        fraction: p_originFrameFraction,
        loops: v71,
        ticksPerSec: a30);
    }
    else
    {
      GetFrame(leaf, timeMSec: lastTimeMSec, frame: v56, fraction: p_originFrameFraction, loops: &v67, ticksPerSec: a30);
      if ( v67 != 0
        || *p_originFrame != cmd->frameInfo.frame
        || cmd->frameInfo.frame != 0
        || (v64 = 1, cmd->frameInfo.frameFraction != 0.0) )
      {
        v64 = 0;
      }
      if ( v64 != 0 )
      {
        cmd->frameInfo.flags |= 0x40u;
        GetFrame(
          leaf,
          timeMSec: 2 * timeMSec - lastTimeMSec,
          frame: &cmd->frameInfo.originFrame,
          fraction: &cmd->frameInfo.originFrameFraction,
          loops: &v67,
          ticksPerSec: a30);
LABEL_19:
        if ( (animData->flags & 0x21) == 0 )
        {
          idBoundsShort::ToBounds(this: (idBoundsShort *)v72, result: (idBounds *)&leaf->anim->translatedBounds);
          idBounds::AddBounds(this: translatedBounds, a: v72);
          idBoundsShort::ToBounds(this: (idBoundsShort *)v72, result: (idBounds *)&leaf->anim->normalizedBounds);
          idBounds::AddBounds(this: normalizedBounds, a: v72);
          if ( (a28 & 1) != 0 && (animData->flags & 0xE) != 0 )
            p_normalizedBounds = (idBounds *)&leaf->anim->normalizedBounds;
          else
            p_normalizedBounds = (idBounds *)&leaf->anim->translatedBounds;
          idBoundsShort::ToBounds(this: (idBoundsShort *)v72, result: p_normalizedBounds);
          idBounds::AddBounds(this: frameBounds, a: v72);
        }
        goto LABEL_32;
      }
    }
    v57 = *p_originFrame;
    v58 = *((unsigned __int16 *)v52 + 17);
    if ( *p_originFrame < v58 || v57 >= *((unsigned __int16 *)v52 + 18) + v58 )
    {
      v59 = *p_originFrame;
      v60 = &v47[__ROL4__((unsigned __int8)v45[v57], 2)];
      v61 = 16 * *(_DWORD *)v60;
      v62 = 16 * *((_DWORD *)v60 + 1) + animData->nextSize;
      cmd->frameInfo.originFrameSetData = (const frameSetData_t *)((char *)animData + v61);
      cmd->frameInfo.originFrameSetSize = v62 - v61;
      cmd->frameInfo.originFrameSetFrame = v59 - LOWORD(animData->startDelta[v61 / 4u]);
    }
    goto LABEL_19;
  }
LABEL_32:
  if ( leaf->type == 1 )
  {
    v65 = *(_DWORD *)&leaf->syncGroup;
    cmd->frameInfo.animModsSize = (_WORD)v65 << 6;
    if ( ((v65 << 6) & 0xFFC0) != 0 )
      cmd->frameInfo.animMods = *((const idMD6Blend::jointMod_t **)&leaf->rateScale + 4 * (leaf->startTime & 1));
    cmd->frameInfo.flags |= *(_WORD *)&leaf[2].type;
    if ( (*(_WORD *)&leaf[2].type & 0x10) != 0 )
    {
      frameBounds->b[0].x = *(float *)&leaf[2].weightGroup;
      frameBounds->b[0].y = *(float *)&leaf[2].startTime;
      frameBounds->b[0].z = leaf[2].rateScale;
      frameBounds->b[1].x = *(float *)&leaf[2].syncGroup;
      frameBounds->b[1].y = *(float *)&leaf[3].type;
      frameBounds->b[1].z = *(float *)&leaf[3].anim;
      translatedBounds->b[0].x = *(float *)&leaf[2].weightGroup;
      translatedBounds->b[0].y = *(float *)&leaf[2].startTime;
      translatedBounds->b[0].z = leaf[2].rateScale;
      translatedBounds->b[1].x = *(float *)&leaf[2].syncGroup;
      translatedBounds->b[1].y = *(float *)&leaf[3].type;
      translatedBounds->b[1].z = *(float *)&leaf[3].anim;
      normalizedBounds->b[0].x = *(float *)&leaf[2].weightGroup;
      normalizedBounds->b[0].y = *(float *)&leaf[2].startTime;
      normalizedBounds->b[0].z = leaf[2].rateScale;
      normalizedBounds->b[1].x = *(float *)&leaf[2].syncGroup;
      normalizedBounds->b[1].y = *(float *)&leaf[3].type;
      normalizedBounds->b[1].z = *(float *)&leaf[3].anim;
    }
    else
    {
      idBounds::AddBounds(this: frameBounds, a: (const idBounds *)&leaf[2].weightGroup);
      idBounds::AddBounds(this: translatedBounds, a: (const idBounds *)&leaf[2].weightGroup);
      idBounds::AddBounds(this: normalizedBounds, a: (const idBounds *)&leaf[2].weightGroup);
    }
    if ( (*(_WORD *)&leaf[2].type & 0x80) != 0 )
      cmd->op = OP_DECODE_FACECOMPOSITE_AND_BLEND;
  }
  return cmd + 1;
}


// ========================================================================
// ParseTree_r
// EA  : 0x82850190
// RVA : 0x00850190
// PDB : w:\tech5\engine\models\skeletalanimation\md6parsetree.cpp
// ========================================================================

md6AnimCommand_t *__fastcall ParseTree_r(
        const idMD6Model *model,
        int lastTimeMSec,
        int timeMSec,
        unsigned int ticksPerSec,
        idMD6FusionBranch *branch,
        md6AnimCommand_t *cmd,
        __int64 translatedBounds,
        idBounds *normalizedBounds,
        md6OriginDelta_t *originDelta,
        const unsigned __int16 animatorFlags,
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
        idBounds *a27,
        int a28,
        int a29,
        int a30,
        char a31)
{
  idBounds *v37; // r24
  idBounds *v38; // r23
  __int64 v39; // r8
  int leftTimeOverride; // r27
  int rightTimeOverride; // r21
  int type; // r11
  md6AnimCommand_t *v43; // r4
  int op; // r11
  idMD6Node *left; // r5
  unsigned int v46; // r11
  __int64 v47; // r10
  int v48; // r11
  char v49; // r11
  bool v50; // zf
  md6AnimCommand_t *v51; // r3
  md6AnimCommand_t *v52; // r27
  md6AnimCommand_t *v53; // r4
  int v54; // r11
  idMD6Node *right; // r5
  unsigned int v56; // r11
  __int64 v57; // r10
  int v58; // r11
  char v59; // r11
  md6AnimCommand_t *v60; // r3
  md6AnimCommand_t *result; // r3
  md6OriginDelta_t *v62; // [sp+8h] [-D8h]
  md6OriginDelta_t *v63; // [sp+8h] [-D8h]
  md6OriginDelta_t *v64; // [sp+Ch] [-D4h]
  md6OriginDelta_t *v65; // [sp+Ch] [-D4h]
  int v66; // [sp+10h] [-D0h]
  int v67; // [sp+10h] [-D0h]
  int v68; // [sp+14h] [-CCh]
  int v69; // [sp+18h] [-C8h]
  int v70; // [sp+1Ch] [-C4h]
  int v71; // [sp+20h] [-C0h]
  int v72; // [sp+24h] [-BCh]
  int v73; // [sp+28h] [-B8h]
  int v74; // [sp+2Ch] [-B4h]
  int v75; // [sp+30h] [-B0h]
  int v76; // [sp+34h] [-ACh]
  int v77; // [sp+38h] [-A8h]
  int v78; // [sp+3Ch] [-A4h]
  int v79; // [sp+40h] [-A0h]
  int v80; // [sp+44h] [-9Ch]
  int v81; // [sp+48h] [-98h]
  int v82; // [sp+4Ch] [-94h]
  int v83; // [sp+50h] [-90h]
  int v84; // [sp+58h] [-88h]

  v37 = (idBounds *)HIDWORD(translatedBounds);
  v38 = (idBounds *)translatedBounds;
  idMD6Branch::UpdateCurrentAlpha(
    this: branch,
    timeMSec,
    lastTimeMSec,
    ticksPerSec,
    a5: (int)branch,
    a6: translatedBounds);
  leftTimeOverride = branch->leftTimeOverride;
  if ( leftTimeOverride < 0 )
    leftTimeOverride = timeMSec;
  rightTimeOverride = branch->rightTimeOverride;
  if ( rightTimeOverride < 0 )
    rightTimeOverride = timeMSec;
  type = branch->type;
  switch ( type )
  {
    case 5:
      HIDWORD(v39) = model->skeleton;
      idMD6FusionBranch::Update(this: branch, forceUpdate: false, gameTime: timeMSec, ticksPerSec, skeleton: v39);
      break;
    case 3:
      idMD6BlendBranch::Update(this: branch, forceUpdate: false, isSorted: true);
      break;
    case 4:
      idMD6BlendAdditiveBranch::Update(this: (idMD6BlendAdditiveBranch *)branch, forceUpdate: false);
      break;
    default:
      break;
  }
  v43 = nullptr;
  if ( branch->filterGroup != 0
    || ((op = branch->op) == 1 || op == 2 || op == 7 || op == 9) && branch->currentAlpha != 1.0
    || op == 3 && branch->currentAlpha != 0.0
    || op == 5 && branch->currentAlpha != 0.0
    || op == 4
    || op == 8
    || op == 6 )
  {
    v43 = cmd;
  }
  left = branch->left;
  if ( left->type == 6 )
  {
    v46 = *(_DWORD *)&left[8].type;
    if ( v46 != 0 )
    {
      LODWORD(v47) = *(unsigned __int16 *)&left[88].type;
      HIDWORD(v47) = v46 >> 31;
      left = *(idMD6Node **)(((4 * (((v47 - (unsigned __int64)v46) >> 32) & (unsigned __int16)v47)) & 0x3FFFC)
                           + *(_DWORD *)&left[4].type);
    }
    else
    {
      left = nullptr;
    }
  }
  v48 = left->type;
  if ( v48 == 1 || (v50 = v48 != 2, v49 = 0, !v50) )
    v49 = 1;
  if ( v49 != 0 )
    v51 = SetupCommandFrameInfo(
            model,
            cmd: v43,
            leaf: (idMD6LeafPlay *)left,
            lastTimeMSec,
            timeMSec: leftTimeOverride,
            frameBounds: v37,
            translatedBounds: v38,
            normalizedBounds: a27,
            originDelta: v62,
            animatorFlags: (const unsigned __int16)v64,
            ticksPerSec: v66,
            a12: v68,
            a13: v69,
            a14: v70,
            a15: v71,
            a16: v72,
            a17: v73,
            a18: v74,
            a19: v75,
            a20: v76,
            a21: v77,
            a22: v78,
            a23: v79,
            a24: v80,
            a25: v81,
            a26: v82,
            a27: v83,
            a28: a31,
            a29: v84,
            a30: ticksPerSec);
  else
    v51 = ParseTree_r(
            model,
            lastTimeMSec,
            timeMSec: leftTimeOverride,
            ticksPerSec,
            branch: (idMD6Branch *)left,
            cmd: v43,
            frameBounds: v37,
            translatedBounds: v38,
            normalizedBounds: (idBounds *)v62,
            originDelta: v64,
            animatorFlags: v66);
  v52 = v51;
  if ( v51 != nullptr )
    cmd = v51;
  v53 = nullptr;
  if ( branch->filterGroup != 0
    || ((v54 = branch->op) == 1 || v54 == 2 || v54 == 7 || v54 == 9) && branch->currentAlpha != 0.0
    || v54 == 4 && branch->currentAlpha != 0.0
    || v54 == 6 && branch->currentAlpha != 0.0
    || v54 == 8 && branch->currentAlpha != 0.0
    || v54 == 3
    || v54 == 5 )
  {
    v53 = cmd;
  }
  right = branch->right;
  if ( right->type == 6 )
  {
    v56 = *(_DWORD *)&right[8].type;
    if ( v56 != 0 )
    {
      LODWORD(v57) = *(unsigned __int16 *)&right[88].type;
      HIDWORD(v57) = v56 >> 31;
      right = *(idMD6Node **)(((4 * (((v57 - (unsigned __int64)v56) >> 32) & (unsigned __int16)v57)) & 0x3FFFC)
                            + *(_DWORD *)&right[4].type);
    }
    else
    {
      right = nullptr;
    }
  }
  v58 = right->type;
  if ( v58 == 1 || (v50 = v58 != 2, v59 = 0, !v50) )
    v59 = 1;
  if ( v59 != 0 )
    v60 = SetupCommandFrameInfo(
            model,
            cmd: v53,
            leaf: (idMD6LeafPlay *)right,
            lastTimeMSec,
            timeMSec: rightTimeOverride,
            frameBounds: v37,
            translatedBounds: v38,
            normalizedBounds: a27,
            originDelta: v63,
            animatorFlags: (const unsigned __int16)v65,
            ticksPerSec: v67,
            a12: v68,
            a13: v69,
            a14: v70,
            a15: v71,
            a16: v72,
            a17: v73,
            a18: v74,
            a19: v75,
            a20: v76,
            a21: v77,
            a22: v78,
            a23: v79,
            a24: v80,
            a25: v81,
            a26: v82,
            a27: v83,
            a28: a31,
            a29: v84,
            a30: ticksPerSec);
  else
    v60 = ParseTree_r(
            model,
            lastTimeMSec,
            timeMSec: rightTimeOverride,
            ticksPerSec,
            branch: (idMD6Branch *)right,
            cmd: v53,
            frameBounds: v37,
            translatedBounds: v38,
            normalizedBounds: (idBounds *)v63,
            originDelta: v65,
            animatorFlags: v67);
  if ( v60 != nullptr )
    cmd = v60;
  if ( v52 == nullptr || v52->op == OP_DECODE_FACECOMPOSITE_AND_BLEND )
    return cmd;
  v50 = v60 == nullptr;
  result = cmd;
  if ( !v50 )
    return SetupCommandBlendInfo(cmd, branch);
  return result;
}


// ========================================================================
// ?ParseTree@@YAHPBVidMD6Model@@HHHPAVidMD6Node@@PAUmd6AnimCommand_t@@HAAVidBounds@@33PAUmd6OriginDelta_t@@G@Z
// EA  : 0x82850568
// RVA : 0x00850568
// PDB : w:\tech5\engine\models\skeletalanimation\md6parsetree.cpp
// ========================================================================

int __fastcall ParseTree(
        const idMD6Model *model,
        int lastTimeMSec,
        int timeMSec,
        unsigned int ticksPerSec,
        idMD6LeafPlay *tree,
        md6AnimCommand_t *cmds,
        const int maxCmds,
        idBounds *frameBounds,
        idBounds *translatedBounds,
        idBounds *normalizedBounds,
        md6OriginDelta_t *originDelta,
        const unsigned __int16 animatorFlags,
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
        idBounds *a28,
        int a29,
        idBounds *a30,
        int a31,
        int a32,
        int a33,
        char a34)
{
  int v41; // r23
  int type; // r10
  char v43; // r11
  unsigned int v44; // r11
  idMD6LeafPlay *v45; // r5
  __int64 v46; // r10
  int v47; // r10
  int v48; // r8
  md6AnimCommand_t *v49; // r9
  int i; // ctr
  md6OriginDelta_t *v52; // [sp+8h] [-B8h]
  md6OriginDelta_t *v53; // [sp+Ch] [-B4h]
  int v54; // [sp+10h] [-B0h]
  int v55; // [sp+14h] [-ACh]
  int v56; // [sp+18h] [-A8h]
  int v57; // [sp+1Ch] [-A4h]
  int v58; // [sp+20h] [-A0h]
  int v59; // [sp+24h] [-9Ch]
  int v60; // [sp+28h] [-98h]
  int v61; // [sp+2Ch] [-94h]
  int v62; // [sp+30h] [-90h]
  int v63; // [sp+34h] [-8Ch]
  int v64; // [sp+38h] [-88h]
  int v65; // [sp+3Ch] [-84h]
  int v66; // [sp+40h] [-80h]
  int v67; // [sp+44h] [-7Ch]
  int v68; // [sp+48h] [-78h]
  int v69; // [sp+4Ch] [-74h]
  int v70; // [sp+50h] [-70h]
  int v71; // [sp+58h] [-68h]
  int v72; // [sp+60h] [-60h]

  frameBounds->b[0].z = 1.0e30;
  frameBounds->b[0].y = 1.0e30;
  v41 = 0;
  frameBounds->b[0].x = 1.0e30;
  frameBounds->b[1].z = -1.0e30;
  frameBounds->b[1].y = -1.0e30;
  frameBounds->b[1].x = -1.0e30;
  if ( a32 != 0 )
    *(_BYTE *)(a32 + 97) = 0;
  if ( tree != nullptr && (unsigned __int8)idMD6Node::IsValid(this: tree) != 0 )
  {
    type = tree->type;
    if ( type == 1 || (v43 = 0, type == 2) )
      v43 = 1;
    if ( v43 != 0 )
    {
      if ( SetupCommandFrameInfo(
             model,
             cmd: cmds,
             leaf: tree,
             lastTimeMSec,
             timeMSec,
             frameBounds,
             translatedBounds: a28,
             normalizedBounds: a30,
             originDelta: v52,
             animatorFlags: (const unsigned __int16)v53,
             ticksPerSec: v54,
             a12: v55,
             a13: v56,
             a14: v57,
             a15: v58,
             a16: v59,
             a17: v60,
             a18: v61,
             a19: v62,
             a20: v63,
             a21: v64,
             a22: v65,
             a23: v66,
             a24: v67,
             a25: v68,
             a26: v69,
             a27: v70,
             a28: a34,
             a29: v71,
             a30: ticksPerSec) != nullptr )
        v41 = 1;
    }
    else if ( type == 6 )
    {
      v44 = *(_DWORD *)&tree->weightGroup;
      if ( v44 != 0 )
      {
        LODWORD(v46) = HIWORD(tree[3].rateScale);
        HIDWORD(v46) = v44 >> 31;
        v45 = *(idMD6LeafPlay **)((char *)&tree->anim->__vftable
                                + ((4 * (((v46 - (unsigned __int64)v44) >> 32) & (unsigned __int16)v46)) & 0x3FFFC));
      }
      else
      {
        v45 = nullptr;
      }
      if ( SetupCommandFrameInfo(
             model,
             cmd: cmds,
             leaf: v45,
             lastTimeMSec,
             timeMSec,
             frameBounds,
             translatedBounds: a28,
             normalizedBounds: a30,
             originDelta: v52,
             animatorFlags: (const unsigned __int16)v53,
             ticksPerSec: v54,
             a12: v55,
             a13: v56,
             a14: v57,
             a15: v58,
             a16: v59,
             a17: v60,
             a18: v61,
             a19: v62,
             a20: v63,
             a21: v64,
             a22: v65,
             a23: v66,
             a24: v67,
             a25: v68,
             a26: v69,
             a27: v70,
             a28: a34,
             a29: v71,
             a30: ticksPerSec) != nullptr )
        v41 = 1;
    }
    else
    {
      v41 = ParseTree_r(
              model,
              lastTimeMSec,
              timeMSec,
              ticksPerSec,
              branch: (idMD6FusionBranch *)tree,
              cmd: cmds,
              translatedBounds: __SPAIR64__((unsigned int)frameBounds, (unsigned int)a28),
              normalizedBounds: (idBounds *)v52,
              originDelta: v53,
              animatorFlags: v54,
              a11: v55,
              a12: v56,
              a13: v57,
              a14: v58,
              a15: v59,
              a16: v60,
              a17: v61,
              a18: v62,
              a19: v63,
              a20: v64,
              a21: v65,
              a22: v66,
              a23: v67,
              a24: v68,
              a25: v69,
              a26: v70,
              a27: a30,
              a28: v71,
              a29: a32,
              a30: v72,
              a31: a34)
          - cmds;
    }
  }
  else
  {
    v41 = 1;
    memset(Dst: cmds, Val: 0, Size: sizeof(md6AnimCommand_t));
    cmds->op = OP_DECODE_AND_PUSH;
  }
  v47 = 0;
  v48 = 0;
  if ( v41 > 0 )
  {
    v49 = cmds;
    for ( i = v41; i != 0; --i )
    {
      if ( v49->op == OP_DECODE_AND_PUSH )
      {
        ++v47;
      }
      else if ( v49->op == OP_POP_AND_BLEND )
      {
        --v47;
      }
      if ( v47 > v48 )
        v48 = v47;
      ++v49;
    }
  }
  memset(Dst: &cmds[v41], Val: 0, Size: sizeof(md6AnimCommand_t));
  cmds[v41].op = OP_END;
  return v41 + 1;
}

