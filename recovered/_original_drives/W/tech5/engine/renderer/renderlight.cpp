
// ========================================================================
// ?GetIndex@idRenderLight@@QBAHXZ
// EA  : 0x829424E8
// RVA : 0x009424E8
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

unsigned int __fastcall idRenderLight::GetIndex(idRenderLight *this)
{
  return this->committed->index.index >> 8;
}


// ========================================================================
// ?GetParmBlock@idRenderLight@@QAAPAVidParmBlock@@XZ
// EA  : 0x829424F8
// RVA : 0x009424F8
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

idStaticParmBlock<32> *__fastcall idRenderLight::GetParmBlock(idRenderLight *this)
{
  return &this->gameParmBlock;
}


// ========================================================================
// ?SetParm@idRenderLight@@QAAXPBVidDeclRenderParm@@ABVidVec4@@@Z
// EA  : 0x82942630
// RVA : 0x00942630
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void __fastcall idRenderLight::SetParm(idRenderLight *this, const idDeclRenderParm *parm, const idVec4 *v4)
{
  double y; // fp13
  double z; // fp12
  parmValue_t v5; // [sp+50h] [-20h] BYREF

  y = v4->y;
  z = v4->z;
  v5.value[0] = v4->x;
  v5.value[1] = y;
  v5.value[3] = v4->w;
  v5.value[2] = z;
  idParmBlock::SetParm(this: &this->gameParmBlock, parm, parmValue: &v5);
}


// ========================================================================
// ?CommitThisFrame@idRenderLight@@QAAXXZ
// EA  : 0x82942880
// RVA : 0x00942880
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void __fastcall idRenderLight::CommitThisFrame(idRenderLight *this)
{
  idRenderLightCommitted *committed; // r11

  committed = this->committed;
  this->unlinked = false;
  if ( committed->world != nullptr )
  {
    committed->world->commitLights.ptr[committed->index.index >> 8] = true;
    this->committed->world->MarkLightSerialized(this: this->committed->world, a2: this, a3: true, a4: false);
  }
}


// ========================================================================
// ?Delete@idRenderLight@@QAAXXZ
// EA  : 0x829428E0
// RVA : 0x009428E0
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void __fastcall idRenderLight::Delete(idRenderLight *this)
{
  idRenderLightCommitted *committed; // r11
  idRenderWorldLocal *world; // r3

  committed = this->committed;
  this->deleteOnSync = true;
  this->unlinked = false;
  if ( committed->world != nullptr )
  {
    committed->world->commitLights.ptr[committed->index.index >> 8] = true;
    this->committed->world->MarkLightSerialized(this: this->committed->world, a2: this, a3: true, a4: false);
  }
  world = this->committed->world;
  if ( world != nullptr )
    world->MarkLightSerialized(this: world, a2: this, a3: false, a4: true);
}


// ========================================================================
// ?Unlink@idRenderLight@@QAAXXZ
// EA  : 0x82942998
// RVA : 0x00942998
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void __fastcall idRenderLight::Unlink(idRenderLight *this)
{
  if ( !this->unlinked )
  {
    idRenderLight::CommitThisFrame(this);
    this->unlinked = true;
  }
}


// ========================================================================
// ?Commit@idRenderLight@@QAAXXZ
// EA  : 0x829429D8
// RVA : 0x009429D8
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void __fastcall idRenderLight::Commit(idRenderLight *this)
{
  const idMaterial *shader; // r11
  idRenderLightCommitted *committed; // r11
  lightType_t lightType; // r10
  const idMaterial *mtrDefaultParallelBlendLight; // r10
  idRenderLightCommitted *v6; // r11
  idParmBlock v7; // [sp+50h] [-30h] BYREF

  if ( r_skipCommits.valueInteger == 0 )
  {
    ++tr.pc.c_lightCommits;
    if ( r_showCommits.valueInteger > 1 )
      idLib::Printf(fmt: "light commit: index %i\n", this->committed->index.index >> 8);
    idStaticParmBlock<32>::operator=(this: &this->committed->renderParmBlock, __that: &this->gameParmBlock);
    idRenderLightParms::operator=(this: &this->committed->r, __that: &this->g);
    shader = this->g.shader;
    if ( shader != nullptr )
    {
      this->committed->lightMtr = shader;
      if ( idDecl::IsImplicit(this: &this->committed->lightMtr->idDecl) )
      {
        idLib::Warning(fmt: "Light shader '%s' defaulted, using standard light", this->committed->lightMtr->name.str);
        this->committed->lightMtr = nullptr;
      }
    }
    else
    {
      this->committed->lightMtr = nullptr;
    }
    committed = this->committed;
    if ( committed->lightMtr == nullptr )
    {
      lightType = this->g.lightType;
      if ( this->g.lightClass == LIGHT_BLENDED_ONLY )
      {
        if ( lightType != LIGHT_POINT )
        {
          if ( lightType == LIGHT_PARALLEL )
            mtrDefaultParallelBlendLight = tr.mtrDefaultParallelBlendLight;
          else
            mtrDefaultParallelBlendLight = tr.mtrDefaultProjectedBlendLight;
        }
        else
        {
          mtrDefaultParallelBlendLight = tr.mtrDefaultPointBlendLight;
        }
      }
      else if ( lightType != LIGHT_POINT )
      {
        if ( lightType == LIGHT_PARALLEL )
          mtrDefaultParallelBlendLight = tr.mtrDefaultParallelLight;
        else
          mtrDefaultParallelBlendLight = tr.mtrDefaultProjectedLight;
      }
      else
      {
        mtrDefaultParallelBlendLight = tr.mtrDefaultPointLight;
      }
      committed->lightMtr = mtrDefaultParallelBlendLight;
    }
    if ( !this->g.noShadows
      && (*((_BYTE *)(v6 = this->committed)->lightMtr + 72) & 0x80) != 0
      && r_shadows.valueInteger != 0 )
    {
      v6->castsShadows = true;
    }
    else
    {
      this->committed->castsShadows = false;
    }
    if ( this->g.lightClass != LIGHT_BLENDED_ONLY
      && (idParmBlock::GetVector(this: &v7, result: &this->committed->renderParmBlock, parm: rp->lightColor),
          *(float *)&v7.ops.list == 0.0)
      && *(float *)&v7.ops.num == 0.0
      && *(float *)&v7.ops.size == 0.0 )
    {
      idRenderLightCommitted::PostCommit(this: this->committed);
      this->unlinked = true;
      idRenderLightCommitted::FreeReferences(this: this->committed);
    }
    else
    {
      this->committed->needsReferences = true;
      this->committed->world->postCommitLights.ptr[this->committed->index.index >> 8] = true;
    }
  }
}


// ========================================================================
// ??0idRenderLight@@AAA@XZ
// EA  : 0x82942C20
// RVA : 0x00942C20
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

idRenderLight *__fastcall idRenderLight::idRenderLight(idRenderLight *this)
{
  idRenderLightCommitted *v2; // r3
  idRenderLightCommitted *v3; // r3

  idRenderLightParms::idRenderLightParms(this: &this->g);
  idStaticParmBlock<32>::idStaticParmBlock<32>(this: &this->gameParmBlock, threadId: THREAD_MAIN);
  this->deleteOnSync = false;
  this->unlinked = true;
  this->needWriteToSnapshot = true;
  this->skipAutoReplication = false;
  this->serializedChangeCount = 0;
  v2 = (idRenderLightCommitted *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x500u,
                                   tag: TAG_RENDERER,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idRenderLightCommitted::idRenderLightCommitted(this: v2);
  else
    v3 = nullptr;
  this->committed = v3;
  return this;
}


// ========================================================================
// __unwind$231198
// EA  : 0x82942CB4
// RVA : 0x00942CB4
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void _unwind_231198()
{
  int v0; // r12

  idStaticParmBlock<32>::~idStaticParmBlock<32>(this: (idStaticParmBlock<32> *)(*(_DWORD *)(v0 - 128 + 148) + 240));
}


// ========================================================================
// __unwind$231199
// EA  : 0x82942CE0
// RVA : 0x00942CE0
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void _unwind_231199()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RENDERER);
}


// ========================================================================
// ??1idRenderLight@@AAA@XZ
// EA  : 0x82942D18
// RVA : 0x00942D18
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void __fastcall idRenderLight::~idRenderLight(idRenderLight *this)
{
  idRenderLightCommitted *committed; // r11
  idRenderLightCommitted *v3; // r29

  committed = this->committed;
  if ( committed->world != nullptr )
  {
    committed->world->commitLights.ptr[committed->index.index >> 8] = false;
    this->committed->world->postCommitLights.ptr[this->committed->index.index >> 8] = false;
  }
  idRenderLightCommitted::FreeReferences(this: this->committed);
  v3 = this->committed;
  if ( v3 != nullptr )
  {
    idRenderLightCommitted::~idRenderLightCommitted(this: this->committed);
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
  }
  idParmBlock::~idParmBlock(this: &this->gameParmBlock);
}


// ========================================================================
// __unwind$231228
// EA  : 0x82942DC4
// RVA : 0x00942DC4
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void _unwind_231228()
{
  int v0; // r12

  idStaticParmBlock<32>::~idStaticParmBlock<32>(this: (idStaticParmBlock<32> *)(*(_DWORD *)(v0 - 112 + 132) + 240));
}


// ========================================================================
// ?Save@idRenderLight@@QBAXPAVidFile@@@Z
// EA  : 0x82942DF0
// RVA : 0x00942DF0
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void __fastcall idRenderLight::Save(idRenderLight *this, idFile *fp)
{
  idFile_vtbl *v3; // r10
  const idMaterial *shader; // r11
  const char *str; // r4
  bool v7[8]; // [sp+50h] [-20h] BYREF

  v3 = fp->__vftable;
  v7[0] = this->unlinked;
  v3->Write(this: fp, a2: v7, a3: 1u);
  shader = this->g.shader;
  if ( shader != nullptr )
    str = shader->name.str;
  else
    str = &byte_8200D768;
  idFile::WriteString(this: fp, string: str);
  fp->Write(this: fp, a2: this, a3: 36u);
  fp->Write(this: fp, a2: &this->g.origin, a3: 12u);
  fp->Write(this: fp, a2: &this->g.allowLightOnlyInViewID, a3: 4u);
  fp->Write(this: fp, a2: &this->g.suppressLightInViewID, a3: 4u);
  fp->Write(this: fp, a2: &this->g.noShadows, a3: 1u);
  fp->Write(this: fp, a2: &this->g.lightType, a3: 4u);
  fp->Write(this: fp, a2: &this->g.lightClass, a3: 4u);
  fp->Write(this: fp, a2: &this->g.lightFalloff, a3: 4u);
  fp->Write(this: fp, a2: &this->g.lightRadius, a3: 12u);
  fp->Write(this: fp, a2: &this->g.lightCenter, a3: 12u);
  fp->Write(this: fp, a2: &this->g.target, a3: 12u);
  fp->Write(this: fp, a2: &this->g.right, a3: 12u);
  fp->Write(this: fp, a2: &this->g.up, a3: 12u);
  fp->Write(this: fp, a2: &this->g.start, a3: 12u);
  fp->Write(this: fp, a2: &this->g.end, a3: 12u);
  fp->Write(this: fp, a2: &this->g.areaLightSize, a3: 4u);
  fp->Write(this: fp, a2: &this->g.shadowSampleScale, a3: 4u);
  idParmBlock::Save(this: &this->gameParmBlock, fp);
}


// ========================================================================
// ?Load@idRenderLight@@QAA_NPAVidFile@@@Z
// EA  : 0x82943060
// RVA : 0x00943060
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

int __fastcall idRenderLight::Load(idRenderLight *this, idFile *fp)
{
  const idMaterial *v5; // r3
  idStr v6[2]; // [sp+50h] [-50h] BYREF

  if ( fp->Read(this: fp, a2: &this->unlinked, a3: 1u) == 0 )
    return 0;
  v6[0].len = 0;
  v6[0].allocedAndFlag = 20;
  v6[0].data = v6[0].baseBuffer;
  v6[0].baseBuffer[0] = 0;
  if ( idFile::ReadString(this: fp, string: v6) == 0 )
  {
    idStr::FreeData(this: v6);
    return 0;
  }
  if ( v6[0].len != 0 )
  {
    if ( v6[0].data != nullptr )
      v5 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                 this: &idMaterial::resourceList,
                                 name: v6[0].data,
                                 makeDefault: true);
    else
      v5 = nullptr;
    this->g.shader = v5;
  }
  else
  {
    this->g.shader = nullptr;
  }
  if ( fp->Read(this: fp, a2: this, a3: 36u) != 0
    && fp->Read(this: fp, a2: &this->g.origin, a3: 12u) != 0
    && fp->Read(this: fp, a2: &this->g.allowLightOnlyInViewID, a3: 4u) != 0
    && fp->Read(this: fp, a2: &this->g.suppressLightInViewID, a3: 4u) != 0
    && fp->Read(this: fp, a2: &this->g.noShadows, a3: 1u) != 0
    && fp->Read(this: fp, a2: &this->g.lightType, a3: 4u) != 0
    && fp->Read(this: fp, a2: &this->g.lightClass, a3: 4u) != 0
    && fp->Read(this: fp, a2: &this->g.lightFalloff, a3: 4u) != 0
    && fp->Read(this: fp, a2: &this->g.lightRadius, a3: 12u) != 0
    && fp->Read(this: fp, a2: &this->g.lightCenter, a3: 12u) != 0
    && fp->Read(this: fp, a2: &this->g.target, a3: 12u) != 0
    && fp->Read(this: fp, a2: &this->g.right, a3: 12u) != 0
    && fp->Read(this: fp, a2: &this->g.up, a3: 12u) != 0
    && fp->Read(this: fp, a2: &this->g.start, a3: 12u) != 0
    && fp->Read(this: fp, a2: &this->g.end, a3: 12u) != 0
    && fp->Read(this: fp, a2: &this->g.areaLightSize, a3: 4u) != 0
    && fp->Read(this: fp, a2: &this->g.shadowSampleScale, a3: 4u) != 0
    && (unsigned __int8)idParmBlock::Load(this: &this->gameParmBlock, fp) != 0 )
  {
    idStr::FreeData(this: v6);
    return 1;
  }
  else
  {
    idStr::FreeData(this: v6);
    return 0;
  }
}


// ========================================================================
// __unwind$231436
// EA  : 0x829434C8
// RVA : 0x009434C8
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void _unwind_231436()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?SerializeSnapshot@idRenderLight@@QAAXAAVidSerializer@@@Z
// EA  : 0x829434F8
// RVA : 0x009434F8
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void __fastcall idRenderLight::SerializeSnapshot(idRenderLight *this, idSerializer *ser)
{
  __int64 v4; // r8
  idBitMsg *msg; // r3
  idBitMsg *v6; // r3
  bool noShadows; // r28
  idBitMsg *v8; // r3
  idBitMsg *v9; // r3
  lightType_t lightType; // r27
  idBitMsg *v11; // r3
  unsigned int v12; // r10
  int v13; // r28
  lightClass_t lightClass; // r27
  idBitMsg *v15; // r3
  bool unlinked; // r28
  idBitMsg *v17; // r3
  idFile_BitMsg v18[2]; // [sp+60h] [-60h] BYREF

  idFile_BitMsg::idFile_BitMsg(this: v18, msg: ser->msg);
  if ( ser->writing )
    idParmBlock::Save(this: &this->gameParmBlock, fp: &v18[0]);
  else
    idParmBlock::Load(this: &this->gameParmBlock, fp: &v18[0]);
  idSerializer::Serialize<idMaterial>(this: ser, decl: &this->g.shader);
  idSerializer::SerializeQ(this: ser, axis: (idQuat *)this, bits: 15, a4: v4);
  idSerializer::Serialize(this: ser, value: &this->g.origin);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->g.allowLightOnlyInViewID, numBits: 32);
  else
    this->g.allowLightOnlyInViewID = idBitMsg::ReadBits(this: msg, numBits: 32);
  v6 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v6, value: this->g.suppressLightInViewID, numBits: 32);
  else
    this->g.suppressLightInViewID = idBitMsg::ReadBits(this: v6, numBits: 32);
  noShadows = this->g.noShadows;
  v8 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v8, value: this->g.noShadows, numBits: 1);
  else
    noShadows = (_cntlzw(idBitMsg::ReadBits(this: v8, numBits: 1) - 1) & 0x20) != 0;
  this->g.noShadows = noShadows;
  idSerializer::Serialize(this: ser, value: &this->g.dynamicModelLightingScale);
  v9 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v9, value: COERCE_INT(this->g.dimShadowStretch), numBits: 32);
  else
    LODWORD(this->g.dimShadowStretch) = idBitMsg::ReadBits(this: v9, numBits: 32);
  lightType = this->g.lightType;
  v11 = ser->msg;
  v12 = _cntlzw(0xFu);
  v13 = 32 - v12;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v11, value: this->g.lightType, numBits: 32 - v12);
  else
    lightType = idBitMsg::ReadBits(this: v11, numBits: 32 - v12);
  this->g.lightType = lightType;
  lightClass = this->g.lightClass;
  v15 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v15, value: this->g.lightClass, numBits: v13);
  else
    lightClass = idBitMsg::ReadBits(this: v15, numBits: v13);
  this->g.lightClass = lightClass;
  idSerializer::Serialize(this: ser, value: &this->g.lightRadius);
  idSerializer::Serialize(this: ser, value: &this->g.lightCenter);
  if ( this->g.lightType == LIGHT_SPOT )
  {
    idSerializer::Serialize(this: ser, value: &this->g.target);
    idSerializer::Serialize(this: ser, value: &this->g.right);
    idSerializer::Serialize(this: ser, value: &this->g.up);
    idSerializer::Serialize(this: ser, value: &this->g.start);
    idSerializer::Serialize(this: ser, value: &this->g.end);
  }
  unlinked = this->unlinked;
  v17 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v17, value: this->unlinked, numBits: 1);
  else
    unlinked = (_cntlzw(idBitMsg::ReadBits(this: v17, numBits: 1) - 1) & 0x20) != 0;
  if ( !ser->writing )
  {
    if ( unlinked )
    {
      if ( !this->unlinked )
      {
        idRenderLight::CommitThisFrame(this);
        this->unlinked = true;
      }
    }
    else
    {
      idRenderLight::CommitThisFrame(this);
    }
  }
  idFile_BitMsg::~idFile_BitMsg(this: v18);
}


// ========================================================================
// __unwind$231719
// EA  : 0x8294379C
// RVA : 0x0094379C
// PDB : w:\tech5\engine\renderer\renderlight.cpp
// ========================================================================

void _unwind_231719()
{
  int v0; // r12

  idFile_BitMsg::~idFile_BitMsg(this: (idFile_BitMsg *)(v0 - 192 + 96));
}

