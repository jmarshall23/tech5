
// ========================================================================
// ?SetupVirtualMaterial@idVirtualTextureSystem@@QAAXPAVidVirtualMaterial@@@Z
// EA  : 0x82977950
// RVA : 0x00977950
// PDB : w:\tech5\engine\renderer\virtualmaterialatlas.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::SetupVirtualMaterial(
        idVirtualTextureSystem *this,
        idVirtualMaterial *vmtr,
        int a3,
        __int64 a4,
        __int64 a5)
{
  int allocWidth; // r11
  __int64 v6; // r9
  __int64 v7; // r7
  int allocHeight; // r11
  __int64 v9; // r9
  int allocX; // r11
  __int64 v11; // r7
  __int64 v12; // r9
  __int64 v13; // r7
  int allocY; // r11
  idMaterial *material; // r3

  allocWidth = vmtr->allocWidth;
  if ( (vmtr->flags & 2) == 0 )
    allocWidth -= 32;
  LODWORD(a5) = allocWidth;
  LODWORD(a4) = this->vmtrMega->VIRTUAL_TEXELS_WIDE;
  vmtr->scaleAndBias.x = (float)a5 / (float)a4;
  HIDWORD(v6) = a4;
  HIDWORD(v7) = vmtr->flags;
  allocHeight = vmtr->allocHeight;
  if ( (v7 & 0x200000000LL) == 0 )
    allocHeight -= 32;
  LODWORD(v6) = allocHeight;
  LODWORD(v7) = this->vmtrMega->VIRTUAL_TEXELS_WIDE;
  vmtr->scaleAndBias.y = (float)v6 / (float)v7;
  HIDWORD(v9) = v7;
  allocX = vmtr->allocX;
  HIDWORD(v11) = vmtr->flags;
  if ( (v11 & 0x200000000LL) == 0 )
    allocX += 16;
  LODWORD(v9) = allocX;
  LODWORD(v11) = this->vmtrMega->VIRTUAL_TEXELS_WIDE;
  vmtr->scaleAndBias.z = (float)v9 / (float)v11;
  HIDWORD(v12) = v11;
  HIDWORD(v13) = vmtr->flags;
  allocY = vmtr->allocY;
  if ( (v13 & 0x200000000LL) == 0 )
    allocY += 16;
  LODWORD(v12) = allocY;
  LODWORD(v13) = this->vmtrMega->VIRTUAL_TEXELS_WIDE;
  vmtr->scaleAndBias.w = (float)v12 / (float)v13;
  material = vmtr->material;
  if ( material != nullptr )
    idMaterial::UpdateVirtualMapping(this: material);
}


// ========================================================================
// ?PrintVirtualMaterial_f@idVirtualTextureSystem@@CAXABVidCmdArgs@@@Z
// EA  : 0x82977AC0
// RVA : 0x00977AC0
// PDB : w:\tech5\engine\renderer\virtualmaterialatlas.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::PrintVirtualMaterial_f(const idCmdArgs *args)
{
  int v2; // r28
  idVirtualTexture *vmtrMega; // r26
  int v4; // r29
  idVirtualMaterial *v5; // r31
  const char *str; // r25
  char *v7; // r3
  int v8; // r5
  int allocY; // r10
  int v10; // r6
  int allocHeight; // r7
  int allocX; // r11
  int v13; // r8
  int allocWidth; // r9
  int pagesWide; // r5
  signed int VIRTUAL_TEXELS_WIDE; // r30
  int v17; // r7
  int v18; // r6

  if ( args->argc == 2 )
  {
    v2 = 0;
    vmtrMega = virtualTextureSystem.vmtrMega;
    if ( virtualTextureSystem.vmtrs.num <= 0 )
    {
LABEL_7:
      if ( args->argc <= 1 )
        idLib::Printf(fmt: "'%s' not found\n", &byte_8200D768);
      else
        idLib::Printf(fmt: "'%s' not found\n", args->argv[1]);
    }
    else
    {
      v4 = 0;
      while ( 1 )
      {
        v5 = virtualTextureSystem.vmtrs.list[v4];
        str = v5->materialName.str;
        v7 = idCmdArgs::Argv(this: args, arg: 1);
        if ( idStr::Icmp(s1: v7, s2: str) == 0 )
          break;
        ++v2;
        ++v4;
        if ( v2 >= virtualTextureSystem.vmtrs.num )
          goto LABEL_7;
      }
      idLib::Printf(fmt: "alloc blocks: %3i,%3i : %2i x %2i\n", v5->allocX, v5->allocY, v5->allocWidth, v5->allocHeight);
      v8 = v5->flags & 2;
      allocY = v5->allocY;
      v10 = allocY;
      if ( v8 != 0 )
      {
        allocHeight = v5->allocHeight;
      }
      else
      {
        v10 = allocY + 16;
        allocHeight = v5->allocHeight - 32;
      }
      allocX = v5->allocX;
      v13 = allocX;
      if ( v8 != 0 )
      {
        allocWidth = v5->allocWidth;
      }
      else
      {
        v13 = allocX + 16;
        allocWidth = v5->allocWidth - 32;
      }
      if ( v8 == 0 )
      {
        allocY += 16;
        allocX += 16;
      }
      pagesWide = vmtrMega->header.pagesWide;
      VIRTUAL_TEXELS_WIDE = vmtrMega->VIRTUAL_TEXELS_WIDE;
      v17 = (allocHeight + v10) * pagesWide;
      v18 = (allocWidth + v13) * pagesWide;
      __twllei(VIRTUAL_TEXELS_WIDE, 0);
      __twllei(VIRTUAL_TEXELS_WIDE, 0);
      __twllei(VIRTUAL_TEXELS_WIDE, 0);
      __twllei(VIRTUAL_TEXELS_WIDE, 0);
      __twlgei(VIRTUAL_TEXELS_WIDE & ~(__ROL4__(v17, 1) - 1), 0xFFFFFFFF);
      __twlgei(VIRTUAL_TEXELS_WIDE & ~(__ROL4__(v18, 1) - 1), 0xFFFFFFFF);
      __twlgei(VIRTUAL_TEXELS_WIDE & ~(__ROL4__(pagesWide * allocY, 1) - 1), 0xFFFFFFFF);
      __twlgei(VIRTUAL_TEXELS_WIDE & ~(__ROL4__(pagesWide * allocX, 1) - 1), 0xFFFFFFFF);
      idLib::Printf(
        fmt: "pages: %i,%i to %i,%i\n",
        pagesWide * allocX / VIRTUAL_TEXELS_WIDE,
        pagesWide * allocY / VIRTUAL_TEXELS_WIDE,
        v18 / VIRTUAL_TEXELS_WIDE,
        v17 / VIRTUAL_TEXELS_WIDE);
      idLib::Printf(
        fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v5->scaleAndBias.x)),
        (unsigned int)COERCE_UNSIGNED_INT64(v5->scaleAndBias.x),
        (unsigned int)COERCE_UNSIGNED_INT64(v5->scaleAndBias.y),
        (unsigned int)COERCE_UNSIGNED_INT64(v5->scaleAndBias.z),
        (unsigned int)COERCE_UNSIGNED_INT64(v5->scaleAndBias.w));
      if ( v5->material != nullptr )
        idLib::Printf(fmt: "loaded\n");
      else
        idLib::Printf(fmt: "not loaded\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "USAGE: printVirtualMaterial <materialName>\n");
  }
}


// ========================================================================
// ?NeedsReload@idVirtualImageFile@@QAA_NXZ
// EA  : 0x82977D10
// RVA : 0x00977D10
// PDB : w:\tech5\engine\renderer\virtualmaterialatlas.cpp
// ========================================================================

BOOL __fastcall idVirtualImageFile::NeedsReload(idVirtualImageFile *this)
{
  unsigned int timeStamp; // r11
  unsigned int v4[4]; // [sp+50h] [-20h] BYREF

  R_LoadImageProgram(name: this->fileName.str, pic: nullptr, width: nullptr, height: nullptr, timestamps: v4);
  timeStamp = this->timeStamp;
  return timeStamp == -1 && v4[0] != -1 || timeStamp < v4[0];
}


// ========================================================================
// ?VirtualMaterialForMaterial@idVirtualTextureSystem@@QAAPAVidVirtualMaterial@@PBVidMaterial@@@Z
// EA  : 0x82977D90
// RVA : 0x00977D90
// PDB : w:\tech5\engine\renderer\virtualmaterialatlas.cpp
// ========================================================================

idVirtualMaterial *__fastcall idVirtualTextureSystem::VirtualMaterialForMaterial(
        idVirtualTextureSystem *this,
        const idMaterial *mtr)
{
  idVirtualMaterial *result; // r3
  const idDeclRenderParm *v5; // r26
  const idDeclRenderParm *v6; // r30
  const idDeclRenderParm *v7; // r29
  int v8; // r30
  int v9; // r11
  const char *str; // r4
  idVirtualMaterial *v11; // r31
  int v12; // r3
  char v13; // r11

  if ( mtr == nullptr )
    return nullptr;
  result = mtr->devVmtr;
  if ( result != nullptr )
    return result;
  v5 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                   this: &idDeclRenderParm::resourceList,
                                   name: "bumpMap",
                                   makeDefault: true);
  v6 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                   this: &idDeclRenderParm::resourceList,
                                   name: "diffuseMap",
                                   makeDefault: true);
  v7 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                   this: &idDeclRenderParm::resourceList,
                                   name: "virtualTransMap",
                                   makeDefault: true);
  if ( (unsigned __int8)idParmBlock::SetsRenderParm(this: &mtr->parmBlock, parm: v5) == 0
    && (unsigned __int8)idParmBlock::SetsRenderParm(this: &mtr->parmBlock, parm: v6) == 0
    && (unsigned __int8)idParmBlock::SetsRenderParm(this: &mtr->parmBlock, parm: v7) == 0 )
  {
    return nullptr;
  }
  v8 = this->vmtrHash.hash[idHashIndex::GenerateKeyForString(
                             this: &this->vmtrHash,
                             string: mtr->name.str,
                             caseSensitive: true)
                         & this->vmtrHash.hashMask
                         & this->vmtrHash.lookupMask];
  if ( v8 == -1 )
  {
LABEL_13:
    idLib::Warning(fmt: "Cannot create new vmtr for %s on the console, operation unsupported", mtr->name.str);
    return nullptr;
  }
  v9 = v8;
  while ( 1 )
  {
    str = mtr->name.str;
    v11 = this->vmtrs.list[v9];
    if ( v11->materialName.str == str || (v12 = idStr::Cmp(s1: v11->materialName.str, s2: str), v13 = 1, v12 == 0) )
      v13 = 0;
    if ( v13 == 0 )
      break;
    v8 = this->vmtrHash.indexChain[this->vmtrHash.lookupMask & v8];
    v9 = v8;
    if ( v8 == -1 )
      goto LABEL_13;
  }
  v11->material = mtr;
  return v11;
}


// ========================================================================
// ?ReadVmtrFile@idVirtualTextureSystem@@QAAXXZ
// EA  : 0x82977F20
// RVA : 0x00977F20
// PDB : w:\tech5\engine\renderer\virtualmaterialatlas.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::ReadVmtrFile(idVirtualTextureSystem *this)
{
  idList<enum encounterGroupRole_t,5> *p_vmtrs; // r26
  int v3; // r3
  int v4; // r23
  int v5; // r28
  int v6; // r27
  idVirtualMaterial *v7; // r3
  idVirtualMaterial *v8; // r30
  __int64 v9; // r10
  __int64 v10; // r8
  int v11; // r5
  int KeyForString; // r3
  idVirtualMaterial *p_scaleAndBias; // [sp+50h] [-160h] BYREF
  idToken v14; // [sp+60h] [-150h] BYREF
  idLexer v15; // [sp+B0h] [-100h] BYREF

  p_vmtrs = (idList<enum encounterGroupRole_t,5> *)&this->vmtrs;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vmtrs);
  idHashIndex::Clear(this: &this->vmtrHash);
  idLexer::idLexer(this: &v15, flags_: 0);
  if ( idLexer::LoadFile(this: &v15, filename_: this->vmtrPath, OSPath: false)
    && (v15.flags = 418360, idLexer::ParseInt(this: &v15) == 25) )
  {
    v3 = idLexer::ParseInt(this: &v15);
    v14.len = 0;
    v14.baseBuffer[0] = 0;
    v4 = v3;
    v14.intvalue = 0;
    v14.floatvalue = -3.4028235e38;
    memset(&v14.whiteSpaceStart_p, 0, 12);
    v14.allocedAndFlag = 20;
    v14.data = v14.baseBuffer;
    v5 = 0;
    if ( v3 > 0 )
    {
      v6 = 0;
      while ( idLexer::ReadToken(this: &v15, token: &v14) )
      {
        idLexer::UnreadToken(this: &v15);
        v7 = (idVirtualMaterial *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x38u,
                                    tag: TAG_VIRTUALTEXTURE,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
        if ( v7 != nullptr )
        {
          v7->materialChecksum = 0;
          v8 = v7;
          v7->cpuVmtrTimeStamp = 0;
          v7->allocX = 0;
          v7->allocY = 0;
          v7->materialName.str = &byte_8200D768;
          v7->allocWidth = 0;
          v7->allocHeight = 0;
          v7->flags = 0;
          v7->material = nullptr;
          v7->cpuVmtr = nullptr;
          v7->scaleAndBias.x = 0.0;
          v7->scaleAndBias.y = 0.0;
          p_scaleAndBias = (idVirtualMaterial *)&v7->scaleAndBias;
          v7->scaleAndBias.z = 0.0;
          v7->scaleAndBias.w = 0.0;
        }
        else
        {
          v8 = nullptr;
        }
        p_scaleAndBias = v8;
        v8->allocX = idLexer::ParseInt(this: &v15);
        v8->allocY = idLexer::ParseInt(this: &v15);
        v8->allocWidth = idLexer::ParseInt(this: &v15);
        v8->allocHeight = idLexer::ParseInt(this: &v15);
        v8->flags = idLexer::ParseInt(this: &v15);
        v8->cpuVmtrTimeStamp = idLexer::ParseInt(this: &v15);
        v8->materialChecksum = idLexer::ParseInt(this: &v15);
        idLexer::ReadToken(this: &v15, token: &v14);
        idAtomicString::Set(this: &v8->materialName, str_: v14.data);
        idVirtualTextureSystem::SetupVirtualMaterial(this, vmtr: v8, a3: v11, a4: v10, a5: v9);
        idList<idAnimWebBlendTree *,5>::Append(this: p_vmtrs, obj: (const encounterGroupRole_t *)&p_scaleAndBias);
        KeyForString = idHashIndex::GenerateKeyForString(
                         this: &this->vmtrHash,
                         string: *(const char **)p_vmtrs->list[v6],
                         caseSensitive: true);
        idHashIndex::Add(this: &this->vmtrHash, key: KeyForString, index: v5++);
        ++v6;
        if ( v5 >= v4 )
          goto LABEL_13;
      }
      idLib::Warning(fmt: "Failed to read all the vmtrs.");
    }
LABEL_13:
    idLib::Printf(fmt: "Read %i vmtrs from %s\n", this->vmtrs.num, this->vmtrPath);
    idStr::FreeData(this: &v14);
  }
  else
  {
    idLib::Printf(fmt: "Bad version on read %s, all vmtrs will be re-created\n", this->vmtrPath);
  }
  idLexer::~idLexer(this: &v15);
}


// ========================================================================
// __unwind$230105
// EA  : 0x829781C4
// RVA : 0x009781C4
// PDB : w:\tech5\engine\renderer\virtualmaterialatlas.cpp
// ========================================================================

void _unwind_230105()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 432 + 176));
}


// ========================================================================
// __unwind$230106
// EA  : 0x829781EC
// RVA : 0x009781EC
// PDB : w:\tech5\engine\renderer\virtualmaterialatlas.cpp
// ========================================================================

void _unwind_230106()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 96));
}

