
// ========================================================================
// ?Init@idTracerManager@@QAAXPAVidRenderModelEffects@@H@Z
// EA  : 0x827180A8
// RVA : 0x007180A8
// PDB : w:\tech5\engine\gamelib\effects\tracermanager.cpp
// ========================================================================

void __fastcall idTracerManager::Init(idTracerManager *this, idRenderModelEffects *_effectsModel, int playerIndex)
{
  this->effectsModel = _effectsModel;
  this->localPlayerIndex = playerIndex;
}


// ========================================================================
// ?AddTracer@idTracerManager@@QAAXPBVidMaterial@@ABVidVec3@@11MMM_NMH@Z
// EA  : 0x827180B8
// RVA : 0x007180B8
// PDB : w:\tech5\engine\gamelib\effects\tracermanager.cpp
// ========================================================================

void __fastcall idTracerManager::AddTracer(
        idTracerManager *this,
        const idMaterial *mat,
        const idVec3 *origin,
        const idVec3 *dir,
        const idVec3 *maxDist,
        double speed,
        double length,
        double height,
        bool ensureVisual,
        double fractionInsured,
        const int playerIndex,
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
        bool a32,
        int a33,
        int a34,
        int a35,
        int a36)
{
  idRenderModelEffects *effectsModel; // r3
  float *v46; // r11
  float *v47; // r11
  float *v48; // r11

  effectsModel = this->effectsModel;
  if ( effectsModel != nullptr )
    idRenderModelEffects::AddTracer(
      this: effectsModel,
      mat,
      origin,
      dir,
      maxDist,
      speed,
      length,
      height,
      ensureVisual,
      fractionInsured,
      lifeTime: -1.0);
  if ( !this->catchingUp )
  {
    if ( net_tracerMgrDebug.valueInteger != 0 )
      idLib::Printf(
        fmt: "::AddTracer. tracerBufferIndex=%d origin=<%.2f,%.2f,%.2f>\n",
        (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(origin->x)),
        origin->x,
        origin->y,
        origin->z);
    v46 = (float *)((char *)this + 72 * this->tracerBufferPos);
    v46[7] = dir->x;
    v46[8] = dir->y;
    v46[9] = dir->z;
    this->tracerBuffer[this->tracerBufferPos].mat = mat;
    v47 = (float *)((char *)this + 72 * this->tracerBufferPos);
    v47[4] = origin->x;
    v47[5] = origin->y;
    v47[6] = origin->z;
    this->tracerBuffer[this->tracerBufferPos].speed = speed;
    this->tracerBuffer[this->tracerBufferPos].height = height;
    this->tracerBuffer[this->tracerBufferPos].length = length;
    v48 = (float *)((char *)this + 72 * this->tracerBufferPos);
    v48[13] = maxDist->x;
    v48[14] = maxDist->y;
    v48[15] = maxDist->z;
    this->tracerBuffer[this->tracerBufferPos].ensureVisual = a32;
    this->tracerBuffer[this->tracerBufferPos].fractionInsured = fractionInsured;
    this->tracerBuffer[this->tracerBufferPos].playerIndex = a36;
    this->tracerBuffer[this->tracerBufferPos].lifeTime = 0;
    this->tracerBuffer[this->tracerBufferPos].startTime = 0;
    this->tracerBufferPos = (this->tracerBufferPos + 1) % 4;
  }
}


// ========================================================================
// ?Update@idTracerManager@@QAAXH@Z
// EA  : 0x82718300
// RVA : 0x00718300
// PDB : w:\tech5\engine\gamelib\effects\tracermanager.cpp
// ========================================================================

void __fastcall idTracerManager::Update(idTracerManager *this, const int time)
{
  int serializeTracerCount; // r11
  int v4; // r8
  int tracerBufferPos; // r5
  int v6; // r4
  float *v7; // r11
  float *v8; // r30
  double v9; // fp31
  char v10; // r26
  double v11; // fp30
  const idMaterial *v12; // r25
  double v13; // fp29
  double v14; // fp28
  const idVec3 *v15; // r29
  const idVec3 *v16; // r28
  const idVec3 *v17; // r30
  float *v18; // r11
  float *v19; // r11
  float *v20; // r11
  int v21; // r11
  int v22; // r11

  serializeTracerCount = this->serializeTracerCount;
  this->catchingUp = true;
  if ( serializeTracerCount > 0 )
  {
    v4 = 0x82000000;
    do
    {
      tracerBufferPos = this->tracerBufferPos;
      v6 = this->serializeTracerCount - 1;
      this->serializeTracerCount = v6;
      v7 = (float *)((char *)this + 72 * tracerBufferPos);
      v8 = v7 + 1;
      if ( net_tracerMgrDebug.valueInteger != 0 )
        idLib::Printf(
          fmt: "::Update. serializeTracerCount=%d tracerBufferIndex=%d origin=<%.2f,%.2f,%.2f>\n",
          v6,
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v7[4])),
          v7[4],
          v7[5],
          v7[6]);
      if ( *((_DWORD *)v8 + 17) != this->localPlayerIndex )
      {
        v9 = v8[16];
        v10 = *((_BYTE *)v8 + 60);
        v11 = v8[10];
        v12 = *((const idMaterial **)v8 + 11);
        v13 = v8[9];
        v14 = v8[2];
        v15 = (const idVec3 *)(v8 + 12);
        v16 = (const idVec3 *)(v8 + 6);
        v17 = (const idVec3 *)(v8 + 3);
        if ( this->effectsModel != nullptr )
          idRenderModelEffects::AddTracer(
            this: this->effectsModel,
            mat: v12,
            origin: v17,
            dir: v16,
            maxDist: v15,
            speed: v14,
            length: v13,
            height: v11,
            ensureVisual: v4,
            fractionInsured: v9,
            lifeTime: -1.0);
        if ( !this->catchingUp )
        {
          if ( net_tracerMgrDebug.valueInteger != 0 )
            idLib::Printf(
              fmt: "::AddTracer. tracerBufferIndex=%d origin=<%.2f,%.2f,%.2f>\n",
              this->tracerBufferPos,
              v17->x,
              v17->y,
              v17->z);
          v18 = (float *)((char *)this + 72 * this->tracerBufferPos);
          v18[7] = v16->x;
          v18[8] = v16->y;
          v18[9] = v16->z;
          this->tracerBuffer[this->tracerBufferPos].mat = v12;
          v19 = (float *)((char *)this + 72 * this->tracerBufferPos);
          v19[4] = v17->x;
          v19[5] = v17->y;
          v19[6] = v17->z;
          this->tracerBuffer[this->tracerBufferPos].speed = v14;
          this->tracerBuffer[this->tracerBufferPos].height = v11;
          this->tracerBuffer[this->tracerBufferPos].length = v13;
          v20 = (float *)((char *)this + 72 * this->tracerBufferPos);
          v20[13] = v15->x;
          v20[14] = v15->y;
          v20[15] = v15->z;
          this->tracerBuffer[this->tracerBufferPos].ensureVisual = v10;
          this->tracerBuffer[this->tracerBufferPos].fractionInsured = v9;
          this->tracerBuffer[this->tracerBufferPos].playerIndex = 0;
          this->tracerBuffer[this->tracerBufferPos].lifeTime = 0;
          this->tracerBuffer[this->tracerBufferPos].startTime = 0;
          this->tracerBufferPos = (this->tracerBufferPos + 1) % 4;
        }
      }
      v21 = this->tracerBufferPos + 1;
      v4 = 4 * (v21 / 4);
      this->tracerBufferPos = v21 % 4;
    }
    while ( this->serializeTracerCount > 0 );
  }
  v22 = this->serializeTracerCount;
  this->catchingUp = false;
  this->serializeTracerCount = v22 - 1;
}


// ========================================================================
// ??0idTracerManager@@QAA@XZ
// EA  : 0x827186F0
// RVA : 0x007186F0
// PDB : w:\tech5\engine\gamelib\effects\tracermanager.cpp
// ========================================================================

idTracerManager *__fastcall idTracerManager::idTracerManager(idTracerManager *this)
{
  this->effectsModel = nullptr;
  this->tracerBufferPos = 0;
  this->serializeTracerCount = 0;
  this->catchingUp = false;
  this->localPlayerIndex = 0;
  memset(Dst: this->tracerBuffer, Val: 0, Size: sizeof(this->tracerBuffer));
  return this;
}


// ========================================================================
// ?Serialize@idTracerManager@@QAAXAAVidSerializer@@@Z
// EA  : 0x82718BE0
// RVA : 0x00718BE0
// PDB : w:\tech5\engine\gamelib\effects\tracermanager.cpp
// ========================================================================

void __fastcall idTracerManager::Serialize(idTracerManager *this, idSerializer *ser)
{
  int tracerBufferPos; // r26
  idBitMsg *msg; // r3
  unsigned int v6; // r10
  idVec3 *p_origin; // r30
  int i; // r28
  idBitMsg *v9; // r3
  idVec3 *v10; // r4
  idBitMsg *v11; // r3
  idBitMsg *v12; // r3
  idVec3 *v13; // r4
  idBitMsg *v14; // r3
  char x_high; // r29
  idBitMsg *v16; // r3
  int v17; // r11
  int serializeTracerCount; // r4

  tracerBufferPos = this->tracerBufferPos;
  msg = ser->msg;
  v6 = _cntlzw(3u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: tracerBufferPos, numBits: 32 - v6);
  else
    tracerBufferPos = idBitMsg::ReadBits(this: msg, numBits: 32 - v6);
  p_origin = &this->tracerBuffer[0].origin;
  for ( i = 4; i != 0; --i )
  {
    idSerializer::SerializeQ<32768,12>(this: ser, value: &p_origin[-1].z);
    v9 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteQuantizedVector<idVec3,32768,12>(this: v9, v: p_origin);
    else
      idBitMsg::ReadQuantizedVector<idVec3,32768,12>(this: v9, v: p_origin);
    v10 = p_origin + 1;
    v11 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteQuantizedVector<idVec3,1,12>(this: v11, v: v10);
    else
      idBitMsg::ReadQuantizedVector<idVec3,1,12>(this: v11, v: v10);
    idSerializer::SerializeQ<1024,10>(this: ser, value: &p_origin[2].x);
    idSerializer::SerializeQ<1024,10>(this: ser, value: &p_origin[2].y);
    idSerializer::Serialize<idMaterial>(this: ser, decl: (const idDecl **)&p_origin[2].z);
    v12 = ser->msg;
    v13 = p_origin + 3;
    if ( ser->writing )
      idBitMsg::WriteQuantizedVector<idVec3,256,8>(this: v12, v: v13);
    else
      idBitMsg::ReadQuantizedVector<idVec3,256,8>(this: v12, v: v13);
    idSerializer::SerializeQ<256,8>(this: ser, value: &p_origin[4].y);
    v14 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v14, value: LODWORD(p_origin[4].z), numBits: 32);
    else
      LODWORD(p_origin[4].z) = idBitMsg::ReadBits(this: v14, numBits: 32);
    x_high = HIBYTE(p_origin[4].x);
    v16 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v16, value: HIBYTE(p_origin[4].x), numBits: 1);
    else
      x_high = (_cntlzw(idBitMsg::ReadBits(this: v16, numBits: 1) - 1) & 0x20) != 0;
    HIBYTE(p_origin[4].x) = x_high;
    p_origin += 6;
  }
  v17 = tracerBufferPos - this->tracerBufferPos;
  if ( v17 >= 4 )
    v17 = 4;
  this->serializeTracerCount = v17;
  if ( v17 < 0 )
    this->serializeTracerCount = v17 + 4;
  if ( net_tracerMgrDebug.valueInteger != 0 )
  {
    serializeTracerCount = this->serializeTracerCount;
    if ( serializeTracerCount != 0 )
      idLib::Printf(fmt: "::Serialize. serializeTracerCount=%d\n", serializeTracerCount);
  }
}


// ========================================================================
// `dynamic initializer for 'net_tracerMgrDebug''
// EA  : 0x8333FA40
// RVA : 0x0133FA40
// PDB : w:\tech5\engine\gamelib\effects\tracermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_tracerMgrDebug__()
{
  idCVar::idCVar(
    this: &net_tracerMgrDebug,
    name: "net_tracerMgrDebug",
    value: "0",
    flags: 1,
    description: "net_tracerMgrDebug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_tracerMgrDebug__);
}

