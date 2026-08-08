
// ========================================================================
// ?Spawn@idInfoTraversal@@QAAXXZ
// EA  : 0x82B04900
// RVA : 0x00B04900
// PDB : w:\tech5\tungsten\game\ai\traversalchain.cpp
// ========================================================================

void __fastcall idInfoTraversal::Spawn(idInfoTraversal *this)
{
  if ( this->aasTraversal )
    this->Remove(this);
}


// ========================================================================
// ?Spawn@idInfoNavFlightVolume@@QAAXXZ
// EA  : 0x82B04920
// RVA : 0x00B04920
// PDB : w:\tech5\tungsten\game\ai\traversalchain.cpp
// ========================================================================

float __fastcall idInfoNavFlightVolume::Spawn(idAIEvent *this, const idEntity *ent)
{
  double v2; // fp1

  v2 = this->InternalGetIntensity(this, a2: ent);
  return *((float *)&v2 + 1);
}


// ========================================================================
// ??0idInfo_TraversalPoint@@QAA@XZ
// EA  : 0x82B04930
// RVA : 0x00B04930
// PDB : w:\tech5\tungsten\game\ai\traversalchain.cpp
// ========================================================================

idInfo_TraversalPoint *__fastcall idInfo_TraversalPoint::idInfo_TraversalPoint(idInfo_TraversalPoint *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfo_TraversalPoint_vtbl *)&idInfo_TraversalPoint::`vftable';
  return this;
}


// ========================================================================
// ??1idInfo_TraversalPoint@@UAA@XZ
// EA  : 0x82B04970
// RVA : 0x00B04970
// PDB : w:\tech5\tungsten\game\ai\traversalchain.cpp
// ========================================================================

void __fastcall idInfo_TraversalPoint::~idInfo_TraversalPoint(idInfo_TraversalPoint *this)
{
  this->__vftable = (idInfo_TraversalPoint_vtbl *)&idInfo_TraversalPoint::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// ??0idInfoTraversal@@QAA@XZ
// EA  : 0x82B04988
// RVA : 0x00B04988
// PDB : w:\tech5\tungsten\game\ai\traversalchain.cpp
// ========================================================================

idInfoTraversal *__fastcall idInfoTraversal::idInfoTraversal(idInfoTraversal *this)
{
  double v2; // fp12

  idEntity::idEntity(this);
  this->aasType = AAS_MONSTER48;
  this->__vftable = (idInfoTraversal_vtbl *)&idInfoTraversal::`vftable';
  idStr::idStr(this: &this->traversalAnim, i: 0);
  this->overrideAnim = ANIMOVERRIDE_NONE;
  this->classA = false;
  this->classB = false;
  this->defaultEndpointOffset = 16.0;
  this->classC = false;
  this->classD = false;
  this->classE = false;
  this->evasionTraversalOnly = false;
  *(_WORD *)&this->emergencyTraversalOnly = 1;
  this->aasTraversal = true;
  this->enabled = true;
  this->runWhenDone = true;
  this->deltaCorrect = true;
  this->longTraversal = false;
  this->traversalEndpoint.x = 16.0;
  this->traversalEndpoint.y = 0.0;
  this->traversalEndpoint.z = 0.0;
  v2 = -this->defaultEndpointOffset;
  this->extrusionEndpoint.x = 0.0;
  this->extrusionEndpoint.y = v2;
  this->extrusionEndpoint.z = 0.0;
  return this;
}


// ========================================================================
// __unwind$487880
// EA  : 0x82B04A6C
// RVA : 0x00B04A6C
// PDB : w:\tech5\tungsten\game\ai\traversalchain.cpp
// ========================================================================

void _unwind_487880()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idInfo_TraversalChain@@QAA@XZ
// EA  : 0x82B04BE0
// RVA : 0x00B04BE0
// PDB : w:\tech5\tungsten\game\ai\traversalchain.cpp
// ========================================================================

idInfo_TraversalChain *__fastcall idInfo_TraversalChain::idInfo_TraversalChain(idInfo_TraversalChain *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfo_TraversalChain_vtbl *)&idInfo_TraversalChain::`vftable';
  this->mData.mClass = 0;
  this->mData.mAASType = AAS_MONSTER48;
  this->mData.mFlags = DELTA_CORRECT|RUN_WHEN_DONE|ENABLED|COMBAT_ONLY;
  this->mData.mExtrusionEndpoint.x = 0.0;
  this->mData.mExtrusionEndpoint.y = 0.0;
  this->mData.mExtrusionEndpoint.z = 0.0;
  this->mData.mAnimWeb = nullptr;
  this->mLinks.granularity = 0;
  this->mLinks.memTag = 5;
  this->mLinks.listStatic = 0;
  this->mLinks.list = nullptr;
  this->mLinks.size = 0;
  this->mLinks.num = 0;
  return this;
}


// ========================================================================
// __unwind$488096
// EA  : 0x82B04C88
// RVA : 0x00B04C88
// PDB : w:\tech5\tungsten\game\ai\traversalchain.cpp
// ========================================================================

void _unwind_488096()
{
  int v0; // r12

  idInfo_TraversalPoint::~idInfo_TraversalPoint(this: *(idInfo_TraversalPoint **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idInfo_TraversalChain@@UAA@XZ
// EA  : 0x82B04CB8
// RVA : 0x00B04CB8
// PDB : w:\tech5\tungsten\game\ai\traversalchain.cpp
// ========================================================================

void __fastcall idInfo_TraversalChain::~idInfo_TraversalChain(idInfo_TraversalChain *this)
{
  char *list; // r3

  this->__vftable = (idInfo_TraversalChain_vtbl *)&idInfo_TraversalChain::`vftable';
  if ( this->mLinks.listStatic == 0 || this->mLinks.listStatic == 2 )
  {
    list = (char *)this->mLinks.list;
    if ( list != nullptr )
      idListArrayDelete<idSpawnRenderParm>(ptr: list, num: this->mLinks.size);
    this->mLinks.list = nullptr;
    this->mLinks.size = 0;
  }
  this->mLinks.num = 0;
  this->__vftable = (idInfo_TraversalChain_vtbl *)&idInfo_TraversalPoint::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$488146
// EA  : 0x82B04D30
// RVA : 0x00B04D30
// PDB : w:\tech5\tungsten\game\ai\traversalchain.cpp
// ========================================================================

void _unwind_488146()
{
  int v0; // r12

  idInfo_TraversalPoint::~idInfo_TraversalPoint(this: *(idInfo_TraversalPoint **)(v0 - 112 + 132));
}

