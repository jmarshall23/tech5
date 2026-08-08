
// ========================================================================
// ?AllocParmState@idParmState@@QAAHPBVidDeclRenderParm@@@Z
// EA  : 0x828D8E00
// RVA : 0x008D8E00
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void __fastcall idParmState::AllocParmState(idParmState *this, const idDeclRenderParm *parm)
{
  const char *v3; // r9
  int v4; // r3
  int v5; // r11
  const idDeclRenderParm **v6; // r10
  int v7; // r11
  int i; // ctr
  int v9; // r5

  v3 = "unknown";
  v4 = 0;
  v5 = 0;
  switch ( parm->parmType )
  {
    case PT_VECTOR:
      v4 = 0;
      v3 = "vector";
      v5 = 1024;
      break;
    case PT_TEXTURE:
    case PT_TEXTURE_2D:
    case PT_TEXTURE_3D:
    case PT_TEXTURE_CUBE:
    case PT_TEXTURE_SHADOW_2D:
    case PT_TEXTURE_SHADOW_3D:
    case PT_TEXTURE_SHADOW_CUBE:
    case PT_TEXTURE_MULTISAMPLE_2D:
      v4 = 1024;
      v3 = "texture";
      v5 = 1536;
      break;
    case PT_PROGRAM:
      v4 = 1536;
      v3 = "program";
      v5 = 1920;
      break;
    case PT_STRING:
      v4 = 1920;
      v3 = "string";
      v5 = 2047;
      break;
    default:
      break;
  }
  if ( v4 >= v5 )
    goto LABEL_12;
  v6 = &this->parmDecl[v4];
  while ( *v6 != nullptr )
  {
    ++v4;
    ++v6;
    if ( v4 >= v5 )
      goto LABEL_12;
  }
  if ( v4 == 2047 )
  {
LABEL_12:
    idLib::Error(fmt: "idParmState::AllocParmState: failed to allocate %s parm state", v3);
  }
  else
  {
    v7 = 0;
    for ( i = 4; i != 0; --i )
    {
      v9 = 4 * (4 * (v4 + 3) + v7++);
      *(float *)((char *)&renderThreadParmState->renderParmVersion + v9) = 0.0;
    }
    renderThreadParmState->onParmBlockStack[v4] = 0;
    this->parmDecl[v4] = parm;
    this->parmUsageMask[v4] = 0;
  }
}


// ========================================================================
// ?FreeParmState@idParmState@@QAAXPBVidDeclRenderParm@@@Z
// EA  : 0x828D8F68
// RVA : 0x008D8F68
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void __fastcall idParmState::FreeParmState(idParmState *this, const idDeclRenderParm *parm)
{
  int parmIndex; // r11

  parmIndex = parm->parmIndex;
  if ( parmIndex != 2047 )
    this->parmDecl[parmIndex] = nullptr;
}


// ========================================================================
// ?GetTableIndex@idParmState@@QAAHPBVidDeclTable@@@Z
// EA  : 0x828D8F88
// RVA : 0x008D8F88
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void __fastcall idParmState::GetTableIndex(idParmState *this, const idDeclTable *table)
{
  int v2; // r11
  int *p_numGlobalTables; // r10
  const idDeclTable **globalTables; // r9

  if ( table != nullptr )
  {
    v2 = 0;
    p_numGlobalTables = &this->numGlobalTables;
    if ( this->numGlobalTables <= 0 )
      goto LABEL_9;
    globalTables = this->globalTables;
    while ( *globalTables != nullptr && *globalTables != table )
    {
      ++v2;
      ++globalTables;
      if ( v2 >= *p_numGlobalTables )
        goto LABEL_9;
    }
    this->globalTables[v2] = table;
    this->globalLookupTables[v2] = table->table;
    if ( v2 == 2047 )
    {
LABEL_9:
      if ( *p_numGlobalTables < 128 )
      {
        this->globalTables[*p_numGlobalTables] = table;
        this->globalLookupTables[(*p_numGlobalTables)++] = table->table;
      }
      else
      {
        idLib::Error(fmt: "more than %d parm block tables", 128);
      }
    }
  }
}


// ========================================================================
// ?GetTable@idParmState@@QBAPBVidDeclTable@@H@Z
// EA  : 0x828D9058
// RVA : 0x008D9058
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

const idDeclTable *__fastcall idParmState::GetTable(idParmState *this, int tableIndex)
{
  if ( tableIndex >= 128 )
    return nullptr;
  else
    return this->globalTables[tableIndex];
}


// ========================================================================
// ?RemoveTable@idParmState@@QAAXPBVidDeclTable@@@Z
// EA  : 0x828D9078
// RVA : 0x008D9078
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void __fastcall idParmState::RemoveTable(idParmState *this, const idDeclTable *table)
{
  int v2; // r11
  int numGlobalTables; // r9
  const idDeclTable **i; // r10

  v2 = 0;
  numGlobalTables = this->numGlobalTables;
  if ( numGlobalTables > 0 )
  {
    for ( i = this->globalTables; *i != table; ++i )
    {
      if ( ++v2 >= numGlobalTables )
        return;
    }
    this->globalTables[v2] = nullptr;
    this->globalLookupTables[v2] = nullptr;
  }
}


// ========================================================================
// ?GetParmNameForIndex@idParmState@@QAAPBDH@Z
// EA  : 0x828D90D8
// RVA : 0x008D90D8
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

const char *__fastcall idParmState::GetParmNameForIndex(idParmState *this, int parmIndex)
{
  return this->parmDecl[parmIndex]->name.str;
}


// ========================================================================
// ?GetRenderParmForIndex@idParmState@@QAAPBVidDeclRenderParm@@H@Z
// EA  : 0x828D90F0
// RVA : 0x008D90F0
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

const idDeclRenderParm *__fastcall idParmState::GetRenderParmForIndex(idParmState *this, int parmIndex)
{
  return this->parmDecl[parmIndex];
}


// ========================================================================
// ?UpdateParmUsageMasks@idParmState@@QAAXPBVidDeclRenderProg@@@Z
// EA  : 0x828D9100
// RVA : 0x008D9100
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void __fastcall idParmState::UpdateParmUsageMasks(idParmState *this, const idDeclRenderProg *prog)
{
  int v2; // r10
  __int16 *v3; // r9
  int v4; // r10
  __int16 *v5; // r9
  int v6; // r10
  __int16 *v7; // r9

  v2 = 0;
  if ( prog->numVertexParms > 0 )
  {
    v3 = (__int16 *)&prog->fragmentProgramChecksum + 1;
    do
    {
      ++v3;
      ++v2;
      this->parmUsageMask[*v3] |= 1u;
    }
    while ( v2 < prog->numVertexParms );
  }
  v4 = 0;
  if ( prog->numFragmentParms > 0 )
  {
    v5 = (__int16 *)&prog->numVertexParms + 1;
    do
    {
      ++v5;
      ++v4;
      this->parmUsageMask[*v5] |= 2u;
    }
    while ( v4 < prog->numFragmentParms );
  }
  v6 = 0;
  if ( prog->numTextureParms > 0 )
  {
    v7 = (__int16 *)&prog->numFragmentParms + 1;
    do
    {
      ++v7;
      ++v6;
      this->parmUsageMask[*v7] |= 4u;
    }
    while ( v6 < prog->numTextureParms );
  }
}


// ========================================================================
// ?PrintSharedRenderParms@idParmState@@QAAXXZ
// EA  : 0x828D91D0
// RVA : 0x008D91D0
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void __fastcall idParmState::PrintSharedRenderParms(idParmState *this)
{
  int v1; // r31
  unsigned __int8 *parmUsageMask; // r28
  const idDeclRenderParm **parmDecl; // r30

  v1 = 0;
  parmUsageMask = this->parmUsageMask;
  parmDecl = this->parmDecl;
  do
  {
    if ( (parmUsageMask[v1] & 3) == 3 )
      idLib::Printf(fmt: "%s\n", (*parmDecl)->name.str);
    ++v1;
    ++parmDecl;
  }
  while ( v1 < 2048 );
}


// ========================================================================
// ?PrintSharedRenderParms_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828D9230
// RVA : 0x008D9230
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void __fastcall PrintSharedRenderParms_f(const idCmdArgs *args)
{
  idParmState::PrintSharedRenderParms(this: renderThreadParmState);
}


// ========================================================================
// ?Init@idParmState@@QAAXXZ
// EA  : 0x828D9240
// RVA : 0x008D9240
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void __fastcall idParmState::Init(idParmState *this)
{
  this->parmIndexPositionToViewTexture = rp->positionToViewTexture->parmIndex;
  this->parmIndexRenderPositionToViewTexture = rp->renderPositionToViewTexture->parmIndex;
  this->parmIndexPositionToFeedback = rp->positionToFeedback->parmIndex;
  this->parmIndexModelMatrixX = rp->modelMatrix[0]->parmIndex;
  this->parmIndexModelMatrixY = rp->modelMatrix[1]->parmIndex;
  this->parmIndexModelMatrixZ = rp->modelMatrix[2]->parmIndex;
  this->parmIndexModelMatrixW = rp->modelMatrix[3]->parmIndex;
  this->parmIndexInverseModelMatrixX = rp->inverseModelMatrix[0]->parmIndex;
  this->parmIndexInverseModelMatrixY = rp->inverseModelMatrix[1]->parmIndex;
  this->parmIndexInverseModelMatrixZ = rp->inverseModelMatrix[2]->parmIndex;
  this->parmIndexInverseModelMatrixW = rp->inverseModelMatrix[3]->parmIndex;
  this->parmIndexMVPMatrixX = rp->mvpMatrix[0]->parmIndex;
  this->parmIndexMVPMatrixY = rp->mvpMatrix[1]->parmIndex;
  this->parmIndexMVPMatrixZ = rp->mvpMatrix[2]->parmIndex;
  this->parmIndexMVPMatrixW = rp->mvpMatrix[3]->parmIndex;
  this->parmIndexPrimeLightDir = rp->primeLightDir->parmIndex;
  this->parmIndexPrimeLightColor = rp->primeLightColor->parmIndex;
  this->parmIndexLightingModel = (int)rp_lightingModel.r[1].resourceError;
  this->parmIndexChannelLight[0] = rp->channelLight[0]->parmIndex;
  this->parmIndexChannelLight[1] = rp->channelLight[1]->parmIndex;
  this->parmIndexChannelLight[2] = rp->channelLight[2]->parmIndex;
  this->parmIndexChannelLight[3] = rp->channelLight[3]->parmIndex;
  this->parmIndexChannelLight[4] = rp->channelLight[4]->parmIndex;
  this->parmIndexChannelLight[5] = rp->channelLight[5]->parmIndex;
  this->parmIndexHighlightColor = rp->highlightColor->parmIndex;
  this->parmIndexVertexStScaleBias = (int)rp_vertexStScaleBias.r[1].resourceError;
  this->parmIndexVertexXYZScale = (int)rp_vertexXYZScale.r[1].resourceError;
  this->parmIndexVertexXYZBias = (int)rp_vertexXYZBias.r[1].resourceError;
  this->parmIndexIf = rp->If->parmIndex;
  this->parmIndexPolygonOffset = rp->polygonOffset->parmIndex;
  this->parmIndexVertexMorphScale = (int)rp_vertexMorphScale.r[1].resourceError;
}


// ========================================================================
// `dynamic initializer for 'rp_vertexStScaleBias''
// EA  : 0x8334C218
// RVA : 0x0134C218
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void _dynamic_initializer_for__rp_vertexStScaleBias__()
{
  rp_vertexStScaleBias.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_vertexStScaleBias;
}


// ========================================================================
// `dynamic initializer for 'rp_vertexXYZScale''
// EA  : 0x8334C238
// RVA : 0x0134C238
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void _dynamic_initializer_for__rp_vertexXYZScale__()
{
  rp_vertexXYZScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_vertexXYZScale;
}


// ========================================================================
// `dynamic initializer for 'rp_vertexXYZBias''
// EA  : 0x8334C258
// RVA : 0x0134C258
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void _dynamic_initializer_for__rp_vertexXYZBias__()
{
  rp_vertexXYZBias.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_vertexXYZBias;
}


// ========================================================================
// `dynamic initializer for 'rp_vertexMorphScale''
// EA  : 0x8334C278
// RVA : 0x0134C278
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void _dynamic_initializer_for__rp_vertexMorphScale__()
{
  rp_vertexMorphScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_vertexMorphScale;
}


// ========================================================================
// `dynamic initializer for 'rp_lightingModel''
// EA  : 0x8334C298
// RVA : 0x0134C298
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

void _dynamic_initializer_for__rp_lightingModel__()
{
  rp_lightingModel.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_lightingModel;
}


// ========================================================================
// `dynamic initializer for 'renderThreadParmStateObject''
// EA  : 0x8334C2B8
// RVA : 0x0134C2B8
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

idParmState *_dynamic_initializer_for__renderThreadParmStateObject__()
{
  return idParmState::idParmState(this: &renderThreadParmStateObject);
}


// ========================================================================
// `dynamic initializer for 'PrintSharedRenderParms_v''
// EA  : 0x8334C2C8
// RVA : 0x0134C2C8
// PDB : w:\tech5\engine\renderer\jobs\render\parmstate_alloc.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__PrintSharedRenderParms_v__()
{
  return idCommandLink::idCommandLink(
           this: &PrintSharedRenderParms_v,
           cmdName: "PrintSharedRenderParms",
           function: PrintSharedRenderParms_f,
           description: "Print render parms that are used by both a vertex and fragment program",
           argCompletion: nullptr);
}

