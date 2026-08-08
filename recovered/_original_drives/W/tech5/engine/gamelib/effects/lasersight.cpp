
// ========================================================================
// ??0idLaserBeam@@QAA@XZ
// EA  : 0x82714D40
// RVA : 0x00714D40
// PDB : w:\tech5\engine\gamelib\effects\lasersight.cpp
// ========================================================================

idLaserBeam *__fastcall idLaserBeam::idLaserBeam(idLaserBeam *this)
{
  this->material = nullptr;
  this->height = 1.0;
  return this;
}


// ========================================================================
// ?Init@idLaserSight@@QAAXPAVidRenderModelBeam@@PAVidRenderModelDecal@@PBVidMaterial@@M2MMMM_N@Z
// EA  : 0x82714D58
// RVA : 0x00714D58
// PDB : w:\tech5\engine\gamelib\effects\lasersight.cpp
// ========================================================================

void __fastcall idLaserSight::Init(
        idLaserSight *this,
        idRenderModelBeam *_beamEffects,
        idRenderModelDecal *_decalEffects,
        const idMaterial *laserBeamMtr,
        double laserBeamHeight,
        const idMaterial *laserPointMtr,
        double laserPointSize,
        double laserPointDepth,
        double fadeIn,
        double fadeOut,
        const idMaterial *isQuad,
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
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        bool a37)
{
  this->laserBeam.height = laserBeamHeight;
  this->laserEndPoint.size = laserPointSize;
  this->beamEffects = _beamEffects;
  this->laserEndPoint.depth = laserPointDepth;
  this->decalEffects = _decalEffects;
  this->fadeInDuration = fadeIn;
  this->laserBeam.material = laserBeamMtr;
  this->fadeOutDuration = fadeOut;
  this->laserEndPoint.material = isQuad;
  this->laserEndPoint.quad = a37;
  this->initialized = true;
  this->hidden = false;
}


// ========================================================================
// ??0idLaserSight@@QAA@XZ
// EA  : 0x82714D98
// RVA : 0x00714D98
// PDB : w:\tech5\engine\gamelib\effects\lasersight.cpp
// ========================================================================

idLaserSight *__fastcall idLaserSight::idLaserSight(idLaserSight *this)
{
  this->initialized = false;
  this->hidden = false;
  this->laserBeam.height = 1.0;
  this->laserBeam.material = nullptr;
  this->laserEndPoint.material = nullptr;
  this->laserEndPoint.size = 1.0;
  this->laserEndPoint.depth = 8.0;
  this->laserEndPoint.handle.value = -1;
  this->laserEndPoint.quad = false;
  this->fadeInDuration = 1.0;
  this->fadeOutDuration = 1.0;
  this->beamEffects = nullptr;
  this->decalEffects = nullptr;
  return this;
}


// ========================================================================
// ?Shutdown@idLaserSight@@QAAXXZ
// EA  : 0x82714DE8
// RVA : 0x00714DE8
// PDB : w:\tech5\engine\gamelib\effects\lasersight.cpp
// ========================================================================

void __fastcall idLaserSight::Shutdown(idLaserSight *this)
{
  idRenderModelDecal *decalEffects; // r3

  decalEffects = this->decalEffects;
  this->initialized = false;
  if ( decalEffects != nullptr && this->laserEndPoint.handle.value != -1 )
    ((void (__fastcall *)(idRenderModelDecal *))decalEffects->RemoveDecal)(a1: decalEffects);
}


// ========================================================================
// ?Show@idLaserSight@@QAAXH@Z
// EA  : 0x82714E20
// RVA : 0x00714E20
// PDB : w:\tech5\engine\gamelib\effects\lasersight.cpp
// ========================================================================

void __fastcall idLaserSight::Show(idLaserSight *this, int startTime)
{
  idRenderModelDecal *decalEffects; // r11
  const idMaterial *material; // r9
  bool quad; // r9
  double size; // fp13
  char v6; // [sp+50h] [-50h] BYREF
  const idMaterial *v7; // [sp+60h] [-40h] BYREF
  float depth; // [sp+64h] [-3Ch]
  float v9; // [sp+68h] [-38h]
  float v10; // [sp+6Ch] [-34h]
  float v11; // [sp+70h] [-30h]
  int v12; // [sp+74h] [-2Ch]
  int v13; // [sp+78h] [-28h]
  int v14; // [sp+7Ch] [-24h]
  bool v15; // [sp+80h] [-20h]

  if ( this->initialized && this->hidden )
  {
    decalEffects = this->decalEffects;
    this->hidden = false;
    if ( decalEffects != nullptr )
    {
      material = this->laserEndPoint.material;
      v14 = 0;
      v15 = false;
      v7 = material;
      v12 = 10000;
      v13 = 2000;
      depth = 8.0;
      v9 = 32.0;
      v10 = 32.0;
      v11 = 0.0;
      if ( material != nullptr )
      {
        quad = this->laserEndPoint.quad;
        size = this->laserEndPoint.size;
        depth = this->laserEndPoint.depth;
        v12 = -1;
        v9 = size;
        v15 = quad;
        v10 = size;
        v11 = 0.0099999998;
        this->laserEndPoint.handle.value = decalEffects->AddDecalFromPoint(
                                             this: (idRenderModel *)&v6,
                                             result: (idHandle<int,enum invalidDecalHandle_t,-1> *)decalEffects,
                                             a3: (const decalParams_t *)&v7,
                                             a4: startTime,
                                             a5: &vec3_origin,
                                             a6: &vec3_origin,
                                             a7: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value)->value;
      }
    }
  }
}


// ========================================================================
// ?Hide@idLaserSight@@QAAXXZ
// EA  : 0x82714F38
// RVA : 0x00714F38
// PDB : w:\tech5\engine\gamelib\effects\lasersight.cpp
// ========================================================================

void __fastcall idLaserSight::Hide(idLaserSight *this)
{
  idRenderModelDecal *decalEffects; // r3

  if ( this->initialized && !this->hidden )
  {
    decalEffects = this->decalEffects;
    this->hidden = true;
    if ( decalEffects != nullptr )
    {
      if ( this->laserEndPoint.handle.value != -1 )
        ((void (__fastcall *)(idRenderModelDecal *))decalEffects->RemoveDecal)(a1: decalEffects);
      this->laserEndPoint.handle.value = -1;
    }
  }
}


// ========================================================================
// ?Update@idLaserBeam@@QAAXPAVidRenderModelBeam@@ABVidVec3@@1M@Z
// EA  : 0x82714FB0
// RVA : 0x00714FB0
// PDB : w:\tech5\engine\gamelib\effects\lasersight.cpp
// ========================================================================

void __fastcall idLaserBeam::Update(
        idLaserBeam *this,
        idRenderModelBeam *beamEffects,
        const idVec3 *startPos,
        const idVec3 *endPos,
        double fade)
{
  int v5; // r9
  double x; // fp8
  double y; // fp7
  double z; // fp6
  double v9; // fp5
  double v10; // fp4
  double v11; // fp2
  double v12; // fp3
  const idMaterial *material; // r5
  beamNodeParms_t v14; // [sp+60h] [-80h] BYREF

  if ( beamEffects != nullptr )
  {
    v5 = (int)(float)((float)fade * (float)255.89999);
    if ( v5 >= 0 )
    {
      if ( v5 > 255 )
        LOBYTE(v5) = -1;
    }
    else
    {
      LOBYTE(v5) = 0;
    }
    x = startPos->x;
    y = startPos->y;
    z = startPos->z;
    v9 = endPos->x;
    v10 = endPos->y;
    v11 = (float)(this->height * (float)0.5);
    v14.color[0] = -1;
    v12 = endPos->z;
    v14.color[1] = -1;
    v14.color[2] = -1;
    v14.color[3] = v5;
    *(_WORD *)&v14.tangent[0][0] = -32640;
    v14.startPos.x = x;
    v14.tangent[0][2] = 0x80;
    v14.startPos.y = y;
    v14.startPos.z = z;
    *(_WORD *)&v14.tangent[1][0] = -32640;
    v14.endPos.x = v9;
    v14.tangent[1][2] = 0x80;
    v14.sMinMax.x = 0.0;
    v14.endPos.y = v10;
    *(_WORD *)&v14.tangent[2][0] = -32640;
    v14.sMinMax.y = 1.0;
    v14.tangent[2][2] = 0x80;
    v14.endPos.z = v12;
    v14.tMinMax.x = 0.0;
    *(_WORD *)&v14.tangent[3][0] = -32640;
    v14.tMinMax.y = 1.0;
    v14.tangent[3][2] = 0x80;
    v14.halfWidth = v11;
    v14.orientVec.x = vec3_origin.x;
    v14.orientVec.y = vec3_origin.y;
    material = this->material;
    v14.orientVec.z = vec3_origin.z;
    idRenderModelBeam::DrawBeam(this: beamEffects, node: &v14, mtr: material, type: BEAM_ORIENT_VIEWER);
  }
}


// ========================================================================
// ??1idLaserSight@@QAA@XZ
// EA  : 0x82715100
// RVA : 0x00715100
// PDB : w:\tech5\engine\gamelib\effects\lasersight.cpp
// ========================================================================

void __fastcall idLaserSight::~idLaserSight(idLaserSight *this)
{
  idRenderModelDecal *decalEffects; // r3

  decalEffects = this->decalEffects;
  this->initialized = false;
  if ( decalEffects != nullptr && this->laserEndPoint.handle.value != -1 )
    ((void (__fastcall *)(idRenderModelDecal *))decalEffects->RemoveDecal)(a1: decalEffects);
  this->beamEffects = nullptr;
  this->decalEffects = nullptr;
}


// ========================================================================
// ?Update@idLaserSight@@QAAXABVidVec3@@0ABVidMat3@@MM@Z
// EA  : 0x82715168
// RVA : 0x00715168
// PDB : w:\tech5\engine\gamelib\effects\lasersight.cpp
// ========================================================================

void __fastcall idLaserSight::Update(
        idLaserSight *this,
        const idVec3 *startPos,
        const idVec3 *endPos,
        const idMat3 *axis,
        double sizeScale,
        double fade)
{
  idRenderModelDecal *decalEffects; // r3

  if ( !this->hidden )
  {
    idLaserBeam::Update(this: &this->laserBeam, beamEffects: this->beamEffects, startPos, endPos, fade);
    decalEffects = this->decalEffects;
    if ( decalEffects != nullptr )
      idRenderModelDecal::SetDecalAttributes(
        this: decalEffects,
        decalHandle: (const idHandle<int,enum invalidDecalHandle_t,-1> *)this->laserEndPoint.handle.value,
        decalWorldPosition: endPos,
        decalWorldAxis: axis,
        sizeScale: (float)((float)sizeScale * (float)fade));
  }
}

