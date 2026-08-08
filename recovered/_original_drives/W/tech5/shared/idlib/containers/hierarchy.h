
// ========================================================================
// ?GetPriorSiblingNode@?$idHierarchy@VidTypeInfo@@@@ABAPAV1@XZ
// EA  : 0x826F9A68
// RVA : 0x006F9A68
// PDB : w:\tech5\shared\idlib\containers\hierarchy.h
// ========================================================================

void __fastcall idHierarchy<idTypeInfo>::GetPriorSiblingNode(
        idHierarchy<idTypeInfo> *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  idHierarchy<idTypeInfo> *child; // r11

  if ( this->parent != nullptr )
  {
    child = this->parent->child;
    if ( child != this )
    {
      while ( child != nullptr )
      {
        child = child->sibling;
        if ( child == this )
          return;
      }
      idLib::Error(
        fmt: "idHierarchy::GetPriorSibling: could not find node in parent's list of children",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        this);
    }
  }
}


// ========================================================================
// ?ParentTo@?$idHierarchy@VidTypeInfo@@@@QAAXAAV1@@Z
// EA  : 0x826F9E08
// RVA : 0x006F9E08
// PDB : w:\tech5\shared\idlib\containers\hierarchy.h
// ========================================================================

void __fastcall idHierarchy<idTypeInfo>::ParentTo(
        idHierarchy<idTypeInfo> *this,
        idHierarchy<idTypeInfo> *node,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  int v9; // r3

  if ( this->parent != nullptr )
  {
    idHierarchy<idTypeInfo>::GetPriorSiblingNode(this, a2: (int)node, a3, a4, a5, a6, a7);
    if ( v9 != 0 )
      *(_DWORD *)(v9 + 4) = this->sibling;
    else
      this->parent->child = this->sibling;
  }
  this->parent = node;
  this->sibling = nullptr;
  this->sibling = node->child;
  node->child = this;
}


// ========================================================================
// ?RemoveFromHierarchy@?$idHierarchy@VidTypeInfo@@@@QAAXXZ
// EA  : 0x826F9E88
// RVA : 0x006F9E88
// PDB : w:\tech5\shared\idlib\containers\hierarchy.h
// ========================================================================

void __fastcall idHierarchy<idTypeInfo>::RemoveFromHierarchy(
        idHierarchy<idTypeInfo> *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  idHierarchy<idTypeInfo> *parent; // r31
  int v9; // r3
  idHierarchy<idTypeInfo> *v10; // r6
  idHierarchy<idTypeInfo> *child; // r11
  idHierarchy<idTypeInfo> *v12; // r10
  idHierarchy<idTypeInfo> *v13; // r7
  idHierarchy<idTypeInfo> *v14; // r11
  idHierarchy<idTypeInfo> **p_sibling; // r9
  idHierarchy<idTypeInfo> *v16; // r10
  idHierarchy<idTypeInfo> *v17; // r7
  idHierarchy<idTypeInfo> *v18; // r11
  idHierarchy<idTypeInfo> **v19; // r9
  idTypeInfo *v20; // r3

  parent = this->parent;
  if ( this->parent != nullptr )
  {
    idHierarchy<idTypeInfo>::GetPriorSiblingNode(this, a2, a3, a4, a5, a6, a7);
    if ( v9 != 0 )
      *(_DWORD *)(v9 + 4) = this->sibling;
    else
      this->parent->child = this->sibling;
  }
  v10 = nullptr;
  child = this->child;
  this->parent = nullptr;
  this->sibling = nullptr;
  if ( parent == nullptr )
    goto _LN80_1;
  if ( child == nullptr )
    return;
  while ( 1 )
  {
    v12 = this->child;
    v13 = v12->parent;
    if ( v12->parent != nullptr )
      break;
LABEL_13:
    v12->sibling = nullptr;
    v12->parent = parent;
    v12->sibling = parent->child;
    parent->child = v12;
    if ( this->child == nullptr )
      return;
  }
  v14 = v13->child;
  if ( v14 == v12 )
  {
    v13->child = v12->sibling;
    goto LABEL_13;
  }
  while ( v14 != nullptr )
  {
    p_sibling = &v14->sibling;
    v14 = v14->sibling;
    if ( v14 == v12 )
    {
      *p_sibling = v12->sibling;
      goto LABEL_13;
    }
  }
  idLib::Error(fmt: "idHierarchy::GetPriorSibling: could not find node in parent's list of children");
_LN80_1:
  if ( child == nullptr )
    return;
  while ( 2 )
  {
    v16 = this->child;
    v17 = v16->parent;
    if ( v16->parent == nullptr )
    {
LABEL_23:
      v16->sibling = v10;
      v16->parent = v10;
      if ( this->child == nullptr )
        return;
      continue;
    }
    break;
  }
  v18 = v17->child;
  if ( v18 == v16 )
  {
    v17->child = v16->sibling;
    goto LABEL_23;
  }
  while ( v18 != nullptr )
  {
    v19 = &v18->sibling;
    v18 = v18->sibling;
    if ( v18 == v16 )
    {
      *v19 = v16->sibling;
      goto LABEL_23;
    }
  }
  idLib::Error(fmt: "idHierarchy::GetPriorSibling: could not find node in parent's list of children");
  idTypeInfo::Init(this: v20);
}


// ========================================================================
// ??1?$idHierarchy@VidTypeInfo@@@@QAA@XZ
// EA  : 0x826FA0B0
// RVA : 0x006FA0B0
// PDB : w:\tech5\shared\idlib\containers\hierarchy.h
// ========================================================================

// attributes: thunk
void __fastcall idHierarchy<idTypeInfo>::~idHierarchy<idTypeInfo>(
        idHierarchy<idTypeInfo> *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  idHierarchy<idTypeInfo>::RemoveFromHierarchy(this, a2, a3, a4, a5, a6, a7);
}

