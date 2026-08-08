
// ========================================================================
// ?GetFoliageSubTreesForView_r@idFoliageModel@@SAXABUfm_model_t@@QAY07$$CBFPAHAAHH@Z
// EA  : 0x827D5E60
// RVA : 0x007D5E60
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void __fastcall idFoliageModel::GetFoliageSubTreesForView_r(
        const fm_model_t *model,
        const __int16 (*frustumVerts)[8],
        int *subTreeNums,
        int *numSubTrees,
        const int nodeNum)
{
  fm_treeNode_t *v9; // r29
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
        idFoliageModel::GetFoliageSubTreesForView_r(
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
// ?InitializeAttributes@idFoliageModel@@CAXPAUfm_model_t@@AAV?$idList@PBVidDeclFoliage@@$04@@I@Z
// EA  : 0x827D6000
// RVA : 0x007D6000
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void __fastcall idFoliageModel::InitializeAttributes(
        fm_model_t *model,
        idList<idDeclFoliage const *,5> *uniqueDecls,
        unsigned int magic)
{
  int v6; // r22
  int v7; // r24
  fm_subTree_t *v8; // r31
  int v9; // r28
  fm_subTreeData_t *data; // r27
  int v11; // r30
  char *v12; // r31
  float *v13; // r11
  const idMaterial *material; // r4
  char v15; // r3
  dm_subTreeDataPtrs_t v16; // [sp+50h] [-70h] BYREF

  if ( model != nullptr )
  {
    v6 = 0;
    if ( model->numSubTrees > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &model->subTrees[v7];
        SetupSubTreePtrsFromTreeNodes(subTreePtrs: &v16, subTree: (const dm_subTreeData_t *)v8->data);
        v9 = 0;
        data = v8->data;
        if ( data->numFoliage > 0 )
        {
          v11 = 0;
          do
          {
            v12 = (char *)v16.detail + v11 * 2;
            v13 = (float *)((char *)&v16.attributes->declIdx + __ROL4__(HIBYTE(v16.detail->xyz[v11 + 3]), 5));
            material = (*(const idDeclFoliage **)((char *)uniqueDecls->list + __ROL4__(
                                                                                *((unsigned __int16 *)v13 + 8),
                                                                                2)))->material;
            *v13 = material->atlasScaleBias.x;
            v13[1] = material->atlasScaleBias.y;
            v13[2] = material->atlasScaleBias.z;
            v13[3] = material->atlasScaleBias.w;
            if ( magic <= 0x464F4C06 )
            {
              v15 = idMath::Ftob(f: 128.0);
              v12[12] = v15;
              v12[13] = v15;
              v12[14] = idMath::Ftob(f: 255.5);
            }
            ++v9;
            v11 += 8;
          }
          while ( v9 < data->numFoliage );
        }
        ++v6;
        ++v7;
      }
      while ( v6 < model->numSubTrees );
    }
  }
}


// ========================================================================
// ?GetFoliageSubTreesForView@idFoliageModel@@SAHABUfm_model_t@@PBUfoliageRenderView_t@@PAH@Z
// EA  : 0x827D6128
// RVA : 0x007D6128
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

int __fastcall idFoliageModel::GetFoliageSubTreesForView(
        const fm_model_t *model,
        const foliageRenderView_t *viewData,
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
    if ( (_S13_19 & 1) == 0 )
      _S13_19 |= 1u;
    v9 = (float)((float)((float)(viewData->viewFwd.z * (float)nearDist) + viewData->viewOrg.z)
               + (float)((float)(viewData->viewLeft.z * (float)nearDist) * (float)v7));
    v10 = (float)((float)(viewData->viewUp.z * (float)nearDist) * (float)v8);
    v11 = (float)((float)((float)((float)(viewData->viewFwd.y * (float)nearDist) + viewData->viewOrg.y)
                        + (float)((float)(viewData->viewLeft.y * (float)nearDist) * (float)v7))
                + (float)((float)(viewData->viewUp.y * (float)nearDist) * (float)v8));
    frustumVerts_0[0].x = (float)((float)((float)(viewData->viewFwd.x * (float)nearDist) + viewData->viewOrg.x)
                                + (float)((float)(viewData->viewLeft.x * (float)nearDist) * (float)v7))
                        + (float)((float)(p_viewUp->x * (float)nearDist) * (float)v8);
    frustumVerts_0[0].y = v11;
    frustumVerts_0[0].z = (float)v9 + (float)v10;
    v12 = (float)((float)(viewData->viewUp.z * (float)nearDist) * (float)v8);
    v13 = (float)((float)((float)(viewData->viewFwd.z * (float)nearDist) + viewData->viewOrg.z)
                - (float)((float)(viewData->viewLeft.z * (float)nearDist) * (float)v7));
    v14 = (float)((float)((float)((float)(viewData->viewFwd.x * (float)nearDist) + viewData->viewOrg.x)
                        - (float)((float)(viewData->viewLeft.x * (float)nearDist) * (float)v7))
                + (float)((float)(p_viewUp->x * (float)nearDist) * (float)v8));
    frustumVerts_0[1].y = (float)((float)((float)(viewData->viewFwd.y * (float)nearDist) + viewData->viewOrg.y)
                                - (float)((float)(viewData->viewLeft.y * (float)nearDist) * (float)v7))
                        + (float)((float)(viewData->viewUp.y * (float)nearDist) * (float)v8);
    frustumVerts_0[1].x = v14;
    frustumVerts_0[1].z = (float)v13 + (float)v12;
    v15 = (float)((float)(p_viewUp->x * (float)nearDist) * (float)v8);
    v16 = (float)((float)((float)(viewData->viewFwd.x * (float)nearDist) + viewData->viewOrg.x)
                - (float)((float)(viewData->viewLeft.x * (float)nearDist) * (float)v7));
    v17 = (float)((float)((float)((float)(viewData->viewFwd.z * (float)nearDist) + viewData->viewOrg.z)
                        - (float)((float)(viewData->viewLeft.z * (float)nearDist) * (float)v7))
                - (float)((float)(viewData->viewUp.z * (float)nearDist) * (float)v8));
    frustumVerts_0[2].y = (float)((float)((float)(viewData->viewFwd.y * (float)nearDist) + viewData->viewOrg.y)
                                - (float)((float)(viewData->viewLeft.y * (float)nearDist) * (float)v7))
                        - (float)((float)(viewData->viewUp.y * (float)nearDist) * (float)v8);
    frustumVerts_0[2].z = v17;
    frustumVerts_0[2].x = (float)v16 - (float)v15;
    v18 = (float)((float)(viewData->viewUp.y * (float)nearDist) * (float)v8);
    v20 = (float)((float)((float)(viewData->viewFwd.x * (float)nearDist) + viewData->viewOrg.x)
                + (float)((float)(viewData->viewLeft.x * (float)nearDist) * (float)v7));
    v21 = (float)((float)((float)(viewData->viewFwd.y * (float)nearDist) + viewData->viewOrg.y)
                + (float)((float)(viewData->viewLeft.y * (float)nearDist) * (float)v7));
    v22 = (float)((float)((float)((float)(viewData->viewFwd.z * (float)nearDist) + viewData->viewOrg.z)
                        + (float)((float)(viewData->viewLeft.z * (float)nearDist) * (float)v7))
                - (float)((float)(viewData->viewUp.z * (float)nearDist) * (float)v8));
    v19 = (float)((float)(p_viewUp->x * (float)nearDist) * (float)v8);
    frustumVerts_0[3].z = v22;
    frustumVerts_0[3].x = (float)v20 - (float)v19;
    frustumVerts_0[3].y = (float)v21 - (float)v18;
    v23 = &v48;
    p_y = &frustumVerts_0[0].y;
    v25 = (float)((float)(viewData->viewUp.y * (float)farDist) * (float)v8);
    v26 = (float)((float)((float)(viewData->viewFwd.y * (float)farDist) + viewData->viewOrg.y)
                + (float)((float)(viewData->viewLeft.y * (float)farDist) * (float)v7));
    v27 = (float)((float)((float)((float)(viewData->viewFwd.z * (float)farDist) + viewData->viewOrg.z)
                        + (float)((float)(viewData->viewLeft.z * (float)farDist) * (float)v7))
                + (float)((float)(viewData->viewUp.z * (float)farDist) * (float)v8));
    frustumVerts_0[4].x = (float)((float)((float)(viewData->viewFwd.x * (float)farDist) + viewData->viewOrg.x)
                                + (float)((float)(viewData->viewLeft.x * (float)farDist) * (float)v7))
                        + (float)((float)(p_viewUp->x * (float)farDist) * (float)v8);
    frustumVerts_0[4].z = v27;
    frustumVerts_0[4].y = (float)v26 + (float)v25;
    v28 = (float)((float)(viewData->viewUp.z * (float)farDist) * (float)v8);
    v29 = (float)((float)((float)(viewData->viewFwd.z * (float)farDist) + viewData->viewOrg.z)
                - (float)((float)(viewData->viewLeft.z * (float)farDist) * (float)v7));
    v30 = (float)((float)((float)((float)(viewData->viewFwd.y * (float)farDist) + viewData->viewOrg.y)
                        - (float)((float)(viewData->viewLeft.y * (float)farDist) * (float)v7))
                + (float)((float)(viewData->viewUp.y * (float)farDist) * (float)v8));
    frustumVerts_0[5].x = (float)((float)((float)(viewData->viewFwd.x * (float)farDist) + viewData->viewOrg.x)
                                - (float)((float)(viewData->viewLeft.x * (float)farDist) * (float)v7))
                        + (float)((float)(p_viewUp->x * (float)farDist) * (float)v8);
    frustumVerts_0[5].y = v30;
    frustumVerts_0[5].z = (float)v29 + (float)v28;
    v31 = (float)((float)(viewData->viewUp.y * (float)farDist) * (float)v8);
    v32 = (float)((float)((float)(viewData->viewFwd.y * (float)farDist) + viewData->viewOrg.y)
                - (float)((float)(viewData->viewLeft.y * (float)farDist) * (float)v7));
    v33 = (float)((float)((float)((float)(viewData->viewFwd.z * (float)farDist) + viewData->viewOrg.z)
                        - (float)((float)(viewData->viewLeft.z * (float)farDist) * (float)v7))
                - (float)((float)(viewData->viewUp.z * (float)farDist) * (float)v8));
    frustumVerts_0[6].x = (float)((float)((float)(viewData->viewFwd.x * (float)farDist) + viewData->viewOrg.x)
                                - (float)((float)(viewData->viewLeft.x * (float)farDist) * (float)v7))
                        - (float)((float)(p_viewUp->x * (float)farDist) * (float)v8);
    frustumVerts_0[6].z = v33;
    frustumVerts_0[6].y = (float)v32 - (float)v31;
    v34 = 8;
    v35 = (float)((float)(viewData->viewUp.y * (float)farDist) * (float)v8);
    v36 = (float)((float)(p_viewUp->x * (float)farDist) * (float)v8);
    v37 = (float)((float)(viewData->viewUp.z * (float)farDist) * (float)v8);
    v38 = (float)((float)((float)(viewData->viewFwd.y * (float)farDist) + viewData->viewOrg.y)
                + (float)((float)(viewData->viewLeft.y * (float)farDist) * (float)v7));
    v39 = (float)((float)((float)(viewData->viewFwd.z * (float)farDist) + viewData->viewOrg.z)
                + (float)((float)(viewData->viewLeft.z * (float)farDist) * (float)v7));
    frustumVerts_0[7].x = (float)((float)((float)(viewData->viewFwd.x * (float)farDist) + viewData->viewOrg.x)
                                + (float)((float)(viewData->viewLeft.x * (float)farDist) * (float)v7))
                        - (float)v36;
    frustumVerts_0[7].y = (float)v38 - (float)v35;
    frustumVerts_0[7].z = (float)v39 - (float)v37;
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
    idFoliageModel::GetFoliageSubTreesForView_r(
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
// ?LoadFoliageForWorld@idFoliageModel@@SAXPAVidRenderWorldLocal@@@Z
// EA  : 0x827D67C0
// RVA : 0x007D67C0
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void __fastcall idFoliageModel::LoadFoliageForWorld(idRenderWorldLocal *rw)
{
  __int64 v2; // r6
  __int64 v3; // r10
  int v4; // r7
  idResource *v5; // r29
  idRenderModelFoliage *v6; // r3
  __int64 v7; // [sp+8h] [-C8h]
  idStr v8; // [sp+50h] [-80h] BYREF
  idStr v9; // [sp+70h] [-60h] BYREF
  idStr v10[2]; // [sp+90h] [-40h] BYREF

  if ( rw != nullptr )
  {
    v8.len = 0;
    v8.allocedAndFlag = 20;
    v8.data = v8.baseBuffer;
    v8.baseBuffer[0] = 0;
    idStr::ExtractFileName(this: &rw->mapName, dest: &v8);
    HIDWORD(v2) = v8.data;
    idMapFile::GetMapModelName(result: v10, entityName: v2, a3: v4, a4: v3, a5: v7);
    idStr::idStr(this: &v9, text: v10);
    idStr::SetFileExtension(this: &v9, extension: "bfoliage");
    if ( fileSystem->FileExists(this: fileSystem, a2: v9.data, a3: false) )
    {
      v5 = idResourceList::Load(
             this: &idFoliageModel::resourceList,
             name: v9.data,
             makeDefault: true,
             skipStaleCheck: false);
      if ( v5->resourceError == nullptr )
      {
        v6 = rw->FoliageRenderModel(this: rw);
        if ( v6 != nullptr )
        {
          v6->foliageBSP = (idFoliageModel *)v5;
          idRenderModel::CommitThisFrame(this: v6);
        }
        else
        {
          idLib::Warning(fmt: "Failed to create foliage render model");
        }
      }
    }
    idStr::FreeData(this: &v9);
    idStr::FreeData(this: v10);
    idStr::FreeData(this: &v8);
  }
}


// ========================================================================
// __unwind$232458
// EA  : 0x827D68EC
// RVA : 0x007D68EC
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void _unwind_232458()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$232459
// EA  : 0x827D6914
// RVA : 0x007D6914
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void _unwind_232459()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 144));
}


// ========================================================================
// __unwind$232460
// EA  : 0x827D693C
// RVA : 0x007D693C
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void _unwind_232460()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?SwapModelSubTrees@idFoliageModel@@CAXPAUfm_subTreeData_t@@PAUfm_subTreeTreeNodes_t@@@Z
// EA  : 0x827D6968
// RVA : 0x007D6968
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void __fastcall idFoliageModel::SwapModelSubTrees(const dm_subTreeData_t *data, const dm_subTreeData_t *treeNodes)
{
  int v3; // r10
  int v4; // r11
  dm_attribute_t *attributes; // r9
  dm_subTreeDataPtrs_t v6; // [sp+50h] [-20h] BYREF
  dm_subTreeDataPtrs_t v7; // [sp+58h] [-18h] BYREF

  SetupSubTreePtrsFromTreeNodes(subTreePtrs: &v7, subTree: treeNodes);
  SetupSubTreePtrsFromTreeNodes(subTreePtrs: &v6, subTree: data);
  v3 = 0;
  if ( data->numAttributes > 0 )
  {
    v4 = 0;
    attributes = v6.attributes;
    do
    {
      LOBYTE(attributes->pad[5]) = 0;
      ++v3;
      v6.attributes[v4++].pad[6] = 0;
      attributes = &v6.attributes[v4];
    }
    while ( v3 < data->numAttributes );
  }
}


// ========================================================================
// ??1idFoliageModel@@UAA@XZ
// EA  : 0x827D69F8
// RVA : 0x007D69F8
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void __fastcall idFoliageModel::~idFoliageModel(idFoliageModel *this)
{
  this->__vftable = (idFoliageModel_vtbl *)&idFoliageModel::`vftable';
  idFoliageModel::FreeData((idDetailModel *)this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sharedAttributes);
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$232633
// EA  : 0x827D6A50
// RVA : 0x007D6A50
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void _unwind_232633()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$232634
// EA  : 0x827D6A78
// RVA : 0x007D6A78
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void _unwind_232634()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}


// ========================================================================
// ??0idFoliageModel@@QAA@XZ
// EA  : 0x827D6AC0
// RVA : 0x007D6AC0
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

idFoliageModel *__fastcall idFoliageModel::idFoliageModel(idFoliageModel *this)
{
  idResource::idResource(this);
  this->__vftable = (idFoliageModel_vtbl *)&idFoliageModel::`vftable';
  this->sharedAttributes.list = nullptr;
  this->sharedAttributes.granularity = 0;
  this->sharedAttributes.memTag = 5;
  this->sharedAttributes.listStatic = 0;
  this->sharedAttributes.size = 0;
  this->sharedAttributes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sharedAttributes);
  this->foliageModelData.numTreeNodes = 0;
  this->foliageModelData.numSubTrees = 0;
  this->foliageModelData.treeNodes = nullptr;
  this->foliageModelData.subTrees = nullptr;
  this->stats.numFoliageNodes = 0;
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
// __unwind$232847
// EA  : 0x827D6B70
// RVA : 0x007D6B70
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void _unwind_232847()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$232848
// EA  : 0x827D6B98
// RVA : 0x007D6B98
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void _unwind_232848()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 52));
}


// ========================================================================
// ?Load_Binary@idFoliageModel@@QAA_NPBD@Z
// EA  : 0x827D6C30
// RVA : 0x007D6C30
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

int __fastcall idFoliageModel::Load_Binary(idFoliageModel *this, const char *foliageFileName)
{
  idFile *v3; // r3
  unsigned int v5; // r30
  int v6; // r28
  const idDeclFoliage *v7; // r3
  fm_treeNode_t *v8; // r4
  idFile *file; // r3
  int *p_numSubTrees; // r26
  fm_subTree_t *v11; // r3
  int numSubTrees; // r4
  int v13; // r28
  int v14; // r30
  int v15; // r25
  int v16; // r28
  int v17; // r27
  fm_subTree_t *v18; // r30
  int numTreeNodes; // r11
  int v20; // r10
  idFileLocal v21; // [sp+50h] [-D0h] BYREF
  unsigned int v22; // [sp+54h] [-CCh] BYREF
  unsigned int v23[2]; // [sp+58h] [-C8h] BYREF
  dm_subTreeDataPtrs_t v24; // [sp+60h] [-C0h] BYREF
  idStr v25; // [sp+70h] [-B0h] BYREF
  idStr v26[4]; // [sp+90h] [-90h] BYREF

  idStr::idStr(this: &v25, text: foliageFileName);
  idStr::SetFileExtension(this: &v25, extension: "bfoliage");
  v3 = fileSystem->OpenFileRead(this: fileSystem, a2: v25.data, a3: 1, a4: 0);
  v21.file = v3;
  if ( v3 != nullptr )
  {
    v3->Read(this: v3, a2: v23, a3: 4u);
    if ( v23[0] == 1179601927 || v23[0] == 1179601926 )
    {
      v21.file->Read(this: v21.file, a2: &v22, a3: 4u);
      idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->sharedAttributes, newNum: v22);
      v5 = 0;
      if ( v22 != 0 )
      {
        v6 = 0;
        do
        {
          v26[0].allocedAndFlag = 20;
          v26[0].len = 0;
          v26[0].data = v26[0].baseBuffer;
          v26[0].baseBuffer[0] = 0;
          idFile::ReadString(this: v21.file, string: v26);
          if ( v26[0].data != nullptr )
            v7 = (const idDeclFoliage *)idDeclInfo::FindWithInheritance(
                                          this: &idDeclFoliage::resourceList,
                                          name: v26[0].data,
                                          makeDefault: true);
          else
            v7 = nullptr;
          this->sharedAttributes.list[v6] = v7;
          idStr::FreeData(this: v26);
          ++v5;
          ++v6;
        }
        while ( v5 < v22 );
      }
      v21.file->Read(this: v21.file, a2: &this->foliageModelData, a3: 4u);
      v8 = (fm_treeNode_t *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\models\\foliage\\FoliageModel.cpp(264) : TAG_FOLIAGE",
                              size: 8 * this->foliageModelData.numTreeNodes,
                              tag: TAG_FOLIAGE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      file = v21.file;
      this->foliageModelData.treeNodes = v8;
      ((void (__fastcall *)(idFile *))file->Read)(a1: file);
      p_numSubTrees = &this->foliageModelData.numSubTrees;
      v21.file->Read(this: v21.file, a2: &this->foliageModelData.numSubTrees, a3: 4u);
      v11 = (fm_subTree_t *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\models\\foliage\\FoliageModel.cpp(272) : TAG_FOLIAGE",
                              size: 32 * this->foliageModelData.numSubTrees,
                              tag: TAG_FOLIAGE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      numSubTrees = this->foliageModelData.numSubTrees;
      this->foliageModelData.subTrees = v11;
      v13 = 0;
      if ( numSubTrees > 0 )
      {
        v14 = 0;
        do
        {
          v21.file->Read(this: v21.file, a2: &this->foliageModelData.subTrees[v14], a3: 8u);
          v21.file->Read(this: v21.file, a2: this->foliageModelData.subTrees[v14].bounds.b[1], a3: 8u);
          v21.file->Read(this: v21.file, a2: &this->foliageModelData.subTrees[v14].maxFoliageHeight, a3: 2u);
          v21.file->Read(this: v21.file, a2: &this->foliageModelData.subTrees[v14].totalDataSize, a3: 4u);
          v21.file->Read(this: v21.file, a2: &this->foliageModelData.subTrees[v14].totalTreeNodeSize, a3: 2u);
          this->foliageModelData.subTrees[v14].data = (fm_subTreeData_t *)idMem::AllocWithLocation(
                                                                            this: &mem,
                                                                            location: "w:\\tech5\\engine\\models\\foliage\\FoliageM"
                                                                            "odel.cpp(283) : TAG_FOLIAGE",
                                                                            size: this->foliageModelData.subTrees[v14].totalDataSize,
                                                                            tag: TAG_FOLIAGE,
                                                                            zeroBuffer: false,
                                                                            align: ALIGN_16,
                                                                            heap: HEAP_DEFAULTHEAP);
          v21.file->Read(
            this: v21.file,
            a2: this->foliageModelData.subTrees[v14].data,
            a3: this->foliageModelData.subTrees[v14].totalDataSize);
          this->foliageModelData.subTrees[v14].treeNodes = (fm_subTreeTreeNodes_t *)idMem::AllocWithLocation(
                                                                                      this: &mem,
                                                                                      location: "w:\\tech5\\engine\\models\\foliage"
                                                                                      "\\FoliageModel.cpp(286) : TAG_FOLIAGE",
                                                                                      size: this->foliageModelData.subTrees[v14].totalTreeNodeSize,
                                                                                      tag: TAG_FOLIAGE,
                                                                                      zeroBuffer: false,
                                                                                      align: ALIGN_16,
                                                                                      heap: HEAP_DEFAULTHEAP);
          v21.file->Read(
            this: v21.file,
            a2: this->foliageModelData.subTrees[v14].treeNodes,
            a3: this->foliageModelData.subTrees[v14].totalTreeNodeSize);
          idFoliageModel::SwapModelSubTrees(
            data: (const dm_subTreeData_t *)this->foliageModelData.subTrees[v14].data,
            treeNodes: (const dm_subTreeData_t *)this->foliageModelData.subTrees[v14].treeNodes);
          ++v13;
          ++v14;
        }
        while ( v13 < *p_numSubTrees );
      }
      v21.file->Read(this: v21.file, a2: v23, a3: 4u);
      if ( v23[0] == 1179601927 || v23[0] == 1179601926 )
      {
        idFoliageModel::InitializeAttributes(
          model: &this->foliageModelData,
          uniqueDecls: &this->sharedAttributes,
          magic: v23[0]);
        v15 = 0;
        v16 = 0;
        if ( *p_numSubTrees > 0 )
        {
          v17 = 0;
          do
          {
            v18 = &this->foliageModelData.subTrees[v17];
            SetupSubTreePtrsFromTreeNodes(subTreePtrs: &v24, subTree: (const dm_subTreeData_t *)v18->data);
            ++v16;
            ++v17;
            v15 += v18->data->numFoliage;
          }
          while ( v16 < *p_numSubTrees );
        }
        numTreeNodes = this->foliageModelData.numTreeNodes;
        v20 = *p_numSubTrees;
        this->stats.numFoliageNodes = v15;
        this->stats.numTreeNodes = numTreeNodes;
        this->stats.numSubTrees = v20;
        idFileLocal::~idFileLocal(this: &v21);
        idStr::FreeData(this: &v25);
        return 1;
      }
      else
      {
        idLib::Warning(fmt: "%s is invalid", v25.data);
        idFileLocal::~idFileLocal(this: &v21);
        idStr::FreeData(this: &v25);
        return 0;
      }
    }
    else
    {
      idLib::Warning(fmt: "%s is not a binary foliage file", v25.data);
      idFoliageModel::FreeData((idDetailModel *)this);
      idFileLocal::~idFileLocal(this: &v21);
      idStr::FreeData(this: &v25);
      return 0;
    }
  }
  else
  {
    idLib::Printf(fmt: "couldn't open file %s for read\n", v25.data);
    idFileLocal::~idFileLocal(this: &v21);
    idStr::FreeData(this: &v25);
    return 0;
  }
}


// ========================================================================
// __unwind$233067_0
// EA  : 0x827D7120
// RVA : 0x007D7120
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void _unwind_233067_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$233068_0
// EA  : 0x827D7148
// RVA : 0x007D7148
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void _unwind_233068_0()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 288 + 80));
}


// ========================================================================
// __unwind$233069_0
// EA  : 0x827D7170
// RVA : 0x007D7170
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void _unwind_233069_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 144));
}


// ========================================================================
// ?LoadResource@idFoliageModel@@UAAXXZ
// EA  : 0x827D7240
// RVA : 0x007D7240
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void __fastcall idFoliageModel::LoadResource(idFoliageModel *this)
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

  idFoliageModel::FreeData((idDetailModel *)this);
  if ( (unsigned __int8)idFoliageModel::Load_Binary(this, foliageFileName: this->name.str) == 0 )
  {
    HIDWORD(v4) = this->name.str;
    idResource::SetResourceError(
      this,
      fmt: "Couldn't load foliage '%s'",
      a3: v4,
      a4: v3,
      a5: v2,
      a6: v5,
      a7: v6,
      a8: v7,
      a9: v8,
      a10: v9,
      a11: v10);
    idFoliageModel::FreeData((idDetailModel *)this);
  }
}


// ========================================================================
// `dynamic initializer for 'r_foliageStartFadeDist''
// EA  : 0x83342BD8
// RVA : 0x01342BD8
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_foliageStartFadeDist__()
{
  idCVar::idCVar(
    this: &r_foliageStartFadeDist,
    name: "r_foliageStartFadeDist",
    value: "3000",
    flags: 4,
    description: "start fading foliage out at this range",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_foliageStartFadeDist__);
}


// ========================================================================
// `dynamic initializer for 'r_foliageSmallFadeDistMax''
// EA  : 0x83342C30
// RVA : 0x01342C30
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_foliageSmallFadeDistMax__()
{
  idCVar::idCVar(
    this: &r_foliageSmallFadeDistMax,
    name: "r_foliageSmallFadeDistMax",
    value: "5000",
    flags: 4,
    description: "small foliage will be completely faded out at this range",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_foliageSmallFadeDistMax__);
}


// ========================================================================
// `dynamic initializer for 'r_foliageBigFadeDistMax''
// EA  : 0x83342C88
// RVA : 0x01342C88
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_foliageBigFadeDistMax__()
{
  idCVar::idCVar(
    this: &r_foliageBigFadeDistMax,
    name: "r_foliageBigFadeDistMax",
    value: "7000",
    flags: 4,
    description: "all foliage will be completely faded out at this range",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_foliageBigFadeDistMax__);
}


// ========================================================================
// `dynamic initializer for 'idFoliageModel::resourceList''
// EA  : 0x83342CE0
// RVA : 0x01342CE0
// PDB : w:\tech5\engine\models\foliage\foliagemodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idFoliageModel::resourceList__()
{
  idResourceList::idResourceList(this: &idFoliageModel::resourceList, typeName: "foliageModel");
  idFoliageModel::resourceList.__vftable = (idTypedResourceList<idFoliageModel>_vtbl *)&idTypedResourceList<idFoliageModel>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idFoliageModel::resourceList__);
}

