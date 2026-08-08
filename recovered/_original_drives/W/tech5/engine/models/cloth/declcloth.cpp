
// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclCloth@@@@UBAHXZ
// EA  : 0x827AB818
// RVA : 0x007AB818
// PDB : w:\tech5\engine\models\cloth\declcloth.cpp
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclCloth>::AllocSize(idDeclInfoTemplate<idDeclCloth> *this)
{
  return 172;
}


// ========================================================================
// ?DefaultDefinition@idDeclCloth@@UBAPBDXZ
// EA  : 0x827AB820
// RVA : 0x007AB820
// PDB : w:\tech5\engine\models\cloth\declcloth.cpp
// ========================================================================

const char *__fastcall idDeclCloth::DefaultDefinition(idDeclCloth *this)
{
  return "{\n\tmaterial\t_default\n\twidth\t\t12\n\theight\t\t12\n\thspacing\t12\n\tvspacing\t12\n}\n";
}


// ========================================================================
// ?FreeData@idDeclCloth@@UAAXXZ
// EA  : 0x827ABBE8
// RVA : 0x007ABBE8
// PDB : w:\tech5\engine\models\cloth\declcloth.cpp
// ========================================================================

void __fastcall idDeclCloth::FreeData(idDeclCloth *this)
{
  idDeclCloth::ropeInfo *list; // r3

  if ( this->ropeData.listStatic == 0 || this->ropeData.listStatic == 2 )
  {
    list = this->ropeData.list;
    if ( list != nullptr )
      idListArrayDelete<idDeclCloth::ropeInfo>(ptr: list, num: this->ropeData.size);
    this->ropeData.list = nullptr;
    this->ropeData.size = 0;
  }
  this->ropeData.num = 0;
}


// ========================================================================
// ??0idDeclCloth@@QAA@XZ
// EA  : 0x827ABD18
// RVA : 0x007ABD18
// PDB : w:\tech5\engine\models\cloth\declcloth.cpp
// ========================================================================

idDeclCloth *__fastcall idDeclCloth::idDeclCloth(idDeclCloth *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->vSpacing = 0.0;
  this->hSpacing = 0.0;
  this->__vftable = (idDeclCloth_vtbl *)&idDeclCloth::`vftable';
  this->gravity = -1000.0;
  this->width = 0;
  this->mass = 10.0;
  this->height = 0;
  this->friction = 0.0099999998;
  this->type = CLOTH_NONE;
  this->collisionFriction = 0.0099999998;
  this->springType = CLOTH_SPRING_BANDED;
  this->springLength = 1.0;
  this->material = nullptr;
  this->springFriction = 0.0099999998;
  this->clothMD6 = nullptr;
  this->springMaxLengthMultiplier = 2.0;
  this->clothDeclFX = nullptr;
  this->md6IsBound = false;
  this->ropeData.granularity = 0;
  this->ropeData.memTag = 5;
  this->ropeData.listStatic = 0;
  this->ropeData.list = nullptr;
  this->ropeData.size = 0;
  this->ropeData.num = 0;
  this->particleData.list = nullptr;
  this->particleData.granularity = 0;
  this->particleData.memTag = 5;
  this->particleData.listStatic = 0;
  this->particleData.size = 0;
  this->particleData.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->particleData);
  this->springData.list = nullptr;
  this->springData.granularity = 0;
  this->springData.memTag = 5;
  this->springData.listStatic = 0;
  this->springData.size = 0;
  this->springData.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->springData);
  return this;
}


// ========================================================================
// __unwind$221821
// EA  : 0x827ABE2C
// RVA : 0x007ABE2C
// PDB : w:\tech5\engine\models\cloth\declcloth.cpp
// ========================================================================

void _unwind_221821()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$221822
// EA  : 0x827ABE54
// RVA : 0x007ABE54
// PDB : w:\tech5\engine\models\cloth\declcloth.cpp
// ========================================================================

void _unwind_221822()
{
  int v0; // r12

  idList<idDeclCloth::ropeInfo,5>::~idList<idDeclCloth::ropeInfo,5>(this: (idList<idDeclCloth::ropeInfo,5> *)(*(_DWORD *)(v0 - 128 + 148) + 124));
}


// ========================================================================
// __unwind$221823_0
// EA  : 0x827ABE80
// RVA : 0x007ABE80
// PDB : w:\tech5\engine\models\cloth\declcloth.cpp
// ========================================================================

void _unwind_221823_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 140));
}


// ========================================================================
// ?Parse@idDeclCloth@@UAAXAAVidParser@@@Z
// EA  : 0x827AC1F0
// RVA : 0x007AC1F0
// PDB : w:\tech5\engine\models\cloth\declcloth.cpp
// ========================================================================

void __fastcall idDeclCloth::Parse(idDeclCloth *this, idParser *src)
{
  int v2; // r30
  int v3; // r27
  int v4; // r25
  char *v5; // r4
  const idDeclMD6 *v6; // r3
  int v7; // r3
  int v8; // r22
  idList<idDeclCloth::particleInfo_t,5> *v9; // r29
  int v10; // r11
  const idMD6Skel *v11; // r11
  int v12; // r21
  __int16 v13; // r23
  char *v14; // r28
  char *v15; // r28
  float *v16; // r11
  double v17; // fp13
  double v18; // fp12
  char *v19; // r9
  idList<idDeclCloth::springInfo_t,5> *p_springData; // r28
  int v21; // r29
  int v22; // r3
  char *v23; // r4
  const idDeclMD6 *v24; // r3
  int v25; // r3
  int width; // r4
  const idMD6Skel *v27; // r11
  int v28; // r24
  idList<idDeclCloth::particleInfo_t,5> *p_particleData; // r29
  int size; // r11
  const char *v31; // r23
  float *v32; // r11
  float *v33; // r10
  idParser *v34; // r3
  bool v35; // zf
  char *data; // r4
  const idDeclMD6 *v37; // r3
  const idMD6Model *v38; // r24
  const idMD6Skel *skeleton; // r11
  double v40; // fp30
  idDeclCloth::ropeInfo *v41; // r3
  __int64 v42; // r11
  idList<idVec3,5> *p_positions; // r29
  double v44; // fp31
  idList<idMat3,5> *p_inverseAxis; // r28
  int UnsignedIntValue; // r3
  idDeclCloth::ropeInfo *v47; // r28
  int v48; // r29
  idVec3 *v49; // r23
  float *v50; // r22
  double v51; // fp13
  double v52; // fp12
  double v53; // fp10
  double v54; // fp9
  double v55; // fp8
  double v56; // fp7
  double v57; // fp6
  double v58; // fp5
  double v59; // fp4
  double v60; // fp3
  idMD6SkelData *v61; // r11
  int v62; // r10
  _DWORD v63[4]; // [sp+50h] [-210h] BYREF
  idToken v64; // [sp+60h] [-200h] BYREF
  idDeclInfoTemplate<idDeclMD6> *v65; // [sp+A8h] [-1B8h]
  int v66; // [sp+ACh] [-1B4h] BYREF
  int v67; // [sp+B0h] [-1B0h] BYREF
  const char *v68; // [sp+B4h] [-1ACh]
  const char *v69; // [sp+B8h] [-1A8h]
  const char *v70; // [sp+BCh] [-1A4h]
  idDeclInfoTemplate<idDeclFX> *v71; // [sp+C0h] [-1A0h]
  const char *v72; // [sp+C4h] [-19Ch]
  const char *v73; // [sp+C8h] [-198h]
  const char *v74; // [sp+CCh] [-194h]
  const char *v75; // [sp+D0h] [-190h]
  const char *v76; // [sp+D4h] [-18Ch]
  const char *v77; // [sp+D8h] [-188h]
  const char *v78; // [sp+DCh] [-184h]
  const char *v79; // [sp+E0h] [-180h]
  const char *v80; // [sp+E4h] [-17Ch]
  const char *v81; // [sp+E8h] [-178h]
  idDeclInfoTemplate<idMaterial> *v82; // [sp+ECh] [-174h]
  const char *v83; // [sp+F0h] [-170h]
  const char *v84; // [sp+F4h] [-16Ch]
  idMat3 *v85; // [sp+F8h] [-168h]
  const char *v86; // [sp+FCh] [-164h]
  const idMD6Model *model; // [sp+100h] [-160h]
  const char *v88; // [sp+104h] [-15Ch]
  const char *v89; // [sp+108h] [-158h]
  const char *v90; // [sp+10Ch] [-154h]
  const char *v91; // [sp+110h] [-150h]
  const char *v92; // [sp+114h] [-14Ch]
  const char *v93; // [sp+118h] [-148h]
  idVec3 v94; // [sp+120h] [-140h] BYREF
  idMat3x4 v95; // [sp+130h] [-130h] BYREF
  __int64 v96; // [sp+160h] [-100h]
  idMat3x4 v97; // [sp+170h] [-F0h] BYREF

  v64.len = 0;
  v64.allocedAndFlag = 20;
  v64.data = v64.baseBuffer;
  v64.floatvalue = -3.4028235e38;
  v64.baseBuffer[0] = 0;
  v64.intvalue = 0;
  memset(&v64.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadToken(this: src, token: &v64) )
  {
    v67 = -2111832064;
    v66 = -2111832064;
    v85 = &mat3_identity;
    v83 = "noBind";
    v81 = "ropeModel";
    v2 = (int)&idDeclReachIK::resourceList.hashTable[243];
    v79 = "square";
    v3 = (int)&idDeclReachIK::resourceList.hashTable[243];
    v4 = (int)"mMaterial";
    v77 = "right";
    v65 = &idDeclMD6::resourceList;
    v75 = "forward";
    v69 = "anchored";
    v73 = "generic";
    v71 = &idDeclFX::resourceList;
    v84 = "clothDeclFX";
    v91 = "springMaxLengthMultiplier";
    v63[0] = -2113601536;
    v82 = &idMaterial::resourceList;
    v88 = "springLength";
    v78 = "gravity";
    v70 = "material";
    v80 = "springFriction";
    v92 = "collisionfriction";
    v76 = "friction";
    v86 = "mass";
    v74 = "cross";
    v93 = "quad";
    v72 = (const char *)-2111849172;
    v90 = (const char *)-2111849192;
    v89 = (const char *)-2113575984;
    v68 = "width";
    do
    {
      if ( idStr::Icmp(s1: v64.data, s2: "}") == 0 )
        break;
      if ( idStr::Icmp(s1: v64.data, s2: v68) != 0 )
      {
        if ( idStr::Icmp(s1: v64.data, s2: v89) != 0 )
        {
          if ( idStr::Icmp(s1: v64.data, s2: v90) != 0 )
          {
            if ( idStr::Icmp(s1: v64.data, s2: v72) != 0 )
            {
              if ( idStr::Icmp(s1: v64.data, s2: "springs") != 0 )
              {
                if ( idStr::Icmp(s1: v64.data, s2: v86) != 0 )
                {
                  if ( idStr::Icmp(s1: v64.data, s2: v76) != 0 )
                  {
                    if ( idStr::Icmp(s1: v64.data, s2: v92) != 0 )
                    {
                      if ( idStr::Icmp(s1: v64.data, s2: v78) != 0 )
                      {
                        if ( idStr::Icmp(s1: v64.data, s2: v88) != 0 )
                        {
                          if ( idStr::Icmp(s1: v64.data, s2: v80) != 0 )
                          {
                            if ( idStr::Icmp(s1: v64.data, s2: v70) != 0 )
                            {
                              if ( idStr::Icmp(s1: v64.data, s2: v91) != 0 )
                              {
                                if ( idStr::Icmp(s1: v64.data, s2: v84) != 0 )
                                {
                                  if ( idStr::Icmp(s1: v64.data, s2: v73) != 0 )
                                  {
                                    if ( idStr::Icmp(s1: v64.data, s2: v79) != 0 )
                                    {
                                      v35 = idStr::Icmp(s1: v64.data, s2: v81) != 0;
                                      v34 = src;
                                      if ( v35 )
                                        goto _LN529;
                                      this->type = CLOTH_ROPE;
                                      idParser::ExpectTokenString(this: src, string: "{");
                                      idParser::ReadToken(this: src, token: &v64);
                                      data = v64.data;
                                      if ( v64.data != nullptr )
                                      {
                                        v37 = (const idDeclMD6 *)idDeclInfo::FindWithInheritance(
                                                                   this: v65,
                                                                   name: v64.data,
                                                                   makeDefault: false);
                                        data = v64.data;
                                      }
                                      else
                                      {
                                        v37 = nullptr;
                                      }
                                      this->clothMD6 = v37;
                                      if ( v37 == nullptr )
                                        goto _LN528;
                                      model = v37->model;
                                      v38 = model;
                                      if ( model == nullptr )
                                        goto _LN528;
                                      skeleton = model->skeleton;
                                      if ( skeleton != nullptr )
                                        v4 = (int)skeleton->data + skeleton->data->inverseBasePoseOffset;
                                      else
                                        v4 = 0;
                                      if ( idParser::ReadToken(this: src, token: &v64) )
                                      {
                                        while ( idStr::Cmp(s1: v64.data, s2: "}") != 0 )
                                        {
                                          if ( idStr::Cmp(s1: v64.data, s2: v83) != 0 )
                                          {
                                            this->md6IsBound = true;
                                            idDeclMD6::GetJointIndex(
                                              this: (idDeclMD6 *)v63,
                                              result: (idIndex<short,enum invalidJointIndex_t> *)this->clothMD6,
                                              jointName: v64.data);
                                            v2 = HIWORD(v63[0]);
                                            if ( v63[0] < 0 )
                                              goto _LN525;
                                            idParser::ReadToken(this: src, token: &v64);
                                            UnsignedIntValue = idToken::GetUnsignedIntValue(this: &v64);
                                            v3 = UnsignedIntValue;
                                            if ( UnsignedIntValue < 2 || UnsignedIntValue > 100 )
                                              goto _LN527;
                                            v47 = idList<idDeclCloth::ropeInfo,5>::Alloc(this: &this->ropeData);
                                            v48 = 0;
                                            if ( v3 > 0 )
                                            {
                                              while ( (v2 & 0x8000u) == 0 )
                                              {
                                                v49 = idList<idVec3,5>::Alloc(this: &v47->positions);
                                                v50 = (float *)idList<idMat3,5>::Alloc(this: &v47->inverseAxis);
                                                v95 = *(idMat3x4 *)(48 * (__int16)v2 + v4);
                                                idMat3x4::Invert(this: &v95);
                                                v51 = v95.mat[7];
                                                v52 = v95.mat[11];
                                                v49->x = v95.mat[3];
                                                v49->y = v51;
                                                v49->z = v52;
                                                v53 = v95.mat[1];
                                                v54 = v95.mat[2];
                                                v55 = v95.mat[4];
                                                v56 = v95.mat[5];
                                                v57 = v95.mat[6];
                                                v58 = v95.mat[8];
                                                v59 = v95.mat[9];
                                                v60 = v95.mat[10];
                                                *v50 = v95.mat[0];
                                                v50[3] = v53;
                                                v50[6] = v54;
                                                v50[1] = v55;
                                                v50[4] = v56;
                                                v50[7] = v57;
                                                v50[2] = v58;
                                                v50[5] = v59;
                                                v50[8] = v60;
                                                idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
                                                  this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v47->indexOfJointToAttachTo,
                                                  obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)v63);
                                                ++v48;
                                                v61 = v38->skeleton->data;
                                                v62 = v61->parentTblOffset + 2 * (__int16)v2;
                                                v2 = *(unsigned __int16 *)((char *)&v61->size + v62);
                                                HIWORD(v63[0]) = *(unsigned __int16 *)((char *)&v61->size + v62);
                                                if ( v48 >= v3 )
                                                  goto LABEL_132;
                                              }
                                              goto _LN526;
                                            }
                                          }
                                          else
                                          {
                                            v2 = idParser::ParseInt(this: src);
                                            v40 = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                            if ( v2 < 2 || v2 > 100 )
                                              goto _LN524;
                                            v41 = idList<idDeclCloth::ropeInfo,5>::Alloc(this: &this->ropeData);
                                            LODWORD(v42) = v2;
                                            v94.x = 0.0;
                                            p_positions = &v41->positions;
                                            v96 = v42;
                                            v94.z = 0.0;
                                            v44 = (float)((float)((float)v42 - (float)1.0) * (float)v40);
                                            v94.y = (float)((float)v42 - (float)1.0) * (float)v40;
                                            v3 = (int)v85;
                                            p_inverseAxis = &v41->inverseAxis;
                                            do
                                            {
                                              idList<idAngles,5>::Append(this: p_positions, obj: &v94);
                                              idList<idMat3,5>::Append(this: p_inverseAxis, obj: (const idMat3 *)v3);
                                              v44 = (float)((float)v44 - (float)v40);
                                              v94.y = v44;
                                              --v2;
                                            }
                                            while ( v2 != 0 );
                                          }
LABEL_132:
                                          if ( !idParser::ReadToken(this: src, token: &v64) )
                                            break;
                                        }
                                      }
                                    }
                                    else
                                    {
                                      this->type = CLOTH_SQUARE;
                                      idParser::ExpectTokenString(this: src, string: "{");
                                      idParser::ReadToken(this: src, token: &v64);
                                      v23 = v64.data;
                                      if ( v64.data != nullptr )
                                      {
                                        v24 = (const idDeclMD6 *)idDeclInfo::FindWithInheritance(
                                                                   this: v65,
                                                                   name: v64.data,
                                                                   makeDefault: false);
                                        v23 = v64.data;
                                      }
                                      else
                                      {
                                        v24 = nullptr;
                                      }
                                      this->clothMD6 = v24;
                                      if ( v24 == nullptr || v24->model == nullptr )
                                        goto _LN523;
                                      this->width = idParser::ParseInt(this: src);
                                      v25 = idParser::ParseInt(this: src);
                                      width = this->width;
                                      this->height = v25;
                                      if ( width < 2 || v25 < 2 || width > 16 || v25 > 16 )
                                        goto _LN522;
                                      v27 = this->clothMD6->model->skeleton;
                                      if ( v27 != nullptr )
                                        v28 = (int)v27->data + v27->data->inverseBasePoseOffset;
                                      else
                                        v28 = 0;
                                      v2 = width * v25;
                                      p_particleData = &this->particleData;
                                      if ( width * v25 <= this->particleData.size
                                        || (unsigned __int8)idList<idDeclCloth::particleInfo_t,5>::Resize(
                                                              this: &this->particleData,
                                                              newsize: width * v25) != 0 )
                                      {
                                        size = this->particleData.size;
                                        if ( v2 < size )
                                          size = v2;
                                        this->particleData.num = size;
                                      }
                                      if ( idParser::ReadToken(this: src, token: &v64) )
                                      {
                                        v2 = 0;
                                        do
                                        {
                                          if ( idStr::Cmp(s1: v64.data, s2: "}") == 0 )
                                            break;
                                          idDeclMD6::GetJointIndex(
                                            this: (idDeclMD6 *)&v67,
                                            result: (idIndex<short,enum invalidJointIndex_t> *)this->clothMD6,
                                            jointName: v64.data);
                                          v4 = HIWORD(v67);
                                          if ( v67 < 0 )
                                            goto _LN521;
                                          v3 = 0;
                                          if ( idParser::ReadToken(this: src, token: &v64) )
                                          {
                                            v31 = v69;
                                            do
                                            {
                                              if ( idStr::Cmp(s1: v64.data, s2: "}") == 0 )
                                                break;
                                              if ( idStr::Icmp(s1: v64.data, s2: v31) == 0 )
                                                v3 = 1;
                                            }
                                            while ( idParser::ReadToken(this: src, token: &v64) );
                                          }
                                          v32 = (float *)((char *)&p_particleData->list->position.x + v2);
                                          v33 = (float *)(48 * (__int16)v4 + v28);
                                          *v32 = v33[3];
                                          v32[1] = v33[7];
                                          v32[2] = v33[11];
                                          *(__int16 *)((char *)&p_particleData->list->jointIndex.value + v2) = v4;
                                          *(&p_particleData->list->anchored + v2) = v3;
                                          *(int *)((char *)&p_particleData->list->rightIndex + v2) = -1;
                                          *(int *)((char *)&p_particleData->list->forwardIndex + v2) = -1;
                                          v2 += 28;
                                        }
                                        while ( idParser::ReadToken(this: src, token: &v64) );
                                      }
                                    }
                                  }
                                  else
                                  {
                                    this->type = CLOTH_GENERIC;
                                    idParser::ExpectTokenString(this: src, string: "{");
                                    idParser::ReadToken(this: src, token: &v64);
                                    v5 = v64.data;
                                    if ( v64.data != nullptr )
                                    {
                                      v6 = (const idDeclMD6 *)idDeclInfo::FindWithInheritance(
                                                                this: v65,
                                                                name: v64.data,
                                                                makeDefault: false);
                                      v5 = v64.data;
                                    }
                                    else
                                    {
                                      v6 = nullptr;
                                    }
                                    this->clothMD6 = v6;
                                    if ( v6 == nullptr || v6->model == nullptr )
                                      goto _LN520;
                                    v7 = idParser::ParseInt(this: src);
                                    v8 = v7;
                                    if ( (unsigned int)v7 > 0x40 )
                                      goto _LN519;
                                    v9 = &this->particleData;
                                    if ( v7 <= this->particleData.size
                                      || (unsigned __int8)idList<idDeclCloth::particleInfo_t,5>::Resize(
                                                            this: &this->particleData,
                                                            newsize: v7) != 0 )
                                    {
                                      v10 = this->particleData.size;
                                      if ( v8 < v10 )
                                        v10 = v8;
                                      this->particleData.num = v10;
                                    }
                                    v11 = this->clothMD6->model->skeleton;
                                    if ( v11 != nullptr )
                                      v12 = (int)v11->data + v11->data->inverseBasePoseOffset;
                                    else
                                      v12 = 0;
                                    v3 = 0;
                                    if ( v8 > 0 )
                                    {
                                      v2 = 0;
                                      while ( 1 )
                                      {
                                        idParser::ReadToken(this: src, token: &v64);
                                        idDeclMD6::GetJointIndex(
                                          this: (idDeclMD6 *)&v66,
                                          result: (idIndex<short,enum invalidJointIndex_t> *)this->clothMD6,
                                          jointName: v64.data);
                                        v13 = HIWORD(v66);
                                        if ( v66 < 0 )
                                          break;
                                        v4 = 0;
                                        *(int *)((char *)&v9->list->forwardIndex + v2) = -1;
                                        *(int *)((char *)&v9->list->rightIndex + v2) = -1;
                                        while ( idParser::ReadToken(this: src, token: &v64) )
                                        {
                                          if ( idStr::Cmp(s1: v64.data, s2: "}") == 0 )
                                            break;
                                          if ( idStr::Icmp(s1: v64.data, s2: v69) != 0 )
                                          {
                                            if ( idStr::Icmp(s1: v64.data, s2: v75) != 0 )
                                            {
                                              if ( idStr::Icmp(s1: v64.data, s2: v77) == 0 )
                                              {
                                                v15 = (char *)v9->list + v2;
                                                *((_DWORD *)v15 + 5) = idParser::ParseInt(this: src);
                                              }
                                            }
                                            else
                                            {
                                              v14 = (char *)v9->list + v2;
                                              *((_DWORD *)v14 + 4) = idParser::ParseInt(this: src);
                                            }
                                          }
                                          else
                                          {
                                            v4 = 1;
                                          }
                                        }
                                        v97 = *(idMat3x4 *)(48 * v13 + v12);
                                        idMat3x4::Invert(this: &v97);
                                        ++v3;
                                        v16 = (float *)((char *)&v9->list->position.x + v2);
                                        v17 = v97.mat[7];
                                        v18 = v97.mat[11];
                                        *v16 = v97.mat[3];
                                        v16[1] = v17;
                                        v16[2] = v18;
                                        *(__int16 *)((char *)&v9->list->jointIndex.value + v2) = v13;
                                        v19 = (char *)v9->list + v2;
                                        v2 += 28;
                                        v19[24] = v4;
                                        if ( v3 >= v8 )
                                          goto LABEL_68;
                                      }
                                      idLib::Error(
                                        fmt: "Invalid joint %s found while parsing %s",
                                        v64.data,
                                        this->name.str);
_LN518:
                                      idLib::Error(fmt: "Invalid index for spring %d in %s", v4, this->name.str);
_LN519:
                                      idLib::Error(fmt: "Invalid num particles for %s, -> %d", this->name.str, v8);
_LN520:
                                      idLib::Error(fmt: "Unable to find md6 decl %s for %s", v5, this->name.str);
_LN521:
                                      idLib::Error(
                                        fmt: "Invalid joint %s found while parsing %s",
                                        v64.data,
                                        this->name.str);
_LN522:
                                      idLib::Error(fmt: "Invalid width or height - %d x %d", width, v25);
_LN523:
                                      idLib::Error(fmt: "Unable to find md6 decl %s for %s", v23, this->name.str);
_LN524:
                                      idLib::Error(fmt: "Invalid number of particles %d", v2);
_LN525:
                                      idLib::Error(fmt: "Invalid joint index %s", v64.data);
_LN526:
                                      idLib::Error(fmt: "Invalid joint found while parsing rope for %s", this->name.str);
_LN527:
                                      idLib::Error(fmt: "Invalid number of particles %d", v3);
_LN528:
                                      idLib::Error(fmt: "Unable to find rope decl %s", data);
_LN529:
                                      idParser::Warning(this: v34, str: "bad token %s", v64.data);
                                      break;
                                    }
LABEL_68:
                                    idParser::ExpectTokenString(this: src, string: "springs");
                                    idParser::ExpectTokenString(this: src, string: "{");
                                    p_springData = &this->springData;
                                    v3 = idParser::ParseInt(this: src);
                                    idList<idDeclCloth::springInfo_t,5>::SetNum(this: &this->springData, newNum: v3);
                                    v4 = 0;
                                    if ( v3 > 0 )
                                    {
                                      v21 = 0;
                                      do
                                      {
                                        v2 = idParser::ParseInt(this: src);
                                        v22 = idParser::ParseInt(this: src);
                                        if ( v2 < 0 || v22 < 0 || v2 > 64 || v22 > 64 )
                                          goto _LN518;
                                        p_springData->list[v21].index1 = v2;
                                        p_springData->list[v21].index2 = v22;
                                        if ( idParser::ReadToken(this: src, token: &v64) )
                                        {
                                          while ( idStr::Cmp(s1: v64.data, s2: "}") != 0
                                               && idParser::ReadToken(this: src, token: &v64) )
                                            ;
                                        }
                                        ++v4;
                                        ++v21;
                                      }
                                      while ( v4 < v3 );
                                    }
                                    idParser::ExpectTokenString(this: src, string: "}");
                                  }
                                }
                                else
                                {
                                  idParser::ReadToken(this: src, token: &v64);
                                  if ( v64.data != nullptr )
                                    this->clothDeclFX = (const idDeclFX *)idDeclInfo::FindWithInheritance(
                                                                            this: v71,
                                                                            name: v64.data,
                                                                            makeDefault: true);
                                  else
                                    this->clothDeclFX = nullptr;
                                }
                              }
                              else
                              {
                                this->springMaxLengthMultiplier = idParser::ParseFloat(this: src, errorFlag: nullptr);
                              }
                            }
                            else
                            {
                              idParser::ReadToken(this: src, token: &v64);
                              if ( v64.data != nullptr )
                                this->material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                                       this: v82,
                                                                       name: v64.data,
                                                                       makeDefault: true);
                              else
                                this->material = nullptr;
                            }
                          }
                          else
                          {
                            this->springFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          }
                        }
                        else
                        {
                          this->springLength = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        }
                      }
                      else
                      {
                        this->gravity = idParser::ParseFloat(this: src, errorFlag: nullptr);
                      }
                    }
                    else
                    {
                      this->collisionFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    }
                  }
                  else
                  {
                    this->friction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  this->mass = idParser::ParseFloat(this: src, errorFlag: nullptr);
                }
              }
              else
              {
                idParser::ReadToken(this: src, token: &v64);
                if ( idStr::Icmp(s1: v64.data, s2: v93) != 0 )
                {
                  if ( idStr::Icmp(s1: v64.data, s2: v74) != 0 )
                    this->springType = CLOTH_SPRING_BANDED;
                  else
                    this->springType = CLOTH_SPRING_CROSS;
                }
                else
                {
                  this->springType = CLOTH_SPRING_QUAD;
                }
              }
            }
            else
            {
              this->hSpacing = idParser::ParseFloat(this: src, errorFlag: nullptr);
            }
          }
          else
          {
            this->vSpacing = idParser::ParseFloat(this: src, errorFlag: nullptr);
          }
        }
        else
        {
          this->height = idParser::ParseInt(this: src);
        }
      }
      else
      {
        this->width = idParser::ParseInt(this: src);
      }
    }
    while ( idParser::ReadToken(this: src, token: &v64) );
  }
  idStr::FreeData(this: &v64);
}


// ========================================================================
// $LN507_0
// EA  : 0x827AD030
// RVA : 0x007AD030
// PDB : w:\tech5\engine\models\cloth\declcloth.cpp
// ========================================================================

void _LN507_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 96));
}

