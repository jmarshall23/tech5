
// ========================================================================
// ?SerializeBoolNonRef@idSerializer@@QAA_N_N@Z
// EA  : 0x82659918
// RVA : 0x00659918
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

BOOL __fastcall idSerializer::SerializeBoolNonRef(idSerializer *this, int value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3

  writing = this->writing;
  msg = this->msg;
  if ( !writing )
    return (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  idBitMsg::WriteBits(this: msg, (unsigned __int8)value, numBits: 1);
  return value;
}


// ========================================================================
// ?Serialize@idSerializer@@QAAXAAH@Z
// EA  : 0x82659988
// RVA : 0x00659988
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize(idSerializer *this, int *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3

  writing = this->writing;
  msg = this->msg;
  if ( writing )
    idBitMsg::WriteBits(this: msg, value: *value, numBits: 32);
  else
    *value = idBitMsg::ReadBits(this: msg, numBits: 32);
}


// ========================================================================
// ?Serialize@idSerializer@@QAAXAAM@Z
// EA  : 0x826599F0
// RVA : 0x006599F0
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3

  writing = this->writing;
  msg = this->msg;
  if ( writing )
    idBitMsg::WriteBits(this: msg, value: COERCE_INT(*value), numBits: 32);
  else
    *(_DWORD *)value = idBitMsg::ReadBits(this: msg, numBits: 32);
}


// ========================================================================
// ?SerializeUMax@idSerializer@@QAAXAAHH@Z
// EA  : 0x826CADF0
// RVA : 0x006CADF0
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeUMax(idSerializer *this, int *value, unsigned int maxSize)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  unsigned int v5; // r11
  bool v6; // zf

  writing = this->writing;
  msg = this->msg;
  v6 = !writing;
  v5 = _cntlzw(maxSize);
  if ( v6 )
    *value = idBitMsg::ReadBits(this: msg, numBits: 32 - v5);
  else
    idBitMsg::WriteBits(this: msg, value: *value, numBits: 32 - v5);
}


// ========================================================================
// ?Serialize@idSerializer@@QAAXAAVidVec3@@@Z
// EA  : 0x826CAE58
// RVA : 0x006CAE58
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize(idSerializer *this, idVec3 *value)
{
  float *p_z; // r30
  idBitMsg *msg; // r29
  int v4; // r31

  p_z = &value[-1].z;
  msg = this->msg;
  v4 = 3;
  if ( this->writing )
  {
    do
    {
      idBitMsg::WriteBits(this: msg, value: COERCE_INT(*++p_z), numBits: 32);
      --v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    do
    {
      --v4;
      *(_DWORD *)++p_z = idBitMsg::ReadBits(this: msg, numBits: 32);
    }
    while ( v4 != 0 );
  }
}


// ========================================================================
// ??$Serialize@VidDeclAF@@@idSerializer@@QAAXAAPBVidDeclAF@@@Z
// EA  : 0x826CB198
// RVA : 0x006CB198
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclAF>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  idResource *v7; // r30
  const idDeclAF *v8; // r3
  int v9[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v9[0] = idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v9, maxSize: 0xFFFFu);
  }
  else
  {
    v9[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v9, maxSize: 0xFFFFu);
    v5 = v9[0];
    if ( v9[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      v7 = (idResource *)idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = (const idDeclAF *)_RTDynamicCast(
                               inptr: v7,
                               VfDelta: 0,
                               SrcType: &idResource `RTTI Type Descriptor',
                               TargetType: (void *)&idDeclAF `RTTI Type Descriptor',
                               isReference: 0);
      *decl = v8;
      if ( v8 == nullptr && v7 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclAF::resourceList.name,
          v7->name.str,
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ?Serialize@idSerializer@@QAAXAAG@Z
// EA  : 0x826E3100
// RVA : 0x006E3100
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize(idSerializer *this, unsigned __int16 *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3

  writing = this->writing;
  msg = this->msg;
  if ( writing )
    idBitMsg::WriteBits(this: msg, value: *value, numBits: 16);
  else
    *value = idBitMsg::ReadBits(this: msg, numBits: 16);
}


// ========================================================================
// ??$Serialize@VidDeclWalkIK@@@idSerializer@@QAAXAAPBVidDeclWalkIK@@@Z
// EA  : 0x826E4998
// RVA : 0x006E4998
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclWalkIK>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  idResource *v7; // r30
  const idDeclWalkIK *v8; // r3
  int v9[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v9[0] = idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v9, maxSize: 0xFFFFu);
  }
  else
  {
    v9[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v9, maxSize: 0xFFFFu);
    v5 = v9[0];
    if ( v9[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      v7 = (idResource *)idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = (const idDeclWalkIK *)_RTDynamicCast(
                                   inptr: v7,
                                   VfDelta: 0,
                                   SrcType: &idResource `RTTI Type Descriptor',
                                   TargetType: (void *)&idDeclWalkIK `RTTI Type Descriptor',
                                   isReference: 0);
      *decl = v8;
      if ( v8 == nullptr && v7 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclWalkIK::resourceList.name,
          v7->name.str,
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclReachIK@@@idSerializer@@QAAXAAPBVidDeclReachIK@@@Z
// EA  : 0x826E4AB8
// RVA : 0x006E4AB8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclReachIK>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  idResource *v7; // r30
  const idDeclReachIK *v8; // r3
  int v9[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v9[0] = idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v9, maxSize: 0xFFFFu);
  }
  else
  {
    v9[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v9, maxSize: 0xFFFFu);
    v5 = v9[0];
    if ( v9[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      v7 = (idResource *)idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = (const idDeclReachIK *)_RTDynamicCast(
                                    inptr: v7,
                                    VfDelta: 0,
                                    SrcType: &idResource `RTTI Type Descriptor',
                                    TargetType: (void *)&idDeclReachIK `RTTI Type Descriptor',
                                    isReference: 0);
      *decl = v8;
      if ( v8 == nullptr && v7 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclReachIK::resourceList.name,
          v7->name.str,
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclVehicleProps@@@idSerializer@@QAAXAAPBVidDeclVehicleProps@@@Z
// EA  : 0x826EE0E0
// RVA : 0x006EE0E0
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclVehicleProps>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  idResource *v7; // r30
  const idDeclVehicleProps *v8; // r3
  int v9[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v9[0] = idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v9, maxSize: 0xFFFFu);
  }
  else
  {
    v9[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v9, maxSize: 0xFFFFu);
    v5 = v9[0];
    if ( v9[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      v7 = (idResource *)idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = (const idDeclVehicleProps *)_RTDynamicCast(
                                         inptr: v7,
                                         VfDelta: 0,
                                         SrcType: &idResource `RTTI Type Descriptor',
                                         TargetType: (void *)&idDeclVehicleProps `RTTI Type Descriptor',
                                         isReference: 0);
      *decl = v8;
      if ( v8 == nullptr && v7 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclVehicleProps::resourceList.name,
          v7->name.str,
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$SerializeUQ@$00$03@idSerializer@@QAAXAAM@Z
// EA  : 0x826EE200
// RVA : 0x006EE200
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeUQ<1,4>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v4; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v4 = (int)(float)(*value * (float)15.0);
    if ( v4 >= 0 )
    {
      if ( v4 > 15 )
        v4 = 15;
      idBitMsg::WriteBits(this: msg, value: v4, numBits: 4);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: 0, numBits: 4);
    }
  }
  else
  {
    *value = (float)__SPAIR64__(&unk_821C0000, idBitMsg::ReadBits(this: msg, numBits: 4)) * (float)0.06666667;
  }
}


// ========================================================================
// ??$SerializeQ@$0FK@$07@idSerializer@@QAAXAAM@Z
// EA  : 0x826EE2D8
// RVA : 0x006EE2D8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeQ<90,8>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v4; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v4 = (int)*value;
    if ( v4 >= -127 )
    {
      if ( v4 > 127 )
        v4 = 127;
      idBitMsg::WriteBits(this: msg, value: v4, numBits: -8);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: -127, numBits: -8);
    }
  }
  else
  {
    *value = (float)__SPAIR64__("_AI_OBSTACLE", idBitMsg::ReadBits(this: msg, numBits: -8)) * (float)0.70866144;
  }
}


// ========================================================================
// ?SerializeUMaxNonRef@idSerializer@@QAAHHH@Z
// EA  : 0x826F3068
// RVA : 0x006F3068
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

int __fastcall idSerializer::SerializeUMaxNonRef(idSerializer *this, int value, unsigned int maxSize)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  unsigned int v6; // r11
  bool v7; // zf

  writing = this->writing;
  msg = this->msg;
  v7 = !writing;
  v6 = _cntlzw(maxSize);
  if ( v7 )
    return idBitMsg::ReadBits(this: msg, numBits: 32 - v6);
  idBitMsg::WriteBits(this: msg, value, numBits: 32 - v6);
  return value;
}


// ========================================================================
// ?Serialize@idSerializer@@QAAXAAE@Z
// EA  : 0x826F30D0
// RVA : 0x006F30D0
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize(idSerializer *this, unsigned __int8 *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3

  writing = this->writing;
  msg = this->msg;
  if ( writing )
    idBitMsg::WriteBits(this: msg, value: *value, numBits: 8);
  else
    *value = idBitMsg::ReadBits(this: msg, numBits: 8);
}


// ========================================================================
// ?SerializeQ@idSerializer@@QAAXAAVidMat3@@H@Z
// EA  : 0x8270B1B8
// RVA : 0x0070B1B8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeQ(idSerializer *this, idQuat *axis, int bits, __int64 a4)
{
  double v7; // fp29
  int v8; // r31
  int v9; // r6
  int v10; // r4
  double v11; // fp0
  double v12; // fp31
  double v13; // fp30
  int v14; // r28
  int v15; // r29
  double v16; // fp30
  __int64 v17; // r10
  double v18; // fp29
  __int64 v19; // r9
  double v20; // fp28
  __int64 v21; // r8
  idMat3 v22[2]; // [sp+60h] [-90h] BYREF

  LODWORD(a4) = (1 << (bits - 1)) - 1;
  v7 = (float)a4;
  if ( this->writing )
  {
    idMat3::ToQuat(this: v22, result: axis);
    v8 = __fabs(v22[0].mat[0].y) > __fabs(v22[0].mat[0].x);
    if ( __fabs(v22[0].mat[0].z) > __fabs(*(&v22[0].mat[0].x + v8)) )
      v8 = 2;
    if ( __fabs(v22[0].mat[1].x) > __fabs(*(&v22[0].mat[0].x + v8)) )
      v8 = 3;
    idBitMsg::WriteBits(this: this->msg, value: v8, numBits: 2);
    v9 = (4 * (v8 - 2)) & 0xC;
    v10 = (4 * (v8 - 1)) & 0xC;
    v11 = *(float *)((char *)&v22[0].mat[0].x + ((4 * (v8 + 1)) & 0xC));
    if ( *(&v22[0].mat[0].x + v8) >= 0.0 )
    {
      v12 = *(float *)((char *)&v22[0].mat[0].x + v9);
      v13 = *(float *)((char *)&v22[0].mat[0].x + v10);
    }
    else
    {
      v11 = -v11;
      v12 = -*(float *)((char *)&v22[0].mat[0].x + v9);
      v13 = -*(float *)((char *)&v22[0].mat[0].x + v10);
    }
    idBitMsg::WriteBits(this: this->msg, value: (int)(float)((float)v11 * (float)v7), numBits: -bits);
    idBitMsg::WriteBits(this: this->msg, value: (int)(float)((float)v12 * (float)v7), numBits: -bits);
    idBitMsg::WriteBits(this: this->msg, value: (int)(float)((float)v13 * (float)v7), numBits: -bits);
  }
  else
  {
    v14 = -bits;
    v15 = idBitMsg::ReadBits(this: this->msg, numBits: 2);
    v16 = (float)((float)1.0 / (float)v7);
    LODWORD(v17) = idBitMsg::ReadBits(this: this->msg, numBits: v14);
    v18 = (float)((float)v17 * (float)((float)1.0 / (float)v7));
    LODWORD(v19) = idBitMsg::ReadBits(this: this->msg, numBits: v14);
    v20 = (float)((float)v19 * (float)v16);
    LODWORD(v21) = idBitMsg::ReadBits(this: this->msg, numBits: v14);
    HIDWORD(v21) = v15 + 1;
    *(float *)((char *)&v22[0].mat[1].y + ((4 * (v15 + 1)) & 0xC)) = v18;
    *(float *)((char *)&v22[0].mat[1].y + ((4 * (v15 - 2)) & 0xC)) = v20;
    *(float *)((char *)&v22[0].mat[1].y + ((4 * (v15 - 1)) & 0xC)) = (float)v21 * (float)v16;
    *(&v22[0].mat[1].y + v15) = __fsqrts(__fabs((float)-(float)((float)((float)((float)v21 * (float)v16)
                                                                      * (float)((float)v21 * (float)v16))
                                                              - (float)-(float)((float)((float)v20 * (float)v20)
                                                                              - (float)-(float)((float)((float)v18 * (float)v18)
                                                                                              - (float)1.0)))));
    *(idMat3 *)&axis->x = *idQuat::ToMat3(this: (idQuat *)&v22[0].mat[2].z, result: (idMat3 *)&v22[0].mat[1].y);
  }
}


// ========================================================================
// ??$Serialize@VidDeclParticle@@@idSerializer@@QAAXAAPBVidDeclParticle@@@Z
// EA  : 0x82713D30
// RVA : 0x00713D30
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclParticle>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclParticle *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclParticle *)_RTDynamicCast(
                                     inptr: v7,
                                     VfDelta: 0,
                                     SrcType: &idResource `RTTI Type Descriptor',
                                     TargetType: (void *)&idDeclParticle `RTTI Type Descriptor',
                                     isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclParticle::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$SerializeQ@$0IAAA@$0M@@idSerializer@@QAAXAAM@Z
// EA  : 0x82718748
// RVA : 0x00718748
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeQ<32768,12>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v4; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v4 = (int)(float)(*value * (float)0.062469482);
    if ( v4 >= -2047 )
    {
      if ( v4 > 2047 )
        v4 = 2047;
      idBitMsg::WriteBits(this: msg, value: v4, numBits: -12);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: -2047, numBits: -12);
    }
  }
  else
  {
    *value = (float)__SPAIR64__("_AI_OBSTACLE", idBitMsg::ReadBits(this: msg, numBits: -12)) * (float)16.007816;
  }
}


// ========================================================================
// ??$SerializeQ@$0EAA@$09@idSerializer@@QAAXAAM@Z
// EA  : 0x82718820
// RVA : 0x00718820
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeQ<1024,10>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v4; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v4 = (int)(float)(*value * (float)0.49902344);
    if ( v4 >= -511 )
    {
      if ( v4 > 511 )
        v4 = 511;
      idBitMsg::WriteBits(this: msg, value: v4, numBits: -10);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: -511, numBits: -10);
    }
  }
  else
  {
    *value = (float)__SPAIR64__(&unk_821F0000, idBitMsg::ReadBits(this: msg, numBits: -10)) * (float)2.0039139;
  }
}


// ========================================================================
// ??$Serialize@VidMaterial@@@idSerializer@@QAAXAAPBVidMaterial@@@Z
// EA  : 0x827188F8
// RVA : 0x007188F8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idMaterial>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idMaterial *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idMaterial *)_RTDynamicCast(
                                 inptr: v7,
                                 VfDelta: 0,
                                 SrcType: &idResource `RTTI Type Descriptor',
                                 TargetType: (void *)&idMaterial `RTTI Type Descriptor',
                                 isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idMaterial::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$SerializeQ@$0BAA@$07@idSerializer@@QAAXAAM@Z
// EA  : 0x82718A18
// RVA : 0x00718A18
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeQ<256,8>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v4; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v4 = (int)(float)(*value * (float)0.49609375);
    if ( v4 >= -127 )
    {
      if ( v4 > 127 )
        v4 = 127;
      idBitMsg::WriteBits(this: msg, value: v4, numBits: -8);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: -127, numBits: -8);
    }
  }
  else
  {
    *value = (float)__SPAIR64__(&unk_821F0000, idBitMsg::ReadBits(this: msg, numBits: -8)) * (float)2.015748;
  }
}


// ========================================================================
// ?Serialize@idSerializer@@QAAXAAVidVec6@@@Z
// EA  : 0x8271A4C8
// RVA : 0x0071A4C8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize(idSerializer *this, idVec6 *value)
{
  float *v2; // r30
  idBitMsg *msg; // r29
  int v4; // r31

  v2 = &value[-1].p[5];
  msg = this->msg;
  v4 = 6;
  if ( this->writing )
  {
    do
    {
      idBitMsg::WriteBits(this: msg, value: COERCE_INT(*++v2), numBits: 32);
      --v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    do
    {
      --v4;
      *(_DWORD *)++v2 = idBitMsg::ReadBits(this: msg, numBits: 32);
    }
    while ( v4 != 0 );
  }
}


// ========================================================================
// ?Serialize@idSerializer@@QAAXAAVidMat3@@@Z
// EA  : 0x8271A538
// RVA : 0x0071A538
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize(idSerializer *this, idMat3 *axis)
{
  idSerializer::Serialize(this, value: axis->mat);
  idSerializer::Serialize(this, value: &axis->mat[1]);
  idSerializer::Serialize(this, value: &axis->mat[2]);
}


// ========================================================================
// ?Serialize@idSerializer@@QAAXAAVidVec4@@@Z
// EA  : 0x827AF6E0
// RVA : 0x007AF6E0
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize(idSerializer *this, idVec4 *value)
{
  float *p_w; // r30
  idBitMsg *msg; // r29
  int v4; // r31

  p_w = &value[-1].w;
  msg = this->msg;
  v4 = 4;
  if ( this->writing )
  {
    do
    {
      idBitMsg::WriteBits(this: msg, value: COERCE_INT(*++p_w), numBits: 32);
      --v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    do
    {
      --v4;
      *(_DWORD *)++p_w = idBitMsg::ReadBits(this: msg, numBits: 32);
    }
    while ( v4 != 0 );
  }
}


// ========================================================================
// ??$Serialize@VidDeclCloth@@@idSerializer@@QAAXAAPBVidDeclCloth@@@Z
// EA  : 0x827B0508
// RVA : 0x007B0508
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclCloth>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclCloth *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclCloth *)_RTDynamicCast(
                                  inptr: v7,
                                  VfDelta: 0,
                                  SrcType: &idResource `RTTI Type Descriptor',
                                  TargetType: (void *)&idDeclCloth `RTTI Type Descriptor',
                                  isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclCloth::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclFlare@@@idSerializer@@QAAXAAPBVidDeclFlare@@@Z
// EA  : 0x827D5330
// RVA : 0x007D5330
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclFlare>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclFlare *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclFlare *)_RTDynamicCast(
                                  inptr: v7,
                                  VfDelta: 0,
                                  SrcType: &idResource `RTTI Type Descriptor',
                                  TargetType: (void *)&idDeclFlare `RTTI Type Descriptor',
                                  isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclFlare::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ?SerializePacked@idSerializer@@QAAXAAH@Z
// EA  : 0x827F2C30
// RVA : 0x007F2C30
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializePacked(idSerializer *this, int *original)
{
  unsigned int v4; // r31
  int v5; // r11
  int v6; // r30
  int v7; // r31
  char Bits; // r3

  if ( this->writing )
  {
    v4 = *original;
    do
    {
      v5 = v4 & 0x7F;
      v4 >>= 7;
      idBitMsg::WriteBits(this: this->msg, value: (v4 == 0 ? 0 : 0x80) | v5, numBits: 8);
    }
    while ( v4 != 0 );
  }
  else
  {
    v6 = 0;
    v7 = 0;
    do
    {
      if ( v7 >= 32 )
        break;
      Bits = idBitMsg::ReadBits(this: this->msg, numBits: 8);
      v6 |= (Bits & 0x7F) << v7;
      v7 += 7;
    }
    while ( Bits < 0 );
    *original = v6;
  }
}


// ========================================================================
// ??$SerializeQ@$00$07@idSerializer@@QAAXAAM@Z
// EA  : 0x827F46D0
// RVA : 0x007F46D0
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeQ<1,8>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v4; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v4 = (int)(float)(*value * (float)127.0);
    if ( v4 >= -127 )
    {
      if ( v4 > 127 )
        v4 = 127;
      idBitMsg::WriteBits(this: msg, value: v4, numBits: -8);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: -127, numBits: -8);
    }
  }
  else
  {
    *value = (float)__SPAIR64__("_AI_OBSTACLE", idBitMsg::ReadBits(this: msg, numBits: -8)) * (float)0.0078740157;
  }
}


// ========================================================================
// ??$SerializeUQ@$0PP@$0BA@@idSerializer@@QAAXAAM@Z
// EA  : 0x827F47A8
// RVA : 0x007F47A8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeUQ<255,16>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3

  writing = this->writing;
  msg = this->msg;
  if ( writing )
    idBitMsg::WriteQuantizedUFloat<255,16>(this: msg, value: *value);
  else
    *value = (float)__SPAIR64__(&unk_82200000, idBitMsg::ReadBits(this: msg, numBits: 16)) * (float)0.0038910506;
}


// ========================================================================
// ??$SerializeQ@$0IA@$0BA@@idSerializer@@QAAXAAM@Z
// EA  : 0x827F4828
// RVA : 0x007F4828
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeQ<128,16>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v4; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v4 = (int)(float)(*value * (float)255.0);
    if ( v4 >= -32767 )
    {
      if ( v4 > 0x7FFF )
        v4 = 0x7FFF;
      idBitMsg::WriteBits(this: msg, value: v4, numBits: -16);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: -32767, numBits: -16);
    }
  }
  else
  {
    *value = (float)__SPAIR64__(&unk_82200000, idBitMsg::ReadBits(this: msg, numBits: -16)) * (float)0.0039063692;
  }
}


// ========================================================================
// ?Serialize@idSerializer@@QAAXAAF@Z
// EA  : 0x8285F248
// RVA : 0x0085F248
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize(idSerializer *this, __int16 *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3

  writing = this->writing;
  msg = this->msg;
  if ( writing )
    idBitMsg::WriteBits(this: msg, value: *value, numBits: -16);
  else
    *value = idBitMsg::ReadBits(this: msg, numBits: -16);
}


// ========================================================================
// ??$SerializeUQ@$0PP@$07@idSerializer@@QAAXAAM@Z
// EA  : 0x82860460
// RVA : 0x00860460
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeUQ<255,8>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v5; // r11
  __int64 v6; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v5 = (int)*value;
    if ( v5 >= 0 )
    {
      if ( v5 > 255 )
        v5 = 255;
      idBitMsg::WriteBits(this: msg, value: v5, numBits: 8);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: 0, numBits: 8);
    }
  }
  else
  {
    LODWORD(v6) = idBitMsg::ReadBits(this: msg, numBits: 8);
    *value = (float)v6;
  }
}


// ========================================================================
// ??$Serialize@VidSoundShader@@@idSerializer@@QAAXAAPBVidSoundShader@@@Z
// EA  : 0x82B4DC00
// RVA : 0x00B4DC00
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idSoundShader>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idSoundShader *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idSoundShader *)_RTDynamicCast(
                                    inptr: v7,
                                    VfDelta: 0,
                                    SrcType: &idResource `RTTI Type Descriptor',
                                    TargetType: (void *)&idSoundShader `RTTI Type Descriptor',
                                    isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idSoundShader::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$SerializeQ@$0DM@$07@idSerializer@@QAAXAAM@Z
// EA  : 0x82B4DD20
// RVA : 0x00B4DD20
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeQ<60,8>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v4; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v4 = (int)(float)(*value * (float)2.0);
    if ( v4 >= -127 )
    {
      if ( v4 > 127 )
        v4 = 127;
      idBitMsg::WriteBits(this: msg, value: v4, numBits: -8);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: -127, numBits: -8);
    }
  }
  else
  {
    *value = (float)__SPAIR64__(&off_822B0000, idBitMsg::ReadBits(this: msg, numBits: -8)) * (float)0.47244096;
  }
}


// ========================================================================
// ??$SerializeQ@$0IAAA@$0L@@idSerializer@@QAAXAAM@Z
// EA  : 0x82B4DDF8
// RVA : 0x00B4DDF8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeQ<32768,11>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v4; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v4 = (int)(float)(*value * (float)0.031219482);
    if ( v4 >= -1023 )
    {
      if ( v4 > 1023 )
        v4 = 1023;
      idBitMsg::WriteBits(this: msg, value: v4, numBits: -11);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: -1023, numBits: -11);
    }
  }
  else
  {
    *value = (float)__SPAIR64__(&off_822B0000, idBitMsg::ReadBits(this: msg, numBits: -11)) * (float)32.031281;
  }
}


// ========================================================================
// ??$SerializeQ@$0EA@$07@idSerializer@@QAAXAAM@Z
// EA  : 0x82B4DED0
// RVA : 0x00B4DED0
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeQ<64,8>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v4; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v4 = (int)*value;
    if ( v4 >= -127 )
    {
      if ( v4 > 127 )
        v4 = 127;
      idBitMsg::WriteBits(this: msg, value: v4, numBits: -8);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: -127, numBits: -8);
    }
  }
  else
  {
    *value = (float)__SPAIR64__(&off_822B0000, idBitMsg::ReadBits(this: msg, numBits: -8)) * (float)0.50393701;
  }
}


// ========================================================================
// ??$Serialize@VidDeclInventory@@@idSerializer@@QAAXAAPBVidDeclInventory@@@Z
// EA  : 0x82B59718
// RVA : 0x00B59718
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclInventory>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclInventory *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclInventory *)_RTDynamicCast(
                                      inptr: v7,
                                      VfDelta: 0,
                                      SrcType: &idResource `RTTI Type Descriptor',
                                      TargetType: &idDeclInventory `RTTI Type Descriptor',
                                      isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclInventory::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclAmmo@@@idSerializer@@QAAXAAPBVidDeclAmmo@@@Z
// EA  : 0x82B59838
// RVA : 0x00B59838
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclAmmo>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclAmmo *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclAmmo *)_RTDynamicCast(
                                 inptr: v7,
                                 VfDelta: 0,
                                 SrcType: &idResource `RTTI Type Descriptor',
                                 TargetType: (void *)&idDeclAmmo `RTTI Type Descriptor',
                                 isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclAmmo::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclWeapon@@@idSerializer@@QAAXAAPBVidDeclWeapon@@@Z
// EA  : 0x82B59958
// RVA : 0x00B59958
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclWeapon>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclWeapon *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclWeapon *)_RTDynamicCast(
                                   inptr: v7,
                                   VfDelta: 0,
                                   SrcType: &idResource `RTTI Type Descriptor',
                                   TargetType: (void *)&idDeclWeapon `RTTI Type Descriptor',
                                   isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclWeapon::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclThrowable@@@idSerializer@@QAAXAAPBVidDeclThrowable@@@Z
// EA  : 0x82B59A78
// RVA : 0x00B59A78
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclThrowable>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclThrowable *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclThrowable *)_RTDynamicCast(
                                      inptr: v7,
                                      VfDelta: 0,
                                      SrcType: &idResource `RTTI Type Descriptor',
                                      TargetType: (void *)&idDeclThrowable `RTTI Type Descriptor',
                                      isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclThrowable::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclProjectile@@@idSerializer@@QAAXAAPBVidDeclProjectile@@@Z
// EA  : 0x82B59B98
// RVA : 0x00B59B98
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclProjectile>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclProjectile *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclProjectile *)_RTDynamicCast(
                                       inptr: v7,
                                       VfDelta: 0,
                                       SrcType: &idResource `RTTI Type Descriptor',
                                       TargetType: (void *)&idDeclProjectile `RTTI Type Descriptor',
                                       isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclProjectile::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclDamage@@@idSerializer@@QAAXAAPBVidDeclDamage@@@Z
// EA  : 0x82B59CB8
// RVA : 0x00B59CB8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclDamage>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclDamage *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclDamage *)_RTDynamicCast(
                                   inptr: v7,
                                   VfDelta: 0,
                                   SrcType: &idResource `RTTI Type Descriptor',
                                   TargetType: (void *)&idDeclDamage `RTTI Type Descriptor',
                                   isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclDamage::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclMetric@@@idSerializer@@QAAXAAPBVidDeclMetric@@@Z
// EA  : 0x82B59DD8
// RVA : 0x00B59DD8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclMetric>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclMetric *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclMetric *)_RTDynamicCast(
                                   inptr: v7,
                                   VfDelta: 0,
                                   SrcType: &idResource `RTTI Type Descriptor',
                                   TargetType: (void *)&idDeclMetric `RTTI Type Descriptor',
                                   isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclMetric::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclFX@@@idSerializer@@QAAXAAPBVidDeclFX@@@Z
// EA  : 0x82B686C8
// RVA : 0x00B686C8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclFX>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclFX *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclFX *)_RTDynamicCast(
                               inptr: v7,
                               VfDelta: 0,
                               SrcType: &idResource `RTTI Type Descriptor',
                               TargetType: (void *)&idDeclFX `RTTI Type Descriptor',
                               isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclFX::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclGore@@@idSerializer@@QAAXAAPBVidDeclGore@@@Z
// EA  : 0x82B6AD70
// RVA : 0x00B6AD70
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclGore>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclGore *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclGore *)_RTDynamicCast(
                                 inptr: v7,
                                 VfDelta: 0,
                                 SrcType: &idResource `RTTI Type Descriptor',
                                 TargetType: (void *)&idDeclGore `RTTI Type Descriptor',
                                 isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclGore::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclTwitchPain@@@idSerializer@@QAAXAAPBVidDeclTwitchPain@@@Z
// EA  : 0x82B6AE90
// RVA : 0x00B6AE90
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclTwitchPain>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclTwitchPain *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclTwitchPain *)_RTDynamicCast(
                                       inptr: v7,
                                       VfDelta: 0,
                                       SrcType: &idResource `RTTI Type Descriptor',
                                       TargetType: (void *)&idDeclTwitchPain `RTTI Type Descriptor',
                                       isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclTwitchPain::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ?SerializeString@idSerializer@@QAAXAAVidAtomicString@@@Z
// EA  : 0x82B6B948
// RVA : 0x00B6B948
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeString(idSerializer *this, idAtomicString *s)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  if ( this->writing )
  {
    idBitMsg::WriteString(this: this->msg, s: s->str, maxLength: -1, make7Bit: true);
  }
  else
  {
    v3.len = 0;
    v3.allocedAndFlag = 20;
    v3.data = v3.baseBuffer;
    v3.baseBuffer[0] = 0;
    idBitMsg::ReadString(this: this->msg, str: &v3);
    idAtomicString::Set(this: s, str_: v3.data);
    idStr::FreeData(this: &v3);
  }
}


// ========================================================================
// __unwind$487903
// EA  : 0x82B6B9DC
// RVA : 0x00B6B9DC
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void _unwind_487903()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?Serialize@idSerializer@@QAAXAAVidVec2@@@Z
// EA  : 0x82B6F0E0
// RVA : 0x00B6F0E0
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize(idSerializer *this, idVec2 *value)
{
  float *p_y; // r30
  idBitMsg *msg; // r29
  int v4; // r31

  p_y = &value[-1].y;
  msg = this->msg;
  v4 = 2;
  if ( this->writing )
  {
    do
    {
      idBitMsg::WriteBits(this: msg, value: COERCE_INT(*++p_y), numBits: 32);
      --v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    do
    {
      --v4;
      *(_DWORD *)++p_y = idBitMsg::ReadBits(this: msg, numBits: 32);
    }
    while ( v4 != 0 );
  }
}


// ========================================================================
// ??$Serialize@VidDeclElectricBolt@@@idSerializer@@QAAXAAPBVidDeclElectricBolt@@@Z
// EA  : 0x82B6F1F0
// RVA : 0x00B6F1F0
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclElectricBolt>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclElectricBolt *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclElectricBolt *)_RTDynamicCast(
                                         inptr: v7,
                                         VfDelta: 0,
                                         SrcType: &idResource `RTTI Type Descriptor',
                                         TargetType: (void *)&idDeclElectricBolt `RTTI Type Descriptor',
                                         isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclElectricBolt::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclLaserGate@@@idSerializer@@QAAXAAPBVidDeclLaserGate@@@Z
// EA  : 0x82B70248
// RVA : 0x00B70248
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclLaserGate>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclLaserGate *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclLaserGate *)_RTDynamicCast(
                                      inptr: v7,
                                      VfDelta: 0,
                                      SrcType: &idResource `RTTI Type Descriptor',
                                      TargetType: (void *)&idDeclLaserGate `RTTI Type Descriptor',
                                      isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclLaserGate::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclImpactSound@@@idSerializer@@QAAXAAPBVidDeclImpactSound@@@Z
// EA  : 0x82B73170
// RVA : 0x00B73170
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclImpactSound>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclImpactSound *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclImpactSound *)_RTDynamicCast(
                                        inptr: v7,
                                        VfDelta: 0,
                                        SrcType: &idResource `RTTI Type Descriptor',
                                        TargetType: (void *)&idDeclImpactSound `RTTI Type Descriptor',
                                        isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclImpactSound::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclPlayerProps@@@idSerializer@@QAAXAAPBVidDeclPlayerProps@@@Z
// EA  : 0x82B78860
// RVA : 0x00B78860
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclPlayerProps>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclPlayerProps *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclPlayerProps *)_RTDynamicCast(
                                        inptr: v7,
                                        VfDelta: 0,
                                        SrcType: &idResource `RTTI Type Descriptor',
                                        TargetType: (void *)&idDeclPlayerProps `RTTI Type Descriptor',
                                        isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclPlayerProps::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclOnlineScoringCallout@@@idSerializer@@QAAXAAPBVidDeclOnlineScoringCallout@@@Z
// EA  : 0x82B78980
// RVA : 0x00B78980
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclOnlineScoringCallout>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclOnlineScoringCallout *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclOnlineScoringCallout *)_RTDynamicCast(
                                                 inptr: v7,
                                                 VfDelta: 0,
                                                 SrcType: &idResource `RTTI Type Descriptor',
                                                 TargetType: (void *)&idDeclOnlineScoringCallout `RTTI Type Descriptor',
                                                 isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclOnlineScoringCallout::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclVehicleWeapon@@@idSerializer@@QAAXAAPBVidDeclVehicleWeapon@@@Z
// EA  : 0x82B97CF8
// RVA : 0x00B97CF8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclVehicleWeapon>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclVehicleWeapon *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclVehicleWeapon *)_RTDynamicCast(
                                          inptr: v7,
                                          VfDelta: 0,
                                          SrcType: &idResource `RTTI Type Descriptor',
                                          TargetType: &idDeclVehicleWeapon `RTTI Type Descriptor',
                                          isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclVehicleWeapon::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$SerializeUQ@$00$05@idSerializer@@QAAXAAM@Z
// EA  : 0x82B97E18
// RVA : 0x00B97E18
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeUQ<1,6>(idSerializer *this, float *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r3
  int v4; // r11

  writing = this->writing;
  msg = this->msg;
  if ( writing )
  {
    v4 = (int)(float)(*value * (float)63.0);
    if ( v4 >= 0 )
    {
      if ( v4 > 63 )
        v4 = 63;
      idBitMsg::WriteBits(this: msg, value: v4, numBits: 6);
    }
    else
    {
      idBitMsg::WriteBits(this: msg, value: 0, numBits: 6);
    }
  }
  else
  {
    *value = (float)__SPAIR64__(&unk_821C0000, idBitMsg::ReadBits(this: msg, numBits: 6)) * (float)0.015873017;
  }
}


// ========================================================================
// ??$Serialize@VidDeclActorModifier@@@idSerializer@@QAAXAAPBVidDeclActorModifier@@@Z
// EA  : 0x82BEAED0
// RVA : 0x00BEAED0
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclActorModifier>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclActorModifier *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclActorModifier *)_RTDynamicCast(
                                          inptr: v7,
                                          VfDelta: 0,
                                          SrcType: &idResource `RTTI Type Descriptor',
                                          TargetType: (void *)&idDeclActorModifier `RTTI Type Descriptor',
                                          isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclActorModifier::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ?SerializeString@idSerializer@@QAAXAAVidStrId@@@Z
// EA  : 0x82C51A78
// RVA : 0x00C51A78
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::SerializeString(idSerializer *this, idStrId *s)
{
  const char *Key; // r3
  idStr v5[2]; // [sp+50h] [-40h] BYREF

  if ( this->writing )
  {
    Key = idStrId::GetKey(this: s);
    idBitMsg::WriteString(this: this->msg, s: Key, maxLength: -1, make7Bit: true);
  }
  else
  {
    v5[0].len = 0;
    v5[0].allocedAndFlag = 20;
    v5[0].data = v5[0].baseBuffer;
    v5[0].baseBuffer[0] = 0;
    idBitMsg::ReadString(this: this->msg, str: v5);
    idStrId::Set(this: s, key: v5[0].data);
    idStr::FreeData(this: v5);
  }
}


// ========================================================================
// __unwind$496055
// EA  : 0x82C51B00
// RVA : 0x00C51B00
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void _unwind_496055()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ??$Serialize@VidDeclVehicleUnlock@@@idSerializer@@QAAXAAPBVidDeclVehicleUnlock@@@Z
// EA  : 0x82D7D3F8
// RVA : 0x00D7D3F8
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclVehicleUnlock>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclVehicleUnlock *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclVehicleUnlock *)_RTDynamicCast(
                                          inptr: v7,
                                          VfDelta: 0,
                                          SrcType: &idResource `RTTI Type Descriptor',
                                          TargetType: (void *)&idDeclVehicleUnlock `RTTI Type Descriptor',
                                          isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclVehicleUnlock::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclDuck@@@idSerializer@@QAAXAAPBVidDeclDuck@@@Z
// EA  : 0x82D7D518
// RVA : 0x00D7D518
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclDuck>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclDuck *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclDuck *)_RTDynamicCast(
                                 inptr: v7,
                                 VfDelta: 0,
                                 SrcType: &idResource `RTTI Type Descriptor',
                                 TargetType: (void *)&idDeclDuck `RTTI Type Descriptor',
                                 isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclDuck::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclOnlineFiction@@@idSerializer@@QAAXAAPBVidDeclOnlineFiction@@@Z
// EA  : 0x82D7D638
// RVA : 0x00D7D638
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclOnlineFiction>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclOnlineFiction *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclOnlineFiction *)_RTDynamicCast(
                                          inptr: v7,
                                          VfDelta: 0,
                                          SrcType: &idResource `RTTI Type Descriptor',
                                          TargetType: &idDeclOnlineFiction `RTTI Type Descriptor',
                                          isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclOnlineFiction::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ??$Serialize@VidDeclEntityDef@@@idSerializer@@QAAXAAPBVidDeclEntityDef@@@Z
// EA  : 0x82D7D758
// RVA : 0x00D7D758
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize<idDeclEntityDef>(idSerializer *this, const idDecl **decl)
{
  idAnimRecorder *v4; // r3
  int v5; // r29
  idAnimRecorder *Instance; // r3
  const char **v7; // r3
  const char **v8; // r30
  const idDeclEntityDef *v9; // r3
  int v10[12]; // [sp+50h] [-30h] BYREF

  if ( this->writing )
  {
    v4 = idAnimRecorder::instance;
    if ( idAnimRecorder::instance == nullptr )
    {
      v4 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v4;
    }
    v10[0] = (unsigned __int16)idAnimRecorder::AddDeclNetworkID(this: v4, ser: this, decl: *decl);
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
  }
  else
  {
    v10[0] = 0xFFFF;
    idSerializer::SerializeUMax(this, value: v10, maxSize: 0xFFFFu);
    v5 = v10[0];
    if ( v10[0] == 0xFFFF )
    {
      *decl = nullptr;
    }
    else
    {
      Instance = idAnimRecorder::GetInstance();
      idAnimRecorder::SerializeDeclNetworkID(this: Instance, ser: this, declNetworkID: v5);
      v8 = v7;
      v9 = (const idDeclEntityDef *)_RTDynamicCast(
                                      inptr: v7,
                                      VfDelta: 0,
                                      SrcType: &idResource `RTTI Type Descriptor',
                                      TargetType: (void *)&idDeclEntityDef `RTTI Type Descriptor',
                                      isReference: 0);
      *decl = v9;
      if ( v9 == nullptr && v8 != nullptr )
        idLib::Warning(
          fmt: "Decl %d is not of type %s (%s) %d",
          v5,
          idDeclEntityDef::resourceList.name,
          v8[2],
          this->msg->readCount);
    }
  }
}


// ========================================================================
// ?Serialize@idSerializer@@QAAXAA_K@Z
// EA  : 0x82E4F030
// RVA : 0x00E4F030
// PDB : w:\tech5\engine\network\serializer.h
// ========================================================================

void __fastcall idSerializer::Serialize(idSerializer *this, unsigned __int64 *value)
{
  BOOL writing; // r11
  idBitMsg *msg; // r30
  idBitMsg *v5; // r3
  __int64 v6; // r31
  int Bits; // r29
  unsigned __int64 v8; // r11

  writing = this->writing;
  msg = this->msg;
  v5 = msg;
  if ( writing )
  {
    v6 = *value;
    idBitMsg::WriteBits(this: v5, value: *((_DWORD *)value + 1), numBits: 32);
    idBitMsg::WriteBits(this: (idBitMsg *)HIDWORD(v6), value: SHIDWORD(v6), numBits: 32);
  }
  else
  {
    Bits = idBitMsg::ReadBits(this: msg, numBits: 32);
    idBitMsg::ReadBits(this: msg, numBits: 32);
    LODWORD(v8) = Bits;
    *value = v8;
  }
}

