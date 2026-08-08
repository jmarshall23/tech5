
// ========================================================================
// ?GetDetailSubTreesForView_r@idDetailModel@@SAXABUdm_model_t@@QAY07$$CBFPAHAAHH@Z
// EA  : 0x827CA6D0
// RVA : 0x007CA6D0
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void __fastcall idDetailModel::GetDetailSubTreesForView_r(
        const dm_model_t *model,
        const __int16 (*frustumVerts)[8],
        int *subTreeNums,
        int *numSubTrees,
        const int nodeNum)
{
  dm_treeNode_t *v9; // r29
  int v10; // r7
  int v11; // r30
  int v12; // r10
  int v13; // ctr
  int v14; // r8
  unsigned int planeDist; // r11
  const __int16 *v16; // r9
  unsigned int v17; // r24
  unsigned int v18; // r22
  unsigned int v19; // r3
  unsigned int v20; // r25

  if ( (nodeNum & 0x8000) != 0 )
  {
LABEL_8:
    subTreeNums[(*numSubTrees)++] = nodeNum & 0xFFFF7FFF;
  }
  else
  {
    while ( 1 )
    {
      v9 = &model->treeNodes[nodeNum];
      v10 = 0;
      v11 = 0;
      v12 = 0;
      v13 = 2;
      v14 = __ROL4__(v9->planeType, 3);
      planeDist = v9->planeDist;
      do
      {
        v16 = &(*frustumVerts)[v14 + v12];
        v17 = *v16;
        v18 = v16[1];
        v19 = (*frustumVerts)[v14 + 2 + v12];
        v20 = (*frustumVerts)[v14 + 3 + v12];
        v10 |= (((int)v20 >> 31) + (v20 >= planeDist) + (planeDist >> 31))
             | (((int)v19 >> 31) + (v19 >= planeDist) + (planeDist >> 31))
             | (((int)v18 >> 31) + (v18 >= planeDist) + (planeDist >> 31))
             | (((int)v17 >> 31) + (v17 >= planeDist) + (planeDist >> 31));
        v11 |= (((int)planeDist >> 31) + (planeDist >= v20) + (v20 >> 31))
             | (((int)planeDist >> 31) + (planeDist >= v19) + (v19 >> 31))
             | (((int)planeDist >> 31) + (planeDist >= v18) + (v18 >> 31))
             | (((int)planeDist >> 31) + (planeDist >= v17) + (v17 >> 31));
        v12 += 4;
        --v13;
      }
      while ( v13 != 0 );
      if ( v10 != 0 )
        idDetailModel::GetDetailSubTreesForView_r(
          model,
          frustumVerts,
          subTreeNums,
          numSubTrees,
          nodeNum: v9->children[0]);
      if ( v11 == 0 )
        break;
      nodeNum = v9->children[1];
      if ( (nodeNum & 0x8000) != 0 )
        goto LABEL_8;
    }
  }
}


// ========================================================================
// ?GetDetailSubTreesForView@idDetailModel@@SAHABUdm_model_t@@PBUdetailRenderView_t@@PAH@Z
// EA  : 0x827CA870
// RVA : 0x007CA870
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

int __fastcall idDetailModel::GetDetailSubTreesForView(
        const dm_model_t *model,
        const detailRenderView_t *viewData,
        int *subTreeNums)
{
  double nearDist; // fp0
  double farDist; // fp13
  idVec3 *p_viewUp; // r11
  double v7; // fp12
  double v8; // fp11
  double v9; // fp6
  double v10; // fp1
  double v11; // fp9
  double v12; // fp7
  double v13; // fp4
  double v14; // fp10
  double v15; // fp2
  double v16; // fp7
  double v17; // fp8
  double v18; // fp5
  double v19; // fp0
  double v20; // fp8
  double v21; // fp7
  double v22; // fp9
  char *v23; // r8
  float *p_y; // r9
  double v25; // fp4
  double v26; // fp2
  double v27; // fp9
  double v28; // fp6
  double v29; // fp1
  double v30; // fp10
  double v31; // fp7
  double v32; // fp2
  double v33; // fp9
  int v34; // ctr
  double v35; // fp2
  double v36; // fp3
  double v37; // fp1
  double v38; // fp11
  double v39; // fp10
  __int16 v40; // r11
  double v41; // fp0
  int v42; // r11
  double v43; // fp0
  int v44; // r11
  int v45; // [sp+50h] [-60h] BYREF
  int v46; // [sp+54h] [-5Ch]
  __int16 v47[8]; // [sp+60h] [-50h] BYREF
  char v48; // [sp+7Eh] [-32h] BYREF

  if ( model->numTreeNodes != 0 )
  {
    nearDist = viewData->nearDist;
    farDist = viewData->farDist;
    p_viewUp = &viewData->viewUp;
    v7 = viewData->fov[0];
    v8 = viewData->fov[1];
    if ( (_S13_18 & 1) == 0 )
      _S13_18 |= 1u;
    v9 = (float)((float)((float)(viewData->viewFwd.z * (float)nearDist) + viewData->viewOrg.z)
               + (float)((float)(viewData->viewLeft.z * (float)nearDist) * (float)v7));
    v10 = (float)((float)(viewData->viewUp.z * (float)nearDist) * (float)v8);
    v11 = (float)((float)((float)((float)(viewData->viewFwd.y * (float)nearDist) + viewData->viewOrg.y)
                        + (float)((float)(viewData->viewLeft.y * (float)nearDist) * (float)v7))
                + (float)((float)(viewData->viewUp.y * (float)nearDist) * (float)v8));
    frustumVerts[0].x = (float)((float)((float)(viewData->viewFwd.x * (float)nearDist) + viewData->viewOrg.x)
                              + (float)((float)(viewData->viewLeft.x * (float)nearDist) * (float)v7))
                      + (float)((float)(p_viewUp->x * (float)nearDist) * (float)v8);
    frustumVerts[0].y = v11;
    frustumVerts[0].z = (float)v9 + (float)v10;
    v12 = (float)((float)(viewData->viewUp.z * (float)nearDist) * (float)v8);
    v13 = (float)((float)((float)(viewData->viewFwd.z * (float)nearDist) + viewData->viewOrg.z)
                - (float)((float)(viewData->viewLeft.z * (float)nearDist) * (float)v7));
    v14 = (float)((float)((float)((float)(viewData->viewFwd.x * (float)nearDist) + viewData->viewOrg.x)
                        - (float)((float)(viewData->viewLeft.x * (float)nearDist) * (float)v7))
                + (float)((float)(p_viewUp->x * (float)nearDist) * (float)v8));
    frustumVerts[1].y = (float)((float)((float)(viewData->viewFwd.y * (float)nearDist) + viewData->viewOrg.y)
                              - (float)((float)(viewData->viewLeft.y * (float)nearDist) * (float)v7))
                      + (float)((float)(viewData->viewUp.y * (float)nearDist) * (float)v8);
    frustumVerts[1].x = v14;
    frustumVerts[1].z = (float)v13 + (float)v12;
    v15 = (float)((float)(p_viewUp->x * (float)nearDist) * (float)v8);
    v16 = (float)((float)((float)(viewData->viewFwd.x * (float)nearDist) + viewData->viewOrg.x)
                - (float)((float)(viewData->viewLeft.x * (float)nearDist) * (float)v7));
    v17 = (float)((float)((float)((float)(viewData->viewFwd.z * (float)nearDist) + viewData->viewOrg.z)
                        - (float)((float)(viewData->viewLeft.z * (float)nearDist) * (float)v7))
                - (float)((float)(viewData->viewUp.z * (float)nearDist) * (float)v8));
    frustumVerts[2].y = (float)((float)((float)(viewData->viewFwd.y * (float)nearDist) + viewData->viewOrg.y)
                              - (float)((float)(viewData->viewLeft.y * (float)nearDist) * (float)v7))
                      - (float)((float)(viewData->viewUp.y * (float)nearDist) * (float)v8);
    frustumVerts[2].z = v17;
    frustumVerts[2].x = (float)v16 - (float)v15;
    v18 = (float)((float)(viewData->viewUp.y * (float)nearDist) * (float)v8);
    v20 = (float)((float)((float)(viewData->viewFwd.x * (float)nearDist) + viewData->viewOrg.x)
                + (float)((float)(viewData->viewLeft.x * (float)nearDist) * (float)v7));
    v21 = (float)((float)((float)(viewData->viewFwd.y * (float)nearDist) + viewData->viewOrg.y)
                + (float)((float)(viewData->viewLeft.y * (float)nearDist) * (float)v7));
    v22 = (float)((float)((float)((float)(viewData->viewFwd.z * (float)nearDist) + viewData->viewOrg.z)
                        + (float)((float)(viewData->viewLeft.z * (float)nearDist) * (float)v7))
                - (float)((float)(viewData->viewUp.z * (float)nearDist) * (float)v8));
    v19 = (float)((float)(p_viewUp->x * (float)nearDist) * (float)v8);
    frustumVerts[3].z = v22;
    frustumVerts[3].x = (float)v20 - (float)v19;
    frustumVerts[3].y = (float)v21 - (float)v18;
    v23 = &v48;
    p_y = &frustumVerts[0].y;
    v25 = (float)((float)(viewData->viewUp.y * (float)farDist) * (float)v8);
    v26 = (float)((float)((float)(viewData->viewFwd.y * (float)farDist) + viewData->viewOrg.y)
                + (float)((float)(viewData->viewLeft.y * (float)farDist) * (float)v7));
    v27 = (float)((float)((float)((float)(viewData->viewFwd.z * (float)farDist) + viewData->viewOrg.z)
                        + (float)((float)(viewData->viewLeft.z * (float)farDist) * (float)v7))
                + (float)((float)(viewData->viewUp.z * (float)farDist) * (float)v8));
    frustumVerts[4].x = (float)((float)((float)(viewData->viewFwd.x * (float)farDist) + viewData->viewOrg.x)
                              + (float)((float)(viewData->viewLeft.x * (float)farDist) * (float)v7))
                      + (float)((float)(p_viewUp->x * (float)farDist) * (float)v8);
    frustumVerts[4].z = v27;
    frustumVerts[4].y = (float)v26 + (float)v25;
    v28 = (float)((float)(viewData->viewUp.z * (float)farDist) * (float)v8);
    v29 = (float)((float)((float)(viewData->viewFwd.z * (float)farDist) + viewData->viewOrg.z)
                - (float)((float)(viewData->viewLeft.z * (float)farDist) * (float)v7));
    v30 = (float)((float)((float)((float)(viewData->viewFwd.y * (float)farDist) + viewData->viewOrg.y)
                        - (float)((float)(viewData->viewLeft.y * (float)farDist) * (float)v7))
                + (float)((float)(viewData->viewUp.y * (float)farDist) * (float)v8));
    frustumVerts[5].x = (float)((float)((float)(viewData->viewFwd.x * (float)farDist) + viewData->viewOrg.x)
                              - (float)((float)(viewData->viewLeft.x * (float)farDist) * (float)v7))
                      + (float)((float)(p_viewUp->x * (float)farDist) * (float)v8);
    frustumVerts[5].y = v30;
    frustumVerts[5].z = (float)v29 + (float)v28;
    v31 = (float)((float)(viewData->viewUp.y * (float)farDist) * (float)v8);
    v32 = (float)((float)((float)(viewData->viewFwd.y * (float)farDist) + viewData->viewOrg.y)
                - (float)((float)(viewData->viewLeft.y * (float)farDist) * (float)v7));
    v33 = (float)((float)((float)((float)(viewData->viewFwd.z * (float)farDist) + viewData->viewOrg.z)
                        - (float)((float)(viewData->viewLeft.z * (float)farDist) * (float)v7))
                - (float)((float)(viewData->viewUp.z * (float)farDist) * (float)v8));
    frustumVerts[6].x = (float)((float)((float)(viewData->viewFwd.x * (float)farDist) + viewData->viewOrg.x)
                              - (float)((float)(viewData->viewLeft.x * (float)farDist) * (float)v7))
                      - (float)((float)(p_viewUp->x * (float)farDist) * (float)v8);
    frustumVerts[6].z = v33;
    frustumVerts[6].y = (float)v32 - (float)v31;
    v34 = 8;
    v35 = (float)((float)(viewData->viewUp.y * (float)farDist) * (float)v8);
    v36 = (float)((float)(p_viewUp->x * (float)farDist) * (float)v8);
    v37 = (float)((float)(viewData->viewUp.z * (float)farDist) * (float)v8);
    v38 = (float)((float)((float)(viewData->viewFwd.y * (float)farDist) + viewData->viewOrg.y)
                + (float)((float)(viewData->viewLeft.y * (float)farDist) * (float)v7));
    v39 = (float)((float)((float)(viewData->viewFwd.z * (float)farDist) + viewData->viewOrg.z)
                + (float)((float)(viewData->viewLeft.z * (float)farDist) * (float)v7));
    frustumVerts[7].x = (float)((float)((float)(viewData->viewFwd.x * (float)farDist) + viewData->viewOrg.x)
                              + (float)((float)(viewData->viewLeft.x * (float)farDist) * (float)v7))
                      - (float)v36;
    frustumVerts[7].y = (float)v38 - (float)v35;
    frustumVerts[7].z = (float)v39 - (float)v37;
    do
    {
      v46 = (int)*(p_y - 1);
      v40 = v46;
      if ( v46 >= -32768 )
      {
        if ( v46 > 0x7FFF )
          v40 = 0x7FFF;
      }
      else
      {
        v40 = 0x8000;
      }
      v41 = *p_y;
      *((_WORD *)v23 - 15) = v40;
      v46 = (int)v41;
      v42 = (int)v41;
      if ( (int)v41 >= -32768 )
      {
        if ( v42 > 0x7FFF )
          LOWORD(v42) = 0x7FFF;
      }
      else
      {
        LOWORD(v42) = 0x8000;
      }
      v43 = p_y[1];
      *((_WORD *)v23 - 7) = v42;
      v46 = (int)v43;
      v44 = (int)v43;
      if ( (int)v43 >= -32768 )
      {
        if ( v44 > 0x7FFF )
          LOWORD(v44) = 0x7FFF;
      }
      else
      {
        LOWORD(v44) = 0x8000;
      }
      v23 += 2;
      *(_WORD *)v23 = v44;
      p_y += 3;
      --v34;
    }
    while ( v34 != 0 );
    v45 = 0;
    idDetailModel::GetDetailSubTreesForView_r(
      model,
      frustumVerts: (const __int16 (*)[8])v47,
      subTreeNums,
      numSubTrees: &v45,
      nodeNum: 0);
    return v45;
  }
  else
  {
    *subTreeNums = 0;
    return 1;
  }
}


// ========================================================================
// ?FreeData@idFoliageModel@@QAAXXZ
// EA  : 0x827CAF98
// RVA : 0x007CAF98
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void __fastcall idFoliageModel::FreeData(idDetailModel *this)
{
  int v2; // r29
  int v3; // r30
  dm_treeNode_t *treeNodes; // r4
  const idDeclDetail **list; // r4

  if ( this->detailModelData.subTrees != nullptr )
  {
    v2 = 0;
    if ( this->detailModelData.numSubTrees > 0 )
    {
      v3 = 0;
      do
      {
        idMem::Free(this: &mem, ptr: this->detailModelData.subTrees[v3].data, align: ALIGN_16);
        idMem::Free(this: &mem, ptr: this->detailModelData.subTrees[v3].treeNodes, align: ALIGN_16);
        ++v2;
        ++v3;
      }
      while ( v2 < this->detailModelData.numSubTrees );
    }
    idMem::Free(this: &mem, ptr: this->detailModelData.subTrees, align: ALIGN_16);
  }
  treeNodes = this->detailModelData.treeNodes;
  if ( treeNodes != nullptr )
    idMem::Free(this: &mem, ptr: treeNodes, align: ALIGN_16);
  this->detailModelData.numTreeNodes = 0;
  this->detailModelData.numSubTrees = 0;
  this->detailModelData.treeNodes = nullptr;
  this->detailModelData.subTrees = nullptr;
  this->stats.numDetailNodes = 0;
  this->stats.numTreeNodes = 0;
  this->stats.numSubTrees = 0;
  if ( this->sharedAttributes.listStatic == 0 || this->sharedAttributes.listStatic == 2 )
  {
    list = this->sharedAttributes.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->sharedAttributes.list = nullptr;
    this->sharedAttributes.size = 0;
  }
  this->sharedAttributes.num = 0;
}


// ========================================================================
// ??1idDetailModel@@UAA@XZ
// EA  : 0x827CB168
// RVA : 0x007CB168
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void __fastcall idDetailModel::~idDetailModel(idDetailModel *this)
{
  this->__vftable = (idDetailModel_vtbl *)&idDetailModel::`vftable';
  idFoliageModel::FreeData(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sharedAttributes);
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$234396
// EA  : 0x827CB1C0
// RVA : 0x007CB1C0
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void _unwind_234396()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$234397
// EA  : 0x827CB1E8
// RVA : 0x007CB1E8
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void _unwind_234397()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}


// ========================================================================
// ??0idDetailModel@@QAA@XZ
// EA  : 0x827CB230
// RVA : 0x007CB230
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

idDetailModel *__fastcall idDetailModel::idDetailModel(idDetailModel *this)
{
  idResource::idResource(this);
  this->__vftable = (idDetailModel_vtbl *)&idDetailModel::`vftable';
  this->sharedAttributes.list = nullptr;
  this->sharedAttributes.granularity = 0;
  this->sharedAttributes.memTag = 5;
  this->sharedAttributes.listStatic = 0;
  this->sharedAttributes.size = 0;
  this->sharedAttributes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sharedAttributes);
  this->detailModelData.numTreeNodes = 0;
  this->detailModelData.numSubTrees = 0;
  this->detailModelData.treeNodes = nullptr;
  this->detailModelData.subTrees = nullptr;
  this->stats.numDetailNodes = 0;
  this->stats.numTreeNodes = 0;
  this->stats.numSubTrees = 0;
  if ( this->sharedAttributes.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sharedAttributes);
  this->sharedAttributes.num = __CFADD__(-this->sharedAttributes.size, this->sharedAttributes.size ^ 0x80000000)
                             ? 0
                             : this->sharedAttributes.size;
  return this;
}


// ========================================================================
// __unwind$234790
// EA  : 0x827CB2E0
// RVA : 0x007CB2E0
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void _unwind_234790()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$234791
// EA  : 0x827CB308
// RVA : 0x007CB308
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void _unwind_234791()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 52));
}


// ========================================================================
// ?Load_Binary@idDetailModel@@QAA_NPBD@Z
// EA  : 0x827CB3A0
// RVA : 0x007CB3A0
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

int __fastcall idDetailModel::Load_Binary(idDetailModel *this, const char *detailFileName)
{
  idFile *v3; // r3
  idFile *v4; // r30
  unsigned int v6; // r29
  int v7; // r27
  const idDeclDetail *v8; // r3
  int *p_numSubTrees; // r21
  dm_subTree_t *v10; // r3
  int numSubTrees; // r4
  int v12; // r22
  int v13; // r29
  dm_subTreeTreeNodes_t *treeNodes; // r7
  dm_subTree_t *v15; // r11
  const dm_subTreeTreeNodes_t *v16; // r18
  const dm_subTreeData_t *data; // r26
  int i; // r10
  int numAttributes; // r10
  int j; // r11
  int k; // r11
  int v22; // r4
  int v23; // r27
  int size; // r11
  bool v25; // r3
  int v26; // r10
  int v27; // r11
  int v28; // r27
  char v29; // r3
  int v30; // r4
  int v31; // r27
  int v32; // r11
  char v33; // r3
  int v34; // r26
  int v35; // r29
  int v36; // r27
  dm_subTree_t *v37; // r30
  int numTreeNodes; // r11
  int v39; // r10
  unsigned int v40; // [sp+50h] [-E0h] BYREF
  int v41; // [sp+54h] [-DCh] BYREF
  int v42; // [sp+58h] [-D8h] BYREF
  int v43; // [sp+5Ch] [-D4h] BYREF
  int v44; // [sp+60h] [-D0h] BYREF
  dm_subTreeTreeNodePtrs_t v45; // [sp+64h] [-CCh] BYREF
  dm_subTreeDataPtrs_t v46; // [sp+68h] [-C8h] BYREF
  idStr v47; // [sp+70h] [-C0h] BYREF
  idStr v48[5]; // [sp+90h] [-A0h] BYREF

  idStr::idStr(this: &v47, text: detailFileName);
  idStr::SetFileExtension(this: &v47, extension: "bdetail");
  v3 = fileSystem->OpenFileRead(this: fileSystem, a2: v47.data, a3: 1, a4: 0);
  v4 = v3;
  if ( v3 == nullptr )
  {
    idLib::Printf(fmt: "couldn't open file %s for read\n", v47.data);
    idStr::FreeData(this: &v47);
    return 0;
  }
  v3->Read(this: v3, a2: &v44, a3: 4u);
  if ( v44 != 1145394179 )
  {
    idLib::Warning(fmt: "%s is not a binary detail file", v47.data);
    ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
    idFoliageModel::FreeData(this);
    idStr::FreeData(this: &v47);
    return 0;
  }
  v4->Read(this: v4, a2: &v40, a3: 4u);
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->sharedAttributes, newNum: v40);
  v6 = 0;
  if ( v40 != 0 )
  {
    v7 = 0;
    do
    {
      v48[0].allocedAndFlag = 20;
      v48[0].len = 0;
      v48[0].data = v48[0].baseBuffer;
      v48[0].baseBuffer[0] = 0;
      idFile::ReadString(this: v4, string: v48);
      if ( v48[0].data != nullptr )
        v8 = (const idDeclDetail *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclDetail::resourceList,
                                     name: v48[0].data,
                                     makeDefault: true);
      else
        v8 = nullptr;
      this->sharedAttributes.list[v7] = v8;
      idStr::FreeData(this: v48);
      ++v6;
      ++v7;
    }
    while ( v6 < v40 );
  }
  v4->Read(this: v4, a2: &this->detailModelData, a3: 4u);
  this->detailModelData.treeNodes = (dm_treeNode_t *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\engine\\models\\detail\\DetailModel.cpp(335) : TAG_DETAIL",
                                                       size: 16 * this->detailModelData.numTreeNodes,
                                                       tag: TAG_DETAIL,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
  ((void (__fastcall *)(idFile *))v4->Read)(a1: v4);
  p_numSubTrees = &this->detailModelData.numSubTrees;
  v4->Read(this: v4, a2: &this->detailModelData.numSubTrees, a3: 4u);
  v10 = (dm_subTree_t *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\engine\\models\\detail\\DetailModel.cpp(343) : TAG_DETAIL",
                          size: 32 * this->detailModelData.numSubTrees,
                          tag: TAG_DETAIL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  numSubTrees = this->detailModelData.numSubTrees;
  this->detailModelData.subTrees = v10;
  v12 = 0;
  if ( numSubTrees > 0 )
  {
    v13 = 0;
    do
    {
      v4->Read(this: v4, a2: &this->detailModelData.subTrees[v13], a3: 8u);
      v4->Read(this: v4, a2: this->detailModelData.subTrees[v13].bounds.b[1], a3: 8u);
      v4->Read(this: v4, a2: &this->detailModelData.subTrees[v13].maxDetailHeight, a3: 2u);
      v4->Read(this: v4, a2: &this->detailModelData.subTrees[v13].totalDataSize, a3: 4u);
      v4->Read(this: v4, a2: &this->detailModelData.subTrees[v13].totalTreeNodeSize, a3: 2u);
      this->detailModelData.subTrees[v13].data = (dm_subTreeData_t *)idMem::AllocWithLocation(
                                                                       this: &mem,
                                                                       location: "w:\\tech5\\engine\\models\\detail\\DetailModel.cp"
                                                                       "p(352) : TAG_DETAIL",
                                                                       size: this->detailModelData.subTrees[v13].totalDataSize,
                                                                       tag: TAG_DETAIL,
                                                                       zeroBuffer: false,
                                                                       align: ALIGN_16,
                                                                       heap: HEAP_DEFAULTHEAP);
      v4->Read(
        this: v4,
        a2: this->detailModelData.subTrees[v13].data,
        a3: this->detailModelData.subTrees[v13].totalDataSize);
      this->detailModelData.subTrees[v13].treeNodes = (dm_subTreeTreeNodes_t *)idMem::AllocWithLocation(
                                                                                 this: &mem,
                                                                                 location: "w:\\tech5\\engine\\models\\detail\\Deta"
                                                                                 "ilModel.cpp(355) : TAG_DETAIL",
                                                                                 size: this->detailModelData.subTrees[v13].totalTreeNodeSize,
                                                                                 tag: TAG_DETAIL,
                                                                                 zeroBuffer: false,
                                                                                 align: ALIGN_16,
                                                                                 heap: HEAP_DEFAULTHEAP);
      v4->Read(
        this: v4,
        a2: this->detailModelData.subTrees[v13].treeNodes,
        a3: this->detailModelData.subTrees[v13].totalTreeNodeSize);
      treeNodes = this->detailModelData.subTrees[v13].treeNodes;
      treeNodes->pad[1] = 0;
      treeNodes->pad[0] = 0;
      v15 = &this->detailModelData.subTrees[v13];
      v16 = v15->treeNodes;
      data = v15->data;
      SetupSubTreePtrsFromTreeNodes(subTreePtrs: &v45, subTree: v16);
      for ( i = 0; i < v16->numTreeNodes; ++i )
        ;
      SetupSubTreePtrsFromTreeNodes(subTreePtrs: &v46, subTree: data);
      numAttributes = data->numAttributes;
      for ( j = 0; j < numAttributes; ++j )
        ;
      for ( k = 0; k < data->numDetail; ++k )
        ;
      ++v12;
      ++v13;
    }
    while ( v12 < *p_numSubTrees );
  }
  v4->Read(this: v4, a2: &v41, a3: 4u);
  v22 = v41;
  v23 = v41;
  size = idDetailModel::paletteEntries.size;
  if ( v41 > idDetailModel::paletteEntries.size )
  {
    v25 = idList<detailPaletteEntry_t,5>::Resize(this: &idDetailModel::paletteEntries, newsize: v41);
    v22 = v41;
    if ( !v25 )
      goto LABEL_26;
    size = idDetailModel::paletteEntries.size;
  }
  if ( v23 >= size )
    idDetailModel::paletteEntries.num = size;
  else
    idDetailModel::paletteEntries.num = v23;
LABEL_26:
  v4->Read(this: v4, a2: idDetailModel::paletteEntries.list, a3: 8 * v22);
  v4->Read(this: v4, a2: &v42, a3: 4u);
  v26 = idDetailModel::paletteVerts.size;
  v27 = v42;
  v28 = v42;
  if ( v42 > idDetailModel::paletteVerts.size )
  {
    v29 = idList<detailPaletteVert_t,5>::Resize(this: &idDetailModel::paletteVerts, newsize: v42);
    v27 = v42;
    if ( v29 == 0 )
      goto LABEL_32;
    v26 = idDetailModel::paletteVerts.size;
  }
  if ( v28 >= v26 )
    idDetailModel::paletteVerts.num = v26;
  else
    idDetailModel::paletteVerts.num = v28;
LABEL_32:
  v4->Read(this: v4, a2: idDetailModel::paletteVerts.list, a3: 10 * v27);
  v4->Read(this: v4, a2: &v43, a3: 4u);
  v30 = v43;
  v31 = v43;
  v32 = idDetailModel::paletteIndices.size;
  if ( v43 > idDetailModel::paletteIndices.size )
  {
    v33 = idList<unsigned short,30>::Resize(this: &idDetailModel::paletteIndices, newsize: v43);
    v30 = v43;
    if ( v33 == 0 )
      goto LABEL_38;
    v32 = idDetailModel::paletteIndices.size;
  }
  if ( v31 >= v32 )
    idDetailModel::paletteIndices.num = v32;
  else
    idDetailModel::paletteIndices.num = v31;
LABEL_38:
  v4->Read(this: v4, a2: idDetailModel::paletteIndices.list, a3: 2 * v30);
  v4->Read(this: v4, a2: &v44, a3: 4u);
  if ( v44 == 1145394179 )
  {
    ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
    v34 = 0;
    v35 = 0;
    if ( *p_numSubTrees > 0 )
    {
      v36 = 0;
      do
      {
        v37 = &this->detailModelData.subTrees[v36];
        SetupSubTreePtrsFromTreeNodes(subTreePtrs: &v46, subTree: v37->data);
        ++v35;
        ++v36;
        v34 += v37->data->numDetail;
      }
      while ( v35 < *p_numSubTrees );
    }
    numTreeNodes = this->detailModelData.numTreeNodes;
    v39 = *p_numSubTrees;
    this->stats.numDetailNodes = v34;
    this->stats.numTreeNodes = numTreeNodes;
    this->stats.numSubTrees = v39;
    idStr::FreeData(this: &v47);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "%s is invalid", v47.data);
    ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
    idStr::FreeData(this: &v47);
    return 0;
  }
}


// ========================================================================
// __unwind$235163
// EA  : 0x827CBAAC
// RVA : 0x007CBAAC
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void _unwind_235163()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$235164
// EA  : 0x827CBAD4
// RVA : 0x007CBAD4
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void _unwind_235164()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 144));
}


// ========================================================================
// ?LoadResource@idDetailModel@@UAAXXZ
// EA  : 0x827CBBA8
// RVA : 0x007CBBA8
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void __fastcall idDetailModel::LoadResource(idDetailModel *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  int v5; // [sp+8h] [-58h]
  int v6; // [sp+Ch] [-54h]
  int v7; // [sp+10h] [-50h]
  int v8; // [sp+14h] [-4Ch]
  int v9; // [sp+18h] [-48h]
  int v10; // [sp+1Ch] [-44h]

  idFoliageModel::FreeData(this);
  if ( (unsigned __int8)idDetailModel::Load_Binary(this, detailFileName: this->name.str) == 0 )
  {
    HIDWORD(v4) = this->name.str;
    idResource::SetResourceError(
      this,
      fmt: "Couldn't load detailmodel '%s'",
      a3: v4,
      a4: v3,
      a5: v2,
      a6: v5,
      a7: v6,
      a8: v7,
      a9: v8,
      a10: v9,
      a11: v10);
    idFoliageModel::FreeData(this);
  }
}


// ========================================================================
// `dynamic initializer for 'r_detailFadeDistMax''
// EA  : 0x83342540
// RVA : 0x01342540
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_detailFadeDistMax__()
{
  idCVar::idCVar(
    this: &r_detailFadeDistMax,
    name: "r_detailFadeDistMax",
    value: "3500",
    flags: 4,
    description: "detail models will be completely faded out at this range",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_detailFadeDistMax__);
}


// ========================================================================
// `dynamic initializer for 'idDetailModel::resourceList''
// EA  : 0x83342598
// RVA : 0x01342598
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDetailModel::resourceList__()
{
  idResourceList::idResourceList(this: &idDetailModel::resourceList, typeName: "detailModel");
  idDetailModel::resourceList.__vftable = (idTypedResourceList<idDetailModel>_vtbl *)&idTypedResourceList<idDetailModel>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDetailModel::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'idDetailModel::paletteEntries''
// EA  : 0x833425E8
// RVA : 0x013425E8
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDetailModel::paletteEntries__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDetailModel::paletteEntries__);
}


// ========================================================================
// `dynamic initializer for 'idDetailModel::paletteVerts''
// EA  : 0x833425F8
// RVA : 0x013425F8
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDetailModel::paletteVerts__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDetailModel::paletteVerts__);
}


// ========================================================================
// `dynamic initializer for 'idDetailModel::paletteIndices''
// EA  : 0x83342608
// RVA : 0x01342608
// PDB : w:\tech5\engine\models\detail\detailmodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDetailModel::paletteIndices__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDetailModel::paletteIndices__);
}

