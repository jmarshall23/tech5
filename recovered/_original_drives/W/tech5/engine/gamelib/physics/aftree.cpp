
// ========================================================================
// ?Solve@idAFTree@@QBAXH@Z
// EA  : 0x82729148
// RVA : 0x00729148
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void __fastcall idAFTree::Solve(idAFTree *this, int auxiliaryIndex)
{
  int v4; // r25
  int v5; // r26
  int v6; // r27
  idAFBody *v7; // r31
  int v8; // r28
  idAFBody *v9; // r11
  idAFConstraint *primaryConstraint; // r30
  const idSpatialVec *p_lm; // r5
  int v12; // r28
  bool v13; // r27
  int v14; // r29
  idAFBody *v15; // r31
  idAFConstraint *v16; // r30
  idAFBody *body2; // r11

  v4 = this->sortedBodies.num - 1;
  if ( v4 >= 0 )
  {
    v5 = v4;
    while ( 1 )
    {
      v6 = 0;
      v7 = this->sortedBodies.list[v5];
      if ( v7->children.num > 0 )
        break;
LABEL_11:
      --v4;
      --v5;
      if ( v4 < 0 )
        goto LABEL_12;
    }
    v8 = 0;
    while ( 1 )
    {
      v9 = v7->children.list[v8];
      primaryConstraint = v9->primaryConstraint;
      if ( (*(_BYTE *)&v9->fl & 4) == 0 )
        break;
      if ( (*(_BYTE *)&primaryConstraint->fl & 8) == 0 )
      {
        p_lm = &primaryConstraint->lm;
        *(_BYTE *)&v7->fl &= ~4u;
        goto LABEL_9;
      }
LABEL_10:
      ++v6;
      ++v8;
      if ( v6 >= v7->children.num )
        goto LABEL_11;
    }
    *(_BYTE *)&primaryConstraint->fl &= ~8u;
    idSpatialMat::TransposeMultiplySub(this: &v9->J, dst: &primaryConstraint->lm, vec: &v9->s);
    p_lm = &primaryConstraint->lm;
    *(_BYTE *)&v7->fl &= ~4u;
LABEL_9:
    idSpatialMat::TransposeMultiplySub(this: &primaryConstraint->J, dst: &v7->s, vec: p_lm);
    goto LABEL_10;
  }
LABEL_12:
  v12 = 0;
  v13 = af_useSymmetry.valueInteger != 0;
  if ( this->sortedBodies.num > 0 )
  {
    v14 = 0;
    do
    {
      v15 = this->sortedBodies.list[v14];
      v16 = v15->primaryConstraint;
      if ( v16 != nullptr )
      {
        if ( v15->parent->maxSubTreeAuxiliaryIndex >= auxiliaryIndex || !v13 )
        {
          if ( (*(_BYTE *)&v16->fl & 8) == 0 )
            idSpatialMat::Multiply(this: &v16->invI, dst: &v16->lm, vec: &v16->lm);
          body2 = v16->body2;
          if ( (*(_BYTE *)&body2->fl & 4) == 0 )
          {
            *(_BYTE *)&v16->fl &= ~8u;
            idSpatialMat::MultiplySub(this: &v16->J, dst: &v16->lm, vec: &body2->s);
          }
          if ( (v15->maxSubTreeAuxiliaryIndex >= auxiliaryIndex || !v13) && v15->children.num != 0 )
          {
            if ( (*(_BYTE *)&v15->fl & 4) == 0 )
              idSpatialMat::Multiply(this: &v15->invI, dst: &v15->s, vec: &v15->s);
            if ( (*(_BYTE *)&v16->fl & 8) == 0 )
            {
              *(_BYTE *)&v15->fl &= ~4u;
              idSpatialMat::MultiplySub(this: &v15->J, dst: &v15->s, vec: &v16->lm);
            }
          }
        }
      }
      else if ( v15->children.num != 0 && (*(_BYTE *)&v15->fl & 4) == 0 )
      {
        idSpatialMat::Multiply(this: &v15->invI, dst: &v15->s, vec: &v15->s);
      }
      ++v12;
      ++v14;
    }
    while ( v12 < this->sortedBodies.num );
  }
}


// ========================================================================
// ?SetMaxSubTreeAuxiliaryIndex@idAFTree@@QAAXXZ
// EA  : 0x827293A0
// RVA : 0x007293A0
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void __fastcall idAFTree::SetMaxSubTreeAuxiliaryIndex(idAFTree *this)
{
  int v1; // r5
  int v2; // r6
  int v3; // r8
  idAFBody *v4; // r11
  int num; // r9
  idAFBody **list; // r7
  int v7; // r10
  int maxSubTreeAuxiliaryIndex; // r9

  v1 = this->sortedBodies.num - 1;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = 0;
      v4 = this->sortedBodies.list[v2];
      num = v4->children.num;
      v4->maxSubTreeAuxiliaryIndex = v4->maxAuxiliaryIndex;
      if ( num > 0 )
      {
        list = v4->children.list;
        v7 = 0;
        do
        {
          maxSubTreeAuxiliaryIndex = list[v7]->maxSubTreeAuxiliaryIndex;
          if ( maxSubTreeAuxiliaryIndex > v4->maxSubTreeAuxiliaryIndex )
            v4->maxSubTreeAuxiliaryIndex = maxSubTreeAuxiliaryIndex;
          ++v3;
          ++v7;
        }
        while ( v3 < v4->children.num );
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
  }
}


// ========================================================================
// ?DebugDraw@idAFTree@@QBAXABVidVec4@@@Z
// EA  : 0x82729418
// RVA : 0x00729418
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void __fastcall idAFTree::DebugDraw(idAFTree *this, const idVec4 *color)
{
  int v4; // r31
  int v5; // r30
  idAFBody *v6; // r26
  idRenderWorld *v7; // r3

  v4 = 1;
  if ( this->sortedBodies.num > 1 )
  {
    v5 = 1;
    do
    {
      v6 = this->sortedBodies.list[v5];
      v7 = common->RW(this: common);
      ((void (__fastcall *)(idRenderWorld *, const idVec4 *, idVec3 *, idVec3 *, double))v7->DebugArrow)(
        a1: v7,
        a2: color,
        a3: &v6->parent->clipModel->origin,
        a4: &v6->clipModel->origin,
        a5: 1.0);
      ++v4;
      ++v5;
    }
    while ( v4 < this->sortedBodies.num );
  }
}


// ========================================================================
// ?Factor@idAFTree@@QBAXXZ
// EA  : 0x827295E0
// RVA : 0x007295E0
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void __fastcall idAFTree::Factor(idAFTree *this)
{
  int v2; // r21
  int v3; // r22
  idAFBody *v4; // r29
  int v5; // r26
  int v6; // r27
  idAFConstraint *primaryConstraint; // r30
  idSpatialMat *p_invI; // r28
  idSpatialMat *p_J; // r30
  idSpatialMat *p_inverseWorldSpatialInertia; // r3
  float v11[72]; // [sp+50h] [-2E0h] BYREF
  float v12[72]; // [sp+170h] [-1C0h] BYREF
  int num; // [sp+290h] [-A0h]
  idSpatialMat v14; // [sp+2A0h] [-90h] BYREF
  idSpatialMat v15[8]; // [sp+2B0h] [-80h] BYREF

  memset(v15, 0, 16);
  v11[52] = v12[52];
  idSpatialMat::SetData(this: v15, rows: 6, columns: 6, data: v12);
  memset(&v14, 0, sizeof(v14));
  idSpatialMat::SetData(this: &v14, rows: 6, columns: 6, data: v11);
  v2 = this->sortedBodies.num - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    while ( 1 )
    {
      v4 = this->sortedBodies.list[v3];
      num = v4->children.num;
      if ( num != 0 )
        break;
      if ( v4->primaryConstraint != nullptr )
      {
        p_inverseWorldSpatialInertia = &v4->inverseWorldSpatialInertia;
LABEL_15:
        idSpatialMat::Multiply(this: p_inverseWorldSpatialInertia, dst: &v14, a: &v4->J);
        idSpatialMat::operator=(this: &v4->J, a: &v14);
      }
LABEL_16:
      --v2;
      --v3;
      if ( v2 < 0 )
        goto LABEL_17;
    }
    v5 = 0;
    if ( num > 0 )
    {
      v6 = 0;
      do
      {
        primaryConstraint = v4->children.list[v6]->primaryConstraint;
        idSpatialMat::TransposeMultiply(this: &primaryConstraint->body1->J, dst: &v14, a: &primaryConstraint->body1->I);
        idSpatialMat::Multiply(this: &v14, dst: v15, a: &primaryConstraint->body1->J);
        idSpatialMat::Negate(this: v15);
        p_invI = &primaryConstraint->invI;
        if ( !idSpatialMat::Inverse(this: v15, dst: &primaryConstraint->invI) )
          idLib::Warning(
            fmt: "idAFTree::Factor: couldn't invert %dx%d matrix for constraint '%s'",
            p_invI->numRows,
            primaryConstraint->invI.numColumns,
            primaryConstraint->name.str);
        p_J = &primaryConstraint->J;
        idSpatialMat::Multiply(this: p_invI, dst: &v14, a: p_J);
        idSpatialMat::operator=(this: p_J, a: &v14);
        idSpatialMat::TransposeMultiply(this: p_J, dst: &v14, a: v15);
        idSpatialMat::Multiply(this: &v14, dst: v15, a: p_J);
        idSpatialMat::Subtract(this: &v4->I, a: v15);
        ++v5;
        ++v6;
      }
      while ( v5 < v4->children.num );
    }
    if ( !idSpatialMat::Inverse(this: &v4->I, dst: &v4->invI) )
      idLib::Warning(
        fmt: "idAFTree::Factor: couldn't invert %dx%d matrix for body %s",
        v4->invI.numRows,
        v4->invI.numColumns,
        v4->name.str);
    if ( v4->primaryConstraint == nullptr )
      goto LABEL_16;
    p_inverseWorldSpatialInertia = &v4->invI;
    goto LABEL_15;
  }
LABEL_17:
  if ( v14.mat != nullptr && v14.allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: v14.mat, align: ALIGN_16);
  if ( v15[0].mat != nullptr && v15[0].allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: v15[0].mat, align: ALIGN_16);
}


// ========================================================================
// __unwind$246498
// EA  : 0x8272984C
// RVA : 0x0072984C
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void _unwind_246498()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$246499
// EA  : 0x82729874
// RVA : 0x00729874
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void _unwind_246499()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(v0 - 240 + 96));
}


// ========================================================================
// ?Response@idAFTree@@QBAXPBVidAFConstraint@@HH@Z
// EA  : 0x827298A8
// RVA : 0x007298A8
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void __fastcall idAFTree::Response(idAFTree *this, const idAFConstraint *constraint, int row, int auxiliaryIndex)
{
  idAFBody *body1; // r11
  int v11; // r10
  int v16; // r9
  int v17; // r8
  idAFBody *v18; // r11
  idAFConstraint *primaryConstraint; // r10
  idAFBody *v25; // r29
  idSpatialMat *v26; // r3
  float *mat; // r10
  float *numColumns; // r9
  float *p; // r8
  idAFConstraint *v31; // r11
  int v32; // r27
  int v33; // r28
  idAFConstraint *v34; // r11
  idAFBody *body2; // r29
  idSpatialMat *v40; // r3
  float *v42; // r10
  float *v43; // r9
  float *v44; // r8
  idAFConstraint *v45; // r11
  int v46; // r27
  int v47; // r28
  idAFConstraint *v48; // r11
  float *v53; // r4
  int v54; // r26
  BOOL v55; // r25
  int v56; // r27
  idAFBody *v57; // r30
  idAFConstraint *v58; // r11
  int v59; // r28
  int v60; // r29
  idAFConstraint *v61; // r11
  idSpatialVec v62; // [sp+50h] [-B0h] BYREF
  idSpatialMat v63; // [sp+58h] [-A8h] BYREF
  idSpatialVec v64[2]; // [sp+70h] [-90h] BYREF
  float v65; // [sp+80h] [-80h] BYREF

  *(_DWORD *)&v62.size = this->sortedBodies.num;
  _R30 = 16;
  if ( *(_DWORD *)&v62.size == 1 )
  {
    body1 = constraint->body1;
    v11 = 8 * row;
    if ( body1->tree == this )
    {
      _R10 = &constraint->J1.mat[v11];
      _R9 = (int)&body1->response[8 * body1->numResponses];
      __asm
      {
        lvx128    v63, r0, r10
        stvx128   v63, r0, r9
        lvx128    v62, r10, r30
        stvx128   v62, r9, r30
      }
    }
    else
    {
      body1 = constraint->body2;
      _R10 = &constraint->J2.mat[v11];
      __asm { lvx128    v61, r0, r10 }
      _R9 = (int)&body1->response[8 * body1->numResponses];
      __asm
      {
        stvx128   v61, r0, r9
        lvx128    v60, r10, r30
        stvx128   v60, r9, r30
      }
    }
    body1->responseIndex[body1->numResponses++] = auxiliaryIndex;
  }
  else
  {
    v16 = 0;
    if ( *(int *)&v62.size > 0 )
    {
      __asm { vspltisw128 v63, 0 }
      v17 = 0;
      do
      {
        v18 = this->sortedBodies.list[v17];
        primaryConstraint = v18->primaryConstraint;
        if ( primaryConstraint != nullptr )
        {
          _R6 = primaryConstraint->lm.p;
          __asm { stvx128   v63, r0, r6 }
          _R5 = _R6;
          __asm { stvx128   v63, r5, r30 }
          *(_BYTE *)&primaryConstraint->fl |= 8u;
        }
        _R7 = v18->s.p;
        ++v16;
        ++v17;
        __asm { stvx128   v63, r0, r7 }
        _R6 = _R7;
        __asm { stvx128   v63, r6, r30 }
        _R10 = (int)&v18->response[8 * v18->numResponses];
        *(_BYTE *)&v18->fl |= 4u;
        __asm
        {
          stvx128   v63, r0, r10
          stvx128   v63, r10, r30
        }
      }
      while ( v16 < this->sortedBodies.num );
    }
    v64[0].allocated = 0;
    v64[0].size = 0;
    v64[0].p = nullptr;
    idSpatialVec::SetData(this: v64, length: 6, data: &v65);
    v25 = constraint->body1;
    if ( v25->tree == this )
    {
      v26 = idSpatialMat::SubSpatialVec(this: &v63, result: (const idSpatialVec *)&constraint->J1, row);
      mat = v25->inverseWorldSpatialInertia.mat;
      numColumns = (float *)v26->numColumns;
      p = v64[0].p;
      *v64[0].p = *mat * *numColumns;
      p[1] = mat[9] * numColumns[1];
      p[2] = mat[18] * numColumns[2];
      p[3] = (float)(mat[27] * numColumns[3])
           + (float)((float)(mat[29] * numColumns[5]) + (float)(mat[28] * numColumns[4]));
      p[4] = (float)(mat[35] * numColumns[3])
           + (float)((float)(mat[37] * numColumns[5]) + (float)(mat[36] * numColumns[4]));
      p[5] = (float)(mat[43] * numColumns[3])
           + (float)((float)(mat[45] * numColumns[5]) + (float)(mat[44] * numColumns[4]));
      if ( v63.numColumns != 0 && SLOWORD(v63.numRows) > 0 )
        idMem::Free(this: &mem, ptr: (void *)v63.numColumns, align: ALIGN_16);
      v31 = v25->primaryConstraint;
      if ( v31 != nullptr )
      {
        *(_BYTE *)&v31->fl &= ~8u;
        idSpatialMat::Multiply(this: &v31->J1, dst: &v31->lm, vec: v64);
      }
      v32 = 0;
      if ( v25->children.num > 0 )
      {
        v33 = 0;
        do
        {
          v34 = v25->children.list[v33]->primaryConstraint;
          *(_BYTE *)&v34->fl &= ~8u;
          idSpatialMat::Multiply(this: &v34->J2, dst: &v34->lm, vec: v64);
          ++v32;
          ++v33;
        }
        while ( v32 < v25->children.num );
      }
      _R9 = v25->response;
      _R11 = &constraint->J1.mat[8 * row];
      _R8 = 8 * v25->numResponses;
      _R10 = &_R9[_R8];
      __asm
      {
        lvx128    v59, r0, r11
        stvx128   v59, r8, r9
        lvx128    v58, r11, r30
        stvx128   v58, r10, r30
      }
    }
    body2 = constraint->body2;
    if ( body2 != nullptr && body2->tree == this )
    {
      v40 = idSpatialMat::SubSpatialVec(
              this: (idSpatialMat *)&v63.allocatedRows,
              result: (const idSpatialVec *)&constraint->J2,
              row);
      v42 = body2->inverseWorldSpatialInertia.mat;
      v43 = (float *)v40->numColumns;
      v44 = v64[0].p;
      *v64[0].p = *v42 * *v43;
      v44[1] = v43[1] * v42[9];
      v44[2] = v43[2] * v42[18];
      v44[3] = (float)(v42[29] * v43[5]) + (float)((float)(v42[28] * v43[4]) + (float)(v42[27] * v43[3]));
      v44[4] = (float)(v42[37] * v43[5]) + (float)((float)(v42[36] * v43[4]) + (float)(v42[35] * v43[3]));
      v44[5] = (float)(v42[45] * v43[5]) + (float)((float)(v42[44] * v43[4]) + (float)(v42[43] * v43[3]));
      if ( v63.mat != nullptr && SLOWORD(v63.allocatedRows) > 0 )
        idMem::Free(this: &mem, ptr: v63.mat, align: ALIGN_16);
      v45 = body2->primaryConstraint;
      if ( v45 != nullptr )
      {
        *(_BYTE *)&v45->fl &= ~8u;
        idSpatialMat::MultiplyAdd(this: &v45->J1, dst: &v45->lm, vec: v64);
      }
      v46 = 0;
      if ( body2->children.num > 0 )
      {
        v47 = 0;
        do
        {
          v48 = body2->children.list[v47]->primaryConstraint;
          *(_BYTE *)&v48->fl &= ~8u;
          idSpatialMat::MultiplyAdd(this: &v48->J2, dst: &v48->lm, vec: v64);
          ++v46;
          ++v47;
        }
        while ( v46 < body2->children.num );
      }
      _R11 = &constraint->J2.mat[8 * row];
      _R9 = body2->response;
      _R8 = 8 * body2->numResponses;
      _R10 = &_R9[_R8];
      __asm
      {
        lvx128    v57, r0, r11
        stvx128   v57, r8, r9
        lvx128    v56, r11, r30
        stvx128   v56, r10, r30
      }
    }
    idAFTree::Solve(this, auxiliaryIndex);
    v53 = nullptr;
    v62.allocated = 0;
    v62.size = 0;
    v62.p = nullptr;
    v54 = 0;
    if ( this->sortedBodies.num > 0 )
    {
      v55 = af_useSymmetry.valueInteger != 0;
      v56 = 0;
      do
      {
        v57 = this->sortedBodies.list[v56];
        if ( !v55 || v57->maxAuxiliaryIndex >= auxiliaryIndex )
        {
          idSpatialVec::SetData(this: &v62, length: 6, data: &v57->response[8 * v57->numResponses]);
          v58 = v57->primaryConstraint;
          if ( v58 != nullptr )
            idSpatialMat::TransposeMultiplyAdd(this: &v58->J1, dst: &v62, vec: &v58->lm);
          v59 = 0;
          if ( v57->children.num > 0 )
          {
            v60 = 0;
            do
            {
              v61 = v57->children.list[v60]->primaryConstraint;
              idSpatialMat::TransposeMultiplyAdd(this: &v61->J2, dst: &v62, vec: &v61->lm);
              ++v59;
              ++v60;
            }
            while ( v59 < v57->children.num );
          }
          v57->responseIndex[v57->numResponses++] = auxiliaryIndex;
        }
        ++v54;
        ++v56;
      }
      while ( v54 < this->sortedBodies.num );
      v53 = v62.p;
    }
    if ( v53 != nullptr && v62.allocated > 0 )
      idMem::Free(this: &mem, ptr: v53, align: ALIGN_16);
    if ( v64[0].p != nullptr && v64[0].allocated > 0 )
      idMem::Free(this: &mem, ptr: v64[0].p, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$246599
// EA  : 0x82729F0C
// RVA : 0x00729F0C
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void _unwind_246599()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$246602
// EA  : 0x82729F34
// RVA : 0x00729F34
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void _unwind_246602()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(v0 - 256 + 80));
}


// ========================================================================
// ?CalculateForces@idAFTree@@QBAXM@Z
// EA  : 0x82729F60
// RVA : 0x00729F60
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void __fastcall idAFTree::CalculateForces(idAFTree *this, double timeStep)
{
  int num; // r11
  int v6; // r8
  int v7; // r9
  char *v8; // r11
  idAFBody *v9; // r6
  int v10; // ctr
  float *p; // r5
  float *v12; // r10
  double v13; // fp5
  double v14; // fp0
  double v15; // fp3
  double v16; // fp12
  double v17; // fp10
  int v18; // r25
  double v19; // fp31
  int v20; // r26
  idAFBody *v22; // r30
  float *v23; // r10
  float *mat; // r9
  float *v25; // r8
  float *v26; // r7
  double v27; // fp10
  double v28; // fp8
  double v29; // fp11
  double v30; // fp6
  double v31; // fp5
  double v32; // fp9
  double v33; // fp7
  double v34; // fp12
  double v35; // fp4
  double v36; // fp13
  idAFConstraint *primaryConstraint; // r31
  int numRows; // r4
  int v46; // r26
  int v47; // r27
  idAFBody *v48; // r31
  idAFConstraint *v49; // r11
  int v50; // r29
  int v51; // r30
  idAFConstraint *v52; // r11
  float v54; // [sp+50h] [-90h] BYREF
  char v55; // [sp+5Ch] [-84h] BYREF
  float v56; // [sp+60h] [-80h]
  float v57; // [sp+64h] [-7Ch]
  float v58; // [sp+68h] [-78h]
  float v59; // [sp+6Ch] [-74h]
  float v60; // [sp+70h] [-70h]
  float v61; // [sp+74h] [-6Ch]

  _R12 = -96;
  __asm { stvx128   v127, r1, r12 }
  num = this->sortedBodies.num;
  v6 = 0;
  if ( num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &v55;
      v9 = this->sortedBodies.list[v7];
      v10 = 6;
      p = v9->auxForce.p;
      v12 = v9->totalForce.p - 1;
      v13 = (float)(v9->current.externalForce.p[1] + p[1]);
      v14 = (float)(v9->current.externalForce.p[3] + p[3]);
      v15 = (float)(v9->current.externalForce.p[2] + p[2]);
      v16 = (float)(v9->current.externalForce.p[4] + p[4]);
      v17 = (float)(v9->current.externalForce.p[5] + p[5]);
      v56 = v9->current.externalForce.p[0] + *p;
      v57 = v13;
      v58 = v15;
      v59 = v14;
      v60 = v16;
      v61 = v17;
      do
      {
        v8 += 4;
        *++v12 = *(float *)v8;
        --v10;
      }
      while ( v10 != 0 );
      num = this->sortedBodies.num;
      ++v6;
      ++v7;
    }
    while ( v6 < num );
  }
  if ( num != 1 )
  {
    v18 = 0;
    v19 = (float)((float)1.0 / (float)timeStep);
    v54 = (float)1.0 / (float)timeStep;
    if ( num > 0 )
    {
      __asm { vspltisw128 v127, 0 }
      v20 = 0;
      _R28 = 16;
      do
      {
        v22 = this->sortedBodies.list[v20];
        v23 = v22->totalForce.p;
        mat = v22->inverseWorldSpatialInertia.mat;
        v25 = v22->acceleration.p;
        *v25 = *v23 * *mat;
        v25[1] = mat[9] * v23[1];
        v25[2] = mat[18] * v23[2];
        v25[3] = (float)(mat[27] * v23[3]) + (float)((float)(mat[29] * v23[5]) + (float)(mat[28] * v23[4]));
        v25[4] = (float)(mat[35] * v23[3]) + (float)((float)(mat[37] * v23[5]) + (float)(mat[36] * v23[4]));
        v25[5] = (float)(mat[43] * v23[3]) + (float)((float)(mat[45] * v23[5]) + (float)(mat[44] * v23[4]));
        v26 = v22->acceleration.p;
        v27 = (float)(v22->current.spatialVelocity.p[0] * (float)v19);
        v28 = (float)(v22->current.spatialVelocity.p[3] * (float)v19);
        v29 = v26[3];
        v30 = (float)(v22->current.spatialVelocity.p[4] * (float)v19);
        v31 = v26[1];
        v32 = v26[4];
        v33 = v26[5];
        v34 = (float)(v22->current.spatialVelocity.p[1] * (float)v19);
        v35 = (float)(v22->current.spatialVelocity.p[5] * (float)v19);
        v36 = *v26;
        v26[2] = (float)(v22->current.spatialVelocity.p[2] * (float)v19) + v26[2];
        *v26 = (float)v36 + (float)v27;
        v26[1] = (float)v31 + (float)v34;
        v26[3] = (float)v29 + (float)v28;
        v26[4] = (float)v32 + (float)v30;
        v26[5] = (float)v33 + (float)v35;
        primaryConstraint = v22->primaryConstraint;
        if ( primaryConstraint != nullptr )
        {
          numRows = primaryConstraint->J1.numRows;
          *(_BYTE *)&primaryConstraint->fl &= ~8u;
          idSpatialVec::SetSize(this: &primaryConstraint->lm, newSize: numRows);
          idSpatialMat::Multiply(
            this: &primaryConstraint->J1,
            dst: &primaryConstraint->lm,
            vec: &primaryConstraint->body1->acceleration);
          idSpatialMat::MultiplyAdd(
            this: &primaryConstraint->J2,
            dst: &primaryConstraint->lm,
            vec: &primaryConstraint->body2->acceleration);
          _R8 = primaryConstraint->c1.p;
          _R7 = primaryConstraint->c2.p;
          _R9 = &v54;
          _R11 = primaryConstraint->lm.p;
          _R10 = _R11 + 4;
          __asm
          {
            lvx128    v62, r8, r28
            lvx128    v61, r7, r28
            lvx128    v60, r0, r7
            vaddfp128 v13, v94, v61
            lvx128    v59, r0, r8
            vaddfp128 v11, v91, v60
            lvlx128   v63, r0, r9
            lvx128    v12, r0, r10
            vspltw128 v0, v63, 0
            lvx128    v10, r0, r11
            vmaddfp   v13, v13, v12, v0
            vmaddfp   v0, v11, v10, v0
            stvx128   v13, r0, r10
            stvx128   v0, r0, r11
          }
        }
        ++v18;
        ++v20;
        *(_BYTE *)&v22->fl |= 4u;
        _R8 = v22->s.p;
        __asm { stvx128   v127, r0, r8 }
        _R7 = _R8;
        __asm { stvx128   v127, r7, r28 }
      }
      while ( v18 < this->sortedBodies.num );
    }
    idAFTree::Solve(this, auxiliaryIndex: 0);
    v46 = 0;
    if ( this->sortedBodies.num > 0 )
    {
      v47 = 0;
      do
      {
        v48 = this->sortedBodies.list[v47];
        v49 = v48->primaryConstraint;
        if ( v49 != nullptr )
          idSpatialMat::TransposeMultiplyAdd(this: &v49->J1, dst: &v48->totalForce, vec: &v49->lm);
        v50 = 0;
        if ( v48->children.num > 0 )
        {
          v51 = 0;
          do
          {
            v52 = v48->children.list[v51]->primaryConstraint;
            idSpatialMat::TransposeMultiplyAdd(this: &v52->J2, dst: &v48->totalForce, vec: &v52->lm);
            ++v50;
            ++v51;
          }
          while ( v50 < v48->children.num );
        }
        ++v46;
        ++v47;
      }
      while ( v46 < this->sortedBodies.num );
    }
  }
  _R0 = -96;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ?SortBodies_r@idAFTree@@AAAXAAV?$idList@PAVidAFBody@@$0EH@@@PAVidAFBody@@@Z
// EA  : 0x8272A328
// RVA : 0x0072A328
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void __fastcall idAFTree::SortBodies_r(
        idAFTree *this,
        idList<idSpawnArea::GeneratedPosition *,5> *sortedList,
        idAFBody *body)
{
  int num; // r11
  int v7; // r27
  int v8; // r30
  idAFBody **list; // r29
  int granularity; // r4
  int size; // r11
  bool v12; // cr58
  signed int v13; // r10
  int v14; // r4
  int v15; // r11
  int v16; // r11
  int v17; // r29
  int v18; // r30

  num = body->children.num;
  v7 = 0;
  if ( num > 0 )
  {
    v8 = 0;
    do
    {
      list = body->children.list;
      if ( sortedList->list != nullptr )
        goto LABEL_7;
      granularity = sortedList->granularity;
      if ( granularity <= 0 )
        granularity = 1;
      if ( idList<idNavSpline *,5>::Resize(this: sortedList, newsize: granularity) )
      {
LABEL_7:
        size = sortedList->size;
        if ( sortedList->num != size )
          goto LABEL_18;
        if ( forceIdListsToReallocateEveryAppend )
        {
          v12 = !idList<idNavSpline *,5>::Resize(this: sortedList, newsize: size + 1);
        }
        else
        {
          v13 = sortedList->granularity;
          if ( sortedList->granularity != 0 )
          {
            v15 = size + v13;
            __twllei(v13, 0);
            __twlgei(v13 & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
            v12 = !idList<idNavSpline *,5>::Resize(this: sortedList, newsize: v15 - v15 % v13);
          }
          else
          {
            v14 = 2 * size;
            if ( 2 * size >= size )
            {
              if ( v14 == 0 )
                v14 = 1;
              v12 = !idList<idNavSpline *,5>::Resize(this: sortedList, newsize: v14);
            }
            else
            {
              v12 = !idList<idNavSpline *,5>::Resize(this: sortedList, newsize: 0x7FFFFFFF);
            }
          }
        }
        if ( !v12 )
        {
LABEL_18:
          v16 = sortedList->num;
          if ( v16 < sortedList->size )
          {
            sortedList->list[v16] = (idSpawnArea::GeneratedPosition *)list[v8];
            ++sortedList->num;
          }
        }
      }
      num = body->children.num;
      ++v7;
      ++v8;
    }
    while ( v7 < num );
  }
  v17 = 0;
  if ( num > 0 )
  {
    v18 = 0;
    do
    {
      idAFTree::SortBodies_r(this, (idList<idAFBody *,71> *)sortedList, body: body->children.list[v18]);
      ++v17;
      ++v18;
    }
    while ( v17 < body->children.num );
  }
}


// ========================================================================
// ?SortBodies@idAFTree@@QAAXXZ
// EA  : 0x8272A4D8
// RVA : 0x0072A4D8
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void __fastcall idAFTree::SortBodies(idAFTree *this)
{
  int num; // r8
  int v3; // r11
  int v4; // r10
  idAFBody **list; // r4
  int v6; // r10
  int listStatic; // r11
  idAFBody *v8; // r30
  idAFBody *v9; // [sp+50h] [-30h] BYREF

  num = this->sortedBodies.num;
  v3 = 0;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      if ( this->sortedBodies.list[v4]->parent == nullptr )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < this->sortedBodies.num );
  }
  if ( v3 >= num )
    idLib::Error(fmt: "Articulated figure tree has no root.");
  list = this->sortedBodies.list;
  v6 = v3;
  v8 = this->sortedBodies.list[v3];
  listStatic = this->sortedBodies.listStatic;
  v9 = this->sortedBodies.list[v6];
  if ( listStatic == 0 || listStatic == 2 )
  {
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->sortedBodies.list = nullptr;
    this->sortedBodies.size = 0;
  }
  this->sortedBodies.num = 0;
  idList<idAnimWebBlendTree *,5>::Append(
    (idList<enum encounterGroupRole_t,5> *)this,
    obj: (const encounterGroupRole_t *)&v9);
  idAFTree::SortBodies_r(this, sortedList: (idList<idSpawnArea::GeneratedPosition *,5> *)this, body: v8);
}


// ========================================================================
// `dynamic initializer for 'af_useSymmetry''
// EA  : 0x83340240
// RVA : 0x01340240
// PDB : w:\tech5\engine\gamelib\physics\aftree.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_useSymmetry__()
{
  idCVar::idCVar(
    this: &af_useSymmetry,
    name: "af_useSymmetry",
    value: "1",
    flags: 1,
    description: "use constraint matrix symmetry",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_useSymmetry__);
}

