
// ========================================================================
// ?ForceRootDifferent@idTypeInfoTree@@QAAX_N@Z
// EA  : 0x82FA1868
// RVA : 0x00FA1868
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::ForceRootDifferent(idTypeInfoTree *this, bool set)
{
  if ( this->root != nullptr )
    this->root->diff = set;
}


// ========================================================================
// ??1idTypeInfoPath@@QAA@XZ
// EA  : 0x82FA1928
// RVA : 0x00FA1928
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoPath::~idTypeInfoPath(idTypeInfoPath *this)
{
  idTypeInfoPath *next; // r30

  next = this->next;
  if ( next != nullptr )
  {
    idTypeInfoPath::~idTypeInfoPath(this: this->next);
    idMem::Free(this: &mem, ptr: next, align: ALIGN_16);
  }
  idStr::FreeData(this: &this->name);
}


// ========================================================================
// __unwind$113160_0
// EA  : 0x82FA1978
// RVA : 0x00FA1978
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_113160_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ?FindAndOverwriteNode@idTypeInfoTree@@AAAPAVidTypeInfoNode@@PBD0000PAV2@@Z
// EA  : 0x82FA19A0
// RVA : 0x00FA19A0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

idTypeInfoNode *__fastcall idTypeInfoTree::FindAndOverwriteNode(
        idTypeInfoTree *this,
        char *type,
        char *ops,
        const char *name,
        char *value,
        char *comment,
        idTypeInfoNode *parentNode)
{
  idTypeInfoNode *children; // r31

  if ( parentNode != nullptr )
    children = parentNode->children;
  else
    children = this->root;
  if ( children == nullptr )
    return nullptr;
  while ( idStr::Cmp(s1: children->name.data, s2: name) != 0 )
  {
    children = children->next;
    if ( children == nullptr )
      return nullptr;
  }
  if ( idStr::Cmp(s1: children->type.data, s2: type) == 0 )
    idStr::Cmp(s1: children->ops.data, s2: ops);
  idStr::operator=(this: &children->type, text: type);
  idStr::operator=(this: &children->ops, text: ops);
  idStr::operator=(this: &children->value, text: value);
  idStr::operator=(this: &children->comment, text: comment);
  return children;
}


// ========================================================================
// ?FindNode_r@idTypeInfoTree@@ABAPAVidTypeInfoNode@@ABV1@PBV2@@Z
// EA  : 0x82FA1A68
// RVA : 0x00FA1A68
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

idTypeInfoNode *__fastcall idTypeInfoTree::FindNode_r(
        idTypeInfoTree *this,
        const idTypeInfoTree *tree,
        const idTypeInfoNode *node)
{
  idTypeInfoNode *Node_r; // r31

  if ( node == nullptr )
    return tree->root;
  Node_r = idTypeInfoTree::FindNode_r(this, tree, node: node->parent);
  if ( Node_r == nullptr )
    return nullptr;
  while ( idStr::Cmp(s1: Node_r->name.data, s2: node->name.data) != 0 )
  {
    Node_r = Node_r->next;
    if ( Node_r == nullptr )
      return nullptr;
  }
  if ( node->children != nullptr )
    return Node_r->children;
  else
    return idStr::Cmp(s1: Node_r->value.data, s2: node->value.data) != 0 ? nullptr : Node_r;
}


// ========================================================================
// ?Diff_r@idTypeInfoTree@@AAAXABV1@PAVidTypeInfoNode@@@Z
// EA  : 0x82FA1B10
// RVA : 0x00FA1B10
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::Diff_r(idTypeInfoTree *this, const idTypeInfoTree *tree, idTypeInfoNode *node)
{
  idTypeInfoNode *i; // r30
  idTypeInfoNode *children; // r5
  idTypeInfoNode *Node_r; // r31
  idTypeInfoNode *parent; // r11

  for ( i = node; i != nullptr; i = i->next )
  {
    children = i->children;
    i->diff = false;
    if ( children != nullptr )
    {
      idTypeInfoTree::Diff_r(this, tree, node: children);
    }
    else
    {
      Node_r = idTypeInfoTree::FindNode_r(this, tree, node: i->parent);
      if ( Node_r == nullptr )
        goto LABEL_11;
      while ( idStr::Cmp(s1: Node_r->name.data, s2: i->name.data) != 0 )
      {
        Node_r = Node_r->next;
        if ( Node_r == nullptr )
          goto LABEL_11;
      }
      if ( i->children != nullptr )
      {
        Node_r = Node_r->children;
      }
      else if ( idStr::Cmp(s1: Node_r->value.data, s2: i->value.data) != 0 )
      {
        goto LABEL_11;
      }
      if ( Node_r == nullptr )
      {
LABEL_11:
        parent = i->parent;
        for ( i->diff = true; parent != nullptr; parent = parent->parent )
          parent->diff = true;
      }
    }
  }
}


// ========================================================================
// ?Diff@idTypeInfoTree@@QAAXABV1@@Z
// EA  : 0x82FA1BF8
// RVA : 0x00FA1BF8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::Diff(idTypeInfoTree *this, const idTypeInfoTree *tree)
{
  idTypeInfoTree::Diff_r(this, tree, node: this->root);
}


// ========================================================================
// ?FindPath@idTypeInfoTree@@CAPAVidTypeInfoNode@@PAV2@PBVidTypeInfoPath@@@Z
// EA  : 0x82FA1C00
// RVA : 0x00FA1C00
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

idTypeInfoNode *__fastcall idTypeInfoTree::FindPath(idTypeInfoNode *baseNode, const idTypeInfoPath *path)
{
  idTypeInfoNode *children; // r31

  if ( baseNode == nullptr )
    return nullptr;
  children = baseNode->children;
  if ( children == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( idStr::Cmp(s1: children->name.data, s2: path->name.data) != 0 )
    {
      children = children->next;
      goto LABEL_7;
    }
    path = path->next;
    if ( path == nullptr )
      return children;
    children = children->children;
LABEL_7:
    if ( children == nullptr )
      return nullptr;
  }
}


// ========================================================================
// ?WriteType_r@idTypeInfoTree@@ABAXAAVidTypeInfoFile@@PAVidTypeInfoNode@@_N@Z
// EA  : 0x82FA1DA8
// RVA : 0x00FA1DA8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::WriteType_r(
        idTypeInfoTree *this,
        idTypeInfoFile *file,
        idTypeInfoNode *node,
        bool onlyDiff)
{
  idTypeInfoNode *i; // r30
  idStr v9[2]; // [sp+50h] [-50h] BYREF

  if ( !onlyDiff || node->diff )
  {
    idStr::idStr(this: v9, text: &node->name);
    idTypeInfoFile::WriteType(this: file, type: node->type.data, ops: node->ops.data, name: node->name.data);
    idTypeInfoFile::WriteSkipObject(this: file, skip: node->skip);
    if ( node->children != nullptr )
    {
      idTypeInfoFile::WriteOpeningBrace(this: file);
      idTypeInfoFile::WriteComment(this: file, comment: node->comment.data);
      for ( i = node->children; i != nullptr; i = i->next )
        idTypeInfoTree::WriteType_r(this, file, node: i, onlyDiff);
    }
    else
    {
      if ( node->value.len != 0 )
      {
        idTypeInfoFile::WriteValueString(this: file, value: &node->value);
        idTypeInfoFile::WriteComment(this: file, comment: node->comment.data);
LABEL_11:
        idStr::FreeData(this: v9);
        return;
      }
      idTypeInfoFile::WriteOpeningBrace(this: file);
      idTypeInfoFile::WriteComment(this: file, comment: node->comment.data);
    }
    idTypeInfoFile::WriteClosingBrace(this: file);
    goto LABEL_11;
  }
}


// ========================================================================
// __unwind$113859
// EA  : 0x82FA1EA8
// RVA : 0x00FA1EA8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_113859()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Write@idTypeInfoTree@@QBAXAAVidTypeInfoFile@@_N@Z
// EA  : 0x82FA1ED8
// RVA : 0x00FA1ED8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::Write(idTypeInfoTree *this, idTypeInfoFile *file, bool onlyDiff)
{
  idTypeInfoNode *root; // r28
  BOOL v7; // r25
  idTypeInfoNode *i; // r30
  idStr v9[3]; // [sp+50h] [-60h] BYREF

  root = this->root;
  if ( this->root != nullptr )
  {
    v7 = onlyDiff;
    while ( 1 )
    {
      if ( !v7 || root->diff )
      {
        idStr::idStr(this: v9, text: &root->name);
        idTypeInfoFile::WriteType(this: file, type: root->type.data, ops: root->ops.data, name: root->name.data);
        idTypeInfoFile::WriteSkipObject(this: file, skip: root->skip);
        if ( root->children != nullptr )
          break;
        if ( root->value.len == 0 )
        {
          idTypeInfoFile::WriteOpeningBrace(this: file);
          idTypeInfoFile::WriteComment(this: file, comment: root->comment.data);
LABEL_12:
          idTypeInfoFile::WriteClosingBrace(this: file);
          goto LABEL_13;
        }
        idTypeInfoFile::WriteValueString(this: file, value: &root->value);
        idTypeInfoFile::WriteComment(this: file, comment: root->comment.data);
LABEL_13:
        idStr::FreeData(this: v9);
      }
      root = root->next;
      if ( root == nullptr )
        return;
    }
    idTypeInfoFile::WriteOpeningBrace(this: file);
    idTypeInfoFile::WriteComment(this: file, comment: root->comment.data);
    for ( i = root->children; i != nullptr; i = i->next )
      idTypeInfoTree::WriteType_r(this, file, node: i, onlyDiff);
    goto LABEL_12;
  }
}


// ========================================================================
// __unwind$113941
// EA  : 0x82FA1FEC
// RVA : 0x00FA1FEC
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_113941()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?InsertNode@idTypeInfoTree@@AAAPAVidTypeInfoNode@@PBD0000PAV2@1@Z
// EA  : 0x82FA2118
// RVA : 0x00FA2118
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

idBlockAlloc<idTypeInfoNode,32,114>::element_t *__fastcall idTypeInfoTree::InsertNode(
        idTypeInfoTree *this,
        char *type,
        char *ops,
        char *name,
        char *value,
        char *comment,
        idTypeInfoNode *parentNode,
        idTypeInfoNode *nodeAfter)
{
  idBlockAlloc<idTypeInfoNode,32,114>::element_t *v15; // r31

  v15 = idBlockAlloc<idTypeInfoNode,32,114>::Alloc(this: &this->nodeBlockAlloc);
  idStr::operator=(this: (idStr *)v15, text: type);
  idStr::operator=(this: (idStr *)&v15->buffer[32], text: ops);
  idStr::operator=(this: (idStr *)&v15->buffer[64], text: name);
  idStr::operator=(this: (idStr *)&v15->buffer[96], text: value);
  idStr::operator=(this: (idStr *)&v15->buffer[128], text: comment);
  *(_DWORD *)&v15->buffer[168] = parentNode;
  *(_DWORD *)&v15->buffer[164] = 0;
  *(_DWORD *)&v15->buffer[160] = 0;
  *(_WORD *)&v15->buffer[172] = 1;
  if ( nodeAfter != nullptr )
  {
    nodeAfter->next = (idTypeInfoNode *)v15;
    return v15;
  }
  else
  {
    if ( parentNode != nullptr )
    {
      *(_DWORD *)&v15->buffer[160] = parentNode->children;
      parentNode->children = (idTypeInfoNode *)v15;
    }
    return v15;
  }
}


// ========================================================================
// ?ReadType_r@idTypeInfoTree@@AAAPAVidTypeInfoNode@@AAVidTypeInfoFile@@PAV2@_N@Z
// EA  : 0x82FA21E0
// RVA : 0x00FA21E0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

idTypeInfoNode *__fastcall idTypeInfoTree::ReadType_r(
        idTypeInfoTree *this,
        idTypeInfoFile *file,
        __int64 overwrite,
        __int64 a4)
{
  idTypeInfoNode *v6; // r29
  bool v7; // r22
  idTypeInfoNode *inserted; // r27
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  int v12; // r4
  va *v13; // r3
  bool v14; // r23
  __int64 v15; // r8
  __int64 v16; // r6
  int v17; // r4
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  idTypeInfoNode *v21; // r30
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  __int64 v25; // r8
  __int64 v26; // r6
  int v27; // r4
  int v29; // [sp+8h] [-1158h]
  int v30; // [sp+Ch] [-1154h]
  int v31; // [sp+10h] [-1150h]
  int v32; // [sp+14h] [-114Ch]
  int v33; // [sp+18h] [-1148h]
  int v34; // [sp+1Ch] [-1144h]
  int v35[4]; // [sp+50h] [-1110h] BYREF
  idStr v36; // [sp+60h] [-1100h] BYREF
  idStr v37; // [sp+80h] [-10E0h] BYREF
  idStr v38; // [sp+A0h] [-10C0h] BYREF
  idStr v39; // [sp+C0h] [-10A0h] BYREF
  idStr v40; // [sp+E0h] [-1080h] BYREF
  va v41; // [sp+100h] [-1060h] BYREF

  v6 = (idTypeInfoNode *)HIDWORD(overwrite);
  v7 = overwrite;
  if ( HIDWORD(overwrite) != 0 )
  {
    inserted = *(idTypeInfoNode **)(HIDWORD(overwrite) + 164);
    if ( inserted != nullptr )
    {
      while ( inserted->next != nullptr )
        inserted = inserted->next;
    }
  }
  else
  {
    inserted = nullptr;
  }
  if ( (unsigned __int8)idTypeInfoFile::CheckClosingBrace(this: file, a2: (int)file, a3: overwrite, a4) == 0 )
  {
    while ( 1 )
    {
      v38.allocedAndFlag = 20;
      v38.len = 0;
      v38.data = v38.baseBuffer;
      v38.baseBuffer[0] = 0;
      v37.allocedAndFlag = 20;
      v37.data = v37.baseBuffer;
      v37.len = 0;
      v37.baseBuffer[0] = 0;
      v36.allocedAndFlag = 20;
      v36.data = v36.baseBuffer;
      v36.len = 0;
      v36.baseBuffer[0] = 0;
      LODWORD(v10) = (unsigned __int8)idTypeInfoFile::CheckArrayElementType(
                                        this: file,
                                        type: &v38,
                                        ops: &v37,
                                        name: &v36,
                                        index: v35);
      if ( (_DWORD)v10 == 0 )
        break;
      HIDWORD(v11) = v35[0];
      if ( v35[0] >= 0 )
      {
        v13 = va::va(
                this: &v41,
                fmt: "[%d]",
                a3: v11,
                a4: v10,
                a5: v9,
                a6: v29,
                a7: v30,
                a8: v31,
                a9: v32,
                a10: v33,
                a11: v34);
        idStr::Append(this: &v36, text: v13);
      }
      v40.allocedAndFlag = 20;
      v40.len = 0;
      v40.data = v40.baseBuffer;
      v40.baseBuffer[0] = 0;
      v39.allocedAndFlag = 20;
      v39.data = v39.baseBuffer;
      v39.len = 0;
      v39.baseBuffer[0] = 0;
      v14 = idTypeInfoFile::CheckSkipObject(this: file, a2: v12, a3: v11, a4: v10);
      HIDWORD(v18) = (unsigned __int8)idTypeInfoFile::CheckOpeningBrace(this: file, a2: v17, a3: v16, a4: v15);
      if ( HIDWORD(v18) != 0 )
      {
        idTypeInfoFile::ReadComment(this: file, comment: &v39, a3: v20, a4: v19, a5: v18);
        if ( !v7
          || (v21 = idTypeInfoTree::FindAndOverwriteNode(
                      this,
                      type: v38.data,
                      ops: v37.data,
                      name: v36.data,
                      value: v40.data,
                      comment: v39.data,
                      parentNode: v6)) == nullptr )
        {
          inserted = (idTypeInfoNode *)idTypeInfoTree::InsertNode(
                                         this,
                                         type: v38.data,
                                         ops: v37.data,
                                         name: v36.data,
                                         value: v40.data,
                                         comment: v39.data,
                                         parentNode: v6,
                                         nodeAfter: inserted);
          v21 = inserted;
        }
        if ( v6 == nullptr )
          v6 = v21;
        idTypeInfoTree::ReadType_r(this, file, parentNode: v21, overwrite: v7);
      }
      else
      {
        idTypeInfoFile::ReadValueString(this: file, value: &v40);
        idTypeInfoFile::ReadComment(this: file, comment: &v39, a3: v24, a4: v23, a5: v22);
        if ( !v7
          || (v21 = idTypeInfoTree::FindAndOverwriteNode(
                      this,
                      type: v38.data,
                      ops: v37.data,
                      name: v36.data,
                      value: v40.data,
                      comment: v39.data,
                      parentNode: v6)) == nullptr )
        {
          inserted = (idTypeInfoNode *)idTypeInfoTree::InsertNode(
                                         this,
                                         type: v38.data,
                                         ops: v37.data,
                                         name: v36.data,
                                         value: v40.data,
                                         comment: v39.data,
                                         parentNode: v6,
                                         nodeAfter: inserted);
          v21 = inserted;
        }
        if ( v6 == nullptr )
          v6 = v21;
      }
      v21->skip = v14;
      idStr::FreeData(this: &v39);
      idStr::FreeData(this: &v40);
      idStr::FreeData(this: &v36);
      idStr::FreeData(this: &v37);
      idStr::FreeData(this: &v38);
      if ( (unsigned __int8)idTypeInfoFile::CheckClosingBrace(this: file, a2: v27, a3: v26, a4: v25) != 0 )
        return v6;
    }
    idStr::FreeData(this: &v36);
    idStr::FreeData(this: &v37);
    idStr::FreeData(this: &v38);
  }
  return v6;
}


// ========================================================================
// __unwind$114334
// EA  : 0x82FA24A4
// RVA : 0x00FA24A4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_114334()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4448 + 160));
}


// ========================================================================
// __unwind$114335
// EA  : 0x82FA24CC
// RVA : 0x00FA24CC
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_114335()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4448 + 128));
}


// ========================================================================
// __unwind$114336_0
// EA  : 0x82FA24F4
// RVA : 0x00FA24F4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_114336_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4448 + 96));
}


// ========================================================================
// __unwind$114337_0
// EA  : 0x82FA251C
// RVA : 0x00FA251C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_114337_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4448 + 224));
}


// ========================================================================
// __unwind$114338_0
// EA  : 0x82FA2544
// RVA : 0x00FA2544
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_114338_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4448 + 192));
}


// ========================================================================
// ?CreatePath@idTypeInfoTree@@AAAPAVidTypeInfoNode@@PBVidTypeInfoPath@@PBVidTypeInfoTools@@@Z
// EA  : 0x82FA2578
// RVA : 0x00FA2578
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

idTypeInfoNode *__fastcall idTypeInfoTree::CreatePath(
        idTypeInfoTree *this,
        const idTypeInfoPath *path,
        idTypeInfoTools *ti)
{
  const idTypeInfoPath *v4; // r28
  int len; // r29
  idTypeInfoNode *children; // r30
  idTypeInfoNode *root; // r26
  const idStr *p_name; // r5
  const idStr *v11; // r3
  idTypeInfoNode *v12; // r10
  const idStr *v13; // r3
  idStr v14; // [sp+50h] [-1B0h] BYREF
  idStr v15; // [sp+70h] [-190h] BYREF
  idStr v16; // [sp+90h] [-170h] BYREF
  char v17[128]; // [sp+B0h] [-150h] BYREF
  char v18[208]; // [sp+130h] [-D0h] BYREF

  v14.len = 0;
  v14.allocedAndFlag = 20;
  v4 = path;
  v14.data = v14.baseBuffer;
  v14.baseBuffer[0] = 0;
  memset(v18, 0, 128);
  memset(v17, 0, sizeof(v17));
  if ( this->root == nullptr )
  {
    idStr::FreeData(this: &v14);
    return nullptr;
  }
  len = path->name.len;
  children = this->root->children;
  root = this->root;
  idStr::EnsureAlloced(this: &v14, amount: path->name.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v14.data, Src: v4->name.data, Size: len);
  v14.data[len] = 0;
  v14.len = len;
  while ( children != nullptr )
  {
    if ( idStr::Cmp(s1: children->name.data, s2: v4->name.data) != 0 )
    {
      children = children->next;
    }
    else
    {
      idTypeInfoTools::GetTypeForPath(
        this: ti,
        typeName: this->root->type.data,
        path: v14.data,
        type: v18,
        maxTypeLen: 128,
        ops: v17,
        maxOpsLen: 128);
      idStr::operator=(this: &children->type, text: v18);
      idStr::operator=(this: &children->ops, text: v17);
      p_name = &v4->next->name;
      if ( p_name == nullptr )
      {
        idStr::FreeData(this: &v14);
        return children;
      }
      v4 = v4->next;
      v11 = operator+(result: &v16, a: ".", b: p_name);
      idStr::Append(this: &v14, text: v11);
      idStr::FreeData(this: &v16);
      root = children;
      children = children->children;
    }
  }
  if ( v4 != nullptr )
  {
    while ( 1 )
    {
      idTypeInfoTools::GetTypeForPath(
        this: ti,
        typeName: this->root->type.data,
        path: v14.data,
        type: v18,
        maxTypeLen: 128,
        ops: v17,
        maxOpsLen: 128);
      v12 = root->children;
      if ( v12 != nullptr )
      {
        while ( v12->next != nullptr )
          v12 = v12->next;
      }
      root = (idTypeInfoNode *)idTypeInfoTree::InsertNode(
                                 this,
                                 type: v18,
                                 ops: v17,
                                 name: v4->name.data,
                                 value: &byte_8200D768,
                                 comment: &byte_8200D768,
                                 parentNode: root,
                                 nodeAfter: v12);
      if ( v4->next == nullptr )
        break;
      v4 = v4->next;
      v13 = operator+(result: &v15, a: ".", b: &v4->name);
      idStr::Append(this: &v14, text: v13);
      idStr::FreeData(this: &v15);
    }
  }
  idStr::FreeData(this: &v14);
  return root;
}


// ========================================================================
// $M114848_0
// EA  : 0x82FA27B8
// RVA : 0x00FA27B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _M114848_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 80));
}


// ========================================================================
// __unwind$114719
// EA  : 0x82FA27E0
// RVA : 0x00FA27E0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_114719()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 144));
}


// ========================================================================
// __unwind$114720
// EA  : 0x82FA2808
// RVA : 0x00FA2808
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_114720()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 112));
}


// ========================================================================
// ?ParsePath@@YAPAVidTypeInfoPath@@AAVidLexer@@@Z
// EA  : 0x82FA2838
// RVA : 0x00FA2838
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

idTypeInfoPath *__fastcall ParsePath(idLexer *src)
{
  idStr *v2; // r17
  idStr *v3; // r19
  __int64 v4; // r8
  idStr *v5; // r3
  idStr *v6; // r30
  bool v7; // r7
  unsigned int allocedAndFlag; // r11
  __int64 v9; // r10
  int v10; // r11
  size_t len; // r29
  int v12; // r4
  bool v13; // zf
  __int64 v14; // r6
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  __int64 v20; // r8
  __int64 v21; // r6
  const idStr *v22; // r3
  idStr *v23; // r3
  idToken v25; // [sp+50h] [-110h] BYREF
  idStr v26; // [sp+A0h] [-C0h] BYREF
  idStr v27[5]; // [sp+C0h] [-A0h] BYREF

  v25.len = 0;
  v25.baseBuffer[0] = 0;
  v25.intvalue = 0;
  v25.floatvalue = -3.4028235e38;
  memset(&v25.whiteSpaceStart_p, 0, 12);
  v25.allocedAndFlag = 20;
  v25.data = v25.baseBuffer;
  v2 = nullptr;
  v3 = nullptr;
  do
  {
    v5 = (idStr *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x24u,
                    tag: TAG_TYPEINFO,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->allocedAndFlag = 20;
      v5->len = 0;
      v6 = v5;
      v5->data = v5->baseBuffer;
      v5->baseBuffer[0] = 0;
      v5[1].len = 0;
    }
    else
    {
      v6 = nullptr;
    }
    idLexer::ExpectTokenType(this: src, type: 4, token: (unsigned int)&v25, a4: v4);
    allocedAndFlag = v6->allocedAndFlag;
    LODWORD(v9) = allocedAndFlag >> 31;
    len = v25.len;
    v12 = v25.len + 1;
    v13 = allocedAndFlag >> 31 == 0;
    v10 = allocedAndFlag & 0x7FFFFFFF;
    if ( v13 )
    {
      if ( v12 > v10 )
        idStr::ReAllocate(this: v6, amount: v12, keepold: false);
    }
    else if ( v12 > v10 )
    {
      HIDWORD(v14) = "amount <= GetAlloced()";
      LODWORD(v14) = 1;
      if ( (unsigned __int8)AssertFailed(
                              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                              expression: v14,
                              inlineBreak: v7,
                              a4: v9) != 0 )
        __trap();
    }
    memcpy(Dst: v6->data, Src: v25.data, Size: len);
    v6->data[len] = 0;
    v6->len = len;
    LODWORD(v17) = (unsigned __int8)idLexer::CheckTokenString(this: src, string: "[", a3: v16, a4: v15);
    if ( (_DWORD)v17 != 0 )
    {
      idLexer::ReadToken(this: src, token: &v25, a3: v19, a4: v18, a5: v17);
      idLexer::ExpectTokenString(this: src, string: "]", a3: v21, a4: v20);
      v22 = operator+(result: &v26, a: "[", b: &v25);
      v23 = operator+(result: v27, a: v22, b: "]");
      idStr::Append(this: v6, text: v23);
      idStr::FreeData(this: v27);
      idStr::FreeData(this: &v26);
    }
    if ( v3 != nullptr )
    {
      v3[1].len = (int)v6;
      v3 = v6;
    }
    else
    {
      v3 = v6;
      v2 = v6;
    }
  }
  while ( (unsigned __int8)idLexer::CheckTokenString(this: src, string: ".", a3: v19, a4: v18) != 0 );
  idStr::FreeData(this: &v25);
  return (idTypeInfoPath *)v2;
}


// ========================================================================
// __unwind$114877
// EA  : 0x82FA2A54
// RVA : 0x00FA2A54
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_114877()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 80));
}


// ========================================================================
// __unwind$114879
// EA  : 0x82FA2A7C
// RVA : 0x00FA2A7C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_114879()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 160));
}


// ========================================================================
// __unwind$114880
// EA  : 0x82FA2AA4
// RVA : 0x00FA2AA4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_114880()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 192));
}


// ========================================================================
// ?FindPath@idTypeInfoTree@@QBAPAVidTypeInfoNode@@PAV2@PBD@Z
// EA  : 0x82FA2AD8
// RVA : 0x00FA2AD8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

idTypeInfoNode *__fastcall idTypeInfoTree::FindPath(idTypeInfoTree *this, idTypeInfoNode *startNode, const char *path)
{
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  idTypeInfoPath *v8; // r30
  idTypeInfoNode *v9; // r29
  idLexer v11; // [sp+50h] [-B0h] BYREF

  idLexer::idLexer(this: &v11, flags_: 0);
  HIDWORD(v7) = 0;
  if ( *path != 0 )
  {
    do
      ++HIDWORD(v7);
    while ( path[HIDWORD(v7)] != 0 );
  }
  LODWORD(v7) = &byte_8200D768;
  idLexer::LoadMemory(this: &v11, ptr: path, name: v7, a4: v6, a5: v5);
  v8 = ParsePath(src: &v11);
  v9 = idTypeInfoTree::FindPath(baseNode: startNode, path: v8);
  if ( v8 != nullptr )
  {
    idTypeInfoPath::~idTypeInfoPath(this: v8);
    idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
  }
  idLexer::~idLexer(this: &v11);
  return v9;
}


// ========================================================================
// __unwind$115050
// EA  : 0x82FA2B84
// RVA : 0x00FA2B84
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_115050()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 256 + 80));
}


// ========================================================================
// ?CreatePath@idTypeInfoTree@@QAAPAVidTypeInfoNode@@PBDPBVidTypeInfoTools@@@Z
// EA  : 0x82FA2BB8
// RVA : 0x00FA2BB8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

idTypeInfoNode *__fastcall idTypeInfoTree::CreatePath(idTypeInfoTree *this, const char *path, idTypeInfoTools *ti)
{
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  idTypeInfoPath *v9; // r30
  idTypeInfoNode *v10; // r29
  idLexer v12; // [sp+50h] [-B0h] BYREF

  idLexer::idLexer(this: &v12, flags_: 0);
  HIDWORD(v8) = 0;
  if ( *path != 0 )
  {
    do
      ++HIDWORD(v8);
    while ( path[HIDWORD(v8)] != 0 );
  }
  LODWORD(v8) = &byte_8200D768;
  idLexer::LoadMemory(this: &v12, ptr: path, name: v8, a4: v7, a5: v6);
  v9 = ParsePath(src: &v12);
  v10 = idTypeInfoTree::CreatePath(this, path: v9, ti);
  if ( v9 != nullptr )
  {
    idTypeInfoPath::~idTypeInfoPath(this: v9);
    idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
  }
  idLexer::~idLexer(this: &v12);
  return v10;
}


// ========================================================================
// __unwind$115091_0
// EA  : 0x82FA2C6C
// RVA : 0x00FA2C6C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_115091_0()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 256 + 80));
}


// ========================================================================
// ?FreeTree_r@idTypeInfoTree@@AAAXPAVidTypeInfoNode@@@Z
// EA  : 0x82FA2C98
// RVA : 0x00FA2C98
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::FreeTree_r(idTypeInfoTree *this, idTypeInfoNode *node)
{
  idTypeInfoNode *v3; // r31
  idBlockAlloc<idTypeInfoNode,32,114> *p_nodeBlockAlloc; // r30
  idTypeInfoNode *next; // r29

  v3 = node;
  if ( node != nullptr )
  {
    p_nodeBlockAlloc = &this->nodeBlockAlloc;
    do
    {
      next = v3->next;
      idTypeInfoTree::FreeTree_r(this, node: v3->children);
      idScenePoint_Combat::scenePointExitAnim_t::~scenePointExitAnim_t(this: (idScenePoint_Combat::scenePointExitAnim_t *)v3);
      v3->type.len = (int)p_nodeBlockAlloc->free;
      p_nodeBlockAlloc->free = (idBlockAlloc<idTypeInfoNode,32,114>::element_t *)v3;
      v3 = next;
      --p_nodeBlockAlloc->active;
    }
    while ( next != nullptr );
  }
}


// ========================================================================
// ?Clear@idTypeInfoTree@@QAAXXZ
// EA  : 0x82FA2D00
// RVA : 0x00FA2D00
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::Clear(idTypeInfoTree *this)
{
  idTypeInfoTree::FreeTree_r(this, node: this->root);
  this->root = nullptr;
}


// ========================================================================
// ?GetPath@idTypeInfoTree@@QAAXPBVidTypeInfoNode@@0AAVidStr@@@Z
// EA  : 0x82FA2D40
// RVA : 0x00FA2D40
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::GetPath(
        idTypeInfoTree *this,
        const idTypeInfoNode *baseNode,
        const idTypeInfoNode *node,
        idStr *path)
{
  const idTypeInfoNode *v5; // r30
  encounterGroupRole_t *list; // r26
  int v8; // r30
  const idStr **v9; // r29
  const idTypeInfoNode *v10; // [sp+50h] [-60h] BYREF
  idList<enum encounterGroupRole_t,5> v11[5]; // [sp+60h] [-50h] BYREF

  v5 = node;
  v10 = node;
  idStr::Clear(this: path);
  memset(v11, 0, 14);
  v11[0].memTag = 5;
  v11[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v11);
  if ( v5 == baseNode )
  {
LABEL_4:
    list = v11[0].list;
    v8 = v11[0].num - 1;
    if ( v11[0].num - 1 >= 0 )
    {
      v9 = (const idStr **)&v11[0].list[v8];
      do
      {
        idStr::Append(this: path, text: *v9 + 2);
        if ( v8 > 0 )
          idStr::Append(this: path, text: ".");
        --v8;
        --v9;
      }
      while ( v8 >= 0 );
    }
    if ( (v11[0].listStatic == 0 || v11[0].listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
  else
  {
    while ( 1 )
    {
      idList<idAnimWebBlendTree *,5>::Append(this: v11, obj: (encounterGroupRole_t *)&v10);
      v5 = v5->parent;
      v10 = v5;
      if ( v5 == nullptr )
        break;
      if ( v5 == baseNode )
        goto LABEL_4;
    }
    idStr::Clear(this: path);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v11);
  }
}


// ========================================================================
// $M115312
// EA  : 0x82FA2E58
// RVA : 0x00FA2E58
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _M115312()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}


// ========================================================================
// ?IsSkipped@idTypeInfoTree@@QBA_NPBD@Z
// EA  : 0x82FA2E80
// RVA : 0x00FA2E80
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

BOOL __fastcall idTypeInfoTree::IsSkipped(idTypeInfoTree *this, const char *path)
{
  idTypeInfoNode *v2; // r3

  v2 = idTypeInfoTree::FindPath(this, startNode: this->root, path);
  return v2 != nullptr && v2->skip;
}


// ========================================================================
// ?GetInt@idTypeInfoTree@@QBA_NPBDAAH@Z
// EA  : 0x82FA2EC8
// RVA : 0x00FA2EC8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

int __fastcall idTypeInfoTree::GetInt(idTypeInfoTree *this, const char *path, int *value)
{
  idTypeInfoNode *v4; // r3

  *value = 0;
  v4 = idTypeInfoTree::FindPath(this, startNode: this->root, path);
  if ( v4 == nullptr )
    return 0;
  *value = atol(nptr: v4->value.data);
  return 1;
}


// ========================================================================
// ?GetStr@idTypeInfoTree@@QBA_NPBDAAVidStr@@@Z
// EA  : 0x82FA2F38
// RVA : 0x00FA2F38
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

int __fastcall idTypeInfoTree::GetStr(idTypeInfoTree *this, const char *path, idStr *value)
{
  idTypeInfoNode *v6; // r11

  idStr::operator=(this: value, text: &byte_8200D768);
  v6 = idTypeInfoTree::FindPath(this, startNode: this->root, path);
  if ( v6 == nullptr )
    return 0;
  idStr::operator=(this: value, text: v6->value.data);
  return 1;
}


// ========================================================================
// ?SetStr@idTypeInfoTree@@QAA_NPBD0@Z
// EA  : 0x82FA2FA0
// RVA : 0x00FA2FA0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

int __fastcall idTypeInfoTree::SetStr(idTypeInfoTree *this, const char *path, char *value)
{
  idTypeInfoNode *v6; // r3

  v6 = idTypeInfoTree::FindPath(this, startNode: this->root, path);
  if ( v6 == nullptr )
  {
    v6 = idTypeInfoTree::CreatePath(this, path, ti: typeInfoTools);
    if ( v6 == nullptr )
      return 0;
  }
  idStr::operator=(this: &v6->value, text: value);
  return 1;
}


// ========================================================================
// ?GetBool@idTypeInfoTree@@QBA_NPBDAA_N@Z
// EA  : 0x82FA3018
// RVA : 0x00FA3018
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

int __fastcall idTypeInfoTree::GetBool(idTypeInfoTree *this, const char *path, bool *value)
{
  idTypeInfoNode *v4; // r30
  idStr v6[2]; // [sp+50h] [-40h] BYREF

  *value = false;
  v4 = idTypeInfoTree::FindPath(this, startNode: this->root, path);
  if ( v4 == nullptr )
    return 0;
  idStr::idStr(this: v6, text: v4->value.data);
  if ( idStr::Icmp(s1: v6[0].data, s2: "true") == 0 || atol(nptr: v4->value.data) == 1 )
    *value = true;
  idStr::FreeData(this: v6);
  return 1;
}


// ========================================================================
// __unwind$115418
// EA  : 0x82FA30A4
// RVA : 0x00FA30A4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_115418()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetVec3@idTypeInfoTree@@QBA_NPBDAAVidVec3@@@Z
// EA  : 0x82FA30D0
// RVA : 0x00FA30D0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

int __fastcall idTypeInfoTree::GetVec3(
        idTypeInfoTree *this,
        const char *path,
        idVec3 *value,
        int a4,
        __int64 a5,
        __int64 a6)
{
  int v8; // r26
  int v9; // r31
  idVec3 *v10; // r29
  __int64 v11; // r6
  va *v12; // r3
  idTypeInfoNode *v13; // r3
  long double v14; // fp2
  int v16; // [sp+8h] [-1088h]
  int v17; // [sp+Ch] [-1084h]
  int v18; // [sp+10h] [-1080h]
  int v19; // [sp+14h] [-107Ch]
  int v20; // [sp+18h] [-1078h]
  int v21; // [sp+1Ch] [-1074h]
  va v22; // [sp+50h] [-1040h] BYREF

  v8 = 0;
  v9 = 0;
  value->z = 0.0;
  v10 = value;
  value->y = 0.0;
  value->x = 0.0;
  do
  {
    LODWORD(v11) = v9 + 120;
    HIDWORD(v11) = path;
    v12 = va::va(
            this: &v22,
            fmt: "%s.%c",
            a3: v11,
            a4: a5,
            a5: a6,
            a6: v16,
            a7: v17,
            a8: v18,
            a9: v19,
            a10: v20,
            a11: v21);
    v13 = idTypeInfoTree::FindPath(this, startNode: this->root, path: v12->buffer);
    if ( v13 != nullptr && v13->value.len != 0 )
    {
      v14 = atof(nptr: v13->value.data);
      v10->x = *(double *)&v14;
      v8 = 1;
    }
    ++v9;
    v10 = (idVec3 *)((char *)v10 + 4);
  }
  while ( v9 < 3 );
  return v8;
}


// ========================================================================
// ?SetVec3@idTypeInfoTree@@QAA_NPBDABVidVec3@@@Z
// EA  : 0x82FA3178
// RVA : 0x00FA3178
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idTypeInfoTree::SetVec3(
        idTypeInfoTree *this,
        const char *path,
        const idVec3 *value,
        int a4,
        __int64 a5,
        __int64 a6)
{
  int v9; // r28
  int v10; // r29
  int i; // r20
  va *v12; // r3
  idTypeInfoNode *v13; // r31
  __int64 v14; // r6 OVERLAPPED
  va *v15; // r3
  const char *v16; // r4
  va *v17; // r3
  idStr *p_value; // r30
  va *v19; // r29
  size_t j; // r31
  int v22; // [sp+8h] [-30B8h]
  int v23; // [sp+Ch] [-30B4h]
  int v24; // [sp+10h] [-30B0h]
  int v25; // [sp+14h] [-30ACh]
  int v26; // [sp+18h] [-30A8h]
  int v27; // [sp+1Ch] [-30A4h]
  va v28; // [sp+50h] [-3070h] BYREF
  va v29; // [sp+1050h] [-2070h] BYREF
  va v30; // [sp+2050h] [-1070h] BYREF

  LODWORD(a6) = &g_ThumbnailCaptureVS[702];
  v9 = 120;
  v10 = 0;
  for ( i = 3; i != 0; --i )
  {
    v12 = va::va(
            this: &v29,
            fmt: "%s.%c",
            a3: __SPAIR64__((unsigned int)path, v9),
            a4: a5,
            a5: a6,
            a6: v22,
            a7: v23,
            a8: v24,
            a9: v25,
            a10: v26,
            a11: v27);
    v13 = idTypeInfoTree::FindPath(this, startNode: this->root, path: v12->buffer);
    if ( v13 != nullptr
      || (v15 = va::va(
                  this: &v28,
                  fmt: "%s.%c",
                  a3: __SPAIR64__((unsigned int)path, v9),
                  a4: a5,
                  a5: a6,
                  a6: v22,
                  a7: v23,
                  a8: v24,
                  a9: v25,
                  a10: v26,
                  a11: v27),
          (v13 = idTypeInfoTree::CreatePath(this, path: v15->buffer, ti: typeInfoTools)) != nullptr) )
    {
      *(double *)((char *)&v14 + 4) = value->x;
      v17 = va::va(
              this: &v30,
              fmt: v16,
              a3: v14,
              a4: a5,
              a5: a6,
              a6: v22,
              a7: v23,
              a8: v24,
              a9: v25,
              a10: v26,
              a11: v27);
      p_value = &v13->value;
      v19 = v17;
      for ( j = 0; v17->buffer[j] != 0; ++j )
        ;
      idStr::EnsureAlloced(this: p_value, amount: j + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: p_value->data, Src: v19, Size: j);
      v10 = 1;
      p_value->data[j] = 0;
      p_value->len = j;
    }
    ++v9;
    value = (const idVec3 *)((char *)value + 4);
  }
  return v10;
}


// ========================================================================
// ?GetMat3@idTypeInfoTree@@QBA_NPBDAAVidMat3@@@Z
// EA  : 0x82FA32B0
// RVA : 0x00FA32B0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

int __fastcall idTypeInfoTree::GetMat3(
        idTypeInfoTree *this,
        const char *path,
        idMat3 *value,
        int a4,
        __int64 a5,
        __int64 a6)
{
  int v9; // r26
  unsigned int v10; // r27
  int v11; // r28
  int i; // r31
  va *v13; // r3
  idTypeInfoNode *v14; // r3
  long double v15; // fp2
  int v17; // [sp+8h] [-1098h]
  int v18; // [sp+Ch] [-1094h]
  int v19; // [sp+10h] [-1090h]
  int v20; // [sp+14h] [-108Ch]
  int v21; // [sp+18h] [-1088h]
  int v22; // [sp+1Ch] [-1084h]
  va v23; // [sp+50h] [-1050h] BYREF

  LODWORD(a6) = 0x82000000;
  v9 = 0;
  value->mat[2].z = 1.0;
  v10 = 0;
  value->mat[1].y = 1.0;
  v11 = 0;
  value->mat[0].x = 1.0;
  value->mat[1].z = 0.0;
  value->mat[0].z = 0.0;
  value->mat[0].y = 0.0;
  value->mat[2].y = 0.0;
  value->mat[2].x = 0.0;
  value->mat[1].x = 0.0;
  do
  {
    for ( i = 0; i < 3; ++i )
    {
      HIDWORD(a5) = i + 120;
      v13 = va::va(
              this: &v23,
              fmt: "%s.mat.mat[%d].%c",
              a3: __SPAIR64__((unsigned int)path, v10),
              a4: a5,
              a5: a6,
              a6: v17,
              a7: v18,
              a8: v19,
              a9: v20,
              a10: v21,
              a11: v22);
      v14 = idTypeInfoTree::FindPath(this, startNode: this->root, path: v13->buffer);
      if ( v14 != nullptr && v14->value.len != 0 )
      {
        v15 = atof(nptr: v14->value.data);
        v9 = 1;
        LODWORD(a6) = 4 * (v11 + i);
        *(float *)((char *)&value->mat[0].x + a6) = *(double *)&v15;
      }
    }
    v11 += 3;
    ++v10;
  }
  while ( v11 < 9 );
  return v9;
}


// ========================================================================
// ?SetMat3@idTypeInfoTree@@QAA_NPBDABVidMat3@@@Z
// EA  : 0x82FA3398
// RVA : 0x00FA3398
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idTypeInfoTree::SetMat3(idTypeInfoTree *this, const char *path, const idMat3 *value)
{
  __int64 v3; // r10
  __int64 v4; // r8
  int v7; // r29
  __int64 v8; // r25
  int i; // r23
  int j; // r28
  va *v11; // r3
  idTypeInfoNode *v12; // r31
  __int64 v13; // r6 OVERLAPPED
  va *v14; // r3
  const char *v15; // r4
  bool v16; // r7
  va *v17; // r3
  idStr *p_value; // r30
  va *v19; // r29
  size_t k; // r31
  unsigned int allocedAndFlag; // r11
  int v22; // r4
  __int64 v23; // r10
  int v24; // r11
  bool v25; // zf
  __int64 v26; // r6
  int v28; // [sp+8h] [-30C8h]
  int v29; // [sp+Ch] [-30C4h]
  int v30; // [sp+10h] [-30C0h]
  int v31; // [sp+14h] [-30BCh]
  int v32; // [sp+18h] [-30B8h]
  int v33; // [sp+1Ch] [-30B4h]
  va v34; // [sp+50h] [-3080h] BYREF
  va v35; // [sp+1050h] [-2080h] BYREF
  va v36; // [sp+2050h] [-1080h] BYREF

  LODWORD(v3) = 0x82000000;
  HIDWORD(v3) = 0x82000000;
  LODWORD(v4) = &unk_821D0000;
  HIDWORD(v8) = path;
  v7 = 0;
  LODWORD(v8) = 0;
  for ( i = 0; i < 9; i += 3 )
  {
    for ( j = 0; j < 3; ++j )
    {
      HIDWORD(v4) = j + 120;
      v11 = va::va(
              this: &v35,
              fmt: "%s.mat.mat[%d].%c",
              a3: v8,
              a4: v4,
              a5: v3,
              a6: v28,
              a7: v29,
              a8: v30,
              a9: v31,
              a10: v32,
              a11: v33);
      v12 = idTypeInfoTree::FindPath(this, startNode: this->root, path: v11->buffer);
      if ( v12 == nullptr )
      {
        HIDWORD(v4) = j + 120;
        v14 = va::va(
                this: &v34,
                fmt: "%s.mat.mat[%d].%c",
                a3: v8,
                a4: v4,
                a5: v3,
                a6: v28,
                a7: v29,
                a8: v30,
                a9: v31,
                a10: v32,
                a11: v33);
        v12 = idTypeInfoTree::CreatePath(this, path: v14->buffer, ti: typeInfoTools);
        if ( v12 == nullptr )
          continue;
      }
      LODWORD(v3) = 4 * (i + j);
      *(double *)((char *)&v13 + 4) = *(float *)((char *)&value->mat[0].x + v3);
      v17 = va::va(
              this: &v36,
              fmt: v15,
              a3: v13,
              a4: v4,
              a5: v3,
              a6: v28,
              a7: v29,
              a8: v30,
              a9: v31,
              a10: v32,
              a11: v33);
      p_value = &v12->value;
      v19 = v17;
      for ( k = 0; v17->buffer[k] != 0; ++k )
        ;
      allocedAndFlag = p_value->allocedAndFlag;
      v22 = k + 1;
      LODWORD(v23) = allocedAndFlag >> 31;
      v25 = allocedAndFlag >> 31 == 0;
      v24 = allocedAndFlag & 0x7FFFFFFF;
      if ( v25 )
      {
        if ( v22 > v24 )
          idStr::ReAllocate(this: p_value, amount: v22, keepold: false);
      }
      else if ( v22 > v24 )
      {
        HIDWORD(v26) = "amount <= GetAlloced()";
        LODWORD(v26) = 1;
        HIDWORD(v23) = (unsigned __int8)v17->buffer[0];
        if ( (unsigned __int8)AssertFailed(
                                file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                                expression: v26,
                                inlineBreak: v16,
                                a4: v23) != 0 )
          __trap();
      }
      memcpy(Dst: p_value->data, Src: v19, Size: k);
      v7 = 1;
      p_value->data[k] = 0;
      p_value->len = k;
    }
    LODWORD(v8) = v8 + 1;
  }
  return v7;
}


// ========================================================================
// ?GetStrType@idTypeInfoTree@@QBA_NPBDAAVidStr@@@Z
// EA  : 0x82FA3550
// RVA : 0x00FA3550
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

int __fastcall idTypeInfoTree::GetStrType(idTypeInfoTree *this, const char *path, idStr *value)
{
  idTypeInfoNode *v6; // r3
  idTypeInfoNode *v7; // r29
  char *data; // r3
  char *v9; // r3
  size_t len; // r30

  idStr::operator=(this: value, text: &byte_8200D768);
  v6 = idTypeInfoTree::FindPath(this, startNode: this->root, path);
  v7 = v6;
  if ( v6 == nullptr )
    return 0;
  data = v6->value.data;
  if ( *data == 34 )
  {
    v9 = idStr::CStyleUnQuote(str: data);
    idStr::operator=(this: value, text: v9);
    return 1;
  }
  else
  {
    len = v7->value.len;
    idStr::EnsureAlloced(this: value, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: value->data, Src: v7->value.data, Size: len);
    value->data[len] = 0;
    value->len = len;
    return 1;
  }
}


// ========================================================================
// ?SetStrType@idTypeInfoTree@@QAA_NPBD0@Z
// EA  : 0x82FA3610
// RVA : 0x00FA3610
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

int __fastcall idTypeInfoTree::SetStrType(idTypeInfoTree *this, const char *path, const char *value)
{
  idTypeInfoNode *v6; // r31
  const char *v8; // r3
  char *v9; // r3

  v6 = idTypeInfoTree::FindPath(this, startNode: this->root, path);
  if ( v6 == nullptr )
  {
    v6 = idTypeInfoTree::CreatePath(this, path, ti: typeInfoTools);
    if ( v6 == nullptr )
      return 0;
  }
  if ( value != nullptr )
  {
    if ( *value != 0 )
      v8 = value;
    else
      v8 = &byte_8200D768;
    v9 = idStr::CStyleQuote(str: v8);
    idStr::operator=(this: &v6->value, text: v9);
    return 1;
  }
  else
  {
    idStr::operator=(this: &v6->value, text: "NULL");
    return 1;
  }
}


// ========================================================================
// ?GetTypes_r@idTypeInfoTree@@QBAXPAVidTypeInfoNode@@PBD1AAV?$idList@PAVidTypeInfoNode@@$04@@@Z
// EA  : 0x82FA36C8
// RVA : 0x00FA36C8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::GetTypes_r(
        idTypeInfoTree *this,
        idTypeInfoNode *node,
        const char *type,
        const char *ops,
        idList<enum encounterGroupRole_t,5> *nodes)
{
  idTypeInfoNode *i; // r31
  int v10; // r3
  idTypeInfoNode *children; // [sp+50h] [-40h] BYREF

  if ( node != nullptr )
  {
    children = node->children;
    for ( i = children; i != nullptr; children = i )
    {
      v10 = idStr::Length(s: type);
      if ( idStr::Icmpn(s1: i->type.data, s2: type, n: v10) == 0 && idStr::Icmp(s1: i->ops.data, s2: ops) == 0 )
        idList<idAnimWebBlendTree *,5>::Append(this: nodes, obj: (encounterGroupRole_t *)&children);
      idTypeInfoTree::GetTypes_r(this, node: i, type, ops, (idList<idTypeInfoNode *,5> *)nodes);
      i = i->next;
    }
  }
}


// ========================================================================
// ?Parse@idTypeInfoTree@@QAAXAAVidTypeInfoFile@@@Z
// EA  : 0x82FA3770
// RVA : 0x00FA3770
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::Parse(idTypeInfoTree *this, idTypeInfoFile *file)
{
  __int64 v4; // r8

  idTypeInfoTree::FreeTree_r(this, node: this->root);
  this->root = nullptr;
  this->root = idTypeInfoTree::ReadType_r(this, file, overwrite: 0, a4: v4);
}


// ========================================================================
// ?RemoveOutOfBoundsMembers_r@idTypeInfoTree@@AAAXPAVidTypeInfoNode@@@Z
// EA  : 0x82FA37D0
// RVA : 0x00FA37D0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::RemoveOutOfBoundsMembers_r(idTypeInfoTree *this, idTypeInfoNode *curNode)
{
  idTypeInfoNode *children; // r31
  int v5; // r3
  idTypeInfoNode *v6; // r31
  int v7; // r25
  idTypeInfoNode *next; // r27
  int len; // r11
  char *data; // r6
  int v11; // r11
  int v12; // r9
  int i; // r10
  int v14; // r8
  idTypeInfoNode *parent; // r10
  idTypeInfoNode *v16; // r11
  idTypeInfoNode **p_next; // r10
  idTypeInfoNode *j; // r31

  if ( curNode != nullptr )
  {
    children = curNode->children;
    if ( children != nullptr )
    {
      while ( idStr::Cmpn(s1: children->name.data, s2: "num", n: 3) != 0 )
      {
        children = children->next;
        if ( children == nullptr )
          goto LABEL_19;
      }
      v5 = atol(nptr: children->value.data);
      v6 = curNode->children;
      v7 = v5;
      if ( v6 != nullptr )
      {
        do
        {
          next = v6->next;
          if ( idStr::Cmpn(s1: v6->name.data, s2: "item", n: 4) == 0 )
          {
            len = v6->name.len;
            data = v6->name.data;
            if ( data[len - 1] == 93 )
            {
              v11 = len - 2;
              v12 = 0;
              for ( i = 1; v11 >= 0; i *= 10 )
              {
                v14 = data[v11];
                if ( v14 == 91 )
                  break;
                --v11;
                v12 += (v14 - 48) * i;
              }
              if ( v12 >= v7 )
              {
                idTypeInfoTree::FreeTree_r(this, node: v6->children);
                parent = v6->parent;
                v6->children = nullptr;
                v16 = parent->children;
                if ( v16 == v6 )
                {
                  parent->children = v6->next;
                }
                else
                {
                  do
                  {
                    p_next = &v16->next;
                    v16 = v16->next;
                  }
                  while ( v16 != v6 );
                  *p_next = v6->next;
                }
                idScenePoint_Combat::scenePointExitAnim_t::~scenePointExitAnim_t(this: (idScenePoint_Combat::scenePointExitAnim_t *)v6);
                v6->type.len = (int)this->nodeBlockAlloc.free;
                this->nodeBlockAlloc.free = (idBlockAlloc<idTypeInfoNode,32,114>::element_t *)v6;
                --this->nodeBlockAlloc.active;
              }
            }
          }
          v6 = next;
        }
        while ( next != nullptr );
      }
    }
LABEL_19:
    for ( j = curNode->children; j != nullptr; j = j->next )
      idTypeInfoTree::RemoveOutOfBoundsMembers_r(this, curNode: j);
  }
}


// ========================================================================
// ?ParseOverwrite@idTypeInfoTree@@QAAXAAVidTypeInfoFile@@@Z
// EA  : 0x82FA3968
// RVA : 0x00FA3968
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::ParseOverwrite(idTypeInfoTree *this, idTypeInfoFile *file, int a3, int a4, __int64 a5)
{
  idTypeInfoNode *Type_r; // r3

  Type_r = idTypeInfoTree::ReadType_r(this, file, overwrite: this->root != nullptr, a4: a5);
  this->root = Type_r;
  idTypeInfoTree::RemoveOutOfBoundsMembers_r(this, curNode: Type_r);
}


// ========================================================================
// ?GetTypes@idTypeInfoTree@@QBAXPBD0AAV?$idList@PAVidTypeInfoNode@@$04@@@Z
// EA  : 0x82FA39B8
// RVA : 0x00FA39B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::GetTypes(
        idTypeInfoTree *this,
        const char *type,
        const char *ops,
        idList<enum encounterGroupRole_t,5> *nodes)
{
  idTypeInfoTree::GetTypes_r(this, node: this->root, type, ops, nodes);
}


// ========================================================================
// ??0idTypeInfoTree@@QAA@PBDH@Z
// EA  : 0x82FA39D8
// RVA : 0x00FA39D8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

idTypeInfoTree *__fastcall idTypeInfoTree::idTypeInfoTree(idTypeInfoTree *this, const char *text, int length)
{
  __int64 v6; // r10
  __int64 v7; // r6
  unsigned int v8; // r8
  __int64 v9; // r8
  idTypeInfoFile v11; // [sp+60h] [-D0h] BYREF

  this->nodeBlockAlloc.blocks = nullptr;
  this->nodeBlockAlloc.free = nullptr;
  this->nodeBlockAlloc.total = 0;
  this->nodeBlockAlloc.active = 0;
  this->nodeBlockAlloc.allowAllocs = true;
  this->nodeBlockAlloc.clearAllocs = false;
  this->root = nullptr;
  idTypeInfoFile::idTypeInfoFile(this: &v11, indent_: 0);
  v11.settings.resolveEntityPointers = false;
  v11.settings.resolveModelPointers = false;
  HIDWORD(v6) = off_82010000;
  LODWORD(v7) = &byte_8200D768;
  HIDWORD(v7) = length;
  if ( idTypeInfoFile::ReadMemory(this: &v11, data: text, name: v7, startLine: v8, a5: v6) )
  {
    idTypeInfoTree::FreeTree_r(this, node: this->root);
    this->root = nullptr;
    this->root = idTypeInfoTree::ReadType_r(this, file: &v11, overwrite: 0, a4: v9);
  }
  idTypeInfoFile::~idTypeInfoFile(this: &v11);
  return this;
}


// ========================================================================
// __unwind$116215
// EA  : 0x82FA3AA8
// RVA : 0x00FA3AA8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_116215()
{
  int v0; // r12

  idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(this: (idBlockAlloc<idTypeInfoNode,32,114> *)(*(_DWORD *)(v0 - 304 + 324) + 4));
}


// ========================================================================
// __unwind$116216
// EA  : 0x82FA3AD4
// RVA : 0x00FA3AD4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_116216()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 304 + 96));
}


// ========================================================================
// ?ExtendListsWithDefaultsBasedOn@idTypeInfoTree@@QAAXABV1@ABVidTypeInfoSettings@@PBVidTypeInfoTools@@@Z
// EA  : 0x82FA3B08
// RVA : 0x00FA3B08
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void __fastcall idTypeInfoTree::ExtendListsWithDefaultsBasedOn(
        idTypeInfoTree *this,
        idTypeInfoTree *referenceTree,
        const idTypeInfoSettings *settings,
        idTypeInfoTools *tit)
{
  int i; // r11
  idTypeInfoNode *v9; // r27
  idStr *v10; // r3
  int v11; // r24
  idTypeInfoNode *Path; // r3
  char v13; // r11
  int v14; // r30
  idTypeInfoNode *v15; // r3
  const classTypeInfo_t *ClassInfo; // r3
  const classVariableInfo_t *templateParms; // r29
  int IsUninitializedType; // r3
  void **v19; // r26
  int v20; // r10
  int v21; // r9
  __int64 v22; // r8
  __int64 v23; // r10
  __int64 v24; // r6
  __int64 v25; // r8
  __int64 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  va *v29; // r3
  idTypeInfoNode *v30; // r3
  int v31; // [sp+8h] [-1208h]
  int v32; // [sp+Ch] [-1204h]
  int v33; // [sp+10h] [-1200h]
  int v34; // [sp+14h] [-11FCh]
  int v35; // [sp+18h] [-11F8h]
  int v36; // [sp+1Ch] [-11F4h]
  idList<enum encounterGroupRole_t,5> v37; // [sp+50h] [-11C0h] BYREF
  idTypeInfoNode *v38; // [sp+60h] [-11B0h] BYREF
  idStr v39; // [sp+70h] [-11A0h] BYREF
  idStr v40; // [sp+90h] [-1180h] BYREF
  idTypeInfoFile v41; // [sp+B0h] [-1160h] BYREF
  idStr v42; // [sp+150h] [-10C0h] BYREF
  va v43; // [sp+170h] [-10A0h] BYREF

  if ( tit != nullptr )
  {
    memset(&v37, 0, 14);
    *(_WORD *)&v37.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v37);
    idTypeInfoTree::GetTypes_r(this, node: this->root, type: "idList <", ops: &byte_8200D768, nodes: &v37);
    for ( i = v37.num; v37.num > 0; i = v37.num )
    {
      v38 = (idTypeInfoNode *)v37.list[i - 1];
      v9 = v38;
      idList<void *,108>::RemoveFast(
        this: (idList<idMapChangeListener *,5> *)&v37,
        obj: (idMapChangeListener *const *)&v38);
      v39.allocedAndFlag = 20;
      v39.data = v39.baseBuffer;
      v39.len = 0;
      v39.baseBuffer[0] = 0;
      idTypeInfoTree::GetPath(this, baseNode: this->root, node: v9, path: &v39);
      v10 = operator+(result: &v42, a: &v39, b: ".");
      operator+(result: &v40, a: v10, b: "num");
      idStr::FreeData(this: &v42);
      v11 = 0;
      Path = idTypeInfoTree::FindPath(this: referenceTree, startNode: referenceTree->root, path: v40.data);
      if ( Path != nullptr )
      {
        v11 = atol(nptr: Path->value.data);
        v13 = 1;
      }
      else
      {
        v13 = 0;
      }
      if ( v13 == 0 )
        goto _M116489_0;
      v14 = 0;
      v15 = idTypeInfoTree::FindPath(this, startNode: this->root, path: v40.data);
      if ( v15 != nullptr )
        v14 = atol(nptr: v15->value.data);
      if ( v14 < v11
        && (ClassInfo = idTypeInfoTools::FindClassInfo(this: tit, typeName: v9->type.data)) != nullptr
        && (templateParms = ClassInfo->templateParms) != nullptr
        && templateParms->reallocate != nullptr
        && idTypeInfoTools::FindEnumInfo(this: tit, typeName: templateParms->type) == nullptr
        && (IsUninitializedType = idTypeInfoTools::IsUninitializedType(
                                    type: templateParms->type,
                                    ops: templateParms->ops),
            (v19 = (void **)templateParms->reallocate(a1: nullptr, a2: 0, a3: 1, a4: TAG_TOOLS, a5: IsUninitializedType)) != nullptr) )
      {
        do
        {
          idTypeInfoFile::idTypeInfoFile(this: &v41, indent_: 0);
          v20 = *(_DWORD *)&settings->resolveEntityPointers;
          v21 = *(_DWORD *)&settings->writeComments;
          v41.settings.writeModifier = settings->writeModifier;
          *(_DWORD *)&v41.settings.resolveEntityPointers = v20;
          *(_DWORD *)&v41.settings.writeComments = v21;
          idTypeInfoFile::WriteMemoryFile(this: &v41);
          HIDWORD(v22) = v14;
          idTypeInfoFile::WriteArrayElementType(
            this: &v41,
            type: templateParms->type,
            ops: templateParms->ops,
            name: "item",
            i: v22,
            a6: v23);
          idTypeInfoTools::WriteObject(
            this: tit,
            file: &v41,
            objectType: templateParms->type,
            objectOps: templateParms->ops,
            objectName: "item",
            objectPtr: v19);
          idTypeInfoFile::ReadMemoryFile(this: &v41);
          LODWORD(v24) = 1;
          HIDWORD(v24) = v9;
          idTypeInfoTree::ReadType_r(this, file: &v41, overwrite: v24, a4: v25);
          HIDWORD(v26) = v14;
          v29 = va::va(
                  this: &v43,
                  fmt: "item[%d]",
                  a3: v26,
                  a4: v28,
                  a5: v27,
                  a6: v31,
                  a7: v32,
                  a8: v33,
                  a9: v34,
                  a10: v35,
                  a11: v36);
          v30 = idTypeInfoTree::FindPath(this, startNode: v9, path: v29->buffer);
          idTypeInfoTree::GetTypes_r(this, node: v30, type: "idList <", ops: &byte_8200D768, nodes: &v37);
          idTypeInfoFile::~idTypeInfoFile(this: &v41);
          ++v14;
        }
        while ( v14 < v11 );
        templateParms->reallocate(a1: v19, a2: 1, a3: 0, a4: TAG_TOOLS, a5: false);
        idStr::FreeData(this: &v40);
      }
      else
      {
_M116489_0:
        idStr::FreeData(this: &v40);
      }
      idStr::FreeData(this: &v39);
    }
    if ( (v37.listStatic == 0 || v37.listStatic == 2) && v37.list != nullptr )
      idMem::Free(this: &mem, ptr: v37.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$116255
// EA  : 0x82FA3E90
// RVA : 0x00FA3E90
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_116255()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4624 + 80));
}


// ========================================================================
// __unwind$116256
// EA  : 0x82FA3EB8
// RVA : 0x00FA3EB8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_116256()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 112));
}


// ========================================================================
// __unwind$116257
// EA  : 0x82FA3EE0
// RVA : 0x00FA3EE0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_116257()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 336));
}


// ========================================================================
// __unwind$116258
// EA  : 0x82FA3F08
// RVA : 0x00FA3F08
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_116258()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 144));
}


// ========================================================================
// __unwind$116259
// EA  : 0x82FA3F30
// RVA : 0x00FA3F30
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.cpp
// ========================================================================

void _unwind_116259()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 4624 + 176));
}

