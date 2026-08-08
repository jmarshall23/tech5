
// ========================================================================
// png_create_struct_2
// EA  : 0x83228610
// RVA : 0x01228610
// PDB : w:\tech5\libs\png\pngmem.c
// ========================================================================

void *__fastcall png_create_struct_2(
        int type,
        void *(__fastcall *malloc_fn)(png_struct_def *, unsigned int),
        void *mem_ptr)
{
  unsigned int v3; // r30
  void *v4; // r3
  void *v5; // r31
  void *v7; // r3
  char v8; // [sp+50h] [-7B0h] BYREF
  void *v9; // [sp+794h] [-6Ch]

  if ( type == 2 )
  {
    v3 = 288;
  }
  else
  {
    if ( type != 1 )
      return nullptr;
    v3 = 1936;
  }
  if ( malloc_fn != nullptr )
  {
    v9 = mem_ptr;
    v4 = malloc_fn(a1: (png_struct_def *)&v8, a2: v3);
    v5 = v4;
    if ( v4 != nullptr )
      memset(Dst: v4, Val: 0, Size: v3);
    return v5;
  }
  v7 = malloc(size: v3);
  v5 = v7;
  if ( v7 == nullptr )
    return v5;
  memset(Dst: v7, Val: 0, Size: v3);
  return v5;
}


// ========================================================================
// png_destroy_struct_2
// EA  : 0x832286C8
// RVA : 0x012286C8
// PDB : w:\tech5\libs\png\pngmem.c
// ========================================================================

void __fastcall png_destroy_struct_2(
        void *struct_ptr,
        void (__fastcall *free_fn)(png_struct_def *, void *),
        void *mem_ptr)
{
  char v3; // [sp+50h] [-7A0h] BYREF
  void *v4; // [sp+794h] [-5Ch]

  if ( struct_ptr != nullptr )
  {
    if ( free_fn != nullptr )
    {
      v4 = mem_ptr;
      free_fn(a1: (png_struct_def *)&v3, a2: struct_ptr);
    }
    else
    {
      free(pBlock: struct_ptr);
    }
  }
}


// ========================================================================
// png_memcpy_check
// EA  : 0x83228720
// RVA : 0x01228720
// PDB : w:\tech5\libs\png\pngmem.c
// ========================================================================

void *__fastcall png_memcpy_check(png_struct_def *png_ptr, void *s1, void *s2, size_t length)
{
  return memcpy(Dst: s1, Src: s2, Size: length);
}


// ========================================================================
// png_memset_check
// EA  : 0x83228730
// RVA : 0x01228730
// PDB : w:\tech5\libs\png\pngmem.c
// ========================================================================

void *__fastcall png_memset_check(png_struct_def *png_ptr, void *s1, int value, size_t length)
{
  return memset(Dst: s1, Val: value, Size: length);
}


// ========================================================================
// png_set_mem_fn
// EA  : 0x83228740
// RVA : 0x01228740
// PDB : w:\tech5\libs\png\pngmem.c
// ========================================================================

void __fastcall png_set_mem_fn(
        png_struct_def *png_ptr,
        void *mem_ptr,
        void *(__fastcall *malloc_fn)(png_struct_def *, unsigned int),
        void (__fastcall *free_fn)(png_struct_def *, void *))
{
  if ( png_ptr != nullptr )
  {
    png_ptr->mem_ptr = mem_ptr;
    png_ptr->malloc_fn = malloc_fn;
    png_ptr->free_fn = free_fn;
  }
}


// ========================================================================
// png_destroy_struct
// EA  : 0x83228758
// RVA : 0x01228758
// PDB : w:\tech5\libs\png\pngmem.c
// ========================================================================

void __fastcall png_destroy_struct(void *struct_ptr)
{
  if ( struct_ptr != nullptr )
    free(pBlock: struct_ptr);
}


// ========================================================================
// png_malloc
// EA  : 0x83228768
// RVA : 0x01228768
// PDB : w:\tech5\libs\png\pngmem.c
// ========================================================================

void *__fastcall png_malloc(png_struct_def *png_ptr, unsigned int size)
{
  int (*malloc_fn)(void); // r11
  void *v4; // r3
  void *v5; // r30

  if ( png_ptr == nullptr || size == 0 )
    return nullptr;
  malloc_fn = (int (*)(void))png_ptr->malloc_fn;
  if ( malloc_fn != nullptr )
    v4 = (void *)malloc_fn();
  else
    v4 = malloc(size);
  v5 = v4;
  if ( v4 == nullptr && (png_ptr->flags & 0x100000) == 0 )
    png_error(png_ptr, error_message: "Out of Memory!");
  return v5;
}


// ========================================================================
// png_free
// EA  : 0x83228800
// RVA : 0x01228800
// PDB : w:\tech5\libs\png\pngmem.c
// ========================================================================

void __fastcall png_free(png_struct_def *png_ptr, void *ptr)
{
  void (*free_fn)(void); // r11

  if ( png_ptr != nullptr && ptr != nullptr )
  {
    free_fn = (void (*)(void))png_ptr->free_fn;
    if ( free_fn != nullptr )
      free_fn();
    else
      free(pBlock: ptr);
  }
}


// ========================================================================
// png_malloc_warn
// EA  : 0x83228830
// RVA : 0x01228830
// PDB : w:\tech5\libs\png\pngmem.c
// ========================================================================

_DWORD *__fastcall png_malloc_warn(_DWORD *png_ptr, unsigned int size)
{
  _DWORD *v2; // r31
  int v3; // r30

  v2 = png_ptr;
  if ( png_ptr != nullptr )
  {
    v3 = png_ptr[347];
    png_ptr[347] = v3 | 0x100000;
    png_ptr = png_malloc((png_struct_def *)png_ptr, size);
    v2[347] = v3;
  }
  return png_ptr;
}

