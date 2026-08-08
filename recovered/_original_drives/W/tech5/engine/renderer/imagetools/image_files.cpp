
// ========================================================================
// user_read_data
// EA  : 0x828C6D98
// RVA : 0x008C6D98
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __fastcall user_read_data(png_struct_def *png_ptr, unsigned __int8 *data, unsigned int length)
{
  void *io_ptr; // r3

  io_ptr = png_get_io_ptr(png_ptr);
  (*(void (__fastcall **)(void *, unsigned __int8 *, unsigned int))(*(_DWORD *)io_ptr + 12))(
    a1: io_ptr,
    a2: data,
    a3: length);
}


// ========================================================================
// ?R_ReorganizeCubeImages@@YAXQAPAEH@Z
// EA  : 0x828C6DE8
// RVA : 0x008C6DE8
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __fastcall R_ReorganizeCubeImages(unsigned __int8 **pics, int size)
{
  R_RotatePic(data: *pics, width: size);
  R_RotatePic(data: pics[1], width: size);
  R_HorizontalFlip(data: pics[1], width: size, height: size);
  R_VerticalFlip(data: pics[1], width: size, height: size);
  R_VerticalFlip(data: pics[2], width: size, height: size);
  R_HorizontalFlip(data: pics[3], width: size, height: size);
  R_RotatePic(data: pics[4], width: size);
  R_RotatePic(data: pics[5], width: size);
}


// ========================================================================
// ?R_LoadCubeImages@@YA_NPBDQAPAEPAHPAI@Z
// EA  : 0x828C6E88
// RVA : 0x008C6E88
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

int __fastcall R_LoadCubeImages(const char *imgName, unsigned __int8 **pics, int *outSize, unsigned int *timestamp)
{
  unsigned __int8 **v8; // r11
  int i; // ctr
  char *v10; // r3
  _DWORD *v11; // r26
  unsigned int v12; // r29
  int v13; // r25
  int v14; // r31
  char *v15; // r10
  unsigned __int8 *v16; // r11
  int v17; // r8
  char *v18; // r10
  int v19; // r8
  unsigned __int8 **v20; // r4
  void **v21; // r30
  int v23; // [sp+50h] [-B0h] BYREF
  int v24; // [sp+54h] [-ACh] BYREF
  unsigned int v25; // [sp+58h] [-A8h] BYREF
  _DWORD v26[8]; // [sp+60h] [-A0h] BYREF
  _DWORD v27[32]; // [sp+80h] [-80h] BYREF

  v26[0] = "_forward.tga";
  v26[1] = "_back.tga";
  v26[2] = "_left.tga";
  v26[3] = "_right.tga";
  v26[4] = "_up.tga";
  v26[5] = "_down.tga";
  v27[0] = "_px.tga";
  v27[1] = "_nx.tga";
  v27[2] = "_py.tga";
  v27[3] = "_ny.tga";
  v27[4] = "_pz.tga";
  v27[5] = "_nz.tga";
  if ( pics != nullptr )
  {
    v8 = pics - 1;
    for ( i = 6; i != 0; --i )
      *++v8 = nullptr;
  }
  if ( timestamp != nullptr )
    *timestamp = -1;
  if ( outSize != nullptr )
    *outSize = 0;
  v10 = strstr(str1: imgName, str2: "_forward");
  if ( v10 != nullptr )
  {
    v11 = v26;
  }
  else
  {
    v10 = strstr(str1: imgName, str2: "_px");
    if ( v10 == nullptr )
    {
      idLib::Warning(fmt: "Cube map file doesn't have _forward or _px: %s", imgName);
      return 0;
    }
    v11 = v27;
  }
  v23 = 0;
  v12 = v10 - imgName;
  v24 = 0;
  v13 = 0;
  v14 = 0;
  while ( 1 )
  {
    strncpy(dest: fullName, source: imgName, count: v12);
    v15 = fullName;
    fullName[v12] = 0;
    v16 = (unsigned __int8 *)v11[v14];
    do
      v17 = (unsigned __int8)*v15++;
    while ( v17 != 0 );
    v18 = v15 - 1;
    do
    {
      v19 = *v16++;
      *v18++ = v19;
    }
    while ( v19 != 0 );
    v20 = nullptr;
    if ( pics != nullptr )
      v20 = &pics[v14];
    R_LoadImageProgram(name: fullName, pic: v20, width: &v23, height: &v24, timestamps: &v25);
    if ( v25 == -1 )
    {
      idLib::Warning(fmt: "Cube map file not found: %s", fullName);
      goto LABEL_32;
    }
    if ( v14 != 0 )
    {
      if ( v23 != v13 )
        break;
    }
    else
    {
      v13 = v23;
    }
    if ( v24 != v13 )
      break;
    if ( timestamp != nullptr && (*timestamp == -1 || v25 > *timestamp) )
      *timestamp = v25;
    if ( ++v14 >= 6 )
      goto LABEL_32;
  }
  idLib::Warning(fmt: "Mismatched sizes on cube map '%s'", imgName);
LABEL_32:
  if ( v14 != 6 )
  {
    if ( pics != nullptr && v14 > 0 )
    {
      v21 = (void **)(pics - 1);
      do
      {
        idMem::Free(this: &mem, ptr: *++v21, align: ALIGN_16);
        --v14;
      }
      while ( v14 != 0 );
    }
    if ( timestamp != nullptr )
    {
      *timestamp = -1;
      return 0;
    }
    return 0;
  }
  if ( pics != nullptr && v11 == v26 )
    R_ReorganizeCubeImages(pics, size: v23);
  if ( outSize != nullptr )
    *outSize = v13;
  return 1;
}


// ========================================================================
// ?R_WritePNGUserWrite@@YAXPAUpng_struct_def@@PAEI@Z
// EA  : 0x828C7168
// RVA : 0x008C7168
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __fastcall R_WritePNGUserWrite(png_struct_def *png_ptr, unsigned __int8 *ptr, unsigned int size)
{
  (*(void (__fastcall **)(void *, unsigned __int8 *, unsigned int))(*(_DWORD *)png_ptr->io_ptr + 16))(
    a1: png_ptr->io_ptr,
    a2: ptr,
    a3: size);
}


// ========================================================================
// ?R_WritePNGUserFlush@@YAXPAUpng_struct_def@@@Z
// EA  : 0x828C7180
// RVA : 0x008C7180
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __fastcall R_WritePNGUserFlush(png_struct_def *png_ptr)
{
  (*(void (__fastcall **)(void *))(*(_DWORD *)png_ptr->io_ptr + 68))(a1: png_ptr->io_ptr);
}


// ========================================================================
// ?R_WritePNGUserMemAlloc@@YAPAXPAUpng_struct_def@@I@Z
// EA  : 0x828C7198
// RVA : 0x008C7198
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void *__fastcall R_WritePNGUserMemAlloc(png_struct_def *png_ptr, unsigned int size)
{
  return idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_files.cpp(1260) : TAG_IMAGE",
           size,
           tag: TAG_IMAGE,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ?R_WritePNGUserError@@YAXPAUpng_struct_def@@PBD@Z
// EA  : 0x828C71C0
// RVA : 0x008C71C0
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __fastcall R_WritePNGUserError(png_struct_def *png_ptr, const char *msg)
{
  idLib::Error(fmt: "R_WritePNG: %s", msg);
}


// ========================================================================
// ?R_WritePNGUserWarning@@YAXPAUpng_struct_def@@PBD@Z
// EA  : 0x828C71D0
// RVA : 0x008C71D0
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __fastcall R_WritePNGUserWarning(png_struct_def *png_ptr, const char *msg)
{
  idLib::Warning(fmt: "R_WritePNG: %s", msg);
}


// ========================================================================
// R_LoadBMP
// EA  : 0x828C7248
// RVA : 0x008C7248
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __fastcall R_LoadBMP(const char *name, unsigned __int8 **pic, int *width, int *height, unsigned int *timestamp)
{
  char v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // r4
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r4
  int v13; // r10
  int v14; // r9
  int v15; // r8
  int v16; // r7
  char v17; // r5
  char v18; // r29
  char v19; // r30
  char v20; // r16
  char v21; // r5
  char v22; // r14
  char v23; // r31
  char v24; // r4
  char v25; // r4
  char v26; // r3
  char v27; // r11
  char v28; // r10
  char v29; // r9
  char v30; // r8
  char v31; // r7
  char v32; // r6
  char v33; // r5
  char v34; // r4
  char v35; // r3
  char v36; // r6
  char v37; // r5
  char v38; // r4
  char v39; // r3
  char v40; // r11
  char v41; // r10
  char v42; // r9
  unsigned __int8 *v43; // r30
  int v44; // r31
  int v45; // r29
  int v46; // r11
  unsigned __int8 *v47; // r3
  int v48; // r31
  unsigned __int8 *v49; // r4
  unsigned __int8 *v50; // r10
  unsigned __int8 *v51; // r11
  int v52; // r5
  unsigned int v53; // r9
  unsigned __int8 *v54; // r11
  int v55; // r3
  unsigned __int8 v56; // r8
  unsigned __int8 v57; // r7
  unsigned __int8 v58; // r7
  unsigned __int8 v59; // r9
  unsigned __int8 v60; // r3
  unsigned __int8 v61; // r9
  unsigned __int8 v62; // r8
  unsigned __int8 v63; // r7
  unsigned int *v64; // r9
  int *v65; // r8
  int *v66; // r7
  unsigned __int8 **v67; // r6
  unsigned int v68; // r5
  const unsigned __int8 *v69; // r4
  const char *v70; // r3
  int v71; // [sp+6Ch] [-4E4h]
  char *v72; // [sp+70h] [-4E0h] BYREF
  int v73; // [sp+74h] [-4DCh]
  unsigned __int16 *v74; // [sp+78h] [-4D8h]
  char v75; // [sp+80h] [-4D0h]
  char v76; // [sp+81h] [-4CFh]
  int v77; // [sp+84h] [-4CCh]
  int v78; // [sp+88h] [-4C8h]
  int v79; // [sp+8Ch] [-4C4h]
  int v80; // [sp+90h] [-4C0h]
  int v81; // [sp+94h] [-4BCh]
  int v82; // [sp+98h] [-4B8h]
  __int16 v83; // [sp+9Ch] [-4B4h]
  unsigned __int16 v84; // [sp+9Eh] [-4B2h]
  int v85; // [sp+A0h] [-4B0h]
  int v86; // [sp+A4h] [-4ACh]
  int v87; // [sp+A8h] [-4A8h]
  int v88; // [sp+ACh] [-4A4h]
  int v89; // [sp+B0h] [-4A0h]
  int v90; // [sp+B4h] [-49Ch]
  _BYTE v91[1176]; // [sp+B8h] [-498h] BYREF

  if ( pic != nullptr )
  {
    *pic = nullptr;
    v74 = &si_vector_decode_cat_0[184];
    v73 = fileSystem->ReadFile(this: fileSystem, a2: name, a3: (void **)&v72, a4: timestamp);
    if ( v72 == nullptr )
      return;
    v5 = v72[1];
    v6 = *(_DWORD *)(v72 + 2);
    v75 = *v72;
    v76 = v5;
    v7 = *(_DWORD *)(v72 + 6);
    v77 = v6;
    v8 = *(_DWORD *)(v72 + 10);
    v78 = v7;
    v9 = *(_DWORD *)(v72 + 14);
    v79 = v8;
    v10 = *(_DWORD *)(v72 + 18);
    v80 = v9;
    v11 = *(_DWORD *)(v72 + 22);
    v81 = v10;
    LOWORD(v6) = *((_WORD *)v72 + 13);
    v82 = v11;
    LOWORD(v7) = *((_WORD *)v72 + 14);
    v83 = v6;
    v12 = *(_DWORD *)(v72 + 30);
    v84 = v7;
    v13 = *(_DWORD *)(v72 + 34);
    v85 = v12;
    v14 = *(_DWORD *)(v72 + 38);
    v86 = v13;
    v15 = *(_DWORD *)(v72 + 42);
    v87 = v14;
    v16 = *(_DWORD *)(v72 + 46);
    v88 = v15;
    v90 = *(_DWORD *)(v72 + 50);
    v89 = v16;
    memcpy(Dst: v91, Src: v72 + 54, Size: 0x400u);
    v17 = v84;
    v18 = HIBYTE(v77);
    LOBYTE(v84) = HIBYTE(v84);
    HIBYTE(v84) = v17;
    v19 = HIBYTE(v78);
    v20 = BYTE1(v77);
    v21 = HIBYTE(v79);
    v22 = HIBYTE(v80);
    v23 = BYTE1(v78);
    v24 = BYTE1(v79);
    v71 = v84;
    BYTE1(v77) = BYTE2(v77);
    HIBYTE(v77) = v77;
    BYTE1(v78) = BYTE2(v78);
    HIBYTE(v78) = v78;
    BYTE1(v79) = BYTE2(v79);
    HIBYTE(v79) = v79;
    HIBYTE(v80) = v80;
    LOBYTE(v77) = v18;
    BYTE2(v79) = v24;
    v25 = BYTE1(v80);
    BYTE1(v80) = BYTE2(v80);
    v26 = HIBYTE(v81);
    HIBYTE(v81) = v81;
    v27 = BYTE1(v81);
    BYTE1(v81) = BYTE2(v81);
    v28 = HIBYTE(v82);
    HIBYTE(v82) = v82;
    v29 = BYTE1(v82);
    BYTE1(v82) = BYTE2(v82);
    LOBYTE(v79) = v21;
    BYTE2(v80) = v25;
    LOBYTE(v81) = v26;
    BYTE2(v81) = v27;
    LOBYTE(v82) = v28;
    BYTE2(v82) = v29;
    v30 = HIBYTE(v83);
    HIBYTE(v83) = v83;
    v31 = HIBYTE(v85);
    HIBYTE(v85) = v85;
    v32 = BYTE1(v85);
    BYTE1(v85) = BYTE2(v85);
    v33 = HIBYTE(v86);
    HIBYTE(v86) = v86;
    v34 = BYTE1(v86);
    BYTE1(v86) = BYTE2(v86);
    v35 = HIBYTE(v87);
    HIBYTE(v87) = v87;
    LOBYTE(v83) = v30;
    LOBYTE(v85) = v31;
    BYTE2(v85) = v32;
    LOBYTE(v86) = v33;
    BYTE2(v86) = v34;
    LOBYTE(v87) = v35;
    v36 = BYTE1(v87);
    BYTE1(v87) = BYTE2(v87);
    v37 = HIBYTE(v88);
    HIBYTE(v88) = v88;
    v38 = BYTE1(v88);
    BYTE1(v88) = BYTE2(v88);
    v39 = HIBYTE(v89);
    v40 = BYTE1(v89);
    v41 = HIBYTE(v90);
    v42 = BYTE1(v90);
    BYTE2(v77) = v20;
    LOBYTE(v78) = v19;
    BYTE2(v78) = v23;
    LOBYTE(v80) = v22;
    BYTE1(v89) = BYTE2(v89);
    HIBYTE(v89) = v89;
    BYTE1(v90) = BYTE2(v90);
    HIBYTE(v90) = v90;
    BYTE2(v87) = v36;
    LOBYTE(v88) = v37;
    BYTE2(v88) = v38;
    LOBYTE(v89) = v39;
    BYTE2(v89) = v40;
    LOBYTE(v90) = v41;
    BYTE2(v90) = v42;
    if ( v84 == 8 )
      v43 = (unsigned __int8 *)(v72 + 1078);
    else
      v43 = (unsigned __int8 *)(v72 + 54);
    if ( v75 != 66 && v76 != 77 )
      idLib::Error(fmt: "LoadBMP: only Windows-style BMP files supported (%s)\n", name);
    if ( v77 != v73 )
      idLib::Error(fmt: "LoadBMP: header size does not match file size (%d vs. %d) (%s)\n", v77, v73, name);
    if ( v85 != 0 )
      idLib::Error(fmt: "LoadBMP: only uncompressed BMP files supported (%s)\n", name);
    if ( (unsigned int)v71 < 8 )
      idLib::Error(fmt: "LoadBMP: monochrome and 4-bit BMP files not supported (%s)\n", name);
    v44 = v82;
    if ( v82 < 0 )
      v44 = -v82;
    v45 = v81;
    v46 = v44 * v81;
    if ( width != nullptr )
      *width = v81;
    if ( height != nullptr )
      *height = v44;
    v47 = (unsigned __int8 *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_files.cpp(283) : TAG_IMAGE",
                               size: 4 * v46,
                               tag: TAG_IMAGE,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    v48 = v44 - 1;
    *pic = v47;
    if ( v48 < 0 )
    {
LABEL_38:
      (*(void (__fastcall **)(_DWORD, char *))(**((_DWORD **)v74 - 6824) + 92))(a1: *((_DWORD *)v74 - 6824), a2: v72);
      return;
    }
    v49 = &v47[4 * v48 * v45];
    while ( 1 )
    {
      v50 = v43;
      v51 = v49;
      v43 += (v71 * v45 / 8 + 3) & 0xFFFFFFFC;
      v52 = 0;
      if ( v45 > 0 )
        break;
LABEL_37:
      --v48;
      v49 -= 4 * v45;
      if ( v48 < 0 )
        goto LABEL_38;
    }
    while ( 1 )
    {
      if ( v71 > 24 )
      {
        if ( v71 != 32 )
        {
LABEL_40:
          idLib::Error(fmt: "LoadBMP: illegal pixel_size '%d' in file '%s'\n", v71, name);
          R_LoadTGA(name: v70, buffer: v69, bufferSize: v68, pic: v67, width: v66, height: v65, timestamp: v64);
          return;
        }
        v60 = *v50;
        v61 = v50[1];
        v62 = v50[2];
        v50 += 3;
        v63 = *v50;
        *v51 = v62;
        v51[1] = v61;
        v51[2] = v60;
        v54 = v51 + 3;
        *v54 = v63;
        goto LABEL_35;
      }
      if ( v71 == 24 )
        break;
      if ( v71 == 8 )
      {
        v55 = __ROL4__(*v50, 2);
        v56 = v91[v55 + 2];
        v57 = v91[v55 + 1];
        LOBYTE(v55) = v91[v55];
        *v51 = v56;
        v51[1] = v57;
        v51[2] = v55;
        v54 = v51 + 3;
        *v54 = -1;
LABEL_35:
        ++v50;
        goto LABEL_36;
      }
      if ( v71 != 16 )
        goto LABEL_40;
      v53 = *(unsigned __int16 *)v51;
      v51[2] = (v53 >> 7) & 0xF8;
      v51[3] = (v53 >> 2) & 0xF8;
      v51[4] = 8 * v53;
      v54 = v51 + 5;
      *v54 = -1;
LABEL_36:
      ++v52;
      v51 = v54 + 1;
      if ( v52 >= v45 )
        goto LABEL_37;
    }
    v58 = *v50;
    v59 = v50[1];
    v50 += 2;
    *v51 = *v50;
    v51[1] = v59;
    v51[2] = v58;
    v54 = v51 + 3;
    *v54 = -1;
    goto LABEL_35;
  }
  if ( timestamp != nullptr )
    *timestamp = fileSystem->GetTimestamp(this: fileSystem, a2: name, a3: false);
}


// ========================================================================
// ?R_LoadTGA@@YA_NPBDPBEIPAPAEPAH3PAI@Z
// EA  : 0x828C78A0
// RVA : 0x008C78A0
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

int __fastcall R_LoadTGA(
        const char *name,
        const unsigned __int8 *buffer,
        const unsigned int bufferSize,
        unsigned __int8 **pic,
        int *width,
        int *height,
        unsigned int *timestamp)
{
  unsigned __int8 v9; // r29
  int v10; // r30
  unsigned __int8 v11; // r19
  const unsigned __int8 *v12; // r31
  unsigned int v14; // r25
  unsigned __int8 *v15; // r3
  int k; // r30
  int v17; // r4
  unsigned __int8 *v18; // r11
  unsigned __int8 v19; // r9
  unsigned __int8 v20; // r10
  unsigned __int8 v21; // r9
  unsigned __int8 v22; // r7
  unsigned __int8 v23; // r6
  _BYTE *v24; // r31
  char v25; // r8
  int v26; // r28
  int v27; // r29
  unsigned __int8 *v28; // r10
  int v29; // r29
  int v30; // r5
  unsigned __int8 *v31; // r7
  unsigned __int8 v32; // r28
  unsigned __int8 v33; // r10
  unsigned __int8 v34; // r9
  _BYTE *v35; // r31
  unsigned __int8 v36; // r8
  unsigned __int8 *v37; // r11
  unsigned __int8 v38; // r8
  unsigned __int8 v39; // r10
  int v40; // r7
  unsigned __int8 *v41; // r9
  unsigned __int8 *v42; // r10
  int v43; // ctr
  char *v44; // r11
  char v45; // r3
  unsigned __int8 v46; // r30
  unsigned __int8 v47; // r29
  int v48; // r7
  int v49; // r8
  const unsigned __int8 *v50; // r10
  _BYTE *v51; // r11
  int j; // ctr
  unsigned __int8 v53; // r5
  unsigned __int8 v54; // r4
  unsigned __int8 v55; // r9
  int v56; // r9
  int v57; // r8
  int v58; // r10
  _BYTE *v59; // r11
  int i; // ctr
  unsigned __int8 v61; // r6
  unsigned __int16 v62; // [sp+5Eh] [-82h]
  unsigned __int16 v63; // [sp+60h] [-80h]

  *pic = nullptr;
  v9 = *buffer;
  v10 = buffer[2];
  v11 = buffer[17];
  HIBYTE(v63) = *((_WORD *)buffer + 7);
  v12 = buffer + 18;
  LOBYTE(v62) = HIBYTE(*((_WORD *)buffer + 6));
  HIBYTE(v62) = *((_WORD *)buffer + 6);
  if ( v10 != 2 && v10 != 10 && v10 != 3 )
  {
    idLib::Warning(fmt: "LoadTGA( %s ): Only type 2 (RGB), 3 (gray), and 10 (RGB) TGA images supported", name);
    return 0;
  }
  if ( buffer[1] != 0 )
  {
    idLib::Warning(fmt: "LoadTGA( %s ): colormaps not supported", name);
    return 0;
  }
  v14 = buffer[16];
  if ( v14 != 32 && v14 != 24 && v10 != 3 )
  {
    idLib::Warning(fmt: "LoadTGA( %s ): Only 32 or 24 bit images supported (no colormaps)", name);
    return 0;
  }
  LOBYTE(v63) = HIBYTE(*((_WORD *)buffer + 7));
  if ( (v10 == 2 || v10 == 3) && (v14 >> 3) * v63 * v62 > bufferSize - *buffer - 18 )
  {
    idLib::Warning(fmt: "LoadTGA( %s ): incomplete file", name);
    return 0;
  }
  if ( width != nullptr )
    *width = v62;
  if ( height != nullptr )
    *height = v63;
  v15 = (unsigned __int8 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_files.cpp(440) : TAG_IMAGE",
                             size: 4 * v63 * v62,
                             tag: TAG_IMAGE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  *pic = v15;
  if ( v9 != 0 )
    v12 += v9;
  if ( v10 == 2 || v10 == 3 )
  {
    switch ( v14 )
    {
      case 8u:
        v56 = v63 - 1;
        if ( v56 >= 0 )
        {
          v57 = (int)&v15[4 * v56 * v62 + 2];
          do
          {
            v58 = 0;
            if ( v62 != 0 )
            {
              v59 = (_BYTE *)(v57 - 3);
              for ( i = v62; i != 0; --i )
              {
                v61 = v12[v58++];
                v59[1] = v61;
                v59[2] = v61;
                v59[3] = v61;
                v59 += 4;
                *v59 = -1;
              }
            }
            --v56;
            v12 += v62;
            v57 += -4 * v62;
          }
          while ( v56 >= 0 );
        }
        break;
      case 0x18u:
        v48 = v63 - 1;
        if ( v48 >= 0 )
        {
          v49 = (int)&v15[4 * v48 * v62 + 2];
          v50 = v12 - 1;
          do
          {
            if ( v62 != 0 )
            {
              v51 = (_BYTE *)(v49 - 3);
              for ( j = v62; j != 0; --j )
              {
                v53 = v50[1];
                v54 = v50[2];
                v50 += 3;
                v55 = *v50;
                v51[3] = v53;
                v51[2] = v54;
                v51[1] = v55;
                v51 += 4;
                *v51 = -1;
              }
            }
            --v48;
            v49 -= 4 * v62;
          }
          while ( v48 >= 0 );
        }
        break;
      case 0x20u:
        v40 = v63 - 1;
        if ( v40 >= 0 )
        {
          v41 = &v15[4 * v40 * v62];
          do
          {
            if ( v62 != 0 )
            {
              v42 = v41 - 2;
              v43 = v62;
              v44 = (char *)(v12 + 3);
              do
              {
                v45 = *v44;
                v46 = *(v44 - 1);
                v47 = *(v44 - 3);
                v42[3] = *(v44 - 2);
                v44[v41 - v12] = v45;
                v44 += 4;
                v42[2] = v46;
                v42 += 4;
                *v42 = v47;
                --v43;
              }
              while ( v43 != 0 );
            }
            --v40;
            v12 += 4 * v62;
            v41 -= 4 * v62;
          }
          while ( v40 >= 0 );
        }
        break;
      default:
LABEL_53:
        idLib::Warning(fmt: "LoadTGA( %s ): illegal pixel_size '%d'", name, v14);
        idMem::Free(this: &mem, ptr: *pic, align: ALIGN_16);
        *pic = nullptr;
        return 0;
    }
  }
  else
  {
    for ( k = v63 - 1; k >= 0; --k )
    {
      v17 = 0;
      v18 = &v15[4 * k * v62];
      if ( v62 != 0 )
      {
        do
        {
          v19 = *v12;
          v20 = (*v12++ & 0x7F) + 1;
          if ( (v19 & 0x80) != 0 )
          {
            if ( v14 == 24 )
            {
              v21 = *v12;
              v25 = -1;
              v22 = v12[1];
              v24 = v12 + 2;
              v23 = *v24;
            }
            else
            {
              if ( v14 != 32 )
                goto LABEL_53;
              v21 = *v12;
              v22 = v12[1];
              v23 = v12[2];
              v24 = v12 + 3;
              v25 = *v24;
            }
            v26 = v20;
            v12 = v24 + 1;
            v27 = 0;
            if ( v20 != 0 )
            {
              v28 = &v15[4 * k * v62];
              do
              {
                *v18 = v23;
                ++v17;
                v18[1] = v22;
                v18[2] = v21;
                v18[3] = v25;
                v18 += 4;
                if ( v17 == v62 )
                {
                  v17 = 0;
                  if ( k <= 0 )
                    goto breakOut;
                  v28 -= 4 * v62;
                  --k;
                  v18 = v28;
                }
                ++v27;
              }
              while ( v27 < v26 );
            }
          }
          else
          {
            v29 = v20;
            v30 = 0;
            if ( v20 != 0 )
            {
              v31 = &v15[4 * k * v62];
              do
              {
                if ( v14 == 24 )
                {
                  v38 = *v12;
                  v39 = v12[1];
                  v35 = v12 + 2;
                  *v18 = *v35;
                  v18[1] = v39;
                  v18[2] = v38;
                  v37 = v18 + 3;
                  *v37 = -1;
                }
                else
                {
                  if ( v14 != 32 )
                    goto LABEL_53;
                  v32 = *v12;
                  v33 = v12[1];
                  v34 = v12[2];
                  v35 = v12 + 3;
                  v36 = *v35;
                  *v18 = v34;
                  v18[1] = v33;
                  v18[2] = v32;
                  v37 = v18 + 3;
                  *v37 = v36;
                }
                ++v17;
                v18 = v37 + 1;
                v12 = v35 + 1;
                if ( v17 == v62 )
                {
                  v17 = 0;
                  if ( k <= 0 )
                    goto breakOut;
                  v31 -= 4 * v62;
                  --k;
                  v18 = v31;
                }
                ++v30;
              }
              while ( v30 < v29 );
            }
          }
        }
        while ( v17 < v62 );
      }
breakOut:
      ;
    }
  }
  if ( (v11 & 0x20) != 0 )
    R_VerticalFlip(data: *pic, width: v62, height: v63);
  return 1;
}


// ========================================================================
// ?R_LoadTGA@@YA_NPBDPAPAEPAH2PAI@Z
// EA  : 0x828C7DD0
// RVA : 0x008C7DD0
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

int __fastcall R_LoadTGA(const char *name, unsigned __int8 **pic, int *width, int *height, unsigned int *timestamp)
{
  unsigned int v11; // r3
  int TGA; // r31
  unsigned __int8 *v13; // [sp+50h] [-40h] BYREF

  if ( pic != nullptr )
  {
    *pic = nullptr;
    v11 = fileSystem->ReadFile(this: fileSystem, a2: name, a3: (void **)&v13, a4: timestamp);
    if ( v13 != nullptr )
    {
      TGA = R_LoadTGA(name, buffer: v13, bufferSize: v11, pic, width, height, timestamp);
      fileSystem->FreeFile(this: fileSystem, a2: v13);
      return TGA;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if ( timestamp != nullptr )
      *timestamp = fileSystem->GetTimestamp(this: fileSystem, a2: name, a3: false);
    return 1;
  }
}


// ========================================================================
// ?R_LoadPNG@@YA_NPBDPAPAEPAH2PAI@Z
// EA  : 0x828C7EC8
// RVA : 0x008C7EC8
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

int __fastcall R_LoadPNG(const char *name, unsigned __int8 **pic, int *width, int *height, unsigned int *timestamp)
{
  idFile *v10; // r3
  idFile *file; // r11
  unsigned int v13; // r3
  png_struct_def *v14; // r3
  unsigned int v15; // r11
  int *buffer; // r28
  int *v17; // r10
  unsigned int v18; // r8
  int *v19; // [sp+8h] [-D8h]
  png_struct_def *v20; // [sp+60h] [-80h] BYREF
  idFileLocal v21; // [sp+64h] [-7Ch] BYREF
  unsigned int v22; // [sp+68h] [-78h] BYREF
  int v23; // [sp+6Ch] [-74h] BYREF
  png_info_struct *info_struct; // [sp+70h] [-70h] BYREF
  int v25; // [sp+74h] [-6Ch] BYREF
  int v26; // [sp+78h] [-68h] BYREF
  int v27; // [sp+80h] [-60h] BYREF
  int v28; // [sp+84h] [-5Ch] BYREF
  unsigned __int8 v29[8]; // [sp+88h] [-58h] BYREF
  idTempArray<int> v30; // [sp+90h] [-50h] BYREF

  if ( pic != nullptr )
  {
    *pic = nullptr;
    if ( width == nullptr )
      goto LABEL_8;
  }
  else if ( width == nullptr )
  {
    if ( height == nullptr )
    {
      if ( timestamp != nullptr )
        *timestamp = ((int (__fastcall *)(idFileSystem *, const char *))fileSystem->GetTimestamp)(
                       a1: fileSystem,
                       a2: name);
      return 1;
    }
LABEL_9:
    *height = 0;
LABEL_10:
    v10 = fileSystem->OpenFileRead(this: fileSystem, a2: name, a3: 1, a4: 0);
    file = v10;
    v21.file = v10;
    if ( v10 != nullptr )
    {
      if ( timestamp != nullptr )
      {
        v13 = v10->Timestamp(this: v10);
        file = v21.file;
        *timestamp = v13;
      }
      file->Read(this: file, a2: v29, a3: 8u);
      if ( png_sig_cmp(sig: v29, start: 0, num_to_check: 8u) != 0 )
      {
        idLib::Warning(fmt: "%s is not a png file.", name);
        idFileLocal::~idFileLocal(this: &v21);
        return 0;
      }
      v14 = png_create_read_struct(user_png_ver: "1.2.29", error_ptr: nullptr, error_fn: nullptr, warn_fn: nullptr);
      v20 = v14;
      if ( v14 != nullptr )
      {
        png_set_sig_bytes(png_ptr: v14, num_bytes: 8);
        info_struct = png_create_info_struct(png_ptr: v20);
        if ( info_struct == nullptr )
        {
          png_destroy_read_struct(png_ptr_ptr: &v20, info_ptr_ptr: nullptr, end_info_ptr_ptr: nullptr);
          idFileLocal::~idFileLocal(this: &v21);
          return 0;
        }
        png_set_read_fn(png_ptr: v20, io_ptr: v21.file, read_data_fn: user_read_data);
        png_read_info(png_ptr: v20, info_ptr: info_struct);
        png_get_IHDR(
          png_ptr: v20,
          info_ptr: info_struct,
          width: (unsigned int *)&v23,
          height: &v22,
          bit_depth: &v26,
          color_type: &v25,
          interlace_type: &v28,
          compression_type: &v27,
          filter_type: v19);
        if ( width != nullptr )
          *width = v23;
        if ( height != nullptr )
          *height = v22;
        if ( pic != nullptr )
        {
          if ( v26 == 16 )
            png_set_strip_16(png_ptr: v20);
          if ( v25 == 3 )
            png_set_palette_to_rgb(png_ptr: v20);
          if ( v25 == 2 )
            png_set_filler(png_ptr: v20, filler: 0xFFu, filler_loc: 1);
          *pic = (unsigned __int8 *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_files.cpp(769) : TAG_IMAGE",
                                      size: 4 * v23 * v22,
                                      tag: TAG_IMAGE,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
          idTempArray<int>::idTempArray<int>(this: &v30, num: v22);
          v15 = 0;
          buffer = v30.buffer;
          if ( v22 != 0 )
          {
            v17 = v30.buffer - 1;
            do
            {
              v18 = 4 * v15 * v23;
              ++v15;
              *++v17 = (int)&(*pic)[v18];
            }
            while ( v15 < v22 );
          }
          png_read_image(png_ptr: v20, image: (unsigned __int8 **)buffer);
          if ( buffer != nullptr )
            idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        }
        png_destroy_read_struct(png_ptr_ptr: &v20, info_ptr_ptr: &info_struct, end_info_ptr_ptr: nullptr);
        idFileLocal::~idFileLocal(this: &v21);
        return 1;
      }
    }
    idFileLocal::~idFileLocal(this: &v21);
    return 0;
  }
  *width = 0;
LABEL_8:
  if ( height == nullptr )
    goto LABEL_10;
  goto LABEL_9;
}


// ========================================================================
// __unwind$224581
// EA  : 0x828C8204
// RVA : 0x008C8204
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_224581()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 224 + 100));
}


// ========================================================================
// R_WritePNGToFile
// EA  : 0x828C8238
// RVA : 0x008C8238
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

int __fastcall R_WritePNGToFile(
        idFile *f,
        const unsigned __int8 *data,
        unsigned int width,
        int height,
        bool flipVertical)
{
  int v5; // r28
  png_info_struct *v11; // r26
  png_struct_def *v12; // r3
  int valueInteger; // r11
  int v15; // ctr
  int *p_int_y_blue; // r10
  const unsigned __int8 *v17; // r11
  int *v18; // r10
  int v19; // ctr
  const unsigned __int8 *v20; // r11
  int v21; // [sp+8h] [-B8h]
  png_struct_def *v22; // [sp+60h] [-60h] BYREF
  png_info_struct *v23[23]; // [sp+64h] [-5Ch] BYREF

  v23[2] = (png_info_struct *)height;
  v5 = 4 * height;
  v11 = (png_info_struct *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                             size: 4 * height,
                             tag: TAG_TEMP,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v23[1] = v11;
  v12 = png_create_write_struct_2(
          user_png_ver: "1.2.29",
          error_ptr: nullptr,
          error_fn: R_WritePNGUserError,
          warn_fn: R_WritePNGUserWarning,
          mem_ptr: nullptr,
          malloc_fn: R_WritePNGUserMemAlloc,
          free_fn: (void (__fastcall *)(png_struct_def *, void *))ZlibFree);
  v22 = v12;
  if ( v12 == nullptr )
  {
    idLib::Warning(fmt: "[%s]: writing failed, couldn't create write struct", "R_WritePNGToFile");
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    return 0;
  }
  valueInteger = image_pngCompressionLevel.valueInteger;
  if ( image_pngCompressionLevel.valueInteger != -1 )
  {
    if ( image_pngCompressionLevel.valueInteger <= 9 )
    {
      if ( image_pngCompressionLevel.valueInteger < 0 )
        valueInteger = 0;
    }
    else
    {
      valueInteger = 9;
    }
    v12->flags |= 2u;
    v22->zlib_level = valueInteger;
    v12 = v22;
  }
  v23[0] = png_create_info_struct(png_ptr: v12);
  if ( v23[0] != nullptr )
  {
    png_set_write_fn(png_ptr: v22, io_ptr: f, write_data_fn: R_WritePNGUserWrite, output_flush_fn: R_WritePNGUserFlush);
    png_set_IHDR(
      png_ptr: v22,
      info_ptr: v23[0],
      width,
      height,
      bit_depth: 8,
      color_type: 6,
      interlace_type: 0,
      compression_type: 0,
      filter_type: v21);
    png_write_info(png_ptr: v22, info_ptr: v23[0]);
    if ( flipVertical )
    {
      if ( height > 0 )
      {
        v15 = height;
        p_int_y_blue = &v11[-1].int_y_blue;
        v17 = &data[(v5 - 4) * width];
        do
        {
          *++p_int_y_blue = (int)v17;
          v17 -= 4 * width;
          --v15;
        }
        while ( v15 != 0 );
      }
    }
    else if ( height > 0 )
    {
      v18 = &v11[-1].int_y_blue;
      v19 = height;
      v20 = data;
      do
      {
        *++v18 = (int)v20;
        v20 += 4 * width;
        --v19;
      }
      while ( v19 != 0 );
    }
    png_write_image(png_ptr: v22, image: (unsigned __int8 **)v11);
    png_write_end(png_ptr: v22, info_ptr: v23[0]);
    png_destroy_write_struct(png_ptr_ptr: &v22, info_ptr_ptr: v23);
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    return 1;
  }
  else
  {
    png_destroy_write_struct(png_ptr_ptr: &v22, info_ptr_ptr: nullptr);
    idLib::Warning(fmt: "[%s]: writing failed, couldn't create info struct", "R_WritePNGToFile");
    if ( v11 == nullptr )
      return 0;
    idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    return 0;
  }
}


// ========================================================================
// __unwind$224679
// EA  : 0x828C84A4
// RVA : 0x008C84A4
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_224679()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 192 + 104));
}


// ========================================================================
// ?R_WritePNG@@YA_NPBDPBEHH_NW4fsPath_t@@@Z
// EA  : 0x828C84D0
// RVA : 0x008C84D0
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

int __fastcall R_WritePNG(
        const char *filename,
        const unsigned __int8 *data,
        unsigned int width,
        int height,
        bool flipVertical,
        fsPath_t basePath)
{
  idFile *v11; // r3
  idFile *v12; // r31
  int v14; // r30

  v11 = fileSystem->OpenFileWrite(this: fileSystem, a2: filename, a3: basePath);
  v12 = v11;
  if ( v11 != nullptr )
  {
    v14 = R_WritePNGToFile(f: v11, data, width, height, flipVertical);
    ((void (__fastcall *)(idFile *, int))v12->dtr_idFile)(a1: v12, a2: 1);
    return v14;
  }
  else
  {
    idLib::Warning(fmt: "R_WritePNG: writing '%s' failed, couldn't open output file", filename);
    return 0;
  }
}


// ========================================================================
// ?R_WriteJPG@@YA_NPBDPBEHHW4fsPath_t@@_N@Z
// EA  : 0x828C8580
// RVA : 0x008C8580
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

int __fastcall R_WriteJPG(
        const char *filename,
        const unsigned __int8 *data,
        int width,
        int height,
        fsPath_t basePath,
        bool useMarkers)
{
  idFile *v12; // r30
  char *buffer; // r28
  unsigned int v15; // [sp+50h] [-3890h] BYREF
  idTempArray<char> v16; // [sp+58h] [-3888h] BYREF
  idStr v17; // [sp+60h] [-3880h] BYREF
  idBareDctEncoder v18; // [sp+80h] [-3860h] BYREF

  if ( width < 16 || height < 16 )
  {
    idLib::Printf(fmt: "R_WriteJPG( %s, %i, %i ) : can't write < 16x16 jpgs\n", filename, width, height);
    return 0;
  }
  idStr::idStr(this: &v17, text: filename);
  v12 = fileSystem->OpenFileWrite(this: fileSystem, a2: v17.data, a3: basePath);
  if ( v12 == nullptr )
  {
    idLib::Warning(fmt: "R_WriteJPG: writing '%s' failed", filename);
    idStr::FreeData(this: &v17);
    return 0;
  }
  idTempArray<char>::idTempArray<char>(this: &v16, num: 4 * width * height);
  idBareDctEncoder::idBareDctEncoder(this: &v18);
  idBareDctBase::SetQuality_Generic(
    this: &v18,
    luminanceQuality: image_screenshotQuality.valueInteger,
    chrominanceQuality: image_screenshotQuality.valueInteger,
    alphaQuality: image_screenshotQuality.valueInteger);
  buffer = v16.buffer;
  v15 = 0;
  idBareDctEncoder::CompressImageRGB_JPEG(
    this: &v18,
    inBuf: data,
    outBuf: (unsigned __int8 *)v16.buffer,
    width,
    height,
    outputBytes: (int *)&v15,
    useMarkers_: useMarkers);
  v12->Write(this: v12, a2: buffer, a3: v15);
  ((void (__fastcall *)(idFile *, int))v12->dtr_idFile)(a1: v12, a2: 1);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v18);
  if ( buffer != nullptr )
    idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  idStr::FreeData(this: &v17);
  return 1;
}


// ========================================================================
// __unwind$224860
// EA  : 0x828C8704
// RVA : 0x008C8704
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_224860()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 14560 + 96));
}


// ========================================================================
// __unwind$224861
// EA  : 0x828C872C
// RVA : 0x008C872C
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_224861()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 14560 + 88));
}


// ========================================================================
// __unwind$224862
// EA  : 0x828C8754
// RVA : 0x008C8754
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_224862()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 14560 + 128));
}


// ========================================================================
// ?R_WriteTGA@@YA_NPBDPBEHHH_N2W4fsPath_t@@@Z
// EA  : 0x828C8788
// RVA : 0x008C8788
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

int __fastcall R_WriteTGA(
        const char *filename,
        char *data,
        int width,
        int height,
        int depth,
        bool flipVertical,
        bool swapRGB,
        fsPath_t basePath)
{
  idFile *v16; // r3
  char *buffer; // r26
  int v18; // r27
  const unsigned __int8 *v19; // r28
  char *v20; // r10
  int v21; // ctr
  const unsigned __int8 *v22; // r11
  char v23; // r6
  void (*Write)(void); // ctr
  char *v25; // r10
  int v26; // ctr
  const unsigned __int8 *v27; // r11
  char v28; // r7
  idFileLocal v29[2]; // [sp+50h] [-90h] BYREF
  idTempArray<char> v30; // [sp+58h] [-88h] BYREF
  _BYTE v31[128]; // [sp+60h] [-80h] BYREF

  if ( depth != 1 && depth != 3 && depth != 4 )
  {
    idLib::Warning(fmt: "R_WriteTGA: unsupported image depth: %d", depth);
    return 0;
  }
  v16 = fileSystem->OpenFileWrite(this: fileSystem, a2: filename, a3: basePath);
  v29[0].file = v16;
  if ( v16 == nullptr )
  {
    idLib::Warning(fmt: "R_WriteTGA: creating memory file failed for %s", filename);
    idFileLocal::~idFileLocal(this: v29);
    return 0;
  }
  memset(v31, 0, 12);
  v31[17] = 0;
  v31[12] = width;
  *(_WORD *)&v31[1] = (unsigned __int8)(((_cntlzw(depth - 1) & 0x20) != 0) + 2);
  v31[13] = BYTE2(width);
  v31[15] = BYTE2(height);
  v31[14] = height;
  v31[16] = 8 * depth;
  if ( !flipVertical )
    v31[17] = 32;
  v16->Write(this: v16, a2: v31, a3: 18u);
  idTempArray<char>::idTempArray<char>(this: &v30, num: 4 * width);
  buffer = v30.buffer;
  if ( height > 0 )
  {
    v18 = v30.buffer - data;
    v19 = (const unsigned __int8 *)(data + 1);
    do
    {
      if ( swapRGB )
      {
        if ( depth == 4 )
        {
          if ( width > 0 )
          {
            v20 = buffer - 1;
            v21 = width;
            v22 = v19;
            do
            {
              v20[1] = v22[1];
              v22[v18] = *v22;
              v20[3] = *(v22 - 1);
              v23 = v22[2];
              v22 += 4;
              v20 += 4;
              *v20 = v23;
              --v21;
            }
            while ( v21 != 0 );
          }
          Write = (void (*)(void))v29[0].file->Write;
          goto LABEL_22;
        }
        if ( depth == 3 && width > 0 )
        {
          v25 = buffer - 1;
          v26 = width;
          v27 = v19;
          do
          {
            v25[1] = v27[1];
            v27[v18] = *v27;
            v28 = *(v27 - 1);
            v27 += 3;
            v25 += 3;
            *v25 = v28;
            --v26;
          }
          while ( v26 != 0 );
        }
      }
      Write = (void (*)(void))v29[0].file->Write;
LABEL_22:
      Write();
      --height;
      v19 += width * depth;
      v18 -= width * depth;
    }
    while ( height != 0 );
  }
  if ( buffer != nullptr )
    idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  idFileLocal::~idFileLocal(this: v29);
  return 1;
}


// ========================================================================
// __unwind$224938
// EA  : 0x828C89EC
// RVA : 0x008C89EC
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_224938()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$224939
// EA  : 0x828C8A14
// RVA : 0x008C8A14
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_224939()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 224 + 88));
}


// ========================================================================
// ?R_LoadImageDimensions@@YAXPBDPAH1PAI@Z
// EA  : 0x828C8A48
// RVA : 0x008C8A48
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __fastcall R_LoadImageDimensions(const char *name, int *width, int *height, unsigned int *timestamp)
{
  int v8; // r29
  bool v9; // r24
  BOOL v10; // r30
  __int64 v11; // r10
  __int64 v12; // r8
  const char **v13; // r30
  __int64 v14; // r6
  va *v15; // r3
  idFile *v16; // r3
  idFile *v17; // r30
  char v18; // r8
  char v19; // r7
  char v20; // r9
  char v21; // r9
  char v22; // r8
  char v23; // r7
  idFile *v24; // r3
  idFile *v25; // r30
  int v26; // [sp+8h] [-1568h]
  int v27; // [sp+Ch] [-1564h]
  int v28; // [sp+10h] [-1560h]
  int v29; // [sp+14h] [-155Ch]
  int v30; // [sp+18h] [-1558h]
  int v31; // [sp+1Ch] [-1554h]
  int v32; // [sp+60h] [-1510h] BYREF
  unsigned __int16 v33; // [sp+64h] [-150Ch] BYREF
  unsigned __int16 v34; // [sp+66h] [-150Ah] BYREF
  int v35; // [sp+68h] [-1508h] BYREF
  unsigned __int16 v36; // [sp+6Ch] [-1504h] BYREF
  unsigned __int16 v37; // [sp+6Eh] [-1502h] BYREF
  unsigned __int16 v38; // [sp+70h] [-1500h] BYREF
  char v39; // [sp+72h] [-14FEh] BYREF
  char v40; // [sp+73h] [-14FDh] BYREF
  idStr v41; // [sp+80h] [-14F0h] BYREF
  idStr v42; // [sp+A0h] [-14D0h] BYREF
  _WORD v43[544]; // [sp+C0h] [-14B0h] BYREF
  va v44; // [sp+500h] [-1070h] BYREF

  idStr::idStr(this: &v41, text: name);
  v8 = 0;
  if ( width != nullptr && height != nullptr )
  {
    *height = 0;
    *width = 0;
  }
  if ( timestamp != nullptr )
    *timestamp = -1;
  v9 = idLib::dontTrack;
  idLib::dontTrack = true;
  v10 = (_cntlzw(idStr::GetFileExtension(this: &v42, result: &v41)->len) & 0x20) != 0;
  idStr::FreeData(this: &v42);
  if ( v10 )
  {
    if ( imageExtensions[0] == nullptr )
      goto LABEL_13;
    v13 = imageExtensions;
    while ( 1 )
    {
      HIDWORD(v14) = v41.data;
      LODWORD(v14) = *v13;
      v15 = va::va(
              this: &v44,
              fmt: "%s.%s",
              a3: v14,
              a4: v12,
              a5: v11,
              a6: v26,
              a7: v27,
              a8: v28,
              a9: v29,
              a10: v30,
              a11: v31);
      LODWORD(v12) = fileSystem->FileExists(this: fileSystem, a2: (const char *)v15, a3: true);
      if ( (_DWORD)v12 != 0 )
        break;
      v13 = &imageExtensions[++v8];
      if ( *v13 == nullptr )
        goto LABEL_13;
    }
    if ( *v13 == nullptr )
    {
LABEL_13:
      idLib::dontTrack = v9;
      goto LABEL_44;
    }
    idStr::DefaultFileExtension(this: &v41, extension: *v13);
  }
  idLib::dontTrack = v9;
  if ( idStr::Find(searchIn: v41.data, searchFor: ".png", casesensitive: true, start: 0, end: v41.len) == -1 )
  {
    if ( idStr::Find(searchIn: v41.data, searchFor: ".bmp", casesensitive: true, start: 0, end: v41.len) == -1 )
    {
      if ( idStr::Find(searchIn: v41.data, searchFor: ".tga", casesensitive: true, start: 0, end: v41.len) != -1 )
      {
        v24 = fileSystem->OpenFileRead(this: fileSystem, a2: v41.data, a3: 1, a4: 0);
        v25 = v24;
        if ( v24 != nullptr )
        {
          if ( timestamp != nullptr )
            *timestamp = v24->Timestamp(this: v24);
          v25->Read(this: v25, a2: &v32, a3: 1u);
          v25->Read(this: v25, a2: (char *)&v32 + 1, a3: 1u);
          v25->Read(this: v25, a2: (char *)&v32 + 2, a3: 1u);
          idFile::ReadLittle<unsigned short>(this: v25, c: &v33);
          idFile::ReadLittle<unsigned short>(this: v25, c: &v34);
          v25->Read(this: v25, a2: &v35, a3: 1u);
          idFile::ReadLittle<unsigned short>(this: v25, c: (unsigned __int16 *)&v35 + 1);
          idFile::ReadLittle<unsigned short>(this: v25, c: &v36);
          idFile::ReadLittle<unsigned short>(this: v25, c: &v37);
          idFile::ReadLittle<unsigned short>(this: v25, c: &v38);
          v25->Read(this: v25, a2: &v39, a3: 1u);
          v25->Read(this: v25, a2: &v40, a3: 1u);
          ((void (__fastcall *)(idFile *, int))v25->dtr_idFile)(a1: v25, a2: 1);
          if ( BYTE2(v32) == 2 || BYTE2(v32) == 10 || BYTE2(v32) == 3 )
          {
            if ( BYTE1(v32) != 0 )
            {
              idLib::Warning(fmt: "R_LoadImageDimensions( %s ): colormaps not supported", name);
            }
            else if ( v39 == 32 || v39 == 24 || BYTE2(v32) == 3 )
            {
              if ( width != nullptr )
                *width = v37;
              if ( height != nullptr )
                *height = v38;
            }
            else
            {
              idLib::Warning(
                fmt: "R_LoadImageDimensions( %s ): Only 32 or 24 bit images supported (no colormaps)",
                name);
            }
          }
          else
          {
            idLib::Warning(
              fmt: "R_LoadImageDimensions( %s ): Only type 2 (RGB), 3 (gray), and 10 (RGB) TGA images supported",
              name);
          }
        }
      }
    }
    else
    {
      v16 = fileSystem->OpenFileRead(this: fileSystem, a2: v41.data, a3: 1, a4: 0);
      v17 = v16;
      if ( v16 != nullptr )
      {
        if ( timestamp != nullptr )
          *timestamp = v16->Timestamp(this: v16);
        v17->Read(this: v17, a2: v43, a3: 1080u);
        if ( width != nullptr )
        {
          *width = *(_DWORD *)&v43[9];
          v18 = *(_BYTE *)width;
          v19 = *((_BYTE *)width + 3);
          v20 = *((_BYTE *)width + 1);
          *((_BYTE *)width + 1) = *((_BYTE *)width + 2);
          *(_BYTE *)width = v19;
          *((_BYTE *)width + 3) = v18;
          *((_BYTE *)width + 2) = v20;
        }
        if ( height != nullptr )
        {
          *height = *(_DWORD *)&v43[11];
          v21 = *((_BYTE *)height + 3);
          v22 = *((_BYTE *)height + 1);
          v23 = *((_BYTE *)height + 2);
          *((_BYTE *)height + 3) = *(_BYTE *)height;
          *(_BYTE *)height = v21;
          *((_BYTE *)height + 2) = v22;
          *((_BYTE *)height + 1) = v23;
        }
        ((void (__fastcall *)(idFile *, int))v17->dtr_idFile)(a1: v17, a2: 1);
      }
    }
  }
  else
  {
    R_LoadPNG(name, pic: nullptr, width, height, timestamp);
  }
LABEL_44:
  idStr::FreeData(this: &v41);
}


// ========================================================================
// __unwind$225074
// EA  : 0x828C8F20
// RVA : 0x008C8F20
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_225074()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5488 + 128));
}


// ========================================================================
// __unwind$225075
// EA  : 0x828C8F48
// RVA : 0x008C8F48
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_225075()
{
  int v0; // r12

  idScopedDontTrack::~idScopedDontTrack(this: (idScopedDontTrack *)(v0 - 5488 + 80));
}


// ========================================================================
// ?R_LoadImage@@YAXPBDPAPAEPAH2PAI@Z
// EA  : 0x828C8F78
// RVA : 0x008C8F78
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __fastcall R_LoadImage(const char *cname, unsigned __int8 **pic, int *width, int *height, unsigned int *timestamp)
{
  bool v10; // r21
  BOOL v11; // r30
  __int64 v12; // r10
  __int64 v13; // r8
  int v14; // r29
  const char **v15; // r30
  __int64 v16; // r6
  va *v17; // r3
  int v18; // [sp+8h] [-1128h]
  int v19; // [sp+Ch] [-1124h]
  int v20; // [sp+10h] [-1120h]
  int v21; // [sp+14h] [-111Ch]
  int v22; // [sp+18h] [-1118h]
  int v23; // [sp+1Ch] [-1114h]
  idStr v24; // [sp+60h] [-10D0h] BYREF
  idStr v25; // [sp+80h] [-10B0h] BYREF
  idStr v26; // [sp+A0h] [-1090h] BYREF
  va v27; // [sp+C0h] [-1070h] BYREF

  idStr::idStr(this: &v24, text: cname);
  if ( pic != nullptr )
    *pic = nullptr;
  if ( timestamp != nullptr )
    *timestamp = -1;
  if ( width != nullptr )
    *width = 0;
  if ( height != nullptr )
    *height = 0;
  if ( pic == nullptr && (width != nullptr || height != nullptr) )
  {
    R_LoadImageDimensions(name: cname, width, height, timestamp);
  }
  else
  {
    v10 = idLib::dontTrack;
    idLib::dontTrack = true;
    v11 = (_cntlzw(idStr::GetFileExtension(this: &v26, result: &v24)->len) & 0x20) != 0;
    idStr::FreeData(this: &v26);
    if ( v11 )
    {
      v14 = 0;
      if ( imageExtensions[0] == nullptr )
        goto LABEL_20;
      v15 = imageExtensions;
      while ( 1 )
      {
        HIDWORD(v16) = v24.data;
        LODWORD(v16) = *v15;
        v17 = va::va(
                this: &v27,
                fmt: "%s.%s",
                a3: v16,
                a4: v13,
                a5: v12,
                a6: v18,
                a7: v19,
                a8: v20,
                a9: v21,
                a10: v22,
                a11: v23);
        LODWORD(v13) = fileSystem->FileExists(this: fileSystem, a2: (const char *)v17, a3: true);
        if ( (_DWORD)v13 != 0 )
          break;
        v15 = &imageExtensions[++v14];
        if ( *v15 == nullptr )
          goto LABEL_20;
      }
      if ( *v15 == nullptr )
      {
LABEL_20:
        idLib::dontTrack = v10;
        goto _M225684_1;
      }
      idStr::DefaultFileExtension(this: &v24, extension: *v15);
    }
    idLib::dontTrack = v10;
    idStr::ToLower(this: &v24);
    v25.len = 0;
    v25.allocedAndFlag = 20;
    v25.data = v25.baseBuffer;
    v25.baseBuffer[0] = 0;
    idStr::ExtractFileExtension(this: &v24, dest: &v25);
    if ( idStr::Cmp(s1: v25.data, s2: "tga") != 0 )
    {
      if ( idStr::Cmp(s1: v25.data, s2: "bmp") != 0 )
      {
        if ( idStr::Cmp(s1: v25.data, s2: "png") != 0 )
          idLib::Warning(fmt: "Unknown image extension on: %s", v24.data);
        else
          R_LoadPNG(name: v24.data, pic, width, height, timestamp);
      }
      else
      {
        R_LoadBMP(name: v24.data, pic, width, height, timestamp);
      }
    }
    else
    {
      R_LoadTGA(name: v24.data, pic, width, height, timestamp);
    }
    if ( (width != nullptr && *width < 1 || height != nullptr && *height < 1) && pic != nullptr && *pic != nullptr )
    {
      idMem::Free(this: &mem, ptr: *pic, align: ALIGN_16);
      *pic = nullptr;
    }
    idStr::FreeData(this: &v25);
  }
_M225684_1:
  idStr::FreeData(this: &v24);
}


// ========================================================================
// __unwind$225563_0
// EA  : 0x828C923C
// RVA : 0x008C923C
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_225563_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 96));
}


// ========================================================================
// __unwind$225564
// EA  : 0x828C9264
// RVA : 0x008C9264
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_225564()
{
  int v0; // r12

  idScopedDontTrack::~idScopedDontTrack(this: (idScopedDontTrack *)(v0 - 4400 + 80));
}


// ========================================================================
// __unwind$225566
// EA  : 0x828C928C
// RVA : 0x008C928C
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void _unwind_225566()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 128));
}


// ========================================================================
// ?TestLoadImage_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828C92B8
// RVA : 0x008C92B8
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __fastcall TestLoadImage_f(const idCmdArgs *args)
{
  const char *v1; // r3
  unsigned int v2; // [sp+50h] [-20h] BYREF
  int v3; // [sp+54h] [-1Ch] BYREF
  int v4; // [sp+58h] [-18h] BYREF
  unsigned __int8 *v5; // [sp+5Ch] [-14h] BYREF

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  R_LoadImage(cname: v1, pic: &v5, width: &v4, height: &v3, timestamp: &v2);
  idLib::Printf(fmt: "%i x %i, timestamp %u\n", v4, v3, v2);
  if ( v5 != nullptr )
    idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
}


// ========================================================================
// `dynamic initializer for 'image_screenshotQuality''
// EA  : 0x8334BF38
// RVA : 0x0134BF38
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__image_screenshotQuality__()
{
  idCVar::idCVar(
    this: &image_screenshotQuality,
    name: "image_screenshotQuality",
    value: "75",
    flags: 2,
    description: "sets the compression quality for jpeg screenshots, 100 is best quality",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__image_screenshotQuality__);
}


// ========================================================================
// `dynamic initializer for 'image_watermark''
// EA  : 0x8334BF90
// RVA : 0x0134BF90
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__image_watermark__()
{
  idCVar::idCVar(
    this: &image_watermark,
    name: "image_watermark",
    value: &byte_8200D768,
    flags: 0,
    description: "places a watermark each image with a watermark",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__image_watermark__);
}


// ========================================================================
// `dynamic initializer for 'image_pngCompressionLevel''
// EA  : 0x8334BFE8
// RVA : 0x0134BFE8
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__image_pngCompressionLevel__()
{
  idCVar::idCVar(
    this: &image_pngCompressionLevel,
    name: "image_pngCompressionLevel",
    value: "1",
    flags: 2,
    description: "CompressionLevel for png [0-9], or -1 for default",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__image_pngCompressionLevel__);
}


// ========================================================================
// `dynamic initializer for 'TestLoadImage_v''
// EA  : 0x8334C040
// RVA : 0x0134C040
// PDB : w:\tech5\engine\renderer\imagetools\image_files.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestLoadImage_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestLoadImage_v,
           cmdName: "TestLoadImage",
           function: TestLoadImage_f,
           description: "Tries to load an image with type based on the extension",
           argCompletion: nullptr);
}

