
// ========================================================================
// ?AssignNodeOcclusionIndices_r@idRenderWorldLocal@@QAAXHHAAH@Z
// EA  : 0x82963B00
// RVA : 0x00963B00
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::AssignNodeOcclusionIndices_r(
        idRenderWorldLocal *this,
        int nodeNum,
        int depth,
        int *numOcclusionIndices)
{
  int v5; // r29
  areaNode_t *v7; // r31
  int v8; // r4

  v5 = depth;
  if ( depth == 6 )
  {
LABEL_6:
    if ( *numOcclusionIndices < 64 )
      this->areaNodeOcclusionIndex[nodeNum] = (*numOcclusionIndices)++;
  }
  else
  {
    while ( 1 )
    {
      v7 = &this->areaNodes[nodeNum];
      v8 = v7->children[0];
      if ( v8 > 0 )
        idRenderWorldLocal::AssignNodeOcclusionIndices_r(this, nodeNum: v8, depth: v5 + 1, numOcclusionIndices);
      nodeNum = v7->children[1];
      if ( nodeNum <= 0 )
        break;
      if ( ++v5 == 6 )
        goto LABEL_6;
    }
  }
}


// ========================================================================
// ?BuildNodeBounds_r@idRenderWorldLocal@@QAA?AVidBounds@@HPAVidPlane@@H@Z
// EA  : 0x82963B98
// RVA : 0x00963B98
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

idRenderWorldLocal *__fastcall idRenderWorldLocal::BuildNodeBounds_r(
        idRenderWorldLocal *this,
        idBounds *result,
        int nodeNum,
        idPlane *planes,
        int numPlanes)
{
  int v8; // r27
  int v9; // r31
  idPlane *v10; // r9
  idBounds *v11; // r3
  idBounds *v12; // r11
  idRenderWorldLocal *v13; // r8
  idRenderWorldLocal_vtbl **v14; // r9
  int v15; // ctr
  double v17; // fp13
  int v18; // r11
  double v19; // fp0
  idPlane *v20; // r8
  double v21; // fp7
  float v22; // r5
  float v23; // r9
  float v24; // r10
  idBounds *v25; // r3
  idBounds *v26; // r11
  idRenderWorldLocal_vtbl **p_z; // r9
  idRenderWorldLocal *v28; // r8
  int i; // ctr
  double v30; // fp9
  idPlane *v31; // r30
  int v32; // r26
  float x; // r8
  float v34; // r9
  float y; // r10
  idBounds *v36; // r3
  idRenderWorldLocal *v37; // r10
  int v38; // ctr
  idRenderWorldLocal_vtbl **v39; // r11
  int v40; // r31
  int v41; // r30
  int v42; // r8
  int v43; // r10
  int v50; // r7
  int v51; // r9
  float *v52; // r5
  float *v53; // r4
  float *v54; // r3
  float *v55; // r11
  int v98; // r11
  int v99; // ctr
  float *v100; // r8
  idRenderWorldLocal *v107; // r6
  float *v108; // r11
  int v109; // ctr
  float *v110; // r10
  float *v111; // r9
  double z; // fp1
  idBounds v125; // [sp+50h] [-140h] BYREF
  float v126[8]; // [sp+70h] [-120h] BYREF
  idBounds v127; // [sp+90h] [-100h] BYREF
  _BYTE v128[160]; // [sp+B0h] [-E0h] BYREF

  if ( nodeNum < 0 )
  {
    v40 = -1 - nodeNum;
    v41 = 72 * (-1 - nodeNum) + LODWORD(result[2].b[1].x);
    idPlane::ConvexPolytopeBounds(result: &v125, planes, numPlanes);
    v42 = *(_DWORD *)(v41 + 52);
    v43 = 0;
    _FP13 = 1.0e30;
    _FP0 = -1.0e30;
    _FP9 = 1.0e30;
    _FP10 = 1.0e30;
    _FP11 = -1.0e30;
    _FP12 = -1.0e30;
    if ( v42 >= 4 )
    {
      v50 = *(_DWORD *)(v41 + 48);
      v51 = 0;
      do
      {
        v43 += 4;
        v52 = *(float **)(v50 + v51 + 16);
        v53 = *(float **)(v50 + v51 + 72);
        v54 = *(float **)(v50 + v51 + 128);
        v55 = *(float **)(v50 + v51 + 184);
        v51 += 224;
        _FP6 = (float)((float)_FP13 - *v52);
        _FP29 = (float)(v52[4] - (float)_FP12);
        _FP28 = (float)(v52[5] - (float)_FP11);
        _FP4 = (float)((float)_FP10 - v52[1]);
        _FP2 = (float)((float)_FP9 - v52[2]);
        _FP31 = (float)(v52[3] - (float)_FP0);
        __asm { fsel      f13, f6, f8, f13 }
        __asm { fsel      f1, f29, f1, f12 }
        __asm { fsel      f12, f28, f30, f11 }
        __asm { fsel      f7, f4, f7, f10 }
        __asm { fsel      f5, f2, f5, f9 }
        __asm { fsel      f3, f31, f3, f0 }
        _FP29 = (float)((float)_FP13 - *v53);
        _FP17 = (float)(v53[4] - (float)_FP1);
        _FP16 = (float)(v53[5] - (float)_FP12);
        _FP22 = (float)((float)_FP7 - v53[1]);
        _FP20 = (float)((float)_FP5 - v53[2]);
        _FP18 = (float)(v53[3] - (float)_FP3);
        __asm
        {
          fsel      f13, f29, f27, f13
          fsel      f1, f17, f23, f1
          fsel      f12, f16, f8, f12
          fsel      f7, f22, f26, f7
          fsel      f5, f20, f25, f5
          fsel      f3, f18, f24, f3
        }
        _FP8 = (float)((float)_FP13 - *v54);
        _FP25 = (float)(v54[4] - (float)_FP1);
        _FP24 = (float)(v54[5] - (float)_FP12);
        _FP29 = (float)((float)_FP7 - v54[1]);
        _FP27 = (float)((float)_FP5 - v54[2]);
        _FP26 = (float)(v54[3] - (float)_FP3);
        __asm
        {
          fsel      f6, f8, f6, f13
          fsel      f11, f25, f11, f1
          fsel      f8, f24, f10, f12
          fsel      f4, f29, f4, f7
          fsel      f2, f27, f2, f5
          fsel      f0, f26, f0, f3
        }
        _FP7 = (float)((float)_FP6 - *v55);
        _FP12 = (float)(v55[4] - (float)_FP11);
        _FP29 = (float)(v55[5] - (float)_FP8);
        _FP5 = (float)((float)_FP4 - v55[1]);
        _FP3 = (float)((float)_FP2 - v55[2]);
        _FP1 = (float)(v55[3] - (float)_FP0);
        __asm
        {
          fsel      f13, f7, f9, f6
          fsel      f12, f12, f21, f11
          fsel      f11, f29, f19, f8
          fsel      f10, f5, f31, f4
          fsel      f9, f3, f30, f2
          fsel      f0, f1, f28, f0
        }
      }
      while ( v43 < v42 - 3 );
    }
    if ( v43 < v42 )
    {
      v98 = 56 * v43;
      v99 = v42 - v43;
      do
      {
        v100 = *(float **)(*(_DWORD *)(v41 + 48) + v98 + 16);
        v98 += 56;
        _FP6 = (float)((float)_FP13 - *v100);
        _FP4 = (float)((float)_FP10 - v100[1]);
        _FP2 = (float)((float)_FP9 - v100[2]);
        _FP31 = (float)(v100[3] - (float)_FP0);
        _FP29 = (float)(v100[4] - (float)_FP12);
        _FP28 = (float)(v100[5] - (float)_FP11);
        __asm
        {
          fsel      f13, f6, f8, f13
          fsel      f10, f4, f7, f10
          fsel      f9, f2, f5, f9
          fsel      f0, f31, f3, f0
          fsel      f12, f29, f1, f12
          fsel      f11, f28, f30, f11
        }
        --v99;
      }
      while ( v99 != 0 );
    }
    if ( _FP13 > _FP0 )
    {
      _FP0 = (float)((float)(v125.b[0].x + v125.b[1].x) * (float)0.5);
      _FP12 = (float)((float)(v125.b[0].y + v125.b[1].y) * (float)0.5);
      _FP11 = (float)((float)(v125.b[0].z + v125.b[1].z) * (float)0.5);
      _FP13 = _FP0;
      _FP10 = _FP12;
      _FP9 = _FP11;
    }
    v107 = (idRenderWorldLocal *)((char *)this - 4);
    v108 = (float *)(LODWORD(result[2].b[1].y) + 24 * v40);
    v109 = 6;
    v110 = (float *)(LODWORD(result[2].b[1].z) + 24 * v40);
    v111 = v108 - 1;
    *v108 = v125.b[0].x;
    v108[1] = v125.b[0].y;
    v108[2] = v125.b[0].z;
    v108[3] = v125.b[1].x;
    v108[4] = v125.b[1].y;
    z = v125.b[1].z;
    v108[5] = v125.b[1].z;
    _FP29 = (float)((float)_FP11 - (float)z);
    _FP5 = (float)(v108[1] - (float)_FP10);
    _FP28 = (float)((float)_FP12 - v108[4]);
    _FP4 = (float)(*v108 - (float)_FP13);
    _FP31 = (float)(v108[2] - (float)_FP9);
    _FP30 = (float)((float)_FP0 - v108[3]);
    __asm { fsel      f6, f5, f10, f6 }
    v108[1] = _FP6;
    __asm { fsel      f5, f4, f13, f7 }
    *v108 = _FP5;
    __asm { fsel      f4, f31, f9, f3 }
    v108[2] = _FP4;
    __asm { fsel      f3, f30, f0, f2 }
    v108[3] = _FP3;
    __asm { fsel      f2, f29, f11, f1 }
    v108[5] = _FP2;
    __asm { fsel      f1, f28, f12, f8 }
    v108[4] = _FP1;
    *v110 = _FP13;
    v110[1] = _FP10;
    v110[2] = _FP9;
    v110[3] = _FP0;
    v110[4] = _FP12;
    v110[5] = _FP11;
    do
    {
      ++v111;
      v107 = (idRenderWorldLocal *)((char *)v107 + 4);
      v107->__vftable = *(idRenderWorldLocal_vtbl **)v111;
      --v109;
    }
    while ( v109 != 0 );
    return this;
  }
  else
  {
    v8 = 24 * nodeNum;
    v9 = LODWORD(result[1].b[1].z) + 24 * nodeNum;
    if ( *(_DWORD *)(v9 + 16) != 0 )
    {
      v17 = *(float *)(v9 + 4);
      v18 = numPlanes;
      if ( *(_DWORD *)(v9 + 20) != 0 )
      {
        v30 = -*(float *)(v9 + 8);
        v125.b[0].x = -*(float *)v9;
        v125.b[0].y = -v17;
        v31 = &planes[v18];
        v125.b[0].z = v30;
        v32 = numPlanes + 1;
        v125.b[1].x = -*(float *)(v9 + 12);
        x = v125.b[0].x;
        v34 = v125.b[1].x;
        y = v125.b[0].y;
        v31->c = v125.b[0].z;
        v31->d = v34;
        v31->b = y;
        planes[v18].a = x;
        idRenderWorldLocal::BuildNodeBounds_r(
          this: (idRenderWorldLocal *)v126,
          result,
          nodeNum: *(_DWORD *)(v9 + 16),
          planes,
          numPlanes: numPlanes + 1);
        v31->a = *(float *)v9;
        v31->b = *(float *)(v9 + 4);
        v31->c = *(float *)(v9 + 8);
        v31->d = *(float *)(v9 + 12);
        idRenderWorldLocal::BuildNodeBounds_r(
          this: (idRenderWorldLocal *)&v127,
          result,
          nodeNum: *(_DWORD *)(v9 + 20),
          planes,
          numPlanes: v32);
        v36 = (idBounds *)(v8 + LODWORD(result[2].b[0].x));
        qmemcpy(v36, v126, sizeof(idBounds));
        idBounds::AddBounds(this: v36, a: &v127);
        v37 = (idRenderWorldLocal *)((char *)this - 4);
        v38 = 6;
        v39 = (idRenderWorldLocal_vtbl **)(v8 + LODWORD(result[2].b[0].x) - 4);
        do
        {
          ++v39;
          v37 = (idRenderWorldLocal *)((char *)v37 + 4);
          v37->__vftable = *v39;
          --v38;
        }
        while ( v38 != 0 );
        return this;
      }
      else
      {
        v19 = *(float *)(v9 + 12);
        v125.b[0].y = -v17;
        v125.b[1].x = -v19;
        v20 = &planes[v18];
        v21 = -*(float *)(v9 + 8);
        v125.b[0].x = -*(float *)v9;
        v125.b[0].z = v21;
        v22 = v125.b[0].x;
        v23 = v125.b[0].z;
        v24 = v125.b[1].x;
        v20->b = v125.b[0].y;
        v20->c = v23;
        planes[v18].a = v22;
        v20->d = v24;
        v25 = idRenderWorldLocal::BuildNodeBounds_r(
                this: (idRenderWorldLocal *)v128,
                result,
                nodeNum: *(_DWORD *)(v9 + 16),
                planes,
                numPlanes: numPlanes + 1);
        v26 = (idBounds *)(LODWORD(result[2].b[0].x) + v8);
        p_z = (idRenderWorldLocal_vtbl **)&v26[-1].b[1].z;
        v28 = (idRenderWorldLocal *)((char *)this - 4);
        *v26 = *v25;
        for ( i = 6; i != 0; --i )
        {
          ++p_z;
          v28 = (idRenderWorldLocal *)((char *)v28 + 4);
          v28->__vftable = *p_z;
        }
        return this;
      }
    }
    else
    {
      v10 = &planes[numPlanes];
      v10->a = *(float *)v9;
      v10->b = *(float *)(v9 + 4);
      v10->c = *(float *)(v9 + 8);
      v10->d = *(float *)(v9 + 12);
      v11 = idRenderWorldLocal::BuildNodeBounds_r(
              this: (idRenderWorldLocal *)v128,
              result,
              nodeNum: *(_DWORD *)(v9 + 20),
              planes,
              numPlanes: numPlanes + 1);
      v12 = (idBounds *)(LODWORD(result[2].b[0].x) + v8);
      v13 = (idRenderWorldLocal *)((char *)this - 4);
      v14 = (idRenderWorldLocal_vtbl **)&v12[-1].b[1].z;
      v15 = 6;
      *v12 = *v11;
      do
      {
        ++v14;
        v13 = (idRenderWorldLocal *)((char *)v13 + 4);
        v13->__vftable = *v14;
        --v15;
      }
      while ( v15 != 0 );
      return this;
    }
  }
}


// ========================================================================
// ?InitForTools@idRenderWorldLocal@@UAA_NPBD@Z
// EA  : 0x829641E0
// RVA : 0x009641E0
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

int __fastcall idRenderWorldLocal::InitForTools(idRenderWorldLocal *this, const char *name)
{
  idStr::operator=(this: &this->mapName, text: name);
  idGlobalShadows::LoadGlobalShadows(this: &this->globalShadows, rw: this->mapName.len == 0 ? nullptr : this);
  idAmbientLighting::LoadAmbientLighting(this: &this->ambientLighting, rw: this->mapName.len == 0 ? nullptr : this);
  return 1;
}


// ========================================================================
// ?ParseNodes@idRenderWorldLocal@@QAAXPAVidLexer@@@Z
// EA  : 0x82964248
// RVA : 0x00964248
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::ParseNodes(idRenderWorldLocal *this, idLexer *src)
{
  int v4; // r3
  unsigned int numAreaNodes; // r11
  areaNode_t *areaNodes; // r5
  float *areaNodeBounds; // r8
  unsigned int v8; // r5
  int *v9; // r3
  int v10; // r9
  int v11; // r28
  int v12; // r27
  int v13; // r30
  areaNode_t *v14; // r29
  float *v15; // r11

  idLexer::ExpectTokenString(this: src, string: "{");
  v4 = idLexer::ParseInt(this: src);
  this->numAreaNodes = v4;
  if ( v4 >= 0 )
  {
    if ( this->IsComboMap(this) && this->numAreaNodes > 0x2000 )
    {
      idLexer::Error(this: src, str: "idRenderWorldLocal::ParseNodes: more than %d area nodes", 0x2000);
    }
    else
    {
      numAreaNodes = this->numAreaNodes;
      if ( numAreaNodes != 0 )
      {
        if ( numAreaNodes > 0xAAAAAAA )
          v8 = -1;
        else
          v8 = 24 * numAreaNodes;
        this->areaNodes = (areaNode_t *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                          size: v8,
                                          tag: TAG_RENDERWORLD,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
        this->areaNodeBounds = (idBounds *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(123) : TAG_RENDERWORLD",
                                             size: 24 * this->numAreaNodes,
                                             tag: TAG_RENDERWORLD,
                                             zeroBuffer: false,
                                             align: ALIGN_128,
                                             heap: HEAP_DEFAULTHEAP);
        v9 = (int *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(124) : TAG_RENDERWORLD",
                      size: 4 * this->numAreaNodes,
                      tag: TAG_RENDERWORLD,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
        v10 = this->numAreaNodes;
        this->areaNodeOcclusionIndex = v9;
        v11 = 0;
        if ( v10 > 0 )
        {
          v12 = 0;
          v13 = 0;
          do
          {
            v14 = &this->areaNodes[v13];
            idLexer::Parse1DMatrix(this: src, x: 4, m: &v14->plane.a, expectCommas: false);
            v14->children[0] = idLexer::ParseInt(this: src);
            v14->children[1] = idLexer::ParseInt(this: src);
            v15 = (float *)&this->areaNodeBounds[v13];
            v15[5] = 0.0;
            ++v11;
            v15[4] = 0.0;
            ++v13;
            v15[3] = 0.0;
            v15[2] = 0.0;
            v15[1] = 0.0;
            *v15 = 0.0;
            this->areaNodeOcclusionIndex[v12++] = -1;
          }
          while ( v11 < this->numAreaNodes );
        }
      }
      else
      {
        this->numAreaNodes = 1;
        this->areaNodes = (areaNode_t *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                          size: 0x18u,
                                          tag: TAG_RENDERWORLD,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
        this->areaNodeBounds = (idBounds *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(113) : TAG_RENDERWORLD",
                                             size: 0x18u,
                                             tag: TAG_RENDERWORLD,
                                             zeroBuffer: false,
                                             align: ALIGN_128,
                                             heap: HEAP_DEFAULTHEAP);
        this->areaNodeOcclusionIndex = (int *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(114) : TAG_RENDERWORLD",
                                                size: 4u,
                                                tag: TAG_RENDERWORLD,
                                                zeroBuffer: false,
                                                align: ALIGN_16,
                                                heap: HEAP_DEFAULTHEAP);
        areaNodes = this->areaNodes;
        areaNodes->plane.a = 0.0;
        areaNodes->plane.b = 0.0;
        areaNodes->plane.c = 1.0;
        areaNodes->plane.d = 131072.0;
        this->areaNodes->children[0] = -1;
        this->areaNodes->children[1] = 0;
        areaNodeBounds = (float *)this->areaNodeBounds;
        areaNodeBounds[5] = 0.0;
        areaNodeBounds[4] = 0.0;
        areaNodeBounds[3] = 0.0;
        areaNodeBounds[2] = 0.0;
        areaNodeBounds[1] = 0.0;
        *areaNodeBounds = 0.0;
        *this->areaNodeOcclusionIndex = -1;
      }
      idLexer::ExpectTokenString(this: src, string: "}");
    }
  }
  else
  {
    idLexer::Error(this: src, str: "idRenderWorldLocal::ParseNodes: bad numAreaNodes");
  }
}


// ========================================================================
// ?SeparateDiffuseOnly@idRenderWorldLocal@@QAAX_N@Z
// EA  : 0x82964688
// RVA : 0x00964688
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::SeparateDiffuseOnly(idRenderWorldLocal *this, bool on)
{
  int v4; // r16
  int i; // r27
  worldArea_t *worldAreas; // r11
  int v7; // r28
  int v8; // r29
  worldArea_t *v9; // r11
  idRenderModelSurface *v10; // r30
  const idMaterial *material; // r11
  int materialNum; // r11
  char *v13; // r4
  char *data; // r4
  const idDecl *v15; // r3
  idStr v16[5]; // [sp+50h] [-B0h] BYREF

  v4 = 0;
  if ( this->numWorldAreas > 0 )
  {
    for ( i = 0; ; ++i )
    {
      worldAreas = this->worldAreas;
      v7 = 0;
      if ( worldAreas[i].worldSurfaces.num > 0 )
        break;
LABEL_36:
      if ( ++v4 >= this->numWorldAreas )
        return;
    }
    v8 = 0;
    v9 = &worldAreas[i];
    while ( 1 )
    {
      v10 = &v9->worldSurfaces.list[v8];
      material = v10->material;
      if ( v10->material == nullptr || material->pageSource <= PAGESOURCE_VMTR )
        goto LABEL_35;
      idStr::idStr(this: v16, text: material->name.str);
      if ( !on )
      {
        if ( idStr::StripTrailingOnce(this: v16, string: "mega.decl") )
        {
          v10->materialNum = 1;
        }
        else if ( idStr::StripTrailingOnce(this: v16, string: "megatrans.decl") )
        {
          v10->materialNum = 2;
        }
        else if ( idStr::StripTrailingOnce(this: v16, string: "meganospec.decl") )
        {
          v10->materialNum = 3;
        }
        else if ( idStr::StripTrailingOnce(this: v16, string: "meganospec_2.decl") )
        {
          v10->materialNum = 4;
        }
        if ( v10->materialNum == 0 )
          goto LABEL_34;
        idStr::Append(this: v16, text: "mega.decl");
        data = v16[0].data;
        if ( v16[0].data == nullptr )
        {
          v15 = nullptr;
          goto LABEL_33;
        }
LABEL_32:
        v15 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: data, makeDefault: true);
        goto LABEL_33;
      }
      materialNum = v10->materialNum;
      if ( materialNum != 1 )
      {
        if ( materialNum == 2 )
        {
          idStr::StripTrailingOnce(this: v16, string: "mega.decl");
          idStr::Append(this: v16, text: "megatrans.decl");
          if ( v16[0].data != nullptr )
            v10->material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                  this: &idMaterial::resourceList,
                                                  name: v16[0].data,
                                                  makeDefault: true);
          else
            v10->material = nullptr;
        }
        else
        {
          if ( materialNum == 3 )
          {
            idStr::StripTrailingOnce(this: v16, string: "mega.decl");
            v13 = "meganospec.decl";
          }
          else
          {
            if ( materialNum != 4 )
              goto LABEL_18;
            idStr::StripTrailingOnce(this: v16, string: "mega.decl");
            v13 = "meganospec_2.decl";
          }
          idStr::Append(this: v16, text: v13);
        }
      }
LABEL_18:
      if ( v10->materialNum != 0 )
      {
        data = v16[0].data;
        if ( v16[0].data == nullptr )
        {
          v15 = nullptr;
LABEL_33:
          v10->material = (const idMaterial *)v15;
          goto LABEL_34;
        }
        goto LABEL_32;
      }
LABEL_34:
      idStr::FreeData(this: v16);
LABEL_35:
      ++v7;
      ++v8;
      v9 = &this->worldAreas[i];
      if ( v7 >= v9->worldSurfaces.num )
        goto LABEL_36;
    }
  }
}


// ========================================================================
// __unwind$235003_0
// EA  : 0x829648F4
// RVA : 0x009648F4
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_235003_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 80));
}


// ========================================================================
// ?separateDiffuseOnly_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82964920
// RVA : 0x00964920
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void __fastcall separateDiffuseOnly_f(const idCmdArgs *args)
{
  const char *v1; // r3
  int v2; // r3

  if ( args->argc == 1 )
  {
    idLib::Printf(fmt: "USAGE: separateDiffuseOnly <0/1>\n");
  }
  else if ( tr.primaryWorld != nullptr )
  {
    if ( args->argc <= 1 )
      v1 = &byte_8200D768;
    else
      v1 = args->argv[1];
    v2 = idStr::Icmp(s1: v1, s2: "0");
    idRenderWorldLocal::SeparateDiffuseOnly(this: tr.primaryWorld, on: v2 != 0);
  }
  else
  {
    idLib::Printf(fmt: "no primary world\n");
  }
}


// ========================================================================
// ?ParseInterAreaPortals@idRenderWorldLocal@@QAAXPAVidLexer@@@Z
// EA  : 0x829649E8
// RVA : 0x009649E8
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::ParseInterAreaPortals(idRenderWorldLocal *this, idLexer *src)
{
  int v4; // r3
  int v5; // r28
  unsigned int v6; // r5
  int *v7; // r3
  worldArea_t *v8; // r27
  worldArea_t *v9; // r11

  idLexer::ExpectTokenString(this: src, string: "{");
  v4 = idLexer::ParseInt(this: src);
  v5 = v4;
  this->numWorldAreas = v4;
  if ( v4 >= 0 )
  {
    if ( v4 <= 0x2000 )
    {
      v6 = 72 * v4 + 4;
      if ( (unsigned int)(72 * v4) > 0xFFFFFFFB )
        v6 = -1;
      v7 = (int *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                    size: v6,
                    tag: TAG_RENDERWORLD,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
      {
        *v7 = v5;
        v8 = (worldArea_t *)(v7 + 1);
        `eh vector constructor iterator'(
          ptr: v7 + 1,
          size: 0x48u,
          count: v5,
          pCtor: (void (__fastcall *)(void *))worldArea_t::worldArea_t,
          pDtor: (void (__fastcall *)(void *))idSurface::~idSurface);
        v9 = v8;
      }
      else
      {
        v9 = nullptr;
      }
      this->worldAreas = v9;
      this->worldAreaSubspaceBounds = (idBounds *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(41) : TAG_RENDERWORLD",
                                                    size: 24 * this->numWorldAreas,
                                                    tag: TAG_RENDERWORLD,
                                                    zeroBuffer: false,
                                                    align: ALIGN_128,
                                                    heap: HEAP_DEFAULTHEAP);
      this->worldAreaGeometryBounds = (idBounds *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(42) : TAG_RENDERWORLD",
                                                    size: 24 * this->numWorldAreas,
                                                    tag: TAG_RENDERWORLD,
                                                    zeroBuffer: false,
                                                    align: ALIGN_128,
                                                    heap: HEAP_DEFAULTHEAP);
      if ( idLexer::ParseInt(this: src) >= 0 )
        idLexer::ExpectTokenString(this: src, string: "}");
      else
        idLexer::Error(this: src, str: "idRenderWorldLocal::ParseInterAreaPortals: bad numInterAreaPortals");
    }
    else
    {
      idLexer::Error(this: src, str: "idRenderWorldLocal::ParseInterAreaPortals: more than %d world areas", 0x2000);
    }
  }
  else
  {
    idLexer::Error(this: src, str: "idRenderWorldLocal::ParseInterAreaPortals: bad numWorldAreas");
  }
}


// ========================================================================
// __unwind$235267_0
// EA  : 0x82964B98
// RVA : 0x00964B98
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_235267_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_RENDERWORLD);
}


// ========================================================================
// ?SetBinaryModelState_Internal@idRenderWorldLocal@@QAAXPBD_N1@Z
// EA  : 0x82964BD0
// RVA : 0x00964BD0
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::SetBinaryModelState_Internal(
        idRenderWorldLocal *this,
        const char *binaryModelName,
        bool isVisible,
        const bool makingDefinition,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        bool a16)
{
  char *data; // r3
  int v21; // r29
  unsigned __int8 v22; // r9
  char *v23; // r10
  int v24; // r30
  int v25; // r30
  idStr v26[4]; // [sp+50h] [-80h] BYREF

  a16 = isVisible;
  idStr::idStr(this: v26, text: binaryModelName);
  data = v26[0].data;
  v21 = 0;
  v22 = *v26[0].data;
  if ( *v26[0].data != 0 )
  {
    v23 = v26[0].data;
    do
    {
      ++v23;
      v21 = 31 * v21 + v22;
      v22 = *v23;
    }
    while ( *v23 != 0 );
  }
  v24 = this->binaryModelHash.hash[this->binaryModelHash.hashMask & this->binaryModelHash.lookupMask & v21];
  if ( v24 == -1 )
  {
LABEL_9:
    if ( makingDefinition )
    {
      v25 = idList<idStr,5>::Append(this: &this->binaryModelNames, obj: v26);
      idList<unsigned char,25>::Append(
        this: (idList<unsigned char,37> *)&this->binaryModelState,
        obj: (const unsigned __int8 *)&a16);
      idHashIndex::Add(this: &this->binaryModelHash, key: v21, index: v25);
      goto LABEL_16;
    }
    idLib::Error(fmt: "BinaryModelName '%s' was not defined", binaryModelName);
  }
  else
  {
    while ( idStr::Cmp(s1: data, s2: this->binaryModelNames.list[v24].data) != 0 )
    {
      v24 = this->binaryModelHash.indexChain[this->binaryModelHash.lookupMask & v24];
      if ( v24 == -1 )
        goto LABEL_9;
      data = v26[0].data;
    }
  }
  if ( makingDefinition && strstr(str1: v26[0].data, str2: "world") == nullptr )
    idLib::Error(fmt: "BinaryModelName '%s' was defined twice", binaryModelName);
  this->binaryModelState.list[v24] = isVisible;
LABEL_16:
  idStr::FreeData(this: v26);
}


// ========================================================================
// $LN43_3
// EA  : 0x82964D54
// RVA : 0x00964D54
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _LN43_3()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ClearWorld@idRenderWorldLocal@@QAAXXZ
// EA  : 0x82964D88
// RVA : 0x00964D88
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::ClearWorld(idRenderWorldLocal *this)
{
  _DWORD *v2; // r3
  worldArea_t *v3; // r26
  worldArea_t *v4; // r11
  int *v5; // r3
  areaNode_t *areaNodes; // r9
  float *areaNodeBounds; // r4
  int v8; // r10
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // [sp+8h] [-98h]
  int v13; // [sp+Ch] [-94h]
  int v14; // [sp+10h] [-90h]
  int v15; // [sp+14h] [-8Ch]
  int v16; // [sp+18h] [-88h]
  int v17; // [sp+1Ch] [-84h]
  int v18; // [sp+20h] [-80h]
  bool v19; // [sp+27h] [-79h]

  this->numWorldAreas = 1;
  v2 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
         size: 0x4Cu,
         tag: TAG_RENDERWORLD,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
  {
    *v2 = 1;
    v3 = (worldArea_t *)(v2 + 1);
    `eh vector constructor iterator'(
      ptr: v2 + 1,
      size: 0x48u,
      count: 1,
      pCtor: (void (__fastcall *)(void *))worldArea_t::worldArea_t,
      pDtor: (void (__fastcall *)(void *))idSurface::~idSurface);
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  this->worldAreas = v4;
  v4->areaNum = 0;
  this->worldAreas->firstSurfaceInWorldModel = 0;
  this->worldAreaSubspaceBounds = (idBounds *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(247) : TAG_RENDERWORLD",
                                                size: 0x18u,
                                                tag: TAG_RENDERWORLD,
                                                zeroBuffer: false,
                                                align: ALIGN_128,
                                                heap: HEAP_DEFAULTHEAP);
  this->worldAreaGeometryBounds = (idBounds *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(248) : TAG_RENDERWORLD",
                                                size: 0x18u,
                                                tag: TAG_RENDERWORLD,
                                                zeroBuffer: false,
                                                align: ALIGN_128,
                                                heap: HEAP_DEFAULTHEAP);
  *this->worldAreaSubspaceBounds = maxWorldBounds;
  *this->worldAreaGeometryBounds = maxWorldBounds;
  this->areaNodes = (areaNode_t *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                    size: 0x18u,
                                    tag: TAG_RENDERWORLD,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  this->areaNodeBounds = (idBounds *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(255) : TAG_RENDERWORLD",
                                       size: 0x18u,
                                       tag: TAG_RENDERWORLD,
                                       zeroBuffer: false,
                                       align: ALIGN_128,
                                       heap: HEAP_DEFAULTHEAP);
  v5 = (int *)idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(256) : TAG_RENDERWORLD",
                size: 4u,
                tag: TAG_RENDERWORLD,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
  areaNodes = this->areaNodes;
  this->areaNodeOcclusionIndex = v5;
  areaNodes->plane.d = 131072.0;
  areaNodes->plane.a = 0.0;
  areaNodes->plane.b = 0.0;
  areaNodes->plane.c = 1.0;
  this->areaNodes->children[0] = -1;
  this->areaNodes->children[1] = 0;
  areaNodeBounds = (float *)this->areaNodeBounds;
  areaNodeBounds[1] = 0.0;
  areaNodeBounds[5] = 0.0;
  areaNodeBounds[4] = 0.0;
  areaNodeBounds[3] = 0.0;
  areaNodeBounds[2] = 0.0;
  *areaNodeBounds = 0.0;
  *this->areaNodeOcclusionIndex = -1;
  this->skyModel = nullptr;
  if ( this->binaryModelNames.size < 0 )
    idList<idStr,99>::~idList<idStr,99>(this: &this->binaryModelNames);
  this->binaryModelNames.num = __CFADD__(-this->binaryModelNames.size, this->binaryModelNames.size ^ 0x80000000)
                             ? 0
                             : this->binaryModelNames.size;
  if ( this->binaryModelState.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->binaryModelState);
  this->binaryModelState.num = __CFADD__(-this->binaryModelState.size, this->binaryModelState.size ^ 0x80000000)
                             ? 0
                             : this->binaryModelState.size;
  idHashIndex::Clear(this: &this->binaryModelHash);
  idRenderWorldLocal::SetBinaryModelState_Internal(
    this,
    binaryModelName: "world",
    isVisible: true,
    makingDefinition: true,
    a5: v11,
    a6: v10,
    a7: v9,
    a8: v8,
    a9: v12,
    a10: v13,
    a11: v14,
    a12: v15,
    a13: v16,
    a14: v17,
    a15: v18,
    a16: v19);
}


// ========================================================================
// __unwind$235404
// EA  : 0x82965078
// RVA : 0x00965078
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_235404()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_RENDERWORLD);
}


// ========================================================================
// ?ParseAreas@idRenderWorldLocal@@QAAXPAVidLexer@@@Z
// EA  : 0x829650B0
// RVA : 0x009650B0
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::ParseAreas(idRenderWorldLocal *this, idLexer *src)
{
  int v4; // r3
  int v5; // r28
  unsigned int v6; // r5
  int *v7; // r3
  worldArea_t *v8; // r27
  worldArea_t *v9; // r9
  idBounds *v10; // r3
  int numWorldAreas; // r10
  int v12; // r26
  int v13; // r27
  int v14; // r3
  int v15; // r29
  idList<idRenderModelSurface,85> *v16; // r11
  idList<idRenderModelSurface,85> *v17; // r28
  int size; // r11

  this->hasWorldSurfaceOffsets = true;
  idLexer::ExpectTokenString(this: src, string: "{");
  v4 = idLexer::ParseInt(this: src);
  v5 = v4;
  this->numWorldAreas = v4;
  if ( v4 >= 0 )
  {
    if ( v4 <= 0x2000 )
    {
      v6 = 72 * v4 + 4;
      if ( (unsigned int)(72 * v4) > 0xFFFFFFFB )
        v6 = -1;
      v7 = (int *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                    size: v6,
                    tag: TAG_RENDERWORLD,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
      {
        *v7 = v5;
        v8 = (worldArea_t *)(v7 + 1);
        `eh vector constructor iterator'(
          ptr: v7 + 1,
          size: 0x48u,
          count: v5,
          pCtor: (void (__fastcall *)(void *))worldArea_t::worldArea_t,
          pDtor: (void (__fastcall *)(void *))idSurface::~idSurface);
        v9 = v8;
      }
      else
      {
        v9 = nullptr;
      }
      this->worldAreas = v9;
      this->worldAreaSubspaceBounds = (idBounds *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(78) : TAG_RENDERWORLD",
                                                    size: 24 * this->numWorldAreas,
                                                    tag: TAG_RENDERWORLD,
                                                    zeroBuffer: false,
                                                    align: ALIGN_128,
                                                    heap: HEAP_DEFAULTHEAP);
      v10 = (idBounds *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\engine\\renderer\\RenderWorld_load.cpp(79) : TAG_RENDERWORLD",
                          size: 24 * this->numWorldAreas,
                          tag: TAG_RENDERWORLD,
                          zeroBuffer: false,
                          align: ALIGN_128,
                          heap: HEAP_DEFAULTHEAP);
      numWorldAreas = this->numWorldAreas;
      this->worldAreaGeometryBounds = v10;
      v12 = 0;
      if ( numWorldAreas > 0 )
      {
        v13 = 0;
        do
        {
          this->worldAreas[v13].firstSurfaceInWorldModel = idLexer::ParseInt(this: src);
          v14 = idLexer::ParseInt(this: src);
          v15 = v14;
          v16 = (idList<idRenderModelSurface,85> *)&this->worldAreas[v13];
          v17 = v16 + 3;
          if ( v14 <= v16[3].size
            || (unsigned __int8)idList<idRenderModelSurface,85>::Resize(this: v16 + 3, newsize: v14) != 0 )
          {
            size = v17->size;
            if ( v15 < size )
              size = v15;
            v17->num = size;
          }
          ++v12;
          ++v13;
        }
        while ( v12 < this->numWorldAreas );
      }
      idLexer::ExpectTokenString(this: src, string: "}");
    }
    else
    {
      idLexer::Error(this: src, str: "idRenderWorldLocal::ParseAreas: more than %d world areas", 0x2000);
    }
  }
  else
  {
    idLexer::Error(this: src, str: "idRenderWorldLocal::ParseAreas: bad numWorldAreas");
  }
}


// ========================================================================
// __unwind$236148
// EA  : 0x829652D4
// RVA : 0x009652D4
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236148()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_RENDERWORLD);
}


// ========================================================================
// ?ParseProc@idRenderWorldLocal@@QAA_NPBD@Z
// EA  : 0x82965308
// RVA : 0x00965308
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

int __fastcall idRenderWorldLocal::ParseProc(idRenderWorldLocal *this, const char *fileName)
{
  idLexer *v4; // r3
  idLexer *v5; // r30
  int v7; // r3
  int i; // r29
  bool v9; // r3
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // [sp+8h] [-128h]
  int v15; // [sp+Ch] [-124h]
  int v16; // [sp+10h] [-120h]
  int v17; // [sp+14h] [-11Ch]
  int v18; // [sp+18h] [-118h]
  int v19; // [sp+1Ch] [-114h]
  int v20; // [sp+20h] [-110h]
  bool v21; // [sp+27h] [-109h]
  idStr v22; // [sp+60h] [-D0h] BYREF
  idToken v23[2]; // [sp+80h] [-B0h] BYREF

  this->hasWorldSurfaceOffsets = false;
  v4 = (idLexer *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x88u,
                    tag: TAG_LEXER,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idLexer::idLexer(this: v4, flags_: 80);
  else
    v5 = nullptr;
  if ( idLexer::LoadFile(this: v5, filename_: fileName, OSPath: false) )
  {
    v23[0].len = 0;
    v23[0].baseBuffer[0] = 0;
    v23[0].intvalue = 0;
    v23[0].allocedAndFlag = 20;
    v23[0].data = v23[0].baseBuffer;
    v23[0].whiteSpaceStart_p = nullptr;
    v23[0].floatvalue = -3.4028235e38;
    v23[0].whiteSpaceEnd_p = nullptr;
    v23[0].next = nullptr;
    if ( idLexer::ReadToken(this: v5, token: v23) )
    {
      if ( idStr::Icmp(s1: v23[0].data, s2: "mapProcFile006") != 0
        && idStr::Icmp(s1: v23[0].data, s2: "mapProcFile005") != 0 )
      {
        idLib::Warning(
          fmt: "idRenderWorldLocal::InitFromMap: bad id '%s' instead of '%s'",
          v23[0].data,
          "mapProcFile006");
      }
      else
      {
        while ( idLexer::ReadToken(this: v5, token: v23) )
        {
          if ( idStr::Cmp(s1: v23[0].data, s2: "interAreaPortals") != 0 )
          {
            if ( idStr::Cmp(s1: v23[0].data, s2: "areas") != 0 )
            {
              if ( idStr::Cmp(s1: v23[0].data, s2: "nodes") != 0 )
              {
                if ( idStr::Cmp(s1: v23[0].data, s2: "binaryModels") != 0 )
                {
                  idLexer::Error(this: v5, str: "idRenderWorldLocal::InitFromMap: bad token \"%s\"", v23[0].data);
                }
                else
                {
                  idLexer::ExpectTokenString(this: v5, string: "{");
                  v7 = idLexer::ParseInt(this: v5);
                  if ( v7 > 0 )
                  {
                    for ( i = v7; i != 0; --i )
                    {
                      idLexer::ReadToken(this: v5, token: v23);
                      idStr::idStr(this: &v22, text: v23[0].data);
                      v9 = idLexer::ParseBool(this: v5);
                      idRenderWorldLocal::SetBinaryModelState_Internal(
                        this,
                        binaryModelName: v23[0].data,
                        isVisible: v9,
                        makingDefinition: true,
                        a5: v13,
                        a6: v12,
                        a7: v11,
                        a8: v10,
                        a9: v14,
                        a10: v15,
                        a11: v16,
                        a12: v17,
                        a13: v18,
                        a14: v19,
                        a15: v20,
                        a16: v21);
                      idStr::FreeData(this: &v22);
                    }
                  }
                  idLexer::ExpectTokenString(this: v5, string: "}");
                }
              }
              else
              {
                idRenderWorldLocal::ParseNodes(this, src: v5);
              }
            }
            else
            {
              idRenderWorldLocal::ParseAreas(this, src: v5);
            }
          }
          else
          {
            idRenderWorldLocal::ParseInterAreaPortals(this, src: v5);
          }
        }
      }
    }
    else
    {
      idLib::Warning(fmt: "idRenderWorldLocal::InitFromMap: couldn't read proc file id");
    }
    if ( v5 != nullptr )
    {
      idLexer::~idLexer(this: v5);
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    }
    idStr::FreeData(this: &v23[0]);
    return 1;
  }
  else
  {
    idLib::Printf(fmt: "idRenderWorldLocal::InitFromMap: %s not found\n", fileName);
    idRenderWorldLocal::ClearWorld(this);
    return 0;
  }
}


// ========================================================================
// __unwind$236199
// EA  : 0x829655F4
// RVA : 0x009655F4
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236199()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 304 + 80), tag: TAG_LEXER);
}


// ========================================================================
// __unwind$236200
// EA  : 0x82965620
// RVA : 0x00965620
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236200()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 128));
}


// ========================================================================
// __unwind$236201_0
// EA  : 0x82965648
// RVA : 0x00965648
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236201_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 96));
}


// ========================================================================
// ?InitFromMap@idRenderWorldLocal@@UAA_NPBD_N@Z
// EA  : 0x82965678
// RVA : 0x00965678
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

int __fastcall idRenderWorldLocal::InitFromMap(idRenderWorldLocal *this, const char *name, bool comboMap)
{
  idRenderWorldLocal_vtbl *v6; // r11
  idRenderModelTransparency *v7; // r3
  idRenderModelDecal *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  BOOL v11; // r20
  const char *v12; // r4
  va *v13; // r3
  __int64 v15; // r10
  int v16; // r7
  __int64 v17; // r6
  idStr *MapModelName; // r3
  idStr *v19; // r3
  idStr *v20; // r3
  bool v21; // r30
  idStaticModel *v22; // r3
  idStaticModel *v23; // r3
  idStaticModel *v24; // r26
  __int64 v25; // r10
  __int64 v26; // r8
  __int64 v27; // r6
  int v28; // r25
  int v29; // r24
  __int64 v30; // r6
  __int64 v31; // r10
  int v32; // r7
  idStr *v33; // r3
  idStr *v34; // r3
  __int64 v35; // r6
  __int64 v36; // r10
  int v37; // r7
  idStr *v38; // r3
  idResource *v39; // r3
  idResource *v40; // r30
  idList<idRenderModelSurface,85> *v41; // r27
  int v42; // r28
  int v43; // r27
  int v44; // r4
  int v45; // r3
  int v46; // r9
  worldArea_t *v47; // r10
  __int64 v48; // r6
  char *v49; // r6
  int v50; // ctr
  int *p_size; // r11
  double v52; // fp0
  double v53; // fp13
  int v54; // r11
  int v55; // r7
  double v56; // fp12
  int v57; // r30
  double v58; // fp11
  char v59; // r28
  int v60; // r27
  int v61; // r25
  int v62; // r24
  int v63; // r23
  __int64 v64; // r10
  int v65; // r7
  __int64 v66; // r6
  idRenderModel *v67; // r3
  idRenderModel *v68; // r3
  int v69; // [sp+8h] [-1268h]
  __int64 v70; // [sp+8h] [-1268h]
  __int64 v71; // [sp+8h] [-1268h]
  __int64 v72; // [sp+8h] [-1268h]
  __int64 v73; // [sp+8h] [-1268h]
  int v74; // [sp+Ch] [-1264h]
  int v75; // [sp+10h] [-1260h]
  int v76; // [sp+10h] [-1260h]
  int v77; // [sp+14h] [-125Ch]
  int v78; // [sp+14h] [-125Ch]
  int v79; // [sp+18h] [-1258h]
  int v80; // [sp+18h] [-1258h]
  int v81; // [sp+1Ch] [-1254h]
  int v82; // [sp+1Ch] [-1254h]
  idStr v83; // [sp+60h] [-1210h] BYREF
  idStr v84; // [sp+80h] [-11F0h] BYREF
  idStr v85; // [sp+A0h] [-11D0h] BYREF
  int v86; // [sp+C0h] [-11B0h]
  int v87; // [sp+C4h] [-11ACh]
  int v88; // [sp+C8h] [-11A8h]
  int v89; // [sp+CCh] [-11A4h]
  int v90; // [sp+D0h] [-11A0h]
  char v91; // [sp+D5h] [-119Bh]
  int v92; // [sp+D8h] [-1198h]
  int v93; // [sp+DCh] [-1194h]
  int v94; // [sp+E0h] [-1190h]
  int v95; // [sp+E4h] [-118Ch]
  float v96; // [sp+E8h] [-1188h]
  float v97; // [sp+ECh] [-1184h]
  float v98; // [sp+F0h] [-1180h]
  float v99; // [sp+F4h] [-117Ch]
  idStr v100; // [sp+100h] [-1170h] BYREF
  idStr v101; // [sp+120h] [-1150h] BYREF
  idStr v102; // [sp+140h] [-1130h] BYREF
  idStr v103; // [sp+160h] [-1110h] BYREF
  idStr v104; // [sp+180h] [-10F0h] BYREF
  idStr v105; // [sp+1A0h] [-10D0h] BYREF
  idStr v106; // [sp+1C0h] [-10B0h] BYREF
  va v107; // [sp+1E0h] [-1090h] BYREF

  if ( this->everInitialized )
    idLib::FatalError(fmt: "idRenderWorldLocal::InitFromMap: everInitialized was set");
  v6 = this->__vftable;
  this->everInitialized = true;
  v7 = (idRenderModelTransparency *)v6->AllocRenderModel(this, a2: "_transparency", a3: true, a4: -1);
  this->transparencyRenderModel = v7;
  idRenderModel::CommitThisFrame(this: v7);
  v8 = (idRenderModelDecal *)this->AllocRenderModel(this, a2: "_decal", a3: 1, a4: -1);
  this->decalRenderModel = v8;
  idRenderModel::CommitThisFrame(this: v8);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->megaTextures);
  if ( name != nullptr && *name != 0 )
  {
    idStr::idStr(this: &v100, text: name);
    idStr::StripPath(this: &v100);
    v84.len = 0;
    v84.allocedAndFlag = 20;
    v84.data = v84.baseBuffer;
    v84.baseBuffer[0] = 0;
    v11 = comboMap;
    if ( comboMap )
      v12 = "%s/_combo/%s";
    else
      v12 = "%s/%s";
    v13 = va::va(
            this: &v107,
            fmt: v12,
            a3: __SPAIR64__((unsigned int)name, (unsigned int)v100.data),
            a4: v10,
            a5: v9,
            a6: v69,
            a7: v74,
            a8: v75,
            a9: v77,
            a10: v79,
            a11: v81);
    idStr::operator=(this: &v84, text: v13);
    idStr::SetFileExtension(this: &v84, extension: "proc");
    if ( (unsigned __int8)idRenderWorldLocal::ParseProc(this, fileName: v84.data) == 0 )
    {
      idStr::FreeData(this: &v84);
      idStr::FreeData(this: &v100);
      return 0;
    }
    this->isComboMap = comboMap;
    idStr::operator=(this: &this->mapName, text: name);
    idStr::StripFileExtension(this: &this->mapName);
    if ( this->numWorldAreas == 0 )
      idRenderWorldLocal::ClearWorld(this);
    v83.allocedAndFlag = 20;
    v83.len = 0;
    v83.data = v83.baseBuffer;
    v83.baseBuffer[0] = 0;
    if ( comboMap )
    {
      HIDWORD(v17) = "_combo/_world.bmodel";
      MapModelName = idMapFile::GetMapModelName(result: &v106, entityName: v17, a3: v16, a4: v15, a5: v70);
      idStr::operator=(this: &v83, text: MapModelName);
      v19 = &v106;
    }
    else
    {
      HIDWORD(v17) = "_world.bmodel";
      v20 = idMapFile::GetMapModelName(result: &v105, entityName: v17, a3: v16, a4: v15, a5: v70);
      idStr::operator=(this: &v83, text: v20);
      v19 = &v105;
    }
    idStr::FreeData(this: v19);
    resourceManager->SetFileHook(this: resourceManager);
    v21 = fileSystem->FileExists(this: fileSystem, a2: v83.data, a3: true);
    resourceManager->ReleaseFileHook(this: resourceManager);
    if ( this->hasWorldSurfaceOffsets && v21 )
    {
      v22 = (idStaticModel *)idResourceList::Load(
                               this: &idStaticModel::resourceList,
                               name: v83.data,
                               makeDefault: false,
                               skipStaleCheck: false);
      this->worldStaticModel = v22;
      if ( v22 != nullptr )
        goto LABEL_33;
      idLib::Error(fmt: "InitFromMap: bad area model '%s'. Try re-compiling the map.", v83.data);
    }
    v23 = (idStaticModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0x194u,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
    if ( v23 != nullptr )
      v24 = idStaticModel::idStaticModel(this: v23);
    else
      v24 = nullptr;
    idResource::SetName(this: v24, _name: v83.data);
    v28 = 0;
    if ( this->numWorldAreas > 0 )
    {
      LODWORD(v25) = &simplex_0[0][20];
      v29 = 0;
      while ( 1 )
      {
        v85.allocedAndFlag = 20;
        v85.len = 0;
        v85.data = v85.baseBuffer;
        v85.baseBuffer[0] = 0;
        HIDWORD(v27) = v28;
        if ( v11 )
        {
          HIDWORD(v30) = va::va(
                           this: &v107,
                           fmt: "_combo/_area%i.bmodel",
                           a3: v27,
                           a4: v26,
                           a5: v25,
                           a6: SHIDWORD(v71),
                           a7: v71,
                           a8: v76,
                           a9: v78,
                           a10: v80,
                           a11: v82);
          v33 = idMapFile::GetMapModelName(result: &v103, entityName: v30, a3: v32, a4: v31, a5: v72);
          idStr::operator=(this: &v85, text: v33);
          v34 = &v103;
        }
        else
        {
          HIDWORD(v35) = va::va(
                           this: &v107,
                           fmt: "_area%i.bmodel",
                           a3: v27,
                           a4: v26,
                           a5: v25,
                           a6: SHIDWORD(v71),
                           a7: v71,
                           a8: v76,
                           a9: v78,
                           a10: v80,
                           a11: v82);
          v38 = idMapFile::GetMapModelName(result: &v104, entityName: v35, a3: v37, a4: v36, a5: v73);
          idStr::operator=(this: &v85, text: v38);
          v34 = &v104;
        }
        idStr::FreeData(this: v34);
        v39 = idResourceList::Load(
                this: &idStaticModel::resourceList,
                name: v85.data,
                makeDefault: false,
                skipStaleCheck: false);
        v40 = v39;
        if ( v39 == nullptr )
          break;
        v41 = (idList<idRenderModelSurface,85> *)&this->worldAreas[v29];
        idList<idRenderModelSurface,62>::SetNum(this: v41 + 3, newNum: (int)v39[10].__vftable);
        v42 = 0;
        v41[4].num = v24->surfaces.num;
        if ( (int)v40[10].__vftable > 0 )
        {
          v43 = 0;
          do
          {
            idStaticModel::AddSurface(this: v24, surf: (const idStaticModelSurface *)(*((_DWORD *)&v40[9] + 8) + v43));
            ++v42;
            v43 += 72;
          }
          while ( v42 < (int)v40[10].__vftable );
        }
        HIBYTE(v40[9].networkID) = 1;
        ((void (__fastcall *)(idResource *, int))v40->dtr_idResource)(a1: v40, a2: 1);
        idStr::FreeData(this: &v85);
        HIDWORD(v25) = this->numWorldAreas;
        ++v28;
        ++v29;
        if ( v28 >= SHIDWORD(v25) )
          goto LABEL_32;
      }
      idLib::Error(fmt: "InitFromMap: bad area model '%s'.  Try re-compiling the map.", v85.data);
      goto _LN269;
    }
LABEL_32:
    idStaticModel::FinishStaticModel(this: v24, cleanup: false);
    idResourceList::Add(this: &idStaticModel::resourceList, ptr: (idResourceList_vtbl *)v24);
    this->worldStaticModel = v24;
LABEL_33:
    v44 = 0;
    if ( this->numWorldAreas > 0 )
    {
      v45 = 0;
      do
      {
        v46 = 0;
        v47 = &this->worldAreas[v45];
        if ( v47->worldSurfaces.num > 0 )
        {
          HIDWORD(v48) = 0;
          do
          {
            v49 = &v85.baseBuffer[12];
            v50 = 7;
            p_size = &this->worldStaticModel->surfaces.list[v46 - 1 + v47->firstSurfaceInWorldModel].skinRemaps.size;
            do
            {
              p_size += 2;
              v49 += 8;
              *(_QWORD *)v49 = *(_QWORD *)p_size;
              --v50;
            }
            while ( v50 != 0 );
            v52 = v96;
            v53 = v97;
            v54 = (int)v47->worldSurfaces.list + HIDWORD(v48);
            v55 = v87;
            LODWORD(v48) = v89;
            v56 = v98;
            v57 = v90;
            v58 = v99;
            v59 = v91;
            v60 = v92;
            ++v46;
            v61 = v93;
            HIDWORD(v48) = v88 + 56;
            v62 = v94;
            v63 = v95;
            *(_DWORD *)v54 = v86;
            *(_DWORD *)(v54 + 4) = v55;
            *(_QWORD *)(v54 + 8) = v48;
            *(_DWORD *)(v54 + 16) = v57;
            *(_BYTE *)(v54 + 20) = 1;
            *(_BYTE *)(v54 + 21) = v59;
            *(_DWORD *)(v54 + 24) = v60;
            *(_DWORD *)(v54 + 28) = v61;
            *(_DWORD *)(v54 + 32) = v62;
            *(_DWORD *)(v54 + 36) = v63;
            *(float *)(v54 + 40) = v52;
            *(float *)(v54 + 44) = v53;
            *(float *)(v54 + 48) = v56;
            *(float *)(v54 + 52) = v58;
            v47->areaNum = v44;
          }
          while ( v46 < v47->worldSurfaces.num );
        }
        ++v44;
        ++v45;
      }
      while ( v44 < this->numWorldAreas );
    }
    HIDWORD(v64) = ((unsigned __int8 (__fastcall *)(idRenderWorldLocal *, int))this->IsComboMap)(a1: this, a2: v44);
    if ( HIDWORD(v64) != 0 )
    {
      HIDWORD(v66) = "_combo/sky.bmodel";
_M236714:
      idMapFile::GetMapModelName(result: &v101, entityName: v66, a3: v65, a4: v64, a5: v71);
      v67 = this->AllocRenderModel(this, a2: v101.data, a3: 0, a4: -1);
      this->skyModel = v67;
      if ( v67 != nullptr )
      {
        *((_BYTE *)&v67->g + 104) |= 0x20u;
        *((_BYTE *)&this->skyModel->g + 104) |= 8u;
        idRenderModel::CommitThisFrame(this: this->skyModel);
        *((_BYTE *)&this->skyModel->g + 105) |= 4u;
      }
      operator+(result: &v102, a: &this->mapName, b: "_occlusion.bmodel");
      v68 = this->AllocRenderModel(this, a2: v102.data, a3: 0, a4: -1);
      this->occlusionBaseModel = v68;
      if ( v68 != nullptr )
        v68->CommitSubclass(this: v68);
      idGlobalShadows::LoadGlobalShadows(this: &this->globalShadows, rw: this);
      idAmbientLighting::LoadAmbientLighting(this: &this->ambientLighting, rw: this);
      idFoliageModel::LoadFoliageForWorld(rw: this);
      idStr::FreeData(this: &v102);
      idStr::FreeData(this: &v101);
      idStr::FreeData(this: &v83);
      idStr::FreeData(this: &v84);
      idStr::FreeData(this: &v100);
      return 1;
    }
_LN269:
    HIDWORD(v66) = "sky.bmodel";
    goto _M236714;
  }
  idStr::operator=(this: &this->mapName, text: &byte_8200D768);
  idRenderWorldLocal::ClearWorld(this);
  return 1;
}


// ========================================================================
// $LN206
// EA  : 0x82965D88
// RVA : 0x00965D88
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _LN206()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 256));
}


// ========================================================================
// __unwind$236353
// EA  : 0x82965DB0
// RVA : 0x00965DB0
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236353()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 128));
}


// ========================================================================
// __unwind$236354
// EA  : 0x82965DD8
// RVA : 0x00965DD8
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236354()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 96));
}


// ========================================================================
// __unwind$236355
// EA  : 0x82965E00
// RVA : 0x00965E00
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236355()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 448));
}


// ========================================================================
// __unwind$236356
// EA  : 0x82965E28
// RVA : 0x00965E28
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236356()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 416));
}


// ========================================================================
// __unwind$236357
// EA  : 0x82965E50
// RVA : 0x00965E50
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void __fastcall _unwind_236357(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 4720 + 80), tag: a2);
}


// ========================================================================
// __unwind$236358
// EA  : 0x82965E78
// RVA : 0x00965E78
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236358()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 160));
}


// ========================================================================
// __unwind$236359
// EA  : 0x82965EA0
// RVA : 0x00965EA0
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236359()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 352));
}


// ========================================================================
// __unwind$236360
// EA  : 0x82965EC8
// RVA : 0x00965EC8
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236360()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 384));
}


// ========================================================================
// __unwind$236361
// EA  : 0x82965EF0
// RVA : 0x00965EF0
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236361()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 288));
}


// ========================================================================
// __unwind$236362
// EA  : 0x82965F18
// RVA : 0x00965F18
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236362()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 320));
}


// ========================================================================
// ?SpecificationComplete@idRenderWorldLocal@@UAAX_N@Z
// EA  : 0x82965F48
// RVA : 0x00965F48
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::SpecificationComplete(idRenderWorldLocal *this, bool preloadPageFileCache)
{
  worldArea_t *worldAreas; // r5
  int v11; // r10
  int numWorldAreas; // ctr
  int v13; // r9
  int v14; // r11
  worldArea_t *v15; // r8
  idRenderModelSurface *list; // r7
  idRenderModelSurface *v17; // r7
  float *geometry; // r7
  float *skyModel; // r11
  double v38; // fp10
  double v39; // fp9
  double v40; // fp13
  int v41; // r12
  double v42; // fp0
  double v43; // fp12
  double v44; // fp11
  idBounds *areaNodeBounds; // r11
  idBounds *worldAreaSubspaceBounds; // r11
  idBounds *worldAreaGeometryBounds; // r11
  const idDeclEnv *v48; // r5
  int v49; // r11
  int v50; // r10
  int v51; // r30
  int size; // r11
  int v53; // r11
  int v54; // r10
  int v55; // r30
  int v56; // r11
  int len; // r30
  char *v58; // r10
  char *v59; // r9
  char v60; // r11
  float *p_megaTextures; // r25
  idVirtualTexture **v62; // r4
  int v63; // r26
  int v64; // r28
  int v65; // r27
  int v66; // r29
  idRenderModelSurface *v67; // r11
  idMaterial *material; // r30
  int pageSource; // r11
  int num; // r8
  int v71; // r10
  idVirtualTexture *v72; // r9
  int v73; // r11
  int v74; // r29
  int v75; // r30
  int v76; // r26
  int v77; // r27
  idRenderModel *v78; // r29
  int v79; // r28
  int v80; // r30
  idRenderModelSurface *v81; // r11
  idTriangles *v82; // r10
  const idMaterial *v83; // r11
  float v84; // r11
  int v85; // r8
  int v86; // r10
  idVirtualTexture *v87; // r9
  int v88; // r11
  int v89; // r29
  int *p_num; // r26
  int v91; // r28
  float v92; // r30
  const char *v93; // r3
  int v94; // r30
  void *v95; // r3
  _DWORD back_chain[20]; // [sp+0h] [-200h]
  idPlane v97; // [sp+50h] [-1B0h] BYREF
  idList<idVehicleState *,5> v98; // [sp+60h] [-1A0h] BYREF
  idStr v99; // [sp+70h] [-190h] BYREF
  idStr v100; // [sp+90h] [-170h] BYREF
  idStr v101; // [sp+B0h] [-150h] BYREF
  char v102; // [sp+D0h] [-130h] BYREF
  int v103; // [sp+150h] [-B0h] BYREF

  idLib::Printf(fmt: "---------- idRenderWorldLocal::SpecificationComplete ----------\n");
  if ( this->numAreaNodes <= 0 )
  {
    areaNodeBounds = this->areaNodeBounds;
    LODWORD(v97.a) = &areaNodeBounds->b[1];
    *areaNodeBounds = maxWorldBounds;
    if ( this->numWorldAreas > 0 )
    {
      worldAreaSubspaceBounds = this->worldAreaSubspaceBounds;
      LODWORD(v97.a) = &worldAreaSubspaceBounds->b[1];
      *worldAreaSubspaceBounds = maxWorldBounds;
      worldAreaGeometryBounds = this->worldAreaGeometryBounds;
      worldAreaGeometryBounds->b[0].x = maxWorldBounds.b[0].x;
      LODWORD(v97.a) = &worldAreaGeometryBounds->b[1];
      worldAreaGeometryBounds->b[0].y = maxWorldBounds.b[0].y;
      worldAreaGeometryBounds->b[0].z = maxWorldBounds.b[0].z;
      worldAreaGeometryBounds->b[1] = maxWorldBounds.b[1];
    }
  }
  else
  {
    _FP0 = 1.0e30;
    _FP13 = -1.0e30;
    _FP11 = 1.0e30;
    _FP12 = 1.0e30;
    _FP9 = -1.0e30;
    _FP10 = -1.0e30;
    if ( this->numWorldAreas > 0 )
    {
      worldAreas = this->worldAreas;
      numWorldAreas = this->numWorldAreas;
      v11 = 0;
      do
      {
        v13 = 0;
        if ( worldAreas[v11].worldSurfaces.num > 0 )
        {
          v14 = 0;
          v15 = &worldAreas[v11];
          do
          {
            list = v15->worldSurfaces.list;
            ++v13;
            v15 = &worldAreas[v11];
            v17 = &list[v14++];
            geometry = (float *)v17->geometry;
            _FP6 = (float)((float)_FP0 - *geometry);
            _FP4 = (float)((float)_FP12 - geometry[1]);
            _FP2 = (float)((float)_FP11 - geometry[2]);
            _FP31 = (float)(geometry[3] - (float)_FP13);
            _FP29 = (float)(geometry[4] - (float)_FP10);
            _FP28 = (float)(geometry[5] - (float)_FP9);
            __asm
            {
              fsel      f0, f6, f8, f0
              fsel      f12, f4, f7, f12
              fsel      f11, f2, f5, f11
              fsel      f13, f31, f3, f13
              fsel      f10, f29, f1, f10
              fsel      f9, f28, f30, f9
            }
          }
          while ( v13 < this->worldAreas[v11].worldSurfaces.num );
        }
        ++v11;
        --numWorldAreas;
      }
      while ( numWorldAreas != 0 );
    }
    skyModel = (float *)this->skyModel;
    if ( skyModel != nullptr )
    {
      _FP6 = (float)((float)_FP0 - skyModel[23]);
      _FP4 = (float)((float)_FP12 - skyModel[24]);
      _FP2 = (float)((float)_FP11 - skyModel[25]);
      _FP31 = (float)(skyModel[26] - (float)_FP13);
      _FP29 = (float)(skyModel[27] - (float)_FP10);
      _FP28 = (float)(skyModel[28] - (float)_FP9);
      LODWORD(v97.b) = skyModel + 23;
      __asm
      {
        fsel      f0, f6, f8, f0
        fsel      f12, f4, f7, f12
        fsel      f11, f2, f5, f11
        fsel      f13, f31, f3, f13
        fsel      f10, f29, f1, f10
        fsel      f9, f28, f30, f9
      }
    }
    ((void (*)(void))RtlCheckStack12)();
    *(_DWORD *)((char *)back_chain + v41) = back_chain[0];
    v97.b = 0.0;
    v97.c = 0.0;
    v97.d = v42;
    *(float *)&v98.list = 1.0;
    *(float *)&v98.num = 0.0;
    LODWORD(v97.a) = &v100.baseBuffer[4];
    *(float *)&v98.size = 0.0;
    *(float *)&v98.granularity = -v40;
    *(float *)&v99.len = 0.0;
    *(float *)&v99.data = -1.0;
    *(float *)&v99.allocedAndFlag = 0.0;
    *(float *)v99.baseBuffer = v43;
    *(float *)&v99.baseBuffer[4] = 0.0;
    *(float *)&v99.baseBuffer[8] = 1.0;
    *(float *)&v99.baseBuffer[12] = 0.0;
    *(float *)&v99.baseBuffer[16] = -v38;
    *(float *)&v100.len = 0.0;
    *(float *)&v100.data = 0.0;
    *(float *)&v100.allocedAndFlag = -1.0;
    *(float *)v100.baseBuffer = v44;
    *(float *)&v100.baseBuffer[4] = 0.0;
    *(float *)&v100.baseBuffer[8] = 0.0;
    *(float *)&v100.baseBuffer[12] = 1.0;
    *(float *)&v100.baseBuffer[16] = -v39;
    idRenderWorldLocal::BuildNodeBounds_r(
      this: (idRenderWorldLocal *)&v103,
      result: (idBounds *)this,
      nodeNum: 0,
      planes: &v97,
      numPlanes: 6);
    v97.b = 0.0;
    idRenderWorldLocal::AssignNodeOcclusionIndices_r(this, nodeNum: 0, depth: 0, numOcclusionIndices: (int *)&v97.b);
  }
  if ( this->dynamicEnvironments.num == 0 )
  {
    v48 = (const idDeclEnv *)idDeclInfo::FindWithInheritance(
                               this: &idDeclEnv::resourceList,
                               name: "default",
                               makeDefault: false);
    if ( v48 == nullptr )
      idLib::Error(fmt: "Invalid or missing environment decl 'default' !");
    this->AddEnvironment(this, a2: &maxWorldBounds, a3: v48);
  }
  v49 = this->renderModels.num - 1;
  if ( v49 >= 0 )
  {
    v50 = v49;
    do
    {
      if ( this->renderModels.list[v50] != nullptr )
        break;
      --v49;
      --v50;
    }
    while ( v49 >= 0 );
  }
  v51 = v49 + 1;
  if ( v49 + 1 <= this->renderModels.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->renderModels,
                          newsize: v49 + 1) != 0 )
  {
    size = this->renderModels.size;
    if ( v51 < size )
      size = v51;
    this->renderModels.num = size;
  }
  v53 = this->renderLights.num - 1;
  if ( v53 >= 0 )
  {
    v54 = v53;
    do
    {
      if ( this->renderLights.list[v54] != nullptr )
        break;
      --v53;
      --v54;
    }
    while ( v53 >= 0 );
  }
  v55 = v53 + 1;
  if ( v53 + 1 <= this->renderLights.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->renderLights,
                          newsize: v53 + 1) != 0 )
  {
    v56 = this->renderLights.size;
    if ( v55 < v56 )
      v56 = v55;
    this->renderLights.num = v56;
  }
  len = this->mapName.len;
  v99.len = 0;
  v99.allocedAndFlag = 20;
  v99.data = v99.baseBuffer;
  v99.baseBuffer[0] = 0;
  if ( len + 1 > 20 )
    idStr::ReAllocate(this: &v99, amount: len + 1, keepold: true);
  v58 = this->mapName.data - 1;
  v59 = v99.data - 1;
  do
  {
    v60 = *++v58;
    *++v59 = *v58;
  }
  while ( v60 != 0 );
  v99.len = len;
  idStr::StripPath(this: &v99);
  idStr::StripFileExtension(this: &v99);
  v100.allocedAndFlag = 20;
  v100.data = v100.baseBuffer;
  v100.len = 0;
  v100.baseBuffer[0] = 0;
  idStr::Format(this: &v100, fmt: "%s/%s_container.pages", vt_filePath.valueString.data, v99.data);
  idVirtualTextureSystem::SetContainerPath(this: &virtualTextureSystem, path: v100.data);
  p_megaTextures = (float *)&this->megaTextures;
  if ( this->megaTextures.listStatic == 0 || this->megaTextures.listStatic == 2 )
  {
    v62 = *(idVirtualTexture ***)p_megaTextures;
    if ( *(_DWORD *)p_megaTextures != 0 )
    {
      v97.a = *p_megaTextures;
      idMem::Free(this: &mem, ptr: v62, align: ALIGN_16);
    }
    *p_megaTextures = 0.0;
    this->megaTextures.size = 0;
  }
  this->megaTextures.num = 0;
  v63 = 0;
  if ( this->numWorldAreas > 0 )
  {
    v64 = 0;
    do
    {
      v65 = 0;
      if ( this->worldAreas[v64].worldSurfaces.num > 0 )
      {
        v66 = 0;
        do
        {
          v67 = &this->worldAreas[v64].worldSurfaces.list[v66];
          material = v67->material;
          if ( v67->geometry != nullptr && material != nullptr )
          {
            idMaterial::SetupVirtualTexture(this: v67->material);
            pageSource = material->pageSource;
            if ( pageSource > 1 )
            {
              LODWORD(v97.a) = material->pageSource;
              num = this->megaTextures.num;
              v71 = 0;
              v72 = &virtualTextureSystem.vts[pageSource];
              LODWORD(v97.b) = v72;
              if ( num <= 0 )
                goto LABEL_57;
              v73 = 0;
              while ( *(idVirtualTexture **)(v73 + *(_DWORD *)p_megaTextures) != v72 )
              {
                ++v71;
                v73 += 4;
                if ( v71 >= num )
                  goto LABEL_57;
              }
              if ( v71 < 0 )
LABEL_57:
                idList<idAnimWebBlendTree *,5>::Append(
                  this: (idList<enum encounterGroupRole_t,5> *)&this->megaTextures,
                  obj: (const encounterGroupRole_t *)&v97.b);
            }
          }
          ++v65;
          ++v66;
        }
        while ( v65 < this->worldAreas[v64].worldSurfaces.num );
      }
      ++v63;
      ++v64;
    }
    while ( v63 < this->numWorldAreas );
  }
  *(_WORD *)&v98.memTag = 1280;
  memset(&v98, 0, 14);
  idResourceList::GetLoadedResources(this: &idMaterial::resourceList, resourceList: &v98);
  v74 = 0;
  if ( v98.num > 0 )
  {
    v75 = 0;
    do
    {
      idMaterial::SetupVirtualTexture(this: (idMaterial *)v98.list[v75]);
      ++v74;
      ++v75;
    }
    while ( v74 < v98.num );
  }
  v76 = 0;
  if ( this->renderModels.num > 0 )
  {
    v77 = 0;
    do
    {
      v78 = this->renderModels.list[v77];
      if ( v78 != nullptr )
      {
        v79 = 0;
        if ( v78->surfaces.num > 0 )
        {
          v80 = 0;
          do
          {
            v81 = &v78->surfaces.list[v80];
            v82 = v81->geometry;
            v83 = v81->material;
            if ( v82 != nullptr && v83 != nullptr )
            {
              v84 = *(float *)&v83->pageSource;
              if ( SLODWORD(v84) > 1 )
              {
                v97.a = v84;
                v85 = this->megaTextures.num;
                v86 = 0;
                v87 = &virtualTextureSystem.vts[LODWORD(v84)];
                LODWORD(v97.b) = v87;
                if ( v85 <= 0 )
                  goto LABEL_77;
                v88 = 0;
                while ( *(idVirtualTexture **)(v88 + *(_DWORD *)p_megaTextures) != v87 )
                {
                  ++v86;
                  v88 += 4;
                  if ( v86 >= v85 )
                    goto LABEL_77;
                }
                if ( v86 < 0 )
LABEL_77:
                  idList<idAnimWebBlendTree *,5>::Append(
                    this: (idList<enum encounterGroupRole_t,5> *)&this->megaTextures,
                    obj: (const encounterGroupRole_t *)&v97.b);
              }
            }
            ++v79;
            ++v80;
          }
          while ( v79 < v78->surfaces.num );
        }
      }
      ++v76;
      ++v77;
    }
    while ( v76 < this->renderModels.num );
  }
  idVirtualTextureSystem::SetContainerPath(this: &virtualTextureSystem, path: &byte_8200D768);
  v89 = 0;
  p_num = &this->megaTextures.num;
  if ( this->megaTextures.num > 0 )
  {
    v91 = 0;
    do
    {
      v92 = *p_megaTextures;
      v93 = this->GetName(this);
      v94 = *(_DWORD *)(v91 + LODWORD(v92));
      v101.baseBuffer[0] = 0;
      v102 = 0;
      v101.data = &v102;
      v101.len = 0;
      v101.allocedAndFlag = -2147483520;
      idStr::operator=(this: &v101, text: v93);
      v95 = *(void **)(v94 + 724);
      LODWORD(v97.a) = v94 + 720;
      *(_DWORD *)(v94 + 720) = v101.len;
      memcpy(Dst: v95, Src: v101.data, Size: v101.len + 1);
      idStr::FreeData(this: &v101);
      ++v89;
      v91 += 4;
    }
    while ( v89 < *p_num );
  }
  if ( preloadPageFileCache
    && vt_nopreload.valueInteger == 0
    && renderSystem->GetNumRenderWorlds(this: renderSystem) <= 1 )
  {
    idVirtualTextureSystem::LockPhysicalPages(
      this: &virtualTextureSystem,
      virtualTextures: *(idVirtualTexture ***)p_megaTextures,
      numVirtualTextures: *p_num,
      maxLockedPages: -1);
  }
  this->specificationCompleteHasBeenCalled = true;
  if ( v98.listStatic == 0 || v98.listStatic == 2 )
  {
    if ( v98.list != nullptr )
      idMem::Free(this: &mem, ptr: v98.list, align: ALIGN_16);
    v98.list = nullptr;
    v98.size = 0;
  }
  v98.num = 0;
  idStr::FreeData(this: &v100);
  idStr::FreeData(this: &v99);
}


// ========================================================================
// $LN503
// EA  : 0x8296689C
// RVA : 0x0096689C
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _LN503()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 112));
}


// ========================================================================
// __unwind$236782
// EA  : 0x829668C4
// RVA : 0x009668C4
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236782()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 144));
}


// ========================================================================
// __unwind$236783
// EA  : 0x829668EC
// RVA : 0x009668EC
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_236783()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 512 + 96));
}


// ========================================================================
// __unwind$237585
// EA  : 0x82966914
// RVA : 0x00966914
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

void _unwind_237585()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 176));
}


// ========================================================================
// `dynamic initializer for 'separateDiffuseOnly_v''
// EA  : 0x8335DE38
// RVA : 0x0135DE38
// PDB : w:\tech5\engine\renderer\renderworld_load.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__separateDiffuseOnly_v__()
{
  return idCommandLink::idCommandLink(
           this: &separateDiffuseOnly_v,
           cmdName: "separateDiffuseOnly",
           function: separateDiffuseOnly_f,
           description: "0/1",
           argCompletion: nullptr);
}

