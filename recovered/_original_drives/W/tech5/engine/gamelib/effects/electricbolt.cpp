
// ========================================================================
// ?Init@idElectricBolt@@QAAXPAVidRenderModelBeam@@PBVidDeclElectricBolt@@@Z
// EA  : 0x82708E68
// RVA : 0x00708E68
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void __fastcall idElectricBolt::Init(
        idElectricBolt *this,
        idRenderModelBeam *_beamModel,
        const idDeclElectricBolt *_eboltDecl)
{
  this->beamModel = _beamModel;
  this->eboltDecl = _eboltDecl;
}


// ========================================================================
// ??1idElectricBolt@@QAA@XZ
// EA  : 0x827091D0
// RVA : 0x007091D0
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void __fastcall idElectricBolt::~idElectricBolt(idElectricBolt *this)
{
  this->eboltDecl = nullptr;
  this->beamModel = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlNodes);
}


// ========================================================================
// ?UpdateControlNodes@idElectricBolt@@QAAXAAV?$idStaticList@UeboltControlNode_t@@$0CA@@@@Z
// EA  : 0x827093C0
// RVA : 0x007093C0
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void __fastcall idElectricBolt::UpdateControlNodes(
        idElectricBolt *this,
        idStaticList<eboltControlNode_t,32> *_controlNodes)
{
  idStaticList<eboltControlNode_t,32>::operator=(this: &this->controlNodes, __that: _controlNodes);
}


// ========================================================================
// ??0idElectricBolt@@QAA@XZ
// EA  : 0x827095C0
// RVA : 0x007095C0
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

idElectricBolt *__fastcall idElectricBolt::idElectricBolt(idElectricBolt *this)
{
  this->eboltDecl = nullptr;
  this->beamModel = nullptr;
  this->controlNodes.num = 0;
  this->controlNodes.size = 32;
  this->controlNodes.list = this->controlNodes.staticList;
  this->controlNodes.granularity = 1;
  this->controlNodes.memTag = 5;
  this->controlNodes.listStatic = 1;
  this->startTime = 0;
  this->diversity = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlNodes);
  return this;
}


// ========================================================================
// __unwind$247864
// EA  : 0x82709644
// RVA : 0x00709644
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void _unwind_247864()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?StartElectricBolt@idElectricBolt@@QAAXHABVidVec3@@0M@Z
// EA  : 0x82709670
// RVA : 0x00709670
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void __fastcall idElectricBolt::StartElectricBolt(
        idElectricBolt *this,
        int _startTime,
        const idVec3 *_startPos,
        const idVec3 *_endPos,
        double _diversity)
{
  eboltControlNode_t *list; // r9
  eboltControlNode_t *v9; // r11

  if ( this->beamModel != nullptr && this->eboltDecl != nullptr )
  {
    this->startTime = _startTime;
    this->diversity = (int)(float)((float)_diversity * (float)32767.0);
    idList<eboltControlNode_t,5>::SetNum(this: &this->controlNodes, newNum: 1);
    list = this->controlNodes.list;
    list->startPos.x = _startPos->x;
    list->startPos.y = _startPos->y;
    list->startPos.z = _startPos->z;
    v9 = this->controlNodes.list;
    v9->endPos.x = _endPos->x;
    v9->endPos.y = _endPos->y;
    v9->endPos.z = _endPos->z;
  }
  else
  {
    idList<eboltControlNode_t,5>::SetNum(this: &this->controlNodes, newNum: 0);
  }
}


// ========================================================================
// ?StartElectricBolt@idElectricBolt@@QAAXHAAV?$idStaticList@UeboltControlNode_t@@$0CA@@@M@Z
// EA  : 0x82709720
// RVA : 0x00709720
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void __fastcall idElectricBolt::StartElectricBolt(
        idElectricBolt *this,
        int _startTime,
        idStaticList<eboltControlNode_t,32> *_controlNodes,
        double _diversity)
{
  this->startTime = _startTime;
  this->diversity = (int)(float)((float)_diversity * (float)32767.0);
  idStaticList<eboltControlNode_t,32>::operator=(this: &this->controlNodes, __that: _controlNodes);
}


// ========================================================================
// ?StopElectricBolt@idElectricBolt@@QAAXXZ
// EA  : 0x82709750
// RVA : 0x00709750
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void __fastcall idElectricBolt::StopElectricBolt(idElectricBolt *this)
{
  idStaticList<eboltControlNode_t,32> *p_controlNodes; // r31

  p_controlNodes = &this->controlNodes;
  if ( this->controlNodes.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlNodes);
  p_controlNodes->num = __CFADD__(-p_controlNodes->size, p_controlNodes->size ^ 0x80000000) ? 0 : p_controlNodes->size;
}


// ========================================================================
// SubdivideBolt_r
// EA  : 0x827099D0
// RVA : 0x007099D0
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall SubdivideBolt_r(
        const idVec3 *startPos,
        const idVec3 *endPos,
        boltStats_t *stats,
        int diversity,
        int subDivisionLevel,
        int branchLevel,
        idStaticList<segment_t,128> *segments,
        idRenderModelBeam *beamModel,
        double deviation,
        const idDeclElectricBolt *eboltDecl,
        const int numSubdivisions,
        const int time,
        idRandom2 *rnd,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        const idDeclElectricBolt *a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        unsigned int a35)
{
  double v37; // fp11
  double v38; // fp8
  double v39; // fp2
  double v40; // fp4
  double v42; // fp3
  double v51; // fp1
  double v52; // fp5
  double v53; // fp1
  __int64 v54; // r4 OVERLAPPED
  double v55; // fp13
  double v56; // fp12
  int v57; // r7
  double v58; // fp28
  int v59; // r4
  __int64 v60; // r11
  double v61; // fp29
  double v62; // fp26
  double v63; // fp1
  __int64 v64; // r9
  double v65; // fp28
  double y; // fp26
  double x; // fp25
  unsigned int v68; // r6
  __int64 v69; // r3
  long double v70; // fp2
  unsigned int v71; // r21
  double v72; // fp29
  long double v73; // fp2
  __int64 v74; // r10
  unsigned int v75; // r10
  unsigned int v76; // r23
  int v77; // r5
  double v78; // fp12
  segment_t *v79; // r3
  double v80; // fp2
  double v81; // fp1
  double v82; // fp12
  segment_t *v83; // r3
  __int64 v84; // r9
  int v85; // r11
  int v86; // r10
  unsigned int v87; // r27
  double v88; // fp10
  double v89; // fp8
  unsigned int v90; // r27
  __int64 v91; // r8
  const idMat3 *v92; // r3
  __int64 v93; // r11
  double v94; // fp0
  idRenderWorld *v95; // r3
  idRenderWorld *v96; // r3
  segment_t *v97; // r3
  __int64 v98; // r6
  long double v99; // fp2
  long double v100; // fp4
  double v101; // fp1
  double v102; // fp10
  long double v103; // fp2
  int v104; // r26
  const idDeclElectricBolt *v105; // [sp+8h] [-1048h]
  const idDeclElectricBolt *v106; // [sp+8h] [-1048h]
  int v107; // [sp+Ch] [-1044h]
  int v108; // [sp+Ch] [-1044h]
  int v109; // [sp+10h] [-1040h]
  int v110; // [sp+10h] [-1040h]
  idRandom2 *v111; // [sp+14h] [-103Ch]
  idRandom2 *v112; // [sp+14h] [-103Ch]
  idVec3 v113; // [sp+88h] [-FC8h] BYREF
  idVec3 v114; // [sp+98h] [-FB8h] BYREF
  idMat3 v115; // [sp+A8h] [-FA8h] BYREF
  idVec3 v116; // [sp+D0h] [-F80h] BYREF
  float v117; // [sp+DCh] [-F74h]
  float v118; // [sp+E0h] [-F70h]
  float v119; // [sp+E4h] [-F6Ch]
  float v120; // [sp+E8h] [-F68h]
  float v121; // [sp+ECh] [-F64h]
  float v122; // [sp+F0h] [-F60h]
  idMat3 v123; // [sp+100h] [-F50h] BYREF
  idRotation v124; // [sp+130h] [-F20h] BYREF
  idStaticList<segment_t,128> v125; // [sp+180h] [-ED0h] BYREF

  v37 = (float)(endPos->y - startPos->y);
  v38 = (float)(endPos->x - startPos->x);
  v39 = (float)(endPos->z + startPos->z);
  v40 = (float)(endPos->z - startPos->z);
  v42 = (float)(endPos->y + startPos->y);
  v113.x = (float)(endPos->x + startPos->x) * (float)0.5;
  v113.z = (float)v39 * (float)0.5;
  v113.y = (float)v42 * (float)0.5;
  _FP5 = (float)((float)((float)((float)v40 * (float)v40)
                       + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f5, f6, f13 }
  v51 = __frsqrte(_FP2);
  v52 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v51
                                                                                      * (float)((float)((float)((float)v40 * (float)v40) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                                                                              * (float)0.5))
                                                                              * (float)v51)
                                                                      - (float)1.5)
                                                      * (float)v51)
                                              * (float)((float)((float)((float)v40 * (float)v40)
                                                              + (float)((float)((float)v38 * (float)v38)
                                                                      + (float)((float)v37 * (float)v37)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v51
                                                                              * (float)((float)((float)((float)v40 * (float)v40)
                                                                                              + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                                                                      * (float)0.5))
                                                                      * (float)v51)
                                                              - (float)1.5)
                                              * (float)v51))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v51
                                                      * (float)((float)((float)((float)v40 * (float)v40)
                                                                      + (float)((float)((float)v38 * (float)v38)
                                                                              + (float)((float)v37 * (float)v37)))
                                                              * (float)0.5))
                                              * (float)v51)
                                      - (float)1.5)
                      * (float)v51));
  v53 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v51 * (float)((float)((float)((float)v40 * (float)v40) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37))) * (float)0.5)) * (float)v51) - (float)1.5)
                                                                                              * (float)v51)
                                                                                      * (float)((float)((float)((float)v40 * (float)v40) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v51 * (float)((float)((float)((float)v40 * (float)v40) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37))) * (float)0.5)) * (float)v51) - (float)1.5)
                                                                                      * (float)v51))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v51
                                                                                              * (float)((float)((float)((float)v40 * (float)v40) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37))) * (float)0.5))
                                                                                      * (float)v51)
                                                                              - (float)1.5)
                                                              * (float)v51))
                                              * (float)((float)((float)((float)v40 * (float)v40)
                                                              + (float)((float)((float)v38 * (float)v38)
                                                                      + (float)((float)v37 * (float)v37)))
                                                      * (float)0.5))
                                      * (float)v52)
                              - (float)1.5)
              * (float)v52);
  v115.mat[1].y = (float)v38 * (float)v53;
  v115.mat[1].z = (float)v37 * (float)v53;
  v115.mat[2].x = (float)v40 * (float)v53;
  HIDWORD(v54) = idVec3::ToMat3(this: &v116, result: (idMat3 *)&v115.mat[1].y);
  v55 = 0.0;
  v56 = 0.0;
  if ( a29->jitterTable != nullptr )
  {
    v57 = a33 - stats->boltStartTime;
    HIDWORD(v60) = a29->jitterFalloffTable;
    v58 = 1.0;
    v59 = __CFADD__(v57, 0x80000000) - 1;
    LODWORD(v60) = v59 & v57;
    v61 = (float)((float)((float)((float)(v113.z - stats->boltStartPos.z) * (float)(v113.z - stats->boltStartPos.z))
                        + (float)((float)((float)(v113.x - stats->boltStartPos.x)
                                        * (float)(v113.x - stats->boltStartPos.x))
                                + (float)((float)(v113.y - stats->boltStartPos.y)
                                        * (float)(v113.y - stats->boltStartPos.y))))
                * stats->invTotalLength);
    v62 = (float)((float)(a29->jitterSpeed * (float)v60)
                + (float)((float)((float)((float)(v113.z - stats->boltStartPos.z)
                                        * (float)(v113.z - stats->boltStartPos.z))
                                + (float)((float)((float)(v113.x - stats->boltStartPos.x)
                                                * (float)(v113.x - stats->boltStartPos.x))
                                        + (float)((float)(v113.y - stats->boltStartPos.y)
                                                * (float)(v113.y - stats->boltStartPos.y))))
                        * stats->invTotalLength));
    if ( HIDWORD(v60) != 0 )
      v58 = idLookupTable::TableLookup(
              this: *(idLookupTable **)(HIDWORD(v60) + 64),
              time: (float)((float)((float)((float)(v113.z - stats->boltStartPos.z) * (float)(v113.z - stats->boltStartPos.z))
                            + (float)((float)((float)(v113.x - stats->boltStartPos.x)
                                            * (float)(v113.x - stats->boltStartPos.x))
                                    + (float)((float)(v113.y - stats->boltStartPos.y)
                                            * (float)(v113.y - stats->boltStartPos.y))))
                    * stats->invTotalLength),
              fastSearch: v59);
    v63 = idLookupTable::TableLookup(this: a29->jitterTable->table, time: v62, fastSearch: v59);
    LODWORD(v64) = subDivisionLevel;
    v65 = (float)((float)v63 * (float)v58);
    y = a29->jitterLeftMag.y;
    x = a29->jitterLeftMag.x;
    v68 = 1664525 * (int)(float)((float)__SPAIR64__(subDivisionLevel, a35) * (float)v61) + 1013904223;
    LODWORD(v69) = (v68 >> 10) & 0x7FFF;
    *((double *)&v70 + 1) = (float)v64;
    v71 = 1664525 * v68 + 1013904223;
    *(double *)&v70 = -(float)(a29->jitterDecay * (float)v64);
    v72 = (float)((float)((float)((float)v69 * (float)(a29->jitterUpMag.y - a29->jitterUpMag.x)) * (float)0.000030518509)
                + a29->jitterUpMag.x);
    v73 = exp(x: v70);
    LODWORD(v74) = (v71 >> 10) & 0x7FFF;
    v55 = (float)((float)((float)*(double *)&v73 * (float)v72) * (float)v65);
    v56 = (float)((float)((float)((float)((float)((float)v74 * (float)((float)y - (float)x)) * (float)0.000030518509)
                                + (float)x)
                        * (float)*(double *)&v73)
                * (float)v65);
  }
  v75 = 1664525 * a35 + 1013904223;
  v76 = 1664525 * v75 + 1013904223;
  v77 = (v75 >> 10) & 0x7FFF;
  LODWORD(v54) = (v76 >> 10) & 0x7FFF;
  v78 = (float)((float)((float)((float)((float)*(__int64 *)((char *)&v54 - 4) * (float)0.000061037019) - (float)1.0)
                      * (float)deviation)
              + (float)v56);
  v113.x = (float)(v120
                 * (float)((float)((float)((float)((float)v54 * (float)0.000061037019) - (float)1.0) * (float)deviation)
                         + (float)v55))
         + (float)((float)(v117 * (float)v78) + v113.x);
  v113.z = (float)(v113.z + (float)(v119 * (float)v78))
         + (float)(v122
                 * (float)((float)((float)((float)((float)v54 * (float)0.000061037019) - (float)1.0) * (float)deviation)
                         + (float)v55));
  v113.y = (float)(v113.y + (float)(v118 * (float)v78))
         + (float)(v121
                 * (float)((float)((float)((float)((float)v54 * (float)0.000061037019) - (float)1.0) * (float)deviation)
                         + (float)v55));
  if ( subDivisionLevel < a31 )
  {
    v104 = subDivisionLevel + 1;
    SubdivideBolt_r(
      startPos,
      endPos: &v113,
      stats,
      diversity,
      subDivisionLevel: v104,
      branchLevel,
      segments,
      beamModel,
      eboltDecl: v105,
      numSubdivisions: v107,
      time: v109,
      rnd: v111,
      deviation: (float)((float)deviation * (float)0.5));
    SubdivideBolt_r(
      startPos: &v113,
      endPos,
      stats,
      diversity,
      subDivisionLevel: v104,
      branchLevel,
      segments,
      beamModel,
      eboltDecl: v106,
      numSubdivisions: v108,
      time: v110,
      rnd: v112,
      deviation: (float)((float)deviation * (float)0.5));
  }
  else
  {
    v79 = idList<segment_t,5>::Alloc(this: segments);
    v79->startPos.x = startPos->x;
    v79->startPos.y = startPos->y;
    v79->startPos.z = startPos->z;
    v79->endPos = v113;
    v80 = (float)(startPos->y - stats->boltStartPos.y);
    v81 = (float)(startPos->x - stats->boltStartPos.x);
    v82 = (float)(startPos->z - stats->boltStartPos.z);
    v79->lengthFrac = (float)((float)((float)v82 * (float)v82)
                            + (float)((float)((float)v81 * (float)v81) + (float)((float)v80 * (float)v80)))
                    * stats->invTotalLength;
    ++stats->numNodes;
    v83 = idList<segment_t,5>::Alloc(this: segments);
    v83->startPos = v113;
    HIDWORD(v84) = &v83->endPos;
    v85 = 0;
    v83->endPos = *endPos;
    v83->lengthFrac = (float)((float)((float)(v113.z - stats->boltStartPos.z) * (float)(v113.z - stats->boltStartPos.z))
                            + (float)((float)((float)(v113.x - stats->boltStartPos.x)
                                            * (float)(v113.x - stats->boltStartPos.x))
                                    + (float)((float)(v113.y - stats->boltStartPos.y)
                                            * (float)(v113.y - stats->boltStartPos.y))))
                    * stats->invTotalLength;
    v86 = stats->numNodes + 1;
    stats->numNodes = v86;
    if ( v86 > 0 )
    {
      do
      {
        HIDWORD(v84) = 1664525 * v76;
        ++v85;
        v76 = 1664525 * v76 + 1013904223;
      }
      while ( v85 < v86 );
    }
    if ( v86 != 0 )
    {
      v87 = 1664525 * v76 + 1013904223;
      LODWORD(v84) = (v87 >> 10) & 0x7FFF;
      if ( (float)((float)v84 * (float)0.000030518509) < (double)a29->branchProbability
        && branchLevel < a29->maxBranchLevels )
      {
        v88 = (float)(v113.z - startPos->z);
        v89 = (float)(v113.y - startPos->y);
        v115.mat[0].x = v113.x - startPos->x;
        v115.mat[0].z = v88;
        v115.mat[0].y = v89;
        idVec3::NormalizeFast(this: v115.mat);
        idVec3::ToMat3(this: v123.mat, result: &v115);
        v90 = 1664525 * v87 + 1013904223;
        LODWORD(v91) = (v90 >> 10) & 0x7FFF;
        idRotation::idRotation(
          this: &v124,
          rotationOrigin: &vec3_origin,
          rotationVec: &v123.mat[2],
          rotationAngle: (float)((float)((float)v91 * a29->maxBranchAngle) * (float)0.000030518509));
        v92 = idRotation::ToMat3(this: &v124);
        idMat3::operator*=(this: &v123, a: v92);
        LODWORD(v93) = ((1664525 * v90 + 1013904223) >> 10) & 0x7FFF;
        v94 = (float)((float)((float)((float)v93 * (float)(a29->branchLength.y - a29->branchLength.x))
                            * (float)0.000030518509)
                    + a29->branchLength.x);
        v114.z = v113.z
               + (float)(v123.mat[0].z
                       * (float)((float)((float)((float)v93 * (float)(a29->branchLength.y - a29->branchLength.x))
                                       * (float)0.000030518509)
                               + a29->branchLength.x));
        v114.y = v113.y + (float)(v123.mat[0].y * (float)v94);
        v114.x = (float)(v123.mat[0].x * (float)v94) + v113.x;
        if ( g_eboltDebug.valueInteger == 4 )
        {
          v95 = common->RW(this: common);
          ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, idVec3 *, double))v95->DebugArrow)(
            a1: v95,
            a2: &idColor::colorGreen,
            a3: startPos,
            a4: &v113,
            a5: 4.0);
          v96 = common->RW(this: common);
          ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, idVec3 *, char *, _DWORD, _DWORD, double))v96->DebugArrow)(
            a1: v96,
            a2: &idColor::colorRed,
            a3: startPos,
            a4: &v114,
            a5: &aAvSsobjectVCom[20],
            a6: 0,
            a7: 0,
            a8: 4.0);
        }
        v125.granularity = 1;
        v125.size = 128;
        v125.list = v125.staticList;
        v125.num = 0;
        v125.memTag = 5;
        v125.listStatic = 1;
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v125);
        v97 = idList<segment_t,5>::Alloc(this: &v125);
        v97->startPos.x = startPos->x;
        LODWORD(v98) = branchLevel;
        v97->startPos.y = startPos->y;
        v97->startPos.z = startPos->z;
        v97->endPos = v114;
        *((double *)&v99 + 1) = (float)v98;
        *((double *)&v100 + 1) = startPos->y;
        *(double *)&v100 = stats->boltStartPos.y;
        v101 = (float)(startPos->y - stats->boltStartPos.y);
        v102 = (float)(startPos->z - stats->boltStartPos.z);
        v97->lengthFrac = (float)((float)((float)v102 * (float)v102)
                                + (float)((float)((float)(startPos->x - stats->boltStartPos.x)
                                                * (float)(startPos->x - stats->boltStartPos.x))
                                        + (float)((float)v101 * (float)v101)))
                        * stats->invTotalLength;
        *(_QWORD *)&v99 = 0x3FE0000000000000LL;
        ++stats->numBranches;
        v103 = pow(x: v99, y: v100);
        GenerateBolt(
          currSegments: &v125,
          stats,
          beamModel,
          eboltDecl: a29,
          currTime: a33,
          diversity: stats->numBranches + diversity,
          branchLevel: branchLevel + 1,
          maxDeviation: (float)(a29->maxBranchDeviation * (float)*(double *)&v103),
          maxSubdivisions: a29->branchSubdivisions);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v125);
      }
    }
  }
}


// ========================================================================
// __unwind$248246
// EA  : 0x8270A21C
// RVA : 0x0070A21C
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void _unwind_248246()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4176 + 384));
}


// ========================================================================
// ?GenerateBolt@@YAXAAV?$idStaticList@Usegment_t@@$0IA@@@AAUboltStats_t@@PAVidRenderModelBeam@@PBVidDeclElectricBolt@@HHHMH@Z
// EA  : 0x8270A250
// RVA : 0x0070A250
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall GenerateBolt(
        idStaticList<segment_t,128> *currSegments,
        boltStats_t *stats,
        idRenderModelBeam *beamModel,
        const idDeclElectricBolt *eboltDecl,
        int currTime,
        int diversity,
        int branchLevel,
        double maxDeviation,
        int maxSubdivisions,
        double a10,
        long double a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31)
{
  boltStats_t *v32; // r14
  idRenderModelBeam *v33; // r20
  unsigned int v36; // r25
  int v37; // r15
  __int64 v40; // r7
  long double v41; // fp2
  long double v42; // fp2
  double v43; // fp10
  double lengthFrac; // fp0
  __int64 v47; // r10
  int boltStartTime; // r11
  idRenderWorld *v49; // r3
  int frames; // r30
  __int64 v51; // r11
  int v52; // r3
  long double v53; // fp2
  double v54; // fp31
  double v55; // fp29
  long double v56; // fp2
  double v57; // fp29
  long double v58; // fp4
  long double v60; // fp2
  segment_t *list; // r11
  __int64 v62; // r8
  double x; // fp6
  __int64 v64; // r5 OVERLAPPED
  BOOL applyGradient; // r6
  double v66; // fp9
  double v67; // fp8
  double v68; // fp7
  double v69; // fp6
  double z; // fp4
  double v71; // fp0
  int revealTime; // r9
  int v75; // r10
  double v76; // fp0
  int v77; // r6
  long double v85; // fp4
  int v86; // r30
  int v87; // r29
  segment_t *v88; // r4
  idMem *v89; // r3
  idMem *v90; // r19
  int valueInteger; // r10
  int v92; // r29
  int v93; // r30
  _BYTE v94[12]; // r11 OVERLAPPED
  long double v95; // fp2
  long double v96; // fp2
  double v97; // fp10
  double v98; // fp0
  int v101; // r8 OVERLAPPED
  double v102; // fp0
  __int64 v103; // fp9
  idRenderWorld *v104; // r3
  __int64 v105; // r10
  __int64 v106; // r6
  long double v107; // fp2
  double v108; // fp27
  long double v109; // fp4
  long double v110; // fp2
  double startWidth; // fp24
  double endWidth; // fp13
  int v113; // r29
  double v114; // fp29
  double v115; // fp25
  idVec4 *p_color; // r26
  int v117; // r27
  segment_t *v121; // r30
  int v123; // r2 OVERLAPPED
  int num; // r11
  beamNodeParms_t *v126; // r11
  double w; // fp7
  BOOL v128; // r8
  double v129; // fp6
  double v130; // fp10
  double v131; // fp11
  double v132; // fp12
  double v133; // fp0
  double v136; // fp0
  int v137; // r3
  const idDeclElectricBolt *v138; // [sp+8h] [-4268h]
  int v139; // [sp+Ch] [-4264h]
  int v140; // [sp+10h] [-4260h]
  idRandom2 *v141; // [sp+14h] [-425Ch]
  int v142; // [sp+18h] [-4258h]
  int v143; // [sp+1Ch] [-4254h]
  int v144; // [sp+20h] [-4250h]
  int v145; // [sp+24h] [-424Ch]
  int v146; // [sp+28h] [-4248h]
  int v147; // [sp+2Ch] [-4244h]
  int v148; // [sp+30h] [-4240h]
  int v149; // [sp+34h] [-423Ch]
  int v150; // [sp+38h] [-4238h]
  int v151; // [sp+3Ch] [-4234h]
  int v152; // [sp+40h] [-4230h]
  int v153; // [sp+44h] [-422Ch]
  int v154; // [sp+48h] [-4228h]
  int v155; // [sp+4Ch] [-4224h]
  int v156; // [sp+50h] [-4220h]
  int v157; // [sp+58h] [-4218h]
  int v158; // [sp+60h] [-4210h]
  int v159; // [sp+68h] [-4208h]
  unsigned __int64 v160; // [sp+88h] [-41E8h] BYREF
  __int64 v161; // [sp+90h] [-41E0h]
  idColor v162; // [sp+A0h] [-41D0h] BYREF
  idColor v163; // [sp+B0h] [-41C0h] BYREF
  _QWORD v164[2]; // [sp+C0h] [-41B0h] BYREF
  _QWORD v165[6]; // [sp+D0h] [-41A0h] BYREF
  beamNodeParms_t v166; // [sp+100h] [-4170h] BYREF
  idStaticList<segment_t,128> v167; // [sp+170h] [-4100h] BYREF
  idList<beamNodeParms_t,5> v168; // [sp+F80h] [-32F0h] BYREF
  int v169; // [sp+F90h] [-32E0h] BYREF

  v32 = stats;
  v33 = beamModel;
  v36 = ((stats->numBranches + 1) << 10) & 0x7C00 ^ diversity;
  v37 = currTime;
  HIDWORD(v160) = v36;
  if ( branchLevel > 0 && eboltDecl->useBranchOverride )
  {
    if ( g_eboltDebug.valueInteger != 0 )
    {
      *(float *)&v40 = idColor::colorCyan.g;
      v163 = idColor::colorCyan;
      switch ( g_eboltDebug.valueInteger )
      {
        case 1:
          *(_QWORD *)&v41 = 0x3FE0000000000000LL;
          *((double *)&v41 + 1) = (float)__SPAIR64__(&unk_821F0000, branchLevel);
          v42 = pow(x: v41, y: a11);
          v43 = (float)(eboltDecl->brightness * (float)*(double *)&v42);
          v163.r = eboltDecl->brightness * (float)*(double *)&v42;
          v163.g = v43;
          v163.b = v43;
          v163.a = v43;
          break;
        case 2:
          lengthFrac = currSegments->list->lengthFrac;
          if ( lengthFrac >= 0.0 )
          {
            if ( lengthFrac > 1.0 )
              lengthFrac = 1.0;
          }
          else
          {
            lengthFrac = 0.0;
          }
          _FP12 = (float)((float)0.2 - (float)((float)1.0 - (float)lengthFrac));
          __asm { fsel      f11, f12, f0, f13 }
          v163.r = _FP11;
          v163.g = _FP11;
          v163.b = _FP11;
          v163.a = _FP11;
          break;
        case 3:
          LODWORD(v47) = eboltDecl->revealTime;
          if ( (_DWORD)v47 != 0 && (boltStartTime = stats->boltStartTime, currTime <= boltStartTime + (int)v47) )
          {
            HIDWORD(v47) = currSegments->list;
            LODWORD(v40) = stats->boltStartTime;
            v160 = __PAIR64__(boltStartTime, v37);
            if ( *(float *)(HIDWORD(v47) + 24) >= (double)(float)((float)((float)__SPAIR64__(boltStartTime, v37)
                                                                        - (float)v40)
                                                                / (float)v47) )
            {
              v163.r = 0.0;
              v163.g = 0.0;
              v163.b = 0.0;
              v163.a = 0.0;
            }
            else
            {
              v163.r = 1.0;
              v163.g = 1.0;
              v163.b = 1.0;
              v163.a = 1.0;
            }
          }
          else
          {
            v163 = idColor::colorWhite;
          }
          break;
        default:
          break;
      }
      v49 = common->RW(this: common);
      v49->DebugLine(
        this: v49,
        a2: (const idVec4 *)&v163,
        a3: &currSegments->list->startPos,
        a4: &currSegments->list->endPos,
        a5: 0,
        a6: false);
    }
    else
    {
      frames = eboltDecl->branchOverride.frames;
      v52 = idRandom2::RandomInt(this: (idRandom2 *)&v160, max: frames);
      if ( frames <= 0 )
      {
        v54 = 1.0;
      }
      else
      {
        HIDWORD(v51) = frames;
        v54 = (float)((float)1.0 / (float)*(__int64 *)((char *)&v51 + 4));
      }
      LODWORD(v51) = v52;
      v55 = (float)((float)v51 * (float)v54);
      *(double *)&v53 = v55;
      v56 = floor(x: v53);
      v57 = (float)((float)v55 - (float)*(double *)&v56);
      *(_QWORD *)&v56 = 0x3FE0000000000000LL;
      *((double *)&v56 + 1) = (float)__SPAIR64__(&unk_821F0000, branchLevel);
      v60 = pow(x: v56, y: v58);
      list = currSegments->list;
      HIDWORD(v62) = allocationCurrent[242];
      x = eboltDecl->color.x;
      LODWORD(v64) = eboltDecl->branchOverride.width;
      applyGradient = eboltDecl->applyGradient;
      *(double *)&v60 = (float)(eboltDecl->brightness * (float)*(double *)&v60);
      v166.startPos = currSegments->list->startPos;
      HIDWORD(v160) = list;
      v66 = (float)((float)x * (float)*(double *)&v60);
      v166.endPos.x = list->endPos.x;
      HIDWORD(v160) = &list->endPos;
      v166.endPos.y = list->endPos.y;
      v67 = (float)(eboltDecl->color.y * (float)*(double *)&v60);
      v68 = (float)(eboltDecl->color.z * (float)*(double *)&v60);
      v69 = (float)(eboltDecl->color.w * (float)*(double *)&v60);
      z = list->endPos.z;
      *((float *)v164 + 1) = eboltDecl->color.y * (float)*(double *)&v60;
      *(float *)v164 = v66;
      *(float *)&v164[1] = v68;
      *((float *)&v164[1] + 1) = v69;
      v166.endPos.z = z;
      v166.sMinMax.x = 0.0;
      v166.sMinMax.y = 1.0;
      v166.tMinMax.x = v57;
      v166.tMinMax.y = (float)v57 + (float)v54;
      v166.halfWidth = (float)v64 * (float)0.5;
      v166.orientVec.x = vec3_origin.x;
      v166.orientVec.y = vec3_origin.y;
      v166.orientVec.z = vec3_origin.z;
      if ( applyGradient )
      {
        v71 = list->lengthFrac;
        if ( v71 >= 0.0 )
        {
          if ( v71 > 1.0 )
            v71 = 1.0;
        }
        else
        {
          v71 = 0.0;
        }
        _FP12 = (float)((float)0.2 - (float)((float)1.0 - (float)v71));
        __asm { fsel      f11, f12, f0, f13 }
        *(float *)v164 = (float)v66 * (float)_FP11;
        *((float *)v164 + 1) = (float)v67 * (float)_FP11;
        *(float *)&v164[1] = (float)v68 * (float)_FP11;
        *((float *)&v164[1] + 1) = (float)v69 * (float)_FP11;
      }
      revealTime = eboltDecl->revealTime;
      if ( revealTime != 0 )
      {
        v75 = v32->boltStartTime;
        if ( v37 <= v75 + revealTime )
        {
          LODWORD(v62) = v37;
          v76 = list->lengthFrac;
          v160 = __PAIR64__(v75, revealTime);
          v77 = v75;
          if ( v76 >= (float)((float)((float)v62 - (float)*(__int64 *)((char *)&v64 - 4))
                            / (float)__SPAIR64__(v75, revealTime)) )
            *((float *)&v164[1] + 1) = 0.0;
          else
            *((float *)&v164[1] + 1) = 1.0;
        }
      }
      _R10 = v164;
      _R9 = &`VertexColorToByteWithScale'::`2'::SIMD_SP_255;
      _R8 = v166.color;
      _R7 = &v166.color[1];
      _R5 = &v166.color[2];
      __asm { lvx128    v62, r0, r10 }
      _R11 = &v166.color[3];
      __asm { lvx128    v63, r0, r9 }
      __asm { vmulfp128 v61, v94, v63 }
      __asm
      {
        vcfpsxws128 v60, v61, 0
        vpkswss128 v59, v92, v60
        vpkshus128 v0, v91, v59
        stvebx    v0, 0, r8
        stvebx    v0, 0, r7
        stvebx    v0, 0, r5
        stvebx    v0, 0, r11
      }
      memset(v166.tangent, 0, sizeof(v166.tangent));
      idRenderModelBeam::DrawBeam(
        this: v33,
        node: &v166,
        mtr: eboltDecl->branchOverride.material,
        type: BEAM_ORIENT_VIEWER);
    }
    return;
  }
  _R16 = 1;
  v167.granularity = 1;
  v167.size = 128;
  v167.num = 0;
  v167.memTag = 5;
  v167.list = v167.staticList;
  v167.listStatic = 1;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v167);
  v86 = 0;
  if ( currSegments->num > 0 )
  {
    v87 = 0;
    do
    {
      SubdivideBolt_r(
        startPos: &currSegments->list[v87].startPos,
        endPos: &currSegments->list[v87].endPos,
        stats: v32,
        diversity,
        subDivisionLevel: 0,
        branchLevel,
        segments: &v167,
        beamModel: v33,
        deviation: maxDeviation,
        eboltDecl: v138,
        numSubdivisions: v139,
        time: v140,
        rnd: v141,
        a14: v142,
        a15: v143,
        a16: v144,
        a17: v145,
        a18: v146,
        a19: v147,
        a20: v148,
        a21: v149,
        a22: v150,
        a23: v151,
        a24: v152,
        a25: v153,
        a26: v154,
        a27: v155,
        a28: v156,
        a29: eboltDecl,
        a30: v157,
        a31,
        a32: v158,
        a33: v37,
        a34: v159,
        a35: v36);
      ++v86;
      ++v87;
    }
    while ( v86 < currSegments->num );
  }
  if ( v167.num == 0 )
  {
    if ( v167.listStatic != 0 && v167.listStatic != 2 )
      return;
    v88 = v167.list;
    if ( v167.list == nullptr )
      return;
    v89 = &mem;
LABEL_99:
    idMem::Free(this: v89, ptr: v88, align: ALIGN_16);
    return;
  }
  v90 = &mem;
  HIDWORD(v160) = &mem;
  valueInteger = g_eboltDebug.valueInteger;
  if ( g_eboltDebug.valueInteger != 0 )
  {
    v92 = 0;
    if ( v167.num > 0 )
    {
      v93 = 0;
      while ( 1 )
      {
        v162 = idColor::colorCyan;
        *(_DWORD *)v94 = &v167.list[v93];
        switch ( valueInteger )
        {
          case 1:
            *(double *)&v95 = 0.5;
            *((double *)&v95 + 1) = (float)(branchLevel | 0x100000000uLL);
            v96 = pow(x: v95, y: v85);
            v97 = (float)(eboltDecl->brightness * (float)*(double *)&v96);
            v162.r = eboltDecl->brightness * (float)*(double *)&v96;
            v162.g = v97;
            v162.b = v97;
            v162.a = v97;
            break;
          case 2:
            v98 = *(float *)(*(_DWORD *)v94 + 24);
            if ( v98 >= 0.0 )
            {
              if ( v98 > 1.0 )
                v98 = 1.0;
            }
            else
            {
              v98 = 0.0;
            }
            _FP13 = (float)((float)0.2 - (float)((float)1.0 - (float)v98));
            __asm { fsel      f12, f13, f29, f0 }
            v162.r = _FP12;
            v162.g = _FP12;
            v162.b = _FP12;
            v162.a = _FP12;
            break;
          case 3:
            *(_DWORD *)&v94[4] = eboltDecl->revealTime;
            if ( *(_DWORD *)&v94[4] != 0
              && (*(_DWORD *)&v94[8] = v32->boltStartTime,
                  v101 = *(_DWORD *)&v94[8] + *(_DWORD *)&v94[4],
                  v37 <= *(_DWORD *)&v94[8] + *(_DWORD *)&v94[4]) )
            {
              v102 = *(float *)(*(_DWORD *)v94 + 24);
              v161 = *(_QWORD *)v94;
              v103 = *(_QWORD *)v94;
              v160 = *(_QWORD *)&v94[4];
              *(_DWORD *)v94 = v37;
              v165[2] = *(_QWORD *)&v94[8];
              if ( v102 >= (float)((float)((float)*(__int64 *)&v94[8] - (float)*(__int64 *)&v94[4]) / (float)v103) )
              {
                v162.r = 0.0;
                v162.g = 0.0;
                v162.b = 0.0;
                v162.a = 0.0;
              }
              else
              {
                v162.r = 1.0;
                v162.g = 1.0;
                v162.b = 1.0;
                v162.a = 1.0;
              }
            }
            else
            {
              v162 = idColor::colorWhite;
            }
            break;
          default:
            break;
        }
        v104 = common->RW(this: common);
        v104->DebugLine(
          this: v104,
          a2: (const idVec4 *)&v162,
          a3: &v167.list[v93].startPos,
          a4: &v167.list[v93].endPos,
          a5: 0,
          a6: false);
        ++v92;
        ++v93;
        if ( v92 >= v167.num )
          break;
        valueInteger = g_eboltDebug.valueInteger;
      }
    }
  }
  else
  {
    *(_QWORD *)&v168.num = 128;
    v168.list = (beamNodeParms_t *)&v169;
    *(_DWORD *)&v168.granularity = 66817;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v168);
    LODWORD(v105) = branchLevel;
    LODWORD(v106) = v167.num;
    *(_QWORD *)&v107 = 0x3FE0000000000000LL;
    v161 = v106;
    *((double *)&v107 + 1) = (float)v105;
    v108 = (float)((float)1.0 / (float)v106);
    v110 = pow(x: v107, y: v109);
    if ( branchLevel <= 0 )
      startWidth = eboltDecl->startWidth;
    else
      startWidth = (float)((float)(eboltDecl->branchStartWidth * (float)*(double *)&v110) * (float)2.0);
    if ( branchLevel <= 0 )
      endWidth = eboltDecl->endWidth;
    else
      endWidth = (float)((float)(eboltDecl->branchEndWidth * (float)*(double *)&v110) * (float)2.0);
    v113 = 0;
    v114 = (float)(eboltDecl->brightness * (float)*(double *)&v110);
    if ( v167.num > 0 )
    {
      v115 = (float)((float)endWidth - (float)startWidth);
      p_color = &eboltDecl->color;
      v117 = 0;
      _R22 = 2;
      _R23 = 3;
      _R25 = &`VertexColorToByteWithScale'::`2'::SIMD_SP_255;
      while ( 1 )
      {
        v121 = &v167.list[v117];
        idList<beamNodeParms_t,5>::PreAllocateWithGranularity(this: &v168, newSize: v168.num + 1);
        num = v168.num;
        if ( v168.num >= v168.size )
        {
          v126 = &v168.list[v168.size - 1];
        }
        else
        {
          ++v168.num;
          v126 = &v168.list[num];
        }
        v126->startPos.x = v121->startPos.x;
        v126->startPos.y = v121->startPos.y;
        v126->startPos.z = v121->startPos.z;
        v126->endPos.x = v121->endPos.x;
        v126->endPos.y = v121->endPos.y;
        v126->endPos.z = v121->endPos.z;
        w = eboltDecl->color.w;
        v128 = eboltDecl->applyGradient;
        v129 = eboltDecl->color.z;
        v130 = (float)(p_color->x * (float)v114);
        v131 = (float)(eboltDecl->color.y * (float)v114);
        v132 = (float)(eboltDecl->color.z * (float)v114);
        *(float *)v165 = p_color->x * (float)v114;
        *(float *)&v165[1] = (float)v129 * (float)v114;
        *((float *)&v165[1] + 1) = (float)w * (float)v114;
        *((float *)v165 + 1) = v131;
        if ( v128 )
        {
          v133 = v121->lengthFrac;
          if ( v133 >= 0.0 )
          {
            if ( v133 > 1.0 )
              v133 = 1.0;
          }
          else
          {
            v133 = 0.0;
          }
          _FP9 = (float)((float)0.2 - (float)((float)1.0 - (float)v133));
          __asm { fsel      f8, f9, f28, f0 }
          *(float *)v165 = (float)v130 * (float)_FP8;
          *((float *)v165 + 1) = (float)v131 * (float)_FP8;
          *(float *)&v165[1] = (float)v132 * (float)_FP8;
          *((float *)&v165[1] + 1) = (float)((float)w * (float)v114) * (float)_FP8;
        }
        DWORD2(_R10) = eboltDecl->revealTime;
        if ( DWORD2(_R10) != 0 )
        {
          LODWORD(_R10) = v32->boltStartTime;
          if ( v37 <= (int)_R10 + DWORD2(_R10) )
          {
            DWORD1(_R10) = v37;
            v136 = v121->lengthFrac;
            v161 = *(_QWORD *)&_R10;
            v165[4] = *(_QWORD *)((char *)&_R10 + 4);
            v165[2] = _R10;
            if ( v136 >= (float)((float)((float)*(__int64 *)&_R10 - (float)(__int64)_R10)
                               / (float)*(__int64 *)((char *)&_R10 + 4)) )
              *((float *)&v165[1] + 1) = 0.0;
            else
              *((float *)&v165[1] + 1) = 1.0;
          }
        }
        DWORD1(_R10) = v113;
        __asm { lvx128    v63, r0, r25 }
        DWORD2(_R10) = v165;
        v165[3] = *(_QWORD *)&_R10;
        LODWORD(_R10) = v126->color;
        __asm { lvx128    v58, r0, r9 }
        ++v113;
        __asm { vmulfp128 v57, v90, v63 }
        ++v117;
        __asm { vcfpsxws128 v56, v57, 0 }
        __asm { vpkswss128 v55, v88, v56 }
        __asm
        {
          vpkshus128 v0, v87, v55
          stvebx    v0, 0, r10
        }
        __asm
        {
          stvebx    v0, r10, r16
          stvebx    v0, r10, r22
          stvebx    v0, r10, r23
        }
        v126->sMinMax.x = (float)*(__int64 *)&_R10 * (float)v108;
        v126->sMinMax.y = (float)((float)*(__int64 *)&_R10 * (float)v108) + (float)v108;
        v126->tMinMax.x = 0.0;
        v126->tMinMax.y = 1.0;
        v137 = v167.num;
        v164[0] = *(_QWORD *)(&v123 - 1);
        v126->halfWidth = (float)((float)((float)v115
                                        * (float)((float)*(__int64 *)&_R10
                                                / (float)((float)*(__int64 *)(&v123 - 1) - (float)1.0)))
                                + (float)startWidth)
                        * (float)0.5;
        v126->orientVec = vec3_origin;
        *(_DWORD *)&v126->tangent[0][0] = 0;
        *(_DWORD *)&v126->tangent[1][0] = 0;
        *(_DWORD *)&v126->tangent[2][0] = 0;
        *(_DWORD *)&v126->tangent[3][0] = 0;
        if ( v113 >= v167.num )
          break;
        v32 = stats;
        _R16 = 1;
        v37 = currTime;
      }
      v90 = (idMem *)HIDWORD(v160);
      v33 = beamModel;
    }
    idRenderModelBeam::DrawBeam(
      this: v33,
      nodes: v168.list,
      numNodes: v168.num,
      mtr: eboltDecl->material,
      type: BEAM_ORIENT_VIEWER);
    if ( v168.listStatic == 0 || v168.listStatic == 2 )
    {
      if ( v168.list != nullptr )
        idMem::Free(this: v90, ptr: v168.list, align: ALIGN_16);
      v168.list = nullptr;
      v168.size = 0;
    }
    v168.num = 0;
  }
  if ( v167.listStatic == 0 || v167.listStatic == 2 )
  {
    v88 = v167.list;
    if ( v167.list != nullptr )
    {
      v89 = v90;
      goto LABEL_99;
    }
  }
}


// ========================================================================
// __unwind$248723
// EA  : 0x8270AED0
// RVA : 0x0070AED0
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void _unwind_248723()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 17008 + 368));
}


// ========================================================================
// __unwind$248724
// EA  : 0x8270AEF8
// RVA : 0x0070AEF8
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void _unwind_248724()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 17008 + 3968));
}


// ========================================================================
// ?Update@idElectricBolt@@QAAXH@Z
// EA  : 0x8270AF28
// RVA : 0x0070AF28
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void __fastcall idElectricBolt::Update(idElectricBolt *this, int currTime)
{
  int v4; // r28
  int v5; // r27
  eboltControlNode_t *v6; // r30
  segment_t *v7; // r3
  int num; // r10
  eboltControlNode_t *list; // r11
  int startTime; // r30
  const idDeclElectricBolt *eboltDecl; // r28
  int v12; // r10
  int diversity; // r8
  idRenderModelBeam *beamModel; // r5
  double v15; // fp8
  long double v16; // fp4
  int v17; // [sp+8h] [-EE8h]
  int v18; // [sp+Ch] [-EE4h]
  int v19; // [sp+10h] [-EE0h]
  int v20; // [sp+14h] [-EDCh]
  int v21; // [sp+18h] [-ED8h]
  int v22; // [sp+1Ch] [-ED4h]
  int v23; // [sp+20h] [-ED0h]
  int v24; // [sp+24h] [-ECCh]
  int v25; // [sp+28h] [-EC8h]
  int v26; // [sp+2Ch] [-EC4h]
  int v27; // [sp+30h] [-EC0h]
  int v28; // [sp+34h] [-EBCh]
  int v29; // [sp+38h] [-EB8h]
  int v30; // [sp+3Ch] [-EB4h]
  int v31; // [sp+40h] [-EB0h]
  int v32; // [sp+44h] [-EACh]
  int v33; // [sp+48h] [-EA8h]
  int v34; // [sp+4Ch] [-EA4h]
  int v35; // [sp+50h] [-EA0h]
  boltStats_t v36; // [sp+70h] [-E80h] BYREF
  idStaticList<segment_t,128> v37; // [sp+90h] [-E60h] BYREF

  if ( this->beamModel != nullptr && this->eboltDecl != nullptr && this->controlNodes.num != 0 )
  {
    v37.granularity = 1;
    v37.num = 0;
    v37.size = 128;
    v37.list = v37.staticList;
    v37.memTag = 5;
    v37.listStatic = 1;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v37);
    v4 = 0;
    if ( this->controlNodes.num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = &this->controlNodes.list[v5];
        v7 = idList<segment_t,5>::Alloc(this: &v37);
        v7->startPos.x = v6->startPos.x;
        ++v4;
        v7->startPos.y = v6->startPos.y;
        ++v5;
        v7->startPos.z = v6->startPos.z;
        v7->endPos = v6->endPos;
        v7->lengthFrac = 1.0;
      }
      while ( v4 < this->controlNodes.num );
    }
    num = this->controlNodes.num;
    list = this->controlNodes.list;
    v36.numNodes = 0;
    v36.numBranches = 0;
    startTime = this->startTime;
    eboltDecl = this->eboltDecl;
    v12 = (int)&list[num];
    diversity = this->diversity;
    beamModel = this->beamModel;
    v15 = (float)(*(float *)(v12 - 8) - list->startPos.y);
    *((double *)&v16 + 1) = (float)((float)((float)(*(float *)(v12 - 12) - list->startPos.x)
                                          * (float)(*(float *)(v12 - 12) - list->startPos.x))
                                  + (float)((float)v15 * (float)v15));
    *(double *)&v16 = (float)((float)((float)(*(float *)(v12 - 4) - list->startPos.z)
                                    * (float)(*(float *)(v12 - 4) - list->startPos.z))
                            + (float)((float)((float)(*(float *)(v12 - 12) - list->startPos.x)
                                            * (float)(*(float *)(v12 - 12) - list->startPos.x))
                                    + (float)((float)v15 * (float)v15)));
    v36.invTotalLength = (float)1.0
                       / (float)((float)((float)(*(float *)(v12 - 4) - list->startPos.z)
                                       * (float)(*(float *)(v12 - 4) - list->startPos.z))
                               + (float)((float)((float)(*(float *)(v12 - 12) - list->startPos.x)
                                               * (float)(*(float *)(v12 - 12) - list->startPos.x))
                                       + (float)((float)v15 * (float)v15)));
    v36.boltStartPos.x = list->startPos.x;
    v36.boltStartPos.y = list->startPos.y;
    v36.boltStartPos.z = list->startPos.z;
    v36.boltStartTime = startTime;
    GenerateBolt(
      currSegments: &v37,
      stats: &v36,
      beamModel,
      eboltDecl,
      currTime,
      diversity,
      branchLevel: 0,
      maxDeviation: eboltDecl->maxDeviation,
      maxSubdivisions: v12,
      a10: v36.invTotalLength,
      a11: v16,
      a12: v17,
      a13: v18,
      a14: v19,
      a15: v20,
      a16: v21,
      a17: v22,
      a18: v23,
      a19: v24,
      a20: v25,
      a21: v26,
      a22: v27,
      a23: v28,
      a24: v29,
      a25: v30,
      a26: v31,
      a27: v32,
      a28: v33,
      a29: v34,
      a30: v35,
      a31: eboltDecl->subdivisions);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v37);
  }
}


// ========================================================================
// __unwind$249412_0
// EA  : 0x8270B0EC
// RVA : 0x0070B0EC
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void _unwind_249412_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 3824 + 144));
}


// ========================================================================
// `dynamic initializer for 'g_eboltDebug''
// EA  : 0x8333F798
// RVA : 0x0133F798
// PDB : w:\tech5\engine\gamelib\effects\electricbolt.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_eboltDebug__()
{
  idCVar::idCVar(
    this: &g_eboltDebug,
    name: "g_eboltDebug",
    value: "0",
    flags: 2,
    description: "1=display wireframe brightness, 2=display wireframe gradient, 3=display wireframe bolt reveal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_eboltDebug__);
}

