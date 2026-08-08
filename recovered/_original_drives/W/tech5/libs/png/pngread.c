
// ========================================================================
// png_create_read_struct_2
// EA  : 0x83214EE0
// RVA : 0x01214EE0
// PDB : w:\tech5\libs\png\pngread.c
// ========================================================================

png_struct_def *__fastcall png_create_read_struct_2(
        const char *user_png_ver,
        void *error_ptr,
        void (__fastcall *error_fn)(png_struct_def *, const char *),
        void (__fastcall *warn_fn)(png_struct_def *, const char *),
        void *mem_ptr,
        void *(__fastcall *malloc_fn)(png_struct_def *, unsigned int),
        void (__fastcall *free_fn)(png_struct_def *, void *))
{
  png_struct_def *struct_2; // r3
  int v9; // r30
  int v10; // r11
  char *header_ver; // r3
  int v12; // r11
  const char *v13; // r3
  int v14; // r3
  const char *v15; // r4
  png_struct_def *v16; // [sp+50h] [-80h]
  char v17[112]; // [sp+60h] [-70h] BYREF

  struct_2 = (png_struct_def *)png_create_struct_2(type: 1, malloc_fn, mem_ptr);
  v16 = struct_2;
  if ( struct_2 == nullptr )
    return nullptr;
  struct_2->user_width_max = 1000000;
  struct_2->user_height_max = 1000000;
  if ( setjmp(a1: struct_2) != 0 )
  {
    png_free(png_ptr: v16, ptr: v16->zbuf);
    v16->zbuf = nullptr;
    png_destroy_struct_2(struct_ptr: v16, free_fn, mem_ptr);
    return nullptr;
  }
  png_set_mem_fn(png_ptr: v16, mem_ptr, malloc_fn, free_fn);
  png_set_error_fn(png_ptr: v16, error_ptr, error_fn, warning_fn: warn_fn);
  if ( user_png_ver != nullptr )
  {
    v9 = 0;
    do
    {
      if ( user_png_ver[v9] != png_get_header_ver(png_ptr: nullptr)[v9] )
        v16->flags |= 0x20000u;
      v10 = (unsigned __int8)png_get_header_ver(png_ptr: nullptr)[v9++];
    }
    while ( v10 != 0 );
  }
  else
  {
    v16->flags |= 0x20000u;
  }
  if ( (v16->flags & 0x20000) != 0 )
  {
    if ( user_png_ver != nullptr )
    {
      header_ver = png_get_header_ver(png_ptr: nullptr);
      v12 = *user_png_ver;
      if ( v12 == *header_ver
        && (v12 != 49
         || *((unsigned __int8 *)user_png_ver + 2) == (unsigned __int8)png_get_header_ver(png_ptr: nullptr)[2])
        && (*user_png_ver != 48 || user_png_ver[2] >= 57) )
      {
        goto LABEL_21;
      }
      snprintf_0(
        string: v17,
        count: 0x50u,
        format: "Application was compiled with png.h from libpng-%.20s",
        user_png_ver);
      png_warning(png_ptr: v16, warning_message: v17);
    }
    v13 = png_get_header_ver(png_ptr: nullptr);
    snprintf_0(string: v17, count: 0x50u, format: "Application  is  running with png.c from libpng-%.20s", v13);
    png_warning(png_ptr: v16, warning_message: v17);
    v16->flags = 0;
    png_error(png_ptr: v16, error_message: "Incompatible libpng version in application and library");
  }
LABEL_21:
  v16->zbuf_size = 0x2000;
  v16->zbuf = (unsigned __int8 *)png_malloc(png_ptr: v16, size: 0x2000u);
  v16->zstream.zalloc = (void *(__fastcall *)(void *, unsigned int, unsigned int))png_zalloc;
  v16->zstream.zfree = (void (__fastcall *)(void *, void *))png_zfree;
  v16->zstream.opaque = v16;
  v14 = inflateInit_(strm: &v16->zstream, version: "1.2.3", stream_size: 56);
  if ( (unsigned int)(v14 + 6) > 6 )
    goto LABEL_31;
  if ( v14 == -6 )
  {
    v15 = "zlib version error";
    goto LABEL_32;
  }
  if ( v14 == -5 )
    goto LABEL_31;
  if ( v14 != -4 )
  {
    if ( v14 != -3 )
    {
      if ( v14 != -2 )
      {
        if ( v14 != -1 )
          goto LABEL_33;
        goto LABEL_31;
      }
      goto LABEL_29;
    }
LABEL_31:
    v15 = "Unknown zlib error";
    goto LABEL_32;
  }
LABEL_29:
  v15 = "zlib memory error";
LABEL_32:
  png_error(png_ptr: v16, error_message: v15);
LABEL_33:
  v16->zstream.next_out = v16->zbuf;
  v16->zstream.avail_out = v16->zbuf_size;
  png_set_read_fn(png_ptr: v16, io_ptr: nullptr, read_data_fn: nullptr);
  if ( setjmp(a1: v16) != 0 )
    abort();
  return v16;
}


// ========================================================================
// png_read_info
// EA  : 0x832151B8
// RVA : 0x012151B8
// PDB : w:\tech5\libs\png\pngread.c
// ========================================================================

void __fastcall png_read_info(png_struct_def *png_ptr, png_info_struct *info_ptr)
{
  unsigned int sig_bytes; // r31
  const char *v5; // r4
  unsigned int uint_31; // r30
  char *v7; // r10
  unsigned __int8 *chunk_name; // r11
  int v9; // r7
  int v10; // r9
  unsigned int mode; // r11
  char *v12; // r10
  unsigned __int8 *v13; // r11
  int v14; // r7
  int v15; // r9
  char *v16; // r10
  unsigned __int8 *v17; // r11
  int v18; // r7
  int v19; // r9
  int v20; // r3
  unsigned __int8 *v21; // r11
  unsigned __int8 *v22; // r8
  char *v23; // r10
  int v24; // r7
  int v25; // r9
  char *v26; // r10
  unsigned __int8 *v27; // r11
  int v28; // r7
  int v29; // r9
  char *v30; // r10
  unsigned __int8 *v31; // r11
  int v32; // r7
  int v33; // r9
  unsigned int v34; // r11
  char *v35; // r10
  int v36; // r7
  int v37; // r9
  char *v38; // r10
  unsigned __int8 *v39; // r11
  int v40; // r7
  int v41; // r9
  char *v42; // r10
  unsigned __int8 *v43; // r11
  int v44; // r7
  int v45; // r9
  char *v46; // r10
  unsigned __int8 *v47; // r11
  int v48; // r7
  int v49; // r9
  char *v50; // r10
  unsigned __int8 *v51; // r11
  int v52; // r7
  int v53; // r9
  char *v54; // r10
  unsigned __int8 *v55; // r11
  int v56; // r7
  int v57; // r9
  char *v58; // r10
  unsigned __int8 *v59; // r11
  int v60; // r7
  int v61; // r9
  char *v62; // r10
  unsigned __int8 *v63; // r11
  int v64; // r7
  int v65; // r9
  char *v66; // r10
  unsigned __int8 *v67; // r11
  int v68; // r7
  int v69; // r9
  char *v70; // r10
  unsigned __int8 *v71; // r11
  int v72; // r7
  int v73; // r9
  char *v74; // r10
  unsigned __int8 *v75; // r11
  int v76; // r7
  int v77; // r9
  char *v78; // r10
  unsigned __int8 *v79; // r11
  int v80; // r7
  int v81; // r9
  char *v82; // r10
  unsigned __int8 *v83; // r11
  int v84; // r7
  int v85; // r9
  char *v86; // r10
  unsigned __int8 *v87; // r11
  int v88; // r7
  int v89; // r9
  char *v90; // r10
  unsigned __int8 *v91; // r11
  int v92; // r7
  int v93; // r9
  char *v94; // r10
  unsigned __int8 *v95; // r11
  int v96; // r7
  int v97; // r9
  char *v98; // r10
  unsigned __int8 *v99; // r11
  int v100; // r7
  int v101; // r9
  char *v102; // r10
  unsigned __int8 *v103; // r11
  int v104; // r7
  int v105; // r9
  unsigned int v106; // r11
  const char *v107; // r4
  unsigned int v108; // r11
  unsigned __int8 v109[4]; // [sp+50h] [-140h] BYREF
  char v110[8]; // [sp+54h] [-13Ch] BYREF
  char v111[8]; // [sp+5Ch] [-134h] BYREF
  char v112[8]; // [sp+64h] [-12Ch] BYREF
  char v113[8]; // [sp+6Ch] [-124h] BYREF
  char v114[8]; // [sp+74h] [-11Ch] BYREF
  char v115[8]; // [sp+7Ch] [-114h] BYREF
  char v116[8]; // [sp+84h] [-10Ch] BYREF
  char v117[8]; // [sp+8Ch] [-104h] BYREF
  char v118[8]; // [sp+94h] [-FCh] BYREF
  char v119[8]; // [sp+9Ch] [-F4h] BYREF
  char v120[8]; // [sp+A4h] [-ECh] BYREF
  char v121[8]; // [sp+ACh] [-E4h] BYREF
  char v122[8]; // [sp+B4h] [-DCh] BYREF
  char v123[8]; // [sp+BCh] [-D4h] BYREF
  char v124[8]; // [sp+C4h] [-CCh] BYREF
  char v125[8]; // [sp+CCh] [-C4h] BYREF
  char v126[8]; // [sp+D4h] [-BCh] BYREF
  char v127[8]; // [sp+DCh] [-B4h] BYREF
  char v128[8]; // [sp+E4h] [-ACh] BYREF
  char v129[164]; // [sp+ECh] [-A4h] BYREF

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    sig_bytes = png_ptr->sig_bytes;
    if ( sig_bytes < 8 )
    {
      png_read_data(png_ptr, data: &info_ptr->signature[sig_bytes], length: 8 - sig_bytes);
      png_ptr->sig_bytes = 8;
      if ( png_sig_cmp(sig: info_ptr->signature, start: sig_bytes, num_to_check: 8 - sig_bytes) != 0 )
      {
        if ( sig_bytes < 4
          && png_sig_cmp(sig: info_ptr->signature, start: sig_bytes, num_to_check: 8 - sig_bytes - 4) != 0 )
        {
          v5 = "Not a PNG file";
        }
        else
        {
          v5 = "PNG file corrupted by ASCII conversion";
        }
        png_error(png_ptr, error_message: v5);
      }
      if ( sig_bytes < 3 )
        png_ptr->mode |= 0x1000u;
    }
    strcpy(v114, "bKGD");
    strcpy(v112, "IHDR");
    strcpy(v110, "IDAT");
    strcpy(v113, "IEND");
    strcpy(v111, "PLTE");
    strcpy(v115, "cHRM");
    strcpy(v116, "gAMA");
    strcpy(v117, "hIST");
    strcpy(v124, "iCCP");
    strcpy(v118, "oFFs");
    strcpy(v119, "pCAL");
    strcpy(v121, "pHYs");
    strcpy(v122, "sBIT");
    strcpy(v120, "sCAL");
    strcpy(v125, "sPLT");
    strcpy(v123, "sRGB");
    strcpy(v126, "tEXt");
    strcpy(v127, "tIME");
    strcpy(v128, "tRNS");
    strcpy(v129, "zTXt");
    do
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              png_read_data(png_ptr, data: v109, length: 4u);
              uint_31 = png_get_uint_31(png_ptr, buf: v109);
              png_reset_crc(png_ptr);
              png_crc_read(png_ptr, buf: png_ptr->chunk_name, length: 4u);
              v7 = v110;
              chunk_name = png_ptr->chunk_name;
              do
              {
                v9 = (unsigned __int8)*v7;
                v10 = *chunk_name - v9;
                if ( *chunk_name != v9 )
                  break;
                ++chunk_name;
                ++v7;
              }
              while ( chunk_name != &png_ptr->chunk_name[4] );
              if ( v10 == 0 )
              {
                mode = png_ptr->mode;
                if ( (mode & 8) != 0 )
                  png_ptr->mode = mode | 0x2000;
              }
              v12 = v112;
              v13 = png_ptr->chunk_name;
              do
              {
                v14 = (unsigned __int8)*v12;
                v15 = *v13 - v14;
                if ( *v13 != v14 )
                  break;
                ++v13;
                ++v12;
              }
              while ( v13 != &png_ptr->chunk_name[4] );
              if ( v15 != 0 )
                break;
              png_handle_IHDR(png_ptr, info_ptr, length: uint_31);
            }
            v16 = v113;
            v17 = png_ptr->chunk_name;
            do
            {
              v18 = (unsigned __int8)*v16;
              v19 = *v17 - v18;
              if ( *v17 != v18 )
                break;
              ++v17;
              ++v16;
            }
            while ( v17 != &png_ptr->chunk_name[4] );
            if ( v19 != 0 )
              break;
            png_handle_IEND(png_ptr, info_ptr, length: uint_31);
          }
          v20 = png_handle_as_unknown(png_ptr, chunk_name: png_ptr->chunk_name);
          v21 = png_ptr->chunk_name;
          v22 = &png_ptr->chunk_name[4];
          if ( v20 != 0 )
            break;
          v35 = v111;
          do
          {
            v36 = (unsigned __int8)*v35;
            v37 = *v21 - v36;
            if ( *v21 != v36 )
              break;
            ++v21;
            ++v35;
          }
          while ( v21 != v22 );
          if ( v37 != 0 )
          {
            v38 = v110;
            v39 = png_ptr->chunk_name;
            do
            {
              v40 = (unsigned __int8)*v38;
              v41 = *v39 - v40;
              if ( *v39 != v40 )
                break;
              ++v39;
              ++v38;
            }
            while ( v39 != &png_ptr->chunk_name[4] );
            if ( v41 == 0 )
            {
              v106 = png_ptr->mode;
              if ( (v106 & 1) == 0 )
              {
                v107 = "Missing IHDR before IDAT";
                goto LABEL_144;
              }
              if ( png_ptr->color_type == 3 && (v106 & 2) == 0 )
              {
                v107 = "Missing PLTE before IDAT";
LABEL_144:
                png_error(png_ptr, error_message: v107);
              }
              v108 = png_ptr->mode;
              png_ptr->idat_size = uint_31;
              png_ptr->mode = v108 | 4;
              return;
            }
            v42 = v114;
            v43 = png_ptr->chunk_name;
            do
            {
              v44 = (unsigned __int8)*v42;
              v45 = *v43 - v44;
              if ( *v43 != v44 )
                break;
              ++v43;
              ++v42;
            }
            while ( v43 != &png_ptr->chunk_name[4] );
            if ( v45 != 0 )
            {
              v46 = v115;
              v47 = png_ptr->chunk_name;
              do
              {
                v48 = (unsigned __int8)*v46;
                v49 = *v47 - v48;
                if ( *v47 != v48 )
                  break;
                ++v47;
                ++v46;
              }
              while ( v47 != &png_ptr->chunk_name[4] );
              if ( v49 != 0 )
              {
                v50 = v116;
                v51 = png_ptr->chunk_name;
                do
                {
                  v52 = (unsigned __int8)*v50;
                  v53 = *v51 - v52;
                  if ( *v51 != v52 )
                    break;
                  ++v51;
                  ++v50;
                }
                while ( v51 != &png_ptr->chunk_name[4] );
                if ( v53 != 0 )
                {
                  v54 = v117;
                  v55 = png_ptr->chunk_name;
                  do
                  {
                    v56 = (unsigned __int8)*v54;
                    v57 = *v55 - v56;
                    if ( *v55 != v56 )
                      break;
                    ++v55;
                    ++v54;
                  }
                  while ( v55 != &png_ptr->chunk_name[4] );
                  if ( v57 != 0 )
                  {
                    v58 = v118;
                    v59 = png_ptr->chunk_name;
                    do
                    {
                      v60 = (unsigned __int8)*v58;
                      v61 = *v59 - v60;
                      if ( *v59 != v60 )
                        break;
                      ++v59;
                      ++v58;
                    }
                    while ( v59 != &png_ptr->chunk_name[4] );
                    if ( v61 != 0 )
                    {
                      v62 = v119;
                      v63 = png_ptr->chunk_name;
                      do
                      {
                        v64 = (unsigned __int8)*v62;
                        v65 = *v63 - v64;
                        if ( *v63 != v64 )
                          break;
                        ++v63;
                        ++v62;
                      }
                      while ( v63 != &png_ptr->chunk_name[4] );
                      if ( v65 != 0 )
                      {
                        v66 = v120;
                        v67 = png_ptr->chunk_name;
                        do
                        {
                          v68 = (unsigned __int8)*v66;
                          v69 = *v67 - v68;
                          if ( *v67 != v68 )
                            break;
                          ++v67;
                          ++v66;
                        }
                        while ( v67 != &png_ptr->chunk_name[4] );
                        if ( v69 != 0 )
                        {
                          v70 = v121;
                          v71 = png_ptr->chunk_name;
                          do
                          {
                            v72 = (unsigned __int8)*v70;
                            v73 = *v71 - v72;
                            if ( *v71 != v72 )
                              break;
                            ++v71;
                            ++v70;
                          }
                          while ( v71 != &png_ptr->chunk_name[4] );
                          if ( v73 != 0 )
                          {
                            v74 = v122;
                            v75 = png_ptr->chunk_name;
                            do
                            {
                              v76 = (unsigned __int8)*v74;
                              v77 = *v75 - v76;
                              if ( *v75 != v76 )
                                break;
                              ++v75;
                              ++v74;
                            }
                            while ( v75 != &png_ptr->chunk_name[4] );
                            if ( v77 != 0 )
                            {
                              v78 = v123;
                              v79 = png_ptr->chunk_name;
                              do
                              {
                                v80 = (unsigned __int8)*v78;
                                v81 = *v79 - v80;
                                if ( *v79 != v80 )
                                  break;
                                ++v79;
                                ++v78;
                              }
                              while ( v79 != &png_ptr->chunk_name[4] );
                              if ( v81 != 0 )
                              {
                                v82 = v124;
                                v83 = png_ptr->chunk_name;
                                do
                                {
                                  v84 = (unsigned __int8)*v82;
                                  v85 = *v83 - v84;
                                  if ( *v83 != v84 )
                                    break;
                                  ++v83;
                                  ++v82;
                                }
                                while ( v83 != &png_ptr->chunk_name[4] );
                                if ( v85 != 0 )
                                {
                                  v86 = v125;
                                  v87 = png_ptr->chunk_name;
                                  do
                                  {
                                    v88 = (unsigned __int8)*v86;
                                    v89 = *v87 - v88;
                                    if ( *v87 != v88 )
                                      break;
                                    ++v87;
                                    ++v86;
                                  }
                                  while ( v87 != &png_ptr->chunk_name[4] );
                                  if ( v89 != 0 )
                                  {
                                    v90 = v126;
                                    v91 = png_ptr->chunk_name;
                                    do
                                    {
                                      v92 = (unsigned __int8)*v90;
                                      v93 = *v91 - v92;
                                      if ( *v91 != v92 )
                                        break;
                                      ++v91;
                                      ++v90;
                                    }
                                    while ( v91 != &png_ptr->chunk_name[4] );
                                    if ( v93 != 0 )
                                    {
                                      v94 = v127;
                                      v95 = png_ptr->chunk_name;
                                      do
                                      {
                                        v96 = (unsigned __int8)*v94;
                                        v97 = *v95 - v96;
                                        if ( *v95 != v96 )
                                          break;
                                        ++v95;
                                        ++v94;
                                      }
                                      while ( v95 != &png_ptr->chunk_name[4] );
                                      if ( v97 != 0 )
                                      {
                                        v98 = v128;
                                        v99 = png_ptr->chunk_name;
                                        do
                                        {
                                          v100 = (unsigned __int8)*v98;
                                          v101 = *v99 - v100;
                                          if ( *v99 != v100 )
                                            break;
                                          ++v99;
                                          ++v98;
                                        }
                                        while ( v99 != &png_ptr->chunk_name[4] );
                                        if ( v101 != 0 )
                                        {
                                          v102 = v129;
                                          v103 = png_ptr->chunk_name;
                                          do
                                          {
                                            v104 = (unsigned __int8)*v102;
                                            v105 = *v103 - v104;
                                            if ( *v103 != v104 )
                                              break;
                                            ++v103;
                                            ++v102;
                                          }
                                          while ( v103 != &png_ptr->chunk_name[4] );
                                          if ( v105 != 0 )
                                            png_handle_unknown(png_ptr, info_ptr, length: uint_31);
                                          else
                                            png_handle_zTXt(png_ptr, info_ptr, length: uint_31);
                                        }
                                        else
                                        {
                                          png_handle_tRNS(png_ptr, info_ptr, length: uint_31);
                                        }
                                      }
                                      else
                                      {
                                        png_handle_tIME(png_ptr, info_ptr, length: uint_31);
                                      }
                                    }
                                    else
                                    {
                                      png_handle_tEXt(png_ptr, info_ptr, length: uint_31);
                                    }
                                  }
                                  else
                                  {
                                    png_handle_sPLT(png_ptr, info_ptr, length: uint_31);
                                  }
                                }
                                else
                                {
                                  png_handle_iCCP(png_ptr, info_ptr, length: uint_31);
                                }
                              }
                              else
                              {
                                png_handle_sRGB(png_ptr, info_ptr, length: uint_31);
                              }
                            }
                            else
                            {
                              png_handle_sBIT(png_ptr, info_ptr, length: uint_31);
                            }
                          }
                          else
                          {
                            png_handle_pHYs(png_ptr, info_ptr, length: uint_31);
                          }
                        }
                        else
                        {
                          png_handle_sCAL(png_ptr, info_ptr, length: uint_31);
                        }
                      }
                      else
                      {
                        png_handle_pCAL(png_ptr, info_ptr, length: uint_31);
                      }
                    }
                    else
                    {
                      png_handle_oFFs(png_ptr, info_ptr, length: uint_31);
                    }
                  }
                  else
                  {
                    png_handle_hIST(png_ptr, info_ptr, length: uint_31);
                  }
                }
                else
                {
                  png_handle_gAMA(png_ptr, info_ptr, length: uint_31);
                }
              }
              else
              {
                png_handle_cHRM(png_ptr, info_ptr, length: uint_31);
              }
            }
            else
            {
              png_handle_bKGD(png_ptr, info_ptr, length: uint_31);
            }
          }
          else
          {
            png_handle_PLTE(png_ptr, info_ptr, length: uint_31);
          }
        }
        v23 = v110;
        do
        {
          v24 = (unsigned __int8)*v23;
          v25 = *v21 - v24;
          if ( *v21 != v24 )
            break;
          ++v21;
          ++v23;
        }
        while ( v21 != v22 );
        if ( v25 == 0 )
          png_ptr->mode |= 4u;
        png_handle_unknown(png_ptr, info_ptr, length: uint_31);
        v26 = v111;
        v27 = png_ptr->chunk_name;
        do
        {
          v28 = (unsigned __int8)*v26;
          v29 = *v27 - v28;
          if ( *v27 != v28 )
            break;
          ++v27;
          ++v26;
        }
        while ( v27 != &png_ptr->chunk_name[4] );
        if ( v29 != 0 )
          break;
        png_ptr->mode |= 2u;
      }
      v30 = v110;
      v31 = png_ptr->chunk_name;
      do
      {
        v32 = (unsigned __int8)*v30;
        v33 = *v31 - v32;
        if ( *v31 != v32 )
          break;
        ++v31;
        ++v30;
      }
      while ( v31 != &png_ptr->chunk_name[4] );
    }
    while ( v33 != 0 );
    v34 = png_ptr->mode;
    if ( (v34 & 1) != 0 )
    {
      if ( png_ptr->color_type == 3 && (v34 & 2) == 0 )
        png_error(png_ptr, error_message: "Missing PLTE before IDAT");
    }
    else
    {
      png_error(png_ptr, error_message: "Missing IHDR before IDAT");
    }
  }
}


// ========================================================================
// png_read_row
// EA  : 0x83215C18
// RVA : 0x01215C18
// PDB : w:\tech5\libs\png\pngread.c
// ========================================================================

void __fastcall png_read_row(png_struct_def *png_ptr, unsigned __int8 *row, unsigned __int8 *dsp_row)
{
  unsigned int pass; // r11
  unsigned int row_number; // r11
  unsigned int v8; // r11
  unsigned __int8 *row_buf; // r10
  char *v10; // r10
  unsigned __int8 *chunk_name; // r11
  int v12; // r7
  int v13; // r9
  unsigned int zbuf_size; // r10
  unsigned __int8 *zbuf; // r4
  unsigned int idat_size; // r11
  int v17; // r3
  char *msg; // r4
  unsigned int v19; // r8
  unsigned int pixel_depth; // r9
  unsigned __int8 color_type; // r8
  unsigned int iwidth; // r11
  unsigned __int8 channels; // r7
  unsigned __int8 bit_depth; // r6
  int v25; // r10
  unsigned __int8 *v26; // r11
  unsigned __int8 *v27; // r4
  int v28; // r5
  void (__fastcall *read_row_fn)(png_struct_def *, unsigned int, int); // r11
  unsigned __int8 v30[4]; // [sp+50h] [-90h] BYREF
  char v31[12]; // [sp+54h] [-8Ch] BYREF
  _DWORD v32[8]; // [sp+60h] [-80h] BYREF
  _DWORD v33[24]; // [sp+80h] [-60h] BYREF

  strcpy(v31, "IDAT");
  v32[0] = 255;
  v32[2] = 255;
  v32[1] = 15;
  v32[3] = 51;
  v32[4] = 255;
  v32[5] = 85;
  v32[6] = 255;
  v33[0] = 128;
  v33[1] = 8;
  v33[2] = 136;
  v33[3] = 34;
  v33[4] = 170;
  v33[5] = 85;
  v33[6] = 255;
  if ( png_ptr == nullptr )
    return;
  if ( (png_ptr->flags & 0x40) == 0 )
    png_read_start_row(png_ptr);
  if ( png_ptr->interlaced != 0 && (png_ptr->transformations & 2) != 0 )
  {
    pass = png_ptr->pass;
    if ( pass <= 6 )
    {
      if ( pass == 1 )
      {
        if ( (png_ptr->row_number & 7) != 0 || png_ptr->width < 5 )
        {
          if ( dsp_row != nullptr )
            png_combine_row(png_ptr, row: dsp_row, mask: 15);
          goto LABEL_44;
        }
      }
      else if ( pass == 2 )
      {
        row_number = png_ptr->row_number;
        if ( (row_number & 7) != 4 )
        {
          if ( dsp_row != nullptr && (row_number & 4) != 0 )
            png_combine_row(png_ptr, row: dsp_row, mask: 255);
          goto LABEL_44;
        }
      }
      else if ( pass == 3 && png_ptr->pass != 0 )
      {
        if ( (png_ptr->row_number & 3) != 0 || png_ptr->width < 3 )
        {
          if ( dsp_row != nullptr )
            png_combine_row(png_ptr, row: dsp_row, mask: 51);
          goto LABEL_44;
        }
      }
      else if ( pass == 4 && png_ptr->pass != 0 )
      {
        v8 = png_ptr->row_number;
        if ( (v8 & 3) != 2 )
        {
          if ( dsp_row != nullptr && (v8 & 2) != 0 )
            png_combine_row(png_ptr, row: dsp_row, mask: 255);
          goto LABEL_44;
        }
      }
      else if ( pass == 5 && png_ptr->pass != 0 )
      {
        if ( (png_ptr->row_number & 1) != 0 || png_ptr->width < 2 )
        {
          if ( dsp_row != nullptr )
            png_combine_row(png_ptr, row: dsp_row, mask: 85);
          goto LABEL_44;
        }
      }
      else if ( png_ptr->pass != 0 )
      {
        if ( (png_ptr->row_number & 1) == 0 )
        {
LABEL_44:
          png_read_finish_row(png_ptr);
          return;
        }
      }
      else if ( (png_ptr->row_number & 7) != 0 )
      {
        if ( dsp_row != nullptr )
          png_combine_row(png_ptr, row: dsp_row, mask: 255);
        goto LABEL_44;
      }
    }
  }
  if ( (png_ptr->mode & 4) == 0 )
    png_error(png_ptr, error_message: "Invalid attempt to read row data");
  row_buf = png_ptr->row_buf;
  png_ptr->zstream.avail_out = png_ptr->irowbytes;
  png_ptr->zstream.next_out = row_buf;
  while ( 1 )
  {
    if ( png_ptr->zstream.avail_in == 0 )
    {
      while ( png_ptr->idat_size == 0 )
      {
        png_crc_finish(png_ptr, skip: 0);
        png_read_data(png_ptr, data: v30, length: 4u);
        png_ptr->idat_size = png_get_uint_31(png_ptr, buf: v30);
        png_reset_crc(png_ptr);
        png_crc_read(png_ptr, buf: png_ptr->chunk_name, length: 4u);
        v10 = v31;
        chunk_name = png_ptr->chunk_name;
        do
        {
          v12 = (unsigned __int8)*v10;
          v13 = *chunk_name - v12;
          if ( *chunk_name != v12 )
            break;
          ++chunk_name;
          ++v10;
        }
        while ( chunk_name != &png_ptr->chunk_name[4] );
        if ( v13 != 0 )
          png_error(png_ptr, error_message: "Not enough image data");
      }
      zbuf_size = png_ptr->zbuf_size;
      zbuf = png_ptr->zbuf;
      idat_size = png_ptr->idat_size;
      png_ptr->zstream.avail_in = zbuf_size;
      png_ptr->zstream.next_in = zbuf;
      if ( zbuf_size > idat_size )
        png_ptr->zstream.avail_in = idat_size;
      png_crc_read(png_ptr, buf: zbuf, length: png_ptr->zstream.avail_in);
      png_ptr->idat_size -= png_ptr->zstream.avail_in;
    }
    v17 = inflate(strm: &png_ptr->zstream, flush: 1);
    if ( v17 == 1 )
      break;
    if ( v17 != 0 )
    {
      msg = png_ptr->zstream.msg;
      if ( msg == nullptr )
        msg = "Decompression error";
      png_error(png_ptr, error_message: msg);
    }
    if ( png_ptr->zstream.avail_out == 0 )
      goto LABEL_72;
  }
  if ( png_ptr->zstream.avail_out != 0 || png_ptr->zstream.avail_in != 0 || png_ptr->idat_size != 0 )
    png_error(png_ptr, error_message: "Extra compressed data");
  v19 = png_ptr->flags | 0x20;
  png_ptr->mode |= 8u;
  png_ptr->flags = v19;
LABEL_72:
  pixel_depth = png_ptr->pixel_depth;
  color_type = png_ptr->color_type;
  iwidth = png_ptr->iwidth;
  channels = png_ptr->channels;
  bit_depth = png_ptr->bit_depth;
  png_ptr->row_info.pixel_depth = pixel_depth;
  png_ptr->row_info.color_type = color_type;
  png_ptr->row_info.width = iwidth;
  png_ptr->row_info.channels = channels;
  png_ptr->row_info.bit_depth = bit_depth;
  if ( pixel_depth < 8 )
    v25 = (pixel_depth * iwidth + 7) >> 3;
  else
    v25 = (pixel_depth >> 3) * iwidth;
  v26 = png_ptr->row_buf;
  png_ptr->row_info.rowbytes = v25;
  if ( *v26 != 0 )
    png_read_filter_row(
      png_ptr,
      row_info: &png_ptr->row_info,
      row: v26 + 1,
      prev_row: png_ptr->prev_row + 1,
      filter: *v26);
  png_memcpy_check(png_ptr, s1: png_ptr->prev_row, s2: png_ptr->row_buf, length: png_ptr->rowbytes + 1);
  if ( (png_ptr->mng_features_permitted & 4) != 0 && png_ptr->filter_type == 64 )
    png_do_read_intrapixel(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  if ( png_ptr->transformations != 0 || (png_ptr->flags & 0x400000) != 0 )
    png_do_read_transformations(png_ptr);
  if ( png_ptr->interlaced != 0 && (png_ptr->transformations & 2) != 0 )
  {
    if ( png_ptr->pass < 6u )
      png_do_read_interlace(png_ptr);
    if ( dsp_row != nullptr )
      png_combine_row(png_ptr, row: dsp_row, mask: *(_DWORD *)((char *)v32 + __ROL4__(png_ptr->pass, 2)));
    if ( row == nullptr )
      goto LABEL_96;
    v27 = row;
    v28 = *(_DWORD *)((char *)v33 + __ROL4__(png_ptr->pass, 2));
  }
  else
  {
    if ( row != nullptr )
      png_combine_row(png_ptr, row, mask: 255);
    if ( dsp_row == nullptr )
      goto LABEL_96;
    v28 = 255;
    v27 = dsp_row;
  }
  png_combine_row(png_ptr, row: v27, mask: v28);
LABEL_96:
  png_read_finish_row(png_ptr);
  read_row_fn = png_ptr->read_row_fn;
  if ( read_row_fn != nullptr )
    read_row_fn(a1: png_ptr, a2: png_ptr->row_number, a3: png_ptr->pass);
}


// ========================================================================
// png_read_image
// EA  : 0x83216228
// RVA : 0x01216228
// PDB : w:\tech5\libs\png\pngread.c
// ========================================================================

void __fastcall png_read_image(png_struct_def *png_ptr, unsigned __int8 **image)
{
  int v4; // r3
  unsigned int height; // r28
  int i; // r26
  unsigned int v7; // r31
  unsigned __int8 **v8; // r30

  if ( png_ptr != nullptr )
  {
    v4 = png_set_interlace_handling(png_ptr);
    height = png_ptr->height;
    png_ptr->num_rows = height;
    if ( v4 > 0 )
    {
      for ( i = v4; i != 0; --i )
      {
        if ( height != 0 )
        {
          v7 = height;
          v8 = image - 1;
          do
          {
            png_read_row(png_ptr, row: *++v8, dsp_row: nullptr);
            --v7;
          }
          while ( v7 != 0 );
        }
      }
    }
  }
}


// ========================================================================
// png_read_destroy
// EA  : 0x83216298
// RVA : 0x01216298
// PDB : w:\tech5\libs\png\pngread.c
// ========================================================================

void __fastcall png_read_destroy(png_struct_def *png_ptr, png_info_struct *info_ptr, png_info_struct *end_info_ptr)
{
  unsigned int free_me; // r11
  unsigned int v6; // r11
  unsigned __int16 **gamma_16_table; // r10
  int v8; // r30
  int v9; // r29
  int v10; // r30
  int v11; // r29
  int v12; // r30
  int v13; // r29
  void (__fastcall *error_fn)(png_struct_def *, const char *); // r30
  void (__fastcall *warning_fn)(png_struct_def *, const char *); // r29
  void *error_ptr; // r28
  void (__fastcall *free_fn)(png_struct_def *, void *); // r27
  _BYTE v18[1344]; // [sp+50h] [-570h] BYREF

  if ( info_ptr != nullptr )
    png_info_destroy(png_ptr, info_ptr);
  if ( end_info_ptr != nullptr )
    png_info_destroy(png_ptr, info_ptr: end_info_ptr);
  png_free(png_ptr, ptr: png_ptr->zbuf);
  png_free(png_ptr, ptr: png_ptr->big_row_buf);
  png_free(png_ptr, ptr: png_ptr->prev_row);
  png_free(png_ptr, ptr: png_ptr->palette_lookup);
  png_free(png_ptr, ptr: png_ptr->dither_index);
  png_free(png_ptr, ptr: png_ptr->gamma_table);
  png_free(png_ptr, ptr: png_ptr->gamma_from_1);
  png_free(png_ptr, ptr: png_ptr->gamma_to_1);
  if ( (png_ptr->free_me & 0x1000) != 0 )
    png_zfree(png_ptr, ptr: png_ptr->palette);
  free_me = png_ptr->free_me;
  png_ptr->free_me = free_me & 0xFFFFEFFF;
  if ( (free_me & 0x2000) != 0 )
    png_free(png_ptr, ptr: png_ptr->trans);
  v6 = png_ptr->free_me;
  png_ptr->free_me = v6 & 0xFFFFDFFF;
  if ( (v6 & 8) != 0 )
    png_free(png_ptr, ptr: png_ptr->hist);
  gamma_16_table = png_ptr->gamma_16_table;
  png_ptr->free_me &= ~8u;
  if ( gamma_16_table != nullptr )
  {
    v8 = 1 << (8 - png_ptr->gamma_shift);
    if ( v8 > 0 )
    {
      v9 = 0;
      do
      {
        png_free(png_ptr, ptr: png_ptr->gamma_16_table[v9]);
        --v8;
        ++v9;
      }
      while ( v8 != 0 );
    }
    png_free(png_ptr, ptr: png_ptr->gamma_16_table);
  }
  if ( png_ptr->gamma_16_from_1 != nullptr )
  {
    v10 = 1 << (8 - png_ptr->gamma_shift);
    if ( v10 > 0 )
    {
      v11 = 0;
      do
      {
        png_free(png_ptr, ptr: png_ptr->gamma_16_from_1[v11]);
        --v10;
        ++v11;
      }
      while ( v10 != 0 );
    }
    png_free(png_ptr, ptr: png_ptr->gamma_16_from_1);
  }
  if ( png_ptr->gamma_16_to_1 != nullptr )
  {
    v12 = 1 << (8 - png_ptr->gamma_shift);
    if ( v12 > 0 )
    {
      v13 = 0;
      do
      {
        png_free(png_ptr, ptr: png_ptr->gamma_16_to_1[v13]);
        --v12;
        ++v13;
      }
      while ( v12 != 0 );
    }
    png_free(png_ptr, ptr: png_ptr->gamma_16_to_1);
  }
  png_free(png_ptr, ptr: png_ptr->time_buffer);
  inflateEnd(strm: &png_ptr->zstream);
  png_free(png_ptr, ptr: png_ptr->save_buffer);
  png_free(png_ptr, ptr: png_ptr->current_text);
  memcpy(Dst: v18, Src: png_ptr, Size: sizeof(v18));
  error_fn = png_ptr->error_fn;
  warning_fn = png_ptr->warning_fn;
  error_ptr = png_ptr->error_ptr;
  free_fn = png_ptr->free_fn;
  memset(Dst: png_ptr, Val: 0, Size: sizeof(png_struct_def));
  png_ptr->error_fn = error_fn;
  png_ptr->warning_fn = warning_fn;
  png_ptr->error_ptr = error_ptr;
  png_ptr->free_fn = free_fn;
  memcpy(Dst: png_ptr, Src: v18, Size: 0x540u);
}


// ========================================================================
// png_create_read_struct
// EA  : 0x83216500
// RVA : 0x01216500
// PDB : w:\tech5\libs\png\pngread.c
// ========================================================================

png_struct_def *__fastcall png_create_read_struct(
        const char *user_png_ver,
        void *error_ptr,
        void (__fastcall *error_fn)(png_struct_def *, const char *),
        void (__fastcall *warn_fn)(png_struct_def *, const char *))
{
  return png_create_read_struct_2(
           user_png_ver,
           error_ptr,
           error_fn,
           warn_fn,
           mem_ptr: nullptr,
           malloc_fn: nullptr,
           free_fn: nullptr);
}


// ========================================================================
// png_destroy_read_struct
// EA  : 0x83216510
// RVA : 0x01216510
// PDB : w:\tech5\libs\png\pngread.c
// ========================================================================

void __fastcall png_destroy_read_struct(
        png_struct_def **png_ptr_ptr,
        png_info_struct **info_ptr_ptr,
        png_info_struct **end_info_ptr_ptr)
{
  png_info_struct *v6; // r30
  png_info_struct *v7; // r26
  png_struct_def *v8; // r31
  void (__fastcall *free_fn)(png_struct_def *, void *); // r29
  void *mem_ptr; // r28

  v6 = nullptr;
  v7 = nullptr;
  if ( png_ptr_ptr != nullptr )
  {
    v8 = *png_ptr_ptr;
    if ( *png_ptr_ptr != nullptr )
    {
      free_fn = v8->free_fn;
      mem_ptr = v8->mem_ptr;
      if ( info_ptr_ptr != nullptr )
        v6 = *info_ptr_ptr;
      if ( end_info_ptr_ptr != nullptr )
        v7 = *end_info_ptr_ptr;
      png_read_destroy(png_ptr: *png_ptr_ptr, info_ptr: v6, end_info_ptr: v7);
      if ( v6 != nullptr )
      {
        png_free_data(png_ptr: v8, info_ptr: v6, mask: 0x4000u, num: -1);
        png_destroy_struct_2(struct_ptr: v6, free_fn, mem_ptr);
        *info_ptr_ptr = nullptr;
      }
      if ( v7 != nullptr )
      {
        png_free_data(png_ptr: v8, info_ptr: v7, mask: 0x4000u, num: -1);
        png_destroy_struct_2(struct_ptr: v7, free_fn, mem_ptr);
        *end_info_ptr_ptr = nullptr;
      }
      png_destroy_struct_2(struct_ptr: v8, free_fn, mem_ptr);
      *png_ptr_ptr = nullptr;
    }
  }
}

