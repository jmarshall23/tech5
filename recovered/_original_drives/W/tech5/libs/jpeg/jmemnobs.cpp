
// ========================================================================
// ?jpeg_get_large@@YAPAXPAUjpeg_common_struct@@I@Z
// EA  : 0x83233D60
// RVA : 0x01233D60
// PDB : w:\tech5\libs\jpeg\jmemnobs.cpp
// ========================================================================

void *__fastcall jpeg_get_large(jpeg_common_struct *cinfo, unsigned int sizeofobject)
{
  return malloc(size: sizeofobject);
}


// ========================================================================
// zcfree
// EA  : 0x83233D68
// RVA : 0x01233D68
// PDB : w:\tech5\libs\jpeg\jmemnobs.cpp
// ========================================================================

void __fastcall zcfree(void *opaque, void *ptr)
{
  free(pBlock: ptr);
}


// ========================================================================
// ?GetTitleStorageString@idSession@@UBAPBDPBD0@Z
// EA  : 0x83233D70
// RVA : 0x01233D70
// PDB : w:\tech5\libs\jpeg\jmemnobs.cpp
// ========================================================================

int __fastcall idSession::GetTitleStorageString(
        jpeg_common_struct *cinfo,
        int min_bytes_needed,
        int max_bytes_needed,
        int already_allocated)
{
  return max_bytes_needed;
}


// ========================================================================
// ?jpeg_open_backing_store@@YAXPAUjpeg_common_struct@@PAUbacking_store_struct@@J@Z
// EA  : 0x83233D78
// RVA : 0x01233D78
// PDB : w:\tech5\libs\jpeg\jmemnobs.cpp
// ========================================================================

void __fastcall jpeg_open_backing_store(jpeg_common_struct *cinfo, backing_store_struct *info, int total_bytes_needed)
{
  cinfo->err->msg_code = 49;
  ((void (__fastcall *)(jpeg_common_struct *, backing_store_struct *, int))cinfo->err->error_exit)(
    a1: cinfo,
    a2: info,
    a3: total_bytes_needed);
}

