
// ========================================================================
// ?SoundRoutingJob@@YAXAAUsoundRoutingParms_t@@@Z
// EA  : 0x82989A50
// RVA : 0x00989A50
// PDB : w:\tech5\engine\sound\occlusion\soundrouting.cpp
// ========================================================================

void __fastcall SoundRoutingJob(soundRoutingParms_t *parms)
{
  unsigned __int8 *temp; // r28
  unsigned __int8 *v3; // r29
  unsigned __int8 *v4; // r30
  int *v5; // r25
  int v6; // r26
  __int16 v8; // r10
  __int16 v9; // r9
  __int16 v10; // r8
  int v11; // r11
  int v12; // r27
  int v18; // r8
  sbspArea_t *v19; // r10
  int numFaces; // r11
  int firstFace; // r9
  int *v24; // r3
  sbspFace_t *faces; // r5
  int v26; // r10
  int v27; // ctr
  int *v28; // r10
  int v31; // r10
  int v32; // r5
  unsigned int v35; // ctr
  int v42; // r4
  int v43; // ctr
  int v44; // r6
  int v45; // r8
  unsigned int v46; // r7
  _WORD *v47; // r10
  int v48; // r11
  int v49; // r9
  unsigned __int8 *v50; // r9
  int v51; // r10
  float v52; // [sp+50h] [-4B0h] BYREF
  int x; // [sp+54h] [-4ACh]
  float v54; // [sp+58h] [-4A8h]
  float v55; // [sp+5Ch] [-4A4h]
  _DWORD v56[128]; // [sp+60h] [-4A0h] BYREF
  int v57; // [sp+260h] [-2A0h]
  _BYTE v58[656]; // [sp+270h] [-290h] BYREF

  XMemSet(dest: parms->route, c: 0, count: 4 * parms->numAreas);
  if ( parms->listenerAreaNum != 0 )
  {
    temp = parms->temp;
    v3 = temp + 40960;
    v4 = temp + 24576;
    v5 = (int *)(temp + 45056);
    v6 = 0;
    XMemSet(dest: temp + 24576, c: 255, count: 0x4000u);
    XMemSet(dest: temp + 40960, c: 0, count: 0x1000u);
    *(_DWORD *)&temp[4 * parms->listenerAreaNum + 24576] = 0;
    x = (int)parms->listenerOrigin.x;
    if ( x >= -32768 )
    {
      v8 = 0x7FFF;
      if ( x <= 0x7FFF )
        v8 = x;
    }
    else
    {
      v8 = 0x8000;
    }
    *(_WORD *)&temp[6 * parms->listenerAreaNum] = v8;
    x = (int)parms->listenerOrigin.y;
    if ( x >= -32768 )
    {
      v9 = 0x7FFF;
      if ( x <= 0x7FFF )
        v9 = x;
    }
    else
    {
      v9 = 0x8000;
    }
    *(_WORD *)&temp[6 * parms->listenerAreaNum + 2] = v9;
    x = (int)parms->listenerOrigin.z;
    if ( x >= -32768 )
    {
      v10 = 0x7FFF;
      if ( x <= 0x7FFF )
        v10 = x;
    }
    else
    {
      v10 = 0x8000;
    }
    v11 = 0;
    v12 = 1;
    _R18 = 16;
    _R24 = &_vmx_42c8000042c8000042c8000042c80000;
    *(_WORD *)&temp[6 * parms->listenerAreaNum + 4] = v10;
    _R21 = &_vmx_3f8000003f8000003f8000003f800000;
    *v5 = parms->listenerAreaNum;
    _R23 = &_vmx_bf000000bf000000bf000000bf000000;
    _R22 = &_vmx_c0400000c0400000c0400000c0400000;
    do
    {
      v18 = *(int *)((char *)v5 + v11);
      ++v6;
      v3[v18] = 0;
      v19 = &parms->flatBSP.areas[v18];
      numFaces = v19->numFaces;
      if ( (unsigned int)numFaces <= 0x80 )
      {
        firstFace = v19->firstFace;
        _R10 = parms->flatBSP.faceIndex;
        _R9 = __ROL4__(firstFace, 2);
        v24 = (int *)((char *)_R10 + _R9);
        __asm { dcbt      r9, r10 }
        faces = parms->flatBSP.faces;
        v26 = numFaces;
        v57 = numFaces;
        if ( numFaces > 0 )
        {
          v27 = numFaces;
          v28 = v24;
          _R6 = v56;
          do
          {
            _R9 = abs32(*v28);
            __asm { dcbt      r9, r6 }
            *(int *)((char *)v28++ + (char *)v56 - (char *)v24) = (int)faces[_R9].center;
            --v27;
          }
          while ( v27 != 0 );
          v26 = v57;
        }
        if ( (v26 & 3) != 0 )
        {
          v31 = v26;
          do
          {
            v56[v31] = v56[0];
            v32 = ++v57 & 3;
            v31 = v57;
          }
          while ( v32 != 0 );
        }
        __asm { lvx128    v62, r0, r21 }
        __asm
        {
          lvx128    v11, r0, r22
          lvx128    v61, r0, r23
        }
        __asm { lvx128    v60, r0, r24 }
        _R10 = &temp[6 * v18];
        *(float *)&x = idMath::FLT_SMALLEST_NON_DENORMAL;
        v52 = idMath::FLT_SMALLEST_NON_DENORMAL;
        v54 = idMath::FLT_SMALLEST_NON_DENORMAL;
        v55 = idMath::FLT_SMALLEST_NON_DENORMAL;
        __asm
        {
          lvrx128   v63, r18, r10
          lvlx128   v59, r0, r10
          vor128    v58, v91, v63
          vupkhsh128 v57, v58
          vcsxwfp128 v63, v57, 0
        }
        if ( numFaces > 0 )
        {
          _R9 = 0;
          v35 = ((unsigned int)(numFaces - 1) >> 2) + 1;
          _R10 = &v52;
          __asm { lvx128    v59, r0, r10 }
          do
          {
            __asm { vor128    v12, v94, v62 }
            _R7 = v58;
            _R6 = v56[_R9];
            _R5 = v56[_R9 + 1];
            _R4 = v56[_R9 + 2];
            _R10 = v56[_R9 + 3];
            __asm
            {
              lvlx128   v56, r0, r6
              lvlx128   v55, r0, r5
              lvlx128   v54, r0, r4
              vupkhsh128 v53, v56
              lvlx128   v52, r0, r10
              vupkhsh128 v51, v55
              vupkhsh128 v50, v54
              vupkhsh128 v49, v52
              vcsxwfp128 v48, v53, 0
              vcsxwfp128 v47, v51, 0
              vcsxwfp128 v46, v50, 0
              vcsxwfp128 v45, v49, 0
              vsubfp128 v44, v95, v48
              vsubfp128 v43, v95, v47
              vsubfp128 v42, v95, v46
              vsubfp128 v41, v95, v45
              vmulfp128 v40, v76, v44
              vmulfp128 v39, v75, v43
              vmulfp128 v38, v74, v42
              vmulfp128 v37, v73, v41
              vmrghw128 v36, v72, v38
              vmrghw128 v35, v71, v37
              vmrglw128 v34, v72, v38
              vmrglw128 v33, v71, v37
              vmrglw128 v32, v68, v35
              vmrghw128 v58, v68, v35
              vmrghw128 v57, v66, v33
              vaddfp128 v56, v64, v57
              vaddfp128 v13, v90, v56
              vcmpgtfp128 v0, v13, v59
              vsel      v0, v12, v13, v0
              vrsqrtefp128 v55, v0
              vmulfp128 v13, v87, v55
              vmulfp128 v54, v87, v61
              vmaddfp   v13, v0, v11, v13
              vmulfp128 v53, v86, v13
              vmulfp128 v52, v85, v0
              vmulfp128 v51, v84, v60
              vcfpuxws128 v50, v51, 0
              stvx128   v50, r9, r7
            }
            _R9 += 4;
            --v35;
          }
          while ( v35 != 0 );
        }
        v42 = *(_DWORD *)&v4[4 * v18];
        if ( numFaces > 0 )
        {
          v43 = numFaces;
          v44 = 0;
          do
          {
            v45 = *(_DWORD *)((char *)&v56[v44] + (char *)v24 - (char *)v56);
            v46 = *(_DWORD *)&v58[v44 * 4] + v42;
            v47 = (_WORD *)v56[v44];
            v48 = abs16(v47[(v45 >= 0) + 6]);
            v49 = v48;
            if ( v46 < *(_DWORD *)&v4[4 * v48] )
            {
              *(_DWORD *)&v4[v49 * 4] = v46;
              parms->route[v49] = -v45;
              v50 = &temp[6 * v48];
              *(_WORD *)v50 = *v47;
              *((_WORD *)v50 + 1) = v47[1];
              *((_WORD *)v50 + 2) = v47[2];
              if ( v3[v48] == 0 )
              {
                v51 = (4 * v12++) & 0x3FFC;
                *(int *)((char *)v5 + v51) = v48;
                v3[v48] = 1;
              }
            }
            ++v44;
            --v43;
          }
          while ( v43 != 0 );
        }
      }
      v11 = (4 * v6) & 0x3FFC;
    }
    while ( v6 != v12 );
  }
}


// ========================================================================
// `dynamic initializer for 'register_SoundRoutingJob''
// EA  : 0x833600F0
// RVA : 0x013600F0
// PDB : w:\tech5\engine\sound\occlusion\soundrouting.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_SoundRoutingJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_SoundRoutingJob,
           function: (void (__fastcall *)(void *))SoundRoutingJob,
           name: "SoundRoutingJob");
}

