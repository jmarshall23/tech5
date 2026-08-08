
// ========================================================================
// ?IsAnimatedRenderModel@idCollisionModelBuilder@@SA_NPBD@Z
// EA  : 0x825D2C78
// RVA : 0x005D2C78
// PDB : w:\tech5\engine\cm\collisionmodelbuilder_sphere.cpp
// ========================================================================

BOOL __fastcall idCollisionModelBuilder::IsAnimatedRenderModel(const char *fileName)
{
  idStr *v1; // r3
  BOOL v2; // r30
  idStr v4; // [sp+50h] [-60h] BYREF
  idStr v5; // [sp+70h] [-40h] BYREF

  v4.len = 0;
  v4.allocedAndFlag = 20;
  v4.data = v4.baseBuffer;
  v4.baseBuffer[0] = 0;
  v1 = idStr::idStr(this: &v5, text: fileName);
  idStr::ExtractFileExtension(this: v1, dest: &v4);
  idStr::FreeData(this: &v5);
  v2 = (_cntlzw(idStr::Icmp(s1: v4.data, s2: "md6")) & 0x20) != 0;
  idStr::FreeData(this: &v4);
  return v2;
}


// ========================================================================
// __unwind$223482
// EA  : 0x825D2D04
// RVA : 0x005D2D04
// PDB : w:\tech5\engine\cm\collisionmodelbuilder_sphere.cpp
// ========================================================================

void _unwind_223482()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$223483
// EA  : 0x825D2D2C
// RVA : 0x005D2D2C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder_sphere.cpp
// ========================================================================

void _unwind_223483()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// ?BuildForDeclMD6@idCollisionModelBuilder@@SA_NPAVidCollisionModelLocal@@PBVidDeclMD6@@@Z
// EA  : 0x825D2F20
// RVA : 0x005D2F20
// PDB : w:\tech5\engine\cm\collisionmodelbuilder_sphere.cpp
// ========================================================================

int __fastcall idCollisionModelBuilder::BuildForDeclMD6(idCollisionModelLocal *model, const idDeclMD6 *md6Decl)
{
  const idMD6Model *v5; // r11
  const idMD6Skel *skeleton; // r30
  idMD6SkelData *data; // r6
  unsigned __int16 numJoints; // r11
  int v9; // r12
  float *v10; // r26
  int v11; // r18
  int i; // r19
  const idJointGroup *JointGroupForIndex; // r3
  const idJointGroup *v14; // r27
  int v15; // r30
  int v16; // r22
  int v17; // r24
  int v18; // r25
  __int16 value; // r8
  idVec3 *v20; // r11
  float x; // r7
  float y; // r6
  float *v23; // r11
  double v24; // fp0
  double v25; // fp13
  double v26; // fp12
  float *v27; // r11
  double v28; // fp0
  double v29; // fp10
  double v30; // fp9
  double v31; // fp8
  size_t num; // r27
  unsigned __int8 *list; // r22
  float *v34; // r20
  float *v35; // r19
  __int16 v36; // r16
  float *v37; // r18
  float *v38; // r21
  unsigned __int8 *v39; // r17
  int v40; // r30
  double v41; // fp0
  double v42; // fp12
  double v43; // fp11
  unsigned __int8 v44; // r11
  unsigned int v45; // r3
  size_t v46; // r26
  size_t v47; // r25
  size_t v48; // r24
  size_t v49; // r16
  size_t v50; // r23
  double v51; // fp0
  double v52; // fp13
  double v53; // fp12
  double v54; // fp11
  double v55; // fp10
  double v56; // fp9
  void *v57; // r30
  unsigned int v58; // r3
  idMem *v59; // r30
  _DWORD back_chain[20]; // [sp+0h] [-1E0h]
  unsigned __int8 surfType; // [sp+50h] [-190h] BYREF
  unsigned __int8 v62; // [sp+51h] [-18Fh] BYREF
  unsigned __int16 v63; // [sp+52h] [-18Eh]
  float v64; // [sp+54h] [-18Ch] BYREF
  float v65; // [sp+58h] [-188h] BYREF
  float v66; // [sp+5Ch] [-184h] BYREF
  float v67; // [sp+60h] [-180h] BYREF
  idMem *v68; // [sp+64h] [-17Ch]
  idVec3 *v69; // [sp+68h] [-178h]
  idList<float,13> v70; // [sp+70h] [-170h] BYREF
  idList<float,13> v71; // [sp+80h] [-160h] BYREF
  idList<float,13> v72; // [sp+90h] [-150h] BYREF
  idList<float,13> v73; // [sp+A0h] [-140h] BYREF
  idList<unsigned char,37> v74; // [sp+B0h] [-130h] BYREF
  idList<unsigned char,37> v75; // [sp+C0h] [-120h] BYREF
  float v76; // [sp+D0h] [-110h]
  float v77; // [sp+D4h] [-10Ch]
  float z; // [sp+D8h] [-108h]
  unsigned int v79[13]; // [sp+E0h] [-100h] BYREF
  cm_sphereModelPtrs_t v80; // [sp+120h] [-C0h] BYREF

  if ( md6Decl == nullptr )
    return 0;
  v5 = md6Decl->model;
  if ( v5 == nullptr )
    return 0;
  skeleton = v5->skeleton;
  if ( ((skeleton->data->numJoints + 7) & 0xFFF8) == 0 )
    return 0;
  *((_BYTE *)&model->idResource + 32) &= ~0x80u;
  idResource::SetName(this: model, _name: md6Decl->name.str);
  model->modelType = CM_SPHEREMODEL;
  model->bounds.b[0].z = 1.0e30;
  model->bounds.b[0].y = 1.0e30;
  model->bounds.b[0].x = 1.0e30;
  model->bounds.b[1].z = -1.0e30;
  model->bounds.b[1].y = -1.0e30;
  model->bounds.b[1].x = -1.0e30;
  model->contents = 0;
  model->sourceFileTime = -1;
  model->isWorldModel = false;
  model->isTraceModel = false;
  model->isConvex = false;
  model->isStreamed = false;
  model->sphereModel = nullptr;
  ((void (*)(void))RtlCheckStack12)();
  data = skeleton->data;
  v68 = &mem;
  numJoints = data->numJoints;
  *(_DWORD *)((char *)back_chain + v9) = back_chain[0];
  v10 = (float *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder_sphere.cpp(89) : TAG_MD6_COLLISION",
                   size: 48 * ((numJoints + 7) & 0xFFF8),
                   tag: TAG_MD6_COLLISION,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  idMD6Blend::DecodeBasePose(
    skeleton: skeleton->data,
    temp: &surfType,
    tempSize: 0x4000u,
    originOffset: md6Decl->config->visualOffset,
    offsetAdd: true,
    outPose: v10);
  idList<idRecycledTraceModel *,13>::idList<idRecycledTraceModel *,13>(this: (idList<float,13> *)&v74);
  idList<idRecycledTraceModel *,13>::idList<idRecycledTraceModel *,13>(this: &v72);
  idList<idRecycledTraceModel *,13>::idList<idRecycledTraceModel *,13>(this: &v71);
  idList<idRecycledTraceModel *,13>::idList<idRecycledTraceModel *,13>(this: &v70);
  idList<idRecycledTraceModel *,13>::idList<idRecycledTraceModel *,13>(this: &v73);
  idList<idRecycledTraceModel *,13>::idList<idRecycledTraceModel *,13>(this: (idList<float,13> *)&v75);
  v63 = 0;
  v11 = idJointGroupCollection::NumJointGroupsForType(this: &md6Decl->jointGroupCollection, type: JOINTGROUP_HITTEST);
  for ( i = 0; i < v11; ++i )
  {
    JointGroupForIndex = idJointGroupCollection::GetJointGroupForIndex(
                           this: &md6Decl->jointGroupCollection,
                           type: JOINTGROUP_HITTEST,
                           index: i);
    v14 = JointGroupForIndex;
    if ( JointGroupForIndex != nullptr )
    {
      v15 = 0;
      if ( JointGroupForIndex->joints.num > 0 )
      {
        v16 = 0;
        v17 = 0;
        v18 = 0;
        do
        {
          value = v14->joints.list[v18].value;
          if ( v15 < 0 || v15 >= v14->jointOffsets.num )
            v20 = &vec3_origin;
          else
            v20 = &v14->jointOffsets.list[v17];
          x = v20->x;
          y = v20->y;
          z = v20->z;
          LODWORD(v64) = value;
          v76 = x;
          v77 = y;
          v23 = &v10[12 * value];
          v24 = (float)((float)(z * v23[2]) + (float)((float)(x * *v23) + (float)(y * v23[1])));
          v25 = (float)((float)(z * v23[6]) + (float)((float)(x * v23[4]) + (float)(y * v23[5])));
          v26 = (float)((float)(x * v23[8]) + (float)((float)(y * v23[9]) + (float)(z * v23[10])));
          if ( v15 < 0 || v15 >= v14->jointScalars.num )
            v64 = 1.0;
          else
            v64 = v14->jointScalars.list[v16];
          v69 = (idVec3 *)value;
          v27 = &v10[12 * value];
          v29 = (float)((float)(v27[5] * (float)v25) + (float)(v27[1] * (float)v24));
          v30 = (float)((float)(v27[4] * (float)v25) + (float)(*v27 * (float)v24));
          v31 = (float)((float)((float)v26 * v27[10])
                      + (float)((float)(v27[6] * (float)v25) + (float)(v27[2] * (float)v24)));
          v28 = v27[8];
          v66 = (float)((float)v26 * v27[9]) + (float)v29;
          v67 = v31;
          v65 = (float)((float)v26 * (float)v28) + (float)v30;
          if ( (unsigned __int16)(value + 1) > (unsigned int)v63 )
            v63 = value + 1;
          surfType = value;
          idList<unsigned char,25>::Append(this: &v74, obj: &surfType);
          idList<float,13>::Append(this: &v72, obj: &v65);
          idList<float,13>::Append(this: &v71, obj: &v66);
          idList<float,13>::Append(this: &v70, obj: &v67);
          idList<float,13>::Append(this: &v73, obj: &v64);
          surfType = v14->args.surfType;
          idList<unsigned char,25>::Append(this: &v75, obj: &surfType);
          ++v15;
          ++v18;
          ++v17;
          ++v16;
        }
        while ( v15 < v14->joints.num );
      }
    }
  }
  num = v74.num;
  list = v75.list;
  v34 = v70.list;
  v35 = v71.list;
  v36 = v74.num;
  v37 = v72.list;
  v38 = v73.list;
  v39 = v74.list;
  if ( (v74.num & 3) != 0 )
  {
    v40 = v74.num;
    v62 = v75.list[v75.num - 1];
    v41 = v70.list[v70.num - 1];
    v42 = v72.list[v72.num - 1];
    v43 = v73.list[v73.num - 1];
    v44 = v74.list[v74.num - 1];
    v66 = v71.list[v71.num - 1];
    v65 = v42;
    v64 = v43;
    v67 = v41;
    if ( v74.num < (int)((v74.num + 3) & 0xFFFFFFFC) )
    {
      surfType = v44;
      do
      {
        idList<unsigned char,25>::Append(this: &v74, obj: &surfType);
        idList<float,13>::Append(this: &v72, obj: &v65);
        idList<float,13>::Append(this: &v71, obj: &v66);
        idList<float,13>::Append(this: &v70, obj: &v67);
        idList<float,13>::Append(this: &v73, obj: &v64);
        idList<unsigned char,25>::Append(this: &v75, obj: &v62);
        ++v40;
      }
      while ( v40 < (int)((v40 + 3) & 0xFFFFFFFC) );
      num = v74.num;
      v39 = v74.list;
      v37 = v72.list;
      v35 = v71.list;
      v34 = v70.list;
      v38 = v73.list;
      list = v75.list;
    }
  }
  idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
  v45 = md6Decl->GetDeclTimestamp(this: md6Decl);
  v46 = 4 * v72.num;
  LOWORD(v79[10]) = (num + 79) & 0xFFF0;
  v47 = 4 * v71.num;
  v48 = 4 * v70.num;
  LOWORD(v79[9]) = v36;
  v49 = v75.num;
  v50 = 4 * v73.num;
  v51 = md6Decl->referenceBounds.b[0].x;
  v52 = md6Decl->referenceBounds.b[0].y;
  HIWORD(v79[9]) = v63;
  HIWORD(v79[11]) = (LOWORD(v79[10]) + 4 * LOWORD(v72.num) + 15) & 0xFFF0;
  LODWORD(v64) = &md6Decl->referenceBounds;
  v53 = md6Decl->referenceBounds.b[0].z;
  HIWORD(v79[10]) = 64;
  v54 = md6Decl->referenceBounds.b[1].x;
  LODWORD(v64) = &md6Decl->referenceBounds.b[1];
  LOWORD(v79[11]) = (HIWORD(v79[11]) + 4 * LOWORD(v71.num) + 15) & 0xFFF0;
  v55 = md6Decl->referenceBounds.b[1].y;
  v56 = md6Decl->referenceBounds.b[1].z;
  v79[1] = v45;
  *(float *)&v79[2] = v51;
  HIWORD(v79[12]) = (LOWORD(v79[11]) + 4 * LOWORD(v70.num) + 15) & 0xFFF0;
  *(float *)&v79[3] = v52;
  *(float *)&v79[4] = v53;
  *(float *)&v79[5] = v54;
  *(float *)&v79[6] = v55;
  *(float *)&v79[7] = v56;
  v79[8] = 128;
  LOWORD(v79[12]) = (HIWORD(v79[12]) + 4 * LOWORD(v73.num) + 15) & 0xFFF0;
  v79[0] = LOWORD(v79[12]) + v75.num;
  v57 = idMem::AllocWithLocation(
          this: v68,
          location: "w:\\tech5\\engine\\cm\\CollisionModelBuilder_sphere.cpp(169) : TAG_ANIMATION",
          size: v79[0],
          tag: TAG_ANIMATION,
          zeroBuffer: true,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  memcpy(Dst: v57, Src: v79, Size: 0x34u);
  idSphereModelCollisionDetection::SetupCollisionSpherePtrs(csData: (const cm_sphereModel_t *)v57, csPtrs: &v80);
  memcpy(Dst: v80.joint, Src: v39, Size: num);
  memcpy(Dst: v80.offsetX, Src: v37, Size: v46);
  memcpy(Dst: v80.offsetY, Src: v35, Size: v47);
  memcpy(Dst: v80.offsetZ, Src: v34, Size: v48);
  memcpy(Dst: v80.radius, Src: v38, Size: v50);
  memcpy(Dst: v80.surfType, Src: list, Size: v49);
  idResource::SetName(this: model, _name: md6Decl->name.str);
  v58 = md6Decl->GetDeclTimestamp(this: md6Decl);
  model->sphereModel = (cm_sphereModel_t *)v57;
  model->sourceFileTime = v58;
  model->bounds.b[0].x = *((float *)v57 + 2);
  model->bounds.b[0].y = *((float *)v57 + 3);
  v69 = &model->bounds.b[1];
  model->bounds.b[0].z = *((float *)v57 + 4);
  model->bounds.b[1].x = *((float *)v57 + 5);
  model->bounds.b[1].y = *((float *)v57 + 6);
  model->bounds.b[1].z = *((float *)v57 + 7);
  model->contents = model->sphereModel->contents;
  if ( (v75.listStatic == 0 || v75.listStatic == 2) && list != nullptr )
  {
    v59 = v68;
    idMem::Free(this: v68, ptr: list, align: ALIGN_16);
  }
  else
  {
    v59 = v68;
  }
  if ( (v73.listStatic == 0 || v73.listStatic == 2) && v38 != nullptr )
    idMem::Free(this: v59, ptr: v38, align: ALIGN_16);
  if ( (v70.listStatic == 0 || v70.listStatic == 2) && v34 != nullptr )
    idMem::Free(this: v59, ptr: v34, align: ALIGN_16);
  if ( (v71.listStatic == 0 || v71.listStatic == 2) && v35 != nullptr )
    idMem::Free(this: v59, ptr: v35, align: ALIGN_16);
  if ( (v72.listStatic == 0 || v72.listStatic == 2) && v37 != nullptr )
    idMem::Free(this: v59, ptr: v37, align: ALIGN_16);
  if ( (v74.listStatic == 0 || v74.listStatic == 2) && v39 != nullptr )
    idMem::Free(this: v59, ptr: v39, align: ALIGN_16);
  return 1;
}


// ========================================================================
// __unwind$223584
// EA  : 0x825D3744
// RVA : 0x005D3744
// PDB : w:\tech5\engine\cm\collisionmodelbuilder_sphere.cpp
// ========================================================================

void _unwind_223584()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 176));
}


// ========================================================================
// __unwind$223585
// EA  : 0x825D376C
// RVA : 0x005D376C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder_sphere.cpp
// ========================================================================

void _unwind_223585()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 144));
}


// ========================================================================
// __unwind$223586
// EA  : 0x825D3794
// RVA : 0x005D3794
// PDB : w:\tech5\engine\cm\collisionmodelbuilder_sphere.cpp
// ========================================================================

void _unwind_223586()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 128));
}


// ========================================================================
// __unwind$223587
// EA  : 0x825D37BC
// RVA : 0x005D37BC
// PDB : w:\tech5\engine\cm\collisionmodelbuilder_sphere.cpp
// ========================================================================

void _unwind_223587()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 112));
}


// ========================================================================
// __unwind$223588
// EA  : 0x825D37E4
// RVA : 0x005D37E4
// PDB : w:\tech5\engine\cm\collisionmodelbuilder_sphere.cpp
// ========================================================================

void _unwind_223588()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 160));
}


// ========================================================================
// __unwind$223589
// EA  : 0x825D380C
// RVA : 0x005D380C
// PDB : w:\tech5\engine\cm\collisionmodelbuilder_sphere.cpp
// ========================================================================

void _unwind_223589()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 192));
}

