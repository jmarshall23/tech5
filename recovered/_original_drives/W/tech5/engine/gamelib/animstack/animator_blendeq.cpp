
// ========================================================================
// ??0idAnimator_BlendEq@@QAA@XZ
// EA  : 0x826DCB50
// RVA : 0x006DCB50
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

idAnimator_BlendEq *__fastcall idAnimator_BlendEq::idAnimator_BlendEq(idAnimator_BlendEq *this)
{
  idAnimator_Base::idAnimator_Base(this);
  this->__vftable = (idAnimator_BlendEq_vtbl *)&idAnimator_BlendEq::`vftable';
  this->blendEq.len = 0;
  this->blendEq.allocedAndFlag = 20;
  this->blendEq.data = this->blendEq.baseBuffer;
  this->blendEq.baseBuffer[0] = 0;
  this->mergeBranch = nullptr;
  this->scalars.list = nullptr;
  this->scalars.granularity = 0;
  this->scalars.memTag = 33;
  this->scalars.listStatic = 0;
  this->scalars.size = 0;
  this->scalars.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalars);
  this->scalarPairs.list = nullptr;
  this->scalarPairs.granularity = 0;
  this->scalarPairs.memTag = 33;
  this->scalarPairs.listStatic = 0;
  this->scalarPairs.size = 0;
  this->scalarPairs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalarPairs);
  this->scalarMem = nullptr;
  this->namedAnims.list = nullptr;
  this->namedAnims.granularity = 0;
  this->namedAnims.memTag = 33;
  this->namedAnims.listStatic = 0;
  this->namedAnims.size = 0;
  this->namedAnims.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->namedAnims);
  return this;
}


// ========================================================================
// __unwind$248940
// EA  : 0x826DCC10
// RVA : 0x006DCC10
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_248940()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$248941
// EA  : 0x826DCC38
// RVA : 0x006DCC38
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_248941()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}


// ========================================================================
// __unwind$248942
// EA  : 0x826DCC64
// RVA : 0x006DCC64
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_248942()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 76));
}


// ========================================================================
// __unwind$248943
// EA  : 0x826DCC90
// RVA : 0x006DCC90
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_248943()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 92));
}


// ========================================================================
// ??1idAnimator_BlendEq@@UAA@XZ
// EA  : 0x826DCCC8
// RVA : 0x006DCCC8
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall idAnimator_BlendEq::~idAnimator_BlendEq(idAnimator_BlendEq *this)
{
  this->__vftable = (idAnimator_BlendEq_vtbl *)&idAnimator_BlendEq::`vftable';
  this->scalarMem = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->namedAnims);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalarPairs);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalars);
  idStr::FreeData(this: &this->blendEq);
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// __unwind$249046
// EA  : 0x826DCD3C
// RVA : 0x006DCD3C
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_249046()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$249047
// EA  : 0x826DCD64
// RVA : 0x006DCD64
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_249047()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// __unwind$249048
// EA  : 0x826DCD90
// RVA : 0x006DCD90
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_249048()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 76));
}


// ========================================================================
// __unwind$249049
// EA  : 0x826DCDBC
// RVA : 0x006DCDBC
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_249049()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 92));
}


// ========================================================================
// ?SetNamedAnims@idAnimator_BlendEq@@QAAXABV?$idList@VidNamedAnim@idAnimator_BlendEq@@$04@@@Z
// EA  : 0x826DCDE8
// RVA : 0x006DCDE8
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall idAnimator_BlendEq::SetNamedAnims(
        idAnimator_BlendEq *this,
        const idList<idAnimator_BlendEq::idNamedAnim,33> *anims)
{
  idList<idAnimator_BlendEq::idNamedAnim,5>::operator=(this: &this->namedAnims, other: anims);
}


// ========================================================================
// ?Free@idAnimator_BlendEq@@AAAXPAVidMD6Allocator@@PAVidMD6Node@@@Z
// EA  : 0x826DD018
// RVA : 0x006DD018
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall idAnimator_BlendEq::Free(
        idAnimator_BlendEq *this,
        idMD6Allocator *allocator,
        const idVoiceEvent *root,
        int a4,
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
        const idVoiceEvent *a16)
{
  int num; // r9
  int v18; // r26
  encounterGroupRole_t *i; // r24
  unsigned __int8 *v20; // r28
  int v21; // r10
  encounterGroupRole_t *v22; // r11
  unsigned int v23; // r11
  int v24; // r30
  int v25; // r29
  int v26; // r30
  int v27; // r29
  int v28; // r30
  int v29; // r29
  encounterGroupRole_t *v30; // r29
  int j; // r30
  encounterGroupRole_t v32[4]; // [sp+50h] [-80h] BYREF
  idList<enum encounterGroupRole_t,5> v33; // [sp+60h] [-70h] BYREF
  idList<enum encounterGroupRole_t,5> v34[6]; // [sp+70h] [-60h] BYREF

  a16 = root;
  if ( root != nullptr )
  {
    memset(v34, 0, 14);
    v34[0].memTag = 5;
    v34[0].listStatic = 0;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v34);
    memset(&v33, 0, 14);
    *(_WORD *)&v33.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33);
    idList<idDeclMD6 const *,5>::AddUnique(this: (idList<idVoiceEvent const *,5> *)&v33, obj: &a16);
    num = v33.num;
    v18 = v34[0].num;
    for ( i = v34[0].list; v33.num > 0; num = v33.num )
    {
      v20 = (unsigned __int8 *)v33.list[num - 1];
      v32[0] = (encounterGroupRole_t)v20;
      if ( num - 1 >= 0 && num - 1 < num )
        v33.num = num - 1;
      v21 = 0;
      if ( v18 <= 0 )
        goto LABEL_12;
      v22 = i;
      while ( *(unsigned __int8 **)v22 != v20 )
      {
        ++v21;
        ++v22;
        if ( v21 >= v18 )
          goto LABEL_12;
      }
      if ( v21 < 0 )
      {
LABEL_12:
        idList<idAnimWebBlendTree *,5>::Append(this: v34, obj: v32);
        v18 = v34[0].num;
        i = v34[0].list;
      }
      v23 = *v20;
      switch ( v23 )
      {
        case 4u:
          v32[0] = *((encounterGroupRole_t *)v20 + 20);
          idList<idAnimWebBlendTree *,5>::Append(this: &v33, obj: v32);
          v24 = *((_DWORD *)v20 + 15);
          if ( v24 > 0 )
          {
            v25 = 0;
            do
            {
              v32[0] = *(encounterGroupRole_t *)(v25 + *((_DWORD *)v20 + 14));
              idList<idAnimWebBlendTree *,5>::Append(this: &v33, obj: v32);
              --v24;
              v25 += 4;
            }
            while ( v24 != 0 );
          }
          break;
        case 3u:
        case 5u:
          v28 = *((_DWORD *)v20 + 15);
          if ( v28 > 0 )
          {
            v29 = 0;
            do
            {
              v32[0] = *(encounterGroupRole_t *)(v29 + *((_DWORD *)v20 + 14));
              idList<idAnimWebBlendTree *,5>::Append(this: &v33, obj: v32);
              --v28;
              v29 += 4;
            }
            while ( v28 != 0 );
          }
          break;
        case 6u:
          v26 = *((_DWORD *)v20 + 2);
          if ( v26 > 0 )
          {
            v27 = 0;
            do
            {
              v32[0] = *(encounterGroupRole_t *)(v27 + *((_DWORD *)v20 + 1));
              idList<idAnimWebBlendTree *,5>::Append(this: &v33, obj: v32);
              --v26;
              v27 += 4;
            }
            while ( v26 != 0 );
          }
          break;
        default:
          if ( (_cntlzw(v23) & 0x20) != 0 )
          {
            v32[0] = *((encounterGroupRole_t *)v20 + 1);
            if ( v32[0] != ROLE_NONE )
              idList<idAnimWebBlendTree *,5>::Append(this: &v33, obj: v32);
            v32[0] = *((encounterGroupRole_t *)v20 + 2);
            if ( v32[0] != ROLE_NONE )
              idList<idAnimWebBlendTree *,5>::Append(this: &v33, obj: v32);
          }
          break;
      }
    }
    if ( (v33.listStatic == 0 || v33.listStatic == 2) && v33.list != nullptr )
      idMem::Free(this: &mem, ptr: v33.list, align: ALIGN_16);
    if ( v18 > 0 )
    {
      v30 = i - 1;
      for ( j = v18; j != 0; --j )
      {
        allocator->Free(this: allocator, a2: *((idMD6Node **)v30++ + 1));
        *v30 = ROLE_NONE;
      }
    }
    allocator->Size(this: allocator);
    if ( (v34[0].listStatic == 0 || v34[0].listStatic == 2) && i != nullptr )
      idMem::Free(this: &mem, ptr: i, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$249332
// EA  : 0x826DD320
// RVA : 0x006DD320
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_249332()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$249333
// EA  : 0x826DD348
// RVA : 0x006DD348
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_249333()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ?EnumerateTreeNodes_r@@YAXPBVidMD6Node@@AAV?$idList@PBVidMD6Node@@$04@@@Z
// EA  : 0x826DD370
// RVA : 0x006DD370
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall EnumerateTreeNodes_r(
        const idMD6Node *node,
        idList<enum encounterGroupRole_t,5> *nodes,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        const idMD6Node *a12)
{
  const idMD6Node *v13; // r29
  int type; // r11
  char v15; // r11
  bool v16; // zf
  const idMD6Node *v17; // r3
  const idMD6Node *v18; // r31
  int v19; // r31
  int v20; // r30
  const idMD6Node *v21; // r3
  int v22; // r31
  int v23; // r30
  int v24; // r31
  int v25; // r30
  const idMD6Node *v26; // r3

  a12 = node;
  v13 = node;
  idList<idAnimWebBlendTree *,5>::Append(this: nodes, obj: (const encounterGroupRole_t *)&a12);
  type = v13->type;
  if ( type == 4 )
  {
LABEL_13:
    EnumerateTreeNodes_r(node: *(const idMD6Node **)&v13[80].type, (idList<idMD6Node const *,5> *)nodes);
    if ( *(int *)&v13[60].type > 0 )
    {
      v19 = 0;
      v20 = *(_DWORD *)&v13[60].type;
      do
      {
        v21 = *(const idMD6Node **)(*(_DWORD *)&v13[56].type + v19);
        if ( v21 != nullptr )
          EnumerateTreeNodes_r(node: v21, (idList<idMD6Node const *,5> *)nodes);
        --v20;
        v19 += 4;
      }
      while ( v20 != 0 );
    }
  }
  else
  {
    while ( type != 3 && type != 5 )
    {
      if ( type == 6 )
      {
        v22 = *(_DWORD *)&v13[8].type;
        if ( v22 > 0 )
        {
          v23 = 0;
          do
          {
            EnumerateTreeNodes_r(
              node: *(const idMD6Node **)(v23 + *(_DWORD *)&v13[4].type),
              (idList<idMD6Node const *,5> *)nodes);
            --v22;
            v23 += 4;
          }
          while ( v22 != 0 );
        }
        return;
      }
      if ( type == 0 || (v16 = type != 4, v15 = 0, !v16) )
        v15 = 1;
      if ( v15 == 0 )
        return;
      v17 = *(const idMD6Node **)&v13[4].type;
      if ( v17 != nullptr )
        EnumerateTreeNodes_r(node: v17, (idList<idMD6Node const *,5> *)nodes);
      v18 = *(const idMD6Node **)&v13[8].type;
      if ( v18 == nullptr )
        return;
      a12 = *(const idMD6Node **)&v13[8].type;
      v13 = v18;
      idList<idAnimWebBlendTree *,5>::Append(this: nodes, obj: (const encounterGroupRole_t *)&a12);
      type = v18->type;
      if ( type == 4 )
        goto LABEL_13;
    }
    if ( *(int *)&v13[60].type > 0 )
    {
      v24 = 0;
      v25 = *(_DWORD *)&v13[60].type;
      do
      {
        v26 = *(const idMD6Node **)(*(_DWORD *)&v13[56].type + v24);
        if ( v26 != nullptr )
          EnumerateTreeNodes_r(node: v26, (idList<idMD6Node const *,5> *)nodes);
        --v25;
        v24 += 4;
      }
      while ( v25 != 0 );
    }
  }
}


// ========================================================================
// ?EnumerateTreeNodes@@YAXPBVidMD6Node@@AAV?$idList@PBVidMD6Node@@$04@@@Z
// EA  : 0x826DD4E0
// RVA : 0x006DD4E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall EnumerateTreeNodes(const idMD6Node *tree, idList<idVehicleState *,5> *nodes, int a3, int a4)
{
  int size; // r11
  int v7; // r5
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  const idMD6Node *v11; // [sp+14h] [-5Ch]

  if ( nodes->size < 0 )
    idList<idThread *,58>::Clear(this: nodes);
  size = nodes->size;
  v7 = __CFADD__(-size, size ^ 0x80000000) - 1;
  nodes->num = v7 & size;
  if ( tree != nullptr )
    EnumerateTreeNodes_r(
      node: tree,
      (idList<enum encounterGroupRole_t,5> *)nodes,
      a3: v7,
      a4,
      a5: (size ^ 0x80000000) - size,
      a6: -size,
      a7: size ^ 0x80000000,
      a8: 0,
      a9: v8,
      a10: v9,
      a11: v10,
      a12: v11);
}


// ========================================================================
// ?FreeUnreferencedLeaves@@YAXPAVidMD6Allocator@@PBVidMD6Node@@AAV?$idList@UexistingNode_t@idAnimWebBlendEquation@@$04@@@Z
// EA  : 0x826DD568
// RVA : 0x006DD568
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall FreeUnreferencedLeaves(
        idMD6Allocator *allocator,
        const idMD6Node *tree,
        idList<idAnimWebBlendEquation::existingNode_t,5> *existingNodes)
{
  int v6; // r6
  int v7; // r5
  int num; // r4
  int v9; // r28
  int v10; // r8
  int v11; // r29
  int v12; // r10
  idVehicleState **list; // r11
  int v14; // r11
  unsigned int v15; // r10
  idAnimWebBlendEquation::existingNode_t *v16; // r11
  idAnimWebBlendEquation::existingNode_t *v17; // r9
  unsigned int v18; // r10
  idList<idVehicleState *,5> v19[5]; // [sp+50h] [-50h] BYREF

  memset(v19, 0, 14);
  v19[0].memTag = 5;
  v19[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: v19);
  num = existingNodes->num;
  if ( num > v19[0].size )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)v19, newsize: num);
  EnumerateTreeNodes(tree, nodes: v19, a3: v7, a4: v6);
  v9 = existingNodes->num - 1;
  if ( v9 >= 0 )
  {
    v10 = v19[0].num;
    v11 = v9;
    do
    {
      v12 = 0;
      if ( v10 <= 0 )
        goto LABEL_11;
      list = v19[0].list;
      while ( *list != (idVehicleState *)existingNodes->list[v11].node )
      {
        ++v12;
        ++list;
        if ( v12 >= v10 )
          goto LABEL_11;
      }
      if ( v12 >= v10 )
      {
LABEL_11:
        allocator->Free(this: allocator, a2: existingNodes->list[v11].node);
        v14 = existingNodes->num;
        if ( v9 < v14 )
        {
          v15 = v14 - 1;
          existingNodes->num = v14 - 1;
          if ( v9 != v14 - 1 )
          {
            v16 = existingNodes->list;
            v17 = &existingNodes->list[v11];
            v18 = v15;
            *(_DWORD *)v16[v11].name = *(_DWORD *)existingNodes->list[v18].name;
            *(_DWORD *)&v17->name[4] = *(_DWORD *)&v16[v18].name[4];
            v17->node = v16[v18].node;
          }
        }
        v10 = v19[0].num;
      }
      --v9;
      --v11;
    }
    while ( v9 >= 0 );
  }
  if ( (v19[0].listStatic == 0 || v19[0].listStatic == 2) && v19[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v19[0].list, align: ALIGN_16);
}


// ========================================================================
// __unwind$249922
// EA  : 0x826DD6EC
// RVA : 0x006DD6EC
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_249922()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 160 + 80));
}


// ========================================================================
// ?InternalShutdown@idAnimator_BlendEq@@MAAXPAVidAnimStack@@@Z
// EA  : 0x826DD848
// RVA : 0x006DD848
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall idAnimator_BlendEq::InternalShutdown(
        idAnimator_BlendEq *this,
        idAnimStack *animStack,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idMD6Branch *mergeBranch; // r11
  struct idMD6BlockAlloc *p_md6Allocator; // r30
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+Ch] [-74h]
  int v14; // [sp+10h] [-70h]
  int v15; // [sp+14h] [-6Ch]
  int v16; // [sp+18h] [-68h]
  int v17; // [sp+1Ch] [-64h]
  int v18; // [sp+20h] [-60h]
  const idVoiceEvent *v19; // [sp+24h] [-5Ch]

  mergeBranch = this->mergeBranch;
  if ( mergeBranch != nullptr )
  {
    p_md6Allocator = &animStack->md6Allocator;
    idAnimator_BlendEq::Free(
      this,
      allocator: &animStack->md6Allocator,
      root: (const idVoiceEvent *)mergeBranch->right,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9: v12,
      a10: v13,
      a11: v14,
      a12: v15,
      a13: v16,
      a14: v17,
      a15: v18,
      a16: v19);
    this->mergeBranch->right = nullptr;
    animStack->md6Allocator.Free(this: p_md6Allocator, a2: this->mergeBranch);
    this->mergeBranch = nullptr;
  }
}


// ========================================================================
// ?ParseBlendEquation@idAnimator_BlendEq@@QAAXPAVidAnimStack@@HABVidModelInfo@idDeclAnimWebNode@@@Z
// EA  : 0x826DD8B0
// RVA : 0x006DD8B0
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall idAnimator_BlendEq::ParseBlendEquation(
        idAnimator_BlendEq *this,
        idAnimStack *animStack,
        int startTime,
        const idDeclAnimWebNode::idModelInfo *modelInfo,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idMD6Branch *mergeBranch; // r11
  idTreeAnimator *treeAnimator; // r11
  const idMD6Model *model; // r20
  int v15; // r27
  unsigned int v16; // r28
  idAnimator_BlendEq::idNamedAnim *v17; // r30
  idMD6Leaf::wrapMode_t v18; // r8
  idMD6LeafPlay *v19; // r3
  idMD6LeafPlay *v20; // r26
  const idDeclVehicleUpgrade **v21; // r30
  int num; // r4
  char v23; // r28
  int v24; // r10
  int v25; // r9
  int v26; // r8
  int v27; // r6
  idList<idAnimWebBlendEquation::existingNode_t,5> *v28; // [sp+8h] [-228h]
  int v29; // [sp+8h] [-228h]
  idMD6Node **v30; // [sp+Ch] [-224h]
  int v31; // [sp+Ch] [-224h]
  idList<idAnimWebScalarPair,33> *v32; // [sp+10h] [-220h]
  int v33; // [sp+10h] [-220h]
  int v34; // [sp+14h] [-21Ch]
  int v35; // [sp+14h] [-21Ch]
  int v36; // [sp+18h] [-218h]
  int v37; // [sp+18h] [-218h]
  int v38; // [sp+1Ch] [-214h]
  int v39; // [sp+1Ch] [-214h]
  int v40; // [sp+20h] [-210h]
  int v41; // [sp+20h] [-210h]
  const idVoiceEvent *v42; // [sp+24h] [-20Ch]
  const idVoiceEvent *v43; // [sp+24h] [-20Ch]
  int v44; // [sp+28h] [-208h]
  int v45; // [sp+2Ch] [-204h]
  int v46; // [sp+30h] [-200h]
  int v47; // [sp+34h] [-1FCh]
  int v48; // [sp+38h] [-1F8h]
  int v49; // [sp+3Ch] [-1F4h]
  int v50; // [sp+40h] [-1F0h]
  int v51; // [sp+44h] [-1ECh]
  int v52; // [sp+48h] [-1E8h]
  int v53; // [sp+4Ch] [-1E4h]
  int v54; // [sp+50h] [-1E0h]
  int v55; // [sp+58h] [-1D8h]
  int v56; // [sp+60h] [-1D0h]
  idVoiceEvent *right; // [sp+70h] [-1C0h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v58; // [sp+80h] [-1B0h] BYREF
  idAnimWebBlendEquation v59; // [sp+90h] [-1A0h] BYREF

  mergeBranch = this->mergeBranch;
  if ( mergeBranch != nullptr )
  {
    right = (idVoiceEvent *)mergeBranch->right;
    if ( right != nullptr )
    {
      idAnimator_BlendEq::Free(
        this,
        allocator: &animStack->md6Allocator,
        root: right,
        a4: (int)modelInfo,
        a5,
        a6,
        a7,
        a8,
        a9: (int)v28,
        a10: (int)v30,
        a11: (int)v32,
        a12: v34,
        a13: v36,
        a14: v38,
        a15: v40,
        a16: v42);
      this->mergeBranch->right = nullptr;
    }
    idList<idAnimWebScalarPair,33>::SetNum(this: &this->scalarPairs, newNum: 0);
    if ( this->blendEq.len != 0 )
    {
      treeAnimator = animStack->treeAnimator;
      if ( treeAnimator != nullptr )
      {
        model = treeAnimator->decl->model;
        idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v58);
        idList<idAnimWebBlendEquation::existingNode_t,5>::SetNum(
          this: (idList<idAAS2DebugAreaModelData::areaTri_t,5> *)&v58,
          newNum: this->namedAnims.num);
        v15 = 0;
        if ( this->namedAnims.num <= 0 )
        {
LABEL_10:
          num = this->scalars.num;
          if ( num > this->scalarPairs.size )
            idList<idAnimWebScalarPair,33>::Resize(
              this: (idList<idAnimWebScalarPair,5> *)&this->scalarPairs,
              newsize: num);
          idList<idAnimWebScalarPair,33>::SetNum(this: &this->scalarPairs, newNum: 0);
          right = nullptr;
          idAnimWebBlendEquation::idAnimWebBlendEquation(this: &v59);
          v23 = idAnimWebBlendEquation::Parse(
                  this: &v59,
                  modelInfo,
                  model,
                  allocator: &animStack->md6Allocator,
                  time: startTime,
                  ticksPerSec_: 16,
                  equation: this->blendEq.data,
                  scalars: (idList<idAnimWebScalar,5> *)&this->scalars,
                  existingNodes: v28,
                  root: v30,
                  scalarPairs: v32,
                  a12: v34,
                  a13: v36,
                  a14: v38,
                  a15: v40,
                  a16: (int)v42,
                  a17: v44,
                  a18: v45,
                  a19: v46,
                  a20: v47,
                  a21: v48,
                  a22: v49,
                  a23: v50,
                  a24: v51,
                  a25: v52,
                  a26: v53,
                  a27: v54,
                  a28: (idList<idAnimWebBlendEquation::existingNode_t,5> *)&v58,
                  a29: v55,
                  a30: (idMD6Node **)&right,
                  a31: v56,
                  a32: (idList<idAnimWebScalarPair,5> *)&this->scalarPairs);
          FreeUnreferencedLeaves(
            allocator: &animStack->md6Allocator,
            tree: (const idMD6Node *)right,
            existingNodes: (idList<idAnimWebBlendEquation::existingNode_t,5> *)&v58);
          if ( v23 == 0 )
          {
            idAnimator_BlendEq::Free(
              this,
              allocator: &animStack->md6Allocator,
              root: right,
              a4: v27,
              a5: 0,
              a6: v26,
              a7: v25,
              a8: v24,
              a9: v29,
              a10: v31,
              a11: v33,
              a12: v35,
              a13: v37,
              a14: v39,
              a15: v41,
              a16: v43);
            this->mergeBranch->right = nullptr;
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v59.allocatedNodes);
LABEL_16:
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v58);
            return;
          }
        }
        else
        {
          v16 = 0;
          while ( 1 )
          {
            v17 = &this->namedAnims.list[v16 / 3];
            v19 = (idMD6LeafPlay *)animStack->md6Allocator.Alloc(this: &animStack->md6Allocator, a2: 2);
            v20 = v19;
            if ( v17->anim == nullptr )
              break;
            idMD6LeafPlay::Init(
              this: v19,
              anim: v17->anim,
              gameTime: 0,
              ticksPerSec: 0,
              frame: 0,
              rateScale: v17->rate,
              wrapMode: v18,
              weightGroup: (const md6WeightGroup_t)v17->wrapMode);
            v21 = &v58.list[v16];
            idStr::snPrintf(dest: (char *)&v58.list[v16], size: 8, fmt: "anim%d", v15++);
            v21[2] = (const idDeclVehicleUpgrade *)v20;
            v16 += 3;
            if ( v15 >= this->namedAnims.num )
              goto LABEL_10;
          }
          idLib::Error(fmt: "idAnimator_BlendEq::ParseBlendEquation() - Anim %d was not strong loaded.", v15);
        }
        this->mergeBranch->right = (idMD6Node *)right;
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v59.allocatedNodes);
        goto LABEL_16;
      }
    }
  }
}


// ========================================================================
// $LN84
// EA  : 0x826DDACC
// RVA : 0x006DDACC
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _LN84()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 560 + 128));
}


// ========================================================================
// __unwind$250100
// EA  : 0x826DDAF4
// RVA : 0x006DDAF4
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_250100()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(v0 - 560 + 144));
}


// ========================================================================
// ?CopyScalars@idAnimator_BlendEq@@AAAXPBVidAnimStack@@HE@Z
// EA  : 0x826DDC60
// RVA : 0x006DDC60
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall idAnimator_BlendEq::CopyScalars(
        idAnimator_BlendEq *this,
        const idAnimStack *stack,
        int curTime,
        unsigned __int8 fieldFlags)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  int v9; // r16
  unsigned __int8 v10; // r17
  int v11; // r21
  idAnimWebScalarPair *v12; // r29
  idMD6Node *node; // r28
  int type; // r11
  char v15; // r11
  bool v16; // zf
  int v17; // r11
  char v18; // r11
  int fieldType; // r11
  double Scalar; // fp1
  int v21; // r4
  signed int data1; // r9
  int v23; // r29
  const idMD6Anim *anim; // r27
  int numFrames; // r26
  idMD6AnimData *animData; // r11
  int v27; // r29
  idMD6AnimData *v28; // r11
  int v29; // r27
  int v30; // r5
  const char *v31; // r29
  unsigned __int16 Frame; // r3
  int v33; // r11
  __int64 v34; // r9
  const idMD6Anim *v35; // r10
  double v36; // fp0
  idMD6AnimData *v37; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v39; // r30
  int v40; // r3
  __int64 totalTicks; // r11
  __int64 v42; // r9
  int v43; // [sp+54h] [-ACh]
  idPLogScope v44[3]; // [sp+58h] [-A8h] BYREF

  RD_EventBegin(name: "idAnimator_BlendEq::InternalPreBlendTree");
  LODWORD(v7) = "idAnimator_BlendEq::InternalPreBlendTree";
  HIDWORD(v7) = 2;
  idPLogScope::idPLogScope(this: v44, pl: &::pLog, gMask: v7, label: v8);
  if ( this->scalarMem != nullptr )
  {
    v9 = 0;
    if ( this->scalarPairs.num > 0 )
    {
      v10 = fieldFlags;
      v11 = 0;
      do
      {
        v12 = &this->scalarPairs.list[v11];
        if ( (v10 & v12->fieldFlags) != 0 )
        {
          node = v12->node;
          if ( node->type == 3 || node->type == 5 )
          {
            if ( v12->fieldType == 4 )
              *(float *)(4 * v12->coordinateIndex + *(_DWORD *)&node[72].type) = idAnimWebScalar::GetScalar(
                                                                                   this: &this->scalars.list[v12->scalarIndex],
                                                                                   memBlock: this->scalarMem);
            goto LABEL_62;
          }
          if ( node->type == 4 )
          {
            if ( v12->fieldType == 4 )
              *(float *)&node[72].type = idAnimWebScalar::GetScalar(
                                           this: &this->scalars.list[v12->scalarIndex],
                                           memBlock: this->scalarMem);
            goto LABEL_62;
          }
          type = node->type;
          if ( node->type == 0 || type == 3 || type == 4 || (v16 = type != 5, v15 = 0, !v16) )
            v15 = 1;
          if ( v15 != 0 )
          {
            if ( v12->fieldType == 0 )
            {
              *(float *)&node[24].type = idAnimWebScalar::GetScalar(
                                           this: &this->scalars.list[v12->scalarIndex],
                                           memBlock: this->scalarMem);
              *(float *)&node[28].type = idAnimWebScalar::GetScalar(
                                           this: &this->scalars.list[v12->scalarIndex],
                                           memBlock: this->scalarMem);
              *(float *)&node[32].type = 0.0;
            }
            goto LABEL_62;
          }
          if ( node->type == 6 )
          {
            if ( v12->fieldType == 0
              && (v12->fieldFlags & 0x10) != 0
              && (_cntlzw(__fabs(
                            idAnimWebScalar::GetScalar(
                              this: &this->scalars.list[v12->scalarIndex],
                              memBlock: this->scalarMem)) < idMath::FLT_SMALLEST_NON_DENORMAL)
                & 0x20) != 0 )
            {
              *(_DWORD *)&node[76].type |= 1 << v12->data1;
            }
            goto LABEL_62;
          }
          v17 = node->type;
          if ( v17 == 1 || (v16 = v17 != 2, v18 = 0, !v16) )
            v18 = 1;
          if ( v18 == 0 )
            goto LABEL_62;
          if ( node->type == 2 )
          {
            fieldType = v12->fieldType;
            if ( fieldType == 1 )
            {
              Scalar = idAnimWebScalar::GetScalar(
                         this: &this->scalars.list[v12->scalarIndex],
                         memBlock: this->scalarMem);
              idMD6LeafPlay::SetRateScale(this: (idMD6LeafPlay *)node, gameTime: curTime, rs: Scalar);
            }
            else if ( fieldType == 2 )
            {
              v43 = (int)idAnimWebScalar::GetScalar(
                           this: &this->scalars.list[v12->scalarIndex],
                           memBlock: this->scalarMem);
              v21 = v43;
              if ( (v12->fieldFlags & 4) != 0 )
              {
                data1 = v12->data1;
                __twllei(data1, 0);
                __twlgei(data1 & ~(__ROL4__(v43, 1) - 1), 0xFFFFFFFF);
                v21 = v43 % data1;
              }
              if ( (v12->fieldFlags & 8) != 0 )
                v21 += v12->data2;
              if ( v21 >= 0 && v21 < this->namedAnims.num )
              {
                v23 = v21;
                anim = this->namedAnims.list[v21].anim;
                if ( anim != nullptr )
                {
                  *(_DWORD *)&node[4].type = anim;
                  idMD6LeafPlay::SetRateScale(
                    this: (idMD6LeafPlay *)node,
                    gameTime: curTime,
                    rs: this->namedAnims.list[v23].rate);
                  numFrames = 0;
                  node[9].type = this->namedAnims.list[v23].wrapMode;
                  animData = anim->animData;
                  v27 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
                  if ( animData != nullptr )
                    numFrames = animData->numFrames;
                  if ( idMD6LeafPlay::GetFrame(
                         this: (idMD6LeafPlay *)node,
                         gameTime: curTime,
                         ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz) >= numFrames )
                  {
                    v28 = anim->animData;
                    v29 = 0;
                    if ( v28 != nullptr )
                      v29 = v28->numFrames;
                    v30 = v27;
                    v31 = *(const char **)(*(_DWORD *)&node[4].type + 8);
                    Frame = idMD6LeafPlay::GetFrame(this: (idMD6LeafPlay *)node, gameTime: curTime, ticksPerSec: v30);
                    idLib::Warning(
                      fmt: "Leaf '%s' current frame is out of range for indexed anim '%s'! Cur = %d, range = [0, %d)",
                      v31,
                      v31,
                      Frame,
                      v29);
                  }
                }
                goto LABEL_62;
              }
              goto LABEL_59;
            }
          }
          else if ( node->type == 1 )
          {
            v33 = v12->fieldType;
            if ( v33 == 3 )
            {
              *(float *)&node[52].type = idAnimWebScalar::GetScalar(
                                           this: &this->scalars.list[v12->scalarIndex],
                                           memBlock: this->scalarMem);
            }
            else if ( v33 == 2 )
            {
              v21 = (int)idAnimWebScalar::GetScalar(
                           this: &this->scalars.list[v12->scalarIndex],
                           memBlock: this->scalarMem);
              if ( (v12->fieldFlags & 4) != 0 )
              {
                LODWORD(v34) = v12->data1;
                HIDWORD(v34) = __ROL4__(v21, 1) - 1;
                __twllei(v34, 0);
                __twlgei(v34 & ~HIDWORD(v34), 0xFFFFFFFF);
                v21 %= (int)v34;
              }
              if ( (v12->fieldFlags & 8) != 0 )
                v21 += v12->data2;
              if ( v21 >= 0 && v21 < this->namedAnims.num )
              {
                v35 = this->namedAnims.list[v21].anim;
                if ( v35 != nullptr )
                {
                  *(_DWORD *)&node[4].type = v35;
                  v36 = *(float *)&node[52].type;
                  node[9].type = this->namedAnims.list[v21].wrapMode;
                  LODWORD(v34) = 0;
                  v37 = v35->animData;
                  if ( v37 != nullptr )
                    LODWORD(v34) = v37->numFrames;
                  v44[1] = (idPLogScope)v34;
                  if ( v36 >= (float)v34 )
                    idLib::Warning(
                      fmt: "Leaf '%s' current frame is out of range for indexed anim '%s'! Cur = %f, range = [0, %d)",
                      v35->name.str,
                      v35->name.str,
                      v36,
                      LODWORD(v36));
                }
                goto LABEL_62;
              }
LABEL_59:
              idLib::Warning(
                fmt: "Anim array index out of range! Index = %d ( scalar %s ), range = [0,%d)",
                v21,
                this->scalars.list[v12->scalarIndex].name.str,
                this->namedAnims.num);
            }
          }
        }
LABEL_62:
        ++v9;
        ++v11;
      }
      while ( v9 < this->scalarPairs.num );
    }
  }
  if ( v44[0].logIndex >= 0 )
  {
    pLog = v44[0].pLog;
    v39 = &v44[0].pLog->logEntries.list[v44[0].logIndex];
    v40 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v39->totalTicks;
    HIDWORD(totalTicks) = v39->parent;
    LODWORD(v42) = v40 - totalTicks;
    v39->totalTicks = v42;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$250301
// EA  : 0x826DE2B4
// RVA : 0x006DE2B4
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_250301()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 104));
}


// ========================================================================
// __unwind$250302
// EA  : 0x826DE2DC
// RVA : 0x006DE2DC
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_250302()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 88));
}


// ========================================================================
// ?InternalStart@idAnimator_BlendEq@@MAAXPBVidAnimStack@@HV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x826DE308
// RVA : 0x006DE308
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall idAnimator_BlendEq::InternalStart(
        idAnimator_BlendEq *this,
        const idAnimStack *stack,
        int curTime,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *blendDurationTicks)
{
  idAnimator_BlendEq::CopyScalars(this, stack, curTime, fieldFlags: 2u);
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_BlendEq@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826DE3A0
// RVA : 0x006DE3A0
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall idAnimator_BlendEq::InternalPreBlendTree(
        idAnimator_BlendEq *this,
        const idAnimStack *stack,
        int curTime,
        const int ticksPerSec)
{
  idAnimator_BlendEq::CopyScalars(this, stack, curTime, fieldFlags: 1u);
}


// ========================================================================
// ?SetBlendEquation@idAnimator_BlendEq@@QAAXPAVidAnimStack@@HPBDABVidModelInfo@idDeclAnimWebNode@@@Z
// EA  : 0x826DE3B0
// RVA : 0x006DE3B0
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void __fastcall idAnimator_BlendEq::SetBlendEquation(
        idAnimator_BlendEq *this,
        idAnimStack *animStack,
        int startTime,
        const char *blendEq,
        const idDeclAnimWebNode::idModelInfo *modelInfo)
{
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  int v13; // r26
  idPair<idStr,float> *list; // r25
  int size; // r22
  int v16; // r28
  int v17; // r29
  idAnimWebScalar *v18; // r30
  char v19; // r11
  idPair<idStr,float> *v20; // r25
  int KeyForString; // r3
  int i; // r23
  idAnimWebScalar *v23; // r28
  int v24; // r3
  int v25; // r30
  idPair<idStr,float> *v26; // r29
  idStr *p_first; // r29
  int j; // r30
  idList<idPair<idStr,float>,5> v29; // [sp+60h] [-90h] BYREF
  idHashIndex v30[4]; // [sp+70h] [-80h] BYREF

  idStr::operator=(this: &this->blendEq, text: blendEq);
  idAnimator_BlendEq::ParseBlendEquation(this, animStack, startTime, modelInfo, a5: v12, a6: v11, a7: v10, a8: v9);
  if ( this->scalarMem != nullptr )
  {
    v13 = 0;
    list = nullptr;
    *(_WORD *)&v29.memTag = 1280;
    size = 0;
    memset(&v29, 0, 14);
    v30[0].memTag = TAG_HASHINDEX;
    idHashIndex::InternalInit(this: v30, initialHashSize: 1024, initialIndexSize: 1024);
    v16 = 0;
    if ( this->scalars.num > 0 )
    {
      v17 = 0;
      do
      {
        v18 = &this->scalars.list[v17];
        if ( (unsigned __int16)v18->scalarIndex < 0x8000u || (v19 = 0, v18->scalarPtr != nullptr) )
          v19 = 1;
        if ( v19 != 0 )
        {
          v20 = idList<idPair<idStr,float>,5>::Alloc(this: &v29);
          idStr::operator=(this: &v20->first, text: v18->name.str);
          v20->second = idAnimWebScalar::GetScalar(this: v18, memBlock: this->scalarMem);
          KeyForString = idHashIndex::GenerateKeyForString(this: v30, string: v18->name.str, caseSensitive: true);
          idHashIndex::Add(this: v30, key: KeyForString, index: v29.num - 1);
        }
        ++v16;
        ++v17;
      }
      while ( v16 < this->scalars.num );
      size = v29.size;
      list = v29.list;
    }
    idAnimWebBlendEquation::AllocateUndeclaredScalars(
      scalars: (idList<idAnimWebScalar,5> *)&this->scalars,
      block: this->scalarMem);
    for ( i = 0; i < this->scalars.num; ++v13 )
    {
      v23 = &this->scalars.list[v13];
      v24 = idHashIndex::GenerateKeyForString(this: v30, string: v23->name.str, caseSensitive: true);
      v25 = v30[0].hash[v30[0].lookupMask & v30[0].hashMask & v24];
      if ( v25 != -1 )
      {
        while ( 1 )
        {
          v26 = &list[v25];
          if ( idStr::Icmp(s1: v23->name.str, s2: v26->first.data) == 0 )
            break;
          v25 = v30[0].indexChain[v30[0].lookupMask & v25];
          if ( v25 == -1 )
            goto LABEL_17;
        }
        idAnimWebScalar::SetScalar(this: v23, memBlock: this->scalarMem, f: v26->second);
      }
LABEL_17:
      ++i;
    }
    idHashIndex::Free(this: v30);
    if ( (v29.listStatic == 0 || v29.listStatic == 2) && list != nullptr )
    {
      if ( size > 0 )
      {
        p_first = &list->first;
        for ( j = size; j != 0; --j )
        {
          idStr::FreeData(this: p_first);
          p_first = (idStr *)((char *)p_first + 36);
        }
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$250759
// EA  : 0x826DE614
// RVA : 0x006DE614
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_250759()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$250760
// EA  : 0x826DE63C
// RVA : 0x006DE63C
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_250760()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(v0 - 240 + 112));
}


// ========================================================================
// ?InternalInit@idAnimator_BlendEq@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826DE670
// RVA : 0x006DE670
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

int __fastcall idAnimator_BlendEq::InternalInit(idAnimator_BlendEq *this, const idAnimatorParms_Base *parms)
{
  idMD6Branch *v4; // r3
  idDeclAnimWebNode::idModelInfo v6[2]; // [sp+60h] [-50h] BYREF

  v4 = (idMD6Branch *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 0);
  this->mergeBranch = v4;
  v4->left = nullptr;
  this->mergeBranch->right = nullptr;
  idList<idAnimWebScalar,5>::operator=(
    this: &this->scalars,
    other: (const idList<idAnimWebScalar,33> *)&parms[1].name.baseBuffer[16]);
  this->scalarMem = (idScalarMemBlock *)parms[1].filterGroup;
  idList<idAnimator_BlendEq::idNamedAnim,5>::operator=(
    this: &this->namedAnims,
    other: (const idList<idAnimator_BlendEq::idNamedAnim,33> *)&parms[1].alpha);
  idDeclAnimWebNode::idModelInfo::idModelInfo(this: v6);
  idAnimator_BlendEq::SetBlendEquation(
    this,
    animStack: parms->animStack,
    startTime: 0,
    blendEq: (const char *)parms[1].name.len,
    modelInfo: v6);
  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: v6);
  return 1;
}


// ========================================================================
// __unwind$250984
// EA  : 0x826DE714
// RVA : 0x006DE714
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.cpp
// ========================================================================

void _unwind_250984()
{
  int v0; // r12

  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: (idDeclAnimWebNode::idModelInfo *)(v0 - 176 + 96));
}

