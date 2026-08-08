
// ========================================================================
// AbortSample
// EA  : 0x82986F10
// RVA : 0x00986F10
// PDB : w:\tech5\engine\samples\rendersamples.cpp
// ========================================================================

int __fastcall AbortSample()
{
  int result; // r3
  idSysLocal v1[8]; // [sp+50h] [-90h] BYREF
  float v2[6]; // [sp+70h] [-70h] BYREF
  char v3; // [sp+88h] [-58h]
  bool v4; // [sp+89h] [-57h]
  _BYTE v5[64]; // [sp+90h] [-50h] BYREF

  v2[0] = 0.0;
  v3 = 0;
  v4 = in_invertLook.valueInteger != 0;
  v2[1] = 1.0;
  v2[2] = 1.0;
  v2[3] = joy_pitchSpeed.valueFloat;
  v2[4] = joy_yawSpeed.valueFloat;
  v2[5] = m_sensitivity.valueFloat;
  usercmdGen->GetUsercmd(
    this: (idUsercmdGen *)v5,
    result: (usercmd_t *)usercmdGen,
    a3: 0,
    a4: (const inputSettings_t *)v2,
    a5: false,
    a6: 0);
  sys->GenerateEvents(this: sys);
  sys->GetEvent(this: v1, result: (sysEvent_t *)sys);
  if ( v1[0].__vftable != (idSysLocal_vtbl *)1 )
    return 0;
  result = 1;
  if ( v1[2].__vftable == nullptr )
    return 0;
  return result;
}


// ========================================================================
// ?Sample_GuiModel_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82987020
// RVA : 0x00987020
// PDB : w:\tech5\engine\samples\rendersamples.cpp
// ========================================================================

void __fastcall Sample_GuiModel_f(const idCmdArgs *args)
{
  idRenderModelGui *v1; // r3
  idRenderModelGui *v2; // r30
  char *v3; // r7
  unsigned __int64 v4; // r6
  const idMaterial *v5; // r3
  unsigned __int64 v6; // r10
  const idVec4 *v7; // r5
  const char *v8; // r4
  const idVec4 *v9; // r5
  const char *v10; // r4
  const idVec4 *v11; // r5
  const char *v12; // r4
  idRenderSystem_vtbl *v13; // r19
  int v14; // r18
  int v15; // r17
  void *v16; // r3
  idRenderModelGui *v17; // [sp+70h] [-100h] BYREF
  idVec4 v18; // [sp+80h] [-F0h] BYREF
  idVec4 v19; // [sp+90h] [-E0h] BYREF
  idVec4 v20; // [sp+A0h] [-D0h] BYREF
  idVec4 v21; // [sp+B0h] [-C0h] BYREF

  v1 = (idRenderModelGui *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0xA410u,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v17 = v1;
  if ( v1 != nullptr )
    v2 = idRenderModelGui::idRenderModelGui(this: v1);
  else
    v2 = nullptr;
  v3 = "olor specular";
  LODWORD(v4) = &idDeclReachIK::resourceList.hashTable[243];
  HIDWORD(v4) = &aAvSsobjectVCom[20];
  do
  {
    idRenderModelGui::Clear(
      this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
      a2: defaultExtraGLState,
      bits: v4,
      a4: (int)v3);
    v2->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&idColor::colorWhite);
    v5 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                               this: &idMaterial::resourceList,
                               name: "codeSampleMedia/vehicleVendor",
                               makeDefault: true);
    v18.x = 0.0;
    v18.y = 200.0;
    v18.z = 0.0;
    v18.w = 1.0;
    v19.x = 800.0;
    v19.y = 200.0;
    v19.z = 1.0;
    v19.w = 1.0;
    v20.x = 800.0;
    v20.y = 0.0;
    v20.z = 1.0;
    v20.w = 0.0;
    v21.x = 0.0;
    v21.y = 0.0;
    v21.z = 0.0;
    v21.w = 0.0;
    idRenderModelGui::DrawStretchPic(
      this: v2,
      topLeft: &v21,
      topRight: &v20,
      bottomRight: &v19,
      bottomLeft: &v18,
      material: v5,
      a7: v6);
    idRenderModelGui::DrawString(
      this: v2,
      x: 0.0,
      y: 0.0,
      string: v8,
      defaultColor: v7,
      forceColor: "white SmallString at 0,0",
      scale: 1.0,
      a8: (const idVec4 *)&idColor::colorWhite,
      a9: 1);
    idRenderModelGui::DrawString(
      this: v2,
      x: 0.0,
      y: 20.0,
      string: v10,
      defaultColor: v9,
      forceColor: "red SmallString at 0,20",
      scale: 1.0,
      a8: (const idVec4 *)&idColor::colorRed,
      a9: 1);
    idRenderModelGui::DrawString(
      this: v2,
      x: 100.0,
      y: 100.0,
      string: v12,
      defaultColor: v11,
      forceColor: "scale 2 string at 100,100",
      scale: 1.0,
      a8: (const idVec4 *)&idColor::colorWhite,
      a9: 1);
    v17 = v2;
    v13 = renderSystem->__vftable;
    v14 = renderSystem->GetHeight(this: renderSystem);
    v15 = renderSystem->GetWidth(this: renderSystem);
    v16 = renderSystem->GetGameWindow(this: renderSystem);
    ((void (__fastcall *)(idRenderSystem *, void *, int, int, _DWORD, idRenderModelGui **, int, int))v13->EndFrame)(
      a1: renderSystem,
      a2: v16,
      a3: v15,
      a4: v14,
      a5: 0,
      a6: &v17,
      a7: 1,
      a8: 1);
  }
  while ( (unsigned __int8)AbortSample() == 0 );
  v2->unlinked = true;
  v2->deleteOnSync = true;
  idRenderModel::CommitThisFrame(this: v2);
}


// ========================================================================
// __unwind$220025_0
// EA  : 0x82987294
// RVA : 0x00987294
// PDB : w:\tech5\engine\samples\rendersamples.cpp
// ========================================================================

void __fastcall _unwind_220025_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 368 + 112), tag: a2);
}


// ========================================================================
// ?Sample_PixelEdges_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829872C8
// RVA : 0x009872C8
// PDB : w:\tech5\engine\samples\rendersamples.cpp
// ========================================================================

void __fastcall Sample_PixelEdges_f(const idCmdArgs *args)
{
  int v1; // r7
  unsigned __int64 v2; // r6
  const idMaterial *v3; // r29
  int v4; // r26
  int v5; // r27
  __int64 v6; // r4
  __int128 v7; // r11
  unsigned int v8; // r3
  unsigned __int64 v9; // r10
  __int128 v10; // r8
  const idVec4 *v11; // r5
  const char *v12; // r4
  const idMaterial *v13; // r3
  int v14; // r5
  const idMaterial *v15; // r4
  const idMaterial *v16; // r3
  int v17; // r5
  const idMaterial *v18; // r4
  const idMaterial *v19; // r3
  int v20; // r5
  const idMaterial *v21; // r4
  int v22; // r26
  int i; // r27
  idColor *v24; // r3
  unsigned int v25; // r3
  signed __int64 v26; // r10
  __int128 v27; // r8
  idImage *v28; // r3
  idImage *v29; // r27
  char *v30; // r3
  char *v31; // r29
  int height; // r9
  int width; // r8
  int j; // r10
  int v35; // r11
  int v36; // r8
  int v37; // r5
  const idMaterial *v38; // r27
  int v39; // r5
  const idMaterial *v40; // r4
  idRenderSystem_vtbl *v41; // r28
  int v42; // r27
  int v43; // r26
  void *v44; // r3
  int v45; // [sp+8h] [-2B8h]
  int v46; // [sp+8Ch] [-234h] BYREF
  idImageOpts v47; // [sp+90h] [-230h] BYREF
  idVec4 v48; // [sp+E0h] [-1E0h] BYREF
  idVec4 v49; // [sp+F0h] [-1D0h] BYREF
  idVec4 v50; // [sp+100h] [-1C0h] BYREF
  idVec4 v51; // [sp+110h] [-1B0h] BYREF
  idVec4 v52; // [sp+120h] [-1A0h] BYREF
  idVec4 v53; // [sp+130h] [-190h] BYREF
  idVec4 v54; // [sp+140h] [-180h] BYREF
  idVec4 v55; // [sp+150h] [-170h] BYREF
  idVec4 v56; // [sp+160h] [-160h] BYREF
  idVec4 v57; // [sp+170h] [-150h] BYREF
  idVec4 v58; // [sp+180h] [-140h] BYREF
  idVec4 v59; // [sp+190h] [-130h] BYREF
  idVec4 v60; // [sp+1A0h] [-120h] BYREF
  __int64 v61; // [sp+1B0h] [-110h]
  signed __int64 v62; // [sp+1B8h] [-108h]
  __int64 v63; // [sp+1C0h] [-100h]
  __int64 v64; // [sp+1C8h] [-F8h]
  __int64 v65; // [sp+1D0h] [-F0h]
  __int64 v66; // [sp+1D8h] [-E8h]
  __int64 v67; // [sp+1E0h] [-E0h]
  char *v68; // [sp+1E8h] [-D8h]
  unsigned int v69; // [sp+1ECh] [-D4h]

  do
  {
    console->Gui(this: console);
    idRenderModelGui::Clear(
      this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
      a2: defaultExtraGLState,
      bits: v2,
      a4: v1);
    v3 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                               this: &idMaterial::resourceList,
                               name: "_white",
                               makeDefault: true);
    v4 = renderSystem->GetWidth(this: renderSystem);
    v5 = renderSystem->GetHeight(this: renderSystem);
    v6 = __PAIR64__(idColor::PackColor(color: (const idVec4 *)&idColor::colorRed), v4);
    MEMORY[0x7F4] = HIDWORD(v6);
    v63 = v7;
    v66 = v6;
    v55.x = 0.0;
    v55.z = 0.0;
    v55.w = 1.0;
    v51.z = 1.0;
    v51.w = 1.0;
    v59.y = 0.0;
    v59.z = 1.0;
    v59.w = 0.0;
    v48.x = 0.0;
    v48.y = 0.0;
    v48.z = 0.0;
    v55.y = (float)(__int64)v7;
    v51.y = v55.y;
    v48.w = 0.0;
    v51.x = (float)v6;
    v59.x = v51.x;
    idRenderModelGui::DrawStretchPic(
      this: nullptr,
      topLeft: &v48,
      topRight: &v59,
      bottomRight: &v51,
      bottomLeft: &v55,
      material: v3,
      a7: *(unsigned __int64 *)((char *)&v7 + 4));
    v8 = idColor::PackColor(color: (const idVec4 *)&idColor::colorDkGrey);
    LODWORD(v9) = v4 - 2;
    HIDWORD(v9) = v5 - 2;
    MEMORY[0x7F4] = v8;
    LODWORD(v10) = v4 - 2;
    v53.x = 1.0;
    DWORD2(v10) = v5 - 2;
    v67 = v10;
    v65 = *(_QWORD *)((char *)&v10 + 4);
    v53.z = 0.0;
    v53.w = 1.0;
    v49.z = 1.0;
    v49.w = 1.0;
    v50.y = 1.0;
    v50.z = 1.0;
    v50.w = 0.0;
    v53.y = (float)*(__int64 *)((char *)&v10 + 4) + (float)1.0;
    v49.y = v53.y;
    v57.x = 1.0;
    v57.y = 1.0;
    v57.z = 0.0;
    v57.w = 0.0;
    v49.x = (float)(__int64)v10 + (float)1.0;
    v50.x = v49.x;
    idRenderModelGui::DrawStretchPic(
      this: nullptr,
      topLeft: &v57,
      topRight: &v50,
      bottomRight: &v49,
      bottomLeft: &v53,
      material: v3,
      a7: v9);
    v52.x = 1.0;
    v52.y = 1.0;
    v52.z = 1.0;
    v52.w = 1.0;
    idRenderModelGui::DrawString(
      this: nullptr,
      x: 100.0,
      y: 300.0,
      string: v12,
      defaultColor: v11,
      forceColor: "One pixel red border at edge of screen",
      scale: 1.0,
      a8: &v52,
      a9: 0);
    v13 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                this: &idMaterial::resourceList,
                                name: "codeSampleMedia/32.bmp",
                                makeDefault: true);
    idRenderModelGui::DrawPic(this: nullptr, x: 100.0, y: 100.0, material: v15, a5: v14, a6: v13);
    v16 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                this: &idMaterial::resourceList,
                                name: "codeSampleMedia/33.bmp",
                                makeDefault: true);
    idRenderModelGui::DrawPic(this: nullptr, x: 200.0, y: 100.0, material: v18, a5: v17, a6: v16);
    v19 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                this: &idMaterial::resourceList,
                                name: "codeSampleMedia/36.bmp",
                                makeDefault: true);
    idRenderModelGui::DrawPic(this: nullptr, x: 300.0, y: 100.0, material: v21, a5: v20, a6: v19);
    v22 = 0;
    for ( i = 200; i > 0; i -= 2 )
    {
      v24 = &idColor::colorBlue;
      if ( (v22 & 1) == 0 )
        v24 = &idColor::colorGreen;
      v25 = idColor::PackColor(color: (const idVec4 *)v24);
      LODWORD(v26) = i;
      MEMORY[0x7F4] = v25;
      HIDWORD(v26) = v22 + 400;
      v56.z = 0.0;
      LODWORD(v27) = v22 + 100;
      v62 = v26;
      DWORD2(v27) = v22 + 400;
      v64 = v27;
      v61 = *(_QWORD *)((char *)&v27 + 4);
      v56.w = 1.0;
      v58.z = 1.0;
      v58.w = 1.0;
      v60.z = 1.0;
      v60.w = 0.0;
      v54.z = 0.0;
      v54.w = 0.0;
      v56.x = (float)(__int64)v27;
      v60.y = (float)*(__int64 *)((char *)&v27 + 4);
      v54.x = v56.x;
      v54.y = v60.y;
      v58.x = (float)v26 + v56.x;
      v56.y = (float)v26 + v60.y;
      v58.y = v56.y;
      v60.x = v58.x;
      idRenderModelGui::DrawStretchPic(
        this: nullptr,
        topLeft: &v54,
        topRight: &v60,
        bottomRight: &v58,
        bottomLeft: &v56,
        material: v3,
        a7: v26);
      ++v22;
    }
    v47.border.x = 0.0;
    v47.border.y = 0.0;
    v47.border.z = 0.0;
    v47.border.w = 0.0;
    memset(&v47.colorFormat, 0, 12);
    v47.lodBias = 0.0;
    v47.lodMinClamp = 0.0;
    v47.cubeFilter = false;
    v47.lodMaxClamp = 13.0;
    v47.depth = 0;
    v47.aniso = 0.0;
    v47.textureType = TT_2D;
    v47.packedTail = true;
    v47.readback = false;
    v47.linear = false;
    v47.forceBias = false;
    v47.depthCompareMode = false;
    v47.overlayMemory = false;
    v47.startPurged = false;
    v47.format = FMT_RGBA8;
    v47.width = 128;
    v47.height = 128;
    v47.numLevels = 1;
    v28 = idImageManager::ScratchImage(this: globalImages, _name: "_checkerboard", imgOpts: &v47);
    v69 = 4 * v47.height * v47.width;
    v29 = v28;
    v30 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                    size: v69,
                    tag: TAG_TEMP,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    v31 = v30;
    v68 = v30;
    height = v47.height;
    width = v47.width;
    for ( j = 0; j < height; ++j )
    {
      v35 = 0;
      if ( width > 0 )
      {
        do
        {
          v36 = 4 * (j * width + v35);
          if ( (((unsigned __int8)v35 ^ (unsigned __int8)j) & 1) != 0 )
          {
            v30[v36] = -1;
            v30[4 * j * v47.width + 1 + 4 * v35] = 0;
          }
          else
          {
            v30[v36] = 0;
            v30[4 * j * v47.width + 1 + 4 * v35] = -1;
          }
          v30[4 * j * v47.width + 2 + 4 * v35] = 0;
          v37 = j * v47.width + v35++;
          v30[4 * v37 + 3] = -1;
          width = v47.width;
        }
        while ( v35 < v47.width );
        height = v47.height;
      }
    }
    idImage::SubImageUpload(
      this: v29,
      mipLevel: 0,
      destX: 0,
      destY: 0,
      destZ: D3DCUBEMAP_FACE_POSITIVE_X,
      width,
      height,
      pic: v30,
      pixelPitch: v45);
    v38 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                this: &idMaterial::resourceList,
                                name: "_checkerboard",
                                makeDefault: true);
    MEMORY[0x7F4] = idColor::PackColor(color: (const idVec4 *)&idColor::colorWhite);
    idRenderModelGui::DrawPic(this: nullptr, x: 400.0, y: 400.0, material: v40, a5: v39, a6: v38);
    v46 = 0;
    v41 = renderSystem->__vftable;
    v42 = renderSystem->GetHeight(this: renderSystem);
    v43 = renderSystem->GetWidth(this: renderSystem);
    v44 = renderSystem->GetGameWindow(this: renderSystem);
    ((void (__fastcall *)(idRenderSystem *, void *, int, int, _DWORD, int *, int, int))v41->EndFrame)(
      a1: renderSystem,
      a2: v44,
      a3: v43,
      a4: v42,
      a5: 0,
      a6: &v46,
      a7: 1,
      a8: 1);
    if ( v31 != nullptr )
      idMem::Free(this: &mem, ptr: v31, align: ALIGN_16);
  }
  while ( (unsigned __int8)AbortSample() == 0 );
}


// ========================================================================
// __unwind$220127
// EA  : 0x8298796C
// RVA : 0x0098796C
// PDB : w:\tech5\engine\samples\rendersamples.cpp
// ========================================================================

void _unwind_220127()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 704 + 488));
}


// ========================================================================
// ?Sample_Viewport_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829879A0
// RVA : 0x009879A0
// PDB : w:\tech5\engine\samples\rendersamples.cpp
// ========================================================================

void __fastcall Sample_Viewport_f(const idCmdArgs *args)
{
  unsigned int v1; // r27
  int v2; // r22
  __int64 v3; // r4
  __int128 v4; // r9
  double v5; // fp26
  double v6; // fp28
  const idMaterial *v7; // r28
  double v8; // fp29
  double v9; // fp27
  idRenderModelGui *v10; // r3
  __int64 v11; // r30
  int v12; // r7
  unsigned __int64 v13; // r6
  unsigned __int64 v14; // r10
  unsigned __int64 v15; // r10
  const idVec4 *v16; // r5
  const char *v17; // r4
  idRenderModelGui *v18; // r3
  int v19; // r7
  unsigned __int64 v20; // r6
  unsigned __int64 v21; // r10
  unsigned __int64 v22; // r10
  const idVec4 *v23; // r5
  const char *v24; // r4
  idRenderSystem_vtbl *v25; // r14
  void *v26; // r3
  _QWORD v27[2]; // [sp+70h] [-210h] BYREF
  idVec4 v28; // [sp+80h] [-200h] BYREF
  idVec4 v29; // [sp+90h] [-1F0h] BYREF
  idVec4 v30; // [sp+A0h] [-1E0h] BYREF
  idVec4 v31; // [sp+B0h] [-1D0h] BYREF
  idVec4 v32; // [sp+C0h] [-1C0h] BYREF
  idVec4 v33; // [sp+D0h] [-1B0h] BYREF
  idVec4 v34; // [sp+E0h] [-1A0h] BYREF
  idVec4 v35; // [sp+F0h] [-190h] BYREF
  idVec4 v36; // [sp+100h] [-180h] BYREF
  idVec4 v37; // [sp+110h] [-170h] BYREF
  idVec4 v38; // [sp+120h] [-160h] BYREF
  idVec4 v39; // [sp+130h] [-150h] BYREF
  idVec4 v40; // [sp+140h] [-140h] BYREF
  idVec4 v41; // [sp+150h] [-130h] BYREF
  idVec4 v42; // [sp+160h] [-120h] BYREF
  idVec4 v43; // [sp+170h] [-110h] BYREF
  idVec4 v44; // [sp+180h] [-100h] BYREF
  idVec4 v45; // [sp+190h] [-F0h] BYREF

  v1 = renderSystem->GetWidth(this: renderSystem);
  v2 = renderSystem->GetHeight(this: renderSystem);
  HIDWORD(v3) = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: "_white", makeDefault: true);
  HIDWORD(v4) = v2 - 2;
  DWORD2(v4) = v1 - 2;
  DWORD1(v4) = v1;
  LODWORD(v3) = v2 - 2;
  LODWORD(v4) = v2;
  v27[0] = v3;
  v27[1] = v4;
  v5 = (float)((float)*(__int64 *)((char *)&v4 + 4) + (float)1.0);
  v6 = (float)*(__int64 *)&v4;
  v7 = (const idMaterial *)HIDWORD(v3);
  v8 = (float)(__int64)v4;
  v9 = (float)((float)v3 + (float)1.0);
  do
  {
    v10 = (idRenderModelGui *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xA410u,
                                tag: TAG_GUI,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    HIDWORD(v27[1]) = v10;
    if ( v10 != nullptr )
      HIDWORD(v11) = idRenderModelGui::idRenderModelGui(this: v10);
    else
      HIDWORD(v11) = 0;
    idRenderModelGui::SetViewport(this: (idRenderModelGui *)HIDWORD(v11), x: 0, y: 0, width: v1, height: v2 / 2);
    idRenderModelGui::Clear(
      this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
      a2: defaultExtraGLState,
      bits: v13,
      a4: v12);
    *(_DWORD *)(HIDWORD(v11) + 2036) = idColor::PackColor(color: (const idVec4 *)&idColor::colorRed);
    v36.x = 0.0;
    v36.y = v8;
    v36.z = 0.0;
    v36.w = 1.0;
    v30.x = v6;
    v30.y = v8;
    v30.z = 1.0;
    v30.w = 1.0;
    v38.x = v6;
    v38.y = 0.0;
    v38.z = 1.0;
    v38.w = 0.0;
    v32.x = 0.0;
    v32.y = 0.0;
    v32.z = 0.0;
    v32.w = 0.0;
    idRenderModelGui::DrawStretchPic(
      this: (idRenderModelGui *)HIDWORD(v11),
      topLeft: &v32,
      topRight: &v38,
      bottomRight: &v30,
      bottomLeft: &v36,
      material: v7,
      a7: v14);
    *(_DWORD *)(HIDWORD(v11) + 2036) = idColor::PackColor(color: (const idVec4 *)&idColor::colorBlack);
    v42.x = 1.0;
    v42.y = v9;
    v42.z = 0.0;
    v42.w = 1.0;
    v34.x = v5;
    v34.y = v9;
    v34.z = 1.0;
    v34.w = 1.0;
    v40.x = v5;
    v40.y = 1.0;
    v40.z = 1.0;
    v40.w = 0.0;
    v28.x = 1.0;
    v28.y = 1.0;
    v28.z = 0.0;
    v28.w = 0.0;
    idRenderModelGui::DrawStretchPic(
      this: (idRenderModelGui *)HIDWORD(v11),
      topLeft: &v28,
      topRight: &v40,
      bottomRight: &v34,
      bottomLeft: &v42,
      material: v7,
      a7: v15);
    v44.x = 1.0;
    v44.y = 1.0;
    v44.z = 1.0;
    v44.w = 1.0;
    idRenderModelGui::DrawString(
      this: (idRenderModelGui *)HIDWORD(v11),
      x: 100.0,
      y: 300.0,
      string: v17,
      defaultColor: v16,
      forceColor: "One pixel red border, top viewport",
      scale: 1.0,
      a8: &v44,
      a9: 0);
    v18 = (idRenderModelGui *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xA410u,
                                tag: TAG_GUI,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    HIDWORD(v27[1]) = v18;
    if ( v18 != nullptr )
      LODWORD(v11) = idRenderModelGui::idRenderModelGui(this: v18);
    else
      LODWORD(v11) = 0;
    idRenderModelGui::SetViewport(this: (idRenderModelGui *)v11, x: 0, y: v2 / 2, width: v1, height: v2 - v2 / 2);
    idRenderModelGui::Clear(
      this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
      a2: defaultExtraGLState,
      bits: v20,
      a4: v19);
    *(_DWORD *)(v11 + 2036) = idColor::PackColor(color: (const idVec4 *)&idColor::colorGreen);
    v29.x = 0.0;
    v29.y = v8;
    v29.z = 0.0;
    v29.w = 1.0;
    v31.x = v6;
    v31.y = v8;
    v31.z = 1.0;
    v31.w = 1.0;
    v33.x = v6;
    v33.y = 0.0;
    v33.z = 1.0;
    v33.w = 0.0;
    v35.x = 0.0;
    v35.y = 0.0;
    v35.z = 0.0;
    v35.w = 0.0;
    idRenderModelGui::DrawStretchPic(
      this: (idRenderModelGui *)v11,
      topLeft: &v35,
      topRight: &v33,
      bottomRight: &v31,
      bottomLeft: &v29,
      material: v7,
      a7: v21);
    *(_DWORD *)(v11 + 2036) = idColor::PackColor(color: (const idVec4 *)&idColor::colorBlack);
    v37.x = 1.0;
    v37.y = v9;
    v37.z = 0.0;
    v37.w = 1.0;
    v39.x = v5;
    v39.y = v9;
    v39.z = 1.0;
    v39.w = 1.0;
    v41.x = v5;
    v41.y = 1.0;
    v41.z = 1.0;
    v41.w = 0.0;
    v43.x = 1.0;
    v43.y = 1.0;
    v43.z = 0.0;
    v43.w = 0.0;
    idRenderModelGui::DrawStretchPic(
      this: (idRenderModelGui *)v11,
      topLeft: &v43,
      topRight: &v41,
      bottomRight: &v39,
      bottomLeft: &v37,
      material: v7,
      a7: v22);
    v45.x = 1.0;
    v45.y = 1.0;
    v45.z = 1.0;
    v45.w = 1.0;
    idRenderModelGui::DrawString(
      this: (idRenderModelGui *)v11,
      x: 100.0,
      y: 300.0,
      string: v24,
      defaultColor: v23,
      forceColor: "One pixel green border, bottom viewport",
      scale: 1.0,
      a8: &v45,
      a9: 0);
    v27[0] = v11;
    v25 = renderSystem->__vftable;
    v26 = renderSystem->GetGameWindow(this: renderSystem);
    ((void (__fastcall *)(idRenderSystem *, void *, unsigned int, int, _DWORD, _QWORD *, int, int))v25->EndFrame)(
      a1: renderSystem,
      a2: v26,
      a3: v1,
      a4: v2,
      a5: 0,
      a6: v27,
      a7: 2,
      a8: 1);
  }
  while ( (unsigned __int8)AbortSample() == 0 );
  *(_BYTE *)(HIDWORD(v11) + 75) = 1;
  *(_BYTE *)(HIDWORD(v11) + 74) = 1;
  idRenderModel::CommitThisFrame(this: (idRenderModel *)HIDWORD(v11));
  *(_BYTE *)(v11 + 75) = 1;
  *(_BYTE *)(v11 + 74) = 1;
  idRenderModel::CommitThisFrame(this: (idRenderModel *)v11);
}


// ========================================================================
// __unwind$220483
// EA  : 0x82987E38
// RVA : 0x00987E38
// PDB : w:\tech5\engine\samples\rendersamples.cpp
// ========================================================================

void _unwind_220483()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 640 + 120), tag: TAG_GUI);
}


// ========================================================================
// __unwind$220484
// EA  : 0x82987E64
// RVA : 0x00987E64
// PDB : w:\tech5\engine\samples\rendersamples.cpp
// ========================================================================

void _unwind_220484()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 640 + 120), tag: TAG_GUI);
}


// ========================================================================
// `dynamic initializer for 'Sample_GuiModel_v''
// EA  : 0x83360020
// RVA : 0x01360020
// PDB : w:\tech5\engine\samples\rendersamples.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Sample_GuiModel_v__()
{
  return idCommandLink::idCommandLink(
           this: &Sample_GuiModel_v,
           cmdName: "Sample_GuiModel",
           function: Sample_GuiModel_f,
           description: "Documentation sample",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Sample_PixelEdges_v''
// EA  : 0x83360048
// RVA : 0x01360048
// PDB : w:\tech5\engine\samples\rendersamples.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Sample_PixelEdges_v__()
{
  return idCommandLink::idCommandLink(
           this: &Sample_PixelEdges_v,
           cmdName: "Sample_PixelEdges",
           function: Sample_PixelEdges_f,
           description: "Documentation sample",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Sample_Viewport_v''
// EA  : 0x83360070
// RVA : 0x01360070
// PDB : w:\tech5\engine\samples\rendersamples.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Sample_Viewport_v__()
{
  return idCommandLink::idCommandLink(
           this: &Sample_Viewport_v,
           cmdName: "Sample_Viewport",
           function: Sample_Viewport_f,
           description: "Documentation sample",
           argCompletion: nullptr);
}

