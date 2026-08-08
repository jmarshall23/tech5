
// ========================================================================
// ?GetSourceSurfaces@idRenderModelStatic@@EBAPBV?$idList@UsourceSurface_t@@$04@@XZ
// EA  : 0x82866D60
// RVA : 0x00866D60
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

const idList<sourceSurface_t,5> *__fastcall idRenderModelStatic::GetSourceSurfaces(idRenderModelStatic *this)
{
  const idStaticModel *staticModel; // r11
  const idList<sourceSurface_t,5> *result; // r3

  staticModel = this->staticModel;
  result = nullptr;
  if ( staticModel != nullptr )
    return &staticModel->sourceSurfaces;
  return result;
}


// ========================================================================
// ?UpdateInView@idRenderModelStatic@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x82866EA0
// RVA : 0x00866EA0
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

int __fastcall idRenderModelStatic::UpdateInView(
        idRenderModelStatic *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools)
{
  const idStaticModel *staticModel; // r11
  int v9; // r20
  int valueInteger; // r22
  int v11; // r27
  int v12; // r21
  idStaticModelSurface *v13; // r25
  idTriangles *geometry; // r28
  const idDrawVert *verts; // r11
  staticTransparencyGenParms_t *v16; // r31
  idMat3 *Axis; // r3
  float *material; // r11
  const approximateLighting_t *ApproximateLighting; // r3

  staticModel = this->staticModel;
  if ( staticModel == nullptr || !staticModel->usesTransparencySort )
    return 0;
  v9 = 0;
  valueInteger = r_useStaticTransparencyGenJobs.valueInteger;
  if ( staticModel->surfaces.num > 0 )
  {
    v11 = 0;
    v12 = 0;
    do
    {
      v13 = &staticModel->surfaces.list[v12];
      if ( (*((_BYTE *)v13->material + 72) & 8) != 0 )
      {
        geometry = v13->geometry;
        if ( geometry != nullptr )
        {
          verts = geometry->verts;
          if ( verts != nullptr )
          {
            v16 = this->transparencyGenParms.list[v11++];
            v16->inputVerts = verts;
            v16->numInputVerts = geometry->numVerts;
            v16->fadeStartDist = r_staticTransparencyFadeStartDist.valueFloat;
            v16->fadeMaxDist = r_staticTransparencyFadeMaxDist.valueFloat;
            v16->origin = idRenderModel::GetOrigin(this)->origin;
            Axis = (idMat3 *)idRenderModel::GetAxis(this);
            material = (float *)v13->material;
            v16->axis = *Axis;
            v16->viewOrg.x = currentView->r.vieworg.x;
            v16->viewOrg.y = currentView->r.vieworg.y;
            v16->viewOrg.z = currentView->r.vieworg.z;
            v16->viewDir.x = currentView->r.viewaxis.mat[0].x;
            v16->viewDir.y = currentView->r.viewaxis.mat[0].y;
            v16->viewDir.z = currentView->r.viewaxis.mat[0].z;
            v16->transSortScaleBias.x = material[14];
            v16->transSortScaleBias.y = material[15];
            v16->transSortScaleBias.z = material[16];
            v16->transSortScaleBias.w = material[17];
            ApproximateLighting = idRenderModel::GetApproximateLighting(this);
            approximateLighting_t::operator=(this: &v16->lighting, __that: ApproximateLighting);
            v16->verts = nullptr;
            v16->quadDepth = nullptr;
            v16->quadsUsed = nullptr;
            idRenderModelTransparency::AllocateQuadSegment(
              numQuads: geometry->numVerts / 4,
              verts: &v16->verts,
              quadDepths: &v16->quadDepth,
              quadsUsed: &v16->quadsUsed,
              hasEmissivePass: false);
            if ( valueInteger == 1 )
              idParallelJobList::AddJob(
                this: updateTools->transparencyJobList,
                function: (void (__fastcall *)(void *))StaticTransparencyGenJob,
                data: v16);
            else
              StaticTransparencyGenJob(parms: v16);
          }
        }
      }
      staticModel = this->staticModel;
      ++v9;
      ++v12;
    }
    while ( v9 < staticModel->surfaces.num );
  }
  return 1;
}


// ========================================================================
// ??0idRenderModelStatic@@QAA@PBVidStaticModel@@@Z
// EA  : 0x828670D8
// RVA : 0x008670D8
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

idRenderModelStatic *__fastcall idRenderModelStatic::idRenderModelStatic(
        idRenderModelStatic *this,
        const idStaticModel *smod)
{
  float *v4; // r10
  bool *p_modelIsAutosprite; // r11
  int i; // ctr
  double v7; // fp13
  double v8; // fp12
  double v9; // fp11
  double v10; // fp10
  double v11; // fp9
  float v13[17]; // [sp+5Ch] [-44h] BYREF

  idRenderModel::idRenderModel(this);
  this->__vftable = (idRenderModelStatic_vtbl *)&idRenderModelStatic::`vftable';
  this->transparencyGenParms.list = nullptr;
  this->transparencyGenParms.granularity = 0;
  this->transparencyGenParms.memTag = 5;
  this->transparencyGenParms.listStatic = 0;
  this->transparencyGenParms.size = 0;
  this->transparencyGenParms.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->transparencyGenParms);
  idRenderModel::SetName(this, name_: smod->name.str);
  v4 = v13;
  p_modelIsAutosprite = &smod->modelIsAutosprite;
  for ( i = 6; i != 0; --i )
  {
    p_modelIsAutosprite += 4;
    *++v4 = *(float *)p_modelIsAutosprite;
  }
  v7 = v13[2];
  v8 = v13[3];
  v9 = v13[4];
  this->referenceBounds.b[0].x = v13[1];
  v10 = v13[5];
  this->referenceBounds.b[0].y = v7;
  this->referenceBounds.b[0].z = v8;
  this->referenceBounds.b[1].x = v9;
  v11 = v13[6];
  this->referenceBounds.b[1].y = v10;
  this->referenceBounds.b[1].z = v11;
  if ( smod->usesTransparencySort )
    *((_BYTE *)&this->g + 106) |= 4u;
  this->staticModel = smod;
  this->reloadCount = 0;
  this->skin = -1;
  return this;
}


// ========================================================================
// __unwind$220429_0
// EA  : 0x828671C4
// RVA : 0x008671C4
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

void _unwind_220429_0()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$220430
// EA  : 0x828671EC
// RVA : 0x008671EC
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

void _unwind_220430()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 2044));
}


// ========================================================================
// ??1idRenderModelStatic@@MAA@XZ
// EA  : 0x82867220
// RVA : 0x00867220
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

void __fastcall idRenderModelStatic::~idRenderModelStatic(idRenderModelStatic *this)
{
  int v2; // r29
  int v3; // r28
  staticTransparencyGenParms_t **list; // r4
  staticTransparencyGenParms_t **v5; // r4

  this->__vftable = (idRenderModelStatic_vtbl *)&idRenderModelStatic::`vftable';
  v2 = 0;
  if ( this->transparencyGenParms.num > 0 )
  {
    v3 = 0;
    do
    {
      idMem::Free(this: &mem, ptr: this->transparencyGenParms.list[v3], align: ALIGN_16);
      ++v2;
      ++v3;
    }
    while ( v2 < this->transparencyGenParms.num );
  }
  if ( this->transparencyGenParms.listStatic == 0 || this->transparencyGenParms.listStatic == 2 )
  {
    list = this->transparencyGenParms.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->transparencyGenParms.list = nullptr;
    this->transparencyGenParms.size = 0;
  }
  this->transparencyGenParms.num = 0;
  if ( this->transparencyGenParms.listStatic == 0 || this->transparencyGenParms.listStatic == 2 )
  {
    v5 = this->transparencyGenParms.list;
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    this->transparencyGenParms.list = nullptr;
    this->transparencyGenParms.size = 0;
  }
  this->transparencyGenParms.num = 0;
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$220652
// EA  : 0x82867314
// RVA : 0x00867314
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

void _unwind_220652()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$220653
// EA  : 0x8286733C
// RVA : 0x0086733C
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

void _unwind_220653()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2044));
}


// ========================================================================
// ?CommitSubclass@idRenderModelStatic@@UAA_NXZ
// EA  : 0x828673D0
// RVA : 0x008673D0
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

BOOL __fastcall idRenderModelStatic::CommitSubclass(idRenderModelStatic *this)
{
  int v3; // r27
  idStaticList<idRenderModel::decalData_t,16> *p_decalData; // r26
  int v5; // r28
  idRenderModel::decalData_t *v6; // r29
  float *Axis; // r3
  double y; // fp13
  double z; // fp0
  double x; // fp12
  double v11; // fp31
  double v12; // fp30
  double v13; // fp29
  idRenderModelParms *Origin; // r3
  double v15; // fp5
  double v16; // fp3
  const idMat3 *v17; // r3
  BOOL v18; // r22
  int v19; // r26
  int v20; // r28
  int v21; // r29
  int *v22; // r9
  int v23; // ctr
  idStaticModelSurface *v24; // r10
  int *p_size; // r11
  skinRemap_t *list; // r4
  const idStaticModel *staticModel; // r11
  const idStaticModel *v28; // r11
  int *v29; // r10
  bool *p_modelIsAutosprite; // r11
  int i; // ctr
  double v32; // fp13
  double v33; // fp12
  double v34; // fp11
  double v35; // fp10
  double v36; // fp9
  int num; // r11
  int v38; // r29
  int customSkin; // r11
  int v40; // r7
  int v41; // r8
  int v42; // r9
  idRenderModelSurface *v43; // r10
  idStaticModelSurface *v44; // r3
  int v45; // r11
  __int64 v46; // [sp+8h] [-138h]
  __int64 v47; // [sp+10h] [-130h]
  __int64 v48; // [sp+18h] [-128h]
  __int64 v49; // [sp+20h] [-120h]
  __int64 v50; // [sp+28h] [-118h]
  __int64 v51; // [sp+30h] [-110h]
  __int64 v52; // [sp+38h] [-108h]
  __int64 v53; // [sp+40h] [-100h]
  __int64 v54; // [sp+48h] [-F8h]
  __int64 v55; // [sp+50h] [-F0h]
  const idStaticModel *p_relativePos; // [sp+60h] [-E0h] BYREF
  idVec3 v57; // [sp+68h] [-D8h] BYREF
  int v58; // [sp+78h] [-C8h] BYREF
  int v59; // [sp+7Ch] [-C4h] BYREF
  idMat3 v60; // [sp+80h] [-C0h] BYREF
  unsigned int v61; // [sp+A8h] [-98h]
  __int64 v62; // [sp+B0h] [-90h]
  idList<skinRemap_t,5> v63; // [sp+B8h] [-88h] BYREF

  if ( this->staticModel == nullptr )
    return false;
  v3 = this->decalData.num - 1;
  if ( v3 >= 0 )
  {
    p_decalData = &this->decalData;
    v5 = v3;
    do
    {
      v6 = &p_decalData->list[v5];
      Axis = (float *)idRenderModel::GetAxis(this);
      y = v6->relativePos.y;
      z = v6->relativePos.z;
      x = v6->relativePos.x;
      p_relativePos = (const idStaticModel *)&v6->relativePos;
      v11 = (float)((float)(Axis[8] * (float)z) + (float)((float)(Axis[2] * (float)x) + (float)(Axis[5] * (float)y)));
      v12 = (float)((float)(Axis[7] * (float)z) + (float)((float)(Axis[1] * (float)x) + (float)(Axis[4] * (float)y)));
      v13 = (float)((float)((float)x * *Axis) + (float)((float)(Axis[3] * (float)y) + (float)(Axis[6] * (float)z)));
      Origin = idRenderModel::GetOrigin(this);
      v15 = (float)(Origin->origin.z + (float)v11);
      v16 = (float)(Origin->origin.y + (float)v12);
      v57.x = Origin->origin.x + (float)v13;
      v57.z = v15;
      v57.y = v16;
      v17 = idRenderModel::GetAxis(this);
      idMat3::operator*(this: &v60, result: &v6->relativeAxis, a: v17);
      if ( !idRenderModel::SetDecalPosition(
              this,
              decalHandle: (const idHandle<int,enum invalidDecalHandle_t,-1> *)v6->handle.value,
              decalWorldPosition: &v57,
              decalWorldAxis: &v60) )
        idList<idRenderModel::decalData_t,5>::RemoveIndexFast(this: &this->decalData, index: v3);
      --v3;
      --v5;
    }
    while ( v3 >= 0 );
  }
  v18 = this->staticModel->reloadCount != this->reloadCount;
  if ( this->staticModel->reloadCount != this->reloadCount )
  {
    this->FreeSurfaces(this);
    v19 = 0;
    v20 = 0;
    if ( this->staticModel->surfaces.num > 0 )
    {
      v21 = 0;
      while ( 1 )
      {
        v22 = &v58;
        v23 = 7;
        v24 = &this->staticModel->surfaces.list[v21];
        p_size = &v24[-1].skinRemaps.size;
        do
        {
          p_size += 2;
          v22 += 2;
          *(_QWORD *)v22 = *(_QWORD *)p_size;
          --v23;
        }
        while ( v23 != 0 );
        v63.list = nullptr;
        v63.listStatic = 0;
        idList<skinRemap_t,5>::operator=(this: &v63, other: &v24->skinRemaps);
        if ( (*(_BYTE *)(LODWORD(v60.mat[0].x) + 72) & 8) == 0 )
          break;
        ++v19;
        if ( v63.listStatic == 0 || v63.listStatic == 2 )
        {
          list = v63.list;
          if ( v63.list != nullptr )
            goto LABEL_21;
LABEL_22:
          v63.list = nullptr;
          v63.size = 0;
        }
LABEL_23:
        staticModel = this->staticModel;
        ++v20;
        v63.num = 0;
        ++v21;
        if ( v20 >= staticModel->surfaces.num )
          goto LABEL_24;
      }
      HIBYTE(v60.mat[1].z) = 1;
      idRenderModel::AddSurface(
        this: (idRenderModel *)LODWORD(v60.mat[0].x),
        surf: (idRenderModelSurface *)LODWORD(v60.mat[0].z),
        a3: *(__int64 *)&v60.mat[1].y,
        a4: __SPAIR64__(LODWORD(v60.mat[2].z), v61),
        a5: v62,
        a6: v46,
        a7: v47,
        a8: v48,
        a9: v49,
        a10: v50,
        a11: v51,
        a12: v52,
        a13: v53,
        a14: v54,
        a15: v55);
      if ( v63.listStatic != 0 && v63.listStatic != 2 )
        goto LABEL_23;
      list = v63.list;
      if ( v63.list == nullptr )
        goto LABEL_22;
LABEL_21:
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      goto LABEL_22;
    }
LABEL_24:
    idRenderModel::FinishSurfaces(this);
    v28 = this->staticModel;
    if ( !v28->modelIsAutosprite )
    {
      p_relativePos = this->staticModel;
      v29 = &v59;
      p_modelIsAutosprite = &v28->modelIsAutosprite;
      for ( i = 6; i != 0; --i )
      {
        p_modelIsAutosprite += 4;
        *++v29 = *(_DWORD *)p_modelIsAutosprite;
      }
      v32 = v60.mat[0].y;
      v33 = v60.mat[0].z;
      v34 = v60.mat[1].x;
      this->referenceBounds.b[0].x = v60.mat[0].x;
      p_relativePos = (const idStaticModel *)&this->referenceBounds.b[1];
      v35 = v60.mat[1].y;
      this->referenceBounds.b[0].y = v32;
      this->referenceBounds.b[0].z = v33;
      this->referenceBounds.b[1].x = v34;
      v36 = v60.mat[1].z;
      this->referenceBounds.b[1].y = v35;
      this->referenceBounds.b[1].z = v36;
    }
    if ( this->staticModel->usesTransparencySort )
    {
      *((_BYTE *)&this->g + 106) |= 4u;
      idRenderModel::SetLitTransSortFlag(this);
    }
    num = this->transparencyGenParms.num;
    this->reloadCount = this->staticModel->reloadCount;
    if ( num < v19 )
    {
      v38 = v19 - num;
      do
      {
        p_relativePos = (const idStaticModel *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\engine\\models\\static\\RenderModelStatic.cpp(140) : TAG_RENDERMODEL",
                                                 size: 0x104u,
                                                 tag: TAG_RENDERMODEL,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->transparencyGenParms,
          obj: (const encounterGroupRole_t *)&p_relativePos);
        --v38;
      }
      while ( v38 != 0 );
    }
  }
  customSkin = this->g.customSkin;
  if ( this->skin != customSkin || v18 )
  {
    this->skin = customSkin;
    if ( customSkin >= 0 )
    {
      v40 = 0;
      if ( this->surfaces.num > 0 )
      {
        v41 = 0;
        v42 = 0;
        do
        {
          ++v40;
          v43 = &this->surfaces.list[v42++];
          v44 = &this->staticModel->surfaces.list[v41++];
          v45 = (int)&v44->skinRemaps.list[this->skin];
          v43->material = *(const idMaterial **)v45;
          v43->skinOffsets.x = *(float *)(v45 + 4);
          v43->skinOffsets.y = *(float *)(v45 + 8);
          v43->skinOffsets.z = *(float *)(v45 + 4);
          v43->skinOffsets.w = *(float *)(v45 + 8);
        }
        while ( v40 < this->surfaces.num );
      }
    }
  }
  return v18;
}


// ========================================================================
// __unwind$220802_0
// EA  : 0x82867820
// RVA : 0x00867820
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

void _unwind_220802_0()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 320 + 128));
}


// ========================================================================
// `dynamic initializer for 'r_staticTransparencyFadeStartDist''
// EA  : 0x83344AD8
// RVA : 0x01344AD8
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_staticTransparencyFadeStartDist__()
{
  idCVar::idCVar(
    this: &r_staticTransparencyFadeStartDist,
    name: "r_staticTransparencyFadeStartDist",
    value: "1024",
    flags: 4,
    description: "start fading out at this range",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_staticTransparencyFadeStartDist__);
}


// ========================================================================
// `dynamic initializer for 'r_staticTransparencyFadeMaxDist''
// EA  : 0x83344B30
// RVA : 0x01344B30
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_staticTransparencyFadeMaxDist__()
{
  idCVar::idCVar(
    this: &r_staticTransparencyFadeMaxDist,
    name: "r_staticTransparencyFadeMaxDist",
    value: "2048",
    flags: 4,
    description: "completely faded out at this range",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_staticTransparencyFadeMaxDist__);
}


// ========================================================================
// `dynamic initializer for 'r_useStaticTransparencyGenJobs''
// EA  : 0x83344B88
// RVA : 0x01344B88
// PDB : w:\tech5\engine\models\static\rendermodelstatic.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useStaticTransparencyGenJobs__()
{
  idCVar::idCVar(
    this: &r_useStaticTransparencyGenJobs,
    name: "r_useStaticTransparencyGenJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useStaticTransparencyGenJobs__);
}

