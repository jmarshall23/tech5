
// ========================================================================
// ?GetRenderParmFromOps_r@idParmBlock@@ABAXHHAATparmValue_t@@@Z
// EA  : 0x8293A050
// RVA : 0x0093A050
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::GetRenderParmFromOps_r(
        idParmBlock *this,
        int numOps,
        int parmIndex,
        parmValue_t *parmValue)
{
  const idDeclRenderParm *RenderParmForIndex; // r3
  int v9; // r8
  int v10; // r29
  int v11; // r30
  int v12; // r28
  expOp_t *v13; // r11
  int parmIndexDest; // r9
  int parmIndexA; // r5
  int parmIndexB; // r5
  parmValue_t v17; // [sp+50h] [-60h] BYREF
  parmValue_t v18[5]; // [sp+60h] [-50h] BYREF

  RenderParmForIndex = idParmState::GetRenderParmForIndex(this: renderThreadParmState, parmIndex);
  idParmState::CopyParmUnaligned(dst: parmValue, src: &RenderParmForIndex->declaredValue);
  v10 = 0;
  if ( numOps > 0 )
  {
    v11 = 0;
    v12 = 0;
    do
    {
      v13 = &this->ops.list[v11];
      parmIndexDest = v13->parmIndexDest;
      if ( parmIndexDest == parmIndex )
      {
        parmIndexA = v13->parmIndexA;
        if ( parmIndexA != 2047 )
          idParmBlock::GetRenderParmFromOps_r(this, numOps: v10, parmIndex: parmIndexA, parmValue: v18);
        parmIndexB = this->ops.list[v11].parmIndexB;
        if ( parmIndexB != 2047 )
          idParmBlock::GetRenderParmFromOps_r(this, numOps: v10, parmIndex: parmIndexB, parmValue: &v17);
        idParmState::ApplyOp(
          op: &this->ops.list[v11],
          constant: &this->constants.list[v12],
          parmA: v18,
          parmB: &v17,
          result: parmValue,
          a6: v9,
          a7: parmIndexDest,
          a8: (int)this->constants.list);
      }
      ++v10;
      ++v12;
      ++v11;
    }
    while ( v10 < numOps );
  }
}


// ========================================================================
// ?GetFloat@idParmBlock@@QBAMPBVidDeclRenderParm@@@Z
// EA  : 0x8293A140
// RVA : 0x0093A140
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

float __fastcall idParmBlock::GetFloat(idParmBlock *this, const idDeclRenderParm *parm)
{
  double v2; // fp1
  parmValue_t v4; // [sp+50h] [-20h] BYREF

  idParmBlock::GetRenderParmFromOps_r(this, numOps: this->ops.num, parmIndex: parm->parmIndex, parmValue: &v4);
  v2 = v4.value[0];
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?GetInteger@idParmBlock@@QBAHPBVidDeclRenderParm@@@Z
// EA  : 0x8293A178
// RVA : 0x0093A178
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

int __fastcall idParmBlock::GetInteger(idParmBlock *this, const idDeclRenderParm *parm)
{
  parmValue_t v3; // [sp+50h] [-20h] BYREF

  idParmBlock::GetRenderParmFromOps_r(this, numOps: this->ops.num, parmIndex: parm->parmIndex, parmValue: &v3);
  return (int)v3.value[0];
}


// ========================================================================
// ?GetImage@idParmBlock@@QBAPBVidImage@@PBVidDeclRenderParm@@@Z
// EA  : 0x8293A1B8
// RVA : 0x0093A1B8
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

const idImage *__fastcall idParmBlock::GetImage(idParmBlock *this, const idDeclRenderParm *parm)
{
  parmType_t parmType; // r11
  char v3; // r11
  bool v4; // zf
  parmValue_t v6; // [sp+50h] [-20h] BYREF

  parmType = parm->parmType;
  if ( parmType < PT_TEXTURE || (v4 = parmType <= PT_TEXTURE_MULTISAMPLE_2D, v3 = 1, !v4) )
    v3 = 0;
  if ( v3 == 0 )
    idLib::Error(fmt: "idParmBlock::GetImage: %s isn't a texture parm", parm->name.str);
  idParmBlock::GetRenderParmFromOps_r(this, numOps: this->ops.num, parmIndex: parm->parmIndex, parmValue: &v6);
  return (const idImage *)v6.swizzle[0];
}


// ========================================================================
// ?GetString@idParmBlock@@QBAPBDPBVidDeclRenderParm@@@Z
// EA  : 0x8293A220
// RVA : 0x0093A220
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

const char *__fastcall idParmBlock::GetString(idParmBlock *this, const idDeclRenderParm *parm)
{
  parmValue_t v3; // [sp+50h] [-20h] BYREF

  if ( parm->parmType != PT_STRING )
    idLib::Error(fmt: "idParmBlock::GetString: %s isn't a string parm", parm->name.str);
  idParmBlock::GetRenderParmFromOps_r(this, numOps: this->ops.num, parmIndex: parm->parmIndex, parmValue: &v3);
  return (const char *)v3.swizzle[0];
}


// ========================================================================
// ?GetProgram@idParmBlock@@QBAPBVidDeclRenderProg@@PBVidDeclRenderParm@@@Z
// EA  : 0x8293A270
// RVA : 0x0093A270
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

const idDeclRenderProg *__fastcall idParmBlock::GetProgram(idParmBlock *this, const idDeclRenderParm *parm)
{
  parmValue_t v3; // [sp+50h] [-20h] BYREF

  if ( parm->parmType != PT_PROGRAM )
    idLib::Error(fmt: "idParmBlock::GetProgram: %s isn't a program parm", parm->name.str);
  idParmBlock::GetRenderParmFromOps_r(this, numOps: this->ops.num, parmIndex: parm->parmIndex, parmValue: &v3);
  return (const idDeclRenderProg *)v3.swizzle[0];
}


// ========================================================================
// ?GetVector@idParmBlock@@QBA?AVidVec4@@PBVidDeclRenderParm@@@Z
// EA  : 0x8293A2C0
// RVA : 0x0093A2C0
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

idParmBlock *__fastcall idParmBlock::GetVector(idParmBlock *this, idParmBlock *result, const idDeclRenderParm *parm)
{
  double v4; // fp13
  double v6; // fp12
  double v7; // fp11
  parmValue_t v8; // [sp+50h] [-20h] BYREF

  if ( parm->parmType != PT_VECTOR )
    idLib::Error(fmt: "idParmBlock::GetVector: %s isn't a vector parm", parm->name.str);
  idParmBlock::GetRenderParmFromOps_r(this: result, numOps: result->ops.num, parmIndex: parm->parmIndex, parmValue: &v8);
  v4 = v8.value[1];
  v6 = v8.value[2];
  v7 = v8.value[3];
  *(float *)&this->ops.list = v8.value[0];
  *(float *)&this->ops.num = v4;
  *(float *)&this->ops.size = v6;
  *(float *)&this->ops.granularity = v7;
  return this;
}


// ========================================================================
// ?SetsRenderParm@idParmBlock@@QBA_NPBVidDeclRenderParm@@@Z
// EA  : 0x8293A340
// RVA : 0x0093A340
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

int __fastcall idParmBlock::SetsRenderParm(idParmBlock *this, const idDeclRenderParm *parm)
{
  int num; // r7
  int v3; // r10
  int v4; // r11
  expOp_t *list; // r9

  num = this->ops.num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  v4 = 0;
  list = this->ops.list;
  while ( list->parmIndexDest != parm->parmIndex )
  {
    ++v3;
    list = &this->ops.list[++v4];
    if ( v3 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?Clear@idParmBlock@@QAAXXZ
// EA  : 0x8293A398
// RVA : 0x0093A398
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::Clear(idParmBlock *this)
{
  if ( this->thread == THREAD_RENDERER )
    idParmState::RemoveFromVirtualStack(this: renderThreadParmState, parmBlock: this);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constants);
  this->usingTempOps = false;
}


// ========================================================================
// ?GetExpressionTemporaryParm@idParmBlock@@AAAPBVidDeclRenderParm@@XZ
// EA  : 0x8293A400
// RVA : 0x0093A400
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

const idDeclRenderParm *__fastcall idParmBlock::GetExpressionTemporaryParm(
        idParmBlock *this,
        int a2,
        __int64 a3,
        __int64 a4)
{
  int v5; // r11
  __int64 v6; // r10
  int *v7; // r30
  int v8; // r29
  va *v9; // r3
  const idDecl *v10; // r3
  int v11; // r11
  int v13; // [sp+8h] [-10B8h]
  int v14; // [sp+Ch] [-10B4h]
  int v15; // [sp+10h] [-10B0h]
  int v16; // [sp+14h] [-10ACh]
  int v17; // [sp+18h] [-10A8h]
  int v18; // [sp+1Ch] [-10A4h]
  idStr v19; // [sp+50h] [-1070h] BYREF
  va v20; // [sp+70h] [-1050h] BYREF

  v5 = dword_83746A40[0];
  if ( dword_83746A40[0] == 0 )
  {
    LODWORD(v6) = &idDeclReachIK::resourceList.hashTable[243];
    HIDWORD(v6) = "Mips";
    v7 = dword_83746A40;
    do
    {
      v8 = v5 + 1;
      HIDWORD(a3) = v5 + 1;
      v9 = va::va(this: &v20, fmt: "temp%i", a3, a4, a5: v6, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
      idStr::idStr(this: &v19, text: v9);
      if ( v19.data != nullptr )
        v10 = idDeclInfo::FindWithInheritance(this: &idDeclRenderParm::resourceList, name: v19.data, makeDefault: true);
      else
        v10 = nullptr;
      v10[1].name.str = (const char *)2;
      *v7 = (int)v10;
      idStr::FreeData(this: &v19);
      ++v7;
      LODWORD(v6) = &idParmBlockOptimizer::c_retainedOps;
      v5 = v8;
    }
    while ( (int)v7 < (int)&idParmBlockOptimizer::c_retainedOps );
  }
  if ( !this->usingTempOps )
    idLib::Error(fmt: "idParmBlock::GetExpressionTemporaryParm: !usingTempOps");
  v11 = currentTempParm;
  if ( currentTempParm >= 32 )
    idLib::FatalError(fmt: "idParmBlock::GetExpressionTemporaryParm: MAX_EXPRESSION_TEMPS");
  currentTempParm = v11 + 1;
  return (const idDeclRenderParm *)dword_83746A40[v11];
}


// ========================================================================
// $LN25_3
// EA  : 0x8293A4F8
// RVA : 0x0093A4F8
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _LN25_3()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ?Save@idParmBlock@@QBAXPAVidFile@@@Z
// EA  : 0x8293A520
// RVA : 0x0093A520
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::Save(idParmBlock *this, idFile *fp)
{
  idFile_vtbl *v3; // r10
  idFile_vtbl *v5; // r7
  int v6; // r25
  int v7; // r27
  int v8; // r28
  const idDeclRenderParm *Dest; // r29
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  unsigned int (__fastcall *v11)(idFile *, const void *, unsigned int); // ctr
  expOp_t *v12; // r3
  int v13; // r11
  const idDeclTable *Table; // r11
  const idDeclRenderParm *v15; // r3
  const char *str; // r4
  int parmType; // r10
  char v18; // r11
  const idImage *image; // r11
  idFile *v20; // r3
  const char *string; // r4
  bool usingTempOps; // [sp+50h] [-50h] BYREF
  char v23; // [sp+51h] [-4Fh] BYREF
  _BYTE v24[2]; // [sp+52h] [-4Eh] BYREF
  int num; // [sp+54h] [-4Ch] BYREF

  v3 = fp->__vftable;
  usingTempOps = this->usingTempOps;
  v3->Write(this: fp, a2: &usingTempOps, a3: 1u);
  v5 = fp->__vftable;
  num = this->ops.num;
  v5->Write(this: fp, a2: &num, a3: 4u);
  v6 = 0;
  if ( this->ops.num > 0 )
  {
    v7 = 0;
    v8 = 0;
    do
    {
      Dest = expOp_t::GetDest(this: &this->ops.list[v8]);
      Write = fp->Write;
      v23 = this->ops.list[v8].type & 0x1F;
      Write(this: fp, a2: &v23, a3: 1u);
      v11 = fp->Write;
      v24[0] = (this->ops.list[v8].type >> 9) & 0xF;
      v11(this: fp, a2: v24, a3: 1u);
      idFile::WriteString(this: fp, string: Dest->name.str);
      v12 = &this->ops.list[v8];
      v13 = v12->type & 0x1F;
      if ( v13 == 2 || v13 == 0 )
      {
        switch ( Dest->parmType )
        {
          case PT_VECTOR:
            fp->Write(this: fp, a2: &this->constants.list[v7], a3: 16u);
            goto LABEL_32;
          case PT_TEXTURE:
          case PT_TEXTURE_2D:
          case PT_TEXTURE_3D:
          case PT_TEXTURE_CUBE:
          case PT_TEXTURE_SHADOW_2D:
          case PT_TEXTURE_SHADOW_3D:
          case PT_TEXTURE_SHADOW_CUBE:
          case PT_TEXTURE_MULTISAMPLE_2D:
            string = *(const char **)(this->constants.list[v7].swizzle[0] + 8);
            goto LABEL_30;
          case PT_PROGRAM:
            v20 = fp;
            image = this->constants.list[v7].image;
            if ( image != nullptr )
              goto LABEL_23;
            string = &byte_8200D768;
            goto LABEL_31;
          case PT_STRING:
            string = this->constants.list[v7].string;
LABEL_30:
            v20 = fp;
            goto LABEL_31;
          default:
            goto LABEL_32;
        }
      }
      if ( v13 == 20 )
      {
        Table = idParmState::GetTable(this: renderThreadParmState, tableIndex: v12->parmIndexA);
        if ( Table != nullptr )
          idFile::WriteString(this: fp, string: Table->name.str);
        else
          idFile::WriteString(this: fp, string: &byte_8200D768);
      }
      else
      {
        v15 = expOp_t::GetA(this: v12);
        if ( v15 != nullptr )
        {
          parmType = Dest->parmType;
          if ( parmType < 1 || (v18 = 1, parmType > 8) )
            v18 = 0;
          if ( v18 != 0 )
          {
            str = *(const char **)(v15->declaredValue.swizzle[0] + 8);
          }
          else if ( parmType == 9 )
          {
            str = *(const char **)(v15->declaredValue.swizzle[0] + 8);
          }
          else
          {
            str = v15->name.str;
          }
        }
        else
        {
          str = &byte_8200D768;
        }
        idFile::WriteString(this: fp, string: str);
        if ( (this->ops.list[v8].type & 0x1F) == 4 )
          fp->Write(this: fp, a2: &this->constants.list[v7], a3: 16u);
      }
      image = (const idImage *)expOp_t::GetB(this: &this->ops.list[v8]);
      v20 = fp;
      if ( image != nullptr )
LABEL_23:
        string = image->name.str;
      else
        string = &byte_8200D768;
LABEL_31:
      idFile::WriteString(this: v20, string);
LABEL_32:
      ++v6;
      ++v8;
      ++v7;
    }
    while ( v6 < this->ops.num );
  }
}


// ========================================================================
// ??0idParmBlock@@QAA@W4threadId_t@@@Z
// EA  : 0x8293A818
// RVA : 0x0093A818
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

idParmBlock *__fastcall idParmBlock::idParmBlock(idParmBlock *this, threadId_t threadId)
{
  this->ops.list = nullptr;
  this->ops.granularity = 0;
  this->ops.memTag = 56;
  this->ops.listStatic = 0;
  this->ops.size = 0;
  this->ops.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->constants.list = nullptr;
  this->constants.granularity = 0;
  this->constants.memTag = 56;
  this->constants.listStatic = 0;
  this->constants.size = 0;
  this->constants.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constants);
  this->thread = threadId;
  this->usingTempOps = false;
  return this;
}


// ========================================================================
// __unwind$231853
// EA  : 0x8293A88C
// RVA : 0x0093A88C
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_231853()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idParmBlock@@QAA@XZ
// EA  : 0x8293A8C0
// RVA : 0x0093A8C0
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::~idParmBlock(idParmBlock *this)
{
  if ( this->thread == THREAD_RENDERER )
    idParmState::RemoveFromVirtualStack(this: renderThreadParmState, parmBlock: this);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constants);
  this->usingTempOps = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constants);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$231877
// EA  : 0x8293A928
// RVA : 0x0093A928
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_231877()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$231878
// EA  : 0x8293A950
// RVA : 0x0093A950
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_231878()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ?WriteConstant@idParmBlock@@CAXAAVidStr@@W4parmType_t@@ABTparmValue_t@@@Z
// EA  : 0x8293A980
// RVA : 0x0093A980
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::WriteConstant(idStr *str, parmType_t parmType, __int64 parmValue, __int64 a4, __int64 a5)
{
  char **v6; // r31
  double v7; // fp1
  __int64 v8; // fp2
  double v9; // fp0
  va *v10; // r3
  __int64 v11; // r8
  va *v12; // r3
  int v13; // [sp+8h] [-2068h]
  int v14; // [sp+Ch] [-2064h]
  int v15; // [sp+10h] [-2060h]
  int v16; // [sp+14h] [-205Ch]
  int v17; // [sp+18h] [-2058h]
  int v18; // [sp+1Ch] [-2054h]
  double v19; // [sp+30h] [-2040h]
  double v20; // [sp+38h] [-2038h]
  va v21; // [sp+50h] [-2020h] BYREF
  va v22; // [sp+1050h] [-1020h] BYREF

  v6 = (char **)HIDWORD(parmValue);
  switch ( parmType )
  {
    case PT_VECTOR:
      v7 = *(float *)HIDWORD(parmValue);
      *(double *)&v8 = *(float *)(HIDWORD(parmValue) + 4);
      if ( v7 == *(double *)&v8
        && (v9 = *(float *)(HIDWORD(parmValue) + 8), *(double *)&v8 == v9)
        && v9 == *(float *)(HIDWORD(parmValue) + 12) )
      {
        HIDWORD(parmValue) = LODWORD(v7);
        v10 = va::va(
                this: &v21,
                fmt: "%f",
                a3: parmValue,
                a4,
                a5,
                a6: v13,
                a7: v14,
                a8: v15,
                a9: v16,
                a10: v17,
                a11: v18);
        idStr::Append(this: str, text: v10);
      }
      else
      {
        v20 = *(float *)(HIDWORD(parmValue) + 12);
        LODWORD(v11) = LODWORD(v20);
        v19 = *(float *)(HIDWORD(parmValue) + 8);
        HIDWORD(v11) = LODWORD(v19);
        v12 = va::va(
                this: &v22,
                fmt: "{ %f, %f, %f, %f }",
                a3: v8,
                a4: v11,
                a5,
                a6: v13,
                a7: v14,
                a8: v15,
                a9: v16,
                a10: v17,
                a11: v18);
        idStr::Append(this: str, text: v12);
      }
      break;
    case PT_TEXTURE:
    case PT_TEXTURE_2D:
    case PT_TEXTURE_3D:
    case PT_TEXTURE_CUBE:
    case PT_TEXTURE_SHADOW_2D:
    case PT_TEXTURE_SHADOW_3D:
    case PT_TEXTURE_SHADOW_CUBE:
    case PT_TEXTURE_MULTISAMPLE_2D:
    case PT_PROGRAM:
      idStr::Append(this: str, text: *(char **)(*(_DWORD *)HIDWORD(parmValue) + 8));
      break;
    case PT_STRING:
      idStr::Append(this: str, text: "\"");
      idStr::Append(this: str, text: *v6);
      idStr::Append(this: str, text: "\"");
      break;
    default:
      return;
  }
}


// ========================================================================
// ?WriteString@idParmBlock@@QBAPAVidStr@@XZ
// EA  : 0x8293AAE0
// RVA : 0x0093AAE0
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

idStr *__fastcall idParmBlock::WriteString(idParmBlock *this)
{
  idStr *v2; // r3
  idStr *v3; // r30
  int v4; // r25
  const idDeclRenderParm *RenderParmForIndex; // r29
  const idDeclRenderParm *v6; // r27
  const idDeclRenderParm *v7; // r28
  int v8; // r11
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  int v12; // r11
  const idDeclTable *Table; // r3
  char *str; // r4
  char *v15; // r4
  int v16; // r29
  float v17; // r4
  char *v18; // r29
  char v19; // r10
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  parmType_t parmType; // r4
  idStr *v27; // r3
  int v29; // r6
  int v30; // r5
  int v31; // r4
  int v32; // r3
  int v33; // [sp+50h] [-100h]
  int v34; // [sp+54h] [-FCh]

  v2 = (idStr *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                  size: 0x20u,
                  tag: TAG_RENDERPARM,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idStr::idStr(this: v2, text: "{\n");
  else
    v3 = nullptr;
  v33 = 0;
  if ( this->ops.num <= 0 )
  {
LABEL_71:
    idStr::Append(this: v3, text: "}\n");
    return v3;
  }
  v34 = 0;
  v4 = 0;
  while ( 1 )
  {
    RenderParmForIndex = idParmState::GetRenderParmForIndex(
                           this: renderThreadParmState,
                           parmIndex: this->ops.list[v4].parmIndexDest);
    v6 = idParmState::GetRenderParmForIndex(this: renderThreadParmState, parmIndex: this->ops.list[v4].parmIndexA);
    v7 = idParmState::GetRenderParmForIndex(this: renderThreadParmState, parmIndex: this->ops.list[v4].parmIndexB);
    idStr::Append(this: v3, text: (char *)RenderParmForIndex->name.str);
    v8 = (this->ops.list[v4].type >> 9) & 0xF;
    if ( v8 != 0 && v8 != 15 )
    {
      idStr::Append(this: v3, text: ".");
      if ( (this->ops.list[v4].type & 0x200) != 0 )
        idStr::Append(this: v3, text: "x");
      if ( (this->ops.list[v4].type & 0x400) != 0 )
        idStr::Append(this: v3, text: "y");
      if ( (this->ops.list[v4].type & 0x800) != 0 )
        idStr::Append(this: v3, text: "z");
      if ( (this->ops.list[v4].type & 0x1000) != 0 )
        idStr::Append(this: v3, text: "w");
    }
    idStr::Append(this: v3, text: "\t");
    LODWORD(v11) = &this->ops.list[v4];
    v12 = *(_WORD *)v11 & 0x1F;
    if ( v12 == 20 )
    {
      Table = idParmState::GetTable(this: renderThreadParmState, tableIndex: *(__int16 *)(v11 + 4));
      if ( Table != nullptr )
        str = (char *)Table->name.str;
      else
        str = "NULL";
      idStr::Append(this: v3, text: str);
      idStr::Append(this: v3, text: "[");
      idStr::Append(this: v3, text: (char *)v7->name.str);
      v15 = "]\n";
      goto LABEL_70;
    }
    if ( v12 == 0 || v12 == 2 )
    {
      LODWORD(v11) = v34 * 16;
      parmType = RenderParmForIndex->parmType;
      HIDWORD(v10) = &this->constants.list[v34];
LABEL_67:
      v27 = v3;
LABEL_68:
      idParmBlock::WriteConstant(str: v27, parmType, parmValue: v10, a4: v9, a5: v11);
      goto LABEL_69;
    }
    if ( v12 == 4 )
      break;
    if ( v12 == 3 || v12 == 1 )
    {
      v27 = v3;
      if ( v6->creator == PC_CONSTANT )
      {
        parmType = v6->parmType;
        LODWORD(v11) = 16 * (v6->parmIndex + 3);
        HIDWORD(v10) = (char *)renderThreadParmState + v11;
        goto LABEL_68;
      }
      idStr::Append(this: v3, text: (char *)v6->name.str);
    }
    else
    {
      v18 = &byte_8200D768;
      v19 = 0;
      switch ( v12 )
      {
        case 5:
          v18 = " + ";
          break;
        case 6:
          v18 = " - ";
          break;
        case 7:
          v18 = " * ";
          break;
        case 8:
          v18 = " dot3";
          v19 = 1;
          break;
        case 9:
          v18 = " dot4";
          v19 = 1;
          break;
        case 10:
          v18 = " / ";
          break;
        case 11:
          v18 = " % ";
          break;
        case 12:
          v18 = " > ";
          break;
        case 13:
          v18 = " >= ";
          break;
        case 14:
          v18 = " < ";
          break;
        case 15:
          v18 = " <= ";
          break;
        case 16:
          v18 = " == ";
          break;
        case 17:
          v18 = " != ";
          break;
        case 18:
          v18 = " && ";
          break;
        case 19:
          v18 = " || ";
          break;
        default:
          break;
      }
      if ( v19 != 0 )
      {
        idStr::Append(this: v3, text: v18);
        idStr::Append(this: v3, text: "( ");
        if ( v6->creator == PC_CONSTANT )
        {
          LODWORD(v20) = 16 * (v6->parmIndex + 3);
          HIDWORD(v22) = (char *)renderThreadParmState + v20;
          idParmBlock::WriteConstant(str: v3, parmType: v6->parmType, parmValue: v22, a4: v21, a5: v20);
        }
        else
        {
          idStr::Append(this: v3, text: (char *)v6->name.str);
        }
        idStr::Append(this: v3, text: ", ");
        if ( v7->creator == PC_CONSTANT )
        {
          LODWORD(v23) = 16 * (v7->parmIndex + 3);
          HIDWORD(v25) = (char *)renderThreadParmState + v23;
          idParmBlock::WriteConstant(str: v3, parmType: v7->parmType, parmValue: v25, a4: v24, a5: v23);
        }
        else
        {
          idStr::Append(this: v3, text: (char *)v7->name.str);
        }
        idStr::Append(this: v3, text: " )");
        goto LABEL_69;
      }
      if ( v6->creator == PC_CONSTANT )
      {
        LODWORD(v11) = 16 * (v6->parmIndex + 3);
        HIDWORD(v10) = (char *)renderThreadParmState + v11;
        idParmBlock::WriteConstant(str: v3, parmType: v6->parmType, parmValue: v10, a4: v9, a5: v11);
      }
      else
      {
        idStr::Append(this: v3, text: (char *)v6->name.str);
      }
      idStr::Append(this: v3, text: v18);
      if ( v7->creator == PC_CONSTANT )
      {
        parmType = v7->parmType;
        LODWORD(v11) = 16 * (v7->parmIndex + 3);
        HIDWORD(v10) = (char *)renderThreadParmState + v11;
        goto LABEL_67;
      }
      idStr::Append(this: v3, text: (char *)v7->name.str);
    }
LABEL_69:
    v15 = "\n";
LABEL_70:
    idStr::Append(this: v3, text: v15);
    ++v4;
    ++v33;
    ++v34;
    if ( v33 >= this->ops.num )
      goto LABEL_71;
  }
  if ( v6->creator == PC_CONSTANT )
  {
    LODWORD(v11) = 16 * (v6->parmIndex + 3);
    HIDWORD(v10) = (char *)renderThreadParmState + v11;
    idParmBlock::WriteConstant(str: v3, parmType: v6->parmType, parmValue: v10, a4: v9, a5: v11);
  }
  else
  {
    idStr::Append(this: v3, text: (char *)v6->name.str);
  }
  idStr::Append(this: v3, text: ".");
  v16 = 0;
  while ( 1 )
  {
    v17 = this->constants.list[v33].value[v16];
    if ( LODWORD(v17) >= 4 )
      break;
    idStr::Append(this: v3, text: (char *)suffix[LODWORD(v17)]);
    if ( ++v16 >= 4 )
      goto LABEL_69;
  }
  idLib::Error(fmt: "idParmBlock::WriteString: bad swizzle index %d for term %s", v17, v6->name.str);
  return _LN300(a1: v32, a2: v31, a3: v30, a4: v29);
}


// ========================================================================
// $LN300
// EA  : 0x8293B1B8
// RVA : 0x0093B1B8
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _LN300()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 336 + 164), tag: TAG_RENDERPARM);
}


// ========================================================================
// ?Print@idParmBlock@@QBAXXZ
// EA  : 0x8293B1E8
// RVA : 0x0093B1E8
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::Print(idParmBlock *this)
{
  idStr *v1; // r31

  v1 = idParmBlock::WriteString(this);
  idLib::Printf(fmt: "%s", v1->data);
  idStr::FreeData(this: v1);
  idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
}


// ========================================================================
// ?RemoveRedundantOperations@idParmBlock@@AAAXXZ
// EA  : 0x8293B4A0
// RVA : 0x0093B4A0
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::RemoveRedundantOperations(idParmBlock *this)
{
  int v1; // r30
  int v3; // r26
  char v4; // r24
  int v5; // r29
  _BYTE *v6; // r27
  int num; // r28
  int v8; // r11
  char v9; // r5
  char v10; // r4
  int v11; // r7
  int v12; // r8
  _BYTE *v13; // r6
  _WORD *v14; // r10
  expOp_t *v15; // r9
  int parmIndexDest; // r11
  int v17; // r6
  int v18; // r9
  int v19; // r7
  int v20; // r10
  int v21; // r8
  int v22; // r5
  expOp_t *v23; // r3
  expOp_t *v24; // r29
  parmValue_t *list; // r11
  parmValue_t *v26; // r3
  int size; // r11
  idList<idPlane,37> *p_constants; // r31
  int v29; // r11
  _BYTE v30[336]; // [sp+50h] [-150h] BYREF

  v1 = 0;
  v3 = this->ops.num - 1;
  v4 = 0;
  if ( v3 >= 0 )
  {
    v5 = v3;
    v6 = &v30[v3];
    num = this->ops.num;
    do
    {
      v8 = this->ops.num;
      v9 = 0;
      *v6 = 0;
      v10 = 0;
      v11 = num;
      if ( num < v8 )
      {
        v12 = v5 * 8 + 8;
        v13 = &v30[num];
        while ( 1 )
        {
          if ( *v13 == 0 )
          {
            v14 = (unsigned __int16 *)((char *)&this->ops.list->type + v12);
            v15 = &this->ops.list[v5];
            parmIndexDest = v15->parmIndexDest;
            if ( (__int16)v14[2] == parmIndexDest || (__int16)v14[3] == parmIndexDest )
              v9 = 1;
            if ( (__int16)v14[1] == parmIndexDest && (v15->type & (unsigned __int16)~*v14 & 0x1E00) == 0 )
              break;
          }
          ++v11;
          ++v13;
          v12 += 8;
          if ( v11 >= this->ops.num )
            goto LABEL_14;
        }
        v10 = 1;
      }
LABEL_14:
      if ( v9 == 0 && (v10 != 0 || expOp_t::GetDest(this: &this->ops.list[v5])->creator == PC_TEMPORARY) )
      {
        v4 = 1;
        *v6 = 1;
      }
      --v3;
      --num;
      --v5;
      --v6;
    }
    while ( v3 >= 0 );
  }
  if ( v4 != 0 )
  {
    v17 = 0;
    if ( this->ops.num > 0 )
    {
      v18 = 0;
      v19 = 0;
      v20 = 0;
      v21 = 0;
      v22 = c_redundantOperationsRemoved;
      do
      {
        if ( v30[v17] != 0 )
        {
          ++v22;
        }
        else
        {
          ++v1;
          v23 = &this->ops.list[v21];
          v24 = &this->ops.list[v20];
          ++v21;
          v23->type = v24->type;
          v23->parmIndexDest = v24->parmIndexDest;
          v23->parmIndexA = v24->parmIndexA;
          v23->parmIndexB = v24->parmIndexB;
          list = this->constants.list;
          v26 = &list[v19];
          v26->swizzle[0] = list[v18].swizzle[0];
          ++v19;
          v26->swizzle[1] = list[v18].swizzle[1];
          v26->swizzle[2] = list[v18].swizzle[2];
          v26->swizzle[3] = list[v18].swizzle[3];
        }
        ++v17;
        ++v20;
        ++v18;
      }
      while ( v17 < this->ops.num );
      c_redundantOperationsRemoved = v22;
    }
    if ( v1 <= this->ops.size
      || idList<detailPaletteEntry_t,5>::Resize((idList<detailPaletteEntry_t,5> *)this, newsize: v1) )
    {
      size = this->ops.size;
      if ( v1 < size )
        size = v1;
      this->ops.num = size;
    }
    p_constants = (idList<idPlane,37> *)&this->constants;
    if ( v1 <= p_constants->size || idList<idPlayerCoverScore_t,5>::Resize(this: p_constants, newsize: v1) )
    {
      v29 = p_constants->size;
      if ( v1 < v29 )
        v29 = v1;
      p_constants->num = v29;
    }
  }
}


// ========================================================================
// ?CopyFrom@idParmBlock@@QAAXABV1@@Z
// EA  : 0x8293B728
// RVA : 0x0093B728
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::CopyFrom(idParmBlock *this, const idParmBlock *other)
{
  int size; // r10
  int num; // r30
  int v6; // r11
  int v7; // r28
  int v8; // r11
  int v9; // r9
  int v10; // r10
  int v11; // r11
  expOp_t *v12; // r7
  expOp_t *v13; // r6
  parmValue_t *v14; // r7
  parmValue_t *v15; // r6

  if ( this->thread == THREAD_RENDERER )
    idParmState::RemoveFromVirtualStack(this: renderThreadParmState, parmBlock: this);
  size = this->ops.size;
  this->usingTempOps = other->usingTempOps;
  num = other->ops.num;
  if ( num <= size
    || idList<detailPaletteEntry_t,5>::Resize((idList<detailPaletteEntry_t,5> *)this, newsize: other->ops.num) )
  {
    v6 = this->ops.size;
    if ( num < v6 )
      v6 = num;
    this->ops.num = v6;
  }
  v7 = other->constants.num;
  if ( v7 <= this->constants.size
    || idList<idPlayerCoverScore_t,5>::Resize(
         this: (idList<idPlane,37> *)&this->constants,
         newsize: other->constants.num) )
  {
    v8 = this->constants.size;
    if ( v7 < v8 )
      v8 = v7;
    this->constants.num = v8;
  }
  v9 = 0;
  if ( other->ops.num > 0 )
  {
    v10 = 0;
    v11 = 0;
    do
    {
      ++v9;
      v12 = &other->ops.list[v11];
      v13 = &this->ops.list[v11++];
      v13->type = v12->type;
      v13->parmIndexDest = v12->parmIndexDest;
      v13->parmIndexA = v12->parmIndexA;
      v13->parmIndexB = v12->parmIndexB;
      v14 = &other->constants.list[v10];
      v15 = &this->constants.list[v10++];
      v15->swizzle[0] = v14->swizzle[0];
      v15->swizzle[1] = v14->swizzle[1];
      v15->swizzle[2] = v14->swizzle[2];
      v15->swizzle[3] = v14->swizzle[3];
    }
    while ( v9 < other->ops.num );
  }
}


// ========================================================================
// ?AddOp@idParmBlock@@QAAXABUexpOp_t@@ABTparmValue_t@@@Z
// EA  : 0x8293B878
// RVA : 0x0093B878
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::AddOp(idParmBlock *this, const expOp_t *op, const idPlane *constant)
{
  idList<expOp_t,56>::Append(this: &this->ops, obj: op);
  idList<aas2Cluster_t,37>::Append(this: (idList<idPlane,37> *)&this->constants, obj: constant);
}


// ========================================================================
// ?ClearParm@idParmBlock@@QAAXPBVidDeclRenderParm@@@Z
// EA  : 0x8293B8C0
// RVA : 0x0093B8C0
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::ClearParm(idParmBlock *this, const idDeclRenderParm *parm)
{
  char v4; // r28
  int v5; // r31
  int v6; // r30
  expOp_t *v7; // r11
  unsigned int v8; // r11
  unsigned __int8 v9; // r11
  bool v10; // zf

  if ( this->thread == THREAD_RENDERER )
    idParmState::RemoveFromVirtualStack(this: renderThreadParmState, parmBlock: this);
  v4 = 0;
  v5 = 0;
  if ( this->ops.num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = &this->ops.list[v6];
      if ( v7->parmIndexDest == parm->parmIndex )
      {
        v8 = v7->type & 0x1F;
        if ( v8 < 2 || v8 == 3 || (v10 = v8 != 2, v9 = 0, !v10) )
          v9 = 1;
        v4 |= (_cntlzw(v9) & 0x20) != 0;
        idList<expOp_t,56>::RemoveIndex(this: &this->ops, index: v5);
        idList<idMenuWidget_DevList::indexInfo_t,5>::RemoveIndex(this: &this->constants, index: v5--);
        --v6;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->ops.num );
  }
  if ( v4 != 0 )
    idParmBlock::RemoveRedundantOperations(this);
}


// ========================================================================
// ?Append@idParmBlock@@QAAXABV1@@Z
// EA  : 0x8293B9B8
// RVA : 0x0093B9B8
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::Append(idParmBlock *this, const idParmBlock *block)
{
  int v4; // r29
  int v5; // r30
  int v6; // r31

  if ( this->thread == THREAD_RENDERER )
    idParmState::RemoveFromVirtualStack(this: renderThreadParmState, parmBlock: this);
  v4 = 0;
  if ( block->ops.num > 0 )
  {
    v5 = 0;
    v6 = 0;
    do
    {
      idList<expOp_t,56>::Append(this: &this->ops, obj: &block->ops.list[v6]);
      idList<aas2Cluster_t,37>::Append(
        this: (idList<idPlane,37> *)&this->constants,
        obj: (const idPlane *)&block->constants.list[v5]);
      ++v4;
      ++v6;
      ++v5;
    }
    while ( v4 < block->ops.num );
  }
  idParmBlock::RemoveRedundantOperations(this);
}


// ========================================================================
// ?Load@idParmBlock@@QAA_NPAVidFile@@@Z
// EA  : 0x8293BA58
// RVA : 0x0093BA58
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

int __fastcall idParmBlock::Load(idParmBlock *this, idFile *fp)
{
  idFile_vtbl *v4; // r11
  idList<parmValue_t,56> *p_constants; // r25
  int v6; // r14
  int v7; // r29
  int v8; // r26
  expOp_t *list; // r11
  unsigned __int16 type; // r6
  const idDecl *v11; // r30
  int v12; // r11
  const idDeclTable *v13; // r4
  expOp_t *v14; // r30
  __int16 v15; // r3
  int trackedMemory; // r10
  char v17; // r11
  const idDecl *v18; // r3
  idDecl_vtbl *v19; // r11
  const idDecl *v20; // r3
  parmValue_t *v21; // r30
  const idDecl *v22; // r3
  _BYTE v24[4]; // [sp+50h] [-D0h] BYREF
  int v25; // [sp+54h] [-CCh] BYREF
  idAtomicString v26; // [sp+58h] [-C8h] BYREF
  int v27; // [sp+5Ch] [-C4h]
  idStr v28[6]; // [sp+60h] [-C0h] BYREF

  if ( fp->Read(this: fp, a2: &this->usingTempOps, a3: 1u) != 0 )
  {
    v4 = fp->__vftable;
    v25 = 0;
    if ( v4->Read(this: fp, a2: &v25, a3: 4u) != 0 )
    {
      idList<sbspArea_t,39>::SetNum(this: &this->ops, newNum: v25);
      p_constants = &this->constants;
      idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)&this->constants, newNum: v25);
      v6 = 0;
      if ( this->ops.num <= 0 )
        return 1;
      v7 = 0;
      v8 = 0;
      while ( fp->Read(this: fp, a2: v24, a3: 1u) != 0 )
      {
        this->ops.list[v7].type = this->ops.list[v7].type & 0xFFE0 | v24[0];
        if ( fp->Read(this: fp, a2: v24, a3: 1u) == 0 )
          break;
        list = this->ops.list;
        type = this->ops.list[v7].type;
        v27 = v24[0];
        list[v7].type = type & 0xE1FF | __ROL4__(v24[0], 9);
        v28[0].allocedAndFlag = 20;
        v28[0].data = v28[0].baseBuffer;
        v28[0].len = 0;
        v28[0].baseBuffer[0] = 0;
        if ( idFile::ReadString(this: fp, string: v28) == 0 )
        {
          idStr::FreeData(this: v28);
          return 0;
        }
        if ( v28[0].data != nullptr )
          v11 = idDeclInfo::FindWithInheritance(
                  this: &idDeclRenderParm::resourceList,
                  name: v28[0].data,
                  makeDefault: true);
        else
          v11 = nullptr;
        this->ops.list[v7].parmIndexDest = (__int16)v11[1].__vftable;
        this->ops.list[v7].type = this->ops.list[v7].type & 0xFE1F | (32 * v11[1].trackedMemory);
        v12 = this->ops.list[v7].type & 0x1F;
        if ( v12 == 2 || v12 == 0 )
        {
          switch ( v11[1].trackedMemory )
          {
            case 0:
              if ( fp->Read(this: fp, a2: &p_constants->list[v8], a3: 16u) == 0 )
                goto LABEL_61;
              break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
              if ( idFile::ReadString(this: fp, string: v28) == 0 )
                goto LABEL_61;
              v21 = p_constants->list;
              v21[v8].swizzle[0] = (int)idImageManager::ImageFromFile(
                                          this: globalImages,
                                          _name: v28[0].data,
                                          opts_p: nullptr,
                                          makeDefault: true);
              if ( p_constants->list[v8].swizzle[0] == 0 )
                idLib::Warning(fmt: "expOp_t::Load: NULL Texture '%s'", v28[0].data);
              break;
            case 9:
              if ( idFile::ReadString(this: fp, string: v28) == 0 )
                goto LABEL_61;
              if ( v28[0].len != 0 )
              {
                if ( v28[0].data != nullptr )
                  v22 = idDeclInfo::FindWithInheritance(
                          this: &idDeclRenderProg::resourceList,
                          name: v28[0].data,
                          makeDefault: true);
                else
                  v22 = nullptr;
                p_constants->list[v8].swizzle[0] = (int)v22;
                if ( p_constants->list[v8].swizzle[0] == 0 )
                  idLib::Warning(fmt: "expOp_t::Load: NULL Program '%s'", v28[0].data);
              }
              else
              {
                p_constants->list[v8].swizzle[0] = 0;
              }
              break;
            case 0xA:
              if ( idFile::ReadString(this: fp, string: v28) == 0 )
                goto LABEL_61;
              idAtomicString::Set(this: &v26, str_: v28[0].data);
              LODWORD(p_constants->list[v8].value[0]) = (idAtomicString)v26.str;
              break;
            default:
              break;
          }
          this->ops.list[v7].parmIndexA = 2047;
          this->ops.list[v7].parmIndexB = 2047;
        }
        else
        {
          if ( v12 == 20 )
          {
            if ( idFile::ReadString(this: fp, string: v28) == 0 )
              goto LABEL_61;
            if ( v28[0].len != 0 )
            {
              if ( v28[0].data != nullptr )
                v13 = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                             this: &idDeclTable::resourceList,
                                             name: v28[0].data,
                                             makeDefault: true);
              else
                v13 = nullptr;
            }
            else
            {
              v13 = nullptr;
            }
            v14 = &this->ops.list[v7];
            idParmState::GetTableIndex(this: renderThreadParmState, table: v13);
            v14->parmIndexA = v15;
          }
          else
          {
            if ( idFile::ReadString(this: fp, string: v28) == 0 )
              goto LABEL_61;
            if ( v28[0].len == 0 )
              goto LABEL_31;
            trackedMemory = v11[1].trackedMemory;
            if ( trackedMemory < 1 || (v17 = 1, trackedMemory > 8) )
              v17 = 0;
            if ( v17 == 0
              && (v27 = v11[1].trackedMemory, trackedMemory != 9)
              && v28[0].data != nullptr
              && (v18 = idDeclInfo::FindWithInheritance(
                          this: &idDeclRenderParm::resourceList,
                          name: v28[0].data,
                          makeDefault: true)) != nullptr )
            {
              v19 = v18[1].__vftable;
            }
            else
            {
LABEL_31:
              LOWORD(v19) = 2047;
            }
            this->ops.list[v7].parmIndexA = (__int16)v19;
            if ( (this->ops.list[v7].type & 0x1F) == 4 && fp->Read(this: fp, a2: &p_constants->list[v8], a3: 16u) == 0 )
            {
LABEL_61:
              idStr::FreeData(this: v28);
              return 0;
            }
          }
          if ( idFile::ReadString(this: fp, string: v28) == 0 )
            goto LABEL_61;
          if ( v28[0].len != 0
            && v28[0].data != nullptr
            && (v20 = idDeclInfo::FindWithInheritance(
                        this: &idDeclRenderParm::resourceList,
                        name: v28[0].data,
                        makeDefault: true)) != nullptr )
          {
            this->ops.list[v7].parmIndexB = (__int16)v20[1].__vftable;
          }
          else
          {
            this->ops.list[v7].parmIndexB = 2047;
          }
        }
        idStr::FreeData(this: v28);
        ++v6;
        ++v8;
        ++v7;
        if ( v6 >= this->ops.num )
          return 1;
      }
    }
  }
  return 0;
}


// ========================================================================
// __unwind$232848_0
// EA  : 0x8293C01C
// RVA : 0x0093C01C
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_232848_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// ??0idParmBlock@@QAA@ABV0@@Z
// EA  : 0x8293C0C8
// RVA : 0x0093C0C8
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

idParmBlock *__fastcall idParmBlock::idParmBlock(idParmBlock *this, const idParmBlock *other)
{
  threadId_t thread; // r11

  this->ops.list = nullptr;
  this->ops.granularity = 0;
  this->ops.memTag = 56;
  this->ops.listStatic = 0;
  this->ops.size = 0;
  this->ops.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->constants.list = nullptr;
  this->constants.granularity = 0;
  this->constants.memTag = 56;
  this->constants.listStatic = 0;
  this->constants.size = 0;
  this->constants.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constants);
  thread = other->thread;
  this->usingTempOps = false;
  this->thread = thread;
  idParmBlock::CopyFrom(this, other);
  return this;
}


// ========================================================================
// __unwind$233273
// EA  : 0x8293C14C
// RVA : 0x0093C14C
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_233273()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$233274
// EA  : 0x8293C174
// RVA : 0x0093C174
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_233274()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// ?SetParm@idParmBlock@@QAAXPBVidDeclRenderParm@@ABTparmValue_t@@@Z
// EA  : 0x8293C1A0
// RVA : 0x0093C1A0
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::SetParm(idParmBlock *this, const idDeclRenderParm *parm, const parmValue_t *parmValue)
{
  int num; // r6
  bool v7; // r28
  int v8; // r11
  expOp_t *v9; // r9
  int v10; // r10
  expOp_t *v11; // r8
  expOp_t *v12; // r31
  parmValue_t *v13; // r11
  unsigned int v14; // r10
  unsigned __int8 v15; // r10
  bool v16; // zf
  int v17; // r11
  int size; // r10
  expOp_t *list; // r9
  int v20; // r11
  int v21; // r10
  parmValue_t *v22; // r9
  unsigned __int16 type; // r9

  if ( this->thread == THREAD_RENDERER )
    idParmState::RemoveFromVirtualStack(this: renderThreadParmState, parmBlock: this);
  num = this->ops.num;
  v7 = false;
  v8 = num - 1;
  if ( num - 1 < 0 )
  {
LABEL_7:
    if ( this->ops.listStatic == 0 || num != this->ops.size )
    {
      idList<expOp_t,56>::PreAllocateWithGranularity(this: &this->ops, newSize: num + 1);
      v17 = this->ops.num;
      size = this->ops.size;
      list = this->ops.list;
      if ( v17 >= size )
      {
        v12 = &list[size - 1];
      }
      else
      {
        v12 = &list[v17];
        this->ops.num = v17 + 1;
      }
      idList<idParser::indent_t,11>::PreAllocateWithGranularity(
        this: (idList<aas2Cluster_t,37> *)&this->constants,
        newSize: this->constants.num + 1);
      v20 = this->constants.num;
      v21 = this->constants.size;
      v22 = this->constants.list;
      if ( v20 >= v21 )
      {
        v13 = &v22[v21 - 1];
      }
      else
      {
        this->constants.num = v20 + 1;
        v13 = &v22[v20];
      }
      v12->type = 0;
      v12->parmIndexDest = 0;
      v12->parmIndexA = 0;
      v12->parmIndexB = 0;
      v13->swizzle[0] = 0;
      v13->swizzle[1] = 0;
      v13->swizzle[2] = 0;
      v13->swizzle[3] = 0;
      goto LABEL_22;
    }
    idLib::FatalError(fmt: "idParmBlock::SetParm: MAX_STATIC_PARM_OPS exceeded");
  }
  else
  {
    v9 = this->ops.list;
    v10 = v8;
    v11 = &this->ops.list[v8];
    while ( v11->parmIndexDest != parm->parmIndex )
    {
      --v10;
      --v8;
      v11 = &v9[v10];
      if ( v8 < 0 )
        goto LABEL_7;
    }
  }
  v12 = &v9[v8];
  v13 = &this->constants.list[v8];
  v14 = v12->type & 0x1F;
  if ( v14 < 2 || v14 == 3 || (v16 = v14 != 2, v15 = 0, !v16) )
    v15 = 1;
  v7 = (_cntlzw(v15) & 0x20) != 0;
LABEL_22:
  type = v12->type;
  v12->parmIndexA = 2047;
  v12->parmIndexB = 2047;
  v12->parmIndexDest = parm->parmIndex;
  v12->type = type & 0xFE00 | (32 * parm->parmType);
  v13->swizzle[0] = parmValue->swizzle[0];
  v13->swizzle[1] = parmValue->swizzle[1];
  v13->swizzle[2] = parmValue->swizzle[2];
  v13->swizzle[3] = parmValue->swizzle[3];
  if ( v7 )
    idParmBlock::RemoveRedundantOperations(this);
}


// ========================================================================
// ?GetExpressionOp@idParmBlock@@AAAPAUexpOp_t@@AAVidParser@@ABTparmValue_t@@@Z
// EA  : 0x8293C3A0
// RVA : 0x0093C3A0
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

expOp_t *__fastcall idParmBlock::GetExpressionOp(idParmBlock *this, idParser *src, aas2Cluster_t *constant)
{
  expOp_t *v6; // r29

  if ( this->ops.num == 256 )
  {
    idParser::Warning(this: src, str: "GetExpressionOp: hit MAX_PARMBLOCK_OPS");
    return &this->ops.list[this->ops.num];
  }
  else
  {
    v6 = idList<expOp_t,56>::Alloc(this: &this->ops);
    v6->type = 0;
    v6->parmIndexDest = 0;
    v6->parmIndexA = 0;
    v6->parmIndexB = 0;
    v6->parmIndexDest = 2047;
    v6->parmIndexA = 2047;
    v6->parmIndexB = 2047;
    *idList<idPlayerCoverScore_t,5>::Alloc(this: (idList<aas2Cluster_t,37> *)&this->constants) = *constant;
    return v6;
  }
}


// ========================================================================
// ?GetConstantVector@idParmBlock@@AAAPBVidDeclRenderParm@@AAVidParser@@QBM@Z
// EA  : 0x8293C450
// RVA : 0x0093C450
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

const idDeclRenderParm *__fastcall idParmBlock::GetConstantVector(
        idParmBlock *this,
        idParser *src,
        __int64 v,
        __int64 a4)
{
  double v5; // fp13
  double v7; // fp12
  double v8; // fp11
  const idDeclRenderParm *ExpressionTemporaryParm; // r29
  expOp_t *ExpressionOp; // r3
  __int16 v11; // r9
  aas2Cluster_t v13; // [sp+50h] [-30h] BYREF

  v5 = *(float *)(HIDWORD(v) + 4);
  v7 = *(float *)(HIDWORD(v) + 8);
  v8 = *(float *)(HIDWORD(v) + 12);
  v13.numAreas = *(int *)HIDWORD(v);
  *(float *)&v13.numReachableAreas = v5;
  *(float *)&v13.numPortals = v7;
  *(float *)&v13.firstPortal = v8;
  ExpressionTemporaryParm = idParmBlock::GetExpressionTemporaryParm(this, a2: (int)src, a3: v, a4);
  ExpressionOp = idParmBlock::GetExpressionOp(this, src, constant: &v13);
  v11 = ExpressionOp->type & 0xE1E0;
  ExpressionOp->type = v11 | 0x1E00;
  ExpressionOp->parmIndexDest = ExpressionTemporaryParm->parmIndex;
  ExpressionOp->type = v11 & 0xE01F | 0x1E00 | (32 * ExpressionTemporaryParm->parmType);
  return ExpressionTemporaryParm;
}


// ========================================================================
// ?EmitOp@idParmBlock@@AAAPBVidDeclRenderParm@@AAVidParser@@PBV2@1PBVidDeclTable@@W4expOpType_t@@@Z
// EA  : 0x8293C4E0
// RVA : 0x0093C4E0
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

const idDeclRenderParm *__fastcall idParmBlock::EmitOp(
        idParmBlock *this,
        idParser *src,
        const idDeclRenderParm *a,
        const idDeclRenderParm *b,
        const idDeclTable *table,
        expOpType_t opType)
{
  __int16 v10; // r25
  int v11; // r3
  int parmIndex; // r30
  __int64 v13; // r8
  __int64 v14; // r6
  int v15; // r4
  const idDeclRenderParm *ExpressionTemporaryParm; // r31
  expOp_t *ExpressionOp; // r3
  unsigned __int16 v18; // r10

  v10 = opType;
  idParmState::GetTableIndex(this: renderThreadParmState, table);
  parmIndex = v11;
  ExpressionTemporaryParm = idParmBlock::GetExpressionTemporaryParm(this, a2: v15, a3: v14, a4: v13);
  ExpressionOp = idParmBlock::GetExpressionOp(this, src, constant: (aas2Cluster_t *)&defaultConstant);
  v18 = ExpressionOp->type & 0xE1E0 | v10 | 0x1E00;
  ExpressionOp->type = v18;
  ExpressionOp->parmIndexDest = ExpressionTemporaryParm->parmIndex;
  if ( parmIndex == 2047 )
    parmIndex = a->parmIndex;
  ExpressionOp->parmIndexA = parmIndex;
  ExpressionOp->parmIndexB = b->parmIndex;
  ExpressionOp->type = v18 & 0xFE1F | (32 * HIWORD(ExpressionTemporaryParm->parmType));
  return ExpressionTemporaryParm;
}


// ========================================================================
// ?ParseIntrinsic@idParmBlock@@AAAPBVidDeclRenderParm@@AAVidParser@@W4expOpType_t@@@Z
// EA  : 0x8293C598
// RVA : 0x0093C598
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

const idDeclRenderParm *__fastcall idParmBlock::ParseIntrinsic(idParmBlock *this, idParser *src, expOpType_t opType)
{
  const idDeclRenderParm *v6; // r28
  const idDeclRenderParm *v7; // r27

  idParser::ExpectTokenString(this: src, string: "(");
  v6 = idParmBlock::ParseExpressionPriority(this, src, priority: 4);
  idParser::ExpectTokenString(this: src, string: ",");
  v7 = idParmBlock::ParseExpressionPriority(this, src, priority: 4);
  idParser::ExpectTokenString(this: src, string: ")");
  return idParmBlock::EmitOp(this, src, a: v6, b: v7, table: nullptr, opType);
}


// ========================================================================
// ?ParseTerm@idParmBlock@@AAAPBVidDeclRenderParm@@AAVidParser@@PAVidToken@@@Z
// EA  : 0x8293C638
// RVA : 0x0093C638
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

const idDeclRenderParm *__fastcall idParmBlock::ParseTerm(idParmBlock *this, idParser *src, idToken *fakeToken)
{
  const idDeclRenderParm *ConstantVector; // r30
  const char *v6; // r26
  idStr *v7; // r3
  const idDeclRenderParm *v8; // r23
  __int64 v9; // r8
  __int64 v10; // r6
  int v11; // r4
  const idDeclRenderParm *ExpressionTemporaryParm; // r3
  const idDeclRenderParm *v13; // r24
  int v14; // r30
  const char *v15; // r8
  aas2Cluster_t *v16; // r9
  char v17; // r11
  char v18; // r10
  _DWORD *v19; // r10
  int v20; // ctr
  expOp_t *ExpressionOp; // r3
  unsigned __int16 type; // r10
  int parmIndex; // r4
  char *data; // r4
  const idDeclTable *v26; // r30
  const idDeclRenderParm *v27; // r29
  __int64 v28; // r8
  __int64 v29; // r6
  int v30; // r4
  __int64 v31; // r6
  __int64 v32; // r8
  aas2Cluster_t v33; // [sp+50h] [-120h] BYREF
  idToken v34; // [sp+60h] [-110h] BYREF
  idStr v35; // [sp+B0h] [-C0h] BYREF
  idToken v36[2]; // [sp+D0h] [-A0h] BYREF

  v34.len = 0;
  v34.allocedAndFlag = 20;
  v34.floatvalue = -3.4028235e38;
  v34.data = v34.baseBuffer;
  v34.baseBuffer[0] = 0;
  v34.intvalue = 0;
  memset(&v34.whiteSpaceStart_p, 0, 12);
  if ( fakeToken != nullptr )
    idToken::operator=(this: &v34, __that: fakeToken);
  else
    idParser::ReadToken(this: src, token: &v34);
  if ( idStr::Cmp(s1: v34.data, s2: "dot3") == 0 )
  {
    ConstantVector = idParmBlock::ParseIntrinsic(this, src, opType: OP_TYPE_DOT3);
LABEL_45:
    idStr::FreeData(this: &v34);
    return ConstantVector;
  }
  if ( idStr::Cmp(s1: v34.data, s2: "dot4") == 0 )
  {
    ConstantVector = idParmBlock::ParseIntrinsic(this, src, opType: OP_TYPE_DOT4);
    goto LABEL_45;
  }
  if ( idStr::Cmp(s1: v34.data, s2: "(") == 0 )
  {
    ConstantVector = idParmBlock::ParseExpressionPriority(this, src, priority: 4);
    idParser::ExpectTokenString(this: src, string: ")");
    goto LABEL_45;
  }
  if ( idStr::Cmp(s1: v34.data, s2: "{") == 0 || idStr::Cmp(s1: v34.data, s2: "-") == 0 || v34.type == 3 )
  {
    idParser::UnreadToken(this: src, token: &v34);
    idDeclRenderParm::ParseVectorConstant(src, vec: (float *)&v33.numAreas);
    HIDWORD(v31) = &v33;
    ConstantVector = idParmBlock::GetConstantVector(this, src, v: v31, a4: v32);
    goto LABEL_45;
  }
  v6 = strstr(str1: v34.data, str2: ".");
  if ( v6 == nullptr )
  {
    data = v34.data;
    if ( v34.data != nullptr )
    {
      ConstantVector = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: v34.data,
                                                   makeDefault: false);
      if ( ConstantVector != nullptr )
        goto LABEL_45;
      data = v34.data;
      if ( v34.data != nullptr )
      {
        v26 = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclTable::resourceList,
                                     name: v34.data,
                                     makeDefault: false);
        if ( v26 != nullptr )
        {
          idParser::ExpectTokenString(this: src, string: "[");
          v27 = idParmBlock::ParseExpressionPriority(this, src, priority: 4);
          idParser::ExpectTokenString(this: src, string: "]");
          ConstantVector = idParmBlock::EmitOp(this, src, a: nullptr, b: v27, table: v26, opType: OP_TYPE_TABLE);
          goto LABEL_45;
        }
        data = v34.data;
      }
    }
    idParser::Warning(this: src, str: "Bad term '%s'", data);
    ConstantVector = idParmBlock::GetExpressionTemporaryParm(this, a2: v30, a3: v29, a4: v28);
    goto LABEL_45;
  }
  v7 = idStr::Left(this: &v35, result: &v34, len: v6 - v34.data);
  idToken::idToken(this: v36, text: v7->data);
  idStr::FreeData(this: &v35);
  v36[0].type = 1;
  v8 = idParmBlock::ParseTerm(this, src, fakeToken: v36);
  ExpressionTemporaryParm = idParmBlock::GetExpressionTemporaryParm(this, a2: v11, a3: v10, a4: v9);
  v33.numAreas = 0;
  v33.numReachableAreas = 1;
  v13 = ExpressionTemporaryParm;
  v33.numPortals = 2;
  v14 = 0;
  v33.firstPortal = 3;
  v15 = v6 + 1;
  v16 = &v33;
  while ( 1 )
  {
    v17 = v15[v14];
    if ( v17 == 0 )
      break;
    v18 = v15[v14];
    if ( v17 <= 90 && v17 >= 65 )
      v18 = v17 + 32;
    switch ( v18 )
    {
      case 'x':
      case 'r':
        v16->numAreas = 0;
        break;
      case 'y':
      case 'g':
        v16->numAreas = 1;
        break;
      case 'z':
      case 'b':
        v16->numAreas = 2;
        break;
      case 'w':
      case 'a':
        v16->numAreas = 3;
        break;
      default:
        idParser::Warning(this: src, str: "bad swizzle '%s'\n", v6);
        goto LABEL_34;
    }
    ++v14;
    v16 = (aas2Cluster_t *)((char *)v16 + 4);
    if ( v14 >= 4 )
      goto LABEL_36;
  }
LABEL_34:
  v19 = (_DWORD *)&v33 + v14 - 1;
  v20 = 4 - v14;
  do
  {
    *++v19 = v33.numAreas;
    --v20;
  }
  while ( v20 != 0 );
LABEL_36:
  ExpressionOp = idParmBlock::GetExpressionOp(this, src, constant: &v33);
  type = ExpressionOp->type;
  ExpressionOp->type = ExpressionOp->type & 0xE1E0 | 0x1E04;
  ExpressionOp->parmIndexDest = v13->parmIndex;
  parmIndex = v8->parmIndex;
  ExpressionOp->parmIndexB = 2047;
  ExpressionOp->parmIndexA = parmIndex;
  ExpressionOp->type = type & 0xE000 | 0x1E04 | (32 * v13->parmType);
  idStr::FreeData(this: &v36[0]);
  idStr::FreeData(this: &v34);
  return v13;
}


// ========================================================================
// __unwind$233811
// EA  : 0x8293CA7C
// RVA : 0x0093CA7C
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_233811()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$233812
// EA  : 0x8293CAA4
// RVA : 0x0093CAA4
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_233812()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 176));
}


// ========================================================================
// __unwind$233813
// EA  : 0x8293CACC
// RVA : 0x0093CACC
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_233813()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 208));
}


// ========================================================================
// ?ParseExpressionPriority@idParmBlock@@AAAPBVidDeclRenderParm@@AAVidParser@@H@Z
// EA  : 0x8293CB00
// RVA : 0x0093CB00
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

const idDeclRenderParm *__fastcall idParmBlock::ParseExpressionPriority(idParmBlock *this, idParser *src, int priority)
{
  const idDeclRenderParm *v7; // r28
  __int64 v8; // r8
  __int64 v9; // r6
  int v10; // r4
  const idDeclRenderParm *v11; // r3
  const idDeclRenderParm *v12; // r30
  const idDeclRenderParm *v13; // r3
  const idDeclRenderParm *v14; // r30
  const idDeclRenderParm *v15; // r3
  const idDeclRenderParm *v16; // r30
  const idDeclRenderParm *v17; // r3
  const idDeclRenderParm *v18; // r30
  const idDeclRenderParm *v19; // r3
  const idDeclRenderParm *v20; // r30
  const idDeclRenderParm *v21; // r3
  const idDeclRenderParm *v22; // r30
  const idDeclRenderParm *v23; // r3
  const idDeclRenderParm *v24; // r30
  const idDeclRenderParm *v25; // r3
  const idDeclRenderParm *v26; // r30
  const idDeclRenderParm *v27; // r3
  const idDeclRenderParm *v28; // r30
  const idDeclRenderParm *v29; // r3
  const idDeclRenderParm *v30; // r30
  const idDeclRenderParm *v31; // r3
  const idDeclRenderParm *v32; // r30
  const idDeclRenderParm *v33; // r3
  const idDeclRenderParm *v34; // r30
  const idDeclRenderParm *v35; // r3
  const idDeclRenderParm *v36; // r30
  idToken v37; // [sp+50h] [-80h] BYREF

  if ( priority == 0 )
    return idParmBlock::ParseTerm(this, src, fakeToken: nullptr);
  v7 = idParmBlock::ParseExpressionPriority(this, src, priority: priority - 1);
  if ( idParser::HadWarning(this: src) )
    return idParmBlock::GetExpressionTemporaryParm(this, a2: v10, a3: v9, a4: v8);
  v37.len = 0;
  v37.allocedAndFlag = 20;
  v37.data = v37.baseBuffer;
  v37.floatvalue = -3.4028235e38;
  v37.baseBuffer[0] = 0;
  v37.intvalue = 0;
  memset(&v37.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadToken(this: src, token: &v37) )
  {
    switch ( priority )
    {
      case 1:
        if ( idStr::Cmp(s1: v37.data, s2: "*") == 0 )
        {
          v11 = idParmBlock::ParseExpressionPriority(this, src, priority: 1);
          v12 = idParmBlock::EmitOp(this, src, a: v7, b: v11, table: nullptr, opType: OP_TYPE_MULTIPLY);
          idStr::FreeData(this: &v37);
          return v12;
        }
        if ( idStr::Cmp(s1: v37.data, s2: "/") == 0 )
        {
          v13 = idParmBlock::ParseExpressionPriority(this, src, priority: 1);
          v14 = idParmBlock::EmitOp(this, src, a: v7, b: v13, table: nullptr, opType: OP_TYPE_DIVIDE);
          idStr::FreeData(this: &v37);
          return v14;
        }
        if ( idStr::Cmp(s1: v37.data, s2: "%") == 0 )
        {
          v15 = idParmBlock::ParseExpressionPriority(this, src, priority: 1);
          v16 = idParmBlock::EmitOp(this, src, a: v7, b: v15, table: nullptr, opType: OP_TYPE_MOD);
          idStr::FreeData(this: &v37);
          return v16;
        }
        break;
      case 2:
        if ( idStr::Cmp(s1: v37.data, s2: "+") == 0 )
        {
          v17 = idParmBlock::ParseExpressionPriority(this, src, priority: 2);
          v18 = idParmBlock::EmitOp(this, src, a: v7, b: v17, table: nullptr, opType: OP_TYPE_ADD);
          idStr::FreeData(this: &v37);
          return v18;
        }
        if ( idStr::Cmp(s1: v37.data, s2: "-") == 0 )
        {
          v19 = idParmBlock::ParseExpressionPriority(this, src, priority: 2);
          v20 = idParmBlock::EmitOp(this, src, a: v7, b: v19, table: nullptr, opType: OP_TYPE_SUBTRACT);
          idStr::FreeData(this: &v37);
          return v20;
        }
        break;
      case 3:
        if ( idStr::Cmp(s1: v37.data, s2: ">") == 0 )
        {
          v21 = idParmBlock::ParseExpressionPriority(this, src, priority: 3);
          v22 = idParmBlock::EmitOp(this, src, a: v7, b: v21, table: nullptr, opType: OP_TYPE_GT);
          idStr::FreeData(this: &v37);
          return v22;
        }
        if ( idStr::Cmp(s1: v37.data, s2: ">=") == 0 )
        {
          v23 = idParmBlock::ParseExpressionPriority(this, src, priority: 3);
          v24 = idParmBlock::EmitOp(this, src, a: v7, b: v23, table: nullptr, opType: OP_TYPE_GE);
          idStr::FreeData(this: &v37);
          return v24;
        }
        if ( idStr::Cmp(s1: v37.data, s2: "<") == 0 )
        {
          v25 = idParmBlock::ParseExpressionPriority(this, src, priority: 3);
          v26 = idParmBlock::EmitOp(this, src, a: v7, b: v25, table: nullptr, opType: OP_TYPE_LT);
          idStr::FreeData(this: &v37);
          return v26;
        }
        if ( idStr::Cmp(s1: v37.data, s2: "<=") == 0 )
        {
          v27 = idParmBlock::ParseExpressionPriority(this, src, priority: 3);
          v28 = idParmBlock::EmitOp(this, src, a: v7, b: v27, table: nullptr, opType: OP_TYPE_LE);
          idStr::FreeData(this: &v37);
          return v28;
        }
        if ( idStr::Cmp(s1: v37.data, s2: "==") == 0 )
        {
          v29 = idParmBlock::ParseExpressionPriority(this, src, priority: 3);
          v30 = idParmBlock::EmitOp(this, src, a: v7, b: v29, table: nullptr, opType: OP_TYPE_EQ);
          idStr::FreeData(this: &v37);
          return v30;
        }
        if ( idStr::Cmp(s1: v37.data, s2: "!=") == 0 )
        {
          v31 = idParmBlock::ParseExpressionPriority(this, src, priority: 3);
          v32 = idParmBlock::EmitOp(this, src, a: v7, b: v31, table: nullptr, opType: OP_TYPE_NE);
          idStr::FreeData(this: &v37);
          return v32;
        }
        break;
      case 4:
        if ( idStr::Cmp(s1: v37.data, s2: "&&") == 0 )
        {
          v33 = idParmBlock::ParseExpressionPriority(this, src, priority: 4);
          v34 = idParmBlock::EmitOp(this, src, a: v7, b: v33, table: nullptr, opType: OP_TYPE_AND);
          idStr::FreeData(this: &v37);
          return v34;
        }
        if ( idStr::Cmp(s1: v37.data, s2: "||") == 0 )
        {
          v35 = idParmBlock::ParseExpressionPriority(this, src, priority: 4);
          v36 = idParmBlock::EmitOp(this, src, a: v7, b: v35, table: nullptr, opType: OP_TYPE_OR);
          idStr::FreeData(this: &v37);
          return v36;
        }
        break;
      default:
        break;
    }
    if ( idStr::Cmp(s1: v37.data, s2: ";") != 0 )
      idParser::UnreadToken(this: src, token: &v37);
  }
  idStr::FreeData(this: &v37);
  return v7;
}


// ========================================================================
// __unwind$234101
// EA  : 0x8293D084
// RVA : 0x0093D084
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_234101()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?Parse@idParmBlock@@QAAXAAVidParser@@@Z
// EA  : 0x8293D0B8
// RVA : 0x0093D0B8
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::Parse(idParmBlock *this, idParser *src)
{
  int v4; // r28
  char *v5; // r30
  _BYTE *v6; // r30
  int v7; // r10
  int v8; // r11
  int len; // r30
  char *data; // r4
  idDecl *v11; // r29
  const idDecl *v12; // r3
  int trackedMemory; // r11
  char v14; // r10
  idImage *v15; // r30
  expOp_t *ExpressionOp; // r3
  __int16 v17; // r9
  idDecl_vtbl *v18; // r6
  const char *v19; // r3
  expOp_t *v20; // r3
  __int16 v21; // r6
  idDecl_vtbl *v22; // r10
  char *v23; // r4
  const idDecl *v24; // r3
  expOp_t *v25; // r3
  __int16 v26; // r9
  idDecl_vtbl *v27; // r6
  const idDeclRenderParm *v28; // r3
  const idDeclRenderParm *v29; // r30
  expOp_t *v30; // r9
  unsigned int v31; // r11
  char v32; // r10
  char v33; // r11
  bool v34; // zf
  expOp_t *v35; // r3
  unsigned __int16 type; // r11
  unsigned __int16 v37; // r11
  int num; // [sp+50h] [-170h]
  idAtomicString v39; // [sp+54h] [-16Ch] BYREF
  aas2Cluster_t *v40; // [sp+58h] [-168h]
  idToken v41; // [sp+60h] [-160h] BYREF
  idStr v42; // [sp+B0h] [-110h] BYREF
  idStr v43; // [sp+D0h] [-F0h] BYREF
  aas2Cluster_t v44; // [sp+F0h] [-D0h] BYREF
  aas2Cluster_t v45; // [sp+100h] [-C0h] BYREF
  aas2Cluster_t v46; // [sp+110h] [-B0h] BYREF

  v41.len = 0;
  v41.baseBuffer[0] = 0;
  v41.floatvalue = -3.4028235e38;
  v41.intvalue = 0;
  memset(&v41.whiteSpaceStart_p, 0, 12);
  v41.allocedAndFlag = 20;
  v41.data = v41.baseBuffer;
  this->usingTempOps = true;
  v40 = (aas2Cluster_t *)&defaultConstant;
  currentTempParm = 0;
  if ( idParser::ExpectAnyToken(this: src, token: &v41) != 0 )
  {
    while ( 1 )
    {
      if ( idStr::Cmp(s1: v41.data, s2: "}") == 0 )
      {
LABEL_62:
        this->usingTempOps = false;
        goto LABEL_63;
      }
      if ( idStr::Cmp(s1: v41.data, s2: "{") == 0 )
      {
        idParser::Warning(this: src, str: "Can't have an open brace inside a parmBlock.");
        goto LABEL_63;
      }
      v4 = 15;
      v5 = strstr(str1: v41.data, str2: ".");
      if ( v5 != nullptr )
        break;
LABEL_14:
      data = v41.data;
      if ( v41.data != nullptr )
      {
        v12 = idDeclInfo::FindWithInheritance(this: &idDeclRenderParm::resourceList, name: v41.data, makeDefault: true);
        data = v41.data;
        v11 = (idDecl *)v12;
      }
      else
      {
        v11 = nullptr;
      }
      if ( v11->resourceError != nullptr )
      {
        idParser::Warning(this: src, str: "'%s' is an unknown renderParm.", data);
        goto LABEL_63;
      }
      idParser::CheckTokenString(this: src, string: "=");
      trackedMemory = v11[1].trackedMemory;
      if ( trackedMemory < 1 || (v14 = 1, trackedMemory > 8) )
        v14 = 0;
      if ( v14 != 0 )
      {
        v15 = idDeclRenderParm::ParseImageLine(this: (idDeclRenderParm *)v11, src);
        if ( idParser::HadWarning(this: src) )
          goto LABEL_63;
        v46.numAreas = (int)v15;
        ExpressionOp = idParmBlock::GetExpressionOp(this, src, constant: &v46);
        v17 = ExpressionOp->type & 0xE1E0;
        ExpressionOp->type = v17 | 0x1E00;
        v18 = v11[1].__vftable;
        ExpressionOp->parmIndexA = 2047;
        ExpressionOp->parmIndexB = 2047;
        ExpressionOp->parmIndexDest = (__int16)v18;
        ExpressionOp->type = v17 & 0xE01F | 0x1E00 | (32 * v11[1].trackedMemory);
        idParser::CheckTokenString(this: src, string: ";");
      }
      else if ( trackedMemory == 10 )
      {
        v42.len = 0;
        v42.baseBuffer[0] = 0;
        v42.data = v42.baseBuffer;
        v42.allocedAndFlag = 20;
        v19 = idParser::ParseRestOfLine(this: src, out: &v42);
        idAtomicString::Set(this: &v39, str_: v19);
        v44.numAreas = (int)v39.str;
        v20 = idParmBlock::GetExpressionOp(this, src, constant: &v44);
        v21 = v20->type & 0xE1E0;
        v20->type = v21 | 0x1E00;
        v22 = v11[1].__vftable;
        v20->parmIndexA = 2047;
        v20->parmIndexB = 2047;
        v20->parmIndexDest = (__int16)v22;
        v20->type = v21 & 0xE01F | 0x1E00 | (32 * v11[1].trackedMemory);
        idParser::CheckTokenString(this: src, string: ";");
        idStr::FreeData(this: &v42);
      }
      else if ( trackedMemory == 9 )
      {
        if ( idParser::ExpectAnyToken(this: src, token: &v41) == 0 )
          goto LABEL_63;
        v23 = v41.data;
        if ( v41.data == nullptr )
          goto LABEL_61;
        v24 = idDeclInfo::FindWithInheritance(this: &idDeclRenderProg::resourceList, name: v41.data, makeDefault: false);
        if ( v24 == nullptr )
        {
          v23 = v41.data;
LABEL_61:
          idParser::Warning(this: src, str: "'%s' is an unknown renderProg.", v23);
          goto LABEL_63;
        }
        v45.numAreas = (int)v24;
        v25 = idParmBlock::GetExpressionOp(this, src, constant: &v45);
        v26 = v25->type & 0xE1E0;
        v25->type = v26 | 0x1E00;
        v27 = v11[1].__vftable;
        v25->parmIndexA = 2047;
        v25->parmIndexB = 2047;
        v25->parmIndexDest = (__int16)v27;
        v25->type = v26 & 0xE01F | 0x1E00 | (32 * v11[1].trackedMemory);
        idParser::CheckTokenString(this: src, string: ";");
      }
      else
      {
        v28 = idParmBlock::ParseExpressionPriority(this, src, priority: 4);
        v29 = v28;
        if ( v28->creator == PC_TEMPORARY )
        {
          num = this->ops.num;
          if ( num > 0 && this->ops.list[num - 1].parmIndexDest == v28->parmIndex )
          {
            v30 = &this->ops.list[num];
            v31 = v30[-1].type & 0x1F;
            if ( v31 < 2 || v31 == 3 || (v32 = 0, v31 == 2) )
              v32 = 1;
            if ( v32 != 0 )
            {
              if ( v31 == 0 || (v34 = v31 != 2, v33 = 0, !v34) )
                v33 = 1;
              if ( v33 != 0 )
              {
                LOWORD(v31) = v4 == 15 ? 0 : 2;
              }
              else
              {
                LOWORD(v31) = 1;
                if ( v4 != 15 )
                  LOWORD(v31) = 3;
              }
            }
            v30[-1].type = v30[-1].type & 0xE1E0 | v31 & 0xE1FF | ((_WORD)v4 << 9);
            v30[-1].parmIndexDest = (__int16)v11[1].__vftable;
          }
        }
        else
        {
          v35 = idParmBlock::GetExpressionOp(this, src, constant: v40);
          type = v35->type;
          if ( v4 == 15 )
            v37 = type & 0xFFE0 | 1;
          else
            v37 = type & 0xFFE0 | 3;
          v35->type = v37;
          v35->type = v37 & 0xE1FF | ((_WORD)v4 << 9);
          v35->parmIndexDest = (__int16)v11[1].__vftable;
          v35->parmIndexA = v29->parmIndex;
          v35->parmIndexB = 2047;
          v35->type = v37 & 0xE01F | ((_WORD)v4 << 9) | (32 * HIWORD(v11[1].trackedMemory));
        }
        if ( idParser::HadWarning(this: src) )
          goto LABEL_62;
      }
      if ( idParser::ExpectAnyToken(this: src, token: &v41) == 0 )
        goto LABEL_63;
    }
    idStr::Left(this: &v43, result: &v41, len: v5 - v41.data);
    v6 = v5 + 1;
    v7 = (char)*v6;
    if ( *v6 != 0 )
    {
      v4 = 0;
      v8 = 0;
      while ( 1 )
      {
        for ( ; v7 != aRgba[v8]; ++v8 )
        {
          if ( v7 == aXyzw_0[v8] )
            break;
          if ( v8 >= 4 )
            goto LABEL_55;
        }
        if ( v8 >= 4 )
          break;
        v7 = (char)*++v6;
        v4 |= 1 << v8++;
        if ( *v6 == 0 )
        {
          len = v43.len;
          idStr::EnsureAlloced(this: &v41, amount: v43.len + 1, keepold: false, geometricGrowth: false);
          memcpy(Dst: v41.data, Src: v43.data, Size: len);
          v41.data[len] = 0;
          v41.len = len;
          idStr::FreeData(this: &v43);
          goto LABEL_14;
        }
      }
    }
LABEL_55:
    idParser::Warning(this: src, str: "bad write mask\n");
    idStr::FreeData(this: &v43);
  }
LABEL_63:
  idStr::FreeData(this: &v41);
}


// ========================================================================
// __unwind$234434
// EA  : 0x8293D740
// RVA : 0x0093D740
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_234434()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 96));
}


// ========================================================================
// __unwind$234435
// EA  : 0x8293D768
// RVA : 0x0093D768
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_234435()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 208));
}


// ========================================================================
// __unwind$234436
// EA  : 0x8293D790
// RVA : 0x0093D790
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _unwind_234436()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 176));
}


// ========================================================================
// ?SetImage@idParmBlock@@QAAXPBVidDeclRenderParm@@PBVidImage@@@Z
// EA  : 0x8293D7B8
// RVA : 0x0093D7B8
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void __fastcall idParmBlock::SetImage(idParmBlock *this, const idDeclRenderParm *parm, const idImage *image)
{
  parmValue_t v3; // [sp+50h] [-20h] BYREF

  v3.swizzle[0] = (int)image;
  idParmBlock::SetParm(this, parm, parmValue: &v3);
}


// ========================================================================
// `dynamic initializer for 'rp_transSortMap''_0
// EA  : 0x83358328
// RVA : 0x01358328
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _dynamic_initializer_for__rp_transSortMap___0()
{
  rp_transSortMap_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_transSortMap_0;
}


// ========================================================================
// `dynamic initializer for 'rp_transAtlasMap''_0
// EA  : 0x83358348
// RVA : 0x01358348
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _dynamic_initializer_for__rp_transAtlasMap___0()
{
  rp_transAtlasMap_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_transAtlasMap_0;
}


// ========================================================================
// `dynamic initializer for 'rp_landPageFile''_0
// EA  : 0x83358368
// RVA : 0x01358368
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _dynamic_initializer_for__rp_landPageFile___0()
{
  rp_landPageFile_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_landPageFile_0;
}


// ========================================================================
// `dynamic initializer for 'rp_landDefinitionFile''_0
// EA  : 0x83358388
// RVA : 0x01358388
// PDB : w:\tech5\engine\renderer\parmblock.cpp
// ========================================================================

void _dynamic_initializer_for__rp_landDefinitionFile___0()
{
  rp_landDefinitionFile_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_landDefinitionFile_0;
}

