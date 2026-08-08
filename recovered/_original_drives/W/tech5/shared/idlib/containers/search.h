
// ========================================================================
// ?Search@?$idSearch_Binary@UjointMod_t@idMD6Blend@@VidSearch_JointMod@@@@UBAHPBUjointMod_t@idMD6Blend@@IABU23@@Z
// EA  : 0x826CAC00
// RVA : 0x006CAC00
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>::Search(
        idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod> *this,
        const idMD6Blend::jointMod_t *base,
        int num,
        const idMD6Blend::jointMod_t *value)
{
  int v4; // r7
  int v5; // r8
  int v6; // r11

  v4 = num;
  if ( num == 0 || base == nullptr )
    return -1;
  v5 = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( base[v5 + (v4 >> 1)].joint.value - value->joint.value <= 0 )
        v5 += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  if ( base[v5].joint.value != value->joint.value )
    return -1;
  return v5;
}


// ========================================================================
// ?Search_FirstGreater@?$idSearch_Binary@UjointMod_t@idMD6Blend@@VidSearch_JointMod@@@@UBAHPBUjointMod_t@idMD6Blend@@HABU23@@Z
// EA  : 0x826CAC90
// RVA : 0x006CAC90
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>::Search_FirstGreater(
        idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod> *this,
        const idMD6Blend::jointMod_t *base,
        int num,
        const idMD6Blend::jointMod_t *value)
{
  int v4; // r7
  int v5; // r8
  int v6; // r11
  int v7; // r6
  int v8; // r9

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    v7 = value->joint.value;
    do
    {
      v8 = v4 >> 1;
      if ( base[v5 + (v4 >> 1)].joint.value - v7 <= 0 )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v8;
    }
    while ( v8 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_FirstGreaterEqual@?$idSearch_Binary@UjointMod_t@idMD6Blend@@VidSearch_JointMod@@@@UBAHPBUjointMod_t@idMD6Blend@@HABU23@@Z
// EA  : 0x826CACF0
// RVA : 0x006CACF0
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>::Search_FirstGreaterEqual(
        idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod> *this,
        const idMD6Blend::jointMod_t *base,
        int num,
        const idMD6Blend::jointMod_t *value)
{
  int v4; // r7
  int v5; // r8
  int v6; // r11
  int v7; // r6
  int v8; // r9

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    v7 = value->joint.value;
    do
    {
      v8 = v4 >> 1;
      if ( base[v5 + (v4 >> 1)].joint.value - v7 < 0 )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v8;
    }
    while ( v8 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_LastLess@?$idSearch_Binary@UjointMod_t@idMD6Blend@@VidSearch_JointMod@@@@UBAHPBUjointMod_t@idMD6Blend@@HABU23@@Z
// EA  : 0x826CAD50
// RVA : 0x006CAD50
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>::Search_LastLess(
        idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod> *this,
        const idMD6Blend::jointMod_t *base,
        int num,
        const idMD6Blend::jointMod_t *value)
{
  int v4; // r8
  int result; // r3
  int v6; // r11

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( base[result + (v4 >> 1)].joint.value - value->joint.value < 0 )
        result += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search_LastLessEqual@?$idSearch_Binary@UjointMod_t@idMD6Blend@@VidSearch_JointMod@@@@UBAHPBUjointMod_t@idMD6Blend@@HABU23@@Z
// EA  : 0x826CADA0
// RVA : 0x006CADA0
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>::Search_LastLessEqual(
        idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod> *this,
        const idMD6Blend::jointMod_t *base,
        int num,
        const idMD6Blend::jointMod_t *value)
{
  int v4; // r8
  int result; // r3
  int v6; // r11

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( base[result + (v4 >> 1)].joint.value - value->joint.value <= 0 )
        result += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search@?$idSearch_Binary@V?$idPair@GUNameStruct_t@idAnimRecorder@@@@VidSearch_NetworkIDNamePair@idAnimRecorder@@@@UBAHPBV?$idPair@GUNameStruct_t@idAnimRecorder@@@@IABV2@@Z
// EA  : 0x826F1118
// RVA : 0x006F1118
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>::Search(
        idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair> *this,
        const idPair<unsigned short,idAnimRecorder::NameStruct_t> *base,
        int num,
        const idPair<unsigned short,idAnimRecorder::NameStruct_t> *value)
{
  int v4; // r7
  int v5; // r8
  int v6; // r10

  v4 = num;
  if ( num == 0 || base == nullptr )
    return -1;
  v5 = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( base[v5 + (v4 >> 1)].first - value->first <= 0 )
        v5 += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  if ( base[v5].first != value->first )
    return -1;
  return v5;
}


// ========================================================================
// ?Search_FirstGreater@?$idSearch_Binary@V?$idPair@GUNameStruct_t@idAnimRecorder@@@@VidSearch_NetworkIDNamePair@idAnimRecorder@@@@UBAHPBV?$idPair@GUNameStruct_t@idAnimRecorder@@@@HABV2@@Z
// EA  : 0x826F11A0
// RVA : 0x006F11A0
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>::Search_FirstGreater(
        idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair> *this,
        const idPair<unsigned short,idAnimRecorder::NameStruct_t> *base,
        int num,
        const idPair<unsigned short,idAnimRecorder::NameStruct_t> *value)
{
  int v4; // r7
  int v5; // r8
  int v6; // r11
  int first; // r6
  int v8; // r9

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    first = value->first;
    do
    {
      v8 = v4 >> 1;
      if ( base[v5 + (v4 >> 1)].first - first <= 0 )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v8;
    }
    while ( v8 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_FirstGreaterEqual@?$idSearch_Binary@V?$idPair@GUNameStruct_t@idAnimRecorder@@@@VidSearch_NetworkIDNamePair@idAnimRecorder@@@@UBAHPBV?$idPair@GUNameStruct_t@idAnimRecorder@@@@HABV2@@Z
// EA  : 0x826F1200
// RVA : 0x006F1200
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>::Search_FirstGreaterEqual(
        idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair> *this,
        const idPair<unsigned short,idAnimRecorder::NameStruct_t> *base,
        int num,
        const idPair<unsigned short,idAnimRecorder::NameStruct_t> *value)
{
  int v4; // r7
  int v5; // r8
  int v6; // r11
  int first; // r6
  int v8; // r9

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    first = value->first;
    do
    {
      v8 = v4 >> 1;
      if ( base[v5 + (v4 >> 1)].first - first < 0 )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v8;
    }
    while ( v8 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_LastLess@?$idSearch_Binary@V?$idPair@GUNameStruct_t@idAnimRecorder@@@@VidSearch_NetworkIDNamePair@idAnimRecorder@@@@UBAHPBV?$idPair@GUNameStruct_t@idAnimRecorder@@@@HABV2@@Z
// EA  : 0x826F1260
// RVA : 0x006F1260
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>::Search_LastLess(
        idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair> *this,
        const idPair<unsigned short,idAnimRecorder::NameStruct_t> *base,
        int num,
        const idPair<unsigned short,idAnimRecorder::NameStruct_t> *value)
{
  int v4; // r8
  int result; // r3
  int v6; // r10

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( base[result + (v4 >> 1)].first - value->first < 0 )
        result += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search_LastLessEqual@?$idSearch_Binary@V?$idPair@GUNameStruct_t@idAnimRecorder@@@@VidSearch_NetworkIDNamePair@idAnimRecorder@@@@UBAHPBV?$idPair@GUNameStruct_t@idAnimRecorder@@@@HABV2@@Z
// EA  : 0x826F12A8
// RVA : 0x006F12A8
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>::Search_LastLessEqual(
        idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair> *this,
        const idPair<unsigned short,idAnimRecorder::NameStruct_t> *base,
        int num,
        const idPair<unsigned short,idAnimRecorder::NameStruct_t> *value)
{
  int v4; // r8
  int result; // r3
  int v6; // r10

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( base[result + (v4 >> 1)].first - value->first <= 0 )
        result += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search@?$idSearch_Binary@MV?$idSearch_BinaryDefault@M@@@@UBAHPBMIABM@Z
// EA  : 0x8276AF88
// RVA : 0x0076AF88
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<float,idSearch_BinaryDefault<float>>::Search(
        idSearch_Binary<float,idSearch_BinaryDefault<float> > *this,
        const float *base,
        int num,
        const float *value)
{
  int v4; // r8
  int v5; // r9
  int v6; // r11

  v4 = num;
  if ( num == 0 || base == nullptr )
    return -1;
  v5 = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      _FP0 = (float)(base[v5 + (v4 >> 1)] - *value);
      if ( _FP0 <= 0.0 )
        __asm { fsel      f0, f0, f13, f12 }
      else
        _FP0 = 1.0;
      if ( (int)_FP0 <= 0 )
        v5 += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  _FP0 = (float)(base[v5] - *value);
  if ( _FP0 <= 0.0 )
    __asm { fsel      f0, f0, f13, f12 }
  else
    _FP0 = 1.0;
  if ( (int)_FP0 != 0 )
    return -1;
  return v5;
}


// ========================================================================
// ?Search_FirstGreater@?$idSearch_Binary@MV?$idSearch_BinaryDefault@M@@@@UBAHPBMHABM@Z
// EA  : 0x8276B060
// RVA : 0x0076B060
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<float,idSearch_BinaryDefault<float>>::Search_FirstGreater(
        idSearch_Binary<float,idSearch_BinaryDefault<float> > *this,
        const float *base,
        int num,
        const float *value)
{
  int v4; // r8
  int v5; // r10
  int v6; // r11
  int v7; // r9

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    do
    {
      v7 = v4 >> 1;
      _FP0 = (float)(base[v5 + (v4 >> 1)] - *value);
      if ( _FP0 <= 0.0 )
        __asm { fsel      f0, f0, f13, f12 }
      else
        _FP0 = 1.0;
      if ( (int)_FP0 <= 0 )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_FirstGreaterEqual@?$idSearch_Binary@MV?$idSearch_BinaryDefault@M@@@@UBAHPBMHABM@Z
// EA  : 0x8276B0F0
// RVA : 0x0076B0F0
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<float,idSearch_BinaryDefault<float>>::Search_FirstGreaterEqual(
        idSearch_Binary<float,idSearch_BinaryDefault<float> > *this,
        const float *base,
        int num,
        const float *value)
{
  int v4; // r8
  int v5; // r10
  int v6; // r11
  int v7; // r9

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    do
    {
      v7 = v4 >> 1;
      _FP0 = (float)(base[v5 + (v4 >> 1)] - *value);
      if ( _FP0 <= 0.0 )
        __asm { fsel      f0, f0, f13, f12 }
      else
        _FP0 = 1.0;
      if ( (int)_FP0 < 0 )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_LastLess@?$idSearch_Binary@MV?$idSearch_BinaryDefault@M@@@@UBAHPBMHABM@Z
// EA  : 0x8276B180
// RVA : 0x0076B180
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<float,idSearch_BinaryDefault<float>>::Search_LastLess(
        idSearch_Binary<float,idSearch_BinaryDefault<float> > *this,
        const float *base,
        int num,
        const float *value)
{
  int v4; // r9
  int result; // r3
  int v6; // r11

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      _FP0 = (float)(base[result + (v4 >> 1)] - *value);
      if ( _FP0 <= 0.0 )
        __asm { fsel      f0, f0, f13, f12 }
      else
        _FP0 = 1.0;
      if ( (int)_FP0 < 0 )
        result += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search_LastLessEqual@?$idSearch_Binary@MV?$idSearch_BinaryDefault@M@@@@UBAHPBMHABM@Z
// EA  : 0x8276B200
// RVA : 0x0076B200
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<float,idSearch_BinaryDefault<float>>::Search_LastLessEqual(
        idSearch_Binary<float,idSearch_BinaryDefault<float> > *this,
        const float *base,
        int num,
        const float *value)
{
  int v4; // r9
  int result; // r3
  int v6; // r11

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      _FP0 = (float)(base[result + (v4 >> 1)] - *value);
      if ( _FP0 <= 0.0 )
        __asm { fsel      f0, f0, f13, f12 }
      else
        _FP0 = 1.0;
      if ( (int)_FP0 <= 0 )
        result += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search@?$idSearch_Binary@IV?$idSearch_BinaryDefault@I@@@@UBAHPBIIABI@Z
// EA  : 0x8276D938
// RVA : 0x0076D938
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int>>::Search(
        idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int> > *this,
        const unsigned int *base,
        int num,
        const unsigned int *value)
{
  int v4; // r8
  int v5; // r9
  int v6; // r11

  v4 = num;
  if ( num == 0 || base == nullptr )
    return -1;
  v5 = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( (signed int)(base[v5 + (v4 >> 1)] - *value) <= 0 )
        v5 += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  if ( base[v5] != *value )
    return -1;
  return v5;
}


// ========================================================================
// ?Search_FirstGreater@?$idSearch_Binary@IV?$idSearch_BinaryDefault@I@@@@UBAHPBIHABI@Z
// EA  : 0x8276D9B0
// RVA : 0x0076D9B0
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int>>::Search_FirstGreater(
        idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int> > *this,
        const unsigned int *base,
        int num,
        const unsigned int *value)
{
  int v4; // r8
  int v5; // r10
  int v6; // r11
  int v7; // r9

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    do
    {
      v7 = v4 >> 1;
      if ( (signed int)(base[v5 + (v4 >> 1)] - *value) <= 0 )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_FirstGreaterEqual@?$idSearch_Binary@IV?$idSearch_BinaryDefault@I@@@@UBAHPBIHABI@Z
// EA  : 0x8276DA08
// RVA : 0x0076DA08
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int>>::Search_FirstGreaterEqual(
        idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int> > *this,
        const unsigned int *base,
        int num,
        const unsigned int *value)
{
  int v4; // r8
  int v5; // r10
  int v6; // r11
  int v7; // r9

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    do
    {
      v7 = v4 >> 1;
      if ( (signed int)(base[v5 + (v4 >> 1)] - *value) < 0 )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_LastLess@?$idSearch_Binary@IV?$idSearch_BinaryDefault@I@@@@UBAHPBIHABI@Z
// EA  : 0x8276DA60
// RVA : 0x0076DA60
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int>>::Search_LastLess(
        idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int> > *this,
        const unsigned int *base,
        int num,
        const unsigned int *value)
{
  int v4; // r9
  int result; // r3
  int v6; // r11

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( (signed int)(base[result + (v4 >> 1)] - *value) < 0 )
        result += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search_LastLessEqual@?$idSearch_Binary@IV?$idSearch_BinaryDefault@I@@@@UBAHPBIHABI@Z
// EA  : 0x8276DAA0
// RVA : 0x0076DAA0
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int>>::Search_LastLessEqual(
        idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int> > *this,
        const unsigned int *base,
        int num,
        const unsigned int *value)
{
  int v4; // r9
  int result; // r3
  int v6; // r11

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( (signed int)(base[result + (v4 >> 1)] - *value) <= 0 )
        result += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search@?$idSearch_Binary@VidStr@@U?$idSearch_BinaryDefault@VidStr@@@@@@UBAHPBVidStr@@IABV2@@Z
// EA  : 0x8279EC48
// RVA : 0x0079EC48
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idStr,idSearch_BinaryDefault<idStr>>::Search(
        idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> > *this,
        const idStr *base,
        int num,
        const idStr *value)
{
  int v6; // r28
  int v7; // r29
  int v8; // r31
  int result; // r3
  bool v10; // zf

  if ( num == 0 || base == nullptr )
    return -1;
  v6 = num;
  v7 = 0;
  if ( num > 0 )
  {
    do
    {
      v8 = v6 >> 1;
      if ( idStr::Icmp(s1: base[v7 + (v6 >> 1)].data, s2: value->data) <= 0 )
        v7 += v6 >> 1;
      v6 -= v8;
    }
    while ( v8 > 0 );
  }
  v10 = idStr::Icmp(s1: base[v7].data, s2: value->data) == 0;
  result = v7;
  if ( !v10 )
    return -1;
  return result;
}


// ========================================================================
// ?Search_FirstGreater@?$idSearch_Binary@VidStr@@U?$idSearch_BinaryDefault@VidStr@@@@@@UBAHPBVidStr@@HABV2@@Z
// EA  : 0x8279ECE0
// RVA : 0x0079ECE0
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idStr,idSearch_BinaryDefault<idStr>>::Search_FirstGreater(
        idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> > *this,
        const idStr *base,
        int num,
        const idStr *value)
{
  int v6; // r28
  int v7; // r30
  int v8; // r11
  int v9; // r29

  v6 = num;
  v7 = 0;
  v8 = 0;
  if ( num > 0 )
  {
    do
    {
      v9 = v6 >> 1;
      if ( idStr::Icmp(s1: base[v7 + (v6 >> 1)].data, s2: value->data) <= 0 )
      {
        v7 += v6 >> 1;
        v8 = 1;
      }
      else
      {
        v8 = 0;
      }
      v6 -= v9;
    }
    while ( v9 > 0 );
  }
  return v8 + v7;
}


// ========================================================================
// ?Search_FirstGreaterEqual@?$idSearch_Binary@VidStr@@U?$idSearch_BinaryDefault@VidStr@@@@@@UBAHPBVidStr@@HABV2@@Z
// EA  : 0x8279ED58
// RVA : 0x0079ED58
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idStr,idSearch_BinaryDefault<idStr>>::Search_FirstGreaterEqual(
        idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> > *this,
        const idStr *base,
        int num,
        const idStr *value)
{
  int v6; // r28
  int v7; // r30
  int v8; // r11
  int v9; // r29

  v6 = num;
  v7 = 0;
  v8 = 0;
  if ( num > 0 )
  {
    do
    {
      v9 = v6 >> 1;
      if ( idStr::Icmp(s1: base[v7 + (v6 >> 1)].data, s2: value->data) < 0 )
      {
        v7 += v6 >> 1;
        v8 = 1;
      }
      else
      {
        v8 = 0;
      }
      v6 -= v9;
    }
    while ( v9 > 0 );
  }
  return v8 + v7;
}


// ========================================================================
// ?Search_LastLess@?$idSearch_Binary@VidStr@@U?$idSearch_BinaryDefault@VidStr@@@@@@UBAHPBVidStr@@HABV2@@Z
// EA  : 0x8279EDD0
// RVA : 0x0079EDD0
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idStr,idSearch_BinaryDefault<idStr>>::Search_LastLess(
        idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> > *this,
        const idStr *base,
        int num,
        const idStr *value)
{
  int v6; // r29
  int v7; // r28
  int v8; // r31

  v6 = num;
  v7 = 0;
  if ( num > 0 )
  {
    do
    {
      v8 = v6 >> 1;
      if ( idStr::Icmp(s1: base[v7 + (v6 >> 1)].data, s2: value->data) < 0 )
        v7 += v6 >> 1;
      v6 -= v8;
    }
    while ( v8 > 0 );
  }
  return v7;
}


// ========================================================================
// ?Search_LastLessEqual@?$idSearch_Binary@VidStr@@U?$idSearch_BinaryDefault@VidStr@@@@@@UBAHPBVidStr@@HABV2@@Z
// EA  : 0x8279EE38
// RVA : 0x0079EE38
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idStr,idSearch_BinaryDefault<idStr>>::Search_LastLessEqual(
        idSearch_Binary<idStr,idSearch_BinaryDefault<idStr> > *this,
        const idStr *base,
        int num,
        const idStr *value)
{
  int v6; // r29
  int v7; // r28
  int v8; // r31

  v6 = num;
  v7 = 0;
  if ( num > 0 )
  {
    do
    {
      v8 = v6 >> 1;
      if ( idStr::Icmp(s1: base[v7 + (v6 >> 1)].data, s2: value->data) <= 0 )
        v7 += v6 >> 1;
      v6 -= v8;
    }
    while ( v8 > 0 );
  }
  return v7;
}


// ========================================================================
// ?Search@?$idSearch_Binary@V?$idPair@UCoordinate_t@idMD6BlendBranch_Base@@PAVidMD6Node@@@@VidSearch_CoordinateNodePair@idMD6BlendBranch_Base@@@@UBAHPBV?$idPair@UCoordinate_t@idMD6BlendBranch_Base@@PAVidMD6Node@@@@IABV2@@Z
// EA  : 0x8283DB20
// RVA : 0x0083DB20
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair>::Search(
        idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair> *this,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *base,
        int num,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *value)
{
  int v4; // r28
  int v5; // r29
  int v6; // r30
  int v7; // r10
  const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *v8; // r11
  int size; // r8
  const float *data; // r7
  int v11; // r11
  double v12; // fp0
  double v13; // fp13
  int result; // r3
  bool v15; // zf

  if ( num == 0 || base == nullptr )
    return -1;
  v4 = num;
  v5 = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      v7 = 0;
      v8 = &base[v5 + (v4 >> 1)];
      size = v8->first.size;
      if ( v8->first.size > 0 )
      {
        data = v8->first.data;
        v11 = 0;
        do
        {
          v12 = data[v11];
          v13 = value->first.data[v11];
          if ( v12 < v13 )
            break;
          if ( v12 > v13 )
            goto LABEL_10;
          ++v7;
          ++v11;
        }
        while ( v7 < size );
      }
      v5 += v4 >> 1;
LABEL_10:
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  v15 = idMD6BlendBranch_Base::idSearch_CoordinateNodePair::Compare(
          (idMD6BlendBranch_Base::idSearch_CoordinateNodePair *)this,
          a: &base[v5],
          b: value) == 0;
  result = v5;
  if ( !v15 )
    return -1;
  return result;
}


// ========================================================================
// ?Search_FirstGreater@?$idSearch_Binary@V?$idPair@UCoordinate_t@idMD6BlendBranch_Base@@PAVidMD6Node@@@@VidSearch_CoordinateNodePair@idMD6BlendBranch_Base@@@@UBAHPBV?$idPair@UCoordinate_t@idMD6BlendBranch_Base@@PAVidMD6Node@@@@HABV2@@Z
// EA  : 0x8283DBF0
// RVA : 0x0083DBF0
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair>::Search_FirstGreater(
        idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair> *this,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *base,
        int num,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *value)
{
  int v4; // r30
  int v5; // r31
  int v6; // r11
  int v7; // r3
  int v8; // r9
  const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *v9; // r11
  int size; // r8
  const float *data; // r7
  int v12; // r11
  double v13; // fp0
  double v14; // fp13

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    do
    {
      v7 = v4 >> 1;
      v8 = 0;
      v9 = &base[v5 + (v4 >> 1)];
      size = v9->first.size;
      if ( v9->first.size > 0 )
      {
        data = v9->first.data;
        v12 = 0;
        do
        {
          v13 = data[v12];
          v14 = value->first.data[v12];
          if ( v13 < v14 )
            break;
          if ( v13 > v14 )
          {
            v6 = 0;
            goto LABEL_8;
          }
          ++v8;
          ++v12;
        }
        while ( v8 < size );
      }
      v5 += v4 >> 1;
      v6 = 1;
LABEL_8:
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_FirstGreaterEqual@?$idSearch_Binary@V?$idPair@UCoordinate_t@idMD6BlendBranch_Base@@PAVidMD6Node@@@@VidSearch_CoordinateNodePair@idMD6BlendBranch_Base@@@@UBAHPBV?$idPair@UCoordinate_t@idMD6BlendBranch_Base@@PAVidMD6Node@@@@HABV2@@Z
// EA  : 0x8283DC98
// RVA : 0x0083DC98
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair>::Search_FirstGreaterEqual(
        idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair> *this,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *base,
        int num,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *value)
{
  int v4; // r30
  int v5; // r31
  int v6; // r11
  int v7; // r3
  int v8; // r9
  const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *v9; // r11
  int size; // r8
  const float *data; // r7
  int v12; // r11
  double v13; // fp0
  double v14; // fp13

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    do
    {
      v7 = v4 >> 1;
      v8 = 0;
      v9 = &base[v5 + (v4 >> 1)];
      size = v9->first.size;
      if ( v9->first.size <= 0 )
      {
LABEL_7:
        v6 = 0;
      }
      else
      {
        data = v9->first.data;
        v12 = 0;
        while ( 1 )
        {
          v13 = data[v12];
          v14 = value->first.data[v12];
          if ( v13 < v14 )
            break;
          if ( v13 <= v14 )
          {
            ++v8;
            ++v12;
            if ( v8 < size )
              continue;
          }
          goto LABEL_7;
        }
        v5 += v4 >> 1;
        v6 = 1;
      }
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_LastLess@?$idSearch_Binary@V?$idPair@UCoordinate_t@idMD6BlendBranch_Base@@PAVidMD6Node@@@@VidSearch_CoordinateNodePair@idMD6BlendBranch_Base@@@@UBAHPBV?$idPair@UCoordinate_t@idMD6BlendBranch_Base@@PAVidMD6Node@@@@HABV2@@Z
// EA  : 0x8283DD40
// RVA : 0x0083DD40
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair>::Search_LastLess(
        idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair> *this,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *base,
        int num,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *value)
{
  int v4; // r30
  int result; // r3
  int v6; // r31
  int v7; // r10
  const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *v8; // r11
  int size; // r8
  const float *data; // r7
  int v11; // r11
  double v12; // fp0
  double v13; // fp13

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      v7 = 0;
      v8 = &base[result + (v4 >> 1)];
      size = v8->first.size;
      if ( v8->first.size > 0 )
      {
        data = v8->first.data;
        v11 = 0;
        while ( 1 )
        {
          v12 = data[v11];
          v13 = value->first.data[v11];
          if ( v12 < v13 )
            break;
          if ( v12 <= v13 )
          {
            ++v7;
            ++v11;
            if ( v7 < size )
              continue;
          }
          goto LABEL_9;
        }
        result += v4 >> 1;
      }
LABEL_9:
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search_LastLessEqual@?$idSearch_Binary@V?$idPair@UCoordinate_t@idMD6BlendBranch_Base@@PAVidMD6Node@@@@VidSearch_CoordinateNodePair@idMD6BlendBranch_Base@@@@UBAHPBV?$idPair@UCoordinate_t@idMD6BlendBranch_Base@@PAVidMD6Node@@@@HABV2@@Z
// EA  : 0x8283DDD8
// RVA : 0x0083DDD8
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair>::Search_LastLessEqual(
        idSearch_Binary<idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *>,idMD6BlendBranch_Base::idSearch_CoordinateNodePair> *this,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *base,
        int num,
        const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *value)
{
  int v4; // r30
  int result; // r3
  int v6; // r31
  int v7; // r10
  const idPair<idMD6BlendBranch_Base::Coordinate_t,idMD6Node *> *v8; // r11
  int size; // r8
  const float *data; // r7
  int v11; // r11
  double v12; // fp0
  double v13; // fp13

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      v7 = 0;
      v8 = &base[result + (v4 >> 1)];
      size = v8->first.size;
      if ( v8->first.size > 0 )
      {
        data = v8->first.data;
        v11 = 0;
        do
        {
          v12 = data[v11];
          v13 = value->first.data[v11];
          if ( v12 < v13 )
            break;
          if ( v12 > v13 )
            goto LABEL_8;
          ++v7;
          ++v11;
        }
        while ( v7 < size );
      }
      result += v4 >> 1;
LABEL_8:
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search@?$idSearch_Binary@V?$idPair@MPAVidMD6Node@@@@VidSearch_AlphaNodePair@idMD6BlendBranch@@@@UBAHPBV?$idPair@MPAVidMD6Node@@@@IABV2@@Z
// EA  : 0x8283DF08
// RVA : 0x0083DF08
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>::Search(
        idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair> *this,
        const idPair<float,idMD6Node *> *base,
        int num,
        const idPair<float,idMD6Node *> *value)
{
  int v4; // r7
  int v5; // r8
  double first; // fp13
  int v7; // r11
  double v8; // fp0
  double v9; // fp0
  double v10; // fp13

  v4 = num;
  if ( num == 0 || base == nullptr )
    return -1;
  v5 = 0;
  if ( num > 0 )
  {
    first = value->first;
    do
    {
      v7 = v4 >> 1;
      v8 = base[v5 + (v4 >> 1)].first;
      if ( v8 > first || v8 >= first )
        v5 += v4 >> 1;
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  v9 = value->first;
  v10 = base[v5].first;
  if ( v10 > v9 || v10 < v9 )
    return -1;
  return v5;
}


// ========================================================================
// ?Search_FirstGreater@?$idSearch_Binary@V?$idPair@MPAVidMD6Node@@@@VidSearch_AlphaNodePair@idMD6BlendBranch@@@@UBAHPBV?$idPair@MPAVidMD6Node@@@@HABV2@@Z
// EA  : 0x8283DF90
// RVA : 0x0083DF90
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>::Search_FirstGreater(
        idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair> *this,
        const idPair<float,idMD6Node *> *base,
        int num,
        const idPair<float,idMD6Node *> *value)
{
  int v4; // r7
  int v5; // r9
  int v6; // r11
  int v7; // r8

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    do
    {
      v7 = v4 >> 1;
      if ( base[v5 + (v4 >> 1)].first >= (double)value->first )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_FirstGreaterEqual@?$idSearch_Binary@V?$idPair@MPAVidMD6Node@@@@VidSearch_AlphaNodePair@idMD6BlendBranch@@@@UBAHPBV?$idPair@MPAVidMD6Node@@@@HABV2@@Z
// EA  : 0x8283DFF0
// RVA : 0x0083DFF0
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>::Search_FirstGreaterEqual(
        idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair> *this,
        const idPair<float,idMD6Node *> *base,
        int num,
        const idPair<float,idMD6Node *> *value)
{
  int v4; // r7
  int v5; // r9
  int v6; // r11
  int v7; // r8

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    do
    {
      v7 = v4 >> 1;
      if ( base[v5 + (v4 >> 1)].first > (double)value->first )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_LastLess@?$idSearch_Binary@V?$idPair@MPAVidMD6Node@@@@VidSearch_AlphaNodePair@idMD6BlendBranch@@@@UBAHPBV?$idPair@MPAVidMD6Node@@@@HABV2@@Z
// EA  : 0x8283E048
// RVA : 0x0083E048
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>::Search_LastLess(
        idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair> *this,
        const idPair<float,idMD6Node *> *base,
        int num,
        const idPair<float,idMD6Node *> *value)
{
  int v4; // r8
  int result; // r3
  int v6; // r11

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( base[result + (v4 >> 1)].first > (double)value->first )
        result += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search_LastLessEqual@?$idSearch_Binary@V?$idPair@MPAVidMD6Node@@@@VidSearch_AlphaNodePair@idMD6BlendBranch@@@@UBAHPBV?$idPair@MPAVidMD6Node@@@@HABV2@@Z
// EA  : 0x8283E088
// RVA : 0x0083E088
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>::Search_LastLessEqual(
        idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair> *this,
        const idPair<float,idMD6Node *> *base,
        int num,
        const idPair<float,idMD6Node *> *value)
{
  int v4; // r8
  int result; // r3
  double first; // fp13
  int v7; // r11
  double v8; // fp0

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    first = value->first;
    do
    {
      v7 = v4 >> 1;
      v8 = base[result + (v4 >> 1)].first;
      if ( v8 > first || v8 >= first )
        result += v4 >> 1;
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search@?$idSearch_Binary@UidPlayerCoverScore_t@@VidSearchPlayerCoverScore@@@@UBAHPBUidPlayerCoverScore_t@@IABU2@@Z
// EA  : 0x82E2BEE8
// RVA : 0x00E2BEE8
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore>::Search(
        idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore> *this,
        const idPlayerCoverScore_t *base,
        int num,
        const idPlayerCoverScore_t *value)
{
  int v4; // r8
  int v5; // r9
  int v6; // r11

  v4 = num;
  if ( num == 0 || base == nullptr )
    return -1;
  v5 = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( base[v5 + (v4 >> 1)].coverIndex - value->coverIndex <= 0 )
        v5 += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  if ( base[v5].coverIndex != value->coverIndex )
    return -1;
  return v5;
}


// ========================================================================
// ?Search_FirstGreater@?$idSearch_Binary@UidPlayerCoverScore_t@@VidSearchPlayerCoverScore@@@@UBAHPBUidPlayerCoverScore_t@@HABU2@@Z
// EA  : 0x82E2BF60
// RVA : 0x00E2BF60
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore>::Search_FirstGreater(
        idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore> *this,
        const idPlayerCoverScore_t *base,
        int num,
        const idPlayerCoverScore_t *value)
{
  int v4; // r8
  int v5; // r10
  int v6; // r11
  int v7; // r9

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    do
    {
      v7 = v4 >> 1;
      if ( base[v5 + (v4 >> 1)].coverIndex - value->coverIndex <= 0 )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_FirstGreaterEqual@?$idSearch_Binary@UidPlayerCoverScore_t@@VidSearchPlayerCoverScore@@@@UBAHPBUidPlayerCoverScore_t@@HABU2@@Z
// EA  : 0x82E2BFB8
// RVA : 0x00E2BFB8
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore>::Search_FirstGreaterEqual(
        idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore> *this,
        const idPlayerCoverScore_t *base,
        int num,
        const idPlayerCoverScore_t *value)
{
  int v4; // r8
  int v5; // r10
  int v6; // r11
  int v7; // r9

  v4 = num;
  v5 = 0;
  v6 = 0;
  if ( num > 0 )
  {
    do
    {
      v7 = v4 >> 1;
      if ( base[v5 + (v4 >> 1)].coverIndex - value->coverIndex < 0 )
      {
        v5 += v4 >> 1;
        v6 = 1;
      }
      else
      {
        v6 = 0;
      }
      v4 -= v7;
    }
    while ( v7 > 0 );
  }
  return v6 + v5;
}


// ========================================================================
// ?Search_LastLess@?$idSearch_Binary@UidPlayerCoverScore_t@@VidSearchPlayerCoverScore@@@@UBAHPBUidPlayerCoverScore_t@@HABU2@@Z
// EA  : 0x82E2C010
// RVA : 0x00E2C010
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore>::Search_LastLess(
        idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore> *this,
        const idPlayerCoverScore_t *base,
        int num,
        const idPlayerCoverScore_t *value)
{
  int v4; // r9
  int result; // r3
  int v6; // r11

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( base[result + (v4 >> 1)].coverIndex - value->coverIndex < 0 )
        result += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}


// ========================================================================
// ?Search_LastLessEqual@?$idSearch_Binary@UidPlayerCoverScore_t@@VidSearchPlayerCoverScore@@@@UBAHPBUidPlayerCoverScore_t@@HABU2@@Z
// EA  : 0x82E2C050
// RVA : 0x00E2C050
// PDB : w:\tech5\shared\idlib\containers\search.h
// ========================================================================

int __fastcall idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore>::Search_LastLessEqual(
        idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore> *this,
        const idPlayerCoverScore_t *base,
        int num,
        const idPlayerCoverScore_t *value)
{
  int v4; // r9
  int result; // r3
  int v6; // r11

  v4 = num;
  result = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = v4 >> 1;
      if ( base[result + (v4 >> 1)].coverIndex - value->coverIndex <= 0 )
        result += v4 >> 1;
      v4 -= v6;
    }
    while ( v6 > 0 );
  }
  return result;
}

