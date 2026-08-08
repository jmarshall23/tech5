
// ========================================================================
// ?CheckOut@idSourceControl@@QAAHABVidStr@@@Z
// EA  : 0x8260B658
// RVA : 0x0060B658
// PDB : w:\tech5\shared\idlib\sourcecontrol.h
// ========================================================================

int __fastcall idSourceControl::CheckOut(idSourceControl *this, const idStr *file)
{
  int v4; // r30
  idStaticList<idStr,1> v6; // [sp+50h] [-50h] BYREF

  idStaticList<idStr,1>::idStaticList<idStr,1>(this: &v6);
  idList<idStr,5>::Append(this: &v6, obj: file);
  v4 = this->CheckOut(this, a2: &v6);
  idStaticList<idStr,1>::~idStaticList<idStr,1>(this: &v6);
  return v4;
}


// ========================================================================
// __unwind$221929
// EA  : 0x8260B6B4
// RVA : 0x0060B6B4
// PDB : w:\tech5\shared\idlib\sourcecontrol.h
// ========================================================================

void _unwind_221929()
{
  int v0; // r12

  idStaticList<idStr,1>::~idStaticList<idStr,1>(this: (idStaticList<idStr,1> *)(v0 - 160 + 80));
}


// ========================================================================
// ?Import@idSourceControl@@QAAHABVidStr@@_N1W4scFileType_t@@@Z
// EA  : 0x8260B6E8
// RVA : 0x0060B6E8
// PDB : w:\tech5\shared\idlib\sourcecontrol.h
// ========================================================================

int __fastcall idSourceControl::Import(
        idSourceControl *this,
        const idStr *file,
        BOOL bKeepCheckedOut,
        BOOL submit,
        scFileType_t fileType)
{
  int v10; // r30
  idStaticList<idStr,1> v12[2]; // [sp+50h] [-70h] BYREF

  idStaticList<idStr,1>::idStaticList<idStr,1>(this: v12);
  idList<idStr,5>::Append(this: &v12[0], obj: file);
  v10 = this->Import(this, a2: v12, a3: bKeepCheckedOut, a4: submit, a5: fileType);
  idStaticList<idStr,1>::~idStaticList<idStr,1>(this: v12);
  return v10;
}


// ========================================================================
// __unwind$221948
// EA  : 0x8260B75C
// RVA : 0x0060B75C
// PDB : w:\tech5\shared\idlib\sourcecontrol.h
// ========================================================================

void _unwind_221948()
{
  int v0; // r12

  idStaticList<idStr,1>::~idStaticList<idStr,1>(this: (idStaticList<idStr,1> *)(v0 - 192 + 80));
}


// ========================================================================
// ??1idSourceControl@@UAA@XZ
// EA  : 0x8269FEA8
// RVA : 0x0069FEA8
// PDB : w:\tech5\shared\idlib\sourcecontrol.h
// ========================================================================

void __fastcall idSourceControl::~idSourceControl(idSourceControl *this)
{
  this->__vftable = (idSourceControl_vtbl *)&idSourceControl::`vftable';
}


// ========================================================================
// ?GetLatest@idSourceControl@@QAAHABVidStr@@_N@Z
// EA  : 0x82F0F400
// RVA : 0x00F0F400
// PDB : w:\tech5\shared\idlib\sourcecontrol.h
// ========================================================================

int __fastcall idSourceControl::GetLatest(idSourceControl *this, const idStr *file, BOOL force)
{
  int v6; // r30
  idStaticList<idStr,1> v8[2]; // [sp+50h] [-60h] BYREF

  idStaticList<idStr,1>::idStaticList<idStr,1>(this: v8);
  idList<idStr,5>::Append(this: &v8[0], obj: file);
  v6 = this->GetLatest(this, a2: v8, a3: force);
  idStaticList<idStr,1>::~idStaticList<idStr,1>(this: v8);
  return v6;
}


// ========================================================================
// __unwind$126005
// EA  : 0x82F0F464
// RVA : 0x00F0F464
// PDB : w:\tech5\shared\idlib\sourcecontrol.h
// ========================================================================

void _unwind_126005()
{
  int v0; // r12

  idStaticList<idStr,1>::~idStaticList<idStr,1>(this: (idStaticList<idStr,1> *)(v0 - 176 + 80));
}


// ========================================================================
// ?Delete@idSourceControl@@QAAHABVidStr@@@Z
// EA  : 0x82F0F498
// RVA : 0x00F0F498
// PDB : w:\tech5\shared\idlib\sourcecontrol.h
// ========================================================================

int __fastcall idSourceControl::Delete(idSourceControl *this, const idStr *file)
{
  int v4; // r30
  idStaticList<idStr,1> v6; // [sp+50h] [-50h] BYREF

  idStaticList<idStr,1>::idStaticList<idStr,1>(this: &v6);
  idList<idStr,5>::Append(this: &v6, obj: file);
  v4 = this->Delete(this, a2: &v6);
  idStaticList<idStr,1>::~idStaticList<idStr,1>(this: &v6);
  return v4;
}


// ========================================================================
// __unwind$126024
// EA  : 0x82F0F4F4
// RVA : 0x00F0F4F4
// PDB : w:\tech5\shared\idlib\sourcecontrol.h
// ========================================================================

void _unwind_126024()
{
  int v0; // r12

  idStaticList<idStr,1>::~idStaticList<idStr,1>(this: (idStaticList<idStr,1> *)(v0 - 160 + 80));
}

