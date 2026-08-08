
// ========================================================================
// ?AddDeclarationForVertexFormat@idDeclRenderProg@@AAAHIPAUD3DVertexShader@@@Z
// EA  : 0x828B2BE8
// RVA : 0x008B2BE8
// PDB : w:\tech5\engine\renderer\declrenderprog_d3d_360.cpp
// ========================================================================

int __fastcall idDeclRenderProg::AddDeclarationForVertexFormat(
        idDeclRenderProg *this,
        unsigned int storedVertexMask,
        D3DVertexShader *vertexShaderD3D)
{
  unsigned int v3; // r10
  int v5; // r31
  unsigned int *p_vertexMask; // r11
  int numVertexDeclarations; // r11
  int v8; // r11
  char *v10; // r30
  D3DResource *v11; // r3

  v3 = storedVertexMask;
  v5 = 0;
  p_vertexMask = &this->vertexDeclarations.ptr[0].vertexMask;
  while ( *p_vertexMask != storedVertexMask )
  {
    ++v5;
    p_vertexMask += 2;
    if ( v5 >= 4 )
      goto LABEL_6;
  }
  if ( v5 < 0 )
  {
LABEL_6:
    numVertexDeclarations = this->numVertexDeclarations;
    if ( numVertexDeclarations >= 4 )
      idLib::Error(
        fmt: "Max vertex declarations exceeded for %s. Can not create declaration for format %d\n",
        this->name.str,
        storedVertexMask);
    this->vertexDeclarations.ptr[numVertexDeclarations].vertexMask = v3;
    this->vertexDeclarations.ptr[this->numVertexDeclarations].vertexShaderD3D = vertexShaderD3D;
    v8 = this->numVertexDeclarations + 1;
    this->numVertexDeclarations = v8;
    return v8 - 1;
  }
  v10 = (char *)this + 8 * v5;
  v11 = *((D3DResource **)v10 + 81);
  if ( v11 != nullptr )
  {
    D3DResource_Release(pResource: v11);
    *((_DWORD *)v10 + 81) = 0;
  }
  *((_DWORD *)v10 + 81) = vertexShaderD3D;
  return v5;
}


// ========================================================================
// ?FreeData@idDeclRenderProg@@UAAXXZ
// EA  : 0x828B2CB0
// RVA : 0x008B2CB0
// PDB : w:\tech5\engine\renderer\declrenderprog_d3d_360.cpp
// ========================================================================

void __fastcall idDeclRenderProg::FreeData(idDeclRenderProg *this)
{
  idArray<idDeclRenderProg::vertexDeclaration_t,4> *p_vertexDeclarations; // r31
  int i; // r29
  void *compiledVertexCode; // r4
  const idDeclRenderProg *inheritedFragmentProgram; // r11
  D3DPixelShader *fragmentShaderD3D; // r3

  if ( this->inheritedVertexProgram == nullptr )
  {
    p_vertexDeclarations = &this->vertexDeclarations;
    for ( i = 4; i != 0; --i )
    {
      if ( p_vertexDeclarations->ptr[0].vertexShaderD3D != nullptr )
      {
        D3DResource_Release(pResource: p_vertexDeclarations->ptr[0].vertexShaderD3D);
        p_vertexDeclarations->ptr[0].vertexShaderD3D = nullptr;
      }
      p_vertexDeclarations = (idArray<idDeclRenderProg::vertexDeclaration_t,4> *)((char *)p_vertexDeclarations + 8);
    }
    compiledVertexCode = this->compiledVertexCode;
    if ( compiledVertexCode != nullptr )
    {
      idMem::Free(this: &mem, ptr: compiledVertexCode, align: ALIGN_16);
      this->compiledVertexCode = nullptr;
    }
  }
  inheritedFragmentProgram = this->inheritedFragmentProgram;
  this->inheritedVertexProgram = nullptr;
  if ( inheritedFragmentProgram == nullptr )
  {
    fragmentShaderD3D = this->fragmentShaderD3D;
    if ( fragmentShaderD3D != nullptr )
    {
      D3DResource_Release(pResource: fragmentShaderD3D);
      this->fragmentShaderD3D = nullptr;
    }
  }
  this->inheritedFragmentProgram = nullptr;
  idDeclRenderProg::Clear(this, target: PT_PC);
}


// ========================================================================
// ?GetVertexProgramForVertexFormat@idDeclRenderProg@@ABAPAUD3DVertexShader@@I@Z
// EA  : 0x828B2D58
// RVA : 0x008B2D58
// PDB : w:\tech5\engine\renderer\declrenderprog_d3d_360.cpp
// ========================================================================

D3DVertexShader *__fastcall idDeclRenderProg::GetVertexProgramForVertexFormat(
        idDeclRenderProg *this,
        unsigned int storedVertexMask)
{
  int v2; // r11
  unsigned int *i; // r10

  v2 = 0;
  for ( i = &this->vertexDeclarations.ptr[0].vertexMask; *i != storedVertexMask; i += 2 )
  {
    if ( ++v2 >= 4 )
      return nullptr;
  }
  if ( v2 >= 0 )
    return this->vertexDeclarations.ptr[v2].vertexShaderD3D;
  else
    return nullptr;
}


// ========================================================================
// ?CreateVertexShaderForVertexFormat@idDeclRenderProg@@AAAXI@Z
// EA  : 0x828B2DA8
// RVA : 0x008B2DA8
// PDB : w:\tech5\engine\renderer\declrenderprog_d3d_360.cpp
// ========================================================================

void __fastcall idDeclRenderProg::CreateVertexShaderForVertexFormat(
        idDeclRenderProg *this,
        unsigned int storedVertexMask)
{
  idDeclRenderProg *v2; // r25
  idDeclRenderProg *v4; // r8
  unsigned int v5; // r4
  D3DVertexShader *VertexProgramForVertexFormat; // r3
  char *v7; // r24
  int v8; // r31
  unsigned int v9; // r29
  unsigned int v10; // r10
  int v11; // r11
  int v12; // r11
  int v13; // r7
  int v14; // r7
  int v15; // r7
  int v16; // r7
  int v17; // r6
  int v18; // r7
  D3DVertexDeclaration *VertexDeclaration; // r31
  unsigned int v20[6]; // [sp+58h] [-218h] BYREF
  _D3DVERTEXELEMENT9 v21[42]; // [sp+70h] [-200h] BYREF

  v2 = this;
  if ( this->compiledVertexCode != nullptr )
  {
    if ( this->inheritedVertexProgram != nullptr )
    {
      VertexProgramForVertexFormat = idDeclRenderProg::GetVertexProgramForVertexFormat(
                                       this: this->inheritedVertexProgram,
                                       storedVertexMask);
      if ( VertexProgramForVertexFormat == nullptr )
      {
        idDeclRenderProg::CreateVertexShaderForVertexFormat(this: v4, storedVertexMask: v5);
        VertexProgramForVertexFormat = idDeclRenderProg::GetVertexProgramForVertexFormat(
                                         this: v2->inheritedVertexProgram,
                                         storedVertexMask);
      }
      idDeclRenderProg::AddDeclarationForVertexFormat(
        this: v2,
        storedVertexMask,
        vertexShaderD3D: VertexProgramForVertexFormat);
    }
    else
    {
      v7 = (char *)this
         + 8 * idDeclRenderProg::AddDeclarationForVertexFormat(this, storedVertexMask, vertexShaderD3D: nullptr);
      *((_DWORD *)v7 + 81) = D3DDevice_CreateVertexShader(pFunction: (const unsigned int *)v2->compiledVertexCode);
      v8 = 0;
      v9 = 0;
      if ( (storedVertexMask & 1) != 0 )
      {
        v21[0].Stream = 0;
        v21[0].Offset = 0;
        if ( (storedVertexMask & 0x20) != 0 )
        {
          v9 = 8;
          v10 = 1712986;
        }
        else
        {
          v9 = 12;
          v10 = 2761657;
        }
        v21[0].Type = v10;
        v8 = 1;
        v21[0].Method = 0;
        v21[0].Usage = 0;
        v21[0].UsageIndex = 0;
      }
      if ( (storedVertexMask & 2) != 0 )
      {
        v11 = v8;
        v21[v11].Stream = 0;
        v21[v11].Offset = v9;
        if ( (storedVertexMask & 0x40) != 0 )
        {
          v9 += 4;
          v21[v11].Type = 2892633;
        }
        else
        {
          v9 += 8;
          v21[v11].Type = 2892709;
        }
        ++v8;
        v21[v11].Method = 0;
        v21[v11].Usage = 5;
        v21[v11].UsageIndex = 0;
      }
      if ( (storedVertexMask & 0x400) != 0 )
      {
        v12 = v8;
        v21[v12].Stream = 0;
        v21[v12].Offset = v9;
        if ( (storedVertexMask & 0x800) != 0 )
        {
          v9 += 4;
          v21[v12].Type = 2892633;
        }
        else
        {
          v9 += 8;
          v21[v12].Type = 2892709;
        }
        ++v8;
        v21[v12].Method = 0;
        v21[v12].Usage = 5;
        v21[v12].UsageIndex = 1;
      }
      if ( (storedVertexMask & 4) != 0 )
      {
        v13 = v8;
        v21[v13].Stream = 0;
        v21[v13].Offset = v9;
        v9 += 4;
        v21[v13].Type = 85126;
        ++v8;
        v21[v13].Method = 0;
        v21[v13].Usage = 3;
        v21[v13].UsageIndex = 0;
      }
      if ( (storedVertexMask & 0x10) != 0 )
      {
        v14 = v8;
        v21[v14].Stream = 0;
        v21[v14].Offset = v9;
        v9 += 4;
        v21[v14].Type = 85126;
        ++v8;
        v21[v14].Method = 0;
        v21[v14].Usage = 6;
        v21[v14].UsageIndex = 0;
      }
      if ( (storedVertexMask & 8) != 0 )
      {
        v15 = v8;
        v21[v15].Offset = v9;
        v21[v15].Stream = 0;
        v9 += 4;
        v21[v15].Method = 0;
        ++v8;
        v21[v15].Usage = 10;
        v21[v15].Type = 1712262;
        v21[v15].UsageIndex = 0;
      }
      if ( idStr::Find(
             searchIn: v2->vertexCode[2].data,
             searchFor: "position1",
             casesensitive: true,
             start: 0,
             end: v2->vertexCode[2].len) != -1 )
      {
        v2 = this;
        v16 = v8;
        v21[v16].Method = 0;
        v21[v16].Usage = 0;
        v21[v16 + 1].UsageIndex = 2;
        v21[v16].Offset = 0;
        v21[v16 + 1].Method = 0;
        v21[v16 + 1].Usage = 0;
        v21[v16].Type = 1713062;
        v21[v16].UsageIndex = 1;
        v21[v16].Stream = 1;
        v21[v16 + 1].Stream = 1;
        v21[v16 + 1].Type = 1713062;
        v21[v16 + 2].Stream = 1;
        v21[v16 + 2].Type = 1713062;
        v21[v16 + 1].Offset = 16;
        v8 += 3;
        v21[v16 + 2].Offset = 32;
        v21[v16 + 2].Method = 0;
        v21[v16 + 2].Usage = 0;
        v21[v16 + 2].UsageIndex = 3;
      }
      if ( (v2->vertexMask & 0x80) != 0 )
      {
        v17 = v8;
        v21[v17].Stream = 2;
        ++v8;
        v21[v17].Offset = 0;
        v21[v17].Type = 85126;
        v21[v17].Method = 0;
        v21[v17].Usage = 10;
        v21[v17].UsageIndex = 1;
      }
      v18 = v8;
      v21[v18].Offset = 0;
      v21[v18].Stream = 255;
      v21[v18].Type = -1;
      v21[v18].Method = 0;
      v21[v18].Usage = 0;
      v21[v18].UsageIndex = 0;
      v20[0] = v9;
      v20[1] = 48;
      v20[2] = 4;
      VertexDeclaration = D3DDevice_CreateVertexDeclaration(pVertexElements: v21);
      D3DVertexShader_Bind(
        pThis: *((D3DVertexShader **)v7 + 81),
        Flags: 0,
        pD3dVertexDeclaration: VertexDeclaration,
        pStreamStrides: v20,
        pD3dPixelShader: v2->fragmentShaderD3D);
      if ( VertexDeclaration != nullptr )
        D3DResource_Release(pResource: VertexDeclaration);
    }
  }
}


// ========================================================================
// ?ReportError@idDeclRenderProg@@AAAXPAUID3DXBuffer@@PBD1@Z
// EA  : 0x828B3268
// RVA : 0x008B3268
// PDB : w:\tech5\engine\renderer\declrenderprog_d3d_360.cpp
// ========================================================================

void __fastcall idDeclRenderProg::ReportError(
        idDeclRenderProg *this,
        ID3DXBuffer *pErrorMsg,
        const char *code,
        const char *extension)
{
  const char *str; // r27
  const char *FileName; // r3
  const char *v9; // r30
  idStr *list; // r21
  idStr *v11; // r24
  int num; // r22
  int v13; // r23
  idStr *v14; // r26
  int v15; // r3
  int v16; // r27
  int v17; // r11
  const char **p_data; // r29
  int v19; // r10
  int v20; // r30
  idList<idStr,5> v21; // [sp+50h] [-80h] BYREF
  idList<idStr,5> v22; // [sp+60h] [-70h] BYREF

  str = this->name.str;
  FileName = idDecl::GetFileName(this: &this->idDecl);
  idLib::Warning(fmt: "Error compiling %s program %s from %s.", extension, str, FileName);
  if ( pErrorMsg != nullptr )
  {
    v9 = (const char *)pErrorMsg->GetBufferPointer(this: pErrorMsg);
    idLib::Printf(fmt: "%s\n", v9);
    *(_WORD *)&v22.memTag = 1280;
    memset(&v22, 0, 14);
    *(_WORD *)&v21.memTag = 1280;
    memset(&v21, 0, 14);
    idStrListBreakupString(list: &v22, string: v9, separator: 10);
    idStrListBreakupString(list: &v21, string: code, separator: 10);
    list = v22.list;
    v11 = v21.list;
    if ( v22.num > 0 )
    {
      num = v22.num;
      v13 = v21.num;
      v14 = v22.list;
      do
      {
        if ( v14->len != 0 )
        {
          v15 = atol(nptr: (const char *)v14->data + 1);
          v16 = v15 - 1 + 3;
          v17 = __CFADD__(v15 - 4, 0x80000000) ? 0 : v15 - 4;
          p_data = (const char **)&v11[v17 - 1].data;
          while ( 1 )
          {
            v19 = v13;
            if ( v13 >= v16 )
              v19 = v16;
            if ( v17 >= v19 )
              break;
            v20 = v17 + 1;
            p_data += 8;
            idLib::Printf(fmt: "%3d: %s\n", v17 + 1, *p_data);
            v17 = v20;
          }
        }
        --num;
        ++v14;
      }
      while ( num != 0 );
    }
    idLib::Printf(fmt: "------------------------------------------\n");
    if ( (v21.listStatic == 0 || v21.listStatic == 2) && v11 != nullptr )
      idListArrayDelete<idStr>(ptr: v11, num: v21.size);
    if ( (v22.listStatic == 0 || v22.listStatic == 2) && list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: v22.size);
  }
}


// ========================================================================
// __unwind$230099
// EA  : 0x828B3440
// RVA : 0x008B3440
// PDB : w:\tech5\engine\renderer\declrenderprog_d3d_360.cpp
// ========================================================================

void _unwind_230099()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$230100
// EA  : 0x828B3468
// RVA : 0x008B3468
// PDB : w:\tech5\engine\renderer\declrenderprog_d3d_360.cpp
// ========================================================================

void _unwind_230100()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 208 + 80));
}


// ========================================================================
// ?UploadTargetCode@idDeclRenderProg@@AAAXXZ
// EA  : 0x828B3498
// RVA : 0x008B3498
// PDB : w:\tech5\engine\renderer\declrenderprog_d3d_360.cpp
// ========================================================================

void __fastcall idDeclRenderProg::UploadTargetCode(idDeclRenderProg *this)
{
  int len; // r4
  D3DPixelShader *fragmentShaderD3D; // r3
  unsigned __int64 glState; // r11
  char v5; // r27
  idFile *v6; // r3
  idFile *v7; // r29
  char *buffer; // r28
  D3DPixelShader *PixelShader; // r3
  char *data; // r5
  int v11; // r6
  int i; // r29
  char *v13; // r29
  unsigned int v14; // r28
  const char *v15; // r3
  HRESULT v16; // r3
  ID3DXBuffer *v17; // r4
  int v18; // r29
  bool v19; // r11
  const char *v20; // r3
  char *v21; // r3
  idFile *v22; // r3
  idFile *v23; // r29
  idFile_vtbl *v24; // r28
  unsigned int v25; // r27
  void *v26; // r3
  const unsigned int *v27; // r3
  char **p_vertexDeclarations; // r29
  int j; // r28
  char *v30; // r3
  void *compiledVertexCode; // r4
  D3DPixelShader *v32; // r11
  char v33; // r8
  bool v34; // r28
  idFile *v35; // r3
  idFile *v36; // r29
  void *v37; // r3
  unsigned int v38; // r5
  char *v39; // r5
  int v40; // r6
  int k; // r29
  unsigned int v42; // r28
  char *v43; // r29
  const char *v44; // r3
  HRESULT v45; // r3
  ID3DXBuffer *v46; // r4
  int v47; // r29
  bool v48; // r11
  const char *v49; // r3
  char *v50; // r3
  unsigned int v51; // r3
  void *v52; // r3
  ID3DXBuffer *v53; // r11
  size_t v54; // r29
  const void *v55; // r3
  idFile *v56; // r3
  idFile *v57; // r29
  idFile_vtbl *v58; // r28
  unsigned int v59; // r27
  void *v60; // r3
  ID3DXBuffer **v61; // [sp+8h] [-278h]
  ID3DXConstantTable **v62; // [sp+Ch] [-274h]
  ID3DXBuffer *v63; // [sp+60h] [-220h] BYREF
  ID3DXBuffer *v64; // [sp+64h] [-21Ch]
  unsigned int v65; // [sp+68h] [-218h] BYREF
  unsigned int v66; // [sp+6Ch] [-214h] BYREF
  idTempArray<char> v67; // [sp+70h] [-210h] BYREF
  unsigned int v68; // [sp+78h] [-208h] BYREF
  D3DPixelShader *v69; // [sp+7Ch] [-204h] BYREF
  int v70; // [sp+80h] [-200h] BYREF
  unsigned int v71; // [sp+84h] [-1FCh] BYREF
  const char *v72; // [sp+88h] [-1F8h]
  int v73; // [sp+8Ch] [-1F4h] BYREF
  unsigned int v74[4]; // [sp+90h] [-1F0h] BYREF
  idStr v75; // [sp+A0h] [-1E0h] BYREF
  idStr v76; // [sp+C0h] [-1C0h] BYREF
  char v77[416]; // [sp+E0h] [-1A0h] BYREF

  len = this->fragmentCode[2].len;
  v72 = "failed to write '%s'";
  if ( len != 0 )
  {
    if ( this->inheritedFragmentProgram == nullptr )
    {
      fragmentShaderD3D = this->fragmentShaderD3D;
      if ( fragmentShaderD3D == nullptr )
        goto LABEL_6;
      v69 = this->fragmentShaderD3D;
      D3DResource_Release(pResource: fragmentShaderD3D);
    }
    this->fragmentShaderD3D = nullptr;
LABEL_6:
    glState = this->glState;
    v5 = 1;
    this->inheritedFragmentProgram = nullptr;
    if ( (glState & 0x780) == 0x780 )
      this->isFastZ = idStr::Find(
                        searchIn: this->fragmentCode[2].data,
                        searchFor: "clip(",
                        casesensitive: false,
                        start: 0,
                        end: this->fragmentCode[2].len) == -1;
    v71 = MD5_BlockChecksum(data: this->fragmentCode[2].data, length: this->fragmentCode[2].len);
    fileSystem->FixLongFilename(
      this: fileSystem,
      a2: "generated/hlsl/",
      a3: "p360",
      a4: this->name.str,
      a5: v77,
      a6: 256);
    idStr::idStr(this: &v75, text: v77);
    if ( idLib::headless || this->isFastZ )
      v5 = 0;
    if ( v5 != 0 )
    {
      v6 = fileSystem->OpenFileRead(this: fileSystem, a2: v75.data, a3: 1, a4: 0);
      v7 = v6;
      if ( v6 != nullptr )
      {
        v73 = 0;
        v65 = 0;
        v6->Read(this: v6, a2: &v73, a3: 4u);
        v7->Read(this: v7, a2: &v65, a3: 4u);
        if ( idLib::production == PROD_PRODUCTION || v71 == v73 )
        {
          v5 = 0;
          idTempArray<char>::idTempArray<char>(this: &v67, num: v65);
          buffer = v67.buffer;
          v7->Read(this: v7, a2: v67.buffer, a3: v65);
          PixelShader = D3DDevice_CreatePixelShader(pFunction: (const unsigned int *)buffer);
          this->fragmentShaderD3D = PixelShader;
          if ( PixelShader == nullptr )
          {
            idLib::Printf(fmt: "CreatePixelShader from '%s' failed\n", v75.data);
            this->fragmentShaderD3D = nullptr;
          }
          if ( buffer != nullptr )
            idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        }
        else
        {
          idLib::Printf(fmt: "%s out of date, recompiling.\n", v75.data);
        }
        ((void (__fastcall *)(idFile *, int))v7->dtr_idFile)(a1: v7, a2: 1);
      }
      else
      {
        idLib::Printf(fmt: "%s not found, recompiling.\n", v75.data);
      }
    }
    v64 = nullptr;
    if ( v5 == 0 )
      goto LABEL_50;
    v63 = nullptr;
    if ( idLib::production == PROD_PRODUCTION )
      idLib::FatalError(fmt: "No compiled fragment program for %s", this->name.str);
    idStr::SetFileExtension(this: &v75, extension: "p360src");
    data = this->fragmentCode[2].data;
    v11 = 0;
    if ( *data != 0 )
    {
      do
        ++v11;
      while ( data[v11] != 0 );
    }
    v67.buffer = this->fragmentCode[2].data;
    ((void (__fastcall *)(idFileSystem *, char *))fileSystem->WriteFile)(a1: fileSystem, a2: v75.data);
    for ( i = 16; i != 0; --i )
      idStreamFileCache::OutOfMemoryCallback(this: streamFileCache);
    v13 = this->fragmentCode[2].data;
    v14 = 0;
    if ( *v13 != 0 )
    {
      do
        ++v14;
      while ( v13[v14] != 0 );
    }
    v67.buffer = this->fragmentCode[2].data;
    v15 = D3DXGetPixelShaderProfile(pDevice: d3d);
    v16 = D3DXCompileShader(
            pSrcData: v13,
            SrcDataSize: v14,
            pDefines: nullptr,
            pInclude: nullptr,
            pEntrypoint: "main",
            pTarget: v15,
            Flags: 0x201u,
            ppShader: &v63,
            ppErrorMsgs: v61,
            ppConstantTable: v62);
    v17 = v64;
    v18 = v16;
    if ( v64 != nullptr )
    {
      v20 = (const char *)v64->GetBufferPointer(this: v64);
      v21 = strstr(str1: v20, str2: "error");
      v17 = v64;
      v19 = v21 != nullptr;
    }
    else
    {
      v19 = false;
    }
    if ( v19 || v18 < 0 )
    {
      idDeclRenderProg::ReportError(this, pErrorMsg: v17, code: this->fragmentCode[2].data, extension: "fragment");
    }
    else
    {
      if ( v17 == nullptr )
        goto LABEL_43;
      idLib::Warning(fmt: "fragment program has warnings");
    }
    if ( v64 != nullptr )
    {
      v64->Release(this: v64);
      v64 = nullptr;
    }
LABEL_43:
    if ( this->resourceError == nullptr )
    {
      if ( v63 == nullptr )
      {
LABEL_50:
        idStr::FreeData(this: &v75);
        goto LABEL_51;
      }
      idStr::SetFileExtension(this: &v75, extension: "p360");
      v22 = fileSystem->OpenFileWrite(this: fileSystem, a2: v75.data, a3: 0);
      v23 = v22;
      if ( v22 != nullptr )
      {
        v22->Write(this: v22, a2: &v71, a3: 4u);
        v74[0] = v63->GetBufferSize(this: v63);
        v23->Write(this: v23, a2: v74, a3: 4u);
        v24 = v23->__vftable;
        v25 = v63->GetBufferSize(this: v63);
        v26 = v63->GetBufferPointer(this: v63);
        v24->Write(this: v23, a2: v26, a3: v25);
        ((void (__fastcall *)(idFile *, int))v23->dtr_idFile)(a1: v23, a2: 1);
      }
      else
      {
        idLib::Warning(fmt: v72, v75.data);
      }
    }
    if ( v63 != nullptr )
    {
      v27 = (const unsigned int *)v63->GetBufferPointer(this: v63);
      this->fragmentShaderD3D = D3DDevice_CreatePixelShader(pFunction: v27);
    }
    goto LABEL_50;
  }
LABEL_51:
  if ( this->vertexCode[2].len == 0 )
    return;
  if ( this->inheritedVertexProgram != nullptr )
  {
    this->vertexDeclarations.ptr[0].vertexShaderD3D = nullptr;
    this->vertexDeclarations.ptr[1].vertexShaderD3D = nullptr;
    this->vertexDeclarations.ptr[2].vertexShaderD3D = nullptr;
    this->vertexDeclarations.ptr[3].vertexShaderD3D = nullptr;
    goto LABEL_60;
  }
  p_vertexDeclarations = (char **)&this->vertexDeclarations;
  for ( j = 4; j != 0; --j )
  {
    v30 = *p_vertexDeclarations;
    if ( *p_vertexDeclarations != nullptr )
    {
      v67.buffer = *p_vertexDeclarations;
      D3DResource_Release(pResource: (D3DResource *)v30);
      *p_vertexDeclarations = nullptr;
    }
    p_vertexDeclarations += 2;
  }
  compiledVertexCode = this->compiledVertexCode;
  if ( compiledVertexCode != nullptr )
  {
    idMem::Free(this: &mem, ptr: compiledVertexCode, align: ALIGN_16);
LABEL_60:
    this->compiledVertexCode = nullptr;
  }
  v32 = this->fragmentShaderD3D;
  this->inheritedVertexProgram = nullptr;
  if ( v32 != nullptr || this->isFastZ )
  {
    v68 = MD5_BlockChecksum(data: this->vertexCode[2].data, length: this->vertexCode[2].len);
    fileSystem->FixLongFilename(
      this: fileSystem,
      a2: "generated/hlsl/",
      a3: "v360",
      a4: this->name.str,
      a5: v77,
      a6: 256);
    idStr::idStr(this: &v76, text: v77);
    v33 = _cntlzw(idLib::headless);
    v34 = (v33 & 0x20) != 0;
    if ( (v33 & 0x20) != 0 )
    {
      v35 = fileSystem->OpenFileRead(this: fileSystem, a2: v76.data, a3: 1, a4: 0);
      v36 = v35;
      if ( v35 != nullptr )
      {
        v70 = 0;
        v66 = 0;
        v35->Read(this: v35, a2: &v70, a3: 4u);
        v36->Read(this: v36, a2: &v66, a3: 4u);
        if ( idLib::production == PROD_PRODUCTION || v68 == v70 )
        {
          v34 = false;
          v37 = idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\engine\\renderer\\DeclRenderProg_D3D_360.cpp(486) : TAG_RENDERPROG",
                  size: v66,
                  tag: TAG_RENDERPROG,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
          v38 = v66;
          this->compiledVertexCode = v37;
          v36->Read(this: v36, a2: v37, a3: v38);
        }
        else
        {
          idLib::Printf(fmt: "%s out of date, recompiling.\n", v76.data);
        }
        ((void (__fastcall *)(idFile *, int))v36->dtr_idFile)(a1: v36, a2: 1);
      }
      else
      {
        idLib::Printf(fmt: "%s not found, recompiling.\n", v76.data);
      }
    }
    if ( !v34 )
      goto LABEL_97;
    if ( idLib::production == PROD_PRODUCTION )
      idLib::FatalError(fmt: "No compiled vertex program for %s", this->name.str);
    idStr::SetFileExtension(this: &v76, extension: "v360src");
    v39 = this->vertexCode[2].data;
    v40 = 0;
    if ( *v39 != 0 )
    {
      do
        ++v40;
      while ( v39[v40] != 0 );
    }
    v67.buffer = this->vertexCode[2].data;
    ((void (__fastcall *)(idFileSystem *, char *))fileSystem->WriteFile)(a1: fileSystem, a2: v76.data);
    for ( k = 16; k != 0; --k )
      idStreamFileCache::OutOfMemoryCallback(this: streamFileCache);
    v63 = nullptr;
    v42 = 0;
    v43 = this->vertexCode[2].data;
    v64 = nullptr;
    if ( *v43 != 0 )
    {
      do
        ++v42;
      while ( v43[v42] != 0 );
    }
    v67.buffer = v43;
    v44 = D3DXGetVertexShaderProfile(pDevice: d3d);
    v45 = D3DXCompileShader(
            pSrcData: v43,
            SrcDataSize: v42,
            pDefines: nullptr,
            pInclude: nullptr,
            pEntrypoint: "main",
            pTarget: v44,
            Flags: 0x201u,
            ppShader: &v63,
            ppErrorMsgs: v61,
            ppConstantTable: v62);
    v46 = v64;
    v47 = v45;
    if ( v64 != nullptr )
    {
      v49 = (const char *)v64->GetBufferPointer(this: v64);
      v50 = strstr(str1: v49, str2: "error");
      v46 = v64;
      v48 = v50 != nullptr;
    }
    else
    {
      v48 = false;
    }
    if ( v48 || v47 < 0 )
    {
      idDeclRenderProg::ReportError(this, pErrorMsg: v46, code: this->vertexCode[2].data, extension: "vertex");
    }
    else
    {
      if ( v46 == nullptr )
        goto LABEL_90;
      idLib::Warning(fmt: "vertex program has warnings");
    }
    if ( v64 != nullptr )
    {
      v64->Release(this: v64);
      v64 = nullptr;
    }
LABEL_90:
    if ( this->resourceError == nullptr )
    {
      if ( v63 == nullptr )
      {
LABEL_97:
        idStr::FreeData(this: &v76);
        goto LABEL_98;
      }
      v51 = v63->GetBufferSize(this: v63);
      v52 = idMem::AllocWithLocation(
              this: &mem,
              location: "w:\\tech5\\engine\\renderer\\DeclRenderProg_D3D_360.cpp(534) : TAG_DECL",
              size: v51,
              tag: TAG_DECL,
              zeroBuffer: false,
              align: ALIGN_16,
              heap: HEAP_DEFAULTHEAP);
      v53 = v63;
      this->compiledVertexCode = v52;
      v54 = v53->GetBufferSize(this: v53);
      v55 = v63->GetBufferPointer(this: v63);
      memcpy(Dst: this->compiledVertexCode, Src: v55, Size: v54);
      idStr::SetFileExtension(this: &v76, extension: "v360");
      v56 = fileSystem->OpenFileWrite(this: fileSystem, a2: v76.data, a3: 0);
      v57 = v56;
      if ( v56 != nullptr )
      {
        v56->Write(this: v56, a2: &v68, a3: 4u);
        v69 = (D3DPixelShader *)v63->GetBufferSize(this: v63);
        v57->Write(this: v57, a2: &v69, a3: 4u);
        v58 = v57->__vftable;
        v59 = v63->GetBufferSize(this: v63);
        v60 = v63->GetBufferPointer(this: v63);
        v58->Write(this: v57, a2: v60, a3: v59);
        ((void (__fastcall *)(idFile *, int))v57->dtr_idFile)(a1: v57, a2: 1);
      }
      else
      {
        idLib::Warning(fmt: v72, v76.data);
      }
    }
    if ( v63 != nullptr )
      v63->Release(this: v63);
    goto LABEL_97;
  }
LABEL_98:
  if ( this->compiledVertexCode != nullptr && !idLib::headless )
    idDeclRenderProg::CreateVertexShaderForVertexFormat(this, storedVertexMask: 0x1Fu);
}


// ========================================================================
// $LN309
// EA  : 0x828B3F50
// RVA : 0x008B3F50
// PDB : w:\tech5\engine\renderer\declrenderprog_d3d_360.cpp
// ========================================================================

void _LN309()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 160));
}


// ========================================================================
// __unwind$230261
// EA  : 0x828B3F78
// RVA : 0x008B3F78
// PDB : w:\tech5\engine\renderer\declrenderprog_d3d_360.cpp
// ========================================================================

void _unwind_230261()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 640 + 112));
}


// ========================================================================
// __unwind$230262
// EA  : 0x828B3FA0
// RVA : 0x008B3FA0
// PDB : w:\tech5\engine\renderer\declrenderprog_d3d_360.cpp
// ========================================================================

void _unwind_230262()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 192));
}

