
// ========================================================================
// ?GetDest@expOp_t@@QBAPBVidDeclRenderParm@@XZ
// EA  : 0x828D7430
// RVA : 0x008D7430
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

const idDeclRenderParm *__fastcall expOp_t::GetDest(expOp_t *this)
{
  int parmIndexDest; // r11

  parmIndexDest = this->parmIndexDest;
  if ( parmIndexDest >= 2047 )
    return nullptr;
  else
    return renderThreadParmState->parmDecl[parmIndexDest];
}


// ========================================================================
// ?GetA@expOp_t@@QBAPBVidDeclRenderParm@@XZ
// EA  : 0x828D7460
// RVA : 0x008D7460
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

const idDeclRenderParm *__fastcall expOp_t::GetA(expOp_t *this)
{
  int parmIndexA; // r11

  parmIndexA = this->parmIndexA;
  if ( parmIndexA >= 2047 )
    return nullptr;
  else
    return renderThreadParmState->parmDecl[parmIndexA];
}


// ========================================================================
// ?GetB@expOp_t@@QBAPBVidDeclRenderParm@@XZ
// EA  : 0x828D7490
// RVA : 0x008D7490
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

const idDeclRenderParm *__fastcall expOp_t::GetB(expOp_t *this)
{
  int parmIndexB; // r11

  parmIndexB = this->parmIndexB;
  if ( parmIndexB >= 2047 )
    return nullptr;
  else
    return renderThreadParmState->parmDecl[parmIndexB];
}


// ========================================================================
// ??0idParmState@@QAA@XZ
// EA  : 0x828D74C0
// RVA : 0x008D74C0
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

idParmState *__fastcall idParmState::idParmState(idParmState *this)
{
  int *p_parmIndexPrimeLightColor; // r10
  int i; // ctr

  this->parmIndexModelMatrixW = 2047;
  this->parmIndexModelMatrixZ = 2047;
  this->parmIndexModelMatrixX = 2047;
  this->numGlobalTables = 0;
  this->parmIndexModelMatrixY = 2047;
  this->parmIndexInverseModelMatrixY = 2047;
  this->parmIndexInverseModelMatrixX = 2047;
  this->parmIndexPositionToFeedback = 2047;
  this->parmIndexInverseModelMatrixZ = 2047;
  this->parmIndexInverseModelMatrixW = 2047;
  this->parmIndexMVPMatrixX = 2047;
  this->parmIndexMVPMatrixY = 2047;
  this->parmIndexMVPMatrixZ = 2047;
  this->parmIndexMVPMatrixW = 2047;
  this->parmIndexPrimeLightDir = 2047;
  this->parmIndexPrimeLightColor = 2047;
  this->parmIndexRenderPositionToViewTexture = 2047;
  this->parmIndexLightingModel = 2047;
  this->parmIndexPositionToViewTexture = 2047;
  this->parmIndexVertexXYZScale = 2047;
  this->parmIndexVertexStScaleBias = 2047;
  this->parmIndexVertexXYZBias = 2047;
  this->parmIndexIf = 2047;
  this->parmIndexPolygonOffset = 2047;
  p_parmIndexPrimeLightColor = &this->parmIndexPrimeLightColor;
  this->parmIndexVertexMorphScale = 2047;
  for ( i = 6; i != 0; --i )
    *++p_parmIndexPrimeLightColor = 2047;
  memset(Dst: this->parmDecl, Val: 0, Size: sizeof(this->parmDecl));
  memset(Dst: this->parmUsageMask, Val: 0, Size: sizeof(this->parmUsageMask));
  memset(Dst: this->globalTables, Val: 0, Size: sizeof(this->globalTables));
  memset(Dst: this->globalLookupTables, Val: 0, Size: sizeof(this->globalLookupTables));
  return this;
}


// ========================================================================
// ?CopyParmUnaligned@idParmState@@CAXPAXPBX@Z
// EA  : 0x828D76A0
// RVA : 0x008D76A0
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

void __fastcall idParmState::CopyParmUnaligned(void *dst, const void *src)
{
  _R11 = 16;
  __asm
  {
    lvlx128   v63, r0, r4
    lvrx128   v62, r11, r4
    vor128    v61, v95, v62
    stvlx128  v61, r0, r3
    stvrx128  v61, r3, r11
  }
}


// ========================================================================
// ?VirtualRollbackParmBlock@idParmState@@QAAXABVidParmBlock@@0@Z
// EA  : 0x828D76C0
// RVA : 0x008D76C0
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

void __fastcall idParmState::VirtualRollbackParmBlock(
        idParmState *this,
        const idParmBlock *localParmBlock,
        const idParmBlock *parmBlock)
{
  unsigned int virtualParmBlockLevel; // r11
  int v4; // r4
  const char *v5; // r5
  unsigned int v6; // r11

  virtualParmBlockLevel = this->parmStack.virtualParmBlockLevel;
  if ( virtualParmBlockLevel != 0 )
  {
    v6 = virtualParmBlockLevel - 1;
    this->parmStack.virtualParmBlockLevel = v6;
    this->parmStack.virtualParmBlockStackMask |= 1 << v6;
    if ( parmBlock == this->parmStack.parmBlockStack[v6].parmBlock )
      return;
    v4 = 1326;
    v5 = "!\"VirtualRollbackParmBlock called with the wrong parmBlock\"";
  }
  else
  {
    v4 = 1320;
    v5 = "!\"VirtualRollbackParmBlock called at level zero\"";
  }
  if ( AssertFailed(
         file: "w:\\tech5\\engine\\renderer\\jobs\\render\\ParmState.cpp",
         line: v4,
         expression: v5,
         inlineBreak: true) )
  {
    __trap();
  }
}


// ========================================================================
// ?ApplyOp@idParmState@@CAXABUexpOp_t@@ABTparmValue_t@@11AAT3@@Z
// EA  : 0x828D7770
// RVA : 0x008D7770
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

void __fastcall idParmState::ApplyOp(
        const expOp_t *op,
        const parmValue_t *constant,
        const parmValue_t *parmA,
        const parmValue_t *parmB,
        parmValue_t *result,
        int a6,
        int a7,
        int a8)
{
  int v10; // r30
  double v59; // fp1

  _R31 = result;
  v10 = (op->type >> 9) & 0xF;
  switch ( a8 )
  {
    case 0:
      __asm
      {
        lvx128    v63, r0, r4# jumptable 828D77A8 case 0
        stvx128   v63, r0, r31
      }
      return;
    case 1:
      __asm
      {
        lvx128    v62, r0, r5# jumptable 828D77A8 case 1
        stvx128   v62, r0, r31
      }
      return;
    case 2:
      __asm { lvx128    v13, r0, r4# jumptable 828D77A8 case 2 }
      _R10 = 16 * v10;
      goto LABEL_5;
    case 3:
      __asm { lvx128    v13, r0, r5# jumptable 828D77A8 case 3 }
      _R10 = 16 * v10;
      goto LABEL_5;
    case 4:
      __asm { lvx128    v63, r0, r4 }
      _R10 = 48;
      __asm { lvx128    v62, r0, r5 }
      _R9 = &vmx_float_zero_2;
      __asm { lvx128    v0, r0, r31 }
      _R8 = 32;
      _R7 = 64;
      _R5 = 16 * v10;
      __asm { lvx128    v7, r9, r10 }
      _R4 = moveMask[0];
      __asm
      {
        lvx128    v13, r9, r8
        vperm128  v10, v95, v63, v7
        lvx128    v12, r9, r7
        lvx128    v11, r5, r4
        vslb      v9, v10, v13
        vaddsbs   v7, v9, v12
        vperm128  v13, v94, v62, v7
        vsel      v12, v0, v13, v11
      }
      goto LABEL_6;
    case 5:
      __asm { lvx128    v61, r0, r6# jumptable 828D77A8 case 5 }
      __asm { lvx128    v60, r0, r5 }
      _R10 = 16 * v10;
      __asm { vaddfp128 v13, v92, v61 }
      goto LABEL_5;
    case 6:
      __asm { lvx128    v59, r0, r6# jumptable 828D77A8 case 6 }
      __asm { lvx128    v58, r0, r5 }
      _R10 = 16 * v10;
      __asm { vsubfp128 v13, v90, v59 }
      goto LABEL_5;
    case 7:
      __asm { lvx128    v57, r0, r6# jumptable 828D77A8 case 7 }
      __asm { lvx128    v56, r0, r5 }
      _R10 = 16 * v10;
      __asm { vmulfp128 v13, v88, v57 }
      goto LABEL_5;
    case 8:
      __asm { lvx128    v55, r0, r6# jumptable 828D77A8 case 8 }
      __asm { lvx128    v54, r0, r5 }
      _R10 = 16 * v10;
      __asm { vmsum3fp128 v13, v86, v55 }
      goto LABEL_5;
    case 9:
      __asm { lvx128    v53, r0, r6# jumptable 828D77A8 case 9 }
      __asm { lvx128    v52, r0, r5 }
      _R10 = 16 * v10;
      __asm { vmsum4fp128 v13, v84, v53 }
LABEL_5:
      _R9 = moveMask[0];
      __asm
      {
        lvx128    v0, r0, r31
        lvx128    v12, r10, r9
        vsel      v12, v0, v13, v12
      }
      goto LABEL_6;
    case 10:
      __asm { lvx128    v12, r0, r6# jumptable 828D77A8 case 10 }
      __asm { vrefp     v0, v12 }
      _R10 = 16;
      _R9 = &vmx_float_zero_2;
      __asm { lvx128    v51, r0, r5 }
      __asm { lvx128    v11, r0, r31 }
      _R7 = 16 * v10;
      _R6 = moveMask[0];
      __asm
      {
        lvx128    v10, r9, r10
        lvx128    v9, r7, r6
        vnmsubfp  v10, v0, v10, v12
        vmaddfp   v0, v10, v0, v0
        vmulfp128 v0, v83, v0
        vsel      v13, v11, v0, v9
        stvx128   v13, r0, r31
      }
      return;
    case 11:
      __asm { lvx128    v12, r0, r5# jumptable 828D77A8 case 11 }
      __asm { vrefp     v0, v12 }
      _R10 = 16;
      _R9 = &vmx_float_zero_2;
      __asm { lvx128    v50, r0, r6 }
      __asm { lvx128    v13, r0, r31 }
      _R7 = 16 * v10;
      _R6 = moveMask[0];
      __asm
      {
        lvx128    v10, r9, r10
        lvx128    v9, r7, r6
        vnmsubfp  v10, v0, v10, v12
        vmaddfp   v0, v10, v0, v0
        vmulfp128 v49, v0, v50
        vrfiz128  v48, v49
        vsubfp128 v0, v81, v48
        vsel      v12, v13, v0, v9
      }
      goto LABEL_6;
    case 12:
      __asm { lvx128    v47, r0, r6# jumptable 828D77A8 case 12 }
      __asm { lvx128    v46, r0, r5 }
      _R10 = 16;
      __asm { vcmpgtfp128 v45, v78, v47 }
      _R9 = &vmx_float_zero_2;
      __asm { lvx128    v13, r0, r31 }
      _R7 = 16 * v10;
      _R6 = moveMask[0];
      __asm
      {
        lvx128    v63, r9, r10
        lvx128    v12, r7, r6
        vand128   v0, v77, v63
        vsel      v12, v13, v0, v12
      }
      goto LABEL_6;
    case 13:
      __asm { lvx128    v44, r0, r6# jumptable 828D77A8 case 13 }
      __asm { lvx128    v43, r0, r5 }
      _R10 = 16;
      __asm { vcmpgefp128 v42, v75, v44 }
      _R9 = &vmx_float_zero_2;
      __asm { lvx128    v13, r0, r31 }
      _R7 = 16 * v10;
      _R6 = moveMask[0];
      __asm
      {
        lvx128    v63, r9, r10
        lvx128    v12, r7, r6
        vand128   v0, v74, v63
        vsel      v12, v13, v0, v12
      }
      goto LABEL_6;
    case 14:
      __asm { lvx128    v40, r0, r6# jumptable 828D77A8 case 14 }
      __asm { lvx128    v41, r0, r5 }
      _R10 = 16;
      __asm { vcmpgefp128 v39, v72, v41 }
      _R9 = &vmx_float_zero_2;
      __asm { lvx128    v13, r0, r31 }
      _R7 = 16 * v10;
      _R6 = moveMask[0];
      __asm
      {
        lvx128    v63, r9, r10
        lvx128    v12, r7, r6
        vand128   v0, v71, v63
        vsel      v12, v13, v0, v12
      }
      goto LABEL_6;
    case 15:
      __asm { lvx128    v37, r0, r6# jumptable 828D77A8 case 15 }
      __asm { lvx128    v38, r0, r5 }
      _R10 = 16;
      __asm { vcmpgtfp128 v36, v69, v38 }
      _R9 = &vmx_float_zero_2;
      __asm { lvx128    v13, r0, r31 }
      _R7 = 16 * v10;
      _R6 = moveMask[0];
      __asm
      {
        lvx128    v63, r9, r10
        lvx128    v12, r7, r6
        vand128   v0, v68, v63
        vsel      v12, v13, v0, v12
      }
      goto LABEL_6;
    case 16:
      __asm { lvx128    v35, r0, r6# jumptable 828D77A8 case 16 }
      __asm { lvx128    v34, r0, r5 }
      _R10 = 16;
      __asm { vcmpeqfp128 v33, v66, v35 }
      _R9 = &vmx_float_zero_2;
      __asm { lvx128    v13, r0, r31 }
      _R7 = 16 * v10;
      _R6 = moveMask[0];
      __asm
      {
        lvx128    v63, r9, r10
        lvx128    v12, r7, r6
        vand128   v0, v65, v63
        vsel      v12, v13, v0, v12
      }
      goto LABEL_6;
    case 17:
      __asm { lvx128    v32, r0, r6# jumptable 828D77A8 case 17 }
      __asm { lvx128    v63, r0, r5 }
      _R10 = 16;
      __asm { vcmpeqfp128 v62, v95, v32 }
      _R9 = &vmx_float_zero_2;
      __asm { lvx128    v13, r0, r31 }
      _R7 = 16 * v10;
      _R6 = moveMask[0];
      __asm
      {
        lvx128    v63, r9, r10
        lvx128    v12, r7, r6
        vandc128  v0, v95, v62
        vsel      v12, v13, v0, v12
      }
      goto LABEL_6;
    case 18:
      __asm
      {
        lvx128    v60, r0, r6
        lvx128    v61, r0, r5
      }
      _R10 = 16;
      _R9 = &vmx_float_zero_2;
      __asm { lvx128    v13, r0, r31 }
      _R7 = 16 * v10;
      _R6 = moveMask[0];
      __asm
      {
        lvx128    v63, r0, r9
        vcmpeqfp128 v59, v93, v63
        lvx128    v62, r9, r10
        vcmpeqfp128 v58, v92, v63
        lvx128    v12, r7, r6
        vnor128   v57, v91, v59
        vnor128   v56, v90, v58
        vand128   v55, v89, v56
        vand128   v0, v87, v62
        vsel      v12, v13, v0, v12
      }
      goto LABEL_6;
    case 19:
      __asm
      {
        lvx128    v53, r0, r6
        lvx128    v54, r0, r5
      }
      _R10 = 16;
      _R9 = &vmx_float_zero_2;
      __asm { lvx128    v13, r0, r31 }
      _R7 = 16 * v10;
      _R6 = moveMask[0];
      __asm
      {
        lvx128    v63, r0, r9
        vcmpeqfp128 v52, v86, v63
        lvx128    v62, r9, r10
        vcmpeqfp128 v51, v85, v63
        lvx128    v12, r7, r6
        vnor128   v50, v84, v52
        vnor128   v49, v83, v51
        vor128    v48, v82, v49
        vand128   v0, v80, v62
        vsel      v12, v13, v0, v12
      }
LABEL_6:
      __asm { stvx128   v12, r0, r31 }
      break;
    case 20:
      v59 = idLookupTable::TableLookup(
              this: (idLookupTable *)renderThreadParmState->globalLookupTables[op->parmIndexA],
              time: parmB->value[0],
              fastSearch: (bool)constant);
      if ( (v10 & 1) != 0 )
        _R31->value[0] = v59;
      if ( (v10 & 2) != 0 )
        _R31->value[1] = v59;
      if ( (v10 & 4) != 0 )
        _R31->value[2] = v59;
      if ( (v10 & 8) != 0 )
        _R31->value[3] = v59;
      break;
  }
}


// ========================================================================
// ?EvaluateParmBlock@idParmState@@QAAXABVidParmBlock@@0@Z
// EA  : 0x828D7C38
// RVA : 0x008D7C38
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::EvaluateParmBlock(
        idParmState *this,
        const idParmBlock *localParmBlock,
        const idParmBlock *parmBlock)
{
  unsigned int *p_currentParmBlockLevel; // r22
  unsigned int currentParmBlockLevel; // r11
  unsigned int *p_currentOpLevel; // r21
  unsigned int currentOpLevel; // r10
  unsigned int v9; // r8
  parmValue_t *v10; // r9
  unsigned __int64 v11; // r5 OVERLAPPED
  int v12; // r10
  int num; // r11
  char v16; // r28
  int v17; // r26
  __int16 *p_parmIndexB; // r30
  int v20; // r27
  int v21; // r11
  int v23; // r8
  int v24; // r10
  __int16 v25; // r7
  __int16 v26; // r11
  __int128 v27; // r8
  unsigned __int64 textureParmVersion; // r10
  unsigned int v29; // r10

  _R31 = this;
  p_currentParmBlockLevel = &this->parmStack.currentParmBlockLevel;
  currentParmBlockLevel = this->parmStack.currentParmBlockLevel;
  if ( currentParmBlockLevel >= 0x20 )
  {
    if ( !AssertFailed(
            file: "w:\\tech5\\engine\\renderer\\jobs\\render\\ParmState.cpp",
            line: 1177,
            expression: "!\"EvaluateParmBlock: exceeded MAX_PARM_STACK_LEVELS\"",
            inlineBreak: true) )
      return;
    goto LABEL_3;
  }
  p_currentOpLevel = &this->parmStack.currentOpLevel;
  currentOpLevel = this->parmStack.currentOpLevel;
  if ( localParmBlock->ops.num + currentOpLevel <= 0x400 )
  {
    HIDWORD(v11) = currentOpLevel + 2580;
    this->parmStack.parmBlockStack[currentParmBlockLevel].parmBlock = parmBlock;
    v9 = *p_currentOpLevel;
    v10 = &this->parmStack.opStack[currentOpLevel];
    LODWORD(v11) = 8 * (*p_currentParmBlockLevel + 5128);
    v12 = c_ops;
    ++dword_8373461C;
    *(_DWORD *)((char *)&this->renderParmVersion + v11) = v9;
    num = localParmBlock->ops.num;
    c_ops = num + v12;
    if ( num > 0 )
    {
      _R11 = localParmBlock->ops.list;
      __asm { dcbt      0, r11 }
      _R29 = localParmBlock->constants.list;
      __asm { dcbt      0, r29 }
      v16 = 0;
      v17 = 1 << *p_currentParmBlockLevel;
      if ( localParmBlock->ops.num > 0 )
      {
        p_parmIndexB = &_R11->parmIndexB;
        _R25 = (char *)v10 - (char *)_R29;
        v20 = localParmBlock->ops.num;
        do
        {
          v21 = *(p_parmIndexB - 2);
          _R9 = 16 * (v21 + 3);
          v23 = _R31->parmUsageMask[v21];
          __asm { lvx128    v63, r9, r31 }
          v24 = 16 * (*(p_parmIndexB - 1) + 3);
          __asm { stvx128   v63, r25, r29 }
          v16 |= v23;
          idParmState::ApplyOp(
            op: (const expOp_t *)(p_parmIndexB - 3),
            constant: _R29,
            parmA: (const parmValue_t *)((char *)_R31 + v24),
            parmB: &_R31->values[*p_parmIndexB],
            result: (parmValue_t *)((char *)_R31 + _R9),
            a6: v23,
            a7: _R9,
            a8: v24);
          v25 = *(p_parmIndexB - 1);
          if ( v25 < 2047 )
            _R31->onParmBlockStack[v25] |= v17;
          if ( *p_parmIndexB < 2047 )
            _R31->onParmBlockStack[*p_parmIndexB] |= v17;
          v26 = *(p_parmIndexB - 2);
          --v20;
          p_parmIndexB += 4;
          ++_R29;
          _R31->onParmBlockStack[v26] |= v17;
        }
        while ( v20 != 0 );
      }
      *((_QWORD *)&v27 + 1) = _R31->fragmentParmVersion;
      textureParmVersion = _R31->textureParmVersion;
      DWORD2(v27) += LODWORD(_R31->vertexParmVersion);
      DWORD1(v27) = HIDWORD(textureParmVersion) + v27;
      LODWORD(v11) = (v16 & 4) + textureParmVersion;
      _R31->vertexParmVersion = *(_QWORD *)((char *)&v27 + 4);
      _R31->fragmentParmVersion = *(unsigned __int64 *)((char *)&v11 - 4);
      _R31->textureParmVersion = v11;
    }
    v29 = *p_currentOpLevel;
    ++*p_currentParmBlockLevel;
    *p_currentOpLevel = localParmBlock->ops.num + v29;
  }
  else if ( AssertFailed(
              file: "w:\\tech5\\engine\\renderer\\jobs\\render\\ParmState.cpp",
              line: 1181,
              expression: "!\"EvaluateParmBlock: exceeded MAX_PARM_STACK_OPS\"",
              inlineBreak: true) )
  {
LABEL_3:
    __trap();
  }
}


// ========================================================================
// ?RollbackParmBlock@idParmState@@QAAXABVidParmBlock@@0@Z
// EA  : 0x828D7EC0
// RVA : 0x008D7EC0
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::RollbackParmBlock(
        idParmState *this,
        const idParmBlock *localParmBlock,
        const idParmBlock *parmBlock)
{
  unsigned int currentParmBlockLevel; // r11
  unsigned int v5; // r11
  int num; // r8
  unsigned int lastOpLevel; // r30
  int v9; // r7
  char v10; // r31
  int v11; // ctr
  __int16 *p_parmIndexDest; // r11
  int v14; // r10
  unsigned __int64 v16; // r5 OVERLAPPED
  int v17; // r10
  __int16 v18; // r10
  int v19; // r10
  __int128 v20; // r8
  unsigned __int64 textureParmVersion; // r10

  currentParmBlockLevel = this->parmStack.currentParmBlockLevel;
  if ( currentParmBlockLevel == 0 )
  {
    if ( !AssertFailed(
            file: "w:\\tech5\\engine\\renderer\\jobs\\render\\ParmState.cpp",
            line: 1240,
            expression: "!\"RollbackParmBlock: called at level zero\"",
            inlineBreak: true) )
      return;
    goto LABEL_3;
  }
  v5 = currentParmBlockLevel - 1;
  this->parmStack.currentParmBlockLevel = v5;
  if ( parmBlock == this->parmStack.parmBlockStack[v5].parmBlock )
  {
    num = localParmBlock->ops.num;
    lastOpLevel = this->parmStack.parmBlockStack[v5].lastOpLevel;
    if ( num > 0 )
    {
      _R10 = localParmBlock->ops.list;
      __asm { dcbt      0, r10 }
      v9 = ~(1 << v5);
      v10 = 0;
      v11 = localParmBlock->ops.num;
      p_parmIndexDest = &localParmBlock->ops.list[num].parmIndexDest;
      _R8 = &this->parmStack.parmBlockStack[2 * lastOpLevel + 30 + 2 * num];
      do
      {
        __asm { lvx128    v63, r0, r8 }
        v14 = *(p_parmIndexDest - 4);
        LOBYTE(v16) = this->parmUsageMask[v14];
        _R10 = 16 * (v14 + 3);
        __asm { stvx128   v63, r10, r3 }
        HIDWORD(v16) = (unsigned __int16)*(p_parmIndexDest - 3);
        v10 |= v16;
        if ( SWORD1(v16) < 2047 )
        {
          v17 = 4 * (SWORD1(v16) + 8204);
          HIDWORD(v16) = *(_DWORD *)((_BYTE *)&this->renderParmVersion + v17) & v9;
          *(_DWORD *)((char *)&this->renderParmVersion + v17) = HIDWORD(v16);
        }
        v18 = *(p_parmIndexDest - 2);
        if ( v18 < 2047 )
        {
          v19 = 4 * (v18 + 8204);
          HIDWORD(v16) = *(_DWORD *)((_BYTE *)&this->renderParmVersion + v19) & v9;
          *(_DWORD *)((char *)&this->renderParmVersion + v19) = HIDWORD(v16);
        }
        p_parmIndexDest -= 4;
        _R8 -= 2;
        this->onParmBlockStack[*p_parmIndexDest] &= v9;
        --v11;
      }
      while ( v11 != 0 );
      *((_QWORD *)&v20 + 1) = this->fragmentParmVersion;
      textureParmVersion = this->textureParmVersion;
      DWORD2(v20) += LODWORD(this->vertexParmVersion);
      DWORD1(v20) = HIDWORD(textureParmVersion) + v20;
      LODWORD(v16) = (v10 & 4) + textureParmVersion;
      this->vertexParmVersion = *(_QWORD *)((char *)&v20 + 4);
      this->fragmentParmVersion = *(unsigned __int64 *)((char *)&v16 - 4);
      this->textureParmVersion = v16;
    }
    this->parmStack.currentOpLevel = lastOpLevel;
  }
  else if ( AssertFailed(
              file: "w:\\tech5\\engine\\renderer\\jobs\\render\\ParmState.cpp",
              line: 1245,
              expression: "!\"RollbackParmBlock: called with the wrong parmBlock\"",
              inlineBreak: true) )
  {
LABEL_3:
    __trap();
  }
}


// ========================================================================
// ?VirtualEvaluateParmBlock@idParmState@@QAAXABVidParmBlock@@0@Z
// EA  : 0x828D80C8
// RVA : 0x008D80C8
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

void __fastcall idParmState::VirtualEvaluateParmBlock(
        idParmState *this,
        const idParmBlock *localParmBlock,
        const idParmBlock *parmBlock)
{
  unsigned int *p_currentParmBlockLevel; // r28
  idParmState::parmStack_t *p_parmStack; // r30
  unsigned int currentParmBlockLevel; // r11
  unsigned int virtualParmBlockLevel; // r10
  unsigned int v10; // r5

  p_currentParmBlockLevel = &this->parmStack.currentParmBlockLevel;
  p_parmStack = &this->parmStack;
  currentParmBlockLevel = this->parmStack.currentParmBlockLevel;
  virtualParmBlockLevel = this->parmStack.virtualParmBlockLevel;
  if ( currentParmBlockLevel > virtualParmBlockLevel )
  {
    if ( parmBlock == this->parmStack.parmBlockStack[virtualParmBlockLevel].parmBlock )
    {
      v10 = this->parmStack.virtualParmBlockStackMask & ~(1 << virtualParmBlockLevel);
      p_parmStack->virtualParmBlockLevel = virtualParmBlockLevel + 1;
      this->parmStack.virtualParmBlockStackMask = v10;
      return;
    }
    do
    {
      idParmState::RollbackParmBlock(
        this,
        localParmBlock: *((const idParmBlock **)&this->parmStack.virtualParmBlockStackMask + 2 * currentParmBlockLevel),
        parmBlock: *((const idParmBlock **)&this->parmStack.virtualParmBlockStackMask + 2 * currentParmBlockLevel));
      currentParmBlockLevel = *p_currentParmBlockLevel;
    }
    while ( *p_currentParmBlockLevel > p_parmStack->virtualParmBlockLevel );
    this->parmStack.virtualParmBlockStackMask = 0;
  }
  idParmState::EvaluateParmBlock(this, localParmBlock, parmBlock);
  ++p_parmStack->virtualParmBlockLevel;
}


// ========================================================================
// ?RollbackVirtualStack@idParmState@@AAAX_N@Z
// EA  : 0x828D81A8
// RVA : 0x008D81A8
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::RollbackVirtualStack(idParmState *this, bool renderParmChange)
{
  unsigned int *p_currentParmBlockLevel; // r29
  idParmState::parmStack_t *p_parmStack; // r22
  const idParmBlock *v6; // r10
  int v7; // r11
  int num; // r8
  unsigned int lastOpLevel; // r3
  int v11; // r7
  unsigned __int64 v12; // r5 OVERLAPPED
  __int16 *p_parmIndexDest; // r11
  int v15; // ctr
  int v16; // r10
  int v18; // r9
  __int16 v19; // r10
  __int128 v20; // r8
  unsigned __int64 textureParmVersion; // r10

  p_currentParmBlockLevel = &this->parmStack.currentParmBlockLevel;
  p_parmStack = &this->parmStack;
  _R31 = this;
  if ( this->parmStack.currentParmBlockLevel > this->parmStack.virtualParmBlockLevel )
  {
    do
    {
      v6 = (const idParmBlock *)*(&_R31->parmStack.virtualParmBlockStackMask + 2 * *p_currentParmBlockLevel);
      if ( *p_currentParmBlockLevel != 0 )
      {
        v7 = *p_currentParmBlockLevel - 1;
        *p_currentParmBlockLevel = v7;
        if ( v6 == _R31->parmStack.parmBlockStack[v7].parmBlock )
        {
          num = v6->ops.num;
          lastOpLevel = _R31->parmStack.parmBlockStack[v7].lastOpLevel;
          if ( num > 0 )
          {
            _R10 = v6->ops.list;
            __asm { dcbt      0, r10 }
            v11 = ~(1 << v7);
            BYTE3(v12) = 0;
            v15 = num;
            p_parmIndexDest = &_R10[num].parmIndexDest;
            _R8 = (int)&_R31->parmStack.parmBlockStack[2 * lastOpLevel + 30 + 2 * num];
            do
            {
              __asm { lvx128    v63, r0, r8 }
              v16 = *(p_parmIndexDest - 4);
              v18 = _R31->parmUsageMask[v16];
              _R10 = 16 * (v16 + 3);
              __asm { stvx128   v63, r10, r31 }
              LOWORD(v12) = *(p_parmIndexDest - 3);
              HIDWORD(v12) = v18 | BYTE3(v12);
              if ( (__int16)v12 < 2047 )
                _R31->onParmBlockStack[(__int16)v12] &= v11;
              v19 = *(p_parmIndexDest - 2);
              if ( v19 < 2047 )
                _R31->onParmBlockStack[v19] &= v11;
              p_parmIndexDest -= 4;
              _R8 -= 16;
              _R31->onParmBlockStack[*p_parmIndexDest] &= v11;
              --v15;
            }
            while ( v15 != 0 );
            *((_QWORD *)&v20 + 1) = _R31->fragmentParmVersion;
            textureParmVersion = _R31->textureParmVersion;
            DWORD2(v20) += LODWORD(_R31->vertexParmVersion);
            DWORD1(v20) = HIDWORD(textureParmVersion) + v20;
            LODWORD(v12) = (BYTE3(v12) & 4) + textureParmVersion;
            _R31->vertexParmVersion = *(_QWORD *)((char *)&v20 + 4);
            _R31->fragmentParmVersion = *(unsigned __int64 *)((char *)&v12 - 4);
            _R31->textureParmVersion = v12;
          }
          _R31->parmStack.currentOpLevel = lastOpLevel;
          continue;
        }
        if ( AssertFailed(
               file: "w:\\tech5\\engine\\renderer\\jobs\\render\\ParmState.cpp",
               line: 1245,
               expression: "!\"RollbackParmBlock: called with the wrong parmBlock\"",
               inlineBreak: true) )
        {
LABEL_4:
          __trap();
        }
      }
      else if ( AssertFailed(
                  file: "w:\\tech5\\engine\\renderer\\jobs\\render\\ParmState.cpp",
                  line: 1240,
                  expression: "!\"RollbackParmBlock: called at level zero\"",
                  inlineBreak: true) )
      {
        goto LABEL_4;
      }
    }
    while ( *p_currentParmBlockLevel > p_parmStack->virtualParmBlockLevel );
  }
  _R31->parmStack.virtualParmBlockStackMask = 0;
}


// ========================================================================
// ?RemoveFromVirtualStack@idParmState@@QAAXABVidParmBlock@@@Z
// EA  : 0x828D83F8
// RVA : 0x008D83F8
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

void __fastcall idParmState::RemoveFromVirtualStack(idParmState *this, const idParmBlock *parmBlock)
{
  idParmState::parmStack_t *p_parmStack; // r28
  unsigned int v5; // r10
  const idParmBlock **p_parmBlock; // r11
  unsigned int virtualParmBlockLevel; // r9
  unsigned int *p_currentParmBlockLevel; // r31
  unsigned int v9; // r11
  unsigned int currentParmBlockLevel; // r8
  const idParmBlock **i; // r10
  const idParmBlock *v12; // r5

  p_parmStack = &this->parmStack;
  v5 = 0;
  if ( this->parmStack.virtualParmBlockLevel != 0 )
  {
    p_parmBlock = &this->parmStack.parmBlockStack[0].parmBlock;
    while ( *p_parmBlock != parmBlock )
    {
      ++v5;
      p_parmBlock += 2;
      if ( v5 >= p_parmStack->virtualParmBlockLevel )
        goto LABEL_8;
    }
    if ( AssertFailed(
           file: "w:\\tech5\\engine\\renderer\\jobs\\render\\ParmState.cpp",
           line: 1364,
           expression: "!\"RemoveFromVirtualStack: tried to delete or modify a parm block while on the stack\"",
           inlineBreak: true) )
    {
      __trap();
    }
  }
LABEL_8:
  virtualParmBlockLevel = p_parmStack->virtualParmBlockLevel;
  p_currentParmBlockLevel = &this->parmStack.currentParmBlockLevel;
  v9 = p_parmStack->virtualParmBlockLevel;
  currentParmBlockLevel = this->parmStack.currentParmBlockLevel;
  if ( p_parmStack->virtualParmBlockLevel < currentParmBlockLevel )
  {
    for ( i = &this->parmStack.parmBlockStack[virtualParmBlockLevel].parmBlock; *i != parmBlock; i += 2 )
    {
      if ( ++v9 >= *p_currentParmBlockLevel )
        return;
    }
    if ( currentParmBlockLevel > virtualParmBlockLevel )
    {
      do
      {
        v12 = (const idParmBlock *)*(&this->parmStack.virtualParmBlockStackMask + 2 * *p_currentParmBlockLevel);
        idParmState::RollbackParmBlock(this, localParmBlock: v12, parmBlock: v12);
      }
      while ( *p_currentParmBlockLevel > p_parmStack->virtualParmBlockLevel );
    }
    this->parmStack.virtualParmBlockStackMask = 0;
  }
}


// ========================================================================
// ?RollbackOpsToZero@idParmState@@QAAXXZ
// EA  : 0x828D8528
// RVA : 0x008D8528
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::RollbackOpsToZero(idParmState *this)
{
  unsigned __int64 renderParmVersion; // r7 OVERLAPPED
  unsigned __int64 fragmentParmVersion; // r9 OVERLAPPED
  unsigned __int64 v4; // r5
  int v5; // r10

  idParmState::RollbackVirtualStack(this, renderParmChange: false);
  if ( this->parmStack.currentParmBlockLevel != 0 )
  {
    renderParmVersion = this->renderParmVersion;
    fragmentParmVersion = this->fragmentParmVersion;
    HIDWORD(v4) = 41008;
    *(unsigned __int64 *)((char *)&fragmentParmVersion - 4) = this->textureParmVersion;
    LODWORD(v4) = HIDWORD(fragmentParmVersion) + 1;
    LODWORD(renderParmVersion) = LODWORD(this->renderParmVersion) + 1;
    this->vertexParmVersion = v4;
    LODWORD(fragmentParmVersion) = fragmentParmVersion + 2;
    *(_DWORD *)HIDWORD(renderParmVersion) = 0;
    HIDWORD(fragmentParmVersion) = v5 + 4;
    this->parmStack.virtualParmBlockLevel = 0;
    this->parmStack.currentOpLevel = 0;
    this->renderParmVersion = renderParmVersion;
    this->fragmentParmVersion = fragmentParmVersion;
    this->textureParmVersion = *(unsigned __int64 *)((char *)&renderParmVersion - 4);
    this->currentMVPHasNegativeDeterminant = false;
  }
}


// ========================================================================
// ?SetVertexMorphScale@idParmState@@QAAXABVidVec4@@@Z
// EA  : 0x828D85C0
// RVA : 0x008D85C0
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetVertexMorphScale(idParmState *this, const idVec4 *scale)
{
  int *p_parmIndexVertexMorphScale; // r29
  parmValue_t *v5; // r11
  __int128 v6; // r6 OVERLAPPED
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  unsigned __int64 renderParmVersion; // r11

  p_parmIndexVertexMorphScale = &this->parmIndexVertexMorphScale;
  if ( (this->onParmBlockStack[this->parmIndexVertexMorphScale] & this->parmStack.virtualParmBlockStackMask) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  v5 = &this->values[*p_parmIndexVertexMorphScale];
  v5->value[0] = scale->x;
  v5->value[1] = scale->y;
  v5->value[2] = scale->z;
  v5->value[3] = scale->w;
  *((_QWORD *)&v6 + 1) = this->vertexParmVersion;
  fragmentParmVersion = this->fragmentParmVersion;
  renderParmVersion = this->renderParmVersion;
  DWORD1(v6) = LODWORD(this->renderParmVersion) + 1;
  HIDWORD(v6) = *((unsigned __int8 *)&this->renderParmVersion
                + *p_parmIndexVertexMorphScale
                + HIDWORD(fragmentParmVersion));
  this->renderParmVersion = *(_QWORD *)&v6;
  HIDWORD(fragmentParmVersion) = (BYTE3(v6) & 1) + v6;
  LODWORD(v6) = (BYTE3(v6) & 2) + fragmentParmVersion;
  DWORD2(v6) = (BYTE3(v6) & 4) + HIDWORD(renderParmVersion);
  this->vertexParmVersion = *(_QWORD *)((char *)&v6 - 4);
  this->fragmentParmVersion = v6;
  this->textureParmVersion = *(_QWORD *)((char *)&v6 + 4);
}


// ========================================================================
// ?SetPositionToViewTexture@idParmState@@QAAXHHHH@Z
// EA  : 0x828D8698
// RVA : 0x008D8698
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetPositionToViewTexture(
        idParmState *this,
        int windowWidth,
        int windowHeight,
        unsigned int renderWidth,
        unsigned int renderHeight)
{
  int v5; // r2 OVERLAPPED
  int *p_parmIndexPositionToViewTexture; // r30
  __int64 v10; // r9
  parmValue_t *v11; // r11
  int v12; // r11 OVERLAPPED
  unsigned __int64 vertexParmVersion; // r6
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  unsigned __int64 v16; // r4
  int v17; // r11

  p_parmIndexPositionToViewTexture = &this->parmIndexPositionToViewTexture;
  HIDWORD(v10) = this->parmStack.virtualParmBlockStackMask;
  if ( (this->onParmBlockStack[this->parmIndexPositionToViewTexture] & HIDWORD(v10)) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  LODWORD(v10) = renderWidth;
  v11 = &this->values[*p_parmIndexPositionToViewTexture];
  v11->value[3] = (float)1.0 / (float)__SPAIR64__(renderWidth, renderHeight);
  v11->value[2] = (float)1.0 / (float)v10;
  v11->value[1] = (float)((float)1.0 / (float)__SPAIR64__(renderWidth, renderHeight)) * (float)0.5;
  v11->value[0] = (float)((float)1.0 / (float)v10) * (float)0.5;
  v12 = LODWORD(this->renderParmVersion) + 1;
  vertexParmVersion = this->vertexParmVersion;
  fragmentParmVersion = this->fragmentParmVersion;
  textureParmVersion = this->textureParmVersion;
  BYTE3(vertexParmVersion) = this->parmUsageMask[*p_parmIndexPositionToViewTexture];
  this->renderParmVersion = *(_QWORD *)&v12;
  LODWORD(v16) = (BYTE3(vertexParmVersion) & 1) + vertexParmVersion;
  HIDWORD(v16) = (BYTE3(vertexParmVersion) & 2) + fragmentParmVersion;
  v17 = (BYTE3(vertexParmVersion) & 4) + textureParmVersion;
  this->vertexParmVersion = v16;
  this->fragmentParmVersion = *(_QWORD *)(&v5 - 1);
  this->textureParmVersion = *(unsigned __int64 *)((char *)&textureParmVersion - 4);
}


// ========================================================================
// ?SetRenderPositionToViewTexture@idParmState@@QAAXHHHH@Z
// EA  : 0x828D87A8
// RVA : 0x008D87A8
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetRenderPositionToViewTexture(
        idParmState *this,
        int windowWidth,
        int windowHeight,
        unsigned int renderWidth,
        unsigned int renderHeight)
{
  int v5; // r2 OVERLAPPED
  int *p_parmIndexRenderPositionToViewTexture; // r30
  __int64 v10; // r9
  parmValue_t *v11; // r11
  int v12; // r11 OVERLAPPED
  unsigned __int64 vertexParmVersion; // r6
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  unsigned __int64 v16; // r4
  int v17; // r11

  p_parmIndexRenderPositionToViewTexture = &this->parmIndexRenderPositionToViewTexture;
  HIDWORD(v10) = this->parmStack.virtualParmBlockStackMask;
  if ( (this->onParmBlockStack[this->parmIndexRenderPositionToViewTexture] & HIDWORD(v10)) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  LODWORD(v10) = renderWidth;
  v11 = &this->values[*p_parmIndexRenderPositionToViewTexture];
  v11->value[3] = (float)1.0 / (float)__SPAIR64__(renderWidth, renderHeight);
  v11->value[2] = (float)1.0 / (float)v10;
  v11->value[1] = (float)((float)1.0 / (float)__SPAIR64__(renderWidth, renderHeight)) * (float)0.5;
  v11->value[0] = (float)((float)1.0 / (float)v10) * (float)0.5;
  v12 = LODWORD(this->renderParmVersion) + 1;
  vertexParmVersion = this->vertexParmVersion;
  fragmentParmVersion = this->fragmentParmVersion;
  textureParmVersion = this->textureParmVersion;
  BYTE3(vertexParmVersion) = this->parmUsageMask[*p_parmIndexRenderPositionToViewTexture];
  this->renderParmVersion = *(_QWORD *)&v12;
  LODWORD(v16) = (BYTE3(vertexParmVersion) & 1) + vertexParmVersion;
  HIDWORD(v16) = (BYTE3(vertexParmVersion) & 2) + fragmentParmVersion;
  v17 = (BYTE3(vertexParmVersion) & 4) + textureParmVersion;
  this->vertexParmVersion = v16;
  this->fragmentParmVersion = *(_QWORD *)(&v5 - 1);
  this->textureParmVersion = *(unsigned __int64 *)((char *)&textureParmVersion - 4);
}


// ========================================================================
// ?SetPositionToFeedback@idParmState@@QAAXHHHH@Z
// EA  : 0x828D88B8
// RVA : 0x008D88B8
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetPositionToFeedback(
        idParmState *this,
        unsigned int renderWidth,
        unsigned int renderHeight,
        __int64 feedbackHeight)
{
  int v4; // r2 OVERLAPPED
  int *p_parmIndexPositionToFeedback; // r30
  unsigned int v6; // r26
  __int64 v7; // r28
  __int128 v10; // r9 OVERLAPPED
  parmValue_t *v11; // r11
  unsigned __int64 v12; // r5
  int v13; // r3
  int v14; // r10

  p_parmIndexPositionToFeedback = &this->parmIndexPositionToFeedback;
  v6 = feedbackHeight;
  v7 = __PAIR64__(HIDWORD(feedbackHeight), renderHeight);
  HIDWORD(feedbackHeight) = this->onParmBlockStack[this->parmIndexPositionToFeedback];
  if ( (HIDWORD(feedbackHeight) & this->parmStack.virtualParmBlockStackMask) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  LODWORD(v10) = renderWidth;
  *(__int64 *)((char *)&feedbackHeight - 4) = v7;
  v11 = &this->values[*p_parmIndexPositionToFeedback];
  v11->value[0] = 0.0;
  v11->value[1] = 0.0;
  v11->value[3] = (float)((float)__SPAIR64__(renderWidth, v6) * (float)0.5) / (float)v7;
  v11->value[2] = (float)((float)feedbackHeight * (float)0.5) / (float)(__int64)v10;
  *(_QWORD *)((char *)&v10 + 4) = this->fragmentParmVersion;
  *(_QWORD *)((char *)&v10 + 12) = this->vertexParmVersion;
  *(_QWORD *)((char *)&v10 - 4) = this->textureParmVersion;
  HIDWORD(v12) = *(unsigned __int8 *)(DWORD1(v10) + v10);
  DWORD1(v10) = BYTE3(v12) & 1;
  this->renderParmVersion = v12;
  LODWORD(v10) = (BYTE3(v12) & 2) + DWORD2(v10);
  v13 = DWORD1(v10) + HIDWORD(v10);
  DWORD2(v10) = (BYTE3(v12) & 4) + v14;
  this->fragmentParmVersion = v10;
  this->vertexParmVersion = *(_QWORD *)(&v4 - 1);
  this->textureParmVersion = *(_QWORD *)((char *)&v10 + 4);
}


// ========================================================================
// ?SetHighlightColor@idParmState@@QAAXABVidVec4@@@Z
// EA  : 0x828D89F8
// RVA : 0x008D89F8
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetHighlightColor(idParmState *this, const idVec4 *highlightColor)
{
  int *p_parmIndexHighlightColor; // r29
  parmValue_t *v5; // r11
  __int128 v6; // r6 OVERLAPPED
  unsigned __int64 fragmentParmVersion; // r8
  unsigned __int64 textureParmVersion; // r10

  p_parmIndexHighlightColor = &this->parmIndexHighlightColor;
  if ( (this->onParmBlockStack[this->parmIndexHighlightColor] & this->parmStack.virtualParmBlockStackMask) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  v5 = &this->values[*p_parmIndexHighlightColor];
  v5->value[0] = highlightColor->x;
  v5->value[1] = highlightColor->y;
  v5->value[2] = highlightColor->z;
  v5->value[3] = 1.0;
  *((_QWORD *)&v6 + 1) = this->vertexParmVersion;
  DWORD1(v6) = LODWORD(this->renderParmVersion) + 1;
  fragmentParmVersion = this->fragmentParmVersion;
  textureParmVersion = this->textureParmVersion;
  HIDWORD(v6) = *(unsigned __int8 *)(DWORD2(v6) + HIDWORD(fragmentParmVersion));
  this->renderParmVersion = *(_QWORD *)&v6;
  HIDWORD(fragmentParmVersion) = (BYTE3(v6) & 1) + v6;
  LODWORD(v6) = (BYTE3(v6) & 2) + fragmentParmVersion;
  DWORD2(v6) = (BYTE3(v6) & 4) + textureParmVersion;
  this->vertexParmVersion = *(_QWORD *)((char *)&v6 - 4);
  this->fragmentParmVersion = v6;
  this->textureParmVersion = *(_QWORD *)((char *)&v6 + 4);
}


// ========================================================================
// ?SetApproximateLighting@idParmState@@QAAXABUapproximateLighting_t@@@Z
// EA  : 0x828D8AD0
// RVA : 0x008D8AD0
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetApproximateLighting(idParmState *this, const approximateLighting_t *lighting)
{
  int v2; // r2 OVERLAPPED
  int *v4; // r29
  int *v5; // r28
  int *v6; // r26
  int *v7; // r27
  int *p_parmIndexPrimeLightDir; // r24
  int *p_parmIndexLightingModel; // r25
  int *v10; // r23
  int *p_parmIndexPrimeLightColor; // r22
  int *parmIndexChannelLight; // r21
  unsigned __int64 vertexParmVersion; // r6
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  unsigned __int64 v35; // r4
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  int v37; // r11
  int v38; // r11

  v4 = &this->parmIndexChannelLight[5];
  v5 = &this->parmIndexChannelLight[4];
  v6 = &this->parmIndexChannelLight[2];
  v7 = &this->parmIndexChannelLight[3];
  p_parmIndexPrimeLightDir = &this->parmIndexPrimeLightDir;
  p_parmIndexLightingModel = &this->parmIndexLightingModel;
  v10 = &this->parmIndexChannelLight[1];
  _R31 = this;
  _R30 = lighting;
  p_parmIndexPrimeLightColor = &this->parmIndexPrimeLightColor;
  parmIndexChannelLight = this->parmIndexChannelLight;
  if ( (this->parmStack.virtualParmBlockStackMask
      & (this->onParmBlockStack[this->parmIndexChannelLight[5]]
       | this->onParmBlockStack[this->parmIndexChannelLight[4]]
       | this->onParmBlockStack[this->parmIndexChannelLight[3]]
       | this->onParmBlockStack[this->parmIndexChannelLight[2]]
       | this->onParmBlockStack[this->parmIndexChannelLight[1]]
       | this->onParmBlockStack[this->parmIndexChannelLight[0]]
       | this->onParmBlockStack[this->parmIndexPrimeLightDir]
       | this->onParmBlockStack[this->parmIndexLightingModel]
       | this->onParmBlockStack[this->parmIndexPrimeLightColor])) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  _R11 = 16;
  _R10 = &_R30->lightingModel;
  __asm { lvlx128   v63, r0, r30 }
  _R9 = &_R30->primeLightColor;
  _R8 = _R30->channelLighting;
  _R7 = &_R30->channelLighting[1];
  __asm
  {
    lvrx128   v62, r11, r30
    lvrx128   v61, r11, r10
  }
  _R6 = &_R30->channelLighting[3];
  __asm { lvlx128   v60, r0, r10 }
  _R10 = &_R30->channelLighting[2];
  _R5 = &_R30->channelLighting[4];
  __asm { vor128    v59, v92, v61 }
  _R4 = &_R30->channelLighting[5];
  __asm { lvrx128   v58, r11, r9 }
  _R3 = 16 * (*p_parmIndexLightingModel + 3);
  __asm
  {
    lvrx128   v57, r11, r8
    lvrx128   v56, r11, r7
    vor128    v55, v95, v62
    lvrx128   v54, r11, r10
  }
  __asm
  {
    lvrx128   v53, r11, r6
    lvrx128   v52, r11, r5
    lvrx128   v51, r11, r4
    lvlx128   v50, r0, r9
    lvlx128   v49, r0, r8
    vor128    v48, v82, v58
    lvlx128   v47, r0, r7
    vor128    v46, v81, v57
    lvlx128   v45, r0, r10
    vor128    v44, v79, v56
    lvlx128   v43, r0, r6
    vor128    v42, v77, v54
    lvlx128   v41, r0, r5
    vor128    v40, v75, v53
    lvlx128   v39, r0, r4
    vor128    v38, v73, v52
    stvx128   v59, r3, r31
  }
  __asm { vor128    v37, v71, v51 }
  _R10 = 16 * (*p_parmIndexPrimeLightDir + 3);
  __asm { stvx128   v55, r10, r31 }
  _R8 = 16 * (*p_parmIndexPrimeLightColor + 3);
  __asm { stvx128   v48, r8, r31 }
  _R6 = 16 * (*parmIndexChannelLight + 3);
  __asm { stvx128   v46, r6, r31 }
  _R4 = 16 * (*v10 + 3);
  __asm { stvx128   v44, r4, r31 }
  _R11 = 16 * (*v6 + 3);
  __asm { stvx128   v42, r11, r31 }
  _R9 = 16 * (*v7 + 3);
  __asm { stvx128   v40, r9, r31 }
  _R7 = 16 * (*v5 + 3);
  __asm { stvx128   v38, r7, r31 }
  _R5 = 16 * (*v4 + 3);
  __asm { stvx128   v37, r5, r31 }
  vertexParmVersion = _R31->vertexParmVersion;
  fragmentParmVersion = _R31->fragmentParmVersion;
  LODWORD(v35) = LODWORD(_R31->renderParmVersion) + 1;
  textureParmVersion = _R31->textureParmVersion;
  HIDWORD(v35) = HIDWORD(vertexParmVersion)
               | (unsigned __int8)(_R31->parmUsageMask[*p_parmIndexPrimeLightDir]
                                 | _R31->parmUsageMask[*p_parmIndexPrimeLightColor]);
  v37 = *(unsigned __int8 *)(HIDWORD(fragmentParmVersion) + 65856);
  HIDWORD(textureParmVersion) = (unsigned __int8)(BYTE3(vertexParmVersion)
                                                | _R31->parmUsageMask[*p_parmIndexPrimeLightDir]
                                                | _R31->parmUsageMask[*p_parmIndexPrimeLightColor]);
  _R31->renderParmVersion = v35;
  LODWORD(v35) = ((v37 | HIDWORD(textureParmVersion)) & 1) + vertexParmVersion;
  HIDWORD(v35) = ((v37 | HIDWORD(textureParmVersion)) & 2) + fragmentParmVersion;
  v38 = ((v37 | HIDWORD(textureParmVersion)) & 4) + textureParmVersion;
  _R31->vertexParmVersion = v35;
  _R31->fragmentParmVersion = *(_QWORD *)(&v2 - 1);
  _R31->textureParmVersion = *(unsigned __int64 *)((char *)&textureParmVersion - 4);
}

