
// ========================================================================
// ?Set16BitVertexScaleBias@idParmState@@QAAXABVidVertexScaleAndBias@@@Z
// EA  : 0x828D6720
// RVA : 0x008D6720
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::Set16BitVertexScaleBias(idParmState *this, const idVertexScaleAndBias *vsb)
{
  int v2; // r2 OVERLAPPED
  int *p_parmIndexVertexXYZBias; // r29
  int *p_parmIndexVertexStScaleBias; // r28
  int *p_parmIndexVertexXYZScale; // r27
  unsigned __int64 v8; // r11 OVERLAPPED
  unsigned __int64 vertexParmVersion; // r6 OVERLAPPED
  char v10; // r4
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  int v12; // r9
  int v13; // r9
  int v14; // r3

  p_parmIndexVertexXYZBias = &this->parmIndexVertexXYZBias;
  p_parmIndexVertexStScaleBias = &this->parmIndexVertexStScaleBias;
  p_parmIndexVertexXYZScale = &this->parmIndexVertexXYZScale;
  if ( ((this->onParmBlockStack[this->parmIndexVertexStScaleBias]
       | this->onParmBlockStack[this->parmIndexVertexXYZBias]
       | this->onParmBlockStack[this->parmIndexVertexXYZScale])
      & this->parmStack.virtualParmBlockStackMask) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  this->values[*p_parmIndexVertexStScaleBias].value[0] = vsb->stScale.x;
  this->values[*p_parmIndexVertexStScaleBias].value[1] = vsb->stScale.y;
  this->values[*p_parmIndexVertexStScaleBias].value[2] = vsb->stBias.x;
  this->values[*p_parmIndexVertexStScaleBias].value[3] = vsb->stBias.y;
  this->values[*p_parmIndexVertexXYZScale].value[0] = vsb->xyzScale.x;
  this->values[*p_parmIndexVertexXYZScale].value[1] = vsb->xyzScale.y;
  this->values[*p_parmIndexVertexXYZScale].value[2] = vsb->xyzScale.z;
  this->values[*p_parmIndexVertexXYZScale].value[3] = 0.0;
  this->values[*p_parmIndexVertexXYZBias].value[0] = vsb->xyzBias.x;
  this->values[*p_parmIndexVertexXYZBias].value[1] = vsb->xyzBias.y;
  this->values[*p_parmIndexVertexXYZBias].value[2] = vsb->xyzBias.z;
  this->values[*p_parmIndexVertexXYZBias].value[3] = 1.0;
  LODWORD(v8) = LODWORD(this->renderParmVersion) + 1;
  HIDWORD(v8) = (char *)this + HIDWORD(this->renderParmVersion);
  vertexParmVersion = this->vertexParmVersion;
  v10 = *(_BYTE *)(HIDWORD(v8) + 65856)
      | this->parmUsageMask[*p_parmIndexVertexXYZBias]
      | this->parmUsageMask[*p_parmIndexVertexXYZScale];
  fragmentParmVersion = this->fragmentParmVersion;
  this->renderParmVersion = v8;
  HIDWORD(fragmentParmVersion) = v10 & 1;
  *(unsigned __int64 *)((char *)&v8 + 4) = this->textureParmVersion;
  v13 = v12 + fragmentParmVersion;
  v14 = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  LODWORD(fragmentParmVersion) = (v10 & 4) + HIDWORD(v8);
  this->fragmentParmVersion = *(unsigned __int64 *)((char *)&fragmentParmVersion - 4);
  this->vertexParmVersion = *(_QWORD *)(&v2 - 1);
  this->textureParmVersion = fragmentParmVersion;
}


// ========================================================================
// ?SetMVPMatrix@idParmState@@QAAXABVidRenderMatrix@@@Z
// EA  : 0x828D9640
// RVA : 0x008D9640
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetMVPMatrix(idParmState *this, const idRenderMatrix *mvp)
{
  int *p_parmIndexMVPMatrixY; // r30
  int *p_parmIndexMVPMatrixX; // r29
  int *p_parmIndexMVPMatrixW; // r28
  int *p_parmIndexMVPMatrixZ; // r27
  unsigned __int64 vertexParmVersion; // r6 OVERLAPPED
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  int v11; // r3
  int v12; // r11
  int v13; // r11
  __int128 v14; // r4
  int v15; // r11

  p_parmIndexMVPMatrixY = &this->parmIndexMVPMatrixY;
  p_parmIndexMVPMatrixX = &this->parmIndexMVPMatrixX;
  p_parmIndexMVPMatrixW = &this->parmIndexMVPMatrixW;
  p_parmIndexMVPMatrixZ = &this->parmIndexMVPMatrixZ;
  if ( ((this->onParmBlockStack[this->parmIndexMVPMatrixX]
       | this->onParmBlockStack[this->parmIndexMVPMatrixY]
       | this->onParmBlockStack[this->parmIndexMVPMatrixW]
       | this->onParmBlockStack[this->parmIndexMVPMatrixZ])
      & this->parmStack.virtualParmBlockStackMask) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  idRenderMatrix::SetMVP(
    mvp,
    row0: (idVec4 *)&this->values[*p_parmIndexMVPMatrixX],
    row1: (idVec4 *)&this->values[*p_parmIndexMVPMatrixY],
    row2: (idVec4 *)&this->values[*p_parmIndexMVPMatrixZ],
    row3: (idVec4 *)&this->values[*p_parmIndexMVPMatrixW],
    negativeDeterminant: &this->currentMVPHasNegativeDeterminant);
  vertexParmVersion = this->vertexParmVersion;
  fragmentParmVersion = this->fragmentParmVersion;
  textureParmVersion = this->textureParmVersion;
  HIDWORD(fragmentParmVersion) = LODWORD(this->renderParmVersion) + 1;
  v11 = this->parmUsageMask[*p_parmIndexMVPMatrixZ];
  v12 = HIDWORD(textureParmVersion) | this->parmUsageMask[*p_parmIndexMVPMatrixW];
  this->renderParmVersion = *(unsigned __int64 *)((char *)&vertexParmVersion - 4);
  HIDWORD(fragmentParmVersion) = (v12 | v11) & 1;
  HIDWORD(textureParmVersion) = (v12 | v11) & 2;
  v13 = (v12 | v11) & 4;
  LODWORD(v14) = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  DWORD2(v14) = HIDWORD(textureParmVersion) + fragmentParmVersion;
  v15 = v13 + textureParmVersion;
  this->vertexParmVersion = v14;
  this->fragmentParmVersion = *(_QWORD *)((char *)&v14 + 4);
  this->textureParmVersion = *(unsigned __int64 *)((char *)&textureParmVersion - 4);
}


// ========================================================================
// ?SetModelMatrix@idParmState@@QAAXABVidRenderMatrix@@@Z
// EA  : 0x828DA9F0
// RVA : 0x008DA9F0
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetModelMatrix(idParmState *this, const idRenderMatrix *modelMatrix)
{
  int *p_parmIndexModelMatrixY; // r30
  int *p_parmIndexModelMatrixX; // r29
  int *p_parmIndexModelMatrixW; // r28
  int *p_parmIndexModelMatrixZ; // r27
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  unsigned __int64 vertexParmVersion; // r6 OVERLAPPED
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  int v11; // r11
  int v12; // r11
  unsigned __int64 v13; // r3

  p_parmIndexModelMatrixY = &this->parmIndexModelMatrixY;
  p_parmIndexModelMatrixX = &this->parmIndexModelMatrixX;
  p_parmIndexModelMatrixW = &this->parmIndexModelMatrixW;
  p_parmIndexModelMatrixZ = &this->parmIndexModelMatrixZ;
  if ( ((this->onParmBlockStack[this->parmIndexModelMatrixX]
       | this->onParmBlockStack[this->parmIndexModelMatrixY]
       | this->onParmBlockStack[this->parmIndexModelMatrixW]
       | this->onParmBlockStack[this->parmIndexModelMatrixZ])
      & this->parmStack.virtualParmBlockStackMask) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  idRenderMatrix::CopyMatrix(
    matrix: modelMatrix,
    row0: (idVec4 *)&this->values[*p_parmIndexModelMatrixX],
    row1: (idVec4 *)&this->values[*p_parmIndexModelMatrixY],
    row2: (idVec4 *)&this->values[*p_parmIndexModelMatrixZ],
    row3: (idVec4 *)&this->values[*p_parmIndexModelMatrixW]);
  fragmentParmVersion = this->fragmentParmVersion;
  vertexParmVersion = this->vertexParmVersion;
  textureParmVersion = this->textureParmVersion;
  v11 = LODWORD(this->renderParmVersion) + 1;
  HIDWORD(fragmentParmVersion) = this->parmUsageMask[*p_parmIndexModelMatrixZ];
  HIDWORD(vertexParmVersion) = this->parmUsageMask[*p_parmIndexModelMatrixX]
                             | this->parmUsageMask[*p_parmIndexModelMatrixY]
                             | this->parmUsageMask[*p_parmIndexModelMatrixW];
  this->renderParmVersion = *(unsigned __int64 *)((char *)&textureParmVersion - 4);
  HIDWORD(textureParmVersion) = (HIDWORD(vertexParmVersion) | HIDWORD(fragmentParmVersion)) & 2;
  v12 = (HIDWORD(vertexParmVersion) | HIDWORD(fragmentParmVersion)) & 4;
  HIDWORD(fragmentParmVersion) = (HIDWORD(vertexParmVersion) | HIDWORD(fragmentParmVersion)) & 1;
  HIDWORD(textureParmVersion) += fragmentParmVersion;
  LODWORD(v13) = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  LODWORD(fragmentParmVersion) = v12 + textureParmVersion;
  this->fragmentParmVersion = *(unsigned __int64 *)((char *)&fragmentParmVersion - 4);
  this->vertexParmVersion = v13;
  this->textureParmVersion = fragmentParmVersion;
}


// ========================================================================
// ?SetInverseModelMatrix@idParmState@@QAAXABVidRenderMatrix@@@Z
// EA  : 0x828DAB78
// RVA : 0x008DAB78
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetInverseModelMatrix(idParmState *this, const idRenderMatrix *inverseModelMatrix)
{
  int *p_parmIndexInverseModelMatrixY; // r30
  int *p_parmIndexInverseModelMatrixX; // r29
  int *p_parmIndexInverseModelMatrixW; // r28
  int *p_parmIndexInverseModelMatrixZ; // r27
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  unsigned __int64 vertexParmVersion; // r6 OVERLAPPED
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  int v11; // r11
  int v12; // r11
  unsigned __int64 v13; // r3

  p_parmIndexInverseModelMatrixY = &this->parmIndexInverseModelMatrixY;
  p_parmIndexInverseModelMatrixX = &this->parmIndexInverseModelMatrixX;
  p_parmIndexInverseModelMatrixW = &this->parmIndexInverseModelMatrixW;
  p_parmIndexInverseModelMatrixZ = &this->parmIndexInverseModelMatrixZ;
  if ( ((this->onParmBlockStack[this->parmIndexInverseModelMatrixX]
       | this->onParmBlockStack[this->parmIndexInverseModelMatrixY]
       | this->onParmBlockStack[this->parmIndexInverseModelMatrixW]
       | this->onParmBlockStack[this->parmIndexInverseModelMatrixZ])
      & this->parmStack.virtualParmBlockStackMask) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  idRenderMatrix::CopyMatrix(
    matrix: inverseModelMatrix,
    row0: (idVec4 *)&this->values[*p_parmIndexInverseModelMatrixX],
    row1: (idVec4 *)&this->values[*p_parmIndexInverseModelMatrixY],
    row2: (idVec4 *)&this->values[*p_parmIndexInverseModelMatrixZ],
    row3: (idVec4 *)&this->values[*p_parmIndexInverseModelMatrixW]);
  fragmentParmVersion = this->fragmentParmVersion;
  vertexParmVersion = this->vertexParmVersion;
  textureParmVersion = this->textureParmVersion;
  v11 = LODWORD(this->renderParmVersion) + 1;
  HIDWORD(fragmentParmVersion) = this->parmUsageMask[*p_parmIndexInverseModelMatrixZ];
  HIDWORD(vertexParmVersion) = this->parmUsageMask[*p_parmIndexInverseModelMatrixX]
                             | this->parmUsageMask[*p_parmIndexInverseModelMatrixY]
                             | this->parmUsageMask[*p_parmIndexInverseModelMatrixW];
  this->renderParmVersion = *(unsigned __int64 *)((char *)&textureParmVersion - 4);
  HIDWORD(textureParmVersion) = (HIDWORD(vertexParmVersion) | HIDWORD(fragmentParmVersion)) & 2;
  v12 = (HIDWORD(vertexParmVersion) | HIDWORD(fragmentParmVersion)) & 4;
  HIDWORD(fragmentParmVersion) = (HIDWORD(vertexParmVersion) | HIDWORD(fragmentParmVersion)) & 1;
  HIDWORD(textureParmVersion) += fragmentParmVersion;
  LODWORD(v13) = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  LODWORD(fragmentParmVersion) = v12 + textureParmVersion;
  this->fragmentParmVersion = *(unsigned __int64 *)((char *)&fragmentParmVersion - 4);
  this->vertexParmVersion = v13;
  this->textureParmVersion = fragmentParmVersion;
}


// ========================================================================
// ?SetMVPMatrixForInverseProject@idParmState@@QAAXABVidRenderMatrix@@0@Z
// EA  : 0x828DFD58
// RVA : 0x008DFD58
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetMVPMatrixForInverseProject(
        idParmState *this,
        const idRenderMatrix *mvp,
        const idRenderMatrix *inverseProject)
{
  int *p_parmIndexMVPMatrixY; // r30
  int *p_parmIndexMVPMatrixX; // r29
  int *p_parmIndexMVPMatrixW; // r28
  int *p_parmIndexMVPMatrixZ; // r27
  unsigned __int64 vertexParmVersion; // r6 OVERLAPPED
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  int v13; // r3
  int v14; // r11
  int v15; // r11
  __int128 v16; // r4
  int v17; // r11

  p_parmIndexMVPMatrixY = &this->parmIndexMVPMatrixY;
  p_parmIndexMVPMatrixX = &this->parmIndexMVPMatrixX;
  p_parmIndexMVPMatrixW = &this->parmIndexMVPMatrixW;
  p_parmIndexMVPMatrixZ = &this->parmIndexMVPMatrixZ;
  if ( ((this->onParmBlockStack[this->parmIndexMVPMatrixX]
       | this->onParmBlockStack[this->parmIndexMVPMatrixY]
       | this->onParmBlockStack[this->parmIndexMVPMatrixW]
       | this->onParmBlockStack[this->parmIndexMVPMatrixZ])
      & this->parmStack.virtualParmBlockStackMask) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  idRenderMatrix::SetMVPForInverseProject(
    mvp,
    inverseProject,
    row0: (idVec4 *)&this->values[*p_parmIndexMVPMatrixX],
    row1: (idVec4 *)&this->values[*p_parmIndexMVPMatrixY],
    row2: (idVec4 *)&this->values[*p_parmIndexMVPMatrixZ],
    row3: (idVec4 *)&this->values[*p_parmIndexMVPMatrixW],
    negativeDeterminant: &this->currentMVPHasNegativeDeterminant);
  vertexParmVersion = this->vertexParmVersion;
  fragmentParmVersion = this->fragmentParmVersion;
  textureParmVersion = this->textureParmVersion;
  HIDWORD(fragmentParmVersion) = LODWORD(this->renderParmVersion) + 1;
  v13 = this->parmUsageMask[*p_parmIndexMVPMatrixZ];
  v14 = HIDWORD(textureParmVersion) | this->parmUsageMask[*p_parmIndexMVPMatrixW];
  this->renderParmVersion = *(unsigned __int64 *)((char *)&vertexParmVersion - 4);
  HIDWORD(fragmentParmVersion) = (v14 | v13) & 1;
  HIDWORD(textureParmVersion) = (v14 | v13) & 2;
  v15 = (v14 | v13) & 4;
  LODWORD(v16) = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  DWORD2(v16) = HIDWORD(textureParmVersion) + fragmentParmVersion;
  v17 = v15 + textureParmVersion;
  this->vertexParmVersion = v16;
  this->fragmentParmVersion = *(_QWORD *)((char *)&v16 + 4);
  this->textureParmVersion = *(unsigned __int64 *)((char *)&textureParmVersion - 4);
}


// ========================================================================
// ?SetMVPMatrixForBounds@idParmState@@QAAXABVidRenderMatrix@@ABVidBounds@@@Z
// EA  : 0x828E0F20
// RVA : 0x008E0F20
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetMVPMatrixForBounds(
        idParmState *this,
        const idRenderMatrix *mvp,
        const idBounds *bounds)
{
  int *p_parmIndexMVPMatrixY; // r30
  int *p_parmIndexMVPMatrixX; // r29
  int *p_parmIndexMVPMatrixW; // r28
  int *p_parmIndexMVPMatrixZ; // r27
  unsigned __int64 vertexParmVersion; // r6 OVERLAPPED
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  int v13; // r3
  int v14; // r11
  int v15; // r11
  __int128 v16; // r4
  int v17; // r11

  p_parmIndexMVPMatrixY = &this->parmIndexMVPMatrixY;
  p_parmIndexMVPMatrixX = &this->parmIndexMVPMatrixX;
  p_parmIndexMVPMatrixW = &this->parmIndexMVPMatrixW;
  p_parmIndexMVPMatrixZ = &this->parmIndexMVPMatrixZ;
  if ( ((this->onParmBlockStack[this->parmIndexMVPMatrixX]
       | this->onParmBlockStack[this->parmIndexMVPMatrixY]
       | this->onParmBlockStack[this->parmIndexMVPMatrixW]
       | this->onParmBlockStack[this->parmIndexMVPMatrixZ])
      & this->parmStack.virtualParmBlockStackMask) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  idRenderMatrix::SetMVPForBounds(
    mvp,
    bounds,
    row0: (idVec4 *)&this->values[*p_parmIndexMVPMatrixX],
    row1: (idVec4 *)&this->values[*p_parmIndexMVPMatrixY],
    row2: (idVec4 *)&this->values[*p_parmIndexMVPMatrixZ],
    row3: (idVec4 *)&this->values[*p_parmIndexMVPMatrixW],
    negativeDeterminant: &this->currentMVPHasNegativeDeterminant);
  vertexParmVersion = this->vertexParmVersion;
  fragmentParmVersion = this->fragmentParmVersion;
  textureParmVersion = this->textureParmVersion;
  HIDWORD(fragmentParmVersion) = LODWORD(this->renderParmVersion) + 1;
  v13 = this->parmUsageMask[*p_parmIndexMVPMatrixZ];
  v14 = HIDWORD(textureParmVersion) | this->parmUsageMask[*p_parmIndexMVPMatrixW];
  this->renderParmVersion = *(unsigned __int64 *)((char *)&vertexParmVersion - 4);
  HIDWORD(fragmentParmVersion) = (v14 | v13) & 1;
  HIDWORD(textureParmVersion) = (v14 | v13) & 2;
  v15 = (v14 | v13) & 4;
  LODWORD(v16) = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  DWORD2(v16) = HIDWORD(textureParmVersion) + fragmentParmVersion;
  v17 = v15 + textureParmVersion;
  this->vertexParmVersion = v16;
  this->fragmentParmVersion = *(_QWORD *)((char *)&v16 + 4);
  this->textureParmVersion = *(unsigned __int64 *)((char *)&textureParmVersion - 4);
}


// ========================================================================
// ?SetMVPMatrixFlipped@idParmState@@QAAXABVidRenderMatrix@@@Z
// EA  : 0x82946688
// RVA : 0x00946688
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParmState::SetMVPMatrixFlipped(idParmState *this, const idRenderMatrix *mvp)
{
  int *p_parmIndexMVPMatrixY; // r30
  int *p_parmIndexMVPMatrixX; // r29
  int *p_parmIndexMVPMatrixW; // r28
  int *p_parmIndexMVPMatrixZ; // r27
  unsigned __int8 v8; // r3
  unsigned __int8 v9; // r4
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  unsigned __int64 vertexParmVersion; // r6
  int v13; // r11
  char v14; // r4
  unsigned __int64 v15; // r3

  p_parmIndexMVPMatrixY = &this->parmIndexMVPMatrixY;
  p_parmIndexMVPMatrixX = &this->parmIndexMVPMatrixX;
  p_parmIndexMVPMatrixW = &this->parmIndexMVPMatrixW;
  p_parmIndexMVPMatrixZ = &this->parmIndexMVPMatrixZ;
  if ( ((this->onParmBlockStack[this->parmIndexMVPMatrixX]
       | this->onParmBlockStack[this->parmIndexMVPMatrixY]
       | this->onParmBlockStack[this->parmIndexMVPMatrixW]
       | this->onParmBlockStack[this->parmIndexMVPMatrixZ])
      & this->parmStack.virtualParmBlockStackMask) != 0 )
    idParmState::RollbackVirtualStack(this, renderParmChange: true);
  idRenderMatrix::SetMVP(
    mvp,
    row0: (idVec4 *)&this->values[*p_parmIndexMVPMatrixX],
    row1: (idVec4 *)&this->values[*p_parmIndexMVPMatrixY],
    row2: (idVec4 *)&this->values[*p_parmIndexMVPMatrixZ],
    row3: (idVec4 *)&this->values[*p_parmIndexMVPMatrixW],
    negativeDeterminant: &this->currentMVPHasNegativeDeterminant);
  this->values[*p_parmIndexMVPMatrixY].value[1] = -this->values[*p_parmIndexMVPMatrixY].value[1];
  this->values[*p_parmIndexMVPMatrixY].value[3] = -this->values[*p_parmIndexMVPMatrixY].value[3];
  v8 = this->parmUsageMask[*p_parmIndexMVPMatrixW];
  v9 = this->parmUsageMask[*p_parmIndexMVPMatrixZ];
  fragmentParmVersion = this->fragmentParmVersion;
  textureParmVersion = this->textureParmVersion;
  vertexParmVersion = this->vertexParmVersion;
  *(unsigned __int64 *)((char *)&textureParmVersion - 4) = this->renderParmVersion;
  v13 = LODWORD(this->renderParmVersion) + 1;
  this->renderParmVersion = *(unsigned __int64 *)((char *)&textureParmVersion - 4);
  v14 = BYTE3(textureParmVersion) | BYTE3(vertexParmVersion) | v8 | v9;
  HIDWORD(fragmentParmVersion) = v14 & 1;
  HIDWORD(textureParmVersion) = (v14 & 2) + fragmentParmVersion;
  LODWORD(v15) = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  LODWORD(fragmentParmVersion) = (v14 & 4) + textureParmVersion;
  this->fragmentParmVersion = *(unsigned __int64 *)((char *)&fragmentParmVersion - 4);
  this->vertexParmVersion = v15;
  this->textureParmVersion = fragmentParmVersion;
}

