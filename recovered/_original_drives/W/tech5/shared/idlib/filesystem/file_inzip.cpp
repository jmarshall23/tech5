
// ========================================================================
// ?Read@idFile_InZip@@UAAIPAXI@Z
// EA  : 0x82F10428
// RVA : 0x00F10428
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

int __fastcall idFile_InZip::Read(idFile_InZip *this, void *buffer, unsigned int len)
{
  return unzReadCurrentFile(file: this->z, buf: buffer, len);
}


// ========================================================================
// ?Tell@idFile_InZip@@UBA_JXZ
// EA  : 0x82F10430
// RVA : 0x00F10430
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

int __fastcall idFile_InZip::Tell(idFile_InZip *this)
{
  return unztell(file: this->z);
}


// ========================================================================
// ?Length@idFile_InZip@@UBA_JXZ
// EA  : 0x82F10458
// RVA : 0x00F10458
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

int __fastcall idFile_InZip::Length(idFile_InZip *this)
{
  return this->fileSize;
}


// ========================================================================
// ??0idFile_InZip@@QAA@XZ
// EA  : 0x82F10470
// RVA : 0x00F10470
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

idFile_InZip *__fastcall idFile_InZip::idFile_InZip(idFile_InZip *this)
{
  idFile::idFile(this);
  this->__vftable = (idFile_InZip_vtbl *)&idFile_InZip::`vftable';
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->fullPath.allocedAndFlag = 20;
  this->fullPath.len = 0;
  this->fullPath.data = this->fullPath.baseBuffer;
  this->fullPath.baseBuffer[0] = 0;
  idStr::operator=(this: &this->name, text: "invalid");
  this->zipFilePos = 0;
  this->fileSize = 0;
  this->timeStamp = 1;
  this->z = nullptr;
  return this;
}


// ========================================================================
// __unwind$111740
// EA  : 0x82F10500
// RVA : 0x00F10500
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

void _unwind_111740()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$111741
// EA  : 0x82F10528
// RVA : 0x00F10528
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

void _unwind_111741()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$111742
// EA  : 0x82F10554
// RVA : 0x00F10554
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

void _unwind_111742()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}


// ========================================================================
// ??1idFile_InZip@@UAA@XZ
// EA  : 0x82F10588
// RVA : 0x00F10588
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

void __fastcall idFile_InZip::~idFile_InZip(idFile_InZip *this)
{
  this->__vftable = (idFile_InZip_vtbl *)&idFile_InZip::`vftable';
  unzCloseCurrentFile(file: this->z);
  unzClose(file: this->z);
  idStr::FreeData(this: &this->fullPath);
  idStr::FreeData(this: &this->name);
  this->__vftable = (idFile_InZip_vtbl *)&idFile::`vftable';
}


// ========================================================================
// __unwind$111828
// EA  : 0x82F105F8
// RVA : 0x00F105F8
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

void _unwind_111828()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$111829
// EA  : 0x82F10620
// RVA : 0x00F10620
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

void _unwind_111829()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$111830
// EA  : 0x82F1064C
// RVA : 0x00F1064C
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

void _unwind_111830()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// ?Write@idFile_InZip@@UAAIPBXI@Z
// EA  : 0x82F10678
// RVA : 0x00F10678
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

void __fastcall idFile_InZip::Write(idFile_InZip *this, const void *buffer, unsigned int len)
{
  idLib::FatalError(fmt: "idFile_InZip::Write: cannot write to the zipped file %s", this->name.data);
}


// ========================================================================
// ?ForceFlush@idFile_InZip@@UAAXXZ
// EA  : 0x82F10688
// RVA : 0x00F10688
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

void __fastcall idFile_InZip::ForceFlush(idFile_InZip *this)
{
  idLib::FatalError(fmt: "idFile_InZip::ForceFlush: cannot flush the zipped file %s", this->name.data);
}


// ========================================================================
// ?Flush@idFile_InZip@@UAAXXZ
// EA  : 0x82F10698
// RVA : 0x00F10698
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

void __fastcall idFile_InZip::Flush(idFile_InZip *this)
{
  idLib::FatalError(fmt: "idFile_InZip::Flush: cannot flush the zipped file %s", this->name.data);
}


// ========================================================================
// ?Seek@idFile_InZip@@UAAH_JW4fsOrigin_t@@@Z
// EA  : 0x82F10710
// RVA : 0x00F10710
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

int __fastcall idFile_InZip::Seek(idFile_InZip *this, int fileSize, __int64 offset, fsOrigin_t origin)
{
  int v6; // r30
  int v7; // r3
  char *buffer; // r26
  int v10; // r29
  unsigned int num; // r24
  int v12; // r30
  idTempArray<char> v13; // [sp+50h] [-50h] BYREF

  v6 = HIDWORD(offset);
  v7 = this->Tell(this);
  switch ( v6 )
  {
    case 1:
      fileSize = this->fileSize - fileSize;
      break;
    case 2:
      break;
    case 0:
      fileSize += v7;
      break;
    default:
      fileSize = 0;
      goto LABEL_9;
  }
  if ( fileSize < 0 )
  {
    fileSize = 0;
    goto LABEL_11;
  }
LABEL_9:
  if ( fileSize > this->fileSize )
    fileSize = this->fileSize;
LABEL_11:
  if ( fileSize < v7 )
  {
    unzSetCurrentFileInfoPosition(file: this->z, pos: this->zipFilePos);
    unzOpenCurrentFile(file: this->z);
  }
  else
  {
    fileSize -= v7;
  }
  if ( fileSize == 0 )
    return 0;
  idTempArray<char>::idTempArray<char>(this: &v13, num: 0x8000u);
  buffer = v13.buffer;
  v10 = 0;
  if ( fileSize - 0x8000 <= 0 )
  {
LABEL_20:
    v12 = 0;
    if ( unzReadCurrentFile(file: this->z, buf: buffer, len: fileSize - v10) + v10 != fileSize )
      v12 = -1;
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    return v12;
  }
  else
  {
    num = v13.num;
    while ( unzReadCurrentFile(file: this->z, buf: buffer, len: num) >= 0x8000 )
    {
      v10 += 0x8000;
      if ( v10 >= fileSize - 0x8000 )
        goto LABEL_20;
    }
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    return -1;
  }
}


// ========================================================================
// __unwind$111907
// EA  : 0x82F10890
// RVA : 0x00F10890
// PDB : w:\tech5\shared\idlib\filesystem\file_inzip.cpp
// ========================================================================

void _unwind_111907()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 160 + 80));
}

