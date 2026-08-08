
// ========================================================================
// ValidateMaterialNames
// EA  : 0x8286C800
// RVA : 0x0086C800
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

int __fastcall ValidateMaterialNames(const char *modelName, const idList<idStr,5> *strings)
{
  int v4; // r27
  int v5; // r28
  int v6; // r30
  idStr *v7; // r31

  v4 = 1;
  v5 = 0;
  if ( strings->num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = &strings->list[v6];
      if ( !idMaterial::IsValidMaterialName(name: v7->data, allowUnderscore: true, allowAmpersand: true) )
      {
        idLib::Warning(fmt: "Model '%s' has invalid materialname '%s'", modelName, v7->data);
        v4 = 0;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < strings->num );
  }
  return v4;
}


// ========================================================================
// ?StripMaterialNumber@@YAHAAVidStr@@@Z
// EA  : 0x8286C898
// RVA : 0x0086C898
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

int __fastcall StripMaterialNumber(idStr *name)
{
  int v2; // r3
  int v3; // r30
  int result; // r3

  v2 = idStr::Find(str: name->data, c: 38, start: 0, end: name->len);
  v3 = v2;
  if ( v2 == -1 || !idStr::IsNumeric(s: &name->data[v2 + 1]) )
    return -1;
  result = atol(nptr: &name->data[v3 + 1]);
  if ( name->len > v3 && v3 >= 0 )
  {
    name->data[v3] = 0;
    name->len = v3;
  }
  return result;
}


// ========================================================================
// ?BuildAutospriteData@idStaticModel@@AAAXXZ
// EA  : 0x8286C998
// RVA : 0x0086C998
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall idStaticModel::BuildAutospriteData(
        idStaticModel *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        idStaticModel *a12)
{
  int num; // r11
  idStaticModel *v15; // r30
  int *p_num; // r29
  idList<idStaticModelSurface,84> *p_surfaces; // r27
  idStaticModelSurface *list; // r9
  int v19; // r10
  int v20; // r11
  float *v21; // r17
  float *p_z; // r22
  float *p_y; // r16
  float *v24; // r15
  float *v25; // r14
  int v26; // r28
  idStaticModelSurface *v31; // r11
  float **p_geometry; // r23
  idTriangles *geometry; // r31
  int *p_numVerts; // r27
  int numVerts; // r11
  int v38; // r29
  int v39; // r30
  double v40; // fp27
  float *p_x; // r11
  double v42; // fp30
  double v43; // fp29
  double v44; // fp28
  double v45; // fp7
  double v46; // fp6
  double v47; // fp5
  double v48; // fp0
  char v50; // r9
  idDrawVert *v51; // r11
  int v52; // r10
  idDrawVert *v53; // r11
  int v54; // r11
  int v55; // r11
  int v56; // r11
  int v57; // r27
  unsigned __int16 **p_indexes; // r24
  idDrawVert **p_verts; // r23
  int v60; // r22
  unsigned __int16 *v61; // r8
  double v62; // fp0
  idDrawVert *v63; // r7
  int v64; // r11
  double v65; // fp13
  int v66; // r6
  int v67; // r9
  int v68; // r11
  int v69; // r5
  float *v70; // r10
  float *v71; // r11
  double v72; // fp9
  double v73; // fp6
  double v74; // fp4
  int v75; // r5
  float *v76; // r11
  double v77; // fp8
  double v78; // fp6
  double v79; // fp4
  double v80; // fp12
  double v81; // fp10
  double v82; // fp7
  double v83; // fp12
  int v84; // r11
  int v85; // r5
  float *v86; // r10
  float *v87; // r11
  double v88; // fp9
  double v89; // fp6
  double v90; // fp4
  double v91; // fp12
  double v92; // fp12
  double v93; // fp11
  double v94; // fp10
  float *v95; // r11
  double v96; // fp8
  double v97; // fp6
  double v98; // fp12
  double v99; // fp10
  double v100; // fp7
  double v101; // fp12
  int v103; // r29
  double v104; // fp12
  int v105; // r8
  int v106; // r4
  int v107; // r6
  int v108; // r10
  int v110; // r8
  float *v112; // r9
  int v113; // r7
  int v114; // r8
  float *v115; // r10
  double v116; // fp9
  double v117; // fp7
  double v119; // fp6
  double v120; // fp8
  float *v121; // r9
  float *v122; // r11
  double v124; // fp4
  double v125; // fp2
  double v126; // fp7
  double v127; // fp1
  double v128; // fp10
  double v130; // fp4
  double v131; // fp11
  double v134; // fp8
  double v135; // fp12
  double v136; // fp11
  unsigned __int16 *v137; // r5
  idDrawVert *v138; // r11
  int v139; // r3
  int v141; // r10
  int v142; // r9
  int v143; // r6
  int v144; // r9
  int v145; // r31
  int v146; // r30
  double v149; // fp13
  double v150; // fp11
  double v151; // fp0
  double v152; // fp12
  int v153; // fp0
  int v154; // r11
  bool v155; // zf
  float *v156; // r9
  float *v157; // r10
  float *v158; // r8
  double v159; // fp2
  double v160; // fp13
  double v161; // fp12
  double v162; // fp11
  double v163; // fp1
  int v176; // r9
  int i; // r30
  idStaticModelSurface *v178; // r31
  int v181; // [sp+50h] [-1C0h] BYREF
  int v182; // [sp+54h] [-1BCh]
  float v183; // [sp+58h] [-1B8h] BYREF
  float v184; // [sp+5Ch] [-1B4h]
  unsigned int v185; // [sp+60h] [-1B0h]
  int v186; // [sp+64h] [-1ACh]
  idList<idStaticModelSurface,84> *v187; // [sp+68h] [-1A8h]
  int v188; // [sp+6Ch] [-1A4h]
  const float *v189; // [sp+70h] [-1A0h]
  int v190; // [sp+74h] [-19Ch]
  float *v191; // [sp+78h] [-198h]
  int v192; // [sp+7Ch] [-194h]
  float *v193; // [sp+80h] [-190h]
  float *v194; // [sp+84h] [-18Ch]
  float *v195; // [sp+88h] [-188h]
  float *v196; // [sp+8Ch] [-184h]
  const char *v197; // [sp+90h] [-180h]
  float **v198; // [sp+98h] [-178h]
  int v199; // [sp+9Ch] [-174h]
  int *v200; // [sp+A0h] [-170h]
  idVec3 *v201; // [sp+A4h] [-16Ch]
  const char *v202; // [sp+A8h] [-168h]
  const char *v203; // [sp+ACh] [-164h]
  const char *v204; // [sp+B0h] [-160h]
  autospriteType_t materialAutospriteType; // [sp+B4h] [-15Ch]
  int v206; // [sp+B8h] [-158h]
  float v207; // [sp+C0h] [-150h] BYREF
  float v208; // [sp+C4h] [-14Ch] BYREF
  float v209; // [sp+C8h] [-148h] BYREF
  float *v210; // [sp+CCh] [-144h]
  float v211; // [sp+D0h] [-140h] BYREF
  float v212; // [sp+D4h] [-13Ch] BYREF
  float v213; // [sp+D8h] [-138h] BYREF
  float v214; // [sp+DCh] [-134h]
  float v215; // [sp+E0h] [-130h]
  float v216; // [sp+E4h] [-12Ch]

  _R12 = -288;
  __asm { stvx128   v126, r1, r12 }
  _R12 = -272;
  __asm { stvx128   v127, r1, r12 }
  num = this->surfaces.num;
  v15 = this;
  a12 = this;
  p_num = &this->surfaces.num;
  if ( num == 0 )
    goto LABEL_73;
  p_surfaces = &this->surfaces;
  v187 = &this->surfaces;
  list = this->surfaces.list;
  if ( list->material == nullptr )
    goto LABEL_73;
  materialAutospriteType = list->material->materialAutospriteType;
  if ( materialAutospriteType == AUTOSPRITE_NONE )
    goto LABEL_73;
  v19 = 1;
  if ( num <= 1 )
  {
LABEL_8:
    v21 = (float *)&idMath::INFINITY;
    p_z = &this->referenceBounds.b[0].z;
    v189 = &idMath::INFINITY;
    p_y = &this->referenceBounds.b[0].y;
    v196 = &this->referenceBounds.b[0].z;
    this->modelIsAutosprite = true;
    v24 = &this->referenceBounds.b[1].z;
    v25 = &this->referenceBounds.b[1].y;
    this->referenceBounds.b[0].z = 1.0e30;
    v26 = 0;
    this->referenceBounds.b[0].y = 1.0e30;
    v194 = &this->referenceBounds.b[0].y;
    v193 = &this->referenceBounds.b[1].z;
    this->referenceBounds.b[0].x = 1.0e30;
    v210 = &this->referenceBounds.b[1].y;
    this->referenceBounds.b[1].z = -1.0e30;
    v201 = &this->referenceBounds.b[1];
    this->referenceBounds.b[1].y = -1.0e30;
    v190 = 0;
    this->referenceBounds.b[1].x = -1.0e30;
    if ( *p_num <= 0 )
    {
LABEL_71:
      for ( i = 0; i < *p_num; ++v26 )
      {
        v178 = &p_surfaces->list[v26];
        idTriangles::UpdateVertexBuffer(this: v178->geometry);
        idTriangles::UpdateIndexBuffer(this: v178->geometry);
        ++i;
      }
      goto LABEL_73;
    }
    v185 = 0;
    v195 = (float *)&idMath::FLT_SMALLEST_NON_DENORMAL;
    v204 = "Autosprite 2 %s max edgeLength exceeded";
    v202 = "Autosprite 1 %s max radius exceeded";
    v203 = "Autosprite %s has odd index count";
    v197 = "Autosprite %s has odd vertex count";
    _R18 = 2;
    _R21 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
    _R20 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
    _R19 = &_vmx_3f8000003f8000003f8000003f800000;
    while ( 1 )
    {
      v31 = &p_surfaces->list[v185 / 0x48];
      p_geometry = (float **)&v31->geometry;
      v198 = (float **)&v31->geometry;
      geometry = v31->geometry;
      if ( geometry == nullptr || v31->material == nullptr )
        goto LABEL_70;
      p_numVerts = &geometry->numVerts;
      v200 = &geometry->numVerts;
      numVerts = geometry->numVerts;
      if ( (numVerts & 3) != 0 )
      {
        idLib::Warning(fmt: v197, v15->name.str);
        p_surfaces = v187;
      }
      else
      {
        if ( geometry->numIndexes == 6 * (numVerts >> 2) )
        {
          idTriangles::CreateBounds(this: geometry);
          _FP26 = 0.0;
          if ( materialAutospriteType == AUTOSPRITE_VIEW_ORIENTED )
          {
            v38 = 0;
            if ( *p_numVerts > 0 )
            {
              v39 = 0;
              v40 = (float)((float)1.0 / (float)__fsqrts(2.0));
              do
              {
                p_x = &geometry->verts[v39].xyz.x;
                v42 = (float)((float)((float)((float)(p_x[26] + p_x[18]) + p_x[10]) + p_x[2]) * (float)0.25);
                v43 = (float)((float)((float)((float)(p_x[25] + p_x[17]) + p_x[9]) + p_x[1]) * (float)0.25);
                v44 = (float)((float)((float)((float)(p_x[24] + p_x[16]) + p_x[8]) + *p_x) * (float)0.25);
                v45 = (float)(p_x[2]
                            - (float)((float)((float)((float)(p_x[26] + p_x[18]) + p_x[10]) + p_x[2]) * (float)0.25));
                v46 = (float)(p_x[1]
                            - (float)((float)((float)((float)(p_x[25] + p_x[17]) + p_x[9]) + p_x[1]) * (float)0.25));
                v47 = (float)(*p_x - (float)((float)((float)((float)(p_x[24] + p_x[16]) + p_x[8]) + *p_x) * (float)0.25));
                v48 = (float)((float)__fsqrts((float)((float)((float)v47 * (float)v47)
                                                    + (float)((float)((float)v46 * (float)v46)
                                                            + (float)((float)v45 * (float)v45))))
                            * (float)v40);
                if ( v48 > 255.0 )
                {
                  idLib::Warning(fmt: v202, a12->name.str);
                  v48 = 255.0;
                }
                _FP13 = (float)((float)v48 - (float)_FP26);
                v199 = (int)v48;
                __asm { fsel      f26, f13, f0, f26 }
                if ( (int)v48 >= 0 )
                {
                  v50 = -1;
                  if ( (int)v48 <= 255 )
                    v50 = (int)v48;
                }
                else
                {
                  v50 = 0;
                }
                v51 = &geometry->verts[v39];
                v51->xyz.x = v44;
                v51->tangent[3] = 0;
                v51->xyz.z = v42;
                v51->tangent[0] = v50;
                v51->xyz.y = v43;
                v51->tangent[1] = -1;
                v51->tangent[2] = -1;
                v52 = 6 * (v38 >> 2);
                v53 = &geometry->verts[v39];
                v53[1].xyz.x = v44;
                v53[1].xyz.y = v43;
                v53[1].xyz.z = v42;
                v53[1].tangent[0] = v50;
                *(_WORD *)&v53[1].tangent[1] = 255;
                v53[1].tangent[3] = 0;
                v54 = (int)&geometry->verts[v39 + 3];
                *(float *)(v54 - 32) = v44;
                *(float *)(v54 - 28) = v43;
                *(float *)(v54 - 24) = v42;
                *(_BYTE *)(v54 - 8) = v50;
                *(_BYTE *)(v54 - 7) = 0;
                *(_BYTE *)(v54 - 6) = 0;
                *(_BYTE *)(v54 - 5) = 0;
                v55 = (int)&geometry->verts[v39 + 3];
                *(float *)v55 = v44;
                *(float *)(v55 + 4) = v43;
                *(float *)(v55 + 8) = v42;
                *(_BYTE *)(v55 + 24) = v50;
                *(_BYTE *)(v55 + 25) = -1;
                *(_BYTE *)(v55 + 26) = 0;
                *(_BYTE *)(v55 + 27) = 0;
                geometry->verts[v39].st.x = 0.0;
                geometry->verts[v39].st.y = 0.0;
                geometry->verts[v39 + 1].st.x = 1.0;
                geometry->verts[v39 + 1].st.y = 0.0;
                geometry->verts[v39 + 2].st.x = 1.0;
                geometry->verts[v39 + 2].st.y = 1.0;
                geometry->verts[v39 + 3].st.x = 0.0;
                geometry->verts[v39 + 3].st.y = 1.0;
                geometry->indexes[v52] = v38;
                geometry->indexes[v52 + 1] = v38 + 1;
                v39 += 4;
                geometry->indexes[v52 + 2] = v38 + 2;
                geometry->indexes[v52 + 3] = v38;
                geometry->indexes[v52 + 4] = v38 + 2;
                geometry->indexes[v52 + 5] = v38 + 3;
                v38 += 4;
              }
              while ( v38 < *p_numVerts );
LABEL_68:
              v15 = a12;
            }
          }
          else if ( materialAutospriteType == AUTOSPRITE_LONGEST_AXIS_ALIGNED )
          {
            v56 = *p_numVerts;
            v57 = 0;
            v188 = 0;
            if ( v56 > 0 )
            {
              __asm { vspltisw128 v126, 0 }
              p_indexes = &geometry->indexes;
              *(_WORD *)((char *)&v186 + 1) = 0;
              p_verts = &geometry->verts;
              LOBYTE(v186) = 0;
              v60 = 2;
              while ( 2 )
              {
                v61 = *p_indexes;
                v62 = *v21;
                v63 = *p_verts;
                v64 = (int)&(*p_indexes)[v60];
                v184 = *v21;
                v183 = v62;
                v65 = v62;
                v66 = 0;
                v181 = 0;
                v67 = 0;
                v182 = 0;
                v68 = __ROL4__(*(unsigned __int16 *)(v64 - 4), 5);
                v69 = __ROL4__(v61[v60 - 1], 5);
                v70 = (float *)((char *)&v63->xyz.x + v68);
                v72 = (float)(*(float *)((char *)&v63->xyz.y + v68) - *(float *)((char *)&v63->xyz.y + v69));
                v73 = (float)(*(float *)((char *)&v63->xyz.z + v68) - *(float *)((char *)&v63->xyz.z + v69));
                v74 = (float)(*(float *)((char *)&v63->xyz.x + v68) - *(float *)((char *)&v63->xyz.x + v69));
                v71 = (float *)((char *)&v63->xyz.x + v69);
                if ( (float)((float)((float)v74 * (float)v74)
                           + (float)((float)((float)v73 * (float)v73) + (float)((float)v72 * (float)v72))) < v62 )
                {
                  v183 = (float)((float)v74 * (float)v74)
                       + (float)((float)((float)v73 * (float)v73) + (float)((float)v72 * (float)v72));
                  v65 = v183;
                  v181 = 0;
                  v184 = v62;
                  v182 = 0;
                }
                v75 = __ROL4__(v61[v60], 5);
                v77 = (float)(*v71 - *(float *)((char *)&v63->xyz.x + v75));
                v78 = (float)(v71[1] - *(float *)((char *)&v63->xyz.y + v75));
                v79 = (float)(v71[2] - *(float *)((char *)&v63->xyz.z + v75));
                v76 = (float *)((char *)&v63->xyz.x + v75);
                v80 = (float)((float)((float)v77 * (float)v77)
                            + (float)((float)((float)v79 * (float)v79) + (float)((float)v78 * (float)v78)));
                if ( v80 < v65 )
                {
                  v66 = 1;
                  v62 = v65;
                  v183 = (float)((float)v77 * (float)v77)
                       + (float)((float)((float)v79 * (float)v79) + (float)((float)v78 * (float)v78));
                  v67 = 0;
                  v65 = v183;
                  v181 = 1;
                  goto LABEL_37;
                }
                if ( v80 < v62 )
                {
                  v67 = 1;
                  v62 = (float)((float)((float)v77 * (float)v77)
                              + (float)((float)((float)v79 * (float)v79) + (float)((float)v78 * (float)v78)));
LABEL_37:
                  v184 = v62;
                  v182 = v67;
                }
                v81 = (float)(v76[1] - v70[1]);
                v82 = (float)(v76[2] - v70[2]);
                v83 = (float)((float)((float)(*v76 - *v70) * (float)(*v76 - *v70))
                            + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81)));
                if ( v83 < v65 )
                {
                  v67 = v66;
                  v62 = v65;
                  v183 = (float)((float)(*v76 - *v70) * (float)(*v76 - *v70))
                       + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81));
                  v66 = 2;
                  v65 = v83;
                  v181 = 2;
                  goto LABEL_42;
                }
                if ( v83 < v62 )
                {
                  v67 = 2;
                  v62 = (float)((float)((float)(*v76 - *v70) * (float)(*v76 - *v70))
                              + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81)));
LABEL_42:
                  v184 = v62;
                  v182 = v67;
                }
                v84 = __ROL4__(v61[v60 + 1], 5);
                v85 = __ROL4__(v61[v60 + 2], 5);
                v86 = (float *)((char *)&v63->xyz.x + v84);
                v88 = (float)(*(float *)((char *)&v63->xyz.y + v84) - *(float *)((char *)&v63->xyz.y + v85));
                v89 = (float)(*(float *)((char *)&v63->xyz.z + v84) - *(float *)((char *)&v63->xyz.z + v85));
                v90 = (float)(*(float *)((char *)&v63->xyz.x + v84) - *(float *)((char *)&v63->xyz.x + v85));
                v87 = (float *)((char *)&v63->xyz.x + v85);
                v91 = (float)((float)((float)v90 * (float)v90)
                            + (float)((float)((float)v89 * (float)v89) + (float)((float)v88 * (float)v88)));
                if ( v91 < v65 )
                {
                  v67 = v66;
                  v62 = v65;
                  v66 = 3;
                  v183 = (float)((float)v90 * (float)v90)
                       + (float)((float)((float)v89 * (float)v89) + (float)((float)v88 * (float)v88));
                  v65 = v183;
                  v181 = 3;
                  goto LABEL_47;
                }
                if ( v91 < v62 )
                {
                  v67 = 3;
                  v62 = (float)((float)((float)v90 * (float)v90)
                              + (float)((float)((float)v89 * (float)v89) + (float)((float)v88 * (float)v88)));
LABEL_47:
                  v184 = v62;
                  v182 = v67;
                }
                v92 = v87[1];
                v93 = v87[2];
                v94 = *v87;
                v95 = (float *)((char *)&v63->xyz.x + __ROL4__(v61[v60 + 3], 5));
                v96 = (float)((float)v92 - v95[1]);
                v97 = (float)((float)v93 - v95[2]);
                v98 = (float)((float)((float)((float)v94 - *v95) * (float)((float)v94 - *v95))
                            + (float)((float)((float)v97 * (float)v97) + (float)((float)v96 * (float)v96)));
                if ( v98 < v65 )
                {
                  v67 = v66;
                  v62 = v65;
                  v66 = 4;
                  v183 = (float)((float)((float)v94 - *v95) * (float)((float)v94 - *v95))
                       + (float)((float)((float)v97 * (float)v97) + (float)((float)v96 * (float)v96));
                  v65 = v98;
                  v181 = 4;
                  goto LABEL_52;
                }
                if ( v98 < v62 )
                {
                  v67 = 4;
                  v62 = (float)((float)((float)((float)v94 - *v95) * (float)((float)v94 - *v95))
                              + (float)((float)((float)v97 * (float)v97) + (float)((float)v96 * (float)v96)));
LABEL_52:
                  v184 = v62;
                  v182 = v67;
                }
                v99 = (float)(v95[1] - v86[1]);
                v100 = (float)(v95[2] - v86[2]);
                v101 = (float)((float)((float)(*v95 - *v86) * (float)(*v95 - *v86))
                             + (float)((float)((float)v100 * (float)v100) + (float)((float)v99 * (float)v99)));
                if ( v101 < v65 )
                {
                  v67 = v66;
                  v62 = v65;
                  v66 = 5;
                  v183 = (float)((float)(*v95 - *v86) * (float)(*v95 - *v86))
                       + (float)((float)((float)v100 * (float)v100) + (float)((float)v99 * (float)v99));
                  v65 = v101;
                  v181 = 5;
                  goto LABEL_57;
                }
                if ( v101 < v62 )
                {
                  v67 = 5;
                  v62 = (float)((float)((float)(*v95 - *v86) * (float)(*v95 - *v86))
                              + (float)((float)((float)v100 * (float)v100) + (float)((float)v99 * (float)v99)));
LABEL_57:
                  v184 = v62;
                  v182 = v67;
                }
                _FP11 = (float)((float)v65 - (float)v62);
                __asm { vmr128    v63, v126 }
                v103 = 0;
                v104 = *v195;
                v105 = edgeVerts[v66][0] + v57;
                v106 = edgeVerts[v66][1] + v57;
                v107 = edgeVerts[v67][0] + v57;
                v108 = v105;
                __asm { fsel      f10, f11, f13, f0 }
                v110 = edgeVerts[v67][1] + v57;
                _R5 = &v209;
                v112 = (float *)((char *)&(*p_verts)->xyz.x + __ROL4__((*p_indexes)[v106], 5));
                v113 = __ROL4__((*p_indexes)[v110], 5);
                v114 = __ROL4__((*p_indexes)[v107], 5);
                v115 = (float *)((char *)&(*p_verts)->xyz.x + __ROL4__((*p_indexes)[v108], 5));
                v116 = __fsqrts(_FP10);
                v117 = *v112;
                _R6 = &v208;
                v119 = v112[2];
                v120 = v112[1];
                v121 = (float *)((char *)&(*p_verts)->xyz.x + v113);
                v122 = (float *)((char *)&(*p_verts)->xyz.x + v114);
                _R7 = &v207;
                v124 = (float)((float)v117 + *v115);
                v125 = (float)(*v121 + *v122);
                v126 = (float)(v121[2] + v122[2]);
                v127 = (float)((float)v119 + v115[2]);
                v128 = (float)((float)(v121[1] + v122[1]) * (float)0.5);
                v212 = (float)((float)v120 + v115[1]) * (float)0.5;
                v215 = v128;
                v211 = (float)v124 * (float)0.5;
                v214 = (float)v125 * (float)0.5;
                v216 = (float)v126 * (float)0.5;
                v213 = (float)v127 * (float)0.5;
                _FP5 = (float)((float)((float)v116 * (float)0.5) - (float)_FP26);
                v130 = (float)((float)v128 - v212);
                __asm { fsel      f26, f5, f6, f26 }
                v131 = (float)((float)((float)((float)(v216 - v213) * (float)(v216 - v213))
                                     + (float)((float)((float)(v214 - v211) * (float)(v214 - v211))
                                             + (float)((float)((float)v128 - v212) * (float)((float)v128 - v212))))
                             * (float)0.5);
                _FP10 = (float)((float)((float)((float)(v216 - v213) * (float)(v216 - v213))
                                      + (float)((float)((float)(v214 - v211) * (float)(v214 - v211))
                                              + (float)((float)((float)v128 - v212) * (float)((float)v128 - v212))))
                              - (float)v104);
                __asm { fsel      f9, f10, f13, f12 }
                v134 = __frsqrte(_FP9);
                v135 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v134 * (float)v131)
                                                                                             * (float)v134)
                                                                                     - (float)1.5)
                                                                     * (float)v134)
                                                             * (float)v131)
                                                     * (float)((float)-(float)((float)((float)((float)v134 * (float)v131)
                                                                                     * (float)v134)
                                                                             - (float)1.5)
                                                             * (float)v134))
                                             - (float)1.5)
                             * (float)((float)-(float)((float)((float)((float)v134 * (float)v131) * (float)v134)
                                                     - (float)1.5)
                                     * (float)v134));
                v136 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v134 * (float)v131) * (float)v134)
                                                                                             - (float)1.5)
                                                                             * (float)v134)
                                                                     * (float)v131)
                                                             * (float)((float)-(float)((float)((float)((float)v134 * (float)v131)
                                                                                             * (float)v134)
                                                                                     - (float)1.5)
                                                                     * (float)v134))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)((float)v134 * (float)v131) * (float)v134)
                                                             - (float)1.5)
                                             * (float)v134))
                             * (float)v131);
                v207 = (float)((float)-(float)((float)((float)v136 * (float)v135) - (float)1.5) * (float)v135)
                     * (float)(v214 - v211);
                v208 = (float)((float)-(float)((float)((float)v136 * (float)v135) - (float)1.5) * (float)v135)
                     * (float)v130;
                v209 = (float)((float)-(float)((float)((float)v136 * (float)v135) - (float)1.5) * (float)v135)
                     * (float)(v216 - v213);
                __asm
                {
                  lvlx128   v60, r0, r5
                  lvlx128   v62, r0, r6
                  lvlx128   v61, r0, r7
                  vrlimi128 v63, v61, 8, 0
                  vor128    v127, v95, v63
                  vrlimi128 v127, v62, 4, 3
                  vrlimi128 v127, v60, 2, 2
                }
                do
                {
                  __asm { lvx128    v63, r0, r19 }
                  __asm
                  {
                    vaddfp128 v12, v127, v63
                    lvx128    v13, r0, r21
                    lvx128    v0, r0, r20
                  }
                  v137 = *p_indexes;
                  v138 = *p_verts;
                  v139 = *(&v181 + v103);
                  _R17 = 1;
                  v141 = edgeVerts[v139][0];
                  __asm { vmaddfp   v0, v12, v0, v13 }
                  v142 = edgeVerts[v139][1];
                  v206 = v103 - 1;
                  v143 = v137[v142 + v57];
                  v144 = __ROL4__(v137[v141 + v57], 5);
                  v191 = &v183;
                  __asm { vcfpsxws128 v59, v0, 0 }
                  v145 = (int)v138 + v144;
                  v146 = (int)v138 + __ROL4__(v143, 5);
                  _R11 = (int)&v138->normal[v144];
                  __asm { vpkswss128 v58, v91, v59 }
                  __asm
                  {
                    vpkshus128 v0, v90, v58
                    stvebx    v0, 0, r11
                    stvebx    v0, r11, r3
                    stvebx    v0, r11, r18
                  }
                  _R11 = v146 + 20;
                  __asm
                  {
                    lvx128    v0, r0, r20
                    lvx128    v13, r0, r21
                    lvx128    v63, r0, r19
                    vaddfp128 v12, v127, v63
                    vmaddfp   v0, v12, v0, v13
                    vcfpsxws128 v57, v0, 0
                    vpkswss128 v56, v89, v57
                    vpkshus128 v0, v88, v56
                    stvebx    v0, 0, r11
                    stvebx    v0, r11, r17
                    stvebx    v0, r11, r18
                  }
                  *(_BYTE *)(v145 + 23) = (v103 == 1) - 1;
                  v149 = *(&v211 + 3 * v103);
                  *(_BYTE *)(v146 + 23) = (v103 != 1) - 1;
                  v150 = *(&v213 + 3 * v103);
                  v151 = (float)((float)__fsqrts(*(&v183 + v103)) * (float)0.5);
                  v152 = *(&v212 + 3 * v103);
                  *(float *)v145 = v149;
                  *(float *)(v145 + 4) = v152;
                  *(float *)(v145 + 8) = v150;
                  *(float *)v146 = v149;
                  *(float *)(v146 + 4) = v152;
                  *(float *)(v146 + 8) = v150;
                  if ( v151 > 255.0 )
                  {
                    idLib::Warning(fmt: v204, a12->name.str);
                    v151 = 255.0;
                  }
                  v153 = (int)v151;
                  v192 = v153;
                  if ( v153 >= 0 )
                  {
                    HIBYTE(v186) = -1;
                    if ( v153 <= 255 )
                      HIBYTE(v186) = v153;
                  }
                  else
                  {
                    HIBYTE(v186) = 0;
                  }
                  v154 = v186;
                  ++v103;
                  *(_DWORD *)(v145 + 28) = v186;
                  *(_DWORD *)(v146 + 28) = v154;
                }
                while ( v103 < 2 );
                v57 += 6;
                v60 += 6;
                v21 = (float *)v189;
                v155 = v188 + 4 < *v200;
                v188 += 4;
                if ( !v155 )
                {
                  v25 = v210;
                  v24 = v193;
                  p_y = v194;
                  p_z = v196;
                  p_geometry = v198;
                  goto LABEL_68;
                }
                continue;
              }
            }
          }
          v156 = *p_geometry;
          v157 = &v201->x;
          p_surfaces = v187;
          *v156 = **p_geometry - (float)_FP26;
          v156[1] = v156[1] - (float)_FP26;
          v156[2] = v156[2] - (float)_FP26;
          v156[3] = v156[3] + (float)_FP26;
          v156[4] = v156[4] + (float)_FP26;
          v156[5] = v156[5] + (float)_FP26;
          v158 = *p_geometry;
          v159 = *p_y;
          v160 = *v157;
          v161 = *v25;
          v162 = *v24;
          v163 = *p_z;
          _FP9 = (float)(v15->referenceBounds.b[0].x - **p_geometry);
          __asm { fsel      f8, f9, f10, f0 }
          v15->referenceBounds.b[0].x = _FP8;
          _FP6 = (float)((float)v159 - v158[1]);
          __asm { fsel      f5, f6, f7, f2 }
          *p_y = _FP5;
          _FP3 = (float)((float)v163 - v158[2]);
          __asm { fsel      f2, f3, f4, f1 }
          *p_z = _FP2;
          _FP0 = (float)(v158[3] - (float)v160);
          __asm { fsel      f13, f0, f1, f13 }
          *v157 = _FP13;
          _FP9 = (float)(v158[4] - (float)v161);
          __asm { fsel      f8, f9, f10, f12 }
          *v25 = _FP8;
          _FP6 = (float)(v158[5] - (float)v162);
          __asm { fsel      f5, f6, f7, f11 }
          *v24 = _FP5;
          goto LABEL_70;
        }
        idLib::Warning(fmt: v203, v15->name.str);
        p_surfaces = v187;
      }
LABEL_70:
      p_num = &v15->surfaces.num;
      v176 = v15->surfaces.num;
      v185 += 72;
      if ( ++v190 >= v176 )
        goto LABEL_71;
    }
  }
  v20 = 1;
  while ( list[v20].material->materialAutospriteType == materialAutospriteType )
  {
    ++v19;
    ++v20;
    if ( v19 >= *p_num )
      goto LABEL_8;
  }
  idLib::Warning(fmt: "Not all surfaces in %s use an autosprite material", this->name.str);
LABEL_73:
  _R0 = -288;
  __asm { lvx128    v126, r1, r0 }
  _R0 = -272;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// MakeStringValidForMaya
// EA  : 0x8286E4D0
// RVA : 0x0086E4D0
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

idStr *__fastcall MakeStringValidForMaya(idStr *result, const idStr *str)
{
  int len; // r29
  int i; // r10
  char *data; // r9
  int v7; // r11

  result->allocedAndFlag = 20;
  result->len = 0;
  result->data = result->baseBuffer;
  result->baseBuffer[0] = 0;
  len = str->len;
  idStr::EnsureAlloced(this: result, amount: str->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: result->data, Src: str->data, Size: len);
  result->data[len] = 0;
  result->len = len;
  if ( len == 0 )
    idStr::operator=(this: result, text: "_");
  for ( i = 0; i < result->len; ++i )
  {
    data = result->data;
    v7 = data[i];
    if ( v7 != 95 && (v7 < 65 || v7 > 90) && (v7 < 97 || v7 > 122) && (i < 0 || v7 < 48 || v7 > 57) )
      data[i] = 95;
  }
  return result;
}


// ========================================================================
// __unwind$238660
// EA  : 0x8286E5DC
// RVA : 0x0086E5DC
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_238660()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 144;
  if ( (*(_DWORD *)(v0 - 144 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 164));
  }
}


// ========================================================================
// ?ConvertToTriStrips@idStaticModel@@AAAXXZ
// EA  : 0x8286E840
// RVA : 0x0086E840
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall idStaticModel::ConvertToTriStrips(idStaticModel *this)
{
  int v2; // r26
  int v3; // r28
  idStaticModelSurface *v4; // r11
  idTriangles *geometry; // r30
  int num; // r10
  idList<unsigned short,5> v7[6]; // [sp+50h] [-60h] BYREF

  if ( r_staticModelTriStrips.valueInteger != 0 )
  {
    v2 = 0;
    if ( this->surfaces.num > 0 )
    {
      v3 = 0;
      do
      {
        v4 = &this->surfaces.list[v3];
        if ( (*((_BYTE *)v4->material + 72) & 8) == 0 )
        {
          geometry = v4->geometry;
          *(_WORD *)&v7[0].memTag = 1280;
          memset(v7, 0, 14);
          TriangleStripper(indexes: geometry->indexes, numIndexes: geometry->numIndexes, stripIndexes: v7);
          if ( v7[0].num < geometry->numIndexes )
          {
            memcpy(Dst: geometry->indexes, Src: v7[0].list, Size: 2 * v7[0].num);
            num = v7[0].num;
            geometry->vertexMask |= 0x200u;
            geometry->numIndexes = num;
          }
          if ( v7[0].listStatic == 0 || v7[0].listStatic == 2 )
          {
            if ( v7[0].list != nullptr )
              idMem::Free(this: &mem, ptr: v7[0].list, align: ALIGN_16);
            v7[0].list = nullptr;
            v7[0].size = 0;
          }
          v7[0].num = 0;
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->surfaces.num );
    }
  }
}


// ========================================================================
// __unwind$239428
// EA  : 0x8286E95C
// RVA : 0x0086E95C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_239428()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 80));
}


// ========================================================================
// BuildRemapTable
// EA  : 0x8286E990
// RVA : 0x0086E990
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall BuildRemapTable(
        idList<idSpawnArea::GeneratedPosition *,5> *remap,
        const idList<idVec3,5> *vecs,
        double epsilon)
{
  int num; // r30
  int size; // r11
  int v8; // r11
  int v9; // r10
  int v10; // r9
  idVec3 *list; // r8
  int v18; // r10
  int v25; // r30
  int v26; // r29
  int *v27; // r27
  int Vector; // r3
  int v29; // [sp+50h] [-F0h]
  idVec3 v30; // [sp+60h] [-E0h] BYREF
  idVec3 v31; // [sp+6Ch] [-D4h] BYREF
  idVectorSubset<idVec3,3> v32; // [sp+80h] [-C0h] BYREF

  num = vecs->num;
  if ( num <= remap->size || (unsigned __int8)idList<idNavSpline *,5>::Resize(this: remap, newsize: vecs->num) != 0 )
  {
    size = remap->size;
    if ( num < size )
      size = num;
    remap->num = size;
  }
  if ( epsilon == 0.0 )
  {
    v8 = 0;
    if ( vecs->num > 0 )
    {
      v9 = 0;
      do
        remap->list[v9++] = (idSpawnArea::GeneratedPosition *)v8++;
      while ( v8 < vecs->num );
    }
  }
  else
  {
    idVectorSubset<idVec3,3>::idVectorSubset<idVec3,3>(this: &v32);
    v10 = 0;
    _FP0 = 1.0e30;
    _FP13 = -1.0e30;
    v29 = vecs->num;
    _FP11 = 1.0e30;
    _FP12 = 1.0e30;
    _FP9 = -1.0e30;
    _FP10 = -1.0e30;
    if ( v29 > 0 )
    {
      list = vecs->list;
      v18 = 0;
      do
      {
        _FP6 = (float)((float)_FP0 - list[v18].x);
        ++v10;
        _FP5 = (float)(list[v18].x - (float)_FP13);
        _FP2 = (float)((float)_FP12 - list[v18].y);
        _FP30 = (float)((float)_FP11 - list[v18].z);
        _FP28 = (float)(list[v18].y - (float)_FP10);
        _FP27 = (float)(list[v18++].z - (float)_FP9);
        __asm
        {
          fsel      f0, f6, f7, f0
          fsel      f13, f5, f7, f13
          fsel      f12, f2, f4, f12
          fsel      f11, f30, f3, f11
          fsel      f10, f28, f4, f10
          fsel      f9, f27, f3, f9
        }
      }
      while ( v10 < v29 );
    }
    v30.x = (float)_FP0 - (float)((float)epsilon * (float)64.0);
    v30.y = (float)_FP12 - (float)((float)epsilon * (float)64.0);
    v30.z = (float)_FP11 - (float)((float)epsilon * (float)64.0);
    v31.x = (float)_FP13 + (float)((float)epsilon * (float)64.0);
    v31.y = (float)_FP10 + (float)((float)epsilon * (float)64.0);
    v31.z = (float)_FP9 + (float)((float)epsilon * (float)64.0);
    idVectorSubset<idVec3,3>::Init(this: &v32, mins: &v30, maxs: &v31, boxHashSize: 32, initialSize: v29);
    v25 = 0;
    if ( vecs->num > 0 )
    {
      v26 = 0;
      do
      {
        v27 = (int *)remap->list;
        Vector = idVectorSubset<idVec3,3>::FindVector(this: &v32, vectorList: vecs->list, vectorNum: v25++, epsilon);
        v27[v26++] = Vector;
      }
      while ( v25 < vecs->num );
    }
    idHashIndex::Free(this: &v32.hash);
  }
}


// ========================================================================
// __unwind$239552
// EA  : 0x8286EB78
// RVA : 0x0086EB78
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_239552()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(v0 - 320 + 128));
}


// ========================================================================
// BuildRemapTable_0
// EA  : 0x8286EBA8
// RVA : 0x0086EBA8
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall BuildRemapTable_0(
        idList<idSpawnArea::GeneratedPosition *,5> *remap,
        const idList<idVec2,5> *vecs,
        double epsilon)
{
  int num; // r29
  int size; // r11
  int v8; // r11
  int v9; // r10
  int v10; // r7
  int v11; // r29
  int v12; // r28
  int v13; // r29
  int v14; // r28
  int *list; // r27
  int Vector; // r3
  idBounds2D v17; // [sp+60h] [-A0h] BYREF
  idVectorSubset<idVec2,2> v18; // [sp+70h] [-90h] BYREF

  num = vecs->num;
  if ( num <= remap->size || (unsigned __int8)idList<idNavSpline *,5>::Resize(this: remap, newsize: vecs->num) != 0 )
  {
    size = remap->size;
    if ( num < size )
      size = num;
    remap->num = size;
  }
  if ( epsilon == 0.0 )
  {
    v8 = 0;
    if ( vecs->num > 0 )
    {
      v9 = 0;
      do
        remap->list[v9++] = (idSpawnArea::GeneratedPosition *)v8++;
      while ( v8 < vecs->num );
    }
  }
  else
  {
    idVectorSubset<idVec2,2>::idVectorSubset<idVec2,2>(this: &v18);
    v10 = vecs->num;
    v11 = 0;
    v17.bounds[0].x = 1.0e30;
    v17.bounds[0].y = 1.0e30;
    v17.bounds[1].x = -1.0e30;
    v17.bounds[1].y = v17.bounds[1].x;
    if ( v10 > 0 )
    {
      v12 = 0;
      do
      {
        idBounds2D::AddPoint(this: &v17, p: &vecs->list[v12]);
        ++v11;
        ++v12;
        v10 = vecs->num;
      }
      while ( v11 < v10 );
    }
    v17.bounds[0].x = v17.bounds[0].x - (float)((float)epsilon * (float)64.0);
    v17.bounds[0].y = v17.bounds[0].y - (float)((float)epsilon * (float)64.0);
    v17.bounds[1].x = v17.bounds[1].x + (float)((float)epsilon * (float)64.0);
    v17.bounds[1].y = v17.bounds[1].y + (float)((float)epsilon * (float)64.0);
    idVectorSubset<idVec2,2>::Init(
      this: &v18,
      mins: v17.bounds,
      maxs: &v17.bounds[1],
      boxHashSize: 32,
      initialSize: v10);
    v13 = 0;
    if ( vecs->num > 0 )
    {
      v14 = 0;
      do
      {
        list = (int *)remap->list;
        Vector = idVectorSubset<idVec2,2>::FindVector(this: &v18, vectorList: vecs->list, vectorNum: v13++, epsilon);
        list[v14++] = Vector;
      }
      while ( v13 < vecs->num );
    }
    idHashIndex::Free(this: &v18.hash);
  }
}


// ========================================================================
// __unwind$239832
// EA  : 0x8286ED60
// RVA : 0x0086ED60
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_239832()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(v0 - 256 + 112));
}


// ========================================================================
// ?WriteStaticBModel@idStaticModel@@SAXPBDIABV?$idList@VidStaticModelSurface@@$04@@ABV?$idList@UsourceSurface_t@@$04@@W4fsPath_t@@@Z
// EA  : 0x8286ED90
// RVA : 0x0086ED90
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall idStaticModel::WriteStaticBModel(
        const char *filename,
        unsigned int timestamp,
        const idList<idStaticModelSurface,5> *surfaces,
        const idList<sourceSurface_t,5> *sourceSurfaces,
        fsPath_t basePath,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        unsigned int a14)
{
  idStr *FileExtension; // r3
  bool v19; // r30
  idFile *v20; // r3
  int v21; // r24
  int v22; // r27
  idStaticModelSurface *v23; // r30
  idTriangles *geometry; // r29
  const idStr *v25; // r3
  int v26; // r29
  int v27; // r28
  idCollisionModelLocal **v28; // r30
  idFileLocal v29; // [sp+50h] [-C0h] BYREF
  int num; // [sp+54h] [-BCh] BYREF
  int v31; // [sp+58h] [-B8h] BYREF
  cmType_t ScriptP; // [sp+5Ch] [-B4h] BYREF
  idStr v33; // [sp+60h] [-B0h] BYREF
  idStr v34; // [sp+80h] [-90h] BYREF
  idStr v35[3]; // [sp+A0h] [-70h] BYREF

  a14 = timestamp;
  idStr::idStr(this: &v33, text: filename);
  FileExtension = idStr::GetFileExtension(this: &v34, result: &v33);
  v19 = idStr::Icmp(s1: FileExtension->data, s2: "pmodel") != 0;
  idStr::FreeData(this: &v34);
  if ( v19 )
    idStr::SetFileExtension(this: &v33, extension: "bmodel");
  idLib::Printf(fmt: "Writing %s\n", v33.data);
  v20 = fileSystem->OpenFileWrite(this: fileSystem, a2: v33.data, a3: basePath);
  v29.file = v20;
  if ( v20 != nullptr )
  {
    v20->Write(this: v20, a2: &BMODEL_MAGIC, a3: 4u);
    v29.file->Write(this: v29.file, a2: &a14, a3: 4u);
    num = surfaces->num;
    v29.file->Write(this: v29.file, a2: &num, a3: 4u);
    v21 = 0;
    if ( surfaces->num > 0 )
    {
      v22 = 0;
      do
      {
        v23 = &surfaces->list[v22];
        geometry = v23->geometry;
        if ( v23->material != nullptr && geometry != nullptr )
        {
          v25 = idMaterial::NameWithoutAutoMaterial(this: (idMaterial *)v35, result: (idStr *)v23->material);
          idFile::WriteString(this: v29.file, string: v25);
          idStr::FreeData(this: v35);
          v29.file->Write(this: v29.file, a2: &v23->materialNum, a3: 4u);
          v29.file->Write(this: v29.file, a2: &v23->binaryModelId, a3: 4u);
          idTriangles::WriteToFile(this: geometry, file: v29.file);
          v29.file->Write(this: v29.file, a2: &BMODEL_MAGIC, a3: 4u);
        }
        ++v21;
        ++v22;
      }
      while ( v21 < surfaces->num );
    }
    v31 = sourceSurfaces->num;
    v29.file->Write(this: v29.file, a2: &v31, a3: 4u);
    v26 = 0;
    if ( sourceSurfaces->num > 0 )
    {
      v27 = 0;
      do
      {
        v28 = (idCollisionModelLocal **)&sourceSurfaces->list[v27];
        idFile::WriteString(this: v29.file, string: (*v28)->name.str);
        ScriptP = idLexer::GetScriptP(this: *v28);
        v29.file->Write(this: v29.file, a2: &ScriptP, a3: 4u);
        v29.file->Write(this: v29.file, a2: v28 + 2, a3: 4u);
        v29.file->Write(this: v29.file, a2: v28 + 3, a3: 4u);
        v29.file->Write(this: v29.file, a2: v28 + 4, a3: 4u);
        ++v26;
        ++v27;
      }
      while ( v26 < sourceSurfaces->num );
    }
    idFileLocal::~idFileLocal(this: &v29);
  }
  else
  {
    idLib::Warning(fmt: "idStaticModel::WriteStaticBModel() - Could not open %s", filename);
    idFileLocal::~idFileLocal(this: &v29);
  }
  idStr::FreeData(this: &v33);
}


// ========================================================================
// __unwind$239966
// EA  : 0x8286F080
// RVA : 0x0086F080
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_239966()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$239967
// EA  : 0x8286F0A8
// RVA : 0x0086F0A8
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_239967()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$239968
// EA  : 0x8286F0D0
// RVA : 0x0086F0D0
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_239968()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$239969
// EA  : 0x8286F0F8
// RVA : 0x0086F0F8
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_239969()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 160));
}


// ========================================================================
// ?BuildMergeList@idStaticModel@@AAAXABV?$idList@VidStr@@$04@@AAV?$idList@PBVidMaterial@@$04@@AAV?$idList@H$04@@12@Z
// EA  : 0x8286F5C0
// RVA : 0x0086F5C0
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall idStaticModel::BuildMergeList(
        idStaticModel *this,
        const idList<idStr,5> *materialNames,
        idList<idSpawnArea::GeneratedPosition *,5> *materials,
        idList<idSpawnArea::GeneratedPosition *,5> *mergeTo,
        idList<idSpawnArea::GeneratedPosition *,5> *uniqueMaterials,
        idList<idSpawnArea::GeneratedPosition *,5> *uniqueMaterialNums)
{
  int num; // r30
  int size; // r11
  int v13; // r30
  int v14; // r11
  int v15; // r30
  int v16; // r11
  int v17; // r30
  int v18; // r11
  char v19; // r24
  int v20; // r8
  int v21; // r7
  int v22; // r6
  unsigned __int64 v23; // r10
  int v24; // r28
  idVehicleState **list; // r19
  int v26; // r27
  int v27; // r30
  idVehicleState **v28; // r29
  int v29; // r18
  const idMaterial *MaterialOrAutoMaterial; // r3
  int v31; // r30
  int v32; // r9
  int v33; // r10
  int v34; // ctr
  int *v35; // r11
  idVehicleState **v36; // r4
  const idDeclRenderParm *v37; // r27
  int v38; // r28
  int v39; // r29
  const idMaterial *v40; // r30
  int v41; // r9
  int v42; // r11
  const idMaterial *v43; // r10
  int *v44; // r30
  idSort_Quick<idSortedMaterial,idSort_SortedMaterial> v45; // [sp+50h] [-C0h] BYREF
  const idMaterial *v46; // [sp+54h] [-BCh] BYREF
  idList<idVehicleState *,5> v47; // [sp+60h] [-B0h] BYREF
  idStr v48[5]; // [sp+70h] [-A0h] BYREF

  num = materialNames->num;
  if ( num <= materials->size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(this: materials, newsize: materialNames->num) != 0 )
  {
    size = materials->size;
    if ( num < size )
      size = num;
    materials->num = size;
  }
  v13 = materialNames->num;
  if ( v13 <= mergeTo->size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(this: mergeTo, newsize: materialNames->num) != 0 )
  {
    v14 = mergeTo->size;
    if ( v13 < v14 )
      v14 = v13;
    mergeTo->num = v14;
  }
  v15 = materialNames->num;
  if ( v15 <= uniqueMaterials->size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(this: uniqueMaterials, newsize: materialNames->num) != 0 )
  {
    v16 = uniqueMaterials->size;
    if ( v15 < v16 )
      v16 = v15;
    uniqueMaterials->num = v16;
  }
  v17 = materialNames->num;
  if ( v17 <= uniqueMaterialNums->size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(this: uniqueMaterialNums, newsize: materialNames->num) != 0 )
  {
    v18 = uniqueMaterialNums->size;
    if ( v17 < v18 )
      v18 = v17;
    uniqueMaterialNums->num = v18;
  }
  if ( materialNames->num != 0 )
  {
    memset(&v47, 0, 14);
    *(_WORD *)&v47.memTag = 1280;
    idList<idThread *,58>::Clear(this: &v47);
    v19 = 0;
    idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)&v47, newNum: materialNames->num);
    LODWORD(v23) = materialNames->num;
    v24 = 0;
    list = v47.list;
    if ( (int)v23 > 0 )
    {
      v26 = 0;
      v27 = 0;
      v28 = v47.list + 2;
      do
      {
        idStr::idStr(this: v48, text: &materialNames->list[v26]);
        v29 = StripMaterialNumber(name: v48);
        MaterialOrAutoMaterial = FindMaterialOrAutoMaterial(name: v48[0].data);
        materials->list[v27] = (idSpawnArea::GeneratedPosition *)MaterialOrAutoMaterial;
        uniqueMaterials->list[v27] = (idSpawnArea::GeneratedPosition *)MaterialOrAutoMaterial;
        uniqueMaterialNums->list[v27] = (idSpawnArea::GeneratedPosition *)v29;
        mergeTo->list[v27] = (idSpawnArea::GeneratedPosition *)v24;
        *(v28 - 2) = (idVehicleState *)materialNames->list[v26].data;
        *(v28 - 1) = (idVehicleState *)MaterialOrAutoMaterial;
        *v28 = (idVehicleState *)v29;
        v28[1] = (idVehicleState *)v24;
        if ( v29 != -1 )
          v19 = 1;
        idStr::FreeData(this: v48);
        ++v24;
        ++v27;
        ++v26;
        v28 += 4;
      }
      while ( v24 < materialNames->num );
    }
    if ( v19 != 0 )
    {
      v45.__vftable = (idSort_Quick<idSortedMaterial,idSort_SortedMaterial>_vtbl *)&idSort_SortedMaterial::`vftable';
      v31 = v47.num;
      if ( list != nullptr )
        idSort_Quick<idSortedMaterial,idSort_SortedMaterial>::Sort(
          this: &v45,
          base: (idSortedMaterial *)list,
          num: v47.num,
          a4: v22,
          a5: v21,
          a6: v20,
          a7: v23);
      v32 = 0;
      v45.__vftable = (idSort_Quick<idSortedMaterial,idSort_SortedMaterial>_vtbl *)&idSort<idSortedMaterial>::`vftable';
      if ( v31 > 0 )
      {
        v33 = 0;
        v34 = v31;
        v35 = (int *)(list - 2);
        do
        {
          mergeTo->list[v35[5]] = (idSpawnArea::GeneratedPosition *)v32++;
          uniqueMaterials->list[v33] = (idSpawnArea::GeneratedPosition *)v35[3];
          v35 += 4;
          uniqueMaterialNums->list[v33++] = (idSpawnArea::GeneratedPosition *)*v35;
          --v34;
        }
        while ( v34 != 0 );
      }
      if ( (v47.listStatic == 0 || v47.listStatic == 2) && list != nullptr )
      {
        v36 = list;
LABEL_57:
        idMem::Free(this: &mem, ptr: v36, align: ALIGN_16);
      }
    }
    else
    {
      if ( r_mergeModelSurfaces.valueInteger == 0 )
      {
        idList<idThread *,58>::Clear(this: &v47);
        return;
      }
      v37 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                        this: &idDeclRenderParm::resourceList,
                                        name: "discrete",
                                        makeDefault: true);
      idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)uniqueMaterials, newNum: 0);
      v38 = 0;
      if ( materials->num > 0 )
      {
        v39 = 0;
        do
        {
          v46 = (const idMaterial *)materials->list[v39];
          v40 = v46;
          if ( v46 != nullptr )
          {
            if ( idParmBlock::GetInteger(this: &v46->parmBlock, parm: v37) != 0 )
              goto LABEL_51;
            v41 = 0;
            if ( uniqueMaterials->num > 0 )
            {
              v42 = 0;
              while ( 1 )
              {
                v43 = (const idMaterial *)uniqueMaterials->list[v42];
                if ( v43 != nullptr && v40 == v43 )
                  break;
                ++v41;
                ++v42;
                if ( v41 >= uniqueMaterials->num )
                  goto LABEL_50;
              }
              mergeTo->list[v39] = (idSpawnArea::GeneratedPosition *)v41;
            }
LABEL_50:
            if ( v41 == uniqueMaterials->num )
            {
LABEL_51:
              v44 = (int *)mergeTo->list;
              v44[v39] = idList<idAnimWebBlendTree *,5>::Append(
                           this: (idList<enum encounterGroupRole_t,5> *)uniqueMaterials,
                           obj: (const encounterGroupRole_t *)&v46);
            }
          }
          ++v38;
          ++v39;
        }
        while ( v38 < materials->num );
      }
      if ( (v47.listStatic == 0 || v47.listStatic == 2) && list != nullptr )
      {
        v36 = list;
        goto LABEL_57;
      }
    }
  }
}


// ========================================================================
// __unwind$240979
// EA  : 0x8286F9C8
// RVA : 0x0086F9C8
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_240979()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$240980
// EA  : 0x8286F9F0
// RVA : 0x0086F9F0
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_240980()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$240981
// EA  : 0x8286FA18
// RVA : 0x0086FA18
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_240981()
{
  int v0; // r12

  idSort_SortedMaterial::~idSort_SortedMaterial(this: (idSort_SortedMaterial *)(v0 - 272 + 80));
}


// ========================================================================
// ?WriteStaticBModel@idStaticModel@@QBAXPBDW4fsPath_t@@@Z
// EA  : 0x8286FA40
// RVA : 0x0086FA40
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall idStaticModel::WriteStaticBModel(
        idStaticModel *this,
        const char *filename,
        fsPath_t basePath,
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
        unsigned int a14)
{
  idStaticModel::WriteStaticBModel(
    filename,
    timestamp: 0,
    surfaces: (const idList<idStaticModelSurface,5> *)&this->surfaces,
    sourceSurfaces: &this->sourceSurfaces,
    basePath,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14);
}


// ========================================================================
// ?ConvertToOBJ@idStaticModel@@QBA_NPBDAAVidOBJModel@@@Z
// EA  : 0x8286FA68
// RVA : 0x0086FA68
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

BOOL __fastcall idStaticModel::ConvertToOBJ(idStaticModel *this, const char *groupName, idOBJModel *destOBJ)
{
  int num; // r29
  int v7; // r28
  const encounterGroupRole_t *v8; // r27
  BOOL v9; // r28
  idList<enum encounterGroupRole_t,5> v11; // [sp+50h] [-70h] BYREF
  idList<enum encounterGroupRole_t,5> v12[6]; // [sp+60h] [-60h] BYREF

  memset(v12, 0, 14);
  v12[0].memTag = 5;
  v12[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v12);
  memset(&v11, 0, 14);
  *(_WORD *)&v11.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v11);
  num = this->surfaces.num;
  if ( num > v12[0].size )
    idList<idNavSpline *,5>::Resize(
      this: (idList<idSpawnArea::GeneratedPosition *,5> *)v12,
      newsize: this->surfaces.num);
  if ( num > v11.size )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v11, newsize: num);
  if ( num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = (const encounterGroupRole_t *)&this->surfaces.list[v7];
      idList<idAnimWebBlendTree *,5>::Append(this: v12, obj: v8 + 4);
      idList<idAnimWebBlendTree *,5>::Append(this: &v11, obj: v8);
      --num;
      ++v7;
    }
    while ( num != 0 );
  }
  v9 = idOBJModel::AddGroupGeometry(
         this: destOBJ,
         groupName,
         tris: (const idList<idTriangles *,5> *)v12,
         mats: (const idList<idMaterial const *,5> *)&v11);
  if ( v11.listStatic == 0 || v11.listStatic == 2 )
  {
    if ( v11.list != nullptr )
      idMem::Free(this: &mem, ptr: v11.list, align: ALIGN_16);
    v11.list = nullptr;
    v11.size = 0;
  }
  v11.num = 0;
  if ( (v12[0].listStatic == 0 || v12[0].listStatic == 2) && v12[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v12[0].list, align: ALIGN_16);
  return v9;
}


// ========================================================================
// __unwind$241393
// EA  : 0x8286FBC8
// RVA : 0x0086FBC8
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_241393()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$241394
// EA  : 0x8286FBF0
// RVA : 0x0086FBF0
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_241394()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 80));
}


// ========================================================================
// ?MergeSurfacesAndBuildSourceSurfaces@idStaticModel@@AAAXXZ
// EA  : 0x8286FE00
// RVA : 0x0086FE00
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall idStaticModel::MergeSurfacesAndBuildSourceSurfaces(idStaticModel *this)
{
  const idDecl *v2; // r11
  bool v3; // r29
  int v4; // r30
  BOOL v5; // r25
  idList<idStaticModelSurface,84> *p_surfaces; // r27
  int v7; // r28
  idStaticModelSurface *list; // r11
  idStaticModelSurface *v9; // r29
  idMaterial *material; // r3
  idTriangles *geometry; // r11
  char v12; // r11
  bool v13; // zf
  const idMaterial *v14; // r3
  int v15; // r8
  idStaticModelSurface *v16; // r7
  int v17; // r10
  idStaticModelSurface *v18; // r11
  idTriangles *v19; // r9
  char v20; // r9
  idTriangles *v21; // r3
  const idTriangles *v22; // r4
  int numVerts; // r10
  cm_buildMaterial_t v24; // [sp+50h] [-90h] BYREF
  idStr v25[3]; // [sp+70h] [-70h] BYREF

  idStr::idStr(this: v25, text: this->name.str);
  idStr::StripFileExtension(this: v25);
  if ( v25[0].data != nullptr )
    v2 = idDeclInfo::FindWithInheritance(this: &idDeclSkins::resourceList, name: v25[0].data, makeDefault: false);
  else
    v2 = nullptr;
  v3 = v2 != nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
  v4 = 0;
  if ( this->surfaces.num > 0 )
  {
    v5 = v3;
    p_surfaces = &this->surfaces;
    v7 = 0;
    do
    {
      list = p_surfaces->list;
      v9 = &p_surfaces->list[v7];
      v24.surfaceType = v4;
      v24.checkCount = 0;
      material = list[v7].material;
      geometry = list[v7].geometry;
      v24.contentFlags = (int)material;
      v24.index = geometry->numVerts - 1;
      if ( v5 )
      {
        if ( geometry->cpuVertexMask != 31 || (v13 = geometry->verts != nullptr, v12 = 1, !v13) )
          v12 = 0;
        if ( v12 != 0 )
        {
          v14 = idMaterial::CompatibleGenericMaterial(this: material);
          if ( v14 != nullptr )
            v9->material = v14;
          v15 = 0;
          if ( v4 > 0 )
          {
            v16 = p_surfaces->list;
            v17 = 0;
            while ( 1 )
            {
              v18 = &v16[v17];
              if ( v16[v17].material == v9->material )
              {
                v19 = v18->geometry;
                if ( v19->cpuVertexMask != 31 || (v13 = v19->verts != nullptr, v20 = 1, !v13) )
                  v20 = 0;
                if ( v20 != 0 )
                  break;
              }
              ++v15;
              ++v17;
              if ( v15 >= v4 )
                goto LABEL_23;
            }
            v21 = v18->geometry;
            v22 = v9->geometry;
            v24.surfaceType = v15;
            numVerts = v22->numVerts;
            v24.checkCount = v21->numVerts;
            v24.index = numVerts + v24.checkCount - 1;
            idTriangles::MergeTriangles(this: v21, tri: v22);
            idList<idStaticModelSurface,84>::RemoveIndex(this: &this->surfaces, index: v4--);
            --v7;
          }
        }
      }
LABEL_23:
      idList<sourceSurface_t,59>::Append(this: (idList<cm_buildMaterial_t,13> *)&this->sourceSurfaces, obj: &v24);
      ++v4;
      ++v7;
    }
    while ( v4 < this->surfaces.num );
  }
  idStr::FreeData(this: v25);
}


// ========================================================================
// __unwind$241745
// EA  : 0x8286FFC8
// RVA : 0x0086FFC8
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_241745()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?TestLoadAllObjModels_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82870380
// RVA : 0x00870380
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall TestLoadAllObjModels_f(const idCmdArgs *args)
{
  idFileList *v1; // r29
  int v2; // r24
  int v3; // r28
  idStaticModel *v4; // r3
  idStaticModel *v5; // r30

  v1 = fileSystem->ListFilesTree(this: fileSystem, a2: "models", a3: "obj", a4: 0);
  v2 = 0;
  if ( v1->list.num > 0 )
  {
    v3 = 0;
    do
    {
      idLib::Printf(fmt: "loading %s.\n", v1->list.list[v3].data);
      v4 = (idStaticModel *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x194u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      if ( v4 != nullptr )
        v5 = idStaticModel::idStaticModel(this: v4);
      else
        v5 = nullptr;
      idResource::SetName(this: v5, _name: v1->list.list[v3].data);
      idStaticModel::PristineLoadResource(this: v5);
      if ( v5 != nullptr )
        ((void (__fastcall *)(idStaticModel *, int))v5->dtr_idResource)(a1: v5, a2: 1);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->list.num );
  }
  idFileList::~idFileList(this: v1);
  idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
}


// ========================================================================
// __unwind$242460
// EA  : 0x828704B4
// RVA : 0x008704B4
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_242460()
{
  int v0; // r12

  std::auto_ptr<idFileList>::~auto_ptr<idFileList>(this: (std::auto_ptr<idFileList> *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$242461
// EA  : 0x828704DC
// RVA : 0x008704DC
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall _unwind_242461(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 84), tag: a2);
}


// ========================================================================
// __unwind$242462
// EA  : 0x82870504
// RVA : 0x00870504
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_242462()
{
  int v0; // r12

  idLoadScreen::Shutdown(this: (idLoadScreen *)(v0 - 160 + 84));
}


// ========================================================================
// ?TestLoadAllLwoModels_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82870538
// RVA : 0x00870538
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall TestLoadAllLwoModels_f(const idCmdArgs *args)
{
  idFileList *v1; // r29
  int v2; // r24
  int v3; // r28
  idStaticModel *v4; // r3
  idStaticModel *v5; // r30

  v1 = fileSystem->ListFilesTree(this: fileSystem, a2: "models", a3: "lwo", a4: 0);
  v2 = 0;
  if ( v1->list.num > 0 )
  {
    v3 = 0;
    do
    {
      idLib::Printf(fmt: "loading %s.\n", v1->list.list[v3].data);
      v4 = (idStaticModel *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x194u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      if ( v4 != nullptr )
        v5 = idStaticModel::idStaticModel(this: v4);
      else
        v5 = nullptr;
      idResource::SetName(this: v5, _name: v1->list.list[v3].data);
      idStaticModel::PristineLoadResource(this: v5);
      if ( v5 != nullptr )
        ((void (__fastcall *)(idStaticModel *, int))v5->dtr_idResource)(a1: v5, a2: 1);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->list.num );
  }
  idFileList::~idFileList(this: v1);
  idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
}


// ========================================================================
// __unwind$242634
// EA  : 0x8287066C
// RVA : 0x0087066C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_242634()
{
  int v0; // r12

  std::auto_ptr<idFileList>::~auto_ptr<idFileList>(this: (std::auto_ptr<idFileList> *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$242635
// EA  : 0x82870694
// RVA : 0x00870694
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall _unwind_242635(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 84), tag: a2);
}


// ========================================================================
// __unwind$242636
// EA  : 0x828706BC
// RVA : 0x008706BC
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_242636()
{
  int v0; // r12

  idLoadScreen::Shutdown(this: (idLoadScreen *)(v0 - 160 + 84));
}


// ========================================================================
// ?ConvertASEToModelSurfaces@idStaticModel@@AAA_NPBVidASEModel@@@Z
// EA  : 0x828714D0
// RVA : 0x008714D0
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

BOOL __fastcall idStaticModel::ConvertASEToModelSurfaces(idStaticModel *this, const idASEModel *ase)
{
  idStaticModel *v2; // r25
  int v4; // r27
  idStr *list; // r30
  int v6; // r28
  idASEMaterial *v7; // r23
  size_t len; // r29
  const idDeclVehicleUpgrade **v10; // r15
  int v11; // r16
  const idDeclVehicleUpgrade **v12; // r28
  const idDeclVehicleUpgrade **v13; // r20
  const idDeclVehicleUpgrade **v14; // r30
  int v15; // r21
  int v16; // r19
  idASEObject *v17; // r27
  idASEMesh *p_mesh; // r30
  unsigned __int8 normalsParsed; // r25
  double valueFloat; // fp1
  double v21; // fp1
  long double v22; // fp2
  int size; // r11
  int num; // r29
  double vOffset; // fp29
  double v26; // fp30
  double vTiling; // fp27
  double uTiling; // fp28
  double v29; // fp31
  double v30; // fp0
  idASEMaterial *v31; // r29
  long double v32; // fp2
  long double v33; // fp2
  int v34; // r9
  int v35; // r11
  float *p_x; // r10
  idVec2 *v37; // r8
  double v38; // fp11
  double v39; // fp8
  int v40; // r9
  idRawSurface *v41; // r29
  idSpawnArea::GeneratedPosition **v42; // r23
  int v43; // r26
  idSpawnArea::GeneratedPosition **v44; // r22
  int v45; // r28
  int v46; // r27
  int i; // r29
  aseFace_t *faces; // r10
  int v49; // r8
  int v50; // r11
  int v51; // r5
  int v52; // r4
  int v53; // r11
  aseFace_t *v54; // r10
  int v55; // r11
  int v56; // r6
  int v57; // r5
  int v58; // r4
  int v59; // r3
  unsigned int v60; // [sp+50h] [-1A0h]
  idList<idVec2,72> v61; // [sp+60h] [-190h] BYREF
  idList<idRawSurface,5> v62; // [sp+70h] [-180h] BYREF
  idList<idStr,5> v63; // [sp+80h] [-170h] BYREF
  idList<idVec3,5> v64; // [sp+90h] [-160h] BYREF
  idList<idSpawnArea::GeneratedPosition *,5> v65; // [sp+A0h] [-150h] BYREF
  idList<idSpawnArea::GeneratedPosition *,5> v66; // [sp+B0h] [-140h] BYREF
  idVec3 v67; // [sp+C0h] [-130h] BYREF
  int v68; // [sp+CCh] [-124h]
  idCVar *v69; // [sp+D0h] [-120h]
  int v70; // [sp+D4h] [-11Ch]
  int v71; // [sp+D8h] [-118h]
  idCVar *v72; // [sp+DCh] [-114h]
  idList<idDeclVehicleUpgrade const *,5> v73; // [sp+E0h] [-110h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v74; // [sp+F0h] [-100h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v75; // [sp+100h] [-F0h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v76[4]; // [sp+110h] [-E0h] BYREF

  v2 = this;
  if ( ase == nullptr || ase->objects.num < 1 )
    return false;
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: v76);
  *(_WORD *)&v63.memTag = 1280;
  memset(&v63, 0, 14);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v74);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v73);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v75);
  if ( ase->materials.num > 0 )
  {
    idList<idStr,3>::SetNum(this: &v63, newNum: ase->objects.num);
    v4 = 0;
    if ( ase->objects.num > 0 )
    {
      list = v63.list;
      v6 = 0;
      do
      {
        v7 = ase->materials.list[ase->objects.list[v6]->materialRef];
        len = v7->name.len;
        idStr::EnsureAlloced(this: list, amount: v7->name.len + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: list->data, Src: v7->name.data, Size: len);
        ++v4;
        ++v6;
        list->data[len] = 0;
        list->len = len;
        ++list;
      }
      while ( v4 < ase->objects.num );
    }
  }
  if ( (unsigned __int8)ValidateMaterialNames(modelName: v2->name.str, strings: &v63) == 0 )
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v75);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v73);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v74);
    idList<idStr,99>::~idList<idStr,99>(this: &v63);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v76);
    return false;
  }
  idStaticModel::BuildMergeList(
    this: v2,
    materialNames: &v63,
    materials: (idList<idSpawnArea::GeneratedPosition *,5> *)&v74,
    mergeTo: (idList<idSpawnArea::GeneratedPosition *,5> *)v76,
    uniqueMaterials: (idList<idSpawnArea::GeneratedPosition *,5> *)&v73,
    uniqueMaterialNums: (idList<idSpawnArea::GeneratedPosition *,5> *)&v75);
  *(_WORD *)&v62.memTag = 1280;
  memset(&v62, 0, 14);
  idList<idRawSurface,5>::SetNum(this: &v62, newNum: v73.num);
  v10 = v76[0].list;
  v11 = 0;
  v12 = v74.list;
  v13 = v73.list;
  v14 = v75.list;
  if ( ase->objects.num > 0 )
  {
    v68 = (char *)v75.list - (char *)v73.list;
    v70 = (char *)v74.list - (char *)v73.list;
    v15 = 0;
    v69 = &r_slopTexCoord;
    v16 = 0;
    v72 = &r_slopVertex;
    while ( 1 )
    {
      v17 = ase->objects.list[v15];
      p_mesh = &v17->mesh;
      normalsParsed = v17->mesh.normalsParsed;
      if ( v11 < v74.num )
        normalsParsed &= idMaterial::MaterialForcesNormalSmoothing(this: *(idMaterial **)((char *)v13 + v70)) - 1;
      *(_WORD *)&v66.memTag = 1280;
      memset(&v66, 0, 14);
      *(_WORD *)&v65.memTag = 1280;
      memset(&v65, 0, 14);
      if ( this->pristine )
        valueFloat = 0.0;
      else
        valueFloat = v72->valueFloat;
      BuildRemapTable(remap: &v66, vecs: &v17->mesh.vertexes, epsilon: valueFloat);
      if ( this->pristine )
        v21 = 0.0;
      else
        v21 = v69->valueFloat;
      BuildRemapTable_0(remap: &v65, vecs: &v17->mesh.tvertexes, epsilon: v21);
      *(_WORD *)&v64.memTag = 1280;
      memset(&v64, 0, 14);
      size = 0;
      memset(&v61, 0, 14);
      *(_WORD *)&v61.memTag = 1280;
      num = v17->mesh.tvertexes.num;
      if ( num <= 0 )
        goto LABEL_23;
      if ( (unsigned __int8)idList<idVec2,72>::Resize(this: &v61, newsize: v17->mesh.tvertexes.num) != 0 )
        break;
LABEL_25:
      if ( ase->materials.num != 0 )
      {
        v31 = ase->materials.list[v17->materialRef];
        *(double *)&v22 = v31->angle;
        v26 = -v31->uOffset;
        vOffset = v31->vOffset;
        uTiling = v31->uTiling;
        vTiling = v31->vTiling;
        v32 = sin(x: v22);
        v29 = (float)*(double *)&v32;
        *(double *)&v32 = v31->angle;
        v33 = cos(x: v32);
        v30 = (float)*(double *)&v33;
      }
      else
      {
        vOffset = 0.0;
        v26 = 0.0;
        vTiling = 1.0;
        uTiling = 1.0;
        v29 = 0.0;
        v30 = 1.0;
      }
      v34 = 0;
      if ( v17->mesh.tvertexes.num > 0 )
      {
        v35 = 0;
        do
        {
          ++v34;
          p_x = &v17->mesh.tvertexes.list[v35].x;
          v37 = &v61.list[v35];
          v38 = (float)((float)(p_x[1] * (float)vTiling) + (float)vOffset);
          v39 = (float)((float)((float)(*p_x * (float)uTiling) + (float)v26) * (float)v29);
          v37->x = (float)((float)((float)(*p_x * (float)uTiling) + (float)v26) * (float)v30)
                 + (float)((float)((float)(p_x[1] * (float)vTiling) + (float)vOffset) * (float)v29);
          v37->y = (float)((float)v38 * (float)v30) - (float)v39;
          ++v35;
        }
        while ( v34 < v17->mesh.tvertexes.num );
      }
      v40 = v68;
      v41 = &v62.list[v16];
      v41->material = (const idMaterial *)*v13;
      v41->materialNum = *(int *)((char *)v13 + v40);
      idRawSurface::InitHash(
        this: v41,
        vList: &v17->mesh.vertexes,
        tvList: (const idList<idVec2,5> *)&v61,
        morphList: &v64);
      v42 = v66.list;
      v43 = 0;
      v44 = v65.list;
      v41->generateNormals = (_cntlzw(normalsParsed) & 0x20) != 0;
      v41->normalEpsilon = (float)1.0 - r_slopNormal.valueFloat;
      if ( v17->mesh.numFaces > 0 )
      {
        v45 = 0;
        v46 = 3;
        while ( 2 )
        {
          for ( i = 0; i < 3; ++i )
          {
            faces = p_mesh->faces;
            v49 = v45 * 21 + i;
            v50 = faces->vertexNum[v49];
            if ( v50 < 0 || v50 >= p_mesh->vertexes.num )
              goto _LN446;
            v51 = 0;
            v52 = (int)v42[v50];
            if ( p_mesh->numTVFaces == p_mesh->numFaces )
            {
              v71 = p_mesh->tvertexes.num;
              if ( v71 != 0 )
              {
                v53 = faces[v45].tVertexNum[i];
                if ( v53 < 0 || v53 >= v71 )
                {
                  idLib::Error(fmt: "ConvertASEToModelSurfaces: bad tex coord index in ASE file %s", this->name.str);
_LN446:
                  idLib::Error(fmt: "ConvertASEToModelSurfaces: bad vertex index in ASE file %s", this->name.str);
                  return _LN447(a1: v59, a2: v58, a3: v57, a4: v56);
                }
                v51 = (int)v44[v53];
              }
            }
            v67.x = 0.0;
            v67.y = 0.0;
            v67.z = 1.0;
            if ( normalsParsed != 0 )
              v67 = *(idVec3 *)&p_mesh->faces->vertexNum[3 * v46 + 3 * i];
            v60 = -1;
            if ( p_mesh->colorsParsed )
            {
              v54 = p_mesh->faces;
              *(_WORD *)((char *)&v60 + 1) = *(_WORD *)&v54->vertexColors[v49][1];
              HIBYTE(v60) = v54[v45].vertexColors[i][0];
              LOBYTE(v60) = v54->vertexColors[v49][3];
            }
            idRawSurface::AddVert(
              this: &v62.list[(_DWORD)v10[v15]],
              v: v52,
              tv: v51,
              normal: &v67,
              color: v60,
              morph: 0);
          }
          ++v43;
          ++v45;
          v46 += 7;
          if ( v43 < p_mesh->numFaces )
            continue;
          break;
        }
      }
      if ( v61.listStatic == 0 || v61.listStatic == 2 )
      {
        if ( v61.list != nullptr )
          idMem::Free(this: &mem, ptr: v61.list, align: ALIGN_16);
        v61.list = nullptr;
        v61.size = 0;
      }
      v61.num = 0;
      if ( v64.listStatic == 0 || v64.listStatic == 2 )
      {
        if ( v64.list != nullptr )
          idMem::Free(this: &mem, ptr: v64.list, align: ALIGN_16);
        v64.list = nullptr;
        v64.size = 0;
      }
      v64.num = 0;
      if ( v65.listStatic == 0 || v65.listStatic == 2 )
      {
        if ( v44 != nullptr )
          idMem::Free(this: &mem, ptr: v44, align: ALIGN_16);
        v65.list = nullptr;
        v65.size = 0;
      }
      v65.num = 0;
      if ( v66.listStatic == 0 || v66.listStatic == 2 )
      {
        if ( v42 != nullptr )
          idMem::Free(this: &mem, ptr: v42, align: ALIGN_16);
        v66.list = nullptr;
        v66.size = 0;
      }
      v55 = ase->objects.num;
      ++v11;
      ++v16;
      v66.num = 0;
      ++v15;
      ++v13;
      if ( v11 >= v55 )
      {
        v14 = v75.list;
        v13 = v73.list;
        v12 = v74.list;
        v2 = this;
        goto LABEL_70;
      }
    }
    size = v61.size;
LABEL_23:
    v61.num = num;
    if ( num >= size )
      v61.num = size;
    goto LABEL_25;
  }
LABEL_70:
  EmitRawSurfacesToStaticModel(rawSurfaces: &v62, model: v2);
  if ( v62.listStatic == 0 || v62.listStatic == 2 )
  {
    if ( v62.list != nullptr )
      idListArrayDelete<idRawSurface>(ptr: v62.list, num: v62.size);
    v62.list = nullptr;
    v62.size = 0;
  }
  v62.num = 0;
  if ( (v75.listStatic == 0 || v75.listStatic == 2) && v14 != nullptr )
    idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
  if ( (v73.listStatic == 0 || v73.listStatic == 2) && v13 != nullptr )
    idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
  if ( (v74.listStatic == 0 || v74.listStatic == 2) && v12 != nullptr )
    idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
  if ( (v63.listStatic == 0 || v63.listStatic == 2) && v63.list != nullptr )
    idListArrayDelete<idStr>(ptr: v63.list, num: v63.size);
  if ( (v76[0].listStatic == 0 || v76[0].listStatic == 2) && v10 != nullptr )
    idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
  return true;
}


// ========================================================================
// $LN447
// EA  : 0x82871D1C
// RVA : 0x00871D1C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _LN447()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 272));
}


// ========================================================================
// __unwind$245065
// EA  : 0x82871D44
// RVA : 0x00871D44
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245065()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 496 + 128));
}


// ========================================================================
// __unwind$245066
// EA  : 0x82871D6C
// RVA : 0x00871D6C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245066()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 240));
}


// ========================================================================
// __unwind$245067
// EA  : 0x82871D94
// RVA : 0x00871D94
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245067()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 224));
}


// ========================================================================
// __unwind$245068
// EA  : 0x82871DBC
// RVA : 0x00871DBC
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245068()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 256));
}


// ========================================================================
// __unwind$245069
// EA  : 0x82871DE4
// RVA : 0x00871DE4
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245069()
{
  int v0; // r12

  idList<idRawSurface,5>::~idList<idRawSurface,5>(this: (idList<idRawSurface,5> *)(v0 - 496 + 112));
}


// ========================================================================
// __unwind$245070
// EA  : 0x82871E0C
// RVA : 0x00871E0C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245070()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 176));
}


// ========================================================================
// __unwind$245071
// EA  : 0x82871E34
// RVA : 0x00871E34
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245071()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 160));
}


// ========================================================================
// __unwind$245072
// EA  : 0x82871E5C
// RVA : 0x00871E5C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245072()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 144));
}


// ========================================================================
// __unwind$245073
// EA  : 0x82871E84
// RVA : 0x00871E84
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245073()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 96));
}


// ========================================================================
// ?ConvertLWOToModelSurfaces@idStaticModel@@AAA_NPBUst_lwObject@@PBUst_lwLayer@@MM@Z
// EA  : 0x82871EB8
// RVA : 0x00871EB8
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

int __fastcall idStaticModel::ConvertLWOToModelSurfaces(
        idStaticModel *this,
        const st_lwObject *lwo,
        const st_lwLayer *layer,
        double vertexSlop,
        double texCoordSlop)
{
  int count; // r30
  int size; // r11
  int v12; // r10
  int v13; // r11
  st_lwVMap *i; // r30
  unsigned int type; // r11
  int v16; // r28
  int nverts; // r10
  int v18; // r29
  float *v19; // r10
  double v20; // fp13
  double v21; // fp12
  int v22; // r28
  int v23; // r10
  int v24; // r29
  float *v25; // r10
  double v26; // fp12
  bfx::BinaryReplayLogOut *v27; // r3
  int v28; // r4
  bool v29; // cr57
  char v30; // r11
  st_lwSurface *j; // r30
  idStr *list; // r27
  int v33; // r30
  idStr *v34; // r29
  int num; // r28
  int *v37; // r18
  st_lwSurface *surf; // r6
  idVehicleState **v39; // r7
  int v40; // r8
  int v41; // r9
  int v42; // r30
  double v43; // fp31
  char v44; // r3
  idVehicleState **v45; // r14
  int v46; // r30
  idMaterial **v47; // r29
  char *v48; // r25
  int v49; // r27
  idMaterial *v50; // r9
  idRawSurface *v51; // r26
  idRawSurface *v52; // r29
  idRawSurface *v53; // r28
  idStr *v54; // r28
  int v55; // r30
  idStr *v56; // r29
  st_lwSurface *v57; // r19
  idVehicleState **v58; // r17
  idVehicleState **v59; // r24
  idVehicleState **v60; // r15
  int v61; // r11
  int v62; // r9
  float x; // r10
  st_lwSurface **v64; // r26
  int v65; // r8
  int v66; // r11
  int *v67; // r27
  int v68; // r18
  int v69; // r29
  st_lwPolVert *v70; // r30
  int v71; // r25
  int v72; // r5
  int v73; // r8
  int v74; // r28
  st_lwVMapList *ptVMaps; // r11
  st_lwVMapList *v76; // r11
  st_lwVMapList *polVertVMaps; // r10
  int nvmaps; // r3
  int v79; // r4
  st_lwVMapPt *vm; // r6
  int v81; // r7
  st_lwVMap *vmap; // r10
  st_lwVMapPt *v83; // r11
  unsigned int v84; // r9
  int offset; // r10
  float *v86; // r10
  int v87; // r10
  int v88; // r11
  idRawSurface *v89; // r29
  int v90; // r30
  idRawSurface *v91; // r28
  idStr *v92; // r28
  int v93; // r30
  idStr *v94; // r29
  unsigned int v95; // [sp+50h] [-1F0h]
  idList<idVec2,72> v96; // [sp+60h] [-1E0h] BYREF
  idList<idRawSurface,5> v97; // [sp+70h] [-1D0h] BYREF
  idList<idVec3,5> v98; // [sp+80h] [-1C0h] BYREF
  idVec3 v99; // [sp+90h] [-1B0h] BYREF
  idList<idVec3,5> v100; // [sp+A0h] [-1A0h] BYREF
  idList<idStr,5> v101; // [sp+B0h] [-190h] BYREF
  idVec2 v102[2]; // [sp+C0h] [-180h] BYREF
  idList<idVehicleState *,5> v103; // [sp+D0h] [-170h] BYREF
  idList<idVehicleState *,5> v104; // [sp+E0h] [-160h] BYREF
  idList<idVehicleState *,5> v105; // [sp+F0h] [-150h] BYREF
  idList<idVehicleState *,5> v106; // [sp+100h] [-140h] BYREF
  idList<idVehicleState *,5> v107; // [sp+110h] [-130h] BYREF
  idList<idVehicleState *,5> v108; // [sp+120h] [-120h] BYREF
  idList<int,5> v109; // [sp+130h] [-110h] BYREF
  int v110; // [sp+140h] [-100h]
  int v111; // [sp+144h] [-FCh]
  idVec3 v112; // [sp+148h] [-F8h] BYREF
  _DWORD v113[6]; // [sp+158h] [-E8h] BYREF
  idStr v114; // [sp+170h] [-D0h] BYREF

  memset(&v100, 0, 14);
  *(_WORD *)&v100.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v100);
  memset(&v98, 0, 14);
  *(_WORD *)&v98.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v98);
  memset(&v96, 0, 14);
  *(_WORD *)&v96.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v96);
  memset(&v103, 0, 14);
  *(_WORD *)&v103.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v103);
  *(_WORD *)&v101.memTag = 1280;
  memset(&v101, 0, 14);
  memset(&v108, 0, 14);
  *(_WORD *)&v108.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v108);
  memset(&v105, 0, 14);
  *(_WORD *)&v105.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v105);
  memset(&v104, 0, 14);
  *(_WORD *)&v104.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v104);
  memset(&v107, 0, 14);
  *(_WORD *)&v107.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v107);
  memset(&v106, 0, 14);
  *(_WORD *)&v106.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v106);
  count = layer->point.count;
  size = v100.size;
  if ( count > v100.size )
  {
    if ( (unsigned __int8)idList<idVec3,59>::Resize(this: &v100, newsize: layer->point.count) == 0 )
      goto LABEL_6;
    size = v100.size;
  }
  v100.num = count;
  if ( count >= size )
    v100.num = size;
LABEL_6:
  v12 = 0;
  if ( layer->point.count > 0 )
  {
    v13 = 0;
    do
    {
      ++v12;
      v100.list[v13].x = layer->point.pt[v13].pos[0] - layer->pivot[0];
      v100.list[v13].y = layer->point.pt[v13].pos[2] - layer->pivot[2];
      v100.list[v13].z = layer->point.pt[v13].pos[1] - layer->pivot[1];
      ++v13;
    }
    while ( v12 < layer->point.count );
  }
  idList<idAngles,5>::Append(this: &v98, obj: &vec3_origin);
  for ( i = layer->vmap; i != nullptr; i = i->next )
  {
    type = i->type;
    if ( type == 1297044038 )
    {
      v16 = 0;
      nverts = i->nverts;
      i->offset = v98.num;
      if ( nverts > 0 )
      {
        v18 = 0;
        do
        {
          v19 = i->val[v18];
          v20 = v19[1];
          v21 = *v19;
          v99.z = v19[2];
          v99.x = v21;
          v99.y = v20;
          idList<idAngles,5>::Append(this: &v98, obj: &v99);
          ++v16;
          ++v18;
        }
        while ( v16 < i->nverts );
      }
    }
    else if ( type == 1415075158 )
    {
      v22 = 0;
      v23 = i->nverts;
      i->offset = v96.num;
      if ( v23 > 0 )
      {
        v24 = 0;
        do
        {
          v25 = i->val[v24];
          v26 = (float)((float)1.0 - v25[1]);
          v102[0].x = *v25;
          v102[0].y = v26;
          idList<idVec2,72>::Append(this: &v96, obj: v102);
          ++v22;
          ++v24;
        }
        while ( v22 < i->nverts );
      }
    }
    else
    {
      ++breakHere;
    }
  }
  if ( v96.num == 0 )
  {
    idLib::Warning(fmt: "ConvertLWOToModelSurfaces: model '%s' has bad or missing uv data", this->name.str);
    v28 = v96.size;
    v29 = v96.size > 1;
    if ( v96.size >= 1 )
    {
LABEL_34:
      v96.num = 1;
      if ( !v29 )
        v96.num = v28;
      goto LABEL_36;
    }
    if ( v96.listStatic == 0 )
    {
      if ( v96.granularity == 1 )
      {
        idPhysics_StaticMulti::UpdateTime(this: v27);
        v28 = v96.size;
      }
      v96.list = (idVec2 *)idListArrayResize<idVec2>(
                             voldptr: (char *)v96.list,
                             oldNum: v28,
                             newNum: 1,
                             tag: (memTag_t)v96.memTag,
                             zeroBuffer: false);
      if ( v96.list == nullptr )
      {
        v28 = v96.size;
        v30 = 0;
LABEL_32:
        if ( v30 == 0 )
          goto LABEL_36;
        v29 = v28 > 1;
        goto LABEL_34;
      }
      v28 = 1;
      v96.size = 1;
      if ( v96.num > 1 )
        v96.num = 1;
    }
    v30 = 1;
    goto LABEL_32;
  }
LABEL_36:
  BuildRemapTable(remap: (idList<idSpawnArea::GeneratedPosition *,5> *)&v107, vecs: &v100, epsilon: vertexSlop);
  BuildRemapTable_0(
    remap: (idList<idSpawnArea::GeneratedPosition *,5> *)&v106,
    vecs: (const idList<idVec2,5> *)&v96,
    epsilon: texCoordSlop);
  for ( j = lwo->surf; j != nullptr; j = j->next )
  {
    idStr::idStr(this: &v114, text: j->name);
    idList<idStr,5>::Append(this: &v101, obj: &v114);
    idStr::FreeData(this: &v114);
  }
  if ( (unsigned __int8)ValidateMaterialNames(modelName: this->name.str, strings: &v101) == 0 )
  {
    if ( (v106.listStatic == 0 || v106.listStatic == 2) && v106.list != nullptr )
      idMem::Free(this: &mem, ptr: v106.list, align: ALIGN_16);
    if ( (v107.listStatic == 0 || v107.listStatic == 2) && v107.list != nullptr )
      idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
    if ( (v104.listStatic == 0 || v104.listStatic == 2) && v104.list != nullptr )
      idMem::Free(this: &mem, ptr: v104.list, align: ALIGN_16);
    if ( (v105.listStatic == 0 || v105.listStatic == 2) && v105.list != nullptr )
      idMem::Free(this: &mem, ptr: v105.list, align: ALIGN_16);
    if ( (v108.listStatic == 0 || v108.listStatic == 2) && v108.list != nullptr )
      idMem::Free(this: &mem, ptr: v108.list, align: ALIGN_16);
    if ( v101.listStatic == 0 || v101.listStatic == 2 )
    {
      list = v101.list;
      if ( v101.list != nullptr )
      {
        v33 = v101.size;
        if ( v101.size > 0 )
        {
          v34 = v101.list;
          do
          {
            idStr::FreeData(this: v34);
            --v33;
            ++v34;
          }
          while ( v33 != 0 );
        }
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      }
    }
    if ( (v103.listStatic == 0 || v103.listStatic == 2) && v103.list != nullptr )
      idMem::Free(this: &mem, ptr: v103.list, align: ALIGN_16);
    if ( v96.listStatic == 0 || v96.listStatic == 2 )
    {
      if ( v96.list != nullptr )
        idMem::Free(this: &mem, ptr: v96.list, align: ALIGN_16);
      v96.list = nullptr;
      v96.size = 0;
    }
    v96.num = 0;
    if ( v98.listStatic == 0 || v98.listStatic == 2 )
    {
      if ( v98.list != nullptr )
        idMem::Free(this: &mem, ptr: v98.list, align: ALIGN_16);
      v98.list = nullptr;
      v98.size = 0;
    }
    v98.num = 0;
    if ( (v100.listStatic == 0 || v100.listStatic == 2) && v100.list != nullptr )
      idMem::Free(this: &mem, ptr: v100.list, align: ALIGN_16);
    return 0;
  }
  idStaticModel::BuildMergeList(
    this,
    materialNames: &v101,
    materials: (idList<idSpawnArea::GeneratedPosition *,5> *)&v108,
    mergeTo: (idList<idSpawnArea::GeneratedPosition *,5> *)&v103,
    uniqueMaterials: (idList<idSpawnArea::GeneratedPosition *,5> *)&v105,
    uniqueMaterialNums: (idList<idSpawnArea::GeneratedPosition *,5> *)&v104);
  *(_WORD *)&v109.memTag = 1280;
  memset(&v109, 0, 14);
  v102[0].x = 0.0;
  num = v105.num;
  idList<idRenderModelCommitted *,5>::SetNum(this: &v109, newNum: v105.num, initValue: (const int *)v102);
  v37 = v109.list;
  if ( v109.num > 0 )
  {
    surf = lwo->surf;
    if ( surf != nullptr )
    {
      v39 = v103.list;
      do
      {
        v40 = 0;
        if ( layer->polygon.count > 0 )
        {
          v41 = 0;
          do
          {
            if ( layer->polygon.pol[v41].surf == surf )
              ++v37[(_DWORD)*v39];
            ++v40;
            ++v41;
          }
          while ( v40 < layer->polygon.count );
        }
        surf = surf->next;
        ++v39;
      }
      while ( surf != nullptr );
    }
  }
  v42 = 0;
  *(_WORD *)&v97.memTag = 1280;
  memset(&v97, 0, 14);
  v43 = (float)((float)1.0 - r_slopNormal.valueFloat);
  if ( num <= 0 || (v44 = idList<idRawSurface,5>::Resize(this: &v97, newsize: num), v42 = v97.size, v44 != 0) )
  {
    v97.num = num;
    if ( num >= v42 )
      v97.num = v42;
  }
  v45 = v105.list;
  if ( num > 0 )
  {
    v46 = 0;
    v47 = (idMaterial **)v105.list;
    v48 = (char *)((char *)v104.list - (char *)v37);
    v49 = (char *)v37 - (char *)v105.list;
    do
    {
      v50 = *v47;
      LODWORD(v102[0].x) = &v97.list[v46];
      *(_DWORD *)LODWORD(v102[0].x) = v50;
      v97.list[v46].materialNum = *(_DWORD *)&v48[(_DWORD)v47 + v49];
      idRawSurface::InitHash(
        this: &v97.list[v46],
        vList: &v100,
        tvList: (const idList<idVec2,5> *)&v96,
        morphList: &v98);
      idRawSurface::InitIndex(this: &v97.list[v46], maxIndexes: 3 * *(_DWORD *)((char *)v47 + v49));
      v51 = &v97.list[v46];
      v51->generateNormals = idMaterial::MaterialForcesNormalSmoothing(this: *v47);
      --num;
      v97.list[v46].normalEpsilon = v43;
      ++v47;
      ++v46;
    }
    while ( num != 0 );
    v42 = v97.size;
  }
  if ( v97.num == 0 )
  {
    if ( v97.listStatic == 0 || v97.listStatic == 2 )
    {
      v52 = v97.list;
      if ( v97.list != nullptr )
      {
        v53 = v97.list;
        if ( v42 > 0 )
        {
          do
          {
            idRawSurface::~idRawSurface(this: v52);
            --v42;
            ++v52;
          }
          while ( v42 != 0 );
        }
        idMem::Free(this: &mem, ptr: v53, align: ALIGN_16);
      }
      v97.list = nullptr;
      v97.size = 0;
    }
    v97.num = 0;
    if ( (v109.listStatic == 0 || v109.listStatic == 2) && v37 != nullptr )
      idMem::Free(this: &mem, ptr: v37, align: ALIGN_16);
    if ( (v106.listStatic == 0 || v106.listStatic == 2) && v106.list != nullptr )
      idMem::Free(this: &mem, ptr: v106.list, align: ALIGN_16);
    if ( (v107.listStatic == 0 || v107.listStatic == 2) && v107.list != nullptr )
      idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
    if ( (v104.listStatic == 0 || v104.listStatic == 2) && v104.list != nullptr )
      idMem::Free(this: &mem, ptr: v104.list, align: ALIGN_16);
    if ( (v105.listStatic == 0 || v105.listStatic == 2) && v45 != nullptr )
      idMem::Free(this: &mem, ptr: v45, align: ALIGN_16);
    if ( (v108.listStatic == 0 || v108.listStatic == 2) && v108.list != nullptr )
      idMem::Free(this: &mem, ptr: v108.list, align: ALIGN_16);
    if ( v101.listStatic == 0 || v101.listStatic == 2 )
    {
      v54 = v101.list;
      if ( v101.list != nullptr )
      {
        v55 = v101.size;
        if ( v101.size > 0 )
        {
          v56 = v101.list;
          do
          {
            idStr::FreeData(this: v56);
            --v55;
            ++v56;
          }
          while ( v55 != 0 );
        }
        idMem::Free(this: &mem, ptr: v54, align: ALIGN_16);
      }
    }
    if ( (v103.listStatic == 0 || v103.listStatic == 2) && v103.list != nullptr )
      idMem::Free(this: &mem, ptr: v103.list, align: ALIGN_16);
    if ( v96.listStatic == 0 || v96.listStatic == 2 )
    {
      if ( v96.list != nullptr )
        idMem::Free(this: &mem, ptr: v96.list, align: ALIGN_16);
      v96.list = nullptr;
      v96.size = 0;
    }
    v96.num = 0;
    if ( v98.listStatic == 0 || v98.listStatic == 2 )
    {
      if ( v98.list != nullptr )
        idMem::Free(this: &mem, ptr: v98.list, align: ALIGN_16);
      v98.list = nullptr;
      v98.size = 0;
    }
    v98.num = 0;
    if ( (v100.listStatic == 0 || v100.listStatic == 2) && v100.list != nullptr )
      idMem::Free(this: &mem, ptr: v100.list, align: ALIGN_16);
    return 0;
  }
  v57 = lwo->surf;
  v58 = v107.list;
  v59 = v106.list;
  if ( v57 != nullptr )
  {
    v60 = v103.list;
    while ( 1 )
    {
      v61 = layer->polygon.count;
      v62 = 0;
      v110 = 0;
      if ( v61 > 0 )
        break;
LABEL_216:
      v57 = v57->next;
      ++v60;
      if ( v57 == nullptr )
        goto LABEL_217;
    }
    x = 0.0;
    v102[0].x = 0.0;
    while ( 1 )
    {
      v64 = (st_lwSurface **)((char *)&layer->polygon.pol->surf + LODWORD(x));
      if ( *v64 == v57 )
      {
        v65 = (int)v64[8];
        v66 = 2;
        v111 = 2;
        if ( v65 > 2 )
          break;
      }
LABEL_215:
      v88 = layer->polygon.count;
      ++v62;
      LODWORD(x) += 40;
      v110 = v62;
      v102[0].x = x;
      if ( v62 >= v88 )
        goto LABEL_216;
    }
    v113[0] = 0;
LABEL_167:
    v113[2] = v66;
    v67 = v113;
    v113[1] = v66 - 1;
    v68 = 3;
LABEL_168:
    v69 = *v67;
    v70 = &layer->polygon.polVerts[(int)v64[9] + *v67];
    v71 = (int)v58[v70->index];
    v112.x = v70->norm[0];
    v112.y = v70->norm[2];
    v112.z = v70->norm[1];
    idVec3::FixDegenerateNormal(this: &v112);
    v72 = 0;
    v73 = 0;
    LODWORD(v99.y) = (int)(float)(v57->color.rgb[0] * (float)255.0);
    if ( v99.y >= 0.0 )
    {
      HIBYTE(v95) = -1;
      if ( SLODWORD(v99.y) <= 255 )
        HIBYTE(v95) = LOBYTE(v99.y);
    }
    else
    {
      HIBYTE(v95) = 0;
    }
    LODWORD(v99.y) = (int)(float)(v57->color.rgb[1] * (float)255.0);
    if ( v99.y >= 0.0 )
    {
      BYTE1(v95) = -1;
      if ( SLODWORD(v99.y) <= 255 )
        BYTE1(v95) = LOBYTE(v99.y);
    }
    else
    {
      BYTE1(v95) = 0;
    }
    LODWORD(v99.y) = (int)(float)(v57->color.rgb[2] * (float)255.0);
    if ( v99.y >= 0.0 )
    {
      BYTE2(v95) = -1;
      if ( SLODWORD(v99.y) <= 255 )
        BYTE2(v95) = LOBYTE(v99.y);
    }
    else
    {
      BYTE2(v95) = 0;
    }
    v74 = 0;
    LOBYTE(v95) = -1;
    while ( 1 )
    {
      if ( v74 != 0 )
      {
        polVertVMaps = layer->polygon.polVertVMaps;
        if ( polVertVMaps != nullptr )
        {
          v76 = &polVertVMaps[(int)v64[9] + v69];
LABEL_186:
          nvmaps = v76->nvmaps;
          v79 = 0;
          if ( v76->nvmaps > 0 )
          {
            vm = v76->vm;
            v81 = 0;
            do
            {
              vmap = vm[v81].vmap;
              v83 = &vm[v81];
              v84 = vmap->type;
              switch ( v84 )
              {
                case 0x54585556u:
                  v72 = (int)*(&v59[vmap->offset] + v83->index);
                  break;
                case 0x4D4F5246u:
                  offset = vmap->offset;
                  if ( offset <= 1 )
                    v73 = v83->index + offset;
                  break;
                case 0x52474241u:
                  v86 = vmap->val[v83->index];
                  LODWORD(v99.y) = (int)(float)(*v86 * (float)255.0);
                  if ( v99.y >= 0.0 )
                  {
                    HIBYTE(v95) = -1;
                    if ( SLODWORD(v99.y) <= 255 )
                      HIBYTE(v95) = LOBYTE(v99.y);
                  }
                  else
                  {
                    HIBYTE(v95) = 0;
                  }
                  LODWORD(v99.y) = (int)(float)(v86[1] * (float)255.0);
                  if ( v99.y >= 0.0 )
                  {
                    BYTE1(v95) = -1;
                    if ( SLODWORD(v99.y) <= 255 )
                      BYTE1(v95) = LOBYTE(v99.y);
                  }
                  else
                  {
                    BYTE1(v95) = 0;
                  }
                  LODWORD(v99.y) = (int)(float)(v86[2] * (float)255.0);
                  if ( v99.y >= 0.0 )
                  {
                    BYTE2(v95) = -1;
                    if ( SLODWORD(v99.y) <= 255 )
                      BYTE2(v95) = LOBYTE(v99.y);
                  }
                  else
                  {
                    BYTE2(v95) = 0;
                  }
                  LODWORD(v99.y) = (int)(float)(v86[3] * (float)255.0);
                  if ( v99.y >= 0.0 )
                  {
                    LOBYTE(v95) = -1;
                    if ( SLODWORD(v99.y) <= 255 )
                      LOBYTE(v95) = LOBYTE(v99.y);
                  }
                  else
                  {
                    LOBYTE(v95) = 0;
                  }
                  break;
                default:
                  break;
              }
              ++v79;
              ++v81;
            }
            while ( v79 < nvmaps );
          }
        }
      }
      else
      {
        ptVMaps = layer->point.ptVMaps;
        if ( ptVMaps != nullptr )
        {
          v76 = &ptVMaps[v70->index];
          goto LABEL_186;
        }
      }
      if ( ++v74 >= 2 )
      {
        idRawSurface::AddVert(this: &v97.list[(_DWORD)*v60], v: v71, tv: v72, normal: &v112, color: v95, morph: v73);
        --v68;
        ++v67;
        if ( v68 == 0 )
        {
          v87 = (int)v64[8];
          v66 = v111 + 1;
          v111 = v66;
          if ( v66 >= v87 )
          {
            v45 = v105.list;
            v37 = v109.list;
            x = v102[0].x;
            v62 = v110;
            goto LABEL_215;
          }
          goto LABEL_167;
        }
        goto LABEL_168;
      }
    }
  }
LABEL_217:
  EmitRawSurfacesToStaticModel(rawSurfaces: &v97, model: this);
  this->referencePosition.x = layer->pivot[0];
  this->referencePosition.y = layer->pivot[2];
  this->referencePosition.z = layer->pivot[1];
  if ( v97.listStatic == 0 || v97.listStatic == 2 )
  {
    v89 = v97.list;
    if ( v97.list != nullptr )
    {
      v90 = v97.size;
      v91 = v97.list;
      if ( v97.size > 0 )
      {
        do
        {
          idRawSurface::~idRawSurface(this: v89);
          --v90;
          ++v89;
        }
        while ( v90 != 0 );
      }
      idMem::Free(this: &mem, ptr: v91, align: ALIGN_16);
    }
    v97.list = nullptr;
    v97.size = 0;
  }
  v97.num = 0;
  if ( (v109.listStatic == 0 || v109.listStatic == 2) && v37 != nullptr )
    idMem::Free(this: &mem, ptr: v37, align: ALIGN_16);
  if ( (v106.listStatic == 0 || v106.listStatic == 2) && v59 != nullptr )
    idMem::Free(this: &mem, ptr: v59, align: ALIGN_16);
  if ( (v107.listStatic == 0 || v107.listStatic == 2) && v58 != nullptr )
    idMem::Free(this: &mem, ptr: v58, align: ALIGN_16);
  if ( (v104.listStatic == 0 || v104.listStatic == 2) && v104.list != nullptr )
    idMem::Free(this: &mem, ptr: v104.list, align: ALIGN_16);
  if ( (v105.listStatic == 0 || v105.listStatic == 2) && v45 != nullptr )
    idMem::Free(this: &mem, ptr: v45, align: ALIGN_16);
  if ( (v108.listStatic == 0 || v108.listStatic == 2) && v108.list != nullptr )
    idMem::Free(this: &mem, ptr: v108.list, align: ALIGN_16);
  if ( v101.listStatic == 0 || v101.listStatic == 2 )
  {
    v92 = v101.list;
    if ( v101.list != nullptr )
    {
      v93 = v101.size;
      if ( v101.size > 0 )
      {
        v94 = v101.list;
        do
        {
          idStr::FreeData(this: v94);
          --v93;
          ++v94;
        }
        while ( v93 != 0 );
      }
      idMem::Free(this: &mem, ptr: v92, align: ALIGN_16);
    }
  }
  if ( (v103.listStatic == 0 || v103.listStatic == 2) && v103.list != nullptr )
    idMem::Free(this: &mem, ptr: v103.list, align: ALIGN_16);
  if ( v96.listStatic == 0 || v96.listStatic == 2 )
  {
    if ( v96.list != nullptr )
      idMem::Free(this: &mem, ptr: v96.list, align: ALIGN_16);
    v96.list = nullptr;
    v96.size = 0;
  }
  v96.num = 0;
  if ( v98.listStatic == 0 || v98.listStatic == 2 )
  {
    if ( v98.list != nullptr )
      idMem::Free(this: &mem, ptr: v98.list, align: ALIGN_16);
    v98.list = nullptr;
    v98.size = 0;
  }
  v98.num = 0;
  if ( (v100.listStatic == 0 || v100.listStatic == 2) && v100.list != nullptr )
    idMem::Free(this: &mem, ptr: v100.list, align: ALIGN_16);
  return 1;
}


// ========================================================================
// __unwind$245920
// EA  : 0x82873024
// RVA : 0x00873024
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245920()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 160));
}


// ========================================================================
// __unwind$245921
// EA  : 0x8287304C
// RVA : 0x0087304C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245921()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 128));
}


// ========================================================================
// __unwind$245922
// EA  : 0x82873074
// RVA : 0x00873074
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245922()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 96));
}


// ========================================================================
// __unwind$245923
// EA  : 0x8287309C
// RVA : 0x0087309C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245923()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 208));
}


// ========================================================================
// __unwind$245924
// EA  : 0x828730C4
// RVA : 0x008730C4
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245924()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 576 + 176));
}


// ========================================================================
// __unwind$245925
// EA  : 0x828730EC
// RVA : 0x008730EC
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245925()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 288));
}


// ========================================================================
// __unwind$245926
// EA  : 0x82873114
// RVA : 0x00873114
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245926()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 240));
}


// ========================================================================
// __unwind$245927
// EA  : 0x8287313C
// RVA : 0x0087313C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245927()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 224));
}


// ========================================================================
// __unwind$245928
// EA  : 0x82873164
// RVA : 0x00873164
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245928()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 272));
}


// ========================================================================
// __unwind$245929
// EA  : 0x8287318C
// RVA : 0x0087318C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245929()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 256));
}


// ========================================================================
// __unwind$245930
// EA  : 0x828731B4
// RVA : 0x008731B4
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245930()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 368));
}


// ========================================================================
// __unwind$245931
// EA  : 0x828731DC
// RVA : 0x008731DC
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245931()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 304));
}


// ========================================================================
// __unwind$245932
// EA  : 0x82873204
// RVA : 0x00873204
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_245932()
{
  int v0; // r12

  idList<idRawSurface,5>::~idList<idRawSurface,5>(this: (idList<idRawSurface,5> *)(v0 - 576 + 112));
}


// ========================================================================
// ?ConvertOBJToModelSurfaces@idStaticModel@@AAA_NPBVidOBJModel@@@Z
// EA  : 0x82873430
// RVA : 0x00873430
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

BOOL __fastcall idStaticModel::ConvertOBJToModelSurfaces(idStaticModel *this, const idOBJModel *obj)
{
  idStaticModel *v2; // r21
  idStr *list; // r19
  int size; // r22
  int v7; // r29
  int v8; // r30
  const idParsedMtl *v9; // r3
  const idMaterial *v10; // r28
  int num; // r30
  bool v12; // r3
  int v13; // r28
  int v14; // r29
  idStr *v15; // r30
  const char *str; // r4
  const idMaterial **v17; // r3
  int v18; // r10
  int v19; // r9
  int v20; // r8
  int v21; // r7
  int v22; // r6
  int v23; // r5
  int v24; // r4
  double valueFloat; // fp1
  double v26; // fp1
  int v27; // r28
  int v28; // r11
  double v29; // fp31
  idVehicleState **v30; // r22
  idVehicleState **v31; // r23
  int v32; // r30
  int *v33; // r29
  int v34; // r27
  int v35; // r10
  idVehicleState **v36; // r15
  int v37; // r18
  idVehicleState **v38; // r20
  idVehicleState **v39; // r17
  int v40; // r21
  idVehicleState *v41; // r23
  idOBJMesh *v42; // r26
  bool hasNormals; // r30
  bool v44; // r3
  unsigned __int8 v45; // r7
  int v46; // r22
  int v47; // r27
  int v48; // r28
  int v49; // r30
  int *v50; // r29
  idVehicleState *v51; // r28
  int v52; // r27
  int v53; // r29
  int v54; // r30
  idOBJFace *v55; // r10
  int v56; // r8
  int v57; // r9
  int v58; // r11
  int v59; // r4
  int v60; // r11
  int v61; // r11
  idVec3 *v62; // r11
  double z; // fp12
  idVec3 *v64; // r11
  int v65; // r11
  int v66; // r11
  int v67; // r10
  int v68; // r9
  int v69; // r8
  int v70; // r7
  idRawSurface *v71; // r29
  int v72; // r30
  idRawSurface *v73; // r28
  int v74; // r30
  idStr *v75; // r29
  int v76; // r6
  int v77; // r5
  int v78; // r4
  int v79; // r3
  int v80; // [sp+8h] [-238h]
  int v81; // [sp+Ch] [-234h]
  int v82; // [sp+10h] [-230h]
  int v83; // [sp+14h] [-22Ch]
  int v84; // [sp+18h] [-228h]
  int v85; // [sp+1Ch] [-224h]
  int v86; // [sp+20h] [-220h]
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> >,std::_Iterator_base0> *v87; // [sp+24h] [-21Ch]
  std::_Tree<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > v88; // [sp+50h] [-1F0h] BYREF
  idList<idRawSurface,5> v89; // [sp+60h] [-1E0h] BYREF
  std::allocator<std::pair<idStr const ,idMaterial const *> > v90[16]; // [sp+70h] [-1D0h] BYREF
  idList<idStr,5> v91; // [sp+80h] [-1C0h] BYREF
  idList<idVehicleState *,5> v92; // [sp+90h] [-1B0h] BYREF
  idList<idVehicleState *,5> v93; // [sp+A0h] [-1A0h] BYREF
  idList<idVehicleState *,5> v94; // [sp+B0h] [-190h] BYREF
  idList<idVehicleState *,5> v95; // [sp+C0h] [-180h] BYREF
  idList<idVehicleState *,5> v96; // [sp+D0h] [-170h] BYREF
  idList<idVehicleState *,5> v97; // [sp+E0h] [-160h] BYREF
  idVec3 v98; // [sp+F0h] [-150h] BYREF
  idList<enum encounterGroupRole_t,5> v99; // [sp+100h] [-140h] BYREF
  idList<idVec3,5> v100; // [sp+110h] [-130h] BYREF
  idList<idVec3,5> v101; // [sp+120h] [-120h] BYREF
  std::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > v102; // [sp+130h] [-110h] BYREF
  idStr v103; // [sp+140h] [-100h] BYREF
  bool v104; // [sp+160h] [-E0h]
  bool v105; // [sp+161h] [-DFh]
  bool v106; // [sp+162h] [-DEh]
  idMtlOptions v107; // [sp+170h] [-D0h] BYREF

  memset(&v97, 0, 14);
  v2 = this;
  *(_WORD *)&v97.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v97);
  memset(&v94, 0, 14);
  *(_WORD *)&v94.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v94);
  memset(&v93, 0, 14);
  *(_WORD *)&v93.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v93);
  list = nullptr;
  size = 0;
  *(_WORD *)&v91.memTag = 1280;
  memset(&v91, 0, 14);
  memset(&v96, 0, 14);
  *(_WORD *)&v96.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v96);
  memset(&v92, 0, 14);
  *(_WORD *)&v92.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v92);
  memset(&v95, 0, 14);
  *(_WORD *)&v95.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v95);
  *(_WORD *)&v89.memTag = 1280;
  memset(&v89, 0, 14);
  if ( obj == nullptr || obj->meshes.num < 1 )
  {
    idList<idRawSurface,5>::~idList<idRawSurface,5>(this: &v89);
    idList<idThread *,58>::Clear(this: &v95);
    idList<idThread *,58>::Clear(this: &v92);
    idList<idThread *,58>::Clear(this: &v96);
    idList<idStr,99>::~idList<idStr,99>(this: &v91);
    idList<idThread *,58>::Clear(this: &v93);
    idList<idThread *,58>::Clear(this: &v94);
    idList<idThread *,58>::Clear(this: &v97);
    return false;
  }
  v103.len = 0;
  v103.baseBuffer[0] = 0;
  v103.allocedAndFlag = 20;
  v103.data = v103.baseBuffer;
  v104 = false;
  v105 = false;
  v106 = false;
  idStr::operator=(this: &v103, text: v2->name.str);
  std::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const,idMaterial const *>>,0>>::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const,idMaterial const *>>,0>>(
    this: &v102,
    _Parg: (const std::less<idStr> *)v90,
    _Al: v90);
  v7 = 0;
  if ( obj->materials.num > 0 )
  {
    v8 = 0;
    do
    {
      idStr::idStr(this: &v107.loadedFile, text: &v103);
      v9 = &obj->materials.list[v8];
      v107.scaleKd = v105;
      v107.scaleKs = v106;
      v107.flipV = v104;
      v10 = DeclMaterialForParsedMtl(mtl: v9, mtlOptions: &v107);
      ++v7;
      *std::map<idStr,idMaterial const *>::operator[](
         this: (std::map<idStr,idMaterial const *> *)&v102,
         _Keyval: &obj->materials.list[v8++].mtlName) = v10;
    }
    while ( v7 < obj->materials.num );
  }
  num = obj->meshes.num;
  if ( num <= 0
    || (v12 = idList<idStr,3>::Resize(this: &v91, newsize: obj->meshes.num), list = v91.list, size = v91.size, v12) )
  {
    v91.num = num;
    if ( num >= size )
      v91.num = size;
  }
  v13 = 0;
  if ( obj->meshes.num > 0 )
  {
    v14 = 0;
    v15 = list;
    do
    {
      if ( obj->mrgb.num <= 0 )
      {
        v17 = std::map<idStr,idMaterial const *>::operator[](
                this: (std::map<idStr,idMaterial const *> *)&v102,
                _Keyval: &obj->meshes.list[v14].materialName);
        if ( *v17 != nullptr )
          str = (*v17)->name.str;
        else
          str = "greyAutoMaterial";
      }
      else
      {
        str = "zbrush";
      }
      idStr::operator=(this: v15, text: str);
      ++v13;
      ++v14;
      ++v15;
    }
    while ( v13 < obj->meshes.num );
  }
  if ( (unsigned __int8)ValidateMaterialNames(modelName: v2->name.str, strings: &v91) == 0 )
  {
    std::_Tree<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const,idMaterial const *>>,0>>::~_Tree<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const,idMaterial const *>>,0>>(
      this: (std::_Tree<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > *)&v102,
      a2: v24,
      a3: v23,
      a4: v22,
      a5: v21,
      a6: v20,
      a7: v19,
      a8: v18);
    idStr::FreeData(this: &v103);
    if ( v89.listStatic == 0 || v89.listStatic == 2 )
    {
      if ( v89.list != nullptr )
        idListArrayDelete<idRawSurface>(ptr: v89.list, num: v89.size);
      v89.list = nullptr;
      v89.size = 0;
    }
    v89.num = 0;
    if ( (v95.listStatic == 0 || v95.listStatic == 2) && v95.list != nullptr )
      idMem::Free(this: &mem, ptr: v95.list, align: ALIGN_16);
    if ( (v92.listStatic == 0 || v92.listStatic == 2) && v92.list != nullptr )
      idMem::Free(this: &mem, ptr: v92.list, align: ALIGN_16);
    if ( (v96.listStatic == 0 || v96.listStatic == 2) && v96.list != nullptr )
      idMem::Free(this: &mem, ptr: v96.list, align: ALIGN_16);
    if ( (v91.listStatic == 0 || v91.listStatic == 2) && list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: size);
    if ( (v93.listStatic == 0 || v93.listStatic == 2) && v93.list != nullptr )
      idMem::Free(this: &mem, ptr: v93.list, align: ALIGN_16);
    if ( (v94.listStatic == 0 || v94.listStatic == 2) && v94.list != nullptr )
      idMem::Free(this: &mem, ptr: v94.list, align: ALIGN_16);
    if ( (v97.listStatic == 0 || v97.listStatic == 2) && v97.list != nullptr )
      idMem::Free(this: &mem, ptr: v97.list, align: ALIGN_16);
    return false;
  }
  idStaticModel::BuildMergeList(
    this: v2,
    materialNames: &v91,
    materials: (idList<idSpawnArea::GeneratedPosition *,5> *)&v96,
    mergeTo: (idList<idSpawnArea::GeneratedPosition *,5> *)&v93,
    uniqueMaterials: (idList<idSpawnArea::GeneratedPosition *,5> *)&v92,
    uniqueMaterialNums: (idList<idSpawnArea::GeneratedPosition *,5> *)&v95);
  if ( v2->pristine )
    valueFloat = 0.0;
  else
    valueFloat = r_slopVertex.valueFloat;
  BuildRemapTable(remap: (idList<idSpawnArea::GeneratedPosition *,5> *)&v97, vecs: &obj->v, epsilon: valueFloat);
  if ( v2->pristine )
    v26 = 0.0;
  else
    v26 = r_slopTexCoord.valueFloat;
  BuildRemapTable_0(remap: (idList<idSpawnArea::GeneratedPosition *,5> *)&v94, vecs: &obj->vt, epsilon: v26);
  *(_WORD *)&v101.memTag = 1280;
  memset(&v101, 0, 14);
  v27 = v92.num;
  v28 = v89.size;
  v29 = (float)((float)1.0 - r_slopNormal.valueFloat);
  if ( v92.num > v89.size )
  {
    if ( (unsigned __int8)idList<idRawSurface,5>::Resize(this: &v89, newsize: v92.num) == 0 )
      goto LABEL_65;
    v28 = v89.size;
  }
  v89.num = v27;
  if ( v27 >= v28 )
    v89.num = v28;
LABEL_65:
  v30 = v92.list;
  v31 = v95.list;
  if ( v27 > 0 )
  {
    v32 = 0;
    v33 = (int *)v95.list;
    v34 = (char *)v92.list - (char *)v95.list;
    do
    {
      v35 = *(int *)((char *)v33 + v34);
      *(_DWORD *)&v88.comp.std::binary_function<idStr,idStr,bool> = &v89.list[v32];
      **(_DWORD **)&v88.comp.std::binary_function<idStr,idStr,bool> = v35;
      v89.list[v32].materialNum = *v33;
      idRawSurface::InitHash(this: &v89.list[v32], vList: &obj->v, tvList: &obj->vt, morphList: &v101);
      --v27;
      ++v33;
      v89.list[v32].generateNormals = false;
      v89.list[v32++].normalEpsilon = v29;
    }
    while ( v27 != 0 );
  }
  v36 = v97.list;
  v37 = 0;
  v38 = v93.list;
  v39 = v96.list;
  if ( obj->meshes.num <= 0 )
  {
LABEL_108:
    EmitRawSurfacesToStaticModel(rawSurfaces: &v89, model: v2);
    if ( v101.listStatic == 0 || v101.listStatic == 2 )
    {
      if ( v101.list != nullptr )
        idMem::Free(this: &mem, ptr: v101.list, align: ALIGN_16);
      v101.list = nullptr;
      v101.size = 0;
    }
    v101.num = 0;
    *(_DWORD *)&v88.comp.std::binary_function<idStr,idStr,bool> = v102._Myhead;
    std::_Tree<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const,idMaterial const *>>,0>>::erase(
      this: &v88,
      result: (std::_Tree<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > *)&v102,
      _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > > *)v102._Myhead->_Left,
      _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > > *)v102._Myhead,
      a5: v70,
      a6: v69,
      a7: v68,
      a8: v67,
      a9: v80,
      a10: v81,
      a11: v82,
      a12: v83,
      a13: v84,
      a14: v85,
      a15: v86,
      a16: v87);
    idMem::Free(this: &mem, ptr: v102._Myhead, align: ALIGN_16);
    idStr::FreeData(this: &v103);
    if ( v89.listStatic == 0 || v89.listStatic == 2 )
    {
      v71 = v89.list;
      if ( v89.list != nullptr )
      {
        v72 = v89.size;
        v73 = v89.list;
        if ( v89.size > 0 )
        {
          do
          {
            idRawSurface::~idRawSurface(this: v71);
            --v72;
            ++v71;
          }
          while ( v72 != 0 );
        }
        idMem::Free(this: &mem, ptr: v73, align: ALIGN_16);
      }
      v89.list = nullptr;
      v89.size = 0;
    }
    v89.num = 0;
    if ( (v95.listStatic == 0 || v95.listStatic == 2) && v31 != nullptr )
      idMem::Free(this: &mem, ptr: v31, align: ALIGN_16);
    if ( (v92.listStatic == 0 || v92.listStatic == 2) && v30 != nullptr )
      idMem::Free(this: &mem, ptr: v30, align: ALIGN_16);
    if ( (v96.listStatic == 0 || v96.listStatic == 2) && v39 != nullptr )
      idMem::Free(this: &mem, ptr: v39, align: ALIGN_16);
    if ( (v91.listStatic == 0 || v91.listStatic == 2) && list != nullptr )
    {
      v74 = v91.size;
      if ( v91.size > 0 )
      {
        v75 = list;
        do
        {
          idStr::FreeData(this: v75);
          --v74;
          ++v75;
        }
        while ( v74 != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    if ( (v93.listStatic == 0 || v93.listStatic == 2) && v38 != nullptr )
      idMem::Free(this: &mem, ptr: v38, align: ALIGN_16);
    if ( (v94.listStatic == 0 || v94.listStatic == 2) && v94.list != nullptr )
      idMem::Free(this: &mem, ptr: v94.list, align: ALIGN_16);
    if ( (v97.listStatic == 0 || v97.listStatic == 2) && v36 != nullptr )
      idMem::Free(this: &mem, ptr: v36, align: ALIGN_16);
    return true;
  }
  else
  {
    v40 = 0;
    while ( 1 )
    {
      v41 = *v38;
      v42 = &obj->meshes.list[v40];
      hasNormals = v42->hasNormals;
      v44 = idMaterial::MaterialForcesNormalSmoothing(this: (idMaterial *)v39[(_DWORD)*v38]);
      *(_WORD *)&v100.memTag = 1280;
      v45 = v44 - 1;
      memset(&v100, 0, 14);
      v46 = v45 & hasNormals;
      if ( (v45 & hasNormals) == 0 )
      {
        *(_WORD *)&v99.memTag = 1280;
        memset(&v99, 0, 14);
        v47 = 0;
        if ( v42->f.num > 0 )
        {
          v48 = 0;
          do
          {
            v49 = 3;
            v50 = &v42->f.list[v48 - 1].vn[2];
            do
            {
              *(_DWORD *)&v88.comp.std::binary_function<idStr,idStr,bool> = *++v50 - 1;
              idList<idAnimWebBlendTree *,5>::Append(this: &v99, obj: (const encounterGroupRole_t *)&v88);
              --v49;
            }
            while ( v49 != 0 );
            ++v47;
            ++v48;
          }
          while ( v47 < v42->f.num );
        }
        if ( !BuildAveragedSurfaceNormals(
                verts: &obj->v,
                indexes: (const idList<int,5> *)&v99,
                averagedSurfaceNormals: &v100) )
        {
          idLib::Error(fmt: "BuildAveragedSurfaceNormals failed in file %s", this->name.str);
_LN757:
          idLib::Error(fmt: "ConvertOBJToModelSurfaces: bad tex coord index in file %s", this->name.str);
_LN758:
          idLib::Error(fmt: "ConvertOBJToModelSurfaces: out of range normal in file %s", this->name.str);
          goto _LN759;
        }
        if ( v99.listStatic == 0 || v99.listStatic == 2 )
        {
          if ( v99.list != nullptr )
            idMem::Free(this: &mem, ptr: v99.list, align: ALIGN_16);
          v99.list = nullptr;
          v99.size = 0;
        }
        v99.num = 0;
      }
      v98.y = 0.0;
      v98.z = 0.0;
      v98.x = 0.0;
      v51 = nullptr;
      v52 = 0;
      v88._Myhead = (std::_Tree_nod<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> >::_Node *)-1;
      if ( v42->f.num > 0 )
        break;
LABEL_101:
      if ( v100.listStatic == 0 || v100.listStatic == 2 )
      {
        if ( v100.list != nullptr )
          idMem::Free(this: &mem, ptr: v100.list, align: ALIGN_16);
        v100.list = nullptr;
        v100.size = 0;
      }
      v66 = obj->meshes.num;
      ++v37;
      ++v40;
      v100.num = 0;
      ++v38;
      if ( v37 >= v66 )
      {
        v31 = v95.list;
        v30 = v92.list;
        list = v91.list;
        v38 = v93.list;
        v2 = this;
        goto LABEL_108;
      }
    }
    v53 = 0;
LABEL_85:
    v54 = 0;
    while ( 1 )
    {
      v55 = v42->f.list;
      v56 = v53 * 9 + v54;
      v57 = v55->v[v56];
      v58 = v57 - 1;
      if ( v57 - 1 < 0 || v58 >= obj->v.num )
        break;
      v59 = (int)v36[v58];
      if ( v42->hasTexCoords )
      {
        v60 = v55[v53].vt[v54] - 1;
        if ( v60 < 0 || v60 >= obj->vt.num )
          goto _LN757;
        v51 = v94.list[v60];
      }
      if ( v46 != 0 )
      {
        v61 = v55[v53].vn[v54] - 1;
        if ( v61 < 0 || v61 >= obj->vn.num )
          goto _LN758;
        v62 = &obj->vn.list[v61];
        v98.x = v62->x;
        v98.y = v62->y;
        z = v62->z;
      }
      else
      {
        v64 = &v100.list[v57];
        v98.x = v64[-1].x;
        v98.y = v64[-1].y;
        z = v64[-1].z;
      }
      v65 = obj->mrgb.num;
      v98.z = z;
      if ( v65 != 0 )
      {
        *(mrgb_t *)&v88.comp.std::binary_function<idStr,idStr,bool> = obj->mrgb.list[v42->f.list->v[v56] - 1];
        *(_WORD *)((char *)&v88._Myhead + 1) = *((_WORD *)&v88.std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0>
                                               + 1);
        LOBYTE(v88._Myhead) = v88.comp.std::binary_function<idStr,idStr,bool>;
        HIBYTE(v88._Myhead) = *((_BYTE *)&v88.std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0>
                              + 1);
      }
      idRawSurface::AddVert(
        this: &v89.list[(_DWORD)v41],
        v: v59,
        tv: (int)v51,
        normal: &v98,
        color: (unsigned int)v88._Myhead,
        morph: 0);
      if ( ++v54 >= 3 )
      {
        ++v52;
        ++v53;
        if ( v52 < v42->f.num )
          goto LABEL_85;
        goto LABEL_101;
      }
    }
_LN759:
    idLib::Error(fmt: "ConvertOBJToModelSurfaces: bad vertex index in file %s", this->name.str);
    return _LN760(a1: v79, a2: v78, a3: v77, a4: v76);
  }
}


// ========================================================================
// $LN760
// EA  : 0x82874064
// RVA : 0x00874064
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _LN760()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 224));
}


// ========================================================================
// __unwind$248641
// EA  : 0x8287408C
// RVA : 0x0087408C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_248641()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 176));
}


// ========================================================================
// __unwind$248642
// EA  : 0x828740B4
// RVA : 0x008740B4
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_248642()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 160));
}


// ========================================================================
// __unwind$248643
// EA  : 0x828740DC
// RVA : 0x008740DC
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_248643()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 576 + 128));
}


// ========================================================================
// __unwind$248644
// EA  : 0x82874104
// RVA : 0x00874104
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_248644()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 208));
}


// ========================================================================
// __unwind$248645
// EA  : 0x8287412C
// RVA : 0x0087412C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_248645()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 144));
}


// ========================================================================
// __unwind$248646
// EA  : 0x82874154
// RVA : 0x00874154
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_248646()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 192));
}


// ========================================================================
// __unwind$248647
// EA  : 0x8287417C
// RVA : 0x0087417C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_248647()
{
  int v0; // r12

  idList<idRawSurface,5>::~idList<idRawSurface,5>(this: (idList<idRawSurface,5> *)(v0 - 576 + 96));
}


// ========================================================================
// __unwind$248648
// EA  : 0x828741A4
// RVA : 0x008741A4
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_248648()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 320));
}


// ========================================================================
// __unwind$248649
// EA  : 0x828741CC
// RVA : 0x008741CC
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall _unwind_248649(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r12

  std::map<idStr,idMaterial const *>::~map<idStr,idMaterial const *>(
    this: (std::map<idStr,idMaterial const *> *)(v8 - 576 + 304),
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8);
}


// ========================================================================
// __unwind$248651
// EA  : 0x828741F4
// RVA : 0x008741F4
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_248651()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 288));
}


// ========================================================================
// __unwind$248652
// EA  : 0x8287421C
// RVA : 0x0087421C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_248652()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 272));
}


// ========================================================================
// __unwind$248653
// EA  : 0x82874244
// RVA : 0x00874244
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_248653()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 576 + 256));
}


// ========================================================================
// __unwind$249552
// EA  : 0x8287426C
// RVA : 0x0087426C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_249552()
{
  int v0; // r12

  std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::~_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>(this: (std::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > *)(v0 - 576 + 304));
}


// ========================================================================
// ?GenerateStaticModel@idStaticModel@@QAA_NQBD@Z
// EA  : 0x828742A0
// RVA : 0x008742A0
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

int __fastcall idStaticModel::GenerateStaticModel(idStaticModel *this, const char *sourceFile)
{
  int v4; // r29
  char v5; // r30
  bool pristine; // r25
  idASEModel *v7; // r3
  idASEModel *v8; // r28
  int v9; // r9
  int v10; // r10
  int v11; // r11
  idASEObject *v12; // r8
  unsigned int *v13; // r4
  st_lwObject *Object; // r3
  st_lwObject *v15; // r28
  double valueFloat; // fp2
  double v17; // fp1
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  idOBJModel *v21; // r3
  idOBJModel *v22; // r28
  int v23; // r8
  int v24; // r10
  int v25; // r11
  idOBJMesh *list; // r9
  int i; // r28
  idTriangles *geometry; // r30
  int v30; // r10
  int v31; // r9
  int v32; // r8
  int v33; // r7
  int v34; // r6
  int v35; // r5
  int v36; // r4
  int v37; // [sp+8h] [-E8h]
  int v38; // [sp+Ch] [-E4h]
  int v39; // [sp+10h] [-E0h]
  idStaticModel *v40; // [sp+14h] [-DCh]
  int v41; // [sp+18h] [-D8h]
  int v42; // [sp+1Ch] [-D4h]
  int num; // [sp+50h] [-A0h]
  int v44[3]; // [sp+54h] [-9Ch] BYREF
  idStr v45; // [sp+60h] [-90h] BYREF
  idStr v46; // [sp+80h] [-70h] BYREF

  idStr::idStr(this: &v46, text: sourceFile);
  v4 = 0;
  v45.len = 0;
  v45.baseBuffer[0] = 0;
  v45.allocedAndFlag = 20;
  v45.data = v45.baseBuffer;
  idStr::ExtractFileExtension(this: &v46, dest: &v45);
  v5 = 0;
  pristine = this->pristine;
  this->sourceTimeStamp = fileSystem->GetTimestamp(this: fileSystem, a2: sourceFile, a3: false);
  if ( idStr::Icmp(s1: v45.data, s2: "ase") != 0 )
  {
    if ( idStr::Icmp(s1: v45.data, s2: "lwo") != 0 )
    {
      if ( idStr::Icmp(s1: v45.data, s2: "obj") != 0 )
      {
        HIDWORD(v20) = sourceFile;
        idResource::SetResourceError(
          this,
          fmt: "Unknown model type for StaticModel '%s'",
          a3: v20,
          a4: v19,
          a5: v18,
          a6: v37,
          a7: v38,
          a8: v39,
          a9: (int)v40,
          a10: v41,
          a11: v42);
        v5 = 0;
      }
      else
      {
        v21 = OBJ_Load(fileName: sourceFile);
        v22 = v21;
        if ( v21 != nullptr )
        {
          v23 = 0;
          v24 = 0;
          v44[0] = v21->meshes.num;
          if ( v44[0] > 0 )
          {
            v25 = 0;
            list = v21->meshes.list;
            do
            {
              ++v24;
              ++v25;
              v23 += list->f.num;
              list = &v21->meshes.list[v25];
            }
            while ( v24 < v44[0] );
            if ( v23 >= 100000 )
              this->pristine = true;
          }
          v5 = idStaticModel::ConvertOBJToModelSurfaces(this, obj: v21);
          idOBJModel::~idOBJModel(this: v22);
          idMem::Free(this: &mem, ptr: v22, align: ALIGN_16);
        }
      }
    }
    else
    {
      Object = lwGetObject(filename: sourceFile, forceSmooth: 0.0, failID: v13, failpos: v44);
      v15 = Object;
      if ( Object != nullptr )
      {
        if ( Object->layer->polygon.count >= 100000 )
          this->pristine = true;
        if ( this->pristine )
          valueFloat = 0.0;
        else
          valueFloat = r_slopTexCoord.valueFloat;
        if ( this->pristine )
          v17 = 0.0;
        else
          v17 = r_slopVertex.valueFloat;
        v5 = idStaticModel::ConvertLWOToModelSurfaces(
               this,
               lwo: Object,
               layer: Object->layer,
               vertexSlop: v17,
               texCoordSlop: valueFloat);
        lwFreeObject(object: v15);
      }
    }
  }
  else
  {
    v7 = ASE_Load(fileName: sourceFile);
    v8 = v7;
    if ( v7 != nullptr )
    {
      v9 = 0;
      v10 = 0;
      num = v7->objects.num;
      if ( num > 0 )
      {
        v11 = 0;
        do
        {
          v12 = v7->objects.list[v11];
          ++v10;
          ++v11;
          v9 += v12->mesh.numFaces;
        }
        while ( v10 < num );
        if ( v9 >= 100000 )
          this->pristine = true;
      }
      v5 = idStaticModel::ConvertASEToModelSurfaces(this, ase: v7);
      ASE_Free(aseModel: v8);
    }
  }
  if ( v5 != 0 )
  {
    for ( i = 0; i < this->surfaces.num; ++v4 )
    {
      geometry = this->surfaces.list[v4].geometry;
      idTriangles::RangeCheckIndexes(
        indexes: geometry->indexes,
        numIndexes: geometry->numIndexes,
        numVerts: geometry->numVerts);
      idTriangles::RemoveDegenerate(this: geometry);
      if ( !this->pristine )
      {
        idTriangles::OptimizeIndexOrder(this: geometry);
        idTriangles::OptimizeVertexOrder(this: geometry);
      }
      ++i;
    }
    idStaticModel::FinishStaticModel(this, cleanup: false);
    idStaticModel::BuildAutospriteData(
      this,
      a2: v36,
      a3: v35,
      a4: v34,
      a5: v33,
      a6: v32,
      a7: v31,
      a8: v30,
      a9: v37,
      a10: v38,
      a11: v39,
      a12: v40);
    if ( this->pristine )
    {
      if ( !pristine )
        idLib::Warning(fmt: "Model '%s' is loaded in pristine mode, it will look flaky if used in the game", sourceFile);
    }
    else
    {
      idStaticModel::MergeSurfacesAndBuildSourceSurfaces(this);
      idStaticModel::ConvertToTriStrips(this);
    }
    idStr::FreeData(this: &v45);
    idStr::FreeData(this: &v46);
    return 1;
  }
  else
  {
    idStr::FreeData(this: &v45);
    idStr::FreeData(this: &v46);
    return 0;
  }
}


// ========================================================================
// __unwind$250323
// EA  : 0x82874634
// RVA : 0x00874634
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250323()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$250324
// EA  : 0x8287465C
// RVA : 0x0087465C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250324()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// ?GenerateBinaryModelFile@idStaticModel@@AAA_NQBD0@Z
// EA  : 0x82874690
// RVA : 0x00874690
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

int __fastcall idStaticModel::GenerateBinaryModelFile(
        idStaticModel *this,
        const char *sourceFile,
        const char *const binaryFile)
{
  int v5; // r10
  int v6; // r9
  int v7; // r8
  int v9; // [sp+8h] [-208h]
  int v10; // [sp+Ch] [-204h]
  int v11; // [sp+10h] [-200h]
  int v12; // [sp+14h] [-1FCh]
  int v13; // [sp+18h] [-1F8h]
  unsigned int v14; // [sp+1Ch] [-1F4h]
  idStaticModel v15; // [sp+50h] [-1C0h] BYREF

  idStaticModel::idStaticModel(this: &v15);
  v15.pristine = this->pristine;
  v5 = (unsigned __int8)idStaticModel::GenerateStaticModel(this: &v15, sourceFile);
  if ( v5 != 0 )
  {
    idStaticModel::WriteStaticBModel(
      filename: this->binaryFileName,
      timestamp: v15.sourceTimeStamp,
      surfaces: (const idList<idStaticModelSurface,5> *)&v15.surfaces,
      sourceSurfaces: &v15.sourceSurfaces,
      basePath: FSPATH_BASE,
      a6: v7,
      a7: v6,
      a8: v5,
      a9: v9,
      a10: v10,
      a11: v11,
      a12: v12,
      a13: v13,
      a14: v14);
    idStaticModel::~idStaticModel(this: &v15);
    return 1;
  }
  else
  {
    idStaticModel::~idStaticModel(this: &v15);
    return 0;
  }
}


// ========================================================================
// __unwind$250441
// EA  : 0x8287470C
// RVA : 0x0087470C
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250441()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 528 + 80));
}


// ========================================================================
// ?ConvertModelFile_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82874740
// RVA : 0x00874740
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __fastcall ConvertModelFile_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v3; // r4
  const char *v4; // r4
  char v5; // r30
  unsigned int *v6; // r4
  st_lwObject *Object; // r23
  const st_lwLayer *layer; // r27
  int v9; // r21
  const char *name; // r4
  int i; // r28
  int v12; // r29
  int v13; // r30
  char v14; // r11
  idStr v15; // [sp+50h] [-560h] BYREF
  idStr v16; // [sp+70h] [-540h] BYREF
  int v17; // [sp+90h] [-520h]
  idStr v18; // [sp+A0h] [-510h] BYREF
  idStr v19; // [sp+C0h] [-4F0h] BYREF
  idStr v20; // [sp+E0h] [-4D0h] BYREF
  int v21[4]; // [sp+100h] [-4B0h] BYREF
  idStr v22; // [sp+110h] [-4A0h] BYREF
  idStr v23; // [sp+130h] [-480h] BYREF
  idOBJModel v24; // [sp+150h] [-460h] BYREF
  idOBJModel v25; // [sp+1B0h] [-400h] BYREF
  idStaticModel v26; // [sp+210h] [-3A0h] BYREF
  idStaticModel v27; // [sp+3B0h] [-200h] BYREF

  argc = args->argc;
  v17 = args->argc;
  if ( v17 == 3 )
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    idStr::idStr(this: &v19, text: v3);
    v15.len = 0;
    v15.allocedAndFlag = 20;
    v15.data = v15.baseBuffer;
    v15.baseBuffer[0] = 0;
    idStr::MakeNameCanonical(this: &v19);
    idStr::ExtractFileExtension(this: &v19, dest: &v15);
    if ( args->argc <= 2 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[2];
    idStr::idStr(this: &v18, text: v4);
    v16.allocedAndFlag = 20;
    v16.data = v16.baseBuffer;
    v16.len = 0;
    v16.baseBuffer[0] = 0;
    idStr::MakeNameCanonical(this: &v18);
    idStr::ExtractFileExtension(this: &v18, dest: &v16);
    v5 = 0;
    if ( idStr::Cmp(s1: v15.data, s2: "lwo") != 0
      && idStr::Cmp(s1: v15.data, s2: "ase") != 0
      && idStr::Cmp(s1: v15.data, s2: "obj") != 0 )
    {
      idLib::Printf(fmt: "ConvertModelFile - Invalid input file extension: \"%s\"", v15.data);
      v5 = 1;
    }
    if ( idStr::Cmp(s1: v16.data, s2: "obj") != 0 )
    {
      idLib::Printf(fmt: "ConvertModelFile - Invalid output file extension: \"%s\"", v16.data);
      v5 = 1;
    }
    if ( v5 != 0 )
    {
      idStr::FreeData(this: &v16);
      idStr::FreeData(this: &v18);
      idStr::FreeData(this: &v15);
    }
    else if ( idStr::Cmp(s1: v15.data, s2: "lwo") != 0 )
    {
      idStaticModel::idStaticModel(this: &v27);
      if ( (unsigned __int8)idStaticModel::GenerateStaticModel(this: &v27, sourceFile: v19.data) != 0 )
      {
        idOBJModel::idOBJModel(this: &v25);
        if ( idStaticModel::ConvertToOBJ(this: &v27, groupName: "defaultGroup", destOBJ: &v25) )
        {
          if ( !idOBJModel::Save(this: &v25, fileName: v18.data) )
            idLib::Printf(fmt: "ConvertModelFile - Failed to save output file: \"%s\"", v18.data);
          idOBJModel::~idOBJModel(this: &v25);
          idStaticModel::~idStaticModel(this: &v27);
          idStr::FreeData(this: &v16);
          idStr::FreeData(this: &v18);
          idStr::FreeData(this: &v15);
        }
        else
        {
          idLib::Printf(fmt: "ConvertModelFile - Failed to convert the model");
          idOBJModel::~idOBJModel(this: &v25);
          idStaticModel::~idStaticModel(this: &v27);
          idStr::FreeData(this: &v16);
          idStr::FreeData(this: &v18);
          idStr::FreeData(this: &v15);
        }
      }
      else
      {
        idLib::Printf(fmt: "ConvertModelFile - Failed to load input file: \"%s\"", v19.data);
        idStaticModel::~idStaticModel(this: &v27);
        idStr::FreeData(this: &v16);
        idStr::FreeData(this: &v18);
        idStr::FreeData(this: &v15);
      }
    }
    else
    {
      Object = lwGetObject(filename: v19.data, forceSmooth: 0.0, failID: v6, failpos: v21);
      if ( Object != nullptr )
      {
        idOBJModel::idOBJModel(this: &v24);
        layer = Object->layer;
        v9 = 0;
        if ( layer != nullptr )
        {
          while ( 1 )
          {
            idStaticModel::idStaticModel(this: &v26);
            name = layer->name;
            if ( name == nullptr )
              name = "layer";
            idStr::idStr(this: &v23, text: name);
            MakeStringValidForMaya(result: &v22, str: &v23);
            idStr::idStr(this: &v20, text: &v22);
            for ( i = 1; ; idStr::Format(this: &v20, fmt: "%s_%i", v22.data, i) )
            {
              v12 = 0;
              if ( v24.meshes.num <= 0 )
              {
LABEL_28:
                v14 = 0;
              }
              else
              {
                v13 = 0;
                while ( idStr::Cmp(s1: v20.data, s2: v24.meshes.list[v13].groupName.data) != 0 )
                {
                  ++v12;
                  ++v13;
                  if ( v12 >= v24.meshes.num )
                    goto LABEL_28;
                }
                v14 = 1;
              }
              if ( v14 == 0 )
                break;
              ++i;
            }
            idLib::Printf(fmt: "groupName: %s\n", v20.data);
            if ( (unsigned __int8)idStaticModel::ConvertLWOToModelSurfaces(
                                    this: &v26,
                                    lwo: Object,
                                    layer,
                                    vertexSlop: 0.0,
                                    texCoordSlop: 0.0) == 0 )
            {
              idLib::Printf(fmt: "ConvertModelFile - Failed to convert layer");
              lwFreeObject(object: Object);
              idStr::FreeData(this: &v20);
              idStr::FreeData(this: &v22);
              idStr::FreeData(this: &v23);
              idStaticModel::~idStaticModel(this: &v26);
              idOBJModel::~idOBJModel(this: &v24);
              idStr::FreeData(this: &v16);
              idStr::FreeData(this: &v18);
              idStr::FreeData(this: &v15);
              goto LABEL_47;
            }
            if ( !idStaticModel::ConvertToOBJ(this: &v26, groupName: v20.data, destOBJ: &v24) )
              break;
            idStr::FreeData(this: &v20);
            idStr::FreeData(this: &v22);
            idStr::FreeData(this: &v23);
            idStaticModel::~idStaticModel(this: &v26);
            ++v9;
            layer = layer->next;
            if ( layer == nullptr )
              goto LABEL_35;
          }
          idLib::Printf(fmt: "ConvertModelFile - Failed to convert the model");
          lwFreeObject(object: Object);
          idStr::FreeData(this: &v20);
          idStr::FreeData(this: &v22);
          idStr::FreeData(this: &v23);
          idStaticModel::~idStaticModel(this: &v26);
          idOBJModel::~idOBJModel(this: &v24);
          idStr::FreeData(this: &v16);
          idStr::FreeData(this: &v18);
          idStr::FreeData(this: &v15);
        }
        else
        {
LABEL_35:
          idLib::Printf(fmt: "%i layers in input LWO file\n", v9);
          idLib::Printf(fmt: "%i meshes in output OBJ file\n", v24.meshes.num);
          lwFreeObject(object: Object);
          if ( !idOBJModel::Save(this: &v24, fileName: v18.data) )
            idLib::Printf(fmt: "ConvertModelFile - Failed to save output file: \"%s\"", v18.data);
          idOBJModel::~idOBJModel(this: &v24);
          idStr::FreeData(this: &v16);
          idStr::FreeData(this: &v18);
          idStr::FreeData(this: &v15);
        }
      }
      else
      {
        idLib::Printf(fmt: "ConvertModelFile - Failed to load input file: \"%s\"", v19.data);
        idStr::FreeData(this: &v16);
        idStr::FreeData(this: &v18);
        idStr::FreeData(this: &v15);
      }
    }
LABEL_47:
    idStr::FreeData(this: &v19);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: ConvertModelFile <inputModelName> <outputModelName>\n");
  }
}


// ========================================================================
// __unwind$250464
// EA  : 0x82874CD0
// RVA : 0x00874CD0
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250464()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1456 + 192));
}


// ========================================================================
// __unwind$250465
// EA  : 0x82874CF8
// RVA : 0x00874CF8
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250465()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1456 + 80));
}


// ========================================================================
// __unwind$250466
// EA  : 0x82874D20
// RVA : 0x00874D20
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250466()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1456 + 160));
}


// ========================================================================
// __unwind$250467
// EA  : 0x82874D48
// RVA : 0x00874D48
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250467()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1456 + 112));
}


// ========================================================================
// __unwind$250468_0
// EA  : 0x82874D70
// RVA : 0x00874D70
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250468_0()
{
  int v0; // r12

  idOBJModel::~idOBJModel(this: (idOBJModel *)(v0 - 1456 + 336));
}


// ========================================================================
// __unwind$250469_0
// EA  : 0x82874D98
// RVA : 0x00874D98
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250469_0()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 1456 + 528));
}


// ========================================================================
// __unwind$250470_0
// EA  : 0x82874DC0
// RVA : 0x00874DC0
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250470_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1456 + 304));
}


// ========================================================================
// __unwind$250471_0
// EA  : 0x82874DE8
// RVA : 0x00874DE8
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250471_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1456 + 272));
}


// ========================================================================
// __unwind$250472_0
// EA  : 0x82874E10
// RVA : 0x00874E10
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250472_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1456 + 224));
}


// ========================================================================
// __unwind$250473_0
// EA  : 0x82874E38
// RVA : 0x00874E38
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250473_0()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 1456 + 944));
}


// ========================================================================
// __unwind$250474_0
// EA  : 0x82874E60
// RVA : 0x00874E60
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void _unwind_250474_0()
{
  int v0; // r12

  idOBJModel::~idOBJModel(this: (idOBJModel *)(v0 - 1456 + 432));
}


// ========================================================================
// `dynamic initializer for 'r_slopVertex''
// EA  : 0x83344D40
// RVA : 0x01344D40
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_slopVertex__()
{
  idCVar::idCVar(
    this: &r_slopVertex,
    name: "r_slopVertex",
    value: "0.01",
    flags: 0,
    description: "merge xyz coordinates this far apart",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_slopVertex__);
}


// ========================================================================
// `dynamic initializer for 'r_slopTexCoord''
// EA  : 0x83344D98
// RVA : 0x01344D98
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_slopTexCoord__()
{
  idCVar::idCVar(
    this: &r_slopTexCoord,
    name: "r_slopTexCoord",
    value: "0.0001",
    flags: 0,
    description: "merge texture coordinates this far apart",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_slopTexCoord__);
}


// ========================================================================
// `dynamic initializer for 'r_slopNormal''
// EA  : 0x83344DF0
// RVA : 0x01344DF0
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_slopNormal__()
{
  idCVar::idCVar(
    this: &r_slopNormal,
    name: "r_slopNormal",
    value: "0.0001",
    flags: 0,
    description: "merge normals that dot less than this",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_slopNormal__);
}


// ========================================================================
// `dynamic initializer for 'r_staticModelTriStrips''
// EA  : 0x83344E48
// RVA : 0x01344E48
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_staticModelTriStrips__()
{
  idCVar::idCVar(
    this: &r_staticModelTriStrips,
    name: "r_staticModelTriStrips",
    value: "1",
    flags: 1,
    description: "build tristrips for static models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_staticModelTriStrips__);
}


// ========================================================================
// `dynamic initializer for 'r_mergeModelSurfaces''
// EA  : 0x83344EA0
// RVA : 0x01344EA0
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_mergeModelSurfaces__()
{
  idCVar::idCVar(
    this: &r_mergeModelSurfaces,
    name: "r_mergeModelSurfaces",
    value: "1",
    flags: 1,
    description: "combine model surfaces with the same material",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_mergeModelSurfaces__);
}


// ========================================================================
// `dynamic initializer for 'ConvertModelFile_v''
// EA  : 0x83344EF8
// RVA : 0x01344EF8
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ConvertModelFile_v__()
{
  return idCommandLink::idCommandLink(
           this: &ConvertModelFile_v,
           cmdName: "ConvertModelFile",
           function: ConvertModelFile_f,
           description: "Convert from one model file format to another.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestLoadAllObjModels_v''
// EA  : 0x83344F20
// RVA : 0x01344F20
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestLoadAllObjModels_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestLoadAllObjModels_v,
           cmdName: "TestLoadAllObjModels",
           function: TestLoadAllObjModels_f,
           description: "Loads every obj file in the tree to test code",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestLoadAllLwoModels_v''
// EA  : 0x83344F48
// RVA : 0x01344F48
// PDB : w:\tech5\engine\models\static\staticmodelgenerator.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestLoadAllLwoModels_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestLoadAllLwoModels_v,
           cmdName: "TestLoadAllLwoModels",
           function: TestLoadAllLwoModels_f,
           description: "Loads every lwo file in the tree to test code",
           argCompletion: nullptr);
}

